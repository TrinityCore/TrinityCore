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
void RandomMovementGenerator<T>::Pause(uint32) { }

template<>
void RandomMovementGenerator<Creature>::Pause(uint32 timer/* = 0*/)
{
    _stalled = timer ? false : true;
    _timer.Reset(timer ? timer : 1);
}

template<class T>
void RandomMovementGenerator<T>::Resume(uint32) { }

template<>
void RandomMovementGenerator<Creature>::Resume(uint32 overrideTimer/* = 0*/)
{
    _stalled = false;
    if (overrideTimer)
        _timer.Reset(overrideTimer);
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

    _wanderDistance = std::max<float>(owner->GetWanderDistance(), 0.1f);

    // Retail seems to let a creature walk 2 up to 10 splines before triggering a pause
    _wanderSteps = urand(2, 10);

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
    float distance = _wanderDistance > 0.1f ? frand(0.1f, _wanderDistance) : _wanderDistance;
    float angle = frand(0.f, static_cast<float>(M_PI * 2));
    owner->MovePositionToFirstCollision(position, distance, angle);
    if (owner->GetPosition().GetExactDist(position) < 0.1f)
    {
        // the path is too short for the spline system to be accepted. Let's try again soon.
        _timer.Reset(500);
        return;
    }

    if (!_path)
        _path = new PathGenerator(owner);

    _path->SetPathLengthLimit(30.0f);
    bool result = _path->CalculatePath(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ());
    // PATHFIND_FARFROMPOLY shouldn't be checked as creatures in water are most likely far from poly
    if (!result || (_path->GetPathType() & PATHFIND_NOPATH)
        || (_path->GetPathType() & PATHFIND_SHORTCUT)
        /*|| (_path->GetPathType() & PATHFIND_FARFROMPOLY)*/)
    {
        _timer.Reset(500);
        return;
    }

    bool walk = true;
    switch (owner->GetMovementTemplate().GetRandom())
    {
        case CreatureRandomMovementType::CanRun:
            walk = owner->IsWalking();
            break;
        case CreatureRandomMovementType::AlwaysRun:
            walk = false;
            break;
        default:
            break;
    }

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_path->GetPath());
    init.SetWalk(walk);
    int32 splineDuration = init.Launch();

    _wanderSteps--;
    if (_wanderSteps) // Creature has yet to do steps before pausing.
        _timer.Reset(splineDuration);
    else
    {
        // Creature has made all its steps, time for a little break
        _timer.Reset(splineDuration + urand(4, 10) * IN_MILLISECONDS); // Retails seems to use round numbers so we do as well
        _wanderSteps = urand(2, 10);
    }

    // Call for creature group update
    owner->SignalFormationMovement();
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

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || _stalled)
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
