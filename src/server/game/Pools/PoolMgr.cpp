/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"

/*static*/ PoolMgr* PoolMgr::instance()
{
    static PoolMgr instance;
    return &instance;
}

void PoolMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    _mapToPool.clear();
    _templates.clear();

    QueryResult result = WorldDatabase.Query("SELECT m.type, m.spawnId, p.entry, m.chance, p.max_limit FROM pool_members m LEFT JOIN pool_template p ON m.poolSpawnId = p.entry");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spawn pools. DB table `pool_members` is empty.");
        return;
    }

    // step 1: building template map
    uint32 c = 0;
    do
    {
        Field* fields = result->Fetch();

        SpawnObjectType type            = SpawnObjectType(fields[0].GetUInt16());
        ObjectGuid::LowType spawnId     = fields[1].GetUInt32();
        ObjectGuid::LowType poolSpawnId = fields[2].GetUInt32();
        double chance                   = fields[3].GetDouble();
        uint32 maxSpawns                = fields[4].GetUInt32();

        if (!chance)
        {
            TC_LOG_ERROR("sql.sql", "Table `pool_members` contains pool member (%u,%u) of pool %u with chance 0.0. Chance must be nonzero - adjusted to 1.0.", uint32(type), spawnId, poolSpawnId);
            chance = 1.0;
        }

        auto pair = _templates.emplace(poolSpawnId, poolSpawnId);
        PoolTemplate& pool = pair.first->second;
        if (pair.second) // this is a new pool
        {
            pool.maxSpawnCount = maxSpawns;
            pool.spawnGroupData = sObjectMgr->GetDefaultSpawnGroup();
        }

        pool.members.emplace_back();
        PoolTemplate::Member& member = pool.members.back();
        member.type = type;
        member.spawnId = spawnId;
        member.chance = chance;
        member.index = (pool.members.size()-1);

        ++c;
    } while (result->NextRow());

    // don't touch the template map after this point (pointers would become invalidated!)

    std::vector<PoolTemplate*> leafPools;
    // step 2: building member -> pool lookup table, looking for leaf pools and sanity checking mapids
    for (auto& pair : _templates)
    {
        PoolTemplate& pool = pair.second;
        bool isLeafPool = true;
        uint32 nMemberSpawns = 0;
        for (auto it = pool.members.begin(); it != pool.members.end();)
        {
            if (!SpawnData::TypeIsValid(it->type))
            {
                TC_LOG_ERROR("sql.sql", "Table `pool_members` contains spawnid (%u,%u) with invalid type in pool %u. Skipped.", uint32(it->type), it->spawnId, pool.spawnId);
                continue;
            }

            SpawnMetadata const* spawn = sObjectMgr->GetSpawnMetadata(it->type, it->spawnId);
            if (!spawn) // spawn data existance
            {
                TC_LOG_ERROR("sql.sql", "Table `pool_members` assigns nonexistant spawnid (%u,%u) to pool %u. Skipped.", uint32(it->type), it->spawnId, pool.spawnId);
                it = pool.members.erase(it);
                continue;
            }

            if (spawn->spawnPool) // each member can only be in one pool
            {
                TC_LOG_ERROR("sql.sql", "Table `pool_members` assigns spawnid (%u,%u) to pool %u, but it is already a member of pool %u. Skipped.", uint32(it->type), it->spawnId, pool.spawnId, spawn->spawnPool.data->spawnId);
                it = pool.members.erase(it);
                continue;
            }

            const_cast<SpawnMetadata*>(spawn)->spawnPool = { &pool, it->index };
            
            if (SpawnData::TypeHasData(it->type))
            {
                uint32 const mapId = spawn->mapId;
                if (pool.mapId == MAPID_INVALID)
                {
                    pool.mapId = mapId;
                    _mapToPool.emplace(mapId, &pool);
                }
                else if (pool.mapId != mapId) // mapid consistency
                {
                    TC_LOG_ERROR("sql.sql", "Table `pool_members` assigns spawnid (%u,%u) on map %u to pool %u on map %u. Skipped.", uint32(it->type), it->spawnId, mapId, pool.spawnId, pool.mapId);
                    it = pool.members.erase(it);
                    continue;
                }
                nMemberSpawns += 1;
            }
            else if (it->type == SPAWN_TYPE_POOL)
            {
                nMemberSpawns += static_cast<PoolTemplate const*>(spawn)->maxSpawnCount;
                isLeafPool = false;
            }
            ++it;
        }

        if (nMemberSpawns < pool.maxSpawnCount)
        {
            TC_LOG_ERROR("sql.sql", "Table `pool_template` specifies a maximum of %u spawns for pool %u, but its members are only capable of spawning %u spawns. Spawn limit reduced.\nNote that this might hide recursive errors, which we are NOT going to bother finding for you.", pool.maxSpawnCount, pool.spawnId, nMemberSpawns);
            pool.maxSpawnCount = nMemberSpawns;
        }

        if (isLeafPool)
            leafPools.emplace_back(&pool);
    }

    // step 3: check for cycles in the pool tree, and build our mapid -> pool lookup table
    for (PoolTemplate* pool : leafPools)
    {
        uint32 const thisMapId = pool->mapId;
        PoolTemplate const* pool1 = pool;
        PoolTemplate const* pool1i;
        PoolTemplate const* pool2 = pool;
        while (1)
        {
            // pool1 steps up twice, pool2 steps up once
            // if there is a cycle, they will coincide after a finite number of steps
            // if there is no cycle, poolId1 will be zero after it hits the top of the tree we're in
            pool2 = pool2->spawnPool.data;

            pool1i = pool1->spawnPool.data;
            if (!pool1i)
                break;

            if (pool1i->mapId == MAPID_INVALID)
            {
                const_cast<PoolTemplate*>(pool1i)->mapId = thisMapId;
                _mapToPool.emplace(thisMapId, pool1i);
            }
            else if (pool1i->mapId != thisMapId) // mapid consistency on half step
            {
                TC_LOG_FATAL("sql.sql", "Table `pool_members` assigns pool %u (in mapid %u) to pool %u (in mapid %u). Go fix that yourself, we're not in the business of untangling your trees for you.", pool1->spawnId, thisMapId, pool1i->spawnId, pool1i->mapId);
                ABORT();
            }

            pool1 = pool1i->spawnPool.data;
            if (!pool1)
                break;

            if (pool1->mapId == MAPID_INVALID)
            {
                const_cast<PoolTemplate*>(pool1)->mapId = thisMapId;
                _mapToPool.emplace(thisMapId, pool1);
            }
            else if (pool1->mapId != thisMapId) // mapid consistency on full step
            {
                TC_LOG_FATAL("sql.sql", "Table `pool_members` assigns pool %u (in mapid %u) to pool %u (in mapid %u). Go fix that yourself, we don't add complex logic just so you can be lazy.", pool1i->spawnId, thisMapId, pool1->spawnId, pool1->mapId);
                ABORT();
            }

            if (pool1 == pool2) // cycle detection
            {
                TC_LOG_FATAL("sql.sql", "Table `pool_members` assigns pool %u to pool %u, forming a cycle. You didn't really think we'd implement a cycle-removal algorithm just so your broken DB works? Go fix it!", pool1i->spawnId, pool1->spawnId);
                ABORT();
            }
        }
    }

    // step 4: output
    TC_LOG_INFO("server.loading", ">> Loaded %u spawn pools (containing %u spawns) in %u ms", _templates.size(), c, GetMSTimeDiffToNow(oldMSTime));
}
