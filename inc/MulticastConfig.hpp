#ifndef MULTICAST_CONFIG_HPP
#define MULTICAST_CONFIG_HPP

#include "std.hpp"

struct MulticastTarget {
    std::string type;  // "Snapshot", "Incrementals-A", etc.
    std::string group_ip;
    int port;
};

class MulticastConfig {
public:
    std::string local_ip;
    std::map<std::string, std::vector<MulticastTarget>> targets;

    bool loadFromFile(const std::string &filename);
};

#endif // MULTICAST_CONFIG_HPP