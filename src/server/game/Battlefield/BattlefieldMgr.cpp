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

#include "BattlefieldMgr.h"
#include "Battlefield.h"
#include "BattlefieldWG.h"
#include "Log.h"
#include "Player.h"
#include "World.h"
#include "ZoneScript.h"
#include <algorithm>

BattlefieldMgr::BattlefieldMgr() : _updateTimer(0)
{
}

BattlefieldMgr::~BattlefieldMgr()
{
}

BattlefieldMgr* BattlefieldMgr::instance()
{
    static BattlefieldMgr instance;
    return &instance;
}

void BattlefieldMgr::Initialize()
{
    BattlefieldWintergrasp* wintergrasp = new BattlefieldWintergrasp();
    if (!wintergrasp->Initialize(/*sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE)*/ false))
    {
        TC_LOG_ERROR("server.loading", ">> Wintergrasp initialization failed!");
        delete wintergrasp;
    }
    else
    {
        _battlefieldContainer.emplace(wintergrasp->GetZoneId(), std::move(wintergrasp));
        TC_LOG_INFO("server.loading", ">> Wintergrasp successfully initialized");
    }
}

Battlefield* BattlefieldMgr::GetBattlefield(uint32 zoneId) const
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return nullptr;

    return itr->second.get();
}

Battlefield* BattlefieldMgr::GetBattlefield(BattlefieldBattleId battleId) const
{
    auto itr = std::find_if(_battlefieldContainer.begin(), _battlefieldContainer.end(), [battleId](BattlefieldContainer::value_type const& a) -> bool
    {
        return a.second->GetId() == battleId;
    });
    return itr != _battlefieldContainer.end() ? itr->second.get() : nullptr;
}

ZoneScript* BattlefieldMgr::GetZoneScript(uint32 zoneId) const
{
    return GetBattlefield(zoneId);
}

ZoneScript* BattlefieldMgr::GetZoneScript(BattlefieldBattleId battleId) const
{
    return GetBattlefield(battleId);
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(uint32 zoneId) const
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return nullptr;

    if (itr->second->IsEnabled())
        return itr->second.get();

    return nullptr;
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(BattlefieldBattleId battleId) const
{
    auto itr = std::find_if(_battlefieldContainer.begin(), _battlefieldContainer.end(), [battleId](BattlefieldContainer::value_type const& a) -> bool
    {
        return a.second->GetId() == battleId && a.second->IsEnabled();
    });
    return itr != _battlefieldContainer.end() ? itr->second.get() : nullptr;
}

void BattlefieldMgr::HandlePlayerEnterZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return;

    itr->second->HandlePlayerEnterZone(player, zoneId);
}

void BattlefieldMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneId);
}

void BattlefieldMgr::Update(uint32 diff)
{
    _updateTimer += diff;
    if (_updateTimer <= BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL)
        return;

    std::for_each(_battlefieldContainer.begin(), _battlefieldContainer.end(), [this](BattlefieldContainer::value_type const& a)
    {
        if (a.second->IsEnabled())
            a.second->Update(_updateTimer);
    });
    _updateTimer = 0;
}
