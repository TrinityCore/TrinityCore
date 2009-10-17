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
#ifndef TRINITY_CONFUSEDGENERATOR_H
#define TRINITY_CONFUSEDGENERATOR_H
#include "MovementGenerator.h"
#include "DestinationHolder.h"
#include "Traveller.h"
#define MAX_CONF_WAYPOINTS 24
template<class T>
class TRINITY_DLL_SPEC ConfusedMovementGenerator
: public MovementGeneratorMedium< T, ConfusedMovementGenerator<T> >
{
    public:
        explicit ConfusedMovementGenerator() : i_nextMoveTime(0) {}
        void Initialize(T &);
        void Finalize(T &);
        void Reset(T &);
        bool Update(T &, const uint32 &);
        bool GetDestination(float &x, float &y, float &z) const
        {
            if(i_destinationHolder.HasArrived()) return false;
            i_destinationHolder.GetDestination(x,y,z);
            return true;
        }
        MovementGeneratorType GetMovementGeneratorType() { return CONFUSED_MOTION_TYPE; }
    private:
        void _InitSpecific(T &, bool &, bool &);
        TimeTracker i_nextMoveTime;
        float i_waypoints[MAX_CONF_WAYPOINTS+1][3];
        DestinationHolder< Traveller<T> > i_destinationHolder;
        uint32 i_nextMove;
};
#endif

