#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/async.h> 
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <memory>
#include <vector>
#include <string>

class Logger {
public:
    static void init(const std::string& log_dir = "logs", size_t max_size = 500 * 1024 * 1024, size_t max_files = 10);

    static std::shared_ptr<spdlog::logger>& get_logger();

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

// 定义简化的日志宏
#define INFO(...) SPDLOG_LOGGER_INFO(Logger::get_logger(), __VA_ARGS__)
#define ERROR(...) SPDLOG_LOGGER_ERROR(Logger::get_logger(), __VA_ARGS__)
#define DEBUG(...) SPDLOG_LOGGER_DEBUG(Logger::get_logger(), __VA_ARGS__)

#endif  // LOGGER_H