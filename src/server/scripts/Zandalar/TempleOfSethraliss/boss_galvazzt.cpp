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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_CONSUME_CHARGE = 266512,
    SPELL_CAPACITANCE = 266511,
    SPELL_INDUCTION = 265974,
    //Energy core
    SPELL_BEAM = 265973,
    SPELL_ENERGY_CORE_VISUAL = 265977,
    SPELL_SUMMON_ENERGY_CORE = 274006,
    SPELL_ARC = 265986,
    SPELL_GALVANIZE = 266923,
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_ENERGY_CORE,
    EVENT_INDUCTION,

    EVENT_CHECK_INBETWEEN,
};

enum Timers
{
    TIMER_CHECK_ENERGY = 1 * IN_MILLISECONDS,
    TIMER_ENERGY_CORE = 15 * IN_MILLISECONDS,
    TIMER_INDUCTION = 5 * IN_MILLISECONDS,

    TIMER_CHECK_INBETWEEN = 1 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_GALVAZZT = 133389,
    NPC_ENERGY_CORE_BFA = 135445,
};

const Position centerPos = { 3704.30f, 3412.07f, 6.75f }; //30y

void AddSC_boss_galvazzt()
{
   
}
