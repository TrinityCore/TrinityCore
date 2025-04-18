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

#ifndef TRINITYCORE_SOCKET_H
#define TRINITYCORE_SOCKET_H

#include "Concepts.h"
#include "Log.h"
#include "MessageBuffer.h"
#include "SocketConnectionInitializer.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <atomic>
#include <memory>
#include <queue>
#include <type_traits>

#define READ_BLOCK_SIZE 4096
#ifdef BOOST_ASIO_HAS_IOCP
#define TC_SOCKET_USE_IOCP
#endif

namespace Trinity::Net
{
using IoContextTcpSocket = boost::asio::basic_stream_socket<boost::asio::ip::tcp, boost::asio::io_context::executor_type>;

enum class SocketReadCallbackResult
{
    KeepReading,
    Stop
};

inline boost::asio::mutable_buffer PrepareReadBuffer(MessageBuffer& readBuffer)
{
    readBuffer.Normalize();
    readBuffer.EnsureFreeSpace();
    return boost::asio::buffer(readBuffer.GetWritePointer(), readBuffer.GetRemainingSpace());
}

template <typename Callable>
concept SocketReadCallback = Trinity::invocable_r<Callable, SocketReadCallbackResult>;

template <typename SocketType>
struct InvokeReadHandlerCallback
{
    SocketReadCallbackResult operator()() const
    {
        return this->Socket->ReadHandler();
    }

    SocketType* Socket;
};

template <typename SocketType>
struct ReadConnectionInitializer final : SocketConnectionInitializer
{
    explicit ReadConnectionInitializer(SocketType* socket) : ReadCallback({ .Socket = socket }) { }

    void Start() override
    {
        ReadCallback.Socket->AsyncRead(std::move(ReadCallback));

        if (this->next)
            this->next->Start();
    }

    InvokeReadHandlerCallback<SocketType> ReadCallback;
};

/**
    @class Socket

    Base async socket implementation

    @tparam Stream stream type used for operations on socket
            Stream must implement the following methods:

            boost::asio::io_context::executor_type get_executor();

            bool is_open() const;

            void close(boost::system::error_code& error);

            void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError);

            template<typename MutableBufferSequence, typename ReadHandlerType>
            void async_read_some(MutableBufferSequence const& buffers, ReadHandlerType&& handler);

            template<typename ConstBufferSequence, typename WriteHandlerType>
            void async_write_some(ConstBufferSequence const& buffers, WriteHandlerType&& handler);

            template<typename ConstBufferSequence>
            std::size_t write_some(ConstBufferSequence const& buffers, boost::system::error_code& error);

            template<typename WaitHandlerType>
            void async_wait(boost::asio::socket_base::wait_type type, WaitHandlerType&& handler);

            template<typename SettableSocketOption>
            void set_option(SettableSocketOption const& option, boost::system::error_code& error);

            tcp::socket::endpoint_type remote_endpoint() const;
*/
template<class Stream = IoContextTcpSocket>
class Socket : public std::enable_shared_from_this<Socket<Stream>>
{
public:
    template<typename... Args>
    explicit Socket(IoContextTcpSocket&& socket, Args&&... args) : _socket(std::move(socket), std::forward<Args>(args)...),
        _remoteAddress(_socket.remote_endpoint().address()), _remotePort(_socket.remote_endpoint().port()), _openState(OpenState_Open)
    {
    }

    template<typename... Args>
    explicit Socket(boost::asio::io_context& context, Args&&... args) : _socket(context, std::forward<Args>(args)...), _openState(OpenState_Closed)
    {
    }

    Socket(Socket const& other) = delete;
    Socket(Socket&& other) = delete;
    Socket& operator=(Socket const& other) = delete;
    Socket& operator=(Socket&& other) = delete;

    virtual ~Socket()
    {
        _openState = OpenState_Closed;
        boost::system::error_code error;
        _socket.close(error);
    }

    virtual void Start() { }

    virtual bool Update()
    {
        if (_openState == OpenState_Closed)
            return false;

#ifndef TC_SOCKET_USE_IOCP
        if (_isWritingAsync || (_writeQueue.empty() && _openState == OpenState_Open))
            return true;

        for (; HandleQueue();)
            ;
#endif

        return true;
    }

    boost::asio::ip::address const& GetRemoteIpAddress() const
    {
        return _remoteAddress;
    }

    uint16 GetRemotePort() const
    {
        return _remotePort;
    }

    template <SocketReadCallback Callback>
    void AsyncRead(Callback&& callback)
    {
        if (!IsOpen())
            return;

        _socket.async_read_some(PrepareReadBuffer(_readBuffer),
            [self = this->shared_from_this(), callback = std::forward<Callback>(callback)](boost::system::error_code const& error, size_t transferredBytes) mutable
            {
                if (self->ReadHandlerInternal(error, transferredBytes))
                    if (callback() == SocketReadCallbackResult::KeepReading)
                        self->AsyncRead(std::forward<Callback>(callback));
            });
    }

    void QueuePacket(MessageBuffer&& buffer)
    {
        _writeQueue.push(std::move(buffer));

#ifdef TC_SOCKET_USE_IOCP
        AsyncProcessQueue();
#endif
    }

    bool IsOpen() const { return _openState == OpenState_Open; }

    void CloseSocket()
    {
        if ((_openState.fetch_or(OpenState_Closed) & OpenState_Closed) == 0)
            return;

        boost::system::error_code shutdownError;
        _socket.shutdown(boost::asio::socket_base::shutdown_send, shutdownError);
        if (shutdownError)
            TC_LOG_DEBUG("network", "Socket::CloseSocket: {} errored when shutting down socket: {} ({})", GetRemoteIpAddress().to_string(),
                shutdownError.value(), shutdownError.message());

        this->OnClose();
    }

    /// Marks the socket for closing after write buffer becomes empty
    void DelayedCloseSocket()
    {
        if (_openState.fetch_or(OpenState_Closing) != 0)
            return;

        if (_writeQueue.empty())
            CloseSocket();
    }

    MessageBuffer& GetReadBuffer() { return _readBuffer; }

    Stream& underlying_stream()
    {
        return _socket;
    }

protected:
    virtual void OnClose() { }

    virtual SocketReadCallbackResult ReadHandler() { return SocketReadCallbackResult::KeepReading; }

    bool AsyncProcessQueue()
    {
        if (_isWritingAsync)
            return false;

        _isWritingAsync = true;

#ifdef TC_SOCKET_USE_IOCP
        MessageBuffer& buffer = _writeQueue.front();
        _socket.async_write_some(boost::asio::buffer(buffer.GetReadPointer(), buffer.GetActiveSize()),
            [self = this->shared_from_this()](boost::system::error_code const& error, std::size_t transferedBytes)
            {
                self->WriteHandler(error, transferedBytes);
            });
#else
        _socket.async_wait(boost::asio::socket_base::wait_type::wait_write,
            [self = this->shared_from_this()](boost::system::error_code const& error)
            {
                self->WriteHandlerWrapper(error);
            });
#endif

        return false;
    }

    void SetNoDelay(bool enable)
    {
        boost::system::error_code err;
        _socket.set_option(boost::asio::ip::tcp::no_delay(enable), err);
        if (err)
            TC_LOG_DEBUG("network", "Socket::SetNoDelay: failed to set_option(boost::asio::ip::tcp::no_delay) for {} - {} ({})",
                GetRemoteIpAddress().to_string(), err.value(), err.message());
    }

private:
    bool ReadHandlerInternal(boost::system::error_code const& error, size_t transferredBytes)
    {
        if (error)
        {
            CloseSocket();
            return false;
        }

        _readBuffer.WriteCompleted(transferredBytes);
        return IsOpen();
    }

#ifdef TC_SOCKET_USE_IOCP

    void WriteHandler(boost::system::error_code const& error, std::size_t transferedBytes)
    {
        if (!error)
        {
            _isWritingAsync = false;
            _writeQueue.front().ReadCompleted(transferedBytes);
            if (!_writeQueue.front().GetActiveSize())
                _writeQueue.pop();

            if (!_writeQueue.empty())
                AsyncProcessQueue();
            else if (_openState == OpenState_Closing)
                CloseSocket();
        }
        else
            CloseSocket();
    }

#else

    void WriteHandlerWrapper(boost::system::error_code const& /*error*/)
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
            if (_openState == OpenState_Closing && _writeQueue.empty())
                CloseSocket();
            return false;
        }
        else if (bytesSent == 0)
        {
            _writeQueue.pop();
            if (_openState == OpenState_Closing && _writeQueue.empty())
                CloseSocket();
            return false;
        }
        else if (bytesSent < bytesToSend) // now n > 0
        {
            queuedMessage.ReadCompleted(bytesSent);
            return AsyncProcessQueue();
        }

        _writeQueue.pop();
        if (_openState == OpenState_Closing && _writeQueue.empty())
            CloseSocket();
        return !_writeQueue.empty();
    }

#endif

    Stream _socket;

    boost::asio::ip::address _remoteAddress;
    uint16 _remotePort = 0;

    MessageBuffer _readBuffer = MessageBuffer(READ_BLOCK_SIZE);
    std::queue<MessageBuffer> _writeQueue;

    // Socket open state "enum" (not enum to enable integral std::atomic api)
    static constexpr uint8 OpenState_Open       = 0x0;
    static constexpr uint8 OpenState_Closing    = 0x1;  ///< Transition to Closed state after sending all queued data
    static constexpr uint8 OpenState_Closed     = 0x2;

    std::atomic<uint8> _openState;

    bool _isWritingAsync = false;
};
}

#endif // TRINITYCORE_SOCKET_H
