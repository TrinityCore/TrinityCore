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

#include "CharacterCache.h"
#include "WorldSession.h"
#include "Guild.h"
#include "GuildFinderMgr.h"
#include "GuildFinderPackets.h"
#include "GuildMgr.h"
#include "Object.h"
#include "Player.h"
#include "SharedDefines.h"
#include "World.h"
#include "WorldPacket.h"

void WorldSession::HandleGuildFinderAddRecruit(WorldPackets::GuildFinder::LFGuildAddRecruit& lfGuildAddRecruit)
{
    if (sGuildFinderMgr->CountRequestsFromPlayer(GetPlayer()->GetGUID()) >= 10)
        return;

    if (!lfGuildAddRecruit.GuildGUID.IsGuild())
        return;
    if (!(lfGuildAddRecruit.ClassRoles & GUILDFINDER_ALL_ROLES) || lfGuildAddRecruit.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(lfGuildAddRecruit.Availability & AVAILABILITY_ALWAYS) || lfGuildAddRecruit.Availability > AVAILABILITY_ALWAYS)
        return;
    if (!(lfGuildAddRecruit.PlayStyle & ALL_INTERESTS) || lfGuildAddRecruit.PlayStyle > ALL_INTERESTS)
        return;

    MembershipRequest request = MembershipRequest(GetPlayer()->GetGUID(), lfGuildAddRecruit.GuildGUID, lfGuildAddRecruit.Availability,
        lfGuildAddRecruit.ClassRoles, lfGuildAddRecruit.PlayStyle, lfGuildAddRecruit.Comment, time(nullptr));
    sGuildFinderMgr->AddMembershipRequest(lfGuildAddRecruit.GuildGUID, request);
}

void WorldSession::HandleGuildFinderBrowse(WorldPackets::GuildFinder::LFGuildBrowse& lfGuildBrowse)
{
    if (!(lfGuildBrowse.ClassRoles & GUILDFINDER_ALL_ROLES) || lfGuildBrowse.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(lfGuildBrowse.Availability & AVAILABILITY_ALWAYS) || lfGuildBrowse.Availability > AVAILABILITY_ALWAYS)
        return;
    if (!(lfGuildBrowse.PlayStyle & ALL_INTERESTS) || lfGuildBrowse.PlayStyle > ALL_INTERESTS)
        return;
    if (lfGuildBrowse.CharacterLevel > int32(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)) || lfGuildBrowse.CharacterLevel < 1)
        return;

    Player* player = GetPlayer();

    LFGuildPlayer settings(player->GetGUID(), lfGuildBrowse.ClassRoles, lfGuildBrowse.Availability, lfGuildBrowse.PlayStyle, ANY_FINDER_LEVEL);
    std::vector<LFGuildSettings const*> guildList = sGuildFinderMgr->GetGuildsMatchingSetting(settings, player->GetTeamId());

    WorldPackets::GuildFinder::LFGuildBrowseResult lfGuildBrowseResult;
    lfGuildBrowseResult.Post.resize(guildList.size());

    for (std::size_t i = 0; i < guildList.size(); ++i)
    {
        LFGuildSettings const* guildSettings = guildList[i];
        WorldPackets::GuildFinder::LFGuildBrowseData& guildData = lfGuildBrowseResult.Post[i];
        Guild* guild = ASSERT_NOTNULL(sGuildMgr->GetGuildByGuid(guildSettings->GetGUID()));

        guildData.GuildName = guild->GetName();
        guildData.GuildGUID = guild->GetGUID();
        guildData.GuildVirtualRealm = GetVirtualRealmAddress();
        guildData.GuildMembers = guild->GetMembersCount();
        guildData.GuildAchievementPoints = guild->GetAchievementMgr().GetAchievementPoints();
        guildData.PlayStyle = guildSettings->GetInterests();
        guildData.Availability = guildSettings->GetAvailability();
        guildData.ClassRoles = guildSettings->GetClassRoles();
        guildData.LevelRange = guildSettings->GetLevel();
        guildData.EmblemStyle = guild->GetEmblemInfo().GetStyle();
        guildData.EmblemColor = guild->GetEmblemInfo().GetColor();
        guildData.BorderStyle = guild->GetEmblemInfo().GetBorderStyle();
        guildData.BorderColor = guild->GetEmblemInfo().GetBorderColor();
        guildData.Background = guild->GetEmblemInfo().GetBackgroundColor();
        guildData.Comment = guildSettings->GetComment();
        guildData.Cached = 0;
        guildData.MembershipRequested = sGuildFinderMgr->HasRequest(player->GetGUID(), guild->GetGUID());
    }

    player->SendDirectMessage(lfGuildBrowseResult.Write());
}

void WorldSession::HandleGuildFinderDeclineRecruit(WorldPackets::GuildFinder::LFGuildDeclineRecruit& lfGuildDeclineRecruit)
{
    if (!GetPlayer()->GetGuild())
        return;

    if (!lfGuildDeclineRecruit.RecruitGUID.IsPlayer())
        return;

    sGuildFinderMgr->RemoveMembershipRequest(lfGuildDeclineRecruit.RecruitGUID, GetPlayer()->GetGuild()->GetGUID());
}

void WorldSession::HandleGuildFinderGetApplications(WorldPackets::GuildFinder::LFGuildGetApplications& /*lfGuildGetApplications*/)
{
    std::vector<MembershipRequest const*> applicatedGuilds = sGuildFinderMgr->GetAllMembershipRequestsForPlayer(GetPlayer()->GetGUID());
    WorldPackets::GuildFinder::LFGuildApplications lfGuildApplications;
    lfGuildApplications.Application.resize(applicatedGuilds.size());
    lfGuildApplications.NumRemaining = 10 - sGuildFinderMgr->CountRequestsFromPlayer(GetPlayer()->GetGUID());

    for (std::size_t i = 0; i < applicatedGuilds.size(); ++i)
    {
        MembershipRequest const* application = applicatedGuilds[i];
        WorldPackets::GuildFinder::LFGuildApplicationData& applicationData = lfGuildApplications.Application[i];

        Guild* guild = ASSERT_NOTNULL(sGuildMgr->GetGuildByGuid(application->GetGuildGuid()));
        LFGuildSettings const& guildSettings = sGuildFinderMgr->GetGuildSettings(application->GetGuildGuid());

        applicationData.GuildGUID = application->GetGuildGuid();
        applicationData.GuildVirtualRealm = GetVirtualRealmAddress();
        applicationData.GuildName = guild->GetName();
        applicationData.ClassRoles = guildSettings.GetClassRoles();
        applicationData.PlayStyle = guildSettings.GetInterests();
        applicationData.Availability = guildSettings.GetAvailability();
        applicationData.SecondsSinceCreated = time(nullptr) - application->GetSubmitTime();
        applicationData.SecondsUntilExpiration = application->GetExpiryTime() - time(nullptr);
        applicationData.Comment = application->GetComment();
    }

    GetPlayer()->SendDirectMessage(lfGuildApplications.Write());
}

void WorldSession::HandleGuildFinderGetGuildPost(WorldPackets::GuildFinder::LFGuildGetGuildPost& /*lfGuildGetGuildPost*/)
{
    Player* player = GetPlayer();

    Guild* guild = player->GetGuild();
    if (!guild) // Player must be in guild
        return;

    WorldPackets::GuildFinder::LFGuildPost lfGuildPost;
    if (guild->GetLeaderGUID() == player->GetGUID())
    {
        LFGuildSettings const& settings = sGuildFinderMgr->GetGuildSettings(guild->GetGUID());
        lfGuildPost.Post = boost::in_place();
        lfGuildPost.Post->Active = settings.IsListed();
        lfGuildPost.Post->PlayStyle = settings.GetInterests();
        lfGuildPost.Post->Availability = settings.GetAvailability();
        lfGuildPost.Post->ClassRoles = settings.GetClassRoles();
        lfGuildPost.Post->LevelRange = settings.GetLevel();
        lfGuildPost.Post->Comment = settings.GetComment();
    }

    player->SendDirectMessage(lfGuildPost.Write());
}

// Lists all recruits for a guild - Misses times
void WorldSession::HandleGuildFinderGetRecruits(WorldPackets::GuildFinder::LFGuildGetRecruits& /*lfGuildGetRecruits*/)
{
    Player* player = GetPlayer();
    Guild* guild = player->GetGuild();
    if (!guild)
        return;

    time_t now = time(nullptr);
    WorldPackets::GuildFinder::LFGuildRecruits lfGuildRecruits;
    lfGuildRecruits.UpdateTime = now;
    if (std::unordered_map<ObjectGuid, MembershipRequest> const* recruitsList = sGuildFinderMgr->GetAllMembershipRequestsForGuild(guild->GetGUID()))
    {
        lfGuildRecruits.Recruits.resize(recruitsList->size());
        std::size_t i = 0;
        for (auto const& recruitRequestPair : *recruitsList)
        {
            WorldPackets::GuildFinder::LFGuildRecruitData& recruitData = lfGuildRecruits.Recruits[i++];
            recruitData.RecruitGUID = recruitRequestPair.first;
            recruitData.RecruitVirtualRealm = GetVirtualRealmAddress();
            recruitData.Comment = recruitRequestPair.second.GetComment();
            recruitData.ClassRoles = recruitRequestPair.second.GetClassRoles();
            recruitData.PlayStyle = recruitRequestPair.second.GetInterests();
            recruitData.Availability = recruitRequestPair.second.GetAvailability();
            recruitData.SecondsSinceCreated = now - recruitRequestPair.second.GetSubmitTime();
            recruitData.SecondsUntilExpiration = recruitRequestPair.second.GetExpiryTime() - now;
            if (CharacterCacheEntry const* charInfo = sCharacterCache->GetCharacterCacheByGuid(recruitRequestPair.first))
            {
                recruitData.Name = charInfo->Name;
                recruitData.CharacterClass = charInfo->Class;
                recruitData.CharacterGender = charInfo->Sex;
                recruitData.CharacterLevel = charInfo->Level;
            }
        }
    }

    player->SendDirectMessage(lfGuildRecruits.Write());
}

void WorldSession::HandleGuildFinderRemoveRecruit(WorldPackets::GuildFinder::LFGuildRemoveRecruit& lfGuildRemoveRecruit)
{
    if (!lfGuildRemoveRecruit.GuildGUID.IsGuild())
        return;

    sGuildFinderMgr->RemoveMembershipRequest(GetPlayer()->GetGUID(), lfGuildRemoveRecruit.GuildGUID);
}

// Sent any time a guild master sets an option in the interface and when listing / unlisting his guild
void WorldSession::HandleGuildFinderSetGuildPost(WorldPackets::GuildFinder::LFGuildSetGuildPost& lfGuildSetGuildPost)
{
    // Level sent is zero if untouched, force to any (from interface). Idk why
    if (!lfGuildSetGuildPost.LevelRange)
        lfGuildSetGuildPost.LevelRange = ANY_FINDER_LEVEL;

    if (!(lfGuildSetGuildPost.ClassRoles & GUILDFINDER_ALL_ROLES) || lfGuildSetGuildPost.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(lfGuildSetGuildPost.Availability & AVAILABILITY_ALWAYS) || lfGuildSetGuildPost.Availability > AVAILABILITY_ALWAYS)
        return;
    if (!(lfGuildSetGuildPost.PlayStyle & ALL_INTERESTS) || lfGuildSetGuildPost.PlayStyle > ALL_INTERESTS)
        return;
    if (!(lfGuildSetGuildPost.LevelRange & ALL_GUILDFINDER_LEVELS) || lfGuildSetGuildPost.LevelRange > ALL_GUILDFINDER_LEVELS)
        return;

    Player* player = GetPlayer();

    if (!player->GetGuildId()) // Player must be in guild
        return;

    Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId());
    if (!guild)
        return;

    // Player must be guild master
    if (guild->GetLeaderGUID() != player->GetGUID())
        return;

    LFGuildSettings settings(lfGuildSetGuildPost.Active, player->GetTeamId(), guild->GetGUID(), lfGuildSetGuildPost.ClassRoles,
        lfGuildSetGuildPost.Availability, lfGuildSetGuildPost.PlayStyle, lfGuildSetGuildPost.LevelRange, lfGuildSetGuildPost.Comment);
    sGuildFinderMgr->SetGuildSettings(guild->GetGUID(), settings);
}
