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

#ifndef BREWMOON_FESTIVAL_SCENARIO_H_
#define BREWMOON_FESTIVAL_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 4

const Position BrewmasterBarrelPoint = { 1696.58f, 333.87f, 483.19f, 2.96f };
const Position BloatExitPoint        = { 1735.07f, 293.63f, 475.54f, 1.28f };

// Bridge
const Position AssaultPath1[5]
{
    { 1812.03f, 210.09f, 478.64f, 1.73f },
    { 1811.96f, 227.91f, 479.72f, 1.59f },
    { 1810.49f, 256.69f, 479.63f, 1.63f },
    { 1807.48f, 283.65f, 478.89f, 1.68f },
    { 1799.98f, 314.42f, 478.08f, 1.77f },
};

// Carvens
const Position AssaultPath2[4]
{
    { 1599.81f, 244.56f, 476.57f, 0.34f },
    { 1634.43f, 255.08f, 476.19f, 0.49f },
    { 1652.86f, 266.79f, 476.91f, 0.71f },
    { 1669.69f, 285.60f, 476.53f, 0.84f },
};

// Steppes first (right side)
const Position AssaultPath3[5]
{
    { 1880.14f, 547.02f, 489.65f, 4.21f },
    { 1855.81f, 495.96f, 489.80f, 4.12f },
    { 1840.00f, 462.25f, 487.66f, 0.66f },
    { 1830.34f, 434.72f, 489.10f, 4.39f },
    { 1819.68f, 420.19f, 487.47f, 3.97f },
};

// Steppes second (left side)
const Position AssaultPath4[5]
{
    { 1921.43f, 533.07f, 483.60f, 4.35f },
    { 1895.44f, 488.16f, 483.69f, 3.99f },
    { 1879.92f, 442.51f, 483.65f, 4.29f },
    { 1851.77f, 397.32f, 483.21f, 4.04f },
    { 1827.61f, 372.23f, 481.51f, 3.97f },
};

// In boats from carvens
const Position AssaultPath5[4]
{
    { 1612.54f, 225.31f, 475.39f, 3.86f },
    { 1653.85f, 250.05f, 475.45f, 3.65f },
    { 1692.88f, 271.49f, 475.45f, 3.54f },
    { 1734.15f, 286.66f, 475.45f, 3.46f },
};

// Leave path (left build)
const Position LeavePath1[4]
{
    { 1736.73f, 331.81f, 479.68f, 0.26f },
    { 1745.57f, 341.41f, 482.06f, 0.82f },
    { 1746.19f, 355.10f, 481.78f, 1.63f },
    { 1735.90f, 357.99f, 482.22f, 2.86f },
};

// Brewmaster path
const Position BrewmasterPath[2]
{
    { 1728.25f, 333.05f, 479.57f, 2.26f },
    { 1703.27f, 333.46f, 479.83f, 3.04f },
};

enum eCreatures
{
    NPC_BATAARI_YAUNGOL         = 63527,
    NPC_BATAARI_FLAMECALLER     = 63526,
    NPC_BATAARI_OUTRUNNER       = 64165,
    NPC_YAUNGOL_BOAT            = 64209, // ship
    NPC_WARBRINGER_QOBI         = 63528,
    NPC_BATAARI_WAR_YETI        = 64185,
    NPC_APOTHECARY_CHENG        = 63812,
    NPC_DISTURBED_SAUROK        = 63521,
    NPC_KARSAR_BLOODLETTER      = 63529,
    NPC_ASSISTANT_BUZAKI        = 63811, // sauroks
    NPC_HOZEN_SNOT              = 63813, // smth intgridient
    NPC_HUNGRY_VIRMEN           = 62807,
    NPC_DIRTY_VIRMEN            = 63743,
    NPC_SPAWN_BURROWED          = 63874,
    NPC_BURROW_VEHICLE          = 63741,
    NPC_BINAN_VILLAGE_ROOF_FIRE = 64893,
    NPC_DEN_MOTHER_MOOF         = 63518, // summoned by 63874
    NPC_WATER_SPIRIT            = 63519,
    NPC_LI_TE                   = 63520,
    NPC_ASSISTANT_KIEU          = 62787, // hopplings
    NPC_ASSISTANT_TART          = 62793, // spirits
    NPC_TARTS_BOAT              = 63826,
    NPC_PURE_WATER_GLOBE        = 63843,
    NPC_WATERSPOUT              = 63823,
    NPC_SACK_OF_GRAIN           = 63941,
    NPC_COMMANDER_HSIEH         = 63818,
    NPC_SLG_GENERIC_MOP         = 63420,
    NPC_BREWMASTER_BOOF         = 64901,
    NPC_FIRELINE                = 64265,
    NPC_OIL_SLICK               = 64271,
    NPC_TIAN_DISCIPLE_SPHERE    = 64908,
    NPC_BINAN_VILLAGER          = 62784,
    NPC_FIREWORKS_BARREL        = 63940,
    NPC_MISTWEAVER_NIAN         = 65295,
};

enum eSpells
{
    SPELL_RESUSCITATE          = 124546,
    SPELL_BURROW_COSMETIC      = 124752,
    SPELL_BURROW_VEHICLE       = 124363, // summ vehicle for 63518
    SPELL_WATER_SHELL          = 124428,
    SPELL_SPAWN_WATER_GLOBE    = 123953,
    SPELL_WATER_SPIRIT_CHANNEL = 124134,
    SPELL_WATER_WALKING        = 131861,
    SPELL_ROOF_FIRE            = 126857,
    SPELL_HEROIC_LEAP_EFF      = 125303,
    SPELL_YETI_SMASH_EFF       = 125331,
    SPELL_FIRELINES            = 125404,

    // Fireworks
    SPELL_FIREWORK             = 124556,
    SPELL_FIREWORK_2           = 126169,
    SPELL_FIREWORK_3           = 128313,
    SPELL_FIREWORK_4           = 128314,
    SPELL_FIREWORK_5           = 128316,
    SPELL_FIREWORK_6           = 128317,
    SPELL_FIREWORK_7           = 128318,

    // Type Identify spells
    SPELL_IN_CAVE              = 125235,
};

enum eData
{
    DATA_BREWMOON_FESTIVAL = 0,
    DATA_SCOUTS_REPORT     = 1,
    DATA_YAUNGOL_ATTACK    = 2,
    DATA_WARBRINGER_QOBI   = 3,

    // Special
    DATA_CARVENS           = 5,
    DATA_BRIDGE            = 6,
    DATA_WEST              = 7,
};

enum eActions
{
    ACTION_INTRO             = 0,
    ACTION_BREWMOON_FESTIVAL = 1,
};

enum eEvents
{
    EVENT_SCOUTS          = 1,
    EVENT_BLOATS          = 2,
    EVENT_YAUNGOLS_ATTACK = 3,
    EVENT_QOBI_ARRIVED    = 4,
};

enum eTypes
{
    TYPE_WEST      = 1,
    TYPE_BRIDGE    = 2,
    TYPE_PASSAGE   = 3,
    TYPE_BLOAT     = 4,
    TYPE_FLAMELINE = 5,
};

enum eTalks
{
    TALK_INTRO     = 0,
    TALK_SPECIAL_1 = 1,
    TALK_SPECIAL_2 = 2,
    TALK_SPECIAL_3 = 3,
    TALK_SPECIAL_4 = 4,
    TALK_SPECIAL_5 = 5,
    TALK_SPECIAL_6 = 6,
    TALK_SPECIAL_7 = 7,
    TALK_SPECIAL_8 = 8,
};

const std::vector<uint32> fireworks =
{
    SPELL_FIREWORK,
    SPELL_FIREWORK_2, // blue
    SPELL_FIREWORK_3, // green
    SPELL_FIREWORK_4, // red
    SPELL_FIREWORK_5, // two read arrows
    SPELL_FIREWORK_6, // looks nice
    SPELL_FIREWORK_7, // looks like 124556
};

#endif // BREWMOON_FESTIVAL_H_