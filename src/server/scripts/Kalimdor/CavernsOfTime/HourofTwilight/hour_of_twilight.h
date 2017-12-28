/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

#ifndef DEF_HOUR_OF_TWILIGHT_H
#define DEF_HOUR_OF_TWILIGHT_H

enum Data
{
    DATA_ARCURION_EVENT,
    DATA_ASIRA_DAWNSLAYER_EVENT,
    DATA_ARCHBISHOP_BENEDICTUS_EVENT,
};

enum Data64
{
    DATA_ARCURION,
    DATA_ASIRA_DAWNSLAYER,
    DATA_ARCHBISHOP_BENEDICTUS,
    DATA_TRASH_KILLED,
    DATA_RESET_TOTALTRASH,
    DATA_THRALL,
    DATA_THRALL_SECOND,
    DATA_THRALL_FINAL
};


enum CreatureIds
{
    // Dungeon Bosses

    BOSS_ARCURION = 54590,
    NPC_FS_ARCURION = 54600,
    NPC_ICY_TOMB = 54995,

    BOSS_ASIRA_DAWNSLAYER = 54968,
    BOSS_ARCHBISHOP_BENEDICTUS = 54938,

    NPC_THRALL = 55779,
    NPC_FROZEN_SERVITOR = 54555,
    NPC_CRYSTALLINE_ELEMENT = 55559,
    NPC_FROZEN_SHARD = 55563,

    NPC_THRALL_SECOND = 54972,
    NPC_TWILIGHT_ASSASSIN = 55106,
    NPC_TWILIGHT_BRUISER = 55112,
    NPC_TWILIGHT_RANGER = 55107,
    NPC_TWILIGHT_SHADOW_WALKER = 55109,
    NPC_TWILIGHT_THUG = 55111,

    NPC_THRALL_FINAL = 54971,
    NPC_FACELESS_BRUTE = 54632,
    NPC_FACELESS_SHADOW_WEAVER = 54633,
    NPC_FLAILING_TENTACLE = 54696,
    NPC_SHADOW_BORER = 54686

};

enum GameObjectIds
{
    GO_ICE_WALL = 202396,
    GO_HOLY_WALL = 210097
};

enum ThrallActions {
     ACTION_MOVE_1 = 1,
     ACTION_MOVE_2,
     ACTION_MOVE_3,
     ACTION_MOVE_4,
     ACTION_MOVE_5,
     ACTION_HEAL,
     ACTION_SUMMON_WAVE_3,
     ACTION_MOVE,
     ACTION_START_ARCURION,
     ACTION_START_ASIRA,
     ACTION_MOVE_BENEDICTUS,
     ACTION_START_BENEDICTUS,
     ACTION_THRALL_STOP_CAST,
     ACTION_LAVA_BURST_ARCURION,
     ACTION_WATER_SHELL,
     ACTION_CHAIN_LIGHTNING
};

const Position SpawnTrash[33] =
{
    {4933.77f, 266.87f, 97.40f, 1.544891f},
    {4918.44f, 265.51f, 97.43f, 1.338924f},
    {4910.98f, 223.60f, 99.05f, 4.084261f},
    {4904.95f, 227.98f, 99.22f, 4.084261f},
    {4890.67f, 201.81f, 99.92f, 0.946594f},
    {4891.85f, 144.00f, 106.37f, 3.130117f},
    {4891.77f, 136.78f, 106.82f, 3.130117f},
    {4891.88f, 145.17f, 106.40f, 3.130117f},
    {4891.79f, 139.35f, 106.28f, 3.130117f},
    {4891.86f, 141.32f, 106.54f, 3.130117f},
    {4380.27f, 419.91f, 10.70f, 0.285451f}, //Twilight Assassin
    {4308.87f, 389.84f, -8.08f, 0.322838f},
    {4307.08f, 395.20f, -8.08f, 0.322838f},
    {4305.60f, 399.62f, -8.08f, 0.322838f},
    {4303.90f, 404.70f, -8.08f, 0.322838f},
    {4298.71f, 474.77f, -7.34f, 0.131855f},
    {4298.09f, 479.42f, -7.34f, 0.131855f},
    {4297.60f, 483.11f, -7.34f, 0.131855f},
    {4296.93f, 488.19f, -7.34f, 0.131855f},
    {4344.60f, 583.93f, 8.13f, 4.277571f},
    {4346.30f, 583.14f, 7.93f, 4.277571f},
    {4348.06f, 582.49f, 7.97f, 4.277571f},
    {4350.02f, 581.75f, 8.07f, 4.277571f},
    {3889.34f, 290.12f, -2.00f, 3.164954f},
    {3906.16f, 262.49f, 6.84f, 2.644990f},
    {3907.13f, 249.20f, 9.17f, 2.192787f},
    {3919.17f, 245.14f, 12.69f, 2.483705f},
    {3815.84f, 323.33f, -31.58f, 5.028507f},
    {3803.37f, 325.79f, -37.76f, 5.311246f},
    {3808.11f, 315.78f, -39.47f, 5.829609f},
    {3730.72f, 264.32f, -87.53f, 0.536728f},
    {3740.43f, 271.24f, -80.68f, 0.203299f},
    {3741.01f, 286.64f, -82.49f, 0.203299f}
};

const Position SpawnFrozenServitor[6] =
{
    {4800.29f, 35.24f, 100.50f, 2.028816f},
    {4822.10f, 43.99f, 107.57f, 2.824868f},
    {4829.50f, 55.76f, 108.94f, 2.670581f},
    {4771.84f, 110.14f, 121.63f, 4.957147f},
    {4752.54f, 88.83f, 111.87f, 5.7768951f},
    {4783.87f, 116.55f, 126.67f, 5.145265f}
};

const Position SpawnBoss[3] =
{
    {4771.48f, 65.26f, 67.12f, 0.60f}

};

const Position MovePoints[4] =
{
    {4873.05f, 165.60f, 98.61f},
    {4899.00f, 215.70f, 99.20f},
    {4870.67f, 164.73f, 98.42f},
    {4770.52f, 62.64f, 67.03f}

};

const Position ArchbishopPoints[7] =
{
    {3671.92f, 285.59f, -118.63f},
    {3711.68f, 286.64f, -99.76f},
    {3671.92f, 285.59f, -118.63f},
    {3639.07f, 282.08f, -120.15f},
    {3596.98f, 278.06f, -120.15f},
    {3580.74f, 276.73f, -114.03f},
    {3547.73f, 273.52f, -115.96f}

};

const Position HomePoints[4] =
{
    { 3563.35f, 274.82f, -115.97f },
    { 3547.73f, 273.52f, -115.96f },
    { 4789.49f, 80.28f, 71.49f },
    { 4285.43f, 578.64f, -6.59f }


};


#endif
