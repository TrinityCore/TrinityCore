/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef __BATTLEGROUNDBFG_H
#define __BATTLEGROUNDBFG_H

#include "Battleground.h"
#include "BattlegroundScore.h"

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates;
    }
}

enum BG_BFG_WorldStates
{
    BG_BFG_OP_OCCUPIED_BASES_HORDE  = 1778,
    BG_BFG_OP_OCCUPIED_BASES_ALLY   = 1779,
    BG_BFG_OP_RESOURCES_ALLY        = 1776,
    BG_BFG_OP_RESOURCES_HORDE       = 1777,
    BG_BFG_OP_RESOURCES_MAX         = 1780,
    BG_BFG_OP_RESOURCES_WARNING     = 1955
};

const uint32 BG_BFG_OP_NODESTATES[3]    = { 1767, 1782, 1772 };
const uint32 BG_BFG_OP_NODEICONS[3]     = { 1842, 1846, 1845 };

enum BG_BFG_NodeObjectId
{
    BG_BFG_OBJECTID_NODE_BANNER_0     = 208779, // Lighthouse banner
    BG_BFG_OBJECTID_NODE_BANNER_1     = 208782, // Mine banner
    BG_BFG_OBJECTID_NODE_BANNER_2     = 208785  // Waterworks banner
};

enum BG_BFG_ObjectType
{
    BG_BFG_OBJECT_BANNER_NEUTRAL            = 0,
    BG_BFG_OBJECT_BANNER_CONT_A             = 1,
    BG_BFG_OBJECT_BANNER_CONT_H             = 2,
    BG_BFG_OBJECT_BANNER_ALLY               = 3,
    BG_BFG_OBJECT_BANNER_HORDE              = 4,
    BG_BFG_OBJECT_AURA_ALLY                 = 5,
    BG_BFG_OBJECT_AURA_HORDE                = 6,
    BG_BFG_OBJECT_AURA_CONTESTED            = 7,
    //gates
    BG_BFG_OBJECT_GATE_A                    = 40,
    BG_BFG_OBJECT_GATE_H                    = 41,
    //buffs
    BG_BFG_OBJECT_SPEEDBUFF_LIGHTHOUSE      = 42,
    BG_BFG_OBJECT_REGENBUFF_LIGHTHOUSE      = 43,
    BG_BFG_OBJECT_BERSERKBUFF_LIGHTHOUSE    = 45,
    BG_BFG_OBJECT_SPEEDBUFF_WATERWORKS      = 46,
    BG_BFG_OBJECT_REGENBUFF_WATERWORKS      = 47,
    BG_BFG_OBJECT_BERSERKBUFF_WATERWORKS    = 48,
    BG_BFG_OBJECT_SPEEDBUFF_MINE            = 49,
    BG_BFG_OBJECT_REGENBUFF_MINE            = 50,
    BG_BFG_OBJECT_BERSERKBUFF_MINE          = 51,
    BG_BFG_OBJECT_MAX                       = 52
};

enum BG_BFG_ObjectTypes
{
    BG_BFG_OBJECTID_BANNER_A            = 208673,
    BG_BFG_OBJECTID_BANNER_CONT_A       = 208763,
    BG_BFG_OBJECTID_BANNER_H            = 208748,
    BG_BFG_OBJECTID_BANNER_CONT_H       = 208733,

    BG_BFG_RBG_OBJECTID_BANNER_A        = 208673, //406012,
    BG_BFG_RBG_OBJECTID_BANNER_CONT_A   = 208763, //406013,
    BG_BFG_RBG_OBJECTID_BANNER_H        = 208748, //406014,
    BG_BFG_RBG_OBJECTID_BANNER_CONT_H   = 208733, //406015,

    BG_BFG_OBJECTID_AURA_A              = 180100,
    BG_BFG_OBJECTID_AURA_H              = 180101,
    BG_BFG_OBJECTID_AURA_C              = 180102,

    BG_BFG_OBJECTID_GATE_A              = 207177,
    BG_BFG_OBJECTID_GATE_H              = 207178
};

enum BG_BFG_BattlegroundBuffObjects
{
    // Sniffed
    BG_OBJECTID_FOODBUFF_ENTRY  = 180145, // Mine

};

enum BG_BFG_Timers
{
    BG_BFG_FLAG_CAPTURING_TIME = 60000
};

enum BG_BFG_Score
{
    BG_BFG_WARNING_NEAR_VICTORY_SCORE   = 1800,
    BG_BFG_MAX_TEAM_SCORE               = 2000
};

/* Do not change below, or this thing will go boom! */
enum BG_BFG_BattlegroundNodes
{
    BG_BFG_NODE_LIGHTHOUSE      = 0,
    BG_BFG_NODE_WATERWORKS      = 1,
    BG_BFG_NODE_MINE            = 2,

    BG_BFG_DYNAMIC_NODES_COUNT  = 3, // Dynamic nodes that can be captured

    BG_BFG_SPIRIT_ALIANCE       = 3,
    BG_BFG_SPIRIT_HORDE         = 4,

    BG_BFG_ALL_NODES_COUNT      = 5 // All nodes (dynamic and static)
};

enum BG_BFG_BroadcastTexts
{
    BG_BFG_TEXT_ALLIANCE_NEAR_VICTORY   = 63126,
    BG_BFG_TEXT_HORDE_NEAR_VICTORY      = 63128
};

enum BG_BFG_NodeStatus
{
    BG_BFG_NODE_TYPE_NEUTRAL                = 0,
    BG_BFG_NODE_TYPE_CONTESTED              = 1,
    BG_BFG_NODE_STATUS_ALLY_CONTESTED       = 1,
    BG_BFG_NODE_STATUS_HORDE_CONTESTED      = 2,
    BG_BFG_NODE_TYPE_OCCUPIED               = 3,
    BG_BFG_NODE_STATUS_ALLY_OCCUPIED        = 3,
    BG_BFG_NODE_STATUS_HORDE_OCCUPIED       = 4
};

enum BG_BFG_Sounds
{
    BG_BFG_SOUND_NODE_CLAIMED               = 8192,
    BG_BFG_SOUND_NODE_CAPTURED_ALLIANCE     = 8173,
    BG_BFG_SOUND_NODE_CAPTURED_HORDE        = 8213,
    BG_BFG_SOUND_NODE_ASSAULTED_ALLIANCE    = 8212,
    BG_BFG_SOUND_NODE_ASSAULTED_HORDE       = 8174,
    BG_BFG_SOUND_NEAR_VICTORY               = 8456
};

enum BG_BFG_Objectives
{
    BG_OBJECTIVE_ASSAULT_BASE   = 122,
    BG_OBJECTIVE_DEFEND_BASE    = 123,
    BFG_OBJECTIVE_ASSAULT_BASE  = 370,
    BFG_OBJECTIVE_DEFEND_BASE   = 371,
};

/* Holiday/Reg Honor/Rep gains */
#define BG_BFG_NotBGWeekendHonorTicks   330
#define BG_BFG_BGWeekendHonorTicks      200

#define BG_EVENT_START_BATTLE 5254 // Achievement: Newbs to Plowshares

struct BFGNodeInfo
{
    uint32 NodeId;
    uint32 TextAllianceAssaulted;
    uint32 TextHordeAssaulted;
    uint32 TextAllianceTaken;
    uint32 TextHordeTaken;
    uint32 TextAllianceDefended;
    uint32 TextHordeDefended;
    uint32 TextAllianceClaims;
    uint32 TextHordeClaims;
};

BFGNodeInfo const BFGNodes[BG_BFG_DYNAMIC_NODES_COUNT] =
{
    { BG_BFG_NODE_LIGHTHOUSE, 45903, 45904, 45905, 45906, 45907, 45908, 45909, 45910 },
    { BG_BFG_NODE_WATERWORKS, 45887, 45888, 45889, 45890, 45891, 45892, 45893, 45894 },
    { BG_BFG_NODE_MINE,       45895, 45896, 45897, 45898, 45899, 45900, 45901, 45902 },
};

Position const BG_BFG_NodePositions[BG_BFG_DYNAMIC_NODES_COUNT] =
{
    { 1057.91f, 1278.33f, 3.27763f, 4.97419f  }, // Lighthouse
    { 980.08f,  948.707f, 12.7478f, 2.740162f }, // Waterworks
    { 1251.02f, 958.359f, 5.67407f, 2.775069f }, // Mine
};

// x, y, z, o, rot0, rot1, rot2, rot3
const float BG_BFG_DoorPositions[2][8] =
{
    { 918.3906f, 1336.641f, 27.4252f, 2.844883f, 0.0f, 0.0f, 0.9890156f,   0.1478114f }, // Alliance Gate
    { 1395.97f,  977.0903f, 7.63597f, 6.274459f, 0.0f, 0.0f, -0.00436306f, 0.9999905f }, // Horde Gate
};

const uint32 BG_BFG_TickIntervals[4] = { 0, 12000, 6000, 1000 };
const uint32 BG_BFG_TickPoints[4] = { 0, 10, 10, 30 };

//Light, Water, Mine, Ally, Horde
const uint32 BG_BFG_GraveyardIds[BG_BFG_ALL_NODES_COUNT] = { 1736, 1738, 1735, 1740, 1739 };

Position const BG_BFG_SpiritGuidePos[BG_BFG_ALL_NODES_COUNT] =
{
    // TODO: sniff correct locations
    { 1034.82f, 1335.58f, 12.0095f, 5.15f }, // Lighthouse
    { 887.578f, 937.337f, 23.7737f, 0.45f }, // Waterworks
    { 1252.23f, 836.547f, 27.7895f, 1.60f }, // Mine
    { 908.274f, 1338.6f, 27.6449f, 5.95f  }, // Alliance
    // Sniffed
    { 1407.43f, 977.115f, 7.525484f, 3.141593f }, // Horde
};

const float BG_BFG_BuffPositions[BG_BFG_DYNAMIC_NODES_COUNT][4] =
{
    // TODO: sniff correct locations
    { 1063.57f, 1313.42f, 4.91f, 4.14f },       // Lighthouse
    { 961.830f, 977.03f, 14.15f, 4.55f },       // Waterworks
    // Sniffed
    { 1195.73f, 1020.3f, 7.97874f, 5.777041f }  // Mine
};

struct BG_BFG_BannerTimer
{
    uint32  timer;
    uint8   type;
    uint8   teamIndex;
};

class BattlegroundBFGScore final : public BattlegroundScore
{
    friend class BattlegroundBFG;

    protected:
        BattlegroundBFGScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid, team), BasesAssaulted(0), BasesDefended(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_BASES_ASSAULTED:
                    BasesAssaulted += value;
                    break;
                case SCORE_BASES_DEFENDED:
                    BasesDefended += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data, ByteBuffer& content) final override;

        uint32 GetAttr1() const final override { return BasesAssaulted; }
        uint32 GetAttr2() const final override { return BasesDefended; }

        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattlegroundBFG : public Battleground
{
    public:
        BattlegroundBFG();
        ~BattlegroundBFG();

        void AddPlayer(Player* player) override;
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;
        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* Source, uint32 Trigger) override;
        bool SetupBattleground() override;
        void Reset() override;
        void EndBattleground(uint32 winner) override;
        WorldSafeLocsEntry const* GetClosestGraveyard(Player* player) override;

        /* Scorekeeping */
        bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;

        /* Nodes occupying */
        void EventPlayerClickedOnFlag(Player* source, GameObject* target_obj) override;

        uint32 GetPrematureWinner() override;

    private:
        void PostUpdateImpl(uint32 diff) override;
        /* Gameobject spawning/despawning */
        void _CreateBanner(uint8 node, uint8 type, uint8 teamIndex, bool delay);
        void _DelBanner(uint8 node, uint8 type, uint8 teamIndex);
        void _SendNodeUpdate(uint8 node);

        /* Creature spawning/despawning */
        /// @todo working, scripted peons spawning
        void _NodeOccupied(uint8 node, Team team);
        void _NodeDeOccupied(uint8 node);

        /* Nodes info:
        * 0: neutral
        * 1: ally contested
        * 2: horde contested
        * 3: ally occupied
        * 4: horde occupied
        */

        uint8                   m_Nodes[BG_BFG_DYNAMIC_NODES_COUNT];
        uint8                   m_prevNodes[BG_BFG_DYNAMIC_NODES_COUNT];
        BG_BFG_BannerTimer      m_BannerTimers[BG_BFG_DYNAMIC_NODES_COUNT];
        uint32                  m_NodeTimers[BG_BFG_DYNAMIC_NODES_COUNT];
        uint32                  m_lastTick[BG_TEAMS_COUNT];
        uint32                  m_HonorScoreTics[BG_TEAMS_COUNT];
        bool                    m_IsInformedNearVictory;
        uint32                  m_HonorTics;
        // need for achievements
        bool                    m_TeamScores500Disadvantage[BG_TEAMS_COUNT];
};

#endif
