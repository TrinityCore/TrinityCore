/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://www.mangosproject.org/>
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
#include "Creature.h"
#include "GameObject.h"
#include "QuestDef.h"

struct PoolTemplateData
{
    uint32  MinLimit;
    uint32  MaxLimit;
};

struct PoolObject
{
    uint32  guid;
    float   chance;
    PoolObject(uint32 _guid, float _chance) : guid(_guid), chance(std::fabs(_chance)) { }
};

// Creature Info
struct PoolCreatureInfo
{
    uint32 creature_id;
    uint32 creature_qual;
    float  chance;
    uint32 phaseMask;
    uint32 displayid;
    int8 equipmentId;
    uint32 spawntimesecs;
    uint32 corpsetimeloot;
    uint32 corpsetimenoloot;
    float spawndist;
    uint32 currentwaypoint;
    uint32 curhealth;
    uint32 curmana;
    uint8 movementType;
    uint8 spawnMask;
    uint32 npcflag;
    uint32 unit_flags;                                      // enum UnitFlags mask values
    uint32 dynamicflags;
};

// Spawn points (shared, creature + game object)
struct PoolSpawnPoints
{
    uint32 guid;
    uint16 mapid;
    uint16 zoneid;
    uint16 areaid;
    float posX;
    float posY;
    float posZ;
    float orientation;
};

struct RespawnTimer
{
    uint32 timediff;
    uint32 pool_id;
};

class Pool                                                  // for Pool of Pool case
{
};

typedef std::set<uint32> ActivePoolObjects;
typedef std::map<uint32, uint32> ActivePoolPools;
typedef std::set<uint32> RespawnPool;
typedef std::map<uint32, uint32> FreeGuid;
typedef std::pair<uint32, uint32> GuidPair;

class ActivePoolData
{
    public:
        template<typename T>
        bool IsActiveObject(uint32 db_guid_or_pool_id) const;

        uint32 GetActiveObjectCount(uint32 pool_id) const;

        template<typename T>
        void ActivateObject(uint32 db_guid_or_pool_id, uint32 pool_id);

        template<typename T>
        void RemoveObject(uint32 db_guid_or_pool_id, uint32 pool_id);

        ActivePoolObjects GetActiveQuests() const { return mActiveQuests; } // a copy of the set
    private:
        ActivePoolObjects mSpawnedCreatures;
        ActivePoolObjects mSpawnedGameobjects;
        ActivePoolObjects mActiveQuests;
        ActivePoolPools   mSpawnedPools;

};

class NewActivePoolData
{
    public:
        bool IsActiveCreature(uint32 guid) const;
        bool IsActiveGameObject(uint32 guid) const;

        uint32 GetActiveObjectCount(uint32 pool_id) const;

        void ActivateCreature(uint32 guid, uint32 pool_id);
        void ActivateGameObject(uint32 guid, uint32 pool_id);

        void RemoveCreature(uint32 guid, uint32 pool_id);
        void RemoveGameObject(uint32 guid, uint32 pool_id);

    private:
        ActivePoolObjects mNewSpawnedCreatures;
        ActivePoolObjects mNewSpawnedGameobjects;
        ActivePoolPools   mNewSpawnedPools;
};

template <class T>
class PoolGroup
{
    typedef std::vector<PoolObject> PoolObjectList;
    public:
        explicit PoolGroup() : poolId(0) { }
        void SetPoolId(uint32 pool_id) { poolId = pool_id; }
        ~PoolGroup() { };
        bool isEmpty() const { return ExplicitlyChanced.empty() && EqualChanced.empty(); }
        void AddEntry(PoolObject& poolitem, uint32 minentries, uint32 maxentries);
        bool CheckPool() const;
        PoolObject* RollOne(ActivePoolData& spawns, uint32 triggerFrom);
        void DespawnObject(ActivePoolData& spawns, uint32 guid=0);
        void Despawn1Object(uint32 guid);
        void SpawnObject(ActivePoolData& spawns, uint32 minlimit, uint32 maxlimit, uint32 triggerFrom);

        void Spawn1Object(PoolObject* obj);
        void ReSpawn1Object(PoolObject* obj);
        void RemoveOneRelation(uint32 child_pool_id);
        uint32 GetFirstEqualChancedObjectId()
        {
            if (EqualChanced.empty())
                return 0;
            return EqualChanced.front().guid;
        }
        uint32 GetPoolId() const { return poolId; }
    private:
        uint32 poolId;
        PoolObjectList ExplicitlyChanced;
        PoolObjectList EqualChanced;
};

class NewPoolGroup
{
    typedef std::vector<PoolCreatureInfo> PoolCreatureList;
    typedef std::vector<PoolSpawnPoints>  PoolSpawnpointList;
    typedef std::pair<uint32, uint32>     SearchPair;
    typedef std::map<uint32, uint32>      SearchMap;
    typedef std::pair<time_t, uint32>     TimePair;
    typedef std::set<TimePair>            SpawnTimeMap;

    public:
        explicit NewPoolGroup() : poolId(0) { }
        void SetPoolId(uint32 pool_id) { poolId = pool_id; }
        ~NewPoolGroup() { };
        bool isEmpty() const { return (PoolCreatures.empty() || PoolSpawns.empty()); }
        void AddCreatureEntry(PoolCreatureInfo& poolitem);
        void AddSpawnEntry(PoolSpawnPoints& poolitem);
        bool CheckPool();
        PoolCreatureInfo* RollCreature();
        PoolSpawnPoints* RollSpawnPoint();
        void DespawnCreature(NewActivePoolData& spawns, SearchMap& CreatureMap, RespawnPool& RespawnMap, uint32 guid);
        void Despawn1Creature(uint32 guid);
        void DespawnGameObject(NewActivePoolData& spawns, uint32 guid=0);
        void Despawn1GameObject(uint32 guid);
        void ClearSpawn(uint32 guid, uint32 minspawns);
        void Respawn1Creature(NewActivePoolData& spawns, SearchMap& CreatureMap, FreeGuid& FreeGuids);
        void SpawnCreature(NewActivePoolData& spawns, SearchMap& CreatureMap, uint32 minlimit, uint32 maxlimit, FreeGuid& FreeGuids);
        void SpawnGameObject(NewActivePoolData& spawns, uint32 minlimit, uint32 maxlimit);
        bool UpdateNewPool(NewActivePoolData& spawns, SearchMap& CreatureMap, FreeGuid& FreeGuids);
        PoolCreatureInfo* GetCreatureInfo(uint32 guid);
        PoolSpawnPoints* GetCreatureSpawn(uint32 guid);

        uint32 Spawn1Creature(PoolCreatureInfo* info, PoolSpawnPoints* spawnpoint, SearchMap& CreatureMap, FreeGuid& FreeGuids);
        void Spawn1GameObject(PoolObject* obj);
        void ReSpawn1Creature(PoolCreatureInfo* info, PoolSpawnPoints* spawnpoint);
        void RemoveOneRelation(uint32 child_pool_id);
        PoolCreatureList const* GetCreatures() { return &PoolCreatures; }
        PoolSpawnpointList const* GetSpawns() { return &PoolSpawns; }
        uint32 PoolSpawnCount() { return PoolActiveSpawns.size(); }
        uint32 GetPoolId() const { return poolId; }
    private:
        uint32 FindSpawnIndex(uint32 guid);
        uint32 FindCreatureIndex(uint32 creature_id, uint32 creature_qual);
        uint32 poolId;
        PoolCreatureList PoolCreatures;
        PoolSpawnpointList PoolSpawns;
        SearchMap PoolFreeSpawns;
        SearchMap PoolActiveSpawns;
        SearchMap CreatureSpawnPoints;
        SearchMap CreatureInfoMap;
        SpawnTimeMap Respawns;

};

typedef std::multimap<uint32, uint32> PooledQuestRelation;
typedef std::pair<PooledQuestRelation::const_iterator, PooledQuestRelation::const_iterator> PooledQuestRelationBounds;
typedef std::pair<PooledQuestRelation::iterator, PooledQuestRelation::iterator> PooledQuestRelationBoundsNC;

class PoolMgr
{
    private:
        PoolMgr();
        ~PoolMgr() { };

    public:
        typedef std::pair<uint32, uint32>           SearchPair;
        typedef std::map<uint32, uint32>            SearchMap;
        static PoolMgr* instance()
        {
            static PoolMgr instance;
            return &instance;
        }

        void LoadFromDB();
        void LoadQuestPools();
        void SaveQuestsToDB();

        void Initialize();

        template<typename T>
        uint32 IsPartOfAPool(uint32 db_guid_or_pool_id) const;

        uint32 IsPoolCreature(uint32 guid) const;

        template<typename T>
        bool IsSpawnedObject(uint32 db_guid_or_pool_id) const { return mSpawnedData.IsActiveObject<T>(db_guid_or_pool_id); }

        bool CheckPool(uint32 pool_id);

        bool NeedExpeditedRespawn(uint32 guid);
        void HandleCreatureDeath(uint32 guid);
        void HandleDespawn(uint32 guid);
        void ResetLootTimer(uint32 guid);
        void UpdateNewPool(uint32 diff);

        void SpawnPool(uint32 pool_id);
        void DespawnPool(uint32 pool_id);

        void SpawnNewPool(uint32 pool_id);

        template<typename T>
        void UpdatePool(uint32 pool_id, uint32 db_guid_or_pool_id);

        void ChangeDailyQuests();
        void ChangeWeeklyQuests();

        PoolCreatureInfo* GetCreatureInfo(uint32 pool_id, uint32 guid);
        PoolSpawnPoints* GetCreatureSpawn(uint32 pool_id, uint32 guid);

        PooledQuestRelation mQuestCreatureRelation;
        PooledQuestRelation mQuestGORelation;
        RespawnPool   mRespawnMap;

    private:
        template<typename T>
        void SpawnPool(uint32 pool_id, uint32 db_guid_or_pool_id);

        uint32 max_pool_id;
        typedef std::vector<PoolTemplateData>       PoolTemplateDataMap;
        typedef std::vector<PoolGroup<Creature> >   PoolGroupCreatureMap;
        typedef std::vector<PoolGroup<GameObject> > PoolGroupGameObjectMap;
        typedef std::vector<PoolGroup<Pool> >       PoolGroupPoolMap;
        typedef std::vector<PoolGroup<Quest> >      PoolGroupQuestMap;

        // Vector types for New Pool Spawning
        typedef std::vector<NewPoolGroup>           NewCreatureDataMap;

        PoolTemplateDataMap    mPoolTemplate;
        PoolGroupCreatureMap   mPoolCreatureGroups;
        PoolGroupGameObjectMap mPoolGameobjectGroups;
        PoolGroupPoolMap       mPoolPoolGroups;
        PoolGroupQuestMap      mPoolQuestGroups;
        NewCreatureDataMap     mNewPoolCreatureInfo;
        SearchMap mCreatureSearchMap;
        SearchMap mGameobjectSearchMap;
        SearchMap mPoolSearchMap;
        SearchMap mQuestSearchMap;
        SearchMap mCreatureInfoSearchMap;
        SearchMap mSpawnPointSearchMap;
        SearchMap mNewCreatureSearchMap;

        // dynamic data
        ActivePoolData mSpawnedData;
        NewActivePoolData mNewSpawnedData;
        FreeGuid mFreeGuids;
};

#define sPoolMgr PoolMgr::instance()

inline uint32 PoolMgr::IsPoolCreature(uint32 guid) const
{
    SearchMap::const_iterator itr = mNewCreatureSearchMap.find(guid);
    if (itr != mNewCreatureSearchMap.end())
        return itr->second;

    return 0;
}

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

// Method that tell if the quest is part of another pool and return the pool id if yes
template<>
inline uint32 PoolMgr::IsPartOfAPool<Quest>(uint32 pool_id) const
{
    SearchMap::const_iterator itr = mQuestSearchMap.find(pool_id);
    if (itr != mQuestSearchMap.end())
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
