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

#include "eternal_palace.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "GridNotifiersImpl.h"

enum Spells
{
    SPELL_OXYGEN_RICH_MEMBRANE = 291977,
    SPELL_BIOLUMINESCENCE = 292133,
    SPELL_BIOLUMINESCENT_CLOUND = 292205, // 302135,
    SPELL_RADIANT_BIOMASS_AURA = 295412,
    SPELL_RADIANT_BIOMASS_PROC = 292138,
    SPELL_DARKEST_DEPTHS = 292127,
    SPELL_BIOELECTRIC_DISCHARGE = 305094,
    SPELL_FEEDING_FRENZY_AURA = 298424,
    SPELL_FEEDING_FRENZY_PROC = 298428,
    SPELL_TOXIC_SPINE_CAST = 292159,
    SPELL_TOXIC_SPINE_MISSILE = 292162,
    SPELL_SHOCK_PULSE_CAST = 292270,
    SPELL_SHOCK_PULSE_DAMAGE = 292279,
    SPELL_BIOELECTRIC_FEELERS_AURA = 297932,
    SPELL_BIOELECTRIC_FEELERS_DUMMY = 292232,
    SPELL_BIOELECTRIC_FEELERS_DAMAGE = 305330,
    SPELL_BIOELECTRIC_FEELERS_AT = 305405,
    SPELL_GAZE_FROM_BELOW = 292307,
    SPELL_CAVITATION_CAST = 292083,
    SPELL_CAVITATION_DAMAGE = 292084,
    SPELL_SLIPSTREAM_AT = 302036,
    SPELL_SLIPSTREAM = 301180,
    SPELL_GLOWING_STINGER_AT = 298594,
    SPELL_GLOWING_STINGER_AURA = 298595,
    SPELL_PIERCING_BARB_CAST = 301494,
    SPELL_PIERCING_BARB_AT = 305187,
    SPELL_PIERCING_BARB_DAMAGE = 301930,
};

enum Events
{
    EVENT_ADD_ENERGY = 1,
    EVENT_CHANGE_PHASE,
    EVENT_TOXIC_SPINE,
    EVENT_REMOVE_INTERMISSION,
    EVENT_SHOCK_PULSE,
    EVENT_REMOVE_MOVEMENT_FORCE,
    EVENT_PIERCING_BARB,
    EVENT_BIOELECTRIC_FEELERS,
};

enum Timers
{
    TIMER_ADD_ENERGY = 1 * IN_MILLISECONDS,
    TIMER_CHANGE_PHASE = 90 * IN_MILLISECONDS, //1.30m
    TIMER_TOXIC_SPINE = 8 * IN_MILLISECONDS,
    TIMER_TOXIC_SPINE_AFTER = 28 * IN_MILLISECONDS,
    TIMER_PIERCING_BARB = 12 * IN_MILLISECONDS,
    TIMER_PIERCING_BARB_AFTER = 24 * IN_MILLISECONDS,
    TIMER_BIOELECTRIC_FEELERS = 4 * IN_MILLISECONDS,
    TIMER_SHOCK_PULSE = 20 * IN_MILLISECONDS,
};

const Position platform1 = { -4.35f, 974.46f, 1255.90f, 3.21f }; // 3.21f
const Position platform2 = { -263.46f, 1099.83f, 1211.03f, 4.68f }; // 4.68
const Position platform3 = { -448.11f, 788.86f, 1171.09f, 0.85f }; // 0.85

const Position firstPlatformCheck = { -54.86f, 959.30f, 1249.38f }; //50y

// boss 40y
const Position secondPlatformCheck1 = { -300.46f, 1030.39f, 1207.40f }; // x 28, y, 20
const Position secondPlatformCheck2 = { -254.09f, 1020.45f, 1206.55f }; // x 27 y 20

// boss 35y
const Position thirdPlatformCheck1 = { -443.87f, 847.56f, 1167.82f }; //x 15 y 20
const Position thirdPlatformCheck2 = { -395.65f, 808.48f, 1166.90f }; //20y both

const Position jellyFishFirstSpawn = { -161.72f, 991.28f, 1242.16f };
const Position jellyFishSecondSpawn = { -354.09f, 911.11f, 1204.11f };

void AddSC_blackwater_behemoth()
{
   
}
