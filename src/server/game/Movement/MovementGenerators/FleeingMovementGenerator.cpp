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

#include "Creature.h"
#include "CreatureAI.h"
#include "MapManager.h"
#include "FleeingMovementGenerator.h"
#include "DestinationHolderImp.h"
#include "ObjectAccessor.h"

#define MIN_QUIET_DISTANCE 28.0f
#define MAX_QUIET_DISTANCE 43.0f

template<class T>
void
FleeingMovementGenerator<T>::_setTargetLocation(T &owner)
{
    if (!&owner)
        return;

    if (owner.HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED))
        return;

    if (!_setMoveData(owner))
        return;

    float x, y, z;
    if (!_getPoint(owner, x, y, z))
        return;

    owner.AddUnitState(UNIT_STAT_FLEEING | UNIT_STAT_ROAMING);
    Traveller<T> traveller(owner);
    i_destinationHolder.SetDestination(traveller, x, y, z);
}

template<>
bool FleeingMovementGenerator<Creature>::GetDestination(float &x, float &y, float &z) const
{
    if (i_destinationHolder.HasArrived())
        return false;

    i_destinationHolder.GetDestination(x, y, z);
    return true;
}

template<>
bool FleeingMovementGenerator<Player>::GetDestination(float & /*x*/, float & /*y*/, float & /*z*/) const
{
    return false;
}

template<class T>
bool
FleeingMovementGenerator<T>::_getPoint(T &owner, float &x, float &y, float &z)
{
    if (!&owner)
        return false;

    x = owner.GetPositionX();
    y = owner.GetPositionY();
    z = owner.GetPositionZ();

    float temp_x, temp_y, angle = 0;
    const Map* _map = owner.GetBaseMap();
    //primitive path-finding
    for (uint8 i = 0; i < 18; ++i)
    {
        if (i_only_forward && i > 2)
            break;

        float distance = 5.0f;

        switch (i)
        {
            case 0:
                angle = i_cur_angle;
                break;
            case 1:
                angle = i_cur_angle;
                distance /= 2;
                break;
            case 2:
                angle = i_cur_angle;
                distance /= 4;
                break;
            case 3:
                angle = i_cur_angle + static_cast<float>(M_PI/4);
                break;
            case 4:
                angle = i_cur_angle - static_cast<float>(M_PI/4);
                break;
            case 5:
                angle = i_cur_angle + static_cast<float>(M_PI/4);
                distance /= 2;
                break;
            case 6:
                angle = i_cur_angle - static_cast<float>(M_PI/4);
                distance /= 2;
                break;
            case 7:
                angle = i_cur_angle + static_cast<float>(M_PI/2);
                break;
            case 8:
                angle = i_cur_angle - static_cast<float>(M_PI/2);
                break;
            case 9:
                angle = i_cur_angle + static_cast<float>(M_PI/2);
                distance /= 2;
                break;
            case 10:
                angle = i_cur_angle - static_cast<float>(M_PI/2);
                distance /= 2;
                break;
            case 11:
                angle = i_cur_angle + static_cast<float>(M_PI/4);
                distance /= 4;
                break;
            case 12:
                angle = i_cur_angle - static_cast<float>(M_PI/4);
                distance /= 4;
                break;
            case 13:
                angle = i_cur_angle + static_cast<float>(M_PI/2);
                distance /= 4;
                break;
            case 14:
                angle = i_cur_angle - static_cast<float>(M_PI/2);
                distance /= 4;
                break;
            case 15:
                angle = i_cur_angle + static_cast<float>(M_PI*3/4);
                distance /= 2;
                break;
            case 16:
                angle = i_cur_angle - static_cast<float>(M_PI*3/4);
                distance /= 2;
                break;
            case 17:
                angle = i_cur_angle + static_cast<float>(M_PI);
                distance /= 2;
                break;
        }
        temp_x = x + distance * cos(angle);
        temp_y = y + distance * sin(angle);
        Trinity::NormalizeMapCoord(temp_x);
        Trinity::NormalizeMapCoord(temp_y);
        if (owner.IsWithinLOS(temp_x, temp_y, z))
        {
            bool is_water_now = _map->IsInWater(x, y, z);

            if (is_water_now && _map->IsInWater(temp_x, temp_y, z))
            {
                x = temp_x;
                y = temp_y;
                return true;
            }
            float new_z = _map->GetHeight(temp_x, temp_y, z, true);

            if (new_z <= INVALID_HEIGHT)
                continue;

            bool is_water_next = _map->IsInWater(temp_x, temp_y, new_z);

            if ((is_water_now && !is_water_next && !is_land_ok) || (!is_water_now && is_water_next && !is_water_ok))
                continue;

            if (!(new_z - z) || distance / fabs(new_z - z) > 1.0f)
            {
                float new_z_left = _map->GetHeight(temp_x + (float)(cos(angle+M_PI/2)), temp_y + (float)(sin(angle+M_PI/2)), z, true);
                float new_z_right = _map->GetHeight(temp_x + (float)(cos(angle-M_PI/2)), temp_y + (float)(sin(angle-M_PI/2)), z, true);
                if (fabs(new_z_left - new_z) < 1.2f && fabs(new_z_right - new_z) < 1.2f)
                {
                    x = temp_x;
                    y = temp_y;
                    z = new_z;
                    return true;
                }
            }
        }
    }
    i_to_distance_from_caster = 0.0f;
    i_nextCheckTime.Reset(urand(500, 1000));
    return false;
}

template<class T>
bool
FleeingMovementGenerator<T>::_setMoveData(T &owner)
{
    float cur_dist_xyz = owner.GetDistance(i_caster_x, i_caster_y, i_caster_z);

    if (i_to_distance_from_caster > 0.0f)
    {
        if ((i_last_distance_from_caster > i_to_distance_from_caster && cur_dist_xyz < i_to_distance_from_caster)   ||
                                                            // if we reach lower distance
           (i_last_distance_from_caster > i_to_distance_from_caster && cur_dist_xyz > i_last_distance_from_caster) ||
                                                            // if we can't be close
           (i_last_distance_from_caster < i_to_distance_from_caster && cur_dist_xyz > i_to_distance_from_caster)   ||
                                                            // if we reach bigger distance
           (cur_dist_xyz > MAX_QUIET_DISTANCE) ||           // if we are too far
           (i_last_distance_from_caster > MIN_QUIET_DISTANCE && cur_dist_xyz < MIN_QUIET_DISTANCE))
                                                            // if we leave 'quiet zone'
        {
            // we are very far or too close, stopping
            i_to_distance_from_caster = 0.0f;
            i_nextCheckTime.Reset(urand(500, 1000));
            return false;
        }
        else
        {
            // now we are running, continue
            i_last_distance_from_caster = cur_dist_xyz;
            return true;
        }
    }

    float cur_dist;
    float angle_to_caster;

    Unit* fright = ObjectAccessor::GetUnit(owner, i_frightGUID);

    if (fright)
    {
        cur_dist = fright->GetDistance(&owner);
        if (cur_dist < cur_dist_xyz)
        {
            i_caster_x = fright->GetPositionX();
            i_caster_y = fright->GetPositionY();
            i_caster_z = fright->GetPositionZ();
            angle_to_caster = fright->GetAngle(&owner);
        }
        else
        {
            cur_dist = cur_dist_xyz;
            angle_to_caster = owner.GetAngle(i_caster_x, i_caster_y) + static_cast<float>(M_PI);
        }
    }
    else
    {
        cur_dist = cur_dist_xyz;
        angle_to_caster = owner.GetAngle(i_caster_x, i_caster_y) + static_cast<float>(M_PI);
    }

    // if we too close may use 'path-finding' else just stop
    i_only_forward = cur_dist >= MIN_QUIET_DISTANCE/3;

    //get angle and 'distance from caster' to run
    float angle;

    if (i_cur_angle == 0.0f && i_last_distance_from_caster == 0.0f) //just started, first time
    {
        angle = (float)rand_norm()*(1.0f - cur_dist/MIN_QUIET_DISTANCE) * static_cast<float>(M_PI/3) + (float)rand_norm()*static_cast<float>(M_PI*2/3);
        i_to_distance_from_caster = MIN_QUIET_DISTANCE;
        i_only_forward = true;
    }
    else if (cur_dist < MIN_QUIET_DISTANCE)
    {
        angle = static_cast<float>(M_PI/6) + (float)rand_norm()*static_cast<float>(M_PI*2/3);
        i_to_distance_from_caster = cur_dist*2/3 + (float)rand_norm()*(MIN_QUIET_DISTANCE - cur_dist*2/3);
    }
    else if (cur_dist > MAX_QUIET_DISTANCE)
    {
        angle = (float)rand_norm()*static_cast<float>(M_PI/3) + static_cast<float>(M_PI*2/3);
        i_to_distance_from_caster = MIN_QUIET_DISTANCE + 2.5f + (float)rand_norm()*(MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE - 2.5f);
    }
    else
    {
        angle = (float)rand_norm()*static_cast<float>(M_PI);
        i_to_distance_from_caster = MIN_QUIET_DISTANCE + 2.5f + (float)rand_norm()*(MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE - 2.5f);
    }

    int8 sign = rand_norm() > 0.5f ? 1 : -1;
    i_cur_angle = sign*angle + angle_to_caster;

    // current distance
    i_last_distance_from_caster = cur_dist;

    return true;
}

template<class T>
void
FleeingMovementGenerator<T>::Initialize(T &owner)
{
    if (!&owner)
        return;

    _Init(owner);
    owner.CastStop();
    owner.AddUnitState(UNIT_STAT_FLEEING | UNIT_STAT_ROAMING);
    owner.SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner.SetTarget(0);
    owner.RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

    if (Unit* fright = ObjectAccessor::GetUnit(owner, i_frightGUID))
    {
        i_caster_x = fright->GetPositionX();
        i_caster_y = fright->GetPositionY();
        i_caster_z = fright->GetPositionZ();
    }
    else
    {
        i_caster_x = owner.GetPositionX();
        i_caster_y = owner.GetPositionY();
        i_caster_z = owner.GetPositionZ();
    }

    i_only_forward = true;
    i_cur_angle = 0.0f;
    i_last_distance_from_caster = 0.0f;
    i_to_distance_from_caster = 0.0f;
    _setTargetLocation(owner);
}

template<>
void
FleeingMovementGenerator<Creature>::_Init(Creature &owner)
{
    if (!&owner)
        return;

    is_water_ok = owner.canSwim();
    is_land_ok  = owner.canWalk();
}

template<>
void
FleeingMovementGenerator<Player>::_Init(Player &)
{
    is_water_ok = true;
    is_land_ok  = true;
}

template<class T>
void
FleeingMovementGenerator<T>::Finalize(T &owner)
{
    owner.RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner.ClearUnitState(UNIT_STAT_FLEEING | UNIT_STAT_ROAMING);
    if (owner.GetTypeId() == TYPEID_UNIT && owner.getVictim())
        owner.SetTarget(owner.getVictim()->GetGUID());
}

template<class T>
void
FleeingMovementGenerator<T>::Reset(T &owner)
{
    Initialize(owner);
}

template<class T>
bool
FleeingMovementGenerator<T>::Update(T &owner, const uint32 time_diff)
{
    if (!&owner || !owner.isAlive())
        return false;
    if (owner.HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED))
        return true;

    Traveller<T> traveller(owner);

    i_nextCheckTime.Update(time_diff);

    if ((owner.IsStopped() && !i_destinationHolder.HasArrived()) || !i_destinationHolder.HasDestination())
    {
        _setTargetLocation(owner);
        return true;
    }

    if (i_destinationHolder.UpdateTraveller(traveller, time_diff))
    {
        i_destinationHolder.ResetUpdate(50);
        if (i_nextCheckTime.Passed() && i_destinationHolder.HasArrived())
        {
            _setTargetLocation(owner);
            return true;
        }
    }
    return true;
}

template void FleeingMovementGenerator<Player>::Initialize(Player &);
template void FleeingMovementGenerator<Creature>::Initialize(Creature &);
template bool FleeingMovementGenerator<Player>::_setMoveData(Player &);
template bool FleeingMovementGenerator<Creature>::_setMoveData(Creature &);
template bool FleeingMovementGenerator<Player>::_getPoint(Player &, float &, float &, float &);
template bool FleeingMovementGenerator<Creature>::_getPoint(Creature &, float &, float &, float &);
template void FleeingMovementGenerator<Player>::_setTargetLocation(Player &);
template void FleeingMovementGenerator<Creature>::_setTargetLocation(Creature &);
template void FleeingMovementGenerator<Player>::Finalize(Player &);
template void FleeingMovementGenerator<Creature>::Finalize(Creature &);
template void FleeingMovementGenerator<Player>::Reset(Player &);
template void FleeingMovementGenerator<Creature>::Reset(Creature &);
template bool FleeingMovementGenerator<Player>::Update(Player &, const uint32);
template bool FleeingMovementGenerator<Creature>::Update(Creature &, const uint32);

void TimedFleeingMovementGenerator::Finalize(Unit &owner)
{
    owner.RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner.ClearUnitState(UNIT_STAT_FLEEING | UNIT_STAT_ROAMING);
    if (Unit* victim = owner.getVictim())
    {
        if (owner.isAlive())
        {
            owner.AttackStop();
            owner.ToCreature()->AI()->AttackStart(victim);
        }
    }
}

bool TimedFleeingMovementGenerator::Update(Unit & owner, const uint32 time_diff)
{
    if (!owner.isAlive())
        return false;

    if (owner.HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED))
        return true;

    i_totalFleeTime.Update(time_diff);
    if (i_totalFleeTime.Passed())
        return false;

    // This calls grant-parent Update method hiden by FleeingMovementGenerator::Update(Creature &, const uint32) version
    // This is done instead of casting Unit& to Creature& and call parent method, then we can use Unit directly
    return MovementGeneratorMedium< Creature, FleeingMovementGenerator<Creature> >::Update(owner, time_diff);
}

