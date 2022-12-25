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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum eSpells
{
    SPELL_WITHER_WILL = 106736,
    SPELL_TOUCH_OF_NOTHINGNESS = 106113,
    SPELL_FIGMENT_OF_DOUBT = 106937,
    SPELL_BOUNDS_OF_REALITY = 131498,
    SPELL_BOUNDS_OF_REALITY_2 = 117665, //pastram
    SPELL_CHI_WAVE = 132464,
    SPELL_CHI_WAVE_2 = 132466,

    SPELL_FIGMENT_OF_DOUBT_2 = 106935,
    SPELL_FIGMENT_OF_DOUBT_3 = 106936, // pastram
    SPELL_COPY_WEAPON = 41054,
    SPELL_COPY_WEAPON_2 = 41055,
    SPELL_GROW = 104921,
    SPELL_DROWNED_STATE = 117509,
    SPELL_DRAW_DOUBT = 106290,
    SPELL_KNOCK_BACK_SELF = 117525,
    SPELL_GATHERING_DOUBT = 117570, // pastram
    SPELL_GATHERING_DOUBT_2 = 117571,
    SPELL_INVISIBILITY_DETECTION = 126839,
    SPELL_WEAKENED_BLOWS = 115798,
    SPELL_RELEASE_DOUBT = 106112,
    SPELL_SCREEN_PHASE = 106290,
    SPELL_CLONE_PLAYER = 45204,
    SPELL_CLONE_WEAPON = 41055,

    SPELL_PURIFIED_WATER = 118714,
};

enum eEvents
{
    EVENT_WITHER_WILL = 1,
    EVENT_TOUCH_OF_NOTHINGNESS = 2,
    EVENT_BOUNDS_OF_REALITY = 3,

    EVENT_GATHERING_DOUBT = 4,

    EVENT_SPELL_PHANTOM_STRIKE = 5,
    EVENT_SPELL_ARMOR_BUFF = 6,
    EVENT_SPELL_FURY = 7,
    EVENT_SANCTUARY = 8,
    EVENT_SIPHON_ESSENCE = 9,
    EVENT_STUN = 10,
    EVENT_BLADE_SONG = 11,
    EVENT_UNTAMED_FURY = 12,
    EVENT_GLIMPSE_OF_MADNESS = 13,
    EVENT_UPDATE_ENERGY = 14,
    EVENT_EXPLODE = 15,
    EVENT_PHASE_TWO = 16,
    EVENT_SEARCH_FIGMENTS = 17,
    EVENT_SCREEN = 18,
    EVENT_COPY_PLAYER = 19,
};

enum Creatures
{
    NPC_SHA_OF_DOUBT = 56439,
    NPC_FIGMENTS_OF_DOUBT = 56792,
};

enum Phases
{
    PHASE_ONE = 1,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_FIGMENTS = 2,
    TALK_DEATH = 3,
    TALK_WIPE = 4,
};

void AddSC_boss_sha_of_doubt()
{
   
}
