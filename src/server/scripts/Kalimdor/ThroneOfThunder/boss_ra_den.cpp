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

#include "throne_of_thunder.h"
#include "Group.h"
#include "SpellAuras.h"

// 7844 world state for heroic attempts

enum Spells
{
    // Shared
    SPELL_MATERIALS_OF_CREATIONS = 138321,
    SPELL_LINGERING_ENERGIES = 138450,

    // Phase 1
    // Vita
    SPELL_IMBUED_WITH_VITA = 138332,
    SPELL_UNLEASHED_VITA = 138330,
    SPELL_FATAL_STRIKE = 138334,
    SPELL_UNSTABLE_VITA = 138297, // used by Ra-den
    SPELL_UNSTABLE_VITA_PLAYER = 138308, // used by players
    SPELL_VITA_SENSIVITY = 138372,
    SPELL_SUMMON_CRACKLING_STALKER = 138339,

    SPELL_UNSTABLE_VITA_VISUAL = 138371,
    SPELL_ANIMA_SENSITIVITY = 139318,
    SPELL_UNSTABLE_VITA_LINE_DAMAGE = 138370,
    // Anima
    SPELL_IMBUED_WITH_ANIMA = 138331,
    SPELL_MURDEROUS_STRIKE = 138333,
    SPELL_SUMMON_SANGUINE_HORROR = 138338,
    SPELL_UNLEASHED_ANIMA = 138329,
    SPELL_UNSTABLE_ANIMA = 138295, // dummy spell
    SPELL_UNSTABLE_ANIMA_VISUAL = 138294, // maybe...
    SPELL_UNSTABLE_ANIMA_PERIODIC = 138288, // player check spell (?)

    // Phase 2
    SPELL_RUIN = 139073,
    SPELL_RUIN_BOLT = 139087,

    SPELL_CALL_ESSENCE = 139040,

    SPELL_CORRUPTED_ANIMA = 139071,
    SPELL_CORRUPTED_VITA = 139072,

    // Crackling Stalker
    SPELL_CRACKLE = 138340,
    SPELL_CAUTERIZING_FLARE = 138337,

    // Sanguine Horror
    SPELL_SANGUINE_VOLLEY = 138341,

    //Achievement
    SPELL_ACHIEVEMENT_RADEN = 140182,
};

enum Creatures
{
    BOSS_RADEN = 69473,

    NPC_SANGUINE_HORROR = 69871,
    NPC_CRACKLING_STALKER = 69872,

    NPC_ESSENCE_OF_ANIMA = 69869,
    NPC_ESSENCE_OF_VITA = 69870,

    NPC_CORRUPTED_ANIMA = 69957,
    NPC_CORRUPTED_VITA = 69958,
};

static const Position CorruptedAnimaPosition[10] =
{
    { 5395.85f, 4678.5f, -2.47899f, 0.830314f }, // 1
    { 5421.87f, 4706.08f, -2.47899f, 0.596266f }, // 2
    { 5458.72f, 4714.56f, -2.47899f, 3.214f }, // 3
    { 5488.01f, 4692.09f, -2.47864f, 2.42468f }, // 4
    { 5504.24f, 4660.64f, -2.47872f, 1.89931f }, // 5
    { 5497.96f, 4629.92f, -2.47872f, 4.15891f }, // 6
    { 5473.94f, 4606.71f, -2.47872f, 0.617544f }, // 7
    { 5445.44f, 4600.93f, -2.47872f, 1.5364f }, // 8
    { 5419.47f, 4611.00f, -2.47872f, 0.900288f }, // 9
    { 5402.13f, 4630.9f, -2.47872f, 0.507587f }, // 10
};

static const Position CorruptedVitaPosition[10] =
{
    { 5457.97f, 4610.82f, -2.47872f + 5.0f, 0.323005f }, // 1
    { 5479.6f, 4622.76f, -2.47637f + 5.0f, 5.55375f }, // 2
    { 5492.19f, 4646.79f, -2.47637f + 5.0f, 1.4846f },  // 3
    { 5488.76f, 4672.49f, -2.47637f + 5.0f, 2.12863f }, // 4
    { 5470.54f, 4694.09f, -2.47887f + 5.0f, 2.68626f }, // 5
    { 5440.5f, 4701.99f, -2.47887f + 5.0f, 3.18734f }, // 6
    { 5414.9f, 4686.82f, -2.47887f + 5.0f, 3.95075f }, // 7
    { 5402.99f, 4655.22f, -2.47887f + 5.0f, 4.75421f }, // 8
    { 5417.78f, 4626.07f, -2.47887f + 5.0f, 5.50427f }, // 9
    { 5434.49f, 4611.88f, -2.47837f + 5.0f, 4.34975f }, // 10
};

enum CorruptedAnimaandVitaPoints
{
    POINT_1 = 1,
    POINT_2,
    POINT_3,
    POINT_4,
    POINT_5,
    POINT_6,
    POINT_7,
    POINT_8,
    POINT_9,
    POINT_10,

    POINT_RADEN = 11,
};

enum Data
{
    DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD = 8089,
};

enum Miscs
{
    DATA_VITA_PHASE = 1,
    DATA_ANIMA_PHASE = 2,
};

enum Achievements
{
    ACHIEVEMENT_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD = 8089,
};

enum Events
{
    EVENT_IMMEDIATE = 1,

    EVENT_ENERGY_REGEN,

    // Sanguine Horror
    EVENT_SANGUINE_VOLLEY,

    // Crackling Stalker
    EVENT_CRACKLE,
    EVENT_CAUTERIZING_FLARE,

    // Ra-den
    EVENT_RUIN_BOLT,
    EVENT_MATERIALS_OF_CREATION,
    EVENT_SELECT_ORB_PHASE_2,
    // anima phase
    EVENT_UNLEASHED_ANIMA,
    EVENT_MURDEROUS_STRIKE,
    EVENT_UNSTABLE_ANIMA,
    EVENT_SUMMON_SANGUINE_HORROR,

    EVENT_REMOVE_SENSITIVITIES,

    //vita phase
    EVENT_SUMMON_CRACKLING_STALKER,
    EVENT_UNSTABLE_VITA,
    EVENT_VITA_FALSE_VARIABLE,
    EVENT_FATAL_STRIKE,
    EVENT_UNLEASHED_VITA,

    // SHARED 1st phase
    EVENT_REFORM_NPC,
    EVENT_CHECK_IF_BOSS_NEARBY,

    // Movement phase 2
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10,

    EVENT_NEAR_RADEN,

    EVENT_KILL,
};

enum Timers
{
    TIMER_SANGUINE_VOLLEY = 8 * IN_MILLISECONDS,
    TIMER_SANGUINE_VOLLEY_SECOND = 2 * IN_MILLISECONDS,

    TIMER_CRACKLE = 10 * IN_MILLISECONDS,

    TIMER_RUIN_BOLT = 2 * IN_MILLISECONDS,
    TIMER_MATERIALS_OF_CREATIONS = 32 * IN_MILLISECONDS,

    TIMER_FATAL_STRIKE = 5 * IN_MILLISECONDS,
    TIMER_ENERGY_REGEN = 4 * IN_MILLISECONDS, // SHARED!
    TIMER_UNLEASHED_VITA = 500, //* IN_MILLISECONDS,
    TIMER_UNSTABLE_VITA = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_CRACKLING_STALKER = 29 * IN_MILLISECONDS,

    TIMER_MURDEROUS_STRIKE = 5 * IN_MILLISECONDS,
    TIMER_UNLEASHED_ANIMA = 500, //* IN_MILLISECONDS,
    TIMER_UNSTABLE_ANIMA = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_SANGUINE_HORROR = 29 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_ANIMA_PHASE = 1,
    ACTION_VITA_PHASE = 2,

    ACTION_MOVE_TO_RADEN = 3,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_MURDEROUS_STRIKE = 2,
    TALK_MATERIALS_OF_CREATIONS = 3,
    TALK_UNSTABLE_VITA = 4,
    TALK_UNSTABLE_ANIMA = 5,
    TALK_PHASE_2 = 6,
    TALK_DEFEAT = 7,
    TALK_BERSERK = 8,
};

void AddSC_bfa_boss_raden()
{
    
}
