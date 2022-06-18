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

#include "WaypointMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(uint32 pathId, bool repeating) : _lastSplineId(0), _pathId(pathId), _waypointDelay(0), _pauseTime(0),
_waypointReached(true), _recalculateSpeed(false), _repeating(repeating), _loadedFromDB(true), _stalled(false), _hasBeenStalled(false), _done(false)
{
}

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(WaypointPath& path, bool repeating) : _lastSplineId(0), _pathId(0), _waypointDelay(0), _pauseTime(0),
_waypointReached(true), _recalculateSpeed(false), _repeating(repeating), _loadedFromDB(false), _stalled(false), _hasBeenStalled(false), _done(false)
{
    _path = &path;
}

void WaypointMovementGenerator<Creature>::DoInitialize(Creature* creature)
{
    _done = false;

    if (_loadedFromDB)
    {
        if (!_pathId)
            _pathId = creature->GetWaypointPath();

        _path = sWaypointMgr->GetPath(_pathId);
    }

    if (!_path)
    {
        // No path id found for entry
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::DoInitialize: creature %s (Entry: %u GUID: %u DB GUID: %u) doesn't have waypoint path id: %u", creature->GetName().c_str(), creature->GetEntry(), creature->GetGUID().GetCounter(), creature->GetSpawnId(), _pathId);
        return;
    }

    // Determine our first waypoint that we want to approach.
    if (CreatureData const* creatureData = creature->GetCreatureData())
    {
        if (_path->Nodes.size() > creatureData->currentwaypoint)
        {
            creature->UpdateCurrentWaypointInfo(creatureData->currentwaypoint, _path->Id);
            _currentNode = creatureData->currentwaypoint;
        }
    }

    // inform AI
    if (CreatureAI* AI = creature->AI())
        AI->WaypointPathStarted(_path->Id);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* creature)
{
    creature->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
    creature->SetWalk(false);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* creature)
{
    // We did not reach our last waypoint before reset, treat this scenario as resuming movement.
    if (!_done && !_waypointReached)
        _hasBeenStalled = true;
    else if (_done)
    {
        // mimic IdleMovementGenerator
        if (!creature->IsStopped())
            creature->StopMoving();
    }
}

void WaypointMovementGenerator<Creature>::ProcessWaypointArrival(Creature* creature, WaypointNode const& waypoint)
{
    if (!_path || _path->Nodes.empty())
        return;

    if (waypoint.Delay > 0)
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    bool const useTransportPath = !creature->GetTransGUID().IsEmpty();

    // Check if the waypoint path has reached its end and may not repeat. Inform AI and update home position.
    if ((_currentNode == _path->Nodes.size() - 1) && !_repeating && !_done)
    {
        WaypointNode const& waypoint = _path->Nodes.at(_currentNode);
        float x = waypoint.X;
        float y = waypoint.Y;
        float z = waypoint.Z;
        float o = creature->GetOrientation();

        if (!useTransportPath)
            creature->SetHomePosition(x, y, z, o);
        else
        {
            if (TransportBase* trans = creature->GetTransport())
            {
                o -= trans->GetTransportOrientation();
                creature->SetTransportHomePosition(x, y, z, o);
                trans->CalculatePassengerPosition(x, y, z, &o);
                creature->SetHomePosition(x, y, z, o);
            }
        }

        _done = true;
        creature->UpdateCurrentWaypointInfo(0, 0);

        // Inform the AI that the path has ended.
        if (CreatureAI* AI = creature->AI())
            AI->WaypointPathEnded(waypoint.Id, _path->Id);
    }

    if (waypoint.EventId && urand(0, 99) < waypoint.EventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.EventId, _currentNode, creature->GetGUID().ToString().c_str());
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        creature->GetMap()->ScriptsStart(sWaypointScripts, waypoint.EventId, creature, nullptr);
    }

    creature->UpdateCurrentWaypointInfo(waypoint.Id, _path->Id);

    // inform AI
    if (CreatureAI* AI = creature->AI())
    {
        AI->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
        AI->WaypointReached(waypoint.Id, _path->Id);
    }

    // All hooks called and infos updated. Time to increment the waypoint node id
    if (_path && !_path->Nodes.empty()) // ensure that the path has not been changed in one of the hooks.
        _currentNode = (_currentNode + 1) % _path->Nodes.size();

    _waypointReached = true;
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* creature, bool relaunch /*= false*/)
{
    // Formation checks. Do not launch a new spline when one of our formation members is currently in combat.
    if (!relaunch)
    {
        if (!IsAllowedToMove(creature) || (creature->IsFormationLeader() && !creature->IsFormationLeaderMoveAllowed()))
        {
            _waypointDelay = 1000;
            return;
        }
    }

    // Step two: node selection is done, build spline data
    creature->AddUnitState(UNIT_STATE_ROAMING_MOVE);
    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);
    bool const useTransportPath = !creature->GetTransGUID().IsEmpty();

    Movement::MoveSplineInit init(creature);
    //! If the creature is on transport, we assume waypoints set in DB are already transport offsets
    if (useTransportPath)
        init.DisableTransportPathTransformations();

    // Determining if we have pre-set spline points in database. Use database data when present, otherwise do own calculations (custom and legacy support)
    if (!waypoint.SplinePoints.empty())
    {
        // We have spline points in waypoint_data_addon table so instead of calculating a path, we append the db side spline points and run that one instead.
        int32 splineIndex = 0;

        std::vector<G3D::Vector3>::const_iterator itr = waypoint.SplinePoints.begin();
        if (splineIndex)
            std::advance(itr, splineIndex);

        init.Path().reserve(waypoint.SplinePoints.size() - splineIndex);
        std::copy(itr, waypoint.SplinePoints.end(), std::back_inserter(init.Path()));

        // Spline points are appended, now add our starting vertex and destination to the path and we're good to go.
        init.Path().insert(init.Path().begin(), PositionToVector3(creature->GetPosition()));
        init.Path().insert(init.Path().end(), PositionToVector3({ waypoint.X, waypoint.Y, waypoint.Z }));
    }
    else
    {
        // We have no db spline points, so we are going to fall back to default waypoint behaivior.
        if (waypoint.SmoothTransition && !creature->movespline->Finalized() && _lastSplineId == creature->movespline->GetId())
        {
            // We are still running our previous waypoint spline. Use its final destination as starting point for our next path.
            init.MoveTo(creature->movespline->FinalDestination(), PositionToVector3({ waypoint.X, waypoint.Y, waypoint.Z }));
            if (!init.Path().empty())
                init.Path().insert(init.Path().begin(), PositionToVector3(creature->GetPosition()));
        }
        else
            init.MoveTo(waypoint.X, waypoint.Y, waypoint.Z);
    }

    if (waypoint.Orientation.has_value() && waypoint.Delay > 0)
        init.SetFacing(*waypoint.Orientation);

    switch (waypoint.MoveType)
    {
        case WAYPOINT_MOVE_TYPE_LAND:
            init.SetAnimation(AnimationTier::Ground);
            break;
        case WAYPOINT_MOVE_TYPE_TAKEOFF:
            init.SetAnimation(AnimationTier::Hover);
            break;
        case WAYPOINT_MOVE_TYPE_RUN:
            init.SetWalk(false);
            break;
        case WAYPOINT_MOVE_TYPE_WALK:
            init.SetWalk(true);
            break;
        default:
            break;
    }

    if (creature->CanFly())
    {
        init.SetFly();
        init.SetSmooth();
        init.SetUncompressed();
    }

    if (waypoint.Velocity > 0.f)
        init.SetVelocity(waypoint.Velocity);

    init.Launch();
    _waypointDelay = waypoint.Delay;

    if (!creature->movespline->Finalized())
        _lastSplineId = creature->movespline->GetId();

    // Inform formation
    creature->SignalFormationMovement();

    // Inform AI
    if (!relaunch)
        if (CreatureAI* AI = creature->AI())
            AI->WaypointStarted(waypoint.Id, _path->Id);

    _waypointReached = false;
    _recalculateSpeed = false;
    _hasBeenStalled = false;
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* creature, uint32 diff)
{
    // Creature has died. Do not update anymore.
    if (!creature || !creature->IsAlive())
        return true;

    // The creature has completed its waypoint path or the path is no longer available.
    if (_done || !_path || _path->Nodes.empty())
        return true;

    // Creature is not moving but has a delay between the current and the next delay.
    if (creature->movespline->Finalized())
        if (_waypointDelay > 0)
            _waypointDelay -= diff;

    // Creature's movement has been paused.
    if (_pauseTime > 0)
        _pauseTime -= diff;

    // Creature cannot move at the moment. Stop movement and hold further updates until the creature can move again.
    if (!IsAllowedToMove(creature))
    {
        _hasBeenStalled = !_waypointReached;
        creature->StopMoving();
        return true;
    }

    // There is no way that this should ever happen but just in case
    if (_path->Nodes.size() - 1 < _currentNode)
        return true;

    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);

    // Basic check for launching a new spline. Creature is no longer moving or is about to smoothly transition from one spline to another
    bool shouldLaunchNextSpline = [&]()
    {
        if (creature->movespline->Finalized())
            return true;

        if (waypoint.SmoothTransition && creature->movespline->MaxPathIdx() >= 1 && creature->movespline->currentPathIdx() >= creature->movespline->MaxPathIdx() - 1)
            return true;

        return false;
    }();

    // Inform AI hooks that we have arrived at our transition point
    if (shouldLaunchNextSpline && !_waypointReached && !_hasBeenStalled)
        ProcessWaypointArrival(creature, waypoint);

    // Waypoint is a one-way path and has been completed. No further actions needed.
    if (_done)
        return true;

    bool hasToRelaunchSpline = _hasBeenStalled || _recalculateSpeed;

    // Creature cannot launch a new spline yet. There is still a delay that needs to expire.
    if (!hasToRelaunchSpline && _waypointDelay > 0)
        return true;

    if (shouldLaunchNextSpline || hasToRelaunchSpline)
        StartMove(creature, hasToRelaunchSpline);

    // Set home position to current position.
    if (!creature->movespline->Finalized())
        if (creature->GetTransGUID().IsEmpty())
            creature->SetHomePosition(creature->GetPosition());

    return true;
}

void WaypointMovementGenerator<Creature>::Pause(uint32 timer /*= 0*/)
{
    _stalled = timer ? false : true;
    _hasBeenStalled = !_waypointReached;
    _pauseTime = timer;
}

void WaypointMovementGenerator<Creature>::Resume(uint32 overrideTimer /*= 0*/)
{
    _hasBeenStalled = !_waypointReached;
    _stalled = false;
    if (overrideTimer)
        _pauseTime = overrideTimer;
}

bool WaypointMovementGenerator<Creature>::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    if (!_path || _path->Nodes.empty())
        return false;

    ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::GetResetPos: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);

    x = waypoint.X;
    y = waypoint.Y;
    z = waypoint.Z;
    return true;
}

bool WaypointMovementGenerator<Creature>::IsAllowedToMove(Creature* creature)
{
    return (!_stalled && _pauseTime <= 0 && !creature->HasUnitState(UNIT_STATE_NOT_MOVE) && !creature->IsMovementPreventedByCasting());
}
