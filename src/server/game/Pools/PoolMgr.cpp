/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "PoolMgr.h"
#include "Containers.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "World.h"

////////////////////////////////////////////////////////////
// template class ActivePoolData

// Method that tell amount spawned objects/subpools
uint32 ActivePoolData::GetActiveObjectCount(uint32 pool_id) const
{
    ActivePoolPools::const_iterator itr = mSpawnedPools.find(pool_id);
    return itr != mSpawnedPools.end() ? itr->second : 0;
}

// Method that tell if a creature is spawned currently
template<>
bool ActivePoolData::IsActiveObject<Creature>(uint32 db_guid) const
{
    return mSpawnedCreatures.find(db_guid) != mSpawnedCreatures.end();
}

// Method that tell if a gameobject is spawned currently
template<>
bool ActivePoolData::IsActiveObject<GameObject>(uint32 db_guid) const
{
    return mSpawnedGameobjects.find(db_guid) != mSpawnedGameobjects.end();
}

// Method that tell if a pool is spawned currently
template<>
bool ActivePoolData::IsActiveObject<Pool>(uint32 sub_pool_id) const
{
    return mSpawnedPools.find(sub_pool_id) != mSpawnedPools.end();
}

// Method that tell if a quest can be started
template<>
bool ActivePoolData::IsActiveObject<Quest>(uint32 quest_id) const
{
    return mActiveQuests.find(quest_id) != mActiveQuests.end();
}

template<>
void ActivePoolData::ActivateObject<Creature>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedCreatures.insert(db_guid);
    ++mSpawnedPools[pool_id];
}

template<>
void ActivePoolData::ActivateObject<GameObject>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedGameobjects.insert(db_guid);
    ++mSpawnedPools[pool_id];
}

template<>
void ActivePoolData::ActivateObject<Pool>(uint32 sub_pool_id, uint32 pool_id)
{
    mSpawnedPools[sub_pool_id] = 0;
    ++mSpawnedPools[pool_id];
}

template<>
void ActivePoolData::ActivateObject<Quest>(uint32 quest_id, uint32 pool_id)
{
    mActiveQuests.insert(quest_id);
    ++mSpawnedPools[pool_id];
}

template<>
void ActivePoolData::RemoveObject<Creature>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedCreatures.erase(db_guid);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

template<>
void ActivePoolData::RemoveObject<GameObject>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedGameobjects.erase(db_guid);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

template<>
void ActivePoolData::RemoveObject<Pool>(uint32 sub_pool_id, uint32 pool_id)
{
    mSpawnedPools.erase(sub_pool_id);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

template<>
void ActivePoolData::RemoveObject<Quest>(uint32 quest_id, uint32 pool_id)
{
    mActiveQuests.erase(quest_id);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

////////////////////////////////////////////////////////////
// class NewActivePoolData

// Method that tell amount spawned objects/subpools
uint32 NewActivePoolData::GetActiveObjectCount(uint32 pool_id) const
{
    ActivePoolPools::const_iterator itr = mNewSpawnedPools.find(pool_id);
    return itr != mNewSpawnedPools.end() ? itr->second : 0;
}

// Method that tell if a creature is spawned currently
bool NewActivePoolData::IsActiveCreature(uint32 guid) const
{
    return mNewSpawnedCreatures.find(guid) != mNewSpawnedCreatures.end();
}

// Method that tell if a gameobject is spawned currently
bool NewActivePoolData::IsActiveGameObject(uint32 guid) const
{
    return mNewSpawnedGameobjects.find(guid) != mNewSpawnedGameobjects.end();
}

void NewActivePoolData::ActivateCreature(uint32 guid, uint32 pool_id)
{
    mNewSpawnedCreatures.insert(guid);
    ++mNewSpawnedPools[pool_id];
}

void NewActivePoolData::ActivateGameObject(uint32 guid, uint32 pool_id)
{
    mNewSpawnedGameobjects.insert(guid);
    ++mNewSpawnedPools[pool_id];
}

void NewActivePoolData::RemoveCreature(uint32 guid, uint32 pool_id)
{
    mNewSpawnedCreatures.erase(guid);
    uint32& val = mNewSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

void NewActivePoolData::RemoveGameObject(uint32 guid, uint32 pool_id)
{
    mNewSpawnedGameobjects.erase(guid);
    uint32& val = mNewSpawnedPools[pool_id];
    if (val > 0)
        --val;
}


////////////////////////////////////////////////////////////
// Methods of template class PoolGroup

// Method to add a gameobject/creature guid to the proper list depending on pool type and chance value
template <class T>
void PoolGroup<T>::AddEntry(PoolObject& poolitem, uint32 minentries, uint32 maxentries)
{
    if (poolitem.chance != 0 && maxentries == 1)
        ExplicitlyChanced.push_back(poolitem);
    else
        EqualChanced.push_back(poolitem);
}

// Method to check the chances are proper in this object pool
template <class T>
bool PoolGroup<T>::CheckPool() const
{
    if (EqualChanced.empty())
    {
        float chance = 0;
        for (uint32 i = 0; i < ExplicitlyChanced.size(); ++i)
            chance += ExplicitlyChanced[i].chance;
        if (chance != 100 && chance != 0)
            return false;
    }
    return true;
}

template <class T>
PoolObject* PoolGroup<T>::RollOne(ActivePoolData& spawns, uint32 triggerFrom)
{
    if (!ExplicitlyChanced.empty())
    {
        float roll = (float)rand_chance();

        for (uint32 i = 0; i < ExplicitlyChanced.size(); ++i)
        {
            roll -= ExplicitlyChanced[i].chance;
            // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
            // so this need explicit check for this case
            if (roll < 0 && (ExplicitlyChanced[i].guid == triggerFrom || !spawns.IsActiveObject<T>(ExplicitlyChanced[i].guid)))
               return &ExplicitlyChanced[i];
        }
    }
    if (!EqualChanced.empty())
    {
        uint32 index = urand(0, EqualChanced.size()-1);
        // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
        // so this need explicit check for this case
        if (EqualChanced[index].guid == triggerFrom || !spawns.IsActiveObject<T>(EqualChanced[index].guid))
           return &EqualChanced[index];
    }

    return NULL;
}

// Main method to despawn a creature or gameobject in a pool
// If no guid is passed, the pool is just removed (event end case)
// If guid is filled, cache will be used and no removal will occur, it just fill the cache
template<class T>
void PoolGroup<T>::DespawnObject(ActivePoolData& spawns, uint32 guid)
{
    for (size_t i=0; i < EqualChanced.size(); ++i)
    {
        // if spawned
        if (spawns.IsActiveObject<T>(EqualChanced[i].guid))
        {
            if (!guid || EqualChanced[i].guid == guid)
            {
                Despawn1Object(EqualChanced[i].guid);
                spawns.RemoveObject<T>(EqualChanced[i].guid, poolId);
            }
        }
    }

    for (size_t i = 0; i < ExplicitlyChanced.size(); ++i)
    {
        // spawned
        if (spawns.IsActiveObject<T>(ExplicitlyChanced[i].guid))
        {
            if (!guid || ExplicitlyChanced[i].guid == guid)
            {
                Despawn1Object(ExplicitlyChanced[i].guid);
                spawns.RemoveObject<T>(ExplicitlyChanced[i].guid, poolId);
            }
        }
    }
}

// Method that is actualy doing the removal job on one creature
template<>
void PoolGroup<Creature>::Despawn1Object(uint32 guid)
{
    if (CreatureData const* data = sObjectMgr->GetCreatureData(guid))
    {
        sObjectMgr->RemoveCreatureFromGrid(guid, data);

        if (Creature* creature = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_UNIT, data->id, guid), (Creature*)NULL))
            creature->AddObjectToRemoveList();
    }
}

// Same on one gameobject
template<>
void PoolGroup<GameObject>::Despawn1Object(uint32 guid)
{
    if (GameObjectData const* data = sObjectMgr->GetGOData(guid))
    {
        sObjectMgr->RemoveGameobjectFromGrid(guid, data);

        if (GameObject* pGameobject = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_GAMEOBJECT, data->id, guid), (GameObject*)NULL))
            pGameobject->AddObjectToRemoveList();
    }
}

// Same on one pool
template<>
void PoolGroup<Pool>::Despawn1Object(uint32 child_pool_id)
{
    sPoolMgr->DespawnPool(child_pool_id);
}

// Same on one quest
template<>
void PoolGroup<Quest>::Despawn1Object(uint32 quest_id)
{
    // Creatures
    QuestRelations* questMap = sObjectMgr->GetCreatureQuestRelationMap();
    PooledQuestRelationBoundsNC qr = sPoolMgr->mQuestCreatureRelation.equal_range(quest_id);
    for (PooledQuestRelation::iterator itr = qr.first; itr != qr.second; ++itr)
    {
        QuestRelations::iterator qitr = questMap->find(itr->second);
        if (qitr == questMap->end())
            continue;
        QuestRelations::iterator lastElement = questMap->upper_bound(itr->second);
        for (; qitr != lastElement; ++qitr)
        {
            if (qitr->first == itr->second && qitr->second == itr->first)
            {
                questMap->erase(qitr);                  // iterator is now no more valid
                break;                                  // but we can exit loop since the element is found
            }
        }
    }

    // Gameobjects
    questMap = sObjectMgr->GetGOQuestRelationMap();
    qr = sPoolMgr->mQuestGORelation.equal_range(quest_id);
    for (PooledQuestRelation::iterator itr = qr.first; itr != qr.second; ++itr)
    {
        QuestRelations::iterator qitr = questMap->find(itr->second);
        if (qitr == questMap->end())
            continue;
        QuestRelations::iterator lastElement = questMap->upper_bound(itr->second);
        for (; qitr != lastElement; ++qitr)
        {
            if (qitr->first == itr->second && qitr->second == itr->first)
            {
                questMap->erase(qitr);                  // iterator is now no more valid
                break;                                  // but we can exit loop since the element is found
            }
        }
    }
}

// Method for a pool only to remove any found record causing a circular dependency loop
template<>
void PoolGroup<Pool>::RemoveOneRelation(uint32 child_pool_id)
{
    for (PoolObjectList::iterator itr = ExplicitlyChanced.begin(); itr != ExplicitlyChanced.end(); ++itr)
    {
        if (itr->guid == child_pool_id)
        {
            ExplicitlyChanced.erase(itr);
            break;
        }
    }
    for (PoolObjectList::iterator itr = EqualChanced.begin(); itr != EqualChanced.end(); ++itr)
    {
        if (itr->guid == child_pool_id)
        {
            EqualChanced.erase(itr);
            break;
        }
    }
}

template <class T>
void PoolGroup<T>::SpawnObject(ActivePoolData& spawns, uint32 minlimit, uint32 maxlimit, uint32 triggerFrom)
{
    uint32 lastDespawned = 0;
    int count = maxlimit - spawns.GetActiveObjectCount(poolId);
    TC_LOG_DEBUG("pool", "Spawning pool %u. Already active %u max: %u available %lu trying for %u", poolId, spawns.GetActiveObjectCount(poolId), maxlimit, EqualChanced.size() + ExplicitlyChanced.size(), count);

    // If triggered from some object respawn this object is still marked as spawned
    // and also counted into m_SpawnedPoolAmount so we need increase count to be
    // spawned by 1
    if (triggerFrom)
        ++count;

    // This will try to spawn the rest of pool, not guaranteed
    for (int i = 0; i < count; ++i)
    {
        PoolObject* obj = RollOne(spawns, triggerFrom);
        if (!obj)
            continue;
        if (obj->guid == lastDespawned)
            continue;

        if (obj->guid == triggerFrom)
        {
            ReSpawn1Object(obj);
            triggerFrom = 0;
            continue;
        }
        spawns.ActivateObject<T>(obj->guid, poolId);
        Spawn1Object(obj);

        if (triggerFrom)
        {
            // One spawn one despawn no count increase
            DespawnObject(spawns, triggerFrom);
            lastDespawned = triggerFrom;
            triggerFrom = 0;
        }
    }
}

// Method that is actualy doing the spawn job on 1 creature
template <>
void PoolGroup<Creature>::Spawn1Object(PoolObject* obj)
{
    if (CreatureData const* data = sObjectMgr->GetCreatureData(obj->guid))
    {
        sObjectMgr->AddCreatureToGrid(obj->guid, data);

        // Spawn if necessary (loaded grids only)
        Map* map = sMapMgr->CreateBaseMap(data->mapid);
        // We use spawn coords to spawn
        if (!map->Instanceable() && map->IsGridLoaded(data->posX, data->posY))
        {
            Creature* creature = new Creature();
            TC_LOG_DEBUG("pool", "Spawning creature %u", obj->guid);
            if (!creature->LoadCreatureFromDB(obj->guid, map))
            {
                delete creature;
                return;
            }
        }
    }
}

// Same for 1 gameobject
template <>
void PoolGroup<GameObject>::Spawn1Object(PoolObject* obj)
{
    if (GameObjectData const* data = sObjectMgr->GetGOData(obj->guid))
    {
        sObjectMgr->AddGameobjectToGrid(obj->guid, data);
        // Spawn if necessary (loaded grids only)
        // this base map checked as non-instanced and then only existed
        Map* map = sMapMgr->CreateBaseMap(data->mapid);
        // We use current coords to unspawn, not spawn coords since creature can have changed grid
        if (!map->Instanceable() && map->IsGridLoaded(data->posX, data->posY))
        {
            GameObject* pGameobject = new GameObject;
            //TC_LOG_DEBUG("pool", "Spawning gameobject %u", guid);
            if (!pGameobject->LoadGameObjectFromDB(obj->guid, map, false))
            {
                delete pGameobject;
                return;
            }
            else
            {
                if (pGameobject->isSpawnedByDefault())
                    map->AddToMap(pGameobject);
            }
        }
    }
}

// Same for 1 pool
template <>
void PoolGroup<Pool>::Spawn1Object(PoolObject* obj)
{
    sPoolMgr->SpawnPool(obj->guid);
}

// Same for 1 quest
template<>
void PoolGroup<Quest>::Spawn1Object(PoolObject* obj)
{
    // Creatures
    QuestRelations* questMap = sObjectMgr->GetCreatureQuestRelationMap();
    PooledQuestRelationBoundsNC qr = sPoolMgr->mQuestCreatureRelation.equal_range(obj->guid);
    for (PooledQuestRelation::iterator itr = qr.first; itr != qr.second; ++itr)
    {
        TC_LOG_DEBUG("pool", "PoolGroup<Quest>: Adding quest %u to creature %u", itr->first, itr->second);
        questMap->insert(QuestRelations::value_type(itr->second, itr->first));
    }

    // Gameobjects
    questMap = sObjectMgr->GetGOQuestRelationMap();
    qr = sPoolMgr->mQuestGORelation.equal_range(obj->guid);
    for (PooledQuestRelation::iterator itr = qr.first; itr != qr.second; ++itr)
    {
        TC_LOG_DEBUG("pool", "PoolGroup<Quest>: Adding quest %u to GO %u", itr->first, itr->second);
        questMap->insert(QuestRelations::value_type(itr->second, itr->first));
    }
}

template <>
void PoolGroup<Quest>::SpawnObject(ActivePoolData& spawns, uint32 minlimit, uint32 maxlimit, uint32 triggerFrom)
{
    TC_LOG_DEBUG("pool", "PoolGroup<Quest>: Spawning pool %u", poolId);
    // load state from db
    if (!triggerFrom)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_POOL_QUEST_SAVE);

        stmt->setUInt32(0, poolId);

        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
        {
            do
            {
                uint32 questId = result->Fetch()[0].GetUInt32();
                spawns.ActivateObject<Quest>(questId, poolId);
                PoolObject tempObj(questId, 0.0f);
                Spawn1Object(&tempObj);
                --maxlimit;
            } while (result->NextRow() && maxlimit);
            return;
        }
    }

    ActivePoolObjects currentQuests = spawns.GetActiveQuests();
    ActivePoolObjects newQuests;

    // always try to select different quests
    for (PoolObjectList::iterator itr = EqualChanced.begin(); itr != EqualChanced.end(); ++itr)
    {
        if (spawns.IsActiveObject<Quest>(itr->guid))
            continue;
        newQuests.insert(itr->guid);
    }

    // clear the pool
    DespawnObject(spawns);

    // recycle minimal amount of quests if possible count is lower than limit
    if (maxlimit > newQuests.size() && !currentQuests.empty())
    {
        do
        {
            uint32 questId = Trinity::Containers::SelectRandomContainerElement(currentQuests);
            newQuests.insert(questId);
            currentQuests.erase(questId);
        } while (newQuests.size() < maxlimit && !currentQuests.empty()); // failsafe
    }

    if (newQuests.empty())
        return;

    // activate <limit> random quests
    do
    {
        uint32 questId = Trinity::Containers::SelectRandomContainerElement(newQuests);
        spawns.ActivateObject<Quest>(questId, poolId);
        PoolObject tempObj(questId, 0.0f);
        Spawn1Object(&tempObj);
        newQuests.erase(questId);
        --maxlimit;
    } while (maxlimit && !newQuests.empty());

    // if we are here it means the pool is initialized at startup and did not have previous saved state
    if (!triggerFrom)
        sPoolMgr->SaveQuestsToDB();
}

// Method that does the respawn job on the specified creature
template <>
void PoolGroup<Creature>::ReSpawn1Object(PoolObject* obj)
{
    if (CreatureData const* data = sObjectMgr->GetCreatureData(obj->guid))
        if (Creature* creature = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_UNIT, data->id, obj->guid), (Creature*)NULL))
        {
            creature->GetMap()->AddToMap(creature);
            TC_LOG_DEBUG("pool", "Respawning creature %u", obj->guid);
        }
}

// Method that does the respawn job on the specified gameobject
template <>
void PoolGroup<GameObject>::ReSpawn1Object(PoolObject* obj)
{
    if (GameObjectData const* data = sObjectMgr->GetGOData(obj->guid))
        if (GameObject* pGameobject = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_GAMEOBJECT, data->id, obj->guid), (GameObject*)NULL))
            pGameobject->GetMap()->AddToMap(pGameobject);
}

// Nothing to do for a child Pool
template <>
void PoolGroup<Pool>::ReSpawn1Object(PoolObject* /*obj*/) { }

// Nothing to do for a quest
template <>
void PoolGroup<Quest>::ReSpawn1Object(PoolObject* /*obj*/) { }

////////////////////////////////////////////////////////////
// Methods of class NewPoolGroup

void NewPoolGroup::AddCreatureEntry(PoolCreatureInfo& poolitem)
{
    PoolCreatures.push_back(poolitem);
}

void NewPoolGroup::AddSpawnEntry(PoolSpawnPoints& poolitem)
{
    PoolSpawns.push_back(poolitem);
}

// For this, we check that if one entry is 0, all are 0. If all don't total 100, all become 0.
bool NewPoolGroup::CheckPool()
{
    if (!PoolCreatures.empty())
    {
        bool bZerofound = false;
        float chance = 0;

        // Create total chance for pool, and also check for zero chance values
        for (uint32 i = 0; i < PoolCreatures.size(); i++)
        {
            if (PoolCreatures[i].chance == 0)
                bZerofound = true;

            chance += PoolCreatures[i].chance;
        }

        // If there were no zeroes, but the chance is not 100% exactly, report warning/fail
        if (!bZerofound && chance != 100)
        {
            if (sWorld->getBoolConfig(CONFIG_POOL_STOP_ON_INVALID_CONFIG))
                return false;

            TC_LOG_WARN("pool", "NEW Pool %u, found total chance %f, must be 0 or 100. Setting all to 0 (equal chance) for this pool", poolId, chance);
            for (uint32 i = 0; i < PoolCreatures.size(); i++)
                PoolCreatures[i].chance = 0;
        }
        // If there were zeroes found, but also other chance values, report warning/fail
        else if (bZerofound && chance != 0)
        {
            if (sWorld->getBoolConfig(CONFIG_POOL_STOP_ON_INVALID_CONFIG))
                return false;

            TC_LOG_WARN("pool", "NEW Pool %u, found a zero chance entry with total chance %f, All entries must be 0, or explicit values. Setting all to 0 (equal chance) for this pool", poolId, chance);
            for (uint32 i = 0; i < PoolCreatures.size(); i++)
                PoolCreatures[i].chance = 0;
        }
    }

    // Populate search maps for spawns
    if (!PoolSpawns.empty())
    {
        PoolFreeSpawns.clear();
        PoolActiveSpawns.clear();

        for (uint i = 0; i < PoolSpawns.size(); i++)
        {
            uint32 guid = PoolSpawns[i].guid;
            SearchPair p(guid, i);
            PoolFreeSpawns.insert(p);
        }
    }

    // Clear respawn timers
    Respawns.clear();
    return true;
}

PoolCreatureInfo* NewPoolGroup::RollCreature()
{
    if (!PoolCreatures.empty())
    {
        // Choose a creature entirely at random if first chance we find is 0
        if (PoolCreatures[0].chance == 0)
        {
            int32 index = irand(0, PoolCreatures.size() -1);
            return &PoolCreatures[index];
        }
        // Choose based on chance rating
        else
        {
            int32 index = irand(1, 100);
            float chance = 0;
            for (uint i = 0; i < PoolCreatures.size(); i++)
            {
                chance += PoolCreatures[i].chance;
                if ((uint32)chance >= (uint32)index)
                    return &PoolCreatures[i];
            }
        }
    }
    return NULL;
}

PoolSpawnPoints* NewPoolGroup::RollSpawnPoint()
{
    if (!PoolSpawns.empty() && !PoolFreeSpawns.empty())
    {
        // If there's only one entry left, just return that
        if (PoolFreeSpawns.size() == 1)
        {
            SearchMap::iterator itr = PoolFreeSpawns.begin();
            return &PoolSpawns[itr->second];
        }

        // Random element remaining in free spawns
        int32 index = irand(0, PoolFreeSpawns.size() -1);

        // Iterate to this element
        SearchMap::iterator itr = PoolFreeSpawns.begin();
        for (uint i = 0; i < index; i++)
            ++itr;

        // Return pointer to the spawn structure
        return &PoolSpawns[itr->second];
    }
    return NULL;
}

void NewPoolGroup::DespawnCreature(NewActivePoolData& spawns, SearchMap& CreatureMap, RespawnPool& RespawnMap, uint32 guid)
{
    // Find the index of the creature info for this guid. Exit if not found
    SearchMap::iterator itrci = CreatureInfoMap.find(guid);
    if (itrci == CreatureInfoMap.end())
    {
        TC_LOG_WARN("pool", "Creature %u not found in Info Map when trying to despawn", guid);
        return;
    }

    uint32 creatureidx = itrci->second;

    // Find the guid of the spawn point for this guid. Exit if not found
    SearchMap::iterator itrsp = CreatureSpawnPoints.find(guid);
    if (itrsp == CreatureSpawnPoints.end())
    {
        TC_LOG_WARN("pool", "Creature %u not found in Spawn Map when trying to despawn", guid);
        return;
    }

    uint32 spawnguid = itrsp->second;

    // If we made it here, it's definately in our pool. So, despawn it
    Despawn1Creature(guid);

    // Delete from creature lookup maps
    CreatureInfoMap.erase(itrci);
    CreatureSpawnPoints.erase(itrsp);

    // Find in Creature map, and delete if found
    SearchMap::iterator itr = CreatureMap.find(guid);
    if (itr != CreatureMap.end())
        CreatureMap.erase(itr);
    else
        TC_LOG_WARN("pool", "Creature %u, in pool %u expected in creature map, but not found!", guid, poolId);

    TC_LOG_DEBUG("pool", "Despawned %u", guid);
}

void NewPoolGroup::ClearSpawn(uint32 guid, uint32 minspawns)
{
    // Find the guid of the spawn point for this guid. Exit if not found
    SearchMap::iterator itrsp = CreatureSpawnPoints.find(guid);
    if (itrsp == CreatureSpawnPoints.end())
        return;

    uint32 spawnguid = itrsp->second;
    // Find spawn point in active points
    SearchMap::iterator itr = PoolActiveSpawns.find(spawnguid);
    if (itr != PoolActiveSpawns.end())
    {
        uint32 spawnidx = itr->second;

        // Delete from active
        PoolActiveSpawns.erase(itr);

        // Add to free spawns
        itr = PoolFreeSpawns.find(spawnguid);
        if (itr == PoolFreeSpawns.end())
        {
            SearchPair p(spawnguid, spawnidx);
            PoolFreeSpawns.insert(p);

            // Add to respawn time
            SearchMap::iterator itrci = CreatureInfoMap.find(guid);
            if (itrci != CreatureInfoMap.end())
            {
                PoolCreatureInfo* cinfo = &PoolCreatures[itrci->second];
                time_t respawntime = time(NULL) + cinfo->spawntimesecs;
                TC_LOG_DEBUG("pool", "Scheduling respawn for %li", respawntime);
                TimePair tp(respawntime, spawnguid);
                Respawns.insert(tp);

                // Expedite oldest (after expedite time) entry if less than minimum spawns
                uint32 currentspawns = PoolSpawnCount();
                time_t now = time(NULL);

                // Find imminent spawns (between now and the fast spawn time)
                SpawnTimeMap::iterator nearitr = Respawns.begin();
                do
                {
                    // If we find one coming soon, consider it a current spawn
                    if (nearitr != Respawns.end() && nearitr->first <= (now + sWorld->getIntConfig(CONFIG_POOL_FAST_RESPAWN_WAIT) + 1))
                        currentspawns++;
                    ++nearitr;
                }
                while (nearitr != Respawns.end() && nearitr->first <= (now + sWorld->getIntConfig(CONFIG_POOL_FAST_RESPAWN_WAIT) + 1));

                // The difference will ALMOST always be 1. But if can be more, and we should always speed up spawns to match minimum count
                if (currentspawns < minspawns && !Respawns.empty())
                {
                    for (uint i = 0; i < (minspawns - currentspawns); i++)
                    {
                        SpawnTimeMap::iterator sitr = Respawns.begin();
                        do
                        {
                            ++sitr;
                        }
                        while (sitr != Respawns.end() && sitr->first < (now + sWorld->getIntConfig(CONFIG_POOL_FAST_RESPAWN_WAIT) + 1));
                        if (sitr != Respawns.end())
                        {
                            respawntime = now + sWorld->getIntConfig(CONFIG_POOL_FAST_RESPAWN_WAIT);
                            SpawnTimeMap::const_iterator itrtmp;
                            do
                            {
                                TimePair tpa(respawntime, sitr->second);
                                itrtmp = Respawns.find(tpa);
                                // On the unlikely chance this spawn point already exists at this time, increase spawn time by 1 second and try again.
                                if (itrtmp != Respawns.end())
                                    respawntime++;
                                TC_LOG_DEBUG("pool", "Expediting oldest spawn at point %u, from %li to %li", sitr->second, sitr->first, respawntime);
                            }
                            while (itrtmp != Respawns.end());
                            TimePair tpa(respawntime, sitr->second);
                            Respawns.insert(tpa);
                            Respawns.erase(sitr);
                        }
                    }
                }
            }
        }
        else
            TC_LOG_WARN("pool", "Active spawn guid %u, also in free spawns!", spawnguid);
    }
    else
        TC_LOG_WARN("pool", "Used spawn %u not found in actives!", spawnguid);
}

void NewPoolGroup::Despawn1Creature(uint32 guid)
{
    if (CreatureData const* data = sObjectMgr->GetCreatureData(guid))
    {
        sObjectMgr->RemoveCreatureFromGrid(guid, data);
        TC_LOG_DEBUG("pool", "Despawning creature %u", guid);

        if (Creature* creature = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_UNIT, data->id, guid), (Creature*)NULL))
            creature->AddObjectToRemoveList();
    }
}

void NewPoolGroup::Despawn1GameObject(uint32 guid)
{
    if (GameObjectData const* data = sObjectMgr->GetGOData(guid))
    {
        sObjectMgr->RemoveGameobjectFromGrid(guid, data);

        if (GameObject* pGameobject = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_GAMEOBJECT, data->id, guid), (GameObject*)NULL))
            pGameobject->AddObjectToRemoveList();
    }
}

void NewPoolGroup::SpawnCreature(NewActivePoolData& spawns, SearchMap& CreatureMap, uint32 minlimit, uint32 maxlimit, FreeGuid& FreeGuids)
{
    int count = maxlimit - spawns.GetActiveObjectCount(poolId);
    uint32 guid;
    TC_LOG_DEBUG("pool", "Spawning new pool %u. Already active %u max: %u available %lu trying for %u", poolId, spawns.GetActiveObjectCount(poolId), maxlimit, PoolSpawns.size(), count);

    for (int i = 0; i < count; ++i)
    {

        PoolCreatureInfo* objcrea = RollCreature();
        PoolSpawnPoints* objspawn = RollSpawnPoint();
        if (!objcrea || !objspawn)
        {
            TC_LOG_WARN("pool", "Failed to create either creature or spawn point during pool %u spawn", poolId);
            return;
        }
        guid = Spawn1Creature(objcrea, objspawn, CreatureMap, FreeGuids);
        if (guid != 0)
        {
            spawns.ActivateCreature(guid, poolId);

        }
    }
}

void NewPoolGroup::Respawn1Creature(NewActivePoolData& spawns, SearchMap& CreatureMap, FreeGuid& FreeGuids)
{
    uint32 guid;
    PoolCreatureInfo* objcrea = RollCreature();
    PoolSpawnPoints* objspawn = RollSpawnPoint();
    if (!objcrea || !objspawn)
    {
        TC_LOG_WARN("pool", "Failed to create either creature or spawn point during pool %u spawn", poolId);
        return;
    }
    guid = Spawn1Creature(objcrea, objspawn, CreatureMap, FreeGuids);
    if (guid != 0)
    {
        spawns.ActivateCreature(guid, poolId);
    }
}

uint32 NewPoolGroup::Spawn1Creature(PoolCreatureInfo* creatureinfo, PoolSpawnPoints* spawnpoint, SearchMap& CreatureMap, FreeGuid& FreeGuids)
{
    CreatureData data;
    uint32 guid = 0;
    if (FreeGuids.empty() || !sWorld->getBoolConfig(CONFIG_POOL_REUSE_GUIDS))
        guid = sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT);
    else
    {
        // There's guids in the Free GUID store, first we must validate them
        FreeGuid::reverse_iterator itr = FreeGuids.rbegin();
        do
        {
            if (itr == FreeGuids.rend())
                break;
            uint32 tguid = itr->first;

            // If this creature isn't already in the world, we can use the guid
            Creature* pCreature = ObjectAccessor::GetObjectInWorld(ObjectGuid(HIGHGUID_UNIT, itr->second, tguid), (Creature*)NULL);
            if (!pCreature && creatureinfo->creature_id != itr->second)
                guid=tguid;

            // Either way, remove the ID from the list
            FreeGuids.erase(FreeGuids.find(tguid));
            ++itr;
        }
        while (itr != FreeGuids.rend() && guid == 0);

        // If there were no free guids in the list, take a new one
        if (guid == 0)
            guid = sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT);
        else
            TC_LOG_DEBUG("pool", "Re-using old guid %u for entry %u", guid, creatureinfo->creature_id);
    }

    // Copy data from structures into Creature data
    data.id = creatureinfo->creature_id;
    data.mapid = spawnpoint->mapid;
    data.phaseMask = creatureinfo->phaseMask;
    data.displayid = creatureinfo->displayid;
    data.equipmentId = creatureinfo->equipmentId;
    data.posX = spawnpoint->posX;
    data.posY = spawnpoint->posY;
    data.posZ = spawnpoint->posZ;
    data.orientation = spawnpoint->orientation;
    data.spawntimesecs = creatureinfo->spawntimesecs;
    data.spawndist = creatureinfo->spawndist;
    data.currentwaypoint = creatureinfo->currentwaypoint;
    data.curhealth = creatureinfo->curhealth;
    data.curmana = creatureinfo->curmana;
    data.movementType = creatureinfo->movementType;
    data.spawnMask = creatureinfo->spawnMask;
    data.npcflag = creatureinfo->npcflag;
    data.unit_flags = creatureinfo->unit_flags;
    data.dynamicflags = creatureinfo->dynamicflags;
    data.dbData = false;

    // Creature and spawn data MUST be added to lookup before LoadCreatureFromDB, since this will call back here!
    // Add guid / Creature ID/Qualifier pair to Search Map, only if not already present
    uint32 index = FindCreatureIndex(creatureinfo->creature_id, creatureinfo->creature_qual);
    if (index != 0xFFFFFFFF)
    {
        SearchPair p(guid, index);
        SearchMap::const_iterator itr = CreatureInfoMap.find(guid);
        if (itr == CreatureInfoMap.end())
        {
            CreatureInfoMap.insert(p);
        }
        else
            TC_LOG_WARN("pool", "Creature Info already present for guid %u!", guid);
    }
    else
        TC_LOG_WARN("pool", "Creature Info index not found for guid %u, Creature %u, qualifier %u", guid, creatureinfo->creature_id, creatureinfo->creature_qual);

    // Add Creature/Spawn pair to Search Map, only if not already present
    SearchPair p(guid, spawnpoint->guid);
    SearchMap::const_iterator itr = CreatureSpawnPoints.find(guid);
    if (itr == CreatureSpawnPoints.end())
        CreatureSpawnPoints.insert(p);

    // Add lookup for this guid and pool
    SearchPair pc(guid, poolId);
    CreatureMap.insert(pc);

    sObjectMgr->AddCreatureToGrid(guid, &data);

    // Spawn if necessary (loaded grids only)
    Map* map = sMapMgr->CreateBaseMap(data.mapid);
    // We use spawn coords to spawn
    if (!map->Instanceable() && map->IsGridLoaded(data.posX, data.posY))
    {
        Creature* creature = new Creature();
        TC_LOG_DEBUG("pool", "Spawning creature %u from pool %u, entry %u with spawnpoint %u at %f, %f, %f", guid, poolId, creatureinfo->creature_id, spawnpoint->guid, spawnpoint->posX, spawnpoint->posY, spawnpoint->posZ);
        if (!creature->LoadCreatureFromDB(guid, map))
        {
            TC_LOG_WARN("pool", "Failed to load creature %u", creatureinfo->creature_id);
            delete creature;
            return 0;
        }
    }

    // Remove spawn point from Free spawns
    itr = PoolFreeSpawns.find(spawnpoint->guid);
    if (itr != PoolFreeSpawns.end())
        PoolFreeSpawns.erase(itr);

    // Add spawn point to Active Spawns
    itr = PoolActiveSpawns.find(spawnpoint->guid);
    if (itr == PoolActiveSpawns.end())
    {
        uint32 index = FindSpawnIndex(spawnpoint->guid);
        if (index != 0xFFFFFFFF)
        {
            SearchPair p(spawnpoint->guid, index);
            PoolActiveSpawns.insert(p);
            TC_LOG_DEBUG("pool", "Spawn point %u, Added to active, removed from free", spawnpoint->guid);
        }
        else
        {
            TC_LOG_WARN("pool", "Spawn point %u, index was not found!", spawnpoint->guid);
        }
    }
    else
    {
        TC_LOG_WARN("pool", "Spawn point %u, in both active and free spawn list!", spawnpoint->guid);
    }

    return guid;
}

// Recover spawn index from guid
uint32 NewPoolGroup::FindSpawnIndex(uint32 guid)
{
    for (uint32 i = 0; i < PoolSpawns.size(); i++)
    {
        if (PoolSpawns[i].guid == guid)
            return i;
    }
    return 0xFFFFFFFF;
}

// Recover creature index from creature/qualifier
uint32 NewPoolGroup::FindCreatureIndex(uint32 creature_id, uint32 creature_qual)
{
    for (uint32 i = 0; i < PoolCreatures.size(); i++)
    {
        if (PoolCreatures[i].creature_id == creature_id && PoolCreatures[i].creature_qual == creature_qual)
            return i;
    }
    return 0xFFFFFFFF;
}

PoolCreatureInfo* NewPoolGroup::GetCreatureInfo(uint32 guid)
{
    SearchMap::const_iterator itr = CreatureInfoMap.find(guid);
    if (itr != CreatureInfoMap.end())
        return &PoolCreatures[itr->second];
}

PoolSpawnPoints* NewPoolGroup::GetCreatureSpawn(uint32 guid)
{
    SearchMap::const_iterator itr = CreatureSpawnPoints.find(guid);
    if (itr != CreatureSpawnPoints.end())
    {
        uint32 index = FindSpawnIndex(itr->second);
        if (index != 0xFFFFFFFF)
            return &PoolSpawns[index];
    }
}

bool NewPoolGroup::UpdateNewPool(NewActivePoolData& spawns, SearchMap& CreatureMap, FreeGuid& FreeGuids)
{
    // Return false if no respawns waiting (we shouldn't get here, but never mind)
    if (Respawns.empty())
    {
        TC_LOG_WARN("pool", "Pool Update for %u reached, but no respawns waiting. What is this, I don't even?", poolId);
        return false;
    }

    SpawnTimeMap::const_iterator itr = Respawns.begin();
    time_t now = time(NULL);

    // If first item is not ready, none are ready
    time_t spawntime = itr->first;
    if (itr->first > now)
        return true;

    // Loop until we find an entry for a later time
    do
    {
        Respawn1Creature(spawns, CreatureMap, FreeGuids);
        Respawns.erase(itr);
        ++itr;
    }
    while (itr != Respawns.end() && itr->first <= now);

    // If no respawns remain queued, return false, to remove the pool from consideration
    if (Respawns.empty())
        return false;

    // More respawns remain
    return true;
}

////////////////////////////////////////////////////////////
// Methods of class PoolMgr

PoolMgr::PoolMgr() : max_pool_id(0) { }

void PoolMgr::Initialize()
{
    QueryResult result = WorldDatabase.Query("SELECT MAX(entry) FROM pool_template");
    if (result)
    {
        Field* fields = result->Fetch();
        max_pool_id = fields[0].GetUInt32();
    }

    mPoolTemplate.resize(max_pool_id + 1);
    mPoolCreatureGroups.resize(max_pool_id + 1);
    mPoolGameobjectGroups.resize(max_pool_id + 1);
    mPoolPoolGroups.resize(max_pool_id + 1);
    mPoolQuestGroups.resize(max_pool_id + 1);
    mNewPoolCreatureInfo.resize(max_pool_id + 1);

    mQuestSearchMap.clear();
    mGameobjectSearchMap.clear();
    mCreatureSearchMap.clear();
}

void PoolMgr::LoadFromDB()
{
    // Pool templates
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.Query("SELECT entry, min_limit, max_limit FROM pool_template");
        if (!result)
        {
            mPoolTemplate.clear();
            TC_LOG_INFO("server.loading", ">> Loaded 0 object pools. DB table `pool_template` is empty.");
            return;
        }

        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint32 pool_id = fields[0].GetUInt32();

            PoolTemplateData& pPoolTemplate = mPoolTemplate[pool_id];
            pPoolTemplate.MinLimit  = fields[1].GetUInt32();
            pPoolTemplate.MaxLimit  = fields[2].GetUInt32();

            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u objects pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }

    // Creatures

    TC_LOG_INFO("server.loading", "Loading Creatures Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 1       2         3
        QueryResult result = WorldDatabase.Query("SELECT guid, pool_entry, chance FROM pool_creature");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 creatures in  pools. DB table `pool_creature` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();

                uint32 guid    = fields[0].GetUInt32();
                uint32 pool_id = fields[1].GetUInt32();
                float chance   = fields[2].GetFloat();

                CreatureData const* data = sObjectMgr->GetCreatureData(guid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature` has a non existing creature spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id);
                    continue;
                }
                if (pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature` pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", pool_id);
                    continue;
                }
                if (chance < 0 || chance > 100)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature` has an invalid chance (%f) for creature guid (%u) in pool id (%u), skipped.", chance, guid, pool_id);
                    continue;
                }
                PoolTemplateData* pPoolTemplate = &mPoolTemplate[pool_id];
                PoolObject plObject = PoolObject(guid, chance);
                PoolGroup<Creature>& cregroup = mPoolCreatureGroups[pool_id];
                cregroup.SetPoolId(pool_id);
                cregroup.AddEntry(plObject, pPoolTemplate->MinLimit, pPoolTemplate->MaxLimit);
                SearchPair p(guid, pool_id);
                mCreatureSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u creatures in pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // New Creatures
    TC_LOG_INFO("server.loading", "Loading NEW Creatures Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                               0        1            2                   3       4          5          6        7             8
        QueryResult result = WorldDatabase.Query("SELECT pool_id, creature_id, creature_qualifier, chance, spawnMask, phaseMask, modelId, equipment_id, spawntimesecs, "
        //                                        9                   10                    11         12               13         14       15
                                                 "corpsetimesecsloot, corpsetimesecsnoloot, spawndist, currentwaypoint, curhealth, curmana, MovementType, "
        //                                        16       17          18
                                                 "npcflag, unit_flags, dynamicflags FROM pool_creature_info");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 NEW creatures in  pools. DB table `pool_creature_info` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                PoolCreatureInfo creatureinfo;

                uint32 pool_id                = fields[0].GetUInt32();
                creatureinfo.creature_id      = fields[1].GetUInt32();
                creatureinfo.creature_qual    = fields[2].GetUInt32();
                creatureinfo.chance           = fields[3].GetFloat();
                creatureinfo.spawnMask        = fields[4].GetUInt8();
                creatureinfo.phaseMask        = fields[5].GetUInt32();
                creatureinfo.displayid        = fields[6].GetUInt32();
                creatureinfo.equipmentId      = fields[7].GetInt8();
                creatureinfo.spawntimesecs    = fields[8].GetUInt32() > 0 ? fields[8].GetUInt32() : sWorld->getIntConfig(CONFIG_POOL_DEFAULT_CREATURE_RESPAWN);
                creatureinfo.corpsetimeloot   = fields[9].GetUInt32() > 0 ? fields[9].GetUInt32() : sWorld->getIntConfig(CONFIG_POOL_DEFAULT_CORPSE_DECAY_LOOT);
                creatureinfo.corpsetimenoloot = fields[10].GetUInt32() > 0 ? fields[10].GetUInt32() : sWorld->getIntConfig(CONFIG_POOL_DEFAULT_CORPSE_DECAY_NOLOOT);
                creatureinfo.spawndist        = fields[11].GetFloat();
                creatureinfo.currentwaypoint  = fields[12].GetUInt32();
                creatureinfo.curhealth        = fields[13].GetUInt32();
                creatureinfo.curmana          = fields[14].GetUInt32();
                creatureinfo.movementType     = fields[15].GetUInt8();
                creatureinfo.npcflag          = fields[16].GetUInt32();
                creatureinfo.unit_flags       = fields[17].GetUInt32();
                creatureinfo.dynamicflags     = fields[18].GetUInt32();

                CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(creatureinfo.creature_id);
                if (!cInfo)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature_info` has a non existing creature template (Entry: %u) defined for pool id (%u), skipped.", creatureinfo.creature_id, pool_id);
                    continue;
                }
                if (pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature` pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", pool_id);
                    continue;
                }
                if (creatureinfo.chance < 0 || creatureinfo.chance > 100)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_creature` has an invalid chance (%f) for creature entry (%u) in pool id (%u), skipped.", creatureinfo.chance, creatureinfo.creature_id, pool_id);
                    continue;
                }
                PoolTemplateData* pPoolTemplate = &mPoolTemplate[pool_id];

                //PoolObject plObject = PoolObject(guid, chance);

                NewPoolGroup& cregroup = mNewPoolCreatureInfo[pool_id];
                cregroup.SetPoolId(pool_id);
                cregroup.AddCreatureEntry(creatureinfo);
                //SearchPair p(guid, pool_id);
                //mCreatureSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u creatures in new pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // New Game Objects will go here!

    // New Spawn Points
    TC_LOG_INFO("server.loading", "Loading NEW Spawn Point Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                               0        1     2    3       4       5           6           7           8
        QueryResult result = WorldDatabase.Query("SELECT pool_id, guid, map, zoneId, areaId, position_x, position_y, position_z, orientation "
                                                 "FROM pool_spawns");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 NEW spawns in  pools. DB table `pool_creature_info` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                PoolSpawnPoints poolspawns;

                uint32 pool_id         = fields[0].GetUInt32();
                poolspawns.guid        = fields[1].GetUInt32();
                poolspawns.mapid       = fields[2].GetUInt16();
                poolspawns.zoneid      = fields[3].GetUInt16();
                poolspawns.areaid      = fields[4].GetUInt16();
                poolspawns.posX        = fields[5].GetFloat();
                poolspawns.posY        = fields[6].GetFloat();
                poolspawns.posZ        = fields[7].GetFloat();
                poolspawns.orientation = fields[8].GetFloat();

                if (pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_spawns` pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", pool_id);
                    continue;
                }
                PoolTemplateData* pPoolTemplate = &mPoolTemplate[pool_id];

                //PoolObject plObject = PoolObject(guid, chance);

                NewPoolGroup& cregroup = mNewPoolCreatureInfo[pool_id];
                cregroup.SetPoolId(pool_id);
                cregroup.AddSpawnEntry(poolspawns);
                //SearchPair p(guid, pool_id);
                //mCreatureSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u spawns in new pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Gameobjects

    TC_LOG_INFO("server.loading", "Loading Gameobject Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 1        2         3
        QueryResult result = WorldDatabase.Query("SELECT guid, pool_entry, chance FROM pool_gameobject");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 gameobjects in  pools. DB table `pool_gameobject` is empty.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();

                uint32 guid    = fields[0].GetUInt32();
                uint32 pool_id = fields[1].GetUInt32();
                float chance   = fields[2].GetFloat();

                GameObjectData const* data = sObjectMgr->GetGOData(guid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_gameobject` has a non existing gameobject spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id);
                    continue;
                }

                GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(data->id);
                if (goinfo->type != GAMEOBJECT_TYPE_CHEST &&
                    goinfo->type != GAMEOBJECT_TYPE_GOOBER &&
                    goinfo->type != GAMEOBJECT_TYPE_FISHINGHOLE)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_gameobject` has a not lootable gameobject spawn (GUID: %u, type: %u) defined for pool id (%u), skipped.", guid, goinfo->type, pool_id);
                    continue;
                }

                if (pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_gameobject` pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", pool_id);
                    continue;
                }

                if (chance < 0 || chance > 100)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_gameobject` has an invalid chance (%f) for gameobject guid (%u) in pool id (%u), skipped.", chance, guid, pool_id);
                    continue;
                }

                PoolTemplateData* pPoolTemplate = &mPoolTemplate[pool_id];
                PoolObject plObject = PoolObject(guid, chance);
                PoolGroup<GameObject>& gogroup = mPoolGameobjectGroups[pool_id];
                gogroup.SetPoolId(pool_id);
                gogroup.AddEntry(plObject, pPoolTemplate->MinLimit, pPoolTemplate->MaxLimit);
                SearchPair p(guid, pool_id);
                mGameobjectSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u gameobject in pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Pool of pools

    TC_LOG_INFO("server.loading", "Loading Mother Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                  1        2            3
        QueryResult result = WorldDatabase.Query("SELECT pool_id, mother_pool, chance FROM pool_pool");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 pools in pools");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();

                uint32 child_pool_id  = fields[0].GetUInt32();
                uint32 mother_pool_id = fields[1].GetUInt32();
                float chance          = fields[2].GetFloat();

                if (mother_pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_pool` mother_pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", mother_pool_id);
                    continue;
                }
                if (child_pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_pool` included pool_id (%u) is out of range compared to max pool id in `pool_template`, skipped.", child_pool_id);
                    continue;
                }
                if (mother_pool_id == child_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_pool` pool_id (%u) includes itself, dead-lock detected, skipped.", child_pool_id);
                    continue;
                }
                if (chance < 0 || chance > 100)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_pool` has an invalid chance (%f) for pool id (%u) in mother pool id (%u), skipped.", chance, child_pool_id, mother_pool_id);
                    continue;
                }
                PoolTemplateData* pPoolTemplateMother = &mPoolTemplate[mother_pool_id];
                PoolObject plObject = PoolObject(child_pool_id, chance);
                PoolGroup<Pool>& plgroup = mPoolPoolGroups[mother_pool_id];
                plgroup.SetPoolId(mother_pool_id);
                plgroup.AddEntry(plObject, pPoolTemplateMother->MinLimit, pPoolTemplateMother->MaxLimit);
                SearchPair p(child_pool_id, mother_pool_id);
                mPoolSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            // Now check for circular reference
            for (uint32 i=0; i < max_pool_id; ++i)
            {
                std::set<uint32> checkedPools;
                for (SearchMap::iterator poolItr = mPoolSearchMap.find(i); poolItr != mPoolSearchMap.end(); poolItr = mPoolSearchMap.find(poolItr->second))
                {
                    checkedPools.insert(poolItr->first);
                    if (checkedPools.find(poolItr->second) != checkedPools.end())
                    {
                        std::ostringstream ss;
                        ss<< "The pool(s) ";
                        for (std::set<uint32>::const_iterator itr=checkedPools.begin(); itr != checkedPools.end(); ++itr)
                            ss << *itr << ' ';
                        ss << "create(s) a circular reference, which can cause the server to freeze.\nRemoving the last link between mother pool "
                            << poolItr->first << " and child pool " << poolItr->second;
                        TC_LOG_ERROR("sql.sql", "%s", ss.str().c_str());
                        mPoolPoolGroups[poolItr->second].RemoveOneRelation(poolItr->first);
                        mPoolSearchMap.erase(poolItr);
                        --count;
                        break;
                    }
                }
            }

            TC_LOG_INFO("server.loading", ">> Loaded %u pools in mother pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    TC_LOG_INFO("server.loading", "Loading Quest Pooling Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_QUEST_POOLS);
        PreparedQueryResult result = WorldDatabase.Query(stmt);

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 quests in pools");
        }
        else
        {
            PooledQuestRelationBounds creBounds;
            PooledQuestRelationBounds goBounds;

            enum eQuestTypes
            {
                QUEST_NONE   = 0,
                QUEST_DAILY  = 1,
                QUEST_WEEKLY = 2
            };

            std::map<uint32, int32> poolTypeMap;
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();

                uint32 entry   = fields[0].GetUInt32();
                uint32 pool_id = fields[1].GetUInt32();

                Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
                if (!quest)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_quest` has a non existing quest template (Entry: %u) defined for pool id (%u), skipped.", entry, pool_id);
                    continue;
                }

                if (pool_id > max_pool_id)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_quest` pool id (%u) is out of range compared to max pool id in `pool_template`, skipped.", pool_id);
                    continue;
                }

                if (!quest->IsDailyOrWeekly())
                {
                    TC_LOG_ERROR("sql.sql", "`pool_quest` has an quest (%u) which is not daily or weekly in pool id (%u), use ExclusiveGroup instead, skipped.", entry, pool_id);
                    continue;
                }

                if (poolTypeMap[pool_id] == QUEST_NONE)
                    poolTypeMap[pool_id] = quest->IsDaily() ? QUEST_DAILY : QUEST_WEEKLY;

                int32 currType = quest->IsDaily() ? QUEST_DAILY : QUEST_WEEKLY;

                if (poolTypeMap[pool_id] != currType)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_quest` quest %u is %s but pool (%u) is specified for %s, mixing not allowed, skipped.",
                                     entry, currType == QUEST_DAILY ? "QUEST_DAILY" : "QUEST_WEEKLY", pool_id, poolTypeMap[pool_id] == QUEST_DAILY ? "QUEST_DAILY" : "QUEST_WEEKLY");
                    continue;
                }

                creBounds = mQuestCreatureRelation.equal_range(entry);
                goBounds = mQuestGORelation.equal_range(entry);

                if (creBounds.first == creBounds.second && goBounds.first == goBounds.second)
                {
                    TC_LOG_ERROR("sql.sql", "`pool_quest` lists entry (%u) as member of pool (%u) but is not started anywhere, skipped.", entry, pool_id);
                    continue;
                }

                PoolTemplateData* pPoolTemplate = &mPoolTemplate[pool_id];
                PoolObject plObject = PoolObject(entry, 0.0f);
                PoolGroup<Quest>& questgroup = mPoolQuestGroups[pool_id];
                questgroup.SetPoolId(pool_id);
                questgroup.AddEntry(plObject, pPoolTemplate->MinLimit, pPoolTemplate->MaxLimit);
                SearchPair p(entry, pool_id);
                mQuestSearchMap.insert(p);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u quests in pools in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // The initialize method will spawn all pools not in an event and not in another pool, this is why there is 2 left joins with 2 null checks
    TC_LOG_INFO("server.loading", "Starting objects pooling system...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.Query("SELECT DISTINCT pool_template.entry, pool_pool.pool_id, pool_pool.mother_pool FROM pool_template"
            " LEFT JOIN game_event_pool ON pool_template.entry=game_event_pool.pool_entry"
            " LEFT JOIN pool_pool ON pool_template.entry=pool_pool.pool_id WHERE game_event_pool.pool_entry IS NULL");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Pool handling system initialized, 0 pools spawned.");
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* fields = result->Fetch();
                uint32 pool_entry = fields[0].GetUInt32();
                uint32 pool_pool_id = fields[1].GetUInt32();

                if (!CheckPool(pool_entry))
                {
                    if (pool_pool_id)
                        // The pool is a child pool in pool_pool table. Ideally we should remove it from the pool handler to ensure it never gets spawned,
                        // however that could recursively invalidate entire chain of mother pools. It can be done in the future but for now we'll do nothing.
                        TC_LOG_ERROR("sql.sql", "Pool Id %u has no equal chance pooled entites defined and explicit chance sum is not 100. This broken pool is a child pool of Id %u and cannot be safely removed.", pool_entry, fields[2].GetUInt32());
                    else
                        TC_LOG_ERROR("sql.sql", "Pool Id %u has no equal chance pooled entites defined and explicit chance sum is not 100. The pool will not be spawned.", pool_entry);
                    continue;
                }

                // Don't spawn child pools, they are spawned recursively by their parent pools
                if (!pool_pool_id)
                {
                    SpawnPool(pool_entry);
                    SpawnNewPool(pool_entry);
                    count++;
                }
            }
            while (result->NextRow());

            TC_LOG_DEBUG("pool", "Pool handling system initialized, %u pools spawned in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

        }
    }
}

void PoolMgr::LoadQuestPools()
{

}

void PoolMgr::SaveQuestsToDB()
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (PoolGroupQuestMap::iterator itr = mPoolQuestGroups.begin(); itr != mPoolQuestGroups.end(); ++itr)
    {
        if (itr->isEmpty())
            continue;
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_QUEST_POOL_SAVE);
        stmt->setUInt32(0, itr->GetPoolId());
        trans->Append(stmt);
    }

    for (SearchMap::iterator itr = mQuestSearchMap.begin(); itr != mQuestSearchMap.end(); ++itr)
    {
        if (IsSpawnedObject<Quest>(itr->first))
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_QUEST_POOL_SAVE);
            stmt->setUInt32(0, itr->second);
            stmt->setUInt32(1, itr->first);
            trans->Append(stmt);
        }
    }

    CharacterDatabase.CommitTransaction(trans);
}

void PoolMgr::ChangeDailyQuests()
{
    for (PoolGroupQuestMap::iterator itr = mPoolQuestGroups.begin(); itr != mPoolQuestGroups.end(); ++itr)
    {
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(itr->GetFirstEqualChancedObjectId()))
        {
            if (quest->IsWeekly())
                continue;

            UpdatePool<Quest>(itr->GetPoolId(), 1);    // anything non-zero means don't load from db
        }
    }

    SaveQuestsToDB();
}

void PoolMgr::ChangeWeeklyQuests()
{
    for (PoolGroupQuestMap::iterator itr = mPoolQuestGroups.begin(); itr != mPoolQuestGroups.end(); ++itr)
    {
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(itr->GetFirstEqualChancedObjectId()))
        {
            if (quest->IsDaily())
                continue;

            UpdatePool<Quest>(itr->GetPoolId(), 1);
        }
    }

    SaveQuestsToDB();
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the creature is respawned only (added back to map)
template<>
void PoolMgr::SpawnPool<Creature>(uint32 pool_id, uint32 db_guid)
{
    if (!mPoolCreatureGroups[pool_id].isEmpty())
        mPoolCreatureGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MinLimit, mPoolTemplate[pool_id].MaxLimit, db_guid);

}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the gameobject is respawned only (added back to map)
template<>
void PoolMgr::SpawnPool<GameObject>(uint32 pool_id, uint32 db_guid)
{
    if (!mPoolGameobjectGroups[pool_id].isEmpty())
        mPoolGameobjectGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MinLimit, mPoolTemplate[pool_id].MaxLimit, db_guid);
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the pool is respawned only
template<>
void PoolMgr::SpawnPool<Pool>(uint32 pool_id, uint32 sub_pool_id)
{
    if (!mPoolPoolGroups[pool_id].isEmpty())
        mPoolPoolGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MinLimit, mPoolTemplate[pool_id].MaxLimit, sub_pool_id);
}

// Call to spawn a pool
template<>
void PoolMgr::SpawnPool<Quest>(uint32 pool_id, uint32 quest_id)
{
    if (!mPoolQuestGroups[pool_id].isEmpty())
        mPoolQuestGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MinLimit, mPoolTemplate[pool_id].MaxLimit, quest_id);
}

void PoolMgr::SpawnPool(uint32 pool_id)
{
    SpawnPool<Pool>(pool_id, 0);
    SpawnPool<GameObject>(pool_id, 0);
    SpawnPool<Creature>(pool_id, 0);
    SpawnPool<Quest>(pool_id, 0);
}

void PoolMgr::SpawnNewPool(uint32 pool_id)
{
    if (!mNewPoolCreatureInfo[pool_id].isEmpty())
        mNewPoolCreatureInfo[pool_id].SpawnCreature(mNewSpawnedData, mNewCreatureSearchMap, mPoolTemplate[pool_id].MinLimit, mPoolTemplate[pool_id].MaxLimit, mFreeGuids);
}

// Call to despawn a pool, all gameobjects/creatures in this pool are removed
void PoolMgr::DespawnPool(uint32 pool_id)
{
    if (!mPoolCreatureGroups[pool_id].isEmpty())
        mPoolCreatureGroups[pool_id].DespawnObject(mSpawnedData);

    if (!mPoolGameobjectGroups[pool_id].isEmpty())
        mPoolGameobjectGroups[pool_id].DespawnObject(mSpawnedData);

    if (!mPoolPoolGroups[pool_id].isEmpty())
        mPoolPoolGroups[pool_id].DespawnObject(mSpawnedData);

    if (!mPoolQuestGroups[pool_id].isEmpty())
        mPoolQuestGroups[pool_id].DespawnObject(mSpawnedData);
}

// Method that check chance integrity of the creatures and gameobjects in this pool
bool PoolMgr::CheckPool(uint32 pool_id)
{
    return pool_id <= max_pool_id &&
        mPoolGameobjectGroups[pool_id].CheckPool() &&
        mPoolCreatureGroups[pool_id].CheckPool() &&
        mPoolPoolGroups[pool_id].CheckPool() &&
        mPoolQuestGroups[pool_id].CheckPool() &&
        mNewPoolCreatureInfo[pool_id].CheckPool();
}

// Call to update the pool when a gameobject/creature part of pool [pool_id] is ready to respawn
// Here we cache only the creature/gameobject whose guid is passed as parameter
// Then the spawn pool call will use this cache to decide
template<typename T>
void PoolMgr::UpdatePool(uint32 pool_id, uint32 db_guid_or_pool_id)
{
    if (uint32 motherpoolid = IsPartOfAPool<Pool>(pool_id))
        SpawnPool<Pool>(motherpoolid, pool_id);
    else
        SpawnPool<T>(pool_id, db_guid_or_pool_id);
}

PoolCreatureInfo* PoolMgr::GetCreatureInfo(uint32 pool_id, uint32 guid)
{
    if (pool_id <= max_pool_id)
        return mNewPoolCreatureInfo[pool_id].GetCreatureInfo(guid);

}

PoolSpawnPoints* PoolMgr::GetCreatureSpawn(uint32 pool_id, uint32 guid)
{
    if (pool_id <= max_pool_id)
        return mNewPoolCreatureInfo[pool_id].GetCreatureSpawn(guid);

}

void PoolMgr::HandleCreatureDeath(uint32 guid)
{
    uint32 pool_id = IsPoolCreature(guid);

    // Nothing to do if this isn't a pool creature
    if (pool_id == 0)
        return;

    // Clear spawn, and internally add to respawn timer in pool context
    mNewPoolCreatureInfo[pool_id].ClearSpawn(guid, mPoolTemplate[pool_id].MinLimit);

    // If pool not already queued, add to pending respawn iterator
    if (mRespawnMap.find(pool_id) == mRespawnMap.end())
        mRespawnMap.insert(pool_id);
}

void PoolMgr::HandleDespawn(uint32 guid)
{
    uint32 pool_id = IsPoolCreature(guid);

    // Nothing to do if this isn't a pool creature
    if (pool_id == 0)
        return;

    TC_LOG_DEBUG("pool", "Trying despawn, %u from pool %u", guid, pool_id);
    PoolCreatureInfo* cinfo = mNewPoolCreatureInfo[pool_id].GetCreatureInfo(guid);
    mNewPoolCreatureInfo[pool_id].DespawnCreature(mNewSpawnedData, mNewCreatureSearchMap, mRespawnMap, guid);

    if (sWorld->getBoolConfig(CONFIG_POOL_REUSE_GUIDS))
    {
        GuidPair gp(guid, cinfo->creature_id);
        mFreeGuids.insert(gp);
    }
}

// This is called every 5 seconds. Be careful what you put here
void PoolMgr::UpdateNewPool(uint32 diff)
{
    if (mRespawnMap.empty())
        return;

    // Iterate the pools that have respawns, and run their local updater
    for (RespawnPool::iterator itr = mRespawnMap.begin(); itr != mRespawnMap.end(); ++itr)
    {
        if (*itr != 0)
        {
            // Remove pool from iterator if there are no more respawns
            if (!mNewPoolCreatureInfo[*itr].UpdateNewPool(mNewSpawnedData, mNewCreatureSearchMap, mFreeGuids))
                mRespawnMap.erase(*itr);
        }
    }
}

template void PoolMgr::UpdatePool<Pool>(uint32 pool_id, uint32 db_guid_or_pool_id);
template void PoolMgr::UpdatePool<GameObject>(uint32 pool_id, uint32 db_guid_or_pool_id);
template void PoolMgr::UpdatePool<Creature>(uint32 pool_id, uint32 db_guid_or_pool_id);
template void PoolMgr::UpdatePool<Quest>(uint32 pool_id, uint32 db_guid_or_pool_id);
