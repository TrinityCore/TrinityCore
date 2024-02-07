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

#ifndef TRINITY_CYCLICMOVEMENTGENERATOR_H
#define TRINITY_CYCLICMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "Timer.h"
#include "Optional.h"

enum MovementGeneratorType : uint8;

class Creature;
struct WaypointPath;

template<class T>
class CyclicMovementGenerator;

template<>
class CyclicMovementGenerator<Creature> : public MovementGeneratorMedium<Creature, CyclicMovementGenerator<Creature>>
{
    public:
        explicit CyclicMovementGenerator(WaypointPath const* path, bool enforceFly = false,
            Optional<Milliseconds> duration = {}, Optional<float> speed = {},
            MovementWalkRunSpeedSelectionMode speedSelectionMode = MovementWalkRunSpeedSelectionMode::Default,
            Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult = {});
        explicit CyclicMovementGenerator();

        void DoInitialize(Creature* owner);
        void DoDeactivate(Creature* owner);
        void DoFinalize(Creature* owner, bool active, bool movementInform);
        void DoReset(Creature* owner);
        bool DoUpdate(Creature* owner, uint32 diff);

        MovementGeneratorType GetMovementGeneratorType() const override { return CYCLIC_SPLINE_MOTION_TYPE; }
        void Pause(uint32 timer = 0) override;
        void Resume(uint32 overrideTimer = 0) override;

    private:
        void StartMovement(Creature* owner);

        WaypointPath const* _path;
        TimeTracker _nextMoveTime;
        bool _enforceFly;
        Optional<float> _velocity;
        Optional<TimeTracker> _duration;
        MovementWalkRunSpeedSelectionMode _speedSelectionMode;
        Optional<Scripting::v2::ActionResultSetter<MovementStopReason>> ScriptResult;
};

#endif // TRINITY_CYCLICMOVEMENTGENERATOR_H
