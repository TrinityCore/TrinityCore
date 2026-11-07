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

#ifndef _Deadmines_h__
#define _Deadmines_h__

#include "CreatureAIImpl.h"

constexpr char const* DMScriptName = "instance_deadmines";
constexpr char const* DataHeader = "DM";

constexpr uint32 const EncounterCount = 6;

enum DMDataTypes
{
    // Encounters
    BOSS_GLUBTOK            = 0,
    BOSS_HELIX_GEARBREAKER  = 1,
    BOSS_FOE_REAPER_5000    = 2,
    BOSS_ADMIRAL_RIPSNARL   = 3,
    BOSS_CAPTAIN_COOKIE     = 4,
    BOSS_VANESSA_VANCLEEF   = 5
};

enum DMCreatureIds
{
    // Bosses
    NPC_GLUBTOK             = 47162,
    NPC_HELIX_GEARBREAKER   = 47296,
    NPC_FOE_REAPER_5000     = 43778,
    NPC_ADMIRAL_RIPSNARL    = 47626,
    NPC_CAPTAIN_COOKIE      = 47739,
    NPC_VANESSA_VAN_CLEEF   = 49541
};

enum DMGameObjectIds
{
    GO_FACTORY_DOOR     = 13965,
    GO_IRON_CLAD_DOOR   = 16397,
    GO_DEFIAS_CANNON    = 16398,
    GO_DOOR_LEVER       = 101833,
    GO_MAST_ROOM_DOOR   = 16400,
    GO_HEAVY_DOOR       = 17153,
    GO_FOUNDRY_DOOR     = 16399
};

template <class AI, class T>
inline AI* GetDeadminesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, DMScriptName);
}

#endif // _Deadmines_h__
