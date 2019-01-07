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
#include "FollowerReference.h"

class Creature;
namespace Movement
{
    struct SpellEffectExtraData;
}

template<class T>
class PointMovementGenerator : public MovementGeneratorMedium< T, PointMovementGenerator<T> >
{
    public:
        PointMovementGenerator(uint32 _id, float _x, float _y, float _z, bool _generatePath, float _speed = 0.0f, Unit const* faceTarget = nullptr,
            Movement::SpellEffectExtraData const* spellEffectExtraData = nullptr) : id(_id),
            i_x(_x), i_y(_y), i_z(_z), speed(_speed), i_faceTarget(faceTarget), i_spellEffectExtra(spellEffectExtraData),
            m_generatePath(_generatePath), i_recalculateSpeed(false) { }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

        void MovementInform(T*);

        void unitSpeedChanged() override { i_recalculateSpeed = true; }

        MovementGeneratorType GetMovementGeneratorType() const override { return POINT_MOTION_TYPE; }

        void GetDestination(float& x, float& y, float& z) const { x = i_x; y = i_y; z = i_z; }
    private:
        uint32 id;
        float i_x, i_y, i_z;
        float speed;
        Unit const* i_faceTarget;
        Movement::SpellEffectExtraData const* i_spellEffectExtra;
        bool m_generatePath;
        bool i_recalculateSpeed;
};

class AssistanceMovementGenerator : public PointMovementGenerator<Creature>
{
    public:
        AssistanceMovementGenerator(float _x, float _y, float _z) :
            PointMovementGenerator<Creature>(0, _x, _y, _z, true) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return ASSISTANCE_MOTION_TYPE; }
        void Finalize(Unit*) override;
};

// Does almost nothing - just doesn't allows previous movegen interrupt current effect.
class EffectMovementGenerator : public MovementGenerator
{
    public:
        EffectMovementGenerator(uint32 id, uint32 arrivalSpellId = 0, ObjectGuid const& arrivalSpellTargetGuid = ObjectGuid::Empty)
            : _id(id), _arrivalSpellId(arrivalSpellId), _arrivalSpellTargetGuid(arrivalSpellTargetGuid) { }
        void Initialize(Unit*) override { }
        void Finalize(Unit*) override;
        void Reset(Unit*) override { }
        bool Update(Unit*, uint32) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return EFFECT_MOTION_TYPE; }
    private:
        uint32 _id;
        uint32 _arrivalSpellId;
        ObjectGuid _arrivalSpellTargetGuid;
};

#endif
