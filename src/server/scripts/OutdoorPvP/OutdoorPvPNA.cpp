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

#include "OutdoorPvPNA.h"
#include "CellImpl.h"
#include "Creature.h"
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldStatePackets.h"

uint32 const NA_CREDIT_MARKER = 24867; // kill credit for pks
uint32 const NA_GUARDS_MAX = 15;
uint32 const NA_BUFF_ZONE = 3518;
uint32 const NA_HALAA_GRAVEYARD = 993;
uint32 const NA_HALAA_GRAVEYARD_ZONE = 3518; // need to add zone id, not area id
uint32 const NA_RESPAWN_TIME = 3600000; // one hour to capture after defeating all guards
uint32 const NA_GUARD_CHECK_TIME = 500; // every half second
uint32 const FLIGHT_NODES_NUM = 4;
uint32 const FlightPathStartNodes[FLIGHT_NODES_NUM] = { 103, 105, 107, 109 };
uint32 const FlightPathEndNodes[FLIGHT_NODES_NUM] = { 104, 106, 108, 110 };

OutdoorPvPNA::OutdoorPvPNA(Map* map) : OutdoorPvP(map)
{
    m_TypeId = OUTDOOR_PVP_NA;
    m_obj = nullptr;
}

void OutdoorPvPNA::OnGameObjectCreate(GameObject* go)
{
    switch (go->GetEntry())
    {
        case 182210:
            m_obj->m_capturePointSpawnId = go->GetSpawnId();
            AddCapturePoint(m_obj);
            break;
    }

    OutdoorPvP::OnGameObjectCreate(go);
}

void OutdoorPvPNA::HandleKillImpl(Player* player, Unit* killed)
{
    if (killed->GetTypeId() == TYPEID_PLAYER && player->GetTeam() != killed->ToPlayer()->GetTeam())
    {
        player->KilledMonsterCredit(NA_CREDIT_MARKER); // 0 guid, btw it isn't even used in killedmonster function :S
        if (player->GetTeam() == ALLIANCE)
            player->CastSpell(player, NA_KILL_TOKEN_ALLIANCE, true);
        else
            player->CastSpell(player, NA_KILL_TOKEN_HORDE, true);
    }
}

uint32 OPvPCapturePointNA::GetAliveGuardsCount() const
{
    Position searchCenter = { -1572.57f, 7945.3f, -22.475f, 2.05949f };

    std::vector<WorldObject*> guards;
    Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck check(ObjectGuid::Empty, GetControllingFaction() == HORDE ? 18192 : 18256);
    Trinity::WorldObjectListSearcher<Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck> searcher(nullptr, guards, check, GRID_MAP_TYPE_MASK_CREATURE);
    Cell::VisitGridObjects(searchCenter.GetPositionX(), searchCenter.GetPositionY(), m_PvP->GetMap(), searcher, SIZE_OF_GRIDS);

    return std::count_if(guards.begin(), guards.end(), [](WorldObject* guard) { return guard->IsUnit() && guard->ToUnit()->IsAlive(); });
}

uint32 OPvPCapturePointNA::GetControllingFaction() const
{
    return m_ControllingFaction;
}

void OPvPCapturePointNA::FactionTakeOver(uint32 team)
{
    if (m_ControllingFaction)
        sObjectMgr->RemoveGraveyardLink(NA_HALAA_GRAVEYARD, NA_HALAA_GRAVEYARD_ZONE, m_ControllingFaction, false);

    m_ControllingFaction = team;
    if (m_ControllingFaction)
        sObjectMgr->AddGraveyardLink(NA_HALAA_GRAVEYARD, NA_HALAA_GRAVEYARD_ZONE, m_ControllingFaction, false);

    m_GuardsAlive = NA_GUARDS_MAX;
    m_capturable = false;
    UpdateHalaaWorldState();
    if (team == ALLIANCE)
    {
        m_WyvernStateSouth = WYVERN_NEU_HORDE;
        m_WyvernStateNorth = WYVERN_NEU_HORDE;
        m_WyvernStateEast = WYVERN_NEU_HORDE;
        m_WyvernStateWest = WYVERN_NEU_HORDE;
        m_PvP->TeamApplyBuff(TEAM_ALLIANCE, NA_CAPTURE_BUFF);
        m_PvP->SetWorldState(NA_UI_HORDE_GUARDS_SHOW, 0);
        m_PvP->SetWorldState(NA_UI_ALLIANCE_GUARDS_SHOW, 1);
        m_PvP->SetWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
        m_PvP->SendDefenseMessage(NA_HALAA_GRAVEYARD_ZONE, TEXT_HALAA_TAKEN_ALLIANCE);
    }
    else
    {
        m_WyvernStateSouth = WYVERN_NEU_ALLIANCE;
        m_WyvernStateNorth = WYVERN_NEU_ALLIANCE;
        m_WyvernStateEast = WYVERN_NEU_ALLIANCE;
        m_WyvernStateWest = WYVERN_NEU_ALLIANCE;
        m_PvP->TeamApplyBuff(TEAM_HORDE, NA_CAPTURE_BUFF);
        m_PvP->SetWorldState(NA_UI_HORDE_GUARDS_SHOW, 1);
        m_PvP->SetWorldState(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
        m_PvP->SetWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
        m_PvP->SendDefenseMessage(NA_HALAA_GRAVEYARD_ZONE, TEXT_HALAA_TAKEN_HORDE);
    }
    UpdateWyvernRoostWorldState(NA_ROOST_S);
    UpdateWyvernRoostWorldState(NA_ROOST_N);
    UpdateWyvernRoostWorldState(NA_ROOST_W);
    UpdateWyvernRoostWorldState(NA_ROOST_E);
}

OPvPCapturePointNA::OPvPCapturePointNA(OutdoorPvP* pvp) : OPvPCapturePoint(pvp), m_capturable(true), m_GuardsAlive(0), m_ControllingFaction(0), m_WyvernStateNorth(0), m_WyvernStateSouth(0), m_WyvernStateEast(0),
    m_WyvernStateWest(0), m_HalaaState(HALAA_N), m_RespawnTimer(NA_RESPAWN_TIME), m_GuardCheckTimer(NA_GUARD_CHECK_TIME)
{
    SetCapturePointData(182210);
}

bool OutdoorPvPNA::SetupOutdoorPvP()
{
//    m_TypeId = OUTDOOR_PVP_NA; _MUST_ be set in ctor, because of spawns cleanup
    // add the zones affected by the pvp buff
    RegisterZone(NA_BUFF_ZONE);

    // halaa
    m_obj = new OPvPCapturePointNA(this);

    return true;
}

void OutdoorPvPNA::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    // add buffs
    if (player->GetTeam() == m_obj->GetControllingFaction())
        player->CastSpell(player, NA_CAPTURE_BUFF, true);
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPNA::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    player->RemoveAurasDueToSpell(NA_CAPTURE_BUFF);
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
}

void OutdoorPvPNA::SendRemoveWorldStates(Player* player)
{
    WorldPackets::WorldState::InitWorldStates initWorldStates;
    initWorldStates.MapID = player->GetMapId();
    initWorldStates.AreaID = player->GetZoneId();
    initWorldStates.SubareaID = player->GetAreaId();
    initWorldStates.Worldstates.emplace_back(NA_UI_HORDE_GUARDS_SHOW, 0);
    initWorldStates.Worldstates.emplace_back(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
    initWorldStates.Worldstates.emplace_back(NA_UI_GUARDS_MAX, 0);
    initWorldStates.Worldstates.emplace_back(NA_UI_GUARDS_LEFT, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_NEU_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_NEU_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_NEU_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_NEU_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_NEU_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_NEU_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_NEU_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_NEU_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_HALAA_NEUTRAL, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_HALAA_NEU_A, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_HALAA_NEU_H, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_HALAA_HORDE, 0);
    initWorldStates.Worldstates.emplace_back(NA_MAP_HALAA_ALLIANCE, 0);
    player->SendDirectMessage(initWorldStates.Write());
}

bool OutdoorPvPNA::Update(uint32 diff)
{
    return m_obj->Update(diff);
}

bool OPvPCapturePointNA::HandleCustomSpell(Player* player, uint32 spellId, GameObject* /*go*/)
{
    std::vector<uint32> nodes;
    nodes.resize(2);
    bool retval = false;
    switch (spellId)
    {
    case NA_SPELL_FLY_NORTH:
        nodes[0] = FlightPathStartNodes[NA_ROOST_N];
        nodes[1] = FlightPathEndNodes[NA_ROOST_N];
        player->ActivateTaxiPathTo(nodes);
        player->SetPlayerFlag(PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_SOUTH:
        nodes[0] = FlightPathStartNodes[NA_ROOST_S];
        nodes[1] = FlightPathEndNodes[NA_ROOST_S];
        player->ActivateTaxiPathTo(nodes);
        player->SetPlayerFlag(PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_WEST:
        nodes[0] = FlightPathStartNodes[NA_ROOST_W];
        nodes[1] = FlightPathEndNodes[NA_ROOST_W];
        player->ActivateTaxiPathTo(nodes);
        player->SetPlayerFlag(PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_EAST:
        nodes[0] = FlightPathStartNodes[NA_ROOST_E];
        nodes[1] = FlightPathEndNodes[NA_ROOST_E];
        player->ActivateTaxiPathTo(nodes);
        player->SetPlayerFlag(PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    default:
        break;
    }

    if (retval)
    {
        //Adding items
        uint32 noSpaceForCount = 0;

        // check space and find places
        ItemPosCountVec dest;

        int32 count = 10;
        uint32 itemid = 24538;
                                                                // bomb id count
        InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemid, count, &noSpaceForCount);
        if (msg != EQUIP_ERR_OK)                               // convert to possible store amount
            count -= noSpaceForCount;

        if (count == 0 || dest.empty())                         // can't add any
        {
            return true;
        }

        Item* item = player->StoreNewItem(dest, itemid, true);

        if (count > 0 && item)
        {
            player->SendNewItem(item, count, true, false);
        }

        return true;
    }
    return false;
}

int32 OPvPCapturePointNA::HandleOpenGo(Player* player, GameObject* go)
{
    switch (go->GetEntry())
    {
        case 182222:
            m_WyvernStateSouth = WYVERN_NEU_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_S);
            break;
        case 182272:
            m_WyvernStateWest = WYVERN_NEU_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_W);
            break;
        case 182273:
            m_WyvernStateNorth = WYVERN_NEU_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_N);
            break;
        case 182274:
            m_WyvernStateEast = WYVERN_NEU_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_E);
            break;
        case 182266:
            m_WyvernStateSouth = WYVERN_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_S);
            break;
        case 182275:
            m_WyvernStateWest = WYVERN_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_W);
            break;
        case 182276:
            m_WyvernStateNorth = WYVERN_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_N);
            break;
        case 182277:
            m_WyvernStateEast = WYVERN_ALLIANCE;
            UpdateWyvernRoostWorldState(NA_ROOST_E);
            break;
        case 182305:
            m_WyvernStateSouth = WYVERN_NEU_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_S);
            break;
        case 182306:
            m_WyvernStateWest = WYVERN_NEU_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_W);
            break;
        case 182307:
            m_WyvernStateNorth = WYVERN_NEU_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_N);
            break;
        case 182308:
            m_WyvernStateEast = WYVERN_NEU_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_E);
            break;
        case 182297:
            m_WyvernStateSouth = WYVERN_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_S);
            break;
        case 182298:
            m_WyvernStateWest = WYVERN_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_W);
            break;
        case 182299:
            m_WyvernStateNorth = WYVERN_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_N);
            break;
        case 182300:
            m_WyvernStateEast = WYVERN_HORDE;
            UpdateWyvernRoostWorldState(NA_ROOST_E);
            break;
        default:
            return OPvPCapturePoint::HandleOpenGo(player, go);
    }

    return 0;
}

bool OPvPCapturePointNA::Update(uint32 diff)
{
    // let the controlling faction advance in phase
    bool capturable = false;
    if (m_ControllingFaction == ALLIANCE && m_activePlayers[0].size() > m_activePlayers[1].size())
        capturable = true;
    else if (m_ControllingFaction == HORDE && m_activePlayers[0].size() < m_activePlayers[1].size())
        capturable = true;

    if (m_GuardCheckTimer < diff)
    {
        m_GuardCheckTimer = NA_GUARD_CHECK_TIME;
        m_GuardsAlive = GetAliveGuardsCount();
        if (m_GuardsAlive == 0)
        {
            m_capturable = true;
            m_RespawnTimer = NA_RESPAWN_TIME;
        }
        // update the guard count for the players in zone
        m_PvP->SetWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
    }
    else
        m_GuardCheckTimer -= diff;

    if (m_capturable)
    {
        if (m_RespawnTimer < diff)
        {
            // if the guards have been killed, then the challenger has one hour to take over halaa.
            // in case they fail to do it, the guards are respawned, and they have to start again.
            if (m_ControllingFaction)
            {
                FactionTakeOver(m_ControllingFaction);
                m_PvP->GetMap()->SpawnGroupSpawn(m_ControllingFaction == HORDE ? SPAWN_GROUP_HORDE_GUARDS : SPAWN_GROUP_ALLIANCE_GUARDS, true);
            }
        }
        else
            m_RespawnTimer -= diff;
    }

    if (m_capturable || capturable)
        return OPvPCapturePoint::Update(diff);

    return false;
}

void OPvPCapturePointNA::ChangeState()
{
    uint32 artkit = 21;
    switch (m_State)
    {
        case OBJECTIVESTATE_NEUTRAL:
            m_HalaaState = HALAA_N;
            break;
        case OBJECTIVESTATE_ALLIANCE:
            m_HalaaState = HALAA_A;
            FactionTakeOver(ALLIANCE);
            artkit = 2;
            break;
        case OBJECTIVESTATE_HORDE:
            m_HalaaState = HALAA_H;
            FactionTakeOver(HORDE);
            artkit = 1;
            break;
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            m_HalaaState = HALAA_N_A;
            break;
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            m_HalaaState = HALAA_N_H;
            break;
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            m_HalaaState = HALAA_N_A;
            artkit = 2;
            break;
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_HalaaState = HALAA_N_H;
            artkit = 1;
        break;
    }

    auto bounds = m_PvP->GetMap()->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateHalaaWorldState();
}

void OPvPCapturePointNA::UpdateHalaaWorldState()
{
    m_PvP->SetWorldState(NA_MAP_HALAA_NEUTRAL, uint32((m_HalaaState & HALAA_N) != 0));
    m_PvP->SetWorldState(NA_MAP_HALAA_NEU_A, uint32((m_HalaaState & HALAA_N_A) != 0));
    m_PvP->SetWorldState(NA_MAP_HALAA_NEU_H, uint32((m_HalaaState & HALAA_N_H) != 0));
    m_PvP->SetWorldState(NA_MAP_HALAA_HORDE, uint32((m_HalaaState & HALAA_H) != 0));
    m_PvP->SetWorldState(NA_MAP_HALAA_ALLIANCE, uint32((m_HalaaState & HALAA_A) != 0));
}

void OPvPCapturePointNA::UpdateWyvernRoostWorldState(uint32 roost)
{
    switch (roost)
    {
        case NA_ROOST_S:
            m_PvP->SetWorldState(NA_MAP_WYVERN_SOUTH_NEU_H, uint32((m_WyvernStateSouth & WYVERN_NEU_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_SOUTH_NEU_A, uint32((m_WyvernStateSouth & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_SOUTH_H, uint32((m_WyvernStateSouth & WYVERN_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_SOUTH_A, uint32((m_WyvernStateSouth & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_N:
            m_PvP->SetWorldState(NA_MAP_WYVERN_NORTH_NEU_H, uint32((m_WyvernStateNorth & WYVERN_NEU_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_NORTH_NEU_A, uint32((m_WyvernStateNorth & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_NORTH_H, uint32((m_WyvernStateNorth & WYVERN_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_NORTH_A, uint32((m_WyvernStateNorth & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_W:
            m_PvP->SetWorldState(NA_MAP_WYVERN_WEST_NEU_H, uint32((m_WyvernStateWest & WYVERN_NEU_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_WEST_NEU_A, uint32((m_WyvernStateWest & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_WEST_H, uint32((m_WyvernStateWest & WYVERN_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_WEST_A, uint32((m_WyvernStateWest & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_E:
            m_PvP->SetWorldState(NA_MAP_WYVERN_EAST_NEU_H, uint32((m_WyvernStateEast & WYVERN_NEU_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_EAST_NEU_A, uint32((m_WyvernStateEast & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_EAST_H, uint32((m_WyvernStateEast & WYVERN_HORDE) != 0));
            m_PvP->SetWorldState(NA_MAP_WYVERN_EAST_A, uint32((m_WyvernStateEast & WYVERN_ALLIANCE) != 0));
            break;
    }
}

class OutdoorPvP_nagrand : public OutdoorPvPScript
{
    public:
        OutdoorPvP_nagrand() : OutdoorPvPScript("outdoorpvp_na") { }

        OutdoorPvP* GetOutdoorPvP(Map* map) const override
        {
            return new OutdoorPvPNA(map);
        }
};

void AddSC_outdoorpvp_na()
{
    new OutdoorPvP_nagrand();
}
