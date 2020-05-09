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

WorldPacket const* WorldPackets::Movement::MoveUpdate::Write()
{
    ObjectGuid guid = Status->guid;
    ObjectGuid transportGuid = Status->transport.guid;

    _worldPacket.WriteBit(Status->HasFallData());
    _worldPacket.WriteBit(guid[3]);
    _worldPacket.WriteBit(guid[6]);
    _worldPacket.WriteBit(!Status->HasExtraMovementFlags());
    _worldPacket.WriteBit(Status->HasSpline());
    _worldPacket.WriteBit(!Status->HasTime());
    _worldPacket.WriteBit(guid[0]);
    _worldPacket.WriteBit(guid[1]);

    if (Status->HasExtraMovementFlags())
        _worldPacket.WriteBits(Status->GetExtraMovementFlags(), 12);

    _worldPacket.WriteBit(guid[7]);
    _worldPacket.WriteBit(!Status->HasMovementFlags());
    _worldPacket.WriteBit(!Status->HasOrientation());
    _worldPacket.WriteBit(guid[2]);
    _worldPacket.WriteBit(!Status->HasSplineElevation());
    _worldPacket.WriteBit(Status->HasHeightChangeFailed());
    _worldPacket.WriteBit(guid[4]);

    if (Status->HasFallData())
        _worldPacket.WriteBit(Status->HasFallDirection());

    _worldPacket.WriteBit(guid[5]);
    _worldPacket.WriteBit(Status->HasTransportData());
    if (Status->HasMovementFlags())
        _worldPacket.WriteBits(Status->GetMovementFlags(), 30);

    if (Status->HasTransportData())
    {
        _worldPacket.WriteBit(transportGuid[3]);
        _worldPacket.WriteBit(Status->HasTransportVehicleId());
        _worldPacket.WriteBit(transportGuid[6]);
        _worldPacket.WriteBit(transportGuid[1]);
        _worldPacket.WriteBit(transportGuid[7]);
        _worldPacket.WriteBit(transportGuid[0]);
        _worldPacket.WriteBit(transportGuid[4]);
        _worldPacket.WriteBit(Status->HasTransportTime2());
        _worldPacket.WriteBit(transportGuid[5]);
        _worldPacket.WriteBit(transportGuid[2]);
    }

    _worldPacket.WriteBit(!Status->HasPitch());
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(guid[5]);

    if (Status->HasFallData())
    {
        if (Status->HasFallDirection())
        {
            _worldPacket << float(Status->jump.xyspeed);
            _worldPacket << float(Status->jump.sinAngle);
            _worldPacket << float(Status->jump.cosAngle);
        }

        _worldPacket << float(Status->jump.zspeed);
        _worldPacket << uint32(Status->jump.fallTime);
    }

    if (Status->HasSplineElevation())
        _worldPacket << float(Status->splineElevation);

    _worldPacket.WriteByteSeq(guid[7]);
    _worldPacket << float(Status->pos.GetPositionY());
    _worldPacket.WriteByteSeq(guid[3]);

    if (Status->HasTransportData())
    {
        if (Status->HasTransportVehicleId())
            _worldPacket << uint32(Status->transport.vehicleId);

        _worldPacket.WriteByteSeq(transportGuid[6]);
        _worldPacket << int8(Status->transport.seat);
        _worldPacket.WriteByteSeq(transportGuid[5]);
        _worldPacket << float(Status->transport.pos.GetPositionX());
        _worldPacket.WriteByteSeq(transportGuid[1]);
        _worldPacket << float(Status->transport.pos.GetOrientation());
        _worldPacket.WriteByteSeq(transportGuid[2]);

        if (Status->HasTransportTime2())
            _worldPacket << uint32(Status->transport.time2);

        _worldPacket.WriteByteSeq(transportGuid[0]);
        _worldPacket << float(Status->transport.pos.GetPositionZ());
        _worldPacket.WriteByteSeq(transportGuid[7]);
        _worldPacket.WriteByteSeq(transportGuid[4]);
        _worldPacket.WriteByteSeq(transportGuid[3]);
        _worldPacket << float(Status->transport.pos.GetPositionY());
        _worldPacket << uint32(Status->transport.time);
    }

    _worldPacket.WriteByteSeq(guid[4]);
    _worldPacket << float(Status->pos.GetPositionX());
    _worldPacket.WriteByteSeq(guid[6]);
    _worldPacket << float(Status->pos.GetPositionZ());

    if (Status->HasTime())
        _worldPacket << uint32(Status->time);

    _worldPacket.WriteByteSeq(guid[2]);

    if (Status->HasPitch())
        _worldPacket << float(Status->pitch);

    _worldPacket.WriteByteSeq(guid[0]);
    if (Status->HasOrientation())
        _worldPacket << float(Status->pos.GetOrientation());

    _worldPacket.WriteByteSeq(guid[1]);

    return &_worldPacket;
}

void WorldPackets::Movement::MoveSetCollisionHeightAck::Read()
{
    _worldPacket >> Height;
    _worldPacket >> Data.Status.pos.m_positionX;
    _worldPacket >> Data.Status.pos.m_positionZ;
    _worldPacket >> Data.AckIndex;
    _worldPacket >> Data.Status.pos.m_positionY;
    Data.Status.guid[6] = _worldPacket.ReadBit();
    Data.Status.guid[4] = _worldPacket.ReadBit();

    Reason = UpdateCollisionHeightReason(_worldPacket.ReadBits(2));

    bool hasPitch = !_worldPacket.ReadBit();
    Data.Status.guid[5] = _worldPacket.ReadBit();
    _worldPacket.ReadBit(); // HeightChangeFailed
    Data.Status.guid[2] = _worldPacket.ReadBit();
    Data.Status.guid[1] = _worldPacket.ReadBit();
    bool hasFallData = _worldPacket.ReadBit();
    Data.Status.guid[3] = _worldPacket.ReadBit();
    _worldPacket.ReadBit(); // HasSpline
    Data.Status.guid[7] = _worldPacket.ReadBit();
    bool hasMovementFlags = !_worldPacket.ReadBit();
    bool hasTransportData = _worldPacket.ReadBit();
    bool hasTime = !_worldPacket.ReadBit();
    bool hasSplineElevation = !_worldPacket.ReadBit();
    bool hasExtraMovementFlags = !_worldPacket.ReadBit();
    bool hasOrientation = !_worldPacket.ReadBit();

    Data.Status.guid[0] = _worldPacket.ReadBit();

    bool hasTransportTime2 = false;
    bool hasVehicleId = false;
    if (hasTransportData)
    {
        Data.Status.transport.guid[4] = _worldPacket.ReadBit();
        Data.Status.transport.guid[3] = _worldPacket.ReadBit();
        hasTransportTime2 = _worldPacket.ReadBit();
        hasVehicleId = _worldPacket.ReadBit();
        Data.Status.transport.guid[5] = _worldPacket.ReadBit();
        Data.Status.transport.guid[1] = _worldPacket.ReadBit();
        Data.Status.transport.guid[7] = _worldPacket.ReadBit();
        Data.Status.transport.guid[2] = _worldPacket.ReadBit();
        Data.Status.transport.guid[6] = _worldPacket.ReadBit();
        Data.Status.transport.guid[0] = _worldPacket.ReadBit();
    }

    if (hasExtraMovementFlags)
        Data.Status.flags2 = _worldPacket.ReadBits(12);

    if (hasMovementFlags)
        Data.Status.flags = _worldPacket.ReadBits(30);

    bool hasFallDirection = false;
    if (hasFallData)
        hasFallDirection = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(Data.Status.guid[0]);
    _worldPacket.ReadByteSeq(Data.Status.guid[3]);
    _worldPacket.ReadByteSeq(Data.Status.guid[1]);
    _worldPacket.ReadByteSeq(Data.Status.guid[5]);
    _worldPacket.ReadByteSeq(Data.Status.guid[7]);
    _worldPacket.ReadByteSeq(Data.Status.guid[6]);
    _worldPacket.ReadByteSeq(Data.Status.guid[2]);
    _worldPacket.ReadByteSeq(Data.Status.guid[4]);

    if (hasTransportData)
    {
        _worldPacket >> Data.Status.transport.pos.m_positionX;
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[4]);

        if (hasTransportTime2)
            _worldPacket >> Data.Status.transport.time2;

        _worldPacket.ReadByteSeq(Data.Status.transport.guid[0]);
        float o = 0.f;
        _worldPacket >> o;
        Data.Status.transport.pos.SetOrientation(o);
        _worldPacket >> Data.Status.transport.pos.m_positionY;
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[7]);
        _worldPacket >> Data.Status.transport.seat;
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[5]);
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[2]);
        _worldPacket >> Data.Status.transport.time;
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[6]);
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[3]);
        _worldPacket.ReadByteSeq(Data.Status.transport.guid[1]);

        if (hasVehicleId)
            _worldPacket >> Data.Status.transport.vehicleId;

        _worldPacket >> Data.Status.transport.pos.m_positionZ;
    }

    if (hasFallData)
    {
        _worldPacket >> Data.Status.jump.zspeed;
        _worldPacket >> Data.Status.jump.fallTime;

        if (hasFallDirection)
        {
            _worldPacket >> Data.Status.jump.cosAngle;
            _worldPacket >> Data.Status.jump.sinAngle;
            _worldPacket >> Data.Status.jump.xyspeed;
        }
    }

    if (hasTime)
        _worldPacket >> Data.Status.time;
    if (hasSplineElevation)
        _worldPacket >> Data.Status.splineElevation;
    if (hasOrientation)
    {
        float o = 0.f;
        _worldPacket >> o;
        Data.Status.pos.SetOrientation(o);
    }
    if (hasPitch)
        _worldPacket >> Data.Status.pitch;
}

WorldPacket const* WorldPackets::Movement::TransferPending::Write()
{
    _worldPacket.WriteBit(TransferSpellID.is_initialized());
    _worldPacket.WriteBit(Ship.is_initialized());
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

WorldPacket const* WorldPackets::Movement::MoveUpdateCollisionHeight::Write()
{
    _worldPacket << float(Status->pos.GetPositionZ());
    _worldPacket << float(Height);
    _worldPacket << float(Status->pos.GetPositionX());
    _worldPacket << float(Status->pos.GetPositionY());

    _worldPacket.WriteBit(Status->guid[6]);
    _worldPacket.WriteBit(Status->guid[7]);
    _worldPacket.WriteBit(!Status->HasSplineElevation());
    _worldPacket.WriteBit(Status->HasTransportData());

    if (Status->HasTransportData())
    {
        _worldPacket.WriteBit(Status->transport.guid[6]);
        _worldPacket.WriteBit(Status->transport.guid[4]);
        _worldPacket.WriteBit(Status->transport.guid[3]);
        _worldPacket.WriteBit(Status->transport.guid[7]);
        _worldPacket.WriteBit(Status->transport.guid[5]);
        _worldPacket.WriteBit(Status->HasTransportVehicleId());
        _worldPacket.WriteBit(Status->transport.guid[1]);
        _worldPacket.WriteBit(Status->transport.guid[0]);
        _worldPacket.WriteBit(Status->transport.guid[2]);
        _worldPacket.WriteBit(Status->HasTransportTime2());
    }

    _worldPacket.WriteBit(Status->guid[3]);
    _worldPacket.WriteBit(!Status->HasOrientation());
    _worldPacket.WriteBit(Status->guid[4]);
    _worldPacket.WriteBit(Status->guid[5]);
    _worldPacket.WriteBit(!Status->HasTime());
    _worldPacket.WriteBit(Status->HasFallData());
    _worldPacket.WriteBit(Status->guid[0]);
    _worldPacket.WriteBit(!Status->HasPitch());
    _worldPacket.WriteBit(Status->HasHeightChangeFailed());
    _worldPacket.WriteBit(Status->guid[2]);
    _worldPacket.WriteBit(!Status->HasMovementFlags());

    if (Status->HasFallData())
        _worldPacket.WriteBit(Status->HasFallDirection());

    _worldPacket.WriteBit(Status->guid[1]);
    _worldPacket.WriteBit(!Status->HasExtraMovementFlags());
    _worldPacket.WriteBit(Status->HasSpline());

    if (Status->HasExtraMovementFlags())
        _worldPacket.WriteBits(Status->GetExtraMovementFlags(), 12);

    if (Status->HasMovementFlags())
        _worldPacket.WriteBits(Status->GetMovementFlags(), 30);

    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(Status->guid[3]);

    if (Status->HasTransportData())
    {
        _worldPacket.WriteByteSeq(Status->transport.guid[7]);
        _worldPacket << uint32(Status->transport.time);
        _worldPacket.WriteByteSeq(Status->transport.guid[4]);

        if (Status->HasTransportVehicleId())
            _worldPacket << uint32(Status->transport.vehicleId);

        if (Status->HasTransportTime2())
            _worldPacket << uint32(Status->transport.time2);

        _worldPacket.WriteByteSeq(Status->transport.guid[5]);
        _worldPacket << float(Status->transport.pos.GetOrientation());
        _worldPacket << float(Status->transport.pos.GetPositionX());
        _worldPacket.WriteByteSeq(Status->transport.guid[6]);
        _worldPacket.WriteByteSeq(Status->transport.guid[0]);
        _worldPacket << float(Status->transport.pos.GetPositionY());
        _worldPacket.WriteByteSeq(Status->transport.guid[2]);
        _worldPacket << float(Status->transport.pos.GetPositionZ());
        _worldPacket.WriteByteSeq(Status->transport.guid[3]);
        _worldPacket.WriteByteSeq(Status->transport.guid[1]);
        _worldPacket << int8(Status->transport.seat);
    }

    if (Status->HasPitch())
        _worldPacket << float(Status->pitch);

    _worldPacket.WriteByteSeq(Status->guid[6]);

    if (Status->HasFallData())
    {
        if (Status->HasFallDirection())
        {
            _worldPacket << float(Status->jump.cosAngle);
            _worldPacket << float(Status->jump.sinAngle);
            _worldPacket << float(Status->jump.xyspeed);
        }

        _worldPacket << float(Status->jump.zspeed);
        _worldPacket << uint32(Status->jump.fallTime);
    }

    _worldPacket.WriteByteSeq(Status->guid[7]);

    if (Status->HasOrientation())
        _worldPacket << float(Status->pos.GetOrientation());

    _worldPacket.WriteByteSeq(Status->guid[0]);
    _worldPacket.WriteByteSeq(Status->guid[5]);
    _worldPacket.WriteByteSeq(Status->guid[4]);

    if (Status->HasSplineElevation())
        _worldPacket << float(Status->splineElevation);

    if (Status->HasTime())
        _worldPacket << uint32(Status->time);

    _worldPacket.WriteByteSeq(Status->guid[2]);
    _worldPacket.WriteByteSeq(Status->guid[1]);

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
