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
#include "CreatureAISelector.h"
#include "Creature.h"
#include "ScriptSystem.h"
#include "Log.h"
#include "Map.h"
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

inline bool IsStatic(MovementGenerator* movement)
{
    return (movement == &si_idleMovement);
}

MotionMaster::~MotionMaster()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator *curr = top();
        pop();
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
        pop();
        if (curr)
            DirectDelete(curr);
    }

    InitDefault();
}

// set new default movement generator
void MotionMaster::InitDefault()
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        MovementGenerator* movement = FactorySelector::selectMovementGenerator(_owner->ToCreature());
        Mutate(movement == NULL ? &si_idleMovement : movement, MOTION_SLOT_IDLE);
    }
    else
    {
        Mutate(&si_idleMovement, MOTION_SLOT_IDLE);
    }
}

void MotionMaster::UpdateMotion(uint32 diff)
{
    if (!_owner)
        return;

    if (_owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED)) // what about UNIT_STATE_DISTRACTED? Why is this not included?
        return;

    ASSERT(!empty());

    _cleanFlag |= MMCF_UPDATE;
    bool isMoveGenUpdateSuccess = top()->Update(_owner, diff);
    _cleanFlag &= ~MMCF_UPDATE;

    if (!isMoveGenUpdateSuccess)
        MovementExpired();

    if (_expireList)
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

void MotionMaster::ClearExpireList()
{
    for (size_t i = 0; i < _expireList->size(); ++i)
    {
        MovementGenerator* mg = (*_expireList)[i];
        DirectDelete(mg);
    }

    delete _expireList;
    _expireList = nullptr;

    if (empty())
        Initialize();
    else if (NeedInitTop())
        InitTop();
    else if (_cleanFlag & MMCF_RESET)
        top()->Reset(_owner);

    _cleanFlag &= ~MMCF_RESET;
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

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
    if (empty())
        return IDLE_MOTION_TYPE;

    return top()->GetMovementGeneratorType();
}

MovementGeneratorType MotionMaster::GetMotionSlotType(int slot) const
{
    if (!_slot[slot])
        return NULL_MOTION_TYPE;
    else
        return _slot[slot]->GetMovementGeneratorType();
}

MovementGenerator* MotionMaster::GetMotionSlot(int slot) const
{
    ASSERT(slot >= 0);
    return _slot[slot];
}

void MotionMaster::propagateSpeedChange()
{
    for (int i = 0; i <= _top; ++i)
    {
        if (_slot[i])
            _slot[i]->unitSpeedChanged();
    }
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
        Mutate(&si_idleMovement, MOTION_SLOT_IDLE);
}

void MotionMaster::MoveTargetedHome()
{
    Clear(false);

    if (_owner->GetTypeId() == TYPEID_UNIT && !_owner->ToCreature()->GetCharmerOrOwnerGUID())
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) targeted home.", _owner->GetEntry(), _owner->GetGUID().ToString().c_str());
        Mutate(new HomeMovementGenerator<Creature>(), MOTION_SLOT_ACTIVE);
    }
    else if (_owner->GetTypeId() == TYPEID_UNIT && !_owner->ToCreature()->GetCharmerOrOwnerGUID().IsEmpty())
    {
        TC_LOG_DEBUG("misc", "Pet or controlled creature (Entry: %u %s) is targeting home", _owner->GetEntry(), _owner->GetGUID().ToString().c_str());
        Unit* target = _owner->ToCreature()->GetCharmerOrOwner();
        if (target)
        {
            TC_LOG_DEBUG("misc", "Following %s", target->GetGUID().ToString().c_str());
            Mutate(new FollowMovementGenerator<Creature>(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE), MOTION_SLOT_ACTIVE);
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "Player (%s) attempted to move towards target home.", _owner->GetGUID().ToString().c_str());
    }
}

void MotionMaster::MoveRandom(float spawndist)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("misc", "Creature (%s) started random movement.", _owner->GetGUID().ToString().c_str());
        Mutate(new RandomMovementGenerator<Creature>(spawndist), MOTION_SLOT_IDLE);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle, MovementSlot slot)
{
    // ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    //_owner->AddUnitState(UNIT_STATE_FOLLOW);
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) follows (%s)", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
        Mutate(new FollowMovementGenerator<Player>(target, dist, angle), slot);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) follows (%s)", _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
        Mutate(new FollowMovementGenerator<Creature>(target, dist, angle), slot);
    }
}

void MotionMaster::MoveChase(Unit* target, float dist, float angle)
{
    // ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    //_owner->ClearUnitState(UNIT_STATE_FOLLOW);
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) chase (%s)",
            _owner->GetGUID().ToString().c_str(),
            target->GetGUID().ToString().c_str());
        Mutate(new ChaseMovementGenerator<Player>(target, dist, angle), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) chase %s",
            _owner->GetEntry(),
            _owner->GetGUID().ToString().c_str(),
            target->GetGUID().ToString().c_str());
        Mutate(new ChaseMovementGenerator<Creature>(target, dist, angle), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveConfused()
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) move confused", _owner->GetGUID().ToString().c_str());
        Mutate(new ConfusedMovementGenerator<Player>(), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) move confused",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str());
        Mutate(new ConfusedMovementGenerator<Creature>(), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) flees from (%s).", _owner->GetGUID().ToString().c_str(),
            enemy->GetGUID().ToString().c_str());
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) flees from (%s)%s.",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(),
            enemy->GetGUID().ToString().c_str(),
            time ? " for a limited time" : "");
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetGUID(), time), MOTION_SLOT_CONTROLLED);
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, bool generatePath)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) targeted point (Id: %u X: %f Y: %f Z: %f).", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath), MOTION_SLOT_ACTIVE);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) targeted point (ID: %u X: %f Y: %f Z: %f).",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath), MOTION_SLOT_ACTIVE);
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
        init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZMinusOffset());
        init.SetFacing(target);
        init.Launch();
        Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    TC_LOG_DEBUG("misc", "Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f).", _owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(x, y, z);
    init.SetAnimation(Movement::ToGround);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    TC_LOG_DEBUG("misc", "Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f).", _owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(x, y, z);
    init.SetAnimation(Movement::ToFly);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed /*= SPEED_CHARGE*/, uint32 id /*= EVENT_CHARGE*/, bool generatePath /*= false*/,
    Unit const* target /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    if (_slot[MOTION_SLOT_CONTROLLED] && _slot[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) charged point (X: %f Y: %f Z: %f).", _owner->GetGUID().ToString().c_str(), x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, generatePath, speed, target, spellEffectExtraData), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) charged point (X: %f Y: %f Z: %f).",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, generatePath, speed, target, spellEffectExtraData), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveCharge(PathGenerator const& path, float speed /*= SPEED_CHARGE*/, Unit const* target /*= nullptr*/,
    Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    G3D::Vector3 dest = path.GetActualEndPosition();

    MoveCharge(dest.x, dest.y, dest.z, speed, EVENT_CHARGE_PREPATH);

    // Charge movement is not started when using EVENT_CHARGE_PREPATH
    Movement::MoveSplineInit init(_owner);
    init.MovebyPath(path.GetPath());
    init.SetVelocity(speed);
    if (target)
        init.SetFacing(target);
    if (spellEffectExtraData)
        init.SetSpellEffectExtraData(*spellEffectExtraData);
    init.Launch();
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    //this function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    if (speedXY < 0.01f)
        return;

    float x, y, z;
    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    _owner->GetNearPoint(_owner, x, y, z, _owner->GetObjectSize(), dist, _owner->GetAngle(srcX, srcY) + float(M_PI));

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(x, y, z);
    init.SetParabolic(max_height, 0);
    init.SetOrientationFixed(true);
    init.SetVelocity(speedXY);
    if (spellEffectExtraData)
        init.SetSpellEffectExtraData(*spellEffectExtraData);

    init.Launch();
    Mutate(new EffectMovementGenerator(0), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveJumpTo(float angle, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z;

    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    _owner->GetClosePoint(x, y, z, _owner->GetObjectSize(), dist, angle);
    MoveJump(x, y, z, 0.0f, speedXY, speedZ);
}

void MotionMaster::MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id /*= EVENT_JUMP*/, bool hasOrientation /* = false*/,
    JumpArrivalCastArgs const* arrivalCast /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    TC_LOG_DEBUG("misc", "Unit (%s) jumps to point (X: %f Y: %f Z: %f).", _owner->GetGUID().ToString().c_str(), x, y, z);
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
    if (spellEffectExtraData)
        init.SetSpellEffectExtraData(*spellEffectExtraData);
    init.Launch();

    uint32 arrivalSpellId = 0;
    ObjectGuid arrivalSpellTargetGuid;
    if (arrivalCast)
    {
        arrivalSpellId = arrivalCast->SpellId;
        arrivalSpellTargetGuid = arrivalCast->Target;
    }

    Mutate(new EffectMovementGenerator(id, arrivalSpellId, arrivalSpellTargetGuid), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount)
{
    float step = 2 * float(M_PI) / stepCount * (clockwise ? -1.0f : 1.0f);
    Position const& pos = { x, y, z, 0.0f };
    float angle = pos.GetAngle(_owner->GetPositionX(), _owner->GetPositionY());

    Movement::MoveSplineInit init(_owner);

    for (uint8 i = 0; i < stepCount; angle += step, ++i)
    {
        G3D::Vector3 point;
        point.x = x + radius * cosf(angle);
        point.y = y + radius * sinf(angle);

        if (_owner->IsFlying())
            point.z = z;
        else
            point.z = _owner->GetMap()->GetHeight(_owner->GetPhaseShift(), point.x, point.y, z);

        init.Path().push_back(point);
    }

    if (_owner->IsFlying())
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

void MotionMaster::MoveSmoothPath(uint32 pointId, Position const* pathPoints, size_t pathSize, bool walk, bool fly)
{
    Movement::MoveSplineInit init(_owner);
    if (fly)
    {
        init.SetFly();
        init.SetUncompressed();
        init.SetSmooth();
    }

    Movement::PointsArray path;
    path.reserve(pathSize);
    std::transform(pathPoints, pathPoints + pathSize, std::back_inserter(path), [](Position const& point)
    {
        return G3D::Vector3(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());
    });
    init.MovebyPath(path);
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
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("misc", "MotionMaster::MoveAlongSplineChain: non-creature %s tried to walk along DB spline chain. Ignoring.", _owner->GetGUID().ToString().c_str());
        return;
    }
    std::vector<SplineChainLink> const* chain = sScriptSystemMgr->GetSplineChain(owner, dbChainId);
    if (!chain)
    {
        TC_LOG_ERROR("misc", "MotionMaster::MoveAlongSplineChain: creature with entry %u tried to walk along non-existing spline chain with DB id %u.", owner->GetEntry(), dbChainId);
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
        TC_LOG_ERROR("misc", "MotionMaster::ResumeSplineChain: unit with entry %u tried to resume a spline chain from empty info.", _owner->GetEntry());
        return;
    }
    Mutate(new SplineChainMovementGenerator(info), MOTION_SLOT_ACTIVE);
}

void MotionMaster::MoveFall(uint32 id /*=0*/)
{
    // use larger distance for vmap height search than in most other cases
    float tz = _owner->GetMap()->GetHeight(_owner->GetPhaseShift(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        TC_LOG_DEBUG("misc", "MotionMaster::MoveFall: unable to retrieve a proper height at map %u (x: %f, y: %f, z: %f).",
            _owner->GetMap()->GetId(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (std::fabs(_owner->GetPositionZ() - tz) < 0.1f)
        return;

    _owner->SetFall(true);

    // don't run spline movement for players
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        _owner->ToPlayer()->SetFallInformation(0, _owner->GetPositionZ());
        return;
    }

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), tz, false);
    init.SetFall();
    init.Launch();
    Mutate(new EffectMovementGenerator(id), MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_ERROR("misc", "Player (GUID: %s) attempted to seek assistance.", _owner->GetGUID().ToString().c_str());
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) seek assistance (X: %f Y: %f Z: %f)",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), x, y, z);
        _owner->AttackStop();
        _owner->CastStop();
        _owner->ToCreature()->SetReactState(REACT_PASSIVE);
        Mutate(new AssistanceMovementGenerator(x, y, z), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_ERROR("misc", "Player (%s) attempedt to call distract after assistance.", _owner->GetGUID().ToString().c_str());
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) is distracted after assistance call (Time: %u).",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), time);
        Mutate(new AssistanceDistractMovementGenerator(time), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            TC_LOG_DEBUG("misc", "%s taxi to (Path %u node %u).", _owner->GetName().c_str(), path, pathnode);
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator();
            mgen->LoadPath(_owner->ToPlayer());
            Mutate(mgen, MOTION_SLOT_CONTROLLED);
        }
        else
        {
            TC_LOG_ERROR("misc", "%s attempted taxi to (non-existing Path %u node %u).",
            _owner->GetName().c_str(), path, pathnode);
        }
    }
    else
    {
        TC_LOG_ERROR("misc", "Creature (Entry: %u %s) attempted taxi to (Path %u node %u).",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), path, pathnode);
    }
}

void MotionMaster::MoveDistract(uint32 timer)
{
    if (_slot[MOTION_SLOT_CONTROLLED])
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("misc", "Player (%s) distracted (timer: %u).", _owner->GetGUID().ToString().c_str(), timer);
    }
    else
    {
        TC_LOG_DEBUG("misc", "Creature (Entry: %u %s) distracted (timer: %u)",
            _owner->GetEntry(), _owner->GetGUID().ToString().c_str(), timer);
    }

    DistractMovementGenerator* mgen = new DistractMovementGenerator(timer);
    Mutate(mgen, MOTION_SLOT_CONTROLLED);
}

void MotionMaster::MovePath(uint32 path_id, bool repeatable)
{
    if (!path_id)
        return;

    Mutate(new WaypointMovementGenerator<Creature>(path_id, repeatable), MOTION_SLOT_IDLE);

    TC_LOG_DEBUG("misc", "%s starts moving over path (Id:%u, repeatable: %s).",
        _owner->GetGUID().ToString().c_str(), path_id, repeatable ? "YES" : "NO");
}

void MotionMaster::MoveRotate(uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    Mutate(new RotateMovementGenerator(time, direction), MOTION_SLOT_ACTIVE);
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
    if (MovementGenerator *curr = _slot[slot])
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
        MovementGenerator *curr = top();
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
        MovementGenerator *curr = top();
        pop();
        if (curr)
            DelayedDelete(curr);
    }
}

void MotionMaster::DirectExpire(bool reset)
{
    if (size() > 1)
    {
        MovementGenerator *curr = top();
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
        MovementGenerator *curr = top();
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
    delete curr;
}

void MotionMaster::DelayedDelete(MovementGenerator* curr)
{
    TC_LOG_FATAL("misc", "Unit (Entry %u) is trying to delete its updating Movement Generator (Type %u)!", _owner->GetEntry(), curr->GetMovementGeneratorType());
    if (IsStatic(curr))
        return;
    if (!_expireList)
        _expireList = new ExpireList();
    _expireList->push_back(curr);
}
