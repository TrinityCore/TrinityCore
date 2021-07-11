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

#ifndef MANGOS_POOLHANDLER_H
#define MANGOS_POOLHANDLER_H

#include "Common.h"
#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include "Creature.h"
#include "GameObject.h"

class MapPersistentState;
struct MapEntry;

enum PoolFlags
{
    // spawn at pool system start (not part of another pool and not part of event spawn)
    POOL_FLAG_AUTO_SPAWN                        = 0x1,
    POOL_FLAG_MAXLIMIT_SCALING_LINEAR           = 0x2,
};

struct PoolTemplateData
{
    PoolTemplateData() : mapEntry(nullptr), MaxLimit(0), PoolFlags(0), InstanceId(0) {}

    MapEntry const* mapEntry;                               // Map id used for pool creature/gameobject spams. In case non-instanceable map
                                                            // it can be not unique but base at sharing same pool system dynamic data in this case this is not important.
                                                            // nullptr is no spawns by some reason
    uint32  MaxLimit;
    uint32  PoolFlags;
    uint32  InstanceId;
    std::string description;

    // helpers
    bool CanBeSpawnedAtMap(MapEntry const* entry) const
    {
        return mapEntry && mapEntry == entry;
    }
    bool IsAutoSpawn() const { return PoolFlags & POOL_FLAG_AUTO_SPAWN; }

    uint32 GetSpawnCount() const;
};

struct PoolObject
{
    enum ObjectFlags
    {
        FLAG_SPAWN_ENABLE_IF_WORLD_POP_OVER_BLIZZLIKE   = 0x1
    };
    uint32  guid;
    uint32  spawnFlags;
    float   chance;
    bool exclude;

    PoolObject(uint32 _guid, float _chance, uint32 flags): guid(_guid), spawnFlags(flags), chance(fabs(_chance)), exclude(false) {}
    bool CanBeSpawned() const;

    template<typename T>
    void CheckEventLinkAndReport(uint32 poolId, int16 event_id, std::map<uint32, int16> const& creature2event, std::map<uint32, int16> const& go2event) const;
};

class Pool                                                  // for Pool of Pool case
{
};

typedef std::set<uint32> SpawnedPoolObjects;
typedef std::map<uint32,uint32> SpawnedPoolPools;

class SpawnedPoolData
{
    public:
        SpawnedPoolData() : m_isInitialized(false) {}

        template<typename T>
        bool IsSpawnedObject(uint32 db_guid_or_pool_id) const;

        uint32 GetSpawnedObjects(uint32 pool_id) const;

        template<typename T>
        void AddSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);

        template<typename T>
        void RemoveSpawn(uint32 db_guid_or_pool_id, uint32 pool_id);

        bool IsInitialized() const { return m_isInitialized; }
        void SetInitialized() { m_isInitialized = true; }

        SpawnedPoolObjects const& GetSpawnedCreatures() const { return mSpawnedCreatures; }
        SpawnedPoolObjects const& GetSpawnedGameobjects() const { return mSpawnedGameobjects; }
        SpawnedPoolPools const& GetSpawnedPools() const { return mSpawnedPools; }
    private:
        SpawnedPoolObjects mSpawnedCreatures;
        SpawnedPoolObjects mSpawnedGameobjects;
        SpawnedPoolPools   mSpawnedPools;
        bool m_isInitialized;
};

typedef std::vector<PoolObject> PoolObjectList;

template <class T>
class PoolGroup
{
    public:
        explicit PoolGroup() : poolId(0) { }
        void SetPoolId(uint32 pool_id) { poolId = pool_id; }
        ~PoolGroup() {};
        bool isEmpty() const { return ExplicitlyChanced.empty() && EqualChanced.empty(); }
        void AddEntry(PoolObject& poolitem, uint32 maxentries);
        bool CheckPool() const;
        void CheckEventLinkAndReport(int16 event_id, std::map<uint32, int16> const& creature2event, std::map<uint32, int16> const& go2event) const;
        PoolObject* RollOne(SpawnedPoolData& spawns, uint32 triggerFrom);
        void DespawnObject(MapPersistentState& mapState, uint32 guid=0);
        void Despawn1Object(MapPersistentState& mapState, uint32 guid);
        void SpawnObject(MapPersistentState& mapState, uint32 limit, uint32 triggerFrom, bool instantly);
        void SetExcludeObject(uint32 guid, bool state);

        void Spawn1Object(MapPersistentState& mapState, PoolObject* obj, bool instantly);
        void ReSpawn1Object(MapPersistentState& mapState, PoolObject* obj);
        void RemoveOneRelation(uint16 child_pool_id);

        time_t GetPoolObjectRespawnTime(MapPersistentState& mapState, uint32 guid);

        PoolObjectList const& GetExplicitlyChanced() const { return ExplicitlyChanced; }
        PoolObjectList const& GetEqualChanced() const { return EqualChanced; }

        size_t size() const { return ExplicitlyChanced.size() + EqualChanced.size(); }
    private:
        uint32 poolId;
        PoolObjectList ExplicitlyChanced;
        PoolObjectList EqualChanced;
};

class PoolManager
{
    public:
        PoolManager();
        ~PoolManager() {};

        void LoadFromDB();
        void Initialize(MapPersistentState* state);         // called at new MapPersistentState object create

        uint16 GetMaxPoolId() const { return max_pool_id; }

        template<typename T>
        uint16 IsPartOfAPool(uint32 db_guid_or_pool_id) const;

        // Method that tell if the creature/gameobject/pool is part of top level pool and return the pool id if yes
        template<typename T>
        uint16 IsPartOfTopPool(uint32 db_guid_or_pool_id) const
        {
            if (uint16 pool_id = IsPartOfAPool<T>(db_guid_or_pool_id))
            {
                if (uint16 top_pool_id = IsPartOfTopPool<Pool>(pool_id))
                    return top_pool_id;

                return pool_id;
            }

            return 0;
        }

        template<typename T>
        void SetExcludeObject(uint16 pool_id, uint32 db_guid_or_pool_id, bool state);

        bool CheckPool(uint16 pool_id) const;
        void CheckEventLinkAndReport(uint16 pool_id, int16 event_id, std::map<uint32, int16> const& creature2event, std::map<uint32, int16> const& go2event) const;

        void SpawnPool(MapPersistentState& mapState, uint16 pool_id, bool instantly);
        void DespawnPool(MapPersistentState& mapState, uint16 pool_id);

        template<typename T>
        void UpdatePool(MapPersistentState& mapState, uint16 pool_id, uint32 db_guid_or_pool_id = 0);

        // used for calling from global systems when need spawn pool in all appropriate map instances
        void SpawnPoolInMaps(uint16 pool_id, bool instantly);
        void DespawnPoolInMaps(uint16 pool_id);

        // used for calling from global systems when need initialize spawn pool state in appropriate (possible) map persistent state
        void InitSpawnPool(MapPersistentState& mapState, uint16 pool_id);

        template<typename T>
        void UpdatePoolInMaps(uint16 pool_id, uint32 db_guid_or_pool_id = 0);

        void RemoveAutoSpawnForPool(uint16 pool_id) { mPoolTemplate[pool_id].PoolFlags &= ~POOL_FLAG_AUTO_SPAWN; }

        typedef std::vector<PoolTemplateData> PoolTemplateDataMap;
        PoolTemplateData const& GetPoolTemplate(uint16 pool_id) const { return mPoolTemplate[pool_id]; }
        PoolGroup<Creature>& GetPoolCreatures(uint16 pool_id)  { return mPoolCreatureGroups[pool_id]; }
        PoolGroup<GameObject>& GetPoolGameObjects(uint16 pool_id)  { return mPoolGameobjectGroups[pool_id]; }
        PoolGroup<Pool> const& GetPoolPools(uint16 pool_id) const  { return mPoolPoolGroups[pool_id]; }
    protected:
        template<typename T>
        void SpawnPoolGroup(MapPersistentState& mapState, uint16 pool_id, uint32 db_guid_or_pool_id, bool instantly);

        uint16 max_pool_id;

        typedef std::vector<PoolGroup<Creature> >   PoolGroupCreatureMap;
        typedef std::vector<PoolGroup<GameObject> > PoolGroupGameObjectMap;
        typedef std::vector<PoolGroup<Pool> >       PoolGroupPoolMap;
        typedef std::pair<uint32, uint16> SearchPair;
        typedef std::map<uint32, uint16> SearchMap;

        PoolTemplateDataMap mPoolTemplate;
        PoolGroupCreatureMap mPoolCreatureGroups;
        PoolGroupGameObjectMap mPoolGameobjectGroups;
        PoolGroupPoolMap mPoolPoolGroups;

        // static maps DB low guid -> pool id
        SearchMap mCreatureSearchMap;
        SearchMap mGameobjectSearchMap;
        SearchMap mPoolSearchMap;
};

#define sPoolMgr MaNGOS::Singleton<PoolManager>::Instance()

// Method that tell if the creature is part of a pool and return the pool id if yes
template<>
inline uint16 PoolManager::IsPartOfAPool<Creature>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mCreatureSearchMap.find(db_guid);
    if (itr != mCreatureSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the gameobject is part of a pool and return the pool id if yes
template<>
inline uint16 PoolManager::IsPartOfAPool<GameObject>(uint32 db_guid) const
{
    SearchMap::const_iterator itr = mGameobjectSearchMap.find(db_guid);
    if (itr != mGameobjectSearchMap.end())
        return itr->second;

    return 0;
}

// Method that tell if the pool is part of another pool and return the pool id if yes
template<>
inline uint16 PoolManager::IsPartOfAPool<Pool>(uint32 pool_id) const
{
    SearchMap::const_iterator itr = mPoolSearchMap.find(pool_id);
    if (itr != mPoolSearchMap.end())
        return itr->second;

    return 0;
}

#endif
