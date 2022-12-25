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

#include "black_rook_hold.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_VENGEFUL_SHEAR = 1,
    SAY_DARK_RUSH = 2,
    SAY_WARN_DARK_RUSH = 3,
    SAY_PHASE_FLY = 4,
    SAY_EYE_BEAMS = 5,
    SAY_WARN_EYE_BEAMS = 6,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_FURY_POWER_OVERRIDE = 197367,
    SPELL_REGEN_POWER = 197394,
    SPELL_BRUTAL_GLAIVE = 197546,
    SPELL_VENGEFUL_SHEAR = 197418,
    SPELL_DARK_RUSH_FILTER = 197478,
    SPELL_DARK_RUSH_CHARGE = 197484,
    SPELL_PHASE_FLY_JUMP = 197622,
    SPELL_EYE_BEAMS = 197674,
    SPELL_EYE_BEAMS_AURA = 197696,
    SPELL_EYE_BEAMS_AT = 197703,
    SPELL_FIXATE_BEAM = 197687,

    //Christmas
    SPELL_CHRISTMAS_CAP = 220873,

    //Other
    SPELL_BOULDER_EXPLODE_AT = 222378,
    SPELL_BOULDER_EXPLODE_REMOVE = 222388,

    SPELL_DRINK_ANCIENT_POTION = 200784,
    SPELL_HYPERACTIVE_DUMMY = 201064,
    SPELL_HYPERACTIVE_AT = 201063, //Dmg 201062
    SPELL_DIZZY_STUN = 201070,
    SPELL_INDIGESTION_DUMMY = 200958,
    SPELL_INDIGESTION_CHANNEL = 200913,
    SPELL_FRENZY_POTION = 201061,
};

enum eEvents
{
    EVENT_BRUTAL_GLAIVE = 1,
    EVENT_VENGEFUL_SHEAR = 2,
    EVENT_DARK_RUSH_1 = 3,
    EVENT_DARK_RUSH_2 = 4,
    EVENT_SUMMON_ADDS = 5,
    EVENT_EYE_BEAMS = 6,
    EVENT_PHASE_FLY = 7,
    EVENT_PHASE_GROUND = 8,

    DATA_ACHIEVEMENT,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

std::vector<std::pair<uint32, Position>> introSumPos
{
    {98706, {3104.32f, 7320.2f,  96.0f, 0.91f}},  //Commander Shemdah'sohn
    {98275, {3121.12f, 7335.8f, 86.37f, 1.18f}},  //Risen Archer
    {98275, {3114.48f, 7340.4f, 86.37f, 0.73f}},  //Risen Archer
    {98275, {3096.66f, 7343.5f, 102.69f, 5.64f}}, //Risen Archer
    {98275, {3129.64f, 7319.1f, 102.78f, 2.94f}}, //Risen Archer
    {98280, {3114.86f, 7346.0f, 86.50f, 0.20f}},  //Risen Arcanist
    {98691, {3125.06f, 7336.8f, 86.46f, 1.68f}},  //Risen Scout
    {98691, {3111.49f, 7364.9f, 102.69f, 5.60f}}, //Risen Scout
    {98691, {3145.1f,  7340.7f, 102.78f, 2.63f}}  //Risen Scout
};

Position const summonsPos[2] =
{
    {3105.11f, 7296.94f, 103.28f, 3.14f}, //NPC_RISEN_ARCANIST
    {3083.07f, 7313.35f, 103.28f, 4.92f}  //NPC_SOUL_TORN_VANGUARD
};

void AddSC_boss_illysanna_ravencrest()
{
    
}
