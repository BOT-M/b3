#ifndef SOCKETWRAPPER_HPP
#define SOCKETWRAPPER_HPP
#include "b3struct.hpp"
#include "std.hpp"

namespace B3
{
    struct MulticastConfig
    {
        std::string group_ip;
        uint16_t port;
        std::string local_ip;
    };

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args &&...args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    class Message;

    // 消息队列（线程安全）
    class MessageQueue
    {
    public:
        void Push(std::unique_ptr<Message> msg);
        std::unique_ptr<Message> Pop();
        bool Empty() const;

    private:
        // mutable std::mutex mutex_;
        // std::condition_variable cv_;
        // std::queue<std::unique_ptr<Message>> queue_;
    };

    class MessageProcessor
    {
    public:
        void Process(const Message &msg);
        void HandleIncrementalRefresh(const Message &msg);
        void HandleSecurityList(const Message &msg);
        void HandleSecurityStatus(const Message &msg);
        void HandleNews(const Message &msg);
    };

    class SocketWrapper
    {
        using DataCallback = std::function<void(char *, size_t)>;

    public:
        explicit SocketWrapper() = default;
        // 禁止拷贝和移动（确保资源安全）
        SocketWrapper(const SocketWrapper &) = delete;
        SocketWrapper &operator=(const SocketWrapper &) = delete;
        ~SocketWrapper();
        bool JoinMulticastGroup(const MulticastConfig &config);
        void SetDataCallback(DataCallback callback);
        void StartReceiving(std::atomic<bool> &running_flag);
        void Close();
        bool IsConnected() const;
        int GetFD() const;

    private:
        void SetSocketOption(int optname, int value);
        void BindSocket(uint16_t port);
        void JoinGroup(const std::string &group_ip, const std::string &local_ip);
        void ThrowSystemError(const std::string &prefix);

    private:
        int fd_ = -1;
        std::atomic<bool> is_connected_{false};
        MulticastConfig config_;
        DataCallback callback_;
    };

} // namespace B3

#endif // SOCKETWRAPPER_HPP