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
#include "court_of_stars.h"
#include "ScriptedGossip.h"
#include "Conversation.h"

enum Says
{
    SAY_AGGRO = 2,
    SAY_MAELSTROM = 3,
    SAY_BLADE = 4,
    SAY_KILL = 5,
    SAY_EVADE = 6,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_PIERCING_GALE = 209628,
    SPELL_SLICING_MAELSTROM = 209676,
    SPELL_BLADE_SURGE = 209602,
    SPELL_WIND_IMAGE = 209614,
    SPELL_SLICING_MAELSTROM_2 = 209741,
    SPELL_ENVELOPING_WINDS_FILTER = 224327,
    SPELL_ENVELOPING_WINDS_AT = 224330,
    SPELL_ENVELOPING_WINDS_STUN = 224333,
};

enum eEvents
{
    EVENT_PIERCING_GALE = 1,
    EVENT_SLICING_MAELSTROM = 2,
    EVENT_BLADE_SURGE = 3,
    EVENT_ENVELOPING_WINDS = 4,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const groupCheckPos[4] =
{
    {938.15f, 3147.17f, 52.24f},
    {931.61f, 3171.08f, 49.57f},
    {947.74f, 3202.11f, 22.57f},
    {973.10f, 3166.68f, 22.57f},
};

uint32 const pathId[4] =
{
    9100408,
    9100407,
    9100406,
    9100405
};

void AddSC_boss_advisor_melandrus()
{
    
}
