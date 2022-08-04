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
#include "DBCStores.h"
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
#include "Player.h"
#include "PoolMgr.h"
#include "RBAC.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

using GameObjectSpawnId = Variant<Hyperlink<gameobject>, ObjectGuid::LowType>;
using GameObjectEntry = Variant<Hyperlink<gameobject_entry>, uint32>;

// definitions are over in cs_npc.cpp
bool HandleNpcSpawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("force"), EXACT_SEQUENCE("ignorerespawn")>> const& opts);
bool HandleNpcDespawnGroup(ChatHandler* handler, std::vector<Variant<uint32, EXACT_SEQUENCE("removerespawntime")>> const& opts);

class gobject_commandscript : public CommandScript
{
public:
    gobject_commandscript() : CommandScript("gobject_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable gobjectCommandTable =
        {
            { "activate",       HandleGameObjectActivateCommand,  rbac::RBAC_PERM_COMMAND_GOBJECT_ACTIVATE,       Console::No },
            { "delete",         HandleGameObjectDeleteCommand,    rbac::RBAC_PERM_COMMAND_GOBJECT_DELETE,         Console::No },
            { "info",           HandleGameObjectInfoCommand,      rbac::RBAC_PERM_COMMAND_GOBJECT_INFO,           Console::No },
            { "move",           HandleGameObjectMoveCommand,      rbac::RBAC_PERM_COMMAND_GOBJECT_MOVE,           Console::No },
            { "near",           HandleGameObjectNearCommand,      rbac::RBAC_PERM_COMMAND_GOBJECT_NEAR,           Console::No },
            { "target",         HandleGameObjectTargetCommand,    rbac::RBAC_PERM_COMMAND_GOBJECT_TARGET,         Console::No },
            { "turn",           HandleGameObjectTurnCommand,      rbac::RBAC_PERM_COMMAND_GOBJECT_TURN,           Console::No },
            { "spawngroup",     HandleNpcSpawnGroup,              rbac::RBAC_PERM_COMMAND_GOBJECT_SPAWNGROUP,     Console::No },
            { "despawngroup",   HandleNpcDespawnGroup,            rbac::RBAC_PERM_COMMAND_GOBJECT_DESPAWNGROUP,   Console::No },
            { "add temp",       HandleGameObjectAddTempCommand,   rbac::RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP,       Console::No },
            { "add",            HandleGameObjectAddCommand,       rbac::RBAC_PERM_COMMAND_GOBJECT_ADD,            Console::No },
            { "set phase",      HandleGameObjectSetPhaseCommand,  rbac::RBAC_PERM_COMMAND_GOBJECT_SET_PHASE,      Console::No },
            { "set state",      HandleGameObjectSetStateCommand,  rbac::RBAC_PERM_COMMAND_GOBJECT_SET_STATE,      Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "gobject", gobjectCommandTable },
        };
        return commandTable;
    }

    static bool HandleGameObjectActivateCommand(ChatHandler* handler, GameObjectSpawnId guidLow)
    {
        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guidLow);
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
    static bool HandleGameObjectAddCommand(ChatHandler* handler, GameObjectEntry objectId, Optional<int32> spawnTimeSecs)
    {
        if (!objectId)
            return false;

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
            TC_LOG_ERROR("sql.sql", "Gameobject (Entry %u GoType: %u) have invalid displayId (%u), not spawned.", *objectId, objectInfo->type, objectInfo->displayId);
            handler->PSendSysMessage(LANG_GAMEOBJECT_HAVE_INVALID_DATA, objectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        Map* map = player->GetMap();

        GameObject* object = new GameObject();
        ObjectGuid::LowType guidLow = map->GenerateLowGuid<HighGuid::GameObject>();

        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(player->GetOrientation(), 0.f, 0.f);
        if (!object->Create(guidLow, objectInfo->entry, map, player->GetPhaseMaskForSpawn(), *player, rot, 255, GO_STATE_READY))
        {
            delete object;
            return false;
        }

        if (spawnTimeSecs)
            object->SetRespawnTime(*spawnTimeSecs);

        // fill the gameobject data and save to the db
        object->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), player->GetPhaseMaskForSpawn());
        guidLow = object->GetSpawnId();

        // delete the old object and do a clean load from DB with a fresh new GameObject instance.
        // this is required to avoid weird behavior and memory leaks
        delete object;

        object = new GameObject();
        // this will generate a new guid if the object is in an instance
        if (!object->LoadFromDB(guidLow, map, true))
        {
            delete object;
            return false;
        }

        /// @todo is it really necessary to add both the real and DB table guid here ?
        sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGameObjectData(guidLow));

        handler->PSendSysMessage(LANG_GAMEOBJECT_ADD, objectId, objectInfo->name.c_str(), guidLow, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
        return true;
    }

    // add go, temp only
    static bool HandleGameObjectAddTempCommand(ChatHandler* handler, GameObjectEntry objectId, Optional<uint64> spawntime)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Seconds spawntm(spawntime.value_or(300));

        QuaternionData rotation = QuaternionData::fromEulerAnglesZYX(player->GetOrientation(), 0.f, 0.f);

        if (!sObjectMgr->GetGameObjectTemplate(objectId))
        {
            handler->PSendSysMessage(LANG_GAMEOBJECT_NOT_EXIST, objectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->SummonGameObject(objectId, *player, rotation, spawntm);

        return true;
    }

    static bool HandleGameObjectTargetCommand(ChatHandler* handler, Optional<Variant<GameObjectEntry, std::string_view>> objectId)
    {
        Player* player = handler->GetSession()->GetPlayer();
        QueryResult result;
        GameEventMgr::ActiveEvents const& activeEventsList = sGameEventMgr->GetActiveEventList();

        if (objectId)
        {
            if (objectId->holds_alternative<GameObjectEntry>())
            {
                result = WorldDatabase.PQuery("SELECT guid, id, position_x, position_y, position_z, orientation, map, phaseMask, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE map = '%i' AND id = '%u' ORDER BY order_ ASC LIMIT 1",
                    player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), static_cast<uint32>(objectId->get<GameObjectEntry>()));
            }
            else
            {
                std::string name = std::string(objectId->get<std::string_view>());
                WorldDatabase.EscapeString(name);
                result = WorldDatabase.PQuery(
                    "SELECT guid, id, position_x, position_y, position_z, orientation, map, phaseMask, (POW(position_x - %f, 2) + POW(position_y - %f, 2) + POW(position_z - %f, 2)) AS order_ "
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

            result = WorldDatabase.PQuery("SELECT gameobject.guid, id, position_x, position_y, position_z, orientation, map, phaseMask, "
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
        uint32 id, phase;
        uint16 mapId;
        uint32 poolId;

        do
        {
            Field* fields = result->Fetch();
            guidLow = fields[0].GetUInt32();
            id =      fields[1].GetUInt32();
            x =       fields[2].GetFloat();
            y =       fields[3].GetFloat();
            z =       fields[4].GetFloat();
            o =       fields[5].GetFloat();
            mapId =   fields[6].GetUInt16();
            phase =   fields[7].GetUInt32();
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

        handler->PSendSysMessage(LANG_GAMEOBJECT_DETAIL, guidLow, objectInfo->name.c_str(), guidLow, id, x, y, z, mapId, o, phase);

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
    static bool HandleGameObjectDeleteCommand(ChatHandler* handler, GameObjectSpawnId spawnId)
    {
        if (GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(spawnId))
        {
            Player const* const player = handler->GetSession()->GetPlayer();
            if (ObjectGuid ownerGuid = object->GetOwnerGUID())
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
            handler->PSendSysMessage(LANG_COMMAND_DELOBJMESSAGE, spawnId);
            return true;
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, spawnId);
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    //turn selected object
    static bool HandleGameObjectTurnCommand(ChatHandler* handler, GameObjectSpawnId guidLow, Optional<float> oz, Optional<float> oy, Optional<float> ox)
    {
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guidLow);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!oz)
            oz = handler->GetSession()->GetPlayer()->GetOrientation();

        Map* map = object->GetMap();
        object->Relocate(object->GetPositionX(), object->GetPositionY(), object->GetPositionZ(), *oz);
        object->SetLocalRotationAngles(*oz, oy.value_or(0.0f), ox.value_or(0.0f));
        object->SaveToDB();

        // Generate a completely new spawn with new guid
        // 3.3.5a client caches recently deleted objects and brings them back to life
        // when CreateObject block for this guid is received again
        // however it entirely skips parsing that block and only uses already known location
        object->Delete();

        object = new GameObject();
        if (!object->LoadFromDB(guidLow, map, true))
        {
            delete object;
            return false;
        }

        handler->PSendSysMessage(LANG_COMMAND_TURNOBJMESSAGE, object->GetSpawnId(), object->GetGOInfo()->name.c_str(), object->GetSpawnId());
        return true;
    }

    //move selected object
    static bool HandleGameObjectMoveCommand(ChatHandler* handler, GameObjectSpawnId guidLow, Optional<std::array<float,3>> xyz)
    {
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guidLow);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Position pos;
        if (xyz)
        {
            pos = { (*xyz)[0], (*xyz)[1], (*xyz)[2] };
            if (!MapManager::IsValidMapCoord(object->GetMapId(), pos))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, pos.GetPositionX(), pos.GetPositionY(), object->GetMapId());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            pos = handler->GetSession()->GetPlayer()->GetPosition();
        }

        Map* map = object->GetMap();

        pos.SetOrientation(object->GetOrientation());
        object->Relocate(pos);

        // update which cell has this gameobject registered for loading
        sObjectMgr->RemoveGameobjectFromGrid(guidLow, object->GetGameObjectData());
        object->SaveToDB();
        sObjectMgr->AddGameobjectToGrid(guidLow, object->GetGameObjectData());

        // Generate a completely new spawn with new guid
        // 3.3.5a client caches recently deleted objects and brings them back to life
        // when CreateObject block for this guid is received again
        // however it entirely skips parsing that block and only uses already known location
        object->Delete();

        object = new GameObject();
        if (!object->LoadFromDB(guidLow, map, true))
        {
            delete object;
            return false;
        }

        handler->PSendSysMessage(LANG_COMMAND_MOVEOBJMESSAGE, object->GetSpawnId(), object->GetGOInfo()->name.c_str(), object->GetSpawnId());
        return true;
    }

    //set phasemask for selected object
    static bool HandleGameObjectSetPhaseCommand(ChatHandler* handler, GameObjectSpawnId guidLow, uint32 phaseMask)
    {
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guidLow);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!phaseMask)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        object->SetPhaseMask(phaseMask, true);
        object->SaveToDB();
        return true;
    }

    static bool HandleGameObjectNearCommand(ChatHandler* handler, Optional<float> dist)
    {
        float distance = dist.value_or(10.0f);
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
                ObjectGuid::LowType guid = fields[0].GetUInt32();
                uint32 entry = fields[1].GetUInt32();
                float x = fields[2].GetFloat();
                float y = fields[3].GetFloat();
                float z = fields[4].GetFloat();
                uint16 mapId = fields[5].GetUInt16();

                GameObjectTemplate const* gameObjectInfo = sObjectMgr->GetGameObjectTemplate(entry);

                if (!gameObjectInfo)
                    continue;

                handler->PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gameObjectInfo->name.c_str(), x, y, z, mapId, "", "");

                ++count;
            } while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_NEAROBJMESSAGE, distance, count);
        return true;
    }

    //show info of gameobject
    static bool HandleGameObjectInfoCommand(ChatHandler* handler, Optional<EXACT_SEQUENCE("guid")> isGuid, Variant<Hyperlink<gameobject_entry>, Hyperlink<gameobject>, uint32> data)
    {
        uint32 entry = 0;
        uint32 type = 0;
        uint32 displayId = 0;
        std::string name;
        uint32 lootId = 0;

        GameObject* thisGO = nullptr;
        GameObjectData const* spawnData = nullptr;

        ObjectGuid::LowType spawnId = 0;
        if (isGuid || data.holds_alternative<Hyperlink<gameobject>>())
        {
            spawnId = *data;
            spawnData = sObjectMgr->GetGameObjectData(spawnId);
            if (!spawnData)
            {
                handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, spawnId);
                handler->SetSentErrorMessage(true);
                return false;
            }
            entry = spawnData->id;
            thisGO = handler->GetObjectFromPlayerMapByDbGuid(spawnId);
        }
        else
        {
            entry = *data;
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
        if (type == GAMEOBJECT_TYPE_CHEST)
            lootId = gameObjectInfo->chest.lootId;
        else if (type == GAMEOBJECT_TYPE_FISHINGHOLE)
            lootId = gameObjectInfo->fishinghole.lootId;

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

        if (spawnData)
        {
            float yaw, pitch, roll;
            spawnData->rotation.toEulerAnglesZYX(yaw, pitch, roll);
            handler->PSendSysMessage(LANG_SPAWNINFO_SPAWNID_LOCATION, spawnData->spawnId, spawnData->spawnPoint.GetPositionX(), spawnData->spawnPoint.GetPositionY(), spawnData->spawnPoint.GetPositionZ());
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
            handler->PSendSysMessage(LANG_OBJECTINFO_AITYPE, GetTypeName(*ai).c_str());

        if (GameObjectDisplayInfoEntry const* modelInfo = sGameObjectDisplayInfoStore.LookupEntry(displayId))
            handler->PSendSysMessage(LANG_GOINFO_MODEL, modelInfo->GeoBoxMax.X, modelInfo->GeoBoxMax.Y, modelInfo->GeoBoxMax.Z, modelInfo->GeoBoxMin.X, modelInfo->GeoBoxMin.Y, modelInfo->GeoBoxMin.Z);

        return true;
    }

    static bool HandleGameObjectSetStateCommand(ChatHandler* handler, GameObjectSpawnId guidLow, int32 objectType, Optional<uint32> objectState)
    {
        if (!guidLow)
            return false;

        GameObject* object = handler->GetObjectFromPlayerMapByDbGuid(guidLow);
        if (!object)
        {
            handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, guidLow);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (objectType < 0)
        {
            if (objectType == -1)
                object->SendObjectDeSpawnAnim(object->GetGUID());
            else if (objectType == -2)
                return false;
            return true;
        }

        if (!objectState)
            return false;

        switch (objectType)
        {
            case 0:
                object->SetGoState(GOState(*objectState));
                break;
            case 1:
                object->SetGoType(GameobjectTypes(*objectState));
                break;
            case 2:
                object->SetGoArtKit(*objectState);
                break;
            case 3:
                object->SetGoAnimProgress(*objectState);
                break;
            case 4:
                object->SendCustomAnim(*objectState);
                break;
            case 5:
                if (*objectState > GO_DESTRUCTIBLE_REBUILDING)
                    return false;

                object->SetDestructibleState(GameObjectDestructibleState(*objectState));
                break;
            default:
                break;
        }
        handler->PSendSysMessage("Set gobject type %d state %u", objectType, *objectState);
        return true;
    }
};

void AddSC_gobject_commandscript()
{
    new gobject_commandscript();
}
