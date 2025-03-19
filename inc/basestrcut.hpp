#pragma once
#include "std.hpp"
#include "utils.hpp"

using NumberOfTrades = uint32_t;
using Quantity = int64_t;
using QuantityOptional = std::optional<int64_t>;
using QuantityVolume = int64_t;
using QuantityVolumeOptional = std::optional<int64_t>;
using FirmOptional = std::optional<uint32_t>;
using OrderID = uint64_t;
using TradeID = uint32_t;
using SeqNum = uint32_t;
constexpr uint32_t SeqNum1 = 1;
using SecurityID = uint64_t;
using SecurityIDOptional = std::optional<uint64_t>;
constexpr char SecurityExchangeBVMF[5] = "BVMF";
using SecurityExchange = std::array<char, 4>;
using RptSeq = std::optional<uint32_t>;
using Symbol = std::array<char, 20>;
using ISINNumber = std::array<char, 12>;
using ClearingHouseID = std::optional<uint64_t>;
using NewsID = std::optional<uint64_t>;
using Currency = std::array<char, 3>;
using SecurityStrategyType = std::optional<std::array<char, 3>>;
using Asset = std::array<char, 6>;
using SettlType = uint16_t;
using CFICode = std::array<char, 6>;
using CountryCode = std::array<char, 2>;
using LanguageCode = std::array<char, 2>;
using LocalMktDate = uint16_t;
using LocalMktDateOptional = std::optional<uint16_t>;
using LocalMktDate32 = int32_t;
using LocalMktDate32Optional = std::optional<int32_t>;

// 复合类型
struct Price
{
    int64_t mantissa;
    static constexpr int8_t exponent = -4;
};

struct PriceOptional
{
    std::optional<int64_t> mantissa;
    static constexpr int8_t exponent = -4;
};

struct Percentage
{
    std::optional<int64_t> mantissa = 0;
    static constexpr int8_t exponent = -4;
};

struct RatioQty
{
    std::optional<int64_t> mantissa;
    static constexpr int8_t exponent = -7;
};

struct UTCTimestampNanos
{
    std::optional<uint64_t> time = 0;
    static constexpr uint8_t unit = 1; // TimeUnit.NANOSECOND
};

struct UTCTimestampSeconds
{
    std::optional<int64_t> time;
    static constexpr uint8_t unit = 2; // TimeUnit.SECOND
};

struct PacketHeader
{
    uint8_t ChannelID;
    uint8_t Reserved;
    uint16_t SequenceVersion;
    uint32_t SequenceNumber;
    uint64_t SendingTime;
    void print() const
    {
        std::cout << "=== Packet Header ===" << std::endl;
        std::cout << "ChannelID: " << static_cast<int>(ChannelID) << std::endl;
        std::cout << "Reserved: " << static_cast<int>(Reserved) << std::endl;
        std::cout << "SequenceVersion: " << SequenceVersion << std::endl;
        std::cout << "SequenceNumber: " << SequenceNumber << std::endl;
        std::cout << "SendingTime: " << SendingTime << std::endl;

        print_beijing_time(SendingTime);

        std::cout << "======================" << std::endl;
    }
};

struct MessageHeader
{
    uint16_t messageLength;
    uint16_t encodingType;
    uint16_t blockLength;
    uint16_t templateID;
    uint16_t schemaID;
    uint16_t schemaVersion;
    void print() const
    {
        std::cout << "=== Message Header ===" << std::endl;
        std::cout << "MessageLength: " << messageLength << std::endl;
        std::cout << "EncodingType: " << encodingType << std::dec << std::endl;
        std::cout << "BlockLength: " << blockLength << std::endl;
        std::cout << "TemplateID: " << templateID << std::endl;
        std::cout << "SchemaID: " << schemaID << std::endl;
        std::cout << "SchemaVersion: " << schemaVersion << std::endl;
        std::cout << "======================" << std::endl;
    }
};

struct TradeMessage
{
    uint64_t securityID;
    uint32_t MDEntryBuyer;
    uint32_t MDEntrySeller;
    uint32_t TradeID;
    int64_t MDEntrySize;
    int64_t MDEntryPx;
    void print() const
    {
        std::cout << "=== Trade Message ===" << std::endl;
        std::cout << "SecurityID: " << be64toh(securityID) << std::endl;
        std::cout << "MDEntryBuyer: " << ntohl(MDEntryBuyer) << std::endl;
        std::cout << "MDEntrySeller: " << ntohl(MDEntrySeller) << std::endl;
        std::cout << "TradeID: " << ntohl(TradeID) << std::endl;
        std::cout << "MDEntrySize: " << be64toh(MDEntrySize) << std::endl;
        std::cout << "MDEntryPx: " << be64toh(MDEntryPx) << std::endl;
        std::cout << "======================" << std::endl;
    }
};

#pragma pack(1)

// Order - MBO (创建或修改订单)
struct Order_MBO_50
{
    SecurityID securityID;                 // 证券 ID
    SecurityIDSource securityIDSource;     // Exchange Symbol
    SecurityExchangeBVMF securityExchange; // 市场代码
    uint8_t matchEventIndicator;           // 事件指示符（是否重传）
    uint8_t mDUpdateAction;                // 订单更新类型 (NEW, CHANGE)
    uint8_t mDEntryType;                   // 订单方向 (BID, OFFER)
    double mDEntryPx;                      // 订单价格（可选）
    uint32_t mDEntrySize;                  // 订单数量
    uint32_t mDEntryPositionNo;            // 订单排名位置
    uint32_t enteringFirm;                 // 经纪公司代码
    uint64_t mDInsertTimestamp;            // 订单插入时间戳（纳秒）
    uint64_t secondaryOrderID;             // 交易所生成的订单 ID
    uint32_t rptSeq;                       // 序列号
    uint64_t mDEntryTimestamp;             // 订单事件发生时间（纳秒）
};

// Delete Order - MBO (删除订单)
struct DeleteOrder_MBO_51
{
    static constexpr uint8_t messageType = 'X';
    static constexpr uint16_t applVerID = 1128;  // FIX50SP2
    uint32_t securityID;                         // 证券 ID
    uint8_t securityIDSource;                    // Exchange Symbol
    uint32_t securityExchange;                   // 市场代码
    uint8_t matchEventIndicator;                 // 事件指示符（是否重传）
    static constexpr uint8_t mDUpdateAction = 2; // DELETE 操作
    uint8_t mDEntryType;                         // 订单方向 (BID, OFFER)
    uint32_t mDEntryPositionNo;                  // 订单排名位置
    uint32_t mDEntrySize;                        // 被删除订单的数量（可选）
    uint64_t secondaryOrderID;                   // 交易所生成的订单 ID
    uint64_t mDEntryTimestamp;                   // 订单事件发生时间（纳秒）
    uint32_t rptSeq;                             // 序列号
};

#pragma pack()
