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
#include "darkheart_thicket.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NIGHTMARE = 1,
    SAY_CRUSHING = 2,
    SAY_ROOTS = 3,
    SAY_EARTH = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_CANCEL_DEEP_ROOTS = 165953, //Remove 165950
    SPELL_SHATTERED_EARTH = 204666,
    SPELL_STRANGLING_ROOTS = 204574,
    SPELL_STRANGLING_ROOTS_AT = 199067,
    SPELL_NIGHTMARE_BREATH = 204667,
    SPELL_CRUSHING_GRIP = 204611,
    //Heroic
    SPELL_UPROOT = 212786,

    //end
    SPELL_TALK = 202883,
};

enum eEvents
{
    EVENT_SHATTERED_EARTH = 1,
    EVENT_STRANGLING_ROOTS = 2,
    EVENT_NIGHTMARE_BREATH = 3,
    EVENT_CRUSHING_GRIP = 4,
    EVENT_REMOVE_PASSENGERS = 5,
    //Heroic
    EVENT_UPROOT = 6,
};

void AddSC_boss_oakheart()
{
    
}
