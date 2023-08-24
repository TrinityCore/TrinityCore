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
 
#ifndef TRINITY_CHASEMOVEMENTGENERATOR_H
#define TRINITY_CHASEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "AbstractPursuer.h"
#include "Optional.h"
#include "Timer.h"

class Unit;
enum ChaseMovementPositionCheckResult : uint8;
enum ChasePositionCheckOptions : uint8;

static constexpr uint32 CHASE_MOVEMENT_INTERVAL         = 400; // sniffed value (1 batch update cyclice)
static constexpr uint32 POSITION_CHECK_INTERVAL         = 100; // the interval at which we check if we already have reached the target
static constexpr uint32 REPOSITION_MOVEMENT_INTERVAL    = 1200; // (3 batch update cycles) TODO: verify

class ChaseMovementGenerator : public MovementGenerator, public AbstractPursuer
{
    public:
        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        explicit ChaseMovementGenerator(Unit* target, Optional<float> range = {}, Optional<ChaseAngle> angle = {});
        ~ChaseMovementGenerator() = default;

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit* owner, uint32 diff) override;
        void Finalize(Unit* owner) override;

        void UnitSpeedChanged() override { }

    private:
        Optional<float> _range;
        Optional<ChaseAngle> _angle;
        uint32 _previousChaseSplineId;
        TimeTrackerSmall _moveTimer;
        TimeTracker _positionCheckTimer;
        std::unique_ptr<PathGenerator> _pathGenerator;

        ChaseMovementPositionCheckResult checkPosition(ChasePositionCheckOptions checkOptions, Unit* owner, Unit* target, Position const* destination = nullptr) const;
        void launchSpline(Unit* owner, Unit* target, Position& destination);
};

#endif
