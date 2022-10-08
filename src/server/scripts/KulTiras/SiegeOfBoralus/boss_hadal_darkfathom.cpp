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

//128651
struct boss_hadal_darkfathom : public BossAI
{
	boss_hadal_darkfathom(Creature* creature) : BossAI(creature, DATA_HADAL_DARKFATHOM) { }

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_MAELSTROM);
		me->SetPower(POWER_MAELSTROM, 0);
	}

	void EnterCombat(Unit* u) override
	{
		_EnterCombat();
		Talk(SAY_AGGRO);
		events.ScheduleEvent(EVENT_BREAK_WATER, 5s);
	}

	void JustDied(Unit* u) override
	{
		_JustDied();
		Talk(SAY_DEATH);
	}

	void ExecuteEvent(uint32 eventid) override
	{
		switch (eventid)
		{
		case EVENT_BREAK_WATER:
		{
			DoCast(BREAK_WATER_SS);
			UnitList tarlist;
			SelectTargetList(tarlist, 5, SELECT_TARGET_RANDOM, 100.0f, true);
			for (Unit* tar : tarlist)
			DoCast(tar, BREAK_WATER_MISSILE, true);
			events.Repeat(15s);
			break;
		}

		default:
			break;
		}
	}
};

void AddSC_boss_hadal_darkfathom()
{
	RegisterCreatureAI(boss_hadal_darkfathom);
}
