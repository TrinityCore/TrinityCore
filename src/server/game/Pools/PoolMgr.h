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

#ifndef TRINITY_POOLHANDLER_H
#define TRINITY_POOLHANDLER_H

#include "Define.h"
#include "ace/Singleton.h"
#include "Creature.h"
#include "GameObject.h"

struct PoolTemplateData
{
    uint32  MaxLimit;
};

struct PoolObject
{
    uint32  guid;
    float   chance;
    PoolObject(uint32 _guid, float _chance): guid(_guid), chance(fabs(_chance)) {}
};

class Pool                                                  // for Pool of Pool case
{
};

typedef std::set<uint32> SpawnedPoolObjects;
typedef std::map<uint32,uint32> SpawnedPoolPools;

class SpawnedPoolData
{
    public:
        template<typename T>
        bool IsSpawnedObject(uint32 db_guid_or_pool_id) const;

        uint32 GetSpawnedObjects(uint32 pool_id) const;

        template<typename T>
        void AddSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);

        template<typename T>
        void RemoveSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);
    private:
        SpawnedPoolObjects mSpawnedCreatures;
        SpawnedPoolObjects mSpawnedGameobjects;
        SpawnedPoolPools   mSpawnedPools;
};

template <class T>
class PoolGroup
{
    typedef std::vector<PoolObject> PoolObjectList;
    public:
        explicit PoolGroup() : poolId(0) { }
        void SetPoolId(uint32 pool_id) { poolId = pool_id; }
        ~PoolGroup() {};
        bool isEmpty() const { return ExplicitlyChanced.empty() && EqualChanced.empty(); }
        void AddEntry(PoolObject& poolitem, uint32 maxentries);
        bool CheckPool() const;
        PoolObject* RollOne(SpawnedPoolData& spawns, uint32 triggerFrom);
        void DespawnObject(SpawnedPoolData& spawns, uint32 guid=0);
        void Despawn1Object(uint32 guid);
        void SpawnObject(SpawnedPoolData& spawns, uint32 limit, uint32 triggerFrom);

        void Spawn1Object(PoolObject* obj);
        void ReSpawn1Object(PoolObject* obj);
        void RemoveOneRelation(uint16 child_pool_id);
    private:
        uint32 poolId;
        PoolObjectList ExplicitlyChanced;
        PoolObjectList EqualChanced;
};

class PoolMgr
{
    friend class ACE_Singleton<PoolMgr, ACE_Null_Mutex>;
    PoolMgr();
    ~PoolMgr() {};

    public:
        void LoadFromDB();
        void Initialize();

        template<typename T>
        uint16 IsPartOfAPool(uint32 db_guid_or_pool_id) const;

        template<typename T>
        bool IsSpawnedObject(uint32 db_guid_or_pool_id) const { return mSpawnedData.IsSpawnedObject<T>(db_guid_or_pool_id); }

        bool CheckPool(uint16 pool_id) const;

        void SpawnPool(uint16 pool_id);
        void DespawnPool(uint16 pool_id);

        template<typename T>
        void UpdatePool(uint16 pool_id, uint32 db_guid_or_pool_id);

    protected:
        template<typename T>
        void SpawnPool(uint16 pool_id, uint32 db_guid_or_pool_id);

        uint16 max_pool_id;
        typedef std::vector<PoolTemplateData> PoolTemplateDataMap;
        typedef std::vector<PoolGroup<Creature> >   PoolGroupCreatureMap;
        typedef std::vector<PoolGroup<GameObject> > PoolGroupGameObjectMap;
        typedef std::vector<PoolGroup<Pool> >       PoolGroupPoolMap;
        typedef std::pair<uint32, uint16> SearchPair;
        typedef std::map<uint32, uint16> SearchMap;

        PoolTemplateDataMap mPoolTemplate;
        PoolGroupCreatureMap mPoolCreatureGroups;
        PoolGroupGameObjectMap mPoolGameobjectGroups;
        PoolGroupPoolMap mPoolPoolGroups;
        SearchMap mCreatureSearchMap;
        SearchMap mGameobjectSearchMap;
        SearchMap mPoolSearchMap;

        // dynamic data
        SpawnedPoolData mSpawnedData;
};

#define poolhandler (*ACE_Singleton<PoolMgr, ACE_Null_Mutex>::instance())

// Method that tell if the creature is part of a pool and return the pool id if yes
template<>
inline uint16 PoolMgr::IsPartOfAPool<Creature>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mCreatureSearchMap.find(db_guid);
    if (itr != mCreatureSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the gameobject is part of a pool and return the pool id if yes
template<>
inline uint16 PoolMgr::IsPartOfAPool<GameObject>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mGameobjectSearchMap.find(db_guid);
    if (itr != mGameobjectSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the pool is part of another pool and return the pool id if yes
template<>
inline uint16 PoolMgr::IsPartOfAPool<Pool>(uint32 pool_id) const
{
    SearchMap::const_iterator itr = mPoolSearchMap.find(pool_id);
    if (itr != mPoolSearchMap.end())
        return itr->second;

    return 0;
}

#endif
