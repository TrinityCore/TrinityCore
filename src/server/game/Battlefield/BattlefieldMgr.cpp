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
#include "ZoneScript.h"

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

Battlefield* BattlefieldMgr::GetBattlefield(BattlefieldId battleId) const
{
    return nullptr;
}

ZoneScript* BattlefieldMgr::GetZoneScript(uint32 zoneId) const
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return nullptr;

    return itr->second.get();
}

ZoneScript* BattlefieldMgr::GetZoneScript(BattlefieldId battleId) const
{
    return nullptr;
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(uint32 zoneId) const
{
    return nullptr;
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(BattlefieldId battleId) const
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
