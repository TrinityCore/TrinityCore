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

#include "FleeingMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"

#define MIN_QUIET_DISTANCE 28.0f
#define MAX_QUIET_DISTANCE 43.0f

FleeingMovementGenerator::FleeingMovementGenerator(ObjectGuid fleeTargetGUID) : _fleeTargetGUID(fleeTargetGUID), _timer(0)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_HIGHEST;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_FLEEING;
}

MovementGeneratorType FleeingMovementGenerator::GetMovementGeneratorType() const
{
    return FLEEING_MOTION_TYPE;
}

void FleeingMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (!owner || !owner->IsAlive())
        return;

    _path = nullptr;
    SetTargetLocation(owner);
}

void FleeingMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
}

bool FleeingMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        _path = nullptr;
        return true;
    }
    else
        RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);

    _timer.Update(diff);
    if ((HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING) && !owner->movespline->Finalized()) || (_timer.Passed() && owner->movespline->Finalized()))
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        SetTargetLocation(owner);
    }

    return true;
}

void FleeingMovementGenerator::Deactivate(Unit* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
}

void FleeingMovementGenerator::Finalize(Unit* owner, bool active, bool /*movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);

        if (owner->IsCreature())
        {
            if (Unit const* victim = owner->GetVictim())
                owner->SetTarget(victim->GetGUID());
        }
        else if (owner->IsPlayer())
            owner->StopMoving();
    }
}

void FleeingMovementGenerator::SetTargetLocation(Unit* owner)
{
    if (!owner || !owner->IsAlive())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        _path = nullptr;
        return;
    }

    Position destination = owner->GetPosition();
    GetPoint(owner, destination);

    // Add LOS check for target point
    if (!owner->IsWithinLOS(destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ()))
    {
        _timer.Reset(200);
        return;
    }

    if (!_path)
    {
        _path = std::make_unique<PathGenerator>(owner);
        _path->SetPathLengthLimit(30.0f);
    }

    bool result = _path->CalculatePath(destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ());
    if (!result || (_path->GetPathType() & PATHFIND_NOPATH)
                || (_path->GetPathType() & PATHFIND_SHORTCUT)
                || (_path->GetPathType() & PATHFIND_FARFROMPOLY))
    {
        _timer.Reset(100);
        return;
    }

    owner->AddUnitState(UNIT_STATE_FLEEING_MOVE);

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_path->GetPath());
    init.SetWalk(false);
    int32 traveltime = init.Launch();
    _timer.Reset(traveltime + urand(800, 1500));
}

void FleeingMovementGenerator::GetPoint(Unit* owner, Position& position) const
{
    float casterDistance, casterAngle;
    if (Unit* fleeTarget = ObjectAccessor::GetUnit(*owner, _fleeTargetGUID))
    {
        casterDistance = fleeTarget->GetDistance(owner);
        if (casterDistance > 0.2f)
            casterAngle = fleeTarget->GetAbsoluteAngle(owner);
        else
            casterAngle = frand(0.0f, 2.0f * float(M_PI));
    }
    else
    {
        casterDistance = 0.0f;
        casterAngle = frand(0.0f, 2.0f * float(M_PI));
    }

    float distance, angle;
    if (casterDistance < MIN_QUIET_DISTANCE)
    {
        distance = frand(0.4f, 1.3f) * (MIN_QUIET_DISTANCE - casterDistance);
        angle = casterAngle + frand(-float(M_PI) / 8.0f, float(M_PI) / 8.0f);
    }
    else if (casterDistance > MAX_QUIET_DISTANCE)
    {
        distance = frand(0.4f, 1.0f) * (MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE);
        angle = -casterAngle + frand(-float(M_PI) / 4.0f, float(M_PI) / 4.0f);
    }
    else // we are inside quiet range
    {
        distance = frand(0.6f, 1.2f) * (MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE);
        angle = frand(0.0f, 2.0f * float(M_PI));
    }

    owner->MovePositionToFirstCollision(position, distance, angle);
}

//---- TimedFleeingMovementGenerator

bool TimedFleeingMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return false;

    _totalFleeTime.Update(diff);
    if (_totalFleeTime.Passed())
        return false;

    return FleeingMovementGenerator::Update(owner, diff);
}

void TimedFleeingMovementGenerator::Finalize(Unit* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (!active)
        return;

    owner->StopMoving();
    if (owner->IsCreature() && owner->IsAlive())
    {
        if (Unit* victim = owner->GetVictim())
        {
            owner->AttackStop();
            owner->GetAI()->AttackStart(victim);
        }
    }

    if (movementInform)
    {
        Creature* ownerCreature = owner->ToCreature();
        if (CreatureAI* AI = ownerCreature ? ownerCreature->AI() : nullptr)
            AI->MovementInform(TIMED_FLEEING_MOTION_TYPE, 0);
    }
}

MovementGeneratorType TimedFleeingMovementGenerator::GetMovementGeneratorType() const
{
    return TIMED_FLEEING_MOTION_TYPE;
}
