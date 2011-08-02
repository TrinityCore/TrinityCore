/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "Traveller.h"

#include "ConfusedMovementGenerator.h"
#include "FleeingMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "PointMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "WaypointMovementGenerator.h"
#include "RandomMovementGenerator.h"

#include <cassert>

inline bool isStatic(MovementGenerator *mv)
{
    return (mv == &si_idleMovement);
}

void MotionMaster::Initialize()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator *curr = top();
        pop();
        if (curr) DirectDelete(curr);
    }

    InitDefault();
}

// set new default movement generator
void MotionMaster::InitDefault()
{
    if (i_owner->GetTypeId() == TYPEID_UNIT)
    {
        MovementGenerator* movement = FactorySelector::selectMovementGenerator(i_owner->ToCreature());
        Mutate(movement == NULL ? &si_idleMovement : movement, MOTION_SLOT_IDLE);
    }
    else
    {
        Mutate(&si_idleMovement, MOTION_SLOT_IDLE);
    }
}

MotionMaster::~MotionMaster()
{
    // clear ALL movement generators (including default)
    while (!empty())
    {
        MovementGenerator *curr = top();
        pop();
        if (curr) DirectDelete(curr);
    }
}

void MotionMaster::UpdateMotion(uint32 diff)
{
    if (!i_owner)
        return;

    if (i_owner->HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED)) // what about UNIT_STAT_DISTRACTED? Why is this not included?
        return;

    ASSERT(!empty());

    m_cleanFlag |= MMCF_UPDATE;
    if (!top()->Update(*i_owner, diff))
    {
        m_cleanFlag &= ~MMCF_UPDATE;
        MovementExpired();
    }
    else
        m_cleanFlag &= ~MMCF_UPDATE;

    if (m_expList)
    {
        for (size_t i = 0; i < m_expList->size(); ++i)
        {
            MovementGenerator* mg = (*m_expList)[i];
            DirectDelete(mg);
        }

        delete m_expList;
        m_expList = NULL;

        if (empty())
            Initialize();
        else if (needInitTop())
            InitTop();
        else if (m_cleanFlag & MMCF_RESET)
            top()->Reset(*i_owner);

        m_cleanFlag &= ~MMCF_RESET;
    }
}

void MotionMaster::DirectClean(bool reset)
{
    while (size() > 1)
    {
        MovementGenerator *curr = top();
        pop();
        if (curr) DirectDelete(curr);
    }

    if (needInitTop())
        InitTop();
    else if (reset)
        top()->Reset(*i_owner);
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

    while (!top())
        --i_top;

    if (empty())
        Initialize();
    else if (needInitTop())
        InitTop();
    else if (reset)
        top()->Reset(*i_owner);
}

void MotionMaster::DelayedExpire()
{
    if (size() > 1)
    {
        MovementGenerator *curr = top();
        pop();
        DelayedDelete(curr);
    }

    while (!top())
        --i_top;
}

void MotionMaster::MoveIdle(MovementSlot slot)
{
    //if (empty() || !isStatic(top()))
    //    push(&si_idleMovement);
    if (!isStatic(Impl[slot]))
        Mutate(&si_idleMovement, slot);
}

void MotionMaster::MoveRandom(float spawndist)
{
    if (i_owner->GetTypeId() == TYPEID_UNIT)
    {
        sLog->outStaticDebug("Creature (GUID: %u) start moving random", i_owner->GetGUIDLow());
        Mutate(new RandomMovementGenerator<Creature>(spawndist), MOTION_SLOT_IDLE);
    }
}

void MotionMaster::MoveTargetedHome()
{
    //if (i_owner->HasUnitState(UNIT_STAT_FLEEING))
    //    return;

    Clear(false);

    if (i_owner->GetTypeId() == TYPEID_UNIT)
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) targeted home", i_owner->GetEntry(), i_owner->GetGUIDLow());
        Mutate(new HomeMovementGenerator<Creature>(), MOTION_SLOT_ACTIVE);
    }
    else
    {
        sLog->outError("Player (GUID: %u) attempt targeted home", i_owner->GetGUIDLow());
    }
}

void MotionMaster::MoveConfused()
{
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) move confused", i_owner->GetGUIDLow());
        Mutate(new ConfusedMovementGenerator<Player>(), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) move confused",
            i_owner->GetEntry(), i_owner->GetGUIDLow());
        Mutate(new ConfusedMovementGenerator<Creature>(), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveChase(Unit* target, float dist, float angle)
{
    // ignore movement request if target not exist
    if (!target || target == i_owner || i_owner->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return;

    i_owner->ClearUnitState(UNIT_STAT_FOLLOW);
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) chase to %s (GUID: %u)",
            i_owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new TargetedMovementGenerator<Player>(*target, dist, angle), MOTION_SLOT_ACTIVE);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) chase to %s (GUID: %u)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new TargetedMovementGenerator<Creature>(*target, dist, angle), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle, MovementSlot slot)
{
    // ignore movement request if target not exist
    if (!target || target == i_owner || i_owner->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
        return;

    i_owner->AddUnitState(UNIT_STAT_FOLLOW);
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) follow to %s (GUID: %u)", i_owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new TargetedMovementGenerator<Player>(*target, dist, angle), slot);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) follow to %s (GUID: %u)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(),
            target->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            target->GetTypeId() == TYPEID_PLAYER ? target->GetGUIDLow() : target->ToCreature()->GetDBTableGUIDLow());
        Mutate(new TargetedMovementGenerator<Creature>(*target, dist, angle), slot);
    }
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z)
{
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) targeted point (Id: %u X: %f Y: %f Z: %f)", i_owner->GetGUIDLow(), id, x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z), MOTION_SLOT_ACTIVE);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) targeted point (ID: %u X: %f Y: %f Z: %f)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), id, x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos, float speed)
{
    if (i_owner->GetTypeId() != TYPEID_UNIT)
        return;

    uint32 moveFlag = SPLINEFLAG_FLYING | SPLINEFLAG_ANIMATIONTIER;
    uint32 moveTime = uint32(i_owner->GetExactDist(&pos) / speed) * IN_MILLISECONDS;

    // CHARGING state makes the unit use m_TempSpeed and JUMPING prevents sending movement packet in PointMovementGenerator
    i_owner->AddUnitState(UNIT_STAT_CHARGING | UNIT_STAT_JUMPING);
    i_owner->m_TempSpeed = speed;

    float x, y, z;
    pos.GetPosition(x, y, z);
    sLog->outStaticDebug("Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f)", i_owner->GetEntry(), id, x, y, z);
    Mutate(new PointMovementGenerator<Creature>(id, x, y, z), MOTION_SLOT_ACTIVE);

    MonsterMoveData data;
    data.DestLocation.Relocate(pos);
    data.SplineFlag = moveFlag;
    data.Time = moveTime;
    data.AnimationState = ANIMATION_ON_GROUND;

    i_owner->SendMonsterMove(data);
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos, float speed)
{
    if (i_owner->GetTypeId() != TYPEID_UNIT)
        return;

    uint32 moveFlag = SPLINEFLAG_FLYING | SPLINEFLAG_ANIMATIONTIER;
    uint32 moveTime = uint32(i_owner->GetExactDist(&pos) / speed) * IN_MILLISECONDS;

    // CHARGING state makes the unit use m_TempSpeed and JUMPING prevents sending movement packet in PointMovementGenerator
    i_owner->AddUnitState(UNIT_STAT_CHARGING | UNIT_STAT_JUMPING);
    i_owner->m_TempSpeed = speed;

    float x, y, z;
    pos.GetPosition(x, y, z);
    sLog->outStaticDebug("Creature (Entry: %u) landing point (ID: %u X: %f Y: %f Z: %f)", i_owner->GetEntry(), id, x, y, z);
    Mutate(new PointMovementGenerator<Creature>(id, x, y, z), MOTION_SLOT_ACTIVE);

    MonsterMoveData data;
    data.DestLocation.Relocate(pos);
    data.SplineFlag = moveFlag;
    data.Time = moveTime;
    data.AnimationState = ANIMATION_FLYING;

    i_owner->SendMonsterMove(data);
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z;
    float dist = speedXY * speedZ * 0.1f;
    i_owner->GetNearPoint(i_owner, x, y, z, i_owner->GetObjectSize(), dist, i_owner->GetAngle(srcX, srcY) + M_PI);
    MoveJump(x, y, z, speedXY, speedZ);
}

void MotionMaster::MoveJumpTo(float angle, float speedXY, float speedZ)
{
    //this function may make players fall below map
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z;
    float dist = speedXY * speedZ * 0.1f;
    i_owner->GetClosePoint(x, y, z, i_owner->GetObjectSize(), dist, angle);
    MoveJump(x, y, z, speedXY, speedZ);
}

void MotionMaster::MoveJump(float x, float y, float z, float speedXY, float speedZ)
{
    uint32 moveFlag = SPLINEFLAG_TRAJECTORY | SPLINEFLAG_WALKING;
    uint32 time = uint32(speedZ * 100);

    // Instantly interrupt non melee spells being casted
    if (i_owner->IsNonMeleeSpellCasted(true))
        i_owner->InterruptNonMeleeSpells(true);

    i_owner->AddUnitState(UNIT_STAT_CHARGING | UNIT_STAT_JUMPING);
    i_owner->m_TempSpeed = speedXY;
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) jump to point (X: %f Y: %f Z: %f)", i_owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Player>(0, x, y, z), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) jump to point (X: %f Y: %f Z: %f)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Creature>(0, x, y, z), MOTION_SLOT_CONTROLLED);
    }

    i_owner->SendMonsterMove(x, y, z, moveFlag, time, speedZ);
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed, uint32 id)
{
    if (Impl[MOTION_SLOT_CONTROLLED] && Impl[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;

    i_owner->AddUnitState(UNIT_STAT_CHARGING);
    i_owner->m_TempSpeed = speed;
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) charge point (X: %f Y: %f Z: %f)", i_owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Player>(id, x, y, z), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) charge point (X: %f Y: %f Z: %f)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), x, y, z);
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveFall(float z, uint32 id)
{
    i_owner->SetFlying(false);
    i_owner->SendMovementFlagUpdate();
    //AddUnitMovementFlag(MOVEMENTFLAG_FALLING);
    MoveCharge(i_owner->GetPositionX(), i_owner->GetPositionY(), z, SPEED_CHARGE, id);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outError("Player (GUID: %u) attempt to seek assistance", i_owner->GetGUIDLow());
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) seek assistance (X: %f Y: %f Z: %f)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), x, y, z);
        i_owner->AttackStop();
        i_owner->ToCreature()->SetReactState(REACT_PASSIVE);
        Mutate(new AssistanceMovementGenerator(x, y, z), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outError("Player (GUID: %u) attempt to call distract after assistance", i_owner->GetGUIDLow());
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) is distracted after assistance call (Time: %u)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), time);
        Mutate(new AssistanceDistractMovementGenerator(time), MOTION_SLOT_ACTIVE);
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    if (i_owner->HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
        return;

    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) flee from %s (GUID: %u)", i_owner->GetGUIDLow(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUIDLow() : enemy->ToCreature()->GetDBTableGUIDLow());
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) flee from %s (GUID: %u)%s",
            i_owner->GetEntry(), i_owner->GetGUIDLow(),
            enemy->GetTypeId() == TYPEID_PLAYER ? "player" : "creature",
            enemy->GetTypeId() == TYPEID_PLAYER ? enemy->GetGUIDLow() : enemy->ToCreature()->GetDBTableGUIDLow(),
            time ? " for a limited time" : "");
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetGUID(), time), MOTION_SLOT_CONTROLLED);
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetGUID()), MOTION_SLOT_CONTROLLED);
    }
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            sLog->outStaticDebug("%s taxi to (Path %u node %u)", i_owner->GetName(), path, pathnode);
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator(sTaxiPathNodesByPath[path], pathnode);
            Mutate(mgen, MOTION_SLOT_CONTROLLED);
        }
        else
        {
            sLog->outError("%s attempt taxi to (not existed Path %u node %u)",
            i_owner->GetName(), path, pathnode);
        }
    }
    else
    {
        sLog->outError("Creature (Entry: %u GUID: %u) attempt taxi to (Path %u node %u)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), path, pathnode);
    }
}

void MotionMaster::MoveDistract(uint32 timer)
{
    if (Impl[MOTION_SLOT_CONTROLLED])
        return;

    if (i_owner->GetTypeId() == TYPEID_PLAYER)
    {
        sLog->outStaticDebug("Player (GUID: %u) distracted (timer: %u)", i_owner->GetGUIDLow(), timer);
    }
    else
    {
        sLog->outStaticDebug("Creature (Entry: %u GUID: %u) (timer: %u)",
            i_owner->GetEntry(), i_owner->GetGUIDLow(), timer);
    }

    DistractMovementGenerator* mgen = new DistractMovementGenerator(timer);
    Mutate(mgen, MOTION_SLOT_CONTROLLED);
}

void MotionMaster::Mutate(MovementGenerator *m, MovementSlot slot)
{
    if (MovementGenerator *curr = Impl[slot])
    {
        Impl[slot] = NULL; // in case a new one is generated in this slot during directdelete
        if (i_top == slot && (m_cleanFlag & MMCF_UPDATE))
            DelayedDelete(curr);
        else
            DirectDelete(curr);
    }
    else if (i_top < slot)
    {
        i_top = slot;
    }

    Impl[slot] = m;
    if (i_top > slot)
        needInit[slot] = true;
    else
    {
        needInit[slot] = false;
        m->Initialize(*i_owner);
    }
}

void MotionMaster::MovePath(uint32 path_id, bool repeatable)
{
    if (!path_id)
        return;
    //We set waypoint movement as new default movement generator
    // clear ALL movement generators (including default)
    /*while (!empty())
    {
        MovementGenerator *curr = top();
        curr->Finalize(*i_owner);
        pop();
        if (!isStatic(curr))
            delete curr;
    }*/

    //i_owner->GetTypeId() == TYPEID_PLAYER ?
        //Mutate(new WaypointMovementGenerator<Player>(path_id, repeatable)):
        Mutate(new WaypointMovementGenerator<Creature>(path_id, repeatable), MOTION_SLOT_IDLE);

    sLog->outStaticDebug("%s (GUID: %u) start moving over path(Id:%u, repeatable: %s)",
        i_owner->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature",
        i_owner->GetGUIDLow(), path_id, repeatable ? "YES" : "NO");
}

void MotionMaster::MoveRotate(uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    Mutate(new RotateMovementGenerator(time, direction), MOTION_SLOT_ACTIVE);
}

void MotionMaster::propagateSpeedChange()
{
    /*Impl::container_type::iterator it = Impl::c.begin();
    for (; it != end(); ++it)
    {
        (*it)->unitSpeedChanged();
    }*/
    for (int i = 0; i <= i_top; ++i)
    {
        if (Impl[i])
            Impl[i]->unitSpeedChanged();
    }
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
   if (empty())
       return IDLE_MOTION_TYPE;

   return top()->GetMovementGeneratorType();
}

MovementGeneratorType MotionMaster::GetMotionSlotType(int slot) const
{
    if (!Impl[slot])
        return NULL_MOTION_TYPE;
    else
        return Impl[slot]->GetMovementGeneratorType();
}

void MotionMaster::InitTop()
{
    top()->Initialize(*i_owner);
    needInit[i_top] = false;
}

void MotionMaster::DirectDelete(_Ty curr)
{
    if (isStatic(curr))
        return;
    curr->Finalize(*i_owner);
    delete curr;
}

void MotionMaster::DelayedDelete(_Ty curr)
{
    sLog->outCrash("Unit (Entry %u) is trying to delete its updating MG (Type %u)!", i_owner->GetEntry(), curr->GetMovementGeneratorType());
    if (isStatic(curr))
        return;
    if (!m_expList)
        m_expList = new ExpireList();
    m_expList->push_back(curr);
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    if (empty())
       return false;

    return top()->GetDestination(x, y, z);
}
