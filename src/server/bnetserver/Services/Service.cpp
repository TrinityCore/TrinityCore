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

#include "Service.h"
#include "Session.h"

void Battlenet::ServiceBaseCaller::SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)>&& callback)
{
    _session->SendRequest(serviceHash, methodId, request, std::move(callback));
}

void Battlenet::ServiceBaseCaller::SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request)
{
    _session->SendRequest(serviceHash, methodId, request);
}

void Battlenet::ServiceBaseCaller::SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, uint32 status)
{
    _session->SendResponse(token, status);
}

void Battlenet::ServiceBaseCaller::SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, google::protobuf::Message const* response)
{
    _session->SendResponse(token, response);
}

std::string Battlenet::ServiceBaseCaller::GetCallerInfo() const
{
    return _session->GetClientInfo();
}
