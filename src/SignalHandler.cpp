#include "SignalHandler.hpp"

std::unordered_map<int, SignalHandler::SignalCallback> SignalHandler::signalCallbacks;

SignalHandler& SignalHandler::getInstance() {
    static SignalHandler instance;
    return instance;
}

void SignalHandler::registerHandler(int signal, SignalCallback callback) {
    struct sigaction sa{};
    sa.sa_handler = SignalHandler::handleSignal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(signal, &sa, nullptr) < 0) {
        std::cerr << "❌ sigaction 失败: " << signal << std::endl;
    } else {
        signalCallbacks[signal] = std::move(callback);
    }
}

void SignalHandler::handleSignal(int signal) {
    auto it = signalCallbacks.find(signal);
    if (it != signalCallbacks.end()) {
        it->second(signal);  // 执行回调函数
    } else {
        std::cerr << "⚠️ 未注册的信号: " << signal << std::endl;
    }
}