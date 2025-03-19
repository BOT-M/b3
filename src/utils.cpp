#include "utils.hpp"
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

void printBinaryAsHexAndDecimal(const char* buffer, size_t length) {
    spdlog::info("start len: {} Printing binary data as hexadecimal and decimal:", length);
    std::stringstream ss;
    ss << "Hexadecimal: ";
    for (size_t i = 0; i < length; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(static_cast<uint8_t>(buffer[i])) << " ";
    }
    spdlog::info(ss.str());
    ss.clear(); 
    ss << "Decimal:     ";
    for (size_t i = 0; i < length; ++i) {
        ss << std::dec << static_cast<int>(static_cast<uint8_t>(buffer[i])) << " ";
    }
}

