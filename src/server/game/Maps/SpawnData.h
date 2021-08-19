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

#ifndef TRINITY_SPAWNDATA_H
#define TRINITY_SPAWNDATA_H

#include "DBCEnums.h"
#include "Position.h"
#include <vector>

enum SpawnObjectType
{
    SPAWN_TYPE_CREATURE = 0,
    SPAWN_TYPE_GAMEOBJECT = 1,

    SPAWN_TYPE_MAX
};

enum SpawnObjectTypeMask
{
    SPAWN_TYPEMASK_CREATURE = (1 << SPAWN_TYPE_CREATURE),
    SPAWN_TYPEMASK_GAMEOBJECT = (1 << SPAWN_TYPE_GAMEOBJECT),

    SPAWN_TYPEMASK_ALL = (1 << SPAWN_TYPE_MAX)-1
};

enum SpawnGroupFlags
{
    SPAWNGROUP_FLAG_NONE                = 0x00,
    SPAWNGROUP_FLAG_SYSTEM              = 0x01,
    SPAWNGROUP_FLAG_COMPATIBILITY_MODE  = 0x02,
    SPAWNGROUP_FLAG_MANUAL_SPAWN        = 0x04,
    SPAWNGROUP_FLAG_DYNAMIC_SPAWN_RATE  = 0x08,
    SPAWNGROUP_FLAG_ESCORTQUESTNPC      = 0x10,

    SPAWNGROUP_FLAGS_ALL = (SPAWNGROUP_FLAG_SYSTEM | SPAWNGROUP_FLAG_COMPATIBILITY_MODE | SPAWNGROUP_FLAG_MANUAL_SPAWN | SPAWNGROUP_FLAG_DYNAMIC_SPAWN_RATE | SPAWNGROUP_FLAG_ESCORTQUESTNPC)
};

struct SpawnGroupTemplateData
{
    uint32 groupId;
    std::string name;
    uint32 mapId;
    SpawnGroupFlags flags;
};

struct SpawnData
{
    SpawnObjectType const type;
    uint64 spawnId = 0;
    uint32 id = 0; // entry in respective _template table
    WorldLocation spawnPoint;
    uint8 phaseUseFlags = 0;
    uint32 phaseId = 0;
    uint32 phaseGroup = 0;
    int32 terrainSwapMap = -1;
    int32 spawntimesecs = 0;
    std::vector<Difficulty> spawnDifficulties;
    SpawnGroupTemplateData const* spawnGroupData = nullptr;
    uint32 scriptId = 0;
    bool dbData = true;

    protected:
    SpawnData(SpawnObjectType t) : type(t) {}
};

enum LinkedRespawnType
{
    LINKED_RESPAWN_CREATURE_TO_CREATURE  = 0,
    LINKED_RESPAWN_CREATURE_TO_GO        = 1, // Creature is dependant on GameObject
    LINKED_RESPAWN_GO_TO_GO              = 2,
    LINKED_RESPAWN_GO_TO_CREATURE        = 3, // GameObject is dependant on Creature
};

#endif
