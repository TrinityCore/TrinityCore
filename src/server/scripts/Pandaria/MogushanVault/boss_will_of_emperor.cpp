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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Jan Xi & Qin Xi
    SPELL_STOMP = 116969,
    SPELL_DEVAST_ARC = 117006,
    SPELL_DEVAST_ARC_2 = 116835,
    SPELL_ARC_VISUAL = 116968,
    SPELL_MAGNETIC_ARMOR_QIN = 116815,
    SPELL_MAGNETIZED_QIN = 116818,
    SPELL_MAGNETIC_PULL_QIN = 116819,
    SPELL_MAGNETIC_ARMOR_JAN = 117193,
    SPELL_MAGNETIZED_JAN = 117195,
    SPELL_MAGNETIC_PULL_JAN = 117194,
    SPELL_FREEZE_ANIM = 16245,
    SPELL_OPPORTUNISTIC_STRIKE = 116808,
    SPELL_GROWING_OPPORTUNITY = 117854,

    // Ancient Mogu Machine
    SPELL_TITAN_GAS = 116779,
    SPELL_TITAN_GAS_AURA = 116803,
    SPELL_TITAN_GAS_AURA2 = 118327,
    SPELL_TITAN_GAS_HEROIC = 118320,

    // Rage
    SPELL_FOCALISED_ASSAULT = 116525,
    SPELL_WITHOUT_ARMOR = 116535,

    // Courage
    SPELL_FOCALISED_DEFENSE = 116778,
    SPELL_IMPEDING_THRUST = 117485,
    SPELL_HALF_PLATE = 116537,
    SPELL_PHALANX_WALL = 116549,

    // Strength
    SPELL_ENERGIZING_SMASH = 116550,
    SPELL_ENERGIZING_VISUAL = 116556,
    SPELL_ENERGIZED = 116605,
    SPELL_FULL_PLATE = 116540,

    // Titan Spark - Heroic
    SPELL_SUMMON_TITAN_SPARK = 117746,
    SPELL_FOCALISED_ENERGY = 116829,
    SPELL_ENERGY_OF_CREATION = 116805,
    SPELL_ENERGY_VISUAL = 127758,

    // Shared
    SPELL_TERRACOTTA_SKYBEAM_S = 118063,
    SPELL_TERRACOTTA_SKYBEAM_M = 118060,
    SPELL_TERRACOTTA_SPAWN = 118165,
    SPELL_WOE_BONUS = 132193,

    // Visual
    SPELL_COSMETIC_LIGHTNING = 127732
};

enum eEvents
{
    // Jan & Qin
    EVENT_DEVASTATING_COMBO = 1,
    EVENT_CHECK_MAGNETIC_ARMOR = 2,
    EVENT_SUMMON_RAGE = 4,
    EVENT_SUMMON_STRENGTH = 5,
    EVENT_SUMMON_COURAGE = 6,
    EVENT_BOSS_CAST_SKYBEAM = 100,
    EVENT_BOSS_CAST_SPAWNIN = 101,
    EVENT_BOSS_WAIT = 102,
    EVENT_BOSS_WAIT_VISIBLE = 103,
    EVENT_BOSS_EMOTE = 104,
    EVENT_BOSS_FREEZE = 105,

    // Shared
    EVENT_WAIT = 11,
    EVENT_WAIT_VISIBLE = 12,
    EVENT_CAST_SKYBEAM = 13,
    EVENT_CAST_SPAWNIN = 14,
    EVENT_TITAN_GAS = 16,
    EVENT_END_TITAN_GAS = 17,

    // Courage
    EVENT_IMPEDING_THRUST = 20,
    EVENT_CHECK_FOCDEF = 21,
    EVENT_PHALANX_WALL = 22,

    // Strenght
    EVENT_ENERGIZING_SMASH = 30,
    EVENT_SELECT_TARGET = 31,
    EVENT_ENERGIZING_VISUAL = 32,

    // Rage
    EVENT_RAGE_FIRST_ATTACK = 33,

    // Titan Spark
    EVENT_LEVITATING = 34,
    EVENT_CHECK_DISTANCE = 35
};

enum eAddActions
{
    // Bosses action
    ACTION_ACTIVATE = 0,
    ACTION_REACHHOME = 1,

    // Adds actions
    ACTION_CHOOSE_TARGET = 2,
    ACTION_COSMECTIC = 3,
    ACTION_MOGU_ACTIVATE = 4,
    ACTION_MOGU_STOP = 5,
    ACTION_BUNNY_RESET = 6,
    ACTION_CONSOLE_RESET = 7
};

enum eDisplayID
{
    DISPLAY_BOSS_INVISIBLE = 15880,
    DISPLAY_ADD_INVISIBLE = 11686,
    // For each creature (Boss or adds), we have : entry - 19008 = displayId, so we can get the right modelId with me->SetDisplayID(me->GetEntry() - 19008);
    DISPLAY_VISIBLE = 19008
};

enum eWeapons
{
    WEAPON_RAGE = 81169,
    WEAPON_STRENGTH = 81170,
    WEAPON_COURAGE_LEFT = 81171,
    WEAPON_COURAGE_RIGHT = 81172,
    WEAPON_JAN_XI = 80289,
    WEAPON_QIN_XI = 80939
};

enum eTalk
{
    TALK_JAN_QIN_XI = 0,
    TALK_RAGE = 1,
    TALK_STRENGTH = 2,
    TALK_COURAGE = 3,
    TALK_TITAN_GAS_END = 5,
    TALK_DEFEATED = 6
};

#define CENTER_X 3869.67f
#define CENTER_Y 1550.34f
#define CENTER_Z 362.282f

// Achievement
#define ACHIEVE 6455

// Starting positions for adds
float tabAlcoves[26][4] =
{
    { 3810.64f, 1550.48f, 428.737f, 6.27265f    },
    { 3811.0f,  1550.39f, 367.725f, 6.2521f     },
    { 3811.62f, 1536.66f, 398.334f, 0.749377f   },
    { 3811.95f, 1536.81f, 428.738f, 0.172334f   },
    { 3811.99f, 1536.68f, 367.726f, 0.22558f    },
    { 3812.12f, 1550.07f, 398.25f,  0.00872824f },
    { 3812.12f, 1564.02f, 428.738f, 5.77924f    },
    { 3812.33f, 1564.24f, 367.726f, 6.03922f    },
    { 3812.83f, 1563.62f, 367.643f, 5.77969f    },
    { 3813.13f, 1563.47f, 398.252f, 5.77872f    },
    { 3813.35f, 1537.36f, 367.643f, 0.150286f   },
    { 3831.79f, 1602.73f, 398.912f, 5.41683f    },
    { 3832.32f, 1498.53f, 368.308f, 0.842962f   },
    { 3850.7f,  1613.53f, 368.308f, 5.07364f    },
    { 3851.34f, 1486.52f, 368.308f, 1.23063f    },
    { 3873.93f, 1615.6f,  429.237f, 4.68575f    },
    { 3874.22f, 1484.84f, 429.236f, 1.57923f    },
    { 3874.31f, 1483.42f, 368.308f, 1.55837f    },
    { 3874.32f, 1618.01f, 368.308f, 4.71767f    },
    { 3874.55f, 1483.5f,  398.912f, 1.59109f    },
    { 3874.61f, 1617.9f,  398.912f, 4.75497f    },
    { 3894.75f, 1485.93f, 368.308f, 1.48814f    },
    { 3895.03f, 1483.62f, 398.912f, 1.48814f    },
    { 3895.25f, 1485.82f, 368.226f, 1.56936f    },
    { 3895.53f, 1617.47f, 398.912f, 4.8269f     },
    { 3895.62f, 1485.9f,  398.829f, 1.56936f    }
};

#define NB_ALCOVES 26

void AddSC_boss_will_of_emperor()
{
   
}
