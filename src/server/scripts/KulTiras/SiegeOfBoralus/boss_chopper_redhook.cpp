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
	SAY_HOOK = 0,
	SAY_INCOMING,
	SAY_GORE
};

enum Events
{
	EVENT_GORE_CRASH = 1,
	EVENT_ON_THE_HOOK,
	EVENT_BARRAGE,
};

enum Spells
{
	ON_THE_HOOK = 257459,
	HEAVY_HITTER = 256867,
	GORE_CRASH = 257326,
	MEAT_HOOK_STALKER = 257340,
	MEAT_HOOK_SPAWN_EFFECT = 257342,
	MEAT_HOOK_STUN = 257354,
	BOILING_RAGE = 257650,
};

void AddSC_boss_chopper_redhook()
{
	
}
