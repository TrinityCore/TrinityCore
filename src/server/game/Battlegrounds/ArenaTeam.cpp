/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "DatabaseEnv.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

ArenaTeam::ArenaTeam()
    : TeamId(0), Type(0), TeamName(), CaptainGuid(), BackgroundColor(0), EmblemStyle(0), EmblemColor(0),
    BorderStyle(0), BorderColor(0)
{
    Stats.WeekGames   = 0;
    Stats.SeasonGames = 0;
    Stats.Rank        = 0;
    Stats.Rating      = sWorld->getIntConfig(CONFIG_ARENA_START_RATING);
    Stats.WeekWins    = 0;
    Stats.SeasonWins  = 0;
}

ArenaTeam::~ArenaTeam()
{ }

bool ArenaTeam::Create(ObjectGuid captainGuid, uint8 type, std::string const& teamName, uint32 backgroundColor, uint8 emblemStyle, uint32 emblemColor, uint8 borderStyle, uint32 borderColor)
{
    // Check if captain is present
    if (!ObjectAccessor::FindPlayer(captainGuid))
        return false;

    // Check if arena team name is already taken
    if (sArenaTeamMgr->GetArenaTeamByName(teamName))
        return false;

    // Generate new arena team id
    TeamId = sArenaTeamMgr->GenerateArenaTeamId();

    // Assign member variables
    CaptainGuid = captainGuid;
    Type = type;
    TeamName = teamName;
    BackgroundColor = backgroundColor;
    EmblemStyle = emblemStyle;
    EmblemColor = emblemColor;
    BorderStyle = borderStyle;
    BorderColor = borderColor;
    ObjectGuid::LowType captainLowGuid = captainGuid.GetCounter();

    // Save arena team to db
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ARENA_TEAM);
    stmt->setUInt32(0, TeamId);
    stmt->setString(1, TeamName);
    stmt->setUInt64(2, captainLowGuid);
    stmt->setUInt8(3, Type);
    stmt->setUInt16(4, Stats.Rating);
    stmt->setUInt32(5, BackgroundColor);
    stmt->setUInt8(6, EmblemStyle);
    stmt->setUInt32(7, EmblemColor);
    stmt->setUInt8(8, BorderStyle);
    stmt->setUInt32(9, BorderColor);
    CharacterDatabase.Execute(stmt);

    // Add captain as member
    AddMember(CaptainGuid);

    TC_LOG_DEBUG("bg.arena", "New ArenaTeam created [Id: %u, Name: %s] [Type: %u] [Captain low GUID: " UI64FMTD "]", GetId(), GetName().c_str(), GetType(), captainLowGuid);
    return true;
}

bool ArenaTeam::AddMember(ObjectGuid playerGuid)
{
    std::string playerName;
    uint8 playerClass;

    // Check if arena team is full (Can't have more than type * 2 players)
    if (GetMembersSize() >= GetType() * 2)
        return false;

    // Get player name and class either from db or ObjectMgr
    Player* player = ObjectAccessor::FindPlayer(playerGuid);
    if (player)
    {
        playerClass = player->getClass();
        playerName = player->GetName();
    }
    else if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(playerGuid))
    {
        playerName = characterInfo->Name;
        playerClass = characterInfo->Class;
    }
    else
        return false;

    // Check if player is already in a similar arena team
    if ((player && player->GetArenaTeamId(GetSlot())) || Player::GetArenaTeamIdFromDB(playerGuid, GetType()) != 0)
    {
        TC_LOG_DEBUG("bg.arena", "Arena: %s %s already has an arena team of type %u", playerGuid.ToString().c_str(), playerName.c_str(), GetType());
        return false;
    }

    // Set player's personal rating
    uint32 personalRating = 0;

    if (sWorld->getIntConfig(CONFIG_ARENA_START_PERSONAL_RATING) > 0)
        personalRating = sWorld->getIntConfig(CONFIG_ARENA_START_PERSONAL_RATING);
    else if (GetRating() >= 1000)
        personalRating = 1000;

    // Try to get player's match maker rating from db and fall back to config setting if not found
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MATCH_MAKER_RATING);
    stmt->setUInt64(0, playerGuid.GetCounter());
    stmt->setUInt8(1, GetSlot());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    uint32 matchMakerRating;
    if (result)
        matchMakerRating = (*result)[0].GetUInt16();
    else
        matchMakerRating = sWorld->getIntConfig(CONFIG_ARENA_START_MATCHMAKER_RATING);

    // Remove all player signatures from other petitions
    // This will prevent player from joining too many arena teams and corrupt arena team data integrity
    //Player::RemovePetitionsAndSigns(playerGuid, GetType()); /// @todo arena teams removed in 5.4

    // Feed data to the struct
    ArenaTeamMember newMember;
    newMember.Name             = playerName;
    newMember.Guid             = playerGuid;
    newMember.Class            = playerClass;
    newMember.SeasonGames      = 0;
    newMember.WeekGames        = 0;
    newMember.SeasonWins       = 0;
    newMember.WeekWins         = 0;
    newMember.PersonalRating   = personalRating;
    newMember.MatchMakerRating = matchMakerRating;

    Members.push_back(newMember);

    // Save player's arena team membership to db
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ARENA_TEAM_MEMBER);
    stmt->setUInt32(0, TeamId);
    stmt->setUInt64(1, playerGuid.GetCounter());
    CharacterDatabase.Execute(stmt);

    // Inform player if online
    if (player)
    {
        player->SetInArenaTeam(TeamId, GetSlot(), GetType());
        player->SetArenaTeamIdInvited(0);

        // Hide promote/remove buttons
        if (CaptainGuid != playerGuid)
            player->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_MEMBER, 1);
    }

    TC_LOG_DEBUG("bg.arena", "Player: %s [%s] joined arena team type: %u [Id: %u, Name: %s].", playerName.c_str(), playerGuid.ToString().c_str(), GetType(), GetId(), GetName().c_str());

    return true;
}

bool ArenaTeam::LoadArenaTeamFromDB(QueryResult result)
{
    if (!result)
        return false;

    Field* fields = result->Fetch();

    TeamId            = fields[0].GetUInt32();
    TeamName          = fields[1].GetString();
    CaptainGuid       = ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64());
    Type              = fields[3].GetUInt8();
    BackgroundColor   = fields[4].GetUInt32();
    EmblemStyle       = fields[5].GetUInt8();
    EmblemColor       = fields[6].GetUInt32();
    BorderStyle       = fields[7].GetUInt8();
    BorderColor       = fields[8].GetUInt32();
    Stats.Rating      = fields[9].GetUInt16();
    Stats.WeekGames   = fields[10].GetUInt16();
    Stats.WeekWins    = fields[11].GetUInt16();
    Stats.SeasonGames = fields[12].GetUInt16();
    Stats.SeasonWins  = fields[13].GetUInt16();
    Stats.Rank        = fields[14].GetUInt32();

    return true;
}

bool ArenaTeam::LoadMembersFromDB(QueryResult result)
{
    if (!result)
        return false;

    bool captainPresentInTeam = false;

    do
    {
        Field* fields = result->Fetch();

        // Prevent crash if db records are broken when all members in result are already processed and current team doesn't have any members
        if (!fields)
            break;

        uint32 arenaTeamId = fields[0].GetUInt32();

        // We loaded all members for this arena_team already, break cycle
        if (arenaTeamId > TeamId)
            break;

        ArenaTeamMember newMember;
        newMember.Guid             = ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64());
        newMember.WeekGames        = fields[2].GetUInt16();
        newMember.WeekWins         = fields[3].GetUInt16();
        newMember.SeasonGames      = fields[4].GetUInt16();
        newMember.SeasonWins       = fields[5].GetUInt16();
        newMember.Name             = fields[6].GetString();
        newMember.Class            = fields[7].GetUInt8();
        newMember.PersonalRating   = fields[8].GetUInt16();
        newMember.MatchMakerRating = fields[9].GetUInt16() > 0 ? fields[9].GetUInt16() : sWorld->getIntConfig(CONFIG_ARENA_START_MATCHMAKER_RATING);

        // Delete member if character information is missing
        if (newMember.Name.empty())
        {
            TC_LOG_ERROR("sql.sql", "ArenaTeam %u has member with empty name - probably %s doesn't exist, deleting him from memberlist!", arenaTeamId, newMember.Guid.ToString().c_str());
            DelMember(newMember.Guid, true);
            continue;
        }

        // Check if team team has a valid captain
        if (newMember.Guid == GetCaptain())
            captainPresentInTeam = true;

        // Put the player in the team
        Members.push_back(newMember);
    }
    while (result->NextRow());

    if (Empty() || !captainPresentInTeam)
    {
        // Arena team is empty or captain is not in team, delete from db
        TC_LOG_DEBUG("bg.arena", "ArenaTeam %u does not have any members or its captain is not in team, disbanding it...", TeamId);
        return false;
    }

    return true;
}

bool ArenaTeam::SetName(std::string const& name)
{
    if (TeamName == name || name.empty() || name.length() > 24 || sObjectMgr->IsReservedName(name) || !ObjectMgr::IsValidCharterName(name))
        return false;

    TeamName = name;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ARENA_TEAM_NAME);
    stmt->setString(0, TeamName);
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);
    return true;
}

void ArenaTeam::SetCaptain(ObjectGuid guid)
{
    // Disable remove/promote buttons
    Player* oldCaptain = ObjectAccessor::FindPlayer(GetCaptain());
    if (oldCaptain)
        oldCaptain->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_MEMBER, 1);

    // Set new captain
    CaptainGuid = guid;

    // Update database
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ARENA_TEAM_CAPTAIN);
    stmt->setUInt64(0, guid.GetCounter());
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);

    // Enable remove/promote buttons
    if (Player* newCaptain = ObjectAccessor::FindPlayer(guid))
    {
        newCaptain->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_MEMBER, 0);
        if (oldCaptain)
        {
            TC_LOG_DEBUG("bg.arena", "Player: %s [%s] promoted player: %s [%s] to leader of arena team [Id: %u, Name: %s] [Type: %u].",
                oldCaptain->GetName().c_str(), oldCaptain->GetGUID().ToString().c_str(), newCaptain->GetName().c_str(),
                newCaptain->GetGUID().ToString().c_str(), GetId(), GetName().c_str(), GetType());
        }
    }
}

void ArenaTeam::DelMember(ObjectGuid guid, bool cleanDb)
{
    // Remove member from team
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
        {
            Members.erase(itr);
            break;
        }

    // Remove arena team info from player data
    if (Player* player = ObjectAccessor::FindPlayer(guid))
    {
        // delete all info regarding this team
        for (uint32 i = 0; i < ARENA_TEAM_END; ++i)
            player->SetArenaTeamInfoField(GetSlot(), ArenaTeamInfoType(i), 0);
        TC_LOG_DEBUG("bg.arena", "Player: %s [%s] left arena team type: %u [Id: %u, Name: %s].", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetType(), GetId(), GetName().c_str());
    }

    // Only used for single member deletion, for arena team disband we use a single query for more efficiency
    if (cleanDb)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM_MEMBER);
        stmt->setUInt32(0, GetId());
        stmt->setUInt64(1, guid.GetCounter());
        CharacterDatabase.Execute(stmt);
    }
}

void ArenaTeam::Disband(WorldSession* session)
{
    // Broadcast update
    if (session)
    {
        if (Player* player = session->GetPlayer())
            TC_LOG_DEBUG("bg.arena", "Player: %s [%s] disbanded arena team type: %u [Id: %u, Name: %s].", player->GetName().c_str(), player->GetGUID().ToString().c_str(), GetType(), GetId(), GetName().c_str());
    }

    // Remove all members from arena team
    while (!Members.empty())
        DelMember(Members.front().Guid, false);

    // Update database
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM);
    stmt->setUInt32(0, TeamId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM_MEMBERS);
    stmt->setUInt32(0, TeamId);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    // Remove arena team from ObjectMgr
    sArenaTeamMgr->RemoveArenaTeam(TeamId);
}

void ArenaTeam::Disband()
{
    // Remove all members from arena team
    while (!Members.empty())
        DelMember(Members.front().Guid, false);

    // Update database
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM);
    stmt->setUInt32(0, TeamId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM_MEMBERS);
    stmt->setUInt32(0, TeamId);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    // Remove arena team from ObjectMgr
    sArenaTeamMgr->RemoveArenaTeam(TeamId);
}

void ArenaTeam::SendStats(WorldSession* session)
{
    WorldPacket data(SMSG_ARENA_TEAM_STATS, 4*7);
    data << uint32(GetId());                                // team id
    data << uint32(Stats.Rating);                           // rating
    data << uint32(Stats.WeekGames);                        // games this week
    data << uint32(Stats.WeekWins);                         // wins this week
    data << uint32(Stats.SeasonGames);                      // played this season
    data << uint32(Stats.SeasonWins);                       // wins this season
    data << uint32(Stats.Rank);                             // rank
    session->SendPacket(&data);
}

void ArenaTeam::NotifyStatsChanged()
{
    // This is called after a rated match ended
    // Updates arena team stats for every member of the team (not only the ones who participated!)
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (Player* player = ObjectAccessor::FindConnectedPlayer(itr->Guid))
            SendStats(player->GetSession());
}

void ArenaTeam::Inspect(WorldSession* /*session*/, ObjectGuid guid)
{
    ArenaTeamMember* member = GetMember(guid);
    if (!member)
        return;

    //WorldPacket data(MSG_INSPECT_ARENA_TEAMS, 8+1+4*6);
    //data << guid;                                           // player guid
    //data << uint8(GetSlot());                               // slot (0...2)
    //data << uint32(GetId());                                // arena team id
    //data << uint32(Stats.Rating);                           // rating
    //data << uint32(Stats.SeasonGames);                      // season played
    //data << uint32(Stats.SeasonWins);                       // season wins
    //data << uint32(member->SeasonGames);                    // played (count of all games, that the inspected member participated...)
    //data << uint32(member->PersonalRating);                 // personal rating
    //session->SendPacket(&data);
}

void ArenaTeamMember::ModifyPersonalRating(Player* player, int32 mod, uint32 type)
{
    if (int32(PersonalRating) + mod < 0)
        PersonalRating = 0;
    else
        PersonalRating += mod;

    if (player)
    {
        player->SetArenaTeamInfoField(ArenaTeam::GetSlotByType(type), ARENA_TEAM_PERSONAL_RATING, PersonalRating);
        player->UpdateCriteria(CRITERIA_TYPE_HIGHEST_PERSONAL_RATING, PersonalRating, type);
    }
}

void ArenaTeamMember::ModifyMatchmakerRating(int32 mod, uint32 /*slot*/)
{
    if (int32(MatchMakerRating) + mod < 0)
        MatchMakerRating = 0;
    else
        MatchMakerRating += mod;
}

void ArenaTeam::BroadcastPacket(WorldPacket* packet)
{
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (Player* player = ObjectAccessor::FindConnectedPlayer(itr->Guid))
            player->GetSession()->SendPacket(packet);
}

uint8 ArenaTeam::GetSlotByType(uint32 type)
{
    switch (type)
    {
        case ARENA_TEAM_2v2: return 0;
        case ARENA_TEAM_3v3: return 1;
        case ARENA_TEAM_5v5: return 2;
        default:
            break;
    }
    TC_LOG_ERROR("bg.arena", "FATAL: Unknown arena team type %u for some arena team", type);
    return 0xFF;
}

uint8 ArenaTeam::GetTypeBySlot(uint8 slot)
{
    switch (slot)
    {
        case 0: return ARENA_TEAM_2v2;
        case 1: return ARENA_TEAM_3v3;
        case 2: return ARENA_TEAM_5v5;
        default:
            break;
    }
    TC_LOG_ERROR("bg.arena", "FATAL: Unknown arena team slot %u for some arena team", slot);
    return 0xFF;
}

bool ArenaTeam::IsMember(ObjectGuid guid) const
{
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
            return true;

    return false;
}

uint32 ArenaTeam::GetAverageMMR(Group* group) const
{
    if (!group)
        return 0;

    uint32 matchMakerRating = 0;
    uint32 playerDivider = 0;
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        // Skip if player is not online
        if (!ObjectAccessor::FindConnectedPlayer(itr->Guid))
            continue;

        // Skip if player is not a member of group
        if (!group->IsMember(itr->Guid))
            continue;

        matchMakerRating += itr->MatchMakerRating;
        ++playerDivider;
    }

    // x/0 = crash
    if (playerDivider == 0)
        playerDivider = 1;

    matchMakerRating /= playerDivider;

    return matchMakerRating;
}

float ArenaTeam::GetChanceAgainst(uint32 ownRating, uint32 opponentRating)
{
    // Returns the chance to win against a team with the given rating, used in the rating adjustment calculation
    // ELO system
    return 1.0f / (1.0f + std::exp(std::log(10.0f) * (float(opponentRating) - float(ownRating)) / 650.0f));
}

int32 ArenaTeam::GetMatchmakerRatingMod(uint32 ownRating, uint32 opponentRating, bool won)
{
    // 'Chance' calculation - to beat the opponent
    // This is a simulation. Not much info on how it really works
    float chance = GetChanceAgainst(ownRating, opponentRating);
    float won_mod = (won) ? 1.0f : 0.0f;
    float mod = won_mod - chance;

    // Work in progress:
    /*
    // This is a simulation, as there is not much info on how it really works
    float confidence_mod = min(1.0f - fabs(mod), 0.5f);

    // Apply confidence factor to the mod:
    mod *= confidence_factor

    // And only after that update the new confidence factor
    confidence_factor -= ((confidence_factor - 1.0f) * confidence_mod) / confidence_factor;
    */

    // Real rating modification
    mod *= sWorld->getFloatConfig(CONFIG_ARENA_MATCHMAKER_RATING_MODIFIER);

    return (int32)ceil(mod);
}

int32 ArenaTeam::GetRatingMod(uint32 ownRating, uint32 opponentRating, bool won /*, float confidence_factor*/)
{
    // 'Chance' calculation - to beat the opponent
    // This is a simulation. Not much info on how it really works
    float chance = GetChanceAgainst(ownRating, opponentRating);

    // Calculate the rating modification
    float mod;

    /// @todo Replace this hack with using the confidence factor (limiting the factor to 2.0f)
    if (won)
    {
        if (ownRating < 1300)
        {
            float win_rating_modifier1 = sWorld->getFloatConfig(CONFIG_ARENA_WIN_RATING_MODIFIER_1);

            if (ownRating < 1000)
                mod =  win_rating_modifier1 * (1.0f - chance);
            else
                mod = ((win_rating_modifier1 / 2.0f) + ((win_rating_modifier1 / 2.0f) * (1300.0f - float(ownRating)) / 300.0f)) * (1.0f - chance);
        }
        else
            mod = sWorld->getFloatConfig(CONFIG_ARENA_WIN_RATING_MODIFIER_2) * (1.0f - chance);
    }
    else
        mod = sWorld->getFloatConfig(CONFIG_ARENA_LOSE_RATING_MODIFIER) * (-chance);

    return (int32)ceil(mod);
}

void ArenaTeam::FinishGame(int32 mod)
{
    // Rating can only drop to 0
    if (int32(Stats.Rating) + mod < 0)
        Stats.Rating = 0;
    else
    {
        Stats.Rating += mod;

        // Check if rating related achivements are met
        for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
            if (Player* member = ObjectAccessor::FindConnectedPlayer(itr->Guid))
                member->UpdateCriteria(CRITERIA_TYPE_HIGHEST_TEAM_RATING, Stats.Rating, Type);
    }

    // Update number of games played per season or week
    Stats.WeekGames += 1;
    Stats.SeasonGames += 1;

    // Update team's rank, start with rank 1 and increase until no team with more rating was found
    Stats.Rank = 1;
    ArenaTeamMgr::ArenaTeamContainer::const_iterator i = sArenaTeamMgr->GetArenaTeamMapBegin();
    for (; i != sArenaTeamMgr->GetArenaTeamMapEnd(); ++i)
    {
        if (i->second->GetType() == Type && i->second->GetStats().Rating > Stats.Rating)
            ++Stats.Rank;
    }
}

int32 ArenaTeam::WonAgainst(uint32 ownMMRating, uint32 opponentMMRating, int32& ratingChange)
{
    // Called when the team has won
    // Change in Matchmaker rating
    int32 mod = GetMatchmakerRatingMod(ownMMRating, opponentMMRating, true);

    // Change in Team Rating
    ratingChange = GetRatingMod(Stats.Rating, opponentMMRating, true);

    // Modify the team stats accordingly
    FinishGame(ratingChange);

    // Update number of wins per season and week
    Stats.WeekWins += 1;
    Stats.SeasonWins += 1;

    // Return the rating change, used to display it on the results screen
    return mod;
}

int32 ArenaTeam::LostAgainst(uint32 ownMMRating, uint32 opponentMMRating, int32& ratingChange)
{
    // Called when the team has lost
    // Change in Matchmaker Rating
    int32 mod = GetMatchmakerRatingMod(ownMMRating, opponentMMRating, false);

    // Change in Team Rating
    ratingChange = GetRatingMod(Stats.Rating, opponentMMRating, false);

    // Modify the team stats accordingly
    FinishGame(ratingChange);

    // return the rating change, used to display it on the results screen
    return mod;
}

void ArenaTeam::MemberLost(Player* player, uint32 againstMatchmakerRating, int32 matchmakerRatingChange)
{
    // Called for each participant of a match after losing
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        if (itr->Guid == player->GetGUID())
        {
            // Update personal rating
            int32 mod = GetRatingMod(itr->PersonalRating, againstMatchmakerRating, false);
            itr->ModifyPersonalRating(player, mod, GetType());

            // Update matchmaker rating
            itr->ModifyMatchmakerRating(matchmakerRatingChange, GetSlot());

            // Update personal played stats
            itr->WeekGames +=1;
            itr->SeasonGames +=1;

            // update the unit fields
            player->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_WEEK,  itr->WeekGames);
            player->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_SEASON,  itr->SeasonGames);
            return;
        }
    }
}

void ArenaTeam::OfflineMemberLost(ObjectGuid guid, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange)
{
    // Called for offline player after ending rated arena match!
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        if (itr->Guid == guid)
        {
            // update personal rating
            int32 mod = GetRatingMod(itr->PersonalRating, againstMatchmakerRating, false);
            itr->ModifyPersonalRating(NULL, mod, GetType());

            // update matchmaker rating
            itr->ModifyMatchmakerRating(MatchmakerRatingChange, GetSlot());

            // update personal played stats
            itr->WeekGames += 1;
            itr->SeasonGames += 1;
            return;
        }
    }
}

void ArenaTeam::MemberWon(Player* player, uint32 againstMatchmakerRating, int32 matchmakerRatingChange)
{
    // called for each participant after winning a match
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        if (itr->Guid == player->GetGUID())
        {
            // update personal rating
            int32 mod = GetRatingMod(itr->PersonalRating, againstMatchmakerRating, true);
            itr->ModifyPersonalRating(player, mod, GetType());

            // update matchmaker rating
            itr->ModifyMatchmakerRating(matchmakerRatingChange, GetSlot());

            // update personal stats
            itr->WeekGames +=1;
            itr->SeasonGames +=1;
            itr->SeasonWins += 1;
            itr->WeekWins += 1;
            // update unit fields
            player->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_WEEK, itr->WeekGames);
            player->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_SEASON, itr->SeasonGames);
            return;
        }
    }
}

void ArenaTeam::SaveToDB()
{
    // Save team and member stats to db
    // Called after a match has ended or when calculating arena_points

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ARENA_TEAM_STATS);
    stmt->setUInt16(0, Stats.Rating);
    stmt->setUInt16(1, Stats.WeekGames);
    stmt->setUInt16(2, Stats.WeekWins);
    stmt->setUInt16(3, Stats.SeasonGames);
    stmt->setUInt16(4, Stats.SeasonWins);
    stmt->setUInt32(5, Stats.Rank);
    stmt->setUInt32(6, GetId());
    trans->Append(stmt);

    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        // Save the effort and go
        if (itr->WeekGames == 0)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ARENA_TEAM_MEMBER);
        stmt->setUInt16(0, itr->PersonalRating);
        stmt->setUInt16(1, itr->WeekGames);
        stmt->setUInt16(2, itr->WeekWins);
        stmt->setUInt16(3, itr->SeasonGames);
        stmt->setUInt16(4, itr->SeasonWins);
        stmt->setUInt32(5, GetId());
        stmt->setUInt64(6, itr->Guid.GetCounter());
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHARACTER_ARENA_STATS);
        stmt->setUInt64(0, itr->Guid.GetCounter());
        stmt->setUInt8(1, GetSlot());
        stmt->setUInt16(2, itr->MatchMakerRating);
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
}

bool ArenaTeam::FinishWeek()
{
    // No need to go further than this
    if (Stats.WeekGames == 0)
        return false;

    // Reset team stats
    Stats.WeekGames = 0;
    Stats.WeekWins = 0;

    // Reset member stats
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        itr->WeekGames = 0;
        itr->WeekWins = 0;
    }

    return true;
}

bool ArenaTeam::IsFighting() const
{
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->Guid))
            if (player->GetMap()->IsBattleArena())
                return true;

    return false;
}

ArenaTeamMember* ArenaTeam::GetMember(const std::string& name)
{
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Name == name)
            return &(*itr);

    return NULL;
}

ArenaTeamMember* ArenaTeam::GetMember(ObjectGuid guid)
{
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
            return &(*itr);

    return NULL;
}
