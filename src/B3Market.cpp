#include "B3Market.hpp"

namespace B3
{
    template <typename T>
    void processMessage(std::stringstream &ss, char *buffer, size_t bufferLength)
    {
        T message(buffer, bufferLength);
        ss << message;
        INFO("{}", ss.str());
    }

    void B3Market::dowork(char *data, std::size_t len)
    {
        std::stringstream ss;
        b3_market_data::PacketHeader packHead(data, len);
        ss << packHead;
        INFO("{}", ss.str());
        print_beijing_time(packHead.sendingTime());

        std::size_t offset = packHead.encodedLength();

        uint8_t channelID = packHead.channelNumber();
        uint32_t sequenceNumber = packHead.sequenceNumber();
        // 检查 sequenceNumber 是否连续
        if (sequenceNumber != 0 && lastSequenceNumbers[channelID] + 1 != sequenceNumber)
        {
            ERROR("Packet loss detected! Channel:{}, Expected:{}, Received:{}", channelID, lastSequenceNumbers[channelID] + 1, sequenceNumber);
        }
        lastSequenceNumbers[channelID] = sequenceNumber;

        INFO("Processing Channel:{}, Sequence:{}", channelID, sequenceNumber);
        INFO("{}  <= {}", offset + 12 ,len);
        while (offset + 12 <= len)
        {
            b3_market_data::FramingHeader framHead(data + offset, len - offset);
            ss.clear();
            ss << framHead;
            INFO("{}", ss.str());
            offset += framHead.encodedLength();

            b3_market_data::MessageHeader msgHead(data + offset, len - offset);
            ss.clear();
            ss << msgHead;
            INFO("{}", ss.str());
            offset += msgHead.encodedLength();

            handleMessage(msgHead.templateId(), data + offset, len - offset);
            offset += framHead.messageLength() - 12;
        }
    };

    void B3Market::handleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength)
    {
        st.insert(id);
        
        std::stringstream ss;
        for(auto it = st.begin(); it != st.end(); it++)
        {
            ss << *it << "\t" ;
        }
        INFO("templateId:{}", ss.str());
        ss.clear();
        switch (id)
        {
        case 1:
        {
            processMessage<b3_market_data::SequenceReset_1>(ss, buffer, bufferLength);
        }
        break;
        case 2:
        {
            processMessage<b3_market_data::Sequence_2>(ss, buffer, bufferLength);
        }
        break;
        case 9:
        {
            processMessage<b3_market_data::EmptyBook_9>(ss, buffer, bufferLength);
        }
        break;
        case 11:
        {
            processMessage<b3_market_data::ChannelReset_11>(ss, buffer, bufferLength);
        }
        break;
        case 3:
        {
            processMessage<b3_market_data::SecurityStatus_3>(ss, buffer, bufferLength);
        }
        break;
        case 10:
        {
            processMessage<b3_market_data::SecurityGroupPhase_10>(ss, buffer, bufferLength);
        }
        break;
        case 12:
        {
            processMessage<b3_market_data::SecurityDefinition_12>(ss, buffer, bufferLength);
            // todo
        }
        break;
        case 5:
        {
            processMessage<b3_market_data::News_5>(ss, buffer, bufferLength);
        }
        break;
        case 15:
        {
            processMessage<b3_market_data::OpeningPrice_15>(ss, buffer, bufferLength);
        }
        break;
        case 16:
        {
            processMessage<b3_market_data::TheoreticalOpeningPrice_16>(ss, buffer, bufferLength);
        }
        break;
        case 17:
        {
            processMessage<b3_market_data::ClosingPrice_17>(ss, buffer, bufferLength);
        }
        break;
        case 19:
        {
            processMessage<b3_market_data::AuctionImbalance_19>(ss, buffer, bufferLength);
        }
        break;
        case 21:
        {
            processMessage<b3_market_data::QuantityBand_21>(ss, buffer, bufferLength);
        }
        break;
        case 22:
        {
            processMessage<b3_market_data::PriceBand_22>(ss, buffer, bufferLength);
        }
        break;
        case 24:
        {
            processMessage<b3_market_data::HighPrice_24>(ss, buffer, bufferLength);
        }
        break;
        case 25:
        {
            processMessage<b3_market_data::LowPrice_25>(ss, buffer, bufferLength);
        }
        break;
        case 27:
        {
            processMessage<b3_market_data::LastTradePrice_27>(ss, buffer, bufferLength);
        }
        break;
        case 28:
        {
            processMessage<b3_market_data::SettlementPrice_28>(ss, buffer, bufferLength);
        }
        break;
        case 29:
        {
            processMessage<b3_market_data::OpenInterest_29>(ss, buffer, bufferLength);
        }
        break;

        case 30:
        {
            processMessage<b3_market_data::SnapshotFullRefresh_Header_30>(ss, buffer, bufferLength);
        }
        break;
        case 50:
        {
            processMessage<b3_market_data::Order_MBO_50>(ss, buffer, bufferLength);
        }
        break;
        case 51:
        {
            processMessage<b3_market_data::DeleteOrder_MBO_51>(ss, buffer, bufferLength);
        }
        break;
        case 52:
        {
            processMessage<b3_market_data::MassDeleteOrders_MBO_52>(ss, buffer, bufferLength);
        }
        break;
        case 53:
        {
            processMessage<b3_market_data::Trade_53>(ss, buffer, bufferLength);
        }
        break;
        case 54:
        {
            processMessage<b3_market_data::ForwardTrade_54>(ss, buffer, bufferLength);
        }
        break;
        case 55:
        {
            processMessage<b3_market_data::ExecutionSummary_55>(ss, buffer, bufferLength);
        }
        break;
        case 56:
        {
            processMessage<b3_market_data::ExecutionStatistics_56>(ss, buffer, bufferLength);
        }
        break;
        case 57:
        {
            processMessage<b3_market_data::TradeBust_57>(ss, buffer, bufferLength);
        }
        break;
        case 71:
        {
            processMessage<b3_market_data::SnapshotFullRefresh_Orders_MBO_71>(ss, buffer, bufferLength);
        }
        break;
        case 0:
        {
            processMessage<b3_market_data::HeaderMessage_0>(ss, buffer, bufferLength);
        }
        break;
        default:
            INFO("Unknown template ID: {}", id);
        }
    }

}