/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#include "MapPersistentStateMgr.h"

#include "Player.h"
#include "GridNotifiers.h"
#include "Log.h"
#include "GridStates.h"
#include "CellImpl.h"
#include "MapManager.h"
#include "Timer.h"
#include "GridNotifiersImpl.h"
#include "Transport.h"
#include "ObjectMgr.h"
#include "GameEventMgr.h"
#include "World.h"
#include "Group.h"
#include "InstanceData.h"
#include "ProgressBar.h"

INSTANTIATE_SINGLETON_1(MapPersistentStateManager);

static uint32 resetEventTypeDelay[MAX_RESET_EVENT_TYPE] = { 0,                      // not used
                                                            3600, 900, 300, 60,     // (seconds) normal and official timer delay to inform player about instance reset
                                                            60, 30, 10, 5           // (seconds) fast reset by gm command inform timer
};

//== MapPersistentState functions ==========================
MapPersistentState::MapPersistentState(uint16 MapId, uint32 InstanceId)
    : m_instanceid(InstanceId), m_mapid(MapId),
      m_usedByMap(nullptr)
{
}

MapPersistentState::~MapPersistentState()
{
}

MapEntry const* MapPersistentState::GetMapEntry() const
{
    if (m_usedByMap)
        return m_usedByMap->GetMapEntry();

    return sMapStorage.LookupEntry<MapEntry>(m_mapid);
}

/* true if the instance state is still valid */
bool MapPersistentState::UnloadIfEmpty()
{
    if (CanBeUnload())
    {
        sMapPersistentStateMgr.RemovePersistentState(GetMapId(), GetInstanceId());
        return false;
    }
    else
        return true;
}

void MapPersistentState::SaveCreatureRespawnTime(uint32 loguid, time_t t)
{
    SetCreatureRespawnTime(loguid, t);

    // BGs/Arenas always reset at server restart/unload, so no reason store in DB
    if (GetMapEntry()->IsBattleGround())
        return;
    static SqlStatementID delSpawnTime;
    static SqlStatementID replSpawnTime;


    if (t > sWorld.GetGameTime())
    {
        SqlStatement stmt = CharacterDatabase.CreateStatement(replSpawnTime, "REPLACE INTO `creature_respawn` (`guid`, `respawn_time`, `instance`, `map`) VALUES ( ?, ?, ?, ?)");
        stmt.PExecute(loguid, uint64(t), m_instanceid, GetMapId());
    }
    else
    {
        SqlStatement stmt = CharacterDatabase.CreateStatement(delSpawnTime, "DELETE FROM `creature_respawn` WHERE `guid` = ? AND `instance` = ?");
        stmt.PExecute(loguid, m_instanceid);
    }
}

void MapPersistentState::SaveGORespawnTime(uint32 loguid, time_t t)
{
    SetGORespawnTime(loguid, t);

    // BGs/Arenas always reset at server restart/unload, so no reason store in DB
    if (GetMapEntry()->IsBattleGround())
        return;
    static SqlStatementID delSpawnTime;
    static SqlStatementID replSpawnTime;

    if (t > sWorld.GetGameTime())
    {
        SqlStatement stmt = CharacterDatabase.CreateStatement(replSpawnTime, "REPLACE INTO `gameobject_respawn` (`guid`, `respawn_time`, `instance`, `map`) VALUES ( ?, ?, ?, ?)");
        stmt.PExecute(loguid, uint64(t), m_instanceid, GetMapId());
    }
    else
    {
        SqlStatement stmt = CharacterDatabase.CreateStatement(delSpawnTime, "DELETE FROM `gameobject_respawn` WHERE `guid` = ? AND `instance` = ?");
        stmt.PExecute(loguid, m_instanceid);
    }
}

void MapPersistentState::SetCreatureRespawnTime(uint32 loguid, time_t t)
{
    if (t > sWorld.GetGameTime())
        m_creatureRespawnTimes[loguid] = t;
    else
    {
        m_creatureRespawnTimes.erase(loguid);
        UnloadIfEmpty();
    }
}

void MapPersistentState::SetGORespawnTime(uint32 loguid, time_t t)
{
    if (t > sWorld.GetGameTime())
        m_goRespawnTimes[loguid] = t;
    else
    {
        m_goRespawnTimes.erase(loguid);
        UnloadIfEmpty();
    }
}

void MapPersistentState::ClearRespawnTimes()
{
    m_goRespawnTimes.clear();
    m_creatureRespawnTimes.clear();

    UnloadIfEmpty();
}

void MapPersistentState::AddCreatureToGrid(uint32 guid, CreatureData const* data)
{
    CellPair cell_pair = MaNGOS::ComputeCellPair(data->position.x, data->position.y);
    uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    m_gridObjectGuids[cell_id].creatures.insert(guid);
}

void MapPersistentState::RemoveCreatureFromGrid(uint32 guid, CreatureData const* data)
{
    CellPair cell_pair = MaNGOS::ComputeCellPair(data->position.x, data->position.y);
    uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    m_gridObjectGuids[cell_id].creatures.erase(guid);
}

void MapPersistentState::AddGameobjectToGrid(uint32 guid, GameObjectData const* data)
{
    CellPair cell_pair = MaNGOS::ComputeCellPair(data->position.x, data->position.y);
    uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    m_gridObjectGuids[cell_id].gameobjects.insert(guid);
}

void MapPersistentState::RemoveGameobjectFromGrid(uint32 guid, GameObjectData const* data)
{
    CellPair cell_pair = MaNGOS::ComputeCellPair(data->position.x, data->position.y);
    uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    m_gridObjectGuids[cell_id].gameobjects.erase(guid);
}

void MapPersistentState::InitPools()
{
    // pool system initialized already for persistent state (can be shared by map states)
    if (!GetSpawnedPoolData().IsInitialized())
    {
        GetSpawnedPoolData().SetInitialized();
        sPoolMgr.Initialize(this);                          // init pool system data for map persistent state
        sGameEventMgr.Initialize(this);                     // init pool system data for map persistent state
    }
}

//== WorldPersistentState functions ========================

bool WorldPersistentState::CanBeUnload() const
{
    // prevent unload if used for loaded map
    // prevent unload if respawn data still exist (will not prevent reset by scheduler)
    // Note: non instanceable Map never unload until server shutdown and in result for loaded non-instanceable maps map persistent states also not unloaded
    //       but for proper work pool systems with shared pools state for non-instanceable maps need
    //       load persistent map states for any non-instanceable maps before Map loading and make sure that it never unloaded
    return /*MapPersistentState::CanBeUnload() && !HasRespawnTimes()*/ false;
}

//== DungeonPersistentState functions =====================

DungeonPersistentState::DungeonPersistentState(uint16 MapId, uint32 InstanceId, time_t resetTime, bool canReset)
    : MapPersistentState(MapId, InstanceId), m_resetTime(resetTime), m_canReset(canReset)
{
    ASSERT(MapId > 1);
}

DungeonPersistentState::~DungeonPersistentState()
{
    UnbindThisState();
}

void DungeonPersistentState::UnbindThisState()
{
    while (!m_playerList.empty())
    {
        Player* player = *(m_playerList.begin());
        player->UnbindInstance(GetMapId(), true);
    }
    while (!m_groupList.empty())
    {
        Group* group = *(m_groupList.begin());
        group->UnbindInstance(GetMapId(), true);
    }
}

bool DungeonPersistentState::CanBeUnload() const
{
    // prevent unload if any bounded groups or online bounded player still exists
    return MapPersistentState::CanBeUnload() && !HasBounds() && !HasRespawnTimes();
}

/*
    Called from AddPersistentState
*/
void DungeonPersistentState::SaveToDB()
{
    // state instance data too
    std::string data;

    if (Map* map = GetMap())
    {
        InstanceData *iData = map->GetInstanceData();
        if (iData && iData->Save())
        {
            data = iData->Save();
            CharacterDatabase.escape_string(data);
        }
    }

    CharacterDatabase.PExecute("INSERT INTO `instance` VALUES ('%u', '%u', '" UI64FMTD "', '%s')", GetInstanceId(), GetMapId(), (uint64)GetResetTimeForDB(), data.c_str());
}

void DungeonPersistentState::DeleteRespawnTimesAndData()
{
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM `creature_respawn` WHERE `instance` = '%u'", GetInstanceId());
    CharacterDatabase.PExecute("DELETE FROM `gameobject_respawn` WHERE `instance` = '%u'", GetInstanceId());
    CharacterDatabase.PExecute("UPDATE `instance` SET `data` = '' WHERE `id` = '%u'", GetInstanceId());
    CharacterDatabase.CommitTransaction();

    ClearRespawnTimes();                                    // state can be deleted at call if only respawn data prevent unload
}

void DungeonPersistentState::DeleteFromDB()
{
    MapPersistentStateManager::DeleteInstanceFromDB(GetMapId(), GetInstanceId());
}

time_t DungeonPersistentState::GetResetTimeForDB() const
{
    // only state the reset time for normal instances
    MapEntry const* entry = GetMapEntry();
    if (!entry || entry->mapType == MAP_RAID)
        return 0;
    else
        return GetResetTime();
}

//== BattleGroundPersistentState functions =================

bool BattleGroundPersistentState::CanBeUnload() const
{
    // prevent unload if used for loaded map
    // BGs/Arenas not locked by respawn data/etc
    return MapPersistentState::CanBeUnload();
}

//== DungeonResetScheduler functions ======================

uint32 DungeonResetScheduler::GetMaxResetTimeFor(MapEntry const* temp)
{
    if (!temp)
        return 0;

    return temp->resetDelay * DAY;
}

time_t DungeonResetScheduler::CalculateNextResetTime(MapEntry const* temp, time_t prevResetTime)
{
    uint32 diff = sWorld.getConfig(CONFIG_UINT32_INSTANCE_RESET_TIME_HOUR) * HOUR;
    uint32 period = GetMaxResetTimeFor(temp);
    return ((prevResetTime + MINUTE) / DAY * DAY) + period + diff;
}

void DungeonResetScheduler::LoadResetTimes()
{
    time_t now = time(nullptr);
    // NOTE: Use DirectPExecute for tables that will be queried later

    // get the current reset times for normal instances (these may need to be updated)
    // these are only kept in memory for InstanceSaves that are loaded later
    // reset_time = 0 in the DB for raid instances so those are skipped

    // NOTE: We _CANNOT_ schedule normal dungeon resets here, since the instance IDs
    // are remapped in PackInstances(). Scheduling normal dungeon resets here leads
    // to raid dungeons being reset if the raid ID is remapped to that of a normal
    // dungeon. This leads to further issues with players being allocated lockouts
    // for random dungeons as we allocate the cleared IDs for future instances, since
    // the player bindings will remain due to the wrong mapId being reset.
    // _____BAD_____
    ResetTimeMapType InstResetTime;

    QueryResult* result = CharacterDatabase.Query("SELECT `id`, `map`, `reset_time` FROM `instance`");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint32 mapId = fields[1].GetUInt32();
            time_t resetTime = time_t(fields[2].GetUInt64());

            MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);

            if (!mapEntry || !mapEntry->IsDungeon())
            {
                sMapPersistentStateMgr.DeleteInstanceFromDB(mapId, id);
                continue;
            }

            // Don't set or update reset time for raid instances
            if (mapEntry->IsRaid())
                continue;

            InstResetTime[id] = std::pair<uint32, uint64>(mapId,
                resetTime ? resetTime : now + 2 * HOUR);
        }
        while (result->NextRow());
        delete result;

        // update reset time for normal instances with the max creature respawn time + X hours
        result = CharacterDatabase.Query("SELECT MAX(`respawn_time`), `instance` FROM `creature_respawn` WHERE `instance` > 0 GROUP BY `instance`");
        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 instance = fields[1].GetUInt32();
                time_t resetTime = time_t(fields[0].GetUInt64() + 2 * HOUR);
                ResetTimeMapType::iterator itr = InstResetTime.find(instance);
                if (itr != InstResetTime.end() && itr->second.second != resetTime)
                {
                    CharacterDatabase.DirectPExecute("UPDATE `instance` SET `reset_time` = '" UI64FMTD "' WHERE `id` = '%u'", uint64(resetTime), instance);
                    itr->second.second = resetTime;
                }
            }
            while (result->NextRow());
            delete result;
        }
    }

    // load the global respawn times for raid instances
    uint32 diff = sWorld.getConfig(CONFIG_UINT32_INSTANCE_RESET_TIME_HOUR) * HOUR;
    m_resetTimeByMapId.resize(sMapStorage.GetMaxEntry() + 1);
    result = CharacterDatabase.Query("SELECT `map`, `reset_time` FROM `instance_reset`");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 mapId = fields[0].GetUInt32();

            MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);

            if (!mapEntry || !mapEntry->IsDungeon())
            {
                sLog.outError("MapPersistentStateManager::LoadResetTimes: invalid map Id %u in instance_reset!", mapId);
                CharacterDatabase.DirectPExecute("DELETE FROM `instance_reset` WHERE `map` = '%u'", mapId);
                continue;
            }

            // update the reset time if the hour in the configs changes
            uint64 oldresettime = fields[1].GetUInt64();
            uint64 newresettime = (oldresettime / DAY) * DAY + diff;
            if (oldresettime != newresettime)
                CharacterDatabase.DirectPExecute("UPDATE `instance_reset` SET `reset_time` = '" UI64FMTD "' WHERE `map` = '%u'", newresettime, mapId);

            SetResetTimeFor(mapId, newresettime);
        }
        while (result->NextRow());
        delete result;
    }

    // clean expired instances, references to them will be deleted in CleanupInstances
    // must be done before calculating new reset times
    m_InstanceSaves._CleanupExpiredInstancesAtTime(now);
}

void DungeonResetScheduler::ScheduleAllDungeonResets()
{
    ResetTimeMapType InstResetTime;

    time_t now = time(nullptr);
    time_t today = (now / DAY) * DAY;

    // Reset times have already been updated and set in LoadResetTimes(). We just need to start
    // the initial reset events based on them. Since LoadResetTimes() is called before
    // PackInstances(), it cannot be done there.
    QueryResult* result = CharacterDatabase.Query("SELECT `id`, `map`, `reset_time` FROM `instance`");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint32 mapId = fields[1].GetUInt32();
            time_t resetTime = time_t(fields[2].GetUInt64());

            // Raids or other maps with a global reset timer
            if (!resetTime)
                continue;

            InstResetTime[id] = std::pair<uint32, time_t>(mapId, resetTime);
        } while (result->NextRow());
        delete result;
    }

    for (const auto& itr : InstResetTime)
    {
        ScheduleReset(true, itr.second.second, DungeonResetEvent(RESET_EVENT_NORMAL_DUNGEON, itr.second.first, itr.first));

        if (now > itr.second.second)
            sLog.outInfo("[DungeonReset] Instance %u (map %u) has reset time before now, but was not cleaned up. Likely expired during load",
                itr.first, itr.second.first);
    }

    uint32 diff = sWorld.getConfig(CONFIG_UINT32_INSTANCE_RESET_TIME_HOUR) * HOUR;
    // calculate new global reset times for expired instances and those that have never been reset yet
    // add the global reset times to the priority queue
    for (auto itr = sMapStorage.begin<MapEntry>(); itr < sMapStorage.end<MapEntry>(); ++itr)
    {
        // only raid maps have a global reset time
        if (!itr->IsDungeon() || !itr->resetDelay)
            continue;

        uint32 period = GetMaxResetTimeFor(*itr);
        time_t t = GetResetTimeFor(itr->id);
        if (!t)
        {
            // initialize the reset time
            t = today + period + diff;
            CharacterDatabase.DirectPExecute("INSERT INTO `instance_reset` VALUES ('%u','" UI64FMTD "')", itr->id, (uint64)t);
        }

        if (t < now)
        {
            // assume that expired instances have already been cleaned
            // calculate the next reset time
            t = (t / DAY) * DAY;
            t += ((today - t) / period + 1) * period + diff;
            CharacterDatabase.DirectPExecute("UPDATE `instance_reset` SET `reset_time` = '" UI64FMTD "' WHERE `map` = '%u'", (uint64)t, itr->id);
        }

        SetResetTimeFor(itr->id, t);

        // schedule the global reset/warning
        ResetEventType type = RESET_EVENT_INFORM_1;
        for (; type < RESET_EVENT_INFORM_LAST; type = ResetEventType(type + 1))
            if (t - resetEventTypeDelay[type] > now)
                break;

        ScheduleReset(true, t - resetEventTypeDelay[type], DungeonResetEvent(type, itr->id, 0));
    }
}

void DungeonResetScheduler::ScheduleReset(bool add, time_t time, DungeonResetEvent event)
{
    MapPersistentStateManager::PersistentStateMap::iterator itr = m_InstanceSaves.m_instanceSaveByInstanceId.find(event.instanceId);
    if (itr == m_InstanceSaves.m_instanceSaveByInstanceId.end())
        sLog.outInfo("[DungeonReset] Instance %u [map %u]: ScheduleReset %u for unknown instance.", event.instanceId, event.mapId, event.type);
    else if (itr->second->GetMapId() != event.mapId)
        sLog.outInfo("[DungeonReset] Instance %u [map %u]: ScheduleReset %u for wrong instance [map %u]", event.instanceId, event.mapId, event.type, itr->second->GetMapId());

    if (add)
        m_resetTimeQueue.insert(std::pair<time_t, DungeonResetEvent>(time, event));
    else
    {
        // find the event in the queue and remove it
        ResetTimeQueue::iterator itr;
        std::pair<ResetTimeQueue::iterator, ResetTimeQueue::iterator> range;
        range = m_resetTimeQueue.equal_range(time);
        for (itr = range.first; itr != range.second; ++itr)
        {
            if (itr->second == event)
            {
                m_resetTimeQueue.erase(itr);
                return;
            }
        }
        // in case the reset time changed (should happen very rarely), we search the whole queue
        if (itr == range.second)
        {
            for (itr = m_resetTimeQueue.begin(); itr != m_resetTimeQueue.end(); ++itr)
            {
                if (itr->second == event)
                {
                    m_resetTimeQueue.erase(itr);
                    return;
                }
            }

            if (itr == m_resetTimeQueue.end())
                sLog.outError("DungeonResetScheduler::ScheduleReset: cannot cancel the reset, the event(%d,%d,%d) was not found!", event.type, event.mapId, event.instanceId);
        }
    }
}

void DungeonResetScheduler::Update()
{
    time_t now = time(nullptr), t;
    while (!m_resetTimeQueue.empty() && (t = m_resetTimeQueue.begin()->first) < now)
    {
        DungeonResetEvent &event = m_resetTimeQueue.begin()->second;
        if (event.type == RESET_EVENT_NORMAL_DUNGEON)
        {
            // for individual normal instances, max creature respawn + X hours
            m_InstanceSaves._ResetInstance(event.mapId, event.instanceId);
        }
        else
        {
            // global reset/warning for a certain map
            time_t resetTime = GetResetTimeFor(event.mapId);
            uint32 timeLeft = uint32(std::max(int32(resetTime - now), 0));
            bool warn = event.type != RESET_EVENT_INFORM_LAST && event.type != RESET_EVENT_FORCED_INFORM_LAST;
            m_InstanceSaves._ResetOrWarnAll(event.mapId, warn, timeLeft);
            if (event.type != RESET_EVENT_INFORM_LAST && event.type != RESET_EVENT_FORCED_INFORM_LAST)
            {
                // schedule the next warning/reset
                event.type = ResetEventType(event.type + 1);
                ScheduleReset(true, resetTime - resetEventTypeDelay[event.type], event);
            }
            else
            {
                // re-schedule the next/new global reset/warning
                // calculate the next reset time
                MapEntry const* instanceTemplate = sMapStorage.LookupEntry<MapEntry>(event.mapId);
                MANGOS_ASSERT(instanceTemplate);

                time_t next_reset = DungeonResetScheduler::CalculateNextResetTime(instanceTemplate, resetTime);

                CharacterDatabase.DirectPExecute("UPDATE `instance_reset` SET `reset_time` = '" UI64FMTD "' WHERE `map` = '%u'", uint64(next_reset), uint32(event.mapId));

                SetResetTimeFor(event.mapId, next_reset);

                ResetEventType type = RESET_EVENT_INFORM_1;
                for (; type < RESET_EVENT_INFORM_LAST; type = ResetEventType(type + 1))
                    if (next_reset - resetEventTypeDelay[type] > now)
                        break;

                // add new scheduler event to the queue
                event.type = type;
                ScheduleReset(true, next_reset - resetEventTypeDelay[event.type], event);
            }
        }
        m_resetTimeQueue.erase(m_resetTimeQueue.begin());
    }
}

void DungeonResetScheduler::ResetAllRaid()
{
    time_t now = time(nullptr);
    ResetTimeQueue rTQ;
    rTQ.clear();

    time_t timeleft = resetEventTypeDelay[RESET_EVENT_FORCED_INFORM_1];

    for (auto& itr : m_resetTimeQueue)
    {
        DungeonResetEvent& event = itr.second;

        // we only reset raid dungeon
        if (event.type == RESET_EVENT_NORMAL_DUNGEON)
        {
            rTQ.insert(std::pair<time_t, DungeonResetEvent>(itr.first, event));
            continue;
        }
        event.type = RESET_EVENT_FORCED_INFORM_1;
        time_t next_reset = now + timeleft;
        SetResetTimeFor(event.mapId, next_reset);
        rTQ.insert(std::pair<time_t, DungeonResetEvent>(now, event));
    }
    m_resetTimeQueue = rTQ;
}

//== MapPersistentStateManager functions =========================

MapPersistentStateManager::MapPersistentStateManager() : lock_instLists(false), m_Scheduler(*this)
{
}

MapPersistentStateManager::~MapPersistentStateManager()
{
    // it is undefined whether this or objectmgr will be unloaded first
    // so we must be prepared for both cases
    lock_instLists = true;
    for (const auto& itr : m_instanceSaveByInstanceId)
        delete  itr.second;
    for (const auto& itr : m_instanceSaveByMapId)
        delete  itr.second;
}

/*
- adding instance into manager
- called from DungeonMap::Add, _LoadBoundInstances, LoadGroups
*/
MapPersistentState* MapPersistentStateManager::AddPersistentState(MapEntry const* mapEntry, uint32 instanceId, time_t resetTime, bool canReset, bool load /*=false*/, bool initPools /*= true*/)
{
    if (MapPersistentState *old_save = GetPersistentState(mapEntry->id, instanceId))
    {
        if (instanceId && old_save->GetMapId() != mapEntry->id)
            sLog.outError("MapPersistentStateManager::AddPersistentState: instance %u has existing map ID '%u', but map to add for is '%u'. Mismatched states are loaded",
                instanceId, old_save->GetMapId(), mapEntry->id);

        return old_save;
    }

    DEBUG_LOG("MapPersistentStateManager::AddPersistentState: mapId = %d, instanceId = %d, reset time = %u, canRset = %u", mapEntry->id, instanceId, resetTime, canReset ? 1 : 0);

    MapPersistentState *state;
    if (mapEntry->IsDungeon())
    {
        DungeonPersistentState* dungeonState = new DungeonPersistentState(mapEntry->id, instanceId, resetTime, canReset);
        if (!load)
        {
            // initialize reset time
            // for normal instances if no creatures are killed the instance will reset in two hours
            if (mapEntry->mapType != MAP_RAID)
            {
                if (!resetTime)
                    resetTime = time(nullptr) + 2 * HOUR;
                dungeonState->SetResetTime(resetTime);
                // Schedule a reset for new instances, removed when a player enters in DungeonMap::Add
                m_Scheduler.ScheduleReset(true, resetTime, DungeonResetEvent(RESET_EVENT_NORMAL_DUNGEON, mapEntry->id, instanceId));
            }
            dungeonState->SaveToDB();
        }
        state = dungeonState;
    }
    else if (mapEntry->IsBattleGround())
        state = new BattleGroundPersistentState(mapEntry->id, instanceId);
    else
        state = new WorldPersistentState(mapEntry->id, instanceId);

    if (instanceId)
        m_instanceSaveByInstanceId[instanceId] = state;
    else
        m_instanceSaveByMapId[mapEntry->id] = state;

    if (initPools)
        state->InitPools();

    return state;
}

MapPersistentState *MapPersistentStateManager::GetPersistentState(uint32 mapId, uint32 instanceId)
{
    if (instanceId)
    {
        PersistentStateMap::iterator itr = m_instanceSaveByInstanceId.find(instanceId);
        return itr != m_instanceSaveByInstanceId.end() ? itr->second : nullptr;
    }
    else
    {
        PersistentStateMap::iterator itr = m_instanceSaveByMapId.find(mapId);
        return itr != m_instanceSaveByMapId.end() ? itr->second : nullptr;
    }
}

void MapPersistentStateManager::DeleteInstanceFromDB(uint32 mapId, uint32 instanceId)
{
    // TODO: An efficient query which ensures that we are only deleting instance data
    // if the mapId is correct (otherwise, we just assume the map is correct - which it _should_ be)
    // eg. DELETE FROM character_instance WHERE instance = '101' AND EXISTS (SELECT id FROM instance WHERE id = '101' AND map = '429');
    if (instanceId)
    {
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM `instance` WHERE `id` = '%u'", instanceId);
        CharacterDatabase.PExecute("DELETE FROM `character_instance` WHERE `instance` = '%u'", instanceId);
        CharacterDatabase.PExecute("DELETE FROM `group_instance` WHERE `instance` = '%u'", instanceId);
        CharacterDatabase.PExecute("DELETE FROM `creature_respawn` WHERE `instance` = '%u'", instanceId);
        CharacterDatabase.PExecute("DELETE FROM `gameobject_respawn` WHERE `instance` = '%u'", instanceId);
        CharacterDatabase.CommitTransaction();
    }
}

void MapPersistentStateManager::RemovePersistentState(uint32 mapId, uint32 instanceId)
{
    if (lock_instLists)
        return;

    if (instanceId)
    {
        PersistentStateMap::iterator itr = m_instanceSaveByInstanceId.find(instanceId);
        if (itr != m_instanceSaveByInstanceId.end())
            _ResetSave(m_instanceSaveByInstanceId, itr);
    }
    else
    {
        PersistentStateMap::iterator itr = m_instanceSaveByMapId.find(mapId);
        if (itr != m_instanceSaveByMapId.end())
            _ResetSave(m_instanceSaveByMapId, itr);
    }
}

void MapPersistentStateManager::_DelHelper(DatabaseType &db, char const* fields, char const* table, char const* queryTail, ...)
{
    Tokens fieldTokens = StrSplit(fields, ", ");
    MANGOS_ASSERT(!fieldTokens.empty());

    va_list ap;
    char szQueryTail [MAX_QUERY_LEN];
    va_start(ap, queryTail);
    vsnprintf(szQueryTail, MAX_QUERY_LEN, queryTail, ap);
    va_end(ap);

    QueryResult* result = db.PQuery("SELECT %s FROM %s %s", fields, table, szQueryTail);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            std::ostringstream ss;
            for (size_t i = 0; i < fieldTokens.size(); i++)
            {
                std::string fieldValue = fields[i].GetCppString();
                db.escape_string(fieldValue);
                ss << (i != 0 ? " AND " : "") << fieldTokens[i] << " = '" << fieldValue << "'";
            }
            db.PExecute("DELETE FROM %s WHERE %s", table, ss.str().c_str());
        }
        while (result->NextRow());
        delete result;
    }
}

void MapPersistentStateManager::CleanupInstances()
{
    BarGoLink bar(2);
    bar.step();

    // load reset times and clean expired instances
    m_Scheduler.LoadResetTimes();

    CharacterDatabase.BeginTransaction();
    // clean character/group - instance binds with invalid group/characters
    _DelHelper(CharacterDatabase, "character_instance.guid, instance", "character_instance", "LEFT JOIN characters ON character_instance.guid = characters.guid WHERE characters.guid IS NULL");
    _DelHelper(CharacterDatabase, "group_instance.leader_guid, instance", "group_instance", "LEFT JOIN characters ON group_instance.leader_guid = characters.guid LEFT JOIN `groups` ON group_instance.leader_guid = `groups`.leader_guid WHERE characters.guid IS NULL OR `groups`.leader_guid IS NULL");

    // clean instances that do not have any players or groups bound to them
    _DelHelper(CharacterDatabase, "id, map", "instance", "LEFT JOIN character_instance ON character_instance.instance = id LEFT JOIN group_instance ON group_instance.instance = id WHERE character_instance.instance IS NULL AND group_instance.instance IS NULL");

    // clean invalid instance references in other tables
    _DelHelper(CharacterDatabase, "character_instance.guid, instance", "character_instance", "LEFT JOIN instance ON character_instance.instance = instance.id WHERE instance.id IS NULL");
    _DelHelper(CharacterDatabase, "group_instance.leader_guid, instance", "group_instance", "LEFT JOIN instance ON group_instance.instance = instance.id WHERE instance.id IS NULL");

    // clean unused respawn data
    CharacterDatabase.PExecute("DELETE FROM `creature_respawn` WHERE `instance` >= %u AND `instance` NOT IN (SELECT `id` FROM `instance`)", RESERVED_INSTANCES_LAST);
    CharacterDatabase.PExecute("DELETE FROM `gameobject_respawn` WHERE `instance` >= %u AND `instance` NOT IN (SELECT `id` FROM `instance`)", RESERVED_INSTANCES_LAST);
    //execute transaction directly
    CharacterDatabase.CommitTransaction();

    bar.step();
    sLog.outString();
    sLog.outString(">> Instances cleaned up");
}

void MapPersistentStateManager::PackInstances()
{
    // this routine renumbers player instance associations in such a way so they start from 1 and go up
    // TODO: this can be done a LOT more efficiently

    // obtain set of all associations
    std::set<uint32> InstanceSet;

    // all valid ids are in the instance table
    // any associations to ids not in this table are assumed to be
    // cleaned already in CleanupInstances
    CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("UPDATE `instance` SET `id` = `id` + %u ORDER BY `id` DESC", RESERVED_INSTANCES_LAST);
        CharacterDatabase.PExecute("UPDATE `creature_respawn` SET `instance` = `instance` + %u WHERE `instance` >= %u ORDER BY `instance` DESC", RESERVED_INSTANCES_LAST, RESERVED_INSTANCES_LAST);
        CharacterDatabase.PExecute("UPDATE `gameobject_respawn` SET `instance` = `instance` + %u WHERE `instance` >= %u ORDER BY `instance` DESC", RESERVED_INSTANCES_LAST, RESERVED_INSTANCES_LAST);
        CharacterDatabase.PExecute("UPDATE `corpse` SET `instance` = `instance` + %u WHERE `instance` >= 0 ORDER BY `instance` DESC", RESERVED_INSTANCES_LAST, RESERVED_INSTANCES_LAST);
        CharacterDatabase.PExecute("UPDATE `character_instance` SET `instance` = `instance` + %u WHERE `instance` >= 0 ORDER BY `instance` DESC", RESERVED_INSTANCES_LAST, RESERVED_INSTANCES_LAST);
        CharacterDatabase.PExecute("UPDATE `group_instance` SET `instance` = `instance` + %u WHERE `instance` >= 0 ORDER BY `instance` DESC", RESERVED_INSTANCES_LAST, RESERVED_INSTANCES_LAST);
        CharacterDatabase.Execute("DELETE FROM `instance` WHERE `map` <= 1");
    CharacterDatabase.CommitTransaction();
    QueryResult* result = CharacterDatabase.Query("SELECT `id` FROM `instance`");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            InstanceSet.insert(fields[0].GetUInt32());
        }
        while (result->NextRow());
        delete result;
    }

    BarGoLink bar(InstanceSet.size() + 1);
    bar.step();

    uint32 InstanceNumber = RESERVED_INSTANCES_LAST;
    // we do assume std::set is sorted properly on integer value
    for (const auto i : InstanceSet)
    {
        if (i != InstanceNumber)
        {
            CharacterDatabase.BeginTransaction();
            // remap instance id
            CharacterDatabase.PExecute("UPDATE `creature_respawn` SET `instance` = '%u' WHERE `instance` = '%u'", InstanceNumber, i);
            CharacterDatabase.PExecute("UPDATE `gameobject_respawn` SET `instance` = '%u' WHERE `instance` = '%u'", InstanceNumber, i);
            CharacterDatabase.PExecute("UPDATE `corpse` SET `instance` = '%u' WHERE `instance` = '%u'", InstanceNumber, i);
            CharacterDatabase.PExecute("UPDATE `character_instance` SET `instance` = '%u' WHERE `instance` = '%u'", InstanceNumber, i);
            CharacterDatabase.PExecute("UPDATE `instance` SET `id` = '%u' WHERE `id` = '%u'", InstanceNumber, i);
            CharacterDatabase.PExecute("UPDATE `group_instance` SET `instance` = '%u' WHERE `instance` = '%u'", InstanceNumber, i);
            //execute transaction synchronously
            CharacterDatabase.CommitTransaction();
        }

        ++InstanceNumber;
        bar.step();
    }

    sLog.outString();
    sLog.outString(">> Instance numbers remapped, next instance id is %u", InstanceNumber);
}

void MapPersistentStateManager::ScheduleInstanceResets()
{
    // Schedule normal dungeon resets on start up. Must be done after CleanupInstances() 
    // and PackInstances()
    m_Scheduler.ScheduleAllDungeonResets();
}

void MapPersistentStateManager::_ResetSave(PersistentStateMap& holder, PersistentStateMap::iterator &itr)
{
    // unbind all players bound to the instance
    // do not allow UnbindInstance to automatically unload the InstanceSaves
    lock_instLists = true;

    if (itr->second->IsUsedByMap())
        sLog.outInfo("[DungeonReset] Deleting map %u instance %u used by a map !", itr->second->GetMapId(), itr->second->GetInstanceId());
    delete itr->second; // Destructor will unbind groups / players
    holder.erase(itr++);
    lock_instLists = false;
}

void MapPersistentStateManager::_ResetInstance(uint32 mapId, uint32 instanceId)
{
    DEBUG_LOG("MapPersistentStateManager::_ResetInstance %u, %u", mapId, instanceId);

    PersistentStateMap::iterator itr = m_instanceSaveByInstanceId.find(instanceId);
    if (itr != m_instanceSaveByInstanceId.end())
    {
        // delay reset until map unload for loaded map
        if (mapId != itr->second->GetMapId())
        {
            sLog.outError("[CRASH] Instance %u is linked to two different maps, '%u' (scheduler) and '%u' (instance bind)",
                instanceId, mapId, itr->second->GetMapId());
            return;
        }

        if (Map* iMap = itr->second->GetMap())
        {
            if (!iMap->IsDungeon())
            {
                sLog.outInfo("[CRASH] Instance %u linked to map %u, which is not a dungeon map!", instanceId, iMap->GetId());
                return;
            }

            ((DungeonMap*)iMap)->Reset(INSTANCE_RESET_RESPAWN_DELAY);
            return;
        }

        _ResetSave(m_instanceSaveByInstanceId, itr);
    }

    DeleteInstanceFromDB(mapId, instanceId);                       // even if state not loaded
}

struct MapPersistantStateResetWorker
{
    MapPersistantStateResetWorker() {};
    void operator()(Map* map)
    {
        map->TeleportAllPlayersTo(TELEPORT_LOCATION_HOMEBIND);
        // Mark the map to be removed. In ~Map, the persistent state gets removed
        // Also prevents players from joining the map again
        ((DungeonMap*)map)->Reset(INSTANCE_RESET_GLOBAL);
    }
};

struct MapPersistantStateWarnWorker
{
    MapPersistantStateWarnWorker(time_t _timeLeft) : timeLeft(_timeLeft)
    {};

    void operator()(Map* map)
    {
        ((DungeonMap*)map)->SendResetWarnings(timeLeft);
    }

    time_t timeLeft;
};

void MapPersistentStateManager::_ResetOrWarnAll(uint32 mapId, bool warn, uint32 timeLeft)
{
    // global reset for all instances of the given map
    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);
    if (!mapEntry->IsDungeon())
        return;

    time_t now = time(nullptr);

    if (!warn)
    {
        // this is called one minute before the reset time
        if (!mapEntry->resetDelay)
        {
            sLog.outError("MapPersistentStateManager::ResetOrWarnAll: no instance template or reset delay for map %d", mapId);
            return;
        }

        // remove all binds for online player
        // If the state is unloaded after players are unbound (no one has entered the map since a restart)
        // the iterator will be invalidated. Therefore, step before unbinding.
        for (PersistentStateMap::iterator itr = m_instanceSaveByInstanceId.begin(); itr != m_instanceSaveByInstanceId.end();)
        {
            PersistentStateMap::iterator curr = itr;
            ++itr;

            if (curr->second->GetMapId() == mapId)
                ((DungeonPersistentState*)(curr->second))->UnbindThisState();
        }

        // reset maps, teleport player automaticaly to their homebinds and unload maps
        MapPersistantStateResetWorker worker;
        sMapMgr.DoForAllMapsWithMapId(mapId, worker);

        // delete them from the DB, even if not loaded
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM `character_instance` USING `character_instance` LEFT JOIN `instance` ON `character_instance`.`instance` = `id` WHERE `map` = '%u'", mapId);
        CharacterDatabase.PExecute("DELETE FROM `group_instance` USING `group_instance` LEFT JOIN `instance` ON `group_instance`.`instance` = `id` WHERE `map` = '%u'", mapId);
        CharacterDatabase.PExecute("DELETE FROM `instance` WHERE `map` = '%u'", mapId);
        CharacterDatabase.CommitTransaction();

        // calculate the next reset time
        time_t next_reset = DungeonResetScheduler::CalculateNextResetTime(mapEntry, now + timeLeft);
        // update it in the DB
        CharacterDatabase.PExecute("UPDATE `instance_reset` SET `reset_time` = '" UI64FMTD "' WHERE `map` = '%u'", (uint64)next_reset, mapId);
        return;
    }

    // note: this isn't fast but it's meant to be executed very rarely
    MapPersistantStateWarnWorker worker(timeLeft);
    sMapMgr.DoForAllMapsWithMapId(mapId, worker);
}

void MapPersistentStateManager::GetStatistics(uint32& numStates, uint32& numBoundPlayers, uint32& numBoundGroups)
{
    numStates = 0;
    numBoundPlayers = 0;
    numBoundGroups = 0;

    // only instanceable maps have bounds
    for (const auto& itr : m_instanceSaveByInstanceId)
    {
        if (!itr.second->GetMapEntry()->IsDungeon())
            continue;

        ++numStates;
        numBoundPlayers += ((DungeonPersistentState*)itr.second)->GetPlayerCount();
        numBoundGroups += ((DungeonPersistentState*)itr.second)->GetGroupCount();
    }
}

void MapPersistentStateManager::_CleanupExpiredInstancesAtTime(time_t t)
{
    _DelHelper(CharacterDatabase, "id, instance.map", "instance", "LEFT JOIN instance_reset ON instance_reset.map = instance.map WHERE (instance.reset_time < '" UI64FMTD "' AND instance.reset_time > '0') OR (NOT instance_reset.reset_time IS NULL AND instance_reset.reset_time < '" UI64FMTD "')", (uint64)t, (uint64)t);
}

void MapPersistentStateManager::LoadCreatureRespawnTimes()
{
    // remove outdated data
    CharacterDatabase.DirectExecute("DELETE FROM `creature_respawn` WHERE `respawn_time` <= UNIX_TIMESTAMP(NOW())");

    uint32 count = 0;

    QueryResult* result = CharacterDatabase.Query("SELECT `guid`, `respawn_time`, `creature_respawn`.`map`, `instance`, `reset_time` FROM `creature_respawn` LEFT JOIN `instance` ON `instance` = `id`");
    if (!result)
    {
        BarGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 creature respawn time.");
        return;
    }

    BarGoLink bar(result->GetRowCount());

    do
    {
        bar.step();
        Field* fields = result->Fetch();

        uint32 loguid       = fields[0].GetUInt32();
        uint64 respawn_time = fields[1].GetUInt64();
        uint32 mapId        = fields[2].GetUInt32();
        uint32 instanceId   = fields[3].GetUInt32();

        time_t resetTime = (time_t)fields[4].GetUInt64();

        CreatureData const* data = sObjectMgr.GetCreatureData(loguid);
        if (!data)
            continue;

        if (mapId != data->position.mapId)
            continue;

        MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);
        if (!mapEntry)
            continue;

        int beginInstance = instanceId;
        int endInstance = instanceId + 1;
        // Special case for instanciated continents
        if (sWorld.getConfig(CONFIG_BOOL_CONTINENTS_INSTANCIATE))
        {
            if (mapEntry->id == 0)
            {
                beginInstance = MAP0_FIRST;
                endInstance = MAP0_LAST;
            }
            if (mapEntry->id == 1)
            {
                beginInstance = MAP1_FIRST;
                endInstance = MAP1_LAST;
            }
        }

        for (int instance = beginInstance; instance < endInstance; ++instance)
        {
            MapPersistentState* state = AddPersistentState(mapEntry, instance,
                resetTime, mapEntry->IsDungeon(), true, false /*= initPools*/);
            if (!state)
                continue;

            state->SetCreatureRespawnTime(loguid, time_t(respawn_time));
        }

        ++count;

    }
    while (result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString(">> Loaded %u creature respawn times", count);
}

void MapPersistentStateManager::LoadGameobjectRespawnTimes()
{
    // remove outdated data
    CharacterDatabase.DirectExecute("DELETE FROM `gameobject_respawn` WHERE `respawn_time` <= UNIX_TIMESTAMP(NOW())");

    uint32 count = 0;

    QueryResult* result = CharacterDatabase.Query("SELECT `guid`, `respawn_time`, `gameobject_respawn`.`map`, `instance`, `reset_time` FROM `gameobject_respawn` LEFT JOIN `instance` ON `instance` = id");

    if (!result)
    {
        BarGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 gameobject respawn time.");
        return;
    }

    BarGoLink bar(result->GetRowCount());

    do
    {
        bar.step();
        Field* fields = result->Fetch();

        uint32 loguid       = fields[0].GetUInt32();
        uint64 respawn_time = fields[1].GetUInt64();
        uint32 mapId        = fields[2].GetUInt32();
        uint32 instanceId   = fields[3].GetUInt32();

        time_t resetTime = (time_t)fields[4].GetUInt64();

        GameObjectData const* data = sObjectMgr.GetGOData(loguid);
        if (!data)
            continue;

        if (mapId != data->position.mapId)
            continue;

        MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId);
        if (!mapEntry)
            continue;

        int beginInstance = instanceId;
        int endInstance = instanceId + 1;

        if (mapEntry->id == 0)
        {
            beginInstance = MAP0_FIRST;
            endInstance = MAP0_LAST;
        }
        if (mapEntry->id == 1)
        {
            beginInstance = MAP1_FIRST;
            endInstance = MAP1_LAST;
        }

        for (int instance = beginInstance; instance < endInstance; ++instance)
        {
            MapPersistentState* state = AddPersistentState(mapEntry, instance,
                resetTime, mapEntry->IsDungeon(), true, false /*= initPools*/);
            if (!state)
                continue;

            state->SetGORespawnTime(loguid, time_t(respawn_time));
        }

        ++count;

    }
    while (result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString(">> Loaded %u gameobject respawn times", count);
}
