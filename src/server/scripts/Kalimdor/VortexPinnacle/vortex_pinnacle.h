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

#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

#include "CreatureAIImpl.h"

#define VPScriptName "instance_vortex_pinnacle"
#define DataHeader "VP"

uint32 const PrismGroundingFieldPoints = 3;

enum DataTypes
{
    // Encounter Data
    DATA_GRAND_VIZIER_ERTAN = 0,
    DATA_ALTAIRUS,
    DATA_ASAAD,

    // Additional Data
    DATA_SLIPSTREAM_ERTAN_1,
    DATA_SLIPSTREAM_ERTAN_2,
    DATA_SLIPSTREAM_ERTAN_3,

    DATA_SLIPSTREAM_ALTAIRUS_1,
    DATA_SLIPSTREAM_ALTAIRUS_2,
    DATA_SLIPSTREAM_ALTAIRUS_3,
    DATA_SLIPSTREAM_ALTAIRUS_4,
    DATA_SLIPSTREAM_ALTAIRUS_5,

    DATA_SLIPSTREAM_ASAAD_1,
    DATA_SLIPSTREAM_ENTRANCE_1,
    DATA_SLIPSTREAM_ENTRANCE_2,

    DATA_COLLECTED_GOLDEN_ORB
};

enum VPCreatureIds
{
    // Bosses
    BOSS_GRAND_VIZIER_ERTAN     = 43878,
    BOSS_ALTAIRUS               = 43873,
    BOSS_ASAAD                  = 43875,

    // Encounter Related Data
    /*Grandvizier Ertan*/
    NPC_ERTANS_VORTEX           = 46007,

    /*Altairus*/
    NPC_INVISIBLE_STALKER       = 42844,
    NPC_AIR_CURRENT             = 47305,
    NPC_TWISTER                 = 47342,

    /*Instance Events*/
    NPC_SLIPSTREAM              = 45455,
    NPC_SLIPSTREAM_LANDING_ZONE = 45504,
    NPC_HOWLING_GALE            = 45572,
    NPC_ZEPHYR                  = 45991,
    NPC_SKYFALL                 = 45981,
    NPC_SKYFALL_STAR            = 52019,
    NPC_GOLDEN_ORB              = 51157,

    // Grounding Field
    NPC_GROUNDING_FIELD         = 47085,
};

enum VPSpells
{
    SPELL_BEAM_A                = 87721,
    SPELL_BEAM_B                = 87722,
    SPELL_BEAM_C                = 87723,
    SPELL_ACHIEVEMENT_CHECK     = 94756
};

enum VPActions
{
    ACTION_GROUNDING_FIELD_TOP  = 1,
    ACTION_SKYFALL_STAR_DEAD    = 2
};

enum VPMisc
{
    PATH_ZEPHYR_SOUTH   = 4599100,
    PATH_ZEPHYR_NORTH   = 4599101
};

enum VPWorldStates
{
    WS_GOLDEN_ORBS_COLLECTED = 5649
};

template <class AI, class T>
inline AI* GetVortexPinnacleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, VPScriptName);
}

#define RegisterVortexPinnacleCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetVortexPinnacleAI)

#endif // DEF_VORTEX_PINNACLE_H
