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

#include "FormationMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "G3DPosition.hpp"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"

FormationMovementGenerator::FormationMovementGenerator(Unit* leader, float range, float angle, uint32 point1, uint32 point2) : AbstractFollower(ASSERT_NOTNULL(leader)),
    _range(range), _angle(angle), _point1(point1), _point2(point2), _lastLeaderSplineID(0), _hasPredictedDestination(false)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_FOLLOW_FORMATION;
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

    _nextMoveTimer.Reset(0);
}

void FormationMovementGenerator::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

bool FormationMovementGenerator::DoUpdate(Creature* owner, uint32 diff)
{
    Unit* target = GetTarget();

    if (!owner || !target)
        return false;

    if (owner->IsJumping())
        return true;

    // Owner cannot move. Reset all fields and wait for next action
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        _nextMoveTimer.Reset(0);
        _hasPredictedDestination = false;
        return true;
    }

    // If target is not moving and destination has been predicted and if we are on the same spline, we stop as well
    if (target->movespline->Finalized() && target->movespline->GetId() == _lastLeaderSplineID && _hasPredictedDestination)
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        _nextMoveTimer.Reset(0);
        _hasPredictedDestination = false;
        return true;
    }

    if (!owner->movespline->Finalized())
        owner->SetHomePosition(owner->GetPosition());

    // Formation leader has launched a new spline, launch a new one for our member as well
    // This action does not reset the regular movement launch cycle interval
    if (!target->movespline->Finalized() && target->movespline->GetId() != _lastLeaderSplineID)
    {
        // Update formation angle
        if (_point1 && target->GetTypeId() == TYPEID_UNIT)
        {
            if (CreatureGroup* formation = target->ToCreature()->GetFormation())
            {
                if (Creature* leader = formation->GetLeader())
                {
                    uint8 currentWaypoint = leader->GetCurrentWaypointInfo().first;
                    if (currentWaypoint == _point1 || currentWaypoint == _point2)
                        _angle = float(M_PI) * 2 - _angle;
                }
            }
        }

        LaunchMovement(owner, target);
        _lastLeaderSplineID = target->movespline->GetId();
        return true;
    }

    _nextMoveTimer.Update(diff);
    if (_nextMoveTimer.Passed())
    {
        _nextMoveTimer.Reset(FORMATION_MOVEMENT_INTERVAL);

        // Our leader has a different position than on our last check, launch movement.
        if (_lastLeaderPosition != target->GetPosition())
        {
            LaunchMovement(owner, target);
            return true;
        }
    }

    // We have reached our destination before launching a new movement. Alling facing with leader
    if (owner->HasUnitState(UNIT_STATE_FOLLOW_FORMATION_MOVE) && owner->movespline->Finalized())
    {
        owner->ClearUnitState(UNIT_STATE_FOLLOW_FORMATION_MOVE);
        owner->SetFacingTo(target->GetOrientation());
        MovementInform(owner);
    }

    return true;
}

void FormationMovementGenerator::LaunchMovement(Creature* owner, Unit* target)
{
    float relativeAngle = 0.f;

    // Determine our relative angle to our current spline destination point
    if (!target->movespline->Finalized())
        relativeAngle = target->GetRelativeAngle(Vector3ToPosition(target->movespline->CurrentDestination()));

    // Destination calculation
    /*
        According to sniff data, formation members have a periodic move interal of 1,2s.
        Each of these splines has a exact duration of 1650ms +- 1ms when no pathfinding is involved.
        To get a representative result like that we have to predict our formation leader's path
        and apply our formation shape based on that destination.
    */
    Position dest = target->GetPosition();
    float velocity = 0.f;

    // Formation leader is moving. Predict our destination
    if (!target->movespline->Finalized())
    {
        // Pick up leader's spline velocity
        velocity = target->movespline->Velocity();

        // Calculate travel distance to get a 1650ms result
        float travelDist = velocity * 1.65f;

        // Move destination ahead...
        target->MovePositionToFirstCollision(dest, travelDist, relativeAngle);
        // ... and apply formation shape
        target->MovePositionToFirstCollision(dest, _range, _angle + relativeAngle);

        float distance = owner->GetExactDist(dest);

        // Calculate catchup speed mod (Limit to a maximum of 50% of our original velocity
        float velocityMod = std::min<float>(distance / travelDist, 1.5f);

        // Now we will always stay synch with our leader
        velocity *= velocityMod;
        _hasPredictedDestination = true;
    }
    else
    {
        // Formation leader is not moving. Just apply the base formation shape on his position.
        target->MovePositionToFirstCollision(dest, _range, _angle + relativeAngle);
        _hasPredictedDestination = false;
    }

    // Leader is not moving, so just pick up his default walk speed
    if (velocity == 0.f)
        velocity = target->GetSpeed(MOVE_WALK);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(PositionToVector3(dest));
    init.SetVelocity(velocity);
    init.Launch();

    _lastLeaderPosition = target->GetPosition();
    owner->AddUnitState(UNIT_STATE_FOLLOW_FORMATION_MOVE);
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
}

void FormationMovementGenerator::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_FOLLOW_FORMATION_MOVE);
}

void FormationMovementGenerator::DoFinalize(Creature* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_FOLLOW_FORMATION_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        MovementInform(owner);
}

void FormationMovementGenerator::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(FORMATION_MOTION_TYPE, 0);
}
