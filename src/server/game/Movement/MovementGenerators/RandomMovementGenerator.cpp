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

#include "RandomMovementGenerator.h"
#include "Creature.h"
#include "Map.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "PathGenerator.h"
#include "Random.h"

template<class T>
RandomMovementGenerator<T>::~RandomMovementGenerator() { }

template<>
RandomMovementGenerator<Creature>::~RandomMovementGenerator()
{
    delete _path;
}

template<class T>
void RandomMovementGenerator<T>::DoInitialize(T*) { }

template<>
void RandomMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    if (!owner || !owner->IsAlive())
        return;

    owner->AddUnitState(UNIT_STATE_ROAMING);
    _reference = owner->GetPosition();
    owner->StopMoving();

    if (!_wanderDistance)
        _wanderDistance = owner->GetRespawnRadius();

    _timer.Reset(0);
}

template<class T>
void RandomMovementGenerator<T>::DoFinalize(T*) { }

template<>
void RandomMovementGenerator<Creature>::DoFinalize(Creature* owner)
{
    owner->ClearUnitState(UNIT_STATE_ROAMING);
    owner->StopMoving();
    owner->SetWalk(false);
}

template<class T>
void RandomMovementGenerator<T>::DoReset(T*) { }

template<>
void RandomMovementGenerator<Creature>::DoReset(Creature* owner)
{
    DoInitialize(owner);
}

template<class T>
void RandomMovementGenerator<T>::SetRandomLocation(T*) { }

template<>
void RandomMovementGenerator<Creature>::SetRandomLocation(Creature* owner)
{
    if (!owner)
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Position position(_reference);
    float distance = frand(0.f, 1.f) * _wanderDistance;
    float angle = frand(0.f, 1.f) * float(M_PI) * 2.f;
    owner->MovePositionToFirstCollision(position, distance, angle);

    uint32 resetTimer = roll_chance_i(50) ? urand(5000, 10000) : urand(1000, 2000);

    if (!_path)
        _path = new PathGenerator(owner);

    _path->SetPathLengthLimit(30.0f);
    bool result = _path->CalculatePath(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ());
    if (!result || (_path->GetPathType() & PATHFIND_NOPATH))
    {
        _timer.Reset(100);
        return;
    }

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_path->GetPath());
    init.SetWalk(true);
    int32 traveltime = init.Launch();
    _timer.Reset(traveltime + resetTimer);

    // Call for creature group update
    owner->SignalFormationMovement(position);
}

template<class T>
bool RandomMovementGenerator<T>::DoUpdate(T*, uint32)
{
    return false;
}

template<>
bool RandomMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return true;
    }
    else
        _interrupt = false;

    _timer.Update(diff);
    if (!_interrupt && _timer.Passed() && owner->movespline->Finalized())
        SetRandomLocation(owner);

    return true;
}
