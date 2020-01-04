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

#ifndef BattlenetMgr_h__
#define BattlenetMgr_h__

#include "ZmqMux.h"
#include "Commands.h"

namespace zmqpp
{
    class socket;
    class message;
}

namespace IPC
{
    namespace BattlenetComm
    {
        class TC_GAME_API ServerManager
        {
            ServerManager() : _socket(nullptr) { }

        public:
            void InitializeConnection();
            void CloseConnection();

            static ServerManager& Instance();

            void SendChangeToonOnlineState(uint32 battlenetAccountId, uint32 gameAccountId, ObjectGuid guid, std::string const& name, bool online);

        private:
            void Send(zmqpp::message* msg);

            static Header CreateHeader(BnetCommands command);
            ZmqMux* _socket;
        };
    }
}

#define sBattlenetServer IPC::BattlenetComm::ServerManager::Instance()

#endif // BattlenetMgr_h__
