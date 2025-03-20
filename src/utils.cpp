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
    std::cout << "北京时间: " << buffer << std::endl;
}

void printBinaryAsHexAndDecimal(const char *buffer, size_t length)
{
    spdlog::info("start len: {} Printing binary data as hexadecimal and decimal:", length);
    std::stringstream ss;
    ss << "Hexadecimal: ";
    for (size_t i = 0; i < length; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(static_cast<uint8_t>(buffer[i])) << " ";
    }
    spdlog::info(ss.str());
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
        std::cout << "frameHead: "  << framHead.encodedLength() << std::endl;
        processedLength += framHead.encodedLength();

        b3_market_data::MessageHeader msgHead(data.data(), processedLength, data.size(), 10);
        std::cout << msgHead << std::endl;
        std::cout << "msgHead: "  << msgHead.encodedLength() << std::endl;
        processedLength += msgHead.encodedLength();

        switch (msgHead.templateId())
        {
        case SecurityStatus:
        {
            b3_market_data::SecurityStatus_3 secStatus(data.data(), processedLength, data.size(), 10);
            std::cout << secStatus << std::endl;
            processedLength += secStatus.encodedLength();
        }
        break;

        case SecurityGroupPhase:
        {
            b3_market_data::SecurityGroupPhase_10 secGroup(data.data(), processedLength, data.size(), 10);
            std::cout << secGroup << std::endl;
            processedLength += secGroup.encodedLength();
        }
        break;

        case SecurityDefinition:
        {
            b3_market_data::SecurityDefinition_12 secDef(data.data(), processedLength, data.size(), 10);
            std::cout << secDef << std::endl;
            processedLength += secDef.encodedLength();
        }
        break;

        case OpeningPrice:
        {
            b3_market_data::OpeningPrice_15 openPrice(data.data(), processedLength, data.size(), 10);
            std::cout << openPrice << std::endl;
            processedLength += openPrice.encodedLength();
        }
        break;

        case TheoreticalOpeningPrice:
        {
            b3_market_data::TheoreticalOpeningPrice_16 theoPrice(data.data(), processedLength, data.size(), 10);
            std::cout << theoPrice << std::endl;
            processedLength += theoPrice.encodedLength();
        }
        break;

        case ClosingPrice:
        {
            b3_market_data::ClosingPrice_17 closePrice(data.data(), processedLength, data.size(), 10);
            std::cout << closePrice << std::endl;
            processedLength += closePrice.encodedLength();
        }
        break;

        case AuctionImbalance:
        {
            b3_market_data::AuctionImbalance_19 imbalance(data.data(), processedLength, data.size(), 10);
            std::cout << imbalance << std::endl;
            processedLength += imbalance.encodedLength();
        }
        break;

        case PriceBand:
        {
            b3_market_data::PriceBand_22 priceBand(data.data(), processedLength, data.size(), 10);
            std::cout << priceBand << std::endl;
            processedLength += priceBand.encodedLength();
        }
        break;

        case QuantityBand:
        {
            b3_market_data::QuantityBand_21 quantityBand(data.data(), processedLength, data.size(), 10);
            std::cout << quantityBand << std::endl;
            processedLength += quantityBand.encodedLength();
        }
        break;

        case HighPrice:
        {
            b3_market_data::HighPrice_24 highPrice(data.data(), processedLength, data.size(), 10);
            std::cout << highPrice << std::endl;
            processedLength += highPrice.encodedLength();
        }
        break;

        case LowPrice:
        {
            b3_market_data::LowPrice_25 lowPrice(data.data(), processedLength, data.size(), 10);
            std::cout << lowPrice << std::endl;
            processedLength += lowPrice.encodedLength();
        }
        break;

        case LastTradePrice:
        {
            b3_market_data::LastTradePrice_27 lastPrice(data.data(), processedLength, data.size(), 10);
            std::cout << lastPrice << std::endl;
            processedLength += lastPrice.encodedLength();
        }
        break;

        case SettlementPrice:
        {
            b3_market_data::SettlementPrice_28 settlePrice(data.data(), processedLength, data.size(), 10);
            std::cout << settlePrice << std::endl;
            processedLength += settlePrice.encodedLength();
        }
        break;

        case OpenInterest:
        {
            b3_market_data::OpenInterest_29 openInterest(data.data(), processedLength, data.size(), 10);
            std::cout << openInterest << std::endl;
            processedLength += openInterest.encodedLength();
        }
        break;

        case ExecutionStatistics:
        {
            b3_market_data::ExecutionStatistics_56 execStats(data.data(), processedLength, data.size(), 10);
            std::cout << execStats << std::endl;
            processedLength += execStats.encodedLength();
        }
        break;

        case SnapshotFullRefresh_Orders_MBO:
        {
            b3_market_data::SnapshotFullRefresh_Orders_MBO_71 snapshot(data.data(), processedLength, data.size(), 10);
            std::cout << snapshot << std::endl;
            processedLength += snapshot.encodedLength();
        }
        break;

        default:
            std::cerr << "Unknown message type: " << msgHead.templateId() << std::endl;
            break;
        }
    }

    return processedLength;
}