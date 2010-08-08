/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "OutdoorPvPHP.h"
#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "Player.h"
#include "WorldPacket.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "ScriptPCH.h"

const uint32 HP_LANG_LOOSE_A[HP_TOWER_NUM] = {LANG_OPVP_HP_LOOSE_BROKENHILL_A,LANG_OPVP_HP_LOOSE_OVERLOOK_A,LANG_OPVP_HP_LOOSE_STADIUM_A};

const uint32 HP_LANG_LOOSE_H[HP_TOWER_NUM] = {LANG_OPVP_HP_LOOSE_BROKENHILL_H,LANG_OPVP_HP_LOOSE_OVERLOOK_H,LANG_OPVP_HP_LOOSE_STADIUM_H};

const uint32 HP_LANG_CAPTURE_A[HP_TOWER_NUM] = {LANG_OPVP_HP_CAPTURE_BROKENHILL_A,LANG_OPVP_HP_CAPTURE_OVERLOOK_A,LANG_OPVP_HP_CAPTURE_STADIUM_A};

const uint32 HP_LANG_CAPTURE_H[HP_TOWER_NUM] = {LANG_OPVP_HP_CAPTURE_BROKENHILL_H,LANG_OPVP_HP_CAPTURE_OVERLOOK_H,LANG_OPVP_HP_CAPTURE_STADIUM_H};

OPvPCapturePointHP::OPvPCapturePointHP(OutdoorPvP *pvp,OutdoorPvPHPTowerType type)
: OPvPCapturePoint(pvp), m_TowerType(type)
{
    SetCapturePointData(HPCapturePoints[type].entry,
        HPCapturePoints[type].map,
        HPCapturePoints[type].x,
        HPCapturePoints[type].y,
        HPCapturePoints[type].z,
        HPCapturePoints[type].o,
        HPCapturePoints[type].rot0,
        HPCapturePoints[type].rot1,
        HPCapturePoints[type].rot2,
        HPCapturePoints[type].rot3);
    AddObject(type,
        HPTowerFlags[type].entry,
        HPTowerFlags[type].map,
        HPTowerFlags[type].x,
        HPTowerFlags[type].y,
        HPTowerFlags[type].z,
        HPTowerFlags[type].o,
        HPTowerFlags[type].rot0,
        HPTowerFlags[type].rot1,
        HPTowerFlags[type].rot2,
        HPTowerFlags[type].rot3);
}

OutdoorPvPHP::OutdoorPvPHP()
{
    m_TypeId = OUTDOOR_PVP_HP;
}

bool OutdoorPvPHP::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    // add the zones affected by the pvp buff
    for (int i = 0; i < OutdoorPvPHPBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPHPBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointHP(this,HP_TOWER_BROKEN_HILL));

    AddCapturePoint(new OPvPCapturePointHP(this,HP_TOWER_OVERLOOK));

    AddCapturePoint(new OPvPCapturePointHP(this,HP_TOWER_STADIUM));

    return true;
}

void OutdoorPvPHP::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    // add buffs
    if (plr->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >=3)
            plr->CastSpell(plr,AllianceBuff,true);
    }
    else
    {
        if (m_HordeTowersControlled >=3)
            plr->CastSpell(plr,HordeBuff,true);
    }
    OutdoorPvP::HandlePlayerEnterZone(plr,zone);
}

void OutdoorPvPHP::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // remove buffs
    if (plr->GetTeam() == ALLIANCE)
    {
        plr->RemoveAurasDueToSpell(AllianceBuff);
    }
    else
    {
        plr->RemoveAurasDueToSpell(HordeBuff);
    }
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}

bool OutdoorPvPHP::Update(uint32 diff)
{
    bool changed = OutdoorPvP::Update(diff);
    if (changed)
    {
        if (m_AllianceTowersControlled == 3)
            TeamApplyBuff(TEAM_ALLIANCE, AllianceBuff, HordeBuff);
        else if (m_HordeTowersControlled == 3)
            TeamApplyBuff(TEAM_HORDE, HordeBuff, AllianceBuff);
        else
        {
            TeamCastSpell(TEAM_ALLIANCE, -AllianceBuff);
            TeamCastSpell(TEAM_HORDE, -HordeBuff);
        }
        SendUpdateWorldState(HP_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
        SendUpdateWorldState(HP_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    }
    return changed;
}

void OutdoorPvPHP::SendRemoveWorldStates(Player *plr)
{
    plr->SendUpdateWorldState(HP_UI_TOWER_DISPLAY_A,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_DISPLAY_H,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_COUNT_H,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_COUNT_A,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_N,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_POS,0);
    plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_DISPLAY,0);
    for (int i = 0; i < HP_TOWER_NUM; ++i)
    {
        plr->SendUpdateWorldState(HP_MAP_N[i],0);
        plr->SendUpdateWorldState(HP_MAP_A[i],0);
        plr->SendUpdateWorldState(HP_MAP_H[i],0);
    }
}

void OutdoorPvPHP::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(HP_UI_TOWER_DISPLAY_A) << uint32(1);
    data << uint32(HP_UI_TOWER_DISPLAY_H) << uint32(1);
    data << uint32(HP_UI_TOWER_COUNT_A) << uint32(m_AllianceTowersControlled);
    data << uint32(HP_UI_TOWER_COUNT_H) << uint32(m_HordeTowersControlled);
    data << uint32(HP_UI_TOWER_SLIDER_DISPLAY) << uint32(0);
    data << uint32(HP_UI_TOWER_SLIDER_POS) << uint32(50);
    data << uint32(HP_UI_TOWER_SLIDER_N) << uint32(100);
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        itr->second->FillInitialWorldStates(data);
    }
}

void OPvPCapturePointHP::ChangeState()
{
    uint32 field = 0;
    switch(m_OldState)
    {
    case OBJECTIVESTATE_NEUTRAL:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE:
        field = HP_MAP_A[m_TowerType];
        if (((OutdoorPvPHP*)m_PvP)->m_AllianceTowersControlled)
            ((OutdoorPvPHP*)m_PvP)->m_AllianceTowersControlled--;
        sWorld.SendZoneText(OutdoorPvPHPBuffZones[0],sObjectMgr.GetTrinityStringForDBCLocale(HP_LANG_LOOSE_A[m_TowerType]));
        break;
    case OBJECTIVESTATE_HORDE:
        field = HP_MAP_H[m_TowerType];
        if (((OutdoorPvPHP*)m_PvP)->m_HordeTowersControlled)
            ((OutdoorPvPHP*)m_PvP)->m_HordeTowersControlled--;
        sWorld.SendZoneText(OutdoorPvPHPBuffZones[0],sObjectMgr.GetTrinityStringForDBCLocale(HP_LANG_LOOSE_H[m_TowerType]));
        break;
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        field = HP_MAP_A[m_TowerType];
        break;
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        field = HP_MAP_H[m_TowerType];
        break;
    }

    // send world state update
    if (field)
    {
        m_PvP->SendUpdateWorldState(field, 0);
        field = 0;
    }
    uint32 artkit = 21;
    uint32 artkit2 = HP_TowerArtKit_N[m_TowerType];
    switch(m_State)
    {
    case OBJECTIVESTATE_NEUTRAL:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE:
        field = HP_MAP_A[m_TowerType];
        artkit = 2;
        artkit2 = HP_TowerArtKit_A[m_TowerType];
        if (((OutdoorPvPHP*)m_PvP)->m_AllianceTowersControlled<3)
            ((OutdoorPvPHP*)m_PvP)->m_AllianceTowersControlled++;
        sWorld.SendZoneText(OutdoorPvPHPBuffZones[0],sObjectMgr.GetTrinityStringForDBCLocale(HP_LANG_CAPTURE_A[m_TowerType]));
        break;
    case OBJECTIVESTATE_HORDE:
        field = HP_MAP_H[m_TowerType];
        artkit = 1;
        artkit2 = HP_TowerArtKit_H[m_TowerType];
        if (((OutdoorPvPHP*)m_PvP)->m_HordeTowersControlled<3)
            ((OutdoorPvPHP*)m_PvP)->m_HordeTowersControlled++;
        sWorld.SendZoneText(OutdoorPvPHPBuffZones[0],sObjectMgr.GetTrinityStringForDBCLocale(HP_LANG_CAPTURE_H[m_TowerType]));
        break;
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        field = HP_MAP_A[m_TowerType];
        artkit = 2;
        artkit2 = HP_TowerArtKit_A[m_TowerType];
        break;
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        field = HP_MAP_H[m_TowerType];
        artkit = 1;
        artkit2 = HP_TowerArtKit_H[m_TowerType];
        break;
    }

    GameObject* flag = HashMapHolder<GameObject>::Find(m_capturePointGUID);
    GameObject* flag2 = HashMapHolder<GameObject>::Find(m_Objects[m_TowerType]);
    if (flag)
    {
        flag->SetGoArtKit(artkit);
    }
    if (flag2)
    {
        flag2->SetGoArtKit(artkit2);
    }

    // send world state update
    if (field)
        m_PvP->SendUpdateWorldState(field, 1);

    // complete quest objective
    if (m_State == OBJECTIVESTATE_ALLIANCE || m_State == OBJECTIVESTATE_HORDE)
        SendObjectiveComplete(HP_CREDITMARKER[m_TowerType], 0);
}

void OPvPCapturePointHP::SendChangePhase()
{
    SendUpdateWorldState(HP_UI_TOWER_SLIDER_N, m_neutralValuePct);
    // send these updates to only the ones in this objective
    uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
    SendUpdateWorldState(HP_UI_TOWER_SLIDER_POS, phase);
    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(HP_UI_TOWER_SLIDER_DISPLAY, 1);
}

void OPvPCapturePointHP::FillInitialWorldStates(WorldPacket &data)
{
    switch(m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            data << uint32(HP_MAP_N[m_TowerType]) << uint32(0);
            data << uint32(HP_MAP_A[m_TowerType]) << uint32(1);
            data << uint32(HP_MAP_H[m_TowerType]) << uint32(0);
            break;
        case OBJECTIVESTATE_HORDE:
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            data << uint32(HP_MAP_N[m_TowerType]) << uint32(0);
            data << uint32(HP_MAP_A[m_TowerType]) << uint32(0);
            data << uint32(HP_MAP_H[m_TowerType]) << uint32(1);
            break;
        case OBJECTIVESTATE_NEUTRAL:
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        default:
            data << uint32(HP_MAP_N[m_TowerType]) << uint32(1);
            data << uint32(HP_MAP_A[m_TowerType]) << uint32(0);
            data << uint32(HP_MAP_H[m_TowerType]) << uint32(0);
            break;
    }
}

bool OPvPCapturePointHP::HandlePlayerEnter(Player *plr)
{
    if (OPvPCapturePoint::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
        plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_N, m_neutralValuePct);
        return true;
    }
    return false;
}

void OPvPCapturePointHP::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(HP_UI_TOWER_SLIDER_DISPLAY, 0);
    OPvPCapturePoint::HandlePlayerLeave(plr);
}

void OutdoorPvPHP::HandleKillImpl(Player *plr, Unit * killed)
{
    if (killed->GetTypeId() != TYPEID_PLAYER)
        return;

    if (plr->GetTeam() == ALLIANCE && killed->ToPlayer()->GetTeam() != ALLIANCE)
        plr->CastSpell(plr,AlliancePlayerKillReward,true);
    else if (plr->GetTeam() == HORDE && killed->ToPlayer()->GetTeam() != HORDE)
        plr->CastSpell(plr,HordePlayerKillReward,true);
}

class OutdoorPvP_hellfire_peninsula : public OutdoorPvPScript
{
    public:

        OutdoorPvP_hellfire_peninsula()
            : OutdoorPvPScript("outdoorpvp_hp")
        {
        }

        OutdoorPvP* GetOutdoorPvP() const
        {
            return new OutdoorPvPHP();
        }
};

void AddSC_outdoorpvp_hp()
{
    new OutdoorPvP_hellfire_peninsula();
}
