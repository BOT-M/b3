#include "MulticastConfig.hpp"

bool MulticastConfig::loadFromFile(const std::string &filename) {
    std::ifstream file(filename, std::ifstream::binary);
    if (!file.is_open()) {
        std::cerr << "❌ 无法打开 JSON 文件: " << filename << std::endl;
        return false;
    }

    Json::Value root;
    Json::CharReaderBuilder reader;
    std::string errs;
    
    if (!Json::parseFromStream(reader, file, &root, &errs)) {
        std::cerr << "❌ JSON 解析错误: " << errs << std::endl;
        return false;
    }

    local_ip = root["local_ip"].asString();

    for (const auto &market : root.getMemberNames()) {
        if (market == "local_ip") continue;

        for (const auto &type : root[market].getMemberNames()) {
            for (const auto &item : root[market][type]) {
                targets[market].push_back({type, item[0].asString(), item[1].asInt()});
            }
        }
    }

    return true;
}