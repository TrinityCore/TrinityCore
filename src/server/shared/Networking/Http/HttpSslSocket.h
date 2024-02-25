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

#ifndef TRINITYCORE_HTTP_SSL_SOCKET_H
#define TRINITYCORE_HTTP_SSL_SOCKET_H

#include "BaseHttpSocket.h"
#include "SslSocket.h"
#include <boost/beast/core/stream_traits.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/ssl/ssl_stream.hpp>

namespace Trinity::Net::Http
{
namespace Impl
{
class BoostBeastSslSocketWrapper : public ::SslSocket<boost::beast::ssl_stream<boost::beast::tcp_stream>>
{
public:
    using SslSocket::SslSocket;

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        _sslSocket.shutdown(shutdownError);
        boost::beast::get_lowest_layer(_sslSocket).socket().shutdown(what, shutdownError);
    }

    void close(boost::system::error_code& /*error*/)
    {
        boost::beast::get_lowest_layer(_sslSocket).close();
    }

    boost::asio::ip::tcp::socket::endpoint_type remote_endpoint() const
    {
        return boost::beast::get_lowest_layer(_sslSocket).socket().remote_endpoint();
    }
};
}

template <typename Derived>
class SslSocket : public BaseSocket<Derived, Impl::BoostBeastSslSocketWrapper>
{
    using SocketBase = BaseSocket<Derived, Impl::BoostBeastSslSocketWrapper>;

public:
    explicit SslSocket(boost::asio::ip::tcp::socket&& socket, boost::asio::ssl::context& sslContext)
        : SocketBase(std::move(socket), sslContext) { }

    SslSocket(SslSocket const& other) = delete;
    SslSocket(SslSocket&& other) = delete;
    SslSocket& operator=(SslSocket const& other) = delete;
    SslSocket& operator=(SslSocket&& other) = delete;

    ~SslSocket() = default;

    void Start() override
    {
        this->AsyncHandshake();
    }

    void AsyncHandshake()
    {
        this->underlying_stream().async_handshake(boost::asio::ssl::stream_base::server,
            [self = this->shared_from_this()](boost::system::error_code const& error) { self->HandshakeHandler(error); });
    }

    void HandshakeHandler(boost::system::error_code const& error)
    {
        if (error)
        {
            TC_LOG_ERROR("server.http.session.ssl", "{} SSL Handshake failed {}", this->GetClientInfo(), error.message());
            this->CloseSocket();
            return;
        }

        this->ResetHttpParser();

        this->AsyncRead();
    }
};
}

#endif // TRINITYCORE_HTTP_SSL_SOCKET_H
