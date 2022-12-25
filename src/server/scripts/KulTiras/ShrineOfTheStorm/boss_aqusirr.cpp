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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "shrine_of_the_storm.h"

enum Spells
{
    SPELL_SEA_BLAST = 265001,
    SPELL_CHOKING_BRINE = 264560,
    SPELL_CHOKING_BRINE_MISSILE_SINGLE = 264714,
    SPELL_CHOKING_BRINE_MISSILE_MULTI = 264703,
    SPELL_SURGING_RUSH = 264101,
    SPELL_UNDERTOW = 264144,
    SPELL_GRASP_FROM_THE_DEPTHS = 264477,
    SPELL_GRASP_FROM_THE_DEPTHS_SUMMON = 264522,
    SPELL_GRASP_FROM_THE_DEPTHS_ROOT = 264526,

    SPELL_ERUPTING_WATER = 264903,
    SPELL_DIMINISH = 264899,

    SPELL_EMERGE_VISUAL = 274948,
};

enum Creatures
{
    BOSS_AQUSIRR = 134056,

    NPC_AQUALING = 134828,
    NPC_GRASPING_TENTACLES = 134612,
};

enum Events
{
    EVENT_SEA_BLAST_CHECK = 1,
    EVENT_SURGING_RUSH,
    EVENT_UNDERTOW,
    EVENT_CHOKING_BRINE,

    EVENT_GRASPING_TENTACLES,

    EVENT_SEA_BLAST_CAST,
};
enum Timers
{
    TIMER_SEA_BLAST_CHECK = 2 * IN_MILLISECONDS,
    TIMER_CHOKING_BRINE = 11 * IN_MILLISECONDS,
    TIMER_UNDERTOW = 30 * IN_MILLISECONDS,
    TIMER_SURGING_RUSH = 17 * IN_MILLISECONDS,

    TIMER_GRASPING_TENTACLES = 15 * IN_MILLISECONDS,

    TIMER_SEA_BLAST_CAST = 2 * IN_MILLISECONDS, //adds
};

#define ROOT me->AddUnitState(UNIT_STATE_ROOT)
#define REMOVE_ROOT me->ClearUnitState(UNIT_STATE_ROOT)

const Position centerPlatform = { 3931.72f, -1244.48f, 128.45f }; //also cheaters check 30y

void AddSC_boss_aqusirr()
{
   
}
