#include "Channel.h"
#include "std.hpp"
// #include "utility/Logging.h"

namespace B3
{
    template <typename T>
    void processMessage(std::stringstream &ss, char *buffer, size_t bufferLength)
    {
        T message(buffer, bufferLength);
        ss << message;
    }

#pragma region Stream
    Stream::Stream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks)
        : config_(config), running_flag_(true), orderbooks_(orderbooks), lastSequenceNumbers_(0)
    {
    }
    void Stream::Start()
    {
        socket_ = std::make_unique<SocketWrapper>();
        if (!socket_->JoinMulticastGroup(config_))
        {
            throw std::runtime_error("Join multicast failed");
        }
        socket_->SetDataCallback([this](char *data, std::size_t size)
                                 { this->DoWork(data, size); });
        socket_->StartReceiving(running_flag_);
    }
    bool Stream::handleSeq(uint32_t sequenceNumber)
    {
        // 检查 sequenceNumber 是否连续
        // 序列号连续性检查, 处理心跳包（sequenceNumber=0）
        // std::cout << "Stream::handleSeq" << std::endl;
        if (sequenceNumber != 0 && sequenceNumber != 1 && lastSequenceNumbers_ + 1 != sequenceNumber)
        {
            // LOG_ERROR << "Packet loss detected! Expected:" << lastSequenceNumbers_ + 1 << " Received:" << sequenceNumber;
            return false;
        }
        lastSequenceNumbers_ = sequenceNumber;
        return true;
    }

    size_t Stream::handlePacket(char *data, std::size_t len)
    {
        std::stringstream ss;
        b3_market_data::PacketHeader packHead(data, len);
        ss << packHead;
        INFO("{}", ss.str());
        // std::cout << ss.str();
        // B3::print_beijing_time(packHead.sendingTime());

        uint32_t sequenceNumber = packHead.sequenceNumber();
        if (!handleSeq(sequenceNumber))
        {
            return 0;
        }
        return packHead.encodedLength();
    }
    void Stream::DoWork(char *data, std::size_t len)
    {
        std::stringstream ss;
        std::size_t offset = 0;
        offset += handlePacket(data, len);
        if (offset == 0)
            return;
        // std::cout << "Processing Channel:" << channelID << " Sequence:" << sequenceNumber;
        while (offset + 12 <= len)
        {
            b3_market_data::FramingHeader framHead(data + offset, len - offset);
            ss.str("");
            ss.clear();
            ss << framHead;
            // std::cout << ss.str();
            offset += framHead.encodedLength();

            b3_market_data::MessageHeader msgHead(data + offset, len - offset);
            ss << msgHead;
            INFO("{}", ss.str());
            // std::cout << ss.str();
            offset += msgHead.encodedLength();

            HandleMessage(msgHead.templateId(), data + offset, len - offset);
            offset += framHead.messageLength() - 12;
        }
    }
    void Stream::HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength)
    {
        std::stringstream ss;
        ss.str("");
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
            ss << "Unknown template ID: " << id;
        }
        INFO("{}", ss.str());
        // std::cout << ss.str();
    }

#pragma endregion // Stream

#pragma region IncrementalStream
    IncrementalStream::IncrementalStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks)
        : Stream(config, orderbooks) {}
    void IncrementalStream::StartProcessing()
    {
        Stream::Start();
    }
    void IncrementalStream::HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength)
    {
        Stream::HandleMessage(id, buffer, bufferLength);
        return;
        std::stringstream ss;
        ss.str("");
        ss.clear();
        switch (id)
        {
        case 71:
        {
            processMessage<b3_market_data::SnapshotFullRefresh_Orders_MBO_71>(ss, buffer, bufferLength);
        }
        }
    }

#pragma endregion // IncrementalStream

#pragma region SnapshotsRecoveryStream
    SnapshotsRecoveryStream::SnapshotsRecoveryStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks)
        : Stream(config, orderbooks) {}
    void SnapshotsRecoveryStream::StartProcessing()
    {
        Stream::Start();
    }
    bool SnapshotsRecoveryStream::handleSeq(uint32_t sequenceNumber)
    {
        if (sequenceNumber != 0 && lastSequenceNumbers_ + 1 != sequenceNumber)
        {
            return false;
        }
        lastSequenceNumbers_ = sequenceNumber;
        return true;
    }
    void SnapshotsRecoveryStream::HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength)
    {
        Stream::HandleMessage(id, buffer, bufferLength);
        return;
        std::stringstream ss;
        ss.str("");
        ss.clear();
        switch (id)
        {
        case 71:
        {
            processMessage<b3_market_data::SnapshotFullRefresh_Orders_MBO_71>(ss, buffer, bufferLength);
        }
        }
    }

#pragma endregion SnapshotsRecoveryStream

#pragma region InstrumentDefinitionStream
    InstrumentDefinitionStream::InstrumentDefinitionStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks)
        : Stream(config, orderbooks)
    {
        lastSequenceNumbers_ = 1;
    }
    void InstrumentDefinitionStream::StartProcessing()
    {
        Stream::Start();
    }

    bool InstrumentDefinitionStream::handleSeq(uint32_t sequenceNumber)
    {

        if (sequenceNumber != 1 && lastSequenceNumbers_ + 1 != sequenceNumber)
        {
            return false;
        }
        lastSequenceNumbers_ = sequenceNumber;
        return true;
    }
    void InstrumentDefinitionStream::HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength)
    {
        if (1 == id)
        {
            INFO("receive incremental SequenceReset_1");
            INFO("lastSequenceNumbers_:{}, totNoRelatedSym_:{}, orderbooks_.size():{}", lastSequenceNumbers_, totNoRelatedSym_, orderbooks_.size());
            for (const auto &order : orderbooks_)
            {
                const char *src = order.second->sSecurityDefinition_12_.c_str();
                b3_market_data::SecurityDefinition_12 message(const_cast<char *>(src), order.second->sSecurityDefinition_12_.size());
                INFO("securityID:{}, symbol:{}", order.first, message.symbol());
            }
            if (totNoRelatedSym_ == orderbooks_.size())
            {
                running_flag_.store(false);
                return;
            }
            else
            {
                ERROR("receive unexpected message");
            }
        }

        if (12 == id) // SecurityDefinition_12
        {
            std::stringstream ss;
            b3_market_data::SecurityDefinition_12 message(buffer, bufferLength);
            if (is_first_packet_)
            {
                totNoRelatedSym_ = message.totNoRelatedSym();
                is_first_packet_ = false;
            }
            ss << message;
            INFO("{}", ss.str());
            INFO("securityID:{}, symbol:{}", message.securityID(), message.symbol());
            if (orderbooks_.find(message.securityID()) == orderbooks_.end())
                orderbooks_[message.securityID()] = std::make_shared<OrderBook>();
            orderbooks_[message.securityID()]->sSecurityDefinition_12_ = std::string(buffer, bufferLength);
        }
    }

#pragma endregion InstrumentDefinitionStream

#pragma region Channel
    Channel::Channel(uint32_t id,
                     const B3Config &config)
        : config_(config)
    {
        std::cout << "Create channel" << std::endl;
    }
    bool Channel::Start()
    {
        if (running_.exchange(true))
            return true;

        try
        {
            if (config_.configs.find(StreamType::Incremental) != config_.configs.end())
            {

                std::cout << "Start incremental stream" << std::endl;
                incremental_thread_ = std::thread(&Channel::RunStream, this, std::unique_ptr<Stream>(new IncrementalStream(config_.configs.at(StreamType::Incremental), orderBooks_)));
            }
            if (config_.configs.find(StreamType::InstrumentDefinition) != config_.configs.end())
            {
                std::cout << "Start instrument definition stream" << std::endl;
                instrumentDefinition_thread_ = std::thread(&Channel::RunStream, this, std::unique_ptr<Stream>(new InstrumentDefinitionStream(config_.configs.at(StreamType::InstrumentDefinition), orderBooks_)));
            }
            if (config_.configs.find(StreamType::MarketRecovery) != config_.configs.end())
            {
                std::cout << "Start market recovery stream" << std::endl;
                snapshotsRecovery_thread_ = std::thread(&Channel::RunStream, this, std::unique_ptr<Stream>(new SnapshotsRecoveryStream(config_.configs.at(StreamType::MarketRecovery), orderBooks_)));
            }

            return true;
        }
        catch (...)
        {
            running_ = false;
            throw;
        }
    }

    void Channel::Stop()
    {
        if (!running_.exchange(false))
            return;

        // 等待线程结束
        if (incremental_thread_.joinable())
            incremental_thread_.join();
        if (incremental_bak_thread_.joinable())
            incremental_bak_thread_.join();
        if (instrumentDefinition_thread_.joinable())
            instrumentDefinition_thread_.join();
        if (snapshotsRecovery_thread_.joinable())
            snapshotsRecovery_thread_.join();
    }
    void Channel::RunStream(std::unique_ptr<Stream> stream)
    {
        stream->StartProcessing();
    }

#pragma endregion Channel
} // namespace B3
