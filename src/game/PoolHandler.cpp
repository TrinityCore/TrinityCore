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
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(PoolHandler);

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
bool PoolGroup<T>::CheckPool(void)
{
    if (EqualChanced.size() == 0)
    {
        float chance = 0;
        for (uint32 i=0; i<ExplicitlyChanced.size(); ++i)
            chance += ExplicitlyChanced[i].chance;
        if (chance != 100 && chance != 0)
            return false;
    }
    return true;
}

// Method that tell if the gameobject, creature or pool is spawned currently
template <class T>
bool PoolGroup<T>::IsSpawnedObject(uint32 guid)
{
    for (uint32 i=0; i<ExplicitlyChanced.size(); ++i)
        if (ExplicitlyChanced[i].guid == guid)
            return ExplicitlyChanced[i].spawned;
    for (uint32 i=0; i<EqualChanced.size(); ++i)
        if (EqualChanced[i].guid == guid)
            return EqualChanced[i].spawned;
    return false;
}

template <class T>
void PoolGroup<T>::RollOne(int32& index, PoolObjectList** store, uint32 triggerFrom)
{
    if (!ExplicitlyChanced.empty())
    {
        float roll = (float)rand_chance();

        for (uint32 i=0; i<ExplicitlyChanced.size(); ++i)
        {
            roll -= ExplicitlyChanced[i].chance;
            // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
            // so this need explicit check for this case
            if (roll < 0 && (!ExplicitlyChanced[i].spawned || ExplicitlyChanced[i].guid == triggerFrom))
            {
                index = i;
                *store = &ExplicitlyChanced;
                return;
            }
        }
    }
    if (!EqualChanced.empty())
    {
        index = irand(0, EqualChanced.size()-1);
        // Triggering object is marked as spawned at this time and can be also rolled (respawn case)
        // so this need explicit check for this case
        if (!EqualChanced[index].spawned || EqualChanced[index].guid == triggerFrom)
        {
            *store = &EqualChanced;
            return;
        }
    }

    index = -1;
}

// Main method to despawn a creature or gameobject in a pool
// If no guid is passed, the pool is just removed (event end case)
// If guid is filled, cache will be used and no removal will occur, it just fill the cache
template<class T>
void PoolGroup<T>::DespawnObject(uint32 guid)
{
    for (size_t i=0; i<EqualChanced.size(); ++i)
    {
        if (EqualChanced[i].spawned)
        {
            if (!guid || EqualChanced[i].guid == guid)
            {
                Despawn1Object(EqualChanced[i].guid);

                EqualChanced[i].spawned = false;
                if (m_SpawnedPoolAmount > 0)
                    --m_SpawnedPoolAmount;
            }
        }
    }

    for (size_t i = 0; i < ExplicitlyChanced.size(); ++i)
    {
        if (ExplicitlyChanced[i].spawned)
        {
            if (!guid || ExplicitlyChanced[i].guid == guid)
            {
                Despawn1Object(ExplicitlyChanced[i].guid);
                ExplicitlyChanced[i].spawned = false;

                if (m_SpawnedPoolAmount > 0)
                    --m_SpawnedPoolAmount;
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
        if(itr->guid == child_pool_id)
        {
            ExplicitlyChanced.erase(itr);
            break;
        }
    }
    for (PoolObjectList::iterator itr = EqualChanced.begin(); itr != EqualChanced.end(); ++itr)
    {
        if(itr->guid == child_pool_id)
        {
            EqualChanced.erase(itr);
            break;
        }
    }
}

template <class T>
void PoolGroup<T>::SpawnObject(uint32 limit, uint32 triggerFrom)
{
    uint32 lastDespawned = 0;
    int count = limit - m_SpawnedPoolAmount;

    // If triggered from some object respawn this object is still marked as spawned
    // and also counted into m_SpawnedPoolAmount so we need increase count to be 
    // spawned by 1
    if (triggerFrom)
        ++count;

    // This will try to spawn the rest of pool, not guaranteed
    for (int i = 0; i < count; ++i)
    {
        int index;
        PoolObjectList* store;

        RollOne(index, &store, triggerFrom);
        if (index == -1)
            continue;
        if ((*store)[index].guid == lastDespawned)
            continue;

        if ((*store)[index].guid == triggerFrom)
        {
            (*store)[index].spawned = ReSpawn1Object(triggerFrom);
            triggerFrom = 0;
            continue;
        }
        else
            (*store)[index].spawned = Spawn1Object((*store)[index].guid);

        if (triggerFrom)
        {
            // One spawn one despawn no count increase
            DespawnObject(triggerFrom);
            lastDespawned = triggerFrom;
            triggerFrom = 0;
        }
        else
            ++m_SpawnedPoolAmount;
    }
}

// Method that is actualy doing the spawn job on 1 creature
template <>
bool PoolGroup<Creature>::Spawn1Object(uint32 guid)
{
    if (CreatureData const* data = objmgr.GetCreatureData(guid))
    {
        objmgr.AddCreatureToGrid(guid, data);

        // Spawn if necessary (loaded grids only)
        Map* map = const_cast<Map*>(MapManager::Instance().CreateBaseMap(data->mapid));
        // We use spawn coords to spawn
        if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
        {
            Creature* pCreature = new Creature;
            //sLog.outDebug("Spawning creature %u",guid);
            if (!pCreature->LoadFromDB(guid, map))
            {
                delete pCreature;
                return false;
            }
            else
                map->Add(pCreature);
        }
        return true;
    }
    return false;
}

// Same for 1 gameobject
template <>
bool PoolGroup<GameObject>::Spawn1Object(uint32 guid)
{
    if (GameObjectData const* data = objmgr.GetGOData(guid))
    {
        objmgr.AddGameobjectToGrid(guid, data);
        // Spawn if necessary (loaded grids only)
        // this base map checked as non-instanced and then only existed
        Map* map = const_cast<Map*>(MapManager::Instance().CreateBaseMap(data->mapid));
        // We use current coords to unspawn, not spawn coords since creature can have changed grid
        if (!map->Instanceable() && map->IsLoaded(data->posX, data->posY))
        {
            GameObject* pGameobject = new GameObject;
            //sLog.outDebug("Spawning gameobject %u", guid);
            if (!pGameobject->LoadFromDB(guid, map))
            {
                delete pGameobject;
                return false;
            }
            else
            {
                if (pGameobject->isSpawnedByDefault())
                    map->Add(pGameobject);
            }
        }
        return true;
    }
    return false;
}

// Same for 1 pool
template <>
bool PoolGroup<Pool>::Spawn1Object(uint32 child_pool_id)
{
    poolhandler.SpawnPool(child_pool_id, 0, 0);
    poolhandler.SpawnPool(child_pool_id, 0, TYPEID_GAMEOBJECT);
    poolhandler.SpawnPool(child_pool_id, 0, TYPEID_UNIT);
    return true;
}

// Method that does the respawn job on the specified creature
template <>
bool PoolGroup<Creature>::ReSpawn1Object(uint32 guid)
{
    if (CreatureData const* data = objmgr.GetCreatureData(guid))
    {
        if (Creature* pCreature = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(guid, data->id, HIGHGUID_UNIT), (Creature*)NULL))
            pCreature->GetMap()->Add(pCreature);
        return true;
    }
    return false;
}

// Same for 1 gameobject
template <>
bool PoolGroup<GameObject>::ReSpawn1Object(uint32 guid)
{
    if (GameObjectData const* data = objmgr.GetGOData(guid))
    {
        if (GameObject* pGameobject = ObjectAccessor::Instance().GetObjectInWorld(MAKE_NEW_GUID(guid, data->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL))
            pGameobject->GetMap()->Add(pGameobject);
        return true;
    }
    return false;
}

// Nothing to do for a child Pool
template <>
bool PoolGroup<Pool>::ReSpawn1Object(uint32 /*guid*/)
{
    return true;
}

////////////////////////////////////////////////////////////
// Methods of class PoolHandler

PoolHandler::PoolHandler()
{
    m_IsPoolSystemStarted = false;
}

void PoolHandler::LoadFromDB()
{
    QueryResult *result = WorldDatabase.Query("SELECT MAX(entry) FROM pool_template");
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
        delete result;
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
    sLog.outString( ">> Loaded %u objects pools", count );
    delete result;

    // Creatures

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
        sLog.outString(">> Loaded %u creatures in pools", count );
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
                sLog.outErrorDb("`pool_creature` has a non existing creature spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id );
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
            cregroup.AddEntry(plObject, pPoolTemplate->MaxLimit);
            SearchPair p(guid, pool_id);
            mCreatureSearchMap.insert(p);

        } while (result->NextRow());
        sLog.outString();
        sLog.outString( ">> Loaded %u creatures in pools", count );
        delete result;
    }

    // Gameobjects

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
        sLog.outString(">> Loaded %u gameobject in pools", count );
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
                sLog.outErrorDb("`pool_gameobject` has a non existing gameobject spawn (GUID: %u) defined for pool id (%u), skipped.", guid, pool_id );
                continue;
            }
            GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(data->id);
            if (goinfo->type != GAMEOBJECT_TYPE_CHEST &&
                goinfo->type != GAMEOBJECT_TYPE_GOOBER &&
                goinfo->type != GAMEOBJECT_TYPE_FISHINGHOLE)
            {
                sLog.outErrorDb("`pool_gameobject` has a not lootable gameobject spawn (GUID: %u, type: %u) defined for pool id (%u), skipped.", guid, goinfo->type, pool_id );
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
            gogroup.AddEntry(plObject, pPoolTemplate->MaxLimit);
            SearchPair p(guid, pool_id);
            mGameobjectSearchMap.insert(p);

        } while( result->NextRow() );
        sLog.outString();
        sLog.outString( ">> Loaded %u gameobject in pools", count );
        delete result;
    }

    // Pool of pools
    mPoolPoolGroups.resize(max_pool_id + 1);
    //                                   1        2            3
    result = WorldDatabase.Query("SELECT pool_id, mother_pool, chance FROM pool_pool");

    count = 0;
    if( !result )
    {
        barGoLink bar2(1);
        bar2.step();

        sLog.outString();
        sLog.outString(">> Loaded %u pools in pools", count );
    }
    else
    {

        barGoLink bar2( result->GetRowCount() );
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
            plgroup.AddEntry(plObject, pPoolTemplateMother->MaxLimit);
            SearchPair p(child_pool_id, mother_pool_id);
            mPoolSearchMap.insert(p);

        } while( result->NextRow() );

        // Now check for circular reference
        for (uint16 i=0; i<max_pool_id; ++i)
        {
            std::set<uint16> checkedPools;
            for (SearchMap::iterator poolItr = mPoolSearchMap.find(i); poolItr != mPoolSearchMap.end(); poolItr = mPoolSearchMap.find(poolItr->second))
            {
                checkedPools.insert(poolItr->first);
                if(checkedPools.find(poolItr->second) != checkedPools.end())
                {
                    std::ostringstream ss;
                    ss<< "The pool(s) ";
                    for (std::set<uint16>::const_iterator itr=checkedPools.begin(); itr!=checkedPools.end(); ++itr)
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
        sLog.outString( ">> Loaded %u pools in mother pools", count );
        delete result;
    }
}

// The initialize method will spawn all pools not in an event and not in another pool, this is why there is 2 left joins with 2 null checks
void PoolHandler::Initialize()
{
    QueryResult *result = WorldDatabase.Query("SELECT DISTINCT pool_template.entry FROM pool_template LEFT JOIN game_event_pool ON pool_template.entry=game_event_pool.pool_entry LEFT JOIN pool_pool ON pool_template.entry=pool_pool.pool_id WHERE game_event_pool.pool_entry IS NULL AND pool_pool.pool_id IS NULL");
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
            SpawnPool(pool_entry, 0, 0);
            SpawnPool(pool_entry, 0, TYPEID_GAMEOBJECT);
            SpawnPool(pool_entry, 0, TYPEID_UNIT);
            count++;
        } while (result->NextRow());
        delete result;
    }

    sLog.outBasic("Pool handling system initialized, %u pools spawned.", count);
    m_IsPoolSystemStarted = true;
}

// Call to spawn a pool, if cache if true the method will spawn only if cached entry is different
// If it's same, the gameobject/creature is respawned only (added back to map)
void PoolHandler::SpawnPool(uint16 pool_id, uint32 guid, uint32 type)
{
    switch (type)
    {
        case TYPEID_UNIT:
            if (!mPoolCreatureGroups[pool_id].isEmpty())
                mPoolCreatureGroups[pool_id].SpawnObject(mPoolTemplate[pool_id].MaxLimit, guid);
            break;
        case TYPEID_GAMEOBJECT:
            if (!mPoolGameobjectGroups[pool_id].isEmpty())
                mPoolGameobjectGroups[pool_id].SpawnObject(mPoolTemplate[pool_id].MaxLimit, guid);
            break;
        default:
            if (!mPoolPoolGroups[pool_id].isEmpty())
                mPoolPoolGroups[pool_id].SpawnObject(mPoolTemplate[pool_id].MaxLimit, guid);
    }
}

// Call to despawn a pool, all gameobjects/creatures in this pool are removed
void PoolHandler::DespawnPool(uint16 pool_id)
{
    if (!mPoolCreatureGroups[pool_id].isEmpty())
        mPoolCreatureGroups[pool_id].DespawnObject();

    if (!mPoolGameobjectGroups[pool_id].isEmpty())
        mPoolGameobjectGroups[pool_id].DespawnObject();

    if (!mPoolPoolGroups[pool_id].isEmpty())
        mPoolPoolGroups[pool_id].DespawnObject();
}

// Call to update the pool when a gameobject/creature part of pool [pool_id] is ready to respawn
// Here we cache only the creature/gameobject whose guid is passed as parameter
// Then the spawn pool call will use this cache to decide
void PoolHandler::UpdatePool(uint16 pool_id, uint32 guid, uint32 type)
{
    if (uint16 motherpoolid = IsPartOfAPool(pool_id, 0))
        SpawnPool(motherpoolid, 0, 0);
    else
        SpawnPool(pool_id, guid, type);
}

// Method that tell if the gameobject/creature is part of a pool and return the pool id if yes
uint16 PoolHandler::IsPartOfAPool(uint32 guid, uint32 type)
{
    if (type == 0) // pool of pool
    {
        SearchMap::const_iterator itr = mPoolSearchMap.find(guid);
        if (itr != mPoolSearchMap.end())
            return itr->second;
    }
    else if (type == TYPEID_GAMEOBJECT)
    {
        SearchMap::const_iterator itr = mGameobjectSearchMap.find(guid);
        if (itr != mGameobjectSearchMap.end())
            return itr->second;
    }
    else // creature
    {
        SearchMap::const_iterator itr = mCreatureSearchMap.find(guid);
        if (itr != mCreatureSearchMap.end())
            return itr->second;
    }
    return 0;
}

// Method that check chance integrity of the creatures and gameobjects in this pool
bool PoolHandler::CheckPool(uint16 pool_id)
{
    return pool_id <= max_pool_id &&
        mPoolGameobjectGroups[pool_id].CheckPool() &&
        mPoolCreatureGroups[pool_id].CheckPool() &&
        mPoolPoolGroups[pool_id].CheckPool();
}

// Method that tell if a creature or gameobject in pool_id is spawned currently
bool PoolHandler::IsSpawnedObject(uint16 pool_id, uint32 guid, uint32 type)
{
    if (pool_id > max_pool_id)
        return false;
    if (type == 0)
        return mPoolPoolGroups[pool_id].IsSpawnedObject(guid);
    else if (type == TYPEID_GAMEOBJECT)
        return mPoolGameobjectGroups[pool_id].IsSpawnedObject(guid);
    else
        return mPoolCreatureGroups[pool_id].IsSpawnedObject(guid);
}
