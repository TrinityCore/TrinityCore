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

#include "siege_of_orgrimmar.hpp"
#include "SpellAuraEffects.h"

#define MALKOROK_POWER_TYPE POWER_ENERGY
#define MALKOROK_POWER_MAX 100

#define ENERGY_UPDATE_TIMER 1000 // in milliseconds
#define FIRST_PHASE_DURATION 140000 // in milliseconds
//#define FIRST_PHASE_DURATION 10000 // in milliseconds

// The boss regenerates 100 rage in 140 seconds
// He should cast the '3 smashes and 1 breath' combo two times per phase
// So he casts arcing smash each 10-15 energy

enum ScriptedTexts
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_INTRO = 2,
    SAY_WIPE = 3,
    SAY_ARCING_SMASH = 4,
    SAY_BREATH_OF_YSHAARJ = 5,
    SAY_BLOOD_RAGE = 6,
    SAY_ZERK = 7,
};

enum Spells
{
    SPELL_ZERO_MANA_REGEN = 96301,

    SPELL_ERADICATE = 143916,

    SPELL_ANCIENT_MIASMA_AURA = 142861,
    SPELL_ANCIENT_MIASMA_DMG = 142906,
    SPELL_ANCIENT_MIASMA_DUMMY_1 = 143018, // on dummy npc
    SPELL_ANCIENT_MIASMA_DUMMY_2 = 143042, // casted by miasmas on blood rage beginning
    SPELL_ANCIENT_MIASMA_DUMMY_3 = 143047, // maybe casted by controller npc 71459
    SPELL_EXPEL_MIASMA = 143199,
    SPELL_ANCIENT_MIASMA_DUMMY_4 = 143983, // from miasmas to the boss on blood rage beginning
    SPELL_ANCIENT_MIASMA_DUMMY_5 = 149440, // casted by miasmas after blood rage (and after hit by 149443)
    SPELL_ANCIENT_MIASMA_DUMMY_6 = 149443, // aoe spell from the boss to all miasmas after blood rage

    SPELL_ANCIENT_BARRIER = 142862,
    SPELL_WEAK_ANCIENT_BARRIER = 142863,
    SPELL_MIDDLE_ANCIENT_BARRIER = 142864,
    SPELL_STRONG_ANCIENT_BARRIER = 142865,

    SPELL_BLOOD_RAGE = 142879,
    SPELL_BLOOD_RAGE_DMG = 142890,
    SPELL_RELENTLESS_ASSAULT = 143261,

    SPELL_SEISMIC_SLAM = 142851,
    SPELL_SEISMIC_SLAM_DMG = 142849,
    SPELL_SEISMIC_SLAM_SUMMON = 143586, // on heroic

    SPELL_ARCING_SMASH_JUMP = 142898,
    SPELL_ARCING_SMASH_DUMMY = 142826, // triggered by jump spell
    SPELL_ARCING_SMASH_CHANNEL = 143805, //
    SPELL_ARCING_SMASH_DUMMY_2 = 143806, // ?
    SPELL_ARCING_SMASH_DMG = 142815,

    SPELL_BREATH_OF_YSHAARJ = 142842,
    SPELL_BREATH_OF_YSHAARJ_DMG = 142816,

    SPELL_FATAL_STRIKES = 146254,
    SPELL_FATAL_STRIKE = 142990,

    SPELL_IMPLODING_ENERGY = 142980,
    SPELL_IMPLODING_ENERGY_AOE = 142988,
    SPELL_IMPLODING_ENERGY_AURA = 144069,
    SPELL_IMPLODING_ENERGY_DMG = 142986,
    SPELL_IMPLODING_ENERGY_DMG_2 = 142987, // if nobody was hit by first dmg spell

    SPELL_DISPLACED_ENERGY = 142913,
    SPELL_DISPLACED_ENERGY_DMG = 142928,

    SPELL_ESSENSE_OF_YSHAARJ_SELF = 143846,
    SPELL_ESSENSE_OF_YSHAARJ_DUMMY = 143848, // triggered by 143846
    SPELL_ESSENSE_OF_YSHAARJ_DUMMY_2 = 143902,
    SPELL_ESSENSE_OF_YSHAARJ_AREATRIGGER = 143850,
    SPELL_ESSENSE_OF_YSHAARJ_DMG = 143857,
    SPELL_ESSENSE_OF_YSHAARJ_SCRIPT = 143908, // ?
    SPELL_ESSENSE_OF_YSHAARJ_EXPLODE = 143913, // visual

    SPELL_LANGUISH_AURA = 142989,
    SPELL_LANGUISH_DEBUFF = 143919,
};

enum Adds
{
    NPC_CONTROLLER = 71459, // casts 71459 spell
    NPC_ANCIENT_MIASMA = 71513,
    NPC_ARCING_SMASH = 71455,
    NPC_IMPLOSION = 71470,

    NPC_LIVING_CORRUPTION = 71644, // on heroic
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_ARCING_SMASH_JUMP,
    EVENT_IMPLODING_ENERGY,
    EVENT_DISPLACED_ENERGY,
    EVENT_CLEAR_ARCING_SMASH,
    EVENT_BLOOD_RAGE,
};

enum Actions
{
    ACTION_ENERGY_FULL = 1,
    ACTION_ENERGY_EMPTY,
    ACTION_IMPLOSION_DAMAGE,
    ACTION_ENDLESS_RAGE,
    ACTION_EXPEL_MIASMA,
    ACTION_SEISMIC_SLAM,
    ACTION_ARCING_SMASH,
    ACTION_BREATH_OF_YSHAARJ,
};

enum Timers
{
    TIMER_BERSERK = 6 * MINUTE * IN_MILLISECONDS,
    TIMER_EVADE_CHECK = 5 * IN_MILLISECONDS,

    TIMER_IMPLODING_ENERGY = 5 * IN_MILLISECONDS, // explodes in 10 seconds after arcing smash

    TIMER_DISPLACED_ENERGY_FIRST = 3500,
    TIMER_DISPLACED_ENERGY = 11000,
};

enum Phases : int
{
    PHASE_NONE = 0,
    PHASE_MIGHT_OF_THE_KORKRON = 1,
    PHASE_ENDLESS_RAGE = 2,
    PHASE_EXPEL_MIASMA = 3,
};

const Position miasmasPos[4] =
{
    {1914.38f, -4950.57f, -198.96f, 3.77f}, // at center
    {1897.40f, -4962.41f, -198.86f, 0.54f},
    {1932.11f, -4961.39f, -198.99f, 2.07f},
    {1926.67f, -4934.21f, -198.99f, 2.32f}
};

const Position centerPos = { 1914.38f, -4950.57f, -198.96f, 3.77f };

#define SEISMIC_SLAM_COUNT 6
const float seismicSlamEnergy[SEISMIC_SLAM_COUNT]
{
    4.f, 18.f, 32.f, 54.f, 68.f, 82.f
};

#define ARCING_SMASH_COUNT 6
const float arcingSmashEnergy[ARCING_SMASH_COUNT]
{
    10.f, 25.f, 40.f, 60.f, 75.f, 90.f
};

#define BREATH_OF_YSHAARJ_COUNT 2
const float breathOfYshaarjEnergy[BREATH_OF_YSHAARJ_COUNT]
{
    48.f, 98.f
};

#define IMPLODING_ENERGY_MIN_DIST 20.f
#define IMPLODING_ENERGY_MAX_DIST 30.f
#define IMPLODING_ENERGY_COUNT_10PPL 3
#define IMPLODING_ENERGY_COUNT_25PPL 7

#define LANGUISH_RANGE 3.f

#define ESSENSE_OF_YSHAARJ_COUNT_10 2
#define ESSENSE_OF_YSHAARJ_COUNT_25 5

#define EVADE_DISTANCE 45.f

void AddSC_boss_malkorok()
{
   
}
