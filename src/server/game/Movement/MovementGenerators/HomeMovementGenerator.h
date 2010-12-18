/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_HOMEMOVEMENTGENERATOR_H
#define TRINITY_HOMEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "DestinationHolder.h"
#include "Traveller.h"

class Creature;

template < class T >
class HomeMovementGenerator;

template <>
class HomeMovementGenerator<Creature>
: public MovementGeneratorMedium< Creature, HomeMovementGenerator<Creature> >
{
    public:

        HomeMovementGenerator() {}
        ~HomeMovementGenerator() {}

        void Initialize(Creature &);
        void Finalize(Creature &);
        void Reset(Creature &);
        bool Update(Creature &, const uint32 &);
        void modifyTravelTime(uint32 travel_time) { i_travel_timer = travel_time; }
        MovementGeneratorType GetMovementGeneratorType() { return HOME_MOTION_TYPE; }

        bool GetDestination(float& x, float& y, float& z) const { i_destinationHolder.GetDestination(x,y,z); return true; }

    private:
        void _setTargetLocation(Creature &);
        DestinationHolder< Traveller<Creature> > i_destinationHolder;

        float ori;
        uint32 i_travel_timer;
};
#endif


