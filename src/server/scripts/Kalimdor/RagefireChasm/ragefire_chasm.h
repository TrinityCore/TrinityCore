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

#ifndef _Ragefire_Chasm_h__
#define _Ragefire_Chasm_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "RFC";
constexpr char const* RfCScriptName = "instance_ragefire_chasm";

constexpr uint32 const EncounterCount = 4;

enum RFCDataTypes
{
    // Encounters
    BOSS_ADAROGG               = 0,
    BOSS_DARK_SHAMAN_KORANTHAL = 1,
    BOSS_SLAGMAW               = 2,
    BOSS_LAVA_GUARD_GORDOTH    = 3
};

enum RFCCreatureIds
{
    // Bosses
    NPC_ADAROGG               = 61408,
    NPC_DARK_SHAMAN_KORANTHAL = 61412,
    NPC_SLAGMAW               = 61463,
    NPC_LAVA_GUARD_GORDOTH    = 61528
};

template <class AI, class T>
inline AI* GetRagefireChasmAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RfCScriptName);
}

#define RegisterRagefireChasmCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetRagefireChasmAI)

#endif // _Ragefire_Chasm_h__
