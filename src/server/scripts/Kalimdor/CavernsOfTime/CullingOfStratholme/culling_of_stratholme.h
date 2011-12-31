/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

enum Data
{
    DATA_MEATHOOK_EVENT,
    DATA_SALRAMM_EVENT,
    DATA_EPOCH_EVENT,
    DATA_MAL_GANIS_EVENT,
    DATA_INFINITE_EVENT,
    DATA_ARTHAS_EVENT,
    DATA_CRATE_COUNT,
};

enum Data64
{
    DATA_ARTHAS,
    DATA_MEATHOOK,
    DATA_SALRAMM,
    DATA_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE,
    DATA_SHKAF_GATE,
    DATA_MAL_GANIS_GATE_1,
    DATA_MAL_GANIS_GATE_2,
    DATA_EXIT_GATE,
    DATA_MAL_GANIS_CHEST
};

enum Creatures
{
    NPC_MEATHOOK        = 26529,
    NPC_SALRAMM         = 26530,
    NPC_EPOCH           = 26532,
    NPC_MAL_GANIS       = 26533,
    NPC_INFINITE        = 32273,
    NPC_ARTHAS          = 26499,
    NPC_JAINA           = 26497,
    NPC_UTHER           = 26528,
    NPC_CHROMIE_2       = 27915,
    NPC_GENERIC_BUNNY   = 28960,
};

enum GameObjects
{
    GO_SHKAF_GATE       = 188686,
    GO_MALGANIS_GATE_1  = 187711,
    GO_MALGANIS_GATE_2  = 187723,
    GO_EXIT_GATE        = 191788,
    GO_MALGANIS_CHEST_N = 190663,
    GO_MALGANIS_CHEST_H = 193597,
    GO_SUSPICIOUS_CRATE = 190094,
    GO_PLAGUED_CRATE    = 190095,
};

enum WorldStatesCoT
{
    WORLDSTATE_SHOW_CRATES          = 3479,
    WORLDSTATE_CRATES_REVEALED      = 3480,
    WORLDSTATE_WAVE_COUNT           = 3504,
    WORLDSTATE_TIME_GUARDIAN        = 3931,
    WORLDSTATE_TIME_GUARDIAN_SHOW   = 3932,
};

enum CrateSpells
{
    SPELL_CRATES_CREDIT     = 58109,
};

#endif
