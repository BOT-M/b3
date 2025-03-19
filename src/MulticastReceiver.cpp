#include "MulticastReceiver.hpp"
#include "utils.hpp"

MulticastReceiver::MulticastReceiver(const MulticastConfig &config, ConcurrentQueue<std::string> &dataQueue)
    : config(config), dataQueue(dataQueue) {}

void MulticastReceiver::listenOnSocket(const MulticastTarget &target)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0)
    {
        std::cerr << "❌ 创建 socket 失败: " << target.group_ip << ":" << target.port << std::endl;
        return;
    }

    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    sockaddr_in local_addr{};
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(target.port);
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (sockaddr *)&local_addr, sizeof(local_addr)) < 0)
    {
        std::cerr << "❌ 绑定失败: " << target.group_ip << ":" << target.port << std::endl;
        close(sockfd);
        return;
    }

    ip_mreq mreq{};
    inet_pton(AF_INET, target.group_ip.c_str(), &mreq.imr_multiaddr);
    inet_pton(AF_INET, config.local_ip.c_str(), &mreq.imr_interface);
    setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
    std::cout << "🔌 已加入组播组 " << target.group_ip << std::endl;

    char buffer[2048];
    sockaddr_in src_addr{};
    socklen_t addr_len = sizeof(src_addr);

    while (true)
    {
        ssize_t len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr *)&src_addr, &addr_len);
        if (len > 0)
        {
            printBinaryAsHexAndDecimal(buffer, len);
            std::string data(buffer, len);
            dataQueue.push(data);
        }
    }
}

void MulticastReceiver::startListening()
{
    for (const auto &[market, targets] : config.targets)
    {
        for (const auto &target : targets)
        {
            threads.emplace_back(&MulticastReceiver::listenOnSocket, this, target);
        }
    }

    for (auto &thread : threads)
    {
        thread.join();
    }
}