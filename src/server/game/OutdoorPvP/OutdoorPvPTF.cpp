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

#include "OutdoorPvPTF.h"
#include "OutdoorPvPMgr.h"
#include "WorldPacket.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "World.h"

OutdoorPvPTF::OutdoorPvPTF()
{
    m_TypeId = OUTDOOR_PVP_TF;
}

OPvPCapturePointTF::OPvPCapturePointTF(OutdoorPvP *pvp, OutdoorPvPTF_TowerType type)
: OPvPCapturePoint(pvp), m_TowerType(type), m_TowerState(TF_TOWERSTATE_N)
{
    SetCapturePointData(TFCapturePoints[type].entry,TFCapturePoints[type].map,TFCapturePoints[type].x,TFCapturePoints[type].y,TFCapturePoints[type].z,TFCapturePoints[type].o,TFCapturePoints[type].rot0,TFCapturePoints[type].rot1,TFCapturePoints[type].rot2,TFCapturePoints[type].rot3);
}

void OPvPCapturePointTF::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(TFTowerWorldStates[m_TowerType].n) << uint32(bool(m_TowerState & TF_TOWERSTATE_N));
    data << uint32(TFTowerWorldStates[m_TowerType].h) << uint32(bool(m_TowerState & TF_TOWERSTATE_H));
    data << uint32(TFTowerWorldStates[m_TowerType].a) << uint32(bool(m_TowerState & TF_TOWERSTATE_A));
}

void OutdoorPvPTF::FillInitialWorldStates(WorldPacket &data)
{
    data << TF_UI_TOWER_SLIDER_POS << uint32(50);
    data << TF_UI_TOWER_SLIDER_N << uint32(100);
    data << TF_UI_TOWER_SLIDER_DISPLAY << uint32(0);

    data << TF_UI_TOWER_COUNT_H << m_HordeTowersControlled;
    data << TF_UI_TOWER_COUNT_A << m_AllianceTowersControlled;
    data << TF_UI_TOWERS_CONTROLLED_DISPLAY << uint32(!m_IsLocked);

    data << TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT << first_digit;
    data << TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT << second_digit;
    data << TF_UI_LOCKED_TIME_HOURS << hours_left;

    data << TF_UI_LOCKED_DISPLAY_NEUTRAL << uint32(m_IsLocked && !m_HordeTowersControlled && !m_AllianceTowersControlled);
    data << TF_UI_LOCKED_DISPLAY_HORDE << uint32(m_IsLocked && (m_HordeTowersControlled > m_AllianceTowersControlled));
    data << TF_UI_LOCKED_DISPLAY_ALLIANCE << uint32(m_IsLocked && (m_HordeTowersControlled < m_AllianceTowersControlled));

    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        itr->second->FillInitialWorldStates(data);
    }
}

void OutdoorPvPTF::SendRemoveWorldStates(Player * plr)
{
    plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS,uint32(0));
    plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_N,uint32(0));
    plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY,uint32(0));

    plr->SendUpdateWorldState(TF_UI_TOWER_COUNT_H,uint32(0));
    plr->SendUpdateWorldState(TF_UI_TOWER_COUNT_A,uint32(0));
    plr->SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY,uint32(0));

    plr->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT,uint32(0));
    plr->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT,uint32(0));
    plr->SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS,uint32(0));

    plr->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL,uint32(0));
    plr->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE,uint32(0));
    plr->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE,uint32(0));

    for (int i = 0; i < TF_TOWER_NUM; ++i)
    {
        plr->SendUpdateWorldState(uint32(TFTowerWorldStates[i].n),uint32(0));
        plr->SendUpdateWorldState(uint32(TFTowerWorldStates[i].h),uint32(0));
        plr->SendUpdateWorldState(uint32(TFTowerWorldStates[i].a),uint32(0));
    }
}

void OPvPCapturePointTF::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].n),uint32(bool(m_TowerState & TF_TOWERSTATE_N)));
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].h),uint32(bool(m_TowerState & TF_TOWERSTATE_H)));
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].a),uint32(bool(m_TowerState & TF_TOWERSTATE_A)));
}

bool OPvPCapturePointTF::HandlePlayerEnter(Player *plr)
{
    if (OPvPCapturePoint::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
        plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_N, m_neutralValuePct);
        return true;
    }
    return false;
}

void OPvPCapturePointTF::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 0);
    OPvPCapturePoint::HandlePlayerLeave(plr);
}

bool OutdoorPvPTF::Update(uint32 diff)
{
    bool changed = OutdoorPvP::Update(diff);

    if (changed)
    {
        if (m_AllianceTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_ALLIANCE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL,uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE,uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE,uint32(1));
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(0));
        }
        else if (m_HordeTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_HORDE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL,uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE,uint32(1));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE,uint32(0));
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(0));
        }
        else
        {
            TeamCastSpell(TEAM_ALLIANCE, -TF_CAPTURE_BUFF);
            TeamCastSpell(TEAM_HORDE, -TF_CAPTURE_BUFF);
        }
        SendUpdateWorldState(TF_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
        SendUpdateWorldState(TF_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    }
    if (m_IsLocked)
    {
        // lock timer is down, release lock
        if (m_LockTimer < diff)
        {
            m_LockTimer = TF_LOCK_TIME;
            m_LockTimerUpdate = 0;
            m_IsLocked = false;
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(1));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL,uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE,uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE,uint32(0));
        }
        else
        {
            // worldstateui update timer is down, update ui with new time data
            if (m_LockTimerUpdate < diff)
            {
                m_LockTimerUpdate = TF_LOCK_TIME_UPDATE;
                uint32 minutes_left = m_LockTimer / 60000;
                hours_left = minutes_left / 60;
                minutes_left -= hours_left * 60;
                second_digit = minutes_left % 10;
                first_digit = minutes_left / 10;

                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT,first_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT,second_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS,hours_left);
            } else m_LockTimerUpdate -= diff;
            m_LockTimer -= diff;
        }
    }
    return changed;
}

void OutdoorPvPTF::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if (plr->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >= TF_TOWER_NUM)
            plr->CastSpell(plr,TF_CAPTURE_BUFF,true);
    }
    else
    {
        if (m_HordeTowersControlled >= TF_TOWER_NUM)
            plr->CastSpell(plr,TF_CAPTURE_BUFF,true);
    }
    OutdoorPvP::HandlePlayerEnterZone(plr,zone);
}

void OutdoorPvPTF::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // remove buffs
    plr->RemoveAurasDueToSpell(TF_CAPTURE_BUFF);
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}

bool OutdoorPvPTF::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    m_IsLocked = false;
    m_LockTimer = TF_LOCK_TIME;
    m_LockTimerUpdate = 0;
    hours_left = 6;
    second_digit = 0;
    first_digit = 0;

    // add the zones affected by the pvp buff
    for (int i = 0; i < OutdoorPvPTFBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPTFBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointTF(this,TF_TOWER_NW));
    AddCapturePoint(new OPvPCapturePointTF(this,TF_TOWER_N));
    AddCapturePoint(new OPvPCapturePointTF(this,TF_TOWER_NE));
    AddCapturePoint(new OPvPCapturePointTF(this,TF_TOWER_SE));
    AddCapturePoint(new OPvPCapturePointTF(this,TF_TOWER_S));

    return true;
}

bool OPvPCapturePointTF::Update(uint32 diff)
{
    // can update even in locked state if gathers the controlling faction
    bool canupdate = ((((OutdoorPvPTF*)m_PvP)->m_AllianceTowersControlled > 0) && m_activePlayers[0].size() > m_activePlayers[1].size()) ||
            ((((OutdoorPvPTF*)m_PvP)->m_HordeTowersControlled > 0) && m_activePlayers[0].size() < m_activePlayers[1].size());
    // if gathers the other faction, then only update if the pvp is unlocked
    canupdate = canupdate || !((OutdoorPvPTF*)m_PvP)->m_IsLocked;
    return canupdate && OPvPCapturePoint::Update(diff);
}

void OPvPCapturePointTF::ChangeState()
{
    // if changing from controlling alliance to horde
    if (m_OldState == OBJECTIVESTATE_ALLIANCE)
    {
        if (((OutdoorPvPTF*)m_PvP)->m_AllianceTowersControlled)
            ((OutdoorPvPTF*)m_PvP)->m_AllianceTowersControlled--;
        sWorld.SendZoneText(OutdoorPvPTFBuffZones[0],objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_TF_LOOSE_A));
    }
    // if changing from controlling horde to alliance
    else if (m_OldState == OBJECTIVESTATE_HORDE)
    {
        if (((OutdoorPvPTF*)m_PvP)->m_HordeTowersControlled)
            ((OutdoorPvPTF*)m_PvP)->m_HordeTowersControlled--;
        sWorld.SendZoneText(OutdoorPvPTFBuffZones[0],objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_TF_LOOSE_H));
    }

    uint32 artkit = 21;

    switch(m_State)
    {
    case OBJECTIVESTATE_ALLIANCE:
        m_TowerState = TF_TOWERSTATE_A;
        artkit = 2;
        if (((OutdoorPvPTF*)m_PvP)->m_AllianceTowersControlled<TF_TOWER_NUM)
            ((OutdoorPvPTF*)m_PvP)->m_AllianceTowersControlled++;
        sWorld.SendZoneText(OutdoorPvPTFBuffZones[0],objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_TF_CAPTURE_A));
        for (PlayerSet::iterator itr = m_activePlayers[0].begin(); itr != m_activePlayers[0].end(); ++itr)
            (*itr)->AreaExploredOrEventHappens(TF_ALLY_QUEST);
        break;
    case OBJECTIVESTATE_HORDE:
        m_TowerState = TF_TOWERSTATE_H;
        artkit = 1;
        if (((OutdoorPvPTF*)m_PvP)->m_HordeTowersControlled<TF_TOWER_NUM)
            ((OutdoorPvPTF*)m_PvP)->m_HordeTowersControlled++;
        sWorld.SendZoneText(OutdoorPvPTFBuffZones[0],objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_TF_CAPTURE_H));
        for (PlayerSet::iterator itr = m_activePlayers[1].begin(); itr != m_activePlayers[1].end(); ++itr)
            (*itr)->AreaExploredOrEventHappens(TF_HORDE_QUEST);
        break;
    case OBJECTIVESTATE_NEUTRAL:
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        m_TowerState = TF_TOWERSTATE_N;
        break;
    }

    GameObject* flag = HashMapHolder<GameObject>::Find(m_capturePointGUID);
    if (flag)
        flag->SetGoArtKit(artkit);

    UpdateTowerState();
}

void OPvPCapturePointTF::SendChangePhase()
{
    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 1);
    // send these updates to only the ones in this objective
    uint32 phase = (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f);
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS, phase);
    // send this too, sometimes it resets :S
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_N, m_neutralValuePct);
}

