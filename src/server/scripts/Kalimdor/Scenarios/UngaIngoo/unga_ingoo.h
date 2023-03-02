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

#ifndef UNGA_INGOO_SCENARIO_H_
#define UNGA_INGOO_SCENARIO_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define CHAPTERS 3

const Position BoInitPoint    = { -3074.82f, 778.71f, 1.87f,  0.95f };
const Position HozenInitPoint = { -3050.62f, 808.76f, 16.85f, 4.13f };
const Position CauldronPos    = { -2941.55f, 767.26f, 10.06f, 3.03f };
const Position BananaShipInit = { -2871.77f, 762.73f, -0.15f, 2.93f };
const Position GladInit       = { -2955.44f, 839.22f, 4.92f,  2.92f };
const Position BanquestPos    = { -2926.35f, 763.54f, 3.17f,  0.22f };

const Position BoWaypoints[12] =
{
    { -3057.22f, 795.54f, 13.85f, 1.06f },
    { -3043.37f, 822.87f, 17.12f, 1.08f },
    { -3031.89f, 847.37f, 11.95f, 1.12f },
    { -3006.71f, 853.58f, 14.98f, 6.22f }, // Talk about hozens, they charmed birds
    { -2998.78f, 850.25f, 16.40f, 5.83f }, // Talk about first keg
    { -2966.58f, 846.41f, 8.72f,  5.86f }, // Talk about hozen gladiators
    { -2939.70f, 788.55f, 4.08f,  5.15f },
    { -2947.48f, 763.37f, 5.30f,  4.77f },
    { -2944.01f, 763.17f, 6.94f,  6.23f },
    { -2940.23f, 763.09f, 8.10f,  6.26f },
    { -2939.23f, 763.88f, 8.13f,  0.87f },
    { -2938.92f, 767.23f, 9.44f,  1.55f },
};

const Position ZipLine[10] =
{
    { -2955.06f, 800.64f, 35.06f, 3.91f },
    { -2949.63f, 828.99f, 27.76f, 1.34f },
    { -2944.94f, 850.04f, 27.78f, 1.36f },
    { -2942.12f, 864.00f, 30.56f, 1.37f },
    { -2958.91f, 885.92f, 26.67f, 2.13f },
    { -2965.99f, 896.18f, 27.43f, 2.07f },
    { -2974.84f, 908.62f, 30.86f, 2.10f },
    { -2981.64f, 928.45f, 27.88f, 1.87f },
    { -2987.30f, 949.25f, 30.48f, 1.83f },
    { -2990.25f, 957.74f, 33.90f, 1.79f },
};

const Position ShipSpawnPoints[3] =
{
    { -2758.25f, 759.63f, 0.25f, 3.06f },
    { -2766.41f, 798.41f, 0.54f, 3.15f },
    { -2781.87f, 859.92f, 1.59f, 3.49f },
};

const Position BrewstealerSpawnPoints[3] =
{
    { -2964.28f, 737.46f, 11.94f, 0.82f },
    { -2983.38f, 756.48f, 13.42f, 0.17f },
    { -2960.25f, 781.47f, 6.59f,  5.29f },
};

const Position JunglerSpawnPoints[2] =
{
    { -2893.92f, 713.37f, 2.82f, 2.27f },
    { -2898.63f, 834.32f, 0.21f, 4.43f },
};

const Position SpearscampPath[2] =
{
    { -3054.55f, 800.32f, 16.36f, 4.03f },
    { -3070.34f, 783.23f, 4.71f,  3.86f },
};

enum eCreatures
{
    NPC_BREWMASTER_BO_ESCORT = 62467,
    NPC_BREWMASTER_BO_BREW   = 62491,
    NPC_UNGA_SPEARSCAMP      = 62474,
    NPC_TRAINED_JUNGLE_LORY  = 62476,
    NPC_UNGA_BIRD_HAVER      = 62475,
    NPC_UNGA_BREW_KEG        = 66252,
    NPC_OKU_OKU              = 62486,
    NPC_GAGOON               = 62485,
    NPC_HOZEN_PIRATE_SHIP    = 62506,
    NPC_CAPTAIN_OOK          = 62465,
    NPC_TRAINED_JIBBERWING   = 67028,
    NPC_UNGA_HOZEKATEER      = 63256,
    NPC_UNGA_NIBSTABBER      = 62494,
    NPC_UNGA_TOTEMCHIPPER    = 62492,
    NPC_UNGA_BREWSTEALER     = 62508,
    NPC_JUNGLE_BREWSTEALER   = 67027,
    NPC_UNGA_SCALLYWAG       = 62590,
    NPC_BREW_DEFENDER        = 62705, // Gun
    NPC_UNSTABLE_KEG         = 62713,
    NPC_CHIHOZEN_BINONO      = 62498,
    NPC_OOKIE                = 62468,

    /*Triggers*/
    NPC_BUNNY_ZTO            = 55370,
    NPC_BUNNY_ZTO_2          = 62167,
    NPC_ZIPLINE_TO_SHIP      = 62500,
    NPC_OOK_SHIP             = 64367,
    NPC_HOZEN_SWING          = 62482,

    NPC_RIK_RIK              = 62569,
    NPC_BA_BAM               = 62466,
    NPC_GROOKA_GROOKA        = 62488,
};

const std::vector<uint32> gladiators =
{
    NPC_OKU_OKU,
    NPC_GAGOON,
};

enum eSpells
{
    SPELL_THROW_KEG                = 130269,
    SPELL_THROW_KEG_VISUAL         = 122129, // red marker on stolen keg
    SPELL_THROW_KEG_IN_CAULDRON    = 121886, // by players
    SPELL_UNGA_BREW_COLLECTED_AURA = 121878,
    SPELL_BREWMASTER_KEG           = 136280, // visual keg on back side
    SPELL_DROP_BREW                = 122131,
    SPELL_POPPED_CORK              = 122436,
    SPELL_PIRATE_SHIP_SAIL         = 122060,
    SPELL_KEG_RUNNER_ACHIEVEMENT   = 127406,
    SPELL_SPILL_NO_EVIL_ACHIEV     = 127407,
    SPELL_ORANGE_ACHIEVEMENT       = 126863,
};

enum eData
{
    DATA_ESCORT           = 0, // First chapter till reach cauldron
    DATA_BARRELS          = 1, // Second chapter, players should collect 100 points of brew (in result 200)
    DATA_CAPTAIN_OOK      = 2, // Last chapter, players should kill npc 62465
    DATA_BARRELS_PROGRESS = 3, // counter for points of brew, set 100 like default at chapter 2 begun
};

enum eActions
{
    ACTION_INTRO            = 0,
    ACTION_HAVER_DEATH      = 1,
    ACTION_GLADIATORS_DEATH = 2,
    ACTION_CAPTAIN_ASSAULT  = 3,
    ACTION_CAPTAIN_DEFEAT   = 4,
};

// Using for chapters 2 events
enum eTypes
{
    TYPE_PIRATE  = 1,
    TYPE_STEALER,
    TYPE_JUNGLER,
    TYPE_BEACH,
    TYPE_KEG_RUNNED,
    TYPE_KEG_STILLED,
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
    TALK_SPECIAL_9,
    TALK_SPECIAL_10,
    TALK_SPECIAL_11,
    TALK_SPECIAL_12,
    TALK_SPECIAL_13,
    TALK_SPECIAL_14,
    TALK_SPECIAL_15,
    TALK_SPECIAL_16,
    TALK_SPECIAL_17,
};

enum eGameObjects
{
    GO_BIGGA_UNGA_KEG   = 215165,
    GO_BIGGA_UNGA_KEG_2 = 212273,
    GO_UNGA_KEG         = 212248,
    GO_UNGA_KEG_2       = 212252,
    GO_UNGA_MUG         = 212253,
    GO_UNGA_MUG_2       = 212256,
    GO_BANQUET          = 215901,
    GO_BEACH_BOMB       = 212293,
    GO_JUNGLE_BREW      = 215853,
};

enum Criteries
{
    CRITERIA_CAULDRON_COUNT   = 21304,
    CRITERIA_OOK_OOK_DEFEATED = 20696,
};

#endif // UNGA_INGOO_H_