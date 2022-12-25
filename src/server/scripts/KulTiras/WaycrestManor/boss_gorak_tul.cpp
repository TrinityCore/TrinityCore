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
#include "waycrest_manor.h"

enum Spells
{
	DARKENED_LIGHTNING = 266225,
	DARKENED_LIGHTNING_2 = 270464,

	SUMMON_DEATH_TOUCHED_SLAVER = 266266,
	SUMMON_DEATH_TOUCHED_SLAVER_MISSILE = 266260,
	DARK_LEAP = 273657,
	DARK_LEAP_2 = 273658,
	DREAD_BOLT = 266460,
	DREAD_ESSENCE = 266181,
	DREAD_ESSENCE_DISPELL = 272829,
	//Heroic+
	DEATH_LENS = 268202,
	DEATH_LENS_PERIODIC = 266724,
};

enum Events
{
	EVENT_DARKENED_LIGHTNING = 1,
	EVENT_DEATHTOUCHED_SLAVER,
	EVENT_DARK_LEAP,
	EVENT_DREAD_BOLT,
	EVENT_DREAD_ESSENCE,
	EVENT_DEATH_LENS,
};

enum Texts
{
	SAY_AGGRO = 0,
	SAY_RISE = 1,
	SAY_DEATH = 2,
};

void AddSC_boss_gorak_tul()
{
	
}
