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
#include "MovementPacketBuilder.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "Position.h"
#include "UnitDefines.h"

ByteBuffer& operator << (ByteBuffer& data, const G3D::Vector3& v)
{
    data << v.x << v.y << v.z;
    return data;
}

ByteBuffer& operator >> (ByteBuffer& data, G3D::Vector3& v)
{
    data >> v.x >> v.y >> v.z;
    return data;
}

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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementSpline const& movementSpline)
{
    data << uint8(movementSpline.Face);
    switch (movementSpline.Face)
    {
        case MONSTER_MOVE_FACING_SPOT:
            data << movementSpline.FaceSpot;
            break;
        case MONSTER_MOVE_FACING_TARGET:
            data << movementSpline.FaceGUID;
            break;
        case MONSTER_MOVE_FACING_ANGLE:
            data << float(movementSpline.FaceDirection);
            break;
        default:
            break;
    }

    data << uint32(movementSpline.Flags);

    if (movementSpline.Flags & ::Movement::MoveSplineFlag::Animation)
    {
        data << uint8(movementSpline.AnimTier);
        data << uint32(movementSpline.TierTransStartTime);
    }

    data << uint32(movementSpline.MoveTime);

    if (movementSpline.Flags & ::Movement::MoveSplineFlag::Parabolic)
    {
        data << float(movementSpline.JumpGravity);
        data << uint32(movementSpline.SpecialTime);
    }

    if (movementSpline.Flags & ::Movement::MoveSplineFlag::Mask_CatmullRom)
    {
        data << uint32(movementSpline.Points.size());
        for (G3D::Vector3 const& point : movementSpline.Points)
            data << point;
    }
    else
    {
        // Linear path: Points[0] = destination, PackedDeltas = intermediate offsets
        uint32 lastIdx = uint32(movementSpline.PackedDeltas.size()) + 1;
        data << uint32(lastIdx);
        if (!movementSpline.Points.empty())
            data << movementSpline.Points.front();
        for (G3D::Vector3 const& offset : movementSpline.PackedDeltas)
            data << TaggedPosition<Position::PackedXYZ>(offset.x, offset.y, offset.z);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementMonsterSpline const& movementMonsterSpline)
{
    if (!movementMonsterSpline.TransportGUID.IsEmpty())
    {
        data << movementMonsterSpline.TransportGUID.WriteAsPacked();
        data << int8(movementMonsterSpline.VehicleSeat);
    }

    data << uint8(0);                                       // sets/unsets MOVEMENTFLAG2_UNK7 (0x40)
    data << movementMonsterSpline.Destination;
    data << uint32(movementMonsterSpline.ID);
    data << movementMonsterSpline.Move;
    return data;
}

namespace WorldPackets::Movement
{
void ClientPlayerMovement::Read()
{
    _worldPacket >> Status.guid.ReadAsPacked();
    _worldPacket >> Status;
}

WorldPacket const* MonsterMove::Write()
{
    _worldPacket << MoverGUID.WriteAsPacked();

    if (!SplineData.TransportGUID.IsEmpty())
        _worldPacket.SetOpcode(SMSG_MONSTER_MOVE_TRANSPORT);

    _worldPacket << SplineData;

    return &_worldPacket;
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
}
