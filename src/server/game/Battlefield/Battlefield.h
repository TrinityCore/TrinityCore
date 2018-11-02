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
#include "ZoneScript.h"

class Player;
enum BattlefieldBattleId : uint8;
enum BattlefieldZoneId : uint32;

class TC_GAME_API Battlefield : public ZoneScript
{
public:
    explicit Battlefield(BattlefieldBattleId battleId, BattlefieldZoneId zoneId);
    virtual ~Battlefield() { }

    BattlefieldBattleId GetId() const { return _battleId; }
    uint32 GetZoneId() const { return _zoneId; }
    bool IsEnabled() const { return _enabled; }

    virtual bool Initialize(bool status);
    virtual void Update(uint32 diff) { }
    virtual void HandlePlayerEnterZone(Player* player, uint32 zoneId) { }
    virtual void HandlePlayerLeaveZone(Player* player, uint32 zoneId) { }

private:
    Battlefield(Battlefield const&) = delete;

    BattlefieldBattleId _battleId;
    uint32 _zoneId;
    bool _enabled;
};

#endif
