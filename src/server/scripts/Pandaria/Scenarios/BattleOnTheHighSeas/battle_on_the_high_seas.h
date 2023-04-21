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

#ifndef BATTLE_ON_THE_HIGH_SEAS_H_
#define BATTLE_ON_THE_HIGH_SEAS_H_

const Position transportCannonsPos[4] =
{
    { 2334.34f, -4210.11f, 11.17f, 3.59f },
    { 2450.68f, -4096.43f, 14.72f, 0.00f },
    { 2446.24f, -4082.65f,  8.98f, 0.18f },
    { 2176.30f, -4230.66f, 14.13f, 3.34f },
};

const Position firstAllianceAssaultSpawnPos[3] =
{
    { 2452.60f, -4100.57f, 15.01f, 0.17f },
    { 2459.27f, -4091.13f, 14.76f, 5.42f },
    { 2446.74f, -4080.98f,  9.04f, 0.32f },
};

const Position zipLinePath[7] =
{
    { 2310.424f, -4221.281f, 13.63178f, 0.0f },
    { 2277.094f, -4218.917f, 22.59995f, 0.0f },
    { 2268.356f, -4178.823f, 29.63214f, 0.0f },
    { 2276.799f, -4161.283f, 29.47711f, 0.0f },
    { 2291.351f, -4153.516f, 26.58501f, 0.0f },
    { 2320.023f, -4145.88f,  21.98498f, 0.0f },
    { 2339.795f, -4139.736f, 17.66394f, 0.0f },
};

const Position zipLineBackPath[5] =
{
    { 2359.295f, -4123.663f, 16.44701f, 0.0f },
    { 2390.149f, -4136.63f , 22.44889f, 0.0f },
    { 2389.448f, -4167.809f, 22.44889f, 0.0f },
    { 2359.552f, -4203.318f, 17.36462f, 0.0f },
    { 2334.715f, -4210.05f , 12.28398f, 0.0f },
};

const Position netScalePos[4] =
{
    { 2444.25f, -4082.86f,  8.78f, 0.14f },
    { 2343.30f, -4103.92f, 21.85f, 3.78f },
    { 2312.62f, -4221.86f, 11.28f, 0.48f },
    { 2165.21f, -4201.07f, 21.80f, 6.12f },
};

const Position parketSumPos = {2347.14f, -4138.11f, 14.45f, 0.32f};

enum Data
{
    DATA_BOARDING_PARTY,
    DATA_EXPLOSIVES_ACQUICITION,
    DATA_SMITHEREENS,
    DATA_DEFEAT_THE_ADMIRAL,

    // Misc
    FACTION_DATA,
    HORDE_ASSAULT_DATA,
    EXPLOSIVES_COUNT_DATA,
    PLANT_COUNT_DATA,
};

enum Creatures
{
    NPC_BARREL_OF_ORANGES        = 71054,
    
    // Alliance
    NPC_LIEUTENANT_PARKER        = 71326,
    NPC_ALLIANCE_CANNONEER       = 69194,
    NPC_ALLIANCE_SWASHBUCKLER    = 69196,
    NPC_ALLIANCE_OFFICER         = 69197,
    NPC_LIEUTENANT_FUSEBLAST     = 71328,
    NPC_LIEUTENANT_FIZZBOIL      = 71330,
    NPC_LIUTENANT_BOLTBLASTER    = 71329,
    NPC_ADMIRAL_HODGSON          = 71327,
    NPC_ALLIANCE_DECKHAND        = 71312,

    // Horde
    NPC_ADMIRAL_HAGMAN           = 71436,
    NPC_HORDE_SQUALSHAPER        = 71367,
    NPC_HORDE_CANNONEER          = 67360,
    NPC_HORDE_SWASHBUCKLER       = 67361,
    NPC_HORDE_CAPTAIN            = 71445,

    // Misc
    NPC_FIRE_BUNNY               = 67392,
    NPC_SAIL_FIRE_BUNNY          = 67393,
    NPC_EXPLOSIVE_BARREL_TRIGGER = 70755,
    NPC_CANNON_EXPLODER          = 67341,
    NPC_TRANSPORT_CANNON_H_A_1   = 71331,
    NPC_TRANSPORT_CANNON_A_H_1   = 71364,
    NPC_TRANSPORT_CANNON_A_H_2   = 71365,
    NPC_TRANSPORT_CANNON_A_H_3   = 71366,
    NPC_TRANSPORT_CANNON_2_H_A_1 = 71167,
    NPC_PLANT_EXPLOSIVES         = 67394,
    NPC_GENERAL_BUNNY_JMF        = 45979, // using for targeting
    NPC_ZIP                      = 70779,
    NPC_ROPE_ANCHOR              = 67328,
    NPC_BOMB                     = 67403,
    NPC_BARREL_FUSE_STALKER      = 70754,
    NPC_FUSE                     = 70754,
    NPC_EXPLOSIVE_BARREL         = 71106,
    NPC_EMOTE_BUNNY              = 67411,
    NPC_NET_CLIMBER_1            = 67331,
};

enum GameObjects
{
    GO_NET                        = 216078,
    GO_NET_2                      = 216076,
    GO_ROPE_LADDER                = 216077,
    GO_ROPE_PILE_TO_ALLIANCE_SHIP = 219270,
    GO_ROPE_PILE_TO_HORDE_SHIP    = 216074,
    GO_RAPIER                     = 219304,
};

enum ExtraSpells
{
    SPELL_CANNON_BARRAGE       = 142058,
    SPELL_BOMBS_AWAY           = 141440,
    SPELL_BOMBS_AWAY_EFF       = 132938,
    SPELL_BOMBS_AWAY_TARGETING = 132935,
    SPELL_SUMMON_ROPE_SWING    = 141133,
};

enum Yells
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
    TALK_SPECIAL_10,
    TALK_SPECIAL_11,
    TALK_SPECIAL_12,
    TALK_SPECIAL_13,
    TALK_SPECIAL_14,
    TALK_SPECIAL_15,
    TALK_SPECIAL_16,
    TALK_SPECIAL_17,
    TALK_SPECIAL_18,
};

enum Actions
{
    ACTION_START_INTRO,
    ACTION_EXPLOSIVE_SHIP,
    ACTION_BOMBS_AWAY,
    ACTION_BOMBS_AWAY_REMOVE,
};

enum Criteries
{
    CRITERIA_EXPLOSIVES_ACQUIRED             = 22261,
    CRITERIA_EXPLOSIVES_PRIMED               = 22262,
    CRITERIA_ALLIANCE_SHIP_DESTROYED         = 22258,
    CRITERIA_DEFEAT_ADMIRAL_HODGSON          = 23336,

    // Criteria Tree
    CRITERIA_TREE_ID_BOARDING_PARTY_HORDE    = 32774,
    CRITERIA_TREE_ID_SMITHEREENS_HORDE       = 32778,
    CRITERIA_TREE_ID_DEFEAT_ADMIRAL_HORDE    = 32781,
    CRITERIA_TREE_ID_BOARDING_PARTY_ALLIANCE = 30721,
    CRITERIA_TREE_ID_SMITHEREENS_ALLIANCE    = 30723,
    CRITERIA_TREE_ID_DEFEAT_ADMIRAL_ALLIANCE = 30733,
};

enum Scenarios
{
    SCENARIO_ID_NAVAL_BATTLE_HORDE    = 239,
    SCENARIO_ID_NAVAL_BATTLE_ALLIANCE = 182,
};

enum Worldstates
{
    WORLDSTATE_KEEP_THOSE_BOMBS_AWAY = 14110,
};

const std::multimap<uint32, Position> invSecondAssaultSpawnPos =
{
    { NPC_ALLIANCE_CANNONEER,    { 2332.27f, -4224.18f, 17.10f, 0.0f } },
    { NPC_ALLIANCE_SWASHBUCKLER, { 2328.62f, -4234.12f, 17.39f, 0.0f } },
    { NPC_ALLIANCE_OFFICER,      { 2325.54f, -4227.70f, 17.07f, 0.0f } },
    { NPC_ALLIANCE_CANNONEER,    { 2322.14f, -4211.83f, 11.40f, 0.0f } },
};

#endif // BATTLE_ON_THE_HIGH_SEAS_H_