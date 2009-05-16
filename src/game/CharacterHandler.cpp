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

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "SharedDefines.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Guild.h"
#include "UpdateMask.h"
#include "Auth/md5.h"
#include "ObjectAccessor.h"
#include "Group.h"
#include "Database/DatabaseImpl.h"
#include "PlayerDump.h"
#include "SocialMgr.h"
#include "Util.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "Chat.h"
#include "SystemConfig.h"

class LoginQueryHolder : public SqlQueryHolder
{
    private:
        uint32 m_accountId;
        uint64 m_guid;
    public:
        LoginQueryHolder(uint32 accountId, uint64 guid)
            : m_accountId(accountId), m_guid(guid) { }
        uint64 GetGuid() const { return m_guid; }
        uint32 GetAccountId() const { return m_accountId; }
        bool Initialize();
};

bool LoginQueryHolder::Initialize()
{
    SetSize(MAX_PLAYER_LOGIN_QUERY);

    bool res = true;

    // NOTE: all fields in `characters` must be read to prevent lost character data at next save in case wrong DB structure.
    // !!! NOTE: including unused `zone`,`online`
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADFROM,            "SELECT guid, account, data, name, race, class, position_x, position_y, position_z, map, orientation, taximask, cinematic, totaltime, leveltime, rest_bonus, logout_time, is_logout_resting, resettalents_cost, resettalents_time, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login, zone, online, death_expire_time, taxi_path, dungeon_difficulty, arena_pending_points,bgid,bgteam,bgmap,bgx,bgy,bgz,bgo,instance_id FROM characters WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADGROUP,           "SELECT leaderGuid FROM group_member WHERE memberGuid ='%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADBOUNDINSTANCES,  "SELECT id, permanent, map, difficulty, resettime FROM character_instance LEFT JOIN instance ON instance = id WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADAURAS,           "SELECT caster_guid,spell,effect_mask,stackcount,amount0, amount1, amount2 ,maxduration,remaintime,remaincharges FROM character_aura WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADSPELLS,          "SELECT spell,active,disabled FROM character_spell WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADQUESTSTATUS,     "SELECT quest,status,rewarded,explored,timer,mobcount1,mobcount2,mobcount3,mobcount4,itemcount1,itemcount2,itemcount3,itemcount4 FROM character_queststatus WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADDAILYQUESTSTATUS,"SELECT quest,time FROM character_queststatus_daily WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADTUTORIALS,       "SELECT tut0,tut1,tut2,tut3,tut4,tut5,tut6,tut7 FROM character_tutorial WHERE account = '%u' AND realmid = '%u'", GetAccountId(), realmID);
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADREPUTATION,      "SELECT faction,standing,flags FROM character_reputation WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADINVENTORY,       "SELECT data,bag,slot,item,item_template FROM character_inventory JOIN item_instance ON character_inventory.item = item_instance.guid WHERE character_inventory.guid = '%u' ORDER BY bag,slot", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADACTIONS,         "SELECT button,action,type,misc FROM character_action WHERE guid = '%u' ORDER BY button", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADMAILCOUNT,       "SELECT COUNT(id) FROM mail WHERE receiver = '%u' AND (checked & 1)=0 AND deliver_time <= '" I64FMTD "'", GUID_LOPART(m_guid),(uint64)time(NULL));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADMAILDATE,        "SELECT MIN(deliver_time) FROM mail WHERE receiver = '%u' AND (checked & 1)=0", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADSOCIALLIST,      "SELECT friend,flags,note FROM character_social WHERE guid = '%u' LIMIT 255", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADHOMEBIND,        "SELECT map,zone,position_x,position_y,position_z FROM character_homebind WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADSPELLCOOLDOWNS,  "SELECT spell,item,time FROM character_spell_cooldown WHERE guid = '%u'", GUID_LOPART(m_guid));
    if(sWorld.getConfig(CONFIG_DECLINED_NAMES_USED))
        res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADDECLINEDNAMES,   "SELECT genitive, dative, accusative, instrumental, prepositional FROM character_declinedname WHERE guid = '%u'",GUID_LOPART(m_guid));
    // in other case still be dummy query
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADGUILD,           "SELECT guildid,rank FROM guild_member WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADARENAINFO,       "SELECT arenateamid, played_week, played_season, personal_rating FROM arena_team_member WHERE guid='%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADACHIEVEMENTS,    "SELECT achievement, date FROM character_achievement WHERE guid = '%u'", GUID_LOPART(m_guid));
    res &= SetPQuery(PLAYER_LOGIN_QUERY_LOADCRITERIAPROGRESS,"SELECT criteria, counter, date FROM character_achievement_progress WHERE guid = '%u'", GUID_LOPART(m_guid));

    return res;
}

// don't call WorldSession directly
// it may get deleted before the query callbacks get executed
// instead pass an account id to this handler
class CharacterHandler
{
    public:
        void HandleCharEnumCallback(QueryResult * result, uint32 account)
        {
            WorldSession * session = sWorld.FindSession(account);
            if(!session)
            {
                delete result;
                return;
            }
            session->HandleCharEnum(result);
        }
        void HandlePlayerLoginCallback(QueryResult * /*dummy*/, SqlQueryHolder * holder)
        {
            if (!holder) return;
            WorldSession *session = sWorld.FindSession(((LoginQueryHolder*)holder)->GetAccountId());
            if(!session)
            {
                delete holder;
                return;
            }
            session->HandlePlayerLogin((LoginQueryHolder*)holder);
        }
} chrHandler;

void WorldSession::HandleCharEnum(QueryResult * result)
{
    // keys can be non cleared if player open realm list and close it by 'cancel'
    LoginDatabase.PExecute("UPDATE account SET v = '0', s = '0' WHERE id = '%u'", GetAccountId());

    WorldPacket data(SMSG_CHAR_ENUM, 100);                  // we guess size

    uint8 num = 0;

    data << num;

    if( result )
    {
        Player *plr = new Player(this);
        do
        {
            uint32 guidlow = (*result)[0].GetUInt32();
            sLog.outDetail("Loading char guid %u from account %u.",guidlow,GetAccountId());

            if(plr->MinimalLoadFromDB( result, guidlow ))
            {
                plr->BuildEnumData( result, &data );
                ++num;
            }
        }
        while( result->NextRow() );

        delete plr;
        delete result;
    }

    data.put<uint8>(0, num);

    SendPacket( &data );
}

void WorldSession::HandleCharEnumOpcode( WorldPacket & /*recv_data*/ )
{
    /// get all the data necessary for loading all characters (along with their pets) on the account
    CharacterDatabase.AsyncPQuery(&chrHandler, &CharacterHandler::HandleCharEnumCallback, GetAccountId(),
         !sWorld.getConfig(CONFIG_DECLINED_NAMES_USED) ?
    //   ------- Query Without Declined Names --------
    //          0                1                2                3                      4                      5               6                     7                     8
        "SELECT characters.guid, characters.data, characters.name, characters.position_x, characters.position_y, characters.position_z, characters.map, characters.totaltime, characters.leveltime, "
    //   9                    10                   11                     12                   13
        "characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, guild_member.guildid "
        "FROM characters LEFT JOIN character_pet ON characters.guid=character_pet.owner AND character_pet.slot='%u' "
        "LEFT JOIN guild_member ON characters.guid = guild_member.guid "
        "WHERE characters.account = '%u' ORDER BY characters.guid"
        :
    //   --------- Query With Declined Names ---------
    //          0                1                2                3                      4                      5               6                     7                     8
        "SELECT characters.guid, characters.data, characters.name, characters.position_x, characters.position_y, characters.position_z, characters.map, characters.totaltime, characters.leveltime, "
    //   9                    10                   11                     12                   13                    14
        "characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, guild_member.guildid, character_declinedname.genitive "
        "FROM characters LEFT JOIN character_pet ON characters.guid = character_pet.owner AND character_pet.slot='%u' "
        "LEFT JOIN character_declinedname ON characters.guid = character_declinedname.guid "
        "LEFT JOIN guild_member ON characters.guid = guild_member.guid "
        "WHERE characters.account = '%u' ORDER BY characters.guid",
        PET_SAVE_AS_CURRENT,GetAccountId());
}

void WorldSession::HandleCharCreateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,1+1+1+1+1+1+1+1+1+1);

    std::string name;
    uint8 race_,class_;

    recv_data >> name;

    // recheck with known string size
    CHECK_PACKET_SIZE(recv_data,(name.size()+1)+1+1+1+1+1+1+1+1+1);

    recv_data >> race_;
    recv_data >> class_;

    WorldPacket data(SMSG_CHAR_CREATE, 1);                  // returned with diff.values in all cases

    if(GetSecurity() == SEC_PLAYER)
    {
        if(uint32 mask = sWorld.getConfig(CONFIG_CHARACTERS_CREATING_DISABLED))
        {
            bool disabled = false;

            uint32 team = Player::TeamForRace(race_);
            switch(team)
            {
                case ALLIANCE: disabled = mask & (1<<0); break;
                case HORDE:    disabled = mask & (1<<1); break;
            }

            if(disabled)
            {
                data << (uint8)CHAR_CREATE_DISABLED;
                SendPacket( &data );
                return;
            }
        }
    }

    ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(class_);
    ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race_);

    if( !classEntry || !raceEntry )
    {
        data << (uint8)CHAR_CREATE_FAILED;
        SendPacket( &data );
        sLog.outError("Class: %u or Race %u not found in DBC (Wrong DBC files?) or Cheater?", class_, race_);
        return;
    }

    // prevent character creating Expansion race without Expansion account
    if (raceEntry->addon > Expansion())
    {
        data << (uint8)CHAR_CREATE_EXPANSION;
        sLog.outError("Expansion %u account:[%d] tried to Create character with expansion %u race (%u)",Expansion(),GetAccountId(),raceEntry->addon,race_);
        SendPacket( &data );
        return;
    }

    // prevent character creating Expansion class without Expansion account
    if (classEntry->addon > Expansion())
    {
        data << (uint8)CHAR_CREATE_EXPANSION_CLASS;
        sLog.outError("Expansion %u account:[%d] tried to Create character with expansion %u class (%u)",Expansion(),GetAccountId(),classEntry->addon,class_);
        SendPacket( &data );
        return;
    }

    // prevent character creating with invalid name
    if(!normalizePlayerName(name))
    {
        data << (uint8)CHAR_NAME_INVALID_CHARACTER;
        SendPacket( &data );
        sLog.outError("Account:[%d] but tried to Create character with empty [name] ",GetAccountId());
        return;
    }

    // check name limitations
    if(!ObjectMgr::IsValidName(name,true))
    {
        data << (uint8)CHAR_NAME_INVALID_CHARACTER;
        SendPacket( &data );
        return;
    }

    if(GetSecurity() == SEC_PLAYER && objmgr.IsReservedName(name))
    {
        data << (uint8)CHAR_NAME_RESERVED;
        SendPacket( &data );
        return;
    }

    if(objmgr.GetPlayerGUIDByName(name))
    {
        data << (uint8)CHAR_CREATE_NAME_IN_USE;
        SendPacket( &data );
        return;
    }

    QueryResult *resultacct = LoginDatabase.PQuery("SELECT SUM(numchars) FROM realmcharacters WHERE acctid = '%d'", GetAccountId());
    if ( resultacct )
    {
        Field *fields=resultacct->Fetch();
        uint32 acctcharcount = fields[0].GetUInt32();
        delete resultacct;

        if (acctcharcount >= sWorld.getConfig(CONFIG_CHARACTERS_PER_ACCOUNT))
        {
            data << (uint8)CHAR_CREATE_ACCOUNT_LIMIT;
            SendPacket( &data );
            return;
        }
    }

    QueryResult *result = CharacterDatabase.PQuery("SELECT COUNT(guid) FROM characters WHERE account = '%d'", GetAccountId());
    uint8 charcount = 0;
    if ( result )
    {
        Field *fields=result->Fetch();
        charcount = fields[0].GetUInt8();
        delete result;

        if (charcount >= sWorld.getConfig(CONFIG_CHARACTERS_PER_REALM))
        {
            data << (uint8)CHAR_CREATE_SERVER_LIMIT;
            SendPacket( &data );
            return;
        }
    }

    // speedup check for heroic class disabled case
    uint32 heroic_free_slots = sWorld.getConfig(CONFIG_HEROIC_CHARACTERS_PER_REALM);
    if(heroic_free_slots==0 && GetSecurity()==SEC_PLAYER && class_ == CLASS_DEATH_KNIGHT)
    {
        data << (uint8)CHAR_CREATE_UNIQUE_CLASS_LIMIT;
        SendPacket( &data );
        return;
    }

    // speedup check for heroic class disabled case
    uint32 req_level_for_heroic = sWorld.getConfig(CONFIG_MIN_LEVEL_FOR_HEROIC_CHARACTER_CREATING);
    if(GetSecurity()==SEC_PLAYER && class_ == CLASS_DEATH_KNIGHT && req_level_for_heroic > sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        data << (uint8)CHAR_CREATE_LEVEL_REQUIREMENT;
        SendPacket( &data );
        return;
    }

    bool AllowTwoSideAccounts = !sWorld.IsPvPRealm() || sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_ACCOUNTS) || GetSecurity() > SEC_PLAYER;
    uint32 skipCinematics = sWorld.getConfig(CONFIG_SKIP_CINEMATICS);

    bool have_same_race = false;

    // if 0 then allowed creating without any characters
    bool have_req_level_for_heroic = (req_level_for_heroic==0);

    if(!AllowTwoSideAccounts || skipCinematics == 1 || class_ == CLASS_DEATH_KNIGHT)
    {
        QueryResult *result2 = CharacterDatabase.PQuery("SELECT guid,race,class FROM characters WHERE account = '%u' %s",
            GetAccountId(), (skipCinematics == 1 || class_ == CLASS_DEATH_KNIGHT) ? "" : "LIMIT 1");
        if(result2)
        {
            uint32 team_= Player::TeamForRace(race_);

            Field* field = result2->Fetch();
            uint8 acc_race  = field[1].GetUInt32();

            if(GetSecurity()==SEC_PLAYER && class_ == CLASS_DEATH_KNIGHT)
            {
                uint8 acc_class = field[2].GetUInt32();
                if(acc_class == CLASS_DEATH_KNIGHT)
                {
                    if(heroic_free_slots > 0)
                        --heroic_free_slots;

                    if(heroic_free_slots==0)
                    {
                        data << (uint8)CHAR_CREATE_UNIQUE_CLASS_LIMIT;
                        SendPacket( &data );
                        return;
                    }
                }

                if(!have_req_level_for_heroic)
                {
                    uint32 acc_guid = field[0].GetUInt32();
                    uint32 acc_level = Player::GetUInt32ValueFromDB(UNIT_FIELD_LEVEL,acc_guid);
                    if(acc_level >= req_level_for_heroic)
                        have_req_level_for_heroic = true;
                }
            }

            // need to check team only for first character
            // TODO: what to if account already has characters of both races?
            if (!AllowTwoSideAccounts)
            {
                uint32 acc_team=0;
                if(acc_race > 0)
                    acc_team = Player::TeamForRace(acc_race);

                if(acc_team != team_)
                {
                    data << (uint8)CHAR_CREATE_PVP_TEAMS_VIOLATION;
                    SendPacket( &data );
                    delete result2;
                    return;
                }
            }

            // search same race for cinematic or same class if need
            // TODO: check if cinematic already shown? (already logged in?; cinematic field)
            while ((skipCinematics == 1 && !have_same_race) || class_ == CLASS_DEATH_KNIGHT)
            {
                if(!result2->NextRow())
                    break;

                field = result2->Fetch();
                acc_race = field[1].GetUInt32();

                if(!have_same_race)
                    have_same_race = race_ == acc_race;

                if(GetSecurity()==SEC_PLAYER && class_ == CLASS_DEATH_KNIGHT)
                {
                    uint8 acc_class = field[2].GetUInt32();
                    if(acc_class == CLASS_DEATH_KNIGHT)
                    {
                        if(heroic_free_slots > 0)
                            --heroic_free_slots;

                        if(heroic_free_slots==0)
                        {
                            data << (uint8)CHAR_CREATE_UNIQUE_CLASS_LIMIT;
                            SendPacket( &data );
                            return;
                        }
                    }

                    if(!have_req_level_for_heroic)
                    {
                        uint32 acc_guid = field[0].GetUInt32();
                        uint32 acc_level = Player::GetUInt32ValueFromDB(UNIT_FIELD_LEVEL,acc_guid);
                        if(acc_level >= req_level_for_heroic)
                            have_req_level_for_heroic = true;
                    }
                }
            }
            delete result2;
        }
    }

    if(GetSecurity()==SEC_PLAYER && class_ == CLASS_DEATH_KNIGHT && !have_req_level_for_heroic)
    {
        data << (uint8)CHAR_CREATE_LEVEL_REQUIREMENT;
        SendPacket( &data );
        return;
    }

    // extract other data required for player creating
    uint8 gender, skin, face, hairStyle, hairColor, facialHair, outfitId;
    recv_data >> gender >> skin >> face;
    recv_data >> hairStyle >> hairColor >> facialHair >> outfitId;

    Player * pNewChar = new Player(this);
    if(!pNewChar->Create( objmgr.GenerateLowGuid(HIGHGUID_PLAYER), name, race_, class_, gender, skin, face, hairStyle, hairColor, facialHair, outfitId ))
    {
        // Player not create (race/class problem?)
        delete pNewChar;

        data << (uint8)CHAR_CREATE_ERROR;
        SendPacket( &data );

        return;
    }

    if ((have_same_race && skipCinematics == 1) || skipCinematics == 2)
        pNewChar->setCinematic(1);                          // not show intro

    // Player created, save it now
    pNewChar->SaveToDB();
    charcount+=1;

    LoginDatabase.PExecute("DELETE FROM realmcharacters WHERE acctid= '%d' AND realmid = '%d'", GetAccountId(), realmID);
    LoginDatabase.PExecute("INSERT INTO realmcharacters (numchars, acctid, realmid) VALUES (%u, %u, %u)",  charcount, GetAccountId(), realmID);

    delete pNewChar;                                        // created only to call SaveToDB()

    data << (uint8)CHAR_CREATE_SUCCESS;
    SendPacket( &data );

    std::string IP_str = GetRemoteAddress();
    sLog.outDetail("Account: %d (IP: %s) Create Character:[%s]",GetAccountId(),IP_str.c_str(),name.c_str());
    sLog.outChar("Account: %d (IP: %s) Create Character:[%s]",GetAccountId(),IP_str.c_str(),name.c_str());
}

void WorldSession::HandleCharDeleteOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 guid;
    recv_data >> guid;

    // can't delete loaded character
    if(objmgr.GetPlayer(guid))
        return;

    uint32 accountId = 0;
    std::string name;

    // is guild leader
    if(objmgr.GetGuildByLeader(guid))
    {
        WorldPacket data(SMSG_CHAR_DELETE, 1);
        data << (uint8)CHAR_DELETE_FAILED_GUILD_LEADER;
        SendPacket( &data );
        return;
    }

    // is arena team captain
    if(objmgr.GetArenaTeamByCaptain(guid))
    {
        WorldPacket data(SMSG_CHAR_DELETE, 1);
        data << (uint8)CHAR_DELETE_FAILED_ARENA_CAPTAIN;
        SendPacket( &data );
        return;
    }

    QueryResult *result = CharacterDatabase.PQuery("SELECT account,name FROM characters WHERE guid='%u'", GUID_LOPART(guid));
    if(result)
    {
        Field *fields = result->Fetch();
        accountId = fields[0].GetUInt32();
        name = fields[1].GetCppString();
        delete result;
    }

    // prevent deleting other players' characters using cheating tools
    if(accountId != GetAccountId())
        return;

    std::string IP_str = GetRemoteAddress();
    sLog.outDetail("Account: %d (IP: %s) Delete Character:[%s] (guid: %u)",GetAccountId(),IP_str.c_str(),name.c_str(),GUID_LOPART(guid));
    sLog.outChar("Account: %d (IP: %s) Delete Character:[%s] (guid: %u)",GetAccountId(),IP_str.c_str(),name.c_str(),GUID_LOPART(guid));

    if(sLog.IsOutCharDump())                                // optimize GetPlayerDump call
    {
        std::string dump = PlayerDumpWriter().GetDump(GUID_LOPART(guid));
        sLog.outCharDump(dump.c_str(),GetAccountId(),GUID_LOPART(guid),name.c_str());
    }

    Player::DeleteFromDB(guid, GetAccountId());

    WorldPacket data(SMSG_CHAR_DELETE, 1);
    data << (uint8)CHAR_DELETE_SUCCESS;
    SendPacket( &data );
}

void WorldSession::HandlePlayerLoginOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    if(PlayerLoading() || GetPlayer() != NULL)
    {
        sLog.outError("Player tryes to login again, AccountId = %d",GetAccountId());
        return;
    }

    m_playerLoading = true;
    uint64 playerGuid = 0;

    DEBUG_LOG( "WORLD: Recvd Player Logon Message" );

    recv_data >> playerGuid;

    LoginQueryHolder *holder = new LoginQueryHolder(GetAccountId(), playerGuid);
    if(!holder->Initialize())
    {
        delete holder;                                      // delete all unprocessed queries
        m_playerLoading = false;
        return;
    }

    CharacterDatabase.DelayQueryHolder(&chrHandler, &CharacterHandler::HandlePlayerLoginCallback, holder);
}

void WorldSession::HandlePlayerLogin(LoginQueryHolder * holder)
{
    uint64 playerGuid = holder->GetGuid();

    Player* pCurrChar = new Player(this);
     // for send server info and strings (config)
    ChatHandler chH = ChatHandler(pCurrChar);

    // "GetAccountId()==db stored account id" checked in LoadFromDB (prevent login not own character using cheating tools)
    if(!pCurrChar->LoadFromDB(GUID_LOPART(playerGuid), holder))
    {
        KickPlayer();                                       // disconnect client, player no set to session and it will not deleted or saved at kick
        delete pCurrChar;                                   // delete it manually
        delete holder;                                      // delete all unprocessed queries
        m_playerLoading = false;
        return;
    }

    pCurrChar->GetMotionMaster()->Initialize();

    SetPlayer(pCurrChar);

    pCurrChar->SendDungeonDifficulty(false);

    WorldPacket data( SMSG_LOGIN_VERIFY_WORLD, 20 );
    data << pCurrChar->GetMapId();
    data << pCurrChar->GetPositionX();
    data << pCurrChar->GetPositionY();
    data << pCurrChar->GetPositionZ();
    data << pCurrChar->GetOrientation();
    SendPacket(&data);

    data.Initialize( SMSG_ACCOUNT_DATA_TIMES, 4+1+8*4 );    // changed in WotLK
    data << uint32(time(NULL));                             // unix time of something
    data << uint8(1);
    for(int i = 0; i < NUM_ACCOUNT_DATA_TYPES; ++i)
        data << uint32(GetAccountData(i)->Time);            // also unix time
    SendPacket(&data);

    data.Initialize(SMSG_FEATURE_SYSTEM_STATUS, 2);         // added in 2.2.0
    data << uint8(2);                                       // unknown value
    data << uint8(0);                                       // enable(1)/disable(0) voice chat interface in client
    SendPacket(&data);

    // Send MOTD
    {
        data.Initialize(SMSG_MOTD, 50);                     // new in 2.0.1
        data << (uint32)0;

        uint32 linecount=0;
        std::string str_motd = sWorld.GetMotd();
        std::string::size_type pos, nextpos;

        pos = 0;
        while ( (nextpos= str_motd.find('@',pos)) != std::string::npos )
        {
            if (nextpos != pos)
            {
                data << str_motd.substr(pos,nextpos-pos);
                ++linecount;
            }
            pos = nextpos+1;
        }

        if (pos<str_motd.length())
        {
            data << str_motd.substr(pos);
            ++linecount;
        }

        data.put(0, linecount);

        SendPacket( &data );
        DEBUG_LOG( "WORLD: Sent motd (SMSG_MOTD)" );

        // send server info
        if(sWorld.getConfig(CONFIG_ENABLE_SINFO_LOGIN) == 1)
            chH.PSendSysMessage(_FULLVERSION);

        DEBUG_LOG( "WORLD: Sent server info" );
    }

    data.Initialize(SMSG_LEARNED_DANCE_MOVES, 4+4);
    data << uint32(0);
    data << uint32(0);
    SendPacket(&data);

    //QueryResult *result = CharacterDatabase.PQuery("SELECT guildid,rank FROM guild_member WHERE guid = '%u'",pCurrChar->GetGUIDLow());
    QueryResult *resultGuild = holder->GetResult(PLAYER_LOGIN_QUERY_LOADGUILD);

    if(resultGuild)
    {
        Field *fields = resultGuild->Fetch();
        pCurrChar->SetInGuild(fields[0].GetUInt32());
        pCurrChar->SetRank(fields[1].GetUInt32());
        delete resultGuild;
    }
    else if(pCurrChar->GetGuildId())                        // clear guild related fields in case wrong data about non existed membership
    {
        pCurrChar->SetInGuild(0);
        pCurrChar->SetRank(0);
    }

    if(pCurrChar->GetGuildId() != 0)
    {
        Guild* guild = objmgr.GetGuildById(pCurrChar->GetGuildId());
        if(guild)
        {
            data.Initialize(SMSG_GUILD_EVENT, (2+guild->GetMOTD().size()+1));
            data << (uint8)GE_MOTD;
            data << (uint8)1;
            data << guild->GetMOTD();
            SendPacket(&data);
            DEBUG_LOG( "WORLD: Sent guild-motd (SMSG_GUILD_EVENT)" );

            data.Initialize(SMSG_GUILD_EVENT, (5+10));      // we guess size
            data<<(uint8)GE_SIGNED_ON;
            data<<(uint8)1;
            data<<pCurrChar->GetName();
            data<<pCurrChar->GetGUID();
            guild->BroadcastPacket(&data);
            DEBUG_LOG( "WORLD: Sent guild-signed-on (SMSG_GUILD_EVENT)" );

            // Increment online members of the guild
            guild->IncOnlineMemberCount();
        }
        else
        {
            // remove wrong guild data
            sLog.outError("Player %s (GUID: %u) marked as member not existed guild (id: %u), removing guild membership for player.",pCurrChar->GetName(),pCurrChar->GetGUIDLow(),pCurrChar->GetGuildId());
            pCurrChar->SetInGuild(0);
        }
    }

    if(!pCurrChar->isAlive())
        pCurrChar->SendCorpseReclaimDelay(true);

    pCurrChar->SendInitialPacketsBeforeAddToMap();

    //Show cinematic at the first time that player login
    if( !pCurrChar->getCinematic() )
    {
        pCurrChar->setCinematic(1);

        if(ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(pCurrChar->getClass()))
        {
            if (cEntry->CinematicSequence)
                pCurrChar->SendCinematicStart(cEntry->CinematicSequence);
            else if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(pCurrChar->getRace()))
                pCurrChar->SendCinematicStart(rEntry->CinematicSequence);

            // send new char string if not empty
            if (!sWorld.GetNewCharString().empty())
                chH.PSendSysMessage(sWorld.GetNewCharString().c_str());
        }
    }

    if (!pCurrChar->GetMap()->Add(pCurrChar))
    {
        AreaTrigger const* at = objmgr.GetGoBackTrigger(pCurrChar->GetMapId());
        if(at)
            pCurrChar->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, pCurrChar->GetOrientation());
        else
            pCurrChar->TeleportTo(pCurrChar->m_homebindMapId, pCurrChar->m_homebindX, pCurrChar->m_homebindY, pCurrChar->m_homebindZ, pCurrChar->GetOrientation());
    }

    ObjectAccessor::Instance().AddObject(pCurrChar);
    //sLog.outDebug("Player %s added to Map.",pCurrChar->GetName());
    pCurrChar->GetSocial()->SendSocialList();

    pCurrChar->SendInitialPacketsAfterAddToMap();

    CharacterDatabase.PExecute("UPDATE characters SET online = 1 WHERE guid = '%u'", pCurrChar->GetGUIDLow());
    LoginDatabase.PExecute("UPDATE account SET online = 1 WHERE id = '%u'", GetAccountId());
    pCurrChar->SetInGameTime( getMSTime() );

    // announce group about member online (must be after add to player list to receive announce to self)
    if(Group *group = pCurrChar->GetGroup())
    {
        //pCurrChar->groupInfo.group->SendInit(this); // useless
        group->SendUpdate();
    }

    // friend status
    sSocialMgr.SendFriendStatus(pCurrChar, FRIEND_ONLINE, pCurrChar->GetGUIDLow(), true);

    // Place character in world (and load zone) before some object loading
    pCurrChar->LoadCorpse();

    // setting Ghost+speed if dead
    if (pCurrChar->m_deathState != ALIVE)
    {
        // not blizz like, we must correctly save and load player instead...
        if(pCurrChar->getRace() == RACE_NIGHTELF)
            pCurrChar->CastSpell(pCurrChar, 20584, true, 0);// auras SPELL_AURA_INCREASE_SPEED(+speed in wisp form), SPELL_AURA_INCREASE_SWIM_SPEED(+swim speed in wisp form), SPELL_AURA_TRANSFORM (to wisp form)
        pCurrChar->CastSpell(pCurrChar, 8326, true, 0);     // auras SPELL_AURA_GHOST, SPELL_AURA_INCREASE_SPEED(why?), SPELL_AURA_INCREASE_SWIM_SPEED(why?)

        pCurrChar->SetMovement(MOVE_WATER_WALK);
    }

    if(uint32 sourceNode = pCurrChar->m_taxi.GetTaxiSource())
    {
        sLog.outDebug( "WORLD: Restart character %u taxi flight", pCurrChar->GetGUIDLow() );

        uint32 MountId = objmgr.GetTaxiMount(sourceNode, pCurrChar->GetTeam(),true);
        uint32 path = pCurrChar->m_taxi.GetCurrentTaxiPath();

        // search appropriate start path node
        uint32 startNode = 0;

        TaxiPathNodeList const& nodeList = sTaxiPathNodesByPath[path];

        float distPrev = MAP_SIZE*MAP_SIZE;
        float distNext =
            (nodeList[0].x-pCurrChar->GetPositionX())*(nodeList[0].x-pCurrChar->GetPositionX())+
            (nodeList[0].y-pCurrChar->GetPositionY())*(nodeList[0].y-pCurrChar->GetPositionY())+
            (nodeList[0].z-pCurrChar->GetPositionZ())*(nodeList[0].z-pCurrChar->GetPositionZ());

        for(uint32 i = 1; i < nodeList.size(); ++i)
        {
            TaxiPathNode const& node = nodeList[i];
            TaxiPathNode const& prevNode = nodeList[i-1];

            // skip nodes at another map
            if(node.mapid != pCurrChar->GetMapId())
                continue;

            distPrev = distNext;

            distNext =
                (node.x-pCurrChar->GetPositionX())*(node.x-pCurrChar->GetPositionX())+
                (node.y-pCurrChar->GetPositionY())*(node.y-pCurrChar->GetPositionY())+
                (node.z-pCurrChar->GetPositionZ())*(node.z-pCurrChar->GetPositionZ());

            float distNodes =
                (node.x-prevNode.x)*(node.x-prevNode.x)+
                (node.y-prevNode.y)*(node.y-prevNode.y)+
                (node.z-prevNode.z)*(node.z-prevNode.z);

            if(distNext + distPrev < distNodes)
            {
                startNode = i;
                break;
            }
        }

        SendDoFlight( MountId, path, startNode );
    }

    // Load pet if any (if player not alive and in taxi flight or another then pet will remember as temporary unsummoned)
    pCurrChar->LoadPet();

    // Set FFA PvP for non GM in non-rest mode
    if(sWorld.IsFFAPvPRealm() && !pCurrChar->isGameMaster() && !pCurrChar->HasFlag(PLAYER_FLAGS,PLAYER_FLAGS_RESTING) )
        pCurrChar->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

    if(pCurrChar->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP))
        pCurrChar->SetContestedPvP();

    // Apply at_login requests
    if(pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
    {
        pCurrChar->resetSpells();
        SendNotification(LANG_RESET_SPELLS);
    }

    if(pCurrChar->HasAtLoginFlag(AT_LOGIN_RESET_TALENTS))
    {
        pCurrChar->resetTalents(true);
        SendNotification(LANG_RESET_TALENTS);
    }

    // show time before shutdown if shutdown planned.
    if(sWorld.IsShutdowning())
        sWorld.ShutdownMsg(true,pCurrChar);

    if(sWorld.getConfig(CONFIG_ALL_TAXI_PATHS))
        pCurrChar->SetTaxiCheater(true);

    if(pCurrChar->isGameMaster())
        SendNotification(LANG_GM_ON);

    std::string IP_str = GetRemoteAddress();
    sLog.outChar("Account: %d (IP: %s) Login Character:[%s] (guid:%u)",
        GetAccountId(),IP_str.c_str(),pCurrChar->GetName() ,pCurrChar->GetGUIDLow());

    m_playerLoading = false;
    delete holder;
}

void WorldSession::HandleSetFactionAtWar( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+1);

    DEBUG_LOG( "WORLD: Received CMSG_SET_FACTION_ATWAR" );

    uint32 repListID;
    uint8  flag;

    recv_data >> repListID;
    recv_data >> flag;

    GetPlayer()->GetReputationMgr().SetAtWar(repListID,flag);
}

//I think this function is never used :/ I dunno, but i guess this opcode not exists
void WorldSession::HandleSetFactionCheat( WorldPacket & /*recv_data*/ )
{
    //CHECK_PACKET_SIZE(recv_data,4+4);

    sLog.outError("WORLD SESSION: HandleSetFactionCheat, not expected call, please report.");
    /*
        uint32 FactionID;
        uint32 Standing;

        recv_data >> FactionID;
        recv_data >> Standing;

        std::list<struct Factions>::iterator itr;

        for(itr = GetPlayer()->factions.begin(); itr != GetPlayer()->factions.end(); ++itr)
        {
            if(itr->ReputationListID == FactionID)
            {
                itr->Standing += Standing;
                itr->Flags = (itr->Flags | 1);
                break;
            }
        }
    */
    GetPlayer()->GetReputationMgr().SendStates();
}

void WorldSession::HandleMeetingStoneInfo( WorldPacket & /*recv_data*/ )
{
    DEBUG_LOG( "WORLD: Received CMSG_MEETING_STONE_INFO" );

    WorldPacket data(SMSG_MEETINGSTONE_SETQUEUE, 5);
    data << uint32(0) << uint8(6);
    SendPacket(&data);
}

void WorldSession::HandleTutorialFlag( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4);

    uint32 iFlag;
    recv_data >> iFlag;

    uint32 wInt = (iFlag / 32);
    if (wInt >= 8)
    {
        //sLog.outError("CHEATER? Account:[%d] Guid[%u] tried to send wrong CMSG_TUTORIAL_FLAG", GetAccountId(),GetGUID());
        return;
    }
    uint32 rInt = (iFlag % 32);

    uint32 tutflag = GetPlayer()->GetTutorialInt( wInt );
    tutflag |= (1 << rInt);
    GetPlayer()->SetTutorialInt( wInt, tutflag );

    //sLog.outDebug("Received Tutorial Flag Set {%u}.", iFlag);
}

void WorldSession::HandleTutorialClear( WorldPacket & /*recv_data*/ )
{
    for (int i = 0; i < 8; ++i)
        GetPlayer()->SetTutorialInt( i, 0xFFFFFFFF );
}

void WorldSession::HandleTutorialReset( WorldPacket & /*recv_data*/ )
{
    for (int i = 0; i < 8; ++i)
        GetPlayer()->SetTutorialInt( i, 0x00000000 );
}

void WorldSession::HandleSetWatchedFactionIndexOpcode(WorldPacket & recv_data)
{
    CHECK_PACKET_SIZE(recv_data,4);

    DEBUG_LOG("WORLD: Received CMSG_SET_WATCHED_FACTION");
    uint32 fact;
    recv_data >> fact;
    GetPlayer()->SetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, fact);
}

void WorldSession::HandleSetWatchedFactionInactiveOpcode(WorldPacket & recv_data)
{
    CHECK_PACKET_SIZE(recv_data,4+1);

    DEBUG_LOG("WORLD: Received CMSG_SET_FACTION_INACTIVE");
    uint32 replistid;
    uint8 inactive;
    recv_data >> replistid >> inactive;

    _player->GetReputationMgr().SetInactive(replistid, inactive);
}

void WorldSession::HandleToggleHelmOpcode( WorldPacket & /*recv_data*/ )
{
    DEBUG_LOG("CMSG_TOGGLE_HELM for %s", _player->GetName());
    _player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
}

void WorldSession::HandleToggleCloakOpcode( WorldPacket & /*recv_data*/ )
{
    DEBUG_LOG("CMSG_TOGGLE_CLOAK for %s", _player->GetName());
    _player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_CLOAK);
}

void WorldSession::HandleChangePlayerNameOpcode(WorldPacket& recv_data)
{
    CHECK_PACKET_SIZE(recv_data, 8+1);

    uint64 guid;
    std::string newname;

    recv_data >> guid;
    recv_data >> newname;

    // prevent character rename to invalid name
    if(!normalizePlayerName(newname))
    {
        WorldPacket data(SMSG_CHAR_RENAME, 1);
        data << uint8(CHAR_NAME_NO_NAME);
        SendPacket( &data );
        return;
    }

    if(!ObjectMgr::IsValidName(newname, true))
    {
        WorldPacket data(SMSG_CHAR_RENAME, 1);
        data << uint8(CHAR_NAME_INVALID_CHARACTER);
        SendPacket( &data );
        return;
    }

    // check name limitations
    if(GetSecurity() == SEC_PLAYER && objmgr.IsReservedName(newname))
    {
        WorldPacket data(SMSG_CHAR_RENAME, 1);
        data << uint8(CHAR_NAME_RESERVED);
        SendPacket( &data );
        return;
    }

    std::string escaped_newname = newname;
    CharacterDatabase.escape_string(escaped_newname);

    // make sure that the character belongs to the current account, that rename at login is enabled
    // and that there is no character with the desired new name
    CharacterDatabase.AsyncPQuery(&WorldSession::HandleChangePlayerNameOpcodeCallBack,
        GetAccountId(), newname,
        "SELECT guid, name FROM characters WHERE guid = %d AND account = %d AND (at_login & %d) = %d AND NOT EXISTS (SELECT NULL FROM characters WHERE name = '%s')",
        GUID_LOPART(guid), GetAccountId(), AT_LOGIN_RENAME, AT_LOGIN_RENAME, escaped_newname.c_str()
    );
}

void WorldSession::HandleChangePlayerNameOpcodeCallBack(QueryResult *result, uint32 accountId, std::string newname)
{
    WorldSession * session = sWorld.FindSession(accountId);
    if(!session)
    {
        if(result) delete result;
        return;
    }

    if (!result)
    {
        WorldPacket data(SMSG_CHAR_RENAME, 1);
        data << uint8(CHAR_CREATE_ERROR);
        session->SendPacket( &data );
        return;
    }

    uint32 guidLow = result->Fetch()[0].GetUInt32();
    uint64 guid = MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER);
    std::string oldname = result->Fetch()[1].GetCppString();

    delete result;

    CharacterDatabase.PExecute("UPDATE characters set name = '%s', at_login = at_login & ~ %u WHERE guid ='%u'", newname.c_str(), uint32(AT_LOGIN_RENAME), guidLow);
    CharacterDatabase.PExecute("DELETE FROM character_declinedname WHERE guid ='%u'", guidLow);

    sLog.outChar("Account: %d (IP: %s) Character:[%s] (guid:%u) Changed name to: %s", session->GetAccountId(), session->GetRemoteAddress().c_str(), oldname.c_str(), guidLow, newname.c_str());

    WorldPacket data(SMSG_CHAR_RENAME, 1+8+(newname.size()+1));
    data << uint8(RESPONSE_SUCCESS);
    data << uint64(guid);
    data << newname;
    session->SendPacket(&data);
}

void WorldSession::HandleDeclinedPlayerNameOpcode(WorldPacket& recv_data)
{
    uint64 guid;

    CHECK_PACKET_SIZE(recv_data, 8);
    recv_data >> guid;

    // not accept declined names for unsupported languages
    std::string name;
    if(!objmgr.GetPlayerNameByGUID(guid, name))
    {
        WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
        data << uint32(1);
        data << uint64(guid);
        SendPacket(&data);
        return;
    }

    std::wstring wname;
    if(!Utf8toWStr(name, wname))
    {
        WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
        data << uint32(1);
        data << uint64(guid);
        SendPacket(&data);
        return;
    }

    if(!isCyrillicCharacter(wname[0]))                      // name already stored as only single alphabet using
    {
        WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
        data << uint32(1);
        data << uint64(guid);
        SendPacket(&data);
        return;
    }

    std::string name2;
    DeclinedName declinedname;

    CHECK_PACKET_SIZE(recv_data, recv_data.rpos() + 1);
    recv_data >> name2;

    if(name2 != name)                                       // character have different name
    {
        WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
        data << uint32(1);
        data << uint64(guid);
        SendPacket(&data);
        return;
    }

    for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
    {
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos() + 1);
        recv_data >> declinedname.name[i];
        if(!normalizePlayerName(declinedname.name[i]))
        {
            WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
            data << uint32(1);
            data << uint64(guid);
            SendPacket(&data);
            return;
        }
    }

    if(!ObjectMgr::CheckDeclinedNames(GetMainPartOfName(wname, 0), declinedname))
    {
        WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
        data << uint32(1);
        data << uint64(guid);
        SendPacket(&data);
        return;
    }

    for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        CharacterDatabase.escape_string(declinedname.name[i]);

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM character_declinedname WHERE guid = '%u'", GUID_LOPART(guid));
    CharacterDatabase.PExecute("INSERT INTO character_declinedname (guid, genitive, dative, accusative, instrumental, prepositional) VALUES ('%u','%s','%s','%s','%s','%s')",
        GUID_LOPART(guid), declinedname.name[0].c_str(), declinedname.name[1].c_str(), declinedname.name[2].c_str(), declinedname.name[3].c_str(), declinedname.name[4].c_str());
    CharacterDatabase.CommitTransaction();

    WorldPacket data(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 4+8);
    data << uint32(0);                                      // OK
    data << uint64(guid);
    SendPacket(&data);
}

void WorldSession::HandleAlterAppearance( WorldPacket & recv_data )
{
    sLog.outDebug("CMSG_ALTER_APPEARANCE");

    CHECK_PACKET_SIZE(recv_data, 4+4+4);

    uint32 Hair, Color, FacialHair;
    recv_data >> Hair >> Color >> FacialHair;

    BarberShopStyleEntry const* bs_hair = sBarberShopStyleStore.LookupEntry(Hair);

    if(!bs_hair || bs_hair->type != 0 || bs_hair->race != _player->getRace() || bs_hair->gender != _player->getGender())
        return;

    BarberShopStyleEntry const* bs_facialHair = sBarberShopStyleStore.LookupEntry(FacialHair);

    if(!bs_facialHair || bs_facialHair->type != 2 || bs_facialHair->race != _player->getRace() || bs_facialHair->gender != _player->getGender())
        return;

    uint32 Cost = _player->GetBarberShopCost(bs_hair->hair_id, Color, bs_facialHair->hair_id);

    // 0 - ok
    // 1,3 - not enough money
    // 2 - you have to seat on barber chair
    if(_player->GetMoney() < Cost)
    {
        WorldPacket data(SMSG_BARBER_SHOP_RESULT, 4);
        data << uint32(1);                                  // no money
        SendPacket(&data);
        return;
    }
    else
    {
        WorldPacket data(SMSG_BARBER_SHOP_RESULT, 4);
        data << uint32(0);                                  // ok
        SendPacket(&data);
    }

    _player->ModifyMoney(-int32(Cost));                     // it isn't free
    _player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER, Cost);

    _player->SetByteValue(PLAYER_BYTES, 2, uint8(bs_hair->hair_id));
    _player->SetByteValue(PLAYER_BYTES, 3, uint8(Color));
    _player->SetByteValue(PLAYER_BYTES_2, 0, uint8(bs_facialHair->hair_id));

    _player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP, 1);

    _player->SetStandState(0);                              // stand up
}

void WorldSession::HandleRemoveGlyph( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4);

    uint32 slot;
    recv_data >> slot;

    if(slot >= MAX_GLYPH_SLOT_INDEX)
    {
        sLog.outDebug("Client sent wrong glyph slot number in opcode CMSG_REMOVE_GLYPH %u", slot);
        return;
    }

    if(uint32 glyph = _player->GetGlyph(slot))
    {
        if(GlyphPropertiesEntry const *gp = sGlyphPropertiesStore.LookupEntry(glyph))
        {
            _player->RemoveAurasDueToSpell(gp->SpellId);
            _player->SetGlyph(slot, 0);
        }
    }
}

void WorldSession::HandleCharCustomize(WorldPacket& recv_data)
{
    CHECK_PACKET_SIZE(recv_data, 8+1);

    uint64 guid;
    std::string newname;

    recv_data >> guid;
    recv_data >> newname;

    CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1+1+1+1+1+1);

    uint8 gender, skin, face, hairStyle, hairColor, facialHair;
    recv_data >> gender >> skin >> hairColor >> hairStyle >> facialHair >> face;

    QueryResult *result = CharacterDatabase.PQuery("SELECT at_login FROM characters WHERE guid ='%u'", GUID_LOPART(guid));
    if (!result)
    {
        WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
        data << uint8(CHAR_CREATE_ERROR);
        SendPacket( &data );
        return;
    }

    Field *fields = result->Fetch();
    uint32 at_loginFlags = fields[0].GetUInt32();
    delete result;

    if (!(at_loginFlags & AT_LOGIN_CUSTOMIZE))
    {
        WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
        data << uint8(CHAR_CREATE_ERROR);
        SendPacket( &data );
        return;
    }

    // prevent character rename to invalid name
    if(!normalizePlayerName(newname))
    {
        WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
        data << uint8(CHAR_NAME_NO_NAME);
        SendPacket( &data );
        return;
    }

    if(!ObjectMgr::IsValidName(newname,true))
    {
        WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
        data << uint8(CHAR_NAME_INVALID_CHARACTER);
        SendPacket( &data );
        return;
    }

    // check name limitations
    if(GetSecurity() == SEC_PLAYER && objmgr.IsReservedName(newname))
    {
        WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
        data << uint8(CHAR_NAME_RESERVED);
        SendPacket( &data );
        return;
    }

    // character with this name already exist
    if(uint64 newguid = objmgr.GetPlayerGUIDByName(newname))
    {
        if(newguid != guid)
        {
            WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1);
            data << uint8(CHAR_CREATE_NAME_IN_USE);
            SendPacket( &data );
            return;
        }
    }

    CharacterDatabase.escape_string(newname);
    Player::Customize(guid, gender, skin, face, hairStyle, hairColor, facialHair);
    CharacterDatabase.PExecute("UPDATE characters set name = '%s', at_login = at_login & ~ %u WHERE guid ='%u'", newname.c_str(), uint32(AT_LOGIN_CUSTOMIZE), GUID_LOPART(guid));
    CharacterDatabase.PExecute("DELETE FROM character_declinedname WHERE guid ='%u'", GUID_LOPART(guid));

    std::string IP_str = GetRemoteAddress();
    sLog.outChar("Account: %d (IP: %s), Character guid: %u Customized to: %s", GetAccountId(), IP_str.c_str(), GUID_LOPART(guid), newname.c_str());

    WorldPacket data(SMSG_CHAR_CUSTOMIZE, 1+8+(newname.size()+1)+6);
    data << uint8(RESPONSE_SUCCESS);
    data << uint64(guid);
    data << newname;
    data << uint8(gender);
    data << uint8(skin);
    data << uint8(face);
    data << uint8(hairStyle);
    data << uint8(hairColor);
    data << uint8(facialHair);
    SendPacket(&data);
}
