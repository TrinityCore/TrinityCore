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

#ifndef TRINITY_RANDOMMOTIONGENERATOR_H
#define TRINITY_RANDOMMOTIONGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class RandomMovementGenerator
: public MovementGeneratorMedium< T, RandomMovementGenerator<T> >
{
    public:
        RandomMovementGenerator(float spawnDist = 0.0f) : _nextMoveTime(0), _wanderDistance(spawnDist) {}

        void SetRandomLocation(T &);
        void Initialize(T &);
        void Finalize(T &);
        void Reset(T &);
        void Interrupt(T &);
        bool Update(T &, const uint32);
        bool GetResetPosition(T&, float& x, float& y, float& z);
        MovementGeneratorType GetMovementGeneratorType() { return RANDOM_MOTION_TYPE; }
    private:
        TimeTrackerSmall _nextMoveTime;

        uint32 _nextMove;
        float _wanderDistance;
};
#endif

