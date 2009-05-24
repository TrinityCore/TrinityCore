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

#include "OutdoorPvPEP.h"
#include "WorldPacket.h"
#include "Player.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "OutdoorPvPMgr.h"
#include "Creature.h"
#include "Language.h"
#include "World.h"
#include "GossipDef.h"

OutdoorPvPObjectiveEP_EWT::OutdoorPvPObjectiveEP_EWT(OutdoorPvP *pvp)
: OutdoorPvPObjective(pvp), m_TowerState(EP_TS_N), m_UnitsSummonedSide(0)
{
    AddCapturePoint(EPCapturePoints[EP_EWT].entry,EPCapturePoints[EP_EWT].map,EPCapturePoints[EP_EWT].x,EPCapturePoints[EP_EWT].y,EPCapturePoints[EP_EWT].z,EPCapturePoints[EP_EWT].o,EPCapturePoints[EP_EWT].rot0,EPCapturePoints[EP_EWT].rot1,EPCapturePoints[EP_EWT].rot2,EPCapturePoints[EP_EWT].rot3);
    AddObject(EP_EWT_FLAGS,EPTowerFlags[EP_EWT].entry,EPTowerFlags[EP_EWT].map,EPTowerFlags[EP_EWT].x,EPTowerFlags[EP_EWT].y,EPTowerFlags[EP_EWT].z,EPTowerFlags[EP_EWT].o,EPTowerFlags[EP_EWT].rot0,EPTowerFlags[EP_EWT].rot1,EPTowerFlags[EP_EWT].rot2,EPTowerFlags[EP_EWT].rot3);
}

bool OutdoorPvPObjectiveEP_EWT::Update(uint32 diff)
{
    if(OutdoorPvPObjective::Update(diff))
    {
        if(m_OldState != m_State || fabs(m_ShiftPhase) == m_ShiftMaxPhase)  // state won't change, only phase when maxed out!
        {
            // if changing from controlling alliance to horde or vice versa
            if( m_OldState == OBJECTIVESTATE_ALLIANCE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_EWT_A));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_EWT] = 0;
            }
            else if ( m_OldState == OBJECTIVESTATE_HORDE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_EWT_H));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_EWT] = 0;
            }

            uint32 artkit = 21;

            switch(m_State)
            {
            case OBJECTIVESTATE_ALLIANCE:
                if(m_ShiftPhase == m_ShiftMaxPhase)
                    m_TowerState = EP_TS_A;
                else
                    m_TowerState = EP_TS_A_P;
                artkit = 2;
                SummonSupportUnitAtNorthpassTower(ALLIANCE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_EWT] = ALLIANCE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_EWT_A));
                break;
            case OBJECTIVESTATE_HORDE:
                if(m_ShiftPhase == -m_ShiftMaxPhase)
                    m_TowerState = EP_TS_H;
                else
                    m_TowerState = EP_TS_H_P;
                artkit = 1;
                SummonSupportUnitAtNorthpassTower(HORDE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_EWT] = HORDE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_EWT_H));
                break;
            case OBJECTIVESTATE_NEUTRAL:
                m_TowerState = EP_TS_N;
                break;
            case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
                m_TowerState = EP_TS_N_A;
                break;
            case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
                m_TowerState = EP_TS_N_H;
                break;
            }

            GameObject* flag = HashMapHolder<GameObject>::Find(m_CapturePoint);
            GameObject* flag2 = HashMapHolder<GameObject>::Find(m_Objects[EP_EWT_FLAGS]);
            if(flag)
            {
                flag->SetGoArtKit(artkit);
                flag->SendUpdateObjectToAllExcept(NULL);
            }
            if(flag2)
            {
                flag2->SetGoArtKit(artkit);
                flag2->SendUpdateObjectToAllExcept(NULL);
            }


            UpdateTowerState();

            // complete quest objective
            if(m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
                SendObjectiveComplete(EP_EWT_CM, 0);
        }

        if(m_ShiftPhase != m_OldPhase)
        {
            // send this too, sometimes the slider disappears, dunno why :(
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
            // send these updates to only the ones in this objective
            uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
            // send this too, sometimes it resets :S
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        }
        return m_OldState != m_State;
    }
    return false;
}

void OutdoorPvPObjectiveEP_EWT::FillInitialWorldStates(WorldPacket &data)
{
    data << EP_EWT_A << uint32(bool(m_TowerState & EP_TS_A));
    data << EP_EWT_H << uint32(bool(m_TowerState & EP_TS_H));
    data << EP_EWT_A_P << uint32(bool(m_TowerState & EP_TS_A_P));
    data << EP_EWT_H_P << uint32(bool(m_TowerState & EP_TS_H_P));
    data << EP_EWT_N_A << uint32(bool(m_TowerState & EP_TS_N_A));
    data << EP_EWT_N_H << uint32(bool(m_TowerState & EP_TS_N_H));
    data << EP_EWT_N << uint32(bool(m_TowerState & EP_TS_N));
}

void OutdoorPvPObjectiveEP_EWT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_EWT_A , bool(m_TowerState & EP_TS_A));
    m_PvP->SendUpdateWorldState(EP_EWT_H , bool(m_TowerState & EP_TS_H));
    m_PvP->SendUpdateWorldState(EP_EWT_A_P , bool(m_TowerState & EP_TS_A_P));
    m_PvP->SendUpdateWorldState(EP_EWT_H_P , bool(m_TowerState & EP_TS_H_P));
    m_PvP->SendUpdateWorldState(EP_EWT_N_A , bool(m_TowerState & EP_TS_N_A));
    m_PvP->SendUpdateWorldState(EP_EWT_N_H , bool(m_TowerState & EP_TS_N_H));
    m_PvP->SendUpdateWorldState(EP_EWT_N , bool(m_TowerState & EP_TS_N));
}

bool OutdoorPvPObjectiveEP_EWT::HandlePlayerEnter(Player *plr)
{
    if(OutdoorPvPObjective::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_EWT::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 0);
    OutdoorPvPObjective::HandlePlayerLeave(plr);
}

bool OutdoorPvPObjectiveEP_EWT::HandleCapturePointEvent(Player *plr, uint32 eventId)
{
    if(eventId == EPTowerPlayerEnterEvents[EP_EWT])
    {
        this->HandlePlayerEnter(plr);
        return true;
    }
    else if (eventId == EPTowerPlayerLeaveEvents[EP_EWT])
    {
        this->HandlePlayerLeave(plr);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_EWT::SummonSupportUnitAtNorthpassTower(uint32 team)
{
    if(m_UnitsSummonedSide != team)
    {
        m_UnitsSummonedSide = team;
        const creature_type * ct = NULL;
        if(team == ALLIANCE)
            ct=EP_EWT_Summons_A;
        else
            ct=EP_EWT_Summons_H;

        for(int i = 0; i < EP_EWT_NUM_CREATURES; ++i)
        {
            DelCreature(i);
            AddCreature(i,ct[i].entry,ct[i].teamval,ct[i].map,ct[i].x,ct[i].y,ct[i].z,ct[i].o,1000000);
        }
    }
}

// NPT
OutdoorPvPObjectiveEP_NPT::OutdoorPvPObjectiveEP_NPT(OutdoorPvP *pvp)
: OutdoorPvPObjective(pvp), m_TowerState(EP_TS_N), m_SummonedGOSide(0)
{
    AddCapturePoint(EPCapturePoints[EP_NPT].entry,EPCapturePoints[EP_NPT].map,EPCapturePoints[EP_NPT].x,EPCapturePoints[EP_NPT].y,EPCapturePoints[EP_NPT].z,EPCapturePoints[EP_NPT].o,EPCapturePoints[EP_NPT].rot0,EPCapturePoints[EP_NPT].rot1,EPCapturePoints[EP_NPT].rot2,EPCapturePoints[EP_NPT].rot3);
    AddObject(EP_NPT_FLAGS,EPTowerFlags[EP_NPT].entry,EPTowerFlags[EP_NPT].map,EPTowerFlags[EP_NPT].x,EPTowerFlags[EP_NPT].y,EPTowerFlags[EP_NPT].z,EPTowerFlags[EP_NPT].o,EPTowerFlags[EP_NPT].rot0,EPTowerFlags[EP_NPT].rot1,EPTowerFlags[EP_NPT].rot2,EPTowerFlags[EP_NPT].rot3);
}

bool OutdoorPvPObjectiveEP_NPT::Update(uint32 diff)
{
    if(OutdoorPvPObjective::Update(diff))
    {
        if(m_OldState != m_State || fabs(m_ShiftPhase) == m_ShiftMaxPhase)  // state won't change, only phase when maxed out!
        {
            // if changing from controlling alliance to horde or vice versa
            if( m_OldState == OBJECTIVESTATE_ALLIANCE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_NPT_A));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_NPT] = 0;
            }
            else if ( m_OldState == OBJECTIVESTATE_HORDE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_NPT_H));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_NPT] = 0;
            }

            uint32 artkit = 21;

            switch(m_State)
            {
            case OBJECTIVESTATE_ALLIANCE:
                if(m_ShiftPhase == m_ShiftMaxPhase)
                    m_TowerState = EP_TS_A;
                else
                    m_TowerState = EP_TS_A_P;
                artkit = 2;
                SummonGO(ALLIANCE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_NPT] = ALLIANCE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_NPT_A));
                break;
            case OBJECTIVESTATE_HORDE:
                if(m_ShiftPhase == -m_ShiftMaxPhase)
                    m_TowerState = EP_TS_H;
                else
                    m_TowerState = EP_TS_H_P;
                artkit = 1;
                SummonGO(HORDE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_NPT] = HORDE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_NPT_H));
                break;
            case OBJECTIVESTATE_NEUTRAL:
                m_TowerState = EP_TS_N;
                m_SummonedGOSide = 0;
                DelObject(EP_NPT_BUFF);
                break;
            case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
                m_TowerState = EP_TS_N_A;
                break;
            case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
                m_TowerState = EP_TS_N_H;
                break;
            }

            GameObject* flag = HashMapHolder<GameObject>::Find(m_CapturePoint);
            GameObject* flag2 = HashMapHolder<GameObject>::Find(m_Objects[EP_NPT_FLAGS]);
            if(flag)
            {
                flag->SetGoArtKit(artkit);
                flag->SendUpdateObjectToAllExcept(NULL);
            }
            if(flag2)
            {
                flag2->SetGoArtKit(artkit);
                flag2->SendUpdateObjectToAllExcept(NULL);
            }

            UpdateTowerState();

            // complete quest objective
            if(m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
                SendObjectiveComplete(EP_NPT_CM, 0);
        }

        if(m_ShiftPhase != m_OldPhase)
        {
            // send this too, sometimes the slider disappears, dunno why :(
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
            // send these updates to only the ones in this objective
            uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
            // send this too, sometimes it resets :S
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        }
        return m_OldState != m_State;
    }
    return false;
}

void OutdoorPvPObjectiveEP_NPT::FillInitialWorldStates(WorldPacket &data)
{
    data << EP_NPT_A << uint32(bool(m_TowerState & EP_TS_A));
    data << EP_NPT_H << uint32(bool(m_TowerState & EP_TS_H));
    data << EP_NPT_A_P << uint32(bool(m_TowerState & EP_TS_A_P));
    data << EP_NPT_H_P << uint32(bool(m_TowerState & EP_TS_H_P));
    data << EP_NPT_N_A << uint32(bool(m_TowerState & EP_TS_N_A));
    data << EP_NPT_N_H << uint32(bool(m_TowerState & EP_TS_N_H));
    data << EP_NPT_N << uint32(bool(m_TowerState & EP_TS_N));
}

void OutdoorPvPObjectiveEP_NPT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_NPT_A , bool(m_TowerState & EP_TS_A));
    m_PvP->SendUpdateWorldState(EP_NPT_H , bool(m_TowerState & EP_TS_H));
    m_PvP->SendUpdateWorldState(EP_NPT_A_P , bool(m_TowerState & EP_TS_A_P));
    m_PvP->SendUpdateWorldState(EP_NPT_H_P , bool(m_TowerState & EP_TS_H_P));
    m_PvP->SendUpdateWorldState(EP_NPT_N_A , bool(m_TowerState & EP_TS_N_A));
    m_PvP->SendUpdateWorldState(EP_NPT_N_H , bool(m_TowerState & EP_TS_N_H));
    m_PvP->SendUpdateWorldState(EP_NPT_N , bool(m_TowerState & EP_TS_N));
}

bool OutdoorPvPObjectiveEP_NPT::HandlePlayerEnter(Player *plr)
{
    if(OutdoorPvPObjective::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_NPT::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 0);
    OutdoorPvPObjective::HandlePlayerLeave(plr);
}

bool OutdoorPvPObjectiveEP_NPT::HandleCapturePointEvent(Player *plr, uint32 eventId)
{
    if(eventId == EPTowerPlayerEnterEvents[EP_NPT])
    {
        this->HandlePlayerEnter(plr);
        return true;
    }
    else if (eventId == EPTowerPlayerLeaveEvents[EP_NPT])
    {
        this->HandlePlayerLeave(plr);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_NPT::SummonGO(uint32 team)
{
    if(m_SummonedGOSide != team)
    {
        m_SummonedGOSide = team;
        DelObject(EP_NPT_BUFF);
        AddObject(EP_NPT_BUFF,EP_NPT_LordaeronShrine.entry,EP_NPT_LordaeronShrine.map,EP_NPT_LordaeronShrine.x,EP_NPT_LordaeronShrine.y,EP_NPT_LordaeronShrine.z,EP_NPT_LordaeronShrine.o,EP_NPT_LordaeronShrine.rot0,EP_NPT_LordaeronShrine.rot1,EP_NPT_LordaeronShrine.rot2,EP_NPT_LordaeronShrine.rot3);
        GameObject * go = HashMapHolder<GameObject>::Find(m_Objects[EP_NPT_BUFF]);
        if(go)
            go->SetUInt32Value(GAMEOBJECT_FACTION,(team == ALLIANCE ? 84 : 83));
    }
}

// CGT
OutdoorPvPObjectiveEP_CGT::OutdoorPvPObjectiveEP_CGT(OutdoorPvP *pvp)
: OutdoorPvPObjective(pvp), m_TowerState(EP_TS_N), m_GraveyardSide(0)
{
    AddCapturePoint(EPCapturePoints[EP_CGT].entry,EPCapturePoints[EP_CGT].map,EPCapturePoints[EP_CGT].x,EPCapturePoints[EP_CGT].y,EPCapturePoints[EP_CGT].z,EPCapturePoints[EP_CGT].o,EPCapturePoints[EP_CGT].rot0,EPCapturePoints[EP_CGT].rot1,EPCapturePoints[EP_CGT].rot2,EPCapturePoints[EP_CGT].rot3);
    AddObject(EP_CGT_FLAGS,EPTowerFlags[EP_CGT].entry,EPTowerFlags[EP_CGT].map,EPTowerFlags[EP_CGT].x,EPTowerFlags[EP_CGT].y,EPTowerFlags[EP_CGT].z,EPTowerFlags[EP_CGT].o,EPTowerFlags[EP_CGT].rot0,EPTowerFlags[EP_CGT].rot1,EPTowerFlags[EP_CGT].rot2,EPTowerFlags[EP_CGT].rot3);
}

bool OutdoorPvPObjectiveEP_CGT::Update(uint32 diff)
{
    if(OutdoorPvPObjective::Update(diff))
    {
        if(m_OldState != m_State || fabs(m_ShiftPhase) == m_ShiftMaxPhase)  // state won't change, only phase when maxed out!
        {
            // if changing from controlling alliance to horde or vice versa
            if( m_OldState == OBJECTIVESTATE_ALLIANCE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_CGT_A));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_CGT] = 0;
            }
            else if ( m_OldState == OBJECTIVESTATE_HORDE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_CGT_H));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_CGT] = 0;
            }

            uint32 artkit = 21;

            switch(m_State)
            {
            case OBJECTIVESTATE_ALLIANCE:
                if(m_ShiftPhase == m_ShiftMaxPhase)
                    m_TowerState = EP_TS_A;
                else
                    m_TowerState = EP_TS_A_P;
                artkit = 2;
                LinkGraveYard(ALLIANCE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_CGT] = ALLIANCE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_CGT_A));
                break;
            case OBJECTIVESTATE_HORDE:
                if(m_ShiftPhase == -m_ShiftMaxPhase)
                    m_TowerState = EP_TS_H;
                else
                    m_TowerState = EP_TS_H_P;
                artkit = 1;
                LinkGraveYard(HORDE);
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_CGT] = HORDE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_CGT_H));
                break;
            case OBJECTIVESTATE_NEUTRAL:
                m_TowerState = EP_TS_N;
                break;
            case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
                m_TowerState = EP_TS_N_A;
                break;
            case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
                m_TowerState = EP_TS_N_H;
                break;
            }

            GameObject* flag = HashMapHolder<GameObject>::Find(m_CapturePoint);
            GameObject* flag2 = HashMapHolder<GameObject>::Find(m_Objects[EP_CGT_FLAGS]);
            if(flag)
            {
                flag->SetGoArtKit(artkit);
                flag->SendUpdateObjectToAllExcept(NULL);
            }
            if(flag2)
            {
                flag2->SetGoArtKit(artkit);
                flag2->SendUpdateObjectToAllExcept(NULL);
            }

            UpdateTowerState();

            // complete quest objective
            if(m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
                SendObjectiveComplete(EP_CGT_CM, 0);
        }

        if(m_ShiftPhase != m_OldPhase)
        {
            // send this too, sometimes the slider disappears, dunno why :(
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
            // send these updates to only the ones in this objective
            uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
            // send this too, sometimes it resets :S
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        }
        return m_OldState != m_State;
    }
    return false;
}

void OutdoorPvPObjectiveEP_CGT::FillInitialWorldStates(WorldPacket &data)
{
    data << EP_CGT_A << uint32(bool(m_TowerState & EP_TS_A));
    data << EP_CGT_H << uint32(bool(m_TowerState & EP_TS_H));
    data << EP_CGT_A_P << uint32(bool(m_TowerState & EP_TS_A_P));
    data << EP_CGT_H_P << uint32(bool(m_TowerState & EP_TS_H_P));
    data << EP_CGT_N_A << uint32(bool(m_TowerState & EP_TS_N_A));
    data << EP_CGT_N_H << uint32(bool(m_TowerState & EP_TS_N_H));
    data << EP_CGT_N << uint32(bool(m_TowerState & EP_TS_N));
}

void OutdoorPvPObjectiveEP_CGT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_CGT_A , bool(m_TowerState & EP_TS_A));
    m_PvP->SendUpdateWorldState(EP_CGT_H , bool(m_TowerState & EP_TS_H));
    m_PvP->SendUpdateWorldState(EP_CGT_A_P , bool(m_TowerState & EP_TS_A_P));
    m_PvP->SendUpdateWorldState(EP_CGT_H_P , bool(m_TowerState & EP_TS_H_P));
    m_PvP->SendUpdateWorldState(EP_CGT_N_A , bool(m_TowerState & EP_TS_N_A));
    m_PvP->SendUpdateWorldState(EP_CGT_N_H , bool(m_TowerState & EP_TS_N_H));
    m_PvP->SendUpdateWorldState(EP_CGT_N , bool(m_TowerState & EP_TS_N));
}

bool OutdoorPvPObjectiveEP_CGT::HandlePlayerEnter(Player *plr)
{
    if(OutdoorPvPObjective::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_CGT::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 0);
    OutdoorPvPObjective::HandlePlayerLeave(plr);
}

bool OutdoorPvPObjectiveEP_CGT::HandleCapturePointEvent(Player *plr, uint32 eventId)
{
    if(eventId == EPTowerPlayerEnterEvents[EP_CGT])
    {
        this->HandlePlayerEnter(plr);
        return true;
    }
    else if (eventId == EPTowerPlayerLeaveEvents[EP_CGT])
    {
        this->HandlePlayerLeave(plr);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_CGT::LinkGraveYard(uint32 team)
{
    if(m_GraveyardSide != team)
    {
        m_GraveyardSide = team;
        objmgr.RemoveGraveYardLink(EP_GraveYardId,EP_GraveYardZone,team,false);
        objmgr.AddGraveYardLink(EP_GraveYardId,EP_GraveYardZone,team,false);
    }
}

// PWT
OutdoorPvPObjectiveEP_PWT::OutdoorPvPObjectiveEP_PWT(OutdoorPvP *pvp)
: OutdoorPvPObjective(pvp), m_TowerState(EP_TS_N), m_FlightMasterSpawned(0)
{
    AddCapturePoint(EPCapturePoints[EP_PWT].entry,EPCapturePoints[EP_PWT].map,EPCapturePoints[EP_PWT].x,EPCapturePoints[EP_PWT].y,EPCapturePoints[EP_PWT].z,EPCapturePoints[EP_PWT].o,EPCapturePoints[EP_PWT].rot0,EPCapturePoints[EP_PWT].rot1,EPCapturePoints[EP_PWT].rot2,EPCapturePoints[EP_PWT].rot3);
    AddObject(EP_PWT_FLAGS,EPTowerFlags[EP_PWT].entry,EPTowerFlags[EP_PWT].map,EPTowerFlags[EP_PWT].x,EPTowerFlags[EP_PWT].y,EPTowerFlags[EP_PWT].z,EPTowerFlags[EP_PWT].o,EPTowerFlags[EP_PWT].rot0,EPTowerFlags[EP_PWT].rot1,EPTowerFlags[EP_PWT].rot2,EPTowerFlags[EP_PWT].rot3);
}

bool OutdoorPvPObjectiveEP_PWT::Update(uint32 diff)
{
    if(OutdoorPvPObjective::Update(diff))
    {
        if(m_OldState != m_State || fabs(m_ShiftPhase) == m_ShiftMaxPhase)  // state won't change, only phase when maxed out!
        {
            // if changing from controlling alliance to horde or vice versa
            if( m_OldState == OBJECTIVESTATE_ALLIANCE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_PWT_A));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_PWT] = 0;
            }
            else if ( m_OldState == OBJECTIVESTATE_HORDE && m_OldState != m_State )
            {
                sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_LOOSE_PWT_H));
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_PWT] = 0;
            }

            uint32 artkit = 21;

            switch(m_State)
            {
            case OBJECTIVESTATE_ALLIANCE:
                if(m_ShiftPhase == m_ShiftMaxPhase)
                    m_TowerState = EP_TS_A;
                else
                    m_TowerState = EP_TS_A_P;
                SummonFlightMaster(ALLIANCE);
                artkit = 2;
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_PWT] = ALLIANCE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_PWT_A));
                break;
            case OBJECTIVESTATE_HORDE:
                if(m_ShiftPhase == -m_ShiftMaxPhase)
                    m_TowerState = EP_TS_H;
                else
                    m_TowerState = EP_TS_H_P;
                SummonFlightMaster(HORDE);
                artkit = 1;
                ((OutdoorPvPEP*)m_PvP)->EP_Controls[EP_PWT] = HORDE;
                if(m_OldState != m_State) sWorld.SendZoneText(EP_GraveYardZone,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_CAPTURE_PWT_H));
                break;
            case OBJECTIVESTATE_NEUTRAL:
                m_TowerState = EP_TS_N;
                DelCreature(EP_PWT_FLIGHTMASTER);
                m_FlightMasterSpawned = 0;
                break;
            case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
                m_TowerState = EP_TS_N_A;
                break;
            case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
                m_TowerState = EP_TS_N_H;
                break;
            }

            GameObject* flag = HashMapHolder<GameObject>::Find(m_CapturePoint);
            GameObject* flag2 = HashMapHolder<GameObject>::Find(m_Objects[EP_PWT_FLAGS]);
            if(flag)
            {
                flag->SetGoArtKit(artkit);
                flag->SendUpdateObjectToAllExcept(NULL);
            }
            if(flag2)
            {
                flag2->SetGoArtKit(artkit);
                flag2->SendUpdateObjectToAllExcept(NULL);
            }

            UpdateTowerState();

            // complete quest objective
            if(m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
                SendObjectiveComplete(EP_PWT_CM, 0);
        }

        if(m_ShiftPhase != m_OldPhase)
        {
            // send this too, sometimes the slider disappears, dunno why :(
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
            // send these updates to only the ones in this objective
            uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
            // send this too, sometimes it resets :S
            SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        }
        return m_OldState != m_State;
    }
    return false;
}

void OutdoorPvPObjectiveEP_PWT::FillInitialWorldStates(WorldPacket &data)
{
    data << EP_PWT_A << uint32(bool(m_TowerState & EP_TS_A));
    data << EP_PWT_H << uint32(bool(m_TowerState & EP_TS_H));
    data << EP_PWT_A_P << uint32(bool(m_TowerState & EP_TS_A_P));
    data << EP_PWT_H_P << uint32(bool(m_TowerState & EP_TS_H_P));
    data << EP_PWT_N_A << uint32(bool(m_TowerState & EP_TS_N_A));
    data << EP_PWT_N_H << uint32(bool(m_TowerState & EP_TS_N_H));
    data << EP_PWT_N << uint32(bool(m_TowerState & EP_TS_N));
}

void OutdoorPvPObjectiveEP_PWT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_PWT_A , bool(m_TowerState & EP_TS_A));
    m_PvP->SendUpdateWorldState(EP_PWT_H , bool(m_TowerState & EP_TS_H));
    m_PvP->SendUpdateWorldState(EP_PWT_A_P , bool(m_TowerState & EP_TS_A_P));
    m_PvP->SendUpdateWorldState(EP_PWT_H_P , bool(m_TowerState & EP_TS_H_P));
    m_PvP->SendUpdateWorldState(EP_PWT_N_A , bool(m_TowerState & EP_TS_N_A));
    m_PvP->SendUpdateWorldState(EP_PWT_N_H , bool(m_TowerState & EP_TS_N_H));
    m_PvP->SendUpdateWorldState(EP_PWT_N , bool(m_TowerState & EP_TS_N));
}

bool OutdoorPvPObjectiveEP_PWT::HandlePlayerEnter(Player *plr)
{
    if(OutdoorPvPObjective::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 1);
        uint32 phase = (uint32)ceil(( m_ShiftPhase + m_ShiftMaxPhase) / ( 2 * m_ShiftMaxPhase ) * 100.0f);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS, phase);
        plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_N, m_NeutralValue);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_PWT::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY, 0);
    OutdoorPvPObjective::HandlePlayerLeave(plr);
}

bool OutdoorPvPObjectiveEP_PWT::HandleCapturePointEvent(Player *plr, uint32 eventId)
{
    if(eventId == EPTowerPlayerEnterEvents[EP_PWT])
    {
        this->HandlePlayerEnter(plr);
        return true;
    }
    else if (eventId == EPTowerPlayerLeaveEvents[EP_PWT])
    {
        this->HandlePlayerLeave(plr);
        return true;
    }
    return false;
}

void OutdoorPvPObjectiveEP_PWT::SummonFlightMaster(uint32 team)
{
    if(m_FlightMasterSpawned != team)
    {
        m_FlightMasterSpawned = team;
        DelCreature(EP_PWT_FLIGHTMASTER);
        AddCreature(EP_PWT_FLIGHTMASTER,EP_PWT_FlightMaster.entry,team,EP_PWT_FlightMaster.map,EP_PWT_FlightMaster.x,EP_PWT_FlightMaster.y,EP_PWT_FlightMaster.z,EP_PWT_FlightMaster.o);
        Creature * c = HashMapHolder<Creature>::Find(m_Creatures[EP_PWT_FLIGHTMASTER]);
        if(c)
        {
            GossipOption gso;
            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_NPT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            c->addGossipOption(gso);

            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_EWT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            c->addGossipOption(gso);

            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_CGT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            c->addGossipOption(gso);
        }
    }
}

bool OutdoorPvPObjectiveEP_PWT::CanTalkTo(Player * p, Creature * c, GossipOption &gso)
{
    if( p->GetTeam() == m_FlightMasterSpawned &&
        c->GetGUID() == m_Creatures[EP_PWT_FLIGHTMASTER] &&
        gso.Id == 50 )
        return true;
    return false;
}

bool OutdoorPvPObjectiveEP_PWT::HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid)
{
    std::map<uint64,uint32>::iterator itr = m_CreatureTypes.find(guid);
    if(itr != m_CreatureTypes.end())
    {
        Creature * cr = HashMapHolder<Creature>::Find(guid);
        if(!cr)
            return true;
        if(itr->second == EP_PWT_FLIGHTMASTER)
        {
            uint32 src = EP_PWT_Taxi;
            uint32 dst = 0;
            switch(gossipid)
            {
            case 0:
                dst = EP_NPT_Taxi;
                break;
            case 1:
                dst = EP_EWT_Taxi;
                break;
            default:
                dst = EP_CGT_Taxi;
                break;
            }

            std::vector<uint32> nodes;
            nodes.resize(2);
            nodes[0] = src;
            nodes[1] = dst;

            plr->PlayerTalkClass->CloseGossip();
            plr->ActivateTaxiPathTo(nodes, cr);
            // leave the opvp, seems like moveinlineofsight isn't called when entering a taxi
            HandlePlayerLeave(plr);
        }
        return true;
    }
    return false;
}

// ep
OutdoorPvPEP::OutdoorPvPEP()
{
    m_TypeId = OUTDOOR_PVP_EP;
    memset(EP_Controls,0,sizeof(EP_Controls));
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
}

bool OutdoorPvPEP::SetupOutdoorPvP()
{
    for(int i = 0; i < EPBuffZonesNum; ++i)
        RegisterZone(EPBuffZones[i]);

    m_OutdoorPvPObjectives.push_back(new OutdoorPvPObjectiveEP_EWT(this));
    m_OutdoorPvPObjectives.push_back(new OutdoorPvPObjectiveEP_PWT(this));
    m_OutdoorPvPObjectives.push_back(new OutdoorPvPObjectiveEP_CGT(this));
    m_OutdoorPvPObjectives.push_back(new OutdoorPvPObjectiveEP_NPT(this));
    return true;
}

bool OutdoorPvPEP::Update(uint32 diff)
{
    if(OutdoorPvP::Update(diff))
    {
        m_AllianceTowersControlled = 0;
        m_HordeTowersControlled = 0;
        for(int i = 0; i < EP_TOWER_NUM; ++i)
        {
            if(EP_Controls[i] == ALLIANCE)
                ++m_AllianceTowersControlled;
            else if(EP_Controls[i] == HORDE)
                ++m_HordeTowersControlled;
            SendUpdateWorldState(EP_UI_TOWER_COUNT_A,m_AllianceTowersControlled);
            SendUpdateWorldState(EP_UI_TOWER_COUNT_H,m_HordeTowersControlled);
            BuffTeams();
        }
        return true;
    }
    return false;
}

void OutdoorPvPEP::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    // add buffs
    if(plr->GetTeam() == ALLIANCE)
    {
        if(m_AllianceTowersControlled && m_AllianceTowersControlled < 5)
            plr->CastSpell(plr,EP_AllianceBuffs[m_AllianceTowersControlled-1],true);
    }
    else
    {
        if(m_HordeTowersControlled && m_HordeTowersControlled < 5)
            plr->CastSpell(plr,EP_HordeBuffs[m_HordeTowersControlled-1],true);
    }
    OutdoorPvP::HandlePlayerEnterZone(plr,zone);
}

void OutdoorPvPEP::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // remove buffs
    if(plr->GetTeam() == ALLIANCE)
    {
        for(int i = 0; i < 4; ++i)
            plr->RemoveAurasDueToSpell(EP_AllianceBuffs[i]);
    }
    else
    {
        for(int i = 0; i < 4; ++i)
            plr->RemoveAurasDueToSpell(EP_HordeBuffs[i]);
    }
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}

void OutdoorPvPEP::BuffTeams()
{
    for(PlayerSet::iterator itr = m_players[0].begin(); itr != m_players[0].end(); ++itr)
    {
        Player * plr = *itr;
        {
            for(int i = 0; i < 4; ++i)
                plr->RemoveAurasDueToSpell(EP_AllianceBuffs[i]);
            if(m_AllianceTowersControlled && m_AllianceTowersControlled < 5)
                plr->CastSpell(plr,EP_AllianceBuffs[m_AllianceTowersControlled-1],true);
        }
    }
    for(PlayerSet::iterator itr = m_players[1].begin(); itr != m_players[1].end(); ++itr)
    {
        Player * plr = *itr;
        {
            for(int i = 0; i < 4; ++i)
                plr->RemoveAurasDueToSpell(EP_HordeBuffs[i]);
            if(m_HordeTowersControlled && m_HordeTowersControlled < 5)
                plr->CastSpell(plr,EP_HordeBuffs[m_HordeTowersControlled-1],true);
        }
    }
}

void OutdoorPvPEP::FillInitialWorldStates(WorldPacket & data)
{
    data << EP_UI_TOWER_COUNT_A << m_AllianceTowersControlled;
    data << EP_UI_TOWER_COUNT_H << m_HordeTowersControlled;
    data << EP_UI_TOWER_SLIDER_DISPLAY << uint32(0);
    data << EP_UI_TOWER_SLIDER_POS << uint32(50);
    data << EP_UI_TOWER_SLIDER_N << uint32(100);
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        (*itr)->FillInitialWorldStates(data);
    }
}

void OutdoorPvPEP::SendRemoveWorldStates(Player *plr)
{
    plr->SendUpdateWorldState(EP_UI_TOWER_COUNT_A,0);
    plr->SendUpdateWorldState(EP_UI_TOWER_COUNT_H,0);
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_DISPLAY,0);
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_POS,0);
    plr->SendUpdateWorldState(EP_UI_TOWER_SLIDER_N,0);

    plr->SendUpdateWorldState(EP_EWT_A,0);
    plr->SendUpdateWorldState(EP_EWT_H,0);
    plr->SendUpdateWorldState(EP_EWT_N,0);
    plr->SendUpdateWorldState(EP_EWT_A_P,0);
    plr->SendUpdateWorldState(EP_EWT_H_P,0);
    plr->SendUpdateWorldState(EP_EWT_N_A,0);
    plr->SendUpdateWorldState(EP_EWT_N_H,0);

    plr->SendUpdateWorldState(EP_PWT_A,0);
    plr->SendUpdateWorldState(EP_PWT_H,0);
    plr->SendUpdateWorldState(EP_PWT_N,0);
    plr->SendUpdateWorldState(EP_PWT_A_P,0);
    plr->SendUpdateWorldState(EP_PWT_H_P,0);
    plr->SendUpdateWorldState(EP_PWT_N_A,0);
    plr->SendUpdateWorldState(EP_PWT_N_H,0);

    plr->SendUpdateWorldState(EP_NPT_A,0);
    plr->SendUpdateWorldState(EP_NPT_H,0);
    plr->SendUpdateWorldState(EP_NPT_N,0);
    plr->SendUpdateWorldState(EP_NPT_A_P,0);
    plr->SendUpdateWorldState(EP_NPT_H_P,0);
    plr->SendUpdateWorldState(EP_NPT_N_A,0);
    plr->SendUpdateWorldState(EP_NPT_N_H,0);

    plr->SendUpdateWorldState(EP_CGT_A,0);
    plr->SendUpdateWorldState(EP_CGT_H,0);
    plr->SendUpdateWorldState(EP_CGT_N,0);
    plr->SendUpdateWorldState(EP_CGT_A_P,0);
    plr->SendUpdateWorldState(EP_CGT_H_P,0);
    plr->SendUpdateWorldState(EP_CGT_N_A,0);
    plr->SendUpdateWorldState(EP_CGT_N_H,0);
}

