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

#ifndef _Blackwing_Descent_h__
#define _Blackwing_Descent_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "BWD";
constexpr char const* BWDScriptName = "instance_blackwing_descent";

constexpr uint32 const EncounterCount = 6;

enum BwdDataTypes
{
    // Encounters
    BOSS_MAGMAW                     = 0,
    BOSS_OMNOTRON_DEFENSE_SYSTEM    = 1,
    BOSS_CHIMAERON                  = 2,
    BOSS_ATRAMEDES                  = 3,
    BOSS_MALORIAK                   = 4,
    BOSS_NEFARIANS_END              = 5
};

enum BWDCreatureIds
{
    // Bosses
    NPC_MAGMAW      = 41570,
    NPC_CHIMAERON   = 43296,
    NPC_ATRAMEDES   = 41442,
    NPC_MALORIAK    = 41378,
    NPC_NEFARIAN    = 41376
};

enum BWDGameObjectIds
{
    GO_INNER_CHAMBER_DOOR   = 205830,
    GO_ATHENAEUM_DOOR       = 208291
};

template <class AI, class T>
inline AI* GetBlackwingDescentAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BWDScriptName);
}

#define RegisterBlackwingDescentCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackwingDescentAI)

#endif // _Blackwing_Descent_h__
