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
#include "MovementGenerator.h"

class PathGenerator;
class Unit;

class FollowMovementGenerator : public MovementGenerator, public AbstractFollower
{
    public:
        MovementGeneratorType GetMovementGeneratorType() const override { return FOLLOW_MOTION_TYPE; }

        FollowMovementGenerator(Unit* target, float range, ChaseAngle angle);
        ~FollowMovementGenerator();

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit* owner, uint32 diff) override;
        void Finalize(Unit* owner) override;

        void UnitSpeedChanged() override { _lastTargetPosition.Relocate(0.0f, 0.0f, 0.0f); }

    private:
        static constexpr uint32 CHECK_INTERVAL = 500;
// static inline const when?
#define FOLLOW_RANGE_TOLERANCE 1.0f

        void UpdatePetSpeed(Unit* owner);

        float const _range;
        ChaseAngle const _angle;

        uint32 _checkTimer = CHECK_INTERVAL;
        std::unique_ptr<PathGenerator> _path;
        Position _lastTargetPosition;
};

#endif
