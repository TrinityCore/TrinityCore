/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo)
{
    data >> movementInfo.flags;
    data >> movementInfo.flags2;
    data >> movementInfo.time;
    data >> movementInfo.pos.PositionXYZOStream();

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        data >> movementInfo.transport.guid.ReadAsPacked();
        data >> movementInfo.transport.pos.PositionXYZOStream();
        data >> movementInfo.transport.time;
        data >> movementInfo.transport.seat;

        if (movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
            data >> movementInfo.transport.time2;
    }

    if (movementInfo.HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING)))
        data >> movementInfo.pitch;

    data >> movementInfo.fallTime;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
    {
        data >> movementInfo.jump.zspeed;
        data >> movementInfo.jump.sinAngle;
        data >> movementInfo.jump.cosAngle;
        data >> movementInfo.jump.xyspeed;
    }

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
        data >> movementInfo.splineElevation;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& ack)
{
    data >> ack.AckIndex;
    data >> ack.movementInfo;

    return data;
}

void WorldPackets::Movement::ClientPlayerMovement::Read()
{
    ObjectGuid guid;
    _worldPacket >> guid.ReadAsPacked();
    _worldPacket >> movementInfo;
    movementInfo.guid = guid;

    _worldPacket.rfinish();
}

void WorldPackets::Movement::MovementAckMessage::Read()
{
    ObjectGuid guid;
    _worldPacket >> guid.ReadAsPacked();

    _worldPacket >> Ack;
    Ack.movementInfo.guid = guid;

    _worldPacket.rfinish();
}

void WorldPackets::Movement::MovementSpeedAck::Read()
{
    ObjectGuid guid;
    _worldPacket >> guid.ReadAsPacked();

    _worldPacket >> Ack;
    _worldPacket >> Speed;

    Ack.movementInfo.guid = guid;

    _worldPacket.rfinish();
}

void WorldPackets::Movement::NotActiveMover::Read()
{
    ObjectGuid guid;
    _worldPacket >> guid.ReadAsPacked();

    _worldPacket >> movementInfo;

    movementInfo.guid = guid;
}

void WorldPackets::Movement::MoveTimeSkipped::Read()
{
    _worldPacket >> moverGUID.ReadAsPacked();
    _worldPacket >> timeSkipped;
}
