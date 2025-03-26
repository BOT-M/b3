#ifndef MARKET_HPP
#define MARKET_HPP
#include "std.hpp"
#include "basestrcut.hpp"
namespace B3
{
    class B3Market
    {
    public:
        B3Market() {};
        void dowork(char *data, std::size_t len);

    private:
        void handleMessage(const size_t id, char *data);

    private:
        std::unordered_map<uint8_t, uint32_t> lastSequenceNumbers;
    };

} // namespace B3

#endif // MARKET_HPP