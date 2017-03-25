/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

template<class T>
class PointMovementGenerator : public MovementGeneratorMedium< T, PointMovementGenerator<T> >
{
    public:
        explicit PointMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, float speed = 0.0f) : _movementId(id), _destination(x, y, z), _speed(speed), _generatePath(generatePath), _recalculateSpeed(false), _interrupt(false) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return POINT_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

        void UnitSpeedChanged() override { _recalculateSpeed = true; }

    private:
        void MovementInform(T*);

        uint32 _movementId;
        G3D::Vector3 _destination;
        float _speed;
        bool _generatePath;
        bool _recalculateSpeed;
        bool _interrupt;
};

class AssistanceMovementGenerator : public PointMovementGenerator<Creature>
{
    public:
        explicit AssistanceMovementGenerator(float _x, float _y, float _z) : PointMovementGenerator<Creature>(0, _x, _y, _z, true) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return ASSISTANCE_MOTION_TYPE; }
        void Finalize(Unit*) override;
};

class EffectMovementGenerator : public MovementGenerator
{
    public:
        explicit EffectMovementGenerator(uint32 id) : _pointId(id) { }

        void Initialize(Unit*) override { }
        void Finalize(Unit*) override;
        void Reset(Unit*) override { }
        bool Update(Unit*, uint32) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return EFFECT_MOTION_TYPE; }

    private:
        void MovementInform(Unit*);

        uint32 _pointId;
};

#endif
