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

class ChaseMovementGenerator : public MovementGenerator, public AbstractPursuer
{
    public:
        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        ChaseMovementGenerator(Unit* target, float range, Optional<ChaseAngle> angle = {});
        ~ChaseMovementGenerator();

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit* owner, uint32 diff) override;
        void Finalize(Unit* owner) override;

        void UnitSpeedChanged() override { _lastTargetPosition.reset(); }

    private:
        void LaunchMovement(Unit* owner, float chaseRange, bool backward = false, bool mutualChase = false);

        static constexpr uint32 CHASE_MOVEMENT_INTERVAL = 400; // sniffed value (1 batch update cyclice)
        static constexpr uint32 REPOSITION_MOVEMENT_INTERVAL = 1200; // (3 batch update cycles) TODO: verify

        TimeTrackerSmall _nextMovementTimer;
        TimeTrackerSmall _nextRepositioningTimer;

        Optional<Position> _lastTargetPosition;
        float const _range;
        Optional<ChaseAngle> const _angle;
};

#endif
