/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef THRONE_OF_THE_FOUR_WINDS_H_
#define THRONE_OF_THE_FOUR_WINDS_H_

#include "CreatureAIImpl.h"

#define TotFWScriptName "instance_throne_of_the_four_winds"
#define DataHeader   "TOTFW"

uint32 const EncounterCount = 2;

enum TFWDataTypes
{
    // Encounter States
    DATA_CONCLAVE_OF_WIND               = 0,
    DATA_ALAKIR                         = 1,

    // Additional Data
    DATA_ANSHAL                         = 2,
    DATA_NEZIR                          = 3,
    DATA_ROHASH                         = 4,
    DATA_SKYWALL_RAID_CENTER_PLATFORM   = 5
};

enum TFWCreatureIds
{
    // Bosses
    BOSS_ANSHAL                     = 45870,
    BOSS_NEZIR                      = 45871,
    BOSS_ROHASH                     = 45872,
    BOSS_ALAKIR                     = 46753,

    // Creatures
    NPC_WORLD_TRIGGER               = 21252,
    NPC_FALL_CATCHER                = 45710,
    NPC_RAVENOUS_CREEPER            = 45812,
    NPC_TORNADO                     = 46207,
    NPC_WORLD_TRIGGER_IMMUNE_TO_PC  = 19871,
};

enum TFWGameObjectIds
{
    GO_SKYWALL_RAID_CENTER_PLATFORM = 207737
};

enum TFWSpells
{
};

enum TFWMisc
{
};

template <class AI, class T>
inline AI* GetThroneOfTheFourWindsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotFWScriptName);
}

#define RegisterThroneOfTheFourWindsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheFourWindsAI)

#endif // THRONE_OF_THE_FOUR_WINDS_H_
