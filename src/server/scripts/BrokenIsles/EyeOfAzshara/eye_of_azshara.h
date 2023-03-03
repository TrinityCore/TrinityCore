/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_EYE_OF_AZSHARA_H
#define DEF_EYE_OF_AZSHARA_H

#define EoAScriptName "instance_eye_of_azshara"
#define DataHeader    "EOA"

uint32 const EncounterCount = 5;

enum EOADataTypes
{
	DATA_PARJESH = 0,
	DATA_LADY_HATECOIL = 1,
	DATA_SERPENTRIX = 2,
	DATA_KING_DEEPBEARD = 3,
	DATA_WRATH_OF_AZSHARA = 4,

	DATA_LADY_INTRO = 5,
	DATA_WRATH_INTRO = 6,
	DATA_RITUAL_EVENT = 7,

	DATA_ARCANIST_DIED = 8,
	DATA_RESPAWN_DUNES = 9,
	DATA_BOSS_DIED = 10,
	DATA_NAGA_DIED = 11,
	DATA_CRY_OF_WRATH = 12
};

enum EOACreatureIds
{
	BOSS_PARJESH = 91784,
	BOSS_LADY_HATECOIL = 91789,
	BOSS_SERPENTRIX = 91797,
	BOSS_KING_DEEPBEARD = 91808,
	BOSS_WRATH_OF_AZSHARA = 96028,

	NPC_HATECOIL_ARCANIST = 97171,

	NPC_RITUALIST_LESHA = 100248,
	NPC_CHANNELER_VARISZ = 100249,
	NPC_BINDER_ASHIOIS = 100250,
	NPC_MYSTIC_SSAVEH = 98173,

	NPC_WATER_SPOUT = 103674, // Not sure

	NPC_WEATHERMAN = 97063
};

enum EOAGameObjectIds
{
	GO_SAND_DUNE = 244690,
	GO_WATER_DOOR = 246983
};

enum EOASpellIds
{
	SPELL_TEMPEST_ATTUNEMENT = 193491,
	SPELL_AQUA_SPOUT_MISSILE = 195212,
	SPELL_FEEDBACK = 196035,
	SPELL_WATER_SPOUT_AT = 195539,
	SPELL_WATER_SPOUT_DAMAGE = 195541,
	SPELL_MASSIVE_QUAKE_AT = 195828,
	SPELL_MASSIVE_QUAKE_DAMAGE = 195832,
	SPELL_ARMORSHELL_SHRAPNEL = 196183,

	SPELL_VIOLENT_WINDS_90S = 191792,
	SPELL_VIOLENT_WINDS_30S = 191805,
	SPELL_VIOLENT_WINDS_10S = 192649,
	SPELL_VIOLENT_WINDS_DUMMY = 191797,

	SPELL_LIGHTNING_STRIKES = 192796, // Cast on a player
	SPELL_LIGHTNING_STRIKES_5S = 192737, // Triggers 192796 every 5 sec
	SPELL_LIGHTNING_STRIKES_AMBIENT = 192728, // Visual only, launched every 250ms (on what? seems to be random coordinates)

	SPELL_SKYBOX_RAIN = 191815,
	SPELL_SKYBOX_WIND = 212614,
	SPELL_SKYBOX_LIGHTNING = 191816,
	SPELL_SKYBOX_HURRICANE = 212615,
};

#endif // EYE_OF_AZSHARA_H_
