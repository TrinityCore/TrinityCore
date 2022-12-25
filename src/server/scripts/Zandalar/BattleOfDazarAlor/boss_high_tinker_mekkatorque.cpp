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
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "VehicleDefines.h"
#include "battle_of_dazaralor.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_DEPLOY_SPARK_BOT,
    SAY_BUSTER_CANNON,
    SAY_GIGAVOLT_CHARGE,
    SAY_BLAST_OFF,
    SAY_WORLD_ENLARGER,
    SAY_STAGE_TWO_BEGINS,
    SAY_HYPERDRIVE,
    SAY_STAGE_THREE_BEGINS,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{
    SPELL_ELECTROSHOCK_STRIKES_DUMMY = 289696,
    SPELL_ELECTROSHOCK_AMPLIFICATION_STACK = 289699,
    SPELL_BUSTER_CANNON_CAST_DUMMY = 287851,
    SPELL_BUSTER_CANNON_DAMAGE = 282182,
    SPELL_BUSTER_CANNON_CREATE_AT = 282153,
    SPELL_HEAVY_THRUSTERS_DUMMY = 284145,
    SPELL_BLAST_OFF = 282205,
    SPELL_CRASH_DOWN = 282245,
    SPELL_CRASH_DOWN_DAMAGE = 283394,
    SPELL_GIGAVOLT_CHARGE = 286646, // 2 tar, on heroic/myth 3
    SPELL_GIGAVOLT_BLAST = 283411,
    SPELL_SHRINK = 284219,
    SPELL_TRAMPLE = 284214,
    SPELL_DEPLOY_SPARK_BOT = 284042, //npc 144942
    SPELL_SPARK_PULSE = 282408,
    SPELL_GNOMISH_FORCE_SHIELD = 282401,
    SPELL_ANTI_TAMPERING_SHOCK = 286480,
    SPELL_SIGNAL_EXPLODING_SHEEP = 287929, //npc 148450
    SPELL_CRITTER_EXPLOSION = 287877,
    SPELL_SHEEP_SHRAPNEL_DAMAGE = 287891,
    SPELL_CRITTER_EXPLOSION_CREATE_AT = 287885,
    SPELL_HYPERDRIVE = 286051,
    //Heroic
    SPELL_WIND_UP = 287293,
    SPELL_WOUND_UP = 287297,
    SPELL_WORMHOLE_GENERATOR_DUMMY_CAST = 287952,
    SPELL_WORMHOLE_GENERATOR_VISUAL = 288232,
    SPELL_WORMHOLE_GENERATOR_TELEPORT = 287226,
};

enum Events
{
    EVENT_ELETROSHOCK_STRIKES = 1,
    EVENT_BUSTER_CANNON,
    EVENT_HEAVY_THRUSTERS,
    EVENT_GIGAVOLT_CHARGE,
    EVENT_SHRINK,
    EVENT_DEPLOY_SPARK_BOT,
    EVENT_SIGNAL_EXPLODING_SHEEP,
    EVENT_HYPERDRIVE,
    EVENT_PHASE_TWO,
    EVENT_PHASE_THREE,
    EVENT_WORLD_ENLARGER,
    //Heroic
    EVENT_WORMHOLE_GENERATOR,
};

const Position gnomish_support_claw_a = { -1588.186f, 789.644f, 126.965f, 0.0f };
const Position gnomish_support_claw_b = { -1605.073f, 788.459f, 126.965f, 0.0f };
const Position gnomish_support_claw_c = { -1605.872f, 816.764f, 126.965f, 0.0f };

void AddSC_boss_high_tinker_mekkatorque()
{
   
}
