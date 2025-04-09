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
#include <array>

namespace Trinity::Net::Http
{
class Socket : public BaseSocket<Impl::BoostBeastSocketWrapper>
{
    using SocketBase = BaseSocket<Impl::BoostBeastSocketWrapper>;

public:
    using SocketBase::SocketBase;

    Socket(Socket const& other) = delete;
    Socket(Socket&& other) = delete;
    Socket& operator=(Socket const& other) = delete;
    Socket& operator=(Socket&& other) = delete;

    ~Socket() = default;

    void Start() override
    {
        std::array<std::shared_ptr<SocketConnectionInitializer>, 2> initializers =
        { {
            std::make_shared<HttpConnectionInitializer<SocketBase>>(this),
            std::make_shared<ReadConnectionInitializer<SocketBase>>(this),
        } };

        SocketConnectionInitializer::SetupChain(initializers)->Start();
    }
};
}

#endif // TRINITYCORE_HTTP_SOCKET_H
