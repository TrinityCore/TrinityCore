/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "WorldSession.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TaxiPackets.h"
#include "TaxiPathGraph.h"
#include "WaypointMovementGenerator.h"

void WorldSession::HandleEnableTaxiNodeOpcode(WorldPackets::Taxi::EnableTaxiNode& enableTaxiNode)
{
    if (Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(enableTaxiNode.Unit, UNIT_NPC_FLAG_FLIGHTMASTER))
        SendLearnNewTaxiNode(unit);
}

void WorldSession::HandleTaxiNodeStatusQueryOpcode(WorldPackets::Taxi::TaxiNodeStatusQuery& taxiNodeStatusQuery)
{
    SendTaxiStatus(taxiNodeStatusQuery.UnitGUID);
}

void WorldSession::SendTaxiStatus(ObjectGuid guid)
{
    // cheating checks
    Creature* unit = ObjectAccessor::GetCreature(*GetPlayer(), guid);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTaxiStatus - %s not found.", guid.ToString().c_str());
        return;
    }

    uint32 curloc = sObjectMgr->GetNearestTaxiNode(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), unit->GetMapId(), GetPlayer()->GetTeam());

    WorldPackets::Taxi::TaxiNodeStatus data;
    data.Unit = guid;

    if (!curloc)
        data.Status = TAXISTATUS_NONE;
    else if (unit->GetReactionTo(GetPlayer()) >= REP_NEUTRAL)
        data.Status = GetPlayer()->m_taxi.IsTaximaskNodeKnown(curloc) ? TAXISTATUS_LEARNED : TAXISTATUS_UNLEARNED;
    else
        data.Status = TAXISTATUS_NOT_ELIGIBLE;

    SendPacket(data.Write());
}

void WorldSession::HandleTaxiQueryAvailableNodesOpcode(WorldPackets::Taxi::TaxiQueryAvailableNodes& taxiQueryAvailableNodes)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (taxiQueryAvailableNodes.Unit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(taxiQueryAvailableNodes.Unit))
            creature->SendMirrorSound(_player, 0);
#endif
    // cheating checks
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(taxiQueryAvailableNodes.Unit, UNIT_NPC_FLAG_FLIGHTMASTER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTaxiQueryAvailableNodes - %s not found or you can't interact with him.", taxiQueryAvailableNodes.Unit.ToString().c_str());
        return;
    }
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // unknown taxi node case
    if (SendLearnNewTaxiNode(unit))
        return;

    // known taxi node case
    SendTaxiMenu(unit);
}

void WorldSession::SendTaxiMenu(Creature* unit)
{
    // find current node
    uint32 curloc = sObjectMgr->GetNearestTaxiNode(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), unit->GetMapId(), GetPlayer()->GetTeam());
    if (!curloc)
        return;

    bool lastTaxiCheaterState = GetPlayer()->isTaxiCheater();
    if (unit->GetEntry() == 29480)
        GetPlayer()->SetTaxiCheater(true); // Grimwing in Ebon Hold, special case. NOTE: Not perfect, Zul'Aman should not be included according to WoWhead, and I think taxicheat includes it.

    TC_LOG_DEBUG("network", "WORLD: CMSG_TAXINODE_STATUS_QUERY %u ", curloc);

    WorldPackets::Taxi::ShowTaxiNodes data;
    data.WindowInfo = boost::in_place();
    data.WindowInfo->UnitGUID = unit->GetGUID();
    data.WindowInfo->CurrentNode = curloc;

    GetPlayer()->m_taxi.AppendTaximaskTo(data, lastTaxiCheaterState);

    TaxiMask reachableNodes;
    std::fill(reachableNodes.begin(), reachableNodes.end(), 0);
    sTaxiPathGraph.GetReachableNodesMask(sTaxiNodesStore.LookupEntry(curloc), &reachableNodes);

    for (std::size_t i = 0; i < TaxiMaskSize; ++i)
    {
        data.CanLandNodes[i] &= reachableNodes[i];
        data.CanUseNodes[i] &= reachableNodes[i];
    }

    SendPacket(data.Write());

    GetPlayer()->SetTaxiCheater(lastTaxiCheaterState);
}

void WorldSession::SendDoFlight(uint32 mountDisplayId, uint32 path, uint32 pathNode)
{
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    while (GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
        GetPlayer()->GetMotionMaster()->MovementExpired(false);

    if (mountDisplayId)
        GetPlayer()->Mount(mountDisplayId);

    GetPlayer()->GetMotionMaster()->MoveTaxiFlight(path, pathNode);
}

bool WorldSession::SendLearnNewTaxiNode(Creature* unit)
{
    // find current node
    uint32 curloc = sObjectMgr->GetNearestTaxiNode(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), unit->GetMapId(), GetPlayer()->GetTeam());

    if (curloc == 0)
        return true;                                        // `true` send to avoid WorldSession::SendTaxiMenu call with one more curlock seartch with same false result.

    if (GetPlayer()->m_taxi.SetTaximaskNode(curloc))
    {
        SendPacket(WorldPackets::Taxi::NewTaxiPath().Write());

        WorldPackets::Taxi::TaxiNodeStatus data;
        data.Unit = unit->GetGUID();
        data.Status = TAXISTATUS_LEARNED;
        SendPacket(data.Write());

        return true;
    }
    else
        return false;
}

void WorldSession::SendDiscoverNewTaxiNode(uint32 nodeid)
{
    if (GetPlayer()->m_taxi.SetTaximaskNode(nodeid))
        SendPacket(WorldPackets::Taxi::NewTaxiPath().Write());
}

void WorldSession::HandleActivateTaxiOpcode(WorldPackets::Taxi::ActivateTaxi& activateTaxi)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(activateTaxi.Vendor, UNIT_NPC_FLAG_FLIGHTMASTER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleActivateTaxiOpcode - %s not found or you can't interact with it.", activateTaxi.Vendor.ToString().c_str());
        SendActivateTaxiReply(ERR_TAXITOOFARAWAY);
        return;
    }

    uint32 curloc = sObjectMgr->GetNearestTaxiNode(unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), unit->GetMapId(), GetPlayer()->GetTeam());
    if (!curloc)
        return;

    TaxiNodesEntry const* from = sTaxiNodesStore.LookupEntry(curloc);
    TaxiNodesEntry const* to = sTaxiNodesStore.LookupEntry(activateTaxi.Node);
    if (!to)
        return;

    if (!GetPlayer()->isTaxiCheater())
    {
        if (!GetPlayer()->m_taxi.IsTaximaskNodeKnown(curloc) || !GetPlayer()->m_taxi.IsTaximaskNodeKnown(activateTaxi.Node))
        {
            SendActivateTaxiReply(ERR_TAXINOTVISITED);
            return;
        }
    }

    uint32 preferredMountDisplay = 0;
    if (MountEntry const* mount = sMountStore.LookupEntry(activateTaxi.FlyingMountID))
    {
        if (GetPlayer()->HasSpell(mount->SourceSpellID))
        {
            if (DB2Manager::MountXDisplayContainer const* mountDisplays = sDB2Manager.GetMountDisplays(mount->ID))
            {
                DB2Manager::MountXDisplayContainer usableDisplays;
                std::copy_if(mountDisplays->begin(), mountDisplays->end(), std::back_inserter(usableDisplays), [this](MountXDisplayEntry const* mountDisplay)
                {
                    if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(mountDisplay->PlayerConditionID))
                        return sConditionMgr->IsPlayerMeetingCondition(GetPlayer(), playerCondition);

                    return true;
                });

                if (!usableDisplays.empty())
                    preferredMountDisplay = Trinity::Containers::SelectRandomContainerElement(usableDisplays)->CreatureDisplayInfoID;
            }
        }
    }

    std::vector<uint32> nodes;
    sTaxiPathGraph.GetCompleteNodeRoute(from, to, GetPlayer(), nodes);
    GetPlayer()->ActivateTaxiPathTo(nodes, unit, 0, preferredMountDisplay);
}

void WorldSession::SendActivateTaxiReply(ActivateTaxiReply reply)
{
    WorldPackets::Taxi::ActivateTaxiReply data;
    data.Reply = reply;
    SendPacket(data.Write());
}

void WorldSession::HandleTaxiRequestEarlyLanding(WorldPackets::Taxi::TaxiRequestEarlyLanding& /*taxiRequestEarlyLanding*/)
{
    if (GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
    {
        if (GetPlayer()->m_taxi.RequestEarlyLanding())
        {
            FlightPathMovementGenerator* flight = static_cast<FlightPathMovementGenerator*>(GetPlayer()->GetMotionMaster()->top());
            flight->LoadPath(GetPlayer(), flight->GetPath()[flight->GetCurrentNode()]->NodeIndex);
            flight->Reset(GetPlayer());
        }
    }
}
