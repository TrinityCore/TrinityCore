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

#ifndef ASSAULT_ON_ZANVESS_H_
#define ASSAULT_ON_ZANVESS_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define CHAPTERS 4

const Position HeartOfZanvessTele = { -926.26f, 4270.08f, 1.33f, 2.96f };

const Position MoveToBattle[5] =
{
    { -1399.97f, 3933.59f, 19.25f,  1.30f },
    { -1399.54f, 4206.26f, 34.85f,  2.00f },
    { -1690.22f, 4279.01f, 45.42f,  2.90f },
    { -1800.25f, 4356.91f, 36.15f,  2.12f },
    { -1784.78f, 4540.19f, 118.87f, 1.12f },
};

const Position MoveToBattleforAlliance[4] =
{
    {  -980.94f, 4296.53f, 149.50f, 3.51f },
    { -1220.60f, 4271.87f, 164.99f, 3.26f },
    { -1508.55f, 4280.47f, 133.32f, 3.06f },
    { -1646.66f, 4394.59f, 138.35f, 2.42f },
};

const Position moveToSecondTowers[2] =
{
    { -1729.63f, 4673.83f, 150.39f, 1.00f },
    { -1637.30f, 4875.82f, 142.73f, 5.92f },
};

const Position moveToLastTowers[3] =
{
    { -1471.88f, 4975.08f, 134.28f, 0.25f },
    { -1325.82f, 4924.02f, 127.72f, 5.90f },
    { -1249.85f, 4863.99f, 127.20f, 0.0f },
};

const Position SwarmSpawnPoints[2] =
{
    { -1211.59f, 4584.07f, 121.95f, 3.31f },
    { -1242.12f, 4533.93f, 125.03f, 1.79f },
};

const Position beachPath[4] =
{
    { -1154.95f, 4792.13f, 148.95f, 5.16f },
    { -1079.66f, 4565.90f, 127.38f, 5.03f },
    { -954.77f,  4434.77f,  84.66f, 5.47f },
    { -987.16f,  4284.31f,  12.17f, 4.48f },
};

enum eData
{
    DATA_ASSAULT_ON_ZANVESS  = 1,
    DATA_DEFENSES_OF_ZANVESS = 2,
    DATA_HEART_OF_ZANVESS    = 3,
    DATA_WEAPON_OF_ZANVESS   = 4,
    DATA_FACTION,
    DATA_TELVRAK_LINKED,
};

enum eSpells
{
    SPELL_ISLAND_SHIELD       = 132675,
    SPELL_SHIELD_BEAM         = 132685,
    SPELL_STRAFING_RAN        = 133676,
    SPELL_STRAFING_RAN_MISSLE = 133714,
    SPELL_PROTECTIVE_SHELL    = 133615,
};

enum eCreatures
{
    NPC_BOMBER                 = 68153,
    NPC_BOMBER_ALI             = 67828,
    NPC_SONIC_CONTROL_TOWER    = 67279,
    NPC_SONIC_CONTROL_TOWER_2  = 67788,
    NPC_ZANTHIK_SWARMER        = 67887,
    NPC_ZANTHIK_SLASHER        = 67809,
    NPC_ZANTHIK_AMBERMANCER    = 62838,
    NPC_ZANTHIK_BRUTALIZER     = 67774,
    NPC_COMMANDER_TELVRAK      = 67879,
    NPC_ZARTHIK_GUARDIAN       = 67710,

    // Aliance
    NPC_SKYFIRE_GYROCOPTER     = 68115,
    NPC_SKYFIRE_GYRO_VEHICLE   = 68849,
    NPC_7TH_LEGION_INFILTRATOR = 67727,
    NPC_7TH_LIGION_PRIEST      = 67892,
    NPC_TEAM_LEADER_SCOOTER    = 67810,
    NPC_SKY_GENERAL_RODGER     = 68828,

    // Horde
    NPC_REAR_ADMIRAL_ZIGG      = 67799,
    NPC_NALLEY                 = 68831,
    NPC_KORKRON_GUNSHIP        = 67275,
    NPC_KORKRON_INFILTRATOR    = 68141,
    NPC_KORKRON_PRIEST         = 68142,
    NPC_SQUAD_LEADER_BOSH      = 68143,
                               
    // Triggers                
    NPC_SHIELD_CHANNEL_POINT   = 68105,
    NPC_SLG_GENERIC_MOP        = 63420,
    NPC_SCENARIO_CONTROLLER    = 67272,
    NPC_STRAFING_RAN           = 67838,
};

enum eActions
{
    ACTION_WHIRLWIND,
    ACTION_DEVASTATING_SMASH,
    ACTION_TELVRAK_ASSAULT,
    ACTION_SWORD,
    ACTION_DAGGERS,
    ACTION_BEACH,
    ACTION_NALLEY_DEFENDERS,
    ACTION_FIRST_TOWER_OFFENSIVE,
    ACTION_SECOND_TOWER_OFFENSIVE,
    ACTION_LAST_TOWER_OFFENSIVE,
    ACTION_MOVE_TO_ISLAND,
};

enum eTypes
{
    TYPE_SWAP_WEAPON,
};

enum eTalks
{
    TALK_INTRO,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_5,
    TALK_SPECIAL_6,
    TALK_SPECIAL_7,
    TALK_SPECIAL_8,
    TALK_SPECIAL_9,
};

enum eTypeWeapons
{
    TYPE_KLAXXI_SWORD  = 89398,
    TYPE_KLAXXI_DAGGER = 89392,
};

enum worldstates
{
    WORLDSTATE_FOR_THE_SWARM = 13120,
};

enum Criteries
{
    // Horde (we cannot yet switch it for alliance tables [same issue like isle of thunder scenarios])
    CRITERIA_KYPARITE_SONIC_TOWER          = 22295,
    CRITERIA_WHISPERING_STONES_SONIC_TOWER = 22296,
    CRITERIA_VENOMSTING_PITS_SONIC_TOWER   = 22297,
    CRITERIA_COMANDER_SCOOTER              = 22300,
    CRITERIA_REACH_HEART_OF_ZANVESS        = 22301,
    CRITERIA_DEFEAT_COMMANDER_TELVRAK      = 22299,
};

const std::vector<uint32> AssaultZanthik=
{
    NPC_ZANTHIK_SLASHER,
    NPC_ZANTHIK_AMBERMANCER
};

const std::vector<uint32> Assault7tdLegion=
{
    NPC_7TH_LEGION_INFILTRATOR,
    NPC_7TH_LIGION_PRIEST,
};

#endif // ASSAULT_ON_ZANVESS_H_