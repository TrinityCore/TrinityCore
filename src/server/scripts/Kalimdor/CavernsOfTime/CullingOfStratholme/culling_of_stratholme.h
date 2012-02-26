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
    DATA_TRANSFORM_CITIZENS,
    DATA_ZOMBIEFEST,
    DATA_ARTHAS_STEP,
};

enum Data64
{
    DATA_ARTHAS,
    DATA_MEATHOOK,
    DATA_SALRAMM,
    DATA_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE,
    DATA_CRIER,
    DATA_SHKAF_GATE,
    DATA_MAL_GANIS_GATE_1,
    DATA_MAL_GANIS_GATE_2,
    DATA_EXIT_GATE,
    DATA_MAL_GANIS_CHEST,
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
    NPC_CHROMIE_3       = 30997,
    NPC_GENERIC_BUNNY   = 28960,
    NPC_LORDAERON_CRIER = 27913,
};

enum Citizens
{
    NPC_CITY_MAN  = 28167,
    NPC_CITY_MAN2 = 28169,
    NPC_CITY_MAN3 = 31126,
    NPC_CITY_MAN4 = 31127,

    NPC_ZOMBIE    = 27737,
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

enum ExtraInfo
{
    SPELL_CRATES_CREDIT        = 58109,
    ITEM_ARCANE_DISRUPTOR      = 37888,
    QUEST_DISPELLING_ILLUSIONS = 13149,
    QUEST_A_ROYAL_ESCORT       = 13151,
    ACHIEVEMENT_CULLING_TIME   = 1817,
    ACHIEVEMENT_ZOMBIEFEST     = 1872,
};

Position const ChromieEntranceSummonPos = {1813.29f, 1283.57f, 142.325f, 3.87816f};
Position const ChromieExitSummonPos     = {2316.56f, 1493.22f, 128.011f, 4.13119f};
Position const InfiniteSummonPos        = {2334.97f, 1269.46f, 132.882f, 3.23105f};

Position const ArthasSpawnPositions[3] =
{
    {2049.41f, 1287.57f, 142.746f, 0.0f},
    {2364.20f, 1194.66f, 131.575f, 0.226905f},
    {2536.80f, 1130.81f, 130.928f, 0.152292f},
};

#endif
