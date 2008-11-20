/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "WorldPacket.h"
#include "ObjectMgr.h"
#include "ArenaTeam.h"

ArenaTeam::ArenaTeam()
{
    Id              = 0;
    Type            = 0;
    Name            = "";
    CaptainGuid     = 0;
    BackgroundColor = 0;                                    // background
    EmblemStyle     = 0;                                    // icon
    EmblemColor     = 0;                                    // icon color
    BorderStyle     = 0;                                    // border
    BorderColor     = 0;                                    // border color
    stats.games     = 0;
    stats.played    = 0;
    stats.rank      = 0;
    stats.rating    = 1500;
    stats.wins      = 0;
    stats.wins2     = 0;
}

ArenaTeam::~ArenaTeam()
{

}

bool ArenaTeam::create(uint64 captainGuid, uint32 type, std::string ArenaTeamName)
{
    if(!objmgr.GetPlayer(captainGuid))                      // player not exist
        return false;
    if(objmgr.GetArenaTeamByName(ArenaTeamName))            // arena team with this name already exist
        return false;

    sLog.outDebug("GUILD: creating arena team %s to leader: %u", ArenaTeamName.c_str(), GUID_LOPART(captainGuid));

    CaptainGuid = captainGuid;
    Name = ArenaTeamName;
    Type = type;

    QueryResult *result = CharacterDatabase.Query("SELECT MAX(arenateamid) FROM arena_team");
    if( result )
    {
        Id = (*result)[0].GetUInt32()+1;
        delete result;
    }
    else Id = 1;

    // ArenaTeamName already assigned to ArenaTeam::name, use it to encode string for DB
    CharacterDatabase.escape_string(ArenaTeamName);

    CharacterDatabase.BeginTransaction();
    // CharacterDatabase.PExecute("DELETE FROM arena_team WHERE arenateamid='%u'", Id); - MAX(arenateam)+1 not exist
    CharacterDatabase.PExecute("DELETE FROM arena_team_member WHERE arenateamid='%u'", Id);
    CharacterDatabase.PExecute("INSERT INTO arena_team (arenateamid,name,captainguid,type,BackgroundColor,EmblemStyle,EmblemColor,BorderStyle,BorderColor) "
        "VALUES('%u','%s','%u','%u','%u','%u','%u','%u','%u')",
        Id, ArenaTeamName.c_str(), GUID_LOPART(CaptainGuid), Type, BackgroundColor,EmblemStyle,EmblemColor,BorderStyle,BorderColor);
    CharacterDatabase.PExecute("INSERT INTO arena_team_stats (arenateamid, rating, games, wins, played, wins2, rank) VALUES "
        "('%u', '%u', '%u', '%u', '%u', '%u', '%u')", Id,stats.rating,stats.games,stats.wins,stats.played,stats.wins2,stats.rank);

    CharacterDatabase.CommitTransaction();

    AddMember(CaptainGuid);
    return true;
}

bool ArenaTeam::AddMember(uint64 PlayerGuid)
{
    std::string plName;
    uint8 plClass;

    // arena team is full (can't have more than type * 2 players!)
    if(GetMembersSize() >= GetType() * 2)
        return false;

    Player *pl = objmgr.GetPlayer(PlayerGuid);
    if(pl)
    {
        if(pl->GetArenaTeamId(GetSlot()))
        {
            sLog.outError("Arena::AddMember() : player already in this sized team");
            return false;
        }

        plClass = (uint8)pl->getClass();
        plName = pl->GetName();
    }
    else
    {
        //                                                     0     1
        QueryResult *result = CharacterDatabase.PQuery("SELECT name, class FROM characters WHERE guid='%u'", GUID_LOPART(PlayerGuid));
        if(!result)
            return false;

        plName = (*result)[0].GetCppString();
        plClass = (*result)[1].GetUInt8();
        delete result;

        // check if player already in arenateam of that size
        if(Player::GetArenaTeamIdFromDB(PlayerGuid, GetType()) != 0)
        {
            sLog.outError("Arena::AddMember() : player already in this sized team");
            return false;
        }
    }

    // remove all player signs from another petitions
    // this will be prevent attempt joining player to many arenateams and corrupt arena team data integrity
    Player::RemovePetitionsAndSigns(PlayerGuid, GetType());

    ArenaTeamMember newmember;
    newmember.name          = plName;
    newmember.guid          = PlayerGuid;
    newmember.Class         = plClass;
    newmember.played_season = 0;
    newmember.played_week   = 0;
    newmember.wons_season   = 0;
    newmember.wons_week     = 0;
    members.push_back(newmember);

    CharacterDatabase.PExecute("INSERT INTO arena_team_member (arenateamid,guid) VALUES ('%u', '%u')", Id, GUID_LOPART(newmember.guid));

    if(pl)
    {
        pl->SetInArenaTeam(Id, GetSlot());
        pl->SetArenaTeamIdInvited(0);
        // personal rating
        pl->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6) + 5, 1500);
    }

    // hide promote/remove buttons
    if(CaptainGuid != PlayerGuid)
    {
        if(pl)
            pl->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6), 1);
    }

    // setuint32valueindb is asynch, can't be used here
    Tokens tokens;
    if(!Player::LoadValuesArrayFromDB(tokens,PlayerGuid))
        return false;

    // arena team id
    uint16 index = PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6);
    char buf[11];
    snprintf(buf,11,"%u",Id);
    tokens[index] = buf;
    // pers rating
    index = PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6) + 5;
    buf[11];
    snprintf(buf,11,"%u",1500);
    tokens[index] = buf;
    // hide promote/remove buttons
    if(CaptainGuid != PlayerGuid)
    {
        index = PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6);
        buf[11];
        snprintf(buf,11,"%u",1);
        tokens[index] = buf;
    }

    Player::SaveValuesArrayInDB(tokens,PlayerGuid);

    return true;
}

bool ArenaTeam::LoadArenaTeamFromDB(uint32 ArenaTeamId)
{
    QueryResult *result = CharacterDatabase.PQuery("SELECT arenateamid,name,captainguid,type,BackgroundColor,EmblemStyle,EmblemColor,BorderStyle,BorderColor FROM arena_team WHERE arenateamid = '%u'", ArenaTeamId);

    if(!result)
        return false;

    Field *fields = result->Fetch();

    Id = fields[0].GetUInt32();
    Name = fields[1].GetCppString();
    CaptainGuid  = MAKE_NEW_GUID(fields[2].GetUInt32(), 0, HIGHGUID_PLAYER);
    Type = fields[3].GetUInt32();
    BackgroundColor = fields[4].GetUInt32();
    EmblemStyle = fields[5].GetUInt32();
    EmblemColor = fields[6].GetUInt32();
    BorderStyle = fields[7].GetUInt32();
    BorderColor = fields[8].GetUInt32();

    delete result;

    // only load here, so additional checks can be made
    LoadStatsFromDB(ArenaTeamId);
    LoadMembersFromDB(ArenaTeamId);

    if(!GetMembersSize())
    {
        // arena team is empty, delete from db
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM arena_team WHERE arenateamid = '%u'", ArenaTeamId);
        CharacterDatabase.PExecute("DELETE FROM arena_team_member WHERE arenateamid = '%u'", ArenaTeamId);
        CharacterDatabase.PExecute("DELETE FROM arena_team_stats WHERE arenateamid = '%u'", ArenaTeamId);
        CharacterDatabase.CommitTransaction();
        // return false
        return false;
    }

    return true;
}

void ArenaTeam::LoadStatsFromDB(uint32 ArenaTeamId)
{
    //                                                     0      1     2    3      4     5
    QueryResult *result = CharacterDatabase.PQuery("SELECT rating,games,wins,played,wins2,rank FROM arena_team_stats WHERE arenateamid = '%u'", ArenaTeamId);

    if(!result)
        return;

    Field *fields = result->Fetch();

    stats.rating    = fields[0].GetUInt32();
    stats.games     = fields[1].GetUInt32();
    stats.wins      = fields[2].GetUInt32();
    stats.played    = fields[3].GetUInt32();
    stats.wins2     = fields[4].GetUInt32();
    stats.rank      = fields[5].GetUInt32();

    delete result;
}

void ArenaTeam::LoadMembersFromDB(uint32 ArenaTeamId)
{
    Field *fields;

    QueryResult *result = CharacterDatabase.PQuery("SELECT guid,played_week,wons_week,played_season,wons_season,points_to_add FROM arena_team_member WHERE arenateamid = '%u'", ArenaTeamId);
    if(!result)
        return;

    do
    {
        fields = result->Fetch();
        ArenaTeamMember newmember;
        newmember.guid          = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);
        // check if this member is in this arenateam
        // based on character data field
        if(Player::GetUInt32ValueFromDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6),newmember.guid) != ArenaTeamId)
        {
            // the player's registered arena team for this slot isn't this team, so delete member info from here
            CharacterDatabase.PExecute("DELETE FROM arena_team_member WHERE guid = '%u' AND arenateamid = '%u'",fields[0].GetUInt32(), ArenaTeamId);
            continue;
        }
        LoadPlayerStats(&newmember);
        newmember.played_week   = fields[1].GetUInt32();
        newmember.wons_week     = fields[2].GetUInt32();
        newmember.played_season = fields[3].GetUInt32();
        newmember.wons_season   = fields[4].GetUInt32();
        members.push_back(newmember);
    }while( result->NextRow() );
    delete result;
}

void ArenaTeam::LoadPlayerStats(ArenaTeamMember *member)
{
    Field *fields;

    QueryResult *result = CharacterDatabase.PQuery("SELECT name,class FROM characters WHERE guid = '%u'", GUID_LOPART(member->guid));
    if(!result)
        return;
    fields = result->Fetch();
    member->name  = fields[0].GetCppString();
    member->Class = fields[1].GetUInt8();

    delete result;
}

void ArenaTeam::SetCaptain(uint64 guid)
{
    // disable remove/promote buttons
    Player *oldcaptain = objmgr.GetPlayer(GetCaptain());
    if(oldcaptain)
        oldcaptain->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6), 1);
    else
        Player::SetUInt32ValueInDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6), 1, GetCaptain());

    // set new captain
    CaptainGuid = guid;

    // update database
    CharacterDatabase.PExecute("UPDATE arena_team SET captainguid = '%u' WHERE arenateamid = '%u'", GUID_LOPART(guid), Id);

    // enable remove/promote buttons
    Player *newcaptain = objmgr.GetPlayer(guid);
    if(newcaptain)
        newcaptain->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6), 0);
    else
        Player::SetUInt32ValueInDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 1 + (GetSlot() * 6), 0, guid);
}

void ArenaTeam::DelMember(uint64 guid)
{
    MemberList::iterator itr;
    for (itr = members.begin(); itr != members.end(); itr++)
    {
        if (itr->guid == guid)
        {
            members.erase(itr);
            break;
        }
    }

    Player *player = objmgr.GetPlayer(guid);
    // this will be ugly. because of the asynchronous sql handling, we have to set all the fields of the player at once, and save them at once, or else the save will only modify the last field.
    // rip off of setuint32valueindb
    if(player)
    {
        player->SetInArenaTeam(0, GetSlot());
        player->GetSession()->SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, GetName(), "", 0);
        // delete all info regarding this team
        for(int i = 0; i < 6; ++i)
        {
            player->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6) + i, 0);
        }
    }

    // we have to do it this way, setuint32valueindb is asynch, unsafe to use multiple times in a row on the same player
    Tokens tokens;
    if(!Player::LoadValuesArrayFromDB(tokens,guid))
        return;

    for(int i = 0; i < 6; ++i)
    {
        uint16 index = PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot() * 6) + i;
        char buf[11];
        snprintf(buf,11,"%u",0);
        tokens[index] = buf;
    }

    Player::SaveValuesArrayInDB(tokens,guid);

    // only delete from this arena team!
    CharacterDatabase.PExecute("DELETE FROM arena_team_member WHERE arenateamid = '%u' AND guid = '%u'", GetId(), GUID_LOPART(guid));
}

void ArenaTeam::Disband(WorldSession *session)
{
    // event
    WorldPacket data;
    session->BuildArenaTeamEventPacket(&data, ERR_ARENA_TEAM_DISBANDED_S, 2, session->GetPlayerName(), GetName(), "");
    BroadcastPacket(&data);

    uint32 count = members.size();
    uint64 *memberGuids = new uint64[count];

    MemberList::iterator itr;
    uint32 i=0;
    for(itr = members.begin(); itr != members.end(); itr++)
    {
        memberGuids[i] = itr->guid;
        ++i;
    }

    for(uint32 j = 0; j < count; j++)
        DelMember(memberGuids[j]);
    delete[] memberGuids;

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM arena_team WHERE arenateamid = '%u'", Id);
    CharacterDatabase.PExecute("DELETE FROM arena_team_member WHERE arenateamid = '%u'", Id);
    CharacterDatabase.PExecute("DELETE FROM arena_team_stats WHERE arenateamid = '%u'", Id);
    CharacterDatabase.CommitTransaction();
    objmgr.RemoveArenaTeam(this);
}

void ArenaTeam::Roster(WorldSession *session)
{
    Player *pl = NULL;

    WorldPacket data(SMSG_ARENA_TEAM_ROSTER, 100);
    data << uint32(GetId());                                // arena team id
    data << uint32(GetMembersSize());                       // members count
    data << uint32(GetType());                              // arena team type?

    for (MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        pl = objmgr.GetPlayer(itr->guid);
        if(pl)
        {
            data << uint64(pl->GetGUID());                  // guid
            data << uint8(1);                               // online flag
            data << pl->GetName();                          // member name
            data << uint32(itr->guid == GetCaptain() ? 0 : 1);// unknown
            data << uint8(pl->getLevel());                  // unknown, probably level
            data << uint8(pl->getClass());                  // class
            data << uint32(itr->played_week);               // played this week
            data << uint32(itr->wons_week);                 // wins this week
            data << uint32(itr->played_season);             // played this season
            data << uint32(itr->wons_season);               // wins this season
            data << uint32(pl->GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + GetSlot() * 6 + 5));                              // personal rating?
        }
        else
        {
            data << uint64(itr->guid);                      // guid
            data << uint8(0);                               // online flag
            data << itr->name;                              // member name
            data << uint32(itr->guid == GetCaptain() ? 0 : 1);// unknown
            data << uint8(0);                               // unknown, level?
            data << uint8(itr->Class);                      // class
            data << uint32(itr->played_week);               // played this week
            data << uint32(itr->wons_week);                 // wins this week
            data << uint32(itr->played_season);             // played this season
            data << uint32(itr->wons_season);               // wins this season
            data << uint32(Player::GetUInt32ValueFromDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + GetSlot() * 6 + 5, itr->guid));                              // personal rating?
        }
    }
    session->SendPacket(&data);
    sLog.outDebug("WORLD: Sent SMSG_ARENA_TEAM_ROSTER");
}

void ArenaTeam::Query(WorldSession *session)
{
    WorldPacket data(SMSG_ARENA_TEAM_QUERY_RESPONSE, 4*7+GetName().size()+1);
    data << uint32(GetId());                                // team id
    data << GetName();                                      // team name
    data << uint32(GetType());                              // arena team type (2=2x2, 3=3x3 or 5=5x5)
    data << uint32(BackgroundColor);                        // background color
    data << uint32(EmblemStyle);                            // emblem style
    data << uint32(EmblemColor);                            // emblem color
    data << uint32(BorderStyle);                            // border style
    data << uint32(BorderColor);                            // border color
    session->SendPacket(&data);
    sLog.outDebug("WORLD: Sent SMSG_ARENA_TEAM_QUERY_RESPONSE");
}

void ArenaTeam::Stats(WorldSession *session)
{
    WorldPacket data(SMSG_ARENA_TEAM_STATS, 4*7);
    data << uint32(GetId());                                // arena team id
    data << uint32(stats.rating);                           // rating
    data << uint32(stats.games);                            // games
    data << uint32(stats.wins);                             // wins
    data << uint32(stats.played);                           // played
    data << uint32(stats.wins2);                            // wins(again o_O)
    data << uint32(stats.rank);                             // rank
    session->SendPacket(&data);
}

void ArenaTeam::NotifyStatsChanged()
{
    // this is called after a rated match ended
    // updates arena team stats for every member of the team (not only the ones who participated!)
    for(MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        Player * plr=objmgr.GetPlayer(itr->guid);
        if(plr)
            Stats(plr->GetSession());
    }
}

void ArenaTeam::InspectStats(WorldSession *session, uint64 guid)
{
    WorldPacket data(MSG_INSPECT_ARENA_TEAMS, 8+1+4*6);
    data << uint64(guid);                                   // player guid
    data << uint8(GetSlot());                               // slot (0...2)
    data << uint32(GetId());                                // arena team id
    data << uint32(stats.rating);                           // rating
    data << uint32(stats.played);                           // season played
    data << uint32(stats.wins2);                            // season wins
    uint32 participated = 0;
    for(MemberList::iterator itr = members.begin(); itr!= members.end(); ++itr)
    {
        if(itr->guid == guid)
        {
            participated = itr->played_season;
            break;
        }
    }
    data << uint32(participated);                            // played (count of all games, that the inspected member participated...)
    data << uint32(Player::GetUInt32ValueFromDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + GetSlot() * 6 + 5, guid));                                       // unk, 2.3.3 (personal rating?)

    session->SendPacket(&data);
}

void ArenaTeam::SetEmblem(uint32 backgroundColor, uint32 emblemStyle, uint32 emblemColor, uint32 borderStyle, uint32 borderColor)
{
    BackgroundColor = backgroundColor;
    EmblemStyle = emblemStyle;
    EmblemColor = emblemColor;
    BorderStyle = borderStyle;
    BorderColor = borderColor;

    CharacterDatabase.PExecute("UPDATE arena_team SET BackgroundColor='%u', EmblemStyle='%u', EmblemColor='%u', BorderStyle='%u', BorderColor='%u' WHERE arenateamid='%u'", BackgroundColor, EmblemStyle, EmblemColor, BorderStyle, BorderColor, Id);
}

void ArenaTeam::SetStats(uint32 stat_type, uint32 value)
{
    switch(stat_type)
    {
        case STAT_TYPE_RATING:
            stats.rating = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET rating = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        case STAT_TYPE_GAMES:
            stats.games = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET games = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        case STAT_TYPE_WINS:
            stats.wins = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET wins = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        case STAT_TYPE_PLAYED:
            stats.played = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET played = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        case STAT_TYPE_WINS2:
            stats.wins2 = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET wins2 = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        case STAT_TYPE_RANK:
            stats.rank = value;
            CharacterDatabase.PExecute("UPDATE arena_team_stats SET rank = '%u' WHERE arenateamid = '%u'", value, GetId());
            break;
        default:
            sLog.outDebug("unknown stat type in ArenaTeam::SetStats() %u", stat_type);
            break;
    }
}

uint8 ArenaTeam::GetSlot() const
{
    uint8 slot = GetSlotByType(GetType());
    if(slot >= MAX_ARENA_SLOT)
    {
        sLog.outError("Unknown arena team type %u for arena team %u", uint32(GetType()), GetId());
        return 0;                                           // better return existed slot to prevent untelated data curruption
    }

    return slot;
}

void ArenaTeam::BroadcastPacket(WorldPacket *packet)
{
    for (MemberList::iterator itr = members.begin(); itr != members.end(); itr++)
    {
        Player *player = objmgr.GetPlayer(itr->guid);
        if(player)
            player->GetSession()->SendPacket(packet);
    }
}

uint8 ArenaTeam::GetSlotByType( uint32 type )
{
    switch(type)
    {
        case ARENA_TEAM_2v2: return 0;
        case ARENA_TEAM_3v3: return 1;
        case ARENA_TEAM_5v5: return 2;
        default:
            break;
    }
    return 0xFF;
}

bool ArenaTeam::HaveMember( uint64 guid ) const
{
    for (MemberList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
        if(itr->guid==guid)
            return true;

    return false;
}

uint32 ArenaTeam::GetPoints(uint32 MemberRating)
{
    // returns how many points would be awarded with this team type with this rating
    float points;

    uint32 rating = MemberRating + 150 < stats.rating ? MemberRating : stats.rating;

    if(rating<=1500)
    {
        points = (float)rating * 0.22f + 14.0f;
    }
    else
    {
        points = 1511.26f / (1.0f + 1639.28f * exp(-0.00412f * (float)rating));
    }

    // type penalties for <5v5 teams
    if(Type == ARENA_TEAM_2v2)
        points *= 0.76f;
    else if(Type == ARENA_TEAM_3v3)
        points *= 0.88f;

    return (uint32) points;
}

float ArenaTeam::GetChanceAgainst(uint32 rating)
{
    // returns the chance to win against a team with the given rating, used in the rating adjustment calculation
    // ELO system
    return 1.0f/(1.0f+exp(log(10.0f)*(float)((float)rating - (float)stats.rating)/400.0f));
}

int32 ArenaTeam::WonAgainstChance(float chance)
{
    // called when the team has won, and had 'chance' calculated chance to beat the opponent
    // calculate the rating modification (ELO system with k=32)
    int32 mod = (int32)floor(32.0f * (1.0f - chance));
    // modify the team stats accordingly
    stats.rating += mod;
    stats.games += 1;
    stats.wins += 1;
    stats.played += 1;
    stats.wins2 += 1;
/*  this should be done in .flusharenapoints; not a breaker though.
    uint32 higher_rank = 0;
    QueryResult *result = CharacterDatabase.PQuery("SELECT DISTINCT COUNT(arenateamid) FROM arena_team_stats WHERE rating > '%u' AND arenateamid <> '%u'",stats.rating, Id);
    if(result)
    {
        higher_rank = result->Fetch()->GetUInt32();
        delete result;
    }
    stats.rank = higher_rank + 1;*/
    // return the rating change, used to display it on the results screen
    return mod;
}

int32 ArenaTeam::LostAgainstChance(float chance)
{
    // called when the team has lost, and had 'chance' calculated chance to beat the opponent
    // calculate the rating modification (ELO system with k=32)
    int32 mod = (int32)ceil(32.0f * (0.0f - chance));
    // modify the team stats accordingly
    stats.rating += mod;
    stats.games += 1;
    stats.played += 1;
/*    uint32 higher_rank = 0;
    QueryResult *result = CharacterDatabase.PQuery("SELECT DISTINCT COUNT (arenateamid) FROM arena_team_stats WHERE rating > '%u' AND arenateamid <> '%u'",stats.rating, Id);
    if(result)
    {
        higher_rank = result->Fetch()->GetUInt32();
        delete result;
    }
    stats.rank = higher_rank + 1;*/
    // return the rating adjustment for display
    return mod;
}

void ArenaTeam::MemberLost(Player * plr, uint32 againstrating)
{
    // called for each participant of a match after losing
    for(MemberList::iterator itr = members.begin(); itr !=  members.end(); ++itr)
    {
        if(itr->guid == plr->GetGUID())
        {
            // update personal rating
            int32 personalrating = plr->GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5);
            float chance = 1.0f/(1.0f+exp(log(10.0f)*(float)((float)againstrating - (float)personalrating)/400.0f));
            int32 mod = (int32)ceil(32.0f * (0.0f - chance));
            personalrating += mod;
            if(personalrating < 0)
                personalrating = 0;
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5, personalrating);
            // update personal played stats
            itr->played_week +=1;
            itr->played_season +=1;
            // update the unit fields
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 6 * GetSlot() + 2, itr->played_week);
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 6 * GetSlot() + 3, itr->played_season);
            return;
        }
    }
}

void ArenaTeam::MemberWon(Player * plr, uint32 againstrating)
{
    // called for each participant after winning a match
    for(MemberList::iterator itr = members.begin(); itr !=  members.end(); ++itr)
    {
        if(itr->guid == plr->GetGUID())
        {
            // update personal rating
            int32 personalrating = plr->GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5);
            float chance = 1.0f/(1.0f+exp(log(10.0f)*(float)((float)againstrating - (float)personalrating)/400.0f));
            int32 mod = (int32)floor(32.0f * (1.0f - chance));
            personalrating += mod;
            if(personalrating < 0)
                personalrating = 0;
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5, personalrating);
            // update personal stats
            itr->played_week +=1;
            itr->played_season +=1;
            itr->wons_season += 1;
            itr->wons_week += 1;
            // update unit fields
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 6 * GetSlot() + 2, itr->played_week);
            plr->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + 6 * GetSlot() + 3, itr->played_season);
            return;
        }
    }
}

void ArenaTeam::UpdateArenaPointsHelper()
{
    // called after a match has ended and the stats are already modified
    // helper function for arena point distribution (this way, when distributing, no actual calculation is required, just a few comparisons)
    // 10 played games per week is a minimum
    if(stats.games < 10)
        return;
    // to get points, a player has to participate in at least 30% of the matches
    uint32 min_plays = (uint32)ceil(stats.games * 0.3);
    for(MemberList::iterator itr = members.begin(); itr !=  members.end(); ++itr)
    {
        // the player participated in enough games, update his points
        if(itr->played_week >= min_plays)
        {
            // do it separately for online and offline players
            // online players might have modified personal rating in MemberLost/MemberWon, that's not already saved to DB because of asynch queries
            // offline player cant have a personal rating not matching the db
            Player * plr = objmgr.GetPlayer(itr->guid);
            uint32 points_to_add = 0;
            if(plr)
                points_to_add = GetPoints(plr->GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5));
            else
                points_to_add = GetPoints(Player::GetUInt32ValueFromDB(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (GetSlot()*6) + 5,itr->guid));
            // it's enough to set the points in memory, the saving is done in separate function
            CharacterDatabase.PExecute("UPDATE arena_team_member SET points_to_add = '%u' WHERE arenateamid = '%u' AND guid = '%u'", points_to_add, Id, itr->guid);
        }
        // the player failed to participate in enough games, so no points for him
        else
        {
            CharacterDatabase.PExecute("UPDATE arena_team_member SET points_to_add = '%u' WHERE arenateamid = '%u' AND guid = '%u'", 0, Id, itr->guid);
        }
    }
}

void ArenaTeam::SaveToDB()
{
    // save team and member stats to db
    // called after a match has ended
    CharacterDatabase.PExecute("UPDATE arena_team_stats SET rating = '%u',games = '%u',played = '%u',rank = '%u',wins = '%u',wins2 = '%u' WHERE arenateamid = '%u'", stats.rating, stats.games, stats.played, stats.rank, stats.wins, stats.wins2, GetId());
    for(MemberList::iterator itr = members.begin(); itr !=  members.end(); ++itr)
    {
        CharacterDatabase.PExecute("UPDATE arena_team_member SET played_week = '%u', wons_week = '%u', played_season = '%u', wons_season = '%u' WHERE arenateamid = '%u' AND guid = '%u'", itr->played_week, itr->wons_week, itr->played_season, itr->wons_season, Id, itr->guid);
    }
}

void ArenaTeam::FinishWeek()
{
    stats.games = 0; // played this week
    stats.wins = 0; // wins this week
    for(MemberList::iterator itr = members.begin(); itr !=  members.end(); ++itr)
    {
        itr->played_week = 0;
        itr->wons_week = 0;
    }
}

/*
arenateam fields (id from 2.3.3 client):
1414 - arena team id 2v2
1415 - 0=captain, 1=member
1416 - played this week
1417 - played this season
1418 - unk
1419 - personal arena rating
1420 - arena team id 3v3
1421 - 0=captain, 1=member
1422 - played this week
1423 - played this season
1424 - unk
1425 - personal arena rating
1426 - arena team id 5v5
1427 - 0=captain, 1=member
1428 - played this week
1429 - played this season
1430 - unk
1431 - personal arena rating
*/
