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
    SAY_AGGRO = 0,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_VENOM_SPRAY = 202414,
    SPELL_WEB_GRAB = 202462,
    SPELL_FEL_DETONATION = 202473,
    SPELL_TOXIC_BLOOD = 210504,

    //Spider
    SPELL_CREEPING_SLAUGHTER = 202306,
};

enum eEvents
{
    EVENT_VENOM_SPRAY = 1,
    EVENT_WEB_GRAB = 2,
    EVENT_FEL_DETONATION = 3,
    EVENT_PHASE_SPIDER = 4,
    EVENT_TOXIC_BLOOD = 5,

    EVENT_1,
    EVENT_2,
};

void AddSC_boss_saelorn()
{
   
}
