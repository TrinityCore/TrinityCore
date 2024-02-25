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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Instance::InstanceLock const& lockInfos)
{
    data << uint32(lockInfos.MapID);
    data << uint32(lockInfos.DifficultyID);
    data << uint64(lockInfos.InstanceID);
    data << uint32(lockInfos.TimeRemaining);
    data << uint32(lockInfos.CompletedMask);

    data.WriteBit(lockInfos.Locked);
    data.WriteBit(lockInfos.Extended);

    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Instance::InstanceInfo::Write()
{
    _worldPacket << int32(LockList.size());

    for (InstanceLock const& instanceLock : LockList)
        _worldPacket << instanceLock;

    return &_worldPacket;
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

WorldPacket const* WorldPackets::Instance::PendingRaidLock::Write()
{
    _worldPacket << int32(TimeUntilLock);
    _worldPacket << uint32(CompletedMask);
    _worldPacket.WriteBit(Extending);
    _worldPacket.WriteBit(WarningOnly);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::RaidInstanceMessage::Write()
{
    _worldPacket << uint8(Type);
    _worldPacket << uint32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket.WriteBit(Locked);
    _worldPacket.WriteBit(Extended);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterEngageUnit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(TargetFramePriority);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterDisengageUnit::Write()
{
    _worldPacket << Unit;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterChangePriority::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(TargetFramePriority);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterTimerStart::Write()
{
    _worldPacket << int32(TimeRemaining);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterObjectiveStart::Write()
{
    _worldPacket << int32(ObjectiveID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterObjectiveUpdate::Write()
{
    _worldPacket << int32(ObjectiveID);
    _worldPacket << int32(ProgressAmount);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterObjectiveComplete::Write()
{
    _worldPacket << int32(ObjectiveID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterStart::Write()
{
    _worldPacket << uint32(InCombatResCount);
    _worldPacket << uint32(MaxInCombatResCount);
    _worldPacket << uint32(CombatResChargeRecovery);
    _worldPacket << uint32(NextCombatResChargeTime);
    _worldPacket.WriteBit(InProgress);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceEncounterGainCombatResurrectionCharge::Write()
{
    _worldPacket << int32(InCombatResCount);
    _worldPacket << uint32(CombatResChargeRecovery);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::BossKill::Write()
{
    _worldPacket << uint32(DungeonEncounterID);

    return &_worldPacket;
}
