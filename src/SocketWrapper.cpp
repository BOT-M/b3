#include "SocketWrapper.h"

namespace B3
{
    SocketWrapper::~SocketWrapper()
    {
        Close();
    }

    bool SocketWrapper::JoinMulticastGroup(const MulticastConfig &config)
    {
        if (is_connected_)
            return true;

        fd_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (fd_ < 0)
        {
            ThrowSystemError("Create socket failed");
        }

        try
        {
            // 2. 设置地址重用
            SetSocketOption(SO_REUSEADDR, 1);

            // 3. 绑定本地地址
            BindSocket(config.port);

            // 4. 加入多播组
            JoinGroup(config.group_ip, config.local_ip);

            is_connected_ = true;
            config_ = config;
            return true;
        }
        catch (...)
        {
            Close();
            throw;
        }
    }

    void SocketWrapper::SetDataCallback(DataCallback callback)
    {
        callback_ = std::move(callback);
    }

    void SocketWrapper::StartReceiving(std::atomic<bool> &running_flag)
    {
        if (!is_connected_)
        {
            throw std::runtime_error("Socket not connected");
        }

        char buffer[2048];
        sockaddr_in src_addr{};
        socklen_t addr_len = sizeof(src_addr);

        while (running_flag.load())
        {
            ssize_t len = recvfrom(fd_, buffer, sizeof(buffer), 0,
                                   (sockaddr *)&src_addr, &addr_len);
            if (len > 0 && callback_)
            {
                callback_(buffer, static_cast<size_t>(len));
            }
            else if (len < 0 && errno != EINTR)
            {
                ThrowSystemError("Receive error");
            }
        }
    }
    void SocketWrapper::Close()
    {
        if (fd_ != -1)
        {
            if (is_connected_)
            {
                // 离开多播组（可选）
                try
                {
                    ip_mreq mreq{};
                    inet_pton(AF_INET, config_.group_ip.c_str(), &mreq.imr_multiaddr);
                    inet_pton(AF_INET, config_.local_ip.c_str(), &mreq.imr_interface);
                    setsockopt(fd_, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
                }
                catch (...)
                {
                    // 确保资源释放，忽略退出时的错误
                }
            }
            close(fd_);
            fd_ = -1;
            is_connected_ = false;
        }
    }

    bool SocketWrapper::IsConnected() const { return is_connected_; }
    int SocketWrapper::GetFD() const { return fd_; }
    void SocketWrapper::SetSocketOption(int optname, int value)
    {
        int reuse = value;
        if (setsockopt(fd_, SOL_SOCKET, optname, &reuse, sizeof(reuse)) < 0)
        {
            ThrowSystemError("Set socket option failed");
        }
    }

    void SocketWrapper::BindSocket(uint16_t port)
    {
        sockaddr_in local_addr{};
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(port);
        local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

        if (bind(fd_, (sockaddr *)&local_addr, sizeof(local_addr)) < 0)
        {
            ThrowSystemError("Bind failed");
        }
    }

    void SocketWrapper::JoinGroup(const std::string &group_ip, const std::string &local_ip)
    {
        ip_mreq mreq{};
        inet_pton(AF_INET, group_ip.c_str(), &mreq.imr_multiaddr);
        inet_pton(AF_INET, local_ip.c_str(), &mreq.imr_interface);

        if (setsockopt(fd_, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0)
        {
            ThrowSystemError("Join multicast group failed");
        }
    }

    void SocketWrapper::ThrowSystemError(const std::string &prefix)
    {
        throw std::system_error(errno, std::system_category(),
                                prefix + " (errno: " + std::to_string(errno) + ")");
    }
} // namespace B3
