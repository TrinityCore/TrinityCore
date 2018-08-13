/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_BLACK_ROOK_HOLD_H
#define DEF_BLACK_ROOK_HOLD_H

enum DataTypes
{
    DATA_AMALGAM_OF_SOULS           = 0,
    DATA_ILLYSANNA_RAVENCREST       = 1,
    DATA_SMASHSPITE                 = 2,
    DATA_LORD_RAVENCREST            = 3,

    DATA_MAX_ENCOUNTERS             = 4,

    DATA_ILLYSANNA_PREEVENT_LOWER   = 5,
    DATA_ILLYSANNA_PREEVENT_UPPER   = 6,

    DATA_STAIRS_BOULDER_1           = 7,
    DATA_STAIRS_BOULDER_2           = 8,
};

enum Creatures
{
    NPC_AMALGAM_OF_SOULS            = 98542,

    // Amalgam of Souls
    NPC_RESTLESS_SOUL               = 99664,

    // Illysanna Ravencrest Pre-Event
    NPC_SOUL_TORN_CHAMPION          = 98243,
    NPC_RISEN_SCOUT                 = 98691,
    NPC_RISEN_ARCHER                = 98275,
    NPC_RISEN_ARCANIST_PREEVENT     = 98280,
    NPC_COMMANDER_SHEMDAHSOHN       = 98706,

    // Smashspite the Hateful
    NPC_SMASHSPITE_THE_HATEFUL      = 98948,
    NPC_SMASHSPITE_FELBAT           = 100759,

    // Illysanna Ravencrest
    NPC_ILLYSANNA_RAVENCREST        = 98696,
    NPC_SOUL_TORN_VANGUARD          = 100485,
    NPC_RISEN_ARCANIST              = 100486,

    NPC_BOULDER                     = 111706,

    // Lord Corvaltus
    NPC_LORD_KURTALOS_RAVENCREST    = 98965, // 94923?
    NPC_LATOSIUS                    = 98970,
    NPC_DANTALIONAX                 = 99611,
    NPC_SOUL_OF_RAVENCREST          = 101054,
};

enum GameObjects
{
    GOB_DOOR_AMALGAME_ENTER_1       = 247403,
    GOB_DOOR_AMALGAME_ENTER_2       = 247406,

    GOB_DOOR_AMALGAME_ROOM_1        = 247403,
    GOB_DOOR_AMALGAME_ROOM_2        = 247404,
    GOB_DOOR_AMALGAME_ROOM_3        = 247405,
    GOB_DOOR_AMALGAME_ROOM_4        = 247406,

    GOB_DOOR_AMALGAME_EXIT          = 247407,

    GOB_DOOR_ILLYSANNA_PORTCULLIS_1 = 245079,
    GOB_DOOR_ILLYSANNA_PORTCULLIS_2 = 245080,

    GOB_DOOR_ILLYSANNA_ENTER        = 247400,
    GOB_DOOR_ILLYSANNA_EXIT_1       = 247399,
    GOB_DOOR_ILLYSANNA_EXIT_2       = 247401,

    GOB_DOOR_SMASHSPITE_ROOM        = 247402,

    GOB_DOOR_RAVENCREST_PASSAGE     = 245104,
    GOB_DOOR_RAVENCREST_ROOM        = 247498,
};

#define FIRST_BOULDER_PATH_SIZE 8
Position const firstBoulderPositions[2][FIRST_BOULDER_PATH_SIZE] =
{
    // Right Boulder path
    {
        { 3174.61f, 7313.83f, 139.81f },
        { 3169.97f, 7306.21f, 125.82f },
        { 3165.80f, 7303.97f, 122.11f },
        { 3160.73f, 7304.57f, 119.03f },
        { 3157.04f, 7307.55f, 115.01f },
        { 3154.86f, 7312.13f, 110.30f },
        { 3155.53f, 7316.91f, 105.78f },
        { 3158.11f, 7321.12f, 102.68f }
    },
    // Left Boulder path
    {
        { 3178.95f, 7312.58f, 129.81f },
        { 3173.63f, 7300.84f, 125.60f },
        { 3167.10f, 7298.92f, 122.56f },
        { 3158.34f, 7298.08f, 119.08f },
        { 3151.37f, 7303.29f, 114.75f },
        { 3148.49f, 7311.23f, 110.23f },
        { 3148.49f, 7319.23f, 106.04f },
        { 3153.75f, 7326.27f, 102.70f }
    }
};

#define SECOND_BOULDER_PATH_SIZE 24
Position const secondBoulderPositions[2][SECOND_BOULDER_PATH_SIZE] =
{
    // Right Boulder path
    {
        { 3174.89f, 7396.5f,  195.699f },
        { 3179.76f, 7396.25f, 193.481f },
        { 3184.04f, 7394.24f, 190.325f },
        { 3186.55f, 7390.7f,  186.787f },
        { 3187.7f,  7385.19f, 183.481f },
        { 3185.57f, 7380.73f, 179.369f },
        { 3181.51f, 7377.89f, 174.993f },
        { 3176.27f, 7377.57f, 170.772f },
        { 3171.04f, 7379.12f, 167.83f  },
        { 3167.75f, 7383.38f, 165.134f },
        { 3168.65f, 7389.74f, 161.938f },
        { 3170.38f, 7394.52f, 161.549f },
        { 3175.62f, 7396.71f, 161.059f },
        { 3181.44f, 7395.48f, 157.368f },
        { 3185.26f, 7392.86f, 153.812f },
        { 3187.27f, 7388.34f, 150.859f },
        { 3186.99f, 7383.71f, 147.016f },
        { 3183.91f, 7379.74f, 142.55f  },
        { 3179.19f, 7377.48f, 138.89f  },
        { 3174.67f, 7377.74f, 137.089f },
        { 3170.56f, 7380.25f, 135.407f },
        { 3168.62f, 7384.59f, 132.999f },
        { 3168.5f,  7387.51f, 131.47f  },
        { 3169.05f, 7390.25f, 129.751f }
    },
    // Left Boulder path
    {
        { 3174.95f, 7401.97f, 195.671f },
        { 3184.84f, 7401.88f, 191.964f },
        { 3191.12f, 7397.3f,  188.559f },
        { 3193.91f, 7389.24f, 185.594f },
        { 3193.26f, 7382.36f, 182.317f },
        { 3187.79f, 7373.91f, 176.792f },
        { 3180.22f, 7371.02f, 172.394f },
        { 3171.82f, 7371.11f, 169.307f },
        { 3166.38f, 7375.65f, 167.331f },
        { 3161.87f, 7383.07f, 164.484f },
        { 3162.69f, 7392.49f, 161.205f },
        { 3170.85f, 7401.16f, 161.044f },
        { 3174.8f,  7401.9f,  161.028f },
        { 3187.68f, 7399.34f, 155.076f },
        { 3190.3f,  7397.27f, 153.763f },
        { 3193.46f, 7389.39f, 150.817f },
        { 3192.88f, 7380.79f, 146.561f },
        { 3190.05f, 7376.07f, 143.989f },
        { 3181.83f, 7371.79f, 139.966f },
        { 3176.19f, 7371.03f, 138.246f },
        { 3171.82f, 7372.55f, 137.045f },
        { 3165.58f, 7376.83f, 135.446f },
        { 3162.14f, 7382.58f, 133.589f },
        { 3161.35f, 7390.89f, 130.754f },
    }
};

#endif
