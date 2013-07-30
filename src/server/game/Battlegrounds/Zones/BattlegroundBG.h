/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __BATTLEGROUNDBG_H
#define __BATTLEGROUNDBG_H

#include "Battleground.h"

enum BG_BG_Rewards
{
    BG_BG_MAP_COMPLETE,
    BG_BG_REWARD_NUM
};

enum BG_BG_WorldStates
{
    BG_BG_OP_OCCUPIED_BASES_HORDE        = 1778,
    BG_BG_OP_OCCUPIED_BASES_ALLY         = 1779,
    BG_BG_OP_RESOURCES_ALLY              = 1776,
    BG_BG_OP_RESOURCES_HORDE             = 1777,
    BG_BG_OP_RESOURCES_MAX               = 1780,
    BG_BG_OP_RESOURCES_WARNING           = 1955
};

const uint32 BG_BG_OP_NODESTATES[3] =    {1787, 1782, 1772};

const uint32 BG_BG_OP_NODEICONS[3]  =    {1843, 1846, 1845};

enum BG_BG_NodeObjectId
{
    BG_BG_OBJECTID_NODE_BANNER_0    = 208779,      // Lighthouse banner
    BG_BG_OBJECTID_NODE_BANNER_1    = 208782,      // Mine banner
    BG_BG_OBJECTID_NODE_BANNER_2    = 208785       // Waterworks banner
};

enum BG_BG_ObjectType
{
    BG_BG_OBJECT_BANNER_NEUTRAL          = 0,
    BG_BG_OBJECT_BANNER_CONT_A           = 1,
    BG_BG_OBJECT_BANNER_CONT_H           = 2,
    BG_BG_OBJECT_BANNER_ALLY             = 3,
    BG_BG_OBJECT_BANNER_HORDE            = 4,
    BG_BG_OBJECT_AURA_ALLY               = 5,
    BG_BG_OBJECT_AURA_HORDE              = 6,
    BG_BG_OBJECT_AURA_CONTESTED          = 7,
    //gates
    BG_BG_OBJECT_GATE_A                  = 25,
    BG_BG_OBJECT_GATE_H                  = 26,
    //buffs
    BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE    = 28,
    BG_BG_OBJECT_REGENBUFF_LIGHTHOUSE    = 29,
    BG_BG_OBJECT_BERSERKBUFF_LIGHTHOUSE  = 30,
    BG_BG_OBJECT_SPEEDBUFF_WATERWORKS    = 31,
    BG_BG_OBJECT_REGENBUFF_WATERWORKS    = 32,
    BG_BG_OBJECT_BERSERKBUFF_WATERWORKS  = 33,
    BG_BG_OBJECT_SPEEDBUFF_MINE          = 34,
    BG_BG_OBJECT_REGENBUFF_MINE          = 35,
    BG_BG_OBJECT_BERSERKBUFF_MINE        = 36,
    BG_BG_OBJECT_MAX                     = 37
};

/* Object id templates from DB */
enum BG_BG_ObjectTypes
{
    BG_BG_OBJECTID_BANNER_A              = 208673,
    BG_BG_OBJECTID_BANNER_CONT_A         = 208763,
    BG_BG_OBJECTID_BANNER_H              = 208748,
    BG_BG_OBJECTID_BANNER_CONT_H         = 208733,

    BG_BG_OBJECTID_AURA_A                = 180100,
    BG_BG_OBJECTID_AURA_H                = 180101,
    BG_BG_OBJECTID_AURA_C                = 180102,

    BG_BG_OBJECTID_GATE_A                = 207177,
    BG_BG_OBJECTID_GATE_H                = 207178
};

enum BG_BG_Timers
{
    BG_BG_FLAG_CAPTURING_TIME            = 60000
};

enum BG_BG_Score
{
    BG_BG_WARNING_NEAR_VICTORY_SCORE     = 1800,
    BG_BG_MAX_TEAM_SCORE                 = 2000
};

/* Do not change below, or this thing will go boom! */
enum BG_BG_BattlegroundNodes
{
    BG_BG_NODE_LIGHTHOUSE       = 0,
    BG_BG_NODE_WATERWORKS       = 1,
    BG_BG_NODE_MINE             = 2,

    BG_BG_DYNAMIC_NODES_COUNT   = 3,                        // Dynamic nodes that can be captured

    BG_BG_SPIRIT_ALIANCE        = 3,
    BG_BG_SPIRIT_HORDE          = 4,

    BG_BG_ALL_NODES_COUNT       = 5                         // All nodes (dynamic and static)
};

enum BG_BG_NodeStatus
{
    BG_BG_NODE_TYPE_NEUTRAL             = 0,
    BG_BG_NODE_TYPE_CONTESTED           = 1,
    BG_BG_NODE_STATUS_ALLY_CONTESTED    = 1,
    BG_BG_NODE_STATUS_HORDE_CONTESTED   = 2,
    BG_BG_NODE_TYPE_OCCUPIED            = 3,
    BG_BG_NODE_STATUS_ALLY_OCCUPIED     = 3,
    BG_BG_NODE_STATUS_HORDE_OCCUPIED    = 4
};

enum BG_BG_Sounds
{
    BG_BG_SOUND_NODE_CLAIMED            = 8192,
    BG_BG_SOUND_NODE_CAPTURED_ALLIANCE  = 8173,
    BG_BG_SOUND_NODE_CAPTURED_HORDE     = 8213,
    BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE = 8212,
    BG_BG_SOUND_NODE_ASSAULTED_HORDE    = 8174,
    BG_BG_SOUND_NEAR_VICTORY            = 8456
};

enum BG_BG_Objectives
{
    BG_OBJECTIVE_ASSAULT_BASE           = 122,
    BG_OBJECTIVE_DEFEND_BASE            = 123
};

#define BG_BG_NotBGBGWeekendHonorTicks          330
#define BG_BG_BGBGWeekendHonorTicks             200
#define BG_BG_NotBGBGWeekendReputationTicks     200
#define BG_BG_BGBGWeekendReputationTicks        150

#define BG_EVENT_START_BATTLE               5254 // Achievement: Newbs to Plowshares

// x, y, z, o
const float BG_BG_NodePositions[BG_BG_DYNAMIC_NODES_COUNT][4] =
{
    {1057.856934f, 1278.269165f, 2.91f, 1.903034f},   // Lighthouse
    {980.1835f, 947.8692f, 13.998f, 5.9015f},         // Waterwork
    {1251.010f, 958.3939f, 5.680f, 2.7698f}           // Mine
};

// x, y, z, o, rot0, rot1, rot2, rot3
const float BG_BG_DoorPositions[2][8] =
{
    {918.876f, 1336.56f, 27.6195f, 2.77481f, 0.0f, 0.0f, 0.983231f, 0.182367f},
    {1396.15f, 977.014f, 7.43169f, 6.27043f, 0.0f, 0.0f, 0.006378f, -0.99998f}
};

// Tick intervals and given points: case 0,1,2,3 captured nodes
const uint32 BG_BG_TickIntervals[4] = {0, 12000, 6000, 1000};
const uint32 BG_BG_TickPoints[4] = {0, 10, 10, 30};

// WorldSafeLocs ids for 3 nodes, and for ally, and horde starting location
const uint32 BG_BG_GraveyardIds[BG_BG_ALL_NODES_COUNT] = {1735, 1736, 1738, 1739, 1740};

// x, y, z, o
const float BG_BG_BuffPositions[BG_BG_DYNAMIC_NODES_COUNT][4] =
{
    {1063.57f, 1313.42f, 4.91f, 4.14f},        // Lighthouse
    {961.830f, 977.03f, 14.15f, 4.55f},        // Waterworks
    {1193.09f, 1017.46f, 7.98f, 0.24f},        // Mine
};

// x, y, z, o
const float BG_BG_SpiritGuidePos[BG_BG_ALL_NODES_COUNT][4] =
{
    {1034.82f, 1335.58f, 12.0095f, 5.15f},     // Lighthouse
    {887.578f, 937.337f, 23.7737f, 0.45f},     // Waterworks
    {1252.23f, 836.547f, 27.7895f, 1.60f},     // Mine
    {908.274f, 1338.6f, 27.6449f, 5.95f},      // Alliance
    {1401.38f, 977.125f, 7.44215f, 3.04f},     // Horde
};

struct BG_BG_BannerTimer
{
    uint32 timer;
    uint8  type;
    uint8  teamIndex;
};

struct BattlegroundBGScore : public BattlegroundScore
{
    BattlegroundBGScore(): BasesAssaulted(0), BasesDefended(0) { }
    ~BattlegroundBGScore() { }
    uint32 BasesAssaulted;
    uint32 BasesDefended;
};

class BattlegroundBG : public Battleground
{
    public:
        BattlegroundBG();
        ~BattlegroundBG();

        void AddPlayer(Player* player);
        void StartingEventCloseDoors();
        void StartingEventOpenDoors();
        void RemovePlayer(Player* player, uint64 guid, uint32 team);
        void HandleAreaTrigger(Player* Source, uint32 Trigger);
        bool SetupBattleground();
        void Reset();
        void EndBattleground(uint32 winner);
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);

        /* Score-keeping */
        void UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor = true);

        void FillInitialWorldStates(WorldPacket& data);

        /* Nodes occupying */
        void EventPlayerClickedOnFlag(Player* source, GameObject* target_obj);

        /* achievement req. */
        bool IsAllNodesConrolledByTeam(uint32 team) const;
        bool IsTeamScores500Disadvantage(uint32 team) const { return m_TeamScores500Disadvantage[GetTeamIndexByTeamId(team)]; }

        uint32 GetPrematureWinner();
    private:
        void PostUpdateImpl(uint32 diff);
        /* GameObject spawning/removing */
        void _CreateBanner(uint8 node, uint8 type, uint8 teamIndex, bool delay);
        void _DelBanner(uint8 node, uint8 type, uint8 teamIndex);
        void _SendNodeUpdate(uint8 node);

        /* Creature spawning/removing */
        // TODO: need to get the peons spawns scripted
        void _NodeOccupied(uint8 node, Team team);
        void _NodeDeOccupied(uint8 node);

        int32 _GetNodeNameId(uint8 node);

        /* Nodes info:
            0: neutral
            1: ally contested
            2: horde contested
            3: ally occupied
            4: horde occupied     */
        uint8               m_Nodes[BG_BG_DYNAMIC_NODES_COUNT];
        uint8               m_prevNodes[BG_BG_DYNAMIC_NODES_COUNT];
        BG_BG_BannerTimer   m_BannerTimers[BG_BG_DYNAMIC_NODES_COUNT];
        uint32              m_NodeTimers[BG_BG_DYNAMIC_NODES_COUNT];
        uint32              m_lastTick[BG_TEAMS_COUNT];
        uint32              m_HonorScoreTics[BG_TEAMS_COUNT];
        uint32              m_ReputationScoreTics[BG_TEAMS_COUNT];
        bool                m_IsInformedNearVictory;
        uint32              m_HonorTics;
        uint32              m_ReputationTics;
        // need for achievements
        bool                m_TeamScores500Disadvantage[BG_TEAMS_COUNT];
};
#endif
