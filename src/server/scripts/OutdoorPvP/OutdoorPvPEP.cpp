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

#include "OutdoorPvPEP.h"
#include "Creature.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "WorldStatePackets.h"

uint32 const EP_AllianceBuffs[4] = { 11413, 11414, 11415, 1386 };
uint32 const EP_HordeBuffs[4] = { 30880, 30683, 30682, 29520 };
uint32 const EP_GraveyardZone = 139;
uint32 const EP_GraveyardId = 927;
uint8 const EPBuffZonesNum = 3;
uint32 const EP_EWT_CM = 17690;
uint32 const EP_CGT_CM = 17689;
uint32 const EP_NPT_CM = 17696;
uint32 const EP_PWT_CM = 17698;
uint32 const EPBuffZones[EPBuffZonesNum] = { 139, 2017, 2057 };
//uint32 const EPTowerPlayerEnterEvents[EP_TOWER_NUM] = { 10691, 10699, 10701, 10705 };
//uint32 const EPTowerPlayerLeaveEvents[EP_TOWER_NUM] = { 10692, 10698, 10700, 10704 };

go_type const EPCapturePoints[EP_TOWER_NUM] =
{
    { 182097, 0, { 2574.51f, -4794.89f, 144.704f, -1.45003f }, { -0.097056f,  0.095578f, -0.656229f,  0.742165f } },
    { 181899, 0, { 3181.08f, -4379.36f, 174.123f, -2.03472f }, { -0.065392f,  0.119494f, -0.842275f,  0.521553f } },
    { 182098, 0, { 2962.71f, -3042.31f, 154.789f,  2.08426f }, { -0.074807f, -0.113837f,  0.855928f,  0.498830f } },
    { 182096, 0, { 1860.85f, -3731.23f, 196.716f, -2.53214f }, {  0.033967f, -0.131914f,  0.944741f, -0.298177f } }
};

go_type const EPTowerFlags[EP_TOWER_NUM] =
{
    { 182106, 0, { 2569.60f, -4772.93f, 115.399f, 2.722710f }, { 0.0f, 0.0f, 0.978148f, 0.207912f } },
    { 182106, 0, { 3148.17f, -4365.51f, 145.029f, 1.535890f }, { 0.0f, 0.0f, 0.694658f, 0.719340f } },
    { 182106, 0, { 2992.63f, -3022.95f, 125.593f, 3.036870f }, { 0.0f, 0.0f, 0.998630f, 0.052336f } },
    { 182106, 0, { 1838.42f, -3703.56f, 167.713f, 0.890118f }, { 0.0f, 0.0f, 0.430511f, 0.902585f } }
};

// uint8 const EP_NUM_CREATURES = 6;
uint8 const EP_EWT_NUM_CREATURES = 5;

// one lordaeron commander, 4 soldiers
// should be spawned at EWT and follow a path, but trans-grid pathing isn't safe, so summon them directly at NPT
creature_type const EP_EWT_Summons_A[EP_EWT_NUM_CREATURES] =
{
    { 17635, 0, { 3167.61f, -4352.09f, 138.20f, 4.5811f } },
    { 17647, 0, { 3172.74f, -4352.99f, 139.14f, 4.9873f } },
    { 17647, 0, { 3165.89f, -4354.46f, 138.67f, 3.7244f } },
    { 17647, 0, { 3164.65f, -4350.26f, 138.22f, 2.4794f } },
    { 17647, 0, { 3169.91f, -4349.68f, 138.37f, 0.7444f } }
};

creature_type const EP_EWT_Summons_H[EP_EWT_NUM_CREATURES] =
{
    { 17995, 0, { 3167.61f, -4352.09f, 138.20f, 4.5811f } },
    { 17996, 0, { 3172.74f, -4352.99f, 139.14f, 4.9873f } },
    { 17996, 0, { 3165.89f, -4354.46f, 138.67f, 3.7244f } },
    { 17996, 0, { 3164.65f, -4350.26f, 138.22f, 2.4794f } },
    { 17996, 0, { 3169.91f, -4349.68f, 138.37f, 0.7444f } }
};

// when spawning, pay attention at setting the faction manually!
creature_type const EP_PWT_FlightMaster = { 17209, 0, { 2987.5f, -3049.11f, 120.126f, 5.75959f } };

// after spawning, modify the faction so that only the controller will be able to use it with SetUInt32Value(GAMEOBJECT_FACTION, faction_id);
go_type const EP_NPT_LordaeronShrine = { 181682, 0, { 3167.72f, -4355.91f, 138.785f, 1.69297f }, { 0.0f, 0.0f, 0.748956f, 0.66262f } };

OPvPCapturePointEP_EWT::OPvPCapturePointEP_EWT(OutdoorPvP* pvp) : OPvPCapturePoint(pvp), m_TowerState(EP_TS_N), m_UnitsSummonedSide(0)
{
    SetCapturePointData(EPCapturePoints[EP_EWT].entry, EPCapturePoints[EP_EWT].map, EPCapturePoints[EP_EWT].pos, EPCapturePoints[EP_EWT].rot);
    AddObject(EP_EWT_FLAGS, EPTowerFlags[EP_EWT].entry, EPTowerFlags[EP_EWT].map, EPTowerFlags[EP_EWT].pos, EPTowerFlags[EP_EWT].rot);
}

void OPvPCapturePointEP_EWT::ChangeState()
{
    // if changing from controlling alliance to horde or vice versa
    if (m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_HORDE)
        ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_EWT, 0);

    uint32 artkit = 21;

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
            m_TowerState = EP_TS_A;
            artkit = 2;
            SummonSupportUnitAtNorthpassTower(ALLIANCE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_EWT, ALLIANCE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_EASTWALL_TOWER_TAKEN_ALLIANCE);
            break;
        case OBJECTIVESTATE_HORDE:
            m_TowerState = EP_TS_H;
            artkit = 1;
            SummonSupportUnitAtNorthpassTower(HORDE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_EWT, HORDE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_EASTWALL_TOWER_TAKEN_HORDE);
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

    Map* map = sMapMgr->FindMap(0, 0);
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[EP_EWT_FLAGS]);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateTowerState();

    // complete quest objective
    if (m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
        SendObjectiveComplete(EP_EWT_CM, ObjectGuid::Empty);
}

void OPvPCapturePointEP_EWT::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(EP_EWT_A, (m_TowerState & EP_TS_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_EWT_H, (m_TowerState & EP_TS_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_EWT_N_A, (m_TowerState & EP_TS_N_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_EWT_N_H, (m_TowerState & EP_TS_N_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_EWT_N, (m_TowerState & EP_TS_N) != 0 ? 1 : 0);
}

void OPvPCapturePointEP_EWT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_EWT_A, (m_TowerState & EP_TS_A) != 0);
    m_PvP->SendUpdateWorldState(EP_EWT_H, (m_TowerState & EP_TS_H) != 0);
    m_PvP->SendUpdateWorldState(EP_EWT_N_A, (m_TowerState & EP_TS_N_A) != 0);
    m_PvP->SendUpdateWorldState(EP_EWT_N_H, (m_TowerState & EP_TS_N_H) != 0);
    m_PvP->SendUpdateWorldState(EP_EWT_N, (m_TowerState & EP_TS_N) != 0);
}

void OPvPCapturePointEP_EWT::SummonSupportUnitAtNorthpassTower(uint32 team)
{
    if (m_UnitsSummonedSide != team)
    {
        m_UnitsSummonedSide = team;
        creature_type const* ct = nullptr;
        if (team == ALLIANCE)
            ct = EP_EWT_Summons_A;
        else
            ct = EP_EWT_Summons_H;

        for (uint8 i = 0; i < EP_EWT_NUM_CREATURES; ++i)
        {
            DelCreature(i);
            AddCreature(i, ct[i].entry, ct[i].map, ct[i].pos, OutdoorPvP::GetTeamIdByTeam(team), 1000000);
        }
    }
}

// NPT
OPvPCapturePointEP_NPT::OPvPCapturePointEP_NPT(OutdoorPvP* pvp)
: OPvPCapturePoint(pvp), m_TowerState(EP_TS_N), m_SummonedGOSide(0)
{
    SetCapturePointData(EPCapturePoints[EP_NPT].entry, EPCapturePoints[EP_NPT].map, EPCapturePoints[EP_NPT].pos, EPCapturePoints[EP_NPT].rot);
    AddObject(EP_NPT_FLAGS, EPTowerFlags[EP_NPT].entry, EPTowerFlags[EP_NPT].map, EPTowerFlags[EP_NPT].pos, EPTowerFlags[EP_NPT].rot);
}

void OPvPCapturePointEP_NPT::ChangeState()
{
    // if changing from controlling alliance to horde or vice versa
    if (m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_HORDE)
        ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_NPT, 0);

    uint32 artkit = 21;

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
            m_TowerState = EP_TS_A;
            artkit = 2;
            SummonGO(ALLIANCE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_NPT, ALLIANCE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_NORTHPASS_TOWER_TAKEN_ALLIANCE);
            break;
        case OBJECTIVESTATE_HORDE:
            m_TowerState = EP_TS_H;
            artkit = 1;
            SummonGO(HORDE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_NPT, HORDE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_NORTHPASS_TOWER_TAKEN_HORDE);
            break;
        case OBJECTIVESTATE_NEUTRAL:
            m_TowerState = EP_TS_N;
            m_SummonedGOSide = 0;
            DelObject(EP_NPT_BUFF);
            break;
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            m_TowerState = EP_TS_N_A;
            break;
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_TowerState = EP_TS_N_A;
            m_SummonedGOSide = 0;
            DelObject(EP_NPT_BUFF);
            break;
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            m_TowerState = EP_TS_N_H;
            break;
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            m_TowerState = EP_TS_N_H;
            m_SummonedGOSide = 0;
            DelObject(EP_NPT_BUFF);
            break;
    }

    Map* map = sMapMgr->FindMap(0, 0);
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[EP_NPT_FLAGS]);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateTowerState();

    // complete quest objective
    if (m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
        SendObjectiveComplete(EP_NPT_CM, ObjectGuid::Empty);
}

void OPvPCapturePointEP_NPT::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(EP_NPT_A, (m_TowerState & EP_TS_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_NPT_H, (m_TowerState & EP_TS_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_NPT_N_A, (m_TowerState & EP_TS_N_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_NPT_N_H, (m_TowerState & EP_TS_N_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_NPT_N, (m_TowerState & EP_TS_N) != 0 ? 1 : 0);
}

void OPvPCapturePointEP_NPT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_NPT_A, (m_TowerState & EP_TS_A) != 0);
    m_PvP->SendUpdateWorldState(EP_NPT_H, (m_TowerState & EP_TS_H) != 0);
    m_PvP->SendUpdateWorldState(EP_NPT_N_A, (m_TowerState & EP_TS_N_A) != 0);
    m_PvP->SendUpdateWorldState(EP_NPT_N_H, (m_TowerState & EP_TS_N_H) != 0);
    m_PvP->SendUpdateWorldState(EP_NPT_N, (m_TowerState & EP_TS_N) != 0);
}

void OPvPCapturePointEP_NPT::SummonGO(uint32 team)
{
    if (m_SummonedGOSide != team)
    {
        m_SummonedGOSide = team;
        DelObject(EP_NPT_BUFF);
        AddObject(EP_NPT_BUFF, EP_NPT_LordaeronShrine.entry, EP_NPT_LordaeronShrine.map, EP_NPT_LordaeronShrine.pos, EP_NPT_LordaeronShrine.rot);

        Map* map = sMapMgr->FindMap(0, 0);
        auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[EP_NPT_BUFF]);
        for (auto itr = bounds.first; itr != bounds.second; ++itr)
            if (GameObject* go = itr->second)
                go->SetFaction(team == ALLIANCE ? FACTION_ALLIANCE_GENERIC : FACTION_HORDE_GENERIC);
    }
}

// CGT
OPvPCapturePointEP_CGT::OPvPCapturePointEP_CGT(OutdoorPvP* pvp)
: OPvPCapturePoint(pvp), m_TowerState(EP_TS_N), m_GraveyardSide(0)
{
    SetCapturePointData(EPCapturePoints[EP_CGT].entry, EPCapturePoints[EP_CGT].map, EPCapturePoints[EP_CGT].pos, EPCapturePoints[EP_CGT].rot);
    AddObject(EP_CGT_FLAGS, EPTowerFlags[EP_CGT].entry, EPTowerFlags[EP_CGT].map, EPTowerFlags[EP_CGT].pos, EPTowerFlags[EP_CGT].rot);
}

void OPvPCapturePointEP_CGT::ChangeState()
{
    // if changing from controlling alliance to horde or vice versa
    if (m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_HORDE)
        ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_CGT, 0);

    uint32 artkit = 21;

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
            m_TowerState = EP_TS_A;
            artkit = 2;
            LinkGraveyard(ALLIANCE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_CGT, ALLIANCE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_CROWN_GUARD_TOWER_TAKEN_ALLIANCE);
            break;
        case OBJECTIVESTATE_HORDE:
            m_TowerState = EP_TS_H;
            artkit = 1;
            LinkGraveyard(HORDE);
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_CGT, HORDE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_CROWN_GUARD_TOWER_TAKEN_HORDE);
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

    Map* map = sMapMgr->FindMap(0, 0);
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[EP_CGT_FLAGS]);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateTowerState();

    // complete quest objective
    if (m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
        SendObjectiveComplete(EP_CGT_CM, ObjectGuid::Empty);
}

void OPvPCapturePointEP_CGT::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(EP_CGT_A, (m_TowerState & EP_TS_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_CGT_H, (m_TowerState & EP_TS_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_CGT_N_A, (m_TowerState & EP_TS_N_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_CGT_N_H, (m_TowerState & EP_TS_N_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_CGT_N, (m_TowerState & EP_TS_N) != 0 ? 1 : 0);
}

void OPvPCapturePointEP_CGT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_CGT_A, (m_TowerState & EP_TS_A) != 0);
    m_PvP->SendUpdateWorldState(EP_CGT_H, (m_TowerState & EP_TS_H) != 0);
    m_PvP->SendUpdateWorldState(EP_CGT_N_A, (m_TowerState & EP_TS_N_A) != 0);
    m_PvP->SendUpdateWorldState(EP_CGT_N_H, (m_TowerState & EP_TS_N_H) != 0);
    m_PvP->SendUpdateWorldState(EP_CGT_N, (m_TowerState & EP_TS_N) != 0);
}

void OPvPCapturePointEP_CGT::LinkGraveyard(uint32 team)
{
    if (m_GraveyardSide != team)
    {
        m_GraveyardSide = team;
        sObjectMgr->RemoveGraveyardLink(EP_GraveyardId, EP_GraveyardZone, team, false);
        sObjectMgr->AddGraveyardLink(EP_GraveyardId, EP_GraveyardZone, team, false);
    }
}

// PWT
OPvPCapturePointEP_PWT::OPvPCapturePointEP_PWT(OutdoorPvP* pvp)
: OPvPCapturePoint(pvp), m_FlightMasterSpawned(0), m_TowerState(EP_TS_N)
{
    SetCapturePointData(EPCapturePoints[EP_PWT].entry, EPCapturePoints[EP_PWT].map, EPCapturePoints[EP_PWT].pos, EPCapturePoints[EP_PWT].rot);
    AddObject(EP_PWT_FLAGS, EPTowerFlags[EP_PWT].entry, EPTowerFlags[EP_PWT].map, EPTowerFlags[EP_PWT].pos, EPTowerFlags[EP_PWT].rot);
}

void OPvPCapturePointEP_PWT::ChangeState()
{
    // if changing from controlling alliance to horde or vice versa
    if ( m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_HORDE)
        ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_PWT, 0);

    uint32 artkit = 21;

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
            m_TowerState = EP_TS_A;
            SummonFlightMaster(ALLIANCE);
            artkit = 2;
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_PWT, ALLIANCE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_PLAGUEWOOD_TOWER_TAKEN_ALLIANCE);
            break;
        case OBJECTIVESTATE_HORDE:
            m_TowerState = EP_TS_H;
            SummonFlightMaster(HORDE);
            artkit = 1;
            ((OutdoorPvPEP*)m_PvP)->SetControlledState(EP_PWT, HORDE);
            m_PvP->SendDefenseMessage(EP_GraveyardZone, TEXT_PLAGUEWOOD_TOWER_TAKEN_HORDE);
            break;
        case OBJECTIVESTATE_NEUTRAL:
            m_TowerState = EP_TS_N;
            DelCreature(EP_PWT_FLIGHTMASTER);
            m_FlightMasterSpawned = 0;
            break;
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            m_TowerState = EP_TS_N_A;
            break;
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_TowerState = EP_TS_N_A;
            DelCreature(EP_PWT_FLIGHTMASTER);
            m_FlightMasterSpawned = 0;
            break;
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            m_TowerState = EP_TS_N_H;
            break;
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            m_TowerState = EP_TS_N_H;
            DelCreature(EP_PWT_FLIGHTMASTER);
            m_FlightMasterSpawned = 0;
            break;
    }

    Map* map = sMapMgr->FindMap(0, 0);
    auto bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    bounds = map->GetGameObjectBySpawnIdStore().equal_range(m_Objects[EP_PWT_FLAGS]);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateTowerState();

    // complete quest objective
    if (m_TowerState == EP_TS_A || m_TowerState == EP_TS_H)
        SendObjectiveComplete(EP_PWT_CM, ObjectGuid::Empty);
}

void OPvPCapturePointEP_PWT::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(EP_PWT_A, (m_TowerState & EP_TS_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_PWT_H, (m_TowerState & EP_TS_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_PWT_N_A, (m_TowerState & EP_TS_N_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_PWT_N_H, (m_TowerState & EP_TS_N_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(EP_PWT_N, (m_TowerState & EP_TS_N) != 0 ? 1 : 0);
}

void OPvPCapturePointEP_PWT::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(EP_PWT_A, (m_TowerState & EP_TS_A) != 0);
    m_PvP->SendUpdateWorldState(EP_PWT_H, (m_TowerState & EP_TS_H) != 0);
    m_PvP->SendUpdateWorldState(EP_PWT_N_A, (m_TowerState & EP_TS_N_A) != 0);
    m_PvP->SendUpdateWorldState(EP_PWT_N_H, (m_TowerState & EP_TS_N_H) != 0);
    m_PvP->SendUpdateWorldState(EP_PWT_N, (m_TowerState & EP_TS_N) != 0);
}

void OPvPCapturePointEP_PWT::SummonFlightMaster(uint32 team)
{
    if (m_FlightMasterSpawned != team)
    {
        m_FlightMasterSpawned = team;
        DelCreature(EP_PWT_FLIGHTMASTER);
        AddCreature(EP_PWT_FLIGHTMASTER, EP_PWT_FlightMaster.entry, EP_PWT_FlightMaster.map, EP_PWT_FlightMaster.pos, OutdoorPvP::GetTeamIdByTeam(team));
        /*
        // sky - we need update gso code

        Creature* c = HashMapHolder<Creature>::Find(m_Creatures[EP_PWT_FLIGHTMASTER]);
        //Spawn flight master as friendly to capturing team
        c->SetUInt32Value(GAMEOBJECT_FACTION, (team == ALLIANCE ? 55 : 68));
        if (c)
        {
            GossipOption gso;
            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_NPT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            gso.BoxMoney = 0;
            gso.Coded = false;
            c->addGossipOption(gso);

            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_EWT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            gso.BoxMoney = 0;
            gso.Coded = false;
            c->addGossipOption(gso);

            gso.Action = GOSSIP_OPTION_OUTDOORPVP;
            gso.GossipId = 0;
            gso.OptionText.assign(sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_EP_FLIGHT_CGT));
            gso.Id = 50;
            gso.Icon = 0;
            gso.NpcFlag = 0;
            gso.BoxMoney = 0;
            gso.Coded = false;
            c->addGossipOption(gso);
        }
        */
    }
}

// ep
OutdoorPvPEP::OutdoorPvPEP()
{
    m_TypeId = OUTDOOR_PVP_EP;
    memset(EP_Controls, 0, sizeof(EP_Controls));
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
}

bool OutdoorPvPEP::SetupOutdoorPvP()
{
    for (uint8 i = 0; i < EPBuffZonesNum; ++i)
        RegisterZone(EPBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointEP_EWT(this));
    AddCapturePoint(new OPvPCapturePointEP_PWT(this));
    AddCapturePoint(new OPvPCapturePointEP_CGT(this));
    AddCapturePoint(new OPvPCapturePointEP_NPT(this));
    SetMapFromZone(EPBuffZones[0]);
    return true;
}

bool OutdoorPvPEP::Update(uint32 diff)
{
    if (OutdoorPvP::Update(diff))
    {
        m_AllianceTowersControlled = 0;
        m_HordeTowersControlled = 0;
        for (int i = 0; i < EP_TOWER_NUM; ++i)
        {
            if (EP_Controls[i] == ALLIANCE)
                ++m_AllianceTowersControlled;
            else if (EP_Controls[i] == HORDE)
                ++m_HordeTowersControlled;
            SendUpdateWorldState(EP_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
            SendUpdateWorldState(EP_UI_TOWER_COUNT_H, m_HordeTowersControlled);
            BuffTeams();
        }
        return true;
    }
    return false;
}

void OutdoorPvPEP::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    // add buffs
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled && m_AllianceTowersControlled < 5)
            player->CastSpell(player, EP_AllianceBuffs[m_AllianceTowersControlled-1], true);
    }
    else
    {
        if (m_HordeTowersControlled && m_HordeTowersControlled < 5)
            player->CastSpell(player, EP_HordeBuffs[m_HordeTowersControlled-1], true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPEP::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    if (player->GetTeam() == ALLIANCE)
    {
        for (int i = 0; i < 4; ++i)
            player->RemoveAurasDueToSpell(EP_AllianceBuffs[i]);
    }
    else
    {
        for (int i = 0; i < 4; ++i)
            player->RemoveAurasDueToSpell(EP_HordeBuffs[i]);
    }
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
}

void OutdoorPvPEP::BuffTeams()
{
    for (GuidSet::iterator itr = m_players[0].begin(); itr != m_players[0].end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer(*itr))
        {
            for (int i = 0; i < 4; ++i)
                player->RemoveAurasDueToSpell(EP_AllianceBuffs[i]);
            if (m_AllianceTowersControlled && m_AllianceTowersControlled < 5)
                player->CastSpell(player, EP_AllianceBuffs[m_AllianceTowersControlled-1], true);
        }
    }
    for (GuidSet::iterator itr = m_players[1].begin(); itr != m_players[1].end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer(*itr))
        {
            for (int i = 0; i < 4; ++i)
                player->RemoveAurasDueToSpell(EP_HordeBuffs[i]);
            if (m_HordeTowersControlled && m_HordeTowersControlled < 5)
                player->CastSpell(player, EP_HordeBuffs[m_HordeTowersControlled-1], true);
        }
    }
}

void OutdoorPvPEP::SetControlledState(uint32 index, uint32 state)
{
    EP_Controls[index] = state;
}

void OutdoorPvPEP::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(EP_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
    packet.Worldstates.emplace_back(EP_UI_TOWER_COUNT_H, m_HordeTowersControlled);

    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(packet);
}

void OutdoorPvPEP::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(EP_UI_TOWER_COUNT_A, 0);
    player->SendUpdateWorldState(EP_UI_TOWER_COUNT_H, 0);

    player->SendUpdateWorldState(EP_EWT_A, 0);
    player->SendUpdateWorldState(EP_EWT_H, 0);
    player->SendUpdateWorldState(EP_EWT_N, 0);
    player->SendUpdateWorldState(EP_EWT_N_A, 0);
    player->SendUpdateWorldState(EP_EWT_N_H, 0);

    player->SendUpdateWorldState(EP_PWT_A, 0);
    player->SendUpdateWorldState(EP_PWT_H, 0);
    player->SendUpdateWorldState(EP_PWT_N, 0);
    player->SendUpdateWorldState(EP_PWT_N_A, 0);
    player->SendUpdateWorldState(EP_PWT_N_H, 0);

    player->SendUpdateWorldState(EP_NPT_A, 0);
    player->SendUpdateWorldState(EP_NPT_H, 0);
    player->SendUpdateWorldState(EP_NPT_N, 0);
    player->SendUpdateWorldState(EP_NPT_N_A, 0);
    player->SendUpdateWorldState(EP_NPT_N_H, 0);

    player->SendUpdateWorldState(EP_CGT_A, 0);
    player->SendUpdateWorldState(EP_CGT_H, 0);
    player->SendUpdateWorldState(EP_CGT_N, 0);
    player->SendUpdateWorldState(EP_CGT_N_A, 0);
    player->SendUpdateWorldState(EP_CGT_N_H, 0);
}

class OutdoorPvP_eastern_plaguelands : public OutdoorPvPScript
{
    public:
        OutdoorPvP_eastern_plaguelands() : OutdoorPvPScript("outdoorpvp_ep") { }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPEP();
        }
};

void AddSC_outdoorpvp_ep()
{
    new OutdoorPvP_eastern_plaguelands();
}
