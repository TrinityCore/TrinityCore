/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_SCHOLOMANCE_H
#define DEF_SCHOLOMANCE_H

#include "CreatureAIImpl.h"

#define ScholomanceScriptName "instance_scholomance"
#define DataHeader "SC"

uint32 const EncounterCount             = 8;

enum SCDataTypes
{
    DATA_DOCTORTHEOLENKRASTINOV         = 0,
    DATA_INSTRUCTORMALICIA              = 1,
    DATA_LADYILLUCIABAROV               = 2,
    DATA_LORDALEXEIBAROV                = 3,
    DATA_LOREKEEPERPOLKELT              = 4,
    DATA_THERAVENIAN                    = 5,
    DATA_DARKMASTERGANDLING             = 6,
    DATA_KIRTONOS                       = 7
};

enum SCCreatureIds
{
    NPC_DARKMASTER_GANDLING             = 1853,
    NPC_BONE_MINION                     = 16119
};

enum SCGameobjectIds
{
    GO_GATE_KIRTONOS                    = 175570,
    GO_GATE_GANDLING                    = 177374,
    GO_GATE_RAVENIAN                    = 177372,
    GO_GATE_THEOLEN                     = 177377,
    GO_GATE_ILLUCIA                     = 177371,
    GO_GATE_MALICIA                     = 177375,
    GO_GATE_BAROV                       = 177373,
    GO_GATE_POLKELT                     = 177376,
    GO_BRAZIER_OF_THE_HERALD            = 175564
};

template <class AI, class T>
inline AI* GetScholomanceAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ScholomanceScriptName);
}

#endif
