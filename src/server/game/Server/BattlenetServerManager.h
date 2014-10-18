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

#ifndef BattlenetMgr_h__
#define BattlenetMgr_h__

#include "ZmqMux.h"
#include "Commands.h"

namespace zmqpp
{
    class socket;
}

namespace Battlenet
{
    class ServerManager
    {
        ServerManager() : _socket(nullptr) { }

    public:
        void InitializeConnection();
        void CloseConnection();

        static ServerManager& Instance()
        {
            static ServerManager instance;
            return instance;
        }

        void SendChangeToonOnlineState(uint32 battlenetAccountId, uint32 gameAccountId, ObjectGuid guid, std::string const& name, bool online);

    private:
        static Header CreateHeader(BnetCommands command);
        ZmqMux* _socket;
    };
}

#define sBattlenetServer Battlenet::ServerManager::Instance()

#endif // BattlenetMgr_h__
