/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "AccountService.h"
#include "Session.h"

Battlenet::Services::Account::Account(Session* session) : AccountService(session)
{
}

uint32 Battlenet::Services::Account::HandleGetAccountState(account::v1::GetAccountStateRequest const* request, account::v1::GetAccountStateResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    return _session->HandleGetAccountState(request, response);
}

uint32 Battlenet::Services::Account::HandleGetGameAccountState(account::v1::GetGameAccountStateRequest const* request, account::v1::GetGameAccountStateResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    return _session->HandleGetGameAccountState(request, response);
}
