#include "utils.hpp"
#include "LargeFileReader.hpp"
#include "PacketHeader.h"
#include "FramingHeader.h"
#include "MessageHeader.h"

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

size_t processLine(std::string &data)
{
    std::cout << "读取到 " << data.size() << " 字节: ";
    size_t processedLength = 0;

    b3_market_data::PacketHeader packHead(data.data(), data.size());
    std::cout << packHead << std::endl;
    print_beijing_time(packHead.sendingTime());
    processedLength += packHead.encodedLength();

    b3_market_data::FramingHeader framHead(data.data(), processedLength, data.size(), 10);
    std::cout << framHead << std::endl;
    processedLength += framHead.encodedLength();

    b3_market_data::MessageHeader msgHead(data.data(), processedLength, data.size(), 10);
    std::cout << msgHead << std::endl;

    return processedLength;
}