/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#include "MapManager.h"
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
void
TargetedMovementGenerator<T>::_setTargetLocation(T &owner)
{
    if( !i_target.isValid() || !&owner )
        return;

    if( owner.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED) )
        return;

    // prevent redundant micro-movement for pets, other followers.
    //if(i_offset && i_target->IsWithinDistInMap(&owner,2*i_offset))
    //    return;

    float x, y, z;
    if(!i_offset)
    {
        // to nearest random contact position
        i_target->GetRandomContactPoint( &owner, x, y, z, 0, MELEE_RANGE - 0.5f );
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
    Traveller<T> traveller(owner);
    i_destinationHolder.SetDestination(traveller, x, y, z);
    owner.addUnitState(UNIT_STAT_CHASE);
    if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
        owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);
}

template<class T>
void
TargetedMovementGenerator<T>::Initialize(T &owner)
{
    if(!&owner)
        return;
    owner.RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

    if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
        owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);

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
    if(!i_target.isValid())
        return false;

    if( !&owner || !owner.isAlive())
        return true;

    if( owner.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_FLEEING | UNIT_STAT_DISTRACTED) )
        return true;

    // prevent movement while casting spells with cast time or channel time
    if ( owner.IsNonMeleeSpellCasted(false, false,  true))
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
    if( owner.IsStopped() && !i_destinationHolder.HasArrived() )
    {
        owner.addUnitState(UNIT_STAT_CHASE);
        if (owner.GetTypeId() == TYPEID_UNIT && ((Creature*)&owner)->canFly())
            owner.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);

        i_destinationHolder.StartTravel(traveller);
        return true;
    }

    if (i_destinationHolder.UpdateTraveller(traveller, time_diff))
    {
        // put targeted movement generators on a higher priority
        if (owner.GetObjectSize())
            i_destinationHolder.ResetUpdate(50);

        //float dist = owner.GetCombatReach() + i_target.getTarget()->GetCombatReach() + sWorld.getRate(RATE_TARGET_POS_RECALCULATION_RANGE);

        //More distance let have better performance, less distance let have more sensitive reaction at target move.

        // try to counter precision differences
        //if( i_destinationHolder.GetDistance2dFromDestSq(*i_target.getTarget()) >= dist * dist)
        if(i_offset ? !i_target->IsWithinDistInMap(&owner,2*i_offset)
            : !i_target->IsWithinMeleeRange(&owner))
        {
            owner.SetInFront(i_target.getTarget());         // Set new Angle For Map::
            _setTargetLocation(owner);                      //Calculate New Dest and Send data To Player
        }
        // Update the Angle of the target only for Map::, no need to send packet for player
        else if ( !i_angle && !owner.HasInArc( 0.01f, i_target.getTarget() ) )
            owner.SetInFront(i_target.getTarget());

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

template void TargetedMovementGenerator<Player>::_setTargetLocation(Player &);
template void TargetedMovementGenerator<Creature>::_setTargetLocation(Creature &);
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

