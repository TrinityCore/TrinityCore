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
#include "ClubMembershipService.h"
#include "GameTime.h"
#include "Guild.h"
#include "Player.h"
#include "SocialMgr.h"
#include "club_listener.pb.h"

namespace Battlenet::Services
{
ClubService::ClubService(WorldSession* session) : BaseService(session) { }

uint32 ClubService::HandleGetClubType(club::v1::GetClubTypeRequest const* request, club::v1::GetClubTypeResponse* response,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    // We only support guilds for now.
    if (request->type().name() == "guild")
    {
        response->set_allocated_type(CreateGuildClubType().release());
        return ERROR_OK;
    }

    return ERROR_NOT_IMPLEMENTED;
}

uint32 ClubService::HandleSubscribe(club::v1::SubscribeRequest const* /*request*/, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    // Subscibe the client to it's own guild club.
    club::v1::SubscribeNotification subscribeNotification;

    Guild::Member const* guildMember = guild->GetMember(player->GetGUID());

    if (!guildMember)
        return ERROR_CLUB_NOT_MEMBER;

    Guild::Member const* guildLeader = guild->GetMember(guild->GetLeaderGUID());

    if (!guildLeader)
        return ERROR_CLUB_NO_SUCH_MEMBER;

    subscribeNotification.set_club_id(guild->GetId());
    subscribeNotification.set_allocated_agent_id(ClubMembershipService::CreateClubMemberId(player->GetGUID()).release());

    club::v1::Club* guildClub = subscribeNotification.mutable_club();

    guildClub->set_id(guild->GetId());
    guildClub->set_allocated_type(CreateGuildClubType().release());
    guildClub->set_name(guild->GetName());

    // These are not related to normal guild functionality so we hardcode them for now.
    guildClub->set_privacy_level(club::v1::PrivacyLevel::PRIVACY_LEVEL_OPEN);
    guildClub->set_visibility_level(club::v1::VISIBILITY_LEVEL_PRIVATE);

    guildClub->set_member_count(guild->GetMembersCount());

    // Set the club leader, guild master in this case.
    club::v1::MemberDescription* guildLeaderDescription = guildClub->add_leader();

    guildLeaderDescription->mutable_id()->mutable_account_id()->set_id(guildLeader->GetAccountId());
    guildLeaderDescription->mutable_id()->set_unique_id(guildLeader->GetGUID().GetCounter());

    club::v1::Member* subscriber = subscribeNotification.mutable_member();

    // The member sending the notification data.
    subscriber->set_allocated_id(ClubMembershipService::CreateClubMemberId(player->GetGUID()).release());

    // Community/Club default roles have slightly different values.
    // Also this is required to set the current leader/guild master symbol in the interface.
    // 1 = Owner, 4 = Member. Once communities are fully implemented these will go into a new database table.
    if (guildMember->IsRank(GuildRankId::GuildMaster))
        subscriber->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
    else if (guild->HasAnyRankRight(guildMember->GetRankId(), GuildRankRights(GR_RIGHT_OFFCHATLISTEN | GR_RIGHT_OFFCHATSPEAK)))
        subscriber->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));
    else
        subscriber->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));

    subscriber->set_presence_level(club::v1::PRESENCE_LEVEL_RICH);
    subscriber->set_whisper_level(club::v1::WHISPER_LEVEL_OPEN);

    // Member is online and active.
    subscriber->set_active(true);

    WorldserverService<club::v1::ClubListener>(_session).OnSubscribe(&subscribeNotification, true, true);

    // Notify the client about the changed club state.
    club::v1::SubscriberStateChangedNotification subscriberStateChangedNotification;

    subscriberStateChangedNotification.set_club_id(guild->GetId());

    club::v1::SubscriberStateAssignment* assignment = subscriberStateChangedNotification.add_assignment();

    assignment->set_allocated_member_id(ClubMembershipService::CreateClubMemberId(player->GetGUID()).release());

    // Member is online and active.
    assignment->set_active(true);

    WorldserverService<club::v1::ClubListener>(_session).OnSubscriberStateChanged(&subscriberStateChangedNotification, true, true);

    return ERROR_OK;
}

uint32 ClubService::HandleGetMembers(club::v1::GetMembersRequest const* /*request*/, club::v1::GetMembersResponse* response,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    response->mutable_member()->Reserve(guild->GetMembersCount());

    for (auto const& [guid, member] : guild->GetMembers())
    {
        club::v1::Member* clubMember = response->add_member();

        clubMember->set_allocated_id(ClubMembershipService::CreateClubMemberId(guid).release());

        // Community/Club default roles have slightly different values.
        // When communities are implemented those are going to be database fields.
        if (member.IsRank(GuildRankId::GuildMaster))
            clubMember->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
        else if (guild->HasAnyRankRight(member.GetRankId(), GuildRankRights(GR_RIGHT_OFFCHATLISTEN | GR_RIGHT_OFFCHATSPEAK)))
            clubMember->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));
        else
            clubMember->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));

        clubMember->set_presence_level(club::v1::PresenceLevel::PRESENCE_LEVEL_RICH);
        clubMember->set_whisper_level(club::v1::WhisperLevel::WHISPER_LEVEL_OPEN);
        clubMember->set_note(member.GetPublicNote());
        clubMember->set_active(member.IsOnline());
    }

    return ERROR_OK;
}

uint32 ClubService::HandleGetStreams(club::v1::GetStreamsRequest const* /*request*/, club::v1::GetStreamsResponse* response,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    // General guild channel.
    club::v1::Stream* generalGuildChannelStream = response->add_stream();

    generalGuildChannelStream->set_club_id(guild->GetId());
    generalGuildChannelStream->set_id(AsUnderlyingType(ClubStreamType::Guild));

    v2::Attribute* generalStreamAttribute = generalGuildChannelStream->add_attribute();

    generalStreamAttribute->set_name("global_strings_tag");
    generalStreamAttribute->mutable_value()->set_string_value("COMMUNITIES_GUILD_GENERAL_CHANNEL_NAME");

    generalGuildChannelStream->set_name("Guild");

    // All roles got access to this channel.
    // Club roles are currently guild role + 1.
    // With a complete club/community system those will be handled differently.
    generalGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
    generalGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Leader));
    generalGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));
    generalGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));

    // No voice support.
    generalGuildChannelStream->set_voice_level(club::v1::StreamVoiceLevel::VOICE_LEVEL_DISABLED);

    // Officer guild channel.
    club::v1::Stream* officerGuildChannelStream = response->add_stream();

    officerGuildChannelStream->set_club_id(guild->GetId());
    officerGuildChannelStream->set_id(AsUnderlyingType(ClubStreamType::Officer));

    v2::Attribute* officerStreamAttribute = officerGuildChannelStream->add_attribute();

    officerStreamAttribute->set_name("global_strings_tag");
    officerStreamAttribute->mutable_value()->set_string_value("COMMUNITIES_GUILD_OFFICER_CHANNEL_NAME");

    officerGuildChannelStream->set_name("Officer");

    // All roles got access to this channel.
    // Club roles are currently guild role + 1.
    // With a complete club/community system those will be handled differently.
    officerGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
    officerGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Leader));
    officerGuildChannelStream->mutable_access()->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));

    // No voice support.
    officerGuildChannelStream->set_voice_level(club::v1::StreamVoiceLevel::VOICE_LEVEL_DISABLED);

    // Enable channel view
    club::v1::StreamView* generalView = response->add_view();

    generalView->set_club_id(guild->GetId());
    generalView->set_stream_id(AsUnderlyingType(ClubStreamType::Guild));

    club::v1::StreamView* officerView = response->add_view();

    officerView->set_club_id(guild->GetId());
    officerView->set_stream_id(AsUnderlyingType(ClubStreamType::Officer));

    return ERROR_OK;
}

uint32 ClubService::HandleSubscribeStream(club::v1::SubscribeStreamRequest const* request, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    // Basic sanity check until full communities are implemented.
    // 1 - Guild, 2 - Officer chat stream.
    if (request->stream_id().empty() || (request->stream_id().Get(0) != AsUnderlyingType(ClubStreamType::Guild) && request->stream_id().Get(0) != AsUnderlyingType(ClubStreamType::Officer)))
        return ERROR_CLUB_STREAM_NO_STREAM;

    return ERROR_OK;
}

uint32 ClubService::HandleUnsubscribeStream(club::v1::UnsubscribeStreamRequest const* /*request*/, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    // We just have to signal the client that the unsubscribe request came through.
    return ERROR_OK;
}

uint32 ClubService::HandleSetStreamFocus(club::v1::SetStreamFocusRequest const* /*request*/, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NOT_MEMBER;

    return ERROR_OK;
}

uint32 ClubService::HandleAdvanceStreamViewTime(club::v1::AdvanceStreamViewTimeRequest const* /*request*/, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NOT_MEMBER;

    return ERROR_OK;
}

uint32 ClubService::HandleCreateMessage(club::v1::CreateMessageRequest const* request, club::v1::CreateMessageResponse* response,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    // Basic sanity check until full communities are implemented.
    // 1 - Guild, 2 - Officer chat stream.
    if (request->stream_id() != AsUnderlyingType(ClubStreamType::Guild) && request->stream_id() != AsUnderlyingType(ClubStreamType::Officer))
        return ERROR_CLUB_STREAM_NO_STREAM;

    // Just some sanity checks. We do not care about the requested stream for now since we only have two.
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_CLUB_NO_CLUB;

    GuildRankRights requiredRights = { };
    ChatMessageResult result = { };

    switch (ClubStreamType(request->stream_id()))
    {
        case ClubStreamType::Guild:
            requiredRights = GR_RIGHT_GCHATLISTEN;
            result = _session->HandleChatMessage(CHAT_MSG_GUILD, LANG_UNIVERSAL, request->options().content());
            break;
        case ClubStreamType::Officer:
            requiredRights = GR_RIGHT_OFFCHATLISTEN;
            result = _session->HandleChatMessage(CHAT_MSG_OFFICER, LANG_UNIVERSAL, request->options().content());
            break;
        default:
            return ERROR_CLUB_STREAM_NO_STREAM;
    }

    if (result == ChatMessageResult::Ok)
    {
        std::chrono::microseconds messageTime = std::chrono::duration_cast<std::chrono::microseconds>(GameTime::GetSystemTime().time_since_epoch());

        FillStreamMessage(response->mutable_message(), request->options().content(), messageTime, player->GetGUID());

        club::v1::StreamMessageAddedNotification messageAddedNotification;
        messageAddedNotification.set_allocated_agent_id(ClubMembershipService::CreateClubMemberId(player->GetGUID()).release());
        messageAddedNotification.set_club_id(guild->GetId());
        messageAddedNotification.set_stream_id(request->stream_id());
        FillStreamMessage(messageAddedNotification.mutable_message(), request->options().content(), messageTime, player->GetGUID());

        guild->BroadcastWorker([&](Player const* receiver)
        {
            Guild::Member const* receiverMember = guild->GetMember(receiver->GetGUID());
            if (!guild->HasAnyRankRight(receiverMember->GetRankId(), requiredRights))
                return;

            if (receiver->GetSocial()->HasIgnore(player->GetGUID(), _session->GetAccountGUID()))
                return;

            WorldserverService<club::v1::ClubListener>(receiver->GetSession()).OnStreamMessageAdded(&messageAddedNotification, true, true);
        }, player);

        return ERROR_OK;
    }

    // If the message is empty there should never be a response to message request.
    continuation = nullptr;

    return ERROR_CLUB_STREAM_NO_SUCH_MESSAGE;
}

std::unique_ptr<club::v1::UniqueClubType> ClubService::CreateGuildClubType()
{
    std::unique_ptr<club::v1::UniqueClubType> type = std::make_unique<club::v1::UniqueClubType>();
    type->set_program(5730135);
    type->set_name("guild");
    return type;
}

void ClubService::FillStreamMessage(club::v1::StreamMessage* message, std::string_view msg, std::chrono::microseconds messageTime, ObjectGuid author)
{
    message->mutable_id()->set_epoch(messageTime.count());
    message->mutable_id()->set_position(0);

    message->mutable_author()->set_allocated_id(ClubMembershipService::CreateClubMemberId(author).release());

    club::v1::ContentChain* contentChain = message->add_content_chain();

    contentChain->set_content(msg.data(), msg.size());
    contentChain->set_edit_time(messageTime.count());
}
}
