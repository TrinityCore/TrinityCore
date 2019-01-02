/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_POINTMOVEMENTGENERATOR_H
#define TRINITY_POINTMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "Optional.h"

class Creature;

template<class T>
class PointMovementGenerator : public MovementGeneratorMedium<T, PointMovementGenerator<T>>
{
    public:
        explicit PointMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, float speed = 0.0f, Optional<float> finalOrient = {});

        MovementGeneratorType GetMovementGeneratorType() const override;

        void DoInitialize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);
        void DoDeactivate(T*);
        void DoFinalize(T*, bool, bool);

        void UnitSpeedChanged() override { PointMovementGenerator<T>::AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

        uint32 GetId() const { return _movementId; }

    private:
        void MovementInform(T*);

        uint32 _movementId;
        float _x, _y, _z;
        float _speed;
        bool _generatePath;
        //! if set then unit will turn to specified _orient in provided _pos
        Optional<float> _finalOrient;
};

class AssistanceMovementGenerator : public PointMovementGenerator<Creature>
{
    public:
        explicit AssistanceMovementGenerator(uint32 id, float x, float y, float z) : PointMovementGenerator<Creature>(id, x, y, z, true) { }

        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override;
};

#endif
