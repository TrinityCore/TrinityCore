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
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "PacketUtilities.h"
#include "Unit.h"

WorldPacket const* WorldPackets::Movement::TransferPending::Write()
{
    _worldPacket.WriteBit(TransferSpellID.has_value());
    _worldPacket.WriteBit(Ship.has_value());
    if (Ship)
    {
        _worldPacket << int32(Ship->OriginMapID);
        _worldPacket << uint32(Ship->ID);
    }

    if (TransferSpellID)
        _worldPacket << int32(*TransferSpellID);

    _worldPacket << int32(MapID);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::SuspendToken::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket.WriteBit(Reason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Movement::SuspendTokenResponse::Read()
{
    _worldPacket >> SequenceIndex;
}

WorldPacket const* WorldPackets::Movement::NewWorld::Write()
{
    _worldPacket << Pos.GetPositionX();
    _worldPacket << Pos.GetOrientation();
    _worldPacket << Pos.GetPositionZ();
    _worldPacket << int32(MapID);
    _worldPacket << Pos.GetPositionY();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetCollisionHeight::Write()
{
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.WriteBit(MoverGUID[6]);
    _worldPacket.WriteBit(MoverGUID[1]);
    _worldPacket.WriteBit(MoverGUID[4]);
    _worldPacket.WriteBit(MoverGUID[7]);
    _worldPacket.WriteBit(MoverGUID[5]);
    _worldPacket.WriteBit(MoverGUID[2]);
    _worldPacket.WriteBit(MoverGUID[0]);
    _worldPacket.WriteBit(MoverGUID[3]);

    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(MoverGUID[6]);
    _worldPacket.WriteByteSeq(MoverGUID[0]);
    _worldPacket.WriteByteSeq(MoverGUID[4]);
    _worldPacket.WriteByteSeq(MoverGUID[3]);
    _worldPacket.WriteByteSeq(MoverGUID[5]);

    _worldPacket << uint32(SequenceIndex);

    _worldPacket.WriteByteSeq(MoverGUID[1]);
    _worldPacket.WriteByteSeq(MoverGUID[2]);
    _worldPacket.WriteByteSeq(MoverGUID[7]);

    _worldPacket << float(Height);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveKnockBack::Write()
{
    _worldPacket.WriteBit(MoverGUID[0]);
    _worldPacket.WriteBit(MoverGUID[3]);
    _worldPacket.WriteBit(MoverGUID[6]);
    _worldPacket.WriteBit(MoverGUID[7]);
    _worldPacket.WriteBit(MoverGUID[2]);
    _worldPacket.WriteBit(MoverGUID[5]);
    _worldPacket.WriteBit(MoverGUID[1]);
    _worldPacket.WriteBit(MoverGUID[4]);

    _worldPacket.WriteByteSeq(MoverGUID[1]);

    _worldPacket << float(Direction.Pos.GetPositionY());
    _worldPacket << int32(SequenceIndex);

    _worldPacket.WriteByteSeq(MoverGUID[6]);
    _worldPacket.WriteByteSeq(MoverGUID[7]);

    _worldPacket << float(Speeds.HorzSpeed);

    _worldPacket.WriteByteSeq(MoverGUID[4]);
    _worldPacket.WriteByteSeq(MoverGUID[5]);
    _worldPacket.WriteByteSeq(MoverGUID[3]);

    _worldPacket << float(Speeds.VertSpeed);
    _worldPacket << float(Direction.Pos.GetPositionX());

    _worldPacket.WriteByteSeq(MoverGUID[2]);
    _worldPacket.WriteByteSeq(MoverGUID[0]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveTeleport::Write()
{
    _worldPacket.WriteBit(MoverGUID[6]);
    _worldPacket.WriteBit(MoverGUID[0]);
    _worldPacket.WriteBit(MoverGUID[3]);
    _worldPacket.WriteBit(MoverGUID[2]);

    _worldPacket.WriteBit(Vehicle.has_value());
    if (Vehicle)
    {
        _worldPacket.WriteBit(Vehicle->VehicleExitVoluntary);
        _worldPacket.WriteBit(Vehicle->VehicleExitTeleport);
    }

    _worldPacket.WriteBit(TransportGUID.has_value());
    _worldPacket.WriteBit(MoverGUID[1]);

    if (TransportGUID.has_value())
    {
        ObjectGuid transGUID = TransportGUID.value();
        _worldPacket.WriteBit(transGUID[1]);
        _worldPacket.WriteBit(transGUID[3]);
        _worldPacket.WriteBit(transGUID[2]);
        _worldPacket.WriteBit(transGUID[5]);
        _worldPacket.WriteBit(transGUID[0]);
        _worldPacket.WriteBit(transGUID[7]);
        _worldPacket.WriteBit(transGUID[6]);
        _worldPacket.WriteBit(transGUID[4]);
    }

    _worldPacket.WriteBit(MoverGUID[4]);
    _worldPacket.WriteBit(MoverGUID[7]);
    _worldPacket.WriteBit(MoverGUID[5]);

    _worldPacket.FlushBits();

    if (TransportGUID.has_value())
    {
        ObjectGuid transGUID = TransportGUID.value();
        _worldPacket.WriteByteSeq(transGUID[5]);
        _worldPacket.WriteByteSeq(transGUID[6]);
        _worldPacket.WriteByteSeq(transGUID[1]);
        _worldPacket.WriteByteSeq(transGUID[7]);
        _worldPacket.WriteByteSeq(transGUID[0]);
        _worldPacket.WriteByteSeq(transGUID[2]);
        _worldPacket.WriteByteSeq(transGUID[4]);
        _worldPacket.WriteByteSeq(transGUID[3]);
    }

    _worldPacket << uint32(SequenceIndex);
    _worldPacket.WriteByteSeq(MoverGUID[1]);
    _worldPacket.WriteByteSeq(MoverGUID[2]);
    _worldPacket.WriteByteSeq(MoverGUID[3]);
    _worldPacket.WriteByteSeq(MoverGUID[5]);
    _worldPacket << float(Pos.Pos.GetPositionX());
    _worldPacket.WriteByteSeq(MoverGUID[4]);
    _worldPacket << float(Facing);
    _worldPacket.WriteByteSeq(MoverGUID[7]);
    _worldPacket << float(Pos.Pos.GetPositionZ());

    if (Vehicle)
        _worldPacket << uint32(Vehicle->VehicleSeatIndex);

    _worldPacket.WriteByteSeq(MoverGUID[0]);
    _worldPacket.WriteByteSeq(MoverGUID[6]);

    _worldPacket << float(Pos.Pos.GetPositionY());

    return &_worldPacket;
}

void WorldPackets::Movement::MoveTeleportAck::Read()
{
    _worldPacket >> AckIndex;
    _worldPacket >> MoveTime;

    MoverGUID[5] = _worldPacket.ReadBit();
    MoverGUID[0] = _worldPacket.ReadBit();
    MoverGUID[1] = _worldPacket.ReadBit();
    MoverGUID[6] = _worldPacket.ReadBit();
    MoverGUID[3] = _worldPacket.ReadBit();
    MoverGUID[7] = _worldPacket.ReadBit();
    MoverGUID[2] = _worldPacket.ReadBit();
    MoverGUID[4] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(MoverGUID[4]);
    _worldPacket.ReadByteSeq(MoverGUID[2]);
    _worldPacket.ReadByteSeq(MoverGUID[7]);
    _worldPacket.ReadByteSeq(MoverGUID[6]);
    _worldPacket.ReadByteSeq(MoverGUID[5]);
    _worldPacket.ReadByteSeq(MoverGUID[1]);
    _worldPacket.ReadByteSeq(MoverGUID[3]);
    _worldPacket.ReadByteSeq(MoverGUID[0]);
}

void WorldPackets::Movement::SetActiveMover::Read()
{
    ActiveMover[7] = _worldPacket.ReadBit();
    ActiveMover[2] = _worldPacket.ReadBit();
    ActiveMover[1] = _worldPacket.ReadBit();
    ActiveMover[0] = _worldPacket.ReadBit();
    ActiveMover[4] = _worldPacket.ReadBit();
    ActiveMover[5] = _worldPacket.ReadBit();
    ActiveMover[6] = _worldPacket.ReadBit();
    ActiveMover[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(ActiveMover[3]);
    _worldPacket.ReadByteSeq(ActiveMover[2]);
    _worldPacket.ReadByteSeq(ActiveMover[4]);
    _worldPacket.ReadByteSeq(ActiveMover[0]);
    _worldPacket.ReadByteSeq(ActiveMover[5]);
    _worldPacket.ReadByteSeq(ActiveMover[1]);
    _worldPacket.ReadByteSeq(ActiveMover[6]);
    _worldPacket.ReadByteSeq(ActiveMover[7]);
}

WorldPacket const* WorldPackets::Movement::MoveUpdateTeleport::Write()
{
    _worldPacket << float(Status->pos.GetPositionZ());
    _worldPacket << float(Status->pos.GetPositionY());
    _worldPacket << float(Status->pos.GetPositionX());

    _worldPacket.WriteBit(!Status->HasOrientation());
    _worldPacket.WriteBit(Status->HasSpline());
    _worldPacket.WriteBit(!Status->HasMovementFlags());
    _worldPacket.WriteBit(Status->guid[2]);
    _worldPacket.WriteBit(Status->guid[4]);
    _worldPacket.WriteBit(Status->guid[6]);
    _worldPacket.WriteBit(Status->HasFallData());
    _worldPacket.WriteBit(Status->guid[0]);
    _worldPacket.WriteBit(Status->HasTransportData());
    _worldPacket.WriteBit(Status->guid[5]);

    if (Status->HasTransportData())
    {
        _worldPacket.WriteBit(Status->transport.guid[1]);
        _worldPacket.WriteBit(Status->transport.guid[4]);
        _worldPacket.WriteBit(Status->transport.guid[5]);
        _worldPacket.WriteBit(Status->transport.guid[3]);
        _worldPacket.WriteBit(Status->transport.guid[0]);
        _worldPacket.WriteBit(Status->HasTransportTime2());
        _worldPacket.WriteBit(Status->transport.guid[7]);
        _worldPacket.WriteBit(Status->transport.guid[6]);
        _worldPacket.WriteBit(Status->HasTransportVehicleId());
        _worldPacket.WriteBit(Status->transport.guid[2]);
    }

    _worldPacket.WriteBit(Status->HasHeightChangeFailed());
    _worldPacket.WriteBit(Status->guid[7]);
    _worldPacket.WriteBit(Status->guid[3]);

    _worldPacket.WriteBit(!Status->HasPitch());
    _worldPacket.WriteBit(!Status->HasExtraMovementFlags());
    _worldPacket.WriteBit(!Status->HasTime());

    if (Status->HasFallData())
        _worldPacket.WriteBit(Status->HasFallDirection());

    if (Status->HasExtraMovementFlags())
        _worldPacket.WriteBits(Status->GetExtraMovementFlags(), 12);

    _worldPacket.WriteBit(!Status->HasSplineElevation());

    if (Status->HasMovementFlags())
        _worldPacket.WriteBits(Status->GetMovementFlags(), 30);

    _worldPacket.WriteBit(Status->guid[1]);
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(Status->guid[7]);

    if (Status->HasTransportData())
    {
        _worldPacket.WriteByteSeq(Status->transport.guid[3]);
        _worldPacket.WriteByteSeq(Status->transport.guid[4]);
        _worldPacket << float(Status->transport.pos.GetOrientation());

        if (Status->HasTransportVehicleId())
            _worldPacket << uint32(Status->transport.vehicleId);

        _worldPacket.WriteByteSeq(Status->transport.guid[1]);

        if (Status->HasTransportTime2())
            _worldPacket << uint32(Status->transport.time2);

        _worldPacket << float(Status->transport.pos.GetPositionZ());

        _worldPacket.WriteByteSeq(Status->transport.guid[7]);
        _worldPacket.WriteByteSeq(Status->transport.guid[0]);
        _worldPacket.WriteByteSeq(Status->transport.guid[6]);
        _worldPacket.WriteByteSeq(Status->transport.guid[5]);
        _worldPacket.WriteByteSeq(Status->transport.guid[2]);

        _worldPacket << int8(Status->transport.seat);
        _worldPacket << uint32(Status->transport.time);
        _worldPacket << float(Status->transport.pos.GetPositionY());
        _worldPacket << float(Status->transport.pos.GetPositionX());
    }

    _worldPacket.WriteByteSeq(Status->guid[6]);

    if (Status->HasPitch())
        _worldPacket << float(Status->pitch);

    if (Status->HasSplineElevation())
        _worldPacket << float(Status->splineElevation);

    if (Status->HasOrientation())
        _worldPacket << float(Status->pos.GetOrientation());

    _worldPacket.WriteByteSeq(Status->guid[2]);
    _worldPacket.WriteByteSeq(Status->guid[3]);
    _worldPacket.WriteByteSeq(Status->guid[1]);

    if (Status->HasFallData())
    {
        _worldPacket << uint32(Status->GetFallTime());

        if (Status->HasFallDirection())
        {
            _worldPacket << float(Status->jump.xyspeed);
            _worldPacket << float(Status->jump.cosAngle);
            _worldPacket << float(Status->jump.sinAngle);
        }

        _worldPacket << float(Status->jump.zspeed);
    }

    _worldPacket.WriteByteSeq(Status->guid[5]);
    _worldPacket.WriteByteSeq(Status->guid[4]);

    if (Status->HasTime())
        _worldPacket << uint32(Status->time);

    _worldPacket.WriteByteSeq(Status->guid[0]);

    return &_worldPacket;
}

void WorldPackets::Movement::MonsterMove::InitializeSplineData(::Movement::MoveSpline const& moveSpline)
{
    SplineData.ID = moveSpline.m_Id;
    WorldPackets::Movement::MovementSpline& movementSpline = SplineData.Move;

    ::Movement::MoveSplineFlag splineFlags = moveSpline.splineflags;
    splineFlags.enter_cycle = moveSpline.isCyclic();
    movementSpline.Flags = uint32(splineFlags & uint32(~::Movement::MoveSplineFlag::Mask_No_Monster_Move));
    movementSpline.Face = moveSpline.facing.type;
    movementSpline.FaceDirection = moveSpline.facing.angle;
    movementSpline.FaceGUID = moveSpline.facing.target;
    movementSpline.FaceSpot = Position(moveSpline.facing.f.x, moveSpline.facing.f.y, moveSpline.facing.f.z);

    if (splineFlags.animation)
    {
        movementSpline.Animation.emplace();
        movementSpline.Animation->TierTransStartTime = moveSpline.effect_start_time;
        movementSpline.Animation->AnimTier = AsUnderlyingType(*moveSpline.anim_tier);
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

    if (splineFlags & ::Movement::MoveSplineFlag::UncompressedPath)
    {
        uint32 count = spline.getPointCount() - (!splineFlags.cyclic ? 3 : 4);
        for (uint32 i = 0; i < count; ++i)
            movementSpline.Points.emplace_back(array[i + 2].x, array[i + 2].y, array[i + 2].z);
    }
    else
    {
        uint32 lastIdx = spline.getPointCount() - 3;
        G3D::Vector3 const* realPath = &spline.getPoint(1);

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

WorldPacket const* WorldPackets::Movement::MonsterMove::Write()
{
    _worldPacket << MoverGUID.WriteAsPacked();

    if (_worldPacket.GetOpcode() == SMSG_ON_MONSTER_MOVE_TRANSPORT)
    {
        _worldPacket << SplineData.Move.TransportGUID.WriteAsPacked();
        _worldPacket << int8(SplineData.Move.VehicleSeat);
    }

    _worldPacket << int8(SplineData.Move.VehicleExitVoluntary);
    _worldPacket << Pos;
    _worldPacket << SplineData;
    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineJumpExtraData const& jumpExtraData)
{
    data << float(jumpExtraData.JumpGravity);
    data << int32(jumpExtraData.StartTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineAnimationExtraData const& animationExtraData)
{
    data << int8(animationExtraData.AnimTier);
    data << int32(animationExtraData.TierTransStartTime);

    return data;
}

WorldPacket const* WorldPackets::Movement::FlightSplineSync::Write()
{
    _worldPacket << float(SplineDist);
    _worldPacket << Guid.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::TransferAborted::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << uint8(TransfertAbort);
    _worldPacket << uint8(Arg);

    return &_worldPacket;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline)
{
    data << int8(movementSpline.Face);

    switch (movementSpline.Face)
    {
        case ::Movement::MONSTER_MOVE_FACING_SPOT:
            data << movementSpline.FaceSpot;
            break;
        case ::Movement::MONSTER_MOVE_FACING_TARGET:
            data << movementSpline.FaceGUID;
            break;
        case ::Movement::MONSTER_MOVE_FACING_ANGLE:
            data << float(movementSpline.FaceDirection);
            break;
    }

    data << int32(movementSpline.Flags);

    if (movementSpline.Animation)
        data << *movementSpline.Animation;

    data << int32(movementSpline.MoveTime);

    if (movementSpline.JumpExtraData)
        data << *movementSpline.JumpExtraData;

    data << int32(movementSpline.Points.size() + movementSpline.PackedDeltas.size());
    for (TaggedPosition<Position::XYZ> const& pos : movementSpline.Points)
        data << pos;
    for (TaggedPosition<Position::PackedXYZ> const& pos : movementSpline.PackedDeltas)
        data << pos;

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline)
{
    data << int32(movementMonsterSpline.ID);
    data << movementMonsterSpline.Move;

    return data;
}

WorldPacket const* WorldPackets::Movement::MoveSetActiveMover::Write()
{
    _worldPacket.WriteBit(MoverGUID[5]);
    _worldPacket.WriteBit(MoverGUID[7]);
    _worldPacket.WriteBit(MoverGUID[3]);
    _worldPacket.WriteBit(MoverGUID[6]);
    _worldPacket.WriteBit(MoverGUID[0]);
    _worldPacket.WriteBit(MoverGUID[4]);
    _worldPacket.WriteBit(MoverGUID[1]);
    _worldPacket.WriteBit(MoverGUID[2]);

    _worldPacket.WriteByteSeq(MoverGUID[6]);
    _worldPacket.WriteByteSeq(MoverGUID[2]);
    _worldPacket.WriteByteSeq(MoverGUID[3]);
    _worldPacket.WriteByteSeq(MoverGUID[0]);
    _worldPacket.WriteByteSeq(MoverGUID[5]);
    _worldPacket.WriteByteSeq(MoverGUID[7]);
    _worldPacket.WriteByteSeq(MoverGUID[1]);
    _worldPacket.WriteByteSeq(MoverGUID[4]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetVehicleRecID::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << int32(VehicleRecID);

    _worldPacket.WriteBit(MoverGUID[3]);
    _worldPacket.WriteBit(MoverGUID[0]);
    _worldPacket.WriteBit(MoverGUID[1]);
    _worldPacket.WriteBit(MoverGUID[7]);
    _worldPacket.WriteBit(MoverGUID[2]);
    _worldPacket.WriteBit(MoverGUID[6]);
    _worldPacket.WriteBit(MoverGUID[5]);
    _worldPacket.WriteBit(MoverGUID[4]);

    _worldPacket.WriteByteSeq(MoverGUID[5]);
    _worldPacket.WriteByteSeq(MoverGUID[7]);
    _worldPacket.WriteByteSeq(MoverGUID[4]);
    _worldPacket.WriteByteSeq(MoverGUID[3]);
    _worldPacket.WriteByteSeq(MoverGUID[2]);
    _worldPacket.WriteByteSeq(MoverGUID[6]);
    _worldPacket.WriteByteSeq(MoverGUID[1]);
    _worldPacket.WriteByteSeq(MoverGUID[0]);

    return &_worldPacket;
}
