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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Creature.h"
#include "ScriptedGossip.h"
#include "CreatureAI.h"
#include "the_underrot.h"

enum Spells
{
    SPELL_BLOOD_BARRIER                     = 269185,
    SPELL_PUTRID_BLOOD_AURA                 = 269303,
    SPELL_PUTRID_BLOOD = 269301,
    SPELL_VILE_EXPULSION                    = 269843,
    SPELL_VILE_EXPULSION_SPORE_DEATH_DAMAGE = 250950,
    SPELL_VILE_EXPULSION_AT_DAMAGE          = 269838,
    SPELL_VILE_EXPULSION_MISSILE_SPAWN      = 269813, // 5 YARDS
    SPELL_VILE_EXPULSION_SPAWN              = 269836,
    SPELL_DISOLVE_CORPSE                    = 265640,
    SPELL_CORPSE_TRANSFORM                  = 265635,
    SPELL_ROTTING_SPORE_SPAWN               = 270104,
    SPELL_ROTTING_SPORE_FIXATE              = 270107,
    SPELL_ROTTING_SPORE_DAMAGE              = 270108,
    // Blood Visage
    SPELL_BLOOD_CLONE_COSMETIC              = 272663,
    SPELL_FATAL_LINK                        = 269692,
    // Titan Keeper Hezrel
    // Pre-boss event
    SPELL_SHADOW_VISUAL                     = 279551,
    SPELL_HOLY_CHANNEL                      = 279250,
    SPELL_OPEN_WEB_DOOR                     = 279271,
    SPELL_UPDATE_INTERACTIONS               = 187114,
    // Boss fight
    SPELL_HOLY_BOLT                         = 269312,
    SPELL_CLEANSING_LIGHT                   = 269310,
    SPELL_PURGE_CORRUPTION                  = 269406,
    SPELL_PERMANENT_FEIGN_DEATH             = 29266,
};

enum Events
{
    EVENT_PUTRID_BLOOD = 1,
    EVENT_VILE_EXPULSION,

    EVENT_CHECK_ENERGY,

    EVENT_CLEANSING_LIGHT,
    EVENT_HOLY_BOLT,
    EVENT_PURGE_CORRUPTION,

    EVENT_FIXATE_FOLLOW,
    EVENT_CHECK_DIST_PLAYER,
    EVENT_FIXATE,
};

enum Timers
{
    TIMER_FIXATE_PLAYER = 1500,
    TIMER_CHECK_ENERGY = 5 * IN_MILLISECONDS,
    TIMER_VILE_EXPULSION = 15 *IN_MILLISECONDS,
    TIMER_PUTRID_BLOOD = 10 * IN_MILLISECONDS,

    TIMER_CLEANSING_LIGHT = 20 * IN_MILLISECONDS,
    TIMER_PURGE_CORRUPTION = 7 * IN_MILLISECONDS,
    TIMER_HOLY_BOLT = 5 * IN_MILLISECONDS,

};

enum Actions
{
    ACTION_COUNT_VISAGE = 1,
    ACTION_COMBAT,
    ACTION_RP_EVENT,
    ACTION_RP_EVENT_2,
    ACTION_RP_EVENT_3,
    ACTION_RP_EVENT_4,
    ACTION_RP_EVENT_5,
    ACTION_RP_EVENT_6,
};

enum Creatures
{
    BOSS_UNBOUND_ABOMINATION = 133007,
}; 

const Position centerPosition = { 1199.420044f, 1481.939941f, -181.505997f };

enum Sounds
{
    SOUND_AGGRO_TITAN = 104794,
    SOUND_AGGRO_UNBOUND = 102970,
    SOUND_UNBOUND_VILE = 102967,
    SOUND_UNBOUND_DEATH = 102966,
    SOUND_TITAN_CLEANSING = 104788,
    SOUND_TITAN_PURGE_CORRUPTION = 104790,
};

enum Points
{
    POINT_1 = 1,
    POINT_2,
    POINT_3,
    POINT_4,
    POINT_5,
    POINT_6,
};

const Position MovementPos[6] =
{
    { 1032.63f, 1144.16f, 14.60f },
    { 981.74f, 1152.87f, 14.34f },
    { 992.49f, 1192.83f, 17.36f },
    { 982.83f, 1235.51f, 14.39f },
    { 1045.11f, 1260.05f, 12.48f },
    { 1097.59f, 1330.80f, 5.81f },
};

#define TITAN_AGGRO "Virulent specimen Detected. Containment priority one."
#define UNBOUND_AGGRO "Devour! Consume! Spread!"
#define UNBOUND_VILE "Infected!"
#define UNBOUND_DEATH "Must... spread..."
#define TITAN_CLEANSING "Cleansing area."
#define TITAN_PURGE_CORRUPTION "Contagion detected. Sanitize."

void AddSC_boss_unbound_abomination()
{
    
}
