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
#include "Creature.h"
#include "CreatureAI.h"
#include "Errors.h"
#include "Log.h"
#include "Map.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(uint32 pathId, bool repeating) : _nextMoveTime(0), _pathId(pathId), _repeating(repeating), _loadedFromDB(true)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(WaypointPath& path, bool repeating) : _nextMoveTime(0), _pathId(0), _repeating(repeating), _loadedFromDB(false)
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

void WaypointMovementGenerator<Creature>::Pause(uint32 timer/* = 0*/)
{
    if (timer)
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
        _nextMoveTime.Reset(timer);
        RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
    }
    else
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
        RemoveFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
    }
}

void WaypointMovementGenerator<Creature>::Resume(uint32 overrideTimer/* = 0*/)
{
    if (overrideTimer)
        _nextMoveTime.Reset(overrideTimer);

    if (_nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached

    RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
}

bool WaypointMovementGenerator<Creature>::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    if (!_path || _path->nodes.empty())
        return false;

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::GetResetPosition: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes.at(_currentNode);

    x = waypoint.x;
    y = waypoint.y;
    z = waypoint.z;
    return true;
}

void WaypointMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (_loadedFromDB)
    {
        if (!_pathId)
            _pathId = owner->GetWaypointPath();

        _path = sWaypointMgr->GetPath(_pathId);
    }

    if (!_path)
    {
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::DoInitialize: couldn't load path for creature (%s) (_pathId: %u)", owner->GetGUID().ToString().c_str(), _pathId);
        return;
    }

    owner->StopMoving();

    _nextMoveTime.Reset(1000);

    // inform AI
    if (CreatureAI* AI = owner->AI())
        AI->WaypointPathStarted(_path->id);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    owner->StopMoving();

    if (!HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED) && _nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return true;

    if (HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED | MOVEMENTGENERATOR_FLAG_PAUSED) || !_path || _path->nodes.empty())
        return true;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE | UNIT_STATE_LOST_CONTROL) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if (HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED))
    {
        /*
         *  relaunch only if
         *  - has a tiner? -> was it interrupted while not waiting aka moving? need to check both:
         *      -> has a timer - is it because its waiting to start next node?
         *      -> has a timer - is it because something set it while moving (like timed pause)?
         *
         *  - doesnt have a timer? -> is movement valid?
         *
         *  TODO: ((_nextMoveTime.Passed() && VALID_MOVEMENT) || (!_nextMoveTime.Passed() && !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)))
         */
        if (HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && (_nextMoveTime.Passed() || !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)))
        {
            StartMove(owner, true);
            return true;
        }

        RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
    }

    // if it's moving
    if (!owner->movespline->Finalized())
    {
        // set home position at place (every MotionMaster::UpdateMotion)
        if (!owner->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) || owner->GetTransGUID().IsEmpty())
            owner->SetHomePosition(owner->GetPosition());

        // relaunch movement if its speed has changed
        if (HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING))
            StartMove(owner, true);
    }
    else if (!_nextMoveTime.Passed()) // it's not moving, is there a timer?
    {
        if (UpdateTimer(diff))
        {
            if (!HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED)) // initial movement call
            {
                StartMove(owner);
                return true;
            }
            else if (!HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)) // timer set before node was reached, resume now
            {
                StartMove(owner, true);
                return true;
            }
        }
        else
            return true; // keep waiting
    }
    else // not moving, no timer
    {
        if (HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        {
            OnArrived(owner); // hooks and wait timer reset (if necessary)
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED); // signals to future StartMove that it reached a node
        }

        if (_nextMoveTime.Passed()) // OnArrived might have set a timer
            StartMove(owner); // check path status, get next point and move if necessary & can
    }

    return true;
}

void WaypointMovementGenerator<Creature>::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

        // TODO: Research if this modification is needed, which most likely isnt
        owner->SetWalk(false);
    }
}

void WaypointMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
}

void WaypointMovementGenerator<Creature>::OnArrived(Creature* owner)
{
    if (!_path || _path->nodes.empty())
        return;

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::OnArrived: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes.at(_currentNode);
    if (waypoint.delay)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        _nextMoveTime.Reset(waypoint.delay);
    }

    if (waypoint.eventId && urand(0, 99) < waypoint.eventChance)
    {
        TC_LOG_DEBUG("maps.script", "Creature movement start script %u at point %u for %s.", waypoint.eventId, _currentNode, owner->GetGUID().ToString().c_str());
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        owner->GetMap()->ScriptsStart(sWaypointScripts, waypoint.eventId, owner, nullptr);
    }

    // inform AI
    if (CreatureAI* AI = owner->AI())
    {
        AI->MovementInform(WAYPOINT_MOTION_TYPE, _currentNode);
        AI->WaypointReached(waypoint.id, _path->id);
    }

    owner->UpdateCurrentWaypointInfo(waypoint.id, _path->id);
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* owner, bool relaunch/* = false*/)
{
    // sanity checks
    if (!owner || !owner->IsAlive() || HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED) || !_path || _path->nodes.empty() || (relaunch && (HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) || !HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))))
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || (owner->IsFormationLeader() && !owner->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
    {
        _nextMoveTime.Reset(1000); // delay 1s
        return;
    }

    bool const transportPath = owner->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && !owner->GetTransGUID().IsEmpty();

    if (HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        if (ComputeNextNode())
        {
            ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);

            // inform AI
            if (CreatureAI* AI = owner->AI())
                AI->WaypointStarted(_path->nodes[_currentNode].id, _path->id);
        }
        else
        {
            WaypointNode const &waypoint = _path->nodes[_currentNode];
            float x = waypoint.x;
            float y = waypoint.y;
            float z = waypoint.z;
            float o = owner->GetOrientation();

            if (!transportPath)
                owner->SetHomePosition(x, y, z, o);
            else
            {
                if (Transport* trans = owner->GetTransport())
                {
                    o -= trans->GetOrientation();
                    owner->SetTransportHomePosition(x, y, z, o);
                    trans->CalculatePassengerPosition(x, y, z, &o);
                    owner->SetHomePosition(x, y, z, o);
                }
                // else if (vehicle) - this should never happen, vehicle offsets are const
            }
            AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
            owner->UpdateCurrentWaypointInfo(0, 0);

            // inform AI
            if (CreatureAI* AI = owner->AI())
                AI->WaypointPathEnded(waypoint.id, _path->id);
            return;
        }
    }
    else if (!HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

        // inform AI
        if (CreatureAI* AI = owner->AI())
            AI->WaypointStarted(_path->nodes[_currentNode].id, _path->id);
    }

    ASSERT(_currentNode < _path->nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, _path->id);
    WaypointNode const &waypoint = _path->nodes[_currentNode];
    Position formationDest(waypoint.x, waypoint.y, waypoint.z, (waypoint.orientation && waypoint.delay) ? waypoint.orientation : 0.0f);

    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_INFORM_ENABLED | MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
    {
        init.DisableTransportPathTransformations();
        if (TransportBase* trans = owner->GetDirectTransport())
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
    owner->SignalFormationMovement(formationDest, waypoint.id, waypoint.moveType, (waypoint.orientation && waypoint.delay) ? true : false);
}

bool WaypointMovementGenerator<Creature>::ComputeNextNode()
{
    if ((_currentNode == _path->nodes.size() - 1) && !_repeating)
        return false;

    _currentNode = (_currentNode + 1) % _path->nodes.size();
    return true;
}

std::string WaypointMovementGenerator<Creature>::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << PathMovementBase::GetDebugInfo() << "\n"
        << MovementGeneratorMedium::GetDebugInfo();
    return sstr.str();
}
