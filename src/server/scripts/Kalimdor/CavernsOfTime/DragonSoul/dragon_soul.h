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

#ifndef _Dragon_Soul_h__
#define _Dragon_Soul_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "DS";
constexpr char const* DSScriptName = "instance_dragon_soul";

constexpr uint32 const EncounterCount = 8;

enum DSDataTypes
{
    // Encounters
    BOSS_MORCHOK                = 0,
    BOSS_WARLORD_ZONOZZ         = 1,
    BOSS_YORSAHJ_THE_UNSLEEPING = 2,
    BOSS_HAGARA_THE_STORMBINDER = 3,
    BOSS_ULTRAXION              = 4,
    BOSS_WARMASTER_BLACKHORN    = 5,
    BOSS_SPINE_OF_DEATHWING     = 6,
    BOSS_MADNESS_OF_DEATHWING   = 7
};

enum DSMapObjIds
{
    // Spine of Deathwing
    /*
    * Data Values:
    * 1, 0, 60,  0, 0, 0  -- Talk
    * 1, 0, 213, 0, 0, 0  -- Scream in Agony
    */
    MAP_OBJ_ID_SPINE_OF_DEATHWING_HEAD  = 6574436,

    // Warmaster Blackhorn
    /*
    * Data Values:
    * 1, 1, [(0 - 100)], 0, 0, 0 -- Skybox cloud speed
    */
    MAP_OBJ_ID_SKYFIRE_SKYBOX           = 6858573
};

template <class AI, class T>
inline AI* GetDragonSoulAI(T* obj)
{
    return GetInstanceAI<AI>(obj, DSScriptName);
}

#define RegisterDragonSoulCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDragonSoulAI)

#endif // _Dragon_Soul_h__
