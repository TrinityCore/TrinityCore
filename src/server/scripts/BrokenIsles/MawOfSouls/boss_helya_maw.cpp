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

#include "maw_of_souls.h"
#include "GameObject.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_TAINT_SEA = 2,
    SAY_97 = 3,
    SAY_94 = 4,
    SAY_90 = 5,
    SAY_87 = 6,
    SAY_PHASE2 = 7,
    SAY_WARN_WING_BUFFET = 8,
    SAY_DEATH = 9,
    SAY_SUBMERGED_2 = 10
};

enum Spells
{
    //Intro
    SPELL_SOULLESS_SCREAM = 194603,

    SPELL_INTERFERE_TARGETTING = 197710,
    SPELL_TAINT_OF_THE_SEA = 197517,
    SPELL_TORRENT = 197805,
    SPELL_TAINTED_ESSENCE = 202470,
    //Phase 2
    SPELL_SUBMERGED = 196947, //32:34
    SPELL_TRANSFORM = 197734, //32:44 - Self hit
                        //SMSG_MOVE_UPDATE_TELEPORT 32:44 - 2933.5 Y: 961.792 Z: 510.38 O: 4.712389
                        SPELL_SMASH = 197689, //Force cast all players
                        SPELL_WING_BUFFET = 198520,
                        SPELL_TORRENT_2 = 198495,
                        SPELL_CORRUPTED_BELLOW = 227233,

                        //Tentacle
                        SPELL_GRASPING_STUN_LEFT = 198180,
                        SPELL_GRASPING_STUN_RIGHT = 196450,
                        SPELL_PIERCING_TENTACLE = 197112,
                        SPELL_SWIRLING_POOL_AT = 195167,
                        SPELL_SWIRLING_POOL_DMG = 195309,
                        SPELL_SWIRLING_POOL_JUMP = 194839,

                        //Swirling Pool
                        SPELL_TURBULENT_WATERS = 197753,

                        //Heroic
                        SPELL_BRACKWATER_BARRAGE = 202088,
                        SPELL_BRACKWATER_BARRAGE_DMG = 202098,

                        //Trash
                        SPELL_GIVE_NO = 196885,
                        SPELL_DEBILITATING = 195293,
                        SPELL_BIND = 195279,
};

enum eEvents
{
    EVENT_INTRO = 1,
    EVENT_TAINT_SEA = 2,
    EVENT_TORRENT = 3,
    EVENT_SUM_DESTRUCTOR_TENTACLE = 4,
    EVENT_SUM_PIERCING_TENTACLE = 5,
    EVENT_P1_SUBMERGED_START = 6,
    EVENT_P1_SUBMERGED_END = 7,
    EVENT_WING_BUFFET = 8,
    EVENT_ACTION_SWIRLING_POOL = 9,
    EVENT_BRACKWATER_BARRAGE = 10,
    EVENT_TORRENT_2 = 11, //Second phase
    EVENT_CORRUPTED_BELLOW = 12,
    EVENT_P2_SUBMERGED_START = 13,
    EVENT_P2_SUBMERGED_END = 14,

    //Trash
    EVENT_SUMMON_1 = 1,
    EVENT_SUMMON_2 = 2,
    EVENT_GIVE_NO = 3,
    EVENT_DEBILITATING = 4,
    EVENT_BIND = 5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
};

enum eVisualKits
{
    VISUAL_KIT_1 = 60920, //30:14 - visual spawn
    VISUAL_KIT_2 = 62877, //30:22 - start intro
    VISUAL_KIT_3 = 60222, //30:28
    VISUAL_KIT_4 = 63777, //Brackwater barrage?

    //Brackwater missle
    VISUAL_BW_MIS_RIGHT = 52865,
    VISUAL_BW_MIS_LEFT = 52868,
    //Heroic
    VISUAL_H_BRACKWATER_LEFT = 52869,
    VISUAL_H_BRACKWATER_RIGHT = 52870,
    //Mythic
    VISUAL_M_BRACKWATER_LEFT = 65462,
    VISUAL_M_BRACKWATER_RIGHT = 65463,
};

enum eMisk
{
    DATA_POOL_ACTIVE = 0,
    DATA_POOL_IDX
};

std::vector<std::pair<uint32, Position>> graspingPos =
{
    //Left
    {NPC_GRASPING_TENTACLE_3, {2917.30f, 950.65f, 512.26f, 5.73f}},
    {NPC_GRASPING_TENTACLE_2, {2921.71f, 959.25f, 513.21f, 5.85f}},
    {NPC_GRASPING_TENTACLE_3, {2925.54f, 965.84f, 512.26f, 5.65f}},

    //Right
    {NPC_GRASPING_TENTACLE_1, {2941.37f, 966.34f, 513.79f, 4.08f}},
    {NPC_GRASPING_TENTACLE_4, {2945.93f, 958.59f, 513.23f, 3.58f}},
    {NPC_GRASPING_TENTACLE_1, {2948.58f, 952.28f, 513.47f, 3.41f}}
};

std::vector<Position> swirlingPos =
{
    {2933.33f, 960.27f, 510.39f, 1.57f},
    {2926.73f, 952.15f, 510.39f, 1.57f},
    {2939.91f, 952.15f, 510.39f, 1.57f},
    {2933.40f, 941.15f, 510.39f, 1.57f},
    {2922.20f, 937.07f, 510.39f, 1.57f},
    {2943.52f, 935.80f, 510.39f, 1.57f},
    {2927.44f, 928.84f, 510.39f, 1.57f},
    {2939.53f, 928.46f, 510.39f, 1.57f},
    {2918.25f, 921.30f, 510.39f, 1.57f},
    {2933.18f, 920.70f, 510.39f, 1.57f},
    {2948.52f, 921.45f, 510.39f, 1.57f}
};

//Skyal
Position const addsPos[18] =
{
    {2942.57f, 886.99f, 537.76f, 4.48f},
    {2924.55f, 887.20f, 537.65f, 5.26f},

    {2906.68f, 752.27f, 538.55f, 4.72f}, //97097
    {2959.93f, 751.26f, 538.52f, 4.63f}, //97097
    {2916.09f, 807.88f, 535.81f, 4.66f}, //97097
    {2950.01f, 804.85f, 535.65f, 4.66f}, //97097
    {2923.85f, 771.78f, 538.59f, 4.53f}, //98919
    {2957.19f, 775.12f, 538.66f, 5.03f}, //98919
    {2923.93f, 838.52f, 536.17f, 4.66f}, //98919
    {2942.26f, 838.82f, 536.16f, 4.64f}, //98919
    {2917.46f, 772.97f, 538.55f, 4.40f}, //99033
    {2950.14f,  773.0f, 538.52f, 4.93f}, //99033
    {2921.54f, 807.65f, 535.82f, 4.67f}, //99033
    {2945.05f, 805.94f, 535.84f, 4.53f}, //99033
    {2911.42f,  775.0f, 538.55f, 4.43f}, //97365
    {2944.38f, 771.65f, 538.54f, 4.94f}, //97365
    {2919.12f, 839.14f, 536.17f, 4.74f}, //97200
    {2946.58f, 838.83f, 536.17f, 4.74f}  //97200
};

uint32 swirlingGO[11]
{
    GO_SWIRLING_POOL_1,
    GO_SWIRLING_POOL_2,
    GO_SWIRLING_POOL_3,
    GO_SWIRLING_POOL_4,
    GO_SWIRLING_POOL_5,
    GO_SWIRLING_POOL_6,
    GO_SWIRLING_POOL_7,
    GO_SWIRLING_POOL_8,
    GO_SWIRLING_POOL_9,
    GO_SWIRLING_POOL_10,
    GO_SWIRLING_POOL_11
};

std::vector<Position> brackwaterLeftPos =
{
    {2939.40f, 962.60f, 512.62f},
    {2942.39f, 959.01f, 512.62f},
    {2936.74f, 958.69f, 512.44f},
    {2940.28f, 954.87f, 512.62f},
    {2945.83f, 955.33f, 512.62f},
    {2935.46f, 953.10f, 512.62f},
    {2938.70f, 950.05f, 512.44f},
    {2944.88f, 950.54f, 512.62f},
    {2935.38f, 946.62f, 512.62f},
    {2949.86f, 946.64f, 512.62f},
    {2941.57f, 945.62f, 512.62f},
    {2939.18f, 942.02f, 512.62f},
    {2947.10f, 941.91f, 512.62f},
    {2936.93f, 938.13f, 512.62f},
    {2943.34f, 937.14f, 512.62f},
    {2950.44f, 936.89f, 512.62f},
    {2936.81f, 931.11f, 512.62f},
    {2947.02f, 931.25f, 512.62f},
    {2941.39f, 929.56f, 512.44f},
    {2936.53f, 924.82f, 512.62f},
    {2943.62f, 924.13f, 512.62f},
    {2950.87f, 923.85f, 512.62f},
    {2939.42f, 917.48f, 512.62f},
    {2946.80f, 916.83f, 512.62f}
};

std::vector<Position> brackwaterRightPos =
{
    {2925.56f, 963.48f, 512.62f},
    {2929.07f, 960.50f, 512.62f},
    {2923.64f, 958.06f, 512.62f},
    {2919.76f, 956.44f, 512.96f},
    {2928.60f, 955.48f, 512.62f},
    {2922.82f, 953.38f, 512.62f},
    {2930.63f, 950.74f, 512.62f},
    {2918.42f, 950.52f, 512.62f},
    {2925.68f, 949.56f, 512.44f},
    {2920.87f, 946.22f, 512.62f},
    {2929.98f, 945.46f, 512.62f},
    {2925.92f, 944.20f, 512.62f},
    {2917.76f, 944.13f, 512.62f},
    {2929.15f, 940.10f, 512.62f},
    {2921.97f, 939.96f, 512.62f},
    {2925.20f, 937.02f, 512.44f},
    {2916.68f, 937.24f, 512.62f},
    {2921.16f, 934.19f, 512.62f},
    {2927.87f, 932.90f, 512.62f},
    {2916.64f, 931.38f, 512.62f},
    {2923.48f, 929.93f, 512.44f},
    {2927.61f, 925.69f, 512.62f},
    {2918.18f, 925.71f, 512.62f},
    {2922.55f, 922.01f, 512.62f},
    {2913.16f, 922.54f, 512.62f},
    {2931.84f, 921.01f, 512.34f},
    {2917.70f, 919.10f, 512.54f},
    {2927.18f, 918.08f, 512.62f}
};

Position const smashPos[5] =
{
    {2947.05f, 914.22f, 513.0f},
    {2950.39f, 914.91f, 512.26f},
    {2933.61f, 914.46f, 512.38f},
    {2923.04f, 914.18f, 512.26f},
    {2915.98f, 914.39f, 512.26f}
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
};

void AddSC_boss_helya_maw()
{
    
}
