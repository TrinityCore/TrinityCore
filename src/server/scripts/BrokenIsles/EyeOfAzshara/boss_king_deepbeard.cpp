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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"

enum Spells
{
	SPELL_CALL_OF_SEAS = 193051,
	SPELL_CALL_OF_SEAS_AURA = 193054,
	SPELL_CALL_OF_SEAS_DMG = 193055,
	SPELL_QUAKE = 193152,
	SPELL_QUAKE_DMG = 193159,
	SPELL_AFTERSHOCK = 193167,
	SPELL_GASEOUS_BUBBLE = 193018,
	SPELL_GASEOUS_EXPLOSION = 193047,
	SPELL_GROUND_SLAM = 193093,
	SPELL_GROUND_SLAM_DMG = 193056,
	SPELL_FRENZY = 197550,
};

enum Events
{
	EVENT_CALL_OF_SEAS = 1,
	EVENT_QUAKE = 2,
	EVENT_GASEOUS_BUBBLES = 3,
	EVENT_GROUND_SLAM = 4,
	EVENT_ADD_ENERGY,
};

enum Timers
{
	TIMER_CALL_OF_SEAS = 30 * IN_MILLISECONDS,
	TIMER_QUAKE = 28 * IN_MILLISECONDS,
	TIMER_GROUND_SLAM_AFTER = 27 * IN_MILLISECONDS,
	TIMER_ADD_ENERGY = 1 * IN_MILLISECONDS,
	TIMER_GASEOUS_BUBBLE_AFTER = 28 * IN_MILLISECONDS,
	TIMER_GROUND_SLAM = 7 * IN_MILLISECONDS,
	TIMER_GASEOUS_BUBBLE = 10 * IN_MILLISECONDS,
};
enum Adds
{
	BOSS_KING_DEEPBEARD = 91797,

	NPC_QUAKE = 97916,
	NPC_CALL_OF_THE_SEA = 97844,
};

const Position CenterPos = { -3447.563f, 4176.818f, 29.186f }; // also cheaters check

enum SoundIds
{
	SOUND_1 = 54316, // aggro
	SOUND_2 = 54310, // call seas
	SOUND_3 = 54315, // quake
	SOUND_4 = 54332, // kill
	SOUND_5 = 54313, // bubble
	SOUND_6 = 54319, // death
};

#define AGGRO_TEXT "You weaklings will drown beneath these waves!"
#define CALL_OF_SEAS_TEXT "Seas! Obey my command!"
#define QUAKE_TEXT "The earth trembles before the rising tide!"
#define KILL_TEXT "This was a inevitable as the tides, fools."
#define GASEOUS_BUBBLE_TEXT "Pity you cannot survive without air!"
#define DEATH_TEXT "I... I've failed... But my queen will not..."

void AddSC_boss_king_deepbeard()
{

}
