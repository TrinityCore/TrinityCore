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

#ifndef BATTLEFIELD_TB_
#define BATTLEFIELD_TB_

#include "Battlefield.h"

class BattlefieldTB;
class TolBaradCapturePoint;

enum TolBaradInfo
{
    BATTLEFIELD_TB_MAPID = 732, // Tol Barad
    BATTLEFIELD_TB_ZONEID = 5095, // Tol Barad
};

enum TolBaradData
{
    BATTLEFIELD_TB_DATA_BUILDINGS_CAPTURED,
    BATTLEFIELD_TB_DATA_TOWERS_INTACT,
    BATTLEFIELD_TB_DATA_TOWERS_DESTROYED,
    BATTLEFIELD_TB_DATA_MAX,
};

enum TolBaradSpells
{
    // Quest completion
    SPELL_VICTORY_ALLIANCE = 94665,
    SPELL_VICTORY_HORDE = 94763,

    // Rewards
    SPELL_REWARD_VICTORY_ALLIANCE = 89789,
    SPELL_REWARD_VICTORY_HORDE = 89791,
    SPELL_REWARD_DEFEAT = 89793,

    SPELL_REWARD_TOWER_INTACT = 89794,
    SPELL_REWARD_TOWER_DAMAGED = 89795,
    SPELL_REWARD_TOWER_DESTROYED = 89796,

    // Player buffs
    SPELL_TB_SLOW_FALL = 88473,
    SPELL_TB_VETERAN = 84655,
    SPELL_TOWER_ATTACK_BONUS = 82629,
    SPELL_TB_SPIRIT_HEAL_CHANNEL = 22011, // this spell replaces m_LastResurrectTimer in Battlefield.cpp?
    SPELL_TB_SPIRITUAL_IMMUNITY = 95332,

    // Vehicle
    SPELL_THICK_LAYER_OF_RUST = 95330,
    SPELL_RIDE_TOL_BARAD_VEHICLE = 84754,
    SPELL_DEPLOY_SIEGE_MODE = 84974,
    SPELL_SIEGE_CANNON_AURA = 85167, // aura, periodically triggers spell 85122
//  SPELL_SIEGE_CANNON_EFFECT = 85122, // targets random
//  SPELL_SIEGE_CANNON_DAMAGE = 85125,
    SPELL_LEAVE_SIEGE_MODE = 85078,

    SPELL_TOWER_RANGE_FINDER_PERIODIC = 85671,
    SPELL_TOWER_RANGE_FINDER = 84979,

    // Teleportation spells
    SPELL_TB_THE_HOLE_TELEPORT = 89035,
    SPELL_TB_D_BLOCK_TELEPORT = 89037,
    SPELL_TB_CURSED_DEPTHS_TELEPORT = 89038,
};

enum TolBaradNpcs
{
    // Cursed Depths area
    NPC_TOLBARAD_CAPTIVE_SPIRIT                     = 47531,
    NPC_TOLBARAD_CELLBLOCK_OOZE                     = 47534,
    NPC_TOLBARAD_ARCHMAGE_GALUS                     = 47537,
    NPC_TOLBARAD_GHASTLY_CONVICT                    = 47590,

    // D-Block area
    NPC_TOLBARAD_SHIVARRA_DESTROYER                 = 47540,
    NPC_TOLBARAD_CELL_WATCHER                       = 47542,
    NPC_TOLBARAD_SVARNOS                            = 47544,
    NPC_TOLBARAD_JAILED_WRATHGUARD                  = 47548,
    NPC_TOLBARAD_IMPRISONED_IMP                     = 47549,

    // The Hole area
    NPC_TOLBARAD_WARDEN_SILVA                       = 48036,
    NPC_TOLBARAD_WARDEN_GUARD                       = 47561,
    NPC_TOLBARAD_IMPRISONED_WORKER                  = 47550,
    NPC_TOLBARAD_EXILED_MAGE                        = 47552,

    // Other
    NPC_CROCOLISK                                   = 47591,
    NPC_PROBLIM                                     = 47593,

    // Graveyard spirits
    NPC_TB_GY_SPIRIT_BARADIN_HOLD_A                 = 45066,
    NPC_TB_GY_SPIRIT_BARADIN_HOLD_H                 = 45067,
    NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_A            = 45068,
    NPC_TB_GY_SPIRIT_WARDENS_VIGIL_A                = 45069,
    NPC_TB_GY_SPIRIT_EAST_SPIRE_A                   = 45070,
    NPC_TB_GY_SPIRIT_SOUTH_SPIRE_A                  = 45071,
    NPC_TB_GY_SPIRIT_WEST_SPIRE_A                   = 45072,
    NPC_TB_GY_SPIRIT_SLAGWORKS_A                    = 45073,
    NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_H            = 45074,
    NPC_TB_GY_SPIRIT_WARDENS_VIGIL_H                = 45075,
    NPC_TB_GY_SPIRIT_SLAGWORKS_H                    = 45076,
    NPC_TB_GY_SPIRIT_WEST_SPIRE_H                   = 45077,
    NPC_TB_GY_SPIRIT_EAST_SPIRE_H                   = 45078,
    NPC_TB_GY_SPIRIT_SOUTH_SPIRE_H                  = 45079,

    // Stalker, dummies
    NPC_DEBUG_ANNOUNCER = 43679,
    NPC_TOWER_RANGE_FINDER = 45492,
    NPC_TOWER_CANNON_TARGET = 45561,
    NPC_SIEGE_ENGINE_TURRET = 45564,
};

enum TolBaradGOs
{
    // Towers
    GO_WEST_SPIRE = 204588,
    GO_EAST_SPIRE = 204589,
    GO_SOUTH_SPIRE = 204590,

    GO_CAPTURE_POINT_NORTH_A_DEFENDING          = 205068,
    GO_CAPTURE_POINT_NORTH_H_DEFENDING          = 205096,
    GO_CAPTURE_POINT_EAST_A_DEFENDING           = 205138,
    GO_CAPTURE_POINT_EAST_H_DEFENDING           = 205139,
    GO_CAPTURE_POINT_WEST_A_DEFENDING           = 205101,
    GO_CAPTURE_POINT_WEST_H_DEFENDING           = 205103,

    // Entrance gates and instance door
    GO_TOLBARAD_GATES = 206598,
    GO_TOLBARAD_DOOR = 206576,

    // Other
    GO_TB_MEETING_STONE = 206668,

    GO_TB_INSTANCE_VISUAL_1 = 207746,
    GO_TB_INSTANCE_VISUAL_2 = 207747,
    GO_TB_INSTANCE_VISUAL_3 = 210114,
    GO_TB_INSTANCE_VISUAL_4 = 210115,
};

enum TolBaradGOArtKit
{
    TB_GO_ARTKIT_FLAG_NONE = 0,
    TB_GO_ARTKIT_FLAG_HORDE = 1,
    TB_GO_ARTKIT_FLAG_ALLIANCE = 2,
};

enum TolBaradWorldStates
{
    TB_WS_ALLIANCE_CONTROLS_SHOW = 5385,
    TB_WS_HORDE_CONTROLS_SHOW = 5384,
    TB_WS_ALLIANCE_ATTACKING_SHOW = 5546,
    TB_WS_HORDE_ATTACKING_SHOW = 5547,

    TB_WS_BUILDINGS_CAPTURED = 5348,
    TB_WS_BUILDINGS_CAPTURED_SHOW = 5349,
    TB_WS_TOWERS_DESTROYED = 5347,
    TB_WS_TOWERS_DESTROYED_SHOW = 5350,

    TB_WS_FACTION_CONTROLLING = 5334, // 1 -> Alliance, 2 -> Horde

    TB_WS_TIME_NEXT_BATTLE = 5332,
    TB_WS_TIME_NEXT_BATTLE_SHOW = 5387,
    TB_WS_TIME_BATTLE_END = 5333,
    TB_WS_TIME_BATTLE_END_SHOW = 5346,

    TB_WS_STATE_PREPARATIONS = 5684,
    TB_WS_STATE_BATTLE = 5344,

    /* Not Sure if TB
    TB_WS_0_UNKNOWN = 5587,
    TB_WS_9_UNKNOWN = 5508,
    TB_WS_35_UNKNOWN = 5679,
    TB_WS_36_UNKNOWN = 5678,
    TB_WS_37_UNKNOWN = 5677,
    TB_WS_60_UNKNOWN = 5361,
    TB_WS_61_UNKNOWN = 5360,
    TB_WS_65_UNKNOWN = 5195,
    TB_WS_66_UNKNOWN = 5193,
    */

    TB_WS_PROGRESS_SHOW = 5376,
    TB_WS_PROGRESS = 5377, // 0 horde, 100 alliance
    TB_WS_PROGRESS_PERCENT_GREY = 5378,

    TB_WS_KEEP_HORDE = 5469,
    TB_WS_KEEP_ALLIANCE = 5470,

    TB_WS_GARRISON_HORDE_CONTROLLED = 5418,
    TB_WS_GARRISON_HORDE_CAPTURING = 5419,
    TB_WS_GARRISON_NEUTRAL = 5420, // unused
    TB_WS_GARRISON_ALLIANCE_CAPTURING = 5421,
    TB_WS_GARRISON_ALLIANCE_CONTROLLED = 5422,

    TB_WS_VIGIL_HORDE_CONTROLLED = 5423,
    TB_WS_VIGIL_HORDE_CAPTURING = 5424,
    TB_WS_VIGIL_NEUTRAL = 5425, // unused
    TB_WS_VIGIL_ALLIANCE_CAPTURING = 5426,
    TB_WS_VIGIL_ALLIANCE_CONTROLLED = 5427,

    TB_WS_SLAGWORKS_HORDE_CONTROLLED = 5428,
    TB_WS_SLAGWORKS_HORDE_CAPTURING = 5429,
    TB_WS_SLAGWORKS_NEUTRAL = 5430, // unused
    TB_WS_SLAGWORKS_ALLIANCE_CAPTURING = 5431,
    TB_WS_SLAGWORKS_ALLIANCE_CONTROLLED = 5432,

    TB_WS_WEST_INTACT_HORDE = 5433,
    TB_WS_WEST_DAMAGED_HORDE = 5434,
    TB_WS_WEST_DESTROYED_NEUTRAL = 5435,
    TB_WS_WEST_INTACT_ALLIANCE = 5436,
    TB_WS_WEST_DAMAGED_ALLIANCE = 5437,
    TB_WS_WEST_INTACT_NEUTRAL = 5453, // unused
    TB_WS_WEST_DAMAGED_NEUTRAL = 5454, // unused

    TB_WS_SOUTH_INTACT_HORDE = 5438,
    TB_WS_SOUTH_DAMAGED_HORDE = 5439,
    TB_WS_SOUTH_DESTROYED_NEUTRAL = 5440,
    TB_WS_SOUTH_INTACT_ALLIANCE = 5441,
    TB_WS_SOUTH_DAMAGED_ALLIANCE = 5442,
    TB_WS_SOUTH_INTACT_NEUTRAL = 5455, // unused
    TB_WS_SOUTH_DAMAGED_NEUTRAL = 5456, // unused

    TB_WS_EAST_INTACT_HORDE = 5443,
    TB_WS_EAST_DAMAGED_HORDE = 5444,
    TB_WS_EAST_DESTROYED_NEUTRAL = 5445,
    TB_WS_EAST_INTACT_ALLIANCE = 5446,
    TB_WS_EAST_DAMAGED_ALLIANCE = 5447,
    TB_WS_EAST_INTACT_NEUTRAL = 5451,
    TB_WS_EAST_DAMAGED_NEUTRAL = 5452,
};

enum TolBaradText
{
    // DEBUG Announcer
    TB_TEXT_EAST_SPIRE_DAMAGED              = 1,
    TB_TEXT_EAST_SPIRE_DESTROYED            = 2,
    TB_TEXT_WEST_SPIRE_DAMAGED              = 3,
    TB_TEXT_WEST_SPIRE_DESTROYED            = 4,
    TB_TEXT_SOUTH_SPIRE_DAMAGED             = 5,
    TB_TEXT_SOUTH_SPIRE_DESTROYED           = 6,
    TB_TEXT_GARRISON_ALLIANCE_GAINED        = 7,
    TB_TEXT_GARRISON_ALLIANCE_LOST          = 8,
    TB_TEXT_GARRISON_HORDE_GAINED           = 9,
    TB_TEXT_GARRISON_HORDE_LOST             = 10,
    TB_TEXT_VIGIL_ALLIANCE_GAINED           = 11,
    TB_TEXT_VIGIL_ALLIANCE_LOST             = 12,
    TB_TEXT_VIGIL_HORDE_GAINED              = 13,
    TB_TEXT_VIGIL_HORDE_LOST                = 14,
    TB_TEXT_SLAGWORKS_ALLIANCE_GAINED       = 15,
    TB_TEXT_SLAGWORKS_ALLIANCE_LOST         = 16,
    TB_TEXT_SLAGWORKS_HORDE_GAINED          = 17,
    TB_TEXT_SLAGWORKS_HORDE_LOST            = 18,
    TB_TEXT_FORTRESS_DEFEND_ALLIANCE        = 19,
    TB_TEXT_FORTRESS_DEFEND_HORDE           = 20,
    TB_TEXT_FORTRESS_CAPTURE_ALLIANCE       = 21,
    TB_TEXT_FORTRESS_CAPTURE_HORDE          = 22,
    TB_TEXT_VEHICLE_OUTSIDE_WARNING         = 23,
    TB_TEXT_PREPARATIONS_IN_5_MIN           = 24,
    TB_TEXT_PREPARATIONS_IN_2_MIN           = 25,
    TB_TEXT_PREPARATIONS_IN_1_MIN           = 26,
};

enum TolBaradEvent
{
    EVENT_COUNT_CAPTURED_BASE = 1,
};

const uint32 TBFactions[BG_TEAMS_COUNT] = { 1610, 1732 };

// Stalker
Position const TolBaradDebugAnnouncerPos = { -1234.25f, 961.903f, 159.4913f, 0.0f };

// Quest Infantry NPCs
enum TBQuestInfantryEntry
{
    NPC_ALLIANCE_WARRIOR_INFANTRY = 47599,
    NPC_ALLIANCE_PALADIN_INFANTRY = 47600,
    NPC_ALLIANCE_HUNTER_INFANTRY = 47595,
    NPC_ALLIANCE_MAGE_INFANTRY = 47598,

    NPC_HORDE_DRUID_INFANTRY = 47607,
    NPC_HORDE_MAGE_INFANTRY = 47608,
    NPC_HORDE_ROGUE_INFANTRY = 47609,
    NPC_HORDE_SHAMAN_INFANTRY = 47610,
};

uint32 const TB_QUEST_INFANTRY[BG_TEAMS_COUNT][4] =
{
    { NPC_HORDE_DRUID_INFANTRY, NPC_HORDE_MAGE_INFANTRY, NPC_HORDE_ROGUE_INFANTRY, NPC_HORDE_SHAMAN_INFANTRY },
    { NPC_ALLIANCE_WARRIOR_INFANTRY, NPC_ALLIANCE_PALADIN_INFANTRY, NPC_ALLIANCE_HUNTER_INFANTRY, NPC_ALLIANCE_MAGE_INFANTRY },
};

uint8 const TB_QUEST_INFANTRY_MAX = 37;
Position const TBQuestInfantrySpawnData[TB_QUEST_INFANTRY_MAX] =
{
    { -930.4685f, 1020.178f, 121.5658f, 0.1537642f  },
    { -831.5157f, 975.816f,  121.5255f, 5.022717f   },
    { -837.0773f, 943.9008f, 121.5055f, 5.461119f   },
    { -839.1646f, 1024.046f, 121.5505f, 4.782219f   },
    { -881.283f,  1033.25f,  121.5243f, 0.0f        },
    { -883.038f,  924.955f,  121.5243f, 0.0f        },
    { -883.913f,  978.059f,  121.5243f, 3.388291f   },
    { -883.6224f, 950.8459f, 121.5122f, 0.8307042f  },
    { -895.181f,  1015.2f,   121.5505f, 2.652318f   },
    { -943.4023f, 961.7462f, 121.5658f, 5.258394f   },
    { -958.649f,  926.877f,  121.5243f, 0.0f        },
    { -959.743f,  1029.09f,  121.5243f, 0.0f        },
    { -964.6652f, 978.5373f, 121.5257f, 0.02025719f },
    { -1407.14f,  721.42f,   123.5033f, 0.0f        },
    { -1414.46f,  671.66f,   123.5043f, 0.0f        },
    { -1431.7f,   623.073f,  123.5043f, 0.0f        },
    { -1434.162f, 655.8566f, 123.5051f, 4.84886f    },
    { -1445.19f,  739.729f,  123.5457f, 5.767949f   },
    { -1460.954f, 718.418f,  123.6453f, 5.178094f   },
    { -1462.48f,  694.378f,  123.5463f, 0.3441857f  },
    { -1372.23f,  683.707f,  123.5043f, 0.0f        },
    { -1479.46f,  635.799f,  123.5043f, 0.0f        },
    { -1491.259f, 734.5692f, 123.4525f, 1.529741f   },
    { -1509.024f, 688.8625f, 123.5463f, 6.243045f   },
    { -1419.311f, 1310.25f,  133.8389f, 0.0f        },
    { -1444.24f,  1266.439f, 133.8229f, 0.0f        },
    { -1450.569f, 1337.351f, 133.914f,  0.0f        },
    { -1479.819f, 1331.34f,  153.2f,    0.0f        },
    { -1497.62f,  1276.429f, 133.6676f, 3.147845f   },
    { -1498.37f,  1379.689f, 133.827f,  0.0f        },
    { -1499.97f,  1232.87f,  133.8239f, 0.0f        },
    { -1505.7f,   1261.99f,  133.7089f, 0.6167698f  },
    { -1531.84f,  1316.569f, 153.2f,    0.0f        },
    { -1533.141f, 1267.66f,  133.836f,  0.0f        },
    { -1547.59f,  1300.21f,  133.7094f, 1.908187f   },
    { -1563.3f,   1325.79f,  133.6673f, 0.0f        },
};

// Guard NPCs
enum TBGuardEntry
{
    NPC_BARADIN_GUARD                       = 51165,
    NPC_HELLSCREAMS_SENTRY                  = 51166,
};

uint8 const TB_GUARDS_MAX = 8;
Position const GuardNPCSpawns[TB_GUARDS_MAX] =
{
//  { -837.3768f, 1196.082f, 114.2994f, 3.036873f },
//  { -762.118f,  1195.259f, 107.2007f, 3.036873f },
//  { -837.809f,  1179.842f, 114.1356f, 3.159046f },
//  { -762.5504f, 1179.019f, 107.2137f, 3.159046f },
    { -1272.951f, 964.8854f, 119.5782f, 3.193953f },
    { -1274.394f, 997.6511f, 119.5743f, 3.193953f },
    { -1248.226f, 1018.476f, 119.8113f, 1.605703f },
    { -1218.948f, 943.5695f, 119.5994f, 4.625123f },
    { -1195.417f, 965.5364f, 119.8113f, 0.0f },
    { -1220.832f, 1018.497f, 119.8113f, 1.605703f },
    { -1196.151f, 999.5121f, 119.5966f, 0.0f },
    { -1249.304f, 942.9063f, 119.5782f, 4.625123f },
};

enum TBFactionNPCEntry
{
    // Guards
    NPC_BARADIN_GUARD_1 = 47324,
    NPC_BARADIN_GUARD_2 = 47325,
    NPC_BARADIN_GRUNT_1 = 47335,
    NPC_BARADIN_GRUNT_2 = 47336,

    // Questgivers
    NPC_SERGEANT_PARKER = 48066, // Everytime
    NPC_COMMANDER_STEVENS = 48039, // One of these three
    NPC_2ND_LIEUTENANT_WANSWORTH = 48061,
    NPC_MARSHAL_FALLOWS = 48074,

    NPC_COMMANDER_ZANOTH = 48069, // Everytime!
    NPC_STAFF_SERGEANT_LAZGAR = 48062, // One of these three
    NPC_DRILLMASTER_RAZGOTH = 48070,
    NPC_PRIVATE_GARNOTH = 48071,

    // Portal summoners
    NPC_MAVEN_ZARA = 50173,
    NPC_RHAGHA = 50167,
};

struct TBFactionNPCInfo
{
    Position pos;
    uint32 entryAlliance;
    uint32 entryHorde;
};

uint8 const TB_FACTION_NPC_MAX = 4;
TBFactionNPCInfo const FactionNPCSpawns[TB_FACTION_NPC_MAX] =
{
    { { -1259.356f, 1057.108f, 107.0786f, 4.956735f }, NPC_BARADIN_GUARD_1, NPC_BARADIN_GRUNT_1 },
    { { -1254.174f, 1061.094f, 107.0772f, 5.445427f }, NPC_BARADIN_GUARD_2, NPC_BARADIN_GRUNT_2 },
    { { -1256.365f, 1058.47f, 107.0776f, 2.216568f }, NPC_MAVEN_ZARA, NPC_RHAGHA },
    { { -1231.38f, 985.681f, 121.2403f, 0.6108652f }, NPC_SERGEANT_PARKER, NPC_COMMANDER_ZANOTH },
};

// Questing
enum TBQuesting
{
    CELLBLOCK_THE_HOLE          = 0, // The Hole area
    CELLBLOCK_D_BLOCK           = 1, // D-Block area
    CELLBLOCK_CURSED_DEPTHS     = 2, // Cursed Depths area
    CELLBLOCK_MAX               = 3,
    CELLBLOCK_NONE,

    AREA_THE_HOLE = 5659,
    AREA_D_BLOCK = 5657,
    AREA_CURSED_DEPTHS = 5658,

    GO_GATE_TO_THE_HOLE                     = 206845,
    GO_GATE_D_BLOCK                         = 206844,
    GO_CURSED_DEPTHS_GATE                   = 206843,

    GO_CRATE_OF_CELLBLOCK_RATIONS           = 206996,
    GO_CURSED_SHACKLES                      = 206905,
    GO_DUSTY_PRISON_JOURNAL                 = 206890,
};

Position const RandomQuestgiverPos = { -1228.93f, 975.038f, 121.7153f, 5.969026f };

struct TBQuestAreaInfo
{
    uint32 entry;
    uint32 teleportSpell;
};
TBQuestAreaInfo const TBQuestAreas[CELLBLOCK_MAX] =
{
    { AREA_THE_HOLE, SPELL_TB_THE_HOLE_TELEPORT },
    { AREA_D_BLOCK, SPELL_TB_D_BLOCK_TELEPORT },
    { AREA_CURSED_DEPTHS, SPELL_TB_CURSED_DEPTHS_TELEPORT },
};
uint32 const RandomQuestgivers[BG_TEAMS_COUNT][CELLBLOCK_MAX] =
{
    { NPC_MARSHAL_FALLOWS, NPC_2ND_LIEUTENANT_WANSWORTH, NPC_COMMANDER_STEVENS },
    { NPC_DRILLMASTER_RAZGOTH, NPC_STAFF_SERGEANT_LAZGAR, NPC_PRIVATE_GARNOTH },
};

// Capture Points
enum TBCapturePointId
{
    TB_BASE_IRONCLAD_GARRISON = 0,
    TB_BASE_WARDENS_VIGIL = 1,
    TB_BASE_SLAGWORKS = 2,
    TB_BASE_COUNT = 3,
};

struct TBCapturePointSpawnData
{
    Position pos;
    TBCapturePointId id;
    uint32 entryFlagPole[2];
    uint32 wsControlled[2];
    uint32 wsCapturing[2];
    uint32 wsNeutral;
    uint32 textGained[2];
    uint32 textLost[2];
};

TBCapturePointSpawnData const TBCapturePoints[TB_BASE_COUNT] =
{
    { { -896.96f, 979.497f, 121.441f, 3.124123f }, TB_BASE_IRONCLAD_GARRISON, { GO_CAPTURE_POINT_NORTH_A_DEFENDING, GO_CAPTURE_POINT_NORTH_H_DEFENDING }, { TB_WS_GARRISON_ALLIANCE_CONTROLLED, TB_WS_GARRISON_HORDE_CONTROLLED }, { TB_WS_GARRISON_ALLIANCE_CAPTURING, TB_WS_GARRISON_HORDE_CAPTURING }, TB_WS_GARRISON_NEUTRAL, { TB_TEXT_GARRISON_ALLIANCE_GAINED, TB_TEXT_GARRISON_HORDE_GAINED }, { TB_TEXT_GARRISON_ALLIANCE_LOST, TB_TEXT_GARRISON_HORDE_LOST } },
    { { -1492.34f, 1309.87f, 152.961f, 5.462882f }, TB_BASE_WARDENS_VIGIL, { GO_CAPTURE_POINT_WEST_A_DEFENDING, GO_CAPTURE_POINT_WEST_H_DEFENDING }, { TB_WS_VIGIL_ALLIANCE_CONTROLLED, TB_WS_VIGIL_HORDE_CONTROLLED }, { TB_WS_VIGIL_ALLIANCE_CAPTURING, TB_WS_VIGIL_HORDE_CAPTURING }, TB_WS_VIGIL_NEUTRAL, { TB_TEXT_VIGIL_ALLIANCE_GAINED, TB_TEXT_VIGIL_HORDE_GAINED }, { TB_TEXT_VIGIL_ALLIANCE_LOST, TB_TEXT_VIGIL_HORDE_LOST } },
    { { -1437.f, 685.556f, 123.421f, 0.802851f }, TB_BASE_SLAGWORKS, { GO_CAPTURE_POINT_EAST_A_DEFENDING, GO_CAPTURE_POINT_EAST_H_DEFENDING }, { TB_WS_SLAGWORKS_ALLIANCE_CONTROLLED, TB_WS_SLAGWORKS_HORDE_CONTROLLED }, { TB_WS_SLAGWORKS_ALLIANCE_CAPTURING, TB_WS_SLAGWORKS_HORDE_CAPTURING }, TB_WS_SLAGWORKS_NEUTRAL, { TB_TEXT_SLAGWORKS_ALLIANCE_GAINED, TB_TEXT_SLAGWORKS_HORDE_GAINED }, { TB_TEXT_SLAGWORKS_ALLIANCE_LOST, TB_TEXT_SLAGWORKS_HORDE_LOST } },
};

// Towers
enum TBTowerId
{
    TB_TOWER_EAST_SPIRE = 0,
    TB_TOWER_SOUTH_SPIRE = 1,
    TB_TOWER_WEST_SPIRE = 2,
    TB_TOWERS_COUNT = 3,
};

struct TBTowerInfo
{
    Position pos;
    uint32 entry;
    uint32 textDamaged;
    uint32 textDestroyed;
    uint32 wsIntact[BG_TEAMS_COUNT];
    uint32 wsDamaged[BG_TEAMS_COUNT];
    uint32 wsDestroyed;
};

TBTowerInfo const TBTowers[TB_TOWERS_COUNT] =
{
    { { -1013.279f, 529.5382f, 146.427f, 1.97222f }, GO_EAST_SPIRE, TB_TEXT_EAST_SPIRE_DAMAGED, TB_TEXT_EAST_SPIRE_DESTROYED, { TB_WS_EAST_INTACT_ALLIANCE, TB_WS_EAST_INTACT_HORDE }, { TB_WS_EAST_DAMAGED_ALLIANCE, TB_WS_EAST_DAMAGED_HORDE }, TB_WS_EAST_DESTROYED_NEUTRAL },
    { { -1618.91f, 954.5417f, 168.601f, 0.06981169f }, GO_SOUTH_SPIRE, TB_TEXT_SOUTH_SPIRE_DAMAGED, TB_TEXT_SOUTH_SPIRE_DESTROYED, { TB_WS_SOUTH_INTACT_ALLIANCE, TB_WS_SOUTH_INTACT_HORDE }, { TB_WS_SOUTH_DAMAGED_ALLIANCE, TB_WS_SOUTH_DAMAGED_HORDE }, TB_WS_SOUTH_DESTROYED_NEUTRAL },
    { { -950.4097f, 1469.101f, 176.596f, 4.180066f }, GO_WEST_SPIRE, TB_TEXT_WEST_SPIRE_DAMAGED, TB_TEXT_WEST_SPIRE_DESTROYED, { TB_WS_WEST_INTACT_ALLIANCE, TB_WS_WEST_INTACT_HORDE }, { TB_WS_WEST_DAMAGED_ALLIANCE, TB_WS_WEST_DAMAGED_HORDE }, TB_WS_WEST_DESTROYED_NEUTRAL },
};

// Vehicles
enum TBVehicles
{
    NPC_ABANDONED_SIEGE_ENGINE = 45344,
};

int8 const TB_ABANDONED_SIEGE_ENGINE_COUNT = 6;
Position const TBAbandonedSiegeEngineSpawnData[TB_ABANDONED_SIEGE_ENGINE_COUNT] =
{
    { -1106.57f, 1196.34f, 121.8023f, 0.4014257f },
    { -1108.52f, 1111.33f, 121.2783f, 1.37881f },
    { -1213.01f, 782.236f, 121.4473f, 1.675516f },
    { -1258.26f, 780.497f, 122.4413f, 1.48353f },
    { -1438.3f, 1095.24f, 121.1363f, 5.288348f },
    { -1442.3f, 1141.07f, 123.6323f, 4.24115f },
};

// Banners
enum TBFactionBannerEntry
{
    GO_BARADINS_WARDEN_BANNER = 207391, // Alliance banner
    GO_HELLSCREAM_REACH_BANNER = 207400, // Horde banner
};

uint32 const TBBannerEntry[BG_TEAMS_COUNT] = { GO_BARADINS_WARDEN_BANNER, GO_HELLSCREAM_REACH_BANNER };

uint8 const TB_BANNER_MAX = 23;
Position const TBBanners[TB_BANNER_MAX] =
{
    { -987.6129f, 963.9861f, 121.4506f, 2.617989f },
    { -988.118f, 993.0087f, 121.6746f, 3.612838f },
    { -1195.941f, 964.342f, 119.728f, 0.8901166f },
    { -1196.892f, 1000.957f, 119.8211f, 5.445428f },
    { -1198.236f, 1081.898f, 120.2007f, 1.06465f },
    { -1089.337f, 1157.161f, 120.2749f, 3.036838f },
    { -1090.033f, 1143.476f, 120.2656f, 3.036838f },
    { -1217.495f, 944.0261f, 119.4949f, 1.989672f },
    { -1219.226f, 1018.168f, 119.728f, 2.251473f },
    { -1210.319f, 1081.885f, 120.2396f, 2.007128f },
    { -1226.903f, 786.7656f, 119.4592f, 1.553341f },
    { -1228.464f, 979.7379f, 119.3814f, 0.03490625f },
    { -1239.668f, 786.7899f, 119.4271f, 1.553341f },
    { -1250.262f, 1017.887f, 119.728f, 0.8377575f },
    { -1250.693f, 943.4496f, 119.4949f, 5.305802f },
    { -1272.29f, 963.5208f, 119.4949f, 2.617989f },
    { -1273.997f, 998.7934f, 119.4884f, 3.665196f },
    { -1378.363f, 725.0087f, 124.2978f, 1.326448f },
    { -1401.97f, 747.0972f, 123.2302f, 0.2443456f },
    { -1421.953f, 1263.559f, 133.6141f, 5.009095f },
    { -1446.497f, 1238.964f, 133.7601f, 5.969027f },
    { -1488.908f, 1118.747f, 124.9255f, 6.248279f },
    { -1488.533f, 1131.608f, 124.6363f, 6.248279f },
};

// Portals
enum TBPortalEntry
{
    TB_PORTAL_ALLIANCE = 208227, // Portal to Stormwind
    TB_PORTAL_HORDE = 208226, // Portal to Orgrimmar
};

uint32 const TBPortalEntry[BG_TEAMS_COUNT] = { TB_PORTAL_ALLIANCE, TB_PORTAL_HORDE };

uint8 const TB_PORTAL_MAX = 2;
Position const TBPortals[TB_PORTAL_MAX] =
{
    { -598.7656f, 1377.974f, 21.91898f, 0.0f },
    { -1257.729f, 1060.365f, 106.9938f, 5.462882f },
};

/* ################### *
 * Tol Barad graveyard *
 * ################### */

enum TBGraveyardAreaId
{
    // Tol Barad
    TB_GY_BARADIN_HOLD = 1789,
    TB_GY_IRONCLAD_GARRISON = 1783,
    TB_GY_WARDENS_VIGIL = 1785,
    TB_GY_SLAGWORKS = 1787,
    TB_GY_WEST_SPIRE = 1784,
    TB_GY_SOUTH_SPIRE = 1786,
    TB_GY_EAST_SPIRE = 1788,
    BATTLEFIELD_TB_GRAVEYARD_MAX = 7,

    // Tol Barad Peninsula
    TBP_GY_ALLIANCE_DAILY = 1808,
    TBP_GY_HORDE_DAILY = 1807,
};

struct TBGraveyardInfo
{
    Position pos;
    uint32 phaseId;
    uint32 gyid;
    uint32 spiritEntry[BG_TEAMS_COUNT];
    bool defenderControls;
};

TBGraveyardInfo const TBGraveyards[BATTLEFIELD_TB_GRAVEYARD_MAX] =
{
    { { -1247.42f, 981.25f, 155.35f, 6.28f }, 128, TB_GY_BARADIN_HOLD, { NPC_TB_GY_SPIRIT_BARADIN_HOLD_A, NPC_TB_GY_SPIRIT_BARADIN_HOLD_H }, true },
    { { -974.28f, 1089.47f, 132.99f, 5.90f }, 64, TB_GY_IRONCLAD_GARRISON, { NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_A, NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_H }, false },
    { { -1570.44f, 1167.57f, 159.50f, 2.20f }, 64, TB_GY_WARDENS_VIGIL, { NPC_TB_GY_SPIRIT_WARDENS_VIGIL_A, NPC_TB_GY_SPIRIT_WARDENS_VIGIL_H }, false },
    { { -1343.32f, 565.24f, 139.04f, 1.66f }, 64, TB_GY_SLAGWORKS, { NPC_TB_GY_SPIRIT_SLAGWORKS_A, NPC_TB_GY_SPIRIT_SLAGWORKS_H }, false },
    { { -1052.02f, 1494.05f, 191.41f, 4.13f }, 64, TB_GY_WEST_SPIRE, { NPC_TB_GY_SPIRIT_WEST_SPIRE_A, NPC_TB_GY_SPIRIT_WEST_SPIRE_H }, false },
    { { -1603.34f, 874.29f, 193.69f, 5.27f }, 64, TB_GY_SOUTH_SPIRE, { NPC_TB_GY_SPIRIT_SOUTH_SPIRE_A, NPC_TB_GY_SPIRIT_SOUTH_SPIRE_H }, false },
    { { -943.66f, 572.36f, 157.54f, 1.74f }, 64, TB_GY_EAST_SPIRE, { NPC_TB_GY_SPIRIT_EAST_SPIRE_A, NPC_TB_GY_SPIRIT_EAST_SPIRE_H }, false },
};

/* ####################### *
 * Tol Barad capture point *
 * ####################### */

class TolBaradCapturePoint : public BfCapturePoint
{
    public:
        TolBaradCapturePoint(BattlefieldTB* battlefield, TeamId teamInControl);

        void ChangeTeam(TeamId /*oldteam*/) override;
};

/* ##################### *
 * Tol Barad battlefield *
 * ##################### */

class TC_GAME_API BattlefieldTB : public Battlefield
{
    public:
        ~BattlefieldTB();

        void OnStartGrouping() override;
        void OnBattleStart() override;
        void OnBattleEnd(bool endByTimer) override;

        void OnPlayerEnterZone(Player* player) override;
        void OnPlayerLeaveZone(Player* player) override;

        void OnPlayerJoinWar(Player* player) override;
        void OnPlayerLeaveWar(Player* player) override;

        bool Update(uint32 diff) override;

        void OnCreatureCreate(Creature* creature) override;
        //void OnCreatureRemove(Creature* creature) override;

        void OnGameObjectCreate(GameObject* go) override;

        void UpdateCapturedBaseCount();
        //void UpdatedDestroyedTowerCount(TeamId team);

        //void DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber = 1) override;

        bool SetupBattlefield() override;

        void SendInitWorldStatesTo(Player* player);
        void SendInitWorldStatesToAll() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
        void UpdateWorldStates();

        void HandleKill(Player* killer, Unit* victim) override;
        //void OnUnitDeath(Unit* unit) override;
        void PromotePlayer(Player* killer);
        void RemoveAurasFromPlayer(Player* player);

        void ProcessEvent(WorldObject* obj, uint32 eventId) override;

        void TowerDamaged(TBTowerId tbTowerId);
        void TowerDestroyed(TBTowerId tbTowerId);

        // returns the graveyardId in the specified area.
        //uint8 GetSpiritGraveyardId(uint32 areaId) const;

        void UpdateNPCsAndGameObjects();
        void CreateCapturePoints();

    protected:
        // Minutes till battle preparation warnings
        bool warnedFiveMinutes;
        bool warnedTwoMinutes;
        bool warnedOneMinute;

        uint32 m_saveTimer;

        bool updatedNPCAndObjects;
        uint32 m_updateObjectsTimer;

        uint32 m_BonusTime;

        GuidSet BattleInactiveNPCs;
        GuidSet BattleInactiveGOs;

        GuidSet TemporaryNPCs;
        GuidSet TemporaryGOs;

        GuidSet Towers;

        uint8 m_iCellblockRandom;

        ObjectGuid TBGatesGUID;
        ObjectGuid TBDoorGUID;

        ObjectGuid m_gateToTheHoleGUID;
        ObjectGuid m_gateDBlockGUID;
        ObjectGuid m_gateCursedDepthsGUID;
};

#endif
