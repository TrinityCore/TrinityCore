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
#include "ScriptMgr.h"
#include <numeric>

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

void MapManager::InitializeVisibilityDistanceInfo()
{
    for (MapMapType::iterator iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        (*iter).second->InitVisibilityDistance();
}

MapManager* MapManager::instance()
{
    static MapManager instance;
    return &instance;
}

Map* MapManager::CreateBaseMap(uint32 id)
{
    Map* map = FindBaseMap(id);

    if (map == nullptr)
    {
        std::lock_guard<std::mutex> lock(_mapsLock);

        MapEntry const* entry = sMapStore.LookupEntry(id);
        ASSERT(entry);

        if (entry->Instanceable())
            map = new MapInstanced(id, i_gridCleanUpDelay);
        else
        {
            map = new Map(id, i_gridCleanUpDelay, 0, REGULAR_DIFFICULTY);
            map->LoadRespawnTimes();
            map->LoadCorpseData();
        }

        Trinity::unique_trackable_ptr<Map>& ptr = i_maps[id];
        ptr.reset(map);
        map->SetWeakPtr(ptr);

        sScriptMgr->OnCreateMap(map);
    }

    ASSERT(map);
    return map;
}

Map* MapManager::FindBaseNonInstanceMap(uint32 mapId) const
{
    Map* map = FindBaseMap(mapId);
    if (map && map->Instanceable())
        return nullptr;
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
        return nullptr;

    if (!map->Instanceable())
        return instanceId == 0 ? map : nullptr;

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
    targetDifficulty = requestedDifficulty = player->GetDifficulty(entry->IsRaid());
    // Get the highest available difficulty if current setting is higher than the instance allows
    MapDifficulty const* mapDiff = GetDownscaledMapDifficultyData(entry->ID, targetDifficulty);
    if (!mapDiff)
        return Map::CANNOT_ENTER_DIFFICULTY_UNAVAILABLE;

    //Bypass checks for GMs
    if (player->IsGameMaster())
        return Map::CAN_ENTER;

    //Other requirements
    if (!player->Satisfy(sObjectMgr->GetAccessRequirement(mapid, targetDifficulty), mapid, true))
        return Map::CANNOT_ENTER_UNSPECIFIED_REASON;

    char const* mapName = entry->MapName[player->GetSession()->GetSessionDbcLocale()];

    Group* group = player->GetGroup();
    if (entry->IsRaid()) // can only enter in a raid group
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

            TC_LOG_DEBUG("maps", "MAP: Player '{}' has corpse in instance '{}' and can enter.", player->GetName(), mapName);
        }
        else
            TC_LOG_DEBUG("maps", "Map::CanPlayerEnter - player '{}' is dead but does not have a corpse!", player->GetName());
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
        if (InstanceSave* save = player->GetInstanceSave(mapid, entry->IsRaid()))
            instanceIdToCheck = save->GetInstanceId();

        // instanceId can never be 0 - will not be found
        if (!player->UpdateAndCheckInstanceCount(instanceIdToCheck) && !player->isDead())
            return Map::CANNOT_ENTER_TOO_MANY_INSTANCES;
    }

    return Map::CAN_ENTER;
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
    // first unload maps
    for (auto iter = i_maps.begin(); iter != i_maps.end(); ++iter)
    {
        iter->second->UnloadAll();

        sScriptMgr->OnDestroyMap(iter->second.get());
    }

    // then delete them
    i_maps.clear();

    if (m_updater.activated())
        m_updater.deactivate();

    Map::DeleteStateMachine();
}

uint32 MapManager::GetNumInstances()
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    uint32 ret = 0;
    for (auto const& [_, map] : i_maps)
    {
        MapInstanced* mapInstanced = map->ToMapInstanced();
        if (!mapInstanced)
            continue;
        ret += mapInstanced->GetInstancedMaps().size();
    }
    return ret;
}

uint32 MapManager::GetNumPlayersInInstances()
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    uint32 ret = 0;
    for (auto& [_, map] : i_maps)
    {
        MapInstanced* mapInstanced = map->ToMapInstanced();
        if (!mapInstanced)
            continue;
        MapInstanced::InstancedMaps& maps = mapInstanced->GetInstancedMaps();
        ret += std::accumulate(maps.begin(), maps.end(), 0u, [](uint32 total, MapInstanced::InstancedMaps::value_type const& value) { return total + value.second->GetPlayers().getSize(); });
    }
    return ret;
}

void MapManager::InitInstanceIds()
{
    _nextInstanceId = 1;

    if (QueryResult result = CharacterDatabase.Query("SELECT IFNULL(MAX(id), 0) FROM instance"))
        _freeInstanceIds.resize((*result)[0].GetUInt64() + 2, true); // make space for one extra to be able to access [_nextInstanceId] index in case all slots are taken
    else
        _freeInstanceIds.resize(_nextInstanceId + 1, true);

    // never allow 0 id
    _freeInstanceIds[0] = false;
}

void MapManager::RegisterInstanceId(uint32 instanceId)
{
    // Allocation and sizing was done in InitInstanceIds()
    _freeInstanceIds[instanceId] = false;

    // Instances are pulled in ascending order from db and nextInstanceId is initialized with 1,
    // so if the instance id is used, increment until we find the first unused one for a potential new instance
    if (_nextInstanceId == instanceId)
        ++_nextInstanceId;
}

uint32 MapManager::GenerateInstanceId()
{
    if (_nextInstanceId == 0xFFFFFFFF)
    {
        TC_LOG_ERROR("maps", "Instance ID overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
        return _nextInstanceId;
    }

    uint32 newInstanceId = _nextInstanceId;
    ASSERT(newInstanceId < _freeInstanceIds.size());
    _freeInstanceIds[newInstanceId] = false;

    // Find the lowest available id starting from the current NextInstanceId (which should be the lowest according to the logic in FreeInstanceId())
    size_t nextFreedId = _freeInstanceIds.find_next(_nextInstanceId++);
    if (nextFreedId == InstanceIds::npos)
    {
        _nextInstanceId = uint32(_freeInstanceIds.size());
        _freeInstanceIds.push_back(true);
    }
    else
        _nextInstanceId = uint32(nextFreedId);

    return newInstanceId;
}

void MapManager::FreeInstanceId(uint32 instanceId)
{
    // If freed instance id is lower than the next id available for new instances, use the freed one instead
    _nextInstanceId = std::min(instanceId, _nextInstanceId);
    _freeInstanceIds[instanceId] = true;
}
