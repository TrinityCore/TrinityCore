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

#include "CyclicMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "ScriptActionResult.h"
#include "Transport.h"
#include "WaypointManager.h"

inline bool CanMove(Creature const* creature)
{
    return (!creature->HasUnitState(UNIT_STATE_NOT_MOVE) && !creature->IsMovementPreventedByCasting());
}

CyclicMovementGenerator<Creature>::CyclicMovementGenerator(WaypointPath const* path, bool enforceFly /*= false*/,
    Optional<Milliseconds> duration /*= {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/) : _path(path), _nextMoveTime(0), _enforceFly(enforceFly), _velocity(speed), _speedSelectionMode(speedSelectionMode)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;

    if (duration)
        _duration.emplace(*duration);

    ScriptResult = std::move(scriptResult);
}

CyclicMovementGenerator<Creature>::CyclicMovementGenerator() : _path(nullptr), _nextMoveTime(0), _enforceFly(false), _speedSelectionMode(MovementWalkRunSpeedSelectionMode::Default)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

void CyclicMovementGenerator<Creature>::DoInitialize(Creature* creature)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (!_path)
    {
        if (uint32 pathId = creature->GetWaypointPathId())
            _path = sWaypointMgr->GetPath(pathId);
    }

    if (_path)
        _nextMoveTime.Reset(1000);
}

void CyclicMovementGenerator<Creature>::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void CyclicMovementGenerator<Creature>::DoFinalize(Creature* owner , bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
    {
        SetScriptResult(MovementStopReason::Finished);
        if (owner->IsAIEnabled())
            owner->AI()->MovementInform(CYCLIC_SPLINE_MOTION_TYPE, 0);
    }
}

void CyclicMovementGenerator<Creature>::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (_nextMoveTime.Passed() && CanMove(owner))
        StartMovement(owner);
}

bool CyclicMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return true;

    if (!_path || _path->Nodes.empty())
        return true;

    if (HasFlag(MOVEMENTGENERATOR_FLAG_PAUSED) || !CanMove(owner))
    {
        owner->StopMoving();
        return true;
    }

    if (!owner->movespline->Finalized())
    {
        if (owner->GetTransGUID().IsEmpty())
            owner->SetHomePosition(owner->GetPosition());
    }

    if (_duration)
    {
        _duration->Update(diff);
        if (_duration->Passed())
        {
            RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
            owner->UpdateCurrentWaypointInfo(0, 0);
            SetScriptResult(MovementStopReason::Finished);
            return false;
        }
    }

    // dont update wait timer while moving
    if (owner->movespline->Finalized())
    {
        _nextMoveTime.Update(diff);
        if (_nextMoveTime.Passed())
        {
            _nextMoveTime.Reset(0);
            StartMovement(owner);
        }
    }

    return true;
}

void CyclicMovementGenerator<Creature>::StartMovement(Creature* owner)
{
    if (!owner || !owner->IsAlive() || !CanMove(owner) || !_path || _path->Nodes.empty())
        return;

    if (!CanMove(owner) || (owner->IsFormationLeader() && !owner->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
    {
        _nextMoveTime.Reset(1000); // delay 1s
        return;
    }

    bool const flying = owner->CanFly() || owner->IsInWater(); // Swimming units also use flying and uncompressed splines
    Movement::MoveSplineInit init(owner);
    Movement::PointsArray path;

    path.reserve(_path->Nodes.size());
    path.push_back(PositionToVector3(owner->GetPosition()));
    std::transform(_path->Nodes.begin(), _path->Nodes.end(), std::back_inserter(path), [](WaypointNode const& node)
    {
        return G3D::Vector3(node.X, node.Y, node.Z);
    });

    if (flying || _enforceFly)
    {
        init.SetFly();
        init.SetUncompressed();
        init.SetSmooth();
    }

    if (_path->Velocity && !_velocity)
        _velocity = *_path->Velocity;

    if (_velocity)
        init.SetVelocity(*_velocity);

    switch (_speedSelectionMode)
    {
        case MovementWalkRunSpeedSelectionMode::Default:
            break;
        case MovementWalkRunSpeedSelectionMode::ForceRun:
            init.SetWalk(false);
            break;
        case MovementWalkRunSpeedSelectionMode::ForceWalk:
            init.SetWalk(true);
            break;
        default:
            break;
    }

    init.MovebyPath(path);
    init.SetCyclic();
    init.Launch();
}

void CyclicMovementGenerator<Creature>::Pause(uint32 timer/* = 0*/)
{
    if (timer)
    {
        // Don't try to paused an already paused generator
        if (HasFlag(MOVEMENTGENERATOR_FLAG_PAUSED))
            return;

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

void CyclicMovementGenerator<Creature>::Resume(uint32 overrideTimer/* = 0*/)
{
    if (overrideTimer)
        _nextMoveTime.Reset(overrideTimer);

    if (_nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached

    RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
}
