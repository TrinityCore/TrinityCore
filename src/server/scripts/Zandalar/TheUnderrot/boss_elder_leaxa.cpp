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
#include "the_underrot.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "CreatureAI.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_TAINT_OF_GHUUN = 260685,
    SPELL_BLOOD_BOLT = 260879,

    SPELL_CREEPING_ROT = 260894,
    SPELL_CREEPING_ROT_TARGET_SELECTOR = 260889,
    SPELL_CREEPING_ROT_TRIGGER = 261496,
    SPELL_CREEPING_ROT_DOT = 261498,
    SPELL_CREEPING_ROT_VISUAL = 260891,

    SPELL_SANGUINE_FEAST_TARGET_SELECTOR = 264747,
    SPELL_SANGUINE_FEAST_CAST = 264757,
    SPELL_SANGUINE_FEAST_JUMP = 264753,

    SPELL_BLOOD_MIRROR = 264603,
    SPELL_BLOOD_MIRROR_MISSILE = 264609,
    SPELL_BLOOD_MIRROR_VISUAL = 272385,
};

enum Events
{
    EVENT_BLOOD_BOLT = 1,
    EVENT_CREEPING_ROT = 2,
    EVENT_BLOOD_MIRROR = 3,
    EVENT_SANGUINE_FEAST = 4,
};

enum Timers
{
    TIMER_BLOOD_BOLT = 4 * IN_MILLISECONDS,

    TIMER_BLOOD_MIRROR = 16 * IN_MILLISECONDS,
    TIMER_BLOOD_MIRROR_AFTER = 30 * IN_MILLISECONDS,

    TIMER_CREEPING_ROT = 15 * IN_MILLISECONDS,

    TIMER_SANGUINE_FEAST = 10 * IN_MILLISECONDS,
    TIMER_SANGUINE_FEAST_AFTER = 30 * IN_MILLISECONDS,
};

enum Sounds
{
    SOUND_ROT = 101026,
    SOUND_AGGRO = 101028,
    SOUND_KILL = 101029,
    SOUND_DEATH = 101030,
    SOUND_MIRROR = 101025,
    SOUND_FEAST = 101028,
};

enum Creatures
{
    BOSS_ELDER_LEAXA = 131318,

    NPC_CREEPING_ROG_TRIGGER = 132398,
    NPC_BLOOD_EFFIGY = 134701,
};

const Position centerPlatform = { 868.98f, 1230.07f, 56.30f }; //cheaters 23y

#define AGGRO_TEXT "For de glory of G'huun!"
#define ROT_TEXT "Rot and wither!"
#define KILL_TEXT "Time for de sacrifice!"
#define DEATH_TEXT "My blood for G'huun..."
#define MIRROR_TEXT "G'huun be everywhere!"
#define FEAST_TEXT "For de glory of G'huun!"

void AddSC_boss_elder_leaxa()
{
    
}
