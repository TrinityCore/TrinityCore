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

#ifndef THRONEOFTHETIDES_H_
#define THRONEOFTHETIDES_H_

#include "CreatureAIImpl.h"

#define TotTScriptName "instance_throne_of_the_tides"
#define DataHeader "TOTT"

uint32 const EncounterCount = 4;

enum TotTDataTypes
{
    // Encounters
    DATA_LADY_NAZJAR        = 0,
    DATA_COMMANDER_ULTHOK   = 1,
    DATA_MINDBENDER_GURSHA  = 2,
    DATA_OZUMAT             = 3
};

enum TotTCreatureIds
{
    // Bosses
    BOSS_LADY_NAZJAR        = 40586,
    BOSS_COMMANDER_ULTHOK   = 40765,
    BOSS_MINDBENDER_GURSHA  = 40788,
    BOSS_OZUMAT             = 40655,

    // Event Creatures
    NPC_OZUMAT_VEHICLE_BIG  = 45030,
    NPC_OZUMAT_VEHICLE      = 44581
};

template <class AI, class T>
inline AI* GetThroneOfTheTodesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotTScriptName);
}

#define RegisterThroneOfTheTidesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheTodesAI)

#endif // THRONEOFTHETIDES_H_
