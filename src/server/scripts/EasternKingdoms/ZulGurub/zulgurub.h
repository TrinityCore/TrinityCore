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

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

#include "CreatureAIImpl.h"

#define DataHeader "ZG"
#define ZGScriptName "instance_zulgurub"

uint32 const EncounterCount = 5;

enum ZGDataTypes
{
    DATA_VENOXIS                    = 0,
    DATA_MANDOKIR                   = 1,
    DATA_KILNARA                    = 2,
    DATA_ZANZIL                     = 3,
    DATA_JINDO                      = 4,

    // Cache of Madness
    DATA_HAZZARAH                   = 5,
    DATA_RENATAKI                   = 6,
    DATA_WUSHOOLAY                  = 7,
    DATA_GRILEK                     = 8,

    // Jin'do the Godbreaker
    DATA_JINDOR_TRIGGER,
};

enum ZGCreatureIds
{
    NPC_VENOXIS                     = 52155,
    NPC_MANDOKIR                    = 52151,
    NPC_KILNARA                     = 52059,
    NPC_ZANZIL                      = 52053,
    NPC_JINDO                       = 52148,

    // Cache of Madness
    NPC_HAZZARAH                    = 52271,
    NPC_RENATAKI                    = 52269,
    NPC_WUSHOOLAY                   = 52286,
    NPC_GRILEK                      = 52258,

    // Bloodlord Mandokir
    NPC_CHAINED_SPIRIT              = 52156,
    NPC_OHGAN                       = 52157,

    // Jin'do the Godbreaker
    NPC_JINDO_TRIGGER               = 52150,
    NPC_SPIRIT_OF_HAKKAR            = 52222,
    NPC_SHADOW_OF_HAKKAR            = 52650
};

enum ZGGameObjectIds
{
    // High Priest Venoxis
    GO_VENOXIS_COIL                 = 208844,

    // Bloodlord Mandokir
    GO_ARENA_DOOR_1                 = 208845,
    GO_ARENA_DOOR_2                 = 208847,
    GO_ARENA_DOOR_3                 = 208848,
    GO_ARENA_DOOR_4                 = 208846,
    GO_ARENA_DOOR_5                 = 208849,

    // High Priestess Kilnara
    GO_FORCEFIELD                   = 180497,

    // Zanzil
    GO_ZANZIL_DOOR                  = 208850,

    // Cache of Madness
    GO_THE_CACHE_OF_MADNESS_DOOR    = 208843
};

template<class AI, class T>
AI* GetZulGurubAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ZGScriptName);
}

#endif
