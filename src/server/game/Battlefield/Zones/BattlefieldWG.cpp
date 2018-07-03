/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

/// @todo Implement proper support for vehicle+player teleportation
/// @todo Use spell victory/defeat in wg instead of RewardMarkOfHonor() && RewardHonor
/// @todo Add proper implement of achievement

#include "BattlefieldWG.h"
#include "AchievementMgr.h"
#include "Battleground.h"
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "DB2Stores.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "World.h"
#include "WorldSession.h"
#include "WorldStatePackets.h"

struct BfWGCoordGY
{
    Position Pos;
    uint32 GraveyardID;
    uint32 TextID;          // for gossip menu
    TeamId StartControl;
};

// 7 in sql, 7 in header
BfWGCoordGY const WGGraveYard[BATTLEFIELD_WG_GRAVEYARD_MAX] =
{
    { { 5104.750f, 2300.940f, 368.579f, 0.733038f }, 1329, BATTLEFIELD_WG_GOSSIPTEXT_GY_NE,       TEAM_NEUTRAL  },
    { { 5099.120f, 3466.036f, 368.484f, 5.317802f }, 1330, BATTLEFIELD_WG_GOSSIPTEXT_GY_NW,       TEAM_NEUTRAL  },
    { { 4314.648f, 2408.522f, 392.642f, 6.268125f }, 1333, BATTLEFIELD_WG_GOSSIPTEXT_GY_SE,       TEAM_NEUTRAL  },
    { { 4331.716f, 3235.695f, 390.251f, 0.008500f }, 1334, BATTLEFIELD_WG_GOSSIPTEXT_GY_SW,       TEAM_NEUTRAL  },
    { { 5537.986f, 2897.493f, 517.057f, 4.819249f }, 1285, BATTLEFIELD_WG_GOSSIPTEXT_GY_KEEP,     TEAM_NEUTRAL  },
    { { 5032.454f, 3711.382f, 372.468f, 3.971623f }, 1331, BATTLEFIELD_WG_GOSSIPTEXT_GY_HORDE,    TEAM_HORDE    },
    { { 5140.790f, 2179.120f, 390.950f, 1.972220f }, 1332, BATTLEFIELD_WG_GOSSIPTEXT_GY_ALLIANCE, TEAM_ALLIANCE },
};

uint32 const ClockWorldState[]         = { 3781, 4354 };
uint32 const WintergraspFaction[]      = { 1732, 1735, 35 };

Position const WintergraspStalkerPos   = { 4948.985f, 2937.789f, 550.5172f,  1.815142f };

Position const WintergraspRelicPos     = { 5440.379f, 2840.493f, 430.2816f, -1.832595f };
QuaternionData const WintergraspRelicRot    = { 0.f, 0.f, -0.7933531f, 0.6087617f };

uint8 const WG_MAX_OBJ              = 32;
uint8 const WG_MAX_TURRET           = 15;
uint8 const WG_MAX_TELEPORTER       = 12;
uint8 const WG_MAX_WORKSHOP         = 6;
uint8 const WG_MAX_TOWER            = 7;

// *****************************************************
// ************ Destructible (Wall, Tower..) ***********
// *****************************************************

struct WintergraspBuildingSpawnData
{
    uint32 entry;
    uint32 WorldState;
    Position pos;
    QuaternionData rot;
    WintergraspGameObjectBuildingType type;
};

WintergraspBuildingSpawnData const WGGameObjectBuilding[WG_MAX_OBJ] =
{
    // Wall (Not spawned in db)
    // Entry  WS      X          Y          Z           O                rX   rY   rZ             rW             Type
    { 190219, 3749, { 5371.457f, 3047.472f, 407.5710f,  3.14159300f }, { 0.f, 0.f, -1.000000000f, 0.00000000f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190220, 3750, { 5331.264f, 3047.105f, 407.9228f,  0.05235888f }, { 0.f, 0.f,  0.026176450f, 0.99965730f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191795, 3764, { 5385.841f, 2909.490f, 409.7127f,  0.00872424f }, { 0.f, 0.f,  0.004362106f, 0.99999050f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191796, 3772, { 5384.452f, 2771.835f, 410.2704f,  3.14159300f }, { 0.f, 0.f, -1.000000000f, 0.00000000f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191799, 3762, { 5371.436f, 2630.610f, 408.8163f,  3.13285800f }, { 0.f, 0.f,  0.999990500f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191800, 3766, { 5301.838f, 2909.089f, 409.8661f,  0.00872424f }, { 0.f, 0.f,  0.004362106f, 0.99999050f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191801, 3770, { 5301.063f, 2771.411f, 409.9014f,  3.14159300f }, { 0.f, 0.f, -1.000000000f, 0.00000000f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191802, 3751, { 5280.197f, 2995.583f, 408.8249f,  1.61442800f }, { 0.f, 0.f,  0.722363500f, 0.69151360f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191803, 3752, { 5279.136f, 2956.023f, 408.6041f,  1.57079600f }, { 0.f, 0.f,  0.707106600f, 0.70710690f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191804, 3767, { 5278.685f, 2882.513f, 409.5388f,  1.57079600f }, { 0.f, 0.f,  0.707106600f, 0.70710690f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191806, 3769, { 5279.502f, 2798.945f, 409.9983f,  1.57079600f }, { 0.f, 0.f,  0.707106600f, 0.70710690f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191807, 3759, { 5279.937f, 2724.766f, 409.9452f,  1.56207000f }, { 0.f, 0.f,  0.704014800f, 0.71018530f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191808, 3760, { 5279.601f, 2683.786f, 409.8488f,  1.55334100f }, { 0.f, 0.f,  0.700908700f, 0.71325110f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191809, 3761, { 5330.955f, 2630.777f, 409.2826f,  3.13285800f }, { 0.f, 0.f,  0.999990500f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190369, 3753, { 5256.085f, 2933.963f, 409.3571f,  3.13285800f }, { 0.f, 0.f,  0.999990500f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190370, 3758, { 5257.463f, 2747.327f, 409.7427f, -3.13285800f }, { 0.f, 0.f, -0.999990500f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190371, 3754, { 5214.960f, 2934.089f, 409.1905f, -0.00872424f }, { 0.f, 0.f, -0.004362106f, 0.99999050f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190372, 3757, { 5215.821f, 2747.566f, 409.1884f, -3.13285800f }, { 0.f, 0.f, -0.999990500f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190374, 3755, { 5162.273f, 2883.043f, 410.2556f,  1.57952200f }, { 0.f, 0.f,  0.710185100f, 0.70401500f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 190376, 3756, { 5163.724f, 2799.838f, 409.2270f,  1.57952200f }, { 0.f, 0.f,  0.710185100f, 0.70401500f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },

    // Tower of keep (Not spawned in db)
    { 190221, 3711, { 5281.154f, 3044.588f, 407.8434f,  3.115388f }, { 0.f, 0.f,  0.9999142f, 0.013101960f }, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER }, // NW
    { 190373, 3713, { 5163.757f, 2932.228f, 409.1904f,  3.124123f }, { 0.f, 0.f,  0.9999619f, 0.008734641f }, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER }, // SW
    { 190377, 3714, { 5166.397f, 2748.368f, 409.1884f, -1.570796f }, { 0.f, 0.f, -0.7071066f, 0.707106900f }, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER }, // SE
    { 190378, 3712, { 5281.192f, 2632.479f, 409.0985f, -1.588246f }, { 0.f, 0.f, -0.7132492f, 0.700910500f }, BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER }, // NE

    // Wall (with passage) (Not spawned in db)
    { 191797, 3765, { 5343.290f, 2908.860f, 409.5757f, 0.00872424f }, { 0.f, 0.f,  0.004362106f, 0.9999905f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191798, 3771, { 5342.719f, 2771.386f, 409.6249f, 3.14159300f }, { 0.f, 0.f, -1.000000000f, 0.0000000f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },
    { 191805, 3768, { 5279.126f, 2840.797f, 409.7826f, 1.57952200f }, { 0.f, 0.f,  0.710185100f, 0.7040150f }, BATTLEFIELD_WG_OBJECTTYPE_WALL },

    // South tower (Not spawned in db)
    { 190356, 3704, { 4557.173f, 3623.943f, 395.8828f,  1.675516f }, { 0.f, 0.f,  0.7431450f, 0.669130400f }, BATTLEFIELD_WG_OBJECTTYPE_TOWER }, // W
    { 190357, 3705, { 4398.172f, 2822.497f, 405.6270f, -3.124123f }, { 0.f, 0.f, -0.9999619f, 0.008734641f }, BATTLEFIELD_WG_OBJECTTYPE_TOWER }, // S
    { 190358, 3706, { 4459.105f, 1944.326f, 434.9912f, -2.002762f }, { 0.f, 0.f, -0.8422165f, 0.539139500f }, BATTLEFIELD_WG_OBJECTTYPE_TOWER }, // E

    // Door of forteress (Not spawned in db)
    { GO_WINTERGRASP_FORTRESS_GATE, 3763, { 5162.991f, 2841.232f, 410.1892f, -3.132858f }, { 0.f, 0.f, -0.9999905f, 0.00436732f }, BATTLEFIELD_WG_OBJECTTYPE_DOOR },

    // Last door (Not spawned in db)
    { GO_WINTERGRASP_VAULT_GATE, 3773, { 5397.108f, 2841.54f, 425.9014f, 3.141593f }, { 0.f, 0.f, -1.f, 0.f }, BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST },
};

struct StaticWintergraspTowerInfo
{
    uint8 TowerId;

    struct
    {
        uint8 Damaged;
        uint8 Destroyed;
    } TextIds;
};

StaticWintergraspTowerInfo const TowerData[WG_MAX_TOWER] =
{
    { BATTLEFIELD_WG_TOWER_FORTRESS_NW,   { BATTLEFIELD_WG_TEXT_NW_KEEPTOWER_DAMAGE,   BATTLEFIELD_WG_TEXT_NW_KEEPTOWER_DESTROY   } },
    { BATTLEFIELD_WG_TOWER_FORTRESS_SW,   { BATTLEFIELD_WG_TEXT_SW_KEEPTOWER_DAMAGE,   BATTLEFIELD_WG_TEXT_SW_KEEPTOWER_DESTROY   } },
    { BATTLEFIELD_WG_TOWER_FORTRESS_SE,   { BATTLEFIELD_WG_TEXT_SE_KEEPTOWER_DAMAGE,   BATTLEFIELD_WG_TEXT_SE_KEEPTOWER_DESTROY   } },
    { BATTLEFIELD_WG_TOWER_FORTRESS_NE,   { BATTLEFIELD_WG_TEXT_NE_KEEPTOWER_DAMAGE,   BATTLEFIELD_WG_TEXT_NE_KEEPTOWER_DESTROY   } },
    { BATTLEFIELD_WG_TOWER_SHADOWSIGHT,   { BATTLEFIELD_WG_TEXT_WESTERN_TOWER_DAMAGE,  BATTLEFIELD_WG_TEXT_WESTERN_TOWER_DESTROY  } },
    { BATTLEFIELD_WG_TOWER_WINTER_S_EDGE, { BATTLEFIELD_WG_TEXT_SOUTHERN_TOWER_DAMAGE, BATTLEFIELD_WG_TEXT_SOUTHERN_TOWER_DESTROY } },
    { BATTLEFIELD_WG_TOWER_FLAMEWATCH,    { BATTLEFIELD_WG_TEXT_EASTERN_TOWER_DAMAGE,  BATTLEFIELD_WG_TEXT_EASTERN_TOWER_DESTROY  } }
};

Position const WGTurret[WG_MAX_TURRET] =
{
    { 5391.19f, 3060.8f,  419.616f, 1.69557f },
    { 5266.75f, 2976.5f,  421.067f, 3.20354f },
    { 5234.86f, 2948.8f,  420.88f,  1.61311f },
    { 5323.05f, 2923.7f,  421.645f, 1.5817f },
    { 5363.82f, 2923.87f, 421.709f, 1.60527f },
    { 5264.04f, 2861.34f, 421.587f, 3.21142f },
    { 5264.68f, 2819.78f, 421.656f, 3.15645f },
    { 5322.16f, 2756.69f, 421.646f, 4.69978f },
    { 5363.78f, 2756.77f, 421.629f, 4.78226f },
    { 5236.2f,  2732.68f, 421.649f, 4.72336f },
    { 5265.02f, 2704.63f, 421.7f,   3.12507f },
    { 5350.87f, 2616.03f, 421.243f, 4.72729f },
    { 5390.95f, 2615.5f,  421.126f, 4.6409f },
    { 5148.8f,  2820.24f, 421.621f, 3.16043f },
    { 5147.98f, 2861.93f, 421.63f,  3.18792f },
};

struct WintergraspObjectPositionData
{
    Position Pos;
    uint32 HordeEntry;
    uint32 AllianceEntry;
};

struct WintergraspGameObjectData
{
    Position Pos;
    QuaternionData Rot;
    uint32 HordeEntry;
    uint32 AllianceEntry;
};

WintergraspGameObjectData const WGPortalDefenderData[WG_MAX_TELEPORTER] =
{
    // Player teleporter
    { { 5153.408f, 2901.349f, 409.1913f, -0.06981169f }, { 0.f, 0.f, -0.03489876f, 0.9993908f }, 190763, 191575 },
    { { 5268.698f, 2666.421f, 409.0985f, -0.71558490f }, { 0.f, 0.f, -0.35020730f, 0.9366722f }, 190763, 191575 },
    { { 5197.050f, 2944.814f, 409.1913f,  2.33874000f }, { 0.f, 0.f,  0.92050460f, 0.3907318f }, 190763, 191575 },
    { { 5196.671f, 2737.345f, 409.1892f, -2.93213900f }, { 0.f, 0.f, -0.99452110f, 0.1045355f }, 190763, 191575 },
    { { 5314.580f, 3055.852f, 408.8620f,  0.54105060f }, { 0.f, 0.f,  0.26723770f, 0.9636307f }, 190763, 191575 },
    { { 5391.277f, 2828.094f, 418.6752f, -2.16420600f }, { 0.f, 0.f, -0.88294700f, 0.4694727f }, 190763, 191575 },
    { { 5153.931f, 2781.671f, 409.2455f,  1.65806200f }, { 0.f, 0.f,  0.73727700f, 0.6755905f }, 190763, 191575 },
    { { 5311.445f, 2618.931f, 409.0916f, -2.37364400f }, { 0.f, 0.f, -0.92718320f, 0.3746083f }, 190763, 191575 },
    { { 5269.208f, 3013.838f, 408.8276f, -1.76278200f }, { 0.f, 0.f, -0.77162460f, 0.6360782f }, 190763, 191575 },

    { { 5401.634f, 2853.667f, 418.6748f,  2.63544400f }, { 0.f, 0.f,  0.96814730f, 0.2503814f }, 192819, 192819 }, // return portal inside fortress, neutral
    // Vehicle teleporter
    { { 5314.515f, 2703.687f, 408.5502f, -0.89011660f }, { 0.f, 0.f, -0.43051050f, 0.9025856f }, 192951, 192951 },
    { { 5316.252f, 2977.042f, 408.5385f, -0.82030330f }, { 0.f, 0.f, -0.39874840f, 0.9170604f }, 192951, 192951 }
};

// *********************************************************
// **********Tower Element(GameObject, Creature)************
// *********************************************************

struct WintergraspTowerData
{
    uint32 towerEntry;                  // Gameobject id of tower
    std::vector<WintergraspGameObjectData> GameObject;   // Gameobject position and entry (Horde/Alliance)

    // Creature: Turrets and Guard /// @todo: Killed on Tower destruction ? Tower damage ? Requires confirming
    std::vector<WintergraspObjectPositionData> CreatureBottom;
};

uint8 const WG_MAX_ATTACKTOWERS = 3;
// 192414 : 0 in sql, 1 in header
// 192278 : 0 in sql, 3 in header
WintergraspTowerData const AttackTowers[WG_MAX_ATTACKTOWERS] =
{
    // West tower
    {
        190356,
        {
            { { 4559.113f, 3606.216f, 419.9992f, 4.799657f }, { 0.f, 0.f, -0.67558960f, 0.73727790f }, 192488, 192501 },    // Flag on tower
            { { 4539.420f, 3622.490f, 420.0342f, 3.211419f }, { 0.f, 0.f, -0.99939060f, 0.03490613f }, 192488, 192501 },    // Flag on tower
            { { 4555.258f, 3641.648f, 419.9740f, 1.675514f }, { 0.f, 0.f,  0.74314400f, 0.66913150f }, 192488, 192501 },    // Flag on tower
            { { 4574.872f, 3625.911f, 420.0792f, 0.087266f }, { 0.f, 0.f,  0.04361916f, 0.99904820f }, 192488, 192501 },    // Flag on tower
            { { 4433.899f, 3534.142f, 360.2750f, 4.433136f }, { 0.f, 0.f, -0.79863550f, 0.60181500f }, 192269, 192278 },    // Flag near workshop
            { { 4572.933f, 3475.519f, 363.0090f, 1.422443f }, { 0.f, 0.f,  0.65275960f, 0.75756520f }, 192269, 192277 }     // Flag near bridge
        },
        {
            { { 4418.688477f, 3506.251709f, 358.975494f,  4.293305f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A }      // Roaming Guard
        }
    },
    // South Tower
    {
        190357,
        {
            { { 4416.004f, 2822.666f, 429.8512f, 6.2657330f }, { 0.f, 0.f, -0.00872612f, 0.99996190f }, 192488, 192501 },    // Flag on tower
            { { 4398.819f, 2804.698f, 429.7920f, 4.6949370f }, { 0.f, 0.f, -0.71325020f, 0.70090960f }, 192488, 192501 },    // Flag on tower
            { { 4387.622f, 2719.566f, 389.9351f, 4.7385700f }, { 0.f, 0.f, -0.69779010f, 0.71630230f }, 192366, 192414 },    // Flag near tower
            { { 4464.124f, 2855.453f, 406.1106f, 0.8290324f }, { 0.f, 0.f,  0.40274720f, 0.91531130f }, 192366, 192429 },    // Flag near tower
            { { 4526.457f, 2810.181f, 391.1997f, 3.2899610f }, { 0.f, 0.f, -0.99724960f, 0.07411628f }, 192269, 192278 }     // Flag near bridge
        },
        {
            { { 4452.859863f, 2808.870117f, 402.604004f, 6.056290f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4455.899902f, 2835.958008f, 401.122559f, 0.034907f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4412.649414f, 2953.792236f, 374.799957f, 0.980838f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Roaming Guard
            { { 4362.089844f, 2811.510010f, 407.337006f, 3.193950f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4412.290039f, 2753.790039f, 401.015015f, 5.829400f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4421.939941f, 2773.189941f, 400.894989f, 5.707230f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A }      // Standing Guard
        }
    },
    // East Tower
    {
        190358,
        {
            { { 4466.793f, 1960.418f, 459.1437f, 1.151916f }, { 0.f, 0.f,  0.5446386f, 0.8386708f }, 192488, 192501 },     // Flag on tower
            { { 4475.351f, 1937.031f, 459.0702f, 5.846854f }, { 0.f, 0.f, -0.2164392f, 0.9762961f }, 192488, 192501 },     // Flag on tower
            { { 4451.758f, 1928.104f, 459.0759f, 4.276057f }, { 0.f, 0.f, -0.8433914f, 0.5372996f }, 192488, 192501 },     // Flag on tower
            { { 4442.987f, 1951.898f, 459.0930f, 2.740162f }, { 0.f, 0.f,  0.9799242f, 0.1993704f }, 192488, 192501 }      // Flag on tower
        },
        {
            { { 4501.060059f, 1990.280029f, 431.157013f, 1.029740f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4463.830078f, 2015.180054f, 430.299988f, 1.431170f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4494.580078f, 1943.760010f, 435.627014f, 6.195920f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4450.149902f, 1897.579956f, 435.045013f, 4.398230f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A },     // Standing Guard
            { { 4428.870117f, 1906.869995f, 432.648010f, 3.996800f }, BATTLEFIELD_WG_NPC_GUARD_H, BATTLEFIELD_WG_NPC_GUARD_A }      // Standing Guard
        }
    }
};

struct WintergraspTowerCannonData
{
    uint32 towerEntry;
    std::vector<Position> TowerCannonBottom;
    std::vector<Position> TurretTop;
};

uint8 const WG_MAX_TOWER_CANNON = 7;

WintergraspTowerCannonData const TowerCannon[WG_MAX_TOWER_CANNON] =
{
    {
        190221,
        {
            // no cannons at bottom
        },
        {
            { 5255.88f, 3047.63f, 438.499f, 3.13677f },
            { 5280.90f, 3071.32f, 438.499f, 1.62879f }
        }
    },
    {
        190373,
        {
            // no cannons at bottom
        },
        {
            { 5138.59f, 2935.16f, 439.845f, 3.11723f },
            { 5163.06f, 2959.52f, 439.846f, 1.47258f }
        }
    },
    {
        190377,
        {
            // no cannons at bottom
        },
        {
            { 5163.84f, 2723.74f, 439.844f, 1.39940f },
            { 5139.69f, 2747.40f, 439.844f, 3.17221f }
        }
    },
    {
        190378,
        {
            // no cannons at bottom
        },
        {
            { 5278.21f, 2607.23f, 439.755f, 4.71944f },
            { 5255.01f, 2631.98f, 439.755f, 3.15257f }
        }
    },
    {
        190356,
        {
            { 4537.380371f, 3599.531738f, 402.886993f, 3.998462f },
            { 4581.497559f, 3604.087158f, 402.886963f, 5.651723f }
        },
        {
            { 4469.448242f, 1966.623779f, 465.647217f, 1.153573f },
            { 4581.895996f, 3626.438477f, 426.539062f, 0.117806f }
        }
    },
    {
        190357,
        {
            { 4421.640137f, 2799.935791f, 412.630920f, 5.459298f },
            { 4420.263184f, 2845.340332f, 412.630951f, 0.742197f }
        },
        {
            { 4423.430664f, 2822.762939f, 436.283142f, 6.223487f },
            { 4397.825684f, 2847.629639f, 436.283325f, 1.579430f },
            { 4398.814941f, 2797.266357f, 436.283051f, 4.703747f }
        }
    },
    {
        190358,
        {
            { 4448.138184f, 1974.998779f, 441.995911f, 1.967238f },
            { 4448.713379f, 1955.148682f, 441.995178f, 0.380733f }
        },
        {
            { 4469.448242f, 1966.623779f, 465.647217f, 1.153573f },
            { 4481.996582f, 1933.658325f, 465.647186f, 5.873029f }
        }
    }
};

// *********************************************************
// *****************WorkShop Data & Element*****************
// *********************************************************

struct StaticWintergraspWorkshopInfo
{
    uint8 WorkshopId;
    uint32 WorldStateId;

    struct
    {
        uint8 AllianceCapture;
        uint8 AllianceAttack;
        uint8 HordeCapture;
        uint8 HordeAttack;
    } TextIds;
};

StaticWintergraspWorkshopInfo const WorkshopData[WG_MAX_WORKSHOP] =
{
    { BATTLEFIELD_WG_WORKSHOP_NE, WORLDSTATE_WORKSHOP_NE, { BATTLEFIELD_WG_TEXT_SUNKEN_RING_CAPTURE_ALLIANCE,   BATTLEFIELD_WG_TEXT_SUNKEN_RING_ATTACK_ALLIANCE,   BATTLEFIELD_WG_TEXT_SUNKEN_RING_CAPTURE_HORDE,   BATTLEFIELD_WG_TEXT_SUNKEN_RING_ATTACK_HORDE   } },
    { BATTLEFIELD_WG_WORKSHOP_NW, WORLDSTATE_WORKSHOP_NW, { BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_CAPTURE_ALLIANCE, BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_ATTACK_ALLIANCE, BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_CAPTURE_HORDE, BATTLEFIELD_WG_TEXT_BROKEN_TEMPLE_ATTACK_HORDE } },
    { BATTLEFIELD_WG_WORKSHOP_SE, WORLDSTATE_WORKSHOP_SE, { BATTLEFIELD_WG_TEXT_EASTSPARK_CAPTURE_ALLIANCE,     BATTLEFIELD_WG_TEXT_EASTSPARK_ATTACK_ALLIANCE,     BATTLEFIELD_WG_TEXT_EASTSPARK_CAPTURE_HORDE,     BATTLEFIELD_WG_TEXT_EASTSPARK_ATTACK_HORDE     } },
    { BATTLEFIELD_WG_WORKSHOP_SW, WORLDSTATE_WORKSHOP_SW, { BATTLEFIELD_WG_TEXT_WESTSPARK_CAPTURE_ALLIANCE,     BATTLEFIELD_WG_TEXT_WESTSPARK_ATTACK_ALLIANCE,     BATTLEFIELD_WG_TEXT_WESTSPARK_CAPTURE_HORDE,     BATTLEFIELD_WG_TEXT_WESTSPARK_ATTACK_HORDE     } },
    // KEEP WORKSHOPS - It can't be taken, so it doesn't have a textids
    { BATTLEFIELD_WG_WORKSHOP_KEEP_WEST, WORLDSTATE_WORKSHOP_K_W, { 0, 0, 0, 0 } },
    { BATTLEFIELD_WG_WORKSHOP_KEEP_EAST, WORLDSTATE_WORKSHOP_K_E, { 0, 0, 0, 0 } }
};

BattlefieldWG::~BattlefieldWG()
{
    for (WintergraspWorkshop* workshop : Workshops)
        delete workshop;

    for (BfWGGameObjectBuilding* building : BuildingsInZone)
        delete building;
}

bool BattlefieldWG::SetupBattlefield()
{
    m_TypeId = BATTLEFIELD_WG;                              // See enum BattlefieldTypes
    m_BattleId = BATTLEFIELD_BATTLEID_WG;
    m_ZoneId = BATTLEFIELD_WG_ZONEID;
    m_MapId = BATTLEFIELD_WG_MAPID;
    m_Map = sMapMgr->FindMap(m_MapId, 0);

    InitStalker(BATTLEFIELD_WG_NPC_STALKER, WintergraspStalkerPos);

    m_MaxPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MAX);
    m_IsEnabled = sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE);
    m_MinPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN);
    m_MinLevel = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL);
    m_BattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_BATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_NoWarBattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_NOBATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_RestartAfterCrash = sWorld->getIntConfig(CONFIG_WINTERGRASP_RESTART_AFTER_CRASH) * MINUTE * IN_MILLISECONDS;

    m_TimeForAcceptInvite = 20;
    m_StartGroupingTimer = 15 * MINUTE * IN_MILLISECONDS;
    m_StartGrouping = false;

    m_tenacityTeam = TEAM_NEUTRAL;
    m_tenacityStack = 0;

    KickPosition.Relocate(5728.117f, 2714.346f, 697.733f, 0);
    KickPosition.m_mapId = m_MapId;

    RegisterZone(m_ZoneId);

    m_Data32.resize(BATTLEFIELD_WG_DATA_MAX);

    m_saveTimer = 60000;

    // Init GraveYards
    SetGraveyardNumber(BATTLEFIELD_WG_GRAVEYARD_MAX);

    // Load from db
    if ((sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE) == 0) && (sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER) == 0)
            && (sWorld->getWorldState(ClockWorldState[0]) == 0))
    {
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, 0);
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER, urand(0, 1));
        sWorld->setWorldState(ClockWorldState[0], uint64(m_NoWarBattleTime));
    }

    m_isActive = sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE) != 0;
    m_DefenderTeam = TeamId(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER));

    m_Timer = sWorld->getWorldState(ClockWorldState[0]);
    if (m_isActive)
    {
        m_isActive = false;
        m_Timer = m_RestartAfterCrash;
    }

    SetData(BATTLEFIELD_WG_DATA_WON_A, uint32(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ATTACKED_A)));
    SetData(BATTLEFIELD_WG_DATA_DEF_A, uint32(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDED_A)));
    SetData(BATTLEFIELD_WG_DATA_WON_H, uint32(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ATTACKED_H)));
    SetData(BATTLEFIELD_WG_DATA_DEF_H, uint32(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDED_H)));

    for (uint8 i = 0; i < BATTLEFIELD_WG_GRAVEYARD_MAX; i++)
    {
        BfGraveyardWG* graveyard = new BfGraveyardWG(this);

        // When between games, the graveyard is controlled by the defending team
        if (WGGraveYard[i].StartControl == TEAM_NEUTRAL)
            graveyard->Initialize(m_DefenderTeam, WGGraveYard[i].GraveyardID);
        else
            graveyard->Initialize(WGGraveYard[i].StartControl, WGGraveYard[i].GraveyardID);

        graveyard->SetTextId(WGGraveYard[i].TextID);
        m_GraveyardList[i] = graveyard;
    }


    Workshops.resize(WG_MAX_WORKSHOP);
    // Spawn workshop creatures and gameobjects
    for (uint8 i = 0; i < WG_MAX_WORKSHOP; i++)
    {
        WintergraspWorkshop* workshop = new WintergraspWorkshop(this, i);
        if (i < BATTLEFIELD_WG_WORKSHOP_NE)
            workshop->GiveControlTo(GetAttackerTeam(), true);
        else
            workshop->GiveControlTo(GetDefenderTeam(), true);

        // Note: Capture point is added once the gameobject is created.
        Workshops[i] = workshop;
    }

    // Spawn turrets and hide them per default
    for (uint8 i = 0; i < WG_MAX_TURRET; i++)
    {
        Position towerCannonPos = WGTurret[i].GetPosition();
        if (Creature* creature = SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, towerCannonPos))
        {
            CanonList.push_back(creature->GetGUID());
            HideNpc(creature);
        }
    }

    BuildingsInZone.resize(WG_MAX_OBJ);
    // Spawn all gameobjects
    for (uint8 i = 0; i < WG_MAX_OBJ; i++)
    {
        if (GameObject* go = SpawnGameObject(WGGameObjectBuilding[i].entry, WGGameObjectBuilding[i].pos, WGGameObjectBuilding[i].rot))
        {
            BfWGGameObjectBuilding* b = new BfWGGameObjectBuilding(this, WGGameObjectBuilding[i].type, WGGameObjectBuilding[i].WorldState);
            b->Init(go);
            if (!IsEnabled() && go->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
                go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

            BuildingsInZone[i] = b;
        }
    }

    // Spawning portal defender
    for (uint8 i = 0; i < WG_MAX_TELEPORTER; ++i)
    {
        WintergraspGameObjectData const& teleporter = WGPortalDefenderData[i];
        if (GameObject* go = SpawnGameObject(teleporter.AllianceEntry, teleporter.Pos, teleporter.Rot))
        {
            DefenderPortalList[TEAM_ALLIANCE].push_back(go->GetGUID());
            go->SetRespawnTime(GetDefenderTeam() == TEAM_ALLIANCE ? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        }

        if (GameObject* go = SpawnGameObject(teleporter.HordeEntry, teleporter.Pos, teleporter.Rot))
        {
            DefenderPortalList[TEAM_HORDE].push_back(go->GetGUID());
            go->SetRespawnTime(GetDefenderTeam() == TEAM_HORDE ? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        }
    }

    UpdateCounterVehicle(true);
    return true;
}

bool BattlefieldWG::Update(uint32 diff)
{
    bool m_return = Battlefield::Update(diff);
    if (m_saveTimer <= diff)
    {
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, m_isActive);
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER, m_DefenderTeam);
        sWorld->setWorldState(ClockWorldState[0], m_Timer);
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ATTACKED_A, GetData(BATTLEFIELD_WG_DATA_WON_A));
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDED_A, GetData(BATTLEFIELD_WG_DATA_DEF_A));
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ATTACKED_H, GetData(BATTLEFIELD_WG_DATA_WON_H));
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDED_H, GetData(BATTLEFIELD_WG_DATA_DEF_H));
        m_saveTimer = 60 * IN_MILLISECONDS;
    }
    else
        m_saveTimer -= diff;

    return m_return;
}

void BattlefieldWG::OnBattleStart()
{
    // Spawn titan relic
    if (GameObject* relic = SpawnGameObject(GO_WINTERGRASP_TITAN_S_RELIC, WintergraspRelicPos, WintergraspRelicRot))
    {
        // Update faction of relic, only attacker can click on
        relic->SetFaction(WintergraspFaction[GetAttackerTeam()]);
        // Set in use (not allow to click on before last door is broken)
        relic->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
        m_titansRelicGUID = relic->GetGUID();
    }
    else
        TC_LOG_ERROR("bg.battlefield", "WG: Failed to spawn titan relic.");


    // Update tower visibility and update faction
    for (auto itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Creature* creature = GetCreature(*itr))
        {
            ShowNpc(creature, true);
            creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
        }
    }

    // Rebuild all wall
    for (BfWGGameObjectBuilding* building : BuildingsInZone)
    {
        building->Rebuild();
        building->UpdateTurretAttack(false);
    }

    SetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT, 0);
    SetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF, 0);
    SetData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, 0);
    SetData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, 0);

    // Update graveyard (in no war time all graveyard is to deffender, in war time, depend of base)
    for (WintergraspWorkshop* workshop : Workshops)
        workshop->UpdateGraveyardAndWorkshop();

    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
    {
        for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            // Kick player in orb room, TODO: offline player ?
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                float x, y, z;
                player->GetPosition(x, y, z);
                if (5500 > x && x > 5392 && y < 2880 && y > 2800 && z < 480)
                    player->TeleportTo(571, 5349.8686f, 2838.481f, 409.240f, 0.046328f);
                SendInitWorldStatesTo(player);
            }
        }
    }

    // Initialize vehicle counter
    UpdateCounterVehicle(true);
    // Send start warning to all players
    SendWarning(BATTLEFIELD_WG_TEXT_START_BATTLE);
}

void BattlefieldWG::UpdateCounterVehicle(bool init)
{
    if (init)
    {
        SetData(BATTLEFIELD_WG_DATA_VEHICLE_H, 0);
        SetData(BATTLEFIELD_WG_DATA_VEHICLE_A, 0);
    }
    SetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H, 0);
    SetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A, 0);

    for (WintergraspWorkshop* workshop : Workshops)
    {
        if (workshop->GetTeamControl() == TEAM_ALLIANCE)
            UpdateData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A, 4);
        else if (workshop->GetTeamControl() == TEAM_HORDE)
            UpdateData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H, 4);
    }

    UpdateVehicleCountWG();
}

void BattlefieldWG::OnBattleEnd(bool endByTimer)
{
    // Remove relic
    if (!m_titansRelicGUID.IsEmpty())
        if (GameObject* relic = GetGameObject(m_titansRelicGUID))
            relic->RemoveFromWorld();
    m_titansRelicGUID.Clear();

    // successful defense
    if (endByTimer)
        UpdateData(GetDefenderTeam() == TEAM_HORDE ? BATTLEFIELD_WG_DATA_DEF_H : BATTLEFIELD_WG_DATA_DEF_A, 1);
    // successful attack (note that teams have already been swapped, so defender team is the one who won)
    else
        UpdateData(GetDefenderTeam() == TEAM_HORDE ? BATTLEFIELD_WG_DATA_WON_H : BATTLEFIELD_WG_DATA_WON_A, 1);

    // Remove turret
    for (auto itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Creature* creature = GetCreature(*itr))
        {
            if (!endByTimer)
                creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
            HideNpc(creature);
        }
    }

    // Update all graveyard, control is to defender when no wartime
    for (uint8 i = 0; i < BATTLEFIELD_WG_GY_HORDE; i++)
        if (BfGraveyard* graveyard = GetGraveyardById(i))
            graveyard->GiveControlTo(GetDefenderTeam());

    // Update portals
    for (auto itr = DefenderPortalList[GetDefenderTeam()].begin(); itr != DefenderPortalList[GetDefenderTeam()].end(); ++itr)
        if (GameObject* portal = GetGameObject(*itr))
            portal->SetRespawnTime(RESPAWN_IMMEDIATELY);

    for (auto itr = DefenderPortalList[GetAttackerTeam()].begin(); itr != DefenderPortalList[GetAttackerTeam()].end(); ++itr)
        if (GameObject* portal = GetGameObject(*itr))
            portal->SetRespawnTime(RESPAWN_ONE_DAY);

    // Saving data
    for (BfWGGameObjectBuilding* building : BuildingsInZone)
        building->Save();

    for (WintergraspWorkshop* workshop : Workshops)
        workshop->Save();

    for (auto itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer(*itr))
        {
            player->CastSpell(player, SPELL_ESSENCE_OF_WINTERGRASP, true);
            player->CastSpell(player, SPELL_VICTORY_REWARD, true);
            // Complete victory quests
            player->AreaExploredOrEventHappens(QUEST_VICTORY_WINTERGRASP_A);
            player->AreaExploredOrEventHappens(QUEST_VICTORY_WINTERGRASP_H);
            // Send Wintergrasp victory achievement
            DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG, player);
            // Award achievement for succeeding in Wintergrasp in 10 minutes or less
            if (!endByTimer && GetTimer() <= 10000)
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG_TIMER_10, player);
        }
    }

    for (auto itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(*itr))
            player->CastSpell(player, SPELL_DEFEAT_REWARD, true);

    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
    {
        for (auto itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                RemoveAurasFromPlayer(player);

        m_PlayersInWar[team].clear();

        for (auto itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                if (creature->IsVehicle())
                    creature->DespawnOrUnsummon();

        m_vehicles[team].clear();
    }

    if (!endByTimer)
    {
        for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        {
            for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                {
                    player->RemoveAurasDueToSpell(m_DefenderTeam == TEAM_ALLIANCE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player->GetGUID());
                    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
                }
            }
        }
    }

    if (!endByTimer) // win alli/horde
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? BATTLEFIELD_WG_TEXT_FORTRESS_CAPTURE_ALLIANCE : BATTLEFIELD_WG_TEXT_FORTRESS_CAPTURE_HORDE);
    else // defend alli/horde
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? BATTLEFIELD_WG_TEXT_FORTRESS_DEFEND_ALLIANCE : BATTLEFIELD_WG_TEXT_FORTRESS_DEFEND_HORDE);
}

// *******************************************************
// ******************* Reward System *********************
// *******************************************************
void BattlefieldWG::DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 /*incrementNumber*/)
{
    AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(achievement);

    if (!achievementEntry)
        return;

    switch (achievement)
    {
        case ACHIEVEMENTS_WIN_WG_100:
        {
            // player->UpdateCriteria();
        }
        default:
        {
            if (player)
                player->CompletedAchievement(achievementEntry);
            break;
        }
    }

}

void BattlefieldWG::OnStartGrouping()
{
    SendWarning(BATTLEFIELD_WG_TEXT_START_GROUPING);
}

uint8 BattlefieldWG::GetSpiritGraveyardId(uint32 areaId) const
{
    switch (areaId)
    {
        case AREA_WINTERGRASP_FORTRESS:
            return BATTLEFIELD_WG_GY_KEEP;
        case AREA_THE_SUNKEN_RING:
            return BATTLEFIELD_WG_GY_WORKSHOP_NE;
        case AREA_THE_BROKEN_TEMPLATE:
            return BATTLEFIELD_WG_GY_WORKSHOP_NW;
        case AREA_WESTPARK_WORKSHOP:
            return BATTLEFIELD_WG_GY_WORKSHOP_SW;
        case AREA_EASTPARK_WORKSHOP:
            return BATTLEFIELD_WG_GY_WORKSHOP_SE;
        case AREA_WINTERGRASP:
            return BATTLEFIELD_WG_GY_ALLIANCE;
        case AREA_THE_CHILLED_QUAGMIRE:
            return BATTLEFIELD_WG_GY_HORDE;
        default:
            TC_LOG_ERROR("bg.battlefield", "BattlefieldWG::GetSpiritGraveyardId: Unexpected Area Id %u", areaId);
            break;
    }

    return 0;
}

void BattlefieldWG::OnCreatureCreate(Creature* creature)
{
    // Accessing to db spawned creatures
    switch (creature->GetEntry())
    {
        case NPC_DWARVEN_SPIRIT_GUIDE:
        case NPC_TAUNKA_SPIRIT_GUIDE:
        {
            TeamId teamId = (creature->GetEntry() == NPC_DWARVEN_SPIRIT_GUIDE ? TEAM_ALLIANCE : TEAM_HORDE);
            uint8 graveyardId = GetSpiritGraveyardId(creature->GetAreaId());
            if (m_GraveyardList[graveyardId])
                m_GraveyardList[graveyardId]->SetSpirit(creature, teamId);
            break;
        }
    }

    // untested code - not sure if it is valid.
    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
            case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
            case NPC_WINTERGRASP_CATAPULT:
            case NPC_WINTERGRASP_DEMOLISHER:
            {
                if (!creature->ToTempSummon() || !creature->ToTempSummon()->GetSummonerGUID() || !ObjectAccessor::FindPlayer(creature->ToTempSummon()->GetSummonerGUID()))
                {
                    creature->DespawnOrUnsummon();
                    return;
                }

                Player* creator = ObjectAccessor::FindPlayer(creature->ToTempSummon()->GetSummonerGUID());
                TeamId team = creator->GetTeamId();

                if (team == TEAM_HORDE)
                {
                    if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_H) < GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H))
                    {
                        UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, 1);
                        creature->AddAura(SPELL_HORDE_FLAG, creature);
                        m_vehicles[team].insert(creature->GetGUID());
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }
                else
                {
                    if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_A) < GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A))
                    {
                        UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, 1);
                        creature->AddAura(SPELL_ALLIANCE_FLAG, creature);
                        m_vehicles[team].insert(creature->GetGUID());
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }

                creature->CastSpell(creator, SPELL_GRAB_PASSENGER, true);
                break;
            }
        }
    }
}

void BattlefieldWG::OnCreatureRemove(Creature* /*creature*/)
{
/* possibly can be used later
    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
            case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
            case NPC_WINTERGRASP_CATAPULT:
            case NPC_WINTERGRASP_DEMOLISHER:
            {
                uint8 team;
                if (creature->getFaction() == WintergraspFaction[TEAM_ALLIANCE])
                    team = TEAM_ALLIANCE;
                else if (creature->getFaction() == WintergraspFaction[TEAM_HORDE])
                    team = TEAM_HORDE;
                else
                    return;

                m_vehicles[team].erase(creature->GetGUID());
                if (team == TEAM_HORDE)
                    UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, -1);
                else
                    UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, -1);
                UpdateVehicleCountWG();

                break;
            }
        }
    }*/
}

void BattlefieldWG::OnGameObjectCreate(GameObject* go)
{
    uint8 workshopId = 0;

    switch (go->GetEntry())
    {
        case GO_WINTERGRASP_FACTORY_BANNER_NE:
            workshopId = BATTLEFIELD_WG_WORKSHOP_NE;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_NW:
            workshopId = BATTLEFIELD_WG_WORKSHOP_NW;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SE:
            workshopId = BATTLEFIELD_WG_WORKSHOP_SE;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SW:
            workshopId = BATTLEFIELD_WG_WORKSHOP_SW;
            break;
        default:
            return;
    }

    for (WintergraspWorkshop* workshop : Workshops)
    {
        if (workshop->GetId() == workshopId)
        {
            WintergraspCapturePoint* capturePoint = new WintergraspCapturePoint(this, GetAttackerTeam());

            capturePoint->SetCapturePointData(go);
            capturePoint->LinkToWorkshop(workshop);
            AddCapturePoint(capturePoint);
            break;
        }
    }
}

// Called when player kill a unit in wg zone
void BattlefieldWG::HandleKill(Player* killer, Unit* victim)
{
    if (killer == victim)
        return;

    if (victim->GetTypeId() == TYPEID_PLAYER)
        HandlePromotion(killer, victim);

    /// @todoRecent PvP activity worldstate
}

bool BattlefieldWG::FindAndRemoveVehicleFromList(Unit* vehicle)
{
    for (uint32 team = 0; team < BG_TEAMS_COUNT; ++team)
    {
        auto itr = m_vehicles[team].find(vehicle->GetGUID());
        if (itr != m_vehicles[team].end())
        {
            m_vehicles[team].erase(itr);

            if (team == TEAM_HORDE)
                UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, -1);
            else
                UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, -1);
            return true;
        }
    }

    return false;
}

void BattlefieldWG::OnUnitDeath(Unit* unit)
{
    if (IsWarTime())
        if (unit->IsVehicle())
            if (FindAndRemoveVehicleFromList(unit))
                UpdateVehicleCountWG();
}

void BattlefieldWG::HandlePromotion(Player* playerKiller, Unit* unitKilled)
{
    uint32 teamId = playerKiller->GetTeamId();

    for (auto iter = m_PlayersInWar[teamId].begin(); iter != m_PlayersInWar[teamId].end(); ++iter)
        if (Player* player = ObjectAccessor::FindPlayer(*iter))
            if (player->GetDistance2d(unitKilled) < 40.0f)
                PromotePlayer(player);
}

// Update rank for player
void BattlefieldWG::PromotePlayer(Player* killer)
{
    if (!m_isActive)
        return;
    // Updating rank of player
    if (Aura* auraRecruit = killer->GetAura(SPELL_RECRUIT))
    {
        if (auraRecruit->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_RECRUIT);
            killer->CastSpell(killer, SPELL_CORPORAL, true);
            if (Creature* stalker = GetCreature(StalkerGuid))
                sCreatureTextMgr->SendChat(stalker, BATTLEFIELD_WG_TEXT_RANK_CORPORAL, killer, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, killer);
        }
        else
            killer->CastSpell(killer, SPELL_RECRUIT, true);
    }
    else if (Aura* auraCorporal = killer->GetAura(SPELL_CORPORAL))
    {
        if (auraCorporal->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_CORPORAL);
            killer->CastSpell(killer, SPELL_LIEUTENANT, true);
            if (Creature* stalker = GetCreature(StalkerGuid))
                sCreatureTextMgr->SendChat(stalker, BATTLEFIELD_WG_TEXT_RANK_FIRST_LIEUTENANT, killer, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, killer);
        }
        else
            killer->CastSpell(killer, SPELL_CORPORAL, true);
    }
}

void BattlefieldWG::RemoveAurasFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_RECRUIT);
    player->RemoveAurasDueToSpell(SPELL_CORPORAL);
    player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
    player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
    player->RemoveAurasDueToSpell(SPELL_TENACITY);
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
    player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
}

void BattlefieldWG::OnPlayerJoinWar(Player* player)
{
    RemoveAurasFromPlayer(player);

    player->CastSpell(player, SPELL_RECRUIT, true);

    if (player->GetZoneId() != m_ZoneId)
    {
        if (player->GetTeamId() == GetDefenderTeam())
            player->TeleportTo(571, 5345, 2842, 410, 3.14f);
        else
        {
            if (player->GetTeamId() == TEAM_HORDE)
                player->TeleportTo(571, 5025.857422f, 3674.628906f, 362.737122f, 4.135169f);
            else
                player->TeleportTo(571, 5101.284f, 2186.564f, 373.549f, 3.812f);
        }
    }

    UpdateTenacity();

    if (player->GetTeamId() == GetAttackerTeam())
    {
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) < 3)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, 3 - GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT));
    }
    else
    {
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) > 0)
           player->SetAuraStack(SPELL_TOWER_CONTROL, player, GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT));
    }
    SendInitWorldStatesTo(player);
}

void BattlefieldWG::OnPlayerLeaveWar(Player* player)
{
    // Remove all aura from WG /// @todo false we can go out of this zone on retail and keep Rank buff, remove on end of WG
    if (!player->GetSession()->PlayerLogout())
    {
        if (Creature* vehicle = player->GetVehicleCreatureBase())   // Remove vehicle of player if he go out.
            vehicle->DespawnOrUnsummon();

        RemoveAurasFromPlayer(player);
    }

    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
    UpdateTenacity();
}

void BattlefieldWG::OnPlayerLeaveZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);

    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWG::OnPlayerEnterZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);

    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
    // Send worldstate to player
    SendInitWorldStatesTo(player);
}

uint32 BattlefieldWG::GetData(uint32 data) const
{
    switch (data)
    {
        // Used to determine when the phasing spells must be cast
        // See: SpellArea::IsFitToRequirements
        case AREA_THE_SUNKEN_RING:
        case AREA_THE_BROKEN_TEMPLATE:
        case AREA_WESTPARK_WORKSHOP:
        case AREA_EASTPARK_WORKSHOP:
            // Graveyards and Workshops are controlled by the same team.
            if (BfGraveyard const* graveyard = GetGraveyardById(GetSpiritGraveyardId(data)))
                return graveyard->GetControlTeamId();
            break;
        default:
            break;
    }

    return Battlefield::GetData(data);
}


void BattlefieldWG::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_ATTACKER), int32(GetAttackerTeam()));
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_DEFENDER), int32(GetDefenderTeam()));
    // Note: cleanup these two, their names look awkward
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_ACTIVE), int32(IsWarTime() ? 0 : 1));
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_SHOW_WORLDSTATE), int32(IsWarTime() ? 1 : 0));

    for (uint32 i = 0; i < 2; ++i)
        packet.Worldstates.emplace_back(ClockWorldState[i], int32(time(nullptr) + (m_Timer / 1000)));

    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_H), int32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_H)));
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_H), int32(GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H)));
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_A), int32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_A)));
    packet.Worldstates.emplace_back(uint32(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_A), int32(GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A)));

    for (BfWGGameObjectBuilding* building : BuildingsInZone)
        building->FillInitialWorldStates(packet);

    for (WintergraspWorkshop* workshop : Workshops)
        workshop->FillInitialWorldStates(packet);
}

void BattlefieldWG::SendInitWorldStatesTo(Player* player)
{
    WorldPackets::WorldState::InitWorldStates packet;
    packet.AreaID = m_ZoneId;
    packet.MapID = m_MapId;
    packet.SubareaID = 0;

    FillInitialWorldStates(packet);

    player->SendDirectMessage(packet.Write());
}

void BattlefieldWG::SendInitWorldStatesToAll()
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (auto itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                SendInitWorldStatesTo(player);
}

void BattlefieldWG::BrokenWallOrTower(TeamId team, BfWGGameObjectBuilding* building)
{
    if (team == GetDefenderTeam())
    {
        for (auto itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                if (player->GetDistance2d(GetGameObject(building->GetGUID())) < 50.0f)
                    player->KilledMonsterCredit(QUEST_CREDIT_DEFEND_SIEGE);
        }
    }
}

// Called when a tower is broke
void BattlefieldWG::UpdatedDestroyedTowerCount(TeamId team)
{
    // Southern tower
    if (team == GetAttackerTeam())
    {
        // Update counter
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, -1);
        UpdateData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT, 1);

        // Remove buff stack on attackers
        for (auto itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->RemoveAuraFromStack(SPELL_TOWER_CONTROL);

        // Add buff stack to defenders and give achievement/quest credit
        for (auto itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                player->CastSpell(player, SPELL_TOWER_CONTROL, true);
                player->KilledMonsterCredit(QUEST_CREDIT_TOWERS_DESTROYED);
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WG_TOWER_DESTROY, player);
            }
        }

        // If all three south towers are destroyed (ie. all attack towers), remove ten minutes from battle time
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) == 3)
        {
            if (int32(m_Timer - 600000) < 0)
                m_Timer = 0;
            else
                m_Timer -= 600000;
            SendInitWorldStatesToAll();
        }
    }
    else // Keep tower
    {
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, -1);
        UpdateData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF, 1);
    }
}

void BattlefieldWG::ProcessEvent(WorldObject* obj, uint32 eventId)
{
    if (!obj || !IsWarTime())
        return;

    // We handle only gameobjects here
    GameObject* go = obj->ToGameObject();
    if (!go)
        return;

    // On click on titan relic
    if (go->GetEntry() == GO_WINTERGRASP_TITAN_S_RELIC)
    {
        if (CanInteractWithRelic())
            EndBattle(false);
        else if (GameObject* relic = GetRelic())
            relic->SetRespawnTime(RESPAWN_IMMEDIATELY);
    }

    // if destroy or damage event, search the wall/tower and update worldstate/send warning message
    for (BfWGGameObjectBuilding* building : BuildingsInZone)
    {
        if (go->GetGUID() == building->GetGUID())
        {
            if (GameObject* buildingGo = GetGameObject(building->GetGUID()))
            {
                if (buildingGo->GetGOInfo()->destructibleBuilding.DamagedEvent == eventId)
                    building->Damaged();
                else if (buildingGo->GetGOInfo()->destructibleBuilding.DestroyedEvent == eventId)
                    building->Destroyed();
                break;
            }
        }
    }
}

// Called when a tower is damaged, used for honor reward calcul
void BattlefieldWG::UpdateDamagedTowerCount(TeamId team)
{
    if (team == GetAttackerTeam())
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, 1);
    else
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, 1);
}

// Update vehicle count WorldState to player
void BattlefieldWG::UpdateVehicleCountWG()
{
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_H,     GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_H, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_A,     GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_A, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A));
}

void BattlefieldWG::UpdateTenacity()
{
    uint32 alliancePlayers = m_PlayersInWar[TEAM_ALLIANCE].size();
    uint32 hordePlayers = m_PlayersInWar[TEAM_HORDE].size();
    int32 newStack = 0;

    if (alliancePlayers && hordePlayers)
    {
        if (alliancePlayers < hordePlayers)
            newStack = int32((float(hordePlayers / alliancePlayers) - 1) * 4);  // positive, should cast on alliance
        else if (alliancePlayers > hordePlayers)
            newStack = int32((1 - float(alliancePlayers / hordePlayers)) * 4);  // negative, should cast on horde
    }

    if (newStack == int32(m_tenacityStack))
        return;

    m_tenacityStack = newStack;
    // Remove old buff
    if (m_tenacityTeam != TEAM_NEUTRAL)
    {
        for (auto itr = m_players[m_tenacityTeam].begin(); itr != m_players[m_tenacityTeam].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                if (player->getLevel() >= m_MinLevel)
                    player->RemoveAurasDueToSpell(SPELL_TENACITY);

        for (auto itr = m_vehicles[m_tenacityTeam].begin(); itr != m_vehicles[m_tenacityTeam].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                creature->RemoveAurasDueToSpell(SPELL_TENACITY_VEHICLE);
    }

    // Apply new buff
    if (newStack)
    {
        m_tenacityTeam = newStack > 0 ? TEAM_ALLIANCE : TEAM_HORDE;

        if (newStack < 0)
            newStack = -newStack;
        if (newStack > 20)
            newStack = 20;

        uint32 buff_honor = SPELL_GREATEST_HONOR;
        if (newStack < 15)
            buff_honor = SPELL_GREATER_HONOR;
        if (newStack < 10)
            buff_honor = SPELL_GREAT_HONOR;
        if (newStack < 5)
            buff_honor = 0;

        for (auto itr = m_PlayersInWar[m_tenacityTeam].begin(); itr != m_PlayersInWar[m_tenacityTeam].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->SetAuraStack(SPELL_TENACITY, player, newStack);

        for (auto itr = m_vehicles[m_tenacityTeam].begin(); itr != m_vehicles[m_tenacityTeam].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, newStack);

        if (buff_honor != 0)
        {
            for (auto itr = m_PlayersInWar[m_tenacityTeam].begin(); itr != m_PlayersInWar[m_tenacityTeam].end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                    player->CastSpell(player, buff_honor, true);

            for (auto itr = m_vehicles[m_tenacityTeam].begin(); itr != m_vehicles[m_tenacityTeam].end(); ++itr)
                if (Creature* creature = GetCreature(*itr))
                    creature->CastSpell(creature, buff_honor, true);
        }
    }
    else
        m_tenacityTeam = TEAM_NEUTRAL;
}

WintergraspCapturePoint::WintergraspCapturePoint(BattlefieldWG* battlefield, TeamId teamInControl) : BfCapturePoint(battlefield)
{
    m_Bf = battlefield;
    m_team = teamInControl;
    m_Workshop = nullptr;
}

void WintergraspCapturePoint::ChangeTeam(TeamId /*oldTeam*/)
{
    ASSERT(m_Workshop);
    m_Workshop->GiveControlTo(m_team);
}

BfGraveyardWG::BfGraveyardWG(BattlefieldWG* battlefield) : BfGraveyard(battlefield)
{
    m_Bf = battlefield;
    m_GossipTextId = 0;
}

BfWGGameObjectBuilding::BfWGGameObjectBuilding(BattlefieldWG* wg, WintergraspGameObjectBuildingType type, uint32 worldState)
{
    ASSERT(wg);

    _wg = wg;
    _teamControl = TEAM_NEUTRAL;
    _type = type;
    _worldState = worldState;
    _state = BATTLEFIELD_WG_OBJECTSTATE_NONE;
    _staticTowerInfo = nullptr;
}

void BfWGGameObjectBuilding::Rebuild()
{
    switch (_type)
    {
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
        case BATTLEFIELD_WG_OBJECTTYPE_WALL:
            _teamControl = _wg->GetDefenderTeam();      // Objects that are part of the keep should be the defender's
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
            _teamControl = _wg->GetAttackerTeam();      // The towers in the south should be the attacker's
            break;
        default:
            _teamControl = TEAM_NEUTRAL;
            break;
    }

    if (GameObject* build = _wg->GetGameObject(_buildGUID))
    {
        // Rebuild gameobject
        if (build->IsDestructibleBuilding())
        {
            build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, nullptr, true);
            if (build->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                    go->SetGoState(GO_STATE_READY);

            // Update worldstate
            _state = WintergraspGameObjectState(BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT - (_teamControl * 3));
            _wg->SendUpdateWorldState(_worldState, _state);
        }
        UpdateCreatureAndGo();
        build->SetFaction(WintergraspFaction[_teamControl]);
    }
}

void BfWGGameObjectBuilding::Damaged()
{
    // Update worldstate
    _state = WintergraspGameObjectState(BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE - (_teamControl * 3));
    _wg->SendUpdateWorldState(_worldState, _state);

    // Send warning message
    if (_staticTowerInfo)
        _wg->SendWarning(_staticTowerInfo->TextIds.Damaged);

    for (ObjectGuid guid : m_CreatureTopList[_wg->GetAttackerTeam()])
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->HideNpc(creature);

    for (ObjectGuid guid : m_TurretTopList)
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->HideNpc(creature);

    if (_type == BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER)
        _wg->UpdateDamagedTowerCount(_wg->GetDefenderTeam());
    else if (_type == BATTLEFIELD_WG_OBJECTTYPE_TOWER)
        _wg->UpdateDamagedTowerCount(_wg->GetAttackerTeam());
}

void BfWGGameObjectBuilding::Destroyed()
{
    // Update worldstate
    _state = WintergraspGameObjectState(BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY - (_teamControl * 3));
    _wg->SendUpdateWorldState(_worldState, _state);

    // Warn players
    if (_staticTowerInfo)
        _wg->SendWarning(_staticTowerInfo->TextIds.Destroyed);

    switch (_type)
    {
        // Inform the global wintergrasp script of the destruction of this object
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
            _wg->UpdatedDestroyedTowerCount(_teamControl);
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
            if (GameObject* build = _wg->GetGameObject(_buildGUID))
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                    go->SetGoState(GO_STATE_ACTIVE);
            _wg->SetRelicInteractible(true);
            if (_wg->GetRelic())
                _wg->GetRelic()->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
            else
                TC_LOG_ERROR("bg.battlefield.wg", "Titan Relic not found.");
            break;
        default:
            break;
    }

    _wg->BrokenWallOrTower(_teamControl, this);
}

void BfWGGameObjectBuilding::Init(GameObject* go)
{
    if (!go)
        return;

    // GameObject associated to object
    _buildGUID = go->GetGUID();

    switch (_type)
    {
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
        case BATTLEFIELD_WG_OBJECTTYPE_WALL:
            _teamControl = _wg->GetDefenderTeam();           // Objects that are part of the keep should be the defender's
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
            _teamControl = _wg->GetAttackerTeam();           // The towers in the south should be the attacker's
            break;
        default:
            _teamControl = TEAM_NEUTRAL;
            break;
    }

    _state = WintergraspGameObjectState(sWorld->getWorldState(_worldState));
    switch (_state)
    {
        case BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_INTACT:
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT:
            go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, nullptr, true);
            break;
        case BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_DESTROY:
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DESTROY:
            go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
            break;
        case BATTLEFIELD_WG_OBJECTSTATE_NEUTRAL_DAMAGE:
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DAMAGE:
            go->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            break;
        default:
            break;
    }

    int32 towerId = -1;
    switch (go->GetEntry())
    {
        case GO_WINTERGRASP_FORTRESS_TOWER_1:
            towerId = BATTLEFIELD_WG_TOWER_FORTRESS_NW;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_2:
            towerId = BATTLEFIELD_WG_TOWER_FORTRESS_SW;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_3:
            towerId = BATTLEFIELD_WG_TOWER_FORTRESS_SE;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_4:
            towerId = BATTLEFIELD_WG_TOWER_FORTRESS_NE;
            break;
        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
            towerId = BATTLEFIELD_WG_TOWER_SHADOWSIGHT;
            break;
        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
            towerId = BATTLEFIELD_WG_TOWER_WINTER_S_EDGE;
            break;
        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
            towerId = BATTLEFIELD_WG_TOWER_FLAMEWATCH;
            break;
    }

    if (towerId >= BATTLEFIELD_WG_TOWER_SHADOWSIGHT) // Attacker towers
    {
        // Spawn associate gameobjects
        for (WintergraspGameObjectData const& gobData : AttackTowers[towerId - 4].GameObject)
        {
            if (GameObject* goHorde = _wg->SpawnGameObject(gobData.HordeEntry, gobData.Pos, gobData.Rot))
                m_GameObjectList[TEAM_HORDE].push_back(goHorde->GetGUID());

            if (GameObject* goAlliance = _wg->SpawnGameObject(gobData.AllianceEntry, gobData.Pos, gobData.Rot))
                m_GameObjectList[TEAM_ALLIANCE].push_back(goAlliance->GetGUID());
        }

        // Spawn associate npc bottom
        for (WintergraspObjectPositionData const& creatureData : AttackTowers[towerId - 4].CreatureBottom)
        {
            if (Creature* creature = _wg->SpawnCreature(creatureData.HordeEntry, creatureData.Pos))
                m_CreatureBottomList[TEAM_HORDE].push_back(creature->GetGUID());

            if (Creature* creature = _wg->SpawnCreature(creatureData.AllianceEntry, creatureData.Pos))
                m_CreatureBottomList[TEAM_ALLIANCE].push_back(creature->GetGUID());
        }
    }

    if (towerId >= 0)
    {
        ASSERT(towerId < WG_MAX_TOWER);
        _staticTowerInfo = &TowerData[towerId];

        // Spawn Turret bottom
        for (Position const& turretPos : TowerCannon[towerId].TowerCannonBottom)
        {
            if (Creature* turret = _wg->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, turretPos))
            {
                m_TowerCannonBottomList.push_back(turret->GetGUID());
                switch (go->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        turret->setFaction(WintergraspFaction[_wg->GetDefenderTeam()]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        turret->setFaction(WintergraspFaction[_wg->GetAttackerTeam()]);
                        break;
                }

                _wg->HideNpc(turret);
            }
        }

        // Spawn Turret top
        for (Position const& towerCannonPos : TowerCannon[towerId].TurretTop)
        {
            if (Creature* turret = _wg->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, towerCannonPos))
            {
                m_TurretTopList.push_back(turret->GetGUID());
                switch (go->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        turret->setFaction(WintergraspFaction[_wg->GetDefenderTeam()]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        turret->setFaction(WintergraspFaction[_wg->GetAttackerTeam()]);
                        break;
                }
                _wg->HideNpc(turret);
            }
        }
        UpdateCreatureAndGo();
    }
}

void BfWGGameObjectBuilding::UpdateCreatureAndGo()
{
    for (ObjectGuid guid : m_CreatureTopList[_wg->GetDefenderTeam()])
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->HideNpc(creature);

    for (ObjectGuid guid : m_CreatureTopList[_wg->GetAttackerTeam()])
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->ShowNpc(creature, true);

    for (ObjectGuid guid : m_CreatureBottomList[_wg->GetDefenderTeam()])
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->HideNpc(creature);

    for (ObjectGuid guid : m_CreatureBottomList[_wg->GetAttackerTeam()])
        if (Creature* creature = _wg->GetCreature(guid))
            _wg->ShowNpc(creature, true);

    for (ObjectGuid guid : m_GameObjectList[_wg->GetDefenderTeam()])
        if (GameObject* go = _wg->GetGameObject(guid))
            go->SetRespawnTime(RESPAWN_ONE_DAY);

    for (ObjectGuid guid : m_GameObjectList[_wg->GetAttackerTeam()])
        if (GameObject* go = _wg->GetGameObject(guid))
            go->SetRespawnTime(RESPAWN_IMMEDIATELY);
}

void BfWGGameObjectBuilding::UpdateTurretAttack(bool disable)
{
    for (ObjectGuid guid : m_TowerCannonBottomList)
    {
        if (Creature* creature = _wg->GetCreature(guid))
        {
            if (disable)
                _wg->HideNpc(creature);
            else
                _wg->ShowNpc(creature, true);

            switch (_buildGUID.GetEntry())
            {
                case GO_WINTERGRASP_FORTRESS_TOWER_1:
                case GO_WINTERGRASP_FORTRESS_TOWER_2:
                case GO_WINTERGRASP_FORTRESS_TOWER_3:
                case GO_WINTERGRASP_FORTRESS_TOWER_4:
                {
                    creature->setFaction(WintergraspFaction[_wg->GetDefenderTeam()]);
                    break;
                }
                case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                {
                    creature->setFaction(WintergraspFaction[_wg->GetAttackerTeam()]);
                    break;
                }
            }
        }
    }

    for (ObjectGuid guid : m_TurretTopList)
    {
        if (Creature* creature = _wg->GetCreature(guid))
        {
            if (disable)
                _wg->HideNpc(creature);
            else
                _wg->ShowNpc(creature, true);

            switch (_buildGUID.GetEntry())
            {
                case GO_WINTERGRASP_FORTRESS_TOWER_1:
                case GO_WINTERGRASP_FORTRESS_TOWER_2:
                case GO_WINTERGRASP_FORTRESS_TOWER_3:
                case GO_WINTERGRASP_FORTRESS_TOWER_4:
                {
                    creature->setFaction(WintergraspFaction[_wg->GetDefenderTeam()]);
                    break;
                }
                case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                {
                    creature->setFaction(WintergraspFaction[_wg->GetAttackerTeam()]);
                    break;
                }
            }
        }
    }
}

void BfWGGameObjectBuilding::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(_worldState), int32(_state));
}

void BfWGGameObjectBuilding::Save()
{
    sWorld->setWorldState(_worldState, _state);
}

WintergraspWorkshop::WintergraspWorkshop(BattlefieldWG* wg, uint8 type)
{
    ASSERT(wg && type < WG_MAX_WORKSHOP);

    _wg = wg;
    _state = BATTLEFIELD_WG_OBJECTSTATE_NONE;
    _teamControl = TEAM_NEUTRAL;
    _staticInfo = &WorkshopData[type];
}

uint8 WintergraspWorkshop::GetId() const
{
    return _staticInfo->WorkshopId;
}

void WintergraspWorkshop::GiveControlTo(TeamId teamId, bool init /*= false*/)
{
    switch (teamId)
    {
        case TEAM_NEUTRAL:
        {
            // Send warning message to all player for inform a faction attack a workshop
            // alliance / horde attacking workshop
            _wg->SendWarning(_teamControl == TEAM_ALLIANCE ? _staticInfo->TextIds.HordeAttack : _staticInfo->TextIds.AllianceAttack);
            break;
        }
        case TEAM_ALLIANCE:
        {
            // Updating worldstate
            _state = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT;
            _wg->SendUpdateWorldState(_staticInfo->WorldStateId, _state);

            // Warning message
            if (!init)
                _wg->SendWarning(_staticInfo->TextIds.AllianceCapture); // workshop taken - alliance

            // Found associate graveyard and update it
            if (_staticInfo->WorkshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                if (BfGraveyard* gy = _wg->GetGraveyardById(_staticInfo->WorkshopId))
                    gy->GiveControlTo(TEAM_ALLIANCE);

            _teamControl = teamId;
            break;
        }
        case TEAM_HORDE:
        {
            // Update worldstate
            _state = BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT;
            _wg->SendUpdateWorldState(_staticInfo->WorldStateId, _state);

            // Warning message
            if (!init)
                _wg->SendWarning(_staticInfo->TextIds.HordeCapture); // workshop taken - horde

            // Update graveyard control
            if (_staticInfo->WorkshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                if (BfGraveyard* gy = _wg->GetGraveyardById(_staticInfo->WorkshopId))
                    gy->GiveControlTo(TEAM_HORDE);

            _teamControl = teamId;
            break;
        }
    }
    if (!init)
        _wg->UpdateCounterVehicle(false);
}

void WintergraspWorkshop::UpdateGraveyardAndWorkshop()
{
    if (_staticInfo->WorkshopId < BATTLEFIELD_WG_WORKSHOP_NE)
        GiveControlTo(_wg->GetAttackerTeam(), true);
    else
        GiveControlTo(_wg->GetDefenderTeam(), true);
}

void WintergraspWorkshop::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(_staticInfo->WorldStateId), int32(_state));
}

void WintergraspWorkshop::Save()
{
    sWorld->setWorldState(_staticInfo->WorldStateId, _state);
}
