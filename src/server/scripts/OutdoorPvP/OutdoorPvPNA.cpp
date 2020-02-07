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
#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
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

// spawned when the alliance is attacking, horde is in control
go_type const HordeControlGOs[NA_CONTROL_GO_NUM] =
{
    { 182267, 530, { -1815.8000f, 8036.5100f, -26.2354f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //ALLY_ROOST_SOUTH
    { 182280, 530, { -1507.9500f, 8132.1000f, -19.5585f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //ALLY_ROOST_WEST
    { 182281, 530, { -1384.5200f, 7779.3300f, -11.1663f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //ALLY_ROOST_NORTH
    { 182282, 530, { -1650.1100f, 7732.5600f, -15.4505f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }, //ALLY_ROOST_EAST

    { 182222, 530, { -1825.4022f, 8039.2602f, -26.0800f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //HORDE_BOMB_WAGON_SOUTH
    { 182272, 530, { -1515.3700f, 8136.9100f, -20.4200f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //HORDE_BOMB_WAGON_WEST
    { 182273, 530, { -1377.9500f, 7773.4400f, -10.3100f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //HORDE_BOMB_WAGON_NORTH
    { 182274, 530, { -1659.8700f, 7733.1500f, -15.7500f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }, //HORDE_BOMB_WAGON_EAST

    { 182266, 530, { -1815.8000f, 8036.5100f, -26.2354f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //DESTROYED_ALLY_ROOST_SOUTH
    { 182275, 530, { -1507.9500f, 8132.1000f, -19.5585f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //DESTROYED_ALLY_ROOST_WEST
    { 182276, 530, { -1384.5200f, 7779.3300f, -11.1663f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //DESTROYED_ALLY_ROOST_NORTH
    { 182277, 530, { -1650.1100f, 7732.5600f, -15.4505f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }  //DESTROYED_ALLY_ROOST_EAST
};

// spawned when the horde is attacking, alliance is in control
go_type const AllianceControlGOs[NA_CONTROL_GO_NUM] =
{
    { 182301, 530, { -1815.8000f, 8036.5100f, -26.2354f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //HORDE_ROOST_SOUTH
    { 182302, 530, { -1507.9500f, 8132.1000f, -19.5585f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //HORDE_ROOST_WEST
    { 182303, 530, { -1384.5200f, 7779.3300f, -11.1663f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //HORDE_ROOST_NORTH
    { 182304, 530, { -1650.1100f, 7732.5600f, -15.4505f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }, //HORDE_ROOST_EAST

    { 182305, 530, { -1825.4022f, 8039.2602f, -26.0800f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //ALLY_BOMB_WAGON_SOUTH
    { 182306, 530, { -1515.3700f, 8136.9100f, -20.4200f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //ALLY_BOMB_WAGON_WEST
    { 182307, 530, { -1377.9500f, 7773.4400f, -10.3100f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //ALLY_BOMB_WAGON_NORTH
    { 182308, 530, { -1659.8700f, 7733.1500f, -15.7500f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }, //ALLY_BOMB_WAGON_EAST

    { 182297, 530, { -1815.8000f, 8036.5100f, -26.2354f, -2.897250f }, { 0.0f, 0.0f, 0.992546f, -0.121869f } }, //DESTROYED_HORDE_ROOST_SOUTH
    { 182298, 530, { -1507.9500f, 8132.1000f, -19.5585f, -1.343900f }, { 0.0f, 0.0f, 0.622515f, -0.782608f } }, //DESTROYED_HORDE_ROOST_WEST
    { 182299, 530, { -1384.5200f, 7779.3300f, -11.1663f, -0.575959f }, { 0.0f, 0.0f, 0.284015f, -0.958820f } }, //DESTROYED_HORDE_ROOST_NORTH
    { 182300, 530, { -1650.1100f, 7732.5600f, -15.4505f, -2.809980f }, { 0.0f, 0.0f, 0.986286f, -0.165048f } }  //DESTROYED_HORDE_ROOST_EAST
};

creature_type const HordeControlNPCs[NA_CONTROL_NPC_NUM] =
{
    { 18816, 530, { -1523.92f, 7951.76f, -17.6942f, 3.51172f } },
    { 18821, 530, { -1527.75f, 7952.46f, -17.6948f, 3.99317f } },
    { 21474, 530, { -1520.14f, 7927.11f, -20.2527f, 3.39389f } },
    { 21484, 530, { -1524.84f, 7930.34f, -20.1820f, 3.64050f } },
    { 21483, 530, { -1570.01f, 7993.80f, -22.4505f, 5.02655f } },
    { 18192, 530, { -1654.06f, 8000.46f, -26.5900f, 3.37000f } },
    { 18192, 530, { -1487.18f, 7899.10f, -19.5300f, 0.95400f } },
    { 18192, 530, { -1480.88f, 7908.79f, -19.1900f, 4.48500f } },
    { 18192, 530, { -1540.56f, 7995.44f, -20.4500f, 0.94700f } },
    { 18192, 530, { -1546.95f, 8000.85f, -20.7200f, 6.03500f } },
    { 18192, 530, { -1595.31f, 7860.53f, -21.5100f, 3.74700f } },
    { 18192, 530, { -1642.31f, 7995.59f, -25.8000f, 3.31700f } },
    { 18192, 530, { -1545.46f, 7995.35f, -20.6300f, 1.09400f } },
    { 18192, 530, { -1487.58f, 7907.99f, -19.2700f, 5.56700f } },
    { 18192, 530, { -1651.54f, 7988.56f, -26.5289f, 2.98451f } },
    { 18192, 530, { -1602.46f, 7866.43f, -22.1177f, 4.74729f } },
    { 18192, 530, { -1591.22f, 7875.29f, -22.3536f, 4.34587f } },
    { 18192, 530, { -1550.60f, 7944.45f, -21.6300f, 3.55900f } },
    { 18192, 530, { -1545.57f, 7935.83f, -21.1300f, 3.44800f } },
    { 18192, 530, { -1550.86f, 7937.56f, -21.7000f, 3.80100f } }
};

creature_type const AllianceControlNPCs[NA_CONTROL_NPC_NUM] =
{
    { 18817, 530, { -1591.18f, 8020.39f, -22.2042f, 4.59022f } },
    { 18822, 530, { -1588.00f, 8019.00f, -22.2042f, 4.06662f } },
    { 21485, 530, { -1521.93f, 7927.37f, -20.2299f, 3.24631f } },
    { 21487, 530, { -1540.33f, 7971.95f, -20.7186f, 3.07178f } },
    { 21488, 530, { -1570.01f, 7993.80f, -22.4505f, 5.02655f } },
    { 18256, 530, { -1654.06f, 8000.46f, -26.5900f, 3.37000f } },
    { 18256, 530, { -1487.18f, 7899.10f, -19.5300f, 0.95400f } },
    { 18256, 530, { -1480.88f, 7908.79f, -19.1900f, 4.48500f } },
    { 18256, 530, { -1540.56f, 7995.44f, -20.4500f, 0.94700f } },
    { 18256, 530, { -1546.95f, 8000.85f, -20.7200f, 6.03500f } },
    { 18256, 530, { -1595.31f, 7860.53f, -21.5100f, 3.74700f } },
    { 18256, 530, { -1642.31f, 7995.59f, -25.8000f, 3.31700f } },
    { 18256, 530, { -1545.46f, 7995.35f, -20.6300f, 1.09400f } },
    { 18256, 530, { -1487.58f, 7907.99f, -19.2700f, 5.56700f } },
    { 18256, 530, { -1651.54f, 7988.56f, -26.5289f, 2.98451f } },
    { 18256, 530, { -1602.46f, 7866.43f, -22.1177f, 4.74729f } },
    { 18256, 530, { -1591.22f, 7875.29f, -22.3536f, 4.34587f } },
    { 18256, 530, { -1603.75f, 8000.36f, -24.1800f, 4.51600f } },
    { 18256, 530, { -1585.73f, 7994.68f, -23.2900f, 4.43900f } },
    { 18256, 530, { -1595.50f, 7991.27f, -23.5300f, 4.73800f } }
};

OutdoorPvPNA::OutdoorPvPNA()
{
    m_TypeId = OUTDOOR_PVP_NA;
    m_obj = nullptr;
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

uint32 OPvPCapturePointNA::GetAliveGuardsCount()
{
    uint32 cnt = 0;
    for (std::map<uint32, uint32>::iterator itr = m_Creatures.begin(); itr != m_Creatures.end(); ++itr)
    {
        switch (itr->first)
        {
            case NA_NPC_GUARD_01:
            case NA_NPC_GUARD_02:
            case NA_NPC_GUARD_03:
            case NA_NPC_GUARD_04:
            case NA_NPC_GUARD_05:
            case NA_NPC_GUARD_06:
            case NA_NPC_GUARD_07:
            case NA_NPC_GUARD_08:
            case NA_NPC_GUARD_09:
            case NA_NPC_GUARD_10:
            case NA_NPC_GUARD_11:
            case NA_NPC_GUARD_12:
            case NA_NPC_GUARD_13:
            case NA_NPC_GUARD_14:
            case NA_NPC_GUARD_15:
            {
                auto bounds = m_PvP->GetMap()->GetCreatureBySpawnIdStore().equal_range(itr->second);
                for (auto itr2 = bounds.first; itr2 != bounds.second; ++itr2)
                    if (itr2->second->IsAlive())
                        ++cnt;
                break;
            }
            default:
                break;
        }
    }
    return cnt;
}

uint32 OPvPCapturePointNA::GetControllingFaction() const
{
    return m_ControllingFaction;
}

void OPvPCapturePointNA::SpawnNPCsForTeam(uint32 team)
{
    creature_type const* creatures = nullptr;
    if (team == ALLIANCE)
        creatures = AllianceControlNPCs;
    else if (team == HORDE)
        creatures = HordeControlNPCs;
    else
        return;
    for (int i = 0; i < NA_CONTROL_NPC_NUM; ++i)
        AddCreature(i, creatures[i].entry, creatures[i].map, creatures[i].pos, OutdoorPvP::GetTeamIdByTeam(team), 1000000);
}

void OPvPCapturePointNA::DeSpawnNPCs()
{
    for (int i = 0; i < NA_CONTROL_NPC_NUM; ++i)
        DelCreature(i);
}

void OPvPCapturePointNA::SpawnGOsForTeam(uint32 team)
{
    go_type const* gos = nullptr;
    if (team == ALLIANCE)
        gos = AllianceControlGOs;
    else if (team == HORDE)
        gos = HordeControlGOs;
    else
        return;

    // roosts and bomb wagons are spawned when someone uses the matching destroyed roost
    static ControlGOTypes const GoTypes[] =
    {
        NA_DESTROYED_ROOST_S,
        NA_DESTROYED_ROOST_W,
        NA_DESTROYED_ROOST_N,
        NA_DESTROYED_ROOST_E
    };

    for (ControlGOTypes goType : GoTypes)
        AddObject(goType, gos[goType].entry, gos[goType].map, gos[goType].pos, gos[goType].rot);
}

void OPvPCapturePointNA::DeSpawnGOs()
{
    for (int i = 0; i < NA_CONTROL_GO_NUM; ++i)
    {
        DelObject(i);
    }
}

void OPvPCapturePointNA::FactionTakeOver(uint32 team)
{
    if (m_ControllingFaction)
        sObjectMgr->RemoveGraveyardLink(NA_HALAA_GRAVEYARD, NA_HALAA_GRAVEYARD_ZONE, m_ControllingFaction, false);

    m_ControllingFaction = team;
    if (m_ControllingFaction)
        sObjectMgr->AddGraveyardLink(NA_HALAA_GRAVEYARD, NA_HALAA_GRAVEYARD_ZONE, m_ControllingFaction, false);
    DeSpawnGOs();
    DeSpawnNPCs();
    SpawnGOsForTeam(team);
    SpawnNPCsForTeam(team);
    m_GuardsAlive = NA_GUARDS_MAX;
    m_capturable = false;
    this->UpdateHalaaWorldState();
    if (team == ALLIANCE)
    {
        m_WyvernStateSouth = WYVERN_NEU_HORDE;
        m_WyvernStateNorth = WYVERN_NEU_HORDE;
        m_WyvernStateEast = WYVERN_NEU_HORDE;
        m_WyvernStateWest = WYVERN_NEU_HORDE;
        m_PvP->TeamApplyBuff(TEAM_ALLIANCE, NA_CAPTURE_BUFF);
        m_PvP->SendUpdateWorldState(NA_UI_HORDE_GUARDS_SHOW, 0);
        m_PvP->SendUpdateWorldState(NA_UI_ALLIANCE_GUARDS_SHOW, 1);
        m_PvP->SendUpdateWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
        m_PvP->SendDefenseMessage(NA_HALAA_GRAVEYARD_ZONE, TEXT_HALAA_TAKEN_ALLIANCE);
    }
    else
    {
        m_WyvernStateSouth = WYVERN_NEU_ALLIANCE;
        m_WyvernStateNorth = WYVERN_NEU_ALLIANCE;
        m_WyvernStateEast = WYVERN_NEU_ALLIANCE;
        m_WyvernStateWest = WYVERN_NEU_ALLIANCE;
        m_PvP->TeamApplyBuff(TEAM_HORDE, NA_CAPTURE_BUFF);
        m_PvP->SendUpdateWorldState(NA_UI_HORDE_GUARDS_SHOW, 1);
        m_PvP->SendUpdateWorldState(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
        m_PvP->SendUpdateWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
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
    SetCapturePointData(182210, 530, { -1572.57f, 7945.3f, -22.475f, 2.05949f }, { 0.0f, 0.0f, 0.857167f, 0.515038f });
}

bool OutdoorPvPNA::SetupOutdoorPvP()
{
//    m_TypeId = OUTDOOR_PVP_NA; _MUST_ be set in ctor, because of spawns cleanup
    // add the zones affected by the pvp buff
    SetMapFromZone(NA_BUFF_ZONE);
    RegisterZone(NA_BUFF_ZONE);

    // halaa
    m_obj = new OPvPCapturePointNA(this);

    AddCapturePoint(m_obj);
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

void OutdoorPvPNA::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    m_obj->FillInitialWorldStates(packet);
}

void OPvPCapturePointNA::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    if (m_ControllingFaction == ALLIANCE)
    {
        packet.Worldstates.emplace_back(NA_UI_HORDE_GUARDS_SHOW, 0);
        packet.Worldstates.emplace_back(NA_UI_ALLIANCE_GUARDS_SHOW, 1);
    }
    else if (m_ControllingFaction == HORDE)
    {
        packet.Worldstates.emplace_back(NA_UI_HORDE_GUARDS_SHOW, 1);
        packet.Worldstates.emplace_back(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
    }
    else
    {
        packet.Worldstates.emplace_back(NA_UI_HORDE_GUARDS_SHOW, 0);
        packet.Worldstates.emplace_back(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
    }

    packet.Worldstates.emplace_back(NA_UI_GUARDS_MAX, NA_GUARDS_MAX);
    packet.Worldstates.emplace_back(NA_UI_GUARDS_LEFT, m_GuardsAlive);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_NEU_H, (m_WyvernStateNorth & WYVERN_NEU_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_NEU_A, (m_WyvernStateNorth & WYVERN_NEU_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_H, (m_WyvernStateNorth & WYVERN_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_NORTH_A, (m_WyvernStateNorth & WYVERN_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_NEU_H, (m_WyvernStateSouth & WYVERN_NEU_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_NEU_A, (m_WyvernStateSouth & WYVERN_NEU_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_H, (m_WyvernStateSouth & WYVERN_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_SOUTH_A, (m_WyvernStateSouth & WYVERN_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_NEU_H, (m_WyvernStateWest & WYVERN_NEU_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_NEU_A, (m_WyvernStateWest & WYVERN_NEU_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_H, (m_WyvernStateWest & WYVERN_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_WEST_A, (m_WyvernStateWest & WYVERN_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_NEU_H, (m_WyvernStateEast & WYVERN_NEU_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_NEU_A, (m_WyvernStateEast & WYVERN_NEU_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_H, (m_WyvernStateEast & WYVERN_HORDE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_WYVERN_EAST_A, (m_WyvernStateEast & WYVERN_ALLIANCE) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_HALAA_NEUTRAL, (m_HalaaState & HALAA_N) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_HALAA_NEU_A, (m_HalaaState & HALAA_N_A) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_HALAA_NEU_H, (m_HalaaState & HALAA_N_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_HALAA_HORDE, (m_HalaaState & HALAA_H) != 0 ? 1 : 0);
    packet.Worldstates.emplace_back(NA_MAP_HALAA_ALLIANCE, (m_HalaaState & HALAA_A) != 0 ? 1 : 0);
}

void OutdoorPvPNA::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(NA_UI_HORDE_GUARDS_SHOW, 0);
    player->SendUpdateWorldState(NA_UI_ALLIANCE_GUARDS_SHOW, 0);
    player->SendUpdateWorldState(NA_UI_GUARDS_MAX, 0);
    player->SendUpdateWorldState(NA_UI_GUARDS_LEFT, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_NEU_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_NEU_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_NEU_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_NEU_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_WEST_NEU_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_WEST_NEU_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_WEST_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_WEST_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_EAST_NEU_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_EAST_NEU_A, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_EAST_H, 0);
    player->SendUpdateWorldState(NA_MAP_WYVERN_EAST_A, 0);
    player->SendUpdateWorldState(NA_MAP_HALAA_NEUTRAL, 0);
    player->SendUpdateWorldState(NA_MAP_HALAA_NEU_A, 0);
    player->SendUpdateWorldState(NA_MAP_HALAA_NEU_H, 0);
    player->SendUpdateWorldState(NA_MAP_HALAA_HORDE, 0);
    player->SendUpdateWorldState(NA_MAP_HALAA_ALLIANCE, 0);
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
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_SOUTH:
        nodes[0] = FlightPathStartNodes[NA_ROOST_S];
        nodes[1] = FlightPathEndNodes[NA_ROOST_S];
        player->ActivateTaxiPathTo(nodes);
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_WEST:
        nodes[0] = FlightPathStartNodes[NA_ROOST_W];
        nodes[1] = FlightPathEndNodes[NA_ROOST_W];
        player->ActivateTaxiPathTo(nodes);
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
        player->UpdatePvP(true, true);
        retval = true;
        break;
    case NA_SPELL_FLY_EAST:
        nodes[0] = FlightPathStartNodes[NA_ROOST_E];
        nodes[1] = FlightPathEndNodes[NA_ROOST_E];
        player->ActivateTaxiPathTo(nodes);
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
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
    int32 retval = OPvPCapturePoint::HandleOpenGo(player, go);
    if (retval >= 0)
    {
        go_type const* gos = nullptr;
        if (m_ControllingFaction == ALLIANCE)
            gos = AllianceControlGOs;
        else if (m_ControllingFaction == HORDE)
            gos = HordeControlGOs;
        else
            return -1;

        int32 del = -1;
        int32 del2 = -1;
        int32 add = -1;
        int32 add2 = -1;

        switch (retval)
        {
            case NA_DESTROYED_ROOST_S:
                del = NA_DESTROYED_ROOST_S;
                add = NA_ROOST_S;
                add2 = NA_BOMB_WAGON_S;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateSouth = WYVERN_ALLIANCE;
                else
                    m_WyvernStateSouth = WYVERN_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_S);
                break;
            case NA_DESTROYED_ROOST_N:
                del = NA_DESTROYED_ROOST_N;
                add = NA_ROOST_N;
                add2 = NA_BOMB_WAGON_N;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateNorth = WYVERN_ALLIANCE;
                else
                    m_WyvernStateNorth = WYVERN_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_N);
                break;
            case NA_DESTROYED_ROOST_W:
                del = NA_DESTROYED_ROOST_W;
                add = NA_ROOST_W;
                add2 = NA_BOMB_WAGON_W;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateWest = WYVERN_ALLIANCE;
                else
                    m_WyvernStateWest = WYVERN_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_W);
                break;
            case NA_DESTROYED_ROOST_E:
                del = NA_DESTROYED_ROOST_E;
                add = NA_ROOST_E;
                add2 = NA_BOMB_WAGON_E;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateEast = WYVERN_ALLIANCE;
                else
                    m_WyvernStateEast = WYVERN_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_E);
                break;
            case NA_BOMB_WAGON_S:
                del = NA_BOMB_WAGON_S;
                del2 = NA_ROOST_S;
                add = NA_DESTROYED_ROOST_S;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateSouth = WYVERN_NEU_ALLIANCE;
                else
                    m_WyvernStateSouth = WYVERN_NEU_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_S);
                break;
            case NA_BOMB_WAGON_N:
                del = NA_BOMB_WAGON_N;
                del2 = NA_ROOST_N;
                add = NA_DESTROYED_ROOST_N;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateNorth = WYVERN_NEU_ALLIANCE;
                else
                    m_WyvernStateNorth = WYVERN_NEU_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_N);
                break;
            case NA_BOMB_WAGON_W:
                del = NA_BOMB_WAGON_W;
                del2 = NA_ROOST_W;
                add = NA_DESTROYED_ROOST_W;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateWest = WYVERN_NEU_ALLIANCE;
                else
                    m_WyvernStateWest = WYVERN_NEU_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_W);
                break;
            case NA_BOMB_WAGON_E:
                del = NA_BOMB_WAGON_E;
                del2 = NA_ROOST_E;
                add = NA_DESTROYED_ROOST_E;
                if (m_ControllingFaction == HORDE)
                    m_WyvernStateEast = WYVERN_NEU_ALLIANCE;
                else
                    m_WyvernStateEast = WYVERN_NEU_HORDE;
                UpdateWyvernRoostWorldState(NA_ROOST_E);
                break;
            default:
                return -1;
                break;
        }

        if (del > -1)
            DelObject(del);

        if (del2 > -1)
            DelObject(del2);

        if (add > -1)
            AddObject(add, gos[add].entry, gos[add].map, gos[add].pos, gos[add].rot);

        if (add2 > -1)
            AddObject(add2, gos[add2].entry, gos[add2].map, gos[add2].pos, gos[add2].rot);

        return retval;
    }
    return -1;
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
        uint32 cnt = GetAliveGuardsCount();
        if (cnt != m_GuardsAlive)
        {
            m_GuardsAlive = cnt;
            if (m_GuardsAlive == 0)
                m_capturable = true;
            // update the guard count for the players in zone
            m_PvP->SendUpdateWorldState(NA_UI_GUARDS_LEFT, m_GuardsAlive);
        }
    } else m_GuardCheckTimer -= diff;

    if (m_capturable || capturable)
    {
        if (m_RespawnTimer < diff)
        {
            // if the guards have been killed, then the challenger has one hour to take over halaa.
            // in case they fail to do it, the guards are respawned, and they have to start again.
            if (m_ControllingFaction)
                FactionTakeOver(m_ControllingFaction);
            m_RespawnTimer = NA_RESPAWN_TIME;
        } else m_RespawnTimer -= diff;

        return OPvPCapturePoint::Update(diff);
    }
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
    m_PvP->SendUpdateWorldState(NA_MAP_HALAA_NEUTRAL, uint32((m_HalaaState & HALAA_N) != 0));
    m_PvP->SendUpdateWorldState(NA_MAP_HALAA_NEU_A, uint32((m_HalaaState & HALAA_N_A) != 0));
    m_PvP->SendUpdateWorldState(NA_MAP_HALAA_NEU_H, uint32((m_HalaaState & HALAA_N_H) != 0));
    m_PvP->SendUpdateWorldState(NA_MAP_HALAA_HORDE, uint32((m_HalaaState & HALAA_H) != 0));
    m_PvP->SendUpdateWorldState(NA_MAP_HALAA_ALLIANCE, uint32((m_HalaaState & HALAA_A) != 0));
}

void OPvPCapturePointNA::UpdateWyvernRoostWorldState(uint32 roost)
{
    switch (roost)
    {
        case NA_ROOST_S:
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_NEU_H, uint32((m_WyvernStateSouth & WYVERN_NEU_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_NEU_A, uint32((m_WyvernStateSouth & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_H, uint32((m_WyvernStateSouth & WYVERN_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_SOUTH_A, uint32((m_WyvernStateSouth & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_N:
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_NEU_H, uint32((m_WyvernStateNorth & WYVERN_NEU_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_NEU_A, uint32((m_WyvernStateNorth & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_H, uint32((m_WyvernStateNorth & WYVERN_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_NORTH_A, uint32((m_WyvernStateNorth & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_W:
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_WEST_NEU_H, uint32((m_WyvernStateWest & WYVERN_NEU_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_WEST_NEU_A, uint32((m_WyvernStateWest & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_WEST_H, uint32((m_WyvernStateWest & WYVERN_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_WEST_A, uint32((m_WyvernStateWest & WYVERN_ALLIANCE) != 0));
            break;
        case NA_ROOST_E:
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_EAST_NEU_H, uint32((m_WyvernStateEast & WYVERN_NEU_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_EAST_NEU_A, uint32((m_WyvernStateEast & WYVERN_NEU_ALLIANCE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_EAST_H, uint32((m_WyvernStateEast & WYVERN_HORDE) != 0));
            m_PvP->SendUpdateWorldState(NA_MAP_WYVERN_EAST_A, uint32((m_WyvernStateEast & WYVERN_ALLIANCE) != 0));
            break;
    }
}

class OutdoorPvP_nagrand : public OutdoorPvPScript
{
    public:
        OutdoorPvP_nagrand() : OutdoorPvPScript("outdoorpvp_na") { }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPNA();
        }
};

void AddSC_outdoorpvp_na()
{
    new OutdoorPvP_nagrand();
}
