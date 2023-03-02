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

#ifndef BREWING_STORM_SCENARIO_H_
#define BREWING_STORM_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define TEXT_CHAPTER_MAKE_BOOMERS_BREW "Let`s get this lightning party started, Blanche."
#define TEXT_CHAPTER_ROAD_TO_THUNDERPAW "Let`s go!"
#define TEXT_CHAPTER_SAVE_THUNDERPAW_REFUGE "Let`s save thunderpaw!"
#define TEXT_LAST_CHAPTER "Let`s kill some lizards, Blanche!"
#define BLANCHE_ALE "Stand in Blanche`s Ale of Replenishment to restore health and mana!"
#define BOOMER_BREW "Use the Boomer Bew to zap saurok minions!"
#define MAX_WP 35
#define CHAPTERS 3

const Position BlancheWaypoints[MAX_WP]
{
    { 2247.05f, -1124.02f, 485.24f, 2.24f },
    { 2233.69f, -1111.92f, 477.90f, 2.97f },
    { 2224.81f, -1116.85f, 476.07f, 3.92f },
    { 2220.96f, -1121.52f, 471.68f, 4.19f },
    { 2218.30f, -1127.26f, 471.34f, 4.27f },
    { 2215.21f, -1138.47f, 462.39f, 4.55f },
    { 2214.71f, -1144.21f, 461.83f, 4.57f }, // spawn
    { 2214.52f, -1155.72f, 453.06f, 4.68f },
    { 2214.67f, -1161.76f, 452.09f, 4.70f },
    { 2214.92f, -1173.37f, 443.02f, 4.71f },
    { 2220.30f, -1179.90f, 442.49f, 5.44f },
    { 2228.66f, -1188.30f, 433.55f, 5.46f },
    { 2236.92f, -1194.25f, 432.86f, 5.66f },
    { 2246.77f, -1200.86f, 423.91f, 5.64f },
    { 2252.95f, -1206.57f, 421.38f, 5.66f }, // spawn+ orient +pi/2
    { 2278.30f, -1176.83f, 422.26f, 0.95f }, // spawn
    { 2288.00f, -1148.67f, 434.14f, 1.23f }, // spawn
    { 2288.74f, -1124.68f, 445.17f, 1.52f },
    { 2285.31f, -1107.08f, 446.39f, 1.91f }, // end of chapter 2td
    { 2272.71f, -1094.15f, 432.50f, 2.31f },
    { 2266.89f, -1088.70f, 432.13f, 2.36f },
    { 2259.51f, -1081.15f, 424.30f, 2.31f },
    { 2238.84f, -1079.53f, 424.49f, 3.10f },
    { 2230.83f, -1079.35f, 428.94f, 3.08f },
    { 2226.93f, -1079.22f, 428.98f, 3.14f },
    { 2218.87f, -1079.19f, 424.56f, 3.09f },
    { 2190.66f, -1076.98f, 430.27f, 3.05f },
    { 2169.34f, -1072.05f, 430.87f, 2.84f },
    { 2164.84f, -1062.99f, 431.73f, 1.57f },
    { 2164.62f, -1051.40f, 440.93f, 1.57f },
    { 2164.55f, -1044.36f, 441.19f, 1.55f },
    { 2164.60f, -1039.15f, 445.29f, 1.41f },
    { 2167.85f, -1025.10f, 446.52f, 0.98f },
    { 2171.70f, -1021.15f, 450.88f, 0.75f },
    { 2179.65f, -1016.12f, 450.77f, 0.16f }, // orient+pi
};

const Position defendersSpawnPos[6] =
{
    { 2212.478f, -1032.934f, 450.854f, 5.21177f  },
    { 2204.878f, -1036.394f, 450.854f, 4.699734f },
    { 2196.233f, -1029.097f, 450.854f, 4.043215f },
    { 2216.51f,    -985.75f, 450.771f, 0.543074f },
    { 2190.20f,    -979.00f, 450.771f, 5.612819f },
    { 2209.25f,   -1004.73f, 450.770f, 3.621843f },
};

enum eCreature
{
    NPC_BREWKEG                     = 58916,
    NPC_BREWMASTER_BLANCHE          = 58740,
    NPC_THUNDERPAW_INITIATE         = 59781, // pandaren
    NPC_THUNDERPAW_GUARDIAN         = 59779,
    NPC_VILETONGUE_SKIRMISHER       = 58738,
    NPC_VILETONGUE_RAIDER           = 58737,
    NPC_VILETONGUE_DECIMATOR        = 71353,
    NPC_BOROKHULA_THE_DESTROYER     = 58739,
                                    
    /*Triggers*/                    
    NPC_LIGHTNING_TARGET_BUNNY      = 70097,
    NPC_LIGHTNING_TARGET_BUNNY_2    = 38821,
    NPC_LIGHTNING_ROD               = 58869,
    NPC_VILETONGUE_VEHICLE          = 59635,
    NPC_VILETONGUE_STALKER          = 59650,
    NPC_BLANCHES_STILL              = 71124,
    NPC_WIND_SLASH                  = 66962,
};

enum eData
{
    DATA_MAKE_BOOMERS_BREW      = 0, // First chapter, done when ur progress bar will done
    DATA_ROAD_TO_THUNDERPAW     = 1, // Second chapter, done when u`ll reach to village
    DATA_SAVE_THUNDERPAW_REFUGE = 2, // Last chapter, done when u`ll kill 58739

    // Misc
    TYPE_HIT_BY_ROAD,
    TYPE_PARTY_OF_SIX,
};

enum eActions
{
    ACTION_IGNITE                 = 0,
    ACTION_BREW_POWER             = 1,
    ACTION_MAKE_BOOMERS_BREW      = 2,
    ACTION_ROAD_TO_THUNDERPAW     = 3,
    ACTION_SAVE_THUNDERPAW_REFUGE = 4,
    ACTION_VILETONGUE_AT_GROUND   = 5,
    ACTION_VILETONGUE_AT_HILL     = 6,
    ACTION_CHAPTER_ONE_COMPLETED  = 7,
    ACTION_BOROKHULA_INIT         = 8,
};

enum eGamesObject
{
    BLANSHE_LIGHTNING_ROD     = 210512,
    BLANSHE_STILL             = 210856,
};

enum Worldstates
{
    WORLDSTATE_PERFECT_POUR = 12627,
    WORLDSTATE_PARTY_OF_SIX = 12628,
};

enum Criteries
{
    CRITERIA_BORAKHULA_DEFEAT = 19565,
};

#endif // BREWING_STORM_SCENARIO_H_