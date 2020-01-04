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

#ifndef TRINITY_POINTMOVEMENTGENERATOR_H
#define TRINITY_POINTMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class Creature;

template<class T>
class PointMovementGenerator : public MovementGeneratorMedium< T, PointMovementGenerator<T> >
{
    public:
        PointMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, float speed = 0.0f) : _movementId(id), _x(x), _y(y), _z(z), _speed(speed), _generatePath(generatePath), _recalculateSpeed(false), _interrupt(false) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return POINT_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

        void UnitSpeedChanged() override { _recalculateSpeed = true; }
    private:
        void MovementInform(T*);

        uint32 _movementId;
        float _x, _y, _z;
        float _speed;
        bool _generatePath;
        bool _recalculateSpeed;
        bool _interrupt;
};

class AssistanceMovementGenerator : public PointMovementGenerator<Creature>
{
    public:
        AssistanceMovementGenerator(float _x, float _y, float _z) : PointMovementGenerator<Creature>(0, _x, _y, _z, true) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return ASSISTANCE_MOTION_TYPE; }
        void Finalize(Unit*) override;
};

#endif
