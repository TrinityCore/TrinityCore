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

#include "MapInstanced.h"
#include "Battleground.h"
#include "DBCStores.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "MMapFactory.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "World.h"

MapInstanced::MapInstanced(uint32 id, time_t expiry) : Map(id, expiry, 0, DUNGEON_DIFFICULTY_NORMAL)
{
    // fill with zero
    memset(&GridMapReference, 0, MAX_NUMBER_OF_GRIDS*MAX_NUMBER_OF_GRIDS*sizeof(uint16));
}

void MapInstanced::InitVisibilityDistance()
{
    if (m_InstancedMaps.empty())
        return;
    //initialize visibility distances for all instance copies
    for (InstancedMaps::iterator i = m_InstancedMaps.begin(); i != m_InstancedMaps.end(); ++i)
    {
        (*i).second->InitVisibilityDistance();
    }
}

void MapInstanced::Update(uint32 t)
{
    // take care of loaded GridMaps (when unused, unload it!)
    Map::Update(t);

    // update the instanced maps
    InstancedMaps::iterator i = m_InstancedMaps.begin();

    while (i != m_InstancedMaps.end())
    {
        if (i->second->CanUnload(t))
        {
            if (!DestroyInstance(i))                             // iterator incremented
            {
                //m_unloadTimer
            }
        }
        else
        {
            // update only here, because it may schedule some bad things before delete
            if (sMapMgr->GetMapUpdater()->activated())
                sMapMgr->GetMapUpdater()->schedule_update(*i->second, t);
            else
                i->second->Update(t);
            ++i;
        }
    }
}

void MapInstanced::DelayedUpdate(uint32 diff)
{
    for (InstancedMaps::iterator i = m_InstancedMaps.begin(); i != m_InstancedMaps.end(); ++i)
        i->second->DelayedUpdate(diff);

    Map::DelayedUpdate(diff); // this may be removed
}

/*
void MapInstanced::RelocationNotify()
{
    for (InstancedMaps::iterator i = m_InstancedMaps.begin(); i != m_InstancedMaps.end(); ++i)
        i->second->RelocationNotify();
}
*/

void MapInstanced::UnloadAll()
{
    // Unload instanced maps
    for (InstancedMaps::iterator i = m_InstancedMaps.begin(); i != m_InstancedMaps.end(); ++i)
        i->second->UnloadAll();

    m_InstancedMaps.clear();

    // Unload own grids (just dummy(placeholder) grids, neccesary to unload GridMaps!)
    Map::UnloadAll();
}

/*
- return the right instance for the object, based on its InstanceId
- create the instance if it's not created already
- the player is not actually added to the instance (only in InstanceMap::Add)
*/
Map* MapInstanced::CreateInstanceForPlayer(uint32 mapId, Player* player, uint32 loginInstanceId /*= 0*/)
{
    if (GetId() != mapId || !player)
        return nullptr;

    Map* map = nullptr;
    uint32 newInstanceId = 0;                       // instanceId of the resulting map

    if (IsBattlegroundOrArena())
    {
        // instantiate or find existing bg map for player
        // the instance id is set in battlegroundid
        newInstanceId = player->GetBattlegroundId();
        if (!newInstanceId)
            return nullptr;

        map = sMapMgr->FindMap(mapId, newInstanceId);
        if (!map)
        {
            if (Battleground* bg = player->GetBattleground())
                map = CreateBattleground(newInstanceId, bg);
            else
            {
                player->TeleportToBGEntryPoint();
                return nullptr;
            }
        }
    }
    else
    {
        InstancePlayerBind* pBind = player->GetBoundInstance(GetId(), player->GetDifficulty(IsRaid()));
        InstanceSave* pSave = pBind ? pBind->save : nullptr;

        // priority:
        // 1. player's permanent bind
        // 2. player's current instance id if this is at login
        // 3. group's current bind
        // 4. player's current bind
        if (!pBind || !pBind->perm)
        {
            if (loginInstanceId) // if the player has a saved instance id on login, we either use this instance or relocate him out (return null)
            {
                map = FindInstanceMap(loginInstanceId);
                if (!map && pSave && pSave->GetInstanceId() == loginInstanceId)
                    map = CreateInstance(loginInstanceId, pSave, pSave->GetDifficulty(), player->GetTeamId());
                return map;
            }

            InstanceGroupBind* groupBind = nullptr;
            Group* group = player->GetGroup();
            // use the player's difficulty setting (it may not be the same as the group's)
            if (group)
            {
                groupBind = group->GetBoundInstance(this);
                if (groupBind)
                {
                    // solo saves should be reset when entering a group's instance
                    player->UnbindInstance(GetId(), player->GetDifficulty(IsRaid()));
                    pSave = groupBind->save;
                }
            }
        }
        if (pSave)
        {
            // solo/perm/group
            newInstanceId = pSave->GetInstanceId();
            map = FindInstanceMap(newInstanceId);
            // it is possible that the save exists but the map doesn't
            if (!map)
                map = CreateInstance(newInstanceId, pSave, pSave->GetDifficulty(), player->GetTeamId());
        }
        else
        {
            // if no instanceId via group members or instance saves is found
            // the instance will be created for the first time
            newInstanceId = sMapMgr->GenerateInstanceId();

            Difficulty diff = player->GetGroup() ? player->GetGroup()->GetDifficulty(IsRaid()) : player->GetDifficulty(IsRaid());
            //Seems it is now possible, but I do not know if it should be allowed
            //ASSERT(!FindInstanceMap(NewInstanceId));
            map = FindInstanceMap(newInstanceId);
            if (!map)
                map = CreateInstance(newInstanceId, nullptr, diff, player->GetTeamId());
        }
    }

    return map;
}

InstanceMap* MapInstanced::CreateInstance(uint32 InstanceId, InstanceSave* save, Difficulty difficulty, TeamId InstanceTeam)
{
    // load/create a map
    std::lock_guard<std::mutex> lock(_mapLock);

    // make sure we have a valid map id
    MapEntry const* entry = sMapStore.LookupEntry(GetId());
    if (!entry)
    {
        TC_LOG_ERROR("maps", "CreateInstance: no entry for map {}", GetId());
        ABORT();
    }
    InstanceTemplate const* iTemplate = sObjectMgr->GetInstanceTemplate(GetId());
    if (!iTemplate)
    {
        TC_LOG_ERROR("maps", "CreateInstance: no instance template for map {}", GetId());
        ABORT();
    }

    // some instances only have one difficulty
    GetDownscaledMapDifficultyData(GetId(), difficulty);

    TC_LOG_DEBUG("maps", "MapInstanced::CreateInstance: {} map instance {} for {} created with difficulty {}", save ? "" : "new ", InstanceId, GetId(), static_cast<uint32>(difficulty));

    InstanceMap* map = new InstanceMap(GetId(), GetGridExpiry(), InstanceId, difficulty, this, InstanceTeam);
    ASSERT(map->IsDungeon());

    map->LoadRespawnTimes();
    map->LoadCorpseData();

    bool load_data = save != nullptr;
    map->CreateInstanceData(load_data);

    if (sWorld->getBoolConfig(CONFIG_INSTANCEMAP_LOAD_GRIDS))
        map->LoadAllCells();

    Trinity::unique_trackable_ptr<Map>& ptr = m_InstancedMaps[InstanceId];
    ptr.reset(map);
    map->SetWeakPtr(ptr);
    return map;
}

BattlegroundMap* MapInstanced::CreateBattleground(uint32 InstanceId, Battleground* bg)
{
    // load/create a map
    std::lock_guard<std::mutex> lock(_mapLock);

    TC_LOG_DEBUG("maps", "MapInstanced::CreateBattleground: map bg {} for {} created.", InstanceId, GetId());

    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), bg->GetMinLevel());

    uint8 spawnMode;

    if (bracketEntry)
        spawnMode = bracketEntry->Difficulty;
    else
        spawnMode = REGULAR_DIFFICULTY;

    BattlegroundMap* map = new BattlegroundMap(GetId(), GetGridExpiry(), InstanceId, this, spawnMode);
    ASSERT(map->IsBattlegroundOrArena());
    map->SetBG(bg);
    bg->SetBgMap(map);

    Trinity::unique_trackable_ptr<Map>& ptr = m_InstancedMaps[InstanceId];
    ptr.reset(map);
    map->SetWeakPtr(ptr);
    return map;
}

// increments the iterator after erase
bool MapInstanced::DestroyInstance(InstancedMaps::iterator &itr)
{
    itr->second->RemoveAllPlayers();
    if (itr->second->HavePlayers())
    {
        ++itr;
        return false;
    }

    itr->second->UnloadAll();
    // should only unload VMaps if this is the last instance and grid unloading is enabled
    if (m_InstancedMaps.size() <= 1 && sWorld->getBoolConfig(CONFIG_GRID_UNLOAD))
    {
        VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(itr->second->GetId());
        MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(itr->second->GetId());
        // in that case, unload grids of the base map, too
        // so in the next map creation, (EnsureGridCreated actually) VMaps will be reloaded
        Map::UnloadAll();
    }

    // Free up the instance id and allow it to be reused for bgs and arenas (other instances are handled in the InstanceSaveMgr)
    if (itr->second->IsBattlegroundOrArena())
        sMapMgr->FreeInstanceId(itr->second->GetInstanceId());

    // erase map
    m_InstancedMaps.erase(itr++);

    return true;
}

Map::EnterState MapInstanced::CannotEnter(Player* /*player*/)
{
    //ABORT();
    return CAN_ENTER;
}
