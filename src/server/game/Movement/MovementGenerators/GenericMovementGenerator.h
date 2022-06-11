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

#ifndef TRINITY_GENERICMOVEMENTGENERATOR_H
#define TRINITY_GENERICMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "MoveSplineInit.h"
#include "Timer.h"
#include <functional>

class Unit;

enum MovementGeneratorType : uint8;

class GenericMovementGenerator : public MovementGenerator
{
    public:
        explicit GenericMovementGenerator(std::function<void(Movement::MoveSplineInit& init)>&& initializer, MovementGeneratorType type, uint32 id,
            uint32 arrivalSpellId = 0, ObjectGuid const& arrivalSpellTargetGuid = ObjectGuid::Empty);

        void Initialize(Unit*) override;
        void Reset(Unit*) override;
        bool Update(Unit*, uint32) override;
        void Deactivate(Unit*) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return _type; }

    private:
        void MovementInform(Unit*);

        std::function<void(Movement::MoveSplineInit& init)> _splineInit;
        MovementGeneratorType _type;
        uint32 _pointId;
        TimeTracker _duration;

        uint32 _arrivalSpellId;
        ObjectGuid _arrivalSpellTargetGuid;
};

#endif
