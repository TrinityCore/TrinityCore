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
#include "IpAddress.h"
#include "Log.h"
#include "MessageBuffer.h"
#include "SocketConnectionInitializer.h"
#include <boost/asio/compose.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <atomic>
#include <memory>
#include <queue>
#include <type_traits>

#ifdef BOOST_ASIO_HAS_IOCP
#define TC_SOCKET_USE_IOCP
#endif

namespace Trinity::Net
{
using IoContextTcpSocket = boost::asio::basic_stream_socket<boost::asio::ip::tcp, boost::asio::io_context::executor_type>;

namespace Impl::Operations
{
template <typename Socket>
struct Connect;
}

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

template <typename SocketType>
struct InvokeReadHandlerCallback
{
    SocketReadCallbackResult operator()() const
    {
        return this->Socket->ReadHandler();
    }

    SocketType* Socket;
};

template <typename AsyncReadObjectType, typename ReadHandlerObjectType = AsyncReadObjectType>
struct ReadConnectionInitializer final : SocketConnectionInitializer
{
    explicit ReadConnectionInitializer(AsyncReadObjectType* socket) : Socket(socket), ReadCallback({ .Socket = socket }) { }
    explicit ReadConnectionInitializer(AsyncReadObjectType* socket, ReadHandlerObjectType* callbackSocket) : Socket(socket), ReadCallback({ .Socket = callbackSocket }) { }

    void Start() override
    {
        Socket->AsyncRead(std::move(ReadCallback));

        this->InvokeNext();
    }

    AsyncReadObjectType* Socket;
    InvokeReadHandlerCallback<ReadHandlerObjectType> ReadCallback;
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

            template<typename ConnectHandlerType>
            void async_connect(boost::asio::ip::tcp::endpoint const& endpoint, ConnectHandlerType&& handler);

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

    template <BOOST_ASIO_COMPLETION_TOKEN_FOR(void(boost::system::error_code, boost::asio::ip::tcp::endpoint)) Callback>
    decltype(auto) Connect(boost::asio::ip::tcp::endpoint const& endpoint, Callback&& callback)
    {
        _openState = OpenState_Open;
        return boost::asio::async_compose<Callback, void(boost::system::error_code, boost::asio::ip::tcp::endpoint), Impl::Operations::Connect<Socket>>(
            Impl::Operations::Connect<Socket>(this->shared_from_this(), endpoint), callback, this->underlying_stream());
    }

    template <BOOST_ASIO_COMPLETION_TOKEN_FOR(void(boost::system::error_code, boost::asio::ip::tcp::endpoint)) Callback>
    decltype(auto) Connect(std::vector<boost::asio::ip::tcp::endpoint> const& endpoints, Callback&& callback)
    {
        _openState = OpenState_Open;
        return boost::asio::async_compose<Callback, void(boost::system::error_code, boost::asio::ip::tcp::endpoint), Impl::Operations::Connect<Socket>>(
            Impl::Operations::Connect<Socket>(this->shared_from_this(), endpoints), callback, this->underlying_stream());
    }

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

    void SetRemoteEndpoint(boost::asio::ip::tcp::endpoint const& endpoint)
    {
        _remoteAddress = endpoint.address();
        _remotePort = endpoint.port();
    }

    template <invocable_r<SocketReadCallbackResult> Callback>
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
            TC_LOG_DEBUG("network", "Socket::CloseSocket: {} errored when shutting down socket: {} ({})", GetRemoteIpAddress(),
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
                GetRemoteIpAddress(), err.value(), err.message());
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

    void QueuedBufferWriteDone()
    {
        _writeQueue.pop();
        if (_openState == OpenState_Closing && _writeQueue.empty())
            CloseSocket();
    }

#ifdef TC_SOCKET_USE_IOCP

    void WriteHandler(boost::system::error_code const& error, std::size_t transferedBytes)
    {
        if (!error)
        {
            _isWritingAsync = false;
            _writeQueue.front().ReadCompleted(transferedBytes);
            if (!_writeQueue.front().GetActiveSize())
                QueuedBufferWriteDone();

            if (!_writeQueue.empty())
                AsyncProcessQueue();
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

            QueuedBufferWriteDone();
            return false;
        }
        else if (bytesSent == 0)
        {
            QueuedBufferWriteDone();
            return false;
        }
        else if (bytesSent < bytesToSend) // now n > 0
        {
            queuedMessage.ReadCompleted(bytesSent);
            return AsyncProcessQueue();
        }

        QueuedBufferWriteDone();
        return !_writeQueue.empty();
    }

#endif

    Stream _socket;

    boost::asio::ip::address _remoteAddress;
    uint16 _remotePort = 0;

    MessageBuffer _readBuffer = MessageBuffer(0x1000);
    std::queue<MessageBuffer> _writeQueue;

    // Socket open state "enum" (not enum to enable integral std::atomic api)
    static constexpr uint8 OpenState_Open       = 0x0;
    static constexpr uint8 OpenState_Closing    = 0x1;  ///< Transition to Closed state after sending all queued data
    static constexpr uint8 OpenState_Closed     = 0x2;

    std::atomic<uint8> _openState;

    bool _isWritingAsync = false;
};

namespace Impl::Operations
{
struct ConnectState
{
    explicit ConnectState(std::shared_ptr<void> const& socketRef, boost::asio::ip::tcp::endpoint const& endpoint)
        : SocketRef(socketRef), Endpoints(1, endpoint), Index(-1) { }

    explicit ConnectState(std::shared_ptr<void> const& socketRef, std::vector<boost::asio::ip::tcp::endpoint> const& endpoints)
        : SocketRef(socketRef), Endpoints(endpoints), Index(-1) { }

    std::weak_ptr<void> SocketRef;
    std::vector<boost::asio::ip::tcp::endpoint> Endpoints;
    std::ptrdiff_t Index;
};

template <typename Socket>
struct Connect
{
    explicit Connect(std::shared_ptr<Socket> const& socketRef, boost::asio::ip::tcp::endpoint const& endpoint)
        : State(std::make_shared<ConnectState>(std::move(socketRef), endpoint)) { }

    explicit Connect(std::shared_ptr<Socket> const& socketRef, std::vector<boost::asio::ip::tcp::endpoint> const& endpoints)
        : State(std::make_shared<ConnectState>(std::move(socketRef), endpoints)) { }

    std::shared_ptr<ConnectState> State;

    template <typename Handler>
    void operator()(Handler& handler, boost::system::error_code error = {})
    {
        std::shared_ptr<Socket> socket = static_pointer_cast<Socket>(State->SocketRef.lock());
        if (!socket)
        {
            error = boost::asio::error::operation_aborted;
            handler.complete(error, boost::asio::ip::tcp::endpoint());
            return;
        }

        bool isFirst = State->Index < 0;

        if (std::max(State->Index, std::ptrdiff_t(0)) >= std::ssize(State->Endpoints))
        {
            Connect::HandleError(socket.get(), "failed to connect to any of specified endpoints");
            error = boost::asio::error::not_found;
            handler.complete(error, boost::asio::ip::tcp::endpoint());
            return;
        }

        if (!isFirst && !socket->underlying_stream().is_open())
        {
            Connect::HandleError(socket.get(), "socket closed");
            error = boost::asio::error::operation_aborted;
            handler.complete(error, boost::asio::ip::tcp::endpoint());
            return;
        }

        if (!error && !isFirst)
        {
            socket->SetRemoteEndpoint(State->Endpoints[State->Index]);
            handler.complete(error, State->Endpoints[State->Index]);
        }
        else
        {
#if BOOST_VERSION >= 107700
            if (handler.cancelled() != boost::asio::cancellation_type::none)
            {
                Connect::HandleError(socket.get(), "connect cancelled");
                error = boost::asio::error::operation_aborted;
                handler.complete(error, boost::asio::ip::tcp::endpoint());
                return;
            }
#endif

            socket->underlying_stream().close(error);
            socket->underlying_stream().async_connect(State->Endpoints[++State->Index], std::move(handler));
        }
    }

    static void HandleError(Socket* self, std::string_view message)
    {
        TC_LOG_DEBUG("network", "Socket::Connect: {}", message);
        self->CloseSocket();
    }
};
}
}

#endif // TRINITYCORE_SOCKET_H
