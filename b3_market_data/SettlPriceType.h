/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _B3_MARKET_DATA_SETTLPRICETYPE_CXX_H_
#define _B3_MARKET_DATA_SETTLPRICETYPE_CXX_H_

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <iomanip>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

namespace b3_market_data {

class SettlPriceType
{
public:
    enum Value
    {
        FINAL = static_cast<std::uint8_t>(1),
        THEORETICAL = static_cast<std::uint8_t>(2),
        UPDATED = static_cast<std::uint8_t>(3),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static SettlPriceType::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(1): return FINAL;
            case static_cast<std::uint8_t>(2): return THEORETICAL;
            case static_cast<std::uint8_t>(3): return UPDATED;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SettlPriceType [E103]");
    }

    static const char *c_str(const SettlPriceType::Value value)
    {
        switch (value)
        {
            case FINAL: return "FINAL";
            case THEORETICAL: return "THEORETICAL";
            case UPDATED: return "UPDATED";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum SettlPriceType [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, SettlPriceType::Value m)
    {
        return os << SettlPriceType::c_str(m);
    }
};

}

#endif
