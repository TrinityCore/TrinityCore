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

#include "OutdoorPvPHP.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldStatePackets.h"

uint32 const OutdoorPvPHPBuffZonesNum = 6;
uint32 const OutdoorPvPHPBuffZones[OutdoorPvPHPBuffZonesNum] = { 3483, 3563, 3562, 3713, 3714, 3836 }; //  HP, citadel, ramparts, blood furnace, shattered halls, mag's lair
uint32 const HP_CREDITMARKER[HP_TOWER_NUM] = { 19032, 19028, 19029 };
//uint32 const HP_CapturePointEvent_Enter[HP_TOWER_NUM] = { 11404, 11396, 11388 };
//uint32 const HP_CapturePointEvent_Leave[HP_TOWER_NUM] = { 11403, 11395, 11387 };
uint32 const HP_MAP_N[HP_TOWER_NUM] = { 2485, 2482, 2472 };
uint32 const HP_MAP_A[HP_TOWER_NUM] = { 2483, 2480, 2471 };
uint32 const HP_MAP_H[HP_TOWER_NUM] = { 2484, 2481, 2470 };
uint32 const HP_TowerArtKit_A[HP_TOWER_NUM] = { 65, 62, 67 };
uint32 const HP_TowerArtKit_H[HP_TOWER_NUM] = { 64, 61, 68 };
uint32 const HP_TowerArtKit_N[HP_TOWER_NUM] = { 66, 63, 69 };

uint32 const HP_LANG_CAPTURE_A[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_ALLIANCE, TEXT_OVERLOOK_TAKEN_ALLIANCE, TEXT_STADIUM_TAKEN_ALLIANCE };
uint32 const HP_LANG_CAPTURE_H[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_HORDE, TEXT_OVERLOOK_TAKEN_HORDE, TEXT_STADIUM_TAKEN_HORDE };

OPvPCapturePointHP::OPvPCapturePointHP(OutdoorPvP* pvp, OutdoorPvPHPTowerType type, GameObject* go, ObjectGuid::LowType const& flagSpawnId)
    : OPvPCapturePoint(pvp), m_TowerType(type), m_flagSpawnId(flagSpawnId)
{
    m_capturePointSpawnId = go->GetSpawnId();
    m_capturePoint = go;
    SetCapturePointData(go->GetEntry());
}

OutdoorPvPHP::OutdoorPvPHP(Map* map) : OutdoorPvP(map), m_towerFlagSpawnIds()
{
    m_TypeId = OUTDOOR_PVP_HP;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
}

bool OutdoorPvPHP::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    // add the zones affected by the pvp buff
    for (uint32 i = 0; i < OutdoorPvPHPBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPHPBuffZones[i]);

    return true;
}

void OutdoorPvPHP::OnGameObjectCreate(GameObject* go)
{
    switch (go->GetEntry())
    {
        case 182175:
            AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_BROKEN_HILL, go, m_towerFlagSpawnIds[HP_TOWER_BROKEN_HILL]));
            break;
        case 182174:
            AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_OVERLOOK, go, m_towerFlagSpawnIds[HP_TOWER_OVERLOOK]));
            break;
        case 182173:
            AddCapturePoint(new OPvPCapturePointHP(this, HP_TOWER_STADIUM, go, m_towerFlagSpawnIds[HP_TOWER_STADIUM]));
            break;
        case 183514:
            m_towerFlagSpawnIds[HP_TOWER_BROKEN_HILL] = go->GetSpawnId();
            break;
        case 182525:
            m_towerFlagSpawnIds[HP_TOWER_OVERLOOK] = go->GetSpawnId();
            break;
        case 183515:
            m_towerFlagSpawnIds[HP_TOWER_STADIUM] = go->GetSpawnId();
            break;
        default:
            break;
    }

    OutdoorPvP::OnGameObjectCreate(go);
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
        SetWorldState(HP_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
        SetWorldState(HP_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    }
    return changed;
}

void OutdoorPvPHP::SendRemoveWorldStates(Player* player)
{
    WorldPackets::WorldState::InitWorldStates initWorldStates;
    initWorldStates.MapID = player->GetMapId();
    initWorldStates.AreaID = player->GetZoneId();
    initWorldStates.SubareaID = player->GetAreaId();
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_DISPLAY_A, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_DISPLAY_H, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_COUNT_H, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_COUNT_A, 0);

    for (size_t i = 0; i < HP_TOWER_NUM; ++i)
    {
        initWorldStates.Worldstates.emplace_back(HP_MAP_N[i], 0);
        initWorldStates.Worldstates.emplace_back(HP_MAP_A[i], 0);
        initWorldStates.Worldstates.emplace_back(HP_MAP_H[i], 0);
    }

    player->SendDirectMessage(initWorldStates.Write());
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
        m_PvP->SetWorldState(field, 0);
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

    Map* map = m_PvP->GetMap();
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_flagSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit2);

    // send world state update
    if (field)
        m_PvP->SetWorldState(field, 1);

    // complete quest objective
    if (m_State == OBJECTIVESTATE_ALLIANCE || m_State == OBJECTIVESTATE_HORDE)
        SendObjectiveComplete(HP_CREDITMARKER[m_TowerType], ObjectGuid::Empty);
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

        OutdoorPvP* GetOutdoorPvP(Map* map) const override
        {
            return new OutdoorPvPHP(map);
        }
};

void AddSC_outdoorpvp_hp()
{
    new OutdoorPvP_hellfire_peninsula();
}
