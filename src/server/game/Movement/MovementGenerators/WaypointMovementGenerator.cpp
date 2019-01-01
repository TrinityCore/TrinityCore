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

#include "WaypointMovementGenerator.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "Log.h"
#include "MapManager.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"
#include "World.h"

void WaypointMovementGenerator<Creature>::LoadPath(Creature* creature)
{
    if (LoadedFromDB)
    {
        if (!path_id)
            path_id = creature->GetWaypointPath();

        i_path = sWaypointMgr->GetPath(path_id);
    }

    if (!i_path)
    {
        // No path id found for entry
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::LoadPath: creature %s (%s DB GUID: " UI64FMTD ") doesn't have waypoint path id: %u", creature->GetName().c_str(), creature->GetGUID().ToString().c_str(), creature->GetSpawnId(), path_id);
        return;
    }

    if (!Stopped())
        StartMoveNow(creature);
}

void WaypointMovementGenerator<Creature>::DoInitialize(Creature* creature)
{
    LoadPath(creature);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* creature)
{
    creature->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
    creature->SetWalk(false);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* creature)
{
    if (!Stopped())
        StartMoveNow(creature);
}

void WaypointMovementGenerator<Creature>::OnArrived(Creature* creature)
{
    if (!i_path || i_path->nodes.empty())
        return;

    WaypointNode const &waypoint = i_path->nodes.at(i_currentNode);
    if (waypoint.delay)
    {
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        Stop(waypoint.delay);
    }

    if (waypoint.eventId && urand(0, 99) < waypoint.eventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.eventId, i_currentNode, creature->GetGUID().ToString().c_str());
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        creature->GetMap()->ScriptsStart(sWaypointScripts, waypoint.eventId, creature, nullptr);
    }

    // Inform script
    MovementInform(creature);
    creature->UpdateWaypointID(i_currentNode);

    creature->SetWalk(waypoint.moveType != WAYPOINT_MOVE_TYPE_RUN);
}

void WaypointMovementGenerator<Creature>::FormationMove(Creature* creature)
{
    bool transportPath = creature->GetTransport() != nullptr;

    WaypointNode const &waypoint = i_path->nodes.at(i_currentNode);

    Movement::Location formationDest(waypoint.x, waypoint.y, waypoint.z, 0.0f);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
    {
        if (TransportBase* trans = creature->GetDirectTransport())
            trans->CalculatePassengerPosition(formationDest.x, formationDest.y, formationDest.z, &formationDest.orientation);
    }

    // Call for creature group update
    if (creature->GetFormation() && creature->GetFormation()->getLeader() == creature)
        creature->GetFormation()->LeaderMoveTo(formationDest.x, formationDest.y, formationDest.z);
}

bool WaypointMovementGenerator<Creature>::StartMove(Creature* creature)
{
    if (!creature || !creature->IsAlive())
        return false;

    if (!i_path || i_path->nodes.empty())
        return false;

    if (Stopped())
        return true;

    bool transportPath = creature->GetTransport() != nullptr;

    if (IsArrivalDone)
    {
        if ((i_currentNode == i_path->nodes.size() - 1) && !repeating) // If that's our last waypoint
        {
            WaypointNode const &waypoint = i_path->nodes.at(i_currentNode);

            float x = waypoint.x;
            float y = waypoint.y;
            float z = waypoint.z;
            float o = creature->GetOrientation();

            if (!transportPath)
                creature->SetHomePosition(x, y, z, o);
            else
            {
                if (Transport* trans = creature->GetTransport())
                {
                    o -= trans->GetOrientation();
                    creature->SetTransportHomePosition(x, y, z, o);
                    trans->CalculatePassengerPosition(x, y, z, &o);
                    creature->SetHomePosition(x, y, z, o);
                }
                else
                    transportPath = false;
                // else if (vehicle) - this should never happen, vehicle offsets are const
            }
            return false;
        }

        i_currentNode = (i_currentNode + 1) % i_path->nodes.size();
    }

    float finalOrient = 0.0f;
    uint8 finalMove = WAYPOINT_MOVE_TYPE_WALK;

    Movement::PointsArray pathing;
    pathing.reserve((i_path->nodes.size() - i_currentNode) + 1);

    pathing.push_back(G3D::Vector3(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ()));
    for (uint32 i = i_currentNode; i < i_path->nodes.size(); ++i)
    {
        WaypointNode const &waypoint = i_path->nodes.at(i);

        pathing.push_back(G3D::Vector3(waypoint.x, waypoint.y, waypoint.z));

        finalOrient = waypoint.orientation;
        finalMove = waypoint.moveType;

        if (waypoint.delay)
            break;
    }

    // if we have only 1 point, only current position, we shall return
    if (pathing.size() < 2)
        return false;

    IsArrivalDone = false;
    i_recalculateSpeed = false;

    creature->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(creature);

    Movement::Location formationDest(i_path->nodes.at(i_currentNode).x, i_path->nodes.at(i_currentNode).y, i_path->nodes.at(i_currentNode).z, 0.0f);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
    {
        init.DisableTransportPathTransformations();
        if (TransportBase* trans = creature->GetDirectTransport())
            trans->CalculatePassengerPosition(formationDest.x, formationDest.y, formationDest.z, &formationDest.orientation);
    }

    init.MovebyPath(pathing, i_currentNode);

    switch (finalMove)
    {
        case WAYPOINT_MOVE_TYPE_LAND:
            init.SetAnimation(Movement::ToGround);
            break;
        case WAYPOINT_MOVE_TYPE_TAKEOFF:
            init.SetAnimation(Movement::ToFly);
            break;
        case WAYPOINT_MOVE_TYPE_RUN:
            init.SetWalk(false);
            break;
        case WAYPOINT_MOVE_TYPE_WALK:
            init.SetWalk(true);
            break;
    }

    if (finalOrient != 0.0f)
        init.SetFacing(finalOrient);

    init.Launch();

    //Call for creature group update
    if (creature->GetFormation() && creature->GetFormation()->getLeader() == creature)
        creature->GetFormation()->LeaderMoveTo(formationDest.x, formationDest.y, formationDest.z);

    return true;
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* creature, uint32 diff)
{
    if (!creature || !creature->IsAlive())
        return false;

    // Waypoint movement can be switched on/off
    // This is quite handy for escort quests and other stuff
    if (creature->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        return true;
    }

    // prevent a crash at empty waypoint path.
    if (!i_path || i_path->nodes.empty())
        return false;

    if (Stopped())
    {
        if (CanMove(diff))
            return StartMoveNow(creature);
    }
    else
    {
        // Set home position at place on waypoint movement.
        if (!creature->GetTransGUID())
            creature->SetHomePosition(creature->GetPosition());

        if (creature->IsStopped())
            Stop(LoadedFromDB ? sWorld->getIntConfig(CONFIG_CREATURE_STOP_FOR_PLAYER) : 2 * HOUR * IN_MILLISECONDS);
        else if (creature->movespline->Finalized())
        {
            OnArrived(creature);

            IsArrivalDone = true;

            if (!Stopped())
            {
                if (creature->IsStopped())
                    Stop(LoadedFromDB ? sWorld->getIntConfig(CONFIG_CREATURE_STOP_FOR_PLAYER) : 2 * HOUR * IN_MILLISECONDS);
                else
                    return StartMove(creature);
            }
        }
        else
        {
            // speed changed during path execution, calculate remaining path and launch it once more
            if (i_recalculateSpeed)
            {
                i_recalculateSpeed = false;

                if (!Stopped())
                    return StartMove(creature);
            }
            else
            {
                uint32 pointId = uint32(creature->movespline->currentPathIdx());
                if (pointId > i_currentNode)
                {
                    OnArrived(creature);
                    i_currentNode = pointId;
                    FormationMove(creature);
                }
            }
        }
    }
    return true;
}

void WaypointMovementGenerator<Creature>::MovementInform(Creature* creature)
{
    if (creature->AI())
        creature->AI()->MovementInform(WAYPOINT_MOTION_TYPE, i_currentNode);
}

bool WaypointMovementGenerator<Creature>::GetResetPos(Creature*, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    if (!i_path || i_path->nodes.empty())
        return false;

    WaypointNode const &waypoint = i_path->nodes.at(i_currentNode);

    x = waypoint.x;
    y = waypoint.y;
    z = waypoint.z;
    return true;
}


//----------------------------------------------------//

uint32 FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if (i_currentNode >= i_path.size())
        return i_path.size();

    uint32 curMapId = i_path[i_currentNode]->ContinentID;
    for (uint32 i = i_currentNode; i < i_path.size(); ++i)
        if (i_path[i]->ContinentID != curMapId)
            return i;

    return i_path.size();
}

#define SKIP_SPLINE_POINT_DISTANCE_SQ (40.0f * 40.0f)

bool IsNodeIncludedInShortenedPath(TaxiPathNodeEntry const* p1, TaxiPathNodeEntry const* p2)
{
    return p1->ContinentID != p2->ContinentID || std::pow(p1->Loc.X - p2->Loc.X, 2) + std::pow(p1->Loc.Y - p2->Loc.Y, 2) > SKIP_SPLINE_POINT_DISTANCE_SQ;
}

void FlightPathMovementGenerator::LoadPath(Player* player, uint32 startNode /*= 0*/)
{
    i_path.clear();
    i_currentNode = startNode;
    _pointsForPathSwitch.clear();
    std::deque<uint32> const& taxi = player->m_taxi.GetPath();
    float discount = player->GetReputationPriceDiscount(player->m_taxi.GetFlightMasterFactionTemplate());
    for (uint32 src = 0, dst = 1; dst < taxi.size(); src = dst++)
    {
        uint32 path, cost;
        sObjectMgr->GetTaxiPath(taxi[src], taxi[dst], path, cost);
        if (path > sTaxiPathNodesByPath.size())
            return;

        TaxiPathNodeList const& nodes = sTaxiPathNodesByPath[path];
        if (!nodes.empty())
        {
            TaxiPathNodeEntry const* start = nodes[0];
            TaxiPathNodeEntry const* end = nodes[nodes.size() - 1];
            bool passedPreviousSegmentProximityCheck = false;
            for (uint32 i = 0; i < nodes.size(); ++i)
            {
                if (passedPreviousSegmentProximityCheck || !src || i_path.empty() || IsNodeIncludedInShortenedPath(i_path.back(), nodes[i]))
                {
                    if ((!src || (IsNodeIncludedInShortenedPath(start, nodes[i]) && i >= 2)) &&
                        (dst == taxi.size() - 1 || (IsNodeIncludedInShortenedPath(end, nodes[i]) && i < nodes.size() - 1)))
                    {
                        passedPreviousSegmentProximityCheck = true;
                        i_path.push_back(nodes[i]);
                    }
                }
                else
                {
                    i_path.pop_back();
                    --_pointsForPathSwitch.back().PathIndex;
                }
            }
        }

        _pointsForPathSwitch.push_back({ uint32(i_path.size() - 1), int64(ceil(cost * discount)) });
    }
}

void FlightPathMovementGenerator::DoInitialize(Player* player)
{
    Reset(player);
    InitEndGridInfo();
}

void FlightPathMovementGenerator::DoFinalize(Player* player)
{
    // remove flag to prevent send object build movement packets for flight state and crash (movement generator already not at top of stack)
    player->ClearUnitState(UNIT_STATE_IN_FLIGHT);

    player->Dismount();
    player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    if (player->m_taxi.empty())
    {
        player->getHostileRefManager().setOnlineOfflineState(true);
        // update z position to ground and orientation for landing point
        // this prevent cheating with landing  point at lags
        // when client side flight end early in comparison server side
        player->StopMoving();
    }

    player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);
    player->RestoreDisplayId();
}

#define PLAYER_FLIGHT_SPEED 30.0f

void FlightPathMovementGenerator::DoReset(Player* player)
{
    player->getHostileRefManager().setOnlineOfflineState(false);
    player->AddUnitState(UNIT_STATE_IN_FLIGHT);
    player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    Movement::MoveSplineInit init(player);
    uint32 end = GetPathAtMapEnd();
    for (uint32 i = i_currentNode; i != end; ++i)
    {
        G3D::Vector3 vertice(i_path[i]->Loc.X, i_path[i]->Loc.Y, i_path[i]->Loc.Z);
        init.Path().push_back(vertice);
    }
    init.SetFirstPointId(i_currentNode);
    init.SetFly();
    init.SetSmooth();
    init.SetUncompressed();
    init.SetWalk(true);
    init.SetVelocity(PLAYER_FLIGHT_SPEED);
    init.Launch();
}

bool FlightPathMovementGenerator::DoUpdate(Player* player, uint32 /*diff*/)
{
    uint32 pointId = (uint32)player->movespline->currentPathIdx();
    if (pointId > i_currentNode)
    {
        bool departureEvent = true;
        do
        {
            DoEventIfAny(player, i_path[i_currentNode], departureEvent);
            while (!_pointsForPathSwitch.empty() && _pointsForPathSwitch.front().PathIndex <= i_currentNode)
            {
                _pointsForPathSwitch.pop_front();
                player->m_taxi.NextTaxiDestination();
                if (!_pointsForPathSwitch.empty())
                {
                    player->UpdateCriteria(CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, _pointsForPathSwitch.front().Cost);
                    player->ModifyMoney(-_pointsForPathSwitch.front().Cost);
                }
            }

            if (pointId == i_currentNode)
                break;

            if (i_currentNode == _preloadTargetNode)
                PreloadEndGrid();
            i_currentNode += (uint32)departureEvent;
            departureEvent = !departureEvent;
        }
        while (true);
    }

    return i_currentNode < (i_path.size() - 1);
}

void FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if (i_path.empty() || i_currentNode >= i_path.size())
        return;

    uint32 map0 = i_path[i_currentNode]->ContinentID;
    for (size_t i = i_currentNode + 1; i < i_path.size(); ++i)
    {
        if (i_path[i]->ContinentID != map0)
        {
            i_currentNode = i;
            return;
        }
    }
}

void FlightPathMovementGenerator::DoEventIfAny(Player* player, TaxiPathNodeEntry const* node, bool departure)
{
    if (uint32 eventid = departure ? node->DepartureEventID : node->ArrivalEventID)
    {
        TC_LOG_DEBUG("maps.script", "Taxi %s event %u of node %u of path %u for player %s", departure ? "departure" : "arrival", eventid, node->NodeIndex, node->PathID, player->GetName().c_str());
        player->GetMap()->ScriptsStart(sEventScripts, eventid, player, player);
    }
}

bool FlightPathMovementGenerator::GetResetPos(Player*, float& x, float& y, float& z)
{
    TaxiPathNodeEntry const* node = i_path[i_currentNode];
    x = node->Loc.X;
    y = node->Loc.Y;
    z = node->Loc.Z;
    return true;
}

void FlightPathMovementGenerator::InitEndGridInfo()
{
    /*! Storage to preload flightmaster grid at end of flight. For multi-stop flights, this will
       be reinitialized for each flightmaster at the end of each spline (or stop) in the flight. */
    uint32 nodeCount = i_path.size();        //! Number of nodes in path.
    _endMapId = i_path[nodeCount - 1]->ContinentID; //! MapId of last node
    _preloadTargetNode = nodeCount - 3;
    _endGridX = i_path[nodeCount - 1]->Loc.X;
    _endGridY = i_path[nodeCount - 1]->Loc.Y;
}

void FlightPathMovementGenerator::PreloadEndGrid()
{
    // used to preload the final grid where the flightmaster is
    Map* endMap = sMapMgr->FindBaseNonInstanceMap(_endMapId);

    // Load the grid
    if (endMap)
    {
        TC_LOG_DEBUG("misc", "Preloading rid (%f, %f) for map %u at node index %u/%u", _endGridX, _endGridY, _endMapId, _preloadTargetNode, (uint32)(i_path.size() - 1));
        endMap->LoadGrid(_endGridX, _endGridY);
    }
    else
        TC_LOG_DEBUG("misc", "Unable to determine map to preload flightmaster grid");
}
