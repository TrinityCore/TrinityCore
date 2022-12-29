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
#include "DBCStores.h"
#include "GameEventSender.h"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Player.h"

 //----------------------------------------------------//

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
}

uint32 FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if (_currentNode >= _path.size())
        return _path.size();

    uint32 curMapId = _path[_currentNode]->ContinentID;
    for (uint32 itr = _currentNode; itr < _path.size(); ++itr)
        if (_path[itr]->ContinentID != curMapId)
            return itr;

    return _path.size();
}

bool IsNodeIncludedInShortenedPath(TaxiPathNodeEntry const* p1, TaxiPathNodeEntry const* p2)
{
    return p1->ContinentID != p2->ContinentID || std::pow(p1->Loc.X - p2->Loc.X, 2) + std::pow(p1->Loc.Y - p2->Loc.Y, 2) > SKIP_SPLINE_POINT_DISTANCE_SQ;
}

void FlightPathMovementGenerator::LoadPath(Player* player)
{
    _pointsForPathSwitch.clear();
    std::deque<uint32> const& taxi = player->m_taxi.GetPath();
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

        _pointsForPathSwitch.push_back({ uint32(_path.size() - 1), int32(cost) });
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

    uint32 taxiNodeId = player->m_taxi.GetTaxiDestination();
    player->m_taxi.ClearTaxiDestinations();
    player->Dismount();
    player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    if (player->m_taxi.empty())
    {
        // update z position to ground and orientation for landing point
        // this prevent cheating with landing  point at lags
        // when client side flight end early in comparison server side
        player->StopMoving();

        // When the player reaches the last flight point, teleport to taxi node location
        if (TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(taxiNodeId))
        {
            player->SetFallInformation(0, node->Pos.Z);
            player->TeleportTo(node->ContinentID, node->Pos.X, node->Pos.Y, node->Pos.Z, player->GetOrientation());
        }
    }

    player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);
}

void FlightPathMovementGenerator::DoReset(Player* player)
{
    player->AddUnitState(UNIT_STATE_IN_FLIGHT);
    player->CombatStopWithPets();
    player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_TAXI_FLIGHT);

    uint32 end = GetPathAtMapEnd();
    uint32 currentNodeId = GetCurrentNode();

    if (currentNodeId == end)
    {
        TC_LOG_DEBUG("movement.flightpath", "FlightPathMovementGenerator::DoReset: trying to start a flypath from the end points.");
        return;
    }

    Movement::MoveSplineInit init(player);
    // Providing an starting vertex since the taxi paths do not provide such
    init.Path().push_back(G3D::Vector3(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()));
    for (uint32 i = currentNodeId; i != end; ++i)
    {
        G3D::Vector3 vertice(_path[i]->Loc.X, _path[i]->Loc.Y, _path[i]->Loc.Z);
        init.Path().push_back(vertice);
    }
    init.SetFirstPointId(GetCurrentNode());
    init.SetFly();
    init.SetWalk(true);
    init.SetSmooth();
    init.SetUncompressed();
    init.SetVelocity(PLAYER_FLIGHT_SPEED);
    init.Launch();
}

bool FlightPathMovementGenerator::DoUpdate(Player* player, uint32 /*diff*/)
{
    // skipping the first spline path point because it's our starting point and not a taxi path point
    uint32 pointId = player->movespline->currentPathIdx() <= 0 ? 0 : player->movespline->currentPathIdx() - 1;
    if (pointId > _currentNode && _currentNode < _path.size() - 1)
    {
        bool departureEvent = true;
        do
        {
            DoEventIfAny(player, _path[_currentNode], departureEvent);
            while (!_pointsForPathSwitch.empty() && _pointsForPathSwitch.front().PathIndex <= _currentNode)
            {
                _pointsForPathSwitch.pop_front();
                player->m_taxi.NextTaxiDestination();
                if (!_pointsForPathSwitch.empty())
                {
                    player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING, _pointsForPathSwitch.front().Cost);
                    player->ModifyMoney(-_pointsForPathSwitch.front().Cost);
                }
            }

            if (pointId == _currentNode)
                break;

            if (_currentNode == _preloadTargetNode)
                PreloadEndGrid(player);
            _currentNode += departureEvent ? 1 : 0;
            departureEvent = !departureEvent;
        } while (_currentNode < _path.size() - 1);
    }

    return _currentNode < (_path.size() - 1);
}

void FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if (_path.empty() || _currentNode >= _path.size())
        return;

    uint32 map0 = _path[_currentNode]->ContinentID;
    for (size_t i = _currentNode + 1; i < _path.size(); ++i)
    {
        if (_path[i]->ContinentID != map0)
        {
            _currentNode = i;
            return;
        }
    }
}

void FlightPathMovementGenerator::DoEventIfAny(Player* player, TaxiPathNodeEntry const* node, bool departure)
{
    if (uint32 eventid = departure ? node->DepartureEventID : node->ArrivalEventID)
    {
        TC_LOG_DEBUG("maps.script", "Taxi %s event %u of node %u of path %u for player %s", departure ? "departure" : "arrival", eventid, node->NodeIndex, node->PathID, player->GetName().c_str());
        GameEvents::Trigger(eventid, player, player);
    }
}

bool FlightPathMovementGenerator::GetResetPos(Player*, float& x, float& y, float& z)
{
    TaxiPathNodeEntry const* node = _path[_currentNode];
    x = node->Loc.X;
    y = node->Loc.Y;
    z = node->Loc.Z;
    return true;
}

void FlightPathMovementGenerator::InitEndGridInfo()
{
    /*! Storage to preload flightmaster grid at end of flight. For multi-stop flights, this will
    be reinitialized for each flightmaster at the end of each spline (or stop) in the flight. */
    uint32 nodeCount = _path.size();        //! Number of nodes in path.
    _endMapId = _path[nodeCount - 1]->ContinentID; //! MapId of last node
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
        TC_LOG_DEBUG("misc", "Preloading rid (%f, %f) for map %u at node index %u/%u", _endGridX, _endGridY, _endMapId, _preloadTargetNode, (uint32)(_path.size() - 1));
        endMap->LoadGrid(_endGridX, _endGridY);
    }
    else
        TC_LOG_DEBUG("misc", "Unable to determine map to preload flightmaster grid");
}
