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

#include "ConnectionService.h"
#include "BattlenetRpcErrorCodes.h"
#include "Session.h"
#include "Timer.h"
#include "Util.h"

namespace Battlenet::Services
{
namespace V1
{
Connection::Connection(Session* session) : ConnectionService(session)
{
}

uint32 Connection::HandleConnect(connection::v1::ConnectRequest const* request, connection::v1::ConnectResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    std::chrono::system_clock::duration now = std::chrono::system_clock::now().time_since_epoch();

    response->mutable_server_id()->set_label(GetPID());
    response->mutable_server_id()->set_epoch(std::chrono::duration_cast<Seconds>(now - Milliseconds(getMSTime())).count());
    if (!request->has_client_id())
    {
        response->mutable_client_id()->set_label(_session->GetSessionId());
        response->mutable_client_id()->set_epoch(std::chrono::duration_cast<Seconds>(_session->GetCreationTime().time_since_epoch()).count());
    }
    else
        response->mutable_client_id()->CopyFrom(request->client_id());

    response->set_server_time(std::chrono::duration_cast<Milliseconds>(now).count());

    response->set_use_bindless_rpc(request->use_bindless_rpc());

    response->set_ciid(Trinity::StringFormat("{:08X}{:08X}-{:08X}{:08X}",
        response->server_id().label(), response->server_id().epoch(),
        response->client_id().label(), response->client_id().epoch()));

    _session->SetClientInstanceId(response->ciid());

    return ERROR_OK;
}

uint32 Connection::HandleKeepAlive(NoData const* /*request*/)
{
    return ERROR_OK;
}

uint32 Connection::HandleRequestDisconnect(connection::v1::DisconnectRequest const* request)
{
    connection::v1::DisconnectNotification disconnectNotification;
    disconnectNotification.set_error_code(request->error_code());
    ForceDisconnect(&disconnectNotification);

    _session->DelayedCloseSocket();
    return ERROR_OK;
}
}
}
