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

#include "crucible_of_storms.h"
#include "Position.h"
#include "Common.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "SpellAuraDefines.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"

enum Spells
{
	//Relic visual
	SPELL_TRIDENT_OF_DEEP_OCEAN = 282171,
	SPELL_VOID_STONE = 282158,
	SPELL_TEMPEST_CALLER = 282162,

	SPELL_ENVELOPING_DARKNESS = 287876,
	SPELL_PACT_OF_THE_RESTLESS = 282675,

	SPELL_POWER_OVERWHELMING = 282914,

	// Fathuul
	SPELL_SHEAR_MIND = 282384,
	SPELL_VOID_CRASH_BIG = 282395,
	SPELL_VOID_CRASH_MIDDLE = 285412,
	SPELL_VOID_CRASH_SMALL = 285411,

	SPELL_CRUSHING_DOUBT = 282432,
	SPELL_CRUSHING_DOUBT_DAMAGE = 282437,

	// Zaxash
	SPELL_APHOTIC_BLAST = 283524,
	SPELL_APHOTIC_BLAST_HC = 282386,

	SPELL_CEREBRAL_ASSAULT = 282589,
	SPELL_DARK_HERALD = 282561,
	SPELL_PROMISES_OF_POWER = 282562,

	// Relics
	SPELL_EMBRACE_OF_THE_VOID = 282738,
	SPELL_UMBRAL_SHELL = 284722,

	SPELL_CUSTODY_OF_THE_DEEP = 282750,
	SPELL_ABYSSAL_COLLAPSE = 282886,
	SPELL_CUSTODY_OF_THE_DEEP_AT = 286701,

	SPELL_STORM_OF_ANNIHILATION = 282743,
	SPELL_ANNIHILATE = 282842,

	SPELL_ELDRITCH_REVELATION = 282617,
	SPELL_ELDRITCH_REVEATION_SUMMON = 282619,

	SPELL_VISAGE_FROM_BEYOND = 282515,
	SPELL_VISAGE_FROM_BEYOND_ADD = 287817,

	SPELL_WITNESS_THE_END = 282621,
	SPELL_WITNESS_THE_END_HC = 283540,
	SPELL_WITNESS_THE_END_AURA = 291580,

	SPELL_TERRIFYING_ECHO = 282517,
	SPELL_COALESCE_VOID = 282524,

	SPELL_AGENT_OF_DEMISE = 282540,
	SPELL_WRACK = 292880,
	SPELL_INCOMPLETE_FORM = 282630,

	SPELL_OCEANIC_ESSENCE_STUN = 293488,
	SPELL_OCEANIC_ESSENCE_VISUAL = 293475,
	SPELL_OCEANIC_ESSENCE_AT = 293478,
	SPELL_SPAWN_VISUAL = 293489, // !?
	SPELL_OCEANIC_ESSENCE_MISSILE = 293465,

	SPELL_STORM_ESSENCE = 293300,

	SPELL_VOID_ESSENCE_PERIODIC = 293461,
	SPELL_VOID_ESSENCE = 293514,
};

enum Events
{
	EVENT_ENRAGE = 1,

	EVENT_SHEAR_MIND,
	EVENT_VOID_CRASH,
	EVENT_CRUSHING_DOUBT,

	EVENT_CEREBRAL_ASSAULT,
	EVENT_APHOTIC_BLAST,
	EVENT_DARK_HERALD,

	EVENT_SUMMON_ELDRITCH,
	EVENT_SUMMON_VISAGE,

	EVENT_WITNESS_THE_END,
	EVENT_TERRIFYING_ECHO,

	EVENT_KILL,
	EVENT_KILL_2,

	EVENT_VOID_ESSENCE,
	EVENT_OCEANIC_ESSENCE,
	EVENT_STORM_ESSENCE,
	EVENT_CUSTODY_OF_THE_DEEP,
};

enum Action
{
	ACTION_RELIC_ACTIVATED = 1,
};

enum Timers
{
	TIMER_ENRAGE = 9 * MINUTE,

	TIMER_SHEAR_MIND = 5 * IN_MILLISECONDS,
	TIMER_VOID_CRASH = 25 * IN_MILLISECONDS,
	TIMER_CRUSHING_DOUBT = 30 * IN_MILLISECONDS,

	TIMER_DARK_HERALD = 40 * IN_MILLISECONDS,
	TIMER_APHOTIC_BLAST = 5 * IN_MILLISECONDS,
	TIMER_CEREBRAL_ASSAULT = 25 * IN_MILLISECONDS,

	TIMER_VOID_ESSENCE = 40 * IN_MILLISECONDS,
	TIMER_OCEANIC_ESSENCE = 6 * IN_MILLISECONDS,
	TIMER_STORM_ESSENCE = 20 * IN_MILLISECONDS,
};

enum Creatures
{
	BOSS_FATHUUL_THE_FEARED = 144754,
	BOSS_ZAXASJ_THE_SPEAKER = 144755,

	NPC_TRIDENT_OF_DEEP_OCEAN_RELIC = 144809,
	NPC_VOID_STONE_RELIC = 147572,
	NPC_TEMPEST_CALLER_RELIC = 147573,

	NPC_OCEANIC_ESSENCE = 151412,

	NPC_OCEAN_RUNE = 147762,

	NPC_ELDRITCH_ABOMINATION = 145053,
	NPC_VISAGE_FROM_BEYOND = 144996,
};

const Position centerPos = { 3631.75f, -1729.25f, 85.65f }; // 60y

const Position relicPos[3] =
{
	{3629.13f, -1761.63f, 85.65f + 5.0f },
	{3662.89f, -1711.87f, 85.72f + 5.0f },
	{3610.93f, -1700.21f, 85.65f + 5.0f },
};

#define ZAX_AGGRO "Embrace the master's truth!"
#define FATHUUL_SHEAR_MIND "Cower before his might!"
#define ZAX_TEMPEST "You are but rubble in the storm's wake!"
#define FATHUUL_TEMPEST "Quake in fear of his endless strenght!"
#define ZAX_VOID "All will be consumed!"
#define FATHUUL_VOID "Tremble before his hunger! His darkness!"
#define ZAX_OCEAN "Your pathetic existence will be washed away!"
#define FATHUUL_OCEAN "You will drown in your terror!"
#define FATHUUL_PACT "Master! Grantme strenght!"
#define ZAX_PACT "He...will yet...claim you..."

void AddSC_bfa_boss_restless_cabal()
{
	
}
