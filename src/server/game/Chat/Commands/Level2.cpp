/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Item.h"
#include "GameObject.h"
#include "Opcodes.h"
#include "Chat.h"
#include "MapManager.h"
#include "Language.h"
#include "World.h"
#include "GameEventMgr.h"
#include "SpellMgr.h"
#include "PoolMgr.h"
#include "AccountMgr.h"
#include "WaypointManager.h"
#include "Util.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <map>
#include "OutdoorPvPMgr.h"
#include "Transport.h"
#include "TargetedMovementGenerator.h"                      // for HandleNpcUnFollowCommand
#include "CreatureGroups.h"

//mute player for some times
bool ChatHandler::HandleMuteCommand(const char* args)
{
    char* nameStr;
    char* delayStr;
    extractOptFirstArg((char*)args,&nameStr,&delayStr);
    if (!delayStr)
        return false;

    char *mutereason = strtok(NULL, "\r");
    std::string mutereasonstr = "No reason";
    if (mutereason != NULL)
         mutereasonstr = mutereason;

    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget(nameStr,&target,&target_guid,&target_name))
        return false;

    uint32 account_id = target ? target->GetSession()->GetAccountId() : sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    // find only player from same account if any
    if (!target)
        if (WorldSession* session = sWorld.FindSession(account_id))
            target = session->GetPlayer();

    uint32 notspeaktime = (uint32) atoi(delayStr);

    // must have strong lesser security level
    if (HasLowerSecurity (target,target_guid,true))
        return false;

    time_t mutetime = time(NULL) + notspeaktime*60;

    if (target)
        target->GetSession()->m_muteTime = mutetime;

    LoginDatabase.PExecute("UPDATE account SET mutetime = " UI64FMTD " WHERE id = '%u'",uint64(mutetime), account_id);

    if (target)
        ChatHandler(target).PSendSysMessage(LANG_YOUR_CHAT_DISABLED, notspeaktime, mutereasonstr.c_str());

    std::string nameLink = playerLink(target_name);

    PSendSysMessage(LANG_YOU_DISABLE_CHAT, nameLink.c_str(), notspeaktime, mutereasonstr.c_str());

    return true;
}

//unmute player
bool ChatHandler::HandleUnmuteCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    uint32 account_id = target ? target->GetSession()->GetAccountId() : sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    // find only player from same account if any
    if (!target)
        if (WorldSession* session = sWorld.FindSession(account_id))
            target = session->GetPlayer();

    // must have strong lesser security level
    if (HasLowerSecurity (target,target_guid,true))
        return false;

    if (target)
    {
        if (target->CanSpeak())
        {
            SendSysMessage(LANG_CHAT_ALREADY_ENABLED);
            SetSentErrorMessage(true);
            return false;
        }

        target->GetSession()->m_muteTime = 0;
    }

    LoginDatabase.PExecute("UPDATE account SET mutetime = '0' WHERE id = '%u'", account_id);

    if (target)
        ChatHandler(target).PSendSysMessage(LANG_YOUR_CHAT_ENABLED);

    std::string nameLink = playerLink(target_name);

    PSendSysMessage(LANG_YOU_ENABLE_CHAT, nameLink.c_str());
    return true;
}

bool ChatHandler::HandleGameObjectTargetCommand(const char* args)
{
    Player* pl = m_session->GetPlayer();
    QueryResult result;
    GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr.GetActiveEventList();
    if (*args)
    {
        // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
        char* cId = extractKeyFromLink((char*)args,"Hgameobject_entry");
        if (!cId)
            return false;

        uint32 id = atol(cId);

        if (id)
            result = WorldDatabase.PQuery("SELECT guid, id, position_x, position_y, position_z, orientation, map, phaseMask, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE map = '%i' AND id = '%u' ORDER BY order_ ASC LIMIT 1",
                pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(), pl->GetMapId(),id);
        else
        {
            std::string name = cId;
            WorldDatabase.escape_string(name);
            result = WorldDatabase.PQuery(
                "SELECT guid, id, position_x, position_y, position_z, orientation, map, phaseMask, (POW(position_x - %f, 2) + POW(position_y - %f, 2) + POW(position_z - %f, 2)) AS order_ "
                "FROM gameobject,gameobject_template WHERE gameobject_template.entry = gameobject.id AND map = %i AND name "_LIKE_" "_CONCAT3_("'%%'","'%s'","'%%'")" ORDER BY order_ ASC LIMIT 1",
                pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(), pl->GetMapId(),name.c_str());
        }
    }
    else
    {
        std::ostringstream eventFilter;
        eventFilter << " AND (event IS NULL ";
        bool initString = true;

        for (GameEventMgr::ActiveEvents::const_iterator itr = activeEventsList.begin(); itr != activeEventsList.end(); ++itr)
        {
            if (initString)
            {
                eventFilter  <<  "OR event IN (" <<*itr;
                initString =false;
            }
            else
                eventFilter << "," << *itr;
        }

        if (!initString)
            eventFilter << "))";
        else
            eventFilter << ")";

        result = WorldDatabase.PQuery("SELECT gameobject.guid, id, position_x, position_y, position_z, orientation, map, phaseMask, "
            "(POW(position_x - %f, 2) + POW(position_y - %f, 2) + POW(position_z - %f, 2)) AS order_ FROM gameobject "
            "LEFT OUTER JOIN game_event_gameobject on gameobject.guid=game_event_gameobject.guid WHERE map = '%i' %s ORDER BY order_ ASC LIMIT 10",
            m_session->GetPlayer()->GetPositionX(), m_session->GetPlayer()->GetPositionY(), m_session->GetPlayer()->GetPositionZ(), m_session->GetPlayer()->GetMapId(),eventFilter.str().c_str());
    }

    if (!result)
    {
        SendSysMessage(LANG_COMMAND_TARGETOBJNOTFOUND);
        return true;
    }

    bool found = false;
    float x, y, z, o;
    uint32 lowguid, id;
    uint16 mapid, phase;
    uint32 pool_id;

    do
    {
        Field *fields = result->Fetch();
        lowguid = fields[0].GetUInt32();
        id =      fields[1].GetUInt32();
        x =       fields[2].GetFloat();
        y =       fields[3].GetFloat();
        z =       fields[4].GetFloat();
        o =       fields[5].GetFloat();
        mapid =   fields[6].GetUInt16();
        phase =   fields[7].GetUInt16();
        pool_id = sPoolMgr.IsPartOfAPool<GameObject>(lowguid);
        if (!pool_id || sPoolMgr.IsSpawnedObject<GameObject>(lowguid))
            found = true;
    } while (result->NextRow() && (!found));

    if (!found)
    {
        PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
        return false;
    }

    GameObjectInfo const* goI = sObjectMgr.GetGameObjectInfo(id);

    if (!goI)
    {
        PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
        return false;
    }

    GameObject* target = m_session->GetPlayer()->GetMap()->GetGameObject(MAKE_NEW_GUID(lowguid,id,HIGHGUID_GAMEOBJECT));

    PSendSysMessage(LANG_GAMEOBJECT_DETAIL, lowguid, goI->name, lowguid, id, x, y, z, mapid, o, phase);

    if (target)
    {
        int32 curRespawnDelay = int32(target->GetRespawnTimeEx()-time(NULL));
        if (curRespawnDelay < 0)
            curRespawnDelay = 0;

        std::string curRespawnDelayStr = secsToTimeString(curRespawnDelay,true);
        std::string defRespawnDelayStr = secsToTimeString(target->GetRespawnDelay(),true);

        PSendSysMessage(LANG_COMMAND_RAWPAWNTIMES, defRespawnDelayStr.c_str(),curRespawnDelayStr.c_str());
    }
    return true;
}

//delete object by selection or guid
bool ChatHandler::HandleGameObjectDeleteCommand(const char* args)
{
    // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* obj = NULL;

    // by DB guid
    if (GameObjectData const* go_data = sObjectMgr.GetGOData(lowguid))
        obj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

    if (!obj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    uint64 owner_guid = obj->GetOwnerGUID();
    if (owner_guid)
    {
        Unit* owner = ObjectAccessor::GetUnit(*m_session->GetPlayer(),owner_guid);
        if (!owner || !IS_PLAYER_GUID(owner_guid))
        {
            PSendSysMessage(LANG_COMMAND_DELOBJREFERCREATURE, GUID_LOPART(owner_guid), obj->GetGUIDLow());
            SetSentErrorMessage(true);
            return false;
        }

        owner->RemoveGameObject(obj,false);
    }

    obj->SetRespawnTime(0);                                 // not save respawn time
    obj->Delete();
    obj->DeleteFromDB();

    PSendSysMessage(LANG_COMMAND_DELOBJMESSAGE, obj->GetGUIDLow());

    return true;
}

//turn selected object
bool ChatHandler::HandleGameObjectTurnCommand(const char* args)
{
    // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* obj = NULL;

    // by DB guid
    if (GameObjectData const* go_data = sObjectMgr.GetGOData(lowguid))
        obj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

    if (!obj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    char* po = strtok(NULL, " ");
    float o;

    if (po)
    {
        o = (float)atof(po);
    }
    else
    {
        Player *chr = m_session->GetPlayer();
        o = chr->GetOrientation();
    }

    obj->Relocate(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), o);
    obj->UpdateRotationFields();
    obj->DestroyForNearbyPlayers();
    obj->UpdateObjectVisibility();

    obj->SaveToDB();
    obj->Refresh();

    PSendSysMessage(LANG_COMMAND_TURNOBJMESSAGE, obj->GetGUIDLow(), obj->GetGOInfo()->name, obj->GetGUIDLow(), o);

    return true;
}

//move selected object
bool ChatHandler::HandleGameObjectMoveCommand(const char* args)
{
    // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* obj = NULL;

    // by DB guid
    if (GameObjectData const* go_data = sObjectMgr.GetGOData(lowguid))
        obj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

    if (!obj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    char* px = strtok(NULL, " ");
    char* py = strtok(NULL, " ");
    char* pz = strtok(NULL, " ");

    if (!px)
    {
        Player *chr = m_session->GetPlayer();
        obj->Relocate(chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ(), obj->GetOrientation());
        obj->DestroyForNearbyPlayers();
        obj->UpdateObjectVisibility();
    }
    else
    {
        if (!py || !pz)
            return false;

        float x = (float)atof(px);
        float y = (float)atof(py);
        float z = (float)atof(pz);

        if (!MapManager::IsValidMapCoord(obj->GetMapId(),x,y,z))
        {
            PSendSysMessage(LANG_INVALID_TARGET_COORD,x,y,obj->GetMapId());
            SetSentErrorMessage(true);
            return false;
        }

        obj->Relocate(x, y, z, obj->GetOrientation());
        obj->DestroyForNearbyPlayers();
        obj->UpdateObjectVisibility();
    }

    obj->SaveToDB();
    obj->Refresh();

    PSendSysMessage(LANG_COMMAND_MOVEOBJMESSAGE, obj->GetGUIDLow(), obj->GetGOInfo()->name, obj->GetGUIDLow());

    return true;
}

//spawn go
bool ChatHandler::HandleGameObjectAddCommand(const char* args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject_entry");
    if (!cId)
        return false;

    uint32 id = atol(cId);
    if (!id)
        return false;

    char* spawntimeSecs = strtok(NULL, " ");

    const GameObjectInfo *gInfo = sObjectMgr.GetGameObjectInfo(id);

    if (!gInfo)
    {
        PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
        SetSentErrorMessage(true);
        return false;
    }

    if (gInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(gInfo->displayId))
    {
        // report to DB errors log as in loading case
        sLog.outErrorDb("Gameobject (Entry %u GoType: %u) have invalid displayId (%u), not spawned.",id, gInfo->type, gInfo->displayId);
        PSendSysMessage(LANG_GAMEOBJECT_HAVE_INVALID_DATA,id);
        SetSentErrorMessage(true);
        return false;
    }

    Player *chr = m_session->GetPlayer();
    float x = float(chr->GetPositionX());
    float y = float(chr->GetPositionY());
    float z = float(chr->GetPositionZ());
    float o = float(chr->GetOrientation());
    Map *map = chr->GetMap();

    GameObject* pGameObj = new GameObject;
    uint32 db_lowGUID = sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT);

    if (!pGameObj->Create(db_lowGUID, gInfo->id, map, chr->GetPhaseMaskForSpawn(), x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
    {
        delete pGameObj;
        return false;
    }

    if (spawntimeSecs)
    {
        uint32 value = atoi((char*)spawntimeSecs);
        pGameObj->SetRespawnTime(value);
        //sLog.outDebug("*** spawntimeSecs: %d", value);
    }

    // fill the gameobject data and save to the db
    pGameObj->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()),chr->GetPhaseMaskForSpawn());

    // this will generate a new guid if the object is in an instance
    if (!pGameObj->LoadFromDB(db_lowGUID, map))
    {
        delete pGameObj;
        return false;
    }

    sLog.outDebug(GetTrinityString(LANG_GAMEOBJECT_CURRENT), gInfo->name, db_lowGUID, x, y, z, o);

    map->Add(pGameObj);

    // TODO: is it really necessary to add both the real and DB table guid here ?
    sObjectMgr.AddGameobjectToGrid(db_lowGUID, sObjectMgr.GetGOData(db_lowGUID));

    PSendSysMessage(LANG_GAMEOBJECT_ADD,id,gInfo->name,db_lowGUID,x,y,z);
    return true;
}

//set pahsemask for selected object
bool ChatHandler::HandleGameObjectPhaseCommand(const char* args)
{
    // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* obj = NULL;

    // by DB guid
    if (GameObjectData const* go_data = sObjectMgr.GetGOData(lowguid))
        obj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

    if (!obj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    char* phaseStr = strtok (NULL, " ");
    uint32 phasemask = phaseStr? atoi(phaseStr) : 0;
    if (phasemask == 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    obj->SetPhaseMask(phasemask,true);
    obj->SaveToDB();
    return true;
}

bool ChatHandler::HandleGameObjectNearCommand(const char* args)
{
    float distance = (!*args) ? 10.0f : (float)(atof(args));
    uint32 count = 0;

    Player* pl = m_session->GetPlayer();
    QueryResult result = WorldDatabase.PQuery("SELECT guid, id, position_x, position_y, position_z, map, "
        "(POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ "
        "FROM gameobject WHERE map='%u' AND (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) <= '%f' ORDER BY order_",
        pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(),
        pl->GetMapId(),pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(),distance*distance);

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            uint32 entry = fields[1].GetUInt32();
            float x = fields[2].GetFloat();
            float y = fields[3].GetFloat();
            float z = fields[4].GetFloat();
            int mapid = fields[5].GetUInt16();

            GameObjectInfo const * gInfo = sObjectMgr.GetGameObjectInfo(entry);

            if (!gInfo)
                continue;

            PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gInfo->name, x, y, z, mapid);

            ++count;
        } while (result->NextRow());
    }

    PSendSysMessage(LANG_COMMAND_NEAROBJMESSAGE,distance,count);
    return true;
}

bool ChatHandler::HandleGUIDCommand(const char* /*args*/)
{
    uint64 guid = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
    {
        SendSysMessage(LANG_NO_SELECTION);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_OBJECT_GUID, GUID_LOPART(guid), GUID_HIPART(guid));
    return true;
}

 //move item to other slot
bool ChatHandler::HandleItemMoveCommand(const char* args)
{
    if (!*args)
        return false;
    uint8 srcslot, dstslot;

    char* pParam1 = strtok((char*)args, " ");
    if (!pParam1)
        return false;

    char* pParam2 = strtok(NULL, " ");
    if (!pParam2)
        return false;

    srcslot = (uint8)atoi(pParam1);
    dstslot = (uint8)atoi(pParam2);

    if (srcslot == dstslot)
        return true;

    if (!m_session->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0, srcslot, true))
        return false;

    if (!m_session->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0, dstslot, false))
        return false;

    uint16 src = ((INVENTORY_SLOT_BAG_0 << 8) | srcslot);
    uint16 dst = ((INVENTORY_SLOT_BAG_0 << 8) | dstslot);

    m_session->GetPlayer()->SwapItem(src, dst);

    return true;
}

//demorph player or unit
bool ChatHandler::HandleDeMorphCommand(const char* /*args*/)
{
    Unit *target = getSelectedUnit();
    if (!target)
        target = m_session->GetPlayer();

    // check online security
    else if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target, 0))
        return false;

    target->DeMorph();

    return true;
}

//kick player
bool ChatHandler::HandleKickPlayerCommand(const char *args)
{
/*    const char* kickName = strtok((char*)args, " ");
    char* kickReason = strtok(NULL, "\n");
    std::string reason = "No Reason";
    std::string kicker = "Console";
    if (kickReason)
        reason = kickReason;
    if (m_session)
        kicker = m_session->GetPlayer()->GetName();

    if (!kickName)
    {
        Player* player = getSelectedPlayer();
        if (!player)
        {
            SendSysMessage(LANG_NO_CHAR_SELECTED);
            SetSentErrorMessage(true);
            return false;
        }

        if (player == m_session->GetPlayer())
        {
            SendSysMessage(LANG_COMMAND_KICKSELF);
            SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (HasLowerSecurity(player, 0))
            return false;

        if (sWorld.getIntConfig(CONFIG_SHOW_KICK_IN_WORLD) == 1)
        {
            sWorld.SendWorldText(LANG_COMMAND_KICKMESSAGE, player->GetName(), kicker.c_str(), reason.c_str());
        }
        else
        {
            PSendSysMessage(LANG_COMMAND_KICKMESSAGE, player->GetName(), kicker.c_str(), reason.c_str());
        }

        player->GetSession()->KickPlayer();
    }
    else
    {
        std::string name = extractPlayerNameFromLink((char*)kickName);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        if (m_session && name == m_session->GetPlayer()->GetName())
        {
            SendSysMessage(LANG_COMMAND_KICKSELF);
            SetSentErrorMessage(true);
            return false;
        }

        Player* player = sObjectMgr.GetPlayer(kickName);
        if (!player)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        if (HasLowerSecurity(player, 0))
        {
            SendSysMessage(LANG_YOURS_SECURITY_IS_LOW); //maybe replacement string for this later on
            SetSentErrorMessage(true);
            return false;
        }

        std::string nameLink = playerLink(name);

        if (sWorld.KickPlayer(name))
        {
            if (sWorld.getIntConfig(CONFIG_SHOW_KICK_IN_WORLD) == 1)
            {
                sWorld.SendWorldText(LANG_COMMAND_KICKMESSAGE, nameLink.c_str(), kicker.c_str(), reason.c_str());
            }
            else
            {
                PSendSysMessage(LANG_COMMAND_KICKMESSAGE,nameLink.c_str());
            }
        }
        else
        {
            PSendSysMessage(LANG_COMMAND_KICKNOTFOUNDPLAYER,nameLink.c_str());
            return false;
        }
    }*/
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    if (m_session && target == m_session->GetPlayer())
    {
        SendSysMessage(LANG_COMMAND_KICKSELF);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    // send before target pointer invalidate
    PSendSysMessage(LANG_COMMAND_KICKMESSAGE,GetNameLink(target).c_str());
    target->GetSession()->KickPlayer();
    return true;
}

//show info of gameobject
bool ChatHandler::HandleGameObjectInfoCommand(const char* args)
{
    uint32 entry = 0;
    uint32 type = 0;
    uint32 displayid = 0;
    std::string name;
    uint32 lootId = 0;

    if (!*args)
    {
        if (WorldObject * obj = getSelectedObject())
            entry = obj->GetEntry();
    }
    else
        entry = atoi((char*)args);

    GameObjectInfo const* goinfo = sObjectMgr.GetGameObjectInfo(entry);

    if (!goinfo)
        return false;

    type = goinfo->type;
    displayid = goinfo->displayId;
    name = goinfo->name;
    if (type == GAMEOBJECT_TYPE_CHEST)
        lootId = goinfo->chest.lootId;
    else if (type == GAMEOBJECT_TYPE_FISHINGHOLE)
        lootId = goinfo->fishinghole.lootId;

    PSendSysMessage(LANG_GOINFO_ENTRY, entry);
    PSendSysMessage(LANG_GOINFO_TYPE, type);
    PSendSysMessage(LANG_GOINFO_LOOTID, lootId);
    PSendSysMessage(LANG_GOINFO_DISPLAYID, displayid);
    PSendSysMessage(LANG_GOINFO_NAME, name.c_str());

    return true;
}

//show info of player
bool ChatHandler::HandlePInfoCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    uint32 accId = 0;
    uint32 money = 0;
    uint32 total_player_time = 0;
    uint8 level = 0;
    uint32 latency = 0;
    uint8 race;
    uint8 Class;

    // get additional information from Player object
    if (target)
    {
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        accId = target->GetSession()->GetAccountId();
        money = target->GetMoney();
        total_player_time = target->GetTotalPlayedTime();
        level = target->getLevel();
        latency = target->GetSession()->GetLatency();
        race = target->getRace();
        Class = target->getClass();
    }
    // get additional information from DB
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        //                                                     0          1      2      3        4     5
        QueryResult result = CharacterDatabase.PQuery("SELECT totaltime, level, money, account, race, class FROM characters WHERE guid = '%u'", GUID_LOPART(target_guid));
        if (!result)
            return false;

        Field *fields = result->Fetch();
        total_player_time = fields[0].GetUInt32();
        level = fields[1].GetUInt32();
        money = fields[2].GetUInt32();
        accId = fields[3].GetUInt32();
        race = fields[4].GetUInt8();
        Class = fields[5].GetUInt8();
    }

    std::string username = GetTrinityString(LANG_ERROR);
    std::string email = GetTrinityString(LANG_ERROR);
    std::string last_ip = GetTrinityString(LANG_ERROR);
    uint32 security = 0;
    std::string last_login = GetTrinityString(LANG_ERROR);

    QueryResult result = LoginDatabase.PQuery("SELECT a.username,aa.gmlevel,a.email,a.last_ip,a.last_login "
                                                "FROM account a "
                                                "LEFT JOIN account_access aa "
                                                "ON (a.id = aa.id) "
                                                "WHERE a.id = '%u'",accId);
    if (result)
    {
        Field* fields = result->Fetch();
        username = fields[0].GetString();
        security = fields[1].GetUInt32();
        email = fields[2].GetString();

        if (email.empty())
            email = "-";

        if (!m_session || m_session->GetSecurity() >= AccountTypes(security))
        {
            last_ip = fields[3].GetString();
            last_login = fields[4].GetString();
        }
        else
        {
            last_ip = "-";
            last_login = "-";
        }
    }

    std::string nameLink = playerLink(target_name);

    PSendSysMessage(LANG_PINFO_ACCOUNT, (target?"":GetTrinityString(LANG_OFFLINE)), nameLink.c_str(), GUID_LOPART(target_guid), username.c_str(), accId, email.c_str(), security, last_ip.c_str(), last_login.c_str(), latency);

    std::string race_s, Class_s;
    switch(race)
    {
        case RACE_HUMAN:            race_s = "Human";       break;
        case RACE_ORC:              race_s = "Orc";         break;
        case RACE_DWARF:            race_s = "Dwarf";       break;
        case RACE_NIGHTELF:         race_s = "Night Elf";   break;
        case RACE_UNDEAD_PLAYER:    race_s = "Undead";      break;
        case RACE_TAUREN:           race_s = "Tauren";      break;
        case RACE_GNOME:            race_s = "Gnome";       break;
        case RACE_TROLL:            race_s = "Troll";       break;
        case RACE_BLOODELF:         race_s = "Blood Elf";   break;
        case RACE_DRAENEI:          race_s = "Draenei";     break;
    }
    switch(Class)
    {
        case CLASS_WARRIOR:         Class_s = "Warrior";        break;
        case CLASS_PALADIN:         Class_s = "Paladin";        break;
        case CLASS_HUNTER:          Class_s = "Hunter";         break;
        case CLASS_ROGUE:           Class_s = "Rogue";          break;
        case CLASS_PRIEST:          Class_s = "Priest";         break;
        case CLASS_DEATH_KNIGHT:    Class_s = "Death Knight";   break;
        case CLASS_SHAMAN:          Class_s = "Shaman";         break;
        case CLASS_MAGE:            Class_s = "Mage";           break;
        case CLASS_WARLOCK:         Class_s = "Warlock";        break;
        case CLASS_DRUID:           Class_s = "Druid";          break;
    }

    std::string timeStr = secsToTimeString(total_player_time,true,true);
    uint32 gold = money /GOLD;
    uint32 silv = (money % GOLD) / SILVER;
    uint32 copp = (money % GOLD) % SILVER;
    PSendSysMessage(LANG_PINFO_LEVEL, race_s.c_str(), Class_s.c_str(), timeStr.c_str(), level, gold, silv, copp);

    return true;
}

/////WAYPOINT COMMANDS

/**
 * Add a waypoint to a creature.
 *
 * The user can either select an npc or provide its GUID.
 *
 * The user can even select a visual waypoint - then the new waypoint
 * is placed *after* the selected one - this makes insertion of new
 * waypoints possible.
 *
 * eg:
 * .wp add 12345
 * -> adds a waypoint to the npc with the GUID 12345
 *
 * .wp add
 * -> adds a waypoint to the currently selected creature
 *
 *
 * @param args if the user did not provide a GUID, it is NULL
 *
 * @return true - command did succeed, false - something went wrong
 */
bool ChatHandler::HandleWpAddCommand(const char* args)
{
    sLog.outDebug("DEBUG: HandleWpAddCommand");

    // optional
    char* path_number = NULL;
    uint32 pathid = 0;

    if (*args)
        path_number = strtok((char*)args, " ");

    uint32 point = 0;
    Creature* target = getSelectedCreature();

    if (!path_number)
    {
        if (target)
            pathid = target->GetWaypointPath();
        else
        {
            QueryResult result = WorldDatabase.Query("SELECT MAX(id) FROM waypoint_data");
            uint32 maxpathid = result->Fetch()->GetInt32();
            pathid = maxpathid+1;
            sLog.outDebug("DEBUG: HandleWpAddCommand - New path started.");
            PSendSysMessage("%s%s|r", "|cff00ff00", "New path started.");
        }
    }
    else
        pathid = atoi(path_number);

    // path_id -> ID of the Path
    // point   -> number of the waypoint (if not 0)

    if (!pathid)
    {
        sLog.outDebug("DEBUG: HandleWpAddCommand - Current creature haven't loaded path.");
        PSendSysMessage("%s%s|r", "|cffff33ff", "Current creature haven't loaded path.");
        return true;
    }

    sLog.outDebug("DEBUG: HandleWpAddCommand - point == 0");

    QueryResult result = WorldDatabase.PQuery("SELECT MAX(point) FROM waypoint_data WHERE id = '%u'",pathid);

    if (result)
        point = (*result)[0].GetUInt32();

    Player* player = m_session->GetPlayer();
    //Map *map = player->GetMap();

    WorldDatabase.PExecute("INSERT INTO waypoint_data (id, point, position_x, position_y, position_z) VALUES ('%u','%u','%f', '%f', '%f')",
        pathid, point+1, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

    PSendSysMessage("%s%s%u%s%u%s|r", "|cff00ff00", "PathID: |r|cff00ffff", pathid, "|r|cff00ff00: Waypoint |r|cff00ffff", point+1,"|r|cff00ff00 created. ");
    return true;
}                                                           // HandleWpAddCommand

bool ChatHandler::HandleWpLoadPathCommand(const char *args)
{
    if (!*args)
        return false;

    // optional
    char* path_number = NULL;

    if (*args)
        path_number = strtok((char*)args, " ");

    uint32 pathid = 0;
    uint32 guidlow = 0;
    Creature* target = getSelectedCreature();

    // Did player provide a path_id?
    if (!path_number)
        sLog.outDebug("DEBUG: HandleWpLoadPathCommand - No path number provided");

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (target->GetEntry() == 1)
    {
        PSendSysMessage("%s%s|r", "|cffff33ff", "You want to load path to a waypoint? Aren't you?");
        SetSentErrorMessage(true);
        return false;
    }

    pathid = atoi(path_number);

    if (!pathid)
    {
        PSendSysMessage("%s%s|r", "|cffff33ff", "No vallid path number provided.");
        return true;
    }

    guidlow = target->GetDBTableGUIDLow();
    QueryResult result = WorldDatabase.PQuery("SELECT guid FROM creature_addon WHERE guid = '%u'",guidlow);

    if (result)
        WorldDatabase.PExecute("UPDATE creature_addon SET path_id = '%u' WHERE guid = '%u'", pathid, guidlow);
    else
        WorldDatabase.PExecute("INSERT INTO creature_addon(guid,path_id) VALUES ('%u','%u')", guidlow, pathid);

    WorldDatabase.PExecute("UPDATE creature SET MovementType = '%u' WHERE guid = '%u'", WAYPOINT_MOTION_TYPE, guidlow);

    target->LoadPath(pathid);
    target->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
    target->GetMotionMaster()->Initialize();
    target->MonsterSay("Path loaded.",0,0);

    return true;
}

bool ChatHandler::HandleReloadAllPaths(const char* args)
{
    if (!*args)
        return false;

    uint32 id = atoi(args);

    if (!id)
        return false;

    PSendSysMessage("%s%s|r|cff00ffff%u|r", "|cff00ff00", "Loading Path: ", id);
    sWaypointMgr->UpdatePath(id);
    return true;
}

bool ChatHandler::HandleWpUnLoadPathCommand(const char * /*args*/)
{
    uint32 guidlow = 0;
    Creature* target = getSelectedCreature();

    if (!target)
    {
        PSendSysMessage("%s%s|r", "|cff33ffff", "You must select target.");
        return true;
    }

    if (target->GetCreatureAddon())
    {
        if (target->GetCreatureAddon()->path_id != 0)
        {
            WorldDatabase.PExecute("DELETE FROM creature_addon WHERE guid = %u", target->GetGUIDLow());
            target->UpdateWaypointID(0);
            WorldDatabase.PExecute("UPDATE creature SET MovementType = '%u' WHERE guid = '%u'", IDLE_MOTION_TYPE, guidlow);
            target->LoadPath(0);
            target->SetDefaultMovementType(IDLE_MOTION_TYPE);
            target->GetMotionMaster()->MoveTargetedHome();
            target->GetMotionMaster()->Initialize();
            target->MonsterSay("Path unloaded.",0,0);
            return true;
        }
        PSendSysMessage("%s%s|r", "|cffff33ff", "Target have no loaded path.");
    }
    return true;
}

bool ChatHandler::HandleWpEventCommand(const char* args)
{
    if (!*args)
        return false;

    char* show_str = strtok((char*)args, " ");
    std::string show = show_str;

    // Check
    if ((show != "add") && (show != "mod") && (show != "del") && (show != "listid")) return false;

    char* arg_id = strtok(NULL, " ");
    uint32 id = 0;

    if (show == "add")
    {
        if (arg_id)
            id = atoi(arg_id);

        if (id)
        {
            QueryResult result = WorldDatabase.PQuery("SELECT id FROM waypoint_scripts WHERE guid = %u", id);

            if (!result)
            {
                WorldDatabase.PExecute("INSERT INTO waypoint_scripts(guid)VALUES(%u)", id);
                PSendSysMessage("%s%s%u|r", "|cff00ff00", "Wp Event: New waypoint event added: ", id);
            }
            else
                PSendSysMessage("|cff00ff00Wp Event: You have choosed an existing waypoint script guid: %u|r", id);
        }
        else
        {
            QueryResult result = WorldDatabase.Query("SELECT MAX(guid) FROM waypoint_scripts");
            id = result->Fetch()->GetUInt32();
            WorldDatabase.PExecute("INSERT INTO waypoint_scripts(guid)VALUES(%u)", id+1);
            PSendSysMessage("%s%s%u|r", "|cff00ff00","Wp Event: New waypoint event added: |r|cff00ffff", id+1);
        }

        return true;
    }

    if (show == "listid")
    {
        if (!arg_id)
        {
            PSendSysMessage("%s%s|r", "|cff33ffff","Wp Event: You must provide waypoint script id.");
            return true;
        }

        id = atoi(arg_id);

        uint32 a2, a3, a4, a5, a6;
        float a8, a9, a10, a11;
        char const* a7;

        QueryResult result = WorldDatabase.PQuery("SELECT guid, delay, command, datalong, datalong2, dataint, x, y, z, o FROM waypoint_scripts WHERE id = %u", id);

        if (!result)
        {
            PSendSysMessage("%s%s%u|r", "|cff33ffff", "Wp Event: No waypoint scripts found on id: ", id);
            return true;
        }

        Field *fields;

        do
        {
            fields = result->Fetch();
            a2 = fields[0].GetUInt32();
            a3 = fields[1].GetUInt32();
            a4 = fields[2].GetUInt32();
            a5 = fields[3].GetUInt32();
            a6 = fields[4].GetUInt32();
            a7 = fields[5].GetCString();
            a8 = fields[6].GetFloat();
            a9 = fields[7].GetFloat();
            a10 = fields[8].GetFloat();
            a11 = fields[9].GetFloat();

            PSendSysMessage("|cffff33ffid:|r|cff00ffff %u|r|cff00ff00, guid: |r|cff00ffff%u|r|cff00ff00, delay: |r|cff00ffff%u|r|cff00ff00, command: |r|cff00ffff%u|r|cff00ff00, datalong: |r|cff00ffff%u|r|cff00ff00, datalong2: |r|cff00ffff%u|r|cff00ff00, datatext: |r|cff00ffff%s|r|cff00ff00, posx: |r|cff00ffff%f|r|cff00ff00, posy: |r|cff00ffff%f|r|cff00ff00, posz: |r|cff00ffff%f|r|cff00ff00, orientation: |r|cff00ffff%f|r", id, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
        }
        while (result->NextRow());
    }

    if (show == "del")
    {
        id = atoi(arg_id);

        QueryResult result = WorldDatabase.PQuery("SELECT guid FROM waypoint_scripts WHERE guid = %u", id);

        if (result)
        {
           WorldDatabase.PExecute("DELETE FROM waypoint_scripts WHERE guid = %u", id);
           PSendSysMessage("%s%s%u|r","|cff00ff00","Wp Event: Waypoint script removed: ", id);
        }
        else
            PSendSysMessage("|cffff33ffWp Event: ERROR: you have selected a non existing script: %u|r", id);

        return true;
    }

    if (show == "mod")
    {
        if (!arg_id)
        {
            SendSysMessage("|cffff33ffERROR: Waypoint script guid not present.|r");
            return true;
        }

        id = atoi(arg_id);

        if (!id)
        {
            SendSysMessage("|cffff33ffERROR: No vallid waypoint script id not present.|r");
            return true;
        }

        char* arg_2 = strtok(NULL," ");

        if (!arg_2)
        {
            SendSysMessage("|cffff33ffERROR: No argument present.|r");
            return true;
        }

        std::string arg_string  = arg_2;

        if ((arg_string != "setid") && (arg_string != "delay") && (arg_string != "command")
        && (arg_string != "datalong") && (arg_string != "datalong2") && (arg_string != "dataint") && (arg_string != "posx")
        && (arg_string != "posy") && (arg_string != "posz") && (arg_string != "orientation"))
        {
            SendSysMessage("|cffff33ffERROR: No valid argument present.|r");
            return true;
        }

        char* arg_3;
        std::string arg_str_2 = arg_2;
        arg_3 = strtok(NULL," ");

        if (!arg_3)
        {
            SendSysMessage("|cffff33ffERROR: No additional argument present.|r");
            return true;
        }

        float coord;

        if (arg_str_2 == "setid")
        {
            uint32 newid = atoi(arg_3);
            PSendSysMessage("%s%s|r|cff00ffff%u|r|cff00ff00%s|r|cff00ffff%u|r","|cff00ff00","Wp Event: Wypoint scipt guid: ", newid," id changed: ", id);
            WorldDatabase.PExecute("UPDATE waypoint_scripts SET id='%u' WHERE guid='%u'",
            newid, id); return true;
        }
        else
        {
            QueryResult result = WorldDatabase.PQuery("SELECT id FROM waypoint_scripts WHERE guid='%u'",id);

            if (!result)
            {
                SendSysMessage("|cffff33ffERROR: You have selected an non existing waypoint script guid.|r");
                return true;
            }

            if (arg_str_2 == "posx")
            {
                coord = (float)(atof(arg_3));
                WorldDatabase.PExecute("UPDATE waypoint_scripts SET x='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script:|r|cff00ffff %u|r|cff00ff00 position_x updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "posy")
            {
                coord = (float)(atof(arg_3));
                WorldDatabase.PExecute("UPDATE waypoint_scripts SET y='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: %u position_y updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "posz")
            {
                coord = (float)(atof(arg_3));
                WorldDatabase.PExecute("UPDATE waypoint_scripts SET z='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 position_z updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "orientation")
            {
                coord = (float)(atof(arg_3));
                WorldDatabase.PExecute("UPDATE waypoint_scripts SET o='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 orientation updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "dataint")
            {
                    WorldDatabase.PExecute("UPDATE waypoint_scripts SET %s='%u' WHERE guid='%u'",
                    arg_2, atoi(arg_3), id);
                    PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 dataint updated.|r", id);
                    return true;
            }
            else
            {
                    std::string arg_str_3 = arg_3;
                    WorldDatabase.escape_string(arg_str_3);
                    WorldDatabase.PExecute("UPDATE waypoint_scripts SET %s='%s' WHERE guid='%u'",
                    arg_2, arg_str_3.c_str(), id);
            }
        }
        PSendSysMessage("%s%s|r|cff00ffff%u:|r|cff00ff00 %s %s|r","|cff00ff00","Waypoint script:", id, arg_2,"updated.");
    }
    return true;
}

bool ChatHandler::HandleWpModifyCommand(const char* args)
{
    sLog.outDebug("DEBUG: HandleWpModifyCommand");

    if (!*args)
        return false;

    // first arg: add del text emote spell waittime move
    char* show_str = strtok((char*)args, " ");
    if (!show_str)
    {
        return false;
    }

    std::string show = show_str;
    // Check
    // Remember: "show" must also be the name of a column!
    if ((show != "delay") && (show != "action") && (show != "action_chance")
        && (show != "move_flag") && (show != "del") && (show != "move") && (show != "wpadd")
)
    {
        return false;
    }

    // Next arg is: <PATHID> <WPNUM> <ARGUMENT>
    char* arg_str = NULL;

    // Did user provide a GUID
    // or did the user select a creature?
    // -> variable lowguid is filled with the GUID of the NPC
    uint32 pathid = 0;
    uint32 point = 0;
    uint32 wpGuid = 0;
    Creature* target = getSelectedCreature();

    if (!target || target->GetEntry() != VISUAL_WAYPOINT)
    {
        SendSysMessage("|cffff33ffERROR: You must select a waypoint.|r");
        return false;
    }

    sLog.outDebug("DEBUG: HandleWpModifyCommand - User did select an NPC");
    // The visual waypoint
    Creature* wpCreature = NULL;
    wpGuid = target->GetGUIDLow();

    // Did the user select a visual spawnpoint?
    if (wpGuid)
        wpCreature = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(wpGuid, VISUAL_WAYPOINT, HIGHGUID_UNIT));
    // attempt check creature existence by DB data
    else
    {
        PSendSysMessage(LANG_WAYPOINT_CREATNOTFOUND, wpGuid);
        return false;
    }
    // User did select a visual waypoint?
    // Check the creature
    if (wpCreature->GetEntry() == VISUAL_WAYPOINT)
    {
        QueryResult result = WorldDatabase.PQuery("SELECT id, point FROM waypoint_data WHERE wpguid = %u", wpGuid);

        if (!result)
        {
            sLog.outDebug("DEBUG: HandleWpModifyCommand - No waypoint found - used 'wpguid'");

            PSendSysMessage(LANG_WAYPOINT_NOTFOUNDSEARCH, target->GetGUIDLow());
            // Select waypoint number from database
            // Since we compare float values, we have to deal with
            // some difficulties.
            // Here we search for all waypoints that only differ in one from 1 thousand
            // (0.001) - There is no other way to compare C++ floats with mySQL floats
            // See also: http://dev.mysql.com/doc/refman/5.0/en/problems-with-float.html
            const char* maxDIFF = "0.01";
            result = WorldDatabase.PQuery("SELECT id, point FROM waypoint_data WHERE (abs(position_x - %f) <= %s) and (abs(position_y - %f) <= %s) and (abs(position_z - %f) <= %s)",
            wpCreature->GetPositionX(), maxDIFF, wpCreature->GetPositionY(), maxDIFF, wpCreature->GetPositionZ(), maxDIFF);
            if (!result)
            {
                    PSendSysMessage(LANG_WAYPOINT_NOTFOUNDDBPROBLEM, wpGuid);
                    return true;
            }
        }
        sLog.outDebug("DEBUG: HandleWpModifyCommand - After getting wpGuid");

        do
        {
            Field *fields = result->Fetch();
            pathid = fields[0].GetUInt32();
            point  = fields[1].GetUInt32();
        }
        while (result->NextRow());

        // We have the waypoint number and the GUID of the "master npc"
        // Text is enclosed in "<>", all other arguments not
        arg_str = strtok((char*)NULL, " ");
    }

    sLog.outDebug("DEBUG: HandleWpModifyCommand - Parameters parsed - now execute the command");

    // Check for argument
    if (show != "del" && show != "move" && arg_str == NULL)
    {
        PSendSysMessage(LANG_WAYPOINT_ARGUMENTREQ, show_str);
        return false;
    }

    if (show == "del" && target)
    {
        PSendSysMessage("|cff00ff00DEBUG: wp modify del, PathID: |r|cff00ffff%u|r", pathid);

        // wpCreature
        Creature* wpCreature = NULL;

        if (wpGuid != 0)
        {
            wpCreature = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(wpGuid, VISUAL_WAYPOINT, HIGHGUID_UNIT));
            wpCreature->CombatStop();
            wpCreature->DeleteFromDB();
            wpCreature->AddObjectToRemoveList();
        }

        WorldDatabase.PExecute("DELETE FROM waypoint_data WHERE id='%u' AND point='%u'",
            pathid, point);
        WorldDatabase.PExecute("UPDATE waypoint_data SET point=point-1 WHERE id='%u' AND point>'%u'",
            pathid, point);

        PSendSysMessage(LANG_WAYPOINT_REMOVED);
        return true;
    }                                                       // del

    if (show == "move" && target)
    {
        PSendSysMessage("|cff00ff00DEBUG: wp move, PathID: |r|cff00ffff%u|r", pathid);

        Player *chr = m_session->GetPlayer();
        Map *map = chr->GetMap();
        {
            // wpCreature
            Creature* wpCreature = NULL;
            // What to do:
            // Move the visual spawnpoint
            // Respawn the owner of the waypoints
            if (wpGuid != 0)
            {
                wpCreature = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(wpGuid, VISUAL_WAYPOINT, HIGHGUID_UNIT));
                wpCreature->CombatStop();
                wpCreature->DeleteFromDB();
                wpCreature->AddObjectToRemoveList();
                // re-create
                Creature* wpCreature2 = new Creature;
                if (!wpCreature2->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), VISUAL_WAYPOINT, 0, 0, chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ(), chr->GetOrientation()))
                {
                    PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, VISUAL_WAYPOINT);
                    delete wpCreature2;
                    return false;
                }

                wpCreature2->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());
                // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
                wpCreature2->LoadFromDB(wpCreature2->GetDBTableGUIDLow(), map);
                map->Add(wpCreature2);
                //sMapMgr.GetMap(npcCreature->GetMapId())->Add(wpCreature2);
            }

            WorldDatabase.PExecute("UPDATE waypoint_data SET position_x = '%f',position_y = '%f',position_z = '%f' where id = '%u' AND point='%u'",
                chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ(), pathid, point);

            PSendSysMessage(LANG_WAYPOINT_CHANGED);
        }
        return true;
    }                                                       // move

    const char *text = arg_str;

    if (text == 0)
    {
        // show_str check for present in list of correct values, no sql injection possible
        WorldDatabase.PExecute("UPDATE waypoint_data SET %s=NULL WHERE id='%u' AND point='%u'",
            show_str, pathid, point);
    }
    else
    {
        // show_str check for present in list of correct values, no sql injection possible
        std::string text2 = text;
        WorldDatabase.escape_string(text2);
        WorldDatabase.PExecute("UPDATE waypoint_data SET %s='%s' WHERE id='%u' AND point='%u'",
            show_str, text2.c_str(), pathid, point);
    }

    PSendSysMessage(LANG_WAYPOINT_CHANGED_NO, show_str);
    return true;
}

bool ChatHandler::HandleWpShowCommand(const char* args)
{
    sLog.outDebug("DEBUG: HandleWpShowCommand");

    if (!*args)
        return false;

    // first arg: on, off, first, last
    char* show_str = strtok((char*)args, " ");
    if (!show_str)
        return false;

    // second arg: GUID (optional, if a creature is selected)
    char* guid_str = strtok((char*)NULL, " ");
    sLog.outDebug("DEBUG: HandleWpShowCommand: show_str: %s guid_str: %s", show_str, guid_str);

    uint32 pathid = 0;
    Creature* target = getSelectedCreature();

    // Did player provide a PathID?

    if (!guid_str)
    {
        sLog.outDebug("DEBUG: HandleWpShowCommand: !guid_str");
        // No PathID provided
        // -> Player must have selected a creature

        if (!target)
        {
            SendSysMessage(LANG_SELECT_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }

        pathid = target->GetWaypointPath();
    }
    else
    {
        sLog.outDebug("|cff00ff00DEBUG: HandleWpShowCommand: PathID provided|r");
        // PathID provided
        // Warn if player also selected a creature
        // -> Creature selection is ignored <-
        if (target)
            SendSysMessage(LANG_WAYPOINT_CREATSELECTED);

        pathid = atoi((char*)guid_str);
    }

    sLog.outDebug("DEBUG: HandleWpShowCommand: danach");

    std::string show = show_str;
    uint32 Maxpoint;

    sLog.outDebug("DEBUG: HandleWpShowCommand: PathID: %u", pathid);

    //PSendSysMessage("wpshow - show: %s", show);

    // Show info for the selected waypoint
    if (show == "info")
    {
        // Check if the user did specify a visual waypoint
        if (target->GetEntry() != VISUAL_WAYPOINT)
        {
            PSendSysMessage(LANG_WAYPOINT_VP_SELECT);
            SetSentErrorMessage(true);
            return false;
        }

        QueryResult result = WorldDatabase.PQuery("SELECT id, point, delay, move_flag, action, action_chance FROM waypoint_data WHERE wpguid = %u", target->GetGUIDLow());

        if (!result)
        {
            SendSysMessage(LANG_WAYPOINT_NOTFOUNDDBPROBLEM);
            return true;
        }

        SendSysMessage("|cff00ffffDEBUG: wp show info:|r");
        do
        {
            Field *fields = result->Fetch();
            pathid                  = fields[0].GetUInt32();
            uint32 point            = fields[1].GetUInt32();
            uint32 delay            = fields[2].GetUInt32();
            uint32 flag             = fields[3].GetUInt32();
            uint32 ev_id            = fields[4].GetUInt32();
            uint32 ev_chance        = fields[5].GetUInt32();

            PSendSysMessage("|cff00ff00Show info: for current point: |r|cff00ffff%u|r|cff00ff00, Path ID: |r|cff00ffff%u|r", point, pathid);
            PSendSysMessage("|cff00ff00Show info: delay: |r|cff00ffff%u|r", delay);
            PSendSysMessage("|cff00ff00Show info: Move flag: |r|cff00ffff%u|r", flag);
            PSendSysMessage("|cff00ff00Show info: Waypoint event: |r|cff00ffff%u|r", ev_id);
            PSendSysMessage("|cff00ff00Show info: Event chance: |r|cff00ffff%u|r", ev_chance);
            }
            while (result->NextRow());

        return true;
    }

    if (show == "on")
    {
        QueryResult result = WorldDatabase.PQuery("SELECT point, position_x,position_y,position_z FROM waypoint_data WHERE id = '%u'", pathid);

        if (!result)
        {
            SendSysMessage("|cffff33ffPath no found.|r");
            SetSentErrorMessage(true);
            return false;
        }

        PSendSysMessage("|cff00ff00DEBUG: wp on, PathID: |cff00ffff%u|r", pathid);

        // Delete all visuals for this NPC
        QueryResult result2 = WorldDatabase.PQuery("SELECT wpguid FROM waypoint_data WHERE id = '%u' and wpguid <> 0", pathid);

        if (result2)
        {
            bool hasError = false;
            do
            {
                Field *fields = result2->Fetch();
                uint32 wpguid = fields[0].GetUInt32();
                Creature* pCreature = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(wpguid,VISUAL_WAYPOINT,HIGHGUID_UNIT));

                if (!pCreature)
                {
                    PSendSysMessage(LANG_WAYPOINT_NOTREMOVED, wpguid);
                    hasError = true;
                    WorldDatabase.PExecute("DELETE FROM creature WHERE guid = '%u'", wpguid);
                }
                else
                {
                    pCreature->CombatStop();
                    pCreature->DeleteFromDB();
                    pCreature->AddObjectToRemoveList();
                }

            }
            while (result2->NextRow());

            if (hasError)
            {
                PSendSysMessage(LANG_WAYPOINT_TOOFAR1);
                PSendSysMessage(LANG_WAYPOINT_TOOFAR2);
                PSendSysMessage(LANG_WAYPOINT_TOOFAR3);
            }
        }

        do
        {
            Field *fields = result->Fetch();
            uint32 point    = fields[0].GetUInt32();
            float x         = fields[1].GetFloat();
            float y         = fields[2].GetFloat();
            float z         = fields[3].GetFloat();

            uint32 id = VISUAL_WAYPOINT;

            Player *chr = m_session->GetPlayer();
            Map *map = chr->GetMap();
            float o = chr->GetOrientation();

            Creature* wpCreature = new Creature;
            if (!wpCreature->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
            {
                PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                delete wpCreature;
                return false;
            }

            sLog.outDebug("DEBUG: UPDATE waypoint_data SET wpguid = '%u' WHERE id = '%u' and point = '%u'", wpCreature->GetGUIDLow(), pathid, point);
            // set "wpguid" column to the visual waypoint
            WorldDatabase.PExecute("UPDATE waypoint_data SET wpguid = '%u' WHERE id = '%u' and point = '%u'", wpCreature->GetGUIDLow(), pathid, point);

            wpCreature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());
            // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
            wpCreature->LoadFromDB(wpCreature->GetDBTableGUIDLow(),map);
            map->Add(wpCreature);

            if (target)
            {
                wpCreature->SetDisplayId(target->GetDisplayId());
                wpCreature->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5);
                wpCreature->SetLevel(point > STRONG_MAX_LEVEL ? STRONG_MAX_LEVEL : point);
            }
        }
        while (result->NextRow());

        SendSysMessage("|cff00ff00Showing the current creature's path.|r");
        return true;
    }

    if (show == "first")
    {
        PSendSysMessage("|cff00ff00DEBUG: wp first, GUID: %u|r", pathid);

        QueryResult result = WorldDatabase.PQuery("SELECT position_x,position_y,position_z FROM waypoint_data WHERE point='1' AND id = '%u'",pathid);
        if (!result)
        {
            PSendSysMessage(LANG_WAYPOINT_NOTFOUND, pathid);
            SetSentErrorMessage(true);
            return false;
        }

        Field *fields = result->Fetch();
        float x         = fields[0].GetFloat();
        float y         = fields[1].GetFloat();
        float z         = fields[2].GetFloat();
        uint32 id = VISUAL_WAYPOINT;

        Player *chr = m_session->GetPlayer();
        float o = chr->GetOrientation();
        Map *map = chr->GetMap();

        Creature* pCreature = new Creature;
        if (!pCreature->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_UNIT),map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
        {
            PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
            delete pCreature;
            return false;
        }

        pCreature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());
        pCreature->LoadFromDB(pCreature->GetDBTableGUIDLow(), map);
        map->Add(pCreature);

        if (target)
        {
            pCreature->SetDisplayId(target->GetDisplayId());
            pCreature->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5);
        }

        return true;
    }

    if (show == "last")
    {
        PSendSysMessage("|cff00ff00DEBUG: wp last, PathID: |r|cff00ffff%u|r", pathid);

        QueryResult result = WorldDatabase.PQuery("SELECT MAX(point) FROM waypoint_data WHERE id = '%u'",pathid);
        if (result)
            Maxpoint = (*result)[0].GetUInt32();
        else
            Maxpoint = 0;

        result = WorldDatabase.PQuery("SELECT position_x,position_y,position_z FROM waypoint_data WHERE point ='%u' AND id = '%u'",Maxpoint, pathid);
        if (!result)
        {
            PSendSysMessage(LANG_WAYPOINT_NOTFOUNDLAST, pathid);
            SetSentErrorMessage(true);
            return false;
        }
        Field *fields = result->Fetch();
        float x         = fields[0].GetFloat();
        float y         = fields[1].GetFloat();
        float z         = fields[2].GetFloat();
        uint32 id = VISUAL_WAYPOINT;

        Player *chr = m_session->GetPlayer();
        float o = chr->GetOrientation();
        Map *map = chr->GetMap();

        Creature* pCreature = new Creature;
        if (!pCreature->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
        {
            PSendSysMessage(LANG_WAYPOINT_NOTCREATED, id);
            delete pCreature;
            return false;
        }

        pCreature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());
        pCreature->LoadFromDB(pCreature->GetDBTableGUIDLow(), map);
        map->Add(pCreature);

        if (target)
        {
            pCreature->SetDisplayId(target->GetDisplayId());
            pCreature->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5);
        }

        return true;
    }

    if (show == "off")
    {
        QueryResult result = WorldDatabase.PQuery("SELECT guid FROM creature WHERE id = '%u'", 1);
        if (!result)
        {
            SendSysMessage(LANG_WAYPOINT_VP_NOTFOUND);
            SetSentErrorMessage(true);
            return false;
        }
        bool hasError = false;
        do
        {
            Field *fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            Creature* pCreature = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(guid,VISUAL_WAYPOINT,HIGHGUID_UNIT));
            if (!pCreature)
            {
                PSendSysMessage(LANG_WAYPOINT_NOTREMOVED, guid);
                hasError = true;
                WorldDatabase.PExecute("DELETE FROM creature WHERE guid = '%u'", guid);
            }
            else
            {
                pCreature->CombatStop();
                pCreature->DeleteFromDB();
                pCreature->AddObjectToRemoveList();
            }
        }
        while (result->NextRow());
        // set "wpguid" column to "empty" - no visual waypoint spawned
        WorldDatabase.PExecute("UPDATE waypoint_data SET wpguid = '0'");
        //WorldDatabase.PExecute("UPDATE creature_movement SET wpguid = '0' WHERE wpguid <> '0'");

        if (hasError)
        {
            PSendSysMessage(LANG_WAYPOINT_TOOFAR1);
            PSendSysMessage(LANG_WAYPOINT_TOOFAR2);
            PSendSysMessage(LANG_WAYPOINT_TOOFAR3);
        }

        SendSysMessage(LANG_WAYPOINT_VP_ALLREMOVED);
        return true;
    }

    PSendSysMessage("|cffff33ffDEBUG: wpshow - no valid command found|r");
    return true;
}

//////////// WAYPOINT COMMANDS //

//rename characters
bool ChatHandler::HandleCharacterRenameCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        PSendSysMessage(LANG_RENAME_PLAYER, GetNameLink(target).c_str());
        target->SetAtLoginFlag(AT_LOGIN_RENAME);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string oldNameLink = playerLink(target_name);

        PSendSysMessage(LANG_RENAME_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(target_guid));
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '1' WHERE guid = '%u'", GUID_LOPART(target_guid));
    }

    return true;
}

// customize characters
bool ChatHandler::HandleCharacterCustomizeCommand(const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    if (target)
    {
        PSendSysMessage(LANG_CUSTOMIZE_PLAYER, GetNameLink(target).c_str());
        target->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = '%u'", target->GetGUIDLow());
    }
    else
    {
        std::string oldNameLink = playerLink(target_name);

        PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(target_guid));
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = '%u'", GUID_LOPART(target_guid));
    }

    return true;
}

bool ChatHandler::HandleCharacterChangeFactionCommand(const char * args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;

    if(!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    if(target)
    {
        // TODO : add text into database
        PSendSysMessage(LANG_CUSTOMIZE_PLAYER, GetNameLink(target).c_str());
        target->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", target->GetGUIDLow());
    }
    else
    {
        std::string oldNameLink = playerLink(target_name);

        // TODO : add text into database
        PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(target_guid));
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", GUID_LOPART(target_guid));
    }

    return true;
}

bool ChatHandler::HandleCharacterChangeRaceCommand(const char * args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if(!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    if(target)
    {
        // TODO : add text into database
        PSendSysMessage(LANG_CUSTOMIZE_PLAYER, GetNameLink(target).c_str());
        target->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '128' WHERE guid = %u", target->GetGUIDLow());
    }
    else
    {
        std::string oldNameLink = playerLink(target_name);

        // TODO : add text into database
        PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(target_guid));
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '128' WHERE guid = %u", GUID_LOPART(target_guid));
    }

    return true;
}

bool ChatHandler::HandleCharacterReputationCommand(const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    LocaleConstant loc = GetSessionDbcLocale();

    FactionStateList const& targetFSL = target->GetReputationMgr().GetStateList();
    for (FactionStateList::const_iterator itr = targetFSL.begin(); itr != targetFSL.end(); ++itr)
    {
        FactionEntry const *factionEntry = sFactionStore.LookupEntry(itr->second.ID);
        char const* factionName = factionEntry ? factionEntry->name[loc] : "#Not found#";
        ReputationRank rank = target->GetReputationMgr().GetRank(factionEntry);
        std::string rankName = GetTrinityString(ReputationRankStrIndex[rank]);
        std::ostringstream ss;
        if (m_session)
            ss << itr->second.ID << " - |cffffffff|Hfaction:" << itr->second.ID << "|h[" << factionName << " " << localeNames[loc] << "]|h|r";
        else
            ss << itr->second.ID << " - " << factionName << " " << localeNames[loc];

        ss << " " << rankName << " (" << target->GetReputationMgr().GetReputation(factionEntry) << ")";

        if (itr->second.Flags & FACTION_FLAG_VISIBLE)
            ss << GetTrinityString(LANG_FACTION_VISIBLE);
        if (itr->second.Flags & FACTION_FLAG_AT_WAR)
            ss << GetTrinityString(LANG_FACTION_ATWAR);
        if (itr->second.Flags & FACTION_FLAG_PEACE_FORCED)
            ss << GetTrinityString(LANG_FACTION_PEACE_FORCED);
        if (itr->second.Flags & FACTION_FLAG_HIDDEN)
            ss << GetTrinityString(LANG_FACTION_HIDDEN);
        if (itr->second.Flags & FACTION_FLAG_INVISIBLE_FORCED)
            ss << GetTrinityString(LANG_FACTION_INVISIBLE_FORCED);
        if (itr->second.Flags & FACTION_FLAG_INACTIVE)
            ss << GetTrinityString(LANG_FACTION_INACTIVE);

        SendSysMessage(ss.str().c_str());
    }
    return true;
}

bool ChatHandler::HandleHonorAddCommand(const char* args)
{
    if (!*args)
        return false;

    Player *target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    uint32 amount = (uint32)atoi(args);
    target->RewardHonor(NULL, 1, amount);
    return true;
}

bool ChatHandler::HandleHonorAddKillCommand(const char* /*args*/)
{
    Unit *target = getSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target, 0))
        return false;

    m_session->GetPlayer()->RewardHonor(target, 1);
    return true;
}

bool ChatHandler::HandleHonorUpdateCommand(const char* /*args*/)
{
    Player *target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    target->UpdateHonorFields();
    return true;
}

bool ChatHandler::HandleLookupEventCommand(const char* args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    wstrToLower(wnamepart);

    bool found = false;
    uint32 count = 0;
    uint32 maxResults = sWorld.getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

    GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();
    GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr.GetActiveEventList();

    for (uint32 id = 0; id < events.size(); ++id)
    {
        GameEventData const& eventData = events[id];

        std::string descr = eventData.description;
        if (descr.empty())
            continue;

        if (Utf8FitTo(descr, wnamepart))
        {
            if (maxResults && count++ == maxResults)
            {
                PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                return true;
            }

            char const* active = activeEvents.find(id) != activeEvents.end() ? GetTrinityString(LANG_ACTIVE) : "";

            if (m_session)
                PSendSysMessage(LANG_EVENT_ENTRY_LIST_CHAT,id,id,eventData.description.c_str(),active);
            else
                PSendSysMessage(LANG_EVENT_ENTRY_LIST_CONSOLE,id,eventData.description.c_str(),active);

            if (!found)
                found = true;
        }
    }

    if (!found)
        SendSysMessage(LANG_NOEVENTFOUND);

    return true;
}

bool ChatHandler::HandleCombatStopCommand(const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    target->CombatStop();
    target->getHostileRefManager().deleteReferences();
    return true;
}

bool ChatHandler::HandleLookupPlayerIpCommand(const char* args)
{

    if (!*args)
        return false;

    std::string ip = strtok ((char*)args, " ");
    char* limit_str = strtok (NULL, " ");
    int32 limit = limit_str ? atoi (limit_str) : -1;

    LoginDatabase.escape_string (ip);

    QueryResult result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE last_ip = '%s'", ip.c_str ());

    return LookupPlayerSearchCommand (result,limit);
}

bool ChatHandler::HandleLookupPlayerAccountCommand(const char* args)
{
    if (!*args)
        return false;

    std::string account = strtok ((char*)args, " ");
    char* limit_str = strtok (NULL, " ");
    int32 limit = limit_str ? atoi (limit_str) : -1;

    if (!AccountMgr::normalizeString (account))
        return false;

    LoginDatabase.escape_string (account);

    QueryResult result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE username = '%s'", account.c_str ());

    return LookupPlayerSearchCommand (result,limit);
}

bool ChatHandler::HandleLookupPlayerEmailCommand(const char* args)
{

    if (!*args)
        return false;

    std::string email = strtok ((char*)args, " ");
    char* limit_str = strtok (NULL, " ");
    int32 limit = limit_str ? atoi (limit_str) : -1;

    LoginDatabase.escape_string (email);

    QueryResult result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE email = '%s'", email.c_str ());

    return LookupPlayerSearchCommand (result,limit);
}

bool ChatHandler::LookupPlayerSearchCommand(QueryResult result, int32 limit)
{
    if (!result)
    {
        PSendSysMessage(LANG_NO_PLAYERS_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    int i = 0;
    uint32 count = 0;
    uint32 maxResults = sWorld.getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
    do
    {
        if (maxResults && count++ == maxResults)
        {
            PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
            return true;
        }

        Field* fields = result->Fetch();
        uint32 acc_id = fields[0].GetUInt32();
        std::string acc_name = fields[1].GetString();

        QueryResult chars = CharacterDatabase.PQuery("SELECT guid,name FROM characters WHERE account = '%u'", acc_id);
        if (chars)
        {
            PSendSysMessage(LANG_LOOKUP_PLAYER_ACCOUNT,acc_name.c_str(),acc_id);

            uint64 guid = 0;
            std::string name;

            do
            {
                Field* charfields = chars->Fetch();
                guid = charfields[0].GetUInt64();
                name = charfields[1].GetString();

                PSendSysMessage(LANG_LOOKUP_PLAYER_CHARACTER,name.c_str(),guid);
                ++i;

            } while (chars->NextRow() && (limit == -1 || i < limit));
        }
    } while (result->NextRow());

    if (i == 0)                                                // empty accounts only
    {
        PSendSysMessage(LANG_NO_PLAYERS_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

/// Triggering corpses expire check in world
bool ChatHandler::HandleServerCorpsesCommand(const char* /*args*/)
{
    sObjectAccessor.RemoveOldCorpses();
    return true;
}

bool ChatHandler::HandleRepairitemsCommand(const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    // Repair items
    target->DurabilityRepairAll(false, 0, false);

    PSendSysMessage(LANG_YOU_REPAIR_ITEMS, GetNameLink(target).c_str());
    if (needReportToTarget(target))
        ChatHandler(target).PSendSysMessage(LANG_YOUR_ITEMS_REPAIRED, GetNameLink().c_str());
    return true;
}

bool ChatHandler::HandleWaterwalkCommand(const char* args)
{
    if (!*args)
        return false;

    Player *player = getSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(player, 0))
        return false;

    if (strncmp(args, "on", 3) == 0)
        player->SetMovement(MOVE_WATER_WALK);               // ON
    else if (strncmp(args, "off", 4) == 0)
        player->SetMovement(MOVE_LAND_WALK);                // OFF
    else
    {
        SendSysMessage(LANG_USE_BOL);
        return false;
    }

    PSendSysMessage(LANG_YOU_SET_WATERWALK, args, GetNameLink(player).c_str());
    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOUR_WATERWALK_SET, args, GetNameLink().c_str());
    return true;
}

bool ChatHandler::HandleCreatePetCommand(const char* /*args*/)
{
    Player *player = m_session->GetPlayer();
    Creature *creatureTarget = getSelectedCreature();

    if (!creatureTarget || creatureTarget->isPet() || creatureTarget->GetTypeId() == TYPEID_PLAYER)
    {
        PSendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    CreatureInfo const* cInfo = sObjectMgr.GetCreatureTemplate(creatureTarget->GetEntry());
    // Creatures with family 0 crashes the server
    if (cInfo->family == 0)
    {
        PSendSysMessage("This creature cannot be tamed. (family id: 0).");
        SetSentErrorMessage(true);
        return false;
    }

    if (player->GetPetGUID())
    {
        PSendSysMessage("You already have a pet");
        SetSentErrorMessage(true);
        return false;
    }

    // Everything looks OK, create new pet
    Pet* pet = new Pet(player, HUNTER_PET);

    if (!pet)
      return false;

    if (!pet->CreateBaseAtCreature(creatureTarget))
    {
        delete pet;
        PSendSysMessage("Error 1");
        return false;
    }

    creatureTarget->setDeathState(JUST_DIED);
    creatureTarget->RemoveCorpse();
    creatureTarget->SetHealth(0); // just for nice GM-mode view

    pet->SetUInt64Value(UNIT_FIELD_CREATEDBY, player->GetGUID());
    pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, player->getFaction());

    if (!pet->InitStatsForLevel(creatureTarget->getLevel()))
    {
        sLog.outError("InitStatsForLevel() in EffectTameCreature failed! Pet deleted.");
        PSendSysMessage("Error 2");
        delete pet;
        return false;
    }

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL,creatureTarget->getLevel()-1);

    pet->GetCharmInfo()->SetPetNumber(sObjectMgr.GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    pet->SetFullHealth();

    pet->GetMap()->Add(pet->ToCreature());

    // visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL,creatureTarget->getLevel());

    player->SetMinion(pet, true);
    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
    player->PetSpellInitialize();

    return true;
}

bool ChatHandler::HandlePetLearnCommand(const char* args)
{
    if (!*args)
        return false;

    Player *plr = m_session->GetPlayer();
    Pet *pet = plr->GetPet();

    if (!pet)
    {
        PSendSysMessage("You have no pet");
        SetSentErrorMessage(true);
        return false;
    }

    uint32 spellId = extractSpellIdFromLink((char*)args);

    if (!spellId || !sSpellStore.LookupEntry(spellId))
        return false;

    // Check if pet already has it
    if (pet->HasSpell(spellId))
    {
        PSendSysMessage("Pet already has spell: %u", spellId);
        SetSentErrorMessage(true);
        return false;
    }

    // Check if spell is valid
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spellId);
        SetSentErrorMessage(true);
        return false;
    }

    pet->learnSpell(spellId);

    PSendSysMessage("Pet has learned spell %u", spellId);
    return true;
}

bool ChatHandler::HandlePetUnlearnCommand(const char *args)
{
    if (!*args)
        return false;

    Player *plr = m_session->GetPlayer();
    Pet *pet = plr->GetPet();

    if (!pet)
    {
        PSendSysMessage("You have no pet");
        SetSentErrorMessage(true);
        return false;
    }

    uint32 spellId = extractSpellIdFromLink((char*)args);

    if (pet->HasSpell(spellId))
        pet->removeSpell(spellId, false);
    else
        PSendSysMessage("Pet doesn't have that spell");

    return true;
}

bool ChatHandler::HandlePetTpCommand(const char *args)
{
    if (!*args)
        return false;

    Player *plr = m_session->GetPlayer();
    Pet *pet = plr->GetPet();

    if (!pet)
    {
        PSendSysMessage("You have no pet");
        SetSentErrorMessage(true);
        return false;
    }

    uint32 tp = atol(args);

    //pet->SetTP(tp);

    PSendSysMessage("Pet's tp changed to %u", tp);
    return true;
}

bool ChatHandler::HandleActivateObjectCommand(const char *args)
{
    if (!*args)
        return false;

    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* obj = NULL;

    // by DB guid
    if (GameObjectData const* go_data = sObjectMgr.GetGOData(lowguid))
        obj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

    if (!obj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    // Activate
    obj->SetLootState(GO_READY);
    obj->UseDoorOrButton(10000);

    PSendSysMessage("Object activated!");

    return true;
}

// add go, temp only
bool ChatHandler::HandleTempGameObjectCommand(const char* args)
{
    if (!*args)
        return false;
    char* charID = strtok((char*)args, " ");
    if (!charID)
        return false;

    Player *chr = m_session->GetPlayer();

    char* spawntime = strtok(NULL, " ");
    uint32 spawntm = 300;

    if (spawntime)
        spawntm = atoi((char*)spawntime);

    float x = chr->GetPositionX();
    float y = chr->GetPositionY();
    float z = chr->GetPositionZ();
    float ang = chr->GetOrientation();

    float rot2 = sin(ang/2);
    float rot3 = cos(ang/2);

    uint32 id = atoi(charID);

    chr->SummonGameObject(id,x,y,z,ang,0,0,rot2,rot3,spawntm);

    return true;
}

bool ChatHandler::HandleLookupTitleCommand(const char* args)
{
    if (!*args)
        return false;

    // can be NULL in console call
    Player* target = getSelectedPlayer();

    // title name have single string arg for player name
    char const* targetName = target ? target->GetName() : "NAME";

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    uint32 counter = 0;                                     // Counter for figure out that we found smth.
    uint32 maxResults = sWorld.getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

    // Search in CharTitles.dbc
    for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
    {
        CharTitlesEntry const *titleInfo = sCharTitlesStore.LookupEntry(id);
        if (titleInfo)
        {
            int loc = GetSessionDbcLocale();
            std::string name = titleInfo->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < TOTAL_LOCALES; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = titleInfo->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < TOTAL_LOCALES)
            {
                if (maxResults && counter == maxResults)
                {
                    PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                char const* knownStr = target && target->HasTitle(titleInfo) ? GetTrinityString(LANG_KNOWN) : "";

                char const* activeStr = target && target->GetUInt32Value(PLAYER_CHOSEN_TITLE) == titleInfo->bit_index
                    ? GetTrinityString(LANG_ACTIVE)
                    : "";

                char titleNameStr[80];
                snprintf(titleNameStr,80,name.c_str(),targetName);

                // send title in "id (idx:idx) - [namedlink locale]" format
                if (m_session)
                    PSendSysMessage(LANG_TITLE_LIST_CHAT,id,titleInfo->bit_index,id,titleNameStr,localeNames[loc],knownStr,activeStr);
                else
                    PSendSysMessage(LANG_TITLE_LIST_CONSOLE,id,titleInfo->bit_index,titleNameStr,localeNames[loc],knownStr,activeStr);

                ++counter;
            }
        }
    }
    if (counter == 0)                                       // if counter == 0 then we found nth
        SendSysMessage(LANG_COMMAND_NOTITLEFOUND);
    return true;
}

bool ChatHandler::HandleTitlesAddCommand(const char* args)
{
    // number or [name] Shift-click form |color|Htitle:title_id|h[name]|h|r
    char* id_p = extractKeyFromLink((char*)args,"Htitle");
    if (!id_p)
        return false;

    int32 id = atoi(id_p);
    if (id <= 0)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    Player * target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
    if (!titleInfo)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    char const* targetName = target->GetName();
    char titleNameStr[80];
    snprintf(titleNameStr,80,titleInfo->name[GetSessionDbcLocale()],targetName);

    target->SetTitle(titleInfo);
    PSendSysMessage(LANG_TITLE_ADD_RES, id, titleNameStr, tNameLink.c_str());

    return true;
}

bool ChatHandler::HandleTitlesRemoveCommand(const char* args)
{
    // number or [name] Shift-click form |color|Htitle:title_id|h[name]|h|r
    char* id_p = extractKeyFromLink((char*)args,"Htitle");
    if (!id_p)
        return false;

    int32 id = atoi(id_p);
    if (id <= 0)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    Player * target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
    if (!titleInfo)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    target->SetTitle(titleInfo,true);

    std::string tNameLink = GetNameLink(target);

    char const* targetName = target->GetName();
    char titleNameStr[80];
    snprintf(titleNameStr,80,titleInfo->name[GetSessionDbcLocale()],targetName);

    PSendSysMessage(LANG_TITLE_REMOVE_RES, id, titleNameStr, tNameLink.c_str());

    if (!target->HasTitle(target->GetInt32Value(PLAYER_CHOSEN_TITLE)))
    {
        target->SetUInt32Value(PLAYER_CHOSEN_TITLE,0);
        PSendSysMessage(LANG_CURRENT_TITLE_RESET, tNameLink.c_str());
    }

    return true;
}

//Edit Player KnownTitles
bool ChatHandler::HandleTitlesSetMaskCommand(const char* args)
{
    if (!*args)
        return false;

    uint64 titles = 0;

    sscanf((char*)args, UI64FMTD, &titles);

    Player *target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    uint64 titles2 = titles;

    for (uint32 i = 1; i < sCharTitlesStore.GetNumRows(); ++i)
        if (CharTitlesEntry const* tEntry = sCharTitlesStore.LookupEntry(i))
            titles2 &= ~(uint64(1) << tEntry->bit_index);

    titles &= ~titles2;                                     // remove not existed titles

    target->SetUInt64Value(PLAYER__FIELD_KNOWN_TITLES, titles);
    SendSysMessage(LANG_DONE);

    if (!target->HasTitle(target->GetInt32Value(PLAYER_CHOSEN_TITLE)))
    {
        target->SetUInt32Value(PLAYER_CHOSEN_TITLE,0);
        PSendSysMessage(LANG_CURRENT_TITLE_RESET,GetNameLink(target).c_str());
    }

    return true;
}

bool ChatHandler::HandleCharacterTitlesCommand(const char* args)
{
    if (!*args)
        return false;

    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    LocaleConstant loc = GetSessionDbcLocale();
    char const* targetName = target->GetName();
    char const* knownStr = GetTrinityString(LANG_KNOWN);

    // Search in CharTitles.dbc
    for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
    {
        CharTitlesEntry const *titleInfo = sCharTitlesStore.LookupEntry(id);
        if (titleInfo && target->HasTitle(titleInfo))
        {
            std::string name = titleInfo->name[loc];
            if (name.empty())
                continue;

            char const* activeStr = target && target->GetUInt32Value(PLAYER_CHOSEN_TITLE) == titleInfo->bit_index
                ? GetTrinityString(LANG_ACTIVE)
                : "";

            char titleNameStr[80];
            snprintf(titleNameStr,80,name.c_str(),targetName);

            // send title in "id (idx:idx) - [namedlink locale]" format
            if (m_session)
                PSendSysMessage(LANG_TITLE_LIST_CHAT,id,titleInfo->bit_index,id,titleNameStr,localeNames[loc],knownStr,activeStr);
            else
                PSendSysMessage(LANG_TITLE_LIST_CONSOLE,id,titleInfo->bit_index,name.c_str(),localeNames[loc],knownStr,activeStr);
        }
    }
    return true;
}

bool ChatHandler::HandleTitlesCurrentCommand(const char* args)
{
    // number or [name] Shift-click form |color|Htitle:title_id|h[name]|h|r
    char* id_p = extractKeyFromLink((char*)args,"Htitle");
    if (!id_p)
        return false;

    int32 id = atoi(id_p);
    if (id <= 0)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    Player * target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
    if (!titleInfo)
    {
        PSendSysMessage(LANG_INVALID_TITLE_ID, id);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    target->SetTitle(titleInfo);                            // to be sure that title now known
    target->SetUInt32Value(PLAYER_CHOSEN_TITLE,titleInfo->bit_index);

    PSendSysMessage(LANG_TITLE_CURRENT_RES, id, titleInfo->name[GetSessionDbcLocale()], tNameLink.c_str());

    return true;
}
