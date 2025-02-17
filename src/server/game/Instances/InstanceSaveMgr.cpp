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

#include "InstanceSaveMgr.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "GridNotifiers.h"
#include "GridStates.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Timer.h"
#include "World.h"

uint16 InstanceSaveManager::ResetTimeDelay[] = {3600, 900, 300, 60};

InstanceSaveManager::~InstanceSaveManager()
{
}

InstanceSaveManager* InstanceSaveManager::instance()
{
    static InstanceSaveManager instance;
    return &instance;
}

void InstanceSaveManager::Unload()
{
    lock_instLists = true;
    for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
    {
        InstanceSave* save = itr->second;

        for (InstanceSave::PlayerListType::iterator itr2 = save->m_playerList.begin(), next = itr2; itr2 != save->m_playerList.end(); itr2 = next)
        {
            ++next;
            (*itr2)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }

        for (InstanceSave::GroupListType::iterator itr2 = save->m_groupList.begin(), next = itr2; itr2 != save->m_groupList.end(); itr2 = next)
        {
            ++next;
            (*itr2)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }

        delete save;
    }
}

/*
- adding instance into manager
- called from InstanceMap::Add, _LoadBoundInstances, LoadGroups
*/
InstanceSave* InstanceSaveManager::AddInstanceSave(uint32 mapId, uint32 instanceId, Difficulty difficulty, time_t resetTime, bool canReset, bool load)
{
    if (InstanceSave* old_save = GetInstanceSave(instanceId))
        return old_save;

    MapEntry const* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
    {
        TC_LOG_ERROR("misc", "InstanceSaveManager::AddInstanceSave: wrong mapid = {}, instanceid = {}!", mapId, instanceId);
        return nullptr;
    }

    if (instanceId == 0)
    {
        TC_LOG_ERROR("misc", "InstanceSaveManager::AddInstanceSave: mapid = {}, wrong instanceid = {}!", mapId, instanceId);
        return nullptr;
    }

    if (difficulty >= (entry->IsRaid() ? MAX_RAID_DIFFICULTY : MAX_DUNGEON_DIFFICULTY))
    {
        TC_LOG_ERROR("misc", "InstanceSaveManager::AddInstanceSave: mapid = {}, instanceid = {}, wrong dificalty {}!", mapId, instanceId, static_cast<uint32>(difficulty));
        return nullptr;
    }

    if (!resetTime)
    {
        // initialize reset time
        // for normal instances if no creatures are killed the instance will reset in two hours
        if (entry->InstanceType == MAP_RAID || difficulty > DUNGEON_DIFFICULTY_NORMAL)
            resetTime = GetResetTimeFor(mapId, difficulty);
        else
        {
            resetTime = GameTime::GetGameTime() + 2 * HOUR;
            // normally this will be removed soon after in InstanceMap::Add, prevent error
            ScheduleReset(true, resetTime, InstResetEvent(0, mapId, difficulty, instanceId));
        }
    }

    TC_LOG_DEBUG("maps", "InstanceSaveManager::AddInstanceSave: mapid = {}, instanceid = {}", mapId, instanceId);

    InstanceSave* save = new InstanceSave(mapId, instanceId, difficulty, resetTime, canReset);
    if (!load)
        save->SaveToDB();

    m_instanceSaveById[instanceId] = save;
    return save;
}

InstanceSave* InstanceSaveManager::GetInstanceSave(uint32 InstanceId)
{
    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(InstanceId);
    return itr != m_instanceSaveById.end() ? itr->second : nullptr;
}

void InstanceSaveManager::DeleteInstanceFromDB(uint32 instanceid)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INSTANCE_BY_INSTANCE);
    stmt->setUInt32(0, instanceid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE);
    stmt->setUInt32(0, instanceid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP_INSTANCE_BY_INSTANCE);
    stmt->setUInt32(0, instanceid);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
    // Respawn times should be deleted only when the map gets unloaded
}

void InstanceSaveManager::RemoveInstanceSave(uint32 InstanceId)
{
    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(InstanceId);
    if (itr != m_instanceSaveById.end())
    {
        // save the resettime for normal instances only when they get unloaded
        if (time_t resettime = itr->second->GetResetTimeForDB())
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_INSTANCE_RESETTIME);

            stmt->setUInt64(0, uint64(resettime));
            stmt->setUInt32(1, InstanceId);

            CharacterDatabase.Execute(stmt);
        }

        itr->second->SetToDelete(true);
        m_instanceSaveById.erase(itr);
    }
}

void InstanceSaveManager::UnloadInstanceSave(uint32 InstanceId)
{
    if (InstanceSave* save = GetInstanceSave(InstanceId))
    {
        save->UnloadIfEmpty();
        if (save->m_toDelete)
            delete save;
    }
}

InstanceSave::InstanceSave(uint16 MapId, uint32 InstanceId, Difficulty difficulty, time_t resetTime, bool canReset)
: m_resetTime(resetTime), m_instanceid(InstanceId), m_mapid(MapId),
  m_difficulty(difficulty), m_canReset(canReset), m_toDelete(false) { }

InstanceSave::~InstanceSave()
{
    // the players and groups must be unbound before deleting the save
    ASSERT(m_playerList.empty() && m_groupList.empty());
}

/*
    Called from AddInstanceSave
*/
void InstanceSave::SaveToDB()
{
    // save instance data too
    std::string data;
    uint32 completedEncounters = 0;

    Map* map = sMapMgr->FindMap(GetMapId(), m_instanceid);
    if (map)
    {
        ASSERT(map->IsDungeon());
        if (InstanceScript* instanceScript = ((InstanceMap*)map)->GetInstanceScript())
        {
            data = instanceScript->GetSaveData();
            completedEncounters = instanceScript->GetCompletedEncounterMask();
        }
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_INSTANCE_SAVE);
    stmt->setUInt32(0, m_instanceid);
    stmt->setUInt16(1, GetMapId());
    stmt->setUInt64(2, uint64(GetResetTimeForDB()));
    stmt->setUInt8(3, uint8(GetDifficulty()));
    stmt->setUInt32(4, completedEncounters);
    stmt->setString(5, data);
    CharacterDatabase.Execute(stmt);
}

time_t InstanceSave::GetResetTimeForDB()
{
    // only save the reset time for normal instances
    MapEntry const* entry = sMapStore.LookupEntry(GetMapId());
    if (!entry || entry->InstanceType == MAP_RAID || GetDifficulty() == DUNGEON_DIFFICULTY_HEROIC)
        return 0;
    else
        return GetResetTime();
}

// to cache or not to cache, that is the question
InstanceTemplate const* InstanceSave::GetTemplate()
{
    return sObjectMgr->GetInstanceTemplate(m_mapid);
}

MapEntry const* InstanceSave::GetMapEntry()
{
    return sMapStore.LookupEntry(m_mapid);
}

void InstanceSave::DeleteFromDB()
{
    InstanceSaveManager::DeleteInstanceFromDB(GetInstanceId());
}

/* true if the instance save is still valid */
bool InstanceSave::UnloadIfEmpty()
{
    if (m_playerList.empty() && m_groupList.empty())
    {
        // don't remove the save if there are still players inside the map
        if (Map* map = sMapMgr->FindMap(GetMapId(), GetInstanceId()))
            if (map->HavePlayers())
                return true;

        if (!sInstanceSaveMgr->lock_instLists)
            sInstanceSaveMgr->RemoveInstanceSave(GetInstanceId());

        return false;
    }
    else
        return true;
}

void InstanceSaveManager::LoadInstances()
{
    uint32 oldMSTime = getMSTime();

    // Delete expired instances (Instance related spawns are removed in the following cleanup queries)
    CharacterDatabase.DirectExecute("DELETE i FROM instance i LEFT JOIN instance_reset ir ON mapid = map AND i.difficulty = ir.difficulty "
                                    "WHERE (i.resettime > 0 AND i.resettime < UNIX_TIMESTAMP()) OR (ir.resettime IS NOT NULL AND ir.resettime < UNIX_TIMESTAMP())");

    // Delete invalid character_instance and group_instance references
    CharacterDatabase.DirectExecute("DELETE ci.* FROM character_instance AS ci LEFT JOIN characters AS c ON ci.guid = c.guid WHERE c.guid IS NULL");
    CharacterDatabase.DirectExecute("DELETE gi.* FROM group_instance     AS gi LEFT JOIN `groups`   AS g ON gi.guid = g.guid WHERE g.guid IS NULL");

    // Delete invalid instance references
    CharacterDatabase.DirectExecute("DELETE i.* FROM instance AS i LEFT JOIN character_instance AS ci ON i.id = ci.instance LEFT JOIN group_instance AS gi ON i.id = gi.instance WHERE ci.guid IS NULL AND gi.guid IS NULL");

    // Delete invalid references to instance
    CharacterDatabase.DirectExecute("DELETE FROM respawn WHERE instanceId > 0 AND instanceId NOT IN (SELECT id FROM instance)");
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM character_instance AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM group_instance     AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");

    // Clean invalid references to instance
    CharacterDatabase.DirectExecute("UPDATE corpse SET instanceId = 0 WHERE instanceId > 0 AND instanceId NOT IN (SELECT id FROM instance)");
    CharacterDatabase.DirectExecute("UPDATE characters AS tmp LEFT JOIN instance ON tmp.instance_id = instance.id SET tmp.instance_id = 0 WHERE tmp.instance_id > 0 AND instance.id IS NULL");

    // Initialize instance id storage (Needs to be done after the trash has been clean out)
    sMapMgr->InitInstanceIds();

    // Load reset times and clean expired instances
    sInstanceSaveMgr->LoadResetTimes();

    TC_LOG_INFO("server.loading", ">> Loaded instances in {} ms", GetMSTimeDiffToNow(oldMSTime));

}

void InstanceSaveManager::LoadResetTimes()
{
    time_t now = GameTime::GetGameTime();
    time_t today = (now / DAY) * DAY;

    // NOTE: Use DirectPExecute for tables that will be queried later

    // get the current reset times for normal instances (these may need to be updated)
    // these are only kept in memory for InstanceSaves that are loaded later
    // resettime = 0 in the DB for raid/heroic instances so those are skipped
    typedef std::pair<uint32 /*PAIR32(map, difficulty)*/, time_t> ResetTimeMapDiffType;
    typedef std::map<uint32, ResetTimeMapDiffType> InstResetTimeMapDiffType;
    InstResetTimeMapDiffType instResetTime;

    // index instance ids by map/difficulty pairs for fast reset warning send
    typedef std::multimap<uint32 /*PAIR32(map, difficulty)*/, uint32 /*instanceid*/ > ResetTimeMapDiffInstances;
    typedef std::pair<ResetTimeMapDiffInstances::const_iterator, ResetTimeMapDiffInstances::const_iterator> ResetTimeMapDiffInstancesBounds;
    ResetTimeMapDiffInstances mapDiffResetInstances;

    if (QueryResult result = CharacterDatabase.Query("SELECT id, map, difficulty, resettime FROM instance ORDER BY id ASC"))
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 instanceId = fields[0].GetUInt32();

            // Mark instance id as being used
            sMapMgr->RegisterInstanceId(instanceId);

            if (time_t resettime = time_t(fields[3].GetUInt64()))
            {
                uint32 mapid = fields[1].GetUInt16();
                uint32 difficulty = fields[2].GetUInt8();

                instResetTime[instanceId] = ResetTimeMapDiffType(MAKE_PAIR32(mapid, difficulty), resettime);
                mapDiffResetInstances.insert(ResetTimeMapDiffInstances::value_type(MAKE_PAIR32(mapid, difficulty), instanceId));
            }
        }
        while (result->NextRow());

        // schedule the reset times
        for (InstResetTimeMapDiffType::iterator itr = instResetTime.begin(); itr != instResetTime.end(); ++itr)
            if (itr->second.second > now)
                ScheduleReset(true, itr->second.second, InstResetEvent(0, PAIR32_LOPART(itr->second.first), Difficulty(PAIR32_HIPART(itr->second.first)), itr->first));
    }

    // load the global respawn times for raid/heroic instances
    uint32 resetHour = sWorld->getIntConfig(CONFIG_INSTANCE_RESET_TIME_HOUR);
    if (QueryResult result = CharacterDatabase.Query("SELECT mapid, difficulty, resettime FROM instance_reset"))
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 mapid = fields[0].GetUInt16();
            Difficulty difficulty = Difficulty(fields[1].GetUInt8());
            uint64 oldresettime = fields[2].GetUInt64();

            MapDifficulty const* mapDiff = GetMapDifficultyData(mapid, difficulty);
            if (!mapDiff)
            {
                TC_LOG_ERROR("misc", "InstanceSaveManager::LoadResetTimes: invalid mapid({})/difficulty({}) pair in instance_reset!", mapid, static_cast<uint32>(difficulty));

                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GLOBAL_INSTANCE_RESETTIME);
                stmt->setUInt16(0, uint16(mapid));
                stmt->setUInt8(1, uint8(difficulty));
                CharacterDatabase.DirectExecute(stmt);
                continue;
            }

            // update the reset time if the hour in the configs changes
            uint64 newresettime = GetLocalHourTimestamp(oldresettime, resetHour, false);
            if (oldresettime != newresettime)
            {
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GLOBAL_INSTANCE_RESETTIME);
                stmt->setUInt64(0, uint64(newresettime));
                stmt->setUInt16(1, uint16(mapid));
                stmt->setUInt8(2, uint8(difficulty));
                CharacterDatabase.DirectExecute(stmt);
            }

            InitializeResetTimeFor(mapid, difficulty, newresettime);
        } while (result->NextRow());
    }

    // calculate new global reset times for expired instances and those that have never been reset yet
    // add the global reset times to the priority queue
    for (MapDifficultyMap::const_iterator itr = sMapDifficultyMap.begin(); itr != sMapDifficultyMap.end(); ++itr)
    {
        uint32 map_diff_pair = itr->first;
        uint32 mapid = PAIR32_LOPART(map_diff_pair);
        Difficulty difficulty = Difficulty(PAIR32_HIPART(map_diff_pair));
        MapDifficulty const* mapDiff = &itr->second;
        if (!mapDiff->resetTime)
            continue;

        // the reset_delay must be at least one day
        uint32 period = uint32(((mapDiff->resetTime * sWorld->getRate(RATE_INSTANCE_RESET_TIME)) / float(DAY)) * float(DAY));
        if (period < DAY)
            period = DAY;

        time_t t = GetResetTimeFor(mapid, difficulty);
        if (!t)
        {
            // initialize the reset time
            t = GetLocalHourTimestamp(today + period, resetHour);

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GLOBAL_INSTANCE_RESETTIME);
            stmt->setUInt16(0, uint16(mapid));
            stmt->setUInt8(1, uint8(difficulty));
            stmt->setUInt64(2, uint64(t));
            CharacterDatabase.DirectExecute(stmt);
        }

        if (t < now)
        {
            // assume that expired instances have already been cleaned
            // calculate the next reset time
            time_t day = (t / DAY) * DAY;
            t = GetLocalHourTimestamp(day + ((today - day) / period + 1) * period, resetHour);

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GLOBAL_INSTANCE_RESETTIME);
            stmt->setUInt64(0, uint64(t));
            stmt->setUInt16(1, uint16(mapid));
            stmt->setUInt8(2, uint8(difficulty));
            CharacterDatabase.DirectExecute(stmt);
        }

        InitializeResetTimeFor(mapid, difficulty, t);

        // schedule the global reset/warning
        uint8 type;
        for (type = 1; type < 4; ++type)
            if (t - ResetTimeDelay[type-1] > now)
                break;

        ScheduleReset(true, t - ResetTimeDelay[type-1], InstResetEvent(type, mapid, difficulty, 0));

        ResetTimeMapDiffInstancesBounds range = mapDiffResetInstances.equal_range(map_diff_pair);
        for (; range.first != range.second; ++range.first)
            ScheduleReset(true, t - ResetTimeDelay[type-1], InstResetEvent(type, mapid, difficulty, range.first->second));
    }
}

time_t InstanceSaveManager::GetSubsequentResetTime(uint32 mapid, Difficulty difficulty, time_t resetTime) const
{
    MapDifficulty const* mapDiff = GetMapDifficultyData(mapid, difficulty);
    if (!mapDiff || !mapDiff->resetTime)
    {
        TC_LOG_ERROR("misc", "InstanceSaveManager::GetSubsequentResetTime: not valid difficulty or no reset delay for map {}", mapid);
        return 0;
    }

    time_t resetHour = sWorld->getIntConfig(CONFIG_INSTANCE_RESET_TIME_HOUR);
    time_t period = uint32(((mapDiff->resetTime * sWorld->getRate(RATE_INSTANCE_RESET_TIME)) / float(DAY)) * float(DAY));
    if (period < DAY)
        period = DAY;

    return GetLocalHourTimestamp(((resetTime + MINUTE) / DAY * DAY) + period, resetHour);
}

void InstanceSaveManager::SetResetTimeFor(uint32 mapid, Difficulty d, time_t t)
{
    ResetTimeByMapDifficultyMap::iterator itr = m_resetTimeByMapDifficulty.find(MAKE_PAIR32(mapid, d));
    ASSERT(itr != m_resetTimeByMapDifficulty.end());
    itr->second = t;
}

void InstanceSaveManager::ScheduleReset(bool add, time_t time, InstResetEvent event)
{
    if (!add)
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
                TC_LOG_ERROR("misc", "InstanceSaveManager::ScheduleReset: cannot cancel the reset, the event({}, {}, {}) was not found!", event.type, event.mapid, event.instanceId);
        }
    }
    else
        m_resetTimeQueue.insert(std::pair<time_t, InstResetEvent>(time, event));
}

void InstanceSaveManager::ForceGlobalReset(uint32 mapId, Difficulty difficulty)
{
    if (!GetDownscaledMapDifficultyData(mapId, difficulty))
        return;
    // remove currently scheduled reset times
    ScheduleReset(false, 0, InstResetEvent(1, mapId, difficulty, 0));
    ScheduleReset(false, 0, InstResetEvent(4, mapId, difficulty, 0));
    // force global reset on the instance
    _ResetOrWarnAll(mapId, difficulty, false, GameTime::GetGameTime());
}

void InstanceSaveManager::Update()
{
    time_t now = GameTime::GetGameTime();
    time_t t;

    while (!m_resetTimeQueue.empty())
    {
        t = m_resetTimeQueue.begin()->first;
        if (t >= now)
            break;

        InstResetEvent &event = m_resetTimeQueue.begin()->second;
        if (event.type == 0)
        {
            // for individual normal instances, max creature respawn + X hours
            _ResetInstance(event.mapid, event.instanceId);
            m_resetTimeQueue.erase(m_resetTimeQueue.begin());
        }
        else
        {
            // global reset/warning for a certain map
            time_t resetTime = GetResetTimeFor(event.mapid, event.difficulty);
            _ResetOrWarnAll(event.mapid, event.difficulty, event.type != 4, resetTime);
            if (event.type != 4)
            {
                // schedule the next warning/reset
                ++event.type;
                ScheduleReset(true, resetTime - ResetTimeDelay[event.type-1], event);
            }
            m_resetTimeQueue.erase(m_resetTimeQueue.begin());
        }
    }
}

void InstanceSaveManager::_ResetSave(InstanceSaveHashMap::iterator &itr)
{
    // unbind all players bound to the instance
    // do not allow UnbindInstance to automatically unload the InstanceSaves
    lock_instLists = true;

    bool shouldDelete = true;
    InstanceSave::PlayerListType &pList = itr->second->m_playerList;
    std::vector<Player*> temp; // list of expired binds that should be unbound
    for (Player* player : pList)
    {
        if (InstancePlayerBind* bind = player->GetBoundInstance(itr->second->GetMapId(), itr->second->GetDifficulty()))
        {
            ASSERT(bind->save == itr->second);
            if (bind->perm && bind->extendState) // permanent and not already expired
            {
                // actual promotion in DB already happened in caller
                bind->extendState = bind->extendState == EXTEND_STATE_EXTENDED ? EXTEND_STATE_NORMAL : EXTEND_STATE_EXPIRED;
                shouldDelete = false;
                continue;
            }
        }
        temp.push_back(player);
    }
    for (Player* player : temp)
    {
        player->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }

    InstanceSave::GroupListType &gList = itr->second->m_groupList;
    while (!gList.empty())
    {
        Group* group = *(gList.begin());
        group->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }

    if (shouldDelete)
    {
        delete itr->second;
        itr = m_instanceSaveById.erase(itr);
    }
    else
        ++itr;

    lock_instLists = false;
}

void InstanceSaveManager::_ResetInstance(uint32 mapid, uint32 instanceId)
{
    TC_LOG_DEBUG("maps", "InstanceSaveMgr::_ResetInstance {}, {}", mapid, instanceId);
    Map const* map = sMapMgr->CreateBaseMap(mapid);
    if (!map->Instanceable())
        return;

    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(instanceId);
    if (itr != m_instanceSaveById.end())
        _ResetSave(itr);

    DeleteInstanceFromDB(instanceId);                       // even if save not loaded

    Map* iMap = ((MapInstanced*)map)->FindInstanceMap(instanceId);

    if (iMap && iMap->IsDungeon())
        ((InstanceMap*)iMap)->Reset(INSTANCE_RESET_RESPAWN_DELAY);

    if (iMap)
    {
        iMap->DeleteRespawnTimes();
        iMap->DeleteCorpseData();
    }
    else
        Map::DeleteRespawnTimesInDB(mapid, instanceId);

    // Free up the instance id and allow it to be reused
    sMapMgr->FreeInstanceId(instanceId);
}

void InstanceSaveManager::_ResetOrWarnAll(uint32 mapid, Difficulty difficulty, bool warn, time_t resetTime)
{
    // global reset for all instances of the given map
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapid);
    if (!mapEntry->Instanceable())
        return;
    TC_LOG_DEBUG("misc", "InstanceSaveManager::ResetOrWarnAll: Processing map {} ({}) on difficulty {} (warn? {})", mapEntry->MapName[0], mapid, static_cast<uint32>(difficulty), warn);

    time_t now = GameTime::GetGameTime();

    if (!warn)
    {
        // calculate the next reset time
        time_t next_reset = GetSubsequentResetTime(mapid, difficulty, resetTime);
        if (!next_reset)
            return;

        // delete/promote instance binds from the DB, even if not loaded
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EXPIRED_CHAR_INSTANCE_BY_MAP_DIFF);
        stmt->setUInt16(0, uint16(mapid));
        stmt->setUInt8(1, uint8(difficulty));
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP_INSTANCE_BY_MAP_DIFF);
        stmt->setUInt16(0, uint16(mapid));
        stmt->setUInt8(1, uint8(difficulty));
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EXPIRED_INSTANCE_BY_MAP_DIFF);
        stmt->setUInt16(0, uint16(mapid));
        stmt->setUInt8(1, uint8(difficulty));
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_EXPIRE_CHAR_INSTANCE_BY_MAP_DIFF);
        stmt->setUInt16(0, uint16(mapid));
        stmt->setUInt8(1, uint8(difficulty));
        trans->Append(stmt);

        CharacterDatabase.CommitTransaction(trans);

        // promote loaded binds to instances of the given map
        for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end();)
        {
            if (itr->second->GetMapId() == mapid && itr->second->GetDifficulty() == difficulty)
                _ResetSave(itr);
            else
                ++itr;
        }

        SetResetTimeFor(mapid, difficulty, next_reset);
        ScheduleReset(true, time_t(next_reset-3600), InstResetEvent(1, mapid, difficulty, 0));

        // Update it in the DB
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GLOBAL_INSTANCE_RESETTIME);

        stmt->setUInt64(0, uint64(next_reset));
        stmt->setUInt16(1, uint16(mapid));
        stmt->setUInt8(2, uint8(difficulty));

        CharacterDatabase.Execute(stmt);
    }

    // note: this isn't fast but it's meant to be executed very rarely
    Map* baseMap = sMapMgr->CreateBaseMap(mapid);            // _not_ include difficulty
    uint32 timeLeft;

    for (auto& [_, map] : baseMap->ToMapInstanced()->GetInstancedMaps())
    {
        InstanceMap* instanceMap = map->ToInstanceMap();
        if (warn)
        {
            if (now >= resetTime)
                timeLeft = 0;
            else
                timeLeft = uint32(resetTime - now);

            instanceMap->SendResetWarnings(timeLeft);
        }
        else
            instanceMap->Reset(INSTANCE_RESET_GLOBAL);
    }

    /// @todo delete creature/gameobject respawn times even if the maps are not loaded
}

uint32 InstanceSaveManager::GetNumBoundPlayersTotal() const
{
    uint32 ret = 0;
    for (InstanceSaveHashMap::const_iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetPlayerCount();

    return ret;
}

uint32 InstanceSaveManager::GetNumBoundGroupsTotal() const
{
    uint32 ret = 0;
    for (InstanceSaveHashMap::const_iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetGroupCount();

    return ret;
}
