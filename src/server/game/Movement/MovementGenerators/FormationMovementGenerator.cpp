/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "FormationMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"

FormationMovementGenerator::FormationMovementGenerator(uint32 id, Position destination, uint32 moveType, bool run, bool orientation) : _movementId(id), _destination(destination), _moveType(moveType), _run(run), _orientation(orientation)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

MovementGeneratorType FormationMovementGenerator::GetMovementGeneratorType() const
{
    return FORMATION_MOTION_TYPE;
}

void FormationMovementGenerator::DoInitialize(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
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

void FormationMovementGenerator::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

bool FormationMovementGenerator::DoUpdate(Creature* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (owner->IsJumping())
        return true;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if ((HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED) && owner->movespline->Finalized()) || (HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING) && !owner->movespline->Finalized()))
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED | MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING);

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

    if (owner->movespline->Finalized())
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

void FormationMovementGenerator::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void FormationMovementGenerator::DoFinalize(Creature* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        MovementInform(owner);
}

void FormationMovementGenerator::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(FORMATION_MOTION_TYPE, _movementId);
}
