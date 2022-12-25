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
#include "the_arcway.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 2,
    SAY_BOMB = 3,
    SAY_TIME = 4,
    SAY_TIME_EMOTE = 5,
    SAY_TIME_REM = 6,
    SAY_EVADE = 8,
    SAY_DEATH = 9,
};

enum Spells
{
    SPELL_ACCELERATING_BLAST = 203176,
    SPELL_CHRONO_SHARDS = 203254,
    SPELL_FORCE_BOMB = 202974,
    SPELL_FORCE_BOMB_AT = 202975,
    SPELL_FORCE_BOMB_AT_2 = 203090,
    SPELL_BANISH_IN_TIME_STUN = 203922,
    SPELL_BANISH_IN_TIME_AT = 203882,
    SPELL_BANISH_IN_TIME_TP = 203883,
    SPELL_BANISH_IN_TIME_TIMER = 203914,
    SPELL_BANISH_IN_TIME_REMOVE = 203941,
    SPELL_UNSTABLE_MANA = 220871,
    SPELL_TIME_SPLIT = 203833,
    SPELL_PULSE_VISUAL = 203835,
};

enum eEvents
{
    EVENT_A_BLAST = 1,
    EVENT_CHRONO_SHARDS = 2,
    EVENT_FORCE_BOMB = 3,
    EVENT_BANISH_IN_TIME = 4,
    EVENT_UNSTABLE_MANA = 5,
    EVENT_1,
    EVENT_2,
};

Position const tpPos[4] =
{
    {3134.70f, 4892.10f, 617.64f, 2.86f},
    {3151.23f, 5109.96f, 623.22f, 2.06f},
    {3154.38f, 4661.42f, 574.20f, 2.95f},
    {3327.04f, 4523.76f, 570.80f, 3.25f}
};

Position const wraithPos[12] =
{
    {3202.04f, 4863.76f, 619.78f, 5.94f},
    {3214.42f, 4990.87f, 624.14f, 1.79f},
    {3237.84f, 4626.11f, 575.03f, 2.78f},
    {3244.24f, 4937.37f, 619.45f, 3.66f},
    {3263.59f, 4879.47f, 619.14f, 0.64f},
    {3323.22f, 4962.37f, 619.30f, 0.0f},
    {3348.97f, 4608.84f, 550.74f, 6.01f},
    {3413.84f, 4714.62f, 590.55f, 0.0f},
    {3415.29f, 4962.56f, 598.39f, 0.0f},
    {3432.10f, 4775.44f, 590.94f, 0.70f},
    {3451.70f, 4640.10f, 567.34f, 1.53f},
    {3467.79f, 4543.19f, 571.34f, 0.03f}
};

void AddSC_boss_advisor_vandros()
{
    
}
