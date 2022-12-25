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

#include "ScriptPCH.h"
#include "ScriptedCreature.h"

#define EVENT_LOREWALKER_STONESTEP_SUNS 0
#define EVENT_LOREWALKER_STONESTEP_TRIAL 1

enum Spells
{
    SPELL_SUNFIRE_RAYS = 107223,
    SPELL_HAUNTING_GAZE = 114646,
    SPELL_HELLFIRE_ARROWS = 113017,
    SPELL_EXTRACT_SHA = 111764,

    SPELL_SHA_MOVE_SPELL = 111807,
    SPELL_ROOT_SELF = 106822,
    SPELL_SUN_VISUAL = 107349,

    SPELL_ROOT_SUN = 93960,
    SPELL_ROOT_TRIAL_OF_YAUNGOL = 106649,

    SPELL_AGONY = 114571,
    SPELL_INTENSITY = 113315,
    SPELL_INTENSITY_TRIGGERED = 113316,
    SPELL_DISSIPATION = 113379,
    SPELL_ULTIMATE_POWER = 113309,
};

enum Events
{
    EVENT_SUNFIRE_RAYS = 1,
    EVENT_HAUNTING_GAZE = 2,
    EVENT_HELLFIRE_ARROWS = 3,

    EVENT_TALK_ONE = 4,
    EVENT_TALK_TWO = 5,
    EVENT_TALK_THREE = 6,
    EVENT_TALK_FOUR = 7,

    EVENT_YELL = 8, // osong

    EVENT_TALK_SUN_ONE = 9,
    EVENT_TALK_SUN_TWO = 10,
    EVENT_TALK_SUN_THREE = 11,
    EVENT_TALK_SUN_FOUR = 12,

    EVENT_TALK_YAUNGOL_FOUR = 13,
    EVENT_TALK_YAUNGOL_ONE = 14,
    EVENT_TALK_YAUNGOL_TWO = 15,
    EVENT_TALK_YAUNGOL_THREE = 16,
    EVENT_TALK_YAUNGOL_FIVE = 17,
    EVENT_TALK_YAUNGOL_SIX = 18,

    EVENT_AGONY,
    EVENT_DONT_STACK,

};

enum Creatures
{
    NPC_ZAO = 58826,
    NPC_SUN = 56915, //69460
    NPC_SHA_ADD_SUN = 58856,
    NPC_SHA_ADD_MOVE_TO_NPC = 58865,

    NPC_LOREWALKER = 56843,
    NPC_SCROLL = 57080,
    NPC_OSONG = 56872,
    NPC_LOREWALKER_SUN = 999606, // LOCAL 999563
    NPC_LOREWALKER_YAUNGOL = 999605, // LOCAL 999564
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2,
};

enum Talks
{
    TALK_INTRO_ONE = 1,
    TALK_INTRO_TWO = 2,
    TALK_INTRO_THREE = 3,
    TALK_INTRO_FOUR = 4,

    TALK_OSONG = 1,

    TALK_ZAO_COMBAT = 1,
    TALK_ZAO_CORRUPTED = 2,

    TALK_SUN_ONE = 1,
    TALK_SUN_TWO = 2,
    TALK_SUN_THREE = 3,
    TALK_SUN_FOUR = 4,

    TALK_YAUNGOL_ONE = 1,
    TALK_YAUNGOL_TWO = 2,
    TALK_YAUNGOL_THREE = 3,
    TALK_YAUNGOL_FOUR = 4,
    TALK_YAUNGOL_FIVE = 5,
    TALK_YAUNGOL_SIX = 6,
};

#define TIMER_INTENSITY 2000
#define TIMER_DISSIPATION 2000

void AddSC_boss_lorewalker_stonestep()
{
    
}
