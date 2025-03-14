#ifndef MULTICAST_RECEIVER_HPP
#define MULTICAST_RECEIVER_HPP

#include "MulticastConfig.hpp"
#include "ConcurrentQueue.hpp"
#include "std.hpp"

class MulticastReceiver
{
public:
    MulticastReceiver(const MulticastConfig &config, ConcurrentQueue<std::string> &dataQueue);
    void startListening();

private:
    MulticastConfig config;
    std::vector<std::thread> threads;
    ConcurrentQueue<std::string> &dataQueue;

    void listenOnSocket(const MulticastTarget &target);
};

#endif // MULTICAST_RECEIVER_HPP