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

#include "tomb_of_sargeras.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CALL = 1,
    SAY_DRAW_IN = 2,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_DRAW_IN = 232061, // 
    SPELL_FRIGID_BLOWS = 233429, // 
    SPELL_DRENCHING_SLOUGH = 233526, // dummy
    SPELL_FROSTY_DISCHARGE = 232174, // at end link

    SPELL_UNCHECKED_RAGE = 231854, // 100%
    SPELL_UNCHECKED_RAGE_VICTIM = 247403, // 
    SPELL_CALL_ADDS = 232192, //

    SPELL_CANCEL_DRENCHED = 239926, // link
    SPELL_CHANGE_ENERGY = 241486, //
    SPELL_REGENERATE_ENERGY = 232379, //

    SPELL_ENQUBATION = 240347,
    SPELL_HARDENED_SHELL = 240315,

    SPELL_ENQUBATION_RED = 242027,
    SPELL_ENQUBATION_BLUE = 242030,
    SPELL_ENQUBATION_GREEN = 242031,

    SPELL_ENRAGE = 64238,  //

    SPELL_JAGGED_ABRASION = 231998,

    //achievement npc spells
    SPELL_SONIC_WAVE = 241436,
    SPELL_SPLASH = 241393,
    SPELL_ELDERS_RAGE = 241416,
};

enum eEvents
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_CALL_ADDS,
    EVENT_DRAW_IN,
    EVENT_HATCHING,
    EVENT_HATCHING_CLEAN_UP,

    EVENT_ENRAGE,

    EVENT_ELDER1,
    EVENT_ELDER2,
    EVENT_ELDER3,
};

enum Misc
{
    DATA_COMPLETE,
};

enum Action
{
    ACTION_COMPLETE,
};

Position const addsPos[4]
{
    {5877.17f, -906.50f, 2920.25f, 6.20f},
    {5880.17f, -896.95f, 2920.35f, 5.73f},
    {5889.86f, -886.83f, 2920.35f, 5.42f},
    {5946.16f, -919.47f, 2919.52f, 2.62f}

};

Position const eggsPos[4]
{
    {5915.40f, -876.02f, 2919.83f, 0.0f},
    {5944.42f, -900.28f, 2919.46f, 0.0f},
    {5918.47f, -945.27f, 2919.86f, 0.0f},
    {5882.26f, -920.99f, 2920.99f, 0.0f}
};

uint32 const eggsCasts[3]
{
    SPELL_ENQUBATION_BLUE,
    SPELL_ENQUBATION_RED,
    SPELL_ENQUBATION_GREEN
};

void AddSC_boss_harjatan()
{
    
}
