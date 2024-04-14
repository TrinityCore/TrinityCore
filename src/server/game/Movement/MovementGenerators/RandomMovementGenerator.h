/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Optional.h"
#include "Position.h"
#include "Timer.h"

class PathGenerator;

template<class T>
class RandomMovementGenerator : public MovementGeneratorMedium<T, RandomMovementGenerator<T>>
{
    public:
        explicit RandomMovementGenerator(float distance = 0.0f, Optional<Milliseconds> duration = {},
            Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult = {});

        MovementGeneratorType GetMovementGeneratorType() const override;

        void Pause(uint32 timer) override;
        void Resume(uint32 overrideTimer) override;

        void DoInitialize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);
        void DoDeactivate(T*);
        void DoFinalize(T*, bool, bool);

        void UnitSpeedChanged() override { RandomMovementGenerator<T>::AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

    private:
        void SetRandomLocation(T*);

        std::unique_ptr<PathGenerator> _path;
        TimeTracker _timer;
        Optional<TimeTracker> _duration;
        Position _reference;
        float _wanderDistance;
        uint8 _wanderSteps;
};

#endif
