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

#ifndef PROVING_GROUNDS_SCENARIO_H_
#define PROVING_GROUNDS_SCENARIO_H_

#include "ScriptPCH.h"

const Position arenaCenterPos = { 3795.67f, 533.56f, 639.00f, 2.99f };

const Position innerPillarsPos[7] =
{
    { 3770.06f, 557.29f, 639.82f, 0.00f }, // FR
    { 3765.17f, 516.49f, 639.82f, 0.00f }, // FL
    { 3800.27f, 568.24f, 639.82f, 0.00f }, // R
    { 3791.67f, 498.88f, 639.82f, 0.00f }, // L
    { 3826.21f, 550.42f, 639.82f, 0.00f }, // BR
    { 3821.37f, 509.75f, 639.82f, 0.00f }, // BL
    { 3752.25f, 538.76f, 639.69f, 0.0f  }, // Forward Gate
};

const Position berserkSpawnPos[2] =
{
    { 3779.84f, 521.218f, 639.091f, 3.01942f },
    { 3783.29f, 549.291f, 639.099f, 3.01942f },
};

enum Data
{
    DATA_SELECT_A_TRIAL,
    DATA_PREPARE_TO_TRIAL,
    DATA_TRIAL,
    
    // Misc
    PLAYER_DATA,
    TRIAL_DATA,
    BARRICADE_DATA,
    INTERRUPT_DATA,
    TAUNT_DATA,
    WAVE_DATA,
    TIMER_DATA,
};

enum Creatures
{
    NPC_PROVING_GROUNDS                 = 61638,
    NPC_PROVING_GROUNDS_2               = 73334,
    NPC_TRIAL_MASTER_ROTUN              = 61636, // beginner
    NPC_FURNISHER_ECHOROOT              = 73327,
    NPC_NADAGA_SOULWEAVER               = 73328,
    NPC_XUEN                            = 71820,

    // Ally for Healer Trial     
    NPC_SOOLI_THE_SURVIVALIST           = 72220, // dps
    NPC_OTO_THE_PROTECTOR               = 72218, // tank
    NPC_KAVAN_THE_ARCANIST              = 72221, // dps
    NPC_KI_THE_ASSASSIN                 = 72219, // dps

    // for Tank Trial
    NPC_SIKARI_THE_MISTWEAVER           = 71828,

    // Illusions
    NPC_LARGE_ILLUSIONARY_SLAYER        = 71062,
    NPC_SMALL_ILLUSIONARY_SLAYER        = 71080,
    NPC_SMALL_ILLUSIONARY_GUARDIAN      = 71079,
    NPC_LARGE_ILLUSIONARY_GUARDIAN      = 71064,
    NPC_SMALL_ILLUSIONARY_VARMINT       = 71078,
    NPC_LARGE_ILLUSIONARY_VARMINT       = 71067,
    NPC_SMALL_ILLUSIONARY_AMBER_WEAVER  = 71077,
    NPC_LARGE_ILLUSIONARY_AMBER_WEAVER  = 71068,
    NPC_LARGE_ILLUSIONARY_MYSTIC        = 71069,
    NPC_SMALL_ILLUSIONARY_MYSTIC        = 71076,
    NPC_LARGE_ILLUSIONARY_BANANA_TOSSER = 71414,
    NPC_SMALL_ILLUSIONARY_BANANA_TOSSER = 71415,
    NPC_SMALL_ILLUSIONARY_BANSHE        = 71075,
    NPC_LARGE_ILLUSIONARY_BANSHE        = 71070,
    NPC_SMALL_ILLUSIONARY_SHA           = 71074,
    NPC_LARGE_ILLUSIONARY_SHA           = 71072,

    // Tank Trial Illusions
    NPC_LARGE_ILLUSIONARY_RIPPER        = 71829,
    NPC_SMALL_ILLUSIONARY_RIPPER        = 71830,
    NPC_LARGE_ILLUSIONARY_FORAGER       = 71831,
    NPC_SMALL_ILLUSIONARY_FORAGER       = 71832,
    NPC_LARGE_ILLUSIONARY_FLAMECALLER   = 71835,
    NPC_SMALL_ILLUSIONARY_FLAMECALLER   = 71836,
    NPC_LARGE_ILLUSIONARY_WIND_GUARD    = 71833,
    NPC_SMALL_ILLUSIONARY_WIND_GUARD    = 71834,
    NPC_LARGE_ILLUSIONARY_AMBUSHER      = 71838,
    NPC_SMALL_ILLUSIONARY_AMBUSHER      = 71839,
    NPC_LARGE_ILLUSIONARY_CONQUEROR     = 71841,
    NPC_SMALL_ILLUSIONARY_CONQUEROR     = 71842,

    // Healer Trial illusions
    NPC_LARGE_ILLUSIONARY_HIVE_SINGER   = 72343,
    NPC_SMALL_ILLUSIONARY_HIVE_SINGER   = 72342,
    NPC_LARGE_ILLUSIONARY_RIPPER_H      = 72337,
    NPC_SMALL_ILLUSIONARY_RIPPER_H      = 72336,
    NPC_SMALL_ILLUSIONARY_FLAMECALLER_H = 72338,
    NPC_LARGE_ILLUSIONARY_FLAMECALLER_H = 72339,
    NPC_LARGE_ILLUSIONARY_AQUALYTE      = 72346,
    NPC_SMALL_ILLUSIONARY_AQUALYTE      = 72344,
    NPC_LARGE_ILLUSIONARY_TUNNELER      = 72387,
    NPC_SMALL_ILLUSIONARY_TUNNELER      = 72386,
    NPC_LARGE_ILLUSIONARY_CONQUEROR_H   = 72341,
    NPC_SMALL_ILLUSIONARY_CONQUEROR_H   = 72340,

    // Misc
    NPC_BERSERKING                      = 73333,
    NPC_VOLATILE_AMBER_GLOBULE          = 73332,
};

enum GameObjects
{
    GO_PROVING_GROUNDS_BARRICADE = 221037, // doesn`t remember this for healer, possible using for dps or tank trial
    GO_SOULWELL                  = 222794,
};

enum Actions
{
    ACTION_START_INTRO,
    ACTION_FAIL_TRIAL,
    ACTION_COMPLETE_TRIAL,
    ACTION_DD_BRONZE_TRIAL,
    ACTION_DD_SILVER_TRIAL,
    ACTION_DD_GOLD_TRIAL,
    ACTION_DD_ENDLESS_TRIAL,
    ACTION_TANK_BRONZE_TRIAL,
    ACTION_TANK_SILVER_TRIAL,
    ACTION_TANK_GOLD_TRIAL,
    ACTION_TANK_ENDLESS_TRIAL,
    ACTION_HEALER_BRONZE_TRIAL,
    ACTION_HEALER_SILVER_TRIAL,
    ACTION_HEALER_GOLD_TRIAL,
    ACTION_HEALER_ENDLESS_TRIAL,
};

enum Yells
{
    TALK_TRIAL_BEGINNING,
    TALK_ILLUSIONARY_SLAYER,
    TALK_ILLUSIONARY_GUARDIAN,
    TALK_ILLUSIONARY_VARMINT,
    TALK_TRIAL_DONE,
    TALK_TRIAL_BEGINNING_SILVER,
    TALK_ILLUSIONARY_AMBER_WEAVER,
    TALK_ILLUSIONARY_MYSTIC,
    TALK_TRIAL_BEGINNING_GOLD,
    TALK_ILLUSIONARY_BANANA_TOSSER,
    TALK_ILLUSIONARY_BANSHEE,
    TALK_ILLUSIONARY_SHA,

    // Sikari
    TALK_SIKARI_BRONZE_INTRO = 0,
    TALK_ILLUSIONARY_RIPPER,
    TALK_ILLUSIONARY_FORAGER,
    TALK_SIKARI_SILVER_INTRO,
    TALK_ILLUSIONARY_FLAMECALLER,
    TALK_ILLUSIONARY_WIND_GUARD,
    TALK_SIKARI_GOLD_INTRO,
    TALK_ILLUSIONARY_AMBUSHER,
    TALK_ILLUSIONARY_CONQUEROR,

    // Healer Trial Friends
    TALK_ILLUSIONARY_RIPPER_H = 0,
    TALK_ILLUSIONARY_FLAMECALLER_H,
    TALK_HEALER_GOLD_INTRO,
    TALK_KI_INTERRUPT,
    TALK_HEALER_BRONZE_OUTRO  = 0, // not only bronze, for whole btw
    TALK_ILLUSIONARY_TUNNELER,
    TALK_HEALER_SILVER_INTRO  = 0,
    TALK_ILLUSIONARY_AQUALYTE,
    TALK_KAVAN_INTERRUPT,
    TALK_HEALER_BRONZE_INTRO  = 0,
    TALK_ILLUSIONARY_HIVE_SINGER,
    TALK_OTO_SHIELDWALL,
    TALK_ILLUSIONARY_CONQUEROR_H,
};

enum MiscSpells
{
    SPELL_XUEN_PRESENCE              = 144041,
    SPELL_XUEN_PRESENCE_MAGIC        = 144042,
    SPELL_XUEN_PRESENCE_MELEE_HASTE  = 144046,
    SPELL_XUEN_PRESENCE_REDUCE_ARMOR = 144044,
    SPELL_XUEN_PRESENCE_CRIT         = 144047,
    SPELL_XUEN_PRESENCE_MASTERY      = 144048,
    SPELL_XUEN_PRESENCE_RANGE_HASTE  = 144050,
    SPELL_XUEN_PRESENCE_STAMINA      = 144051,
    SPELL_XUEN_PRESENCE_STAT         = 144053,

    // Illusions
    SPELL_ILLUSIONARY_SLAYER         = 142828,
    SPELL_ILLUSIONARY_GUARDIAN       = 142836,
    SPELL_ILLUSIONARY_VARMINT        = 142834,
    SPELL_ILLUSIONARY_AMBER_WEAVER   = 142835,
    SPELL_ILLUSIONARY_MYSTIC         = 142833,
    SPELL_ILLUSIONARY_BANANA_TOSSER  = 142839,
    SPELL_ILLUSIONARY_BANSHE         = 142838,
    SPELL_ILLUSIONARY_SHA            = 142837,
    SPELL_ILLUSIONARY_RIPPER         = 144084,
    SPELL_ILLUSIONARY_FORAGER        = 144085,
    SPELL_ILLUSIONARY_FLAMECALLER    = 144091,
    SPELL_ILLUSIONARY_WIND_GUARD     = 144087,
    SPELL_ILLUSIONARY_AMBUSHER       = 144086,
    SPELL_ILLUSIONARY_CONQUEROR      = 144088,
    SPELL_ILLUSIONARY_HIVE_SINGER    = 145198,
    SPELL_ILLUSIONARY_RIPPER_H       = 145408,
    SPELL_ILLUSIONARY_FLAMECALLER_H  = 145401,
    SPELL_ILLUSIONARY_AQUALYTE       = 145204,
    SPELL_ILLUSIONARY_TUNNELER       = 145258,
    SPELL_ILLUSIONARY_CONQUEROR_H    = 145409,

    // Misc
    SPELL_ENDLESS_WAVE_HP            = 144651, // stackable (only for endless trial)
    SPELL_ENDLESS_WAVE_DMG           = 144763, // for tank & healer trial
};

enum Criteries
{
    CRITERIA_DEFEAT_ILLUSIONS = 23727,
};

enum Achievements
{
    ACHIEV_PROVING_YOURSELF_DD_BRONZE         = 8486,
    ACHIEV_PROVING_YOURSELF_DD_SILVER         = 8491,
    ACHIEV_PROVING_YOURSELF_DD_GOLD           = 8496,
    ACHIEV_PROVING_YOURSELF_TANK_BRONZE       = 8487,
    ACHIEV_PROVING_YOURSELF_TANK_SILVER       = 8492,
    ACHIEV_PROVING_YOURSELF_TANK_GOLD         = 8497,
    ACHIEV_PROVING_YOURSELF_HEALER_BRONZE     = 8488,
    ACHIEV_PROVING_YOURSELF_HEALER_SILVER     = 8493,
    ACHIEV_PROVING_YOURSELF_HEALER_GOLD       = 8498,
    ACHIEV_PROVING_YOURSELF_DD_ENDLESS_10     = 8501,
    ACHIEV_PROVING_YOURSELF_DD_ENDLESS_20     = 8504,
    ACHIEV_PROVING_YOURSELF_DD_ENDLESS_30     = 8507,
    ACHIEV_PROVING_YOURSELF_TANK_ENDLESS_10   = 8502,
    ACHIEV_PROVING_YOURSELF_TANK_ENDLESS_20   = 8505,
    ACHIEV_PROVING_YOURSELF_TANK_ENDLESS_30   = 8508,
    ACHIEV_PROVING_YOURSELF_HEALER_ENDLESS_10 = 8503,
    ACHIEV_PROVING_YOURSELF_HEALER_ENDLESS_20 = 8506,
    ACHIEV_PROVING_YOURSELF_HEALER_ENDLESS_30 = 8509,

    // for non-spec silver trial
    ACHIEV_YOU_ARE_DOING_THIS_WRONG           = 8697,
};

enum Trials
{
    TRIAL_NONE,
    TRIAL_DD_BRONZE,
    TRIAL_DD_SILVER,
    TRIAL_DD_GOLD,
    TRIAL_HEAL_BRONZE,
    TRIAL_HEAL_SILVER,
    TRIAL_HEAL_GOLD,
    TRIAL_TANK_BRONZE,
    TRIAL_TANK_SILVER,
    TRIAL_TANK_GOLD,
    TRIAL_DD_ENDLESS,
    TRIAL_HEAL_ENDLESS,
    TRIAL_TANK_ENDLESS,
};

const std::vector<uint32> raidBuffs =
{
    SPELL_XUEN_PRESENCE,
    SPELL_XUEN_PRESENCE_MAGIC,
    SPELL_XUEN_PRESENCE_MELEE_HASTE,
    SPELL_XUEN_PRESENCE_REDUCE_ARMOR,
    SPELL_XUEN_PRESENCE_CRIT,
    SPELL_XUEN_PRESENCE_MASTERY,
    SPELL_XUEN_PRESENCE_RANGE_HASTE,
    SPELL_XUEN_PRESENCE_STAMINA,
    SPELL_XUEN_PRESENCE_STAT,
};

const std::map<uint32, Position> invHealerTrialFriends =
{
    { NPC_OTO_THE_PROTECTOR, arenaCenterPos },
    { NPC_SOOLI_THE_SURVIVALIST, { 3795.07f, 529.26f, 639.00f, 3.00f } },
    { NPC_KAVAN_THE_ARCANIST,    { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_KI_THE_ASSASSIN,       { 3794.78f, 524.70f, 639.00f, 3.00f } },
};

const std::map<uint32, uint32> invRewardType =
{
    { TRIAL_DD_BRONZE,   ACHIEV_PROVING_YOURSELF_DD_BRONZE     },
    { TRIAL_DD_SILVER,   ACHIEV_PROVING_YOURSELF_DD_SILVER     },
    { TRIAL_DD_GOLD,     ACHIEV_PROVING_YOURSELF_DD_GOLD       },
    { TRIAL_TANK_BRONZE, ACHIEV_PROVING_YOURSELF_TANK_BRONZE   },
    { TRIAL_TANK_SILVER, ACHIEV_PROVING_YOURSELF_TANK_SILVER   },
    { TRIAL_TANK_GOLD,   ACHIEV_PROVING_YOURSELF_TANK_GOLD     },
    { TRIAL_HEAL_BRONZE, ACHIEV_PROVING_YOURSELF_HEALER_BRONZE },
    { TRIAL_HEAL_SILVER, ACHIEV_PROVING_YOURSELF_HEALER_SILVER },
    { TRIAL_HEAL_GOLD,   ACHIEV_PROVING_YOURSELF_HEALER_GOLD   },
};

const std::map<uint32, uint32> invAllowTrialType =
{
    { ACHIEV_PROVING_YOURSELF_DD_BRONZE,      1 },
    { ACHIEV_PROVING_YOURSELF_DD_SILVER,      2 },
    { ACHIEV_PROVING_YOURSELF_DD_GOLD,        3 },
    { ACHIEV_PROVING_YOURSELF_TANK_GOLD,      5 },
    { ACHIEV_PROVING_YOURSELF_TANK_BRONZE,    7 },
    { ACHIEV_PROVING_YOURSELF_TANK_SILVER,    6 },
    { ACHIEV_PROVING_YOURSELF_HEALER_GOLD,    9 },
    { ACHIEV_PROVING_YOURSELF_HEALER_BRONZE, 11 },
    { ACHIEV_PROVING_YOURSELF_HEALER_SILVER, 10 },
};

const std::map<uint32, uint32> invIllusionaryType =
{
    { NPC_LARGE_ILLUSIONARY_SLAYER,        SPELL_ILLUSIONARY_SLAYER        },
    { NPC_SMALL_ILLUSIONARY_SLAYER,        SPELL_ILLUSIONARY_SLAYER        },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN,      SPELL_ILLUSIONARY_GUARDIAN      },
    { NPC_LARGE_ILLUSIONARY_GUARDIAN,      SPELL_ILLUSIONARY_GUARDIAN      },
    { NPC_SMALL_ILLUSIONARY_VARMINT,       SPELL_ILLUSIONARY_VARMINT       },
    { NPC_LARGE_ILLUSIONARY_VARMINT,       SPELL_ILLUSIONARY_VARMINT       },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER,  SPELL_ILLUSIONARY_AMBER_WEAVER  },
    { NPC_LARGE_ILLUSIONARY_AMBER_WEAVER,  SPELL_ILLUSIONARY_AMBER_WEAVER  },
    { NPC_LARGE_ILLUSIONARY_MYSTIC,        SPELL_ILLUSIONARY_MYSTIC        },
    { NPC_SMALL_ILLUSIONARY_MYSTIC,        SPELL_ILLUSIONARY_MYSTIC        },
    { NPC_LARGE_ILLUSIONARY_BANANA_TOSSER, SPELL_ILLUSIONARY_BANANA_TOSSER },
    { NPC_SMALL_ILLUSIONARY_BANANA_TOSSER, SPELL_ILLUSIONARY_BANANA_TOSSER },
    { NPC_SMALL_ILLUSIONARY_BANSHE,        SPELL_ILLUSIONARY_BANSHE        },
    { NPC_LARGE_ILLUSIONARY_BANSHE,        SPELL_ILLUSIONARY_BANSHE        },
    { NPC_SMALL_ILLUSIONARY_SHA,           SPELL_ILLUSIONARY_SHA           },
    { NPC_LARGE_ILLUSIONARY_SHA,           SPELL_ILLUSIONARY_SHA           },
    { NPC_LARGE_ILLUSIONARY_RIPPER,        SPELL_ILLUSIONARY_RIPPER        },
    { NPC_SMALL_ILLUSIONARY_RIPPER,        SPELL_ILLUSIONARY_RIPPER        },
    { NPC_LARGE_ILLUSIONARY_FORAGER,       SPELL_ILLUSIONARY_FORAGER       },
    { NPC_SMALL_ILLUSIONARY_FORAGER,       SPELL_ILLUSIONARY_FORAGER       },
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER,   SPELL_ILLUSIONARY_FLAMECALLER   },
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER,   SPELL_ILLUSIONARY_FLAMECALLER   },
    { NPC_LARGE_ILLUSIONARY_WIND_GUARD,    SPELL_ILLUSIONARY_WIND_GUARD    },
    { NPC_SMALL_ILLUSIONARY_WIND_GUARD,    SPELL_ILLUSIONARY_WIND_GUARD    },
    { NPC_LARGE_ILLUSIONARY_AMBUSHER,      SPELL_ILLUSIONARY_AMBUSHER      },
    { NPC_SMALL_ILLUSIONARY_AMBUSHER,      SPELL_ILLUSIONARY_AMBUSHER      },
    { NPC_LARGE_ILLUSIONARY_CONQUEROR,     SPELL_ILLUSIONARY_CONQUEROR     },
    { NPC_SMALL_ILLUSIONARY_CONQUEROR,     SPELL_ILLUSIONARY_CONQUEROR     },
    { NPC_LARGE_ILLUSIONARY_RIPPER_H,      SPELL_ILLUSIONARY_RIPPER_H      },
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,      SPELL_ILLUSIONARY_RIPPER_H      },
    { NPC_LARGE_ILLUSIONARY_HIVE_SINGER,   SPELL_ILLUSIONARY_HIVE_SINGER   },
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER,   SPELL_ILLUSIONARY_HIVE_SINGER   },
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER_H, SPELL_ILLUSIONARY_FLAMECALLER_H },
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER_H, SPELL_ILLUSIONARY_FLAMECALLER_H },
    { NPC_LARGE_ILLUSIONARY_AQUALYTE,      SPELL_ILLUSIONARY_AQUALYTE      },
    { NPC_SMALL_ILLUSIONARY_AQUALYTE,      SPELL_ILLUSIONARY_AQUALYTE      },
    { NPC_LARGE_ILLUSIONARY_TUNNELER,      SPELL_ILLUSIONARY_TUNNELER      },
    { NPC_SMALL_ILLUSIONARY_TUNNELER,      SPELL_ILLUSIONARY_TUNNELER      },
    { NPC_LARGE_ILLUSIONARY_CONQUEROR_H,   SPELL_ILLUSIONARY_CONQUEROR_H   },
    { NPC_SMALL_ILLUSIONARY_CONQUEROR_H,   SPELL_ILLUSIONARY_CONQUEROR_H   },
};

const std::vector<uint32> illusions =
{
    SPELL_ILLUSIONARY_SLAYER,
    SPELL_ILLUSIONARY_GUARDIAN,
    SPELL_ILLUSIONARY_VARMINT,
    SPELL_ILLUSIONARY_AMBER_WEAVER,
    SPELL_ILLUSIONARY_MYSTIC,
    SPELL_ILLUSIONARY_BANANA_TOSSER,
    SPELL_ILLUSIONARY_BANSHE,
    SPELL_ILLUSIONARY_SHA,
};

const std::vector<uint32> tankTrialIllusions =
{
    SPELL_ILLUSIONARY_RIPPER,
    SPELL_ILLUSIONARY_FORAGER,
    SPELL_ILLUSIONARY_FLAMECALLER,
    SPELL_ILLUSIONARY_WIND_GUARD,
    SPELL_ILLUSIONARY_AMBUSHER,
    SPELL_ILLUSIONARY_CONQUEROR,
};

const std::multimap<uint32, Position> invBronzeWave1 =
{
    { NPC_LARGE_ILLUSIONARY_SLAYER, arenaCenterPos },
};

const std::multimap<uint32, Position> invBronzeWave2 =
{
    { NPC_SMALL_ILLUSIONARY_SLAYER, { 3795.44f, 530.48f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_SLAYER, { 3796.12f, 536.56f, 639.00f, 3.03f } },
};

const std::multimap<uint32, Position> invBronzeWave3 =
{
    { NPC_LARGE_ILLUSIONARY_SLAYER, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3795.07f, 529.26f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invBronzeWave4 =
{
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, arenaCenterPos },
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3795.07f, 529.26f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3800.09f, 533.03f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3791.43f, 534.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3796.75f, 542.18f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3793.17f, 536.97f, 639.00f, 3.00f } }, // RFN
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3792.65f, 530.36f, 639.00f, 3.00f } }, // LFN
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3798.14f, 530.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3798.99f, 536.00f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invBronzeWave5 =
{
    { NPC_LARGE_ILLUSIONARY_VARMINT, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_VARMINT,  { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,  { 3795.07f, 529.26f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,  { 3791.43f, 534.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,  { 3793.17f, 536.97f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,  { 3792.65f, 530.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3797.42f, 548.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3793.72f, 518.85f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_SLAYER,   { 3781.34f, 535.35f, 639.00f, 3.00f } },
};

const std::map<uint32, std::multimap<uint32, Position>> invBronzeTrial =
{
    { 1, invBronzeWave1 },
    { 2, invBronzeWave2 },
    { 3, invBronzeWave3 },
    { 4, invBronzeWave4 },
    { 5, invBronzeWave5 },
};

const std::multimap<uint32, Position> invSilverWave1 =
{
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3794.78f, 524.70f, 639.00f, 3.00f } }, // R->
    { NPC_SMALL_ILLUSIONARY_SLAYER,   { 3796.75f, 542.18f, 639.00f, 3.00f } }, // L->
};

const std::multimap<uint32, Position> invSilverWave2 =
{
    { NPC_SMALL_ILLUSIONARY_VARMINT, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3796.29f, 537.98f, 639.00f, 3.00f } }, // RN
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3795.07f, 529.26f, 639.00f, 3.00f } }, // LN
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3800.09f, 533.03f, 639.00f, 3.00f } }, // BN
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3798.14f, 530.16f, 639.00f, 3.00f } }, // FN
    { NPC_LARGE_ILLUSIONARY_VARMINT, { 3798.99f, 536.00f, 639.00f, 3.00f } }, // LBN
    { NPC_SMALL_ILLUSIONARY_SLAYER,  { 3785.57f, 534.81f, 639.00f, 3.00f } }, // RBN
};

const std::multimap<uint32, Position> invSilverWave3 =
{
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_SLAYER, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_SLAYER, { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invSilverWave4 =
{
    { NPC_LARGE_ILLUSIONARY_VARMINT, arenaCenterPos },
    { NPC_LARGE_ILLUSIONARY_VARMINT,      { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_VARMINT,      { 3795.07f, 529.26f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,      { 3791.43f, 534.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,      { 3793.17f, 536.97f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,      { 3792.65f, 530.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3809.90f, 531.81f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invSilverWave5 =
{
    { NPC_LARGE_ILLUSIONARY_MYSTIC,  { 3785.57f, 534.81f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3800.09f, 533.03f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3798.14f, 530.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3798.99f, 536.00f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3804.99f, 532.42f, 639.00f, 3.00f } }, // B->
};

const std::multimap<uint32, Position> invSilverWave6 =
{
    { NPC_SMALL_ILLUSIONARY_MYSTIC, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_SLAYER,   { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_GUARDIAN, { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invSilverWave7 =
{
    { NPC_SMALL_ILLUSIONARY_MYSTIC,       { 3785.57f, 534.81f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN,     { 3797.42f, 548.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN,     { 3793.72f, 518.85f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3800.09f, 533.03f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,      { 3798.14f, 530.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT,      { 3798.99f, 536.00f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invSilverWave8 =
{
    { NPC_LARGE_ILLUSIONARY_MYSTIC, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_SLAYER,       { 3785.57f, 534.81f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::map<uint32, std::multimap<uint32, Position>> invSilverTrial =
{
    { 1, invSilverWave1 },
    { 2, invSilverWave2 },
    { 3, invSilverWave3 },
    { 4, invSilverWave4 },
    { 5, invSilverWave5 },
    { 6, invSilverWave6 },
    { 7, invSilverWave7 },
    { 8, invSilverWave8 },
};

const std::multimap<uint32, Position> invGoldWave1 =
{
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_SLAYER,   { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_SLAYER,   { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave2 =
{
    { NPC_LARGE_ILLUSIONARY_AMBER_WEAVER, arenaCenterPos },
    { NPC_LARGE_ILLUSIONARY_BANANA_TOSSER, { 3796.29f, 537.98f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave3 =
{
    { NPC_SMALL_ILLUSIONARY_BANANA_TOSSER, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_MYSTIC,       { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave4 =
{
    { NPC_LARGE_ILLUSIONARY_MYSTIC, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_BANANA_TOSSER, { 3800.09f, 533.03f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave5 =
{
    { NPC_SMALL_ILLUSIONARY_BANSHE, arenaCenterPos }, // additional banshe atleast 10s until timer expire
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3796.75f, 542.18f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, { 3804.99f, 532.42f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave6 =
{
    { NPC_LARGE_ILLUSIONARY_VARMINT, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3796.29f, 537.98f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3795.07f, 529.26f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3798.14f, 530.16f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3793.17f, 536.97f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_VARMINT, { 3792.65f, 530.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_MYSTIC,  { 3797.42f, 548.36f, 639.00f, 3.00f } }, // RL
    { NPC_SMALL_ILLUSIONARY_MYSTIC,  { 3793.72f, 518.85f, 639.00f, 3.00f } }, // LL
};

const std::multimap<uint32, Position> invGoldWave7 =
{
    { NPC_SMALL_ILLUSIONARY_GUARDIAN, arenaCenterPos }, // + additional banshee (45s remain) - > Large at 20s remain
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER,  { 3797.42f, 548.36f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_MYSTIC,        { 3793.72f, 518.85f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_BANANA_TOSSER, { 3796.29f, 537.98f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave8 =
{
    { NPC_SMALL_ILLUSIONARY_SHA, arenaCenterPos },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3794.78f, 524.70f, 639.00f, 3.00f } },
    { NPC_SMALL_ILLUSIONARY_AMBER_WEAVER, { 3796.75f, 542.18f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave9 =
{
    { NPC_SMALL_ILLUSIONARY_BANANA_TOSSER, { 3793.17f, 536.97f, 639.00f, 3.00f } }, // + additional banshee (50s remain)
    { NPC_SMALL_ILLUSIONARY_SHA,           { 3792.65f, 530.36f, 639.00f, 3.00f } },
    { NPC_LARGE_ILLUSIONARY_MYSTIC,        { 3785.57f, 534.81f, 639.00f, 3.00f } },
};

const std::multimap<uint32, Position> invGoldWave10 =
{
    { NPC_LARGE_ILLUSIONARY_SHA, arenaCenterPos }, // + additional banshee (50/25s remain)
    { NPC_LARGE_ILLUSIONARY_SLAYER, { 3785.57f, 534.81f, 639.00f, 3.00f } },
};

const std::map<uint32, std::multimap<uint32, Position>> invGoldTrial =
{
    { 1, invGoldWave1 },
    { 2, invGoldWave2 },
    { 3, invGoldWave3 },
    { 4, invGoldWave4 },
    { 5, invGoldWave5 },
    { 6, invGoldWave6 },
    { 7, invGoldWave7 },
    { 8, invGoldWave8 },
    { 9, invGoldWave9 },
    { 10, invGoldWave10 },
};

const std::multimap<uint32, Position> invTankBronzeWave1 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankBronzeWave2 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankBronzeWave3 =
{
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankBronzeWave4 =
{
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_RIPPER,  innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankBronzeWave5 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_RIPPER, innerPillarsPos[1] },
};

// 30s remain
const std::multimap<uint32, Position> invTankBronzeAdditionalWave5 =
{
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[0] },
};

const std::map<uint32, std::multimap<uint32, Position>> invTankBronzeTrial =
{
    { 1, invTankBronzeWave1 },
    { 2, invTankBronzeWave2 },
    { 3, invTankBronzeWave3 },
    { 4, invTankBronzeWave4 },
    { 5, invTankBronzeWave5 },
};

const std::multimap<uint32, Position> invTankSilverWave1 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_RIPPER, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankSilverWave2 =
{
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankSilverWave3 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_RIPPER,      innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankSilverWave4 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankSilverWave5 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,      innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,      innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankSilverAdditionalWave5 =
{
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankSilverWave6 =
{
    { NPC_LARGE_ILLUSIONARY_WIND_GUARD, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,     innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankSilverWave7 =
{
    { NPC_LARGE_ILLUSIONARY_WIND_GUARD,  innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_RIPPER,      innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankSilverWave8 =
{
    { NPC_LARGE_ILLUSIONARY_WIND_GUARD, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,    innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankSilverAdditionalWave8 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,      innerPillarsPos[1] },
};

const std::map<uint32, std::multimap<uint32, Position>> invTankSilverTrial =
{
    { 1, invTankSilverWave1 },
    { 2, invTankSilverWave2 },
    { 3, invTankSilverWave3 },
    { 4, invTankSilverWave4 },
    { 5, invTankSilverWave5 },
    { 6, invTankSilverWave6 },
    { 7, invTankSilverWave7 },
    { 8, invTankSilverWave8 },
};

const std::multimap<uint32, Position> invTankGoldWave1 =
{
    { NPC_SMALL_ILLUSIONARY_WIND_GUARD, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,     innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankGoldWave2 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FORAGER,     innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankGoldWave3 =
{
    { NPC_SMALL_ILLUSIONARY_AMBUSHER, innerPillarsPos[5] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,   innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,   innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankGoldWave4 =
{
    { NPC_SMALL_ILLUSIONARY_WIND_GUARD, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_RIPPER,     innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankGoldWave5 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invTankGoldWave6 =
{
    { NPC_SMALL_ILLUSIONARY_CONQUEROR, innerPillarsPos[6] },
    { NPC_SMALL_ILLUSIONARY_RIPPER, innerPillarsPos[6] },
};

const std::multimap<uint32, Position> invTankGoldWave7 =
{
    { NPC_SMALL_ILLUSIONARY_CONQUEROR,  innerPillarsPos[3] },
    { NPC_SMALL_ILLUSIONARY_WIND_GUARD, innerPillarsPos[3] },
};

const std::multimap<uint32, Position> invTankGoldWave8 =
{
    { NPC_LARGE_ILLUSIONARY_CONQUEROR,   innerPillarsPos[2] },
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[2] },
};

const std::multimap<uint32, Position> invTankGoldWave9 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invTankGoldWave10 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER, innerPillarsPos[0] },
};

const std::map<uint32, std::multimap<uint32, Position>> invTankGoldTrial =
{
    { 1, invTankGoldWave1 },
    { 2, invTankGoldWave2 },
    { 3, invTankGoldWave3 },
    { 4, invTankGoldWave4 },
    { 5, invTankGoldWave5 },
    { 6, invTankGoldWave6 },
    { 7, invTankGoldWave7 },
    { 8, invTankGoldWave8 },
    { 9, invTankGoldWave9 },
    { 10, invTankGoldWave10 },
};

const std::multimap<uint32, Position> invHealerBronzeWave1 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerBronzeWave2 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerBronzeWave3 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerBronzeWave4 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H,    innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerBronzeWave5 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_RIPPER_H, innerPillarsPos[0] },
};

const std::map<uint32, std::multimap<uint32, Position>> invHealerBronzeTrial =
{
    { 1, invHealerBronzeWave1 },
    { 2, invHealerBronzeWave2 },
    { 3, invHealerBronzeWave3 },
    { 4, invHealerBronzeWave4 },
    { 5, invHealerBronzeWave5 },
};

const std::multimap<uint32, Position> invHealerSilverWave1 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerSilverWave2 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,    innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerSilverWave3 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,      innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerSilverWave4 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H,      innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerSilverWave5 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H,      innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER,   innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerSilverWave6 =
{
    { NPC_LARGE_ILLUSIONARY_RIPPER_H, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_AQUALYTE, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerSilverWave7 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_AQUALYTE,      innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerSilverWave8 =
{
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_AQUALYTE,    innerPillarsPos[0] },
};

const std::map<uint32, std::multimap<uint32, Position>> invHealerSilverTrial =
{
    { 1, invHealerSilverWave1 },
    { 2, invHealerSilverWave2 },
    { 3, invHealerSilverWave3 },
    { 4, invHealerSilverWave4 },
    { 5, invHealerSilverWave5 },
    { 6, invHealerSilverWave6 },
    { 7, invHealerSilverWave7 },
    { 8, invHealerSilverWave8 },
};

const std::multimap<uint32, Position> invHealerGoldWave1 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,      innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerGoldWave2 =
{
    { NPC_LARGE_ILLUSIONARY_AQUALYTE,    innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerGoldWave3 =
{
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_TUNNELER,    innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerGoldWave4 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,      innerPillarsPos[1] },
    { NPC_LARGE_ILLUSIONARY_TUNNELER,      innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerGoldWave5 =
{
    { NPC_SMALL_ILLUSIONARY_TUNNELER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_AQUALYTE, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerGoldWave6 =
{
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,    innerPillarsPos[6] },
    { NPC_SMALL_ILLUSIONARY_RIPPER_H,    innerPillarsPos[6] },
    { NPC_SMALL_ILLUSIONARY_CONQUEROR_H, innerPillarsPos[6] },
};

const std::multimap<uint32, Position> invHealerGoldWave7 =
{
    { NPC_SMALL_ILLUSIONARY_HIVE_SINGER, innerPillarsPos[0] },
    { NPC_LARGE_ILLUSIONARY_TUNNELER,    innerPillarsPos[0] },
    { NPC_SMALL_ILLUSIONARY_CONQUEROR_H, innerPillarsPos[0] },
};

const std::multimap<uint32, Position> invHealerGoldWave8 =
{
    { NPC_LARGE_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[1] },
    { NPC_SMALL_ILLUSIONARY_CONQUEROR_H,   innerPillarsPos[1] },
};

const std::multimap<uint32, Position> invHealerGoldWave9 =
{
    { NPC_SMALL_ILLUSIONARY_FLAMECALLER_H, innerPillarsPos[2] },
    { NPC_LARGE_ILLUSIONARY_CONQUEROR_H,   innerPillarsPos[2] },
};

const std::multimap<uint32, Position> invHealerGoldWave10 =
{
    { NPC_SMALL_ILLUSIONARY_TUNNELER,    innerPillarsPos[6] },
    { NPC_LARGE_ILLUSIONARY_CONQUEROR_H, innerPillarsPos[6] },
};

const std::map<uint32, std::multimap<uint32, Position>> invHealerGoldTrial =
{
    { 1, invHealerGoldWave1 },
    { 2, invHealerGoldWave2 },
    { 3, invHealerGoldWave3 },
    { 4, invHealerGoldWave4 },
    { 5, invHealerGoldWave5 },
    { 6, invHealerGoldWave6 },
    { 7, invHealerGoldWave7 },
    { 8, invHealerGoldWave8 },
    { 9, invHealerGoldWave9 },
    { 10, invHealerGoldWave10 },
};

#endif // PROVING_GROUNDS_SCENARIO_H_