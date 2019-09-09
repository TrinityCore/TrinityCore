/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "DBCStores.h"
#include "Log.h"
#include "MapManager.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Player.h"

#define FLIGHT_TRAVEL_UPDATE 100
#define TIMEDIFF_NEXT_WP 250
#define SKIP_SPLINE_POINT_DISTANCE_SQ (40.f * 40.f)
#define PLAYER_FLIGHT_SPEED 32.0f

FlightPathMovementGenerator::FlightPathMovementGenerator(uint32 startNode)
{
    _currentNode = startNode;
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
    x = node->LocX;
    y = node->LocY;
    z = node->LocZ;
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
    owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    Movement::MoveSplineInit init(owner);
    uint32 end = GetPathAtMapEnd();
    for (uint32 i = GetCurrentNode(); i != end; ++i)
    {
        G3D::Vector3 vertice(_path[i]->LocX, _path[i]->LocY, _path[i]->LocZ);
        init.Path().push_back(vertice);
    }
    init.SetFirstPointId(GetCurrentNode());
    init.SetFly();
    init.SetVelocity(PLAYER_FLIGHT_SPEED);
    init.Launch();
}

bool FlightPathMovementGenerator::DoUpdate(Player* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    uint32 pointId = owner->movespline->currentPathIdx() < 0 ? 0 : owner->movespline->currentPathIdx();
    if (pointId > _currentNode && _currentNode < _path.size())
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
                    owner->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, _pointsForPathSwitch.front().Cost);
                    owner->ModifyMoney(-_pointsForPathSwitch.front().Cost);
                }
            }

            if (pointId == _currentNode)
                break;

            if (_currentNode == _preloadTargetNode)
                PreloadEndGrid();

            _currentNode += departureEvent ? 1 : 0;
            departureEvent = !departureEvent;
        } while (_currentNode < _path.size());
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
    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    if (owner->m_taxi.empty())
    {
        // update z position to ground and orientation for landing point
        // this prevent cheating with landing point at lags
        // when client side flight end early in comparison server side
        owner->StopMoving();
        float mapHeight = owner->GetMap()->GetHeight(_path[GetCurrentNode()]->LocX, _path[GetCurrentNode()]->LocY, _path[GetCurrentNode()]->LocZ);
        owner->SetFallInformation(0, mapHeight);
        // When the player reaches the last flight point, teleport to destination at map height
        owner->TeleportTo(_path[GetCurrentNode()]->MapID, _path[GetCurrentNode()]->LocX, _path[GetCurrentNode()]->LocY, mapHeight, owner->GetOrientation());
    }

    owner->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);
}

uint32 FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if (_currentNode >= _path.size())
        return _path.size();

    uint32 curMapId = _path[_currentNode]->MapID;
    for (uint32 itr = _currentNode; itr < _path.size(); ++itr)
    {
        if (_path[itr]->MapID != curMapId)
            return itr;
    }

    return _path.size();
}

bool IsNodeIncludedInShortenedPath(TaxiPathNodeEntry const* p1, TaxiPathNodeEntry const* p2)
{
    return p1->MapID != p2->MapID || std::pow(p1->LocX - p2->LocX, 2) + std::pow(p1->LocY - p2->LocY, 2) > SKIP_SPLINE_POINT_DISTANCE_SQ;
}

void FlightPathMovementGenerator::LoadPath(Player* owner)
{
    _pointsForPathSwitch.clear();
    std::deque<uint32> const& taxi = owner->m_taxi.GetPath();
    float discount = owner->GetReputationPriceDiscount(owner->m_taxi.GetFlightMasterFactionTemplate());
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
                if (passedPreviousSegmentProximityCheck || !src || _path.empty() || IsNodeIncludedInShortenedPath(_path[_path.size() - 1], nodes[i]))
                {
                    if ((!src || (IsNodeIncludedInShortenedPath(start, nodes[i]) && i >= 2)) &&
                        (dst == taxi.size() - 1 || (IsNodeIncludedInShortenedPath(end, nodes[i]) && i < nodes.size() - 1)))
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

        _pointsForPathSwitch.push_back({ uint32(_path.size() - 1), int32(ceil(cost * discount)) });
    }
}

void FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if (_path.empty() || _currentNode >= _path.size())
        return;

    uint32 map0 = _path[_currentNode]->MapID;
    for (size_t i = _currentNode + 1; i < _path.size(); ++i)
    {
        if (_path[i]->MapID != map0)
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
        TC_LOG_DEBUG("maps.script", "FlightPathMovementGenerator::DoEventIfAny: taxi %s event %u of node %u of path %u for player %s", departure ? "departure" : "arrival", eventid, node->NodeIndex, node->PathID, owner->GetName().c_str());
        owner->GetMap()->ScriptsStart(sEventScripts, eventid, owner, owner);
    }
}

void FlightPathMovementGenerator::InitEndGridInfo()
{
    /*!
     *  Storage to preload flightmaster grid at end of flight. For multi-stop flights, this will
     *  be reinitialized for each flightmaster at the end of each spline (or stop) in the flight.
     */
    uint32 nodeCount = _path.size(); //! Number of nodes in path.
    ASSERT(nodeCount, "FlightPathMovementGenerator::InitEndGridInfo() called with empty _path");
    _endMapId = _path[nodeCount - 1]->MapID; //! MapId of last node
    if (nodeCount < 3)
        _preloadTargetNode = 0;
    else
        _preloadTargetNode = nodeCount - 3;
    _endGridX = _path[nodeCount - 1]->LocX;
    _endGridY = _path[nodeCount - 1]->LocY;
}

void FlightPathMovementGenerator::PreloadEndGrid()
{
    // Used to preload the final grid where the flightmaster is
    Map* endMap = sMapMgr->FindBaseNonInstanceMap(_endMapId);

    // Load the grid
    if (endMap)
    {
        TC_LOG_DEBUG("movement.flightpath", "FlightPathMovementGenerator::PreloadEndGrid: preloading grid (%f, %f) for map %u at node index %u/%u", _endGridX, _endGridY, _endMapId, _preloadTargetNode, uint32(_path.size() - 1));
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
