#include "DataProcessor.hpp"

// 处理一行数据的函数
void processLine(const std::vector<char>& lineData) {
    std::cout << "读取到 " << lineData.size() << " 字节: ";
    for (unsigned char c : lineData) {
        std::cout << std::hex << static_cast<int>(c) << " ";
    }
    std::cout << std::dec << std::endl; // 重新切换回十进制
}

// 逐行读取二进制数据
void readBinaryFile(const std::string &fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(ifs, line))
    {                                                       // 逐行读取
        std::vector<char> buffer(line.begin(), line.end()); // 转换为 char 向量
        processLine(buffer);
    }
}

int main(int argc, char **argv)
{
    std::string filename = argv[1];
    if (filename.empty())
    {
        std::cout << "use readfile filename" << std::endl;
    }
    readBinaryFile(fileName);
    return 0;
}