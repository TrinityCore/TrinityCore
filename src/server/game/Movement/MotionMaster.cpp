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

#include "MotionMaster.h"
#include "ChaseMovementGenerator.h"
#include "ConfusedMovementGenerator.h"
#include "Creature.h"
#include "CreatureAISelector.h"
#include "CyclicMovementGenerator.h"
#include "DBCStores.h"
#include "G3DPosition.hpp"
#include "FleeingMovementGenerator.h"
#include "FlightPathMovementGenerator.h"
#include "FollowMovementGenerator.h"
#include "FormationMovementGenerator.h"
#include "GenericMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "Player.h"
#include "PointMovementGenerator.h"
#include "RandomMovementGenerator.h"
#include "ScriptSystem.h"
#include "SplineChainMovementGenerator.h"
#include "Unit.h"
#include "WaypointDefines.h"
#include "WaypointMovementGenerator.h"
#include "WaypointManager.h"

inline MovementGenerator* GetIdleMovementGenerator()
{
    return sMovementGeneratorRegistry->GetRegistryItem(IDLE_MOTION_TYPE)->Create();
}

inline bool IsStatic(MovementGenerator* movement)
{
    return (movement == GetIdleMovementGenerator());
}

MotionMaster::~MotionMaster()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator* movement = top();
        pop();
        if (movement && !IsStatic(movement))
            delete movement;
    }

    while (!_expireList.empty())
    {
        delete _expireList.back();
        _expireList.pop_back();
    }
}

void MotionMaster::Initialize()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator* curr = top();
        pop();
        if (curr)
            DirectDelete(curr);
    }

    InitDefault();
}

// set new default movement generator
void MotionMaster::InitDefault()
{
    Mutate(FactorySelector::SelectMovementGenerator(_owner), MOTION_SLOT_IDLE);
}

void MotionMaster::UpdateMotion(uint32 diff)
{
    if (!_owner)
        return;

    ASSERT(!empty());

    _cleanFlag |= MMCF_UPDATE;
    if (!top()->Update(_owner, diff))
    {
        _cleanFlag &= ~MMCF_UPDATE;
        MovementExpired();
    }
    else
        _cleanFlag &= ~MMCF_UPDATE;

    if (!_expireList.empty())
        ClearExpireList();
}

void MotionMaster::Clear(bool reset /*= true*/)
{
    if (_cleanFlag & MMCF_UPDATE)
    {
        if (reset)
            _cleanFlag |= MMCF_RESET;
        else
            _cleanFlag &= ~MMCF_RESET;
        DelayedClean();
    }
    else
        DirectClean(reset);
}

void MotionMaster::Clear(MovementSlot slot)
{
    if (empty() || IsInvalidMovementSlot(slot))
        return;

    if (_cleanFlag & MMCF_UPDATE)
        DelayedClean(slot);
    else
        DirectClean(slot);
}

void MotionMaster::MovementExpired(bool reset /*= true*/)
{
    if (_cleanFlag & MMCF_UPDATE)
    {
        if (reset)
            _cleanFlag |= MMCF_RESET;
        else
            _cleanFlag &= ~MMCF_RESET;
        DelayedExpire();
    }
    else
        DirectExpire(reset);
}

MovementSlot MotionMaster::GetCurrentSlot() const
{
    if (empty() || (_slot[MOTION_SLOT_IDLE] && !_slot[MOTION_SLOT_ACTIVE]))
        return MOTION_SLOT_IDLE;

    if (_slot[MOTION_SLOT_ACTIVE])
        return MOTION_SLOT_ACTIVE;

    if (_slot[MOTION_SLOT_CONTROLLED])
        return MOTION_SLOT_CONTROLLED;

    return MAX_MOTION_SLOT;
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
    if (empty())
        return IDLE_MOTION_TYPE;

    if (topOrNull())
        return top()->GetMovementGeneratorType();
    else
        return IDLE_MOTION_TYPE;
}

MovementGeneratorType MotionMaster::GetMotionSlotType(MovementSlot slot) const
{
    if (empty() || IsInvalidMovementSlot(slot) || !_slot[slot])
        return MAX_MOTION_TYPE;

    return _slot[slot]->GetMovementGeneratorType();
}

MovementGenerator* MotionMaster::GetMotionSlot(MovementSlot slot) const
{
    if (empty() || IsInvalidMovementSlot(slot) || !_slot[slot])
        return nullptr;

    return _slot[slot];
}

void MotionMaster::PropagateSpeedChange()
{
    if (empty())
        return;

    MovementGenerator* movement = top();
    if (!movement)
        return;

    movement->UnitSpeedChanged();
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    if (_owner->movespline->Finalized())
        return false;

    G3D::Vector3 const& dest = _owner->movespline->FinalDestination();
    x = dest.x;
    y = dest.y;
    z = dest.z;
    return true;
}

void MotionMaster::MoveIdle()
{
    //! Should be preceded by MovementExpired or Clear if there's an overlying movementgenerator active
    if (empty() || !IsStatic(top()))
        Mutate(GetIdleMovementGenerator(), MOTION_SLOT_IDLE);
}

void MotionMaster::MoveTargetedHome()
{
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', attempted to move towards target home.", _owner->GetGUID().ToString().c_str());
        return;
    }

    Clear(false);

    Unit* target = owner->GetCharmerOrOwner();
    if (!target)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', targeted home.", _owner->GetGUID().ToString().c_str());
        Mutate(new HomeMovementGenerator<Creature>(), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', starts following '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
        owner->FollowTarget(target);
    }
}

void MotionMaster::MoveRandom(float wanderDistance)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRandom: '%s', started random movement (spawnDist: %f)", _owner->GetGUID().ToString().c_str(), wanderDistance);
        Mutate(new RandomMovementGenerator<Creature>(wanderDistance), MOTION_SLOT_IDLE);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle, bool joinFormation /*= false*/, bool catchUpToTarget /*= false*/, bool faceTarget /*= false*/, MovementSlot slot /*= MOTION_SLOT_IDLE*/)
{
    // ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFollow: '%s', starts following '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());

    Mutate(new FollowMovementGenerator(target, dist, angle, joinFormation, catchUpToTarget, faceTarget), slot);
}

void MotionMaster::MoveChase(Unit* target, Optional<float> dist /*= std::nullopt*/, Optional<ChaseAngle> angle /*= std::nullopt*/)
{
    // ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveChase: '%s', starts chasing '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
    Mutate(new ChaseMovementGenerator(target, dist, angle), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveConfused()
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '%s', started confused movement.", _owner->GetGUID().ToString().c_str());
        Mutate(new ConfusedMovementGenerator<Player>(), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '%s', started confused movement.", _owner->GetGUID().ToString().c_str());
        Mutate(new ConfusedMovementGenerator<Creature>(), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFleeing: '%s', flees from '%s' (time: %u)", _owner->GetGUID().ToString().c_str(), enemy->GetGUID().ToString().c_str(), time);
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetGUID(), time), MOTION_SLOT_CONTROLLED);
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
    else
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, bool generatePath, float speed)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePoint: '%s', targeted point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath, speed), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePoint: '%s', targeted point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath, speed), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveCloserAndStop(uint32 id, Unit* target, float distance)
{
    float distanceToTravel = _owner->GetExactDist2d(target) - distance;
    if (distanceToTravel > 0.0f)
    {
        float angle = _owner->GetAngle(target);
        float destx = _owner->GetPositionX() + distanceToTravel * std::cos(angle);
        float desty = _owner->GetPositionY() + distanceToTravel * std::sin(angle);
        MovePoint(id, destx, desty, target->GetPositionZ());
    }
    else
    {
        // we are already close enough. We just need to turn toward the target without changing position.
        Movement::MoveSplineInit init(_owner);
        init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        init.SetFacing(target);
        Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos, Optional<float> velocity /*= { }*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveLand: '%s', landing point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(PositionToVector3(pos), false);
    init.SetSmooth();
    init.SetFly();
    init.SetAnimation(AnimationTier::Ground);
    if (velocity)
        init.SetVelocity(velocity.value());
    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos, Optional<float> velocity /*= { }*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTakeoff: '%s', landing point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(PositionToVector3(pos), false);
    init.SetSmooth();
    init.SetFly();
    init.SetAnimation(AnimationTier::Hover);
    if (velocity)
        init.SetVelocity(velocity.value());
    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed /*= SPEED_CHARGE*/, uint32 id /*= EVENT_CHARGE*/, bool generatePath /*= false*/)
{
    if (_slot[MOTION_SLOT_CONTROLLED] && _slot[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveCharge: '%s', charging point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath, speed), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveCharge: '%s', charging point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath, speed), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveCharge(PathGenerator const& path, float speed /*= SPEED_CHARGE*/)
{
    G3D::Vector3 dest = path.GetActualEndPosition();

    MoveCharge(dest.x, dest.y, dest.z, speed, EVENT_CHARGE_PREPATH);

    // Charge movement is not started when using EVENT_CHARGE_PREPATH
    Movement::MoveSplineInit init(_owner);
    init.MovebyPath(path.GetPath());
    init.SetVelocity(speed);
    init.Launch();
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    if (speedXY < 0.01f)
        return;

    Position dest = _owner->GetPosition();
    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    // Use a mmap raycast to get a valid destination.
    _owner->MovePositionToFirstCollision(dest, dist, _owner->GetRelativeAngle(srcX, srcY) + float(M_PI));

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), false);
    init.SetParabolic(max_height, 0);
    init.SetOrientationFixed(true);
    init.SetVelocity(speedXY);
    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, 0), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveJumpTo(float angle, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z = _owner->GetPositionZ();

    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    _owner->GetNearPoint2D(nullptr, x, y, dist, _owner->GetOrientation() + angle);
    _owner->UpdateAllowedPositionZ(x, y, z);
    MoveJump(x, y, z, 0.0f, speedXY, speedZ);
}

void MotionMaster::MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id, bool hasOrientation /* = false*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveJump: '%s', jumps to point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
    if (speedXY < 0.01f)
        return;

    float moveTimeHalf = speedZ / Movement::gravity;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(x, y, z, false);
    init.SetParabolic(max_height, 0);
    init.SetVelocity(speedXY);
    if (hasOrientation)
        init.SetFacing(o);

    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveJumpWithGravity(Position const& pos, float speedXY, float gravity, uint32 id, bool hasOrientation /* = false*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveJump: '%s', jumps to point Id: %u (%s)", _owner->GetGUID().ToString().c_str(), id, pos.ToString().c_str());
    if (speedXY < 0.01f)
        return;

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), false);
    init.SetParabolicVerticalAcceleration(gravity, 0);
    init.SetVelocity(speedXY);
    if (hasOrientation)
        init.SetFacing(pos.GetOrientation());

    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount, float velocity /*= 0.f*/)
{
    float step = 2 * float(M_PI) / stepCount * (clockwise ? -1.0f : 1.0f);
    Position const& pos = { x, y, z, 0.0f };
    float angle = pos.GetAngle(_owner->GetPositionX(), _owner->GetPositionY());

    Movement::MoveSplineInit init(_owner);

    // add the owner's current position as starting point as it gets removed after entering the cycle
    init.Path().push_back(G3D::Vector3(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ()));

    for (uint8 i = 0; i < stepCount; angle += step, ++i)
    {
        G3D::Vector3 point;
        point.x = x + radius * cosf(angle);
        point.y = y + radius * sinf(angle);

        if (_owner->IsFlying())
            point.z = z;
        else
            point.z = _owner->GetMapHeight(point.x, point.y, z) + _owner->GetHoverOffset();

        init.Path().push_back(point);
    }

    if (_owner->IsFlying())
    {
        init.SetFly();
        init.SetCyclic();
        init.SetAnimation(AnimationTier::Hover);
        init.SetUncompressed();
    }
    else
    {
        init.SetWalk(true);
        init.SetCyclic();
    }

    init.SetSmooth();
    if (velocity > 0.f)
        init.SetVelocity(velocity);

    Mutate(new GenericMovementGenerator(std::move(init), CYCLIC_SPLINE_MOTION_TYPE, 0), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveCyclicPath(Position const* pathPoints, size_t pathSize, bool walk /*= false*/, bool fly /*= false*/, float velocity /*= 0.0f*/)
{
    Movement::MoveSplineInit init(_owner);
    Movement::PointsArray path;
    path.reserve(pathSize);
    std::transform(pathPoints, pathPoints + pathSize, std::back_inserter(path), [](Position const& point)
    {
        return G3D::Vector3(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());
    });

    if (fly)
    {
        init.SetFly();
        init.SetUncompressed();
    }

    if (velocity > 0.0f)
        init.SetVelocity(velocity);

    init.MovebyPath(path);
    init.SetSmooth();
    init.SetWalk(walk);
    init.SetCyclic();
    Mutate(new GenericMovementGenerator(std::move(init), CYCLIC_SPLINE_MOTION_TYPE, 0), MOTION_SLOT_IDLE);
}

void MotionMaster::MoveCyclicPath(uint32 pathId)
{
    if (WaypointPath const* splinePath = sWaypointMgr->GetPath(pathId))
        Mutate(new CyclicMovementGenerator<Creature>(splinePath), MOTION_SLOT_IDLE);
}

void MotionMaster::MoveSmoothPath(uint32 pointId, Position const* pathPoints, size_t pathSize, bool walk /*= false*/, bool fly /*= false*/, float velocity /*= 0.0f*/)
{
    Movement::MoveSplineInit init(_owner);
    Movement::PointsArray path;
    path.reserve(pathSize);
    std::transform(pathPoints, pathPoints + pathSize, std::back_inserter(path), [](Position const& point)
    {
        return G3D::Vector3(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());
    });

    if (fly)
    {
        init.SetFly();
        init.SetSmooth();
        init.SetUncompressed();
    }
    else
    {
        if (pathSize > 1)
        {
            G3D::Vector3 middle = (path[0] + path[pathSize]) / 2.f;
            for (uint32 i = 1; i < pathSize; ++i)
            {
                G3D::Vector3 delta = middle - path[i];
                if (delta.x > 400 || delta.y > 400 || delta.z > 400)
                {
                    init.SetUncompressed();
                    break;
                }
            }
        }
    }

    if (velocity > 0.0f)
        init.SetVelocity(velocity);

    init.MovebyPath(path);
    init.SetWalk(walk);

    // This code is not correct
    // GenericMovementGenerator does not affect UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE
    // need to call PointMovementGenerator with various pointIds
    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, pointId), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, uint16 dbChainId, bool walk)
{
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '%s', tried to walk along DB spline chain. Ignoring.", _owner->GetGUID().ToString().c_str());
        return;
    }
    std::vector<SplineChainLink> const* chain = sScriptSystemMgr->GetSplineChain(owner, dbChainId);
    if (!chain)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '%s', tried to walk along non-existing spline chain with DB Id: %u.", _owner->GetGUID().ToString().c_str(), dbChainId);
        return;
    }
    MoveAlongSplineChain(pointId, *chain, walk);
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, std::vector<SplineChainLink> const& chain, bool walk)
{
    Mutate(new SplineChainMovementGenerator(pointId, chain, walk), MOTION_SLOT_ACTIVE);
}

void MotionMaster::ResumeSplineChain(SplineChainResumeInfo const& info)
{
    if (info.Empty())
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::ResumeSplineChain: '%s', tried to resume a spline chain from empty info.", _owner->GetGUID().ToString().c_str());
        return;
    }
    Mutate(new SplineChainMovementGenerator(info), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveFall(uint32 id /*=0*/)
{
    // use larger distance for vmap height search than in most other cases
    float tz = _owner->GetMapHeight(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFall: '%s', unable to retrieve a proper height at map Id: %u (X: %f, Y: %f, Z: %f)",
            _owner->GetGUID().ToString().c_str(), _owner->GetMap()->GetId(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (std::fabs(_owner->GetPositionZ() - tz) < 0.1f)
        return;

    // rooted units don't move (also setting falling+root flag causes client freezes)
    if (_owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        return;

    _owner->AddUnitMovementFlag(MOVEMENTFLAG_FALLING);
    _owner->m_movementInfo.SetFallTime(0);

    if (_owner->GetTypeId() == TYPEID_PLAYER)
        _owner->SetFall(true);

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), tz + _owner->GetHoverOffset(), false);
    init.SetFall();
    Mutate(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (Creature* creature = _owner->ToCreature())
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '%s', seeks assistance (X: %f, Y: %f, Z: %f)", creature->GetGUID().ToString().c_str(), x, y, z);
        creature->AttackStop();
        creature->CastStop();
        creature->ResetSpellFocusInfo();
        creature->SetReactState(REACT_PASSIVE);
        Mutate(new AssistanceMovementGenerator(x, y, z), MOTION_SLOT_ACTIVE);
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '%s', attempted to seek assistance.", _owner->GetGUID().ToString().c_str());
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '%s', is distracted after assistance call (Time: %u)", _owner->GetGUID().ToString().c_str(), time);
        Mutate(new AssistanceDistractMovementGenerator(time), MOTION_SLOT_ACTIVE);
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '%s', attempted to call distract assistance.", _owner->GetGUID().ToString().c_str());
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', taxi to path Id: %u (node %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);
            FlightPathMovementGenerator* movement = new FlightPathMovementGenerator(pathnode);
            movement->LoadPath(_owner->ToPlayer());
            Mutate(movement, MOTION_SLOT_CONTROLLED);
        }
        else
            TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', attempted taxi to non-existing path Id: %u (node: %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', attempted taxi to path Id: %u (node: %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);
}

void MotionMaster::MoveDistract(uint32 timer)
{
    if (_slot[MOTION_SLOT_CONTROLLED])
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveDistract: '%s', distracted (timer: %u)", _owner->GetGUID().ToString().c_str(), timer);
    else
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveDistract: '%s', distracted (timer: %u)", _owner->GetGUID().ToString().c_str(), timer);

    Mutate(new DistractMovementGenerator(timer), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MovePath(uint32 pathId, bool repeatable)
{
    if (!pathId)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '%s', starts moving over path Id: %u (repeatable: %s)", _owner->GetGUID().ToString().c_str(), pathId, repeatable ? "YES" : "NO");
    Mutate(new WaypointMovementGenerator<Creature>(pathId, repeatable), MOTION_SLOT_IDLE);
}

void MotionMaster::MovePath(WaypointPath& path, bool repeatable)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '%s', starts moving over path Id: %u (repeatable: %s)", _owner->GetGUID().ToString().c_str(), path.Id, repeatable ? "YES" : "NO");
    Mutate(new WaypointMovementGenerator<Creature>(path, repeatable), MOTION_SLOT_IDLE);
}

void MotionMaster::MoveRotate(uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRotate: '%s', starts rotate (time: %u, direction: %u)", _owner->GetGUID().ToString().c_str(), time, direction);
    Mutate(new RotateMovementGenerator(time, direction), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveFormation(Unit* leader, float range, float angle, int32 point1, int32 point2)
{
    if (_owner->GetTypeId() == TYPEID_UNIT && leader)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFormation: '%s', started to move in a formation with leader %s", _owner->GetGUID().ToString().c_str(), leader->GetGUID().ToString().c_str());
        Mutate(new FormationMovementGenerator(leader, range, angle, point1, point2), MOTION_SLOT_IDLE);
    }
}

void MotionMaster::LaunchMoveSpline(Movement::MoveSplineInit&& init, uint32 id/*= 0*/, MovementSlot slot/*= MOTION_SLOT_ACTIVE*/, MovementGeneratorType type/*= EFFECT_MOTION_TYPE*/)
{
    if (IsInvalidMovementGeneratorType(type))
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '%s', tried to launch a spline with an invalid MovementGeneratorType: %u (Id: %u, Slot: %u)", _owner->GetGUID().ToString().c_str(), type, id, slot);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '%s', initiates spline Id: %u (Type: %u, Slot: %u)", _owner->GetGUID().ToString().c_str(), id, type, slot);
    Mutate(new GenericMovementGenerator(std::move(init), type, id), slot);
}

/******************** Private methods ********************/

void MotionMaster::pop()
{
    if (empty())
        return;

    _slot[_top] = nullptr;
    while (!empty() && !top())
        --_top;
}

bool MotionMaster::NeedInitTop() const
{
    if (empty())
        return false;
    return _initialize[_top];
}

void MotionMaster::InitTop()
{
    top()->Initialize(_owner);
    _initialize[_top] = false;
}

void MotionMaster::Mutate(MovementGenerator *m, MovementSlot slot)
{
    if (MovementGenerator* curr = _slot[slot])
    {
        _slot[slot] = nullptr; // in case a new one is generated in this slot during directdelete
        if (_top == slot && (_cleanFlag & MMCF_UPDATE))
            DelayedDelete(curr);
        else
            DirectDelete(curr);
    }
    else if (_top < slot)
    {
        _top = slot;
    }

    _slot[slot] = m;
    if (_top > slot)
        _initialize[slot] = true;
    else
    {
        _initialize[slot] = false;
        m->Initialize(_owner);
    }
}

void MotionMaster::DirectClean(bool reset)
{
    while (size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        if (curr)
            DirectDelete(curr);
    }

    if (empty())
        return;

    if (NeedInitTop())
        InitTop();
    else if (reset)
        top()->Reset(_owner);
}

void MotionMaster::DelayedClean()
{
    while (size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        if (curr)
            DelayedDelete(curr);
    }
}

void MotionMaster::DirectClean(MovementSlot slot)
{
    if (MovementGenerator* motion = GetMotionSlot(slot))
    {
        _slot[slot] = nullptr;
        DirectDelete(motion);
    }

    while (!empty() && !top())
        --_top;

    if (empty())
        Initialize();
    else if (NeedInitTop())
        InitTop();
}

void MotionMaster::DelayedClean(MovementSlot slot)
{
    if (MovementGenerator* motion = GetMotionSlot(slot))
    {
        _slot[slot] = nullptr;
        DelayedDelete(motion);
    }

    while (!empty() && !top())
        --_top;
}

void MotionMaster::DirectExpire(bool reset)
{
    if (size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        DirectDelete(curr);
    }

    while (!empty() && !top())
        --_top;

    if (empty())
        Initialize();
    else if (NeedInitTop())
        InitTop();
    else if (reset)
        top()->Reset(_owner);
}

void MotionMaster::DelayedExpire()
{
    if (size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        DelayedDelete(curr);
    }

    while (!empty() && !top())
        --_top;
}

void MotionMaster::DirectDelete(MovementGenerator* curr)
{
    if (IsStatic(curr))
        return;


    curr->Finalize(_owner);
    curr->NotifyAIOnFinalize(_owner);
    delete curr;
}

void MotionMaster::DelayedDelete(MovementGenerator* curr)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::DelayedDelete: '%s', delayed deleting movement generator (type: %u)", _owner->GetGUID().ToString().c_str(), curr->GetMovementGeneratorType());
    if (IsStatic(curr))
        return;

    _expireList.push_back(curr);
}

void MotionMaster::ClearExpireList()
{
    for (auto itr : _expireList)
        DirectDelete(itr);

    _expireList.clear();

    if (empty())
        Initialize();
    else if (NeedInitTop())
        InitTop();
    else if (_cleanFlag & MMCF_RESET)
        top()->Reset(_owner);

    _cleanFlag &= ~MMCF_RESET;
}
