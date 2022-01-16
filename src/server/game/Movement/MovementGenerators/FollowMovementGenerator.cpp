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
#include "EventProcessor.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "Util.h"
#include <optional>

// Helpers
inline UnitMoveType SelectSpeedType(uint32 moveFlags)
{
    if (moveFlags & MOVEMENTFLAG_FLYING)
    {
        if (moveFlags & MOVEMENTFLAG_BACKWARD)
            return MOVE_FLIGHT_BACK;
        else
            return MOVE_FLIGHT;
    }
    else if (moveFlags & MOVEMENTFLAG_SWIMMING)
    {
        if (moveFlags & MOVEMENTFLAG_BACKWARD)
            return MOVE_SWIM_BACK;
        else
            return MOVE_SWIM;
    }
    else if (moveFlags & MOVEMENTFLAG_WALKING)
        return MOVE_WALK;
    else if (moveFlags & MOVEMENTFLAG_BACKWARD)
        return MOVE_RUN_BACK;

    return MOVE_RUN;
}

inline bool IsTargetMoving(Unit const* target)
{
    return target->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT) || !target->movespline->Finalized();
}

inline float GetVelocity(Unit* owner, Unit* target, bool catchUp)
{
    float targetSpeed = 0.f;
    float velocity = 0.f;
    if (target->IsPlayer())
        targetSpeed = target->GetSpeed(SelectSpeedType(target->m_movementInfo.GetMovementFlags()));
    else
    {
        if (!target->movespline->Finalized())
            targetSpeed = target->movespline->Velocity();
        else
            targetSpeed = target->GetSpeed(MOVE_RUN);
    }

    if (catchUp)
        velocity = targetSpeed;
    else
    {
        if (owner->IsFlying())
            velocity = owner->GetSpeed(MOVE_FLIGHT);
        else if (!owner->IsWalking())
            velocity = owner->GetSpeed(MOVE_RUN);
        else
            velocity = owner->GetSpeed(MOVE_WALK);

        // Owner might be able to walk faster than its target so we limit the speed
        //velocity = std::min<float>(velocity, targetSpeed);
    }

    return velocity;
}

static void ApplyCatchUpMod(Unit* owner, Position dest, float& velocity)
{
    float distance = owner->GetExactDist2d(dest);

    if (!dest.HasInArc(float(M_PI), owner)) // owner is falling back. Catch up
        AddPct(velocity, ((distance / velocity) * 100.f));
    else if (distance < 3.f)
        AddPct(velocity, -((distance / velocity) * 100.f));
}

static void DoMovementInform(Unit* owner, Unit* target)
{
    if (owner->GetTypeId() != TYPEID_UNIT)
        return;

    if (CreatureAI* AI = owner->ToCreature()->AI())
        AI->MovementInform(FOLLOW_MOTION_TYPE, target->GetGUID().GetCounter());
}

static void GetFollowOffsets(uint8 followerIndex, float& distance, float& relativeAngle)
{
    uint8 rowOffset = 0;

    if (followerIndex >= DEFAULT_ROW_FOLLOWERS)
        rowOffset = std::floor<uint8>((followerIndex - DEFAULT_ROW_FOLLOWERS) / MAX_FOLLOWERS_PER_ROW);
    else
    {
        // Default left and right follower slots
        distance = STRAIGHT_FOLLOW_DISTANCE;
        relativeAngle = followerIndex == 0 ? float(M_PI_2) : float(-M_PI_2);
        return;
    }

    // Further follower slots. Calculating a place in further rows
    uint8 rowIndex = (followerIndex - DEFAULT_ROW_FOLLOWERS) % MAX_FOLLOWERS_PER_ROW;

    // Blizzard assigns new followers in a left-right repeat pattern rather than just going from left to right
    bool left = rowIndex % 2;
    Position pos;
    pos.RelocateOffset({ 0.f, left ? -STRAIGHT_FOLLOW_DISTANCE : STRAIGHT_FOLLOW_DISTANCE });

    if (rowIndex <= 3)
    {
        pos.RelocateOffset({ -(STRAIGHT_FOLLOW_DISTANCE * rowOffset) });

        // Inner and outer positions
        float angle = float(M_PI);
        if (rowIndex <= 1)
            angle += left ? float(-(M_PI_4 / 2)) : float(M_PI_4 / 2);
        else
            angle += left ? float(M_PI_4 / 2) : float(-(M_PI_4 / 2));

        pos.m_positionX += std::cos(angle) * SIDE_FOLLOW_DISTANCE;
        pos.m_positionY += std::sin(angle) * SIDE_FOLLOW_DISTANCE;
    }
    else
    {
        // Middle positions
        pos.RelocateOffset({ -(STRAIGHT_FOLLOW_DISTANCE + STRAIGHT_FOLLOW_DISTANCE * rowOffset) });
    }

    distance = Position().GetExactDist2d(pos);
    relativeAngle = Position().GetRelativeAngle(pos);
}

FollowMovementGenerator::FollowMovementGenerator(Unit* target, Optional<float> distance, Optional<float> angle, bool joinFormation /*= true*/, bool catchUpToTarget /*= false*/, bool faceTarget /*= false*/) :
    AbstractPursuer(PursuingType::Follow, ASSERT_NOTNULL(target)), _joinFormation(joinFormation), _catchUpToTarget(catchUpToTarget), _faceTarget(faceTarget)
{
    _distance = distance ? distance.value() : 0.f;
    _angle = angle ? angle.value() : 0.f;
}

FollowMovementGenerator::~FollowMovementGenerator() { }

void FollowMovementGenerator::Initialize(Unit* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW);

    Unit* target = GetTarget();
    // owner joins a organized follower formation.
    if (_joinFormation && target)
    {
        target->AddFormationFollower(owner);
        UpdateFollowFormation();
    }

    _followMovementTimer.Reset(0);
    _events.ScheduleEvent(EVENT_ALLIGN_TO_TARGET, Milliseconds(ALLIGN_MOVEMENT_INTERVAL));
}

void FollowMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_FOLLOW_MOVE);

    Unit* target = GetTarget();
    if (_joinFormation && target)
    {
        target->RemoveFormationFollower(owner);
        UpdateFollowFormation();
    }
}

void FollowMovementGenerator::Reset(Unit* /*owner*/)
{
    _followMovementTimer.Reset(0);
    _events.ScheduleEvent(EVENT_ALLIGN_TO_TARGET, 1ms);
}

bool FollowMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // Owner might be dead or gone
    if (!owner->IsAlive())
        return false;

    Unit* target = GetTarget();

    // Our target might have gone away
    if (!target || !target->IsInWorld() || !target->IsAlive())
        return false;

    // Follower cannot move at the moment
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        owner->StopMoving();
        _followMovementTimer.Reset(0);
        return true;
    }

    // Default follow movement procedure when target is moving
    _followMovementTimer.Update(diff);
    if (_followMovementTimer.Passed())
    {

        _followMovementTimer.Reset(FOLLOW_MOVEMENT_INTERVAL);
        if (IsTargetMoving(target))
        {
            _events.Reset();
            LaunchMovement(owner);
            return true;
        }
        else if (owner->HasUnitState(UNIT_STATE_FOLLOW_MOVE))
        {
            owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
            DoMovementInform(owner, target);

            if (!_faceTarget)
            {
                owner->StopMoving();
                _events.ScheduleEvent(EVENT_ALLIGN_TO_TARGET, Milliseconds(ALLIGN_MOVEMENT_INTERVAL));
            }
            else
                _events.ScheduleEvent(EVENT_ALLIGN_TO_TARGET, 1ms);
        }
    }

    _events.Update(diff);
    while (uint32 eventId = _events.ExecuteEvent())
    {
        switch (eventId)
        {
            case EVENT_ALLIGN_TO_TARGET:
            {
                Position pos = target->GetPosition();
                target->MovePositionToFirstCollision(pos, _distance, _angle);

                Movement::MoveSplineInit init (owner);
                if (_faceTarget)
                    init.SetFacing(target);
                init.MoveTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                uint32 duration = std::max<uint32>(1, init.Launch());

                if (!_faceTarget)
                    _events.ScheduleEvent(EVENT_ALLIGN_TO_FACING_DIRECTION, Milliseconds(duration + FOLLOW_MOVEMENT_INTERVAL));
                break;
            }
            case EVENT_ALLIGN_TO_FACING_DIRECTION:
                owner->SetFacingTo(target->GetOrientation());
                break;
            default:
                break;
        }
    }

    return true;
}

void FollowMovementGenerator::UpdateFollowFormation()
{
    Unit* target = GetTarget();
    uint8 followSlot = 0;
    for (ObjectGuid guid : target->GetFormationFollowers())
    {
        if (Unit* follower = ObjectAccessor::GetUnit(*target, guid))
        {
            for (uint8 slot = MOTION_SLOT_IDLE; slot < MAX_MOTION_SLOT; ++slot)
            {
                MovementGenerator* moveGen = follower->GetMotionMaster()->GetMotionSlot(MovementSlot(slot));
                if (!moveGen || moveGen->GetMovementGeneratorType() != FOLLOW_MOTION_TYPE)
                    continue;

                if (FollowMovementGenerator* followMoveGen = static_cast<FollowMovementGenerator*>(moveGen))
                    followMoveGen->UpdateFormationFollowOffsets(followSlot);
            }

            ++followSlot;
        }
    }
}

void FollowMovementGenerator::UpdateFormationFollowOffsets(uint32 slot)
{
    // Do not update follow values for follow targets that are not part of the follow formation.
    if (!_joinFormation)
        return;

    GetFollowOffsets(slot, _distance, _angle);
};

void FollowMovementGenerator::LaunchMovement(Unit* owner)
{
    Unit* target = GetTarget();
    Position dest = target->GetPosition();
    float offset = 0.f;

    // Strafe handling for player sidewards movement
    if (target->IsPlayer())
        offset = target->m_movementInfo.GetMovementDirection();

    // Let's start with a cheap base destination calculation
    dest.m_positionX += std::cos(Position::NormalizeOrientation(target->GetOrientation() + _angle)) * _distance;
    dest.m_positionY += std::sin(Position::NormalizeOrientation(target->GetOrientation() + _angle)) * _distance;
    dest.SetOrientation(dest.GetOrientation() + offset);

    // Calculate velocity based on target's speed values
    float velocity = GetVelocity(owner, target, (_joinFormation || _catchUpToTarget));
    if (velocity == 0.f)
        return;

    // Calculate catchup speed values if owner follows its target in a formation
    if (_joinFormation || _catchUpToTarget)
        ApplyCatchUpMod(owner, dest, velocity);

    if (velocity <= 0.1f)
        return;

    // Predicting our follow destination if the owner is slower or equally as fast as the target
    bool predictDestination = (!_joinFormation && !_catchUpToTarget && velocity < target->GetSpeed(SelectSpeedType(target->m_movementInfo.GetMovementFlags())))
        || (_joinFormation || _catchUpToTarget);

    if (predictDestination)
    {
        dest.m_positionX += std::cos(Position::NormalizeOrientation(target->GetOrientation() + offset)) * velocity;
        dest.m_positionY += std::sin(Position::NormalizeOrientation(target->GetOrientation() + offset)) * velocity;
    }

    // Now we calculate our actual destination data
    if (!owner->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
    {
        float relativeAngle = target->GetRelativeAngle(dest);
        float distance = target->GetExactDist2d(dest);
        dest = target->GetPosition();
        target->MovePositionToFirstCollision(dest, distance, relativeAngle);
    }

    Movement::MoveSplineInit init(owner);
    init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
    init.SetVelocity(velocity);

    if (_faceTarget)
        init.SetFacing(target);

    init.Launch();

    owner->AddUnitState(UNIT_STATE_FOLLOW_MOVE);
}
