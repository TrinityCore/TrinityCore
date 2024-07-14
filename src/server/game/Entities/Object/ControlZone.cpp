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

#include "ControlZone.h"

#include "GameEventSender.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "Object.h"
#include "ObjectAccessor.h"

ControlZone::ControlZone(WorldObject* owner, GameObjectTemplate const* gameobjectTemplate) : _owner(owner), _controlZoneTemplate(gameobjectTemplate), _enabled(true)
{
    ASSERT(gameobjectTemplate->type == GAMEOBJECT_TYPE_CONTROL_ZONE);

    if (owner->GetMap()->Instanceable())
        _heartbeatRate = 1s;
    else if (gameobjectTemplate->controlZone.FrequentHeartbeat)
        _heartbeatRate = 2500ms;
    else
        _heartbeatRate = 5s;

    _heartbeatTracker.Reset(_heartbeatRate);
    _previousTeamId = GetControllingTeam();
    _contestedTriggered = false;
    _value = static_cast<float>(gameobjectTemplate->controlZone.startingValue);
}

void ControlZone::Update(uint32 diff)
{
    if (!_enabled)
        return;

    _heartbeatTracker.Update(diff);
    if (_heartbeatTracker.Passed())
    {
        _heartbeatTracker.Reset(_heartbeatRate);
        HandleHeartbeat();
    }
}

TeamId ControlZone::GetControllingTeam() const
{
    if (_value < GetMaxHordeValue())
        return TEAM_HORDE;

    if (_value > GetMinAllianceValue())
        return TEAM_ALLIANCE;

    return TEAM_NEUTRAL;
}

GuidUnorderedSet const* ControlZone::GetInsidePlayers() const
{
    return &_insidePlayers;
}

void ControlZone::SetValue(float value)
{
    _value = RoundToInterval<float>(value, 0.0f, 100.0f);
}

void ControlZone::HandleHeartbeat()
{
    // update player list inside control zone
    std::vector<Player*> targetList;
    SearchTargets(targetList);

    TeamId const oldControllingTeam = GetControllingTeam();
    float const pointsGained = CalculatePointsPerSecond(targetList) * _heartbeatRate.count() / 1000.0f;
    if (pointsGained == 0)
        return;

    int32 const oldRoundedValue = static_cast<int32>(_value);
    SetValue(_value + pointsGained);
    int32 const roundedValue = static_cast<int32>(_value);
    if (oldRoundedValue == roundedValue)
        return;

    TeamId const newControllingTeam = GetControllingTeam();
    TeamId const assaultingTeam = pointsGained > 0 ? TEAM_ALLIANCE : TEAM_HORDE;

    if (oldControllingTeam != newControllingTeam)
        _contestedTriggered = false;

    if (oldControllingTeam != TEAM_ALLIANCE && newControllingTeam == TEAM_ALLIANCE)
        TriggerEvent(_controlZoneTemplate->controlZone.ProgressEventAlliance);
    else if (oldControllingTeam != TEAM_HORDE && newControllingTeam == TEAM_HORDE)
        TriggerEvent(_controlZoneTemplate->controlZone.ProgressEventHorde);
    else if (oldControllingTeam == TEAM_HORDE && newControllingTeam == TEAM_NEUTRAL)
        TriggerEvent(_controlZoneTemplate->controlZone.NeutralEventHorde);
    else if (oldControllingTeam == TEAM_ALLIANCE && newControllingTeam == TEAM_NEUTRAL)
        TriggerEvent(_controlZoneTemplate->controlZone.NeutralEventAlliance);

    if (roundedValue == 100 && newControllingTeam == TEAM_ALLIANCE && assaultingTeam == TEAM_ALLIANCE)
        TriggerEvent(_controlZoneTemplate->controlZone.CaptureEventAlliance);
    else if (roundedValue == 0 && newControllingTeam == TEAM_HORDE && assaultingTeam == TEAM_HORDE)
        TriggerEvent(_controlZoneTemplate->controlZone.CaptureEventHorde);

    if (oldRoundedValue == 100 && assaultingTeam == TEAM_HORDE && !_contestedTriggered)
    {
        TriggerEvent(_controlZoneTemplate->controlZone.ContestedEventHorde);
        _contestedTriggered = true;
    }
    else if (oldRoundedValue == 0 && assaultingTeam == TEAM_ALLIANCE && !_contestedTriggered)
    {
        TriggerEvent(_controlZoneTemplate->controlZone.ContestedEventAlliance);
        _contestedTriggered = true;
    }

    for (Player* player : targetList)
        player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldstate2, roundedValue);
}

void ControlZone::SearchTargets(std::vector<Player*>& targetList)
{
    Trinity::AnyUnitInObjectRangeCheck check(_owner, _controlZoneTemplate->controlZone.radius, true);
    Trinity::PlayerListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(_owner, targetList, check);
    Cell::VisitWorldObjects(_owner, searcher, _controlZoneTemplate->controlZone.radius);
    HandleUnitEnterExit(targetList);
}

float ControlZone::CalculatePointsPerSecond(std::vector<Player*> const& targetList) const
{
    int32 delta = 0;

    for (Player const* player : targetList)
    {
        if (!player->IsOutdoorPvPActive())
            continue;

        if (player->GetTeamId() == TEAM_HORDE)
            delta--;
        else
            delta++;
    }

    uint32 const minTime = _controlZoneTemplate->controlZone.minTime;
    uint32 const maxTime = _controlZoneTemplate->controlZone.maxTime;
    uint32 const minSuperiority = _controlZoneTemplate->controlZone.minSuperiority;
    uint32 const maxSuperiority = _controlZoneTemplate->controlZone.maxSuperiority;

    if (static_cast<uint32>(std::abs(delta)) < minSuperiority)
        return 0;

    float const slope = (static_cast<float>(minTime) - maxTime) / (maxSuperiority - minSuperiority);
    float const intercept = maxTime - slope * minSuperiority;
    float const timeNeeded = slope * std::abs(delta) + intercept;
    float percentageIncrease = 100.0f / timeNeeded;

    if (delta < 0)
        percentageIncrease *= -1;

    return percentageIncrease;
}

void ControlZone::HandleUnitEnterExit(std::vector<Player*> const& newTargetList)
{
    GuidUnorderedSet exitPlayers(std::move(_insidePlayers));

    std::vector<Player*> enteringPlayers;

    for (Player* unit : newTargetList)
    {
        if (exitPlayers.erase(unit->GetGUID()) == 0) // erase(key_type) returns number of elements erased
            enteringPlayers.push_back(unit);

        _insidePlayers.insert(unit->GetGUID());
    }

    for (Player* player : enteringPlayers)
    {
        player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldState1, 1);
        player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldstate2, static_cast<int32>(_value));
        player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldstate3, _controlZoneTemplate->controlZone.neutralPercent);
    }

    for (ObjectGuid const& exitPlayerGuid : exitPlayers)
        if (Player const* player = ObjectAccessor::GetPlayer(*_owner, exitPlayerGuid))
            player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldState1, 0);
}

float ControlZone::GetMaxHordeValue() const
{
    // ex: if neutralPercent is 40; then 0 - 30 is Horde Controlled
    return 50.0f - _controlZoneTemplate->controlZone.neutralPercent / 2.0f;
}

float ControlZone::GetMinAllianceValue() const
{
    // ex: if neutralPercent is 40; then 70 - 100 is Alliance Controlled
    return 50.0f + _controlZoneTemplate->controlZone.neutralPercent / 2.0f;
}

void ControlZone::TriggerEvent(uint32 eventId) const
{
    if (eventId <= 0)
        return;

    _owner->GetMap()->UpdateSpawnGroupConditions();
    GameEvents::Trigger(eventId, _owner, nullptr);
}

uint32 ControlZone::GetStartingValue() const
{
    return _controlZoneTemplate->controlZone.startingValue;
}

void ControlZone::Disable()
{
    for (ObjectGuid const& guid : _insidePlayers)
        if (Player* player = ObjectAccessor::GetPlayer(*_owner, guid))
            player->SendUpdateWorldState(_controlZoneTemplate->controlZone.worldState1, 0);

    _insidePlayers.clear();
}
