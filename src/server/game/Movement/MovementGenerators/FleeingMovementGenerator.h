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

#ifndef TRINITY_FLEEINGMOVEMENTGENERATOR_H
#define TRINITY_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "ObjectGuid.h"
#include "Timer.h"

class Creature;
class PathGenerator;
struct Position;

template<class T>
class FleeingMovementGenerator : public MovementGeneratorMedium<T, FleeingMovementGenerator<T>>
{
    public:
        explicit FleeingMovementGenerator(ObjectGuid fleeTargetGUID);

        MovementGeneratorType GetMovementGeneratorType() const override;

        void DoInitialize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);
        void DoDeactivate(T*);
        void DoFinalize(T*, bool, bool);

        void UnitSpeedChanged() override { FleeingMovementGenerator<T>::AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

    private:
        void SetTargetLocation(T*);
        void GetPoint(T*, Position& position);

        std::unique_ptr<PathGenerator> _path;
        ObjectGuid _fleeTargetGUID;
        TimeTracker _timer;
};

class TimedFleeingMovementGenerator : public FleeingMovementGenerator<Creature>
{
    public:
        explicit TimedFleeingMovementGenerator(ObjectGuid fleeTargetGUID, uint32 time) : FleeingMovementGenerator<Creature>(fleeTargetGUID), _totalFleeTime(time) { }

        bool Update(Unit*, uint32) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override;

    private:
        TimeTracker _totalFleeTime;
};

#endif
