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

#include "GameObject.h"
#include "SpellAuraEffects.h"
#include "SpellAuraDefines.h"
#include "throne_of_thunder.h"

Position PlatformCenter = { 5895.829f,  4512.626f, -6.276f, 6.242f };

// clockwise
static const Position YellowEyeWay[8] =
{
    { 5833.541f,  4523.083f, -6.277f, 1.873f },
    { 5859.474f,  4563.136f, -6.277f, 1.873f },
    { 5905.615f,  4573.638f, -6.277f, 1.873f },
    { 5945.436f,  4548.107f, -6.277f, 1.873f },
    { 5955.923f,  4502.487f, -6.277f, 1.873f },
    { 5930.874f,  4463.088f, -6.277f, 1.873f },
    { 5886.584f,  4452.482f, -6.277f, 1.873f },
    { 5845.496f,  4476.399f, -6.277f, 1.873f },
};

// counter clockwise
static const Position YellowEyeWay2[8] =
{
    { 5845.496f,  4476.399f, -6.277f, 1.873f },
    { 5886.584f,  4452.482f, -6.277f, 1.873f },
    { 5930.874f,  4463.088f, -6.277f, 1.873f },
    { 5955.923f,  4502.487f, -6.277f, 1.873f },
    { 5945.436f,  4548.107f, -6.277f, 1.873f },
    { 5905.615f,  4573.638f, -6.277f, 1.873f },
    { 5859.474f,  4563.136f, -6.277f, 1.873f },
    { 5833.541f,  4523.083f, -6.277f, 1.873f },
};

Position WallsofIce1[5] =
{
    { 5940.07f, 4484.06f, -3.87f, 2.53f }, // x5925.18"	y"4493.79"	z"-6.27763"	o"5.61419 rotation2 0.328294 rotation3 -0.944576
    { 5927.63f, 4490.19f, -6.27f, 2.48f },
    { 5923.44f, 4498.62f, -6.27f, 2.54f },
    { 5911.40f, 4503.76f, -6.27f, 2.45f },
    { 5907.17f, 4508.19f, -6.27f, 2.58f },
};

Position WallsofIce2[4] =
{
    { 5885.82f, 4512.41f, -6.27f, 3.26f }, // x5862.33"	y"4508.2"	z"-6.27703"	o"3.28283 rotation2 0.997507 rotation3 -0.0705623
    { 5870.28f, 4510.39f, -6.27f, 3.30f },
    { 5856.52f, 4506.37f, -6.27f, 0.16f },
    { 5845.16f, 4505.20f, -6.27f, 0.19f },
};

Position WallsofIce3[4] =
{
    { 5910.73f, 4568.82f, -6.27f, 1.02f }, //  x5903.09, y4547.13, z-6.27707, o1.28039  rotation2 0.597351, rotation3 0.80198
    { 5903.07f, 4549.19f, -6.27f, 1.31f },
    { 5901.82f, 4538.36f, -6.27f, 4.53f }, //orientation
    { 5898.68f, 4523.55f, -6.27f, 1.31f },
};

enum WallsofIceObject
{
    GO_WALL_OF_ICE = 221422,
    GO_WALL_OF_ICE_1 = 999235,
    GO_WALL_OF_ICE_2 = 999236,
};

Position CriomsonFogs[3] =
{
    { 5874.76f, 4465.76f, -6.27f, 1.12f },
    { 5945.27f, 4512.17f, -6.27f, 3.11f },
    { 5914.87f, 4559.68f, -6.27f, 4.32f },
};

Position AzureFogs[3] =
{
    { 5946.81f, 4499.13f, -6.27f, 2.93f },
    { 5849.98f, 4531.87f, -6.27f, 5.91f },
    { 5879.26f, 4464.22f, -6.27f, 1.14f },
};

Position AmberFogs[2] =
{
    { 5869.07f, 4562.25f, -6.27f, 5.16f },
    { 5929.27f, 4474.55f, -6.27f, 2.45f },
};

Position firstPlatformMaze[27] =
{
    { 5948.27f, 4486.34f, -6.27782f, 2.75145f },
    { 5944.89f, 4479.75f, -6.27782f, 2.46085f },
    { 5951.67f, 4493.98f, -6.27782f, 2.74359f },
    { 5939.84f, 4474.75f, -6.27782f, 2.35089f },
    { 5934.88f, 4469.91f, -6.27782f, 2.28806f },
    { 5928.42f, 4464.68f, -6.27782f, 2.13098f },
    { 5921.72f, 4461.66f, -6.27782f, 1.95034f },
    { 5912.68f, 4458.06f, -6.27782f, 1.95034f },
    { 5940.51f, 4497.75f, -6.27782f, 4.35601f },
    { 5938.19f, 4491.52f, -6.27782f, 4.24606f },
    { 5934.97f, 4486.21f, -6.27782f, 4.04971f },
    { 5930.6f,  4481.15f, -6.27782f, 3.99474f },
    { 5926.2f,  4476.54f, -6.27782f, 3.93583f },
    { 5921.33f, 4472.27f, -6.27782f, 3.64916f },
    { 5914.34f, 4469.15f, -6.27782f, 3.50779f },
    { 5908.62f, 4466.88f, -6.27782f, 3.46067f },
    { 5930.55f, 4503.24f, -6.27723f, 4.29456f },
    { 5925.66f, 4496.61f, -6.27723f, 5.83394f },
    { 5920.11f, 4489.32f, -6.27723f, 5.67687f },
    { 5913.77f, 4484.01f, -6.27723f, 5.27632f },
    { 5906.75f, 4481.3f,  -6.27723f, 5.07998f },
    { 5900.2f,  4478.56f, -6.27723f, 5.06427f },
    { 5923.57f, 4505.54f, -6.27713f, 4.33386f },
    { 5919.4f,  4498.78f, -6.27713f, 3.99223f },
    { 5915.01f, 4493.54f, -6.27713f, 3.83907f },
    { 5908.83f, 4489.92f, -6.27713f, 3.57204f },
    { 5901.25f, 4487.07f, -6.27713f, 3.3482f },
};

Position secondPlatformMaze[17] =
{
    { 5905.89f, 4485.5f,  -6.27622f, 3.30895f },
    { 5896.51f, 4483.75f, -6.27622f, 0.0416808f },
    { 5887.8f,  4485.03f, -6.27622f, 6.15601f, },
    { 5878.75f, 4488.54f, -6.27622f, 5.66122f },
    { 5872.19f, 4494.12f, -6.27622f, 5.44916f },
    { 5904.18f, 4470.85f, -6.2768f,  0.234899f },
    { 5895.62f, 4470.25f, -6.2768f,  0.0228417f, },
    { 5887.09f, 4470.59f, -6.2768f,  6.07827f },
    { 5878.38f, 4473.12f, -6.2768f,  5.87014f, },
    { 5870.03f, 4477.61f, -6.2768f,  5.55206f },
    { 5862.55f, 4484.47f, -6.2768f,  5.40677f, },
    { 5853.93f, 4475.85f, -6.27748f, 0.631524f },
    { 5860.7f,  4468.19f, -6.27748f, 0.835728f },
    { 5870.33f, 4462.01f, -6.27748f, 1.036f },
    { 5879.51f, 4457.67f, -6.27748f, 1.1656f },
    { 5889.9f,  4455.25f, -6.27748f, 1.46405f },
    { 5900.03f, 4454.99f, -6.27748f, 1.59756f },
};

Position thirdPlatformMaze[19] =
{
    { 5867.94f, 4497.45f, -6.27642f, 5.11861f },
    { 5865.8f,  4509.83f, -6.27642f, 4.93012f },
    { 5866.84f, 4519.44f, -6.27642f, 4.48245f },
    { 5870.96f, 4528.12f, -6.27642f, 4.20364f },
    { 5876.89f, 4535.47f, -6.27642f, 3.92483f },
    { 5861.1f,  4491.03f, -6.27642f, 5.17819f },
    { 5858.3f,  4499.43f, -6.27642f, 4.71874f },
    { 5856.68f, 4508.77f, -6.27642f, 4.78551f },
    { 5856.91f, 4516.89f, -6.27642f, 4.60094f },
    { 5858.95f, 4525.15f, -6.27642f, 4.33391f },
    { 5862.61f, 4532.59f, -6.27642f, 4.21218f },
    { 5869.22f, 4541.13f, -6.27642f, 3.92944f },
    { 5859.0f,  4551.14f, -6.27642f, 5.48452f },
    { 5850.37f, 4541.51f, -6.27642f, 5.61018f },
    { 5845.19f, 4532.4f,  -6.27642f, 5.8026f },
    { 5841.43f, 4522.34f, -6.27642f, 5.94397f },
    { 5840.26f, 4512.19f, -6.27642f, 6.25419f },
    { 5841.1f,  4500.92f, -6.27642f, 0.198772f },
    { 5843.49f, 4489.4f,  -6.27642f, 0.308728f },
};

Position fourthPlatformMaze[31] =
{
    { 5902.64f, 4541.51f, -6.27684f, 2.99415f },
    { 5911.51f, 4537.12f, -6.27684f, 2.51898f },
    { 5918.19f, 4530.55f, -6.27684f, 2.25588f },
    { 5923.9f,  4521.01f, -6.27684f, 1.9535f },
    { 5923.82f, 4511.55f, -6.27684f, 1.66687f },
    { 5933.65f, 4511.61f, -6.27718f, 4.61212f },
    { 5932.67f, 4522.16f, -6.27718f, 4.87129f },
    { 5929.93f, 4530.77f, -6.27718f, 5.04015f },
    { 5924.87f, 4540.22f, -6.27718f, 5.39357f },
    { 5915.5f,  4546.92f, -6.27718f, 5.75877f },
    { 5904.92f, 4551.38f, -6.27718f, 5.97868f },
    { 5895.25f, 4552.75f, -6.27718f, 6.1711f },
    { 5885.9f,  4552.35f, -6.27718f, 0.0881835f },
    { 5876.24f, 4549.81f, -6.27718f, 0.390562f },
    { 5948.08f, 4514.54f, -6.27771f, 3.18266f },
    { 5946.25f, 4527.19f, -6.27771f, 3.36723f },
    { 5943.26f, 4536.69f, -6.27771f, 3.54787f },
    { 5937.69f, 4546.74f, -6.27771f, 3.74029f },
    { 5931.45f, 4554.32f, -6.27771f, 3.9013f },
    { 5923.56f, 4561.15f, -6.27771f, 4.10157f },
    { 5913.1f,  4566.27f, -6.27771f, 4.24687f },
    { 5902.76f, 4569.54f, -6.27771f, 4.54925f },
    { 5891.02f, 4570.13f, -6.27771f, 4.67883f },
    { 5880.83f, 4568.94f, -6.27771f, 4.9615f },
    { 5869.91f, 4565.3f,  -6.27771f, 5.07152f },
    { 5891.34f, 4541.86f, -6.27684f, 3.44968f },
    { 5882.23f, 4539.21f, -6.27684f, 3.65388f },
    { 5921.81f, 4502.19f, -6.27782f, 4.35919f },
    { 5928.02f, 4499.76f, -6.27782f, 2.71377f },
    { 5940.07f, 4494.8f,  -6.27782f, 2.73734f },
    { 5948.34f, 4491.19f, -6.27782f, 2.74912f },
};

static const Position SternPattern[4] =
{
    { 5846.17f, 4511.81f, -6.27f, 6.27f },
    { 5946.34f, 4511.34f, -6.27f, 3.09f },
    { 5895.18f, 4467.46f, -6.27f, 1.55f },
    { 5896.57f, 4554.89f, -6.27f, 4.64f },
};

enum Spells
{
    SPELL_HARD_STARE = 133765,
    SPELL_GAZE = 134029,
    SPELL_FORCE_OF_WILL = 136932,
    SPELL_FORCE_OF_WILL_KNOCKBACK = 136413,
    SPELL_LINGERING_GAZE_CAST = 138467,
    SPELL_LINGERING_GAZE_MARKER = 134626,
    SPELL_LINGERING_GAZE_DMG = 133792,
    SPELL_BERSERK_KILLALL = 137747,
    SPELL_DRAIN_LIFE_STUN = 137727,
    SPELL_DRAIN_LIFE_CHANNEL = 133795,
    SPELL_DRAIN_LIFE_DAMAGE = 133798,
    SPELL_DRAIN_LIFE_HEAL = 133807,
    SPELL_DESINTEGRATION_BEAM = 133776,
    SPELL_DESINTEGRATION_BEAM_PRECAST = 134169,
    SPELL_MIND_DAGGERS = 139108,

    // Beams
    SPELL_YELLOW_BEAM = 133740,
    SPELL_RED_BEAM = 133734,
    SPELL_BLUE_BEAM = 133672,
    SPELL_YELLOW_BEAM_DMG = 133738,
    SPELL_RED_BEAM_DMG = 133732,
    SPELL_BLUE_BEAM_DMG = 133677,
    SPELL_YELLOW_BEAM_DMG_TO_ALL = 133739,
    SPELL_RED_BEAM_DMG_TO_ALL = 133733,
    SPELL_BLUE_BEAM_DMG_TO_ALL = 133678,

    SPELL_FOG_INVISIBLE = 137092,

    SPELL_CAUSTIC_SPIKE = 136154,
    SPELL_ICY_GRASP = 136177,
    SPELL_CRIMSON_BLOOM = 136122,
    SPELL_FLASH_FREEZE = 136124,
    SPELL_AMBER_RETALIATION = 136175,
    SPELL_BURST_OF_AMBER = 136123,

    // hc spells
    SPELL_DEVOUR_PERIODIC = 134010,
    SPELL_DEVOUR_SHARED_HP = 134005,
    SPELL_DARK_PLAGUE = 133598,
    SPELL_DARK_PARASITE = 133597,

    SPELL_VOID_LINGERING_GAZE = 134040,
    SPELL_ICE_WALL = 134576, // .mod scale 0.4 for correct size

    SPELL_STERN_GAZE = 136618, // channel speLL
    SPELL_STERN_GAZE_DAMAGE = 136616,

    SPELL_MAZE_VIZUAL = 142155,
    SPELL_EYE_SORES = 134755,

    // fogs colors
    SPELL_RED_FOG = 136128,
    SPELL_BLUE_FOG = 136130,
    SPELL_YELLOW_FOG = 136129,

    // colorblind pre-cast spells
    SPELL_RED_PREBLIND = 134123,
    SPELL_BLUE_PREBLIND = 134122,
    SPELL_YELLOW_PREBLIND = 134124,
};

enum NpcEntry
{
    // Beam phase eyes
    YELLOW_EYE = 67856, // for yellow beam
    BLUE_EYE = 67854, // for blue beam
    RED_EYE = 67855, // for red beam
    YELLOW_EYE_MOVER = 67829, // yellow eye not work with player, just with invisible

    // Durumu eyes
    MIND_EYE = 67875,
    HUNGRY_EYE = 67859,
    APPRAYISYING_EYE = 67858,
    EVIL_EYE = 67860,
    STERN_EYE = 69280,
    CROSS_EYE = 67857,
    WANDERING_EYE = 68024,

    // fogs
    CRIMSON_FOG = 69050,
    AZURE_FOG = 69052,
    AMBER_FOG = 69051,

    BOSS_DURUMU = 68036,

    // custom ais
    NPC_VOID_ZONE_LINGERING_GAZE = 999249,
    NPC_WALL_OF_ICE_1 = 999250,
    NPC_WALL_OF_ICE_2 = 999251,
    NPC_WALL_OF_ICE_3 = 999252,

    NPC_MAZE_PERIODIC = 999256,
    NPC_MAZE_BEAM = 999257,

    NPC_SAFESPOT_1 = 999259,
    NPC_SAFESPOT_2 = 999260,
    NPC_SAFESPOT_3 = 999261,
    NPC_SAFESPOT_4 = 999265,
    NPC_SAFESPOT_5 = 999263,
    NPC_SAFESPOT_6 = 999266,
    NPC_SAFESPOT_7 = 999264,
};

enum Events
{
    // Durumu
    EVENT_HARD_STARE = 1,
    EVENT_GAZE,
    EVENT_BERSERK,
    EVENT_LIGHT_SPECTRUM_SAY_SUMMON,
    EVENT_LIGHT_SPECTRUM,
    EVENT_MAZE_TIME,
    EVENT_MAZE_ORIENTATION,
    EVENT_MAZE_END,
    EVENT_MIND_DAGGERS,
    EVENT_LINGERING_TRIGGERED,
    EVENT_LINGERING_MARKER,
    EVENT_WALLS_OF_ICE,

    // Eyes
    EVENT_FORCE_OF_WILL,
    EVENT_LINGERING_GAZE,
    EVENT_DRAIN_LIFE,
    EVENT_DRAIN_LIFE_TAR_CHECK,
    EVENT_EYES_ORIENTATION,
    EVENT_START_DEVOUR,
    EVENT_DEVOUR,
    // summon eyes
    EVENT_SUMMON_APPRAISIING_EYE,
    EVENT_SUMMON_EVIL_EYE,
    EVENT_SUMMON_HUNGRY_EYE,
    EVENT_SUMMON_MINDS_EYE,
    EVENT_SUMMON_CROSS_EYE,
    EVENT_SUMMON_STERN_EYE,

    // For roaming fogs and eyes
    EVENT_MOVE_RANDOM,
    EVENT_CHECK_BEAM_TARGET,

    EVENT_RED_EYE_VISUAL,
    EVENT_BLUE_EYE_VISUAL,

    // fogs
    EVENT_RED_FOG_WIND,
    EVENT_FOG_CAST,
    EVENT_DARK_PARASITE,
    // Eye mover
    EVENT_DISINTEGRATION_BEAM,
    EVENT_KILL_PLAYERS,
    EVENT_INITIALIZE_TYPE_MOVE,

    EVENT_ACTIVATE_MOVE,
    EVENT_PREACTION_TARGET,

    EVENT_DAMAGE_PLAYERS,
    EVENT_RED_EYE,
    EVENT_BLUE_EYE,
    EVENT_YELLOW_EYE,

    EVENT_CHECK_PLAYERS_FRONT,
    EVENT_DAMAGE_RAID,
    EVENT_KEEP_TARGET_MOVER,
    EVENT_DISINTEGRATION_BEAM_END,
    EVENT_HEROIC_SPECTRUM,
    EVENT_CAST_ONEYE,
    EVENT_CAUSTIC_SPIKE,
    EVENT_SUMMON_FOGS_CRIMSON,
    EVENT_SUMMON_FOGS_CRIMSON_KILLED,
    EVENT_SUMMON_FOGS_AZURE,
    EVENT_SUMMON_FOGS_AMBER,
    EVENT_CRIMSON_BLOOM,
    EVENT_ICY_GRASP,
    EVENT_FLASH_FREEZE,
    EVENT_AMBER_RETALIATION,
    EVENT_BURST_OF_AMBER,
    EVENT_STERN_GAZE,

    // maze safespot
    EVENT_CREATE_SAFESPOT,
    EVENT_CREATE_SAFESPOT_2,
    EVENT_CREATE_SAFESPOT_3,
    EVENT_CREATE_SAFESPOT_4,
    EVENT_CREATE_SAFESPOT_5,
    EVENT_CREATE_SAFESPOT_6,
    EVENT_CREATE_SAFESPOT_7,

    // movement
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_1_REVERSE,
    EVENT_2_REVERSE,
    EVENT_3_REVERSE,
    EVENT_4_REVERSE,
    EVENT_5_REVERSE,
    EVENT_6_REVERSE,
    EVENT_7_REVERSE,
    EVENT_8_REVERSE,

    // maze events
    EVENT_EYE_SORES_PLAYERS,
    EVENT_ADD_VIZUAL,
    EVENT_CHECK_PLAYERS_AND_MAKE_SAFEZONE,
    EVENT_READD_VIZUAL_MAZE,
    EVENT_SUMMON_MAZE_1,
    EVENT_SUMMON_MAZE_2,
    EVENT_ADD_WALLS_BEFORE_MAZE,
    EVENT_SUMMON_MAZE_3,
    EVENT_SUMMON_MAZE_4,
};

enum Points
{
    POINT_1 = 1,
    POINT_2 = 2,
    POINT_3 = 3,
    POINT_4 = 4,
    POINT_5 = 5,
    POINT_6 = 6,
    POINT_7 = 7,
    POINT_8 = 8,
    POINT_1_REVERSE = 9,
    POINT_2_REVERSE = 10,
    POINT_3_REVERSE = 11,
    POINT_4_REVERSE = 12,
    POINT_5_REVERSE = 13,
    POINT_6_REVERSE = 14,
    POINT_7_REVERSE = 15,
    POINT_8_REVERSE = 16,
};

enum Actions
{
    ACTION_LIGHT_SPECTRUM_DONE = 1,
    ACTION_ADD_SPECTRUM = 2,
    ACTION_CAST_SPELL_MOVER = 3,
    ACTION_ACTIVATE_WALLS = 4,
    ACTION_SPAWN_SPOTS = 5,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_HARD_STARE = 2,
    TALK_COLORBLIND = 3,
    TALK_GAZE = 4,
    TALK_DISINTEGRATION = 5,
    TALK_WIPE = 6,
    TALK_DEATH = 7,
};

#define STERN_DISTANCE 50.0f
#define IMMUNE_NPC me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC)
#define IMMUNE_PC me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC)

void AddSC_boss_durumu()
{
    
}
