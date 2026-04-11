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

#ifndef TRINITYCORE_SESSION_MANAGER_H
#define TRINITYCORE_SESSION_MANAGER_H

#include "SocketMgr.h"
#include "Session.h"

namespace Battlenet
{
    class SessionNetworkThread final : public Trinity::Net::NetworkThread<Session, SessionNetworkThread>
    {
    };

    class SessionManager;

    struct SessionManagerTraits
    {
        using Self = SessionManager;
        using SocketType = Session;
        using ThreadType = SessionNetworkThread;
    };

    class SessionManager final : public Trinity::Net::SocketMgr<SessionManagerTraits>
    {
    public:
        static SessionManager& Instance();
    };
}

#define sSessionMgr Battlenet::SessionManager::Instance()

#endif // TRINITYCORE_SESSION_MANAGER_H
