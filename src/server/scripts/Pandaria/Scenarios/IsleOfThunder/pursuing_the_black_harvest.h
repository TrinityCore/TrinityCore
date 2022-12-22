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

#ifndef PURSUING_THE_BLACK_HARVEST_SCENARIO_H_
#define PURSUING_THE_BLACK_HARVEST_SCENARIO_H_

#include "ScriptPCH.h"
#include "ScenarioMgr.h"

#define CHAPTERS 9

const Position DemonicGatewayPos = { 645.96f, 305.97f, 353.67f, 6.15f };
const Position felStalkerPos     = { 677.73f, 305.48f, 353.19f, 3.15f };
const Position entrancePos       = { 711.20f, 998.29f,  53.55f, 4.66f };

const Position akamaScrollPath[6] =
{
    { 747.29f, 514.64f, 112.84f, 4.99f },
    { 745.15f, 498.72f, 112.76f, 4.52f },
    { 703.29f, 462.86f, 112.74f, 3.84f },
    { 704.51f, 394.93f, 113.16f, 4.70f },
    { 704.00f, 375.43f, 125.05f, 4.68f },
    { 703.24f, 357.72f, 125.15f, 4.63f },
};

const Position akamaSanctumPath[5] =
{
    { 724.33f, 354.70f, 125.16f, 6.20f },
    { 762.46f, 309.34f, 125.09f, 5.46f },
    { 781.58f, 297.84f, 112.80f, 5.77f },
    { 808.19f, 235.39f, 112.75f, 5.11f },
    { 808.52f, 220.40f, 112.76f, 4.73f },
};

const Position akamaPostSanctumPath[3] =
{
    { 808.01f, 119.75f, 112.41f, 4.63f },
    { 756.76f,  69.93f, 112.73f, 3.94f },
    { 663.71f,  65.22f, 112.72f, 3.18f },
};

const Position akamaLastPath[3] =
{
    { 732.50f,  67.13f, 113.25f, 0.00f },
    { 751.60f, 163.19f, 112.77f, 1.36f },
    { 751.75f, 225.62f,  63.63f, 1.53f },
};

const Position kanrethadPath[2] =
{
    { 662.39f, 308.06f, 354.01f, 6.01f },
    { 659.02f, 324.64f, 353.94f, 2.05f },
};

enum Creatures
{
    NPC_HUNGERING_SOUL_FRAGMENT = 68140,
    NPC_SUFFERING_SOUL_FRAGMENT = 68139,
    NPC_ASHTONGUE_SHAMAN        = 68129,
    NPC_ASHTONGUE_PRIMALIST     = 68096,
    NPC_ASHTONGUE_WORKER        = 68098,
    NPC_UNBOUND_CENTURION       = 68176,
    NPC_UNBOUND_NIGHTLORD       = 68174,
    NPC_FREED_IMP               = 68173,
    NPC_UNBOUND_BONEMENDER      = 68175,
    NPC_UNBOUND_SUCCUBUS        = 68205,
    NPC_UNBOUND_SHIVARRA        = 68206,
    NPC_JUBEKA_SHADOWBREAKER    = 70166,
    NPC_DEMONIC_SOULWELL        = 70052,
    NPC_AKAMA                   = 68137,
    NPC_ESSENCE_OF_ORDER        = 68151,
    NPC_KANRETHAD_EBONLOCKE     = 69964,
    NPC_PIT_LORD                = 70075,
    NPC_DOOM_LORD               = 70073,
    NPC_DEMONIC_GATEWAY         = 70028,
    NPC_KANRETHAD_WILD_IMP      = 70071,
    NPC_KANRETHAD_FEELHUNTER    = 70072,
    NPC_HARVEST_CREDIT          = 68054, // also used like vehicle for cosmetic transformation (no data)

    // Credits
    NPC_NETHERSTORM_MEMORY      = 68782,
    NPC_BLADES_EDGE_MEMORY      = 68783,
    NPC_SHADOWMOON_MEMORY       = 68780,
    NPC_BLACK_TEMPLE_ENTRANCE   = 68053,
};

enum iSpells
{
    SPELL_TRUSTED_BY_ASHTONGUE    = 134206,
    SPELL_MEMORY_OF_THE_RELICVARY = 134210,
};

enum Data
{
    STEP_ENTER_THE_BLACK_TEMPLE,
    STEP_SEARCH_FOR_SIGNS,
    STEP_FOLLOW_AKAMA,
    STEP_UNCOVER_COUNCILS_PLAN,
    STEP_DEFEAT_ESSENCE_OF_ORDER,
    STEP_ESCAPE_SHRINE_OF_LOST_SOULS,
    STEP_PLUNDER_THE_DEN_OF_MORTAL_DELIGHTS,
    STEP_HEAD_OF_THE_TEMPLE_SUMMIT,
    STEP_DEFEAT_KANRETHAD,

    // Misc
    PLAYER_DATA,
};

enum eActions
{
    ACTION_START_INTRO,
    ACTION_MOVE_TO_SANCTUM,
    ACTION_KANRETHAD_DEFEATED,
    ACTION_INIT_FLAME,
};

enum GameObjects
{
    GO_ILLIDARI_SCROLL = 216364,
};

enum eTalks
{
    TALK_INTRO,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_5,
    TALK_SPECIAL_6,
    TALK_SPECIAL_7,
    TALK_SPECIAL_8,
};

enum Quests
{
    QUEST_INFILTRATING_TO_BLACK_TEMPLE = 32325,
    QUEST_SEEK_THE_SIGNAL              = 32324,
};

const std::map<uint32, uint32> invOutlandSceneType =
{
    { 127, NPC_NETHERSTORM_MEMORY },
    { 128, NPC_BLADES_EDGE_MEMORY },
    { 129, NPC_SHADOWMOON_MEMORY  },
};

#endif // PURSUING_THE_BLACK_HARVEST_SCENARIO_H_