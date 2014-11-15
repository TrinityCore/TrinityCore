/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "MovementPackets.h"

void WorldPackets::Movement::ClientPlayerMovement::Read()
{
    _worldPacket >> movementInfo.guid;
    _worldPacket >> movementInfo.time;
    _worldPacket >> movementInfo.pos.m_positionX;
    _worldPacket >> movementInfo.pos.m_positionY;
    _worldPacket >> movementInfo.pos.m_positionZ;
    _worldPacket >> movementInfo.pos.m_orientation;
    _worldPacket >> movementInfo.pitch;
    _worldPacket >> movementInfo.splineElevation;

    uint32 removeMovementForcesCount;
    _worldPacket >> removeMovementForcesCount;

    uint32 int168;
    _worldPacket >> int168;

    for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        ObjectGuid guid;
        _worldPacket >> guid;
    }

    // ResetBitReader

    movementInfo.flags = _worldPacket.ReadBits(30);
    movementInfo.flags2 = _worldPacket.ReadBits(15);

    bool hasTransport = _worldPacket.ReadBit();
    bool hasFall = _worldPacket.ReadBit();

    _worldPacket.ReadBit(); // HeightChangeFailed
    _worldPacket.ReadBit(); // RemoteTimeValid

    if (hasTransport)
    {
        _worldPacket >> movementInfo.transport.guid;
        _worldPacket >> movementInfo.transport.pos.m_positionX;
        _worldPacket >> movementInfo.transport.pos.m_positionY;
        _worldPacket >> movementInfo.transport.pos.m_positionZ;
        _worldPacket >> movementInfo.transport.pos.m_orientation;
        _worldPacket >> movementInfo.transport.seat;
        _worldPacket >> movementInfo.transport.time;

        bool hasPrevTime = _worldPacket.ReadBit();
        bool hasVehicleId = _worldPacket.ReadBit();

        if (hasPrevTime)
            _worldPacket >> movementInfo.transport.prevTime;

        if (hasVehicleId)
            _worldPacket >> movementInfo.transport.vehicleId;
    }

    if (hasFall)
    {
        _worldPacket >> movementInfo.jump.fallTime;
        _worldPacket >> movementInfo.jump.zspeed;

        // ResetBitReader

        bool hasFallDirection = _worldPacket.ReadBit();
        if (hasFallDirection)
        {
            _worldPacket >> movementInfo.jump.sinAngle;
            _worldPacket >> movementInfo.jump.cosAngle;
            _worldPacket >> movementInfo.jump.xyspeed;
        }
    }
}

WorldPacket const* WorldPackets::Movement::ServerPlayerMovement::Write()
{
    MovementInfo const movementInfo = mover->m_movementInfo;

    bool hasMovementFlags = mover->GetUnitMovementFlags() != 0;
    bool hasMovementFlags2 = mover->GetExtraUnitMovementFlags() != 0;
    bool hasTransportData = !mover->GetTransGUID().IsEmpty();
    bool hasSpline = mover->IsSplineEnabled();

    bool hasTransportPrevTime = hasTransportData && movementInfo.transport.prevTime != 0;
    bool hasTransportVehicleId = hasTransportData && movementInfo.transport.vehicleId != 0;
    bool hasPitch = mover->HasUnitMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || mover->HasExtraUnitMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING);
    bool hasFallDirection = mover->HasUnitMovementFlag(MOVEMENTFLAG_FALLING);
    bool hasFallData = hasFallDirection || movementInfo.jump.fallTime != 0;
    bool hasSplineElevation = mover->HasUnitMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);

    _worldPacket << movementInfo.guid;
    _worldPacket << movementInfo.time;
    _worldPacket << movementInfo.pos.m_positionX;
    _worldPacket << movementInfo.pos.m_positionY;
    _worldPacket << movementInfo.pos.m_positionZ;
    _worldPacket << movementInfo.pos.m_orientation;
    _worldPacket << movementInfo.pitch;
    _worldPacket << movementInfo.splineElevation;

    uint32 removeMovementForcesCount = 0;
    _worldPacket << removeMovementForcesCount;

    uint32 int168 = 0;
    _worldPacket << int168;

    /*for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        _worldPacket << ObjectGuid;
    }*/

    _worldPacket.FlushBits();

    _worldPacket.WriteBits(movementInfo.flags, 30);
    _worldPacket.WriteBits(movementInfo.flags2, 15);

    _worldPacket.WriteBit(hasTransportData);
    _worldPacket.WriteBit(hasFallData);

    _worldPacket.WriteBit(0); // HeightChangeFailed
    _worldPacket.WriteBit(0); // RemoteTimeValid

    if (hasTransportData)
    {
        _worldPacket << movementInfo.transport.guid;
        _worldPacket << movementInfo.transport.pos.m_positionX;
        _worldPacket << movementInfo.transport.pos.m_positionY;
        _worldPacket << movementInfo.transport.pos.m_positionZ;
        _worldPacket << movementInfo.transport.pos.m_orientation;
        _worldPacket << movementInfo.transport.seat;
        _worldPacket << movementInfo.transport.time;

        _worldPacket.WriteBit(hasTransportPrevTime);
        _worldPacket.WriteBit(hasTransportVehicleId);

        if (hasTransportPrevTime)
            _worldPacket << movementInfo.transport.prevTime;

        if (hasTransportVehicleId)
            _worldPacket << movementInfo.transport.vehicleId;
    }

    if (hasFallData)
    {
        _worldPacket << movementInfo.jump.fallTime;
        _worldPacket << movementInfo.jump.zspeed;

        _worldPacket.FlushBits();

        _worldPacket.WriteBit(hasFallDirection);
        if (hasFallDirection)
        {
            _worldPacket << movementInfo.jump.sinAngle;
            _worldPacket << movementInfo.jump.cosAngle;
            _worldPacket << movementInfo.jump.xyspeed;
        }
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}
