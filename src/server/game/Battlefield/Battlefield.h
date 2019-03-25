/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_BATTLEFIELD_H_
#define TRINITY_BATTLEFIELD_H_

#include "Common.h"
#include "SharedDefines.h"
#include "Timer.h"
#include "ZoneScript.h"
#include <memory>
#include <unordered_map>

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates;
    }
}

class BattlefieldGraveyard;
class ObjectGuid;
class Player;
class Unit;
struct WorldSafeLocsEntry;

class TC_GAME_API Battlefield : public ZoneScript
{
public:
    explicit Battlefield(BattlefieldBattleId battleId, BattlefieldZoneId zoneId);
    virtual ~Battlefield() { }

    // Called on battlefield creation
    virtual bool Initialize(bool enabled);
    virtual void Update(uint32 diff);

    // Called when a player enters the battlefield zone
    virtual void HandlePlayerEnterZone(Player* player);
    // Called when a player leaves the battlefield zone
    virtual void HandlePlayerLeaveZone(Player* player);
    // Called when a player inside the battlefield zone kills a unit
    virtual void HandleKill(Player* /*killer*/, Unit* /*victim*/) { }
    // Called when a player queries a gossip from a spirit healer
    virtual void HandleAreaSpiritHealerQueryOpcode(Player* player, ObjectGuid source);
    // Called when a player moves into a resurrection queue
    virtual void HandleAddPlayerToResurrectionQueue(Player* player, ObjectGuid source);
    // Called when a player moves out of a resurrection queue
    virtual void HandleRemovePlayerFromResurrectionQueue(Player* player);

    virtual void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& /*packet*/) { }
    virtual void SendGlobalWorldStates(Player const* /*player*/) const { }

    // Can players inside the battlefield zone use ground mounts?
    virtual bool IsMountAllowed() const { return true; }
    // Can players inside the battlefield zone use flying mounts?
    virtual bool IsFlyingMountAllowed() const { return true; }
    // Is the referenced SpellArea spellId allowed for the referenced player and newArea?
    virtual bool IsSpellAreaAllowed(uint32 /*spellId*/, Player const* /*player*/, uint32 /*newArea*/) const { return false; }

    BattlefieldBattleId GetId() const { return _battleId; }
    uint32 GetZoneId() const { return _zoneId; }
    // enum PvPTeamId
    PvPTeamId GetControllingTeam() const { return _controllingTeam; }
    // enum PvPTeamId
    PvPTeamId GetAttackingTeam() const;
    // enum TeamId
    TeamId GetControllingTeamId() const;
    // enum TeamId
    TeamId GetAttackingTeamId() const;
    // Battle timer
    uint32 GetTimer() const { return _timer.GetTimer(); }
    // Closest available graveyard for Player's TeamId
    WorldSafeLocsEntry const* GetClosestGraveyard(Player* who) const;

    bool IsEnabled() const { return _enabled; }
    bool IsWarTime() const { return _active; }

private:
    typedef std::unique_ptr<BattlefieldGraveyard> BattlefieldGraveyardPointer;
    typedef std::unordered_map<uint8 /*id*/, BattlefieldGraveyard> BattlefieldGraveyardContainer;

    Battlefield(Battlefield const&) = delete;
    Battlefield& operator=(Battlefield const&) = delete;

    // constant information
    BattlefieldBattleId _battleId;
    uint32 _zoneId;

    bool _enabled;
    bool _active;
    PvPTeamId _controllingTeam;
    CountdownTimer _timer;
};

#endif
