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

#ifndef TRINITY_FORMATIONMOVEMENTGENERATOR_H
#define TRINITY_FORMATIONMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "Position.h"

class Creature;

class FormationMovementGenerator : public MovementGeneratorMedium<Creature, FormationMovementGenerator>
{
    public:
        explicit FormationMovementGenerator(uint32 id, Position destination, uint32 moveType, bool run, bool orientation);

        MovementGeneratorType GetMovementGeneratorType() const override;

        void DoInitialize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, uint32);
        void DoDeactivate(Creature*);
        void DoFinalize(Creature*, bool, bool);

        void UnitSpeedChanged() override { AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }

    private:
        void MovementInform(Creature*);

        uint32 _movementId;
        Position _destination;
        uint32 _moveType;
        bool _run;
        bool _orientation;
};

#endif // TRINITY_FORMATIONMOVEMENTGENERATOR_H
