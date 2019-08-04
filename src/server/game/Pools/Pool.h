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

#ifndef TRINITY_POOL_H
#define TRINITY_POOL_H

#include "Define.h"
#include "ObjectGuid.h"
#include "SpawnData.h"
#include <unordered_set>
#include <utility>

class Map;
struct PoolTemplate;

class TC_GAME_API Pool
{
    public:
        Pool(PoolTemplate const* pool, Map const* map);

        bool IsTopLevel() const;
        bool CanSpawnAny() const { return GetCurrentSpawns() < GetMaxSpawns(); }
        bool CanSpawnMember(uint32 i) const { return GetCurrentSpawnsOf(i) < GetMaxSpawnsOf(i); }

        uint32 GetCurrentSpawnsOf(uint32 i) const { return uint32(_currentSpawns.count(i)); }
        uint32 GetMaxSpawnsOf(uint32 i) const;

        uint32 GetCurrentSpawns() const { return uint32(_currentSpawns.size()); }
        uint32 GetMaxSpawns() const;

    private:
        std::pair<SpawnObjectType, ObjectGuid::LowType> SelectMemberToSpawn();
        void NotifyMemberGone(SpawnObjectType type, ObjectGuid::LowType spawnId);

        PoolTemplate const& _template;
        Map const* const _map;
        std::unordered_set<uint32> _currentSpawns;

    friend class Map;
};

#endif
