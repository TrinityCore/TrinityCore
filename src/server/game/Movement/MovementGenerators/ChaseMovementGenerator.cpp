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
#include "AbstractPursuer.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Unit.h"
#include "Util.h"
#include "Vehicle.h"

static bool IsMutualChase(Unit const* owner, Unit const* target)
{
    MovementGenerator* gen = target->GetMotionMaster()->topOrNull();
    if (!gen || gen->GetMovementGeneratorType() != CHASE_MOTION_TYPE)
        return false;

    return (static_cast<ChaseMovementGenerator*>(gen)->GetTarget() == owner);
}

static void DoMovementInform(Unit* owner, Unit const* target)
{
    if (Creature* cOwner = owner->ToCreature())
        if (CreatureAI* ai = cOwner->AI())
            ai->MovementInform(CHASE_MOTION_TYPE, target->GetGUID().GetCounter());
}

static bool PositionOkay(Unit const* owner, Unit const* target, float distance, Optional<ChaseAngle> angle)
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

inline float GetChaseRange(Unit const* owner, Unit const* target)
{
    float hitboxSum = owner->GetCombatReach() + target->GetCombatReach();

    float hoverDelta = owner->GetHoverOffset() - target->GetHoverOffset();
    if (hoverDelta != 0.0f)
        return std::sqrt(std::max(hitboxSum * hitboxSum - hoverDelta * hoverDelta, 0.0f));

    return hitboxSum;
}

ChaseMovementGenerator::ChaseMovementGenerator(Unit* target, float range, Optional<ChaseAngle> angle) : AbstractPursuer(PursuingType::Chase, ASSERT_NOTNULL(target)), _range(range), _angle(angle) { }
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

    Unit* target = GetTarget();

    // our target might have gone away
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

    // We are done moving. Trigger movement inform hook and clear chase move state
    if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && owner->movespline->Finalized())
    {
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);

        owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
        DoMovementInform(owner, target);
        return true;
    }

    // Owner cannot reach target (example: target is in water and owner cannot swim)
    Creature* creature = owner->ToCreature();
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

    bool  const mutualChase         = IsMutualChase(owner, target);
    float const chaseRange          = GetChaseRange(owner, target);
    float const rangeTolerance      = _range > 0.f ? _range : chaseRange;
    Optional<ChaseAngle> chaseAngle = mutualChase ? Optional<ChaseAngle>() : _angle;

    // Update Movement
    _nextMovementTimer.Update(diff);
    _nextRepositioningTimer.Update(diff);

    // Handle repositioning and scattering arround target
    if (_nextRepositioningTimer.Passed())
    {
        _nextRepositioningTimer.Reset(REPOSITION_MOVEMENT_INTERVAL);

        if (!owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && owner->IsCreature() && !target->isMoving())
        {
            // Owner is too close to its target. Step back.
            if (owner->GetBoundaryRadius() <= 5.f && owner->GetExactDist2d(target) < owner->GetBoundaryRadius())
            {
                LaunchMovement(owner, chaseRange, true, mutualChase);
                return true;
            }
        }
    }

    if (_nextMovementTimer.Passed())
    {
        _nextMovementTimer.Reset(CHASE_MOVEMENT_INTERVAL);

        // Target has moved since we last checked its position. Handle new cases
        if (!_lastTargetPosition || target->GetPosition() != _lastTargetPosition.value())
        {
            // Create new snapshot of our target's position
            _lastTargetPosition = target->GetPosition();

            if (PositionOkay(owner, target, rangeTolerance, chaseAngle))
            {
                if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && !target->isMoving() && !mutualChase)
                {
                    // Our current position is fine. Stop movement.
                    owner->StopMoving();
                    return true;
                }
            }
            else if (owner->GetExactDist2d(target) > rangeTolerance + 0.1f) // 0.1f here to avoid edge cases when the owner has stepped back before
                LaunchMovement(owner, chaseRange, false, mutualChase);
        }
    }

    return true;
}

void ChaseMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_CHASE | UNIT_STATE_CHASE_MOVE);
    if (Creature* cOwner = owner->ToCreature())
        cOwner->SetCannotReachTarget(false);
}

void ChaseMovementGenerator::LaunchMovement(Unit* owner, float chaseRange, bool backward /*= false*/, bool mutualChase /*= false*/)
{
    Unit* target = GetTarget();

    // Owner may launch a new spline
    Position dest = target->GetVehicle() ? target->GetVehicle()->GetBase()->GetPosition() : target->GetPosition();

    // Predict chase destination to keep up with chase target
    bool predictDestination = !backward && !mutualChase && target->isMoving();
    if (predictDestination)
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

        if (!owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
            target->MovePositionToFirstCollision(dest, additionalRange, _angle ? Position::NormalizeOrientation(target->GetOrientation() - _angle->RelativeAngle + float(M_PI)) : target->GetRelativeAngle(owner) + float(M_PI));
        else
            target->GetNearPoint(owner, dest.m_positionX, dest.m_positionY, dest.m_positionZ, additionalRange - target->GetCombatReach() - owner->GetCombatReach(), Position::NormalizeOrientation(target->GetOrientation() + float(M_PI) + (_angle ? _angle->RelativeAngle : 0.f)));
    }
    else if (!owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
        target->MovePositionToFirstCollision(dest, chaseRange, _angle ? target->NormalizeOrientation(target->GetOrientation() - _angle->RelativeAngle) : target->GetRelativeAngle(owner));
    else
        target->GetNearPoint(owner, dest.m_positionX, dest.m_positionY, dest.m_positionZ, chaseRange - target->GetCombatReach() - owner->GetCombatReach(), Position::NormalizeOrientation(target->GetOrientation() + (_angle ? _angle->RelativeAngle : 0.f)));

    owner->UpdateAllowedPositionZ(dest.GetPositionX(), dest.GetPositionY(), dest.m_positionZ);

    Creature* creature = owner->ToCreature();
    Movement::MoveSplineInit init(owner);

    PathGenerator path(owner);
    bool success = path.CalculatePath(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), owner->CanFly());
    if (!success || (path.GetPathType() & (PATHFIND_NOPATH /*| PATHFIND_INCOMPLETE*/)))
    {
        if (creature)
            creature->SetCannotReachTarget(true);

        owner->StopMoving();
        return;
    }

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
