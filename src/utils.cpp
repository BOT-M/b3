#include "utils.hpp"
#include "LargeFileReader.hpp"
#include "basestrcut.hpp"
// 将纳秒时间戳转换为北京时间（UTC+8）
void print_beijing_time(uint64_t nanoseconds)
{
    using namespace std::chrono;

    // 转换为秒级时间戳
    std::time_t seconds = nanoseconds / 1'000'000'000;

    // 转换为本地时间（UTC+8）
    std::tm *tm_time = std::gmtime(&seconds); // 先转换为 UTC 时间
    tm_time->tm_hour -= 3;                    // 调整到北京时间

    // 输出格式化时间
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_time);

    INFO("北京时间:{}", buffer);
}

void print_brazil_b3_time(uint64_t nanoseconds)
{
    using namespace std::chrono;

    // 转换纳秒到秒
    std::time_t seconds = nanoseconds / 1'000'000'000;

    // 调整到巴西 B3 交易所时间（UTC-3）
    seconds -= 3 * 3600; // 直接减去 3 小时的秒数

    // 转换为本地时间
    std::tm *tm_time = std::gmtime(&seconds); // 仍然用 UTC 解析时间

    // 格式化时间输出
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_time);
    std::cout << "巴西 B3 交易所时间 (UTC-3): " << buffer << std::endl;
}

void printBinaryAsHexAndDecimal(const char *buffer, size_t length)
{
    INFO("start len: {} Printing binary data as hexadecimal and decimal:", length);
    std::stringstream ss;
    ss << "Hexadecimal: ";
    for (size_t i = 0; i < length; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(static_cast<uint8_t>(buffer[i])) << " ";
    }
    INFO(ss.str());
    ss.clear();
    ss << "Decimal:     ";
    for (size_t i = 0; i < length; ++i)
    {
        ss << std::dec << static_cast<int>(static_cast<uint8_t>(buffer[i])) << " ";
    }
}

size_t processData(std::string &data)
{
    std::cout << "读取到 " << data.size() << " 字节: ";
    size_t processedLength = 0;

    b3_market_data::PacketHeader packHead(data.data(), data.size());
    std::cout << packHead << std::endl;
    print_beijing_time(packHead.sendingTime());
    processedLength += packHead.encodedLength();

    while (data.size() > processedLength)
    {

        b3_market_data::FramingHeader framHead(data.data(), processedLength, data.size(), 10);
        std::cout << framHead << std::endl;
        processedLength += framHead.encodedLength();

        b3_market_data::MessageHeader msgHead(data.data(), processedLength, data.size(), 10);
        std::cout << msgHead << std::endl;
        processedLength += msgHead.encodedLength();

        switch (msgHead.templateId())
        {
        case Sequence_2:
        {
            b3_market_data::Sequence_2 seq(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << seq << std::endl;
        }
        break;
        case SecurityStatus:
        {
            b3_market_data::SecurityStatus_3 secStatus(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << secStatus << std::endl;
        }
        break;

        case SecurityGroupPhase:
        {
            b3_market_data::SecurityGroupPhase_10 secGroup(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << secGroup << std::endl;
        }
        break;

        case SecurityDefinition:
        {
            b3_market_data::SecurityDefinition_12 secDef(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << secDef << std::endl;
        }
        break;

        case OpeningPrice:
        {
            b3_market_data::OpeningPrice_15 openPrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << openPrice << std::endl;
        }
        break;

        case TheoreticalOpeningPrice:
        {
            b3_market_data::TheoreticalOpeningPrice_16 theoPrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << theoPrice << std::endl;
        }
        break;

        case ClosingPrice:
        {
            b3_market_data::ClosingPrice_17 closePrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << closePrice << std::endl;
        }
        break;

        case AuctionImbalance:
        {
            b3_market_data::AuctionImbalance_19 imbalance(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << imbalance << std::endl;
        }
        break;

        case PriceBand:
        {
            b3_market_data::PriceBand_22 priceBand(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << priceBand << std::endl;
        }
        break;

        case QuantityBand:
        {
            b3_market_data::QuantityBand_21 quantityBand(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << quantityBand << std::endl;
        }
        break;

        case HighPrice:
        {
            b3_market_data::HighPrice_24 highPrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << highPrice << std::endl;
        }
        break;

        case LowPrice:
        {
            b3_market_data::LowPrice_25 lowPrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << lowPrice << std::endl;
            processedLength += lowPrice.encodedLength();
        }
        break;

        case LastTradePrice:
        {
            b3_market_data::LastTradePrice_27 lastPrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << lastPrice << std::endl;
        }
        break;

        case SettlementPrice:
        {
            b3_market_data::SettlementPrice_28 settlePrice(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << settlePrice << std::endl;
        }
        break;

        case OpenInterest:
        {
            b3_market_data::OpenInterest_29 openInterest(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << openInterest << std::endl;
        }
        break;

        case ExecutionStatistics:
        {
            b3_market_data::ExecutionStatistics_56 execStats(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << execStats << std::endl;
        }
        break;

        case SnapshotFullRefresh_Orders_MBO:
        {
            b3_market_data::SnapshotFullRefresh_Orders_MBO_71 snapshot(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << snapshot << std::endl;
        }
        break;

        case Order_MBO:
        {
            b3_market_data::Order_MBO_50 order(data.data(), processedLength, data.size(), msgHead.blockLength(), 10);
            std::cout << order << std::endl;
        }

        default:
            std::cerr << "Unknown message type: " << msgHead.templateId() << std::endl;
            break;
        }
        std::cout << "=== templateId:" << msgHead.templateId() << " framLen:" << framHead.messageLength() << " headLen:" << msgHead.blockLength() << std::endl;
        processedLength += framHead.messageLength() - 12;
    }

    std::cout << std::endl;
    return processedLength;
}