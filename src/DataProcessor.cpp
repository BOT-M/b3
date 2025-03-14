#include "DataProcessor.hpp"
#include "std.hpp"
#include "basestrcut.hpp"

DataProcessor::DataProcessor(ConcurrentQueue<std::string> &dataQueue, int isReadFile) : dataQueue(dataQueue), isReadFile_(isReadFile)
{
    generate_file_name();
    if (isReadFile_ = 0)
    {
        ofs_.open(file_name_, std::ios::binary | std::ios::app);
        if (!ofs_.is_open())
        {
            std::cerr << "Failed to open file: " << file_name_ << std::endl;
            return;
        }
    }
    else if (isReadFile_ = 1)
    {
        std::ifstream ifs(file_name_, std::ios::in | std::ios::binary);
        if (!ifs.is_open())
        {
            std::cerr << "Failed to open file for binary reading: " << file_name_ << std::endl;
            return;
        }
    }
}

void DataProcessor::startProcessing()
{
    std::string data;
    while (true)
    {
        if (dataQueue.pop(data))
        {
            write_data(data.c_str(), data.size());
            analyze_data(data.c_str(), data.size());
        }
    }
}

void DataProcessor::generate_file_name()
{
    // 1. 创建data目录（若不存在）
    boost::filesystem::path dir("data");
    if (!boost::filesystem::exists(dir))
    {
        try
        {
            boost::filesystem::create_directory(dir);
        }
        catch (const boost::filesystem::filesystem_error &e)
        {
            std::cerr << "Error creating directory: " << e.what() << std::endl;
            return;
        }
    }

    // 2. 生成日期字符串（YYYY-MM-DD）
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time);
    std::ostringstream date_oss;
    date_oss << std::put_time(&now_tm, "%Y-%m-%d");
    std::string date_str = date_oss.str();

    // 3. 处理IP和端口
    //     std::string ip_str = group_ip_;
    //     std::replace(ip_str.begin(), ip_str.end(), '.', '_'); // 将.替换为_
    //     std::ostringstream port_oss;
    //     port_oss << std::setw(5) << std::setfill('0') << port_; // 端口号补零到5位
    //     std::string port_str = port_oss.str();
    //
    // 4. 组合文件名
    file_name_ = "data/" + date_str + ".bin"; //  + "_" + ip_str + "_" + port_str + ".bin";
}

void DataProcessor::write_data(const char *buffer, ssize_t len)
{
    if (!ofs_.is_open())
    {
        std::cerr << "Failed to open file: " << file_name_ << std::endl;
        return;
    }
    ofs_.write(buffer, len);
    ofs_ << '\n'; // 每个buffer占一行
    ofs_.flush(); // 确保数据及时写入
}

void DataProcessor::read_data()
{
    std::ifstream ifs(file_name_, std::ios::in | std::ios::binary);
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open file for reading: " << file_name_ << std::endl;
        return;
    }

    std::string line;
    while (std::getline(ifs, line)) // 按行读取数据
    {
        process_line(line); // 处理每一行的数据
    }

    ifs.close();
}

void DataProcessor::analyze_data(const char *buffer, ssize_t len)
{
    if (len < sizeof(PacketHeader))
    {
        std::cerr << "数据包长度不足 16 字节，丢弃数据包" << std::endl;
        return;
    }

    std::cout << " len :" << len << std::endl;

    PacketHeader header;
    memcpy(&header, buffer, sizeof(PacketHeader));

    header.SequenceVersion = ntohs(header.SequenceVersion);
    header.SequenceNumber = ntohl(header.SequenceNumber);
    header.SendingTime = be64toh(header.SendingTime);

    header.print();

    // 解析 SBE 消息
    ssize_t offset = sizeof(PacketHeader);
    while (offset + 12 <= len)
    {
        MessageHeader msgHeader;
        memcpy(&msgHeader, buffer + offset, sizeof(MessageHeader));

        msgHeader.messageLength = ntohs(msgHeader.messageLength);
        msgHeader.encodingType = ntohs(msgHeader.encodingType);
        msgHeader.blockLength = ntohs(msgHeader.blockLength);
        msgHeader.templateID = ntohs(msgHeader.templateID);
        msgHeader.schemaID = ntohs(msgHeader.schemaID);
        msgHeader.schemaVersion = ntohs(msgHeader.schemaVersion);

        msgHeader.print();
        offset += msgHeader.messageLength;
    }
}