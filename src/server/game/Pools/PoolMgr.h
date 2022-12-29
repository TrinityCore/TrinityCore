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

#ifndef TRINITY_POOLHANDLER_H
#define TRINITY_POOLHANDLER_H

#include "Define.h"
#include "SpawnData.h"
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

class Creature;
class GameObject;
class Map;
class Quest;

struct PoolTemplateData
{
    uint32 MaxLimit;
    int32 MapId;
};

struct PoolObject
{
    ObjectGuid::LowType guid;
    float chance;
    PoolObject(ObjectGuid::LowType _guid, float _chance) : guid(_guid), chance(std::fabs(_chance)) { }
};

class Pool                                                  // for Pool of Pool case
{
};

typedef std::set<ObjectGuid::LowType> SpawnedPoolObjects;
typedef std::map<uint32, uint32> SpawnedPoolPools;

class TC_GAME_API SpawnedPoolData
{
    public:
        explicit SpawnedPoolData(Map* owner);
        ~SpawnedPoolData();

        SpawnedPoolData(SpawnedPoolData const& right) = delete;
        SpawnedPoolData(SpawnedPoolData&& right) = delete;
        SpawnedPoolData& operator=(SpawnedPoolData const& right) = delete;
        SpawnedPoolData& operator=(SpawnedPoolData&& right) = delete;

        Map* GetMap() const { return mOwner; }

        template<typename T>
        bool IsSpawnedObject(uint32 db_guid_or_pool_id) const;

        bool IsSpawnedObject(SpawnObjectType type, uint32 db_guid_or_pool_id) const;

        uint32 GetSpawnedObjects(uint32 pool_id) const;

        template<typename T>
        void AddSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);

        template<typename T>
        void RemoveSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);
    private:
        Map* mOwner;
        SpawnedPoolObjects mSpawnedCreatures;
        SpawnedPoolObjects mSpawnedGameobjects;
        SpawnedPoolPools   mSpawnedPools;
};

template <class T>
class TC_GAME_API PoolGroup
{
    typedef std::vector<PoolObject> PoolObjectList;
    public:
        explicit PoolGroup();
        ~PoolGroup();

        PoolGroup(PoolGroup const& right) = delete;
        PoolGroup(PoolGroup&& right) = delete;
        PoolGroup& operator=(PoolGroup const& right) = delete;
        PoolGroup& operator=(PoolGroup&& right) = delete;

        void SetPoolId(uint32 pool_id) { poolId = pool_id; }
        bool isEmpty() const { return ExplicitlyChanced.empty() && EqualChanced.empty(); }
        bool isEmptyDeepCheck() const;
        void AddEntry(PoolObject& poolitem, uint32 maxentries);
        bool CheckPool() const;
        void DespawnObject(SpawnedPoolData& spawns, ObjectGuid::LowType guid = 0, bool alwaysDeleteRespawnTime = false);
        void Despawn1Object(SpawnedPoolData& spawns, ObjectGuid::LowType guid, bool alwaysDeleteRespawnTime = false, bool saveRespawnTime = true);
        void SpawnObject(SpawnedPoolData& spawns, uint32 limit, uint32 triggerFrom);
        void RemoveRespawnTimeFromDB(SpawnedPoolData& spawns, ObjectGuid::LowType guid);

        void Spawn1Object(SpawnedPoolData& spawns, PoolObject* obj);
        void ReSpawn1Object(SpawnedPoolData& spawns, PoolObject* obj);
        void RemoveOneRelation(uint32 child_pool_id);
        uint32 GetPoolId() const { return poolId; }
    private:
        uint32 poolId;
        PoolObjectList ExplicitlyChanced;
        PoolObjectList EqualChanced;
};

class TC_GAME_API PoolMgr
{
    private:
        PoolMgr();
        ~PoolMgr();

    public:
        PoolMgr(PoolMgr const& right) = delete;
        PoolMgr(PoolMgr&& right) = delete;
        PoolMgr& operator=(PoolMgr const& right) = delete;
        PoolMgr& operator=(PoolMgr&& right) = delete;

        static PoolMgr* instance();

        void LoadFromDB();

        void Initialize();

        template<typename T>
        uint32 IsPartOfAPool(uint32 db_guid_or_pool_id) const;
        uint32 IsPartOfAPool(SpawnObjectType type, ObjectGuid::LowType spawnId) const;

        template<typename T>
        bool IsSpawnedObject(SpawnedPoolData& spawnedPoolData, uint32 db_guid_or_pool_id) const { return spawnedPoolData.IsSpawnedObject<T>(db_guid_or_pool_id); }

        bool IsEmpty(uint32 pool_id) const;
        bool CheckPool(uint32 pool_id) const;

        void SpawnPool(SpawnedPoolData& spawnedPoolData, uint32 pool_id);
        void DespawnPool(SpawnedPoolData& spawnedPoolData, uint32 pool_id, bool alwaysDeleteRespawnTime = false);

        template<typename T>
        void UpdatePool(SpawnedPoolData& spawnedPoolData, uint32 pool_id, uint32 db_guid_or_pool_id);
        void UpdatePool(SpawnedPoolData& spawnedPoolData, uint32 pool_id, SpawnObjectType type, ObjectGuid::LowType spawnId);

        std::unique_ptr<SpawnedPoolData> InitPoolsForMap(Map* map);

        PoolTemplateData const* GetPoolTemplate(uint16 pool_id) const;

    private:
        template<typename T>
        void SpawnPool(SpawnedPoolData& spawnedPoolData, uint32 pool_id, uint32 db_guid_or_pool_id);

        typedef std::unordered_map<uint32, PoolTemplateData>      PoolTemplateDataMap;
        typedef std::unordered_map<uint32, PoolGroup<Creature>>   PoolGroupCreatureMap;
        typedef std::unordered_map<uint32, PoolGroup<GameObject>> PoolGroupGameObjectMap;
        typedef std::unordered_map<uint32, PoolGroup<Pool>>       PoolGroupPoolMap;
        typedef std::pair<uint32, uint32>           SearchPair;
        typedef std::map<uint32, uint32>            SearchMap;

        PoolTemplateDataMap    mPoolTemplate;
        PoolGroupCreatureMap   mPoolCreatureGroups;
        PoolGroupGameObjectMap mPoolGameobjectGroups;
        PoolGroupPoolMap       mPoolPoolGroups;
        SearchMap mCreatureSearchMap;
        SearchMap mGameobjectSearchMap;
        SearchMap mPoolSearchMap;
        std::unordered_map<uint32, std::vector<uint32>> mAutoSpawnPoolsPerMap;
};

#define sPoolMgr PoolMgr::instance()

// Method that tell if the creature is part of a pool and return the pool id if yes
template<>
inline uint32 PoolMgr::IsPartOfAPool<Creature>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mCreatureSearchMap.find(db_guid);
    if (itr != mCreatureSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the gameobject is part of a pool and return the pool id if yes
template<>
inline uint32 PoolMgr::IsPartOfAPool<GameObject>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mGameobjectSearchMap.find(db_guid);
    if (itr != mGameobjectSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the pool is part of another pool and return the pool id if yes
template<>
inline uint32 PoolMgr::IsPartOfAPool<Pool>(uint32 pool_id) const
{
    SearchMap::const_iterator itr = mPoolSearchMap.find(pool_id);
    if (itr != mPoolSearchMap.end())
        return itr->second;

    return 0;
}

#endif
