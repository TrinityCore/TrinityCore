#include "siege_of_orgrimmar.hpp"
#include "Vehicle.h"
#include "MovementGenerator.h"
#include "MoveSplineInit.h"
#include "SpellMgr.h"

// todo implement movement forces

enum ScriptedTexts
{
    SAY_AGGRO               = 0,
    SAY_DEATH_1             = 1,
    SAY_DEATH_2             = 2,
    SAY_WEAPON_DESTROYED    = 4,
    SAY_SHREDDER            = 11,
    SAY_KILL                = 16,
    SAY_LASER               = 19,
    SAY_MAGNET              = 20,
    SAY_OVERCHARGED_MINES   = 21,
    SAY_MINES               = 22,
    SAY_MISSILE             = 23,
    SAY_CONVEYOR_EMOTE      = 24,
    SAY_SHREDDER_EMOTE      = 25,
};

enum Spells
{
    // Pipe transfer
    SPELL_PIPE_TRANSFER             = 143738, // removes crawler mines fixate
    SPELL_PIPE_TRANSFER_TRANSITION  = 143758, // teleports to the conveyor, applies 144236
    SPELL_PIPE_TRANSFER_EJECTION    = 143797, // teleports to ejection (?)
    SPELL_PIPE_TRANSFER_TO_ENTRANCE = 145223, // teleports to entrance (?)
    SPELL_PIPE_TRANSFER_TO_EXIT     = 145237, // teleports to exit (?)
    //SPELL_PIPE_TRANSFER           = , // teleports to (?)
    SPELL_PIPE_TRANSFER_JUMP        = 143798,
    SPELL_PIPE_TRANSFER_FALL        = 145224, // applies when player teleports to the conveyor
    SPELL_PIPE_TRANSFER_FALL_2      = 145238, // applies when player teleports to the conveyor

    SPELL_PATTERN_RECOGNITION       = 144236,

    // The boss

    SPELL_MAGNETIC_LASSO            = 145351,
    SPELL_MAGNETIC_LASSO_JUMP       = 145358, // to pull player back to the platform

    SPELL_TELEPORT_FORCE            = 149427, // ? in sniffs
    SPELL_TELEPORT                  = 149426, // ? in sniffs

    SPELL_LOAD_SAWBLADE             = 143264,
    SPELL_LAUNCH_SAWBLADE           = 143265,
    SPELL_LAUNCH_SAWBLADE_JUMP      = 143266,
    SPELL_LAUNCH_SAWBLADE_AOE       = 143291, // targets player
    SPELL_LAUNCH_SAWBLADE_AURA      = 143329, // casted by sawblade on self by 143265
    SPELL_LAUNCH_SAWBLADE_REMOVE    = 144028,

    SPELL_SERRATED_SLASH_DMG        = 143328, // damages shredders
    SPELL_SERRATED_SLASH_MARK       = 145381,
    SPELL_SERRATED_SLASH_KNOCKBACK  = 143327, // damages players
    SPELL_SERRATED_SLASH_REMOVE     = 145370, // removes 143327

    SPELL_PROTECTIVE_FRENZY         = 145365,

    SPELL_ELECTROSTATIC_CHARGE      = 143385,

    SPELL_AUTOMATIC_REPAIR_BEAM_MARK_1  = 144212, // on caster
    SPELL_AUTOMATIC_REPAIR_BEAM_HEAL    = 144213,
    SPELL_AUTOMATIC_REPAIR_BEAM_MARK_2  = 145701, // not used in sniffs

    SPELL_ENERGIZED_DEFENSIVE_MATRIX    = 148990,

    // Laser Array Bunny
    SPELL_CONVEYOR_DEATH_BEAM_DUMMY     = 144284,
    SPELL_CONVEYOR_DEATH_BEAM_AREATRIGGER   = 144282,
    SPELL_MATTER_PURIFICATION_BEAM  = 144335,

    // Laser Array Target Vehicle
    SPELL_RELAY_CLOSE_PIPE_HANDLER      = 148779,

    // Steam Vent
    SPELL_STEAM_VENT                    = 145209,

    // Conveyor
    SPELL_ON_PLATFORM                   = 145480,
    SPELL_ON_CONVEYOR                   = 144287,
    SPELL_CREATE_CONVEYOR_TRIGGER       = 145272, // 2033.77 -5563.46 -266.2

    // Siege Engineer Helper
    SPELL_SIEGE_ENGINEER_HELPER_PERIODIC    = 143531,
    SPELL_OPEN_PIPE_HANDLER                 = 143485,
    SPELL_CLOSE_PIPE_HANDLER                = 144242,

    SPELL_SUMMON_DEACTIVATED_TURRET_VEHICLE = 143528,  // 1962.337 -5452.712 -303.1317
    SPELL_SUMMON_DEACTIVATED_ROCKET_TURRET  = 143526, // 1962.337 -5452.712 -303.1317
    SPELL_SUMMON_DISASSEMBLED_CRAWLER_MINE_VEHICLE  = 144012, // 1962.337 -5452.712 -303.1317
    SPELL_SUMMON_DEACTIVATED_LASER_TURRET   = 143263, // 1962.337 -5452.712 -303.1317
    SPELL_SUMMON_DEACTIVATED_MAGNET_TURRET  = 143936, // 1962.337 -5452.712 -303.1317

    SPELL_SUMMON_ACTIVATED_TURRET_VEHICLE   = 143560, // 1935.752 -5739.543 -302.998
    SPELL_SUMMON_ACTIVATED_TURRET_PLACEHOLDER   = 143565, // 1962.337 -5452.712 -303.1317
    SPELL_SUMMON_ACTIVATED_ROCKET_TURRET    = 143561, // 1935.752 -5739.543 -302.998
    SPELL_SUMMON_ACTIVATED_CRAWLER_MINE_CONTROLLER  = 144011, // 1935.752 -5739.543 -302.998
    SPELL_SUMMON_ACTIVATED_MAGNET_TURRET    = 143938,
    SPELL_SUMMON_ACTIVATED_LASER_TURRET     = 143711,

    SPELL_ACTIVATED_TURRET_VEHICLE_FIRE_NOTIFICATION    = 143651,
    SPELL_ACTIVATED_LEAVE_HANDLER           = 143490,
    SPELL_DESPAWN_AREATRIGGERS              = 144200,
    SPELL_DESPAWN_PASSENGERS                = 143553, // by 71614 71751

    SPELL_TURRET_DEATH_PING                 = 144292, // by 71751
    SPELL_DEACTIVATED_TURRET_DEATH_REPORT   = 143558, // by 71751
    SPELL_TURRET_EXPLOSION                  = 144510, // by 71751

    SPELL_ELECTROMAGNETIC_BARRIER_DUMMY     = 146663,
    SPELL_ELECTROMAGNETIC_BARRIER_IMMUNITY  = 145154,

    // Automated Shredder
    SPELL_REACTIVE_ARMOR                = 143387,
    SPELL_DEATH_FROM_ABOVE              = 144208,
    SPELL_DEATH_FROM_ABOVE_MISSILE      = 147010,
    SPELL_DEATH_FROM_ABOVE_DMG          = 144210,
    SPELL_OVERLOAD                      = 145444,
    SPELL_AUTOMATED_SHREDDER_DEATH_NOTIFY   = 145453,

    // Laser Turret
    SPELL_LOCKED_ON                     = 143828,
    SPELL_LASER_GROUND_EFFECT_PERIODIC  = 143829,
    SPELL_LASER_GROUND_EFFECT           = 143830,
    SPELL_LASER_TURRET_TARGETTING_FORCE = 145906,
    SPELL_LASER_TURRET_TARGETTING_AOE   = 143833,
    SPELL_LASER_TURRET_TARGETTING_SUMMON     = 143838,
    SPELL_LASER_VISUAL_FORCECAST        = 143866,
    SPELL_DESINTEGRATION_LASER          = 143867, // visual ray
    SPELL_DESINTEGRATION_LASER_2        = 146680, // visual ray
    SPELL_SUPERHEATED_AURA              = 144040,
    SPELL_SUPERHEATED_DMG               = 143856,
    SPELL_SUPERHEATED_DUMMY             = 145347,

    // Crawler Mine
    SPELL_BREAK_IN_PERIOD               = 145269,
    SPELL_READY_TO_GO                   = 145580,
    SPELL_CRAWLER_MINE_JUMP             = 144008,
    SPELL_CRAWLER_MINE_FIXATE_TARGETTING    = 144009, // triggered by 144008
    SPELL_CRAWLER_MINE_FIXATE           = 144010,
    SPELL_DETONATE                      = 144026,
    SPELL_DETONATE_DMG                  = 143002,
    SPELL_BREAK_PLAYER_TARGETTING       = 140562, // in sniffs

    // Electromagnet
    SPELL_MAGNETIC_CRUSH                = 143487, // casted by electromagnet in normal mode
    SPELL_MAGNETIC_CRUSH_DMG            = 144466,
    SPELL_MAGNETIC_PULSE_SCRIPT         = 143357, // triggered by 143487, targets sawblade (I think)
    SPELL_MAGNETIC_PULSE_JUMP           = 143945, // casted by sawblade
    SPELL_MAGNETIC_PULSE_JUMP_2         = 143359, // triggered by 143945
    SPELL_MAGNETIC_CRUSH_PULL           = 147369, // casted by electromagnet in heroic mode. Periodic trigger for 147370 in 5 secs, but 147369 has 4.5 secs duration. Do it manually.
    SPELL_MAGNETIC_CRUSH_PUSH           = 147370, // casted by electromagnet in heroic mode. Periodic trigger for 147369 in 5 secs, but 147370 has 4.5 secs duration. Do it manually.
    SPELL_MAGNETIC_PULSE_SCRIPT_PULL    = 147458, // triggered by 147369, targets sawblade (I think) (heroic)
    SPELL_MAGNETIC_PULSE_JUMP_PULL      = 147459, // (heroic)
    SPELL_MAGNETIC_PULSE_SCRIPT_PUSH    = 147380, // triggered by 147370, targets sawblade (I think) (heroic)
    SPELL_MAGNETIC_PULSE_JUMP_PUSH      = 147379, // (heroic)


    // Shockwave Missile Turret
    SPELL_SHOCKWAVE_MISSILE             = 143639, // casted by turret
    SPELL_SHOCKWAVE_MISSILE_AOE         = 143642, // targettting
    SPELL_SHOCKWAVE_MISSILE_PERIODIC    = 146149, // triggers 146154 periodically (in heroic)
    SPELL_SHOCKWAVE_MISSILE_AOE_2       = 146154, // targettting (in heroic)
    SPELL_SHOCKWAVE_MISSILE_MISSILE     = 143640,
    SPELL_SHOCKWAVE_MISSILE_MISSILE_2   = 146153, // (in heroic)
    SPELL_SHOCKWAVE_MISSILE_SUMMON      = 143641,
    SPELL_SHOCKWAVE_MISSILE_SUMMON_2    = 146152, // (in heroic)
    SPELL_SHOCKWAVE_MISSILE_DMG_10      = 144658, // 10 yards
    SPELL_SHOCKWAVE_MISSILE_DMG_25      = 144660,
    SPELL_SHOCKWAVE_MISSILE_DMG_45      = 144661,
    SPELL_SHOCKWAVE_MISSILE_DMG_65      = 144662,
    SPELL_SHOCKWAVE_MISSILE_DMG_85      = 144663,
    SPELL_SHOCKWAVE_MISSILE_DMG_105     = 144664,
    SPELL_SHOCKWAVE_MISSILE_VISUAL_1    = 144647, // visual for shockwave missile
    SPELL_SHOCKWAVE_MISSILE_VISUAL_2    = 146155, // visual for overcharged shockwave missile
};

enum Adds
{
    NPC_SIEGECRAFTER_BLACKFUSE_GOBLIN   = 72694,
    NPC_SAWBLADE                        = 71532,

    NPC_AUTOMATED_SHREDDER              = 71591,

    NPC_SIEGE_ENGINEER_HELPER_BUNNY     = 71520, // for example, casts conveyor trigger

    NPC_STEAM_VENT_BUNNY                = 72345,
    NPC_LASER_ARRAY_BUNNY               = 71910,
    NPC_LASER_ARRAY_TARGET_VEHICLE      = 71912, // is transport for 71910

    NPC_DEACTIVATED_TURRET_VEHICLE      = 71614, // vehicle for 71606 71790 71751 71694
    NPC_DEACTIVATED_MISSILE_TURRET      = 71606,
    NPC_DISASSEMBLED_CRAWLER_MINES      = 71790,
    NPC_DEACTIVATED_LASER_TURRET        = 71751,
    NPC_DEACTIVATED_ELECTROMAGNET       = 71694,

    NPC_ACTIVATED_TURRET_VEHICLE        = 71637, // by 143560, vehicle for 72027 71795 71639 72015 71696
    NPC_ACTIVATED_TURRET_PLACEHOLDER    = 71639, // by 143565, spawns instead of killed weapon
    NPC_ACTIVATED_MISSILE_TURRET_BASE   = 72027, // by 143561, vehicle for 71638
    NPC_ACTIVATED_MISSILE_TURRET        = 71638,
    NPC_SHOCKWAVE_MISSILE               = 72052,
    NPC_ACTIVATED_CRAWLER_MINE_VEHICLE  = 71795, // by 144011, vehicle for 71788
    NPC_CRAWLER_MINE                    = 71788,
    NPC_ACTIVATED_ELECTROMAGNET         = 71696, // by 143938
    NPC_ACTIVATED_LASER_TURRET_BASE     = 72015, // by 143711, vehicle for 71752
    NPC_ACTIVATED_LASER_TURRET          = 71752,


    NPC_OVERCHARGED_MISSILE_TURRET      = 72831,
    NPC_OVERCHARGED_SHOCKWAVE_MISSILE   = 72832,
    NPC_OVERCHARGED_MISSILE_CASTER_STALKER  = 72834, // ?
    NPC_OVERCHARGED_CRAWLER_MINE        = 72668,
    NPC_OVERCHARGED_LASER_TURRET        = 72773,
    NPC_OVERCHARGED_ELECTROMAGNET       = 73387,

    NPC_LASER_TARGET_BUNNY              = 71740,
};

enum Events
{
    EVENT_ELECTROSTATIC_CHARGE      = 1,
    EVENT_LAUCH_SAWBLADE,
    EVENT_AUTOMATED_SHREDDER,
    EVENT_AUTOMATED_SHREDDER_REPAIR,
    EVENT_OVERLOAD,
    EVENT_DEATH_FROM_ABOVE,
    EVENT_SPAWN_DEACTIVATED_WEAPON,
    EVENT_SPAWN_ACTIVATED_WEAPON,
    EVENT_LASER_TURRET,
    EVENT_LASER_TARGET_TARGET,
    EVENT_LASER_TARGET_TARGET_STOP,
    EVENT_CRAWLER_MINE_PREPARE,
    EVENT_CRAWLER_MINE,
    EVENT_CRAWLER_MINE_START,
    EVENT_CRAWLER_MINE_READY_TO_GO,
    EVENT_ELECTROMAGNET,
    EVENT_ELECTROMAGNET_SWITCH,
    EVENT_SHOCKWAVE_MISSILE_TURRET,
    EVENT_SHOCKWAVE_MISSILE,
};

enum Datas
{
    DATA_DESTROYED_DEACTIVATED_WEAPON   = 1,
    DATA_LASER_TARGET_GUID,
    DATA_CRAWLER_MINE_COUNTER,
    DATA_CRAWLER_MINE_FIXATE,
    DATA_SAWBLADE_ON_GROUND,                // to see when a sawblade is on the ground
    DATA_SAWBLADE_TO_ELECTROMAGNET_PULL,    // to see when a sawblade is pulled by an electromagnet
    DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH,    // to see when a sawblade is pushed by an electromagnet

    DATA_LASERS_KILLED,
    DATA_MINES_KILLED,
    DATA_MAGNETS_KILLED,
    DATA_SHOCKWAVE_KILLED,
};

enum Actions
{
    ACTION_MOVE_WITH_CONVEYOR   = 1,    // used to trigger weapons to move with the conveyor
    ACTION_END_OF_CONVEYOR,             // used to trigger the controller when deactivated weapons reach the end of the conveyor
    ACTION_WEAPON_READY,                // used to trigger the controller when activated weapons reach the end of the conveyor
    ACTION_CRAWLER_MINE_START,          // used to trigger crawler mine moving after an overcharged crawler mine's death
};

enum DisplayIds
{

};

enum Timers
{
    TIMER_BERSERK                       = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_ELECTROSTATIC_CHARGE_FIRST    = 250,
    TIMER_ELECTROSTATIC_CHARGE          = 17 * IN_MILLISECONDS,
    TIMER_LAUNCH_SAWBLADE_FIRST         = 10 * IN_MILLISECONDS,
    TIMER_LAUNCH_SAWBLADE               = 15 * IN_MILLISECONDS,
    TIMER_SAWVBLADE_TARGETS             = 1 * IN_MILLISECONDS,
    TIMER_OVERLOAD                      = 10 * IN_MILLISECONDS,
    TIMER_DEATH_FROM_ABOVE_FIRST        = 18 * IN_MILLISECONDS,
    TIMER_DEATH_FROM_ABOVE              = 40 * IN_MILLISECONDS,
    TIMER_AUTOMATED_SHREDDER_FIRST      = 35 * IN_MILLISECONDS,
    TIMER_AUTOMATED_SHREDDER            = 60 * IN_MILLISECONDS,
    TIMER_AUTOMATED_SHREDDER_REPAIR     = 3 * IN_MILLISECONDS,
    TIMER_DEACTIVATED_WEAPON_FIRST      = 2 * IN_MILLISECONDS,
    TIMER_DEACTIVATED_WEAPON            = 65 * IN_MILLISECONDS,

    TIMER_LASER_TURRET_ACTIVATION       = 1 * IN_MILLISECONDS,
    TIMER_LASER_TARGET_MOVE             = 2 * IN_MILLISECONDS,
    TIMER_LASER_DURATION_NORMAL         = 15 * IN_MILLISECONDS,
    TIMER_LASER_DURATION_HEROIC         = 50 * IN_MILLISECONDS,
    TIMER_SUPERHEATED_DURATION          = 50 * IN_MILLISECONDS,
    TIMER_CRAWLER_MINE_ACTIVATION_FIRST = 2 * IN_MILLISECONDS,
    TIMER_CRAWLER_MINE_ACTIVATION       = 5 * IN_MILLISECONDS,
    TIMER_CRAWLER_MINE_READY_TO_GO      = 60 * IN_MILLISECONDS,
    TIMER_ELECTROMAGNET_ACTIVATION      = 2 * IN_MILLISECONDS,
    TIMER_ELECTROMAGNET_SWITCH          = 5 * IN_MILLISECONDS,
    TIMER_SHOCKWAVE_MISSILE_ACTIVATION  = 2 * IN_MILLISECONDS,
    TIMER_SHOCKWAVE_MISSILE_FIRST       = 2 * IN_MILLISECONDS,
    TIMER_SHOCKWAVE_MISSILE             = 4 * IN_MILLISECONDS,
};

enum VehicleSeats
{
    SEAT_SAWBLADE   = 0,
    SEAT_BLACKFUSE  = 1,
};

enum MovementPoints : int
{
    POINT_END_OF_CONVEYOR   = 1,
    POINT_SAWBLADE_ELECTROMAGNET,
};

enum WeaponTypes : int
{
    WEAPON_SHOCKWAVE_MISSILE_TURRET,
    WEAPON_LASER_TURRET,
    WEAPON_ELECTROMAGNET,
    WEAPON_CRAWLER_MINE,
    WEAPON_COUNT,

    WEAPON_NONE,
};

#define WEAPON_SEQUENCE_COUNT 12
#define WEAPON_PER_LINE 3
#define WEAPON_TO_READY 4
const WeaponTypes weaponSequences[WEAPON_SEQUENCE_COUNT][WEAPON_PER_LINE]
{
    { WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_CRAWLER_MINE, WEAPON_LASER_TURRET },
    { WEAPON_CRAWLER_MINE, WEAPON_LASER_TURRET, WEAPON_SHOCKWAVE_MISSILE_TURRET },
    { WEAPON_LASER_TURRET, WEAPON_ELECTROMAGNET, WEAPON_SHOCKWAVE_MISSILE_TURRET },
    { WEAPON_LASER_TURRET, WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_CRAWLER_MINE },
    { WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_ELECTROMAGNET, WEAPON_CRAWLER_MINE },
    { WEAPON_LASER_TURRET, WEAPON_CRAWLER_MINE, WEAPON_CRAWLER_MINE },
    { WEAPON_CRAWLER_MINE, WEAPON_LASER_TURRET, WEAPON_SHOCKWAVE_MISSILE_TURRET },
    { WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_ELECTROMAGNET, WEAPON_CRAWLER_MINE },
    { WEAPON_LASER_TURRET, WEAPON_CRAWLER_MINE, WEAPON_LASER_TURRET },
    { WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_LASER_TURRET, WEAPON_CRAWLER_MINE },
    { WEAPON_SHOCKWAVE_MISSILE_TURRET, WEAPON_ELECTROMAGNET, WEAPON_SHOCKWAVE_MISSILE_TURRET },
    { WEAPON_CRAWLER_MINE, WEAPON_ELECTROMAGNET, WEAPON_LASER_TURRET }
};

const WeaponTypes overchargeSequence[WEAPON_COUNT] =
{
    WEAPON_ELECTROMAGNET,
    WEAPON_CRAWLER_MINE,
    WEAPON_SHOCKWAVE_MISSILE_TURRET,
    WEAPON_LASER_TURRET,
};

// MOVEMENTFLAG_DISABLE_GRAVITY, MOVEMENTFLAG_ROOT (1536)
const Position siegeEngineerHelperPos = { 1956.205f, -5608.715f, -309.2436f, 5.302907f };

#define LASER_ARRAY_LINES_COUNT 5
#define LASER_ARRAY_POINTS_COUNT 5
const Position laserArrayPos[LASER_ARRAY_LINES_COUNT][LASER_ARRAY_POINTS_COUNT] =
{
    // * * * * * from north-west to south-east
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    {
        { 1970.609f, -5494.204f, -303.2739f, 5.283258f },
        { 1976.499f, -5490.422f, -303.2739f, 5.283258f },
        { 1982.389f, -5486.639f, -303.2739f, 5.283258f },
        { 1988.279f, -5482.856f, -303.2739f, 5.283258f },
        { 1994.169f, -5479.074f, -303.2739f, 5.283258f }
    },
    {
        { 1999.539f, -5537.805f, -302.9146f, 5.283258f },
        { 2005.429f, -5534.022f, -302.9146f, 5.283258f },
        { 2011.319f, -5530.24f, -302.9146f, 5.283258f },
        { 2017.209f, -5526.457f, -302.9146f, 5.283258f },
        { 2023.099f, -5522.675f, -302.9146f, 5.283258f }
    },
    {
        { 2017.534f, -5563.981f, -303.5679f, 5.283258f },
        { 2023.424f, -5560.199f, -303.5679f, 5.283258f },
        { 2029.314f, -5556.417f, -303.5679f, 5.283258f },
        { 2035.204f, -5552.634f, -303.5679f, 5.283258f },
        { 2041.094f, -5548.852f, -303.5679f, 5.283258f }
    },
    {
        { 2056.919f, -5572.532f, -303.2581f, 5.283258f },
        { 2051.029f, -5576.314f, -303.2581f, 5.283258f },
        { 2045.139f, -5580.097f, -303.2581f, 5.283258f },
        { 2039.249f, -5583.88f, -303.2581f, 5.283258f },
        { 2033.359f, -5587.662f, -303.2581f, 5.283258f }
    },
    {
        { 2076.56f, -5601.192f, -302.9146f, 5.283258f },
        { 2070.67f, -5604.974f, -302.9146f, 5.283258f },
        { 2064.78f, -5608.757f, -302.9146f, 5.283258f },
        { 2058.889f, -5612.54f, -302.9146f, 5.283258f },
        { 2053.0f, -5616.322f, -302.9146f, 5.283258f }
    }
};

#define STEAM_VENTS_COUNT 6
const Position steamVentsPos[STEAM_VENTS_COUNT] =
{
    { 1887.135f, -5588.172f, -313.0506f, 6.104739f },
    { 1885.184f, -5607.734f, -311.1529f, 6.209213f },
    { 1878.431f, -5595.221f, -313.1387f, 6.146268f },
    { 1894.163f, -5573.434f, -310.1116f, 6.011731f },
    { 1902.306f, -5563.738f, -311.4448f, 5.93033f },
    { 1914.462f, -5550.249f, -311.7415f, 5.93033f }
};

#define SHOCKWAVE_MOSSILE_POS_COUNT 21
const Position shockwaveMissileTurretPos[SHOCKWAVE_MOSSILE_POS_COUNT] =
{
    { 1926.40f, -5653.87f, -309.31f, 0.94f },
    { 1957.464844f, -5557.352051f, -309.31f, 0.265050f },
    { 1965.199951f, -5559.879395f, -309.31f, 5.781598f },
    { 1973.733398f, -5565.924316f, -309.31f, 5.583068f },
    { 1980.425049f, -5571.562012f, -309.31f, 5.583068f },
    { 1988.175903f, -5578.030762f, -309.31f, 5.708295f },
    { 1997.459106f, -5585.757324f, -309.31f, 4.944715f },
    { 1991.042236f, -5595.712402f, -309.31f, 3.496964f },
    { 1981.834106f, -5597.989746f, -309.31f, 3.225127f },
    { 1970.801147f, -5592.247559f, -309.31f, 2.556231f },
    { 1963.507813f, -5587.413086f, -309.31f, 2.556231f },
    { 1957.432861f, -5582.482422f, -309.31f, 2.369915f },
    { 1953.587158f, -5578.071777f, -309.31f, 2.156111f },
    { 1950.186768f, -5569.683594f, -309.31f, 1.783483f },
    { 1950.400879f, -5560.945313f, -309.31f, 1.349768f },
    { 1953.021851f, -5553.578125f, -309.31f, 0.928270f },
    { 1959.958862f, -5549.662109f, -309.08f, 0.283807f },
    { 1964.802490f, -5549.130371f, -308.31f, 6.093574f },
    { 1972.494873f, -5551.299316f, -308.31f, 5.833957f },
    { 1977.761230f, -5554.484375f, -309.31f, 5.696512f },
    { 1981.235840f, -5556.780273f, -309.31f, 5.702621f }
};

const Position endOfFirstConveyorPos =  { 2095.06f, -5652.94f, -302.87f, 2.15f };
const Position endOfSecondConveyorPos = { 1855.05f, -5618.66f, -302.87f, 2.23f };
const Position automatedShredderPos = { 1975.13f, -5637.32f, -309.31f, 2.18f };
const Position crawlerMineJumpPos = { 1911.91f, -5634.93f, -309.31f, 0.53f };
#define SAWBLADE_PULL_POS_COUNT 3
const Position sawbladePullPos[SAWBLADE_PULL_POS_COUNT] =
{
    { 1892.182861f, -5618.150391f, -308.321320f, 5.058303f },
    { 1899.715576f, -5637.610352f, -308.321320f, 5.195741f },
    { 1914.891357f, -5657.220215f, -308.321320f, 5.614177f }
};
#define SAWBLADE_PUSH_POS_COUNT 9
const Position sawbladePushPos[SAWBLADE_PUSH_POS_COUNT] =
{
    { 2020.556274f, -5611.636719f, -308.320587f, 1.820267f },
    { 2020.556274f, -5611.636719f, -308.320587f, 1.746963f },
    { 2019.040649f, -5603.019043f, -308.320587f, 1.743909f },
    { 2013.899170f, -5584.634277f, -308.320587f, 2.085994f },
    { 2005.456787f, -5570.866699f, -308.320587f, 2.226496f },
    { 1998.943481f, -5563.477539f, -308.320587f, 2.412812f },
    { 1990.494751f, -5557.254395f, -308.320587f, 2.593019f },
    { 1986.861328f, -5555.219727f, -308.320587f, 2.644942f },
    { 1973.175659f, -5549.339844f, -308.320587f, 2.867910f }
};
const Position centerPos = { 1956.14f, -5608.56f, -309.32f, 2.14f };

const static float s_SerratedLashRange = 4.25f;

#define CRAWLER_MINES_COUNT 3

#define LASER_GROUND_EFFECT_SIZE 3.f

bool IsOnConveyor(Unit* target)
{
    return target->HasAura(SPELL_ON_CONVEYOR);
}

Creature* GetBlackfuse(WorldObject* p_Searcher)
{
    if (InstanceScript* l_Instance = p_Searcher->GetInstanceScript())
    {
        return l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_SIEGECRAFTER_BLACKFUSE));
    }

    return nullptr;
}

const Position& GetNearestPullPositionToMagnet(Unit* p_Magnet)
{
    int32 l_Index = -1;
    for (int32 l_I = 0; l_I < SAWBLADE_PULL_POS_COUNT; ++l_I)
    {
        if (l_Index == -1 || p_Magnet->GetDistance(sawbladePullPos[l_I]) < p_Magnet->GetDistance(sawbladePullPos[l_Index]))
            l_Index = l_I;
    }

    if (l_Index < 0)
        return sawbladePullPos[0];

    return sawbladePullPos[l_Index];
}

class WeaponSpawnHelper
{
    public:

        WeaponSpawnHelper(Creature* owner) : m_Owner(owner),
            m_CurrentWeaponSequence(0), m_LastDestroyedWeapon(WEAPON_NONE), m_IsAnyWeaponDestroyed(false),
            m_NextOverchargedWeapon(WEAPON_NONE)
        {
            memset(m_OverchargedCounter, 0, sizeof(m_OverchargedCounter));
        }

        void ResetSequence()
        {
            m_CurrentWeaponSequence = 0;
            m_IsAnyWeaponDestroyed = false;

            memset(m_OverchargedCounter, 0, sizeof(m_OverchargedCounter));
            m_NextOverchargedWeapon = WEAPON_NONE;
        }

        void SpawnDeactivatedWeapon()
        {
            _SpawnDeactivatedWeapon();
        }

        void SpawnActivatedWeapon()
        {
            _SpawnActivatedWeapon();
        }

        void SetLastDestroyedWeapon(WeaponTypes weaponType)
        {
            m_LastDestroyedWeapon = weaponType;
        }

        void ClearLastDestroyedWeapon()
        {
            m_LastDestroyedWeapon = WEAPON_NONE;
        }

        bool IsWeaponDestroyed(WeaponTypes weaponType) const
        {
            return m_LastDestroyedWeapon == weaponType;
        }

        bool IsAnyWeaponDestroyed() const { return m_IsAnyWeaponDestroyed; }

        static uint32 GetDeactivatedEntryByWeaponType(WeaponTypes weaponType)
        {
            switch (weaponType)
            {
                case WeaponTypes::WEAPON_SHOCKWAVE_MISSILE_TURRET: return NPC_DEACTIVATED_MISSILE_TURRET;
                case WeaponTypes::WEAPON_LASER_TURRET: return NPC_DEACTIVATED_LASER_TURRET;
                case WeaponTypes::WEAPON_ELECTROMAGNET: return NPC_DEACTIVATED_ELECTROMAGNET;
                case WeaponTypes::WEAPON_CRAWLER_MINE: return NPC_DISASSEMBLED_CRAWLER_MINES;
            }
            return 0;
        }

        static WeaponTypes GetWeaponTypeByEntry(uint32 entry)
        {
            switch (entry)
            {
                case NPC_DEACTIVATED_MISSILE_TURRET:
                case NPC_ACTIVATED_MISSILE_TURRET:
                case NPC_OVERCHARGED_MISSILE_TURRET:
                    return WEAPON_SHOCKWAVE_MISSILE_TURRET;
                case NPC_DEACTIVATED_LASER_TURRET:
                case NPC_ACTIVATED_LASER_TURRET:
                case NPC_OVERCHARGED_LASER_TURRET:
                    return WEAPON_LASER_TURRET;
                case NPC_DEACTIVATED_ELECTROMAGNET:
                case NPC_ACTIVATED_ELECTROMAGNET:
                case NPC_OVERCHARGED_ELECTROMAGNET:
                    return WEAPON_ELECTROMAGNET;
                case NPC_DISASSEMBLED_CRAWLER_MINES:
                case NPC_CRAWLER_MINE:
                case NPC_OVERCHARGED_CRAWLER_MINE:
                    return WEAPON_CRAWLER_MINE;
            }

            return WEAPON_NONE;
        }

    private:

        void _SpawnDeactivatedWeapon()
        {
            if (m_CurrentWeaponSequence >= WEAPON_SEQUENCE_COUNT)
                m_CurrentWeaponSequence = 0;

            Position  pos = { 1962.337f, -5452.712f, -303.0483f, 5.305801f };

            if (Creature* pVehicle = m_Owner->SummonCreature(NPC_DEACTIVATED_TURRET_VEHICLE, pos))
            {
                for (uint8 i = 0; i < WEAPON_PER_LINE; ++i)
                {
                    uint32 weaponEntry = WeaponSpawnHelper::GetDeactivatedEntryByWeaponType(weaponSequences[m_CurrentWeaponSequence][i]);
                    if (Creature* pCreature = m_Owner->SummonCreature(weaponEntry, pos))
                    {
                        pCreature->EnterVehicle(pVehicle, i);
                        //pCreature->ClearUnitState(UNIT_STATE_ONVEHICLE);
                    }
                }

                pVehicle->AI()->DoAction(ACTION_MOVE_WITH_CONVEYOR);
            }
        }

        void _SpawnActivatedWeapon()
        {
            m_IsAnyWeaponDestroyed = false;

            if (m_CurrentWeaponSequence >= WEAPON_SEQUENCE_COUNT)
                m_CurrentWeaponSequence = 0;

            Position  pos = { 1935.752f, -5739.543f, -302.988f, 5.305801f };

            if (Creature* pVehicle = m_Owner->SummonCreature(NPC_ACTIVATED_TURRET_VEHICLE, pos))
            {
                UpdateNextOverchargedWeapon();

                for (uint8 i = 0; i < WEAPON_PER_LINE; ++i)
                {
                    WeaponTypes weaponType = weaponSequences[m_CurrentWeaponSequence][i];

                    Creature* pWeaponBase = NULL;
                    Creature* pWeapon = NULL;

                    if (IsWeaponDestroyed(weaponType))
                    {
                        pWeaponBase = CreatePlaceholder(pos);
                        m_IsAnyWeaponDestroyed = true;
                    }
                    else
                    {
                        pWeaponBase = CreateActivatedWeaponBase(weaponType, pos);

                        pWeapon = CreateActivatedWeapon(weaponType, pos);
                    }

                    if (pWeaponBase)
                    {
                        pWeaponBase->EnterVehicle(pVehicle, i);
                        //pCreature->ClearUnitState(UNIT_STATE_ONVEHICLE);
                    }

                    if (pWeapon)
                    {
                        pWeapon->EnterVehicle(pWeaponBase, 0);
                    }

                    if (weaponType == WEAPON_CRAWLER_MINE)
                    {
                        CreateActivatedCrawlerMines(pos, pWeaponBase, CRAWLER_MINES_COUNT);
                    }
                }

                pVehicle->AI()->DoAction(ACTION_MOVE_WITH_CONVEYOR);
            }

            ClearLastDestroyedWeapon();

            ++m_CurrentWeaponSequence;
        }

        Creature* CreateActivatedWeaponBase(WeaponTypes weaponType, const Position& pos)
        {
            switch (weaponType)
            {
                case WEAPON_SHOCKWAVE_MISSILE_TURRET:
                    return CreateActivatedMissileTurretBase(pos);
                case WEAPON_CRAWLER_MINE:
                    return CreateActivatedCrawlerMineBase(pos);
                case WEAPON_LASER_TURRET:
                    return CreateActivatedLaserTurretBase(pos);
                case WEAPON_ELECTROMAGNET:
                    return CreateActivatedElectromagnetBase(pos);
            }

            return NULL;
        }

        Creature* CreateActivatedMissileTurretBase(const Position& pos)
        {
            Creature* pBase = m_Owner->SummonCreature(NPC_ACTIVATED_MISSILE_TURRET_BASE, pos);
            return pBase;
        }

        Creature* CreateActivatedCrawlerMineBase(const Position& pos)
        {
            Creature* pBase = m_Owner->SummonCreature(NPC_ACTIVATED_CRAWLER_MINE_VEHICLE, pos);
            return pBase;
        }

        Creature* CreateActivatedElectromagnetBase(const Position& pos)
        {
            uint32 creatureEntry = IsWeaponOvercharged(WEAPON_ELECTROMAGNET) ? NPC_OVERCHARGED_ELECTROMAGNET : NPC_ACTIVATED_ELECTROMAGNET;

            Creature* pCreature = m_Owner->SummonCreature(creatureEntry, pos);
            return pCreature;
        }

        Creature* CreateActivatedLaserTurretBase(const Position& pos)
        {
            Creature* pBase = m_Owner->SummonCreature(NPC_ACTIVATED_LASER_TURRET_BASE, pos);
            return pBase;
        }

        Creature* CreateActivatedWeapon(WeaponTypes weaponType, const Position& pos)
        {
            switch (weaponType)
            {
                case WEAPON_SHOCKWAVE_MISSILE_TURRET:
                    return CreateActivatedMissileTurret(pos);
                // Handle crawler mines in CreateActivatedCrawlerMines
                //case WEAPON_CRAWLER_MINE:
                //    return CreateActivatedCrawlerMine(pos);
                case WEAPON_LASER_TURRET:
                    return CreateActivatedLaserTurret(pos);
                // We create electromagnet as base in CreateActivatedWeaponBase
                //case WEAPON_ELECTROMAGNET:
                //    return CreateActivatedElectromagnet(pos);
            }

            return NULL;
        }

        Creature* CreateActivatedMissileTurret(const Position& pos)
        {
            uint32 creatureEntry = IsWeaponOvercharged(WEAPON_SHOCKWAVE_MISSILE_TURRET) ? NPC_OVERCHARGED_MISSILE_TURRET : NPC_ACTIVATED_MISSILE_TURRET;

            Creature* pCreature = m_Owner->SummonCreature(creatureEntry, pos);
            return pCreature;
        }

        Creature* CreateActivatedCrawlerMine(const Position& pos)
        {
            Creature* pCreature = m_Owner->SummonCreature(NPC_CRAWLER_MINE, pos);
            return pCreature;
        }

        void CreateActivatedCrawlerMines(const Position& pos, Unit* pVehicle, const uint8 count)
        {
            uint32 creatureEntry = IsWeaponOvercharged(WEAPON_CRAWLER_MINE) ? NPC_OVERCHARGED_CRAWLER_MINE : NPC_CRAWLER_MINE;

            for (uint8 i = 0; i < count; ++i)
            {
                if (Creature* pCreature = m_Owner->SummonCreature(creatureEntry, pos))
                {
                    pCreature->AI()->SetData(DATA_CRAWLER_MINE_COUNTER, i);

                    if (pVehicle)
                        pCreature->EnterVehicle(pVehicle, i);
                }
            }
        }

        Creature* CreateActivatedElectromagnet(const Position& pos)
        {
            uint32 creatureEntry = IsWeaponOvercharged(WEAPON_ELECTROMAGNET) ? NPC_OVERCHARGED_ELECTROMAGNET : NPC_ACTIVATED_ELECTROMAGNET;

            Creature* pCreature = m_Owner->SummonCreature(creatureEntry, pos);
            return pCreature;
        }

        Creature* CreateActivatedLaserTurret(const Position& pos)
        {
            uint32 creatureEntry = IsWeaponOvercharged(WEAPON_LASER_TURRET) ? NPC_OVERCHARGED_LASER_TURRET : NPC_ACTIVATED_LASER_TURRET;

            Creature* pCreature = m_Owner->SummonCreature(creatureEntry, pos);
            return pCreature;
        }

        Creature* CreatePlaceholder(const Position& pos)
        {
            Creature* pCreature = m_Owner->SummonCreature(NPC_ACTIVATED_TURRET_PLACEHOLDER, pos);
            return pCreature;
        }

        void UpdateNextOverchargedWeapon()
        {
            if (!m_Owner->GetMap()->IsHeroic())
                return;

            auto prevOverchargedWeapon = m_NextOverchargedWeapon;

            std::list<WeaponTypes> weaponForOvercharge;
            for (uint8 i = 0; i < WEAPON_PER_LINE; ++i)
            {
                WeaponTypes weaponType = weaponSequences[m_CurrentWeaponSequence][i];

                if (IsWeaponDestroyed(weaponType))
                    continue;

                if (weaponType == prevOverchargedWeapon)
                    continue;

                weaponForOvercharge.push_back(weaponType);
            }

            m_NextOverchargedWeapon = weaponForOvercharge.empty() ? WeaponTypes::WEAPON_ELECTROMAGNET : Trinity::Containers::SelectRandomContainerElement(weaponForOvercharge);

            ++m_OverchargedCounter[m_NextOverchargedWeapon];
        }

        bool IsWeaponOvercharged(WeaponTypes weaponType) const
        {
            return m_NextOverchargedWeapon == weaponType;
        }

    private:

        Creature* m_Owner;
        uint8 m_CurrentWeaponSequence;
        WeaponTypes m_LastDestroyedWeapon;
        bool m_IsAnyWeaponDestroyed;
        uint32 m_OverchargedCounter[WEAPON_COUNT];
        WeaponTypes m_NextOverchargedWeapon;

};

class ActivatedWeaponCheckPredicate
{
    public:
        ActivatedWeaponCheckPredicate() {}

        bool operator()(ObjectGuid guid)
        {
            switch (ObjectAccessor::GetUnit(*_owner, guid)->GetEntry())
            {
                case NPC_ACTIVATED_ELECTROMAGNET:
                case NPC_CRAWLER_MINE:
                case NPC_ACTIVATED_MISSILE_TURRET:
                case NPC_ACTIVATED_LASER_TURRET:
                case NPC_OVERCHARGED_ELECTROMAGNET:
                case NPC_OVERCHARGED_CRAWLER_MINE:
                case NPC_OVERCHARGED_MISSILE_TURRET:
                case NPC_OVERCHARGED_LASER_TURRET:
                    return true;
            }

            return false;
        }

        void setOwner(Unit* owner)
        {
            _owner = owner;
        }

    private:
        uint32 _entry;
        Unit* _owner;
};

class boss_siegecrafter_blackfuse : public CreatureScript
{
    public:

        boss_siegecrafter_blackfuse() : CreatureScript("boss_siegecrafter_blackfuse") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_siegecrafter_blackfuseAI(creature);
        }

        struct boss_siegecrafter_blackfuseAI : public BossAI
        {
            boss_siegecrafter_blackfuseAI(Creature* creature) : BossAI(creature, DATA_SIEGECRAFTER_BLACKFUSE),
                m_WeaponSpawnHelper(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
                me->SetBoundingRadius(6.0f);
                me->SetCombatReach(6.0f);
            }

            void Reset() override
            {
                _Reset();

                ClearEncounter();

                InitVehicles();
                LoadSawblade();

                m_WeaponSpawnHelper.ResetSequence();

                memset(weaponsKilled, 0, sizeof(weaponsKilled));

                me->SetReactState(ReactStates::REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_AGGRO);

                InitLaserArrays();
                InitSteamVents();

                me->AddAura(SPELL_AUTOMATIC_REPAIR_BEAM_MARK_1, me);

                events.ScheduleEvent(EVENT_SPAWN_DEACTIVATED_WEAPON, TIMER_DEACTIVATED_WEAPON_FIRST);
                events.ScheduleEvent(EVENT_ELECTROSTATIC_CHARGE, TIMER_ELECTROSTATIC_CHARGE_FIRST);
                events.ScheduleEvent(EVENT_LAUCH_SAWBLADE, TIMER_LAUNCH_SAWBLADE_FIRST);
                events.ScheduleEvent(EVENT_AUTOMATED_SHREDDER, TIMER_AUTOMATED_SHREDDER_FIRST);
                events.ScheduleEvent(EVENT_AUTOMATED_SHREDDER_REPAIR, TIMER_AUTOMATED_SHREDDER_REPAIR);

                DoZoneInCombat();
                instance->SetBossState(DATA_SIEGECRAFTER_BLACKFUSE, IN_PROGRESS);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                BossAI::SummonedCreatureDespawn(summon);

                if (summon->GetEntry() == NPC_ACTIVATED_ELECTROMAGNET ||
                    summon->GetEntry() == NPC_OVERCHARGED_ELECTROMAGNET)
                {
                    DespawnUsedSawblades();
                }
            }

            void JustDied(Unit* who)
            {
                Talk(SAY_DEATH_1);

                _JustDied();

                ClearEncounter();
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                {
                    Talk(SAY_KILL);
                }
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_END_OF_CONVEYOR)
                {
                    HandleWeaponAtEndOfConveyor();
                }
                else if (action == ACTION_WEAPON_READY)
                {
                    HandleWeaponIsReady();
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_DESTROYED_DEACTIVATED_WEAPON)
                {
                    HandleDestroyedWeapon((WeaponTypes)data);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_LASERS_KILLED: return weaponsKilled[WEAPON_LASER_TURRET] ? 1 : 0;
                    case DATA_MINES_KILLED: return weaponsKilled[WEAPON_CRAWLER_MINE] ? 1 : 0;
                    case DATA_MAGNETS_KILLED: return weaponsKilled[WEAPON_ELECTROMAGNET] ? 1 : 0;
                    case DATA_SHOCKWAVE_KILLED: return weaponsKilled[WEAPON_SHOCKWAVE_MISSILE_TURRET] ? 1 : 0;
                }

                return 0;
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                if (summon->GetEntry() == NPC_AUTOMATED_SHREDDER)
                {
                    HandleAutomatedShredderDies();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (IsOutOfArena())
                {
                    EnterEvadeMode();
                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_ELECTROSTATIC_CHARGE:
                        DoElectrostaticCharge();
                        events.ScheduleEvent(EVENT_ELECTROSTATIC_CHARGE, TIMER_ELECTROSTATIC_CHARGE);
                        break;
                    case EVENT_LAUCH_SAWBLADE:
                        DoLaunchSawblade();
                        events.ScheduleEvent(EVENT_LAUCH_SAWBLADE, TIMER_LAUNCH_SAWBLADE);
                        break;
                    case EVENT_AUTOMATED_SHREDDER:
                        DoAutomatedShredder();
                        events.ScheduleEvent(EVENT_AUTOMATED_SHREDDER, TIMER_AUTOMATED_SHREDDER);
                        break;
                    case EVENT_AUTOMATED_SHREDDER_REPAIR:
                        HealAutomatedShredders();
                        events.ScheduleEvent(EVENT_AUTOMATED_SHREDDER_REPAIR, TIMER_AUTOMATED_SHREDDER_REPAIR);
                        break;
                    case EVENT_SPAWN_DEACTIVATED_WEAPON:
                        DoSpawnDeactivatedWeapon();
                        events.ScheduleEvent(EVENT_SPAWN_DEACTIVATED_WEAPON, TIMER_DEACTIVATED_WEAPON);
                        break;
                    case EVENT_SPAWN_ACTIVATED_WEAPON:
                        DoSpawnActivatedWeapon();
                        break;
                }
            }

        private:

            void LoadSawblade()
            {
                // HACK: it's blizzlike just to cast 'load_sawblade'
                // But we don't use it
                // Add aura and spawn sawblade manually

                me->AddAura(SPELL_LOAD_SAWBLADE, me);

                if (Creature* pSawBlade = me->SummonCreature(NPC_SAWBLADE, *me))
                {
                    pSawBlade->EnterVehicle(me, SEAT_SAWBLADE);
                }
            }

            void InitVehicles()
            {
                if (Creature* pGoblin = me->SummonCreature(NPC_SIEGECRAFTER_BLACKFUSE_GOBLIN, *me))
                {
                    pGoblin->EnterVehicle(me, SEAT_BLACKFUSE);
                }
            }

            void InitLaserArrays()
            {
                // two points from each line should be disabled except first and last lines
                for (uint8 i_line = 0; i_line < LASER_ARRAY_LINES_COUNT; ++i_line)
                {
                    uint8 pointToSkip1 = urand(0, 1);
                    uint8 pointToSkip2 = urand(2, LASER_ARRAY_POINTS_COUNT - 1);

                    for (uint8 i_point = 0; i_point < LASER_ARRAY_POINTS_COUNT; ++i_point)
                    {
                        if (i_line > 0 && i_line < LASER_ARRAY_LINES_COUNT - 1 &&
                            (i_point == pointToSkip1 || i_point == pointToSkip2 ))
                            continue;

                        me->SummonCreature(NPC_LASER_ARRAY_BUNNY, laserArrayPos[i_line][i_point]);
                    }
                }
            }

            void InitSteamVents()
            {
                for (uint8 i = 0; i < STEAM_VENTS_COUNT; ++i)
                {
                    me->SummonCreature(NPC_STEAM_VENT_BUNNY, steamVentsPos[i]);
                }
            }

            bool IsOutOfArena() const
            {
                return me->GetDistance(me->GetHomePosition()) >= 65.f;
            }

            void ClearEncounter()
            {
                me->DespawnCreaturesInArea(NPC_LASER_TARGET_BUNNY, 200);
                me->DespawnCreaturesInArea(NPC_SHOCKWAVE_MISSILE, 200);

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELECTROSTATIC_CHARGE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGNETIC_CRUSH_DMG);
            }

            void HealAutomatedShredders()
            {
                std::list<Creature*> shredders;
                me->GetCreatureListWithEntryInGrid(shredders, NPC_AUTOMATED_SHREDDER, 100.0f);
                for (std::list<Creature*>::const_iterator itr_shredder = shredders.begin(); itr_shredder != shredders.end(); ++itr_shredder)
                {
                    Creature* pShredder = (*itr_shredder);

                    if (me->GetDistance(pShredder) <= 30.0f && !pShredder->HasAura(SPELL_AUTOMATIC_REPAIR_BEAM_HEAL))
                    {
                        DoCast(pShredder, SPELL_AUTOMATIC_REPAIR_BEAM_HEAL);
                    }
                    else if (me->GetDistance(pShredder) > 30.0f && pShredder->HasAura(SPELL_AUTOMATIC_REPAIR_BEAM_HEAL))
                    {
                        pShredder->RemoveAura(SPELL_AUTOMATIC_REPAIR_BEAM_HEAL);
                    }
                }
            }

            void HandleAutomatedShredderDies()
            {
                DoCast(me, SPELL_PROTECTIVE_FRENZY, true);
            }

            void HandleWeaponAtEndOfConveyor()
            {
                events.ScheduleEvent(EVENT_SPAWN_ACTIVATED_WEAPON, 3000);
            }

            void HandleWeaponIsReady()
            {
                ActivatedWeaponCheckPredicate weaponPred;
                weaponPred.setOwner(me);
                summons.DoAction(ACTION_WEAPON_READY, weaponPred);

                if (!m_WeaponSpawnHelper.IsAnyWeaponDestroyed())
                {
                    DoCast(me, SPELL_ENERGIZED_DEFENSIVE_MATRIX, true);
                }
            }

            void HandleDestroyedWeapon(WeaponTypes weaponType)
            {
                Talk(SAY_WEAPON_DESTROYED);

                m_WeaponSpawnHelper.SetLastDestroyedWeapon(weaponType);

                weaponsKilled[weaponType] = true;
            }

            void DoElectrostaticCharge()
            {
                DoCastVictim(SPELL_ELECTROSTATIC_CHARGE);
            }

            void DoLaunchSawblade()
            {
                me->AddAura(SPELL_LOAD_SAWBLADE, me);
                DoCastAOE(SPELL_LAUNCH_SAWBLADE_AOE);
            }

            void DoAutomatedShredder()
            {
                Talk(SAY_SHREDDER_EMOTE);
                Talk(SAY_SHREDDER);
                me->SummonCreature(NPC_AUTOMATED_SHREDDER, automatedShredderPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
            }

            void DoSpawnDeactivatedWeapon()
            {
                Talk(SAY_CONVEYOR_EMOTE);
                m_WeaponSpawnHelper.SpawnDeactivatedWeapon();
            }

            void DoSpawnActivatedWeapon()
            {
                // Remove previous weapons

                summons.DespawnEntry(NPC_OVERCHARGED_MISSILE_TURRET);
                //summons.DespawnEntry(NPC_OVERCHARGED_CRAWLER_MINE);
                summons.DespawnEntry(NPC_OVERCHARGED_LASER_TURRET);
                summons.DespawnEntry(NPC_OVERCHARGED_ELECTROMAGNET);
                summons.DespawnEntry(NPC_ACTIVATED_ELECTROMAGNET);
                //summons.DespawnEntry(NPC_CRAWLER_MINE);
                summons.DespawnEntry(NPC_ACTIVATED_MISSILE_TURRET);
                summons.DespawnEntry(NPC_ACTIVATED_LASER_TURRET);
                summons.DespawnEntry(NPC_ACTIVATED_CRAWLER_MINE_VEHICLE);
                summons.DespawnEntry(NPC_ACTIVATED_LASER_TURRET_BASE);
                summons.DespawnEntry(NPC_ACTIVATED_MISSILE_TURRET_BASE);
                summons.DespawnEntry(NPC_ACTIVATED_TURRET_PLACEHOLDER);
                summons.DespawnEntry(NPC_ACTIVATED_TURRET_VEHICLE);

                m_WeaponSpawnHelper.SpawnActivatedWeapon();
            }

            void DespawnUsedSawblades()
            {
                for (SummonList::iterator itrSummon = summons.begin(); itrSummon != summons.end();)
                {
                    Creature* summon = ObjectAccessor::GetCreature(*me, *itrSummon);
                    if (!summon)
                    {
                        itrSummon = summons.erase(itrSummon);
                        continue;
                    }

                    uint32 isPulled = 0;
                    uint32 isPushed = 0;

                    bool isEntry = summon->GetEntry() == NPC_SAWBLADE;
                    if (isEntry)
                    {
                        isPulled = summon->AI()->GetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PULL);
                        isPushed = summon->AI()->GetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH);
                    }

                    if (isEntry && (isPulled || isPushed))
                    {
                        itrSummon = summons.erase(itrSummon);
                        summon->DespawnOrUnsummon();
                    }
                    else
                    {
                        ++itrSummon;
                    }
                }
            }

        private:

            WeaponSpawnHelper m_WeaponSpawnHelper;
            bool weaponsKilled[WEAPON_COUNT];

        };
};

class npc_siegecrafter_blackfuse_goblin : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_goblin() : CreatureScript("npc_siegecrafter_blackfuse_goblin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_goblinAI(creature);
        }

        struct npc_siegecrafter_blackfuse_goblinAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_goblinAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }


        private:

        private:

        };
};

class npc_siegecrafter_blackfuse_sawblade : public CreatureScript
{
    public:
        npc_siegecrafter_blackfuse_sawblade() : CreatureScript("npc_siegecrafter_blackfuse_sawblade") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_sawbladeAI(creature);
        }

        struct npc_siegecrafter_blackfuse_sawbladeAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_sawbladeAI(Creature* creature) : ScriptedAI(creature),
                m_IsLanded(false), m_CheckTargetsTimer(500), m_IsPulledByElectromagnet(false), m_IsPushedByElectromagnet(false)
            {
                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE && id == EVENT_JUMP)
                {
                    if (!m_IsLanded)
                    {
                        HandleLanded();
                    }
                    else if (m_IsPulledByElectromagnet)
                    {
                        HandleJumpToElectromagnet();
                    }
                }
                else if (type == POINT_MOTION_TYPE && id == POINT_SAWBLADE_ELECTROMAGNET || // second way for electromagnet without 'jump' spells
                        type == EFFECT_MOTION_TYPE && id == EVENT_CHARGE)                   // third way for electromagnet without 'jump' spells
                {
                    if (m_IsPulledByElectromagnet)
                    {
                        HandleJumpToElectromagnet();
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_SAWBLADE_ON_GROUND)
                {
                    return m_IsLanded ? 1 : 0;
                }
                else if (type == DATA_SAWBLADE_TO_ELECTROMAGNET_PULL)
                {
                    return m_IsPulledByElectromagnet ? 1 : 0;
                }
                else if (type == DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH)
                {
                    return m_IsPushedByElectromagnet ? 1 : 0;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_SAWBLADE_TO_ELECTROMAGNET_PULL)
                {
                    m_IsPulledByElectromagnet = true;
                    m_IsPushedByElectromagnet = false;
                }
                else if (type == DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH)
                {
                    m_IsPushedByElectromagnet = true;
                    m_IsPulledByElectromagnet = false;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                CheckTargets(diff);
            }

        private:

            void HandleLanded()
            {
                m_IsLanded = true;

                DoCast(me, SPELL_LAUNCH_SAWBLADE_REMOVE, true);
            }

            void HandleJumpToElectromagnet()
            {
                // Despawn it in 'DespawnUsedSawblades'
                //if (!IsHeroic())
                //{
                //    me->DespawnOrUnsummon(1000);
                //}
            }

            void CheckTargets(const uint32 diff)
            {
                if (!m_IsLanded)
                    return;

                if (m_CheckTargetsTimer <= diff)
                {
                    m_CheckTargetsTimer = TIMER_SAWVBLADE_TARGETS;

                    std::list<Unit*> targets;
                    SelectTargets(targets);
                    ProcessTargets(targets);
                }
                else
                {
                    m_CheckTargetsTimer -= diff;
                }
            }

            void SelectTargets(std::list<Unit*>& targets)
            {
                SerratedLashTargetsCheck check(me);
                Trinity::UnitListSearcher<SerratedLashTargetsCheck> searcher(me, targets, check);
                //me->VisitNearbyObject(s_SerratedLashRange, searcher);
                Cell::VisitWorldObjects(me, searcher, s_SerratedLashRange);
            }

            void ProcessTargets(std::list<Unit*>& targets)
            {
                if (targets.empty())
                    return;

                for (std::list<Unit*>::const_iterator itr_target = targets.begin(); itr_target != targets.end(); ++itr_target)
                {
                    Unit* target = (*itr_target);

                    if (target->IsPlayer())
                    {
                        target->CastSpell(target, SPELL_SERRATED_SLASH_KNOCKBACK, true);
                    }
                    else
                    {
                        target->CastSpell(target, SPELL_SERRATED_SLASH_DMG, true);
                    }
                }
            }

        private:

            class SerratedLashTargetsCheck
            {
                public:
                    SerratedLashTargetsCheck(WorldObject const* object) : m_pObject(object) {}

                    bool operator() (Unit* unit)
                    {
                        if (m_pObject->GetExactDist2d(unit) > s_SerratedLashRange)
                            return false;

                        if (IsOnConveyor(unit))
                            return false;

                        if (unit->IsPlayer())
                            return true;

                        if (unit->GetEntry() == NPC_AUTOMATED_SHREDDER &&
                            !unit->HasAura(SPELL_SERRATED_SLASH_DMG))
                            return true;

                        return false;
                    }

                private:
                    WorldObject const* m_pObject;
            };

        private:

            bool m_IsLanded;
            uint32 m_CheckTargetsTimer;
            bool m_IsPulledByElectromagnet;
            bool m_IsPushedByElectromagnet;
        };
};

class npc_siegecrafter_blackfuse_automated_shredder : public CreatureScript
{
    public:
        npc_siegecrafter_blackfuse_automated_shredder() : CreatureScript("npc_siegecrafter_blackfuse_automated_shredder") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_automated_shredderAI(creature);
        }

        struct npc_siegecrafter_blackfuse_automated_shredderAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_automated_shredderAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_AGGRESSIVE);

                //ApplyAllImmunities(true);

                // Enable electostatic charge dmg
                me->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
            }

            void Reset() override
            {
                me->AddAura(SPELL_REACTIVE_ARMOR, me);
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_OVERLOAD, TIMER_OVERLOAD);
                events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, TIMER_DEATH_FROM_ABOVE_FIRST);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE && id == /*EVENT_KNOCKBACK = 1006 in shared defines*/ 1006)
                {
                    DoCastAOE(SPELL_DEATH_FROM_ABOVE_DMG, true);
                    me->SetReactState(REACT_AGGRESSIVE);
                }
            }

            void JustDied(Unit* who) override
            {
                // We handle it at 'SummonedCreatureDies'
                //DoCast(me, SPELL_AUTOMATED_SHREDDER_DEATH_NOTIFY, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                // Prevent actions while 'death from above' jumping
                if (IsInDeathFromAbove())
                    return;

                if (!UpdateVictim())
                    return;

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

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_OVERLOAD:
                        DoOverload();
                        events.ScheduleEvent(EVENT_OVERLOAD, TIMER_OVERLOAD);
                        break;
                    case EVENT_DEATH_FROM_ABOVE:
                        DoDeathFromAbove();
                        events.ScheduleEvent(EVENT_DEATH_FROM_ABOVE, TIMER_DEATH_FROM_ABOVE);
                        break;
                }
            }

            void DoOverload()
            {
                DoCastAOE(SPELL_OVERLOAD);
            }

            void DoDeathFromAbove()
            {
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                DoCast(SPELL_DEATH_FROM_ABOVE);
            }

            bool IsInDeathFromAbove() const
            {
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == EFFECT_MOTION_TYPE)
                {
                    return true;
                }

                return false;
            }

        private:

            InstanceScript* pInstance;

        };
};

class npc_siegecrafter_blackfuse_siege_engineer_helper : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_siege_engineer_helper() : CreatureScript("npc_siegecrafter_blackfuse_siege_engineer_helper") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_siege_engineer_helperAI(creature);
        }

        struct npc_siegecrafter_blackfuse_siege_engineer_helperAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_siege_engineer_helperAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);
            }
        };
};

class npc_siegecrafter_blackfuse_siege_deactivated_base : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_siege_deactivated_base() : CreatureScript("npc_siegecrafter_blackfuse_siege_deactivated_base") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_siege_deactivated_baseAI(creature);
        }

        struct npc_siegecrafter_blackfuse_siege_deactivated_baseAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_siege_deactivated_baseAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_MOVE_WITH_CONVEYOR)
                {
                    MoveWithConveyor();
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_END_OF_CONVEYOR)
                {
                    HandleEndOfConveyor();
                }
            }

        private:

            void MoveWithConveyor()
            {
                if (me->isMoving())
                    return;

                //me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POINT_END_OF_CONVEYOR, endOfFirstConveyorPos);
            }

            void HandleEndOfConveyor()
            {
                if (Creature* pController = GetBlackfuse(me))
                {
                    pController->AI()->DoAction(ACTION_END_OF_CONVEYOR);
                }

                if (Vehicle* pVehicle = me->GetVehicleKit())
                {
                    for (uint8 i = 0; i < WEAPON_PER_LINE; ++i)
                        if (Unit* pWeapon = pVehicle->GetPassenger(i))
                            if (Creature* pCreature = pWeapon->ToCreature())
                                pCreature->DespawnOrUnsummon();
                }

                me->DespawnOrUnsummon(100);
            }
        };
};

class npc_siegecrafter_blackfuse_siege_deactivated_weapon : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_siege_deactivated_weapon() : CreatureScript("npc_siegecrafter_blackfuse_siege_deactivated_weapon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_siege_deactivated_weaponAI(creature);
        }

        struct npc_siegecrafter_blackfuse_siege_deactivated_weaponAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_siege_deactivated_weaponAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                m_WeaponType = WeaponSpawnHelper::GetWeaponTypeByEntry(creature->GetEntry());

                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

            }

            void JustDied(Unit* killer) override
            {
                HandleWeaponDestroyed();
            }

        private:

            void HandleWeaponDestroyed()
            {
                if (m_WeaponType == WEAPON_NONE)
                    return;

                if (Creature* pController = GetBlackfuse(me))
                {
                    pController->AI()->SetData(DATA_DESTROYED_DEACTIVATED_WEAPON, m_WeaponType);
                }

                DoCast(SPELL_TURRET_EXPLOSION);
                DoCastAOE(SPELL_ELECTROMAGNETIC_BARRIER_IMMUNITY, true);
            }

        private:

            InstanceScript* pInstance;
            WeaponTypes m_WeaponType;

        };
};

class npc_siegecrafter_blackfuse_siege_activated_base : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_siege_activated_base() : CreatureScript("npc_siegecrafter_blackfuse_siege_activated_base") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_siege_activated_baseAI(creature);
        }

        struct npc_siegecrafter_blackfuse_siege_activated_baseAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_siege_activated_baseAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_MOVE_WITH_CONVEYOR)
                {
                    MoveWithConveyor();
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_END_OF_CONVEYOR)
                {
                    HandleEndOfConveyor();
                }
            }

        private:

            void MoveWithConveyor()
            {
                if (me->isMoving())
                    return;

                //me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(POINT_END_OF_CONVEYOR, endOfSecondConveyorPos);
            }

            void HandleEndOfConveyor()
            {
                if (Creature* pController = GetBlackfuse(me))
                {
                    pController->AI()->DoAction(ACTION_WEAPON_READY);
                }
            }

        private:

            InstanceScript* pInstance;

        };
};

class npc_siegecrafter_blackfuse_siege_activated_weapon_base : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_siege_activated_weapon_base() : CreatureScript("npc_siegecrafter_blackfuse_siege_activated_weapon_base") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_siege_activated_weapon_baseAI(creature);
        }

        struct npc_siegecrafter_blackfuse_siege_activated_weapon_baseAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_siege_activated_weapon_baseAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

        private:

            InstanceScript* pInstance;

        };
};

struct npc_siegecrafter_blackfuse_siege_activated_weaponAI : public ScriptedAI
{
    npc_siegecrafter_blackfuse_siege_activated_weaponAI(Creature* creature) : ScriptedAI(creature)
    {
        pInstance = creature->GetInstanceScript();
        m_WeaponType = WeaponSpawnHelper::GetWeaponTypeByEntry(creature->GetEntry());

        //ApplyAllImmunities(true);

        me->setActive(true);

        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

        m_IsActivated = false;
    }

    void JustSummoned(Creature* summon) override
    {
        if (me->IsInCombat())
            DoZoneInCombat(summon);

        summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        summons.Despawn(summon);
    }

    void DoAction(const int32 action) override
    {
        if (action == ACTION_WEAPON_READY)
        {
            ActivateWeapon();
        }
    }

protected:

    bool IsWeaponType(WeaponTypes weaponType) const
    {
        return m_WeaponType == weaponType;
    }

    bool IsOvercharged() const
    {
        switch (me->GetEntry())
        {
            case NPC_OVERCHARGED_MISSILE_TURRET:
            case NPC_OVERCHARGED_SHOCKWAVE_MISSILE:
            case NPC_OVERCHARGED_LASER_TURRET:
            case NPC_OVERCHARGED_ELECTROMAGNET:
            case NPC_OVERCHARGED_CRAWLER_MINE:
                return true;
        }

        return false;
    }

    virtual void DoActivateWeapon() { }

private:

    void ActivateWeapon()
    {
        if (m_IsActivated)
            return;

        m_IsActivated = true;

        DoActivateWeapon();
    }

private:

    InstanceScript* pInstance;
    WeaponTypes m_WeaponType;
    bool m_IsActivated;

};

class npc_siegecrafter_blackfuse_laser_turret : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_laser_turret() : CreatureScript("npc_siegecrafter_blackfuse_laser_turret") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_laser_turretAI(creature);
        }

        struct npc_siegecrafter_blackfuse_laser_turretAI : public npc_siegecrafter_blackfuse_siege_activated_weaponAI
        {
            npc_siegecrafter_blackfuse_laser_turretAI(Creature* creature) : npc_siegecrafter_blackfuse_siege_activated_weaponAI(creature)
            {
            }

            void JustSummoned(Creature* summon) override
            {
                npc_siegecrafter_blackfuse_siege_activated_weaponAI::JustSummoned(summon);

                if (summon->GetEntry() == NPC_LASER_TARGET_BUNNY)
                {
                    DoCastLaserRay(summon);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_LASER_TURRET:
                        DoUseLaserTurret();
                        break;
                }
            }

            void DoActivateWeapon() override
            {
                events.ScheduleEvent(EVENT_LASER_TURRET, TIMER_LASER_TURRET_ACTIVATION);
            }

            void DoUseLaserTurret()
            {
                if (IsOvercharged())
                {
                    if (Creature* l_Blackfuse = GetBlackfuse(me))
                        l_Blackfuse->AI()->Talk(ScriptedTexts::SAY_LASER);

                    CreateLaserCirclePath(20.f, 2 * float(M_PI));
                    CreateLaserCirclePath(40.f, float(M_PI) / 2);
                    CreateLaserCirclePath(60.f, 3 * float(M_PI) / 2);
                }
                else
                {
                    DoCast(me, SPELL_LASER_TURRET_TARGETTING_FORCE);
                }
            }

            void DoCastLaserRay(Creature* target)
            {
                if (IsOvercharged())
                {
                    Position pos = me->GetPosition();

                    float l_Angle = me->GetOrientation();
                    /*float l_Dist = 23.0f; // 6.91f;
                    pos.m_positionX = pos.GetPositionX() + l_Dist * cosf(l_Angle);
                    pos.m_positionY = pos.GetPositionY() + l_Dist * sinf(l_Angle);
                    pos.m_positionZ = pos.GetPositionZ() + 12.3f;*/

                    float l_Dist = 6.91f;
                    pos.m_positionX = pos.GetPositionX() + me->GetTransOffsetX();
                    pos.m_positionY = pos.GetPositionY() + me->GetTransOffsetY();
                    pos.m_positionZ = pos.GetPositionZ() + me->GetTransOffsetZ();

                    if (Unit* l_Base1 = me->GetVehicleBase())
                    {
                        pos.m_positionX += l_Base1->GetTransOffsetX();
                        pos.m_positionY += l_Base1->GetTransOffsetY();
                        pos.m_positionZ += l_Base1->GetTransOffsetZ();
                    }

                    pos.m_positionX += l_Dist * cosf(l_Angle);
                    pos.m_positionY += l_Dist * sinf(l_Angle);
                    pos.m_positionZ += + 12.3f;

                    if (Creature* pDummy = me->SummonCreature(WORLD_TRIGGER, pos, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, Timers::TIMER_LASER_DURATION_HEROIC))
                    {
                        pDummy->SetDisableGravity(true);
                        pDummy->SetDisplayId(11686);
                        pDummy->CastSpell(target, SPELL_DESINTEGRATION_LASER);
                    }
                }
                else
                    DoCast(target, SPELL_DESINTEGRATION_LASER);
            }

            void CreateLaserCirclePath(float radius, float skipAngle)
            {
                const int sectors = 32;
                const float step = -float(M_PI) / (sectors / 2);
                float angle = skipAngle;

                Movement::PointsArray points;
                for (uint8 i = 0; i < sectors - 1; angle += step, ++i)
                {
                    G3D::Vector3 point;
                    point.x = centerPos.GetPositionX() + radius * cosf(angle);
                    point.y = centerPos.GetPositionY() + radius * sinf(angle);
                    point.z = centerPos.GetPositionZ();
                    points.push_back(point);
                }

                // HACK:
                // It's better to create a unit first and then fill it's MoveSplineInit, but (it's first way) we need a first position to spawn a unit, so fill a temporary array with points, then create a unit.
                // Or the second way is to use relocate & updatevisibility to relocate the unit from the spawn position to the first circle position.

                Movement::Location const& firstPoint = points[0];
                if (Creature* pLaser = me->SummonCreature(NPC_LASER_TARGET_BUNNY, firstPoint.x, firstPoint.y, firstPoint.z, 0.0f))
                {
                    pLaser->SetDisableGravity(true);
                    pLaser->AddAura(SPELL_LASER_GROUND_EFFECT_PERIODIC, pLaser);

                    Movement::MoveSplineInit init(pLaser);

                    for (G3D::Vector3& l_Point : points)
                        init.Path().push_back(l_Point);

                    init.SetWalk(false);
                    init.SetVelocity(10.0f);
                    init.SetSmooth();
                    init.Launch();
                }
            }

        private:

        };
};

class npc_siegecrafter_blackfuse_laser_target : public CreatureScript
{
    public:
        npc_siegecrafter_blackfuse_laser_target() : CreatureScript("npc_siegecrafter_blackfuse_laser_target") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_laser_targetAI(creature);
        }

        struct npc_siegecrafter_blackfuse_laser_targetAI : public ScriptedAI
        {
            npc_siegecrafter_blackfuse_laser_targetAI(Creature* creature) : ScriptedAI(creature),
                m_IsOvercharged(false), m_TargetGuid(ObjectGuid::Empty)
            {
                pInstance = creature->GetInstanceScript();

                // speed from sniffs
                me->SetSpeed(MOVE_RUN, 0.7857143f);
                me->SetSpeed(MOVE_WALK, 2.2f);

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetDisplayId(11686);
            }

            void Reset() override
            {
                events.Reset();
            }

            void IsSummonedBy(Unit* owner) override
            {
                if (owner && owner->GetEntry() == NPC_OVERCHARGED_LASER_TURRET)
                {
                    m_IsOvercharged = true;
                }

                if (!m_IsOvercharged)
                {
                    events.ScheduleEvent(Events::EVENT_LASER_TARGET_TARGET, Timers::TIMER_LASER_TARGET_MOVE);
                    events.ScheduleEvent(Events::EVENT_LASER_TARGET_TARGET, Timers::TIMER_LASER_DURATION_NORMAL + Timers::TIMER_LASER_TURRET_ACTIVATION);
                    events.ScheduleEvent(Events::EVENT_LASER_TARGET_TARGET_STOP, (2 * Timers::TIMER_LASER_DURATION_NORMAL) + Timers::TIMER_LASER_TURRET_ACTIVATION);
                }
            }

            //void SplineMovementUpdate(uint32 p_Type, uint32 p_Id) override
            void MovementInform(uint32 p_Type, uint32 p_Id) override
            {
                if (m_IsOvercharged && p_Type == Movement::MoveSpline::UpdateResult::Result_Arrived)
                {
                    me->RemoveAura(Spells::SPELL_DESINTEGRATION_LASER);
                    me->RemoveAura(Spells::SPELL_LASER_GROUND_EFFECT_PERIODIC);

                    me->DespawnOrUnsummon(Timers::TIMER_SUPERHEATED_DURATION);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 l_EventId = events.ExecuteEvent())
                {
                    switch (l_EventId)
                    {
                        case Events::EVENT_LASER_TARGET_TARGET:
                            SelectNextTarget();
                            break;
                        case Events::EVENT_LASER_TARGET_TARGET_STOP:
                            ClearTarget();
                            me->DespawnOrUnsummon(Timers::TIMER_SUPERHEATED_DURATION);
                            break;
                    }
                }
            }

        private:

            void SelectNextTarget()
            {
                ClearTarget();

                if (Unit* l_Target = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true, -SPELL_ON_CONVEYOR))
                {
                    if (!me->HasAura(Spells::SPELL_LASER_GROUND_EFFECT_PERIODIC))
                        me->AddAura(Spells::SPELL_LASER_GROUND_EFFECT_PERIODIC, me);

                    DoCast(l_Target, SPELL_LOCKED_ON);
                    me->ClearUnitState(UNIT_STATE_CASTING);

                    me->GetMotionMaster()->MoveFollow(l_Target, 0.0f, 0.0f);

                    m_TargetGuid = l_Target->GetGUID();
                }
            }

            void ClearTarget()
            {
                me->StopMoving();

                me->RemoveAura(Spells::SPELL_LASER_GROUND_EFFECT_PERIODIC);

                if (Unit* l_OldTarget = ObjectAccessor::GetUnit(*me, m_TargetGuid))
                {
                    l_OldTarget->RemoveAura(SPELL_LOCKED_ON);
                }

                m_TargetGuid = ObjectGuid::Empty;
            }

        private:

            InstanceScript* pInstance;
            bool m_IsOvercharged;
            ObjectGuid m_TargetGuid;
        };
};

class npc_siegecrafter_blackfuse_crawler_mine : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_crawler_mine() : CreatureScript("npc_siegecrafter_blackfuse_crawler_mine") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_crawler_mineAI(creature);
        }

        struct npc_siegecrafter_blackfuse_crawler_mineAI : public npc_siegecrafter_blackfuse_siege_activated_weaponAI
        {
            npc_siegecrafter_blackfuse_crawler_mineAI(Creature* creature) : npc_siegecrafter_blackfuse_siege_activated_weaponAI(creature)
            {
                //ApplyAllImmunities(true);

                ApplyCrawlerMineImmune(false);

                // from sniffs
                me->SetSpeed(MOVE_RUN, 0.8571429f);
                me->SetSpeed(MOVE_WALK, 1.6f);

                m_CrawlerMineCounter = 0;
                m_CrawlerMineFixateTargetGuid = ObjectGuid::Empty;
                m_IsExploded = false;
                m_CheckFixateTimer = 1000;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE && id == EVENT_JUMP)
                {
                    // targetting was triggered by 'jump' spell
                    CrawlerMineMove(false);
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_CRAWLER_MINE_COUNTER)
                {
                    m_CrawlerMineCounter = data;
                }
            }

            void SetObjectGuid(ObjectGuid guid, int32 type)
            {
                if (type == DATA_CRAWLER_MINE_FIXATE)
                {
                    SetFixateTargetGuid(guid);
                }
            }

            void DoAction(const int32 action) override
            {
                npc_siegecrafter_blackfuse_siege_activated_weaponAI::DoAction(action);

                if (action == ACTION_CRAWLER_MINE_START)
                {
                    events.ScheduleEvent(EVENT_CRAWLER_MINE_START, 1000);
                }
            }

            void JustDied(Unit* killer) override
            {
                if (IsOvercharged())
                    CreateNewCrawlerMines(2);

                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (m_IsExploded)
                    return;

                events.Update(diff);

                CheckFixateTarget(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void ApplyCrawlerMineImmune(bool apply)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, apply);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, apply);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, apply);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, apply);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_CRAWLER_MINE_PREPARE:
                        DoCrawlerMinePrepare();
                        break;
                    case EVENT_CRAWLER_MINE:
                        DoCrawlerMineJump();
                        break;
                    case EVENT_CRAWLER_MINE_START:
                        CrawlerMineMove(true);
                        break;
                    case EVENT_CRAWLER_MINE_READY_TO_GO:
                        DoReadyToGo();
                        break;
                }
            }

            void DoActivateWeapon()
            {
                events.ScheduleEvent(EVENT_CRAWLER_MINE_PREPARE, 100);
                events.ScheduleEvent(EVENT_CRAWLER_MINE, m_CrawlerMineCounter == 0 ? TIMER_CRAWLER_MINE_ACTIVATION_FIRST : m_CrawlerMineCounter * TIMER_CRAWLER_MINE_ACTIVATION);
            }

            void DoCrawlerMinePrepare()
            {
                me->ExitVehicle();
            }

            void DoCrawlerMineJump()
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                me->CastSpell(crawlerMineJumpPos.GetPositionX(), crawlerMineJumpPos.GetPositionY(), crawlerMineJumpPos.GetPositionZ(), SPELL_CRAWLER_MINE_JUMP, true);
            }

            void DoReadyToGo()
            {
                me->RemoveAura(SPELL_BREAK_IN_PERIOD);
                me->AddAura(SPELL_READY_TO_GO, me);

                ApplyCrawlerMineImmune(true);
            }

            void DoExplode()
            {
                m_IsExploded = true;

                DoCast(me, SPELL_DETONATE, true);

                me->GetMotionMaster()->MovementExpired(false);

                if (Unit* target = GetFixateTarget())
                    target->RemoveAura(SPELL_CRAWLER_MINE_FIXATE, me->GetGUID());

                if (IsOvercharged())
                    CreateNewCrawlerMines(2);

                me->DespawnOrUnsummon(2000);
            }

            void CrawlerMineMove(bool withTargetting)
            {
                me->AddAura(SPELL_BREAK_IN_PERIOD, me);

                if (withTargetting)
                    DoCastAOE(SPELL_CRAWLER_MINE_FIXATE_TARGETTING, true);

                events.ScheduleEvent(EVENT_CRAWLER_MINE_READY_TO_GO, TIMER_CRAWLER_MINE_READY_TO_GO);
            }

            void SetFixateTargetGuid(ObjectGuid guid)
            {
                m_CrawlerMineFixateTargetGuid = guid;

                if (Unit* target = GetFixateTarget())
                {
                    DoCast(target, SPELL_CRAWLER_MINE_FIXATE);
                    me->ClearUnitState(UNIT_STATE_CASTING);

                    me->GetMotionMaster()->MoveFollow(target, 0.f, 0.f);
                }
            }

            Unit* GetFixateTarget()
            {
                return ObjectAccessor::GetUnit(*me, m_CrawlerMineFixateTargetGuid);
            }

            void CheckFixateTarget(const uint32 diff)
            {
                if (m_IsExploded)
                    return;

                if (m_CheckFixateTimer <= diff)
                {
                    m_CheckFixateTimer = 500;

                    if (Unit* target = GetFixateTarget())
                    {
                        if (me->GetDistance(target) <= 1.f)
                        {
                            DoExplode();
                        }
                    }
                }
                else
                {
                    m_CheckFixateTimer -= diff;
                }
            }

            void CreateNewCrawlerMines(uint8 count)
            {
                if (count < 1)
                    return;

                for (uint8 i = 0; i < count; ++i)
                {
                    if (Creature* pMine = me->SummonCreature(NPC_CRAWLER_MINE, *me))
                    {
                        pMine->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                        pMine->AI()->DoAction(ACTION_CRAWLER_MINE_START);
                    }
                }
            }

        private:

            uint8 m_CrawlerMineCounter;
            ObjectGuid m_CrawlerMineFixateTargetGuid;
            bool m_IsExploded;
            uint32 m_CheckFixateTimer;

        };
};

class npc_siegecrafter_blackfuse_electromagnet : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_electromagnet() : CreatureScript("npc_siegecrafter_blackfuse_electromagnet") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_electromagnetAI(creature);
        }

        struct npc_siegecrafter_blackfuse_electromagnetAI : public npc_siegecrafter_blackfuse_siege_activated_weaponAI
        {
            npc_siegecrafter_blackfuse_electromagnetAI(Creature* creature) : npc_siegecrafter_blackfuse_siege_activated_weaponAI(creature),
                m_IsPulling(false)
            {
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ELECTROMAGNET:
                        DoUseElectromagnet();
                        break;
                    case EVENT_ELECTROMAGNET_SWITCH:
                        SwitchElectroMagnet();
                        events.ScheduleEvent(EVENT_ELECTROMAGNET_SWITCH, TIMER_ELECTROMAGNET_SWITCH);
                        break;
                }
            }

            void DoActivateWeapon() override
            {
                events.ScheduleEvent(EVENT_ELECTROMAGNET, TIMER_ELECTROMAGNET_ACTIVATION);
            }

            void DoUseElectromagnet()
            {
                if (IsOvercharged())
                {
                    if (Creature* l_Blackfuse = GetBlackfuse(me))
                        l_Blackfuse->AI()->Talk(ScriptedTexts::SAY_MAGNET);

                    m_IsPulling = true;
                    DoCast(me, SPELL_MAGNETIC_CRUSH_PULL);

                    events.ScheduleEvent(EVENT_ELECTROMAGNET_SWITCH, TIMER_ELECTROMAGNET_SWITCH);
                }
                else
                {
                    DoCast(me, SPELL_MAGNETIC_CRUSH);
                }
            }

            void SwitchElectroMagnet()
            {
                if (m_IsPulling)
                {
                    m_IsPulling = false;

                    DoCast(me, SPELL_MAGNETIC_CRUSH_PUSH);
                }
                else
                {
                    m_IsPulling = true;

                    DoCast(me, SPELL_MAGNETIC_CRUSH_PULL);
                }
            }

        private:

            bool m_IsPulling;

        };
};

class npc_siegecrafter_blackfuse_shockwave_missile_turret : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_shockwave_missile_turret() : CreatureScript("npc_siegecrafter_blackfuse_shockwave_missile_turret") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_shockwave_missile_turretAI(creature);
        }

        struct npc_siegecrafter_blackfuse_shockwave_missile_turretAI : public npc_siegecrafter_blackfuse_siege_activated_weaponAI
        {
            npc_siegecrafter_blackfuse_shockwave_missile_turretAI(Creature* creature) : npc_siegecrafter_blackfuse_siege_activated_weaponAI(creature)
            {
            }

            void SummonedCreatureDies(Creature* p_Creature, Unit* p_Killer) override
            {
                if (p_Creature->GetEntry() == Adds::NPC_OVERCHARGED_SHOCKWAVE_MISSILE)
                {
                    DoUseNextShockwaveMissileTurret();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_SHOCKWAVE_MISSILE_TURRET:
                        DoUseShockwaveMissileTurret();
                        break;
                }
            }

            void DoActivateWeapon() override
            {
                events.ScheduleEvent(EVENT_SHOCKWAVE_MISSILE_TURRET, TIMER_SHOCKWAVE_MISSILE_ACTIVATION);
            }

            void DoUseShockwaveMissileTurret()
            {
                if (IsOvercharged())
                {
                    if (Creature* l_Blackfuse = GetBlackfuse(me))
                        l_Blackfuse->AI()->Talk(ScriptedTexts::SAY_MISSILE);
                }

                m_LastMissilePosIndex = urand(0, SHOCKWAVE_MOSSILE_POS_COUNT - 1);

                DoCastMissileTurret();
            }

            void DoUseNextShockwaveMissileTurret()
            {
                if (m_MissileCounter >= 3)
                    return;

                ++m_LastMissilePosIndex;
                if (m_LastMissilePosIndex >= SHOCKWAVE_MOSSILE_POS_COUNT)
                    m_LastMissilePosIndex = 0;

                DoCastMissileTurret();
            }

            void DoCastMissileTurret()
            {
                me->CastSpell(shockwaveMissileTurretPos[m_LastMissilePosIndex].GetPositionX(), shockwaveMissileTurretPos[m_LastMissilePosIndex].GetPositionY(), shockwaveMissileTurretPos[m_LastMissilePosIndex].GetPositionZ(), IsHeroic() ? SPELL_SHOCKWAVE_MISSILE_MISSILE_2 : SPELL_SHOCKWAVE_MISSILE_MISSILE, false);

                ++m_MissileCounter;
            }

        private:

            uint32 m_LastMissilePosIndex = 0;
            uint32 m_MissileCounter = 0;

        };
};

class npc_siegecrafter_blackfuse_shockwave_missile : public CreatureScript
{
    public:

        npc_siegecrafter_blackfuse_shockwave_missile() : CreatureScript("npc_siegecrafter_blackfuse_shockwave_missile") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_shockwave_missileAI(creature);
        }

        struct npc_siegecrafter_blackfuse_shockwave_missileAI : public npc_siegecrafter_blackfuse_siege_activated_weaponAI
        {
            npc_siegecrafter_blackfuse_shockwave_missileAI(Creature* creature) : npc_siegecrafter_blackfuse_siege_activated_weaponAI(creature)
            {
                if (!IsOvercharged())
                {
                    me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                }
                else
                {
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                }

                m_ShockwaveMissileCounter = 0;
            }

            void IsSummonedBy(Unit* owner) override
            {
                DoCast(me, IsOvercharged() ? SPELL_SHOCKWAVE_MISSILE_VISUAL_2 : SPELL_SHOCKWAVE_MISSILE_VISUAL_1);

                m_ShockwaveMissileCounter = 0;

                events.ScheduleEvent(EVENT_SHOCKWAVE_MISSILE, TIMER_SHOCKWAVE_MISSILE_FIRST);

                me->SetOrientation(me->GetAngle(&centerPos));
                me->SetFacingTo(me->GetAngle(&centerPos));
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_SHOCKWAVE_MISSILE:
                        DoShockwaveMissile();
                        events.ScheduleEvent(EVENT_SHOCKWAVE_MISSILE, TIMER_SHOCKWAVE_MISSILE);
                        break;
                }
            }

            void DoShockwaveMissile()
            {
                uint32 spellId = GetSpellForMissile();

                if (spellId)
                {
                    DoCast(me, spellId);
                }
                else
                {
                    me->DespawnOrUnsummon(500);
                }

                ++m_ShockwaveMissileCounter;

                if (IsOvercharged() && m_ShockwaveMissileCounter >= 6)
                {
                    m_ShockwaveMissileCounter = 0;
                }
            }

            uint32 GetSpellForMissile() const
            {
                switch (m_ShockwaveMissileCounter)
                {
                    case 0: return SPELL_SHOCKWAVE_MISSILE_DMG_10;
                    case 1: return SPELL_SHOCKWAVE_MISSILE_DMG_25;
                    case 2: return SPELL_SHOCKWAVE_MISSILE_DMG_45;
                    case 3: return SPELL_SHOCKWAVE_MISSILE_DMG_65;
                    case 4: return SPELL_SHOCKWAVE_MISSILE_DMG_85;
                    case 5: return SPELL_SHOCKWAVE_MISSILE_DMG_105;
                }

                return 0;
            }

        private:

            uint32 m_ShockwaveMissileCounter;

        };
};

class npc_siegecrafter_blackfuse_laser_array : public CreatureScript
{
    public:
        npc_siegecrafter_blackfuse_laser_array() : CreatureScript("npc_siegecrafter_blackfuse_laser_array") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_laser_arrayAI(creature);
        }

        struct npc_siegecrafter_blackfuse_laser_arrayAI : public Scripted_NoMovementAI
        {
            npc_siegecrafter_blackfuse_laser_arrayAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset() override
            {
                me->AddAura(SPELL_CONVEYOR_DEATH_BEAM_DUMMY, me);

                me->CastSpell(me, SPELL_CONVEYOR_DEATH_BEAM_AREATRIGGER, true);
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class npc_siegecrafter_blackfuse_steam_vent : public CreatureScript
{
    public:
        npc_siegecrafter_blackfuse_steam_vent() : CreatureScript("npc_siegecrafter_blackfuse_steam_vent") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siegecrafter_blackfuse_steam_ventAI(creature);
        }

        struct npc_siegecrafter_blackfuse_steam_ventAI : public Scripted_NoMovementAI
        {
            npc_siegecrafter_blackfuse_steam_ventAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset() override
            {
                me->AddAura(SPELL_STEAM_VENT, me);
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class spell_siegecrafter_blackfuse_electromagnetic_barrier : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_electromagnetic_barrier() : SpellScriptLoader("spell_siegecrafter_blackfuse_electromagnetic_barrier") { }

        class spell_siegecrafter_blackfuse_electromagnetic_barrier_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_siegecrafter_blackfuse_electromagnetic_barrier_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetCaster() || !GetUnitOwner())
                    return;

                // HACK: prevent from applying animation on caster, because caster should be dead
                if (GetCaster() == GetUnitOwner())
                    return;

                GetUnitOwner()->AddAura(SPELL_ELECTROMAGNETIC_BARRIER_DUMMY, GetUnitOwner());
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->RemoveAura(SPELL_ELECTROMAGNETIC_BARRIER_DUMMY);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_siegecrafter_blackfuse_electromagnetic_barrier_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_siegecrafter_blackfuse_electromagnetic_barrier_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_siegecrafter_blackfuse_electromagnetic_barrier_AuraScript();
        }
};

class spell_siegecrafter_blackfuse_laser_turret_targetting : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_laser_turret_targetting() : SpellScriptLoader("spell_siegecrafter_blackfuse_laser_turret_targetting") { }

        class spell_siegecrafter_blackfuse_laser_turret_targetting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_laser_turret_targetting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_LASER_TURRET_TARGETTING_SUMMON, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_laser_turret_targetting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_laser_turret_targetting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_laser_turret_targetting_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_laser_ground_effect : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_laser_ground_effect() : SpellScriptLoader("spell_siegecrafter_blackfuse_laser_ground_effect") { }

        class spell_siegecrafter_blackfuse_laser_ground_effect_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_siegecrafter_blackfuse_laser_ground_effect_AuraScript);

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                std::vector<AreaTrigger*> areaTriggers = GetCaster()->GetAreaTriggers(SPELL_LASER_GROUND_EFFECT);
                // todo redo this
                //GetCaster()->GetAreaTriggerList(areaTriggers, SPELL_LASER_GROUND_EFFECT);
                /*areaTriggers.remove_if([&](AreaTrigger* areaTrigger) -> bool
                {
                    return GetUnitOwner()->GetExactDist(areaTrigger) > LASER_GROUND_EFFECT_SIZE;
                });*/

                if (!areaTriggers.empty())
                {
                    PreventDefaultAction();
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_siegecrafter_blackfuse_laser_ground_effect_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_siegecrafter_blackfuse_laser_ground_effect_AuraScript();
        }
};

class spell_siegecrafter_blackfuse_crawler_mine_targetting : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_crawler_mine_targetting() : SpellScriptLoader("spell_siegecrafter_blackfuse_crawler_mine_targetting") { }

        class spell_siegecrafter_blackfuse_crawler_mine_targetting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_crawler_mine_targetting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->SetGUID(GetHitUnit()->GetGUID(), DATA_CRAWLER_MINE_FIXATE);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_crawler_mine_targetting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_crawler_mine_targetting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_crawler_mine_targetting_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_magnetic_pulse : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_magnetic_pulse() : SpellScriptLoader("spell_siegecrafter_blackfuse_magnetic_pulse") { }

        class spell_siegecrafter_blackfuse_magnetic_pulse_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_magnetic_pulse_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    if (obj->GetEntry() != NPC_SAWBLADE)
                        return true;

                    if (Creature* creature = obj->ToCreature())
                    {
                        if (creature->AI()->GetData(DATA_SAWBLADE_ON_GROUND) == 1 &&
                            creature->AI()->GetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PULL) == 0)
                        {
                            return false;
                        }
                    }

                    return true;
                });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pCreature = GetHitUnit()->ToCreature())
                {
                    pCreature->AI()->SetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PULL, DONE);
                    //pCreature->CastSpell(GetCaster(), SPELL_MAGNETIC_PULSE_JUMP, true);
                    //pCreature->GetMotionMaster()->MovePoint(POINT_SAWBLADE_ELECTROMAGNET, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ());
                    const Position& randomPos = GetNearestPullPositionToMagnet(GetCaster());
                    pCreature->GetMotionMaster()->MoveCharge(randomPos.GetPositionX(), randomPos.GetPositionY(), randomPos.GetPositionZ());
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_magnetic_pulse_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_magnetic_pulse_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_magnetic_pulse_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_magnetic_pulse_pull : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_magnetic_pulse_pull() : SpellScriptLoader("spell_siegecrafter_blackfuse_magnetic_pulse_pull") { }

        class spell_siegecrafter_blackfuse_magnetic_pulse_pull_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_magnetic_pulse_pull_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    if (obj->GetEntry() != NPC_SAWBLADE)
                        return true;

                    if (Creature* creature = obj->ToCreature())
                    {
                        if (creature->AI()->GetData(DATA_SAWBLADE_ON_GROUND) == 1 &&
                            creature->AI()->GetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PULL) == 0)
                        {
                            return false;
                        }
                    }

                    return true;
                });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pCreature = GetHitUnit()->ToCreature())
                {
                    pCreature->StopMoving();
                    pCreature->GetMotionMaster()->MovementExpired(false);

                    pCreature->AI()->SetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PULL, DONE);
                    //pCreature->CastSpell(GetCaster(), SPELL_MAGNETIC_PULSE_JUMP_PULL, true);
                    //pCreature->GetMotionMaster()->MovePoint(POINT_SAWBLADE_ELECTROMAGNET, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ());
                    const Position& randomPos = GetNearestPullPositionToMagnet(GetCaster());
                    pCreature->GetMotionMaster()->MoveCharge(randomPos.GetPositionX(), randomPos.GetPositionY(), randomPos.GetPositionZ());
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_magnetic_pulse_pull_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_magnetic_pulse_pull_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_magnetic_pulse_pull_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_magnetic_pulse_push : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_magnetic_pulse_push() : SpellScriptLoader("spell_siegecrafter_blackfuse_magnetic_pulse_push") { }

        class spell_siegecrafter_blackfuse_magnetic_pulse_push_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_magnetic_pulse_push_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    if (obj->GetEntry() != NPC_SAWBLADE)
                        return true;

                    if (Creature* creature = obj->ToCreature())
                    {
                        if (creature->AI()->GetData(DATA_SAWBLADE_ON_GROUND) == 1 &&
                            creature->AI()->GetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH) == 0)
                        {
                            return false;
                        }
                    }

                    return true;
                });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pCreature = GetHitUnit()->ToCreature())
                {
                    pCreature->StopMoving();
                    pCreature->GetMotionMaster()->MovementExpired(false);

                    pCreature->AI()->SetData(DATA_SAWBLADE_TO_ELECTROMAGNET_PUSH, DONE);

                    //pCreature->CastSpell(sawbladePushPos.GetPositionX() + frand(0.f, 10.f), sawbladePushPos.GetPositionY() + frand(0.f, 20.f), sawbladePushPos.GetPositionZ(), SPELL_MAGNETIC_PULSE_JUMP_PUSH, true);
                    //pCreature->GetMotionMaster()->MovePoint(POINT_SAWBLADE_ELECTROMAGNET, sawbladePushPos.GetPositionX() + frand(0.f, 10.f), sawbladePushPos.GetPositionY() + frand(0.f, 40.f), sawbladePushPos.GetPositionZ());
                    const Position& randomPos = sawbladePushPos[urand(0, SAWBLADE_PUSH_POS_COUNT - 1)];
                    pCreature->GetMotionMaster()->MoveCharge(randomPos.GetPositionX(), randomPos.GetPositionY(), randomPos.GetPositionZ());
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_magnetic_pulse_push_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_magnetic_pulse_push_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_magnetic_pulse_push_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_shockwave_missile_dmg : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_shockwave_missile_dmg() : SpellScriptLoader("spell_siegecrafter_blackfuse_shockwave_missile_dmg") { }

        class spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                SpellInfo const* spellInfo = GetSpellInfo();
                //float maxRadius = spellInfo->Effects[EFFECT_1].CalcRadius();
                float maxRadius = spellInfo->GetEffect(EFFECT_1)->CalcRadius();
                float minRadius = maxRadius - 20.f;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    if (caster->GetExactDist(obj) >= maxRadius ||
                        caster->GetExactDist(obj) <= minRadius)
                        return true;

                    return false;
                });
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENTRY);

                if (m_scriptSpellId == SPELL_SHOCKWAVE_MISSILE_DMG_10)
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript::FilterTargets, EFFECT_3, TARGET_UNIT_SRC_AREA_ENEMY);
                else
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript::FilterTargets, EFFECT_3, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_shockwave_missile_dmg_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_launch_sawblade_aoe : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_launch_sawblade_aoe() : SpellScriptLoader("spell_siegecrafter_blackfuse_launch_sawblade_aoe") { }

        class spell_siegecrafter_blackfuse_launch_sawblade_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_launch_sawblade_aoe_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_LAUNCH_SAWBLADE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_launch_sawblade_aoe_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_launch_sawblade_aoe_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_launch_sawblade : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_launch_sawblade() : SpellScriptLoader("spell_siegecrafter_blackfuse_launch_sawblade") { }

        class spell_siegecrafter_blackfuse_launch_sawblade_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_launch_sawblade_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                LaunchSawblade(GetCaster(), GetHitUnit());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_launch_sawblade_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            void LaunchSawblade(Unit* caster, Unit* target)
            {
                // HACK: it's blizzlike to use passenger sawblade
                // but it causes bugs.
                // Use an alternative way.
                /*if (Vehicle* pVehicle = caster->GetVehicleKit())
                {
                    if (Unit* pSawblade = pVehicle->GetPassenger(SEAT_SAWBLADE))
                    {
                        pSawblade->ExitVehicle();
                        pSawblade->StopMoving();
                        pSawblade->CastSpell(target, SPELL_LAUNCH_SAWBLADE_JUMP, true);
                    }
                }*/
                if (Creature* pSawblade = caster->SummonCreature(NPC_SAWBLADE, *caster))
                {
                    pSawblade->AddAura(SPELL_LAUNCH_SAWBLADE_AURA, pSawblade);
                    pSawblade->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + 0.4f, SPELL_LAUNCH_SAWBLADE_JUMP, true);
                }
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_launch_sawblade_SpellScript();
        }
};

class spell_siegecrafter_blackfuse_death_from_above : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_death_from_above() : SpellScriptLoader("spell_siegecrafter_blackfuse_death_from_above") { }

        class spell_siegecrafter_blackfuse_death_from_above_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_death_from_above_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                float x, y;
                GetCaster()->GetPosition(x, y);

                const float ratio = 0.1f;
                float speedxy = 0.f;
                float speedz = float(300) * ratio;

                GetCaster()->KnockbackFrom(x, y, speedxy, speedz);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_siegecrafter_blackfuse_death_from_above_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
                OnEffectHitTarget += SpellEffectFn(spell_siegecrafter_blackfuse_death_from_above_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }

        private:

        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_death_from_above_SpellScript();
        }
};


class spell_siegecrafter_blackfuse_pipe_transfer_jump : public SpellScriptLoader
{
    public:
        spell_siegecrafter_blackfuse_pipe_transfer_jump() : SpellScriptLoader("spell_siegecrafter_blackfuse_pipe_transfer_jump") { }

        class spell_siegecrafter_blackfuse_pipe_transfer_jump_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siegecrafter_blackfuse_pipe_transfer_jump_SpellScript);

            void FilterTarget(WorldObject*& target)
            {
                if (!GetCaster())
                    return;

                const Unit* caster = GetCaster();

                Creature* nearest = caster->FindNearestCreature(723454, 200.0f);

                target = nearest;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;
            }

            void Register()
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_siegecrafter_blackfuse_pipe_transfer_jump_SpellScript::FilterTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siegecrafter_blackfuse_pipe_transfer_jump_SpellScript::FilterTargets, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siegecrafter_blackfuse_pipe_transfer_jump_SpellScript();
        }
};

struct spell_area_siegecrafter_blackfuse_laser_ground_effect : AreaTriggerAI
{
    spell_area_siegecrafter_blackfuse_laser_ground_effect(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        at->SetDuration(Timers::TIMER_SUPERHEATED_DURATION);
    }

    void OnUnitEnter(Unit* p_Target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (IsOnConveyor(p_Target))
            return;

        if (!p_Target->IsPlayer())
            return;

        caster->AddAura(SPELL_SUPERHEATED_AURA, p_Target);
    }

    bool OnRemoveTarget(Unit* target, bool /*byExpire*/)
    {
    }
};

struct spell_area_siegecrafter_blackfuse_magnetic_crush : AreaTriggerAI
{
    spell_area_siegecrafter_blackfuse_magnetic_crush(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUpdate(uint32 p_Diff) override
    {
        if (m_IsUpdated)
            return;

        m_IsUpdated = true;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_CRUSH_DMG);

        /*l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            l_Caster->AddAura(spellInfo, MAX_EFFECT_MASK, p_Player);

            if (p_Player->GetForcedMovement().IsActive())
                p_Player->GetForcedMovement().Stop();

            p_Player->GetForcedMovement().StartPullingTo(*l_Caster, 2.f);
        });*/
    }

    void OnRemove()
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

       /* l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            p_Player->RemoveAura(SPELL_MAGNETIC_CRUSH_DMG);

            p_Player->GetForcedMovement().Stop();
        });*/
    }

    bool m_IsUpdated = false;
};

struct spell_area_siegecrafter_blackfuse_magnetic_crush_pull : AreaTriggerAI
{
    spell_area_siegecrafter_blackfuse_magnetic_crush_pull(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUpdate(uint32 p_Diff) override
    {
        if (m_IsUpdated)
            return;

        m_IsUpdated = true;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_CRUSH_DMG);

        /*l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            l_Caster->AddAura(spellInfo, MAX_EFFECT_MASK, p_Player);

            if (p_Player->GetForcedMovement().IsActive())
                p_Player->GetForcedMovement().Stop();

            p_Player->GetForcedMovement().StartPullingTo(*l_Caster, 2.f);
        });*/
    }

    void OnRemove()
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        /*l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            p_Player->RemoveAura(SPELL_MAGNETIC_CRUSH_DMG);

            p_Player->GetForcedMovement().Stop();
        });*/
    }

    bool m_IsUpdated = false;
};

struct spell_area_siegecrafter_blackfuse_magnetic_crush_push : AreaTriggerAI
{
    spell_area_siegecrafter_blackfuse_magnetic_crush_push(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUpdate(uint32 p_Diff) override
    {
        if (m_IsUpdated)
            return;

        m_IsUpdated = true;

        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_CRUSH_DMG);

        /*l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            l_Caster->AddAura(spellInfo, MAX_EFFECT_MASK, p_Player);

            if (p_Player->GetForcedMovement().IsActive())
                p_Player->GetForcedMovement().Stop();

            p_Player->GetForcedMovement().StartPushingFrom(*l_Caster, 2.f);
        });*/
    }

    void OnRemove() override
    {
        Unit* l_Caster = at->GetCaster();
        if (!l_Caster)
            return;

        /*l_Caster->GetMap()->ForEachPlayer([&](Player* p_Player) -> void
        {
            if (IsOnConveyor(p_Player))
                return;

            p_Player->RemoveAura(SPELL_MAGNETIC_CRUSH_DMG);

            p_Player->GetForcedMovement().Stop();
        });*/
    }

    bool m_IsUpdated = false;
};


struct spell_area_siegecrafter_blackfuse_conveyor_death_beam : AreaTriggerAI
{
    spell_area_siegecrafter_blackfuse_conveyor_death_beam(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* p_Target)
    {
        if (Unit* l_Caster = at->GetCaster())
        {
            if (!p_Target->IsPlayer())
                return;

            if (!p_Target->IsHostileTo(l_Caster))
                return;

            p_Target->CastSpell(p_Target, SPELL_MATTER_PURIFICATION_BEAM, true);
        }

        return;
    }
};

bool CanTriggerPipeTransfer(Player* player)
{
    // Handle if player is jumping by pipe transfer
    if (player->GetMotionMaster()->GetCurrentMovementGeneratorType() == EFFECT_MOTION_TYPE)
    {
        float x, y, z;
        if (player->GetMotionMaster()->GetDestination(x, y, z))
            if (player->GetPositionZ() < z)
                return false;
    }

    if (player->HasAura(SPELL_PIPE_TRANSFER_TO_EXIT) ||
        player->HasAura(SPELL_PIPE_TRANSFER_TO_ENTRANCE) ||
        player->HasAura(SPELL_PIPE_TRANSFER_EJECTION))
        return false;

    return true;
}

// 9250 9251 9252 -- 'entrance' triggers (from left to right)
class at_siegecrafter_blackfuse_pipe_entrance : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse_pipe_entrance()
            : AreaTriggerScript("at_siegecrafter_blackfuse_pipe_entrance")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                if (CanMoveToInstance(player))
                {
                    MoveToEntrance(player);
                }
                else
                {
                    RejectToEntrance(player);
                }
            }

            return true;
        }

    private:

        bool CanMoveToInstance(Player* player) const
        {
            // TODO: maybe need to check 'in progress'
            return true;
        }

        void MoveToEntrance(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_ENTRANCE);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_TO_ENTRANCE, true);
        }

        void RejectToEntrance(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_ENTRANCE_REJECTION);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_JUMP, true);
        }
};

// 9256 9255 9254 9257 9253 9371 -- 'exit' triggers (from left to right)
class at_siegecrafter_blackfuse_pipe_exit : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse_pipe_exit()
            : AreaTriggerScript("at_siegecrafter_blackfuse_pipe_exit")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                if (CanMoveToExit(player))
                {
                    MoveToExit(player);
                }
                else
                {
                    RejectToExit(player);
                }
            }

            return true;
        }

    private:

        bool CanMoveToExit(Player* player) const
        {
            if (InstanceScript* pInstance = player->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_SIEGECRAFTER_BLACKFUSE) == IN_PROGRESS)
                    return false;
            }

            return true;
        }

        void MoveToExit(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_EXIT);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_TO_EXIT, true);
        }

        void RejectToExit(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_REJECTION);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_JUMP, true);
        }
};

// 9240 9241 9189  9236 9190 -- 'transition' triggers (from left to right)
class at_siegecrafter_blackfuse_pipe_transition : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse_pipe_transition()
            : AreaTriggerScript("at_siegecrafter_blackfuse_pipe_transition")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                if (CanMoveToTransition(player))
                {
                    MoveToTransition(player);
                }
                else
                {
                    RejectToTransition(player);
                }
            }

            return true;
        }

    private:

        bool CanMoveToTransition(Player* player) const
        {
            if (InstanceScript* pInstance = player->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_SIEGECRAFTER_BLACKFUSE) != IN_PROGRESS)
                    return false;
            }

            if (player->HasAura(SPELL_PATTERN_RECOGNITION))
                return false;

            return true;
        }

        void MoveToTransition(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_TRANSITION);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_TRANSITION, true);
        }

        void RejectToTransition(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_REJECTION);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_JUMP, true);
        }
};

// 9238 9239 9216 9194 -- 'ejection' triggers (from left to right)
class at_siegecrafter_blackfuse_pipe_ejection : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse_pipe_ejection()
            : AreaTriggerScript("at_siegecrafter_blackfuse_pipe_ejection")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                MoveToEjection(player);
            }

            return true;
        }

    private:

        void MoveToEjection(Player* player)
        {
            if (!CanTriggerPipeTransfer(player))
                return;

            player->GetSceneMgr().PlayScene(SCENE_SIEGECRAFTER_PIPE_EJECTION);
            player->CastSpell(player, SPELL_PIPE_TRANSFER_EJECTION, true);
        }
};

// 9264 -- Platform trigger
class at_siegecrafter_blackfuse_platform : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse_platform()
            : AreaTriggerScript("at_siegecrafter_blackfuse_platform")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                AppyOnPlatform(player, true);
            }
            else
            {
                AppyOnPlatform(player, false);
            }

            return true;
        }

    private:

        void AppyOnPlatform(Player* player, bool apply)
        {
            const float force = 3.f;

            if (apply)
            {
                player->AddAura(SPELL_ON_PLATFORM, player);
            }
            else
            {
                player->RemoveAura(SPELL_ON_PLATFORM);
            }
        }
};

// 9179 -- Conveyor trigger
class at_siegecrafter_blackfuse_conveyor : public AreaTriggerScript
{
    public:
        at_siegecrafter_blackfuse_conveyor()
            : AreaTriggerScript("at_siegecrafter_blackfuse_conveyor") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            AppyOnConveyor(player, p_Enter);
            return true;
        }

    private:

        void AppyOnConveyor(Player* player, bool apply)
        {
            const float force = 7.f;

            if (apply)
            {
                player->AddAura(SPELL_ON_CONVEYOR, player);

                /*if (player->GetMovementForces().IsActive())
                    player->GetForcedMovement().Stop();

                player->GetForcedMovement().StartPullingTo(endOfFirstConveyorPos, force);*/
            }
            else
            {
                //player->GetForcedMovement().Stop();

                /// If the player jumps while is on conveyor he will be out of areatrigger and the aura will be removed here. It's wrong, because he is still on conveyor.
                /// We cannot modify the height of the areatrigger, so just delay removing. If the player jumps he will receive the aura again on landing.
                if (Aura* l_Aur = player->GetAura(Spells::SPELL_ON_CONVEYOR))
                {
                    l_Aur->SetMaxDuration(4000);
                    l_Aur->SetDuration(4000);
                }
            }
        }
};

class achievement_lasers_and_magnets_and_drills_laser : public AchievementCriteriaScript
{
    public:
        achievement_lasers_and_magnets_and_drills_laser() : AchievementCriteriaScript("achievement_lasers_and_magnets_and_drills_laser") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Creature* pBlackfuse = GetBlackfuse(source))
            {
                if (pBlackfuse->AI()->GetData(DATA_LASERS_KILLED) == 0)
                    return true;
            }
            return false;
        }
};

class achievement_lasers_and_magnets_and_drills_mines : public AchievementCriteriaScript
{
    public:
        achievement_lasers_and_magnets_and_drills_mines() : AchievementCriteriaScript("achievement_lasers_and_magnets_and_drills_mines") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Creature* pBlackfuse = GetBlackfuse(source))
            {
                if (pBlackfuse->AI()->GetData(DATA_MINES_KILLED) == 0)
                    return true;
            }
            return false;
        }
};

class achievement_lasers_and_magnets_and_drills_magnet : public AchievementCriteriaScript
{
    public:
        achievement_lasers_and_magnets_and_drills_magnet() : AchievementCriteriaScript("achievement_lasers_and_magnets_and_drills_magnet") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Creature* pBlackfuse = GetBlackfuse(source))
            {
                if (pBlackfuse->AI()->GetData(DATA_MAGNETS_KILLED) == 0)
                    return true;
            }
            return false;
        }
};

class achievement_lasers_and_magnets_and_drills_shockwave : public AchievementCriteriaScript
{
    public:
        achievement_lasers_and_magnets_and_drills_shockwave() : AchievementCriteriaScript("achievement_lasers_and_magnets_and_drills_shockwave") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Creature* pBlackfuse = GetBlackfuse(source))
            {
                if (pBlackfuse->AI()->GetData(DATA_SHOCKWAVE_KILLED) == 0)
                    return true;
            }
            return false;
        }
};

void AddSC_boss_siegecrafter_blackfuse()
{
    new boss_siegecrafter_blackfuse();                          // 71504
    new npc_siegecrafter_blackfuse_goblin();                    // 72694
    new npc_siegecrafter_blackfuse_sawblade();                  // 71532
    new npc_siegecrafter_blackfuse_automated_shredder();        // 71591
    new npc_siegecrafter_blackfuse_siege_engineer_helper();     // 71520
    new npc_siegecrafter_blackfuse_siege_deactivated_base();    // 71614
    new npc_siegecrafter_blackfuse_siege_deactivated_weapon();  // 71606
    new npc_siegecrafter_blackfuse_siege_activated_base();      // 71637
    new npc_siegecrafter_blackfuse_siege_activated_weapon_base();   // 71639 72027 71795 72015
    new npc_siegecrafter_blackfuse_laser_turret();              // 71752
    new npc_siegecrafter_blackfuse_laser_target();              // 71740
    new npc_siegecrafter_blackfuse_crawler_mine();              // 71788
    new npc_siegecrafter_blackfuse_electromagnet();             // 71696
    new npc_siegecrafter_blackfuse_shockwave_missile_turret();  // 71638
    new npc_siegecrafter_blackfuse_shockwave_missile();         // 72052
    new npc_siegecrafter_blackfuse_laser_array();               // 71910
    new npc_siegecrafter_blackfuse_steam_vent();                // 72345

    new spell_siegecrafter_blackfuse_electromagnetic_barrier(); // 145154
    new spell_siegecrafter_blackfuse_laser_turret_targetting(); // 143833
    new spell_siegecrafter_blackfuse_laser_ground_effect();     // 143829
    new spell_siegecrafter_blackfuse_crawler_mine_targetting(); // 144009
    new spell_siegecrafter_blackfuse_magnetic_pulse();          // 143357
    new spell_siegecrafter_blackfuse_magnetic_pulse_pull();     // 147458
    new spell_siegecrafter_blackfuse_magnetic_pulse_push();     // 147380
    new spell_siegecrafter_blackfuse_shockwave_missile_dmg();   // 144658 144660 144661 144662 144663 144664
    new spell_siegecrafter_blackfuse_launch_sawblade_aoe();     // 143291
    new spell_siegecrafter_blackfuse_launch_sawblade();         // 143265
    new spell_siegecrafter_blackfuse_death_from_above();        // 144208
    new spell_siegecrafter_blackfuse_pipe_transfer_jump();      // 143798

    RegisterAreaTriggerAI(spell_area_siegecrafter_blackfuse_laser_ground_effect);    // 143830
    RegisterAreaTriggerAI(spell_area_siegecrafter_blackfuse_magnetic_crush);         // 143487
    RegisterAreaTriggerAI(spell_area_siegecrafter_blackfuse_magnetic_crush_pull);    // 147369
    RegisterAreaTriggerAI(spell_area_siegecrafter_blackfuse_magnetic_crush_push);    // 147370
    RegisterAreaTriggerAI(spell_area_siegecrafter_blackfuse_conveyor_death_beam);    // 144282

    new at_siegecrafter_blackfuse_pipe_entrance();              // 9250 9251 9252
    new at_siegecrafter_blackfuse_pipe_exit();                  // 9256 9255 9254 9257 9253 9371
    new at_siegecrafter_blackfuse_pipe_transition();            // 9240 9241 9189 9236 9190
    new at_siegecrafter_blackfuse_pipe_ejection();              // 9238 9239 9216 9194
    new at_siegecrafter_blackfuse_platform();                   // 9264
    new at_siegecrafter_blackfuse_conveyor();                   // 9179

    new achievement_lasers_and_magnets_and_drills_laser();      // 23772
    new achievement_lasers_and_magnets_and_drills_mines();      // 23775
    new achievement_lasers_and_magnets_and_drills_magnet();     // 23773
    new achievement_lasers_and_magnets_and_drills_shockwave();  // 23774
}
