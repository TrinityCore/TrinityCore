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
#include "shadopan_monastery.h"
#include "Vehicle.h"

enum eSpells
{
    // Snowdrift

    SPELL_CHASE_DOWN = 118961,
    SPELL_FIST_OF_FURY = 106853,
    SPELL_PARRY_STANCE = 106454,
    SPELL_QUIVERING_PALM = 106422,
    SPELL_TORNADO_KICK = 106434,

    SPELL_SMOKE_BOMB = 110444,

    // Novices

    // Flagrant Lotus
    SPELL_BALL_OF_FIRE = 113760,
    SPELL_BALL_OF_FIRE_DAMAGE = 106470,
    SPELL_FLYING_KICK = 106439,

    SPELL_CALL_STAFF = 106681,
    SPELL_RELEASE_STAFF = 106680,

    // Flying Snow
    SPELL_WHIRLING_STEEL_FOCUS = 106699,
    SPELL_WHIRLING_STEEL_DAMAGE = 106646,

    // Both
    SPELL_FLARE = 132951
};

enum eEvents
{
    // Snowdrift
    EVENT_FIRST_EVENT = 1,
    EVENT_CHECK_WIPE = 2,

    EVENT_CHASE_DOWN = 3,
    EVENT_FIST_OF_FURY = 4,
    EVENT_PARRY_STANCE = 5,
    EVENT_QUIVERING_PALM = 6,
    EVENT_TORNADO_KICK = 7,
    EVENT_FIREBALL = 8,
    EVENT_PHASE_3 = 9,

    EVENT_DISAPPEAR = 10,
    EVENT_DISAPPEAR_TWO = 11,

    // Miniboss
    EVENT_BALL_OF_FIRE = 12,
    EVENT_FLYING_KICK = 13,
    EVENT_CALL_STAFF = 14,
    EVENT_RELEASE_STAFF = 15,

    EVENT_WHIRLING_STEEL_FOCUS = 16,
    EVENT_WHIRLING_STEEL_CHANGE = 17,
    EVENT_WHIRLING_STEEL_STOP = 18
};

enum ePhases
{
    PHASE_FIRST_EVENT = 1,
    PHASE_FIGHT_1 = 2,
    PHASE_FIGHT_2 = 3,
    PHASE_FIGHT_3 = 4
};

enum ePoints
{
    POINT_BEGIN_EVENT = 1,
    POINT_PHASE_FIGHT = 2,

    POINT_NOVICE_JUMP = 3,
    POINT_NOVICE_DEFEATED = 4,
    POINT_NOVICE_DEFEATED_SECOND = 5,

    POINT_MINIBOSS_JUMP = 6,
    POINT_MINIBOSS_DEFEATED = 7
};

Position SnowdriftPos[2] =
{
    {3680.56f, 3045.27f, 816.20f},
    {3713.60f, 3091.87f, 817.31f}
};

Position InitiateSpawnPos[5] =
{
    {3708.56f, 3039.60f, 816.28f},
    {3699.19f, 3049.62f, 816.28f},
    {3688.03f, 3055.68f, 816.28f},
    {3675.10f, 3066.98f, 816.28f},
    {3668.95f, 3070.81f, 816.28f}
};

Position MinibossSpawnPos[2] =
{
    {3683.72f, 3053.94f, 816.28f},
    {3687.77f, 3051.30f, 816.28f}
};

Position ClonePos[3] =
{
    {3683.37f, 3087.65f, 815.70f, 0.0f},
    {3719.41f, 3062.31f, 815.70f, 1.88f},
    {3718.04f, 3097.97f, 817.40f, 4.06f}
};

#define defaultrand urand(1000, 10000)

void AddSC_boss_master_snowdrift()
{
   
}
