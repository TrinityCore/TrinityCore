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
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"

enum Spells
{
	// Warlord Parjesh
	SPELL_ENERGIZE = 202143,
	SPELL_CRASHING_WAVE_CAST = 191900,
	SPELL_CRASHING_WAVE_DMG = 191919,
	SPELL_CRASHING_WAVE_CHARGE = 191902,
	SPELL_QUICKSAND = 192053,
	SPELL_QUICKSAND_AT = 192041,
	SPELL_QUICKSAND_5_YARDS = 192040,
	SPELL_QUICKSAND_10_YARDS = 192042,
	SPELL_QUICKSAND_15_YARDS = 192043,
	SPELL_QUICKSAND_20_YARDS = 192046,
	SPELL_QUICKSAND_25_YARDS = 192047,
	SPELL_IMPALING_SPEAR = 191946,
	SPELL_IMPALING_SPEAR_MARK = 192094,
	SPELL_IMPALING_SPEAR_KNOCK = 193183,
	SPELL_IMPALING_SPEAR_DMG = 191977,
	SPELL_IMPALING_SPEAR_ADD = 191975,
	SPELL_THROW_SPEAR = 192131,
	SPELL_CALL_REINFORCEMENTS = 196563,
	SPELL_CALL_REINFORCEMENTS_M = 192072, // Summon The melee add
	SPELL_CALL_REINFORCEMENTS_C = 192073, // Summon the caster add
	SPELL_ENRAGE = 197064,
	SPELL_EMPTY_ENERGY = 202146,

	// HateCoil ShellBreaker
	SPELL_BELLOWING_ROAR = 192135,
	SPELL_MOTIVATED = 197495,

	// HateCoil Crestrider
	SPELL_LIGHTING_STRIKE = 192138,
	SPELL_RESTORATION = 197502,
};

enum Events
{
	// Warlord Parjesh
	EVENT_CALL_REINFORCEMENTS = 1,
	EVENT_THROW_SPEAR = 2,
	EVENT_IMPALING_SPEAR = 3,
	EVENT_CRASHING_WAVE = 4,

	// Hatecoil ShellBreaker
	EVENT_BELLOWING_ROAR = 5,

	// Hatecoil Crestrider
	EVENT_LIGHTING_STRIKE = 6,
	EVENT_RESTORATION = 7,
};

enum Timers
{
	TIMER_CRASHING_WAVE = 30 * IN_MILLISECONDS,
	TIMER_IMPALE = 5 * IN_MILLISECONDS,
	TIMER_CALLING_REINFORCEMENTS = 5 * IN_MILLISECONDS,
	TIMER_CALLING_REINFORCEMENTS_AFTER = 20 * IN_MILLISECONDS,
	TIMER_THROW_SPEAR = 15 * IN_MILLISECONDS,

	TIMER_BELLOWING_ROAR = 10 * IN_MILLISECONDS,
	TIMER_RESTORATION = 15 * IN_MILLISECONDS,
	TIMER_LIGHTING_STRIKE = 3 * IN_MILLISECONDS,
};
enum Creatures
{
	BOSS_WARLORD_PARJESH = 91784,

	NPC_HATECOIL_SHELLBREAKER = 97264,
	NPC_HATECOIL_CRESTRIDER = 97269,
};

enum Says
{
	SAY_INTRO = 0,
	SAY_AGGRO = 1,
	SAY_REINFORCEMENTS = 2,
	SAY_IMPALING_SPEAR = 3,
	SAY_ENRAGE = 4,
	SAY_KILL = 5,
	SAY_DEATH = 6,
};

enum SoundIds
{
	SOUND_1 = 54181,
	SOUND_2 = 54182,
	SOUND_3 = 0, // will update asap i will find it
	SOUND_4 = 54185,
	SOUND_5 = 54187,
	SOUND_6 = 54184,
};

enum AreaTriggers
{
	AREA_CRASHING_WAVE_MOVE = 4863,
	AREA_CRASHING_WAVE_DMG = 4888,
};

#define AGGRO_TEXT "Ah, we meet again, weakling. Now it's just you and me... and my guards!"
#define DEATH_TEXT "You can't stop.... the storm..."
#define INTRO_TEXT "Hmph. Intruders. They will not get far."
#define IMPALE_TEXT "Like fish in a net."
#define REINFORCEMENTS_TEXT "Ha, nowhere to hide!"
#define KILL_TEXT "Useless. All of you!"

void AddSC_boss_warlord_parjesh()
{
	
}
