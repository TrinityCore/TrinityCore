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

#include "siege_of_orgrimmar.hpp"
#include "Object.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Player.h"

#include "ScriptedGossip.h"

// There are 36+36 lightweight crates (18 per room),
// 12+12 stout crates (6 per room),
// 4+4 massive crates (2 per room),
// 8 pandaren crates (2 per room).
// West and South rooms are mantid, North and East rooms are mogu.
// Players have two ways: from North to West and from East to South.
// North and West are first rooms, South and East are second rooms.
//

// TODO:
// "Return to Stone" spells

#define POSITION_X_MIN 1528.39f
#define POSITION_X_MAX 1735.57f
#define POSITION_Y_MIN -5226.14f
#define POSITION_Y_MAX -5018.64f
#define POSITION_Z_MIN -293.f
#define POSITION_Z_MAX -280.f

#define MAX_ENERGY 50
#define LIGHTWEIGHT_MOB_ENERGY 2
#define STOUT_MOB_ENERGY 5
#define MASSIVE_MOB_ENERGY 10

enum ScriptedTexts
{
    SAY_COMPLETE_3 = 0,
    SAY_MODULE_1_50 = 1,
    SAY_MODULE_2_50 = 3,
    SAY_MODULE_1_100 = 4,
    SAY_COMPLETE_1 = 5,
    SAY_COMPLETE_2 = 6,
    SAY_AGGRO = 10,
    SAY_OUT_OF_TIME = 12,
    SAY_WIPE = 13,
};

enum Spells
{
    SPELL_ACHIEVEMENT = 145904,

    SPELL_GB_11010 = 145864, // berserk, kill all players

    SPELL_UNSTABLE_DEFENSE_SYSTEMS_TELEPORT = 142722,
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_GOBJECT = 144256, // no visual, hits gameobjects
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AURA_1 = 144273, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_1 = 144281, // fast red ray from caster to dest, from the spoils to chests at the beginning of the fight
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_1 = 144921, // alternative power 0 - 50
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_PERIODIC = 145685, // triggers damage
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_1 = 145687, // red zone around the spoils
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_DMG = 145688, // damage
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AURA_2 = 145838, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_2 = 146529, // red ray from caster to dest, from mobs to levers
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_2 = 147672, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_3 = 147673, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2 = 148505, // alternative power 0 - 50
    SPELL_UNSTABLE_DEFENCE_SYSTEMS_AURA_3 = 149117, // red beam on the ground

    SPELL_LIFT_HOOK = 142721,
    SPELL_LEFT_HOOK_JUMP = 146489,
    SPELL_LIFT_HOOK_AURA = 146491,
    SPELL_LIFT_HOOK_VEHICLE = 146500,

    // Animated Stone Mogu
    SPELL_HARDEN_FLESH = 144922,
    SPELL_HARDEN_FLESH_DMG = 145218,

    SPELL_EARTHEN_SHARD = 144923,

    // Burial Urn
    SPELL_SPARK_OF_LIFE_PERIODIC = 142694,
    SPELL_SPARK_OF_LIFE_MISSILE = 142695,
    SPELL_SPARK_OF_LIFE_VISUAL = 142676, // used by Spark of Life
    SPELL_PULSATION = 142765,
    SPELL_PULSATION_DMG = 142759,
    SPELL_NOVA = 142775,

    // Quilen Guardian
    SPELL_CARNIVOROUS_BITE = 144853,

    // Mogu Shadow Ritualist
    SPELL_TORMENT = 142934,
    SPELL_TORMENT_DUMMY = 142942,
    SPELL_TORMENT_DMG = 142983,

    SPELL_MOGU_RUNE_OF_POWER = 145461,
    SPELL_MOGU_RUNE_OF_POWER_AREATRIGGER = 145460,
    SPELL_MOGU_RUNE_OF_POWER_AURA = 145458,

    SPELL_FORBIDDEN_MAGIC = 145230,
    SPELL_FORBIDDEN_MAGIC_DMG = 145240,

    // Modified Anima Golem
    SPELL_CRIMSON_RECONSTITUTION = 142947,
    SPELL_CRIMSON_RECONSTITUTION_AREATRIGGER = 145270,
    SPELL_CRIMSON_RECONSTITUTION_HEAL = 145271,
    SPELL_MATTER_SCRAMBLE = 145288,
    SPELL_MATTER_SCRAMBLE_AOE = 145369,
    SPELL_MATTER_SCRAMBLE_DMG = 145393,
    SPELL_CRIMSON_ACID = 149280,

    //
    SPELL_RETURN_TO_STONE = 145489,
    SPELL_RETURN_TO_STONE_DMG = 145514, // damage and knock back
    SPELL_STONE_STATUE = 142526, // sitting down, explode on removing (in 2 sec) (it's not a statue spell)
    SPELL_RETURN_TO_STONE_VISUAL_1 = 142944, // attacking
    SPELL_RETURN_TO_STONE_VISUAL_2 = 144873, // sitting down, explode on removing (in 3 sec) (it's not a statue spell)
    SPELL_RETURN_TO_STONE_VISUAL_3 = 145499, // sit down, explode on removing
    SPELL_RETURN_TO_STONE_VISUAL_4 = 145537, // explode, stone on the ground
    SPELL_RETURN_TO_STONE_SPAWN_1 = 145483, // some visual
    SPELL_RETURN_TO_STONE_SPAWN_2 = 144872, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_3 = 148508, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_4 = 148509, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_5 = 148511, // no visual
    SPELL_ANIMATED_STRIKE = 145523,
    SPELL_STRENGTH_OF_THE_STONE = 145998,

    // Jun-Wei
    SPELL_SHADOW_VOLLEY = 148515,
    SPELL_SHADOW_VOLLEY_DMG = 148516,

    // Zu-Yin
    SPELL_MOLTEN_FIST = 148518,
    SPELL_MOLTEN_FIST_DMG = 148517,

    // Xiang-Lin
    SPELL_JADE_TEMPEST = 148582,
    SPELL_JADE_TEMPEST_DMG = 148583,

    // Kun-Da
    SPELL_FRACTURE = 148513,
    SPELL_FRACTURE_DMG = 148514,

    // Sri'thik Bombardier
    SPELL_GUSTING_BOMB = 145712,
    SPELL_GUSTING_BOMB_AREATRIGGER = 145714,
    SPELL_GUSTING_BOMB_PERIODIC = 145715,
    SPELL_GUSTING_BOMB_DMG_1 = 145716,
    SPELL_GUSTING_BOMB_JUMP = 145717,
    SPELL_GUSTING_BOMB_DMG_2 = 145718,

    SPELL_THROW_EXPLOSIVES = 145702,
    SPELL_THROW_EXPLOSIVES_DMG = 145706,

    // Amber Encased Kunchong
    SPELL_ENCAPSULATED_PHEROMONES_SPAWN = 142492,
    SPELL_ENCAPSULATED_PHEROMONES_PERIODIC = 142524,
    SPELL_ENCAPSULATED_PHEROMONES_TRANSFORM = 142559,
    SPELL_ENCAPSULATED_PHEROMONES_AREATRIGGER = 145285,
    SPELL_ENCAPSULATED_PHEROMONES_AURA = 145747,
    SPELL_ENCAPSULATED_PHEROMONES_DMG = 145748,

    // Kor'thik Warcaller
    SPELL_ENRAGE = 145692,
    SPELL_SHATTERED_ARMOR = 148510,

    // Zar'thik Amber Priest
    SPELL_MANTID_SWARM = 142539,
    SPELL_MANTID_SWARM_SUMMON_1 = 145806,
    SPELL_MANTID_SWARM_SUMMON_2 = 145807,
    SPELL_MANTID_SWARM_SUMMON_3 = 145808,

    SPELL_RESIDUE = 145786,
    SPELL_RESIDUE_HEAL = 145790,

    // Set'thik Wind Wielder
    SPELL_WINDSTORM_AREATRIGGER = 145286,
    SPELL_WINDSTORM_DMG = 145817,

    SPELL_RAGE_OF_THE_EMPRESS = 145812,
    SPELL_RAGE_OF_THE_EMPRESS_AURA = 145813,

    // Mantid Commander
    SPELL_SET_TO_BLOW = 145996,
    SPELL_SET_TO_BLOW_OVERRIDE = 145987,
    SPELL_SET_TO_BLOW_DMG = 145993,
    SPELL_SET_TO_BLOW_AREATRIGGER = 146365,
    SPELL_THROW_BOMB = 146364, // player uses this spell to place bombs

    SPELL_PHEROMONE_CLOUD = 148762,
    SPELL_PHEROMONE_CLOUD_DMG = 148760,

    // Ancient Brewmaster Spirit
    SPELL_KEG_TOSS_DUMMY = 146213, // what for ?
    SPELL_KEG_TOSS_MISSILE = 146214,
    SPELL_KEG_TOSS_DMG = 146217,

    SPELL_BREATH_OF_FIRE = 146222,
    SPELL_BREATH_OF_FIRE_DMG = 146226,
    SPELL_BREATH_OF_FIRE_CONFUSE = 146235,
    SPELL_BREATH_OF_FIRE_PERIODIC_DMG = 146230, // triggered by 146235

    SPELL_BLADE_OF_THE_HUNDRED_STEPS = 146068,
    SPELL_BLADE_OF_THE_HUNDRED_STEPS_DMG = 146081,

    // Wise Mistweaver Spirit
    SPELL_EMINENCE = 146189,
    SPELL_EMINENCE_HEAL = 146190,

    SPELL_GUSTING_CRANE_KICK = 146180,
    SPELL_GUSTING_CRANE_KICK_DMG = 146182,
    SPELL_GUSTING_CRANE_KICK_VISUAL = 146185,

    SPELL_STAFF_OF_RESONATING_WATER = 146099,
    SPELL_STAFF_OF_RESONATING_WATER_AREATRIGGER = 146098,
    SPELL_STAFF_OF_RESONATING_WATER_HEAL = 146582,
    SPELL_STAFF_OF_RESONATING_WATER_DMG = 146679,

    // Nameless Windwalker Spirit
    SPELL_PATH_OF_BLOSSOMS_JUMP = 146256,
    SPELL_PATH_OF_BLOSSOMS_AURA = 146253,
    SPELL_PATH_OF_BLOSSOMS_AREATRIGGER = 146255,
    SPELL_PATH_OF_BLOSSOMS_DMG = 146257,
    SPELL_MASS_PARALYSIS = 146289,

    SPELL_CLAW_OF_BURNING_ANGER = 146141,
    SPELL_CLAW_OF_BURNING_ANGER_DMG = 146142,

    // Unstable Spark
    SPELL_UNSTABLE_SPARK_MISSILE = 146824,
    SPELL_UNSTABLE_SPARK_SUMMON = 146820,
    SPELL_UNSTABLE_SPARK_DUMMY = 146803, // aura without any visual
    SPELL_UNSTABLE_SPARK_VISUAL = 146696,
    SPELL_SUPERNOVA = 146815,
};

enum Adds
{
    NPC_UNSECURED_STOCKPILE_OF_PANDAREN_SPOILS = 71501, // for what?
    NPC_SPOILS_OF_PANDARIA = 72281, // spawns at lever's locations, casts red beam on self
    NPC_LIFT_HOOK = 72972,
    NPC_MANTID_SPOILS_1 = 71512,
    NPC_MOGU_SPOILS_1 = 73720,
    NPC_MANTID_SPOILS_2 = 73721,
    NPC_MOGU_SPOILS_2 = 73722,

    // Lightweight Mogu
    NPC_ANIMATED_STONE_MOGU = 71380,
    NPC_BURIAL_URN = 71382,
    NPC_SPARK_OF_LIFE = 71433,
    NPC_QUILEN_GUARDIAN = 71378,
    NPC_QUILEN_GUARDIANS = 72223,

    // Stout Mogu
    NPC_MODIFIED_ANIMA_GOLEM = 71395,
    NPC_MOGU_SHADOW_RITUALIST = 71393,

    // Massive Mogu
    NPC_JUN_WEI = 73723,
    NPC_ZU_YIN = 73724,
    NPC_XIANG_LIN = 73725,
    NPC_KUN_DA = 71408,
    NPC_STONE_STATUE = 72535,

    // Lightweight Mantid
    NPC_SRITHIK_BOMBARDIER = 71385,
    NPC_AMBER_ENCASED_KUNCHONG = 71388,
    NPC_KORTHIK_WARCALLER = 71383,
    NPC_ZARTHIK_SWARMER = 71398, // called by warcallers

    // Stout Mantid
    NPC_ZARTHIK_AMBER_PRIEST = 71397,
    NPC_SETTHIK_WIND_WIELDER = 71405,

    // Massive Mantid
    COMMANDER_IKTAL = 73948,
    COMMANDER_NAKAZ = 73949,
    COMMANDER_TIK = 73951,
    COMMANDER_ZAKTAL = 71409,

    // Pandaren
    NPC_ANCIENT_BREWMASTER_SPIRIT = 71427,
    NPC_WISE_MISTWEAVER_SPIRIT = 71428,
    NPC_NAMELESS_WINDWALKER_SPIRIT = 71430,

    // Unstable Spark
    NPC_UNSTABLE_SPARK = 73104,
};

enum Events
{

};

enum Datas
{
    DATA_ROOM_STATE_NORTH = 1,
    DATA_ROOM_STATE_WEST,
    DATA_ROOM_STATE_SOUTH,
    DATA_ROOM_STATE_EAST,

    DATA_MOB_ROOM,
    DATA_LIFT_HOOK_ROOM,

    DATA_LIGHTWEIGHT_DIED,
    DATA_STOUT_DIED,
    DATA_MASSIVE_DIED,

    DATA_STONE_STATUE_COUNT
};

enum Actions
{
    ACTION_START_ENCOUNTER = 1,
    ACTION_RESET_ENCOUNTER,
    ACTION_FIRST_MODULE_ACTIVATED,
    ACTION_START_SECOND_PART,
    ACTION_SECOND_MODULE_ACTIVATED,
    ACTION_COMPLETE_ENCOUNTER,

    ACTION_USED_LEVER_NORTH,
    ACTION_USED_LEVER_WEST,
    ACTION_USED_LEVER_SOUTH,
    ACTION_USED_LEVER_EAST,
};

enum Timers
{
    TIMER_CHECK_EVADE = 30 * IN_MILLISECONDS,

    TIMER_MOB_AGGRO = 2 * IN_MILLISECONDS,

    TIMER_LIFT_HOOK_COOLDOWN = 10 * IN_MILLISECONDS,

    TIMER_BERSERK = 270 * IN_MILLISECONDS,
    TIMER_UPDATE_WORLD_STATE = 1 * IN_MILLISECONDS,

    // Amber Encased Kunchong
    TIMER_ENCAPSULATED_PHEROMONES = 4 * IN_MILLISECONDS,

    // Kor'thik Warcaller
    TIMER_ENRAGE_FIRST = 4 * IN_MILLISECONDS,
    TIMER_ENRAGE = 10 * IN_MILLISECONDS,

    // Zar'thik Amber Priest
    TIMER_MANTID_SWARM_FIRST = 8 * IN_MILLISECONDS,
    TIMER_MANTID_SWARM = 35 * IN_MILLISECONDS,
    TIMER_RESIDUE_FIRST = 5 * IN_MILLISECONDS,
    TIMER_RESIDUE = 18 * IN_MILLISECONDS,

    // Set'thik Wind Wielder
    TIMER_RAGE_OF_THE_EMPRESS_FIRST = 3 * IN_MILLISECONDS,
    TIMER_RAGE_OF_THE_EMPRESS = 18 * IN_MILLISECONDS,
    TIMER_WINDSTORM_FIRST = 6 * IN_MILLISECONDS,
    TIMER_WINDSTORM = 34 * IN_MILLISECONDS,
    TUNER_WINDSTORM_DMG_DELAY = 2 * IN_MILLISECONDS,

    // Mantid Commander
    TIMER_SET_TO_BLOW_FIRST = 5 * IN_MILLISECONDS,
    TIMER_SET_TO_BLOW = 28 * IN_MILLISECONDS,
    TIMER_SET_TO_BLOW_EXPLODE = 3 * IN_MILLISECONDS,
    TIMER_PHEROMONE_CLOUD = 5 * IN_MILLISECONDS,

    // Ancient Brewmaster Spirit
    TIMER_KEG_TOSS_FIRST = 5 * IN_MILLISECONDS,
    TIMER_KEG_TOSS = 10 * IN_MILLISECONDS,
    TIMER_BREATH_OF_FIRE_FIRST = 9 * IN_MILLISECONDS,
    TIMER_BREATH_OF_FIRE = 18 * IN_MILLISECONDS,

    // Wise Mistweaver Spirit
    TIMER_GUSTING_CRANE_KICK_FIRST = 8 * IN_MILLISECONDS,
    TIMER_GUSTING_CRANE_KICK = 25 * IN_MILLISECONDS,

    // Nameless Windwalker Spirit
    TIMER_PATH_OF_BLOSSOMS_FIRST = 8 * IN_MILLISECONDS,
    TIMER_PATH_OF_BLOSSOMS = 25 * IN_MILLISECONDS,
    TIMER_PATH_OF_BLOSSOMS_EXPLODE = 2 * IN_MILLISECONDS,
};

enum eDatas
{
    DATA_MATTER_SCRAMBLE_COUNT = 1,
    DATA_MATTER_SCRAMBLE_GUID
};

enum Phases
{
    PHASE_ONE,
    PHASE_TWO,
};

enum SpoilsOfPandariaRooms : int
{
    ROOM_NONE = -1, // no room
    ROOM_NORTH = 0, // north
    ROOM_WEST = 1,  // west
    ROOM_SOUTH = 2, // south
    ROOM_EAST = 3,  // east

    MAX_ROOMS = 4
};

enum SpoilsOfPandariaCrates : int
{
    CRATE_NONE = -1,
    CRATE_LIGHTWEIGHT_MOGU = 0,
    CRATE_STOUT_MOGU = 1,
    CRATE_MASSIVE_MOGU = 2,
    CRATE_LIGHTWEIGHT_MANTID = 3,
    CRATE_STOUT_MANTID = 4,
    CRATE_MASSIVE_MANTID = 5,
    CRATE_PANDAREN = 6,
};

/*#define ROOM_POSITIONS_NORTH_MAX 14
const Position northRoomPos[ROOM_POSITIONS_NORTH_MAX] =
{
    {1700.78f, -5085.56f, -289.40f, 1.70f},
    {1693.30f, -5090.13f, -289.35f, 1.87f},
    {1691.42f, -5087.63f, -289.23f, 1.86f},
    {1655.12f, -5111.52f, -289.39f, 3.14f},
    {1657.04f, -5115.13f, -289.70f, 3.36f},
    {1653.36f, -5117.78f, -289.35f, 3.50f},
    {1667.33f, -5136.40f, -290.12f, 2.87f},
    {1660.42f, -5140.47f, -289.73f, 3.40f},
    {1694.82f, -5192.77f, -289.23f, 4.96f},
    {1729.05f, -5172.08f, -289.39f, 6.22f},
    {1726.47f, -5168.15f, -289.38f, 0.28f},
    {1728.51f, -5163.82f, -289.39f, 0.58f},
    {1718.47f, -5148.44f, -289.38f, 0.68f},
    {1735.54f, -5137.00f, -289.42f, 0.47f}
};

#define ROOM_POSITIONS_WEST_MAX 15
const Position westRoomPos[ROOM_POSITIONS_WEST_MAX] =
{
    {1647.56f, -5109.13f, -289.35f, 4.75f},
    {1652.20f, -5107.12f, -289.04f, 4.80f},
    {1654.02f, -5109.88f, -289.39f, 4.98f},
    {1689.72f, -5085.22f, -289.23f, 0.20f},
    {1688.00f, -5082.02f, -289.56f, 0.36f},
    {1695.20f, -5077.29f, -289.40f, 0.51f},
    {1660.55f, -5025.74f, -289.42f, 1.77f},
    {1643.74f, -5036.78f, -289.42f, 2.06f},
    {1640.68f, -5033.03f, -289.41f, 1.96f},
    {1632.96f, -5022.17f, -289.40f, 0.82f},
    {1628.27f, -5022.39f, -289.39f, 1.21f},
    {1625.55f, -5018.64f, -289.39f, 1.49f},
    {1593.55f, -5042.63f, -289.23f, 3.32f},
    {1628.60f, -5094.50f, -289.75f, 4.84f},
    {1634.36f, -5089.90f, -290.12f, 5.22f}
};

#define ROOM_POSITIONS_SOUTH_MAX 11
const Position southRoomPos[ROOM_POSITIONS_SOUTH_MAX] =
{
    {1568.88f, -5174.79f, -289.40f, 0.68f},
    {1616.39f, -5142.75f, -289.35f, 5.50f},
    {1630.20f, -5161.59f, -290.13f, 2.02f},
    {1635.45f, -5157.54f, -289.75f, 5.28f},
    {1670.37f, -5209.22f, -289.23f, 5.60f},
    {1638.39f, -5233.24f, -289.39f, 2.18f},
    {1635.91f, -5229.49f, -289.38f, 4.37f},
    {1630.97f, -5229.69f, -289.40f, 4.03f},
    {1620.38f, -5214.58f, -289.38f, 3.78f},
    {1603.39f, -5226.14f, -289.42f, 3.85f},
    {1568.74f, -5174.59f, -289.40f, 2.32f}
};

#define ROOM_POSITIONS_EAST_MAX 10
const Position eastRoomPos[ROOM_POSITIONS_EAST_MAX] =
{
    {1568.88f, -5174.79f, -289.40f, 0.68f},
    {1616.39f, -5142.75f, -289.35f, 5.50f},
    {1630.20f, -5161.59f, -290.13f, 2.02f},
    {1635.45f, -5157.54f, -289.75f, 5.28f},
    {1670.37f, -5209.22f, -289.23f, 5.60f},
    {1638.39f, -5233.24f, -289.39f, 2.18f},
    {1635.91f, -5229.49f, -289.38f, 4.37f},
    {1630.97f, -5229.69f, -289.40f, 4.03f},
    {1620.38f, -5214.58f, -289.38f, 3.78f},
    {1603.39f, -5226.14f, -289.42f, 3.85f}
};*/

#define LIFT_HOOK_COUNT 8
const Position liftHookPos[LIFT_HOOK_COUNT] =
{
    {1667.83f, -5122.12f, -290.00f, 2.26f}, // north 1
    {1671.60f, -5125.71f, -289.97f, 3.46f}, // north 2

    {1647.28f, -5087.84f, -289.97f, 2.17f}, // west 1
    {1651.51f, -5093.90f, -289.96f, 2.24f}, // west 2

    {1599.73f, -5124.61f, -290.08f, 0.51f}, // south 1
    {1602.56f, -5129.56f, -290.08f, 0.50f}, // south 2

    {1615.20f, -5155.27f, -290.02f, 5.29f}, // east 1
    {1611.73f, -5157.54f, -289.95f, 5.29f}  // east 2
};

const uint32 leftHookRoomSequence[LIFT_HOOK_COUNT]
{
    ROOM_NORTH,
    ROOM_NORTH,
    ROOM_WEST,
    ROOM_WEST,
    ROOM_SOUTH,
    ROOM_SOUTH,
    ROOM_EAST,
    ROOM_EAST
};

const Position liftEndPos[MAX_ROOMS] =
{
    {1649.12f, -5132.58f, -271.01f, 2.16f}, // north
    {1631.69f, -5107.25f, -271.01f, 5.22f}, // west
    {1613.90f, -5119.49f, -271.01f, 5.34f}, // south
    {1631.22f, -5146.79f, -270.98f, 2.12f}  // east
};

const Position unstableSparkPos[MAX_ROOMS] =
{
    { 1693.60f, -5134.22f, -289.91f, 2.53f }, // north
    { 1650.74f, -5065.91f, -289.91f, 3.82f }, // west
    { 1569.24f, -5114.05f, -289.91f, 5.26f }, // south
    { 1617.72f, -5193.00f, -289.88f, 2.09f }  // east
};

#define LIGHTWEIGHT_MOGU_MOBS_COUNT 3
const uint32 lightweightMoguMobs[LIGHTWEIGHT_MOGU_MOBS_COUNT] =
{
    NPC_ANIMATED_STONE_MOGU,
    NPC_BURIAL_URN,
    NPC_QUILEN_GUARDIANS
};

#define STOUT_MOGU_MOBS_COUNT 2
const uint32 stoutMoguMobs[LIGHTWEIGHT_MOGU_MOBS_COUNT] =
{
    NPC_MODIFIED_ANIMA_GOLEM,
    NPC_MOGU_SHADOW_RITUALIST
};

#define MASSIVE_MOGU_MOBS_COUNT 4
const uint32 massiveMoguMobs[MASSIVE_MOGU_MOBS_COUNT] =
{
    NPC_JUN_WEI,
    NPC_ZU_YIN,
    NPC_XIANG_LIN,
    NPC_KUN_DA
};

#define LIGHTWEIGHT_MANTID_MOBS_COUNT 3
const uint32 lightweightMantidMobs[LIGHTWEIGHT_MANTID_MOBS_COUNT] =
{
    NPC_SRITHIK_BOMBARDIER,
    NPC_AMBER_ENCASED_KUNCHONG,
    NPC_KORTHIK_WARCALLER
};

#define STOUT_MANTID_MOBS_COUNT 2
const uint32 stoutMantidMobs[STOUT_MANTID_MOBS_COUNT] =
{
    NPC_ZARTHIK_AMBER_PRIEST,
    NPC_SETTHIK_WIND_WIELDER
};

#define MASSIVE_MANTID_MOBS_COUNT 4
const uint32 massiveMantidMobs[MASSIVE_MANTID_MOBS_COUNT] =
{
    COMMANDER_IKTAL,
    COMMANDER_NAKAZ,
    COMMANDER_TIK,
    COMMANDER_ZAKTAL
};

#define PANDAREN_MOBS_COUNT 3
const uint32 pandarenMobs[PANDAREN_MOBS_COUNT] =
{
    NPC_ANCIENT_BREWMASTER_SPIRIT,
    NPC_WISE_MISTWEAVER_SPIRIT,
    NPC_NAMELESS_WINDWALKER_SPIRIT
};

/*struct SimplePoint
{
    SimplePoint() { }
    SimplePoint(float _x, float _y) { x = _x; y = _y; }

    float x;
    float y;
};

typedef std::vector<SimplePoint> SimplePoints;

bool IsSimplePointInZone(const SimplePoint &test, const SimplePoints &polygon)
{
    const static int qpatt[2][2] = { {0,1}, {3,2} };

    if (polygon.size() < 3)
        return false;

    SimplePoints::const_iterator end = polygon.end();
    SimplePoint pred_pt = polygon.back();
    pred_pt.x -= test.x;
    pred_pt.y -= test.y;

    int pred_q = qpatt[pred_pt.y < 0][pred_pt.x<  0];

    int w = 0;

    for (SimplePoints::const_iterator iter = polygon.begin(); iter != end; ++iter)
    {
        SimplePoint cur_pt = *iter;

        cur_pt.x -= test.x;
        cur_pt.y -= test.y;

        int q = qpatt[cur_pt.y < 0][cur_pt.x < 0];

        switch (q - pred_q)
        {
            case -3:
                ++w;
                break;
            case 3:
                --w;
                break;
            case -2:
                if (pred_pt.x * cur_pt.y >= pred_pt.y * cur_pt.x)
                    ++w;
                break;
            case 2:
                if (!(pred_pt.x * cur_pt.y >= pred_pt.y * cur_pt.x))
                    --w;
                break;
        }

        pred_pt = cur_pt;
        pred_q = q;
    }
    return w != 0;
}*/

bool IsFirstRoom(SpoilsOfPandariaRooms room)
{
    return room == SpoilsOfPandariaRooms::ROOM_NORTH || room == SpoilsOfPandariaRooms::ROOM_SOUTH;
}

bool IsSecondRoom(SpoilsOfPandariaRooms room)
{
    return room == SpoilsOfPandariaRooms::ROOM_WEST || room == SpoilsOfPandariaRooms::ROOM_EAST;
}

SpoilsOfPandariaRooms GetCrateRoomForCrateEntry(uint32 crateEntry)
{
    switch (crateEntry)
    {
        // Crates in north room
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_18:
        // Crates in north room
    case GO_STOUT_CRATE_OF_MOGU_1:
    case GO_STOUT_CRATE_OF_MOGU_2:
    case GO_STOUT_CRATE_OF_MOGU_3:
    case GO_STOUT_CRATE_OF_MOGU_4:
    case GO_STOUT_CRATE_OF_MOGU_5:
    case  GO_STOUT_CRATE_OF_MOGU_6:
        // Crates in north room
    case GO_MASSIVE_CRATE_OF_MOGU_1:
    case GO_MASSIVE_CRATE_OF_MOGU_2:
    case GO_CRATE_OF_PANDAREN_RELICS_1:
    case GO_CRATE_OF_PANDAREN_RELICS_2:
        return SpoilsOfPandariaRooms::ROOM_NORTH;
        // Crates in east room
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_36:
        // Crates in east room
    case GO_STOUT_CRATE_OF_MOGU_7:
    case GO_STOUT_CRATE_OF_MOGU_8:
    case GO_STOUT_CRATE_OF_MOGU_9:
    case GO_STOUT_CRATE_OF_MOGU_10:
    case GO_STOUT_CRATE_OF_MOGU_11:
    case GO_STOUT_CRATE_OF_MOGU_12:
        // Crates in east room
    case GO_MASSIVE_CRATE_OF_MOGU_3:
    case GO_MASSIVE_CRATE_OF_MOGU_4:
        // east
    case GO_CRATE_OF_PANDAREN_RELICS_7:
    case GO_CRATE_OF_PANDAREN_RELICS_8:
        return SpoilsOfPandariaRooms::ROOM_EAST;
        // Crates in south room
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_18:
        // Crates in south room
    case GO_STOUT_CRATE_OF_MANTID_1:
    case GO_STOUT_CRATE_OF_MANTID_2:
    case GO_STOUT_CRATE_OF_MANTID_3:
    case GO_STOUT_CRATE_OF_MANTID_4:
    case GO_STOUT_CRATE_OF_MANTID_5:
    case GO_STOUT_CRATE_OF_MANTID_6:
        // Crates in south room
    case GO_MASSIVE_CRATE_OF_MANTID_1:
    case GO_MASSIVE_CRATE_OF_MANTID_2:
        // south
    case GO_CRATE_OF_PANDAREN_RELICS_3:
    case GO_CRATE_OF_PANDAREN_RELICS_4:
        return SpoilsOfPandariaRooms::ROOM_SOUTH;
        // Crates in west room
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_36:
        // Crates in west room
    case GO_STOUT_CRATE_OF_MANTID_7:
    case GO_STOUT_CRATE_OF_MANTID_8:
    case GO_STOUT_CRATE_OF_MANTID_9:
    case GO_STOUT_CRATE_OF_MANTID_10:
    case GO_STOUT_CRATE_OF_MANTID_11:
    case GO_STOUT_CRATE_OF_MANTID_12:
        // Crates in west room
    case GO_MASSIVE_CRATE_OF_MANTID_3:
    case GO_MASSIVE_CRATE_OF_MANTID_4:
        // west
    case GO_CRATE_OF_PANDAREN_RELICS_5:
    case GO_CRATE_OF_PANDAREN_RELICS_6:
        return SpoilsOfPandariaRooms::ROOM_WEST;
    }

    return SpoilsOfPandariaRooms::ROOM_NONE;
}

bool IsCrateEntry(uint32 crateEntry)
{
    switch (crateEntry)
    {
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_18:
    case GO_STOUT_CRATE_OF_MOGU_1:
    case GO_STOUT_CRATE_OF_MOGU_2:
    case GO_STOUT_CRATE_OF_MOGU_3:
    case GO_STOUT_CRATE_OF_MOGU_4:
    case GO_STOUT_CRATE_OF_MOGU_5:
    case  GO_STOUT_CRATE_OF_MOGU_6:
    case GO_MASSIVE_CRATE_OF_MOGU_1:
    case GO_MASSIVE_CRATE_OF_MOGU_2:
    case GO_CRATE_OF_PANDAREN_RELICS_1:
    case GO_CRATE_OF_PANDAREN_RELICS_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_36:
    case GO_STOUT_CRATE_OF_MOGU_7:
    case GO_STOUT_CRATE_OF_MOGU_8:
    case GO_STOUT_CRATE_OF_MOGU_9:
    case GO_STOUT_CRATE_OF_MOGU_10:
    case GO_STOUT_CRATE_OF_MOGU_11:
    case GO_STOUT_CRATE_OF_MOGU_12:
    case GO_MASSIVE_CRATE_OF_MOGU_3:
    case GO_MASSIVE_CRATE_OF_MOGU_4:
    case GO_CRATE_OF_PANDAREN_RELICS_7:
    case GO_CRATE_OF_PANDAREN_RELICS_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_18:
    case GO_STOUT_CRATE_OF_MANTID_1:
    case GO_STOUT_CRATE_OF_MANTID_2:
    case GO_STOUT_CRATE_OF_MANTID_3:
    case GO_STOUT_CRATE_OF_MANTID_4:
    case GO_STOUT_CRATE_OF_MANTID_5:
    case GO_STOUT_CRATE_OF_MANTID_6:
    case GO_MASSIVE_CRATE_OF_MANTID_1:
    case GO_MASSIVE_CRATE_OF_MANTID_2:
    case GO_CRATE_OF_PANDAREN_RELICS_3:
    case GO_CRATE_OF_PANDAREN_RELICS_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_36:
    case GO_STOUT_CRATE_OF_MANTID_7:
    case GO_STOUT_CRATE_OF_MANTID_8:
    case GO_STOUT_CRATE_OF_MANTID_9:
    case GO_STOUT_CRATE_OF_MANTID_10:
    case GO_STOUT_CRATE_OF_MANTID_11:
    case GO_STOUT_CRATE_OF_MANTID_12:
    case GO_MASSIVE_CRATE_OF_MANTID_3:
    case GO_MASSIVE_CRATE_OF_MANTID_4:
    case GO_CRATE_OF_PANDAREN_RELICS_5:
    case GO_CRATE_OF_PANDAREN_RELICS_6:
        return true;
    }

    return false;
}

SpoilsOfPandariaCrates GetCrateTypeForCrateEntry(uint32 crateEntry)
{
    switch (crateEntry)
    {
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_18:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MOGU_36:
        return SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MOGU;
    case GO_STOUT_CRATE_OF_MOGU_1:
    case GO_STOUT_CRATE_OF_MOGU_2:
    case GO_STOUT_CRATE_OF_MOGU_3:
    case GO_STOUT_CRATE_OF_MOGU_4:
    case GO_STOUT_CRATE_OF_MOGU_5:
    case GO_STOUT_CRATE_OF_MOGU_6:
    case GO_STOUT_CRATE_OF_MOGU_7:
    case GO_STOUT_CRATE_OF_MOGU_8:
    case GO_STOUT_CRATE_OF_MOGU_9:
    case GO_STOUT_CRATE_OF_MOGU_10:
    case GO_STOUT_CRATE_OF_MOGU_11:
    case GO_STOUT_CRATE_OF_MOGU_12:
        return SpoilsOfPandariaCrates::CRATE_STOUT_MOGU;
    case GO_MASSIVE_CRATE_OF_MOGU_1:
    case GO_MASSIVE_CRATE_OF_MOGU_2:
    case GO_MASSIVE_CRATE_OF_MOGU_3:
    case GO_MASSIVE_CRATE_OF_MOGU_4:
        return SpoilsOfPandariaCrates::CRATE_MASSIVE_MOGU;
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_1:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_2:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_3:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_4:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_5:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_6:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_7:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_8:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_9:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_10:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_11:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_12:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_13:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_14:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_15:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_16:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_17:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_18:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_19:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_20:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_21:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_22:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_23:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_24:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_25:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_26:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_27:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_28:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_29:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_30:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_31:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_32:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_33:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_34:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_35:
    case GO_LIGHTWEIGHT_CRATE_OF_MANTID_36:
        return SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MANTID;
    case GO_STOUT_CRATE_OF_MANTID_1:
    case GO_STOUT_CRATE_OF_MANTID_2:
    case GO_STOUT_CRATE_OF_MANTID_3:
    case GO_STOUT_CRATE_OF_MANTID_4:
    case GO_STOUT_CRATE_OF_MANTID_5:
    case GO_STOUT_CRATE_OF_MANTID_6:
    case GO_STOUT_CRATE_OF_MANTID_7:
    case GO_STOUT_CRATE_OF_MANTID_8:
    case GO_STOUT_CRATE_OF_MANTID_9:
    case GO_STOUT_CRATE_OF_MANTID_10:
    case GO_STOUT_CRATE_OF_MANTID_11:
    case GO_STOUT_CRATE_OF_MANTID_12:
        return SpoilsOfPandariaCrates::CRATE_STOUT_MANTID;
    case GO_MASSIVE_CRATE_OF_MANTID_1:
    case GO_MASSIVE_CRATE_OF_MANTID_2:
    case GO_MASSIVE_CRATE_OF_MANTID_3:
    case GO_MASSIVE_CRATE_OF_MANTID_4:
        return SpoilsOfPandariaCrates::CRATE_MASSIVE_MANTID;
    case GO_CRATE_OF_PANDAREN_RELICS_1:
    case GO_CRATE_OF_PANDAREN_RELICS_2:
    case GO_CRATE_OF_PANDAREN_RELICS_3:
    case GO_CRATE_OF_PANDAREN_RELICS_4:
    case GO_CRATE_OF_PANDAREN_RELICS_5:
    case GO_CRATE_OF_PANDAREN_RELICS_6:
    case GO_CRATE_OF_PANDAREN_RELICS_7:
    case GO_CRATE_OF_PANDAREN_RELICS_8:
        return SpoilsOfPandariaCrates::CRATE_PANDAREN;
    }

    return SpoilsOfPandariaCrates::CRATE_NONE;
}

uint32 GetMobEntryForCrateType(SpoilsOfPandariaCrates crate)
{
    switch (crate)
    {
    case SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MOGU:
        return lightweightMoguMobs[urand(0, LIGHTWEIGHT_MOGU_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_STOUT_MOGU:
        return stoutMoguMobs[urand(0, STOUT_MOGU_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_MASSIVE_MOGU:
        return massiveMoguMobs[urand(0, MASSIVE_MOGU_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MANTID:
        return lightweightMantidMobs[urand(0, LIGHTWEIGHT_MANTID_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_STOUT_MANTID:
        return stoutMantidMobs[urand(0, STOUT_MANTID_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_MASSIVE_MANTID:
        return massiveMantidMobs[urand(0, MASSIVE_MANTID_MOBS_COUNT - 1)];
    case SpoilsOfPandariaCrates::CRATE_PANDAREN:
        return pandarenMobs[urand(0, PANDAREN_MOBS_COUNT - 1)];
    }

    return 0;
}

SpoilsOfPandariaCrates GetCrateTypeForMobEntry(uint32 mobEntry)
{
    switch (mobEntry)
    {
    case NPC_ANIMATED_STONE_MOGU:
    case NPC_BURIAL_URN:
    case NPC_QUILEN_GUARDIAN:
    case NPC_QUILEN_GUARDIANS:
        return SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MOGU;
    case NPC_SRITHIK_BOMBARDIER:
    case NPC_AMBER_ENCASED_KUNCHONG:
    case NPC_KORTHIK_WARCALLER:
        return SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MANTID;
    case NPC_MODIFIED_ANIMA_GOLEM:
    case NPC_MOGU_SHADOW_RITUALIST:
        return SpoilsOfPandariaCrates::CRATE_STOUT_MOGU;
    case NPC_ZARTHIK_AMBER_PRIEST:
    case NPC_SETTHIK_WIND_WIELDER:
        return SpoilsOfPandariaCrates::CRATE_STOUT_MANTID;
    case NPC_JUN_WEI:
    case NPC_ZU_YIN:
    case NPC_XIANG_LIN:
    case NPC_KUN_DA:
        return SpoilsOfPandariaCrates::CRATE_MASSIVE_MOGU;
    case COMMANDER_IKTAL:
    case COMMANDER_NAKAZ:
    case COMMANDER_TIK:
    case COMMANDER_ZAKTAL:
        return SpoilsOfPandariaCrates::CRATE_MASSIVE_MANTID;
    }

    return SpoilsOfPandariaCrates::CRATE_NONE;
}

uint32 GetPowerForMobEntry(uint32 mobEntry)
{
    switch (mobEntry)
    {
    case NPC_ANIMATED_STONE_MOGU:
    case NPC_BURIAL_URN:
    case NPC_QUILEN_GUARDIAN:
    case NPC_QUILEN_GUARDIANS:
    case NPC_SRITHIK_BOMBARDIER:
    case NPC_AMBER_ENCASED_KUNCHONG:
    case NPC_KORTHIK_WARCALLER:
        return LIGHTWEIGHT_MOB_ENERGY;
    case NPC_MODIFIED_ANIMA_GOLEM:
    case NPC_MOGU_SHADOW_RITUALIST:
    case NPC_ZARTHIK_AMBER_PRIEST:
    case NPC_SETTHIK_WIND_WIELDER:
        return STOUT_MOB_ENERGY;
    case NPC_JUN_WEI:
    case NPC_ZU_YIN:
    case NPC_XIANG_LIN:
    case NPC_KUN_DA:
    case COMMANDER_IKTAL:
    case COMMANDER_NAKAZ:
    case COMMANDER_TIK:
    case COMMANDER_ZAKTAL:
        return MASSIVE_MOB_ENERGY;
    }
    return 0;
}

bool IsInProgress(WorldObject* pSearcher)
{
    if (InstanceScript* pInstance = pSearcher->GetInstanceScript())
    {
        if (pInstance->GetBossState(DATA_SPOILS_OF_PANDARIA) == IN_PROGRESS)
            return true;
    }

    return false;
}

bool IsEncounterDone(WorldObject* pSearcher)
{
    if (InstanceScript* pInstance = pSearcher->GetInstanceScript())
    {
        if (pInstance->GetBossState(DATA_SPOILS_OF_PANDARIA) == DONE)
            return true;
    }

    return false;
}

Creature* GetSpoilsOfPandaria(WorldObject* pSearcher)
{
    if (InstanceScript* pInstance = pSearcher->GetInstanceScript())
    {
        return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SPOILS_OF_PANDARIA));
    }

    return nullptr;
}

GameObject* GetLeverForRoom(WorldObject* pSearcher, SpoilsOfPandariaRooms room)
{
    if (InstanceScript* pInstance = pSearcher->GetInstanceScript())
    {
        switch (room)
        {
        case SpoilsOfPandariaRooms::ROOM_NORTH:
            return pInstance->instance->GetGameObject(pInstance->GetObjectGuid(DATA_SPOILS_OF_PANDARIA_LEVER_NORTH));
        case SpoilsOfPandariaRooms::ROOM_WEST:
            return pInstance->instance->GetGameObject(pInstance->GetObjectGuid(DATA_SPOILS_OF_PANDARIA_LEVER_WEST));
        case SpoilsOfPandariaRooms::ROOM_SOUTH:
            return pInstance->instance->GetGameObject(pInstance->GetObjectGuid(DATA_SPOILS_OF_PANDARIA_LEVER_SOUTH));
        case SpoilsOfPandariaRooms::ROOM_EAST:
            return pInstance->instance->GetGameObject(pInstance->GetObjectGuid(DATA_SPOILS_OF_PANDARIA_LEVER_EAST));
        }
    }

    return nullptr;
}

SpoilsOfPandariaRooms GetOtherRoom(SpoilsOfPandariaRooms room)
{
    switch (room)
    {
    case SpoilsOfPandariaRooms::ROOM_NORTH: return SpoilsOfPandariaRooms::ROOM_SOUTH;
    case SpoilsOfPandariaRooms::ROOM_SOUTH: return SpoilsOfPandariaRooms::ROOM_NORTH;
    case SpoilsOfPandariaRooms::ROOM_WEST: return SpoilsOfPandariaRooms::ROOM_EAST;
    case SpoilsOfPandariaRooms::ROOM_EAST: return SpoilsOfPandariaRooms::ROOM_WEST;
    }

    return SpoilsOfPandariaRooms::ROOM_NONE;
}

const Position spoilsOfPandariaPosition = { 1631.799f, -5125.967f, -271.027f, 5.315065f };

void AddSC_boss_spoils_of_pandaria()
{
   
}
