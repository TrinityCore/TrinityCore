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

#include "Creature.h"
#include "MapManager.h"
#include "RandomMovementGenerator.h"
#include "Traveller.h"
#include "DestinationHolderImp.h"

#define RUNNING_CHANCE_RANDOMMV 20                                  //will be "1 / RUNNING_CHANCE_RANDOMMV"

template<>
bool
RandomMovementGenerator<Creature>::GetDestination(float &x, float &y, float &z) const
{
    if(i_destinationHolder.HasArrived())
        return false; 
    
    i_destinationHolder.GetDestination(x, y, z); 
    return true;
}

template<>
void
RandomMovementGenerator<Creature>::_setRandomLocation(Creature &creature)
{
    float i_x,i_y,i_z,n_x,n_y,n_z,ori,dist;
    creature.GetHomePosition(i_x,i_y,i_z,ori);

    const float angle = 2*M_PI*rand_norm();
	const float range = rand_norm()*wander_dist;
	const float distX = range*cos(angle);
    const float distY = range*sin(angle);

    n_x = i_x + distX;
    n_y = i_y + distY;

    Trinity::NormalizeMapCoord(n_x);
    Trinity::NormalizeMapCoord(n_y);

    Map const* map = MapManager::Instance().GetBaseMap(creature.GetMapId());

    switch(_InhabitType)
    {
    case INHABIT_AIR:
    {
        //don't use normalized n_x, n_y because difference is too small.. and this is random movement
        dist = sqrtf(distX*distX + distY*distY);
        const float distanceZ = rand_norm() * dist/2; // Limit height change
        n_z = i_z + distanceZ;
        float tz = map->GetHeight(n_x,n_y,n_z - 2.0f,false);
        if (tz >= n_z || ground >= n_z)
            return;
        //creature.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);
        break;
    }
    case INHABIT_WATER:
    {
        //some small creatures can swim above water level
        float water = map->GetWaterLevel(n_x,n_y) - 1.8f;
        float floor = map->GetHeight(n_x,n_y,i_z,false) + 0.2f;
        if (water - floor < 0)
            return;
        float z_diff = 2 * 1.192*creature.GetDistance2d(n_x,n_y);	//1.192 = tan(50)
        //if(water - floor > z_diff){
        n_z = z_diff*(1 - 2*rand_norm()) + creature.GetPositionZ();
        n_z = n_z > water ? water : n_z;
        n_z = n_z < floor ? floor : n_z;
        //}else
        //n_z =  floor + rand_norm()*(water - floor);
        //creature.AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
        break;
    } 
    case INHABIT_GROUND:
	{
        dist = (distX*distX + distY*distY);
        dist = dist>=100.0f ? 10.0f : sqrtf(dist); // 10.0 is the max that vmap high can check (MAX_CAN_FALL_DISTANCE)
        n_z = map->GetHeight(n_x,n_y,i_z,false);
        if (fabs(n_z - i_z) > dist)
        {
            n_z = map->GetHeight(n_x,n_y,i_z,true); // Vmap Horizontal or above
            if (fabs(n_z - i_z) > dist)
            {
                n_z = map->GetHeight(n_x,n_y,i_z + 8.0f,true); // Vmap Higher
                if (fabs(n_z - i_z) > dist)
                    return;
            }
        }
        if (!irand(0,RUNNING_CHANCE_RANDOMMV))
            creature.RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        else
            creature.AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        break;
    }
    default:
        n_z = i_z;
        break;
    }

    Traveller<Creature> traveller(creature);
    creature.SetOrientation(creature.GetAngle(n_x,n_y));
    i_destinationHolder.SetDestination(traveller,n_x,n_y,n_z);
    creature.addUnitState(UNIT_STAT_ROAMING);

	switch(_InhabitType)
	{
	case INHABIT_AIR:
		i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime());
		break;
	case INHABIT_WATER:
		i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime() + urand(500,3000));
		break;
	default:
		i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime() + urand(500,5000));
		break;
	}
}

template<>
void
RandomMovementGenerator<Creature>::Initialize(Creature &creature)
{
    if(!creature.isAlive())
        return;

    wander_dist = creature.GetRespawnRadius();
	Map const* map = MapManager::Instance().GetBaseMap(creature.GetMapId());

    _InhabitType = creature.GetCreatureInfo()->InhabitType;

	// Let's select only one movement type
	// TODO: make this check more correct
	float water;
	if(_InhabitType & (INHABIT_WATER | INHABIT_AIR))
		water = map->GetWaterLevel(creature.GetPositionX(),creature.GetPositionY());
	if(_InhabitType & INHABIT_AIR)
	{
		float floor = map->GetHeight(creature.GetPositionX(),creature.GetPositionY(),creature.GetPositionZ(),true);
		ground = floor > water ? floor : water;
		if(ground + 2.0f < creature.GetPositionZ())
		{
			_InhabitType = INHABIT_AIR;
			creature.addUnitState(UNIT_STAT_IN_FLIGHT);
			creature.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);
			i_nextMoveTime.Reset(urand(0,1000));	//to make them call _setRandomLocation not in one time
			//_setRandomLocation(creature);
			return;
		}else
			_InhabitType &= ~INHABIT_AIR;
	}
	if(_InhabitType & INHABIT_WATER)
	{
		if (water > creature.GetPositionZ()) //don't use "+2.0f" because under-water creatures already has height <= -1.9(if water level is 0)
		{
			_InhabitType = INHABIT_WATER;
			creature.addUnitState(UNIT_STAT_IN_FLIGHT);
			creature.AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
			i_nextMoveTime.Reset(urand(0,1000));
			//_setRandomLocation(creature);
			return;
		}else
			_InhabitType &= ~INHABIT_WATER;
	}
	if(_InhabitType & INHABIT_GROUND)
		i_nextMoveTime.Reset(urand(0,1000));
		//_setRandomLocation(creature);
}

template<>
void
RandomMovementGenerator<Creature>::Reset(Creature &creature)
{
    Initialize(creature);
}

template<>
void
RandomMovementGenerator<Creature>::Finalize(Creature &creature){}

template<>
bool
RandomMovementGenerator<Creature>::Update(Creature &creature, const uint32 &diff)
{
    if(creature.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED))
    {
        i_nextMoveTime.Update(i_nextMoveTime.GetExpiry());    // Expire the timer
        creature.clearUnitState(UNIT_STAT_ROAMING);
        return true;
    }

    i_nextMoveTime.Update(diff);

    if(i_destinationHolder.HasArrived() && !creature.IsStopped() && !(_InhabitType & (INHABIT_WATER | INHABIT_AIR)))
        creature.clearUnitState(UNIT_STAT_ROAMING);

    if(!i_destinationHolder.HasArrived() && creature.IsStopped())
        creature.addUnitState(UNIT_STAT_ROAMING);

    CreatureTraveller traveller(creature);

    if( i_destinationHolder.UpdateTraveller(traveller, diff, false, true) )
    {
        if(i_nextMoveTime.Passed())                               
            _setRandomLocation(creature);
        else if(creature.isPet() && creature.GetOwner() && creature.GetDistance(creature.GetOwner()) > PET_FOLLOW_DIST+2.5f)
        {
           creature.SetUnitMovementFlags(MOVEMENTFLAG_NONE);
           _setRandomLocation(creature);
        }
    }
    return true;
}
