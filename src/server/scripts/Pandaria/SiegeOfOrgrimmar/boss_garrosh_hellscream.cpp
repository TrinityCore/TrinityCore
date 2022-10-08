#include "siege_of_orgrimmar.hpp"
#include <set>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SceneHelper.h"

// todo readd update spellscripts

enum ScriptedTexts
{
    SAY_GARROSH_DEATH           = 1,
    SAY_GARROSH_DEATH_2         = 2,
    SAY_GARROSH_INTERMISSION    = 3,
    SAY_BOMBARDMENT             = 4,
    SAY_MANIFEST_RAGE           = 5,
    SAY_GARROSH_PHASE_2         = 6,
    SAY_GARROSH_YSHAARJ         = 7,
    SAY_GARROSH_PHASE_3         = 8,
    SAY_GARROSH_PHASE_4_1       = 9,
    SAY_GARROSH_PHASE_4_2       = 10,
    SAY_GARROSH_INTRO_1         = 11,
    SAY_GARROSH_INTRO_2         = 12,
    SAY_GARROSH_INTRO_3         = 13,
    SAY_GARROSH_INTRO_4         = 14,
    SAY_GARROSH_INTRO_5         = 15,
    SAY_GARROSH_AGGRO           = 16,
    SAY_GARROSH_KILL            = 17,
    SAY_GARROSH_WIPE            = 18,
    SAY_GARROSH_IRON_STAR       = 19,
    SAY_GARROSH_BERSERK         = 20,
    SAY_GARROSH_FARSEER         = 22,
    SAY_GARROSH_WARSONG         = 23,
    SAY_GARROSH_WHIRLING        = 24,
    SAY_GARROSH_WHIRLING_2      = 25,

    SAY_THRALL_INTRO_1          = 0,
    SAY_THRALL_INTRO_2          = 1,
    SAY_THRALL_INTRO_3          = 2,

    SAY_HEARTH_OF_YSHAARJ       = 0,
};

enum Spells
{
    // Thrall
    // Intro
    SPELL_CALL_OF_THE_ELEMENTS                  = 147815,
    SPELL_ASTRAL_RECALL                         = 147811, // 1120.73, -5644.33, -289.902
    SPELL_EXHAUSTED                             = 147861,
    SPELL_ATTACK_GARROSH                        = 147892,

    // Garrosh Intro
    SPELL_DEFEND_AGAIST_THRALL                  = 147899,
    SPELL_ATTACK_THRALL                         = 147831, // has attribute SPELL_ATTR3_ONLY_TARGET_PLAYERS, remove it

    // Finale
    SPELL_GARROSH_FINALE_HORDE_MOVIE_1          = 147301,
    SPELL_GARROSH_FINALE_HORDE_MOVIE_2          = 149978,
    SPELL_GARROSH_FINALE_HORDE_FADE             = 147314,
    SPELL_GARROSH_FINALE_HORDE_REMOVE           = 147329,
    SPELL_GARROSH_FINALE_ALLIANCE_MOVIE_1       = 147302,
    SPELL_GARROSH_FINALE_ALLIANCE_MOVIE_2       = 149979,
    SPELL_GARROSH_FINALE_ALLIANCE_FADE          = 147332,
    SPELL_GARROSH_FINALE_ALLIANCE_REMOVE        = 147331,

    // Garrosh general spells
    SPELL_ZERO_ENERGY                           = 72242,
    SPELL_ACHIEVEMENT_CHECK                     = 148305, // in sniffs, casted by adds ?
    SPELL_BERSERK                               = 26662,

    // First phase
    SPELL_HELLSCREAMS_WARSONG                   = 144821,
    SPELL_DESECRATE_AOE                         = 144745, // targetting
    SPELL_DESECRATE_MISSILE                     = 144748,
    SPELL_DESECRATE_DMG                         = 144758,
    SPELL_DESECRATED_WEAPON_VISUAL              = 144760, // visual area
    SPELL_DESECRATED_WEAPON_2                   = 145880, // visual weapon
    SPELL_DESECRATED_DMG                        = 144762,
    SPELL_SUMMON_ADDS                           = 144489, // periodic 5000 msecs, in sniffs

    // Second Phase Transition
    SPELL_THROW_AXE_AT_HEART                    = 145235,
    SPELL_TRANSITION_VISUAL_AURA                = 146756, // casted by Garrosh before second phase
    SPELL_PHASE_TWO_TRANSFORM                   = 144842, // triggered by 144852 (transition visual)

    // Second Phase: Realm of Y'Shaarj
    SPELL_ENTER_REALM_OF_YSHAARJ_SCRIPT_1       = 144866,
    SPELL_ENTER_REALM_OF_YSHAARJ_SCRIPT_2       = 144878,
    SPELL_ENTER_REALM_OF_YSHAARJ_JUMP           = 144870, // triggered by 144867, casted by Garrosh
    SPELL_ENTER_REALM_OF_YSHAARJ_JUMP_2         = 144868, // triggered by 144867, casted by players
    SPELL_TELEPORT_RED_CRANE_AOE                = 144880, // triggers 144881
    SPELL_TELEPORT_RED_CRANE                    = 144881, // teleports players to Red Crane Temple
    SPELL_TELEPORT_JADE_SERPENT_AOE             = 144883, // triggers 144884
    SPELL_TELEPORT_JADE_SERPENT                 = 144884, // teleports players to Jade Serpent Temple
    SPELL_TELEPORT_TERRACE_AOE                  = 144885, // triggers 144886
    SPELL_TELEPORT_TERRACE                      = 144886, // teleports players to Terrace
    SPELL_REALM_OF_YSHAARJ                      = 144954, // from the boss to players
    SPELL_REALM_OF_YSHAARJ_SELF                 = 144958, // on self
    SPELL_REALM_OF_YSHAARJ_REMOVE               = 145647, // removes 144954

    SPELL_YSHAARJ_PROTECTION                    = 144945,
    SPELL_ABSORB_ENERGY                         = 144946,
    SPELL_GROWING_POWER                         = 144947,
    SPELL_GARROSH_ENERGY                        = 145801, // casted on players

    SPELL_JUMP_TO_GROUND                        = 144956,

    SPELL_BREAK_PLAYER_TARGETTING               = 140562,

    // Second phase
    SPELL_ANNIHILATION_FORCE                    = 144970,
    SPELL_ANNIHILATION_SUMMON                   = 148203,
    SPELL_ANNIHILATION_DMG                      = 144969,
    SPELL_WHIRLING_CORRUPTION                   = 144985,
    SPELL_WHIRLING_CORRUPTION_DMG               = 144989,
    SPELL_WHIRLING_CORRUPTION_SCRIPT            = 145036, // ?
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_AURA    = 145833,
    SPELL_WHIRLING_CORRUPTION_ADDITIONAL_MISSILE    = 144994,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION         = 145037,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_MISSILE = 145023,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_DMG     = 145033,
    SPELL_TOUCH_OF_YSHAARJ_AOE                  = 145065, // hit 2 players
    SPELL_TOUCH_OF_YSHAARJ_SINGLE               = 145071, // hit 1 player
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT               = 145096, // ?
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT_2             = 145163, // ?
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT_PLAYER        = 145599, // casted by players on other players
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AURA       = 145832,
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE        = 145171, // hit 2 players
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE     = 145175, // hit 1 player
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_IMMUNE     = 145710,
    SPELL_EMPOWERED_DESECRATE_AURA              = 145829,
    SPELL_DESECRATED_DMG_2                      = 144817,
    SPELL_POWER_OF_THE_OLD_GOD                  = 144819, // Triggers periodically 144820 which heals the empower desecrated weapon
    SPELL_POWER_OF_THE_OLD_GOD_HEAL             = 144820,
    SPELL_EMPOWERED_DESECRATE_MISSILE           = 144749,
    SPELL_EMPOWERED_DESECRATE_DMG               = 144816,
    SPELL_EMPOWERED_DESECRATED_WEAPON_VISUAL    = 144818, // visual area
    SPELL_GRIPPING_DESPAIR_PERIODIC_DMG         = 145183,
    SPELL_GRIPPING_DESPAIR_SCRIPT               = 145207, // ?
    SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA       = 145831,
    SPELL_EMPOWERED_GRIPPING_DESPAIR_PERIODIC_DMG = 145195,
    SPELL_EMPOWERED_GRIPPING_DESPAIR_DMG        = 149252,
    SPELL_EXPLOSIVE_DESPAIR_DEBUFF              = 145213,
    SPELL_EXPLOSIVE_DESPAIR_DMG                 = 145199,
    SPELL_WEAK_MINDED_AOE                       = 145331, // Lasts 67 secs. It is used on teleportation to realm of yshaarj on players afftected by touch of yshaarj.
    SPELL_WEAK_MINDED                           = 148440, // Lasts 15 secs, triggered by 146986 (teleport spell).

    // Third phase
    SPELL_TRANSITION_VISUAL_AURA_2              = 146845, // casted by Garrosh before third phase
    SPELL_PHASE_THREE_TRANSFORM                 = 145246, // triggered by 145222 (transition visual)
    SPELL_PHASE_THREE_TRANSFORM_2               = 145598, // Scale +50%, applies all empowered weapon buffs

    // Fourth Phase
    SPELL_PHASE_THREE_DE_TRANSFORM_PERIODIC     = 146966, // triggers 146967 in 6 secs, heroic ?
    SPELL_PHASE_THREE_DE_TRANSFORM              = 146967, // removes 145598, heroic ?
    SPELL_PHASE_THREE_DE_TRANSFORM_PERIODIC_2   = 147608, // triggers 146972, lasts 23 secs
    SPELL_PHASE_THREE_DE_TRANSFORM_MISSILE      = 146972,
    SPELL_PHASE_FOUR_TRANSFORM                  = 146987,
    SPELL_ENTER_REALM_OF_GARROSH                = 146984, // heroic
    SPELL_ENTER_REALM_OF_GARROSH_JUMP           = 146985,  // heroic
    SPELL_REALM_OF_GARROSH_TELEPORT             = 149140,

    // Fourth Phase
    SPELL_CALL_GUNSHIP                          = 147187,
    SPELL_CALL_BOMBARDMENT                      = 147120,
    SPELL_BOMBARDMENT_FORCE                     = 147131, // triggered by 147120
    SPELL_BOMBARDMENT_AOE                       = 147132, // triggered by 147131
    SPELL_BOMBARDMENT_MISSILE                   = 147133,
    SPELL_BOMBARDMENT_DMG                       = 147135,
    SPELL_NAPALM                                = 147136,
    SPELL_CLUMP_CHECK_FORCE                     = 147126, // triggered by 147120 every 500 msec
    SPELL_CLUMP_CHECK_SUMMON                    = 147130, // triggered by 147126
    SPELL_FIRE_IRON_STAR                        = 147053, // casted by Clump (73278)
    SPELL_FIRE_UNSTABLE_IRON_STAR_MISSILE       = 147047,
    SPELL_IRON_STAR_CRATER                      = 147048,
    SPELL_FIXATE                                = 147665,
    SPELL_UNSTABLE_IRON_STAR_AURA               = 147148,
    SPELL_UNSTABLE_IRON_STAR_DMG                = 147173, // hits players
    SPELL_UNSTABLE_IRON_STAR_STUN               = 147177, // hits Garrosh
    SPELL_UNSTABLE_IRON_STAR_DMG_2              = 147179, // ?
    SPELL_MALICE                                = 147209,
    SPELL_MALICE_AOE                            = 147229, // hits ally
    SPELL_MALICIOUS_BLAST                       = 147235,
    SPELL_MALICIOUS_ENERGY                      = 147236,
    SPELL_MALICIOUS_ENERGY_EXPLOSION            = 147733,
    SPELL_MANIFEST_RAGE                         = 147011,
    SPELL_MANIFESTATION_OF_RAGE_MISSILE         = 147035,
    SPELL_MANIFESTATION_OF_RAGE_SUMMON          = 147013,

    // Kor'kron Warbringer
    SPELL_HAMSTRING                             = 144582,
    SPELL_BLOOD_FRENZY                          = 147300,

    // Farseer Wolf Rider
    SPELL_ANCESTRAL_CHAIN_HEAL                  = 144583,
    SPELL_CHAIN_LIGHTNING                       = 144584,
    SPELL_ANCESTRAL_FURY                        = 144585,
    SPELL_FURY                                  = 144588,

    // Siege Engineer
    SPELL_POWER_IRON_STAR                       = 144616,

    // Iron Star
    SPELL_IRON_STAR_IMPACT                      = 144645,
    SPELL_IRON_STAR_IMPACT_2                    = 149468,
    SPELL_IRON_STAR_IMPACT_DMG_1                = 144650, // casted on players
    SPELL_IRON_STAR_IMPACT_DMG_2                = 144653, // casted on creatures
    SPELL_IRON_STAR_IMPACT_DUMMY                = 148299, // ?
    SPELL_EXPLODING_IRON_STAR                   = 144798,

    // Heart of Y'shaarj
    SPELL_TRANSITION_VISUAL                     = 144852, // for 2 phase
    SPELL_ENTER_THE_REALM_OF_YSHAARJ            = 144867,
    SPELL_TRANSITION_VISUAL_2                   = 145222, // for 3 phase
    SPELL_HEARTBEAT_SOUND                       = 148574,
    SPELL_HEARTBEAT_SOUND_2                     = 148591,

    // Embodied Despair
    SPELL_CONSUMED_HOPE                         = 149032,
    SPELL_HOPE_MISSILE                          = 149002,
    SPELL_HOPE_AREATRIGGER                      = 149003,
    SPELL_HOPE_AURA                             = 149004,
    SPELL_ULTIMATE_DESPAIR                      = 147341,
    SPELL_ULTIMATE_DESPAIR_DMG                  = 147342,

    // Embodied Doubt
    SPELL_CONSUMED_FAITH                        = 149033,
    SPELL_FAITH_MISSILE                         = 148991,
    SPELL_FAITH_AREATRIGGER                     = 148992,
    SPELL_FAITH_AURA                            = 148994,
    SPELL_EMBODIED_DOUBT                        = 149347,

    // Embodied Fear
    SPELL_REDUCE_CRITICAL_STRIKE_CHANCE         = 64481, // from sniffs
    SPELL_CONSUMED_COURAGE                      = 149011,
    SPELL_COURAGE_MISSILE                       = 148980,
    SPELL_COURAGE_AREATRIGGER                   = 148982,
    SPELL_COURAGE_AURA                          = 148983,
    SPELL_CRUSHING_FEAR_PERIODIC                = 147327,
    SPELL_CRUSHING_FEAR_AOE                     = 147325, // triggered by 147327 every 3 secs
    SPELL_CRUSHING_FEAR_MISSILE                 = 147326,
    SPELL_CRUSHING_FEAR_DMG                     = 147324,

    // Minion of Y'Shaarj
    SPELL_EMPOWERED                             = 145050,
};

enum Adds
{
    NPC_HEART_OF_YSHAARJ    = 72215, // at the center of the room
    NPC_HEART_OF_YSHAARJ_2  = 72228, // at the red crane, jade serpent and terrace

    NPC_KORKRON_WARBRINGER  = 71979,
    NPC_FARSEER_WOLF_RIDER  = 71983,
    NPC_DESECRATED_WEAPON   = 72154,
    NPC_SIEGE_ENGINEER      = 71984,
    NPC_KORKRON_IRON_STAR   = 71985,
    NPC_EMBODIED_DESPAIR    = 72238,
    NPC_EMBODIED_DOUBT      = 72236,
    NPC_EMBODIED_FEAR       = 72237,
    NPC_MINION_OF_YSHAARJ   = 72272,
    NPC_EMPOWERED_DESECRATED_WEAPON = 72198,
    NPC_CLUMP               = 73278,
    NPC_IRON_STAR           = 73059,
    NPC_MANIFESTATION_OF_RAGE   = 73253,

    NPC_GUNSHIP_SMALL_CANNON    = 73262, // I think it's correct entry
    NPC_GUNSHIP_MAIN_CANNON     = 73258, // I think it's correct entry
};

enum Events
{
    // Garrosh Hellscream
    EVENT_HELLSCREAMS_WARSONG   = 1,
    EVENT_DESECRATE,
    EVENT_KORKRON_WARBRINGERS,
    EVENT_FARSEER_WOLF_RIDER,
    EVENT_SIEGE_ENGINEER,
    EVENT_BERSERK,

    EVENT_FIRST_PHASE_ENDING,
    EVENT_SECOND_PHASE_PREPARE,
    EVENT_SECOND_PHASE_START,
    EVENT_SECOND_PHASE_ENDING,
    EVENT_THIRD_PHASE_PREPARE,
    EVENT_THIRD_PHASE_START,
    EVENT_THIRD_PHASE_ENDING,
    EVENT_FOURTH_PHASE_PREPARE,
    EVENT_FOURTH_PHASE_START,

    EVENT_REALM_OF_YSHAARJ, // Garrosh triggers realm of Y'Shaarj
    EVENT_REALM_OF_YSHAARJ_SPAWN,
    EVENT_REAM_OF_YSHAARJ_TALK,
    EVENT_REALM_OF_YSHAARJ_ACTIVATE_GARROSH,
    EVENT_REALM_OF_YSHAARJ_TELEPORT,
    EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT,
    EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT_END,
    EVENT_REALM_OF_GARROSH_TELEPORT_PREPARE,
    EVENT_REALM_OF_GARROSH_TELEPORT,

    EVENT_ANNIHILATION,

    EVENT_WHIRLING_CORRUPTION,
    EVENT_TOUCH_OF_YSHAARJ,
    EVENT_GRIPPING_DESPAIR,

    EVENT_BOMBARDMENT,
    EVENT_MALICE,

    // Heart of Y'Shaarj
    EVENT_TELEPORT,

    // Kor'kron Warbringer
    EVENT_HAMSTRING,
    EVENT_RESUME_FIGHT,

    // Farseer Wolf Rider
    EVENT_ANCESTRAL_CHAIN_HEAL,
    EVENT_CHAIN_LIGHTNING,

    // Embodied Doubt
    EVENT_EMBODIED_DOUBT,
};

enum Timers
{
    // Garrosh Hellscream
    TIMER_BERSERK                       = 18 * MINUTE * IN_MILLISECONDS,
    TIMER_HELLSCREAMS_WARSONG_FIRST     = 22 * IN_MILLISECONDS,
    TIMER_HELLSCREAMS_WARSONG           = 43 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_1             = 11 * IN_MILLISECONDS,
    TIMER_DESECRATE_1                   = 41 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_2             = 10 * IN_MILLISECONDS,
    TIMER_DESECRATE_2                   = 35 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_3             = 21 * IN_MILLISECONDS,
    TIMER_DESECRATE_3                   = 25 * IN_MILLISECONDS,
    TIMER_KORKRON_WARBRINGERS_FIRST     = 2 * IN_MILLISECONDS,
    TIMER_KORKRON_WARBRINGERS           = 40 * IN_MILLISECONDS,
    TIMER_FARSEER_WOLF_RIDER_FIRST      = 30 * IN_MILLISECONDS,
    TIMER_FARSEER_WOLF_RIDER            = 50 * IN_MILLISECONDS,
    TIMER_SIEGE_ENGINEER_FIRST          = 20 * IN_MILLISECONDS,
    TIMER_SIEGE_ENGINEER                = 42 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ_FIRST        = 16 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ              = 146 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ_TELEPORT_OUT = 61 * IN_MILLISECONDS,
    TIMER_ANNIHILATION                  = 3500,
    TIMER_WHIRLING_CORRUPTION_FIRST     = 30 * IN_MILLISECONDS,
    TIMER_WHIRLING_CORRUPTION           = 50 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ_FIRST_1      = 15 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ_FIRST_2      = 30 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ              = 45 * IN_MILLISECONDS,
    TIMER_BOMBARDMENT_FIRST             = 50 * IN_MILLISECONDS, // 70 secs or 50 secs after cinematic (aggro)
    TIMER_BOMBARDMENT                   = 55 * IN_MILLISECONDS,
    TIMER_MALICE_FIRST                  = 11 * IN_MILLISECONDS, // 29.5 secs or 11 secs after cinematic (aggro)
    TIMER_MALICE                        = 29500,

    // Kor'kron Warbringer
    TIMER_HAMSTRING_FIRST_MIN           = 10 * IN_MILLISECONDS,
    TIMER_HAMSTRING_FIRST_MAX           = 25 * IN_MILLISECONDS,
    TIMER_HAMSTRING_MIN                 = 15 * IN_MILLISECONDS,
    TIMER_HAMSTRING_MAX                 = 35 * IN_MILLISECONDS,
    TIMER_RESUME_FIGHT                  = 5 * IN_MILLISECONDS,

    // Farseer Wolf Rider
    TIMER_ANCESTRAL_CHAIN_HEAL_FIRST    = 10 * IN_MILLISECONDS,
    TIMER_ANCESTRAL_CHAIN_HEAL          = 25 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING_FIRST         = 7 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING               = 2500,

    // Embodied Doubt
    TIMER_EMBODIED_DOUBT_MIN            = 5 * IN_MILLISECONDS,
    TIMER_EMBODIED_DOUBT_MAX            = 7 * IN_MILLISECONDS,

    TIMER_IRON_STAR_FIXATE_FIRST        = 2 * IN_MILLISECONDS,
    TIMER_IRON_STAR_FIXATE              = 12 * IN_MILLISECONDS,
};

enum Actions
{
    // intro actions
    ACTION_JUMP_INTO_ROOM   = 1,
    ACTION_MOVE_TO_FIGHT,
    ACTION_FIGHT,
    ACTION_HIT_BY_GARROSH,

    // First phase
    ACTION_POWER_IRON_STAR,

    // Second phase
    ACTION_SECOND_PHASE_STARTING_FIRST_TIME,   // mark when second phase is starting
    ACTION_SECOND_PHASE_STARTING,
    ACTION_THIRD_PHASE_STARTING,
    ACTION_FOURTH_PHASE_STARTING,

    ACTION_REALM_OF_YSHAARJ_ACTIVATE,
    ACTION_REALM_OF_YSHAARJ_ENDING,    // mark when realm of y'shaarj is ending

    ACTION_PAUSE_FIGHT,     // mark to pause orc adds
    ACTION_RESUME_FIGHT,    // mark to resume orc adds

    ACTION_CLUMP_CHECK,
};

enum eDatas
{
    DATA_IRON_STAR_CREATURES    = 1, // how many creatures was killed by Iron Star
    DATA_TOUCH_SUCCESSFUL,
};

enum Phases : int
{
    PHASE_1 = 0,            // Phase 1: Stage One: The True Horde
    PHASE_1_INTERMISSION,   // Phase 1: The time between Phase 1 and Phase 2 (animation and scripts)
    PHASE_2,                // Phase 2: Stage Two: Corruption of Y'shaarj
    PHASE_2_YSHAARJ,        // Phase 2: Intermission: Realm of Y'Shaarj
    PHASE_2_INTERMISSION,   // Phase 2: The time between Phase 2 and Phase 3 (animation and scripts)
    PHASE_3,                // Phase 3: Stage Three: MY WORLD
    PHASE_3_INTERMISSION,   // Phase 3: The time between Phase 3 and Phase 4 (animation and scripts)
    PHASE_4,                // Phase 4: Stage Four: Mythic Only Stormwind loc
};

enum Points : int
{
    POINT_ORC   = 1,    // The point that warbringers reach on entering combat
    POINT_ORC_CENTER,
    POINT_ENGINEER,
    POINT_IRON_STAR,    // The point that iron stars reach on moving through the room
};

enum IntermissionIndexes : int
{
    INTERMISSION_NONE           = -1,   // Intermission initial state
    INTERMISSION_RED_CRANE      = 0,    // Intermission phase at the red crane's temple
    INTERMISSION_JADE_SERPENT   = 1,    // Intermission phase at the jade serpent's temple
    INTERMISSION_TERRACE        = 2,    // Intermission phase at the terrace of the endless spring
    INTERMISSION_COUNT          = 3,    // Count of intermission phases
};

const Position centerOfRoomPos = { 1073.27f, -5639.64f, -317.37f, 3.01f };
const Position garroshFightPos = { 1028.82f, -5634.50f, -317.67f, 6.16f };
const Position thrallFightPos = { 1034.93f, -5635.62f, -317.67f, 3.03f };
const Position thrallKnockBackPos = { 1098.70f, -5646.42f, -317.67f, 2.94f };
const Position heartOfYshaarjPos = { 1073.01f, -5639.33f, -266.1497f, 0.f };
const Position heartOfYshaarjIntermissionPos[INTERMISSION_COUNT] =
{
    { 1056.184f, -5818.878f, -357.39f, 6.024623f },     // Red Crane
    { 1104.589f, -5328.837f, -339.1655f, 5.295208f },   // Jade Serpent
    { 800.0191f, -5602.043f, -383.0974f, 5.295208f }    // Terrace
};
#define KORKRON_WARBRINGERS_COUNT 6
const Position korkronWarbringersPos[2][KORKRON_WARBRINGERS_COUNT]
{
    {
        { 997.1441f, -5554.838f, -309.3391f, 5.471175f },
        { 997.2309f, -5561.731f, -309.8141f, 6.111355f },
        { 997.7778f, -5567.394f, -310.4835f, 0.5425754f },
        { 983.4496f, -5692.309f, -309.7805f, 6.035443f },
        { 982.0851f, -5699.49f, -309.4232f, 6.231002f },
        { 980.5538f, -5706.045f, -308.9297f, 5.76421f }
    },
    {
        { 1042.230713f, -5557.982422f, -317.687988f, 6.132235f },
        { 1040.899292f, -5566.559570f, -317.687988f, 6.129180f },
        { 1039.511475f, -5575.500000f, -317.687988f, 6.129180f },
        { 1026.006104f, -5696.662109f, -317.688568f, 6.217761f },
        { 1025.486694f, -5704.590332f, -317.688568f, 6.217761f },
        { 1024.931763f, -5713.059570f, -317.688568f, 6.217761f }
    }
};

G3D::Vector3 const FarseerWolfRidersStartPos[2] =
{
    { 992.38620f, -5560.95700f, -307.51330f },
    { 976.20450f, -5698.73200f, -306.50940f },
};

uint32 const FarseerWolfRidersWPId[2] =
{
    719830,
    719831,
};

Position const SiegeEngineerLeft[2] =
{
    { 1085.70400f, -5515.16800f, -304.40250f, 0.0f }, ///< Start
    { 1083.83300f, -5537.22100f, -304.43910f, 0.0f }, ///< End
};

Position const SiegeEngineerRight[2] =
{
    { 1059.86700f, -5764.31400f, -301.94540f, 0.0f }, ///< Start
    { 1062.20000f, -5742.86800f, -304.46870f, 0.0f }, ///< End
};

#define KORKRON_IRONSTARS_COUNT 2
const Position korkronIronStarsPos[2][KORKRON_IRONSTARS_COUNT] =
{
    {
        { 1087.052f, -5758.288f, -317.5687f, 1.459921f },
        { 1059.924f, -5520.203f, -317.5687f, 4.647993f }
    },
    {
        { 1037.21f, -5726.54f, -317.46f, 4.62f },
        { 1108.39f, -5552.89f, -317.46f, 1.56f }
    }
};
#define EXPLODING_IRON_STAR_MIN_DAMAGE 40000
#define EXPLODING_IRON_STAR_MIN_DAMAGE_RANGE 300.f
const Position playerTeleportPos[INTERMISSION_COUNT] =
{
    { 1055.22f, -5844.20f, -318.85f, 4.61f },   // Red Crane
    { 1092.57f, -5453.62f, -354.89f, 1.44f },   // Jade Serpent
    { 1084.50f, -5631.19f, -423.44f, 3.0f }     // Terrace
};
const Position garroshTeleportPos[INTERMISSION_COUNT] =
{
    { 1056.40f, -5831.44f, -368.66f, 1.43f },   // Red Crane
    { 1104.03f, -5343.33f, -349.77f, 1.45f },   // Jade Serpent
    { 813.93f, -5603.03f, -397.69f, 2.92f }     // Terrace
};
const Position garroshTeleportHeroicPos = { -8497.64f, 1086.49f, 17.95f, 1.52f };
const Position playerTeleportHeroicPos = { -8490.92f, 1143.54f, 18.05f, 4.66f };
#define EMBODIED_DOUBT_COUNT 15
const Position embodiedDoubtPos[EMBODIED_DOUBT_COUNT] =
{
    // Entrance - left pack
    { 1075.60f, -5435.83f, -355.10f, 5.904884f },
    { 1072.99f, -5432.08f, -355.10f, 6.175061f },
    { 1077.09f, -5430.16f, -355.10f, 5.581300f },
    // Entrance - right pack
    { 1112.34f, -5433.23f, -355.10f, 3.666526f },
    { 1116.57f, -5435.78f, -355.10f, 3.350792f },
    { 1112.84f, -5439.66f, -355.10f, 3.350792f },
    // Middle pack
    { 1093.15f, -5406.77f, -349.80f, 4.616044f },
    { 1098.19f, -5402.27f, -349.80f, 4.601921f },
    { 1101.53f, -5407.40f, -349.80f, 4.596415f },
    // Final room - left pack
    { 1080.00f, -5362.76f, -350.50f, 0.129081f },
    { 1075.04f, -5357.84f, -350.50f, 6.196280f },
    { 1080.82f, -5353.70f, -350.50f, 6.121659f },
    // Final room - right pack
    { 1125.23f, -5358.33f, -350.30f, 3.360995f },
    { 1129.58f, -5363.71f, -350.50f, 3.035054f },
    { 1123.94f, -5368.10f, -350.50f, 2.980077f }
};
#define EMBODIED_DESPAIR_COUNT 2
const Position embodiedDespairPos[EMBODIED_DESPAIR_COUNT] =
{
    { 1067.46f, -5877.48f, -360.27f, 1.79192f },
    { 1036.38f, -5874.01f, -360.35f, 1.18423f }
};
#define EMBODIED_FEAR_COUNT 24
const Position embodiedFearPos[EMBODIED_FEAR_COUNT] =
{
    // Entrance - left pack of 4
    { 1058.67f, -5643.02f, -423.70f, 0.542238f },
    { 1056.69f, -5649.16f, -423.70f, 0.531266f },
    { 1052.79f, -5641.00f, -423.70f, 0.301930f },
    { 1050.75f, -5646.90f, -423.70f, 0.400896f },
    // Entrance - right pack of 4
    { 1056.36f, -5615.39f, -423.70f, 5.736331f },
    { 1063.05f, -5614.16f, -423.70f, 5.776928f },
    { 1053.63f, -5608.94f, -423.70f, 5.776928f },
    { 1061.39f, -5607.75f, -423.70f, 5.714340f },
    // Entrance - middle pack of 3
    { 1041.51f, -5628.75f, -423.70f, 6.183964f },
    { 1042.53f, -5624.01f, -423.70f, 6.162547f },
    { 1037.80f, -5625.97f, -424.90f, 6.203388f },
    // Hall - middle pack of 3
    { 1023.78f, -5627.09f, -423.90f, 6.131130f },
    { 1024.42f, -5622.90f, -423.90f, 6.131130f },
    { 1019.52f, -5624.53f, -423.90f, 6.131130f },
    // Middle platform - pack of 4
    {  951.53f, -5620.36f, -416.40f, 6.233232f },
    {  952.19f, -5614.01f, -416.40f, 0.019162f },
    {  942.55f, -5619.50f, -416.40f, 0.025445f },
    {  943.01f, -5613.14f, -416.40f, 6.211241f },
    // Final hall - left pack of 3
    {  875.61f, -5619.27f, -398.10f, 1.491785f },
    {  870.37f, -5623.31f, -398.00f, 1.582891f },
    {  867.07f, -5618.60f, -398.10f, 1.491785f },
    // Final hall - right pack of 3
    {  877.17f, -5598.14f, -398.10f, 4.693069f },
    {  873.56f, -5594.62f, -398.00f, 4.693069f },
    {  868.70f, -5598.00f, -398.10f, 4.652226f }
};

// TODO: create more spawns if we find gunship models or objects
const Position gunshipPos = { -8482.87f, 1284.26f, 6.33f, 4.70f };

#define WHIRLING_CORRUPTION_MIN_DAMAGE_RANGE 30.f

#define PERSONAL_LOOT_ENTRY 718651
#define PERSONAL_LOOT_ENTRY_HEROIC 718652
#define PERSONAL_LOOT_CHANCE 18.f

#define MALICE_TARGETS_COUNT_10 2
#define MALICE_TARGETS_COUNT_25 5

const static std::vector<G3D::Vector2> s_IronStarVertices
{
    { 29, -17 },
    { -54, -17 },
    { -54, 17 },
    { 29, 17 },
};

Creature* GetGarrosh(WorldObject* searcher)
{
    if (InstanceScript* pInstance = searcher->GetInstanceScript())
        return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_GARROSH_HELLSCREAM));

    return NULL;
}


class OrcsSpawnHelper
{
    public:

        OrcsSpawnHelper(Creature* owner) : m_Owner(owner) { }

        void SpawnKorkronWarbringers()
        {
            for (uint8 i = 0; i < KORKRON_WARBRINGERS_COUNT; ++i)
            {
                if (Creature* warbringer = m_Owner->SummonCreature(NPC_KORKRON_WARBRINGER, korkronWarbringersPos[0][i]))
                {
                    ///< TODO: implement mmaps and move straight to the center
                    Position const& pos = korkronWarbringersPos[1][i];
                    warbringer->SetHomePosition(pos);
                    warbringer->GetMotionMaster()->MoveCharge(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 20.0f, POINT_ORC, false);
                }
            }
        }

        void SpawnFarseerWolfRaiders()
        {
            uint8 const side = urand(0, 1);

            G3D::Vector3 const& pos = FarseerWolfRidersStartPos[side];
            if (Creature* farseer = m_Owner->SummonCreature(NPC_FARSEER_WOLF_RIDER, pos.x, pos.y, pos.z))
                farseer->GetMotionMaster()->MovePath(FarseerWolfRidersWPId[side], false);
        }

        void SpawnSiegeEngineers()
        {
            if (Creature* engineer = m_Owner->SummonCreature(NPC_SIEGE_ENGINEER, SiegeEngineerLeft[0], TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 17 * IN_MILLISECONDS))
                engineer->GetMotionMaster()->MovePoint(POINT_ENGINEER, SiegeEngineerLeft[1], false);

            if (Creature* engineer = m_Owner->SummonCreature(NPC_SIEGE_ENGINEER, SiegeEngineerRight[0], TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 17 * IN_MILLISECONDS))
                engineer->GetMotionMaster()->MovePoint(POINT_ENGINEER, SiegeEngineerRight[1], false);

            for (uint8 i = 0; i < KORKRON_IRONSTARS_COUNT; ++i)
                m_Owner->SummonCreature(NPC_KORKRON_IRON_STAR, korkronIronStarsPos[0][i]);
        }

    private:

        Creature* m_Owner;
};

class RealmOfYShaarjHelper
{
        public:

        RealmOfYShaarjHelper(Creature* owner) :
            m_Owner(owner), m_HeartOfYShaarjGuid(ObjectGuid::Empty), m_HeartOfYShaarjIntermissionGuid(ObjectGuid::Empty),
            m_NextIntermission(INTERMISSION_NONE),
            m_YShaarjCreaturesLeft(0), m_firstTime(true)
        {
        }

        void Reset()
        {
            m_Events.Reset();
            m_HeartOfYShaarjGuid = ObjectGuid::Empty;
            m_HeartOfYShaarjIntermissionGuid = ObjectGuid::Empty;
            m_NextIntermission = INTERMISSION_NONE;
            m_YShaarjCreaturesLeft = 0;
            m_firstTime = true;

            if (InstanceScript* pInstance = m_Owner->GetInstanceScript())
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROSH_ENERGY);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPE_AURA);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FAITH_AURA);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_COURAGE_AURA);
            }
        }

        void EnterFight()
        {
            if (Creature* pHeart = m_Owner->SummonCreature(NPC_HEART_OF_YSHAARJ, heartOfYshaarjPos))
            {
                m_HeartOfYShaarjGuid = pHeart->GetGUID();
            }
        }

        void FirstPhaseEnding()
        {
            m_Owner->CastStop();
            m_Owner->AttackStop();
            m_Owner->SetReactState(REACT_PASSIVE);

            m_Owner->CastSpell(m_Owner, SPELL_THROW_AXE_AT_HEART, true);

            m_Owner->NearTeleportTo(centerOfRoomPos);

            m_Events.ScheduleEvent(EVENT_SECOND_PHASE_PREPARE, 2000);
        }

        void SecondPhaseEnding()
        {
            m_Owner->CastStop();
            m_Owner->AttackStop();
            m_Owner->SetReactState(REACT_PASSIVE);

            m_Owner->CastSpell(m_Owner, SPELL_THROW_AXE_AT_HEART, true);

            m_Owner->NearTeleportTo(centerOfRoomPos);

            m_Events.ScheduleEvent(EVENT_THIRD_PHASE_PREPARE, 2000);
        }

        void ThirdPhaseEnding()
        {
            m_Owner->CastStop();
            m_Owner->AttackStop();
            m_Owner->SetReactState(REACT_PASSIVE);

            m_Events.ScheduleEvent(EVENT_FOURTH_PHASE_PREPARE, 2000);
        }

        void PrepareRealmOfYShaarj()
        {
            m_Owner->CastStop();
            m_Owner->AttackStop();
            m_Owner->SetReactState(REACT_PASSIVE);

            if (Creature* pHeart = ObjectAccessor::GetCreature(*m_Owner, m_HeartOfYShaarjGuid))
            {
                pHeart->CastSpell(pHeart, SPELL_ENTER_THE_REALM_OF_YSHAARJ);
            }

            m_Events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ_TELEPORT, 3000);
        }

        void YShaarjCreatureDied()
        {
            if (m_YShaarjCreaturesLeft == 0)
                return;

            --m_YShaarjCreaturesLeft;

            if (m_YShaarjCreaturesLeft == 0)
            {
                RealmOfYShaarjActivateGarrosh();
            }
        }

        void Update(const uint32 diff)
        {
            m_Events.Update(diff);

            if (m_Owner->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = m_Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SECOND_PHASE_PREPARE:
                        SecondPhasePreparing();
                        break;
                    case EVENT_SECOND_PHASE_START:
                        SecondPhaseStarting();
                        break;
                    case EVENT_THIRD_PHASE_PREPARE:
                        ThirdPhasePreparing();
                        break;
                    case EVENT_THIRD_PHASE_START:
                        ThirdPhaseStarting();
                        break;
                    case EVENT_FOURTH_PHASE_PREPARE:
                        FourthPhasePreparing();
                        break;
                    case EVENT_FOURTH_PHASE_START:
                        FourthPhaseStarting();
                        break;
                    case EVENT_REALM_OF_GARROSH_TELEPORT_PREPARE:
                        PrepareTeleportToRealmOfGarrosh();
                        break;
                    case EVENT_REALM_OF_GARROSH_TELEPORT:
                        TeleportToRealmOfGarrosh();
                        break;
                    case EVENT_REALM_OF_YSHAARJ_TELEPORT:
                        TeleportToRealmOfYShaarj();
                        break;
                    case EVENT_REALM_OF_YSHAARJ_SPAWN:
                        CreateRealmOfYShaarj();
                        break;
                    case EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT:
                        TeleportOutOfRealmOfYShaarj();
                        break;
                    case EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT_END:
                        TeleportOutOfRealmOfYShaarjEnd();
                        break;
                    case EVENT_REAM_OF_YSHAARJ_TALK:
                        HearthOfYShaarjTalk();
                        break;
                    case EVENT_REALM_OF_YSHAARJ_ACTIVATE_GARROSH:
                        m_Owner->AI()->DoAction(ACTION_REALM_OF_YSHAARJ_ACTIVATE);
                        break;
                }
            }
        }

    private:

        void SecondPhasePreparing()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_INTERMISSION);

            m_Owner->CastSpell(m_Owner, SPELL_TRANSITION_VISUAL_AURA);

            if (Creature* pHeart = ObjectAccessor::GetCreature(*m_Owner, m_HeartOfYShaarjGuid))
            {
                pHeart->CastSpell(m_Owner, SPELL_TRANSITION_VISUAL);
                m_Owner->SetFullHealth();
            }

            m_Events.ScheduleEvent(EVENT_SECOND_PHASE_START, 9000);
        }

        void SecondPhaseStarting()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_PHASE_2);

            m_Owner->SetReactState(REACT_AGGRESSIVE);

            m_Owner->AI()->DoAction(ACTION_SECOND_PHASE_STARTING_FIRST_TIME);
        }

        void ThirdPhasePreparing()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_INTERMISSION);

            m_Owner->CastSpell(m_Owner, SPELL_TRANSITION_VISUAL_AURA_2);

            if (Creature* pHeart = ObjectAccessor::GetCreature(*m_Owner, m_HeartOfYShaarjGuid))
            {
                pHeart->CastSpell(m_Owner, SPELL_TRANSITION_VISUAL_2);
                m_Owner->RemoveAura(SPELL_PHASE_TWO_TRANSFORM);
                m_Owner->CastSpell(m_Owner, SPELL_PHASE_THREE_TRANSFORM_2, true);
                m_Owner->SetHealth(m_Owner->GetHealth() + m_Owner->CountPctFromMaxHealth(20));
            }

            m_Events.ScheduleEvent(EVENT_THIRD_PHASE_START, 18000);
        }

        void ThirdPhaseStarting()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_PHASE_3);

            m_Owner->SetReactState(REACT_AGGRESSIVE);

            m_Owner->AI()->DoAction(ACTION_THIRD_PHASE_STARTING);
        }

        void FourthPhasePreparing()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_PHASE_4_1);

            m_Owner->CastSpell(m_Owner, SPELL_PHASE_THREE_DE_TRANSFORM_PERIODIC_2);

            m_Events.ScheduleEvent(EVENT_REALM_OF_GARROSH_TELEPORT_PREPARE, 23000);
        }

        void PrepareTeleportToRealmOfGarrosh()
        {
            m_Owner->CastSpell(m_Owner, SPELL_ENTER_REALM_OF_GARROSH);

            m_Events.ScheduleEvent(EVENT_REALM_OF_GARROSH_TELEPORT, 2000);
        }

        void TeleportToRealmOfGarrosh()
        {
            m_Owner->RemoveAura(SPELL_PHASE_TWO_TRANSFORM);
            m_Owner->RemoveAura(SPELL_PHASE_THREE_TRANSFORM);
            m_Owner->RemoveAura(SPELL_PHASE_THREE_TRANSFORM_2);

            m_Owner->CastSpell(m_Owner, SPELL_PHASE_FOUR_TRANSFORM, true);
            m_Owner->SetHealth(m_Owner->CountPctFromMaxHealth(60));

            if (InstanceScript* pInstance = m_Owner->GetInstanceScript())
            {
                pInstance->DoAddAuraOnPlayers(Spells::SPELL_WEAK_MINDED);
                pInstance->DoNearTeleportPlayers(playerTeleportHeroicPos);
            }

            m_Owner->GetMotionMaster()->MovementExpired(false);
            m_Owner->NearTeleportTo(garroshTeleportHeroicPos);

            m_Events.ScheduleEvent(EVENT_FOURTH_PHASE_START, 16000);
        }

        ///< Stormwind
        void FourthPhaseStarting()
        {
            m_Owner->AI()->Talk(SAY_GARROSH_PHASE_4_2);
            m_Owner->SetReactState(REACT_AGGRESSIVE);
            m_Owner->AI()->DoAction(ACTION_FOURTH_PHASE_STARTING);
        }

        void TeleportToRealmOfYShaarj()
        {
            uint32 spellId = 0;

            if (m_Owner->GetMap()->IsHeroic())
            {
                switch (m_NextIntermission)
                {
                    case INTERMISSION_JADE_SERPENT:
                        spellId = SPELL_TELEPORT_TERRACE_AOE;
                        m_NextIntermission = INTERMISSION_TERRACE;
                        break;
                    case INTERMISSION_TERRACE:
                        spellId = SPELL_TELEPORT_RED_CRANE_AOE;
                        m_NextIntermission = INTERMISSION_RED_CRANE;
                        break;
                    case INTERMISSION_RED_CRANE:
                        spellId = SPELL_TELEPORT_JADE_SERPENT_AOE;
                        m_NextIntermission = INTERMISSION_JADE_SERPENT;
                        break;
                    default:
                        spellId = SPELL_TELEPORT_JADE_SERPENT_AOE;
                        m_NextIntermission = INTERMISSION_JADE_SERPENT;
                        break;
                }
            }
            else
            {
                switch (urand(0, 2))
                {
                    case 0: spellId = SPELL_TELEPORT_RED_CRANE_AOE; m_NextIntermission = INTERMISSION_RED_CRANE; break;
                    case 1: spellId = SPELL_TELEPORT_JADE_SERPENT_AOE; m_NextIntermission = INTERMISSION_JADE_SERPENT; break;
                    case 2: spellId = SPELL_TELEPORT_TERRACE_AOE; m_NextIntermission = INTERMISSION_TERRACE; break;
                }
            }

            if (Creature* pHeart = ObjectAccessor::GetCreature(*m_Owner, m_HeartOfYShaarjGuid))
            {
                pHeart->CastSpell(pHeart, spellId);
            }

            // Stop jumping movement
            m_Owner->GetMotionMaster()->MovementExpired(false);
            m_Owner->NearTeleportTo(garroshTeleportPos[(int)m_NextIntermission]);

            m_Events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ_SPAWN, 1000);
        }

        void CreateRealmOfYShaarj()
        {
            if (m_NextIntermission == INTERMISSION_NONE)
                return;

            SpawnYShaarjCreatures(m_NextIntermission);

            m_Owner->CastSpell(m_Owner, SPELL_REALM_OF_YSHAARJ, true);
            m_Owner->CastSpell(m_Owner, SPELL_REALM_OF_YSHAARJ_SELF, true);
            if (!m_firstTime)
                m_Owner->CastSpell(m_Owner, SPELL_YSHAARJ_PROTECTION, true);
            else ///< Disable heal effect for the first time
                m_Owner->CastCustomSpell(SPELL_YSHAARJ_PROTECTION, SpellValueMod::SPELLVALUE_BASE_POINT2, 0, m_Owner, true);

            if (m_Owner->GetMap()->IsHeroic() && m_NextIntermission == IntermissionIndexes::INTERMISSION_TERRACE)
                m_Owner->CastSpell(m_Owner, SPELL_CRUSHING_FEAR_PERIODIC, true);

            m_Owner->AI()->Talk(SAY_GARROSH_YSHAARJ);

            if (InstanceScript* pInstance = m_Owner->GetInstanceScript())
                pInstance->DoAddAuraOnPlayers(SPELL_GARROSH_ENERGY);

            m_firstTime = false;

            m_Events.ScheduleEvent(EVENT_REAM_OF_YSHAARJ_TALK, 5000);
            m_Events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT, TIMER_REALM_OF_YSHAARJ_TELEPORT_OUT);
        }

        void SpawnYShaarjCreatures(IntermissionIndexes intermission)
        {
            if (Creature* pHeart = m_Owner->SummonCreature(NPC_HEART_OF_YSHAARJ_2, heartOfYshaarjIntermissionPos[m_NextIntermission]))
            {
                m_HeartOfYShaarjIntermissionGuid = pHeart->GetGUID();
                pHeart->CastSpell(m_Owner, SPELL_ABSORB_ENERGY);
            }

            if (m_NextIntermission == INTERMISSION_RED_CRANE)
            {
                for (uint8 i = 0; i < EMBODIED_DESPAIR_COUNT; ++i)
                {
                    m_Owner->SummonCreature(NPC_EMBODIED_DESPAIR, embodiedDespairPos[i]);
                }

                m_YShaarjCreaturesLeft = EMBODIED_DESPAIR_COUNT;
            }
            else if (m_NextIntermission == INTERMISSION_JADE_SERPENT)
            {
                for (uint8 i = 0; i < EMBODIED_DOUBT_COUNT; ++i)
                {
                    m_Owner->SummonCreature(NPC_EMBODIED_DOUBT, embodiedDoubtPos[i]);
                }

                m_YShaarjCreaturesLeft = EMBODIED_DOUBT_COUNT;
            }
            else if (m_NextIntermission == INTERMISSION_TERRACE)
            {
                for (uint8 i = 0; i < EMBODIED_FEAR_COUNT; ++i)
                {
                    m_Owner->SummonCreature(NPC_EMBODIED_FEAR, embodiedFearPos[i]);
                }

                m_YShaarjCreaturesLeft = EMBODIED_FEAR_COUNT;
            }
        }

        void HearthOfYShaarjTalk()
        {
            if (Creature* pHeart = ObjectAccessor::GetCreature(*m_Owner, m_HeartOfYShaarjIntermissionGuid))
            {
                pHeart->AI()->Talk(SAY_HEARTH_OF_YSHAARJ);
            }
        }

        void RealmOfYShaarjActivateGarrosh()
        {
            m_Owner->RemoveAura(SPELL_ABSORB_ENERGY);
            m_Owner->RemoveAura(SPELL_YSHAARJ_PROTECTION);
            m_Owner->RemoveAura(SPELL_CRUSHING_FEAR_PERIODIC);

            // He should move towards victims https://www.youtube.com/watch?v=pUhdIdXQYOI
            //m_Owner->SetReactState(REACT_AGGRESSIVE);

            m_Events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ_ACTIVATE_GARROSH, 2*IN_MILLISECONDS);
        }

        void TeleportOutOfRealmOfYShaarj()
        {
            m_Owner->CastStop();
            m_Owner->AttackStop();
            m_Owner->SetReactState(REACT_PASSIVE);

            m_Owner->CastSpell(m_Owner, SPELL_REALM_OF_YSHAARJ_REMOVE, true);
            m_Owner->RemoveAura(SPELL_REALM_OF_YSHAARJ_SELF);

            m_Owner->AI()->DoAction(ACTION_REALM_OF_YSHAARJ_ENDING);

            m_Owner->NearTeleportTo(centerOfRoomPos);

            Position outPos;
            outPos.Relocate(centerOfRoomPos);
            outPos.m_positionZ += 10.f;

            if (InstanceScript* pInstance = m_Owner->GetInstanceScript())
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROSH_ENERGY);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPE_AURA);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FAITH_AURA);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_COURAGE_AURA);
                pInstance->DoNearTeleportPlayers(outPos);
            }

            m_Events.CancelEvent(EVENT_REALM_OF_YSHAARJ_ACTIVATE_GARROSH);
            m_Events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ_TELEPORT_OUT_END, 2000);
        }

        void TeleportOutOfRealmOfYShaarjEnd()
        {
            m_Events.CancelEvent(EVENT_REALM_OF_YSHAARJ_ACTIVATE_GARROSH);

            m_Owner->SetReactState(REACT_AGGRESSIVE);

            m_Owner->AI()->DoAction(ACTION_SECOND_PHASE_STARTING);
        }

    private:

        Creature* m_Owner;
        ObjectGuid m_HeartOfYShaarjGuid;
        ObjectGuid m_HeartOfYShaarjIntermissionGuid;
        EventMap m_Events;
        IntermissionIndexes m_NextIntermission;
        uint32 m_YShaarjCreaturesLeft;
        bool m_firstTime;
};

class GarroshEnergyRegenerator
{
    public:

        GarroshEnergyRegenerator(Creature* owner) : m_Owner(owner) { }

        void Activate() { m_IsActive = true; }
        bool IsActive() const { return m_IsActive; }
        void Stop()
        {
            m_IsActive = false;
        }

        void Reset()
        {
            Stop();
            m_Owner->SetPower(POWER_ENERGY, 0);
            m_UpdateTimer = 900;
        }

        void Update(const uint32 diff)
        {
            if (!m_IsActive)
                return;

            if (m_UpdateTimer <= diff)
            {
                m_UpdateTimer = 900;

                UpdateEnergy();
            }
            else
            {
                m_UpdateTimer -= diff;
            }
        }

    private:

        void UpdateEnergy()
        {
            int32 currentEnergy = m_Owner->GetPower(POWER_ENERGY);
            if (currentEnergy < 100)
            {
                m_Owner->SetPower(POWER_ENERGY, currentEnergy + 1);
            }
            else
            {
                if (!m_Owner->HasUnitState(UNIT_STATE_CASTING))
                {
                    m_Owner->AI()->Talk(SAY_MANIFEST_RAGE);
                    m_Owner->CastSpell(m_Owner, SPELL_MANIFEST_RAGE);

                    // Next update after casting the spell.
                    m_UpdateTimer = 4000;
                    m_Owner->SetPower(POWER_ENERGY, 0);
                }
            }
        }

    private:

        Creature* m_Owner;
        uint32 m_UpdateTimer;
        bool m_IsActive;
};

#define CLUMP_CHECK_RANGE 8.f
#define CLUMP_CHECK_TARGET_COUNT_10 4
#define CLUMP_CHECK_TARGET_COUNT_25 7

struct ClumpCheckSelector : public std::unary_function<Unit*, bool>
{
    public:

        ClumpCheckSelector() { }

        bool operator()(Unit const* target) const
        {
            if (!target)
                return false;

            if (!target->IsPlayer())
                return false;

            std::list<Player*> players;
            target->GetPlayerListInGrid(players, CLUMP_CHECK_RANGE);

            const uint8 neededCount = target->GetMap()->Is25ManRaid() ? CLUMP_CHECK_TARGET_COUNT_25 : CLUMP_CHECK_TARGET_COUNT_10;

            if (players.size() < neededCount)
                return false;

            return true;
        }
};


class boss_garrosh_hellscream : public CreatureScript
{
    public:
        boss_garrosh_hellscream() : CreatureScript("boss_garrosh_hellscream") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_garrosh_hellscreamAI(creature);
        }

        struct boss_garrosh_hellscreamAI : public BossAI
        {
            boss_garrosh_hellscreamAI(Creature* creature) : BossAI(creature, DATA_GARROSH_HELLSCREAM),
                m_OrcsSpawner(creature), m_YShaarjHelper(creature), m_EnergyRegenerator(creature)
            {
                me->setActive(true);

                //ApplyAllImmunities(true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
                me->SetBoundingRadius(1.085f);
                me->SetCombatReach(6.3f);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                me->SetReactState(REACT_DEFENSIVE);
            }

            void Reset() override
            {
                _Reset();

                ClearEncounter();

                InitializePowers();

                me->SetReactState(REACT_DEFENSIVE);

                m_Phase = PHASE_1;
                m_IronStarCreatures = 0;
                m_GrippingDespairEnabled = false;
                m_CanFireIronStar = false;

                m_YShaarjHelper.Reset();
                m_EnergyRegenerator.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_GARROSH_AGGRO);

                m_YShaarjHelper.EnterFight();

                events.ScheduleEvent(EVENT_HELLSCREAMS_WARSONG, TIMER_HELLSCREAMS_WARSONG_FIRST);
                events.ScheduleEvent(EVENT_DESECRATE, TIMER_DESECRATE_FIRST_1);
                events.ScheduleEvent(EVENT_KORKRON_WARBRINGERS, TIMER_KORKRON_WARBRINGERS_FIRST);
                events.ScheduleEvent(EVENT_FARSEER_WOLF_RIDER, TIMER_FARSEER_WOLF_RIDER_FIRST);
                events.ScheduleEvent(EVENT_SIEGE_ENGINEER, TIMER_SIEGE_ENGINEER_FIRST);
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);

                if (IsHeroic())
                    SpawnGunships();

                DoZoneInCombat();
                instance->SetBossState(DATA_GARROSH_HELLSCREAM, IN_PROGRESS);
            }

            void AttackStart(Unit* who) override
            {
                if (me->Attack(who, true))
                    DoStartMovement(who);
            }

            bool CanAIAttack(Unit const* who) const override
            {
                // Prevent attacking a target that have 'SPELL_TOUCH_OF_YSHAARJ*' auras
                if (who->IsCharmed())
                    return false;

                return true;
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                BossAI::SummonedCreatureDies(summon, killer);

                if (m_Phase == Phases::PHASE_2_YSHAARJ &&
                    (summon->GetEntry() == NPC_EMBODIED_DOUBT ||
                    summon->GetEntry() == NPC_EMBODIED_DESPAIR ||
                    summon->GetEntry() == NPC_EMBODIED_FEAR))
                {
                    m_YShaarjHelper.YShaarjCreatureDied();
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_FIGHT:
                        ActivateGarrosh();
                        break;
                    case ACTION_SECOND_PHASE_STARTING_FIRST_TIME:
                        SecondPhaseStarting(true);
                        break;
                    case ACTION_SECOND_PHASE_STARTING:
                        SecondPhaseStarting(false);
                        break;
                    case ACTION_THIRD_PHASE_STARTING:
                        ThirdPhaseStarting();
                        break;
                    case ACTION_FOURTH_PHASE_STARTING:
                        FourthPhaseStarting();
                        break;
                    case ACTION_REALM_OF_YSHAARJ_ACTIVATE:
                        OnActivateInRealmOfYShaarj();
                        break;
                    case ACTION_REALM_OF_YSHAARJ_ENDING:
                        RealmOfYShaarjEnding();
                        break;
                    case ACTION_CLUMP_CHECK:
                        ClumpCheck();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_IRON_STAR_CREATURES)
                {
                    m_IronStarCreatures += data;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_IRON_STAR_CREATURES)
                    return m_IronStarCreatures;

                return 0;
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (m_Phase != (IsHeroic() ? PHASE_4 : PHASE_3))
                {
                    CheckPhases(damage);
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->IsPlayer())
                    Talk(SAY_GARROSH_KILL);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                Talk(SAY_GARROSH_WIPE);

                // The boss is too far
                if (m_Phase == PHASE_4)
                {
                    me->NearTeleportTo(me->GetHomePosition());
                    _EnterEvadeMode();
                    me->SetLastDamagedTime(0);
                    Reset();
                    return;
                }

                BossAI::EnterEvadeMode();
            }

            void JustDied(Unit* who) override
            {
                _JustDied();

                ClearEncounter();

                Talk(IsHeroic() ? SAY_GARROSH_DEATH_2 : SAY_GARROSH_DEATH);

                CompleteEncounter();
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                m_YShaarjHelper.Update(diff);
                m_EnergyRegenerator.Update(diff);

                instance->SetData(DATA_GARROSH_HELLSCREAM_ENERGY, me->GetPower(POWER_ENERGY));

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                // check phase first to prevent updating victim and entering evade mode when not wanted
                if (!(m_Phase == PHASE_1_INTERMISSION || m_Phase == PHASE_2_INTERMISSION || m_Phase == PHASE_3_INTERMISSION))
                    if (!UpdateVictim())
                        return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                //DoMeleeAttackIfReady();
                MeleeDamage();
            }

        private:

            void InitializePowers()
            {
                me->AddAura(SPELL_ZERO_ENERGY, me);

                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                me->SetPower(POWER_ENERGY, 0);
            }

            void SpawnGunships()
            {
                me->SummonCreature(NPC_GUNSHIP_SMALL_CANNON, gunshipPos);
                me->SummonCreature(NPC_GUNSHIP_MAIN_CANNON, gunshipPos);
            }

            void ClearEncounter()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROSH_ENERGY);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_YSHAARJ_AOE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_YSHAARJ_SINGLE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXPLOSIVE_DESPAIR_DEBUFF);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DESECRATED_DMG);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DESECRATED_DMG_2);

                me->DespawnCreaturesInArea(NPC_IRON_STAR, 200);
            }

            void CompleteEncounter()
            {
                DoCastAOE(SPELL_GARROSH_FINALE_HORDE_MOVIE_1);

                for (uint8 i = 0; i < GARROSH_FINALE_NPC_COUNT; ++i)
                {
                    instance->instance->SummonCreature(garroshFinaleNpcSequence[i], garroshFinaleNpcPositions[i]);
                }

                /*PersonalLootProcessor personalLoot(IsHeroic() ? PERSONAL_LOOT_ENTRY_HEROIC : PERSONAL_LOOT_ENTRY);
                instance->instance->ForEachPlayer([&personalLoot](Player* player) -> void
                {
                    personalLoot.ProcessLootFor(player, false, 18.f);
                });*/
            }

            void ActivateGarrosh()
            {
                me->SetHomePosition(garroshFightPos);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_BERSERK:
                        Talk(SAY_GARROSH_BERSERK);
                        me->AddAura(SPELL_BERSERK, me);
                        break;
                    case EVENT_HELLSCREAMS_WARSONG:
                        DoHellscreamsWarsong();
                        events.ScheduleEvent(EVENT_HELLSCREAMS_WARSONG, TIMER_HELLSCREAMS_WARSONG);
                        break;
                    case EVENT_DESECRATE:
                        DoDesecrate();
                        events.ScheduleEvent(EVENT_DESECRATE, ((m_Phase == PHASE_1) ? TIMER_DESECRATE_1 : ((m_Phase == PHASE_2) ? TIMER_DESECRATE_2 : TIMER_DESECRATE_3)));
                        break;
                    case EVENT_KORKRON_WARBRINGERS:
                        DoKorkronWarbringers();
                        events.ScheduleEvent(EVENT_KORKRON_WARBRINGERS, TIMER_KORKRON_WARBRINGERS);
                        break;
                    case EVENT_FARSEER_WOLF_RIDER:
                        DoFarseerWolfRider();
                        events.ScheduleEvent(EVENT_FARSEER_WOLF_RIDER, TIMER_FARSEER_WOLF_RIDER);
                        break;
                    case EVENT_SIEGE_ENGINEER:
                        DoSiegeEngineer();
                        events.ScheduleEvent(EVENT_SIEGE_ENGINEER, TIMER_SIEGE_ENGINEER);
                        break;
                    case EVENT_FIRST_PHASE_ENDING:
                        FirstPhaseEnding();
                        break;
                    case EVENT_SECOND_PHASE_ENDING:
                        SecondPhaseEnding();
                        break;
                    case EVENT_THIRD_PHASE_ENDING:
                        ThirdPhaseEnding();
                        break;
                    case EVENT_REALM_OF_YSHAARJ:
                        EnterRealmOfYShaarj();
                        break;
                    case EVENT_ANNIHILATION:
                        DoAnnihilation();
                        events.ScheduleEvent(EVENT_ANNIHILATION, TIMER_ANNIHILATION);
                        break;
                    case EVENT_WHIRLING_CORRUPTION:
                        DoWhirlingCorruption();
                        events.ScheduleEvent(EVENT_WHIRLING_CORRUPTION, TIMER_WHIRLING_CORRUPTION);
                        break;
                    case EVENT_TOUCH_OF_YSHAARJ:
                        DoTouchOfYShaarj();
                        events.ScheduleEvent(EVENT_TOUCH_OF_YSHAARJ, TIMER_TOUCH_OF_YSHAARJ);
                        break;
                    case EVENT_BOMBARDMENT:
                        DoBombardment();
                        events.ScheduleEvent(EVENT_BOMBARDMENT, TIMER_BOMBARDMENT);
                        break;
                    case EVENT_MALICE:
                        DoMalice();
                        events.ScheduleEvent(EVENT_MALICE, TIMER_MALICE);
                        break;
                }
            }

            void CheckPhases(uint32& damage)
            {
                // Phase 1 ends when the boss reaches 10%
                if (m_Phase == PHASE_1)
                {
                    if (me->GetHealth() <= damage || me->GetHealthPct() < 10.f)
                    {
                        damage = 0;
                        m_Phase = PHASE_1_INTERMISSION;
                        events.ScheduleEvent(EVENT_FIRST_PHASE_ENDING, 1);
                    }
                }
                // Cannot damage the boss when it's the intermission phase
                else if (m_Phase == PHASE_1_INTERMISSION)
                {
                    damage = 0;
                }
                else if (m_Phase == PHASE_2)
                {
                    if (me->GetHealth() <= damage || me->GetHealthPct() < 10.f)
                    {
                        damage = 0;
                        m_Phase = PHASE_2_INTERMISSION;
                        events.ScheduleEvent(EVENT_SECOND_PHASE_ENDING, 1);
                    }
                }
                else if (m_Phase == PHASE_2_YSHAARJ)
                {
                    if (me->GetHealth() <= damage || me->GetHealthPct() < 10.f)
                    {
                        damage = 0;
                    }
                }
                else if (m_Phase == PHASE_2_INTERMISSION)
                {
                    damage = 0;
                }
                else if (m_Phase == PHASE_3)
                {
                    if (me->GetHealth() <= damage || me->GetHealthPct() < 2.f)
                    {
                        damage = 0;
                        m_Phase = PHASE_3_INTERMISSION;
                        events.ScheduleEvent(EVENT_THIRD_PHASE_ENDING, 1);
                    }
                }
                else if (m_Phase == PHASE_3_INTERMISSION)
                {
                    damage = 0;
                }
                /*else if (m_Phase == PHASE_4)
                {

                }*/
            }

            void MeleeDamage()
            {
                Unit* victim = me->GetVictim();
                if (!victim)
                    return;

                if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    me->AttackerStateUpdate(victim);
                    me->resetAttackTimer();

                    if (m_GrippingDespairEnabled && (m_Phase == PHASE_2 || m_Phase == PHASE_3))
                    {
                        DoGrippingDespair(victim);
                    }
                }
            }

            void DoHellscreamsWarsong()
            {
                Talk(SAY_GARROSH_WARSONG);

                DoCastAOE(SPELL_HELLSCREAMS_WARSONG);
            }

            void DoDesecrate()
            {
                DoCastAOE(SPELL_DESECRATE_AOE);
            }

            void DoKorkronWarbringers()
            {
                m_OrcsSpawner.SpawnKorkronWarbringers();
            }

            void DoFarseerWolfRider()
            {
                Talk(SAY_GARROSH_FARSEER);

                m_OrcsSpawner.SpawnFarseerWolfRaiders();
            }

            void DoSiegeEngineer()
            {
                // need to despawn previous creatures
                summons.DespawnEntry(NPC_SIEGE_ENGINEER);
                summons.DespawnEntry(NPC_KORKRON_IRON_STAR);

                m_OrcsSpawner.SpawnSiegeEngineers();
            }

            void FirstPhaseEnding()
            {
                events.CancelEvent(EVENT_HELLSCREAMS_WARSONG);
                events.CancelEvent(EVENT_DESECRATE);
                events.CancelEvent(EVENT_KORKRON_WARBRINGERS);
                events.CancelEvent(EVENT_FARSEER_WOLF_RIDER);
                events.CancelEvent(EVENT_SIEGE_ENGINEER);

                m_YShaarjHelper.FirstPhaseEnding();
            }

            void SecondPhaseEnding()
            {
                events.CancelEvent(EVENT_REALM_OF_YSHAARJ);
                events.CancelEvent(EVENT_WHIRLING_CORRUPTION);
                events.CancelEvent(EVENT_TOUCH_OF_YSHAARJ);
                events.CancelEvent(EVENT_DESECRATE);

                m_YShaarjHelper.SecondPhaseEnding();
            }

            void SecondPhaseStarting(bool isFistTime)
            {
                if (isFistTime)
                {
                    summons.DespawnEntry(NPC_SIEGE_ENGINEER);
                    summons.DespawnEntry(NPC_KORKRON_IRON_STAR);
                }
                else
                {
                    // Need to continue adds attacking
                    EntryCheckPredicate check1(NPC_KORKRON_WARBRINGER);
                    summons.DoAction(ACTION_RESUME_FIGHT, check1);

                    EntryCheckPredicate check2(NPC_FARSEER_WOLF_RIDER);
                    summons.DoAction(ACTION_RESUME_FIGHT, check2);

                    events.ScheduleEvent(EVENT_WHIRLING_CORRUPTION, TIMER_WHIRLING_CORRUPTION_FIRST);
                    events.ScheduleEvent(EVENT_TOUCH_OF_YSHAARJ, TIMER_TOUCH_OF_YSHAARJ_FIRST_1);
                    events.ScheduleEvent(EVENT_DESECRATE, TIMER_DESECRATE_FIRST_2);

                    m_GrippingDespairEnabled = true;
                }

                m_Phase = PHASE_2;

                CalculateEmpoweredAuras();

                events.ScheduleEvent(EVENT_REALM_OF_YSHAARJ, isFistTime ? TIMER_REALM_OF_YSHAARJ_FIRST : TIMER_REALM_OF_YSHAARJ);
            }

            void ThirdPhaseStarting()
            {
                m_Phase = PHASE_3;

                CalculateEmpoweredAuras();

                events.ScheduleEvent(EVENT_WHIRLING_CORRUPTION, TIMER_WHIRLING_CORRUPTION_FIRST);
                events.ScheduleEvent(EVENT_TOUCH_OF_YSHAARJ, TIMER_TOUCH_OF_YSHAARJ_FIRST_2);
                events.ScheduleEvent(EVENT_DESECRATE, TIMER_DESECRATE_FIRST_3);
            }

            void ThirdPhaseEnding()
            {
                events.CancelEvent(EVENT_WHIRLING_CORRUPTION);
                events.CancelEvent(EVENT_TOUCH_OF_YSHAARJ);
                events.CancelEvent(EVENT_DESECRATE);

                m_YShaarjHelper.ThirdPhaseEnding();
            }

            void FourthPhaseStarting()
            {
                m_Phase = PHASE_4;

                DoCast(me, SPELL_CALL_GUNSHIP, true);

                events.ScheduleEvent(EVENT_BOMBARDMENT, TIMER_BOMBARDMENT_FIRST);
                events.ScheduleEvent(EVENT_MALICE, TIMER_MALICE_FIRST);

                m_EnergyRegenerator.Reset();
                m_EnergyRegenerator.Activate();
            }

            void EnterRealmOfYShaarj()
            {
                m_Phase = PHASE_2_YSHAARJ;

                // Need to stop adds attacking and resume after intermission
                EntryCheckPredicate check1(NPC_KORKRON_WARBRINGER);
                summons.DoAction(ACTION_PAUSE_FIGHT, check1);

                EntryCheckPredicate check2(NPC_FARSEER_WOLF_RIDER);
                summons.DoAction(ACTION_PAUSE_FIGHT, check2);

                events.CancelEvent(EVENT_WHIRLING_CORRUPTION);
                events.CancelEvent(EVENT_TOUCH_OF_YSHAARJ);
                events.CancelEvent(EVENT_DESECRATE);

                m_YShaarjHelper.PrepareRealmOfYShaarj();
            }

            void OnActivateInRealmOfYShaarj()
            {
                events.ScheduleEvent(EVENT_ANNIHILATION, TIMER_ANNIHILATION);
            }

            void RealmOfYShaarjEnding()
            {
                events.CancelEvent(EVENT_ANNIHILATION);

                summons.DespawnEntry(NPC_EMBODIED_FEAR);
                summons.DespawnEntry(NPC_EMBODIED_DESPAIR);
                summons.DespawnEntry(NPC_EMBODIED_DOUBT);
                summons.DespawnEntry(NPC_HEART_OF_YSHAARJ_2);
            }

            void CalculateEmpoweredAuras()
            {
                if (me->GetPower(POWER_ENERGY) >= 100)
                    me->AddAura(SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA, me);

                if (me->GetPower(POWER_ENERGY) >= 75)
                    me->AddAura(SPELL_EMPOWERED_DESECRATE_AURA, me);

                if (me->GetPower(POWER_ENERGY) >= 50)
                    me->AddAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AURA, me);

                if (me->GetPower(POWER_ENERGY) >= 25)
                    me->AddAura(SPELL_EMPOWERED_WHIRLING_CORRUPTION_AURA, me);
            }

            void DoAnnihilation()
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                {
                    me->StopMoving();
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->Clear(false);

                    me->SetOrientation(me->GetAngle(target));
                    me->SetFacingToObject(target);

                    DoCast(target, SPELL_ANNIHILATION_DMG);
                }
                else
                {
                    if (!me->isMoving())
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true))
                            me->GetMotionMaster()->MoveFollow(l_Target, 0.0f, 0.0f);
                }
            }

            void DoWhirlingCorruption()
            {
                if (me->HasAura(SPELL_EMPOWERED_WHIRLING_CORRUPTION_AURA))
                {
                    Talk(SAY_GARROSH_WHIRLING_2);
                    DoCast(me, SPELL_EMPOWERED_WHIRLING_CORRUPTION);
                }
                else
                {
                    Talk(SAY_GARROSH_WHIRLING);
                    DoCast(me, SPELL_WHIRLING_CORRUPTION);
                }
            }

            void DoTouchOfYShaarj()
            {
                if (me->HasAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AURA))
                {
                    me->CastCustomSpell(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE, SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 4 : 2, me, false);
                }
                else
                {
                    me->CastCustomSpell(SPELL_TOUCH_OF_YSHAARJ_AOE, SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 4 : 2, me, false);
                }
            }

            void DoGrippingDespair(Unit* victim)
            {
                if (!urand(0, 1))
                    return;

                if (me->HasAura(SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA))
                {
                    DoCast(victim, SPELL_EMPOWERED_GRIPPING_DESPAIR_PERIODIC_DMG, true);
                }
                else
                {
                    DoCast(victim, SPELL_GRIPPING_DESPAIR_PERIODIC_DMG, true);
                }
            }

            void DoBombardment()
            {
                Talk(SAY_BOMBARDMENT);

                DoCast(me, SPELL_CALL_BOMBARDMENT);

                m_CanFireIronStar = true;
            }

            void DoMalice()
            {
                DoCastAOE(SPELL_MALICE);
            }

            void ClumpCheck()
            {
                if (!m_CanFireIronStar)
                    return;

                ClumpCheckSelector selector;
                std::list<Unit*> targets;
                SelectTargetList(targets, selector, 1, SELECT_TARGET_RANDOM);

                if (targets.empty())
                    return;

                Unit* target = targets.front();

                if (Creature* pCreature = me->SummonCreature(NPC_CLUMP, *target, TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    pCreature->CastSpell(pCreature, SPELL_FIRE_IRON_STAR, true);
                    m_CanFireIronStar = false;
                }
            }

        private:

            OrcsSpawnHelper m_OrcsSpawner;
            RealmOfYShaarjHelper m_YShaarjHelper;
            GarroshEnergyRegenerator m_EnergyRegenerator;
            Phases m_Phase;
            uint32 m_IronStarCreatures;
            bool m_GrippingDespairEnabled;
            bool m_CanFireIronStar;
        };
};

class npc_garrosh_hellscream_thrall : public CreatureScript
{
    public:
        npc_garrosh_hellscream_thrall() : CreatureScript("npc_garrosh_hellscream_thrall") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_thrallAI(creature);
        }

        struct npc_garrosh_hellscream_thrallAI : public ScriptedAI
        {
            npc_garrosh_hellscream_thrallAI(Creature* creature) : ScriptedAI(creature), sceneHelper(creature->GetGUID(), creature->GetMap())
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);

                m_GarroshGuid = ObjectGuid::Empty;
            }

            void Reset() override
            {
                events.Reset();
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_GARROSH_HELLSCREAM_INTRO:
                        InitializeGarroshIntro();
                        break;
                    case ACTION_JUMP_INTO_ROOM:
                        JumpIntoRoom();
                        break;
                    case ACTION_MOVE_TO_FIGHT:
                        MoveToFightGarrosh();
                        break;
                    case ACTION_FIGHT:
                        FightGarrosh();
                        break;
                    case ACTION_HIT_BY_GARROSH:
                        HitByGarrosh();
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);
            }

        private:

            void InitializeGarroshIntro()
            {
                Talk(SAY_THRALL_INTRO_1);

                const Position balconyPos = { 1125.45f, -5644.99f, -291.32f, 3.04f };

                if (Creature* pGarrosh = GetGarrosh(me))
                {
                    m_GarroshGuid = pGarrosh->GetGUID();
                }

                // todo add thi
                sceneHelper.AddSceneActionMovePos(balconyPos, 1000);
                sceneHelper.AddSceneActionAI(ACTION_JUMP_INTO_ROOM, 4000);
                sceneHelper.AddSceneActionTalkByActor(m_GarroshGuid, SAY_GARROSH_INTRO_1, 8000);
                sceneHelper.AddSceneActionTalkByActor(m_GarroshGuid, SAY_GARROSH_INTRO_2, 21000);
                sceneHelper.AddSceneActionTalkByActor(m_GarroshGuid, SAY_GARROSH_INTRO_3, 13000);
                sceneHelper.AddSceneActionTalk(SAY_THRALL_INTRO_2, 18000);
                sceneHelper.AddSceneCast(SPELL_CALL_OF_THE_ELEMENTS, 10000);
                sceneHelper.AddSceneActionTalkByActor(m_GarroshGuid, SAY_GARROSH_INTRO_4, 7000);
                sceneHelper.AddSceneActionTalk(SAY_THRALL_INTRO_3, 21000);
                sceneHelper.AddSceneActionTalkByActor(m_GarroshGuid, SAY_GARROSH_INTRO_5, 7000);
                sceneHelper.AddSceneActionAI(ACTION_MOVE_TO_FIGHT, 4000);
                sceneHelper.AddSceneActionAI(ACTION_FIGHT, 5000);
                sceneHelper.AddSceneActionAI(ACTION_HIT_BY_GARROSH, 3000);
                sceneHelper.AddSceneCast(SPELL_EXHAUSTED, 2000);
            }

            void JumpIntoRoom()
            {
                me->GetMotionMaster()->MoveJump(centerOfRoomPos, 20.0f, 20.0f, centerOfRoomPos.GetOrientation());
            }

            void MoveToFightGarrosh()
            {
                me->GetMotionMaster()->MovePoint(0, thrallFightPos);

                if (Creature* pGarrosh = GetGarrosh(me))
                {
                    pGarrosh->GetMotionMaster()->MovePoint(0, garroshFightPos);
                }
            }

            void FightGarrosh()
            {
                DoCast(SPELL_ATTACK_GARROSH);

                if (Creature* pGarrosh = GetGarrosh(me))
                {
                    pGarrosh->CastSpell(pGarrosh, SPELL_DEFEND_AGAIST_THRALL);
                    pGarrosh->AI()->DoAction(ACTION_FIGHT);
                }
            }

            void HitByGarrosh()
            {
                if (Creature* pGarrosh = GetGarrosh(me))
                {
                    pGarrosh->CastSpell(me, SPELL_ATTACK_THRALL);
                }
            }

        private:
            SceneHelper sceneHelper;
            InstanceScript* pInstance;
            ObjectGuid m_GarroshGuid;
        };
};

class npc_garrosh_hellscream_heart_of_yshaarj : public CreatureScript
{
    public:
        npc_garrosh_hellscream_heart_of_yshaarj() : CreatureScript("npc_garrosh_hellscream_heart_of_yshaarj") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_heart_of_yshaarjAI(creature);
        }

        struct npc_garrosh_hellscream_heart_of_yshaarjAI : public ScriptedAI
        {
            npc_garrosh_hellscream_heart_of_yshaarjAI(Creature* creature) : ScriptedAI(creature)
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

class npc_garrosh_hellscream_heart_of_yshaarj_2 : public CreatureScript
{
    public:
        npc_garrosh_hellscream_heart_of_yshaarj_2() : CreatureScript("npc_garrosh_hellscream_heart_of_yshaarj_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_heart_of_yshaarj_2AI(creature);
        }

        struct npc_garrosh_hellscream_heart_of_yshaarj_2AI : public ScriptedAI
        {
            npc_garrosh_hellscream_heart_of_yshaarj_2AI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

        private:

        private:

            InstanceScript* pInstance;
        };
};

class npc_garrosh_hellscream_desecrated_weapon : public CreatureScript
{
    public:
        npc_garrosh_hellscream_desecrated_weapon() : CreatureScript("npc_garrosh_hellscream_desecrated_weapon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_desecrated_weaponAI(creature);
        }

        struct npc_garrosh_hellscream_desecrated_weaponAI : public Scripted_NoMovementAI
        {
            npc_garrosh_hellscream_desecrated_weaponAI(Creature* creature) : Scripted_NoMovementAI(creature),
                m_OldScale(100.f)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);

                me->SetBoundingRadius(6.0f);
                me->SetCombatReach(6.0f);

                me->SetReactState(REACT_PASSIVE);

                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                me->AddAura(IsEmpowered() ? SPELL_EMPOWERED_DESECRATED_WEAPON_VISUAL : SPELL_DESECRATED_WEAPON_VISUAL, me);
                me->AddAura(SPELL_DESECRATED_WEAPON_2, me);

                if (IsEmpowered())
                    me->AddAura(SPELL_POWER_OF_THE_OLD_GOD, me);

                m_UpdateScaleTimer = 1000;
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (me->GetHealth() <= damage)
                {
                    if (IsEmpowered())
                    {
                        damage = 0;
                    }
                }
            }

            void JustDied(Unit* who) override
            {
                me->DespawnOrUnsummon(100);
            }

            void UpdateAI(const uint32 diff) override
            {
                UpdateTargets(diff);
            }

        private:

            bool IsEmpowered() const
            {
                return me->GetEntry() == NPC_EMPOWERED_DESECRATED_WEAPON;
            }

            void UpdateTargets(const uint32 diff)
            {
                if (m_UpdateScaleTimer <= diff)
                {
                    m_UpdateScaleTimer = 1000;

                    UpdateScale();
                }
                else
                {
                    m_UpdateScaleTimer -= diff;
                }
            }

            void UpdateScale()
            {
                if (me->GetHealth() > 0)
                {
                    ///< TODO: implement m_ScaleCurveID
                    float scale = me->GetHealthPct() / 100.0f;
                    if (scale == m_OldScale)
                        return;

                    me->SetObjectScale(scale);

                    if (AreaTrigger* pAreaTrigger = me->GetAreaTrigger(IsEmpowered() ? SPELL_EMPOWERED_DESECRATED_WEAPON_VISUAL : SPELL_DESECRATED_WEAPON_VISUAL))
                    {
                        pAreaTrigger->SetObjectScale(scale);
                        //pAreaTrigger->SetFloatValue(AREATRIGGER_FIELD_EXPLICIT_SCALE, scale);
                        pAreaTrigger->SetObjectScale(MAX_AREATRIGGER_SCALE);
                    }

                    m_OldScale = scale;
                }
            }

        private:
            uint32 m_UpdateScaleTimer;
            float m_OldScale;
        };
};

struct npc_garrosh_hellscream_orcsAI : public ScriptedAI
{
    npc_garrosh_hellscream_orcsAI(Creature* creature)
        : ScriptedAI(creature)
    {
        //ApplyAllImmunities(true);

        ///< Disable some immunities
        for (uint32 mechanic : { MECHANIC_SNARE, MECHANIC_STUN, MECHANIC_ROOT, MECHANIC_GRIP})
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, mechanic, false);

        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, false);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, false);

        me->m_CombatDistance = 70.0f;

        me->SetReactState(REACT_PASSIVE);
        me->setRegeneratingHealth(false);
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_ORC)
            me->GetMotionMaster()->MoveCharge(centerOfRoomPos.GetPositionX(), centerOfRoomPos.GetPositionY(), centerOfRoomPos.GetPositionZ(), 20.0f, POINT_ORC_CENTER, false);
        else if ((type == POINT_MOTION_TYPE && id == POINT_ORC_CENTER)
            || (type == WAYPOINT_MOTION_TYPE && id == 7))
            AtEndPoint();
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (me->GetEntry() == NPC_FARSEER_WOLF_RIDER/*todo check this && spell->_IsCrowdControl(0, false)*/)
        {
            me->AI()->AttackStart(caster);
            AtEndPoint();
        }
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/) override
    {
        if (attacker->GetTypeId() == TYPEID_PLAYER)
        {
            me->GetMotionMaster()->MovementExpired(false);
            me->GetMotionMaster()->Clear();

            me->AI()->AttackStart(attacker);
            AtEndPoint();
        }
    }

    void AttackStart(Unit* victim) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        ScriptedAI::AttackStart(victim);
    }

    void DoAction(const int32 action) override
    {
        switch (action)
        {
            case ACTION_PAUSE_FIGHT:
                PauseFight();
                break;
            case ACTION_RESUME_FIGHT:
                events.ScheduleEvent(Events::EVENT_RESUME_FIGHT, Timers::TIMER_RESUME_FIGHT);
                break;
        }
    }

    void JustDied(Unit* who) override
    {
        events.Reset();
        summons.DespawnAll();

        me->DespawnOrUnsummon(3000);
    }

    void UpdateAI(const uint32 diff) override
    {
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

protected:

    virtual void ExecuteEvent(const uint32 eventId)
    {
        if (eventId == EVENT_RESUME_FIGHT)
            ResumeFight();
    }

    virtual void DoAtEndPoint() { }

    virtual void DoResumeFight() { }

private:

    void AtEndPoint()
    {
        if (!_atEndCalled)
        {
            DoAtEndPoint();
            _atEndCalled = true;
        }
    }

    void PauseFight()
    {
        me->CastStop();
        me->AttackStop();
        me->SetReactState(REACT_PASSIVE);
        //me->RemoveNegativeAuras();
    }

    void ResumeFight()
    {
        DoResumeFight();
    }

    bool _atEndCalled = false;
};

using OrcAI = npc_garrosh_hellscream_orcsAI;

class npc_garrosh_hellscream_korkron_warbringer : public CreatureScript
{
    public:
        npc_garrosh_hellscream_korkron_warbringer() : CreatureScript("npc_garrosh_hellscream_korkron_warbringer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_korkron_warbringerAI(creature);
        }

        struct npc_garrosh_hellscream_korkron_warbringerAI : public OrcAI
        {
            npc_garrosh_hellscream_korkron_warbringerAI(Creature* creature) : OrcAI(creature)
            {
                if (IsHeroic())
                {
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                }
            }

            void DoAtEndPoint() override
            {
                if (IsHeroic())
                    me->AddAura(SPELL_BLOOD_FRENZY, me);

                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);
                events.ScheduleEvent(EVENT_HAMSTRING, urand(TIMER_HAMSTRING_FIRST_MIN, TIMER_HAMSTRING_FIRST_MAX));
            }

            void DoResumeFight() override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_HAMSTRING, urand(TIMER_HAMSTRING_FIRST_MIN, TIMER_HAMSTRING_FIRST_MAX));
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                OrcAI::ExecuteEvent(eventId);

                switch (eventId)
                {
                    case EVENT_HAMSTRING:
                        DoCastVictim(SPELL_HAMSTRING);
                        events.ScheduleEvent(EVENT_HAMSTRING, urand(TIMER_HAMSTRING_MIN, TIMER_HAMSTRING_MAX));
                        break;
                }
            }
        };
};

class npc_garrosh_hellscream_farseer_wolf_rider : public CreatureScript
{
    public:
        npc_garrosh_hellscream_farseer_wolf_rider() : CreatureScript("npc_garrosh_hellscream_farseer_wolf_rider") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_farseer_wolf_riderAI(creature);
        }

        struct npc_garrosh_hellscream_farseer_wolf_riderAI : public OrcAI
        {
            npc_garrosh_hellscream_farseer_wolf_riderAI(Creature* creature) : OrcAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                me->ApplySpellImmune(SPELL_IRON_STAR_IMPACT_DMG_2, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            }

            void Reset() override
            {
              me->AddAura(SPELL_ANCESTRAL_FURY, me);
            }

            void DoAtEndPoint() override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);

                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING_FIRST);
                events.ScheduleEvent(EVENT_ANCESTRAL_CHAIN_HEAL, TIMER_ANCESTRAL_CHAIN_HEAL_FIRST);
            }

            void DoResumeFight() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
                events.ScheduleEvent(EVENT_ANCESTRAL_CHAIN_HEAL, TIMER_ANCESTRAL_CHAIN_HEAL);
            }

            void ExecuteEvent(const uint32 eventId)
            {
                OrcAI::ExecuteEvent(eventId);

                switch (eventId)
                {
                    case EVENT_CHAIN_LIGHTNING:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_CHAIN_LIGHTNING);

                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
                        break;
                    }
                    case EVENT_ANCESTRAL_CHAIN_HEAL:
                        DoCast(me, SPELL_ANCESTRAL_CHAIN_HEAL);
                        events.ScheduleEvent(EVENT_ANCESTRAL_CHAIN_HEAL, TIMER_ANCESTRAL_CHAIN_HEAL);
                        break;
                }
            }
        };
};

class npc_garrosh_hellscream_siege_engineer : public CreatureScript
{
    public:
        npc_garrosh_hellscream_siege_engineer() : CreatureScript("npc_garrosh_hellscream_siege_engineer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_siege_engineerAI(creature);
        }

        struct npc_garrosh_hellscream_siege_engineerAI : public OrcAI
        {
            npc_garrosh_hellscream_siege_engineerAI(Creature* creature) : OrcAI(creature)
            {
                //ApplyAllImmunities(true);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_ENGINEER)
                    DoCast(me, SPELL_POWER_IRON_STAR);
            }

            void DamageTaken(Unit* attacker, uint32& /*damage*/) override { }

            void AttackStart(Unit* victim) override { }

            void UpdateAI(const uint32 diff) override { }
        };
};

class OrcAddsCheck
{
    public:
        OrcAddsCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) {}

        bool operator()(Unit* c)
        {
            if (c->GetEntry() != NPC_KORKRON_WARBRINGER &&
                c->GetEntry() != NPC_FARSEER_WOLF_RIDER)
                return false;

            if (c->IsAlive() && i_obj->GetExactDist(c) <= i_range)
                return true;

            return false;
        }

    private:
        WorldObject const* i_obj;
        float i_range;
};

class npc_garrosh_hellscream_korkron_iron_star : public CreatureScript
{
    public:
        npc_garrosh_hellscream_korkron_iron_star() : CreatureScript("npc_garrosh_hellscream_korkron_iron_star") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_korkron_iron_starAI(creature);
        }

        struct npc_garrosh_hellscream_korkron_iron_starAI : public Scripted_NoMovementAI
        {
            npc_garrosh_hellscream_korkron_iron_starAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                me->SetDisableGravity(true);
                me->SetAnimTier(UnitBytes1_Flags(UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER), false);
                me->SetSheath(SHEATH_STATE_MELEE);

                m_IsPowered = false;
                m_IsLeftSide = me->GetPositionY() < -5640.f;
                m_UpdateTargetsTimer = 1000;

                _polygonVertices = s_IronStarVertices;

                float const orientation = me->NormalizeOrientation(me->GetOrientation() + (M_PI / 2));

                float angleSin = std::sin(orientation);
                float angleCos = std::cos(orientation);

                // This is needed to rotate the vertices, following orientation
                for (G3D::Vector2& vertice : _polygonVertices)
                {
                    float x = vertice.x * angleCos - vertice.y * angleSin;
                    float y = vertice.y * angleCos + vertice.x * angleSin;
                    vertice.x = x;
                    vertice.y = y;
                }
            }

            bool IsInPoligon(Position const* pos)
            {
                float testX = pos->GetPositionX();
                float testY = pos->GetPositionY();

                bool locatedInPolygon = false;

                for (std::size_t vertex = 0; vertex < _polygonVertices.size(); ++vertex)
                {
                    std::size_t nextVertex;

                    if (vertex == (_polygonVertices.size() - 1))
                        nextVertex = 0;
                    else
                        nextVertex = vertex + 1;

                    float vertX_i = me->GetPositionX() + _polygonVertices[vertex].x;
                    float vertY_i = me->GetPositionY() + _polygonVertices[vertex].y;
                    float vertX_j = me->GetPositionX() + _polygonVertices[nextVertex].x;
                    float vertY_j = me->GetPositionY() + _polygonVertices[nextVertex].y;

                    bool belowLowY = vertY_i > testY;
                    bool belowHighY = vertY_j > testY;

                    bool withinYsEdges = belowLowY != belowHighY;

                    if (withinYsEdges)
                    {
                        float slopeOfLine = (vertX_j - vertX_i) / (vertY_j - vertY_i);

                        float pointOnLine = (slopeOfLine* (testY - vertY_i)) + vertX_i;

                        bool isLeftToLine = testX < pointOnLine;

                        if (isLeftToLine)
                            locatedInPolygon = !locatedInPolygon;
                    }
                }

                return locatedInPolygon;
            }

            const float c_DamageRange = 70.0f;

            void DoAction(const int32 action) override
            {
                if (action == ACTION_POWER_IRON_STAR)
                    HandlePowerIronStar();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_IRON_STAR)
                    HandleExplode();
            }

            void JustDied(Unit* who) override
            {
                m_IsPowered = false;

                me->DespawnOrUnsummon(3000);
            }

            void UpdateAI(const uint32 diff) override
            {
                UpdateTargets(diff);
            }

        private:

            void UpdateTargets(const uint32 diff)
            {
                if (!m_IsPowered)
                    return;

                if (m_UpdateTargetsTimer <= diff)
                {
                    m_UpdateTargetsTimer = 1000;

                    std::list<Player*> players;
                    me->GetPlayerListInGrid(players, c_DamageRange);

                    float minZ = me->GetPositionZ() - 1.0f;
                    float maxZ = me->GetPositionZ() + 1.0f;

                    players.remove_if([this, minZ, maxZ](Player const* target) -> bool
                    {
                        return !IsInPoligon(target)
                            || target->GetPositionZ() < minZ
                            || target->GetPositionZ() > maxZ;
                    });

                    for (Player* target : players)
                        me->CastSpell(target, SPELL_IRON_STAR_IMPACT_DMG_1, true);

                    DamageCreatures();
                }
                else
                {
                    m_UpdateTargetsTimer -= diff;
                }
            }

            void DamageCreatures()
            {
                std::list<Creature*> creatures;
                OrcAddsCheck checker(me, c_DamageRange);
                Trinity::CreatureListSearcher<OrcAddsCheck> searcher(me, creatures, checker);
                //me->VisitNearbyGridObject(c_DamageRange, searcher);
                Cell::VisitWorldObjects(me, searcher, c_DamageRange);

                float minZ = me->GetPositionZ() - 1.0f;
                float maxZ = me->GetPositionZ() + 1.0f;

                creatures.remove_if([this, minZ, maxZ](Creature const* target) -> bool
                {
                    return !IsInPoligon(target)
                        || target->GetPositionZ() < minZ
                        || target->GetPositionZ() > maxZ;
                });

                ///< Remove creatures that was hited
                creatures.remove_if([&](Creature const* cre) -> bool { return m_hitedCreatures.find(cre->GetGUID()) != m_hitedCreatures.end(); });

                if (creatures.empty())
                    return;

                for (Creature* creature : creatures)
                {
                    ///< Hotfix: Farseer Wolf Rider can no longer be hit multiple times by the same Iron Star.
                    if (creature->GetEntry() == NPC_FARSEER_WOLF_RIDER)
                        m_hitedCreatures.emplace(creature->GetGUID());

                    creature->CastSpell(creature, SPELL_IRON_STAR_IMPACT_DMG_2, true);
                }

                if (Creature* pGarrosh = GetGarrosh(me))
                    pGarrosh->AI()->SetData(DATA_IRON_STAR_CREATURES, creatures.size());
            }

            void HandlePowerIronStar()
            {
                if (m_IsPowered)
                    return;

                m_IsPowered = true;

                me->AddAura(SPELL_IRON_STAR_IMPACT, me);
                me->AddAura(SPELL_IRON_STAR_IMPACT_2, me);

                me->GetMotionMaster()->MovePoint(POINT_IRON_STAR, korkronIronStarsPos[1][size_t(m_IsLeftSide)], false);

                if (Creature* pGarrosh = GetGarrosh(me))
                    pGarrosh->AI()->Talk(SAY_GARROSH_IRON_STAR);
            }

            void HandleExplode()
            {
                m_IsPowered = false;

                DoCast(me, SPELL_EXPLODING_IRON_STAR, true);

                me->Kill(me);
            }

        private:
            bool m_IsLeftSide;
            uint32 m_UpdateTargetsTimer;
            bool m_IsPowered;

            std::set<ObjectGuid> m_hitedCreatures;
            std::vector<G3D::Vector2> _polygonVertices;
        };
};

class npc_garrosh_hellscream_embodied : public CreatureScript
{
    public:
        npc_garrosh_hellscream_embodied() : CreatureScript("npc_garrosh_hellscream_embodied") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_embodiedAI(creature);
        }

        struct npc_garrosh_hellscream_embodiedAI : public ScriptedAI
        {
            npc_garrosh_hellscream_embodiedAI(Creature* creature) : ScriptedAI(creature)
            {
                m_ConsumedAuraId = 0;
                switch (me->GetEntry())
                {
                    case NPC_EMBODIED_DESPAIR:
                        m_ConsumedAuraId = SPELL_CONSUMED_HOPE;
                        //ApplyAllImmunities(true);
                        break;
                    case NPC_EMBODIED_DOUBT:
                        m_ConsumedAuraId = SPELL_CONSUMED_FAITH;
                        break;
                    case NPC_EMBODIED_FEAR:
                        m_ConsumedAuraId = SPELL_CONSUMED_COURAGE;
                        break;
                }
            }

            void Reset() override
            {
                events.Reset();

                me->AddAura(SPELL_REDUCE_CRITICAL_STRIKE_CHANCE, me);

                if (m_ConsumedAuraId)
                {
                    me->AddAura(m_ConsumedAuraId, me);
                }
            }

            void EnterCombat(Unit* who) override
            {
                switch (me->GetEntry())
                {
                    case Adds::NPC_EMBODIED_DOUBT:
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_EMBODIED_DOUBT, urand(TIMER_EMBODIED_DOUBT_MIN, TIMER_EMBODIED_DOUBT_MAX));
                        break;
                    case Adds::NPC_EMBODIED_DESPAIR:
                    {
                        std::list<Creature*> l_Despairs;
                        GetOtherEmbodiedDespairs(l_Despairs);

                        for (auto l_Despair : l_Despairs)
                        {
                            if (l_Despair && l_Despair->IsAlive() && !l_Despair->IsInCombat())
                                DoZoneInCombat(l_Despair);
                        }

                        break;
                    }
                }
            }

            void JustDied(Unit* who) override
            {
                events.Reset();

                if (me->GetEntry() == Adds::NPC_EMBODIED_DESPAIR && IsHeroic())
                {
                    std::list<Creature*> l_Despairs;
                    GetOtherEmbodiedDespairs(l_Despairs);

                    for (auto l_Despair : l_Despairs)
                    {
                        if (l_Despair && l_Despair->IsAlive())
                        {
                            l_Despair->AttackStop();
                            l_Despair->StopMoving();
                            l_Despair->CastSpell(l_Despair, Spells::SPELL_ULTIMATE_DESPAIR);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EMBODIED_DOUBT:
                            DoCast(me, SPELL_EMBODIED_DOUBT);
                            events.ScheduleEvent(EVENT_EMBODIED_DOUBT, urand(TIMER_EMBODIED_DOUBT_MIN, TIMER_EMBODIED_DOUBT_MAX));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            void GetOtherEmbodiedDespairs(std::list<Creature*>& l_Despairs)
            {
                /*me->GetCreatureListWithEntryInGrid(l_Despairs, Adds::NPC_EMBODIED_DESPAIR, 30.f, [&](Unit const* l_Unit) -> bool
                {
                    return l_Unit != me;
                });*/
                me->GetCreatureListWithEntryInGrid(l_Despairs, Adds::NPC_EMBODIED_DESPAIR, 30.0f);
                for (Creature* creature : l_Despairs)
                    if (creature = me)
                        l_Despairs.remove(me);
            }

        private:

            uint32 m_ConsumedAuraId;
        };
};

class npc_garrosh_hellscream_minion_of_yshaarj : public CreatureScript
{
    public:
        npc_garrosh_hellscream_minion_of_yshaarj() : CreatureScript("npc_garrosh_hellscream_minion_of_yshaarj") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_minion_of_yshaarjAI(creature);
        }

        struct npc_garrosh_hellscream_minion_of_yshaarjAI : public ScriptedAI
        {
            npc_garrosh_hellscream_minion_of_yshaarjAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                InitializePowers();

                DoCast(me, SPELL_EMPOWERED, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                MeleeDamage();
            }

        private:

            void InitializePowers()
            {
                me->AddAura(SPELL_ZERO_ENERGY, me);

                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                me->SetPower(POWER_ENERGY, 0);
            }

            void IncreaseEnergy()
            {
                if (!IsHeroic())
                    return;

                const int32 addEnergy = 10;

                me->ModifyPower(POWER_ENERGY, addEnergy);

                if (me->GetPower(POWER_ENERGY) >= 100)
                {
                    uint32 spellId = sSpellMgr->GetSpellInfo(SPELL_EMPOWERED)->GetEffect(EFFECT_0)->TriggerSpell;
                    DoCastAOE(spellId, true);
                    me->SetPower(POWER_ENERGY, 0);
                }
            }

            void MeleeDamage()
            {
                Unit* victim = me->GetVictim();
                if (!victim)
                    return;

                if (me->isAttackReady() && me->IsWithinMeleeRange(victim))
                {
                    me->AttackerStateUpdate(victim);
                    me->resetAttackTimer();

                    IncreaseEnergy();
                }
            }
        };
};

class npc_garrosh_hellscream_manifestation_of_rage : public CreatureScript
{
    public:
        npc_garrosh_hellscream_manifestation_of_rage() : CreatureScript("npc_garrosh_hellscream_manifestation_of_rage") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_manifestation_of_rageAI(creature);
        }

        struct npc_garrosh_hellscream_manifestation_of_rageAI : public ScriptedAI
        {
            npc_garrosh_hellscream_manifestation_of_rageAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);
            }
        };
};

class npc_garrosh_hellscream_gunship_cannon : public CreatureScript
{
    public:
        npc_garrosh_hellscream_gunship_cannon() : CreatureScript("npc_garrosh_hellscream_gunship_cannon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_gunship_cannonAI(creature);
        }

        struct npc_garrosh_hellscream_gunship_cannonAI : public ScriptedAI
        {
            npc_garrosh_hellscream_gunship_cannonAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisableGravity(true);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }
        };
};

class npc_garrosh_hellscream_iron_star : public CreatureScript
{
    public:
        npc_garrosh_hellscream_iron_star() : CreatureScript("npc_garrosh_hellscream_iron_star") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_hellscream_iron_starAI(creature);
        }

        struct npc_garrosh_hellscream_iron_starAI : public ScriptedAI
        {
            npc_garrosh_hellscream_iron_starAI(Creature* creature) : ScriptedAI(creature),
                m_IsMoving(false), m_MovingTimer(TIMER_IRON_STAR_FIXATE_FIRST), m_IsExploded(false), m_ExplodeCheckTimer(500)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset() override
            {
                me->AddAura(SPELL_UNSTABLE_IRON_STAR_AURA, me);
            }

            void IsSummonedBy(Unit* p_Owner) override
            {
                // Set in combat to enable SelectTarget
                if (Creature* l_Garrosh = GetGarrosh(me))
                {
                    if (l_Garrosh->IsInCombat())
                        DoZoneInCombat();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                UpdateMoving(diff);
                UpdateExplode(diff);
            }

        private:

            void UpdateMoving(const uint32 diff)
            {
                if (m_IsExploded)
                    return;

                if (m_MovingTimer <= diff)
                {
                    m_MovingTimer = TIMER_IRON_STAR_FIXATE;

                    m_IsMoving = true;

                    if (Unit* nextTarget = GetNextTarget())
                    {
                        ApplyFixate(nextTarget);
                        FollowTarget(nextTarget);
                    }
                }
                else
                {
                    m_MovingTimer -= diff;
                }
            }

            void UpdateExplode(const uint32 diff)
            {
                if (!m_IsMoving || m_IsExploded)
                    return;

                if (m_ExplodeCheckTimer <= diff)
                {
                    m_ExplodeCheckTimer = 500;

                    if (me->SelectNearestPlayer(5.0f) != nullptr)
                    {
                        DoExplode(false);
                        return;
                    }

                    if (Creature* pGarrosh = GetGarrosh(me))
                    {
                        if (pGarrosh->GetDistance(me) <= 5.f)
                        {
                            DoExplode(true);
                            return;
                        }
                    }
                }
                else
                {
                    m_ExplodeCheckTimer -= diff;
                }
            }

            Unit* GetNextTarget()
            {
                return SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true);
            }

            void ApplyFixate(Unit* target)
            {
                DoCast(target, SPELL_FIXATE);
                me->ClearUnitState(UNIT_STATE_CASTING);
            }

            void FollowTarget(Unit* target)
            {
                me->StopMoving();
                me->GetMotionMaster()->MovementExpired(false);
                me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
            }

            void DoExplode(bool withGarrosh)
            {
                m_IsExploded = true;

                me->StopMoving();
                me->GetMotionMaster()->MovementExpired(false);

                DoCastAOE(SPELL_UNSTABLE_IRON_STAR_DMG, true);

                if (withGarrosh)
                    DoCast(me, SPELL_UNSTABLE_IRON_STAR_STUN, true);

                me->Kill(me);
                me->DespawnOrUnsummon(500);
            }

        private:

            bool m_IsMoving;
            bool m_IsExploded;
            uint32 m_MovingTimer;
            uint32 m_ExplodeCheckTimer;
        };
};

class spell_garrosh_hellscream_attack_thrall : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_attack_thrall() : SpellScriptLoader("spell_garrosh_hellscream_attack_thrall") { }

        class spell_garrosh_hellscream_attack_thrall_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_attack_thrall_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* target = GetHitUnit();
                if (!target)
                    return;

                // Need to correct knockback destination
                Movement::MoveSplineInit init(target);
                init.MoveTo(thrallKnockBackPos.GetPositionX(), thrallKnockBackPos.GetPositionY(), thrallKnockBackPos.GetPositionZ(), false);
                init.SetParabolic(10.f,0);
                init.SetOrientationFixed(true);
                init.SetVelocity(40.f);
                init.Launch();
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_attack_thrall_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_attack_thrall_SpellScript();
        }
};

class spell_garrosh_hellscream_desecrate_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_desecrate_aoe() : SpellScriptLoader("spell_garrosh_hellscream_desecrate_aoe") { }

        class spell_garrosh_hellscream_desecrate_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_desecrate_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer();
                });

                std::list<WorldObject*> rangeTargets;

                for (auto target : targets)
                {
                    if (GetCaster()->GetDistance(target) >= 15.0f)
                    {
                        rangeTargets.push_back(target);
                    }
                }

                WorldObject* target = NULL;

                if (!rangeTargets.empty())
                {
                    target = Trinity::Containers::SelectRandomContainerElement(rangeTargets);
                }
                else if (!targets.empty())
                {
                    target = Trinity::Containers::SelectRandomContainerElement(targets);
                }

                targets.clear();

                if (target)
                {
                    targets.push_back(target);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetCaster()->HasAura(SPELL_EMPOWERED_DESECRATE_AURA))
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_EMPOWERED_DESECRATE_MISSILE, true);
                }
                else
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DESECRATE_MISSILE, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_desecrate_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_desecrate_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_desecrate_aoe_SpellScript();
        }
};

class spell_garrosh_hellscream_ancestral_fury : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_ancestral_fury() : SpellScriptLoader("spell_garrosh_hellscream_ancestral_fury") { }

        class spell_garrosh_hellscream_ancestral_fury_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_ancestral_fury_AuraScript);

            bool HandleCheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetSpellInfo()->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
                    return true;

                return false;
            }

            void Register()
            {
                DoCheckProc += AuraCheckProcFn(spell_garrosh_hellscream_ancestral_fury_AuraScript::HandleCheckProc);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_ancestral_fury_AuraScript();
        }
};

class spell_garrosh_hellscream_power_iron_star : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_power_iron_star() : SpellScriptLoader("spell_garrosh_hellscream_power_iron_star") { }

        class spell_garrosh_hellscream_power_iron_star_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_power_iron_star_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Creature* pCreature = GetUnitOwner()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_POWER_IRON_STAR);
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_garrosh_hellscream_power_iron_star_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_power_iron_star_AuraScript();
        }
};

class spell_garrosh_hellscream_power_exploding_iron_star : public SpellScriptLoader
{
    public:

        spell_garrosh_hellscream_power_exploding_iron_star() : SpellScriptLoader("spell_garrosh_hellscream_power_exploding_iron_star") { }

        class spell_garrosh_hellscream_power_exploding_iron_star_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_power_exploding_iron_star_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                int32 const minDamage = GetEffectValue() / 5;
                SetHitDamage(int32(minDamage + ((GetEffectValue() - minDamage) / std::max(GetHitUnit()->GetDistance2d(GetCaster()), 1.0f))));
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_power_exploding_iron_star_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_power_exploding_iron_star_SpellScript();
        }
};

class spell_garrosh_hellscream_teleport_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_teleport_aoe(const char* scriptName, uint32 teleportSpellId) : SpellScriptLoader(scriptName), m_TeleportSpellId(teleportSpellId) { }

        class spell_garrosh_hellscream_teleport_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_teleport_aoe_SpellScript);

        public:

            spell_garrosh_hellscream_teleport_aoe_SpellScript(uint32 teleportSpellId) : m_TeleportSpellId(teleportSpellId)
            {

            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetHitUnit(), m_TeleportSpellId, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_teleport_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:

            uint32 m_TeleportSpellId;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_teleport_aoe_SpellScript(m_TeleportSpellId);
        }

    private:

        uint32 m_TeleportSpellId;
};

class spell_garrosh_hellscream_annihilation : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_annihilation() : SpellScriptLoader("spell_garrosh_hellscream_annihilation") { }

        class spell_garrosh_hellscream_annihilation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_annihilation_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsPlayer() || !GetCaster()->isInFront(obj, float(M_PI) / 4.5f);
                });
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_annihilation_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_annihilation_SpellScript();
        }
};

/*class spell_garrosh_hellscream_garrosh_energy : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_garrosh_energy() : SpellScriptLoader("spell_garrosh_hellscream_garrosh_energy") { }

        class spell_garrosh_hellscream_garrosh_energy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_garrosh_energy_AuraScript);

            void OnUpdate(uint32 diff)
            {
                if (m_UpdateTimer <= diff)
                {
                    ///< TODO: HACK, remove someday
                    if (Unit* owner = GetUnitOwner())
                        if (InstanceScript* instance = owner->GetInstanceScript())
                            owner->SetPower(POWER_ALTERNATE_POWER, instance->GetData(DATA_GARROSH_HELLSCREAM_ENERGY));

                    m_UpdateTimer = 1000;
                }
                else
                    m_UpdateTimer -= diff;
            }

            void Register()
            {
                OnEffectUpdate += AuraEffectUpdateFn(spell_garrosh_hellscream_garrosh_energy_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER);
            }

            uint32 m_UpdateTimer = 1000;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_garrosh_energy_AuraScript();
        }
};*/

class spell_garrosh_hellscream_consumed_hope : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_consumed_hope() : SpellScriptLoader("spell_garrosh_hellscream_consumed_hope") { }

        class spell_garrosh_hellscream_consumed_hope_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_consumed_hope_AuraScript);

            // This aura has dummy auraeffect only instead of proc_trigger_spell like other 'consumed' spells.
            // Handle proc here.
            void OnProc(AuraEffect const* p_AurEff, ProcEventInfo& p_EventInfo)
            {
                PreventDefaultAction();

                if (!GetUnitOwner())
                    return;

                for (uint8 i = 0; i < 5; ++i)
                {
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_HOPE_MISSILE, true);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_garrosh_hellscream_consumed_hope_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_garrosh_hellscream_consumed_hope_AuraScript();
        }
};

class spell_garrosh_hellscream_whirling_corruption_dmg : public SpellScriptLoader
{
    public:

        spell_garrosh_hellscream_whirling_corruption_dmg() : SpellScriptLoader("spell_garrosh_hellscream_whirling_corruption_dmg") { }

        class spell_garrosh_hellscream_whirling_corruption_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_whirling_corruption_dmg_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float dist = GetCaster()->GetDistance(GetHitUnit());

                if (dist > WHIRLING_CORRUPTION_MIN_DAMAGE_RANGE)
                    dist = WHIRLING_CORRUPTION_MIN_DAMAGE_RANGE;
                else if (dist < 1.0f)
                    dist = 1.0f;

                int32 minDamage = GetHitDamage() / 4;

                int32 reduceDamage = dist * ((GetHitDamage() - minDamage) / WHIRLING_CORRUPTION_MIN_DAMAGE_RANGE);
                int32 damage = GetHitDamage() - reduceDamage;
                if (damage < minDamage)
                    damage = minDamage;

                SetHitDamage(damage);
            }

            void HandleOnCast()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_WHIRLING_CORRUPTION_ADDITIONAL_MISSILE, true); ///< Visual
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_garrosh_hellscream_whirling_corruption_dmg_SpellScript::HandleOnCast);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_whirling_corruption_dmg_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_whirling_corruption_dmg_SpellScript();
        }
};

class spell_garrosh_hellscream_empowered_whirling_corruption: public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_empowered_whirling_corruption() : SpellScriptLoader("spell_garrosh_hellscream_empowered_whirling_corruption") { }

        class spell_garrosh_hellscream_empowered_whirling_corruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_empowered_whirling_corruption_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                // The auraeffect has periodic 500 msec
                // It's too fast
                if (aurEff->GetTickNumber() % 3 == 1)
                    SendMissile();
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_garrosh_hellscream_empowered_whirling_corruption_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

        private:

            void SendMissile()
            {
                if (Creature* pGarrosh = GetUnitOwner()->ToCreature())
                {
                    if (Unit* target = pGarrosh->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    {
                        pGarrosh->CastSpell(target, SPELL_EMPOWERED_WHIRLING_CORRUPTION_MISSILE, true);
                    }
                }
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_empowered_whirling_corruption_AuraScript();
        }
};

struct TouchOfYshaarjTargetSelector : public std::unary_function<Unit*, bool>
{
    const Unit* me;

    TouchOfYshaarjTargetSelector(Unit const* unit) : me(unit) {}

    bool operator()(Unit const* target) const
    {
        if (!target)
            return false;

        if (!target->IsPlayer())
            return false;

        if (me->GetVictim() && me->GetVictim()->GetGUID() == target->GetGUID())
            return false;

        if (target->ToPlayer()->GetRoleForGroup() == Roles::ROLE_TANK)
            return false;

        //if (target->HasAura(SPELL_TOUCH_OF_YSHAARJ_SINGLE) ||
        //    target->HasAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE) ||
        //    target->HasAura(SPELL_TOUCH_OF_YSHAARJ_AOE) ||
        //    target->HasAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE))
        //    return false;

        if (target->IsCharmed())
            return false;

        return true;
    }
};

class spell_garrosh_hellscream_touch_of_yshaarj : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_touch_of_yshaarj() : SpellScriptLoader("spell_garrosh_hellscream_touch_of_yshaarj") { }

        class spell_garrosh_hellscream_touch_of_yshaarj_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_touch_of_yshaarj_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                // Recalculate targets
                targets.clear();

                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    uint8 targetsCount = pCreature->GetMap()->Is25ManRaid() ? 4 : 2;
                    std::list<Unit*> newTargets;
                    pCreature->AI()->SelectTargetList(newTargets, TouchOfYshaarjTargetSelector(pCreature), targetsCount, SELECT_TARGET_RANDOM);

                    for (auto target : newTargets)
                        targets.push_back(target);

                    Trinity::Containers::RandomResize(targets, targetsCount);
                }
            }

            void Register()
            {
                if (m_scriptSpellId == SPELL_TOUCH_OF_YSHAARJ_AOE || m_scriptSpellId == SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE)
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_touch_of_yshaarj_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                }
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_touch_of_yshaarj_SpellScript();
        }

        class spell_garrosh_hellscream_touch_of_yshaarj_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript);

            bool Load() override
            {
                //m_UpdateTimer = 500;
                m_TouchTimer = 5000;
                m_OldFlag = false;

                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                amount = -1;
            }

            void OnAbsorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                if (!GetTarget())
                    return;

                if (!dmgInfo.GetAttacker())
                    return;

                if (!dmgInfo.GetAttacker()->IsCharmedOwnedByPlayerOrPlayer())
                    return;

                const int32 minHealth = 10000;

                if (GetTarget()->GetHealth() <= dmgInfo.GetDamage())
                {
                    absorbAmount = dmgInfo.GetDamage() - GetTarget()->GetHealth() + minHealth;
                }
                else if (GetTarget()->GetHealth() <= minHealth)
                {
                    absorbAmount = dmgInfo.GetDamage();
                }
                else if ((GetTarget()->GetHealth() - dmgInfo.GetDamage()) <= minHealth)
                {
                    absorbAmount = dmgInfo.GetDamage() - (GetTarget()->GetHealth() - minHealth);
                }
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                m_OldFlag = GetUnitOwner()->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);

                GetUnitOwner()->RemoveUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);

                GetUnitOwner()->SetUnitFlags(UNIT_FLAG_PACIFIED);
                GetUnitOwner()->AttackStop();
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                if (m_OldFlag)
                    GetUnitOwner()->SetUnitFlags(UNIT_FLAG_PVP_ATTACKABLE);

                GetUnitOwner()->RemoveUnitFlag(UNIT_FLAG_PACIFIED);
            }

            /*void OnUpdate(uint32 diff, AuraEffect* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                if (RemoveAura(diff))
                    return;

                CastOnPlayers(diff);
            }*/

            bool RemoveAura(const uint32 diff)
            {
                if (m_UpdateTimer <= diff)
                {
                    m_UpdateTimer = 500;

                    if (GetUnitOwner()->GetHealthPct() <= 20.f)
                    {
                        Remove();
                        return true;
                    }
                }
                else
                {
                    m_UpdateTimer -= diff;
                }

                return false;
            }

            void CastOnPlayers(const uint32 diff)
            {
                if (m_TouchTimer <= diff)
                {
                    Unit* owner = GetUnitOwner();

                    if (owner->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, GetUnitOwner(), 20.0f);

                    playerList.remove_if([owner](Player* player) -> bool
                    {
                        return (player == owner) || player->IsCharmed() || player->GetRoleForGroup() == Roles::ROLE_TANK;
                    });

                    if (!playerList.empty())
                    {
                        if (Unit* target = playerList.front())
                        {
                            owner->CastSpell(target, SPELL_TOUCH_OF_YSHAARJ_SCRIPT_PLAYER, false);
                            m_TouchTimer = 200;
                        }
                    }
                    else
                    {
                        m_TouchTimer = 1000;
                    }
                }
                else
                {
                    m_TouchTimer -= diff;
                }
            }

            void SetData(uint32 type, uint32 data) /*override*/
            {
                if (type == DATA_TOUCH_SUCCESSFUL)
                {
                    m_TouchTimer = 5000;
                }
            }

            void Register()
            {
                if (m_scriptSpellId == SPELL_TOUCH_OF_YSHAARJ_SINGLE || m_scriptSpellId == SPELL_TOUCH_OF_YSHAARJ_AOE)
                {
                    OnEffectApply += AuraEffectApplyFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::HandleApply, EFFECT_3, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
                    OnEffectRemove += AuraEffectApplyFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::HandleRemove, EFFECT_3, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
                }
                else if (m_scriptSpellId == SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE || m_scriptSpellId == SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE)
                {
                    OnEffectApply += AuraEffectApplyFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::HandleApply, EFFECT_4, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
                    OnEffectRemove += AuraEffectApplyFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::HandleRemove, EFFECT_4, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
                }

                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::OnAbsorb, EFFECT_0);
                //OnEffectUpdate += AuraEffectUpdateFn(spell_garrosh_hellscream_touch_of_yshaarj_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }

        private:

            uint32 m_UpdateTimer;
            uint32 m_TouchTimer;;
            bool m_OldFlag;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_touch_of_yshaarj_AuraScript();
        }
};

class spell_garrosh_hellscream_touch_of_yshaarj_player : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_touch_of_yshaarj_player() : SpellScriptLoader("spell_garrosh_hellscream_touch_of_yshaarj_player") { }

        class spell_garrosh_hellscream_touch_of_yshaarj_player_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_touch_of_yshaarj_player_SpellScript);

            void HandleHit()
            {
                if (!GetCaster() || !GetHitPlayer())
                    return;

                if (Creature* pGarrosh = GetGarrosh(GetCaster()))
                {
                    if (pGarrosh->HasAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AURA))
                    {
                        pGarrosh->AddAura(SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE, GetHitPlayer());
                    }
                    else
                    {
                        pGarrosh->AddAura(SPELL_TOUCH_OF_YSHAARJ_SINGLE, GetHitPlayer());
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_garrosh_hellscream_touch_of_yshaarj_player_SpellScript::HandleHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_touch_of_yshaarj_player_SpellScript();
        }
};

class spell_garrosh_hellscream_empowered_gripping_despair : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_empowered_gripping_despair() : SpellScriptLoader("spell_garrosh_hellscream_empowered_gripping_despair") { }

        class spell_garrosh_hellscream_empowered_gripping_despair_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_empowered_gripping_despair_AuraScript);

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                int32 damage = aurEff->GetAmount();

                GetUnitOwner()->CastCustomSpell(GetUnitOwner(), SPELL_EXPLOSIVE_DESPAIR_DMG, &damage, NULL, NULL, true);
                GetUnitOwner()->CastCustomSpell(SPELL_EXPLOSIVE_DESPAIR_DEBUFF, SpellValueMod::SPELLVALUE_AURA_STACK, GetStackAmount(), GetUnitOwner(), true);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_garrosh_hellscream_empowered_gripping_despair_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_empowered_gripping_despair_AuraScript();
        }
};

class spell_garrosh_hellscream_crushing_fear_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_crushing_fear_aoe() : SpellScriptLoader("spell_garrosh_hellscream_crushing_fear_aoe") { }

        class spell_garrosh_hellscream_crushing_fear_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_crushing_fear_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_CRUSHING_FEAR_MISSILE, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_crushing_fear_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_crushing_fear_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_crushing_fear_aoe_SpellScript();
        }
};

class spell_garrosh_hellscream_manifest_rage: public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_manifest_rage() : SpellScriptLoader("spell_garrosh_hellscream_manifest_rage") { }

        class spell_garrosh_hellscream_manifest_rage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_manifest_rage_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                SendMissile(GetUnitOwner());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_garrosh_hellscream_manifest_rage_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:

            void SendMissile(Unit* caster)
            {
                float dist = frand(10.f, 30.f);
                float angle = frand(0.f, 2 * float(M_PI));
                float posX = caster->GetPositionX() + dist * std::cos(angle);
                float posY = caster->GetPositionY() + dist * std::sin(angle);
                float posZ = caster->GetPositionZ();

                caster->CastSpell(posX, posY, posZ, SPELL_MANIFESTATION_OF_RAGE_MISSILE, true);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_manifest_rage_AuraScript();
        }
};

class spell_garrosh_hellscream_malice : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_malice() : SpellScriptLoader("spell_garrosh_hellscream_malice") { }

        class spell_garrosh_hellscream_malice_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_malice_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    targets.remove(pCreature->GetVictim());

                    if (targets.empty())
                    {
                        if (Unit* target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            targets.push_back(target);
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_malice_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_malice_SpellScript();
        }
};

class spell_garrosh_hellscream_malice_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_malice_aoe() : SpellScriptLoader("spell_garrosh_hellscream_malice_aoe") { }

        class spell_garrosh_hellscream_malice_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_malice_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                m_TargetsCount = targets.size();
            }

            void HandleAfterCast()
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                int32 l_TargetsNeeded = l_Caster->GetMap()->Is25ManRaid() ? MALICE_TARGETS_COUNT_25 : MALICE_TARGETS_COUNT_10;
                if (m_TargetsCount < l_TargetsNeeded)
                {
                    int32 l_Difference = l_TargetsNeeded - m_TargetsCount;
                    for (int32 l_I = 0; l_I < l_Difference; ++l_I)
                        l_Caster->CastSpell(l_Caster, Spells::SPELL_MALICIOUS_ENERGY, true);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                if (Creature* l_Garrosh = GetGarrosh(l_Caster))
                    l_Garrosh->CastSpell(l_Target, Spells::SPELL_MALICIOUS_BLAST, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_malice_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                AfterCast += SpellCastFn(spell_garrosh_hellscream_malice_aoe_SpellScript::HandleAfterCast);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_malice_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            int32 m_TargetsCount;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_malice_aoe_SpellScript();
        }
};

// check forcecast
/*class spell_garrosh_hellscream_malicious_energy : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_malicious_energy() : SpellScriptLoader("spell_garrosh_hellscream_malicious_energy") { }

        class spell_garrosh_hellscream_malicious_energy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_malicious_energy_SpellScript);

            void HandleForceCast(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Caster || !l_Target)
                    return;

                int32 l_Difference = GetSpellValue()->EffectBasePoints[2]; //GetSpell()->GetSpellValue(SpellValueMod::SPELLVALUE_BASE_POINT2);
                if (l_Difference > 1)
                {
                    PreventHitDefaultEffect(effIndex);

                    l_Target->CastCustomSpell(Spells::SPELL_MALICIOUS_ENERGY_EXPLOSION, SpellValueMod::SPELLVALUE_BASE_POINT2, l_Difference, l_Target, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_malicious_energy_SpellScript::HandleForceCast, SpellEffIndex::EFFECT_1, SpellEffects::SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_malicious_energy_SpellScript();
        }
};*/

class spell_garrosh_hellscream_malicious_energy_explosion : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_malicious_energy_explosion() : SpellScriptLoader("spell_garrosh_hellscream_malicious_energy_explosion") { }

        class spell_garrosh_hellscream_malicious_energy_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_malicious_energy_explosion_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                int32 l_Difference = GetSpellValue()->EffectBasePoints[2];//GetSpellValue(SpellValueMod::SPELLVALUE_BASE_POINT2);
                if (l_Difference > 1)
                {
                    SetHitDamage(GetHitDamage() * l_Difference);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_malicious_energy_explosion_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_malicious_energy_explosion_SpellScript();
        }
};

class spell_garrosh_hellscream_call_bombardment: public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_call_bombardment() : SpellScriptLoader("spell_garrosh_hellscream_call_bombardment") { }

        class spell_garrosh_hellscream_call_bombardment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_garrosh_hellscream_call_bombardment_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                // Prevent default Clump Check.
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                // TODO:
                // Create clump check manually.
                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->DoAction(ACTION_CLUMP_CHECK);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_garrosh_hellscream_call_bombardment_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_garrosh_hellscream_call_bombardment_AuraScript();
        }
};

class spell_garrosh_hellscream_bombardment_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_bombardment_aoe() : SpellScriptLoader("spell_garrosh_hellscream_bombardment_aoe") { }

        class spell_garrosh_hellscream_bombardment_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_bombardment_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_BOMBARDMENT_MISSILE, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_bombardment_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_bombardment_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_bombardment_aoe_SpellScript();
        }
};

class spell_garrosh_hellscream_fire_iron_star_aoe : public SpellScriptLoader
{
    public:
        spell_garrosh_hellscream_fire_iron_star_aoe() : SpellScriptLoader("spell_garrosh_hellscream_fire_iron_star_aoe") { }

        class spell_garrosh_hellscream_fire_iron_star_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_garrosh_hellscream_fire_iron_star_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return obj->GetEntry() != NPC_GUNSHIP_MAIN_CANNON;
                });

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_FIRE_UNSTABLE_IRON_STAR_MISSILE, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garrosh_hellscream_fire_iron_star_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_garrosh_hellscream_fire_iron_star_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_garrosh_hellscream_fire_iron_star_aoe_SpellScript();
        }
};

template<uint32 SpellId>
struct spell_area_garrosh_hellscream_embodied_aura : AreaTriggerAI
{
    spell_area_garrosh_hellscream_embodied_aura(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        if (at->GetDuration() > 0 && !target->HasAura(SpellId))
        {
            target->CastSpell(target, SpellId, true);
            at->SetDuration(0);
        }
    }
};

struct spell_area_garrosh_hellscream_desecrated : AreaTriggerAI
{
    spell_area_garrosh_hellscream_desecrated(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        if (!at->GetCaster())
            return;

        at->GetCaster()->AddAura(at->GetCaster()->GetEntry() == NPC_EMPOWERED_DESECRATED_WEAPON ? SPELL_DESECRATED_DMG_2 : SPELL_DESECRATED_DMG, target);
    }

    void OnUnitExit(Unit* target)
    {
        if (!at->GetCaster())
            return;

        target->RemoveAura(at->GetCaster()->GetEntry() == NPC_EMPOWERED_DESECRATED_WEAPON ? SPELL_DESECRATED_DMG_2 : SPELL_DESECRATED_DMG);

        return;
    }
};

struct spell_area_garrosh_hellscream_bombardment : AreaTriggerAI
{
    spell_area_garrosh_hellscream_bombardment(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        if (!at->GetCaster())
            return;

        if (!target->isTargetableForAttack())
            return;

        at->GetCaster()->AddAura(SPELL_NAPALM, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_NAPALM);
    }
};

class achievement_garrosh_hellscream_strike : public AchievementCriteriaScript
{
    public:
        achievement_garrosh_hellscream_strike() : AchievementCriteriaScript("achievement_garrosh_hellscream_strike") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Creature* pGarrosh = GetGarrosh(source))
            {
                if (pGarrosh->AI()->GetData(DATA_IRON_STAR_CREATURES) >= 18)
                    return true;
            }

            return false;
        }
};

class at_garrosh_hellscream_intro : public AreaTriggerScript
{
    public:

        at_garrosh_hellscream_intro()
            : AreaTriggerScript("at_garrosh_hellscream_intro")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                SendIntro(player);
            }

            return true;
        }

    private:

        void SendIntro(WorldObject* searcher)
        {
            if (InstanceScript* pInstance = searcher->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_GARROSH_HELLSCREAM) != DONE &&
                    pInstance->GetData(DATA_GARROSH_HELLSCREAM_INTRO) != DONE)
                {
                    pInstance->SetData(DATA_GARROSH_HELLSCREAM_INTRO, DONE);
                }
            }
        }
};

void AddSC_boss_garrosh_hellscream()
{
    new boss_garrosh_hellscream();                      // 71865
    new npc_garrosh_hellscream_thrall();                // 73483
    new npc_garrosh_hellscream_heart_of_yshaarj();      // 72215
    new npc_garrosh_hellscream_heart_of_yshaarj_2();    // 72228
    new npc_garrosh_hellscream_desecrated_weapon();     // 72154 72198
    new npc_garrosh_hellscream_korkron_warbringer();    // 71979
    new npc_garrosh_hellscream_farseer_wolf_rider();    // 71983
    new npc_garrosh_hellscream_siege_engineer();        // 71984
    new npc_garrosh_hellscream_korkron_iron_star();     // 71985
    new npc_garrosh_hellscream_embodied();              // 72237
    new npc_garrosh_hellscream_minion_of_yshaarj();     // 72272
    new npc_garrosh_hellscream_manifestation_of_rage(); // 73253
    new npc_garrosh_hellscream_gunship_cannon();        // 73262 73258
    new npc_garrosh_hellscream_iron_star();             // 73059

    new spell_garrosh_hellscream_attack_thrall();       // 147831
    new spell_garrosh_hellscream_desecrate_aoe();       // 144745
    new spell_garrosh_hellscream_ancestral_fury();      // 144585
    new spell_garrosh_hellscream_power_iron_star();     // 144616
    new spell_garrosh_hellscream_power_exploding_iron_star();   // 144798
    new spell_garrosh_hellscream_teleport_aoe("spell_garrosh_hellscream_teleport_red_crane_aoe", SPELL_TELEPORT_RED_CRANE); // 144880
    new spell_garrosh_hellscream_teleport_aoe("spell_garrosh_hellscream_teleport_jade_serpent_aoe", SPELL_TELEPORT_JADE_SERPENT); // 144883
    new spell_garrosh_hellscream_teleport_aoe("spell_garrosh_hellscream_teleport_terrace_aoe", SPELL_TELEPORT_TERRACE); // 144885
    new spell_garrosh_hellscream_annihilation();        // 144969
    //new spell_garrosh_hellscream_garrosh_energy();      // 145801
    new spell_garrosh_hellscream_consumed_hope();       // 149032
    new spell_garrosh_hellscream_whirling_corruption_dmg(); // 144989
    new spell_garrosh_hellscream_empowered_whirling_corruption();   // 145037
    new spell_garrosh_hellscream_touch_of_yshaarj();    // 145065 145071 145171 145175
    new spell_garrosh_hellscream_touch_of_yshaarj_player(); // 145599
    new spell_garrosh_hellscream_empowered_gripping_despair();  // 145195
    new spell_garrosh_hellscream_crushing_fear_aoe();   // 147325
    new spell_garrosh_hellscream_manifest_rage();       // 147011
    new spell_garrosh_hellscream_malice();              // 147209
    new spell_garrosh_hellscream_malice_aoe();          // 147229
    //new spell_garrosh_hellscream_malicious_energy();    // 147236
    new spell_garrosh_hellscream_malicious_energy_explosion(); // 147733
    new spell_garrosh_hellscream_call_bombardment();    // 147120
    new spell_garrosh_hellscream_bombardment_aoe();     // 147132
    new spell_garrosh_hellscream_fire_iron_star_aoe();  // 147053

    new GenericAreaTriggerEntityScript<spell_area_garrosh_hellscream_embodied_aura<SPELL_HOPE_AURA>>("spell_area_garrosh_hellscream_embodied_aura_hope");    // 149003
    new GenericAreaTriggerEntityScript<spell_area_garrosh_hellscream_embodied_aura<SPELL_FAITH_AURA>>("spell_area_garrosh_hellscream_embodied_aura_faith");    // 148992
    new GenericAreaTriggerEntityScript<spell_area_garrosh_hellscream_embodied_aura<SPELL_COURAGE_AURA>>("spell_area_garrosh_hellscream_embodied_aura_courage");    // 148982

    RegisterAreaTriggerAI(spell_area_garrosh_hellscream_desecrated);     // 144760 144818
    RegisterAreaTriggerAI(spell_area_garrosh_hellscream_bombardment);    // 147135

    new achievement_garrosh_hellscream_strike();    // 23893

    new at_garrosh_hellscream_intro();                  // 9374
}
