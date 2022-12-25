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
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "terrace_of_endless_spring.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "Pet.h"
#include "Group.h"

enum eTsulongEvents
{
    EVENT_NONE,
    EVENT_FLY,
    EVENT_WAYPOINT_FIRST,
    EVENT_WAYPOINT_SECOND,
    EVENT_SWITCH_TO_NIGHT_PHASE,
    EVENT_BERSERK,
    // night phase
    EVENT_SPAWN_SUNBEAM,
    EVENT_SHADOW_BREATH,
    EVENT_DARK_OF_NIGHT,
    EVENT_NIGHTMARES,
    EVENT_DARK_AURA,
    // day phase
    EVENT_SUMMON_TERROR,
    EVENT_SUMMON_SHA,
    EVENT_SUN_BREATH,
    EVENT_EVADE_CHECK,

    EVENT_TSULONG_ENRAGE,
};

enum eTsulongSpells
{
    SPELL_DREAD_SHADOWS = 122767,
    SPELL_DREAD_SHADOWS_DEBUFF = 122768,
    SPELL_SUNBEAM_DUMMY = 122782,
    SPELL_SUNBEAM_PROTECTION = 122789,
    SPELL_NIGHT_PHASE_EFFECT = 122841,
    SPELL_SHADOW_BREATH = 122752,
    SPELL_NIGHTMARES = 122775,
    SPELL_NIGHTMARES_EFF = 122770,
    SPELL_SHA_ACTIVE = 122438, // night phase regen

    // day phase
    SPELL_GOLD_ACTIVE = 122453, // day phase regen and model
    SPELL_SUN_BREATH = 122855,
    SPELL_SUN_BREATH_PLAYER = 122858,
    SPELL_SUMMON_EMBODIED_TERROR = 122995, // 62969
    SPELL_SUMMON_SHA_PERIODIC = 122946,
    SPELL_SUMMON_SHA_PERIODIC_EFF = 122952,
    SPELL_SUMMON_SHA_MISSILE = 122953, // 62919
    SPELL_UNLEASHED_SHA_EXPLOSION = 130008,

    // Heroic mode
    SPELL_THE_DARK_OF_NIGHT = 123739,
    SPELL_DARK_FIXATE_AURA = 123740,
    SPELL_DARK_EXPLOSION = 130013,

    SPELL_LIGHT_OF_DAY_BUFF = 123716,
    SPELL_LIGHT_OF_DAY_AURA = 123816,

    SPELL_TSULONG_ENRAGE = 26662,
    SPELL_TSULONG_ACHIEVEMENT_MARKER = 123901,
};

enum eTsulongTimers
{
    TIMER_FIRST_WAYPOINT = 5000, // 5 secs for test, live : 120 000
};

enum eTsulongPhase
{
    PHASE_NONE,
    PHASE_FLY,
    PHASE_DAY,
    PHASE_NIGHT
};

enum eTsulongWaypoints
{
    WAYPOINT_FIRST = 10001,
    WAYPOINT_SECOND = 10002
};

enum eTsulongDisplay
{
    DISPLAY_TSULON_NIGHT = 42532,
    DISPLAY_TSULON_DAY = 42533,

    FACTION_DAY = 2104,
    FACTION_NIGHT = 1965,
};

enum eTsulongActions
{
    ACTION_SPAWN_SUNBEAM = 10,
    ACTION_REGEN_COMPLETE,
};

enum eTsulongCreatures
{
    SUNBEAM_DUMMY_ENTRY = 62849,
    NPC_THE_DARK_OF_THE_NIGHT = 63346,
};

enum
{
    SPELL_TERRORIZE = 123011,
    SPELL_TERRORIZE_TSULONG = 123012,
    SPELL_TINY_TERROR = 123038,
    SPELL_TINY_TERROR_EFF = 123026,
    SPELL_SUMMON_TINY_TERROR = 123508
};

void AddSC_boss_tsulong()
{
    
}
