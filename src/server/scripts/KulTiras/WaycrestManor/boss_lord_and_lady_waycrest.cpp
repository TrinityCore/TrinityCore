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
#include "GameObject.h"

enum Spells
{
	WRACKING_CHORD_CHANNEL = 268278,
	WRACKING_CHORD_DAMAGE = 268271,
	DISCORDANT_CADENZA_CHANNEL = 268306,
	DISCORDANT_CADENZA_DAMAGE = 268308,
	VITALITY_TRANSFER_DUMMY = 261446,
	WASTING_STRIKE = 261438,
	VIRULENT_PATHOGEN_AURA = 261440,
	VIRULENT_PATHOGEN_EXP = 261441,
	PUTRID_VITALITY = 261447,
	CONTAGIOUS_REMNANTS_MISSILE = 268385,
};

enum Events
{
	EVENT_WRACKING_CHORD = 1,
	EVENT_DISCORDANT_CADENZA,
	EVENT_WASTING_STRIKE,
	EVENT_VIRULENT_PATHOGEN,
	EVENT_CONTAGIOUS_REMNANTS,
};

enum Texts
{
	SAY_INTRO = 0,
	SAY_AGGRO = 6,
	SAY_CADENZA_WARNING = 1,
	SAY_VITALITY_TRANSFER = 2,
	SAY_VIRULENT_PATHOGEN = 1,
	SAY_DEATH_LADY = 4,
};

enum Misc
{
	ENCOUNTER_ID = 2116,
};

void AddSC_boss_lord_and_lady_waycrest()
{
	
}
