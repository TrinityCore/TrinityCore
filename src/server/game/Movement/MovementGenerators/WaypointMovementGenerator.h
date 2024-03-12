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

#ifndef TRINITY_WAYPOINTMOVEMENTGENERATOR_H
#define TRINITY_WAYPOINTMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "PathMovementBase.h"
#include "Timer.h"

class Creature;
class Unit;
struct WaypointPath;

template<class T>
class WaypointMovementGenerator;

template<>
class WaypointMovementGenerator<Creature> : public MovementGeneratorMedium<Creature, WaypointMovementGenerator<Creature>>,
    public PathMovementBase<Creature, WaypointPath const*>
{
    public:
        explicit WaypointMovementGenerator(uint32 pathId, bool repeating, Optional<Milliseconds> duration = {}, Optional<float> speed = {},
            MovementWalkRunSpeedSelectionMode speedSelectionMode = MovementWalkRunSpeedSelectionMode::Default,
            Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd = {}, Optional<float> wanderDistanceAtPathEnds = {},
            bool followPathBackwardsFromEndToStart = false, bool generatePath = true);
        explicit WaypointMovementGenerator(WaypointPath const& path, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
            MovementWalkRunSpeedSelectionMode speedSelectionMode,
            Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd, Optional<float> wanderDistanceAtPathEnds,
            bool followPathBackwardsFromEndToStart, bool generatePath);
        ~WaypointMovementGenerator();

        MovementGeneratorType GetMovementGeneratorType() const override;

        void UnitSpeedChanged() override { AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }
        void Pause(uint32 timer) override;
        void Resume(uint32 overrideTimer) override;
        bool GetResetPosition(Unit*, float& x, float& y, float& z) override;

        void DoInitialize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, uint32);
        void DoDeactivate(Creature*);
        void DoFinalize(Creature*, bool, bool);

        std::string GetDebugInfo() const override;

    private:
        void MovementInform(Creature*);
        void OnArrived(Creature*);
        void StartMove(Creature*, bool relaunch = false);
        bool ComputeNextNode();
        bool UpdateTimer(uint32 diff)
        {
            _nextMoveTime.Update(diff);
            if (_nextMoveTime.Passed())
            {
                _nextMoveTime.Reset(0);
                return true;
            }
            return false;
        }

        TimeTracker _nextMoveTime;
        uint32 _pathId;
        bool _repeating;
        bool _loadedFromDB;

        Optional<TimeTracker> _duration;
        Optional<float> _speed;
        MovementWalkRunSpeedSelectionMode _speedSelectionMode;
        Optional<std::pair<Milliseconds, Milliseconds>> _waitTimeRangeAtPathEnd;
        Optional<float> _wanderDistanceAtPathEnds;
        bool _followPathBackwardsFromEndToStart;
        bool _isReturningToStart;
        bool _generatePath;
};

#endif
