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
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Unit.h"
#include "Util.h"

static bool HasLostTarget(Unit* owner, Unit* target)
{
    return owner->GetVictim() != target;
}

static bool IsMutualChase(Unit* owner, Unit* target)
{
    if (target->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
        return false;

    if (ChaseMovementGenerator* movement = dynamic_cast<ChaseMovementGenerator*>(target->GetMotionMaster()->GetCurrentMovementGenerator()))
        return movement->GetTarget() == owner;

    return false;
}

static bool PositionOkay(Unit* owner, Unit* target, Optional<float> minDistance, Optional<float> maxDistance, Optional<ChaseAngle> angle)
{
    float const distSq = owner->GetExactDistSq(target);
    if (minDistance && distSq < square(*minDistance))
        return false;
    if (maxDistance && distSq > square(*maxDistance))
        return false;
    if (angle && !angle->IsAngleOkay(target->GetRelativeAngle(owner)))
        return false;
    if (!owner->IsWithinLOSInMap(target))
        return false;
    return true;
}

static void DoMovementInform(Unit* owner, Unit* target)
{
    if (owner->GetTypeId() != TYPEID_UNIT)
        return;

    if (CreatureAI* AI = owner->ToCreature()->AI())
        AI->MovementInform(CHASE_MOTION_TYPE, target->GetGUID().GetCounter());
}

ChaseMovementGenerator::ChaseMovementGenerator(Unit *target, Optional<ChaseRange> range, Optional<ChaseAngle> angle) : AbstractFollower(ASSERT_NOTNULL(target)), _range(range),
    _angle(angle), _rangeCheckTimer(RANGE_CHECK_INTERVAL)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_CHASE;
}
ChaseMovementGenerator::~ChaseMovementGenerator() = default;

void ChaseMovementGenerator::Initialize(Unit* /*owner*/)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED | MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);

    _path = nullptr;
    _lastTargetPosition.reset();
}

void ChaseMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
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

    // the owner might be unable to move (rooted or casting), or we have lost the target, pause movement
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || HasLostTarget(owner, target))
    {
        owner->StopMoving();
        _lastTargetPosition.reset();
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);
        return true;
    }

    bool const mutualChase = IsMutualChase(owner, target);
    float const hitboxSum = owner->GetCombatReach() + target->GetCombatReach();
    float const minRange = _range ? _range->MinRange + hitboxSum : CONTACT_DISTANCE;
    float const minTarget = (_range ? _range->MinTolerance : 0.0f) + hitboxSum;
    float const maxRange = _range ? _range->MaxRange + hitboxSum : owner->GetMeleeRange(target); // melee range already includes hitboxes
    float const maxTarget = _range ? _range->MaxTolerance + hitboxSum : CONTACT_DISTANCE + hitboxSum;
    Optional<ChaseAngle> angle = mutualChase ? Optional<ChaseAngle>() : _angle;

    // periodically check if we're already in the expected range...
    _rangeCheckTimer.Update(diff);
    if (_rangeCheckTimer.Passed())
    {
        _rangeCheckTimer.Reset(RANGE_CHECK_INTERVAL);
        if (HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && PositionOkay(owner, target, _movingTowards ? Optional<float>() : minTarget, _movingTowards ? maxTarget : Optional<float>(), angle))
        {
            RemoveFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            _path = nullptr;
            if (Creature* cOwner = owner->ToCreature())
                cOwner->SetCannotReachTarget(false);
            owner->StopMoving();
            owner->SetInFront(target);
            DoMovementInform(owner, target);
            return true;
        }
    }

    // if we're done moving, we want to clean up
    if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) && owner->movespline->Finalized())
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        _path = nullptr;
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);
        owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
        owner->SetInFront(target);
        DoMovementInform(owner, target);
    }

    // if the target moved, we have to consider whether to adjust
    if (!_lastTargetPosition || target->GetPosition() != _lastTargetPosition.value() || mutualChase != _mutualChase)
    {
        _lastTargetPosition = target->GetPosition();
        _mutualChase = mutualChase;
        if (owner->HasUnitState(UNIT_STATE_CHASE_MOVE) || !PositionOkay(owner, target, minRange, maxRange, angle))
        {
            Creature* const cOwner = owner->ToCreature();
            // can we get to the target?
            if (cOwner && !target->isInAccessiblePlaceFor(cOwner))
            {
                cOwner->SetCannotReachTarget(true);
                cOwner->StopMoving();
                _path = nullptr;
                return true;
            }

            // figure out which way we want to move
            bool const moveToward = !owner->IsInDist(target, maxRange);

            // make a new path if we have to...
            if (!_path || moveToward != _movingTowards)
                _path = std::make_unique<PathGenerator>(owner);

            float x, y, z;
            bool shortenPath;
            // if we want to move toward the target and there's no fixed angle...
            if (moveToward && !angle)
            {
                // ...we'll pathfind to the center, then shorten the path
                target->GetPosition(x, y, z);
                shortenPath = true;
            }
            else
            {
                // otherwise, we fall back to nearpoint finding
                target->GetNearPoint(owner, x, y, z, (moveToward ? maxTarget : minTarget) - hitboxSum, angle ? target->ToAbsoluteAngle(angle->RelativeAngle) : target->GetAbsoluteAngle(owner));
                shortenPath = false;
            }

            if (owner->IsHovering())
                owner->UpdateAllowedPositionZ(x, y, z);

            bool success = _path->CalculatePath(x, y, z, owner->CanFly());
            if (!success || (_path->GetPathType() & (PATHFIND_NOPATH /* | PATHFIND_INCOMPLETE*/)))
            {
                if (cOwner)
                    cOwner->SetCannotReachTarget(true);
                owner->StopMoving();
                return true;
            }

            if (shortenPath)
                _path->ShortenPathUntilDist(PositionToVector3(target), maxTarget);

            if (cOwner)
                cOwner->SetCannotReachTarget(false);

            bool walk = false;
            if (cOwner && !cOwner->IsPet())
            {
                switch (cOwner->GetMovementTemplate().GetChase())
                {
                    case CreatureChaseMovementType::CanWalk:
                        walk = owner->IsWalking();
                        break;
                    case CreatureChaseMovementType::AlwaysWalk:
                        walk = true;
                        break;
                    default:
                        break;
                }
            }

            owner->AddUnitState(UNIT_STATE_CHASE_MOVE);
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);

            Movement::MoveSplineInit init(owner);
            init.MovebyPath(_path->GetPath());
            init.SetWalk(walk);
            init.SetFacing(target);
            init.Launch();
        }
    }

    // and then, finally, we're done for the tick
    return true;
}

void ChaseMovementGenerator::Deactivate(Unit* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
    owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
    if (Creature* cOwner = owner->ToCreature())
        cOwner->SetCannotReachTarget(false);
}

void ChaseMovementGenerator::Finalize(Unit* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
        if (Creature* cOwner = owner->ToCreature())
            cOwner->SetCannotReachTarget(false);
    }
}
