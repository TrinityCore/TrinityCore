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

/*
static bool IsMutualChase(Unit const* owner, Unit const* target)
{
    MovementGenerator* gen = target->GetMotionMaster()->topOrNull();
    if (!gen || gen->GetMovementGeneratorType() != CHASE_MOTION_TYPE)
        return false;

    return (static_cast<ChaseMovementGenerator*>(gen)->GetTarget() == owner);
}
*/

enum ChaseMovementPositionCheckResult : uint8
{
    CHASE_POSITION_CHECK_RESULT_VALID           = 0x0,
    CHASE_POSITION_CHECK_RESULT_TOO_FAR         = 0x1,
    CHASE_POSITION_CHECK_RESULT_TOO_CLOSE       = 0x2,
    CHASE_POSITION_CHECK_RESULT_ANGLE_INVALID   = 0x4,
    CHASE_POSITION_CHECK_RESULT_NOT_IN_LOS      = 0x8,
};

enum ChasePositionCheckOptions : uint8
{
    CHASE_POSITION_CHECK_NONE       = 0x0, // everything's fine
    CHASE_POSITION_CHECK_DISTANCE   = 0x1, // the target is too far away
    CHASE_POSITION_CHECK_BOUNDARY   = 0x2, // the target is too close
    CHASE_POSITION_CHECK_ANGLE      = 0x4, // our angle towards the target is out of bounds
    CHASE_POSITION_CHECK_LOS        = 0x8  // our target is not in line of sight
};

inline void DoMovementInform(Unit* owner, Unit const* target)
{
    if (owner->IsCreature())
        return;

    if (CreatureAI* AI = owner->ToCreature()->AI())
        AI->MovementInform(CHASE_MOTION_TYPE, target->GetGUID().GetCounter());
}

inline float GetHitboxSum(Unit const* owner, Unit const* target)
{
    float hitboxSum = owner->GetCombatReach() + target->GetCombatReach();
    float hoverDelta = owner->GetHoverOffset() - target->GetHoverOffset();
    if (hoverDelta != 0.0f)
        return std::sqrt(std::max(hitboxSum * hitboxSum - hoverDelta * hoverDelta, 0.0f));

    return hitboxSum;
}

inline float SelectMovementSpeed(Unit const* target)
{
    UnitMoveType moveType = MOVE_RUN;
    if (target->IsFlying())
        moveType = MOVE_FLIGHT;

    return target->GetSpeed(moveType);
}

ChaseMovementGenerator::ChaseMovementGenerator(Unit* target, Optional<float> range /*= {}*/, Optional<ChaseAngle> angle /*= {}*/) :
    AbstractPursuer(PursuingType::Chase, ASSERT_NOTNULL(target)),
    _range(range), _angle(angle), _previousChaseSplineId(0), _moveTimer(0), _positionCheckTimer(0) { }

void ChaseMovementGenerator::Initialize(Unit* owner)
{
    owner->AddUnitState(UNIT_STATE_CHASE);
    owner->SetWalk(false);
    _pathGenerator = std::make_unique<PathGenerator>(owner);
    _moveTimer.Reset(0);
}

bool ChaseMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // owner might be dead or gone (can we even get nullptr here?)
    if (!owner || !owner->IsAlive())
        return false;

    // validate our target
    Unit* target = GetTarget();
    if (!target || !target->IsInWorld() || owner->GetVictim() != target)
        return false;

    _moveTimer.Update(diff);
    _positionCheckTimer.Update(diff);

    // ------------------------ This segment will handle the clearing of the chase state and the movement inform of the previous updtae cycle

    // Make sure that the spline that we are moving along right now is our current chase spline
    if (owner->movespline->Finalized() || owner->movespline->GetId() != _previousChaseSplineId)
    {
        if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE))
        {
            owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
            // trigger movement inform if we have just reached our target
            if (owner->movespline->GetId() == _previousChaseSplineId)
                DoMovementInform(owner, target);
        }
    }

    // ------------------------ Next up we will perform somce basic checks that prevent the chasing unit to move

    // the owner might be unable to move (rooted or casting), pause movement
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        owner->StopMoving();
        return true;
    }

    Creature* creature = owner->ToCreature();
    // check if the chase target is in an accessible place
    if (creature)
    {
        if (!target->isInAccessiblePlaceFor(creature))
        {
            creature->SetCannotReachTarget(true);
            creature->StopMoving();
            return true;
        }
    }

    // ------------------------ Now we can finally perform the movement actions

    if (_positionCheckTimer.Passed())
    {
        _positionCheckTimer.Reset(POSITION_CHECK_INTERVAL);

        // Check the target angle and update the destination
        Position destination = target->GetVehicle() ? target->GetVehicle()->GetBase()->GetPosition() : target->GetPosition();
        uint8 result = checkPosition(CHASE_POSITION_CHECK_ANGLE, owner, target);

        // The target is still moving so we move our chase destination ahead of the target to keep up
        if (target->isMoving())
        {
            float angle = target->IsPlayer() ? target->m_movementInfo.GetMovementDirection() : 0.f;
            if (result & CHASE_POSITION_CHECK_RESULT_ANGLE_INVALID)
                angle = Position::NormalizeOrientation(_angle->RelativeAngle + float(M_PI));

            target->MovePositionToFirstCollision(destination, SelectMovementSpeed(owner) * 0.5f, angle);
        }
        else
        {
            float angle = target->GetRelativeAngle(owner);
            if (result & CHASE_POSITION_CHECK_RESULT_ANGLE_INVALID)
                angle = _angle->RelativeAngle;

            target->MovePositionToFirstCollision(destination, GetHitboxSum(owner, target), angle);
        }

        // Destination set and ready. Now the usual checks
        result |= checkPosition(ChasePositionCheckOptions(CHASE_POSITION_CHECK_DISTANCE | CHASE_POSITION_CHECK_LOS), owner, target, &destination);

        if (result == CHASE_POSITION_CHECK_RESULT_VALID)
        {
            owner->StopMoving();
            return true;
        }

        if (_moveTimer.Passed())
        {
            _moveTimer.Reset(CHASE_MOVEMENT_INTERVAL);
            launchSpline(owner, target, destination);
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

ChaseMovementPositionCheckResult ChaseMovementGenerator::checkPosition(ChasePositionCheckOptions checkOptions, Unit* owner, Unit* target, Position const* destination /*nullptr*/) const
{
    uint8 result = CHASE_POSITION_CHECK_RESULT_VALID;
    if (checkOptions & CHASE_POSITION_CHECK_DISTANCE)
    {
        float range = _range.has_value() ? *_range : (GetHitboxSum(owner, target) + float(CONTACT_DISTANCE));

        // We have yet to reach the destination of the target so keep moving
        if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && target->isMoving() && destination)
        {
            if (owner->GetExactDist(destination) >= range)
                result |= CHASE_POSITION_CHECK_RESULT_TOO_FAR;
        }
        else if (owner->GetExactDist(target) >= range)
            result |= CHASE_POSITION_CHECK_RESULT_TOO_FAR;
    }

    //if (checkOptions & CHASE_POSITION_CHECK_BOUNDARY)
    {
    }

    if (checkOptions & CHASE_POSITION_CHECK_ANGLE)
    {
        // owner's relative angle to its target is not within boundaries
        if (_angle.has_value() && !_angle->IsAngleOkay(target->GetRelativeAngle(owner)))
            result |= CHASE_POSITION_CHECK_RESULT_ANGLE_INVALID;
    }

    if (checkOptions & CHASE_POSITION_CHECK_LOS)
    {
        // check if the target is in line of sight
        if (!owner->IsWithinLOSInMap(target))
            result |= CHASE_POSITION_CHECK_RESULT_NOT_IN_LOS;
    }

    return static_cast<ChaseMovementPositionCheckResult>(result);
}

void ChaseMovementGenerator::launchSpline(Unit* owner, Unit* target, Position& destination)
{
    Position startPoint = owner->GetPosition();
    if (owner->IsHovering())
        startPoint.m_positionZ = owner->GetFloorZ();

    bool success = _pathGenerator->CalculatePath(startPoint, destination, owner->IsFlying());
    uint32 deniedPathResultTypes = PATHFIND_NOPATH | PATHFIND_INCOMPLETE;
    if ((!owner->IsFlying() || (target->IsInWater() && !owner->CanEnterWater())) && !owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING)) // only flying and swimming units and units with pathfinding disabled may use shortcuts an
        deniedPathResultTypes |= PATHFIND_SHORTCUT;

    bool cantReachTarget = !success || (_pathGenerator->GetPathType() & deniedPathResultTypes);
    if (cantReachTarget)
    {
        owner->ToCreature()->SetCannotReachTarget(true);
        owner->StopMoving();
        return;
    }
    else
        owner->ToCreature()->SetCannotReachTarget(false);

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_pathGenerator->GetPath());
    init.SetWalk(false);
    init.SetFacing(target);

    if (target->isMoving())
    {
        // When the target is still moving but the chaser is already within the combat reach of the target, it adapts its speed to the target's one
        float targetSpeed = SelectMovementSpeed(target);
        if (owner->GetExactDist(target) <= (GetHitboxSum(owner, target) + CONTACT_DISTANCE) && SelectMovementSpeed(owner) > targetSpeed)
            init.SetVelocity(targetSpeed);
    }

    if (init.Launch())
    {
        _previousChaseSplineId = owner->movespline->GetId();
        owner->AddUnitState(UNIT_STATE_CHASE_MOVE);
    }
}
