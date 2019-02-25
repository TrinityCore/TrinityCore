/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "AbstractFollower.h"
#include "MovementDefines.h"
#include "MovementGenerator.h"
#include "Optional.h"
#include "Position.h"

class PathGenerator;
class Unit;

class ChaseMovementGenerator : public MovementGenerator, public AbstractFollower
{
    public:
        explicit ChaseMovementGenerator(Unit* target, Optional<ChaseRange> range = {}, Optional<ChaseAngle> angle = {}, bool walk = false);
        ~ChaseMovementGenerator();

        void Initialize(Unit*) override;
        void Reset(Unit*) override;
        bool Update(Unit*, uint32) override;
        void Deactivate(Unit*) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        void UnitSpeedChanged() override { _lastTargetPosition.reset(); }

    private:
        static constexpr uint32 RANGE_CHECK_INTERVAL = 100; // time (ms) until we attempt to recalculate

        Optional<ChaseRange> const _range;
        Optional<ChaseAngle> const _angle;
        bool _walk;

        std::unique_ptr<PathGenerator> _path;
        Optional<Position> _lastTargetPosition;
        uint32 _rangeCheckTimer = RANGE_CHECK_INTERVAL;
        bool _movingTowards = true;
        bool _mutualChase = true;
};

#endif
