/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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
    DATA_MORCHOK                    = 0,
    DATA_YORSAHJ                    = 1,
    DATA_ZONOZZ                     = 2,
    DATA_HAGARA                     = 3,
    DATA_ULTRAXION                  = 4,
    DATA_BLACKHORN                  = 5,
    DATA_SPINE                      = 6,
    DATA_MADNESS                    = 7,
    DATA_DEATHWING                  = 8,
    DATA_KOHCROM                    = 10,
    DATA_HAGARA_EVENT               = 11,
    DATA_LESSER_CACHE_10N           = 12,
    DATA_LESSER_CACHE_25N           = 13,
    DATA_LESSER_CACHE_10H           = 14,
    DATA_LESSER_CACHE_25H           = 15,
    DATA_SWAYZE                     = 16,
    DATA_REEVS                      = 17,
    DATA_ALLIANCE_SHIP              = 18,
    DATA_BACK_PLATE_1               = 19,
    DATA_BACK_PLATE_2               = 20,
    DATA_BACK_PLATE_3               = 21,
    DATA_GREATER_CACHE_10N          = 22,
    DATA_GREATER_CACHE_25N          = 23,
    DATA_GREATER_CACHE_10H          = 24,
    DATA_GREATER_CACHE_25H          = 25,
    DATA_ALEXSTRASZA_DRAGON         = 26,
    DATA_NOZDORMU_DRAGON            = 27,
    DATA_YSERA_DRAGON               = 28,
    DATA_KALECGOS_DRAGON            = 29,
    DATA_TRALL_MAELSTROM            = 30,
    DATA_ELEMENTIUM_FRAGMENT_10N    = 31,
    DATA_ELEMENTIUM_FRAGMENT_25N    = 32,
    DATA_ELEMENTIUM_FRAGMENT_10H    = 33,
    DATA_ELEMENTIUM_FRAGMENT_25H    = 34,
    DATA_ALL_HEROIC                 = 35,
};

enum Bosses
{
    BOSS_MORCHOK                = 0,
    BOSS_WARLORD                = 1,
    BOSS_UNSLEEPING                = 2,
    BOSS_HAGARA                    = 3,
    BOSS_ULTRAXION                = 4,
    BOSS_WARMASTER                = 5,
    BOSS_DEATHWING                = 6,
    DATA_PORTALS_ON_OFF            = 7,
    DATA_WAVE                    = 8,
    DATA_TRALL_VS_ULTRAXION     = 9,

    MAX_ENCOUNTER               = 10,
};

enum CreatureIds
{
    NPC_MORCHOK                     = 55265,
    NPC_KOHCROM                     = 57773,
    NPC_YORSAHJ                     = 55312,
    NPC_ZONOZZ                      = 55308,
    NPC_HAGARA                      = 55689,
    NPC_ULTRAXION                   = 55294,
    NPC_BLACKHORN                   = 56427,
    NPC_GORIONA                     = 56781,
    NPC_SKY_CAPTAIN_SWAYZE          = 55870,
    NPC_KAANU_REEVS                 = 55891,
    NPC_SPINE_OF_DEATHWING          = 53879, // 109983 105003 109035 95278 105036
    NPC_DEATHWING                   = 56173, // at the eye

    NPC_TARGET_DUMMY                = 56126, //Target to Siege

    NPC_HARBRINGER_OF_TWILIGHT        = 55969, //Attack
    NPC_HARBRINGER_OF_DESTRUCTION    = 55967, //Attack
    NPC_FORCE_OF_DESTRUCTION        = 56143, //Attack
    NPC_PORTENT_OF_TWILIGHT            = 56144, //Attack
    NPC_ARCANE_WARDEN                = 56141, //Defense
    NPC_CHAMPION_OF_LIFE            = 55911, //Defense
    NPC_CHAMPION_OF_MAGIC            = 55912, //Defense
    NPC_CHAMPION_OF_TIME            = 55913, //Defense
    NPC_CHAMPION_OF_EMERALD_DREAM    = 55914, //Defense

    NPC_NETHESTRASZ                 = 57287, //
    NPC_EIENDORMI                   = 57288, //
    NPC_VALEERA                     = 57289, //
    NPC_VEHICLE_NETHESTRASZ         = 572870, //
    NPC_VEHICLE_EIENDORMI           = 572880, //
    NPC_VEHICLE_VALEERA             = 572890, //
    NPC_TRAVEL_TO_WYRMREST_TEMPLE   = 57328, //
    NPC_TRAVEL_TO_WYRMREST_BASE     = 57882, //
    NPC_TRAVEL_TO_WYRMREST_SUMMIT   = 57379, //
    NPC_TRAVEL_TO_EYE_OF_ETERNITY   = 57377, // teleport to Hagara
    NPC_TRAVEL_TO_MAELSTORM         = 57443, //
    NPC_TRAVEL_TO_DECK              = 57378, //
    NPC_DASNURIMI                   = 58153, // trader
    NPC_YSERA_THE_AWAKENED          = 56665,
    NPC_ALEXTRASZA_THE_LIFE_BINDER  = 56630,
    NPC_KALECGOS                    = 56664,
    NPC_THRALL_1                    = 56667, // near summit
    NPC_NOZDORMU_THE_TIMELESS_ONE   = 56666,
    NPC_THE_DRAGON_SOUL             = 56668, // near summit
    NPC_DEATHWING_TOWER             = 55971, //The Destroyer Siege the Tower

    NPC_THRALL_2                    = 56103, // after spine
    NPC_THE_DRAGON_SOUL_2           = 56694, // after spine

    NPC_ALEXSTRASZA_DRAGON          = 56099, // 1
    NPC_NOZDORMU_DRAGON             = 56102, // 2
    NPC_YSERA_DRAGON                = 56100, // 3
    NPC_KALECGOS_DRAGON             = 56101, // 4

    NPC_AGGRA                       = 58211, // after madness
    NPC_THRALL_3                    = 58232, // after madness
    NPC_KALECGOS_2                  = 58210, // after madness
    NPC_NOZDORMU_2                  = 58208, // after madness
    NPC_ALEXSTRASZA_2               = 58207, // after madness
    NPC_YSERA_2                     = 58209, // after madness
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
    GO_ALIANCE_SHIP_1                   = 210211,
    GO_HORDE_SHIP                       = 210061,
    GO_DEATHWING_BACK_PLATE_1           = 209623,
    GO_DEATHWING_BACK_PLATE_2           = 209631,
    GO_DEATHWING_BACK_PLATE_3           = 209632,
    GO_GREATER_CACHE_OF_THE_ASPECTS_LFR = 210222,
    GO_GREATER_CACHE_OF_THE_ASPECTS_10N = 209894,
    GO_GREATER_CACHE_OF_THE_ASPECTS_25N = 209895,
    GO_GREATER_CACHE_OF_THE_ASPECTS_10H = 209896,
    GO_GREATER_CACHE_OF_THE_ASPECTS_25H = 209897,
    GO_ELEMENTIUM_FRAGMENT_LFR          = 210079,
    GO_ELEMENTIUM_FRAGMENT_10N          = 210217,
    GO_ELEMENTIUM_FRAGMENT_25N          = 210218,
    GO_ELEMENTIUM_FRAGMENT_10H          = 210219,
    GO_ELEMENTIUM_FRAGMENT_25H          = 210220,
    GO_ULTRAXION_LOOT_10N               = 210160,
    GO_ULTRAXION_LOOT_25N               = 210161,
    GO_ULTRAXION_LOOT_10H               = 210162,
    GO_ULTRAXION_LOOT_25H               = 210163,
};

enum SharedSpells
{
    SPELL_MORCHOK_SIEGE_MISSILE_1               = 107541, //Siege of Dragon Blight
    SPELL_MORCHOK_SIEGE_MISSILE_2               = 110307,

    SPELL_TELEPORT_VISUAL_ACTIVE                = 108203,
    SPELL_TELEPORT_VISUAL_DISABLED              = 108227,

    SPELL_CHARGING_UP_LIFE                      = 108490,
    SPELL_CHARGING_UP_MAGIC                     = 108491,
    SPELL_CHARGING_UP_EARTH                     = 108492,
    SPELL_CHARGING_UP_TIME                      = 108493,
    SPELL_CHARGING_UP_DREAMS                    = 108494,
    SPELL_WARD_OF_TIME                          = 108160,
    SPELL_WARD_OF_EARTH                         = 108161,
    SPELL_WARD_OF_MAGIC                         = 108162,
    SPELL_WARD_OF_LIFE                          = 108163,
    SPELL_WARD_OF_DREAMS                        = 108164,

    SPELL_TELEPORT_SINGLE_TO_DEATHWINGS_BACK    = 106054,
    SPELL_DRAGON_SOUL_PARATROOPER_KIT_1         = 104953, // Swayze has it while jumping to spine of deathwing
    SPELL_DRAGON_SOUL_PARATROOPER_KIT_2         = 105008, // Reevs has it while jumping to spine of deathwing

    SPELL_PARACHUTE                             = 110660, // used by players

    SPELL_PLAY_MOVIE_DEATHWING_2                = 106085, // movie before jumping at spine of deathwing
};

enum ActionsEvent
{
    ACTION_START_WYRMREST_EVENT = 1,
    ACTION_DEATHWING_ATTACK        = 2,
    ACTION_RESET_BATTLE         = 3,
};

const Position teleportPos[6] =
{
    {-1779.503662f, -2393.439941f, 45.61f, 3.20f},   // Wyrmrest Temple/Base
    {-1854.233154f, -3068.658691f, -178.34f, 0.46f}, // Yor'sahj The Unsleeping
    {-1743.647827f, -1835.132568f, -220.51f, 4.53f}, // Warlord Zon'ozz
    {-1781.188477f, -2375.122559f, 341.35f, 4.43f},  // Wyrmrest Summit
    {13629.356445f, 13612.099609f, 123.49f, 3.14f},  // Hagara
    {-13854.668945f, -13666.967773f, 275.f, 1.60f},  // Spine
};

const Position ultraxionPos[2] =
{
    { -1689.47f, -2388.03f, 250.083f, 3.28122f}, // spawn
    { -1699.47f, -2388.03f, 355.192993f, 3.21552f }, // move to
};
const Position morchokPos = { -1997.53f, -2408.27f, 70.18f, 0.0f };

const Position skyfirePos = {13444.9f, -12133.3f, 151.21f, 0.0f};
const Position spinedeathwingPos = {-13852.5f, -13665.38f, 297.3786f, 1.53589f};

const Position madnessdeathwingPos = {-12081.390625f, 12160.050781f, 30.60f, 6.03f};

#endif
