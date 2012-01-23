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
#include "MapManager.h"
#include "ConfusedMovementGenerator.h"
#include "VMapFactory.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"

#ifdef MAP_BASED_RAND_GEN
#define rand_norm() unit.rand_norm()
#define urand(a, b) unit.urand(a, b)
#endif

template<class T>
void ConfusedMovementGenerator<T>::Initialize(T &unit)
{
    const float wander_distance=4;
    float x,y,z;
    x = unit.GetPositionX();
    y = unit.GetPositionY();
    z = unit.GetPositionZ();

    Map const* map = unit.GetBaseMap();

    i_nextMove = 1;

    bool is_water_ok, is_land_ok;
    _InitSpecific(unit, is_water_ok, is_land_ok);

    for (uint8 idx = 0; idx < MAX_CONF_WAYPOINTS + 1; ++idx)
    {
        const float wanderX=wander_distance*(float)rand_norm() - wander_distance/2;
        const float wanderY=wander_distance*(float)rand_norm() - wander_distance/2;

        i_waypoints[idx][0] = x + wanderX;
        i_waypoints[idx][1] = y + wanderY;

        // prevent invalid coordinates generation
        Trinity::NormalizeMapCoord(i_waypoints[idx][0]);
        Trinity::NormalizeMapCoord(i_waypoints[idx][1]);

        bool is_water = map->IsInWater(i_waypoints[idx][0],i_waypoints[idx][1],z);
        // if generated wrong path just ignore
        if ((is_water && !is_water_ok) || (!is_water && !is_land_ok))
        {
            i_waypoints[idx][0] = idx > 0 ? i_waypoints[idx-1][0] : x;
            i_waypoints[idx][1] = idx > 0 ? i_waypoints[idx-1][1] : y;
        }

        unit.UpdateAllowedPositionZ(i_waypoints[idx][0], i_waypoints[idx][1], z);
        i_waypoints[idx][2] =  z;
    }

    unit.StopMoving();
    unit.SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit.AddUnitState(UNIT_STAT_CONFUSED|UNIT_STAT_CONFUSED_MOVE);
}

template<>
void ConfusedMovementGenerator<Creature>::_InitSpecific(Creature &creature, bool &is_water_ok, bool &is_land_ok)
{
    is_water_ok = creature.canSwim();
    is_land_ok  = creature.canWalk();
}

template<>
void ConfusedMovementGenerator<Player>::_InitSpecific(Player &, bool &is_water_ok, bool &is_land_ok)
{
    is_water_ok = true;
    is_land_ok  = true;
}

template<class T>
void ConfusedMovementGenerator<T>::Reset(T &unit)
{
    i_nextMove = 1;
    i_nextMoveTime.Reset(0);
    unit.StopMoving();
    unit.AddUnitState(UNIT_STAT_CONFUSED|UNIT_STAT_CONFUSED_MOVE);
}

template<class T>
bool ConfusedMovementGenerator<T>::Update(T &unit, const uint32 &diff)
{
    if (unit.HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED))
        return true;

    if (i_nextMoveTime.Passed())
    {
        // currently moving, update location
        unit.AddUnitState(UNIT_STAT_CONFUSED_MOVE);

        if (unit.movespline->Finalized())
        {
            i_nextMove = urand(1,MAX_CONF_WAYPOINTS);
            i_nextMoveTime.Reset(urand(0, 1500-1));     // TODO: check the minimum reset time, should be probably higher
        }
    }
    else
    {
        // waiting for next move
        i_nextMoveTime.Update(diff);
        if(i_nextMoveTime.Passed() )
        {
            // start moving
            unit.AddUnitState(UNIT_STAT_CONFUSED_MOVE);

            ASSERT( i_nextMove <= MAX_CONF_WAYPOINTS );
            float x = i_waypoints[i_nextMove][0];
            float y = i_waypoints[i_nextMove][1];
            float z = i_waypoints[i_nextMove][2];
            Movement::MoveSplineInit init(unit);
            init.MoveTo(x, y, z);
            init.SetWalk(true);
            init.Launch();
        }
    }

    return true;
}

template<>
void ConfusedMovementGenerator<Player>::Finalize(Player &unit)
{
    unit.RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit.ClearUnitState(UNIT_STAT_CONFUSED|UNIT_STAT_CONFUSED_MOVE);
}

template<>
void ConfusedMovementGenerator<Creature>::Finalize(Creature &unit)
{
    unit.RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
    unit.ClearUnitState(UNIT_STAT_CONFUSED|UNIT_STAT_CONFUSED_MOVE);
    if (unit.getVictim())
        unit.SetTarget(unit.getVictim()->GetGUID());
}

template void ConfusedMovementGenerator<Player>::Initialize(Player &player);
template void ConfusedMovementGenerator<Creature>::Initialize(Creature &creature);
template void ConfusedMovementGenerator<Player>::Reset(Player &player);
template void ConfusedMovementGenerator<Creature>::Reset(Creature &creature);
template bool ConfusedMovementGenerator<Player>::Update(Player &player, const uint32 &diff);
template bool ConfusedMovementGenerator<Creature>::Update(Creature &creature, const uint32 &diff);

