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
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "PacketUtilities.h"
#include "Unit.h"

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo& movementInfo)
{
    bool hasTransportData = !movementInfo.transport.guid.IsEmpty();
    bool hasFallDirection = movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
    bool hasFallData = hasFallDirection || movementInfo.jump.fallTime != 0;
    bool hasSpline = false; // todo 6.x send this infos

    data << movementInfo.guid;
    data << movementInfo.time;
    data << movementInfo.pos.PositionXYZOStream();
    data << movementInfo.pitch;
    data << movementInfo.splineElevation;

    uint32 removeMovementForcesCount = 0;
    data << removeMovementForcesCount;

    uint32 int168 = 0;
    data << int168;

    /*for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        data << ObjectGuid;
    }*/

    data.WriteBits(movementInfo.flags, 30);
    data.WriteBits(movementInfo.flags2, 15);

    data.WriteBit(hasTransportData);
    data.WriteBit(hasFallData);
    data.WriteBit(hasSpline);

    data.WriteBit(0); // HeightChangeFailed
    data.WriteBit(0); // RemoteTimeValid

    data.FlushBits();

    if (hasTransportData)
        data << movementInfo.transport;

    if (hasFallData)
    {
        data << movementInfo.jump.fallTime;
        data << movementInfo.jump.zspeed;

        data.WriteBit(hasFallDirection);
        data.FlushBits();
        if (hasFallDirection)
        {
            data << movementInfo.jump.sinAngle;
            data << movementInfo.jump.cosAngle;
            data << movementInfo.jump.xyspeed;
        }
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo)
{
    bool hasSpline = false;

    data >> movementInfo.guid;
    data >> movementInfo.time;
    data >> movementInfo.pos.PositionXYZOStream();
    data >> movementInfo.pitch;
    data >> movementInfo.splineElevation;

    uint32 removeMovementForcesCount;
    data >> removeMovementForcesCount;

    uint32 int168;
    data >> int168;

    for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        ObjectGuid guid;
        data >> guid;
    }

    movementInfo.flags = data.ReadBits(30);
    movementInfo.flags2 = data.ReadBits(15);

    bool hasTransport = data.ReadBit();
    bool hasFall = data.ReadBit();
    hasSpline = data.ReadBit(); // todo 6.x read this infos

    data.ReadBit(); // HeightChangeFailed
    data.ReadBit(); // RemoteTimeValid

    if (hasTransport)
        data >> movementInfo.transport;

    if (hasFall)
    {
        data >> movementInfo.jump.fallTime;
        data >> movementInfo.jump.zspeed;

        // ResetBitReader

        bool hasFallDirection = data.ReadBit();
        if (hasFallDirection)
        {
            data >> movementInfo.jump.sinAngle;
            data >> movementInfo.jump.cosAngle;
            data >> movementInfo.jump.xyspeed;
        }
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo::TransportInfo& transportInfo)
{
    data >> transportInfo.guid;                 // Transport Guid
    data >> transportInfo.pos.PositionXYZOStream();
    data >> transportInfo.seat;                 // VehicleSeatIndex
    data >> transportInfo.time;                 // MoveTime

    bool hasPrevTime = data.ReadBit();
    bool hasVehicleId = data.ReadBit();

    if (hasPrevTime)
        data >> transportInfo.prevTime;         // PrevMoveTime

    if (hasVehicleId)
        data >> transportInfo.vehicleId;        // VehicleRecID

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo::TransportInfo const& transportInfo)
{
    bool hasPrevTime = transportInfo.prevTime != 0;
    bool hasVehicleId = transportInfo.vehicleId != 0;

    data << transportInfo.guid;                 // Transport Guid
    data << transportInfo.pos.GetPositionX();
    data << transportInfo.pos.GetPositionY();
    data << transportInfo.pos.GetPositionZ();
    data << transportInfo.pos.GetOrientation();
    data << transportInfo.seat;                 // VehicleSeatIndex
    data << transportInfo.time;                 // MoveTime

    data.WriteBit(hasPrevTime);
    data.WriteBit(hasVehicleId);

    data.FlushBits();

    if (hasPrevTime)
        data << transportInfo.prevTime;         // PrevMoveTime

    if (hasVehicleId)
        data << transportInfo.vehicleId;        // VehicleRecID

    return data;
}

void WorldPackets::Movement::ClientPlayerMovement::Read()
{
    _worldPacket >> movementInfo;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MonsterSplineFilterKey const& monsterSplineFilterKey)
{
    data << monsterSplineFilterKey.Idx;
    data << monsterSplineFilterKey.Speed;

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MonsterSplineFilter const& monsterSplineFilter)
{
    data << uint32(monsterSplineFilter.FilterKeys.size());
    data << monsterSplineFilter.BaseSpeed;
    data << monsterSplineFilter.StartOffset;
    data << monsterSplineFilter.DistToPrevFilterKey;
    for (WorldPackets::Movement::MonsterSplineFilterKey const& filterKey : monsterSplineFilter.FilterKeys)
        data << filterKey;
    data << monsterSplineFilter.AddedToStart;
    data.WriteBits(monsterSplineFilter.FilterFlags, 2);
    data.FlushBits();

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline)
{
    data << movementSpline.Flags;
    data << movementSpline.AnimTier;
    data << movementSpline.TierTransStartTime;
    data << movementSpline.Elapsed;
    data << movementSpline.MoveTime;
    data << movementSpline.JumpGravity;
    data << movementSpline.SpecialTime;
    data << int32(movementSpline.Points.size());
    data << movementSpline.Mode;
    data << movementSpline.VehicleExitVoluntary;
    data << movementSpline.TransportGUID;
    data << movementSpline.VehicleSeat;
    data << int32(movementSpline.PackedDeltas.size());
    for (G3D::Vector3 const& pos : movementSpline.Points)
        data << pos;
    for (G3D::Vector3 const& pos : movementSpline.PackedDeltas)
        data.appendPackXYZ(pos.x, pos.y, pos.z);
    data.WriteBits(movementSpline.Face, 2);
    data.WriteBit(movementSpline.SplineFilter.HasValue);
    data.FlushBits();

    switch (movementSpline.Face)
    {
        case ::Movement::MONSTER_MOVE_FACING_SPOT:
            data << movementSpline.FaceSpot;
            break;
        case ::Movement::MONSTER_MOVE_FACING_TARGET:
            data << movementSpline.FaceDirection;
            data << movementSpline.FaceGUID;
            break;
        case ::Movement::MONSTER_MOVE_FACING_ANGLE:
            data << movementSpline.FaceDirection;
            break;
    }

    if (movementSpline.SplineFilter.HasValue)
        data << movementSpline.SplineFilter.Value;

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline)
{
    data << movementMonsterSpline.ID;
    data << movementMonsterSpline.Destination;
    data << movementMonsterSpline.Move;
    data.WriteBit(movementMonsterSpline.CrzTeleport);

    // Unk bits. 0 if monster is moving, 1 or 2 if stopped
    if (movementMonsterSpline.Move.Flags)
        data.WriteBits(0, 2);
    else
        data.WriteBits(2, 2);

    data.FlushBits();

    return data;
}

void WorldPackets::Movement::CommonMovement::WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data)
{
    data << uint32(moveSpline.GetId());                                         // ID

    if (!moveSpline.isCyclic())                                                 // Destination
        data << moveSpline.FinalDestination().xyz();
    else
        data << G3D::Vector3::zero();

    if (data.WriteBit(!moveSpline.Finalized()))                                 // MovementSplineMove
    {
        data.FlushBits();

        ::Movement::MoveSplineFlag const& splineFlags = moveSpline.splineflags;

        data.WriteBits(moveSpline.splineflags.raw(), 25);                       // SplineFlags

        uint8 face = ::Movement::MONSTER_MOVE_NORMAL;
        if (splineFlags.final_angle)
            face = ::Movement::MONSTER_MOVE_FACING_ANGLE;
        else if (splineFlags.final_target)
            face = ::Movement::MONSTER_MOVE_FACING_TARGET;
        else if (splineFlags.final_point)
            face = ::Movement::MONSTER_MOVE_FACING_SPOT;

        data.WriteBits(face, 2);                                                // Face

        bool HasJumpGravity = data.WriteBit(moveSpline.splineflags & (::Movement::MoveSplineFlag::Parabolic | ::Movement::MoveSplineFlag::Animation));                 // HasJumpGravity
        bool HasSpecialTime = data.WriteBit((moveSpline.splineflags & ::Movement::MoveSplineFlag::Parabolic) && moveSpline.effect_start_time < moveSpline.Duration()); // HasSpecialTime

        data.WriteBits(uint8(moveSpline.spline.mode()), 2);                     // Mode

        data.WriteBit(0);                                                       // HasSplineFilterKey

        data << int32(moveSpline.timePassed());                                 // Elapsed
        data << uint32(moveSpline.Duration());                                  // Duration
        data << float(1.0f);                                                    // DurationModifier
        data << float(1.0f);                                                    // NextDurationModifier

        uint32 PointsCount = moveSpline.getPath().size();
        data << uint32(PointsCount);

        switch (face)
        {
            case ::Movement::MONSTER_MOVE_FACING_SPOT:
                data << moveSpline.facing.f;        // FaceSpot
                break;
            case ::Movement::MONSTER_MOVE_FACING_TARGET:
                data << moveSpline.facing.target;   // FaceGUID
                break;
            case ::Movement::MONSTER_MOVE_FACING_ANGLE:
                data << moveSpline.facing.angle;    // FaceDirection
                break;
        }

        if (HasJumpGravity)
            data << float(moveSpline.vertical_acceleration);                    // JumpGravity

        if (HasSpecialTime)
            data << uint32(moveSpline.effect_start_time);                       // SpecialTime

        //if (HasSplineFilterKey)
        //{
        //    data << uint32(FilterKeysCount);
        //    for (var i = 0; i < PointsCount; ++i)
        //    {
        //        data << float(In);
        //        data << float(Out);
        //    }

        //    data.WriteBits(FilterFlags, 2);
        //}

        data.append<G3D::Vector3>(&moveSpline.getPath()[0], PointsCount);            // Points
    }
}

void WorldPackets::Movement::MonsterMove::InitializeSplineData(::Movement::MoveSpline const& moveSpline)
{
    SplineData.ID = moveSpline.m_Id;
    WorldPackets::Movement::MovementSpline& movementSpline = SplineData.Move;

    ::Movement::MoveSplineFlag splineFlags = moveSpline.splineflags;
    splineFlags.enter_cycle = moveSpline.isCyclic();
    movementSpline.Flags = uint32(splineFlags & uint32(~::Movement::MoveSplineFlag::Mask_No_Monster_Move));

    switch (moveSpline.splineflags & ::Movement::MoveSplineFlag::Mask_Final_Facing)
    {
        case ::Movement::MoveSplineFlag::Final_Point:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_SPOT;
            movementSpline.FaceSpot = moveSpline.facing.f;
            break;
        case ::Movement::MoveSplineFlag::Final_Target:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_TARGET;
            movementSpline.FaceGUID = moveSpline.facing.target;
            break;
        case ::Movement::MoveSplineFlag::Final_Angle:
            movementSpline.Face = ::Movement::MONSTER_MOVE_FACING_ANGLE;
            movementSpline.FaceDirection = moveSpline.facing.angle;
            break;
        default:
            movementSpline.Face = ::Movement::MONSTER_MOVE_NORMAL;
            break;
    }

    if (splineFlags.animation)
    {
        movementSpline.AnimTier = splineFlags.getAnimationId();
        movementSpline.TierTransStartTime = moveSpline.effect_start_time;
    }

    movementSpline.MoveTime = moveSpline.Duration();

    if (splineFlags.parabolic)
    {
        movementSpline.JumpGravity = moveSpline.vertical_acceleration;
        movementSpline.SpecialTime = moveSpline.effect_start_time;
    }

    ::Movement::Spline<int32> const& spline = moveSpline.spline;
    std::vector<G3D::Vector3> const& array = spline.getPoints();

    if (splineFlags & ::Movement::MoveSplineFlag::UncompressedPath)
    {
        if (!splineFlags.cyclic)
        {
            uint32 count = spline.getPointCount() - 3;
            for (uint32 i = 2; i < count; ++i)
                movementSpline.Points.push_back(array[i]);
        }
        else
        {
            uint32 count = spline.getPointCount() - 3;
            movementSpline.Points.push_back(array[1]);
            for (uint32 i = 1; i < count; ++i)
                movementSpline.Points.push_back(array[i]);
        }
    }
    else
    {
        uint32 lastIdx = spline.getPointCount() - 3;
        G3D::Vector3 const* realPath = &spline.getPoint(1);

        movementSpline.Points.push_back(realPath[lastIdx]);

        if (lastIdx > 1)
        {
            G3D::Vector3 middle = (realPath[0] + realPath[lastIdx]) / 2.f;

            // first and last points already appended
            for (uint32 i = 1; i < lastIdx; ++i)
                movementSpline.PackedDeltas.push_back(middle - realPath[i]);
        }
    }
}

WorldPacket const* WorldPackets::Movement::MonsterMove::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Pos;
    _worldPacket << SplineData;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSplineSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateSpeed::Write()
{
    _worldPacket << *movementInfo;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSplineSetFlag::Write()
{
    _worldPacket << MoverGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetFlag::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdate::Write()
{
    _worldPacket << *movementInfo;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::TransferPending::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket.WriteBit(Ship.HasValue);
    _worldPacket.WriteBit(TransferSpellID.HasValue);
    if (Ship.HasValue)
    {
        _worldPacket << uint32(Ship.Value.ID);
        _worldPacket << int32(Ship.Value.OriginMapID);
    }

    if (TransferSpellID.HasValue)
        _worldPacket << int32(TransferSpellID.Value);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::TransferAborted::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << uint8(Arg);
    _worldPacket.WriteBits(TransfertAbort, 5);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::NewWorld::Write()
{
    _worldPacket << MapID;
    _worldPacket << Pos.PositionXYZOStream();
    _worldPacket << Reason;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveTeleport::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << Pos.PositionXYZStream();
    _worldPacket << Facing;

    _worldPacket.WriteBit(TransportGUID.HasValue);
    _worldPacket.WriteBit(Vehicle.HasValue);
    _worldPacket.FlushBits();

    if (TransportGUID.HasValue)
        _worldPacket << TransportGUID.Value;

    if (Vehicle.HasValue)
    {
        _worldPacket << Vehicle.Value.VehicleSeatIndex;
        _worldPacket.WriteBit(Vehicle.Value.VehicleExitVoluntary);
        _worldPacket.WriteBit(Vehicle.Value.VehicleExitTeleport);
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateTeleport::Write()
{
    _worldPacket << *movementInfo;

    _worldPacket << int32(MovementForces.size());
    for (WorldPackets::Movement::MovementForce const& force : MovementForces)
    {
        _worldPacket << force.ID;
        _worldPacket << force.Direction;
        _worldPacket << force.TransportID;
        _worldPacket << force.Magnitude;
        _worldPacket.WriteBits(force.Type, 2);
        _worldPacket.FlushBits();
    }

    _worldPacket.WriteBit(WalkSpeed.HasValue);
    _worldPacket.WriteBit(RunSpeed.HasValue);
    _worldPacket.WriteBit(RunBackSpeed.HasValue);
    _worldPacket.WriteBit(SwimSpeed.HasValue);
    _worldPacket.WriteBit(SwimBackSpeed.HasValue);
    _worldPacket.WriteBit(FlightSpeed.HasValue);
    _worldPacket.WriteBit(FlightBackSpeed.HasValue);
    _worldPacket.WriteBit(TurnRate.HasValue);
    _worldPacket.WriteBit(PitchRate.HasValue);

    if (WalkSpeed.HasValue)
        _worldPacket << WalkSpeed.Value;

    if (RunSpeed.HasValue)
        _worldPacket << RunSpeed.Value;

    if (RunBackSpeed.HasValue)
        _worldPacket << RunBackSpeed.Value;

    if (SwimSpeed.HasValue)
        _worldPacket << SwimSpeed.Value;

    if (SwimBackSpeed.HasValue)
        _worldPacket << SwimBackSpeed.Value;

    if (FlightSpeed.HasValue)
        _worldPacket << FlightSpeed.Value;

    if (FlightBackSpeed.HasValue)
        _worldPacket << FlightBackSpeed.Value;

    if (TurnRate.HasValue)
        _worldPacket << TurnRate.Value;

    if (PitchRate.HasValue)
        _worldPacket << PitchRate.Value;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveTeleportAck::Read()
{
    _worldPacket >> MoverGUID;
    _worldPacket >> AckIndex;
    _worldPacket >> MoveTime;
}

ByteBuffer operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& ack)
{
    data >> ack.movementInfo;
    data >> ack.AckIndex;
    return data;
}

void WorldPackets::Movement::MovementAckMessage::Read()
{
    _worldPacket >> Ack;
}

void WorldPackets::Movement::MovementSpeedAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> Speed;
}

void WorldPackets::Movement::SetActiveMover::Read()
{
    _worldPacket >> ActiveMover;
}

WorldPacket const* WorldPackets::Movement::MoveSetActiveMover::Write()
{
    _worldPacket << MoverGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateKnockBack::Write()
{
    _worldPacket << *movementInfo;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetCollisionHeight::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << float(Height);
    _worldPacket << float(Scale);
    _worldPacket << uint32(MountDisplayID);
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateCollisionHeight::Write()
{
    _worldPacket << *movementInfo;
    _worldPacket << float(Scale);
    _worldPacket << float(Height);

    return &_worldPacket;
}

void WorldPackets::Movement::MoveSetCollisionHeightAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> Height;
    _worldPacket >> MountDisplayID;
    Reason = UpdateCollisionHeightReason(_worldPacket.ReadBits(2));
}
