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
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(uint32 pathId, bool repeating) : _nextMoveTime(0), _recalculateSpeed(false), _isArrivalDone(false), _pathId(pathId),
_repeating(repeating), _loadedFromDB(true), _stalled(false), _done(false)
{
}

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(WaypointPath& path, bool repeating) : _nextMoveTime(0), _recalculateSpeed(false), _isArrivalDone(false), _pathId(0),
_repeating(repeating), _loadedFromDB(false), _stalled(false), _done(false)
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

    _nextMoveTime.Reset(1000);

    // inform AI
    if (creature->IsAIEnabled)
        creature->AI()->WaypointPathStarted(_path->Id);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* creature)
{
    creature->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
    creature->SetWalk(false);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* creature)
{
    if (!_done && _nextMoveTime.Passed() && CanMove(creature))
        StartMove(creature);
    else if (_done)
    {
        // mimic IdleMovementGenerator
        if (!creature->IsStopped())
            creature->StopMoving();
    }
}

void WaypointMovementGenerator<Creature>::OnArrived(Creature* creature)
{
    if (!_path || _path->Nodes.empty())
        return;

    ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::OnArrived: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
    WaypointNode const &waypoint = _path->Nodes.at(_currentNode);
    if (waypoint.Delay)
    {
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        _nextMoveTime.Reset(waypoint.Delay);
    }

    if (waypoint.EventId && urand(0, 99) < waypoint.EventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.EventId, _currentNode, creature->GetGUID().ToString().c_str());
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        creature->GetMap()->ScriptsStart(sWaypointScripts, waypoint.EventId, creature, nullptr);
    }

    // inform AI
    if (creature->IsAIEnabled)
    {
        creature->AI()->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
        creature->AI()->WaypointReached(waypoint.Id, _path->Id);
    }

    creature->UpdateCurrentWaypointInfo(waypoint.Id, _path->Id);
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* creature, bool relaunch/* = false*/)
{
    // sanity checks
    if (!creature || !creature->IsAlive() || _done || !_path || _path->Nodes.empty() || (relaunch && _isArrivalDone))
        return;

    if (!relaunch)  // on relaunch, can avoid this since its only called on valid movement
    {
        if (!CanMove(creature) || (creature->IsFormationLeader() && !creature->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
        {
            _nextMoveTime.Reset(1000); // delay 1s
            return;
        }
    }

    bool transportPath = !creature->GetTransGUID().IsEmpty();

    if (_isArrivalDone)
    {
        ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
        WaypointNode const &waypoint = _path->Nodes.at(_currentNode);

        if ((_currentNode == _path->Nodes.size() - 1) && !_repeating) // If that's our last waypoint
        {
            float x = waypoint.X;
            float y = waypoint.Y;
            float z = waypoint.Z;
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
            _done = true;
            creature->UpdateCurrentWaypointInfo(0, 0);

            // inform AI
            if (creature->IsAIEnabled)
                creature->AI()->WaypointPathEnded(waypoint.Id, _path->Id);
            return;
        }

        _currentNode = (_currentNode + 1) % _path->Nodes.size();

        // inform AI
        if (creature->IsAIEnabled)
            creature->AI()->WaypointStarted(waypoint.Id, _path->Id);
    }

    ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
    WaypointNode const &waypoint = _path->Nodes[_currentNode];

    _isArrivalDone = false;
    _recalculateSpeed = false;

    creature->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(creature);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
        init.DisableTransportPathTransformations();

    //! Do not use formationDest here, MoveTo requires transport offsets due to DisableTransportPathTransformations() call
    //! but formationDest contains global coordinates
    init.MoveTo(waypoint.X, waypoint.Y, waypoint.Z);

    //! Accepts angles such as 0.00001 and -0.00001, 0 must be ignored, default value in waypoint table
    if (waypoint.Orientation && waypoint.Delay)
        init.SetFacing(waypoint.Orientation);

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

    if (waypoint.Velocity > 0.f)
        init.SetVelocity(waypoint.Velocity);

    init.Launch();

    // inform formation
    creature->SignalFormationMovement();

    return;
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* creature, uint32 diff)
{
    if (!creature || !creature->IsAlive())
        return true;

    if (_done || !_path || _path->Nodes.empty())
        return true;

    if (_stalled || creature->HasUnitState(UNIT_STATE_NOT_MOVE) || creature->IsMovementPreventedByCasting())
    {
        creature->StopMoving();
        return true;
    }

    // if it's moving
    if (!creature->movespline->Finalized())
    {
        // set home position at place (every MotionMaster::UpdateMotion)
        if (creature->GetTransGUID().IsEmpty())
            creature->SetHomePosition(creature->GetPosition());

        // relaunch movement if its speed has changed
        if (_recalculateSpeed)
            StartMove(creature, true);
    }
    else
    {
        // check if there is a wait time for the next movement
        if (!_nextMoveTime.Passed())
        {
            // dont update wait timer while moving
            _nextMoveTime.Update(diff);
            if (_nextMoveTime.Passed())
            {
                _nextMoveTime.Reset(0);
                StartMove(creature); // check path status, get next point and move if necessary & can
            }
        }
        else // if it's not moving and there is no timer, assume node is reached
        {
            OnArrived(creature); // hooks and wait timer reset (if necessary)
            _isArrivalDone = true; // signals that the next move will happen after reaching a node

            if (_nextMoveTime.Passed())
                StartMove(creature); // check path status, get next point and move if necessary & can
        }
    }

    return true;
}

void WaypointMovementGenerator<Creature>::MovementInform(Creature* creature)
{
    if (creature->AI())
        creature->AI()->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
}

bool WaypointMovementGenerator<Creature>::GetResetPos(Creature*, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    if (!_path || _path->Nodes.empty())
        return false;

    ASSERT(_currentNode < _path->Nodes.size(), "WaypointMovementGenerator::GetResetPos: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->Id);
    WaypointNode const &waypoint = _path->Nodes.at(_currentNode);

    x = waypoint.X;
    y = waypoint.Y;
    z = waypoint.Z;
    return true;
}

void WaypointMovementGenerator<Creature>::Pause(uint32 timer/* = 0*/)
{
    _stalled = timer ? false : true;
    _nextMoveTime.Reset(timer ? timer : 1);
}

void WaypointMovementGenerator<Creature>::Resume(uint32 overrideTimer/* = 0*/)
{
    _stalled = false;
    if (overrideTimer)
        _nextMoveTime.Reset(overrideTimer);
}

/*static*/ bool WaypointMovementGenerator<Creature>::CanMove(Creature* creature)
{
    return !creature->HasUnitState(UNIT_STATE_NOT_MOVE) && !creature->IsMovementPreventedByCasting();
}
