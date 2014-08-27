/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __BATTLEGROUNDSA_H
#define __BATTLEGROUNDSA_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Object.h"

#define BG_SA_FLAG_AMOUNT           3
#define BG_SA_DEMOLISHER_AMOUNT     4

enum BG_SA_Status
{
    BG_SA_NOT_STARTED = 0,
    BG_SA_WARMUP,
    BG_SA_ROUND_ONE,
    BG_SA_SECOND_WARMUP,
    BG_SA_ROUND_TWO,
    BG_SA_BONUS_ROUND
};

enum BG_SA_GateState
{
    BG_SA_GATE_OK           = 1,
    BG_SA_GATE_DAMAGED      = 2,
    BG_SA_GATE_DESTROYED    = 3
};

enum BG_SA_EventIds
{
    BG_SA_EVENT_BLUE_GATE_DAMAGED           = 19040,
    BG_SA_EVENT_BLUE_GATE_DESTROYED         = 19045,

    BG_SA_EVENT_GREEN_GATE_DAMAGED          = 19041,
    BG_SA_EVENT_GREEN_GATE_DESTROYED        = 19046,

    BG_SA_EVENT_RED_GATE_DAMAGED            = 19042,
    BG_SA_EVENT_RED_GATE_DESTROYED          = 19047,

    BG_SA_EVENT_PURPLE_GATE_DAMAGED         = 19043,
    BG_SA_EVENT_PURPLE_GATE_DESTROYED       = 19048,

    BG_SA_EVENT_YELLOW_GATE_DAMAGED         = 19044,
    BG_SA_EVENT_YELLOW_GATE_DESTROYED       = 19049,

    BG_SA_EVENT_ANCIENT_GATE_DAMAGED        = 19836,
    BG_SA_EVENT_ANCIENT_GATE_DESTROYED      = 19837,

    BG_SA_EVENT_TITAN_RELIC_ACTIVATED       = 22097
};

enum SASpellIds
{
    SPELL_TELEPORT_DEFENDER                 = 52364,
    SPELL_TELEPORT_ATTACKERS                = 60178,
    SPELL_END_OF_ROUND                      = 52459,
    SPELL_REMOVE_SEAFORIUM                  = 59077,
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT      = 60027,
    SPELL_HORDE_CONTROL_PHASE_SHIFT         = 60028
};

enum SACreatureIds
{
    NPC_KANRETHAD                                   = 29,
    NPC_INVISIBLE_STALKER                           = 15214,
    NPC_WORLD_TRIGGER                               = 22515,
    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC   = 23472,

    NPC_ANTI_PERSONNAL_CANNON                       = 27894,
    NPC_DEMOLISHER_SA                               = 28781,
    NPC_RIGGER_SPARKLIGHT                           = 29260,
    NPC_GORGRIL_RIGSPARK                            = 29262
};

enum SAGameObjectIds
{
    GO_GATE_OF_THE_GREEN_EMERALD            = 190722,
    GO_GATE_OF_THE_PURPLE_AMETHYST          = 190723,
    GO_GATE_OF_THE_BLUE_SAPPHIRE            = 190724,
    GO_GATE_OF_THE_RED_SUN                  = 190726,
    GO_GATE_OF_THE_YELLOW_MOON              = 190727,
    GO_CHAMBER_OF_ANCIENT_RELICS            = 192549,
};

enum BG_SA_Timers
{
    BG_SA_BOAT_START    =  60 * IN_MILLISECONDS,
    BG_SA_WARMUPLENGTH  = 120 * IN_MILLISECONDS,
    BG_SA_ROUNDLENGTH   = 600 * IN_MILLISECONDS
};

enum SASounds
{
    SOUND_GRAVEYARD_TAKEN_HORDE     = 8174,
    SOUND_GRAVEYARD_TAKEN_ALLIANCE  = 8212,
    SOUND_DEFEAT_HORDE              = 15905,
    SOUND_VICTORY_HORDE             = 15906,
    SOUND_VICTORY_ALLIANCE          = 15907,
    SOUND_DEFEAT_ALLIANCE           = 15908,
    SOUND_WALL_DESTROYED_ALLIANCE   = 15909,
    SOUND_WALL_DESTROYED_HORDE      = 15910,
    SOUND_WALL_ATTACKED_HORDE       = 15911,
    SOUND_WALL_ATTACKED_ALLIANCE    = 15912
};

enum SATexts
{
    // Kanrethad
    TEXT_ROUND_STARTED              = 1,
    TEXT_ROUND_1_FINISHED           = 2,

    // Rigger Sparklight / Gorgril Rigspark
    TEXT_SPARKLIGHT_RIGSPARK_SPAWN  = 1,

    // World Trigger
    TEXT_BLUE_GATE_UNDER_ATTACK     = 1,
    TEXT_GREEN_GATE_UNDER_ATTACK    = 2,
    TEXT_RED_GATE_UNDER_ATTACK      = 3,
    TEXT_PURPLE_GATE_UNDER_ATTACK   = 4,
    TEXT_YELLOW_GATE_UNDER_ATTACK   = 5,
    TEXT_YELLOW_GATE_DESTROYED      = 6,
    TEXT_PURPLE_GATE_DESTROYED      = 7,
    TEXT_RED_GATE_DESTROYED         = 8,
    TEXT_GREEN_GATE_DESTROYED       = 9,
    TEXT_BLUE_GATE_DESTROYED        = 10,
    TEXT_EAST_GRAVEYARD_CAPTURED_A  = 11,
    TEXT_WEST_GRAVEYARD_CAPTURED_A  = 12,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_A = 13,
    TEXT_EAST_GRAVEYARD_CAPTURED_H  = 14,
    TEXT_WEST_GRAVEYARD_CAPTURED_H  = 15,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_H = 16,
    TEXT_ANCIENT_GATE_UNDER_ATTACK  = 17,
    TEXT_ANCIENT_GATE_DESTROYED     = 18
};

enum SAWorldStates
{
    BG_SA_TIMER_MINS                = 3559,
    BG_SA_TIMER_SEC_TENS            = 3560,
    BG_SA_TIMER_SEC_DECS            = 3561,
    BG_SA_ALLY_ATTACKS              = 4352,
    BG_SA_HORDE_ATTACKS             = 4353,
    BG_SA_PURPLE_GATEWS             = 3614,
    BG_SA_RED_GATEWS                = 3617,
    BG_SA_BLUE_GATEWS               = 3620,
    BG_SA_GREEN_GATEWS              = 3623,
    BG_SA_YELLOW_GATEWS             = 3638,
    BG_SA_ANCIENT_GATEWS            = 3849,
    BG_SA_LEFT_GY_ALLIANCE          = 3635,
    BG_SA_RIGHT_GY_ALLIANCE         = 3636,
    BG_SA_CENTER_GY_ALLIANCE        = 3637,
    BG_SA_RIGHT_ATT_TOKEN_ALL       = 3627,
    BG_SA_LEFT_ATT_TOKEN_ALL        = 3626,
    BG_SA_LEFT_ATT_TOKEN_HRD        = 3629,
    BG_SA_RIGHT_ATT_TOKEN_HRD       = 3628,
    BG_SA_HORDE_DEFENCE_TOKEN       = 3631,
    BG_SA_ALLIANCE_DEFENCE_TOKEN    = 3630,
    BG_SA_RIGHT_GY_HORDE            = 3632,
    BG_SA_LEFT_GY_HORDE             = 3633,
    BG_SA_CENTER_GY_HORDE           = 3634,
    BG_SA_BONUS_TIMER               = 3571,
    BG_SA_ENABLE_TIMER              = 3564
};

enum BG_SA_NPCs
{
    BG_SA_GUN_1 = 0,
    BG_SA_GUN_2,
    BG_SA_GUN_3,
    BG_SA_GUN_4,
    BG_SA_GUN_5,
    BG_SA_GUN_6,
    BG_SA_GUN_7,
    BG_SA_GUN_8,
    BG_SA_GUN_9,
    BG_SA_GUN_10,
    BG_SA_DEMOLISHER_1,
    BG_SA_DEMOLISHER_2,
    BG_SA_DEMOLISHER_3,
    BG_SA_DEMOLISHER_4,
    BG_SA_DEMOLISHER_5,
    BG_SA_DEMOLISHER_6,
    BG_SA_DEMOLISHER_7,
    BG_SA_DEMOLISHER_8,
    BG_SA_NPC_SPARKLIGHT,
    BG_SA_NPC_RIGSPARK,
    BG_SA_NPC_KANRETHAD,
    BG_SA_MAXNPC
};

enum BG_SA_Boat
{
    BG_SA_BOAT_ONE_A    = 193182,
    BG_SA_BOAT_TWO_H    = 193183,
    BG_SA_BOAT_ONE_H    = 193184,
    BG_SA_BOAT_TWO_A    = 193185
};

uint32 const BG_SA_NpcEntries[BG_SA_MAXNPC] =
{
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    NPC_ANTI_PERSONNAL_CANNON,
    // 4 beach demolishers
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    // 4 factory demolishers
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    NPC_DEMOLISHER_SA,
    // Used Demolisher Salesman
    NPC_RIGGER_SPARKLIGHT,
    NPC_GORGRIL_RIGSPARK,
    // Kanrethad
    NPC_KANRETHAD
};

Position const BG_SA_NpcSpawnlocs[BG_SA_MAXNPC] =
{
    // Cannons
    { 1436.429f, 110.05f, 41.407f, 5.4f },
    { 1404.9023f, 84.758f, 41.183f, 5.46f },
    { 1068.693f, -86.951f, 93.81f, 0.02f },
    { 1068.83f, -127.56f, 96.45f, 0.0912f },
    { 1422.115f, -196.433f, 42.1825f, 1.0222f },
    { 1454.887f, -220.454f, 41.956f, 0.9627f },
    { 1232.345f, -187.517f, 66.945f, 0.45f },
    { 1249.634f, -224.189f, 66.72f, 0.635f },
    { 1236.213f, 92.287f, 64.965f, 5.751f },
    { 1215.11f, 57.772f, 64.739f, 5.78f },
    // Demolishers
    { 1611.597656f, -117.270073f, 8.719355f, 2.513274f},
    { 1575.562500f, -158.421875f, 5.024450f, 2.129302f},
    { 1618.047729f, 61.424641f, 7.248210f, 3.979351f},
    { 1575.103149f, 98.873344f, 2.830360f, 3.752458f},
    // Demolishers 2
    { 1371.055786f, -317.071136f, 35.007359f, 1.947460f},
    { 1424.034912f, -260.195190f, 31.084425f, 2.820013f},
    { 1353.139893f, 223.745438f, 35.265411f, 4.343684f},
    { 1404.809570f, 197.027237f, 32.046032f, 3.605401f},
    // Npcs
    { 1348.644165f, -298.786469f, 31.080130f, 1.710423f},
    { 1358.191040f, 195.527786f, 31.018187f, 4.171337f},
    { 841.921f, -134.194f, 196.838f, 6.23082f }
};

enum BG_SA_Objects
{
    BG_SA_GREEN_GATE = 0,
    BG_SA_YELLOW_GATE,
    BG_SA_BLUE_GATE,
    BG_SA_RED_GATE,
    BG_SA_PURPLE_GATE,
    BG_SA_ANCIENT_GATE,
    BG_SA_TITAN_RELIC,
    BG_SA_PORTAL_DEFFENDER_BLUE,
    BG_SA_PORTAL_DEFFENDER_GREEN,
    BG_SA_PORTAL_DEFFENDER_YELLOW,
    BG_SA_PORTAL_DEFFENDER_PURPLE,
    BG_SA_PORTAL_DEFFENDER_RED,
    BG_SA_BOAT_ONE,
    BG_SA_BOAT_TWO,
    BG_SA_SIGIL_1,
    BG_SA_SIGIL_2,
    BG_SA_SIGIL_3,
    BG_SA_SIGIL_4,
    BG_SA_SIGIL_5,
    BG_SA_CENTRAL_FLAGPOLE,
    BG_SA_RIGHT_FLAGPOLE,
    BG_SA_LEFT_FLAGPOLE,
    BG_SA_CENTRAL_FLAG,
    BG_SA_RIGHT_FLAG,
    BG_SA_LEFT_FLAG,
    BG_SA_BOMB,
    BG_SA_MAXOBJ = BG_SA_BOMB+68
};

Position const BG_SA_ObjSpawnlocs[BG_SA_MAXOBJ] =
{
    { 1411.57f, 108.163f, 28.692f, 5.441f },
    { 1055.452f, -108.1f, 82.134f, 0.034f },
    { 1431.3413f, -219.437f, 30.893f, 0.9736f },
    { 1227.667f, -212.555f, 55.372f, 0.5023f },
    { 1214.681f, 81.21f, 53.413f, 5.745f },
    { 878.555f, -108.2f, 117.845f, 0.0f },
    { 836.5f, -108.8f, 120.219f, 0.0f },
    // Portal
    {1468.380005f, -225.798996f, 30.896200f, 0.0f}, //blue
    {1394.270020f, 72.551399f, 31.054300f, 0.0f}, //green
    {1065.260010f, -89.79501f, 81.073402f, 0.0f}, //yellow
    {1216.069946f, 47.904301f, 54.278198f, 0.0f}, //purple
    {1255.569946f, -233.548996f, 56.43699f, 0.0f}, //red
    // Ships
    { 2679.696777f, -826.891235f, 3.712860f, 5.78367f}, //rot2 1 rot3 0.0002f
    { 2574.003662f, 981.261475f, 2.603424f, 0.807696f},
    // Sigils
    { 1414.054f, 106.72f, 41.442f, 5.441f },
    { 1060.63f, -107.8f, 94.7f, 0.034f },
    { 1433.383f, -216.4f, 43.642f, 0.9736f },
    { 1230.75f, -210.724f, 67.611f, 0.5023f },
    { 1217.8f, 79.532f, 66.58f, 5.745f },
    // Flagpoles
    { 1215.114258f, -65.711861f, 70.084267f, -3.124123f},
    {1338.863892f, -153.336533f, 30.895121f, -2.530723f},
    {1309.124268f, 9.410645f, 30.893402f, -1.623156f},
    // Flags
    { 1215.108032f, -65.715767f, 70.084267f, -3.124123f},
    { 1338.859253f, -153.327316f, 30.895077f, -2.530723f},
    { 1309.192017f, 9.416233f, 30.893402f, 1.518436f},
    // Bombs
    {1333.45f, 211.354f, 31.0538f, 5.03666f},
    {1334.29f, 209.582f, 31.0532f, 1.28088f},
    {1332.72f, 210.049f, 31.0532f, 1.28088f},
    {1334.28f, 210.78f, 31.0538f, 3.85856f},
    {1332.64f, 211.39f, 31.0532f, 1.29266f},
    {1371.41f, 194.028f, 31.5107f, 0.753095f},
    {1372.39f, 194.951f, 31.4679f, 0.753095f},
    {1371.58f, 196.942f, 30.9349f, 1.01777f},
    {1370.43f, 196.614f, 30.9349f, 0.957299f},
    {1369.46f, 196.877f, 30.9351f, 2.45348f},
    {1370.35f, 197.361f, 30.9349f, 1.08689f},
    {1369.47f, 197.941f, 30.9349f, 0.984787f},
    {1592.49f, 47.5969f, 7.52271f, 4.63218f},
    {1593.91f, 47.8036f, 7.65856f, 4.63218f},
    {1593.13f, 46.8106f, 7.54073f, 4.63218f},
    {1589.22f, 36.3616f, 7.45975f, 4.64396f},
    {1588.24f, 35.5842f, 7.55613f, 4.79564f},
    {1588.14f, 36.7611f, 7.49675f, 4.79564f},
    {1595.74f, 35.5278f, 7.46602f, 4.90246f},
    {1596, 36.6475f, 7.47991f, 4.90246f},
    {1597.03f, 36.2356f, 7.48631f, 4.90246f},
    {1597.93f, 37.1214f, 7.51725f, 4.90246f},
    {1598.16f, 35.888f, 7.50018f, 4.90246f},
    {1579.6f, -98.0917f, 8.48478f, 1.37996f},
    {1581.2f, -98.401f, 8.47483f, 1.37996f},
    {1580.38f, -98.9556f, 8.4772f, 1.38781f},
    {1585.68f, -104.966f, 8.88551f, 0.493246f},
    {1586.15f, -106.033f, 9.10616f, 0.493246f},
    {1584.88f, -105.394f, 8.82985f, 0.493246f},
    {1581.87f, -100.899f, 8.46164f, 0.929142f},
    {1581.48f, -99.4657f, 8.46926f, 0.929142f},
    {1583.2f, -91.2291f, 8.49227f, 1.40038f},
    {1581.94f, -91.0119f, 8.49977f, 1.40038f},
    {1582.33f, -91.951f, 8.49353f, 1.1844f},
    {1342.06f, -304.049f, 30.9532f, 5.59507f},
    {1340.96f, -304.536f, 30.9458f, 1.28323f},
    {1341.22f, -303.316f, 30.9413f, 0.486051f},
    {1342.22f, -302.939f, 30.986f, 4.87643f},
    {1382.16f, -287.466f, 32.3063f, 4.80968f},
    {1381, -287.58f, 32.2805f, 4.80968f},
    {1381.55f, -286.536f, 32.3929f, 2.84225f},
    {1382.75f, -286.354f, 32.4099f, 1.00442f},
    {1379.92f, -287.34f, 32.2872f, 3.81615f},
    {1100.52f, -2.41391f, 70.2984f, 0.131054f},
    {1099.35f, -2.13851f, 70.3375f, 4.4586f},
    {1099.59f, -1.00329f, 70.238f, 2.49903f},
    {1097.79f, 0.571316f, 70.159f, 4.00307f},
    {1098.74f, -7.23252f, 70.7972f, 4.1523f},
    {1098.46f, -5.91443f, 70.6715f, 4.1523f},
    {1097.53f, -7.39704f, 70.7959f, 4.1523f},
    {1097.32f, -6.64233f, 70.7424f, 4.1523f},
    {1096.45f, -5.96664f, 70.7242f, 4.1523f},
    {971.725f, 0.496763f, 86.8467f, 2.09233f},
    {973.589f, 0.119518f, 86.7985f, 3.17225f},
    {972.524f, 1.25333f, 86.8351f, 5.28497f},
    {971.993f, 2.05668f, 86.8584f, 5.28497f},
    {973.635f, 2.11805f, 86.8197f, 2.36722f},
    {974.791f, 1.74679f, 86.7942f, 1.5936f},
    {974.771f, 3.0445f, 86.8125f, 0.647199f},
    {979.554f, 3.6037f, 86.7923f, 1.69178f},
    {979.758f, 2.57519f, 86.7748f, 1.76639f},
    {980.769f, 3.48904f, 86.7939f, 1.76639f},
    {979.122f, 2.87109f, 86.7794f, 1.76639f},
    {986.167f, 4.85363f, 86.8439f, 1.5779f},
    {986.176f, 3.50367f, 86.8217f, 1.5779f},
    {987.33f, 4.67389f, 86.8486f, 1.5779f},
    {985.23f, 4.65898f, 86.8368f, 1.5779f},
    {984.556f, 3.54097f, 86.8137f, 1.5779f},
};

/* Ships:
 * 193182 - ally
 * 193183 - horde
 * 193184 - horde
 * 193185 - ally
 * Banners:
 * 191308 - left one,
 * 191306 - right one,
 * 191310 - central,
 * Ally ones, substract 1
 * to get horde ones.
 */

uint32 const BG_SA_ObjEntries[BG_SA_MAXOBJ + BG_SA_FLAG_AMOUNT] =
{
    190722,
    190727,
    190724,
    190726,
    190723,
    192549,
    192834,
    192819,
    192819,
    192819,
    192819,
    192819,
    0, // Boat
    0, // Boat
    192687,
    192685,
    192689,
    192690,
    192691,
    191311,
    191311,
    191311,
    191310,
    191306,
    191308,
    190753
};

uint32 const BG_SA_Factions[2] =
{
    1732,
    1735,
};

enum BG_SA_Graveyards
{
    BG_SA_BEACH_GY = 0,
    BG_SA_DEFENDER_LAST_GY,
    BG_SA_RIGHT_CAPTURABLE_GY,
    BG_SA_LEFT_CAPTURABLE_GY,
    BG_SA_CENTRAL_CAPTURABLE_GY,
    BG_SA_MAX_GY
};

const uint32 BG_SA_GYEntries[BG_SA_MAX_GY] =
{
    1350,
    1349,
    1347,
    1346,
    1348,
};

float const BG_SA_GYOrientation[BG_SA_MAX_GY] =
{
    6.202f,
    1.926f, // right capturable GY
    3.917f, // left capturable GY
    3.104f, // center, capturable
    6.148f, // defender last GY
};

struct GateInfo
{
    uint8 GateId;
    uint32 GameObjectId;
    uint32 WorldState;
    uint8 DamagedText;
    uint8 DestroyedText;
};

#define MAX_GATES 6
GateInfo const Gates[MAX_GATES] =
{
    { BG_SA_GREEN_GATE,   GO_GATE_OF_THE_GREEN_EMERALD,   BG_SA_GREEN_GATEWS,   TEXT_GREEN_GATE_UNDER_ATTACK,   TEXT_GREEN_GATE_DESTROYED   },
    { BG_SA_YELLOW_GATE,  GO_GATE_OF_THE_YELLOW_MOON,     BG_SA_YELLOW_GATEWS,  TEXT_YELLOW_GATE_UNDER_ATTACK,  TEXT_YELLOW_GATE_DESTROYED  },
    { BG_SA_BLUE_GATE,    GO_GATE_OF_THE_BLUE_SAPPHIRE,   BG_SA_BLUE_GATEWS,    TEXT_BLUE_GATE_UNDER_ATTACK,    TEXT_BLUE_GATE_DESTROYED    },
    { BG_SA_RED_GATE,     GO_GATE_OF_THE_RED_SUN,         BG_SA_RED_GATEWS,     TEXT_RED_GATE_UNDER_ATTACK,     TEXT_RED_GATE_DESTROYED     },
    { BG_SA_PURPLE_GATE,  GO_GATE_OF_THE_PURPLE_AMETHYST, BG_SA_PURPLE_GATEWS,  TEXT_PURPLE_GATE_UNDER_ATTACK,  TEXT_PURPLE_GATE_DESTROYED  },
    { BG_SA_ANCIENT_GATE, GO_CHAMBER_OF_ANCIENT_RELICS,   BG_SA_ANCIENT_GATEWS, TEXT_ANCIENT_GATE_UNDER_ATTACK, TEXT_ANCIENT_GATE_DESTROYED }
};

struct BG_SA_RoundScore
{
    TeamId winner;
    uint32 time;
};

struct BattlegroundSAScore final : public BattlegroundScore
{
    friend class BattlegroundSA;

    protected:
        BattlegroundSAScore(uint64 playerGuid) : BattlegroundScore(playerGuid), DemolishersDestroyed(0), GatesDestroyed(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_DESTROYED_DEMOLISHER:
                    DemolishersDestroyed += value;
                    break;
                case SCORE_DESTROYED_WALL:
                    GatesDestroyed += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data) final override
        {
            data << uint32(2); // Objectives Count
            data << uint32(DemolishersDestroyed);
            data << uint32(GatesDestroyed);
        }

        uint32 GetAttr1() const { return DemolishersDestroyed; }
        uint32 GetAttr2() const { return GatesDestroyed; }

        uint32 DemolishersDestroyed;
        uint32 GatesDestroyed;
};

/// Class for manage Strand of Ancient battleground
class BattlegroundSA : public Battleground
{
    public:
        BattlegroundSA();
        ~BattlegroundSA();

        /**
         * \brief Called every time for update battle data
         * -Update timer
         * -Round switch
         */
        void PostUpdateImpl(uint32 diff) override;

        /* inherited from BattlegroundClass */
        /// Called when a player join battle
        void AddPlayer(Player* player) override;
        /// Called when battle start
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;
        /// Called for ini battleground, after that the first player be entered
        bool SetupBattleground() override;
        void Reset() override;
        /// Called for generate packet contain worldstate data
        void FillInitialWorldStates(WorldPacket& data) override;
        /// Called when a player kill a unit in bg
        void HandleKillUnit(Creature* creature, Player* killer) override;
        /// Return the nearest graveyard where player can respawn
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;
        /// Called when someone activates an event
        void ProcessEvent(WorldObject* /*obj*/, uint32 /*eventId*/, WorldObject* /*invoker*/ = NULL) override;
        /// Called when a player click on flag (graveyard flag)
        void EventPlayerClickedOnFlag(Player* source, GameObject* go) override;
        /// Called when a player clicked on relic
        void TitanRelicActivated(Player* clicker);

        /// Return GateInfo, relative to bg data, according to gameobject entry
        GateInfo const* GetGate(uint32 entry)
        {
            for (uint8 i = 0; i < MAX_GATES; ++i)
                if (Gates[i].GameObjectId == entry)
                    return &Gates[i];
            return NULL;
        }

        /// Called on battleground ending
        void EndBattleground(uint32 winner) override;

        /// Called when a player leave battleground
        void RemovePlayer(Player* player, uint64 guid, uint32 team) override;
        void HandleAreaTrigger(Player* Source, uint32 Trigger) override;

        /* Scorekeeping */

        // Achievement: Not Even a Scratch
        bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target = NULL, uint32 miscValue = 0) override;

        // Control Phase Shift
        bool IsSpellAllowed(uint32 spellId, Player const* player) const override;

    private:

        /**
         * \brief Called on setup and between the two round
         * -Delete all gameobject / creature
         * -Respawn all gameobject / creature to have good faction
         */
        bool ResetObjs();
        /// Called for start ship movement
        void StartShips();
        /**
         * \brief Called between the two round
         * -Teleport all players to good location
         */
        void TeleportPlayers();
        /**
         * \brief Called on start and between the two round
         * -Update faction of all vehicle
         */
        void OverrideGunFaction();
        /// Set selectable or not demolisher, called on battle start, when boats arrive to dock
        void DemolisherStartState(bool start);
        /**
         * \brief Called when a gate is destroy
         * -Give honor to player witch destroy it
         * -Update worldstate
         * -Delete gameobject in front of door (lighting object, with different colours for each door)
         */
        void DestroyGate(Player* player, GameObject* go) override;
        /// Update timer worldstate
        void SendTime();
        /**
         * \brief Called when a graveyard is capture
         * -Update spiritguide
         * -Update gameobject (flag)
         * -Update Worldstate
         * -Send warning for announce this
         * \param i : id of graveyard
         * \param Source : Player who capture gy
         */
        void CaptureGraveyard(BG_SA_Graveyards i, Player* Source);
        /// Switch on/off timer worldstate
        void ToggleTimer();

        /// Respawn dead demolisher
        void UpdateDemolisherSpawns();

        /// Send packet to player for create boats (client part)
        void SendTransportInit(Player* player);
        /// Send packet to player for destroy boats (client part)
        void SendTransportsRemove(Player* player);

        /// Id of attacker team
        TeamId Attackers;

        /// Totale elapsed time of current round
        uint32 TotalTime;
        /// Max time of round
        uint32 EndRoundTimer;
        /// For know if boats has start moving or not yet
        bool ShipsStarted;
        /// Status of each gate (Destroy/Damage/Intact)
        BG_SA_GateState GateStatus[MAX_GATES];
        /// Statu of battle (Start or not, and what round)
        BG_SA_Status Status;
        /// Team witch conntrol each graveyard
        TeamId GraveyardStatus[BG_SA_MAX_GY];
        /// Score of each round
        BG_SA_RoundScore RoundScores[2];
        /// used for know we are in timer phase or not (used for worldstate update)
        bool TimerEnabled;
        /// 5secs before starting the 1min countdown for second round
        uint32 UpdateWaitTimer;
        /// for know if warning about second round start has been sent
        bool SignaledRoundTwo;
        /// for know if warning about second round start has been sent
        bool SignaledRoundTwoHalfMin;
        /// for know if second round has been init
        bool InitSecondRound;
        std::map<uint32/*id*/, uint32/*timer*/> DemoliserRespawnList;

        // Achievement: Defense of the Ancients
        bool _gateDestroyed;

        // Achievement: Not Even a Scratch
        bool _allVehiclesAlive[BG_TEAMS_COUNT];
};
#endif
