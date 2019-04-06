/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "MapManager.h"
#include "InstanceSaveMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Transport.h"
#include "GridDefines.h"
#include "MapInstanced.h"
#include "InstanceScript.h"
#include "Config.h"
#include "World.h"
#include "Corpse.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "Group.h"
#include "Player.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "MiscPackets.h"

MapManager::MapManager()
    : _nextInstanceId(0), _scheduledScripts(0)
{
    i_gridCleanUpDelay = sWorld->getIntConfig(CONFIG_INTERVAL_GRIDCLEAN);
    i_timer.SetInterval(sWorld->getIntConfig(CONFIG_INTERVAL_MAPUPDATE));
}

MapManager::~MapManager() { }

void MapManager::Initialize()
{
    Map::InitStateMachine();

    int num_threads(sWorld->getIntConfig(CONFIG_NUMTHREADS));
    // Start mtmaps if needed.
    if (num_threads > 0)
        m_updater.activate(num_threads);
}

void MapManager::InitializeParentMapData(std::unordered_map<uint32, std::vector<uint32>> const& mapData)
{
    _parentMapData = mapData;
}

void MapManager::InitializeVisibilityDistanceInfo()
{
    for (auto iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        iter->second->InitVisibilityDistance();
}

MapManager* MapManager::instance()
{
    static MapManager instance;
    return &instance;
}

Map* MapManager::CreateBaseMap(uint32 id)
{
    Map* map = FindBaseMap(id);

    if (!map)
    {
        MapEntry const* entry = sMapStore.AssertEntry(id);
        if (entry->ParentMapID != -1)
        {
            CreateBaseMap(entry->ParentMapID);

            // must have been created by parent map
            map = FindBaseMap(id);
            return ASSERT_NOTNULL(map);
        }

        std::lock_guard<std::mutex> lock(_mapsLock);
        map = CreateBaseMap_i(entry);
    }

    ASSERT(map);
    return map;
}

Map* MapManager::CreateBaseMap_i(MapEntry const* mapEntry)
{
    Map* map;
    if (mapEntry->Instanceable())
        map = new MapInstanced(mapEntry->ID, i_gridCleanUpDelay);
    else
        map = new Map(mapEntry->ID, i_gridCleanUpDelay, 0, DIFFICULTY_NONE);

    i_maps[mapEntry->ID] = map;

    for (uint32 childMapId : _parentMapData[mapEntry->ID])
        map->AddChildTerrainMap(CreateBaseMap_i(sMapStore.AssertEntry(childMapId)));

    if (!mapEntry->Instanceable())
    {
        map->LoadRespawnTimes();
        map->LoadCorpseData();
    }

    return map;
}

Map* MapManager::FindBaseNonInstanceMap(uint32 mapId) const
{
    Map* map = FindBaseMap(mapId);
    if (map && map->Instanceable())
        return NULL;
    return map;
}

Map* MapManager::CreateMap(uint32 id, Player* player, uint32 loginInstanceId)
{
    Map* m = CreateBaseMap(id);

    if (m && m->Instanceable())
        m = ((MapInstanced*)m)->CreateInstanceForPlayer(id, player, loginInstanceId);

    return m;
}

Map* MapManager::FindMap(uint32 mapid, uint32 instanceId) const
{
    Map* map = FindBaseMap(mapid);
    if (!map)
        return NULL;

    if (!map->Instanceable())
        return instanceId == 0 ? map : NULL;

    return ((MapInstanced*)map)->FindInstanceMap(instanceId);
}

Map::EnterState MapManager::PlayerCannotEnter(uint32 mapid, Player* player, bool loginCheck)
{
    MapEntry const* entry = sMapStore.LookupEntry(mapid);
    if (!entry)
        return Map::CANNOT_ENTER_NO_ENTRY;

    if (!entry->IsDungeon())
        return Map::CAN_ENTER;

    InstanceTemplate const* instance = sObjectMgr->GetInstanceTemplate(mapid);
    if (!instance)
        return Map::CANNOT_ENTER_UNINSTANCED_DUNGEON;

    Difficulty targetDifficulty, requestedDifficulty;
    targetDifficulty = requestedDifficulty = player->GetDifficultyID(entry);
    // Get the highest available difficulty if current setting is higher than the instance allows
    MapDifficultyEntry const* mapDiff = sDB2Manager.GetDownscaledMapDifficultyData(mapid, targetDifficulty);
    if (!mapDiff)
        return Map::CANNOT_ENTER_DIFFICULTY_UNAVAILABLE;

    //Bypass checks for GMs
    if (player->IsGameMaster())
        return Map::CAN_ENTER;

    char const* mapName = entry->MapName->Str[sWorld->GetDefaultDbcLocale()];

    Group* group = player->GetGroup();
    if (entry->IsRaid() && entry->Expansion() >= sWorld->getIntConfig(CONFIG_EXPANSION)) // can only enter in a raid group but raids from old expansion don't need a group
        if ((!group || !group->isRaidGroup()) && !sWorld->getBoolConfig(CONFIG_INSTANCE_IGNORE_RAID))
            return Map::CANNOT_ENTER_NOT_IN_RAID;

    if (!player->IsAlive())
    {
        if (player->HasCorpse())
        {
            // let enter in ghost mode in instance that connected to inner instance with corpse
            uint32 corpseMap = player->GetCorpseLocation().GetMapId();
            do
            {
                if (corpseMap == mapid)
                    break;

                InstanceTemplate const* corpseInstance = sObjectMgr->GetInstanceTemplate(corpseMap);
                corpseMap = corpseInstance ? corpseInstance->Parent : 0;
            } while (corpseMap);

            if (!corpseMap)
                return Map::CANNOT_ENTER_CORPSE_IN_DIFFERENT_INSTANCE;

            TC_LOG_DEBUG("maps", "MAP: Player '%s' has corpse in instance '%s' and can enter.", player->GetName().c_str(), mapName);
        }
        else
            TC_LOG_DEBUG("maps", "Map::CanPlayerEnter - player '%s' is dead but does not have a corpse!", player->GetName().c_str());
    }

    //Get instance where player's group is bound & its map
    if (!loginCheck && group)
    {
        InstanceGroupBind* boundInstance = group->GetBoundInstance(entry);
        if (boundInstance && boundInstance->save)
            if (Map* boundMap = sMapMgr->FindMap(mapid, boundInstance->save->GetInstanceId()))
                if (Map::EnterState denyReason = boundMap->CannotEnter(player))
                    return denyReason;
    }

    // players are only allowed to enter 5 instances per hour
    if (entry->IsDungeon() && (!player->GetGroup() || (player->GetGroup() && !player->GetGroup()->isLFGGroup())))
    {
        uint32 instanceIdToCheck = 0;
        if (InstanceSave* save = player->GetInstanceSave(mapid))
            instanceIdToCheck = save->GetInstanceId();

        // instanceId can never be 0 - will not be found
        if (!player->CheckInstanceCount(instanceIdToCheck) && !player->isDead())
            return Map::CANNOT_ENTER_TOO_MANY_INSTANCES;
    }

    //Other requirements
    if (player->Satisfy(sObjectMgr->GetAccessRequirement(mapid, targetDifficulty), mapid, true))
        return Map::CAN_ENTER;
    else
        return Map::CANNOT_ENTER_UNSPECIFIED_REASON;
}

void MapManager::Update(uint32 diff)
{
    i_timer.Update(diff);
    if (!i_timer.Passed())
        return;

    MapMapType::iterator iter = i_maps.begin();
    for (; iter != i_maps.end(); ++iter)
    {
        if (m_updater.activated())
            m_updater.schedule_update(*iter->second, uint32(i_timer.GetCurrent()));
        else
            iter->second->Update(uint32(i_timer.GetCurrent()));
    }
    if (m_updater.activated())
        m_updater.wait();

    for (iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        iter->second->DelayedUpdate(uint32(i_timer.GetCurrent()));

    i_timer.SetCurrent(0);
}

void MapManager::DoDelayedMovesAndRemoves() { }

bool MapManager::ExistMapAndVMap(uint32 mapid, float x, float y)
{
    GridCoord p = Trinity::ComputeGridCoord(x, y);

    int gx = (MAX_NUMBER_OF_GRIDS - 1) - p.x_coord;
    int gy = (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord;

    return Map::ExistMap(mapid, gx, gy) && Map::ExistVMap(mapid, gx, gy);
}

bool MapManager::IsValidMAP(uint32 mapid, bool startUp)
{
    MapEntry const* mEntry = sMapStore.LookupEntry(mapid);

    if (startUp)
        return mEntry ? true : false;
    else
        return mEntry && (!mEntry->IsDungeon() || sObjectMgr->GetInstanceTemplate(mapid));

    /// @todo add check for battleground template
}

void MapManager::UnloadAll()
{
    // first unlink child maps
    for (auto iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        iter->second->UnlinkAllChildTerrainMaps();

    for (MapMapType::iterator iter = i_maps.begin(); iter != i_maps.end();)
    {
        iter->second->UnloadAll();
        delete iter->second;
        i_maps.erase(iter++);
    }

    if (m_updater.activated())
        m_updater.deactivate();

    Map::DeleteStateMachine();
}

uint32 MapManager::GetNumInstances()
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    uint32 ret = 0;
    for (MapMapType::iterator itr = i_maps.begin(); itr != i_maps.end(); ++itr)
    {
        Map* map = itr->second;
        if (!map->Instanceable())
            continue;
        MapInstanced::InstancedMaps &maps = ((MapInstanced*)map)->GetInstancedMaps();
        for (MapInstanced::InstancedMaps::iterator mitr = maps.begin(); mitr != maps.end(); ++mitr)
            if (mitr->second->IsDungeon()) ret++;
    }
    return ret;
}

uint32 MapManager::GetNumPlayersInInstances()
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    uint32 ret = 0;
    for (MapMapType::iterator itr = i_maps.begin(); itr != i_maps.end(); ++itr)
    {
        Map* map = itr->second;
        if (!map->Instanceable())
            continue;
        MapInstanced::InstancedMaps &maps = ((MapInstanced*)map)->GetInstancedMaps();
        for (MapInstanced::InstancedMaps::iterator mitr = maps.begin(); mitr != maps.end(); ++mitr)
            if (mitr->second->IsDungeon())
                ret += ((InstanceMap*)mitr->second)->GetPlayers().getSize();
    }
    return ret;
}

void MapManager::InitInstanceIds()
{
    _nextInstanceId = 1;

    QueryResult result = CharacterDatabase.Query("SELECT MAX(id) FROM instance");
    if (result)
    {
        uint32 maxId = (*result)[0].GetUInt32();

        // Resize to multiples of 32 (vector<bool> allocates memory the same way)
        _instanceIds.resize((maxId / 32) * 32 + 32);
    }
}

void MapManager::RegisterInstanceId(uint32 instanceId)
{
    // Allocation and sizing was done in InitInstanceIds()
    _instanceIds[instanceId] = true;
}

uint32 MapManager::GenerateInstanceId()
{
    uint32 newInstanceId = _nextInstanceId;

    // Find the lowest available id starting from the current NextInstanceId (which should be the lowest according to the logic in FreeInstanceId()
    for (uint32 i = ++_nextInstanceId; i < 0xFFFFFFFF; ++i)
    {
        if ((i < _instanceIds.size() && !_instanceIds[i]) || i >= _instanceIds.size())
        {
            _nextInstanceId = i;
            break;
        }
    }

    if (newInstanceId == _nextInstanceId)
    {
        TC_LOG_ERROR("maps", "Instance ID overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }

    // Allocate space if necessary
    if (newInstanceId >= uint32(_instanceIds.size()))
    {
        // Due to the odd memory allocation behavior of vector<bool> we match size to capacity before triggering a new allocation
        if (_instanceIds.size() < _instanceIds.capacity())
        {
            _instanceIds.resize(_instanceIds.capacity());
        }
        else
            _instanceIds.resize((newInstanceId / 32) * 32 + (newInstanceId % 32 > 0 ? 32 : 0));
    }

    _instanceIds[newInstanceId] = true;

    return newInstanceId;
}

void MapManager::FreeInstanceId(uint32 instanceId)
{
    // If freed instance id is lower than the next id available for new instances, use the freed one instead
    if (instanceId < _nextInstanceId)
        SetNextInstanceId(instanceId);

    _instanceIds[instanceId] = false;
}
