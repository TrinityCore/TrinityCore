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
#include "Errors.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"
#include <sstream>

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(uint32 pathId, bool repeating) : _lastSplineId(0), _pathId(pathId), _waypointDelay(0), _pauseTime(0),
_waypointReached(true), _recalculateSpeed(false), _repeating(repeating), _loadedFromDB(true), _stalled(false), _hasBeenStalled(false), _done(false)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(WaypointPath& path, bool repeating) : _lastSplineId(0), _pathId(0), _waypointDelay(0), _pauseTime(0),
_waypointReached(true), _recalculateSpeed(false), _repeating(repeating), _loadedFromDB(false), _stalled(false), _hasBeenStalled(false), _done(false)
{
    _path = &path;

    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

MovementGeneratorType WaypointMovementGenerator<Creature>::GetMovementGeneratorType() const
{
    return WAYPOINT_MOTION_TYPE;
}

bool WaypointMovementGenerator<Creature>::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
{
    // Prevent a crash at empty waypoint path.
    if (!_path || _path->Nodes.empty())
        return false;

    ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::GetResetPosition: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);

    x = waypoint.X;
    y = waypoint.Y;
    z = waypoint.Z;
    return true;
}

void WaypointMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    _done = false;

    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (_loadedFromDB)
    {
        if (!_pathId)
            _pathId = owner->GetWaypointPath();

        _path = sWaypointMgr->GetPath(_pathId);
    }

    if (!_path)
    {
        // No path id found for entry.
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::DoInitialize: couldn't load path for creature (%s) (_pathId: %u)", owner->GetGUID().ToString().c_str(), _pathId);
        return;
    }

    // Determine our first waypoint that we want to approach.
    if (CreatureData const* creatureData = owner->GetCreatureData())
    {
        if (_path->Nodes.size() > creatureData->currentwaypoint)
        {
            owner->UpdateCurrentWaypointInfo(creatureData->currentwaypoint, _path->Id);
            _currentNode = creatureData->currentwaypoint;
        }
    }

    // Inform AI.
    if (CreatureAI* AI = owner->AI())
        AI->WaypointPathStarted(_path->Id);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    // We did not reach our last waypoint before reset, treat this scenario as resuming movement.
    if (!_done && !_waypointReached)
        _hasBeenStalled = true;
    else if (_done)
    {
        // Mimic IdleMovementGenerator.
        if (!owner->IsStopped())
            owner->StopMoving();
    }
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 diff)
{
    // Creature has died. Do not update anymore.
    if (!owner || !owner->IsAlive())
        return true;

    // The creature has completed its waypoint path or the path is no longer available.
    if (_done || !_path || _path->Nodes.empty())
        return true;

    // Creature is not moving but has a delay between the current and the next delay.
    if (owner->movespline->Finalized())
        if (_waypointDelay > 0)
            _waypointDelay -= diff;

    // Creature's movement has been paused.
    if (_pauseTime > 0)
        _pauseTime -= diff;

    // Creature cannot move at the moment. Stop movement and hold further updates until the creature can move again.
    if (!IsAllowedToMove(owner))
    {
        _hasBeenStalled = !_waypointReached;
        owner->StopMoving();
        return true;
    }

    // There is no way that this should ever happen, but just in case.
    if (_path->Nodes.size() - 1 < _currentNode)
        return true;

    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);

    // Basic check for launching a new spline. Creature is no longer moving or is about to smoothly transition from one spline to another.
    bool shouldLaunchNextSpline = [&]()
    {
        if (owner->movespline->Finalized())
            return true;

        if (waypoint.SmoothTransition && owner->movespline->MaxPathIdx() >= 1 && owner->movespline->currentPathIdx() >= owner->movespline->MaxPathIdx() - 1)
            return true;

        return false;
    }();

    // Inform AI hooks that we have arrived at our transition point.
    if (shouldLaunchNextSpline && !_waypointReached && !_hasBeenStalled)
        ProcessWaypointArrival(owner, waypoint);

    // Waypoint is a one-way path and has been completed. No further actions needed.
    if (_done)
        return true;

    bool hasToRelaunchSpline = _hasBeenStalled || _recalculateSpeed;

    // Creature cannot launch a new spline yet. There is still a delay that needs to expire.
    if (!hasToRelaunchSpline && _waypointDelay > 0)
        return true;

    if (shouldLaunchNextSpline || hasToRelaunchSpline)
        StartMove(owner, hasToRelaunchSpline);

    // Set home position to current position.
    if (!owner->movespline->Finalized())
        if (owner->GetTransGUID().IsEmpty())
            owner->SetHomePosition(owner->GetPosition());

    return true;
}

void WaypointMovementGenerator<Creature>::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool /*movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        owner->SetWalk(false);
    }
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

bool WaypointMovementGenerator<Creature>::IsAllowedToMove(Creature* owner)
{
    return (!_stalled && _pauseTime <= 0 && !owner->HasUnitState(UNIT_STATE_NOT_MOVE) && !owner->IsMovementPreventedByCasting());
}

void WaypointMovementGenerator<Creature>::ProcessWaypointArrival(Creature* owner, WaypointNode const& waypoint)
{
    if (!_path || _path->Nodes.empty())
        return;

    if (waypoint.Delay > 0)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    bool const useTransportPath = !owner->GetTransGUID().IsEmpty();

    // Check if the waypoint path has reached its end and may not repeat. Inform AI and update home position.
    if ((_currentNode == _path->Nodes.size() - 1) && !_repeating && !_done)
    {
        WaypointNode const& waypoint = _path->Nodes.at(_currentNode);
        float x = waypoint.X;
        float y = waypoint.Y;
        float z = waypoint.Z;
        float o = owner->GetOrientation();

        if (!useTransportPath)
            owner->SetHomePosition(x, y, z, o);
        else
        {
            if (TransportBase* trans = owner->GetTransport())
            {
                o -= trans->GetTransportOrientation();
                owner->SetTransportHomePosition(x, y, z, o);
                trans->CalculatePassengerPosition(x, y, z, &o);
                owner->SetHomePosition(x, y, z, o);
            }
        }

        _done = true;
        owner->UpdateCurrentWaypointInfo(0, 0);

        // Inform AI that the path has ended.
        if (CreatureAI* AI = owner->AI())
            AI->WaypointPathEnded(waypoint.Id, _path->Id);
    }

    if (waypoint.EventId && urand(0, 99) < waypoint.EventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.EventId, _currentNode, owner->GetGUID().ToString().c_str());
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        owner->GetMap()->ScriptsStart(sWaypointScripts, waypoint.EventId, owner, nullptr);
    }

    owner->UpdateCurrentWaypointInfo(waypoint.Id, _path->Id);

    // Inform AI.
    if (CreatureAI* AI = owner->AI())
    {
        AI->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
        AI->WaypointReached(waypoint.Id, _path->Id);
    }

    // All hooks called and infos updated. Time to increment the waypoint nodeId.
    if (_path && !_path->Nodes.empty()) // Ensure that the path has not been changed in one of the hooks.
        _currentNode = (_currentNode + 1) % _path->Nodes.size();

    _waypointReached = true;
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* owner, bool relaunch /*= false*/)
{
    // Formation checks. Do not launch a new spline when one of our formation members is currently in combat.
    if (!relaunch)
    {
        if (!IsAllowedToMove(owner) || (owner->IsFormationLeader() && !owner->IsFormationLeaderMoveAllowed()))
        {
            _waypointDelay = 1000;
            return;
        }
    }

    // Now that node selection is done, we build spline data.
    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);
    WaypointNode const& waypoint = _path->Nodes.at(_currentNode);
    bool const useTransportPath = !owner->GetTransGUID().IsEmpty();

    Movement::MoveSplineInit init(owner);
    // If the creature is on transport, we assume waypoints set in DB are already transport offsets.
    if (useTransportPath)
        init.DisableTransportPathTransformations();

    // Determining if we have pre-set spline points in database. Use database data when present, otherwise do own calculations (custom and legacy support).
    if (!waypoint.SplinePoints.empty())
    {
        // We have spline points in waypoint_data_addon table so instead of calculating a path, we append the db side spline points and run that one instead.
        int32 splineIndex = 0;

        std::vector<G3D::Vector3>::const_iterator itr = waypoint.SplinePoints.begin();
        if (splineIndex)
            std::advance(itr, splineIndex);

        init.Path().reserve(waypoint.SplinePoints.size() - splineIndex);
        std::copy(itr, waypoint.SplinePoints.end(), std::back_inserter(init.Path()));

        // Spline points are appended. Now add our starting vertex and destination to the path and we're good to go.
        init.Path().insert(init.Path().begin(), PositionToVector3(owner->GetPosition()));
        init.Path().insert(init.Path().end(), PositionToVector3({ waypoint.X, waypoint.Y, waypoint.Z }));
    }
    else
    {
        // We have no db spline points, so we are going to fall back to default waypoint behaivior.
        if (waypoint.SmoothTransition && !owner->movespline->Finalized() && _lastSplineId == owner->movespline->GetId())
        {
            // We are still running our previous waypoint spline. Use its final destination as starting point for our next path.
            init.MoveTo(owner->movespline->FinalDestination(), PositionToVector3({ waypoint.X, waypoint.Y, waypoint.Z }));
            if (!init.Path().empty())
                init.Path().insert(init.Path().begin(), PositionToVector3(owner->GetPosition()));
        }
        else
            init.MoveTo(waypoint.X, waypoint.Y, waypoint.Z);
    }

    if (waypoint.Orientation.has_value() && waypoint.Delay > 0)
        init.SetFacing(*waypoint.Orientation);

    switch (waypoint.MoveType)
    {
        case WAYPOINT_MOVE_TYPE_LAND:
            init.SetAnimation(AnimTier::Ground);
            break;
        case WAYPOINT_MOVE_TYPE_TAKEOFF:
            init.SetAnimation(AnimTier::Hover);
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

    if (owner->CanFly())
    {
        init.SetFly();
        init.SetSmooth();
        init.SetUncompressed();
    }

    if (waypoint.Velocity > 0.f)
        init.SetVelocity(waypoint.Velocity);

    init.Launch();
    _waypointDelay = waypoint.Delay;

    if (!owner->movespline->Finalized())
        _lastSplineId = owner->movespline->GetId();

    // Inform formation.
    owner->SignalFormationMovement();

    // Inform AI.
    if (!relaunch)
        if (CreatureAI* AI = owner->AI())
            AI->WaypointStarted(waypoint.Id, _path->Id);

    _waypointReached = false;
    _recalculateSpeed = false;
    _hasBeenStalled = false;
}

std::string WaypointMovementGenerator<Creature>::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << PathMovementBase::GetDebugInfo() << "\n"
        << MovementGeneratorMedium::GetDebugInfo();
    return sstr.str();
}
