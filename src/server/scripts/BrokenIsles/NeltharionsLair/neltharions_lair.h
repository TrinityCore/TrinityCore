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

#ifndef DEF_NELTHARIONS_LAIR_H_
#define DEF_NELTHARIONS_LAIR_H_

#include "CreatureAIImpl.h"

#define DataHeader "NeltharionsLair"
#define NLScriptName "instance_neltharions_lair"

constexpr uint32 EncounterCount = 4;

enum NLDataTypes : uint8
{
    // Encounters
    DATA_ROKMORA = 0,
    DATA_ULAROGG_CRAGSHAPER,
    DATA_NARAXAS,
    DATA_DARGRUL_THE_UNDERKING,

    DATA_ROKMORA_INTRO_STATE
};

enum NLCreatureIds
{
    // Bosses
    BOSS_ROKMORA               = 91003,
    BOSS_ULAROGG_CRAGSHAPER    = 91004,
    BOSS_NARAXAS               = 91005,
    BOSS_DARGRUL_THE_UNDERKING = 91007
};

enum NLGameObjects
{
    GO_MYSTIC_BARRIER = 248871
};

template <class AI, class T>
inline AI* GetNeltharionsLairAI(T* obj)
{
    return GetInstanceAI<AI>(obj, NLScriptName);
}

#define RegisterNeltharionsLairCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetNeltharionsLairAI)

#endif
