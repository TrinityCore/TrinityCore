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

#include "FollowMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "Optional.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "Player.h"
#include "Unit.h"
#include "Util.h"

static void DoMovementInform(Unit* owner, Unit* target)
{
    if (owner->GetTypeId() != TYPEID_UNIT)
        return;

    if (CreatureAI* AI = owner->ToCreature()->AI())
        AI->MovementInform(FOLLOW_MOTION_TYPE, target->GetGUID().GetCounter());
}

FollowMovementGenerator::FollowMovementGenerator(Unit* target, float range, ChaseAngle angle) : AbstractFollower(ASSERT_NOTNULL(target)), _range(range), _angle(angle)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_FOLLOW;
}
FollowMovementGenerator::~FollowMovementGenerator() = default;

static bool PositionOkay(Unit* owner, Unit* target, float range, Optional<ChaseAngle> angle = {})
{
    if (owner->GetExactDistSq(target) > square(owner->GetCombatReach() + target->GetCombatReach() + range))
        return false;

    return !angle || angle->IsAngleOkay(target->GetRelativeAngle(owner));
}

void FollowMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    owner->StopMoving();
    UpdatePetSpeed(owner);
    _path = nullptr;
    _lastTargetPosition.reset();
}

void FollowMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
}

bool FollowMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // owner might be dead or gone
    if (!owner || !owner->IsAlive())
        return false;

    // our target might have gone away
    Unit* const target = GetTarget();
    if (!target || !target->IsInWorld())
        return false;

    if (owner->IsJumping())
        return true;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        owner->StopMoving();
        _lastTargetPosition.reset();
        return true;
    }

    if (owner->HasUnitState(UNIT_STATE_FOLLOW_MOVE))
    {
        if (_checkTimer > diff)
            _checkTimer -= diff;
        else
        {
            _checkTimer = CHECK_INTERVAL;
            if (PositionOkay(owner, target, _range, _angle))
            {
                _path = nullptr;
                owner->StopMoving();
                DoMovementInform(owner, target);
                return true;
            }
        }
    }

    if (owner->HasUnitState(UNIT_STATE_FOLLOW_MOVE) && owner->movespline->Finalized())
    {
        _path = nullptr;
        owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
        DoMovementInform(owner, target);
    }

    if (!_lastTargetPosition || _lastTargetPosition->GetExactDistSq(target->GetPosition()) > 0.0f)
    {
        _lastTargetPosition = target->GetPosition();
        if (owner->HasUnitState(UNIT_STATE_FOLLOW_MOVE) || !PositionOkay(owner, target, _range + FOLLOW_RANGE_TOLERANCE))
        {
            if (!_path)
                _path = std::make_unique<PathGenerator>(owner);

            float x, y, z;

            // select angle
            float tAngle;
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

            target->GetNearPoint(owner, x, y, z, _range, target->ToAbsoluteAngle(tAngle));

            if (owner->IsHovering())
                owner->UpdateAllowedPositionZ(x, y, z);

            // pets are allowed to "cheat" on pathfinding when following their master
            bool allowShortcut = false;
            if (Pet* oPet = owner->ToPet())
            {
                if (target->GetGUID() == oPet->GetOwnerGUID())
                    allowShortcut = true;
            }

            bool transport = owner->GetTransport();
            bool success = _path->CalculatePath(x, y, z, allowShortcut);
            if (!transport)
            {
                if (!success || (_path->GetPathType() & PATHFIND_NOPATH))
                {
                    if (owner->GetOwner() && owner->GetOwner()->ToPlayer() && owner->GetOwner()->ToPlayer()->InArena()) // arena force destination for pet (arena nagrand)
                    {
                        Movement::MoveSplineInit init(owner);
                        init.MoveTo(x, y, z, true, true);
                        init.SetWalk(false);
                        init.SetFacing(target);
                        init.Launch();
                        return true;
                    }

                    owner->StopMoving();
                }
            }
            else
            {
                // check dynamic collision
                bool dcol = owner->GetMap()->getObjectHitPos(owner->GetPhaseMask(), owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ() + 0.5f, x, y, z + 0.5f, x, y, z, -0.5f);
                // collision occured
                if (dcol && (z < owner->GetOwner()->GetPositionZ()))
                {
                    // move back a bit
                    x -= CONTACT_DISTANCE * std::cos(owner->GetOrientation());
                    y -= CONTACT_DISTANCE * std::sin(owner->GetOrientation());
                    if (Map* map = owner->GetMap())
                        z = map->GetHeight(owner->GetPhaseMask(), x, y, z + 2.8f, true);
                }

                if (z < target->GetPositionZ())
                    z = target->GetPositionZ();
            }

            owner->AddUnitState(UNIT_STATE_FOLLOW_MOVE);

            Movement::MoveSplineInit init(owner);
            if (!transport)
                init.MovebyPath(_path->GetPath());
            else
                init.MoveTo(x, y, z, false, true);
            bool walk;
            if (owner->GetOwner() && owner->GetOwner()->ToPlayer())
                walk = owner->GetOwner()->ToPlayer()->HasWalkingFlag();
            else
                walk = target->IsWalking();
            init.SetWalk(walk);
            init.SetFacing(target->GetOrientation());
            init.Launch();
        }
    }
    return true;
}

void FollowMovementGenerator::Deactivate(Unit* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
}

void FollowMovementGenerator::Finalize(Unit* owner, bool active, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
        UpdatePetSpeed(owner);
    }
}

void FollowMovementGenerator::UpdatePetSpeed(Unit* owner)
{
    if (Pet* oPet = owner->ToPet())
    {
        if (!GetTarget() || GetTarget()->GetGUID() == owner->GetOwnerGUID())
        {
            oPet->UpdateSpeed(MOVE_RUN);
            oPet->UpdateSpeed(MOVE_WALK);
            oPet->UpdateSpeed(MOVE_SWIM);
        }
    }
}
