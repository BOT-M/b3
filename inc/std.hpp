#pragma once

#include <cstring>
#include <stdexcept>
#include <arpa/inet.h>
#include <unistd.h>
#include <csignal>
#include <vector>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <iomanip> // 需要包含这个头文件
#include <poll.h>

#include <atomic>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <string>
#include <iostream>
// 三方包
#include <boost/filesystem.hpp>
#include <json/json.h>