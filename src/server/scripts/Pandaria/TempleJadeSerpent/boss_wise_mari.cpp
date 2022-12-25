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
#include "ScriptedCreature.h"

enum eBoss
{
    BOSS_WASE_MARI = 1,
};
enum eSpells
{
    SPELL_WATER_BUBBLE = 106062,
    SPELL_CALL_WATER = 106526,
    SPELL_CORRUPTED_FOUTAIN = 106518,
    SPELL_SHA_RESIDUE = 106653,
    SPELL_HYDROLANCE_PRECAST = 115220,
    SPELL_HYDROLANCE_DMG_BOTTOM = 106267,
    SPELL_HYDROLANCE_VISUAL = 106055,
    SPELL_HYDROLANCE_DMG = 106105,
    SPELL_WASH_AWAY = 106331,
    SPELL_BUBBLE_BURST = 106612,
};
enum eTexts
{
    TALK_AGGRO = 1,
    TALK_SPELL_CALL_WATER = 2,
    TALK_WATER = 3,
    TALK_DEATH = 4,
    TALK_PHASE_TWO = 5,
};
enum eEvents
{
    EVENT_CALL_WATER = 1,
    EVENT_HYDROLANCE = 2,
    EVENT_HYDROLANCE_START = 3,
    EVENT_SWITCH_PHASE_TWO = 4,
    EVENT_WASH_AWAY = 5,

    EVENT_CALL_WATER_2 = 6,
    EVENT_CALL_WATER_3 = 7,
    EVENT_CALL_WATER_4 = 8,

    EVENT_PHASE_TWO_SEARCHER = 9,
};
enum eCreatures
{
    CREATURE_FOUTAIN_TRIGGER = 56586,
    CREATURE_CORRUPT_DROPLET = 62358,
    CREATURE_HYDROLANCE_BOTTOM_TRIGGER = 56542,
    NPC_CORRUPTED_LIVING_WATER = 56511, // 59873
    NPC_CORRUPTED_WATER_TRIGGER = 999057,
};
enum eTimers
{
    TIMER_CALL_WATTER = 15000,
    TIMER_HYDROLANCE_START = 10000,
    TIMER_HYDROLANCE = 5500,
    //TIMER_SWITCH_PHASE_TWO = 15000,
    TIMER_WASH_AWAY = 125,
};
enum hydrolancePhase
{
    HYDROLANCE_BOTTOM = 1,
    HYDROLANCE_LEFT = 2,
    HYDROLANCE_RIGHT = 3,
};
static const float fountainTriggerPos[4][3] =
{
    { 1022.743f, -2544.295f, 173.7757f },
    { 1023.314f, -2569.695f, 176.0339f },
    { 1059.943f, -2581.648f, 176.1427f },
    { 1075.231f, -2561.335f, 173.8758f },
};
static const float hydrolanceLeftTrigger[5][3] =
{
    { 1061.411f, -2570.721f, 174.2403f },
    { 1058.921f, -2573.487f, 174.2403f },
    { 1055.910f, -2575.674f, 174.2403f },
    { 1052.511f, -2577.188f, 174.2403f },
    { 1048.871f, -2577.961f, 174.2403f },
};
static const float hydrolanceRightTrigger[5][3] =
{
    { 1035.333f, -2573.693f, 174.2403f },
    { 1032.795f, -2570.971f, 174.2403f },
    { 1030.878f, -2567.781f, 174.2403f },
    { 1029.667f, -2564.263f, 174.2403f },
    { 1029.213f, -2560.569f, 174.2403f },
};

void AddSC_boss_wise_mari()
{
    
}
