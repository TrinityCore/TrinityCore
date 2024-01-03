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

#include "BattlegroundEY.h"
#include "AreaTrigger.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "Creature.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "Util.h"

enum EyeOfTheStormPvpStats
{
    PVP_STAT_FLAG_CAPTURES = 183
};

BattlegroundEY::BattlegroundEY(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    BgObjects.resize(0);
    BgCreatures.resize(0);
    m_HonorScoreTics = { 0, 0 };
    m_FlagCapturedBgObjectType = 0;
    m_HonorTics = 0;
    _pointsTimer.Reset(POINTS_TICK_TIME);
    _assaultEnabled = false;
    _assaultStackCount = 0;
    _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);
}

BattlegroundEY::~BattlegroundEY() { }

void BattlegroundEY::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        _pointsTimer.Update(diff);
        if (_pointsTimer.Passed())
        {
            _pointsTimer.Reset(POINTS_TICK_TIME);

            uint8 baseCountAlliance = GetControlledBaseCount(TEAM_ALLIANCE);
            uint8 baseCountHorde = GetControlledBaseCount(TEAM_HORDE);
            if (baseCountAlliance > 0)
                AddPoints(ALLIANCE, BG_EY_TickPoints[baseCountAlliance - 1]);
            if (baseCountHorde > 0)
                AddPoints(HORDE, BG_EY_TickPoints[baseCountHorde - 1]);
        }

        if (_assaultEnabled)
        {
            _flagAssaultTimer.Update(diff);
            if (_flagAssaultTimer.Passed())
            {
                _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);
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

void BattlegroundEY::StartingEventOpenDoors()
{
    for (ObjectGuid const& door : _doorGUIDs)
    {
        if (GameObject* gameObject = GetBgMap()->GetGameObject(door))
        {
            gameObject->UseDoorOrButton();
            gameObject->DespawnOrUnsummon(3s);
        }
    }

    // Achievement: Flurry
    TriggerGameEvent(BG_EY_EVENT_START_BATTLE);
}

void BattlegroundEY::AddPoints(Team team, uint32 Points)
{
    TeamId team_index = GetTeamIndexByTeamId(team);
    m_TeamScores[team_index] += Points;
    m_HonorScoreTics[team_index] += Points;
    if (m_HonorScoreTics[team_index] >= m_HonorTics)
    {
        RewardHonorToTeam(GetBonusHonorFromKill(1), team);
        m_HonorScoreTics[team_index] -= m_HonorTics;
    }
    UpdateTeamScore(team_index);
}

uint8 BattlegroundEY::GetControlledBaseCount(TeamId teamId) const
{
    uint8 baseCount = 0;
    for (auto const& controlZoneHandler : _controlZoneHandlers)
    {
        uint32 point = controlZoneHandler.second->GetPoint();
        switch (teamId)
        {
            case TEAM_ALLIANCE:
                if (GetBgMap()->GetWorldStateValue(m_PointsIconStruct[point].WorldStateAllianceControlledIndex) == 1)
                    baseCount++;
                break;
            case TEAM_HORDE:
                if (GetBgMap()->GetWorldStateValue(m_PointsIconStruct[point].WorldStateHordeControlledIndex) == 1)
                    baseCount++;
                break;
            default:
                break;
        }
    }
    return baseCount;
}

void BattlegroundEY::DoForFlagKeepers(std::function<void(Player*)> action) const
{
    if (GameObject* flag = GetBgMap()->GetGameObject(_flagGUID))
    {
        if (Player* carrier = ObjectAccessor::FindPlayer(flag->GetFlagCarrierGUID()))
            action(carrier);
    }
}

void BattlegroundEY::ResetAssaultDebuff()
{
    _assaultEnabled = false;
    _assaultStackCount = 0;
    _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);
    DoForFlagKeepers([&](Player* player) -> void
    {
        RemoveAssaultDebuffFromPlayer(player);
    });
}

void BattlegroundEY::ApplyAssaultDebuffToPlayer(Player* player)
{
    if (_assaultStackCount == 0)
        return;

    uint32 spellId = BG_EY_FOCUSED_ASSAULT_SPELL;
    if (_assaultStackCount >= BG_EY_FLAG_BRUTAL_ASSAULT_STACK_COUNT)
    {
        player->RemoveAurasDueToSpell(BG_EY_FOCUSED_ASSAULT_SPELL);
        spellId = BG_EY_BRUTAL_ASSAULT_SPELL;
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

void BattlegroundEY::RemoveAssaultDebuffFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(BG_EY_FOCUSED_ASSAULT_SPELL);
    player->RemoveAurasDueToSpell(BG_EY_BRUTAL_ASSAULT_SPELL);
}

void BattlegroundEY::UpdateTeamScore(TeamId Team)
{
    uint32 score = GetTeamScore(Team);

    if (score >= BG_EY_MAX_TEAM_SCORE)
    {
        score = BG_EY_MAX_TEAM_SCORE;
        if (Team == TEAM_ALLIANCE)
            EndBattleground(ALLIANCE);
        else
            EndBattleground(HORDE);
    }

    if (Team == TEAM_ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_RESOURCES, score);
    else
        UpdateWorldState(EY_HORDE_RESOURCES, score);
}

void BattlegroundEY::EndBattleground(Team winner)
{
    // Win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    // Complete map reward
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundEY::UpdatePointsCount(TeamId teamId)
{
    if (teamId == TEAM_ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_BASE, GetControlledBaseCount(TEAM_ALLIANCE));
    else
        UpdateWorldState(EY_HORDE_BASE, GetControlledBaseCount(TEAM_HORDE));
}

void BattlegroundEY::OnGameObjectCreate(GameObject* gameObject)
{
    switch (gameObject->GetEntry())
    {
        case BG_OBJECT_A_DOOR_EY_ENTRY:
        case BG_OBJECT_H_DOOR_EY_ENTRY:
            _doorGUIDs.insert(gameObject->GetGUID());
            break;
        case BG_OBJECT_FLAG2_EY_ENTRY:
            _flagGUID = gameObject->GetGUID();
            break;
        default:
            break;
    }
}

bool BattlegroundEY::CanCaptureFlag(AreaTrigger* areaTrigger, Player* player)
{
    if (areaTrigger->GetEntry() != AREATRIGGER_CAPTURE_FLAG)
        return false;

    if (GameObject* flag = GetBgMap()->GetGameObject(_flagGUID))
    {
        if (flag->GetFlagCarrierGUID() != player->GetGUID())
            return false;
    }

    if (GameObject* controlzone = player->FindNearestGameObjectWithOptions(40.0f, { .StringId = "bg_eye_of_the_storm_control_zone" }))
    {
        uint32 point = _controlZoneHandlers[controlzone->GetEntry()]->GetPoint();
        switch (GetPlayerTeam(player->GetGUID()))
        {
            case ALLIANCE:
                return GetBgMap()->GetWorldStateValue(m_PointsIconStruct[point].WorldStateAllianceControlledIndex) == 1;
            case HORDE:
                return GetBgMap()->GetWorldStateValue(m_PointsIconStruct[point].WorldStateHordeControlledIndex) == 1;
            default:
                return false;
        }
    }

    return false;
}

void BattlegroundEY::OnCaptureFlag(AreaTrigger* areaTrigger, Player* player)
{
    if (areaTrigger->GetEntry() != AREATRIGGER_CAPTURE_FLAG)
        return;

    uint32 baseCount = GetControlledBaseCount(GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID())));

    if (GameObject* gameObject = GetBgMap()->GetGameObject(_flagGUID))
        gameObject->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

    Team team = Team(GetPlayerTeam(player->GetGUID()));
    if (team == ALLIANCE)
    {
        SendBroadcastText(BG_EY_TEXT_ALLIANCE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE);
    }
    else
    {
        SendBroadcastText(BG_EY_TEXT_HORDE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_HORDE);
    }

    if (baseCount > 0)
        AddPoints(team, BG_EY_FlagPoints[baseCount - 1]);

    UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_BASE);
    UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_BASE);

    UpdatePvpStat(player, PVP_STAT_FLAG_CAPTURES, 1);

    player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
    player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
}

void BattlegroundEY::OnFlagStateChange(GameObject* /*flagInBase*/, FlagState /*oldValue*/, FlagState newValue, Player* player)
{
    switch (newValue)
    {
        case FlagState::InBase:
            ResetAssaultDebuff();
            break;
        case FlagState::Dropped:
            player->CastSpell(player, SPELL_RECENTLY_DROPPED_NEUTRAL_FLAG, true);
            RemoveAssaultDebuffFromPlayer(player);

            UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_WAIT_RESPAWN);
            UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_WAIT_RESPAWN);

            if (GetPlayerTeam(player->GetGUID()) == ALLIANCE)
                SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE);
            else
                SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE);
            break;
        case FlagState::Taken:
            if (GetPlayerTeam(player->GetGUID()) == ALLIANCE)
            {
                UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_PLAYER);
                PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE);
                SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            }
            else
            {
                UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_PLAYER);
                PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_HORDE);
                SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
            }

            ApplyAssaultDebuffToPlayer(player);
            _assaultEnabled = true;

            player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
            break;
        case FlagState::Respawning:
            ResetAssaultDebuff();
            break;
        default:
            break;
    }

    UpdateWorldState(NETHERSTORM_FLAG, AsUnderlyingType(newValue));
}

void BattlegroundEY::HandleAreaTrigger(Player* player, uint32 trigger, bool entered)
{
    if (!player->IsAlive())                                  //hack code, must be removed later
        return;

    switch (trigger)
    {
        case 4530: // Horde Start
        case 4531: // Alliance Start
            if (GetStatus() == STATUS_WAIT_JOIN && !entered)
                TeleportPlayerToExploitLocation(player);
            break;
        case 4512:
        case 4515:
        case 4517:
        case 4519:
        case 4568:
        case 4569:
        case 4570:
        case 4571:
        case 5866:
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger, entered);
            break;
    }
}

bool BattlegroundEY::SetupBattleground()
{
    UpdateWorldState(EY_MAX_RESOURCES, BG_EY_MAX_TEAM_SCORE);

    _controlZoneHandlers[BG_OBJECT_FR_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(this, FEL_REAVER);
    _controlZoneHandlers[BG_OBJECT_BE_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(this, BLOOD_ELF);
    _controlZoneHandlers[BG_OBJECT_DR_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(this, DRAENEI_RUINS);
    _controlZoneHandlers[BG_OBJECT_HU_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(this, MAGE_TOWER);

    return true;
}

void BattlegroundEY::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[TEAM_ALLIANCE] = 0;
    m_TeamScores[TEAM_HORDE] = 0;
    m_HonorScoreTics = { 0, 0 };
    m_FlagCapturedBgObjectType = 0;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_EY_EYWeekendHonorTicks : BG_EY_NotEYWeekendHonorTicks;
}

void BattlegroundEY::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
    EventPlayerDroppedFlag(player);
}

void BattlegroundEY::EventTeamLostPoint(TeamId teamId, uint32 point, GameObject* controlZone)
{
    if (teamId == TEAM_ALLIANCE)
    {
        SendBroadcastText(m_LosingPointTypes[point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, controlZone);
        UpdateWorldState(m_PointsIconStruct[point].WorldStateAllianceControlledIndex, 0);
    }
    else if (teamId == TEAM_HORDE)
    {
        SendBroadcastText(m_LosingPointTypes[point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, controlZone);
        UpdateWorldState(m_PointsIconStruct[point].WorldStateHordeControlledIndex, 0);
    }

    UpdateWorldState(m_PointsIconStruct[point].WorldStateControlIndex, 1);
    UpdatePointsCount(teamId);
}

void BattlegroundEY::EventTeamCapturedPoint(TeamId teamId, uint32 point, GameObject* controlZone)
{
    if (teamId == TEAM_ALLIANCE)
    {
        SendBroadcastText(m_CapturingPointTypes[point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, controlZone);
        UpdateWorldState(m_PointsIconStruct[point].WorldStateAllianceControlledIndex, 1);
    }
    else if (teamId == TEAM_HORDE)
    {
        SendBroadcastText(m_CapturingPointTypes[point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, controlZone);
        UpdateWorldState(m_PointsIconStruct[point].WorldStateHordeControlledIndex, 1);
    }

    UpdateWorldState(m_PointsIconStruct[point].WorldStateControlIndex, 0);
    UpdatePointsCount(teamId);
}

WorldSafeLocsEntry const* BattlegroundEY::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? EY_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : EY_EXPLOIT_TELEPORT_LOCATION_HORDE);
}

Team BattlegroundEY::GetPrematureWinner()
{
    if (GetTeamScore(TEAM_ALLIANCE) > GetTeamScore(TEAM_HORDE))
        return ALLIANCE;
    else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))
        return HORDE;

    return Battleground::GetPrematureWinner();
}

void BattlegroundEY::ProcessEvent(WorldObject* target, uint32 eventId, WorldObject* invoker)
{
    Battleground::ProcessEvent(target, eventId, invoker);

    if (invoker)
    {
        if (GameObject* gameobject = invoker->ToGameObject())
        {
            if (gameobject->GetGoType() == GAMEOBJECT_TYPE_CONTROL_ZONE)
            {
                if (!_controlZoneHandlers.contains(gameobject->GetEntry()))
                    return;

                auto controlzone = gameobject->GetGOInfo()->controlZone;
                BattlegroundEYControlZoneHandler& handler = *_controlZoneHandlers[invoker->GetEntry()];
                if (eventId == controlzone.NeutralEventAlliance)
                    handler.HandleNeutralEventAlliance(gameobject);
                else if (eventId == controlzone.NeutralEventHorde)
                    handler.HandleNeutralEventHorde(gameobject);
                else if (eventId == controlzone.ProgressEventAlliance)
                    handler.HandleProgressEventAlliance(gameobject);
                else if (eventId == controlzone.ProgressEventHorde)
                    handler.HandleProgressEventHorde(gameobject);
            }
        }
    }
}

BattlegroundEYControlZoneHandler::BattlegroundEYControlZoneHandler(BattlegroundEY* bg, uint32 point) : ControlZoneHandler(),
    _battleground(bg), _point(point)
{
}

void BattlegroundEYControlZoneHandler::HandleProgressEventHorde(GameObject* controlZone)
{
    _battleground->EventTeamCapturedPoint(TEAM_HORDE, _point, controlZone);
}

void BattlegroundEYControlZoneHandler::HandleProgressEventAlliance(GameObject* controlZone)
{
    _battleground->EventTeamCapturedPoint(TEAM_ALLIANCE, _point, controlZone);
}

void BattlegroundEYControlZoneHandler::HandleNeutralEventHorde(GameObject* controlZone)
{
    _battleground->EventTeamLostPoint(TEAM_HORDE, _point, controlZone);
}

void BattlegroundEYControlZoneHandler::HandleNeutralEventAlliance(GameObject* controlZone)
{
    _battleground->EventTeamLostPoint(TEAM_ALLIANCE, _point, controlZone);
}
