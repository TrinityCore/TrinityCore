/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "MovementGenerator.h"
#include "Optional.h"

class PathGenerator;
class Unit;

class ChaseMovementGenerator : public MovementGenerator, public AbstractFollower
{
    public:
        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        ChaseMovementGenerator(Unit* target, Optional<ChaseRange> range = {}, Optional<ChaseAngle> angle = {});
        ~ChaseMovementGenerator();

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit* owner, uint32 diff) override;
        void Finalize(Unit* owner) override;

        void UnitSpeedChanged() override { _lastTargetPosition.Relocate(0.0f,0.0f,0.0f); }

    private:
        static constexpr uint32 RANGE_CHECK_INTERVAL = 100; // time (ms) until we attempt to recalculate

        Optional<ChaseRange> const _range;
        Optional<ChaseAngle> const _angle;

        std::unique_ptr<PathGenerator> _path;
        Position _lastTargetPosition;
        uint32 _rangeCheckTimer = RANGE_CHECK_INTERVAL;
        bool _movingTowards = true;
        bool _mutualChase = true;
};

#endif
