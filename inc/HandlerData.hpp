#ifndef HANDLERDATA_HPP
#define HANDLERDATA_HPP

#include "std.hpp"

namespace b3
{
    class HandlerData
    {
    private:
        
    public:
        HandlerData();
        ~HandlerData();
        void analyzeData(const char* data, const std::size_t size);
    };

    

}

#endif // HANDLERDATA_HPP
