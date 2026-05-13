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

#include "MovementPackets.h"
#include "UnitDefines.h"

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo)
{
    data << uint32(movementInfo.flags);
    data << uint16(movementInfo.flags2);
    data << uint32(movementInfo.time);
    data << movementInfo.pos.PositionXYZOStream();

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        data << movementInfo.transport.guid.WriteAsPacked();
        data << movementInfo.transport.pos.PositionXYZOStream();
        data << uint32(movementInfo.transport.time);
        data << int8(movementInfo.transport.seat);

        if (movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
            data << uint32(movementInfo.transport.time2);
    }

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING) || movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        data << float(movementInfo.pitch);

    data << uint32(movementInfo.fallTime);

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
    {
        data << float(movementInfo.jump.zspeed);
        data << float(movementInfo.jump.sinAngle);
        data << float(movementInfo.jump.cosAngle);
        data << float(movementInfo.jump.xyspeed);
    }

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
        data << float(movementInfo.splineElevation);

    return data;
}

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

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING) || movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
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

namespace WorldPackets::Movement
{
void ClientPlayerMovement::Read()
{
    _worldPacket >> Status.guid.ReadAsPacked();
    _worldPacket >> Status;
}

WorldPacket const* MoveUpdate::Write()
{
    _worldPacket << Status->guid.WriteAsPacked();
    _worldPacket << *Status;

    return &_worldPacket;
}

WorldPacket const* FlightSplineSync::Write()
{
    _worldPacket << float(SplineDist);
    _worldPacket << Guid.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* MoveSplineSetSpeed::Write()
{
    _worldPacket << MoverGUID.WriteAsPacked();
    _worldPacket << float(Speed);

    return &_worldPacket;
}

WorldPacket const* MoveSetSpeed::Write()
{
    _worldPacket << MoverGUID.WriteAsPacked();
    _worldPacket << uint32(SequenceIndex);
    if (GetOpcode() == SMSG_FORCE_RUN_SPEED_CHANGE)
        _worldPacket << uint8(Unknown);

    _worldPacket << float(Speed);

    return &_worldPacket;
}

WorldPacket const* MoveUpdateSpeed::Write()
{
    _worldPacket << Status->guid.WriteAsPacked();
    _worldPacket << *Status;
    _worldPacket << float(Speed);

    return &_worldPacket;
}

WorldPacket const* NewWorld::Write()
{
    _worldPacket << MapID;
    _worldPacket << Pos.PositionXYZOStream();

    return &_worldPacket;
}
}
