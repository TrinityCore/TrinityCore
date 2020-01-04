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

#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "FormationMovementGenerator.h"

void FormationMovementGenerator::DoInitialize(Creature* owner)
{
    owner->AddUnitState(UNIT_STATE_ROAMING);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(_destination.GetPositionX(), _destination.GetPositionY(), _destination.GetPositionZ());
    if (_orientation)
        init.SetFacing(_destination.GetOrientation());

    switch (_moveType)
    {
        case 2: // WAYPOINT_MOVE_TYPE_LAND
            init.SetAnimation(Movement::ToGround);
            break;
        case 3: // WAYPOINT_MOVE_TYPE_TAKEOFF
            init.SetAnimation(Movement::ToFly);
            break;
        case 1: // WAYPOINT_MOVE_TYPE_RUN
            init.SetWalk(false);
            break;
        case 0: // WAYPOINT_MOVE_TYPE_WALK
            init.SetWalk(true);
            break;
    }

    if (_run)
        init.SetWalk(false);

    init.Launch();
}

bool FormationMovementGenerator::DoUpdate(Creature* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return true;
    }

    if ((_interrupt && owner->movespline->Finalized()) || (_recalculateSpeed && !owner->movespline->Finalized()))
    {
        _recalculateSpeed = false;
        _interrupt = false;

        owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

        Movement::MoveSplineInit init(owner);
        init.MoveTo(_destination.GetPositionX(), _destination.GetPositionY(), _destination.GetPositionZ());
        if (_orientation)
            init.SetFacing(_destination.GetOrientation());

        switch (_moveType)
        {
            case 2: // WAYPOINT_MOVE_TYPE_LAND
                init.SetAnimation(Movement::ToGround);
                break;
            case 3: // WAYPOINT_MOVE_TYPE_TAKEOFF
                init.SetAnimation(Movement::ToFly);
                break;
            case 1: // WAYPOINT_MOVE_TYPE_RUN
                init.SetWalk(false);
                break;
            case 0: // WAYPOINT_MOVE_TYPE_WALK
                init.SetWalk(true);
                break;
        }

        if (_run)
            init.SetWalk(false);
        init.Launch();
    }

    return !owner->movespline->Finalized();
}

void FormationMovementGenerator::DoFinalize(Creature* owner)
{
    owner->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);

    if (owner->movespline->Finalized())
        MovementInform(owner);
}

void FormationMovementGenerator::DoReset(Creature* owner)
{
    owner->StopMoving();
    DoInitialize(owner);
}

void FormationMovementGenerator::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(FORMATION_MOTION_TYPE, _movementId);
}
