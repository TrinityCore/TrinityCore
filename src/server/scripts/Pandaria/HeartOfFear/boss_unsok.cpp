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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "heart_of_fear.h"

enum eUnsokSpells
{
    // --- Un'sok ---
    SPELL_AMBER_SCALPEL = 121994,
    SPELL_CONCENTRATED_MUTATION = 122556,
    SPELL_DRAW_POWER = 122547,
    SPELL_PARASITIC_GROWTH = 121949,
    SPELL_RESHAPED = 122784,
    SPELL_AMBER_CARAPACE = 122540,
    SPELL_VOLATILE_AMBER = 123014,
    SPELL_GROW = 122555,
    SPELL_UNSOK_BERSERK = 26662,

    // --- Adds ---
    SPELL_FIXATE = 122477,
    SPELL_LIVING_AMBER_DEBUFF = 64481,
    SPELL_PERMANENT_FEIGN_DEATH = 70628,    // Can't resurrect
    SPELL_TEMP_FEIGN_DEATH = 126009,   // Can resurrect
    SPELL_RESURRECT = 58854,
    SPELL_CLEAR_DEBUFF = 34098,
    SPELL_BURNING_AMBER = 122503,   // Create a burning amber area, triggers 122504 dealing damages

    // --- Mutated Construct ---
    SPELL_CONSUME_AMBER = 123156,
    SPELL_AMBER_EXPLOSION = 122398,
    SPELL_MUTATED_EXPLOSION = 122402,
    SPELL_MUTATED_SLAM = 122960,

    // --- Amber Monstruosity ---
    SPELL_MASSIVE_STOMP = 122408,
    SPELL_MSTR_EXPLOSION = 122402,
    SPELL_RIDE_MONSTRUOSITY = 43671,
    SPELL_GRAB = 122415,
    SPELL_FLING = 122413,
    SPELL_FLING_FLYING = 122420,
    SPELL_FLING_LANDING = 122457,

    // --- Amber Pool Stallker ---
    SPELL_BUBBLING_AMBER = 122977,
    SPELL_POOL_DRAW_POWER = 122551,
    SPELL_BURNING_POOL = 123020,
    SPELL_HEAL_MUTATED = 123198,

    // --- Amber Globule ---
    SPELL_AMBER_GLOBULE = 125498,
    SPELL_AMBER_BEACON = 125502,
    SPELL_AMBERGEDDON = 125508,

    SPELL_UNSOK_BONUS = 132198
};

enum eUnsokEvents
{
    EVENT_UNSOK_BERSERK = 1,
    EVENT_AMBER_SCALPEL,
    EVENT_PARASITIC_GROWTH,
    EVENT_RESHAPE_LIFE,
    EVENT_RESHAPE_ACTIVE,
    EVENT_VOLATILE_AMBER,
    EVENT_AMBER_RESURRECT,
    EVENT_CHECK_MUTATED,
    EVENT_AMBER_EXPLOSION,
    EVENT_MASSIVE_STOMP,
    EVENT_GRAB,
    EVENT_FLING,
    EVENT_GROW,
    EVENT_DRAW_POWER,
    EVENT_AMBER_GLOBULE,
    EVENT_BERSERK,
    EVENT_SCALPEL_DESPAWN
};

enum eUnsokTalk
{
    TALK_INTRO = 0,
    TALK_AGGRO = 1,
    TALK_SCALPEL = 2,
    TALK_RESHAPE = 3,
    TALK_RESHAPE2 = 4,
    TALK_PHASE2 = 5,
    TALK_PHASE3 = 6,
    TALK_SLAY = 7,
    TALK_DEATH = 8
};

enum eUnsokActions
{
    ACTION_UNSOK_LAST_PHASE = 1,
    ACTION_AMBER_POOL,
    ACTION_END_POOL,
    ACTION_AMBER_CONSUMED,
    ACTION_LAUNCH_LAST_PHASE
};

enum eUnsokAdds
{
    NPC_AMBER_SCALPEL = 62510,
    NPC_LIVING_AMBER = 62691,
    NPC_MUTATED_CONSTRUCT = 62701,
    NPC_AMBER_MONSTRUOSITY = 62711,
    NPC_AMBER_POOL_STALKER = 62762,
    NPC_AMBER_GLOBULE = 64283
};

enum eUnsokTypes
{
    TYPE_GET_SCALPEL_TARGET = 1
};

Position spawnAmberMonstruosity = { -2549.87f, 770.0f, 582.92f, 0.0f };
Position roomCenter = { -2479.44f, 700.0f, 580.10f, 0.0f };

Position poolPositionsTab[4] =
{
    {-2409.33f, 630.0f, 582.92f, 0.0f},
    {-2549.87f, 770.0f, 582.92f, 0.0f},
    {-2409.33f, 770.0f, 582.92f, 0.0f},
    {-2549.87f, 630.0f, 582.92f, 0.0f}
};

void AddSC_boss_unsok()
{
    
}
