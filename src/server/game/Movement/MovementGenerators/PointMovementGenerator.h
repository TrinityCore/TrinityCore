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
#include "Position.h"

class Creature;
namespace Movement
{
    struct SpellEffectExtraData;
}

class PointMovementGenerator : public MovementGenerator
{
    public:
        explicit PointMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, Optional<float> speed = {}, Optional<float> finalOrient = {},
            Unit const* faceTarget = nullptr, Movement::SpellEffectExtraData const* spellEffectExtraData = nullptr,
            MovementWalkRunSpeedSelectionMode speedSelectionMode = MovementWalkRunSpeedSelectionMode::Default,
            Optional<float> closeEnoughDistance = {},
            Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult = {});

        MovementGeneratorType GetMovementGeneratorType() const override;

        void Initialize(Unit* owner) override;
        void Reset(Unit* owner) override;
        bool Update(Unit* owner, uint32 diff) override;
        void Deactivate(Unit* owner) override;
        void Finalize(Unit* owner, bool active, bool movementInform) override;

        void UnitSpeedChanged() override { AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

        uint32 GetId() const { return _movementId; }

    private:
        void MovementInform(Unit*);

        uint32 _movementId;
        Position _destination;
        Optional<float> _speed;
        bool _generatePath;
        //! if set then unit will turn to specified _orient in provided _pos
        Optional<float> _finalOrient;
        Unit const* i_faceTarget;
        std::unique_ptr<Movement::SpellEffectExtraData> i_spellEffectExtra;
        MovementWalkRunSpeedSelectionMode _speedSelectionMode;
        Optional<float> _closeEnoughDistance;
};

class AssistanceMovementGenerator : public PointMovementGenerator
{
    public:
        explicit AssistanceMovementGenerator(uint32 id, float x, float y, float z) : PointMovementGenerator(id, x, y, z, true) { }

        void Finalize(Unit* owner, bool active, bool movementInform) override;
        MovementGeneratorType GetMovementGeneratorType() const override;
};

#endif
