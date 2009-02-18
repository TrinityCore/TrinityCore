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

#ifndef TRINITY_TARGETEDMOVEMENTGENERATOR_H
#define TRINITY_TARGETEDMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "DestinationHolder.h"
#include "Traveller.h"
#include "FollowerReference.h"

class TRINITY_DLL_SPEC TargetedMovementGeneratorBase
{
    public:
        TargetedMovementGeneratorBase(Unit &target) { i_target.link(&target, this); }
        void stopFollowing() { }
    protected:
        FollowerReference i_target;
};

template<class T>
class TRINITY_DLL_SPEC TargetedMovementGenerator
: public MovementGeneratorMedium< T, TargetedMovementGenerator<T> >, public TargetedMovementGeneratorBase
{
    public:

        TargetedMovementGenerator(Unit &target)
            : TargetedMovementGeneratorBase(target), i_offset(0), i_angle(0), i_recalculateTravel(false) {}
        TargetedMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorBase(target), i_offset(offset), i_angle(angle), i_recalculateTravel(false) {}
        ~TargetedMovementGenerator() {}

        void Initialize(T &);
        void Finalize(T &);
        void Reset(T &);
        bool Update(T &, const uint32 &);
        MovementGeneratorType GetMovementGeneratorType() { return TARGETED_MOTION_TYPE; }

        Unit* GetTarget() const;

        bool GetDestination(float &x, float &y, float &z) const
        {
            if(i_destinationHolder.HasArrived()) return false;
            i_destinationHolder.GetDestination(x,y,z);
            return true;
        }

        void unitSpeedChanged() { i_recalculateTravel=true; }
    private:

        void _setTargetLocation(T &);

        float i_offset;
        float i_angle;
        DestinationHolder< Traveller<T> > i_destinationHolder;
        bool i_recalculateTravel;
};
#endif

