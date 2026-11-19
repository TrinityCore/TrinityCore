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

#ifndef TRINITYCORE_MOVEMENT_INFO_H
#define TRINITYCORE_MOVEMENT_INFO_H

#include "EnumFlag.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include <algorithm>
#include <vector>

// EnumUtils: DESCRIBE THIS
enum MovementFlags : uint64
{
    MOVEMENTFLAG_NONE                       = 0x0000000000000000,   // SKIP
    MOVEMENTFLAG_FORWARD                    = 0x0000000000000001,
    MOVEMENTFLAG_BACKWARD                   = 0x0000000000000002,
    MOVEMENTFLAG_STRAFE_LEFT                = 0x0000000000000004,
    MOVEMENTFLAG_STRAFE_RIGHT               = 0x0000000000000008,
    MOVEMENTFLAG_LEFT                       = 0x0000000000000010,
    MOVEMENTFLAG_RIGHT                      = 0x0000000000000020,
    MOVEMENTFLAG_PITCH_UP                   = 0x0000000000000040,
    MOVEMENTFLAG_PITCH_DOWN                 = 0x0000000000000080,
    MOVEMENTFLAG_WALKING                    = 0x0000000000000100,   // Walking
    MOVEMENTFLAG_DISABLE_GRAVITY            = 0x0000000000000200,   // Former MOVEMENTFLAG_LEVITATING. This is used when walking is not possible.
    MOVEMENTFLAG_ROOT                       = 0x0000000000000400,   // Must not be set along with MOVEMENTFLAG_MASK_MOVING
    MOVEMENTFLAG_FALLING                    = 0x0000000000000800,   // damage dealt on that type of falling
    MOVEMENTFLAG_FALLING_FAR                = 0x0000000000001000,
    MOVEMENTFLAG_PENDING_STOP               = 0x0000000000002000,
    MOVEMENTFLAG_PENDING_STRAFE_STOP        = 0x0000000000004000,
    MOVEMENTFLAG_PENDING_FORWARD            = 0x0000000000008000,
    MOVEMENTFLAG_PENDING_BACKWARD           = 0x0000000000010000,
    MOVEMENTFLAG_PENDING_STRAFE_LEFT        = 0x0000000000020000,
    MOVEMENTFLAG_PENDING_STRAFE_RIGHT       = 0x0000000000040000,
    MOVEMENTFLAG_PENDING_ROOT               = 0x0000000000080000,
    MOVEMENTFLAG_SWIMMING                   = 0x0000000000100000,   // appears with fly flag also
    MOVEMENTFLAG_ASCENDING                  = 0x0000000000200000,   // press "space" when flying
    MOVEMENTFLAG_DESCENDING                 = 0x0000000000400000,
    MOVEMENTFLAG_CAN_FLY                    = 0x0000000000800000,   // Appears when unit can fly. For example, appears when a player sits on a mount.
    MOVEMENTFLAG_FLYING                     = 0x0000000001000000,   // unit is actually flying. pretty sure this is only used for players. creatures use disable_gravity
    MOVEMENTFLAG_SPLINE_ELEVATION           = 0x0000000002000000,   // used for flight paths
    MOVEMENTFLAG_WATERWALKING               = 0x0000000004000000,   // prevent unit from falling through water
    MOVEMENTFLAG_FALLING_SLOW               = 0x0000000008000000,   // active rogue safe fall spell (passive)
    MOVEMENTFLAG_CANNOT_SWIM                = 0x0000000010000000,
    MOVEMENTFLAG_DISABLE_COLLISION          = 0x0000000020000000,
    MOVEMENTFLAG_KNOCKBACK                  = 0x0000000040000000,
    MOVEMENTFLAG_TOUCHING_GROUND            = 0x0000000080000000,   // terrain normal calculation is disabled if this flag is not present, client automatically handles setting this flag
    MOVEMENTFLAG_NO_STRAFE                  = 0x0000000100000000,
    MOVEMENTFLAG_NO_JUMPING                 = 0x0000000200000000,
    MOVEMENTFLAG_FULL_SPEED_TURNING         = 0x0000000400000000,
    MOVEMENTFLAG_FULL_SPEED_PITCHING        = 0x0000000800000000,
    MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING      = 0x0000001000000000,
    MOVEMENTFLAG_WATERWALKING_FULL_PITCH    = 0x0000002000000000,
    MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS      = 0x0000004000000000,
    MOVEMENTFLAG_CAN_TURN_WHILE_FALLING     = 0x0000008000000000,
    MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES     = 0x0000010000000000,
    MOVEMENTFLAG_CAN_DOUBLE_JUMP            = 0x0000020000000000,
    MOVEMENTFLAG_DOUBLE_JUMP                = 0x0000040000000000,
    MOVEMENTFLAG_UNK43                      = 0x0000080000000000,   // old MovementFlags2 0x8000
    MOVEMENTFLAG_DISABLE_INERTIA            = 0x0000100000000000,
    MOVEMENTFLAG_CAN_ADV_FLY                = 0x0000200000000000,
    MOVEMENTFLAG_ADV_FLYING                 = 0x0000400000000000,
    MOVEMENTFLAG_UNK47                      = 0x0000800000000000,   // old MovementFlags3 0x8
    MOVEMENTFLAG_UNK48                      = 0x0001000000000000,   // old MovementFlags3 0x10
    MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT   = 0x0002000000000000,   // falling after dismounting while adv flying
    MOVEMENTFLAG_UNK50                      = 0x0004000000000000,   // old MovementFlags3 0x200
    MOVEMENTFLAG_WALKING_ON_WATER           = 0x0008000000000000,   // currently on water surface
    MOVEMENTFLAG_CAN_DRIVE                  = 0x0010000000000000,
    MOVEMENTFLAG_DRIVING_FORWARD            = 0x0020000000000000,
    MOVEMENTFLAG_DRIVING_BACKWARD           = 0x0040000000000000,
    MOVEMENTFLAG_UNK55                      = 0x0080000000000000,   // old MovementFlags3 0x20000
    MOVEMENTFLAG_UNK56                      = 0x0100000000000000,   // old MovementFlags3 0x40000
    MOVEMENTFLAG_UNK57                      = 0x0200000000000000,   // old MovementFlags3 0x80000
    MOVEMENTFLAG_UNK58                      = 0x0400000000000000,
    MOVEMENTFLAG_HOVER                      = 0x0800000000000000,

    MOVEMENTFLAG_MASK_MOVING =
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT |
        MOVEMENTFLAG_FALLING | MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING,// SKIP

    MOVEMENTFLAG_MASK_TURNING =
        MOVEMENTFLAG_LEFT | MOVEMENTFLAG_RIGHT | MOVEMENTFLAG_PITCH_UP | MOVEMENTFLAG_PITCH_DOWN, // SKIP

    MOVEMENTFLAG_MASK_MOVING_FLY =
        MOVEMENTFLAG_FLYING | MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING, // SKIP

    // Movement flags allowed for creature in CreateObject - we need to keep all other enabled serverside
    // to properly calculate all movement
    MOVEMENTFLAG_MASK_CREATURE_ALLOWED =
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_ROOT | MOVEMENTFLAG_SWIMMING |
        MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_WATERWALKING | MOVEMENTFLAG_FALLING_SLOW | MOVEMENTFLAG_HOVER | MOVEMENTFLAG_DISABLE_COLLISION, // SKIP

    /// @todo if needed: add more flags to this masks that are exclusive to players
    MOVEMENTFLAG_MASK_PLAYER_ONLY =
        MOVEMENTFLAG_FLYING, // SKIP

    /// Movement flags that have change status opcodes associated for players
    MOVEMENTFLAG_MASK_HAS_PLAYER_STATUS_OPCODE = MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_ROOT |
        MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_WATERWALKING | MOVEMENTFLAG_FALLING_SLOW | MOVEMENTFLAG_HOVER | MOVEMENTFLAG_DISABLE_COLLISION // SKIP
};

DEFINE_ENUM_FLAG(MovementFlags);

struct MovementInfo
{
    // common
    ObjectGuid guid;
    MovementFlags flags = MOVEMENTFLAG_NONE;
    Position pos;
    uint32 time = 0;

    // transport
    struct TransportInfo
    {
        void Reset()
        {
            guid.Clear();
            pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
            seat = -1;
            time = 0;
            prevTime = 0;
            vehicleId = 0;
        }

        ObjectGuid guid;
        Position pos;
        int8 seat = -1;
        uint32 time = 0;
        uint32 prevTime = 0;
        uint32 vehicleId = 0;
    } transport;

    // swimming/flying
    float pitch = 0.0f;

    struct Inertia
    {
        Inertia() : id(0), lifetime(0) { }

        int32 id;
        Position force;
        uint32 lifetime;
    };

    Optional<Inertia> inertia;

    // jumping
    struct JumpInfo
    {
        void Reset()
        {
            fallTime = 0;
            zspeed = sinAngle = cosAngle = xyspeed = 0.0f;
        }

        uint32 fallTime = 0;

        float zspeed = 0.0f;
        float sinAngle = 0.0f;
        float cosAngle = 0.0f;
        float xyspeed = 0.0f;

    } jump;

    float stepUpStartElevation = 0.0f;

    // advflying
    struct AdvFlying
    {
        AdvFlying() : forwardVelocity(0.0f), upVelocity(0.0f) { }

        float forwardVelocity;
        float upVelocity;
    };

    struct Drive
    {
        Drive() : speed(0.0f), movementAngle(0.0f), accelerating(false), drifting(false) { }

        float speed;
        float movementAngle;
        bool accelerating;
        bool drifting;
    };

    Optional<AdvFlying> advFlying;

    Optional<Drive> driveStatus;

    float gravityModifier = 1.0f;

    Optional<ObjectGuid> standingOnGameObjectGUID;

    MovementFlags GetMovementFlags() const { return flags; }
    void SetMovementFlags(MovementFlags flag) { flags = flag; }
    void AddMovementFlag(MovementFlags flag) { flags |= flag; }
    void RemoveMovementFlag(MovementFlags flag) { flags &= ~flag; }
    bool HasMovementFlag(MovementFlags flag) const { return (flags & flag) != 0; }

    uint32 GetFallTime() const { return jump.fallTime; }
    void SetFallTime(uint32 fallTime) { jump.fallTime = fallTime; }

    void ResetTransport()
    {
        transport.Reset();
    }

    void ResetJump()
    {
        jump.Reset();
    }

    void OutDebug();
};

enum class MovementForceType : uint8
{
    SingleDirectional   = 0, // always in a single direction
    Gravity             = 1  // pushes/pulls away from a single point
};

struct MovementForce
{
    ObjectGuid ID;
    TaggedPosition<Position::XYZ> Origin;
    TaggedPosition<Position::XYZ> Direction;
    uint32 TransportID = 0;
    float Magnitude = 0.0f;
    MovementForceType Type = MovementForceType::SingleDirectional;
    int32 MovementForceID = 0;
    int32 DurationMs = 0;
    uint32 EndTimestamp = 0;
    uint32 Flags = 0;
};

class MovementForces
{
public:
    using Container = std::vector<MovementForce>;

    Container const* GetForces() const { return &_forces; }
    bool Add(MovementForce const& newForce)
    {
        auto itr = FindMovementForce(newForce.ID);
        if (itr == _forces.end())
        {
            _forces.push_back(newForce);
            return true;
        }

        return false;
    }

    bool Remove(ObjectGuid id)
    {
        auto itr = FindMovementForce(id);
        if (itr != _forces.end())
        {
            _forces.erase(itr);
            return true;
        }

        return false;
    }

    float GetModMagnitude() const { return _modMagnitude; }
    void SetModMagnitude(float modMagnitude) { _modMagnitude = modMagnitude; }

    bool IsEmpty() const { return _forces.empty() && _modMagnitude == 1.0f; }

private:
    Container::iterator FindMovementForce(ObjectGuid id)
    {
        return std::find_if(_forces.begin(), _forces.end(), [id](MovementForce const& force) { return force.ID == id; });
    }

    Container _forces;
    float _modMagnitude = 1.0f;
};

#endif // TRINITYCORE_MOVEMENT_INFO_H
