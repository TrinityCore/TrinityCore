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
    // We only support guilds for now.
    if (request->type().name() == "guild")
    {
        response->mutable_type()->set_name("guild");
        response->mutable_type()->set_program(5730135);

        return ERROR_OK;
    }

    return ERROR_NOT_IMPLEMENTED;
}

uint32 Battlenet::ClubService::HandleSubscribe(club::v1::SubscribeRequest const* /*request*/, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    // Subscibe the client to it's own guild club.
    ::bgs::protocol::club::v1::SubscribeNotification subscribeNotification;

    uint32 bnetStatus = guild->HandleClubSubscribe(&subscribeNotification, _session);

    if (bnetStatus != ERROR_OK)
        return bnetStatus;

    WorldserverService<club::v1::ClubListener>(_session).OnSubscribe(&subscribeNotification, true, true);

    // Notify the client about the changed club state.
    ::bgs::protocol::club::v1::SubscriberStateChangedNotification subscriberStateChangedNotification;

    bnetStatus = guild->HandleClubSubscriberStateChanged(&subscriberStateChangedNotification, _session);

    if (bnetStatus != ERROR_OK)
        return bnetStatus;

    WorldserverService<club::v1::ClubListener>(_session).OnSubscriberStateChanged(&subscriberStateChangedNotification, true, true);

    return bnetStatus;
}

uint32 Battlenet::ClubService::HandleGetMembers(club::v1::GetMembersRequest const* /*request*/, club::v1::GetMembersResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    return guild->HandleGetMembers(response);
}

uint32 Battlenet::ClubService::HandleGetStreams(club::v1::GetStreamsRequest const* /*request*/, club::v1::GetStreamsResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    return guild->HandleClubStreams(response, _session);
}

uint32 Battlenet::ClubService::HandleSubscribeStream(club::v1::SubscribeStreamRequest const* request, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    // Basic sanity check until full communities are implemented.
    // 1 - Guild, 2 - Officer chat stream.
    if (request->stream_id().Get(0) != (uint64)ClubStreamType::Guild && request->stream_id().Get(0) != (uint64)ClubStreamType::Officer)
        return ERROR_CLUB_STREAM_NO_STREAM;

    return ERROR_OK;
}

uint32 Battlenet::ClubService::HandleUnsubscribeStream(club::v1::UnsubscribeStreamRequest const* /*request*/, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    // We just have to signal the client that the unsubscribe request came through.
    return ERROR_OK;
}

uint32 Battlenet::ClubService::HandleSetStreamFocus(club::v1::SetStreamFocusRequest const* /*request*/, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NOT_MEMBER;

    return ERROR_OK;
}

uint32 Battlenet::ClubService::HandleAdvanceStreamViewTime(club::v1::AdvanceStreamViewTimeRequest const* /*request*/, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NOT_MEMBER;

    return ERROR_OK;
}

uint32 Battlenet::Services::ClubService::HandleCreateMessage(club::v1::CreateMessageRequest const* request, club::v1::CreateMessageResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    // Basic sanity check until full communities are implemented.
    // 1 - Guild, 2 - Officer chat stream.
    if (request->stream_id() != (uint64)ClubStreamType::Guild && request->stream_id() != (uint64)ClubStreamType::Officer)
        return ERROR_CLUB_STREAM_NO_STREAM;

    // Just some sanity checks. We do not care about the requested stream for now since we only have two.
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    switch ((ClubStreamType)request->stream_id())
    {
        case ClubStreamType::Guild:
            _session->HandleChatMessage(CHAT_MSG_GUILD, LANG_UNIVERSAL, request->options().content(), response);
            break;
        case ClubStreamType::Officer:
            _session->HandleChatMessage(CHAT_MSG_OFFICER, LANG_UNIVERSAL, request->options().content(), response);
            break;
        default:
            return ERROR_CLUB_STREAM_NO_STREAM;
    }

    if (response->has_message())
        return ERROR_OK;

    // If the message is empty there should never be a response to message request.
    continuation = nullptr;

    return ERROR_CLUB_STREAM_NO_SUCH_MESSAGE;
}
