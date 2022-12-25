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
#include "tol_dagor.h"
#include <iostream>
using namespace std;

enum Spells {
    SPELL_CINDER_FLAME = 256955,
    SPELL_FUSELIGHTER = 257028,
    //Ignition
    SPELL_IGNITION = 256970,
    SPELL_IGNITION_AREAEFFECT = 256973,

    SPELL_ARMAMENT = 262327,
    SPELL_ARMAMENT_TEST = 263052,

    SPELL_BURNING_ARSENAL = 256710,

    SPELL_PICKING_UP = 265610,
    SPELL_CARRYING_MUNITIONS = 256496,
};

enum Events {
    EVENTS_CINDER_FLAME = 1,
    EVENTS_FUSELIGHTER = 2,
    EVENTS_IGNITION = 3,

    EVENT_DESPAWN = 5,
};

enum Actions {
    ACTION_THROW_BOMB = 0,
};

//todo correct
Position BarrelPositions[]{
    { 60.00f, -2962.62f, 60.92f },
    { 67.81f, -2674.87f, 60.92f },
    { 62.545f, -2682.86f, 60.92f },
    { 71.17f, -2690.06f, 60.83f },
};

void AddSC_boss_knight_captain_valyri()
{
    
}
