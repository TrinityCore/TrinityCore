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

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

#include "CreatureAIImpl.h"

#define ZGScriptName "instance_zulgurub"
#define DataHeader "ZG"

uint32 const EncounterCount = 12;

enum ZGDataTypes
{
    DATA_JEKLIK             = 0,  // Main boss
    DATA_VENOXIS            = 1,  // Main boss
    DATA_MARLI              = 2,  // Main boss
    DATA_ARLOKK             = 3,  // Main boss
    DATA_THEKAL             = 4,  // Main boss
    DATA_HAKKAR             = 5,  // End boss
    DATA_MANDOKIR           = 6,  // Optional boss
    DATA_JINDO              = 7,  // Optional boss
    DATA_GAHZRANKA          = 8,  // Optional boss
    DATA_EDGE_OF_MADNESS    = 9,  // Optional Event Edge of Madness - one of: Gri'lek, Renataki, Hazza'rah, or Wushoolay
    DATA_LORKHAN            = 10, // Zealot Lor'Khan add to High priest Thekal!
    DATA_ZATH               = 11, // Zealot Zath add to High priest Thekal!
    TYPE_EDGE_OF_MADNESS    = 12  // Boss storage
};

enum ZGCreatureIds
{
    NPC_ARLOKK              = 14515, // Arlokk Event
    NPC_PANTHER_TRIGGER     = 15091, // Arlokk Event
    NPC_ZULIAN_PROWLER      = 15101, // Arlokk Event
    NPC_ZEALOT_LORKHAN      = 11347,
    NPC_ZEALOT_ZATH         = 11348,
    NPC_PRIESTESS_MARLI     = 14510,
    NPC_HIGH_PRIEST_THEKAL  = 14509,
    NPC_JINDO_THE_HEXXER    = 11380,
    NPC_NIGHTMARE_ILLUSION  = 15163,
    NPC_SHADE_OF_JINDO      = 14986,
    NPC_SACRIFICED_TROLL    = 14826,
    NPC_MANDOKIR            = 11382, // Mandokir Event
    NPC_OHGAN               = 14988, // Mandokir Event
    NPC_VILEBRANCH_SPEAKER  = 11391, // Mandokir Event
    NPC_CHAINED_SPIRT       = 15117  // Mandokir Event

};

enum ZGGameObjectIds
{
    GO_FORCEFIELD           = 180497, // Arlokk Event
    GO_GONG_OF_BETHEKK      = 180526  // Arlokk Event
};

template <class AI, class T>
inline AI* GetZulGurubAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ZGScriptName);
}

#endif
