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
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "UnitDefines.h"
#include "Util.h"

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

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineJumpExtraData const& jumpExtraData)
{
    data << float(jumpExtraData.JumpGravity);
    data << uint32(jumpExtraData.StartTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineAnimTierTransition const& animTierTransition)
{
    data << uint8(animTierTransition.AnimTier);
    data << uint32(animTierTransition.StartTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementSpline const& movementSpline)
{
    switch (movementSpline.Face)
    {
        case ::Movement::MONSTER_MOVE_FACING_TARGET:
            data << movementSpline.FaceGUID;
            break;
        case ::Movement::MONSTER_MOVE_FACING_ANGLE:
            data << float(movementSpline.FaceDirection);
            break;
        case ::Movement::MONSTER_MOVE_FACING_SPOT:
            data << movementSpline.FaceSpot;
            break;
        default:
            break;
    }

    data << uint32(movementSpline.Flags);

    if (movementSpline.AnimTierTransition)
        data << *movementSpline.AnimTierTransition;

    data << uint32(movementSpline.MoveTime);

    if (movementSpline.JumpExtraData)
        data << *movementSpline.JumpExtraData;

    data << uint32(movementSpline.Points.size() + movementSpline.PackedDeltas.size());

    for (TaggedPosition<Position::XYZ> const& pos : movementSpline.Points)
        data << pos;

    for (TaggedPosition<Position::PackedXYZ> const& pos : movementSpline.PackedDeltas)
        data << pos;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementMonsterSpline const& movementMonsterSpline)
{
    data << uint32(movementMonsterSpline.ID);
    data << uint8(movementMonsterSpline.Move.Face);

    if (movementMonsterSpline.Move.Face != ::Movement::MONSTER_MOVE_STOP)
        data << movementMonsterSpline.Move;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementSplineTransport const& splineTransport)
{
    data << splineTransport.TransportGUID.WriteAsPacked();
    data << int8(splineTransport.VehicleSeat);

    return data;
}

void CommonMovement::WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data)
{
    G3D::Vector3 dest = moveSpline.isCyclic() ? G3D::Vector3::zero() : moveSpline.FinalDestination();

    data << uint32(moveSpline.splineflags.raw());                               // SplineFlags

    if (moveSpline.splineflags.final_angle)
        data << moveSpline.facing.angle;                                        // FaceDirection
    else if (moveSpline.splineflags.final_target)
        data << moveSpline.facing.target;                                       // FaceGUID
    else if (moveSpline.splineflags.final_point)
    {
        data << float(moveSpline.facing.f.x);                                   // FaceSpot
        data << float(moveSpline.facing.f.y);
        data << float(moveSpline.facing.f.z);
    }

    data << int32(moveSpline.timePassed());                                     // Elapsed
    data << uint32(moveSpline.Duration());                                      // Duration
    data << uint32(moveSpline.GetId());                                         // ID

    data << float(1.0f);                                                        // DurationModifier
    data << float(1.0f);                                                        // NextDurationModifier

    data << float(moveSpline.vertical_acceleration);
    data << uint32(moveSpline.effect_start_time);

    data << uint32(moveSpline.getPath().size());
    data.append(reinterpret_cast<float const*>(moveSpline.getPath().data()), moveSpline.getPath().size() * 3);
    data << uint8(moveSpline.spline.mode());                                    // Mode
    data << dest.x << dest.y << dest.z;                                         // Destination
}

void MonsterMove::InitializeSplineData(::Movement::MoveSpline const& moveSpline)
{
    SplineData.ID = moveSpline.m_Id;
    MovementSpline& movementSpline = SplineData.Move;

    ::Movement::MoveSplineFlag splineFlags = moveSpline.splineflags;
    movementSpline.Flags = uint32(splineFlags & ~::Movement::MoveSplineFlag::Mask_No_Monster_Move);
    switch (splineFlags & ::Movement::MoveSplineFlag::Mask_Final_Facing)
    {
        case ::Movement::MoveSplineFlag::Final_Target:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_TARGET;
            movementSpline.FaceGUID = moveSpline.facing.target;
            break;
        case ::Movement::MoveSplineFlag::Final_Angle:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_ANGLE;
            movementSpline.FaceDirection = moveSpline.facing.angle;
            break;
        case ::Movement::MoveSplineFlag::Final_Point:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_SPOT;
            movementSpline.FaceSpot = Position(moveSpline.facing.f.x, moveSpline.facing.f.y, moveSpline.facing.f.z);
            break;
        default:
            movementSpline.Face = ::Movement::MONSTER_MOVE_NORMAL;
            break;
    }

    if (splineFlags.animation)
    {
        movementSpline.AnimTierTransition.emplace();
        movementSpline.AnimTierTransition->StartTime = moveSpline.effect_start_time;
        movementSpline.AnimTierTransition->AnimTier = AsUnderlyingType(moveSpline.GetAnimTier());
    }

    movementSpline.MoveTime = moveSpline.Duration();

    if (splineFlags.parabolic)
    {
        movementSpline.JumpExtraData.emplace();
        movementSpline.JumpExtraData->JumpGravity = moveSpline.vertical_acceleration;
        movementSpline.JumpExtraData->StartTime = moveSpline.effect_start_time;
    }

    ::Movement::Spline<int32> const& spline = moveSpline.spline;
    std::vector<G3D::Vector3> const& array = spline.getPoints();

    if (splineFlags & ::Movement::MoveSplineFlag::Mask_CatmullRom)
    {
        uint32 count = spline.getPointCount() - (splineFlags.cyclic ? 4 : 3);
        for (uint32 i = 0; i < count; ++i)
            movementSpline.Points.emplace_back(array[i + 2].x, array[i + 2].y, array[i + 2].z);
    }
    else
    {
        uint32 lastIdx = spline.getPointCount() - 3;
        G3D::Vector3 const* realPath = &array[1];

        movementSpline.Points.emplace_back(realPath[lastIdx].x, realPath[lastIdx].y, realPath[lastIdx].z);

        if (lastIdx > 1)
        {
            G3D::Vector3 middle = (realPath[0] + realPath[lastIdx]) / 2.f;

            // first and last points already appended
            for (uint32 i = 1; i < lastIdx; ++i)
            {
                G3D::Vector3 delta = middle - realPath[i];
                movementSpline.PackedDeltas.emplace_back(delta.x, delta.y, delta.z);
            }
        }
    }
}

WorldPacket const* MonsterMove::Write()
{
    _worldPacket << MoverGUID.WriteAsPacked();
    if (Transport)
    {
        _worldPacket.SetOpcode(SMSG_MONSTER_MOVE_TRANSPORT);
        _worldPacket << *Transport;
    }

    _worldPacket << uint8(VehicleExitVoluntary);
    _worldPacket << Pos;
    _worldPacket << SplineData;

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

WorldPacket const* TransferPending::Write()
{
    _worldPacket << int32(MapID);
    if (Ship)
    {
        _worldPacket << uint32(Ship->ID);
        _worldPacket << int32(Ship->OriginMapID);
    }

    return &_worldPacket;
}

WorldPacket const* TransferAborted::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << uint8(TransfertAbort);
    switch (TransfertAbort)
    {
        case TRANSFER_ABORT_INSUF_EXPAN_LVL:
        case TRANSFER_ABORT_DIFFICULTY:
        case TRANSFER_ABORT_UNIQUE_MESSAGE:
            _worldPacket << uint8(Arg);
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPacket const* NewWorld::Write()
{
    _worldPacket << MapID;
    _worldPacket << Pos.PositionXYZOStream();

    return &_worldPacket;
}
}
