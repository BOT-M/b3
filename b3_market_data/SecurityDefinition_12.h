/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _B3_MARKET_DATA_SECURITYDEFINITION_12_CXX_H_
#define _B3_MARKET_DATA_SECURITYDEFINITION_12_CXX_H_

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#  include <string_view>
#  define SBE_NODISCARD [[nodiscard]]
#  if !defined(SBE_USE_STRING_VIEW)
#    define SBE_USE_STRING_VIEW 1
#  endif
#else
#  define SBE_NODISCARD
#endif

#if __cplusplus >= 202002L
#  include <span>
#  if !defined(SBE_USE_SPAN)
#    define SBE_USE_SPAN 1
#  endif
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <limits>
#include <cstring>
#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#  if defined(SBE_NO_BOUNDS_CHECK)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#  elif defined(_MSC_VER)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#  else 
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#  endif

#endif

#define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()


#include "NewsSource.h"
#include "RatioQty.h"
#include "MaturityMonthYear.h"
#include "Product.h"
#include "MDUpdateAction.h"
#include "TextEncoding.h"
#include "InstrAttribType.h"
#include "TradingSessionID.h"
#include "MultiLegPriceMethod.h"
#include "Fixed8.h"
#include "ImbalanceCondition.h"
#include "Boolean.h"
#include "FramingHeader.h"
#include "MessageType.h"
#include "SecurityTradingStatus.h"
#include "MultiLegModel.h"
#include "SecurityTradingEvent.h"
#include "PriceOffset8Optional.h"
#include "SecurityIDSource.h"
#include "PriceBandType.h"
#include "Price.h"
#include "PriceLimitType.h"
#include "PacketHeader.h"
#include "PriceType.h"
#include "OpenCloseSettlFlag.h"
#include "MatchEventIndicator.h"
#include "SecurityType.h"
#include "LotType.h"
#include "PriceBandMidpointPriceType.h"
#include "PriceOptional.h"
#include "GroupSizeEncoding.h"
#include "Side.h"
#include "Price8.h"
#include "TrdSubType.h"
#include "UTCTimestampSeconds.h"
#include "MDEntryType.h"
#include "ImpliedMarketIndicator.h"
#include "MessageHeader.h"
#include "PutOrCall.h"
#include "Percentage.h"
#include "SecurityUpdateAction.h"
#include "ApplVerID.h"
#include "GovernanceIndicator.h"
#include "UTCTimestampNanos.h"
#include "TradeCondition.h"
#include "AggressorSide.h"
#include "SecurityMatchType.h"
#include "TradingSessionSubID.h"
#include "InstrAttribValue.h"
#include "VarString.h"
#include "SettlPriceType.h"
#include "ExerciseStyle.h"

namespace b3_market_data {

class SecurityDefinition_12
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position = 0;
    std::uint64_t m_actingBlockLength = 0;
    std::uint64_t m_actingVersion = 0;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
    {
        return &m_position;
    }

public:
    static constexpr std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(231);
    static constexpr std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(12);
    static constexpr std::uint16_t SBE_SCHEMA_ID = static_cast<std::uint16_t>(2);
    static constexpr std::uint16_t SBE_SCHEMA_VERSION = static_cast<std::uint16_t>(10);
    static constexpr const char* SBE_SEMANTIC_VERSION = "1.9.0";

    enum MetaAttribute
    {
        EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE
    };

    union sbe_float_as_uint_u
    {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u
    {
        double fp_value;
        std::uint64_t uint_value;
    };

    using messageHeader = MessageHeader;

    SecurityDefinition_12() = default;

    SecurityDefinition_12(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_position(sbeCheckPosition(offset + actingBlockLength)),
        m_actingBlockLength(actingBlockLength),
        m_actingVersion(actingVersion)
    {
    }

    SecurityDefinition_12(char *buffer, const std::uint64_t bufferLength) :
        SecurityDefinition_12(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    SecurityDefinition_12(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        SecurityDefinition_12(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(231);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(12);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(2);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(10);
    }

    SBE_NODISCARD static const char *sbeSemanticVersion() SBE_NOEXCEPT
    {
        return "1.9.0";
    }

    SBE_NODISCARD static SBE_CONSTEXPR const char *sbeSemanticType() SBE_NOEXCEPT
    {
        return "";
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    SecurityDefinition_12 &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    SecurityDefinition_12 &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        messageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr
            .blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset + messageHeader::encodedLength();
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    SecurityDefinition_12 &wrapForDecode(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    SecurityDefinition_12 &sbeRewind()
    {
        return wrapForDecode(m_buffer, m_offset, m_actingBlockLength, m_actingVersion, m_bufferLength);
    }

    SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
    {
        return m_position;
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    std::uint64_t sbeCheckPosition(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position)
    {
        m_position = sbeCheckPosition(position);
    }

    SBE_NODISCARD std::uint64_t encodedLength() const SBE_NOEXCEPT
    {
        return sbePosition() - m_offset;
    }

    SBE_NODISCARD std::uint64_t decodeLength() const
    {
        SecurityDefinition_12 skipper(m_buffer, m_offset, m_bufferLength, m_actingBlockLength, m_actingVersion);
        skipper.skip();
        return skipper.encodedLength();
    }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT
    {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT
    {
        return m_actingVersion;
    }

    SBE_NODISCARD static const char *messageTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "constant";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t messageTypeId() SBE_NOEXCEPT
    {
        return 35;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t messageTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool messageTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t messageTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t messageTypeEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD static SBE_CONSTEXPR MessageType::Value messageTypeConstValue() SBE_NOEXCEPT
    {
        return MessageType::Value::SecurityDefinition;
    }

    SBE_NODISCARD MessageType::Value messageType() const
    {
        return MessageType::Value::SecurityDefinition;
    }

    SBE_NODISCARD char messageTypeRaw() const SBE_NOEXCEPT
    {
        return static_cast<char>(MessageType::Value::SecurityDefinition);
    }

    SBE_NODISCARD static const char *applVerIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "constant";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t applVerIDId() SBE_NOEXCEPT
    {
        return 1128;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t applVerIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool applVerIDInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t applVerIDEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t applVerIDEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD static SBE_CONSTEXPR ApplVerID::Value applVerIDConstValue() SBE_NOEXCEPT
    {
        return ApplVerID::Value::FIX50SP2;
    }

    SBE_NODISCARD ApplVerID::Value applVerID() const
    {
        return ApplVerID::Value::FIX50SP2;
    }

    SBE_NODISCARD std::uint8_t applVerIDRaw() const SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(ApplVerID::Value::FIX50SP2);
    }

    SBE_NODISCARD static const char *securityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityIDId() SBE_NOEXCEPT
    {
        return 48;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityIDInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityIDEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint64_t securityIDNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR std::uint64_t securityIDMinValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t securityIDMaxValue() SBE_NOEXCEPT
    {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t securityIDEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t securityID() const SBE_NOEXCEPT
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &securityID(const std::uint64_t value) SBE_NOEXCEPT
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *securityExchangeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityExchangeId() SBE_NOEXCEPT
    {
        return 207;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityExchangeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityExchangeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityExchangeEncodingOffset() SBE_NOEXCEPT
    {
        return 8;
    }

    static SBE_CONSTEXPR char securityExchangeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityExchangeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityExchangeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityExchangeEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    static SBE_CONSTEXPR std::uint64_t securityExchangeLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD const char *securityExchange() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 8;
    }

    SBE_NODISCARD char *securityExchange() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 8;
    }

    SBE_NODISCARD char securityExchange(const std::uint64_t index) const
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for securityExchange [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 8 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &securityExchange(const std::uint64_t index, const char value)
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for securityExchange [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 8 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSecurityExchange(char *const dst, const std::uint64_t length) const
    {
        if (length > 4)
        {
            throw std::runtime_error("length too large for getSecurityExchange [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 8, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getSecurityExchangeAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 8;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 4);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityExchange(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 4, "array too large for putSecurityExchange");

        std::memcpy(m_buffer + m_offset + 8, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 4; ++start)
        {
            m_buffer[m_offset + 8 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putSecurityExchange(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putSecurityExchange(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 8, src, sizeof(char) * 4);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityExchange(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putSecurityExchange(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putSecurityExchange(
        const char value0,
        const char value1,
        const char value2,
        const char value3) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 8, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 9, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 10, &val2, sizeof(char));
        char val3 = (value3);
        std::memcpy(m_buffer + m_offset + 11, &val3, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSecurityExchangeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 8;
        std::size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSecurityExchangeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityExchangeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getSecurityExchangeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 8;
        std::size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putSecurityExchange(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putSecurityExchange [E106]");
        }

        std::memcpy(m_buffer + m_offset + 8, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 8 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putSecurityExchange(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putSecurityExchange [E106]");
        }

        std::memcpy(m_buffer + m_offset + 8, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 8 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *securityIDSourceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityIDSourceId() SBE_NOEXCEPT
    {
        return 22;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityIDSourceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityIDSourceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityIDSourceEncodingOffset() SBE_NOEXCEPT
    {
        return 12;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityIDSourceEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD char securityIDSourceRaw() const SBE_NOEXCEPT
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 12, sizeof(char));
        return (val);
    }

    SBE_NODISCARD SecurityIDSource::Value securityIDSource() const
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 12, sizeof(char));
        return SecurityIDSource::get((val));
    }

    SecurityDefinition_12 &securityIDSource(const SecurityIDSource::Value value) SBE_NOEXCEPT
    {
        char val = (value);
        std::memcpy(m_buffer + m_offset + 12, &val, sizeof(char));
        return *this;
    }

    SBE_NODISCARD static const char *securityGroupMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityGroupId() SBE_NOEXCEPT
    {
        return 1151;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityGroupSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityGroupInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityGroupEncodingOffset() SBE_NOEXCEPT
    {
        return 13;
    }

    static SBE_CONSTEXPR char securityGroupNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityGroupMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityGroupMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityGroupEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t securityGroupLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *securityGroup() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 13;
    }

    SBE_NODISCARD char *securityGroup() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 13;
    }

    SBE_NODISCARD char securityGroup(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for securityGroup [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 13 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &securityGroup(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for securityGroup [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 13 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSecurityGroup(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getSecurityGroup [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 13, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getSecurityGroupAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 13;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 3);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityGroup(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 3, "array too large for putSecurityGroup");

        std::memcpy(m_buffer + m_offset + 13, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 3; ++start)
        {
            m_buffer[m_offset + 13 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putSecurityGroup(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putSecurityGroup(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 13, src, sizeof(char) * 3);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityGroup(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putSecurityGroup(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putSecurityGroup(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 13, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 14, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 15, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSecurityGroupAsString() const
    {
        const char *buffer = m_buffer + m_offset + 13;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSecurityGroupAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityGroupAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getSecurityGroupAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 13;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putSecurityGroup(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSecurityGroup [E106]");
        }

        std::memcpy(m_buffer + m_offset + 13, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 13 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putSecurityGroup(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSecurityGroup [E106]");
        }

        std::memcpy(m_buffer + m_offset + 13, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 13 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *symbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t symbolId() SBE_NOEXCEPT
    {
        return 55;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t symbolSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool symbolInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t symbolEncodingOffset() SBE_NOEXCEPT
    {
        return 16;
    }

    static SBE_CONSTEXPR char symbolNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char symbolMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char symbolMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t symbolEncodingLength() SBE_NOEXCEPT
    {
        return 20;
    }

    static SBE_CONSTEXPR std::uint64_t symbolLength() SBE_NOEXCEPT
    {
        return 20;
    }

    SBE_NODISCARD const char *symbol() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 16;
    }

    SBE_NODISCARD char *symbol() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 16;
    }

    SBE_NODISCARD char symbol(const std::uint64_t index) const
    {
        if (index >= 20)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 16 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &symbol(const std::uint64_t index, const char value)
    {
        if (index >= 20)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 16 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSymbol(char *const dst, const std::uint64_t length) const
    {
        if (length > 20)
        {
            throw std::runtime_error("length too large for getSymbol [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 16, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getSymbolAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 16;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 20);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSymbol(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 20, "array too large for putSymbol");

        std::memcpy(m_buffer + m_offset + 16, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 20; ++start)
        {
            m_buffer[m_offset + 16 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putSymbol(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putSymbol(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 16, src, sizeof(char) * 20);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSymbol(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putSymbol(std::span<const char, N>(src));
    }
    #endif

    SBE_NODISCARD std::string getSymbolAsString() const
    {
        const char *buffer = m_buffer + m_offset + 16;
        std::size_t length = 0;

        for (; length < 20 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSymbolAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSymbolAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getSymbolAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 16;
        std::size_t length = 0;

        for (; length < 20 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putSymbol(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 20)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 16, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 20; ++start)
        {
            m_buffer[m_offset + 16 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putSymbol(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 20)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 16, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 20; ++start)
        {
            m_buffer[m_offset + 16 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *securityUpdateActionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityUpdateActionId() SBE_NOEXCEPT
    {
        return 980;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityUpdateActionSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityUpdateActionInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityUpdateActionEncodingOffset() SBE_NOEXCEPT
    {
        return 36;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityUpdateActionEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD char securityUpdateActionRaw() const SBE_NOEXCEPT
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 36, sizeof(char));
        return (val);
    }

    SBE_NODISCARD SecurityUpdateAction::Value securityUpdateAction() const
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 36, sizeof(char));
        return SecurityUpdateAction::get((val));
    }

    SecurityDefinition_12 &securityUpdateAction(const SecurityUpdateAction::Value value) SBE_NOEXCEPT
    {
        char val = (value);
        std::memcpy(m_buffer + m_offset + 36, &val, sizeof(char));
        return *this;
    }

    SBE_NODISCARD static const char *securityTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityTypeId() SBE_NOEXCEPT
    {
        return 167;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 37;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t securityTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 37, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD SecurityType::Value securityType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 37, sizeof(std::uint8_t));
        return SecurityType::get((val));
    }

    SecurityDefinition_12 &securityType(const SecurityType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 37, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *securitySubTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securitySubTypeId() SBE_NOEXCEPT
    {
        return 762;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securitySubTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securitySubTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securitySubTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 38;
    }

    static SBE_CONSTEXPR std::uint16_t securitySubTypeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t securitySubTypeMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    static SBE_CONSTEXPR std::uint16_t securitySubTypeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(65534);
    }

    static SBE_CONSTEXPR std::size_t securitySubTypeEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint16_t securitySubType() const SBE_NOEXCEPT
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 38, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    SecurityDefinition_12 &securitySubType(const std::uint16_t value) SBE_NOEXCEPT
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 38, &val, sizeof(std::uint16_t));
        return *this;
    }

    SBE_NODISCARD static const char *totNoRelatedSymMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t totNoRelatedSymId() SBE_NOEXCEPT
    {
        return 393;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t totNoRelatedSymSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool totNoRelatedSymInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t totNoRelatedSymEncodingOffset() SBE_NOEXCEPT
    {
        return 40;
    }

    static SBE_CONSTEXPR std::uint32_t totNoRelatedSymNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t totNoRelatedSymMinValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t totNoRelatedSymMaxValue() SBE_NOEXCEPT
    {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t totNoRelatedSymEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::uint32_t totNoRelatedSym() const SBE_NOEXCEPT
    {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 40, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &totNoRelatedSym(const std::uint32_t value) SBE_NOEXCEPT
    {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 40, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *minPriceIncrementMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minPriceIncrementId() SBE_NOEXCEPT
    {
        return 969;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minPriceIncrementSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minPriceIncrementInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minPriceIncrementEncodingOffset() SBE_NOEXCEPT
    {
        return 44;
    }

private:
    Fixed8 m_minPriceIncrement;

public:
    SBE_NODISCARD Fixed8 &minPriceIncrement()
    {
        m_minPriceIncrement.wrap(m_buffer, m_offset + 44, m_actingVersion, m_bufferLength);
        return m_minPriceIncrement;
    }

    SBE_NODISCARD static const char *strikePriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t strikePriceId() SBE_NOEXCEPT
    {
        return 202;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t strikePriceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool strikePriceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t strikePriceEncodingOffset() SBE_NOEXCEPT
    {
        return 52;
    }

private:
    PriceOptional m_strikePrice;

public:
    SBE_NODISCARD PriceOptional &strikePrice()
    {
        m_strikePrice.wrap(m_buffer, m_offset + 52, m_actingVersion, m_bufferLength);
        return m_strikePrice;
    }

    SBE_NODISCARD static const char *contractMultiplierMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t contractMultiplierId() SBE_NOEXCEPT
    {
        return 231;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t contractMultiplierSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool contractMultiplierInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t contractMultiplierEncodingOffset() SBE_NOEXCEPT
    {
        return 60;
    }

private:
    Fixed8 m_contractMultiplier;

public:
    SBE_NODISCARD Fixed8 &contractMultiplier()
    {
        m_contractMultiplier.wrap(m_buffer, m_offset + 60, m_actingVersion, m_bufferLength);
        return m_contractMultiplier;
    }

    SBE_NODISCARD static const char *priceDivisorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t priceDivisorId() SBE_NOEXCEPT
    {
        return 37012;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceDivisorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool priceDivisorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceDivisorEncodingOffset() SBE_NOEXCEPT
    {
        return 68;
    }

private:
    Fixed8 m_priceDivisor;

public:
    SBE_NODISCARD Fixed8 &priceDivisor()
    {
        m_priceDivisor.wrap(m_buffer, m_offset + 68, m_actingVersion, m_bufferLength);
        return m_priceDivisor;
    }

    SBE_NODISCARD static const char *securityValidityTimestampMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityValidityTimestampId() SBE_NOEXCEPT
    {
        return 6938;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityValidityTimestampSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityValidityTimestampInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityValidityTimestampEncodingOffset() SBE_NOEXCEPT
    {
        return 76;
    }

private:
    UTCTimestampSeconds m_securityValidityTimestamp;

public:
    SBE_NODISCARD UTCTimestampSeconds &securityValidityTimestamp()
    {
        m_securityValidityTimestamp.wrap(m_buffer, m_offset + 76, m_actingVersion, m_bufferLength);
        return m_securityValidityTimestamp;
    }

    SBE_NODISCARD static const char *noSharesIssuedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t noSharesIssuedId() SBE_NOEXCEPT
    {
        return 7595;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noSharesIssuedSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noSharesIssuedInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t noSharesIssuedEncodingOffset() SBE_NOEXCEPT
    {
        return 84;
    }

    static SBE_CONSTEXPR std::uint64_t noSharesIssuedNullValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t noSharesIssuedMinValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t noSharesIssuedMaxValue() SBE_NOEXCEPT
    {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t noSharesIssuedEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t noSharesIssued() const SBE_NOEXCEPT
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 84, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &noSharesIssued(const std::uint64_t value) SBE_NOEXCEPT
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 84, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *clearingHouseIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t clearingHouseIDId() SBE_NOEXCEPT
    {
        return 37037;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t clearingHouseIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool clearingHouseIDInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t clearingHouseIDEncodingOffset() SBE_NOEXCEPT
    {
        return 92;
    }

    static SBE_CONSTEXPR std::uint64_t clearingHouseIDNullValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t clearingHouseIDMinValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t clearingHouseIDMaxValue() SBE_NOEXCEPT
    {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t clearingHouseIDEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t clearingHouseID() const SBE_NOEXCEPT
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 92, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &clearingHouseID(const std::uint64_t value) SBE_NOEXCEPT
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 92, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *minOrderQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minOrderQtyId() SBE_NOEXCEPT
    {
        return 9749;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minOrderQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minOrderQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minOrderQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 100;
    }

    static SBE_CONSTEXPR std::int64_t minOrderQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t minOrderQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t minOrderQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t minOrderQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t minOrderQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 100, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &minOrderQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 100, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *maxOrderQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t maxOrderQtyId() SBE_NOEXCEPT
    {
        return 9748;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t maxOrderQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool maxOrderQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t maxOrderQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 108;
    }

    static SBE_CONSTEXPR std::int64_t maxOrderQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t maxOrderQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t maxOrderQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t maxOrderQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t maxOrderQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 108, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &maxOrderQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 108, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *minLotSizeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minLotSizeId() SBE_NOEXCEPT
    {
        return 1231;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minLotSizeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minLotSizeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minLotSizeEncodingOffset() SBE_NOEXCEPT
    {
        return 116;
    }

    static SBE_CONSTEXPR std::int64_t minLotSizeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t minLotSizeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t minLotSizeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t minLotSizeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t minLotSize() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 116, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &minLotSize(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 116, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *minTradeVolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minTradeVolId() SBE_NOEXCEPT
    {
        return 562;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minTradeVolSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minTradeVolInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minTradeVolEncodingOffset() SBE_NOEXCEPT
    {
        return 124;
    }

    static SBE_CONSTEXPR std::int64_t minTradeVolNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t minTradeVolMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t minTradeVolMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t minTradeVolEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t minTradeVol() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 124, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &minTradeVol(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 124, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *corporateActionEventIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t corporateActionEventIdId() SBE_NOEXCEPT
    {
        return 37010;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t corporateActionEventIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool corporateActionEventIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t corporateActionEventIdEncodingOffset() SBE_NOEXCEPT
    {
        return 132;
    }

    static SBE_CONSTEXPR std::uint32_t corporateActionEventIdNullValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t corporateActionEventIdMinValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t corporateActionEventIdMaxValue() SBE_NOEXCEPT
    {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t corporateActionEventIdEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::uint32_t corporateActionEventId() const SBE_NOEXCEPT
    {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 132, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &corporateActionEventId(const std::uint32_t value) SBE_NOEXCEPT
    {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 132, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *issueDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t issueDateId() SBE_NOEXCEPT
    {
        return 225;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t issueDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool issueDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t issueDateEncodingOffset() SBE_NOEXCEPT
    {
        return 136;
    }

    static SBE_CONSTEXPR std::int32_t issueDateNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t issueDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t issueDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t issueDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t issueDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 136, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &issueDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 136, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *maturityDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t maturityDateId() SBE_NOEXCEPT
    {
        return 541;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t maturityDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool maturityDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t maturityDateEncodingOffset() SBE_NOEXCEPT
    {
        return 140;
    }

    static SBE_CONSTEXPR std::int32_t maturityDateNullValue() SBE_NOEXCEPT
    {
        return INT32_C(0);
    }

    static SBE_CONSTEXPR std::int32_t maturityDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t maturityDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t maturityDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t maturityDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 140, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &maturityDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 140, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *countryOfIssueMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t countryOfIssueId() SBE_NOEXCEPT
    {
        return 470;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t countryOfIssueSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool countryOfIssueInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t countryOfIssueEncodingOffset() SBE_NOEXCEPT
    {
        return 144;
    }

    static SBE_CONSTEXPR char countryOfIssueNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char countryOfIssueMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char countryOfIssueMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t countryOfIssueEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    static SBE_CONSTEXPR std::uint64_t countryOfIssueLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD const char *countryOfIssue() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 144;
    }

    SBE_NODISCARD char *countryOfIssue() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 144;
    }

    SBE_NODISCARD char countryOfIssue(const std::uint64_t index) const
    {
        if (index >= 2)
        {
            throw std::runtime_error("index out of range for countryOfIssue [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 144 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &countryOfIssue(const std::uint64_t index, const char value)
    {
        if (index >= 2)
        {
            throw std::runtime_error("index out of range for countryOfIssue [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 144 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getCountryOfIssue(char *const dst, const std::uint64_t length) const
    {
        if (length > 2)
        {
            throw std::runtime_error("length too large for getCountryOfIssue [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 144, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getCountryOfIssueAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 144;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 2);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCountryOfIssue(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 2, "array too large for putCountryOfIssue");

        std::memcpy(m_buffer + m_offset + 144, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 2; ++start)
        {
            m_buffer[m_offset + 144 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putCountryOfIssue(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putCountryOfIssue(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 144, src, sizeof(char) * 2);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCountryOfIssue(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putCountryOfIssue(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putCountryOfIssue(
        const char value0,
        const char value1) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 144, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 145, &val1, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getCountryOfIssueAsString() const
    {
        const char *buffer = m_buffer + m_offset + 144;
        std::size_t length = 0;

        for (; length < 2 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getCountryOfIssueAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getCountryOfIssueAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getCountryOfIssueAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 144;
        std::size_t length = 0;

        for (; length < 2 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putCountryOfIssue(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 2)
        {
            throw std::runtime_error("string too large for putCountryOfIssue [E106]");
        }

        std::memcpy(m_buffer + m_offset + 144, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 2; ++start)
        {
            m_buffer[m_offset + 144 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putCountryOfIssue(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 2)
        {
            throw std::runtime_error("string too large for putCountryOfIssue [E106]");
        }

        std::memcpy(m_buffer + m_offset + 144, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 2; ++start)
        {
            m_buffer[m_offset + 144 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *startDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t startDateId() SBE_NOEXCEPT
    {
        return 916;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t startDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool startDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t startDateEncodingOffset() SBE_NOEXCEPT
    {
        return 146;
    }

    static SBE_CONSTEXPR std::int32_t startDateNullValue() SBE_NOEXCEPT
    {
        return INT32_C(0);
    }

    static SBE_CONSTEXPR std::int32_t startDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t startDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t startDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t startDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 146, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &startDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 146, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *endDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t endDateId() SBE_NOEXCEPT
    {
        return 917;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t endDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool endDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t endDateEncodingOffset() SBE_NOEXCEPT
    {
        return 150;
    }

    static SBE_CONSTEXPR std::int32_t endDateNullValue() SBE_NOEXCEPT
    {
        return INT32_C(0);
    }

    static SBE_CONSTEXPR std::int32_t endDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t endDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t endDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t endDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 150, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &endDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 150, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *settlTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t settlTypeId() SBE_NOEXCEPT
    {
        return 63;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t settlTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool settlTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t settlTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 154;
    }

    static SBE_CONSTEXPR std::uint16_t settlTypeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t settlTypeMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    static SBE_CONSTEXPR std::uint16_t settlTypeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(65534);
    }

    static SBE_CONSTEXPR std::size_t settlTypeEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint16_t settlType() const SBE_NOEXCEPT
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 154, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    SecurityDefinition_12 &settlType(const std::uint16_t value) SBE_NOEXCEPT
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 154, &val, sizeof(std::uint16_t));
        return *this;
    }

    SBE_NODISCARD static const char *settlDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t settlDateId() SBE_NOEXCEPT
    {
        return 64;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t settlDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool settlDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t settlDateEncodingOffset() SBE_NOEXCEPT
    {
        return 156;
    }

    static SBE_CONSTEXPR std::int32_t settlDateNullValue() SBE_NOEXCEPT
    {
        return INT32_C(0);
    }

    static SBE_CONSTEXPR std::int32_t settlDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t settlDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t settlDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t settlDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 156, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &settlDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 156, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *datedDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t datedDateId() SBE_NOEXCEPT
    {
        return 873;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t datedDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool datedDateInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t datedDateEncodingOffset() SBE_NOEXCEPT
    {
        return 160;
    }

    static SBE_CONSTEXPR std::int32_t datedDateNullValue() SBE_NOEXCEPT
    {
        return INT32_C(0);
    }

    static SBE_CONSTEXPR std::int32_t datedDateMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t datedDateMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t datedDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t datedDate() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 160, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition_12 &datedDate(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 160, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *isinNumberMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t isinNumberId() SBE_NOEXCEPT
    {
        return 37026;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t isinNumberSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool isinNumberInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t isinNumberEncodingOffset() SBE_NOEXCEPT
    {
        return 164;
    }

    static SBE_CONSTEXPR char isinNumberNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char isinNumberMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char isinNumberMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t isinNumberEncodingLength() SBE_NOEXCEPT
    {
        return 12;
    }

    static SBE_CONSTEXPR std::uint64_t isinNumberLength() SBE_NOEXCEPT
    {
        return 12;
    }

    SBE_NODISCARD const char *isinNumber() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 164;
    }

    SBE_NODISCARD char *isinNumber() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 164;
    }

    SBE_NODISCARD char isinNumber(const std::uint64_t index) const
    {
        if (index >= 12)
        {
            throw std::runtime_error("index out of range for isinNumber [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 164 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &isinNumber(const std::uint64_t index, const char value)
    {
        if (index >= 12)
        {
            throw std::runtime_error("index out of range for isinNumber [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 164 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getIsinNumber(char *const dst, const std::uint64_t length) const
    {
        if (length > 12)
        {
            throw std::runtime_error("length too large for getIsinNumber [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 164, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getIsinNumberAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 164;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 12);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putIsinNumber(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 12, "array too large for putIsinNumber");

        std::memcpy(m_buffer + m_offset + 164, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 12; ++start)
        {
            m_buffer[m_offset + 164 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putIsinNumber(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putIsinNumber(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 164, src, sizeof(char) * 12);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putIsinNumber(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putIsinNumber(std::span<const char, N>(src));
    }
    #endif

    SBE_NODISCARD std::string getIsinNumberAsString() const
    {
        const char *buffer = m_buffer + m_offset + 164;
        std::size_t length = 0;

        for (; length < 12 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getIsinNumberAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getIsinNumberAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getIsinNumberAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 164;
        std::size_t length = 0;

        for (; length < 12 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putIsinNumber(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 12)
        {
            throw std::runtime_error("string too large for putIsinNumber [E106]");
        }

        std::memcpy(m_buffer + m_offset + 164, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 12; ++start)
        {
            m_buffer[m_offset + 164 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putIsinNumber(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 12)
        {
            throw std::runtime_error("string too large for putIsinNumber [E106]");
        }

        std::memcpy(m_buffer + m_offset + 164, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 12; ++start)
        {
            m_buffer[m_offset + 164 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *assetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t assetId() SBE_NOEXCEPT
    {
        return 6937;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t assetSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool assetInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t assetEncodingOffset() SBE_NOEXCEPT
    {
        return 176;
    }

    static SBE_CONSTEXPR char assetNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char assetMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char assetMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t assetEncodingLength() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t assetLength() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD const char *asset() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 176;
    }

    SBE_NODISCARD char *asset() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 176;
    }

    SBE_NODISCARD char asset(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for asset [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 176 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &asset(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for asset [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 176 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getAsset(char *const dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
            throw std::runtime_error("length too large for getAsset [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 176, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getAssetAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 176;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 6);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putAsset(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 6, "array too large for putAsset");

        std::memcpy(m_buffer + m_offset + 176, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 6; ++start)
        {
            m_buffer[m_offset + 176 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putAsset(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putAsset(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 176, src, sizeof(char) * 6);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putAsset(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putAsset(std::span<const char, N>(src));
    }
    #endif

    SBE_NODISCARD std::string getAssetAsString() const
    {
        const char *buffer = m_buffer + m_offset + 176;
        std::size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getAssetAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getAssetAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getAssetAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 176;
        std::size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putAsset(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putAsset [E106]");
        }

        std::memcpy(m_buffer + m_offset + 176, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 176 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putAsset(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putAsset [E106]");
        }

        std::memcpy(m_buffer + m_offset + 176, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 176 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *cfiCodeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t cfiCodeId() SBE_NOEXCEPT
    {
        return 461;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t cfiCodeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool cfiCodeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t cfiCodeEncodingOffset() SBE_NOEXCEPT
    {
        return 182;
    }

    static SBE_CONSTEXPR char cfiCodeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char cfiCodeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char cfiCodeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t cfiCodeEncodingLength() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t cfiCodeLength() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD const char *cfiCode() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 182;
    }

    SBE_NODISCARD char *cfiCode() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 182;
    }

    SBE_NODISCARD char cfiCode(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for cfiCode [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 182 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &cfiCode(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for cfiCode [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 182 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getCfiCode(char *const dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
            throw std::runtime_error("length too large for getCfiCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 182, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getCfiCodeAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 182;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 6);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCfiCode(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 6, "array too large for putCfiCode");

        std::memcpy(m_buffer + m_offset + 182, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 6; ++start)
        {
            m_buffer[m_offset + 182 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putCfiCode(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putCfiCode(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 182, src, sizeof(char) * 6);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCfiCode(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putCfiCode(std::span<const char, N>(src));
    }
    #endif

    SBE_NODISCARD std::string getCfiCodeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 182;
        std::size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getCfiCodeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getCfiCodeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getCfiCodeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 182;
        std::size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putCfiCode(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putCfiCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 182, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 182 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putCfiCode(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putCfiCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 182, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 182 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *maturityMonthYearMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t maturityMonthYearId() SBE_NOEXCEPT
    {
        return 200;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t maturityMonthYearSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool maturityMonthYearInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t maturityMonthYearEncodingOffset() SBE_NOEXCEPT
    {
        return 188;
    }

private:
    MaturityMonthYear m_maturityMonthYear;

public:
    SBE_NODISCARD MaturityMonthYear &maturityMonthYear()
    {
        m_maturityMonthYear.wrap(m_buffer, m_offset + 188, m_actingVersion, m_bufferLength);
        return m_maturityMonthYear;
    }

    SBE_NODISCARD static const char *contractSettlMonthMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t contractSettlMonthId() SBE_NOEXCEPT
    {
        return 667;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t contractSettlMonthSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool contractSettlMonthInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t contractSettlMonthEncodingOffset() SBE_NOEXCEPT
    {
        return 193;
    }

private:
    MaturityMonthYear m_contractSettlMonth;

public:
    SBE_NODISCARD MaturityMonthYear &contractSettlMonth()
    {
        m_contractSettlMonth.wrap(m_buffer, m_offset + 193, m_actingVersion, m_bufferLength);
        return m_contractSettlMonth;
    }

    SBE_NODISCARD static const char *currencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t currencyId() SBE_NOEXCEPT
    {
        return 15;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t currencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool currencyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t currencyEncodingOffset() SBE_NOEXCEPT
    {
        return 198;
    }

    static SBE_CONSTEXPR char currencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char currencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char currencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t currencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t currencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *currency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 198;
    }

    SBE_NODISCARD char *currency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 198;
    }

    SBE_NODISCARD char currency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for currency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 198 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &currency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for currency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 198 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 198, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getCurrencyAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 198;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 3);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCurrency(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 3, "array too large for putCurrency");

        std::memcpy(m_buffer + m_offset + 198, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 3; ++start)
        {
            m_buffer[m_offset + 198 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putCurrency(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putCurrency(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 198, src, sizeof(char) * 3);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putCurrency(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putCurrency(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 198, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 199, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 200, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 198;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 198;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putCurrency(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 198, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 198 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putCurrency(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 198, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 198 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *strikeCurrencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t strikeCurrencyId() SBE_NOEXCEPT
    {
        return 947;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t strikeCurrencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool strikeCurrencyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t strikeCurrencyEncodingOffset() SBE_NOEXCEPT
    {
        return 201;
    }

    static SBE_CONSTEXPR char strikeCurrencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char strikeCurrencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char strikeCurrencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t strikeCurrencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t strikeCurrencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *strikeCurrency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 201;
    }

    SBE_NODISCARD char *strikeCurrency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 201;
    }

    SBE_NODISCARD char strikeCurrency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for strikeCurrency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 201 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &strikeCurrency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for strikeCurrency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 201 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getStrikeCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getStrikeCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 201, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getStrikeCurrencyAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 201;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 3);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putStrikeCurrency(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 3, "array too large for putStrikeCurrency");

        std::memcpy(m_buffer + m_offset + 201, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 3; ++start)
        {
            m_buffer[m_offset + 201 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putStrikeCurrency(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putStrikeCurrency(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 201, src, sizeof(char) * 3);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putStrikeCurrency(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putStrikeCurrency(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putStrikeCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 201, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 202, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 203, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getStrikeCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 201;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getStrikeCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getStrikeCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getStrikeCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 201;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putStrikeCurrency(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putStrikeCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 201, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 201 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putStrikeCurrency(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putStrikeCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 201, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 201 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *settlCurrencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t settlCurrencyId() SBE_NOEXCEPT
    {
        return 120;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t settlCurrencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool settlCurrencyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t settlCurrencyEncodingOffset() SBE_NOEXCEPT
    {
        return 204;
    }

    static SBE_CONSTEXPR char settlCurrencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char settlCurrencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char settlCurrencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t settlCurrencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t settlCurrencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *settlCurrency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 204;
    }

    SBE_NODISCARD char *settlCurrency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 204;
    }

    SBE_NODISCARD char settlCurrency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for settlCurrency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 204 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &settlCurrency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for settlCurrency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 204 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSettlCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getSettlCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 204, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getSettlCurrencyAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 204;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 3);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSettlCurrency(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 3, "array too large for putSettlCurrency");

        std::memcpy(m_buffer + m_offset + 204, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 3; ++start)
        {
            m_buffer[m_offset + 204 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putSettlCurrency(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putSettlCurrency(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 204, src, sizeof(char) * 3);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSettlCurrency(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putSettlCurrency(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putSettlCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 204, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 205, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 206, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSettlCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 204;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSettlCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSettlCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getSettlCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 204;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putSettlCurrency(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSettlCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 204, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 204 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putSettlCurrency(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSettlCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 204, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 204 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *securityStrategyTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityStrategyTypeId() SBE_NOEXCEPT
    {
        return 7534;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityStrategyTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityStrategyTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityStrategyTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 207;
    }

    static SBE_CONSTEXPR char securityStrategyTypeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityStrategyTypeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityStrategyTypeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityStrategyTypeEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t securityStrategyTypeLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *securityStrategyType() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 207;
    }

    SBE_NODISCARD char *securityStrategyType() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 207;
    }

    SBE_NODISCARD char securityStrategyType(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for securityStrategyType [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 207 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition_12 &securityStrategyType(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for securityStrategyType [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 207 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSecurityStrategyType(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getSecurityStrategyType [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 207, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    #ifdef SBE_USE_SPAN
    SBE_NODISCARD std::span<const char> getSecurityStrategyTypeAsSpan() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 207;
        return std::span<const char>(reinterpret_cast<const char*>(buffer), 3);
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityStrategyType(std::span<const char, N> src) SBE_NOEXCEPT
    {
        static_assert(N <= 3, "array too large for putSecurityStrategyType");

        std::memcpy(m_buffer + m_offset + 207, src.data(), sizeof(char) * N);
        for (std::size_t start = N; start < 3; ++start)
        {
            m_buffer[m_offset + 207 + start] = 0;
        }

        return *this;
    }
    #endif

    #ifdef SBE_USE_SPAN
    template <typename T>
    SecurityDefinition_12 &putSecurityStrategyType(T&& src)  SBE_NOEXCEPT requires
        (std::is_pointer_v<std::remove_reference_t<T>> &&
         !std::is_array_v<std::remove_reference_t<T>>)
    #else
    SecurityDefinition_12 &putSecurityStrategyType(const char *const src) SBE_NOEXCEPT
    #endif
    {
        std::memcpy(m_buffer + m_offset + 207, src, sizeof(char) * 3);
        return *this;
    }

    #ifdef SBE_USE_SPAN
    template <std::size_t N>
    SecurityDefinition_12 &putSecurityStrategyType(const char (&src)[N]) SBE_NOEXCEPT
    {
        return putSecurityStrategyType(std::span<const char, N>(src));
    }
    #endif

    SecurityDefinition_12 &putSecurityStrategyType(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 207, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 208, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 209, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSecurityStrategyTypeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 207;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSecurityStrategyTypeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityStrategyTypeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #ifdef SBE_USE_STRING_VIEW
    SBE_NODISCARD std::string_view getSecurityStrategyTypeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 207;
        std::size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #ifdef SBE_USE_STRING_VIEW
    SecurityDefinition_12 &putSecurityStrategyType(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSecurityStrategyType [E106]");
        }

        std::memcpy(m_buffer + m_offset + 207, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 207 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition_12 &putSecurityStrategyType(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSecurityStrategyType [E106]");
        }

        std::memcpy(m_buffer + m_offset + 207, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 207 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *lotTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t lotTypeId() SBE_NOEXCEPT
    {
        return 1093;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lotTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool lotTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t lotTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 210;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t lotTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t lotTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 210, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD LotType::Value lotType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 210, sizeof(std::uint8_t));
        return LotType::get((val));
    }

    SecurityDefinition_12 &lotType(const LotType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 210, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *tickSizeDenominatorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t tickSizeDenominatorId() SBE_NOEXCEPT
    {
        return 5151;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tickSizeDenominatorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool tickSizeDenominatorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t tickSizeDenominatorEncodingOffset() SBE_NOEXCEPT
    {
        return 211;
    }

    static SBE_CONSTEXPR std::uint8_t tickSizeDenominatorNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR std::uint8_t tickSizeDenominatorMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(0);
    }

    static SBE_CONSTEXPR std::uint8_t tickSizeDenominatorMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(254);
    }

    static SBE_CONSTEXPR std::size_t tickSizeDenominatorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t tickSizeDenominator() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 211, sizeof(std::uint8_t));
        return (val);
    }

    SecurityDefinition_12 &tickSizeDenominator(const std::uint8_t value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 211, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *productMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t productId() SBE_NOEXCEPT
    {
        return 460;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t productSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool productInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t productEncodingOffset() SBE_NOEXCEPT
    {
        return 212;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t productEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t productRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 212, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD Product::Value product() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 212, sizeof(std::uint8_t));
        return Product::get((val));
    }

    SecurityDefinition_12 &product(const Product::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 212, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *exerciseStyleMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t exerciseStyleId() SBE_NOEXCEPT
    {
        return 1194;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exerciseStyleSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exerciseStyleInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exerciseStyleEncodingOffset() SBE_NOEXCEPT
    {
        return 213;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exerciseStyleEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t exerciseStyleRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 213, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD ExerciseStyle::Value exerciseStyle() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 213, sizeof(std::uint8_t));
        return ExerciseStyle::get((val));
    }

    SecurityDefinition_12 &exerciseStyle(const ExerciseStyle::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 213, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *putOrCallMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t putOrCallId() SBE_NOEXCEPT
    {
        return 201;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t putOrCallSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool putOrCallInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t putOrCallEncodingOffset() SBE_NOEXCEPT
    {
        return 214;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t putOrCallEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t putOrCallRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 214, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD PutOrCall::Value putOrCall() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 214, sizeof(std::uint8_t));
        return PutOrCall::get((val));
    }

    SecurityDefinition_12 &putOrCall(const PutOrCall::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 214, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *priceTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t priceTypeId() SBE_NOEXCEPT
    {
        return 423;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool priceTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 215;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t priceTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 215, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD PriceType::Value priceType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 215, sizeof(std::uint8_t));
        return PriceType::get((val));
    }

    SecurityDefinition_12 &priceType(const PriceType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 215, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *marketSegmentIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t marketSegmentIDId() SBE_NOEXCEPT
    {
        return 1300;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t marketSegmentIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool marketSegmentIDInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t marketSegmentIDEncodingOffset() SBE_NOEXCEPT
    {
        return 216;
    }

    static SBE_CONSTEXPR std::uint8_t marketSegmentIDNullValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(0);
    }

    static SBE_CONSTEXPR std::uint8_t marketSegmentIDMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(0);
    }

    static SBE_CONSTEXPR std::uint8_t marketSegmentIDMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(254);
    }

    static SBE_CONSTEXPR std::size_t marketSegmentIDEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t marketSegmentID() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 216, sizeof(std::uint8_t));
        return (val);
    }

    SecurityDefinition_12 &marketSegmentID(const std::uint8_t value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 216, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *governanceIndicatorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t governanceIndicatorId() SBE_NOEXCEPT
    {
        return 37011;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t governanceIndicatorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool governanceIndicatorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t governanceIndicatorEncodingOffset() SBE_NOEXCEPT
    {
        return 217;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t governanceIndicatorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t governanceIndicatorRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 217, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD GovernanceIndicator::Value governanceIndicator() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 217, sizeof(std::uint8_t));
        return GovernanceIndicator::get((val));
    }

    SecurityDefinition_12 &governanceIndicator(const GovernanceIndicator::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 217, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *securityMatchTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityMatchTypeId() SBE_NOEXCEPT
    {
        return 37015;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityMatchTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityMatchTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityMatchTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 218;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityMatchTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t securityMatchTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 218, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD SecurityMatchType::Value securityMatchType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 218, sizeof(std::uint8_t));
        return SecurityMatchType::get((val));
    }

    SecurityDefinition_12 &securityMatchType(const SecurityMatchType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 218, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *lastFragmentMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t lastFragmentId() SBE_NOEXCEPT
    {
        return 893;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lastFragmentSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool lastFragmentInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t lastFragmentEncodingOffset() SBE_NOEXCEPT
    {
        return 219;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t lastFragmentEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t lastFragmentRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 219, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD Boolean::Value lastFragment() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 219, sizeof(std::uint8_t));
        return Boolean::get((val));
    }

    SecurityDefinition_12 &lastFragment(const Boolean::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 219, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *multiLegModelMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t multiLegModelId() SBE_NOEXCEPT
    {
        return 1377;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t multiLegModelSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool multiLegModelInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t multiLegModelEncodingOffset() SBE_NOEXCEPT
    {
        return 220;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t multiLegModelEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t multiLegModelRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 220, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD MultiLegModel::Value multiLegModel() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 220, sizeof(std::uint8_t));
        return MultiLegModel::get((val));
    }

    SecurityDefinition_12 &multiLegModel(const MultiLegModel::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 220, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *multiLegPriceMethodMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t multiLegPriceMethodId() SBE_NOEXCEPT
    {
        return 1378;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t multiLegPriceMethodSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool multiLegPriceMethodInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t multiLegPriceMethodEncodingOffset() SBE_NOEXCEPT
    {
        return 221;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t multiLegPriceMethodEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t multiLegPriceMethodRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 221, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD MultiLegPriceMethod::Value multiLegPriceMethod() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 221, sizeof(std::uint8_t));
        return MultiLegPriceMethod::get((val));
    }

    SecurityDefinition_12 &multiLegPriceMethod(const MultiLegPriceMethod::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 221, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *minCrossQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minCrossQtyId() SBE_NOEXCEPT
    {
        return 35561;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minCrossQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minCrossQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minCrossQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 222;
    }

    static SBE_CONSTEXPR std::int64_t minCrossQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t minCrossQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t minCrossQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t minCrossQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t minCrossQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 222, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    SecurityDefinition_12 &minCrossQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 222, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *impliedMarketIndicatorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t impliedMarketIndicatorId() SBE_NOEXCEPT
    {
        return 1144;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t impliedMarketIndicatorSinceVersion() SBE_NOEXCEPT
    {
        return 10;
    }

    SBE_NODISCARD bool impliedMarketIndicatorInActingVersion() SBE_NOEXCEPT
    {
        return m_actingVersion >= impliedMarketIndicatorSinceVersion();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t impliedMarketIndicatorEncodingOffset() SBE_NOEXCEPT
    {
        return 230;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t impliedMarketIndicatorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t impliedMarketIndicatorRaw() const SBE_NOEXCEPT
    {
        if (m_actingVersion < 10)
        {
            return static_cast<std::uint8_t>(255);
        }

        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 230, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD ImpliedMarketIndicator::Value impliedMarketIndicator() const
    {
        if (m_actingVersion < 10)
        {
            return ImpliedMarketIndicator::NULL_VALUE;
        }

        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 230, sizeof(std::uint8_t));
        return ImpliedMarketIndicator::get((val));
    }

    SecurityDefinition_12 &impliedMarketIndicator(const ImpliedMarketIndicator::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 230, &val, sizeof(std::uint8_t));
        return *this;
    }

    class NoUnderlyings
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        NoUnderlyings() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(28));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 28;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 28;
        }

        SBE_NODISCARD std::uint64_t sbeActingBlockLength() SBE_NOEXCEPT
        {
            return m_blockLength;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoUnderlyings &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex()
        {
            m_count = m_index;
            GroupSizeEncoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

        template<class Func> inline void forEach(Func &&func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }


        SBE_NODISCARD static const char *underlyingSecurityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSecurityIDId() SBE_NOEXCEPT
        {
            return 309;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSecurityIDInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSecurityIDEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT64;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDMinValue() SBE_NOEXCEPT
        {
            return UINT64_C(0x0);
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDMaxValue() SBE_NOEXCEPT
        {
            return UINT64_C(0xfffffffffffffffe);
        }

        static SBE_CONSTEXPR std::size_t underlyingSecurityIDEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::uint64_t underlyingSecurityID() const SBE_NOEXCEPT
        {
            std::uint64_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        NoUnderlyings &underlyingSecurityID(const std::uint64_t value) SBE_NOEXCEPT
        {
            std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint64_t));
            return *this;
        }

        SBE_NODISCARD static const char *underlyingSecurityIDSourceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "constant";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSecurityIDSourceId() SBE_NOEXCEPT
        {
            return 305;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDSourceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSecurityIDSourceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSecurityIDSourceEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSecurityIDSourceEncodingLength() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR SecurityIDSource::Value underlyingSecurityIDSourceConstValue() SBE_NOEXCEPT
        {
            return SecurityIDSource::Value::EXCHANGE_SYMBOL;
        }

        SBE_NODISCARD SecurityIDSource::Value underlyingSecurityIDSource() const
        {
            return SecurityIDSource::Value::EXCHANGE_SYMBOL;
        }

        SBE_NODISCARD char underlyingSecurityIDSourceRaw() const SBE_NOEXCEPT
        {
            return static_cast<char>(SecurityIDSource::Value::EXCHANGE_SYMBOL);
        }

        SBE_NODISCARD static const char *underlyingSecurityExchangeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "constant";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSecurityExchangeId() SBE_NOEXCEPT
        {
            return 308;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSecurityExchangeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSecurityExchangeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSecurityExchangeEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        static SBE_CONSTEXPR char underlyingSecurityExchangeNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char underlyingSecurityExchangeMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char underlyingSecurityExchangeMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t underlyingSecurityExchangeEncodingLength() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSecurityExchangeLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD const char *underlyingSecurityExchange() const
        {
            static const std::uint8_t underlyingSecurityExchangeValues[] = { 66, 86, 77, 70, 0 };

            return (const char *)underlyingSecurityExchangeValues;
        }

        SBE_NODISCARD char underlyingSecurityExchange(const std::uint64_t index) const
        {
            static const std::uint8_t underlyingSecurityExchangeValues[] = { 66, 86, 77, 70, 0 };

            return (char)underlyingSecurityExchangeValues[index];
        }

        std::uint64_t getUnderlyingSecurityExchange(char *dst, const std::uint64_t length) const
        {
            static std::uint8_t underlyingSecurityExchangeValues[] = { 66, 86, 77, 70 };
            std::uint64_t bytesToCopy = length < sizeof(underlyingSecurityExchangeValues) ? length : sizeof(underlyingSecurityExchangeValues);

            std::memcpy(dst, underlyingSecurityExchangeValues, static_cast<std::size_t>(bytesToCopy));
            return bytesToCopy;
        }

        std::string getUnderlyingSecurityExchangeAsString() const
        {
            static const std::uint8_t UnderlyingSecurityExchangeValues[] = { 66, 86, 77, 70 };

            return std::string((const char *)UnderlyingSecurityExchangeValues, 4);
        }

        std::string getUnderlyingSecurityExchangeAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getUnderlyingSecurityExchangeAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        SBE_NODISCARD static const char *underlyingSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSymbolId() SBE_NOEXCEPT
        {
            return 311;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSymbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSymbolInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSymbolEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        static SBE_CONSTEXPR char underlyingSymbolNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char underlyingSymbolMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char underlyingSymbolMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t underlyingSymbolEncodingLength() SBE_NOEXCEPT
        {
            return 20;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSymbolLength() SBE_NOEXCEPT
        {
            return 20;
        }

        SBE_NODISCARD const char *underlyingSymbol() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 8;
        }

        SBE_NODISCARD char *underlyingSymbol() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 8;
        }

        SBE_NODISCARD char underlyingSymbol(const std::uint64_t index) const
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for underlyingSymbol [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 8 + (index * 1), sizeof(char));
            return (val);
        }

        NoUnderlyings &underlyingSymbol(const std::uint64_t index, const char value)
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for underlyingSymbol [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 8 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getUnderlyingSymbol(char *const dst, const std::uint64_t length) const
        {
            if (length > 20)
            {
                throw std::runtime_error("length too large for getUnderlyingSymbol [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 8, sizeof(char) * static_cast<std::size_t>(length));
            return length;
        }

        #ifdef SBE_USE_SPAN
        SBE_NODISCARD std::span<const char> getUnderlyingSymbolAsSpan() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 8;
            return std::span<const char>(reinterpret_cast<const char*>(buffer), 20);
        }
        #endif

        #ifdef SBE_USE_SPAN
        template <std::size_t N>
        NoUnderlyings &putUnderlyingSymbol(std::span<const char, N> src) SBE_NOEXCEPT
        {
            static_assert(N <= 20, "array too large for putUnderlyingSymbol");

            std::memcpy(m_buffer + m_offset + 8, src.data(), sizeof(char) * N);
            for (std::size_t start = N; start < 20; ++start)
            {
                m_buffer[m_offset + 8 + start] = 0;
            }

            return *this;
        }
        #endif

        #ifdef SBE_USE_SPAN
        template <typename T>
        NoUnderlyings &putUnderlyingSymbol(T&& src)  SBE_NOEXCEPT requires
            (std::is_pointer_v<std::remove_reference_t<T>> &&
             !std::is_array_v<std::remove_reference_t<T>>)
        #else
        NoUnderlyings &putUnderlyingSymbol(const char *const src) SBE_NOEXCEPT
        #endif
        {
            std::memcpy(m_buffer + m_offset + 8, src, sizeof(char) * 20);
            return *this;
        }

        #ifdef SBE_USE_SPAN
        template <std::size_t N>
        NoUnderlyings &putUnderlyingSymbol(const char (&src)[N]) SBE_NOEXCEPT
        {
            return putUnderlyingSymbol(std::span<const char, N>(src));
        }
        #endif

        SBE_NODISCARD std::string getUnderlyingSymbolAsString() const
        {
            const char *buffer = m_buffer + m_offset + 8;
            std::size_t length = 0;

            for (; length < 20 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getUnderlyingSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getUnderlyingSymbolAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #ifdef SBE_USE_STRING_VIEW
        SBE_NODISCARD std::string_view getUnderlyingSymbolAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 8;
            std::size_t length = 0;

            for (; length < 20 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #ifdef SBE_USE_STRING_VIEW
        NoUnderlyings &putUnderlyingSymbol(const std::string_view str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 20)
            {
                throw std::runtime_error("string too large for putUnderlyingSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 8, str.data(), srcLength);
            for (std::size_t start = srcLength; start < 20; ++start)
            {
                m_buffer[m_offset + 8 + start] = 0;
            }

            return *this;
        }
        #else
        NoUnderlyings &putUnderlyingSymbol(const std::string &str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 20)
            {
                throw std::runtime_error("string too large for putUnderlyingSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 8, str.c_str(), srcLength);
            for (std::size_t start = srcLength; start < 20; ++start)
            {
                m_buffer[m_offset + 8 + start] = 0;
            }

            return *this;
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, NoUnderlyings &writer)
        {
            builder << '{';
            builder << R"("underlyingSecurityID": )";
            builder << +writer.underlyingSecurityID();

            builder << ", ";
            builder << R"("underlyingSecurityIDSource": )";
            builder << '"' << writer.underlyingSecurityIDSource() << '"';

            builder << ", ";
            builder << R"("underlyingSymbol": )";
            builder << '"' <<
                writer.getUnderlyingSymbolAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoUnderlyings m_noUnderlyings;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t noUnderlyingsId() SBE_NOEXCEPT
    {
        return 711;
    }

    SBE_NODISCARD inline NoUnderlyings &noUnderlyings()
    {
        m_noUnderlyings.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noUnderlyings;
    }

    NoUnderlyings &noUnderlyingsCount(const std::uint8_t count)
    {
        m_noUnderlyings.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noUnderlyings;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noUnderlyingsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noUnderlyingsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class NoLegs
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        NoLegs() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(38));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 38;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 38;
        }

        SBE_NODISCARD std::uint64_t sbeActingBlockLength() SBE_NOEXCEPT
        {
            return m_blockLength;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoLegs &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex()
        {
            m_count = m_index;
            GroupSizeEncoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

        template<class Func> inline void forEach(Func &&func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }


        SBE_NODISCARD static const char *legSecurityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSecurityIDId() SBE_NOEXCEPT
        {
            return 602;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSecurityIDSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSecurityIDInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityIDEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint64_t legSecurityIDNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT64;
        }

        static SBE_CONSTEXPR std::uint64_t legSecurityIDMinValue() SBE_NOEXCEPT
        {
            return UINT64_C(0x0);
        }

        static SBE_CONSTEXPR std::uint64_t legSecurityIDMaxValue() SBE_NOEXCEPT
        {
            return UINT64_C(0xfffffffffffffffe);
        }

        static SBE_CONSTEXPR std::size_t legSecurityIDEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::uint64_t legSecurityID() const SBE_NOEXCEPT
        {
            std::uint64_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        NoLegs &legSecurityID(const std::uint64_t value) SBE_NOEXCEPT
        {
            std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint64_t));
            return *this;
        }

        SBE_NODISCARD static const char *legSecurityIDSourceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "constant";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSecurityIDSourceId() SBE_NOEXCEPT
        {
            return 603;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSecurityIDSourceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSecurityIDSourceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityIDSourceEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityIDSourceEncodingLength() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR SecurityIDSource::Value legSecurityIDSourceConstValue() SBE_NOEXCEPT
        {
            return SecurityIDSource::Value::EXCHANGE_SYMBOL;
        }

        SBE_NODISCARD SecurityIDSource::Value legSecurityIDSource() const
        {
            return SecurityIDSource::Value::EXCHANGE_SYMBOL;
        }

        SBE_NODISCARD char legSecurityIDSourceRaw() const SBE_NOEXCEPT
        {
            return static_cast<char>(SecurityIDSource::Value::EXCHANGE_SYMBOL);
        }

        SBE_NODISCARD static const char *legSecurityExchangeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "constant";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSecurityExchangeId() SBE_NOEXCEPT
        {
            return 616;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSecurityExchangeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSecurityExchangeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityExchangeEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        static SBE_CONSTEXPR char legSecurityExchangeNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char legSecurityExchangeMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char legSecurityExchangeMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t legSecurityExchangeEncodingLength() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint64_t legSecurityExchangeLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD const char *legSecurityExchange() const
        {
            static const std::uint8_t legSecurityExchangeValues[] = { 66, 86, 77, 70, 0 };

            return (const char *)legSecurityExchangeValues;
        }

        SBE_NODISCARD char legSecurityExchange(const std::uint64_t index) const
        {
            static const std::uint8_t legSecurityExchangeValues[] = { 66, 86, 77, 70, 0 };

            return (char)legSecurityExchangeValues[index];
        }

        std::uint64_t getLegSecurityExchange(char *dst, const std::uint64_t length) const
        {
            static std::uint8_t legSecurityExchangeValues[] = { 66, 86, 77, 70 };
            std::uint64_t bytesToCopy = length < sizeof(legSecurityExchangeValues) ? length : sizeof(legSecurityExchangeValues);

            std::memcpy(dst, legSecurityExchangeValues, static_cast<std::size_t>(bytesToCopy));
            return bytesToCopy;
        }

        std::string getLegSecurityExchangeAsString() const
        {
            static const std::uint8_t LegSecurityExchangeValues[] = { 66, 86, 77, 70 };

            return std::string((const char *)LegSecurityExchangeValues, 4);
        }

        std::string getLegSecurityExchangeAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getLegSecurityExchangeAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        SBE_NODISCARD static const char *legRatioQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legRatioQtyId() SBE_NOEXCEPT
        {
            return 623;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legRatioQtySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legRatioQtyInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legRatioQtyEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

private:
        RatioQty m_legRatioQty;

public:
        SBE_NODISCARD RatioQty &legRatioQty()
        {
            m_legRatioQty.wrap(m_buffer, m_offset + 8, m_actingVersion, m_bufferLength);
            return m_legRatioQty;
        }

        SBE_NODISCARD static const char *legSecurityTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSecurityTypeId() SBE_NOEXCEPT
        {
            return 609;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSecurityTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSecurityTypeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 16;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityTypeEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t legSecurityTypeRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD SecurityType::Value legSecurityType() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::uint8_t));
            return SecurityType::get((val));
        }

        NoLegs &legSecurityType(const SecurityType::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 16, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *legSideMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSideId() SBE_NOEXCEPT
        {
            return 624;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSideSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSideInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSideEncodingOffset() SBE_NOEXCEPT
        {
            return 17;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSideEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t legSideRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 17, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD Side::Value legSide() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 17, sizeof(std::uint8_t));
            return Side::get((val));
        }

        NoLegs &legSide(const Side::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 17, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *legSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSymbolId() SBE_NOEXCEPT
        {
            return 600;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSymbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSymbolInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSymbolEncodingOffset() SBE_NOEXCEPT
        {
            return 18;
        }

        static SBE_CONSTEXPR char legSymbolNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char legSymbolMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char legSymbolMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t legSymbolEncodingLength() SBE_NOEXCEPT
        {
            return 20;
        }

        static SBE_CONSTEXPR std::uint64_t legSymbolLength() SBE_NOEXCEPT
        {
            return 20;
        }

        SBE_NODISCARD const char *legSymbol() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 18;
        }

        SBE_NODISCARD char *legSymbol() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 18;
        }

        SBE_NODISCARD char legSymbol(const std::uint64_t index) const
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for legSymbol [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 18 + (index * 1), sizeof(char));
            return (val);
        }

        NoLegs &legSymbol(const std::uint64_t index, const char value)
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for legSymbol [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 18 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getLegSymbol(char *const dst, const std::uint64_t length) const
        {
            if (length > 20)
            {
                throw std::runtime_error("length too large for getLegSymbol [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 18, sizeof(char) * static_cast<std::size_t>(length));
            return length;
        }

        #ifdef SBE_USE_SPAN
        SBE_NODISCARD std::span<const char> getLegSymbolAsSpan() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 18;
            return std::span<const char>(reinterpret_cast<const char*>(buffer), 20);
        }
        #endif

        #ifdef SBE_USE_SPAN
        template <std::size_t N>
        NoLegs &putLegSymbol(std::span<const char, N> src) SBE_NOEXCEPT
        {
            static_assert(N <= 20, "array too large for putLegSymbol");

            std::memcpy(m_buffer + m_offset + 18, src.data(), sizeof(char) * N);
            for (std::size_t start = N; start < 20; ++start)
            {
                m_buffer[m_offset + 18 + start] = 0;
            }

            return *this;
        }
        #endif

        #ifdef SBE_USE_SPAN
        template <typename T>
        NoLegs &putLegSymbol(T&& src)  SBE_NOEXCEPT requires
            (std::is_pointer_v<std::remove_reference_t<T>> &&
             !std::is_array_v<std::remove_reference_t<T>>)
        #else
        NoLegs &putLegSymbol(const char *const src) SBE_NOEXCEPT
        #endif
        {
            std::memcpy(m_buffer + m_offset + 18, src, sizeof(char) * 20);
            return *this;
        }

        #ifdef SBE_USE_SPAN
        template <std::size_t N>
        NoLegs &putLegSymbol(const char (&src)[N]) SBE_NOEXCEPT
        {
            return putLegSymbol(std::span<const char, N>(src));
        }
        #endif

        SBE_NODISCARD std::string getLegSymbolAsString() const
        {
            const char *buffer = m_buffer + m_offset + 18;
            std::size_t length = 0;

            for (; length < 20 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getLegSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getLegSymbolAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #ifdef SBE_USE_STRING_VIEW
        SBE_NODISCARD std::string_view getLegSymbolAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 18;
            std::size_t length = 0;

            for (; length < 20 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #ifdef SBE_USE_STRING_VIEW
        NoLegs &putLegSymbol(const std::string_view str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 20)
            {
                throw std::runtime_error("string too large for putLegSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 18, str.data(), srcLength);
            for (std::size_t start = srcLength; start < 20; ++start)
            {
                m_buffer[m_offset + 18 + start] = 0;
            }

            return *this;
        }
        #else
        NoLegs &putLegSymbol(const std::string &str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 20)
            {
                throw std::runtime_error("string too large for putLegSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 18, str.c_str(), srcLength);
            for (std::size_t start = srcLength; start < 20; ++start)
            {
                m_buffer[m_offset + 18 + start] = 0;
            }

            return *this;
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, NoLegs &writer)
        {
            builder << '{';
            builder << R"("legSecurityID": )";
            builder << +writer.legSecurityID();

            builder << ", ";
            builder << R"("legSecurityIDSource": )";
            builder << '"' << writer.legSecurityIDSource() << '"';

            builder << ", ";
            builder << R"("legRatioQty": )";
            builder << writer.legRatioQty();

            builder << ", ";
            builder << R"("legSecurityType": )";
            builder << '"' << writer.legSecurityType() << '"';

            builder << ", ";
            builder << R"("legSide": )";
            builder << '"' << writer.legSide() << '"';

            builder << ", ";
            builder << R"("legSymbol": )";
            builder << '"' <<
                writer.getLegSymbolAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoLegs m_noLegs;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t noLegsId() SBE_NOEXCEPT
    {
        return 555;
    }

    SBE_NODISCARD inline NoLegs &noLegs()
    {
        m_noLegs.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noLegs;
    }

    NoLegs &noLegsCount(const std::uint8_t count)
    {
        m_noLegs.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noLegs;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noLegsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noLegsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class NoInstrAttribs
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        NoInstrAttribs() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(2));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 2;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD std::uint64_t sbeActingBlockLength() SBE_NOEXCEPT
        {
            return m_blockLength;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoInstrAttribs &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex()
        {
            m_count = m_index;
            GroupSizeEncoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

        template<class Func> inline void forEach(Func &&func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }


        SBE_NODISCARD static const char *instrAttribTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t instrAttribTypeId() SBE_NOEXCEPT
        {
            return 871;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t instrAttribTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool instrAttribTypeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribTypeEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t instrAttribTypeRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD InstrAttribType::Value instrAttribType() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return InstrAttribType::get((val));
        }

        NoInstrAttribs &instrAttribType(const InstrAttribType::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *instrAttribValueMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t instrAttribValueId() SBE_NOEXCEPT
        {
            return 872;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t instrAttribValueSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool instrAttribValueInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribValueEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribValueEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t instrAttribValueRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD InstrAttribValue::Value instrAttribValue() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return InstrAttribValue::get((val));
        }

        NoInstrAttribs &instrAttribValue(const InstrAttribValue::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::uint8_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, NoInstrAttribs &writer)
        {
            builder << '{';
            builder << R"("instrAttribType": )";
            builder << '"' << writer.instrAttribType() << '"';

            builder << ", ";
            builder << R"("instrAttribValue": )";
            builder << '"' << writer.instrAttribValue() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoInstrAttribs m_noInstrAttribs;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t noInstrAttribsId() SBE_NOEXCEPT
    {
        return 870;
    }

    SBE_NODISCARD inline NoInstrAttribs &noInstrAttribs()
    {
        m_noInstrAttribs.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noInstrAttribs;
    }

    NoInstrAttribs &noInstrAttribsCount(const std::uint8_t count)
    {
        m_noInstrAttribs.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noInstrAttribs;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noInstrAttribsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noInstrAttribsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static const char *securityDescMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *securityDescCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t securityDescSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool securityDescInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    static SBE_CONSTEXPR std::uint16_t securityDescId() SBE_NOEXCEPT
    {
        return 107;
    }

    static SBE_CONSTEXPR std::uint64_t securityDescHeaderLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t securityDescLength() const
    {
        std::uint8_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
        return (length);
    }

    std::uint64_t skipSecurityDesc()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *securityDesc()
    {
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
        const char *fieldPtr = m_buffer + sbePosition() + 1;
        sbePosition(sbePosition() + 1 + (lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getSecurityDesc(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, static_cast<std::size_t>(bytesToCopy));
        return bytesToCopy;
    }

    SecurityDefinition_12 &putSecurityDesc(const char *src, const std::uint8_t length)
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue = (length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint8_t));
        if (length != std::uint8_t(0))
        {
            std::uint64_t pos = sbePosition();
            sbePosition(pos + length);
            std::memcpy(m_buffer + pos, src, length);
        }
        return *this;
    }

    std::string getSecurityDescAsString()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    std::string getSecurityDescAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityDescAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    std::string_view getSecurityDescAsStringView()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    SecurityDefinition_12 &putSecurityDesc(const std::string &str)
    {
        if (str.length() > 250)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSecurityDesc(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    SecurityDefinition_12 &putSecurityDesc(const std::string_view str)
    {
        if (str.length() > 250)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSecurityDesc(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const SecurityDefinition_12 &_writer)
{
    SecurityDefinition_12 writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "SecurityDefinition_12", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("messageType": )";
    builder << '"' << writer.messageType() << '"';

    builder << ", ";
    builder << R"("applVerID": )";
    builder << '"' << writer.applVerID() << '"';

    builder << ", ";
    builder << R"("securityID": )";
    builder << +writer.securityID();

    builder << ", ";
    builder << R"("securityExchange": )";
    builder << '"' <<
        writer.getSecurityExchangeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("securityIDSource": )";
    builder << '"' << writer.securityIDSource() << '"';

    builder << ", ";
    builder << R"("securityGroup": )";
    builder << '"' <<
        writer.getSecurityGroupAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("securityUpdateAction": )";
    builder << '"' << writer.securityUpdateAction() << '"';

    builder << ", ";
    builder << R"("securityType": )";
    builder << '"' << writer.securityType() << '"';

    builder << ", ";
    builder << R"("securitySubType": )";
    builder << +writer.securitySubType();

    builder << ", ";
    builder << R"("totNoRelatedSym": )";
    builder << +writer.totNoRelatedSym();

    builder << ", ";
    builder << R"("minPriceIncrement": )";
    builder << writer.minPriceIncrement();

    builder << ", ";
    builder << R"("strikePrice": )";
    builder << writer.strikePrice();

    builder << ", ";
    builder << R"("contractMultiplier": )";
    builder << writer.contractMultiplier();

    builder << ", ";
    builder << R"("priceDivisor": )";
    builder << writer.priceDivisor();

    builder << ", ";
    builder << R"("securityValidityTimestamp": )";
    builder << writer.securityValidityTimestamp();

    builder << ", ";
    builder << R"("noSharesIssued": )";
    builder << +writer.noSharesIssued();

    builder << ", ";
    builder << R"("clearingHouseID": )";
    builder << +writer.clearingHouseID();

    builder << ", ";
    builder << R"("minOrderQty": )";
    builder << +writer.minOrderQty();

    builder << ", ";
    builder << R"("maxOrderQty": )";
    builder << +writer.maxOrderQty();

    builder << ", ";
    builder << R"("minLotSize": )";
    builder << +writer.minLotSize();

    builder << ", ";
    builder << R"("minTradeVol": )";
    builder << +writer.minTradeVol();

    builder << ", ";
    builder << R"("corporateActionEventId": )";
    builder << +writer.corporateActionEventId();

    builder << ", ";
    builder << R"("issueDate": )";
    builder << +writer.issueDate();

    builder << ", ";
    builder << R"("maturityDate": )";
    builder << +writer.maturityDate();

    builder << ", ";
    builder << R"("countryOfIssue": )";
    builder << '"' <<
        writer.getCountryOfIssueAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("startDate": )";
    builder << +writer.startDate();

    builder << ", ";
    builder << R"("endDate": )";
    builder << +writer.endDate();

    builder << ", ";
    builder << R"("settlType": )";
    builder << +writer.settlType();

    builder << ", ";
    builder << R"("settlDate": )";
    builder << +writer.settlDate();

    builder << ", ";
    builder << R"("datedDate": )";
    builder << +writer.datedDate();

    builder << ", ";
    builder << R"("isinNumber": )";
    builder << '"' <<
        writer.getIsinNumberAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("asset": )";
    builder << '"' <<
        writer.getAssetAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("cfiCode": )";
    builder << '"' <<
        writer.getCfiCodeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("maturityMonthYear": )";
    builder << writer.maturityMonthYear();

    builder << ", ";
    builder << R"("contractSettlMonth": )";
    builder << writer.contractSettlMonth();

    builder << ", ";
    builder << R"("currency": )";
    builder << '"' <<
        writer.getCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("strikeCurrency": )";
    builder << '"' <<
        writer.getStrikeCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("settlCurrency": )";
    builder << '"' <<
        writer.getSettlCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("securityStrategyType": )";
    builder << '"' <<
        writer.getSecurityStrategyTypeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("lotType": )";
    builder << '"' << writer.lotType() << '"';

    builder << ", ";
    builder << R"("tickSizeDenominator": )";
    builder << +writer.tickSizeDenominator();

    builder << ", ";
    builder << R"("product": )";
    builder << '"' << writer.product() << '"';

    builder << ", ";
    builder << R"("exerciseStyle": )";
    builder << '"' << writer.exerciseStyle() << '"';

    builder << ", ";
    builder << R"("putOrCall": )";
    builder << '"' << writer.putOrCall() << '"';

    builder << ", ";
    builder << R"("priceType": )";
    builder << '"' << writer.priceType() << '"';

    builder << ", ";
    builder << R"("marketSegmentID": )";
    builder << +writer.marketSegmentID();

    builder << ", ";
    builder << R"("governanceIndicator": )";
    builder << '"' << writer.governanceIndicator() << '"';

    builder << ", ";
    builder << R"("securityMatchType": )";
    builder << '"' << writer.securityMatchType() << '"';

    builder << ", ";
    builder << R"("lastFragment": )";
    builder << '"' << writer.lastFragment() << '"';

    builder << ", ";
    builder << R"("multiLegModel": )";
    builder << '"' << writer.multiLegModel() << '"';

    builder << ", ";
    builder << R"("multiLegPriceMethod": )";
    builder << '"' << writer.multiLegPriceMethod() << '"';

    builder << ", ";
    builder << R"("minCrossQty": )";
    builder << +writer.minCrossQty();

    builder << ", ";
    builder << R"("impliedMarketIndicator": )";
    builder << '"' << writer.impliedMarketIndicator() << '"';

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("noUnderlyings": [)";
        writer.noUnderlyings().forEach(
            [&](NoUnderlyings &noUnderlyings)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << noUnderlyings;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("noLegs": [)";
        writer.noLegs().forEach(
            [&](NoLegs &noLegs)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << noLegs;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("noInstrAttribs": [)";
        writer.noInstrAttribs().forEach(
            [&](NoInstrAttribs &noInstrAttribs)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << noInstrAttribs;
            });
        builder << ']';
    }

    builder << ", ";
    builder << R"("securityDesc": )";
    builder << '"' <<
        writer.getSecurityDescAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    auto &noUnderlyingsGroup { noUnderlyings() };
    while (noUnderlyingsGroup.hasNext())
    {
        noUnderlyingsGroup.next().skip();
    }
    auto &noLegsGroup { noLegs() };
    while (noLegsGroup.hasNext())
    {
        noLegsGroup.next().skip();
    }
    auto &noInstrAttribsGroup { noInstrAttribs() };
    while (noInstrAttribsGroup.hasNext())
    {
        noInstrAttribsGroup.next().skip();
    }
    skipSecurityDesc();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    std::size_t noUnderlyingsLength = 0,
    std::size_t noLegsLength = 0,
    std::size_t noInstrAttribsLength = 0,
    std::size_t securityDescLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += NoUnderlyings::sbeHeaderSize();
    if (noUnderlyingsLength > 254LL)
    {
        throw std::runtime_error("noUnderlyingsLength outside of allowed range [E110]");
    }
    length += noUnderlyingsLength *NoUnderlyings::sbeBlockLength();

    length += NoLegs::sbeHeaderSize();
    if (noLegsLength > 254LL)
    {
        throw std::runtime_error("noLegsLength outside of allowed range [E110]");
    }
    length += noLegsLength *NoLegs::sbeBlockLength();

    length += NoInstrAttribs::sbeHeaderSize();
    if (noInstrAttribsLength > 254LL)
    {
        throw std::runtime_error("noInstrAttribsLength outside of allowed range [E110]");
    }
    length += noInstrAttribsLength *NoInstrAttribs::sbeBlockLength();

    length += securityDescHeaderLength();
    if (securityDescLength > 250LL)
    {
        throw std::runtime_error("securityDescLength too long for length type [E109]");
    }
    length += securityDescLength;

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
