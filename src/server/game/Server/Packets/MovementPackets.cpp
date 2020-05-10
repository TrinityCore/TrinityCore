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
