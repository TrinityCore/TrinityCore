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

#include "WorldSession.h"
#include "BattlenetPackets.h"
#include "WorldserverServiceDispatcher.h"
#include "ObjectDefines.h"

void WorldSession::HandleBattlenetChangeRealmTicket(WorldPackets::Battlenet::ChangeRealmTicket& changeRealmTicket)
{
    SetRealmListSecret(changeRealmTicket.Secret);

    WorldPackets::Battlenet::ChangeRealmTicketResponse realmListTicket;
    realmListTicket.Token = changeRealmTicket.Token;
    realmListTicket.Allow = true;
    realmListTicket.Ticket << "WorldserverRealmListTicket";

    SendPacket(realmListTicket.Write());
}

void WorldSession::HandleBattlenetRequest(WorldPackets::Battlenet::Request& request)
{
    sServiceDispatcher.Dispatch(this, request.Method.GetServiceHash(), request.Method.Token, request.Method.GetMethodId(), std::move(request.Data));
}

void WorldSession::SendBattlenetResponse(uint32 serviceHash, uint32 methodId, uint32 token, pb::Message const* response)
{
    WorldPackets::Battlenet::Response bnetResponse;
    bnetResponse.BnetStatus = ERROR_OK;
    bnetResponse.Method.Type = MAKE_PAIR64(methodId, serviceHash);
    bnetResponse.Method.ObjectId = 1;
    bnetResponse.Method.Token = token;

    if (response->ByteSize())
    {
        bnetResponse.Data.resize(response->ByteSize());
        response->SerializePartialToArray(bnetResponse.Data.contents(), response->ByteSize());
    }

    SendPacket(bnetResponse.Write());
}

void WorldSession::SendBattlenetResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status)
{
    WorldPackets::Battlenet::Response bnetResponse;
    bnetResponse.BnetStatus = BattlenetRpcErrorCode(status);
    bnetResponse.Method.Type = MAKE_PAIR64(methodId, serviceHash);
    bnetResponse.Method.ObjectId = 1;
    bnetResponse.Method.Token = token;

    SendPacket(bnetResponse.Write());
}

void WorldSession::SendBattlenetRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request, std::function<void(MessageBuffer)> callback)
{
    _battlenetResponseCallbacks[_battlenetRequestToken] = std::move(callback);
    SendBattlenetRequest(serviceHash, methodId, request);
}

void WorldSession::SendBattlenetRequest(uint32 serviceHash, uint32 methodId, pb::Message const* request)
{
    WorldPackets::Battlenet::Notification notification;
    notification.Method.Type = MAKE_PAIR64(methodId, serviceHash);
    notification.Method.ObjectId = 1;
    notification.Method.Token = _battlenetRequestToken++;

    if (request->ByteSize())
    {
        notification.Data.resize(request->ByteSize());
        request->SerializePartialToArray(notification.Data.contents(), request->ByteSize());
    }

    SendPacket(notification.Write());
}
