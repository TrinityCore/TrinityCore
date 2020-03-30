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
            float destOrientation = target->GetOrientation();
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

                destOrientation += offset;
            }

            target->MovePositionToFirstCollision(dest, _range + target->GetBoundaryRadius() + owner->GetBoundaryRadius(), _angle.RelativeAngle);
            dest.SetOrientation(destOrientation);

            // Determine our velocity
            float velocity = 0.f;
            if (_useTargetSpeed)
            {
                velocity = target->IsWalking() ? target->GetSpeed(MOVE_WALK) : target->GetSpeed(MOVE_RUN);

                // Backwards player movement speed
                if (target->IsPlayer() && target->HasUnitMovementFlag(MOVEMENTFLAG_BACKWARD))
                    velocity = target->GetSpeed(MOVE_RUN_BACK);
            }
            else
                velocity = owner->IsWalking() ? owner->GetSpeed(MOVE_WALK) : owner->GetSpeed(MOVE_RUN);

            // Follow target based speed allignment
            float distance = owner->GetExactDist2d(dest);
            if (_useTargetSpeed)
            {

                // Determine catchup speed rate
                if (!dest.HasInArc(float(M_PI), owner)) // follower is behind follow destination
                {
                    // Limit catchup speed to a total of 1.5 times of the follow target's velocity
                    float distMod = 1.f + std::min<float>(distance * 0.1f, 0.5f);
                    velocity *= distMod;
                }
                else if (distance > (velocity / 2))
                {
                    // We are beyond our destination, throttle movement to fall back
                    float distMod = 1.f - std::min<float>((distance - (velocity / 2)) * 0.1f, 0.5f);
                    velocity *= distMod;
                }
            }

            // Move our destination ahead (according to sniffs, it's roundabout velocity * 2)
            target->MovePositionToFirstCollision(dest, (velocity * 2) - distance, offset);

            Movement::MoveSplineInit init(owner);
            init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
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
        target->MovePositionToFirstCollision(dest, _range + target->GetBoundaryRadius() + owner->GetBoundaryRadius(), tAngle);

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
