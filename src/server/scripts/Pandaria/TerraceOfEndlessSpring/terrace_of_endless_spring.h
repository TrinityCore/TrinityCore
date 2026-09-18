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

#ifndef DEF_TERRACE_OF_ENDLESS_SPRING_H_
#define DEF_TERRACE_OF_ENDLESS_SPRING_H_

#include "CreatureAIImpl.h"

#define TOESScriptName "instance_terrace_of_endless_spring"
#define DataHeader "TOES"

uint32 const EncounterCount = 4;

enum TOESDataTypes
{
    // Encounters
    DATA_PROTECTORS_OF_THE_ENDLESS = 0,
    DATA_TSULONG,
    DATA_LEI_SHI,
    DATA_SHA_OF_FEAR,

    // Protectors of the Endless Additional Data
    DATA_PROTECTOR_KAOLAN,
    DATA_ELDER_REGAIL,
    DATA_ELDER_ASANI,

    DATA_PROTECTORS_INTRO_STATE
};

enum TOESCreatureIds
{
    // Bosses
    BOSS_PROTECTOR_KAOLAN           = 60583,
    BOSS_ELDER_REGAIL               = 60585,
    BOSS_ELDER_ASANI                = 60586,
    BOSS_TSULONG                    = 62442,
    BOSS_LEI_SHI                    = 62983,
    BOSS_SHA_OF_FEAR                = 60999,

    NPC_CORRUPTION_DUMMY            = 63420
};

enum TOESSharedActions
{
    ACTION_PROTECTORS_INTRO         = 1
};

template <class AI, class T>
inline AI* GetTerraceOfEndlessSpringAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TOESScriptName);
}

#define RegisterTerraceOfEndlessSpringCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTerraceOfEndlessSpringAI)

#endif
