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

#include "Pool.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "PoolMgr.h"

Pool::Pool(PoolTemplate const* pool, Map const* map)
    : _template(*pool), _map(map) { }

bool Pool::IsTopLevel() const { return !_template.spawnPool; }

uint32 Pool::GetMaxSpawnsOf(uint32 i) const
{
    if (!(i < _template.members.size()))
        return 0;

    PoolTemplate::Member const& member = _template.members[i];

    if (SpawnData::TypeHasData(member.type))
        return 1;
    else if (member.type == SPAWN_TYPE_POOL)
        return ASSERT_NOTNULL(sPoolMgr->GetPoolTemplate(member.spawnId))->maxSpawnCount;
    else
    {
        ASSERT(false, "Invalid spawn type %u for member %u in Pool::GetMaxSpawnsOf", member.type, i);
        return 0;
    }
}

uint32 Pool::GetMaxSpawns() const { return _template.maxSpawnCount; }

std::pair<SpawnObjectType, ObjectGuid::LowType> Pool::SelectMemberToSpawn()
{
    ASSERT(CanSpawnAny(), "Pool %u asked to spawn a member even though it's already fully spawned. Map info:\n%s", _template.spawnId, _map->GetDebugInfo().c_str());

    PoolTemplate::Member const& toSpawn = *Trinity::Containers::SelectRandomWeightedContainerElement(_template.members, [this](PoolTemplate::Member const& member)
    {
        return CanSpawnMember(member.index) ? member.chance : 0.0;
    });

    ASSERT(CanSpawnMember(toSpawn.index), "Pool %u selected member %u that's already fully spawned.", _template.spawnId, toSpawn.index);
    _currentSpawns.insert(toSpawn.index);
    return { toSpawn.type, toSpawn.spawnId };
}

void Pool::NotifyMemberGone(SpawnObjectType type, ObjectGuid::LowType spawnId)
{
    auto memIt = std::find_if(_template.members.begin(), _template.members.end(), [type, spawnId](PoolTemplate::Member const& member) { return (member.type == type) && (member.spawnId == spawnId); });
    if (memIt == _template.members.end())
    {
        TC_LOG_ERROR("maps", "Pool %u notified that entity with id (%u,%u) is gone, but it does not belong to the pool.", _template.spawnId, uint32(type), spawnId);
        return;
    }

    auto spawnIt = _currentSpawns.find(memIt->index);
    if (spawnIt == _currentSpawns.end())
    {
        TC_LOG_ERROR("maps", "Pool %u notified that entity with id (%u,%u) is gone, but that entity is not currently spawned.", _template.spawnId, uint32(type), spawnId);
        return;
    }
    _currentSpawns.erase(spawnIt);
}
