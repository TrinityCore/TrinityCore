/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LOST_CITY_OF_THE_TOLVIR_H_
#define LOST_CITY_OF_THE_TOLVIR_H_

#define LCTScriptName "instance_lost_city_of_the_tolvir"
#define DataHeader   "LCT"

uint32 const EncounterCount = 4;

enum LCTDataTypes
{
    // Encounter States
    DATA_GENERAL_HUSAM          = 1,
    DATA_LOCKMAW                = 2,
    DATA_AUGH                   = 3,
    DATA_HIGH_PROPHET_BARIM     = 4,
    DATA_SIAMAT                 = 5,

    // Additional Data
    DATA_SIAMAT_PLATFORM        = 6,
    DATA_BLAZE_OF_THE_HEAVENS   = 7,
    DATA_HARBINGER_OF_DARKNESS  = 8,
};

enum LCTCreatureIds
{
    // Bosses
    BOSS_GENERAL_HUSAM              = 44577,
    BOSS_LOCKMAW                    = 43614,
    BOSS_AUGH                       = 49045,
    BOSS_HIGH_PROPHET_BARIM         = 43612,
    BOSS_SIAMAT                     = 44819,

    // Misc
    NPC_BAD_INTENTIONS_TARGET       = 44586,
    NPC_SHOCKWAVE_STALKER           = 44711,
    NPC_SHOCKWAVE_VISUAL            = 44712,
    NPC_TOLVIR_LAND_MINE            = 44796,
    NPC_REPENTANCE                  = 43817,
    NPC_BLAZE_OF_THE_HEAVENS        = 48906,
    NPC_SOUL_FRAGMENT               = 43934,
    NPC_HARBINGER_OF_DARKNESS       = 43927,
};

enum LCTGameObjectIds
{
    GO_SIAMAT_PLATFORM = 205365
};

template<class AI>
AI* GetLostCityOfTheTolvirAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, LCTScriptName);
}

#endif // LOST_CITY_OF_THE_TOLVIR_H_
