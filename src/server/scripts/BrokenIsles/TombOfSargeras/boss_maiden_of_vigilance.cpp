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

#include "tomb_of_sargeras.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_INFUSION_START = 1,
    SAY_INFUSION_END = 2,
    SAY_SECOND_PHASE = 3,
    SAY_SECOND_PHASE_LATER = 4,
    SAY_BEFORE_DEATH = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    // Global
    SPELL_INFUSION = 235271,
    SPELL_MASS_INSTABILITY = 235267,
    SPELL_UNSTABLE_SOUL = 235117,

    // Light Side
    SPELL_LIGHT_INFUSION = 235213,
    SPELL_HAMMER_OF_CREATION = 241635,
    SPELL_HAMMER_OF_CREATION_AOE = 235569,
    SPELL_HAMMER_OF_CREATION_VICT = 241624,
    SPELL_LIGHT_REMANENCE = 237994,
    SPELL_LIGHT_REMANENCE_SMALL = 238311,

    // Fel side
    SPELL_FEL_INFUSION = 235240,
    SPELL_HAMMER_OF_OBLITERATION = 241636,
    SPELL_HAMMER_OF_OBLITERATION_AOE = 235573,
    SPELL_HAMMER_OF_OBLITERATION_VICT = 241634,
    SPELL_FEL_REMANENCE = 238316,
    SPELL_FEL_REMANENCE_SMALL = 238416,

    // Phase two
    SPELL_MOVE_TO_ANOTHER = 235630,
    SPELL_BLOWBACK = 248812,
    SPELL_TITANIC_BULWARK = 235028,

    SPELL_WRATH_OF_THE_CREATORS = 234891,
    SPELL_WRATH_OF_THE_CREATORS_TICK = 235014,
    SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT = 234917,
    SPELL_WRATH_OF_THE_CREATORS_TICK_FEL = 236433,
    SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT_DMG = 234896,
    SPELL_WRATH_OF_THE_CREATORS_TICK_FEL_DMG = 236432,
    SPELL_WRATH_OF_THE_CREATORS_BUFF = 237339,

    SPELL_EXTINGUISH_LIFE = 238475,

    SPELL_ESSENCE_FRAGMENTS = 236061,
    SPELL_ESSENCE_FRAGMENTS_TICK = 235859,
    SPELL_CREATE_AT_VISUAL_FEL = 236708,
    SPELL_CREATE_AT_VISUAL_LIGHT = 236690,

    SPELL_ESSENCE_HIT_LIGHT = 235554,
    SPELL_ESSENCE_BUFF_LIGHT = 235534,
    SPELL_ESSENCE_HIT_FEL = 235555,
    SPELL_ESSENCE_BUFF_FEL = 235538,

    // myth
    SPELL_FRAGMENT_BURST = 239069,
    SPELL_FRAGMENT_BURST_DEBUFF = 241729,

    SPELL_FRAGMENTING = 239153,
    SPELL_LIGHT_FRAGMENT = 241697,
    SPELL_LIGHT_FRAGMENT_FOCUS = 241713,
    SPELL_FEL_FRAGMENT = 241728,
    SPELL_FEL_FRAGMENT_FOCUS = 241727,

    SPELL_ENRAGE = 64238,
    SPELL_SHIELD = 241593,

    SPELL_UNKWN = 237856,
};

enum eEvents
{
    EVENT_INFUSION = 1,
    EVENT_LIGHT_HAMMER,
    EVENT_FEL_HAMMER,
    EVENT_MASS_INSTABILITY,
    EVENT_SECOND_PHASE,

    EVENT_FRAGMENTS,

};

Position const fragmentsPos[6]
{
    {6375.67f, -789.47f, 2887.84f, 0.0f}, // original right 1
    {6384.21f, -788.24f, 2887.84f, 0.0f}, // original right 2
    {6394.00f, -786.70f, 2887.84f, 0.0f}, // original right 3
    {6376.05f, -799.67f, 2887.84f, 0.0f}, // original left 1
    {6384.74f, -801.70f, 2887.84f, 0.0f}, // original left 2
    {6393.59f, -803.61f, 2887.84f, 0.0f}  // original left 3

    //6319.85 other side
};

void AddSC_boss_maiden_of_vigilance()
{
    
}
