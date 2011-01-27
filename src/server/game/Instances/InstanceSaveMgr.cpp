/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "SQLStorage.h"
#include "Player.h"
#include "GridNotifiers.h"
#include "Log.h"
#include "GridStates.h"
#include "CellImpl.h"
#include "Map.h"
#include "MapManager.h"
#include "MapInstanced.h"
#include "InstanceSaveMgr.h"
#include "Timer.h"
#include "GridNotifiersImpl.h"
#include "Config.h"
#include "Transport.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Group.h"
#include "InstanceScript.h"

uint16 InstanceSaveManager::ResetTimeDelay[] = {3600, 900, 300, 60};

InstanceSaveManager::~InstanceSaveManager()
{
    // it is undefined whether this or objectmgr will be unloaded first
    // so we must be prepared for both cases
    lock_instLists = true;
    for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
    {
        InstanceSave *save = itr->second;

        for (InstanceSave::PlayerListType::iterator itr2 = save->m_playerList.begin(), next = itr2; itr2 != save->m_playerList.end(); itr2 = next)
        {
            ++next;
            (*itr2)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }
        save->m_playerList.clear();

        for (InstanceSave::GroupListType::iterator itr2 = save->m_groupList.begin(), next = itr2; itr2 != save->m_groupList.end(); itr2 = next)
        {
            ++next;
            (*itr2)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }
        save->m_groupList.clear();
        delete save;
    }
}

/*
- adding instance into manager
- called from InstanceMap::Add, _LoadBoundInstances, LoadGroups
*/
InstanceSave* InstanceSaveManager::AddInstanceSave(uint32 mapId, uint32 instanceId, Difficulty difficulty, time_t resetTime, bool canReset, bool load)
{
    if (InstanceSave *old_save = GetInstanceSave(instanceId))
        return old_save;

    const MapEntry* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
    {
        sLog->outError("InstanceSaveManager::AddInstanceSave: wrong mapid = %d, instanceid = %d!", mapId, instanceId);
        return NULL;
    }

    if (instanceId == 0)
    {
        sLog->outError("InstanceSaveManager::AddInstanceSave: mapid = %d, wrong instanceid = %d!", mapId, instanceId);
        return NULL;
    }

    if (difficulty >= (entry->IsRaid() ? MAX_RAID_DIFFICULTY : MAX_DUNGEON_DIFFICULTY))
    {
        sLog->outError("InstanceSaveManager::AddInstanceSave: mapid = %d, instanceid = %d, wrong dificalty %u!", mapId, instanceId, difficulty);
        return NULL;
    }

    if (!resetTime)
    {
        // initialize reset time
        // for normal instances if no creatures are killed the instance will reset in two hours
        if (entry->map_type == MAP_RAID || difficulty > DUNGEON_DIFFICULTY_NORMAL)
            resetTime = GetResetTimeFor(mapId,difficulty);
        else
        {
            resetTime = time(NULL) + 2 * HOUR;
            // normally this will be removed soon after in InstanceMap::Add, prevent error
            ScheduleReset(true, resetTime, InstResetEvent(0, mapId, difficulty, instanceId));
        }
    }

    sLog->outDebug("InstanceSaveManager::AddInstanceSave: mapid = %d, instanceid = %d", mapId, instanceId);

    InstanceSave *save = new InstanceSave(mapId, instanceId, difficulty, resetTime, canReset);
    if (!load)
        save->SaveToDB();

    m_instanceSaveById[instanceId] = save;
    return save;
}

InstanceSave *InstanceSaveManager::GetInstanceSave(uint32 InstanceId)
{
    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(InstanceId);
    return itr != m_instanceSaveById.end() ? itr->second : NULL;
}

void InstanceSaveManager::DeleteInstanceFromDB(uint32 instanceid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM instance WHERE id = '%u'", instanceid);
    trans->PAppend("DELETE FROM character_instance WHERE instance = '%u'", instanceid);
    trans->PAppend("DELETE FROM group_instance WHERE instance = '%u'", instanceid);
    CharacterDatabase.CommitTransaction(trans);
    // respawn times should be deleted only when the map gets unloaded
}

void InstanceSaveManager::RemoveInstanceSave(uint32 InstanceId)
{
    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(InstanceId);
    if (itr != m_instanceSaveById.end())
    {
        // save the resettime for normal instances only when they get unloaded
        if (time_t resettime = itr->second->GetResetTimeForDB())
            CharacterDatabase.PExecute("UPDATE instance SET resettime = '"UI64FMTD"' WHERE id = '%u'", (uint64)resettime, InstanceId);

        delete itr->second;
        m_instanceSaveById.erase(itr);
    }
}

InstanceSave::InstanceSave(uint16 MapId, uint32 InstanceId, Difficulty difficulty, time_t resetTime, bool canReset)
: m_resetTime(resetTime), m_instanceid(InstanceId), m_mapid(MapId),
  m_difficulty(difficulty), m_canReset(canReset)
{
}

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

    Map *map = sMapMgr->FindMap(GetMapId(),m_instanceid);
    if (map)
    {
        ASSERT(map->IsDungeon());
        if (InstanceScript *iData = ((InstanceMap*)map)->GetInstanceScript())
        {
            data = iData->GetSaveData();
            if (!data.empty())
                CharacterDatabase.escape_string(data);
        }
    }

    CharacterDatabase.PExecute("INSERT INTO instance VALUES ('%u', '%u', '%u', '%u', '%s')", m_instanceid, GetMapId(), (uint32)GetResetTimeForDB(), GetDifficulty(), data.c_str());
}

time_t InstanceSave::GetResetTimeForDB()
{
    // only save the reset time for normal instances
    const MapEntry *entry = sMapStore.LookupEntry(GetMapId());
    if (!entry || entry->map_type == MAP_RAID || GetDifficulty() == DUNGEON_DIFFICULTY_HEROIC)
        return 0;
    else
        return GetResetTime();
}

// to cache or not to cache, that is the question
InstanceTemplate const* InstanceSave::GetTemplate()
{
    return ObjectMgr::GetInstanceTemplate(m_mapid);
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
        if (!sInstanceSaveMgr->lock_instLists)
            sInstanceSaveMgr->RemoveInstanceSave(GetInstanceId());

        return false;
    }
    else
        return true;
}

void InstanceSaveManager::_DelHelper(const char *fields, const char *table, const char *queryTail,...)
{
    Tokens fieldTokens(fields, ',');
    ASSERT(fieldTokens.size() != 0);

    va_list ap;
    char szQueryTail [MAX_QUERY_LEN];
    va_start(ap, queryTail);
    vsnprintf(szQueryTail, MAX_QUERY_LEN, queryTail, ap);
    va_end(ap);

    QueryResult result = CharacterDatabase.PQuery("SELECT %s FROM %s %s", fields, table, szQueryTail);
    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            std::ostringstream ss;
            for (size_t i = 0; i < fieldTokens.size(); i++)
            {
                std::string fieldValue = fields[i].GetString();
                CharacterDatabase.escape_string(fieldValue);
                ss << (i != 0 ? " AND " : "") << fieldTokens[i] << " = '" << fieldValue << "'";
            }
            CharacterDatabase.DirectPExecute("DELETE FROM %s WHERE %s", table, ss.str().c_str());
        } while (result->NextRow());
    }
}

void InstanceSaveManager::CleanupAndPackInstances()
{
    uint32 oldMSTime = getMSTime();

    // load reset times and clean expired instances
    sInstanceSaveMgr->LoadResetTimes();

    // Delete invalid character_instance and group_instance references
    CharacterDatabase.DirectExecute("DELETE ci.* FROM character_instance AS ci LEFT JOIN characters AS c ON ci.guid = c.guid WHERE c.guid IS NULL");
    CharacterDatabase.DirectExecute("DELETE gi.* FROM group_instance     AS gi LEFT JOIN groups     AS g ON gi.guid = g.guid WHERE g.guid IS NULL");

    // Delete invalid instance references
    CharacterDatabase.DirectExecute("DELETE i.* FROM instance AS i LEFT JOIN character_instance AS ci ON i.id = ci.instance LEFT JOIN group_instance AS gi ON i.id = gi.instance WHERE ci.guid IS NULL AND gi.guid IS NULL");

    // Delete invalid references to instance
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM creature_respawn   AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM gameobject_respawn AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM character_instance AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");
    CharacterDatabase.DirectExecute("DELETE tmp.* FROM group_instance     AS tmp LEFT JOIN instance ON tmp.instance = instance.id WHERE tmp.instance > 0 AND instance.id IS NULL");

    // Clean invalid references to instance
    CharacterDatabase.DirectExecute("UPDATE corpse     AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = 0 WHERE tmp.instance    > 0 AND instance.id IS NULL");
    CharacterDatabase.DirectExecute("UPDATE characters AS tmp LEFT JOIN instance ON tmp.instance_id = instance.id SET tmp.instance_id = 0 WHERE tmp.instance_id > 0 AND instance.id IS NULL");

    // Create new index
    CharacterDatabase.DirectExecute("ALTER TABLE instance ADD newid INT UNSIGNED AUTO_INCREMENT, ADD INDEX(newid)");

    // Update old ids
    CharacterDatabase.DirectExecute("UPDATE account_instance_times  AS tmp LEFT JOIN instance ON tmp.instanceId  = instance.id SET tmp.instanceId  = instance.newid WHERE tmp.instanceId  > 0");
    CharacterDatabase.DirectExecute("UPDATE corpse                  AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = instance.newid WHERE tmp.instance    > 0");
    CharacterDatabase.DirectExecute("UPDATE character_instance      AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = instance.newid WHERE tmp.instance    > 0");
    CharacterDatabase.DirectExecute("UPDATE group_instance          AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = instance.newid WHERE tmp.instance    > 0");
    CharacterDatabase.DirectExecute("UPDATE characters              AS tmp LEFT JOIN instance ON tmp.instance_id = instance.id SET tmp.instance_id = instance.newid WHERE tmp.instance_id > 0");
    CharacterDatabase.DirectExecute("UPDATE creature_respawn        AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = instance.newid WHERE tmp.instance    > 0");
    CharacterDatabase.DirectExecute("UPDATE gameobject_respawn      AS tmp LEFT JOIN instance ON tmp.instance    = instance.id SET tmp.instance    = instance.newid WHERE tmp.instance    > 0");

    // Update instance too
    CharacterDatabase.DirectExecute("UPDATE instance SET id = newid");

    // Finally drop the no longer needed column
    CharacterDatabase.DirectExecute("ALTER TABLE instance DROP COLUMN newid");

    // Bake some cookies for click
    sLog->outString(">> Cleaned up and packed instances in %u ms", GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void InstanceSaveManager::LoadResetTimes()
{
    time_t now = time(NULL);
    time_t today = (now / DAY) * DAY;

    // NOTE: Use DirectPExecute for tables that will be queried later

    // get the current reset times for normal instances (these may need to be updated)
    // these are only kept in memory for InstanceSaves that are loaded later
    // resettime = 0 in the DB for raid/heroic instances so those are skipped
    typedef std::pair<uint32 /*PAIR32(map,difficulty)*/, time_t> ResetTimeMapDiffType;
    typedef std::map<uint32, ResetTimeMapDiffType> InstResetTimeMapDiffType;
    InstResetTimeMapDiffType instResetTime;

    // index instance ids by map/difficulty pairs for fast reset warning send
    typedef std::multimap<uint32 /*PAIR32(map,difficulty)*/, uint32 /*instanceid*/ > ResetTimeMapDiffInstances;
    ResetTimeMapDiffInstances mapDiffResetInstances;

    QueryResult result = CharacterDatabase.Query("SELECT id, map, difficulty, resettime FROM instance WHERE resettime > 0");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            if (time_t resettime = time_t(fields[3].GetUInt32()))
            {
                uint32 id = fields[0].GetUInt32();
                uint32 mapid = fields[1].GetUInt16();
                uint32 difficulty = fields[2].GetUInt8();
                instResetTime[id] = ResetTimeMapDiffType(MAKE_PAIR32(mapid, difficulty), resettime);
                mapDiffResetInstances.insert(ResetTimeMapDiffInstances::value_type(MAKE_PAIR32(mapid, difficulty), id));
            }
        }
        while (result->NextRow());

        // update reset time for normal instances with the max creature respawn time + X hours
        result = CharacterDatabase.Query("SELECT MAX(respawntime), instance FROM creature_respawn WHERE instance > 0 GROUP BY instance");
        if (result)
        {
            do
            {
                Field *fields = result->Fetch();
                uint32 instance = fields[1].GetUInt32();
                time_t resettime = time_t(fields[0].GetUInt32() + 2 * HOUR);
                InstResetTimeMapDiffType::iterator itr = instResetTime.find(instance);
                if (itr != instResetTime.end() && itr->second.second != resettime)
                {
                    CharacterDatabase.DirectPExecute("UPDATE instance SET resettime = '"UI64FMTD"' WHERE id = '%u'", uint64(resettime), instance);
                    itr->second.second = resettime;
                }
            }
            while (result->NextRow());
        }

        // schedule the reset times
        for (InstResetTimeMapDiffType::iterator itr = instResetTime.begin(); itr != instResetTime.end(); ++itr)
            if (itr->second.second > now)
                ScheduleReset(true, itr->second.second, InstResetEvent(0, PAIR32_LOPART(itr->second.first), Difficulty(PAIR32_HIPART(itr->second.first)), itr->first));
    }

    // load the global respawn times for raid/heroic instances
    uint32 diff = sWorld->getIntConfig(CONFIG_INSTANCE_RESET_TIME_HOUR) * HOUR;
    result = CharacterDatabase.Query("SELECT mapid, difficulty, resettime FROM instance_reset");
    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 mapid = fields[0].GetUInt16();
            Difficulty difficulty = Difficulty(fields[1].GetUInt32());
            uint64 oldresettime = fields[2].GetUInt32();

            MapDifficulty const* mapDiff = GetMapDifficultyData(mapid, difficulty);
            if (!mapDiff)
            {
                sLog->outError("InstanceSaveManager::LoadResetTimes: invalid mapid(%u)/difficulty(%u) pair in instance_reset!", mapid, difficulty);
                CharacterDatabase.DirectPExecute("DELETE FROM instance_reset WHERE mapid = '%u' AND difficulty = '%u'", mapid,difficulty);
                continue;
            }

            // update the reset time if the hour in the configs changes
            uint64 newresettime = (oldresettime / DAY) * DAY + diff;
            if (oldresettime != newresettime)
                CharacterDatabase.DirectPExecute("UPDATE instance_reset SET resettime = '%u' WHERE mapid = '%u' AND difficulty = '%u'", uint32(newresettime), mapid, difficulty);

            SetResetTimeFor(mapid, difficulty, newresettime);
        } while (result->NextRow());
    }

    // clean expired instances, references to them will be deleted in CleanupInstances
    // must be done before calculating new reset times
    _DelHelper("id, map, instance.difficulty", "instance", "LEFT JOIN instance_reset ON mapid = map AND instance.difficulty =  instance_reset.difficulty WHERE (instance.resettime < '"UI64FMTD"' AND instance.resettime > '0') OR (NOT instance_reset.resettime IS NULL AND instance_reset.resettime < '"UI64FMTD"')",  (uint64)now, (uint64)now);

    ResetTimeMapDiffInstances::const_iterator in_itr;

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
        uint32 period = uint32(((mapDiff->resetTime * sWorld->getRate(RATE_INSTANCE_RESET_TIME))/DAY) * DAY);
        if (period < DAY)
            period = DAY;

        time_t t = GetResetTimeFor(mapid,difficulty);
        if (!t)
        {
            // initialize the reset time
            t = today + period + diff;
            CharacterDatabase.DirectPExecute("INSERT INTO instance_reset VALUES ('%u','%u','%u')", mapid, difficulty, (uint32)t);
        }

        if (t < now)
        {
            // assume that expired instances have already been cleaned
            // calculate the next reset time
            t = (t / DAY) * DAY;
            t += ((today - t) / period + 1) * period + diff;
            CharacterDatabase.DirectPExecute("UPDATE instance_reset SET resettime = '"UI64FMTD"' WHERE mapid = '%u' AND difficulty= '%u'", (uint64)t, mapid, difficulty);
        }

        SetResetTimeFor(mapid,difficulty,t);

        // schedule the global reset/warning
        uint8 type;
        for (type = 1; type < 4; ++type)
            if (t - ResetTimeDelay[type-1] > now)
                break;

        ScheduleReset(true, t - ResetTimeDelay[type-1], InstResetEvent(type, mapid, difficulty, 0));

        for (in_itr = mapDiffResetInstances.lower_bound(map_diff_pair); in_itr != mapDiffResetInstances.upper_bound(map_diff_pair); ++in_itr)
            ScheduleReset(true, t - ResetTimeDelay[type-1], InstResetEvent(type, mapid, difficulty, in_itr->second));
    }
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
                sLog->outError("InstanceSaveManager::ScheduleReset: cannot cancel the reset, the event(%d,%d,%d) was not found!", event.type, event.mapid, event.instanceId);
        }
    }
    else
        m_resetTimeQueue.insert(std::pair<time_t, InstResetEvent>(time, event));
}

void InstanceSaveManager::Update()
{
    time_t now = time(NULL);
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
            time_t resetTime = GetResetTimeFor(event.mapid,event.difficulty);
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

    InstanceSave::PlayerListType &pList = itr->second->m_playerList;
    while (!pList.empty())
    {
        Player *player = *(pList.begin());
        player->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }

    InstanceSave::GroupListType &gList = itr->second->m_groupList;
    while (!gList.empty())
    {
        Group *group = *(gList.begin());
        group->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }

    delete itr->second;
    m_instanceSaveById.erase(itr++);

    lock_instLists = false;
}

void InstanceSaveManager::_ResetInstance(uint32 mapid, uint32 instanceId)
{
    sLog->outDebug("InstanceSaveMgr::_ResetInstance %u, %u", mapid, instanceId);
    Map *map = (MapInstanced*)sMapMgr->CreateBaseMap(mapid);
    if (!map->Instanceable())
        return;

    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(instanceId);
    if (itr != m_instanceSaveById.end())
        _ResetSave(itr);

    DeleteInstanceFromDB(instanceId);                       // even if save not loaded

    Map* iMap = ((MapInstanced*)map)->FindMap(instanceId);

    if (iMap && iMap->IsDungeon())
        ((InstanceMap*)iMap)->Reset(INSTANCE_RESET_RESPAWN_DELAY);
    else
        sObjectMgr->DeleteRespawnTimeForInstance(instanceId);   // even if map is not loaded
}

void InstanceSaveManager::_ResetOrWarnAll(uint32 mapid, Difficulty difficulty, bool warn, time_t resetTime)
{
    // global reset for all instances of the given map
    MapEntry const *mapEntry = sMapStore.LookupEntry(mapid);
    if (!mapEntry->Instanceable())
        return;

    time_t now = time(NULL);

    if (!warn)
    {
        MapDifficulty const* mapDiff = GetMapDifficultyData(mapid, difficulty);
        if (!mapDiff || !mapDiff->resetTime)
        {
            sLog->outError("InstanceSaveManager::ResetOrWarnAll: not valid difficulty or no reset delay for map %d", mapid);
            return;
        }

        // remove all binds to instances of the given map
        for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end();)
        {
            if (itr->second->GetMapId() == mapid && itr->second->GetDifficulty() == difficulty)
                _ResetSave(itr);
            else
                ++itr;
        }

        // delete them from the DB, even if not loaded
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM character_instance USING character_instance LEFT JOIN instance ON character_instance.instance = id WHERE map = '%u' and difficulty='%u'", mapid, difficulty);
        trans->PAppend("DELETE FROM group_instance USING group_instance LEFT JOIN instance ON group_instance.instance = id WHERE map = '%u' and difficulty='%u'", mapid, difficulty);
        trans->PAppend("DELETE FROM instance WHERE map = '%u' and difficulty='%u'", mapid, difficulty);
        CharacterDatabase.CommitTransaction(trans);

        // calculate the next reset time
        uint32 diff = sWorld->getIntConfig(CONFIG_INSTANCE_RESET_TIME_HOUR) * HOUR;

        uint32 period = uint32(((mapDiff->resetTime * sWorld->getRate(RATE_INSTANCE_RESET_TIME))/DAY) * DAY);
        if (period < DAY)
            period = DAY;

        uint64 next_reset = ((resetTime + MINUTE) / DAY * DAY) + period + diff;

        SetResetTimeFor(mapid, difficulty, next_reset);
        ScheduleReset(true, time_t(next_reset-3600), InstResetEvent(1, mapid, difficulty, 0));

        // update it in the DB
        CharacterDatabase.PExecute("UPDATE instance_reset SET resettime = '%u' WHERE mapid = '%d' AND difficulty = '%d'", uint32(next_reset), mapid, difficulty);
    }

    // note: this isn't fast but it's meant to be executed very rarely
    Map const *map = sMapMgr->CreateBaseMap(mapid);          // _not_ include difficulty
    MapInstanced::InstancedMaps &instMaps = ((MapInstanced*)map)->GetInstancedMaps();
    MapInstanced::InstancedMaps::iterator mitr;
    uint32 timeLeft;

    for (mitr = instMaps.begin(); mitr != instMaps.end(); ++mitr)
    {
        Map *map2 = mitr->second;
        if (!map2->IsDungeon())
            continue;

        if (warn)
        {
            if (now <= resetTime)
                timeLeft = 0;
            else
                timeLeft = uint32(now - resetTime);

            ((InstanceMap*)map2)->SendResetWarnings(timeLeft);
        }
        else
            ((InstanceMap*)map2)->Reset(INSTANCE_RESET_GLOBAL);
    }

    // TODO: delete creature/gameobject respawn times even if the maps are not loaded
}

uint32 InstanceSaveManager::GetNumBoundPlayersTotal()
{
    uint32 ret = 0;
    for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetPlayerCount();

    return ret;
}

uint32 InstanceSaveManager::GetNumBoundGroupsTotal()
{
    uint32 ret = 0;
    for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetGroupCount();

    return ret;
}
