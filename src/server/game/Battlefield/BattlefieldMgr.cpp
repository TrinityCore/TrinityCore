/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "BattlefieldWG.h"
#include "Log.h"
#include "Player.h"

BattlefieldMgr::BattlefieldMgr()
{
    _updateTimer = 0;
}

BattlefieldMgr::~BattlefieldMgr()
{
    for (auto itr = _battlefieldContainer.begin(); itr != _battlefieldContainer.end(); ++itr)
        delete itr->second;

    _battlefieldContainer.clear();
}

BattlefieldMgr* BattlefieldMgr::instance()
{
    static BattlefieldMgr instance;
    return &instance;
}

void BattlefieldMgr::Initialize()
{
    Battlefield* wintergrasp = new BattlefieldWG();
    if (!wintergrasp->SetupBattlefield())
    {
        TC_LOG_ERROR("bg.battlefield", "BattlefieldMgr::Initialize: wintergrasp initialized failed");
        delete wintergrasp;
    }
    else
    {
        _battlefieldContainer[wintergrasp->GetBattleId()] = wintergrasp;
        TC_LOG_INFO("bg.battlefield", "BattlefieldMgr: wintergrasp successfully initiated");
    }
}

void BattlefieldMgr::HandlePlayerEnterZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return;

    if (itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerEnterZone(player, zoneId);
    TC_LOG_DEBUG("battlefield", "BattlefieldMgr::HandlePlayerEnterZone: player %u entered battlefield id %u", player->GetGUID().GetCounter(), itr->second->GetBattleId());
}

void BattlefieldMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return;

    if (!itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneId);
    TC_LOG_DEBUG("battlefield", "BattlefieldMgr::HandlePlayerLeaveZone: player %u left battlefield id %u", player->GetGUID().GetCounter(), itr->second->GetBattleId());
}

Battlefield* BattlefieldMgr::GetEnabledBattlefield(uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr == _battlefieldContainer.end())
        return nullptr;

    if (!itr->second->IsEnabled())
        return nullptr;

    return itr->second;
}

Battlefield* BattlefieldMgr::GetBattlefield(uint32 battleId)
{
    for (auto itr = _battlefieldContainer.begin(); itr != _battlefieldContainer.end(); ++itr)
    {
        if (itr->second->GetBattleId() == battleId)
            return itr->second;
    }

    return nullptr;
}

ZoneScript* BattlefieldMgr::GetZoneScript(uint32 zoneId)
{
    auto itr = _battlefieldContainer.find(zoneId);
    if (itr != _battlefieldContainer.end())
        return itr->second;

    return nullptr;
}

void BattlefieldMgr::Update(uint32 diff)
{
    _updateTimer += diff;
    if (_updateTimer > BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (auto itr = _battlefieldContainer.begin(); itr != _battlefieldContainer.end(); ++itr)
        {
            if (itr->second->IsEnabled())
                itr->second->Update(_updateTimer);
        }

        _updateTimer = 0;
    }
}
