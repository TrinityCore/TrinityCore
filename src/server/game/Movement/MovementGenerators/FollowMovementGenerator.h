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

#ifndef TRINITY_FOLLOWMOVEMENTGENERATOR_H
#define TRINITY_FOLLOWMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "AbstractPursuer.h"
#include "EventMap.h"
#include "Optional.h"
#include "Timer.h"

class Unit;

enum Events
{
    EVENT_ALLIGN_TO_TARGET = 1,
    EVENT_ALLIGN_TO_FACING_DIRECTION,
};

constexpr uint8 MAX_FOLLOWERS_PER_ROW = 6;
constexpr uint8 DEFAULT_ROW_FOLLOWERS = 2;
constexpr float STRAIGHT_FOLLOW_DISTANCE = 3.f;
constexpr float SIDE_FOLLOW_DISTANCE = 3.3541f;

class FollowMovementGenerator : public MovementGenerator, public AbstractPursuer
{
public:
    MovementGeneratorType GetMovementGeneratorType() const override { return FOLLOW_MOTION_TYPE; }

    FollowMovementGenerator(Unit* target, Optional<float> distance, Optional<float> angle, bool joinFormation = false, bool catchUpToTarget = false, bool faceTarget = false);
    ~FollowMovementGenerator();

    void Initialize(Unit* owner) override;
    void Finalize(Unit* owner) override;
    void Reset(Unit* /*owner*/) override;
    bool Update(Unit* owner, uint32 diff) override;

private:
    void UpdateFollowFormation();
    void UpdateFormationFollowOffsets(uint32 slot);
    void LaunchMovement(Unit* owner);

    static constexpr uint32 FOLLOW_MOVEMENT_INTERVAL = 400; // sniffed (1 batch update cycle)
    static constexpr uint32 ALLIGN_MOVEMENT_INTERVAL = 2000; // sniffed (5 batch update cycles)

    float _distance;
    float _angle;
    bool const _joinFormation;
    bool const _catchUpToTarget;
    bool const _faceTarget;

    TimeTrackerSmall _followMovementTimer;
    EventMap _events;
};

#endif
