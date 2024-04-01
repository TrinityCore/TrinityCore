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
#include "BattlegroundScript.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Timer.h"

struct battleground_warsong_gulch : BattlegroundScript
{
    static constexpr Seconds FLAG_ASSAULT_TIMER = 30s;

    enum Misc
    {
        MAX_TEAM_SCORE                          = 3,
        FLAG_BRUTAL_ASSAULT_STACK_COUNT         = 5
    };

    enum Spells : uint32
    {
        SPELL_FOCUSED_ASSAULT                   = 46392,
        SPELL_BRUTAL_ASSAULT                    = 46393,
        SPELL_CAPTURED_ALLIANCE_COSMETIC_FX     = 262508,
        SPELL_CAPTURED_HORDE_COSMETIC_FX        = 262512,
        SPELL_WARSONG_FLAG                      = 23333,
        SPELL_WARSONG_FLAG_DROPPED              = 23334,
        SPELL_SILVERWING_FLAG                   = 23335,
        SPELL_SILVERWING_FLAG_DROPPED           = 23336,
        SPELL_QUICK_CAP_TIMER                   = 183317,
    };

    enum AreaTriggers : uint32
    {
        AT_CAPTURE_POINT_ALLIANCE               = 30,
        AT_CAPTURE_POINT_HORDE                  = 31
    };

    enum Events : uint32
    {
        EVENT_START_BATTLE                      = 35912
    };

    enum PvpStats : uint32
    {
        PVP_STAT_FLAG_CAPTURES                  = 928,
        PVP_STAT_FLAG_RETURNS                   = 929
    };

    enum WorldStates : int32
    {
        WORLD_STATE_FLAG_STATE_ALLIANCE             = 1545,
        WORLD_STATE_FLAG_STATE_HORDE                = 1546,
        WORLD_STATE_FLAG_STATE_NEUTRAL              = 1547,
        WORLD_STATE_HORDE_FLAG_COUNT_PICKED_UP      = 17712,
        WORLD_STATE_ALLIANCE_FLAG_COUNT_PICKED_UP   = 17713,
        WORLD_STATE_FLAG_CAPTURES_ALLIANCE          = 1581,
        WORLD_STATE_FLAG_CAPTURES_HORDE             = 1582,
        WORLD_STATE_FLAG_CAPTURES_MAX               = 1601,
        WORLD_STATE_FLAG_CAPTURES_MAX_NEW           = 17303,
        WORLD_STATE_FLAG_CONTROL_HORDE              = 2338,
        WORLD_STATE_FLAG_CONTROL_ALLIANCE           = 2339,
        WORLD_STATE_STATE_TIMER                     = 4248,
        WORLD_STATE_STATE_TIMER_ACTIVE              = 4247
    };

    enum Texts
    {
        TEXT_START_ONE_MINUTE                   = 10015,
        TEXT_START_HALF_MINUTE                  = 10016,
        TEXT_BATTLE_HAS_BEGUN                   = 10014,
        TEXT_CAPTURED_HORDE_FLAG                = 9801,
        TEXT_CAPTURED_ALLIANCE_FLAG             = 9802,
        TEXT_FLAGS_PLACED                       = 9803,
        TEXT_ALLIANCE_FLAG_PICKED_UP            = 9804,
        TEXT_ALLIANCE_FLAG_DROPPED              = 9805,
        TEXT_HORDE_FLAG_PICKED_UP               = 9807,
        TEXT_HORDE_FLAG_DROPPED                 = 9806,
        TEXT_ALLIANCE_FLAG_RETURNED             = 9808,
        TEXT_HORDE_FLAG_RETURNED                = 9809
    };

    enum Sounds
    {
        SOUND_FLAG_CAPTURED_ALLIANCE            = 8173,
        SOUND_FLAG_CAPTURED_HORDE               = 8213,
        SOUND_FLAG_PLACED                       = 8232,
        SOUND_FLAG_RETURNED                     = 8192,
        SOUND_HORDE_FLAG_PICKED_UP              = 8212,
        SOUND_ALLIANCE_FLAG_PICKED_UP           = 8174,
        SOUND_FLAGS_RESPAWNED                   = 8232
    };

    enum GameObjects
    {
        OBJECT_ALLIANCE_DOOR                    = 309704,
        OBJECT_PORTCULLIS_009                   = 309705,
        OBJECT_PORTCULLIS_002                   = 309883,
        OBJECT_COLLISION_PC_SIZE                = 242273,
        OBJECT_HORDE_GATE_1                     = 352709,
        OBJECT_HORDE_GATE_2                     = 352710,
        OBJECT_ALLIANCE_FLAG_IN_BASE            = 227741,
        OBJECT_HORDE_FLAG_IN_BASE               = 227740
    };

    static constexpr std::array<std::array<uint32, 3>, 2> HONOR_REWARDS =
    {{
        { 20, 40, 40 },
        { 60, 40, 80 }
    }};

    explicit battleground_warsong_gulch(BattlegroundMap* map) : BattlegroundScript(map), _lastFlagCaptureTeam(TEAM_OTHER), _bothFlagsKept(false), _flags({ }), _assaultStackCount(0), _capturePointAreaTriggers({ })
    {
        _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);

        if (sBattlegroundMgr->IsBGWeekend(battleground->GetTypeID()))
        {
            _reputationCapture = 45;
            _honorWinKills = 3;
            _honorEndKills = 4;
        }
        else
        {
            _reputationCapture = 35;
            _honorWinKills = 1;
            _honorEndKills = 2;
        }
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
                _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
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

        UpdateWorldState(WORLD_STATE_STATE_TIMER_ACTIVE, 1);
        UpdateWorldState(WORLD_STATE_STATE_TIMER, std::chrono::system_clock::to_time_t(GameTime::GetSystemTime() + 15min));

        // players joining later are not eligibles
        TriggerGameEvent(EVENT_START_BATTLE);
    }

    void OnEnd(Team winner) override
    {
        BattlegroundScript::OnEnd(winner);
        // Win reward
        if (winner == ALLIANCE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(_honorWinKills), ALLIANCE);
        if (winner == HORDE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(_honorWinKills), HORDE);

        // Complete map_end rewards (even if no team wins)
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(_honorEndKills), ALLIANCE);
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(_honorEndKills), HORDE);
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
        _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
        DoForFlagKeepers([&](Player* player) -> void
        {
            RemoveAssaultDebuffFromPlayer(player);
        });
    }

    void ApplyAssaultDebuffToPlayer(Player* player) const
    {
        if (_assaultStackCount == 0)
            return;

        uint32 spellId = SPELL_FOCUSED_ASSAULT;
        if (_assaultStackCount >= FLAG_BRUTAL_ASSAULT_STACK_COUNT)
        {
            player->RemoveAurasDueToSpell(SPELL_FOCUSED_ASSAULT);
            spellId = SPELL_BRUTAL_ASSAULT;
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
        player->RemoveAurasDueToSpell(SPELL_FOCUSED_ASSAULT);
        player->RemoveAurasDueToSpell(SPELL_BRUTAL_ASSAULT);
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
            UpdateWorldState(WORLD_STATE_FLAG_STATE_ALLIANCE, AsUnderlyingType(value));
            UpdateWorldState(WORLD_STATE_FLAG_CONTROL_HORDE, transformValueToOtherTeamControlWorldState(value));
        }
        else
        {
            UpdateWorldState(WORLD_STATE_FLAG_STATE_HORDE, AsUnderlyingType(value));
            UpdateWorldState(WORLD_STATE_FLAG_CONTROL_ALLIANCE, transformValueToOtherTeamControlWorldState(value));
        }
    }

    void UpdateTeamScore(TeamId team) const
    {
        if (team == TEAM_ALLIANCE)
            UpdateWorldState(WORLD_STATE_FLAG_CAPTURES_ALLIANCE, battleground->GetTeamScore(team));
        else
            UpdateWorldState(WORLD_STATE_FLAG_CAPTURES_HORDE, battleground->GetTeamScore(team));
    }

    void OnGameObjectCreate(GameObject* gameObject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameObject);
        switch (gameObject->GetEntry())
        {
            case OBJECT_ALLIANCE_DOOR:
            case OBJECT_PORTCULLIS_009:
            case OBJECT_PORTCULLIS_002:
            case OBJECT_COLLISION_PC_SIZE:
            case OBJECT_HORDE_GATE_1:
            case OBJECT_HORDE_GATE_2:
                _doors.insert(gameObject->GetGUID());
                break;
            case OBJECT_ALLIANCE_FLAG_IN_BASE:
                _flags[TEAM_ALLIANCE] = gameObject->GetGUID();
                break;
            case OBJECT_HORDE_FLAG_IN_BASE:
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
            case AT_CAPTURE_POINT_ALLIANCE:
                _capturePointAreaTriggers[TEAM_ALLIANCE] = areaTrigger->GetGUID();
                break;
            case AT_CAPTURE_POINT_HORDE:
                _capturePointAreaTriggers[TEAM_HORDE] = areaTrigger->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnFlagStateChange(GameObject* flagInBase, FlagState oldValue, FlagState newValue, Player* player) override
    {
        BattlegroundScript::OnFlagStateChange(flagInBase, oldValue, newValue, player);

        Team const team = flagInBase->GetEntry() == OBJECT_HORDE_FLAG_IN_BASE ? HORDE : ALLIANCE;
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
                        battleground->UpdatePvpStat(player, PVP_STAT_FLAG_RETURNS, 1);      // +1 flag returns

                        if (team == ALLIANCE)
                        {
                            battleground->SendBroadcastText(TEXT_ALLIANCE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                            battleground->PlaySoundToAll(SOUND_FLAG_RETURNED);
                        }
                        else
                        {
                            battleground->SendBroadcastText(TEXT_HORDE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_HORDE, player);
                            battleground->PlaySoundToAll(SOUND_FLAG_RETURNED);
                        }
                    }
                    // Flag respawned due to timeout/capture
                    else if (GetFlagState(otherTeamId) != FlagState::Respawning)
                    {
                        // if other flag is respawning, we will let that one handle the message and sound to prevent double message/sound.
                        battleground->SendBroadcastText(TEXT_FLAGS_PLACED, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        battleground->PlaySoundToAll(SOUND_FLAGS_RESPAWNED);
                    }

                    HandleFlagRoomCapturePoint();
                }
                break;
            }
            case FlagState::Dropped:
            {
                player->RemoveAurasDueToSpell(SPELL_QUICK_CAP_TIMER);
                RemoveAssaultDebuffFromPlayer(player);

                uint32 recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_HORDE_FLAG;
                if (team == ALLIANCE)
                {
                    recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_ALLIANCE_FLAG;
                    battleground->SendBroadcastText(TEXT_ALLIANCE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                }
                else
                    battleground->SendBroadcastText(TEXT_HORDE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE, player);

                player->CastSpell(player, recentlyDroppedSpellId, true);
                break;
            }
            case FlagState::Taken:
            {
                if (team == HORDE)
                {
                    battleground->SendBroadcastText(TEXT_HORDE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_HORDE, player);
                    battleground->PlaySoundToAll(SOUND_HORDE_FLAG_PICKED_UP);
                }
                else
                {
                    battleground->SendBroadcastText(TEXT_ALLIANCE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                    battleground->PlaySoundToAll(SOUND_ALLIANCE_FLAG_PICKED_UP);
                }

                if (GetFlagState(otherTeamId) == FlagState::Taken)
                    _bothFlagsKept = true;

                ApplyAssaultDebuffToPlayer(player);

                flagInBase->CastSpell(player, SPELL_QUICK_CAP_TIMER, true);
                player->StartCriteria(CriteriaStartEvent::BeSpellTarget, SPELL_QUICK_CAP_TIMER, Seconds(GameTime::GetGameTime() - flagInBase->GetFlagTakenFromBaseTime()));
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
        for (ObjectGuid const& flagGuid: _flags)
            if (GameObject const* flag = battlegroundMap->GetGameObject(flagGuid))
                flag->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

        // 2. update points
        if (battleground->GetTeamScore(teamId) < MAX_TEAM_SCORE)
            battleground->AddPoint(team, 1);

        UpdateTeamScore(teamId);

        // 3. chat message & sound
        if (team == ALLIANCE)
        {
            battleground->SendBroadcastText(TEXT_CAPTURED_HORDE_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
            battleground->PlaySoundToAll(SOUND_FLAG_CAPTURED_ALLIANCE);
            battleground->RewardReputationToTeam(890, _reputationCapture, ALLIANCE);
            player->CastSpell(player, SPELL_CAPTURED_ALLIANCE_COSMETIC_FX);
        }
        else
        {
            battleground->SendBroadcastText(TEXT_CAPTURED_ALLIANCE_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            battleground->PlaySoundToAll(SOUND_FLAG_CAPTURED_HORDE);
            battleground->RewardReputationToTeam(889, _reputationCapture, HORDE);
            player->CastSpell(player, SPELL_CAPTURED_HORDE_COSMETIC_FX);
        }

        // 4. update criteria's for achievement, player score etc.
        battleground->UpdatePvpStat(player, PVP_STAT_FLAG_CAPTURES, 1);      // +1 flag captures

        // 5. Remove all related auras
        RemoveAssaultDebuffFromPlayer(player);

        if (GameObject const* flag = battlegroundMap->GetGameObject(_flags[otherTeamId]))
            player->RemoveAurasDueToSpell(flag->GetGOInfo()->newflag.pickupSpell, flag->GetGUID());

        player->RemoveAurasDueToSpell(SPELL_QUICK_CAP_TIMER);

        player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);

        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(2), team);

        // update last flag capture to be used if teamscore is equal
        SetLastFlagCapture(team);

        if (battleground->GetTeamScore(teamId) == MAX_TEAM_SCORE)
            winner = team;

        if (winner)
        {
            UpdateWorldState(WORLD_STATE_FLAG_STATE_ALLIANCE, 1);
            UpdateWorldState(WORLD_STATE_FLAG_STATE_HORDE, 1);
            UpdateWorldState(WORLD_STATE_STATE_TIMER_ACTIVE, 0);

            battleground->RewardHonorToTeam(HONOR_REWARDS[BattlegroundMgr::IsBGWeekend(battleground->GetTypeID()) ? 1 : 0][0], winner);
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

    uint32 _honorWinKills;
    uint32 _honorEndKills;
    uint32 _reputationCapture;
};

void AddSC_battleground_warsong_gulch()
{
    RegisterBattlegroundMapScript(battleground_warsong_gulch, 2106);
}
