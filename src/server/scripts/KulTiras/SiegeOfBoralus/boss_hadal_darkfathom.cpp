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

const Position pos = { };

enum Texts
{
	SAY_AGGRO = 0,
	SAY_DEATH = 1,
};

enum Events
{
	EVENT_BREAK_WATER = 1,
};

enum Spells
{
	CRASHING_TIDE_SS = 261563,
	CRASHING_TIDE_MISSILE = 261564,
	BREAK_WATER_SS = 257882,
	BREAK_WATER_MISSILE = 257884,
	TIDAL_SURGE_SS = 276068,
	TIDAL_SURGE_CREATE_AT = 276039, //at 14062
	TIDAL_SURGE_KNOCKBACK = 276042,
	TIDAL_SURGE_CREATE_AT_TWO = 276047, //at 14065
	TIDAL_SURGE_APPLY_AURA_FROM_AT = 279962, // at 14062
	TIDAL_SURGE_KC = 290586
};

void AddSC_boss_hadal_darkfathom()
{
	
}
