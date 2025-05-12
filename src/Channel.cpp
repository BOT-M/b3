#include "Channel.h"

#include "std.hpp"
// #include "utility/Logging.h"

namespace B3
{
    template <typename T>
    void processMessage(char* buffer, size_t bufferLength)
    {
        std::stringstream ss;

        T message(buffer, bufferLength);
        ss << message;
        INFO("== {}", ss.str());
    }

#pragma region Stream
    Stream::Stream(const MulticastConfig& config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks)
        : config_(config), running_flag_(true), orderbooks_(orderbooks), last_sequence_numbers_(0)
    {
    }
    void Stream::Start()
    {
        socket_ = std::make_unique<SocketWrapper>();
        if (!socket_->JoinMulticastGroup(config_))
        {
            throw std::runtime_error("Join multicast failed");
        }
        socket_->SetDataCallback([this](char* data, std::size_t size) { this->DoWork(data, size); });
        socket_->StartReceiving(running_flag_);
    }

    const char* Stream::GetStreamName() const
    {
        return "Stream";
    }

    size_t Stream::HandlePacket(char* data, std::size_t len)
    {
        std::stringstream ss;
        ss << config_.group_ip << ":" << config_.port << " [" << GetStreamName() << "] ";
        b3_market_data::PacketHeader packHead(data, len);

        ss << packHead;
        // INFO("{}", ss.str());

        uint32_t sequenceNumber = packHead.sequenceNumber();
        if (!HandlePacketSeq(sequenceNumber))
        {
            return 0;
        }
        return packHead.encodedLength();
    }

    void Stream::HandleSequence2(const b3_market_data::Sequence_2& msg)
    {
        // todo: NextSeqNo
    }
    void Stream::DoWork(char* data, std::size_t len)
    {
        std::stringstream ss;
        std::size_t       offset = 0;
        offset += HandlePacket(data, len);
        if (offset == 0)
        {
            return;
        }

        while (offset + 12 <= len)
        {
            b3_market_data::FramingHeader framHead(data + offset, len - offset);
            ss.str("");
            ss.clear();
            ss << config_.group_ip << ":" << config_.port << " [" << GetStreamName() << "]  ";

            ss << framHead;
            offset += framHead.encodedLength();

            b3_market_data::MessageHeader msgHead(data + offset, len - offset);
            ss << msgHead;
            // INFO("{}", ss.str());
            offset += msgHead.encodedLength();

            HandleMessage(msgHead.templateId(), data + offset, len - offset);
            offset += framHead.messageLength() - 12;
        }
    }

    void Stream::HandleMessage(const size_t id, char* buffer, const std::uint64_t bufferLength)
    {
        std::stringstream ss;
        ss << config_.group_ip << ":" << config_.port << " [" << GetStreamName() << "] ";
        switch (id)
        {
            case 1:
            {
                b3_market_data::SequenceReset_1 msg(buffer, bufferLength);
                HandleSequenceReset1(msg);
                ss << msg;
            }
            break;
            case 2:
            {
                return;
                b3_market_data::Sequence_2 msg(buffer, bufferLength);
                HandleSequence2(msg);
                ss << msg;
            }
            break;
            case 9:
            {
                b3_market_data::EmptyBook_9 msg(buffer, bufferLength);
                HandlEmptyBook9(msg);
                ss << msg;
            }
            break;
            case 11:
            {
                b3_market_data::ChannelReset_11 msg(buffer, bufferLength);
                HandlChannelReset11(msg);
                ss << msg;
            }
            break;
            case 3:
            {
                b3_market_data::SecurityStatus_3 msg(buffer, bufferLength);
                // HandlSecurityStatus_3(msg);
                ss << msg;
            }
            break;
            case 10:
            {
                b3_market_data::SecurityGroupPhase_10 msg(buffer, bufferLength);
                // HandlSecurityGroupPhase_10(msg);
                ss << msg;
            }
            break;
            case 12:
            {
                b3_market_data::SecurityDefinition_12 msg(buffer, bufferLength);
                HandleSecurityDefinition12(msg);
                ss << msg;
            }
            break;
            case 5:
            {
                b3_market_data::News_5 msg(buffer, bufferLength);
                HandlNews5(msg);
                ss << msg;
            }
            break;
            case 15:
            {
                b3_market_data::OpeningPrice_15 msg(buffer, bufferLength);
                // HandlOpeningPrice_15(msg);
                ss << msg;
            }
            break;
            case 16:
            {
                b3_market_data::TheoreticalOpeningPrice_16 msg(buffer, bufferLength);
                // HandlTheoreticalOpeningPrice_16(msg);
                ss << msg;
            }
            break;
            case 17:
            {
                b3_market_data::ClosingPrice_17 msg(buffer, bufferLength);
                // HandlClosingPrice_17(msg);
                ss << msg;
            }
            break;
            case 19:
            {
                b3_market_data::AuctionImbalance_19 msg(buffer, bufferLength);
                // HandlAuctionImbalance_19(msg);
                ss << msg;
            }
            break;
            case 21:
            {
                b3_market_data::QuantityBand_21 msg(buffer, bufferLength);
                // HandlQuantityBand_21(msg);
                ss << msg;
            }
            break;
            case 22:
            {
                b3_market_data::PriceBand_22 msg(buffer, bufferLength);
                // HandlPriceBand_22(msg);
                ss << msg;
            }
            break;
            case 24:
            {
                b3_market_data::HighPrice_24 msg(buffer, bufferLength);
                // HandlHighPrice_24(msg);
                ss << msg;
            }
            break;
            case 25:
            {
                b3_market_data::LowPrice_25 msg(buffer, bufferLength);
                // HandlLowPrice_25(msg);
                ss << msg;
            }
            break;
            case 27:
            {
                b3_market_data::LastTradePrice_27 msg(buffer, bufferLength);
                // HandlLastTradePrice_27(msg);
                ss << msg;
            }
            break;
            case 28:
            {
                b3_market_data::SettlementPrice_28 msg(buffer, bufferLength);
                // HandlSettlementPrice_28(msg);
                ss << msg;
            }
            break;
            case 29:
            {
                b3_market_data::OpenInterest_29 msg(buffer, bufferLength);
                // HandlOpenInterest_29(msg);
                ss << msg;
            }
            break;
            case 30:
            {
                b3_market_data::SnapshotFullRefresh_Header_30 msg(buffer, bufferLength);
                HandleSnapshotFullRefreshHeader30(msg);
                ss << msg;
            }
            break;
            case 50:
            {
                b3_market_data::Order_MBO_50 msg(buffer, bufferLength);
                HandlOrderMBO50(msg);
                ss << msg;
            }
            break;
            case 51:
            {
                b3_market_data::DeleteOrder_MBO_51 msg(buffer, bufferLength);
                // HandlDeleteOrder_MBO_51(msg);
                ss << msg;
            }
            break;
            case 52:
            {
                b3_market_data::MassDeleteOrders_MBO_52 msg(buffer, bufferLength);
                // HandlMassDeleteOrders_MBO_52(msg);
                ss << msg;
            }
            break;
            case 53:
            {
                b3_market_data::Trade_53 msg(buffer, bufferLength);
                // HandlTrade_53(msg);
                ss << msg;
            }
            break;
            case 54:
            {
                b3_market_data::ForwardTrade_54 msg(buffer, bufferLength);
                // HandlForwardTrade_54(msg);
                ss << msg;
            }
            break;
            case 55:
            {
                b3_market_data::ExecutionSummary_55 msg(buffer, bufferLength);
                // HandlExecutionSummary_55(msg);
                ss << msg;
            }
            break;
            case 56:
            {
                b3_market_data::ExecutionStatistics_56 msg(buffer, bufferLength);
                // HandlExecutionStatistics_56(msg);
                ss << msg;
            }
            break;
            case 57:
            {
                b3_market_data::TradeBust_57 msg(buffer, bufferLength);
                // HandlTradeBust_57(msg);
                ss << msg;
            }
            break;
            case 71:
            {
                b3_market_data::SnapshotFullRefresh_Orders_MBO_71 msg(buffer, bufferLength);
                // HandlSnapshotFullRefresh_Orders_MBO_71(msg);
                ss << msg;
            }
            break;
            case 0:
            {
                b3_market_data::HeaderMessage_0 msg(buffer, bufferLength);
                // HandlHeaderMessage_0(msg);
                ss << msg;
            }
            break;
            default:
                ss << "Unknown template ID: " << id;
        }
        INFO("{}", ss.str());
    }

#pragma endregion  // Stream

#pragma region IncrementalStream
    IncrementalStream::IncrementalStream(const MulticastConfig&                                    config,
                                         std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks)
        : Stream(config, orderbooks)
    {
    }
    const char* IncrementalStream::GetStreamName() const
    {
        return "IncrementalStream";
    }
    void IncrementalStream::StartProcessing()
    {
        Stream::Start();
    }
    void IncrementalStream::SetLastMsgSeqNumProcessed(uint32_t seq)
    {
        last_msg_seq_num_processed.store(seq);
    }
    bool IncrementalStream::HandlePacketSeq(uint32_t sequence_number)
    {
        //  if (current_sequence_version_ != sequence_version)
        //  {
        //      // 处理SequenceVersion变更
        //      current_sequence_version_ = sequence_version;
        //      last_sequence_numbers_    = sequence_number;  // 重置为当前sequence_number
        //      return true;                                  // 或者根据协议决定是否需要校验
        //  }
        // 原有的处理逻辑
        // todo: if (sequence_number < last_msg_seq_num_processed) return false;
        // if (sequence_number != 0 && last_sequence_numbers_ + 1 != sequence_number)
        // {
        //     return false;
        // }
        // last_sequence_numbers_ = sequence_number;
        return true;
    }
    void IncrementalStream::HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg)
    {
        last_sequence_numbers_ = msg.newSeqNo();
    }
    void IncrementalStream::HandlNews5(const b3_market_data::News_5& msg) {}
    void IncrementalStream::HandleSecurityDefinition12(const b3_market_data::SecurityDefinition_12& msg)
    {
        // LastFragment = true; 表是结束
        // if (orderbooks_.find(msg.securityID()) == orderbooks_.end()) orderbooks_[msg.securityID()] = std::make_shared<OrderBook>();
        // orderbooks_[msg.securityID()]->s_security_definition_12_.assign(msg.buffer(), msg.buffer() + msg.bufferLength());
    }

    void IncrementalStream::HandlEmptyBook9(const b3_market_data::EmptyBook_9& msg)
    {
        // todo:
    }

    void IncrementalStream::HandlChannelReset11(const b3_market_data::ChannelReset_11& msg)
    {
        // todo:
    }

    void IncrementalStream::HandlOrderMBO50(const b3_market_data::Order_MBO_50& msg)
    {
        // todo:matchEventIndicator第5位（RecoveryMsg）置位 重建消息
        // if ((msg.matchEventIndicator() & 0x20) != 0)
        // todo;
    }

#pragma endregion  // IncrementalStream

#pragma region SnapshotsRecoveryStream

    SnapshotsRecoveryStream::SnapshotsRecoveryStream(const MulticastConfig&                                    config,
                                                     std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks)
        : Stream(config, orderbooks)
    {
    }

    const char* SnapshotsRecoveryStream::GetStreamName() const
    {
        return "SnapshotsRecoveryStream";
    }
    void SnapshotsRecoveryStream::StartProcessing()
    {
        Stream::Start();
    }
    bool SnapshotsRecoveryStream::HandlePacketSeq(uint32_t sequenceNumber)
    {
        if (sequenceNumber != 1 && last_sequence_numbers_ + 1 != sequenceNumber)
        {
            return false;
        }
        last_sequence_numbers_ = sequenceNumber;
        return true;
    }

    void SnapshotsRecoveryStream::HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg)
    {
        std::stringstream ss;
        INFO("[SnapshotsRecoveryStream] SequenceReset_1 last_sequence_numbers_:{}, tot_num_reports_:{}, orderbooks_.size():{}",
             last_sequence_numbers_, tot_num_reports_, orderbooks_.size());
        for (const auto& order : orderbooks_)
        {
            // char *src = order.second;
            // processMessage<b3_market_data::SnapshotFullRefresh_Header_30> ss(const_cast<char
            // *>(src), order.second->s_snapshot_full_refresh_header_30_.size());
        }
        if (tot_num_reports_ == orderbooks_.size())
        {
            INFO("[SnapshotsRecoveryStream] SequenceReset_1, all orderbooks_ received");
            running_flag_.store(false);
            return;
        }
        else
        {
            ERROR("receive unexpected message");
        }
    }

    void SnapshotsRecoveryStream::HandleSnapshotFullRefreshHeader30(const b3_market_data::SnapshotFullRefresh_Header_30& msg)
    {
        if (is_first_packet_)
        {
            INFO("fist packet, {}", msg.totNumReports());
            tot_num_reports_ = msg.totNumReports();
            is_first_packet_ = false;
        }
        if (orderbooks_.find(msg.securityID()) == orderbooks_.end()) orderbooks_[msg.securityID()] = std::make_shared<OrderBook>();
        orderbooks_[msg.securityID()]->s_snapshot_full_refresh_header_30_.assign(msg.buffer(), msg.buffer() + msg.bufferLength());
    }

#pragma endregion SnapshotsRecoveryStream

#pragma region InstrumentDefinitionStream
    InstrumentDefinitionStream::InstrumentDefinitionStream(const MulticastConfig&                                    config,
                                                           std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks)
        : Stream(config, orderbooks)
    {
        last_sequence_numbers_ = 1;
    }

    const char* InstrumentDefinitionStream::GetStreamName() const
    {
        return "InstrumentDefinitionStream";
    }
    void InstrumentDefinitionStream::StartProcessing()
    {
        Stream::Start();
    }

    bool InstrumentDefinitionStream::HandlePacketSeq(uint32_t sequenceNumber)
    {
        if (sequenceNumber != 1 && last_sequence_numbers_ + 1 != sequenceNumber)
        {
            INFO("ignore this message");
            return false;
        }
        last_sequence_numbers_ = sequenceNumber;
        return true;
    }
    void InstrumentDefinitionStream::HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg)
    {
        INFO("[InstrumentDefinitionStream] last_sequence_numbers_:{}, tot_no_related_sym_:{}, orderbooks_.size():{}",
             last_sequence_numbers_, tot_no_related_sym_, orderbooks_.size());
        std::stringstream ss;
        for (const auto& order : orderbooks_)
        {
            b3_market_data::SecurityDefinition_12 message(order.second->s_security_definition_12_.data(),
                                                          order.second->s_security_definition_12_.size());
            ss.str("");
            ss.clear();
            ss << message;
            INFO("securityID:{}, message:{}", order.first, ss.str());
        }
        if (tot_no_related_sym_ == orderbooks_.size())
        {
            INFO("receive InstrumentDefinitionStream SequenceReset_1, all orderbooks_ received");
            running_flag_.store(false);
            return;
        }
        else
        {
            ERROR("receive unexpected message");
        }
    }

    void InstrumentDefinitionStream::HandleSecurityDefinition12(const b3_market_data::SecurityDefinition_12& msg)
    {
        if (is_first_packet_)
        {
            tot_no_related_sym_ = msg.totNoRelatedSym();
            is_first_packet_    = false;
        }
        if (orderbooks_.find(msg.securityID()) == orderbooks_.end()) orderbooks_[msg.securityID()] = std::make_shared<OrderBook>();
        orderbooks_[msg.securityID()]->s_security_definition_12_.assign(msg.buffer(), msg.buffer() + msg.bufferLength());
    }

#pragma endregion InstrumentDefinitionStream

#pragma region Channel
    Channel::Channel(uint32_t id, const B3Config& config) : config_(config)
    {
        std::cout << "Create channel" << std::endl;
    }

    bool Channel::Start()
    {
        if (running_.exchange(true)) return true;

        try
        {
            if (config_.configs_.find(StreamType::kIncremental) != config_.configs_.end())
            {
                std::cout << "Start incremental stream" << std::endl;
                incremental_thread_ =
                    std::thread(&Channel::RunStream, this,
                                std::unique_ptr<Stream>(new IncrementalStream(config_.configs_.at(StreamType::kIncremental), orderbooks_)));
            }
            if (config_.configs_.find(StreamType::kIncrementalBak) != config_.configs_.end())
            {
                std::cout << "Start incremental stream" << std::endl;
                incremental_bak_thread_ = std::thread(
                    &Channel::RunStream, this,
                    std::unique_ptr<Stream>(new IncrementalStream(config_.configs_.at(StreamType::kIncrementalBak), orderbooks_)));
            }

            if (config_.configs_.find(StreamType::kInstrumentDefinition) != config_.configs_.end())
            {
                std::cout << "Start instrument definition stream" << std::endl;
                instrument_definition_thread_ = std::thread(&Channel::RunStream, this,
                                                            std::unique_ptr<Stream>(new InstrumentDefinitionStream(
                                                                config_.configs_.at(StreamType::kInstrumentDefinition), orderbooks_)));
            }
            if (config_.configs_.find(StreamType::kMarketRecovery) != config_.configs_.end())
            {
                std::cout << "Start market recovery stream" << std::endl;
                snapshots_recovery_thread_ = std::thread(
                    &Channel::RunStream, this,
                    std::unique_ptr<Stream>(new SnapshotsRecoveryStream(config_.configs_.at(StreamType::kMarketRecovery), orderbooks_)));
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
        if (!running_.exchange(false)) return;

        // 等待线程结束
        if (incremental_thread_.joinable()) incremental_thread_.join();
        if (incremental_bak_thread_.joinable()) incremental_bak_thread_.join();
        if (instrument_definition_thread_.joinable()) instrument_definition_thread_.join();
        if (snapshots_recovery_thread_.joinable()) snapshots_recovery_thread_.join();
    }
    void Channel::RunStream(std::unique_ptr<Stream> stream)
    {
        stream->StartProcessing();
    }

#pragma endregion Channel
}  // namespace B3
