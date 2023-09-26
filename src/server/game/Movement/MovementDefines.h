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

#ifndef TRINITY_MOVEMENTDEFINES_H
#define TRINITY_MOVEMENTDEFINES_H

#include "Common.h"

#define SPEED_CHARGE 42.0f // assume it is 25 yard per 0.6 second

// EnumUtils: DESCRIBE THIS
enum MovementGeneratorType : uint8
{
    IDLE_MOTION_TYPE                = 0,     // IdleMovementGenerator.h
    RANDOM_MOTION_TYPE              = 1,     // RandomMovementGenerator.h
    WAYPOINT_MOTION_TYPE            = 2,     // WaypointMovementGenerator.h
    MAX_DB_MOTION_TYPE              = 3,     // Below motion types can't be set in DB.
    CONFUSED_MOTION_TYPE            = 4,     // ConfusedMovementGenerator.h
    CHASE_MOTION_TYPE               = 5,     // ChaseMovementGenerator.h
    HOME_MOTION_TYPE                = 6,     // HomeMovementGenerator.h
    FLIGHT_MOTION_TYPE              = 7,     // FlightPathMovementGenerator.h
    POINT_MOTION_TYPE               = 8,     // PointMovementGenerator.h
    FLEEING_MOTION_TYPE             = 9,     // FleeingMovementGenerator.h
    DISTRACT_MOTION_TYPE            = 10,    // IdleMovementGenerator.h
    ASSISTANCE_MOTION_TYPE          = 11,    // PointMovementGenerator.h
    ASSISTANCE_DISTRACT_MOTION_TYPE = 12,    // IdleMovementGenerator.h
    TIMED_FLEEING_MOTION_TYPE       = 13,    // FleeingMovementGenerator.h
    FOLLOW_MOTION_TYPE              = 14,    // FollowMovementGenerator.h
    ROTATE_MOTION_TYPE              = 15,    // IdleMovementGenerator.h
    EFFECT_MOTION_TYPE              = 16,
    SPLINE_CHAIN_MOTION_TYPE        = 17,    // SplineChainMovementGenerator.h
    FORMATION_MOTION_TYPE           = 18,    // FormationMovementGenerator.h
    JUMP_MOTION_TYPE                = 19,    // JumpMovementGenerator.h
    CHARGE_MOTION_TYPE              = 20,    // ChargeMovementGenerator.h
    MAX_MOTION_TYPE                          // SKIP
};

enum MovementGeneratorMode : uint8
{
    MOTION_MODE_DEFAULT = 0,
    MOTION_MODE_OVERRIDE
};

enum MovementGeneratorPriority : uint8
{
    MOTION_PRIORITY_NONE = 0,
    MOTION_PRIORITY_NORMAL,
    MOTION_PRIORITY_HIGHEST
};

enum MovementSlot : uint8
{
    MOTION_SLOT_DEFAULT = 0,
    MOTION_SLOT_ACTIVE,
    MAX_MOTION_SLOT
};

enum RotateDirection : uint8
{
    ROTATE_DIRECTION_LEFT = 0,
    ROTATE_DIRECTION_RIGHT
};

struct TC_GAME_API ChaseRange
{
    ChaseRange(float range);
    ChaseRange(float _minRange, float _maxRange);
    ChaseRange(float _minRange, float _minTolerance, float _maxTolerance, float _maxRange);

    // this contains info that informs how we should path!
    float MinRange;     // we have to move if we are within this range...    (min. attack range)
    float MinTolerance; // ...and if we are, we will move this far away
    float MaxRange;     // we have to move if we are outside this range...   (max. attack range)
    float MaxTolerance; // ...and if we are, we will move into this range
};

struct TC_GAME_API ChaseAngle
{
    ChaseAngle(float angle, float _tolerance = M_PI_4);

    float RelativeAngle; // we want to be at this angle relative to the target (0 = front, M_PI = back)
    float Tolerance;     // but we'll tolerate anything within +- this much

    float UpperBound() const;
    float LowerBound() const;
    bool IsAngleOkay(float relativeAngle) const;
};

inline bool IsInvalidMovementGeneratorType(uint8 const type) { return type == MAX_DB_MOTION_TYPE || type >= MAX_MOTION_TYPE; }
inline bool IsInvalidMovementSlot(uint8 const slot) { return slot >= MAX_MOTION_SLOT; }

#endif
