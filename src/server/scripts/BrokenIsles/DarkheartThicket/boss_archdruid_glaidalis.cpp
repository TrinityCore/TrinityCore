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
    SAY_EVENT_BOSS = 0,
    SAY_AGGRO = 1,
    SAY_NIGHTFALL = 2,
    SAY_RAMPAGE = 3,
    SAY_GREIEVOUS = 4,
    SAY_20 = 5,
    SAY_DEATH = 6,
    //event
    SAY_EVENT = 0,
};

enum Spells
{
    SPELL_PRE_GRIEVOUS_LEAP = 197709,
    SPELL_GRIEVOUS_LEAP = 196346,
    SPELL_GRIEVOUS_LEAP_MORPH = 196348,
    SPELL_GRIEVOUS_LEAP_RETURN = 198095,
    SPELL_GRIEVOUS_LEAP_DOT = 196376,
    SPELL_GRIEVOUS_LEAP_AOE_1 = 196354,
    SPELL_GRIEVOUS_LEAP_AOE_2 = 198269,
    SPELL_PRIMAL_RAMPAGE_MORPH = 198360,
    SPELL_PRIMAL_RAMPAGE_KNOCK = 198376,
    SPELL_PRIMAL_RAMPAGE_CHARGE = 198379,
    SPELL_NIGHTFALL = 198400,
    SPELL_NIGHTFALL_DOT = 198408,
    SPELL_SUM_ABOMINATION = 198432, //Mythic

    //Pre-event
    SPELL_VISUAL = 197642,
    //End
    SPELL_TALK = 202882,

    //Abomination
    SPELL_FIXATE = 198477,
    SPELL_NIGHTMARE_DEATH = 210262,
};

enum eEvents
{
    EVENT_PRE_GRIEVOUS_LEAP = 1,
    EVENT_GRIEVOUS_LEAP = 2,
    EVENT_PRIMAL_RAMPAGE = 3,
    EVENT_NIGHTFALL = 4,
};

void AddSC_boss_archdruid_glaidalis()
{
    
}
