#ifndef STREAM_HPP
#define STREAM_HPP
#include "SocketWrapper.h"

namespace B3
{
    class Message;
    enum class StreamType
    {
        Incremental = 0,
        IncrementalBak = 1,
        InstrumentDefinition = 2,
        MarketRecovery = 3
    };

    struct B3Config
    {
        B3Config() {}
        B3Config(std::string local_ip, std::string incremental, std::string definition, std::string recovery, std::string incremental_bak)
            : local_ip_(local_ip)
        {
            parse(StreamType::Incremental, incremental);
            parse(StreamType::InstrumentDefinition, definition);
            parse(StreamType::MarketRecovery, recovery);
            parse(StreamType::IncrementalBak, incremental_bak);
        }
        void parse(StreamType type, const std::string &address)
        {
            if (address.empty())
                return;

            B3::MulticastConfig config;
            config.local_ip = local_ip_;
            auto pos = address.find(':');
            if (pos != std::string::npos)
            {
                config.group_ip = address.substr(0, pos);
                config.port = std::stoi(address.substr(pos + 1));
            }
            else
            {
                return;
            }
            configs[type] = config;
        }
        std::string local_ip_;
        std::unordered_map<StreamType, B3::MulticastConfig> configs;
    };
    class OrderBook
    {
    public:
        std::string sSecurityDefinition_12_;
    };
    // 流基类
    class Stream
    {
    public:
        virtual ~Stream() = default;
        void Start();
        virtual void StartProcessing() = 0;
        void DoWork(char *data, std::size_t len);
        virtual void HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength);
        virtual std::size_t handlePacket(char *data, std::size_t len);
        // virtual std::size_t handleFam(char *data, std::size_t len, uint32_t& templateId, std::size_t& offset);
        virtual bool handleSeq(uint32_t sequenceNumber);
    
    protected:
        void handleSquence(int id);

    protected:
        explicit Stream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks);
        std::unique_ptr<SocketWrapper> socket_;
        MulticastConfig config_;
        std::atomic<bool> running_flag_{false};
        std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks_;
        uint32_t lastSequenceNumbers_{0};

        const int sequence_interval_ms = 1000; // 配置：Sequence间隔，单位毫秒
        const int max_no_msg_time_ms = 3 * sequence_interval_ms;
    };

    class IncrementalStream : public Stream
    {
    public:
        explicit IncrementalStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks);
        void StartProcessing() override;
        void HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength) override;

    private:
        std::atomic<uint64_t> last_processed_seq_{0};
    };

    class SnapshotsRecoveryStream : public Stream
    {
    public:
        explicit SnapshotsRecoveryStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks);
        void StartProcessing() override;
        void HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength) override;
        virtual bool handleSeq(uint32_t sequenceNumber) override;

    private:
        uint32_t totNumReports_{0};
        bool is_first_packet_{true};
    };

    class InstrumentDefinitionStream : public Stream
    {
    public:
        explicit InstrumentDefinitionStream(const MulticastConfig &config, std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> &orderbooks);
        void StartProcessing() override;
        void HandleMessage(const size_t id, char *buffer, const std::uint64_t bufferLength) override;
        virtual bool handleSeq(uint32_t sequenceNumber) override;

    private:
        uint32_t expected_symbols_{0};
        uint32_t totNoRelatedSym_{0};
        bool is_first_packet_{true};
    };

    class Channel : public std::enable_shared_from_this<Channel>
    {
    public:
        explicit Channel(uint32_t id,
                         const B3Config &config);
        // 生命周期控制
        bool Start();
        void Stop();

    private:
        // 线程控制
        void RunStream(std::unique_ptr<Stream> stream);

    private:
        B3Config config_;

        // 线程控制
        std::atomic<bool> running_{false};
        std::thread incremental_thread_;
        std::thread incremental_bak_thread_;
        std::thread instrumentDefinition_thread_;
        std::thread snapshotsRecovery_thread_;

        std::unordered_map<uint64_t, std::shared_ptr<OrderBook>> orderBooks_;
    };
} // namespace B3

#endif // STREAM_HPP