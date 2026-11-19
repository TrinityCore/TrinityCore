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

#ifndef _Grim_Batol_h__
#define _Grim_Batol_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "GB";
constexpr char const* GBTScriptName = "instance_grim_batol";

constexpr uint32 const EncounterCount = 4;

enum GBDataTypes
{
    // Encounters
    BOSS_GENERAL_UMBRISS        = 0,
    BOSS_FORGEMASTER_THRONGUS   = 1,
    BOSS_DRAHGA_SHADOWBURNER    = 2,
    BOSS_ERUDAX                 = 3
};

enum GBCreatureIds
{
    // Bosses
    NPC_GENERAL_UMBRISS         = 39625,
    NPC_FORGEMASTER_THRONGUS    = 40177,
    NPC_DRAHGA_SHADOWBURNER     = 40319,
    NPC_ERUDAX                  = 40484
};

template <class AI, class T>
inline AI* GetGrimBatolAI(T* obj)
{
    return GetInstanceAI<AI>(obj, GBTScriptName);
}

#define RegisterGrimBatolCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetGrimBatolAI)

#endif // _Grim_Batol_h__
