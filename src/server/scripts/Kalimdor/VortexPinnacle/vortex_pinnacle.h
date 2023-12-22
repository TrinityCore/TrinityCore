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

#ifndef _Vortex_Pinnacle_h__
#define _Vortex_Pinnacle_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "VP";
constexpr char const* VPScriptName = "instance_vortex_pinnacle";

constexpr uint32 const EncounterCount = 3;

enum TotFWDataTypes
{
    // Encounters
    BOSS_GRAND_VIZIER_ERTAN = 0,
    BOSS_ALTAIRUS           = 1,
    BOSS_ASAAD              = 2
};

enum TotFWCreatureIds
{
    // Bosses
    NPC_GRAND_VIZIER_ERTAN  = 43878,
    NPC_ALTAIRUS            = 43873,
    NPC_ASAAD               = 43875
};

template <class AI, class T>
inline AI* GetVortexPinnacleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, VPScriptName);
}

#define RegisterVortexPinnacleCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetVortexPinnacleAI)

#endif // _Vortex_Pinnacle_h__
