/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "ArenaTeam.h"
#include "World.h"
#include "Group.h"

ArenaTeam::ArenaTeam()
{
    TeamId            = 0;
    Type              = 0;
    TeamName          = "";
    CaptainGuid       = 0;
    BackgroundColor   = 0;
    EmblemStyle       = 0;
    EmblemColor       = 0;
    BorderStyle       = 0;
    BorderColor       = 0;
    Stats.WeekGames   = 0;
    Stats.SeasonGames = 0;
    Stats.Rank        = 0;
    Stats.Rating      = sWorld->getIntConfig(CONFIG_ARENA_START_RATING);
    Stats.WeekWins    = 0;
    Stats.SeasonWins  = 0;
}

ArenaTeam::~ArenaTeam()
{
}

bool ArenaTeam::Create(uint32 captainGuid, uint8 type, std::string teamName, uint32 backgroundColor, uint8 emblemStyle, uint32 emblemColor, uint8 borderStyle, uint32 borderColor)
{
    // Check if captain is present
    if (!sObjectMgr->GetPlayer(captainGuid))
        return false;

    // Check if arena team name is already taken
    if (sObjectMgr->GetArenaTeamByName(TeamName))
        return false;


    // Generate new arena team id
    TeamId = sObjectMgr->GenerateArenaTeamId();

    // Assign member variables
    CaptainGuid = captainGuid;
    Type = type;
    TeamName = teamName;
    BackgroundColor = backgroundColor;
    EmblemStyle = emblemStyle;
    EmblemColor = emblemColor;
    BorderStyle = borderStyle;
    BorderColor = borderColor;



    // Save arena team to db
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_ADD_ARENA_TEAM);
    stmt->setUInt32(0, TeamId);
    stmt->setString(1, TeamName);
    stmt->setUInt32(2, GUID_LOPART(CaptainGuid));
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

    sLog->outArena("New ArenaTeam created [Id: %u] [Type: %u] [Captain low GUID: %u]", GetId(), GetType(), GUID_LOPART(CaptainGuid));
    return true;
}

bool ArenaTeam::AddMember(const uint64& playerGuid)
{
    std::string playerName;
    uint8 playerClass;

    // Check if arena team is full (Can't have more than type * 2 players)
    if (GetMembersSize() >= GetType() * 2)
        return false;

    // Get player name and class either from db or ObjectMgr
    Player *player = sObjectMgr->GetPlayer(playerGuid);
    if (player)
    {
        playerClass = player->getClass();
        playerName = player->GetName();
    }
    else
    {
        //          0     1
        // SELECT name, class FROM characters WHERE guid = ?
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_LOAD_PLAYER_NAME_CLASS);
        stmt->setUInt32(0, GUID_LOPART(playerGuid));
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (!result)
            return false;

        playerName = (*result)[0].GetString();
        playerClass = (*result)[1].GetUInt8();
    }

    // Check if player is already in a similar arena team
    if (player && player->GetArenaTeamId(GetSlot()) || Player::GetArenaTeamIdFromDB(playerGuid, GetType()) != 0)
    {
        sLog->outError("Arena: Player %s (guid: %u) already has an arena team of type %u", playerName.c_str(), playerGuid, GetType());
        return false;
    }

    // Set player's personal rating
    uint32 personalRating = 0;

    if (sWorld->getIntConfig(CONFIG_ARENA_START_PERSONAL_RATING) > 0)
        personalRating = sWorld->getIntConfig(CONFIG_ARENA_START_PERSONAL_RATING);
    else if (GetRating() >= 1000)
        personalRating = 1000;

    // Try to get player's match maker rating from db and fall back to config setting if not found
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_LOAD_MATCH_MAKER_RATING);
    stmt->setUInt32(0, GUID_LOPART(playerGuid));
    stmt->setUInt8(1, GetSlot());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    uint32 matchMakerRating;
    if (result)
        matchMakerRating = (*result)[0].GetUInt32();
    else
        matchMakerRating = sWorld->getIntConfig(CONFIG_ARENA_START_MATCHMAKER_RATING);

    // Remove all player signatures from other petitions
    // This will prevent player from joining too many arena teams and corrupt arena team data integrity
    Player::RemovePetitionsAndSigns(playerGuid, GetType());

    // Feed data to the struct
    ArenaTeamMember newmember;
    newmember.Name              = playerName;
    newmember.Guid              = playerGuid;
    newmember.Class             = playerClass;
    newmember.SeasonGames      = 0;
    newmember.WeekGames        = 0;
    newmember.SeasonWins       = 0;
    newmember.WeekWins         = 0;
    newmember.PersonalRating   = personalRating;
    newmember.MatchMakerRating = matchMakerRating;

    Members.push_back(newmember);

    // Save player's arena team membership to db
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SET_ARENA_TEAM_MEMBER);
    stmt->setUInt32(0, TeamId);
    stmt->setUInt32(1, playerGuid);
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

    sLog->outArena("Player: %s [GUID: %u] joined arena team type: %u [Id: %u].", playerName.c_str(), playerGuid, GetType(), GetId());

    return true;
}

bool ArenaTeam::LoadArenaTeamFromDB(QueryResult result)
{
    if (!result)
        return false;

    Field *fields = result->Fetch();

    TeamId            = fields[0].GetUInt32();
    TeamName          = fields[1].GetString();
    CaptainGuid       = MAKE_NEW_GUID(fields[2].GetUInt32(), 0, HIGHGUID_PLAYER);
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
        Field *fields = result->Fetch();

        // Prevent crash if db records are broken when all members in result are already processed and current team doesn't have any members
        if (!fields)
            break;

        uint32 arenaTeamId = fields[0].GetUInt32();

        // We loaded all members for this arena_team already, break cycle
        if (arenaTeamId > TeamId)
            break;

        ArenaTeamMember newMember;
        newMember.Guid              = MAKE_NEW_GUID(fields[1].GetUInt32(), 0, HIGHGUID_PLAYER);
        newMember.WeekGames        = fields[2].GetUInt16();
        newMember.WeekWins         = fields[3].GetUInt16();
        newMember.SeasonGames      = fields[4].GetUInt16();
        newMember.SeasonWins       = fields[5].GetUInt16();
        newMember.Name              = fields[6].GetString();
        newMember.Class             = fields[7].GetUInt8();
        newMember.PersonalRating   = fields[8].GetUInt16();
        newMember.MatchMakerRating = fields[9].GetUInt16() > 0 ? fields[9].GetUInt16() : 1500;

        // Delete member if character information is missing
        if (newMember.Name.empty())
        {
            sLog->outErrorDb("ArenaTeam %u has member with empty name - probably player %u doesn't exist, deleting him from memberlist!", arenaTeamId, GUID_LOPART(newMember.Guid));
            this->DelMember(newMember.Guid, true);
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
        sLog->outErrorDb("ArenaTeam %u does not have any members or its captain is not in team, disbanding it...", TeamId);
        return false;
    }

    return true;
}

void ArenaTeam::SetCaptain(const uint64& guid)
{
    // Disable remove/promote buttons
    Player* oldCaptain = sObjectMgr->GetPlayer(GetCaptain());
    if (oldCaptain)
        oldCaptain->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_MEMBER, 1);

    // Set new captain
    CaptainGuid = guid;

    // Update database
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPDATE_ARENA_TEAM_CAPTAIN);
    stmt->setUInt32(0, GUID_LOPART(guid));
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);

    // Enable remove/promote buttons
    Player *newCaptain = sObjectMgr->GetPlayer(guid);
    if (newCaptain)
    {
        newCaptain->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_MEMBER, 0);
        sLog->outArena("Player: %s [GUID: %u] promoted player: %s [GUID: %u] to leader of arena team [Id: %u] [Type: %u].",
                        oldCaptain->GetName(), oldCaptain->GetGUIDLow(), newCaptain->GetName(), newCaptain->GetGUIDLow(), GetId(), GetType());
    }
}

void ArenaTeam::DelMember(uint64 guid, bool cleanDb)
{
    // Remove member from team
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
        {
            Members.erase(itr);
            break;
        }

    // Inform player and remove arena team info from player data
    if (Player *player = sObjectMgr->GetPlayer(guid))
    {
        player->GetSession()->SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, GetName(), "", 0);
        // delete all info regarding this team
        for (uint32 i = 0; i < ARENA_TEAM_END; ++i)
            player->SetArenaTeamInfoField(GetSlot(), ArenaTeamInfoType(i), 0);
        sLog->outArena("Player: %s [GUID: %u] left arena team type: %u [Id: %u].", player->GetName(), player->GetGUIDLow(), GetType(), GetId());
    }

    // Only used for single member deletion, for arena team disband we use a single query for more efficiency
    if (cleanDb)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARENA_TEAM_MEMBER);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, GUID_LOPART(guid));
        CharacterDatabase.Execute(stmt);
    }
}

void ArenaTeam::Disband(WorldSession* session)
{
    // Remove all members from arena team
    while (!Members.empty())
        DelMember(Members.front().Guid, false);

    // Broadcast update
    if (session)
    {
        BroadcastEvent(ERR_ARENA_TEAM_DISBANDED_S, 0, 2, session->GetPlayerName(), GetName(), "");

        if (Player *player = session->GetPlayer())
            sLog->outArena("Player: %s [GUID: %u] disbanded arena team type: %u [Id: %u].", player->GetName(), player->GetGUIDLow(), GetType(), GetId());
    }

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
    sObjectMgr->RemoveArenaTeam(TeamId);
}

void ArenaTeam::Roster(WorldSession* session)
{
    Player* pl = NULL;

    uint8 unk308 = 0;

    WorldPacket data(SMSG_ARENA_TEAM_ROSTER, 100);
    data << uint32(GetId());                                // team id
    data << uint8(unk308);                                  // 308 unknown value but affect packet structure
    data << uint32(GetMembersSize());                       // members count
    data << uint32(GetType());                              // arena team type?

    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        pl = sObjectMgr->GetPlayer(itr->Guid);

        data << uint64(itr->Guid);                          // guid
        data << uint8((pl ? 1 : 0));                        // online flag
        data << itr->Name;                                  // member name
        data << uint32((itr->Guid == GetCaptain() ? 0 : 1));// captain flag 0 captain 1 member
        data << uint8((pl ? pl->getLevel() : 0));           // unknown, level?
        data << uint8(itr->Class);                          // class
        data << uint32(itr->WeekGames);                    // played this week
        data << uint32(itr->WeekWins);                     // wins this week
        data << uint32(itr->SeasonGames);                  // played this season
        data << uint32(itr->SeasonWins);                   // wins this season
        data << uint32(itr->PersonalRating);               // personal rating
        if (unk308)
        {
            data << float(0.0);                             // 308 unk
            data << float(0.0);                             // 308 unk
        }
    }

    session->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_ARENA_TEAM_ROSTER");
}

void ArenaTeam::Query(WorldSession* session)
{
    WorldPacket data(SMSG_ARENA_TEAM_QUERY_RESPONSE, 4*7+GetName().size()+1);
    data << uint32(GetId());                                // team id
    data << GetName();                                      // team name
    data << uint32(GetType());                              // arena team type (2=2x2, 3=3x3 or 5=5x5)
    data << uint32(BackgroundColor);                      // background color
    data << uint32(EmblemStyle);                          // emblem style
    data << uint32(EmblemColor);                          // emblem color
    data << uint32(BorderStyle);                          // border style
    data << uint32(BorderColor);                          // border color
    session->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_ARENA_TEAM_QUERY_RESPONSE");
}

void ArenaTeam::SendStats(WorldSession* session)
{
    WorldPacket data(SMSG_ARENA_TEAM_STATS, 4*7);
    data << uint32(GetId());                                // team id
    data << uint32(Stats.Rating);                         // rating
    data << uint32(Stats.WeekGames);                     // games this week
    data << uint32(Stats.WeekWins);                      // wins this week
    data << uint32(Stats.SeasonGames);                   // played this season
    data << uint32(Stats.SeasonWins);                    // wins this season
    data << uint32(Stats.Rank);                           // rank
    session->SendPacket(&data);
}

void ArenaTeam::NotifyStatsChanged()
{
    // This is called after a rated match ended
    // Updates arena team stats for every member of the team (not only the ones who participated!)
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
    {
        Player* plr = sObjectMgr->GetPlayer(itr->Guid);
        if (plr)
            SendStats(plr->GetSession());
    }
}

void ArenaTeam::Inspect(WorldSession* session, uint64 guid)
{
    ArenaTeamMember* member = GetMember(guid);
    if (!member)
        return;

    WorldPacket data(MSG_INSPECT_ARENA_TEAMS, 8+1+4*6);
    data << uint64(guid);                                   // player guid
    data << uint8(GetSlot());                               // slot (0...2)
    data << uint32(GetId());                                // arena team id
    data << uint32(Stats.Rating);                           // rating
    data << uint32(Stats.SeasonGames);                      // season played
    data << uint32(Stats.SeasonWins);                       // season wins
    data << uint32(member->SeasonGames);                    // played (count of all games, that the inspected member participated...)
    data << uint32(member->PersonalRating);                 // personal rating
    session->SendPacket(&data);
}

void ArenaTeamMember::ModifyPersonalRating(Player* plr, int32 mod, uint32 slot)
{
    if (int32(PersonalRating) + mod < 0)
        PersonalRating = 0;
    else
        PersonalRating += mod;
    if (plr)
        plr->SetArenaTeamInfoField(slot, ARENA_TEAM_PERSONAL_RATING, PersonalRating);
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
    {
        Player* player = sObjectMgr->GetPlayer(itr->Guid);
        if (player)
            player->GetSession()->SendPacket(packet);
    }
}

void ArenaTeam::BroadcastEvent(ArenaTeamEvents event, uint64 guid, uint8 strCount, std::string str1, std::string str2, std::string str3)
{
    WorldPacket data(SMSG_ARENA_TEAM_EVENT, 1+1+1);
    data << uint8(event);
    data << uint8(strCount);
    switch (strCount)
    {
        case 0:
            break;
        case 1:
            data << str1;
            break;
        case 2:
            data << str1 << str2;
            break;
        case 3:
            data << str1 << str2 << str3;
            break;
        default:
            sLog->outError("Unhandled strCount %u in ArenaTeam::BroadcastEvent", strCount);
            return;
    }

    if (guid)
        data << uint64(guid);

    BroadcastPacket(&data);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_ARENA_TEAM_EVENT");
}

uint8 ArenaTeam::GetSlotByType(uint32 type)
{
    switch(type)
    {
        case ARENA_TEAM_2v2: return 0;
        case ARENA_TEAM_3v3: return 1;
        case ARENA_TEAM_5v5: return 2;
        default:
            break;
    }
    sLog->outError("FATAL: Unknown arena team type %u for some arena team", type);
    return 0xFF;
}

bool ArenaTeam::IsMember(const uint64& guid) const
{
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
            return true;

    return false;
}

uint32 ArenaTeam::GetPoints(uint32 memberRating)
{
    // Returns how many points would be awarded with this team type with this rating
    float points;

    uint32 rating = memberRating + 150 < Stats.Rating ? memberRating : Stats.Rating;

    if (rating <= 1500)
    {
        if (sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) < 6)
            points = (float)rating * 0.22f + 14.0f;
        else
            points = 344;
    }
    else
        points = 1511.26f / (1.0f + 1639.28f * exp(-0.00412f * (float)rating));

    // Type penalties for teams < 5v5
    if  (Type == ARENA_TEAM_2v2)
        points *= 0.76f;
    else if (Type == ARENA_TEAM_3v3)
        points *= 0.88f;

    return (uint32) points;
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
        if (!ObjectAccessor::FindPlayer(itr->Guid))
            continue;

        // Skip if player is not member of group
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
    return 1.0f / (1.0f + exp(log(10.0f) * (float)((float)opponentRating - (float)ownRating) / 400.0f));
}

int32 ArenaTeam::GetRatingMod(uint32 ownRating, uint32 opponentRating, bool won, bool calculateMatchMakerRating)
{
    // 'Chance' calculation - to beat the opponent
    float chance = GetChanceAgainst(ownRating, opponentRating);
    float won_mod = (won) ? 1.0f : 0.0f;

    // Calculate the rating modification
    // Simulation on how it works. Not much info on how it really works
    float mod;

    if (won && !calculateMatchMakerRating)
    {
        if (ownRating < 1000)
            mod = 48.0f * (won_mod - chance);
        else if (ownRating < 1300)
            mod = (24.0f + (24.0f * (1300.0f - int32(ownRating)) / 300.0f)) * (won_mod - chance);
        else
            mod = 24.0f * (won_mod - chance);
    }
    else
        mod = 24.0f * (won_mod - chance);

    return (int32)ceil(mod);
}

int32 ArenaTeam::GetPersonalRatingMod(int32 baseRating, uint32 ownRating, uint32 opponentRating)
{
    // Max (2 * team rating gain/loss), min 0 gain/loss
    float chance = GetChanceAgainst(ownRating, opponentRating);
    chance *= 2.0f;

    return (int32)ceil(float(baseRating) * chance);
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
            if (Player* member = ObjectAccessor::FindPlayer(itr->Guid))
            {
                member->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING, Stats.Rating, Type);
                member->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_TEAM_RATING, Stats.Rating, Type);
            }
    }

    // Update number of games played per season or week
    Stats.WeekGames += 1;
    Stats.SeasonGames += 1;

    // Update team's rank, start with rank 1 and increase until no team with more rating was found
    Stats.Rank = 1;
    ObjectMgr::ArenaTeamMap::const_iterator i = sObjectMgr->GetArenaTeamMapBegin();
    for (; i != sObjectMgr->GetArenaTeamMapEnd(); ++i)
    {
        if (i->second->GetType() == Type && i->second->GetStats().Rating > Stats.Rating)
            ++Stats.Rank;
    }
}

int32 ArenaTeam::WonAgainst(uint32 againstRating)
{
    // Called when the team has won
    // Own team rating versus opponents matchmaker rating
    int32 mod = GetRatingMod(Stats.Rating, againstRating, true);

    // Modify the team stats accordingly
    FinishGame(mod);

    // Update number of wins per season and week
    Stats.WeekWins += 1;
    Stats.SeasonWins += 1;

    // Return the rating change, used to display it on the results screen
    return mod;
}

int32 ArenaTeam::LostAgainst(uint32 againstRating)
{
    // Called when the team has lost
    // Own team rating versus opponents matchmaker rating
    int32 mod = GetRatingMod(Stats.Rating, againstRating, false);

    // Modify the team stats accordingly
    FinishGame(mod);

    // return the rating change, used to display it on the results screen
    return mod;
}

void ArenaTeam::MemberLost(Player* plr, uint32 againstMatchmakerRating, int32 teamratingchange)
{
    // Called for each participant of a match after losing
    for (MemberList::iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        if (itr->Guid == plr->GetGUID())
        {
            // Update personal rating
            int32 mod = GetPersonalRatingMod(teamratingchange, itr->PersonalRating, (Stats.Rating - teamratingchange));
            itr->ModifyPersonalRating(plr, mod, GetSlot());

            // Update matchmaker rating
            mod = GetRatingMod(itr->MatchMakerRating, againstMatchmakerRating, false, true);
            itr->ModifyMatchmakerRating(mod, GetSlot());

            // Update personal played stats
            itr->WeekGames +=1;
            itr->SeasonGames +=1;

            // update the unit fields
            plr->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_WEEK,  itr->WeekGames);
            plr->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_SEASON,  itr->SeasonGames);
            return;
        }
    }
}

void ArenaTeam::OfflineMemberLost(uint64 guid, uint32 againstMatchMakerRating, int32 ratingChange)
{
    // Called for offline player after ending rated arena match!
    for (MemberList::iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        if (itr->Guid == guid)
        {
            // update personal rating
            int32 mod = GetPersonalRatingMod(ratingChange, itr->PersonalRating, (Stats.Rating - ratingChange));
            itr->ModifyPersonalRating(NULL, mod, GetSlot());

            // update matchmaker rating
            mod = GetRatingMod(itr->MatchMakerRating, againstMatchMakerRating, false, true);
            itr->ModifyMatchmakerRating(mod, GetSlot());

            // update personal played stats
            itr->WeekGames +=1;
            itr->SeasonGames +=1;
            return;
        }
    }
}

void ArenaTeam::MemberWon(Player* plr, uint32 againstMatchMakerRating, int32 ratingChange)
{
    // called for each participant after winning a match
    for (MemberList::iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        if (itr->Guid == plr->GetGUID())
        {
            // update personal rating
            int32 mod = GetPersonalRatingMod(ratingChange, (Stats.Rating - ratingChange), itr->PersonalRating);
            itr->ModifyPersonalRating(plr, mod, GetSlot());

            // update matchmaker rating
            mod = GetRatingMod(itr->MatchMakerRating, againstMatchMakerRating, true, true);
            itr->ModifyMatchmakerRating(mod, GetSlot());

            // update personal stats
            itr->WeekGames +=1;
            itr->SeasonGames +=1;
            itr->SeasonWins += 1;
            itr->WeekWins += 1;
            // update unit fields
            plr->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_WEEK, itr->WeekGames);
            plr->SetArenaTeamInfoField(GetSlot(), ARENA_TEAM_GAMES_SEASON, itr->SeasonGames);
            return;
        }
    }
}

void ArenaTeam::UpdateArenaPointsHelper(std::map<uint32, uint32>& playerPoints)
{
    // Called after a match has ended and the stats are already modified
    // Helper function for arena point distribution (this way, when distributing, no actual calculation is required, just a few comparisons)
    // 10 played games per week is a minimum
    if (Stats.WeekGames < 10)
        return;

    // To get points, a player has to participate in at least 30% of the matches
    uint32 requiredGames = (uint32) ceil(Stats.WeekGames * 0.3);

    for (MemberList::const_iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        // The player participated in enough games, update his points
        uint32 pointsToAdd = 0;
        if (itr->WeekGames >= requiredGames)
            pointsToAdd = GetPoints(itr->PersonalRating);

        std::map<uint32, uint32>::iterator plr_itr = playerPoints.find(GUID_LOPART(itr->Guid));
        if (plr_itr != playerPoints.end())
        {
            // Check if there is already more points
            if (plr_itr->second < pointsToAdd)
                playerPoints[GUID_LOPART(itr->Guid)] = pointsToAdd;
        }
        else
            playerPoints[GUID_LOPART(itr->Guid)] = pointsToAdd;
    }
}

void ArenaTeam::SaveToDB()
{
    // Save team and member stats to db
    // Called after a match has ended or when calculating arena_points

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPDATE_ARENA_TEAM_STATS);
    stmt->setUInt16(0, Stats.Rating);
    stmt->setUInt16(1, Stats.WeekGames);
    stmt->setUInt16(2, Stats.WeekWins);
    stmt->setUInt16(3, Stats.SeasonGames);
    stmt->setUInt16(4, Stats.SeasonWins);
    stmt->setUInt32(5, Stats.Rank);
    stmt->setUInt32(6, GetId());
    trans->Append(stmt);

    for (MemberList::const_iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPDATE_ARENA_TEAM_MEMBER);
        stmt->setUInt16(0, itr->PersonalRating);
        stmt->setUInt16(1, itr->WeekGames);
        stmt->setUInt16(2, itr->WeekWins);
        stmt->setUInt16(3, itr->SeasonGames);
        stmt->setUInt16(4, itr->SeasonWins);
        stmt->setUInt32(5, GetId());
        stmt->setUInt16(6, GUID_LOPART(itr->Guid));
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPDATE_CHARACTER_ARENA_STATS);
        stmt->setUInt32(0, GUID_LOPART(itr->Guid));
        stmt->setUInt8(1, GetSlot());
        stmt->setUInt16(2, itr->MatchMakerRating);
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
}

void ArenaTeam::FinishWeek()
{
    // Reset team stats
    Stats.WeekGames = 0;
    Stats.WeekWins = 0;

    // Reset member stats
    for (MemberList::iterator itr = Members.begin(); itr !=  Members.end(); ++itr)
    {
        itr->WeekGames = 0;
        itr->WeekWins = 0;
    }
}

bool ArenaTeam::IsFighting() const
{
    for (MemberList::const_iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (Player* player = sObjectMgr->GetPlayer(itr->Guid))
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

ArenaTeamMember* ArenaTeam::GetMember(const uint64& guid)
{
    for (MemberList::iterator itr = Members.begin(); itr != Members.end(); ++itr)
        if (itr->Guid == guid)
            return &(*itr);

    return NULL;
}
