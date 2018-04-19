/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "Log.h"
#include "Map.h"
#include "MovementDefines.h"
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

MovementGeneratorType WaypointMovementGenerator<Creature>::GetMovementGeneratorType() const
{
    return WAYPOINT_MOTION_TYPE;
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
        creature->AI()->WaypointPathStarted(_path->id);
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
    if (!_path || _path->nodes.empty())
        return;

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::OnArrived: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes.at(_currentNode);
    if (waypoint.delay)
    {
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        _nextMoveTime.Reset(waypoint.delay);
    }

    if (waypoint.eventId && urand(0, 99) < waypoint.eventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.eventId, _currentNode, creature->GetGUID().ToString().c_str());
        creature->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        creature->GetMap()->ScriptsStart(sWaypointScripts, waypoint.eventId, creature, nullptr);
    }

    // inform AI
    if (creature->IsAIEnabled)
    {
        creature->AI()->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
        creature->AI()->WaypointReached(waypoint.id, _path->id);
    }

    creature->UpdateCurrentWaypointInfo(waypoint.id, _path->id);
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* creature, bool relaunch/* = false*/)
{
    // sanity checks
    if (!creature || !creature->IsAlive() || _done || !_path || _path->nodes.empty() || (relaunch && _isArrivalDone))
        return;

    if (!relaunch)  // on relaunch, can avoid this since its only called on valid movement
    {
        if (!CanMove(creature) || (creature->IsFormationLeader() && !creature->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
        {
            _nextMoveTime.Reset(1000); // delay 1s
            return;
        }
    }

    bool transportPath = creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && !creature->GetTransGUID().IsEmpty();

    if (_isArrivalDone)
    {
        ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
        WaypointNode const &waypoint = _path->nodes.at(_currentNode);

        if ((_currentNode == _path->nodes.size() - 1) && !_repeating) // If that's our last waypoint
        {
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
            _done = true;
            creature->UpdateCurrentWaypointInfo(0, 0);

            // inform AI
            if (creature->IsAIEnabled)
                creature->AI()->WaypointPathEnded(waypoint.id, _path->id);
            return;
        }

        _currentNode = (_currentNode + 1) % _path->nodes.size();

        // inform AI
        if (creature->IsAIEnabled)
            creature->AI()->WaypointStarted(waypoint.id, _path->id);
    }

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes[_currentNode];
    Position formationDest(waypoint.x, waypoint.y, waypoint.z, (waypoint.orientation && waypoint.delay) ? waypoint.orientation : 0.0f);

    _isArrivalDone = false;
    _recalculateSpeed = false;

    creature->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(creature);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
    {
        init.DisableTransportPathTransformations();
        if (TransportBase* trans = creature->GetDirectTransport())
        {
            float orientation = formationDest.GetOrientation();
            trans->CalculatePassengerPosition(formationDest.m_positionX, formationDest.m_positionY, formationDest.m_positionZ, &orientation);
            formationDest.SetOrientation(orientation);
        }
    }

    //! Do not use formationDest here, MoveTo requires transport offsets due to DisableTransportPathTransformations() call
    //! but formationDest contains global coordinates
    init.MoveTo(waypoint.x, waypoint.y, waypoint.z);

    //! Accepts angles such as 0.00001 and -0.00001, 0 must be ignored, default value in waypoint table
    if (waypoint.orientation && waypoint.delay)
        init.SetFacing(waypoint.orientation);

    switch (waypoint.moveType)
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
        default:
            break;
    }

    init.Launch();

    // inform formation
    creature->SignalFormationMovement(formationDest, waypoint.id, waypoint.moveType, (waypoint.orientation && waypoint.delay) ? true : false);
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* creature, uint32 diff)
{
    if (!creature || !creature->IsAlive())
        return true;

    if (_done || !_path || _path->nodes.empty())
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
        if (!creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || creature->GetTransGUID().IsEmpty())
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
            // update timer since it's not moving
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
            _isArrivalDone = true; // signals to future StartMove that it reached a node

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
    if (!_path || _path->nodes.empty())
        return false;

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::GetResetPos: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes.at(_currentNode);

    x = waypoint.x;
    y = waypoint.y;
    z = waypoint.z;
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
