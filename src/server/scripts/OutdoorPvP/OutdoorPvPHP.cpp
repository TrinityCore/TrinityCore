/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Map.h"
#include "OutdoorPvPHP.h"
#include "OutdoorPvPMgr.h"
#include "Player.h"
#include "WorldPacket.h"

uint32 const OutdoorPvPHPBuffZonesNum = 6;
                                                         //  HP, citadel, ramparts, blood furnace, shattered halls, mag's lair
uint32 const OutdoorPvPHPBuffZones[OutdoorPvPHPBuffZonesNum] = { 3483, 3563, 3562, 3713, 3714, 3836 };

uint32 const HP_CREDITMARKER[HP_TOWER_NUM] = { 19032, 19028, 19029 };

/*
uint32 const HP_CapturePointEvent_Enter[HP_TOWER_NUM] = { 11404, 11396, 11388 };
uint32 const HP_CapturePointEvent_Leave[HP_TOWER_NUM] = { 11403, 11395, 11387 };
*/

uint32 const HP_MAP_N[HP_TOWER_NUM] = { 0x9b5, 0x9b2, 0x9a8 };
uint32 const HP_MAP_A[HP_TOWER_NUM] = { 0x9b3, 0x9b0, 0x9a7 };
uint32 const HP_MAP_H[HP_TOWER_NUM] = { 0x9b4, 0x9b1, 0x9a6 };

uint32 const HP_TowerArtKit_A[HP_TOWER_NUM] = { 65, 62, 67 };
uint32 const HP_TowerArtKit_H[HP_TOWER_NUM] = { 64, 61, 68 };
uint32 const HP_TowerArtKit_N[HP_TOWER_NUM] = { 66, 63, 69 };

go_type const HPCapturePoints[HP_TOWER_NUM] =
{
    { 182175, 530, { -471.462f, 3451.09f, 34.6432f,  0.174533f }, { 0.0f, 0.0f, 0.087156f,  0.996195f } },  // 0 - Broken Hill
    { 182174, 530, { -184.889f, 3476.93f, 38.2050f, -0.017453f }, { 0.0f, 0.0f, 0.008727f, -0.999962f } },  // 1 - Overlook
    { 182173, 530, { -290.016f, 3702.42f, 56.6729f,  0.034907f }, { 0.0f, 0.0f, 0.017452f,  0.999848f } }   // 2 - Stadium
};

go_type const HPTowerFlags[HP_TOWER_NUM] =
{
    { 183514, 530, { -467.078f, 3528.17f, 64.7121f,  3.14159f }, { 0.0f, 0.0f, 1.000000f,  0.000000f } },   // 0 broken hill
    { 182525, 530, { -187.887f, 3459.38f, 60.0403f, -3.12414f }, { 0.0f, 0.0f, 0.999962f, -0.008727f } },   // 1 overlook
    { 183515, 530, { -289.610f, 3696.83f, 75.9447f,  3.12414f }, { 0.0f, 0.0f, 0.999962f,  0.008727f } }    // 2 stadium
};

uint32 const HP_LANG_CAPTURE_A[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_ALLIANCE, TEXT_OVERLOOK_TAKEN_ALLIANCE, TEXT_STADIUM_TAKEN_ALLIANCE };
uint32 const HP_LANG_CAPTURE_H[HP_TOWER_NUM] = { TEXT_BROKEN_HILL_TAKEN_HORDE, TEXT_OVERLOOK_TAKEN_HORDE, TEXT_STADIUM_TAKEN_HORDE };

OPvPCapturePointHP::OPvPCapturePointHP(OutdoorPvP* pvp, OutdoorPvPHPTowerType type)
: OPvPCapturePoint(pvp), m_TowerType(type)
{
    SetCapturePointData(HPCapturePoints[type].entry, HPCapturePoints[type].map, HPCapturePoints[type].pos, HPCapturePoints[type].rot);
    AddObject(type, HPTowerFlags[type].entry, HPTowerFlags[type].map, HPTowerFlags[type].pos, HPTowerFlags[type].rot);
}

OutdoorPvPHP::OutdoorPvPHP()
{
    m_TypeId = OUTDOOR_PVP_HP;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    SetMapFromZone(OutdoorPvPHPBuffZones[0]);
}

bool OutdoorPvPHP::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    // add the zones affected by the pvp buff
    for (uint32 i = 0; i < OutdoorPvPHPBuffZonesNum; ++i)
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

void OutdoorPvPHP::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(HP_UI_TOWER_DISPLAY_A) << uint32(1);
    data << uint32(HP_UI_TOWER_DISPLAY_H) << uint32(1);
    data << uint32(HP_UI_TOWER_COUNT_A) << uint32(m_AllianceTowersControlled);
    data << uint32(HP_UI_TOWER_COUNT_H) << uint32(m_HordeTowersControlled);

    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(data);
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

    Map* map = m_PvP->GetMap();
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

void OPvPCapturePointHP::FillInitialWorldStates(WorldPacket &data)
{
    switch (m_State)
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
