#include "logger.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>

std::shared_ptr<spdlog::logger> Logger::logger_ = nullptr;

std::string GenerateLogFilename(const std::string &log_dir)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << log_dir << "/B3_"
       << std::put_time(std::localtime(&now_time), "%Y-%m-%d_%H-%M-%S")
       << ".log";
    return ss.str();
}
void Logger::init(const std::string &log_dir, size_t max_size, size_t max_files)
{
    std::string log_filename = GenerateLogFilename(log_dir);

    // 创建文件日志 sink（滚动文件日志，每个文件 500MB，最多保留 10 个文件）
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_filename, max_size, max_files);

    // 创建控制台日志 sink（带颜色）
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    // 组合 sink，确保同时输出到文件和控制台
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    logger_ = std::make_shared<spdlog::logger>("multi_sink_logger", sinks.begin(), sinks.end());

    // 设置日志格式：
    // [%Y-%m-%d %H:%M:%S.%e] [线程ID] [日志级别] message
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%^%l%$] [%s:%#] %v");

    // 设置默认日志器
    spdlog::set_default_logger(logger_);
    spdlog::info("Logger initialized.");
}

std::shared_ptr<spdlog::logger> &Logger::get_logger()
{
    return logger_;
}