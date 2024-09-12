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
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "CharacterCache.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GarrisonMap.h"
#include "Group.h"
#include "InstanceLockMgr.h"
#include "Log.h"
#include "Map.h"
#include "OutdoorPvPMgr.h"
#include "Player.h"
#include "ScenarioMgr.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldStateMgr.h"
#include <boost/dynamic_bitset.hpp>
#include <numeric>

MapManager::MapManager()
    : _freeInstanceIds(std::make_unique<InstanceIds>()), _nextInstanceId(0), _scheduledScripts(0)
{
    i_gridCleanUpDelay = sWorld->getIntConfig(CONFIG_INTERVAL_GRIDCLEAN);
    i_timer.SetInterval(sWorld->getIntConfig(CONFIG_INTERVAL_MAPUPDATE));
}

MapManager::~MapManager() = default;

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
    for (auto iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        iter->second->InitVisibilityDistance();
}

MapManager* MapManager::instance()
{
    static MapManager instance;
    return &instance;
}

Map* MapManager::FindMap_i(uint32 mapId, uint32 instanceId) const
{
    auto itr = i_maps.find({ mapId, instanceId });
    return itr != i_maps.end() ? itr->second.get() : nullptr;
}

Map* MapManager::CreateWorldMap(uint32 mapId, uint32 instanceId)
{
    Map* map = new Map(mapId, i_gridCleanUpDelay, instanceId, DIFFICULTY_NONE);
    map->LoadRespawnTimes();
    map->LoadCorpseData();
    map->InitSpawnGroupState();

    if (sWorld->getBoolConfig(CONFIG_BASEMAP_LOAD_GRIDS))
        map->LoadAllCells();

    return map;
}

InstanceMap* MapManager::CreateInstance(uint32 mapId, uint32 instanceId, InstanceLock* instanceLock, Difficulty difficulty, TeamId team, Group* group)
{
    // make sure we have a valid map id
    MapEntry const* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
    {
        TC_LOG_ERROR("maps", "CreateInstance: no entry for map {}", mapId);
        ABORT();
    }

    // some instances only have one difficulty
    sDB2Manager.GetDownscaledMapDifficultyData(mapId, difficulty);

    TC_LOG_DEBUG("maps", "MapInstanced::CreateInstance: {}map instance {} for {} created with difficulty {}",
        instanceLock && instanceLock->IsNew() ? "" : "new ", instanceId, mapId, sDifficultyStore.AssertEntry(difficulty)->Name[sWorld->GetDefaultDbcLocale()]);

    InstanceMap* map = new InstanceMap(mapId, i_gridCleanUpDelay, instanceId, difficulty, team, instanceLock);
    ASSERT(map->IsDungeon());

    map->LoadRespawnTimes();
    map->LoadCorpseData();
    if (group)
        map->TrySetOwningGroup(group);

    map->CreateInstanceData();
    map->SetInstanceScenario(sScenarioMgr->CreateInstanceScenario(map, team));
    map->InitSpawnGroupState();

    if (sWorld->getBoolConfig(CONFIG_INSTANCEMAP_LOAD_GRIDS))
        map->LoadAllCells();

    return map;
}

BattlegroundMap* MapManager::CreateBattleground(uint32 mapId, uint32 instanceId, Battleground* bg)
{
    TC_LOG_DEBUG("maps", "MapInstanced::CreateBattleground: map bg {} for {} created.", instanceId, mapId);

    BattlegroundMap* map = new BattlegroundMap(mapId, i_gridCleanUpDelay, instanceId, DIFFICULTY_NONE);
    ASSERT(map->IsBattlegroundOrArena());
    map->SetBG(bg);
    bg->SetBgMap(map);
    map->InitScriptData();
    map->InitSpawnGroupState();

    if (sWorld->getBoolConfig(CONFIG_BATTLEGROUNDMAP_LOAD_GRIDS))
        map->LoadAllCells();

    return map;
}

GarrisonMap* MapManager::CreateGarrison(uint32 mapId, uint32 instanceId, Player* owner)
{
    GarrisonMap* map = new GarrisonMap(mapId, i_gridCleanUpDelay, instanceId, owner->GetGUID());
    ASSERT(map->IsGarrison());
    map->InitSpawnGroupState();
    return map;
}

/*
- return the right instance for the object, based on its InstanceId
- create the instance if it's not created already
- the player is not actually added to the instance (only in InstanceMap::Add)
*/
Map* MapManager::CreateMap(uint32 mapId, Player* player)
{
    if (!player)
        return nullptr;

    MapEntry const* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
        return nullptr;

    std::unique_lock<std::shared_mutex> lock(_mapsLock);

    Map* map = nullptr;
    uint32 newInstanceId = 0;                       // instanceId of the resulting map

    if (entry->IsBattlegroundOrArena())
    {
        // instantiate or find existing bg map for player
        // the instance id is set in battlegroundid
        newInstanceId = player->GetBattlegroundId();
        if (!newInstanceId)
            return nullptr;

        map = FindMap_i(mapId, newInstanceId);
        if (!map)
        {
            if (Battleground* bg = player->GetBattleground())
                map = CreateBattleground(mapId, newInstanceId, bg);
            else
            {
                player->TeleportToBGEntryPoint();
                return nullptr;
            }
        }
    }
    else if (entry->IsDungeon())
    {
        Group* group = player->GetGroup();
        Difficulty difficulty = group ? group->GetDifficultyID(entry) : player->GetDifficultyID(entry);
        MapDb2Entries entries{ entry, sDB2Manager.GetDownscaledMapDifficultyData(mapId, difficulty) };
        ObjectGuid instanceOwnerGuid = group ? group->GetRecentInstanceOwner(mapId) : player->GetGUID();
        InstanceLock* instanceLock = sInstanceLockMgr.FindActiveInstanceLock(instanceOwnerGuid, entries);
        if (instanceLock)
        {
            newInstanceId = instanceLock->GetInstanceId();

            // Reset difficulty to the one used in instance lock
            if (!entries.Map->IsFlexLocking())
                difficulty = instanceLock->GetDifficultyId();
        }
        else
        {
            // Try finding instance id for normal dungeon
            if (!entries.MapDifficulty->HasResetSchedule())
                newInstanceId = group ? group->GetRecentInstanceId(mapId) : player->GetRecentInstanceId(mapId);

            // If not found or instance is not a normal dungeon, generate new one
            if (!newInstanceId)
                newInstanceId = GenerateInstanceId();

            instanceLock = sInstanceLockMgr.CreateInstanceLockForNewInstance(instanceOwnerGuid, entries, newInstanceId);
        }

        // it is possible that the save exists but the map doesn't
        map = FindMap_i(mapId, newInstanceId);

        // is is also possible that instance id is already in use by another group for boss-based locks
        if (!entries.IsInstanceIdBound() && instanceLock && map && map->ToInstanceMap()->GetInstanceLock() != instanceLock)
        {
            newInstanceId = GenerateInstanceId();
            instanceLock->SetInstanceId(newInstanceId);
            map = nullptr;
        }

        if (!map)
        {
            map = CreateInstance(mapId, newInstanceId, instanceLock, difficulty, GetTeamIdForTeam(sCharacterCache->GetCharacterTeamByGuid(instanceOwnerGuid)), group);
            if (group)
                group->SetRecentInstance(mapId, instanceOwnerGuid, newInstanceId);
            else
                player->SetRecentInstance(mapId, newInstanceId);
        }
    }
    else if (entry->IsGarrison())
    {
        newInstanceId = player->GetGUID().GetCounter();
        map = FindMap_i(mapId, newInstanceId);
        if (!map)
            map = CreateGarrison(mapId, newInstanceId, player);
    }
    else
    {
        newInstanceId = 0;
        if (entry->IsSplitByFaction())
            newInstanceId = player->GetTeamId();

        map = FindMap_i(mapId, newInstanceId);
        if (!map)
            map = CreateWorldMap(mapId, newInstanceId);
    }

    if (map)
    {
        Trinity::unique_trackable_ptr<Map>& ptr = i_maps[{ map->GetId(), map->GetInstanceId() }];
        if (ptr.get() != map)
        {
            ptr.reset(map);
            map->SetWeakPtr(ptr);

            sScriptMgr->OnCreateMap(map);
            sOutdoorPvPMgr->CreateOutdoorPvPForMap(map);
            sBattlefieldMgr->CreateBattlefieldsForMap(map);
        }
    }

    return map;
}

Map* MapManager::FindMap(uint32 mapId, uint32 instanceId) const
{
    std::shared_lock<std::shared_mutex> lock(_mapsLock);
    return FindMap_i(mapId, instanceId);
}

uint32 MapManager::FindInstanceIdForPlayer(uint32 mapId, Player const* player) const
{
    MapEntry const* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
        return 0;

    if (entry->IsBattlegroundOrArena())
        return player->GetBattlegroundId();
    else if (entry->IsDungeon())
    {
        Group const* group = player->GetGroup();
        Difficulty difficulty = group ? group->GetDifficultyID(entry) : player->GetDifficultyID(entry);
        MapDb2Entries entries{ entry, sDB2Manager.GetDownscaledMapDifficultyData(mapId, difficulty) };
        ObjectGuid instanceOwnerGuid = group ? group->GetRecentInstanceOwner(mapId) : player->GetGUID();
        InstanceLock* instanceLock = sInstanceLockMgr.FindActiveInstanceLock(instanceOwnerGuid, entries);
        uint32 newInstanceId = 0;
        if (instanceLock)
            newInstanceId = instanceLock->GetInstanceId();
        else if (!entries.MapDifficulty->HasResetSchedule()) // Try finding instance id for normal dungeon
            newInstanceId = group ? group->GetRecentInstanceId(mapId) : player->GetRecentInstanceId(mapId);

        if (!newInstanceId)
            return 0;

        Map* map = FindMap(mapId, newInstanceId);

        // is is possible that instance id is already in use by another group for boss-based locks
        if (!entries.IsInstanceIdBound() && instanceLock && map && map->ToInstanceMap()->GetInstanceLock() != instanceLock)
            return 0;

        return newInstanceId;
    }
    else if (entry->IsGarrison())
        return uint32(player->GetGUID().GetCounter());
    else
    {
        if (entry->IsSplitByFaction())
            return player->GetTeamId();

        return 0;
    }
}

void MapManager::Update(uint32 diff)
{
    i_timer.Update(diff);
    if (!i_timer.Passed())
        return;

    MapMapType::iterator iter = i_maps.begin();
    while (iter != i_maps.end())
    {
        if (iter->second->CanUnload(uint32(i_timer.GetCurrent())))
        {
            if (DestroyMap(iter->second.get()))
                iter = i_maps.erase(iter);
            else
                ++iter;

            continue;
        }

        if (m_updater.activated())
            m_updater.schedule_update(*iter->second, uint32(i_timer.GetCurrent()));
        else
            iter->second->Update(uint32(i_timer.GetCurrent()));

        ++iter;
    }
    if (m_updater.activated())
        m_updater.wait();

    for (iter = i_maps.begin(); iter != i_maps.end(); ++iter)
        iter->second->DelayedUpdate(uint32(i_timer.GetCurrent()));

    i_timer.SetCurrent(0);
}

bool MapManager::DestroyMap(Map* map)
{
    map->RemoveAllPlayers();
    if (map->HavePlayers())
        return false;

    sOutdoorPvPMgr->DestroyOutdoorPvPForMap(map);
    sBattlefieldMgr->DestroyBattlefieldsForMap(map);
    sScriptMgr->OnDestroyMap(map);

    map->UnloadAll();

    // Free up the instance id and allow it to be reused for normal dungeons, bgs and arenas
    if (map->IsBattlegroundOrArena() || (map->IsDungeon() && !map->GetMapDifficulty()->HasResetSchedule()))
        sMapMgr->FreeInstanceId(map->GetInstanceId());

    // erase map
    return true;
}

bool MapManager::IsValidMAP(uint32 mapId)
{
    return sMapStore.LookupEntry(mapId) != nullptr;
}

void MapManager::UnloadAll()
{
    // first unload maps
    for (auto iter = i_maps.begin(); iter != i_maps.end(); ++iter)
    {
        iter->second->UnloadAll();

        sOutdoorPvPMgr->DestroyOutdoorPvPForMap(iter->second.get());
        sBattlefieldMgr->DestroyBattlefieldsForMap(iter->second.get());
        sScriptMgr->OnDestroyMap(iter->second.get());
    }

    // then delete them
    i_maps.clear();

    if (m_updater.activated())
        m_updater.deactivate();

    Map::DeleteStateMachine();
}

uint32 MapManager::GetNumInstances() const
{
    std::shared_lock<std::shared_mutex> lock(_mapsLock);
    return std::count_if(i_maps.begin(), i_maps.end(), [](MapMapType::value_type const& value) { return value.second->IsDungeon(); });
}

uint32 MapManager::GetNumPlayersInInstances() const
{
    std::shared_lock<std::shared_mutex> lock(_mapsLock);
    return std::accumulate(i_maps.begin(), i_maps.end(), 0u, [](uint32 total, MapMapType::value_type const& value) { return total + (value.second->IsDungeon() ? value.second->GetPlayers().getSize() : 0); });
}

void MapManager::InitInstanceIds()
{
    _nextInstanceId = 1;

    uint64 maxExistingInstanceId = 0;
    if (QueryResult result = CharacterDatabase.Query("SELECT IFNULL(MAX(instanceId), 0) FROM instance"))
        maxExistingInstanceId = std::max(maxExistingInstanceId, (*result)[0].GetUInt64());

    if (QueryResult result = CharacterDatabase.Query("SELECT IFNULL(MAX(instanceId), 0) FROM character_instance_lock"))
        maxExistingInstanceId = std::max(maxExistingInstanceId, (*result)[0].GetUInt64());

    _freeInstanceIds->resize(maxExistingInstanceId + 2, true); // make space for one extra to be able to access [_nextInstanceId] index in case all slots are taken

    // never allow 0 id
    _freeInstanceIds->set(0, false);
}

void MapManager::RegisterInstanceId(uint32 instanceId)
{
    // Allocation and sizing was done in InitInstanceIds()
    _freeInstanceIds->set(instanceId, false);

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
    ASSERT(newInstanceId < _freeInstanceIds->size());
    _freeInstanceIds->set(newInstanceId, false);

    // Find the lowest available id starting from the current NextInstanceId (which should be the lowest according to the logic in FreeInstanceId())
    size_t nextFreedId = _freeInstanceIds->find_next(_nextInstanceId++);
    if (nextFreedId == InstanceIds::npos)
    {
        _nextInstanceId = uint32(_freeInstanceIds->size());
        _freeInstanceIds->push_back(true);
    }
    else
        _nextInstanceId = uint32(nextFreedId);

    return newInstanceId;
}

void MapManager::FreeInstanceId(uint32 instanceId)
{
    // If freed instance id is lower than the next id available for new instances, use the freed one instead
    _nextInstanceId = std::min(instanceId, _nextInstanceId);
    _freeInstanceIds->set(instanceId, true);
}

// hack to allow conditions to access what faction owns the map (these worldstates should not be set on these maps)
class SplitByFactionMapScript : public WorldMapScript
{
public:
    SplitByFactionMapScript(char const* name, uint32 mapId) : WorldMapScript(name, mapId)
    {
    }

    void OnCreate(Map* map) override
    {
        sWorldStateMgr->SetValue(WS_TEAM_IN_INSTANCE_ALLIANCE, map->GetInstanceId() == TEAM_ALLIANCE, false, map);
        sWorldStateMgr->SetValue(WS_TEAM_IN_INSTANCE_HORDE, map->GetInstanceId() == TEAM_HORDE, false, map);
    }
};

void MapManager::AddSC_BuiltInScripts()
{
    for (MapEntry const* mapEntry : sMapStore)
        if (mapEntry->IsWorldMap() && mapEntry->IsSplitByFaction())
            new SplitByFactionMapScript(Trinity::StringFormat("world_map_set_faction_worldstates_{}", mapEntry->ID).c_str(), mapEntry->ID);
}
