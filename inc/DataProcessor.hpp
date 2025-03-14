#ifndef DATA_PROCESSOR_HPP
#define DATA_PROCESSOR_HPP

#include "ConcurrentQueue.hpp"
#include "std.hpp"

class DataProcessor
{
public:
    DataProcessor(ConcurrentQueue<std::string> &dataQueue, int isReadFile = 0);
    void startProcessing();

private:
    void generate_file_name();
    void analyze_data(const char *data, ssize_t len);
    void write_data(const char *buffer, ssize_t len);
    void DataProcessor::read_data();

private:
    ConcurrentQueue<std::string> &dataQueue;
    std::ofstream ofs_;
    std::ofstream ifs_;
    std::string file_name_;
    int isReadFile_;
};

#endif // DATA_PROCESSOR_HPP