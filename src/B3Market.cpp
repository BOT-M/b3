#include "B3Market.hpp"

namespace B3
{

    void B3Market::dowork(char *data, std::size_t len)
    {
        std::stringstream ss;
        b3_market_data::PacketHeader packHead(data, len);
        ss << packHead;
        INFO("{}", ss.str());
        std::cout << packHead << std::endl;
        print_beijing_time(packHead.sendingTime());

        std::size_t offset = packHead.bufferLength();

        uint8_t channelID = packHead.channelNumber();
        uint32_t sequenceNumber = packHead.sequenceNumber();
        // 检查 sequenceNumber 是否连续
        if (sequenceNumber != 0 && lastSequenceNumbers[channelID] + 1 != sequenceNumber)
        {
            ERROR("Packet loss detected! Channel:{}, Expected:{}, Received:{}",channelID ,lastSequenceNumbers[channelID] + 1, sequenceNumber);
        }
        lastSequenceNumbers[channelID] = sequenceNumber;

        INFO("Processing Channel:{}, Sequence:{}", channelID, sequenceNumber);

        while (offset + 12 <= len)
        {
            b3_market_data::FramingHeader framHead(data, offset, len, 10);
            ss.clear();
            ss << framHead;
            INFO("{}", ss.str()); 
            offset += framHead.encodedLength();

            b3_market_data::MessageHeader msgHead(data, offset, len, 10);
            ss << msgHead;  
            INFO("{}",ss.str());
            offset += msgHead.encodedLength();

            handleMessage(msgHead.templateId(), data + offset + 12);
            offset += framHead.messageLength();
        }
    };

    void B3Market::handleMessage(const size_t id, char *data)
    {
        switch (id)
        {
        case 50:
            std::cout << "Handling Order_50 message" << std::endl;
            break;
        case 53:
            std::cout << "Handling Trade_53 message" << std::endl;
            break;
        default:
            std::cout << "Unknown template ID: " << id << std::endl;
        }
    }

}