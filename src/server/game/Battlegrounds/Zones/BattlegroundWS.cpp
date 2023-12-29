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

#include "BattlegroundWS.h"
#include "AreaTrigger.h"
#include "BattlegroundMgr.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Log.h"
#include "Map.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellInfo.h"

// these variables aren't used outside of this file, so declare them only here
enum BG_WSG_Rewards
{
    BG_WSG_WIN = 0,
    BG_WSG_FLAG_CAP,
    BG_WSG_MAP_COMPLETE,
    BG_WSG_REWARD_NUM
};

uint32 BG_WSG_Honor[2][BG_WSG_REWARD_NUM] =
{
    {20, 40, 40}, // normal honor
    {60, 40, 80}  // holiday
};

enum WarsongGulchPvpStats
{
    PVP_STAT_FLAG_CAPTURES  = 928,
    PVP_STAT_FLAG_RETURNS   = 929
};

BattlegroundWS::BattlegroundWS(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    BgObjects.resize(0);
    BgCreatures.resize(0);

    StartMessageIds[BG_STARTING_EVENT_SECOND] = BG_WS_TEXT_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = BG_WS_TEXT_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = BG_WS_TEXT_BATTLE_HAS_BEGUN;

    _bothFlagsKept = false;

    _lastFlagCaptureTeam = TEAM_OTHER;
    m_ReputationCapture = 0;
    m_HonorWinKills = 0;
    m_HonorEndKills = 0;

    _flags = { };
    _capturePointAreaTriggers = { };

    _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
    _assaultStackCount = 0;
}

BattlegroundWS::~BattlegroundWS() { }

void BattlegroundWS::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (GetElapsedTime() >= 17 * MINUTE * IN_MILLISECONDS)
        {
            if (GetTeamScore(TEAM_ALLIANCE) == 0)
            {
                if (GetTeamScore(TEAM_HORDE) == 0) // No one scored - result is tie
                    EndBattleground(TEAM_OTHER);
                else // Horde has more points and thus wins
                    EndBattleground(HORDE);
            }
            else if (GetTeamScore(TEAM_HORDE) == 0) // Alliance has > 0, Horde has 0, alliance wins
                EndBattleground(ALLIANCE);
            else if (GetTeamScore(TEAM_HORDE) == GetTeamScore(TEAM_ALLIANCE)) // Team score equal, winner is team that scored the last flag
                EndBattleground(_lastFlagCaptureTeam);
            else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))  // Last but not least, check who has the higher score
                EndBattleground(HORDE);
            else
                EndBattleground(ALLIANCE);
        }

        if (_bothFlagsKept)
        {
            _flagAssaultTimer.Update(diff);
            if (_flagAssaultTimer.Passed())
            {
                _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
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

void BattlegroundWS::DoForFlagKeepers(std::function<void(Player*)> action) const
{
    for (ObjectGuid flagGUID : _flags)
    {
        if (GameObject* flag = GetBgMap()->GetGameObject(flagGUID))
        {
            if (Player* carrier = ObjectAccessor::FindPlayer(flag->GetFlagCarrierGUID()))
                action(carrier);
        }
    }
}

void BattlegroundWS::ResetAssaultDebuff()
{
    _bothFlagsKept = false;
    _assaultStackCount = 0;
    _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
    DoForFlagKeepers([&](Player* player) -> void
    {
        RemoveAssaultDebuffFromPlayer(player);
    });
}

void BattlegroundWS::ApplyAssaultDebuffToPlayer(Player* player)
{
    if (_assaultStackCount == 0)
        return;

    uint32 spellId = WS_SPELL_FOCUSED_ASSAULT;
    if (_assaultStackCount >= FLAG_BRUTAL_ASSAULT_STACK_COUNT)
    {
        player->RemoveAurasDueToSpell(WS_SPELL_FOCUSED_ASSAULT);
        spellId = WS_SPELL_BRUTAL_ASSAULT;
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

void BattlegroundWS::RemoveAssaultDebuffFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(WS_SPELL_FOCUSED_ASSAULT);
    player->RemoveAurasDueToSpell(WS_SPELL_BRUTAL_ASSAULT);
}

void BattlegroundWS::StartingEventOpenDoors()
{
    for (ObjectGuid door : _doors)
    {
        if (GameObject* gameObject = GetBgMap()->GetGameObject(door))
        {
            gameObject->UseDoorOrButton();
            gameObject->DespawnOrUnsummon(3s);
        }
    }

    UpdateWorldState(BG_WS_STATE_TIMER_ACTIVE, 1);
    UpdateWorldState(BG_WS_STATE_TIMER, GameTime::GetGameTime() + 15 * MINUTE);

    // players joining later are not eligibles
    TriggerGameEvent(WS_EVENT_START_BATTLE);
}

FlagState BattlegroundWS::GetFlagState(TeamId team) const
{
    if (GameObject* gameObject = FindBgMap()->GetGameObject(_flags[team]))
        return gameObject->GetFlagState();

    return FlagState(0);
}

ObjectGuid const& BattlegroundWS::GetFlagCarrierGUID(TeamId team) const
{
    if (GameObject* gameObject = FindBgMap()->GetGameObject(_flags[team]))
        return gameObject->GetFlagCarrierGUID();

    return ObjectGuid::Empty;
}

void BattlegroundWS::HandleFlagRoomCapturePoint()
{
    DoForFlagKeepers([&](Player* player) -> void
    {
        TeamId team = GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID()));
        if (AreaTrigger* trigger = GetBgMap()->GetAreaTrigger(_capturePointAreaTriggers[team]))
            if (trigger->GetInsideUnits().contains(player->GetGUID()))
                if (CanCaptureFlag(trigger, player))
                    OnCaptureFlag(trigger, player);
    });
}

void BattlegroundWS::UpdateFlagState(uint32 team, FlagState value)
{
    auto transformValueToOtherTeamControlWorldState = [](FlagState value)
    {
        switch (value)
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
        UpdateWorldState(BG_WS_FLAG_STATE_ALLIANCE, AsUnderlyingType(value));
        UpdateWorldState(BG_WS_FLAG_CONTROL_HORDE, transformValueToOtherTeamControlWorldState(value));
    }
    else
    {
        UpdateWorldState(BG_WS_FLAG_STATE_HORDE, AsUnderlyingType(value));
        UpdateWorldState(BG_WS_FLAG_CONTROL_ALLIANCE, transformValueToOtherTeamControlWorldState(value));
    }
}

void BattlegroundWS::UpdateTeamScore(TeamId team)
{
    if (team == TEAM_ALLIANCE)
        UpdateWorldState(BG_WS_FLAG_CAPTURES_ALLIANCE, GetTeamScore(team));
    else
        UpdateWorldState(BG_WS_FLAG_CAPTURES_HORDE, GetTeamScore(team));
}

bool BattlegroundWS::SetupBattleground()
{
    return true;
}

void BattlegroundWS::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[TEAM_ALLIANCE]      = 0;
    m_TeamScores[TEAM_HORDE]         = 0;

    if (sBattlegroundMgr->IsBGWeekend(GetTypeID()))
    {
        m_ReputationCapture = 45;
        m_HonorWinKills = 3;
        m_HonorEndKills = 4;
    }
    else
    {
        m_ReputationCapture = 35;
        m_HonorWinKills = 1;
        m_HonorEndKills = 2;
    }
    _lastFlagCaptureTeam             = TEAM_OTHER;
    _bothFlagsKept                   = false;

    _doors.clear();
    _flags = { };
    _assaultStackCount = 0;
    _flagAssaultTimer.Reset(FLAG_ASSAULT_TIMER);
    _capturePointAreaTriggers = { };
}

void BattlegroundWS::EndBattleground(Team winner)
{
    // Win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), HORDE);

    // Complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundWS::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    EventPlayerDroppedFlag(player);

    Battleground::HandleKillPlayer(player, killer);
}

WorldSafeLocsEntry const* BattlegroundWS::GetClosestGraveyard(Player* player)
{
    return sObjectMgr->GetClosestGraveyard(*player, player->GetBGTeam(), player);
}

WorldSafeLocsEntry const* BattlegroundWS::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? WS_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : WS_EXPLOIT_TELEPORT_LOCATION_HORDE);
}

Team BattlegroundWS::GetPrematureWinner()
{
    if (GetTeamScore(TEAM_ALLIANCE) > GetTeamScore(TEAM_HORDE))
        return ALLIANCE;
    else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))
        return HORDE;

    return Battleground::GetPrematureWinner();
}

void BattlegroundWS::OnGameObjectCreate(GameObject* gameObject)
{
    switch (gameObject->GetEntry())
    {
        case BG_WS_OBJECT_ALLIANCE_DOOR:
        case BG_WS_OBJECT_PORTCULLIS_009:
        case BG_WS_OBJECT_PORTCULLIS_002:
        case BG_WS_OBJECT_COLLISION_PC_SIZE:
        case BG_WS_OBJECT_HORDE_GATE_1:
        case BG_WS_OBJECT_HORDE_GATE_2:
            _doors.insert(gameObject->GetGUID());
            break;
        case BG_WS_OBJECT_ALLIANCE_FLAG_IN_BASE:
            _flags[TEAM_ALLIANCE] = gameObject->GetGUID();
            break;
        case BG_WS_OBJECT_HORDE_FLAG_IN_BASE:
            _flags[TEAM_HORDE] = gameObject->GetGUID();
            break;
        default:
            break;
    }
}

void BattlegroundWS::OnAreaTriggerCreate(AreaTrigger* areaTrigger)
{
    if (!areaTrigger->IsServerSide())
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

void BattlegroundWS::OnFlagStateChange(GameObject* flagInBase, FlagState /*oldValue*/, FlagState newValue, Player* player)
{
    Team team = flagInBase->GetEntry() == BG_WS_OBJECT_HORDE_FLAG_IN_BASE ? HORDE : ALLIANCE;
    TeamId otherTeamId = GetTeamIndexByTeamId(GetOtherTeam(team));

    UpdateFlagState(team, newValue);

    switch (newValue)
    {
        case FlagState::InBase:
        {
            if (GetStatus() == STATUS_IN_PROGRESS)
            {
                ResetAssaultDebuff();
                if (player)
                {
                    // flag got returned to base by player interaction
                    UpdatePvpStat(player, PVP_STAT_FLAG_RETURNS, 1);      // +1 flag returns

                    if (team == ALLIANCE)
                    {
                        SendBroadcastText(BG_WS_TEXT_ALLIANCE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                        PlaySoundToAll(BG_WS_SOUND_FLAG_RETURNED);
                    }
                    else
                    {
                        SendBroadcastText(BG_WS_TEXT_HORDE_FLAG_RETURNED, CHAT_MSG_BG_SYSTEM_HORDE, player);
                        PlaySoundToAll(BG_WS_SOUND_FLAG_RETURNED);
                    }
                }
                // Flag respawned due to timeout/capture
                else if (GetFlagState(otherTeamId) != FlagState::Respawning)
                {
                    // if other flag is respawning, we will let that one handle the message and sound to prevent double message/sound.
                    SendBroadcastText(BG_WS_TEXT_FLAGS_PLACED, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    PlaySoundToAll(BG_WS_SOUND_FLAGS_RESPAWNED);
                }

                HandleFlagRoomCapturePoint();
            }
            break;
        }
        case FlagState::Dropped:
        {
            player->RemoveAurasDueToSpell(BG_WS_SPELL_QUICK_CAP_TIMER);
            RemoveAssaultDebuffFromPlayer(player);

            uint32 recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_HORDE_FLAG;
            if (team == ALLIANCE)
            {
                recentlyDroppedSpellId = SPELL_RECENTLY_DROPPED_ALLIANCE_FLAG;
                SendBroadcastText(BG_WS_TEXT_ALLIANCE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            }
            else
                SendBroadcastText(BG_WS_TEXT_HORDE_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE, player);

            player->CastSpell(player, recentlyDroppedSpellId, true);
            break;
        }
        case FlagState::Taken:
        {
            if (team == HORDE)
            {
                SendBroadcastText(BG_WS_TEXT_HORDE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_HORDE, player);
                PlaySoundToAll(BG_WS_SOUND_HORDE_FLAG_PICKED_UP);
            }
            else
            {
                SendBroadcastText(BG_WS_TEXT_ALLIANCE_FLAG_PICKED_UP, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                PlaySoundToAll(BG_WS_SOUND_ALLIANCE_FLAG_PICKED_UP);
            }

            if (GetFlagState(otherTeamId) == FlagState::Taken)
                _bothFlagsKept = true;

            ApplyAssaultDebuffToPlayer(player);

            flagInBase->CastSpell(player, BG_WS_SPELL_QUICK_CAP_TIMER, true);
            player->StartCriteria(CriteriaStartEvent::BeSpellTarget, BG_WS_SPELL_QUICK_CAP_TIMER, Seconds(GameTime::GetGameTime() - flagInBase->GetFlagTakenFromBaseTime()));
            break;
        }
        case FlagState::Respawning:
            ResetAssaultDebuff();
            break;
        default:
            break;
    }
}

bool BattlegroundWS::CanCaptureFlag(AreaTrigger* areaTrigger, Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return false;

    Team team = GetPlayerTeam(player->GetGUID());
    TeamId teamId = GetTeamIndexByTeamId(team);
    TeamId otherTeamId = GetTeamIndexByTeamId(GetOtherTeam(team));

    if (areaTrigger->GetGUID() != _capturePointAreaTriggers[teamId])
        return false;

    // check if enemy flag's carrier is this player
    if (GetFlagCarrierGUID(otherTeamId) != player->GetGUID())
        return false;

    // check that team's flag is in base
    return GetFlagState(teamId) == FlagState::InBase;
}

void BattlegroundWS::OnCaptureFlag(AreaTrigger* /*areaTrigger*/, Player* player)
{
    Team winner = TEAM_OTHER;

    Team team = GetPlayerTeam(player->GetGUID());
    TeamId teamId = GetTeamIndexByTeamId(team);
    TeamId otherTeamId = GetTeamIndexByTeamId(GetOtherTeam(team));

    /*
        1. Update flag states & score world states
        2. udpate points
        3. chat message & sound
        4. update criterias & achievements
        5. remove all related auras
        ?. Reward honor & reputation
    */

    // 1. update the flag states
    for (uint8 i = 0; i < _flags.size(); i++)
        if (GameObject* gameObject = GetBgMap()->GetGameObject(_flags[i]))
            gameObject->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

    // 2. update points
    if (GetTeamScore(teamId) < BG_WS_MAX_TEAM_SCORE)
        AddPoint(team, 1);

    UpdateTeamScore(teamId);

    // 3. chat message & sound
    if (team == ALLIANCE)
    {
        SendBroadcastText(BG_WS_TEXT_CAPTURED_HORDE_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
        PlaySoundToAll(BG_WS_SOUND_FLAG_CAPTURED_ALLIANCE);
        RewardReputationToTeam(890, m_ReputationCapture, ALLIANCE);
        player->CastSpell(player, SPELL_CAPTURED_ALLIANCE_COSMETIC_FX);
    }
    else
    {
        SendBroadcastText(BG_WS_TEXT_CAPTURED_ALLIANCE_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
        PlaySoundToAll(BG_WS_SOUND_FLAG_CAPTURED_HORDE);
        RewardReputationToTeam(889, m_ReputationCapture, HORDE);
        player->CastSpell(player, SPELL_CAPTURED_HORDE_COSMETIC_FX);
    }

    // 4. update criteria's for achievement, player score etc.
    UpdatePvpStat(player, PVP_STAT_FLAG_CAPTURES, 1);      // +1 flag captures

    // 5. Remove all related auras
    RemoveAssaultDebuffFromPlayer(player);

    if (GameObject* gameObject = GetBgMap()->GetGameObject(_flags[otherTeamId]))
        player->RemoveAurasDueToSpell(gameObject->GetGOInfo()->newflag.pickupSpell, gameObject->GetGUID());

    player->RemoveAurasDueToSpell(BG_WS_SPELL_QUICK_CAP_TIMER);

    player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);

    RewardHonorToTeam(GetBonusHonorFromKill(2), team);

    // update last flag capture to be used if teamscore is equal
    SetLastFlagCapture(team);

    if (GetTeamScore(teamId) == BG_WS_MAX_TEAM_SCORE)
        winner = team;

    if (winner)
    {
        UpdateWorldState(BG_WS_FLAG_STATE_ALLIANCE, 1);
        UpdateWorldState(BG_WS_FLAG_STATE_HORDE, 1);
        UpdateWorldState(BG_WS_STATE_TIMER_ACTIVE, 0);

        RewardHonorToTeam(BG_WSG_Honor[BattlegroundMgr::IsBGWeekend(GetTypeID()) ? 1 : 0][BG_WSG_WIN], winner);
        EndBattleground(winner);
    }
}
