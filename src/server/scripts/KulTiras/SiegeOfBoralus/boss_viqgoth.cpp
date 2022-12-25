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
#include "TaskScheduler.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"

enum JainaTexts
{
	SAY_OUTRO_1 = 0,
	SAY_OUTRO_2 = 1
};

enum Misc
{
	ENCOUNTER_ID = 2100,
};

enum Events
{
	EVENT_ERADICATION = 1,
	EVENT_PUTRID_WATERS,
	EVENT_CHECK_PLAYERS,
};

enum Spells
{
	TERROR_FROM_BELOW_SCREEN_EFFECT = 279897,
	ERADICATION_MISSILE = 269456,
	PUTRID_WATERS = 275014,
	PUTRID_WATERS_EXP = 275051,
	BLAST_SS = 269416,
	BLAST_MISSILE = 269420,
};

void AddSC_boss_viqgoth()
{
	
}
