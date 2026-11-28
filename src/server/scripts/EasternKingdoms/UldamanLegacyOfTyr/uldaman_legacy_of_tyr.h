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

#ifndef DEF_ULDAMAN_LEGACY_OF_TYR_H_
#define DEF_ULDAMAN_LEGACY_OF_TYR_H_

#include "CreatureAIImpl.h"

#define ULOTScriptName "instance_uldaman_legacy_of_tyr"
#define DataHeader "UldamanLegacyOfTyr"

uint32 const EncounterCount = 5;

enum UldamanLegacyOfTyrDataTypes
{
    // Encounters
    DATA_THE_LOST_DWARVES = 0,
    DATA_BROMACH,
    DATA_SENTINEL_TALONDRAS,
    DATA_EMBERON,
    DATA_CHRONO_LORD_DEIOS,

    DATA_OLAF,
    DATA_BAELOG,
    DATA_ERIK_THE_SWIFT
};

enum UldamanLegacyOfTyrCreatureIds
{
    // Bosses
    BOSS_OLAF               = 184580,
    BOSS_BAELOG             = 184581,
    BOSS_ERIK_THE_SWIFT     = 184582,
    BOSS_BROMACH            = 184018,
    BOSS_SENTINEL_TALONDRAS = 184124,
    BOSS_EMBERON            = 184422,
    BOSS_CHRONO_LORD_DEIOS  = 184125
};

enum UldamanLegacyOfTyrGameObjectIds
{
    GO_DOOR_START_TALONDRAS = 377366,
    GO_DOOR_EXIT_TALONDRAS  = 376554
};

template <class AI, class T>
inline AI* GetUldamanLegacyOfTyrAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ULOTScriptName);
}

#define RegisterUldamanLegacyOfTyrCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetUldamanLegacyOfTyrAI)

#endif
