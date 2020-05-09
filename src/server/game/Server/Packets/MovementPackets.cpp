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
    bool hasFallDirection = Status->HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
    bool hasFallData = hasFallDirection || Status->jump.fallTime != 0;
    bool hasMovementFlags = Status->GetMovementFlags() != 0;
    bool hasExtraMovementFlags = Status->GetExtraMovementFlags() != 0;
    bool hasSpline = false; // todo 4.x send this info
    bool heightChangeFailed = false; // todo 4.x send this info
    bool hasTime = Status->time != 0;
    bool hasOrientation = !G3D::fuzzyEq(Status->pos.GetOrientation(), 0.0f);
    bool hasSplineElevation = Status->HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);
    bool hasPitch = Status->HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || Status->HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING);
    bool hasTransportData = !Status->transport.guid.IsEmpty();
    bool hasTransportVehicleId = hasTransportData && Status->transport.vehicleId != 0;
    bool hasTransportTime2 = hasTransportData && Status->transport.time2 != 0;

    ObjectGuid guid = Status->guid;
    ObjectGuid transportGuid = Status->transport.guid;

    _worldPacket.WriteBit(hasFallData);
    _worldPacket.WriteBit(guid[3]);
    _worldPacket.WriteBit(guid[6]);
    _worldPacket.WriteBit(!hasExtraMovementFlags);
    _worldPacket.WriteBit(hasSpline);
    _worldPacket.WriteBit(!hasTime);
    _worldPacket.WriteBit(guid[0]);
    _worldPacket.WriteBit(guid[1]);

    if (hasExtraMovementFlags)
        _worldPacket.WriteBits(Status->GetExtraMovementFlags(), 12);

    _worldPacket.WriteBit(guid[7]);
    _worldPacket.WriteBit(!hasMovementFlags);
    _worldPacket.WriteBit(!hasOrientation);
    _worldPacket.WriteBit(guid[2]);
    _worldPacket.WriteBit(!hasSplineElevation);
    _worldPacket.WriteBit(heightChangeFailed);
    _worldPacket.WriteBit(guid[4]);

    if (hasFallData)
        _worldPacket.WriteBit(hasFallDirection);

    _worldPacket.WriteBit(guid[5]);
    _worldPacket.WriteBit(hasTransportData);
    if (hasMovementFlags)
        _worldPacket.WriteBits(Status->GetMovementFlags(), 30);

    if (hasTransportData)
    {
        _worldPacket.WriteBit(transportGuid[3]);
        _worldPacket.WriteBit(hasTransportVehicleId);
        _worldPacket.WriteBit(transportGuid[6]);
        _worldPacket.WriteBit(transportGuid[1]);
        _worldPacket.WriteBit(transportGuid[7]);
        _worldPacket.WriteBit(transportGuid[0]);
        _worldPacket.WriteBit(transportGuid[4]);
        _worldPacket.WriteBit(hasTransportTime2);
        _worldPacket.WriteBit(transportGuid[5]);
        _worldPacket.WriteBit(transportGuid[2]);
    }

    _worldPacket.WriteBit(!hasPitch);
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(guid[5]);

    if (hasFallData)
    {
        if (hasFallDirection)
        {
            _worldPacket << float(Status->jump.xyspeed);
            _worldPacket << float(Status->jump.sinAngle);
            _worldPacket << float(Status->jump.cosAngle);
        }

        _worldPacket << float(Status->jump.zspeed);
        _worldPacket << uint32(Status->jump.fallTime);
    }

    if (hasSplineElevation)
        _worldPacket << float(Status->splineElevation);

    _worldPacket.WriteByteSeq(guid[7]);
    _worldPacket << float(Status->pos.GetPositionY());
    _worldPacket.WriteByteSeq(guid[3]);

    if (hasTransportData)
    {
        if (hasTransportVehicleId)
            _worldPacket << uint32(Status->transport.vehicleId);

        _worldPacket.WriteByteSeq(transportGuid[6]);
        _worldPacket << uint8(Status->transport.seat);
        _worldPacket.WriteByteSeq(transportGuid[5]);
        _worldPacket << float(Status->transport.pos.GetPositionX());
        _worldPacket.WriteByteSeq(transportGuid[1]);
        _worldPacket << float(Status->transport.pos.GetOrientation());
        _worldPacket.WriteByteSeq(transportGuid[2]);

        if (hasTransportTime2)
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

    if (hasTime)
        _worldPacket << uint32(Status->time);

    _worldPacket.WriteByteSeq(guid[2]);

    if (hasPitch)
        _worldPacket << float(Status->pitch);

    _worldPacket.WriteByteSeq(guid[0]);
    if (hasOrientation)
        _worldPacket << float(Status->pos.GetOrientation());

    _worldPacket.WriteByteSeq(guid[1]);

    return &_worldPacket;
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
