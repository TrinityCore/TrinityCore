/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ConnectionService.h"
#include "Duration.h"
#include "Log.h"
#include "Session.h"
#include "Util.h"
#include "BattlenetRpcErrorCodes.h"

Battlenet::Services::Connection::Connection(Session* session) : ConnectionService(session)
{
}

uint32 Battlenet::Services::Connection::HandleConnect(connection::v1::ConnectRequest const* request, connection::v1::ConnectResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    if (request->has_client_id())
        response->mutable_client_id()->CopyFrom(request->client_id());

    std::chrono::system_clock::duration now = std::chrono::system_clock::now().time_since_epoch();

    response->mutable_server_id()->set_label(GetPID());
    response->mutable_server_id()->set_epoch(std::chrono::duration_cast<Seconds>(now).count());
    response->set_server_time(std::chrono::duration_cast<Milliseconds>(now).count());

    response->set_use_bindless_rpc(request->use_bindless_rpc());
    return ERROR_OK;
}

uint32 Battlenet::Services::Connection::HandleKeepAlive(NoData const* /*request*/)
{
    return ERROR_OK;
}

uint32 Battlenet::Services::Connection::HandleRequestDisconnect(connection::v1::DisconnectRequest const* request)
{
    connection::v1::DisconnectNotification disconnectNotification;
    disconnectNotification.set_error_code(request->error_code());
    ForceDisconnect(&disconnectNotification);

    _session->DelayedCloseSocket();
    return ERROR_OK;
}
