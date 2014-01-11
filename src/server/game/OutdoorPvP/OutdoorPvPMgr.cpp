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

#include "OutdoorPvPMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "DisableMgr.h"
#include "ScriptMgr.h"

OutdoorPvPMgr::OutdoorPvPMgr()
{
    m_UpdateTimer = 0;
    //TC_LOG_DEBUG("outdoorpvp", "Instantiating OutdoorPvPMgr");
}

void OutdoorPvPMgr::Die()
{
    //TC_LOG_DEBUG("outdoorpvp", "Deleting OutdoorPvPMgr");
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
        delete *itr;

    for (OutdoorPvPDataMap::iterator itr = m_OutdoorPvPDatas.begin(); itr != m_OutdoorPvPDatas.end(); ++itr)
        delete itr->second;
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

        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_OUTDOORPVP, typeId, NULL))
            continue;

        if (typeId >= MAX_OUTDOORPVP_TYPES)
        {
            TC_LOG_ERROR("sql.sql", "Invalid OutdoorPvPTypes value %u in outdoorpvp_template; skipped.", typeId);
            continue;
        }

        OutdoorPvPData* data = new OutdoorPvPData();
        OutdoorPvPTypes realTypeId = OutdoorPvPTypes(typeId);
        data->TypeId = realTypeId;
        data->ScriptId = sObjectMgr->GetScriptId(fields[1].GetCString());
        m_OutdoorPvPDatas[realTypeId] = data;

        ++count;
    }
    while (result->NextRow());

    OutdoorPvP* pvp;
    for (uint8 i = 1; i < MAX_OUTDOORPVP_TYPES; ++i)
    {
        OutdoorPvPDataMap::iterator iter = m_OutdoorPvPDatas.find(OutdoorPvPTypes(i));
        if (iter == m_OutdoorPvPDatas.end())
        {
            TC_LOG_ERROR("sql.sql", "Could not initialize OutdoorPvP object for type ID %u; no entry in database.", uint32(i));
            continue;
        }

        pvp = sScriptMgr->CreateOutdoorPvP(iter->second);
        if (!pvp)
        {
            TC_LOG_ERROR("outdoorpvp", "Could not initialize OutdoorPvP object for type ID %u; got NULL pointer from script.", uint32(i));
            continue;
        }

        if (!pvp->SetupOutdoorPvP())
        {
            TC_LOG_ERROR("outdoorpvp", "Could not initialize OutdoorPvP object for type ID %u; SetupOutdoorPvP failed.", uint32(i));
            delete pvp;
            continue;
        }

        m_OutdoorPvPSet.push_back(pvp);
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u outdoor PvP definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void OutdoorPvPMgr::AddZone(uint32 zoneid, OutdoorPvP* handle)
{
    m_OutdoorPvPMap[zoneid] = handle;
}

void OutdoorPvPMgr::HandlePlayerEnterZone(Player* player, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if (itr == m_OutdoorPvPMap.end())
        return;

    if (itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerEnterZone(player, zoneid);
    TC_LOG_DEBUG("outdoorpvp", "Player %u entered outdoorpvp id %u", player->GetGUIDLow(), itr->second->GetTypeId());
}

void OutdoorPvPMgr::HandlePlayerLeaveZone(Player* player, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if (itr == m_OutdoorPvPMap.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if (!itr->second->HasPlayer(player))
        return;

    itr->second->HandlePlayerLeaveZone(player, zoneid);
    TC_LOG_DEBUG("outdoorpvp", "Player %u left outdoorpvp id %u", player->GetGUIDLow(), itr->second->GetTypeId());
}

OutdoorPvP* OutdoorPvPMgr::GetOutdoorPvPToZoneId(uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if (itr == m_OutdoorPvPMap.end())
    {
        // no handle for this zone, return
        return NULL;
    }
    return itr->second;
}

void OutdoorPvPMgr::Update(uint32 diff)
{
    m_UpdateTimer += diff;
    if (m_UpdateTimer > OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
            (*itr)->Update(m_UpdateTimer);
        m_UpdateTimer = 0;
    }
}

bool OutdoorPvPMgr::HandleCustomSpell(Player* player, uint32 spellId, GameObject* go)
{
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if ((*itr)->HandleCustomSpell(player, spellId, go))
            return true;
    }
    return false;
}

ZoneScript* OutdoorPvPMgr::GetZoneScript(uint32 zoneId)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneId);
    if (itr != m_OutdoorPvPMap.end())
        return itr->second;
    else
        return NULL;
}

bool OutdoorPvPMgr::HandleOpenGo(Player* player, uint64 guid)
{
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if ((*itr)->HandleOpenGo(player, guid))
            return true;
    }
    return false;
}

void OutdoorPvPMgr::HandleGossipOption(Player* player, uint64 guid, uint32 gossipid)
{
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if ((*itr)->HandleGossipOption(player, guid, gossipid))
            return;
    }
}

bool OutdoorPvPMgr::CanTalkTo(Player* player, Creature* creature, GossipMenuItems const& gso)
{
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if ((*itr)->CanTalkTo(player, creature, gso))
            return true;
    }
    return false;
}

void OutdoorPvPMgr::HandleDropFlag(Player* player, uint32 spellId)
{
    for (OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if ((*itr)->HandleDropFlag(player, spellId))
            return;
    }
}

void OutdoorPvPMgr::HandlePlayerResurrects(Player* player, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if (itr == m_OutdoorPvPMap.end())
        return;

    if (itr->second->HasPlayer(player))
        itr->second->HandlePlayerResurrects(player, zoneid);
}
