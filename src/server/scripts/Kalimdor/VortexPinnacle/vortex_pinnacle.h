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

#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

#include "CreatureAIImpl.h"

#define VPScriptName "instance_vortex_pinnacle"
#define DataHeader "VP"

uint32 const Slipstreams = 13;
uint32 const PrismGroundingFieldPoints = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_GRAND_VIZIER_ERTAN,
    DATA_ALTAIRUS,
    DATA_ASAAD,

    // Additional Data
    DATA_SLIPSTREAM,
    DATA_SLIPSTREAM_1,
    DATA_SLIPSTREAM_2,
    DATA_SLIPSTREAM_3,
    DATA_SLIPSTREAM_4,
    DATA_SLIPSTREAM_5,
    DATA_SLIPSTREAM_6,
    DATA_SLIPSTREAM_7,
    DATA_SLIPSTREAM_8,
    DATA_SLIPSTREAM_9,
    DATA_SLIPSTREAM_10,
    DATA_SLIPSTREAM_11,
};

enum Misc
{
    NPC_GRAND_VIZIER_ERTAN      = 43878,
    NPC_ALTAIRUS                = 43873,
    NPC_ASAAD                   = 43875,

    NPC_SLIPSTREAM              = 45455,
    NPC_SLIPSTREAM_LANDING_ZONE = 45504,

    NPC_HOWLING_GALE            = 45572,

    // Grounding Field
    NPC_GROUNDING_FIELD         = 47085,
    SPELL_BEAM_A                = 87721,
    SPELL_BEAM_B                = 87722,
    SPELL_BEAM_C                = 87723,
    ACTION_GROUNDING_FIELD_TOP  = 1,

    // Skyfall
    ACTION_SKYFALL_STAR_DEAD    = 2,

    // Zephyr
    NPC_ZEPHYR                  = 45991,
    EVENT_SUMMON_ZEPHYRS        = 1,
    PATH_ZEPHYR_SOUTH           = 4599100,
    PATH_ZEPHYR_NORTH           = 4599101,
};

template <class AI, class T>
inline AI* GetVortexPinnacleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, VPScriptName);
}

#define RegisterVortexPinnacleCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetVortexPinnacleAI)

#endif // DEF_VORTEX_PINNACLE_H
