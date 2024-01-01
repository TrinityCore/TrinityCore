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

#ifndef _Well_of_Eternity_h__
#define _Well_of_Eternity_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "WOE";
constexpr char const* WoEScriptName = "instance_well_of_eternity";

constexpr uint32 const EncounterCount = 3;

enum WoEDataTypes
{
    // Encounters
    BOSS_PEROTHARN              = 0,
    BOSS_QUEEN_AZSHARA          = 1,
    BOSS_MANNOROTH              = 2
};

enum WoECreatureIds
{
    // Bosses
    NPC_PEROTHARN = 55085
};

template <class AI, class T>
inline AI* GetWellOfEnernityAI(T* obj)
{
    return GetInstanceAI<AI>(obj, WoEScriptName);
}

#define RegisterWellOfEternityCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetWellOfEnernityAI)

#endif // _Well_of_Eternity_h__
