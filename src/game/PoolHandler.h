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

#ifndef MANGOS_POOLHANDLER_H
#define MANGOS_POOLHANDLER_H

#include "Platform/Define.h"
#include "Policies/Singleton.h"
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
    bool    spawned;
    PoolObject(uint32 _guid, float _chance): guid(_guid), chance(fabs(_chance)), spawned(false) {}
};

template <class T>
class PoolGroup
{
    public:
        PoolGroup();
        ~PoolGroup() {};
        bool isEmpty() { return ExplicitlyChanced.empty() && EqualChanced.empty(); }
        void AddEntry(PoolObject& poolitem, uint32 maxentries);
        bool CheckPool(void);
        uint32 RollOne(void);
        bool IsSpawnedObject(uint32 guid);
        void DespawnObject(uint32 guid=0);
        void Despawn1Object(uint32 guid);
        void SpawnObject(uint32 limit, bool cache=false);
        bool Spawn1Object(uint32 guid);
        bool ReSpawn1Object(uint32 guid);
        void RemoveOneRelation(uint16 child_pool_id);
    private:
        typedef std::vector<PoolObject> PoolObjectList;
        PoolObjectList ExplicitlyChanced;
        PoolObjectList EqualChanced;
        uint32 m_LastDespawnedNode;                         // Store the guid of the removed creature/gameobject during a pool update
        uint32 m_SpawnedPoolAmount;                         // Used to know the number of spawned objects
};

class Pool                                                  // for Pool of Pool case
{
};

class PoolHandler
{
    public:
        PoolHandler();
        ~PoolHandler() {};
        void LoadFromDB();
        uint16 IsPartOfAPool(uint32 guid, uint32 type);
        bool IsSpawnedObject(uint16 pool_id, uint32 guid, uint32 type);
        bool CheckPool(uint16 pool_id);
        void SpawnPool(uint16 pool_id, bool cache=false);
        void DespawnPool(uint16 pool_id);
        void UpdatePool(uint16 pool_id, uint32 guid, uint32 type);
        void Initialize();

    protected:
        bool m_IsPoolSystemStarted;
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

};

#define poolhandler MaNGOS::Singleton<PoolHandler>::Instance()
#endif
