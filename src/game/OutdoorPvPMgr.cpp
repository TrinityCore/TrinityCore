/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "OutdoorPvPMgr.h"
#include "OutdoorPvPHP.h"
#include "OutdoorPvPNA.h"
#include "OutdoorPvPTF.h"
#include "OutdoorPvPZM.h"
#include "OutdoorPvPSI.h"
#include "OutdoorPvPEP.h"
#include "Wintergrasp.h"
#include "Player.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1( OutdoorPvPMgr );

OutdoorPvPMgr::OutdoorPvPMgr()
{
    m_UpdateTimer = OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL;
    //sLog.outDebug("Instantiating OutdoorPvPMgr");
}

OutdoorPvPMgr::~OutdoorPvPMgr()
{
    //sLog.outDebug("Deleting OutdoorPvPMgr");
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        (*itr)->DeleteSpawns();
    }
}

void OutdoorPvPMgr::InitOutdoorPvP()
{
    // create new opvp
    OutdoorPvP * pOP = new OutdoorPvPHP;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : HP init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : HP successfully initiated.");
    }


    pOP = new OutdoorPvPNA;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : NA init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : NA successfully initiated.");
    }


    pOP = new OutdoorPvPTF;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : TF init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : TF successfully initiated.");
    }

    pOP = new OutdoorPvPZM;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : ZM init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : ZM successfully initiated.");
    }

    pOP = new OutdoorPvPSI;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : SI init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : SI successfully initiated.");
    }

    pOP = new OutdoorPvPEP;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : EP init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : EP successfully initiated.");
    }

    pOP = new OPvPWintergrasp;
    // respawn, init variables
    if(!pOP->SetupOutdoorPvP())
    {
        sLog.outDebug("OutdoorPvP : Wintergrasp init failed.");
        delete pOP;
    }
    else
    {
        m_OutdoorPvPSet.push_back(pOP);
        sLog.outDebug("OutdoorPvP : Wintergrasp successfully initiated.");
    }
}

void OutdoorPvPMgr::AddZone(uint32 zoneid, OutdoorPvP *handle)
{
    m_OutdoorPvPMap[zoneid] = handle;
}


void OutdoorPvPMgr::HandlePlayerEnterZone(Player *plr, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if(itr == m_OutdoorPvPMap.end())
        return;

    if(itr->second->HasPlayer(plr))
        return;

    itr->second->HandlePlayerEnterZone(plr, zoneid);
    sLog.outDebug("Player %u entered outdoorpvp id %u", plr->GetGUIDLow(), itr->second->GetTypeId());
}

void OutdoorPvPMgr::HandlePlayerLeaveZone(Player *plr, uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if(itr == m_OutdoorPvPMap.end())
        return;

    // teleport: remove once in removefromworld, once in updatezone
    if(!itr->second->HasPlayer(plr))
        return;

    itr->second->HandlePlayerLeaveZone(plr, zoneid);
    sLog.outDebug("Player %u left outdoorpvp id %u",plr->GetGUIDLow(), itr->second->GetTypeId());
}

OutdoorPvP * OutdoorPvPMgr::GetOutdoorPvPToZoneId(uint32 zoneid)
{
    OutdoorPvPMap::iterator itr = m_OutdoorPvPMap.find(zoneid);
    if(itr == m_OutdoorPvPMap.end())
    {
        // no handle for this zone, return
        return NULL;
    }
    return itr->second;
}

void OutdoorPvPMgr::Update(uint32 diff)
{
    if(m_UpdateTimer < diff)
    {
        for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
        {
            (*itr)->Update(diff);
        }
        m_UpdateTimer = OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL;
    } else m_UpdateTimer -= diff;
}

bool OutdoorPvPMgr::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if((*itr)->HandleCustomSpell(plr,spellId,go))
            return true;
    }
    return false;
}

void OutdoorPvPMgr::OnGameObjectCreate(GameObject *go, bool add)
{
    if(go->GetGoType() != GAMEOBJECT_TYPE_CAPTURE_POINT)
        return;

    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
        for(OutdoorPvP::OPvPCapturePointMap::iterator itr2 = (*itr)->m_capturePoints.begin(); itr2 != (*itr)->m_capturePoints.end(); ++itr2)
            if((*itr2)->m_CapturePointGUID == go->GetDBTableGUIDLow())
                (*itr2)->m_capturePoint = add ? go : NULL;
}

bool OutdoorPvPMgr::HandleOpenGo(Player *plr, uint64 guid)
{
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if((*itr)->HandleOpenGo(plr,guid))
            return true;
    }
    return false;
}

void OutdoorPvPMgr::HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid)
{
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if((*itr)->HandleGossipOption(plr,guid,gossipid))
            return;
    }
}

bool OutdoorPvPMgr::CanTalkTo(Player * plr, Creature * c, GossipOption & gso)
{
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if((*itr)->CanTalkTo(plr,c,gso))
            return true;
    }
    return false;
}

void OutdoorPvPMgr::HandleDropFlag(Player *plr, uint32 spellId)
{
    for(OutdoorPvPSet::iterator itr = m_OutdoorPvPSet.begin(); itr != m_OutdoorPvPSet.end(); ++itr)
    {
        if((*itr)->HandleDropFlag(plr,spellId))
            return;
    }
}
