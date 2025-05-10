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

#ifndef TRINITYCORE_IP_BAN_CHECK_CONNECTION_INITIALIZER_H
#define TRINITYCORE_IP_BAN_CHECK_CONNECTION_INITIALIZER_H

#include "DatabaseEnvFwd.h"
#include "Log.h"
#include "QueryCallback.h"
#include "SocketConnectionInitializer.h"

namespace Trinity::Net
{
namespace IpBanCheckHelpers
{
TC_SHARED_API QueryCallback AsyncQuery(std::string_view ipAddress);
TC_SHARED_API bool IsBanned(PreparedQueryResult const& result);
}

template <typename SocketImpl>
struct IpBanCheckConnectionInitializer final : SocketConnectionInitializer
{
    explicit IpBanCheckConnectionInitializer(SocketImpl* socket) : _socket(socket) { }

    void Start() override
    {
        _socket->QueueQuery(IpBanCheckHelpers::AsyncQuery(_socket->GetRemoteIpAddress().to_string()).WithPreparedCallback([socketRef = _socket->weak_from_this(), self = this->shared_from_this()](PreparedQueryResult const& result)
        {
            std::shared_ptr<SocketImpl> socket = static_pointer_cast<SocketImpl>(socketRef.lock());
            if (!socket)
                return;

            if (IpBanCheckHelpers::IsBanned(result))
            {
                TC_LOG_ERROR("network", "IpBanCheckConnectionInitializer: IP {} is banned.", socket->GetRemoteIpAddress().to_string());
                socket->CloseSocket();
                return;
            }

            if (self->next)
                self->next->Start();
        }));
    }

private:
    SocketImpl* _socket;
};
}

#endif // TRINITYCORE_IP_BAN_CHECK_CONNECTION_INITIALIZER_H
