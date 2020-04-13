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

#include "ChaseMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Unit.h"
#include "Util.h"
#include "Vehicle.h"

static bool IsMutualChase(Unit* owner, Unit* target)
{
    MovementGenerator const* gen = target->GetMotionMaster()->topOrNull();
    if (!gen || gen->GetMovementGeneratorType() != CHASE_MOTION_TYPE)
        return false;

    return (static_cast<ChaseMovementGenerator const*>(gen)->GetTarget() == owner);
}

static void DoMovementInform(Unit* owner, Unit* target)
{
    if (Creature* cOwner = owner->ToCreature())
        if (CreatureAI* ai = cOwner->AI())
            ai->MovementInform(CHASE_MOTION_TYPE, target->GetGUID().GetCounter());
}

static bool PositionOkay(Unit* owner, Unit* target, float distance, Optional<ChaseAngle> angle)
{
    float const dist = owner->GetExactDist2d(target);

    // owner's distance to its chase target is outside of its range
    if (dist > distance)
        return false;

    // owner's relative angle to its target is not within boundaries
    if (angle && !angle->IsAngleOkay(target->GetRelativeAngle(owner)))
        return false;

    // owner cannot see its target
    if (!owner->IsWithinLOSInMap(target))
        return false;

    return true;
}

ChaseMovementGenerator::ChaseMovementGenerator(Unit* target, float range, Optional<ChaseAngle> angle) : AbstractFollower(ASSERT_NOTNULL(target)), _range(range), _angle(angle) { }
ChaseMovementGenerator::~ChaseMovementGenerator() = default;

void ChaseMovementGenerator::Initialize(Unit* owner)
{
    owner->AddUnitState(UNIT_STATE_CHASE);
    owner->SetWalk(false);
    _lastTargetPosition.reset();
    _nextMovementTimer.Reset(0);
    _nextRepositioningTimer.Reset(0);
}

bool ChaseMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // owner might be dead or gone (can we even get nullptr here?)
    if (!owner || !owner->IsAlive())
        return false;

    // our target might have gone away
    Unit* const target = GetTarget();
    if (!target || !target->IsInWorld())
        return false;

    // the owner might've selected a different target (feels like we shouldn't check this here...)
    if (owner->GetVictim() != target)
        return false;

    // the owner might be unable to move (rooted or casting), pause movement
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        owner->StopMoving();
        _lastTargetPosition.reset();
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);
        return true;
    }

    bool  const mutualChase     = IsMutualChase(owner, target);
    //float const hitboxSum       = owner->GetCombatReach() + target->GetCombatReach();
    float const chaseRange = owner->GetCombatReach() + target->GetCombatReach();
    float const rangeTolerance  = _range > 0.f ? _range : chaseRange;
    Optional<ChaseAngle> chaseAngle = mutualChase ? Optional<ChaseAngle>() : _angle;

    // We are done moving. Trigger movement inform hook and clear chase move state
    if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && owner->movespline->Finalized())
    {
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);

        owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
        owner->SetInFront(target);
        DoMovementInform(owner, target);
    }

    // Update Movement
    _nextMovementTimer.Update(diff);
    _nextRepositioningTimer.Update(diff);

    // Handle repositioning and scattering arround target
    if (_nextRepositioningTimer.Passed())
    {
        _nextRepositioningTimer.Reset(REPOSITION_MOVEMENT_INTERVAL);

        if (!owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && owner->IsCreature())
        {
            // Owner is too close to its target. Step back.
            if (owner->GetExactDist2d(target) < owner->GetBoundaryRadius())
            {
                LaunchMovement(owner, target, chaseRange, true);
                return true;
            }
        }
    }

    if (_nextMovementTimer.Passed())
    {
        _nextMovementTimer.Reset(CHASE_MOVEMENT_INTERVAL);

        // Target has moved since we last checked its position. Handle new cases
        if (!_lastTargetPosition || target->GetPosition() != _lastTargetPosition.get())
        {
            // Create new snapshot of our target's position
            _lastTargetPosition = target->GetPosition();

            Creature* creature = owner->ToCreature();
            // Owner cannot reach target (example: target is in water and owner cannot swim)
            if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && creature)
            {
                if (!target->isInAccessiblePlaceFor(creature))
                {
                    creature->SetCannotReachTarget(true);
                    creature->StopMoving();
                    return true;
                }
            }
            else if (creature && !target->isInAccessiblePlaceFor(creature))
            {
                creature->SetCannotReachTarget(true);
                return true;
            }

            bool isMoving = target->HasUnitMovementFlag(MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT | MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD) || !target->movespline->Finalized();
            if (PositionOkay(owner, target, rangeTolerance, chaseAngle) && !isMoving)
            {
                if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE))
                {
                    // Just stopping our movement, movementinform and cleanups will be executed in the code above on the next update tick
                    owner->StopMoving();
                    return true;
                }
            }
            else if (owner->GetExactDist2d(target) > rangeTolerance + 0.1f) // 0.1f here to avoid edge cases when the owner has stepped back before
                LaunchMovement(owner, target, chaseRange);
        }
    }

    // and then, finally, we're done for the tick
    return true;
}

void ChaseMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_CHASE | UNIT_STATE_CHASE_MOVE);
    if (Creature* cOwner = owner->ToCreature())
        cOwner->SetCannotReachTarget(false);
}

void ChaseMovementGenerator::LaunchMovement(Unit* owner, Unit* target, float chaseRange, bool backward /*= false*/)
{
    // Owner may launch a new spline
    Position dest = target->GetVehicle() ? target->GetVehicle()->GetBase()->GetPosition() : target->GetPosition();

    // Player chase target is currently moving
    bool predictDestination = target->HasUnitMovementFlag(MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT | MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD);

    if (!backward && predictDestination)
    {
        UnitMoveType moveType = MOVE_RUN;
        if (target->CanFly())
            moveType = target->HasUnitMovementFlag(MOVEMENTFLAG_BACKWARD) ? MOVE_FLIGHT_BACK : MOVE_FLIGHT;
        else
        {
            if (target->IsWalking())
                moveType = MOVE_WALK;
            else
                moveType = target->HasUnitMovementFlag(MOVEMENTFLAG_BACKWARD) ? MOVE_RUN_BACK : MOVE_RUN;
        }

        float additionalRange = target->GetSpeed(moveType) * 0.5f;

        target->MovePositionToFirstCollision(dest, additionalRange, _angle ? _angle->RelativeAngle : target->GetRelativeAngle(owner) + float(M_PI));
    }
    else
        target->MovePositionToFirstCollision(dest, chaseRange, _angle ? _angle->RelativeAngle : target->GetRelativeAngle(owner));

    owner->UpdateAllowedPositionZ(dest.GetPositionX(), dest.GetPositionY(), dest.m_positionZ);

    Creature* creature = owner->ToCreature();

    PathGenerator path(owner);
    bool success = path.CalculatePath(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), owner->CanFly());
    if (!success || (path.GetPathType() & (PATHFIND_NOPATH /*| PATHFIND_INCOMPLETE*/)))
    {
        if (creature)
            creature->SetCannotReachTarget(true);

        owner->StopMoving();
        return;
    }

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(path.GetPath());
    init.SetWalk(false);
    if (backward)
        init.SetBackward();
    else
        init.SetFacing(target);

    init.Launch();

    if (!backward)
        owner->AddUnitState(UNIT_STATE_CHASE_MOVE);

    if (creature)
        creature->SetCannotReachTarget(false);
}
