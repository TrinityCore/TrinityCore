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
#include "OutdoorPvPZM.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "Player.h"
#include "Creature.h"
#include "ObjectAccessor.h"
#include "WorldPacket.h"
#include "GossipDef.h"
#include "World.h"
OPvPCapturePointZM_Beacon::OPvPCapturePointZM_Beacon(OutdoorPvP *pvp, ZM_BeaconType type)
: OPvPCapturePoint(pvp), m_TowerType(type), m_TowerState(ZM_TOWERSTATE_N)
{
    SetCapturePointData(ZMCapturePoints[type].entry,ZMCapturePoints[type].map,ZMCapturePoints[type].x,ZMCapturePoints[type].y,ZMCapturePoints[type].z,ZMCapturePoints[type].o,ZMCapturePoints[type].rot0,ZMCapturePoints[type].rot1,ZMCapturePoints[type].rot2,ZMCapturePoints[type].rot3);
}
void OPvPCapturePointZM_Beacon::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(ZMBeaconInfo[m_TowerType].ui_tower_n) << uint32(bool(m_TowerState & ZM_TOWERSTATE_N));
    data << uint32(ZMBeaconInfo[m_TowerType].map_tower_n) << uint32(bool(m_TowerState & ZM_TOWERSTATE_N));
    data << uint32(ZMBeaconInfo[m_TowerType].ui_tower_a) << uint32(bool(m_TowerState & ZM_TOWERSTATE_A));
    data << uint32(ZMBeaconInfo[m_TowerType].map_tower_a) << uint32(bool(m_TowerState & ZM_TOWERSTATE_A));
    data << uint32(ZMBeaconInfo[m_TowerType].ui_tower_h) << uint32(bool(m_TowerState & ZM_TOWERSTATE_H));
    data << uint32(ZMBeaconInfo[m_TowerType].map_tower_h) << uint32(bool(m_TowerState & ZM_TOWERSTATE_H));
}
void OPvPCapturePointZM_Beacon::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_n),uint32(bool(m_TowerState & ZM_TOWERSTATE_N)));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_n),uint32(bool(m_TowerState & ZM_TOWERSTATE_N)));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_a),uint32(bool(m_TowerState & ZM_TOWERSTATE_A)));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_a),uint32(bool(m_TowerState & ZM_TOWERSTATE_A)));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_h),uint32(bool(m_TowerState & ZM_TOWERSTATE_H)));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_h),uint32(bool(m_TowerState & ZM_TOWERSTATE_H)));
}
bool OPvPCapturePointZM_Beacon::HandlePlayerEnter(Player *plr)
{
    if(OPvPCapturePoint::HandlePlayerEnter(plr))
    {
        plr->SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_disp, 1);
        uint32 phase = (uint32)ceil(( m_value + m_maxValue) / ( 2 * m_maxValue ) * 100.0f);
        plr->SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_pos, phase);
        plr->SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_n, m_neutralValuePct);
        return true;
    }
    return false;
}
void OPvPCapturePointZM_Beacon::HandlePlayerLeave(Player *plr)
{
    plr->SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_disp, 0);
    OPvPCapturePoint::HandlePlayerLeave(plr);
}
void OPvPCapturePointZM_Beacon::ChangeState()
{
    // if changing from controlling alliance to horde
    if( m_OldState == OBJECTIVESTATE_ALLIANCE )
    {
        if(((OutdoorPvPZM*)m_PvP)->m_AllianceTowersControlled)
            ((OutdoorPvPZM*)m_PvP)->m_AllianceTowersControlled--;
        sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(ZMBeaconLooseA[m_TowerType]));
    }
    // if changing from controlling horde to alliance
    else if ( m_OldState == OBJECTIVESTATE_HORDE )
    {
        if(((OutdoorPvPZM*)m_PvP)->m_HordeTowersControlled)
            ((OutdoorPvPZM*)m_PvP)->m_HordeTowersControlled--;
        sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(ZMBeaconLooseH[m_TowerType]));
    }
    switch(m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
            m_TowerState = ZM_TOWERSTATE_A;
            if(((OutdoorPvPZM*)m_PvP)->m_AllianceTowersControlled<ZM_NUM_BEACONS)
                ((OutdoorPvPZM*)m_PvP)->m_AllianceTowersControlled++;
            sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(ZMBeaconCaptureA[m_TowerType]));
            break;
        case OBJECTIVESTATE_HORDE:
            m_TowerState = ZM_TOWERSTATE_H;
            if(((OutdoorPvPZM*)m_PvP)->m_HordeTowersControlled<ZM_NUM_BEACONS)
                ((OutdoorPvPZM*)m_PvP)->m_HordeTowersControlled++;
            sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(ZMBeaconCaptureH[m_TowerType]));
            break;
        case OBJECTIVESTATE_NEUTRAL:
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_TowerState = ZM_TOWERSTATE_N;
            break;
    }
    UpdateTowerState();
}
void OPvPCapturePointZM_Beacon::SendChangePhase()
{
    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_disp, 1);
    // send these updates to only the ones in this objective
    uint32 phase = (uint32)ceil(( m_value + m_maxValue) / ( 2 * m_maxValue ) * 100.0f);
    SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_pos, phase);
    SendUpdateWorldState(ZMBeaconInfo[m_TowerType].slider_n, m_neutralValuePct);
}
bool OutdoorPvPZM::Update(uint32 diff)
{
    bool changed = false;
    if(changed = OutdoorPvP::Update(diff))
    {
        if(m_AllianceTowersControlled == ZM_NUM_BEACONS)
            m_GraveYard->SetBeaconState(ALLIANCE);
        else if(m_HordeTowersControlled == ZM_NUM_BEACONS)
            m_GraveYard->SetBeaconState(HORDE);
        else
            m_GraveYard->SetBeaconState(0);
    }
    return changed;
}
void OutdoorPvPZM::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if(plr->GetTeam() == ALLIANCE)
    {
        if(m_GraveYard->m_GraveYardState & ZM_GRAVEYARD_A)
            plr->CastSpell(plr,ZM_CAPTURE_BUFF,true);
    }
    else
    {
        if(m_GraveYard->m_GraveYardState & ZM_GRAVEYARD_H)
            plr->CastSpell(plr,ZM_CAPTURE_BUFF,true);
    }
    OutdoorPvP::HandlePlayerEnterZone(plr,zone);
}
void OutdoorPvPZM::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // remove buffs
    plr->RemoveAurasDueToSpell(ZM_CAPTURE_BUFF);
    // remove flag
    plr->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
    plr->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}
OutdoorPvPZM::OutdoorPvPZM()
{
    m_TypeId = OUTDOOR_PVP_ZM;
    m_GraveYard = NULL;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
}
bool OutdoorPvPZM::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    // add the zones affected by the pvp buff
    for(int i = 0; i < OutdoorPvPZMBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPZMBuffZones[i]);
    AddCapturePoint(new OPvPCapturePointZM_Beacon(this,ZM_BEACON_WEST));
    AddCapturePoint(new OPvPCapturePointZM_Beacon(this,ZM_BEACON_EAST));
    m_GraveYard = new OPvPCapturePointZM_GraveYard(this);
    AddCapturePoint(m_GraveYard); // though the update function isn't used, the handleusego is!
    return true;
}
void OutdoorPvPZM::HandleKillImpl(Player *plr, Unit * killed)
{
    if(killed->GetTypeId() != TYPEID_PLAYER)
        return;
    if(plr->GetTeam() == ALLIANCE && ((Player*)killed)->GetTeam() != ALLIANCE)
        plr->CastSpell(plr,ZM_AlliancePlayerKillReward,true);
    else if(plr->GetTeam() == HORDE && ((Player*)killed)->GetTeam() != HORDE)
        plr->CastSpell(plr,ZM_HordePlayerKillReward,true);
}
bool OPvPCapturePointZM_GraveYard::Update(uint32 diff)
{
    bool retval = m_State != m_OldState;
    m_State = m_OldState;
    return retval;
}
int32 OPvPCapturePointZM_GraveYard::HandleOpenGo(Player *plr, uint64 guid)
{
    uint32 retval = OPvPCapturePoint::HandleOpenGo(plr, guid);
    if(retval>=0)
    {
        if(plr->HasAura(ZM_BATTLE_STANDARD_A) && m_GraveYardState != ZM_GRAVEYARD_A)
        {
            if(m_GraveYardState == ZM_GRAVEYARD_H)
                sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_LOOSE_GY_H));
            m_GraveYardState = ZM_GRAVEYARD_A;
            DelObject(0);   // only one gotype is used in the whole outdoor pvp, no need to call it a constant
            AddObject(0,ZM_Banner_A.entry,ZM_Banner_A.map,ZM_Banner_A.x,ZM_Banner_A.y,ZM_Banner_A.z,ZM_Banner_A.o,ZM_Banner_A.rot0,ZM_Banner_A.rot1,ZM_Banner_A.rot2,ZM_Banner_A.rot3);
            objmgr.RemoveGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, HORDE);          // rem gy
            objmgr.AddGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, ALLIANCE, false);   // add gy
            m_PvP->TeamApplyBuff(TEAM_ALLIANCE, ZM_CAPTURE_BUFF);
            plr->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
            sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_CAPTURE_GY_A));
        }
        else if(plr->HasAura(ZM_BATTLE_STANDARD_H) && m_GraveYardState != ZM_GRAVEYARD_H)
        {
            if(m_GraveYardState == ZM_GRAVEYARD_A)
                sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_LOOSE_GY_A));
            m_GraveYardState = ZM_GRAVEYARD_H;
            DelObject(0);   // only one gotype is used in the whole outdoor pvp, no need to call it a constant
            AddObject(0,ZM_Banner_H.entry,ZM_Banner_H.map,ZM_Banner_H.x,ZM_Banner_H.y,ZM_Banner_H.z,ZM_Banner_H.o,ZM_Banner_H.rot0,ZM_Banner_H.rot1,ZM_Banner_H.rot2,ZM_Banner_H.rot3);
            objmgr.RemoveGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, ALLIANCE);          // rem gy
            objmgr.AddGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, HORDE, false);   // add gy
            m_PvP->TeamApplyBuff(TEAM_HORDE, ZM_CAPTURE_BUFF);
            plr->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
            sWorld.SendZoneText(ZM_GRAVEYARD_ZONE,objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_CAPTURE_GY_H));
        }
        UpdateTowerState();
    }
    return retval;
}
OPvPCapturePointZM_GraveYard::OPvPCapturePointZM_GraveYard(OutdoorPvP *pvp)
: OPvPCapturePoint(pvp)
{
    m_BothControllingFaction = 0;
    m_GraveYardState = ZM_GRAVEYARD_N;
    m_FlagCarrierGUID = 0;
    // add field scouts here
    AddCreature(ZM_ALLIANCE_FIELD_SCOUT,ZM_AllianceFieldScout.entry,ZM_AllianceFieldScout.teamval,ZM_AllianceFieldScout.map,ZM_AllianceFieldScout.x,ZM_AllianceFieldScout.y,ZM_AllianceFieldScout.z,ZM_AllianceFieldScout.o);
    AddCreature(ZM_HORDE_FIELD_SCOUT,ZM_HordeFieldScout.entry,ZM_HordeFieldScout.teamval,ZM_HordeFieldScout.map,ZM_HordeFieldScout.x,ZM_HordeFieldScout.y,ZM_HordeFieldScout.z,ZM_HordeFieldScout.o);
    // add neutral banner
    AddObject(0,ZM_Banner_N.entry,ZM_Banner_N.map,ZM_Banner_N.x,ZM_Banner_N.y,ZM_Banner_N.z,ZM_Banner_N.o,ZM_Banner_N.rot0,ZM_Banner_N.rot1,ZM_Banner_N.rot2,ZM_Banner_N.rot3);
}
void OPvPCapturePointZM_GraveYard::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_N,uint32(bool(m_GraveYardState & ZM_GRAVEYARD_N)));
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_H,uint32(bool(m_GraveYardState & ZM_GRAVEYARD_H)));
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_A,uint32(bool(m_GraveYardState & ZM_GRAVEYARD_A)));
    m_PvP->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_READY,uint32(m_BothControllingFaction == ALLIANCE));
    m_PvP->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_NOT_READY,uint32(m_BothControllingFaction != ALLIANCE));
    m_PvP->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_READY,uint32(m_BothControllingFaction == HORDE));
    m_PvP->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_NOT_READY,uint32(m_BothControllingFaction != HORDE));
}
void OPvPCapturePointZM_GraveYard::FillInitialWorldStates(WorldPacket &data)
{
    data << ZM_MAP_GRAVEYARD_N  << uint32(bool(m_GraveYardState & ZM_GRAVEYARD_N));
    data << ZM_MAP_GRAVEYARD_H  << uint32(bool(m_GraveYardState & ZM_GRAVEYARD_H));
    data << ZM_MAP_GRAVEYARD_A  << uint32(bool(m_GraveYardState & ZM_GRAVEYARD_A));
    data << ZM_MAP_ALLIANCE_FLAG_READY  << uint32(m_BothControllingFaction == ALLIANCE);
    data << ZM_MAP_ALLIANCE_FLAG_NOT_READY  << uint32(m_BothControllingFaction != ALLIANCE);
    data << ZM_MAP_HORDE_FLAG_READY  << uint32(m_BothControllingFaction == HORDE);
    data << ZM_MAP_HORDE_FLAG_NOT_READY  << uint32(m_BothControllingFaction != HORDE);
}
void OPvPCapturePointZM_GraveYard::SetBeaconState(uint32 controlling_faction)
{
    // nothing to do here
    if(m_BothControllingFaction == controlling_faction)
        return;
    m_BothControllingFaction = controlling_faction;
    switch(controlling_faction)
    {
    case ALLIANCE:
        // if ally already controls the gy and taken back both beacons, return, nothing to do for us
        if(m_GraveYardState & ZM_GRAVEYARD_A)
            return;
        // ally doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    case HORDE:
        // if horde already controls the gy and taken back both beacons, return, nothing to do for us
        if(m_GraveYardState & ZM_GRAVEYARD_H)
            return;
        // horde doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    default:
        // if the graveyard is not neutral, then leave it that way
        // if the graveyard is neutral, then we have to dispel the buff from the flag carrier
        if(m_GraveYardState & ZM_GRAVEYARD_N)
        {
            // gy was neutral, thus neutral banner was spawned, it is possible that someone was taking the flag to the gy
            if(m_FlagCarrierGUID)
            {
                // remove flag from carrier, reset flag carrier guid
                Player * p = objmgr.GetPlayer(m_FlagCarrierGUID);
                if(p)
                {
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
                }
                m_FlagCarrierGUID = 0;
            }
        }
        break;
    }
    // send worldstateupdate
    UpdateTowerState();
}
bool OPvPCapturePointZM_GraveYard::CanTalkTo(Player * plr, Creature * c, GossipOption & gso)
{
    uint64 guid = c->GetGUID();
    std::map<uint64,uint32>::iterator itr = m_CreatureTypes.find(guid);
    if(itr != m_CreatureTypes.end())
    {
        if(itr->second == ZM_ALLIANCE_FIELD_SCOUT && plr->GetTeam() == ALLIANCE && m_BothControllingFaction == ALLIANCE && !m_FlagCarrierGUID && m_GraveYardState != ZM_GRAVEYARD_A)
        {
            gso.OptionText.assign(objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_GOSSIP_ALLIANCE));
            return true;
        }
        else if(itr->second == ZM_HORDE_FIELD_SCOUT && plr->GetTeam() == HORDE && m_BothControllingFaction == HORDE && !m_FlagCarrierGUID && m_GraveYardState != ZM_GRAVEYARD_H)
        {
            gso.OptionText.assign(objmgr.GetTrinityStringForDBCLocale(LANG_OPVP_ZM_GOSSIP_HORDE));
            return true;
        }
    }
    return false;
}
bool OPvPCapturePointZM_GraveYard::HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid)
{
    std::map<uint64,uint32>::iterator itr = m_CreatureTypes.find(guid);
    if(itr != m_CreatureTypes.end())
    {
        Creature * cr = HashMapHolder<Creature>::Find(guid);
        if(!cr)
            return true;
        // if the flag is already taken, then return
        if(m_FlagCarrierGUID)
            return true;
        if(itr->second == ZM_ALLIANCE_FIELD_SCOUT)
        {
            cr->CastSpell(plr,ZM_BATTLE_STANDARD_A,true);
            m_FlagCarrierGUID = plr->GetGUID();
        }
        else if(itr->second == ZM_HORDE_FIELD_SCOUT)
        {
            cr->CastSpell(plr,ZM_BATTLE_STANDARD_H,true);
            m_FlagCarrierGUID = plr->GetGUID();
        }
        UpdateTowerState();
        plr->PlayerTalkClass->CloseGossip();
        return true;
    }
    return false;
}
bool OPvPCapturePointZM_GraveYard::HandleDropFlag(Player * plr, uint32 spellId)
{
    switch(spellId)
    {
    case ZM_BATTLE_STANDARD_A:
        m_FlagCarrierGUID = 0;
        return true;
    case ZM_BATTLE_STANDARD_H:
        m_FlagCarrierGUID = 0;
        return true;
    }
    return false;
}
void OutdoorPvPZM::FillInitialWorldStates(WorldPacket &data)
{
    data << ZM_WORLDSTATE_UNK_1 << uint32(1);
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        itr->second->FillInitialWorldStates(data);
    }
}
void OutdoorPvPZM::SendRemoveWorldStates(Player *plr)
{
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_N_W,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_POS_W,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_DISPLAY_W,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_N_E,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_POS_E,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_SLIDER_DISPLAY_E,0);
    plr->SendUpdateWorldState(ZM_WORLDSTATE_UNK_1,1);
    plr->SendUpdateWorldState(ZM_UI_TOWER_EAST_N,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_EAST_H,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_EAST_A,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_WEST_N,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_WEST_H,0);
    plr->SendUpdateWorldState(ZM_UI_TOWER_WEST_A,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_EAST_N,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_EAST_H,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_EAST_A,0);
    plr->SendUpdateWorldState(ZM_MAP_GRAVEYARD_H,0);
    plr->SendUpdateWorldState(ZM_MAP_GRAVEYARD_A,0);
    plr->SendUpdateWorldState(ZM_MAP_GRAVEYARD_N,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_WEST_N,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_WEST_H,0);
    plr->SendUpdateWorldState(ZM_MAP_TOWER_WEST_A,0);
    plr->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_READY,0);
    plr->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_NOT_READY,0);
    plr->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_NOT_READY,0);
    plr->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_READY,0);
}

