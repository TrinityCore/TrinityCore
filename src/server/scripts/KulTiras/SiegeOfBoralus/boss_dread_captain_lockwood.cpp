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
#include "siege_of_boralus.h"
#include "ScriptedGossip.h"

const Position lockwood_home_pos = { 620.0f, -245.0f, 12.58f, 1.0f };
const Position lockwood_withdraw_pos = { 662.0f, -245.0f, 11.06f, 3.25f };
const Position deckhand_door_pos = { 656.0f, -227.0f, 1100.0f, 4.78f };
const Position deckhand_2_pos = { 671.0f, -245.0f, 1100.0f, 3.23f };
const Position cannoneer_pos = { 671.0f, -242.0f, 1098.0f, 3.23f };

const Position summons_pos = { 641.0f, -244.0f, 12.0f, 3.30f };

enum Texts
{
	SAY_AGGRO = 0,
	SAY_GUT,
	SAY_CANNON,
	SAY_WITHDRAW,
	SAY_CLEAR,
	SAY_ADS,
	SAY_DEATH,
	SAY_WIPE,
};

enum Events
{
	EVENT_SHOOT = 1,
	EVENT_GUT_SHOT,
	EVENT_CLEAR_THE_DECK,
	EVENT_WITHDRAW,
	EVENT_DREAD_VOLLEY,
	EVENT_CANNON_BARRAGE,
	EVENT_EVASIVE,
	EVENT_RANGE
};

enum Spells
{
	EVASIVE = 272471,
	LOCKWOOD_SHOOT = 280389, // random every 2.5s
	GUT_SHOT = 273470, // random
	CLEAR_THE_DECK = 269029, //tank
	WITHDRAW = 268752, // at 100 energy

	DREAD_VOLLEY_CHANNEL = 268933,
	DREAD_VOLLEY_GROUND_MARK = 268940,
	DREAD_VOLLEY_MISSILE = 268944,

	UNSTABLE_ORDNACE_SUMMON = 268963,
	UNSTABLE_ORDNACE = 268995,
	UNSTABLE_ORDNACE_EXP = 269015,
};

void AddSC_boss_dread_captain_lockwood()
{
	
}
