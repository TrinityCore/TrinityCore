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

/* ScriptData
Name: gobject_commandscript
%Complete: 100
Comment: All gobject related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "PoolMgr.h"
#include "RBAC.h"
#include "WorldSession.h"
#include <boost/core/demangle.hpp>
#include <sstream>
#include <typeinfo>

// definitions are over in cs_npc.cpp
bool HandleNpcSpawnGroup(ChatHandler* handler, char const* args);
bool HandleNpcDespawnGroup(ChatHandler* handler, char const* args);

using namespace Trinity::ChatCommands;
class gobject_commandscript : public CommandScript
{
public:
    gobject_commandscript() : CommandScript("gobject_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> gobjectAddCommandTable =
        {
            { "temp", rbac::RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP, false, &HandleGameObjectAddTempCommand,   "" },
            { "",     rbac::RBAC_PERM_COMMAND_GOBJECT_ADD,      false, &HandleGameObjectAddCommand,       "" },
        };
        static std::vector<ChatCommand> gobjectSetCommandTable =
        {
            { "phase", rbac::RBAC_PERM_COMMAND_GOBJECT_SET_PHASE, false, &HandleGameObjectSetPhaseCommand,  "" },
            { "state", rbac::RBAC_PERM_COMMAND_GOBJECT_SET_STATE, false, &HandleGameObjectSetStateCommand,  "" },
        };
        static std::vector<ChatCommand> gobjectCommandTable =
        {
            { "activate",     rbac::RBAC_PERM_COMMAND_GOBJECT_ACTIVATE,     false, &HandleGameObjectActivateCommand,  ""       },
            { "delete",       rbac::RBAC_PERM_COMMAND_GOBJECT_DELETE,       false, &HandleGameObjectDeleteCommand,    ""       },
            { "info",         rbac::RBAC_PERM_COMMAND_GOBJECT_INFO,         false, &HandleGameObjectInfoCommand,      ""       },
            { "move",         rbac::RBAC_PERM_COMMAND_GOBJECT_MOVE,         false, &HandleGameObjectMoveCommand,      ""       },
            { "near",         rbac::RBAC_PERM_COMMAND_GOBJECT_NEAR,         false, &HandleGameObjectNearCommand,      ""       },
            { "target",       rbac::RBAC_PERM_COMMAND_GOBJECT_TARGET,       false, &HandleGameObjectTargetCommand,    ""       },
            { "turn",         rbac::RBAC_PERM_COMMAND_GOBJECT_TURN,         false, &HandleGameObjectTurnCommand,      ""       },
            { "spawngroup",   rbac::RBAC_PERM_COMMAND_GOBJECT_SPAWNGROUP,   false, &HandleNpcSpawnGroup,              ""       },
            { "despawngroup", rbac::RBAC_PERM_COMMAND_GOBJECT_DESPAWNGROUP, false, &HandleNpcDespawnGroup,            ""       },
            { "add",          rbac::RBAC_PERM_COMMAND_GOBJECT_ADD,          false, nullptr,         "", gobjectAddCommandTable },
            { "set",          rbac::RBAC_PERM_COMMAND_GOBJECT_SET,          false, nullptr,         "", gobjectSetCommandTable },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "gobject", rbac::RBAC_PERM_COMMAND_GOBJECT, false, nullptr, "", gobjectCommandTable },
        };
        return commandTable;
    }

    static bool HandleGameObjectActivateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoull(id);
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32_t const autoCloseTime = object->GetGOInfo()->GetAutoCloseTime() ? 10000u : 0u;

        // Activate
        object->SetLootState(GO_READY);
        object->UseDoorOrButton(autoCloseTime, false, handler->GetSession()->GetPlayer());

        handler->PSendSysMessage("Object activated!");

        return true;
    }

    //spawn go
    static bool HandleGameObjectAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject_entry");
        if (!id)
            return false;

        uint32 objectId = atoul(id);
        if (!objectId)
            return false;

        char* spawntimeSecs = strtok(nullptr, " ");

        GameObjectTemplate const* objectInfo = sObjectMgr->GetGameObjectTemplate(objectId);
        if (!objectInfo)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, objectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (objectInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(objectInfo->displayId))
        {
            // report to DB errors log as in loading case
            TC_LOG_ERROR("sql.sql", "Gameobject (Entry %u GoType: %u) have invalid displayId (%u), not spawned.", objectId, objectInfo->type, objectInfo->displayId);
            handler->PSendSysMessage(LANG_GAMEOBJECT_HAVE_INVALID_DATA, objectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        Map* map = player->GetMap();

        GameObject* object = GameObject::CreateGameObject(objectInfo->entry, map, *player, QuaternionData::fromEulerAnglesZYX(player->GetOrientation(), 0.0f, 0.0f), 255, GO_STATE_READY);
        if (!object)
            return false;

        PhasingHandler::InheritPhaseShift(object, player);

        if (spawntimeSecs)
        {
            int32 value = atoi(spawntimeSecs);
            object->SetRespawnTime(value);
        }

        // fill the gameobject data and save to the db
        object->SaveToDB(map->GetId(), { map->GetDifficultyID() });
        ObjectGuid::LowType spawnId = object->GetSpawnId();

        // delete the old object and do a clean load from DB with a fresh new GameObject instance.
        // this is required to avoid weird behavior and memory leaks
        delete object;

        // this will generate a new guid if the object is in an instance
        object = GameObject::CreateGameObjectFromDB(spawnId, map);
        if (!object)
            return false;

        /// @todo is it really necessary to add both the real and DB table guid here ?
        sObjectMgr->AddGameobjectToGrid(ASSERT_NOTNULL(sObjectMgr->GetGameObjectData(spawnId)));

        handler->PSendSysMessage(LANG_GAMEOBJECT_ADD, objectId, objectInfo->name.c_str(), std::to_string(spawnId).c_str(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
        return true;
    }

    // add go, temp only
    static bool HandleGameObjectAddTempCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* id = strtok((char*)args, " ");
        if (!id)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* spawntime = strtok(nullptr, " ");
        Seconds spawntm = 300s;

        if (spawntime)
            spawntm = Seconds(atoul(spawntime));

        uint32 objectId = atoul(id);

        if (!sObjectMgr->GetGameObjectTemplate(objectId))
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, objectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->SummonGameObject(objectId, *player, QuaternionData::fromEulerAnglesZYX(player->GetOrientation(), 0.0f, 0.0f), spawntm);

        return true;
    }

    static bool HandleGameObjectTargetCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        QueryResult result;
        GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr->GetActiveEventList();

        if (*args)
        {
            // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
            char* id = handler->extractKeyFromLink((char*)args, "Hgameobject_entry");
            if (!id)
                return false;

            uint32 objectId = atoul(id);

            if (objectId)
                result = WorldDatabase.PQuery("SELECT guid, id, position_x, position_y, position_z, orientation, map, PhaseId, PhaseGroup, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE map = '%i' AND id = '%u' ORDER BY order_ ASC LIMIT 1",
                player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), objectId);
            else
            {
                std::string name = id;
                WorldDatabase.EscapeString(name);
                result = WorldDatabase.PQuery(
                    "SELECT guid, id, position_x, position_y, position_z, orientation, map, PhaseId, PhaseGroup, (POW(position_x - %f, 2) + POW(position_y - %f, 2) + POW(position_z - %f, 2)) AS order_ "
                    "FROM gameobject LEFT JOIN gameobject_template ON gameobject_template.entry = gameobject.id WHERE map = %i AND name LIKE '%%%s%%' ORDER BY order_ ASC LIMIT 1",
                    player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), name.c_str());
            }
        }
        else
        {
            std::ostringstream eventFilter;
            eventFilter << " AND (eventEntry IS NULL ";
            bool initString = true;

            for (GameEventMgr::ActiveEvents::const_iterator itr = activeEventsList.begin(); itr != activeEventsList.end(); ++itr)
            {
                if (initString)
                {
                    eventFilter  <<  "OR eventEntry IN (" << *itr;
                    initString = false;
                }
                else
                    eventFilter << ',' << *itr;
            }

            if (!initString)
                eventFilter << "))";
            else
                eventFilter << ')';

            result = WorldDatabase.PQuery("SELECT gameobject.guid, id, position_x, position_y, position_z, orientation, map, PhaseId, PhaseGroup, "
                "(POW(position_x - %f, 2) + POW(position_y - %f, 2) + POW(position_z - %f, 2)) AS order_ FROM gameobject "
                "LEFT OUTER JOIN game_event_gameobject on gameobject.guid = game_event_gameobject.guid WHERE map = '%i' %s ORDER BY order_ ASC LIMIT 10",
                handler->GetSession()->GetPlayer()->GetPositionX(), handler->GetSession()->GetPlayer()->GetPositionY(), handler->GetSession()->GetPlayer()->GetPositionZ(),
                handler->GetSession()->GetPlayer()->GetMapId(), eventFilter.str().c_str());
        }

        if (!result)
        {
            handler->SendSysMessage(LANG_COMMAND_TARGETOBJNOTFOUND);
            return true;
        }

        bool found = false;
        float x, y, z, o;
        ObjectGuid::LowType guidLow;
        uint32 id, phaseId, phaseGroup;
        uint16 mapId;
        uint32 poolId;

        do
        {
            Field* fields = result->Fetch();
            guidLow =       fields[0].GetUInt64();
            id =            fields[1].GetUInt32();
            x =             fields[2].GetFloat();
            y =             fields[3].GetFloat();
            z =             fields[4].GetFloat();
            o =             fields[5].GetFloat();
            mapId =         fields[6].GetUInt16();
            phaseId =       fields[7].GetUInt32();
            phaseGroup =    fields[8].GetUInt32();
            poolId =  sPoolMgr->IsPartOfAPool<GameObject>(guidLow);
            if (!poolId || sPoolMgr->IsSpawnedObject<GameObject>(guidLow))
                found = true;
        } while (result->NextRow() && !found);

        if (!found)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, id);
            return false;
        }

        GameObjectTemplate const* objectInfo = sObjectMgr->GetGameObjectTemplate(id);

        if (!objectInfo)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, id);
            return false;
        }

        GameObject* target = handler->GetObjectFromPlayerMapByDbGuid(guidLow);

        handler->PSendSysMessage(LANG_GAMEOBJECT_DETAIL, std::to_string(guidLow).c_str(), objectInfo->name.c_str(), std::to_string(guidLow).c_str(), id, x, y, z, mapId, o, phaseId, phaseGroup);

        if (target)
        {
            int32 curRespawnDelay = int32(target->GetRespawnTimeEx() - GameTime::GetGameTime());
            if (curRespawnDelay < 0)
                curRespawnDelay = 0;

            std::string curRespawnDelayStr = secsToTimeString(curRespawnDelay, TimeFormat::ShortText);
            std::string defRespawnDelayStr = secsToTimeString(target->GetRespawnDelay(), TimeFormat::ShortText);

            handler->PSendSysMessage(LANG_COMMAND_RAWPAWNTIMES, defRespawnDelayStr.c_str(), curRespawnDelayStr.c_str());
        }
        return true;
    }

    //delete object by selection or guid
    static bool HandleGameObjectDeleteCommand(ChatHandler* handler, Variant<Hyperlink<gameobject>, ObjectGuid::LowType> spawnId)
    {
        if (GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(spawnId))
        {
            Player const* const player = handler->GetSession()->GetPlayer();
            ObjectGuid ownerGuid = object->GetOwnerGUID();
            if (!ownerGuid.IsEmpty())
            {
                Unit* owner = ObjectAccessor::GetUnit(*player, ownerGuid);
                if (!owner || !ownerGuid.IsPlayer())
                {
                    handler->PSendSysMessage(LANG_COMMAND_DELOBJREFERCREATURE, ownerGuid.GetCounter(), spawnId);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                owner->RemoveGameObject(object, false);
            }
        }

        if (GameObject::DeleteFromDB(spawnId))
        {
            handler->PSendSysMessage(LANG_COMMAND_DELOBJMESSAGE, std::to_string(spawnId));
            return true;
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(spawnId));
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    //turn selected object
    static bool HandleGameObjectTurnCommand(ChatHandler* handler, char const* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoull(id);
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* orientation = strtok(nullptr, " ");
        float oz = 0.f, oy = 0.f, ox = 0.f;

        if (orientation)
        {
            oz = float(atof(orientation));

            orientation = strtok(nullptr, " ");
            if (orientation)
            {
                oy = float(atof(orientation));
                orientation = strtok(nullptr, " ");
                if (orientation)
                    ox = float(atof(orientation));
            }
        }
        else
        {
            Player* player = handler->GetSession()->GetPlayer();
            oz = player->GetOrientation();
        }

        Map* map = object->GetMap();

        object->Relocate(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), oz);
        object->SetLocalRotationAngles(oz, oy, ox);
        object->SaveToDB();

        // Generate a completely new spawn with new guid
        // 3.3.5a client caches recently deleted objects and brings them back to life
        // when CreateObject block for this guid is received again
        // however it entirely skips parsing that block and only uses already known location
        object->Delete();

        object = GameObject::CreateGameObjectFromDB(guidLow, map);
        if (!object)
            return false;

        handler->PSendSysMessage(LANG_COMMAND_TURNOBJMESSAGE, std::to_string(object->GetSpawnId()).c_str(), object->GetGOInfo()->name.c_str(), object->GetGUID().ToString().c_str(), object->GetOrientation());
        return true;
    }

    //move selected object
    static bool HandleGameObjectMoveCommand(ChatHandler* handler, char const* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_guid|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoull(id);
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* toX = strtok(nullptr, " ");
        char* toY = strtok(nullptr, " ");
        char* toZ = strtok(nullptr, " ");

        float x, y, z;
        if (!toX)
        {
            Player* player = handler->GetSession()->GetPlayer();
            player->GetPosition(x, y, z);
        }
        else
        {
            if (!toY || !toZ)
                return false;

            x = (float)atof(toX);
            y = (float)atof(toY);
            z = (float)atof(toZ);

            if (!MapManager::IsValidMapCoord(object->GetMapId(), x, y, z))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, object->GetMapId());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        Map* map = object->GetMap();

        object->Relocate(x, y, z, object->GetOrientation());

        // update which cell has this gameobject registered for loading
        sObjectMgr->RemoveGameobjectFromGrid(object->GetGameObjectData());
        object->SaveToDB();
        sObjectMgr->AddGameobjectToGrid(object->GetGameObjectData());

        // Generate a completely new spawn with new guid
        // 3.3.5a client caches recently deleted objects and brings them back to life
        // when CreateObject block for this guid is received again
        // however it entirely skips parsing that block and only uses already known location
        object->Delete();

        object = GameObject::CreateGameObjectFromDB(guidLow, map);
        if (!object)
            return false;

        handler->PSendSysMessage(LANG_COMMAND_MOVEOBJMESSAGE, std::to_string(object->GetSpawnId()).c_str(), object->GetGOInfo()->name.c_str(), object->GetGUID().ToString().c_str());
        return true;
    }

    //set phasemask for selected object
    static bool HandleGameObjectSetPhaseCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        /*// number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoull(id);
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* phase = strtok (nullptr, " ");
        uint32 phaseMask = phase ? atoul(phase) : 0;
        if (phaseMask == 0)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        object->SetPhaseMask(phaseMask, true);
        object->SaveToDB();*/
        return true;
    }

    static bool HandleGameObjectNearCommand(ChatHandler* handler, char const* args)
    {
        float distance = (!*args) ? 10.0f : (float)(atof(args));
        uint32 count = 0;

        Player* player = handler->GetSession()->GetPlayer();

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_GAMEOBJECT_NEAREST);
        stmt->setFloat(0, player->GetPositionX());
        stmt->setFloat(1, player->GetPositionY());
        stmt->setFloat(2, player->GetPositionZ());
        stmt->setUInt32(3, player->GetMapId());
        stmt->setFloat(4, player->GetPositionX());
        stmt->setFloat(5, player->GetPositionY());
        stmt->setFloat(6, player->GetPositionZ());
        stmt->setFloat(7, distance * distance);
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                ObjectGuid::LowType guid = fields[0].GetUInt64();
                uint32 entry = fields[1].GetUInt32();
                float x = fields[2].GetFloat();
                float y = fields[3].GetFloat();
                float z = fields[4].GetFloat();
                uint16 mapId = fields[5].GetUInt16();

                GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate(entry);

                if (!gameObjectInfo)
                    continue;

                handler->PSendSysMessage(LANG_GO_LIST_CHAT, std::to_string(guid).c_str(), entry, std::to_string(guid).c_str(), gameObjectInfo->name.c_str(), x, y, z, mapId, "", "");

                ++count;
            } while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_NEAROBJMESSAGE, distance, count);
        return true;
    }

    //show info of gameobject
    static bool HandleGameObjectInfoCommand(ChatHandler* handler, char const* args)
    {
        uint32 entry = 0;
        uint32 type = 0;
        uint32 displayId = 0;
        std::string name;
        uint32 lootId = 0;

        if (!*args)
            return false;

        char* param1 = handler->extractKeyFromLink((char*)args, "Hgameobject_entry");
        if (!param1)
            return false;

        GameObject* thisGO = nullptr;
        GameObjectData const* data = nullptr;

        ObjectGuid::LowType spawnId = 0;
        if (strcmp(param1, "guid") == 0)
        {
            char* tail = strtok(nullptr, "");
            char* cValue = handler->extractKeyFromLink(tail, "Hgameobject");
            if (!cValue)
                return false;
            spawnId = atoull(cValue);
            data = sObjectMgr->GetGameObjectData(spawnId);
            if (!data)
            {
                handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, spawnId);
                handler->SetSentErrorMessage(true);
                return false;
            }
            entry = data->id;
            thisGO = handler->GetObjectFromPlayerMapByDbGuid(spawnId);
        }
        else
        {
            entry = atoul(param1);
        }

        GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate(entry);
        if (!gameObjectInfo)
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        type = gameObjectInfo->type;
        displayId = gameObjectInfo->displayId;
        name = gameObjectInfo->name;
        lootId = gameObjectInfo->GetLootId();

        // If we have a real object, send some info about it
        if (thisGO)
        {
            handler->PSendSysMessage(LANG_SPAWNINFO_GUIDINFO, thisGO->GetGUID().ToString().c_str());
            handler->PSendSysMessage(LANG_SPAWNINFO_COMPATIBILITY_MODE, thisGO->GetRespawnCompatibilityMode());

            if (thisGO->GetGameObjectData() && thisGO->GetGameObjectData()->spawnGroupData->groupId)
            {
                SpawnGroupTemplateData const* groupData = thisGO->GetGameObjectData()->spawnGroupData;
                handler->PSendSysMessage(LANG_SPAWNINFO_GROUP_ID, groupData->name.c_str(), groupData->groupId, groupData->flags, thisGO->GetMap()->IsSpawnGroupActive(groupData->groupId));
            }

            GameObjectOverride const* goOverride = sObjectMgr->GetGameObjectOverride(spawnId);
            if (!goOverride)
                goOverride = sObjectMgr->GetGameObjectTemplateAddon(entry);
            if (goOverride)
                handler->PSendSysMessage(LANG_GOINFO_ADDON, goOverride->Faction, goOverride->Flags);
        }

        if (data)
        {
            float yaw, pitch, roll;
            data->rotation.toEulerAnglesZYX(yaw, pitch, roll);
            handler->PSendSysMessage(LANG_SPAWNINFO_SPAWNID_LOCATION, std::to_string(data->spawnId), data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY(), data->spawnPoint.GetPositionZ());
            handler->PSendSysMessage(LANG_SPAWNINFO_ROTATION, yaw, pitch, roll);
        }

        handler->PSendSysMessage(LANG_GOINFO_ENTRY, entry);
        handler->PSendSysMessage(LANG_GOINFO_TYPE, type);
        handler->PSendSysMessage(LANG_GOINFO_LOOTID, lootId);
        handler->PSendSysMessage(LANG_GOINFO_DISPLAYID, displayId);
        handler->PSendSysMessage(LANG_GOINFO_NAME, name.c_str());
        handler->PSendSysMessage(LANG_GOINFO_SIZE, gameObjectInfo->size);
        handler->PSendSysMessage(LANG_OBJECTINFO_AIINFO, gameObjectInfo->AIName.c_str(), sObjectMgr->GetScriptName(gameObjectInfo->ScriptId).c_str());
        if (GameObjectAI const* ai = thisGO ? thisGO->AI() : nullptr)
            handler->PSendSysMessage(LANG_OBJECTINFO_AITYPE, boost::core::demangle(typeid(*ai).name()).c_str());

        if (GameObjectDisplayInfoEntry const* modelInfo = sGameObjectDisplayInfoStore.LookupEntry(displayId))
            handler->PSendSysMessage(LANG_GOINFO_MODEL, modelInfo->GeoBoxMax.X, modelInfo->GeoBoxMax.Y, modelInfo->GeoBoxMax.Z, modelInfo->GeoBoxMin.X, modelInfo->GeoBoxMin.Y, modelInfo->GeoBoxMin.Z);

        return true;
    }

    static bool HandleGameObjectSetStateCommand(ChatHandler* handler, char const* args)
    {
        // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject");
        if (!id)
            return false;

        ObjectGuid::LowType guidLow = atoull(id);
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, std::to_string(guidLow).c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* type = strtok(nullptr, " ");
        if (!type)
            return false;

        int32 objectType = atoi(type);
        if (objectType < 0)
        {
            if (objectType == -1)
                object->SendGameObjectDespawn();
            else if (objectType == -2)
                return false;
            return true;
        }

        char* state = strtok(nullptr, " ");
        if (!state)
            return false;

        int32 objectState = atoi(state);

        switch (objectType)
        {
            case 0:
                object->SetGoState(GOState(objectState));
                break;
            case 1:
                object->SetGoType(GameobjectTypes(objectState));
                break;
            case 2:
                object->SetGoArtKit(objectState);
                break;
            case 3:
                object->SetGoAnimProgress(objectState);
                break;
            case 4:
                object->SendCustomAnim(objectState);
                break;
            case 5:
                if (objectState < 0 || objectState > GO_DESTRUCTIBLE_REBUILDING)
                    return false;

                object->SetDestructibleState(GameObjectDestructibleState(objectState));
                break;
            default:
                break;
        }

        handler->PSendSysMessage("Set gobject type %d state %d", objectType, objectState);
        return true;
    }
};

void AddSC_gobject_commandscript()
{
    new gobject_commandscript();
}
