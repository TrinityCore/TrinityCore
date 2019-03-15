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

#ifndef TRINITY_BATTLEFIELD_MGR_H_
#define TRINITY_BATTLEFIELD_MGR_H_

#include "Common.h"
#include "SharedDefines.h"
#include <functional>
#include <memory>
#include <unordered_map>

class Battlefield;
class Player;
class ZoneScript;

static uint32 constexpr BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL = 1000;

class TC_GAME_API BattlefieldMgr
{
public:
    static BattlefieldMgr* instance();

    // create battlefields
    void Initialize();
    void Update(uint32 diff);
    void ForEach(std::function<void(Battlefield*)> const& action);

    // called when a player enters a battlefield area
    void HandlePlayerEnterZone(Player* player, uint32 zoneId);
    // called when player leaves a battlefield area
    void HandlePlayerLeaveZone(Player* player, uint32 zoneId);

    Battlefield* GetBattlefield(uint32 zoneId) const;
    Battlefield* GetBattlefield(BattlefieldBattleId battleId) const;
    ZoneScript* GetZoneScript(uint32 zoneId) const;
    ZoneScript* GetZoneScript(BattlefieldBattleId battleId) const;
    Battlefield* GetEnabledBattlefield(uint32 zoneId) const;
    Battlefield* GetEnabledBattlefield(BattlefieldBattleId battleId) const;

private:
    typedef std::unique_ptr<Battlefield> BattlefieldPointer;
    typedef std::unordered_map<uint32 /*zoneId*/, BattlefieldPointer> BattlefieldContainer;

    explicit BattlefieldMgr();
    ~BattlefieldMgr();

    // contains all initialized battlefields
    BattlefieldContainer _battlefieldContainer;
    // update interval
    uint32 _updateTimer;
};

#define sBattlefieldMgr BattlefieldMgr::instance()

#endif
