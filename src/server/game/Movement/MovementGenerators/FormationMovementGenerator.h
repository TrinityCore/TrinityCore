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

#ifndef TRINITY_FORMATIONMOVEMENTGENERATOR_H
#define TRINITY_FORMATIONMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class FormationMovementGenerator : public MovementGeneratorMedium< Creature, FormationMovementGenerator >
{
    public:
        explicit FormationMovementGenerator(uint32 id, Position destination, uint32 moveType, bool run, bool orientation) : _movementId(id), _destination(destination), _moveType(moveType), _run(run), _orientation(orientation), _recalculateSpeed(false), _interrupt(false) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return FORMATION_MOTION_TYPE; }

        void DoInitialize(Creature*);
        void DoFinalize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, uint32);

        void UnitSpeedChanged() override { _recalculateSpeed = true; }

    private:
        void MovementInform(Creature*);

        uint32 _movementId;
        Position _destination;
        uint32 _moveType;
        bool _run;
        bool _orientation;
        bool _recalculateSpeed;
        bool _interrupt;
};

#endif // TRINITY_FORMATIONMOVEMENTGENERATOR_H
