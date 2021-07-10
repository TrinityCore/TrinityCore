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

#include "InspectPackets.h"

WorldPacket const* WorldPackets::Inspect::InspectHonorStats::Write()
{
    _worldPacket.WriteBit(PlayerGUID[4]);
    _worldPacket.WriteBit(PlayerGUID[3]);
    _worldPacket.WriteBit(PlayerGUID[6]);
    _worldPacket.WriteBit(PlayerGUID[2]);
    _worldPacket.WriteBit(PlayerGUID[5]);
    _worldPacket.WriteBit(PlayerGUID[0]);
    _worldPacket.WriteBit(PlayerGUID[7]);
    _worldPacket.WriteBit(PlayerGUID[1]);

    _worldPacket << uint8(LifetimeMaxRank);
    _worldPacket << uint16(YesterdayHK);
    _worldPacket << uint16(TodayHK);
    _worldPacket.WriteByteSeq(PlayerGUID[2]);
    _worldPacket.WriteByteSeq(PlayerGUID[0]);
    _worldPacket.WriteByteSeq(PlayerGUID[6]);
    _worldPacket.WriteByteSeq(PlayerGUID[3]);
    _worldPacket.WriteByteSeq(PlayerGUID[4]);
    _worldPacket.WriteByteSeq(PlayerGUID[1]);
    _worldPacket.WriteByteSeq(PlayerGUID[5]);
    _worldPacket << uint32(LifetimeHK);
    _worldPacket.WriteByteSeq(PlayerGUID[7]);

    return &_worldPacket;
}

void WorldPackets::Inspect::RequestHonorStats::Read()
{
    TargetGUID[1] = _worldPacket.ReadBit();
    TargetGUID[5] = _worldPacket.ReadBit();
    TargetGUID[7] = _worldPacket.ReadBit();
    TargetGUID[3] = _worldPacket.ReadBit();
    TargetGUID[2] = _worldPacket.ReadBit();
    TargetGUID[4] = _worldPacket.ReadBit();
    TargetGUID[0] = _worldPacket.ReadBit();
    TargetGUID[6] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(TargetGUID[4]);
    _worldPacket.ReadByteSeq(TargetGUID[7]);
    _worldPacket.ReadByteSeq(TargetGUID[0]);
    _worldPacket.ReadByteSeq(TargetGUID[5]);
    _worldPacket.ReadByteSeq(TargetGUID[1]);
    _worldPacket.ReadByteSeq(TargetGUID[6]);
    _worldPacket.ReadByteSeq(TargetGUID[2]);
    _worldPacket.ReadByteSeq(TargetGUID[3]);
}

void WorldPackets::Inspect::RequestInspectRatedBgStats::Read()
{
    TargetGUID[1] = _worldPacket.ReadBit();
    TargetGUID[4] = _worldPacket.ReadBit();
    TargetGUID[6] = _worldPacket.ReadBit();
    TargetGUID[5] = _worldPacket.ReadBit();
    TargetGUID[0] = _worldPacket.ReadBit();
    TargetGUID[2] = _worldPacket.ReadBit();
    TargetGUID[7] = _worldPacket.ReadBit();
    TargetGUID[3] = _worldPacket.ReadBit();

   _worldPacket.ReadByteSeq(TargetGUID[4]);
   _worldPacket.ReadByteSeq(TargetGUID[7]);
   _worldPacket.ReadByteSeq(TargetGUID[2]);
   _worldPacket.ReadByteSeq(TargetGUID[5]);
   _worldPacket.ReadByteSeq(TargetGUID[6]);
   _worldPacket.ReadByteSeq(TargetGUID[3]);
   _worldPacket.ReadByteSeq(TargetGUID[0]);
   _worldPacket.ReadByteSeq(TargetGUID[1]);
}

WorldPacket const* WorldPackets::Inspect::InspectRatedBgStats::Write()
{
    _worldPacket.WriteBit(PlayerGUID[6]);
    _worldPacket.WriteBit(PlayerGUID[4]);
    _worldPacket.WriteBit(PlayerGUID[5]);
    _worldPacket.WriteBit(PlayerGUID[1]);
    _worldPacket.WriteBit(PlayerGUID[2]);
    _worldPacket.WriteBit(PlayerGUID[7]);
    _worldPacket.WriteBit(PlayerGUID[0]);
    _worldPacket.WriteBit(PlayerGUID[3]);

    _worldPacket.WriteByteSeq(PlayerGUID[3]);
    _worldPacket << int32(Rating);
    _worldPacket.WriteByteSeq(PlayerGUID[1]);
    _worldPacket.WriteByteSeq(PlayerGUID[7]);
    _worldPacket.WriteByteSeq(PlayerGUID[3]);
    _worldPacket.WriteByteSeq(PlayerGUID[6]);
    _worldPacket << int32(Won);
    _worldPacket << int32(Played);
    _worldPacket.WriteByteSeq(PlayerGUID[2]);
    _worldPacket.WriteByteSeq(PlayerGUID[5]);
    _worldPacket.WriteByteSeq(PlayerGUID[0]);

    return &_worldPacket;
}
