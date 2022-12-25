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
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"
#include "Pet.h"

enum ScriptedTexts
{
    SAY_AGGRO = 0,
    SAY_WIPE = 1,
    SAY_WIN = 2,
    SAY_EVENT_6 = 8,
    SAY_EVENT_7 = 9,
};

enum Spells
{
    SPELL_ENTER_QUARANTINE = 145633,
    SPELL_QUARANTINE_SAFETY_MEASURES_1 = 145779,
    SPELL_QUARANTINE_SAFETY_MEASURES_2 = 145773, // triggered by 145779
    SPELL_QUARANTINE_SAFETY_MEASURES_3 = 145776, // triggered by 145773 145779

    SPELL_EXTRACT_CORRUPTION_FORCE = 145139,
    SPELL_EXTRACT_CORRUPTION_DUMMY_1 = 145140, // triggered by 145139
    SPELL_EXTRACT_CORRUPTION = 145143,

    SPELL_CORRUPTION = 144421,

    // Amalgam
    SPELL_UNCHECKED_CORRUPTION = 145679, // if there are no melee target

    SPELL_UNLEASHED_ANGER = 145214,
    SPELL_UNLEASHED_ANGER_DUMMY = 145216, // triggered by 145214
    SPELL_UNLEASHED_ANGER_DMG = 145212,

    SPELL_SELF_DOUBT = 146124,

    SPELL_BLIND_HATRED = 145226, // main beam
    SPELL_BLIND_HATRED_2 = 145613, // another beam ?
    SPELL_BLIND_HATRED_DUMMY = 145571, // some animation, maybe on hit players
    SPELL_BLIND_HATRED_DMG = 145227,
    SPELL_BLIND_HATRED_PERIODIC = 145573, // every 250 ms

    SPELL_FUSION = 145765, // ?
    SPELL_FUSION_AURA = 145132,

    SPELL_ICY_FEAR_PERIODIC = 145733,
    SPELL_ICY_FEAR_DMG = 145735, // requires 145178 target aura (?) seems like quarantine zone mark

    SPELL_FRAYED = 146179,

    SPELL_UNLEASH_CORRUPTION_SUMMON_1 = 145005, // triggered by 144478 (72262 unleashed fragment of corruption)
    SPELL_UNLEASH_CORRUPTION_SUMMON_2 = 145006, // triggered by 144490 145768 (72263 essence of corruption)
    SPELL_UNLEASH_CORRUPTION_SUMMON_3 = 145007, // triggered by 144491 145769 (72264 manifestation of corruption)
    SPELL_UNLEASH_CORRUPTION_MISSILE_1 = 145768, // summons 145006
    SPELL_UNLEASH_CORRUPTION_MISSILE_2 = 145769, // summons 145007

    SPELL_SPAWN_VICTORY_ORB_1 = 144478, // triggers 145005
    SPELL_SPAWN_VICTORY_ORB_2 = 144490, // triggers 145006
    SPELL_SPAWN_VICTORY_ORB_3 = 144491, // triggers 145007
    SPELL_SPAWN_VICTORY_ORB_4 = 145241, // big yellow orb
    SPELL_SPAWN_VICTORY_ORB_5 = 145242, // medium yellow orb
    SPELL_SPAWN_VICTORY_ORB_6 = 145243, // small yellow orb
    SPELL_SPAWN_VICTORY_ORB_7 = 146716, // small yellow orb

    SPELL_LOOK_WITHIN_DUMMY = 144717, // some visual effect, yellow orb
    SPELL_LOOK_WITHIN_1 = 144724, // phase 173
    SPELL_LOOK_WITHIN_2 = 144725, // phase 174
    SPELL_LOOK_WITHIN_3 = 144726, // phase 2439
    SPELL_LOOK_WITHIN_4 = 144727, // phase 2440
    SPELL_LOOK_WITHIN_5 = 146826, // phase 2441
    SPELL_LOOK_WITHIN_6 = 146827, // phase 2510
    SPELL_LOOK_WITHIN_7 = 146828, // phase 2511
    SPELL_LOOK_WITHIN_8 = 146829, // phase 2512
    SPELL_LOOK_WITHIN_9 = 146830, // phase 2513
    SPELL_LOOK_WITHIN_10 = 146831, // phase 2514
    SPELL_LOOK_WITHIN_11 = 146832, // phase 2515
    SPELL_LOOK_WITHIN_12 = 146833, // phase 2516
    SPELL_LOOK_WITHIN_13 = 146834, // phase 2517
    SPELL_LOOK_WITHIN_14 = 146835, // phase 2518
    SPELL_LOOK_WITHIN_15 = 146836, // phase 2519
    SPELL_LOOK_WITHIN_16 = 146837, // phase 2520

    SPELL_TEST_OF_SERENITY = 144849,
    SPELL_TEST_OF_RELIANCE = 144850,
    SPELL_TEST_OF_RELIANCE_DUMMY = 146712, // triggered by 144850
    SPELL_TEST_OF_CONFIDENCE = 144851,

    SPELL_SPAWN_VICTORY_ORB = 144490,

    SPELL_CLEANSE_15 = 144449,
    SPELL_CLEANSE_40 = 144450,
    SPELL_CLEANSE_100 = 147657,

    SPELL_PURIFIED = 144452,
    SPELL_PURIFIED_IMMUNE = 146022,

    SPELL_UNLEASHED_1 = 146173, // casted by minions ?
    SPELL_UNLEASHED_2 = 146174, // casted by minions ?
    SPELL_FOUL_LINK_1 = 148974, // Spell Icon, triggered by 146173 146174, casted by the boss
    SPELL_FOUL_LINK_2 = 149189, // Gray Ray, triggered by 146173 146174

    // Manifestation of Corruption
    SPELL_MANIFESTATION_OF_CORRUPTION_SUMMON = 144739, // player summons it
    SPELL_TEAR_REALITY = 144482, // for testing
    SPELL_BURST_OF_ANGER = 147082, // for all, requires 145178 target aura (?) seems like quarantine zone mark
    SPELL_RESIDUAL_CORRUPTION_AURA = 145074,
    SPELL_RESIDUAL_CORRUPTION_DMG = 145073, // requires 145178 target aura (?) seems like quarantine zone mark
    SPELL_CORRUPT = 145052,

    // Essense of Corruption
    SPELL_ESSENSE_OF_CORRUPTION_SUMMON = 144733, // player summons it
    SPELL_ESSENSE_OF_CORRUPTION = 148452, // for testing, triggers 8279 and 149601
    SPELL_DARK_BULWARK = 149601,
    SPELL_EXPEL_CORRUPTION_1 = 144479, // for testing
    SPELL_EXPELLED_CORRUPTION_1 = 144480, // dmg aura
    SPELL_EXPEL_CORRUPTION_2 = 145064, // for all
    SPELL_EXPELLED_CORRUPTION_2 = 145134, // for all, dmg

    // Greater Corruption
    SPELL_GREATER_CORRUPTION_SUMMON = 144980,
    SPELL_DISHEARTENING_LAUGH = 146707,
    SPELL_LINGERING_CORRUPTION = 144514,
    SPELL_BOTTOMLESS_PIT_AOE_1 = 146701, // targetting
    SPELL_BOTTOMLESS_PIT_AOE_2 = 146705,
    SPELL_BOTTOMLESS_PIT_AREATRIGGER = 146793,
    SPELL_BOTTOMLESS_PIT_DMG = 146703,

    // Titanic Corruption
    SPELL_TITANIC_CORRUPTION_SUMMON = 144848,
    SPELL_BURST_OF_CORRUPTION = 144654,
    SPELL_CORRUPTION_DMG = 144639,
    SPELL_HURL_CORRUPTION = 144649,
    SPELL_PIERCING_CORRUPTION = 144657,
    SPELL_TITANIC_SMASH = 144628,

};

enum Adds
{
    NPC_QUARANTINE_MEASURES = 72669,
    NPC_QUARANTINE_NOVA = 72670,
    NPC_BLIND_HATRED = 72565,
    NPC_PURIFYING_LIGHT = 72065, //73224,

    NPC_MANIFESTATION_OF_CORRUPTION_1 = 71977, // for testing
    NPC_ESSENCE_OF_CORRUPTION_1 = 71976, // for testing
    NPC_MANIFESTATION_OF_CORRUPTION_2 = 72264, // for all players
    NPC_ESSENSE_OF_CORRUPTION_2 = 72263, // for all players
    NPC_RESIDUAL_CORRUPTION = 72550,
    NPC_GREATER_CORRUPTION = 72001,
    NPC_TITANIC_CORRUPTION = 72051,
    NPC_UNLEASHED_FRAGMENT_OF_CORRUPTION = 72262,
};

enum Events
{
    EVENT_BERSERK = 1,

    EVENT_ACTIVATE_AMALGAM,
    EVENT_TELEPORT_TO_EXIT,
    EVENT_NORUSHEN_TALK_1,
    EVENT_NORUSHEN_TALK_2,
    EVENT_NORUSHEN_TALK_3,

    // Amalgam
    EVENT_UNCHECKED_CORRUPTION,
    EVENT_UNLEASHED_ANGER,
    EVENT_SELF_DOUBT,
    EVENT_BLIND_HATRED,
    EVENT_PURIFYING_LIGHT,

    EVENT_MOVE,
    EVENT_TEAR_REALITY,
    EVENT_BURST_OF_ANGER,

    EVENT_EXPEL_CORRUPTION,

    EVENT_DISHEARTENING_LAUGH,
    EVENT_LINGERING_CORRUPTION,
    EVENT_BOTTOMLESS_PIT,

    EVENT_BURST_OF_CORRUPTION,
    EVENT_HURL_CORRUPTION,
    EVENT_PIERCING_CORRUPTION,
    EVENT_TITANIC_SMASH,

    EVENT_BLIND_HARTED_MOVE,
};

enum Actions
{
    ACTION_START_BATTLE = 1,
    ACTION_EVADE_COMBAT,
    ACTION_COMPLETE_ENCOUNTER,

    ACTION_ACTIVATE_AMALGAM,
    ACTION_SPAWN_LIGHT,
    ACTION_SPAWN_MANIFESTATION,
    ACTION_SPAWN_ESSENSE,
};

enum eData
{
    DATA_BLIND_HATRED_POINT = 1,
    DATA_BLIND_HATRED_MOVING,
    DATA_PURIFYING_LIGHT_ID,

    DATA_PLAYER_TEST_ADD,
    DATA_PLAYER_TEST_REMOVE,
    DATA_PLAYER_TEST_DIED,
    DATA_PLAYER_TEST_PASSED,
    DATA_PLAYER_TEST_KILLED_CREATURE,

    DATA_EXPEL_CORRUPTION_TARGET,
};

enum MovementPoints
{
    POINT_BLIND_HATRED = 1,
};

enum Timers
{
    TIMER_BURST_OF_ANGER_FIRST = 2 * IN_MILLISECONDS,
    TIMER_BURST_OF_ANGER = 15 * IN_MILLISECONDS,
};

const Position centerPos = { 777.24f, 974.06f, 356.34f, 4.92f };

#define MAX_PURIFYING_LIGHT_POINTS 12
#define SPAWN_PURIFYING_LIGHT_10N 2
#define SPAWN_PURIFYING_LIGHT_25N_10H 5

const Position purifyingLightPos[MAX_PURIFYING_LIGHT_POINTS] =
{
    ///10-Normal Mode:
    { 804.5843f, 955.5048f, 356.3400f, 2.53f },  ///< Orb[6] = Left Side-5
    { 759.9286f, 946.2224f, 356.3400f, 0.99f },  ///< Orb[11] = Right Side-5
    /// 25-Normal Mode & 10-Heroic Mode:
    { 770.5687f, 1006.4410f, 356.7991f, 4.95f }, ///< Orb[1] = Center (At Norushen)
    { 803.3580f, 994.7569f, 356.3400f, 3.79f },  ///< Orb[4] = Left Side-3
    { 745.4035f, 982.6478f, 356.3400f, 6.02f },  ///< Orb[9] = Right Side-3
    /// 25-Heroic Mode:
    { 784.4426f, 1006.5900f, 356.3400f, 4.48f }, ///< Orb[2] = Left Side-1
    { 794.9124f, 1002.3000f, 356.3400f, 4.08f }, ///< Orb[3] = Left Side-2
    { 809.5897f, 981.0729f, 356.8000f, 3.33f },  ///< Orb[5] = Left Side-4
    { 757.9774f, 1001.039f, 356.3400f, 5.32f },  ///< Orb[7] = Right Side-1
    { 750.1006f, 992.8862f, 356.3400f, 5.69f },  ///< Orb[8] = Right Side-2
    { 745.1585f, 967.5299f, 356.8001f, 0.20f },  ///< Orb[10] = Right Side-4
    { 784.1593f, 942.0058f, 356.7998f, 1.78f }   ///< Orb[12] = Center (At Entrance)
};

#define MAX_BLIND_HATRED_POINTS 4
const Position blindHatredPos[MAX_BLIND_HATRED_POINTS] =
{
    {830.26f, 927.20f, 360.0f, 1.80f},
    {809.09f, 1023.42f, 360.0f, 3.38f},
    {728.46f, 1006.08f, 360.0f, 3.45f},
    {748.99f, 909.47f, 360.0f, 0.30f}
};

#define MAX_PHASE_SPELLS 16
const uint32 phaseSpells[MAX_PHASE_SPELLS] =
{
    SPELL_LOOK_WITHIN_1,
    SPELL_LOOK_WITHIN_2,
    SPELL_LOOK_WITHIN_3,
    SPELL_LOOK_WITHIN_4,
    SPELL_LOOK_WITHIN_5,
    SPELL_LOOK_WITHIN_6,
    SPELL_LOOK_WITHIN_7,
    SPELL_LOOK_WITHIN_8,
    SPELL_LOOK_WITHIN_9,
    SPELL_LOOK_WITHIN_10,
    SPELL_LOOK_WITHIN_11,
    SPELL_LOOK_WITHIN_12,
    SPELL_LOOK_WITHIN_13,
    SPELL_LOOK_WITHIN_14,
    SPELL_LOOK_WITHIN_15,
    SPELL_LOOK_WITHIN_16
};

#define MAX_ESSENSES 4
const Position essenseOfCorruptionPos[MAX_ESSENSES] =
{
    {787.456848f, 985.921326f, 356.34f, 2.606646f},
    {765.036438f, 983.373108f, 356.34f, 4.118547f},
    {767.934448f, 962.017456f, 356.34f, 5.700681f},
    {790.376404f, 965.921204f, 356.35f, 2.453494f}
};

const Position manifestationPos = { 777.564575f, 974.335632f, 356.35f, 2.584832f };

const Position norushenStartPos = { 768.84f, 1013.45f, 356.08f, 4.98f };
const Position norushenExitPos = { 794.67f, 892.50f, 371.13f, 1.76f };

#define TIMER_TESTS_UPDATE 1 * IN_MILLISECONDS
#define TIMER_TESTS_DURATION 1 * MINUTE * IN_MILLISECONDS

#define MAX_CONTAINMENTS 6
const uint8 containmentData[MAX_CONTAINMENTS] =
{
    DATA_LIGHT_CONTAINMENT_1,
    DATA_LIGHT_CONTAINMENT_2,
    DATA_LIGHT_CONTAINMENT_3,
    DATA_LIGHT_CONTAINMENT_4,
    DATA_LIGHT_CONTAINMENT_TOP,
    DATA_LIGHT_CONTAINMENT_BOTTOM
};

inline uint8 GetPurifyingLightsCount(Difficulty p_Difficulty)
{
    switch (p_Difficulty)
    {
    case DIFFICULTY_25_N:
    case DIFFICULTY_10_HC:
        return SPAWN_PURIFYING_LIGHT_25N_10H;
        break;
    case DIFFICULTY_25_HC:
        return MAX_PURIFYING_LIGHT_POINTS;
        break;
    }

    return SPAWN_PURIFYING_LIGHT_10N;
}

void AddSC_boss_norushen()
{
   
}
