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
#include "AbstractPursuer.h"
#include "Timer.h"

class Creature;

class FormationMovementGenerator : public MovementGeneratorMedium<Creature, FormationMovementGenerator>, public AbstractPursuer
{
    public:
        explicit FormationMovementGenerator(Unit* leader, float range, float angle, int32 point1, int32 point2);

        MovementGeneratorType GetMovementGeneratorType() const override { return FORMATION_MOTION_TYPE; }

        void DoInitialize(Creature* owner);
        void DoFinalize(Creature* owner);
        void DoReset(Creature* owner) { DoInitialize(owner); };
        bool DoUpdate(Creature* owner, uint32 diff);

    private:
        void MovementInform(Creature* owner);

        void LaunchMovement(Creature* owner, Unit* target);

        static constexpr uint32 FORMATION_MOVEMENT_INTERVAL = 1200; // sniffed (3 batch update cycles)
        float const _range;
        float _angle;
        int32 const _point1;
        int32 const _point2;
        uint32 _lastLeaderSplineID;
        bool _hasPredictedDestination;

        Position _lastLeaderPosition;
        TimeTrackerSmall _nextMoveTimer;
};

#endif // TRINITY_FORMATIONMOVEMENTGENERATOR_H
