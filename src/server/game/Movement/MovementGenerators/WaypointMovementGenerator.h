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
#include "WaypointDefines.h"
#include <variant>

class Creature;
class Unit;

template<class T>
class WaypointMovementGenerator;

template<>
class WaypointMovementGenerator<Creature> : public MovementGeneratorMedium<Creature, WaypointMovementGenerator<Creature>>,
    public PathMovementBase<Creature, std::variant<WaypointPath const*, std::unique_ptr<WaypointPath>>>
{
    public:
        explicit WaypointMovementGenerator(uint32 pathId, bool repeating, Optional<Milliseconds> duration = {}, Optional<float> speed = {},
            MovementWalkRunSpeedSelectionMode speedSelectionMode = MovementWalkRunSpeedSelectionMode::Default,
            Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd = {}, Optional<float> wanderDistanceAtPathEnds = {},
            Optional<bool> followPathBackwardsFromEndToStart = {}, Optional<bool> exactSplinePath = {}, bool generatePath = true,
            Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult = {});
        explicit WaypointMovementGenerator(WaypointPath const& path, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
            MovementWalkRunSpeedSelectionMode speedSelectionMode,
            Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd, Optional<float> wanderDistanceAtPathEnds,
            Optional<bool> followPathBackwardsFromEndToStart, Optional<bool> exactSplinePath, bool generatePath,
            Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult = {});
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

        WaypointPath const* GetPath() const { return std::visit([](auto&& path) -> WaypointPath const* { return std::addressof(*path); }, _path); }

        std::string GetDebugInfo() const override;

    private:
        void MovementInform(Creature const*) const;
        void OnArrived(Creature*);
        void StartMove(Creature*, bool relaunch = false);
        bool ComputeNextNode();
        bool UpdateMoveTimer(uint32 diff) { return UpdateTimer(_moveTimer, diff); }
        bool UpdateWaitTimer(uint32 diff) { return UpdateTimer(_nextMoveTime, diff); }
        static bool UpdateTimer(TimeTracker& timer, uint32 diff)
        {
            timer.Update(Milliseconds(diff));
            if (timer.Passed())
            {
                timer.Reset(0);
                return true;
            }
            return false;
        }

        bool IsFollowingPathBackwardsFromEndToStart() const;
        bool IsExactSplinePath() const;

        bool IsLoadedFromDB() const { return std::holds_alternative<WaypointPath const*>(_path); }

        uint32 _pathId;
        Optional<TimeTracker> _duration;
        Optional<float> _speed;
        MovementWalkRunSpeedSelectionMode _speedSelectionMode;
        Optional<std::pair<Milliseconds, Milliseconds>> _waitTimeRangeAtPathEnd;
        Optional<float> _wanderDistanceAtPathEnds;
        Optional<bool> _followPathBackwardsFromEndToStart;
        Optional<bool> _exactSplinePath;
        bool _repeating;
        bool _generatePath;

        TimeTracker _moveTimer;
        TimeTracker _nextMoveTime;
        std::vector<int32> _waypointTransitionSplinePoints;
        bool _isReturningToStart;
};

#endif
