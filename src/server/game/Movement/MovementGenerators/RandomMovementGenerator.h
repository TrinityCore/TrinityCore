/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Position.h"
#include "Timer.h"

class PathGenerator;

template<class T>
class RandomMovementGenerator : public MovementGeneratorMedium< T, RandomMovementGenerator<T> >
{
    public:
        explicit RandomMovementGenerator(float distance = 0.0f) : _timer(0), _reference(), _wanderDistance(distance), _interrupt(false) { }
        ~RandomMovementGenerator();

        MovementGeneratorType GetMovementGeneratorType() const override;
        void UnitSpeedChanged() override { } //TODO

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

    private:
        void SetRandomLocation(T*);

        std::unique_ptr<PathGenerator> _path;
        TimeTracker _timer;
        Position _reference;
        float _wanderDistance;
        bool _interrupt;
};

#endif
