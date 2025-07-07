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

namespace Trinity::Net::Http
{
class TC_NETWORK_API Socket : public BaseSocket<Impl::BoostBeastSocketWrapper>
{
    using SocketBase = BaseSocket<Impl::BoostBeastSocketWrapper>;

public:
    explicit Socket(IoContextTcpSocket&& socket);

    explicit Socket(boost::asio::io_context& context);

    Socket(Socket const& other) = delete;
    Socket(Socket&& other) = delete;
    Socket& operator=(Socket const& other) = delete;
    Socket& operator=(Socket&& other) = delete;

    ~Socket();

    void Start() override;
};
}

#endif // TRINITYCORE_HTTP_SOCKET_H
