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

#ifndef MovementInfo_h__
#define MovementInfo_h__

#include "ObjectGuid.h"
#include "Position.h"

struct MovementInfo
{
    // common
    ObjectGuid guid;
    uint32 flags;
    uint16 flags2;
    Position pos;
    uint32 time;
    uint32 movementCounter;

    // transport
    struct TransportInfo
    {
        void Reset()
        {
            guid.Clear();
            pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
            seat = -1;
            time = 0;
            time2 = 0;
            vehicleId = 0;
        }

        ObjectGuid guid;
        Position pos;
        int8 seat = -1;
        uint32 time = 0;
        uint32 time2 = 0;
        uint32 vehicleId = 0;
    } transport;

    // swimming/flying
    float pitch;

    // jumping
    struct JumpInfo
    {
        void Reset()
        {
            fallTime = 0;
            zspeed = sinAngle = cosAngle = xyspeed = 0.0f;
        }

        uint32 fallTime;

        float zspeed, sinAngle, cosAngle, xyspeed;

    } jump;

    // spline
    float splineElevation;

    // height change
    bool heightChangeFailed;

    MovementInfo() :
        flags(0), flags2(0), time(0), movementCounter(0), pitch(0.0f), splineElevation(0.0f), heightChangeFailed(false)
    {
        pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
        transport.Reset();
        jump.Reset();
    }

    uint32 GetMovementFlags() const { return flags; }
    void SetMovementFlags(uint32 flag) { flags = flag; }
    void AddMovementFlag(uint32 flag) { flags |= flag; }
    void RemoveMovementFlag(uint32 flag) { flags &= ~flag; }
    bool HasMovementFlag(uint32 flag) const { return (flags & flag) != 0; }

    uint16 GetExtraMovementFlags() const { return flags2; }
    void SetExtraMovementFlags(uint16 flag) { flags2 = flag; }
    void AddExtraMovementFlag(uint16 flag) { flags2 |= flag; }
    void RemoveExtraMovementFlag(uint16 flag) { flags2 &= ~flag; }
    bool HasExtraMovementFlag(uint16 flag) const { return (flags2 & flag) != 0; }

    uint32 GetFallTime() const { return jump.fallTime; }
    void SetFallTime(uint32 time) { jump.fallTime = time; }

    void ResetTransport();
    void ResetJump();
    bool HasFallDirection() const;
    bool HasFallData() const;
    bool HasMovementFlags() const;
    bool HasExtraMovementFlags() const;
    bool HasSpline() const;
    bool HasHeightChangeFailed() const;
    bool HasTime() const;
    bool HasOrientation() const;
    bool HasSplineElevation() const;
    bool HasPitch() const;
    bool HasTransportData() const;
    bool HasTransportVehicleId() const;
    bool HasTransportTime2() const;

    // Returns the angle of the current movement direction based on movement flags (forward, strafe left etc)
    float GetMovementDirection() const;

    void OutDebug();
};

#endif // MovementInfo_h__
