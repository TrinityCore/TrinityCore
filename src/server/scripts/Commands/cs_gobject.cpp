/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
Name: gobject_commandscript
%Complete: 100
Comment: All gobject related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "PoolMgr.h"
#include "MapManager.h"
#include "Chat.h"

class gobject_commandscript : public CommandScript
{
public:
    gobject_commandscript() : CommandScript("gobject_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand gobjectAddCommandTable[] =
        {
            { "temp",           SEC_GAMEMASTER,     false, &HandleGameObjectAddTempCommand,   "", NULL },
            { "",               SEC_GAMEMASTER,     false, &HandleGameObjectAddCommand,       "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand gobjectSetCommandTable[] =
        {
            { "phase",          SEC_GAMEMASTER,     false, &HandleGameObjectSetPhaseCommand,  "", NULL },
            { "state",          SEC_GAMEMASTER,     false, &HandleGameObjectSetStateCommand,  "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand gobjectCommandTable[] =
        {
            { "activate",       SEC_GAMEMASTER,     false, &HandleGameObjectActivateCommand,  "", NULL },
            { "delete",         SEC_GAMEMASTER,     false, &HandleGameObjectDeleteCommand,    "", NULL },
            { "info",           SEC_GAMEMASTER,     false, &HandleGameObjectInfoCommand,      "", NULL },
            { "move",           SEC_GAMEMASTER,     false, &HandleGameObjectMoveCommand,      "", NULL },
            { "near",           SEC_GAMEMASTER,     false, &HandleGameObjectNearCommand,      "", NULL },
            { "target",         SEC_GAMEMASTER,     false, &HandleGameObjectTargetCommand,    "", NULL },
            { "turn",           SEC_GAMEMASTER,     false, &HandleGameObjectTurnCommand,      "", NULL },
            { "add",            SEC_GAMEMASTER,     false, NULL,            "", gobjectAddCommandTable },
            { "set",            SEC_GAMEMASTER,     false, NULL,            "", gobjectSetCommandTable },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "gobject",        SEC_GAMEMASTER,     false, NULL,                "", gobjectCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleGameObjectActivateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* obj = NULL;

        // by DB guid
        if (GameObjectData const* go_data = sObjectMgr->GetGOData(lowguid))
            obj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

        if (!obj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Activate
        obj->SetLootState(GO_READY);
        obj->UseDoorOrButton(10000);

        handler->PSendSysMessage("Object activated!");

        return true;
    }

    //spawn go
    static bool HandleGameObjectAddCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject_entry");
        if (!cId)
            return false;

        uint32 id = atol(cId);
        if (!id)
            return false;

        char* spawntimeSecs = strtok(NULL, " ");

        const GameObjectInfo *gInfo = ObjectMgr::GetGameObjectInfo(id);

        if (!gInfo)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (gInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(gInfo->displayId))
        {
            // report to DB errors log as in loading case
            sLog->outErrorDb("Gameobject (Entry %u GoType: %u) have invalid displayId (%u), not spawned.",id, gInfo->type, gInfo->displayId);
            handler->PSendSysMessage(LANG_GAMEOBJECT_HAVE_INVALID_DATA,id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->GetSession()->GetPlayer();
        float x = float(chr->GetPositionX());
        float y = float(chr->GetPositionY());
        float z = float(chr->GetPositionZ());
        float o = float(chr->GetOrientation());
        Map *map = chr->GetMap();

        GameObject* pGameObj = new GameObject;
        uint32 db_lowGUID = sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT);

        if (!pGameObj->Create(db_lowGUID, gInfo->id, map, chr->GetPhaseMaskForSpawn(), x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
        {
            delete pGameObj;
            return false;
        }

        if (spawntimeSecs)
        {
            uint32 value = atoi((char*)spawntimeSecs);
            pGameObj->SetRespawnTime(value);
            //sLog->outDebug(LOG_FILTER_TSCR, "*** spawntimeSecs: %d", value);
        }

        // fill the gameobject data and save to the db
        pGameObj->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()),chr->GetPhaseMaskForSpawn());

        // this will generate a new guid if the object is in an instance
        if (!pGameObj->LoadFromDB(db_lowGUID, map))
        {
            delete pGameObj;
            return false;
        }

        map->Add(pGameObj);

        // TODO: is it really necessary to add both the real and DB table guid here ?
        sObjectMgr->AddGameobjectToGrid(db_lowGUID, sObjectMgr->GetGOData(db_lowGUID));

        handler->PSendSysMessage(LANG_GAMEOBJECT_ADD,id,gInfo->name,db_lowGUID,x,y,z);
        return true;
    }

    // add go, temp only
    static bool HandleGameObjectAddTempCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;
        char* charID = strtok((char*)args, " ");
        if (!charID)
            return false;

        Player *chr = handler->GetSession()->GetPlayer();

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

    static bool HandleGameObjectTargetCommand(ChatHandler* handler, const char* args)
    {
        Player* pl = handler->GetSession()->GetPlayer();
        QueryResult result;
        GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr->GetActiveEventList();
        if (*args)
        {
            // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
            char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject_entry");
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
                    eventFilter  <<  "OR eventEntry IN (" <<*itr;
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
                "LEFT OUTER JOIN game_event_gameobject on gameobject.guid = game_event_gameobject.guid WHERE map = '%i' %s ORDER BY order_ ASC LIMIT 10",
                handler->GetSession()->GetPlayer()->GetPositionX(), handler->GetSession()->GetPlayer()->GetPositionY(), handler->GetSession()->GetPlayer()->GetPositionZ(),
                handler->GetSession()->GetPlayer()->GetMapId(),eventFilter.str().c_str());
        }

        if (!result)
        {
            handler->SendSysMessage(LANG_COMMAND_TARGETOBJNOTFOUND);
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
            pool_id = sPoolMgr->IsPartOfAPool<GameObject>(lowguid);
            if (!pool_id || sPoolMgr->IsSpawnedObject<GameObject>(lowguid))
                found = true;
        } while (result->NextRow() && (!found));

        if (!found)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
            return false;
        }

        GameObjectInfo const* goI = ObjectMgr::GetGameObjectInfo(id);

        if (!goI)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST,id);
            return false;
        }

        GameObject* target = handler->GetSession()->GetPlayer()->GetMap()->GetGameObject(MAKE_NEW_GUID(lowguid,id,HIGHGUID_GAMEOBJECT));

        handler->PSendSysMessage(LANG_GAMEOBJECT_DETAIL, lowguid, goI->name, lowguid, id, x, y, z, mapid, o, phase);

        if (target)
        {
            int32 curRespawnDelay = int32(target->GetRespawnTimeEx()-time(NULL));
            if (curRespawnDelay < 0)
                curRespawnDelay = 0;

            std::string curRespawnDelayStr = secsToTimeString(curRespawnDelay,true);
            std::string defRespawnDelayStr = secsToTimeString(target->GetRespawnDelay(),true);

            handler->PSendSysMessage(LANG_COMMAND_RAWPAWNTIMES, defRespawnDelayStr.c_str(),curRespawnDelayStr.c_str());
        }
        return true;
    }

    //delete object by selection or guid
    static bool HandleGameObjectDeleteCommand(ChatHandler* handler, const char* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* obj = NULL;

        // by DB guid
        if (GameObjectData const* go_data = sObjectMgr->GetGOData(lowguid))
            obj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

        if (!obj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint64 owner_guid = obj->GetOwnerGUID();
        if (owner_guid)
        {
            Unit* owner = ObjectAccessor::GetUnit(*handler->GetSession()->GetPlayer(),owner_guid);
            if (!owner || !IS_PLAYER_GUID(owner_guid))
            {
                handler->PSendSysMessage(LANG_COMMAND_DELOBJREFERCREATURE, GUID_LOPART(owner_guid), obj->GetGUIDLow());
                handler->SetSentErrorMessage(true);
                return false;
            }

            owner->RemoveGameObject(obj,false);
        }

        obj->SetRespawnTime(0);                                 // not save respawn time
        obj->Delete();
        obj->DeleteFromDB();

        handler->PSendSysMessage(LANG_COMMAND_DELOBJMESSAGE, obj->GetGUIDLow());

        return true;
    }

    //turn selected object
    static bool HandleGameObjectTurnCommand(ChatHandler* handler, const char* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* obj = NULL;

        // by DB guid
        if (GameObjectData const* go_data = sObjectMgr->GetGOData(lowguid))
            obj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

        if (!obj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
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
            Player *chr = handler->GetSession()->GetPlayer();
            o = chr->GetOrientation();
        }

        obj->Relocate(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), o);
        obj->UpdateRotationFields();
        obj->DestroyForNearbyPlayers();
        obj->UpdateObjectVisibility();

        obj->SaveToDB();
        obj->Refresh();

        handler->PSendSysMessage(LANG_COMMAND_TURNOBJMESSAGE, obj->GetGUIDLow(), obj->GetGOInfo()->name, obj->GetGUIDLow(), o);

        return true;
    }

    //move selected object
    static bool HandleGameObjectMoveCommand(ChatHandler* handler, const char* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* obj = NULL;

        // by DB guid
        if (GameObjectData const* go_data = sObjectMgr->GetGOData(lowguid))
            obj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

        if (!obj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* px = strtok(NULL, " ");
        char* py = strtok(NULL, " ");
        char* pz = strtok(NULL, " ");

        if (!px)
        {
            Player *chr = handler->GetSession()->GetPlayer();
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
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD,x,y,obj->GetMapId());
                handler->SetSentErrorMessage(true);
                return false;
            }

            obj->Relocate(x, y, z, obj->GetOrientation());
            obj->DestroyForNearbyPlayers();
            obj->UpdateObjectVisibility();
        }

        obj->SaveToDB();
        obj->Refresh();

        handler->PSendSysMessage(LANG_COMMAND_MOVEOBJMESSAGE, obj->GetGUIDLow(), obj->GetGOInfo()->name, obj->GetGUIDLow());

        return true;
    }

    //set pahsemask for selected object
    static bool HandleGameObjectSetPhaseCommand(ChatHandler* handler, const char* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args,"Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* obj = NULL;

        // by DB guid
        if (GameObjectData const* go_data = sObjectMgr->GetGOData(lowguid))
            obj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid,go_data->id);

        if (!obj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* phaseStr = strtok (NULL, " ");
        uint32 phasemask = phaseStr? atoi(phaseStr) : 0;
        if (phasemask == 0)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        obj->SetPhaseMask(phasemask,true);
        obj->SaveToDB();
        return true;
    }

    static bool HandleGameObjectNearCommand(ChatHandler* handler, const char* args)
    {
        float distance = (!*args) ? 10.0f : (float)(atof(args));
        uint32 count = 0;

        Player* pl = handler->GetSession()->GetPlayer();
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
                uint16 mapid = fields[5].GetUInt16();

                GameObjectInfo const * gInfo = ObjectMgr::GetGameObjectInfo(entry);

                if (!gInfo)
                    continue;

                handler->PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gInfo->name, x, y, z, mapid);

                ++count;
            } while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_NEAROBJMESSAGE,distance,count);
        return true;
    }

    //show info of gameobject
    static bool HandleGameObjectInfoCommand(ChatHandler* handler, const char* args)
    {
        uint32 entry = 0;
        uint32 type = 0;
        uint32 displayid = 0;
        std::string name;
        uint32 lootId = 0;

        if (!*args)
        {
            if (WorldObject * obj = handler->getSelectedObject())
                entry = obj->GetEntry();
            else
                entry = atoi((char*)args);
        }

        GameObjectInfo const* goinfo = ObjectMgr::GetGameObjectInfo(entry);

        if (!goinfo)
            return false;

        type = goinfo->type;
        displayid = goinfo->displayId;
        name = goinfo->name;
        if (type == GAMEOBJECT_TYPE_CHEST)
            lootId = goinfo->chest.lootId;
        else if (type == GAMEOBJECT_TYPE_FISHINGHOLE)
            lootId = goinfo->fishinghole.lootId;

        handler->PSendSysMessage(LANG_GOINFO_ENTRY, entry);
        handler->PSendSysMessage(LANG_GOINFO_TYPE, type);
        handler->PSendSysMessage(LANG_GOINFO_LOOTID, lootId);
        handler->PSendSysMessage(LANG_GOINFO_DISPLAYID, displayid);
        handler->PSendSysMessage(LANG_GOINFO_NAME, name.c_str());

        return true;
    }

    static bool HandleGameObjectSetStateCommand(ChatHandler* handler, const char* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!cId)
            return false;

        uint32 lowguid = atoi(cId);
        if (!lowguid)
            return false;

        GameObject* gobj = NULL;

        if (GameObjectData const* goData = sObjectMgr->GetGOData(lowguid))
            gobj = handler->GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid, goData->id);

        if (!gobj)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* ctype = strtok(NULL, " ");
        if (!ctype)
            return false;

        int32 type = atoi(ctype);
        if (type < 0)
        {
            if (type == -1)
                gobj->SendObjectDeSpawnAnim(gobj->GetGUID());
            else if (type == -2)
            {
                return false;
            }
            return true;
        }

        char* cstate = strtok(NULL, " ");
        if (!cstate)
            return false;

        int32 state = atoi(cstate);

        if (type < 4)
            gobj->SetByteValue(GAMEOBJECT_BYTES_1, type, state);
        else if (type == 4)
        {
            WorldPacket data(SMSG_GAMEOBJECT_CUSTOM_ANIM,8+4);
            data << gobj->GetGUID();
            data << (uint32)(state);
            gobj->SendMessageToSet(&data, true);
        }
        handler->PSendSysMessage("Set gobject type %d state %d", type, state);
        return true;
    }
};

void AddSC_gobject_commandscript()
{
    new gobject_commandscript();
}
