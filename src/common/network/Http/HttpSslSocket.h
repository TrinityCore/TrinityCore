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
#include "SslStream.h"

namespace Trinity::Net::Http
{
class TC_NETWORK_API SslSocket : public BaseSocket<SslStream<Impl::BoostBeastSocketWrapper>>
{
    using SocketBase = BaseSocket<SslStream<Impl::BoostBeastSocketWrapper>>;

public:
    explicit SslSocket(IoContextTcpSocket&& socket, boost::asio::ssl::context& sslContext);

    explicit SslSocket(boost::asio::io_context& context, boost::asio::ssl::context& sslContext);

    SslSocket(SslSocket const& other) = delete;
    SslSocket(SslSocket&& other) = delete;
    SslSocket& operator=(SslSocket const& other) = delete;
    SslSocket& operator=(SslSocket&& other) = delete;

    ~SslSocket();

    void Start() override;
};
}

#endif // TRINITYCORE_HTTP_SSL_SOCKET_H
