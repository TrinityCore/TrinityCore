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

#ifndef SCARLET_M_
#define SCARLET_M_

#include "CreatureAIImpl.h"

#define SMScriptName "instance_scarlet_monastery"
#define DataHeader "SM"

uint32 const EncounterCount = 10;

enum SMDataTypes
{
    DATA_INTERROGATOR_VISHAS = 0,
    DATA_BLOODMAGE_THALNOS,
    DATA_HOUNDMASTER_LOKSEY,
    DATA_ARCANIST_DOAN,
    DATA_HEROD,
    DATA_HIGH_INQUISITOR_FAIRBANKS,
    DATA_MOGRAINE_AND_WHITE_EVENT, // Last DungeonEncounter.dbc entry

    DATA_AZSHIR,
    DATA_SCORN,
    DATA_HORSEMAN_EVENT, // Last defined encounter

    DATA_HEAD,
    DATA_HORSEMAN,
    DATA_MOGRAINE,
    DATA_VORREL,
    DATA_WHITEMANE,

    DATA_PUMPKIN_SHRINE,
    DATA_HIGH_INQUISITORS_DOOR,
};

enum SMCreatureIds
{
    NPC_MOGRAINE = 3976,
    NPC_WHITEMANE = 3977,
    NPC_VORREL = 3981,
    NPC_HORSEMAN = 23682,
    NPC_HEAD = 23775,
    NPC_PUMPKIN = 23694
};

enum SMGameObjectIds
{
    GO_HIGH_INQUISITORS_DOOR = 104600,
    GO_PUMPKIN_SHRINE = 186267
};

template <class AI, class T>
inline AI* GetScarletMonasteryAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SMScriptName);
}

#define RegisterScarletMonasteryCreatureAI(ai) RegisterCreatureAIWithFactory(ai, GetScarletMonasteryAI)
#define RegisterScarletMonasteryGameObjectAI(ai) RegisterGameObjectAIWithFactory(ai, GetScarletMonasteryAI)

#endif // SCARLET_M_
