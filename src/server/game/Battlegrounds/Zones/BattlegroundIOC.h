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

#ifndef __BATTLEGROUNDIOC_H
#define __BATTLEGROUNDIOC_H

#include "Battleground.h"
#include "BattlegroundScore.h"

class BattlegroundIOC : public Battleground
{
public:
    /* Construction */
    BattlegroundIOC(BattlegroundTemplate const* battlegroundTemplate);
    ~BattlegroundIOC();

    /* inherited from BattlegroundClass */
    void AddPlayer(Player* player) override;
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    /* BG Flags */
    //ObjectGuid GetFlagPickerGUID(int32 team) const override
    //{
    //    if (team == TEAM_ALLIANCE || team == TEAM_HORDE)
    //        return m_FlagKeepers[team];
    //    return ObjectGuid::Empty;
    //}
    //void SetAllianceFlagPicker(ObjectGuid guid) { m_FlagKeepers[TEAM_ALLIANCE] = guid; }
    //void SetHordeFlagPicker(ObjectGuid guid) { m_FlagKeepers[TEAM_HORDE] = guid; }
    //bool IsAllianceFlagPickedup() const { return !m_FlagKeepers[TEAM_ALLIANCE].IsEmpty(); }
    //bool IsHordeFlagPickedup() const { return !m_FlagKeepers[TEAM_HORDE].IsEmpty(); }
    //void RespawnFlag(uint32 Team, bool captured);
    //void RespawnFlagAfterDrop(uint32 Team);
    //uint8 GetFlagState(uint32 team) { return _flagState[GetTeamIndexByTeamId(team)]; }

    /* Battleground Events */
    void EventPlayerDroppedFlag(Player* player) override;
    void EventPlayerClickedOnFlag(Player* player, GameObject* target_obj) override;
    //void EventPlayerCapturedFlag(Player* player);

    void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
    void HandleAreaTrigger(Player* player, uint32 trigger, bool entered) override;
    void HandleKillPlayer(Player* player, Player* killer) override;
    bool SetupBattleground() override;
    void Reset() override;
    void EndBattleground(uint32 winner) override;
    WorldSafeLocsEntry const* GetClosestGraveyard(Player* player) override;
    WorldSafeLocsEntry const* GetExploitTeleportLocation(Team team) override;

    /*void UpdateFlagState(uint32 team, uint32 value);
    void SetLastFlagCapture(uint32 team) { _lastFlagCaptureTeam = team; }
    void UpdateTeamScore(uint32 team);
    bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;
    void SetDroppedFlagGUID(ObjectGuid guid, int32 team = -1) override
    {
        if (team == TEAM_ALLIANCE || team == TEAM_HORDE)
            m_DroppedFlagGUID[team] = guid;
    }*/

    //ObjectGuid GetDroppedFlagGUID(uint32 TeamID) { return m_DroppedFlagGUID[GetTeamIndexByTeamId(TeamID)]; }
    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

    /* Scorekeeping */
    //void AddPoint(uint32 TeamID, uint32 Points = 1) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] += Points; }
    //void SetTeamPoint(uint32 TeamID, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] = Points; }
    //void RemovePoint(uint32 TeamID, uint32 Points = 1) { m_TeamScores[GetTeamIndexByTeamId(TeamID)] -= Points; }

    uint32 GetPrematureWinner() override;

    /* Achievements*/
    bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target = nullptr, uint32 miscvalue1 = 0) override;

protected:
    // void PostUpdateImpl(uint32 diff) override;
    // void GetPlayerPositionData(std::vector<WorldPackets::Battleground::BattlegroundPlayerPosition>* positions) const override;

private:
    //ObjectGuid m_FlagKeepers[2];                            // 0 - alliance, 1 - horde
    //ObjectGuid m_DroppedFlagGUID[2];
    //uint8 _flagState[2];                               // for checking flag state
    //int32 _flagsTimer[2];
    //int32 _flagsDropTimer[2];
    //uint32 _lastFlagCaptureTeam;                       // Winner is based on this if score is equal

    //uint32 m_ReputationCapture;
    //uint32 m_HonorWinKills;
    //uint32 m_HonorEndKills;
    //int32 _flagSpellForceTimer;
    //bool _bothFlagsKept;
    //uint8 _flagDebuffState;                            // 0 - no debuffs, 1 - focused assault, 2 - brutal assault
    //uint8 _minutesElapsed;
};

#endif
