/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_MAW_OF_SOULS_H
#define DEF_MAW_OF_SOULS_H

#include "Map.h"
#include "Creature.h"
#include "ObjectMgr.h"

#define DataHeader "MOS"
#define MOSScriptName "instance_maw_of_souls"

uint32 const EncounterCount = 3;

enum MOSDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_YMIRON = 1,
    DATA_HARBARON = 2,
    DATA_HELYA = 3,
};

enum MOSCreatureIds
{
    // NPCs
    BOSS_YMIRON_FALLEN = 96756,
    BOSS_HARBARON      = 96754,
    NPC_SKJAL_MAW      = 99307,
    BOSS_HELYA         = 96759,

    // Triggers
};

enum MOSGameObjectsIds
{
    GO_HORN_OF_DAMMED  = 247041,
    GO_WALL_OF_SOULS   = 246947,
    GO_WALL_OF_SOULS_2 = 246948,
    GO_COLLISION_WALL  = 243403,
    GO_MURKY_FOG       = 265476,
    GO_WALL_OF_SOULS_3 = 246435,
    GO_TRAP_DOOR_01    = 246840,
    GO_TRAP_DOOR_02    = 246842,
    GO_TRAP_DOOR_03    = 246843,
    GO_TRAP_DOOR_04    = 246844,
    GO_TRAP_DOOR_05    = 246839,
    GO_TRAP_DOOR_06    = 246838,
    GO_TRAP_DOOR_07    = 246834,
    GO_TRAP_DOOR_09    = 246835,
    GO_TRAP_DOOR_10    = 246837,
    GO_TRAP_DOOR_11    = 246841,
    GO_NAGLFAR         = 246919,
};

template<class AI>
AI* GetMawOfSoulsAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, MOSScriptName);
}

using SpellTargets = std::list<WorldObject*>;

struct PlayerFilter
{
    bool operator() (WorldObject*& target)
    {
        if (target->ToPlayer())
            return false;

        return true;
    }
};

#endif
