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
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "Unit.h"

#define MIN_QUIET_DISTANCE 28.0f
#define MAX_QUIET_DISTANCE 43.0f

template<class T>
FleeingMovementGenerator<T>::FleeingMovementGenerator(ObjectGuid fleeTargetGUID) : _fleeTargetGUID(fleeTargetGUID), _timer(0)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_HIGHEST;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_FLEEING;
}

template<class T>
MovementGeneratorType FleeingMovementGenerator<T>::GetMovementGeneratorType() const
{
    return FLEEING_MOTION_TYPE;
}

template<class T>
void FleeingMovementGenerator<T>::DoInitialize(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (!owner || !owner->IsAlive())
        return;

    // TODO: UNIT_FIELD_FLAGS should not be handled by generators
    owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);

    _path = nullptr;
    SetTargetLocation(owner);
}

template<class T>
void FleeingMovementGenerator<T>::DoReset(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

template<class T>
bool FleeingMovementGenerator<T>::DoUpdate(T* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        _path = nullptr;
        return true;
    }
    else
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);

    _timer.Update(diff);
    if ((MovementGenerator::HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING) && !owner->movespline->Finalized()) || (_timer.Passed() && owner->movespline->Finalized()))
    {
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        SetTargetLocation(owner);
    }

    return true;
}

template<class T>
void FleeingMovementGenerator<T>::DoDeactivate(T* owner)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
}

template<class T>
void FleeingMovementGenerator<T>::DoFinalize(T*, bool, bool)
{
}

template<>
void FleeingMovementGenerator<Player>::DoFinalize(Player* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
    {
        owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
        owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
        owner->StopMoving();
    }
}

template<>
void FleeingMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
    {
        owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
        owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
        if (owner->GetVictim())
            owner->SetTarget(owner->EnsureVictim()->GetGUID());
    }
}

template<class T>
void FleeingMovementGenerator<T>::SetTargetLocation(T* owner)
{
    if (!owner || !owner->IsAlive())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
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

template<class T>
void FleeingMovementGenerator<T>::GetPoint(T* owner, Position &position)
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

template FleeingMovementGenerator<Player>::FleeingMovementGenerator(ObjectGuid);
template FleeingMovementGenerator<Creature>::FleeingMovementGenerator(ObjectGuid);
template MovementGeneratorType FleeingMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType FleeingMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void FleeingMovementGenerator<Player>::DoInitialize(Player*);
template void FleeingMovementGenerator<Creature>::DoInitialize(Creature*);
template void FleeingMovementGenerator<Player>::DoReset(Player*);
template void FleeingMovementGenerator<Creature>::DoReset(Creature*);
template bool FleeingMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool FleeingMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void FleeingMovementGenerator<Player>::DoDeactivate(Player*);
template void FleeingMovementGenerator<Creature>::DoDeactivate(Creature*);
template void FleeingMovementGenerator<Player>::SetTargetLocation(Player*);
template void FleeingMovementGenerator<Creature>::SetTargetLocation(Creature*);
template void FleeingMovementGenerator<Player>::GetPoint(Player*, Position &);
template void FleeingMovementGenerator<Creature>::GetPoint(Creature*, Position &);

//---- TimedFleeingMovementGenerator

bool TimedFleeingMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return false;

    _totalFleeTime.Update(diff);
    if (_totalFleeTime.Passed())
        return false;

    return FleeingMovementGenerator<Creature>::DoUpdate(owner->ToCreature(), diff);
}

void TimedFleeingMovementGenerator::Finalize(Unit* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (!active)
        return;

    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner->StopMoving();
    if (Unit* victim = owner->GetVictim())
    {
        if (owner->IsAlive())
        {
            owner->AttackStop();
            owner->ToCreature()->AI()->AttackStart(victim);
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
