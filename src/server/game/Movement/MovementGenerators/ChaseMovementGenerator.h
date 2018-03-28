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

#include "MovementGenerator.h"
#include "Unit.h"
#include "Optional.h"
#include "PathGenerator.h"

class ChaseMovementGenerator : public MovementGenerator, public AbstractFollower
{
    public:
        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        ChaseMovementGenerator(Unit* target, Optional<ChaseRange> range = {}, Optional<ChaseAngle> angle = {}) : AbstractFollower(ASSERT_NOTNULL(target)), _range(range), _angle(angle) {}

        void Initialize(Unit* owner) override { owner->AddUnitState(UNIT_STATE_CHASE); owner->SetWalk(false); }
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit* owner, uint32 diff) override;
        void Finalize(Unit* owner) override;

        void UnitSpeedChanged() override { _lastTargetPosition.Relocate(0.0f,0.0f,0.0f); }

    private:
        static const uint32 RANGE_CHECK_INTERVAL = 100; // time (ms) until we attempt to recalculate

        Optional<ChaseRange> const _range;
        Optional<ChaseAngle> const _angle;

        std::unique_ptr<PathGenerator> _path;
        Position _lastTargetPosition;
        uint32 _rangeCheckTimer = RANGE_CHECK_INTERVAL;
        bool _movingTowards = true;
        bool _mutualChase = true;
};

#endif
