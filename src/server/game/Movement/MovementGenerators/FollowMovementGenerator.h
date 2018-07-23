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
 
#ifndef TRINITY_FOLLOWMOVEMENTGENERATOR_H
#define TRINITY_FOLLOWMOVEMENTGENERATOR_H

#include "AbstractFollower.h"
#include "MovementDefines.h"
#include "MovementGenerator.h"
#include "Optional.h"
#include "Position.h"

class PathGenerator;
class Unit;

#define FOLLOW_RANGE_TOLERANCE 1.0f

class FollowMovementGenerator : public MovementGenerator, public AbstractFollower
{
    public:
        explicit FollowMovementGenerator(Unit* target, float range, ChaseAngle angle);
        ~FollowMovementGenerator();

        void Initialize(Unit*) override;
        void Reset(Unit*) override;
        bool Update(Unit*, uint32) override;
        void Deactivate(Unit*) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return FOLLOW_MOTION_TYPE; }

        void UnitSpeedChanged() override { _lastTargetPosition.reset(); }

    private:
        static constexpr uint32 CHECK_INTERVAL = 500;

        void UpdatePetSpeed(Unit* owner);

        float const _range;
        ChaseAngle const _angle;

        uint32 _checkTimer = CHECK_INTERVAL;
        std::unique_ptr<PathGenerator> _path;
        Optional<Position> _lastTargetPosition;
};

#endif
