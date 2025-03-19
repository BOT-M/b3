#ifndef DATA_PROCESSOR_HPP
#define DATA_PROCESSOR_HPP

#include "ConcurrentQueue.hpp"
#include "std.hpp"

class DataProcessor
{
public:
    DataProcessor(const std::string &filename, ConcurrentQueue<std::string> &dataQueue);
    DataProcessor(ConcurrentQueue<std::string> &dataQueue);
    void startProcessing();
    void analyze_data(const char *data, ssize_t len);

private:
    void generate_file_name();
    void write_data(const char *buffer, ssize_t len);
    void read_data();

private:
    ConcurrentQueue<std::string> &dataQueue;
    std::ofstream ofs_;
    std::ofstream ifs_;
    std::string file_name_;
};

#endif // DATA_PROCESSOR_HPP