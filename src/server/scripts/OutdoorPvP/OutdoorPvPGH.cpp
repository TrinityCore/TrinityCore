/*
* Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "OutdoorPvPGH.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "WorldPacket.h"
#include "Language.h"
#include "World.h"
#include "ScriptPCH.h"


OPvPCapturePointGH::OPvPCapturePointGH(OutdoorPvP *pvp) :
OPvPCapturePoint(pvp), 
m_capturable(true), 
m_ControllingFaction(0),
m_VentureState(VENTURE_N)
{
    SetCapturePointData(189310,571,2483.68f,-1873.6f,10.68f,-0.1047f,0.0f,0.0f,0.0f,0.0f);
}

void OPvPCapturePointGH::SpawnNPCsForTeam(uint32 team)
{
    const creature_type* creatures = NULL;
    if (team == ALLIANCE)
        creatures = AllianceControlNPCs;
    else if (team == HORDE)
        creatures = HordeControlNPCs;
    else
        return;
    for (int i = 0; i < GH_CONTROL_NPC_NUM; ++i)
        AddCreature(i,creatures[i].entry,creatures[i].teamval,creatures[i].map,creatures[i].x,creatures[i].y,creatures[i].z,creatures[i].o,1000000);
}

void OPvPCapturePointGH::DeSpawnNPCs()
{
    for (int i = 0; i < GH_CONTROL_NPC_NUM; ++i)
        DelCreature(i);
}

void OPvPCapturePointGH::FactionTakeOver(uint32 team)
{
    m_ControllingFaction = team;
    DeSpawnNPCs();
    SpawnNPCsForTeam(team);
    m_capturable = true;
}

bool OPvPCapturePointGH::HandlePlayerEnter(Player *plr)
{
    if (OPvPCapturePoint::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
        plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_N, m_neutralValuePct);
        return true;
    }
    return false;
}

void OPvPCapturePointGH::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_DISPLAY, 0);
    OPvPCapturePoint::HandlePlayerLeave(plr);
}

void OPvPCapturePointGH::FillInitialWorldStates(WorldPacket &data)
{
    data << GH_UI_TOWER_SLIDER_DISPLAY << uint32(0);
    data << GH_UI_TOWER_SLIDER_POS << uint32(50);
    data << GH_UI_TOWER_SLIDER_N << uint32(100);

    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEUTRAL ,uint32(bool(m_VentureState & VENTURE_N)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_HORDE ,uint32(bool(m_VentureState & VENTURE_H)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_ALLIANCE ,uint32(bool(m_VentureState & VENTURE_A)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEU_A ,uint32(bool(m_VentureState & VENTURE_N_A)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEU_H ,uint32(bool(m_VentureState & VENTURE_N_H)));
}

bool OPvPCapturePointGH::Update(uint32 diff)
{
    // ToDo: research if all the soldiers attack at once
    // research if they respawn after some time
    if (m_capturable)
        return OPvPCapturePoint::Update(diff);
    return false;
}

void OPvPCapturePointGH::ChangeState()
{
    switch(m_OldState)
    {
    case OBJECTIVESTATE_NEUTRAL:
        break;
    case OBJECTIVESTATE_ALLIANCE:
        sWorld->SendZoneText(GH_OUTDOORPVP_ZONE,sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_GH_LOOSE_A));
        DeSpawnNPCs();
        break;
    case OBJECTIVESTATE_HORDE:
        sWorld->SendZoneText(GH_OUTDOORPVP_ZONE,sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_GH_LOOSE_H));
        DeSpawnNPCs();
        break;
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        break;
    }

    uint32 artkit = 21;
    switch(m_State)
    {
    case OBJECTIVESTATE_NEUTRAL:
        m_VentureState = VENTURE_N;
        break;
    case OBJECTIVESTATE_ALLIANCE:
        m_VentureState = VENTURE_A;
        FactionTakeOver(ALLIANCE);
        artkit = 2;
        sWorld->SendZoneText(GH_OUTDOORPVP_ZONE,sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_GH_CAPTURE_A));
        break;
    case OBJECTIVESTATE_HORDE:
        m_VentureState = VENTURE_H;
        FactionTakeOver(HORDE);
        artkit = 1;
        sWorld->SendZoneText(GH_OUTDOORPVP_ZONE,sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_GH_CAPTURE_H));
        break;
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        m_VentureState = VENTURE_N_A;
        break;
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        m_VentureState = VENTURE_N_H;
        break;
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        m_VentureState = VENTURE_N_A;
        artkit = 2;
        break;
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        m_VentureState = VENTURE_N_H;
        artkit = 1;
        break;
    }

    GameObject* flag = HashMapHolder<GameObject>::Find(m_capturePointGUID);
    if (flag)
    {
        flag->SetGoArtKit(artkit);
    }
    // ToDo: research about the world states!
    //this->UpdateVentureWorldState();
}

void OPvPCapturePointGH::UpdateVentureWorldState()
{
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEUTRAL ,uint32(bool(m_VentureState & VENTURE_N)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_HORDE ,uint32(bool(m_VentureState & VENTURE_H)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_ALLIANCE ,uint32(bool(m_VentureState & VENTURE_A)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEU_A ,uint32(bool(m_VentureState & VENTURE_N_A)));
    m_PvP->SendUpdateWorldState(GH_MAP_VENTURE_NEU_H ,uint32(bool(m_VentureState & VENTURE_N_H)));
}

void OPvPCapturePointGH::SendChangePhase()
{
    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(GH_UI_TOWER_SLIDER_DISPLAY, 1);
    // send these updates to only the ones in this objective
    uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
    SendUpdateWorldState(GH_UI_TOWER_SLIDER_POS, phase);
    SendUpdateWorldState(GH_UI_TOWER_SLIDER_N, m_neutralValuePct);
}


OutdoorPvPGH::OutdoorPvPGH()
{
    m_TypeId = OUTDOOR_PVP_GH;
}

void OutdoorPvPGH::HandleKillImpl(Player *plr, Unit * killed)
{
    if (killed->GetTypeId() == TYPEID_PLAYER && plr->GetTeam() != killed->ToPlayer()->GetTeam())
        plr->CastSpell(plr,GH_VENTURE_KILL_CREDIT,true);
}

void OutdoorPvPGH::SendRemoveWorldStates(Player *plr)
{
    plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_DISPLAY,0);
    plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_POS,0);
    plr->SendUpdateWorldState(GH_UI_TOWER_SLIDER_N,0);
}

bool OutdoorPvPGH::Update(uint32 diff)
{
    return m_obj->Update(diff);
}

void OutdoorPvPGH::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    OutdoorPvP::HandlePlayerEnterZone(plr,zone);
}

void OutdoorPvPGH::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}

bool OutdoorPvPGH::SetupOutdoorPvP()
{
    RegisterZone(GH_OUTDOORPVP_ZONE);
    m_obj = new OPvPCapturePointGH(this);
    if (!m_obj)
        return false;
    AddCapturePoint(m_obj);
    return true;
}

void OutdoorPvPGH::FillInitialWorldStates(WorldPacket &data)
{
    m_obj->FillInitialWorldStates(data);
}

class OutdoorPvP_grizzly : public OutdoorPvPScript
{
public:

    OutdoorPvP_grizzly()
        : OutdoorPvPScript("outdoorpvp_gh")
    {
    }

    OutdoorPvP* GetOutdoorPvP() const
    {
        return new OutdoorPvPGH();
    }
};

void AddSC_outdoorpvp_gh()
{
    new OutdoorPvP_grizzly();
}