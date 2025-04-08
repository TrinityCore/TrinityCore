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

#ifndef TRINITYCORE_SSL_STREAM_H
#define TRINITYCORE_SSL_STREAM_H

#include "SocketConnectionInitializer.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/system/error_code.hpp>

namespace Trinity::Net
{
template <typename SocketImpl>
struct SslHandshakeConnectionInitializer final : SocketConnectionInitializer
{
    explicit SslHandshakeConnectionInitializer(SocketImpl* socket) : _socket(socket) { }

    void Start() override
    {
        _socket->underlying_stream().async_handshake(boost::asio::ssl::stream_base::server,
            [socketRef = _socket->weak_from_this(), self = this->shared_from_this()](boost::system::error_code const& error)
            {
                std::shared_ptr<SocketImpl> socket = static_pointer_cast<SocketImpl>(socketRef.lock());
                if (!socket)
                    return;

                if (error)
                {
                    TC_LOG_ERROR("session", "{} SSL Handshake failed {}", socket->GetClientInfo(), error.message());
                    socket->CloseSocket();
                    return;
                }

                if (self->next)
                    self->next->Start();
        });
    }

private:
    SocketImpl* _socket;
};

template<class WrappedStream = IoContextTcpSocket>
class SslStream
{
public:
    explicit SslStream(IoContextTcpSocket&& socket, boost::asio::ssl::context& sslContext) : _sslSocket(std::move(socket), sslContext)
    {
        _sslSocket.set_verify_mode(boost::asio::ssl::verify_none);
    }

    explicit SslStream(boost::asio::io_context& context, boost::asio::ssl::context& sslContext) : _sslSocket(context, sslContext)
    {
        _sslSocket.set_verify_mode(boost::asio::ssl::verify_none);
    }

    // adapting tcp::socket api
    void close(boost::system::error_code& error)
    {
        _sslSocket.next_layer().close(error);
    }

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        _sslSocket.shutdown(shutdownError);
        _sslSocket.next_layer().shutdown(what, shutdownError);
    }

    template<typename MutableBufferSequence, typename ReadHandlerType>
    void async_read_some(MutableBufferSequence const& buffers, ReadHandlerType&& handler)
    {
        _sslSocket.async_read_some(buffers, std::forward<ReadHandlerType>(handler));
    }

    template<typename ConstBufferSequence, typename WriteHandlerType>
    void async_write_some(ConstBufferSequence const& buffers, WriteHandlerType&& handler)
    {
        _sslSocket.async_write_some(buffers, std::forward<WriteHandlerType>(handler));
    }

    template<typename ConstBufferSequence>
    std::size_t write_some(ConstBufferSequence const& buffers, boost::system::error_code& error)
    {
        return _sslSocket.write_some(buffers, error);
    }

    template<typename WaitHandlerType>
    void async_wait(boost::asio::socket_base::wait_type type, WaitHandlerType&& handler)
    {
        _sslSocket.next_layer().async_wait(type, std::forward<WaitHandlerType>(handler));
    }

    template<typename SettableSocketOption>
    void set_option(SettableSocketOption const& option, boost::system::error_code& error)
    {
        _sslSocket.next_layer().set_option(option, error);
    }

    IoContextTcpSocket::endpoint_type remote_endpoint() const
    {
        return _sslSocket.next_layer().remote_endpoint();
    }

    // ssl api
    template<typename HandshakeHandlerType>
    void async_handshake(boost::asio::ssl::stream_base::handshake_type type, HandshakeHandlerType&& handler)
    {
        _sslSocket.async_handshake(type, std::forward<HandshakeHandlerType>(handler));
    }

protected:
    boost::asio::ssl::stream<WrappedStream> _sslSocket;
};
}

#endif // TRINITYCORE_SSL_STREAM_H
