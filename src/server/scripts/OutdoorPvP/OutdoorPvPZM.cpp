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

#include "ScriptMgr.h"
#include "Creature.h"
#include "GossipDef.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPZM.h"
#include "Player.h"
#include "WorldStatePackets.h"

OPvPCapturePointZM_Beacon::OPvPCapturePointZM_Beacon(OutdoorPvP* pvp, ZM_BeaconType type)
: OPvPCapturePoint(pvp), m_TowerType(type), m_TowerState(ZM_TOWERSTATE_N)
{
    SetCapturePointData(ZMCapturePoints[type].entry, ZMCapturePoints[type].map, ZMCapturePoints[type].x, ZMCapturePoints[type].y, ZMCapturePoints[type].z, ZMCapturePoints[type].o, ZMCapturePoints[type].rot0, ZMCapturePoints[type].rot1, ZMCapturePoints[type].rot2, ZMCapturePoints[type].rot3);
}

void OPvPCapturePointZM_Beacon::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].ui_tower_n, (m_TowerState & ZM_TOWERSTATE_N) != 0);
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].map_tower_n, (m_TowerState & ZM_TOWERSTATE_N) != 0);
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].ui_tower_a, (m_TowerState & ZM_TOWERSTATE_A) != 0);
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].map_tower_a, 0);
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].ui_tower_h, (m_TowerState & ZM_TOWERSTATE_H) != 0);
    packet.Worldstates.emplace_back(ZMBeaconInfo[m_TowerType].map_tower_h, (m_TowerState & ZM_TOWERSTATE_H) != 0);
}

void OPvPCapturePointZM_Beacon::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_n), uint32((m_TowerState & ZM_TOWERSTATE_N) != 0));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_n), uint32((m_TowerState & ZM_TOWERSTATE_N) != 0));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_a), uint32((m_TowerState & ZM_TOWERSTATE_A) != 0));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_a), uint32((m_TowerState & ZM_TOWERSTATE_A) != 0));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].ui_tower_h), uint32((m_TowerState & ZM_TOWERSTATE_H) != 0));
    m_PvP->SendUpdateWorldState(uint32(ZMBeaconInfo[m_TowerType].map_tower_h), uint32((m_TowerState & ZM_TOWERSTATE_H) != 0));
}

void OPvPCapturePointZM_Beacon::ChangeState()
{
    // if changing from controlling alliance to horde
    if (m_OldState == OBJECTIVESTATE_ALLIANCE)
    {
        if (uint32 alliance_towers = ((OutdoorPvPZM*)m_PvP)->GetAllianceTowersControlled())
            ((OutdoorPvPZM*)m_PvP)->SetAllianceTowersControlled(--alliance_towers);
    }
    // if changing from controlling horde to alliance
    else if (m_OldState == OBJECTIVESTATE_HORDE)
    {
        if (uint32 horde_towers = ((OutdoorPvPZM*)m_PvP)->GetHordeTowersControlled())
            ((OutdoorPvPZM*)m_PvP)->SetHordeTowersControlled(--horde_towers);
    }

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
        {
            m_TowerState = ZM_TOWERSTATE_A;
            uint32 alliance_towers = ((OutdoorPvPZM*)m_PvP)->GetAllianceTowersControlled();
            if (alliance_towers < ZM_NUM_BEACONS)
                ((OutdoorPvPZM*)m_PvP)->SetAllianceTowersControlled(++alliance_towers);
            m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, ZMBeaconCaptureA[m_TowerType]);
            break;
        }
        case OBJECTIVESTATE_HORDE:
        {
            m_TowerState = ZM_TOWERSTATE_H;
            uint32 horde_towers = ((OutdoorPvPZM*)m_PvP)->GetHordeTowersControlled();
            if (horde_towers < ZM_NUM_BEACONS)
                ((OutdoorPvPZM*)m_PvP)->SetHordeTowersControlled(++horde_towers);
            m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, ZMBeaconCaptureH[m_TowerType]);
            break;
        }
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

bool OutdoorPvPZM::Update(uint32 diff)
{
    bool changed = OutdoorPvP::Update(diff);
    if (changed)
    {
        if (m_AllianceTowersControlled == ZM_NUM_BEACONS)
            m_GraveYard->SetBeaconState(ALLIANCE);
        else if (m_HordeTowersControlled == ZM_NUM_BEACONS)
            m_GraveYard->SetBeaconState(HORDE);
        else
            m_GraveYard->SetBeaconState(0);
    }
    return changed;
}

void OutdoorPvPZM::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_GraveYard->GetGraveYardState() & ZM_GRAVEYARD_A)
            player->CastSpell(player, ZM_CAPTURE_BUFF, true);
    }
    else
    {
        if (m_GraveYard->GetGraveYardState() & ZM_GRAVEYARD_H)
            player->CastSpell(player, ZM_CAPTURE_BUFF, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPZM::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    player->RemoveAurasDueToSpell(ZM_CAPTURE_BUFF);
    // remove flag
    player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
    player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
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

    SetMapFromZone(OutdoorPvPZMBuffZones[0]);

    // add the zones affected by the pvp buff
    for (uint8 i = 0; i < OutdoorPvPZMBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPZMBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointZM_Beacon(this, ZM_BEACON_WEST));
    AddCapturePoint(new OPvPCapturePointZM_Beacon(this, ZM_BEACON_EAST));
    m_GraveYard = new OPvPCapturePointZM_GraveYard(this);
    AddCapturePoint(m_GraveYard); // though the update function isn't used, the handleusego is!

    return true;
}

void OutdoorPvPZM::HandleKillImpl(Player* player, Unit* killed)
{
    if (killed->GetTypeId() != TYPEID_PLAYER)
        return;

    if (player->GetTeam() == ALLIANCE && killed->ToPlayer()->GetTeam() != ALLIANCE)
        player->CastSpell(player, ZM_AlliancePlayerKillReward, true);
    else if (player->GetTeam() == HORDE && killed->ToPlayer()->GetTeam() != HORDE)
        player->CastSpell(player, ZM_HordePlayerKillReward, true);
}

bool OPvPCapturePointZM_GraveYard::Update(uint32 /*diff*/)
{
    bool retval = m_State != m_OldState;
    m_State = m_OldState;
    return retval;
}

int32 OPvPCapturePointZM_GraveYard::HandleOpenGo(Player* player, GameObject* go)
{
    int32 retval = OPvPCapturePoint::HandleOpenGo(player, go);
    if (retval >= 0)
    {
        if (player->HasAura(ZM_BATTLE_STANDARD_A) && m_GraveYardState != ZM_GRAVEYARD_A)
        {
            m_GraveYardState = ZM_GRAVEYARD_A;
            DelObject(0);   // only one gotype is used in the whole outdoor pvp, no need to call it a constant
            AddObject(0, ZM_Banner_A.entry, ZM_Banner_A.map, ZM_Banner_A.x, ZM_Banner_A.y, ZM_Banner_A.z, ZM_Banner_A.o, ZM_Banner_A.rot0, ZM_Banner_A.rot1, ZM_Banner_A.rot2, ZM_Banner_A.rot3);
            sObjectMgr->RemoveGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, HORDE);          // rem gy
            sObjectMgr->AddGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, ALLIANCE, false);   // add gy
            m_PvP->TeamApplyBuff(TEAM_ALLIANCE, ZM_CAPTURE_BUFF);
            player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
            m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, TEXT_TWIN_SPIRE_RUINS_TAKEN_ALLIANCE);
        }
        else if (player->HasAura(ZM_BATTLE_STANDARD_H) && m_GraveYardState != ZM_GRAVEYARD_H)
        {
            m_GraveYardState = ZM_GRAVEYARD_H;
            DelObject(0);   // only one gotype is used in the whole outdoor pvp, no need to call it a constant
            AddObject(0, ZM_Banner_H.entry, ZM_Banner_H.map, ZM_Banner_H.x, ZM_Banner_H.y, ZM_Banner_H.z, ZM_Banner_H.o, ZM_Banner_H.rot0, ZM_Banner_H.rot1, ZM_Banner_H.rot2, ZM_Banner_H.rot3);
            sObjectMgr->RemoveGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, ALLIANCE);          // rem gy
            sObjectMgr->AddGraveYardLink(ZM_GRAVEYARD_ID, ZM_GRAVEYARD_ZONE, HORDE, false);   // add gy
            m_PvP->TeamApplyBuff(TEAM_HORDE, ZM_CAPTURE_BUFF);
            player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
            m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, TEXT_TWIN_SPIRE_RUINS_TAKEN_HORDE);
        }
        UpdateTowerState();
    }
    return retval;
}

OPvPCapturePointZM_GraveYard::OPvPCapturePointZM_GraveYard(OutdoorPvP* pvp)
: OPvPCapturePoint(pvp)
{
    m_BothControllingFaction = 0;
    m_GraveYardState = ZM_GRAVEYARD_N;
    m_FlagCarrierGUID.Clear();
    // add field scouts here
    AddCreature(ZM_ALLIANCE_FIELD_SCOUT, ZM_AllianceFieldScout.entry, ZM_AllianceFieldScout.map, ZM_AllianceFieldScout.x, ZM_AllianceFieldScout.y, ZM_AllianceFieldScout.z, ZM_AllianceFieldScout.o);
    AddCreature(ZM_HORDE_FIELD_SCOUT, ZM_HordeFieldScout.entry, ZM_HordeFieldScout.map, ZM_HordeFieldScout.x, ZM_HordeFieldScout.y, ZM_HordeFieldScout.z, ZM_HordeFieldScout.o);
    // add neutral banner
    AddObject(0, ZM_Banner_N.entry, ZM_Banner_N.map, ZM_Banner_N.x, ZM_Banner_N.y, ZM_Banner_N.z, ZM_Banner_N.o, ZM_Banner_N.rot0, ZM_Banner_N.rot1, ZM_Banner_N.rot2, ZM_Banner_N.rot3);
}

void OPvPCapturePointZM_GraveYard::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_N, uint32((m_GraveYardState & ZM_GRAVEYARD_N) != 0));
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_H, uint32((m_GraveYardState & ZM_GRAVEYARD_H) != 0));
    m_PvP->SendUpdateWorldState(ZM_MAP_GRAVEYARD_A, uint32((m_GraveYardState & ZM_GRAVEYARD_A) != 0));

    m_PvP->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_READY, uint32(m_BothControllingFaction == ALLIANCE));
    m_PvP->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_NOT_READY, uint32(m_BothControllingFaction != ALLIANCE));
    m_PvP->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_READY, uint32(m_BothControllingFaction == HORDE));
    m_PvP->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_NOT_READY, uint32(m_BothControllingFaction != HORDE));
}

void OPvPCapturePointZM_GraveYard::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(ZM_MAP_GRAVEYARD_N), int32((m_GraveYardState & ZM_GRAVEYARD_N) != 0));
    packet.Worldstates.emplace_back(uint32(ZM_MAP_GRAVEYARD_H), int32((m_GraveYardState & ZM_GRAVEYARD_H) != 0));
    packet.Worldstates.emplace_back(uint32(ZM_MAP_GRAVEYARD_A), int32((m_GraveYardState & ZM_GRAVEYARD_A) != 0));

    packet.Worldstates.emplace_back(uint32(ZM_MAP_ALLIANCE_FLAG_READY), int32(m_BothControllingFaction == ALLIANCE));
    packet.Worldstates.emplace_back(uint32(ZM_MAP_ALLIANCE_FLAG_NOT_READY), int32(m_BothControllingFaction != ALLIANCE));
    packet.Worldstates.emplace_back(uint32(ZM_MAP_HORDE_FLAG_READY), int32(m_BothControllingFaction == HORDE));
    packet.Worldstates.emplace_back(uint32(ZM_MAP_HORDE_FLAG_NOT_READY), int32(m_BothControllingFaction != HORDE));
}

void OPvPCapturePointZM_GraveYard::SetBeaconState(uint32 controlling_faction)
{
    // nothing to do here
    if (m_BothControllingFaction == controlling_faction)
        return;
    m_BothControllingFaction = controlling_faction;

    switch (controlling_faction)
    {
    case ALLIANCE:
        // if ally already controls the gy and taken back both beacons, return, nothing to do for us
        if (m_GraveYardState & ZM_GRAVEYARD_A)
            return;
        // ally doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    case HORDE:
        // if horde already controls the gy and taken back both beacons, return, nothing to do for us
        if (m_GraveYardState & ZM_GRAVEYARD_H)
            return;
        // horde doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    default:
        // if the graveyard is not neutral, then leave it that way
        // if the graveyard is neutral, then we have to dispel the buff from the flag carrier
        if (m_GraveYardState & ZM_GRAVEYARD_N)
        {
            // gy was neutral, thus neutral banner was spawned, it is possible that someone was taking the flag to the gy
            if (!m_FlagCarrierGUID.IsEmpty())
            {
                // remove flag from carrier, reset flag carrier guid
                Player* p = ObjectAccessor::FindPlayer(m_FlagCarrierGUID);
                if (p)
                {
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
                }
                m_FlagCarrierGUID.Clear();
            }
        }
        break;
    }
    // send worldstateupdate
    UpdateTowerState();
}

bool OPvPCapturePointZM_GraveYard::CanTalkTo(Player* player, Creature* c, GossipMenuItems const& /*gso*/)
{
    std::map<ObjectGuid::LowType, uint32>::iterator itr = m_CreatureTypes.find(c->GetSpawnId());
    if (itr != m_CreatureTypes.end())
    {
        if (itr->second == ZM_ALLIANCE_FIELD_SCOUT && player->GetTeam() == ALLIANCE && m_BothControllingFaction == ALLIANCE && !m_FlagCarrierGUID && m_GraveYardState != ZM_GRAVEYARD_A)
            return true;
        else if (itr->second == ZM_HORDE_FIELD_SCOUT && player->GetTeam() == HORDE && m_BothControllingFaction == HORDE && !m_FlagCarrierGUID && m_GraveYardState != ZM_GRAVEYARD_H)
            return true;
    }
    return false;
}

bool OPvPCapturePointZM_GraveYard::HandleGossipOption(Player* player, Creature* creature, uint32 /*gossipid*/)
{
    std::map<ObjectGuid::LowType, uint32>::iterator itr = m_CreatureTypes.find(creature->GetSpawnId());
    if (itr != m_CreatureTypes.end())
    {
        // if the flag is already taken, then return
        if (!m_FlagCarrierGUID.IsEmpty())
            return true;
        if (itr->second == ZM_ALLIANCE_FIELD_SCOUT)
        {
            creature->CastSpell(player, ZM_BATTLE_STANDARD_A, true);
            m_FlagCarrierGUID = player->GetGUID();
        }
        else if (itr->second == ZM_HORDE_FIELD_SCOUT)
        {
            creature->CastSpell(player, ZM_BATTLE_STANDARD_H, true);
            m_FlagCarrierGUID = player->GetGUID();
        }
        UpdateTowerState();
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }
    return false;
}

bool OPvPCapturePointZM_GraveYard::HandleDropFlag(Player* /*player*/, uint32 spellId)
{
    switch (spellId)
    {
    case ZM_BATTLE_STANDARD_A:
        m_FlagCarrierGUID.Clear();
        return true;
    case ZM_BATTLE_STANDARD_H:
        m_FlagCarrierGUID.Clear();
        return true;
    }
    return false;
}

uint32 OPvPCapturePointZM_GraveYard::GetGraveYardState() const
{
    return m_GraveYardState;
}

uint32 OutdoorPvPZM::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPZM::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPZM::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPZM::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

void OutdoorPvPZM::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(ZM_WORLDSTATE_UNK_1), 1);
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(packet);
}

void OutdoorPvPZM::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(ZM_WORLDSTATE_UNK_1, 1);
    player->SendUpdateWorldState(ZM_UI_TOWER_EAST_N, 0);
    player->SendUpdateWorldState(ZM_UI_TOWER_EAST_H, 0);
    player->SendUpdateWorldState(ZM_UI_TOWER_EAST_A, 0);
    player->SendUpdateWorldState(ZM_UI_TOWER_WEST_N, 0);
    player->SendUpdateWorldState(ZM_UI_TOWER_WEST_H, 0);
    player->SendUpdateWorldState(ZM_UI_TOWER_WEST_A, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_EAST_N, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_EAST_H, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_EAST_A, 0);
    player->SendUpdateWorldState(ZM_MAP_GRAVEYARD_H, 0);
    player->SendUpdateWorldState(ZM_MAP_GRAVEYARD_A, 0);
    player->SendUpdateWorldState(ZM_MAP_GRAVEYARD_N, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_WEST_N, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_WEST_H, 0);
    player->SendUpdateWorldState(ZM_MAP_TOWER_WEST_A, 0);
    player->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_READY, 0);
    player->SendUpdateWorldState(ZM_MAP_HORDE_FLAG_NOT_READY, 0);
    player->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_NOT_READY, 0);
    player->SendUpdateWorldState(ZM_MAP_ALLIANCE_FLAG_READY, 0);
}

class OutdoorPvP_zangarmarsh : public OutdoorPvPScript
{
    public:
        OutdoorPvP_zangarmarsh() : OutdoorPvPScript("outdoorpvp_zm") { }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPZM();
        }
};

void AddSC_outdoorpvp_zm()
{
    new OutdoorPvP_zangarmarsh();
}
