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

#include "ClubService.h"
#include "BattlenetRpcErrorCodes.h"
#include "Guild.h"


Battlenet::Services::ClubService::ClubService(WorldSession* session) : BaseService(session) { }

uint32 Battlenet::Services::ClubService::HandleGetClubType(club::v1::GetClubTypeRequest const* request, club::v1::GetClubTypeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleSubscribe(club::v1::SubscribeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleGetMembers(club::v1::GetMembersRequest const* request, club::v1::GetMembersResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleGetStreams(club::v1::GetStreamsRequest const* request, club::v1::GetStreamsResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleSubscribeStream(club::v1::SubscribeStreamRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleUnsubscribeStream(club::v1::UnsubscribeStreamRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleSetStreamFocus(club::v1::SetStreamFocusRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleAdvanceStreamViewTime(club::v1::AdvanceStreamViewTimeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::Services::ClubService::HandleCreateMessage(club::v1::CreateMessageRequest const* request, club::v1::CreateMessageResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return ERROR_RPC_NOT_IMPLEMENTED;
}
