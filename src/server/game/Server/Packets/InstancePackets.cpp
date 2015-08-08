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

#include "InstancePackets.h"

WorldPacket const* WorldPackets::Instance::UpdateLastInstance::Write()
{
    _worldPacket << uint32(MapID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::UpdateInstanceOwnership::Write()
{
    _worldPacket << int32(IOwnInstance);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceInfo::Write()
{
    _worldPacket << int32(LockList.size());

    for (InstanceLockInfos const& lockInfos : LockList)
        _worldPacket << lockInfos;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Instance::InstanceLockInfos const& lockInfos)
{
    data << lockInfos.MapID;
    data << lockInfos.DifficultyID;
    data << lockInfos.InstanceID;
    data << lockInfos.TimeRemaining;
    data << lockInfos.CompletedMask;

    data.WriteBit(lockInfos.Locked);
    data.WriteBit(lockInfos.Extended);

    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Instance::InstanceReset::Write()
{
    _worldPacket << uint32(MapID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceResetFailed::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket.WriteBits(ResetFailedReason, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceSaveCreated::Write()
{
    _worldPacket.WriteBit(Gm);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Instance::InstanceLockResponse::Read()
{
    AcceptLock = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Instance::RaidGroupOnly::Write()
{
    _worldPacket << Delay;
    _worldPacket << Reason;

    return &_worldPacket;
}
