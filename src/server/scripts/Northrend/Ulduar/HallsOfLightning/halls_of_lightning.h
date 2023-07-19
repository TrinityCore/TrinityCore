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

#ifndef HALLS_OF_LIGHTNING_H_
#define HALLS_OF_LIGHTNING_H_

#include "CreatureAIImpl.h"

#define HoLScriptName "instance_halls_of_lightning"
#define DataHeader    "HOL"

uint32 const EncounterCount = 4;

enum HOLDataTypes
{
    // Bosses
    DATA_GENERAL_BJARNGRIM  = 0,
    DATA_VOLKHAN            = 1,
    DATA_IONAR              = 2,
    DATA_LOKEN              = 3,

    // Additional Data
    /*General Bjarngrim*/
    DATA_INVISIBLE_STALKER,

    /*Volkhan*/
    DATA_VOLKHAN_TEMPER_VISUAL,
    DATA_VOLKHANS_ANVIL,

    /*Loken*/
    DATA_LOKEN_GLOBE
};

enum HOLCreaturesIds
{
    // Bosses
    NPC_GENERAL_BJARNGRIM       = 28586,
    NPC_VOLKHAN                 = 28587,
    NPC_IONAR                   = 28546,
    NPC_LOKEN                   = 28923,

    /*General Bjarngrim*/
    NPC_INVISIBLE_STALKER       = 30298,

    /*Volkhan*/
    NPC_VOLKHANS_ANVIL          = 28823,
    NPC_MOLTEN_GOLEM            = 28695
};

enum HOLGameObjectIds
{
    GO_BJARNGRIM_DOOR           = 191416,
    GO_VOLKHAN_DOOR             = 191325,
    GO_IONAR_DOOR               = 191326,
    GO_LOKEN_DOOR               = 191324,

    /*Volkhan*/
    GO_VOLKHAN_TEMPER_VISUAL    = 190858,

    /*Loken*/
    GO_LOKEN_THRONE             = 192654
};

template <class AI, class T>
inline AI* GetHallsOfLightningAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HoLScriptName);
}

#define RegisterHallsOfLightningCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfLightningAI)

#endif // HALLS_OF_LIGHTNING_H_
