#ifndef STREAM_HPP
#define STREAM_HPP

#include "SocketWrapper.h"

namespace B3
{
    class Message;
    enum class StreamType
    {
        kIncremental          = 0,
        kIncrementalBak       = 1,
        kInstrumentDefinition = 2,
        kMarketRecovery       = 3
    };

    struct B3Config
    {
        B3Config() {}
        B3Config(const std::string& local_ip, const std::string& incremental, const std::string& definition, const std::string& recovery,
                 const std::string& incremental_bak)
            : local_ip_(local_ip)
        {
            Parse(StreamType::kIncremental, incremental);
            Parse(StreamType::kInstrumentDefinition, definition);
            Parse(StreamType::kMarketRecovery, recovery);
            Parse(StreamType::kIncrementalBak, incremental_bak);
        }

        void Parse(StreamType type, const std::string& address)
        {
            if (address.empty()) return;

            B3::MulticastConfig config;
            config.local_ip = local_ip_;
            auto pos        = address.find(':');
            if (pos != std::string::npos)
            {
                config.group_ip = address.substr(0, pos);
                config.port     = std::stoi(address.substr(pos + 1));
            }
            else
            {
                return;
            }
            configs_[type] = config;
        }

        std::string                                         local_ip_;
        std::unordered_map<StreamType, B3::MulticastConfig> configs_;
    };

    class OrderBook
    {
       public:
        std::vector<char> s_security_definition_12_;
        std::vector<char> s_snapshot_full_refresh_header_30_;
        std::vector<char> s_order_MBO_50_;
        std::vector<char> s_snapshot_full_refresh_orders_mbo_71_;
    };

    // 流基类
    class Stream
    {
       public:
        explicit Stream(const MulticastConfig& config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks);
        virtual ~Stream() = default;
        void Start();

       public:
        virtual void HandlNews5(const b3_market_data::News_5& msg){};
        virtual void HandlEmptyBook9(const b3_market_data::EmptyBook_9& msg){};
        virtual void HandlChannelReset11(const b3_market_data::ChannelReset_11& msg){};
        virtual void HandleSecurityDefinition12(const b3_market_data::SecurityDefinition_12& msg){};
        virtual void HandleSnapshotFullRefreshHeader30(const b3_market_data::SnapshotFullRefresh_Header_30& msg){};
        virtual void HandlOrderMBO50(const b3_market_data::Order_MBO_50& msg){};

        virtual const char* GetStreamName() const;

       public:
        virtual void StartProcessing()                                                = 0;
        virtual bool HandlePacketSeq(uint32_t sequence_number)                        = 0;
        virtual void HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg) = 0;

       public:
        void DoWork(char* data, std::size_t len);
        void HandleMessage(const size_t id, char* buffer, const std::uint64_t buffer_length);
        void HandleSequence2(const b3_market_data::Sequence_2& msg);  // todo:处理心跳

        std::size_t HandlePacket(char* data, std::size_t len);

       public:
        std::unique_ptr<SocketWrapper>                            socket_;
        MulticastConfig                                           config_;
        std::atomic<bool>                                         running_flag_{false};
        std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks_;
        uint32_t                                                  last_sequence_numbers_{0};

        const int kSequenceIntervalMs = 1000;  // 配置：Sequence间隔，单位毫秒
        const int kMaxNoMsgTimeMs     = 3 * kSequenceIntervalMs;
        uint64_t  last_recv_time_{0};
        bool      is_first_packet_{true};
    };
    class IncrementalStream : public Stream
    {
       public:
        explicit IncrementalStream(const MulticastConfig& config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks);
        void StartProcessing() override;
        bool HandlePacketSeq(uint32_t sequence_number) override;
        void HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg) override;
        void HandlNews5(const b3_market_data::News_5& msg) override;
        void HandlEmptyBook9(const b3_market_data::EmptyBook_9& msg) override;
        void HandlChannelReset11(const b3_market_data::ChannelReset_11& msg) override;
        void HandleSecurityDefinition12(const b3_market_data::SecurityDefinition_12& msg) override;
        void HandlOrderMBO50(const b3_market_data::Order_MBO_50& msg) override;

        const char* GetStreamName() const override;

        void SetLastMsgSeqNumProcessed(uint32_t seq);

       private:
        std::atomic<uint32_t> last_msg_seq_num_processed{0};
    };

    class SnapshotsRecoveryStream : public Stream
    {
       public:
        explicit SnapshotsRecoveryStream(const MulticastConfig&                                    config,
                                         std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks);
        void StartProcessing() override;

        bool HandlePacketSeq(uint32_t sequence_number) override;
        void HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg) override;
        void HandleSnapshotFullRefreshHeader30(const b3_market_data::SnapshotFullRefresh_Header_30& msg) override;

        const char* GetStreamName() const override;

       public:
       private:
        uint32_t tot_num_reports_{0};
    };

    class InstrumentDefinitionStream : public Stream
    {
       public:
        explicit InstrumentDefinitionStream(const MulticastConfig&                                    config,
                                            std::unordered_map<uint64_t, std::shared_ptr<OrderBook>>& orderbooks);
        void StartProcessing() override;

        bool HandlePacketSeq(uint32_t sequence_number) override;
        void HandleSequenceReset1(const b3_market_data::SequenceReset_1& msg) override;
        void HandleSecurityDefinition12(const b3_market_data::SecurityDefinition_12& msg) override;

        const char* GetStreamName() const override;

       public:
       private:
        uint32_t expected_symbols_{0};
        uint32_t tot_no_related_sym_{0};
    };

    class Channel : public std::enable_shared_from_this<Channel>
    {
       public:
        explicit Channel(uint32_t id, const B3Config& config);
        bool Start();
        void Stop();

       private:
        void RunStream(std::unique_ptr<Stream> stream);

       private:
        B3Config          config_;
        std::atomic<bool> running_{false};
        std::thread       incremental_thread_;
        std::thread       incremental_bak_thread_;
        std::thread       instrument_definition_thread_;
        std::thread       snapshots_recovery_thread_;

        std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> orderbooks_;
    };

}  // namespace B3

#endif  // STREAM_HPP
