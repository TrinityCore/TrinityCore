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

#include "violet_hold_assault.h"

enum Says
{
    SAY_AGGRO = 2,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_FINGER_LASER = 201159, //Delta Finger Laser X-treme!!!
    SPELL_ELEMENTIUM_BOMB = 201240,
    SPELL_OVERLOADED_E_BOMB = 201432,
    SPELL_ROCKET_CHICKEN = 201392,
    SPELL_REINFORCED_ROCKET_CHICKEN = 201438,
    SPELL_MILLIFICENTS_RAGE = 201572,
    SPELL_MILLIFICENTS_ANGRY = 201491,

    //Summons
    SPELL_EXPLOSION = 201291,
    SPELL_DISARMING = 201265,
    SPELL_EJECT_ALL_PASSENGERS = 158747,
    SPELL_SQUIRREL_SEARCH = 201305,
    SPELL_SQUIRREL_CHARGE = 201302,
    SPELL_OVERLOADED = 201434,
    SPELL_OVERLOADED_SUM = 201436,

    SPELL_CHICKEN_SWARM_ROCKETS = 201356,
    SPELL_SWARM_ROCKETS_SEARCH = 201386,
    SPELL_SWARM_ROCKETS_DMG = 201387,
    SPELL_ROCKET_CHICKEN_ROCKET = 201369,
    SPELL_THORIUM_PLATING = 201441,

    //?
    SPELL_MILLIFICENTS_IRE = 208114,
};

enum eEvents
{
    EVENT_FINGER_LASER = 1,
    EVENT_ELEMENTIUM_BOMB = 2,
    EVENT_ROCKET_CHICKEN = 3,

    EVENT_1,
    EVENT_2,
};

enum Misc
{
    DATA_ANGRY,
};

void AddSC_boss_millificient_manastorm()
{
    
}
