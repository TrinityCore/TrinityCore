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

#ifndef TRINITYCORE_HTTP_SOCKET_H
#define TRINITYCORE_HTTP_SOCKET_H

#include "BaseHttpSocket.h"
#include <boost/beast/core/tcp_stream.hpp>

namespace Trinity::Net::Http
{
namespace Impl
{
class BoostBeastSocketWrapper : public boost::beast::tcp_stream
{
public:
    using boost::beast::tcp_stream::tcp_stream;

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        socket().shutdown(what, shutdownError);
    }

    void close(boost::system::error_code& /*error*/)
    {
        boost::beast::tcp_stream::close();
    }

    boost::asio::ip::tcp::socket::endpoint_type remote_endpoint() const
    {
        return socket().remote_endpoint();
    }
};
}

template <typename Derived>
class Socket : public BaseSocket<Derived, Impl::BoostBeastSocketWrapper>
{
    using SocketBase = BaseSocket<Derived, Impl::BoostBeastSocketWrapper>;

public:
    template<typename... Args>
    explicit Socket(boost::asio::ip::tcp::socket&& socket, Args&&...)
        : SocketBase(std::move(socket)) { }

    Socket(Socket const& other) = delete;
    Socket(Socket&& other) = delete;
    Socket& operator=(Socket const& other) = delete;
    Socket& operator=(Socket&& other) = delete;

    ~Socket() = default;

    void Start() override
    {
        this->ResetHttpParser();

        this->AsyncRead();
    }
};
}

#endif // TRINITYCORE_HTTP_SOCKET_H
