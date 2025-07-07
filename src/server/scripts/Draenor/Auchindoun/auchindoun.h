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

#ifndef _Auchindoun_h__
#define _Auchindoun_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "Auchindoun";
constexpr char const* AuchindounScriptName = "instance_auchindoun";

constexpr uint32 EncounterCount = 4;

enum AuchindounDataTypes
{
    // Encounters
    DATA_VIGILANT_KAATHAR  = 0,
    DATA_SOULBINDER_NYAMI  = 1,
    DATA_AZZAKEL           = 2,
    DATA_TERONGOR          = 3,

    DATA_SOULBINDER_TUULANI,

    // GameObjects
    DATA_HOLY_BARRIER,
};

enum AuchindounCreatureIds
{
    // Bosses
    BOSS_VIGILANT_KAATHAR  = 75839,
    BOSS_SOULBINDER_NYAMI  = 76177,
    BOSS_AZZAKEL           = 75927,
    BOSS_TERONGOR          = 77734,

    NPC_SOULBINDER_TUULANI = 79248
};

enum AuchindounGameobjectIds
{
    GO_HOLY_BARRIER        = 230398
};

template <class AI, class T>
inline AI* GetAuchindounAI(T* obj)
{
    return GetInstanceAI<AI>(obj, AuchindounScriptName);
}

#define RegisterAuchindounCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAuchindounAI)

#endif // _Auchindoun_h__
