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

#ifndef DEF_SERPENT_SHRINE_H
#define DEF_SERPENT_SHRINE_H

#include "CreatureAIImpl.h"

#define SSCScriptName "instance_serpent_shrine"
#define DataHeader "SS"

enum SSWaterEventState
{
    WATERSTATE_NONE     = 0,
    WATERSTATE_FRENZY   = 1,
    WATERSTATE_SCALDING = 2
};

enum SSBosses
{
    BOSS_HYDROSS_THE_UNSTABLE   = 0,
    BOSS_THE_LURKER_BELOW       = 1,
    BOSS_LEOTHERAS_THE_BLIND    = 2,
    BOSS_FATHOM_LORD_KARATHRESS = 3,
    BOSS_MOROGRIM_TIDEWALKER    = 4,
    BOSS_LADY_VASHJ             = 5
};

enum SSDataTypes
{
    DATA_CARIBDIS                   = 2,
    DATA_KARATHRESS                 = 3,
    DATA_SHARKKIS                   = 6,
    DATA_THELURKERBELOW             = 11,
    DATA_TIDALVESS                  = 12,
    DATA_LEOTHERAS                  = 14,
    DATA_LEOTHERAS_EVENT_STARTER    = 15,
    DATA_STRANGE_POOL               = 17,
    DATA_WATER                      = 18,
    DATA_TRASH                      = 19,

    DATA_BRIDGE_PART_1,
    DATA_BRIDGE_PART_2,
    DATA_BRIDGE_PART_3,
    DATA_SHIELD_GENERATOR_1,
    DATA_SHIELD_GENERATOR_2,
    DATA_SHIELD_GENERATOR_3,
    DATA_SHIELD_GENERATOR_4
};

enum SSCreatureIds
{
    NPC_LADY_VASHJ                  = 21212
};

enum SSGameObjectIds
{
    GO_BRIDGE_PART_1                = 184203,
    GO_BRIDGE_PART_2                = 184204,
    GO_BRIDGE_PART_3                = 184205,
    GO_SHIELD_GENERATOR_1           = 185051,
    GO_SHIELD_GENERATOR_2           = 185052,
    GO_SHIELD_GENERATOR_3           = 185053,
    GO_SHIELD_GENERATOR_4           = 185054
};

template <class AI, class T>
inline AI* GetSerpentshrineCavernAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SSCScriptName);
}

#define RegisterSerpentshrineCavernCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSerpentshrineCavernAI)
#define RegisterSerpentshrineCavernGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetSerpentshrineCavernAI)

#endif
