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
#include "GameObjectAI.h"
#include "GameObject.h"

enum Spells
{
	SPELL_ARCANE_SHIELDING = 197868,
	SPELL_STATIC_NOVA = 193597,
	SPELL_BECKON_STORM = 193682,
	SPELL_BECKON_STORM_SUMMON = 193683,
	SPELL_FOCUSED_LIGHTNING = 193611,
	SPELL_EXCESS_LIGHTING_PLAYER = 193624,
	SPELL_EXCESS_LIGHTING_SAND = 193625,
	SPELL_CRACKLING_THUNDER = 197326,
	SPELL_CURSE_OF_WITCH_AURA = 193698,
	SPELL_CURSE_OF_WITCH_KNOCK = 193700,
	SPELL_CURSE_OF_WITCH_KILL = 193720,
	SPELL_MONSOON = 196630,

	SPELL_WATERY_SPLASH = 193636,

	SPELL_SAND_DUNE = 193060,
	SPELL_SAND_DUNE_SUMMON = 193061,

	// Monsoon
	SPELL_MONSOON_VISAL = 196609,
	SPELL_MONSOON_DMG = 196610,

	// Hatecoil Arcanist
	SPELL_AQUA_SPOT = 196027,
	SPELL_ARCANE_REBOUND = 196028,
	SPELL_POLYMORPH = 197105,
	SPELL_ARCANE_ALIGNMENT = 197115,
	SPELL_ARCANE_FORTIFICATION = 199865,
};

enum Npcs
{
	BOSS_LADY_HATECOIL = 91789,

	NPC_SALTSEA_GLOBULE = 98293,
	NPC_SAND_DUNE = 97853,
	NPC_MONSOON = 99852,
};

enum Objects
{
	GO_SAND_DUNE = 244690,
};

enum Timers
{
	TIMER_BECKON_STORM = 19 * IN_MILLISECONDS,
	TIMER_BECKON_STORM_AFTER = 40 * IN_MILLISECONDS,
	TIMER_CURSE_OF_WITCH = 16 * IN_MILLISECONDS,
	TIMER_CURSE_OF_WITCH_AFTER = 25 * IN_MILLISECONDS,
	TIMER_STATIC_NOVA = 11 * IN_MILLISECONDS,
	TIMER_CRACKLING_THUNDER_CHECK = 2 * IN_MILLISECONDS,

	TIMER_MONSOON_AFTER = 25 * IN_MILLISECONDS,
	TIMER_MONSOON = 50 * IN_MILLISECONDS,
};

enum Sounds
{
	SOUND_1 = 54194, // aggro
	SOUND_2 = 54201, // static nova
	SOUND_3 = 54204, // beckon storm
	SOUND_4 = 54203, // focused lightning 
	SOUND_5 = 54202, // cuse of witch
	SOUND_6 = 54195, // death
	SOUND_7 = 54199, // kilL
};

#define AGGRO_TEXT "Continue the rituals! I will handle these fools"
#define STATIC_NOVA_TEXT "Just you wait..."
#define BECKON_STORM_TEXT "The waters rise..."
#define FOCUSED_LIGHTNING_TEXT "A storm is gathering..."
#define CURSE_OF_WITCH_TEXT "There is no escape!"
#define DEATH_TEXT "Can you feel the winds? They come for you"
#define KILL_TEXT "The Hatecoil proves superior!"

enum Events
{
	EVENT_STATIC_NOVA = 1,
	EVENT_BECKON_STORM = 2,
	EVENT_FOCUSED_LIGHTING = 3,
	EVENT_CRACKLING_THUNDER = 4,
	EVENT_CURSE_OF_WITCH = 5,
	EVENT_MONSOON = 6,

	EVENT_AQUA_SPOT = 7,
	EVENT_ARCANE_REBOUND = 8,
	EVENT_POLYMORPH = 9,
};

const Position ArenaCenter = { -3439.963f, 4589.192f, -0.4387f };

void AddSC_boss_lady_hatecoil()
{
	
}
