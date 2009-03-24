/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Player.h"
#include "Opcodes.h"
#include "ObjectMgr.h"
#include "Guild.h"
#include "Chat.h"
#include "SocialMgr.h"
#include "Util.h"
#include "Language.h"

Guild::Guild()
{
    Id = 0;
    name = "";
    leaderGuid = 0;
    GINFO = MOTD = "";
    EmblemStyle = 0;
    EmblemColor = 0;
    BorderStyle = 0;
    BorderColor = 0;
    BackgroundColor = 0;

    CreatedYear = 0;
    CreatedMonth = 0;
    CreatedDay = 0;
}

Guild::~Guild()
{

}

bool Guild::create(Player* leader, std::string gname)
{
    if(objmgr.GetGuildByName(gname))
        return false;

    WorldSession* lSession = leader->GetSession();
    if(!lSession)
        return false;

    leaderGuid = leader->GetGUID();
    name = gname;
    GINFO = "";
    MOTD = "No message set.";
    guildbank_money = 0;
    purchased_tabs = 0;
    Id = objmgr.GenerateGuildId();

    sLog.outDebug("GUILD: creating guild %s to leader: %u", gname.c_str(), GUID_LOPART(leaderGuid));

    // gname already assigned to Guild::name, use it to encode string for DB
    CharacterDatabase.escape_string(gname);

    std::string dbGINFO = GINFO;
    std::string dbMOTD = MOTD;
    CharacterDatabase.escape_string(dbGINFO);
    CharacterDatabase.escape_string(dbMOTD);

    CharacterDatabase.BeginTransaction();
    // CharacterDatabase.PExecute("DELETE FROM guild WHERE guildid='%u'", Id); - MAX(guildid)+1 not exist
    CharacterDatabase.PExecute("DELETE FROM guild_rank WHERE guildid='%u'", Id);
    CharacterDatabase.PExecute("DELETE FROM guild_member WHERE guildid='%u'", Id);
    CharacterDatabase.PExecute("INSERT INTO guild (guildid,name,leaderguid,info,motd,createdate,EmblemStyle,EmblemColor,BorderStyle,BorderColor,BackgroundColor,BankMoney) "
        "VALUES('%u','%s','%u', '%s', '%s', NOW(),'%u','%u','%u','%u','%u','" I64FMTD "')",
        Id, gname.c_str(), GUID_LOPART(leaderGuid), dbGINFO.c_str(), dbMOTD.c_str(), EmblemStyle, EmblemColor, BorderStyle, BorderColor, BackgroundColor, guildbank_money);
    CharacterDatabase.CommitTransaction();

    CreateRank(lSession->GetMangosString(LANG_GUILD_MASTER),  GR_RIGHT_ALL);
    CreateRank(lSession->GetMangosString(LANG_GUILD_OFFICER), GR_RIGHT_ALL);
    CreateRank(lSession->GetMangosString(LANG_GUILD_VETERAN), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    CreateRank(lSession->GetMangosString(LANG_GUILD_MEMBER),  GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    CreateRank(lSession->GetMangosString(LANG_GUILD_INITIATE),GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);

    return AddMember(leaderGuid, (uint32)GR_GUILDMASTER);
}

bool Guild::AddMember(uint64 plGuid, uint32 plRank)
{
    Player* pl = objmgr.GetPlayer(plGuid);
    if(pl)
    {
        if(pl->GetGuildId() != 0)
            return false;
    }
    else
    {
        if(Player::GetGuildIdFromDB(plGuid) != 0)           // player already in guild
            return false;
    }

    // remove all player signs from another petitions
    // this will be prevent attempt joining player to many guilds and corrupt guild data integrity
    Player::RemovePetitionsAndSigns(plGuid, 9);

    // fill player data
    MemberSlot newmember;

    if(!FillPlayerData(plGuid, &newmember))                 // problems with player data collection
        return false;

    newmember.RankId = plRank;
    newmember.OFFnote = (std::string)"";
    newmember.Pnote = (std::string)"";
    newmember.logout_time = time(NULL);
    newmember.BankResetTimeMoney = 0;                       // this will force update at first query
    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
        newmember.BankResetTimeTab[i] = 0;
    members[GUID_LOPART(plGuid)] = newmember;

    std::string dbPnote = newmember.Pnote;
    std::string dbOFFnote = newmember.OFFnote;
    CharacterDatabase.escape_string(dbPnote);
    CharacterDatabase.escape_string(dbOFFnote);

    CharacterDatabase.PExecute("INSERT INTO guild_member (guildid,guid,rank,pnote,offnote) VALUES ('%u', '%u', '%u','%s','%s')",
        Id, GUID_LOPART(plGuid), newmember.RankId, dbPnote.c_str(), dbOFFnote.c_str());

    // If player not in game data in data field will be loaded from guild tables, no need to update it!!
    if(pl)
    {
        pl->SetInGuild(Id);
        pl->SetRank(newmember.RankId);
        pl->SetGuildIdInvited(0);
    }
    return true;
}

void Guild::SetMOTD(std::string motd)
{
    MOTD = motd;

    // motd now can be used for encoding to DB
    CharacterDatabase.escape_string(motd);
    CharacterDatabase.PExecute("UPDATE guild SET motd='%s' WHERE guildid='%u'", motd.c_str(), Id);
}

void Guild::SetGINFO(std::string ginfo)
{
    GINFO = ginfo;

    // ginfo now can be used for encoding to DB
    CharacterDatabase.escape_string(ginfo);
    CharacterDatabase.PExecute("UPDATE guild SET info='%s' WHERE guildid='%u'", ginfo.c_str(), Id);
}

bool Guild::LoadGuildFromDB(uint32 GuildId)
{
    if(!LoadRanksFromDB(GuildId))
        return false;

    if(!LoadMembersFromDB(GuildId))
        return false;

    QueryResult *result = CharacterDatabase.PQuery("SELECT MAX(TabId) FROM guild_bank_tab WHERE guildid='%u'", GuildId);
    if(result)
    {
        Field *fields = result->Fetch();
        purchased_tabs = fields[0].GetUInt8()+1;            // Because TabId begins at 0
        delete result;
    }
    else
        purchased_tabs = 0;

    LoadBankRightsFromDB(GuildId);                          // Must be after LoadRanksFromDB because it populates rank struct

    //                                        0        1     2           3            4            5           6
    result = CharacterDatabase.PQuery("SELECT guildid, name, leaderguid, EmblemStyle, EmblemColor, BorderStyle, BorderColor,"
    //   7                8     9     10          11
        "BackgroundColor, info, motd, createdate, BankMoney FROM guild WHERE guildid = '%u'", GuildId);

    if(!result)
        return false;

    Field *fields = result->Fetch();

    Id = fields[0].GetUInt32();
    name = fields[1].GetCppString();
    leaderGuid  = MAKE_NEW_GUID(fields[2].GetUInt32(), 0, HIGHGUID_PLAYER);

    EmblemStyle = fields[3].GetUInt32();
    EmblemColor = fields[4].GetUInt32();
    BorderStyle = fields[5].GetUInt32();
    BorderColor = fields[6].GetUInt32();
    BackgroundColor = fields[7].GetUInt32();
    GINFO = fields[8].GetCppString();
    MOTD = fields[9].GetCppString();
    uint64 time = fields[10].GetUInt64();                   //datetime is uint64 type ... YYYYmmdd:hh:mm:ss
    guildbank_money = fields[11].GetUInt64();

    delete result;

    uint64 dTime = time /1000000;
    CreatedDay   = dTime%100;
    CreatedMonth = (dTime/100)%100;
    CreatedYear  = (dTime/10000)%10000;

    // If the leader does not exist attempt to promote another member
    if(!objmgr.GetPlayerAccountIdByGUID(leaderGuid ))
    {
        DelMember(leaderGuid);

        // check no members case (disbanded)
        if(members.empty())
            return false;
    }

    sLog.outDebug("Guild %u Creation time Loaded day: %u, month: %u, year: %u", GuildId, CreatedDay, CreatedMonth, CreatedYear);
    m_bankloaded = false;
    m_eventlogloaded = false;
    m_onlinemembers = 0;
    RenumBankLogs();
    RenumGuildEventlog();
    return true;
}

bool Guild::LoadRanksFromDB(uint32 GuildId)
{
    Field *fields;
    QueryResult *result = CharacterDatabase.PQuery("SELECT rname,rights,BankMoneyPerDay,rid FROM guild_rank WHERE guildid = '%u' ORDER BY rid ASC", GuildId);

    if(!result)
        return false;

    bool broken_ranks = false;

    do
    {
        fields = result->Fetch();

        std::string rankName = fields[0].GetCppString();
        uint32 rankRights    = fields[1].GetUInt32();
        uint32 rankMoney     = fields[2].GetUInt32();
        uint32 rankRID       = fields[3].GetUInt32();

        if(rankRID != m_ranks.size()+1)                     // guild_rank.rid always store rank+1
            broken_ranks =  true;

        if(m_ranks.size()==GR_GUILDMASTER)                  // prevent loss leader rights
            rankRights |= GR_RIGHT_ALL;

        AddRank(rankName,rankRights,rankMoney);
    }while( result->NextRow() );
    delete result;

    if(m_ranks.size()==0)                                   // empty rank table?
    {
        AddRank("Guild Master",GR_RIGHT_ALL,0);
        broken_ranks = true;
    }

    // guild_rank have wrong numbered ranks, repair
    if(broken_ranks)
    {
        sLog.outError("Guild %u have broken `guild_rank` data, repairing...",GuildId);
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM guild_rank WHERE guildid='%u'", GuildId);
        for(size_t i =0; i < m_ranks.size(); ++i)
        {
            // guild_rank.rid always store rank+1
            std::string name = m_ranks[i].name;
            uint32 rights = m_ranks[i].rights;
            CharacterDatabase.escape_string(name);
            CharacterDatabase.PExecute( "INSERT INTO guild_rank (guildid,rid,rname,rights) VALUES ('%u', '%u', '%s', '%u')", GuildId, i+1, name.c_str(), rights);
        }
        CharacterDatabase.CommitTransaction();
    }

    return true;
}

bool Guild::LoadMembersFromDB(uint32 GuildId)
{
    //                                                     0                 1     2      3        4                  5
    QueryResult *result = CharacterDatabase.PQuery("SELECT guild_member.guid,rank, pnote, offnote, BankResetTimeMoney,BankRemMoney,"
    //   6                  7                 8                  9                 10                 11
        "BankResetTimeTab0, BankRemSlotsTab0, BankResetTimeTab1, BankRemSlotsTab1, BankResetTimeTab2, BankRemSlotsTab2,"
    //   12                 13                14                 15                16                 17
        "BankResetTimeTab3, BankRemSlotsTab3, BankResetTimeTab4, BankRemSlotsTab4, BankResetTimeTab5, BankRemSlotsTab5,"
    //   18
        "logout_time FROM guild_member LEFT JOIN characters ON characters.guid = guild_member.guid WHERE guildid = '%u'", GuildId);

    if(!result)
        return false;

    do
    {
        Field *fields = result->Fetch();
        MemberSlot newmember;
        newmember.RankId = fields[1].GetUInt32();
        uint64 guid = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);

        // Player does not exist
        if(!FillPlayerData(guid, &newmember))
            continue;

        newmember.Pnote                 = fields[2].GetCppString();
        newmember.OFFnote               = fields[3].GetCppString();
        newmember.BankResetTimeMoney    = fields[4].GetUInt32();
        newmember.BankRemMoney          = fields[5].GetUInt32();
        for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
        {
            newmember.BankResetTimeTab[i] = fields[6+(2*i)].GetUInt32();
            newmember.BankRemSlotsTab[i]  = fields[7+(2*i)].GetUInt32();
        }
        newmember.logout_time           = fields[18].GetUInt64();
        members[GUID_LOPART(guid)]      = newmember;

    }while( result->NextRow() );
    delete result;

    if(members.empty())
        return false;

    return true;
}

bool Guild::FillPlayerData(uint64 guid, MemberSlot* memslot)
{
    std::string plName;
    uint32 plLevel;
    uint32 plClass;
    uint32 plZone;

    Player* pl = objmgr.GetPlayer(guid);
    if(pl)
    {
        plName  = pl->GetName();
        plLevel = pl->getLevel();
        plClass = pl->getClass();
        plZone  = pl->GetZoneId();
    }
    else
    {
        PCachePlayerInfo pInfo = objmgr.GetPlayerInfoFromCache(GUID_LOPART(guid));
        if(pInfo)
        {
            plName = pInfo->sPlayerName;
            plClass = pInfo->unClass;
            if(plClass<CLASS_WARRIOR||plClass>=MAX_CLASSES)     // can be at broken `class` field
            {
                sLog.outError("Player (GUID: %u) has a broken data in field `characters`.`class`.",GUID_LOPART(guid));
                return false;
            }
            plLevel = pInfo->unLevel;
            plZone = Player::GetZoneIdFromDB(guid);
        }
        else
        {
            QueryResult *result = CharacterDatabase.PQuery("SELECT name,data,zone,class FROM characters WHERE guid = '%u'", GUID_LOPART(guid));
            if(!result)
                return false;                                   // player doesn't exist

            Field *fields = result->Fetch();

            plName = fields[0].GetCppString();

            Tokens data = StrSplit(fields[1].GetCppString(), " ");
            plLevel = Player::GetUInt32ValueFromArray(data,UNIT_FIELD_LEVEL);

            plZone = fields[2].GetUInt32();
            plClass = fields[3].GetUInt32();
            delete result;

        if(plLevel<1||plLevel>STRONG_MAX_LEVEL)             // can be at broken `data` field
        {
            sLog.outError("Player (GUID: %u) has a broken data in field `characters`.`data`.",GUID_LOPART(guid));
            return false;
        }

        if(!plZone)
        {
            sLog.outError("Player (GUID: %u) has broken zone-data",GUID_LOPART(guid));
            //here it will also try the same, to get the zone from characters-table, but additional it tries to find
            plZone = Player::GetZoneIdFromDB(guid);
            //the zone through xy coords.. this is a bit redundant, but
            //shouldn't be called often
        }

        if(plClass<CLASS_WARRIOR||plClass>=MAX_CLASSES)     // can be at broken `class` field
        {
            sLog.outError("Player (GUID: %u) has a broken data in field `characters`.`class`.",GUID_LOPART(guid));
            return false;
        }
    }
    }

    memslot->name = plName;
    memslot->level = plLevel;
    memslot->Class = plClass;
    memslot->zoneId = plZone;

    return(true);
}

void Guild::LoadPlayerStatsByGuid(uint64 guid)
{
    MemberList::iterator itr = members.find(GUID_LOPART(guid));
    if (itr == members.end() )
        return;

    Player *pl = ObjectAccessor::FindPlayer(guid);
    if(!pl)
        return;
    itr->second.name  = pl->GetName();
    itr->second.level = pl->getLevel();
    itr->second.Class = pl->getClass();
}

void Guild::SetLeader(uint64 guid)
{
    leaderGuid = guid;
    ChangeRank(guid, GR_GUILDMASTER);

    CharacterDatabase.PExecute("UPDATE guild SET leaderguid='%u' WHERE guildid='%u'", GUID_LOPART(guid), Id);
}

void Guild::DelMember(uint64 guid, bool isDisbanding)
{
    if(leaderGuid == guid && !isDisbanding)
    {
        MemberSlot* oldLeader = NULL;
        MemberSlot* best = NULL;
        uint64 newLeaderGUID = 0;
        for(Guild::MemberList::iterator i = members.begin(); i != members.end(); ++i)
        {
            if(i->first == GUID_LOPART(guid))
            {
                oldLeader = &(i->second);
                continue;
            }

            if(!best || best->RankId > i->second.RankId)
            {
                best = &(i->second);
                newLeaderGUID = i->first;
            }
        }
        if(!best)
        {
            Disband();
            return;
        }

        SetLeader(newLeaderGUID);

        // If player not online data in data field will be loaded from guild tabs no need to update it !!
        if(Player *newLeader = objmgr.GetPlayer(newLeaderGUID))
            newLeader->SetRank(GR_GUILDMASTER);

        // when leader non-exist (at guild load with deleted leader only) not send broadcasts
        if(oldLeader)
        {
            WorldPacket data(SMSG_GUILD_EVENT, (1+1+(oldLeader->name).size()+1+(best->name).size()+1));
            data << (uint8)GE_LEADER_CHANGED;
            data << (uint8)2;
            data << oldLeader->name;
            data << best->name;
            BroadcastPacket(&data);

            data.Initialize(SMSG_GUILD_EVENT, (1+1+(oldLeader->name).size()+1));
            data << (uint8)GE_LEFT;
            data << (uint8)1;
            data << oldLeader->name;
            BroadcastPacket(&data);
        }

        sLog.outDebug( "WORLD: Sent (SMSG_GUILD_EVENT)" );
    }

    members.erase(GUID_LOPART(guid));

    Player *player = objmgr.GetPlayer(guid);
    // If player not online data in data field will be loaded from guild tabs no need to update it !!
    if(player)
    {
        player->SetInGuild(0);
        player->SetRank(0);
    }

    CharacterDatabase.PExecute("DELETE FROM guild_member WHERE guid = '%u'", GUID_LOPART(guid));
}

void Guild::ChangeRank(uint64 guid, uint32 newRank)
{
    MemberList::iterator itr = members.find(GUID_LOPART(guid));
    if( itr != members.end() )
        itr->second.RankId = newRank;

    Player *player = objmgr.GetPlayer(guid);
    // If player not online data in data field will be loaded from guild tabs no need to update it !!
    if(player)
        player->SetRank(newRank);

    CharacterDatabase.PExecute( "UPDATE guild_member SET rank='%u' WHERE guid='%u'", newRank, GUID_LOPART(guid) );
}

void Guild::SetPNOTE(uint64 guid,std::string pnote)
{
    MemberList::iterator itr = members.find(GUID_LOPART(guid));
    if( itr == members.end() )
        return;

    itr->second.Pnote = pnote;

    // pnote now can be used for encoding to DB
    CharacterDatabase.escape_string(pnote);
    CharacterDatabase.PExecute("UPDATE guild_member SET pnote = '%s' WHERE guid = '%u'", pnote.c_str(), itr->first);
}

void Guild::SetOFFNOTE(uint64 guid,std::string offnote)
{
    MemberList::iterator itr = members.find(GUID_LOPART(guid));
    if( itr == members.end() )
        return;
    itr->second.OFFnote = offnote;
    // offnote now can be used for encoding to DB
    CharacterDatabase.escape_string(offnote);
    CharacterDatabase.PExecute("UPDATE guild_member SET offnote = '%s' WHERE guid = '%u'", offnote.c_str(), itr->first);
}

void Guild::BroadcastToGuild(WorldSession *session, const std::string& msg, uint32 language)
{
    if (session && session->GetPlayer() && HasRankRight(session->GetPlayer()->GetRank(),GR_RIGHT_GCHATSPEAK))
    {
        WorldPacket data;
        ChatHandler(session).FillMessageData(&data, CHAT_MSG_GUILD, language, 0, msg.c_str());

        for (MemberList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
        {
            Player *pl = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));

            if (pl && pl->GetSession() && HasRankRight(pl->GetRank(),GR_RIGHT_GCHATLISTEN) && !pl->GetSocial()->HasIgnore(session->GetPlayer()->GetGUIDLow()) )
                pl->GetSession()->SendPacket(&data);
        }
    }
}

void Guild::BroadcastToOfficers(WorldSession *session, const std::string& msg, uint32 language)
{
    if (session && session->GetPlayer() && HasRankRight(session->GetPlayer()->GetRank(),GR_RIGHT_OFFCHATSPEAK))
    {
        for(MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
        {
            WorldPacket data;
            ChatHandler::FillMessageData(&data, session, CHAT_MSG_OFFICER, language, NULL, 0, msg.c_str(),NULL);

            Player *pl = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));

            if (pl && pl->GetSession() && HasRankRight(pl->GetRank(),GR_RIGHT_OFFCHATLISTEN) && !pl->GetSocial()->HasIgnore(session->GetPlayer()->GetGUIDLow()))
                pl->GetSession()->SendPacket(&data);
        }
    }
}

void Guild::BroadcastPacket(WorldPacket *packet)
{
    for(MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
        if(player)
            player->GetSession()->SendPacket(packet);
    }
}

void Guild::BroadcastPacketToRank(WorldPacket *packet, uint32 rankId)
{
    for(MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        if (itr->second.RankId == rankId)
        {
            Player *player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
            if(player)
                player->GetSession()->SendPacket(packet);
        }
    }
}

void Guild::CreateRank(std::string name_,uint32 rights)
{
    if(m_ranks.size() >= GUILD_MAX_RANKS)
        return;

    AddRank(name_,rights,0);

    for (int i = 0; i < purchased_tabs; ++i)
    {
        CreateBankRightForTab(m_ranks.size()-1, uint8(i));
    }

    // guild_rank.rid always store rank+1 value

    // name now can be used for encoding to DB
    CharacterDatabase.escape_string(name_);
    CharacterDatabase.PExecute( "INSERT INTO guild_rank (guildid,rid,rname,rights) VALUES ('%u', '%u', '%s', '%u')", Id, (unsigned int)m_ranks.size(), name_.c_str(), rights );
}

void Guild::AddRank(const std::string& name_,uint32 rights, uint32 money)
{
    m_ranks.push_back(RankInfo(name_,rights,money));
}

void Guild::DelRank()
{
    if(m_ranks.empty())
        return;

    // guild_rank.rid always store rank+1 value
    uint32 rank = m_ranks.size()-1;
    CharacterDatabase.PExecute("DELETE FROM guild_rank WHERE rid>='%u' AND guildid='%u'", (rank+1), Id);

    m_ranks.pop_back();
}

std::string Guild::GetRankName(uint32 rankId)
{
    if(rankId >= m_ranks.size())
        return "<unknown>";

    return m_ranks[rankId].name;
}

uint32 Guild::GetRankRights(uint32 rankId)
{
    if(rankId >= m_ranks.size())
        return 0;

    return m_ranks[rankId].rights;
}

void Guild::SetRankName(uint32 rankId, std::string name_)
{
    if(rankId >= m_ranks.size())
        return;

    m_ranks[rankId].name = name_;

    // name now can be used for encoding to DB
    CharacterDatabase.escape_string(name_);
    CharacterDatabase.PExecute("UPDATE guild_rank SET rname='%s' WHERE rid='%u' AND guildid='%u'", name_.c_str(), (rankId+1), Id);
}

void Guild::SetRankRights(uint32 rankId, uint32 rights)
{
    if(rankId >= m_ranks.size())
        return;

    m_ranks[rankId].rights = rights;

    CharacterDatabase.PExecute("UPDATE guild_rank SET rights='%u' WHERE rid='%u' AND guildid='%u'", rights, (rankId+1), Id);
}

int32 Guild::GetRank(uint32 LowGuid)
{
    MemberList::iterator itr = members.find(LowGuid);
    if (itr==members.end())
        return -1;

    return itr->second.RankId;
}

void Guild::Disband()
{
    WorldPacket data(SMSG_GUILD_EVENT, 1);
    data << (uint8)GE_DISBANDED;
    BroadcastPacket(&data);

    while (!members.empty())
    {
        MemberList::iterator itr = members.begin();
        DelMember(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER), true);
    }

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM guild WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_rank WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_bank_tab WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_bank_right WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_bank_eventlog WHERE guildid = '%u'",Id);
    CharacterDatabase.PExecute("DELETE FROM guild_eventlog WHERE guildid = '%u'",Id);
    CharacterDatabase.CommitTransaction();
    objmgr.RemoveGuild(Id);
}

void Guild::Roster(WorldSession *session)
{
                                                            // we can only guess size
    WorldPacket data(SMSG_GUILD_ROSTER, (4+MOTD.length()+1+GINFO.length()+1+4+m_ranks.size()*(4+4+GUILD_BANK_MAX_TABS*(4+4))+members.size()*50));
    data << (uint32)members.size();
    data << MOTD;
    data << GINFO;

    data << (uint32)m_ranks.size();
    for (RankList::const_iterator ritr = m_ranks.begin(); ritr != m_ranks.end(); ++ritr)
    {
        data << (uint32)ritr->rights;
        data << (uint32)ritr->BankMoneyPerDay;              // count of: withdraw gold(gold/day) Note: in game set gold, in packet set bronze.
        for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
        {
            data << (uint32)ritr->TabRight[i];              // for TAB_i rights: view tabs = 0x01, deposit items =0x02
            data << (uint32)ritr->TabSlotPerDay[i];         // for TAB_i count of: withdraw items(stack/day)
        }
    }
    for (MemberList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        if (Player *pl = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER)))
        {
            data << (uint64)pl->GetGUID();
            data << (uint8)1;
            data << (std::string)pl->GetName();
            data << (uint32)itr->second.RankId;
            data << (uint8)pl->getLevel();
            data << (uint8)pl->getClass();
            data << (uint8)0;                               // new 2.4.0
            data << (uint32)pl->GetZoneId();
            data << itr->second.Pnote;
            data << itr->second.OFFnote;
        }
        else
        {
            data << uint64(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
            data << (uint8)0;
            data << itr->second.name;
            data << (uint32)itr->second.RankId;
            data << (uint8)itr->second.level;
            data << (uint8)itr->second.Class;
            data << (uint8)0;                               // new 2.4.0
            data << (uint32)itr->second.zoneId;
            data << (float(time(NULL)-itr->second.logout_time) / DAY);
            data << itr->second.Pnote;
            data << itr->second.OFFnote;
        }
    }
    session->SendPacket(&data);;
    sLog.outDebug( "WORLD: Sent (SMSG_GUILD_ROSTER)" );
}

void Guild::Query(WorldSession *session)
{
    WorldPacket data(SMSG_GUILD_QUERY_RESPONSE, (8*32+200));// we can only guess size

    data << Id;
    data << name;

    for (size_t i = 0 ; i < 10; ++i)                        // show always 10 ranks
    {
        if(i < m_ranks.size())
            data << m_ranks[i].name;
        else
            data << (uint8)0;                               // null string
    }

    data << uint32(EmblemStyle);
    data << uint32(EmblemColor);
    data << uint32(BorderStyle);
    data << uint32(BorderColor);
    data << uint32(BackgroundColor);
    data << uint32(0);                                      // something new in WotLK

    session->SendPacket( &data );
    sLog.outDebug( "WORLD: Sent (SMSG_GUILD_QUERY_RESPONSE)" );
}

void Guild::SetEmblem(uint32 emblemStyle, uint32 emblemColor, uint32 borderStyle, uint32 borderColor, uint32 backgroundColor)
{
    EmblemStyle = emblemStyle;
    EmblemColor = emblemColor;
    BorderStyle = borderStyle;
    BorderColor = borderColor;
    BackgroundColor = backgroundColor;

    CharacterDatabase.PExecute("UPDATE guild SET EmblemStyle=%u, EmblemColor=%u, BorderStyle=%u, BorderColor=%u, BackgroundColor=%u WHERE guildid = %u", EmblemStyle, EmblemColor, BorderStyle, BorderColor, BackgroundColor, Id);
}

void Guild::UpdateLogoutTime(uint64 guid)
{
    MemberList::iterator itr = members.find(GUID_LOPART(guid));
    if (itr == members.end() )
        return;

    itr->second.logout_time = time(NULL);

    if (m_onlinemembers > 0)
        --m_onlinemembers;
    else
    {
        UnloadGuildBank();
        UnloadGuildEventlog();
    }
}

// *************************************************
// Guild Eventlog part
// *************************************************
// Display guild eventlog
void Guild::DisplayGuildEventlog(WorldSession *session)
{
    // Load guild eventlog, if not already done
    if (!m_eventlogloaded)
        LoadGuildEventLogFromDB();

    // Sending result
    WorldPacket data(MSG_GUILD_EVENT_LOG_QUERY, 0);
    // count, max count == 100
    data << uint8(m_GuildEventlog.size());
    for (GuildEventlog::const_iterator itr = m_GuildEventlog.begin(); itr != m_GuildEventlog.end(); ++itr)
    {
        // Event type
        data << uint8((*itr)->EventType);
        // Player 1
        data << uint64((*itr)->PlayerGuid1);
        // Player 2 not for left/join guild events
        if( (*itr)->EventType != GUILD_EVENT_LOG_JOIN_GUILD && (*itr)->EventType != GUILD_EVENT_LOG_LEAVE_GUILD )
            data << uint64((*itr)->PlayerGuid2);
        // New Rank - only for promote/demote guild events
        if( (*itr)->EventType == GUILD_EVENT_LOG_PROMOTE_PLAYER || (*itr)->EventType == GUILD_EVENT_LOG_DEMOTE_PLAYER )
            data << uint8((*itr)->NewRank);
        // Event timestamp
        data << uint32(time(NULL)-(*itr)->TimeStamp);
    }
    session->SendPacket(&data);
    sLog.outDebug("WORLD: Sent (MSG_GUILD_EVENT_LOG_QUERY)");
}

// Load guild eventlog from DB
void Guild::LoadGuildEventLogFromDB()
{
    // Return if already loaded
    if (m_eventlogloaded)
        return;

    QueryResult *result = CharacterDatabase.PQuery("SELECT LogGuid, EventType, PlayerGuid1, PlayerGuid2, NewRank, TimeStamp FROM guild_eventlog WHERE guildid=%u ORDER BY LogGuid DESC LIMIT %u", Id, GUILD_EVENTLOG_MAX_ENTRIES);
    if(!result)
        return;
    do
    {
        Field *fields = result->Fetch();
        GuildEventlogEntry *NewEvent = new GuildEventlogEntry;
        // Fill entry
        NewEvent->LogGuid = fields[0].GetUInt32();
        NewEvent->EventType = fields[1].GetUInt8();
        NewEvent->PlayerGuid1 = fields[2].GetUInt32();
        NewEvent->PlayerGuid2 = fields[3].GetUInt32();
        NewEvent->NewRank = fields[4].GetUInt8();
        NewEvent->TimeStamp = fields[5].GetUInt64();
        // Add entry to map
        m_GuildEventlog.push_front(NewEvent);

    } while( result->NextRow() );
    delete result;

    // Check lists size in case to many event entries in db
    // This cases can happen only if a crash occured somewhere and table has too many log entries
    if (!m_GuildEventlog.empty())
    {
        CharacterDatabase.PExecute("DELETE FROM guild_eventlog WHERE guildid=%u AND LogGuid < %u", Id, m_GuildEventlog.front()->LogGuid);
    }
    m_eventlogloaded = true;
}

// Unload guild eventlog
void Guild::UnloadGuildEventlog()
{
    if (!m_eventlogloaded)
        return;
    GuildEventlogEntry *EventLogEntry;
    if( !m_GuildEventlog.empty() )
    {
        do
        {
            EventLogEntry = *(m_GuildEventlog.begin());
            m_GuildEventlog.pop_front();
            delete EventLogEntry;
        }while( !m_GuildEventlog.empty() );
    }
    m_eventlogloaded = false;
}

// This will renum guids used at load to prevent always going up until infinit
void Guild::RenumGuildEventlog()
{
    QueryResult *result = CharacterDatabase.PQuery("SELECT Min(LogGuid), Max(LogGuid) FROM guild_eventlog WHERE guildid = %u", Id);
    if(!result)
        return;

    Field *fields = result->Fetch();
    CharacterDatabase.PExecute("UPDATE guild_eventlog SET LogGuid=LogGuid-%u+1 WHERE guildid=%u ORDER BY LogGuid %s",fields[0].GetUInt32(), Id, fields[0].GetUInt32()?"ASC":"DESC");
    GuildEventlogMaxGuid = fields[1].GetUInt32()+1;
    delete result;
}

// Add entry to guild eventlog
void Guild::LogGuildEvent(uint8 EventType, uint32 PlayerGuid1, uint32 PlayerGuid2, uint8 NewRank)
{
    GuildEventlogEntry *NewEvent = new GuildEventlogEntry;
    // Fill entry
    NewEvent->LogGuid = GuildEventlogMaxGuid++;
    NewEvent->EventType = EventType;
    NewEvent->PlayerGuid1 = PlayerGuid1;
    NewEvent->PlayerGuid2 = PlayerGuid2;
    NewEvent->NewRank = NewRank;
    NewEvent->TimeStamp = uint32(time(NULL));
    // Check max entry limit and delete from db if needed
    if (m_GuildEventlog.size() > GUILD_EVENTLOG_MAX_ENTRIES)
    {
        GuildEventlogEntry *OldEvent = *(m_GuildEventlog.begin());
        m_GuildEventlog.pop_front();
        CharacterDatabase.PExecute("DELETE FROM guild_eventlog WHERE guildid='%u' AND LogGuid='%u'", Id, OldEvent->LogGuid);
        delete OldEvent;
    }
    // Add entry to map
    m_GuildEventlog.push_back(NewEvent);
    // Add new eventlog entry into DB
    CharacterDatabase.PExecute("INSERT INTO guild_eventlog (guildid, LogGuid, EventType, PlayerGuid1, PlayerGuid2, NewRank, TimeStamp) VALUES ('%u','%u','%u','%u','%u','%u','" I64FMTD "')",
        Id, NewEvent->LogGuid, uint32(NewEvent->EventType), NewEvent->PlayerGuid1, NewEvent->PlayerGuid2, uint32(NewEvent->NewRank), NewEvent->TimeStamp);
}

// *************************************************
// Guild Bank part
// *************************************************
// Bank content related
void Guild::DisplayGuildBankContent(WorldSession *session, uint8 TabId)
{
    WorldPacket data(SMSG_GUILD_BANK_LIST,1200);

    GuildBankTab const* tab = GetBankTab(TabId);
    if (!tab)
        return;

    if(!IsMemberHaveRights(session->GetPlayer()->GetGUIDLow(),TabId,GUILD_BANK_RIGHT_VIEW_TAB))
        return;

    data << uint64(GetGuildBankMoney());
    data << uint8(TabId);
                                                            // remaining slots for today
    data << uint32(GetMemberSlotWithdrawRem(session->GetPlayer()->GetGUIDLow(), TabId));
    data << uint8(0);                                       // Tell client this is a tab content packet

    data << uint8(GUILD_BANK_MAX_SLOTS);

    for (int i=0; i<GUILD_BANK_MAX_SLOTS; ++i)
        AppendDisplayGuildBankSlot(data, tab, i);

    session->SendPacket(&data);

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::DisplayGuildBankMoneyUpdate()
{
    WorldPacket data(SMSG_GUILD_BANK_LIST, 8+1+4+1+1);

    data << uint64(GetGuildBankMoney());
    data << uint8(0);                                       // TabId, default 0
    data << uint32(0);                                      // slot withdrow, default 0
    data << uint8(0);                                       // Tell client this is a tab content packet
    data << uint8(0);                                       // not send items
    BroadcastPacket(&data);

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::DisplayGuildBankContentUpdate(uint8 TabId, int32 slot1, int32 slot2)
{
    GuildBankTab const* tab = GetBankTab(TabId);
    if (!tab)
        return;

    WorldPacket data(SMSG_GUILD_BANK_LIST,1200);

    data << uint64(GetGuildBankMoney());
    data << uint8(TabId);
    // remaining slots for today

    size_t rempos = data.wpos();
    data << uint32(0);                                      // will be filled later
    data << uint8(0);                                       // Tell client this is a tab content packet

    if(slot2==-1)                                           // single item in slot1
    {
        data << uint8(1);

        AppendDisplayGuildBankSlot(data, tab, slot1);
    }
    else                                                    // 2 items (in slot1 and slot2)
    {
        data << uint8(2);

        if(slot1 > slot2)
            std::swap(slot1,slot2);

        AppendDisplayGuildBankSlot(data, tab, slot1);
        AppendDisplayGuildBankSlot(data, tab, slot2);
    }

    for(MemberList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
        if(!player)
            continue;

        if(!IsMemberHaveRights(itr->first,TabId,GUILD_BANK_RIGHT_VIEW_TAB))
            continue;

        data.put<uint32>(rempos,uint32(GetMemberSlotWithdrawRem(player->GetGUIDLow(), TabId)));

        player->GetSession()->SendPacket(&data);
    }

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::DisplayGuildBankContentUpdate(uint8 TabId, GuildItemPosCountVec const& slots)
{
    GuildBankTab const* tab = GetBankTab(TabId);
    if (!tab)
        return;

    WorldPacket data(SMSG_GUILD_BANK_LIST,1200);

    data << uint64(GetGuildBankMoney());
    data << uint8(TabId);
    // remaining slots for today

    size_t rempos = data.wpos();
    data << uint32(0);                                      // will be filled later
    data << uint8(0);                                       // Tell client this is a tab content packet

    data << uint8(slots.size());                            // updates count

    for(GuildItemPosCountVec::const_iterator itr = slots.begin(); itr != slots.end(); ++itr)
        AppendDisplayGuildBankSlot(data, tab, itr->slot);

    for(MemberList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER));
        if(!player)
            continue;

        if(!IsMemberHaveRights(itr->first,TabId,GUILD_BANK_RIGHT_VIEW_TAB))
            continue;

        data.put<uint32>(rempos,uint32(GetMemberSlotWithdrawRem(player->GetGUIDLow(), TabId)));

        player->GetSession()->SendPacket(&data);
    }

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

Item* Guild::GetItem(uint8 TabId, uint8 SlotId)
{
    if (TabId >= m_TabListMap.size() || SlotId >= GUILD_BANK_MAX_SLOTS)
        return NULL;
    return m_TabListMap[TabId]->Slots[SlotId];
}

// *************************************************
// Tab related

void Guild::DisplayGuildBankTabsInfo(WorldSession *session)
{
    // Time to load bank if not already done
    if (!m_bankloaded)
        LoadGuildBankFromDB();

    WorldPacket data(SMSG_GUILD_BANK_LIST, 500);

    data << uint64(GetGuildBankMoney());
    data << uint8(0);                                       // TabInfo packet must be for TabId 0
    data << uint32(0xFFFFFFFF);                             // bit 9 must be set for this packet to work
    data << uint8(1);                                       // Tell Client this is a TabInfo packet

    data << uint8(purchased_tabs);                          // here is the number of tabs

    for(int i = 0; i < purchased_tabs; ++i)
    {
        data << m_TabListMap[i]->Name.c_str();
        data << m_TabListMap[i]->Icon.c_str();
    }
    data << uint8(0);                                       // Do not send tab content
    session->SendPacket(&data);

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::CreateNewBankTab()
{
    if (purchased_tabs >= GUILD_BANK_MAX_TABS)
        return;

    ++purchased_tabs;

    GuildBankTab* AnotherTab = new GuildBankTab;
    memset(AnotherTab->Slots, 0, GUILD_BANK_MAX_SLOTS * sizeof(Item*));
    m_TabListMap.resize(purchased_tabs);
    m_TabListMap[purchased_tabs-1] = AnotherTab;

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM guild_bank_tab WHERE guildid='%u' AND TabId='%u'", Id, uint32(purchased_tabs-1));
    CharacterDatabase.PExecute("INSERT INTO guild_bank_tab (guildid,TabId) VALUES ('%u','%u')", Id, uint32(purchased_tabs-1));
    CharacterDatabase.CommitTransaction();
}

void Guild::SetGuildBankTabInfo(uint8 TabId, std::string Name, std::string Icon)
{
    if (TabId >= GUILD_BANK_MAX_TABS)
        return;
    if (TabId >= m_TabListMap.size())
        return;

    if (!m_TabListMap[TabId])
        return;

    if(m_TabListMap[TabId]->Name == Name && m_TabListMap[TabId]->Icon == Icon)
        return;

    m_TabListMap[TabId]->Name = Name;
    m_TabListMap[TabId]->Icon = Icon;

    CharacterDatabase.escape_string(Name);
    CharacterDatabase.escape_string(Icon);
    CharacterDatabase.PExecute("UPDATE guild_bank_tab SET TabName='%s',TabIcon='%s' WHERE guildid='%u' AND TabId='%u'", Name.c_str(), Icon.c_str(), Id, uint32(TabId));
}

void Guild::CreateBankRightForTab(uint32 rankId, uint8 TabId)
{
    sLog.outDebug("CreateBankRightForTab. rank: %u, TabId: %u", rankId, uint32(TabId));
    if (rankId >= m_ranks.size() || TabId >= GUILD_BANK_MAX_TABS)
        return;

    m_ranks[rankId].TabRight[TabId]=0;
    m_ranks[rankId].TabSlotPerDay[TabId]=0;
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM guild_bank_right WHERE guildid = '%u' AND TabId = '%u' AND rid = '%u'", Id, uint32(TabId), rankId);
    CharacterDatabase.PExecute("INSERT INTO guild_bank_right (guildid,TabId,rid) VALUES ('%u','%u','%u')", Id, uint32(TabId), rankId);
    CharacterDatabase.CommitTransaction();
}

uint32 Guild::GetBankRights(uint32 rankId, uint8 TabId) const
{
    if(rankId >= m_ranks.size() || TabId >= GUILD_BANK_MAX_TABS)
        return 0;

    return m_ranks[rankId].TabRight[TabId];
}

// *************************************************
// Guild bank loading/unloading related

// This load should be called when the bank is first accessed by a guild member
void Guild::LoadGuildBankFromDB()
{
    if (m_bankloaded)
        return;

    m_bankloaded = true;
    LoadGuildBankEventLogFromDB();

    //                                                     0      1        2        3
    QueryResult *result = CharacterDatabase.PQuery("SELECT TabId, TabName, TabIcon, TabText FROM guild_bank_tab WHERE guildid='%u' ORDER BY TabId", Id);
    if(!result)
    {
        purchased_tabs = 0;
        return;
    }

    m_TabListMap.resize(purchased_tabs);
    do
    {
        Field *fields = result->Fetch();
        uint8 TabId = fields[0].GetUInt8();

        GuildBankTab *NewTab = new GuildBankTab;
        memset(NewTab->Slots, 0, GUILD_BANK_MAX_SLOTS * sizeof(Item*));

        NewTab->Name = fields[1].GetCppString();
        NewTab->Icon = fields[2].GetCppString();
        NewTab->Text = fields[3].GetCppString();

        m_TabListMap[TabId] = NewTab;
    }while( result->NextRow() );

    delete result;

    // data needs to be at first place for Item::LoadFromDB
    //                                        0     1      2       3          4
    result = CharacterDatabase.PQuery("SELECT data, TabId, SlotId, item_guid, item_entry FROM guild_bank_item JOIN item_instance ON item_guid = guid WHERE guildid='%u' ORDER BY TabId", Id);
    if(!result)
        return;

    do
    {
        Field *fields = result->Fetch();
        uint8 TabId = fields[1].GetUInt8();
        uint8 SlotId = fields[2].GetUInt8();
        uint32 ItemGuid = fields[3].GetUInt32();
        uint32 ItemEntry = fields[4].GetUInt32();

        if (TabId >= purchased_tabs || TabId >= GUILD_BANK_MAX_TABS)
        {
            sLog.outError( "Guild::LoadGuildBankFromDB: Invalid tab for item (GUID: %u id: #%u) in guild bank, skipped.", ItemGuid,ItemEntry);
            continue;
        }

        if (SlotId >= GUILD_BANK_MAX_SLOTS)
        {
            sLog.outError( "Guild::LoadGuildBankFromDB: Invalid slot for item (GUID: %u id: #%u) in guild bank, skipped.", ItemGuid,ItemEntry);
            continue;
        }

        ItemPrototype const *proto = objmgr.GetItemPrototype(ItemEntry);

        if(!proto)
        {
            sLog.outError( "Guild::LoadGuildBankFromDB: Unknown item (GUID: %u id: #%u) in guild bank, skipped.", ItemGuid,ItemEntry);
            continue;
        }

        Item *pItem = NewItemOrBag(proto);
        if(!pItem->LoadFromDB(ItemGuid, 0, result))
        {
            CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE guildid='%u' AND TabId='%u' AND SlotId='%u'", Id, uint32(TabId), uint32(SlotId));
            sLog.outError("Item GUID %u not found in item_instance, deleting from Guild Bank!", ItemGuid);
            delete pItem;
            continue;
        }

        pItem->AddToWorld();
        m_TabListMap[TabId]->Slots[SlotId] = pItem;
    }while( result->NextRow() );

    delete result;
}

// This unload should be called when the last member of the guild gets offline
void Guild::UnloadGuildBank()
{
    if (!m_bankloaded)
        return;
    for (uint8 i = 0 ; i < purchased_tabs ; ++i )
    {
        for (uint8 j = 0 ; j < GUILD_BANK_MAX_SLOTS ; ++j)
        {
            if (m_TabListMap[i]->Slots[j])
            {
                m_TabListMap[i]->Slots[j]->RemoveFromWorld();
                delete m_TabListMap[i]->Slots[j];
            }
        }
        delete m_TabListMap[i];
    }
    m_TabListMap.clear();

    UnloadGuildBankEventLog();
    m_bankloaded = false;
}

// *************************************************
// Money deposit/withdraw related

void Guild::SendMoneyInfo(WorldSession *session, uint32 LowGuid)
{
    WorldPacket data(MSG_GUILD_BANK_MONEY_WITHDRAWN, 4);
    data << uint32(GetMemberMoneyWithdrawRem(LowGuid));
    session->SendPacket(&data);
    sLog.outDebug("WORLD: Sent MSG_GUILD_BANK_MONEY_WITHDRAWN");
}

bool Guild::MemberMoneyWithdraw(uint32 amount, uint32 LowGuid)
{
    uint32 MoneyWithDrawRight = GetMemberMoneyWithdrawRem(LowGuid);

    if (MoneyWithDrawRight < amount || GetGuildBankMoney() < amount)
        return false;

    SetBankMoney(GetGuildBankMoney()-amount);

    if (MoneyWithDrawRight < WITHDRAW_MONEY_UNLIMITED)
    {
        MemberList::iterator itr = members.find(LowGuid);
        if (itr == members.end() )
            return false;
        itr->second.BankRemMoney -= amount;
        CharacterDatabase.PExecute("UPDATE guild_member SET BankRemMoney='%u' WHERE guildid='%u' AND guid='%u'",
            itr->second.BankRemMoney, Id, LowGuid);
    }
    return true;
}

void Guild::SetBankMoney(int64 money)
{
    if (money < 0)                                          // I don't know how this happens, it does!!
        money = 0;
    guildbank_money = money;

    CharacterDatabase.PExecute("UPDATE guild SET BankMoney='" I64FMTD "' WHERE guildid='%u'", money, Id);
}

// *************************************************
// Item per day and money per day related

bool Guild::MemberItemWithdraw(uint8 TabId, uint32 LowGuid)
{
    uint32 SlotsWithDrawRight = GetMemberSlotWithdrawRem(LowGuid, TabId);

    if (SlotsWithDrawRight == 0)
        return false;

    if (SlotsWithDrawRight < WITHDRAW_SLOT_UNLIMITED)
    {
        MemberList::iterator itr = members.find(LowGuid);
        if (itr == members.end() )
            return false;
        --itr->second.BankRemSlotsTab[TabId];
        CharacterDatabase.PExecute("UPDATE guild_member SET BankRemSlotsTab%u='%u' WHERE guildid='%u' AND guid='%u'",
            uint32(TabId), itr->second.BankRemSlotsTab[TabId], Id, LowGuid);
    }
    return true;
}

bool Guild::IsMemberHaveRights(uint32 LowGuid, uint8 TabId, uint32 rights) const
{
    MemberList::const_iterator itr = members.find(LowGuid);
    if (itr == members.end() )
        return false;

    if (itr->second.RankId == GR_GUILDMASTER)
        return true;

    return (GetBankRights(itr->second.RankId,TabId) & rights)==rights;
}

uint32 Guild::GetMemberSlotWithdrawRem(uint32 LowGuid, uint8 TabId)
{
    MemberList::iterator itr = members.find(LowGuid);
    if (itr == members.end() )
        return 0;

    if (itr->second.RankId == GR_GUILDMASTER)
        return WITHDRAW_SLOT_UNLIMITED;

    if((GetBankRights(itr->second.RankId,TabId) & GUILD_BANK_RIGHT_VIEW_TAB)!=GUILD_BANK_RIGHT_VIEW_TAB)
        return 0;

    uint32 curTime = uint32(time(NULL)/MINUTE);
    if (curTime - itr->second.BankResetTimeTab[TabId] >= 24*HOUR/MINUTE)
    {
        itr->second.BankResetTimeTab[TabId] = curTime;
        itr->second.BankRemSlotsTab[TabId] = GetBankSlotPerDay(itr->second.RankId, TabId);
        CharacterDatabase.PExecute("UPDATE guild_member SET BankResetTimeTab%u='%u',BankRemSlotsTab%u='%u' WHERE guildid='%u' AND guid='%u'",
            uint32(TabId), itr->second.BankResetTimeTab[TabId], uint32(TabId), itr->second.BankRemSlotsTab[TabId], Id, LowGuid);
    }
    return itr->second.BankRemSlotsTab[TabId];
}

uint32 Guild::GetMemberMoneyWithdrawRem(uint32 LowGuid)
{
    MemberList::iterator itr = members.find(LowGuid);
    if (itr == members.end() )
        return 0;

    if (itr->second.RankId == GR_GUILDMASTER)
        return WITHDRAW_MONEY_UNLIMITED;

    uint32 curTime = uint32(time(NULL)/MINUTE);             // minutes
                                                            // 24 hours
    if (curTime > itr->second.BankResetTimeMoney + 24*HOUR/MINUTE)
    {
        itr->second.BankResetTimeMoney = curTime;
        itr->second.BankRemMoney = GetBankMoneyPerDay(itr->second.RankId);
        CharacterDatabase.PExecute("UPDATE guild_member SET BankResetTimeMoney='%u',BankRemMoney='%u' WHERE guildid='%u' AND guid='%u'",
            itr->second.BankResetTimeMoney, itr->second.BankRemMoney, Id, LowGuid);
    }
    return itr->second.BankRemMoney;
}

void Guild::SetBankMoneyPerDay(uint32 rankId, uint32 money)
{
    if (rankId >= m_ranks.size())
        return;

    if (rankId == GR_GUILDMASTER)
        money = WITHDRAW_MONEY_UNLIMITED;

    m_ranks[rankId].BankMoneyPerDay = money;

    for (MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
        if (itr->second.RankId == rankId)
            itr->second.BankResetTimeMoney = 0;

    CharacterDatabase.PExecute("UPDATE guild_rank SET BankMoneyPerDay='%u' WHERE rid='%u' AND guildid='%u'", money, (rankId+1), Id);
    CharacterDatabase.PExecute("UPDATE guild_member SET BankResetTimeMoney='0' WHERE guildid='%u' AND rank='%u'", Id, rankId);
}

void Guild::SetBankRightsAndSlots(uint32 rankId, uint8 TabId, uint32 right, uint32 nbSlots, bool db)
{
    if(rankId >= m_ranks.size() ||
        TabId >= GUILD_BANK_MAX_TABS ||
        TabId >= purchased_tabs)
        return;

    if (rankId == GR_GUILDMASTER)
    {
        nbSlots = WITHDRAW_SLOT_UNLIMITED;
        right = GUILD_BANK_RIGHT_FULL;
    }

    m_ranks[rankId].TabSlotPerDay[TabId]=nbSlots;
    m_ranks[rankId].TabRight[TabId]=right;

    if (db)
    {
        for (MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
            if (itr->second.RankId == rankId)
                for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
                    itr->second.BankResetTimeTab[i] = 0;

        CharacterDatabase.PExecute("DELETE FROM guild_bank_right WHERE guildid='%u' AND TabId='%u' AND rid='%u'", Id, uint32(TabId), rankId);
        CharacterDatabase.PExecute("INSERT INTO guild_bank_right (guildid,TabId,rid,gbright,SlotPerDay) VALUES "
            "('%u','%u','%u','%u','%u')", Id, uint32(TabId), rankId, m_ranks[rankId].TabRight[TabId], m_ranks[rankId].TabSlotPerDay[TabId]);
        CharacterDatabase.PExecute("UPDATE guild_member SET BankResetTimeTab%u='0' WHERE guildid='%u' AND rank='%u'", uint32(TabId), Id, rankId);
    }
}

uint32 Guild::GetBankMoneyPerDay(uint32 rankId)
{
    if(rankId >= m_ranks.size())
        return 0;

    if (rankId == GR_GUILDMASTER)
        return WITHDRAW_MONEY_UNLIMITED;
    return m_ranks[rankId].BankMoneyPerDay;
}

uint32 Guild::GetBankSlotPerDay(uint32 rankId, uint8 TabId)
{
    if(rankId >= m_ranks.size() || TabId >= GUILD_BANK_MAX_TABS)
        return 0;

    if (rankId == GR_GUILDMASTER)
        return WITHDRAW_SLOT_UNLIMITED;
    return m_ranks[rankId].TabSlotPerDay[TabId];
}

// *************************************************
// Rights per day related

void Guild::LoadBankRightsFromDB(uint32 GuildId)
{
    //                                                     0      1    2        3
    QueryResult *result = CharacterDatabase.PQuery("SELECT TabId, rid, gbright, SlotPerDay FROM guild_bank_right WHERE guildid = '%u' ORDER BY TabId", GuildId);

    if(!result)
        return;

    do
    {
        Field *fields = result->Fetch();
        uint8 TabId = fields[0].GetUInt8();
        uint32 rankId = fields[1].GetUInt32();
        uint16 right = fields[2].GetUInt16();
        uint16 SlotPerDay = fields[3].GetUInt16();

        SetBankRightsAndSlots(rankId, TabId, right, SlotPerDay, false);

    }while( result->NextRow() );
    delete result;

    return;
}

// *************************************************
// Bank log related

void Guild::LoadGuildBankEventLogFromDB()
{
    // We can't add a limit as in Guild::LoadGuildEventLogFromDB since we fetch both money and bank log and know nothing about the composition
    //                                                     0        1         2      3           4            5               6          7
    QueryResult *result = CharacterDatabase.PQuery("SELECT LogGuid, LogEntry, TabId, PlayerGuid, ItemOrMoney, ItemStackCount, DestTabId, TimeStamp FROM guild_bank_eventlog WHERE guildid='%u' ORDER BY TimeStamp DESC", Id);
    if(!result)
        return;

    do
    {
        Field *fields = result->Fetch();
        GuildBankEvent *NewEvent = new GuildBankEvent;

        NewEvent->LogGuid = fields[0].GetUInt32();
        NewEvent->LogEntry = fields[1].GetUInt8();
        uint8 TabId = fields[2].GetUInt8();
        NewEvent->PlayerGuid = fields[3].GetUInt32();
        NewEvent->ItemOrMoney = fields[4].GetUInt32();
        NewEvent->ItemStackCount = fields[5].GetUInt8();
        NewEvent->DestTabId = fields[6].GetUInt8();
        NewEvent->TimeStamp = fields[7].GetUInt64();

        if (TabId >= GUILD_BANK_MAX_TABS)
        {
            sLog.outError( "Guild::LoadGuildBankEventLogFromDB: Invalid tabid '%u' for guild bank log entry (guild: '%s', LogGuid: %u), skipped.", TabId, GetName().c_str(), NewEvent->LogGuid);
            delete NewEvent;
            continue;
        }
        if (NewEvent->isMoneyEvent() && m_GuildBankEventLog_Money.size() >= GUILD_BANK_MAX_LOGS
                || m_GuildBankEventLog_Item[TabId].size() >= GUILD_BANK_MAX_LOGS)
        {
            delete NewEvent;
            continue;
        }
        if (NewEvent->isMoneyEvent())
            m_GuildBankEventLog_Money.push_front(NewEvent);
        else
            m_GuildBankEventLog_Item[TabId].push_front(NewEvent);

    }while( result->NextRow() );
    delete result;

    // Check lists size in case to many event entries in db for a tab or for money
    // This cases can happen only if a crash occured somewhere and table has too many log entries
    if (!m_GuildBankEventLog_Money.empty())
    {
        CharacterDatabase.PExecute("DELETE FROM guild_bank_eventlog WHERE guildid=%u AND LogGuid < %u",
            Id, m_GuildBankEventLog_Money.front()->LogGuid);
    }
    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        if (!m_GuildBankEventLog_Item[i].empty())
        {
            CharacterDatabase.PExecute("DELETE FROM guild_bank_eventlog WHERE guildid=%u AND LogGuid < %u",
                Id, m_GuildBankEventLog_Item[i].front()->LogGuid);
        }
    }
}

void Guild::UnloadGuildBankEventLog()
{
    GuildBankEvent *EventLogEntry;
    if( !m_GuildBankEventLog_Money.empty() )
    {
        do
        {
            EventLogEntry = *(m_GuildBankEventLog_Money.begin());
            m_GuildBankEventLog_Money.pop_front();
            delete EventLogEntry;
        }while( !m_GuildBankEventLog_Money.empty() );
    }

    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        if( !m_GuildBankEventLog_Item[i].empty() )
        {
            do
            {
                EventLogEntry = *(m_GuildBankEventLog_Item[i].begin());
                m_GuildBankEventLog_Item[i].pop_front();
                delete EventLogEntry;
            }while( !m_GuildBankEventLog_Item[i].empty() );
        }
    }
}

void Guild::DisplayGuildBankLogs(WorldSession *session, uint8 TabId)
{
    if (TabId > GUILD_BANK_MAX_TABS)
        return;

    if (TabId == GUILD_BANK_MAX_TABS)
    {
        // Here we display money logs
        WorldPacket data(MSG_GUILD_BANK_LOG_QUERY, m_GuildBankEventLog_Money.size()*(4*4+1)+1+1);
        data << uint8(TabId);                               // Here GUILD_BANK_MAX_TABS
        data << uint8(m_GuildBankEventLog_Money.size());    // number of log entries
        for (GuildBankEventLog::const_iterator itr = m_GuildBankEventLog_Money.begin(); itr != m_GuildBankEventLog_Money.end(); ++itr)
        {
            data << uint8((*itr)->LogEntry);
            data << uint64(MAKE_NEW_GUID((*itr)->PlayerGuid,0,HIGHGUID_PLAYER));
            if ((*itr)->LogEntry == GUILD_BANK_LOG_DEPOSIT_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_WITHDRAW_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_REPAIR_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_UNK1 ||
                (*itr)->LogEntry == GUILD_BANK_LOG_UNK2)
            {
                data << uint32((*itr)->ItemOrMoney);
            }
            else
            {
                data << uint32((*itr)->ItemOrMoney);
                data << uint32((*itr)->ItemStackCount);
                if ((*itr)->LogEntry == GUILD_BANK_LOG_MOVE_ITEM || (*itr)->LogEntry == GUILD_BANK_LOG_MOVE_ITEM2)
                    data << uint8((*itr)->DestTabId);       // moved tab
            }
            data << uint32(time(NULL)-(*itr)->TimeStamp);
        }
        session->SendPacket(&data);
    }
    else
    {
        // here we display current tab logs
        WorldPacket data(MSG_GUILD_BANK_LOG_QUERY, m_GuildBankEventLog_Item[TabId].size()*(4*4+1+1)+1+1);
        data << uint8(TabId);                               // Here a real Tab Id
                                                            // number of log entries
        data << uint8(m_GuildBankEventLog_Item[TabId].size());
        for (GuildBankEventLog::const_iterator itr = m_GuildBankEventLog_Item[TabId].begin(); itr != m_GuildBankEventLog_Item[TabId].end(); ++itr)
        {
            data << uint8((*itr)->LogEntry);
            data << uint64(MAKE_NEW_GUID((*itr)->PlayerGuid,0,HIGHGUID_PLAYER));
            if ((*itr)->LogEntry == GUILD_BANK_LOG_DEPOSIT_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_WITHDRAW_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_REPAIR_MONEY ||
                (*itr)->LogEntry == GUILD_BANK_LOG_UNK1 ||
                (*itr)->LogEntry == GUILD_BANK_LOG_UNK2)
            {
                data << uint32((*itr)->ItemOrMoney);
            }
            else
            {
                data << uint32((*itr)->ItemOrMoney);
                data << uint32((*itr)->ItemStackCount);
                if ((*itr)->LogEntry == GUILD_BANK_LOG_MOVE_ITEM || (*itr)->LogEntry == GUILD_BANK_LOG_MOVE_ITEM2)
                    data << uint8((*itr)->DestTabId);       // moved tab
            }
            data << uint32(time(NULL)-(*itr)->TimeStamp);
        }
        session->SendPacket(&data);
    }
    sLog.outDebug("WORLD: Sent (MSG_GUILD_BANK_LOG_QUERY)");
}

void Guild::LogBankEvent(uint8 LogEntry, uint8 TabId, uint32 PlayerGuidLow, uint32 ItemOrMoney, uint8 ItemStackCount, uint8 DestTabId)
{
    GuildBankEvent *NewEvent = new GuildBankEvent;

    NewEvent->LogGuid = LogMaxGuid++;
    NewEvent->LogEntry = LogEntry;
    NewEvent->PlayerGuid = PlayerGuidLow;
    NewEvent->ItemOrMoney = ItemOrMoney;
    NewEvent->ItemStackCount = ItemStackCount;
    NewEvent->DestTabId = DestTabId;
    NewEvent->TimeStamp = uint32(time(NULL));

    if (NewEvent->isMoneyEvent())
    {
        if (m_GuildBankEventLog_Money.size() > GUILD_BANK_MAX_LOGS)
        {
            GuildBankEvent *OldEvent = *(m_GuildBankEventLog_Money.begin());
            m_GuildBankEventLog_Money.pop_front();
            CharacterDatabase.PExecute("DELETE FROM guild_bank_eventlog WHERE guildid='%u' AND LogGuid='%u'", Id, OldEvent->LogGuid);
            delete OldEvent;
        }
        m_GuildBankEventLog_Money.push_back(NewEvent);
    }
    else
    {
        if (m_GuildBankEventLog_Item[TabId].size() > GUILD_BANK_MAX_LOGS)
        {
            GuildBankEvent *OldEvent = *(m_GuildBankEventLog_Item[TabId].begin());
            m_GuildBankEventLog_Item[TabId].pop_front();
            CharacterDatabase.PExecute("DELETE FROM guild_bank_eventlog WHERE guildid='%u' AND LogGuid='%u'", Id, OldEvent->LogGuid);
            delete OldEvent;
        }
        m_GuildBankEventLog_Item[TabId].push_back(NewEvent);
    }
    CharacterDatabase.PExecute("INSERT INTO guild_bank_eventlog (guildid,LogGuid,LogEntry,TabId,PlayerGuid,ItemOrMoney,ItemStackCount,DestTabId,TimeStamp) VALUES ('%u','%u','%u','%u','%u','%u','%u','%u','" I64FMTD "')",
        Id, NewEvent->LogGuid, uint32(NewEvent->LogEntry), uint32(TabId), NewEvent->PlayerGuid, NewEvent->ItemOrMoney, uint32(NewEvent->ItemStackCount), uint32(NewEvent->DestTabId), NewEvent->TimeStamp);
}

// This will renum guids used at load to prevent always going up until infinit
void Guild::RenumBankLogs()
{
    QueryResult *result = CharacterDatabase.PQuery("SELECT Min(LogGuid), Max(LogGuid) FROM guild_bank_eventlog WHERE guildid = %u", Id);
    if(!result)
        return;

    Field *fields = result->Fetch();
    CharacterDatabase.PExecute("UPDATE guild_bank_eventlog SET LogGuid=LogGuid-%u+1 WHERE guildid=%u ORDER BY LogGuid %s",fields[0].GetUInt32(), Id, fields[0].GetUInt32()?"ASC":"DESC");
    LogMaxGuid = fields[1].GetUInt32()+1;
    delete result;
}

bool Guild::AddGBankItemToDB(uint32 GuildId, uint32 BankTab , uint32 BankTabSlot , uint32 GUIDLow, uint32 Entry )
{
    CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE guildid = '%u' AND TabId = '%u'AND SlotId = '%u'", GuildId, BankTab, BankTabSlot);
    CharacterDatabase.PExecute("INSERT INTO guild_bank_item (guildid,TabId,SlotId,item_guid,item_entry) "
        "VALUES ('%u', '%u', '%u', '%u', '%u')", GuildId, BankTab, BankTabSlot, GUIDLow, Entry);
    return true;
}

void Guild::AppendDisplayGuildBankSlot( WorldPacket& data, GuildBankTab const *tab, int slot )
{
    Item *pItem = tab->Slots[slot];
    uint32 entry = pItem ? pItem->GetEntry() : 0;

    data << uint8(slot);
    data << uint32(entry);
    if (entry)
    {
        // random item property id +8
        data << (uint32) pItem->GetItemRandomPropertyId();
        if (pItem->GetItemRandomPropertyId())
            // SuffixFactor +4
            data << (uint32) pItem->GetItemSuffixFactor();
        // +12 // ITEM_FIELD_STACK_COUNT
        data << uint32(pItem->GetCount());
        data << uint32(0);                                  // +16 // Unknown value
        data << uint8(0);                                   // unknown 2.4.2
        if (uint32 Enchant0 = pItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT))
        {
            data << uint8(1);                               // number of enchantments (max 3) why max 3?
            data << uint8(PERM_ENCHANTMENT_SLOT);           // enchantment slot (range: 0:2)
            data << uint32(Enchant0);                       // enchantment id
        }
        else
            data << uint8(0);                               // no enchantments (0)
    }
}

Item* Guild::StoreItem(uint8 tabId, GuildItemPosCountVec const& dest, Item* pItem )
{
    if( !pItem )
        return NULL;

    Item* lastItem = pItem;

    for(GuildItemPosCountVec::const_iterator itr = dest.begin(); itr != dest.end(); )
    {
        uint8 slot = itr->slot;
        uint32 count = itr->count;

        ++itr;

        if(itr == dest.end())
        {
            lastItem = _StoreItem(tabId,slot,pItem,count,false);
            break;
        }

        lastItem = _StoreItem(tabId,slot,pItem,count,true);
    }

    return lastItem;
}

// Return stored item (if stored to stack, it can diff. from pItem). And pItem ca be deleted in this case.
Item* Guild::_StoreItem( uint8 tab, uint8 slot, Item *pItem, uint32 count, bool clone )
{
    if( !pItem )
        return NULL;

    sLog.outDebug( "GUILD STORAGE: StoreItem tab = %u, slot = %u, item = %u, count = %u", tab, slot, pItem->GetEntry(), count);

    Item* pItem2 = m_TabListMap[tab]->Slots[slot];

    if( !pItem2 )
    {
        if(clone)
            pItem = pItem->CloneItem(count);
        else
            pItem->SetCount(count);

        if(!pItem)
            return NULL;

        m_TabListMap[tab]->Slots[slot] = pItem;

        pItem->SetUInt64Value(ITEM_FIELD_CONTAINED, 0);
        pItem->SetUInt64Value(ITEM_FIELD_OWNER, 0);
        AddGBankItemToDB(GetId(), tab, slot, pItem->GetGUIDLow(), pItem->GetEntry());
        pItem->FSetState(ITEM_NEW);
        pItem->SaveToDB();                                  // not in onventory and can be save standalone

        return pItem;
    }
    else
    {
        pItem2->SetCount( pItem2->GetCount() + count );
        pItem2->FSetState(ITEM_CHANGED);
        pItem2->SaveToDB();                                 // not in onventory and can be save standalone

        if(!clone)
        {
            pItem->RemoveFromWorld();
            pItem->DeleteFromDB();
            delete pItem;
        }

        return pItem2;
    }
}

void Guild::RemoveItem(uint8 tab, uint8 slot )
{
    m_TabListMap[tab]->Slots[slot] = NULL;
    CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE guildid='%u' AND TabId='%u' AND SlotId='%u'",
        GetId(), uint32(tab), uint32(slot));
}

uint8 Guild::_CanStoreItem_InSpecificSlot( uint8 tab, uint8 slot, GuildItemPosCountVec &dest, uint32& count, bool swap, Item* pSrcItem ) const
{
    Item* pItem2 = m_TabListMap[tab]->Slots[slot];

    // ignore move item (this slot will be empty at move)
    if(pItem2==pSrcItem)
        pItem2 = NULL;

    uint32 need_space;

    // empty specific slot - check item fit to slot
    if( !pItem2 || swap )
    {
        // non empty stack with space
        need_space = pSrcItem->GetMaxStackCount();
    }
    // non empty slot, check item type
    else
    {
        // check item type
        if(pItem2->GetEntry() != pSrcItem->GetEntry())
            return EQUIP_ERR_ITEM_CANT_STACK;

        // check free space
        if(pItem2->GetCount() >= pSrcItem->GetMaxStackCount())
            return EQUIP_ERR_ITEM_CANT_STACK;

        need_space = pSrcItem->GetMaxStackCount() - pItem2->GetCount();
    }

    if(need_space > count)
        need_space = count;

    GuildItemPosCount newPosition = GuildItemPosCount(slot,need_space);
    if(!newPosition.isContainedIn(dest))
    {
        dest.push_back(newPosition);
        count -= need_space;
    }

    return EQUIP_ERR_OK;
}

uint8 Guild::_CanStoreItem_InTab( uint8 tab, GuildItemPosCountVec &dest, uint32& count, bool merge, Item* pSrcItem, uint8 skip_slot ) const
{
    for(uint32 j = 0; j < GUILD_BANK_MAX_SLOTS; j++)
    {
        // skip specific slot already processed in first called _CanStoreItem_InSpecificSlot
        if(j==skip_slot)
            continue;

        Item* pItem2 = m_TabListMap[tab]->Slots[j];

        // ignore move item (this slot will be empty at move)
        if(pItem2==pSrcItem)
            pItem2 = NULL;

        // if merge skip empty, if !merge skip non-empty
        if((pItem2!=NULL)!=merge)
            continue;

        if( pItem2 )
        {
            if(pItem2->GetEntry() == pSrcItem->GetEntry() && pItem2->GetCount() < pSrcItem->GetMaxStackCount() )
            {
                uint32 need_space = pSrcItem->GetMaxStackCount() - pItem2->GetCount();
                if(need_space > count)
                    need_space = count;

                GuildItemPosCount newPosition = GuildItemPosCount(j,need_space);
                if(!newPosition.isContainedIn(dest))
                {
                    dest.push_back(newPosition);
                    count -= need_space;

                    if(count==0)
                        return EQUIP_ERR_OK;
                }
            }
        }
        else
        {
            uint32 need_space = pSrcItem->GetMaxStackCount();
            if(need_space > count)
                need_space = count;

            GuildItemPosCount newPosition = GuildItemPosCount(j,need_space);
            if(!newPosition.isContainedIn(dest))
            {
                dest.push_back(newPosition);
                count -= need_space;

                if(count==0)
                    return EQUIP_ERR_OK;
            }
        }
    }
    return EQUIP_ERR_OK;
}

uint8 Guild::CanStoreItem( uint8 tab, uint8 slot, GuildItemPosCountVec &dest, uint32 count, Item *pItem, bool swap ) const
{
    sLog.outDebug( "GUILD STORAGE: CanStoreItem tab = %u, slot = %u, item = %u, count = %u", tab, slot, pItem->GetEntry(), count);

    if(count > pItem->GetCount())
        return EQUIP_ERR_COULDNT_SPLIT_ITEMS;

    if(pItem->IsSoulBound())
        return EQUIP_ERR_CANT_DROP_SOULBOUND;

    // in specific slot
    if( slot != NULL_SLOT )
    {
        uint8 res = _CanStoreItem_InSpecificSlot(tab,slot,dest,count,swap,pItem);
        if(res!=EQUIP_ERR_OK)
            return res;

        if(count==0)
            return EQUIP_ERR_OK;
    }

    // not specific slot or have spece for partly store only in specific slot

    // search stack in tab for merge to
    if( pItem->GetMaxStackCount() > 1 )
    {
        uint8 res = _CanStoreItem_InTab(tab,dest,count,true,pItem,slot);
        if(res!=EQUIP_ERR_OK)
            return res;

        if(count==0)
            return EQUIP_ERR_OK;
    }

    // search free slot in bag for place to
    uint8 res = _CanStoreItem_InTab(tab,dest,count,false,pItem,slot);
    if(res!=EQUIP_ERR_OK)
        return res;

    if(count==0)
        return EQUIP_ERR_OK;

    return EQUIP_ERR_BANK_FULL;
}

void Guild::SetGuildBankTabText(uint8 TabId, std::string text)
{
    if (TabId >= GUILD_BANK_MAX_TABS)
        return;
    if (TabId >= m_TabListMap.size())
        return;
    if (!m_TabListMap[TabId])
        return;

    if(m_TabListMap[TabId]->Text==text)
        return;

    utf8truncate(text,500);                                 // DB and client size limitation

    m_TabListMap[TabId]->Text = text;

    CharacterDatabase.escape_string(text);
    CharacterDatabase.PExecute("UPDATE guild_bank_tab SET TabText='%s' WHERE guildid='%u' AND TabId='%u'", text.c_str(), Id, uint32(TabId));

    // announce
    SendGuildBankTabText(NULL,TabId);
}

void Guild::SendGuildBankTabText(WorldSession *session, uint8 TabId)
{
    if (TabId > GUILD_BANK_MAX_TABS)
        return;

    GuildBankTab const *tab = GetBankTab(TabId);
    if (!tab)
        return;

    WorldPacket data(MSG_QUERY_GUILD_BANK_TEXT, 1+tab->Text.size()+1);
    data << uint8(TabId);
    data << tab->Text;

    if(session)
        session->SendPacket(&data);
    else
        BroadcastPacket(&data);

}

bool GuildItemPosCount::isContainedIn(GuildItemPosCountVec const &vec) const
{
    for(GuildItemPosCountVec::const_iterator itr = vec.begin(); itr != vec.end();++itr)
        if(itr->slot == slot)
            return true;

    return false;
}

