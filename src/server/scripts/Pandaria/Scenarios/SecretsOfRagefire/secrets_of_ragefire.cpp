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

#include "secrets_of_ragefire.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_FUSE = 140896,
    SPELL_TWISTED_ELEMENTS = 142296,
    SPELL_GLACIAL_FREEZE_TOTEM = 142320,
    SPELL_RUINED_EARTH = 142306,
    SPELL_RUINED_EARTH_SELECTOR = 142307,
    SPELL_RUINED_EARTH_SUMM = 142308,
    SPELL_RUINED_EARTH_SUMM_2 = 142309,
    SPELL_RUINED_EARTH_SUMM_3 = 142316,
    SPELL_RUINED_EARTH_VISUAL = 142310,
    SPELL_RUINED_EARTH_EFF = 142311,
    SPELL_GLACIAL_FREEZE = 142321,
    SPELL_GLACIAL_FREEZE_EFF = 142322,
    SPELL_LAVA_BURST = 142338,
    SPELL_POISON_BOLT_TOTEM = 142339,
    SPELL_EMBERSTRIKES = 142406,
    SPELL_EMBERSTRIKES_EFF = 142407,
    SPELL_POOL_OF_EMBERS = 142413,
    SPELL_SHADOW_STEP = 80576,
    SPELL_HUGE_EXPLOSION = 141954,
    SPELL_DEMOLISH_ARMOR = 142764,
    SPELL_DIRE_RAGE = 142760,
    SPELL_ATTACH_EGG_YOLK = 141891,
    SPELL_ATTACH_POOL_PONY = 141889,
    SPELL_ATTACH_BATTERY_1 = 141887,
    SPELL_ATTACH_BATTERY_2 = 141888,
    SPELL_ATTACH_CANNON_BALL_1 = 141879,
    SPELL_ATTACH_CANNON_BALL_2 = 141880,
    SPELL_ATTACH_CANNON_BALL_3 = 141881,
    SPELL_POISON_BOLT = 142345,
    SPELL_FLAME_BREATH = 142745,
    SPELL_SHATTERING_STOMP = 142771,
    SPELL_SHATTERED_EARTH = 142766,
    SPELL_SHATTERED_EARTH_EFF = 142768,
};

enum Events
{
    EVENT_TWISTED_ELEMENTS = 1,
    EVENT_GLACIAL_FREEZE_TOTEM,
    EVENT_RUINED_EARTH,
    EVENT_LAVA_BURST,
    EVENT_POISON_BOLT_TOTEM,
    EVENT_EMBERSTRIKES,
    EVENT_SHADOWSTEP,
    EVENT_DEMOLISH_ARMOR,
    EVENT_DIRE_RAGE,
    EVENT_FLAME_BREATH,
    EVENT_SHATTERING_STOMP,
};

void AddSC_secrets_of_ragefire()
{
    
}