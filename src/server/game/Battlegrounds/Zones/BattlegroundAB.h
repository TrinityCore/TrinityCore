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

#ifndef __BATTLEGROUNDAB_H
#define __BATTLEGROUNDAB_H

#include "Battleground.h"
#include "Object.h"

enum BG_AB_WorldStates
{
    BG_AB_WS_OCCUPIED_BASES_HORDE       = 1778,
    BG_AB_WS_OCCUPIED_BASES_ALLY        = 1779,
    BG_AB_WS_RESOURCES_ALLY             = 1776,
    BG_AB_WS_RESOURCES_HORDE            = 1777,
    BG_AB_WS_RESOURCES_MAX              = 1780,
    BG_AB_WS_RESOURCES_WARNING          = 1955,

    BG_AB_WS_STABLE_ICON                = 1842,             // Stable map icon (NONE)
    BG_AB_WS_STABLE_STATE_ALIENCE       = 1767,             // Stable map state (ALIENCE)
    BG_AB_WS_STABLE_STATE_HORDE         = 1768,             // Stable map state (HORDE)
    BG_AB_WS_STABLE_STATE_CON_ALI       = 1769,             // Stable map state (CON ALIENCE)
    BG_AB_WS_STABLE_STATE_CON_HOR       = 1770,             // Stable map state (CON HORDE)
    BG_AB_WS_FARM_ICON                  = 1845,             // Farm map icon (NONE)
    BG_AB_WS_FARM_STATE_ALIENCE         = 1772,             // Farm state (ALIENCE)
    BG_AB_WS_FARM_STATE_HORDE           = 1773,             // Farm state (HORDE)
    BG_AB_WS_FARM_STATE_CON_ALI         = 1774,             // Farm state (CON ALIENCE)
    BG_AB_WS_FARM_STATE_CON_HOR         = 1775,             // Farm state (CON HORDE)
    BG_AB_WS_BLACKSMITH_ICON            = 1846,             // Blacksmith map icon (NONE)
    BG_AB_WS_BLACKSMITH_STATE_ALIENCE   = 1782,             // Blacksmith map state (ALIENCE)
    BG_AB_WS_BLACKSMITH_STATE_HORDE     = 1783,             // Blacksmith map state (HORDE)
    BG_AB_WS_BLACKSMITH_STATE_CON_ALI   = 1784,             // Blacksmith map state (CON ALIENCE)
    BG_AB_WS_BLACKSMITH_STATE_CON_HOR   = 1785,             // Blacksmith map state (CON HORDE)
    BG_AB_WS_LUMBERMILL_ICON            = 1844,             // Lumber Mill map icon (NONE)
    BG_AB_WS_LUMBERMILL_STATE_ALIENCE   = 1792,             // Lumber Mill map state (ALIENCE)
    BG_AB_WS_LUMBERMILL_STATE_HORDE     = 1793,             // Lumber Mill map state (HORDE)
    BG_AB_WS_LUMBERMILL_STATE_CON_ALI   = 1794,             // Lumber Mill map state (CON ALIENCE)
    BG_AB_WS_LUMBERMILL_STATE_CON_HOR   = 1795,             // Lumber Mill map state (CON HORDE)
    BG_AB_WS_GOLDMINE_ICON              = 1843,             // Gold Mine map icon (NONE)
    BG_AB_WS_GOLDMINE_STATE_ALIENCE     = 1787,             // Gold Mine map state (ALIENCE)
    BG_AB_WS_GOLDMINE_STATE_HORDE       = 1788,             // Gold Mine map state (HORDE)
    BG_AB_WS_GOLDMINE_STATE_CON_ALI     = 1789,             // Gold Mine map state (CON ALIENCE
    BG_AB_WS_GOLDMINE_STATE_CON_HOR     = 1790,             // Gold Mine map state (CON HORDE)

    BG_AB_WS_HAD_500_DISADVANTAGE_ALLIANCE  = 3644,
    BG_AB_WS_HAD_500_DISADVANTAGE_HORDE     = 3645,

    BG_AB_WS_FARM_ICON_NEW              = 8808,             // Farm map icon
    BG_AB_WS_LUMBER_MILL_ICON_NEW       = 8805,             // Lumber Mill map icon
    BG_AB_WS_BLACKSMITH_ICON_NEW        = 8799,             // Blacksmith map icon
    BG_AB_WS_GOLD_MINE_ICON_NEW         = 8809,             // Gold Mine map icon
    BG_AB_WS_STABLES_ICON_NEW           = 5834,             // Stable map icon

    BG_AB_WS_FARM_HORDE_CONTROL_STATE           = 17328,
    BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE        = 17325,
    BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE    = 17330,
    BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE = 17326,
    BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE     = 17327,
    BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE  = 17324,
    BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE      = 17329,
    BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE   = 17323,
    BG_AB_WS_STABLES_HORDE_CONTROL_STATE        = 17331,
    BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE     = 17322,
};

/* Object id templates from DB */
enum BG_AB_ObjectTypes
{
    BG_AB_OBJECTID_CAPTURE_POINT_STABLES        = 227420,
    BG_AB_OBJECTID_CAPTURE_POINT_BLACKSMITH     = 227522,
    BG_AB_OBJECTID_CAPTURE_POINT_FARM           = 227536,
    BG_AB_OBJECTID_CAPTURE_POINT_GOLD_MINE      = 227538,
    BG_AB_OBJECTID_CAPTURE_POINT_LUMBER_MILL    = 227544,

    BG_AB_OBJECTID_GHOST_GATE                   = 180322,
    BG_AB_OBJECTID_ALLIANCE_DOOR                = 322273,
    BG_AB_OBJECTID_HORDE_DOOR                   = 322274
};

enum BG_AB_Creatures
{
    BG_AB_NPC_THE_BLACK_BRIDE                   = 150501,
    BG_AB_NPC_RADULF_LEDER                      = 150505
};

enum BG_AB_Score
{
    BG_AB_WARNING_NEAR_VICTORY_SCORE    = 1200,
    BG_AB_MAX_TEAM_SCORE                = 1500
};

/* do NOT change the order, else wrong behaviour */
enum BG_AB_BattlegroundNodes
{
    BG_AB_NODE_STABLES          = 0,
    BG_AB_NODE_BLACKSMITH       = 1,
    BG_AB_NODE_FARM             = 2,
    BG_AB_NODE_LUMBER_MILL      = 3,
    BG_AB_NODE_GOLD_MINE        = 4,

    BG_AB_DYNAMIC_NODES_COUNT   = 5,                        // dynamic nodes that can be captured

    BG_AB_SPIRIT_ALIANCE        = 5,
    BG_AB_SPIRIT_HORDE          = 6,

    BG_AB_ALL_NODES_COUNT       = 7                         // all nodes (dynamic and static)
};

enum BG_AB_BroadcastTexts
{
    BG_AB_TEXT_ALLIANCE_NEAR_VICTORY    = 10598,
    BG_AB_TEXT_HORDE_NEAR_VICTORY       = 10599,
};

enum BG_AB_Sounds
{
    BG_AB_SOUND_NODE_CLAIMED            = 8192,
    BG_AB_SOUND_NODE_CAPTURED_ALLIANCE  = 8173,
    BG_AB_SOUND_NODE_CAPTURED_HORDE     = 8213,
    BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE = 8212,
    BG_AB_SOUND_NODE_ASSAULTED_HORDE    = 8174,
    BG_AB_SOUND_NEAR_VICTORY_ALLIANCE   = 8456,
    BG_AB_SOUND_NEAR_VICTORY_HORDE      = 8457
};

enum BG_AB_ExploitTeleportLocations
{
    AB_EXPLOIT_TELEPORT_LOCATION_ALLIANCE = 7056,
    AB_EXPLOIT_TELEPORT_LOCATION_HORDE = 7055
};

#define BG_AB_NotABBGWeekendHonorTicks      260
#define BG_AB_ABBGWeekendHonorTicks         160
#define BG_AB_NotABBGWeekendReputationTicks 160
#define BG_AB_ABBGWeekendReputationTicks    120

enum BG_AB_Events
{
    AB_EVENT_START_BATTLE                       = 9158, // Achievement: Let's Get This Done

    AB_EVENT_CONTESTED_STABLES_HORDE            = 28523,
    AB_EVENT_CAPTURE_STABLES_HORDE              = 28527,
    AB_EVENT_DEFENDED_STABLES_HORDE             = 28525,
    AB_EVENT_CONTESTED_STABLES_ALLIANCE         = 28522,
    AB_EVENT_CAPTURE_STABLES_ALLIANCE           = 28526,
    AB_EVENT_DEFENDED_STABLES_ALLIANCE          = 28524,

    AB_EVENT_CONTESTED_BLACKSMITH_HORDE         = 8876,
    AB_EVENT_CAPTURE_BLACKSMITH_HORDE           = 8773,
    AB_EVENT_DEFENDED_BLACKSMITH_HORDE          = 8770,
    AB_EVENT_CONTESTED_BLACKSMITH_ALLIANCE      = 8874,
    AB_EVENT_CAPTURE_BLACKSMITH_ALLIANCE        = 8769,
    AB_EVENT_DEFENDED_BLACKSMITH_ALLIANCE       = 8774,

    AB_EVENT_CONTESTED_FARM_HORDE               = 39398,
    AB_EVENT_CAPTURE_FARM_HORDE                 = 39399,
    AB_EVENT_DEFENDED_FARM_HORDE                = 39400,
    AB_EVENT_CONTESTED_FARM_ALLIANCE            = 39401,
    AB_EVENT_CAPTURE_FARM_ALLIANCE              = 39402,
    AB_EVENT_DEFENDED_FARM_ALLIANCE             = 39403,

    AB_EVENT_CONTESTED_GOLD_MINE_HORDE          = 39404,
    AB_EVENT_CAPTURE_GOLD_MINE_HORDE            = 39405,
    AB_EVENT_DEFENDED_GOLD_MINE_HORDE           = 39406,
    AB_EVENT_CONTESTED_GOLD_MINE_ALLIANCE       = 39407,
    AB_EVENT_CAPTURE_GOLD_MINE_ALLIANCE         = 39408,
    AB_EVENT_DEFENDED_GOLD_MINE_ALLIANCE        = 39409,

    AB_EVENT_CONTESTED_LUMBER_MILL_HORDE        = 39387,
    AB_EVENT_CAPTURE_LUMBER_MILL_HORDE          = 39388,
    AB_EVENT_DEFENDED_LUMBER_MILL_HORDE         = 39389,
    AB_EVENT_CONTESTED_LUMBER_MILL_ALLIANCE     = 39390,
    AB_EVENT_CAPTURE_LUMBER_MILL_ALLIANCE       = 39391,
    AB_EVENT_DEFENDED_LUMBER_MILL_ALLIANCE      = 39392
};

// Tick intervals and given points: case 0, 1, 2, 3, 4, 5 captured nodes
const uint32 BG_AB_TickInterval = 2000;
const uint32 BG_AB_TickPoints[6] = { 0, 2, 3, 4, 7, 60 };

// WorldSafeLocs ids for 5 nodes, and for ally, and horde starting location
enum BG_AB_Graveyards
{
    AB_GRAVEYARD_ALLIANCE_BASE = 7251,
    AB_GRAVEYARD_STABLES       = 7252,
    AB_GRAVEYARD_GOLD_MINE     = 7253,
    AB_GRAVEYARD_LUMBER_MILL   = 7254,
    AB_GRAVEYARD_HORDE_BASE    = 7255,
    AB_GRAVEYARD_FARM          = 7256,
    AB_GRAVEYARD_BLACKSMITH    = 7257
};

const uint32 BG_AB_GraveyardIds[BG_AB_ALL_NODES_COUNT] =
{
    AB_GRAVEYARD_STABLES,
    AB_GRAVEYARD_BLACKSMITH,
    AB_GRAVEYARD_FARM,
    AB_GRAVEYARD_LUMBER_MILL,
    AB_GRAVEYARD_GOLD_MINE,
    AB_GRAVEYARD_ALLIANCE_BASE,
    AB_GRAVEYARD_HORDE_BASE
};

class BattlegroundAB : public Battleground
{
    public:
        BattlegroundAB(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundAB();

        void StartingEventOpenDoors() override;
        bool SetupBattleground() override;
        void Reset() override;
        void EndBattleground(Team winner) override;
        WorldSafeLocsEntry const* GetClosestGraveyard(Player* player) override;
        WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;

        Team GetPrematureWinner() override;

        void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker = nullptr) override;

        void OnCreatureCreate(Creature* creature) override;
        void OnGameObjectCreate(GameObject* gameObject) override;
    private:
        void PostUpdateImpl(uint32 diff) override;

        void _CalculateTeamNodes(uint8& alliance, uint8& horde);

        uint32              m_lastTick;
        uint32              m_HonorScoreTics[PVP_TEAMS_COUNT];
        uint32              m_ReputationScoreTics[PVP_TEAMS_COUNT];
        bool                m_IsInformedNearVictory;
        uint32              m_HonorTics;
        uint32              m_ReputationTics;

        GuidVector          _gameobjectsToRemoveOnMatchStart;
        GuidVector          _creaturesToRemoveOnMatchStart;
        GuidVector          _doors;
        GuidVector          _capturePoints;
};
#endif
