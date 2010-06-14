/*
 * Copyright (C) 2005-2009 MaNGOS <http://www.mangosproject.org/>
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

#include "PoolHandler.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Log.h"
#include "MapManager.h"
#include "SingletonImp.h"

INSTANTIATE_SINGLETON_1(PoolHandler);

////////////////////////////////////////////////////////////
// template class SpawnedPoolData

// Method that tell amount spawned objects/subpools
uint32 SpawnedPoolData::GetSpawnedObjects(uint32 pool_id) const
{
    SpawnedPoolPools::const_iterator itr = mSpawnedPools.find(pool_id);
    return itr != mSpawnedPools.end() ? itr->second : 0;
}

// Method that tell if a creature is spawned currently
template<>
bool SpawnedPoolData::IsSpawnedObject<Creature>(uint32 db_guid) const
{
    return mSpawnedCreatures.find(db_guid) != mSpawnedCreatures.end();
}

// Method that tell if a gameobject is spawned currently
template<>
bool SpawnedPoolData::IsSpawnedObject<GameObject>(uint32 db_guid) const
{
    return mSpawnedGameobjects.find(db_guid) != mSpawnedGameobjects.end();
}

// Method that tell if a pool is spawned currently
template<>
bool SpawnedPoolData::IsSpawnedObject<Pool>(uint32 sub_pool_id) const
{
    return mSpawnedPools.find(sub_pool_id) != mSpawnedPools.end();
}

template<>
void SpawnedPoolData::AddSpawn<Creature>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedCreatures.insert(db_guid);
    ++mSpawnedPools[pool_id];
}

template<>
void SpawnedPoolData::AddSpawn<GameObject>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedGameobjects.insert(db_guid);
    ++mSpawnedPools[pool_id];
}

template<>
void SpawnedPoolData::AddSpawn<Pool>(uint32 sub_pool_id, uint32 pool_id)
{
    mSpawnedPools[sub_pool_id] = 0;
    ++mSpawnedPools[pool_id];
}

template<>
void SpawnedPoolData::RemoveSpawn<Creature>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedCreatures.erase(db_guid);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

template<>
void SpawnedPoolData::RemoveSpawn<GameObject>(uint32 db_guid, uint32 pool_id)
{
    mSpawnedGameobjects.erase(db_guid);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

template<>
void SpawnedPoolData::RemoveSpawn<Pool>(uint32 sub_pool_id, uint32 pool_id)
{
    mSpawnedPools.erase(sub_pool_id);
    uint32& val = mSpawnedPools[pool_id];
    if (val > 0)
        --val;
}

////////////////////////////////////////////////////////////
// Methods of template class PoolGroup

// Method to add a gameobject/creature guid to the proper list depending on pool type and chance value
template <class T>
void PoolGroup<T>::AddEntry(PoolObject& poolitem, uint32 maxentries)
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
    if (EqualChanced.size() && ExplicitlyChanced.size())
        return false;

    if (ExplicitlyChanced.size())
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
PoolObject* PoolGroup<T>::RollOne(SpawnedPoolData& spawns, uint32 triggerFrom)
{
    if (!ExplicitlyChanced.empty())
    {
        float roll = (float)rand_chance();

        for (uint32 i=0; i<ExplicitlyChanced.size(); ++i)
        {
            roll -= ExplicitlyChanced[i].chance;
            // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
            // so this need explicit check for this case
            if (roll < 0 && (ExplicitlyChanced[i].guid == triggerFrom || !spawns.IsSpawnedObject<T>(ExplicitlyChanced[i].guid)))
               return &ExplicitlyChanced[i];
        }
    }
    if (!EqualChanced.empty())
    {
        int32 index = irand(0, EqualChanced.size()-1);
        // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
        // so this need explicit check for this case
        if (EqualChanced[index].guid == triggerFrom || !spawns.IsSpawnedObject<T>(EqualChanced[index].guid))
           return &EqualChanced[index];
    }

    return NULL;
}

// Main method to despawn a creature or gameobject in a pool
// If no guid is passed, the pool is just removed (event end case)
// If guid is filled, cache will be used and no removal will occur, it just fill the cache
template<class T>
void PoolGroup<T>::DespawnObject(SpawnedPoolData& spawns, uint32 guid)
{
    for (size_t i=0; i<EqualChanced.size(); ++i)
    {
        // if spawned
        if (spawns.IsSpawnedObject<T>(EqualChanced[i].guid))
        {
            if (!guid || EqualChanced[i].guid == guid)
            {
                Despawn1Object(EqualChanced[i].guid);
                spawns.RemoveSpawn<T>(EqualChanced[i].guid,poolId);
            }
        }
    }

    for (size_t i = 0; i < ExplicitlyChanced.size(); ++i)
    {
        // spawned
        if (spawns.IsSpawnedObject<T>(ExplicitlyChanced[i].guid))
        {
            if (!guid || ExplicitlyChanced[i].guid == guid)
            {
                Despawn1Object(ExplicitlyChanced[i].guid);
                spawns.RemoveSpawn<T>(ExplicitlyChanced[i].guid,poolId);
            }
        }
    }
}

// Method that is actualy doing the removal job on one creature
template<>
void PoolGroup<Creature>::Despawn1Object(uint32 guid)
{
    if (CreatureData const* data = objmgr.GetCreatureData(guid))
    {
        objmgr.RemoveCreatureFromGrid(guid, data);

        if (Creature* pCreature = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(guid, data->id, HIGHGUID_UNIT), (Creature*)NULL))
            pCreature->AddObjectToRemoveList();
    }
}

// Same on one gameobject
template<>
void PoolGroup<GameObject>::Despawn1Object(uint32 guid)
{
    if (GameObjectData const* data = objmgr.GetGOData(guid))
    {
        objmgr.RemoveGameobjectFromGrid(guid, data);

        if (GameObject* pGameobject = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(guid, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL))
            pGameobject->AddObjectToRemoveList();
    }
}

// Same on one pool
template<>
void PoolGroup<Pool>::Despawn1Object(uint32 child_pool_id)
{
    poolhandler.DespawnPool(child_pool_id);
}

// Method for a pool only to remove any found record causing a circular dependency loop
template<>
void PoolGroup<Pool>::RemoveOneRelation(uint16 child_pool_id)
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
void PoolGroup<T>::SpawnObject(SpawnedPoolData& spawns, uint32 limit, uint32 triggerFrom)
{
    uint32 lastDespawned = 0;
    int count = limit - spawns.GetSpawnedObjects(poolId);

    // If triggered from some object respawn this object is still marked as spawned
    // and also counted into m_SpawnedPoolAmount so we need increase count to be
    // spawned by 1
    if (triggerFrom)
        ++count;

    // This will try to spawn the rest of pool, not guaranteed
    for (int i = 0; i < count; ++i)
    {
        PoolObject* obj = RollOne(spawns,triggerFrom);
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
        spawns.AddSpawn<T>(obj->guid,poolId);
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
    if (CreatureData const* data = objmgr.GetCreatureData(obj->guid))
    {
        objmgr.AddCreatureToGrid(obj->guid, data);

        // Spawn if necessary (loaded grids only)
        Map* map = const_cast<Map*>(MapManager::Instance().CreateBaseMap(data->mapid));
        // We use spawn coords to spawn
        if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
        {
            Creature* pCreature = new Creature;
            //sLog.outDebug("Spawning creature %u",guid);
            if (!pCreature->LoadFromDB(obj->guid, map))
            {
                delete pCreature;
                return;
            }
            else
                map->Add(pCreature);
        }
    }
}

// Same for 1 gameobject
template <>
void PoolGroup<GameObject>::Spawn1Object(PoolObject* obj)
{
    if (GameObjectData const* data = objmgr.GetGOData(obj->guid))
    {
        objmgr.AddGameobjectToGrid(obj->guid, data);
        // Spawn if necessary (loaded grids only)
        // this base map checked as non-instanced and then only existed
        Map* map = const_cast<Map*>(MapManager::Instance().CreateBaseMap(data->mapid));
        // We use current coords to unspawn, not spawn coords since creature can have changed grid
        if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
        {
            GameObject* pGameobject = new GameObject;
            //sLog.outDebug("Spawning gameobject %u", guid);
            if (!pGameobject->LoadFromDB(obj->guid, map))
            {
                delete pGameobject;
                return;
            }
            else
            {
                if (pGameobject->isSpawnedByDefault())
                    map->Add(pGameobject);
            }
        }
    }
}

// Same for 1 pool
template <>
void PoolGroup<Pool>::Spawn1Object(PoolObject* obj)
{
    poolhandler.SpawnPool(obj->guid);
}

// Method that does the respawn job on the specified creature
template <>
void PoolGroup<Creature>::ReSpawn1Object(PoolObject* obj)
{
    if (CreatureData const* data = objmgr.GetCreatureData(obj->guid))
        if (Creature* pCreature = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(obj->guid, data->id, HIGHGUID_UNIT), (Creature*)NULL))
            pCreature->GetMap()->Add(pCreature);
}

// Method that does the respawn job on the specified gameobject
template <>
void PoolGroup<GameObject>::ReSpawn1Object(PoolObject* obj)
{
    if (GameObjectData const* data = objmgr.GetGOData(obj->guid))
        if (GameObject* pGameobject = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(obj->guid, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL))
            pGameobject->GetMap()->Add(pGameobject);
}

// Nothing to do for a child Pool
template <>
void PoolGroup<Pool>::ReSpawn1Object(PoolObject* /*obj*/)
{
}

////////////////////////////////////////////////////////////
// Methods of class PoolHandler

PoolHandler::PoolHandler()
{
}

void PoolHandler::LoadFromDB()
{
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT MAX(entry) FROM pool_template");
    if (!result)
    {
        sLog.outString(">> Table pool_template is empty.");
        sLog.outString();
        return;
    }
    else
    {
        Field *fields = result->Fetch();
        max_pool_id = fields[0].GetUInt16();
    }

    mPoolTemplate.resize(max_pool_id + 1);

    result = WorldDatabase.Query("SELECT entry,max_limit FROM pool_template");
    if (!result)
    {
        mPoolTemplate.clear();
        sLog.outString(">> Table pool_template is empty:");
        sLog.outString();
        return;
    }

    uint32 count = 0;

    barGoLink bar(result->GetRowCount());
    do
    {
        ++count;
        Field *fields = result->Fetch();

        bar.step();

        uint16 pool_id = fields[0].GetUInt16();

        PoolTemplateData& pPoolTemplate = mPoolTemplate[pool_id];
        pPoolTemplate.MaxLimit  = fields[1].GetUInt32();

    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u objects pools", count);

    // Creatures

    sLog.outString();
    sLog.outString("Loading Creatures Pooling Data...");

    mPoolCreatureGroups.resize(max_pool_id + 1);
    mCreatureSearchMap.clear();
    //                                   1     2           3
    result = WorldDatabase.Query("SELECT guid, pool_entry, chance FROM pool_creature");

    count = 0;
    if (!result)
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u creatures in pools", count);
    }
    else
    {

        barGoLink bar2(result->GetRowCount());
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint32 guid    = fields[0].GetUInt32();
            uint16 pool_id = fields[1].GetUInt16();
            float chance   = fields[2].GetFloat();

            CreatureData const* data = objmgr.GetCreatureData(guid);
            if (!data)
            {
                sLog.outErrorDb("`pool_creature` has a non existing creature spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id);
                continue;
            }
            if (pool_id > max_pool_id)
            {
                sLog.outErrorDb("`pool_creature` pool id (%i) is out of range compared to max pool id in `pool_template`, skipped.",pool_id);
                continue;
            }
            if (chance < 0 || chance > 100)
            {
                sLog.outErrorDb("`pool_creature` has an invalid chance (%f) for creature guid (%u) in pool id (%i), skipped.", chance, guid, pool_id);
                continue;
            }
            PoolTemplateData *pPoolTemplate = &mPoolTemplate[pool_id];
            ++count;

            PoolObject plObject = PoolObject(guid, chance);
            PoolGroup<Creature>& cregroup = mPoolCreatureGroups[pool_id];
            cregroup.SetPoolId(pool_id);
            cregroup.AddEntry(plObject, pPoolTemplate->MaxLimit);
            SearchPair p(guid, pool_id);
            mCreatureSearchMap.insert(p);

        } while (result->NextRow());
        sLog.outString();
        sLog.outString(">> Loaded %u creatures in pools", count);
    }

    // Gameobjects

    sLog.outString("Loading Gameobject Pooling Data...");

    mPoolGameobjectGroups.resize(max_pool_id + 1);
    mGameobjectSearchMap.clear();
    //                                   1     2           3
    result = WorldDatabase.Query("SELECT guid, pool_entry, chance FROM pool_gameobject");

    count = 0;
    if (!result)
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u gameobject in pools", count);
    }
    else
    {

        barGoLink bar2(result->GetRowCount());
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint32 guid    = fields[0].GetUInt32();
            uint16 pool_id = fields[1].GetUInt16();
            float chance   = fields[2].GetFloat();

            GameObjectData const* data = objmgr.GetGOData(guid);
            if (!data)
            {
                sLog.outErrorDb("`pool_gameobject` has a non existing gameobject spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id);
                continue;
            }
            GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(data->id);
            if (goinfo->type != GAMEOBJECT_TYPE_CHEST &&
                goinfo->type != GAMEOBJECT_TYPE_GOOBER &&
                goinfo->type != GAMEOBJECT_TYPE_FISHINGHOLE)
            {
                sLog.outErrorDb("`pool_gameobject` has a not lootable gameobject spawn (GUID: %u, type: %u) defined for pool id (%u), skipped.", guid, goinfo->type, pool_id);
                continue;
            }
            if (pool_id > max_pool_id)
            {
                sLog.outErrorDb("`pool_gameobject` pool id (%i) is out of range compared to max pool id in `pool_template`, skipped.",pool_id);
                continue;
            }
            if (chance < 0 || chance > 100)
            {
                sLog.outErrorDb("`pool_gameobject` has an invalid chance (%f) for gameobject guid (%u) in pool id (%i), skipped.", chance, guid, pool_id);
                continue;
            }
            PoolTemplateData *pPoolTemplate = &mPoolTemplate[pool_id];

            ++count;

            PoolObject plObject = PoolObject(guid, chance);
            PoolGroup<GameObject>& gogroup = mPoolGameobjectGroups[pool_id];
            gogroup.SetPoolId(pool_id);
            gogroup.AddEntry(plObject, pPoolTemplate->MaxLimit);
            SearchPair p(guid, pool_id);
            mGameobjectSearchMap.insert(p);

        } while (result->NextRow());
        sLog.outString();
        sLog.outString(">> Loaded %u gameobject in pools", count);
    }

    // Pool of pools

    sLog.outString("Loading Mother Pooling Data...");

    mPoolPoolGroups.resize(max_pool_id + 1);
    //                                      1        2            3
    result = WorldDatabase.Query("SELECT pool_id, mother_pool, chance FROM pool_pool");

    count = 0;
    if (!result)
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u pools in pools", count);
    }
    else
    {

        barGoLink bar2(result->GetRowCount());
        do
        {
            Field *fields = result->Fetch();

            bar2.step();

            uint16 child_pool_id  = fields[0].GetUInt16();
            uint16 mother_pool_id = fields[1].GetUInt16();
            float chance          = fields[2].GetFloat();

            if (mother_pool_id > max_pool_id)
            {
                sLog.outErrorDb("`pool_pool` mother_pool id (%i) is out of range compared to max pool id in `pool_template`, skipped.",mother_pool_id);
                continue;
            }
            if (child_pool_id > max_pool_id)
            {
                sLog.outErrorDb("`pool_pool` included pool_id (%i) is out of range compared to max pool id in `pool_template`, skipped.",child_pool_id);
                continue;
            }
            if (mother_pool_id == child_pool_id)
            {
                sLog.outErrorDb("`pool_pool` pool_id (%i) includes itself, dead-lock detected, skipped.",child_pool_id);
                continue;
            }
            if (chance < 0 || chance > 100)
            {
                sLog.outErrorDb("`pool_pool` has an invalid chance (%f) for pool id (%u) in mother pool id (%i), skipped.", chance, child_pool_id, mother_pool_id);
                continue;
            }
            PoolTemplateData *pPoolTemplateMother = &mPoolTemplate[mother_pool_id];

            ++count;

            PoolObject plObject = PoolObject(child_pool_id, chance);
            PoolGroup<Pool>& plgroup = mPoolPoolGroups[mother_pool_id];
            plgroup.SetPoolId(mother_pool_id);
            plgroup.AddEntry(plObject, pPoolTemplateMother->MaxLimit);
            SearchPair p(child_pool_id, mother_pool_id);
            mPoolSearchMap.insert(p);

        } while (result->NextRow());

        // Now check for circular reference
        for (uint16 i=0; i<max_pool_id; ++i)
        {
            std::set<uint16> checkedPools;
            for (SearchMap::iterator poolItr = mPoolSearchMap.find(i); poolItr != mPoolSearchMap.end(); poolItr = mPoolSearchMap.find(poolItr->second))
            {
                checkedPools.insert(poolItr->first);
                if (checkedPools.find(poolItr->second) != checkedPools.end())
                {
                    std::ostringstream ss;
                    ss<< "The pool(s) ";
                    for (std::set<uint16>::const_iterator itr=checkedPools.begin(); itr != checkedPools.end(); ++itr)
                        ss << *itr << " ";
                    ss << "create(s) a circular reference, which can cause the server to freeze.\nRemoving the last link between mother pool "
                        << poolItr->first << " and child pool " << poolItr->second;
                    sLog.outErrorDb(ss.str().c_str());
                    mPoolPoolGroups[poolItr->second].RemoveOneRelation(poolItr->first);
                    mPoolSearchMap.erase(poolItr);
                    --count;
                    break;
                }
            }
        }

        sLog.outString();
        sLog.outString(">> Loaded %u pools in mother pools", count);
    }
}

// The initialize method will spawn all pools not in an event and not in another pool, this is why there is 2 left joins with 2 null checks
void PoolHandler::Initialize()
{
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT DISTINCT pool_template.entry FROM pool_template LEFT JOIN game_event_pool ON pool_template.entry=game_event_pool.pool_entry LEFT JOIN pool_pool ON pool_template.entry=pool_pool.pool_id WHERE game_event_pool.pool_entry IS NULL AND pool_pool.pool_id IS NULL");
    uint32 count=0;
    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint16 pool_entry = fields[0].GetUInt16();
            if (!CheckPool(pool_entry))
            {
                sLog.outErrorDb("Pool Id (%u) has all creatures or gameobjects with explicit chance sum <>100 and no equal chance defined. The pool system cannot pick one to spawn.", pool_entry);
                continue;
            }
            SpawnPool(pool_entry);;
            count++;
        } while (result->NextRow());
    }

    sLog.outBasic("Pool handling system initialized, %u pools spawned.", count);
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the creature is respawned only (added back to map)
template<>
void PoolHandler::SpawnPool<Creature>(uint16 pool_id, uint32 db_guid)
{
    if (!mPoolCreatureGroups[pool_id].isEmpty())
        mPoolCreatureGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MaxLimit, db_guid);
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the gameobject is respawned only (added back to map)
template<>
void PoolHandler::SpawnPool<GameObject>(uint16 pool_id, uint32 db_guid)
{
    if (!mPoolGameobjectGroups[pool_id].isEmpty())
        mPoolGameobjectGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MaxLimit, db_guid);
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the pool is respawned only
template<>
void PoolHandler::SpawnPool<Pool>(uint16 pool_id, uint32 sub_pool_id)
{
    if (!mPoolPoolGroups[pool_id].isEmpty())
        mPoolPoolGroups[pool_id].SpawnObject(mSpawnedData, mPoolTemplate[pool_id].MaxLimit, sub_pool_id);
}

void PoolHandler::SpawnPool(uint16 pool_id)
{
    SpawnPool<Pool>(pool_id, 0);
    SpawnPool<GameObject>(pool_id, 0);
    SpawnPool<Creature>(pool_id, 0);
}

// Call to despawn a pool, all gameobjects/creatures in this pool are removed
void PoolHandler::DespawnPool(uint16 pool_id)
{
    if (!mPoolCreatureGroups[pool_id].isEmpty())
        mPoolCreatureGroups[pool_id].DespawnObject(mSpawnedData);

    if (!mPoolGameobjectGroups[pool_id].isEmpty())
        mPoolGameobjectGroups[pool_id].DespawnObject(mSpawnedData);

    if (!mPoolPoolGroups[pool_id].isEmpty())
        mPoolPoolGroups[pool_id].DespawnObject(mSpawnedData);
}

// Method that check chance integrity of the creatures and gameobjects in this pool
bool PoolHandler::CheckPool(uint16 pool_id) const
{
    return pool_id <= max_pool_id &&
        mPoolGameobjectGroups[pool_id].CheckPool() &&
        mPoolCreatureGroups[pool_id].CheckPool() &&
        mPoolPoolGroups[pool_id].CheckPool();
}

// Call to update the pool when a gameobject/creature part of pool [pool_id] is ready to respawn
// Here we cache only the creature/gameobject whose guid is passed as parameter
// Then the spawn pool call will use this cache to decide
template<typename T>
void PoolHandler::UpdatePool(uint16 pool_id, uint32 db_guid_or_pool_id)
{
    if (uint16 motherpoolid = IsPartOfAPool<Pool>(pool_id))
        SpawnPool<Pool>(motherpoolid, pool_id);
    else
        SpawnPool<T>(pool_id, db_guid_or_pool_id);
}

template void PoolHandler::UpdatePool<Pool>(uint16 pool_id, uint32 db_guid_or_pool_id);
template void PoolHandler::UpdatePool<GameObject>(uint16 pool_id, uint32 db_guid_or_pool_id);
template void PoolHandler::UpdatePool<Creature>(uint16 pool_id, uint32 db_guid_or_pool_id);
