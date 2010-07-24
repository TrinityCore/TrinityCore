/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "GlobalEvents.h"
#include "OutdoorPvPMgr.h"

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

    uint32 account_id = target ? target->GetSession()->GetAccountId() : objmgr.GetPlayerAccountIdByGUID(target_guid);

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

    uint32 account_id = target ? target->GetSession()->GetAccountId() : objmgr.GetPlayerAccountIdByGUID(target_guid);

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

bool ChatHandler::HandleGoTicketCommand(const char * args)
{
    if (!*args)
        return false;

    char *cstrticket_id = strtok((char*)args, " ");

    if (!cstrticket_id)
        return false;

    uint64 ticket_id = atoi(cstrticket_id);
    if (!ticket_id)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticket_id);
    if (!ticket)
    {
        SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
        return true;
    }

    float x, y, z;
    int mapid;

    x = ticket->pos_x;
    y = ticket->pos_y;
    z = ticket->pos_z;
    mapid = ticket->map;

    Player* _player = m_session->GetPlayer();
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
     else
        _player->SaveRecallPosition();

    _player->TeleportTo(mapid, x, y, z, 1, 0);
    return true;
}

bool ChatHandler::HandleGoTriggerCommand(const char* args)
{
    Player* _player = m_session->GetPlayer();

    if (!*args)
        return false;

    char *atId = strtok((char*)args, " ");
    if (!atId)
        return false;

    int32 i_atId = atoi(atId);

    if (!i_atId)
        return false;

    AreaTriggerEntry const* at = sAreaTriggerStore.LookupEntry(i_atId);
    if (!at)
    {
        PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND,i_atId);
        SetSentErrorMessage(true);
        return false;
    }

    if (!MapManager::IsValidMapCoord(at->mapid,at->x,at->y,at->z))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD,at->x,at->y,at->mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(at->mapid, at->x, at->y, at->z, _player->GetOrientation());
    return true;
}

bool ChatHandler::HandleGoGraveyardCommand(const char* args)
{
    Player* _player = m_session->GetPlayer();

    if (!*args)
        return false;

    char *gyId = strtok((char*)args, " ");
    if (!gyId)
        return false;

    int32 i_gyId = atoi(gyId);

    if (!i_gyId)
        return false;

    WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(i_gyId);
    if (!gy)
    {
        PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST,i_gyId);
        SetSentErrorMessage(true);
        return false;
    }

    if (!MapManager::IsValidMapCoord(gy->map_id,gy->x,gy->y,gy->z))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD,gy->x,gy->y,gy->map_id);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(gy->map_id, gy->x, gy->y, gy->z, _player->GetOrientation());
    return true;
}

/** \brief Teleport the GM to the specified creature
*
* .gocreature <GUID>      --> TP using creature.guid
* .gocreature azuregos    --> TP player to the mob with this name
*                             Warning: If there is more than one mob with this name
*                                      you will be teleported to the first one that is found.
* .gocreature id 6109     --> TP player to the mob, that has this creature_template.entry
*                             Warning: If there is more than one mob with this "id"
*                                      you will be teleported to the first one that is found.
*/
//teleport to creature
bool ChatHandler::HandleGoCreatureCommand(const char* args)
{
    if (!*args)
        return false;
    Player* _player = m_session->GetPlayer();

    // "id" or number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
    char* pParam1 = extractKeyFromLink((char*)args,"Hcreature");
    if (!pParam1)
        return false;

    std::ostringstream whereClause;

    // User wants to teleport to the NPC's template entry
    if (strcmp(pParam1, "id") == 0)
    {
        //sLog.outError("DEBUG: ID found");

        // Get the "creature_template.entry"
        // number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
        char* tail = strtok(NULL,"");
        if (!tail)
            return false;
        char* cId = extractKeyFromLink(tail,"Hcreature_entry");
        if (!cId)
            return false;

        int32 tEntry = atoi(cId);
        //sLog.outError("DEBUG: ID value: %d", tEntry);
        if (!tEntry)
            return false;

        whereClause << "WHERE id = '" << tEntry << "'";
    }
    else
    {
        //sLog.outError("DEBUG: ID *not found*");

        int32 guid = atoi(pParam1);

        // Number is invalid - maybe the user specified the mob's name
        if (!guid)
        {
            std::string name = pParam1;
            WorldDatabase.escape_string(name);
            whereClause << ", creature_template WHERE creature.id = creature_template.entry AND creature_template.name "_LIKE_" '" << name << "'";
        }
        else
        {
            whereClause <<  "WHERE guid = '" << guid << "'";
        }
    }
    //sLog.outError("DEBUG: %s", whereClause.c_str());

    QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT position_x,position_y,position_z,orientation,map FROM creature %s", whereClause.str().c_str());
    if (!result)
    {
        SendSysMessage(LANG_COMMAND_GOCREATNOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }
    if (result->GetRowCount() > 1)
        SendSysMessage(LANG_COMMAND_GOCREATMULTIPLE);

    Field *fields = result->Fetch();
    float x = fields[0].GetFloat();
    float y = fields[1].GetFloat();
    float z = fields[2].GetFloat();
    float ort = fields[3].GetFloat();
    int mapid = fields[4].GetUInt16();

    if (!MapManager::IsValidMapCoord(mapid,x,y,z,ort))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD,x,y,mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(mapid, x, y, z, ort);
    return true;
}

//teleport to gameobject
bool ChatHandler::HandleGoObjectCommand(const char* args)
{
    if (!*args)
        return false;

    Player* _player = m_session->GetPlayer();

    // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject");
    if (!cId)
        return false;

    int32 guid = atoi(cId);
    if (!guid)
        return false;

    float x, y, z, ort;
    int mapid;

    // by DB guid
    if (GameObjectData const* go_data = objmgr.GetGOData(guid))
    {
        x = go_data->posX;
        y = go_data->posY;
        z = go_data->posZ;
        ort = go_data->orientation;
        mapid = go_data->mapid;
    }
    else
    {
        SendSysMessage(LANG_COMMAND_GOOBJNOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (!MapManager::IsValidMapCoord(mapid,x,y,z,ort))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD,x,y,mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(mapid, x, y, z, ort);
    return true;
}

bool ChatHandler::HandleGameObjectTargetCommand(const char* args)
{
    Player* pl = m_session->GetPlayer();
    QueryResult_AutoPtr result;
    GameEventMgr::ActiveEvents const& activeEventsList = gameeventmgr.GetActiveEventList();
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
    uint16 mapid, pool_id, phase;

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
        pool_id = poolhandler.IsPartOfAPool<GameObject>(lowguid);
        if (!pool_id || poolhandler.IsSpawnedObject<GameObject>(lowguid))
            found = true;
    } while (result->NextRow() && (!found));

    if (!found)
    {
        PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
        return false;
    }

    GameObjectInfo const* goI = objmgr.GetGameObjectInfo(id);

    if (!goI)
    {
        PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
        return false;
    }

    GameObject* target = m_session->GetPlayer()->GetMap()->GetGameObject(MAKE_NEW_GUID(lowguid,id,HIGHGUID_GAMEOBJECT));

    PSendSysMessage(LANG_GAMEOBJECT_DETAIL, lowguid, goI->name, lowguid, id, x, y, z, mapid, o, phase);

    if (target)
    {
        int32 curRespawnDelay = target->GetRespawnTimeEx()-time(NULL);
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
    if (GameObjectData const* go_data = objmgr.GetGOData(lowguid))
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
    if (GameObjectData const* go_data = objmgr.GetGOData(lowguid))
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
    if (GameObjectData const* go_data = objmgr.GetGOData(lowguid))
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

    const GameObjectInfo *gInfo = objmgr.GetGameObjectInfo(id);

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
    uint32 db_lowGUID = objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT);

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
    objmgr.AddGameobjectToGrid(db_lowGUID, objmgr.GetGOData(db_lowGUID));

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
    if (GameObjectData const* go_data = objmgr.GetGOData(lowguid))
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
    float distance = (!*args) ? 10 : atol(args);
    uint32 count = 0;

    Player* pl = m_session->GetPlayer();
    QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT guid, id, position_x, position_y, position_z, map, "
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

            GameObjectInfo const * gInfo = objmgr.GetGameObjectInfo(entry);

            if (!gInfo)
                continue;

            PSendSysMessage(LANG_GO_LIST_CHAT, guid, guid, gInfo->name, x, y, z, mapid);

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

bool ChatHandler::HandleModifyRepCommand(const char * args)
{
    if (!*args) return false;

    Player* target = NULL;
    target = getSelectedPlayer();

    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    char* factionTxt = extractKeyFromLink((char*)args,"Hfaction");
    if (!factionTxt)
        return false;

    uint32 factionId = atoi(factionTxt);

    int32 amount = 0;
    char *rankTxt = strtok(NULL, " ");
    if (!factionTxt || !rankTxt)
        return false;

    amount = atoi(rankTxt);
    if ((amount == 0) && (rankTxt[0] != '-') && !isdigit(rankTxt[0]))
    {
        std::string rankStr = rankTxt;
        std::wstring wrankStr;
        if (!Utf8toWStr(rankStr,wrankStr))
            return false;
        wstrToLower(wrankStr);

        int r = 0;
        amount = -42000;
        for (; r < MAX_REPUTATION_RANK; ++r)
        {
            std::string rank = GetTrinityString(ReputationRankStrIndex[r]);
            if (rank.empty())
                continue;

            std::wstring wrank;
            if (!Utf8toWStr(rank,wrank))
                continue;

            wstrToLower(wrank);

            if (wrank.substr(0,wrankStr.size()) == wrankStr)
            {
                char *deltaTxt = strtok(NULL, " ");
                if (deltaTxt)
                {
                    int32 delta = atoi(deltaTxt);
                    if ((delta < 0) || (delta > ReputationMgr::PointsInRank[r] -1))
                    {
                        PSendSysMessage(LANG_COMMAND_FACTION_DELTA, (ReputationMgr::PointsInRank[r]-1));
                        SetSentErrorMessage(true);
                        return false;
                    }
                    amount += delta;
                }
                break;
            }
            amount += ReputationMgr::PointsInRank[r];
        }
        if (r >= MAX_REPUTATION_RANK)
        {
            PSendSysMessage(LANG_COMMAND_FACTION_INVPARAM, rankTxt);
            SetSentErrorMessage(true);
            return false;
        }
    }

    FactionEntry const *factionEntry = sFactionStore.LookupEntry(factionId);

    if (!factionEntry)
    {
        PSendSysMessage(LANG_COMMAND_FACTION_UNKNOWN, factionId);
        SetSentErrorMessage(true);
        return false;
    }

    if (factionEntry->reputationListID < 0)
    {
        PSendSysMessage(LANG_COMMAND_FACTION_NOREP_ERROR, factionEntry->name[GetSessionDbcLocale()], factionId);
        SetSentErrorMessage(true);
        return false;
    }

    target->GetReputationMgr().SetReputation(factionEntry,amount);
    PSendSysMessage(LANG_COMMAND_MODIFY_REP, factionEntry->name[GetSessionDbcLocale()], factionId,
        GetNameLink(target).c_str(), target->GetReputationMgr().GetReputation(factionEntry));
    return true;
}

//-----------------------Npc Commands-----------------------
//add spawn of creature
bool ChatHandler::HandleNpcAddCommand(const char* args)
{
    if (!*args)
        return false;
    char* charID = extractKeyFromLink((char*)args,"Hcreature_entry");
    if (!charID)
        return false;

    char* team = strtok(NULL, " ");
    int32 teamval = 0;
    if (team) { teamval = atoi(team); }
    if (teamval < 0) { teamval = 0; }

    uint32 id  = atoi(charID);

    Player *chr = m_session->GetPlayer();
    float x = chr->GetPositionX();
    float y = chr->GetPositionY();
    float z = chr->GetPositionZ();
    float o = chr->GetOrientation();
    Map *map = chr->GetMap();

    Creature* pCreature = new Creature;
    if (!pCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), id, 0, (uint32)teamval, x, y, z, o))
    {
        delete pCreature;
        return false;
    }

    pCreature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());

    uint32 db_guid = pCreature->GetDBTableGUIDLow();

    // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
    pCreature->LoadFromDB(db_guid, map);

    map->Add(pCreature);
    objmgr.AddCreatureToGrid(db_guid, objmgr.GetCreatureData(db_guid));
    return true;
}

//add item in vendorlist
bool ChatHandler::HandleNpcAddVendorItemCommand(const char* args)
{
    if (!*args)
        return false;

    char* pitem  = extractKeyFromLink((char*)args,"Hitem");
    if (!pitem)
    {
        SendSysMessage(LANG_COMMAND_NEEDITEMSEND);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 itemId = atol(pitem);

    char* fmaxcount = strtok(NULL, " ");                    //add maxcount, default: 0
    uint32 maxcount = 0;
    if (fmaxcount)
        maxcount = atol(fmaxcount);

    char* fincrtime = strtok(NULL, " ");                    //add incrtime, default: 0
    uint32 incrtime = 0;
    if (fincrtime)
        incrtime = atol(fincrtime);

    char* fextendedcost = strtok(NULL, " ");                //add ExtendedCost, default: 0
    uint32 extendedcost = fextendedcost ? atol(fextendedcost) : 0;

    Creature* vendor = getSelectedCreature();

    uint32 vendor_entry = vendor ? vendor->GetEntry() : 0;

    if (!objmgr.IsVendorItemValid(vendor_entry,itemId,maxcount,incrtime,extendedcost,m_session->GetPlayer()))
    {
        SetSentErrorMessage(true);
        return false;
    }

    objmgr.AddVendorItem(vendor_entry,itemId,maxcount,incrtime,extendedcost);

    ItemPrototype const* pProto = objmgr.GetItemPrototype(itemId);

    PSendSysMessage(LANG_ITEM_ADDED_TO_LIST,itemId,pProto->Name1,maxcount,incrtime,extendedcost);
    return true;
}

//del item from vendor list
bool ChatHandler::HandleNpcDelVendorItemCommand(const char* args)
{
    if (!*args)
        return false;

    Creature* vendor = getSelectedCreature();
    if (!vendor || !vendor->isVendor())
    {
        SendSysMessage(LANG_COMMAND_VENDORSELECTION);
        SetSentErrorMessage(true);
        return false;
    }

    char* pitem  = extractKeyFromLink((char*)args,"Hitem");
    if (!pitem)
    {
        SendSysMessage(LANG_COMMAND_NEEDITEMSEND);
        SetSentErrorMessage(true);
        return false;
    }
    uint32 itemId = atol(pitem);

    if (!objmgr.RemoveVendorItem(vendor->GetEntry(),itemId))
    {
        PSendSysMessage(LANG_ITEM_NOT_IN_LIST,itemId);
        SetSentErrorMessage(true);
        return false;
    }

    ItemPrototype const* pProto = objmgr.GetItemPrototype(itemId);

    PSendSysMessage(LANG_ITEM_DELETED_FROM_LIST,itemId,pProto->Name1);
    return true;
}

//add move for creature
bool ChatHandler::HandleNpcAddMoveCommand(const char* args)
{
    if (!*args)
        return false;

    char* guid_str = strtok((char*)args, " ");
    char* wait_str = strtok((char*)NULL, " ");

    uint32 lowguid = atoi((char*)guid_str);

    Creature* pCreature = NULL;

    /* FIXME: impossible without entry
    if (lowguid)
        pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(),MAKE_GUID(lowguid,HIGHGUID_UNIT));
    */

    // attempt check creature existence by DB data
    if (!pCreature)
    {
        CreatureData const* data = objmgr.GetCreatureData(lowguid);
        if (!data)
        {
            PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowguid);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        // obtain real GUID for DB operations
        lowguid = pCreature->GetDBTableGUIDLow();
    }

    int wait = wait_str ? atoi(wait_str) : 0;

    if (wait < 0)
        wait = 0;

    //Player* player = m_session->GetPlayer();

    //WaypointMgr.AddLastNode(lowguid, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), wait, 0);

    // update movement type
    WorldDatabase.PExecuteLog("UPDATE creature SET MovementType = '%u' WHERE guid = '%u'", WAYPOINT_MOTION_TYPE,lowguid);
    if (pCreature && pCreature->GetWaypointPath())
    {
        pCreature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
        pCreature->GetMotionMaster()->Initialize();
        if (pCreature->isAlive())                            // dead creature will reset movement generator at respawn
        {
            pCreature->setDeathState(JUST_DIED);
            pCreature->Respawn(true);
        }
        pCreature->SaveToDB();
    }

    SendSysMessage(LANG_WAYPOINT_ADDED);

    return true;
}

//change level of creature or pet
bool ChatHandler::HandleNpcChangeLevelCommand(const char* args)
{
    if (!*args)
        return false;

    uint8 lvl = (uint8) atoi((char*)args);
    if (lvl < 1 || lvl > sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL) + 3)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Creature* pCreature = getSelectedCreature();
    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (pCreature->isPet())
    {
        if (((Pet*)pCreature)->getPetType() == HUNTER_PET)
        {
            pCreature->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, objmgr.GetXPForLevel(lvl)/4);
            pCreature->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
        }
        ((Pet*)pCreature)->GivePetLevel(lvl);
    }
    else
    {
        pCreature->SetMaxHealth(100 + 30*lvl);
        pCreature->SetHealth(100 + 30*lvl);
        pCreature->SetLevel(lvl);
        pCreature->SaveToDB();
    }

    return true;
}

//set npcflag of creature
bool ChatHandler::HandleNpcFlagCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 npcFlags = (uint32) atoi((char*)args);

    Creature* pCreature = getSelectedCreature();

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    pCreature->SetUInt32Value(UNIT_NPC_FLAGS, npcFlags);

    WorldDatabase.PExecuteLog("UPDATE creature_template SET npcflag = '%u' WHERE entry = '%u'", npcFlags, pCreature->GetEntry());

    SendSysMessage(LANG_VALUE_SAVED_REJOIN);

    return true;
}

bool ChatHandler::HandleNpcDeleteCommand(const char* args)
{
    Creature* unit = NULL;

    if (*args)
    {
        // number or [name] Shift-click form |color|Hcreature:creature_guid|h[name]|h|r
        char* cId = extractKeyFromLink((char*)args,"Hcreature");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        if (CreatureData const* cr_data = objmgr.GetCreatureData(lowguid))
            unit = m_session->GetPlayer()->GetMap()->GetCreature(MAKE_NEW_GUID(lowguid, cr_data->id, HIGHGUID_UNIT));
    }
    else
        unit = getSelectedCreature();

    if (!unit || unit->isPet() || unit->isTotem())
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // Delete the creature
    unit->CombatStop();
    unit->DeleteFromDB();
    unit->AddObjectToRemoveList();

    SendSysMessage(LANG_COMMAND_DELCREATMESSAGE);

    return true;
}

//move selected creature
bool ChatHandler::HandleNpcMoveCommand(const char* args)
{
    uint32 lowguid = 0;

    Creature* pCreature = getSelectedCreature();

    if (!pCreature)
    {
        // number or [name] Shift-click form |color|Hcreature:creature_guid|h[name]|h|r
        char* cId = extractKeyFromLink((char*)args,"Hcreature");
        if (!cId)
            return false;

        lowguid = atoi(cId);

        /* FIXME: impossibel without entry
        if (lowguid)
            pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(),MAKE_GUID(lowguid,HIGHGUID_UNIT));
        */

        // Attempting creature load from DB data
        if (!pCreature)
        {
            CreatureData const* data = objmgr.GetCreatureData(lowguid);
            if (!data)
            {
                PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowguid);
                SetSentErrorMessage(true);
                return false;
            }

            uint32 map_id = data->mapid;

            if (m_session->GetPlayer()->GetMapId() != map_id)
            {
                PSendSysMessage(LANG_COMMAND_CREATUREATSAMEMAP, lowguid);
                SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            lowguid = pCreature->GetDBTableGUIDLow();
        }
    }
    else
    {
        lowguid = pCreature->GetDBTableGUIDLow();
    }

    float x = m_session->GetPlayer()->GetPositionX();
    float y = m_session->GetPlayer()->GetPositionY();
    float z = m_session->GetPlayer()->GetPositionZ();
    float o = m_session->GetPlayer()->GetOrientation();

    if (pCreature)
    {
        if (CreatureData const* data = objmgr.GetCreatureData(pCreature->GetDBTableGUIDLow()))
        {
            const_cast<CreatureData*>(data)->posX = x;
            const_cast<CreatureData*>(data)->posY = y;
            const_cast<CreatureData*>(data)->posZ = z;
            const_cast<CreatureData*>(data)->orientation = o;
        }
        pCreature->GetMap()->CreatureRelocation(pCreature,x, y, z,o);
        pCreature->GetMotionMaster()->Initialize();
        if (pCreature->isAlive())                            // dead creature will reset movement generator at respawn
        {
            pCreature->setDeathState(JUST_DIED);
            pCreature->Respawn();
        }
    }

    WorldDatabase.PExecuteLog("UPDATE creature SET position_x = '%f', position_y = '%f', position_z = '%f', orientation = '%f' WHERE guid = '%u'", x, y, z, o, lowguid);
    PSendSysMessage(LANG_COMMAND_CREATUREMOVED);
    return true;
}

/**HandleNpcSetMoveTypeCommand
 * Set the movement type for an NPC.<br/>
 * <br/>
 * Valid movement types are:
 * <ul>
 * <li> stay - NPC wont move </li>
 * <li> random - NPC will move randomly according to the spawndist </li>
 * <li> way - NPC will move with given waypoints set </li>
 * </ul>
 * additional parameter: NODEL - so no waypoints are deleted, if you
 *                       change the movement type
 */
bool ChatHandler::HandleNpcSetMoveTypeCommand(const char* args)
{
    if (!*args)
        return false;

    // 3 arguments:
    // GUID (optional - you can also select the creature)
    // stay|random|way (determines the kind of movement)
    // NODEL (optional - tells the system NOT to delete any waypoints)
    //        this is very handy if you want to do waypoints, that are
    //        later switched on/off according to special events (like escort
    //        quests, etc)
    char* guid_str = strtok((char*)args, " ");
    char* type_str = strtok((char*)NULL, " ");
    char* dontdel_str = strtok((char*)NULL, " ");

    bool doNotDelete = false;

    if (!guid_str)
        return false;

    uint32 lowguid = 0;
    Creature* pCreature = NULL;

    if (dontdel_str)
    {
        //sLog.outError("DEBUG: All 3 params are set");

        // All 3 params are set
        // GUID
        // type
        // doNotDEL
        if (stricmp(dontdel_str, "NODEL") == 0)
        {
            //sLog.outError("DEBUG: doNotDelete = true;");
            doNotDelete = true;
        }
    }
    else
    {
        // Only 2 params - but maybe NODEL is set
        if (type_str)
        {
            sLog.outError("DEBUG: Only 2 params ");
            if (stricmp(type_str, "NODEL") == 0)
            {
                //sLog.outError("DEBUG: type_str, NODEL ");
                doNotDelete = true;
                type_str = NULL;
            }
        }
    }

    if (!type_str)                                           // case .setmovetype $move_type (with selected creature)
    {
        type_str = guid_str;
        pCreature = getSelectedCreature();
        if (!pCreature || pCreature->isPet())
            return false;
        lowguid = pCreature->GetDBTableGUIDLow();
    }
    else                                                    // case .setmovetype #creature_guid $move_type (with selected creature)
    {
        lowguid = atoi((char*)guid_str);

        /* impossible without entry
        if (lowguid)
            pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(),MAKE_GUID(lowguid,HIGHGUID_UNIT));
        */

        // attempt check creature existence by DB data
        if (!pCreature)
        {
            CreatureData const* data = objmgr.GetCreatureData(lowguid);
            if (!data)
            {
                PSendSysMessage(LANG_COMMAND_CREATGUIDNOTFOUND, lowguid);
                SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            lowguid = pCreature->GetDBTableGUIDLow();
        }
    }

    // now lowguid is low guid really existed creature
    // and pCreature point (maybe) to this creature or NULL

    MovementGeneratorType move_type;

    std::string type = type_str;

    if (type == "stay")
        move_type = IDLE_MOTION_TYPE;
    else if (type == "random")
        move_type = RANDOM_MOTION_TYPE;
    else if (type == "way")
        move_type = WAYPOINT_MOTION_TYPE;
    else
        return false;

    // update movement type
    //if (doNotDelete == false)
    //    WaypointMgr.DeletePath(lowguid);

    if (pCreature)
    {
        // update movement type
        if (doNotDelete == false)
            pCreature->LoadPath(0);

        pCreature->SetDefaultMovementType(move_type);
        pCreature->GetMotionMaster()->Initialize();
        if (pCreature->isAlive())                            // dead creature will reset movement generator at respawn
        {
            pCreature->setDeathState(JUST_DIED);
            pCreature->Respawn();
        }
        pCreature->SaveToDB();
    }
    if (doNotDelete == false)
    {
        PSendSysMessage(LANG_MOVE_TYPE_SET,type_str);
    }
    else
    {
        PSendSysMessage(LANG_MOVE_TYPE_SET_NODEL,type_str);
    }

    return true;
}

//set model of creature
bool ChatHandler::HandleNpcSetModelCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 displayId = (uint32) atoi((char*)args);

    Creature *pCreature = getSelectedCreature();

    if (!pCreature || pCreature->isPet())
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    pCreature->SetDisplayId(displayId);
    pCreature->SetNativeDisplayId(displayId);

    pCreature->SaveToDB();

    return true;
}
//set faction of creature
bool ChatHandler::HandleNpcFactionIdCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 factionId = (uint32) atoi((char*)args);

    if (!sFactionTemplateStore.LookupEntry(factionId))
    {
        PSendSysMessage(LANG_WRONG_FACTION, factionId);
        SetSentErrorMessage(true);
        return false;
    }

    Creature* pCreature = getSelectedCreature();

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    pCreature->setFaction(factionId);

    // faction is set in creature_template - not inside creature

    // update in memory
    if (CreatureInfo const *cinfo = pCreature->GetCreatureInfo())
    {
        const_cast<CreatureInfo*>(cinfo)->faction_A = factionId;
        const_cast<CreatureInfo*>(cinfo)->faction_H = factionId;
    }

    // and DB
    WorldDatabase.PExecuteLog("UPDATE creature_template SET faction_A = '%u', faction_H = '%u' WHERE entry = '%u'", factionId, factionId, pCreature->GetEntry());

    return true;
}
//set spawn dist of creature
bool ChatHandler::HandleNpcSpawnDistCommand(const char* args)
{
    if (!*args)
        return false;

    float option = atof((char*)args);
    if (option < 0.0f)
    {
        SendSysMessage(LANG_BAD_VALUE);
        return false;
    }

    MovementGeneratorType mtype = IDLE_MOTION_TYPE;
    if (option >0.0f)
        mtype = RANDOM_MOTION_TYPE;

    Creature *pCreature = getSelectedCreature();
    uint32 u_guidlow = 0;

    if (pCreature)
        u_guidlow = pCreature->GetDBTableGUIDLow();
    else
        return false;

    pCreature->SetRespawnRadius((float)option);
    pCreature->SetDefaultMovementType(mtype);
    pCreature->GetMotionMaster()->Initialize();
    if (pCreature->isAlive())                                // dead creature will reset movement generator at respawn
    {
        pCreature->setDeathState(JUST_DIED);
        pCreature->Respawn();
    }

    WorldDatabase.PExecuteLog("UPDATE creature SET spawndist=%f, MovementType=%i WHERE guid=%u",option,mtype,u_guidlow);
    PSendSysMessage(LANG_COMMAND_SPAWNDIST,option);
    return true;
}
//spawn time handling
bool ChatHandler::HandleNpcSpawnTimeCommand(const char* args)
{
    if (!*args)
        return false;

    char* stime = strtok((char*)args, " ");

    if (!stime)
        return false;

    int i_stime = atoi((char*)stime);

    if (i_stime < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Creature *pCreature = getSelectedCreature();
    uint32 u_guidlow = 0;

    if (pCreature)
        u_guidlow = pCreature->GetDBTableGUIDLow();
    else
        return false;

    WorldDatabase.PExecuteLog("UPDATE creature SET spawntimesecs=%i WHERE guid=%u",i_stime,u_guidlow);
    pCreature->SetRespawnDelay((uint32)i_stime);
    PSendSysMessage(LANG_COMMAND_SPAWNTIME,i_stime);

    return true;
}
//npc follow handling
bool ChatHandler::HandleNpcFollowCommand(const char* /*args*/)
{
    Player *player = m_session->GetPlayer();
    Creature *creature = getSelectedCreature();

    if (!creature)
    {
        PSendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // Follow player - Using pet's default dist and angle
    creature->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, creature->GetFollowAngle());

    PSendSysMessage(LANG_CREATURE_FOLLOW_YOU_NOW, creature->GetName());
    return true;
}
//npc unfollow handling
bool ChatHandler::HandleNpcUnFollowCommand(const char* /*args*/)
{
    Player *player = m_session->GetPlayer();
    Creature *creature = getSelectedCreature();

    if (!creature)
    {
        PSendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (/*creature->GetMotionMaster()->empty() ||*/
        creature->GetMotionMaster()->GetCurrentMovementGeneratorType () != TARGETED_MOTION_TYPE)
    {
        PSendSysMessage(LANG_CREATURE_NOT_FOLLOW_YOU, creature->GetName());
        SetSentErrorMessage(true);
        return false;
    }

    TargetedMovementGenerator<Creature> const* mgen
        = static_cast<TargetedMovementGenerator<Creature> const*>((creature->GetMotionMaster()->top()));

    if (mgen->GetTarget() != player)
    {
        PSendSysMessage(LANG_CREATURE_NOT_FOLLOW_YOU, creature->GetName());
        SetSentErrorMessage(true);
        return false;
    }

    // reset movement
    creature->GetMotionMaster()->MovementExpired(true);

    PSendSysMessage(LANG_CREATURE_NOT_FOLLOW_YOU_NOW, creature->GetName());
    return true;
}
//npc tame handling
bool ChatHandler::HandleNpcTameCommand(const char* /*args*/)
{
    Creature *creatureTarget = getSelectedCreature ();
    if (!creatureTarget || creatureTarget->isPet ())
    {
        PSendSysMessage (LANG_SELECT_CREATURE);
        SetSentErrorMessage (true);
        return false;
    }

    Player *player = m_session->GetPlayer ();

    if (player->GetPetGUID ())
    {
        SendSysMessage (LANG_YOU_ALREADY_HAVE_PET);
        SetSentErrorMessage (true);
        return false;
    }

    CreatureInfo const* cInfo = creatureTarget->GetCreatureInfo();

    if (!cInfo->isTameable (player->CanTameExoticPets()))
    {
        PSendSysMessage (LANG_CREATURE_NON_TAMEABLE,cInfo->Entry);
        SetSentErrorMessage (true);
        return false;
    }

    // Everything looks OK, create new pet
    Pet* pet = player->CreateTamedPetFrom (creatureTarget);
    if (!pet)
    {
        PSendSysMessage (LANG_CREATURE_NON_TAMEABLE,cInfo->Entry);
        SetSentErrorMessage (true);
        return false;
    }

    // place pet before player
    float x,y,z;
    player->GetClosePoint (x,y,z,creatureTarget->GetObjectSize (),CONTACT_DISTANCE);
    pet->Relocate (x,y,z,M_PI-player->GetOrientation ());

    // set pet to defensive mode by default (some classes can't control controlled pets in fact).
    pet->SetReactState(REACT_DEFENSIVE);

    // calculate proper level
    uint8 level = (creatureTarget->getLevel() < (player->getLevel() - 5)) ? (player->getLevel() - 5) : creatureTarget->getLevel();

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);

    // add to world
    pet->GetMap()->Add(pet->ToCreature());

    // visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

    // caster have pet now
    player->SetMinion(pet, true);

    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
    player->PetSpellInitialize();

    return true;
}
//npc phasemask handling
//change phasemask of creature or pet
bool ChatHandler::HandleNpcSetPhaseCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 phasemask = (uint32) atoi((char*)args);
    if (phasemask == 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Creature* pCreature = getSelectedCreature();
    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    pCreature->SetPhaseMask(phasemask,true);

    if (!pCreature->isPet())
        pCreature->SaveToDB();

    return true;
}
//npc deathstate handling
bool ChatHandler::HandleNpcSetDeathStateCommand(const char* args)
{
    if (!*args)
        return false;

    Creature* pCreature = getSelectedCreature();
    if (!pCreature || pCreature->isPet())
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (strncmp(args, "on", 3) == 0)
        pCreature->SetDeadByDefault(true);
    else if (strncmp(args, "off", 4) == 0)
        pCreature->SetDeadByDefault(false);
    else
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    pCreature->SaveToDB();
    pCreature->Respawn();

    return true;
}

//TODO: NpcCommands that need to be fixed :

bool ChatHandler::HandleNpcNameCommand(const char* /*args*/)
{
    /* Temp. disabled
    if (!*args)
        return false;

    if (strlen((char*)args)>75)
    {
        PSendSysMessage(LANG_TOO_LONG_NAME, strlen((char*)args)-75);
        return true;
    }

    for (uint8 i = 0; i < strlen(args); ++i)
    {
        if (!isalpha(args[i]) && args[i] != ' ')
        {
            SendSysMessage(LANG_CHARS_ONLY);
            return false;
        }
    }

    uint64 guid;
    guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
        SendSysMessage(LANG_NO_SELECTION);
        return true;
    }

    Creature* pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(), guid);

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        return true;
    }

    pCreature->SetName(args);
    uint32 idname = objmgr.AddCreatureTemplate(pCreature->GetName());
    pCreature->SetUInt32Value(OBJECT_FIELD_ENTRY, idname);

    pCreature->SaveToDB();
    */

    return true;
}

bool ChatHandler::HandleNpcSubNameCommand(const char* /*args*/)
{
    /* Temp. disabled

    if (!*args)
        args = "";

    if (strlen((char*)args)>75)
    {

        PSendSysMessage(LANG_TOO_LONG_SUBNAME, strlen((char*)args)-75);
        return true;
    }

    for (uint8 i = 0; i < strlen(args); i++)
    {
        if (!isalpha(args[i]) && args[i] != ' ')
        {
            SendSysMessage(LANG_CHARS_ONLY);
            return false;
        }
    }
    uint64 guid;
    guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
        SendSysMessage(LANG_NO_SELECTION);
        return true;
    }

    Creature* pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(), guid);

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        return true;
    }

    uint32 idname = objmgr.AddCreatureSubName(pCreature->GetName(),args,pCreature->GetUInt32Value(UNIT_FIELD_DISPLAYID));
    pCreature->SetUInt32Value(OBJECT_FIELD_ENTRY, idname);

    pCreature->SaveToDB();
    */
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

    if (!m_session->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0,srcslot))
        return false;

    if (!m_session->GetPlayer()->IsValidPos(INVENTORY_SLOT_BAG_0,dstslot))
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

//morph creature or player
bool ChatHandler::HandleModifyMorphCommand(const char* args)
{
    if (!*args)
        return false;

    uint16 display_id = (uint16)atoi((char*)args);

    Unit *target = getSelectedUnit();
    if (!target)
        target = m_session->GetPlayer();

    // check online security
    else if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target, 0))
        return false;

    target->SetDisplayId(display_id);

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

        if (sWorld.getConfig(CONFIG_SHOW_KICK_IN_WORLD) == 1)
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

        Player* player = objmgr.GetPlayer(kickName);
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
            if (sWorld.getConfig(CONFIG_SHOW_KICK_IN_WORLD) == 1)
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

//set temporary phase mask for player
bool ChatHandler::HandleModifyPhaseCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 phasemask = (uint32)atoi((char*)args);

    Unit *target = getSelectedUnit();
    if (!target)
        target = m_session->GetPlayer();

    // check online security
    else if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target, 0))
        return false;

    target->SetPhaseMask(phasemask,true);

    return true;
}
//show info of gameobject
bool ChatHandler::HandleGOInfoCommand(const char* args)
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

    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);

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
        QueryResult_AutoPtr result = CharacterDatabase.PQuery("SELECT totaltime, level, money, account, race, class FROM characters WHERE guid = '%u'", GUID_LOPART(target_guid));
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

    QueryResult_AutoPtr result = LoginDatabase.PQuery("SELECT a.username,aa.gmlevel,a.email,a.last_ip,a.last_login "
                                                "FROM account a "
                                                "LEFT JOIN account_access aa "
                                                "ON (a.id = aa.id) "
                                                "WHERE a.id = '%u'",accId);
    if (result)
    {
        Field* fields = result->Fetch();
        username = fields[0].GetCppString();
        security = fields[1].GetUInt32();
        email = fields[2].GetCppString();

        if (email.empty())
            email = "-";

        if (!m_session || m_session->GetSecurity() >= security)
        {
            last_ip = fields[3].GetCppString();
            last_login = fields[4].GetCppString();
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
            QueryResult_AutoPtr result = WorldDatabase.Query("SELECT MAX(id) FROM waypoint_data");
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

    QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT MAX(point) FROM waypoint_data WHERE id = '%u'",pathid);

    if (result)
        point = (*result)[0].GetUInt32();

    Player* player = m_session->GetPlayer();
    //Map *map = player->GetMap();

    WorldDatabase.PExecuteLog("INSERT INTO waypoint_data (id, point, position_x, position_y, position_z) VALUES ('%u','%u','%f', '%f', '%f')",
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
    QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT guid FROM creature_addon WHERE guid = '%u'",guidlow);

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
            QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT id FROM waypoint_scripts WHERE guid = %u", id);

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
            QueryResult_AutoPtr result = WorldDatabase.Query("SELECT MAX(guid) FROM waypoint_scripts");
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

        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT guid, delay, command, datalong, datalong2, dataint, x, y, z, o FROM waypoint_scripts WHERE id = %u", id);

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
            a7 = fields[5].GetString();
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

        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT guid FROM waypoint_scripts WHERE guid = %u", id);

        if (result)
        {
           WorldDatabase.PExecuteLog("DELETE FROM waypoint_scripts WHERE guid = %u", id);
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
            WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET id='%u' WHERE guid='%u'",
            newid, id); return true;
        }
        else
        {
            QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT id FROM waypoint_scripts WHERE guid='%u'",id);

            if (!result)
            {
                SendSysMessage("|cffff33ffERROR: You have selected an non existing waypoint script guid.|r");
                return true;
            }

            if (arg_str_2 == "posx")
            {
                coord = atof(arg_3);
                WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET x='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script:|r|cff00ffff %u|r|cff00ff00 position_x updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "posy")
            {
                coord = atof(arg_3);
                WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET y='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: %u position_y updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "posz")
            {
                coord = atof(arg_3);
                WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET z='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 position_z updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "orientation")
            {
                coord = atof(arg_3);
                WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET o='%f' WHERE guid='%u'",
                    coord, id);
                PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 orientation updated.|r", id);
                return true;
            }
            else if (arg_str_2 == "dataint")
            {
                    WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET %s='%u' WHERE guid='%u'",
                    arg_2, atoi(arg_3), id);
                    PSendSysMessage("|cff00ff00Waypoint script: |r|cff00ffff%u|r|cff00ff00 dataint updated.|r", id);
                    return true;
            }
            else
            {
                    std::string arg_str_3 = arg_3;
                    WorldDatabase.escape_string(arg_str_3);
                    WorldDatabase.PExecuteLog("UPDATE waypoint_scripts SET %s='%s' WHERE guid='%u'",
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
        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT id, point FROM waypoint_data WHERE wpguid = %u", wpGuid);

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

        WorldDatabase.PExecuteLog("DELETE FROM waypoint_data WHERE id='%u' AND point='%u'",
            pathid, point);
        WorldDatabase.PExecuteLog("UPDATE waypoint_data SET point=point-1 WHERE id='%u' AND point>'%u'",
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
                if (!wpCreature2->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), VISUAL_WAYPOINT, 0, 0, chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ(), chr->GetOrientation()))
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

            WorldDatabase.PExecuteLog("UPDATE waypoint_data SET position_x = '%f',position_y = '%f',position_z = '%f' where id = '%u' AND point='%u'",
                chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ(), pathid, point);

            PSendSysMessage(LANG_WAYPOINT_CHANGED);
        }
        return true;
    }                                                       // move

    const char *text = arg_str;

    if (text == 0)
    {
        // show_str check for present in list of correct values, no sql injection possible
        WorldDatabase.PExecuteLog("UPDATE waypoint_data SET %s=NULL WHERE id='%u' AND point='%u'",
            show_str, pathid, point);
    }
    else
    {
        // show_str check for present in list of correct values, no sql injection possible
        std::string text2 = text;
        WorldDatabase.escape_string(text2);
        WorldDatabase.PExecuteLog("UPDATE waypoint_data SET %s='%s' WHERE id='%u' AND point='%u'",
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

        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT id, point, delay, move_flag, action, action_chance FROM waypoint_data WHERE wpguid = %u", target->GetGUIDLow());

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
        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT point, position_x,position_y,position_z FROM waypoint_data WHERE id = '%u'", pathid);

        if (!result)
        {
            SendSysMessage("|cffff33ffPath no found.|r");
            SetSentErrorMessage(true);
            return false;
        }

        PSendSysMessage("|cff00ff00DEBUG: wp on, PathID: |cff00ffff%u|r", pathid);

        // Delete all visuals for this NPC
        QueryResult_AutoPtr result2 = WorldDatabase.PQuery("SELECT wpguid FROM waypoint_data WHERE id = '%u' and wpguid <> 0", pathid);

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
                    WorldDatabase.PExecuteLog("DELETE FROM creature WHERE guid = '%u'", wpguid);
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
            if (!wpCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
            {
                PSendSysMessage(LANG_WAYPOINT_VP_NOTCREATED, id);
                delete wpCreature;
                return false;
            }

            sLog.outDebug("DEBUG: UPDATE waypoint_data SET wpguid = '%u");
            // set "wpguid" column to the visual waypoint
            WorldDatabase.PExecuteLog("UPDATE waypoint_data SET wpguid = '%u' WHERE id = '%u' and point = '%u'", wpCreature->GetGUIDLow(), pathid, point);

            wpCreature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());
            // To call _LoadGoods(); _LoadQuests(); CreateTrainerSpells();
            wpCreature->LoadFromDB(wpCreature->GetDBTableGUIDLow(),map);
            map->Add(wpCreature);

            if (target)
            {
                wpCreature->SetDisplayId(target->GetDisplayId());
                wpCreature->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5);
                wpCreature->SetLevel(point > MAX_LEVEL ? MAX_LEVEL : point);
            }
        }
        while (result->NextRow());

        SendSysMessage("|cff00ff00Showing the current creature's path.|r");
        return true;
    }

    if (show == "first")
    {
        PSendSysMessage("|cff00ff00DEBUG: wp first, GUID: %u|r", pathid);

        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT position_x,position_y,position_z FROM waypoint_data WHERE point='1' AND id = '%u'",pathid);
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
        if (!pCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT),map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
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

        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT MAX(point) FROM waypoint_data WHERE id = '%u'",pathid);
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
        if (!pCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), map, chr->GetPhaseMaskForSpawn(), id, 0, 0, x, y, z, o))
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
        QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT guid FROM creature WHERE id = '%u'", 1);
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
                WorldDatabase.PExecuteLog("DELETE FROM creature WHERE guid = '%u'", guid);
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
        WorldDatabase.PExecuteLog("UPDATE waypoint_data SET wpguid = '0'");
        //WorldDatabase.PExecuteLog("UPDATE creature_movement SET wpguid = '0' WHERE wpguid <> '0'");

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

//change standstate
bool ChatHandler::HandleModifyStandStateCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 anim_id = atoi((char*)args);
    m_session->GetPlayer()->SetUInt32Value(UNIT_NPC_EMOTESTATE , anim_id);

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

    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();
    GameEventMgr::ActiveEvents const& activeEvents = gameeventmgr.GetActiveEventList();

    for (uint32 id = 0; id < events.size(); ++id)
    {
        GameEventData const& eventData = events[id];

        std::string descr = eventData.description;
        if (descr.empty())
            continue;

        if (Utf8FitTo(descr, wnamepart))
        {
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

bool ChatHandler::HandleEventActiveListCommand(const char* /*args*/)
{
    uint32 counter = 0;

    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();
    GameEventMgr::ActiveEvents const& activeEvents = gameeventmgr.GetActiveEventList();

    char const* active = GetTrinityString(LANG_ACTIVE);

    for (GameEventMgr::ActiveEvents::const_iterator itr = activeEvents.begin(); itr != activeEvents.end(); ++itr)
    {
        uint32 event_id = *itr;
        GameEventData const& eventData = events[event_id];

        if (m_session)
            PSendSysMessage(LANG_EVENT_ENTRY_LIST_CHAT,event_id,event_id,eventData.description.c_str(),active);
        else
            PSendSysMessage(LANG_EVENT_ENTRY_LIST_CONSOLE,event_id,eventData.description.c_str(),active);

        ++counter;
    }

    if (counter == 0)
        SendSysMessage(LANG_NOEVENTFOUND);

    return true;
}

bool ChatHandler::HandleEventInfoCommand(const char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameevent");
    if (!cId)
        return false;

    uint32 event_id = atoi(cId);

    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();

    if (event_id >=events.size())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventMgr::ActiveEvents const& activeEvents = gameeventmgr.GetActiveEventList();
    bool active = activeEvents.find(event_id) != activeEvents.end();
    char const* activeStr = active ? GetTrinityString(LANG_ACTIVE) : "";

    std::string startTimeStr = TimeToTimestampStr(eventData.start);
    std::string endTimeStr = TimeToTimestampStr(eventData.end);

    uint32 delay = gameeventmgr.NextCheck(event_id);
    time_t nextTime = time(NULL)+delay;
    std::string nextStr = nextTime >= eventData.start && nextTime < eventData.end ? TimeToTimestampStr(time(NULL)+delay) : "-";

    std::string occurenceStr = secsToTimeString(eventData.occurence * MINUTE);
    std::string lengthStr = secsToTimeString(eventData.length * MINUTE);

    PSendSysMessage(LANG_EVENT_INFO,event_id,eventData.description.c_str(),activeStr,
        startTimeStr.c_str(),endTimeStr.c_str(),occurenceStr.c_str(),lengthStr.c_str(),
        nextStr.c_str());
    return true;
}

bool ChatHandler::HandleEventStartCommand(const char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameevent");
    if (!cId)
        return false;

    int32 event_id = atoi(cId);

    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();

    if (event_id < 1 || event_id >=events.size())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventMgr::ActiveEvents const& activeEvents = gameeventmgr.GetActiveEventList();
    if (activeEvents.find(event_id) != activeEvents.end())
    {
        PSendSysMessage(LANG_EVENT_ALREADY_ACTIVE,event_id);
        SetSentErrorMessage(true);
        return false;
    }

    gameeventmgr.StartEvent(event_id,true);
    return true;
}

bool ChatHandler::HandleEventStopCommand(const char* args)
{
    if (!*args)
        return false;

    // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameevent");
    if (!cId)
        return false;

    int32 event_id = atoi(cId);

    GameEventMgr::GameEventDataMap const& events = gameeventmgr.GetEventMap();

    if (event_id < 1 || event_id >=events.size())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventData const& eventData = events[event_id];
    if (!eventData.isValid())
    {
        SendSysMessage(LANG_EVENT_NOT_EXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameEventMgr::ActiveEvents const& activeEvents = gameeventmgr.GetActiveEventList();

    if (activeEvents.find(event_id) == activeEvents.end())
    {
        PSendSysMessage(LANG_EVENT_NOT_ACTIVE,event_id);
        SetSentErrorMessage(true);
        return false;
    }

    gameeventmgr.StopEvent(event_id,true);
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

void ChatHandler::HandleLearnSkillRecipesHelper(Player* player,uint32 skill_id)
{
    uint32 classmask = player->getClassMask();

    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->spellId);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,player,false))
            continue;

        player->learnSpell(skillLine->spellId, false);
    }
}

bool ChatHandler::HandleLearnAllCraftsCommand(const char* /*args*/)
{

    for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
    {
        SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(i);
        if (!skillInfo)
            continue;

        if ((skillInfo->categoryId == SKILL_CATEGORY_PROFESSION || skillInfo->categoryId == SKILL_CATEGORY_SECONDARY) &&
            skillInfo->canLink)                             // only prof. with recipes have
        {
            HandleLearnSkillRecipesHelper(m_session->GetPlayer(),skillInfo->id);
        }
    }

    SendSysMessage(LANG_COMMAND_LEARN_ALL_CRAFT);
    return true;
}

bool ChatHandler::HandleLearnAllRecipesCommand(const char* args)
{
    //  Learns all recipes of specified profession and sets skill to max
    //  Example: .learn all_recipes enchanting

    Player* target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        return false;
    }

    if (!*args)
        return false;

    std::wstring wnamepart;

    if (!Utf8toWStr(args,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    std::string name;

    SkillLineEntry const *targetSkillInfo = NULL;
    for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
    {
        SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(i);
        if (!skillInfo)
            continue;

        if ((skillInfo->categoryId != SKILL_CATEGORY_PROFESSION &&
            skillInfo->categoryId != SKILL_CATEGORY_SECONDARY) ||
            !skillInfo->canLink)                            // only prof with recipes have set
            continue;

        int loc = GetSessionDbcLocale();
        name = skillInfo->name[loc];
        if (name.empty())
            continue;

        if (!Utf8FitTo(name, wnamepart))
        {
            loc = 0;
            for (; loc < MAX_LOCALE; ++loc)
            {
                if (loc == GetSessionDbcLocale())
                    continue;

                name = skillInfo->name[loc];
                if (name.empty())
                    continue;

                if (Utf8FitTo(name, wnamepart))
                    break;
            }
        }

        if (loc < MAX_LOCALE)
        {
            targetSkillInfo = skillInfo;
            break;
        }
    }

    if (!targetSkillInfo)
        return false;

    HandleLearnSkillRecipesHelper(target,targetSkillInfo->id);

    uint16 maxLevel = target->GetPureMaxSkillValue(targetSkillInfo->id);
    target->SetSkill(targetSkillInfo->id, target->GetSkillStep(targetSkillInfo->id), maxLevel, maxLevel);
    PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, name.c_str());
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

    QueryResult_AutoPtr result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE last_ip = '%s'", ip.c_str ());

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

    QueryResult_AutoPtr result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE username = '%s'", account.c_str ());

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

    QueryResult_AutoPtr result = LoginDatabase.PQuery ("SELECT id,username FROM account WHERE email = '%s'", email.c_str ());

    return LookupPlayerSearchCommand (result,limit);
}

bool ChatHandler::LookupPlayerSearchCommand(QueryResult_AutoPtr result, int32 limit)
{
    if (!result)
    {
        PSendSysMessage(LANG_NO_PLAYERS_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    int i =0;
    do
    {
        Field* fields = result->Fetch();
        uint32 acc_id = fields[0].GetUInt32();
        std::string acc_name = fields[1].GetCppString();

        QueryResult_AutoPtr chars = CharacterDatabase.PQuery("SELECT guid,name FROM characters WHERE account = '%u'", acc_id);
        if (chars)
        {
            PSendSysMessage(LANG_LOOKUP_PLAYER_ACCOUNT,acc_name.c_str(),acc_id);

            uint64 guid = 0;
            std::string name;

            do
            {
                Field* charfields = chars->Fetch();
                guid = charfields[0].GetUInt64();
                name = charfields[1].GetCppString();

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
    CorpsesErase();
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

    CreatureInfo const* cInfo = objmgr.GetCreatureTemplate(creatureTarget->GetEntry());
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
        sLog.outError("ERROR: InitStatsForLevel() in EffectTameCreature failed! Pet deleted.");
        PSendSysMessage("Error 2");
        delete pet;
        return false;
    }

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL,creatureTarget->getLevel()-1);

     pet->GetCharmInfo()->SetPetNumber(objmgr.GeneratePetNumber(), true);
     // this enables pet details window (Shift+P)
     pet->InitPetCreateSpells();
     pet->SetHealth(pet->GetMaxHealth());

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
    if (GameObjectData const* go_data = objmgr.GetGOData(lowguid))
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

// add creature, temp only
bool ChatHandler::HandleTempAddSpwCommand(const char* args)
{
    if (!*args)
        return false;
    char* charID = strtok((char*)args, " ");
    if (!charID)
        return false;

    Player *chr = m_session->GetPlayer();

    uint32 id = atoi(charID);
    if (!id)
        return false;

    chr->SummonCreature(id, *chr, TEMPSUMMON_CORPSE_DESPAWN, 120);

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

bool ChatHandler::HandleNpcAddFormationCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 leaderGUID = (uint32) atoi((char*)args);
    Creature *pCreature = getSelectedCreature();

    if (!pCreature || !pCreature->GetDBTableGUIDLow())
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 lowguid = pCreature->GetDBTableGUIDLow();
    if (pCreature->GetFormation())
    {
        PSendSysMessage("Selected creature is already member of group %u", pCreature->GetFormation()->GetId());
        return false;
    }

    if (!lowguid)
        return false;

    Player *chr = m_session->GetPlayer();
    FormationInfo *group_member;

    group_member                 = new FormationInfo;
    group_member->follow_angle   = (pCreature->GetAngle(chr) - chr->GetOrientation()) * 180 / M_PI;
    group_member->follow_dist    = sqrtf(pow(chr->GetPositionX() - pCreature->GetPositionX(),int(2))+pow(chr->GetPositionY()-pCreature->GetPositionY(),int(2)));
    group_member->leaderGUID     = leaderGUID;
    group_member->groupAI        = 0;

    CreatureGroupMap[lowguid] = group_member;
    pCreature->SearchFormation();

    WorldDatabase.PExecuteLog("INSERT INTO creature_formations (leaderGUID, memberGUID, dist, angle, groupAI) VALUES ('%u','%u','%f', '%f', '%u')",
        leaderGUID, lowguid, group_member->follow_dist, group_member->follow_angle, group_member->groupAI);

    PSendSysMessage("Creature %u added to formation with leader %u", lowguid, leaderGUID);

    return true;
 }

bool ChatHandler::HandleNpcSetLinkCommand(const char* args)
{
    if (!*args)
        return false;

    uint32 linkguid = (uint32) atoi((char*)args);

    Creature* pCreature = getSelectedCreature();

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!pCreature->GetDBTableGUIDLow())
    {
        PSendSysMessage("Selected creature isn't in creature table", pCreature->GetGUIDLow());
        SetSentErrorMessage(true);
        return false;
    }

    if (!objmgr.SetCreatureLinkedRespawn(pCreature->GetDBTableGUIDLow(), linkguid))
    {
        PSendSysMessage("Selected creature can't link with guid '%u'", linkguid);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("LinkGUID '%u' added to creature with DBTableGUID: '%u'", linkguid, pCreature->GetDBTableGUIDLow());
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
                for (; loc < MAX_LOCALE; ++loc)
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

            if (loc < MAX_LOCALE)
            {
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
