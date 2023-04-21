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

#ifndef ARENA_OF_ANNIHILIATION_SCENARIO_H_
#define ARENA_OF_ANNIHILIATION_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 6
#define WALL_DIFF 2.0943f // we should make mercedes angle diff 2pi/3

const Position ArenaPos     = { 3795.57f, 533.56f, 639.00f, 6.13f };
const Position makiSpawnPos = { 3716.46f, 543.177f, 639.774f, 6.16253f };

enum eCreatures
{
    NPC_GURGTHOCK           = 63315,
    NPC_WODIN_TROLL_SERVANT = 63314,
    NPC_SCAR_SHELL          = 63311,
    NPC_JOL_GRUM            = 63312,
    NPC_LITTLE_LIUYANG      = 63313,
    NPC_CHAGAN_FIREHOOF     = 63318,
    NPC_CLOUDBENDER_KOBO    = 63316,
    NPC_SATAY_BYU           = 64281, // at chapter 5td we should random choise [kobo or byu or maki]
    NPC_MAKI_WATERBLADE     = 64280,
    NPC_WORLD_INV_TRIGGER   = 41206,
    NPC_FLAME_WALL          = 63534,
    NPC_FLAMECOAXING_SPIRIT = 63539,
    NPC_BATU                = 63872,
    NPC_TRAILBLAZE          = 63544,
    NPC_TWISTER             = 66991,
};

enum eData
{
    DATA_SCAR_SHELL = 1, // First chapter, done at encounter died 63311
    DATA_JOL_GRUM   = 2, // Second chapter, done at encounter died 63312
    DATA_LIUYANG    = 3, // Third chapter, done at encounter died 63313
    DATA_CHAGAN     = 4, // Four chapter, done at encounter died 63318
    DATA_ASSASSIN   = 5, // Last chapter, done at encounter died (at last chapter we have rotate now 64281 or 63316)
    DATA_CALL       = 6, // using at gong
};

enum eActions
{
    ACTION_INTRO          = 0,
    ACTION_REMOVE_SHELL   = 1,
    ACTION_REMOVE_VEHICLE = 2,
};

enum eType
{
    TYPE_FLAMELINE = 1,
};

enum eTalks
{
    TALK_INTRO_1           = 0,
    TALK_INTRO_2           = 1,
    TALK_INTRO_3           = 2,
    TALK_SCAR_SHELL_INTRO  = 3,
    TALK_SCAR_SHELL_DEFEAT = 4,
    TALK_NEW_CHALLENGE     = 5,
    TALK_JOL_GRUM_INTRO    = 6,
    TALK_JOL_GRUM_DEFEAT   = 7,
    TALK_LIUYANG_INTRO     = 8,
    TALK_LIUYANG_DEFEAT    = 9,
    TALK_CHAGAN_INTRO      = 10,
    TALK_CHAGAN_DEFEAT     = 11,
    TALK_ASSASSIN_INTRO    = 12,
    TALK_ASSASSIN_DEFEAT   = 13,
    TALK_DONE              = 14,
};

enum eGameObjects
{
    GO_TIGER_TEMPLE_GONG = 212974,
    GO_TIGER_TEMPLE_DOOR = 211693,
};

enum worldstates
{
    WORLDSTATE_BEAT_THE_HEAT = 12579,
};

enum Criteries
{
    CRITERIA_GONG                = 20810,
    CRITERIA_SCAR_SHELL_DEFEATED = 19336,
    CRITERIA_JOL_GRUM_DEFEATED   = 19337,
    CRITERIA_LIUYANG_DEFEATED    = 21922,
    CRITERIA_CHAGAN_DEFEATED     = 19341,
    CRITERIA_LAST_CHALLENGER     = 20587,
};

const std::map<uint32, uint32> invChallengerType =
{
    { NPC_SCAR_SHELL,       CRITERIA_SCAR_SHELL_DEFEATED },
    { NPC_JOL_GRUM,         CRITERIA_JOL_GRUM_DEFEATED   },
    { NPC_LITTLE_LIUYANG,   CRITERIA_LIUYANG_DEFEATED    },
    { NPC_CHAGAN_FIREHOOF,  CRITERIA_CHAGAN_DEFEATED     },
    { NPC_CLOUDBENDER_KOBO, CRITERIA_LAST_CHALLENGER     },
    { NPC_SATAY_BYU,        CRITERIA_LAST_CHALLENGER     },
};

#endif // ARENA_OF_ANNIHILIATION_H_