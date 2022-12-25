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
	TENDERIZE = 264923,
	TENDERIZE_DAMAGE = 262371,
	CONSUME_ALL = 264734,
	CALL_SERVANT = 264931,
	CONSUME_SERVANT_INSTAKILL = 265002,
	CONSUME_SERVANT_BUFF = 265005,
	ROTTEN_EXPULSION = 264694,
	ROTTEN_EXPULSION_MISSILE = 264697,
	ROTTEN_EXPULSION_AT = 264698 , // at 12821
	ROTTEN_EXPULSION_AT_AURA = 264712,
	ROTTEN_EXPULSION_SUMMON = 268231,
	BILE_EXPOLOSION
};

enum Events
{
	EVENT_TENDERIZE = 1,
	EVENT_CONSUME_ALL,
	EVENT_CALL_SERVANT,
	EVENT_ROTTEN_EXPULSION,
	EVENT_CHECK_RANGE,
	EVENT_NO_HOSTILES
};

enum Texts
{
	SAY_AGGRO = 0,
	SAY_WARNING_SERVANT = 1,
	SAY_SERVANT = 2,
	SAY_DEATH = 3,
};

const Position servant_left_pos = { -461.0f, -330.0f, 237.0f, 3.1f };
const Position servant_middle_pos = { -481.0f, -308.0f, 237.0f, 4.7f };
const Position servant_right_pos = { -525.0f, -330.0f, 237.0f, 0.0f };
const Position bile_oozeling_pos = { -493.0f, -328.0f, 236.0f, 4.69f };

void AddSC_boss_raal_the_gluttonous()
{
	
}
