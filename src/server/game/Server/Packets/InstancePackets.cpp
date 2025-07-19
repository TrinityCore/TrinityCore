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
#include "PacketOperators.h"

namespace WorldPackets::Instance
{
WorldPacket const* UpdateLastInstance::Write()
{
    _worldPacket << uint32(MapID);

    return &_worldPacket;
}

WorldPacket const* UpdateInstanceOwnership::Write()
{
    _worldPacket << int32(IOwnInstance);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, InstanceLock const& lockInfos)
{
    data << uint64(lockInfos.InstanceID);
    data << uint32(lockInfos.MapID);
    data << uint32(lockInfos.DifficultyID);
    data << uint32(lockInfos.TimeRemaining);
    data << uint32(lockInfos.CompletedMask);

    data << Bits<1>(lockInfos.Locked);
    data << Bits<1>(lockInfos.Extended);

    data.FlushBits();

    return data;
}

WorldPacket const* InstanceInfo::Write()
{
    _worldPacket << Size<int32>(LockList);

    for (InstanceLock const& instanceLock : LockList)
        _worldPacket << instanceLock;

    return &_worldPacket;
}

WorldPacket const* InstanceReset::Write()
{
    _worldPacket << uint32(MapID);

    return &_worldPacket;
}

WorldPacket const* InstanceResetFailed::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << Bits<2>(ResetFailedReason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* InstanceSaveCreated::Write()
{
    _worldPacket << Bits<1>(Gm);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void InstanceLockResponse::Read()
{
    _worldPacket >> Bits<1>(AcceptLock);
}

WorldPacket const* RaidGroupOnly::Write()
{
    _worldPacket << Delay;
    _worldPacket << Reason;

    return &_worldPacket;
}

WorldPacket const* PendingRaidLock::Write()
{
    _worldPacket << int32(TimeUntilLock);
    _worldPacket << uint32(CompletedMask);
    _worldPacket << Bits<1>(Extending);
    _worldPacket << Bits<1>(WarningOnly);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* RaidInstanceMessage::Write()
{
    _worldPacket << int32(Type);
    _worldPacket << uint32(MapID);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << int32(TimeLeft);
    _worldPacket << SizedString::BitsSize<8>(WarningMessage);
    _worldPacket << Bits<1>(Locked);
    _worldPacket << Bits<1>(Extended);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(WarningMessage);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterEngageUnit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(TargetFramePriority);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterDisengageUnit::Write()
{
    _worldPacket << Unit;

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterChangePriority::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(TargetFramePriority);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterTimerStart::Write()
{
    _worldPacket << int32(TimeRemaining);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterObjectiveStart::Write()
{
    _worldPacket << int32(ObjectiveID);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterObjectiveUpdate::Write()
{
    _worldPacket << int32(ObjectiveID);
    _worldPacket << int32(ProgressAmount);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterObjectiveComplete::Write()
{
    _worldPacket << int32(ObjectiveID);

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterStart::Write()
{
    _worldPacket << uint32(InCombatResCount);
    _worldPacket << uint32(MaxInCombatResCount);
    _worldPacket << uint32(CombatResChargeRecovery);
    _worldPacket << uint32(NextCombatResChargeTime);
    _worldPacket << Bits<1>(InProgress);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* InstanceEncounterGainCombatResurrectionCharge::Write()
{
    _worldPacket << int32(InCombatResCount);
    _worldPacket << uint32(CombatResChargeRecovery);

    return &_worldPacket;
}

WorldPacket const* BossKill::Write()
{
    _worldPacket << uint32(DungeonEncounterID);

    return &_worldPacket;
}
}
