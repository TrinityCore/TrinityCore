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
#include "ScriptedCreature.h"
#include "vault_of_the_wardens.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_SHADOWSTEP = 1,
    SAY_SHADOWSTEP_EMOTE = 2,
    SAY_SHADOWSTEP_REMOVE = 3,
    SAY_GLAIVE = 4,
    SAY_KILLED = 5,
    SAY_TURN_KICK = 6,
    SAY_DEATH = 7,
    SAY_EVADE = 8,
    SAY_EMOTE_CREEPING = 10,
};

enum Spells
{
    SPELL_KNOCKDOWN_KICK = 197251,
    SPELL_TURN_KICK = 197250,
    SPELL_DEEPENING_SHADOWS = 213583,  // 213397
    SPELL_DEEPENING_SHADOWS_TWO = 213576,  // two targets 
    SPELL_DEEPENING_SHADOWS_RAND = 197551,
    SPELL_DETONATING_MOONGLAIVE = 197513,
    SPELL_SHADOWSTEP = 203416,
    SPELL_SHADOWSTEP_2 = 204635,
    SPELL_VENGEANCE = 204984,   //! To-Do invis for npc and cast from invis with visual
    SPELL_VENGEANCE_SHIELD = 205004,

    // while invis
    SPELL_INVISE_BY_SHADOWSTEP = 204461,
    SPELL_INVISE_BY_SHADOWSTEP_1 = 192750,
    SPELL_FEL_GLAIVE = 197333,
    SPELL_STEAL_LIGHT = 206387,

    // heroic and mythic 
    SPELL_CREEPING_DOOM_SHIELD = 197422,
    SPELL_CREEPING_DOOM_SECOND = 213685,
    SPELL_CREEPING_DOOM_DMG = 197507,

    //Other
    SPELL_ELUNES_LIGHT = 201359,
    SPELL_ELUNES_LIGHT_VIS_1 = 197897,
    SPELL_ELUNES_LIGHT_VIS_2 = 204294,
    SPELL_ELUNES_LIGHT_CLICK = 197890,
    SPELL_ELUNES_LIGHT_OVERRIDE = 192656,
    SPELL_ELUNES_LIGHT_SUMMON = 204491,
    SPELL_ELUNES_LIGHT_DMG = 192752,


    SPELL_INTRO = 198309,
};

enum eEvents
{
    EVENT_KNOCKDOWN_KICK = 1,
    EVENT_KNOCKDOWN_KICK_TRIGGER,
    EVENT_DEEPENING_SHADOWS,
    EVENT_DETONATING_MOONGLAIVE,
    EVENT_SHADOWSTEP,
    EVENT_VENGEANCE,
    EVENT_CREEPING_FIRST,
    EVENT_CREEPING_SECOND,

    EVENT_1,

    ACTION_1,
};

Position const centrPos = { 4049.907f, -297.4254f, -281.4167f };

std::map<uint8, std::pair<Position, Position> > paths =
{
    {0, {{4074.16f, -325.45f, -281.11f}, {4028.46f, -325.07f, -281.11f}}},
    {1, {{4022.30f, -321.86f, -281.11f}, {4022.86f, -273.61f, -281.11f}}},
    {2, {{4027.00f, -269.02f, -281.11f}, {4074.33f, -269.34f, -281.11f}}}
};

Position const vengeance_position[4]
{
    {4027.47f, -273.93f, -281.11f, 0.0f},
    {4074.04f, -274.42f, -281.11f, 0.0f},
    {4074.04f, -320.78f, -281.11f, 0.0f},
    {4027.47f, -320.78f, -281.11f, 0.0f},
};

std::map<uint8, std::pair<Position, Position> > creeping_walls =
{
    {0, {{4020.11f, -267.21f, -281.11f, 6.26f}, {4020.11f, -327.91f, -281.11f, 6.26f}}},
    {1, {{4081.06f, -327.91f, -281.11f, 1.55f}, {4020.11f, -327.91f, -281.11f, 1.55f}}},
    {2, {{4081.06f, -267.21f, -281.11f, 3.17f}, {4081.06f, -327.91f, -281.11f, 3.17f}}},
    {3, {{4081.06f, -267.21f, -281.11f, 4.71f}, {4020.11f, -267.21f, -281.11f, 4.71f}}}
};

void AddSC_boss_cordana_felsong()
{
   
}
