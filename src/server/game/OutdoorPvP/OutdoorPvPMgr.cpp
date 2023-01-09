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

#include "OutdoorPvPMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"

OutdoorPvPMgr::OutdoorPvPMgr()
{
    m_UpdateTimer = 0;
}

OutdoorPvPMgr::~OutdoorPvPMgr() = default;

void OutdoorPvPMgr::Die()
{
    m_OutdoorPvPByMap.clear();

    m_OutdoorPvPDatas.fill(0);

    m_OutdoorPvPMap.clear();
}

OutdoorPvPMgr* OutdoorPvPMgr::instance()
{
    static OutdoorPvPMgr instance;
    return &instance;
}

void OutdoorPvPMgr::InitOutdoorPvP()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0       1
    QueryResult result = WorldDatabase.Query("SELECT TypeId, ScriptName FROM outdoorpvp_template");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 outdoor PvP definitions. DB table `outdoorpvp_template` is empty.");
        return;
    }

    uint32 count = 0;
    uint32 typeId = 0;

    do
    {
        Field* fields = result->Fetch();

        typeId = fields[0].GetUInt8();

        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_OUTDOORPVP, typeId, nullptr))
            continue;

        if (typeId >= MAX_OUTDOORPVP_TYPES)
        {
            TC_LOG_ERROR("sql.sql", "Invalid OutdoorPvPTypes value %u in outdoorpvp_template; skipped.", typeId);
            continue;
        }

        m_OutdoorPvPDatas[typeId] = sObjectMgr->GetScriptId(fields[1].GetString());

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u outdoor PvP definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void OutdoorPvPMgr::CreateOutdoorPvPForMap(Map* map)
{
    for (uint8 i = 1; i < MAX_OUTDOORPVP_TYPES; ++i)
    {
        if (map->GetId() != m_OutdoorMapIds[i])
            continue;

        if (!m_OutdoorPvPDatas[i])
        {
            TC_LOG_ERROR("sql.sql", "Could not initialize OutdoorPvP object for type ID %u; no entry in database.", uint32(i));
            continue;
        }

        OutdoorPvP* pvp = sScriptMgr->CreateOutdoorPvP(m_OutdoorPvPDatas[i], map);
        if (!pvp)
        {
            TC_LOG_ERROR("outdoorpvp", "Could not initialize OutdoorPvP object for type ID %u; got nullptr pointer from script.", uint32(i));
            continue;
        }

        if (!pvp->SetupOutdoorPvP())
        {
            TC_LOG_ERROR("outdoorpvp", "Could not initialize OutdoorPvP object for type ID %u; SetupOutdoorPvP failed.", uint32(i));
            delete pvp;
            continue;
        }

        m_OutdoorPvPByMap[map].emplace_back(pvp);
    }
}

void OutdoorPvPMgr::DestroyOutdoorPvPForMap(Map* map)
{
    Trinity::Containers::EraseIf(m_OutdoorPvPMap, [map](OutdoorPvPMap::value_type const& pair)
    {
        return pair.first.first == map;
    });
    m_OutdoorPvPByMap.erase(map);
}

void OutdoorPvPMgr::AddZone(uint32 zoneid, OutdoorPvP* handle)
{
    m_OutdoorPvPMap[{ handle->GetMap(), zoneid }] = handle;
}

void OutdoorPvPMgr::HandlePlayerEnterZone(Player* player, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find({ player->GetMap(), zoneid });
    if (itr == m_OutdoorPvPMap.end())
        return;

    if (itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerEnterZone(player, zoneid);
    TC_LOG_DEBUG("outdoorpvp", "Player %u entered outdoorpvp id %u", player->GetGUID().GetCounter(), itr->second->GetTypeId());
}

void OutdoorPvPMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find({ player->GetMap(), zoneid });
    if (itr == m_OutdoorPvPMap.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if (!itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneid);
    TC_LOG_DEBUG("outdoorpvp", "Player %u left outdoorpvp id %u", player->GetGUID().GetCounter(), itr->second->GetTypeId());
}

OutdoorPvP* OutdoorPvPMgr::GetOutdoorPvPToZoneId(Map* map, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find({ map, zoneid });
    if (itr == m_OutdoorPvPMap.end())
    {
        // no handle for this zone, return
        return nullptr;
    }
    return itr->second;
}

void OutdoorPvPMgr::Update(uint32 diff)
{
    m_UpdateTimer += diff;
    if (m_UpdateTimer > OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (auto mapItr = m_OutdoorPvPByMap.begin(); mapItr != m_OutdoorPvPByMap.end(); ++mapItr)
            for (auto itr = mapItr->second.begin(); itr != mapItr->second.end(); ++itr)
                (*itr)->Update(m_UpdateTimer);
        m_UpdateTimer = 0;
    }
}

bool OutdoorPvPMgr::HandleCustomSpell(Player* player, uint32 spellId, GameObject* go)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            return pvp->HandleCustomSpell(player, spellId, go);

    return false;
}

bool OutdoorPvPMgr::HandleOpenGo(Player* player, GameObject* go)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            return pvp->HandleOpenGo(player, go);

    return false;
}

void OutdoorPvPMgr::HandleGossipOption(Player* player, Creature* creature, uint32 gossipid)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            pvp->HandleGossipOption(player, creature, gossipid);
}

bool OutdoorPvPMgr::CanTalkTo(Player* player, Creature* creature, GossipMenuItems const& gso)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            return pvp->CanTalkTo(player, creature, gso);

    return false;
}

void OutdoorPvPMgr::HandleDropFlag(Player* player, uint32 spellId)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            pvp->HandleDropFlag(player, spellId);
}

void OutdoorPvPMgr::HandlePlayerResurrects(Player* player, uint32 zoneid)
{
    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HasPlayer(player))
            pvp->HandlePlayerResurrects(player, zoneid);
}

std::string OutdoorPvPMgr::GetDefenseMessage(uint32 zoneId, uint32 id, LocaleConstant locale) const
{
    if (BroadcastText const* bct = sObjectMgr->GetBroadcastText(id))
        return bct->GetText(locale);

    TC_LOG_ERROR("outdoorpvp", "Can not find DefenseMessage (Zone: %u, Id: %u). BroadcastText (Id: %u) does not exist.", zoneId, id, id);
    return "";
}
