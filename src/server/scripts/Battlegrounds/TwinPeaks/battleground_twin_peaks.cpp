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

#include "AreaTrigger.h"
#include "Battleground.h"
#include "BattlegroundScript.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Timer.h"

namespace TwinPeaks
{
    namespace AreaTriggers
    {
        static constexpr uint32 CapturePointAlliance = 30;
        static constexpr uint32 CapturePointHorde = 31;
    }

    namespace Events
    {
        static constexpr uint32 StartBattle = 35912;
    }

    namespace GameObjects
    {
        static constexpr uint32 GhostGate = 180322;
        static constexpr uint32 Gate1 = 208205;
        static constexpr uint32 Gate2 = 208207;
        static constexpr uint32 Gate3 = 208206;
        static constexpr uint32 Portcullis = 203710;
        static constexpr uint32 HordeFlag = 227740;;
        static constexpr uint32 AllianceFlag = 227741;
        static constexpr uint32 WildHammerGate1 = 206653;
        static constexpr uint32 WildHammerGate2 = 206654;
        static constexpr uint32 WildHammerGate3 = 206655;
    }

    namespace Misc
    {
        static constexpr uint8 MaxTeamScore = 3;
        static constexpr uint8 FlagBrutalAssaultStackCount = 5;
    }

    namespace PvpStats
    {
        static constexpr uint32 FlagCaptures = 290;
        static constexpr uint32 FlagReturns = 291;
    }

    namespace Sounds
    {
        static constexpr uint32 PvpFlagCapturedAlliance = 8173;
        static constexpr uint32 PvpFlagCapturedHorde = 8213;
        static constexpr uint32 FlagReturned = 8192;
        static constexpr uint32 PvpFlagTakenHorde = 8212;
        static constexpr uint32 PvpFlagTakenAlliance = 8174;
        static constexpr uint32 FlagsRespawned = 8232;
    }

    namespace Spells
    {
        static constexpr uint32 FocusedAssault = 46392;
        static constexpr uint32 BrutalAssault = 46393;
        static constexpr uint32 QuickCapTimer = 183317;
        static constexpr uint32 CapturedAllianceCosmeticFx = 262508;
        static constexpr uint32 CapturedHordeCosmeticFx = 262512;
    }

    namespace Texts
    {
        static constexpr uint32 CapturedHordeFlag = 9801;
        static constexpr uint32 CapturedAllianceFlag = 9802;
        static constexpr uint32 FlagsPlaced = 9803;
        static constexpr uint32 AllianceFlagPickedUp = 9804;
        static constexpr uint32 AllianceFlagDropped = 9805;
        static constexpr uint32 HordeFlagPickedUp = 9807;
        static constexpr uint32 HordeFlagDropped = 9806;
        static constexpr uint32 AllianceFlagReturned = 9808;
        static constexpr uint32 HordeFlagReturned = 9809;
    }

    namespace Timers
    {
        static constexpr Seconds FlagAssaultTimer = 30s;
    }

    namespace WorldStates
    {
        static constexpr uint32 FlagStateAlliance = 1545;
        static constexpr uint32 FlagStateHorde = 1546;
        static constexpr uint32 FlagCapturesAlliance = 1581;
        static constexpr uint32 FlagCapturesHorde = 1582;
        static constexpr uint32 FlagControlHorde = 2338;
        static constexpr uint32 FlagControlAlliance = 2339;
        static constexpr uint32 Timer = 4248;
        static constexpr uint32 TimerActive = 4247;
        static constexpr uint32 DoubleJeopardyAllianceEnabled = 5746;
        static constexpr uint32 DoubleJeopardyHordeEnabled = 5747;
    }
}

struct battleground_twin_peaks : BattlegroundScript
{
    explicit battleground_twin_peaks(BattlegroundMap* map) : BattlegroundScript(map), _lastFlagCaptureTeam(TEAM_OTHER), _bothFlagsKept(false), _flags({ }), _assaultStackCount(0), _capturePointAreaTriggers({ })
    {
        _flagAssaultTimer.Reset(TwinPeaks::Timers::FlagAssaultTimer);
    }

    void OnUpdate(uint32 diff) override
    {
        BattlegroundScript::OnUpdate(diff);

        if (battleground->GetStatus() == STATUS_IN_PROGRESS)
        {
            if (battleground->GetElapsedTime() >= 17 * MINUTE * IN_MILLISECONDS)
            {
                if (battleground->GetTeamScore(TEAM_ALLIANCE) == 0)
                {
                    if (battleground->GetTeamScore(TEAM_HORDE) == 0) // No one scored - result is tie
                        battleground->EndBattleground(TEAM_OTHER);
                    else // Horde has more points and thus wins
                        battleground->EndBattleground(HORDE);
                }
                else if (battleground->GetTeamScore(TEAM_HORDE) == 0) // Alliance has > 0, Horde has 0, alliance wins
                    battleground->EndBattleground(ALLIANCE);
                else if (battleground->GetTeamScore(TEAM_HORDE) == battleground->GetTeamScore(TEAM_ALLIANCE)) // Team score equal, winner is team that scored the last flag
                    battleground->EndBattleground(_lastFlagCaptureTeam);
                else if (battleground->GetTeamScore(TEAM_HORDE) > battleground->GetTeamScore(TEAM_ALLIANCE))  // Last but not least, check who has the higher score
                    battleground->EndBattleground(HORDE);
                else
                    battleground->EndBattleground(ALLIANCE);
            }
        }

        if (_bothFlagsKept)
        {
            _flagAssaultTimer.Update(diff);
            if (_flagAssaultTimer.Passed())
            {
                _flagAssaultTimer.Reset(TwinPeaks::Timers::FlagAssaultTimer);
                if (_assaultStackCount < std::numeric_limits<uint8>::max())
                {
                    _assaultStackCount++;

                    // update assault debuff stacks
                    DoForFlagKeepers([&](Player* player) -> void
                    {
                        ApplyAssaultDebuffToPlayer(player);
                    });
                }
            }
        }
    }

    void OnStart() override
    {
        BattlegroundScript::OnStart();
        for (ObjectGuid door : _doors)
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(door))
            {
                gameObject->UseDoorOrButton();
                gameObject->DespawnOrUnsummon(3s);
            }
        }

        UpdateWorldState(TwinPeaks::WorldStates::TimerActive, 1);
        UpdateWorldState(TwinPeaks::WorldStates::Timer, std::chrono::system_clock::to_time_t(GameTime::GetSystemTime() + 15min));

        // players joining later are not eligibles
        TriggerGameEvent(TwinPeaks::Events::StartBattle);
    }

    void DoForFlagKeepers(std::function<void(Player*)> const& action) const
    {
        for (ObjectGuid flagGUID : _flags)
            if (GameObject const* flag = battlegroundMap->GetGameObject(flagGUID))
                if (Player* carrier = ObjectAccessor::FindPlayer(flag->GetFlagCarrierGUID()))
                    action(carrier);
    }

    void ResetAssaultDebuff()
    {
        _bothFlagsKept = false;
        _assaultStackCount = 0;
        _flagAssaultTimer.Reset(TwinPeaks::Timers::FlagAssaultTimer);
        DoForFlagKeepers([&](Player* player) -> void
        {
            RemoveAssaultDebuffFromPlayer(player);
        });
    }

    void ApplyAssaultDebuffToPlayer(Player* player) const
    {
        if (_assaultStackCount == 0)
            return;

        uint32 spellId = TwinPeaks::Spells::FocusedAssault;
        if (_assaultStackCount >= TwinPeaks::Misc::FlagBrutalAssaultStackCount)
        {
            player->RemoveAurasDueToSpell(TwinPeaks::Spells::FocusedAssault);
            spellId = TwinPeaks::Spells::BrutalAssault;
        }

        Aura* aura = player->GetAura(spellId);
        if (!aura)
        {
            player->CastSpell(player, spellId, true);
            aura = player->GetAura(spellId);
        }

        if (aura)
            aura->SetStackAmount(_assaultStackCount);
    }

    void RemoveAssaultDebuffFromPlayer(Player* player) const
    {
        player->RemoveAurasDueToSpell(TwinPeaks::Spells::FocusedAssault);
        player->RemoveAurasDueToSpell(TwinPeaks::Spells::BrutalAssault);
    }

    FlagState GetFlagState(TeamId team) const
    {
        if (GameObject const* flag = battlegroundMap->GetGameObject(_flags[team]))
            return flag->GetFlagState();

        return FlagState(0);
    }

    ObjectGuid const& GetFlagCarrierGUID(TeamId team) const
    {
        if (GameObject const* flag = battlegroundMap->GetGameObject(_flags[team]))
            return flag->GetFlagCarrierGUID();

        return ObjectGuid::Empty;
    }

    void HandleFlagRoomCapturePoint()
    {
        DoForFlagKeepers([&](Player* player) -> void
        {
            TeamId const team = Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID()));
            if (AreaTrigger* trigger = battlegroundMap->GetAreaTrigger(_capturePointAreaTriggers[team]))
                if (trigger->GetInsideUnits().contains(player->GetGUID()))
                    if (CanCaptureFlag(trigger, player))
                        OnCaptureFlag(trigger, player);
        });
    }

    void UpdateFlagState(uint32 team, FlagState value) const
    {
        auto transformValueToOtherTeamControlWorldState = [](FlagState state)
        {
            switch (state)
            {
                case FlagState::InBase:
                case FlagState::Dropped:
                case FlagState::Respawning:
                    return 1;
                case FlagState::Taken:
                    return 2;
                default:
                    return 0;
            }
        };

        if (team == ALLIANCE)
        {
            UpdateWorldState(TwinPeaks::WorldStates::FlagStateAlliance, AsUnderlyingType(value));
            UpdateWorldState(TwinPeaks::WorldStates::FlagControlHorde, transformValueToOtherTeamControlWorldState(value));
        }
        else
        {
            UpdateWorldState(TwinPeaks::WorldStates::FlagStateHorde, AsUnderlyingType(value));
            UpdateWorldState(TwinPeaks::WorldStates::FlagControlAlliance, transformValueToOtherTeamControlWorldState(value));
        }
    }

    void UpdateTeamScore(TeamId team) const
    {
        if (team == TEAM_ALLIANCE)
            UpdateWorldState(TwinPeaks::WorldStates::FlagCapturesAlliance, battleground->GetTeamScore(team));
        else
            UpdateWorldState(TwinPeaks::WorldStates::FlagCapturesHorde, battleground->GetTeamScore(team));

        TeamId const otherTeam = GetOtherTeam(team);
        uint32 const teamScore = battleground->GetTeamScore(team);
        uint32 const otherTeamScore = battleground->GetTeamScore(otherTeam);
        if (teamScore == 2 && otherTeamScore == 0)
            UpdateWorldState(team == TEAM_ALLIANCE ? TwinPeaks::WorldStates::DoubleJeopardyHordeEnabled : TwinPeaks::WorldStates::DoubleJeopardyAllianceEnabled, 1, true);
    }

    void OnGameObjectCreate(GameObject* gameObject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameObject);
        switch (gameObject->GetEntry())
        {
            case TwinPeaks::GameObjects::Gate1:
            case TwinPeaks::GameObjects::Gate2:
            case TwinPeaks::GameObjects::Gate3:
            case TwinPeaks::GameObjects::GhostGate:
            case TwinPeaks::GameObjects::Portcullis:
            case TwinPeaks::GameObjects::WildHammerGate1:
            case TwinPeaks::GameObjects::WildHammerGate2:
            case TwinPeaks::GameObjects::WildHammerGate3:
                _doors.insert(gameObject->GetGUID());
                break;
            case TwinPeaks::GameObjects::AllianceFlag:
                _flags[TEAM_ALLIANCE] = gameObject->GetGUID();
                break;
            case TwinPeaks::GameObjects::HordeFlag:
                _flags[TEAM_HORDE] = gameObject->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnAreaTriggerCreate(AreaTrigger* areaTrigger) override
    {
        BattlegroundScript::OnAreaTriggerCreate(areaTrigger);
        if (!areaTrigger->IsStaticSpawn())
            return;

        switch (areaTrigger->GetEntry())
        {
            case TwinPeaks::AreaTriggers::CapturePointAlliance:
                _capturePointAreaTriggers[TEAM_ALLIANCE] = areaTrigger->GetGUID();
                break;
            case TwinPeaks::AreaTriggers::CapturePointHorde:
                _capturePointAreaTriggers[TEAM_HORDE] = areaTrigger->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnFlagStateChange(GameObject* flagInBase, FlagState oldValue, FlagState newValue, Player* player) override
    {
        BattlegroundScript::OnFlagStateChange(flagInBase, oldValue, newValue, player);

        Team const team = flagInBase->GetEntry() == TwinPeaks::GameObjects::HordeFlag ? HORDE : ALLIANCE;
        TeamId const otherTeamId = Battleground::GetTeamIndexByTeamId(GetOtherTeam(team));

        UpdateFlagState(team, newValue);

        switch (newValue)
        {
            case FlagState::InBase:
            {
                if (battleground->GetStatus() == STATUS_IN_PROGRESS)
                {
                    ResetAssaultDebuff();
                    if (player)
                    {
                        // flag got returned to base by player interaction
                        battleground->UpdatePvpStat(player, TwinPeaks::PvpStats::FlagReturns, 1);      // +1 flag returns

                        if (team == ALLIANCE)
                        {
                            battleground->SendBroadcastText(TwinPeaks::Texts::AllianceFlagReturned, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                            battleground->PlaySoundToAll(TwinPeaks::Sounds::FlagReturned);
                        }
                        else
                        {
                            battleground->SendBroadcastText(TwinPeaks::Texts::HordeFlagReturned, CHAT_MSG_BG_SYSTEM_HORDE, player);
                            battleground->PlaySoundToAll(TwinPeaks::Sounds::FlagReturned);
                        }
                    }
                    // Flag respawned due to timeout/capture
                    else if (GetFlagState(otherTeamId) != FlagState::Respawning)
                    {
                        // if other flag is respawning, we will let that one handle the message and sound to prevent double message/sound.
                        battleground->SendBroadcastText(TwinPeaks::Texts::FlagsPlaced, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        battleground->PlaySoundToAll(TwinPeaks::Sounds::FlagsRespawned);
                    }

                    HandleFlagRoomCapturePoint();
                }
                break;
            }
            case FlagState::Dropped:
            {
                player->RemoveAurasDueToSpell(TwinPeaks::Spells::QuickCapTimer);
                RemoveAssaultDebuffFromPlayer(player);

                uint32 recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_HORDE_FLAG;
                if (team == ALLIANCE)
                {
                    recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_ALLIANCE_FLAG;
                    battleground->SendBroadcastText(TwinPeaks::Texts::AllianceFlagDropped, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                }
                else
                    battleground->SendBroadcastText(TwinPeaks::Texts::HordeFlagDropped, CHAT_MSG_BG_SYSTEM_HORDE, player);

                player->CastSpell(player, recentlyDroppedSpellId, true);
                break;
            }
            case FlagState::Taken:
            {
                if (team == HORDE)
                {
                    battleground->SendBroadcastText(TwinPeaks::Texts::HordeFlagPickedUp, CHAT_MSG_BG_SYSTEM_HORDE, player);
                    battleground->PlaySoundToAll(TwinPeaks::Sounds::PvpFlagTakenHorde);
                }
                else
                {
                    battleground->SendBroadcastText(TwinPeaks::Texts::AllianceFlagPickedUp, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                    battleground->PlaySoundToAll(TwinPeaks::Sounds::PvpFlagTakenAlliance);
                }

                if (GetFlagState(otherTeamId) == FlagState::Taken)
                    _bothFlagsKept = true;

                ApplyAssaultDebuffToPlayer(player);

                flagInBase->CastSpell(player, TwinPeaks::Spells::QuickCapTimer, true);
                player->StartCriteria(CriteriaStartEvent::BeSpellTarget, TwinPeaks::Spells::QuickCapTimer, Seconds(GameTime::GetGameTime() - flagInBase->GetFlagTakenFromBaseTime()));
                break;
            }
            case FlagState::Respawning:
                ResetAssaultDebuff();
                break;
            default:
                break;
        }
    }

    bool CanCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return false;

        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const teamId = Battleground::GetTeamIndexByTeamId(team);
        TeamId const otherTeamId = Battleground::GetTeamIndexByTeamId(GetOtherTeam(team));

        if (areaTrigger->GetGUID() != _capturePointAreaTriggers[teamId])
            return false;

        // check if enemy flag's carrier is this player
        if (GetFlagCarrierGUID(otherTeamId) != player->GetGUID())
            return false;

        // check that team's flag is in base
        return GetFlagState(teamId) == FlagState::InBase;
    }

    void OnCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        BattlegroundScript::OnCaptureFlag(areaTrigger, player);

        Team winner = TEAM_OTHER;

        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const teamId = Battleground::GetTeamIndexByTeamId(team);
        TeamId const otherTeamId = Battleground::GetTeamIndexByTeamId(GetOtherTeam(team));

        /*
            1. Update flag states & score world states
            2. update points
            3. chat message & sound
            4. update criterias & achievements
            5. remove all related auras
            ?. Reward honor & reputation
        */

        // 1. update the flag states
        for (ObjectGuid const& flagGuid : _flags)
            if (GameObject const* flag = battlegroundMap->GetGameObject(flagGuid))
                flag->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

        // 2. update points
        if (battleground->GetTeamScore(teamId) < TwinPeaks::Misc::MaxTeamScore)
            battleground->AddPoint(team, 1);

        UpdateTeamScore(teamId);

        // 3. chat message & sound
        if (team == ALLIANCE)
        {
            battleground->SendBroadcastText(TwinPeaks::Texts::CapturedHordeFlag, CHAT_MSG_BG_SYSTEM_HORDE, player);
            battleground->PlaySoundToAll(TwinPeaks::Sounds::PvpFlagCapturedAlliance);
            player->CastSpell(player, TwinPeaks::Spells::CapturedAllianceCosmeticFx);
        }
        else
        {
            battleground->SendBroadcastText(TwinPeaks::Texts::CapturedAllianceFlag, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            battleground->PlaySoundToAll(TwinPeaks::Sounds::PvpFlagCapturedHorde);
            player->CastSpell(player, TwinPeaks::Spells::CapturedHordeCosmeticFx);
        }

        // 4. update criteria's for achievement, player score etc.
        battleground->UpdatePvpStat(player, TwinPeaks::PvpStats::FlagCaptures, 1);      // +1 flag captures

        // 5. Remove all related auras
        RemoveAssaultDebuffFromPlayer(player);

        if (GameObject const* flag = battlegroundMap->GetGameObject(_flags[otherTeamId]))
            player->RemoveAurasDueToSpell(flag->GetGOInfo()->newflag.pickupSpell, flag->GetGUID());

        player->RemoveAurasDueToSpell(TwinPeaks::Spells::QuickCapTimer);

        player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);

        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(2), team);

        // update last flag capture to be used if teamscore is equal
        SetLastFlagCapture(team);

        if (battleground->GetTeamScore(teamId) == TwinPeaks::Misc::MaxTeamScore)
            winner = team;

        if (winner)
        {
            UpdateWorldState(TwinPeaks::WorldStates::FlagStateAlliance, 1);
            UpdateWorldState(TwinPeaks::WorldStates::FlagStateHorde, 1);
            UpdateWorldState(TwinPeaks::WorldStates::TimerActive, 0);

            battleground->EndBattleground(winner);
        }
    }

    Team GetPrematureWinner() override
    {
        if (battleground->GetTeamScore(TEAM_ALLIANCE) > battleground->GetTeamScore(TEAM_HORDE))
            return ALLIANCE;
        if (battleground->GetTeamScore(TEAM_HORDE) > battleground->GetTeamScore(TEAM_ALLIANCE))
            return HORDE;

        return BattlegroundScript::GetPrematureWinner();
    }

    void SetLastFlagCapture(Team team)
    {
        _lastFlagCaptureTeam = team;
    }

private:
    Team _lastFlagCaptureTeam;
    bool _bothFlagsKept;
    GuidSet _doors;
    std::array<ObjectGuid, PVP_TEAMS_COUNT> _flags;

    TimeTracker _flagAssaultTimer;
    uint8 _assaultStackCount;
    std::array<ObjectGuid, PVP_TEAMS_COUNT> _capturePointAreaTriggers;
};

void AddSC_battleground_twin_peaks()
{
    RegisterBattlegroundMapScript(battleground_twin_peaks, 726);
}
