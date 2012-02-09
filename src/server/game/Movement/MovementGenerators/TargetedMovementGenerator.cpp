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

#include "ByteBuffer.h"
#include "TargetedMovementGenerator.h"
#include "Errors.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "World.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"

#include <cmath>

template<class T, typename D>
void TargetedMovementGeneratorMedium<T,D>::_setTargetLocation(T &unit)
{
    if (!i_target.isValid() || !i_target->IsInWorld())
        return;

    if (unit.HasUnitState(UNIT_STATE_NOT_MOVE))
        return;

    float x, y, z;

    if (i_offset && i_target->IsWithinDistInMap(&unit,2*i_offset))
    {
        if (!unit.movespline->Finalized())
            return;

        unit.GetPosition(x, y, z);
    }
    else if (!i_offset)
    {
        if (i_target->IsWithinMeleeRange(&unit))
            return;

        // to nearest random contact position
        i_target->GetRandomContactPoint(&unit, x, y, z, 0, MELEE_RANGE - 0.5f);
    }
    else
    {
        if (i_target->IsWithinDistInMap(&unit, i_offset + 1.0f))
            return;
        // to at i_offset distance from target and i_angle from target facing
        i_target->GetClosePoint(x, y, z, unit.GetObjectSize(), i_offset, i_angle);
    }

    /*
        We MUST not check the distance difference and avoid setting the new location for smaller distances.
        By that we risk having far too many GetContactPoint() calls freezing the whole system.
        In TargetedMovementGenerator<T>::Update() we check the distance to the target and at
        some range we calculate a new position. The calculation takes some processor cycles due to vmaps.
        If the distance to the target it too large to ignore,
        but the distance to the new contact point is short enough to be ignored,
        we will calculate a new contact point each update loop, but will never move to it.
        The system will freeze.
        ralf

        //We don't update Mob Movement, if the difference between New destination and last destination is < BothObjectSize
        float  bothObjectSize = i_target->GetObjectBoundingRadius() + owner.GetObjectBoundingRadius() + CONTACT_DISTANCE;
        if( i_destinationHolder.HasDestination() && i_destinationHolder.GetDestinationDiff(x,y,z) < bothObjectSize )
            return;
    */

    i_targetReached = false;
    i_recalculateTravel = false;

    Movement::MoveSplineInit init(unit);
    init.MoveTo(x,y,z);
    init.SetWalk(((D*)this)->EnableWalking());
    init.Launch();
}

template<>
void TargetedMovementGeneratorMedium<Player,ChaseMovementGenerator<Player> >::UpdateFinalDistance(float /*fDistance*/)
{
    // nothing to do for Player
}

template<>
void TargetedMovementGeneratorMedium<Player,FollowMovementGenerator<Player> >::UpdateFinalDistance(float /*fDistance*/)
{
    // nothing to do for Player
}

template<>
void TargetedMovementGeneratorMedium<Creature,ChaseMovementGenerator<Creature> >::UpdateFinalDistance(float fDistance)
{
    i_offset = fDistance;
    i_recalculateTravel = true;
}

template<>
void TargetedMovementGeneratorMedium<Creature,FollowMovementGenerator<Creature> >::UpdateFinalDistance(float fDistance)
{
    i_offset = fDistance;
    i_recalculateTravel = true;
}

template<class T, typename D>
bool TargetedMovementGeneratorMedium<T,D>::Update(T &unit, const uint32 & time_diff)
{
    if (!i_target.isValid() || !i_target->IsInWorld())
        return false;

    if (!unit.isAlive())
        return true;

    if (unit.HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        return true;
    }

    // prevent movement while casting spells with cast time or channel time
    if (unit.IsNonMeleeSpellCasted(false, false,  true))
    {
        if (!unit.IsStopped())
            unit.StopMoving();
        return true;
    }

    // prevent crash after creature killed pet
    if (static_cast<D*>(this)->_lostTarget(unit))
    {
        return true;
    }

    i_recheckDistance.Update(time_diff);
    if (i_recheckDistance.Passed())
    {
        i_recheckDistance.Reset(50);
        //More distance let have better performance, less distance let have more sensitive reaction at target move.
        float allowed_dist = i_target->GetObjectSize() + unit.GetObjectSize() + MELEE_RANGE - 0.5f;
        float dist = (unit.movespline->FinalDestination() - G3D::Vector3(i_target->GetPositionX(),i_target->GetPositionY(),i_target->GetPositionZ())).squaredLength();
        if (dist >= allowed_dist * allowed_dist)
            _setTargetLocation(unit);
    }

    if (unit.movespline->Finalized())
    {
        static_cast<D*>(this)->MovementInform(unit);
        if (i_angle == 0.f && !unit.HasInArc(0.01f, i_target.getTarget()))
            unit.SetInFront(i_target.getTarget());

        if (!i_targetReached)
        {
            i_targetReached = true;
            static_cast<D*>(this)->_reachTarget(unit);
        }
    }
    else
    {
        if (i_recalculateTravel)
            _setTargetLocation(unit);
    }
    return true;
}

//-----------------------------------------------//
template<class T>
void ChaseMovementGenerator<T>::_reachTarget(T &unit)
{
    if (unit.IsWithinMeleeRange(this->i_target.getTarget()))
        unit.Attack(this->i_target.getTarget(),true);
}

template<>
void ChaseMovementGenerator<Player>::Initialize(Player &unit)
{
    unit.AddUnitState(UNIT_STATE_CHASE);
    _setTargetLocation(unit);
}

template<>
void ChaseMovementGenerator<Creature>::Initialize(Creature &unit)
{
    unit.SetWalk(false);
    unit.AddUnitState(UNIT_STATE_CHASE);
    _setTargetLocation(unit);
}

template<class T>
void ChaseMovementGenerator<T>::Finalize(T &unit)
{
    unit.ClearUnitState(UNIT_STATE_CHASE);
}

template<class T>
void ChaseMovementGenerator<T>::Reset(T &unit)
{
    Initialize(unit);
}

template<class T>
void ChaseMovementGenerator<T>::MovementInform(T & /*unit*/)
{
}

template<>
void ChaseMovementGenerator<Creature>::MovementInform(Creature &unit)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (unit.AI())
        unit.AI()->MovementInform(CHASE_MOTION_TYPE, i_target.getTarget()->GetGUIDLow());
}

//-----------------------------------------------//
template<>
bool FollowMovementGenerator<Creature>::EnableWalking() const
{
    return i_target.isValid() && i_target->IsWalking();
}

template<>
bool FollowMovementGenerator<Player>::EnableWalking() const
{
    return false;
}

template<>
void FollowMovementGenerator<Player>::_updateSpeed(Player &/*u*/)
{
    // nothing to do for Player
}

template<>
void FollowMovementGenerator<Creature>::_updateSpeed(Creature &unit)
{
    // pet only sync speed with owner
    if (!((Creature&)unit).isPet() || !i_target.isValid() || i_target->GetGUID() != unit.GetOwnerGUID())
        return;

    unit.UpdateSpeed(MOVE_RUN,true);
    unit.UpdateSpeed(MOVE_WALK,true);
    unit.UpdateSpeed(MOVE_SWIM,true);
}

template<>
void FollowMovementGenerator<Player>::Initialize(Player &unit)
{
    unit.AddUnitState(UNIT_STATE_FOLLOW);
    _updateSpeed(unit);
    _setTargetLocation(unit);
}

template<>
void FollowMovementGenerator<Creature>::Initialize(Creature &unit)
{
    unit.AddUnitState(UNIT_STATE_FOLLOW);
    _updateSpeed(unit);
    _setTargetLocation(unit);
}

template<class T>
void FollowMovementGenerator<T>::Finalize(T &unit)
{
    unit.ClearUnitState(UNIT_STATE_FOLLOW);
    _updateSpeed(unit);
}

template<class T>
void FollowMovementGenerator<T>::Reset(T &unit)
{
    Initialize(unit);
}

template<class T>
void FollowMovementGenerator<T>::MovementInform(T & /*unit*/)
{
}

template<>
void FollowMovementGenerator<Creature>::MovementInform(Creature &unit)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (unit.AI())
        unit.AI()->MovementInform(FOLLOW_MOTION_TYPE, i_target.getTarget()->GetGUIDLow());
}

//-----------------------------------------------//
template void TargetedMovementGeneratorMedium<Player,ChaseMovementGenerator<Player> >::_setTargetLocation(Player &);
template void TargetedMovementGeneratorMedium<Player,FollowMovementGenerator<Player> >::_setTargetLocation(Player &);
template void TargetedMovementGeneratorMedium<Creature,ChaseMovementGenerator<Creature> >::_setTargetLocation(Creature &);
template void TargetedMovementGeneratorMedium<Creature,FollowMovementGenerator<Creature> >::_setTargetLocation(Creature &);
template bool TargetedMovementGeneratorMedium<Player,ChaseMovementGenerator<Player> >::Update(Player &, const uint32 &);
template bool TargetedMovementGeneratorMedium<Player,FollowMovementGenerator<Player> >::Update(Player &, const uint32 &);
template bool TargetedMovementGeneratorMedium<Creature,ChaseMovementGenerator<Creature> >::Update(Creature &, const uint32 &);
template bool TargetedMovementGeneratorMedium<Creature,FollowMovementGenerator<Creature> >::Update(Creature &, const uint32 &);

template void ChaseMovementGenerator<Player>::_reachTarget(Player &);
template void ChaseMovementGenerator<Creature>::_reachTarget(Creature &);
template void ChaseMovementGenerator<Player>::Finalize(Player &);
template void ChaseMovementGenerator<Creature>::Finalize(Creature &);
template void ChaseMovementGenerator<Player>::Reset(Player &);
template void ChaseMovementGenerator<Creature>::Reset(Creature &);
template void ChaseMovementGenerator<Player>::MovementInform(Player &);

template void FollowMovementGenerator<Player>::Finalize(Player &);
template void FollowMovementGenerator<Creature>::Finalize(Creature &);
template void FollowMovementGenerator<Player>::Reset(Player &);
template void FollowMovementGenerator<Creature>::Reset(Creature &);
template void FollowMovementGenerator<Player>::MovementInform(Player &);
