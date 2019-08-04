/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_POOLMGR_H
#define TRINITY_POOLMGR_H

#include "Define.h"
#include "ObjectGuid.h"
#include "SpawnData.h"
#include <unordered_map>

struct PoolTemplate : public SpawnMetadata
{
    struct Member
    {
        uint32 index;
        SpawnObjectType type;
        ObjectGuid::LowType spawnId;
        double chance;
    };

    PoolTemplate(uint32 id) : SpawnMetadata(SPAWN_TYPE_POOL) { spawnId = id; }
    std::vector<Member> members;
    uint32 maxSpawnCount;
};

class TC_GAME_API PoolMgr
{
    private:
        PoolMgr() {}
        ~PoolMgr() {}

    public:
        static PoolMgr* instance();
        void LoadFromDB();

        PoolTemplate const* GetPoolTemplate(uint32 e) const
        {
            auto it = _templates.find(e);
            return (it != _templates.end()) ? &it->second : nullptr;
        }

        std::vector<PoolTemplate const*> GetMapPools(uint32 mapId) const
        {
            std::vector<PoolTemplate const*> v;
            for (auto const& pair : Trinity::Containers::MapEqualRange(_mapToPool, mapId))
                v.emplace_back(pair.second);
            return v;
        }

    private:
        std::unordered_map<uint32, PoolTemplate> _templates;
        std::unordered_multimap<uint32, PoolTemplate const*> _mapToPool;
};

#define sPoolMgr PoolMgr::instance()

#endif
