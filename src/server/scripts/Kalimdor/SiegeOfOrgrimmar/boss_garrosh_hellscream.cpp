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
#include <set>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SceneHelper.h"

// todo readd update spellscripts

enum ScriptedTexts
{
    SAY_GARROSH_DEATH = 1,
    SAY_GARROSH_DEATH_2 = 2,
    SAY_GARROSH_INTERMISSION = 3,
    SAY_BOMBARDMENT = 4,
    SAY_MANIFEST_RAGE = 5,
    SAY_GARROSH_PHASE_2 = 6,
    SAY_GARROSH_YSHAARJ = 7,
    SAY_GARROSH_PHASE_3 = 8,
    SAY_GARROSH_PHASE_4_1 = 9,
    SAY_GARROSH_PHASE_4_2 = 10,
    SAY_GARROSH_INTRO_1 = 11,
    SAY_GARROSH_INTRO_2 = 12,
    SAY_GARROSH_INTRO_3 = 13,
    SAY_GARROSH_INTRO_4 = 14,
    SAY_GARROSH_INTRO_5 = 15,
    SAY_GARROSH_AGGRO = 16,
    SAY_GARROSH_KILL = 17,
    SAY_GARROSH_WIPE = 18,
    SAY_GARROSH_IRON_STAR = 19,
    SAY_GARROSH_BERSERK = 20,
    SAY_GARROSH_FARSEER = 22,
    SAY_GARROSH_WARSONG = 23,
    SAY_GARROSH_WHIRLING = 24,
    SAY_GARROSH_WHIRLING_2 = 25,

    SAY_THRALL_INTRO_1 = 0,
    SAY_THRALL_INTRO_2 = 1,
    SAY_THRALL_INTRO_3 = 2,

    SAY_HEARTH_OF_YSHAARJ = 0,
};

enum Spells
{
    // Thrall
    // Intro
    SPELL_CALL_OF_THE_ELEMENTS = 147815,
    SPELL_ASTRAL_RECALL = 147811, // 1120.73, -5644.33, -289.902
    SPELL_EXHAUSTED = 147861,
    SPELL_ATTACK_GARROSH = 147892,

    // Garrosh Intro
    SPELL_DEFEND_AGAIST_THRALL = 147899,
    SPELL_ATTACK_THRALL = 147831, // has attribute SPELL_ATTR3_ONLY_TARGET_PLAYERS, remove it

    // Finale
    SPELL_GARROSH_FINALE_HORDE_MOVIE_1 = 147301,
    SPELL_GARROSH_FINALE_HORDE_MOVIE_2 = 149978,
    SPELL_GARROSH_FINALE_HORDE_FADE = 147314,
    SPELL_GARROSH_FINALE_HORDE_REMOVE = 147329,
    SPELL_GARROSH_FINALE_ALLIANCE_MOVIE_1 = 147302,
    SPELL_GARROSH_FINALE_ALLIANCE_MOVIE_2 = 149979,
    SPELL_GARROSH_FINALE_ALLIANCE_FADE = 147332,
    SPELL_GARROSH_FINALE_ALLIANCE_REMOVE = 147331,

    // Garrosh general spells
    SPELL_ZERO_ENERGY = 72242,
    SPELL_ACHIEVEMENT_CHECK = 148305, // in sniffs, casted by adds ?
    SPELL_BERSERK = 26662,

    // First phase
    SPELL_HELLSCREAMS_WARSONG = 144821,
    SPELL_DESECRATE_AOE = 144745, // targetting
    SPELL_DESECRATE_MISSILE = 144748,
    SPELL_DESECRATE_DMG = 144758,
    SPELL_DESECRATED_WEAPON_VISUAL = 144760, // visual area
    SPELL_DESECRATED_WEAPON_2 = 145880, // visual weapon
    SPELL_DESECRATED_DMG = 144762,
    SPELL_SUMMON_ADDS = 144489, // periodic 5000 msecs, in sniffs

    // Second Phase Transition
    SPELL_THROW_AXE_AT_HEART = 145235,
    SPELL_TRANSITION_VISUAL_AURA = 146756, // casted by Garrosh before second phase
    SPELL_PHASE_TWO_TRANSFORM = 144842, // triggered by 144852 (transition visual)

    // Second Phase: Realm of Y'Shaarj
    SPELL_ENTER_REALM_OF_YSHAARJ_SCRIPT_1 = 144866,
    SPELL_ENTER_REALM_OF_YSHAARJ_SCRIPT_2 = 144878,
    SPELL_ENTER_REALM_OF_YSHAARJ_JUMP = 144870, // triggered by 144867, casted by Garrosh
    SPELL_ENTER_REALM_OF_YSHAARJ_JUMP_2 = 144868, // triggered by 144867, casted by players
    SPELL_TELEPORT_RED_CRANE_AOE = 144880, // triggers 144881
    SPELL_TELEPORT_RED_CRANE = 144881, // teleports players to Red Crane Temple
    SPELL_TELEPORT_JADE_SERPENT_AOE = 144883, // triggers 144884
    SPELL_TELEPORT_JADE_SERPENT = 144884, // teleports players to Jade Serpent Temple
    SPELL_TELEPORT_TERRACE_AOE = 144885, // triggers 144886
    SPELL_TELEPORT_TERRACE = 144886, // teleports players to Terrace
    SPELL_REALM_OF_YSHAARJ = 144954, // from the boss to players
    SPELL_REALM_OF_YSHAARJ_SELF = 144958, // on self
    SPELL_REALM_OF_YSHAARJ_REMOVE = 145647, // removes 144954

    SPELL_YSHAARJ_PROTECTION = 144945,
    SPELL_ABSORB_ENERGY = 144946,
    SPELL_GROWING_POWER = 144947,
    SPELL_GARROSH_ENERGY = 145801, // casted on players

    SPELL_JUMP_TO_GROUND = 144956,

    SPELL_BREAK_PLAYER_TARGETTING = 140562,

    // Second phase
    SPELL_ANNIHILATION_FORCE = 144970,
    SPELL_ANNIHILATION_SUMMON = 148203,
    SPELL_ANNIHILATION_DMG = 144969,
    SPELL_WHIRLING_CORRUPTION = 144985,
    SPELL_WHIRLING_CORRUPTION_DMG = 144989,
    SPELL_WHIRLING_CORRUPTION_SCRIPT = 145036, // ?
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_AURA = 145833,
    SPELL_WHIRLING_CORRUPTION_ADDITIONAL_MISSILE = 144994,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION = 145037,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_MISSILE = 145023,
    SPELL_EMPOWERED_WHIRLING_CORRUPTION_DMG = 145033,
    SPELL_TOUCH_OF_YSHAARJ_AOE = 145065, // hit 2 players
    SPELL_TOUCH_OF_YSHAARJ_SINGLE = 145071, // hit 1 player
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT = 145096, // ?
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT_2 = 145163, // ?
    SPELL_TOUCH_OF_YSHAARJ_SCRIPT_PLAYER = 145599, // casted by players on other players
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AURA = 145832,
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_AOE = 145171, // hit 2 players
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_SINGLE = 145175, // hit 1 player
    SPELL_EMPOWERED_TOUCH_OF_YSHAARJ_IMMUNE = 145710,
    SPELL_EMPOWERED_DESECRATE_AURA = 145829,
    SPELL_DESECRATED_DMG_2 = 144817,
    SPELL_POWER_OF_THE_OLD_GOD = 144819, // Triggers periodically 144820 which heals the empower desecrated weapon
    SPELL_POWER_OF_THE_OLD_GOD_HEAL = 144820,
    SPELL_EMPOWERED_DESECRATE_MISSILE = 144749,
    SPELL_EMPOWERED_DESECRATE_DMG = 144816,
    SPELL_EMPOWERED_DESECRATED_WEAPON_VISUAL = 144818, // visual area
    SPELL_GRIPPING_DESPAIR_PERIODIC_DMG = 145183,
    SPELL_GRIPPING_DESPAIR_SCRIPT = 145207, // ?
    SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA = 145831,
    SPELL_EMPOWERED_GRIPPING_DESPAIR_PERIODIC_DMG = 145195,
    SPELL_EMPOWERED_GRIPPING_DESPAIR_DMG = 149252,
    SPELL_EXPLOSIVE_DESPAIR_DEBUFF = 145213,
    SPELL_EXPLOSIVE_DESPAIR_DMG = 145199,
    SPELL_WEAK_MINDED_AOE = 145331, // Lasts 67 secs. It is used on teleportation to realm of yshaarj on players afftected by touch of yshaarj.
    SPELL_WEAK_MINDED = 148440, // Lasts 15 secs, triggered by 146986 (teleport spell).

    // Third phase
    SPELL_TRANSITION_VISUAL_AURA_2 = 146845, // casted by Garrosh before third phase
    SPELL_PHASE_THREE_TRANSFORM = 145246, // triggered by 145222 (transition visual)
    SPELL_PHASE_THREE_TRANSFORM_2 = 145598, // Scale +50%, applies all empowered weapon buffs

    // Fourth Phase
    SPELL_PHASE_THREE_DE_TRANSFORM_PERIODIC = 146966, // triggers 146967 in 6 secs, heroic ?
    SPELL_PHASE_THREE_DE_TRANSFORM = 146967, // removes 145598, heroic ?
    SPELL_PHASE_THREE_DE_TRANSFORM_PERIODIC_2 = 147608, // triggers 146972, lasts 23 secs
    SPELL_PHASE_THREE_DE_TRANSFORM_MISSILE = 146972,
    SPELL_PHASE_FOUR_TRANSFORM = 146987,
    SPELL_ENTER_REALM_OF_GARROSH = 146984, // heroic
    SPELL_ENTER_REALM_OF_GARROSH_JUMP = 146985,  // heroic
    SPELL_REALM_OF_GARROSH_TELEPORT = 149140,

    // Fourth Phase
    SPELL_CALL_GUNSHIP = 147187,
    SPELL_CALL_BOMBARDMENT = 147120,
    SPELL_BOMBARDMENT_FORCE = 147131, // triggered by 147120
    SPELL_BOMBARDMENT_AOE = 147132, // triggered by 147131
    SPELL_BOMBARDMENT_MISSILE = 147133,
    SPELL_BOMBARDMENT_DMG = 147135,
    SPELL_NAPALM = 147136,
    SPELL_CLUMP_CHECK_FORCE = 147126, // triggered by 147120 every 500 msec
    SPELL_CLUMP_CHECK_SUMMON = 147130, // triggered by 147126
    SPELL_FIRE_IRON_STAR = 147053, // casted by Clump (73278)
    SPELL_FIRE_UNSTABLE_IRON_STAR_MISSILE = 147047,
    SPELL_IRON_STAR_CRATER = 147048,
    SPELL_FIXATE = 147665,
    SPELL_UNSTABLE_IRON_STAR_AURA = 147148,
    SPELL_UNSTABLE_IRON_STAR_DMG = 147173, // hits players
    SPELL_UNSTABLE_IRON_STAR_STUN = 147177, // hits Garrosh
    SPELL_UNSTABLE_IRON_STAR_DMG_2 = 147179, // ?
    SPELL_MALICE = 147209,
    SPELL_MALICE_AOE = 147229, // hits ally
    SPELL_MALICIOUS_BLAST = 147235,
    SPELL_MALICIOUS_ENERGY = 147236,
    SPELL_MALICIOUS_ENERGY_EXPLOSION = 147733,
    SPELL_MANIFEST_RAGE = 147011,
    SPELL_MANIFESTATION_OF_RAGE_MISSILE = 147035,
    SPELL_MANIFESTATION_OF_RAGE_SUMMON = 147013,

    // Kor'kron Warbringer
    SPELL_HAMSTRING = 144582,
    SPELL_BLOOD_FRENZY = 147300,

    // Farseer Wolf Rider
    SPELL_ANCESTRAL_CHAIN_HEAL = 144583,
    SPELL_CHAIN_LIGHTNING = 144584,
    SPELL_ANCESTRAL_FURY = 144585,
    SPELL_FURY = 144588,

    // Siege Engineer
    SPELL_POWER_IRON_STAR = 144616,

    // Iron Star
    SPELL_IRON_STAR_IMPACT = 144645,
    SPELL_IRON_STAR_IMPACT_2 = 149468,
    SPELL_IRON_STAR_IMPACT_DMG_1 = 144650, // casted on players
    SPELL_IRON_STAR_IMPACT_DMG_2 = 144653, // casted on creatures
    SPELL_IRON_STAR_IMPACT_DUMMY = 148299, // ?
    SPELL_EXPLODING_IRON_STAR = 144798,

    // Heart of Y'shaarj
    SPELL_TRANSITION_VISUAL = 144852, // for 2 phase
    SPELL_ENTER_THE_REALM_OF_YSHAARJ = 144867,
    SPELL_TRANSITION_VISUAL_2 = 145222, // for 3 phase
    SPELL_HEARTBEAT_SOUND = 148574,
    SPELL_HEARTBEAT_SOUND_2 = 148591,

    // Embodied Despair
    SPELL_CONSUMED_HOPE = 149032,
    SPELL_HOPE_MISSILE = 149002,
    SPELL_HOPE_AREATRIGGER = 149003,
    SPELL_HOPE_AURA = 149004,
    SPELL_ULTIMATE_DESPAIR = 147341,
    SPELL_ULTIMATE_DESPAIR_DMG = 147342,

    // Embodied Doubt
    SPELL_CONSUMED_FAITH = 149033,
    SPELL_FAITH_MISSILE = 148991,
    SPELL_FAITH_AREATRIGGER = 148992,
    SPELL_FAITH_AURA = 148994,
    SPELL_EMBODIED_DOUBT = 149347,

    // Embodied Fear
    SPELL_REDUCE_CRITICAL_STRIKE_CHANCE = 64481, // from sniffs
    SPELL_CONSUMED_COURAGE = 149011,
    SPELL_COURAGE_MISSILE = 148980,
    SPELL_COURAGE_AREATRIGGER = 148982,
    SPELL_COURAGE_AURA = 148983,
    SPELL_CRUSHING_FEAR_PERIODIC = 147327,
    SPELL_CRUSHING_FEAR_AOE = 147325, // triggered by 147327 every 3 secs
    SPELL_CRUSHING_FEAR_MISSILE = 147326,
    SPELL_CRUSHING_FEAR_DMG = 147324,

    // Minion of Y'Shaarj
    SPELL_EMPOWERED = 145050,
};

enum Adds
{
    NPC_HEART_OF_YSHAARJ = 72215, // at the center of the room
    NPC_HEART_OF_YSHAARJ_2 = 72228, // at the red crane, jade serpent and terrace

    NPC_KORKRON_WARBRINGER = 71979,
    NPC_FARSEER_WOLF_RIDER = 71983,
    NPC_DESECRATED_WEAPON = 72154,
    NPC_SIEGE_ENGINEER = 71984,
    NPC_KORKRON_IRON_STAR = 71985,
    NPC_EMBODIED_DESPAIR = 72238,
    NPC_EMBODIED_DOUBT = 72236,
    NPC_EMBODIED_FEAR = 72237,
    NPC_MINION_OF_YSHAARJ = 72272,
    NPC_EMPOWERED_DESECRATED_WEAPON = 72198,
    NPC_CLUMP = 73278,
    NPC_IRON_STAR = 73059,
    NPC_MANIFESTATION_OF_RAGE = 73253,

    NPC_GUNSHIP_SMALL_CANNON = 73262, // I think it's correct entry
    NPC_GUNSHIP_MAIN_CANNON = 73258, // I think it's correct entry
};

enum Events
{
    // Garrosh Hellscream
    EVENT_HELLSCREAMS_WARSONG = 1,
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
    TIMER_BERSERK = 18 * MINUTE * IN_MILLISECONDS,
    TIMER_HELLSCREAMS_WARSONG_FIRST = 22 * IN_MILLISECONDS,
    TIMER_HELLSCREAMS_WARSONG = 43 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_1 = 11 * IN_MILLISECONDS,
    TIMER_DESECRATE_1 = 41 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_2 = 10 * IN_MILLISECONDS,
    TIMER_DESECRATE_2 = 35 * IN_MILLISECONDS,
    TIMER_DESECRATE_FIRST_3 = 21 * IN_MILLISECONDS,
    TIMER_DESECRATE_3 = 25 * IN_MILLISECONDS,
    TIMER_KORKRON_WARBRINGERS_FIRST = 2 * IN_MILLISECONDS,
    TIMER_KORKRON_WARBRINGERS = 40 * IN_MILLISECONDS,
    TIMER_FARSEER_WOLF_RIDER_FIRST = 30 * IN_MILLISECONDS,
    TIMER_FARSEER_WOLF_RIDER = 50 * IN_MILLISECONDS,
    TIMER_SIEGE_ENGINEER_FIRST = 20 * IN_MILLISECONDS,
    TIMER_SIEGE_ENGINEER = 42 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ_FIRST = 16 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ = 146 * IN_MILLISECONDS,
    TIMER_REALM_OF_YSHAARJ_TELEPORT_OUT = 61 * IN_MILLISECONDS,
    TIMER_ANNIHILATION = 3500,
    TIMER_WHIRLING_CORRUPTION_FIRST = 30 * IN_MILLISECONDS,
    TIMER_WHIRLING_CORRUPTION = 50 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ_FIRST_1 = 15 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ_FIRST_2 = 30 * IN_MILLISECONDS,
    TIMER_TOUCH_OF_YSHAARJ = 45 * IN_MILLISECONDS,
    TIMER_BOMBARDMENT_FIRST = 50 * IN_MILLISECONDS, // 70 secs or 50 secs after cinematic (aggro)
    TIMER_BOMBARDMENT = 55 * IN_MILLISECONDS,
    TIMER_MALICE_FIRST = 11 * IN_MILLISECONDS, // 29.5 secs or 11 secs after cinematic (aggro)
    TIMER_MALICE = 29500,

    // Kor'kron Warbringer
    TIMER_HAMSTRING_FIRST_MIN = 10 * IN_MILLISECONDS,
    TIMER_HAMSTRING_FIRST_MAX = 25 * IN_MILLISECONDS,
    TIMER_HAMSTRING_MIN = 15 * IN_MILLISECONDS,
    TIMER_HAMSTRING_MAX = 35 * IN_MILLISECONDS,
    TIMER_RESUME_FIGHT = 5 * IN_MILLISECONDS,

    // Farseer Wolf Rider
    TIMER_ANCESTRAL_CHAIN_HEAL_FIRST = 10 * IN_MILLISECONDS,
    TIMER_ANCESTRAL_CHAIN_HEAL = 25 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING_FIRST = 7 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING = 2500,

    // Embodied Doubt
    TIMER_EMBODIED_DOUBT_MIN = 5 * IN_MILLISECONDS,
    TIMER_EMBODIED_DOUBT_MAX = 7 * IN_MILLISECONDS,

    TIMER_IRON_STAR_FIXATE_FIRST = 2 * IN_MILLISECONDS,
    TIMER_IRON_STAR_FIXATE = 12 * IN_MILLISECONDS,
};

enum Actions
{
    // intro actions
    ACTION_JUMP_INTO_ROOM = 1,
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
    DATA_IRON_STAR_CREATURES = 1, // how many creatures was killed by Iron Star
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
    POINT_ORC = 1,    // The point that warbringers reach on entering combat
    POINT_ORC_CENTER,
    POINT_ENGINEER,
    POINT_IRON_STAR,    // The point that iron stars reach on moving through the room
};

enum IntermissionIndexes : int
{
    INTERMISSION_NONE = -1,   // Intermission initial state
    INTERMISSION_RED_CRANE = 0,    // Intermission phase at the red crane's temple
    INTERMISSION_JADE_SERPENT = 1,    // Intermission phase at the jade serpent's temple
    INTERMISSION_TERRACE = 2,    // Intermission phase at the terrace of the endless spring
    INTERMISSION_COUNT = 3,    // Count of intermission phases
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

void AddSC_boss_garrosh_hellscream()
{
    
}
