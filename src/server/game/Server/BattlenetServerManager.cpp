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

#include "Config.h"
#include "World.h"
#include "ZmqContext.h"
#include "BattlenetServerManager.h"

void Battlenet::ServerManager::InitializeConnection()
{
    std::string bnetserverAddress = sConfigMgr->GetStringDefault("BnetServer.Address", "127.0.0.1");
    int32 bnetserverPort = sConfigMgr->GetIntDefault("BnetServer.Port", 1118);
    _socket = new ZmqMux("inproc://bnetmgr", "tcp://" + bnetserverAddress + ":" + std::to_string(bnetserverPort));
    _socket->Start();
}

void Battlenet::ServerManager::CloseConnection()
{
    _socket->End();
    delete _socket;
    _socket = nullptr;
}

Battlenet::Header Battlenet::ServerManager::CreateHeader(BnetCommands command)
{
    Header header;
    header.Ipc.Channel = IPC_CHANNEL_BNET;
    header.Ipc.Command = command;
    header.Realm = realmHandle;
    return header;
}

void Battlenet::ServerManager::SendChangeToonOnlineState(uint32 battlenetAccountId, uint32 gameAccountId, ObjectGuid guid, std::string const& name, bool online)
{
    // Do nothing for Grunt login
    if (!battlenetAccountId)
        return;

    Header header = CreateHeader(BNET_CHANGE_TOON_ONLINE_STATE);
    ToonHandle toon;
    toon.AccountId = battlenetAccountId;
    toon.GameAccountId = gameAccountId;
    toon.Guid = guid;
    toon.Name = name;

    zmqpp::message msg;
    msg << header;
    msg << toon;
    msg << online;

    _socket->Send(&msg);
}
