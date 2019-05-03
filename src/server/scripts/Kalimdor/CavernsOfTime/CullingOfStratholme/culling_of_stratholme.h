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

#ifndef DEF_CULLING_OF_STRATHOLME_H
#define DEF_CULLING_OF_STRATHOLME_H

#include "CreatureAIImpl.h"

#define CoSScriptName "instance_culling_of_stratholme"
#define DataHeader "CS"

uint32 const EncounterCount = 5;

enum CSDataTypes
{
    DATA_ARTHAS,
    DATA_MEATHOOK,
    DATA_SALRAMM,
    DATA_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE,
    DATA_CRATE_COUNT,
    DATA_SHKAF_GATE,
    DATA_MAL_GANIS_GATE_1,
    DATA_MAL_GANIS_GATE_2,
    DATA_EXIT_GATE,
    DATA_MAL_GANIS_CHEST,
    DATA_INFINITE_COUNTER
};

enum CSCreatureIds
{
    NPC_MEATHOOK         = 26529,
    NPC_SALRAMM          = 26530,
    NPC_EPOCH            = 26532,
    NPC_MAL_GANIS        = 26533,
    NPC_INFINITE         = 32273,
    NPC_ARTHAS           = 26499,
    NPC_JAINA            = 26497,
    NPC_UTHER            = 26528,
    NPC_CHROMIE          = 26527,
    NPC_CHROMIE_2        = 27915,
    NPC_CHROMIE_3        = 30997,
    NPC_GENERIC_BUNNY    = 28960,

    NPC_TIME_RIFT        = 28409,
    NPC_GUARDIAN_OF_TIME = 32281
};

enum CSGameObjectIds
{
    GO_SHKAF_GATE       = 188686,
    GO_MALGANIS_GATE_1  = 187711,
    GO_MALGANIS_GATE_2  = 187723,
    GO_EXIT_GATE        = 191788,
    GO_MALGANIS_CHEST_N = 190663,
    GO_MALGANIS_CHEST_H = 193597,
    GO_SUSPICIOUS_CRATE = 190094,
    GO_PLAGUED_CRATE    = 190095
};

enum CSWorldStatesCoT
{
    WORLDSTATE_SHOW_CRATES          = 3479,
    WORLDSTATE_CRATES_REVEALED      = 3480,
    WORLDSTATE_WAVE_COUNT           = 3504,
    WORLDSTATE_TIME_GUARDIAN        = 3931,
    WORLDSTATE_TIME_GUARDIAN_SHOW   = 3932
};

enum CSCrateSpells
{
    SPELL_CRATES_CREDIT     = 58109
};

enum CSTexts
{
    SAY_CRATES_COMPLETED    = 0,
    // Chromie
    SAY_INFINITE_START      = 0, // On Infinite Corruptor event start
    SAY_INFINITE            = 1, // On Infinite Corruptor event at 5 minutes
    SAY_INFINITE_FAIL       = 2, // On Infinite Corruptor event fail
    // Infinite Corruptor
    SAY_FAIL_EVENT          = 2 // On Infinite Corruptor event fail
};

enum CSInstanceEvents
{
    EVENT_INFINITE_TIMER    = 1
};

template <class AI, class T>
inline AI* GetCullingOfStratholmeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, CoSScriptName);
}

#endif
