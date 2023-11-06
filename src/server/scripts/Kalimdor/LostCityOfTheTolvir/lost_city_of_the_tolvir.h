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

#ifndef LostCityOfTheTolvir_h__
#define LostCityOfTheTolvir_h__

#include "CreatureAIImpl.h"

#define DataHeader "LCT"
#define LCTScriptName "instance_lost_city_of_the_tolvir"

static constexpr uint32 EncounterCount = 4;

enum LCTData
{
    // Encounters
    BOSS_GENERAL_HUSAM      = 0,
    BOSS_LOCKMAW_AND_AUGH   = 1,
    BOSS_HIGH_PROPHET_BARIM = 2,
    BOSS_SIAMAT             = 3,

    DATA_LOCKMAW,
    DATA_AUGH
};

enum LCTCreatureIds
{
    // Bosses
    NPC_GENERAL_HUSAM               = 44577,
    NPC_LOCKMAW                     = 43614,
    NPC_AUGH                        = 49045,
    NPC_HIGH_PROPHET_BARIM          = 43612,
    NPC_SIAMAT                      = 44819,

    // Encounter related creatures
    /*General Husam*/
    NPC_BAD_INTENTIONS_TARGET       = 44586,
    NPC_SHOCKWAVE_STALKER           = 44711,
    NPC_TOLVIR_LAND_MINE_TARGET     = 44840,
    NPC_TOLVIR_LAND_MINE_VEHICLE    = 44798,
    NPC_TOLVIR_LAND_MINE_CASTER     = 44796
};

template <class AI, class T>
inline AI* GetLostCityOfTheTolvirAI(T* obj)
{
    return GetInstanceAI<AI>(obj, LCTScriptName);
}

#define RegisterLostCityOfTheTolvirAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetLostCityOfTheTolvirAI)

#endif // LostCityOfTheTolvir_h__
