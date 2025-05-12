#include <json/json.h>

#include "Channel.h"
#include "SignalHandler.hpp"
#include "logger.hpp"
#include "std.hpp"
void signalHandler(int signum)
{
    std::cout << "\n📢 收到信号 " << signum << "，程序即将退出...\n";
    exit(0);
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    std::string              token;

    for (char ch : str)
    {
        if (ch == delimiter)
        {
            if (!token.empty()) result.push_back(token);
            token.clear();
        }
        else
        {
            token += ch;
        }
    }
    if (!token.empty()) result.push_back(token);  // 最后一个部分

    return result;
}

int main(int argc, char* argv[])
{
    SignalHandler& handler = SignalHandler::getInstance();
    handler.registerHandler(SIGINT, signalHandler);
    handler.registerHandler(SIGTERM, signalHandler);

    std::string filename;
    if (argc > 1)
    {
        std::cout << "argv:" << argv[1] << std::endl;
        filename = argv[1];
    }

    if (filename.empty()) std::cerr << "未指定组播配置文件" << std::endl;

    std::vector<std::string> parts = split(filename, '.');

    std::string log_dir = "logs/" + parts[0];
    Logger::init(log_dir);  // 初始化日志
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open B3.json" << std::endl;
        return 1;
    }

    Json::Value             root;
    Json::CharReaderBuilder reader;
    std::string             errs;

    // (2) 解析 JSON
    if (!Json::parseFromStream(reader, file, &root, &errs))
    {
        std::cerr << "JSON parse error: " << errs << std::endl;
        return 1;
    }
    B3::B3Config config;
    // (3) 提取关键字段
    try
    {
        // 读取字符串字段
        std::string so_path  = root["so_path"].asString();
        std::string local_ip = root["local_ip"].asString();

        // 读取数组中的对象
        const Json::Value& market = root["market"];
        if (!market.empty())
        {
            const Json::Value& first_market         = market[0];  // 取第一个市场配置
            int                channel              = first_market["Channel"].asInt();
            std::string        InstrumentDefinition = first_market["InstrumentDefinition"].asString();
            std::string        Incremental          = first_market["Incremental"].asString();
            std::string        SnapshotsRecovery    = first_market["SnapshotsRecovery"].asString();
            std::string        IncrementalBak       = first_market["IncrementalBak"].asString();
            config = B3::B3Config{local_ip, Incremental, InstrumentDefinition, SnapshotsRecovery, IncrementalBak};
            // 遍历所有字段（适用于未知结构的JSON）
            std::cout << "\nAll Market Fields:\n";
            for (const auto& key : first_market.getMemberNames())
            {
                std::cout << "  " << key << ": " << first_market[key].asString() << "\n";
            }
        }
    }
    catch (const Json::Exception& e)
    {
        std::cerr << "JSON access error: " << e.what() << std::endl;
        return 1;
    }
    B3::Channel channel(78, config);
    channel.Start();
    while (true)
    {
        ::sleep(1);
    }
    return 0;
}
