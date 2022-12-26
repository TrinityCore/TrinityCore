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
#include "Containers.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"

namespace
{
    constexpr std::array<uint32, BATTLEFIELD_MAX> BattlefieldIdToMapId = { 0, 571, 732 };
    constexpr std::array<uint32, BATTLEFIELD_MAX> BattlefieldIdToZoneId = { 0, 4197, 5095 }; // imitate World_PVP_Area.db2
    std::array<uint32, BATTLEFIELD_MAX> BattlefieldIdToScriptId = { 0, 0, 0 };
}

BattlefieldMgr::BattlefieldMgr()
{
    _updateTimer = 0;
}

BattlefieldMgr::~BattlefieldMgr() = default;

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

            BattlefieldIdToScriptId[typeId] = sObjectMgr->GetScriptId(fields[1].GetString());

            ++count;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u battlefields in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlefieldMgr::CreateBattlefieldsForMap(Map* map)
{
    for (uint32 i = 0; i < BATTLEFIELD_MAX; ++i)
    {
        if (!BattlefieldIdToScriptId[i])
            continue;

        if (BattlefieldIdToMapId[i] != map->GetId())
            continue;

        Battlefield* bf = sScriptMgr->CreateBattlefield(BattlefieldIdToScriptId[i], map);
        if (!bf)
            continue;

        if (!bf->SetupBattlefield())
        {
            TC_LOG_INFO("bg.battlefield", "Setting up battlefield with TypeId %u on map %u instance id %u failed.", i, map->GetId(), map->GetInstanceId());
            delete bf;
        }

        _battlefieldsByMap[map].emplace_back(bf);
        TC_LOG_INFO("bg.battlefield", "Setting up battlefield with TypeId %u on map %u instance id %u succeeded.", i, map->GetId(), map->GetInstanceId());
    }
}

void BattlefieldMgr::DestroyBattlefieldsForMap(Map const* map)
{
    _battlefieldsByMap.erase(map);
}

void BattlefieldMgr::AddZone(uint32 zoneId, Battlefield* bf)
{
    _battlefieldsByZone[{ bf->GetMap(), zoneId }] = bf;
}

void BattlefieldMgr::HandlePlayerEnterZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldsByZone.find({ player->GetMap(), zoneId });
    if (itr == _battlefieldsByZone.end())
        return;

    Battlefield* bf = itr->second;
    if (!bf->IsEnabled() || bf->HasPlayer(player))
        return;

    bf->HandlePlayerEnterZone(player, zoneId);
    TC_LOG_DEBUG("bg.battlefield", "Player %u entered battlefield id %u", player->GetGUID().GetCounter(), bf->GetTypeId());
}

void BattlefieldMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneId)
{
    auto itr = _battlefieldsByZone.find({ player->GetMap(), zoneId });
    if (itr == _battlefieldsByZone.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if (!itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneId);
    TC_LOG_DEBUG("bg.battlefield", "Player %u left battlefield id %u", player->GetGUID().GetCounter(), itr->second->GetTypeId());
}

bool BattlefieldMgr::IsWorldPvpArea(uint32 zoneId) const
{
    return std::find(BattlefieldIdToZoneId.begin(), BattlefieldIdToZoneId.end(), zoneId) != BattlefieldIdToZoneId.end();
}

Battlefield* BattlefieldMgr::GetBattlefieldToZoneId(Map const* map, uint32 zoneId)
{
    auto itr = _battlefieldsByZone.find({ map, zoneId });
    if (itr == _battlefieldsByZone.end())
    {
        // no handle for this zone, return
        return nullptr;
    }

    if (!itr->second->IsEnabled())
        return nullptr;

    return itr->second;
}

Battlefield* BattlefieldMgr::GetBattlefieldByBattleId(Map const* map, uint32 battleId)
{
    if (BattlefieldsMapByMap::mapped_type const* battlefields = Trinity::Containers::MapGetValuePtr(_battlefieldsByMap, map))
        for (std::unique_ptr<Battlefield> const& battlefield : *battlefields)
            if (battlefield->GetBattleId() == battleId)
                return battlefield.get();

    return nullptr;
}

void BattlefieldMgr::Update(uint32 diff)
{
    _updateTimer += diff;
    if (_updateTimer > BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (auto const& [map, battlefields] : _battlefieldsByMap)
            for (std::unique_ptr<Battlefield> const& bfItr : battlefields)
                if (bfItr->IsEnabled())
                    bfItr->Update(_updateTimer);

        _updateTimer = 0;
    }
}
