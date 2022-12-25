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
#include "temple_of_sethraliss.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_EMPOWERMENT = 269670,
    SPELL_LIFE_FORCE = 274149,
    SPELL_CARDIAC_SHOCK = 279015,
    SPELL_LIFE_FORCE_HEAL = 274149,
    SPELL_CHAIN_LIGHTNING = 268061,
    SPELL_SNAKE_CHARM = 268008,
    SPELL_JOLT = 279000,
    SPELL_TAINT_DEBUFF = 267944,
  
    SPELL_TAINT_CHANNEL = 273677,
    SPELL_TAINT_VISUAL = 267759,
    SPELL_HEART_ATTACK = 268007,
  
    SPELL_PULSE = 268024,
    SPELL_PLAGUE = 269686,
    SPELL_SPAWN_FRAGMENT = 278885,
    SPELL_LAVA_BURST = 274642,
    SPELL_FLAME_SHOCK = 268013
};

enum Events
{
    EVENT_SUMMON_TOADS = 1,
    EVENT_SUMMON_HEXER,
    EVENT_SUMMON_GUARDIAN,
    EVENT_SUMMON_DOCTOR,
    EVENT_CHECK_PLAYERS,
    EVENT_PULSE,
    EVENT_CHAIN_LIGHTNING,
    EVENT_SNAKE_CHARM,
    EVENT_CHANNEL,
    EVENT_HEART_ATTACK,
    EVENT_LIGHTNING_STRIKE,
};

enum Timers
{
    TIMER_PULSE = 30 * IN_MILLISECONDS,
    TIMER_LIGHTNING_STRIKE = 15 * IN_MILLISECONDS,

    TIMER_CHECK_PLAYERS = 2 * IN_MILLISECONDS,

    TIMER_SUMMON_TOADS = 25 * IN_MILLISECONDS,
    TIMER_SUMMON_GUARDIAN = 15 * IN_MILLISECONDS,
    TIMER_SUMMON_DOCTOR = 20 * IN_MILLISECONDS,

    TIMER_CHAIN_LIGHTNING = 8 * IN_MILLISECONDS,
    TIMER_SNAKE_CHARM = 25 * IN_MILLISECONDS,
    TIMER_HEART_ATTACK = 5 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_START = 1,
    ACTION_COMPLETE,
};

enum Creatures
{
    BOSS_AVATAR_OF_SETHRALISS = 133392,

    NPC_HOODOO_HEXER_BFA = 136250,
    NPC_PLAGUE_DOCTOR_BFA = 139949,
    NPC_HEART_GUARDIAN_BFA = 139946,
    NPC_PLAGUE_TOAD_BFA = 137233,
    NPC_ENERGY_FRAGMENT_BFA = 142929,
};

Position HoodooPos[4] =
{
    { 4142.10f, 3678.26f, -42.95f },
    { 4167.25f, 3692.94f, -42.95f },
    { 4181.25f, 3668.73f, -42.95f },
    { 4156.75f, 3653.69f, -42.95f },
};

Position ToadPos[5] =
{
    { 4142.10f, 3678.26f, -42.95f },
    { 4167.25f, 3692.94f, -42.95f },
    { 4181.25f, 3668.73f, -42.95f },
    { 4156.75f, 3653.69f, -42.95f },
    { 4168.72f, 3655.34f, -43.25f },
};

#define AVATAR_START "The hex is shattered, but the temple's defenses have awakened!"
#define SECOND_TEXT_AVATAR "Should you fail, I am lost!"
#define AVATAR_COMPLETED "The storm has broken, and I am myself again. Thank you."
#define FIRST_TEXT_AVATAR "Restore me and I will disable them!"

void AddSC_boss_avatar_of_sethraliss()
{
    
}
