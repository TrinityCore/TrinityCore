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

#ifndef SLAVE_PENS_H
#define SLAVE_PENS_H

#include "CreatureAIImpl.h"

uint32 const EncounterCount               = 3;

#define SPScriptName "instance_the_slave_pens"
#define DataHeader "SP"

enum SPDataTypes
{
    DATA_MENNU_THE_BETRAYER               = 0,
    DATA_ROKMAR_THE_CRACKLER              = 1,
    DATA_QUAGMIRRAN                       = 2,
    DATA_AHUNE                            = 3,
    DATA_AHUNE_BUNNY                      = 4,
    DATA_FROZEN_CORE                      = 5,
    DATA_FLAMECALLER_000                  = 6,
    DATA_FLAMECALLER_001                  = 7,
    DATA_FLAMECALLER_002                  = 8,
    DATA_BONFIRE_BUNNY_000                = 9,
    DATA_BONFIRE_BUNNY_001                = 10,
    DATA_BONFIRE_BUNNY_002                = 11,
    DATA_BEAM_BUNNY_000                   = 12,
    DATA_BEAM_BUNNY_001                   = 13,
    DATA_BEAM_BUNNY_002                   = 14,
    DATA_LUMA_SKYMOTHER                   = 15
};

enum SPCreaturesIds
{
    NPC_AHUNE                            = 25740,
    NPC_FROZEN_CORE                      = 25865,
    NPC_LUMA_SKYMOTHER                   = 25697,
    NPC_AHUNE_LOC_BUNNY                  = 25745,
    NPC_EARTHEN_RING_FLAMECALLER         = 25754,
    NPC_SHAMAN_BONFIRE_BUNNY_000         = 25971,
    NPC_SHAMAN_BONFIRE_BUNNY_001         = 25972,
    NPC_SHAMAN_BONFIRE_BUNNY_002         = 25973,
    NPC_SHAMAN_BEAM_BUNNY_000            = 25964,
    NPC_SHAMAN_BEAM_BUNNY_001            = 25965,
    NPC_SHAMAN_BEAM_BUNNY_002            = 25966
};

enum SPGameObjectIds
{
    GO_ICE_SPEAR                         = 188077,
    GO_ICE_STONE                         = 187882
};

template <class AI, class T>
inline AI* GetSlavePensAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SPScriptName);
}

#define RegisterSlavePensCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSlavePensAI)
#define RegisterSlavePensGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetSlavePensAI)

#endif // SLAVE_PENS_H
