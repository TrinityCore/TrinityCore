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
	SOUL_HARVEST = 260512,
	CRUSH = 260508,
	SOUL_THORNS = 260551,
	SOUL_THORNS_SPAWN_EFECT = 267912,
	SOUL_THORNS_MAIN = 267907,
	BURNING_BRUSH_AURA = 260541,
	BURNING_FISTS = 272668,
};

enum Events
{
	EVENT_SOUL_HARVEST = 1,
	EVENT_CRUSH,
	EVENT_SOUL_THORNS,
	EVENT_BURNING_BRUSH,
	EVENT_BURNING_SOUL_KILL
};

enum Texts
{
	SAY_AGGRO = 9,
	SAY_DEATH = 8,
	SAY_THORNS = 1,
	SAY_WARNING_SOUL_THORNS = 2,
	SAY_WARNING_SOUL_HARVEST = 3,
	SAY_FIRE = 7,
};

const Position burning_soul_pos = { -409.0f, -261.0f, 234.0f, 3.0f };

void AddSC_boss_soulbound_goliath()
{
	
}
