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

#ifndef ControlZone_h__
#define ControlZone_h__

#include "Duration.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "Timer.h"

struct GameObjectTemplate;

class Player;
class WorldObject;

class TC_GAME_API ControlZone
{
public:
    explicit ControlZone(WorldObject* owner, GameObjectTemplate const* gameobjectTemplate);

    void Update(uint32 diff);
    TeamId GetControllingTeam() const;
    GuidUnorderedSet const* GetInsidePlayers() const;
    void SetValue(float value);
    void HandleHeartbeat();
    void SearchTargets(std::vector<Player*>& targetList);
    float CalculatePointsPerSecond(std::vector<Player*> const& targetList) const;
    void HandleUnitEnterExit(std::vector<Player*> const& newTargetList);
    float GetMaxHordeValue() const;
    float GetMinAllianceValue() const;
    void TriggerEvent(uint32 eventId) const;
    uint32 GetStartingValue() const;

    void Enable() { _enabled = true; }
    void Disable();

private:
    WorldObject* _owner;
    GameObjectTemplate const* _controlZoneTemplate;

    Milliseconds _heartbeatRate;
    TimeTracker _heartbeatTracker;
    GuidUnorderedSet _insidePlayers;
    TeamId _previousTeamId;
    float _value;
    bool _contestedTriggered;
    bool _enabled;
};

#endif // ControlZone_h__
