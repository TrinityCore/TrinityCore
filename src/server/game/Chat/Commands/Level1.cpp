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

#include "Common.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "TicketMgr.h"
#include "Player.h"
#include "AccountMgr.h"
#include "Opcodes.h"
#include "Chat.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "CellImpl.h"
#include "InstanceSaveMgr.h"
#include "Util.h"
#include "Group.h"

#ifdef _DEBUG_VMAPS
#include "VMapFactory.h"
#endif

bool ChatHandler::HandleNameAnnounceCommand(const char* args)
{
    WorldPacket data;
    if (!*args)
        return false;

    std::string name("Console");
    if (WorldSession* session = GetSession())
        name = session->GetPlayer()->GetName();

    sWorld->SendWorldText(LANG_ANNOUNCE_COLOR, name.c_str(), args);
    return true;
}

bool ChatHandler::HandleGMNameAnnounceCommand(const char* args)
{
    WorldPacket data;
    if (!*args)
        return false;

    std::string name("Console");
    if (WorldSession* session = GetSession())
        name = session->GetPlayer()->GetName();

    sWorld->SendGMText(LANG_GM_ANNOUNCE_COLOR, name.c_str(), args);
    return true;
}

// global announce
bool ChatHandler::HandleAnnounceCommand(const char* args)
{
    if (!*args)
        return false;

    char buff[2048];
    sprintf(buff, GetTrinityString(LANG_SYSTEMMESSAGE), args);
    sWorld->SendServerMessage(SERVER_MSG_STRING, buff);
    return true;
}

// announce to logged in GMs
bool ChatHandler::HandleGMAnnounceCommand(const char* args)
{
    if (!*args)
        return false;

    sWorld->SendGMText(LANG_GM_BROADCAST, args);
    return true;
}

//notification player at the screen
bool ChatHandler::HandleNotifyCommand(const char* args)
{
    if (!*args)
        return false;

    std::string str = GetTrinityString(LANG_GLOBAL_NOTIFY);
    str += args;

    WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
    data << str;
    sWorld->SendGlobalMessage(&data);

    return true;
}

//notification GM at the screen
bool ChatHandler::HandleGMNotifyCommand(const char* args)
{
    if (!*args)
        return false;

    std::string str = GetTrinityString(LANG_GM_NOTIFY);
    str += args;

    WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
    data << str;
    sWorld->SendGlobalGMMessage(&data);

    return true;
}

bool ChatHandler::HandleGPSCommand(const char* args)
{
    WorldObject *obj = NULL;
    if (*args)
    {
        uint64 guid = extractGuidFromLink((char*)args);
        if (guid)
            obj = (WorldObject*)ObjectAccessor::GetObjectByTypeMask(*m_session->GetPlayer(), guid, TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = getSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }
    CellPair cell_val = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(cell_val);

    uint32 zone_id, area_id;
    obj->GetZoneAndAreaId(zone_id, area_id);

    MapEntry const* mapEntry = sMapStore.LookupEntry(obj->GetMapId());
    AreaTableEntry const* zoneEntry = GetAreaEntryByAreaID(zone_id);
    AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(area_id);

    float zone_x = obj->GetPositionX();
    float zone_y = obj->GetPositionY();

    Map2ZoneCoordinates(zone_x, zone_y, zone_id);

    Map const *map = obj->GetMap();
    float ground_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), MAX_HEIGHT);
    float floor_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ());

    GridPair p = Trinity::ComputeGridPair(obj->GetPositionX(), obj->GetPositionY());

    // 63? WHY?
    int gx = 63 - p.x_coord;
    int gy = 63 - p.y_coord;

    uint32 have_map = Map::ExistMap(obj->GetMapId(), gx, gy) ? 1 : 0;
    uint32 have_vmap = Map::ExistVMap(obj->GetMapId(), gx, gy) ? 1 : 0;

    if (have_vmap)
    {
        if (map->IsOutdoors(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ()))
            PSendSysMessage("You are outdoors");
        else
            PSendSysMessage("You are indoors");
    }
    else PSendSysMessage("no VMAP available for area info");

    PSendSysMessage(LANG_MAP_POSITION,
        obj->GetMapId(), (mapEntry ? mapEntry->name[GetSessionDbcLocale()] : "<unknown>"),
        zone_id, (zoneEntry ? zoneEntry->area_name[GetSessionDbcLocale()] : "<unknown>"),
        area_id, (areaEntry ? areaEntry->area_name[GetSessionDbcLocale()] : "<unknown>"),
        obj->GetPhaseMask(),
        obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation(),
        cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), obj->GetInstanceId(),
        zone_x, zone_y, ground_z, floor_z, have_map, have_vmap);

    LiquidData liquid_status;
    ZLiquidStatus res = map->getLiquidStatus(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), MAP_ALL_LIQUIDS, &liquid_status);
    if (res)
    {
        PSendSysMessage(LANG_LIQUID_STATUS, liquid_status.level, liquid_status.depth_level, liquid_status.type, res);
    }
    return true;
}

//Summon Player
bool ChatHandler::HandleSummonCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    Player* _player = m_session->GetPlayer();
    if (target == _player || target_guid == _player->GetGUID())
    {
        PSendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        std::string nameLink = playerLink(target_name);
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        if (target->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, nameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        Map* pMap = m_session->GetPlayer()->GetMap();

        if (pMap->IsBattlegroundOrArena())
        {
            // only allow if gm mode is on
            if (!_player->isGameMaster())
            {
                PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, nameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            // if both players are in different bgs
            else if (target->GetBattlegroundId() && m_session->GetPlayer()->GetBattlegroundId() != target->GetBattlegroundId())
                target->LeaveBattleground(false); // Note: should be changed so target gets no Deserter debuff

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            target->SetBattlegroundId(m_session->GetPlayer()->GetBattlegroundId(), m_session->GetPlayer()->GetBattlegroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!target->GetMap()->IsBattlegroundOrArena())
                target->SetBattlegroundEntryPoint();
        }
        else if (pMap->IsDungeon())
        {
            Map* cMap = target->GetMap();

            if (cMap->Instanceable() && cMap->GetInstanceId() != pMap->GetInstanceId())
                target->UnbindInstance(pMap->GetInstanceId(), target->GetDungeonDifficulty(), true);

            // we are in instance, and can summon only player in our group with us as lead
            if (!m_session->GetPlayer()->GetGroup() || !target->GetGroup() ||
                (target->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()) ||
                (m_session->GetPlayer()->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()))
                // the last check is a bit excessive, but let it be, just in case
            {
                PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, nameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }

        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), "");
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_SUMMONED_BY, playerLink(_player->GetName()).c_str());

        // stop flight if need
        if (target->isInFlight())
        {
            target->GetMotionMaster()->MovementExpired();
            target->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            target->SaveRecallPosition();

        // before GM
        float x, y, z;
        m_session->GetPlayer()->GetClosePoint(x, y, z, target->GetObjectSize());
        target->TeleportTo(m_session->GetPlayer()->GetMapId(), x, y, z, target->GetOrientation());
        target->SetPhaseMask(m_session->GetPlayer()->GetPhaseMask(), true);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), GetTrinityString(LANG_OFFLINE));

        // in point where GM stay
        Player::SavePositionInDB(m_session->GetPlayer()->GetMapId(),
            m_session->GetPlayer()->GetPositionX(),
            m_session->GetPlayer()->GetPositionY(),
            m_session->GetPlayer()->GetPositionZ(),
            m_session->GetPlayer()->GetOrientation(),
            m_session->GetPlayer()->GetZoneId(),
            target_guid);
    }

    return true;
}

//Teleport to Player
bool ChatHandler::HandleAppearCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    Player* _player = m_session->GetPlayer();
    if (target == _player || target_guid == _player->GetGUID())
    {
        SendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        std::string chrNameLink = playerLink(target_name);

        Map* cMap = target->GetMap();
        if (cMap->IsBattlegroundOrArena())
        {
            // only allow if gm mode is on
            if (!_player->isGameMaster())
            {
                PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, chrNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            // if both players are in different bgs
            else if (_player->GetBattlegroundId() && _player->GetBattlegroundId() != target->GetBattlegroundId())
                _player->LeaveBattleground(false); // Note: should be changed so _player gets no Deserter debuff

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            _player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!_player->GetMap()->IsBattlegroundOrArena())
                _player->SetBattlegroundEntryPoint();
        }
        else if (cMap->IsDungeon())
        {
            // we have to go to instance, and can go to player only if:
            //   1) we are in his group (either as leader or as member)
            //   2) we are not bound to any group and have GM mode on
            if (_player->GetGroup())
            {
                // we are in group, we can go only if we are in the player group
                if (_player->GetGroup() != target->GetGroup())
                {
                    PSendSysMessage(LANG_CANNOT_GO_TO_INST_PARTY, chrNameLink.c_str());
                    SetSentErrorMessage(true);
                    return false;
                }
            }
            else
            {
                // we are not in group, let's verify our GM mode
                if (!_player->isGameMaster())
                {
                    PSendSysMessage(LANG_CANNOT_GO_TO_INST_GM, chrNameLink.c_str());
                    SetSentErrorMessage(true);
                    return false;
                }
            }

            // if the player or the player's group is bound to another instance
            // the player will not be bound to another one
            InstancePlayerBind *pBind = _player->GetBoundInstance(target->GetMapId(), target->GetDifficulty(cMap->IsRaid()));
            if (!pBind)
            {
                Group* group = _player->GetGroup();
                // if no bind exists, create a solo bind
                InstanceGroupBind *gBind = group ? group->GetBoundInstance(target) : NULL;                // if no bind exists, create a solo bind
                if (!gBind)
                    if (InstanceSave *save = sInstanceSaveMgr->GetInstanceSave(target->GetInstanceId()))
                        _player->BindToInstance(save, !save->CanReset());
            }

            if (cMap->IsRaid())
                _player->SetRaidDifficulty(target->GetRaidDifficulty());
            else
                _player->SetDungeonDifficulty(target->GetDungeonDifficulty());
        }

        PSendSysMessage(LANG_APPEARING_AT, chrNameLink.c_str());

        // stop flight if need
        if (_player->isInFlight())
        {
            _player->GetMotionMaster()->MovementExpired();
            _player->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            _player->SaveRecallPosition();

        // to point to see at target with same orientation
        float x, y, z;
        target->GetContactPoint(_player, x, y, z);

        _player->TeleportTo(target->GetMapId(), x, y, z, _player->GetAngle(target), TELE_TO_GM_MODE);
        _player->SetPhaseMask(target->GetPhaseMask(), true);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_APPEARING_AT, nameLink.c_str());

        // to point where player stay (if loaded)
        float x, y, z, o;
        uint32 map;
        bool in_flight;
        if (!Player::LoadPositionFromDB(map, x, y, z, o, in_flight, target_guid))
            return false;

        // stop flight if need
        if (_player->isInFlight())
        {
            _player->GetMotionMaster()->MovementExpired();
            _player->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            _player->SaveRecallPosition();

        _player->TeleportTo(map, x, y, z, _player->GetOrientation());
    }

    return true;
}

// Teleport player to last position
bool ChatHandler::HandleRecallCommand(const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    if (target->IsBeingTeleported())
    {
        PSendSysMessage(LANG_IS_TELEPORTED, GetNameLink(target).c_str());
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (target->isInFlight())
    {
        target->GetMotionMaster()->MovementExpired();
        target->CleanupAfterTaxiFlight();
    }

    target->TeleportTo(target->m_recallMap, target->m_recallX, target->m_recallY, target->m_recallZ, target->m_recallO);
    return true;
}

//Enable On\OFF all taxi paths
bool ChatHandler::HandleTaxiCheatCommand(const char* args)
{
    if (!*args)
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    std::string argstr = (char*)args;

    Player *chr = getSelectedPlayer();
    if (!chr)
    {
        chr=m_session->GetPlayer();
    }

    // check online security
    else if (HasLowerSecurity(chr, 0))
        return false;

    if (argstr == "on")
    {
        chr->SetTaxiCheater(true);
        PSendSysMessage(LANG_YOU_GIVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_ADDED, GetNameLink().c_str());
        return true;
    }

    if (argstr == "off")
    {
        chr->SetTaxiCheater(false);
        PSendSysMessage(LANG_YOU_REMOVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_REMOVED, GetNameLink().c_str());

        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

bool ChatHandler::HandleLookupAreaCommand(const char* args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr (namepart, wnamepart))
        return false;

    bool found = false;
    uint32 count = 0;
    uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

    // converting string that we try to find to lower case
    wstrToLower (wnamepart);

    // Search in AreaTable.dbc
    for (uint32 areaflag = 0; areaflag < sAreaStore.GetNumRows (); ++areaflag)
    {
        AreaTableEntry const *areaEntry = sAreaStore.LookupEntry (areaflag);
        if (areaEntry)
        {
            int loc = GetSessionDbcLocale ();
            std::string name = areaEntry->area_name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo (name, wnamepart))
            {
                loc = 0;
                for (; loc < TOTAL_LOCALES; ++loc)
                {
                    if (loc == GetSessionDbcLocale ())
                        continue;

                    name = areaEntry->area_name[loc];
                    if (name.empty ())
                        continue;

                    if (Utf8FitTo (name, wnamepart))
                        break;
                }
            }

            if (loc < TOTAL_LOCALES)
            {
                if (maxResults && count++ == maxResults)
                {
                    PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                // send area in "id - [name]" format
                std::ostringstream ss;
                if (m_session)
                    ss << areaEntry->ID << " - |cffffffff|Harea:" << areaEntry->ID << "|h[" << name << " " << localeNames[loc]<< "]|h|r";
                else
                    ss << areaEntry->ID << " - " << name << " " << localeNames[loc];

                SendSysMessage (ss.str ().c_str());

                if (!found)
                    found = true;
            }
        }
    }

    if (!found)
        SendSysMessage (LANG_COMMAND_NOAREAFOUND);

    return true;
}

//Find tele in game_tele order by name
bool ChatHandler::HandleLookupTeleCommand(const char * args)
{
    if (!*args)
    {
        SendSysMessage(LANG_COMMAND_TELE_PARAMETER);
        SetSentErrorMessage(true);
        return false;
    }

    char const* str = strtok((char*)args, " ");
    if (!str)
        return false;

    std::string namepart = str;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart, wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    std::ostringstream reply;
    uint32 count = 0;
    uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
    bool limitReached = false;

    GameTeleMap const & teleMap = sObjectMgr->GetGameTeleMap();
    for (GameTeleMap::const_iterator itr = teleMap.begin(); itr != teleMap.end(); ++itr)
    {
        GameTele const* tele = &itr->second;

        if (tele->wnameLow.find(wnamepart) == std::wstring::npos)
            continue;

        if (maxResults && count++ == maxResults)
        {
            limitReached = true;
            break;
        }

        if (m_session)
            reply << "  |cffffffff|Htele:" << itr->first << "|h[" << tele->name << "]|h|r\n";
        else
            reply << "  " << itr->first << " " << tele->name << "\n";
    }

    if (reply.str().empty())
        SendSysMessage(LANG_COMMAND_TELE_NOLOCATION);
    else
        PSendSysMessage(LANG_COMMAND_TELE_LOCATION, reply.str().c_str());

    if (limitReached)
        PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);

    return true;
}

//Enable\Dissable accept whispers (for GM)
bool ChatHandler::HandleWhispersCommand(const char* args)
{
    if (!*args)
    {
        PSendSysMessage(LANG_COMMAND_WHISPERACCEPTING, m_session->GetPlayer()->isAcceptWhispers() ?  GetTrinityString(LANG_ON) : GetTrinityString(LANG_OFF));
        return true;
    }

    std::string argstr = (char*)args;
    // whisper on
    if (argstr == "on")
    {
        m_session->GetPlayer()->SetAcceptWhispers(true);
        SendSysMessage(LANG_COMMAND_WHISPERON);
        return true;
    }

    // whisper off
    if (argstr == "off")
    {
        m_session->GetPlayer()->SetAcceptWhispers(false);
        SendSysMessage(LANG_COMMAND_WHISPEROFF);
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

//Save all players in the world
bool ChatHandler::HandleSaveAllCommand(const char* /*args*/)
{
    sObjectAccessor->SaveAllPlayers();
    SendSysMessage(LANG_PLAYERS_SAVED);
    return true;
}

// Jail by WarHead edited by spgm
bool ChatHandler::HandleJailCommand(const char *args)
{
    std::string cname, announce, ban_reason, ban_by;
    time_t localtime;
    localtime = time(NULL);

    char *charname = strtok((char*)args, " ");
    if (charname == NULL)
    {
        SendSysMessage(LANG_JAIL_NONAME);
        return true;
    } else cname = charname;

    char *timetojail = strtok(NULL, " ");
    if (timetojail == NULL)
    {
        SendSysMessage(LANG_JAIL_NOTIME);
        return true;
    }

    uint32 jailtime = (uint32) atoi((char*)timetojail);
    if (jailtime < 1 || jailtime > sObjectMgr->m_jailconf_max_duration)
    {
        PSendSysMessage(LANG_JAIL_VALUE, sObjectMgr->m_jailconf_max_duration);
        return true;
    }

    char *reason = strtok(NULL, "\0");
    std::string jailreason;
    if (reason == NULL || strlen((const char*)reason) < sObjectMgr->m_jailconf_min_reason)
    {
        PSendSysMessage(LANG_JAIL_NOREASON, sObjectMgr->m_jailconf_min_reason);
        return true;
    } else jailreason = reason;

    uint64 GUID = sObjectMgr->GetPlayerGUIDByName(cname.c_str());
    if (GUID == 0)
    {
        SendSysMessage(LANG_JAIL_WRONG_NAME);
        return true;
    }

    Player *chr = sObjectMgr->GetPlayer(GUID);
    if (!chr)
    {
		uint32 jail_guid = GUID_LOPART(GUID);
		std::string jail_char = cname;
		bool jail_isjailed = true;
		uint32 jail_release = localtime + (jailtime * 60 * 60);
		uint32 jail_amnestietime = localtime +(60* 60 * 24 * sObjectMgr->m_jailconf_amnestie);
		std::string jail_reason = jailreason;
		uint32 jail_times = 0;

		SQLTransaction trans = CharacterDatabase.BeginTransaction();
		QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `jail` WHERE `guid`='%u' LIMIT 1", jail_guid);
		CharacterDatabase.CommitTransaction(trans);

        if (!result)
        {
            jail_times = 1;
        }
        else
        {
            Field *fields = result->Fetch();
            jail_times = fields[5].GetUInt32()+1;
        }

        uint32 jail_gmacc = m_session->GetAccountId();
        std::string jail_gmchar = m_session->GetPlayerName();

        SQLTransaction trans2 = CharacterDatabase.BeginTransaction();
		if (!result) CharacterDatabase.PExecute("INSERT INTO `jail` VALUES ('%u','%s','%u','%u','%s','%u','%u','%s',CURRENT_TIMESTAMP,'%u')", jail_guid, jail_char.c_str(), jail_release, jail_amnestietime, jail_reason.c_str(), jail_times, jail_gmacc, jail_gmchar.c_str(), jailtime);
        else CharacterDatabase.PExecute("UPDATE `jail` SET `release`='%u', `amnestietime`='%u',`reason`='%s',`times`='%u',`gmacc`='%u',`gmchar`='%s',`duration`='%u' WHERE `guid`='%u' LIMIT 1", jail_release, jail_amnestietime, jail_reason.c_str(), jail_times, jail_gmacc, jail_gmchar.c_str(), jailtime, jail_guid);
        CharacterDatabase.CommitTransaction(trans2);

        PSendSysMessage(LANG_JAIL_WAS_JAILED, cname.c_str(), jailtime);

        announce = GetTrinityString(LANG_JAIL_ANNOUNCE1);
        announce += cname;
        announce += GetTrinityString(LANG_JAIL_ANNOUNCE2);
        announce += timetojail;
        announce += GetTrinityString(LANG_JAIL_ANNOUNCE3);
        announce += m_session->GetPlayerName();
        announce += GetTrinityString(LANG_JAIL_ANNOUNCE4);
        announce += jail_reason;

        HandleAnnounceCommand(announce.c_str());

        if ((sObjectMgr->m_jailconf_max_jails == jail_times) && !sObjectMgr->m_jailconf_ban)
        {
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`='%u' LIMIT 1", GUID_LOPART(GUID));
            CharacterDatabase.CommitTransaction(trans);

            if (!result)
            {
                PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                return true;
            }

            Field *fields = result->Fetch();

            Player::DeleteFromDB(GUID, fields[1].GetUInt32());
        }
        else if ((sObjectMgr->m_jailconf_max_jails == jail_times) && sObjectMgr->m_jailconf_ban)
        {
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`='%u' LIMIT 1", GUID_LOPART(GUID));
            CharacterDatabase.CommitTransaction(trans);

            if (!result)
            {
                PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                return true;
            }
            Field *fields = result->Fetch();
            uint32 acc_id = fields[1].GetUInt32();

            SQLTransaction trans2 = LoginDatabase.BeginTransaction();
            result = LoginDatabase.PQuery("SELECT * FROM `account` WHERE `id`='%u' LIMIT 1", acc_id);
            LoginDatabase.CommitTransaction(trans2);

            if (!result)
            {
                PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                return true;
            }
            ban_reason = GetTrinityString(LANG_JAIL_BAN_REASON);
            ban_by = GetTrinityString(LANG_JAIL_BAN_BY);

            SQLTransaction trans3 = LoginDatabase.BeginTransaction();
            LoginDatabase.PExecute("INSERT IGNORE INTO `account_banned` (`id`,`bandate`,`bannedby`,`banreason`) VALUES ('%u',UNIX_TIMESTAMP,'%s','%s')", acc_id, ban_by.c_str(), ban_reason.c_str());
            LoginDatabase.CommitTransaction(trans3);

        }
        return true;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`='%u' LIMIT 1", chr->GetGUIDLow());
    CharacterDatabase.CommitTransaction(trans);

    if (!result)
    {
        PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
        return true;
    }

    Field *fields = result->Fetch();

    if (chr->GetName() == m_session->GetPlayerName())
    {
        SendSysMessage(LANG_JAIL_NO_JAIL);
        return true;
    }

		chr->SaveToDB();

		chr->m_jail_guid = fields[0].GetUInt32();
		chr->m_jail_char = fields[3].GetString();
		chr->m_jail_isjailed = true;
		chr->m_jail_release = localtime + (jailtime * 60 * 60);
		chr->m_jail_amnestietime = localtime +(60* 60 * 24 * sObjectMgr->m_jailconf_amnestie);
		chr->m_jail_reason = jailreason;
		chr->m_jail_times = chr->m_jail_times+1;
		chr->m_jail_gmacc = m_session->GetAccountId();
		chr->m_jail_gmchar = m_session->GetPlayerName();
		chr->m_jail_duration = jailtime;

		chr->_SaveJail();

		PSendSysMessage(LANG_JAIL_WAS_JAILED, fields[3].GetString().c_str(), jailtime);
		ChatHandler(chr).PSendSysMessage(LANG_JAIL_YOURE_JAILED, m_session->GetPlayerName(), jailtime);
		ChatHandler(chr).PSendSysMessage(LANG_JAIL_REASON, m_session->GetPlayerName(), jailreason.c_str());

		announce = GetTrinityString(LANG_JAIL_ANNOUNCE1);
		announce += fields[3].GetString();
		announce += GetTrinityString(LANG_JAIL_ANNOUNCE2);
		announce += timetojail;
		announce += GetTrinityString(LANG_JAIL_ANNOUNCE3);
		announce += m_session->GetPlayerName();
		announce += GetTrinityString(LANG_JAIL_ANNOUNCE4);
		announce += chr->m_jail_reason;

		HandleAnnounceCommand(announce.c_str());

    if (sObjectMgr->m_jailconf_max_jails == chr->m_jail_times)
    {
        chr->GetSession()->KickPlayer();
        chr->DeleteFromDB(fields[0].GetUInt64(), fields[1].GetUInt32());
    }
    else if ((sObjectMgr->m_jailconf_max_jails == chr->m_jail_times) && sObjectMgr->m_jailconf_ban)
    {
        uint32 acc_id = chr->GetSession()->GetAccountId();
        ban_reason = GetTrinityString(LANG_JAIL_BAN_REASON);
        ban_by = GetTrinityString(LANG_JAIL_BAN_BY);

		SQLTransaction trans = LoginDatabase.BeginTransaction();
        LoginDatabase.PExecute("INSERT IGNORE INTO `account_banned` (`id`,`bandate`,`bannedby`,`banreason`) VALUES ('%u',UNIX_TIMESTAMP,'%s','%s')", acc_id, ban_by.c_str(), ban_reason.c_str());
        LoginDatabase.CommitTransaction(trans);

        chr->GetSession()->LogoutPlayer(false);
    }
    else chr->GetSession()->LogoutPlayer(false);
    return true;
}

bool ChatHandler::HandleUnJailCommand(const char *args)
{
    char *charname = strtok((char*)args, " ");
    std::string cname;

    if (charname == NULL) return false;
    else cname = charname;

    uint64 GUID = sObjectMgr->GetPlayerGUIDByName(cname.c_str());
    Player *chr = sObjectMgr->GetPlayer(GUID);

    if (chr)
    {
        if (chr->GetName() == m_session->GetPlayerName())
        {
            SendSysMessage(LANG_JAIL_NO_UNJAIL);
            return true;
        }

        if (chr->m_jail_isjailed)
        {
            chr->m_jail_isjailed = false;
            chr->m_jail_release = 0;
            chr->m_jail_times = chr->m_jail_times-1;

            chr->_SaveJail();

            if (chr->m_jail_times == 0)
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                CharacterDatabase.PQuery("DELETE FROM `jail` WHERE `guid`='%u' LIMIT 1", chr->GetGUIDLow());
                CharacterDatabase.CommitTransaction(trans);
            }

            PSendSysMessage(LANG_JAIL_WAS_UNJAILED, cname.c_str());
            ChatHandler(chr).PSendSysMessage(LANG_JAIL_YOURE_UNJAILED, m_session->GetPlayerName());    
            chr->CastSpell(chr,8690,false);
            //chr->GetSession()->LogoutPlayer(false);
        } else PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, cname.c_str());
        return true;
    }
    else
    {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        QueryResult jresult = CharacterDatabase.PQuery("SELECT * FROM `jail` WHERE `guid`='%u' LIMIT 1", GUID_LOPART(GUID));
        CharacterDatabase.CommitTransaction(trans);

        if (!jresult)
        {
            PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, cname.c_str());
            return true;
        }
        else
        {
            Field *fields = jresult->Fetch();
            uint32 jail_times = fields[4].GetUInt32()-1;

            if (jail_times == 0)
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                CharacterDatabase.PQuery("DELETE FROM `jail` WHERE `guid`='%u' LIMIT 1", fields[0].GetUInt32());
                CharacterDatabase.CommitTransaction(trans);
            }
            else
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                CharacterDatabase.PQuery("UPDATE `jail` SET `release`='0',`times`='%u' WHERE `guid`='%u' LIMIT 1", jail_times, fields[0].GetUInt32());
                CharacterDatabase.CommitTransaction(trans);
            }

            PSendSysMessage(LANG_JAIL_WAS_UNJAILED, cname.c_str());
            return true;
        }

    }
    return true;
}

//Send mail by command
bool ChatHandler::HandleSendMailCommand(const char* args)
{
    // format: name "subject text" "mail text"
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    char* tail1 = strtok(NULL, "");
    if (!tail1)
        return false;

    char* msgSubject = extractQuotedArg(tail1);
    if (!msgSubject)
        return false;

    char* tail2 = strtok(NULL, "");
    if (!tail2)
        return false;

    char* msgText = extractQuotedArg(tail2);
    if (!msgText)
        return false;

    // msgSubject, msgText isn't NUL after prev. check
    std::string subject = msgSubject;
    std::string text    = msgText;

    // from console show not existed sender
    MailSender sender(MAIL_NORMAL, m_session ? m_session->GetPlayer()->GetGUIDLow() : 0, MAIL_STATIONERY_GM);

    //- TODO: Fix poor design
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    MailDraft(subject, text)
        .SendMailTo(trans, MailReceiver(target, GUID_LOPART(target_guid)), sender);

    CharacterDatabase.CommitTransaction(trans);

    std::string nameLink = playerLink(target_name);
    PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
    return true;
}

//Summon group of player
bool ChatHandler::HandleGroupSummonCommand(const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    Group *grp = target->GetGroup();

    std::string nameLink = GetNameLink(target);

    if (!grp)
    {
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    Map* gmMap = m_session->GetPlayer()->GetMap();
    bool to_instance =  gmMap->Instanceable();

    // we are in instance, and can summon only player in our group with us as lead
    if (to_instance && (
        !m_session->GetPlayer()->GetGroup() || (grp->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()) ||
        (m_session->GetPlayer()->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID())))
        // the last check is a bit excessive, but let it be, just in case
    {
        SendSysMessage(LANG_CANNOT_SUMMON_TO_INST);
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pl = itr->getSource();

        if (!pl || pl == m_session->GetPlayer() || !pl->GetSession())
            continue;

        // check online security
        if (HasLowerSecurity(pl, 0))
            return false;

        std::string plNameLink = GetNameLink(pl);

        if (pl->IsBeingTeleported() == true)
        {
            PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        if (to_instance)
        {
            Map* plMap = pl->GetMap();

            if (plMap->Instanceable() && plMap->GetInstanceId() != gmMap->GetInstanceId())
            {
                // cannot summon from instance to instance
                PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, plNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }

        PSendSysMessage(LANG_SUMMONING, plNameLink.c_str(), "");
        if (needReportToTarget(pl))
            ChatHandler(pl).PSendSysMessage(LANG_SUMMONED_BY, GetNameLink().c_str());

        // stop flight if need
        if (pl->isInFlight())
        {
            pl->GetMotionMaster()->MovementExpired();
            pl->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            pl->SaveRecallPosition();

        // before GM
        float x, y, z;
        m_session->GetPlayer()->GetClosePoint(x, y, z, pl->GetObjectSize());
        pl->TeleportTo(m_session->GetPlayer()->GetMapId(), x, y, z, pl->GetOrientation());
    }

    return true;
}
