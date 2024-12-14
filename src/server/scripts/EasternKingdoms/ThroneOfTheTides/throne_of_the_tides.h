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

#ifndef _Throne_of_the_Tides_h__
#define _Throne_of_the_Tides_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "TOTT";
constexpr char const* TotTScriptName = "instance_throne_of_the_tides";

constexpr uint32 const EncounterCount = 4;

enum TotTDataTypes
{
    // Encounters
    BOSS_LADY_NAZJAR        = 0,
    BOSS_COMMANDER_ULTHOK   = 1,
    BOSS_MINDBENDER_GURSHA  = 2,
    BOSS_OZUMAT             = 3,

    /*Ozumat*/
    DATA_OZUMAT
};

enum TotTCreatureIds
{
    // Bosses
    NPC_LADY_NAZJAR         = 40586,
    NPC_COMMANDER_ULTHOK    = 40765,
    NPC_MINDBENDER_GURSHA   = 40788,
    NPC_OZUMAT              = 44566
};

enum TotTGameObjectIds
{
    GO_DOODAD_ABYSSAL_MAW_DOOR_1    = 204338,
    GO_DOODAD_ABYSSAL_MAW_DOOR_2    = 204339,
    GO_DOODAD_ABYSSAL_MAW_DOOR_4    = 204341
};

template <class AI, class T>
inline AI* GetThroneOfTheTidesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotTScriptName);
}

#define RegisterThroneOfTheTidesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheTidesAI)

#endif // _Throne_of_the_Tides_h__
