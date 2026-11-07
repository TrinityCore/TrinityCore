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

#ifndef _Throne_of_the_Four_Winds_h__
#define _Throne_of_the_Four_Winds_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "TFW";
constexpr char const* TotFWScriptName = "instance_throne_of_the_four_winds";

constexpr uint32 const EncounterCount = 2;

enum TotFWDataTypes
{
    // Encounters
    BOSS_CONCLAVE_OF_WIND   = 0,
    BOSS_ALAKIR             = 1
};

enum TotFWCreatureIds
{
    // Bosses
    NPC_ANSHAL  = 45870,
    NPC_NEZIR   = 45871,
    NPC_ROHASH  = 45872,
    NPC_ALAKIR  = 46753
};

template <class AI, class T>
inline AI* GetThroneOfTheFourWindsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotFWScriptName);
}

#define RegisterThroneOfTheFourWindsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheFourWindsAI)

#endif // _Throne_of_the_Four_Winds_h__
