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

#ifndef DEF_ONYXIAS_LAIR_H
#define DEF_ONYXIAS_LAIR_H

#include "CreatureAIImpl.h"

#define OnyxiaScriptName "instance_onyxias_lair"
#define DataHeader "OL"

uint32 const EncounterCount     = 1;

enum OLDataTypes
{
    DATA_ONYXIA                 = 0,
};

enum OLData32
{
    DATA_ONYXIA_PHASE           = 0,
    DATA_SHE_DEEP_BREATH_MORE   = 1,
    DATA_MANY_WHELPS_COUNT      = 2
};

enum OLData64
{
    DATA_ONYXIA_GUID            = 0,
    DATA_FLOOR_ERUPTION_GUID    = 1
};

enum OLOnyxiaPhases
{
    PHASE_START                 = 1,
    PHASE_BREATH                = 2,
    PHASE_END                   = 3
};

enum OLCreatureIds
{
    NPC_WHELP                   = 11262,
    NPC_LAIRGUARD               = 36561,
    NPC_ONYXIA                  = 10184,
    NPC_TRIGGER                 = 14495
};

enum OLGameObjectIds
{
    GO_WHELP_SPAWNER            = 176510,
    GO_WHELP_EGG                = 176511
};

enum OLAchievementData
{
    ACHIEV_CRITERIA_MANY_WHELPS_10_PLAYER                   = 12565, // Criteria for achievement 4403: Many Whelps! Handle It! (10 player) Hatch 50 eggs in 10s
    ACHIEV_CRITERIA_MANY_WHELPS_25_PLAYER                   = 12568, // Criteria for achievement 4406: Many Whelps! Handle It! (25 player) Hatch 50 eggs in 10s
    ACHIEV_CRITERIA_DEEP_BREATH_10_PLAYER                   = 12566, // Criteria for achievement 4404: She Deep Breaths More (10 player) Everybody evade Deep Breath
    ACHIEV_CRITERIA_DEEP_BREATH_25_PLAYER                   = 12569, // Criteria for achievement 4407: She Deep Breaths More (25 player) Everybody evade Deep Breath
    ACHIEV_TIMED_START_EVENT                                =  6601, // Timed event for achievement 4402, 4005: More Dots! (10, 25 player) 5 min kill
};

template <class AI, class T>
inline AI* GetOnyxiasLairAI(T* obj)
{
    return GetInstanceAI<AI>(obj, OnyxiaScriptName);
}

#define RegisterOnyxiasLairCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetOnyxiasLairAI)

#endif
