/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _B3_MARKET_DATA_MATCHEVENTINDICATOR_CXX_H_
#define _B3_MARKET_DATA_MATCHEVENTINDICATOR_CXX_H_

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


namespace b3_market_data {

class MatchEventIndicator
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_actingVersion = 0;

public:
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

    MatchEventIndicator() = default;

    MatchEventIndicator(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 1) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    MatchEventIndicator(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        MatchEventIndicator(buffer, 0, bufferLength, actingVersion)
    {
    }

    MatchEventIndicator(
        char *buffer,
        const std::uint64_t bufferLength) :
        MatchEventIndicator(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    MatchEventIndicator &wrap(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingVersion = actingVersion;

        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 1) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }

        return *this;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t encodedLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
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

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(2);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(10);
    }

    MatchEventIndicator &clear()
    {
        std::uint8_t zero = 0;
        std::memcpy(m_buffer + m_offset, &zero, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD bool isEmpty() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return 0 == val;
    }

    SBE_NODISCARD std::uint8_t rawValue() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return val;
    }

    MatchEventIndicator &rawValue(std::uint8_t value)
    {
        std::memcpy(m_buffer + m_offset, &value, sizeof(std::uint8_t));
        return *this;
    }

    static bool implied(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 4u)) != 0;
    }

    static std::uint8_t implied(const std::uint8_t bits, const bool value)
    {
        return value ? static_cast<std::uint8_t>(bits | (static_cast<std::uint8_t>(1) << 4u)) : static_cast<std::uint8_t>(bits & ~(static_cast<std::uint8_t>(1) << 4u));
    }

    SBE_NODISCARD bool implied() const
    {
        if (m_actingVersion < 10)
        {
            return false;
        }

        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 4u)) != 0;
    }

    MatchEventIndicator &implied(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? static_cast<std::uint8_t>((bits) | (static_cast<std::uint8_t>(1) << 4u)) : static_cast<std::uint8_t>((bits) & ~(static_cast<std::uint8_t>(1) << 4u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    static bool recoveryMsg(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 5u)) != 0;
    }

    static std::uint8_t recoveryMsg(const std::uint8_t bits, const bool value)
    {
        return value ? static_cast<std::uint8_t>(bits | (static_cast<std::uint8_t>(1) << 5u)) : static_cast<std::uint8_t>(bits & ~(static_cast<std::uint8_t>(1) << 5u));
    }

    SBE_NODISCARD bool recoveryMsg() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 5u)) != 0;
    }

    MatchEventIndicator &recoveryMsg(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? static_cast<std::uint8_t>((bits) | (static_cast<std::uint8_t>(1) << 5u)) : static_cast<std::uint8_t>((bits) & ~(static_cast<std::uint8_t>(1) << 5u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    static bool endOfEvent(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 7u)) != 0;
    }

    static std::uint8_t endOfEvent(const std::uint8_t bits, const bool value)
    {
        return value ? static_cast<std::uint8_t>(bits | (static_cast<std::uint8_t>(1) << 7u)) : static_cast<std::uint8_t>(bits & ~(static_cast<std::uint8_t>(1) << 7u));
    }

    SBE_NODISCARD bool endOfEvent() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 7u)) != 0;
    }

    MatchEventIndicator &endOfEvent(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? static_cast<std::uint8_t>((bits) | (static_cast<std::uint8_t>(1) << 7u)) : static_cast<std::uint8_t>((bits) & ~(static_cast<std::uint8_t>(1) << 7u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &builder, MatchEventIndicator &writer)
    {
        builder << '[';
        bool atLeastOne = false;
        if (writer.implied())
        {
            builder << R"("implied")";
            atLeastOne = true;
        }
        if (writer.recoveryMsg())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("recoveryMsg")";
            atLeastOne = true;
        }
        if (writer.endOfEvent())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("endOfEvent")";
        }
        builder << ']';
        return builder;
    }
};
}
#endif
