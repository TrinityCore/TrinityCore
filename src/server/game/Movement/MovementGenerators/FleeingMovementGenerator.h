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

#ifndef TRINITY_FLEEINGMOVEMENTGENERATOR_H
#define TRINITY_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "ObjectGuid.h"
#include "Timer.h"

class PathGenerator;
struct Position;

class FleeingMovementGenerator : public MovementGenerator
{
    public:
        explicit FleeingMovementGenerator(ObjectGuid fleeTargetGUID);

        MovementGeneratorType GetMovementGeneratorType() const override;

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override;
        bool Update(Unit* owner, uint32 diff) override;
        void Deactivate(Unit* owner) override;
        void Finalize(Unit* owner, bool, bool) override;

        void UnitSpeedChanged() override { AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

    private:
        void SetTargetLocation(Unit* owner);
        void GetPoint(Unit* owner, Position& position) const;

        std::unique_ptr<PathGenerator> _path;
        ObjectGuid _fleeTargetGUID;
        TimeTracker _timer;
};

class TimedFleeingMovementGenerator : public FleeingMovementGenerator
{
    public:
        explicit TimedFleeingMovementGenerator(ObjectGuid fleeTargetGUID, Milliseconds time) : FleeingMovementGenerator(fleeTargetGUID), _totalFleeTime(time) { }

        bool Update(Unit*, uint32) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override;

    private:
        TimeTracker _totalFleeTime;
};

#endif
