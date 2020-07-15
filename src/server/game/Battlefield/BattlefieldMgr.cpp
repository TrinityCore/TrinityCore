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

#include "BattlefieldMgr.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"

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

BattlefieldMgr* BattlefieldMgr::instance()
{
    static BattlefieldMgr instance;
    return &instance;
}

void BattlefieldMgr::InitBattlefield()
{
    uint32 oldMSTime = getMSTime();

    uint32 count = 0;

    if (QueryResult result = WorldDatabase.Query("SELECT TypeId, ScriptName FROM battlefield_template"))
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 typeId = fields[0].GetUInt8();

            if (typeId >= BATTLEFIELD_MAX)
            {
                TC_LOG_ERROR("sql.sql", "BattlefieldMgr::InitBattlefield: Invalid TypeId value %u in battlefield_template, skipped.", typeId);
                continue;
            }

            uint32 scriptId = sObjectMgr->GetScriptId(fields[1].GetString());

            Battlefield* bf = sScriptMgr->CreateBattlefield(scriptId);
            if (!bf)
                continue;

            if (!bf->SetupBattlefield())
            {
                TC_LOG_INFO("bg.battlefield", "Setting up battlefield with TypeId %u failed.", typeId);
                delete bf;
            }
            else
            {
                _battlefieldSet.push_back(bf);
                TC_LOG_INFO("bg.battlefield", "Setting up battlefield with TypeId %u succeeded.", typeId);
            }

            ++count;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u battlefields in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
    TC_LOG_DEBUG("bg.battlefield", "Player %s entered battlefield id %u", player->GetGUID().ToString().c_str(), bf->GetTypeId());
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
    TC_LOG_DEBUG("bg.battlefield", "Player %s left battlefield id %u", player->GetGUID().ToString().c_str(), itr->second->GetTypeId());
}

Battlefield* BattlefieldMgr::GetBattlefieldToZoneId(uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr == _battlefieldMap.end())
    {
        // no handle for this zone, return
        return nullptr;
    }

    if (!itr->second->IsEnabled())
        return nullptr;

    return itr->second;
}

Battlefield* BattlefieldMgr::GetBattlefieldByBattleId(uint32 battleId)
{
    for (BattlefieldSet::iterator itr = _battlefieldSet.begin(); itr != _battlefieldSet.end(); ++itr)
    {
        if ((*itr)->GetBattleId() == battleId)
            return *itr;
    }
    return nullptr;
}

ZoneScript* BattlefieldMgr::GetZoneScript(uint32 zoneId)
{
    BattlefieldMap::iterator itr = _battlefieldMap.find(zoneId);
    if (itr != _battlefieldMap.end())
        return itr->second;

    return nullptr;
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
