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

#include "Log.h"
#include "SessionManager.h"
#include "WoWRealmPackets.h"
#include "ZmqContext.h"
#include "WorldListener.h"

WorldListener::HandlerTable const WorldListener::_handlers;

WorldListener::HandlerTable::HandlerTable()
{
#define DEFINE_HANDLER(opc, func) _handlers[opc] = { func, #opc }

    DEFINE_HANDLER(BNET_CHANGE_TOON_ONLINE_STATE, &WorldListener::HandleToonOnlineStatusChange);

#undef DEFINE_HANDLER
}

WorldListener::WorldListener(uint16 worldListenPort) : _worldListenPort(worldListenPort)
{
    _worldSocket = sIpcContext->CreateNewSocket(zmqpp::socket_type::pull);
}

WorldListener::~WorldListener()
{
    delete _worldSocket;
}

void WorldListener::Run()
{
    while (!ProcessExit())
    {
        _poller->poll();
        if (_poller->events(*_worldSocket) & zmqpp::poller::poll_in)
        {
            int32 op1;
            do
            {
                zmqpp::message msg;
                _worldSocket->receive(msg);
                Dispatch(msg);
                _worldSocket->get(zmqpp::socket_option::events, op1);
            } while (op1 & zmqpp::poller::poll_in);
        }
    }
}

void WorldListener::HandleOpen()
{
    try
    {
        _worldSocket->bind(std::string("tcp://*:") + std::to_string(_worldListenPort));
    }
    catch (zmqpp::zmq_internal_exception& ex)
    {
        TC_LOG_FATAL("server.ipc", "Could not bind to WorldserverListenPort %u. Exception: %s. Shutting down bnetserver.", _worldListenPort, ex.what());
        abort();
    }

    _poller->add(*_worldSocket);
    TC_LOG_INFO("server.ipc", "Listening on connections from worldservers on port %u...", _worldListenPort);
}

void WorldListener::HandleClose()
{
    _worldSocket->close();
    TC_LOG_INFO("server.ipc", "Shutting down connections from worldservers...");
}

void WorldListener::Dispatch(zmqpp::message& msg) const
{
    IPC::BattlenetComm::Header ipcHeader;
    msg >> ipcHeader;

    if (ipcHeader.Ipc.Channel != IPC_CHANNEL_BNET)
        return;

    if (ipcHeader.Ipc.Command < IPC_BNET_MAX_COMMAND)
        (this->*_handlers[ipcHeader.Ipc.Command].Handler)(ipcHeader.Realm, msg);
}

void WorldListener::HandleToonOnlineStatusChange(Battlenet::RealmHandle const& realm, zmqpp::message& msg) const
{
    IPC::BattlenetComm::ToonHandle toonHandle;
    bool online;
    msg >> toonHandle;
    msg >> online;

    if (Battlenet::Session* session = sSessionMgr.GetSession(toonHandle.AccountId, toonHandle.GameAccountId))
    {
        if (online)
        {
            if (!session->IsToonOnline())
            {
                Battlenet::WoWRealm::ToonReady* toonReady = new Battlenet::WoWRealm::ToonReady();
                toonReady->Realm = realm;
                toonReady->Guid = toonHandle.Guid;
                toonReady->Name = toonHandle.Name;
                session->SetToonOnline(true);
                session->AsyncWrite(toonReady);
            }
        }
        else if (session->IsToonOnline())
        {
            session->AsyncWrite(new Battlenet::WoWRealm::ToonLoggedOut());
            session->SetToonOnline(false);
        }
    }
}
