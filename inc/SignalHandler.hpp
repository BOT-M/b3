#ifndef SIGNAL_HANDLER_HPP
#define SIGNAL_HANDLER_HPP

#include <csignal>
#include <functional>
#include <iostream>
#include <unordered_map>

class SignalHandler
{
   public:
    using SignalCallback = std::function<void(int)>;

    static SignalHandler& getInstance();

    void        registerHandler(int signal, SignalCallback callback);
    static void handleSignal(int signal);

   private:
    SignalHandler() = default;
    static std::unordered_map<int, SignalCallback> signalCallbacks;
};

#endif  // SIGNAL_HANDLER_HPP