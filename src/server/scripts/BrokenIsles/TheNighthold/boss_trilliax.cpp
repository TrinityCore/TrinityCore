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

#include "thenighthold.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerTemplate.h"

Position const sludgeraxSumPos[8] =
{
    {427.32f, 3336.66f, -225.69f, 2.21f},
    {429.49f, 3340.25f, -225.69f, 0.73f},
    {459.06f, 3344.21f, -225.59f, 1.59f},
    {466.09f, 3280.36f, -225.64f, 2.11f},
    {475.85f, 3291.92f, -225.66f, 0.70f},
    {477.00f, 3278.06f, -225.63f, 3.26f},
    {494.54f, 3319.75f, -225.69f, 2.81f},
    {495.03f, 3313.42f, -225.69f, 1.97f}
};

Position const trilliaxCentrPos = { 458.19f, 3309.75f, -224.126f };

Position const scrubberPos[5] =
{
    {413.16f, 3285.52f, -225.67f, 3.64f},
    {459.70f, 3360.98f, -225.67f, 1.52f},
    {479.96f, 3355.19f, -225.69f, 1.11f},
    {453.32f, 3259.95f, -225.69f, 4.62f},
    {502.97f, 3331.67f, -225.69f, 0.44f}
};

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_TIDY_UP = 3,
    CONV_TOXIC = 2092,
    CONV_BONDS = 2200,
    CONV_ANNIGILATION = 2098,
    CONV_AFTER_ANNIG = 2206,
    CONV_AFTER_ANNIG_1 = 2204,
    CONV_FEAST = 2096,
    CONV_TIDY_UP = 2097,
    CONV_STERILIZE = 2195,
    CONV_STERILIZE_1 = 2194,
    CONV_RAGE = 2093,
    CONV_DIED = 2205
};

enum Spells
{
    //Intro
    SPELL_DEAD_COSMETIC = 223945,
    SPELL_BURSTING_SLIME = 223710,
    SPELL_DEATH_COSMETIC_2 = 223721,

    SPELL_ARCANE_SEEPAGE = 206482,
    SPELL_ARCANE_SEEPAGE_FILTER = 208875,
    SPELL_ARCANE_SEEPAGE_AT = 206487,
    SPELL_ARCANE_SLASH = 206641,
    SPELL_FORM_CLEANER_DUMMY = 206570,
    SPELL_FORM_CLEANER = 206560,
    SPELL_FORM_MANIAC = 206557,
    SPELL_FORM_CARETAKER = 206559,
    SPELL_ANNIHILATION_JUMP = 207620,
    SPELL_ANNIHILATION_AT = 207630,
    SPELL_TOXIC_SLICE = 206788,
    SPELL_TOXIC_SLICE_TRIG = 206789,
    SPELL_TOXIC_SLICE_AT = 206796,
    SPELL_STERILIZE = 208506,
    SPELL_STERILIZE_AURA = 208499,
    SPELL_STERILIZE_AURA_2 = 218247,
    SPELL_CLEANSING_RAGE_FILTER = 206834,
    SPELL_CLEANSING_RAGE_FILTER_2 = 206820,
    SPELL_MANA_RUPTURE = 206645,
    SPELL_ARCING_BONDS_FILTER = 208924,
    SPELL_ARCING_BONDS_DMG = 208918,
    SPELL_ARCING_BONDS_VISUAL = 209023,
    SPELL_SUCCULENT_FEAST = 207502,
    SPELL_SUCCULENT_FEAST_SUM = 207503,
    SPELL_SUCCULENT_FEAST_AT = 206835,
    SPELL_TIDY_UP = 207513,
    SPELL_TIDY_UP_SUM = 207531,

    //Heroic
    SPELL_TOXIC_SLICE_HEROIC = 214573,

    //Mythic
    SPELL_DEACTIVATED_CONSTRUCT = 214881,
    SPELL_ENERGIZED = 214670,
    SPELL_DUAL_PERSONALITIES_CLEANER = 214882,
    SPELL_DUAL_PERSONALITIES_MANIAC = 215066,
    SPELL_TOXIC_SLICE_COPY = 215062,
    SPELL_CLEANSING_RAGE_COPY = 215072,
    SPELL_ANNIHILATION_AT_COPY = 214672,

    //Scrubber
    SPELL_ENERGY_AURA = 224470,
    SPELL_STERILIZE_DEBUFF = 214583,
    SPELL_SCRUBBING_MAX = 211897,
    SPELL_SCRUBBING_MIN = 211907,
    SPELL_ENERGY_STATE_1 = 215048,
    SPELL_ENERGY_STATE_2 = 224472,
    SPELL_CLEANSING_DESTRUCTION = 207327,
    SPELL_CLEANSING_DESTRUCTION_PLR = 207328,
};

enum eEvents
{
    EVENT_ARCANE_SLASH = 1,
    EVENT_ANNIHILATION = 2,
    EVENT_TOXIC_SLICE = 3,
    EVENT_STERILIZE = 4,
    EVENT_CLEANSING_RAGE = 5,
    EVENT_MANA_RUPTURE = 6,
    EVENT_ARCING_BONDS = 7,
    EVENT_SUCCULENT_FEAST = 8,
    EVENT_TIDY_UP = 9
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
};

void AddSC_boss_trilliax()
{
    
}
