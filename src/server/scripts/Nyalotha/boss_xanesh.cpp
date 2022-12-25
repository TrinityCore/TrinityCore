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
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "nyalotha.h"

enum Texts
{
	SAY_AGGRO = 0,
	SAY_SOUL_FLAY,
	SAY_ABYSSAL_STRIKE,
	SAY_TORMENT,
	SAY_VOID_RITUAL,
	SAY_OBELISKS,
};

enum Spells
{
	SPELL_TORMENT_DAMAGE = 311383,
	SPELL_TORMENT_SUMMON_VEHICLE = 305907,
	SPELL_TORMENT_CREATE_AT = 305912,
	SPELL_TORMENT_SCREEN_EFFECT = 305916,
	SPELL_ANQUISH = 305794,
	SPELL_ABYSSAL_STRIKE = 311551,
	SPELL_SOUL_FLY_TRIGGER = 306319,
	SPELL_SOUL_FLY_DEBUFF = 306311,
	SPELL_SOUL_FLY_MISSILE = 306315,
	SPELL_SOUL_FLY = 306228,
	SPELL_VOID_RITUAL = 312336,
	SPELL_VOID_RITUAL_DAMAGE = 313258,
	SPELL_VOID_SHIELD = 314035,
	SPELL_VOIDWOKEN = 312406,
	SPELL_REVILE = 309654,
	SPELL_DARK_COLLAPSE_DAMAGE = 306876,
	SPELL_DARK_ASCENSION = 313264,
	SPELL_FANATICISM = 314179,
	SPELL_VOID_TOUCHED_TRIGGER = 313198,
	SPELL_VOID_ORB_VISUAL = 311591,
	SPELL_GOAL_PORTAL_VISUAL = 312326,
	
	SPELL_DOOM = 314300,
	SPELL_OBELISK_AREA_DENIAL = 306493,
	SPELL_LARGE_OBELISK_AREA_DENIAL = 315494,
	SPELL_SUMMON_RITUAL_OBELISKS = 306495,
	SPELL_RITUAL_FIELD = 305575,
	SPELL_RITUAL_OBELISK_KNOCKBACK = 314297,
	SPELL_IMMINENT_DOOM = 314298,
	SPELL_IMMINENT_DOOM_SCREEN_EFFECT = 314299,
	
	SPELL_TERROR_WAVE = 316211,
	SPELL_BERSERK = 306845,
};

enum Events
{
	EVENT_TORMENT = 1,
	EVENT_ABYSSAL_STRIKE,
	EVENT_SOUL_FLY,
	EVENT_VOID_RITUAL,
	EVENT_OBELISKS,
	EVENT_BERSERK
};

const Position goal_portal_spawn_one = { -559.329f, -342.082f, -251.202f, 1.0f };
const Position goal_portal_spawn_two = { -501.874f, -336.755f, -251.092f, 1.0f };
const Position goal_portal_spawn_three = { -496.966f, -378.767f, -251.133f, 1.0f };
const Position goal_portal_spawn_four = { -551.031f, -382.878f, -251.157f, 1.0f };
const Position void_orb_spawn = { -521.773f, -392.395f, -251.088f, 1.682f };
const Position azshara_pos = { -524.841f, -357.070f, -250.923f, 4.783f };

void AddSC_xanesh()
{
	
};
