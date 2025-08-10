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

#include "BattlegroundScript.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "Creature.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Log.h"
#include "Map.h"
#include "ScriptMgr.h"

struct battleground_arathi_basin : BattlegroundScript
{
    // Tick intervals and given points: case 0, 1, 2, 3, 4, 5 captured nodes
    static constexpr uint32 BG_AB_TickInterval = 2000;
    static constexpr uint32 BG_AB_TickPoints[6] = { 0, 2, 3, 4, 7, 60 };
    static constexpr uint32 NORMAL_HONOR_TICKS = 160;
    static constexpr uint32 WEEKEND_HONOR_TICKS = 260;
    static constexpr uint32 NORMAL_REPUTATION_TICKS = 120;
    static constexpr uint32 WEEKEND_REPUTATION_TICKS = 160;

    enum PvpStats
    {
        PVP_STAT_BASES_ASSAULTED                    = 926,
        PVP_STAT_BASES_DEFENDED                     = 927,
    };

    enum Events
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

    enum Sounds
    {
        BG_AB_SOUND_NODE_CLAIMED                    = 8192,
        BG_AB_SOUND_NODE_CAPTURED_ALLIANCE          = 8173,
        BG_AB_SOUND_NODE_CAPTURED_HORDE             = 8213,
        BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE         = 8212,
        BG_AB_SOUND_NODE_ASSAULTED_HORDE            = 8174,
        BG_AB_SOUND_NEAR_VICTORY_ALLIANCE           = 8456,
        BG_AB_SOUND_NEAR_VICTORY_HORDE              = 8457
    };

    enum BroadcastTexts
    {
        BG_AB_TEXT_ALLIANCE_NEAR_VICTORY            = 10598,
        BG_AB_TEXT_HORDE_NEAR_VICTORY               = 10599,
    };

    enum Score
    {
        BG_AB_WARNING_NEAR_VICTORY_SCORE            = 1200,
        BG_AB_MAX_TEAM_SCORE                        = 1500
    };

    enum Creatures
    {
        BG_AB_NPC_THE_BLACK_BRIDE                   = 150501,
        BG_AB_NPC_RADULF_LEDER                      = 150505
    };

    enum ObjectTypes
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

    enum WorldStates
    {
        BG_AB_WS_OCCUPIED_BASES_HORDE               = 1778,
        BG_AB_WS_OCCUPIED_BASES_ALLY                = 1779,
        BG_AB_WS_RESOURCES_ALLY                     = 1776,
        BG_AB_WS_RESOURCES_HORDE                    = 1777,
        BG_AB_WS_RESOURCES_MAX                      = 1780,
        BG_AB_WS_RESOURCES_WARNING                  = 1955,

        BG_AB_WS_STABLE_ICON                        = 1842,             // Stable map icon (NONE)
        BG_AB_WS_STABLE_STATE_ALIENCE               = 1767,             // Stable map state (ALIENCE)
        BG_AB_WS_STABLE_STATE_HORDE                 = 1768,             // Stable map state (HORDE)
        BG_AB_WS_STABLE_STATE_CON_ALI               = 1769,             // Stable map state (CON ALIENCE)
        BG_AB_WS_STABLE_STATE_CON_HOR               = 1770,             // Stable map state (CON HORDE)
        BG_AB_WS_FARM_ICON                          = 1845,             // Farm map icon (NONE)
        BG_AB_WS_FARM_STATE_ALIENCE                 = 1772,             // Farm state (ALIENCE)
        BG_AB_WS_FARM_STATE_HORDE                   = 1773,             // Farm state (HORDE)
        BG_AB_WS_FARM_STATE_CON_ALI                 = 1774,             // Farm state (CON ALIENCE)
        BG_AB_WS_FARM_STATE_CON_HOR                 = 1775,             // Farm state (CON HORDE)
        BG_AB_WS_BLACKSMITH_ICON                    = 1846,             // Blacksmith map icon (NONE)
        BG_AB_WS_BLACKSMITH_STATE_ALIENCE           = 1782,             // Blacksmith map state (ALIENCE)
        BG_AB_WS_BLACKSMITH_STATE_HORDE             = 1783,             // Blacksmith map state (HORDE)
        BG_AB_WS_BLACKSMITH_STATE_CON_ALI           = 1784,             // Blacksmith map state (CON ALIENCE)
        BG_AB_WS_BLACKSMITH_STATE_CON_HOR           = 1785,             // Blacksmith map state (CON HORDE)
        BG_AB_WS_LUMBERMILL_ICON                    = 1844,             // Lumber Mill map icon (NONE)
        BG_AB_WS_LUMBERMILL_STATE_ALIENCE           = 1792,             // Lumber Mill map state (ALIENCE)
        BG_AB_WS_LUMBERMILL_STATE_HORDE             = 1793,             // Lumber Mill map state (HORDE)
        BG_AB_WS_LUMBERMILL_STATE_CON_ALI           = 1794,             // Lumber Mill map state (CON ALIENCE)
        BG_AB_WS_LUMBERMILL_STATE_CON_HOR           = 1795,             // Lumber Mill map state (CON HORDE)
        BG_AB_WS_GOLDMINE_ICON                      = 1843,             // Gold Mine map icon (NONE)
        BG_AB_WS_GOLDMINE_STATE_ALIENCE             = 1787,             // Gold Mine map state (ALIENCE)
        BG_AB_WS_GOLDMINE_STATE_HORDE               = 1788,             // Gold Mine map state (HORDE)
        BG_AB_WS_GOLDMINE_STATE_CON_ALI             = 1789,             // Gold Mine map state (CON ALIENCE
        BG_AB_WS_GOLDMINE_STATE_CON_HOR             = 1790,             // Gold Mine map state (CON HORDE)

        BG_AB_WS_HAD_500_DISADVANTAGE_ALLIANCE      = 3644,
        BG_AB_WS_HAD_500_DISADVANTAGE_HORDE         = 3645,

        BG_AB_WS_FARM_ICON_NEW                      = 8808,             // Farm map icon
        BG_AB_WS_LUMBER_MILL_ICON_NEW               = 8805,             // Lumber Mill map icon
        BG_AB_WS_BLACKSMITH_ICON_NEW                = 8799,             // Blacksmith map icon
        BG_AB_WS_GOLD_MINE_ICON_NEW                 = 8809,             // Gold Mine map icon
        BG_AB_WS_STABLES_ICON_NEW                   = 5834,             // Stable map icon

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

    explicit battleground_arathi_basin(BattlegroundMap* map) : BattlegroundScript(map), _lastTick(0), _isInformedNearVictory(false)
    {
        bool const isBGWeekend = sBattlegroundMgr->IsBGWeekend(battleground->GetTypeID());

        _honorTics = (isBGWeekend) ? WEEKEND_HONOR_TICKS : NORMAL_HONOR_TICKS;
        _reputationTics = (isBGWeekend) ? WEEKEND_REPUTATION_TICKS : NORMAL_REPUTATION_TICKS;
        _honorScoreTics = { { 0, 0 } };
        _reputationScoreTics = { { 0, 0 } };
    }

    void OnInit() override
    {
        BattlegroundScript::OnInit();

        UpdateWorldState(BG_AB_WS_RESOURCES_MAX, BG_AB_MAX_TEAM_SCORE);
        UpdateWorldState(BG_AB_WS_RESOURCES_WARNING, BG_AB_WARNING_NEAR_VICTORY_SCORE);
    }

    void OnUpdate(uint32 diff) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        // Accumulate points
        _lastTick += diff;
        if (_lastTick > BG_AB_TickInterval)
        {
            _lastTick -= BG_AB_TickInterval;

            uint8 ally = 0, horde = 0;
            _CalculateTeamNodes(ally, horde);
            uint8 points[PVP_TEAMS_COUNT] = { ally, horde };

            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
            {
                if (!points[team])
                    continue;

                battleground->AddPoint(team == TEAM_HORDE ? HORDE : ALLIANCE, BG_AB_TickPoints[points[team]]);
                _honorScoreTics[team] += BG_AB_TickPoints[points[team]];
                _reputationScoreTics[team] += BG_AB_TickPoints[points[team]];

                if (_reputationScoreTics[team] >= _reputationTics)
                {
                    (team == TEAM_ALLIANCE) ? battleground->RewardReputationToTeam(509, 10, ALLIANCE) : battleground->RewardReputationToTeam(510, 10, HORDE);
                    _reputationScoreTics[team] -= _reputationTics;
                }

                if (_honorScoreTics[team] >= _honorTics)
                {
                    battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), (team == TEAM_ALLIANCE) ? ALLIANCE : HORDE);
                    _honorScoreTics[team] -= _honorTics;
                }

                const uint32 teamScore = battleground->GetTeamScore(static_cast<TeamId>(team));
                if (!_isInformedNearVictory && teamScore > BG_AB_WARNING_NEAR_VICTORY_SCORE)
                {
                    if (team == TEAM_ALLIANCE)
                    {
                        battleground->SendBroadcastText(BG_AB_TEXT_ALLIANCE_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        battleground->PlaySoundToAll(BG_AB_SOUND_NEAR_VICTORY_ALLIANCE);
                    }
                    else
                    {
                        battleground->SendBroadcastText(BG_AB_TEXT_HORDE_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        battleground->PlaySoundToAll(BG_AB_SOUND_NEAR_VICTORY_HORDE);
                    }
                    _isInformedNearVictory = true;
                }

                if (teamScore > BG_AB_MAX_TEAM_SCORE)
                    battleground->SetTeamPoint(team == TEAM_HORDE ? HORDE : ALLIANCE, BG_AB_MAX_TEAM_SCORE);

                if (team == TEAM_ALLIANCE)
                    UpdateWorldState(BG_AB_WS_RESOURCES_ALLY, teamScore);
                else
                    UpdateWorldState(BG_AB_WS_RESOURCES_HORDE, teamScore);

                // update achievement flags
                // we increased m_TeamScores[team] so we just need to check if it is 500 more than other teams resources
                uint8 otherTeam = (team + 1) % PVP_TEAMS_COUNT;
                if (teamScore > battleground->GetTeamScore(static_cast<TeamId>(otherTeam)) + 500)
                {
                    if (team == TEAM_ALLIANCE)
                        UpdateWorldState(BG_AB_WS_HAD_500_DISADVANTAGE_HORDE, 1);
                    else
                        UpdateWorldState(BG_AB_WS_HAD_500_DISADVANTAGE_ALLIANCE, 1);
                }
            }

            UpdateWorldState(BG_AB_WS_OCCUPIED_BASES_ALLY, ally);
            UpdateWorldState(BG_AB_WS_OCCUPIED_BASES_HORDE, horde);
        }

        // Test win condition
        if (battleground->GetTeamScore(TEAM_ALLIANCE) >= BG_AB_MAX_TEAM_SCORE && battleground->GetTeamScore(TEAM_HORDE) >= BG_AB_MAX_TEAM_SCORE)
            battleground->EndBattleground(TEAM_OTHER); // draw
        else if (battleground->GetTeamScore(TEAM_ALLIANCE) >= BG_AB_MAX_TEAM_SCORE)
            battleground->EndBattleground(ALLIANCE);
        else if (battleground->GetTeamScore(TEAM_HORDE) >= BG_AB_MAX_TEAM_SCORE)
            battleground->EndBattleground(HORDE);
    }

    void OnStart() override
    {
        // Achievement: Let's Get This Done
        TriggerGameEvent(AB_EVENT_START_BATTLE);
    }

    void _CalculateTeamNodes(uint8& alliance, uint8& horde) const
    {
        alliance = 0;
        horde = 0;

        for (ObjectGuid const& guid : _capturePoints)
        {
            if (GameObject const* capturePoint = battlegroundMap->GetGameObject(guid))
            {
                int32 const wsValue = battlegroundMap->GetWorldStateValue(capturePoint->GetGOInfo()->capturePoint.worldState1);
                switch (WorldPackets::Battleground::BattlegroundCapturePointState(wsValue))
                {
                    case WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured:
                        ++alliance;
                        break;
                    case WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured:
                        ++horde;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    Team GetPrematureWinner() override
    {
        // How many bases each team owns
        uint8 ally = 0, horde = 0;
        _CalculateTeamNodes(ally, horde);

        if (ally > horde)
            return ALLIANCE;
        if (horde > ally)
            return HORDE;

        // If the values are equal, fall back to the original result (based on number of players on each team)
        return BattlegroundScript::GetPrematureWinner();
    }

    void ProcessEvent(WorldObject* /*source*/, uint32 eventId, WorldObject* invoker) override
    {
        switch (eventId)
        {
            case AB_EVENT_START_BATTLE:
            {
                for (ObjectGuid const& guid : _creaturesToRemoveOnMatchStart)
                    if (Creature* creature = battlegroundMap->GetCreature(guid))
                        creature->DespawnOrUnsummon();

                for (ObjectGuid const& guid : _gameobjectsToRemoveOnMatchStart)
                    if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
                        gameObject->DespawnOrUnsummon();

                for (ObjectGuid const& guid : _doors)
                {
                    if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
                    {
                        gameObject->UseDoorOrButton();
                        gameObject->DespawnOrUnsummon(3s);
                    }
                }
                break;
            }
            case AB_EVENT_CONTESTED_BLACKSMITH_ALLIANCE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 1);
                UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_BLACKSMITH_ALLIANCE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 2);
                UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_BLACKSMITH_ALLIANCE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                break;
            case AB_EVENT_CONTESTED_BLACKSMITH_HORDE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 1);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_BLACKSMITH_HORDE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_BLACKSMITH_HORDE:
                UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                break;
            case AB_EVENT_CONTESTED_FARM_ALLIANCE:
                UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 1);
                UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_FARM_ALLIANCE:
                UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 2);
                UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_FARM_ALLIANCE:
                UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                break;
            case AB_EVENT_CONTESTED_FARM_HORDE:
                UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 1);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_FARM_HORDE:
                UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_FARM_HORDE:
                UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                break;
            case AB_EVENT_CONTESTED_GOLD_MINE_ALLIANCE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 1);
                UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_GOLD_MINE_ALLIANCE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 2);
                UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_GOLD_MINE_ALLIANCE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                break;
            case AB_EVENT_CONTESTED_GOLD_MINE_HORDE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 1);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_GOLD_MINE_HORDE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_GOLD_MINE_HORDE:
                UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                break;
            case AB_EVENT_CONTESTED_LUMBER_MILL_ALLIANCE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 1);
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_LUMBER_MILL_ALLIANCE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 2);
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_LUMBER_MILL_ALLIANCE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                break;
            case AB_EVENT_CONTESTED_LUMBER_MILL_HORDE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 1);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_LUMBER_MILL_HORDE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_LUMBER_MILL_HORDE:
                UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                break;
            case AB_EVENT_CONTESTED_STABLES_ALLIANCE:
                UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 1);
                UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_STABLES_ALLIANCE:
                UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 2);
                UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 0);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_STABLES_ALLIANCE:
                UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                break;
            case AB_EVENT_CONTESTED_STABLES_HORDE:
                UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 1);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
                break;
            case AB_EVENT_DEFENDED_STABLES_HORDE:
                UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 0);
                UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                if (Player* player = invoker->ToPlayer())
                    battleground->UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
                break;
            case AB_EVENT_CAPTURE_STABLES_HORDE:
                UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 2);
                battleground->PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                break;
            default:
                TC_LOG_WARN("bg.events", "BattlegroundAB::ProcessEvent: Unhandled event %u.", eventId);
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case BG_AB_NPC_THE_BLACK_BRIDE:
            case BG_AB_NPC_RADULF_LEDER:
                _creaturesToRemoveOnMatchStart.push_back(creature->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameObject) override
    {
        if (gameObject->GetGOInfo()->type == GAMEOBJECT_TYPE_CAPTURE_POINT)
            _capturePoints.push_back(gameObject->GetGUID());

        switch (gameObject->GetEntry())
        {
            case BG_AB_OBJECTID_GHOST_GATE:
                _gameobjectsToRemoveOnMatchStart.push_back(gameObject->GetGUID());
                break;
            case BG_AB_OBJECTID_ALLIANCE_DOOR:
            case BG_AB_OBJECTID_HORDE_DOOR:
                _doors.push_back(gameObject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnEnd(Team winner) override
    {
        BattlegroundScript::OnEnd(winner);

        // Win reward
        if (winner == ALLIANCE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), ALLIANCE);
        if (winner == HORDE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), HORDE);
        // Complete map_end rewards (even if no team wins)
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), HORDE);
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), ALLIANCE);
    }

private:
    uint32 _lastTick;
    std::array<uint32, PVP_TEAMS_COUNT> _honorScoreTics;
    std::array<uint32, PVP_TEAMS_COUNT> _reputationScoreTics;
    bool _isInformedNearVictory;
    uint32 _honorTics;
    uint32 _reputationTics;

    GuidVector _gameobjectsToRemoveOnMatchStart;
    GuidVector _creaturesToRemoveOnMatchStart;
    GuidVector _doors;
    GuidVector _capturePoints;
};

void AddSC_battleground_arathi_basin()
{
    RegisterBattlegroundMapScript(battleground_arathi_basin, 2107);
}
