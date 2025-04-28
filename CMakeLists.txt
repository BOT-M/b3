cmake_minimum_required(VERSION 3.10)
project(MulticastReceiver)


# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost)
find_package(jsoncpp)
find_package(spdlog)

# 包含头文件目录
include_directories(
    /home/yueran/work/b3/inc
    /home/yueran/work/b3/b3_market_data
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")  # 控制所有可执行文件及 Windows 动态库[1,4](@ref)

# 查找 src 目录下的所有 cpp 文件
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# 检查是否找到源文件
if(NOT SOURCES)
    message(FATAL_ERROR "❌ 未找到 src 目录下的 .cpp 源文件")
endif()


# 生成可执行文件
add_executable(MulticastReceive ${SOURCES} main.cpp)

# 链接 pthread
target_link_libraries(MulticastReceive 
    pthread 
    boost::boost
    JsonCpp::JsonCpp
    spdlog::spdlog
    )

