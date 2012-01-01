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

#ifndef TRINITY_DESTINATIONHOLDERIMP_H
#define TRINITY_DESTINATIONHOLDERIMP_H

#include "MapManager.h"
#include "DestinationHolder.h"

#include <cmath>

template<typename TRAVELLER>
void
DestinationHolder<TRAVELLER>::_findOffSetPoint(float x1, float y1, float x2, float y2, float offset, float &x, float &y)
{
    /* given the point (x1, y1) and (x2, y2).. need to find the point (x, y) on the same line
     * such that the distance from (x, y) to (x2, y2) is offset.
     * Let the distance of p1 to p2 = d.. then the ratio of offset/d = (x2-x)/(x2-x1)
     * hence x = x2 - (offset/d)*(x2-x1)
     * like wise offset/d = (y2-y)/(y2-y1);
     */
    if (offset == 0)
    {
        x = x2;
        y = y2;
    }
    else
    {
        double x_diff = double(x2 - x1);
        double y_diff = double(y2 - y1);
        double distance_d = (double)((x_diff*x_diff) + (y_diff * y_diff));
        if (distance_d == 0)
        {
            x = x2;
            y = y2;
        }
        else
        {
            distance_d = ::sqrt(distance_d);                // starting distance
            double distance_ratio = (double)(distance_d - offset)/(double)distance_d;
            // line above has revised formula which is more correct, I think
            x = (float)(x1 + (distance_ratio*x_diff));
            y = (float)(y1 + (distance_ratio*y_diff));
        }
    }
}

template<typename TRAVELLER>
uint32
DestinationHolder<TRAVELLER>::SetDestination(TRAVELLER &traveller, float dest_x, float dest_y, float dest_z, bool sendMove)
{
    i_destSet = true;
    i_destX = dest_x;
    i_destY = dest_y;
    i_destZ = dest_z;

    return StartTravel(traveller, sendMove);
}

template<typename TRAVELLER>
uint32
DestinationHolder<TRAVELLER>::StartTravel(TRAVELLER &traveller, bool sendMove)
{
    if (!i_destSet) return 0;

    i_fromX = traveller.GetPositionX();
    i_fromY = traveller.GetPositionY();
    i_fromZ = traveller.GetPositionZ();

    i_totalTravelTime = traveller.GetTotalTrevelTimeTo(i_destX, i_destY, i_destZ);
    i_timeElapsed = 0;
    if (sendMove)
        traveller.MoveTo(i_destX, i_destY, i_destZ, i_totalTravelTime);
    return i_totalTravelTime;
}

template<typename TRAVELLER>
bool
DestinationHolder<TRAVELLER>::UpdateTraveller(TRAVELLER &traveller, uint32 diff, bool micro_movement)
{
    i_timeElapsed += diff;

    // Update every TRAVELLER_UPDATE_INTERVAL
    i_tracker.Update(diff);
    if (!i_tracker.Passed())
        return false;
    else
        ResetUpdate();

    if (!i_destSet) return true;

    float x, y, z;
    if (!micro_movement)
        GetLocationNowNoMicroMovement(x, y, z);
    else
    {
        if (!traveller.GetTraveller().HasUnitState(UNIT_STAT_MOVING | UNIT_STAT_IN_FLIGHT))
            return true;

        if (traveller.GetTraveller().HasUnitState(UNIT_STAT_IN_FLIGHT))
            GetLocationNow(traveller.GetTraveller().GetBaseMap(), x, y, z, true);                  // Should reposition Object with right Coord, so I can bypass some Grid Relocation
        else
            GetLocationNow(traveller.GetTraveller().GetBaseMap(), x, y, z, false);

        // Change movement computation to micro movement based on last tick coords, this makes system work
        // even on multiple floors zones without hugh vmaps usage ;)

        // Take care of underrun of uint32
        if (i_totalTravelTime >= i_timeElapsed)
            i_totalTravelTime -= i_timeElapsed;     // Consider only the remaining part
        else
            i_totalTravelTime = 0;

        i_timeElapsed = 0;
        i_fromX = x;                            // and change origine
        i_fromY = y;                            // then I take into account only micro movement
        i_fromZ = z;
    }

    if (traveller.GetTraveller().GetPositionX() != x || traveller.GetTraveller().GetPositionY() != y || traveller.GetTraveller().GetPositionZ() != z)
    {
        float ori = traveller.GetTraveller().GetAngle(x, y);
        traveller.Relocation(x, y, z, ori);
    }

    return true;
}

template<typename TRAVELLER>
void
DestinationHolder<TRAVELLER>::GetLocationNow(const Map* map, float &x, float &y, float &z, bool is3D) const
{
    if (HasArrived())
    {
        x = i_destX;
        y = i_destY;
        z = i_destZ;
    }
    else if (HasDestination())
    {
        double percent_passed = (double)i_timeElapsed / (double)i_totalTravelTime;
        const float distanceX = (float)((i_destX - i_fromX) * percent_passed);
        const float distanceY = (float)((i_destY - i_fromY) * percent_passed);
        const float distanceZ = (float)((i_destZ - i_fromZ) * percent_passed);
        x = i_fromX + distanceX;
        y = i_fromY + distanceY;
        float z2 = i_fromZ + distanceZ;
        // All that is not finished but previous code neither... Traveller need be able to swim.
        if (is3D)
            z = z2;
        else
        {
            //That part is good for mob Walking on the floor. But the floor is not always what we thought.
            z = map->GetHeight(x, y, i_fromZ, false); // Disable cave check
            const float groundDist = sqrt(distanceX*distanceX + distanceY*distanceY);
            const float zDist = fabs(i_fromZ - z) + 0.000001f;
            const float slope = groundDist / zDist;
            if (slope < 1.0f)  // This prevents the ground returned by GetHeight to be used when in cave
                z = z2; // a climb or jump of more than 45 is denied
        }
    }
}

template<typename TRAVELLER>
float
DestinationHolder<TRAVELLER>::GetDistance3dFromDestSq(const WorldObject &obj) const
{
    float x, y, z;
    obj.GetPosition(x, y, z);
    return (i_destX-x)*(i_destX-x)+(i_destY-y)*(i_destY-y)+(i_destZ-z)*(i_destZ-z);
}

template<typename TRAVELLER>
float
DestinationHolder<TRAVELLER>::GetDestinationDiff(float x, float y, float z) const
{
    return sqrt(((x-i_destX)*(x-i_destX)) + ((y-i_destY)*(y-i_destY)) + ((z-i_destZ)*(z-i_destZ)));
}

template<typename TRAVELLER>
void
DestinationHolder<TRAVELLER>::GetLocationNowNoMicroMovement(float &x, float &y, float &z) const
{
    if (HasArrived())
    {
        x = i_destX;
        y = i_destY;
        z = i_destZ;
    }
    else
    {
        double percent_passed = (double)i_timeElapsed / (double)i_totalTravelTime;
        x = (float)(i_fromX + ((i_destX - i_fromX) * percent_passed));
        y = (float)(i_fromY + ((i_destY - i_fromY) * percent_passed));
        z = (float)(i_fromZ + ((i_destZ - i_fromZ) * percent_passed));
    }
}

#endif

