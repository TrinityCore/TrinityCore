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

#include "ClubMembershipService.h"
#include "BattlenetRpcErrorCodes.h"
#include "CharacterCache.h"
#include "ClubService.h"
#include "ClubUtils.h"
#include "Guild.h"
#include "Player.h"

namespace Battlenet::Services
{
ClubMembershipService::ClubMembershipService(WorldSession* session) : BaseService(session) { }

uint32 ClubMembershipService::HandleSubscribe(club_membership::v1::client::SubscribeRequest const* /*request*/, club_membership::v1::client::SubscribeResponse* response,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    Player const* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild const* guild = player->GetGuild();

    if (!guild)
        return ERROR_OK;

    club_membership::v1::client::ClubMembershipDescription* description = response->mutable_state()->add_description();
    description->set_allocated_member_id(CreateClubMemberId(player->GetGUID()).release());

    club::v1::ClubDescription* club = description->mutable_club();
    club->set_id(guild->GetId());
    club->set_allocated_type(ClubService::CreateGuildClubType().release());
    club->set_name(guild->GetName());
    club->set_privacy_level(club::v1::PrivacyLevel::PRIVACY_LEVEL_OPEN);
    club->set_visibility_level(club::v1::VISIBILITY_LEVEL_PRIVATE);
    club->set_member_count(guild->GetMembersCount());
    club->set_creation_time(
        std::chrono::duration_cast<std::chrono::microseconds>(SystemTimePoint::clock::from_time_t(guild->GetCreatedDate()).time_since_epoch()).count());

    // Not setting these can cause issues.
    club->set_timezone("");
    club->set_locale("");

    club::v1::client::MemberDescription* leader = club->add_leader();

    leader->set_allocated_id(CreateClubMemberId(guild->GetLeaderGUID()).release());

    response->mutable_state()->mutable_mention_view()->set_last_read_time(0);
    response->mutable_state()->mutable_mention_view()->set_last_message_time(0);

    return ERROR_OK;
}

uint32 ClubMembershipService::HandleUnsubscribe(club_membership::v1::client::UnsubscribeRequest const* /*request*/, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& /*continuation*/)
{
    // We just have to signal the client that the unsubscribe request came through.
    return ERROR_OK;
}

std::unique_ptr<club::v1::MemberId> ClubMembershipService::CreateClubMemberId(ObjectGuid guid)
{
    std::unique_ptr<club::v1::MemberId> id = std::make_unique<club::v1::MemberId>();
    id->set_account_id(sCharacterCache->GetCharacterAccountIdByGuid(guid));
    id->set_unique_id(Clubs::CreateClubMemberId(guid));
    return id;
}
}
