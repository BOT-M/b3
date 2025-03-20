#include "std.hpp"
#include "utils.hpp"
#include "LargeFileReader.hpp"
#include "PacketHeader.h"
#include "FramingHeader.h"
#include "MessageHeader.h"



int main(int argc, char **argv)
{
    std::string filename = argv[1];
    if (filename.empty())
    {
        std::cout << "use readfile filename" << std::endl;
    }
    LargeFileReader reader(filename);
    reader.readFromFile();
    
    return 0;
}