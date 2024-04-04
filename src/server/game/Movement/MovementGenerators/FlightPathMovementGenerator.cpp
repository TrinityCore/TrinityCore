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

#include "FlightPathMovementGenerator.h"
#include "DB2Stores.h"
#include "GameEventSender.h"
#include "Log.h"
#include "Map.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Player.h"
#include <sstream>

#define FLIGHT_TRAVEL_UPDATE 100
#define TIMEDIFF_NEXT_WP 250
#define SKIP_SPLINE_POINT_DISTANCE_SQ (40.f * 40.f)
#define PLAYER_FLIGHT_SPEED 32.0f

FlightPathMovementGenerator::FlightPathMovementGenerator(Optional<float> speed)
{
    _speed = speed;
    _endGridX = 0.0f;
    _endGridY = 0.0f;
    _endMapId = 0;
    _preloadTargetNode = 0;

    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_HIGHEST;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_IN_FLIGHT;
}

MovementGeneratorType FlightPathMovementGenerator::GetMovementGeneratorType() const
{
    return FLIGHT_MOTION_TYPE;
}

bool FlightPathMovementGenerator::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
{
    TaxiPathNodeEntry const* node = _path[_currentNode];
    x = node->Loc.X;
    y = node->Loc.Y;
    z = node->Loc.Z;
    return true;
}

void FlightPathMovementGenerator::DoInitialize(Player* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    DoReset(owner);
    InitEndGridInfo();
}

void FlightPathMovementGenerator::DoReset(Player* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    owner->CombatStopWithPets();
    owner->SetUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_ON_TAXI);

    uint32 end = GetPathAtMapEnd();
    uint32 currentNodeId = GetCurrentNode();

    if (currentNodeId == end)
    {
        TC_LOG_DEBUG("movement.flightpath", "FlightPathMovementGenerator::DoReset: trying to start a flypath from the end point. {}", owner->GetDebugInfo());
        return;
    }

    Movement::MoveSplineInit init(owner);
    // Providing a starting vertex since the taxi paths do not provide such
    init.Path().push_back(G3D::Vector3(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ()));
    for (uint32 i = currentNodeId; i != end; ++i)
    {
        G3D::Vector3 vertice(_path[i]->Loc.X, _path[i]->Loc.Y, _path[i]->Loc.Z);
        init.Path().push_back(vertice);
    }
    init.SetFirstPointId(GetCurrentNode());
    init.SetFly();
    init.SetSmooth();
    init.SetUncompressed();
    init.SetWalk(true);
    init.SetVelocity(_speed.value_or(PLAYER_FLIGHT_SPEED));
    init.Launch();
}

bool FlightPathMovementGenerator::DoUpdate(Player* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    // skipping the first spline path point because it's our starting point and not a taxi path point
    uint32 pointId = owner->movespline->currentPathIdx() <= 0 ? 0 : owner->movespline->currentPathIdx() - 1;
    if (pointId > _currentNode && _currentNode < _path.size() - 1)
    {
        bool departureEvent = true;
        do
        {
            ASSERT(_currentNode < _path.size(), "Point Id: %u\n%s", pointId, owner->GetDebugInfo().c_str());

            DoEventIfAny(owner, _path[_currentNode], departureEvent);
            while (!_pointsForPathSwitch.empty() && _pointsForPathSwitch.front().PathIndex <= _currentNode)
            {
                _pointsForPathSwitch.pop_front();
                owner->m_taxi.NextTaxiDestination();
                if (!_pointsForPathSwitch.empty())
                {
                    owner->UpdateCriteria(CriteriaType::MoneySpentOnTaxis, _pointsForPathSwitch.front().Cost);
                    owner->ModifyMoney(-_pointsForPathSwitch.front().Cost);
                }
            }

            if (pointId == _currentNode)
                break;

            if (_currentNode == _preloadTargetNode)
                PreloadEndGrid(owner);

            _currentNode += departureEvent ? 1 : 0;
            departureEvent = !departureEvent;
        } while (_currentNode < _path.size() - 1);
    }

    if (_currentNode >= (_path.size() - 1))
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

void FlightPathMovementGenerator::DoDeactivate(Player* /*owner*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

void FlightPathMovementGenerator::DoFinalize(Player* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (!active)
        return;

    owner->m_taxi.ClearTaxiDestinations();
    owner->Dismount();
    owner->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_ON_TAXI);

    // update z position to ground and orientation for landing point
    // this prevent cheating with landing point at lags
    // when client side flight end early in comparison server side
    owner->StopMoving();

    // When the player reaches the last flight point, teleport to destination taxi node location
    if (!_path.empty() && (_path.size() < 2 || !(_path[_path.size() - 2]->Flags & TAXI_PATH_NODE_FLAG_TELEPORT)))
    {
        TaxiPathEntry const* lastPath = sTaxiPathStore.AssertEntry(_path.back()->PathID);
        if (TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(lastPath->ToTaxiNode))
        {
            owner->SetFallInformation(0, node->Pos.Z);
            owner->TeleportTo(node->ContinentID, node->Pos.X, node->Pos.Y, node->Pos.Z, owner->GetOrientation());
        }
    }

    owner->RemovePlayerFlag(PLAYER_FLAGS_TAXI_BENCHMARK);
}

uint32 FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if (_currentNode >= _path.size())
        return _path.size();

    uint32 curMapId = _path[_currentNode]->ContinentID;
    for (uint32 itr = _currentNode; itr < _path.size(); ++itr)
    {
        if (_path[itr]->ContinentID != curMapId)
            return itr;
        if (itr > 0 && _path[itr - 1]->Flags & TAXI_PATH_NODE_FLAG_TELEPORT)
            return itr;
    }

    return _path.size();
}

bool IsNodeIncludedInShortenedPath(TaxiPathNodeEntry const* p1, TaxiPathNodeEntry const* p2)
{
    return p1->ContinentID != p2->ContinentID
        || std::pow(p1->Loc.X - p2->Loc.X, 2) + std::pow(p1->Loc.Y - p2->Loc.Y, 2) > SKIP_SPLINE_POINT_DISTANCE_SQ
        || p2->Flags & TAXI_PATH_NODE_FLAG_TELEPORT
        || (p2->Flags & TAXI_PATH_NODE_FLAG_STOP && p2->Delay);
}

void FlightPathMovementGenerator::LoadPath(Player* owner, uint32 startNode /*= 0*/)
{
    _path.clear();
    _currentNode = startNode;
    _pointsForPathSwitch.clear();
    std::deque<uint32> const& taxi = owner->m_taxi.GetPath();
    float discount = owner->GetReputationPriceDiscount(owner->m_taxi.GetFlightMasterFactionTemplate());
    for (uint32 src = 0, dst = 1; dst < taxi.size(); src = dst++)
    {
        uint32 path, cost;
        sObjectMgr->GetTaxiPath(taxi[src], taxi[dst], path, cost);
        if (path >= sTaxiPathNodesByPath.size())
            return;

        TaxiPathNodeList const& nodes = sTaxiPathNodesByPath[path];
        if (!nodes.empty())
        {
            TaxiPathNodeEntry const* start = nodes[0];
            TaxiPathNodeEntry const* end = nodes[nodes.size() - 1];
            bool passedPreviousSegmentProximityCheck = false;
            for (uint32 i = 0; i < nodes.size(); ++i)
            {
                if (passedPreviousSegmentProximityCheck || !src || _path.empty() || IsNodeIncludedInShortenedPath(_path.back(), nodes[i]))
                {
                    if ((!src || (IsNodeIncludedInShortenedPath(start, nodes[i]) && i >= 2)) &&
                        (dst == taxi.size() - 1 || (IsNodeIncludedInShortenedPath(end, nodes[i]) && (i < nodes.size() - 1 || _path.empty()))) &&
                        (!(nodes[i]->Flags & TAXI_PATH_NODE_FLAG_TELEPORT) || _path.empty() || !(_path.back()->Flags & TAXI_PATH_NODE_FLAG_TELEPORT))) // skip consecutive teleports, only keep the first one
                    {
                        passedPreviousSegmentProximityCheck = true;
                        _path.push_back(nodes[i]);
                    }
                }
                else
                {
                    _path.pop_back();
                    --_pointsForPathSwitch.back().PathIndex;
                }
            }
        }

        _pointsForPathSwitch.push_back({ uint32(std::max<std::size_t>(_path.size(), 1) - 1), int64(ceil(cost * discount)) });
    }
}

void FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if (_path.empty() || _currentNode >= _path.size())
        return;

    uint32 map0 = _path[_currentNode]->ContinentID;
    for (size_t i = _currentNode + 1; i < _path.size(); ++i)
    {
        if (_path[i]->ContinentID != map0 || _path[i - 1]->Flags & TAXI_PATH_NODE_FLAG_TELEPORT)
        {
            _currentNode = i;
            return;
        }
    }
}

void FlightPathMovementGenerator::DoEventIfAny(Player* owner, TaxiPathNodeEntry const* node, bool departure)
{
    ASSERT(node, "%s", owner->GetDebugInfo().c_str());

    if (uint32 eventid = departure ? node->DepartureEventID : node->ArrivalEventID)
    {
        TC_LOG_DEBUG("maps.script", "FlightPathMovementGenerator::DoEventIfAny: taxi {} event {} of node {} of path {} for player {}", departure ? "departure" : "arrival", eventid, node->NodeIndex, node->PathID, owner->GetName());
        GameEvents::Trigger(eventid, owner, owner);
    }
}

void FlightPathMovementGenerator::InitEndGridInfo()
{
    /*!
     *  Storage to preload flightmaster grid at end of flight. For multi-stop flights, this will
     *  be reinitialized for each flightmaster at the end of each spline (or stop) in the flight.
     */
    uint32 nodeCount = _path.size(); // Number of nodes in path.
    ASSERT(nodeCount, "FlightPathMovementGenerator::InitEndGridInfo() called with empty _path");
    _endMapId = _path[nodeCount - 1]->ContinentID; // MapId of last node
    if (nodeCount < 3)
        _preloadTargetNode = 0;
    else
        _preloadTargetNode = nodeCount - 3;

    while (_path[_preloadTargetNode]->ContinentID != _endMapId)
        ++_preloadTargetNode;

    _endGridX = _path[nodeCount - 1]->Loc.X;
    _endGridY = _path[nodeCount - 1]->Loc.Y;
}

void FlightPathMovementGenerator::PreloadEndGrid(Player* owner)
{
    // Used to preload the final grid where the flightmaster is
    Map* endMap = owner->GetMap();

    // Load the grid
    if (endMap)
    {
        TC_LOG_DEBUG("movement.flightpath", "FlightPathMovementGenerator::PreloadEndGrid: preloading grid ({}, {}) for map {} at node index {}/{}", _endGridX, _endGridY, _endMapId, _preloadTargetNode, uint32(_path.size() - 1));
        endMap->LoadGrid(_endGridX, _endGridY);
    }
    else
        TC_LOG_DEBUG("movement.flightpath", "FlightPathMovementGenerator::PreloadEndGrid: unable to determine map to preload flightmaster grid");
}

uint32 FlightPathMovementGenerator::GetPathId(size_t index) const
{
    if (index >= _path.size())
        return 0;

    return _path[index]->PathID;
}

std::string FlightPathMovementGenerator::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << PathMovementBase::GetDebugInfo() << "\n"
        << MovementGeneratorMedium::GetDebugInfo() << "\n"
        << "Start Path Id: " << GetPathId(0)
        << " Path Size: " << _path.size()
        << " HasArrived: " << HasArrived()
        << " End Grid X: " << _endGridX
        << " End Grid Y: " << _endGridY
        << " End Map Id: " << _endMapId
        << " Preloaded Target Node: " << _preloadTargetNode;
    return sstr.str();
}
