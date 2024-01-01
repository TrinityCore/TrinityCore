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

#ifndef _End_Time_h__
#define _End_Time_h__

#include "CreatureAIImpl.h"

constexpr char const* DataHeader = "ET";
constexpr char const* ETScriptName = "instance_end_time";

constexpr uint32 const EncounterCount = 5;

enum ETWDataTypes
{
    // Encounters
    BOSS_ECHO_OF_BAINE      = 0,
    BOSS_ECHO_OF_SYLVANAS   = 1,
    BOSS_ECHO_OF_JAINA      = 2,
    BOSS_ECHO_OF_TYRANDE    = 3,
    BOSS_MUROZOND           = 4
};

enum ETCreatureIds
{
    // Bosses
    NPC_MUROZOND            = 54432
};

template <class AI, class T>
inline AI* GetEndTimeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ETScriptName);
}

#define RegisterEndTimeCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetEndTimeAI)

#endif // _End_Time_h__
