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

#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScript.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Timer.h"

namespace BattleForGilneas
{
    namespace GameObjects
    {
        static constexpr uint32 CapturePointLighthouse = 228050;
        static constexpr uint32 CapturePointWaterworks = 228052;
        static constexpr uint32 CapturePointMines = 228053;

        static constexpr uint32 AllianceDoor = 207177;
        static constexpr uint32 HordeGate1 = 207178;
        static constexpr uint32 HordeGate2 = 205495;
        static constexpr uint32 AllianceGate = 205496;
    }

    namespace PvpStats
    {
        static constexpr uint32 BasesAssaulted = 370;
        static constexpr uint32 BasesDefended = 371;
    }

    namespace Sounds
    {
        static constexpr uint32 PvpFlagTakenAlliance = 8174;
        static constexpr uint32 PvpFlagCapturedAlliance = 8173;
        static constexpr uint32 PvpFlagCapturedHorde = 8213;
        static constexpr uint32 PvpFlagTakenHorde = 8212;
    }

    namespace WorldStates
    {
        static constexpr uint32 OccupiedBasesHorde = 1778;
        static constexpr uint32 OccupiedBasesAlliance = 1779;
        static constexpr uint32 ResourcesAlliance = 1776;
        static constexpr uint32 ResourcesHorde = 1777;

        static constexpr uint32 HadResourceDisadvantageAlliance = 3645;
        static constexpr uint32 HadResourceDisadvantageHorde = 3644;

        static constexpr uint32 HordeLighthouse = 17355;
        static constexpr uint32 AllianceLighthouse = 17356;
        static constexpr uint32 HordeWaterworks = 17358;
        static constexpr uint32 AllianceWaterworks = 17357;
        static constexpr uint32 HordeMines = 17360;
        static constexpr uint32 AllianceMines = 17359;
    }

    namespace Texts
    {
        static constexpr uint32 AllianceNearVictory = 10598;
        static constexpr uint32 HordeNearVictory = 10599;
    }

    namespace Events
    {
        static constexpr uint32 StartBattle = 35912;
    }
}

struct BattleForGilneasCapturePointData
{
    // 0 - uncontrolled, 1 - partially controlled, 2 - fully controlled
    int32 WorldStateHordeControlState;
    int32 WorldStateAllianceControlState;
};

struct battleground_battle_for_gilneas : BattlegroundScript
{
    static constexpr uint32 TICK_POINTS[4] = { 0, 1, 3, 30 };

    static constexpr uint32 WARNING_NEAR_VICTORY_SCORE = 1200;
    static constexpr uint32 MAX_TEAM_SCORE = 1500;

    explicit battleground_battle_for_gilneas(BattlegroundMap* map) : BattlegroundScript(map)
    {
        _capturePointData[BattleForGilneas::GameObjects::CapturePointLighthouse] = { BattleForGilneas::WorldStates::HordeLighthouse, BattleForGilneas::WorldStates::AllianceLighthouse };
        _capturePointData[BattleForGilneas::GameObjects::CapturePointWaterworks] = { BattleForGilneas::WorldStates::HordeWaterworks, BattleForGilneas::WorldStates::AllianceWaterworks };
        _capturePointData[BattleForGilneas::GameObjects::CapturePointMines] = { BattleForGilneas::WorldStates::HordeMines, BattleForGilneas::WorldStates::AllianceMines };
        _isInformedNearVictory = { false, false };

        _tickTracker.Reset(1s);
    }

    void OnUpdate(uint32 diff) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        // Accumulate points
        _tickTracker.Update(diff);
        if (_tickTracker.Passed())
        {
            _tickTracker.Reset(1s);

            uint8 ally = 0, horde = 0;
            CalculateTeamNodes(ally, horde);
            uint8 const points[PVP_TEAMS_COUNT] = { ally, horde };

            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
            {
                if (!points[team])
                    continue;

                battleground->AddPoint(team == TEAM_HORDE ? HORDE : ALLIANCE, TICK_POINTS[points[team]]);

                const uint32 teamScore = battleground->GetTeamScore(static_cast<TeamId>(team));
                if (!_isInformedNearVictory[team] && teamScore > WARNING_NEAR_VICTORY_SCORE)
                {
                    if (team == TEAM_ALLIANCE)
                        battleground->SendBroadcastText(BattleForGilneas::Texts::AllianceNearVictory, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    else
                        battleground->SendBroadcastText(BattleForGilneas::Texts::HordeNearVictory, CHAT_MSG_BG_SYSTEM_NEUTRAL);

                    _isInformedNearVictory[team] = true;
                }

                if (teamScore > MAX_TEAM_SCORE)
                    battleground->SetTeamPoint(team == TEAM_HORDE ? HORDE : ALLIANCE, MAX_TEAM_SCORE);

                if (team == TEAM_ALLIANCE)
                    UpdateWorldState(BattleForGilneas::WorldStates::ResourcesAlliance, teamScore);
                else
                    UpdateWorldState(BattleForGilneas::WorldStates::ResourcesHorde, teamScore);

                // update achievement flags
                // we increased m_TeamScores[team] so we just need to check if it is 500 more than other teams resources
                TeamId const otherTeamId = GetOtherTeam(static_cast<TeamId>(team));
                if (teamScore > battleground->GetTeamScore(otherTeamId) + 500)
                {
                    if (team == TEAM_ALLIANCE)
                        UpdateWorldState(BattleForGilneas::WorldStates::HadResourceDisadvantageHorde, 1, true);
                    else
                        UpdateWorldState(BattleForGilneas::WorldStates::HadResourceDisadvantageAlliance, 1, true);
                }
            }

            UpdateWorldState(BattleForGilneas::WorldStates::OccupiedBasesAlliance, ally);
            UpdateWorldState(BattleForGilneas::WorldStates::OccupiedBasesHorde, horde);
        }

        // Test win condition
        if (battleground->GetTeamScore(TEAM_ALLIANCE) >= MAX_TEAM_SCORE && battleground->GetTeamScore(TEAM_HORDE) >= MAX_TEAM_SCORE)
            battleground->EndBattleground(TEAM_OTHER); // draw
        else if (battleground->GetTeamScore(TEAM_ALLIANCE) >= MAX_TEAM_SCORE)
            battleground->EndBattleground(ALLIANCE);
        else if (battleground->GetTeamScore(TEAM_HORDE) >= MAX_TEAM_SCORE)
            battleground->EndBattleground(HORDE);
    }

    void OnStart() override
    {
        TriggerGameEvent(BattleForGilneas::Events::StartBattle);
        for (ObjectGuid const& guid : _doors)
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
            {
                gameObject->UseDoorOrButton();
                gameObject->DespawnOrUnsummon(3s);
            }
        }
    }

    void ProcessEvent(WorldObject* source, uint32 eventId, WorldObject* invoker) override
    {
        if (GameObject const* capturePoint = Object::ToGameObject(source))
        {
            if (capturePoint->GetGoType() != GAMEOBJECT_TYPE_CAPTURE_POINT)
                return;

            if (capturePoint->GetGOInfo()->capturePoint.ContestedEventAlliance == eventId || capturePoint->GetGOInfo()->capturePoint.ContestedEventHorde == eventId)
                HandleAssaultPoint(capturePoint, Object::ToPlayer(invoker));
            else if (capturePoint->GetGOInfo()->capturePoint.DefendedEventAlliance == eventId || capturePoint->GetGOInfo()->capturePoint.DefendedEventHorde == eventId)
                HandleDefendPoint(capturePoint, Object::ToPlayer(invoker));
            else if (capturePoint->GetGOInfo()->capturePoint.CaptureEventAlliance == eventId)
                HandleCapturePoint(capturePoint, TEAM_ALLIANCE);
            else if (capturePoint->GetGOInfo()->capturePoint.CaptureEventHorde == eventId)
                HandleCapturePoint(capturePoint, TEAM_HORDE);
        }
    }

    void HandleAssaultPoint(GameObject const* capturePoint, Player* player)
    {
        if (!player)
            return;

        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        if (team == ALLIANCE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 1);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 0);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagTakenAlliance);
        }
        else if (team == HORDE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 0);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 1);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagTakenHorde);
        }

        battleground->UpdatePvpStat(player, BattleForGilneas::PvpStats::BasesAssaulted, 1);
    }

    void HandleDefendPoint(GameObject const* capturePoint, Player* player)
    {
        if (!player)
            return;

        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        if (team == ALLIANCE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 2);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 0);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagCapturedAlliance);
        }
        else if (team == HORDE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 0);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 2);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagCapturedHorde);
        }

        battleground->UpdatePvpStat(player, BattleForGilneas::PvpStats::BasesDefended, 1);
    }

    void HandleCapturePoint(GameObject const* capturePoint, TeamId const teamId)
    {
        if (teamId == TEAM_ALLIANCE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 2);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 0);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagCapturedAlliance);
        }
        else if (teamId == TEAM_HORDE)
        {
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateAllianceControlState, 0);
            UpdateWorldState(_capturePointData[capturePoint->GetEntry()].WorldStateHordeControlState, 2);
            battleground->PlaySoundToAll(BattleForGilneas::Sounds::PvpFlagCapturedHorde);
        }
    }

    void CalculateTeamNodes(uint8& alliance, uint8& horde) const
    {
        alliance = 0;
        horde = 0;

        for (ObjectGuid const& guid : _capturePoints)
        {
            if (GameObject const* capturePoint = battlegroundMap->GetGameObject(guid))
            {
                int32 const wsValue = battlegroundMap->GetWorldStateValue(capturePoint->GetGOInfo()->capturePoint.worldState1);
                switch (static_cast<WorldPackets::Battleground::BattlegroundCapturePointState>(wsValue))
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

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        if (gameobject->GetGoType() == GAMEOBJECT_TYPE_CAPTURE_POINT)
            _capturePoints.emplace_back(gameobject->GetGUID());

        switch (gameobject->GetEntry())
        {
            case BattleForGilneas::GameObjects::HordeGate1:
            case BattleForGilneas::GameObjects::AllianceDoor:
            case BattleForGilneas::GameObjects::HordeGate2:
            case BattleForGilneas::GameObjects::AllianceGate:
                _doors.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    TimeTracker _tickTracker;
    GuidVector _capturePoints;
    GuidVector _doors;
    std::array<bool, PVP_TEAMS_COUNT> _isInformedNearVictory;
    std::unordered_map<uint32, BattleForGilneasCapturePointData> _capturePointData;
};

void AddSC_battleground_battle_for_gilneas()
{
    RegisterBattlegroundMapScript(battleground_battle_for_gilneas, 761);
}
