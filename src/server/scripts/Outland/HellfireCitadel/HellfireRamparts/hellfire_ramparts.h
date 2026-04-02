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

#ifndef DEF_RAMPARTS_H
#define DEF_RAMPARTS_H

#include "CreatureAIImpl.h"

#define HRScriptName "instance_ramparts"
#define DataHeader "HR"

uint32 constexpr EncounterCount   = 3;

enum HRDataTypes
{
    DATA_WATCHKEEPER_GARGOLMAR    = 0,
    DATA_OMOR_THE_UNSCARRED       = 1,
    DATA_VAZRUDEN_THE_HERALD      = 2,

    DATA_VAZRUDEN,
    DATA_FEL_IRON_CHEST
};

enum HRCreatureIds
{
    NPC_HELLFIRE_SENTRY           = 17517,
    NPC_VAZRUDEN_HERALD           = 17307,
    NPC_NAZAN                     = 17536,
    NPC_VAZRUDEN                  = 17537
};

enum HRGameobjectIds
{
    GO_FEL_IRON_CHEST_NORMAL      = 185168,
    GO_FEL_IRON_CHEST_HEROIC      = 185169
};

enum HRActionIds
{
    ACTION_START_ENCOUNTER        = 1730700
};

enum HRSpawnGroups
{
    SPAWN_GROUP_VAZRUDEN          = 357,
    SPAWN_GROUP_HELLFIRE_SENTRY_1 = 358,
    SPAWN_GROUP_HELLFIRE_SENTRY_2 = 359
};

enum HREventsIds
{
    EVENT_RESET_VAZRUDEN          = 1
};

template <class AI, class T>
inline AI* GetHellfireRampartsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HRScriptName);
}

#define RegisterHellfireRampartsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHellfireRampartsAI)
#define RegisterHellfireRampartsGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetHellfireRampartsAI)

#endif
