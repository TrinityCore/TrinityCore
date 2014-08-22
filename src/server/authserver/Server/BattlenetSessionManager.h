/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef BattlenetSessionManager_h__
#define BattlenetSessionManager_h__

#include "BattlenetSession.h"

namespace Battlenet
{
#pragma pack(push, 1)

    struct SessionInfo
    {
        uint32 AccountId;
        uint32 GameAccountIndex;

        bool operator<(SessionInfo const& right) const
        {
            return memcmp(this, &right, sizeof(SessionInfo)) < 0;
        }
    };

#pragma pack(pop)

    class SessionManager
    {
    public:
        static SessionManager& Instance()
        {
            static SessionManager instance;
            return instance;
        }

        // noop for now, will be needed later to broadcast realmlist updates for example
        void AddSession(Session* /*session*/) { }

        void RemoveSession(Session* /*session*/) { }

    private:
        std::map<SessionInfo, Session> _sessions;
    };
}

#define sBattlenetSessionMgr Battlenet::SessionManager::Instance()

#endif // BattlenetSessionManager_h__
