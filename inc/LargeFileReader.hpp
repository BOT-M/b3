#ifndef LARGEFILEREADER_HPP
#define LARGEFILEREADER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

class LargeFileReader
{
public:
    explicit LargeFileReader(const std::string &file_name, size_t buffer_size = 64 * 1024)
        : file_name_(file_name), buffer_size_(buffer_size) {}

    void readFromFile()
    {
        std::ifstream ifs(file_name_, std::ios::binary);
        if (!ifs.is_open())
        {
            std::cerr << "Failed to open file: " << file_name_ << std::endl;
            return;
        }

        std::vector<char> buffer(buffer_size_);
        std::string leftover; // 存储未处理完的数据

        while (ifs.read(buffer.data(), buffer_size_) || ifs.gcount() > 0)
        {
            size_t bytesRead = ifs.gcount();

            // 将 leftover（上次未处理完的数据）拼接到本次读取数据前面
            std::string data = leftover + std::string(buffer.data(), bytesRead);

            // 处理数据，并返回未处理完的数据
            leftover = processValue(data);
        }

        // 处理最后剩余的 leftover（如果有的话）
        if (!leftover.empty())
        {
            finalProcessing(leftover);
        }
    }

private:
    std::string file_name_;
    size_t buffer_size_;

    /**
     * 处理读取到的数据
     * @param data  当前读取到的数据（包含上次未处理完的部分）
     * @return      返回未处理完的部分（供下一次拼接）
     */
    std::string processValue(const std::string &data)
    {
        size_t processedLength = 0;

        std::string cleanedData;
        cleanedData.reserve(data.size());  // 预分配容量

        // 移除所有 '\n'
        for (char c : data) {
            if (c != '\n') {
                cleanedData.push_back(c);
            }
        }
        processedLength = processData(cleanedData);

        // 返回未处理完的部分（例如最后不完整的一行）
        return data.substr(processedLength);
    }

    /**
     * 处理最后剩余的数据（如果有的话）
     */
    void finalProcessing(const std::string &leftover)
    {
        std::cout << "Final processing of leftover: " << leftover << std::endl;
    }
};



#endif // LARGEFILEREADER_HPP