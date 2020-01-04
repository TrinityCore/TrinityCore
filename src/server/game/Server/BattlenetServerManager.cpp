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

#include "Config.h"
#include "World.h"
#include "ZmqContext.h"
#include "BattlenetServerManager.h"

void IPC::BattlenetComm::ServerManager::InitializeConnection()
{
    std::string bnetserverAddress = sConfigMgr->GetStringDefault("BnetServer.Address", "127.0.0.1");
    int32 bnetserverPort = sConfigMgr->GetIntDefault("BnetServer.Port", 1118);
    _socket = new ZmqMux("inproc://bnetmgr", "tcp://" + bnetserverAddress + ":" + std::to_string(bnetserverPort));
    _socket->Start();
}

void IPC::BattlenetComm::ServerManager::CloseConnection()
{
    _socket->End();
    delete _socket;
    _socket = nullptr;
}

IPC::BattlenetComm::ServerManager& IPC::BattlenetComm::ServerManager::Instance()
{
    static ServerManager instance;
    return instance;
}

IPC::BattlenetComm::Header IPC::BattlenetComm::ServerManager::CreateHeader(BnetCommands command)
{
    Header header;
    header.Ipc.Channel = IPC_CHANNEL_BNET;
    header.Ipc.Command = command;
    header.Realm = realm.Id;
    return header;
}

void IPC::BattlenetComm::ServerManager::SendChangeToonOnlineState(uint32 battlenetAccountId, uint32 gameAccountId, ObjectGuid guid, std::string const& name, bool online)
{
    // Do nothing for Grunt login
    if (!battlenetAccountId)
        return;

    Header header = CreateHeader(BNET_CHANGE_TOON_ONLINE_STATE);
    ToonHandle toon;
    toon.AccountId = battlenetAccountId;
    toon.GameAccountId = gameAccountId;
    toon.Guid = guid.GetCounter();
    toon.Name = name;

    zmqpp::message msg;
    msg << header;
    msg << toon;
    msg << online;

    Send(&msg);
}

void IPC::BattlenetComm::ServerManager::Send(zmqpp::message* msg)
{
    if (!_socket)
        return;

    _socket->Send(msg);
}
