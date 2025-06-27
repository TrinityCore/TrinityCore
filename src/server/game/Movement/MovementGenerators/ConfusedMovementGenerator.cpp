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

#include "ConfusedMovementGenerator.h"
#include "Creature.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Player.h"
#include "Random.h"

template<class T>
ConfusedMovementGenerator<T>::ConfusedMovementGenerator() : _timer(0), _x(0.f), _y(0.f), _z(0.f)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_HIGHEST;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_CONFUSED;
}

template<class T>
MovementGeneratorType ConfusedMovementGenerator<T>::GetMovementGeneratorType() const
{
    return CONFUSED_MOTION_TYPE;
}

template<class T>
void ConfusedMovementGenerator<T>::DoInitialize(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (!owner || !owner->IsAlive())
        return;

    // TODO: UNIT_FIELD_FLAGS should not be handled by generators
    owner->SetUnitFlag(UNIT_FLAG_CONFUSED);
    owner->StopMoving();

    _timer.Reset(0);
    owner->GetPosition(_x, _y, _z);
    _path = nullptr;
}

template<class T>
void ConfusedMovementGenerator<T>::DoReset(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

template<class T>
bool ConfusedMovementGenerator<T>::DoUpdate(T* owner, uint32 diff)
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

    // waiting for next move
    _timer.Update(diff);
    if ((MovementGenerator::HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING) && !owner->movespline->Finalized()) || (_timer.Passed() && owner->movespline->Finalized()))
    {
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);

        Position destination(_x, _y, _z);
        float distance = 4.0f * frand(0.0f, 1.0f) - 2.0f;
        float angle = frand(0.0f, 1.0f) * float(M_PI) * 2.0f;
        owner->MovePositionToFirstCollision(destination, distance, angle);

        // Check if the destination is in LOS
        if (!owner->IsWithinLOS(destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ()))
        {
            // Retry later on
            _timer.Reset(200);
            return true;
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
            return true;
        }

        owner->AddUnitState(UNIT_STATE_CONFUSED_MOVE);

        Movement::MoveSplineInit init(owner);
        init.MovebyPath(_path->GetPath());
        init.SetWalk(true);
        int32 traveltime = init.Launch();
        _timer.Reset(traveltime + urand(800, 1500));
    }

    return true;
}

template<class T>
void ConfusedMovementGenerator<T>::DoDeactivate(T* owner)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_CONFUSED_MOVE);
}

template<class T>
void ConfusedMovementGenerator<T>::DoFinalize(T*, bool, bool) { }

template<>
void ConfusedMovementGenerator<Player>::DoFinalize(Player* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
    {
        owner->RemoveUnitFlag(UNIT_FLAG_CONFUSED);
        owner->StopMoving();
    }
}

template<>
void ConfusedMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
    {
        owner->RemoveUnitFlag(UNIT_FLAG_CONFUSED);
        owner->ClearUnitState(UNIT_STATE_CONFUSED_MOVE);
        if (owner->GetVictim())
            owner->SetTarget(owner->EnsureVictim()->GetGUID());
    }
}

template ConfusedMovementGenerator<Player>::ConfusedMovementGenerator();
template ConfusedMovementGenerator<Creature>::ConfusedMovementGenerator();
template MovementGeneratorType ConfusedMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType ConfusedMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void ConfusedMovementGenerator<Player>::DoInitialize(Player*);
template void ConfusedMovementGenerator<Creature>::DoInitialize(Creature*);
template void ConfusedMovementGenerator<Player>::DoReset(Player*);
template void ConfusedMovementGenerator<Creature>::DoReset(Creature*);
template bool ConfusedMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool ConfusedMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void ConfusedMovementGenerator<Player>::DoDeactivate(Player*);
template void ConfusedMovementGenerator<Creature>::DoDeactivate(Creature*);
