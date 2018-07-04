/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "AreaTriggerPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::AreaTrigger::AreaTriggerSplineInfo const& areaTriggerSpline)
{
    data << uint32(areaTriggerSpline.TimeToTarget);
    data << uint32(areaTriggerSpline.ElapsedTimeForMovement);

    data.WriteBits(areaTriggerSpline.Points.size(), 16);
    data.FlushBits();

    for (TaggedPosition<Position::XYZ> const& point : areaTriggerSpline.Points)
        data << point;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::AreaTrigger::AreaTriggerUnkTypeInfo const& areaTriggerUnkType)
{
    data.WriteBit(areaTriggerUnkType.AreaTriggerUnkGUID.is_initialized());
    data.WriteBit(areaTriggerUnkType.Center.is_initialized());
    data.WriteBit(areaTriggerUnkType.UnkBit1);
    data.WriteBit(areaTriggerUnkType.UnkBit2);

    data << uint32(areaTriggerUnkType.UnkUInt1);
    data << int32(areaTriggerUnkType.UnkInt1);
    data << uint32(areaTriggerUnkType.UnkUInt2);
    data << float(areaTriggerUnkType.Radius);
    data << float(areaTriggerUnkType.BlendFromRadius);
    data << float(areaTriggerUnkType.InitialAngel);
    data << float(areaTriggerUnkType.ZOffset);

    if (areaTriggerUnkType.AreaTriggerUnkGUID)
        data << *areaTriggerUnkType.AreaTriggerUnkGUID;

    if (areaTriggerUnkType.Center)
        data << *areaTriggerUnkType.Center;

    return data;
}

void WorldPackets::AreaTrigger::AreaTrigger::Read()
{
    _worldPacket >> AreaTriggerID;
    Entered = _worldPacket.ReadBit();
    FromClient = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::AreaTrigger::AreaTriggerDenied::Write()
{
    _worldPacket << int32(AreaTriggerID);
    _worldPacket.WriteBit(Entered);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AreaTrigger::AreaTriggerRePath::Write()
{
    _worldPacket << TriggerGUID;
    _worldPacket << AreaTriggerSpline;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AreaTrigger::AreaTriggerReShape::Write()
{
    _worldPacket << TriggerGUID;

    _worldPacket.WriteBit(AreaTriggerSpline.is_initialized());
    _worldPacket.WriteBit(AreaTriggerUnkType.is_initialized());
    _worldPacket.FlushBits();

    if (AreaTriggerSpline)
        _worldPacket << *AreaTriggerSpline;

    if (AreaTriggerUnkType)
        _worldPacket << *AreaTriggerUnkType;

    return &_worldPacket;
}
