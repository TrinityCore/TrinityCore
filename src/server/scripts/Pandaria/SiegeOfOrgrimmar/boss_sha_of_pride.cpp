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
#include "GameObjectAI.h"
#include "ObjectMgr.h"
#include "SceneHelper.h"

#define MAX_SHA_POWER 100
#define SHA_POWER_PERIODIC 600

#define DEFAULT_PRIDE_INCREASE 5

#define MAX_LINGERING_CORRUPTIONS 10

#define GIFT_OF_TITANS_COUNT_10 2
#define GIFT_OF_TITANS_COUNT_25 5
#define MARK_OF_ARROGANCE_COUNT_10 2
#define MARK_OF_ARROGANCE_COUNT_25 5

enum ScriptedTextNorushen
{
    SAY_GIFT_OF_THE_TITANS = 0,
    SAY_FINAL_GIFT = 1,
    SAY_NORUSHEN_INTRO_1 = 2,
    SAY_NORUSHEN_INTRO_2 = 3,
};

#define SOUND_DEATH 38897

enum ScriptedTextShaOfPride
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_UNLEASHED = 2,
    SAY_INTRO = 3,
    SAY_KILL = 4,
    SAY_SELF_REFLECTION = 5,
    SAY_SWELLING_PRIDE = 6,
    SAY_CORRUPTED_PRISON = 7,
};

enum ScriptedTextJaina
{
    SAY_JAINA_INTRO_1 = 0,
    SAY_JAINA_INTRO_2 = 1,
    SAY_JAINA_INTRO_3 = 2,
    SAY_JAINA_INTRO_4 = 3,
    SAY_JAINA_INTRO_5 = 4,
};

enum ScriptedTextLorthemar
{
    SAY_LORTHEMAR_INTRO_1 = 0,
    SAY_LORTHEMAR_INTRO_2 = 1,
    SAY_LORTHEMAR_INTRO_3 = 2,
    SAY_LORTHEMAR_INTRO_4 = 3,
    SAY_LORTHEMAR_INTRO_5 = 4,
};

Position npcAfterShaOfPridePos[7] =
{
    { 750.75f, 1131.48f, 356.08f, 1.73f}, // Jaina
    { 740.28f, 1129.70f, 356.08f, 1.73f}, // Lor'themar
    { 744.46f, 1134.51f, 356.08f, 1.73f}, // Gorehowl
    { 785.54f, 1171.07f, 356.08f, 4.14f}, // Portal to Orgrimmar (alliance)
    { 782.49f, 1165.84f, 356.08f, 0.82f}, // Jaina near portal
    { 688.79f, 1151.24f, 356.08f, 5.81f}, // Portal to Orgrimmar (horde)
    { 695.27f, 1146.95f, 356.08f, 2.62f}  // Lor'themar near portal
};

Position galakrasPlayersPos[3] =
{
    { 1366.50f, -5416.54f, 10.47f, 1.59f}, // alliance intro position
    { 1767.58f, -5265.74f, 6.97f, 2.90f},  // horde intro position
    { 1440.49f, -5015.87f, 12.11f, 1.67f}  // position at the docks
};


enum Spells
{
    // Intro

    SPELL_SHA_VORTEX = 146024,

    // Lingering Corruption
    SPELL_CORRUPTED_TOUCH = 149207,
    SPELL_CORRUPTED_TOUCH_DMG = 149209,

    // Boss

    SPELL_ZERO_POWER = 72242,

    SPELL_BERSERK = 26662,

    SPELL_PRIDE = 144343,

    SPELL_SWELLING_PRIDE = 144400,
    SPELL_BURSTING_PRIDE = 144910, // 25-49 pride
    SPELL_BURSTING_PRIDE_DMG = 144911,
    SPELL_PROJECTION_1 = 144952, // 50-74 pride
    SPELL_PROJECTION_2 = 145526, // explode visual (without dmg)
    SPELL_PROJECTION_MISSILE = 145066, // triggers non-existed spell 145324
    SPELL_PROJECTION_DMG = 145320,
    SPELL_PROJECTION_MARK = 146822,
    SPELL_AURA_OF_PRIDE = 146817, // 75-99 pride
    SPELL_AURA_OF_PRIDE_DMG = 146818,
    SPELL_OVERCOME_1 = 144843, // buff
    SPELL_OVERCOME_2 = 144863, // debuff

    SPELL_GIFT_OF_THE_TITANS = 146595, // casted by norushen
    SPELL_GIFT_OF_THE_TITANS_1 = 144359, // 1 player
    SPELL_GIFT_OF_THE_TITANS_2 = 146594, // 2 players
    SPELL_GIFT_OF_THE_TITANS_AOE = 144363, // search 8 yards
    SPELL_POWER_OF_THE_TITANS = 144364,
    SPELL_FINAL_GIFT = 144854,

    SPELL_MARK_OF_ARROGANCE = 144351,

    SPELL_WOUNDED_PRIDE = 144358,

    SPELL_SELF_REFLECTION = 144800,
    SPELL_SELF_REFLECTION_SPAWN = 144784,
    SPELL_SELF_REFLECTION_DMG = 144788,

    SPELL_REACHING_ATTACK = 144774,

    SPELL_UNLEASHED = 144832,
    SPELL_UNLEASHED_DMG = 144836,

    SPELL_CORRUPTED_PRISON_1 = 144574,
    SPELL_CORRUPTED_PRISON_2 = 144636,
    SPELL_CORRUPTED_PRISON_3 = 144683,
    SPELL_CORRUPTED_PRISON_4 = 144684,
    SPELL_CORRUPTED_PRISON_DMG = 144615, // knockback players
    SPELL_CORRUPTED_PRISON_OBJECT_1 = 144550, // ?
    SPELL_CORRUPTED_PRISON_OBJECT_2 = 144552, // ?
    SPELL_CORRUPTED_PRISON_OBJECT_3 = 144559, // ?

    // heroic spells
    SPELL_BANISHMENT_AOE_1 = 146823, // targets player
    SPELL_BANISHMENT_AOE_2 = 147028, // ?
    SPELL_BANISHMENT_TELEPORT = 148705,
    SPELL_BANISHMENT = 145215,
    SPELL_BANISHMENT_CLONE = 147365, // a wrong spell, I cannot find the correct one
    SPELL_BANISHMENT_AREATRIGGERS = 145217, // creates triggers
    SPELL_BANISHMENT_SCALE = 145684,
    SPELL_BANISHMENT_STUN = 146623,
    SPELL_CORRUPTION_PERIODIC_DMG = 145219,

    SPELL_ORB_OF_LIGHT_AREATRIGGER = 145299,
    SPELL_ORB_OF_LIGHT_DEBUFF = 145345,
    SPELL_ORB_OF_LIGHT_DUMMY = 145705, // ?
    SPELL_ORB_OF_LIGHT_HEAL = 149008,

    SPELL_ETHEREAL_CORRUPTION = 149027,
    SPELL_ETHEREAL_CORRUPTION_DMG = 149031,

    // Manifestation of Pride
    SPELL_MANIFESTATION_SPAWN = 144778,
    SPELL_MOCKING_BLAST = 144379,
    SPELL_LAST_WORD = 144370,

    SPELL_RIFT_OF_CORRUPTION_VISUAL_1 = 147186,
    SPELL_RIFT_OF_CORRUPTION_VISUAL_2 = 147210,
    SPELL_RIFT_OF_CORRUPTION_VISUAL_3 = 147211,
    SPELL_RIFT_OF_CORRUPTION_CLOSE = 147199,
    SPELL_UNSTABLE_CORRUPTION_PERIODIC = 147183,     ///< Summon NPC_RIFT_OF_CORRUPTION
    SPELL_UNSTABLE_CORRUPTION_PERIODIC_2 = 147389,
    SPELL_UNSTABLE_CORRUPTION_MISSILE = 147391,
    SPELL_UNSTABLE_CORRUPTION_DMG = 147198,
    SPELL_COLLAPSING_RIFT = 147388,
    SPELL_WEAKENED_RESOLVE = 147207,
};

enum Adds
{
    NPC_MANIFESTATION_OF_PRIDE = 71946,
    NPC_REFLECTION = 72172,
    NPC_SHADOW_PRISON = 72017,
    NPC_SHA_VORTEX = 72239,
    NPC_RIFT_OF_CORRUPTION = 72846,
    NPC_CORRUPTED_FRAGMENT = 72569,
    NPC_ETHEREAL_CORRUPTION = 73972
};

enum Events
{
    EVENT_SPAWN_SHA_OF_PRIDE = 1,
    EVENT_GIFT_OF_THE_TITANS,
    EVENT_FINAL_GIFT,

    EVENT_BERSERK,

    EVENT_REACHING_ATTACK,
    EVENT_MARK_OF_ARROGANCE,
    EVENT_SHADOW_PRISON,
    EVENT_SWELLING_PRIDE,
    EVENT_WOUNDED_PRIDE,
    EVENT_MANIFESTATION,
    EVENT_SELF_REFLECTION,
    EVENT_BANISHMENT,

    EVENT_REFLECTION_DMG,

    EVENT_GET_READY,
    EVENT_MOVE,
    EVENT_MOCKING_BLAST,
};

enum Timers
{
    TIMER_BERSERK = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_BANISHMENT = 37500
};

enum Actions
{
    ACTION_LINGERING_CORRUPTION_DIED = 1,
    ACTION_UNLEASHED,
    ACTION_RESET,
    ACTION_COMPLETED,
    ACTION_COMBAT_START,
};

enum eData
{
    DATA_TRAPPED_PLAYER = 1,
    DATA_TRAP_USED,
    DATA_TRAP_DEACTIVATED,
    DATA_BANISHED_PLAYER,
    DATA_BANISHED_PLAYER_REMOVE
};

enum PrideLevels
{
    PRIDE_MAX = 100,
};

const uint32 prisonSpells[MAX_SHADOW_PRISONS] =
{
    SPELL_CORRUPTED_PRISON_1,
    SPELL_CORRUPTED_PRISON_2,
    SPELL_CORRUPTED_PRISON_3,
    SPELL_CORRUPTED_PRISON_4
};

const Position shaVortexPos = { 747.83f, 1112.96f, 356.08f, 4.96f };

const Position manifestationPos10Man1 = { 735.34f, 1173.69f, 356.08f, 4.88f };    ///< Spawn on 10-Man Normal & Heroic
const Position manifestationPos25Man1 = { 809.4360f, 1126.069f, 356.08f, 3.34f }; ///< Spawn-1 on 25-Man Normal & Heroic
const Position manifestationPos25Man2 = { 686.6197f, 1099.645f, 356.08f, 0.21f }; ///< Spawn-2 on 25-Man Normal & Heroic

const Position prisonPos[MAX_SHADOW_PRISONS] =
{
    {764.30f, 1137.92f, 356.08f, 4.17f},
    {772.71f, 1096.25f, 356.08f, 2.53f},
    {731.98f, 1087.30f, 356.08f, 0.93f},
    {722.91f, 1128.89f, 356.08f, 5.65f}
};

enum BanishmentSizes : int
{
    MAN_10 = 1,
    MAN_25 = 3
};

const static std::vector<Position> s_RiftOfCorruptionPos =
{
    {756.455688f, 1070.445679f, 356.08f, 0.214239f},
    {788.021362f, 1083.490234f, 356.08f, 0.635736f},
    {790.660400f, 1116.040039f, 356.08f, 1.716968f},
    {778.604553f, 1155.088501f, 356.08f, 2.217879f},
    {743.775757f, 1155.686401f, 356.08f, 3.354089f},
    {706.478577f, 1142.788574f, 356.08f, 4.007716f},
    {705.524841f, 1106.764282f, 356.08f, 4.829329f},
    {719.434448f, 1072.366943f, 356.08f, 5.452409f}
};

const static std::vector<Position> s_MazeOuterPos =
{
    { 790.22f, 1178.94f, 356.072f, 4.87f },
    { 813.41f, 1070.07f, 356.072f, 1.71f },
    { 705.09f, 1046.00f, 356.072f, 1.67f },
    { 681.32f, 1155.88f, 356.072f, 0.15f }
};

#define MAX_MAZE_LINES 4
const static std::vector<Position> s_MazeLinesPos[MAX_MAZE_LINES] =
{
    {
        { 707.41f, 1110.85f, 356.072f, 1.69f},
        { 701.38f, 1142.33f, 356.072f, 1.79f },
        { 733.47f, 1150.15f, 356.072f, 0.16f },
        { 731.86f, 1157.54f, 356.072f, 3.06f },
        { 691.11f, 1148.89f, 356.072f, 4.93f },
        { 699.57f, 1109.44f, 356.072f, 0.07f }
    },
    {
        { 702.20f, 1096.29f, 356.072f, 4.91f },
        { 711.16f, 1056.51f, 356.072f, 4.97f },
        { 750.82f, 1064.71f, 356.072f, 3.93f },
        { 748.95f, 1072.20f, 356.072f, 3.29f },
        { 717.15f, 1066.25f, 356.072f, 3.35f },
        { 709.54f, 1097.71f, 356.072f, 1.72f }
    },
    {
        { 762.17f, 1074.80f, 356.072f, 0.18f },
        { 763.56f, 1067.35f, 356.072f, 0.18f },
        { 804.61f, 1076.12f, 356.072f, 0.20f },
        { 795.80f, 1115.63f, 356.072f, 1.72f },
        { 788.24f, 1113.43f, 356.072f, 3.50f },
        { 794.56f, 1082.61f, 356.072f, 3.03f }
    },
    {
        { 786.17f, 1128.11f, 356.072f, 1.76f },
        { 794.04f, 1128.93f, 356.072f, 1.76f },
        { 784.82f, 1169.42f, 356.072f, 3.23f },
        { 746.28f, 1161.56f, 356.072f, 4.72f },
        { 747.09f, 1153.45f, 356.072f, 6.12f },
        { 778.13f, 1160.16f, 356.072f, 4.85f }
    }
};

const static std::vector<Position> s_MazeInnerPos =
{
    { 718.79f, 1110.09f, 356.072f, 0.21f },
    { 732.73f, 1113.37f, 356.072f, 0.22f },
    { 740.80f, 1125.62f, 356.072f, 1.16f },
    { 738.16f, 1140.65f, 356.072f, 4.76f },
    { 744.55f, 1142.53f, 356.072f, 4.88f },
    { 747.68f, 1128.62f, 356.312f, 5.16f },
    { 762.27f, 1119.56f, 356.072f, 5.72f },
    { 776.37f, 1122.79f, 356.072f, 0.25f },
    { 777.17f, 1116.58f, 356.072f, 3.34f },
    { 762.07f, 1113.13f, 356.142f, 3.36f },
    { 754.31f, 1100.38f, 356.072f, 4.90f },
    { 757.35f, 1085.07f, 356.072f, 4.94f },
    { 750.99f, 1084.61f, 356.072f, 2.49f },
    { 747.56f, 1099.66f, 356.072f, 1.76f },
    { 734.32f, 1106.83f, 356.312f, 2.72f },
    { 719.45f, 1104.09f, 356.072f, 3.33f }
};

#define ORB_OF_LIGHT_COUNT 16
const Position OrbOfLightPos[ORB_OF_LIGHT_COUNT] =
{
    { 707.33f, 1049.58f, 356.072f, 0.22f },
    { 810.36f, 1072.77f, 356.085f, 0.30f },
    { 788.93f, 1177.47f, 356.072f, 3.25f },
    { 684.71f, 1152.18f, 356.072f, 4.98f },
    { 739.01f, 1153.83f, 356.072f, 5.15f },
    { 775.52f, 1155.16f, 356.072f, 4.94f },
    { 790.83f, 1121.30f, 356.072f, 4.38f },
    { 791.18f, 1084.94f, 356.072f, 3.34f },
    { 756.84f, 1070.19f, 356.072f, 3.43f },
    { 720.37f, 1069.57f, 356.072f, 2.11f },
    { 705.69f, 1103.52f, 356.072f, 1.73f },
    { 704.35f, 1139.94f, 356.072f, 0.43f },
    { 733.48f, 1121.81f, 356.072f, 4.38f },
    { 739.00f, 1099.27f, 356.072f, 6.21f },
    { 761.87f, 1105.65f, 356.072f, 1.31f },
    { 756.88f, 1127.60f, 356.072f, 2.59f }
};

#define ETHEREAL_CORRUPTION_COUNT 7
const Position s_EtherealCorruptions[ETHEREAL_CORRUPTION_COUNT] =
{
    { 721.04f, 1070.79f, 356.072f, 0.20f },
    { 790.54f, 1084.72f, 356.072f, 1.98f },
    { 775.54f, 1154.06f, 356.072f, 4.04f },
    { 766.33f, 1108.42f, 356.072f, 0.51f },
    { 733.85f, 1121.66f, 356.072f, 1.47f },
    { 749.05f, 1139.95f, 356.072f, 4.97f },
    { 762.96f, 1123.65f, 356.072f, 2.78f }
};

constexpr uint32 EtherealCorruptionsPath[ETHEREAL_CORRUPTION_COUNT] = { 739720, 739721, 739722, 739723, 739724, 739725, 739726 };

enum ePhaseMasks
{
    DEFAULT = 1,
    BANISHMENT_ALL = 65534
};

inline void TryIncreasePrideOnUnit(Unit* target, int32 prideToAdd)
{
    int32 currentPride = target->GetPower(POWER_ALTERNATE_POWER);
    if (currentPride >= PRIDE_MAX)
        return;

    if (target->HasAura(SPELL_GIFT_OF_THE_TITANS_1) ||
        target->HasAura(SPELL_GIFT_OF_THE_TITANS_2))
        return;

    int32 newPride = std::min(currentPride + prideToAdd, (int)PRIDE_MAX);

    target->SetPower(POWER_ALTERNATE_POWER, newPride);
}

Creature* GetShaOfPride(WorldObject* p_Searcher)
{
    if (InstanceScript* l_Instance = p_Searcher->GetInstanceScript())
        return l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_SHA_OF_PRIDE));

    return nullptr;
}

/// Check if players can be damaged by maze walls
// todo fix this
bool IsPlayerInMaze(Player* /*Player*/)
{
    /*if (!Trinity::IsPositionInZone(*p_Player, s_MazeOuterPos))
        return false;

    constexpr float l_CircleRange = 9.0f;

    for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
        if (p_Player->GetExactDist2d(&prisonPos[i]) <= l_CircleRange)
            return false;

    for (uint8 i = 0; i < MAX_MAZE_LINES; ++i)
        if (Trinity::IsPositionInZone(*p_Player, s_MazeLinesPos[i]))
            return false;

    if (Trinity::IsPositionInZone(*p_Player, s_MazeInnerPos))
        return false;*/

        //return true;
    return false;
}

void AddSC_boss_sha_of_pride()
{
    
}
