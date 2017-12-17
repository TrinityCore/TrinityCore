/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Creature.h"
#include "ConfusedMovementGenerator.h"
#include "PathGenerator.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"
#include "Random.h"

template<class T>
void ConfusedMovementGenerator<T>::DoInitialize(T* unit)
{
    unit->AddUnitState(UNIT_STATE_CONFUSED);
    unit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit->GetPosition(i_x, i_y, i_z);

    if (!unit->IsStopped())
        unit->StopMoving();
}

template<class T>
void ConfusedMovementGenerator<T>::DoReset(T* unit)
{
    unit->AddUnitState(UNIT_STATE_CONFUSED);
    i_nextMoveTime.Reset(0);

    if (!unit->IsStopped())
        unit->StopMoving();
}

template<class T>
bool ConfusedMovementGenerator<T>::DoUpdate(T* unit, uint32 diff)
{
    // Update timer.
    if (!i_nextMoveTime.Passed())
        i_nextMoveTime.Update(diff);

    // Check if it's time to move.
    if (!i_nextMoveTime.Passed())
        return true;

    // Only move if there's no reason to stay.
    if (unit->HasUnitState(UNIT_STATE_NOT_MOVE))
        return true;
 
    // Ready to move.
    _move(unit);

    return true;
}

template<class T>
void ConfusedMovementGenerator<T>::_move(T* unit)
{
    // Get original position (where we started)
    Position pos;
    pos.Relocate(i_x, i_y, i_z);

    // Generate vector
    float dist = float(urand(1, 4));
    float angle = 2 * float(M_PI) * float(rand_norm());

    // Check how far we can move (collision check).
    unit->MovePositionToFirstCollision(pos, dist, angle);

    // Generate path
    PathGenerator path(unit);
    path.SetPathLengthLimit(10.0f);
    bool result = path.CalculatePath(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
    if (!result || (path.GetPathType() & PATHFIND_NOPATH))
        return; // Return without setting timer, generate another path on next update.

    // Add "currently moving" flag.
    unit->AddUnitState(UNIT_STATE_CONFUSED_MOVE);

    // Send packet
    Movement::MoveSplineInit init(unit);
    init.MovebyPath(path.GetPath());
    init.SetWalk(true);
    init.Launch();

    // Next move packet always arrives in 800 ms.
    // (Blizzard updates movement every 400 ms, so this value could be anything between 400 and 800)
    i_nextMoveTime.Reset(750);
}

template<>
void ConfusedMovementGenerator<Player>::DoFinalize(Player* unit)
{
    unit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit->ClearUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_CONFUSED_MOVE);
    unit->StopMoving();
}

template<>
void ConfusedMovementGenerator<Creature>::DoFinalize(Creature* unit)
{
    unit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit->ClearUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_CONFUSED_MOVE);
    if (unit->GetVictim())
        unit->SetTarget(unit->EnsureVictim()->GetGUID());
}

template void ConfusedMovementGenerator<Player>::DoInitialize(Player*);
template void ConfusedMovementGenerator<Creature>::DoInitialize(Creature*);
template void ConfusedMovementGenerator<Player>::DoReset(Player*);
template void ConfusedMovementGenerator<Creature>::DoReset(Creature*);
template bool ConfusedMovementGenerator<Player>::DoUpdate(Player*, uint32 diff);
template bool ConfusedMovementGenerator<Creature>::DoUpdate(Creature*, uint32 diff);
template void ConfusedMovementGenerator<Player>::_move(Player*);
template void ConfusedMovementGenerator<Creature>::_move(Creature*);
