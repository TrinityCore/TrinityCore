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

#include "FollowMovementGenerator.h"
#include "CreatureAI.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "Util.h"

FollowMovementGenerator::FollowMovementGenerator(Unit* target, float range, ChaseAngle angle, bool allignToTargetSpeed) : AbstractFollower(ASSERT_NOTNULL(target)),
    _range(range), _useTargetSpeed(allignToTargetSpeed), _hasStopped(false), _angle(angle) { }

FollowMovementGenerator::~FollowMovementGenerator() { }

inline UnitMoveType SelectSpeedType(uint32 moveFlags)
{
    if (moveFlags & MOVEMENTFLAG_FLYING)
    {
        if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.flight >= speed_obj.flight_back*/)
            return MOVE_FLIGHT_BACK;
        else
            return MOVE_FLIGHT;
    }
    else if (moveFlags & MOVEMENTFLAG_SWIMMING)
    {
        if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.swim >= speed_obj.swim_back*/)
            return MOVE_SWIM_BACK;
        else
            return MOVE_SWIM;
    }
    else if (moveFlags & MOVEMENTFLAG_WALKING)
    {
        //if (speed_obj.run > speed_obj.walk)
        return MOVE_WALK;
    }
    else if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.run >= speed_obj.run_back*/)
        return MOVE_RUN_BACK;

    // Flying creatures use MOVEMENTFLAG_CAN_FLY or MOVEMENTFLAG_DISABLE_GRAVITY
    // Run speed is their default flight speed.
    return MOVE_RUN;
}

static void DoMovementInform(Unit* owner, Unit* target)
{
    if (owner->GetTypeId() != TYPEID_UNIT)
        return;
    if (UnitAI* ai = owner->GetAI())
        static_cast<CreatureAI*>(ai)->MovementInform(FOLLOW_MOTION_TYPE, target->GetGUID().GetCounter());
}

void FollowMovementGenerator::Initialize(Unit* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW);
    _hasStopped = false;
    _followMovementTimer.Reset(0);
}

bool FollowMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // owner might be dead or gone
    if (!owner->IsAlive())
        return false;

    // our target might have gone away
    Unit* const target = GetTarget();
    if (!target)
        return false;

    // follower cannot move at the moment
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        owner->StopMoving();
        _hasStopped = true;
        _followMovementTimer.Reset(0);
        return true;
    }

    _followMovementTimer.Update(diff);
    if (_followMovementTimer.Passed())
    {
        // Follow target is moving, launch our follow movement
        if (!target->movespline->Finalized() || target->isMoving())
        {
            Position dest = target->GetPosition();

            float offset = 0.f;

            // Strafe handling for player sidewards movement
            if (target->IsPlayer())
            {
                if (target->HasUnitMovementFlag(MOVEMENTFLAG_STRAFE_LEFT))
                    offset += float(M_PI / 2);

                if (target->HasUnitMovementFlag(MOVEMENTFLAG_STRAFE_RIGHT))
                    offset -= float(M_PI / 2);

                if (target->HasUnitMovementFlag(MOVEMENTFLAG_BACKWARD))
                    offset += float(M_PI);

                // Player moves forward while strafing, cut strafe offset in half
                if (offset != 0.f && target->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD))
                    offset *= 0.5f;
            }

            float angle = !target->HasUnitMovementFlag(MOVEMENTFLAG_BACKWARD) ? _angle.RelativeAngle : -_angle.RelativeAngle;

            // Let's start with a cheap base destination calculation
            dest.m_positionX += std::cos(Position::NormalizeOrientation(target->GetOrientation() + offset + angle)) * (_range + target->GetBoundaryRadius() + owner->GetBoundaryRadius());
            dest.m_positionY += std::sin(Position::NormalizeOrientation(target->GetOrientation() + offset + angle)) * (_range + target->GetBoundaryRadius() + owner->GetBoundaryRadius());

            // Determine our velocity
            float velocity = 0.f;
            if (_useTargetSpeed)
            {
                if (target->IsPlayer())
                    velocity = target->GetSpeed(SelectSpeedType(target->m_movementInfo.GetMovementFlags()));
                else
                {
                    if (!target->movespline->Finalized())
                        velocity = target->movespline->Velocity();
                    else
                        velocity = target->GetSpeed(MOVE_RUN);
                }


                // Catchup / throttle speed modifier calculation
                if (velocity > 0.f)
                {
                    float distance = owner->GetExactDist2d(dest);
                    float distMod = 1.f;
                    if (!dest.HasInArc(float(M_PI), owner)) // Follower is in falling back, catch up
                        distMod += std::min<float>(distance * 0.1f, 0.5f);
                    else if (distance > (velocity / 2))  // Follower is beyond destination, fall back
                        distMod -= std::min<float>((distance - (velocity / 2)), 0.5f);

                    velocity *= distMod;
                }
            }

            // Predicting our follow destination (roundabout velocity * 2 according to sniff data)
            dest.m_positionX += std::cos(Position::NormalizeOrientation(target->GetOrientation() + offset)) * (velocity * 2);
            dest.m_positionY += std::sin(Position::NormalizeOrientation(target->GetOrientation() + offset)) * (velocity * 2);

            // Now we calculate out actual destination data
            if (!owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
            {
                float relativeAngle = target->GetRelativeAngle(dest);
                float distance = target->GetExactDist2d(dest);
                dest = target->GetPosition();
                target->MovePositionToFirstCollision(dest, distance, relativeAngle);
            }

            Movement::MoveSplineInit init(owner);
            init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
            if (velocity > 0.f)
                init.SetVelocity(velocity);
            init.Launch();

            _hasStopped = false;
            owner->AddUnitState(UNIT_STATE_FOLLOW_MOVE);
            _followMovementTimer.Reset(FOLLOW_MOVEMENT_INTERVAL);
        }
    }

    // Follow target has stopped moving, allign to current position and inform AI
    // (Note: for WoD and beyond this rule only applies to regular followers. Pets, Guardians, Minions etc. stop in the next update cycle)
    if (!_hasStopped && target->movespline->Finalized() && !target->isMoving())
    {
        // select angle
        float tAngle = 0.f;
        float const curAngle = target->GetRelativeAngle(owner);
        if (_angle.IsAngleOkay(curAngle))
            tAngle = curAngle;
        else
        {
            float const diffUpper = Position::NormalizeOrientation(curAngle - _angle.UpperBound());
            float const diffLower = Position::NormalizeOrientation(_angle.LowerBound() - curAngle);
            if (diffUpper < diffLower)
                tAngle = _angle.UpperBound();
            else
                tAngle = _angle.LowerBound();
        }

        Position dest = target->GetPosition();
        if (!owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
            target->MovePositionToFirstCollision(dest, _range + target->GetBoundaryRadius() + owner->GetBoundaryRadius(), tAngle);
        else
        {
            dest.m_positionX += std::cos(Position::NormalizeOrientation(target->GetOrientation() + tAngle)) * (_range + target->GetBoundaryRadius() + owner->GetBoundaryRadius());
            dest.m_positionY += std::sin(Position::NormalizeOrientation(target->GetOrientation() + tAngle)) * (_range + target->GetBoundaryRadius() + owner->GetBoundaryRadius());
        }

        Movement::MoveSplineInit init(owner);
        init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
        init.SetFacing(target->GetOrientation());
        init.Launch();

        _followMovementTimer.Reset(FOLLOW_MOVEMENT_INTERVAL); // block excessive movement launching via stutter stepping
        _hasStopped = true;
        return true;
    }

    if (owner->HasUnitState(UNIT_STATE_FOLLOW_MOVE) && owner->movespline->Finalized())
    {
        owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
        owner->SetFacingTo(target->GetOrientation()); // according to sniffs we launch a extra spline just for the facing
        DoMovementInform(owner, target);
    }

    return true;
}

void FollowMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_FOLLOW_MOVE);
}
