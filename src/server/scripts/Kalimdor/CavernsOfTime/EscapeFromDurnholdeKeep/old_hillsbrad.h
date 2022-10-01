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

#ifndef DEF_OLD_HILLSBRAD_H
#define DEF_OLD_HILLSBRAD_H

#include "CreatureAIImpl.h"

#define OHScriptName "instance_old_hillsbrad"
#define DataHeader "OH"

constexpr uint32 OldHillsbradFoothillsBossCount = 3;

enum OHDataTypes
{
    DATA_LIEUTENANT_DRAKE   = 0,
    DATA_CAPTAIN_SKARLOC    = 1,
    DATA_EPOCH_HUNTER       = 2,

    TYPE_BARREL_DIVERSION   = 3,
    TYPE_THRALL_EVENT       = 4,

    DATA_THRALL             = 5,
    DATA_TARETHA            = 6
};

enum OHWorldStateIds
{
    WORLD_STATE_OH              = 2436
};

enum OHThrallEscortStates
{
    OH_ESCORT_PRISON_TO_SKARLOC,
    OH_ESCORT_HORSE_RIDE,
    OH_ESCORT_BARN_TO_TARETHA,
    OH_ESCORT_EPOCH_HUNTER,
    OH_ESCORT_FINISHED,

    OH_ESCORT_DEATH_EVENT           // increment wipe counter
};

template <class AI, class T>
inline AI* GetOldHillsbradAI(T* obj)
{
    return GetInstanceAI<AI>(obj, OHScriptName);
}

#define RegisterOldHillsbradCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetOldHillsbradAI)
#define RegisterOldHillsbradGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetOldHillsbradAI)

#endif
