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

#ifndef DARK_HEART_OF_PANDARIA_SCENARIO_H_
#define DARK_HEART_OF_PANDARIA_SCENARIO_H_

#include "ScriptPCH.h"

#define CHAPTERS 5

const Position craftyPath[3] =
{
    { 857.26f, 1094.39f, 358.28f, 3.47f },
    { 841.01f, 1090.23f, 356.52f, 3.36f },
    { 814.10f, 1109.76f, 357.10f, 2.43f },
};

const Position gearslipPath[2] =
{
    { 834.21f, 1093.79f, 356.52f, 2.57f },
    { 809.32f, 1123.51f, 357.10f, 2.26f },
};

const Position darkheartDest    = { 773.64f, 1144.86f, 357.77f, 3.54f };
const Position malkorokSpawnPos = { 819.37f, 1106.35f, 357.10f, 2.28f };

enum Creatures
{
    NPC_GRIZZLE_GEARSLIP            = 70956,
    NPC_HAMFISTED_BRUISER           = 70741,
    NPC_BIG_BLOSSOM_DIGGER          = 71589,
    NPC_BIG_BLOSSOM_DIGGER_FEMALE   = 70643,
    NPC_TRILLIUM_BLADED_ROCK_CUTTER = 70706,
    NPC_FIERY_ANGER                 = 70824,
    NPC_EARTHBORN_HATRED            = 70822,
    NPC_URTHARGES_THE_DESTROYER     = 70959,
    NPC_VASE_ARTIFACT               = 70788,
    NPC_SCROLL_ARTIFACT             = 70792,
    NPC_BOOK_ARTIFACT               = 70791,
    NPC_CRATE_OF_ARTIFACTS          = 70797,
    NPC_CRAFTY_THE_AMBITIOUS        = 71358,
    NPC_KOKRON_ELITE                = 71360,
    NPC_NORUSHEN                    = 71246,
    NPC_ECHO_OF_YSHAARJ             = 71123,
    NPC_MALKOROK                    = 71177,
    NPC_VOLATILE_EARTH              = 70877,
    NPC_BLOOD_OF_YSHAARJ            = 70690,
    NPC_QUIVERING_BLOOD             = 71112,
    NPC_MOUTH_OF_TERROR             = 70691,
    NPC_HEART_CONTROLLER            = 71280,
};

enum iSpells
{
    SPELL_GOBLIN_ILLISION_FEMALE = 142358, // for alliance players
    SPELL_GOBLIN_ILLUSION_MALE   = 142360,
    SPELL_URTHARGES_SHIELD       = 141203,

    // Artifacts
    SPELL_CRATE_ARTIFACT_VISUAL  = 141196,
    SPELL_CRATE_ARTIFACT_AT      = 141195,
    SPELL_SCROLL_ARTIFACT_VISUAL = 141172,
    SPELL_SCROLL_ARTIFACT_AT     = 141171,
    SPELL_BOOK_ARTIFACT_VISUAL   = 141164,
    SPELL_BOOK_ARTIFACT_AT       = 141165,
    SPELL_VASE_ARTIFACT_AT       = 141161,
    SPELL_VASE_ARTIFACT_VISUAL   = 141160,

    // Achievement
    SPELL_ACCELERATED_ARCHEOLOGY = 143408,
};

enum Data
{
    STEP_TALK_WITH_LEADER,
    STEP_URTHARGES_DEFEATED,
    STEP_STUFF_POCKETS,
    STEP_END_OF_MINE,
    STEP_ECHO_DEFEATED,
    MAX_STEP,

    // Misc
    DATA_ARTIFACT,
};

enum eActions
{
    ACTION_START_INTRO,
    ACTION_GRIZZLE_ANSWER,
    ACTION_LEAVE_MALKOROK,
};

enum GameObjects
{
    GO_STRANGE_WALL           = 220194,
    GO_HEART_OF_YSHAARJ       = 220195,
    GO_BLOSSOM_INVISIBLE_WALL = 219352,
    GO_BOULDERS               = 219351,
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

enum Criteries
{
    CRITERIA_ARTIFACTS_STOLEN       = 23253,
    CRITERIA_DEFEAT_ECHO_OF_YSHAARJ = 23251,
};

const std::map<uint32, std::array<uint32, 4>> invArtifactsType =
{
    { NPC_CRATE_OF_ARTIFACTS, { SPELL_CRATE_ARTIFACT_VISUAL,  SPELL_CRATE_ARTIFACT_AT,  0, 2 } },
    { NPC_VASE_ARTIFACT,      { SPELL_VASE_ARTIFACT_VISUAL,   SPELL_VASE_ARTIFACT_AT,   1, 5 } },
    { NPC_SCROLL_ARTIFACT,    { SPELL_SCROLL_ARTIFACT_VISUAL, SPELL_SCROLL_ARTIFACT_AT, 1, 10 } },
    { NPC_BOOK_ARTIFACT,      { SPELL_BOOK_ARTIFACT_VISUAL,   SPELL_BOOK_ARTIFACT_AT,   0, 10 } },
};

#endif // DARK_HEART_OF_PANDARIA_SCENARIO_H_