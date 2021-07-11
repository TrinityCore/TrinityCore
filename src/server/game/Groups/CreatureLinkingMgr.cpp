/*
* This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
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

/**
* @addtogroup npc_linking
* @{
*
* @file CreatureLinkingMgr.cpp
* This file contains the code needed for MaNGOS to link npcs together
* Currently implemented
* - Aggro on boss aggro, also reversed
* - Despawning/ Selfkill on death of mob if the NPC it is linked to dies
* - Respawning on leaving combat if the linked to NPC evades, also reversed
* - Respawning on death of the linked to NPC
* - (Re)Spawning dependend on boss Alive/ Dead
* - Following NPCs
*
*/

#include "CreatureLinkingMgr.h"
#include "Policies/Singleton.h"
#include "ProgressBar.h"
#include "Database/DatabaseEnv.h"
#include "ObjectMgr.h"
#include "SharedDefines.h"
#include "Creature.h"
#include "CreatureAI.h"

INSTANTIATE_SINGLETON_1(CreatureLinkingMgr);

#define INVALID_MAP_ID      0xFFFFFFFF

/* *********************************************************
* Method to Load From DB
* DB Format:   entry, map, master_entry, flag, search_radius   for `creature_linking_template` (by entry)
*              0      1    2             3     4
* DB Format:   guid, master_guid, flag                         for `creature_linking` (by guid)
*              0     1            2
* **************************************
* entry/guid:                  creature_template.entry/guid
* map:                         Map on which the NPC has to be
* master_entry/master_guid     creature_template.entry of the npc, that shall trigger the actions
* flag:                        flag value, of type CreatureLinkingFlags
* search_radius:               radius, in which master and slave must be spawned so that they are linked together
*
* ***************************************************** */

void CreatureLinkingMgr::LoadFromDB()
{
    // Clear maps
    m_creatureLinkingMap.clear();
    m_creatureLinkingGuidMap.clear();
    m_eventTriggers.clear();                              // master
    m_eventGuidTriggers.clear();

    // Load `creature_linking_template`
    sLog.outString("> Loading table `creature_linking_template`");
    uint32 count = 0;
    std::unique_ptr<QueryResult> result(WorldDatabase.Query("SELECT `entry`, `map`, `master_entry`, `flag`, `search_range` FROM `creature_linking_template`"));
    if (!result)
    {
        BarGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Table creature_linking_template is empty.");
    }
    else
    {
        BarGoLink bar((int)result->GetRowCount());
        do
        {
            bar.step();
            Field* fields = result->Fetch();

            CreatureLinkingInfo tmp;

            uint32 entry = fields[0].GetUInt32();
            tmp.mapId = fields[1].GetUInt32();
            tmp.masterId = fields[2].GetUInt32();
            tmp.linkingFlag = fields[3].GetUInt16();
            tmp.searchRange = fields[4].GetUInt16();
            tmp.masterDBGuid = 0;                        // Will be initialized for unique mobs in IsLinkingEntryValid (only for spawning dependend)

            if (!IsLinkingEntryValid(entry, &tmp, true))
                continue;

            ++count;

            // Add it to the map
            m_creatureLinkingMap.insert(CreatureLinkingMap::value_type(entry, tmp));

            // Store master_entry
            m_eventTriggers.insert(tmp.masterId);
        } while (result->NextRow());

        sLog.outString();
        sLog.outString(">> Loaded creature linking for %u creature-entries", count);
    }

    // Load `creature_linking`
    sLog.outString("> Loading table `creature_linking`");
    count = 0;
    result.reset(WorldDatabase.Query("SELECT `guid`, `master_guid`, `flag` FROM `creature_linking`"));
    if (!result)
    {
        BarGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Table creature_linking is empty.");
        return;
    }

    BarGoLink guidBar((int)result->GetRowCount());
    do
    {
        guidBar.step();

        Field* fields = result->Fetch();
        CreatureLinkingInfo tmp;

        uint32 guid = fields[0].GetUInt32();
        tmp.mapId = INVALID_MAP_ID;           // some invalid value, this marks the guid-linking
        tmp.masterId = fields[1].GetUInt32();
        tmp.linkingFlag = fields[2].GetUInt16();
        tmp.masterDBGuid = tmp.masterId;
        tmp.searchRange = 0;

        if (!IsLinkingEntryValid(guid, &tmp, false))
            continue;

        ++count;

        // Add it to the map
        m_creatureLinkingGuidMap.insert(CreatureLinkingMap::value_type(guid, tmp));

        // Store master_guid
        m_eventGuidTriggers.insert(tmp.masterId);
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded creature linking for %u creature-Guids", count);
}

/** This function is used to check if a DB-Entry is valid
*
*  @param byEntry: is the first parameter of the function a npc entry or a npc guid?
*  @param slaveEntry: dependend on byEntry param this is either the slave's npc-entry or the npc-guid
*  @param pTmp: Information about the CreatureLinking of the npc. Note that this information may be changed in some cases
*
*  In case of checking by entry and in case of linked spawning and searchRange == 0, pTmp will be changed to keep information about the (unique!) master's db-guid
*/
bool CreatureLinkingMgr::IsLinkingEntryValid(uint32 slaveEntry, CreatureLinkingInfo* pTmp, bool byEntry)
{
    // Basic checks first
    if (byEntry)                                            // Entry given
    {
        CreatureInfo const* pInfo = ObjectMgr::GetCreatureTemplate(slaveEntry);
        CreatureInfo const* pMasterInfo = ObjectMgr::GetCreatureTemplate(pTmp->masterId);

        if (!pInfo)
        {
            if (!sObjectMgr.IsExistingCreatureId(slaveEntry))
                sLog.outErrorDb("`creature_linking_template` has a non existing slave_entry (slave: %u, master %u), skipped.", slaveEntry, pTmp->masterId);
            return false;
        }
        if (!pMasterInfo)
        {
            if (!sObjectMgr.IsExistingCreatureId(pTmp->masterId))
                sLog.outErrorDb("`creature_linking_template` has a non existing master_entry (slave: %u, master %u), skipped", slaveEntry, pTmp->masterId);
            return false;
        }
        if (pTmp->mapId && !sMapStorage.LookupEntry<MapEntry>(pTmp->mapId))
        {
            sLog.outErrorDb("`creature_linking_template` has a non existing map %u (slave %u, master %u), skipped", pTmp->mapId, slaveEntry, pTmp->masterId);
            return false;
        }
    }
    else                                                    // guid given
    {
        CreatureData const* slaveData = sObjectMgr.GetCreatureData(slaveEntry);
        CreatureData const* masterData = sObjectMgr.GetCreatureData(pTmp->masterId);

        if (!slaveData)
        {
            if (!sObjectMgr.IsExistingCreatureGuid(slaveEntry))
                sLog.outErrorDb("`creature_linking` has a non existing slave (guid: %u, master_guid %u), skipped", slaveEntry, pTmp->masterId);
            return false;
        }
        if (!masterData)
        {
            if (!sObjectMgr.IsExistingCreatureGuid(pTmp->masterId))
                sLog.outErrorDb("`creature_linking` has a non existing master (guid: %u,, master_guid: %u), skipped", slaveEntry, pTmp->masterId);
            return false;
        }
        if (slaveData->position.mapId != masterData->position.mapId)
        {
            sLog.outErrorDb("`creature_linking` has a slave and master on different maps (guid: %u, master_guid: %u), skipped", slaveEntry, pTmp->masterId);
            return false;
        }
    }

    if (pTmp->linkingFlag & ~(LINKING_FLAG_INVALID - 1) || pTmp->linkingFlag == 0)
    {
        sLog.outErrorDb("`creature_linking%s` has invalid flag, (entry: %u, map: %u, flags: %u), skipped", byEntry ? "_template" : "", slaveEntry, pTmp->mapId, pTmp->linkingFlag);
        return false;
    }

    // Additional checks, depending on flags
    if (pTmp->linkingFlag & FLAG_DESPAWN_ON_RESPAWN && slaveEntry == pTmp->masterId)
    {
        sLog.outErrorDb("`creature_linking%s` has pointless FLAG_DESPAWN_ON_RESPAWN for self, (entry: %u, map: %u), skipped", byEntry ? "_template" : "", slaveEntry, pTmp->mapId);
        return false;
    }

    if (byEntry)
    {
        // Check for uniqueness of mob whom is followed, on whom spawning is dependend
        if (pTmp->searchRange == 0 && pTmp->linkingFlag & (FLAG_FOLLOW | FLAG_CANT_SPAWN_IF_BOSS_DEAD | FLAG_CANT_SPAWN_IF_BOSS_ALIVE))
        {
            QueryResult* result = WorldDatabase.PQuery("SELECT guid FROM creature WHERE id=%u AND map=%u LIMIT 2", pTmp->masterId, pTmp->mapId);
            if (!result)
            {
                sLog.outErrorDb("`creature_linking_template` has FLAG_FOLLOW, but no master, (entry: %u, map: %u, master: %u)", slaveEntry, pTmp->mapId, pTmp->masterId);
                return false;
            }

            if (result->GetRowCount() > 1)
            {
                sLog.outErrorDb("`creature_linking_template` has FLAG_FOLLOW, but non unique master, (entry: %u, map: %u, master: %u)", slaveEntry, pTmp->mapId, pTmp->masterId);
                delete result;
                return false;
            }
            Field* fields = result->Fetch();
            pTmp->masterDBGuid = fields[0].GetUInt32();
            delete result;
        }
    }

    // All checks are passed, entry/guid is valid
    return true;
}

// Linked actions and corresponding flags
enum EventMask
{
    EVENT_MASK_ON_AGGRO = FLAG_AGGRO_ON_AGGRO,
    EVENT_MASK_ON_EVADE = FLAG_RESPAWN_ON_EVADE | FLAG_DESPAWN_ON_EVADE,
    EVENT_MASK_ON_DIE = FLAG_DESPAWN_ON_DEATH | FLAG_SELFKILL_ON_DEATH | FLAG_RESPAWN_ON_DEATH | FLAG_FOLLOW,
    EVENT_MASK_ON_RESPAWN = FLAG_RESPAWN_ON_RESPAWN | FLAG_DESPAWN_ON_RESPAWN | FLAG_FOLLOW,
    EVENT_MASK_TRIGGER_TO = FLAG_TO_AGGRO_ON_AGGRO | FLAG_TO_RESPAWN_ON_EVADE | FLAG_FOLLOW,
    EVENT_MASK_ON_DESPAWN = FLAG_DESPAWN_ON_DESPAWN,
};

// This functions checks if the NPC has linked NPCs for dynamic action
bool CreatureLinkingMgr::IsLinkedEventTrigger(Creature* pCreature) const
{
    // Entry case
    if (m_eventTriggers.find(pCreature->GetEntry()) != m_eventTriggers.end())
        return true;

    // Guid case
    if (m_eventGuidTriggers.find(pCreature->GetGUIDLow()) != m_eventGuidTriggers.end())
        return true;

    // Also return true for npcs that trigger reverse actions, or for followers(needed in respawn)
    if (CreatureLinkingInfo const* pInfo = GetLinkedTriggerInformation(pCreature))
        return !!(pInfo->linkingFlag & EVENT_MASK_TRIGGER_TO);

    return false;
}

// This function check if the NPC is a master to other NPCs
// return true only for masters stored by entry - this prevents adding them to master-holder maps
bool CreatureLinkingMgr::IsLinkedMaster(Creature* pCreature) const
{
    return m_eventTriggers.find(pCreature->GetEntry()) != m_eventTriggers.end();
}

// This function checks if the spawning of this NPC is dependend on other NPCs
bool CreatureLinkingMgr::IsSpawnedByLinkedMob(Creature* pCreature) const
{
    return IsSpawnedByLinkedMob(GetLinkedTriggerInformation(pCreature));
}
bool CreatureLinkingMgr::IsSpawnedByLinkedMob(CreatureLinkingInfo const* pInfo) const
{
    return pInfo && pInfo->linkingFlag & (FLAG_CANT_SPAWN_IF_BOSS_DEAD | FLAG_CANT_SPAWN_IF_BOSS_ALIVE) && (pInfo->masterDBGuid || pInfo->searchRange);
}

// This gives the information of a linked NPC (describes action when its ActionTrigger triggers)
// Depends of the map
CreatureLinkingInfo const* CreatureLinkingMgr::GetLinkedTriggerInformation(Creature* pCreature) const
{
    return GetLinkedTriggerInformation(pCreature->GetEntry(), pCreature->GetGUIDLow(), pCreature->GetMapId());
}
CreatureLinkingInfo const* CreatureLinkingMgr::GetLinkedTriggerInformation(uint32 entry, uint32 lowGuid, uint32 mapId) const
{
    // guid case
    CreatureLinkingMapBounds bounds = m_creatureLinkingGuidMap.equal_range(lowGuid);
    for (CreatureLinkingMap::const_iterator iter = bounds.first; iter != bounds.second;)
        return &(iter->second);

    // entry case
    bounds = m_creatureLinkingMap.equal_range(entry);
    for (CreatureLinkingMap::const_iterator iter = bounds.first; iter != bounds.second; ++iter)
    {
        if (iter->second.mapId == mapId)
            return &(iter->second);
    }

    return nullptr;
}

// Function to add slave-NPCs to the holder
void CreatureLinkingHolder::AddSlaveToHolder(Creature* pCreature)
{
    CreatureLinkingInfo const* pInfo = sCreatureLinkingMgr.GetLinkedTriggerInformation(pCreature);
    if (!pInfo)
        return;

    if (pInfo->mapId == INVALID_MAP_ID)                     // Guid case, store master->slaves for fast access
    {
        HolderMapBounds bounds = m_holderGuidMap.equal_range(pInfo->masterId);
        for (HolderMap::iterator itr = bounds.first; itr != bounds.second; ++itr)
        {
            if (itr->second.linkingFlag == pInfo->linkingFlag)
            {
                itr->second.linkedGuids.push_back(pCreature->GetObjectGuid());
                pCreature = nullptr;                           // Store that is was handled
                break;
            }
        }

        // If this is a new flag, insert new entry
        if (pCreature)
        {
            InfoAndGuids tmp;
            tmp.linkedGuids.push_back(pCreature->GetObjectGuid());
            tmp.linkingFlag = pInfo->linkingFlag;
            tmp.searchRange = 0;
            m_holderGuidMap.insert(HolderMap::value_type(pInfo->masterId, tmp));
        }
        return;
    }

    // First try to find holder with same flag
    HolderMapBounds bounds = m_holderMap.equal_range(pInfo->masterId);
    for (HolderMap::iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        if (itr->second.linkingFlag == pInfo->linkingFlag && itr->second.searchRange == pInfo->searchRange)
        {
            itr->second.linkedGuids.push_back(pCreature->GetObjectGuid());
            pCreature = nullptr;                               // Store that is was handled
            break;
        }
    }

    // If this is a new flag, insert new entry
    if (pCreature)
    {
        InfoAndGuids tmp;
        tmp.linkedGuids.push_back(pCreature->GetObjectGuid());
        tmp.linkingFlag = pInfo->linkingFlag;
        tmp.searchRange = pInfo->searchRange;
        m_holderMap.insert(HolderMap::value_type(pInfo->masterId, tmp));
    }
}

// Function to add master-NPCs to the holder
void CreatureLinkingHolder::AddMasterToHolder(Creature* pCreature)
{
    if (pCreature->IsPet())
        return;

    // Only add master NPCs (by entry)
    if (!sCreatureLinkingMgr.IsLinkedMaster(pCreature))
        return;

    // Check, if already stored
    BossGuidMapBounds bounds = m_masterGuid.equal_range(pCreature->GetEntry());
    for (BossGuidMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
        if (itr->second == pCreature->GetObjectGuid())
            return;                                         // Already added

    m_masterGuid.insert(BossGuidMap::value_type(pCreature->GetEntry(), pCreature->GetObjectGuid()));
}

// Function to process actions for linked NPCs
void CreatureLinkingHolder::DoCreatureLinkingEvent(CreatureLinkingEvent eventType, Creature* pSource, Unit* pEnemy /* = nullptr*/)
{
    // This check will be needed in reload case
    if (!sCreatureLinkingMgr.IsLinkedEventTrigger(pSource))
        return;

    // Ignore atypic behaviour
    if (pSource->IsControlledByPlayer())
        return;

    if (eventType == LINKING_EVENT_AGGRO && !pEnemy)
        return;

    uint32 eventFlagFilter = 0;
    uint32 reverseEventFlagFilter = 0;

    switch (eventType)
    {
    case LINKING_EVENT_AGGRO:   eventFlagFilter = EVENT_MASK_ON_AGGRO;   reverseEventFlagFilter = FLAG_TO_AGGRO_ON_AGGRO;   break;
    case LINKING_EVENT_EVADE:   eventFlagFilter = EVENT_MASK_ON_EVADE;   reverseEventFlagFilter = FLAG_TO_RESPAWN_ON_EVADE; break;
    case LINKING_EVENT_DIE:     eventFlagFilter = EVENT_MASK_ON_DIE;     reverseEventFlagFilter = 0;                        break;
    case LINKING_EVENT_RESPAWN: eventFlagFilter = EVENT_MASK_ON_RESPAWN; reverseEventFlagFilter = FLAG_FOLLOW;              break;
    case LINKING_EVENT_DESPAWN: eventFlagFilter = EVENT_MASK_ON_DESPAWN; reverseEventFlagFilter = 0;                        break;
    }

    // Process Slaves (by entry)
    HolderMapBounds bounds = m_holderMap.equal_range(pSource->GetEntry());
    for (HolderMap::iterator itr = bounds.first; itr != bounds.second; ++itr)
        ProcessSlaveGuidList(eventType, pSource, itr->second.linkingFlag & eventFlagFilter, itr->second.searchRange, itr->second.linkedGuids, pEnemy);

    // Process Slaves (by guid)
    bounds = m_holderGuidMap.equal_range(pSource->GetGUIDLow());
    for (HolderMap::iterator itr = bounds.first; itr != bounds.second; ++itr)
        ProcessSlaveGuidList(eventType, pSource, itr->second.linkingFlag & eventFlagFilter, itr->second.searchRange, itr->second.linkedGuids, pEnemy);

    // Process Master
    if (CreatureLinkingInfo const* pInfo = sCreatureLinkingMgr.GetLinkedTriggerInformation(pSource))
    {
        if (pInfo->linkingFlag & reverseEventFlagFilter)
        {
            Creature* pMaster = nullptr;
            if (pInfo->mapId != INVALID_MAP_ID)             // entry case
            {
                BossGuidMapBounds finds = m_masterGuid.equal_range(pInfo->masterId);
                for (BossGuidMap::const_iterator itr = finds.first; itr != finds.second; ++itr)
                {
                    pMaster = pSource->GetMap()->GetCreature(itr->second);
                    if (pMaster && IsSlaveInRangeOfBoss(pSource, pMaster, pInfo->searchRange))
                        break;
                }
            }
            else                                            // guid case
            {
                CreatureData const* masterData = sObjectMgr.GetCreatureData(pInfo->masterDBGuid);
                CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(masterData->creature_id[0]);
                pMaster = pSource->GetMap()->GetCreature(ObjectGuid(cInfo->GetHighGuid(), cInfo->entry, pInfo->masterDBGuid));
            }

            if (pMaster)
            {
                switch (eventType)
                {
                case LINKING_EVENT_AGGRO:
                    if (pMaster->IsControlledByPlayer())
                        return;

                    if (pMaster->IsInCombat())
                        pMaster->SetInCombatWith(pEnemy);
                    else
                        pMaster->AI()->AttackStart(pEnemy);
                    break;
                case LINKING_EVENT_EVADE:
                    if (!pMaster->IsAlive())
                        pMaster->Respawn();
                    break;
                case LINKING_EVENT_RESPAWN:
                    if (pMaster->IsAlive())
                        SetFollowing(pSource, pMaster);
                    break;
                case LINKING_EVENT_DIE:                 // Nothing linked for this case
                case LINKING_EVENT_DESPAWN:             // Nothing linked for this case
                    break;
                }
            }
        }
    }
}

// Helper function, to process a slave list
void CreatureLinkingHolder::ProcessSlaveGuidList(CreatureLinkingEvent eventType, Creature* pSource, uint32 flag, uint16 searchRange, GuidList& slaveGuidList, Unit* pEnemy)
{
    if (!flag)
        return;

    for (GuidList::iterator slave_itr = slaveGuidList.begin(); slave_itr != slaveGuidList.end();)
    {
        Creature* pSlave = pSource->GetMap()->GetCreature(*slave_itr);
        if (!pSlave)
        {
            // Remove old guid first
            slaveGuidList.erase(slave_itr++);
            continue;
        }

        ++slave_itr;

        // Ignore Pets
        if (pSlave->IsPet())
            continue;

        // Handle single slave
        if (IsSlaveInRangeOfBoss(pSlave, pSource, searchRange))
            ProcessSlave(eventType, pSource, flag, pSlave, pEnemy);
    }
}

// Helper function, to process a single slave
void CreatureLinkingHolder::ProcessSlave(CreatureLinkingEvent eventType, Creature* pSource, uint32 flag, Creature* pSlave, Unit* pEnemy)
{
    switch (eventType)
    {
    case LINKING_EVENT_AGGRO:
        if (flag & FLAG_AGGRO_ON_AGGRO)
        {
            if (pSlave->IsControlledByPlayer())
                return;

            if (pSlave->IsInCombat())
            {
                if (pSource->GetMap()->IsDungeon() && pSource->HasExtraFlag(CREATURE_FLAG_EXTRA_AGGRO_ZONE))
                    pSlave->SetInCombatWithZone();
                else
                    pSlave->SetInCombatWith(pEnemy);
            }
            else {
                pSlave->AI()->AttackStart(pEnemy);
                if (pSource->GetMap()->IsDungeon() && pSource->HasExtraFlag(CREATURE_FLAG_EXTRA_AGGRO_ZONE))
                    pSlave->SetInCombatWithZone();
            }
        }
        break;
    case LINKING_EVENT_EVADE:
        if (flag & FLAG_DESPAWN_ON_EVADE && pSlave->IsAlive())
            pSlave->ForcedDespawn();
        if (flag & FLAG_RESPAWN_ON_EVADE && !pSlave->IsAlive())
            pSlave->Respawn();
        break;
    case LINKING_EVENT_DIE:
        if (flag & FLAG_SELFKILL_ON_DEATH && pSlave->IsAlive())
            pSlave->DealDamage(pSlave, pSlave->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        if (flag & FLAG_DESPAWN_ON_DEATH && pSlave->IsAlive())
            pSlave->ForcedDespawn();
        if (flag & FLAG_RESPAWN_ON_DEATH && !pSlave->IsAlive())
            pSlave->Respawn();
        break;
    case LINKING_EVENT_RESPAWN:
        if (flag & FLAG_RESPAWN_ON_RESPAWN)
        {
            // Additional check to prevent endless loops (in case whole group respawns on first respawn)
            if (!pSlave->IsAlive() && pSlave->GetRespawnTime() > time(nullptr))
                pSlave->Respawn();
        }
        else if (flag & FLAG_DESPAWN_ON_RESPAWN && pSlave->IsAlive())
            pSlave->ForcedDespawn();

        if (flag & FLAG_FOLLOW && pSlave->IsAlive() && !pSlave->IsInCombat())
            SetFollowing(pSlave, pSource);

        break;
    case LINKING_EVENT_DESPAWN:
        if (flag & FLAG_DESPAWN_ON_DESPAWN && !pSlave->IsDespawned())
            pSlave->ForcedDespawn();

        break;
    }
}

// Helper function to set following
void CreatureLinkingHolder::SetFollowing(Creature* pWho, Creature* pWhom) const
{
    // Do some calculations
    float sX, sY, sZ, mX, mY, mZ, mO;
    pWho->GetRespawnCoord(sX, sY, sZ);
    pWhom->GetRespawnCoord(mX, mY, mZ, &mO);

    float dx, dy, dz;
    dx = sX - mX;
    dy = sY - mY;
    dz = sZ - mZ;

    float dist = sqrt(dx * dx + dy * dy + dz * dz);
    // REMARK: This code needs the same distance calculation that is used for following
    // Atm this means we have to subtract the bounding radiuses
    dist = dist - pWho->GetObjectBoundingRadius() - pWhom->GetObjectBoundingRadius();
    if (dist < 0.0f)
        dist = 0.0f;

    // Need to pass the relative angle to following
    float angle = atan2(dy, dx) - mO;
    angle = (angle >= 0) ? angle : 2 * M_PI_F + angle;

    pWho->GetMotionMaster()->MoveFollow(pWhom, dist, angle);
}

// Function to check if a slave belongs to a boss by range-issue
bool CreatureLinkingHolder::IsSlaveInRangeOfBoss(Creature const* pSlave, Creature const* pBoss, uint16 searchRange) const
{
    float sX, sY, sZ;
    pSlave->GetRespawnCoord(sX, sY, sZ);
    return IsSlaveInRangeOfBoss(pBoss, sX, sY, searchRange);
}
bool CreatureLinkingHolder::IsSlaveInRangeOfBoss(Creature const* pBoss, float sX, float sY, uint16 searchRange) const
{
    if (!searchRange)
        return true;

    // Do some calculations
    float mX, mY, mZ, dx, dy;
    pBoss->GetRespawnCoord(mX, mY, mZ);

    dx = sX - mX;
    dy = sY - mY;

    return dx * dx + dy * dy < searchRange * searchRange;
}

// helper function to check if a lowguid can respawn
bool CreatureLinkingHolder::IsRespawnReady(uint32 dbLowGuid, Map* _map) const
{
    time_t respawnTime = _map->GetPersistentState()->GetCreatureRespawnTime(dbLowGuid);
    return (!respawnTime || respawnTime <= time(nullptr)) && CanSpawn(dbLowGuid, _map, nullptr, 0.0f, 0.0f);
}

// Function to check if a passive spawning condition is met
bool CreatureLinkingHolder::CanSpawn(Creature* pCreature) const
{
    CreatureLinkingInfo const*  pInfo = sCreatureLinkingMgr.GetLinkedTriggerInformation(pCreature);
    if (!pInfo)
        return true;

    float sx, sy, sz;
    pCreature->GetRespawnCoord(sx, sy, sz);
    return CanSpawn(0, pCreature->GetMap(), pInfo, sx, sy);
}

/** Worker function to check if a spawning condition is met
*
*  This function is used directly from above function, and for recursive use
*   in case of recursive use it is used only on _map with information of lowGuid.
*
*  @param lowGuid (only relevant in case of recursive uses) -- db-guid of the npc that is checked
*  @param _map Map on which things are checked
*  @param pInfo (only shipped in case of initial use) -- used as marker of first use, also in first use filled directly
*  @param sx, sy (spawn position of the checked npc with initial use)
*/
bool CreatureLinkingHolder::CanSpawn(uint32 lowGuid, Map* _map, CreatureLinkingInfo const*  pInfo, float sx, float sy) const
{
    if (!pInfo)                                             // Prepare data for recursive use
    {
        CreatureData const* data = sObjectMgr.GetCreatureData(lowGuid);
        if (!data)
            return true;
        pInfo = sCreatureLinkingMgr.GetLinkedTriggerInformation(data->creature_id[0], lowGuid, data->position.mapId);
        if (!pInfo)
            return true;
        // Has lowGuid npc actually spawning linked?
        if (!sCreatureLinkingMgr.IsSpawnedByLinkedMob(pInfo))
            return true;

        sx = data->position.x;                              // Fill position data
        sy = data->position.y;
    }

    if (pInfo->searchRange == 0)                            // Map wide case
    {
        if (!pInfo->masterDBGuid)
            return false;                                   // This should never happen

        if (pInfo->linkingFlag & FLAG_CANT_SPAWN_IF_BOSS_DEAD)
            return IsRespawnReady(pInfo->masterDBGuid, _map);
        else if (pInfo->linkingFlag & FLAG_CANT_SPAWN_IF_BOSS_ALIVE)
            return !IsRespawnReady(pInfo->masterDBGuid, _map);
        else
            return true;
    }

    // Search for nearby master
    BossGuidMapBounds finds = m_masterGuid.equal_range(pInfo->masterId);
    for (BossGuidMap::const_iterator itr = finds.first; itr != finds.second; ++itr)
    {
        Creature* pMaster = _map->GetCreature(itr->second);
        if (pMaster && IsSlaveInRangeOfBoss(pMaster, sx, sy, pInfo->searchRange))
        {
            if (pInfo->linkingFlag & FLAG_CANT_SPAWN_IF_BOSS_DEAD)
                return pMaster->IsAlive();
            else if (pInfo->linkingFlag & FLAG_CANT_SPAWN_IF_BOSS_ALIVE)
                return !pMaster->IsAlive();
            else
                return true;
        }
    }

    return true;                                            // local boss does not exist - spawn
}

// This function lets a slave refollow his master
bool CreatureLinkingHolder::TryFollowMaster(Creature* pCreature)
{
    CreatureLinkingInfo const*  pInfo = sCreatureLinkingMgr.GetLinkedTriggerInformation(pCreature);
    if (!pInfo || !(pInfo->linkingFlag & FLAG_FOLLOW))
        return false;

    Creature* pMaster = nullptr;
    if (pInfo->mapId != INVALID_MAP_ID)                     // entry case
    {
        BossGuidMapBounds finds = m_masterGuid.equal_range(pInfo->masterId);
        for (BossGuidMap::const_iterator itr = finds.first; itr != finds.second; ++itr)
        {
            pMaster = pCreature->GetMap()->GetCreature(itr->second);
            if (pMaster && IsSlaveInRangeOfBoss(pCreature, pMaster, pInfo->searchRange))
                break;
        }
    }
    else                                                    // guid case
    {
        CreatureData const* masterData = sObjectMgr.GetCreatureData(pInfo->masterDBGuid);
        CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(masterData->creature_id[0]);
        pMaster = pCreature->GetMap()->GetCreature(ObjectGuid(cInfo->GetHighGuid(), cInfo->entry, pInfo->masterDBGuid));
    }

    if (pMaster && pMaster->IsAlive())
    {
        SetFollowing(pCreature, pMaster);
        return true;
    }

    return false;
}

/*! @} */
