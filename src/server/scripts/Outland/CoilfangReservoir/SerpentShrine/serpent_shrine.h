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
    DATA_CANSTARTPHASE3             = 1,
    DATA_CARIBDIS                   = 2,
    DATA_KARATHRESS                 = 3,
    DATA_KARATHRESSEVENT_STARTER    = 4,
    DATA_LADYVASHJ                  = 5,
    DATA_SHARKKIS                   = 6,
    DATA_SHIELDGENERATOR1           = 7,
    DATA_SHIELDGENERATOR2           = 8,
    DATA_SHIELDGENERATOR3           = 9,
    DATA_SHIELDGENERATOR4           = 10,
    DATA_THELURKERBELOW             = 11,
    DATA_TIDALVESS                  = 12,
    DATA_FATHOMLORDKARATHRESSEVENT  = 13,
    DATA_LEOTHERAS                  = 14,
    DATA_LEOTHERAS_EVENT_STARTER    = 15,
    DATA_CONTROL_CONSOLE            = 16,
    DATA_STRANGE_POOL               = 17,
    DATA_WATER                      = 18,
    DATA_TRASH                      = 19,
};

template <class AI, class T>
inline AI* GetSerpentshrineCavernAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SSCScriptName);
}

#define RegisterSerpentshrineCavernCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSerpentshrineCavernAI)
#define RegisterSerpentshrineCavernGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetSerpentshrineCavernAI)

#endif
