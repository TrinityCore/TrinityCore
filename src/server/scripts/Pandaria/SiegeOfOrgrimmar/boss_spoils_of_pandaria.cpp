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
    SAY_COMPLETE_3      = 0,
    SAY_MODULE_1_50     = 1,
    SAY_MODULE_2_50     = 3,
    SAY_MODULE_1_100    = 4,
    SAY_COMPLETE_1      = 5,
    SAY_COMPLETE_2      = 6,
    SAY_AGGRO           = 10,
    SAY_OUT_OF_TIME     = 12,
    SAY_WIPE            = 13,
};

enum Spells
{
    SPELL_ACHIEVEMENT                               = 145904,

    SPELL_GB_11010                                  = 145864, // berserk, kill all players

    SPELL_UNSTABLE_DEFENSE_SYSTEMS_TELEPORT         = 142722,
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_GOBJECT          = 144256, // no visual, hits gameobjects
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AURA_1           = 144273, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_1            = 144281, // fast red ray from caster to dest, from the spoils to chests at the beginning of the fight
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_1          = 144921, // alternative power 0 - 50
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_PERIODIC         = 145685, // triggers damage
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_1    = 145687, // red zone around the spoils
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_DMG              = 145688, // damage
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AURA_2           = 145838, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_2            = 146529, // red ray from caster to dest, from mobs to levers
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_2    = 147672, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_3    = 147673, // no visuals ?
    SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2          = 148505, // alternative power 0 - 50
    SPELL_UNSTABLE_DEFENCE_SYSTEMS_AURA_3           = 149117, // red beam on the ground

    SPELL_LIFT_HOOK                                 = 142721,
    SPELL_LEFT_HOOK_JUMP                            = 146489,
    SPELL_LIFT_HOOK_AURA                            = 146491,
    SPELL_LIFT_HOOK_VEHICLE                         = 146500,

    // Animated Stone Mogu
    SPELL_HARDEN_FLESH                              = 144922,
    SPELL_HARDEN_FLESH_DMG                          = 145218,

    SPELL_EARTHEN_SHARD                             = 144923,

    // Burial Urn
    SPELL_SPARK_OF_LIFE_PERIODIC                    = 142694,
    SPELL_SPARK_OF_LIFE_MISSILE                     = 142695,
    SPELL_SPARK_OF_LIFE_VISUAL                      = 142676, // used by Spark of Life
    SPELL_PULSATION                                 = 142765,
    SPELL_PULSATION_DMG                             = 142759,
    SPELL_NOVA                                      = 142775,

    // Quilen Guardian
    SPELL_CARNIVOROUS_BITE                          = 144853,

    // Mogu Shadow Ritualist
    SPELL_TORMENT                                   = 142934,
    SPELL_TORMENT_DUMMY                             = 142942,
    SPELL_TORMENT_DMG                               = 142983,

    SPELL_MOGU_RUNE_OF_POWER                        = 145461,
    SPELL_MOGU_RUNE_OF_POWER_AREATRIGGER            = 145460,
    SPELL_MOGU_RUNE_OF_POWER_AURA                   = 145458,

    SPELL_FORBIDDEN_MAGIC                           = 145230,
    SPELL_FORBIDDEN_MAGIC_DMG                       = 145240,

    // Modified Anima Golem
    SPELL_CRIMSON_RECONSTITUTION                    = 142947,
    SPELL_CRIMSON_RECONSTITUTION_AREATRIGGER        = 145270,
    SPELL_CRIMSON_RECONSTITUTION_HEAL               = 145271,
    SPELL_MATTER_SCRAMBLE                           = 145288,
    SPELL_MATTER_SCRAMBLE_AOE                       = 145369,
    SPELL_MATTER_SCRAMBLE_DMG                       = 145393,
    SPELL_CRIMSON_ACID                              = 149280,

    //
    SPELL_RETURN_TO_STONE                           = 145489,
    SPELL_RETURN_TO_STONE_DMG                       = 145514, // damage and knock back
    SPELL_STONE_STATUE                              = 142526, // sitting down, explode on removing (in 2 sec) (it's not a statue spell)
    SPELL_RETURN_TO_STONE_VISUAL_1                  = 142944, // attacking
    SPELL_RETURN_TO_STONE_VISUAL_2                  = 144873, // sitting down, explode on removing (in 3 sec) (it's not a statue spell)
    SPELL_RETURN_TO_STONE_VISUAL_3                  = 145499, // sit down, explode on removing
    SPELL_RETURN_TO_STONE_VISUAL_4                  = 145537, // explode, stone on the ground
    SPELL_RETURN_TO_STONE_SPAWN_1                   = 145483, // some visual
    SPELL_RETURN_TO_STONE_SPAWN_2                   = 144872, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_3                   = 148508, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_4                   = 148509, // no visual
    SPELL_RETURN_TO_STONE_SPAWN_5                   = 148511, // no visual
    SPELL_ANIMATED_STRIKE                           = 145523,
    SPELL_STRENGTH_OF_THE_STONE                     = 145998,

    // Jun-Wei
    SPELL_SHADOW_VOLLEY                             = 148515,
    SPELL_SHADOW_VOLLEY_DMG                         = 148516,

    // Zu-Yin
    SPELL_MOLTEN_FIST                               = 148518,
    SPELL_MOLTEN_FIST_DMG                           = 148517,

    // Xiang-Lin
    SPELL_JADE_TEMPEST                              = 148582,
    SPELL_JADE_TEMPEST_DMG                          = 148583,

    // Kun-Da
    SPELL_FRACTURE                                  = 148513,
    SPELL_FRACTURE_DMG                              = 148514,

    // Sri'thik Bombardier
    SPELL_GUSTING_BOMB                              = 145712,
    SPELL_GUSTING_BOMB_AREATRIGGER                  = 145714,
    SPELL_GUSTING_BOMB_PERIODIC                     = 145715,
    SPELL_GUSTING_BOMB_DMG_1                        = 145716,
    SPELL_GUSTING_BOMB_JUMP                         = 145717,
    SPELL_GUSTING_BOMB_DMG_2                        = 145718,

    SPELL_THROW_EXPLOSIVES                          = 145702,
    SPELL_THROW_EXPLOSIVES_DMG                      = 145706,

    // Amber Encased Kunchong
    SPELL_ENCAPSULATED_PHEROMONES_SPAWN             = 142492,
    SPELL_ENCAPSULATED_PHEROMONES_PERIODIC          = 142524,
    SPELL_ENCAPSULATED_PHEROMONES_TRANSFORM         = 142559,
    SPELL_ENCAPSULATED_PHEROMONES_AREATRIGGER       = 145285,
    SPELL_ENCAPSULATED_PHEROMONES_AURA              = 145747,
    SPELL_ENCAPSULATED_PHEROMONES_DMG               = 145748,

    // Kor'thik Warcaller
    SPELL_ENRAGE                                    = 145692,
    SPELL_SHATTERED_ARMOR                           = 148510,

    // Zar'thik Amber Priest
    SPELL_MANTID_SWARM                              = 142539,
    SPELL_MANTID_SWARM_SUMMON_1                     = 145806,
    SPELL_MANTID_SWARM_SUMMON_2                     = 145807,
    SPELL_MANTID_SWARM_SUMMON_3                     = 145808,

    SPELL_RESIDUE                                   = 145786,
    SPELL_RESIDUE_HEAL                              = 145790,

    // Set'thik Wind Wielder
    SPELL_WINDSTORM_AREATRIGGER                     = 145286,
    SPELL_WINDSTORM_DMG                             = 145817,

    SPELL_RAGE_OF_THE_EMPRESS                       = 145812,
    SPELL_RAGE_OF_THE_EMPRESS_AURA                  = 145813,

    // Mantid Commander
    SPELL_SET_TO_BLOW                               = 145996,
    SPELL_SET_TO_BLOW_OVERRIDE                      = 145987,
    SPELL_SET_TO_BLOW_DMG                           = 145993,
    SPELL_SET_TO_BLOW_AREATRIGGER                   = 146365,
    SPELL_THROW_BOMB                                = 146364, // player uses this spell to place bombs

    SPELL_PHEROMONE_CLOUD                           = 148762,
    SPELL_PHEROMONE_CLOUD_DMG                       = 148760,

    // Ancient Brewmaster Spirit
    SPELL_KEG_TOSS_DUMMY                            = 146213, // what for ?
    SPELL_KEG_TOSS_MISSILE                          = 146214,
    SPELL_KEG_TOSS_DMG                              = 146217,

    SPELL_BREATH_OF_FIRE                            = 146222,
    SPELL_BREATH_OF_FIRE_DMG                        = 146226,
    SPELL_BREATH_OF_FIRE_CONFUSE                    = 146235,
    SPELL_BREATH_OF_FIRE_PERIODIC_DMG               = 146230, // triggered by 146235

    SPELL_BLADE_OF_THE_HUNDRED_STEPS                = 146068,
    SPELL_BLADE_OF_THE_HUNDRED_STEPS_DMG            = 146081,

    // Wise Mistweaver Spirit
    SPELL_EMINENCE                                  = 146189,
    SPELL_EMINENCE_HEAL                             = 146190,

    SPELL_GUSTING_CRANE_KICK                        = 146180,
    SPELL_GUSTING_CRANE_KICK_DMG                    = 146182,
    SPELL_GUSTING_CRANE_KICK_VISUAL                 = 146185,

    SPELL_STAFF_OF_RESONATING_WATER                 = 146099,
    SPELL_STAFF_OF_RESONATING_WATER_AREATRIGGER     = 146098,
    SPELL_STAFF_OF_RESONATING_WATER_HEAL            = 146582,
    SPELL_STAFF_OF_RESONATING_WATER_DMG             = 146679,

    // Nameless Windwalker Spirit
    SPELL_PATH_OF_BLOSSOMS_JUMP                     = 146256,
    SPELL_PATH_OF_BLOSSOMS_AURA                     = 146253,
    SPELL_PATH_OF_BLOSSOMS_AREATRIGGER              = 146255,
    SPELL_PATH_OF_BLOSSOMS_DMG                      = 146257,
    SPELL_MASS_PARALYSIS                            = 146289,

    SPELL_CLAW_OF_BURNING_ANGER                     = 146141,
    SPELL_CLAW_OF_BURNING_ANGER_DMG                 = 146142,

    // Unstable Spark
    SPELL_UNSTABLE_SPARK_MISSILE                    = 146824,
    SPELL_UNSTABLE_SPARK_SUMMON                     = 146820,
    SPELL_UNSTABLE_SPARK_DUMMY                      = 146803, // aura without any visual
    SPELL_UNSTABLE_SPARK_VISUAL                     = 146696,
    SPELL_SUPERNOVA                                 = 146815,
};

enum Adds
{
    NPC_UNSECURED_STOCKPILE_OF_PANDAREN_SPOILS  = 71501, // for what?
    NPC_SPOILS_OF_PANDARIA                      = 72281, // spawns at lever's locations, casts red beam on self
    NPC_LIFT_HOOK                               = 72972,
    NPC_MANTID_SPOILS_1                         = 71512,
    NPC_MOGU_SPOILS_1                           = 73720,
    NPC_MANTID_SPOILS_2                         = 73721,
    NPC_MOGU_SPOILS_2                           = 73722,

    // Lightweight Mogu
    NPC_ANIMATED_STONE_MOGU                     = 71380,
    NPC_BURIAL_URN                              = 71382,
    NPC_SPARK_OF_LIFE                           = 71433,
    NPC_QUILEN_GUARDIAN                         = 71378,
    NPC_QUILEN_GUARDIANS                        = 72223,

    // Stout Mogu
    NPC_MODIFIED_ANIMA_GOLEM                    = 71395,
    NPC_MOGU_SHADOW_RITUALIST                   = 71393,

    // Massive Mogu
    NPC_JUN_WEI                                 = 73723,
    NPC_ZU_YIN                                  = 73724,
    NPC_XIANG_LIN                               = 73725,
    NPC_KUN_DA                                  = 71408,
    NPC_STONE_STATUE                            = 72535,

    // Lightweight Mantid
    NPC_SRITHIK_BOMBARDIER                      = 71385,
    NPC_AMBER_ENCASED_KUNCHONG                  = 71388,
    NPC_KORTHIK_WARCALLER                       = 71383,
    NPC_ZARTHIK_SWARMER                         = 71398, // called by warcallers

    // Stout Mantid
    NPC_ZARTHIK_AMBER_PRIEST                    = 71397,
    NPC_SETTHIK_WIND_WIELDER                    = 71405,

    // Massive Mantid
    COMMANDER_IKTAL                             = 73948,
    COMMANDER_NAKAZ                             = 73949,
    COMMANDER_TIK                               = 73951,
    COMMANDER_ZAKTAL                            = 71409,

    // Pandaren
    NPC_ANCIENT_BREWMASTER_SPIRIT               = 71427,
    NPC_WISE_MISTWEAVER_SPIRIT                  = 71428,
    NPC_NAMELESS_WINDWALKER_SPIRIT              = 71430,

    // Unstable Spark
    NPC_UNSTABLE_SPARK                          = 73104,
};

enum Events
{

};

enum Datas
{
    DATA_ROOM_STATE_NORTH   = 1,
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
    ACTION_START_ENCOUNTER  = 1,
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
    TIMER_CHECK_EVADE           = 30 * IN_MILLISECONDS,

    TIMER_MOB_AGGRO             = 2 * IN_MILLISECONDS,

    TIMER_LIFT_HOOK_COOLDOWN    = 10 * IN_MILLISECONDS,

    TIMER_BERSERK               = 270 * IN_MILLISECONDS,
    TIMER_UPDATE_WORLD_STATE    = 1 * IN_MILLISECONDS,

    // Amber Encased Kunchong
    TIMER_ENCAPSULATED_PHEROMONES   = 4 * IN_MILLISECONDS,

    // Kor'thik Warcaller
    TIMER_ENRAGE_FIRST              = 4 * IN_MILLISECONDS,
    TIMER_ENRAGE                    = 10 * IN_MILLISECONDS,

    // Zar'thik Amber Priest
    TIMER_MANTID_SWARM_FIRST        = 8 * IN_MILLISECONDS,
    TIMER_MANTID_SWARM              = 35 * IN_MILLISECONDS,
    TIMER_RESIDUE_FIRST             = 5 * IN_MILLISECONDS,
    TIMER_RESIDUE                   = 18 * IN_MILLISECONDS,

    // Set'thik Wind Wielder
    TIMER_RAGE_OF_THE_EMPRESS_FIRST = 3 * IN_MILLISECONDS,
    TIMER_RAGE_OF_THE_EMPRESS       = 18 * IN_MILLISECONDS,
    TIMER_WINDSTORM_FIRST           = 6 * IN_MILLISECONDS,
    TIMER_WINDSTORM                 = 34 * IN_MILLISECONDS,
    TUNER_WINDSTORM_DMG_DELAY       = 2 * IN_MILLISECONDS,

    // Mantid Commander
    TIMER_SET_TO_BLOW_FIRST         = 5 * IN_MILLISECONDS,
    TIMER_SET_TO_BLOW               = 28 * IN_MILLISECONDS,
    TIMER_SET_TO_BLOW_EXPLODE       = 3 * IN_MILLISECONDS,
    TIMER_PHEROMONE_CLOUD           = 5 * IN_MILLISECONDS,

    // Ancient Brewmaster Spirit
    TIMER_KEG_TOSS_FIRST            = 5 * IN_MILLISECONDS,
    TIMER_KEG_TOSS                  = 10 * IN_MILLISECONDS,
    TIMER_BREATH_OF_FIRE_FIRST      = 9 * IN_MILLISECONDS,
    TIMER_BREATH_OF_FIRE            = 18 * IN_MILLISECONDS,

    // Wise Mistweaver Spirit
    TIMER_GUSTING_CRANE_KICK_FIRST  = 8 * IN_MILLISECONDS,
    TIMER_GUSTING_CRANE_KICK        = 25 * IN_MILLISECONDS,

    // Nameless Windwalker Spirit
    TIMER_PATH_OF_BLOSSOMS_FIRST    = 8 * IN_MILLISECONDS,
    TIMER_PATH_OF_BLOSSOMS          = 25 * IN_MILLISECONDS,
    TIMER_PATH_OF_BLOSSOMS_EXPLODE  = 2 * IN_MILLISECONDS,
};

enum eDatas
{
    DATA_MATTER_SCRAMBLE_COUNT  = 1,
    DATA_MATTER_SCRAMBLE_GUID
};

enum Phases
{
    PHASE_ONE,
    PHASE_TWO,
};

enum SpoilsOfPandariaRooms : int
{
    ROOM_NONE   = -1, // no room
    ROOM_NORTH  = 0, // north
    ROOM_WEST   = 1,  // west
    ROOM_SOUTH  = 2, // south
    ROOM_EAST   = 3,  // east

    MAX_ROOMS   = 4
};

enum SpoilsOfPandariaCrates : int
{
    CRATE_NONE                  = -1,
    CRATE_LIGHTWEIGHT_MOGU      = 0,
    CRATE_STOUT_MOGU            = 1,
    CRATE_MASSIVE_MOGU          = 2,
    CRATE_LIGHTWEIGHT_MANTID    = 3,
    CRATE_STOUT_MANTID          = 4,
    CRATE_MASSIVE_MANTID        = 5,
    CRATE_PANDAREN              = 6,
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

/*class RoomChecker
{
    public:

        static SimplePoints m_RoomPoints[MAX_ROOMS];

        static bool IsInAnyRoom(WorldObject const* object)
        {
            // don't use 'IsInRoom', make it faster
            if (object->GetPositionX() >= POSITION_X_MIN && object->GetPositionX() <= POSITION_X_MAX &&
                object->GetPositionY() >= POSITION_Y_MIN && object->GetPositionY() <= POSITION_Y_MAX &&
                object->GetPositionZ() >= POSITION_Z_MIN && object->GetPositionZ() <= POSITION_Z_MAX)
            {
                return true;
            }
            return false;
        }

        static bool IsInRoom(WorldObject const* object, SpoilsOfPandariaRooms room)
        {
            if (!IsInAnyRoom(object))
            {
                return false;
            }

            SimplePoint point(object->GetPositionX(), object->GetPositionY());
            bool result = IsSimplePointInZone(point, m_RoomPoints[room]);
            return result;
        }

        static void InitializeRoomPoints()
        {
            m_RoomPoints[ROOM_NORTH].clear();
            m_RoomPoints[ROOM_WEST].clear();
            m_RoomPoints[ROOM_SOUTH].clear();
            m_RoomPoints[ROOM_EAST].clear();

            m_RoomPoints[ROOM_NORTH].reserve(ROOM_POSITIONS_NORTH_MAX);
            m_RoomPoints[ROOM_WEST].reserve(ROOM_POSITIONS_WEST_MAX);
            m_RoomPoints[ROOM_SOUTH].reserve(ROOM_POSITIONS_SOUTH_MAX);
            m_RoomPoints[ROOM_EAST].reserve(ROOM_POSITIONS_EAST_MAX);

            for (auto& pos : northRoomPos)
                m_RoomPoints[ROOM_NORTH].push_back(SimplePoint(pos.GetPositionX(), pos.GetPositionY()));

            for (auto& pos : westRoomPos)
                m_RoomPoints[ROOM_WEST].push_back(SimplePoint(pos.GetPositionX(), pos.GetPositionY()));

            for (auto& pos : southRoomPos)
                m_RoomPoints[ROOM_SOUTH].push_back(SimplePoint(pos.GetPositionX(), pos.GetPositionY()));

            for (auto& pos : eastRoomPos)
                m_RoomPoints[ROOM_EAST].push_back(SimplePoint(pos.GetPositionX(), pos.GetPositionY()));
        }
};

SimplePoints RoomChecker::m_RoomPoints[MAX_ROOMS];*/

const Position spoilsOfPandariaPosition = { 1631.799f, -5125.967f, -271.027f, 5.315065f };

class RoomChecker
{
    public:

        static bool IsObjectInAnyRoom(WorldObject const* object)
        {
            if (object->GetPositionX() >= POSITION_X_MIN && object->GetPositionX() <= POSITION_X_MAX &&
                object->GetPositionY() >= POSITION_Y_MIN && object->GetPositionY() <= POSITION_Y_MAX &&
                object->GetPositionZ() >= POSITION_Z_MIN && object->GetPositionZ() <= POSITION_Z_MAX)
            {
                return true;
            }

            return false;
        }

        static bool IsObjectInRoom(WorldObject const* object, SpoilsOfPandariaRooms room)
        {
            if (!IsObjectInAnyRoom(object))
            {
                return false;
            }

            if (GetRoomForObject(object) != room)
                return false;

            return true;
        }

        static SpoilsOfPandariaRooms GetRoomForObject(WorldObject const* object)
        {
            if (object->GetPositionZ() < POSITION_Z_MIN || object->GetPositionZ() > POSITION_Z_MAX)
                return SpoilsOfPandariaRooms::ROOM_NONE;

            if (object->GetDistance2d(spoilsOfPandariaPosition.GetPositionX(), spoilsOfPandariaPosition.GetPositionY()) >= 150.0f)
                return SpoilsOfPandariaRooms::ROOM_NONE;

            float angle = object->GetAngle(&spoilsOfPandariaPosition);

            if (angle >= 0.6f && angle < 2.17f)
            {
                return SpoilsOfPandariaRooms::ROOM_EAST;
            }
            else if (angle >= 2.17f && angle < 3.74f)
            {
                return SpoilsOfPandariaRooms::ROOM_NORTH;
            }
            else if (angle >= 3.74f && angle < 5.31f)
            {
                return SpoilsOfPandariaRooms::ROOM_WEST;
            }
            else if (angle >= 5.31f || angle < 0.6f)
            {
                return SpoilsOfPandariaRooms::ROOM_SOUTH;
            }

            return SpoilsOfPandariaRooms::ROOM_NONE;
        }
};

class RoomsController
{
    private:

        class CratesCheck
        {
            public:
                CratesCheck() {}
                bool operator() (GameObject* go)
                {
                    if (!IsCrateEntry(go->GetEntry()))
                        return false;
                    return true;
                }
        };

    public:

        RoomsController(Creature* owner) : m_Owner(owner),
            m_Map(owner->GetMap()),
            pInstance(owner->GetInstanceScript())
        {
            memset(m_RoomOpened, 0, sizeof(m_RoomOpened));
        }

        void InitializeCrates()
        {
            cratesGUIDs[0].clear();
            cratesGUIDs[1].clear();
            cratesGUIDs[2].clear();
            cratesGUIDs[3].clear();

            std::list<GameObject*> cratesList;
            GetCratesList(cratesList);

            for (GameObject* pCrate : cratesList)
            {
                if (!IsCrateEntry(pCrate->GetEntry()))
                    continue;

                switch (RoomChecker::GetRoomForObject(pCrate))
                {
                    case SpoilsOfPandariaRooms::ROOM_NORTH: cratesGUIDs[0].insert(pCrate->GetGUID()); break;
                    case SpoilsOfPandariaRooms::ROOM_WEST: cratesGUIDs[1].insert(pCrate->GetGUID()); break;
                    case SpoilsOfPandariaRooms::ROOM_SOUTH: cratesGUIDs[2].insert(pCrate->GetGUID()); break;
                    case SpoilsOfPandariaRooms::ROOM_EAST: cratesGUIDs[3].insert(pCrate->GetGUID()); break;
                }
            }
        }

        void OpenFirstDoors()
        {
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_NORTH);
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_SOUTH);

            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_NORTH, true);
            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_SOUTH, true);

            m_RoomOpened[ROOM_NORTH] = true;
            m_RoomOpened[ROOM_SOUTH] = true;
        }

        void OpenSecondDoors()
        {
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_WEST);
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_NORTH_WEST);
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_EAST);
            OpenDoor(DATA_SPOILS_OF_PANDARIA_GATE_SOUTH_EAST);

            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_EAST, true);
            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_WEST, true);

            m_RoomOpened[ROOM_WEST] = true;
            m_RoomOpened[ROOM_EAST] = true;
        }

        void CloseAllDoors()
        {
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_NORTH);
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_WEST);
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_SOUTH);
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_EAST);
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_NORTH_WEST);
            CloseDoor(DATA_SPOILS_OF_PANDARIA_GATE_SOUTH_EAST);

            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_NORTH, false);
            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_WEST, false);
            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_SOUTH, false);
            EnableCratesInRoom(SpoilsOfPandariaRooms::ROOM_EAST, false);

            m_RoomOpened[ROOM_NORTH] = false;
            m_RoomOpened[ROOM_WEST] = false;
            m_RoomOpened[ROOM_SOUTH] = false;
            m_RoomOpened[ROOM_EAST] = false;
        }

        bool IsRoomOpened(SpoilsOfPandariaRooms room) const
        {
            return m_RoomOpened[(int)room];
        }

    private:

        void OpenDoor(uint32 type)
        {
            if (GameObject* pGo = GetGameObject(type))
                pGo->SetGoState(GO_STATE_ACTIVE);
        }

        void CloseDoor(uint32 type)
        {
            if (GameObject* pGo = GetGameObject(type))
                pGo->SetGoState(GO_STATE_READY);
        }

        void EnableCratesInRoom(SpoilsOfPandariaRooms room, bool enable)
        {
            std::set<ObjectGuid>* cratesList = GetGUIDsListForRoom(room);
            if (cratesList == nullptr)
                return;

            for (std::set<ObjectGuid>::const_iterator guidItr = cratesList->begin(); guidItr != cratesList->end(); ++guidItr)
            {
                GameObject* pGo = m_Map->GetGameObject(*guidItr);
                if (!pGo)
                    continue;

                if (enable)
                {
                    m_Owner->CastSpell(pGo, SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_1, true);

                    pGo->RemoveFlag(GO_FLAG_INTERACT_COND);
                }
                else
                {
                    pGo->SetFlags(GO_FLAG_INTERACT_COND);

                    // Reset state
                    pGo->SetLootState(GO_JUST_DEACTIVATED);
                    pGo->RemoveFlag(GO_FLAG_IN_USE);
                    pGo->SetGoState(GO_STATE_READY);
                }
            }
        }

        std::set<ObjectGuid>* GetGUIDsListForRoom(SpoilsOfPandariaRooms room)
        {
            switch (room)
            {
                case SpoilsOfPandariaRooms::ROOM_NORTH: return &cratesGUIDs[0]; break;
                case SpoilsOfPandariaRooms::ROOM_WEST: return &cratesGUIDs[1]; break;
                case SpoilsOfPandariaRooms::ROOM_SOUTH: return &cratesGUIDs[2]; break;
                case SpoilsOfPandariaRooms::ROOM_EAST: return &cratesGUIDs[3]; break;
            }

            return nullptr;
        }

        GameObject* GetGameObject(uint32 type)
        {
            if (pInstance)
            {
                return pInstance->instance->GetGameObject(pInstance->GetObjectGuid(type));
            }

            return nullptr;
        }

        void GetCratesList(std::list<GameObject*>& gameObjects)
        {
            CellCoord pair(Trinity::ComputeCellCoord(m_Owner->GetPositionX(), m_Owner->GetPositionY()));
            Cell cell(pair);
            cell.SetNoCreate();

            CratesCheck check;
            Trinity::GameObjectListSearcher<CratesCheck> searcher(m_Owner, gameObjects, check);
            TypeContainerVisitor<Trinity::GameObjectListSearcher<CratesCheck>, GridTypeMapContainer> visitor(searcher);

            cell.Visit(pair, visitor, *(m_Owner->GetMap()), *m_Owner, 200.0f);
        }

    private:
        Creature* m_Owner;
        Map* m_Map;
        InstanceScript* pInstance;
        bool m_RoomOpened[MAX_ROOMS];
        std::set<ObjectGuid> cratesGUIDs[MAX_ROOMS];
};

class FramesController
{
    public:

        FramesController(Creature* owner) :
            m_Owner(owner), pInstance(owner->GetInstanceScript())
        {
            Reset();
        }

        void Reset()
        {
            memset(m_SpoilsFrameGuids, 0, sizeof(m_SpoilsFrameGuids));
            memset(m_SpoilsEnergy, 0, sizeof(m_SpoilsEnergy));
            memset(m_SpoilsDummyGuids, 0, sizeof(m_SpoilsDummyGuids));
            memset(m_UsedLevers, 0, sizeof(m_UsedLevers));
            m_IsSpoilsSpawned = false;
        }

        void StartFirstRooms()
        {
            SpawnSpoilsFrames();

            EnableFirstFrames(true);
        }

        void StartSecondRooms()
        {
            SpawnSpoilsFrames();

            EnableFirstFrames(false);
            EnableSecondFrames(true);
        }

        void End()
        {
            EnableFirstFrames(false);
            EnableSecondFrames(false);
            DespawnAll();
            Reset();
        }

        void EnergyIncreased(SpoilsOfPandariaRooms room, int32 energy)
        {
            IncreaseEnergy(room, energy);
        }

        bool IsFirstRoomsDone() const
        {
            return m_SpoilsEnergy[(int)ROOM_NORTH] >= MAX_ENERGY &&
                m_SpoilsEnergy[(int)ROOM_SOUTH] >= MAX_ENERGY;
        }

        bool IsSecondRoomsDone() const
        {
            return m_SpoilsEnergy[(int)ROOM_WEST] >= MAX_ENERGY &&
                m_SpoilsEnergy[(int)ROOM_EAST] >= MAX_ENERGY;
        }

        void UseLever(SpoilsOfPandariaRooms room)
        {
            if (!CanActivateLever(room))
                return;

            m_UsedLevers[(int)room] = true;

            EnableRedBeamAtSpoilsDummy(room, false);

            if (IsFirstRoom(room))
            {
                if (IsAllFirstLeversActivated())
                {
                    m_Owner->AI()->DoAction(ACTION_START_SECOND_PART);
                }
                else
                {
                    m_Owner->AI()->DoAction(ACTION_FIRST_MODULE_ACTIVATED);
                }
            }
            else if (IsSecondRoom(room))
            {
                if (IsAllSecondLeversActivated())
                {
                    m_Owner->AI()->DoAction(ACTION_COMPLETE_ENCOUNTER);
                }
                else
                {
                    m_Owner->AI()->DoAction(ACTION_SECOND_MODULE_ACTIVATED);
                }
            }
        }

    private:

        void SpawnSpoilsFrames()
        {
            if (m_IsSpoilsSpawned)
                return;

            if (Creature* pSpoil = m_Owner->SummonCreature(NPC_MANTID_SPOILS_1, *m_Owner))
            {
                pSpoil->AddAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2, pSpoil);
                m_SpoilsFrameGuids[ROOM_NORTH] = pSpoil->GetGUID();
            }

            if (Creature* pSpoil = m_Owner->SummonCreature(NPC_MOGU_SPOILS_1, *m_Owner))
            {
                pSpoil->AddAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2, pSpoil);
                m_SpoilsFrameGuids[ROOM_SOUTH] = pSpoil->GetGUID();
            }

            if (Creature* pSpoil = m_Owner->SummonCreature(NPC_MANTID_SPOILS_2, *m_Owner))
            {
                pSpoil->AddAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2, pSpoil);
                m_SpoilsFrameGuids[ROOM_WEST] = pSpoil->GetGUID();
            }

            if (Creature* pSpoil = m_Owner->SummonCreature(NPC_MOGU_SPOILS_2, *m_Owner))
            {
                pSpoil->AddAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_POWER_2, pSpoil);
                m_SpoilsFrameGuids[ROOM_EAST] = pSpoil->GetGUID();
            }

            SpawnSpoilsDummy();

            m_IsSpoilsSpawned = true;
        }

        void SpawnSpoilsDummy()
        {
            for (uint8 i = 0; i < MAX_ROOMS; ++i)
            {
                if (GameObject* pLever = GetLeverForRoom(m_Owner, (SpoilsOfPandariaRooms)i))
                {
                    if (Creature* pDummy = m_Owner->SummonCreature(NPC_SPOILS_OF_PANDARIA, *pLever))
                        m_SpoilsDummyGuids[i] = pDummy->GetGUID();
                }
            }
        }

        void DespawnAll()
        {
            for (uint8 i = 0; i < MAX_ROOMS; ++i)
            {
                if (m_SpoilsFrameGuids[i] != ObjectGuid::Empty)
                {
                    if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[i]))
                        pSpoil->DespawnOrUnsummon();

                    m_SpoilsFrameGuids[i] = ObjectGuid::Empty;
                }

                if (m_SpoilsDummyGuids[i] != ObjectGuid::Empty)
                {
                    if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsDummyGuids[i]))
                        pSpoil->DespawnOrUnsummon();

                    m_SpoilsDummyGuids[i] = ObjectGuid::Empty;
                }
            }

            m_IsSpoilsSpawned = false;
        }

        void EnableFirstFrames(bool enable)
        {
            if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[ROOM_NORTH]))
                pInstance->SendEncounterUnit(enable ? ENCOUNTER_FRAME_ENGAGE : ENCOUNTER_FRAME_DISENGAGE, pSpoil);

            if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[ROOM_SOUTH]))
                pInstance->SendEncounterUnit(enable ? ENCOUNTER_FRAME_ENGAGE : ENCOUNTER_FRAME_DISENGAGE, pSpoil);
        }

        void EnableSecondFrames(bool enable)
        {
            if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[ROOM_WEST]))
                pInstance->SendEncounterUnit(enable ? ENCOUNTER_FRAME_ENGAGE : ENCOUNTER_FRAME_DISENGAGE, pSpoil);

            if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[ROOM_EAST]))
                pInstance->SendEncounterUnit(enable ? ENCOUNTER_FRAME_ENGAGE : ENCOUNTER_FRAME_DISENGAGE, pSpoil);
        }

        void IncreaseEnergy(SpoilsOfPandariaRooms room, int32 energy)
        {
            uint32& currentEnergy = m_SpoilsEnergy[(int)room];

            if (currentEnergy >= MAX_ENERGY)
                return;

            currentEnergy += energy;

            UpdateSpoilsEnergy();

            if (currentEnergy >= MAX_ENERGY)
            {
                EnableRedBeamAtSpoilsDummy(room, true);
            }
        }

        void UpdateSpoilsEnergy()
        {
            if (!pInstance)
                return;

            for (uint8 i = 0; i < MAX_ROOMS; ++i)
            {
                if (m_SpoilsFrameGuids[i] == ObjectGuid::Empty)
                    continue;

                if (Creature* pSpoil = pInstance->instance->GetCreature(m_SpoilsFrameGuids[i]))
                {
                    pSpoil->SetPower(POWER_ALTERNATE_POWER, m_SpoilsEnergy[i]);
                }
            }
        }

        void EnableRedBeamAtSpoilsDummy(SpoilsOfPandariaRooms room, bool enable)
        {
            if (!pInstance)
                return;

            Creature* pSpoilsDummy = pInstance->instance->GetCreature(m_SpoilsDummyGuids[(int)room]);
            if (!pSpoilsDummy)
                return;

            if (enable)
            {
                pSpoilsDummy->CastSpell(pSpoilsDummy, SPELL_UNSTABLE_DEFENCE_SYSTEMS_AURA_3, true);
            }
            else
            {
                pSpoilsDummy->RemoveAura(SPELL_UNSTABLE_DEFENCE_SYSTEMS_AURA_3);
            }
        }

        bool CanActivateLever(SpoilsOfPandariaRooms room) const
        {
            return m_UsedLevers[(int)room] == false &&
                m_SpoilsEnergy[(int)room] >= MAX_ENERGY;
        }

        bool IsAllFirstLeversActivated()
        {
            return m_UsedLevers[ROOM_NORTH] == true && m_UsedLevers[ROOM_SOUTH] == true;
        }

        bool IsAllSecondLeversActivated()
        {
            return m_UsedLevers[ROOM_WEST] == true && m_UsedLevers[ROOM_EAST] == true;
        }

    private:

        bool m_IsSpoilsSpawned;
        Creature* m_Owner;
        InstanceScript* pInstance;
        ObjectGuid m_SpoilsFrameGuids[MAX_ROOMS];  // npcs those are showed with frames
        uint32 m_SpoilsEnergy[MAX_ROOMS];      // energy of each spoil
        ObjectGuid m_SpoilsDummyGuids[MAX_ROOMS]; // npcs those are spawned at levers' locations and cast red beams on self
        bool m_UsedLevers[MAX_ROOMS];
};

class BerserkController
{
    public:

        BerserkController(Creature* owner) : m_Owner(owner), m_Instance(owner->GetInstanceScript()) { }

        void Activate()
        {
            m_IsActive = true;
            m_BerserkTimer = TIMER_BERSERK;
            m_UpdateWorldStateTimer = TIMER_UPDATE_WORLD_STATE;

            UpdateWorldStateForAll();
        }

        void Deactivate()
        {
            m_IsActive = false;

            UpdateWorldStateForAll();
        }

        void Update(const uint32 diff)
        {
            if (!m_IsActive)
                return;

            if (m_BerserkTimer <= diff)
            {
                m_BerserkTimer = TIMER_BERSERK;

                m_IsActive = false;

                m_Owner->AI()->Talk(SAY_OUT_OF_TIME);
                m_Owner->CastSpell(m_Owner, SPELL_GB_11010, true);
                m_Owner->AI()->DoAction(ACTION_RESET_ENCOUNTER);
            }
            else
            {
                m_BerserkTimer -= diff;
            }

            if (m_UpdateWorldStateTimer <= diff)
            {
                m_UpdateWorldStateTimer = TIMER_UPDATE_WORLD_STATE;

                UpdateWorldStateForAll();
            }
            else
            {
                m_UpdateWorldStateTimer -= diff;
            }
        }

    private:

        void UpdateWorldStateForPlayer(Player* player)
        {
            if (m_IsActive)
            {
                uint32 secondsLeft = m_BerserkTimer / IN_MILLISECONDS;
                player->SendUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER, secondsLeft);
                player->SendUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER_VISUAL, 1);
            }
            else
            {
                player->SendUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER, 0);
                player->SendUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER_VISUAL, 0);
            }
        }

        void UpdateWorldStateForAll()
        {
            if (!m_Instance)
                return;

            if (m_IsActive)
            {
                uint32 secondsLeft = m_BerserkTimer / IN_MILLISECONDS;
                m_Instance->DoUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER, secondsLeft);
                m_Instance->DoUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER_VISUAL, 1);
            }
            else
            {
                m_Instance->DoUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER, 0);
                m_Instance->DoUpdateWorldState(WORLDSTATE_SPOILS_OF_PANDARIA_TIMER_VISUAL, 0);
            }
        }

    private:

        Creature* m_Owner;
        InstanceScript* m_Instance;
        uint32 m_BerserkTimer;
        uint32 m_UpdateWorldStateTimer;
        bool m_IsActive;
};

class PlayerInRoomTargetCheck : public std::unary_function<Unit*, bool>
{
    public:

        explicit PlayerInRoomTargetCheck(Unit* attacker, float distance, SpoilsOfPandariaRooms room, Unit* p_SkipTarget = nullptr) :
            m_Attacker(attacker), m_Distance(distance), m_Room(room), m_SkipTarget(p_SkipTarget) { }

        bool operator()(Unit const* target) const
        {
            if (m_SkipTarget && m_SkipTarget == target)
                return false;

            if (!target->IsInCombat())
                return false;

            if (!target->IsPlayer())
                return false;

            if (m_Distance > 0.0f && !m_Attacker->IsWithinCombatRange(target, m_Distance))
                return false;

            if (m_Distance < 0.0f && m_Attacker->IsWithinCombatRange(target, -m_Distance))
                return false;

            if (!RoomChecker::IsObjectInRoom(target, m_Room))
                return false;

            return true;
        }

    private:
        Unit* m_Attacker;
        SpoilsOfPandariaRooms m_Room;
        float m_Distance;
        Unit* m_SkipTarget;
};

class SpellPathWorker
{
    public:

        SpellPathWorker(Creature* p_Owner) : m_Owner(p_Owner) { }

        void SpawnSpellPathFor(Unit* p_Target, uint32 p_SpellId)
        {
            if (m_SpawnPathEnabled)
                return;

            float l_MaxDistance = m_Owner->GetDistance(p_Target);
            float l_Angle = m_Owner->GetAngle(p_Target);

            for (float l_Dist = 0.f; l_Dist <= l_MaxDistance; l_Dist += 2.5f)
            {
                Position l_Pos;
                l_Pos.m_positionX = m_Owner->GetPositionX() + (m_Owner->GetObjectSize() + l_Dist) * std::cos(l_Angle);
                l_Pos.m_positionY = m_Owner->GetPositionY() + (m_Owner->GetObjectSize() + l_Dist) * std::sin(l_Angle);
                l_Pos.m_positionZ = m_Owner->GetPositionZ();

                m_PathPositions.push(l_Pos);
            }

            m_SpawnPathTimer = 100;
            m_SpawnPathEnabled = true;
            m_SpellId = p_SpellId;
        }

        void UpdateSpellPath(uint32 p_Diff)
        {
            if (!m_SpawnPathEnabled)
                return;

            if (m_PathPositions.empty())
            {
                m_SpawnPathEnabled = false;
                return;
            }

            if (m_SpawnPathTimer <= p_Diff)
            {
                m_SpawnPathTimer = 100;

                Position l_Pos = m_PathPositions.front();

                m_Owner->CastSpell(l_Pos, m_SpellId, true);

                m_PathPositions.pop();
            }
            else
            {
                m_SpawnPathTimer -= p_Diff;
            }
        }

    private:

        Creature* m_Owner;
        uint32 m_SpawnPathTimer = 100;
        std::queue<Position> m_PathPositions;
        bool m_SpawnPathEnabled = false;
        uint32 m_SpellId;
};

class npc_secured_stockpile_of_pandaren_spoils : public CreatureScript
{
    public:
        npc_secured_stockpile_of_pandaren_spoils() : CreatureScript("npc_secured_stockpile_of_pandaren_spoils") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_secured_stockpile_of_pandaren_spoilsAI(creature);
        }

        struct npc_secured_stockpile_of_pandaren_spoilsAI : public Scripted_NoMovementAI
        {
            npc_secured_stockpile_of_pandaren_spoilsAI(Creature* creature) : Scripted_NoMovementAI(creature),
                m_RoomsController(creature), m_FramesController(creature), m_BerserkController(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                m_EvadeTimer = TIMER_CHECK_EVADE;
                m_Phase = PHASE_ONE;

                pInstance = me->GetInstanceScript();
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_START_ENCOUNTER:
                        StartEncounter();
                        break;
                    case ACTION_RESET_ENCOUNTER:
                        ResetEncounter();
                        break;
                    case ACTION_START_SECOND_PART:
                        StartSecondPhase();
                        break;
                    case ACTION_COMPLETE_ENCOUNTER:
                        CompleteEncounter();
                        break;
                    case ACTION_FIRST_MODULE_ACTIVATED:
                        Talk(SAY_MODULE_1_50);
                        break;
                    case ACTION_SECOND_MODULE_ACTIVATED:
                        Talk(SAY_MODULE_2_50);
                        break;
                    case ACTION_USED_LEVER_NORTH:
                        HandleLeverUsed(SpoilsOfPandariaRooms::ROOM_NORTH);
                        break;
                    case ACTION_USED_LEVER_WEST:
                        HandleLeverUsed(SpoilsOfPandariaRooms::ROOM_WEST);
                        break;
                    case ACTION_USED_LEVER_SOUTH:
                        HandleLeverUsed(SpoilsOfPandariaRooms::ROOM_SOUTH);
                        break;
                    case ACTION_USED_LEVER_EAST:
                        HandleLeverUsed(SpoilsOfPandariaRooms::ROOM_EAST);
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_LIGHTWEIGHT_DIED)
                {
                    m_FramesController.EnergyIncreased((SpoilsOfPandariaRooms)data, LIGHTWEIGHT_MOB_ENERGY);
                }
                else if (type == DATA_STOUT_DIED)
                {
                    m_FramesController.EnergyIncreased((SpoilsOfPandariaRooms)data, STOUT_MOB_ENERGY);
                }
                else if (type == DATA_MASSIVE_DIED)
                {
                    m_FramesController.EnergyIncreased((SpoilsOfPandariaRooms)data, MASSIVE_MOB_ENERGY);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ROOM_STATE_NORTH: return (uint32)m_RoomsController.IsRoomOpened(SpoilsOfPandariaRooms::ROOM_NORTH);
                    case DATA_ROOM_STATE_WEST: return (uint32)m_RoomsController.IsRoomOpened(SpoilsOfPandariaRooms::ROOM_WEST);
                    case DATA_ROOM_STATE_SOUTH: return (uint32)m_RoomsController.IsRoomOpened(SpoilsOfPandariaRooms::ROOM_SOUTH);
                    case DATA_ROOM_STATE_EAST: return (uint32)m_RoomsController.IsRoomOpened(SpoilsOfPandariaRooms::ROOM_EAST);
                }

                return 0;
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!IsInProgress(me))
                    return;

                CheckForEvade(diff);

                m_BerserkController.Update(diff);
            }

        private:

            void StartEncounter()
            {
                Talk(SAY_AGGRO);

                DoCast(me, SPELL_UNSTABLE_DEFENSE_SYSTEMS_AREATRIGGER_1, true);

                m_RoomsController.InitializeCrates();

                SpawnLiftHooks();

                StartFirstPhase();

                if (pInstance)
                    pInstance->SetBossState(DATA_SPOILS_OF_PANDARIA, IN_PROGRESS);

                DoZoneInCombat();
            }

            void StartFirstPhase()
            {
                m_Phase = PHASE_ONE;

                m_RoomsController.OpenFirstDoors();
                m_FramesController.StartFirstRooms();

                m_BerserkController.Activate();
            }

            void StartSecondPhase()
            {
                Talk(SAY_MODULE_1_100);

                m_Phase = PHASE_TWO;

                m_RoomsController.OpenSecondDoors();
                m_FramesController.StartSecondRooms();

                m_BerserkController.Activate();
            }

            void ResetEncounter()
            {
                Talk(SAY_WIPE);

                ClearEncouterState();

                if (pInstance)
                {
                    pInstance->SetBossState(DATA_SPOILS_OF_PANDARIA, NOT_STARTED);
                }
            }

            void CompleteEncounter()
            {
                Talk(SAY_COMPLETE_1);

                ClearEncouterState();

                if (pInstance)
                {
                    //pInstance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ACHIEVEMENT, me);
                   // pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT);
                    pInstance->DoModifyPlayerCurrencies(396, 4000);

                    pInstance->SetBossState(DATA_SPOILS_OF_PANDARIA, DONE);
                    //pInstance->DoPermBindPlayersForRaid();

                    SpawnLoot();
                }
            }

            void ClearEncouterState()
            {
                me->DespawnCreaturesInArea(Adds::NPC_STONE_STATUE, 200);

                if (pInstance)
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_CLAW_OF_BURNING_ANGER);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_STAFF_OF_RESONATING_WATER);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_BLADE_OF_THE_HUNDRED_STEPS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_GUSTING_BOMB_PERIODIC);
                }

                m_RoomsController.CloseAllDoors();
                m_FramesController.End();

                m_BerserkController.Deactivate();

                events.Reset();
                summons.DespawnAll();
                me->RemoveAllAreaTriggers();

                me->CombatStop();
                me->DeleteThreatList();
                me->getHostileRefManager().deleteReferences();

                m_EvadeTimer = TIMER_CHECK_EVADE;
                m_Phase = PHASE_ONE;
            }

            void SpawnLoot()
            {
                if (!pInstance)
                    return;

                switch (GetDifficulty())
                {
                    case DIFFICULTY_10_N:
                        pInstance->DoRespawnGameObject(pInstance->GetObjectGuid(DATA_UNLOCKED_STOCKPILE_10), DAY);
                        break;
                    case DIFFICULTY_25_N:
                        pInstance->DoRespawnGameObject(pInstance->GetObjectGuid(DATA_UNLOCKED_STOCKPILE_25), DAY);
                        break;
                    case DIFFICULTY_10_HC:
                        pInstance->DoRespawnGameObject(pInstance->GetObjectGuid(DATA_UNLOCKED_STOCKPILE_10H), DAY);
                        break;
                    case DIFFICULTY_25_HC:
                        pInstance->DoRespawnGameObject(pInstance->GetObjectGuid(DATA_UNLOCKED_STOCKPILE_25H), DAY);
                        break;
                }

                // Bonus loot roll there
                //CreatureBonusLootProcessor bonusLoot(me);
                //bonusLoot.SendBonusLootToPlayers();
            }

            void SpawnLiftHooks()
            {
                for (uint8 i = 0; i < LIFT_HOOK_COUNT; ++i)
                {
                    if (i % 2 == 0 && !Is25ManRaid())
                        continue;

                    if (Creature* pLiftHook = me->SummonCreature(NPC_LIFT_HOOK, liftHookPos[i]))
                        pLiftHook->AI()->SetData(DATA_LIFT_HOOK_ROOM, leftHookRoomSequence[i]);
                }
            }

            void CheckForEvade(const uint32 diff)
            {
                if (m_EvadeTimer <= diff)
                {
                    m_EvadeTimer = TIMER_CHECK_EVADE;

                    bool isAnyPlayerInRooms = IsAnyPlayerInRooms();

                    if (!isAnyPlayerInRooms)
                    {
                        ResetEncounter();
                    }
                }
                else
                {
                    m_EvadeTimer -= diff;
                }
            }

            bool IsAnyPlayerInRooms() const
            {
                if (!pInstance)
                    return false;

                Map::PlayerList const& players = pInstance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itrPlayer = players.begin(); itrPlayer != players.end(); ++itrPlayer)
                {
                    Player* player = itrPlayer->GetSource();
                    if (player->IsGameMaster())
                        continue;

                    if (RoomChecker::IsObjectInAnyRoom(player))
                        return true;
                }

                return false;
            }

            void HandleLeverUsed(SpoilsOfPandariaRooms room)
            {
                m_FramesController.UseLever(room);
            }

        private:

            RoomsController m_RoomsController;
            FramesController m_FramesController;
            BerserkController m_BerserkController;
            InstanceScript* pInstance;

            uint32 m_EvadeTimer;
            Phases m_Phase;

        };
};

class npc_spoils_of_pandaria_lift_hook : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_lift_hook() : CreatureScript("npc_spoils_of_pandaria_lift_hook") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_lift_hookAI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            // prevent from gossip menu
            return true;
        }

        struct npc_spoils_of_pandaria_lift_hookAI : public Scripted_NoMovementAI
        {
            npc_spoils_of_pandaria_lift_hookAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->setActive(true);

                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));

                m_IsReady = true;
                m_CooldownTimer = TIMER_LIFT_HOOK_COOLDOWN;
                m_Room = SpoilsOfPandariaRooms::ROOM_NONE;

                pInstance = me->GetInstanceScript();
            }

            void Reset() override
            {
                me->AddAura(SPELL_LIFT_HOOK, me);
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_LIFT_HOOK_ROOM)
                {
                    m_Room = (SpoilsOfPandariaRooms)data;
                }
            }

            void sGossipHello(Player* player) override
            {
                if (!IsReady())
                    return;

                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));

                m_IsReady = false;
                m_CooldownTimer = TIMER_LIFT_HOOK_COOLDOWN;

                if (m_Room != SpoilsOfPandariaRooms::ROOM_NONE)
                {
                    player->NearTeleportTo(liftEndPos[(int)m_Room]);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                UpdateCooldown(diff);
            }

        private:

            bool IsReady() const { return m_IsReady; }

            void UpdateCooldown(const uint32 diff)
            {
                if (IsReady())
                    return;

                if (m_CooldownTimer <= diff)
                {
                    m_IsReady = true;
                    m_CooldownTimer = TIMER_LIFT_HOOK_COOLDOWN;
                    me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                }
                else
                {
                    m_CooldownTimer -= diff;
                }

            }

        private:

            InstanceScript* pInstance;
            bool m_IsReady;
            uint32 m_CooldownTimer;
            SpoilsOfPandariaRooms m_Room;
        };
};

class npc_spoils_of_pandaria_unstable_spark : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_unstable_spark() : CreatureScript("npc_spoils_of_pandaria_unstable_spark") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_unstable_sparkAI(creature);
        }

        struct npc_spoils_of_pandaria_unstable_sparkAI : public Scripted_NoMovementAI
        {
            npc_spoils_of_pandaria_unstable_sparkAI(Creature* creature) : Scripted_NoMovementAI(creature),
                m_CastTimer(1000), m_IsCastingSupernova(false)
            {
                me->SetReactState(REACT_PASSIVE);

                //ApplyAllImmunities(true);
            }

            void Reset()
            {
                DoCast(me, SPELL_UNSTABLE_SPARK_VISUAL, true);
            }

            void IsSummonedBy(Unit* owner) override
            {

                DoCast(me, SPELL_SUPERNOVA);
            }

            void JustDied(Unit* who) override
            {
                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff)
            {
                UpdateCastingSupernova(diff);
            }

        private:

            void UpdateCastingSupernova(const uint32 diff)
            {
                if (m_IsCastingSupernova)
                    return;

                if (m_CastTimer <= diff)
                {
                    m_CastTimer = 1000;
                    m_IsCastingSupernova = true;

                    DoCast(me, SPELL_SUPERNOVA);
                }
                else
                {
                    m_CastTimer -= diff;
                }
            }

        private:

            uint32 m_CastTimer;
            bool m_IsCastingSupernova;

        };
};


struct npc_spoils_of_pandaria_mobAI : public ScriptedAI
{
    public:

        npc_spoils_of_pandaria_mobAI(Creature* creature) : ScriptedAI(creature),
            m_AggroTimer(TIMER_MOB_AGGRO), m_AggroDone(false)
        {
            //ApplyAllImmunities(true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);

            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();

            m_AggroTimer = TIMER_MOB_AGGRO;
            m_AggroDone = false;
        }

        bool CanAIAttack(Unit const* l_Target) const override
        {
            if (!RoomChecker::IsObjectInRoom(l_Target, GetRoom()))
                return false;

            return true;
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (me->IsInCombat())
                DoZoneInCombat(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_MOB_ROOM)
            {
                m_Room = (SpoilsOfPandariaRooms)data;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_MOB_ROOM)
                return (uint32)m_Room;

            return 0;
        }

        void JustDied(Unit* who) override
        {
            events.Reset();
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();

            if (CanIncreaseEnergy())
            {
                SendRayToLever();
                IncreaseEnergy();

                // spawn unstable spark after 'summons.DespawnAll'
                if (IsHeroic())
                    SendUnstableSpark();
            }

            me->DespawnOrUnsummon(10000);
        }

    protected:

        void UpdateAggroState(const uint32 diff)
        {
            if (m_AggroDone)
                return;

            if (m_AggroTimer <= diff)
            {
                m_AggroTimer = TIMER_MOB_AGGRO;
                m_AggroDone = true;

                me->SetReactState(REACT_AGGRESSIVE);
                DoAggro();
            }
            else
            {
                m_AggroTimer -= diff;
            }
        }

        SpoilsOfPandariaRooms GetRoom() const
        {
            return m_Room;
        }

        void GetPlayersInRoom(std::list<Player*>& p_Players)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        if (RoomChecker::IsObjectInRoom(player, GetRoom()))
                            p_Players.push_back(player);
        }

        void GetPlayersInRoomWithRoles(std::list<Player*>& p_Players, std::set<Roles> const& p_Roles)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                {
                    if (Player* player = i->GetSource())
                    {
                        if (p_Roles.find((Roles)player->GetRoleForGroup()) != p_Roles.end() && RoomChecker::IsObjectInRoom(player, GetRoom()))
                            p_Players.push_back(player);
                    }
                }
        }

        virtual void DoAggro() { }

        virtual bool CanIncreaseEnergy() const { return true; }

    private:

        void IncreaseEnergy()
        {
            if (Creature* pSpoils = GetSpoilsOfPandaria(me))
            {
                SpoilsOfPandariaCrates crateType = GetCrateTypeForMobEntry(me->GetEntry());
                SpoilsOfPandariaRooms room = GetRoom();
                switch (crateType)
                {
                    case SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MOGU:
                    case SpoilsOfPandariaCrates::CRATE_LIGHTWEIGHT_MANTID:
                        pSpoils->AI()->SetData(DATA_LIGHTWEIGHT_DIED, (int)room);
                        break;
                    case SpoilsOfPandariaCrates::CRATE_STOUT_MOGU:
                    case SpoilsOfPandariaCrates::CRATE_STOUT_MANTID:
                        pSpoils->AI()->SetData(DATA_STOUT_DIED, (int)room);
                        break;
                    case SpoilsOfPandariaCrates::CRATE_MASSIVE_MOGU:
                    case SpoilsOfPandariaCrates::CRATE_MASSIVE_MANTID:
                        pSpoils->AI()->SetData(DATA_MASSIVE_DIED, (int)room);
                        break;
                }
            }
        }

        void SendRayToLever()
        {
            if (GameObject* pLever = GetLeverForRoom(me, GetRoom()))
            {
                me->CastSpell(pLever, SPELL_UNSTABLE_DEFENSE_SYSTEMS_RAY_2, true);
            }
        }

        void SendUnstableSpark()
        {
            SpoilsOfPandariaRooms otherRoom = GetOtherRoom(GetRoom());
            if (otherRoom == SpoilsOfPandariaRooms::ROOM_NONE)
                return;

            me->CastSpell(unstableSparkPos[otherRoom].GetPositionX(), unstableSparkPos[otherRoom].GetPositionY(), unstableSparkPos[otherRoom].GetPositionZ(), SPELL_UNSTABLE_SPARK_MISSILE, true);
        }

    private:

        uint32 m_AggroTimer;
        bool m_AggroDone;
        SpoilsOfPandariaRooms m_Room;

};

class npc_spoils_of_pandaria_animated_stone_mogu : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_animated_stone_mogu() : CreatureScript("npc_spoils_of_pandaria_animated_stone_mogu") { }

        enum eEvents
        {
            EVENT_HARDEN_FLESH  = 1,
            EVENT_EARTHEN_SHARD
        };

        enum eTimers
        {
            TIMER_HARDEN_FLESH_MIN      = 3 * IN_MILLISECONDS,
            TIMER_HARDEN_FLESH_MAX      = 7 * IN_MILLISECONDS,
            TIMER_EARTHEN_SHARD_FIRST   = 1 * IN_MILLISECONDS,
            TIMER_EARTHEN_SHARD_MIN     = 9 * IN_MILLISECONDS,
            TIMER_EARTHEN_SHARD_MAX     = 12 * IN_MILLISECONDS
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_animated_stone_moguAI(creature);
        }

        struct npc_spoils_of_pandaria_animated_stone_moguAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_animated_stone_moguAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(eEvents::EVENT_HARDEN_FLESH, urand(eTimers::TIMER_HARDEN_FLESH_MIN, eTimers::TIMER_HARDEN_FLESH_MAX));
                events.ScheduleEvent(eEvents::EVENT_EARTHEN_SHARD, eTimers::TIMER_EARTHEN_SHARD_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case eEvents::EVENT_HARDEN_FLESH:
                        DoHardenFlesh();
                        events.ScheduleEvent(eEvents::EVENT_HARDEN_FLESH, urand(eTimers::TIMER_HARDEN_FLESH_MIN, eTimers::TIMER_HARDEN_FLESH_MAX));
                        break;
                    case eEvents::EVENT_EARTHEN_SHARD:
                        DoEarthenShard();
                        events.ScheduleEvent(eEvents::EVENT_EARTHEN_SHARD, urand(eTimers::TIMER_EARTHEN_SHARD_MIN, eTimers::TIMER_EARTHEN_SHARD_MAX));
                        break;
                }
            }

            void DoHardenFlesh()
            {
                DoCast(me, Spells::SPELL_HARDEN_FLESH);
            }

            void DoEarthenShard()
            {
                Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, -10.0f, GetRoom()));
                if (!l_Target)
                    l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom()));

                if (!l_Target)
                    return;

                DoCast(l_Target, Spells::SPELL_EARTHEN_SHARD);
            }
        };
};

class npc_spoils_of_pandaria_burial_urn : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_burial_urn() : CreatureScript("npc_spoils_of_pandaria_burial_urn") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_burial_urnAI(creature);
        }

        struct npc_spoils_of_pandaria_burial_urnAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_burial_urnAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);
            }

        private:

            void DoAggro() override
            {
                DoCast(me, Spells::SPELL_SPARK_OF_LIFE_PERIODIC, true);
            }

        };
};

class npc_spoils_of_pandaria_spark_of_life : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_spark_of_life() : CreatureScript("npc_spoils_of_pandaria_spark_of_life") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_spark_of_lifeAI(creature);
        }

        struct npc_spoils_of_pandaria_spark_of_lifeAI : public Scripted_NoMovementAI
        {
            npc_spoils_of_pandaria_spark_of_lifeAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                //ApplyAllImmunities(true);

                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                me->AddAura(Spells::SPELL_SPARK_OF_LIFE_VISUAL, me);
                me->AddAura(Spells::SPELL_PULSATION, me);
            }

            void JustDied(Unit* p_Who) override
            {
                DoCast(me, Spells::SPELL_NOVA, true);

                me->DespawnOrUnsummon(100);
            }
        };
};

class npc_spoils_of_pandaria_quilen_guardian : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_quilen_guardian() : CreatureScript("npc_spoils_of_pandaria_quilen_guardian") { }

        enum eEvents
        {
            EVENT_CARNIVOROUS_BITE  = 1
        };

        enum eTimers
        {
            TIMER_CARNIVOROUS_BITE_FIRST_MIN    = 2 * IN_MILLISECONDS,
            TIMER_CARNIVOROUS_BITE_FIRST_MAX    = 5 * IN_MILLISECONDS,
            TIMER_CARNIVOROUS_BITE_MIN          = 6 * IN_MILLISECONDS,
            TIMER_CARNIVOROUS_BITE_MAX          = 10 * IN_MILLISECONDS
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_quilen_guardianAI(creature);
        }

        struct npc_spoils_of_pandaria_quilen_guardianAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_quilen_guardianAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void SetQuilenGuids(std::vector<ObjectGuid>& l_Guids)
            {
                m_QuilenGuids = l_Guids;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(eEvents::EVENT_CARNIVOROUS_BITE, urand(eTimers::TIMER_CARNIVOROUS_BITE_FIRST_MIN, eTimers::TIMER_CARNIVOROUS_BITE_FIRST_MAX));
            }

            bool CanIncreaseEnergy() const override
            {
                return !IsAnyQuilenAlive();
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case eEvents::EVENT_CARNIVOROUS_BITE:
                        DoCarnovorousBite();
                        events.ScheduleEvent(eEvents::EVENT_CARNIVOROUS_BITE, urand(eTimers::TIMER_CARNIVOROUS_BITE_MIN, eTimers::TIMER_CARNIVOROUS_BITE_MAX));
                        break;
                }
            }

            void DoCarnovorousBite()
            {
                DoCastVictim(Spells::SPELL_CARNIVOROUS_BITE);
            }

            bool IsAnyQuilenAlive() const
            {
                for (auto l_Guid : m_QuilenGuids)
                {
                    if (me->GetGUID() == l_Guid)
                        continue;

                    if (Creature* l_Quilen = ObjectAccessor::GetCreature(*me, l_Guid))
                        if (l_Quilen->IsInCombat())
                            return true;
                }

                return false;
            }

        private:

            std::vector<ObjectGuid> m_QuilenGuids;
        };
};

class npc_spoils_of_pandaria_quilen_guardians : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_quilen_guardians() : CreatureScript("npc_spoils_of_pandaria_quilen_guardians") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_quilen_guardiansAI(creature);
        }

        struct npc_spoils_of_pandaria_quilen_guardiansAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_quilen_guardiansAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void IsSummonedBy(Unit* p_Owner) override
            {
                Creature* l_Spoils = GetSpoilsOfPandaria(me);
                if (!l_Spoils)
                    return;

                float l_Orientation = frand(0.f, 2.f * float(M_PI));

                std::vector<Position> l_Positions =
                {
                    { me->GetPositionX() + 1.f, me->GetPositionY() + 1.0f, me->GetPositionZ(), l_Orientation },
                    { me->GetPositionX() - 1.f, me->GetPositionY() + 1.0f, me->GetPositionZ(), l_Orientation },
                    { me->GetPositionX() + 1.0f, me->GetPositionY() - 1.f, me->GetPositionZ(), l_Orientation },
                    { me->GetPositionX() - 1.f, me->GetPositionY() - 1.f, me->GetPositionZ(), l_Orientation }
                };

                std::vector<ObjectGuid> l_Guids;
                std::vector<Creature*> l_Quilens;

                for (auto l_Position : l_Positions)
                {
                    if (Creature* l_Quilen = l_Spoils->SummonCreature(Adds::NPC_QUILEN_GUARDIAN, l_Position))
                    {
                        l_Quilen->AI()->SetData(Datas::DATA_MOB_ROOM, RoomChecker::GetRoomForObject(l_Quilen));
                        l_Quilens.push_back(l_Quilen);
                        l_Guids.push_back(l_Quilen->GetGUID());
                    }
                }

                for (auto l_Quilen : l_Quilens)
                {
                    if (npc_spoils_of_pandaria_quilen_guardian::npc_spoils_of_pandaria_quilen_guardianAI* l_QuilenAI =
                        CAST_AI(npc_spoils_of_pandaria_quilen_guardian::npc_spoils_of_pandaria_quilen_guardianAI, l_Quilen->GetAI()))
                    {
                        l_QuilenAI->SetQuilenGuids(l_Guids);
                    }
                }

                me->DespawnOrUnsummon(1000);
            }
        };
};

class npc_spoils_of_pandaria_mogu_shadow_ritualist : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_mogu_shadow_ritualist() : CreatureScript("npc_spoils_of_pandaria_mogu_shadow_ritualist") { }

        enum eEvents
        {
            EVENT_TORMENT = 1,
            EVENT_MOGU_RUNE_OF_POWER,
            EVENT_FORBIDDEN_MAGIC
        };

        enum eTimers
        {
            TIMER_FORBIDDEN_MAGIC_FIRST     = 5 * IN_MILLISECONDS,
            TIMER_FORBIDDEN_MAGIC           = 10 * IN_MILLISECONDS,
            TIMER_TORMENT                   = 3 * IN_MILLISECONDS,
            TIMER_MOGU_RUNE_OF_POWER_FIRST  = 8 * IN_MILLISECONDS,
            TIMER_MOGU_RUNE_OF_POWER        = 25 * IN_MILLISECONDS
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_mogu_shadow_ritualistAI(creature);
        }

        struct npc_spoils_of_pandaria_mogu_shadow_ritualistAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_mogu_shadow_ritualistAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(eEvents::EVENT_FORBIDDEN_MAGIC, eTimers::TIMER_FORBIDDEN_MAGIC_FIRST);
                events.ScheduleEvent(eEvents::EVENT_TORMENT, eTimers::TIMER_TORMENT);
                events.ScheduleEvent(eEvents::EVENT_MOGU_RUNE_OF_POWER, eTimers::TIMER_MOGU_RUNE_OF_POWER_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case eEvents::EVENT_FORBIDDEN_MAGIC:
                        DoForbiddenMagic();
                        events.ScheduleEvent(eEvents::EVENT_FORBIDDEN_MAGIC, eTimers::TIMER_FORBIDDEN_MAGIC);
                        break;
                    case eEvents::EVENT_TORMENT:
                        DoTorment();
                        break;
                    case eEvents::EVENT_MOGU_RUNE_OF_POWER:
                        DoMoguRuneOfPower();
                        events.ScheduleEvent(eEvents::EVENT_MOGU_RUNE_OF_POWER, eTimers::TIMER_MOGU_RUNE_OF_POWER);
                        break;
                }
            }

            void DoForbiddenMagic()
            {
                if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 8.0f, GetRoom())))
                    DoCast(l_Target, Spells::SPELL_FORBIDDEN_MAGIC);
            }

            void DoTorment()
            {
                if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom())))
                    DoCast(l_Target, Spells::SPELL_TORMENT);
            }

            void DoMoguRuneOfPower()
            {
                DoCast(me, Spells::SPELL_MOGU_RUNE_OF_POWER);
            }
        };
};

class npc_spoils_of_pandaria_modified_anima_golem : public CreatureScript
{
    private:

        enum eEvents
        {
            EVENT_CRIMSON_RECONSTITUTION    = 1,
            EVENT_MATTER_SCRAMBLE,
            EVENT_CRIMSON_ACID
        };

        enum eTimers
        {
            TIMER_CRIMSON_RECONSTITUTION_FIRST  = 4 * IN_MILLISECONDS,
            TIMER_CRIMSON_RECONSTITUTION        = 25 * IN_MILLISECONDS,
            TIMER_MATTER_SCRAMBLE_FIRST         = 8 * IN_MILLISECONDS,
            TIMER_MATTER_SCRAMBLE               = 25 * IN_MILLISECONDS,
            TIMER_CRIMSON_ACID                  = 20 * IN_MILLISECONDS
        };

    public:
        npc_spoils_of_pandaria_modified_anima_golem() : CreatureScript("npc_spoils_of_pandaria_modified_anima_golem") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_modified_anima_golemAI(creature);
        }

        struct npc_spoils_of_pandaria_modified_anima_golemAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_modified_anima_golemAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            bool IsAcidAreaTrigger(ObjectGuid l_Guid) const
            {
                return m_AcidAreaTriggers.find(l_Guid) != m_AcidAreaTriggers.end();
            }

            void SetData(uint32 p_Id, uint32 p_Data) override
            {
                if (p_Id == eDatas::DATA_MATTER_SCRAMBLE_COUNT)
                    m_ScrambleCount = p_Data;

                npc_spoils_of_pandaria_mobAI::SetData(p_Id, p_Data);
            }

            void SetObjectGuid(ObjectGuid p_Guid, int32 p_Id)
            {
                if (p_Id == eDatas::DATA_MATTER_SCRAMBLE_GUID)
                    AddMatterScrambleTarget(p_Guid);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(eEvents::EVENT_CRIMSON_RECONSTITUTION, eTimers::TIMER_CRIMSON_RECONSTITUTION_FIRST);
                events.ScheduleEvent(eEvents::EVENT_CRIMSON_ACID, eTimers::TIMER_CRIMSON_ACID);
                events.ScheduleEvent(eEvents::EVENT_MATTER_SCRAMBLE, eTimers::TIMER_MATTER_SCRAMBLE_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case eEvents::EVENT_CRIMSON_RECONSTITUTION:
                        DoCrimsonReconstitution();
                        events.ScheduleEvent(eEvents::EVENT_CRIMSON_RECONSTITUTION, eTimers::TIMER_CRIMSON_RECONSTITUTION);
                        break;
                    case eEvents::EVENT_CRIMSON_ACID:
                        DoCrimsonAcid();
                        events.ScheduleEvent(eEvents::EVENT_CRIMSON_ACID, eTimers::TIMER_CRIMSON_ACID);
                        break;
                    case eEvents::EVENT_MATTER_SCRAMBLE:
                        DoMatterScramble();
                        events.ScheduleEvent(eEvents::EVENT_MATTER_SCRAMBLE, eTimers::TIMER_MATTER_SCRAMBLE);
                        break;
                }
            }

            void DoCrimsonReconstitution()
            {
                DoCast(me, Spells::SPELL_CRIMSON_RECONSTITUTION);
            }

            void DoCrimsonAcid()
            {
                DoCast(me, Spells::SPELL_CRIMSON_ACID);

                std::vector<AreaTrigger*> l_AreaTriggers;
                l_AreaTriggers = me->GetAreaTriggers(Spells::SPELL_CRIMSON_RECONSTITUTION_AREATRIGGER);

                for (auto l_AreaTrigger : l_AreaTriggers)
                {
                    m_AcidAreaTriggers.insert(l_AreaTrigger->GetGUID());
                }
            }

            void DoMatterScramble()
            {
                DoCast(me, Spells::SPELL_MATTER_SCRAMBLE);

                m_ScrambleCount = 0;
                m_ScrambleGuids.clear();
            }

            void AddMatterScrambleTarget(ObjectGuid p_Guid)
            {
                m_ScrambleGuids.insert(p_Guid);

                if (m_ScrambleCount > 1 && m_ScrambleGuids.size() >= m_ScrambleCount)
                {
                    ObjectGuid l_PrevGuid = *m_ScrambleGuids.rbegin();

                    for (auto l_Guid : m_ScrambleGuids)
                    {
                        if (l_PrevGuid != ObjectGuid::Empty)
                        {
                            Unit* l_DestTarget = ObjectAccessor::GetUnit(*me, l_PrevGuid);
                            Unit* l_Target = ObjectAccessor::GetUnit(*me, l_Guid);

                            if (l_DestTarget != nullptr && l_Target != nullptr)
                            {
                                if (l_Target->IsInCombat())
                                    l_Target->NearTeleportTo(*l_DestTarget);
                            }
                        }

                        l_PrevGuid = l_Guid;
                    }

                    m_ScrambleCount = 0;
                    m_ScrambleGuids.clear();
                }
            }

        private:

            std::set<ObjectGuid> m_AcidAreaTriggers;
            std::set<ObjectGuid> m_ScrambleGuids;
            uint32 m_ScrambleCount = 0;
        };
};

class npc_spoils_of_pandaria_jun_wei : public CreatureScript
{
    private:

        enum eEvents
        {
            EVENT_SHADOW_VOLLEY = 1,
            EVENT_RETURN_TO_STONE
        };

        enum eTimers
        {
            TIMER_SHADOW_VOLLEY_FIRST   = 7 * IN_MILLISECONDS,
            TIMER_SHADOW_VOLLEY         = 15 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE_FIRST = 4 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE       = 15 * IN_MILLISECONDS
        };

    public:
        npc_spoils_of_pandaria_jun_wei() : CreatureScript("npc_spoils_of_pandaria_jun_wei") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_jun_weiAI(creature);
        }

        struct npc_spoils_of_pandaria_jun_weiAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_jun_weiAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_StatuesCount(0)
            {

            }

            void JustSummoned(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                {
                    m_StatuesCount++;

                    if (!me->HasAura(Spells::SPELL_STRENGTH_OF_THE_STONE))
                        me->AddAura(Spells::SPELL_STRENGTH_OF_THE_STONE, me);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                    m_StatuesCount--;
            }

            uint32 GetData(uint32 p_Type) const override
            {
                if (p_Type == DATA_STONE_STATUE_COUNT)
                {
                    return m_StatuesCount;
                }

                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(eEvents::EVENT_SHADOW_VOLLEY, eTimers::TIMER_SHADOW_VOLLEY_FIRST);
                events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case eEvents::EVENT_SHADOW_VOLLEY:
                        DoShadowVolley();
                        events.ScheduleEvent(eEvents::EVENT_SHADOW_VOLLEY, eTimers::TIMER_SHADOW_VOLLEY);
                        break;
                    case eEvents::EVENT_RETURN_TO_STONE:
                        DoReturnToStone();
                        events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE);
                        break;
                }
            }

            void DoShadowVolley()
            {
                DoCast(me, Spells::SPELL_SHADOW_VOLLEY);
            }

            void DoReturnToStone()
            {
                DoCast(me, SPELL_RETURN_TO_STONE);
            }

        private:

            uint32 m_StatuesCount;
        };
};

class npc_spoils_of_pandaria_zu_yin : public CreatureScript
{
    private:

        enum eEvents
        {
            EVENT_MOLTEN_FIST = 1,
            EVENT_RETURN_TO_STONE
        };

        enum eTimers
        {
            TIMER_MOLTEN_FIST_FIRST     = 5 * IN_MILLISECONDS,
            TIMER_MOLTEN_FIST           = 15 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE_FIRST = 4 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE       = 15 * IN_MILLISECONDS
        };

    public:
        npc_spoils_of_pandaria_zu_yin() : CreatureScript("npc_spoils_of_pandaria_zu_yin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_zu_yinAI(creature);
        }

        struct npc_spoils_of_pandaria_zu_yinAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_zu_yinAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_StatuesCount(0)
            {

            }

            void JustSummoned(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                {
                    m_StatuesCount++;

                    if (!me->HasAura(Spells::SPELL_STRENGTH_OF_THE_STONE))
                        me->AddAura(Spells::SPELL_STRENGTH_OF_THE_STONE, me);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                    m_StatuesCount--;
            }

            uint32 GetData(uint32 p_Type) const override
            {
                if (p_Type == DATA_STONE_STATUE_COUNT)
                {
                    return m_StatuesCount;
                }

                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_MOLTEN_FIST, TIMER_MOLTEN_FIST_FIRST);
                events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_MOLTEN_FIST:
                        DoMoltenFist();
                        events.ScheduleEvent(EVENT_MOLTEN_FIST, TIMER_MOLTEN_FIST);
                        break;
                    case eEvents::EVENT_RETURN_TO_STONE:
                        DoReturnToStone();
                        events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE);
                        break;
                }
            }

            void DoMoltenFist()
            {
                DoCast(me, SPELL_MOLTEN_FIST);
            }

            void DoReturnToStone()
            {
                DoCast(me, SPELL_RETURN_TO_STONE);
            }

        private:

            uint32 m_StatuesCount;
        };
};

class npc_spoils_of_pandaria_xiang_lin : public CreatureScript
{
    private:

        enum eEvents
        {
            EVENT_JADE_TEMPEST = 1,
            EVENT_RETURN_TO_STONE
        };

        enum eTimers
        {
            TIMER_JADE_TEMPEST_FIRST    = 5 * IN_MILLISECONDS,
            TIMER_JADE_TEMPEST          = 15 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE_FIRST = 4 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE       = 15 * IN_MILLISECONDS
        };

    public:
        npc_spoils_of_pandaria_xiang_lin() : CreatureScript("npc_spoils_of_pandaria_xiang_lin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_xiang_linAI(creature);
        }

        struct npc_spoils_of_pandaria_xiang_linAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_xiang_linAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_StatuesCount(0)
            {

            }

            void JustSummoned(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                {
                    m_StatuesCount++;

                    if (!me->HasAura(Spells::SPELL_STRENGTH_OF_THE_STONE))
                        me->AddAura(Spells::SPELL_STRENGTH_OF_THE_STONE, me);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                    m_StatuesCount--;
            }

            uint32 GetData(uint32 p_Type) const override
            {
                if (p_Type == DATA_STONE_STATUE_COUNT)
                {
                    return m_StatuesCount;
                }

                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_JADE_TEMPEST, TIMER_JADE_TEMPEST_FIRST);
                events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_JADE_TEMPEST:
                        DoJadeTempest();
                        events.ScheduleEvent(EVENT_JADE_TEMPEST, TIMER_JADE_TEMPEST);
                        break;
                    case eEvents::EVENT_RETURN_TO_STONE:
                        DoReturnToStone();
                        events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE);
                        break;
                }
            }

            void DoJadeTempest()
            {
                DoCast(me, SPELL_JADE_TEMPEST);
            }

            void DoReturnToStone()
            {
                DoCast(me, SPELL_RETURN_TO_STONE);
            }

        private:

            uint32 m_StatuesCount;
        };
};

class npc_spoils_of_pandaria_kun_da : public CreatureScript
{
    private:

        enum eEvents
        {
            EVENT_FRACTURE = 1,
            EVENT_RETURN_TO_STONE
        };

        enum eTimers
        {
            TIMER_FRACTURE_FIRST        = 5 * IN_MILLISECONDS,
            TIMER_FRACTURE              = 15 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE_FIRST = 4 * IN_MILLISECONDS,
            TIMER_RETURN_TO_STONE       = 15 * IN_MILLISECONDS
        };

    public:
        npc_spoils_of_pandaria_kun_da() : CreatureScript("npc_spoils_of_pandaria_kun_da") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_kun_daAI(creature);
        }

        struct npc_spoils_of_pandaria_kun_daAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_kun_daAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_StatuesCount(0)
            {

            }

            void JustSummoned(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                {
                    m_StatuesCount++;

                    if (!me->HasAura(Spells::SPELL_STRENGTH_OF_THE_STONE))
                        me->AddAura(Spells::SPELL_STRENGTH_OF_THE_STONE, me);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Creature) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_STONE_STATUE)
                    m_StatuesCount--;
            }

            uint32 GetData(uint32 p_Type) const override
            {
                if (p_Type == DATA_STONE_STATUE_COUNT)
                {
                    return m_StatuesCount;
                }

                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_FRACTURE, TIMER_FRACTURE_FIRST);
                events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE_FIRST);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_FRACTURE:
                        DoFracture();
                        events.ScheduleEvent(EVENT_FRACTURE, TIMER_FRACTURE);
                        break;
                    case eEvents::EVENT_RETURN_TO_STONE:
                        DoReturnToStone();
                        events.ScheduleEvent(eEvents::EVENT_RETURN_TO_STONE, eTimers::TIMER_RETURN_TO_STONE);
                        break;
                }
            }

            void DoFracture()
            {
                DoCast(me, SPELL_FRACTURE);
            }

            void DoReturnToStone()
            {
                DoCast(me, SPELL_RETURN_TO_STONE);
            }

        private:

            uint32 m_StatuesCount;
        };
};

class npc_spoils_of_pandaria_stone_statue : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_stone_statue() : CreatureScript("npc_spoils_of_pandaria_stone_statue") { }

        enum eEvents
        {
            EVENT_ANIMATED_STRIKE   = 1
        };

        enum eTimers
        {
            TIMER_ANIMATED_STRIKE_FIRST_MIN = 3 * IN_MILLISECONDS,
            TIMER_ANIMATED_STRIKE_FIRST_MAX = 7 * IN_MILLISECONDS,
            TIMER_ANIMATED_STRIKE_MIN       = 10 * IN_MILLISECONDS,
            TIMER_ANIMATED_STRIKE_MAX       = 20 * IN_MILLISECONDS
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_stone_statueAI(creature);
        }

        struct npc_spoils_of_pandaria_stone_statueAI : public ScriptedAI
        {
            npc_spoils_of_pandaria_stone_statueAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->SetReactState(ReactStates::REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* p_Owner) override
            {
                me->AddAura(Spells::SPELL_RETURN_TO_STONE_VISUAL_3, me);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                events.ScheduleEvent(eEvents::EVENT_ANIMATED_STRIKE, urand(eTimers::TIMER_ANIMATED_STRIKE_FIRST_MIN, eTimers::TIMER_ANIMATED_STRIKE_FIRST_MAX));
            }

            void JustDied(Unit* p_Killer) override
            {
                events.Reset();

                me->DespawnOrUnsummon(1 * IN_MILLISECONDS);
            }

            void UpdateAI(const uint32 p_Diff)
            {
                UpdateVisual(p_Diff);

                if (!UpdateVictim())
                    return;

                events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                if (uint32 l_EventId = events.ExecuteEvent())
                {
                    ExecuteEvent(l_EventId);
                }
            }

        private:

            void UpdateVisual(uint32 p_Diff)
            {
                if (m_VisualDone)
                    return;

                if (m_UpdateTimer <= p_Diff)
                {
                    m_VisualDone = true;

                    me->RemoveAura(Spells::SPELL_RETURN_TO_STONE_VISUAL_3);
                    DoCast(me, Spells::SPELL_RETURN_TO_STONE_SPAWN_1);
                }
                else
                {
                    m_UpdateTimer -= p_Diff;
                }
            }

            void ExecuteEvent(uint32 p_EventId)
            {
                if (p_EventId == eEvents::EVENT_ANIMATED_STRIKE)
                {
                    DoAnimatedStrike();
                    events.ScheduleEvent(eEvents::EVENT_ANIMATED_STRIKE, urand(eTimers::TIMER_ANIMATED_STRIKE_MIN, eTimers::TIMER_ANIMATED_STRIKE_MAX));
                }
            }

            void DoAnimatedStrike()
            {
                float l_Orientation = frand(0.f, 2.f * float(M_PI));
                me->SetOrientation(l_Orientation);
                me->SetFacingTo(l_Orientation);
                DoCast(me, Spells::SPELL_ANIMATED_STRIKE);
            }

        private:

            bool m_VisualDone = false;
            uint32 m_UpdateTimer = 1 * IN_MILLISECONDS;
        };
};

class npc_spoils_of_pandaria_srithik_bombardier : public CreatureScript
{
    public:
        npc_spoils_of_pandaria_srithik_bombardier() : CreatureScript("npc_spoils_of_pandaria_srithik_bombardier") { }

        enum eEvents
        {
            EVENT_GUSTING_BOMB = 1,
            EVENT_THROW_EXPLOSIVES,
        };

        enum eTimers
        {
            TIMER_GUSTING_BOMB_FIRST = 4 * IN_MILLISECONDS,
            TIMER_GUSTING_BOMB = 10 * IN_MILLISECONDS,
            TIMER_THROW_EXPLOSIVES_FIRST = 7 * IN_MILLISECONDS,
            TIMER_THROW_EXPLOSIVES = 15 * IN_MILLISECONDS
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_srithik_bombardierAI(creature);
        }

        struct npc_spoils_of_pandaria_srithik_bombardierAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_srithik_bombardierAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_SpellPathWorker(creature)
            {

            }

            void SetObjectGuid(ObjectGuid p_Guid, int32 l_Type)
            {
                if (Unit* l_Target = ObjectAccessor::GetUnit(*me, p_Guid))
                {
                    m_SpellPathWorker.SpawnSpellPathFor(l_Target, Spells::SPELL_GUSTING_BOMB_AREATRIGGER);
                }
            }

            void JustDied(Unit* p_Who) override
            {
                npc_spoils_of_pandaria_mobAI::JustDied(p_Who);

                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    l_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_GUSTING_BOMB_PERIODIC);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                m_SpellPathWorker.UpdateSpellPath(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_GUSTING_BOMB, TIMER_GUSTING_BOMB_FIRST);
                events.ScheduleEvent(EVENT_THROW_EXPLOSIVES, TIMER_THROW_EXPLOSIVES_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_GUSTING_BOMB:
                        DoGustingBomb();
                        events.ScheduleEvent(EVENT_GUSTING_BOMB, TIMER_GUSTING_BOMB);
                        break;
                    case EVENT_THROW_EXPLOSIVES:
                        DoThrowExplosives();
                        events.ScheduleEvent(EVENT_THROW_EXPLOSIVES, TIMER_THROW_EXPLOSIVES);
                        break;
                }
            }

            void DoGustingBomb()
            {
                DoCast(me, SPELL_GUSTING_BOMB);
            }

            void DoThrowExplosives()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, -15.0f, GetRoom()));
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom()));

                if (!target)
                    return;

                DoCast(target, SPELL_THROW_EXPLOSIVES);
            }

        private:

            SpellPathWorker m_SpellPathWorker;
        };
};

class npc_spoils_of_pandaria_amber_encased_kunchong : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_ENCAPSULATED_PHEROMONES  = 1,
        };

    public:
        npc_spoils_of_pandaria_amber_encased_kunchong() : CreatureScript("npc_spoils_of_pandaria_amber_encased_kunchong") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_amber_encased_kunchongAI(creature);
        }

        struct npc_spoils_of_pandaria_amber_encased_kunchongAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_amber_encased_kunchongAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_ENCAPSULATED_PHEROMONES, TIMER_ENCAPSULATED_PHEROMONES);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ENCAPSULATED_PHEROMONES:
                        DoEncapsulatedPheromones();
                        events.ScheduleEvent(EVENT_ENCAPSULATED_PHEROMONES, TIMER_ENCAPSULATED_PHEROMONES);
                        break;
                }
            }

            void DoEncapsulatedPheromones()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, -15.0f, GetRoom()));
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom()));

                if (!target)
                    return;

                DoCast(target, SPELL_ENCAPSULATED_PHEROMONES_AREATRIGGER);
            }
        };
};

class npc_spoils_of_pandaria_korthik_warcaller : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_ENRAGE  = 1,
        };

    public:
        npc_spoils_of_pandaria_korthik_warcaller() : CreatureScript("npc_spoils_of_pandaria_korthik_warcaller") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_korthik_warcallerAI(creature);
        }

        struct npc_spoils_of_pandaria_korthik_warcallerAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_korthik_warcallerAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ENRAGE:
                        DoEnrage();
                        events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE);
                        break;
                }
            }

            void DoEnrage()
            {
                DoCast(me, SPELL_ENRAGE);
            }
        };
};

class npc_spoils_of_pandaria_zarthik_amber_priest : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_MANDID_SWARM  = 1,
            EVENT_RESIDUE,
        };

    public:
        npc_spoils_of_pandaria_zarthik_amber_priest() : CreatureScript("npc_spoils_of_pandaria_zarthik_amber_priest") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_zarthik_amber_priestAI(creature);
        }

        struct npc_spoils_of_pandaria_zarthik_amber_priestAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_zarthik_amber_priestAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_MANDID_SWARM, TIMER_MANTID_SWARM_FIRST);
                events.ScheduleEvent(EVENT_RESIDUE, TIMER_RESIDUE_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_MANDID_SWARM:
                        DoMantidSwarm();
                        events.ScheduleEvent(EVENT_MANDID_SWARM, TIMER_MANTID_SWARM);
                        break;
                    case EVENT_RESIDUE:
                        DoResidue();
                        events.ScheduleEvent(EVENT_RESIDUE, TIMER_RESIDUE);
                        break;
                }
            }

            void DoMantidSwarm()
            {
                DoCast(me, SPELL_MANTID_SWARM);
            }

            void DoResidue()
            {
                DoCastAOE(SPELL_RESIDUE);
            }
        };
};

class npc_spoils_of_pandaria_setthik_wind_wielder : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_RAGE_OF_THE_EMPRESS   = 1,
            EVENT_WINDSTORM,
        };

    public:
        npc_spoils_of_pandaria_setthik_wind_wielder() : CreatureScript("npc_spoils_of_pandaria_setthik_wind_wielder") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_setthik_wind_wielderAI(creature);
        }

        struct npc_spoils_of_pandaria_setthik_wind_wielderAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_setthik_wind_wielderAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_RAGE_OF_THE_EMPRESS, TIMER_RAGE_OF_THE_EMPRESS_FIRST);
                events.ScheduleEvent(EVENT_WINDSTORM, TIMER_WINDSTORM_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_RAGE_OF_THE_EMPRESS:
                        DoRageOfTheEmpress();
                        events.ScheduleEvent(EVENT_RAGE_OF_THE_EMPRESS, TIMER_RAGE_OF_THE_EMPRESS);
                        break;
                    case EVENT_WINDSTORM:
                        DoWindStorm();
                        events.ScheduleEvent(EVENT_WINDSTORM, TIMER_WINDSTORM);
                        break;
                }
            }

            void DoRageOfTheEmpress()
            {
                DoCastAOE(SPELL_RAGE_OF_THE_EMPRESS);
            }

            void DoWindStorm()
            {
                DoCast(SPELL_WINDSTORM_AREATRIGGER);
            }
        };
};

class npc_spoils_of_pandaria_mantid_commander : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_SET_TO_BLOW  = 1,
            EVENT_PHEROMONE_CLOUD,
        };

    public:
        npc_spoils_of_pandaria_mantid_commander() : CreatureScript("npc_spoils_of_pandaria_mantid_commander") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_mantid_commanderAI(creature);
        }

        struct npc_spoils_of_pandaria_mantid_commanderAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_mantid_commanderAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_SET_TO_BLOW, TIMER_SET_TO_BLOW_FIRST);
                events.ScheduleEvent(EVENT_PHEROMONE_CLOUD, TIMER_PHEROMONE_CLOUD);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_SET_TO_BLOW:
                        DoSetToBlow();
                        events.ScheduleEvent(EVENT_SET_TO_BLOW, TIMER_SET_TO_BLOW);
                        break;
                    case EVENT_PHEROMONE_CLOUD:
                        DoPheromoneCloud();
                        break;
                }
            }

            void DoSetToBlow()
            {
                DoCast(me, SPELL_SET_TO_BLOW);
            }

            void DoPheromoneCloud()
            {
                DoCast(me, SPELL_PHEROMONE_CLOUD);
            }

        };
};

class npc_spoils_of_pandaria_ancient_brewmaster_spirit : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_KEG_TOSS  = 1,
            EVENT_BREATH_OF_FIRE,
        };

    public:
        npc_spoils_of_pandaria_ancient_brewmaster_spirit() : CreatureScript("npc_spoils_of_pandaria_ancient_brewmaster_spirit") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_ancient_brewmaster_spiritAI(creature);
        }

        struct npc_spoils_of_pandaria_ancient_brewmaster_spiritAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_ancient_brewmaster_spiritAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void JustDied(Unit* p_Who) override
            {
                npc_spoils_of_pandaria_mobAI::JustDied(p_Who);

                BuffPlayers();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_KEG_TOSS, TIMER_KEG_TOSS_FIRST);
                events.ScheduleEvent(EVENT_BREATH_OF_FIRE, TIMER_BREATH_OF_FIRE_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_KEG_TOSS:
                        DoKegToss();
                        events.ScheduleEvent(EVENT_KEG_TOSS, TIMER_KEG_TOSS);
                        break;
                    case EVENT_BREATH_OF_FIRE:
                        DoBreathOfFire();
                        events.ScheduleEvent(EVENT_BREATH_OF_FIRE, TIMER_BREATH_OF_FIRE);
                        break;
                }
            }

            void DoKegToss()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, -15.0f, GetRoom()));
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom()));

                if (!target)
                    return;

                DoCast(target, SPELL_KEG_TOSS_MISSILE);
            }

            void DoBreathOfFire()
            {
                DoCastVictim(SPELL_BREATH_OF_FIRE);
            }

            void BuffPlayers()
            {
                std::list<Player*> l_Players;
                GetPlayersInRoomWithRoles(l_Players, { Roles::ROLE_TANK });

                for (auto l_Player : l_Players)
                {
                    DoCast(l_Player, Spells::SPELL_BLADE_OF_THE_HUNDRED_STEPS, true);
                }
            }
        };
};

class npc_spoils_of_pandaria_wise_mistweaver_spirit : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_GUSTING_CRANE_KICK    = 1,
        };

    public:
        npc_spoils_of_pandaria_wise_mistweaver_spirit() : CreatureScript("npc_spoils_of_pandaria_wise_mistweaver_spirit") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_wise_mistweaver_spiritAI(creature);
        }

        struct npc_spoils_of_pandaria_wise_mistweaver_spiritAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_wise_mistweaver_spiritAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature)
            {

            }

            void Reset()
            {
                npc_spoils_of_pandaria_mobAI::Reset();

                me->AddAura(SPELL_EMINENCE, me);
            }

            void JustDied(Unit* p_Who) override
            {
                npc_spoils_of_pandaria_mobAI::JustDied(p_Who);

                BuffPlayers();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_GUSTING_CRANE_KICK, TIMER_GUSTING_CRANE_KICK_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_GUSTING_CRANE_KICK:
                        DoGustingCraneKick();
                        events.ScheduleEvent(EVENT_GUSTING_CRANE_KICK, TIMER_GUSTING_CRANE_KICK);
                        break;
                }
            }

            void DoGustingCraneKick()
            {
                PullAllPlayers();
                DoCast(me, SPELL_GUSTING_CRANE_KICK);
            }

            void PullAllPlayers()
            {
                std::list<Player*> l_Players;
                GetPlayersInRoom(l_Players);

                for (auto l_Player : l_Players)
                {
                    //<l_Player->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetExactDist2d(l_Player), 10.f);
                    l_Player->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), me->GetExactDist2d(l_Player), 10.f);
                }
            }

            void BuffPlayers()
            {
                std::list<Player*> l_Players;
                GetPlayersInRoomWithRoles(l_Players, { Roles::ROLE_HEALER });

                for (auto l_Player : l_Players)
                {
                    DoCast(l_Player, Spells::SPELL_STAFF_OF_RESONATING_WATER, true);
                }
            }
        };
};

class npc_spoils_of_pandaria_nameless_windwalker_spirit : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_PATH_OF_BLOSSOMS  = 1,
        };

    public:
        npc_spoils_of_pandaria_nameless_windwalker_spirit() : CreatureScript("npc_spoils_of_pandaria_nameless_windwalker_spirit") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spoils_of_pandaria_nameless_windwalker_spiritAI(creature);
        }

        struct npc_spoils_of_pandaria_nameless_windwalker_spiritAI : public npc_spoils_of_pandaria_mobAI
        {
            npc_spoils_of_pandaria_nameless_windwalker_spiritAI(Creature* creature) :
                npc_spoils_of_pandaria_mobAI(creature), m_SpellPathWorker(creature)
            {

            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == EVENT_JUMP)
                {
                    me->GetMotionMaster()->MovementExpired(false);

                    me->SetReactState(REACT_AGGRESSIVE);

                    DoMassParalysis();
                }
            }

            void JustDied(Unit* p_Who) override
            {
                npc_spoils_of_pandaria_mobAI::JustDied(p_Who);

                BuffPlayers();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                UpdateAggroState(diff);

                m_SpellPathWorker.UpdateSpellPath(diff);

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ProcessEvents(eventId);
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoAggro() override
            {
                events.ScheduleEvent(EVENT_PATH_OF_BLOSSOMS, TIMER_PATH_OF_BLOSSOMS_FIRST);
            }

        private:

            void ProcessEvents(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_PATH_OF_BLOSSOMS:
                        DoPathOfBlossoms();
                        events.ScheduleEvent(EVENT_PATH_OF_BLOSSOMS, TIMER_PATH_OF_BLOSSOMS);
                        break;
                }
            }

            void DoPathOfBlossoms()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, -15.0f, GetRoom()));
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(me, 0.0f, GetRoom()));

                if (!target)
                    return;

                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();

                m_SpellPathWorker.SpawnSpellPathFor(target, Spells::SPELL_PATH_OF_BLOSSOMS_AREATRIGGER);

                me->AddAura(SPELL_PATH_OF_BLOSSOMS_AURA, me);
                DoCast(target, SPELL_PATH_OF_BLOSSOMS_JUMP);
            }


            void DoMassParalysis()
            {
                DoCastAOE(SPELL_MASS_PARALYSIS, true);
            }

            void BuffPlayers()
            {
                std::list<Player*> l_Players;
                GetPlayersInRoomWithRoles(l_Players, { Roles::ROLE_DAMAGE });

                for (auto l_Player : l_Players)
                {
                    DoCast(l_Player, Spells::SPELL_CLAW_OF_BURNING_ANGER, true);
                }
            }

        private:

            SpellPathWorker m_SpellPathWorker;
        };
};

class go_spoils_of_pandaria_stockpile : public GameObjectScript
{
    public:
        go_spoils_of_pandaria_stockpile() : GameObjectScript("go_spoils_of_pandaria_stockpile") { }

        bool OnGossipHello(Player* pPlayer, GameObject* pGo) override
        {
            if (IsEncounterDone(pGo))
                return true;

            if (IsInProgress(pGo))
                return true;

            pPlayer->PrepareGossipMenu(pGo, 15814);
            //pPlayer->PlayerTalkClass->SendGossipMenu(15814, pGo->GetGUID());
            pPlayer->PlayerTalkClass->SendGossipMenu(15814, pGo->GetGUID());
            //AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, gossipText.str(), GOSSIP_SENDER_MAIN, 0);
            //pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* pPlayer, GameObject* pGo, uint32 /*sender*/, uint32 action) override
        {
            pPlayer->PlayerTalkClass->SendCloseGossip();

            if (IsInProgress(pGo) || IsEncounterDone(pGo))
                return true;

            // in any case of action

            if (Creature* pSpoils = GetSpoilsOfPandaria(pGo))
            {
                pSpoils->AI()->DoAction(ACTION_START_ENCOUNTER);
            }

            return true;
        }

    private:

};

class go_spoils_of_pandaria_lever : public GameObjectScript
{
    public:
        go_spoils_of_pandaria_lever() : GameObjectScript("go_spoils_of_pandaria_lever") { }

        bool OnGossipHello(Player* pPlayer, GameObject* pGo) override
        {
            if (Creature* pSpoils = GetSpoilsOfPandaria(pGo))
            {
                uint8 action = GetActionForLever(pGo);
                pSpoils->AI()->DoAction(action);
            }

            return false;
        }

    private:

        uint8 GetActionForLever(GameObject* pGo)
        {
            switch (pGo->GetEntry())
            {
                case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_NORTH: return ACTION_USED_LEVER_NORTH;
                case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_WEST: return ACTION_USED_LEVER_WEST;
                case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_SOUTH: return ACTION_USED_LEVER_SOUTH;
                case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_EAST: return ACTION_USED_LEVER_EAST;
            }

            return 0;
        }

};

class spell_spoils_of_pandaria_breaking : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_breaking() : SpellScriptLoader("spell_spoils_of_pandaria_breaking") { }

        class spell_spoils_of_pandaria_breaking_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_breaking_SpellScript);

            SpellCastResult HandleCheckCast()
            {
                if (!GetCaster())
                    return SpellCastResult::SPELL_FAILED_DONT_REPORT;

                if (GetCaster()->IsPlayer() && GetCaster()->ToPlayer()->IsGameMaster())
                    return SpellCastResult::SPELL_CAST_OK;

                if (!IsInProgress(GetCaster()))
                    return SpellCastResult::SPELL_FAILED_DONT_REPORT;

                return SpellCastResult::SPELL_CAST_OK;
            }

            void HandleActivate(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                PreventHitDefaultEffect(effIndex);

                GameObject* pCrate = GetHitGObj();
                if (!pCrate)
                    return;

                if (!IsCrateEntry(pCrate->GetEntry()))
                    return;

                if (pCrate->GetGoState() == GO_STATE_ACTIVE)
                    return;

                Creature* pSpoils = GetSpoilsOfPandaria(GetCaster());
                if (!pSpoils)
                    return;

                SpoilsOfPandariaRooms room = RoomChecker::GetRoomForObject(pCrate);
                if (room == SpoilsOfPandariaRooms::ROOM_NONE)
                    return;

                SpoilsOfPandariaCrates crateType = GetCrateTypeForCrateEntry(pCrate->GetEntry());
                if (crateType == SpoilsOfPandariaCrates::CRATE_NONE)
                    return;

                uint32 summonEntry = GetMobEntryForCrateType(crateType);
                if (!summonEntry)
                    return;

                pCrate->SetLootState(GO_ACTIVATED);
                pCrate->SetFlags(GO_FLAG_IN_USE);
                pCrate->SetGoState(GO_STATE_ACTIVE);

                if (Creature* pMob = pSpoils->SummonCreature(summonEntry, *pCrate))
                {
                    pMob->AI()->SetData(DATA_MOB_ROOM, (int)room);
                }
            }

            void HandleLock(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_spoils_of_pandaria_breaking_SpellScript::HandleCheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_breaking_SpellScript::HandleActivate, EFFECT_0, SPELL_EFFECT_ACTIVATE_OBJECT);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_breaking_SpellScript::HandleLock, EFFECT_1, SPELL_EFFECT_OPEN_LOCK);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_breaking_SpellScript();
        }
};

class spell_spoils_of_pandaria_unstable_defense_systems_dmg : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_unstable_defense_systems_dmg() : SpellScriptLoader("spell_spoils_of_pandaria_unstable_defense_systems_dmg") { }

        class spell_spoils_of_pandaria_unstable_defense_systems_dmg_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_unstable_defense_systems_dmg_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetCaster()->CastSpell(GetUnitOwner(), SPELL_UNSTABLE_DEFENSE_SYSTEMS_DMG, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_unstable_defense_systems_dmg_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_unstable_defense_systems_dmg_AuraScript();
        }
};

class spell_spoils_of_pandaria_mantid_swarm : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_mantid_swarm() : SpellScriptLoader("spell_spoils_of_pandaria_mantid_swarm") { }

        class spell_spoils_of_pandaria_mantid_swarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_mantid_swarm_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_MANTID_SWARM_SUMMON_1, true);
                GetCaster()->CastSpell(GetCaster(), SPELL_MANTID_SWARM_SUMMON_2, true);
                GetCaster()->CastSpell(GetCaster(), SPELL_MANTID_SWARM_SUMMON_3, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_mantid_swarm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_mantid_swarm_SpellScript();
        }
};

class spell_spoils_of_pandaria_residue : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_residue() : SpellScriptLoader("spell_spoils_of_pandaria_residue") { }

        class spell_spoils_of_pandaria_residue_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_residue_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_RESIDUE_HEAL, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_residue_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_residue_SpellScript();
        }
};

class spell_spoils_of_pandaria_rage_of_the_empress : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_rage_of_the_empress() : SpellScriptLoader("spell_spoils_of_pandaria_rage_of_the_empress") { }

        class spell_spoils_of_pandaria_rage_of_the_empress_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_rage_of_the_empress_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_RAGE_OF_THE_EMPRESS_AURA, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_rage_of_the_empress_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_rage_of_the_empress_SpellScript();
        }
};

class spell_spoils_of_pandaria_set_to_blow : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_set_to_blow() : SpellScriptLoader("spell_spoils_of_pandaria_set_to_blow") { }

        class spell_spoils_of_pandaria_set_to_blow_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_set_to_blow_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    SpoilsOfPandariaRooms room = (SpoilsOfPandariaRooms)pCreature->AI()->GetData(DATA_MOB_ROOM);

                    if (Unit* target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(pCreature, 0.0f, room)))
                    {
                        pCreature->CastCustomSpell(SPELL_SET_TO_BLOW_OVERRIDE, SpellValueMod::SPELLVALUE_AURA_STACK, 4, target, true);
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_set_to_blow_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_set_to_blow_SpellScript();
        }
};

class spell_spoils_of_pandaria_set_to_blow_override : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_set_to_blow_override() : SpellScriptLoader("spell_spoils_of_pandaria_set_to_blow_override") { }

        class spell_spoils_of_pandaria_set_to_blow_override_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_set_to_blow_override_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                int stacks = GetAura()->GetStackAmount();

                Difficulty difficulty = GetUnitOwner()->GetMap()->GetDifficultyID();
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_SET_TO_BLOW_DMG);
                int basepoints = spellInfo->GetEffect(EFFECT_0)->BasePoints * stacks;

                GetUnitOwner()->CastCustomSpell(GetUnitOwner(), SPELL_SET_TO_BLOW_DMG, &basepoints, NULL, NULL, true);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spoils_of_pandaria_set_to_blow_override_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_set_to_blow_override_AuraScript();
        }
};

class spell_spoils_of_pandaria_throw_bomb : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_throw_bomb() : SpellScriptLoader("spell_spoils_of_pandaria_throw_bomb") { }

        class spell_spoils_of_pandaria_throw_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_throw_bomb_SpellScript);

            void HandleBeforeCast()
            {
                GetCaster()->RemoveAuraFromStack(SPELL_SET_TO_BLOW_OVERRIDE);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (WorldLocation const* loc = GetHitDest())
                {
                    GetCaster()->CastSpell(loc->GetPositionX(), loc->GetPositionY(), loc->GetPositionZ(), SPELL_SET_TO_BLOW_AREATRIGGER, true);
                }
            }

            void Register()
            {
                BeforeCast += SpellCastFn(spell_spoils_of_pandaria_throw_bomb_SpellScript::HandleBeforeCast);
                OnEffectHit += SpellEffectFn(spell_spoils_of_pandaria_throw_bomb_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_throw_bomb_SpellScript();
        }
};

class spell_spoils_of_pandaria_breath_of_fire : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_breath_of_fire() : SpellScriptLoader("spell_spoils_of_pandaria_breath_of_fire") { }

        class spell_spoils_of_pandaria_breath_of_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_breath_of_fire_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_BREATH_OF_FIRE_DMG, true);

                if (GetHitUnit()->HasAura(SPELL_KEG_TOSS_DMG))
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_BREATH_OF_FIRE_CONFUSE, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_breath_of_fire_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_breath_of_fire_SpellScript();
        }
};

class spell_spoils_of_pandaria_eminence : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_eminence() : SpellScriptLoader("spell_spoils_of_pandaria_eminence") { }

        class spell_spoils_of_pandaria_eminence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_eminence_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* actor = eventInfo.GetActor();

                if (!actor)
                    return;

                int32 healValue = eventInfo.GetDamageInfo()->GetDamage() * 1.5f;

                actor->CastCustomSpell(actor, SPELL_EMINENCE_HEAL, &healValue, NULL, NULL, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_spoils_of_pandaria_eminence_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:


        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_eminence_AuraScript();
        }
};

class spell_spoils_of_pandaria_massive_mogu_aoe : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_massive_mogu_aoe(const char* name, uint32 dmgSpellId) : SpellScriptLoader(name), _dmgSpellId(dmgSpellId) { }

        class spell_spoils_of_pandaria_massive_mogu_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_massive_mogu_aoe_SpellScript);

        public:

            spell_spoils_of_pandaria_massive_mogu_aoe_SpellScript(uint32 dmgSpellId) : SpellScript(), _dmgSpellId(dmgSpellId) { }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                Creature* pCreature = GetCaster()->ToCreature();
                if (!pCreature)
                    return;

                SpoilsOfPandariaRooms room = (SpoilsOfPandariaRooms)pCreature->AI()->GetData(DATA_MOB_ROOM);

                PlayerInRoomTargetCheck check(pCreature, 0.0f, room);

                std::list<Player*> players;
                GetCaster()->GetPlayerListInGrid(players, 50.0f);

                int32 l_Damage = 150000;
                switch (pCreature->GetMap()->GetDifficultyID())
                {
                    case Difficulty::DIFFICULTY_25_N: l_Damage = 165000; break;
                    case Difficulty::DIFFICULTY_10_HC: l_Damage = 300000; break;
                    case Difficulty::DIFFICULTY_25_HC: l_Damage = 301000; break;
                }

                for (auto l_Player : players)
                {
                    if (!check(l_Player))
                        continue;

                    pCreature->CastCustomSpell(_dmgSpellId, SpellValueMod::SPELLVALUE_BASE_POINT0, l_Damage, l_Player, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_massive_mogu_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            uint32 _dmgSpellId;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_massive_mogu_aoe_SpellScript(_dmgSpellId);
        }

    private:

        uint32 _dmgSpellId;

};

class spell_spoils_of_pandaria_unstable_spark : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_unstable_spark() : SpellScriptLoader("spell_spoils_of_pandaria_unstable_spark") { }

        class spell_spoils_of_pandaria_unstable_spark_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_unstable_spark_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                // the caster is 'spoils of pandaria mob', he will be despawned in 10 secs after death
                if (!GetCaster())
                    return;

                if (Creature* pSpoils = GetSpoilsOfPandaria(GetCaster()))
                {
                    WorldLocation summonPos = *GetExplTargetDest();

                    pSpoils->CastSpell(summonPos.GetPositionX(), summonPos.GetPositionY(), summonPos.GetPositionZ(), SPELL_UNSTABLE_SPARK_SUMMON, true);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_spoils_of_pandaria_unstable_spark_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_unstable_spark_SpellScript();
        }
};

class spell_spoils_of_pandaria_blade_of_the_thousand_steps : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_blade_of_the_thousand_steps() : SpellScriptLoader("spell_spoils_of_pandaria_blade_of_the_thousand_steps") { }

        class spell_spoils_of_pandaria_blade_of_the_thousand_steps_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_blade_of_the_thousand_steps_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* l_Caster = eventInfo.GetActor();
                Unit* l_Target = eventInfo.GetActionTarget();

                if (!l_Caster || !l_Target)
                    return;

                l_Caster->CastSpell(l_Target, Spells::SPELL_BLADE_OF_THE_HUNDRED_STEPS_DMG, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_spoils_of_pandaria_blade_of_the_thousand_steps_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_blade_of_the_thousand_steps_AuraScript();
        }
};

class spell_spoils_of_pandaria_gusting_bomb : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_gusting_bomb() : SpellScriptLoader("spell_spoils_of_pandaria_gusting_bomb") { }

        class spell_spoils_of_pandaria_gusting_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_gusting_bomb_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                if (Creature* l_Creature = GetCaster()->ToCreature())
                {
                    SpoilsOfPandariaRooms l_Room = (SpoilsOfPandariaRooms)l_Creature->AI()->GetData(DATA_MOB_ROOM);

                    if (Unit* l_Target = l_Creature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(l_Creature, 0.0f, l_Room)))
                    {
                        l_Creature->CastSpell(l_Target, Spells::SPELL_GUSTING_BOMB_DMG_2, true);
                        l_Creature->AI()->SetGUID(l_Target->GetGUID());
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_gusting_bomb_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_gusting_bomb_SpellScript();
        }
};

class spell_spoils_of_pandaria_gusting_bomb_periodic : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_gusting_bomb_periodic() : SpellScriptLoader("spell_spoils_of_pandaria_gusting_bomb_periodic") { }

        class spell_spoils_of_pandaria_gusting_bomb_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_gusting_bomb_periodic_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                GetCaster()->CastSpell(GetUnitOwner(), Spells::SPELL_GUSTING_BOMB_DMG_1, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_gusting_bomb_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_gusting_bomb_periodic_AuraScript();
        }
};

class spell_spoils_of_pandaria_spark_of_life_periodic: public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_spark_of_life_periodic() : SpellScriptLoader("spell_spoils_of_pandaria_spark_of_life_periodic") { }

        class spell_spoils_of_pandaria_spark_of_life_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_spark_of_life_periodic_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                Unit* l_Owner = GetUnitOwner();
                if (!l_Owner)
                    return;

                PreventDefaultAction();

                const float l_Radius = 5.f;
                const float l_Angle = frand(0.f, 2.f * float(M_PI));

                Position l_Pos;
                l_Pos.m_positionX = l_Owner->GetPositionX() + (l_Owner->GetObjectSize() + l_Radius) * std::cos(l_Angle);
                l_Pos.m_positionY = l_Owner->GetPositionY() + (l_Owner->GetObjectSize() + l_Radius) * std::sin(l_Angle);
                l_Pos.m_positionZ = l_Owner->GetPositionZ();

                l_Owner->CastSpell(l_Pos, Spells::SPELL_SPARK_OF_LIFE_MISSILE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_spark_of_life_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_spark_of_life_periodic_AuraScript();
        }
};

class spell_spoils_of_pandaria_spark_of_life_missile : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_spark_of_life_missile() : SpellScriptLoader("spell_spoils_of_pandaria_spark_of_life_missile") { }

        class spell_spoils_of_pandaria_spark_of_life_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_spark_of_life_missile_SpellScript);

            void HandleHit(SpellEffIndex p_EffIndex)
            {
                PreventHitDefaultEffect(p_EffIndex);

                Unit* l_Caster = GetCaster();
                if (!l_Caster || !l_Caster->IsInCombat())
                    return;

                if (WorldLocation const* l_DestLoc = GetExplTargetDest())
                {
                    l_Caster->SummonCreature(Adds::NPC_SPARK_OF_LIFE, l_DestLoc->GetPositionX(), l_DestLoc->GetPositionY(), l_DestLoc->GetPositionZ(), TempSummonType::TEMPSUMMON_CORPSE_DESPAWN);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_spoils_of_pandaria_spark_of_life_missile_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_spark_of_life_missile_SpellScript();
        }
};

class spell_spoils_of_pandaria_harden_flesh : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_harden_flesh() : SpellScriptLoader("spell_spoils_of_pandaria_harden_flesh") { }

        class spell_spoils_of_pandaria_harden_flesh_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_harden_flesh_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    SpoilsOfPandariaRooms room = (SpoilsOfPandariaRooms)l_Creature->AI()->GetData(DATA_MOB_ROOM);

                    if (Unit* l_Target = l_Creature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(l_Caster, 0.0f, room)))
                    {
                        l_Caster->CastSpell(l_Target, Spells::SPELL_HARDEN_FLESH_DMG, true);
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_harden_flesh_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_harden_flesh_SpellScript();
        }
};

class spell_spoils_of_pandaria_torment : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_torment() : SpellScriptLoader("spell_spoils_of_pandaria_torment") { }

        class spell_spoils_of_pandaria_torment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_torment_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    SpoilsOfPandariaRooms room = (SpoilsOfPandariaRooms)l_Creature->AI()->GetData(DATA_MOB_ROOM);

                    if (Unit* l_Target = l_Creature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(l_Caster, 0.0f, room)))
                    {
                        l_Caster->CastSpell(l_Target, Spells::SPELL_TORMENT_DUMMY, true);
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_torment_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_torment_SpellScript();
        }
};

class spell_spoils_of_pandaria_torment_dummy : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_torment_dummy() : SpellScriptLoader("spell_spoils_of_pandaria_torment_dummy") { }

        class spell_spoils_of_pandaria_torment_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_torment_dummy_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit* l_OriginalCaster = GetOriginalCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_OriginalCaster || !l_Target)
                    return;

                l_OriginalCaster->CastSpell(l_Target, Spells::SPELL_TORMENT_DMG, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_torment_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_torment_dummy_SpellScript();
        }
};

class spell_spoils_of_pandaria_torment_dmg : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_torment_dmg() : SpellScriptLoader("spell_spoils_of_pandaria_torment_dmg") { }

        class spell_spoils_of_pandaria_torment_dmg_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_torment_dmg_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetUnitOwner();
                if (!l_Caster || !l_Target || !l_Caster->IsInCombat() || !l_Target->IsInCombat())
                {
                    Remove();
                    return;
                }

                int32 l_Damage = aurEff->GetAmount() * aurEff->GetTickNumber();

                SpellNonMeleeDamage l_DamageInfo(l_Caster, l_Target, this->GetId(), Spells::SPELL_TORMENT_DMG, SpellSchoolMask::SPELL_SCHOOL_MASK_SHADOW);
                l_DamageInfo.damage = l_Damage;
                l_Caster->SendSpellNonMeleeDamageLog(&l_DamageInfo);
                l_Caster->DealSpellDamage(&l_DamageInfo, false);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetUnitOwner();
                if (!l_Caster || !l_Target || !l_Caster->IsInCombat() || !l_Target->IsInCombat())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                {
                    SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Target);

                    if (Creature* l_Creature = l_Caster->ToCreature())
                    {
                        if (Unit* l_NewTarget = l_Creature->AI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(l_Creature, 0.0f, l_Room, l_Target)))
                        {
                            l_Target->CastSpell(l_NewTarget, Spells::SPELL_TORMENT_DUMMY, true, nullptr, nullptr, l_Caster->GetGUID());
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_torment_dmg_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_spoils_of_pandaria_torment_dmg_AuraScript::HandleRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_torment_dmg_AuraScript();
        }
};

class spell_spoils_of_pandaria_mogu_rune_of_power : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_mogu_rune_of_power() : SpellScriptLoader("spell_spoils_of_pandaria_mogu_rune_of_power") { }

        class spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript);

            void FilterTargets(std::list<WorldObject*>& l_Targets)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                {
                    l_Targets.clear();
                    return;
                }

                SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Caster);

                l_Targets.remove_if([l_Caster, l_Room](WorldObject* l_Target)
                {
                    if (RoomChecker::GetRoomForObject(l_Target) != l_Room)
                        return true;

                    if (l_Target == l_Caster)
                        return true;

                    return false;
                });

                if (l_Targets.empty())
                    l_Targets.push_back(l_Caster);

                if (l_Targets.size() > 1)
                    Trinity::Containers::RandomResize(l_Targets, 1);
            }

            //void HandleDummy(SpellEffIndex effIndex)
            void DoEffectHitTarget(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                l_Caster->CastSpell(l_Target, Spells::SPELL_MOGU_RUNE_OF_POWER_AREATRIGGER, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript::FilterTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ALLY);
               // OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript::DoEffectHitTarget, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_mogu_rune_of_power_SpellScript();
        }
};

class spell_spoils_of_pandaria_crimson_reconstitution : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_crimson_reconstitution() : SpellScriptLoader("spell_spoils_of_pandaria_crimson_reconstitution") { }

        class spell_spoils_of_pandaria_crimson_reconstitution_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_crimson_reconstitution_SpellScript);

            void FilterTargets(std::list<WorldObject*>& l_Targets)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                {
                    l_Targets.clear();
                    return;
                }

                SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Caster);

                l_Targets.remove_if([l_Caster, l_Room](WorldObject* l_Target)
                {
                    if (RoomChecker::GetRoomForObject(l_Target) != l_Room)
                        return true;

                    if (l_Target == l_Caster)
                        return true;

                    return false;
                });

                if (l_Targets.empty())
                    l_Targets.push_back(l_Caster);

                if (l_Targets.size() > 1)
                    Trinity::Containers::RandomResize(l_Targets, 1);
            }

            //void HandleDummy(SpellEffIndex effIndex)
            void DoEffectHitTarget(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                l_Caster->CastSpell(l_Target, Spells::SPELL_CRIMSON_RECONSTITUTION_AREATRIGGER, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spoils_of_pandaria_crimson_reconstitution_SpellScript::FilterTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ALLY);
                //OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_crimson_reconstitution_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_crimson_reconstitution_SpellScript::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_crimson_reconstitution_SpellScript();
        }
};

class spell_spoils_of_pandaria_matter_scramble : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_matter_scramble() : SpellScriptLoader("spell_spoils_of_pandaria_matter_scramble") { }

        class spell_spoils_of_pandaria_matter_scramble_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_matter_scramble_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                Unit* l_Caster = GetCaster();

                if (!l_Caster || !l_Caster->IsInCombat())
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Creature);

                    const uint32 l_TargetsCount = 2;

                    std::list<Unit*> l_Targets;
                    l_Creature->AI()->SelectTargetList(l_Targets, PlayerInRoomTargetCheck(l_Creature, 0.0f, l_Room), l_TargetsCount, SelectAggroTarget::SELECT_TARGET_RANDOM);

                    uint32 l_NoTargetsCount = l_Targets.size() >= l_TargetsCount ? 0 : l_TargetsCount - l_Targets.size();
                    if (l_NoTargetsCount > l_TargetsCount)
                        l_NoTargetsCount = l_TargetsCount;

                    l_Creature->AI()->SetData(eDatas::DATA_MATTER_SCRAMBLE_COUNT, l_Targets.size());

                    for (auto l_Target : l_Targets)
                    {
                        l_Creature->CastSpell(l_Target, Spells::SPELL_MATTER_SCRAMBLE_AOE, true);
                    }

                    if (l_NoTargetsCount > 0)
                    {
                        for (uint32 i = 0; i < l_NoTargetsCount; ++i)
                            l_Creature->CastSpell(l_Creature, Spells::SPELL_MATTER_SCRAMBLE_DMG, true);
                    }
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spoils_of_pandaria_matter_scramble_AuraScript::HandleRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_matter_scramble_AuraScript();
        }
};

class spell_spoils_of_pandaria_matter_scramble_dummy : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_matter_scramble_dummy() : SpellScriptLoader("spell_spoils_of_pandaria_matter_scramble_dummy") { }

        class spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& l_Targets)
            {
                Trinity::Containers::RandomResize(l_Targets, 1);
            }

            void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    m_HasTarget = true;
                    l_Creature->AI()->SetGUID(l_Target->GetGUID(), eDatas::DATA_MATTER_SCRAMBLE_GUID);
                }
            }

            void HandleAfterHit()
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                if (m_HasTarget)
                    return;

                if (WorldLocation const* l_Loc = GetHitDest())
                {
                    l_Caster->CastSpell(*l_Loc, Spells::SPELL_MATTER_SCRAMBLE_DMG, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript::FilterTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_DEST_AREA_ENEMY);
                //OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript::DoEffectHitTarget, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
                AfterHit += SpellHitFn(spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript::HandleAfterHit);
            }

        private:

            bool m_HasTarget = false;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_matter_scramble_dummy_SpellScript();
        }
};

class spell_spoils_of_pandaria_pheromone_cloud : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_pheromone_cloud() : SpellScriptLoader("spell_spoils_of_pandaria_pheromone_cloud") { }

        class spell_spoils_of_pandaria_pheromone_cloud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_pheromone_cloud_AuraScript);

            void HandlePeriodic(AuraEffect const* p_AurEff)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Creature);

                    const uint32 l_TargetsCount = 25;

                    std::list<Unit*> l_Targets;
                    l_Creature->AI()->SelectTargetList(l_Targets, PlayerInRoomTargetCheck(l_Creature, 0.0f, l_Room), l_TargetsCount, SelectAggroTarget::SELECT_TARGET_RANDOM);

                    for (auto l_Target : l_Targets)
                    {
                        l_Creature->CastSpell(l_Target, Spells::SPELL_PHEROMONE_CLOUD_DMG, true);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_pheromone_cloud_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_pheromone_cloud_AuraScript();
        }
};

class spell_spoils_of_pandaria_return_to_stone : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_return_to_stone() : SpellScriptLoader("spell_spoils_of_pandaria_return_to_stone") { }

        class spell_spoils_of_pandaria_return_to_stone_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_return_to_stone_SpellScript);

            //void HandleDummy(SpellEffIndex effIndex)
            void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                if (Creature* l_Creature = l_Caster->ToCreature())
                {
                    SpoilsOfPandariaRooms l_Room = RoomChecker::GetRoomForObject(l_Creature);

                    if (Unit* l_Target = l_Creature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, PlayerInRoomTargetCheck(l_Creature, 0.0f, l_Room)))
                        l_Creature->CastSpell(l_Target, Spells::SPELL_RETURN_TO_STONE_DMG, true);
                }
            }

            void Register()
            {
                //OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_return_to_stone_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_return_to_stone_SpellScript::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);

            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_return_to_stone_SpellScript();
        }
};

class spell_spoils_of_pandaria_return_to_stone_dmg : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_return_to_stone_dmg() : SpellScriptLoader("spell_spoils_of_pandaria_return_to_stone_dmg") { }

        class spell_spoils_of_pandaria_return_to_stone_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spoils_of_pandaria_return_to_stone_SpellScript);

            //void HandleHitTarget(SpellEffIndex effIndex)
            void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                l_Caster->SummonCreature(Adds::NPC_STONE_STATUE, *l_Target);
            }

            void Register()
            {
                //OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_return_to_stone_SpellScript::HandleHitTarget, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_spoils_of_pandaria_return_to_stone_SpellScript::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_spoils_of_pandaria_return_to_stone_SpellScript();
        }
};

class spell_spoils_of_pandaria_strength_of_the_stone : public SpellScriptLoader
{
    public:
        spell_spoils_of_pandaria_strength_of_the_stone() : SpellScriptLoader("spell_spoils_of_pandaria_strength_of_the_stone") { }

        class spell_spoils_of_pandaria_strength_of_the_stone_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spoils_of_pandaria_strength_of_the_stone_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                if (Creature* l_Creature = GetUnitOwner()->ToCreature())
                {
                    uint32 l_Count = l_Creature->AI()->GetData(Datas::DATA_STONE_STATUE_COUNT);
                    if (l_Count > 0)
                    {
                        uint32 l_Amount = l_Count * 10;
                        if (AuraEffect* l_AurEff = GetAura()->GetEffect(SpellEffIndex::EFFECT_0))
                        {
                            if (l_AurEff->GetAmount() != l_Amount)
                                l_AurEff->ChangeAmount(l_Amount);
                        }
                    }
                    else
                    {
                        Remove();
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_spoils_of_pandaria_strength_of_the_stone_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spoils_of_pandaria_strength_of_the_stone_AuraScript();
        }
};

struct spell_area_spoils_of_pandaria_unstable_defense_systems : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_unstable_defense_systems(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        at->GetCaster()->AddAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_PERIODIC, target);

        return;
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_UNSTABLE_DEFENSE_SYSTEMS_PERIODIC);
    }
};

struct spell_area_spoils_of_pandaria_path_of_blossoms : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_path_of_blossoms(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        // Enable after few seconds
        if (at->GetDuration() > (at->GetTotalDuration() - TIMER_PATH_OF_BLOSSOMS_EXPLODE))
        {
            return;
        }

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        if (at->GetDuration() > 0)
        {
            caster->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_PATH_OF_BLOSSOMS_DMG, true);
            at->SetDuration(0);
        }
    }
};

struct spell_area_spoils_of_pandaria_gusting_crane_kick : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_gusting_crane_kick(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUpdate(uint32 p_Diff) override
    {
        if (m_UpdateTimer <= p_Diff)
        {
            m_UpdateTimer = 1 * IN_MILLISECONDS;

            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_GUSTING_CRANE_KICK_DMG, true);
            caster->CastSpell(caster, SPELL_GUSTING_CRANE_KICK_VISUAL, true);
        }
        else
        {
            m_UpdateTimer -= p_Diff;
        }
    }

private:

    uint32 m_UpdateTimer = 100;
};

struct spell_area_spoils_of_pandaria_set_to_blow : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_set_to_blow(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        // Enable after few seconds
        if (at->GetDuration() > (at->GetTotalDuration() - TIMER_SET_TO_BLOW_EXPLODE))
        {
            return;
        }

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->IsPlayer())
            return;

        if (at->GetDuration() > 0)
        {
            caster->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_SET_TO_BLOW_DMG, true);
            at->SetDuration(0);
        }

        return;
    }

    void OnRemove()
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), SPELL_SET_TO_BLOW_DMG, true);

        ExplodeOtherBombs(at);
    }

private:

    void ExplodeOtherBombs(AreaTrigger* searcher)
    {
        std::list<AreaTrigger*> areaTriggers;
        //searcher->GetAreaTriggerListInGrid(areaTriggers, SPELL_SET_TO_BLOW_AREATRIGGER, 9.0f);
        areaTriggers = searcher->SelectNearestAreaTriggers(SPELL_SET_TO_BLOW_AREATRIGGER, 9.0f);

        areaTriggers.remove(searcher);

        for (auto otherTrigger : areaTriggers)
        {
            if (otherTrigger->GetDuration() > 0)
                otherTrigger->SetDuration(0);
        }
    }

};

struct spell_area_spoils_of_pandaria_windstorm : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_windstorm(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        // Enable after few seconds
        if (at->GetDuration() > (at->GetTotalDuration() - TIMER_SET_TO_BLOW_EXPLODE))
        {
            return;
        }

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        caster->CastSpell(target, SPELL_WINDSTORM_DMG, true);
    }
};

struct spell_area_spoils_of_pandaria_encapsulated_pheromones : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_encapsulated_pheromones(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        at->GetCaster()->AddAura(SPELL_ENCAPSULATED_PHEROMONES_AURA, target);

        return;
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_ENCAPSULATED_PHEROMONES_AURA);
        return;
    }
};

struct spell_area_spoils_of_pandaria_staff_of_resonating_water : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_staff_of_resonating_water(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        Position l_Dest;
        l_Caster->GetNearPoint2D(l_Dest.m_positionX, l_Dest.m_positionY, 40.f, l_Caster->GetOrientation());
        l_Dest.m_positionZ = l_Caster->GetPositionZ();

        at->Relocate(*l_Caster);
        //trigger->SetSource(*l_Caster);

        at->SetDestination(l_Dest, 0);
        //trigger->SetTrajectory(AreatriggerInterpolation::AREATRIGGER_INTERPOLATION_LINEAR);
    }

    void OnUnitEnter(Unit* target)
    {
        if (at->GetDuration() == 0)
            return;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        if (l_Caster == target)
            return;

        if (RoomChecker::GetRoomForObject(l_Caster) != RoomChecker::GetRoomForObject(target))
            return;

        bool l_IsEmpty = false;

        if (l_Caster->IsFriendlyTo(target))
        {
            if (!target->IsFullHealth())
            {
                float l_MissingHealthPct = 100.f - target->GetHealthPct();
                int32 l_Heal = 0;
                if (m_WavePower > l_MissingHealthPct)
                {
                    l_Heal = target->CountPctFromMaxHealth((int32)l_MissingHealthPct);
                    m_WavePower -= l_MissingHealthPct;
                }
                else
                {
                    l_Heal = target->CountPctFromMaxHealth((int32)m_WavePower);
                    l_IsEmpty = true;
                }

                l_Caster->CastCustomSpell(Spells::SPELL_STAFF_OF_RESONATING_WATER_HEAL, SpellValueMod::SPELLVALUE_BASE_POINT0, l_Heal, target, true);
            }
        }
        else
        {
            if (target->isTargetableForAttack())
            {
                l_Caster->CastSpell(target, Spells::SPELL_STAFF_OF_RESONATING_WATER_DMG, true);
            }
        }

        if (l_IsEmpty || m_WavePower == 0.f)
        {
            at->SetDuration(0);
        }

        return;
    }

private:

    float m_WavePower = 100.f;
};

struct spell_area_spoils_of_pandaria_gusting_bomb : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_gusting_bomb(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        if (target->IsPlayer())
        {
            l_Caster->AddAura(Spells::SPELL_GUSTING_BOMB_PERIODIC, target);
        }
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(Spells::SPELL_GUSTING_BOMB_PERIODIC);
    }
};

struct spell_area_spoils_of_pandaria_mogu_rune_of_power : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_mogu_rune_of_power(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster || !l_Caster->IsInCombat())
            return;

        l_Caster->AddAura(Spells::SPELL_MOGU_RUNE_OF_POWER_AURA, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(Spells::SPELL_MOGU_RUNE_OF_POWER_AURA);
    }
};


struct spell_area_spoils_of_pandaria_crimson_reconstitution : AreaTriggerAI
{
    spell_area_spoils_of_pandaria_crimson_reconstitution(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster || !l_Caster->IsInCombat())
            return;

        if (!l_Caster->IsFriendlyTo(target))
            return;

        l_Caster->AddAura(Spells::SPELL_CRIMSON_RECONSTITUTION_HEAL, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(Spells::SPELL_CRIMSON_RECONSTITUTION_HEAL);
    }

    void OnUpdate(uint32 p_Diff) override
    {
        if (m_UpdateTimer <= p_Diff)
        {
            m_UpdateTimer = 1 * IN_MILLISECONDS;

            Unit* l_Caster = at->GetCaster();
            if (!l_Caster || !l_Caster->IsInCombat())
                return;

            if (!CheckAcid(l_Caster, at))
                return;

            DealAcidDamage(l_Caster);
        }
        else
        {
            m_UpdateTimer -= p_Diff;
        }
    }

private:

    bool CheckAcid(Unit* p_Caster, AreaTrigger* p_AreaTrigger)
    {
        if (m_IsAcid)
            return true;

        if (Creature* l_Creature = p_Caster->ToCreature())
            if (auto l_GolemAI = CAST_AI(npc_spoils_of_pandaria_modified_anima_golem::npc_spoils_of_pandaria_modified_anima_golemAI, l_Creature->GetAI()))
                if (l_GolemAI->IsAcidAreaTrigger(p_AreaTrigger->GetGUID()))
                {
                    m_IsAcid = true;
                    return true;
                }

        return false;
    }

    void DealAcidDamage(Unit* p_Caster)
    {
        const float l_Radius = 2.f;
        std::list<Unit*> l_Targets;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(p_Caster, p_Caster, l_Radius);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(p_Caster, l_Targets, u_check);
        //p_Caster->VisitNearbyObject(l_Radius, searcher);
        Cell::VisitWorldObjects(p_Caster, searcher, l_Radius);

        const int32 l_Damage = 50000;

        for (auto l_Target : l_Targets)
        {
            SpellNonMeleeDamage l_DamageInfo(p_Caster, l_Target, /*todo check this*/0, Spells::SPELL_CRIMSON_ACID, SpellSchoolMask::SPELL_SCHOOL_MASK_FIRE);
            l_DamageInfo.damage = l_Damage;
            p_Caster->SendSpellNonMeleeDamageLog(&l_DamageInfo);
            p_Caster->DealSpellDamage(&l_DamageInfo, false);
        }
    }

private:

    uint32 m_UpdateTimer = 100;
    bool m_IsAcid = false;
};

void AddSC_boss_spoils_of_pandaria()
{
    new npc_secured_stockpile_of_pandaren_spoils();         // 71889
    new npc_spoils_of_pandaria_lift_hook();                 // 72972
    new npc_spoils_of_pandaria_unstable_spark();            // 73104
    new npc_spoils_of_pandaria_animated_stone_mogu();       // 71380
    new npc_spoils_of_pandaria_burial_urn();                // 71382
    new npc_spoils_of_pandaria_spark_of_life();             // 71433
    new npc_spoils_of_pandaria_quilen_guardian();           // 71378
    new npc_spoils_of_pandaria_quilen_guardians();          // 72223
    new npc_spoils_of_pandaria_mogu_shadow_ritualist();     // 71393
    new npc_spoils_of_pandaria_modified_anima_golem();      // 71395
    new npc_spoils_of_pandaria_jun_wei();                   // 73723
    new npc_spoils_of_pandaria_zu_yin();                    // 73724
    new npc_spoils_of_pandaria_xiang_lin();                 // 73725
    new npc_spoils_of_pandaria_kun_da();                    // 71408
    new npc_spoils_of_pandaria_stone_statue();              // 72535
    new npc_spoils_of_pandaria_srithik_bombardier();        // 71385
    new npc_spoils_of_pandaria_amber_encased_kunchong();    // 71388
    new npc_spoils_of_pandaria_korthik_warcaller();         // 71383
    new npc_spoils_of_pandaria_zarthik_amber_priest();      // 71397
    new npc_spoils_of_pandaria_setthik_wind_wielder();      // 71405
    new npc_spoils_of_pandaria_mantid_commander();          // 73948, 73949, 73951, 71409
    new npc_spoils_of_pandaria_ancient_brewmaster_spirit(); // 71427
    new npc_spoils_of_pandaria_wise_mistweaver_spirit();    // 71428
    new npc_spoils_of_pandaria_nameless_windwalker_spirit();// 71430

    new go_spoils_of_pandaria_stockpile();                  // 220823
    new go_spoils_of_pandaria_lever();                      // 221771, 221773, 221772, 221774

    new spell_spoils_of_pandaria_breaking();                // 144229
    new spell_spoils_of_pandaria_unstable_defense_systems_dmg();    // 145685
    new spell_spoils_of_pandaria_mantid_swarm();            // 142539
    new spell_spoils_of_pandaria_residue();                 // 145786
    new spell_spoils_of_pandaria_rage_of_the_empress();     // 145812
    new spell_spoils_of_pandaria_set_to_blow();             // 145996
    new spell_spoils_of_pandaria_set_to_blow_override();    // 145987
    new spell_spoils_of_pandaria_throw_bomb();              // 146364
    new spell_spoils_of_pandaria_breath_of_fire();          // 146222
    new spell_spoils_of_pandaria_eminence();                // 146189
    new spell_spoils_of_pandaria_massive_mogu_aoe("spell_spoils_of_pandaria_shadow_volley", SPELL_SHADOW_VOLLEY_DMG);   // 148515
    new spell_spoils_of_pandaria_massive_mogu_aoe("spell_spoils_of_pandaria_molten_fist", SPELL_MOLTEN_FIST_DMG);       // 148518
    new spell_spoils_of_pandaria_massive_mogu_aoe("spell_spoils_of_pandaria_jade_tempest", SPELL_JADE_TEMPEST_DMG);     // 148582
    new spell_spoils_of_pandaria_massive_mogu_aoe("spell_spoils_of_pandaria_fracture", SPELL_FRACTURE_DMG);             // 148513
    new spell_spoils_of_pandaria_unstable_spark();          // 146824
    new spell_spoils_of_pandaria_blade_of_the_thousand_steps(); // 146068
    new spell_spoils_of_pandaria_gusting_bomb();            // 145712
    new spell_spoils_of_pandaria_gusting_bomb_periodic();   // 145715
    new spell_spoils_of_pandaria_spark_of_life_periodic();  // 142694
    new spell_spoils_of_pandaria_spark_of_life_missile();   // 142695
    new spell_spoils_of_pandaria_harden_flesh();            // 144922
    new spell_spoils_of_pandaria_torment();                 // 142934
    new spell_spoils_of_pandaria_torment_dummy();           // 142942
    new spell_spoils_of_pandaria_torment_dmg();             // 142983
    new spell_spoils_of_pandaria_mogu_rune_of_power();      // 145461
    new spell_spoils_of_pandaria_crimson_reconstitution();  // 142947
    new spell_spoils_of_pandaria_matter_scramble();         // 145288
    new spell_spoils_of_pandaria_matter_scramble_dummy();   // 145369
    new spell_spoils_of_pandaria_pheromone_cloud();         // 148762
    new spell_spoils_of_pandaria_return_to_stone();         // 145489
    new spell_spoils_of_pandaria_return_to_stone_dmg();     // 145514
    new spell_spoils_of_pandaria_strength_of_the_stone();   // 145998

    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_unstable_defense_systems);   // 145687
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_path_of_blossoms);           // 146255
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_gusting_crane_kick);         // 146180
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_set_to_blow);                // 146365
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_windstorm);                  // 145286
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_encapsulated_pheromones);    // 145285
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_staff_of_resonating_water);  // 146098
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_gusting_bomb);               // 145714
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_mogu_rune_of_power);         // 145460
    RegisterAreaTriggerAI(spell_area_spoils_of_pandaria_crimson_reconstitution);     // 145270
}
