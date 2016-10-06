/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "CreatureAISelector.h"
#include "Creature.h"
#include "ScriptSystem.h"
#include "ConfusedMovementGenerator.h"
#include "FleeingMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "PointMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "WaypointMovementGenerator.h"
#include "RandomMovementGenerator.h"
#include "SplineChainMovementGenerator.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"

inline bool IsStatic(MovementGenerator *mv) { return (mv == &si_idleMovement); }

MotionMaster::~MotionMaster()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator *curr = top();
        Pop();
        if (curr && !IsStatic(curr))
            delete curr;    // Skip finalizing on delete, it might launch new movement
    }
}

void MotionMaster::Initialize()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator *curr = top();
        Pop();
        if (curr)
            DirectDelete(curr);
    }

    InitDefault();
}

// set new default movement generator
void MotionMaster::InitDefault()
{
    if (m_owner->GetTypeId() == TYPEID_UNIT)
    {
        MovementGenerator* movement = FactorySelector::selectMovementGenerator(m_owner->ToCreature());
        Mutate(movement == NULL ? &si_idleMovement : movement, MOTION_SLOT_IDLE);
    }
    else
    {
        Mutate(&si_idleMovement, MOTION_SLOT_IDLE);
    }
}

void MotionMaster::UpdateMotion(uint32 diff)
{
    if (!m_owner)
        return;

    if (m_owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED)) // what about UNIT_STATE_DISTRACTED? Why is this not included?
        return;

    ASSERT(!empty());

    m_cleanFlag |= MMCF_UPDATE;
    if (!top()->Update(m_owner, diff))
    {
        m_cleanFlag &= ~MMCF_UPDATE;
        MovementExpired();
    }
    else
        m_cleanFlag &= ~MMCF_UPDATE;

    if (m_expireList)
    {
        for (size_t i = 0; i < m_expireList->size(); ++i)
        {
            MovementGenerator* mg = (*m_expireList)[i];
            DirectDelete(mg);
        }

        delete m_expireList;
        m_expireList = nullptr;

        if (empty())
            Initialize();
        else if (NeedInitTop())
            InitTop();
        else if (m_cleanFlag & MMCF_RESET)
            top()->Reset(m_owner);

        m_cleanFlag &= ~MMCF_RESET;
    }

    // probably not the best place to pu this but im not really sure where else to put it.
    m_owner->UpdateUnderwaterState(m_owner->GetMap(), m_owner->GetPositionX(), m_owner->GetPositionY(), m_owner->GetPositionZ());
}

void MotionMaster::Clear(bool reset /*= true*/)
{
    if (m_cleanFlag & MMCF_UPDATE)
    {
        if (reset)
            m_cleanFlag |= MMCF_RESET;
        else
            m_cleanFlag &= ~MMCF_RESET;
        DelayedClean();
    }
    else
        DirectClean(reset);
}

void MotionMaster::MovementExpired(bool reset /*= true*/)
{
    if (m_cleanFlag & MMCF_UPDATE)
    {
        if (reset)
            m_cleanFlag |= MMCF_RESET;
        else
            m_cleanFlag &= ~MMCF_RESET;
        DelayedExpire();
    }
    else
        DirectExpire(reset);
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
    if (empty())
        return IDLE_MOTION_TYPE;

    return top()->GetMovementGeneratorType();
}

MovementGeneratorType MotionMaster::GetMotionSlotType(int slot) const
{
    if (!m_slot[slot])
        return NULL_MOTION_TYPE;
    else
        return m_slot[slot]->GetMovementGeneratorType();
}

MovementGenerator* MotionMaster::GetMotionSlot(int slot) const
{
    ASSERT(slot >= 0);
    return m_slot[slot];
}

void MotionMaster::propagateSpeedChange()
{
    for (int i = 0; i <= m_top; ++i)
    {
        if (m_slot[i])
            m_slot[i]->unitSpeedChanged();
    }
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    if (m_owner->movespline->Finalized())
        return false;

    G3D::Vector3 const& dest = m_owner->movespline->FinalDestination();
    x = dest.x;
    y = dest.y;
    z = dest.z;
    return true;
}

void MotionMaster::MoveIdle()
{
    //! Should be preceded by MovementExpired or Clear if there's an overlying movementgenerator active
    if (empty() || !IsStatic(top()))
        Mutate(&si_idleMovement, MOTION_SLOT_IDLE);
}

void MotionMaster::MoveTargetedHome()
{
    Clear(false);

    if (m_owner->GetTypeId() == TYPEID_UNIT && !m_owner->ToCreature()->GetCharmerOrOwnerGUID())
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) targeted home.", m_owner->GetEntry(), m_owner->GetGUID().GetCounter());
        Mutate(new HomeMovementGenerator<Creature>(), MOTION_SLOT_ACTIVE);
    }
    else if (m_owner->GetTypeId() == TYPEID_UNIT && m_owner->ToCreature()->GetCharmerOrOwnerGUID())
    {
        TC_LOG_DEBUG("misc", "Pet or controlled creature (Entry: %u GUID: %u) is targeting home.", m_owner->GetEntry(), m_owner->GetGUID().GetCounter());
        Unit* target = m_owner->ToCreature()->GetCharmerOrOwner();
        if (target)
        {
            TC_LOG_DEBUG("misc", "Following %s (GUID: %u).", target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature", target->GetTypeId() == TYPEID_PLAYER ? target->GetGUID().GetCounter() : ((Creature*)target)->GetSpawnId());
            Mutate(new FollowMovementGenerator<Creature>(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE), MOTION_SLOT_ACTIVE);
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "Player (GUID: %u) attempted to move towards target home.", m_owner->GetGUID().GetCounter());
    }
}

void MotionMaster::MoveRandom(float spawndist)
{
    if (m_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("misc", "Creature (GUID: %u) started random movement.", m_owner->GetGUID().GetCounter());
        Mutate(new RandomMovementGenerator<Creature>(spawndist), MOTION_SLOT_IDLE);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle, MovementSlot slot)
{
    // ignore movement request if target not exist
    if (!target || target == m_owner)
        return;

    //m_owner->AddUnitState(UNIT_STATE_FOLLOW);
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) follows %s (GUID: %u).", m_owner->GetGUID().GetCounter(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUID().GetCounter() : target->ToCreature()->GetSpawnId());
        Mutate(new FollowMovementGenerator<Player>(target, dist, angle), slot);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) follows %s (GUID: %u).",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUID().GetCounter() : target->ToCreature()->GetSpawnId());
        Mutate(new FollowMovementGenerator<Creature>(target, dist, angle), slot);
    }
}

void MotionMaster::MoveChase(Unit* target, float dist, float angle)
{
    // ignore movement request if target not exist
    if (!target || target == m_owner)
        return;

    //m_owner->ClearUnitState(UNIT_STATE_FOLLOW);
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) chase to %s (GUID: %u)",
            m_owner->GetGUID().GetCounter(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUID().GetCounter() : target->ToCreature()->GetSpawnId());
        Mutate(new ChaseMovementGenerator<Player>(target, dist, angle), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) chase to %s (GUID: %u)",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUID().GetCounter() : target->ToCreature()->GetSpawnId());
        Mutate(new ChaseMovementGenerator<Creature>(target, dist, angle), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveConfused()
{
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) move confused", m_owner->GetGUID().GetCounter());
        Mutate(new ConfusedMovementGenerator<Player>(), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) move confused",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter());
        Mutate(new ConfusedMovementGenerator<Creature>(), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) flees from %s (GUID: %u).", m_owner->GetGUID().GetCounter(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUID().GetCounter() : enemy->ToCreature()->GetSpawnId());
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) flees from %s (GUID: %u)%s.",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUID().GetCounter() : enemy->ToCreature()->GetSpawnId(),
            time ? " for a limited time" : "");
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetGUID(), time), MOTION_SLOT_CONTROLLED);
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, bool generatePath)
{
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) targeted point (Id: %u X: %f Y: %f Z: %f).", m_owner->GetGUID().GetCounter(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) targeted point (ID: %u X: %f Y: %f Z: %f).",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveCloserAndStop(uint32 id, Unit* target, float distance)
{
    float distanceToTravel = m_owner->GetExactDist2d(target) - distance;
    if (distanceToTravel > 0.0f)
    {
        float angle = m_owner->GetAngle(target);
        float destx = m_owner->GetPositionX() + distanceToTravel * std::cos(angle);
        float desty = m_owner->GetPositionY() + distanceToTravel * std::sin(angle);
        MovePoint(id, destx, desty, target->GetPositionZ());
    }
    else
    {
        // we are already close enough. We just need to turn toward the target without changing position.
        Movement::MoveSplineInit init(m_owner);
        init.MoveTo(m_owner->GetPositionX(), m_owner->GetPositionY(), m_owner->GetPositionZMinusOffset());
        init.SetFacing(target);
        init.Launch();
        Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    TC_LOG_DEBUG("misc", "Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f).", m_owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(m_owner);
    init.MoveTo(x, y, z);
    init.SetAnimation(Movement::ToGround);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    TC_LOG_DEBUG("misc", "Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f).", m_owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(m_owner);
    init.MoveTo(x, y, z);
    init.SetAnimation(Movement::ToFly);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed /*= SPEED_CHARGE*/, uint32 id /*= EVENT_CHARGE*/, bool generatePath /*= false*/)
{
    if (m_slot[MOTION_SLOT_CONTROLLED] && m_slot[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;

    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) charged point (X: %f Y: %f Z: %f).", m_owner->GetGUID().GetCounter(), x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath, speed), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) charged point (X: %f Y: %f Z: %f).",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath, speed), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveCharge(PathGenerator const& path, float speed /*= SPEED_CHARGE*/)
{
    G3D::Vector3 dest = path.GetActualEndPosition();

    MoveCharge(dest.x, dest.y, dest.z, speed, EVENT_CHARGE_PREPATH);

    // Charge movement is not started when using EVENT_CHARGE_PREPATH
    Movement::MoveSplineInit init(m_owner);
    init.MovebyPath(path.GetPath());
    init.SetVelocity(speed);
    init.Launch();
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    if (speedXY <= 0.1f)
        return;

    float x, y, z;
    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    m_owner->GetNearPoint(m_owner, x, y, z, m_owner->GetObjectSize(), dist, m_owner->GetAngle(srcX, srcY) + float(M_PI));

    Movement::MoveSplineInit init(m_owner);
    init.MoveTo(x, y, z);
    init.SetParabolic(max_height, 0);
    init.SetOrientationFixed(true);
    init.SetVelocity(speedXY);
    init.Launch();
    Mutate(new EffectMovementGenerator(0), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveJumpTo(float angle, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z;

    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    m_owner->GetClosePoint(x, y, z, m_owner->GetObjectSize(), dist, angle);
    MoveJump(x, y, z, 0.0f, speedXY, speedZ);
}

void MotionMaster::MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id, bool hasOrientation /* = false*/)
{
    TC_LOG_DEBUG("misc", "Unit (GUID: %u) jumps to point (X: %f Y: %f Z: %f).", m_owner->GetGUID().GetCounter(), x, y, z);
    if (speedXY <= 0.1f)
        return;

    float moveTimeHalf = speedZ / Movement::gravity;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    Movement::MoveSplineInit init(m_owner);
    init.MoveTo(x, y, z, false);
    init.SetParabolic(max_height, 0);
    init.SetVelocity(speedXY);
    if (hasOrientation)
        init.SetFacing(o);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount)
{
    float step = 2 * float(M_PI) / stepCount * (clockwise ? -1.0f : 1.0f);
    Position const& pos = { x, y, z, 0.0f };
    float angle = pos.GetAngle(m_owner->GetPositionX(), m_owner->GetPositionY());

    Movement::MoveSplineInit init(m_owner);

    for (uint8 i = 0; i < stepCount; angle += step, ++i)
    {
        G3D::Vector3 point;
        point.x = x + radius * cosf(angle);
        point.y = y + radius * sinf(angle);

        if (m_owner->IsFlying())
            point.z = z;
        else
            point.z = m_owner->GetMap()->GetHeight(m_owner->GetPhaseMask(), point.x, point.y, z);

        init.Path().push_back(point);
    }

    if (m_owner->IsFlying())
    {
        init.SetFly();
        init.SetCyclic();
        init.SetAnimation(Movement::ToFly);
    }
    else
    {
        init.SetWalk(true);
        init.SetCyclic();
    }

    init.Launch();
}

void MotionMaster::MoveSmoothPath(uint32 pointId, G3D::Vector3 const* pathPoints, size_t pathSize, bool walk)
{
    Movement::PointsArray path(pathPoints, pathPoints + pathSize);
    MoveSmoothPath(pointId, path, walk);
}

void MotionMaster::MoveSmoothPath(uint32 pointId, Movement::PointsArray const& path, bool walk)
{
    Movement::MoveSplineInit init(m_owner);
    init.MovebyPath(path);
    init.SetSmooth();
    init.SetWalk(walk);
    init.Launch();

    // This code is not correct
    // EffectMovementGenerator does not affect UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE
    // need to call PointMovementGenerator with various pointIds
    Mutate(new EffectMovementGenerator(pointId), MOTION_SLOT_ACTIVE);
    //Position pos(pathPoints[pathSize - 1].x, pathPoints[pathSize - 1].y, pathPoints[pathSize - 1].z);
    //MovePoint(EVENT_CHARGE_PREPATH, pos, false);
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, uint16 dbChainId, bool walk)
{
    Creature* owner = m_owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("misc", "MotionMaster::MoveAlongSplineChain: non-creature %s tried to walk along DB spline chain. Ignoring.", m_owner->GetGUID().ToString().c_str());
        return;
    }
    SplineChain const* chain = sScriptSystemMgr->GetSplineChain(owner, dbChainId);
    if (!chain)
    {
        TC_LOG_ERROR("misc", "MotionMaster::MoveAlongSplineChain: creature with entry %u tried to walk along non-existing spline chain with DB id %u.", owner->GetEntry(), dbChainId);
        return;
    }
    MoveAlongSplineChain(pointId, *chain, walk);
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, SplineChain const& chain, bool walk)
{
    Mutate(new SplineChainMovementGenerator(pointId, chain, walk), MOTION_SLOT_ACTIVE);
}

void MotionMaster::ResumeSplineChain(SplineChainResumeInfo const& info)
{
    if (info.Empty())
    {
        TC_LOG_ERROR("misc", "MotionMaster::ResumeSplineChain: unit with entry %u tried to resume a spline chain from empty info.", m_owner->GetEntry());
        return;
    }
    Mutate(new SplineChainMovementGenerator(info), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveFall(uint32 id /*=0*/)
{
    // use larger distance for vmap height search than in most other cases
    float tz = m_owner->GetMap()->GetHeight(m_owner->GetPhaseMask(), m_owner->GetPositionX(), m_owner->GetPositionY(), m_owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        TC_LOG_DEBUG("misc", "MotionMaster::MoveFall: unable to retrieve a proper height at map %u (x: %f, y: %f, z: %f).",
            m_owner->GetMap()->GetId(), m_owner->GetPositionX(), m_owner->GetPositionY(), m_owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (std::fabs(m_owner->GetPositionZ() - tz) < 0.1f)
        return;

    m_owner->AddUnitMovementFlag(MOVEMENTFLAG_FALLING);
    m_owner->m_movementInfo.SetFallTime(0);

    // don't run spline movement for players
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    Movement::MoveSplineInit init(m_owner);
    init.MoveTo(m_owner->GetPositionX(), m_owner->GetPositionY(), tz, false);
    init.SetFall();
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_ERROR("misc", "Player (GUID: %u) attempted to seek assistance.", m_owner->GetGUID().GetCounter());
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) seek assistance (X: %f Y: %f Z: %f)",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), x, y, z);
        m_owner->AttackStop();
        m_owner->CastStop();
        m_owner->ToCreature()->SetReactState(REACT_PASSIVE);
        Mutate(new AssistanceMovementGenerator(x, y, z), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_ERROR("misc", "Player (GUID: %u) attempted to call distract assistance.", m_owner->GetGUID().GetCounter());
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) is distracted after assistance call (Time: %u).",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), time);
        Mutate(new AssistanceDistractMovementGenerator(time), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            TC_LOG_DEBUG("misc", "%s taxi to (Path %u node %u).", m_owner->GetName().c_str(), path, pathnode);
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator(pathnode);
            mgen->LoadPath(m_owner->ToPlayer());
            Mutate(mgen, MOTION_SLOT_CONTROLLED);
        }
        else
        {
            TC_LOG_ERROR("misc", "%s attempted taxi to (non-existing Path %u node %u).",
            m_owner->GetName().c_str(), path, pathnode);
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "Creature (Entry: %u GUID: %u) attempted taxi to (Path %u node %u).",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), path, pathnode);
    }
}

void MotionMaster::MoveDistract(uint32 timer)
{
    if (m_slot[MOTION_SLOT_CONTROLLED])
        return;

    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (GUID: %u) distracted (timer: %u).", m_owner->GetGUID().GetCounter(), timer);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u GUID: %u) distracted (timer: %u)",
            m_owner->GetEntry(), m_owner->GetGUID().GetCounter(), timer);
    }

    DistractMovementGenerator* mgen = new DistractMovementGenerator(timer);
    Mutate(mgen, MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MovePath(uint32 path_id, bool repeatable)
{
    if (!path_id)
        return;

    Mutate(new WaypointMovementGenerator<Creature>(path_id, repeatable), MOTION_SLOT_IDLE);

    TC_LOG_DEBUG("misc", "%s (GUID: %u) starts moving over path(Id:%u, repeatable: %s).",
        m_owner->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature",
        m_owner->GetGUID().GetCounter(), path_id, repeatable ? "YES" : "NO");
}

void MotionMaster::MoveRotate(uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    Mutate(new RotateMovementGenerator(time, direction), MOTION_SLOT_ACTIVE);
}

/******************** Private methods ********************/

bool MotionMaster::NeedInitTop() const
{
    if (empty())
        return false;
    return m_initialize[m_top];
}

void MotionMaster::InitTop()
{
    top()->Initialize(m_owner);
    m_initialize[m_top] = false;
}

void MotionMaster::Pop()
{
    if (empty())
        return;

    m_slot[m_top] = NULL;
    while (!empty() && !top())
        --m_top;
}

void MotionMaster::Mutate(MovementGenerator *m, MovementSlot slot)
{
    if (MovementGenerator *curr = m_slot[slot])
    {
        m_slot[slot] = NULL; // in case a new one is generated in this slot during directdelete
        if (m_top == slot && (m_cleanFlag & MMCF_UPDATE))
            DelayedDelete(curr);
        else
            DirectDelete(curr);
    }
    else if (m_top < slot)
    {
        m_top = slot;
    }

    m_slot[slot] = m;
    if (m_top > slot)
        m_initialize[slot] = true;
    else
    {
        m_initialize[slot] = false;
        m->Initialize(m_owner);
    }
}

void MotionMaster::DirectClean(bool reset)
{
    while (size() > 1)
    {
        MovementGenerator *curr = top();
        Pop();
        if (curr) DirectDelete(curr);
    }

    if (empty())
        return;

    if (NeedInitTop())
        InitTop();
    else if (reset)
        top()->Reset(m_owner);
}

void MotionMaster::DelayedClean()
{
    while (size() > 1)
    {
        MovementGenerator *curr = top();
        Pop();
        if (curr)
            DelayedDelete(curr);
    }
}

void MotionMaster::DirectExpire(bool reset)
{
    if (size() > 1)
    {
        MovementGenerator *curr = top();
        Pop();
        DirectDelete(curr);
    }

    while (!empty() && !top())
        --m_top;

    if (empty())
        Initialize();
    else if (NeedInitTop())
        InitTop();
    else if (reset)
        top()->Reset(m_owner);
}

void MotionMaster::DelayedExpire()
{
    if (size() > 1)
    {
        MovementGenerator *curr = top();
        Pop();
        DelayedDelete(curr);
    }

    while (!empty() && !top())
        --m_top;
}

void MotionMaster::DirectDelete(MovementGenerator* curr)
{
    if (IsStatic(curr))
        return;
    curr->Finalize(m_owner);
    delete curr;
}

void MotionMaster::DelayedDelete(MovementGenerator* curr)
{
    TC_LOG_FATAL("misc", "Unit (Entry %u) is trying to delete its updating Movement Generator (Type %u)!", m_owner->GetEntry(), curr->GetMovementGeneratorType());
    if (IsStatic(curr))
        return;
    if (!m_expireList)
        m_expireList = new ExpireList();
    m_expireList->push_back(curr);
}
