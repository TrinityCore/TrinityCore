/*
 * Copyright 2023 AzgathCore
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

#include "emerald_nightmare.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_FOCUSED_GAZE_EMOTE = 1,
    SAY_FOCUSED_GAZE = 2,
    SAY_CACOPHONY = 3,
    SAY_DEATH = 4,
    SAY_BLOOD_FRENZY = 5,
};

enum Spells
{
    SPELL_EMPTY_ENERGY = 205270,
    SPELL_FEROCIOUS_YELL = 204990,
    SPELL_ENERGIZE = 205272,
    SPELL_BERSERK = 26662,
    SPELL_OVERWHELM_AURA = 197946,
    SPELL_OVERWHELM_DUMMY = 197947,
    SPELL_OVERWHELM_DMG = 197943,
    SPELL_REND_FLESH_AURA = 197948,
    SPELL_REND_FLESH_DUMMY = 197949,
    SPELL_REND_FLESH_DMG = 197942,
    SPELL_FOCUSED_GAZE = 198006,
    SPELL_BARRELING_MOMENTUM = 198002,
    SPELL_B_MOMENTUM_FILTER = 198004,
    SPELL_B_MOMENTUM_PING = 198007,
    SPELL_B_MOMENTUM_CHARGE = 198009,
    SPELL_B_MOMENTUM_AT = 198093,
    SPELL_B_MOMENTUM_DMG = 198099,
    SPELL_B_MOMENTUM_AOE = 198109,
    SPELL_B_MOMENTUM_DUMMY = 198102,
    SPELL_MOMENTUM_DEBUFF = 198108,
    SPELL_TRAMPLING_SLAM = 199237,
    SPELL_BLOOD_FRENZY = 198388,
    SPELL_ROARING_CACOPHONY_AURA = 197986,
    SPELL_ROARING_CACOPHONY_DUMMY_1 = 197988,
    SPELL_ROARING_CACOPHONY_DUMMY_2 = 197989,
    SPELL_ROARING_CACOPHONY_DMG = 197969,
    SPELL_ECHOING_DISCHORD = 198392,

    SPELL_ROARING_CACOPHONY_SUM = 197982,
    SPELL_NIGHTMARISH_CACOPHONY = 197980,
    SPELL_NIGHTMARE_IMAGE_AT = 197960, 
    SPELL_NIGHTMARE_IMAGE_MORPH = 204969,
};

enum eEvents
{
    EVENT_FOCUSED_GAZE = 1,
    EVENT_REND_FLESH = 2,
    EVENT_OVERWHELM = 3,
    EVENT_ROARING_CACOPHONY = 4,
    EVENT_ROARING_CACOPHONY_2 = 5,

    EVENT_ACTIVATE_IMAGE,
    ACTION_BARRELING_MOMENTUM,
};

enum eOther
{
    DATA_PLAYER_HITCOUNT = 1,
    DATA_MOMENTUM_TARGET = 2,

    ACTION_1,
    ACTION_2,
    ACTION_3,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

void AddSC_ursoc()
{
   
}
