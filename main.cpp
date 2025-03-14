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
    std::string xml_filename = "b3-market-data-messages-1.9.0.xml";
    if (argc > 2)
    {
        std::cout << "argv2:" << argv[2] << std::endl;
        xml_filename = argv[2];
    }
    loadSchema(xml_filename);
    int isFile = 0;
    if (argc > 3)
    {
        std::cout << "argv3:" << argv[3] << std::endl;
        isFile = atoi(argv[3]);
    }
    ConcurrentQueue<std::string> dataQueue;
    DataProcessor processor(dataQueue);
    std::thread processorThread(&DataProcessor::startProcessing, &processor);
    if (isFile)
    {
    }
    else
    {

        MulticastReceiver receiver(config, dataQueue);
        std::thread receiverThread(&MulticastReceiver::startListening, &receiver);
        receiverThread.join();
    }

    processorThread.join();

    return 0;
}