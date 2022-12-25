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

#include "emerald_nightmare.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ROT = 1,
    SAY_BREATH_EMOTE = 2,
    SAY_BREATH = 3,
    SAY_PHASE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_ENERGIZE = 220952,
    SPELL_ALLOW_ROT_CAST = 204755,
    SPELL_HEART_SWARM = 203552,
    SPELL_ROT_FILTER = 203095,
    SPELL_ROT_DOT = 203096,
    SPELL_VOLATILE_ROT = 204463,
    SPELL_INFESTED_GROUND_MISSILE = 204377,
    SPELL_INFESTED_GROUND_AT = 203044,
    SPELL_INFESTED_GROUND_VIS = 204476,
    SPELL_INFESTED_BREATH_FILTER = 202968,
    SPELL_INFESTED_BREATH_CHANNEL = 202977,
    SPELL_INFESTED_BREATH_DMG = 202978,
    SPELL_TRANSFORM_BUGS = 204894,

    //Heroic
    SPELL_TARGETING_AURA = 220189,
    SPELL_INFESTED = 204504,

    //Mythic
    SPELL_INFESTED_MIND_FILTER = 225943,
    SPELL_INFESTED_MIND = 205043,
    SPELL_SPREAD_INFESTATION = 205070,

    //!Trash
        //Gelatinized Decay - 111004
        SPELL_TRANSFORM_INSECT_AURA = 220978,
        SPELL_TRANSFORM_INSECT = 220976,
        SPELL_WAVE_OF_DECAY = 221059,
        SPELL_UNSTABLE_DECAY = 221030,
        SPELL_PUTRID_SWARM = 221033,

        //Corrupted Vermin - 111005
        SPELL_HEART_SWARM_SCALE = 203647,
        SPELL_PUTRID_SWARM_DMG = 221036,

        //Corrupted Vermin - 102998
        SPELL_SCALE = 196285,
        SPELL_BURST_OF_CORRUPTION = 203646,
};

enum eEvents
{
    EVENT_CHECK_POWER = 1,
    EVENT_ALLOW_ROT_CAST = 2,
    EVENT_ROT = 3,
    EVENT_VOLATILE_ROT = 4,
    EVENT_INFESTED_BREATH = 5,
    EVENT_HEART_SWARM_END = 6,
    EVENT_INFESTED_MIND = 7,
};

enum ePhases
{
    PHASE_BATTLE = 1,
    PHASE_SWARM = 2
};

enum eOther
{
    DATA_SWARM_COUNTER = 1,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
};

Position const decayPos[3] =
{
    {1910.29f, 1332.19f, 369.50f},
    {1866.0f,  1332.56f, 369.50f},
    {1851.89f, 1295.29f, 369.50f}
};

void AddSC_nythendra()
{
   
}
