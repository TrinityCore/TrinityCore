/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "MapManager.h"
#include "OutdoorPvPHP.h"
#include "Player.h"
#include "WorldStatePackets.h"

const uint32 HP_LANG_CAPTURE_A[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_ALLIANCE, TEXT_OVERLOOK_TAKEN_ALLIANCE, TEXT_STADIUM_TAKEN_ALLIANCE };

const uint32 HP_LANG_CAPTURE_H[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_HORDE, TEXT_OVERLOOK_TAKEN_HORDE, TEXT_STADIUM_TAKEN_HORDE };

OPvPCapturePointHP::OPvPCapturePointHP(OutdoorPvP* pvp, OutdoorPvPHPTowerType type)
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
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
}

bool OutdoorPvPHP::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    SetMapFromZone(OutdoorPvPHPBuffZones[0]);

    // add the zones affected by the pvp buff
    for (int i = 0; i < OutdoorPvPHPBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPHPBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_BROKEN_HILL));

    AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_OVERLOOK));

    AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_STADIUM));

    return true;
}

void OutdoorPvPHP::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    // add buffs
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >=3)
            player->CastSpell(player, AllianceBuff, true);
    }
    else
    {
        if (m_HordeTowersControlled >=3)
            player->CastSpell(player, HordeBuff, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPHP::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    if (player->GetTeam() == ALLIANCE)
    {
        player->RemoveAurasDueToSpell(AllianceBuff);
    }
    else
    {
        player->RemoveAurasDueToSpell(HordeBuff);
    }
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
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

void OutdoorPvPHP::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(HP_UI_TOWER_DISPLAY_A, 0);
    player->SendUpdateWorldState(HP_UI_TOWER_DISPLAY_H, 0);
    player->SendUpdateWorldState(HP_UI_TOWER_COUNT_H, 0);
    player->SendUpdateWorldState(HP_UI_TOWER_COUNT_A, 0);

    for (int i = 0; i < HP_TOWER_NUM; ++i)
    {
        player->SendUpdateWorldState(HP_MAP_N[i], 0);
        player->SendUpdateWorldState(HP_MAP_A[i], 0);
        player->SendUpdateWorldState(HP_MAP_H[i], 0);
    }
}

void OutdoorPvPHP::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(HP_UI_TOWER_DISPLAY_A), 1);
    packet.Worldstates.emplace_back(uint32(HP_UI_TOWER_DISPLAY_H), 1);
    packet.Worldstates.emplace_back(uint32(HP_UI_TOWER_COUNT_A), int32(m_AllianceTowersControlled));
    packet.Worldstates.emplace_back(uint32(HP_UI_TOWER_COUNT_H), int32(m_HordeTowersControlled));

    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(packet);
}

void OPvPCapturePointHP::ChangeState()
{
    uint32 field = 0;
    switch (m_OldState)
    {
    case OBJECTIVESTATE_NEUTRAL:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE:
        field = HP_MAP_A[m_TowerType];
        if (uint32 alliance_towers = ((OutdoorPvPHP*)m_PvP)->GetAllianceTowersControlled())
            ((OutdoorPvPHP*)m_PvP)->SetAllianceTowersControlled(--alliance_towers);
        break;
    case OBJECTIVESTATE_HORDE:
        field = HP_MAP_H[m_TowerType];
        if (uint32 horde_towers = ((OutdoorPvPHP*)m_PvP)->GetHordeTowersControlled())
            ((OutdoorPvPHP*)m_PvP)->SetHordeTowersControlled(--horde_towers);
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
    switch (m_State)
    {
    case OBJECTIVESTATE_NEUTRAL:
        field = HP_MAP_N[m_TowerType];
        break;
    case OBJECTIVESTATE_ALLIANCE:
    {
        field = HP_MAP_A[m_TowerType];
        artkit = 2;
        artkit2 = HP_TowerArtKit_A[m_TowerType];
        uint32 alliance_towers = ((OutdoorPvPHP*)m_PvP)->GetAllianceTowersControlled();
        if (alliance_towers < 3)
            ((OutdoorPvPHP*)m_PvP)->SetAllianceTowersControlled(++alliance_towers);
        m_PvP->SendDefenseMessage(OutdoorPvPHPBuffZones[0], HP_LANG_CAPTURE_A[m_TowerType]);
        break;
    }
    case OBJECTIVESTATE_HORDE:
    {
        field = HP_MAP_H[m_TowerType];
        artkit = 1;
        artkit2 = HP_TowerArtKit_H[m_TowerType];
        uint32 horde_towers = ((OutdoorPvPHP*)m_PvP)->GetHordeTowersControlled();
        if (horde_towers < 3)
            ((OutdoorPvPHP*)m_PvP)->SetHordeTowersControlled(++horde_towers);
        m_PvP->SendDefenseMessage(OutdoorPvPHPBuffZones[0], HP_LANG_CAPTURE_H[m_TowerType]);
        break;
    }
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

    Map* map = sMapMgr->FindMap(530, 0);
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[m_TowerType]);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit2);

    // send world state update
    if (field)
        m_PvP->SendUpdateWorldState(field, 1);

    // complete quest objective
    if (m_State == OBJECTIVESTATE_ALLIANCE || m_State == OBJECTIVESTATE_HORDE)
        SendObjectiveComplete(HP_CREDITMARKER[m_TowerType], ObjectGuid::Empty);
}

void OPvPCapturePointHP::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            packet.Worldstates.emplace_back(uint32(HP_MAP_N[m_TowerType]), 0);
            packet.Worldstates.emplace_back(uint32(HP_MAP_A[m_TowerType]), 1);
            packet.Worldstates.emplace_back(uint32(HP_MAP_H[m_TowerType]), 0);
            break;
        case OBJECTIVESTATE_HORDE:
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            packet.Worldstates.emplace_back(uint32(HP_MAP_N[m_TowerType]), 0);
            packet.Worldstates.emplace_back(uint32(HP_MAP_A[m_TowerType]), 0);
            packet.Worldstates.emplace_back(uint32(HP_MAP_H[m_TowerType]), 1);
            break;
        case OBJECTIVESTATE_NEUTRAL:
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        default:
            packet.Worldstates.emplace_back(uint32(HP_MAP_N[m_TowerType]), 1);
            packet.Worldstates.emplace_back(uint32(HP_MAP_A[m_TowerType]), 0);
            packet.Worldstates.emplace_back(uint32(HP_MAP_H[m_TowerType]), 0);
            break;
    }
}

void OutdoorPvPHP::HandleKillImpl(Player* player, Unit* killed)
{
    if (killed->GetTypeId() != TYPEID_PLAYER)
        return;

    if (player->GetTeam() == ALLIANCE && killed->ToPlayer()->GetTeam() != ALLIANCE)
        player->CastSpell(player, AlliancePlayerKillReward, true);
    else if (player->GetTeam() == HORDE && killed->ToPlayer()->GetTeam() != HORDE)
        player->CastSpell(player, HordePlayerKillReward, true);
}

uint32 OutdoorPvPHP::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPHP::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPHP::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPHP::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

class OutdoorPvP_hellfire_peninsula : public OutdoorPvPScript
{
    public:
        OutdoorPvP_hellfire_peninsula() : OutdoorPvPScript("outdoorpvp_hp") { }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPHP();
        }
};

void AddSC_outdoorpvp_hp()
{
    new OutdoorPvP_hellfire_peninsula();
}
