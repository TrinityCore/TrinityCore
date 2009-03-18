/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "InstanceSaveMgr.h"
#include "Common.h"
#include "Database/SQLStorage.h"

#include "Player.h"
#include "GridNotifiers.h"
#include "WorldSession.h"
#include "Log.h"
#include "GridStates.h"
#include "CellImpl.h"
#include "Map.h"
#include "MapManager.h"
#include "MapInstanced.h"
#include "InstanceSaveMgr.h"
#include "Timer.h"
#include "GridNotifiersImpl.h"
#include "Config/ConfigEnv.h"
#include "Transports.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Group.h"
#include "InstanceData.h"
#include "ProgressBar.h"

INSTANTIATE_SINGLETON_1( InstanceSaveManager );

InstanceSaveManager::InstanceSaveManager() : lock_instLists(false)
{
}

InstanceSaveManager::~InstanceSaveManager()
{
    // it is undefined whether this or objectmgr will be unloaded first
    // so we must be prepared for both cases
    lock_instLists = true;
    for (InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
    {
        InstanceSave *save = itr->second;
        for(InstanceSave::PlayerListType::iterator itr = save->m_playerList.begin(), next = itr; itr != save->m_playerList.end(); itr = next)
        {
            ++next;
            (*itr)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }
        save->m_playerList.clear();
        for(InstanceSave::GroupListType::iterator itr = save->m_groupList.begin(), next = itr; itr != save->m_groupList.end(); itr = next)
        {
            ++next;
            (*itr)->UnbindInstance(save->GetMapId(), save->GetDifficulty(), true);
        }
        save->m_groupList.clear();
        delete save;
    }
}

/*
- adding instance into manager
- called from InstanceMap::Add, _LoadBoundInstances, LoadGroups
*/
InstanceSave* InstanceSaveManager::AddInstanceSave(uint32 mapId, uint32 instanceId, uint8 difficulty, time_t resetTime, bool canReset, bool load)
{
    InstanceSave *save = GetInstanceSave(instanceId);
    if(save) return save;

    const MapEntry* entry = sMapStore.LookupEntry(mapId);
    if(!entry || instanceId == 0)
    {
        sLog.outError("InstanceSaveManager::AddInstanceSave: mapid = %d, instanceid = %d!", mapId, instanceId);
        return NULL;
    }

    if(!resetTime)
    {
        // initialize reset time
        // for normal instances if no creatures are killed the instance will reset in two hours
        if(entry->map_type == MAP_RAID || difficulty == DIFFICULTY_HEROIC)
            resetTime = GetResetTimeFor(mapId);
        else
        {
            resetTime = time(NULL) + 2 * HOUR;
            // normally this will be removed soon after in InstanceMap::Add, prevent error
            ScheduleReset(true, resetTime, InstResetEvent(0, mapId, instanceId));
        }
    }

    sLog.outDebug("InstanceSaveManager::AddInstanceSave: mapid = %d, instanceid = %d", mapId, instanceId);

    save = new InstanceSave(mapId, instanceId, difficulty, resetTime, canReset);
    if(!load) save->SaveToDB();

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
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM instance WHERE id = '%u'", instanceid);
    CharacterDatabase.PExecute("DELETE FROM character_instance WHERE instance = '%u'", instanceid);
    CharacterDatabase.PExecute("DELETE FROM group_instance WHERE instance = '%u'", instanceid);
    CharacterDatabase.CommitTransaction();
    // respawn times should be deleted only when the map gets unloaded
}

void InstanceSaveManager::RemoveInstanceSave(uint32 InstanceId)
{
    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find( InstanceId );
    if(itr != m_instanceSaveById.end())
    {
        // save the resettime for normal instances only when they get unloaded
        if(time_t resettime = itr->second->GetResetTimeForDB())
            CharacterDatabase.PExecute("UPDATE instance SET resettime = '"I64FMTD"' WHERE id = '%u'", (uint64)resettime, InstanceId);
        delete itr->second;
        m_instanceSaveById.erase(itr);
    }
}

InstanceSave::InstanceSave(uint16 MapId, uint32 InstanceId, uint8 difficulty,
                           time_t resetTime, bool canReset)
: m_mapid(MapId), m_instanceid(InstanceId), m_resetTime(resetTime),
  m_difficulty(difficulty), m_canReset(canReset)
{
}

InstanceSave::~InstanceSave()
{
    // the players and groups must be unbound before deleting the save
    assert(m_playerList.empty() && m_groupList.empty());
}

/*
    Called from AddInstanceSave
*/
void InstanceSave::SaveToDB()
{
    // save instance data too
    std::string data;

    Map *map = MapManager::Instance().FindMap(GetMapId(),m_instanceid);
    if(map)
    {
        assert(map->IsDungeon());
        InstanceData *iData = ((InstanceMap *)map)->GetInstanceData();
        if(iData && iData->Save())
        {
            data = iData->Save();
            CharacterDatabase.escape_string(data);
        }
    }

    CharacterDatabase.PExecute("INSERT INTO instance VALUES ('%u', '%u', '"I64FMTD"', '%u', '%s')", m_instanceid, GetMapId(), (uint64)GetResetTimeForDB(), GetDifficulty(), data.c_str());
}

time_t InstanceSave::GetResetTimeForDB()
{
    // only save the reset time for normal instances
    const MapEntry *entry = sMapStore.LookupEntry(GetMapId());
    if(!entry || entry->map_type == MAP_RAID || GetDifficulty() == DIFFICULTY_HEROIC)
        return 0;
    else
        return GetResetTime();
}

// to cache or not to cache, that is the question
InstanceTemplate const* InstanceSave::GetTemplate()
{
    return objmgr.GetInstanceTemplate(m_mapid);
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
    if(m_playerList.empty() && m_groupList.empty())
    {
        if(!sInstanceSaveManager.lock_instLists)
            sInstanceSaveManager.RemoveInstanceSave(GetInstanceId());
        return false;
    }
    else
        return true;
}

void InstanceSaveManager::_DelHelper(DatabaseType &db, const char *fields, const char *table, const char *queryTail,...)
{
    Tokens fieldTokens = StrSplit(fields, ", ");
    assert(fieldTokens.size() != 0);

    va_list ap;
    char szQueryTail [MAX_QUERY_LEN];
    va_start(ap, queryTail);
    int res = vsnprintf( szQueryTail, MAX_QUERY_LEN, queryTail, ap );
    va_end(ap);

    QueryResult *result = db.PQuery("SELECT %s FROM %s %s", fields, table, szQueryTail);
    if(result)
    {
        do
        {
            Field *fields = result->Fetch();
            std::ostringstream ss;
            for(size_t i = 0; i < fieldTokens.size(); i++)
            {
                std::string fieldValue = fields[i].GetCppString();
                db.escape_string(fieldValue);
                ss << (i != 0 ? " AND " : "") << fieldTokens[i] << " = '" << fieldValue << "'";
            }
            db.DirectPExecute("DELETE FROM %s WHERE %s", table, ss.str().c_str());
        } while (result->NextRow());
        delete result;
    }
}

void InstanceSaveManager::CleanupInstances()
{
    uint64 now = (uint64)time(NULL);

    barGoLink bar(2);
    bar.step();

    // load reset times and clean expired instances
    sInstanceSaveManager.LoadResetTimes();

    // clean character/group - instance binds with invalid group/characters
    _DelHelper(CharacterDatabase, "character_instance.guid, instance", "character_instance", "LEFT JOIN characters ON character_instance.guid = characters.guid WHERE characters.guid IS NULL");
    _DelHelper(CharacterDatabase, "group_instance.leaderGuid, instance", "group_instance", "LEFT JOIN characters ON group_instance.leaderGuid = characters.guid LEFT JOIN groups ON group_instance.leaderGuid = groups.leaderGuid WHERE characters.guid IS NULL OR groups.leaderGuid IS NULL");

    // clean instances that do not have any players or groups bound to them
    _DelHelper(CharacterDatabase, "id, map, difficulty", "instance", "LEFT JOIN character_instance ON character_instance.instance = id LEFT JOIN group_instance ON group_instance.instance = id WHERE character_instance.instance IS NULL AND group_instance.instance IS NULL");

    // clean invalid instance references in other tables
    _DelHelper(CharacterDatabase, "character_instance.guid, instance", "character_instance", "LEFT JOIN instance ON character_instance.instance = instance.id WHERE instance.id IS NULL");
    _DelHelper(CharacterDatabase, "group_instance.leaderGuid, instance", "group_instance", "LEFT JOIN instance ON group_instance.instance = instance.id WHERE instance.id IS NULL");

    // creature_respawn and gameobject_respawn are in another database
    // first, obtain total instance set
    std::set< uint32 > InstanceSet;
    QueryResult *result = CharacterDatabase.Query("SELECT id FROM instance");
    if( result )
    {
        do
        {
            Field *fields = result->Fetch();
            InstanceSet.insert(fields[0].GetUInt32());
        }
        while (result->NextRow());
        delete result;
    }

    // creature_respawn
    result = WorldDatabase.Query("SELECT DISTINCT(instance) FROM creature_respawn WHERE instance <> 0");
    if( result )
    {
        do
        {
            Field *fields = result->Fetch();
            if(InstanceSet.find(fields[0].GetUInt32()) == InstanceSet.end())
                WorldDatabase.DirectPExecute("DELETE FROM creature_respawn WHERE instance = '%u'", fields[0].GetUInt32());
        }
        while (result->NextRow());
        delete result;
    }

    // gameobject_respawn
    result = WorldDatabase.Query("SELECT DISTINCT(instance) FROM gameobject_respawn WHERE instance <> 0");
    if( result )
    {
        do
        {
            Field *fields = result->Fetch();
            if(InstanceSet.find(fields[0].GetUInt32()) == InstanceSet.end())
                WorldDatabase.DirectPExecute("DELETE FROM gameobject_respawn WHERE instance = '%u'", fields[0].GetUInt32());
        }
        while (result->NextRow());
        delete result;
    }

    bar.step();
    sLog.outString();
    sLog.outString( ">> Initialized %u instances", (uint32)InstanceSet.size());
}

void InstanceSaveManager::PackInstances()
{
    // this routine renumbers player instance associations in such a way so they start from 1 and go up
    // TODO: this can be done a LOT more efficiently

    // obtain set of all associations
    std::set< uint32 > InstanceSet;

    // all valid ids are in the instance table
    // any associations to ids not in this table are assumed to be
    // cleaned already in CleanupInstances
    QueryResult *result = CharacterDatabase.Query("SELECT id FROM instance");
    if( result )
    {
        do
        {
            Field *fields = result->Fetch();
            InstanceSet.insert(fields[0].GetUInt32());
        }
        while (result->NextRow());
        delete result;
    }

    barGoLink bar( InstanceSet.size() + 1);
    bar.step();

    uint32 InstanceNumber = 1;
    // we do assume std::set is sorted properly on integer value
    for (std::set< uint32 >::iterator i = InstanceSet.begin(); i != InstanceSet.end(); ++i)
    {
        if (*i != InstanceNumber)
        {
            // remap instance id
            WorldDatabase.PExecute("UPDATE creature_respawn SET instance = '%u' WHERE instance = '%u'", InstanceNumber, *i);
            WorldDatabase.PExecute("UPDATE gameobject_respawn SET instance = '%u' WHERE instance = '%u'", InstanceNumber, *i);
            CharacterDatabase.PExecute("UPDATE corpse SET instance = '%u' WHERE instance = '%u'", InstanceNumber, *i);
            CharacterDatabase.PExecute("UPDATE character_instance SET instance = '%u' WHERE instance = '%u'", InstanceNumber, *i);
            CharacterDatabase.PExecute("UPDATE instance SET id = '%u' WHERE id = '%u'", InstanceNumber, *i);
            CharacterDatabase.PExecute("UPDATE group_instance SET instance = '%u' WHERE instance = '%u'", InstanceNumber, *i);
        }

        ++InstanceNumber;
        bar.step();
    }

    sLog.outString();
    sLog.outString( ">> Instance numbers remapped, next instance id is %u", InstanceNumber );
}

void InstanceSaveManager::LoadResetTimes()
{
    time_t now = time(NULL);
    time_t today = (now / DAY) * DAY;

    // NOTE: Use DirectPExecute for tables that will be queried later

    // get the current reset times for normal instances (these may need to be updated)
    // these are only kept in memory for InstanceSaves that are loaded later
    // resettime = 0 in the DB for raid/heroic instances so those are skipped
    typedef std::map<uint32, std::pair<uint32, uint64> > ResetTimeMapType;
    ResetTimeMapType InstResetTime;
    QueryResult *result = CharacterDatabase.Query("SELECT id, map, resettime FROM instance WHERE resettime > 0");
    if( result )
    {
        do
        {
            if(uint64 resettime = (*result)[2].GetUInt64())
            {
                uint32 id = (*result)[0].GetUInt32();
                uint32 mapid = (*result)[1].GetUInt32();
                InstResetTime[id] = std::pair<uint32, uint64>(mapid, resettime);
            }
        }
        while (result->NextRow());
        delete result;

        // update reset time for normal instances with the max creature respawn time + X hours
        result = WorldDatabase.Query("SELECT MAX(respawntime), instance FROM creature_respawn WHERE instance > 0 GROUP BY instance");
        if( result )
        {
            do
            {
                Field *fields = result->Fetch();
                uint32 instance = fields[1].GetUInt32();
                uint64 resettime = fields[0].GetUInt64() + 2 * HOUR;
                ResetTimeMapType::iterator itr = InstResetTime.find(instance);
                if(itr != InstResetTime.end() && itr->second.second != resettime)
                {
                    CharacterDatabase.DirectPExecute("UPDATE instance SET resettime = '"I64FMTD"' WHERE id = '%u'", resettime, instance);
                    itr->second.second = resettime;
                }
            }
            while (result->NextRow());
            delete result;
        }

        // schedule the reset times
        for(ResetTimeMapType::iterator itr = InstResetTime.begin(); itr != InstResetTime.end(); ++itr)
            if(itr->second.second > now)
                ScheduleReset(true, itr->second.second, InstResetEvent(0, itr->second.first, itr->first));
    }

    // load the global respawn times for raid/heroic instances
    uint32 diff = sWorld.getConfig(CONFIG_INSTANCE_RESET_TIME_HOUR) * HOUR;
    m_resetTimeByMapId.resize(sMapStore.GetNumRows()+1);
    result = CharacterDatabase.Query("SELECT mapid, resettime FROM instance_reset");
    if(result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 mapid = fields[0].GetUInt32();
            if(!objmgr.GetInstanceTemplate(mapid))
            {
                sLog.outError("InstanceSaveManager::LoadResetTimes: invalid mapid %u in instance_reset!", mapid);
                CharacterDatabase.DirectPExecute("DELETE FROM instance_reset WHERE mapid = '%u'", mapid);
                continue;
            }

            // update the reset time if the hour in the configs changes
            uint64 oldresettime = fields[1].GetUInt64();
            uint64 newresettime = (oldresettime / DAY) * DAY + diff;
            if(oldresettime != newresettime)
                CharacterDatabase.DirectPExecute("UPDATE instance_reset SET resettime = '"I64FMTD"' WHERE mapid = '%u'", newresettime, mapid);

            m_resetTimeByMapId[mapid] = newresettime;
        } while(result->NextRow());
        delete result;
    }

    // clean expired instances, references to them will be deleted in CleanupInstances
    // must be done before calculating new reset times
    _DelHelper(CharacterDatabase, "id, map, difficulty", "instance", "LEFT JOIN instance_reset ON mapid = map WHERE (instance.resettime < '"I64FMTD"' AND instance.resettime > '0') OR (NOT instance_reset.resettime IS NULL AND instance_reset.resettime < '"I64FMTD"')",  (uint64)now, (uint64)now);

    // calculate new global reset times for expired instances and those that have never been reset yet
    // add the global reset times to the priority queue
    for(uint32 i = 0; i < sInstanceTemplate.MaxEntry; i++)
    {
        InstanceTemplate* temp = (InstanceTemplate*)objmgr.GetInstanceTemplate(i);
        if(!temp) continue;
        // only raid/heroic maps have a global reset time
        const MapEntry* entry = sMapStore.LookupEntry(temp->map);
        if(!entry || !entry->HasResetTime())
            continue;

        uint32 period = temp->reset_delay * DAY;
        assert(period != 0);
        time_t t = m_resetTimeByMapId[temp->map];
        if(!t)
        {
            // initialize the reset time
            t = today + period + diff;
            CharacterDatabase.DirectPExecute("INSERT INTO instance_reset VALUES ('%u','"I64FMTD"')", i, (uint64)t);
        }

        if(t < now)
        {
            // assume that expired instances have already been cleaned
            // calculate the next reset time
            t = (t / DAY) * DAY;
            t += ((today - t) / period + 1) * period + diff;
            CharacterDatabase.DirectPExecute("UPDATE instance_reset SET resettime = '"I64FMTD"' WHERE mapid = '%u'", (uint64)t, i);
        }

        m_resetTimeByMapId[temp->map] = t;

        // schedule the global reset/warning
        uint8 type = 1;
        static int tim[4] = {3600, 900, 300, 60};
        for(; type < 4; type++)
            if(t - tim[type-1] > now) break;
        ScheduleReset(true, t - tim[type-1], InstResetEvent(type, i));
    }
}

void InstanceSaveManager::ScheduleReset(bool add, time_t time, InstResetEvent event)
{
    if(add) m_resetTimeQueue.insert(std::pair<time_t, InstResetEvent>(time, event));
    else
    {
        // find the event in the queue and remove it
        ResetTimeQueue::iterator itr;
        std::pair<ResetTimeQueue::iterator, ResetTimeQueue::iterator> range;
        range = m_resetTimeQueue.equal_range(time);
        for(itr = range.first; itr != range.second; ++itr)
            if(itr->second == event) { m_resetTimeQueue.erase(itr); return; }
        // in case the reset time changed (should happen very rarely), we search the whole queue
        if(itr == range.second)
        {
            for(itr = m_resetTimeQueue.begin(); itr != m_resetTimeQueue.end(); ++itr)
                if(itr->second == event) { m_resetTimeQueue.erase(itr); return; }
            if(itr == m_resetTimeQueue.end())
                sLog.outError("InstanceSaveManager::ScheduleReset: cannot cancel the reset, the event(%d,%d,%d) was not found!", event.type, event.mapid, event.instanceId);
        }
    }
}

void InstanceSaveManager::Update()
{
    time_t now = time(NULL), t;
    while(!m_resetTimeQueue.empty() && (t = m_resetTimeQueue.begin()->first) < now)
    {
        InstResetEvent &event = m_resetTimeQueue.begin()->second;
        if(event.type == 0)
        {
            // for individual normal instances, max creature respawn + X hours
            _ResetInstance(event.mapid, event.instanceId);
            m_resetTimeQueue.erase(m_resetTimeQueue.begin());
        }
        else
        {
            // global reset/warning for a certain map
            time_t resetTime = GetResetTimeFor(event.mapid);
            _ResetOrWarnAll(event.mapid, event.type != 4, resetTime - now);
            if(event.type != 4)
            {
                // schedule the next warning/reset
                event.type++;
                static int tim[4] = {3600, 900, 300, 60};
                ScheduleReset(true, resetTime - tim[event.type-1], event);
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
    while(!pList.empty())
    {
        Player *player = *(pList.begin());
        player->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }
    InstanceSave::GroupListType &gList = itr->second->m_groupList;
    while(!gList.empty())
    {
        Group *group = *(gList.begin());
        group->UnbindInstance(itr->second->GetMapId(), itr->second->GetDifficulty(), true);
    }
    m_instanceSaveById.erase(itr++);
    lock_instLists = false;
}

void InstanceSaveManager::_ResetInstance(uint32 mapid, uint32 instanceId)
{
    sLog.outDebug("InstanceSaveMgr::_ResetInstance %u, %u", mapid, instanceId);
    Map *map = (MapInstanced*)MapManager::Instance().GetBaseMap(mapid);
    if(!map->Instanceable())
        return;

    InstanceSaveHashMap::iterator itr = m_instanceSaveById.find(instanceId);
    if(itr != m_instanceSaveById.end()) _ResetSave(itr);
    DeleteInstanceFromDB(instanceId);                       // even if save not loaded

    Map* iMap = ((MapInstanced*)map)->FindMap(instanceId);
    if(iMap && iMap->IsDungeon()) ((InstanceMap*)iMap)->Reset(INSTANCE_RESET_RESPAWN_DELAY);
    else objmgr.DeleteRespawnTimeForInstance(instanceId);   // even if map is not loaded
}

void InstanceSaveManager::_ResetOrWarnAll(uint32 mapid, bool warn, uint32 timeLeft)
{
    // global reset for all instances of the given map
    // note: this isn't fast but it's meant to be executed very rarely
    Map *map = (MapInstanced*)MapManager::Instance().GetBaseMap(mapid);
    if(!map->Instanceable())
        return;
    uint64 now = (uint64)time(NULL);

    if(!warn)
    {
        // this is called one minute before the reset time
        InstanceTemplate* temp = (InstanceTemplate*)objmgr.GetInstanceTemplate(mapid);
        if(!temp || !temp->reset_delay)
        {
            sLog.outError("InstanceSaveManager::ResetOrWarnAll: no instance template or reset delay for map %d", mapid);
            return;
        }

        // remove all binds to instances of the given map
        for(InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end();)
        {
            if(itr->second->GetMapId() == mapid)
                _ResetSave(itr);
            else
                ++itr;
        }

        // delete them from the DB, even if not loaded
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM character_instance USING character_instance LEFT JOIN instance ON character_instance.instance = id WHERE map = '%u'", mapid);
        CharacterDatabase.PExecute("DELETE FROM group_instance USING group_instance LEFT JOIN instance ON group_instance.instance = id WHERE map = '%u'", mapid);
        CharacterDatabase.PExecute("DELETE FROM instance WHERE map = '%u'", mapid);
        CharacterDatabase.CommitTransaction();

        // calculate the next reset time
        uint32 diff = sWorld.getConfig(CONFIG_INSTANCE_RESET_TIME_HOUR) * HOUR;
        uint32 period = temp->reset_delay * DAY;
        uint64 next_reset = ((now + timeLeft + MINUTE) / DAY * DAY) + period + diff;
        // update it in the DB
        CharacterDatabase.PExecute("UPDATE instance_reset SET resettime = '"I64FMTD"' WHERE mapid = '%d'", next_reset, mapid);
    }

    MapInstanced::InstancedMaps &instMaps = ((MapInstanced*)map)->GetInstancedMaps();
    MapInstanced::InstancedMaps::iterator mitr;
    for(mitr = instMaps.begin(); mitr != instMaps.end(); ++mitr)
    {
        Map *map = mitr->second;
        if(!map->IsDungeon()) continue;
        if(warn) ((InstanceMap*)map)->SendResetWarnings(timeLeft);
        else ((InstanceMap*)map)->Reset(INSTANCE_RESET_GLOBAL);
    }

    // TODO: delete creature/gameobject respawn times even if the maps are not loaded
}

uint32 InstanceSaveManager::GetNumBoundPlayersTotal()
{
    uint32 ret = 0;
    for(InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetPlayerCount();
    return ret;
}

uint32 InstanceSaveManager::GetNumBoundGroupsTotal()
{
    uint32 ret = 0;
    for(InstanceSaveHashMap::iterator itr = m_instanceSaveById.begin(); itr != m_instanceSaveById.end(); ++itr)
        ret += itr->second->GetGroupCount();
    return ret;
}

