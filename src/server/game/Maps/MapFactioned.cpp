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

#include "MapFactioned.h"
#include "Log.h"
#include "MapManager.h"
#include "MMapFactory.h"
#include "VMapManager2.h"
#include "World.h"

MapFactioned::MapFactioned(uint32 id, time_t expiry) : Map(id, expiry, 0, DIFFICULTY_NONE)
{
}

MapFactioned::~MapFactioned() = default;

void MapFactioned::InitVisibilityDistance()
{
    if (_factionedMaps.empty())
        return;

    //initialize visibility distances for all instance copies
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        (*i).second->InitVisibilityDistance();
}

void MapFactioned::Update(uint32 t)
{
    // take care of loaded GridMaps (when unused, unload it!)
    Map::Update(t);

    // update the instanced maps
    FactionedMaps::iterator i = _factionedMaps.begin();

    while (i != _factionedMaps.end())
    {
        if (sMapMgr->GetMapUpdater()->activated())
            sMapMgr->GetMapUpdater()->schedule_update(*i->second, t);
        else
            i->second->Update(t);

        ++i;
    }
}

void MapFactioned::DelayedUpdate(uint32 diff)
{
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        i->second->DelayedUpdate(diff);

    Map::DelayedUpdate(diff); // this may be removed
}

void MapFactioned::RemoveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans, bool alwaysDeleteFromDB)
{
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        i->second->RemoveRespawnTime(type, spawnId, dbTrans, alwaysDeleteFromDB);
}

void MapFactioned::CreateGameobject(ObjectGuid::LowType spawnId, bool addToMap, Position const& spawnPoint)
{
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        if (i->second->IsGridLoaded(spawnPoint))
            i->second->CreateGameobject(spawnId, addToMap, spawnPoint);
}

void MapFactioned::CreateCreature(ObjectGuid::LowType spawnId, bool addToMap, Position const& spawnPoint)
{
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        if (i->second->IsGridLoaded(spawnPoint))
            i->second->CreateCreature(spawnId, addToMap, spawnPoint);
}

void MapFactioned::UnloadAll()
{
    // Unload instanced maps
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        i->second->UnloadAll();

    // Delete the maps only after everything is unloaded to prevent crashes
    for (FactionedMaps::iterator i = _factionedMaps.begin(); i != _factionedMaps.end(); ++i)
        delete i->second;

    _factionedMaps.clear();

    // Unload own grids (just dummy(placeholder) grids, neccesary to unload GridMaps!)
    Map::UnloadAll();
}

Map* MapFactioned::CreateFactionMapForTeam(uint32 mapId, TeamId teamId)
{
    if (GetId() != mapId)
        return nullptr;

    Map* map = FindFactionMap(teamId);
    if (!map)
        map = CreateFactionMap(teamId);

    return map;
}

Map* MapFactioned::CreateFactionMap(TeamId teamId)
{
    // load/create a map
    std::lock_guard<std::mutex> lock(_mapLock);

    TC_LOG_DEBUG("maps", "MapFactioned::CreateFactionMap: new map instance %d created for team %s", GetId(), teamId == TEAM_ALLIANCE ? "ALLIANCE" : "HORDE");

    // We use TeamId as InstanceId to prevent meddling with MMAP Reference Counts
    Map* map = new Map(GetId(), GetGridExpiry(), teamId, DIFFICULTY_NONE, this, teamId);
    ASSERT(map->IsFactioned());

    map->LoadRespawnTimes();
    map->LoadCorpseData();

    if (sWorld->getBoolConfig(CONFIG_BASEMAP_LOAD_GRIDS))
        map->LoadAllCells();

    _factionedMaps[teamId] = map;
    return map;
}
