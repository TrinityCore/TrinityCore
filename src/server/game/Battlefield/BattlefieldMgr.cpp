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
#include "Player.h"
#include "SharedDefines.h"
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
    return nullptr;
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(BattlefieldBattleId battleId) const
{
    return nullptr;
}

void BattlefieldMgr::HandlePlayerEnterZone(Player* player, uint32 zoneId)
{
}

void BattlefieldMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneId)
{
}

void BattlefieldMgr::Update(uint32 diff)
{
}
