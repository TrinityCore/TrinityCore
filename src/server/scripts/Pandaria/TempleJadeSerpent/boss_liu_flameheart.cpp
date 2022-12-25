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

enum Spells
{
    //LIU FLAMEHEART Event:
    SPELL_POSSESSED_BY_SHA = 110164, //On Spawn
    SPELL_DUST_VISUAL = 110518, //On Spawn
    SPELL_SERPENT_DANCE_TRIGGER = 106878,
    SPELL_SERPENT_STRIKE = 106823, //2 24 24 - 5 25 38 419912664 419923538 every 10 seconds
    SPELL_SERPENT_WAVE_SUMMON_CONTROLLER = 106982, // 1 or 2 seconds after serpent strike
    SPELL_SERPENT_KICK = 106856, // 419913710 419924520, every 10 seconds
    SPELL_JADE_ESSENCE = 106797, //AddAura on phase 2
    SPELL_JADE_SERPENT_DANCE_TRIGGER = 106882,
    SPELL_JADE_SERPENT_STRIKE = 106841,
    SPELL_JADE_SERPENT_WAVE_SUMMON_CONTROLLER = 106995,
    SPELL_JADE_SERPENT_KICK = 106864,
    SPELL_DEATH_SIPHON = 116783,
    SPELL_SUMMON_JADE_SERPENT = 106895,
    SPELL_JADE_SOUL = 106909,

    SPELL_JADE_SERPENT_HEALTH = 106924,
    SPELL_SHARED_HEALTH = 114711,
    SPELL_TRANSFORM_VISUAL = 74620, //When the dragon is dead, cast this and remove the possess aura.
    SPELL_JADE_FIRE = 107045,
    SPELL_JADE_FIRE_MISSILE = 107098,
    SPELL_JADE_FIRE_SUMMON = 107103,
    SPELL_CLEANSING_BREATH = 132387,

    SPELL_JADE_SERPENT_WAVE_DMG = 118540,

    SPELL_SERPENT_WAVE_SUMMON = 118551,
    SPELL_SERPENT_WAVE_SUMMON_N = 118549,
    SPELL_SERPENT_WAVE_SUMMON_E = 106930,
    SPELL_SERPENT_WAVE_SUMMON_S = 106928,
    SPELL_SERPENT_WAVE_SUMMON_W = 106931,

    SPELL_JADE_SERPENT_WAVE_VISUAL = 107002,
    SPELL_SERPENT_WAVE_VISUAL = 106939,
    SPELL_SERPENT_WAVE_PERIODIC = 106959,
    SPELL_JADE_SERPENT_WAVE_PERIODIC = 107054,
    SPELL_JADE_SERPENT_WAVE_STALKER_PERIODIC = 106879,
    SPELL_JADE_SERPENT_WAVE = 119508,
    SPELL_SERPENT_WAVE = 106938,

    SPELL_JADE_FIRE_PERIODIC = 107108,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2,
    PHASE_THREE = 3,
};

enum Events
{
    EVENT_SERPENT_STRIKE = 1,
    EVENT_SERPENT_KICK = 2,
    EVENT_SERPENT_WAVE = 3,

    EVENT_JADE_SERPENT_STRIKE = 4,
    EVENT_JADE_SERPENT_KICK = 5,
    EVENT_JADE_SERPENT_WAVE = 6,

    EVENT_SUMMON_YULON = 7,
    EVENT_JADE_FIRE = 8,
    EVENT_JADE_TARGET = 9,
    EVENT_ADD_AURA = 10,
    EVENT_SUMMON_MOVE = 11,
    EVENT_REACH_TRIGGER = 12,
};

enum Texts
{
    TALK_AGGRO = 1,
    TALK_PHASE_TWO = 2,
    TALK_PHASE_THREE = 3,
    TALK_DEATH_LIU = 4,
    TALK_DEATH_YULON = 5,
};

enum Creatures
{
    NPC_TRIGGER_JADE_FIRE_PERIODIC = 56893,
    NPC_LIU_FLAMEHEART = 56732,
    NPC_WAVE_CONTROLER = 56789,
    NPC_YULON = 56762,
    NPC_TRIGGER_TARGET = 999564, // local 999561
    NPC_MINION_OF_DOUBT = 57109,
};


void AddSC_boss_liu_flameheat()
{
   
}
