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
#include "ScriptMgr.h"
#include "SpellHistory.h"
#include "shrine_of_the_storm.h"

enum Spells
{
    SPELL_COSMETIC_REINFORCING_WARD = 274690,
    SPELL_HINDERING_CLEAVE = 267899,
    SPELL_REINFORCING_WARD = 267905,
    SPELL_REINFORCING_WARD_DMG_DEC = 267904,
    SPELL_REINFORCING_WARD_REMOVE_NEG = 267952,
    SPELL_BLESSING_OF_IRONSIDES = 267901,

    SPELL_BLESSING_OF_THE_TEMPEST = 267830,
    SPELL_SLICING_BLAST = 267818,
    SPELL_SWIFTNESS_WARD = 267891,
    SPELL_SWIFTNESS_WARD_BUFF = 267888,
    SPELL_COSMETIC_SWIFTNESS_WARD = 274689,
    SPELL_BLOWBACK = 267842,
    SPELL_BLOWBACK_VISUAL = 267836,
    SPELL_BLOWBACK_DMG = 267838,

    SPELL_PERMANENT_FEIGN_DEATH = 70628,
};

enum Creatures
{
    BOSS_BROTHER_IRONHULL = 134063,
    BOSS_GALECALLER_FAYE = 134058,

    NPC_BLOWBACK = 136314,
};

enum Events
{
    EVENT_HINDERING_CLEAVE = 1,
    EVENT_REINFORCING_WARD,

    EVENT_SWIFTNESS_WARD,
    EVENT_SLICING_BLAST,

    EVENT_REGEN_MANA,

    EVENT_BLOWBACK_MOVEMENT,

    EVENT_BLESSING_OF_IRONSIDE,
    EVENT_BLESSING_OF_THE_TEMPEST,
};

enum Timers
{
    TIMER_REINFORCING_WARD = 1 * IN_MILLISECONDS,
    TIMER_SWIFTNESS_WARD = 1 * IN_MILLISECONDS,

    TIMER_REGEN_MANA = 2 * IN_MILLISECONDS, // both use this

    TIMER_HINDERING_CLEAVE = 18 * IN_MILLISECONDS,
    TIMER_SLICING_BLAST = 5 * IN_MILLISECONDS,

    TIMER_BLESSING_OF_IRONSIDE = 32 * IN_MILLISECONDS,
    TIMER_BLESSING_OF_THE_TEMPEST = 20 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_FINISH_OTHER = 1,
};

#define IRONHULL_AGGRO "The tides shall take you!"
#define IRONHULL_WARD "My hull is impenetrable"

#define FAYE_WARD "The breeze is ever at your backs!"
#define FAYE_BLOWBACK "Winds, protect me!"
#define FAYE_DEATH "The clouds... break..."

const Position centerPos = { 3939.35f, -1007.21f, 109.22f }; // cheaters

uint8 CouncilActive(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* ironhull = instance->GetCreature(BOSS_BROTHER_IRONHULL);
    if (ironhull && ironhull->IsAlive())
        ++count;

    Creature* faye = instance->GetCreature(BOSS_GALECALLER_FAYE);
    if (faye && faye->IsAlive())
        ++count;

    return count;
}

void AddSC_boss_tidesage_council()
{
    
}
