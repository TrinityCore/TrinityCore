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
#include "gate_setting_sun.h"

struct StrafPointStruct
{
    uint8 pointIdBeginOutside;
    Position beginOutside;

    uint8 pointIdBegin;
    Position begin;

    uint8 pointIdEnd;
    Position end;

    uint8 pointIdOutside;
    Position outside;
};

enum eMovements
{
    POINT_NORTH_START = 1,
    POINT_SOUTH_START = 2,
    POINT_WEST_START = 3,
    POINT_EAST_START = 4,

    POINT_NORTH_END = 5,
    POINT_SOUTH_END = 6,
    POINT_WEST_END = 7,
    POINT_EAST_END = 8,

    POINT_NORTH_OUTSIDE = 9,
    POINT_SOUTH_OUTSIDE = 10,
    POINT_WEST_OUTSIDE = 11,
    POINT_EAST_OUTSIDE = 12,

    POINT_KRIKTHIK_CIRCLE = 13,

    MOV_NORTH_SOUTH = 0,
    MOV_SOUTH_NORTH = 1,
    MOV_WEST_EAST = 2,
    MOV_EAST_WEST = 3
};

StrafPointStruct StrafPoints[4] =
{
    { POINT_NORTH_OUTSIDE, {1258.0f, 2304.644f, 438.0f, 0.0f}, POINT_NORTH_START, {1238.007f, 2304.644f, 435.0f, 0.0f}, POINT_NORTH_END, {1153.398f, 2304.578f, 435.0f, 0.0f}, POINT_SOUTH_OUTSIDE, {1133.4f, 2304.578f, 438.0f, 0.0f} }, // North -> South
    { POINT_SOUTH_OUTSIDE, {1133.4f, 2304.578f, 438.0f, 0.0f}, POINT_SOUTH_START, {1153.398f, 2304.578f, 435.0f, 0.0f}, POINT_SOUTH_END, {1238.007f, 2304.644f, 435.0f, 0.0f}, POINT_NORTH_OUTSIDE, {1258.0f, 2304.644f, 438.0f, 0.0f} }, // South -> North
    { POINT_WEST_OUTSIDE,  {1195.3f, 2366.941f, 438.0f, 0.0f}, POINT_WEST_START,  {1195.299f, 2348.941f, 435.0f, 0.0f}, POINT_WEST_END,  {1195.392f, 2263.441f, 435.0f, 0.0f}, POINT_EAST_OUTSIDE,  {1195.4f, 2243.441f, 438.0f, 0.0f} }, // West  -> East
    { POINT_EAST_OUTSIDE,  {1195.4f, 2243.441f, 438.0f, 0.0f}, POINT_EAST_START,  {1195.392f, 2263.441f, 435.0f, 0.0f}, POINT_EAST_END,  {1195.299f, 2348.941f, 435.0f, 0.0f}, POINT_WEST_OUTSIDE,  {1195.3f, 2366.941f, 438.0f, 0.0f} }  // East  -> West
};

Position CenterPos = { 1195.0f, 2304.0f, 438.0f, 0.0f };

enum eSpells
{
    SPELL_PREY_TIME = 106933,
    SPELL_IMPALING_STRIKE = 107047,

    SPELL_STRAFING_RUN = 107342,
    SPELL_STRAFIND_RUN_DMG = 116298,

    SPELL_RIDE_VEHICLE = 46598,

    // Disruptor
    SPELL_BOMB = 115110
};

enum eEvents
{
    EVENT_PREY_TIME = 1,
    EVENT_IMPALING_STRIKE = 2,

    EVENT_DISRUPTOR_BOMBARD = 3
};

enum ePhases
{
    PHASE_MAIN = 1,
    PHASE_NORTH_SOUTH = 2,
    PHASE_WEST_EAST = 3
};

enum eStrafing
{
    STRAF_NONE = 0,
    STRAF_70 = 1,
    STRAF_30 = 2
};

#define MAX_DISRUPTOR   5
#define MAX_STRIKER     10
#define RADIUS_CIRCLE   100.0f

void AddSC_boss_striker_gadok()
{
    
}
