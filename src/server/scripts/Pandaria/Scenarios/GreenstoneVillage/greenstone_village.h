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

#ifndef GREENSTONE_VILLAGE_SCENARIO_H_
#define GREENSTONE_VILLAGE_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 5

const Position TzuPath[CHAPTERS-3] = 
{
    { 1937.24f, -1865.01f, 203.31f, 5.46f },
    { 1951.65f, -1880.72f, 202.69f, 5.46f }
};

const Position HuiPath[CHAPTERS - 3] =
{
    { 2251.97f, -1851.67f, 230.01f, 4.02f },
    { 2232.57f, -1876.45f, 223.91f, 4.03f }
};

enum eCreatures
{
    NPC_SASSY_SEEDLING        = 61157,
    NPC_CURSED_JADE           = 61174,
    NPC_WILY_WOODLING         = 61155,
    NPC_GREENSTONE_TERROR     = 61159,
    NPC_DOOM_BLOOM            = 61414,
    NPC_CURSED_BREW           = 62637,
    NPC_JADE_DESTROYER        = 62619, // at chapter 2 instance should random choise jade monstrosity
    NPC_BEAST_OF_JADE         = 66772,
    NPC_BLOODTHIRSTRY_PROWLER = 62945,
    NPC_BELLIGERENT_BLOSSOM   = 61183,
    NPC_VENGEFUL_HUI          = 61156,

    // interactive npc
    NPC_COWARDLY_ZUE          = 62706,
    NPC_MAYOR_LIN             = 65271,
    NPC_LA_THE_GENTLE         = 61343,
    NPC_WOODCARVER_LIUPO      = 61342,
    NPC_PORTLY_SHUNG          = 61461,
    NPC_SCRIBE_RINJI          = 61346,
    NPC_GRACEFUL_SWAN         = 61350,
    NPC_MEILA                 = 61462,
    NPC_UNCONSCIOUS_MONK      = 61204,
    NPC_BREWMASTER_TZU        = 61203,
    NPC_BURGLED_BARREL        = 62682,
    NPC_BARREL_CHEST_HUO      = 62988,
    NPC_STONECUTTER_LON       = 62989,
    NPC_KIRI_JADE_EYES        = 62990,
    NPC_MONSTER_TARGET_WOOD   = 61223,
    NPC_JADE_BLAZE            = 62623,
    NPC_BREW_BUBLE            = 66756,
};

enum eData
{
    DATA_RESCUE_VILLAGE          = 0, // First chapter, done when u`ll help villagers
    DATA_RESCUE_DOJO             = 1, // Second chapter, done when u`ll help to brewmaster (u need kill any monstrosity)
    DATA_RECOVER_BURGLED_BARRELS = 2, // Third chapter, done when u`ll return back 6 barrels
    DATA_GREENSTONE_MASONS       = 3, // Four chapter, done when u`ll heal 3 massons
    DATA_DEFEAT_VENGEFUL_HUI     = 4, // Last chapter, done when u`ll kill 61156
};

enum eActions
{
    ACTION_TALK      = 0,
    ACTION_INTRO     = 1,
    ACTION_SPECIAL_1 = 2,
    ACTION_SPECIAL_2=  3,
    ACTION_SPECIAL_3 = 4,
};

enum eTalks
{
    TALK_INTRO = 0,
    TALK_PROTECTED = 1,
    TALK_SPECIAL_1 = 2,
    TALK_SPECIAL_2 = 3,
    TALK_SPECIAL_3 = 4,
    TALK_SPECIAL_4 = 5,
};

enum eSpells
{
    SPELL_VOLATILE_GREENSTONE_BREW = 119091, // at chapter 4 begun
};

enum eAreaTriggers
{
    AT_INTRO        = 8083,
    AT_BEFORE_SHUNG = 8469,
    AT_BEFORE_LIUPO = 7869,
    AT_BEFORE_LIN   = 8472,
    AT_BEFORE_MEILA = 7868,
    AT_BEFORE_SWAN  = 7873,
    AT_BEFORE_RINJI = 7872,
    AT_BEHIND_TZU   = 8102,
};

enum worldstates
{
    WORLDSTATE_PERFECT_DELIVERY  = 12583,
    WORLDSTATE_SAVE_IT_FOR_LATER = 12585,
};

enum Criteries
{
    CRITERIA_LA_LIUPO_RESCUED     = 19204,
    CRITERIA_MAYOR_LIN_RESCUED    = 21336,
    CRITERIA_MEILA_RESCUED        = 19200,
    CRITERIA_PORTLY_SHUNG_RESCUED = 19201,
    CRITERIA_SCRIBE_RINJI_RESCUED = 19202,
    CRITERIA_SWAN_RESCUED         = 19203,
    CRITERIA_STOLEN_BREW          = 19229,
    CRITERIA_KIRI_RESCUED         = 19265,
    CRITERIA_XO_RESCUED           = 1244,
    CRITERIA_LON_RESCUED          = 19264,
    CRITERIA_HUI_DEFEATED         = 19205,
};

const std::map<uint32, uint32> invVillagerCriteriaType =
{
    { NPC_WOODCARVER_LIUPO, CRITERIA_LA_LIUPO_RESCUED     },
    { NPC_MAYOR_LIN,        CRITERIA_MAYOR_LIN_RESCUED    },
    { NPC_MEILA,            CRITERIA_MEILA_RESCUED        },
    { NPC_PORTLY_SHUNG,     CRITERIA_PORTLY_SHUNG_RESCUED },
    { NPC_SCRIBE_RINJI,     CRITERIA_SCRIBE_RINJI_RESCUED },
    { NPC_GRACEFUL_SWAN,    CRITERIA_SWAN_RESCUED         },
};

const std::map<uint32, uint32> invstonecutterCriteriaType =
{
    { NPC_KIRI_JADE_EYES,   CRITERIA_KIRI_RESCUED },
    { NPC_BARREL_CHEST_HUO, CRITERIA_XO_RESCUED   },
    { NPC_STONECUTTER_LON,  CRITERIA_LON_RESCUED  },
};

#endif // GREENSTONE_VILLAGE_H_