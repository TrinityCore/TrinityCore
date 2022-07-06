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

#include "GuildFinderMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "GuildFinderPackets.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "World.h"

MembershipRequest::MembershipRequest() : _availability(0), _classRoles(0), _interests(0), _time(GameTime::GetGameTime())
{
}

MembershipRequest::MembershipRequest(ObjectGuid const& playerGUID, ObjectGuid const& guildId, uint32 availability, uint32 classRoles, uint32 interests, std::string comment, time_t submitTime) :
    _comment(std::move(comment)), _guildId(guildId), _playerGUID(playerGUID), _availability(availability), _classRoles(classRoles), _interests(interests), _time(submitTime)
{
}

GuildFinderMgr::GuildFinderMgr()
{
}

GuildFinderMgr::~GuildFinderMgr()
{
}

void GuildFinderMgr::LoadFromDB()
{
    LoadGuildSettings();
    LoadMembershipRequests();
}

void GuildFinderMgr::LoadGuildSettings()
{
    TC_LOG_INFO("server.loading", "Loading guild finder guild-related settings...");
    //                                                           0                1             2                  3             4           5             6         7
    QueryResult result = CharacterDatabase.Query("SELECT gfgs.guildId, gfgs.availability, gfgs.classRoles, gfgs.interests, gfgs.level, gfgs.listed, gfgs.comment, c.race "
                                                 "FROM guild_finder_guild_settings gfgs "
                                                 "LEFT JOIN guild_member gm ON gm.guildid=gfgs.guildId "
                                                 "LEFT JOIN characters c ON c.guid = gm.guid LIMIT 1");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 guild finder guild-related settings. Table `guild_finder_guild_settings` is empty.");
        return;
    }

    uint32 count = 0;
    uint32 oldMSTime = getMSTime();
    do
    {
        Field* fields = result->Fetch();
        ObjectGuid guildId = ObjectGuid::Create<HighGuid::Guild>(fields[0].GetUInt64());
        uint8  availability = fields[1].GetUInt8();
        uint8  classRoles   = fields[2].GetUInt8();
        uint8  interests    = fields[3].GetUInt8();
        uint8  level        = fields[4].GetUInt8();
        bool   listed       = (fields[5].GetUInt8() != 0);
        std::string comment = fields[6].GetString();

        TeamId guildTeam = TEAM_NEUTRAL;
        if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(fields[7].GetUInt8()))
            guildTeam = (TeamId)raceEntry->Alliance;

        LFGuildSettings settings(listed, guildTeam, guildId, classRoles, availability, interests, level, comment);
        _guildSettings[guildId] = settings;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u guild finder guild-related settings in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void GuildFinderMgr::LoadMembershipRequests()
{
    TC_LOG_INFO("server.loading", "Loading guild finder membership requests...");
    //                                                      0         1           2            3           4         5         6
    QueryResult result = CharacterDatabase.Query("SELECT guildId, playerGuid, availability, classRole, interests, comment, submitTime "
                                                 "FROM guild_finder_applicant");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 guild finder membership requests. Table `guild_finder_applicant` is empty.");
        return;
    }

    uint32 count = 0;
    uint32 oldMSTime = getMSTime();
    do
    {
        Field* fields = result->Fetch();
        ObjectGuid guildId = ObjectGuid::Create<HighGuid::Guild>(fields[0].GetUInt64());
        ObjectGuid playerId = ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64());
        uint8  availability = fields[2].GetUInt8();
        uint8  classRoles   = fields[3].GetUInt8();
        uint8  interests    = fields[4].GetUInt8();
        std::string comment = fields[5].GetString();
        time_t submitTime   = fields[6].GetInt64();

        MembershipRequest request(playerId, guildId, availability, classRoles, interests, std::move(comment), submitTime);

        _membershipRequestsByGuild[guildId][playerId] = request;
        _membershipRequestsByPlayer[playerId][guildId] = request;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u guild finder membership requests in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void GuildFinderMgr::AddMembershipRequest(ObjectGuid const& guildGuid, MembershipRequest const& request)
{
    _membershipRequestsByGuild[guildGuid][request.GetPlayerGUID()] = request;
    _membershipRequestsByPlayer[request.GetPlayerGUID()][guildGuid] = request;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GUILD_FINDER_APPLICANT);
    stmt->setUInt64(0, request.GetGuildGuid().GetCounter());
    stmt->setUInt64(1, request.GetPlayerGUID().GetCounter());
    stmt->setUInt8(2, request.GetAvailability());
    stmt->setUInt8(3, request.GetClassRoles());
    stmt->setUInt8(4, request.GetInterests());
    stmt->setString(5, request.GetComment());
    stmt->setInt64(6, request.GetSubmitTime());
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);

    // Notify the applicant his submittion has been added
    if (Player* player = ObjectAccessor::FindPlayer(request.GetPlayerGUID()))
        SendMembershipRequestListUpdate(player);

    // Notify the guild master and officers the list changed
    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildGuid))
        SendApplicantListUpdate(guild);
}

void GuildFinderMgr::RemoveAllMembershipRequestsFromPlayer(ObjectGuid const& playerId)
{
    auto playerItr = _membershipRequestsByPlayer.find(playerId);
    if (playerItr == _membershipRequestsByPlayer.end())
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (auto& guildRequestPair : playerItr->second)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_FINDER_APPLICANT);
        stmt->setUInt64(0, guildRequestPair.first.GetCounter());
        stmt->setUInt64(1, playerId.GetCounter());
        trans->Append(stmt);

        // Notify the guild master and officers the list changed
        if (Guild* guild = sGuildMgr->GetGuildByGuid(guildRequestPair.first))
            SendApplicantListUpdate(guild);

        auto guildItr = _membershipRequestsByGuild.find(guildRequestPair.first);
        if (guildItr == _membershipRequestsByGuild.end())
            continue;

        guildItr->second.erase(playerId);
        if (guildItr->second.empty())
            _membershipRequestsByGuild.erase(guildItr);
    }

    CharacterDatabase.CommitTransaction(trans);

    _membershipRequestsByPlayer.erase(playerItr);
}

void GuildFinderMgr::RemoveMembershipRequest(ObjectGuid const& playerId, ObjectGuid const& guildId)
{
    auto guildItr = _membershipRequestsByGuild.find(guildId);
    if (guildItr != _membershipRequestsByGuild.end())
    {
        guildItr->second.erase(playerId);
        if (guildItr->second.empty())
            _membershipRequestsByGuild.erase(guildItr);
    }

    auto playerItr = _membershipRequestsByPlayer.find(playerId);
    if (playerItr != _membershipRequestsByPlayer.end())
    {
        playerItr->second.erase(guildId);
        if (playerItr->second.empty())
            _membershipRequestsByPlayer.erase(playerItr);
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_FINDER_APPLICANT);
    stmt->setUInt64(0, guildId.GetCounter());
    stmt->setUInt64(1, playerId.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    // Notify the applicant his submittion has been removed
    if (Player* player = ObjectAccessor::FindPlayer(playerId))
        SendMembershipRequestListUpdate(player);

    // Notify the guild master and officers the list changed
    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildId))
        SendApplicantListUpdate(guild);
}

std::vector<MembershipRequest const*> GuildFinderMgr::GetAllMembershipRequestsForPlayer(ObjectGuid const& playerGuid)
{
    std::vector<MembershipRequest const*> resultSet;
    auto playerItr = _membershipRequestsByPlayer.find(playerGuid);
    if (playerItr == _membershipRequestsByPlayer.end())
        return resultSet;

    resultSet.reserve(playerItr->second.size());
    for (auto const& guildRequestPair : playerItr->second)
        resultSet.push_back(&guildRequestPair.second);

    return resultSet;
}

uint8 GuildFinderMgr::CountRequestsFromPlayer(ObjectGuid const& playerId)
{
    auto playerItr = _membershipRequestsByPlayer.find(playerId);
    return playerItr != _membershipRequestsByPlayer.end() ? playerItr->second.size() : 0;
}

std::vector<LFGuildSettings const*> GuildFinderMgr::GetGuildsMatchingSetting(LFGuildPlayer& settings, TeamId faction)
{
    std::vector<LFGuildSettings const*> resultSet;
    for (LFGuildStore::const_iterator itr = _guildSettings.begin(); itr != _guildSettings.end(); ++itr)
    {
        LFGuildSettings const& guildSettings = itr->second;

        if (!guildSettings.IsListed())
            continue;

        if (guildSettings.GetTeam() != faction)
            continue;

        if (!(guildSettings.GetAvailability() & settings.GetAvailability()))
            continue;

        if (!(guildSettings.GetClassRoles() & settings.GetClassRoles()))
            continue;

        if (!(guildSettings.GetInterests() & settings.GetInterests()))
            continue;

        if (!(guildSettings.GetLevel() & settings.GetLevel()))
            continue;

        resultSet.push_back(&itr->second);
    }

    return resultSet;
}

bool GuildFinderMgr::HasRequest(ObjectGuid const& playerId, ObjectGuid const& guildId)
{
    auto guildItr = _membershipRequestsByGuild.find(guildId);
    if (guildItr == _membershipRequestsByGuild.end())
        return false;

    return guildItr->second.count(playerId) > 0;
}

void GuildFinderMgr::SetGuildSettings(ObjectGuid const& guildGuid, LFGuildSettings const& settings)
{
    _guildSettings[guildGuid] = settings;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_GUILD_FINDER_GUILD_SETTINGS);
    stmt->setUInt64(0, settings.GetGUID().GetCounter());
    stmt->setUInt8(1, settings.GetAvailability());
    stmt->setUInt8(2, settings.GetClassRoles());
    stmt->setUInt8(3, settings.GetInterests());
    stmt->setUInt8(4, settings.GetLevel());
    stmt->setUInt8(5, settings.IsListed());
    stmt->setString(6, settings.GetComment());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void GuildFinderMgr::DeleteGuild(ObjectGuid const& guildId)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    auto guildItr = _membershipRequestsByGuild.find(guildId);
    if (guildItr != _membershipRequestsByGuild.end())
    {
        for (auto playerRequestPair : guildItr->second)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_FINDER_APPLICANT);
            stmt->setUInt64(0, guildId.GetCounter());
            stmt->setUInt64(1, playerRequestPair.first.GetCounter());
            trans->Append(stmt);

            auto playerItr = _membershipRequestsByPlayer.find(playerRequestPair.first);
            if (playerItr != _membershipRequestsByPlayer.end())
            {
                playerItr->second.erase(guildId);
                if (playerItr->second.empty())
                    _membershipRequestsByPlayer.erase(playerItr);
            }

            // Notify the applicant his submition has been removed
            if (Player* player = ObjectAccessor::FindPlayer(playerRequestPair.first))
                SendMembershipRequestListUpdate(player);
        }
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_FINDER_GUILD_SETTINGS);
    stmt->setUInt64(0, guildId.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    _membershipRequestsByGuild.erase(guildId);
    _guildSettings.erase(guildId);

    // Notify the guild master the list changed (even if he's not a GM any more, not sure if needed)
    if (Guild* guild = sGuildMgr->GetGuildByGuid(guildId))
        SendApplicantListUpdate(guild);
}

void GuildFinderMgr::SendApplicantListUpdate(Guild* guild)
{
    WorldPackets::GuildFinder::LFGuildApplicantListChanged applicantListChanged;
    guild->BroadcastPacketToRank(applicantListChanged.Write(), GR_OFFICER);
    if (Player* player = ObjectAccessor::FindPlayer(guild->GetLeaderGUID()))
        player->SendDirectMessage(applicantListChanged.GetRawPacket());
}

void GuildFinderMgr::SendMembershipRequestListUpdate(Player* player)
{
    player->SendDirectMessage(WorldPackets::GuildFinder::LFGuildApplicationsListChanged().Write());
}

GuildFinderMgr* GuildFinderMgr::instance()
{
    static GuildFinderMgr instance;
    return &instance;
}
