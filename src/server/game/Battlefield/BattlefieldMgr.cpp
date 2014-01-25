/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "Player.h"

BattlefieldMgr::BattlefieldMgr()
{
    _updateTimer = 0;
}

BattlefieldMgr::~BattlefieldMgr()
{
    for (BattlefieldSet::iterator itr = _battlefieldSet.begin(); itr != _battlefieldSet.end(); ++itr)
        delete *itr;

    _battlefieldMap.clear();
}

void BattlefieldMgr::InitBattlefield()
{
    Battlefield* wg = new BattlefieldWG();
    // respawn, init variables
    if (!wg->SetupBattlefield())
    {
        TC_LOG_INFO("bg.battlefield", "Battlefield: Wintergrasp init failed.");
        delete wg;
    }
    else
    {
        _battlefieldSet.push_back(wg);
        TC_LOG_INFO("bg.battlefield", "Battlefield: Wintergrasp successfully initiated.");
    }

    /*
    For Cataclysm: Tol Barad
    Battlefield* tb = new BattlefieldTB;
    // respawn, init variables
    if (!tb->SetupBattlefield())
    {
        TC_LOG_DEBUG("bg.battlefield", "Battlefield: Tol Barad init failed.");
        delete tb;
    }
    else
    {
        _battlefieldSet.push_back(tb);
        TC_LOG_DEBUG("bg.battlefield", "Battlefield: Tol Barad successfully initiated.");
    }
    */
}

void BattlefieldMgr::AddZone(uint32 zoneId, Battlefield* bf)
{
    _battlefieldMap[zoneId] = bf;
}

void BattlefieldMgr::HandlePlayerEnterZone(Player* player, uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr == _battlefieldMap.end())
        return;

    Battlefield* bf = itr->second;
    if (!bf->IsEnabled() || bf->HasPlayer(player))
        return;

    bf->HandlePlayerEnterZone(player, zoneId);
    TC_LOG_DEBUG("bg.battlefield", "Player %u entered battlefield id %u", player->GetGUIDLow(), bf->GetTypeId());
}

void BattlefieldMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr == _battlefieldMap.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if (!itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneId);
    TC_LOG_DEBUG("bg.battlefield", "Player %u left battlefield id %u", player->GetGUIDLow(), itr->second->GetTypeId());
}

Battlefield* BattlefieldMgr::GetBattlefieldToZoneId(uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr == _battlefieldMap.end())
    {
        // no handle for this zone, return
        return NULL;
    }

    if (!itr->second->IsEnabled())
        return NULL;

    return itr->second;
}

Battlefield* BattlefieldMgr::GetBattlefieldByBattleId(uint32 battleId)
{
    for (BattlefieldSet::iterator itr = _battlefieldSet.begin(); itr != _battlefieldSet.end(); ++itr)
    {
        if ((*itr)->GetBattleId() == battleId)
            return *itr;
    }
    return NULL;
}

Battlefield* BattlefieldMgr::GetBattlefieldByGUID(uint64 guid)
{
    for (BattlefieldSet::iterator itr = _battlefieldSet.begin(); itr != _battlefieldSet.end(); ++itr)
        if ((*itr)->GetGUID() == guid)
            return *itr;

    return NULL;
}

ZoneScript* BattlefieldMgr::GetZoneScript(uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr != _battlefieldMap.end())
        return itr->second;

    return NULL;
}

void BattlefieldMgr::Update(uint32 diff)
{
    _updateTimer += diff;
    if (_updateTimer > BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (BattlefieldSet::iterator itr = _battlefieldSet.begin(); itr != _battlefieldSet.end(); ++itr)
            if ((*itr)->IsEnabled())
                (*itr)->Update(_updateTimer);
        _updateTimer = 0;
    }
}
