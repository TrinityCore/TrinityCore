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

#ifndef _Shrine_Of_The_Storm_h__
#define _Shrine_Of_The_Storm_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "SOTS";
constexpr char const* ShrineOfTheStormScriptName = "instance_shrine_of_the_storm";

constexpr uint32 const EncounterCount = 4;

enum ShrineOfTheStormDataTypes
{
    // Encounters
    DATA_AQUSIRR                = 0,
    DATA_TIDESAGE_COUNCIL       = 1,
    DATA_LORD_STORMSONG         = 2,
    DATA_VOLZITH_THE_WHISPERER  = 3,

    DATA_BROTHER_IRONHULL,
    DATA_GALECALLER_FAYE
};

enum ShrineOfTheStormCreatureIds
{
    // Bosses
    BOSS_AQUSIRR                    = 134056,
    BOSS_BROTHER_IRONHULL           = 134063,
    BOSS_GALECALLER_FAYE            = 134058,
    BOSS_LORD_STORMSONG             = 134060,
    BOSS_VOLZITH_THE_WHISPERER      = 134069,

    NPC_LORD_SONGSTORM_AQUSIRR      = 139737,
    NPC_SHRINE_OF_THE_STORM_DUMMY   = 139986,
    NPC_GRASPING_TENTACLE           = 134612,
    NPC_AQUALING                    = 134828,
};

template <class AI, class T>
inline AI* GetShrineOfTheStormAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ShrineOfTheStormScriptName);
}

#define RegisterShrineOfTheStormCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetShrineOfTheStormAI)

#endif // _Shrine_Of_The_Storm_h__
