/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

#ifndef DEF_DRAGONSOUL_H
#define DEF_DRAGONSOUL_H
// 109247 - ds nerf real
// 109251 - ds nerf dummy
// 109255 - ds nerf dummy
// 108202 - temple teleport
// 108263 - ship teleport
// 106094 - eye teleport +
// 109835 - summit teleport +
// 106093 - summit teleport aoe
// 106092 - temple teleport aoe
#define DSScriptName "instance_dragon_soul"

enum Datas
{
    DATA_MORCHOK            = 0,
    DATA_YORSAHJ            = 1,
    DATA_ZONOZZ             = 2,
    DATA_HAGARA             = 3,
    DATA_ULTRAXION          = 4,
    DATA_BLACKHORN          = 5,
    DATA_SPINE              = 6,
    DATA_DEATHWING          = 7,
    DATA_DAMAGE_DEATHWING   = 8,
    DATA_KOHCROM            = 10,
    DATA_HAGARA_EVENT       = 11,
    DATA_LESSER_CACHE_10N   = 12,
    DATA_LESSER_CACHE_25N   = 13,
    DATA_LESSER_CACHE_10H   = 14,
    DATA_LESSER_CACHE_25H   = 15,
    DATA_SWAYZE             = 16,
    DATA_REEVS              = 17,
    DATA_ALLIANCE_SHIP      = 18,
    DATA_BACK_PLATE_1       = 19,
    DATA_BACK_PLATE_2       = 20,
    DATA_BACK_PLATE_3       = 21,
    DATA_GREATER_CACHE_10N  = 22,
    DATA_GREATER_CACHE_25N  = 23,
    DATA_GREATER_CACHE_10H  = 24,
    DATA_GREATER_CACHE_25H  = 25,
    DATA_TRALL_VS_ULTRAXION = 27,
};

enum CreatureIds
{
    NPC_MORCHOK                   = 55265,
    NPC_KOHCROM                   = 57773,
    NPC_YORSAHJ                   = 55312,
    NPC_ZONOZZ                    = 55308,
    NPC_HAGARA                    = 55689,
    NPC_ULTRAXION                 = 55294,
    NPC_BLACKHORN                 = 56427,
    NPC_GORIONA                   = 56781,
    NPC_SKY_CAPTAIN_SWAYZE        = 55870,
    NPC_KAANU_REEVS               = 55891,
    NPC_SPINE_OF_DEATHWING        = 53879, // 109983 105003 109035 95278 105036
    NPC_VOID_OF_THE_UNMAKING      = 55334,
    NPC_EYE_OF_GORATH             = 57875,
    NPC_FLAIL_OF_GORATH              = 55417,
    NPC_CLAW_OF_GORATH            = 55418,
    NPC_ICE_WAVE                  = 56104,
    NPC_FALLING_ICICLE            = 57867,
    NPC_ICICLE                    = 48916,
    NPC_FORZEN_BINDIG_CRYSTAL     = 56136,
    NPC_CRYSTAL_CONDUCTOR         = 56165,
    NPC_BOUND_LIGHTNING_ELEMENTAL = 56700,
    NPC_ICE_TOMB                  = 55695,
    NPC_ICE_LANCE                 = 56108,
    NPC_STORM_PILLAR              = 575824,
    NPC_FROSTFLAKE                = 575825,

    NPC_NETHESTRASZ                = 57287, // teleport upstairs
    NPC_EIENDORMI                  = 57288, // teleport to Yor'sahj
    NPC_VALEERA                    = 57289, // teleport to Zon'ozz
    NPC_TRAVEL_TO_WYRMREST_TEMPLE  = 57328, //
    NPC_TRAVEL_TO_WYRMREST_BASE    = 57882, //
    NPC_TRAVEL_TO_WYRMREST_SUMMIT  = 57379, //
    NPC_TRAVEL_TO_EYE_OF_ETERNITY  = 57377, // teleport to Hagara
    NPC_TRAVEL_TO_MAELSTORM        = 57443, //
    NPC_TRAVEL_TO_DECK             = 57378, //
    NPC_DASNURIMI                  = 58153, // trader
    NPC_YSERA_THE_AWAKENED         = 56665,
    NPC_ALEXTRASZA_THE_LIFE_BINDER = 56630,
    NPC_KALECGOS                   = 56664,
    NPC_THRALL_1                   = 56667, // near summit
    NPC_NOZDORMU_THE_TIMELESS_ONE  = 56666,
    NPC_THE_DRAGON_SOUL            = 56668, // near summit
    NPC_TYRYGOSA                   = 57682,
    NPC_LIFEBINDER                 = 57632,
    NPC_AFRASASTRASZ               = 55476,

    NPC_THRALL_2                   = 56103, // after spine
    NPC_THE_DRAGON_SOUL_2          = 56694, // after spine

    NPC_DEATHWING_PREULTRAXION     = 55971,
    NPC_DEATHWING                  = 56173, // at the eye
    NPC_DEATHWING_1                = 57962, // invisible head
    NPC_ALEXSTRASZA_DRAGON         = 56099, // 1
    NPC_NOZDORMU_DRAGON            = 56102, // 2
    NPC_YSERA_DRAGON               = 56100, // 3
    NPC_KALECGOS_DRAGON            = 56101, // 4
    NPC_ARM_TENTACLE_1             = 56846, // 2
    NPC_ARM_TENTACLE_2             = 56167, // 3
    NPC_WING_TENTACLE              = 56168, // 1
    NPC_AGGRA                      = 58211, // after madness
    NPC_THRALL_3                   = 58232, // after madness
    NPC_KALECGOS_2                 = 58210, // after madness
    NPC_NOZDORMU_2                 = 58208, // after madness
    NPC_ALEXSTRASZA_2              = 58207, // after madness
    NPC_YSERA_2                    = 58209, // after madness
    NPC_CORRUPTION_PARASITE        = 57479,
    NPC_CONGEALING_BLOOD           = 57798,
    NPC_ELEMENTIUM_FRAGMENT        = 56724,
    NPC_ELEMENTIUM_TERROR          = 56710,
    NPC_MUTATED_CORRUPTION         = 56471,
    NPC_TWILIGHT_ASSAULTER         = 56251,
    NPC_TWILIGHT_ASSAULT_DRAKE     = 56587,
    NPC_TWILIGHT_ASSAULT_DRAKE_2   = 56855,
    NPC_TWILIGHT_INFILTRATOR       = 56922,
    NPC_TWILIGHT_ELITE_SLAYER      = 56848,
    NPC_TWILIGHT_ELITE_DREADBLADE  = 56854,
    NPC_TWILIGHT_SAPPER            = 56923,
    NPC_SKYFIRE_HARPOON_GUN        = 56681,
    NPC_THE_SKYFIRE                = 56598,
    NPC_FIRE_STALKER               = 57852,
    NPC_FIRE_CONTROLLER            = 57920,
    NPC_SKYFIRE_BRIGADE            = 58174,
    NPC_ONSLAUGHT_TARGET           = 57238,
    NPC_SHOCKWAVE_TARGET           = 575806,
    NPC_ENGINE_STALKER             = 57190,
    NPC_MASSIVE_EXPLOSION          = 57297,
    NPC_BLADE_RUSH                 = 575807,
    NPC_SPAWNER                    = 53888,
    NPC_CORRUPTION                 = 56162,
    NPC_CORRUPTED_BLOOD            = 53889,
    NPC_HIDEOUS_AMALGAMATION       = 53890,
    NPC_BURNING_TENDONS            = 56575,
    NPC_BURNING_TENDONS_2          = 56341,
    NPC_JUMP_PAD                   = 56699,
    NPC_DEATHWING_ARM_R               = 57686,
    NPC_DEATHWING_ARM_L               = 57694,
    NPC_DEATHWING_WING_R           = 57695,
    NPC_DEATHWING_WING_L           = 57696,
    NPC_DEATHWING_TAIL_TENTACLE       = 56844,
    NPC_BLISTERING_TENTACLES       = 56188,
    NPC_HEMORRHAGE_TARGET           = 56359,
    NPC_REGENERATIVE_BLOOD           = 56263,
    NPC_ELEMENTIUM_BOLT            = 56262,
    NPC_PLATFORM                   = 56307,
    NPC_CRUSH_TARGET               = 56581,
    NPC_TIME_ZONE_TARGET           = 56332,
    NPC_TIME_ZONE                  = 56311,
    NPC_CORRUPTING_PARASITE        = 57479,
    NPC_CONGEALING_BLOOD_TARGET    = 57788,
};

enum GameObjects
{
    GO_INNER_WALL                       = 209596,
    GO_THE_FOCUSING_IRIS                = 210132,
    GO_LESSER_CACHE_OF_THE_ASPECTS_LFR  = 210221,
    GO_LESSER_CACHE_OF_THE_ASPECTS_10N  = 210160,
    GO_LESSER_CACHE_OF_THE_ASPECTS_25N  = 210161,
    GO_LESSER_CACHE_OF_THE_ASPECTS_10H  = 210162,
    GO_LESSER_CACHE_OF_THE_ASPECTS_25H  = 210163,
    GO_ALLIANCE_SHIP                    = 210210,
    GO_ALLIANCE_SHIP_1                  = 210211,
    GO_DEATHWING_BACK_PLATE_1           = 209623,
    GO_DEATHWING_BACK_PLATE_2           = 209631,
    GO_DEATHWING_BACK_PLATE_3           = 209632,
    GO_GREATER_CACHE_OF_THE_ASPECTS_LFR = 210222,
    GO_GREATER_CACHE_OF_THE_ASPECTS_10N = 209894,
    GO_GREATER_CACHE_OF_THE_ASPECTS_25N = 209895,
    GO_GREATER_CACHE_OF_THE_ASPECTS_10H = 209896,
    GO_GREATER_CACHE_OF_THE_ASPECTS_25H = 209897,
    GO_ELEMENTIUM_FRAGMENT_10N          = 210217,
    GO_ELEMENTIUM_FRAGMENT_25N          = 210218,
    GO_ELEMENTIUM_FRAGMENT_10H          = 210219,
    GO_ELEMENTIUM_FRAGMENT_25H          = 210220,
};

enum SharedSpells
{
    SPELL_TELEPORT_VISUAL_ACTIVE   = 108203,
    SPELL_TELEPORT_VISUAL_DISABLED = 108227,

    SPELL_CHARGING_UP_LIFE          = 108490,
    SPELL_CHARGING_UP_MAGIC         = 108491,
    SPELL_CHARGING_UP_EARTH         = 108492,
    SPELL_CHARGING_UP_TIME          = 108493,
    SPELL_CHARGING_UP_DREAMS        = 108494,
    SPELL_WARD_OF_TIME              = 108160,
    SPELL_WARD_OF_EARTH             = 108161,
    SPELL_WARD_OF_MAGIC             = 108162,
    SPELL_WARD_OF_LIFE              = 108163,
    SPELL_WARD_OF_DREAMS            = 108164,
    SPELL_SOUL_CHARGED              = 110489,

    // Aspects debuff
    SPELL_LAST_DEF_OF_AZEROTH   = 106218,
    SPELL_GIFT_OF_LIFE          = 106042,
    SPELL_ESSENCE_OF_DREAMS     = 106049,
    SPELL_SOURCE_OF_MAGIC       = 106050,
    SPELL_TIMELOOP              = 105984,

    SPELL_GIFT_OF_LIFE_BUFF     = 105896,
    SPELL_ESSENCE_OF_DREAMS_BUFF= 105900,
    SPELL_SOURCE_OF_MAGIC_BUFF  = 105903,

    SPELL_TELEPORT_SINGLE_TO_DEATHWINGS_BACK = 106054,
    SPELL_DRAGON_SOUL_PARATROOPER_KIT_1      = 104953, // Swayze has it while jumping to spine of deathwing
    SPELL_DRAGON_SOUL_PARATROOPER_KIT_2      = 105008, // Reevs has it while jumping to spine of deathwing

    SPELL_PARACHUTE                          = 110660, // used by players

    SPELL_PLAY_MOVIE_DEATHWING_1             = 106087,
    SPELL_PLAY_MOVIE_DEATHWING_2             = 106085, // movie before jumping at spine of deathwing
    SPELL_PLAY_MOVIE_DEATHWING_3             = 104574,

    SPELL_WARDEN_RING_GREEN                  = 95514,
    SPELL_WARDEN_RING_ORANGE                 = 110468,
    SPELL_WARDEN_RING_YELLOW                 = 110469,
};

const Position teleportPos[6] =
{
    { -1779.503662f, -2393.439941f, 45.61f, 3.20f },  // Wyrmrest Temple/Base
    { -1854.233154f, -3068.658691f, -178.34f, 0.46f },  // Yor'sahj The Unsleeping
    { -1743.647827f, -1835.132568f, -220.51f, 4.53f },  // Warlord Zon'ozz
    { -1781.188477f, -2375.122559f, 341.35f, 4.43f },  // Wyrmrest Summit
    { 13629.356445f, 13612.099609f, 123.49f, 3.14f },  // Hagara
    { -13854.668945f, -13666.967773f, 275.f, 1.60f },  // Spine
};

const Position ultraxionPos[2] =
{
    { -1564.f, -2369.f, 250.083f, 3.28122f }, // spawn
    { -1710.696f, -2387.132f, 355.884f, 3.224f }  // move to
};

const Position swayzePos = { -1694.87f, -2356.11f, 340.06f, 4.82f };
const Position skyfireSpawn = { -1699.89f, -2372.27f, 319.62f, 1.59f };
const Position dsoulPos = { -1786.72f, -2393.23f, 343.603f, 0.174533f };
const Position madnessdeathwingPos = { -12081.390625f, 12160.050781f, 30.60f, 6.03f };
const Position skyfirePos = { 13444.9f, -12133.3f, 151.21f, 0.0f };
const Position spinedeathwingPos = { -13852.5f, -13665.38f, 297.3786f, 1.53589f };

void WhisperToAllPlayerInZone(int32 TextId, Creature* sender);
#endif
