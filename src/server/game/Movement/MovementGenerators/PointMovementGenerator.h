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

#ifndef TRINITY_POINTMOVEMENTGENERATOR_H
#define TRINITY_POINTMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "DestinationHolder.h"
#include "Traveller.h"
#include "FollowerReference.h"

template<class T>
class PointMovementGenerator
: public MovementGeneratorMedium< T, PointMovementGenerator<T> >
{
    public:
        PointMovementGenerator(uint32 _id, float _x, float _y, float _z) : id(_id),
            i_x(_x), i_y(_y), i_z(_z), i_nextMoveTime(0), arrived(false) {}

        void Initialize(T &);
        void Finalize(T &unit);
        void Reset(T &unit){unit.StopMoving();}
        bool Update(T &, const uint32 &diff);

        void MovementInform(T &);

        MovementGeneratorType GetMovementGeneratorType() { return POINT_MOTION_TYPE; }

        bool GetDestination(float& x, float& y, float& z) const { x=i_x; y=i_y; z=i_z; return true; }
    private:
        uint32 id;
        float i_x, i_y, i_z;
        TimeTracker i_nextMoveTime;
        DestinationHolder< Traveller<T> > i_destinationHolder;
        bool arrived;
};

class AssistanceMovementGenerator
: public PointMovementGenerator<Creature>
{
    public:
        AssistanceMovementGenerator(float _x, float _y, float _z) :
            PointMovementGenerator<Creature>(0, _x, _y, _z) {}

        MovementGeneratorType GetMovementGeneratorType() { return ASSISTANCE_MOTION_TYPE; }
        void Finalize(Unit &);
};

#endif

