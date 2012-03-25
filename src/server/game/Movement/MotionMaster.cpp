/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ConfusedMovementGenerator.h"
#include "FleeingMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "PointMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "WaypointMovementGenerator.h"
#include "RandomMovementGenerator.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include <cassert>

inline bool isStatic(MovementGenerator *mv)
{
    return (mv == &si_idleMovement);
}

void MotionMaster::Initialize()
{
    impl()->DropAllAIStates();

    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        MovementGenerator* movement = FactorySelector::selectMovementGenerator(_owner->ToCreature());
        if (movement)
            Mutate(movement, UNIT_ACTION_IDLE);
    }
}

MotionMaster::~MotionMaster()
{
}

void MotionMaster::MoveIdle()
{
    impl()->DropAllAIStates();
}

void MotionMaster::MoveRandom(float spawndist)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        sLog->outStaticDebug("Creature (GUID: %u) start moving random", _owner->GetGUIDLow());
        Mutate(new RandomMovementGenerator<Creature>(spawndist), UNIT_ACTION_DOWAYPOINTS);
    }
}

void MotionMaster::MoveTargetedHome()
{
    //impl()->DropAction(UNIT_ACTION_CHASE);
    Clear(false);

    if (_owner->GetTypeId()==TYPEID_UNIT && !((Creature*)_owner)->GetCharmerOrOwnerGUID())
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) targeted home", _owner->GetEntry(), _owner->GetGUIDLow());
        Mutate(new HomeMovementGenerator<Creature>(), UNIT_ACTION_DOWAYPOINTS);
    }
    else if (_owner->GetTypeId()==TYPEID_UNIT && ((Creature*)_owner)->GetCharmerOrOwnerGUID())
    {
        sLog->outStaticDebug("Pet or controlled creature (Entry: %u GUID: %u) targeting home", _owner->GetEntry(), _owner->GetGUIDLow() );
        Unit *target = ((Creature*)_owner)->GetCharmerOrOwner();
        if (target)
        {
            sLog->outStaticDebug("Following %s (GUID: %u)", target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature", target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : ((Creature*)target)->GetDBTableGUIDLow() );
            Mutate(new FollowMovementGenerator<Creature>(*target,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE), UNIT_ACTION_CHASE);
        }
    }
    else
    {
        sLog->outError("Player (GUID: %u) attempt targeted home", _owner->GetGUIDLow());
    }
}

void MotionMaster::MoveConfused()
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) move confused", _owner->GetGUIDLow());
        Mutate(new ConfusedMovementGenerator<Player>(), UNIT_ACTION_CONFUSED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) move confused",
            _owner->GetEntry(), _owner->GetGUIDLow());
        Mutate(new ConfusedMovementGenerator<Creature>(), UNIT_ACTION_CONFUSED);
    }
}

void MotionMaster::MoveChase(Unit* target, float dist, float angle)
{
    // ignore movement request if target not exist
    if (!target || target == _owner || _owner->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return;
    //ASSERT(false);
    //_owner->ClearUnitState(UNIT_STATE_FOLLOW);
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) chase to %s (GUID: %u)",
            _owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new ChaseMovementGenerator<Player>(*target,dist,angle), UNIT_ACTION_CHASE);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) chase to %s (GUID: %u)",
            _owner->GetEntry(), _owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new ChaseMovementGenerator<Creature>(*target,dist,angle), UNIT_ACTION_CHASE);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle, UnitActionId slot)
{
    // ignore movement request if target not exist
    if (!target || target == _owner || _owner->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return;

    //_owner->AddUnitState(UNIT_STATE_FOLLOW);
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) follow to %s (GUID: %u)", _owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new FollowMovementGenerator<Player>(*target,dist,angle), slot);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) follow to %s (GUID: %u)",
            _owner->GetEntry(), _owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new FollowMovementGenerator<Creature>(*target,dist,angle), slot);
    }
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) targeted point (Id: %u X: %f Y: %f Z: %f)", _owner->GetGUIDLow(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z), UNIT_ACTION_DOWAYPOINTS);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) targeted point (ID: %u X: %f Y: %f Z: %f)",
            _owner->GetEntry(), _owner->GetGUIDLow(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z), UNIT_ACTION_DOWAYPOINTS);
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos, float speed)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    sLog->outStaticDebug("Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f)", _owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(*_owner);
    init.MoveTo(x,y,z);
    init.SetVelocity(speed);
    init.SetAnimation(Movement::ToGround);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), UNIT_ACTION_DOWAYPOINTS);
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos, float speed)
{
    float x, y, z;
    pos.GetPosition(x, y, z);

    sLog->outStaticDebug("Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f)", _owner->GetEntry(), id, x, y, z);

    Movement::MoveSplineInit init(*_owner);
    init.MoveTo(x,y,z);
    init.SetVelocity(speed);
    init.SetAnimation(Movement::ToFly);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), UNIT_ACTION_DOWAYPOINTS);
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z;
    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;

    _owner->GetNearPoint(_owner, x, y, z, _owner->GetObjectSize(), dist, _owner->GetAngle(srcX, srcY) + M_PI);
    MoveJump(x, y, z, speedXY, speedZ);
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
    MoveJump(x, y, z, speedXY, speedZ);
}

void MotionMaster::MoveJump(float x, float y, float z, float speedXY, float speedZ, uint32 id)
{
    sLog->outStaticDebug("Unit (GUID: %u) jump to point (X: %f Y: %f Z: %f)", _owner->GetGUIDLow(), x, y, z);

    float moveTimeHalf = speedZ / Movement::gravity;
    float max_height = -Movement::computeFallElevation(moveTimeHalf,false,-speedZ);

    Movement::MoveSplineInit init(*_owner);
    init.MoveTo(x,y,z);
    init.SetParabolic(max_height,0);
    init.SetVelocity(speedXY);
    init.Launch();
    Mutate(new EffectMovementGenerator(id), UNIT_ACTION_EFFECT);
}

void MotionMaster::MoveFall(uint32 id/*=0*/)
{
    // use larger distance for vmap height search than in most other cases
    float tz = _owner->GetMap()->GetHeight(_owner->GetPhaseMask(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        sLog->outStaticDebug("MotionMaster::MoveFall: unable retrive a proper height at map %u (x: %f, y: %f, z: %f).",
            _owner->GetMap()->GetId(), _owner->GetPositionX(), _owner->GetPositionX(), _owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (fabs(_owner->GetPositionZ() - tz) < 0.1f)
        return;

    Movement::MoveSplineInit init(*_owner);
    init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), tz);
    init.SetFall();
    init.Launch();
    Mutate(new EffectMovementGenerator(id), UNIT_ACTION_EFFECT);
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed, uint32 id)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) charge point (X: %f Y: %f Z: %f)", _owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, speed), UNIT_ACTION_EFFECT);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) charge point (X: %f Y: %f Z: %f)",
            _owner->GetEntry(), _owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, speed), UNIT_ACTION_EFFECT);
    }
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outError("Player (GUID: %u) attempt to seek assistance", _owner->GetGUIDLow());
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) seek assistance (X: %f Y: %f Z: %f)",
            _owner->GetEntry(), _owner->GetGUIDLow(), x, y, z);
        _owner->AttackStop();
        _owner->ToCreature()->SetReactState(REACT_PASSIVE);
        Mutate(new AssistanceMovementGenerator(x, y, z), UNIT_ACTION_ASSISTANCE);
    }
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outError("Player (GUID: %u) attempt to call distract after assistance", _owner->GetGUIDLow());
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) is distracted after assistance call (Time: %u)",
            _owner->GetEntry(), _owner->GetGUIDLow(), time);
        Mutate(new AssistanceDistractMovementGenerator(time), UNIT_ACTION_ASSISTANCE);
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    if (_owner->HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
        return;

    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) flee from %s (GUID: %u)", _owner->GetGUIDLow(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUIDLow() : enemy->ToCreature()->GetDBTableGUIDLow());
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetGUID()), UNIT_ACTION_FEARED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) flee from %s (GUID: %u)%s",
            _owner->GetEntry(), _owner->GetGUIDLow(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUIDLow() : enemy->ToCreature()->GetDBTableGUIDLow(),
            time ? " for a limited time" : "");
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetGUID(), time), UNIT_ACTION_FEARED);
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetGUID()), UNIT_ACTION_FEARED);
    }
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            sLog->outStaticDebug("%s taxi to (Path %u node %u)", _owner->GetName(), path, pathnode);
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator(sTaxiPathNodesByPath[path], pathnode);
            Mutate(mgen, UNIT_ACTION_EFFECT);
        }
        else
        {
            sLog->outError("%s attempt taxi to (not existed Path %u node %u)",
            _owner->GetName(), path, pathnode);
        }
    }
    else
    {
        sLog->outError("Creature (Entry: %u GUID: %u) attempt taxi to (Path %u node %u)",
            _owner->GetEntry(), _owner->GetGUIDLow(), path, pathnode);
    }
}

void MotionMaster::MoveDistract(uint32 timer)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) distracted (timer: %u)", _owner->GetGUIDLow(), timer);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) (timer: %u)",
            _owner->GetEntry(), _owner->GetGUIDLow(), timer);
    }

    DistractMovementGenerator* mgen = new DistractMovementGenerator(timer);
    Mutate(mgen, UNIT_ACTION_EFFECT);
}

void MotionMaster::MovePath(uint32 path_id, bool repeatable)
{
    if (!path_id)
        return;

    Mutate(new WaypointMovementGenerator<Creature>(path_id, repeatable), UNIT_ACTION_DOWAYPOINTS);

    sLog->outStaticDebug("%s (GUID: %u) start moving over path(Id:%u, repeatable: %s)",
        _owner->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature",
        _owner->GetGUIDLow(), path_id, repeatable ? "YES" : "NO");
}

void MotionMaster::MoveRotate(uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    Mutate(new RotateMovementGenerator(time, direction), UNIT_ACTION_DOWAYPOINTS);
}

void MotionMaster::Mutate(MovementGenerator* mgen, UnitActionId stateId)
{
    impl()->PushAction(stateId, UnitActionPtr(mgen));
}

void MotionMaster::Clear(bool reset /*= true*/)
{
    if (reset)
        impl()->DropAllAIStatesExcept(UNIT_ACTION_PRIORITY_IDLE);
    else
        Initialize();
}

MovementGenerator* MotionMaster::top()
{
    UnitActionPtr mgen = impl()->CurrentAction();
    return ((MovementGenerator*)&*mgen);
}

UnitStateMgr* MotionMaster::impl()
{
    UnitStateMgr* mgr = &_owner->GetUnitStateMgr();
    return mgr;
}

bool MotionMaster::empty()
{
    MovementGenerator* mgen = top();
    if (isStatic(mgen))
        return true;

    return false;
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
   return const_cast<MotionMaster*>(this)->top()->GetMovementGeneratorType();
}

MovementGeneratorType MotionMaster::GetMotionSlotType(UnitActionPriority priority) const
{
    ActionInfo *state = const_cast<MotionMaster*>(this)->impl()->GetAction(priority);
    if (state)
        return state->action->GetMovementGeneratorType();

    return NULL_MOTION_TYPE;
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    if (_owner->movespline->Finalized())
       return false;

    const G3D::Vector3& dest = _owner->movespline->FinalDestination();
    x = dest.x;
    y = dest.y;
    z = dest.z;
    return true;
}
