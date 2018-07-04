/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DRAK_THARON_KEEP_H_
#define DRAK_THARON_KEEP_H_

#include "CreatureAIImpl.h"

#define DrakTharonKeepScriptName "instance_drak_tharon_keep"
#define DataHeader               "DTK"

uint32 const EncounterCount = 4;

enum DTKDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_TROLLGORE                      = 0,
    DATA_NOVOS                          = 1,
    DATA_KING_DRED                      = 2,
    DATA_THARON_JA                      = 3,

    // Additional data
    //DATA_KING_DRED_ACHIEV,

    DATA_TROLLGORE_INVADER_SUMMONER_1,
    DATA_TROLLGORE_INVADER_SUMMONER_2,
    DATA_TROLLGORE_INVADER_SUMMONER_3,

    DATA_NOVOS_CRYSTAL_1,
    DATA_NOVOS_CRYSTAL_2,
    DATA_NOVOS_CRYSTAL_3,
    DATA_NOVOS_CRYSTAL_4,
    DATA_NOVOS_SUMMONER_1,
    DATA_NOVOS_SUMMONER_2,
    DATA_NOVOS_SUMMONER_3,
    DATA_NOVOS_SUMMONER_4,

    ACTION_CRYSTAL_HANDLER_DIED
};

enum DTKCreatureIds
{
    NPC_TROLLGORE                       = 26630,
    NPC_NOVOS                           = 26631,
    NPC_KING_DRED                       = 27483,
    NPC_THARON_JA                       = 26632,

    // Trollgore
    NPC_DRAKKARI_INVADER_A              = 27709,
    NPC_DRAKKARI_INVADER_B              = 27753,
    NPC_DRAKKARI_INVADER_C              = 27754,

    // Novos
    NPC_CRYSTAL_CHANNEL_TARGET          = 26712,
    NPC_CRYSTAL_HANDLER                 = 26627,
    NPC_HULKING_CORPSE                  = 27597,
    NPC_FETID_TROLL_CORPSE              = 27598,
    NPC_RISEN_SHADOWCASTER              = 27600,

    // King Dred
    NPC_DRAKKARI_GUTRIPPER              = 26641,
    NPC_DRAKKARI_SCYTHECLAW             = 26628,

    NPC_WORLD_TRIGGER                   = 22515
};

enum DTKGameObjectIds
{
    GO_NOVOS_CRYSTAL_1                  = 189299,
    GO_NOVOS_CRYSTAL_2                  = 189300,
    GO_NOVOS_CRYSTAL_3                  = 189301,
    GO_NOVOS_CRYSTAL_4                  = 189302
};

template<typename AI>
inline AI* GetDrakTharonKeepAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, DrakTharonKeepScriptName);
}

#endif // DRAK_THARON_KEEP_H_
