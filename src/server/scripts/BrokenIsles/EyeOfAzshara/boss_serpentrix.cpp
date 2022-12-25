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
#include "ScriptedCreature.h"

enum Spells
{
	// Serpentrix
	SPELL_TOXIC_WOUND = 191855,
	SPELL_TOXIC_PUDDLE = 191858,
	SPELL_POISON_SPIT = 192050, //cast
	SPELL_POISON_SPIT_TRIGGER = 191839, // xyz marker
	SPELL_POISON_SPIT_DMG_1 = 191841, //damage xyz
	SPELL_POISON_SPIT_DMG_2 = 191843,
	SPELL_POISON_SPIT_DMG_3 = 191845,
	SPELL_SUMERGE = 191873,
	SPELL_RAMPAGE = 191848,
	SPELL_RAMPAGE_TRIGGER = 191850,
	SPELL_HYDRA_HEAD = 202680,
	SPELL_HYDRA_HEAD_HIDE = 180898,

	// Blazing Hydra Spawn
	SPELL_BLAZING_NOVA = 192003,

	// Arcane Hydra Spawn
	SPELL_ARCANE_BLAST = 192005,
	SPELL_ARCANE_CHARGE = 192007,
};

enum Events
{
	EVENT_TOXIC_WOUND = 1,
	EVENT_POISON_SPIT = 2,
	EVENT_ACTIVATE_HEADS = 3,
	EVENT_RAMPAGE = 4,

	EVENT_ARCANE_BLAST,
	EVENT_BLAZING_NOVA,
};

enum Creatures
{
	BOSS_SERPENTRIX = 91797,

	NPC_BLAZING_HYDRA = 97259,
	NPC_ARCANE_HYDRA = 97260,
	NPC_SINK_HOLE = 97263,
};

enum Timers
{
	TIMER_ARCANE_BLAST = 3 * IN_MILLISECONDS,
	TIMER_BLAZING_NOVA = 3 * IN_MILLISECONDS,

	TIMER_TOXIC_WOUND = 25 * IN_MILLISECONDS,
	TIMER_POISON_SPIT = 7 * IN_MILLISECONDS,

	TIMER_RAMPAGE_CHECK = 2 * IN_MILLISECONDS,
};

const Position spawnHeadPos[4] =
{
	{ -3256.36f, 4370.39f, 0.37f }, // 2
	{ -3199.39f, 4384.95f, 0.16f }, // 3
	{ -3246.70f, 4479.64f, 0.26f }, // 5
	{ -3294.19f, 4460.52f, -0.63f }, // 6
};

const Position emergeBossPos[2] =
{
	{ -3192.23f, 4440.18f, -0.64f }, // 1
	{ -3304.16f, 4405.52f, 0.08f }, // 2
};

const Position mainHole[1] =
{
	{ -3253.82f, 4428.95f, -1.74f }, // cheaters 95yards check also while reseting 
};

void AddSC_boss_serpentrix()
{
	
}
