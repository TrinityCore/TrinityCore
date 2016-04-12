/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "FollowerReference.h"

template<class T>
class PointMovementGenerator : public MovementGeneratorMedium< T, PointMovementGenerator<T> >
{
    public:
        PointMovementGenerator(uint32 _id, float _x, float _y, float _z, bool _generatePath, float _speed = 0.0f) :
            m_id(_id), m_x(_x), m_y(_y), m_z(_z), m_speed(_speed), m_generatePath(_generatePath), m_recalculateSpeed(false), m_interrupt(false) { }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

        void MovementInform(T*);
        void DoInterrupt(T*);

        void UnitSpeedChanged() override { m_recalculateSpeed = true; }
        void unitMovementInterrupted(Unit* unit) override { DoInterrupt(static_cast<T*>(unit)); }

        MovementGeneratorType GetMovementGeneratorType() const override { return POINT_MOTION_TYPE; }

        void GetDestination(float& x, float& y, float& z) const { x = m_x; y = m_y; z = m_z; }
    private:
        uint32 m_id;
        float m_x, m_y, m_z;
        float m_speed;
        bool m_generatePath;
        bool m_recalculateSpeed;
        bool m_interrupt;
};

template<class T>
class AssistanceMovementGenerator : public PointMovementGenerator<T>
{
    public:
        AssistanceMovementGenerator(float _x, float _y, float _z) : PointMovementGenerator<T>(0, _x, _y, _z, true) { }

        void DoFinalize(T*);
        MovementGeneratorType GetMovementGeneratorType() const override { return ASSISTANCE_MOTION_TYPE; }
};

class EffectMovementGenerator : public MovementGenerator
{
    public:
        explicit EffectMovementGenerator(uint32 Id) : m_id(Id) { }
        void Initialize(Unit*) override { }
        void Finalize(Unit*) override;
        void Reset(Unit*) override { }
        bool Update(Unit*, uint32) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return EFFECT_MOTION_TYPE; }

        void MovementInform(Unit*);
    private:
        uint32 m_id;
};

#endif
