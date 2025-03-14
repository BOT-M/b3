#pragma once
#include "std.hpp"

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
        std::cout << "SequenceVersion: " << ntohs(SequenceVersion) << std::endl;
        std::cout << "SequenceNumber: " << ntohl(SequenceNumber) << std::endl;
        // Convert SendingTime from nanoseconds to std::chrono::system_clock::time_point
        auto sending_time_ns = std::chrono::nanoseconds(SendingTime);
        auto sending_time_sys = std::chrono::system_clock::time_point(sending_time_ns);

        // Convert to local time (BRT/BST, assuming UTC-3)
        std::time_t sending_time_t = std::chrono::system_clock::to_time_t(sending_time_sys);
        std::tm sending_time_tm = *std::localtime(&sending_time_t);

        // Adjust for UTC-3 (BRT/BST)
        sending_time_tm.tm_hour -= 3;
        std::mktime(&sending_time_tm); // Normalize the tm structure

        // Format and print the time
        std::ostringstream time_oss;
        time_oss << std::put_time(&sending_time_tm, "%Y-%m-%d %H:%M:%S");
        std::cout << "SendingTime: " << time_oss.str() << " BRT/BST" << std::endl;

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
        std::cout << "MessageLength: " << ntohs(messageLength) << std::endl;
        std::cout << "EncodingType: 0x" << std::hex << ntohs(encodingType) << std::dec << std::endl;
        std::cout << "BlockLength: " << ntohs(blockLength) << std::endl;
        std::cout << "TemplateID: " << ntohs(templateID) << std::endl;
        std::cout << "SchemaID: " << ntohs(schemaID) << std::endl;
        std::cout << "SchemaVersion: " << ntohs(schemaVersion) << std::endl;
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