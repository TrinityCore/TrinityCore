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

#ifndef DEF_HALLS_OF_INFUSION_H_
#define DEF_HALLS_OF_INFUSION_H_

#include "CreatureAIImpl.h"

#define HOFScriptName "instance_halls_of_infusion"
#define DataHeader "HallsOfInfusion"

uint32 const EncounterCount = 4;

enum HallsOfInfusionDataTypes
{
    // Encounters
    DATA_WATCHER_IRIDEUS       = 0,
    DATA_GULPING_GOLIATH       = 1,
    DATA_KHAJIN_THE_UNYIELDING = 2,
    DATA_PRIMAL_TSUNAMI        = 3
};

enum HallsOfInfusionCreatureIds
{
    // Bosses
    BOSS_WATCHER_IRIDEUS       = 189719,
    BOSS_GULPING_GOLIATH       = 189722,
    BOSS_KHAJIN_THE_UNYIELDING = 189727,
    BOSS_PRIMAL_TSUNAMI        = 189729
};

enum HallsOfInfusionGameObjectIds
{
    GO_WATCHER_IRIDEUS_DOOR1 = 379303,
    GO_WATCHER_IRIDEUS_DOOR2 = 379304
};

template <class AI, class T>
inline AI* GetHallsOfInfusionAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HOFScriptName);
}

#define RegisterHallsOfInfusionCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfInfusionAI)

#endif
