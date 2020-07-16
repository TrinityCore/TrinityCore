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

    _worldPacket.WriteBit(Vehicle.is_initialized());
    if (Vehicle)
    {
        _worldPacket.WriteBit(Vehicle->VehicleExitVoluntary);
        _worldPacket.WriteBit(Vehicle->VehicleExitTeleport);
    }

    _worldPacket.WriteBit(TransportGUID.is_initialized());
    _worldPacket.WriteBit(MoverGUID[1]);

    if (TransportGUID.is_initialized())
    {
        ObjectGuid transGUID = TransportGUID.get();
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

    if (TransportGUID.is_initialized())
    {
        ObjectGuid transGUID = TransportGUID.get();
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
