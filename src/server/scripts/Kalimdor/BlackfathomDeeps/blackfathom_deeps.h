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

#ifndef BFD_H_
#define BFD_H_

#include "CreatureAIImpl.h"

#define BFDScriptName "instance_blackfathom_deeps"
#define DataHeader "BFD"

uint32 const EncounterCount = 3;

enum BFDData64
{
    DATA_SHRINE1,
    DATA_SHRINE2,
    DATA_SHRINE3,
    DATA_SHRINE4,
    DATA_TWILIGHT_LORD_KELRIS,
    DATA_SHRINE_OF_GELIHAST,
    DATA_ALTAR_OF_THE_DEEPS,
    DATA_MAINDOOR,
};

enum BFDData
{
    DATA_GELIHAST,
    DATA_KELRIS,
    DATA_AKU_MAI,
    DATA_FIRE,
    DATA_EVENT
};

enum BFDCreatureIds
{
    NPC_TWILIGHT_LORD_KELRIS                               = 4832,
    NPC_LORGUS_JETT                                        = 12902,

    NPC_AKU_MAI_SNAPJAW                                    = 4825,
    NPC_MURKSHALLOW_SOFTSHELL                              = 4977,
    NPC_AKU_MAI_SERVANT                                    = 4978,
    NPC_BARBED_CRUSTACEAN                                  = 4823,

    NPC_MORRIDUNE                                          = 6729
};

enum BFDGameObjectIds
{
    GO_SHRINE_OF_GELIHAST                                  = 103015,
    GO_FIRE_OF_AKU_MAI_1                                   = 21118,
    GO_FIRE_OF_AKU_MAI_2                                   = 21119,
    GO_FIRE_OF_AKU_MAI_3                                   = 21120,
    GO_FIRE_OF_AKU_MAI_4                                   = 21121,
    GO_AKU_MAI_DOOR                                        = 21117,
    GO_ALTAR_OF_THE_DEEPS                                  = 103016
};

template<class AI, class T>
AI* GetBlackfathomDeepsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BFDScriptName);
}

#endif // BFD_H_
