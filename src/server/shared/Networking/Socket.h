/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "MessageBuffer.h"
#include "Log.h"
#include <atomic>
#include <queue>
#include <memory>
#include <functional>
#include <type_traits>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;

#define READ_BLOCK_SIZE 4096
#ifdef BOOST_ASIO_HAS_IOCP
#define TC_SOCKET_USE_IOCP
#endif

enum ProxyHeaderReadingState
{
    PROXY_HEADER_READING_STATE_NOT_STARTED,
    PROXY_HEADER_READING_STATE_STARTED,
    PROXY_HEADER_READING_STATE_FINISHED,
    PROXY_HEADER_READING_STATE_FAILED,
};

enum ProxyHeaderAddressFamilyAndProtocol
{
    PROXY_HEADER_ADDRESS_FAMILY_AND_PROTOCOL_TCP_V4 = 0x11,
    PROXY_HEADER_ADDRESS_FAMILY_AND_PROTOCOL_TCP_V6 = 0x21,
};

template<class T>
class Socket : public std::enable_shared_from_this<T>
{
public:
    explicit Socket(tcp::socket&& socket) : _socket(std::move(socket)), _remoteAddress(_socket.remote_endpoint().address()),
        _remotePort(_socket.remote_endpoint().port()), _readBuffer(), _closed(false), _closing(false), _isWritingAsync(false), _proxyHeaderReadingState(PROXY_HEADER_READING_STATE_NOT_STARTED)
    {
        _readBuffer.Resize(READ_BLOCK_SIZE);
    }

    virtual ~Socket()
    {
        _closed = true;
        boost::system::error_code error;
        _socket.close(error);
    }

    virtual void Start() = 0;

    virtual bool Update()
    {
        if (_closed)
            return false;

#ifndef TC_SOCKET_USE_IOCP
        if (_isWritingAsync || (_writeQueue.empty() && !_closing))
            return true;

        for (; HandleQueue();)
            ;
#endif

        return true;
    }

    boost::asio::ip::address GetRemoteIpAddress() const
    {
        return _remoteAddress;
    }

    uint16 GetRemotePort() const
    {
        return _remotePort;
    }

    void AsyncRead()
    {
        if (!IsOpen())
            return;

        _readBuffer.Normalize();
        _readBuffer.EnsureFreeSpace();
        _socket.async_read_some(boost::asio::buffer(_readBuffer.GetWritePointer(), _readBuffer.GetRemainingSpace()),
            std::bind(&Socket<T>::ReadHandlerInternal, this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void AsyncReadProxyHeader()
    {
        if (!IsOpen())
            return;

        _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_STARTED;

        _readBuffer.Normalize();
        _readBuffer.EnsureFreeSpace();
        _socket.async_read_some(boost::asio::buffer(_readBuffer.GetWritePointer(), _readBuffer.GetRemainingSpace()),
            std::bind(&Socket<T>::ProxyReadHeaderHandler, this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void AsyncReadWithCallback(void (T::*callback)(boost::system::error_code, std::size_t))
    {
        if (!IsOpen())
            return;

        _readBuffer.Normalize();
        _readBuffer.EnsureFreeSpace();
        _socket.async_read_some(boost::asio::buffer(_readBuffer.GetWritePointer(), _readBuffer.GetRemainingSpace()),
            std::bind(callback, this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void QueuePacket(MessageBuffer&& buffer)
    {
        _writeQueue.push(std::move(buffer));

#ifdef TC_SOCKET_USE_IOCP
        AsyncProcessQueue();
#endif
    }

    ProxyHeaderReadingState GetProxyHeaderReadingState() const { return _proxyHeaderReadingState; }
    bool IsOpen() const { return !_closed && !_closing; }

    void CloseSocket()
    {
        if (_closed.exchange(true))
            return;

        boost::system::error_code shutdownError;
        _socket.shutdown(boost::asio::socket_base::shutdown_send, shutdownError);
        if (shutdownError)
            TC_LOG_DEBUG("network", "Socket::CloseSocket: {} errored when shutting down socket: {} ({})", GetRemoteIpAddress().to_string(),
                shutdownError.value(), shutdownError.message());

        OnClose();
    }

    /// Marks the socket for closing after write buffer becomes empty
    void DelayedCloseSocket()
    {
        if (_closing.exchange(true))
            return;

        if (_writeQueue.empty())
            CloseSocket();
    }

    MessageBuffer& GetReadBuffer() { return _readBuffer; }

protected:
    virtual void OnClose() { }

    virtual void ReadHandler() = 0;

    bool AsyncProcessQueue()
    {
        if (_isWritingAsync)
            return false;

        _isWritingAsync = true;

#ifdef TC_SOCKET_USE_IOCP
        MessageBuffer& buffer = _writeQueue.front();
        _socket.async_write_some(boost::asio::buffer(buffer.GetReadPointer(), buffer.GetActiveSize()), std::bind(&Socket<T>::WriteHandler,
            this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
#else
        _socket.async_write_some(boost::asio::null_buffers(), std::bind(&Socket<T>::WriteHandlerWrapper,
            this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
#endif

        return false;
    }

    void SetNoDelay(bool enable)
    {
        boost::system::error_code err;
        _socket.set_option(tcp::no_delay(enable), err);
        if (err)
            TC_LOG_DEBUG("network", "Socket::SetNoDelay: failed to set_option(boost::asio::ip::tcp::no_delay) for {} - {} ({})",
                GetRemoteIpAddress().to_string(), err.value(), err.message());
    }

private:
    void ReadHandlerInternal(boost::system::error_code error, size_t transferredBytes)
    {
        if (error)
        {
            CloseSocket();
            return;
        }

        _readBuffer.WriteCompleted(transferredBytes);
        ReadHandler();
    }

    // ProxyReadHeaderHandler reads Proxy Protocol v2 header (v1 is not supported).
    // See https://www.haproxy.org/download/1.8/doc/proxy-protocol.txt (2.2. Binary header format (version 2)) for more details.
    void ProxyReadHeaderHandler(boost::system::error_code error, size_t transferredBytes)
    {
        if (error)
        {
            CloseSocket();
            return;
        }

        _readBuffer.WriteCompleted(transferredBytes);

        MessageBuffer& packet = GetReadBuffer();

        const int minimumProxyProtocolV2Size = 28;
        if (packet.GetActiveSize() < minimumProxyProtocolV2Size)
        {
            AsyncReadProxyHeader();
            return;
        }

        uint8* readPointer = packet.GetReadPointer();

        const uint8 signatureSize = 12;
        const uint8 expectedSignature[signatureSize] = {0x0D, 0x0A, 0x0D, 0x0A, 0x00, 0x0D, 0x0A, 0x51, 0x55, 0x49, 0x54, 0x0A};
        if (memcmp(packet.GetReadPointer(), expectedSignature, signatureSize) != 0)
        {
            _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_FAILED;
            TC_LOG_DEBUG("network", "Socket::ProxyReadHeaderHandler: received bad PROXY Protocol v2 signature for {}", GetRemoteIpAddress().to_string());
            return;
        }

        const uint8 version = (readPointer[signatureSize] & 0xF0) >> 4;
        const uint8 command = (readPointer[signatureSize] & 0xF);

        if (version != 2)
        {
            _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_FAILED;
            TC_LOG_DEBUG("network", "Socket::ProxyReadHeaderHandler: received bad PROXY Protocol v2 signature for {}", GetRemoteIpAddress().to_string());
            return;
        }

        const uint8 addressFamily = readPointer[13];
        const uint16 len = (readPointer[14] << 8) | readPointer[15];
        if (static_cast<size_t>(len) + 16 > packet.GetActiveSize())
        {
            AsyncReadProxyHeader();
            return;
        }

        // Connection created by a proxy itself (health checks?), ignore and do nothing.
        if (command == 0)
        {
            packet.ReadCompleted(len+16);
            _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_FINISHED;
            return;
        }

        auto remainingLen = packet.GetActiveSize() - 16;
        readPointer += 16; // Skip strait to address.

        switch (addressFamily)
        {
            case PROXY_HEADER_ADDRESS_FAMILY_AND_PROTOCOL_TCP_V4:
            {
                if (remainingLen < 12)
                {
                    AsyncReadProxyHeader();
                    return;
                }

                boost::asio::ip::address_v4::bytes_type b;
                auto addressSize = sizeof(b);

                std::copy(readPointer, readPointer+addressSize, b.begin());
                _remoteAddress = boost::asio::ip::address_v4(b);

                readPointer += 2 * addressSize; // Skip server address.
                _remotePort = (readPointer[0] << 8) | readPointer[1];

                break;
            }

            case PROXY_HEADER_ADDRESS_FAMILY_AND_PROTOCOL_TCP_V6:
            {
                if (remainingLen < 36)
                {
                    AsyncReadProxyHeader();
                    return;
                }

                boost::asio::ip::address_v6::bytes_type b;
                auto addressSize = sizeof(b);

                std::copy(readPointer, readPointer+addressSize, b.begin());
                _remoteAddress = boost::asio::ip::address_v6(b);

                readPointer += 2 * addressSize; // Skip server address.
                _remotePort = (readPointer[0] << 8) | readPointer[1];

                break;
            }

            default:
                _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_FAILED;
                TC_LOG_DEBUG("network", "Socket::ProxyReadHeaderHandler: unsupported address family type {}", GetRemoteIpAddress().to_string());
                return;
        }

        packet.ReadCompleted(len+16);
        _proxyHeaderReadingState = PROXY_HEADER_READING_STATE_FINISHED;
    }

#ifdef TC_SOCKET_USE_IOCP

    void WriteHandler(boost::system::error_code error, std::size_t transferedBytes)
    {
        if (!error)
        {
            _isWritingAsync = false;
            _writeQueue.front().ReadCompleted(transferedBytes);
            if (!_writeQueue.front().GetActiveSize())
                _writeQueue.pop();

            if (!_writeQueue.empty())
                AsyncProcessQueue();
            else if (_closing)
                CloseSocket();
        }
        else
            CloseSocket();
    }

#else

    void WriteHandlerWrapper(boost::system::error_code /*error*/, std::size_t /*transferedBytes*/)
    {
        _isWritingAsync = false;
        HandleQueue();
    }

    bool HandleQueue()
    {
        if (_writeQueue.empty())
            return false;

        MessageBuffer& queuedMessage = _writeQueue.front();

        std::size_t bytesToSend = queuedMessage.GetActiveSize();

        boost::system::error_code error;
        std::size_t bytesSent = _socket.write_some(boost::asio::buffer(queuedMessage.GetReadPointer(), bytesToSend), error);

        if (error)
        {
            if (error == boost::asio::error::would_block || error == boost::asio::error::try_again)
                return AsyncProcessQueue();

            _writeQueue.pop();
            if (_closing && _writeQueue.empty())
                CloseSocket();
            return false;
        }
        else if (bytesSent == 0)
        {
            _writeQueue.pop();
            if (_closing && _writeQueue.empty())
                CloseSocket();
            return false;
        }
        else if (bytesSent < bytesToSend) // now n > 0
        {
            queuedMessage.ReadCompleted(bytesSent);
            return AsyncProcessQueue();
        }

        _writeQueue.pop();
        if (_closing && _writeQueue.empty())
            CloseSocket();
        return !_writeQueue.empty();
    }

#endif

    tcp::socket _socket;

    boost::asio::ip::address _remoteAddress;
    uint16 _remotePort;

    MessageBuffer _readBuffer;
    std::queue<MessageBuffer> _writeQueue;

    std::atomic<bool> _closed;
    std::atomic<bool> _closing;

    bool _isWritingAsync;

    ProxyHeaderReadingState _proxyHeaderReadingState;
};

#endif // __SOCKET_H__
