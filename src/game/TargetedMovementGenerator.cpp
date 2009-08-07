/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ByteBuffer.h"
#include "TargetedMovementGenerator.h"
#include "Errors.h"
#include "Creature.h"
#include "DestinationHolderImp.h"
#include "World.h"

#define SMALL_ALPHA 0.05f

#include <cmath>
/*
struct StackCleaner
{
    Creature &i_creature;
    StackCleaner(Creature &creature) : i_creature(creature) {}
    void Done(void) { i_creature.StopMoving(); }
    ~StackCleaner()
    {
        i_creature->Clear();
    }
};
*/

template<class T>
TargetedMovementGenerator<T>::TargetedMovementGenerator(Unit &target, float offset, float angle)
: TargetedMovementGeneratorBase(target)
, i_offset(offset), i_angle(angle), i_recalculateTravel(false)
{
    target.GetPosition(i_targetX, i_targetY, i_targetZ);
}

template<class T>
bool
TargetedMovementGenerator<T>::_setTargetLocation(T &owner)
{
    if (!i_target.isValid() || !i_target->IsInWorld())
        return false;

    if( owner.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED) )
        return false;

    float x, y, z;
    Traveller<T> traveller(owner);
    if(i_destinationHolder.HasDestination())
    {
        if(i_destinationHolder.HasArrived())
        {
            // prevent redundant micro-movement
            if(i_offset ? i_target->IsWithinDistInMap(&owner, i_offset + 1.0f) : i_target->IsWithinMeleeRange(&owner))
                return false;
        }
        else
        {
            bool stop = false;
            if(!i_offset)
            {
                if(i_target->IsWithinMeleeRange(&owner, 0))
                    stop = true;
            }
            else if(!i_angle && !owner.hasUnitState(UNIT_STAT_FOLLOW))
            {
                if(i_target->IsWithinDist(&owner, i_offset * 0.8))
                    stop = true;
            }

            if(stop)
            {
                owner.GetPosition(x, y, z);
                i_destinationHolder.SetDestination(traveller, x, y, z);
                i_destinationHolder.StartTravel(traveller, false);
                owner.StopMoving();
                return false;
            }
        }

        if(i_target->GetDistanceSq(i_targetX, i_targetY, i_targetZ) < 0.01f)
            return false;
    }

    if(!i_offset)
    {
        // to nearest random contact position
        i_target->GetRandomContactPoint( &owner, x, y, z, 0, MELEE_RANGE - 0.5f );
    }
    else if(!i_angle && !owner.hasUnitState(UNIT_STAT_FOLLOW))
    {
        // caster chase
        i_target->GetContactPoint(&owner, x, y, z, i_offset * urand(80, 100) * 0.01f);
    }
    else
    {
        // to at i_offset distance from target and i_angle from target facing
        i_target->GetClosePoint(x,y,z,owner.GetObjectSize(),i_offset,i_angle);
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
        float  bothObjectSize = i_target->GetObjectSize() + owner.GetObjectSize() + CONTACT_DISTANCE;
        if( i_destinationHolder.HasDestination() && i_destinationHolder.GetDestinationDiff(x,y,z) < bothObjectSize )
            return;
    */
    i_destinationHolder.SetDestination(traveller, x, y, z);
    owner.addUnitState(UNIT_STAT_CHASE);
    if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
        owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
    i_destinationHolder.StartTravel(traveller);
    return true;
}

template<class T>
void
TargetedMovementGenerator<T>::Initialize(T &owner)
{
    if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->HasSearchedAssistance())
        owner.AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
    else
        owner.RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

    if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
        owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING);

    _setTargetLocation(owner);
}

template<class T>
void
TargetedMovementGenerator<T>::Finalize(T &owner)
{
    owner.clearUnitState(UNIT_STAT_CHASE);
}

template<class T>
void
TargetedMovementGenerator<T>::Reset(T &owner)
{
    Initialize(owner);
}

template<class T>
bool
TargetedMovementGenerator<T>::Update(T &owner, const uint32 & time_diff)
{
    if (!i_target.isValid() || !i_target->IsInWorld())
        return false;

    if( !&owner || !owner.isAlive())
        return true;

    if( owner.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_FLEEING | UNIT_STAT_DISTRACTED) )
        return true;

    // prevent movement while casting spells with cast time or channel time
    if(owner.hasUnitState(UNIT_STAT_CASTING))
    {
        if (!owner.IsStopped())
            owner.StopMoving();
        return true;
    }

    // prevent crash after creature killed pet
    if (!owner.hasUnitState(UNIT_STAT_FOLLOW) && owner.getVictim() != i_target.getTarget())
        return true;

    Traveller<T> traveller(owner);

    if( !i_destinationHolder.HasDestination() )
        _setTargetLocation(owner);
    else if( owner.IsStopped() && !i_destinationHolder.HasArrived() )
    {
        owner.addUnitState(UNIT_STAT_CHASE);
        if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
            owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING);

        i_destinationHolder.StartTravel(traveller);
        return true;
    }

    if (i_destinationHolder.UpdateTraveller(traveller, time_diff))
    {
        // put targeted movement generators on a higher priority
        //if (owner.GetObjectSize())
        //i_destinationHolder.ResetUpdate(50);

        // target moved
        if(i_targetX != i_target->GetPositionX() || i_targetY != i_target->GetPositionY()
            || i_targetZ != i_target->GetPositionZ())
        {
            if(_setTargetLocation(owner) || !owner.hasUnitState(UNIT_STAT_FOLLOW))
                owner.SetInFront(i_target.getTarget());
            i_target->GetPosition(i_targetX, i_targetY, i_targetZ);
        }

        if(( owner.IsStopped() && !i_destinationHolder.HasArrived() ) || i_recalculateTravel )
        {
            i_recalculateTravel = false;
            //Angle update will take place into owner.StopMoving()
            owner.SetInFront(i_target.getTarget());

            owner.StopMoving();
            if(owner.IsWithinMeleeRange(i_target.getTarget()) && !owner.hasUnitState(UNIT_STAT_FOLLOW))
                owner.Attack(i_target.getTarget(),true);
        }
    }
    return true;
}

template<class T>
Unit*
TargetedMovementGenerator<T>::GetTarget() const
{
    return i_target.getTarget();
}

template TargetedMovementGenerator<Player>::TargetedMovementGenerator(Unit &target, float offset, float angle);
template TargetedMovementGenerator<Creature>::TargetedMovementGenerator(Unit &target, float offset, float angle);
template bool TargetedMovementGenerator<Player>::_setTargetLocation(Player &);
template bool TargetedMovementGenerator<Creature>::_setTargetLocation(Creature &);
template void TargetedMovementGenerator<Player>::Initialize(Player &);
template void TargetedMovementGenerator<Creature>::Initialize(Creature &);
template void TargetedMovementGenerator<Player>::Finalize(Player &);
template void TargetedMovementGenerator<Creature>::Finalize(Creature &);
template void TargetedMovementGenerator<Player>::Reset(Player &);
template void TargetedMovementGenerator<Creature>::Reset(Creature &);
template bool TargetedMovementGenerator<Player>::Update(Player &, const uint32 &);
template bool TargetedMovementGenerator<Creature>::Update(Creature &, const uint32 &);
template Unit* TargetedMovementGenerator<Player>::GetTarget() const;
template Unit* TargetedMovementGenerator<Creature>::GetTarget() const;

