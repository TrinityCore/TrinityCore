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
#include "WorldPacket.h"
#include "UnitDefines.h"

struct MovementInfo
{
    // common
    ObjectGuid guid;
    uint32 flags;
    uint16 flags2;
    Position pos;
    uint32 time;

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
        }

        ObjectGuid guid;
        Position pos;
        int8 seat;
        uint32 time;
        uint32 time2;
    } transport;

    // swimming/flying
    float pitch;

    // falling
    uint32 fallTime;

    // jumping
    struct JumpInfo
    {
        void Reset()
        {
            zspeed = sinAngle = cosAngle = xyspeed = 0.0f;
        }

        float zspeed, sinAngle, cosAngle, xyspeed;

    } jump;

    // spline
    float splineElevation;

    MovementInfo() :
        guid(), flags(0), flags2(0), time(0), pitch(0.0f), fallTime(0), splineElevation(0.0f)
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
    void AddExtraMovementFlag(uint16 flag) { flags2 |= flag; }
    bool HasExtraMovementFlag(uint16 flag) const { return (flags2 & flag) != 0; }

    void SetFallTime(uint32 val) { fallTime = val; }

    void OutDebug();

    void Write(WorldPacket* data)
    {
        *data << guid.WriteAsPacked();
        *data << flags;
        *data << flags2;
        *data << time;
        *data << pos.PositionXYZOStream();

        if (HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
        {
           *data << transport.guid.WriteAsPacked();
           *data << transport.pos.PositionXYZOStream();
           *data << transport.time;
           *data << transport.seat;

           if (HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
               *data << transport.time2;
        }

        if (HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
            *data << pitch;

        *data << fallTime;

        if (HasMovementFlag(MOVEMENTFLAG_FALLING))
        {
            *data << jump.zspeed;
            *data << jump.sinAngle;
            *data << jump.cosAngle;
            *data << jump.xyspeed;
        }

        if (HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
            *data << splineElevation;
    }
};

#endif // MovementInfo_h__
