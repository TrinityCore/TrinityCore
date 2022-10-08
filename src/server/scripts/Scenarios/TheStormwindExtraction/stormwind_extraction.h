/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_STORMWIND_EXTRACTION_H
#define DEF_STORMWIND_EXTRACTION_H

enum Npcs
{
    NPC_JAINA           = 134201,
    NPC_ROKHAN          = 134038,
    NPC_THALYSSRA       = 134037,
    NPC_SAURFANG        = 134120,
    NPC_ZUL             = 134093,
    NPC_TALANJI         = 134092,
    NPC_NATHANOS        = 134039,
    NPC_GREYMANE        = 134200,

    NPC_FX_STALKER      = 134094,
    NPC_ESCAPE_STOCKADE = 139948,
};

enum Spells
{
    SPELL_TELEPORT_STOCKADE             = 269934,
    SPELL_SCENE_GENN_ARRIVES            = 264771,
    SPELL_SCENE_JAINA_AND_ZUL           = 273374,

    SPELL_ROKHAN_SOLO_STEALTH           = 86603,

    SPELL_ARCANE_CHANNELING             = 54219,
    SPELL_ARCANE_BARRIER                = 271187,
    SPELL_ARCANE_BARRIER_MOVING         = 263506,

    SPELL_CHAT_BUBBLE                   = 140812,

    SPELL_NULLIFICATION_BARRIER         = 264422,

    SPELL_TALANJI_OPEN_ARCANE_BARRIER   = 271229,

    SPELL_SCENARIO_COMPLETE             = 263950,
    SPELL_SCENARIO_COMPLETE_TELEPORT    = 263948,
};

enum GameObjects
{
    GOB_SEWER_ACCESS_GATE    = 281475,
};

enum Events
{
    SCENARIO_EVENT_STORMWIND_INFILTRATION   = 62745,
    SCENARIO_EVENT_ENTER_STOCKADE           = 62746,
    SCENARIO_EVENT_FIND_ROKHAN              = 62758,
    SCENARIO_EVENT_FREE_SAURFANG            = 62803,
    EVENT_FIND_PRISONNERS                   = 100,
    SCENARIO_EVENT_FREE_PRISONNERS          = 62811,
    EVENT_END_OF_PRISON_REACHED             = 101,
    SCENARIO_EVENT_PRISON_ESCAPE            = 62824,
};

enum CriteriaTrees
{
    CRITERIA_TREE_OPEN_SEWERS = 65350,
};

enum SummonGroups
{
    SUMMON_GROUP_LION_REST          = 10,
    SUMMON_GROUP_TALANJI_ZUL_PRISON = 11,
    SUMMON_GROUP_INSIDE_PRISON      = 20,
    SUMMON_GROUP_GUARD_ENTRANCE     = 21,
    SUMMON_GROUP_GUARD_FIRST_ROOM   = 22,
    SUMMON_GROUP_ALL_AFTER_FREED    = 30,
    SUMMON_GROUP_BATTLEMAGE         = 31,
    SUMMON_GROUP_OUTSIDE_PRISON     = 40,
    SUMMON_GROUP_CATHEDRAL_PLACE    = 50,
    SUMMON_GROUP_HARBOR             = 60,

    SUMMON_GROUP_END_HARBOR_HACKFIX = 70,
    SUMMON_GROUP_END_HARBOR_JAINA   = 80,
};

enum Conversations
{
    CONVERSATION_NATHANOS_1         = 7039,
    CONVERSATION_NATHANOS_2         = 7040,
    CONVERSATION_NATHANOS_3         = 7041,
    CONVERSATION_PRISON_ENTRANCE    = 7042,
    CONVERSATION_SAURFANG           = 7044,
    CONVERSATION_ESCORT_ARRIVED     = 9683,
    CONVERSATION_THANK_YOU_PRISON   = 7047,
    CONVERSATION_NULLIFICATION      = 7055,
    CONVERSATION_HOW_GET_OUT        = 7052,
    CONVERSATION_BEFORE_ESCAPE      = 7058,
    CONVERSATION_AFTER_ESCAPE       = 7088,
    CONVERSATION_GENN_ATTACK        = 7109,
    CONVERSATION_JAINA_END_OF_ESCAPE= 7145,
    CONVERSATION_THANKS_ZUL         = 7147,
};

/*
Position JainaSpawnPosition1 = { -8653.080078f, 904.432007f, 98.132301f, 0.805635f };
Position JainaSpawnPosition2 = { -8566.570313f, 997.429016f, 96.022499f, 0.000000f };

struct GameObjectPosition
{
    GameObjectPosition(float x, float y, float z, float o, float rotZ, float rotW) :
        Pos(x, y, z, o), Rotation(0.f, 0.f, rotZ, rotW) { }

    Position Pos;
    QuaternionData Rotation;
};

GameObjectPosition IceWallsPositions[] =
{
    { -8621.37f,   914.25f,   99.0104f,   5.41026f,   -0.422736f,   0.906253f },
    { -8452.76f,   990.917f,  96.811f,    2.23348f,    0.898675f,   0.438615f },
    { -8472.41f,   974.832f,  96.811f,    2.28748f,    0.91019f,    0.414192f },
    { -8472.77f,   959.8f,    96.3558f,   0.790681f,   0.385122f,   0.922866f },
    { -8546.13f,   988.936f,  96.7536f,   0.63382f,    0.311632f,   0.950203f },
    { -8556.80f,   1005.84f,  89.7307f,   0.63382f,    0.311632f,   0.950203f },
    { -8572.19f,   979.74f,   97.2586f,   0.627084f,   0.30843f,    0.951247f },
    { -8579.49f,   1010.6f,   96.0583f,   5.39409f,   -0.43005f,    0.902805f },
    { -8585.31f,   997.102f,  97.1700f,   0.649522f,   0.319082f,   0.947727f },
    { -8434.54f,   1003.75f,  79.1708f,   3.86788f,   -0.934785f,   0.355214f },
    { -8463.41f,   992.559f,  79.4635f,   3.88565f,   -0.931591f,   0.363508f },
    { -8481.19f,   1048.86f,  59.5312f,   4.1714f,    -0.870339f,   0.492452f },
    { -8504.15f,   1056.11f,  59.8153f,   4.64229f,   -0.731451f,   0.681894f },
    { -8528.94f,   1052.14f,  59.6034f,   5.09847f,   -0.558317f,   0.829628f },
    { -8448.32f,   1013.47f,  59.4733f,   0.474711f,   0.235133f,   0.971963f },
    { -8548.13f,   1036.82f,  59.4965f,   5.72583f,   -0.275085f,   0.961420f },
    { -8463.33f,   1032.81f,  59.4733f,   3.8785f,    -0.932886f,   0.360171f },
    { -8570.90f,   1021.26f,  96.2347f,   0.662291f,   0.325127f,   0.945670f },
};
*/
#endif
