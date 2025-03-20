#include "MulticastConfig.hpp"
#include "MulticastReceiver.hpp"
#include "DataProcessor.hpp"
#include "SignalHandler.hpp"
#include "xml.hpp"
void signalHandler(int signum)
{
    std::cout << "\n📢 收到信号 " << signum << "，程序即将退出...\n";
    exit(0);
}

int main(int argc, char *argv[])
{
    auto logger = spdlog::basic_logger_mt("file_logger", "logs/app.log");
    spdlog::set_default_logger(logger);

    spdlog::info("Logging to a file.");
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
    
    SignalHandler &handler = SignalHandler::getInstance();
    handler.registerHandler(SIGINT, signalHandler);
    handler.registerHandler(SIGTERM, signalHandler);

    std::string filename;
    if (argc > 1)
    {
        std::cout << "argv:" << argv[1] << std::endl;
        filename = argv[1];
    }
    if (filename.empty())
        std::cerr << "未指定组播配置文件" << std::endl;

    MulticastConfig config;
    if (!config.loadFromFile(filename))
    {
        return 1;
    }
   
    ConcurrentQueue<std::string> dataQueue;
    DataProcessor processor(dataQueue);
    std::thread processorThread(&DataProcessor::startProcessing, &processor);
    MulticastReceiver receiver(config, dataQueue);
    std::thread receiverThread(&MulticastReceiver::startListening, &receiver);
    receiverThread.join();
    processorThread.join();

    return 0;
}