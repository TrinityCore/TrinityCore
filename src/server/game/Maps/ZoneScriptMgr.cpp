/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.TrinityCore.org/>
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

#include "ZoneScriptMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(ZoneScriptMgr);

void RegisterZoneScripts();

ZoneScriptMgr::ZoneScriptMgr()
{
    m_UpdateTimer = 0;
}

ZoneScriptMgr::~ZoneScriptMgr()
{
    for (const auto& itr : m_ZoneScriptsSet)
        delete itr;
    for (const auto& itr : m_ZoneScripts_Scripts)
        delete itr;
}

void ZoneScriptMgr::InitZoneScripts()
{
    RegisterZoneScripts();
}

void ZoneScriptMgr::InitMapZoneScripts(uint32 mapId, Map* pMap)
{
    ZoneScript* pScript = nullptr;
    uint32 counter = 0;
    for (const auto& itr : m_ZoneScripts_Scripts)
    {
        if (itr->GetMapId() != mapId)
            continue;

        pScript = itr->GetZoneScript();
        if (!pScript)
        {
            sLog.outError("Could not initialize ZoneScript object. Got nullptr pointer from script.");
            continue;
        }
        pScript->SetMap(pMap);
        if (!pScript->SetupZoneScript())
        {
            sLog.outError("Could not initialize ZoneScript object. SetupZoneScript failed.");
            delete pScript;
            continue;
        }
        m_ZoneScriptsSet.insert(pScript);
        ++counter;
    }

    sLog.outString("ZoneScriptMgr : %u scripts on the map %u.", counter, mapId);
}

void ZoneScriptMgr::AddZone(uint32 zoneid, ZoneScript *handle)
{
    m_ZoneScriptsMap[zoneid] = handle;
}

void ZoneScriptMgr::HandlePlayerEnterZone(Player* plr, uint32 zoneid)
{
    ZoneScriptsMap::iterator itr = m_ZoneScriptsMap.find(zoneid);
    if (itr == m_ZoneScriptsMap.end())
        return;

    if (itr->second->HasPlayer(plr))
        return;

    itr->second->OnPlayerEnter(plr);
    //DEBUG_LOG("Player %u entered ZoneScript", plr->GetGUIDLow());
}

void ZoneScriptMgr::HandlePlayerLeaveZone(Player* plr, uint32 zoneid)
{
    ZoneScriptsMap::iterator itr = m_ZoneScriptsMap.find(zoneid);
    if (itr == m_ZoneScriptsMap.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if (!itr->second->HasPlayer(plr))
        return;

    itr->second->OnPlayerLeave(plr);
    //DEBUG_LOG("Player %u left ZoneScript", plr->GetGUIDLow());
}

ZoneScript * ZoneScriptMgr::GetZoneScriptToZoneId(uint32 zoneid)
{
    ZoneScriptsMap::iterator itr = m_ZoneScriptsMap.find(zoneid);
    if (itr == m_ZoneScriptsMap.end())
    {
        // no handle for this zone, return
        //DETAIL_LOG("Pas de script pour la zone %u", zoneid);
        return nullptr;
    }
    return itr->second;
}

void ZoneScriptMgr::Update(uint32 diff)
{
    m_UpdateTimer += diff;
    if (m_UpdateTimer > OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (const auto itr : m_ZoneScriptsSet)
            itr->Update(m_UpdateTimer);
        m_UpdateTimer = 0;
    }
}

bool ZoneScriptMgr::HandleCustomSpell(Player* plr, uint32 spellId, GameObject* go)
{
    for (const auto itr : m_ZoneScriptsSet)
    {
        if (itr->HandleCustomSpell(plr, spellId, go))
            return true;
    }
    return false;
}

ZoneScript * ZoneScriptMgr::GetZoneScript(uint32 zoneId)
{
    ZoneScriptsMap::iterator itr = m_ZoneScriptsMap.find(zoneId);
    if (itr != m_ZoneScriptsMap.end())
        return itr->second;
    else
        return nullptr;
}

bool ZoneScriptMgr::HandleOpenGo(Player* plr, uint64 guid)
{
    for (const auto itr : m_ZoneScriptsSet)
    {
        if (itr->HandleOpenGo(plr, guid))
            return true;
    }
    return false;
}

void ZoneScriptMgr::HandleGossipOption(Player* plr, uint64 guid, uint32 gossipid)
{
    for (const auto itr : m_ZoneScriptsSet)
    {
        if (itr->HandleGossipOption(plr, guid, gossipid))
            return;
    }
}

void ZoneScriptMgr::HandleDropFlag(Player* plr, uint32 spellId)
{
    for (const auto itr : m_ZoneScriptsSet)
    {
        if (itr->HandleDropFlag(plr, spellId))
            return;
    }
}


void ZoneScriptMgr::OnMapCrashed(Map* map)
{
    ZoneScriptsSet::iterator itr = m_ZoneScriptsSet.begin();
    for (; itr != m_ZoneScriptsSet.end(); ++itr)
        if ((*itr)->GetMap() == map)
        {
            m_ZoneScriptsSet.erase(itr);
            itr = m_ZoneScriptsSet.begin();
        }
    ZoneScriptsMap::iterator itr2 = m_ZoneScriptsMap.begin();
    for (; itr2 != m_ZoneScriptsMap.end(); ++itr2)
        if (itr2->second->GetMap() == map)
        {
            m_ZoneScriptsMap.erase(itr2);
            itr2 = m_ZoneScriptsMap.begin();
        }
}

