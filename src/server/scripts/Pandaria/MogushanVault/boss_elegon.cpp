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
#include "mogu_shan_vault.h"

enum eElegonPhase
{
    PHASE_1 = 1,
    PHASE_2 = 2,
    PHASE_3 = 3,
    PHASE_FINAL = 4
};

enum eSpells
{
    // Elegon
    SPELL_APPARITION_VISUAL = 127808,

    // Platform
    SPELL_TOUCH_OF_THE_TITANS = 130287,
    SPELL_TOUCH_OF_TITANS_VISUAL = 117874,
    SPELL_ELEGON_OVERCHARGED = 117877,
    SPELL_ELEGON_OVERCHARGED_2 = 117878,

    // Phase 1
    SPELL_CELESTIAL_BREATH = 117960,
    SPELL_MATERIALIZE_PROTECTOR = 117954,
    SPELL_GRASPING_ENERGY_TENDRILS = 127362,
    SPELL_GRASPING_ENERGY_GRIP = 129724,
    SPELL_RADIATING_ENERGIES = 118310,
    SPELL_RADIATING_ENERGIES_VISUAL = 118992,
    SPELL_RADIATING_OUTSIDE_VORTEX = 118313,
    SPELL_RADIATING_INSIDE_VORTEX = 122741,

    // Phase 2
    SPELL_FOCUS_POWER = 119358,
    SPELL_DRAW_POWER_SHORT = 119360,
    SPELL_DRAW_POWER_LONG = 124967,
    SPELL_DRAW_POWER_SUMMONS = 118018,
    SPELL_DRAW_POWER_DEBUFF = 119387,

    // Phase 3
    SPELL_UNSTABLE_ENERGY = 116994,
    SPELL_UNSTABLE_ENERGY_DAMAGE = 116997,
    SPELL_PHASE_SHIFTED = 118921,
    SPELL_OVERLOADED_MISSILE = 116989,
    SPELL_OVERLOADED = 117204,
    SPELL_ENERGY_CASCADE = 122199,
    SPELL_ENERGY_CONDUIT = 116663,

    // Empyreal Focus
    SPELL_FOCUS_INACTIVE = 127303,
    SPELL_FOCUS_ACTIVE = 127305,
    SPELL_FOCUS_ACTIVATION_VISUAL = 118794,
    SPELL_FOCUS_ACTIVATE_STATE = 127305,
    SPELL_FOCUS_LIGHT_AREATRIGGER = 116546,
    SPELL_FOCUS_LIGHT_CASTBAR = 116598,
    SPELL_FOCUS_LIGHT_WALL_VISUAL = 116604,

    // Celestial Protector
    SPELL_TOTAL_ANNIHILATION = 129711,
    SPELL_ARCING_ENERGY = 117945,
    SPELL_STABILITY_FLUX = 117911,
    SPELL_ECLIPSE_NO_PHASE = 117885,
    SPELL_ECLIPSE_PHASE = 117886,
    SPELL_CLOSED_CIRCUIT = 117949,

    // Cosmic Spark
    SPELL_ICE_TRAP = 135382,

    // Energy Charge
    SPELL_CORE_CHECKER = 118024,
    SPELL_CORE_BEAM = 118430,
    SPELL_DISCHARGE = 118299,
    SPELL_HIGH_ENERGY = 118118,

    // Infinite Energy (Intro)
    SPELL_SPAWN_FLASH_1_PERIODIC = 127785,
    SPELL_SPAWN_FLASH_2_PERIODIC = 127783,
    SPELL_SPAWN_FLASH_3_PERIODIC = 127781,

    // Heroic
    SPELL_DESTABILIZING_ENERGIES = 132222,
    SPELL_CATASTROPHIC_ANOMALY = 127341,

    SPELL_ELEGON_BONUS = 132192
};

enum eEvents
{
    // Elegon
    EVENT_CHECK_UNIT_ON_PLATFORM = 1,
    EVENT_CHECK_MELEE = 2,
    EVENT_CELESTIAL_BREATH = 3,
    EVENT_MATERIALIZE_PROTECTOR = 4,

    EVENT_FOCUS_POWER = 5,
    EVENT_DRAW_POWER = 6,

    // Celestial Protector
    EVENT_ARCING_ENERGY = 5,
    EVENT_TOUCH_OF_THE_TITANS = 6,
    EVENT_KILLED = 7,

    // Cosmic Spark
    EVENT_ICE_TRAP = 8,

    EVENT_ENRAGE_HARD = 9,
    EVENT_DESPAWN_PLATFORM = 10,
    EVENT_AFTER_DESPAWN_PLATFORM = 11,
    EVENT_END_OF_PHASE_3 = 12,
    EVENT_RADIATING_ENERGIES = 13,
    EVENT_LAUNCH_COSMIC_SPARK = 14,
    EVENT_COSMICSPARK_ATTACK = 15
};

enum elegonActions
{
    ACTION_RESET_DRAWING_POWER = 1,
    ACTION_SPAWN_ENERGY_CHARGES = 2,
    ACTION_DESPAWN_ENERGY_CHARGES = 3,
    ACTION_EMPYREAL_FOCUS_KILLED = 4,
    ACTION_WIPE = 5
};

enum eMovementPoints
{
    POINT_EMPYEREAN_FOCUS = 1
};

enum empyrealFocusActions
{
    ACTION_ACTIVATE_EMPYREAL_FOCUS = 1,
    ACTION_RESET_EMPYREAL_FOCUS = 2
};

enum empyrealFocusEvents
{
    EVENT_ACTIVATE_EMPYREAL_FOCUS = 1,
    EVENT_APPEAR_WALL_OF_LIGHTNING = 2
};

enum eTalk
{
    TALK_INTRO = 0,
    TALK_INTRO_2 = 1,
    TALK_AGGRO = 2,
    TALK_DEATH = 3,
    TALK_A_TO_B_1 = 4,
    TALK_A_TO_B_2 = 5,
    TALK_B_TO_C_1 = 6,
    TALK_C_TO_A_1 = 7,
    TALK_C_TO_A_2 = 8,
    TALK_C_TO_A_3 = 9,
    TALK_ENRAGE_HARD = 10,
    TALK_ENRAGE_SOFT = 11,
    TALK_SLAY = 12
};

// Set values in reset of mob_empyreal_focus
ObjectGuid empyrealFocus[6] =
{
    ObjectGuid::Empty, // South-West
    ObjectGuid::Empty, // North-West
    ObjectGuid::Empty, // South
    ObjectGuid::Empty, // North
    ObjectGuid::Empty, // South-East
    ObjectGuid::Empty, // North-East
};

Position middlePos = { 4023.15f, 1907.60f, 358.872f, 0.0f };
Position infiniteEnergyPos = { 4023.45f, 1907.60f, 365.0f, 0.0f };

Position energyChargePos[6] =
{
    { 4029.58f, 1914.03f, 360.83f, 0.788954f }, // North-West
    { 4032.21f, 1907.66f, 360.83f, 0.002521f }, // North
    { 4029.58f, 1901.30f, 360.83f, 5.497790f }, // North-East
    { 4016.85f, 1901.30f, 360.83f, 3.923430f }, // South-East
    { 4014.21f, 1907.66f, 360.83f, 3.139080f }, // South
    { 4016.85f, 1914.03f, 360.83f, 2.356190f }  // South-West
};

Position empyrealFocusPosition[6] =
{
    { 4054.24f, 1938.86f, 358.872f, 0.785398f }, // North-West
    { 4067.13f, 1907.75f, 358.872f, 0.000000f }, // North
    { 4054.24f, 1876.64f, 358.872f, 5.49779f },  // North-East
    { 3992.02f, 1876.64f, 358.872f, 3.92699f },  // South-East
    { 3979.13f, 1907.75f, 358.872f, 3.14159f },  // South
    { 3992.02f, 1938.86f, 358.872f, 2.35619f }   // South-West
};

enum infiniteActions
{
    ACTION_INFINITE_GO_DOWN = 0,
    ACTION_INFINITE_ACTIVATION_WEST = 1,
    ACTION_INFINITE_ACTIVATION = 2,
    ACTION_INFINITE_ACTIVATION_EAST = 3,
    ACTION_INFINITE_FLASH_SPAWN = 4,
    ACTION_INFINITE_SPAWN_PLATFORM = 5,
    ACTION_INFINITE_SPAWN_BOSS = 6,
    ACTION_INFINITE_LOOT = 7
};

void AddSC_boss_elegon()
{
    
}
