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
#include "InstanceScript.h"
#include "Player.h"

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
    data << uint32(lockInfos.Difficulty);
    data << uint32(lockInfos.Heroic);
    data << uint64(lockInfos.InstanceID);
    data << uint8(lockInfos.Locked);
    data << uint8(lockInfos.Extended);
    data << uint32(lockInfos.TimeRemaining);
    data << uint32(lockInfos.CompletedMask);

    return data;
}

WorldPacket const* WorldPackets::Instance::InstanceInfo::Write()
{
    _worldPacket << int32(LockList.size());

    for (InstanceLock const& instanceLock : LockList)
        _worldPacket << instanceLock;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::RaidInstanceMessage::Write()
{
    _worldPacket << int32(Type);
    _worldPacket << int32(MapID);
    _worldPacket << int32(Difficulty);
    _worldPacket << int32(TimeLeft);

    if (Type == RAID_INSTANCE_WELCOME)
    {
        _worldPacket << bool(Extended);
        _worldPacket << bool(Locked);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::PendingRaidLock::Write()
{
    _worldPacket << int32(TimeUntilLock);
    _worldPacket << uint32(CompletedMask);
    _worldPacket << bool(Extending);
    _worldPacket << bool(WarningOnly);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::InstanceSaveCreated::Write()
{
    _worldPacket << uint32(Gm);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::RaidGroupOnly::Write()
{
    _worldPacket << int32(Delay);
    _worldPacket << uint32(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::UpdateInstanceEncounterUnit::Write()
{
    _worldPacket << uint32(Type);

    switch (Type)
    {
        case ENCOUNTER_FRAME_ENGAGE:
        case ENCOUNTER_FRAME_DISENGAGE:
        case ENCOUNTER_FRAME_UPDATE_PRIORITY:
            _worldPacket << Unit.WriteAsPacked();
            _worldPacket << uint8(Param1);
            break;
        case ENCOUNTER_FRAME_ADD_TIMER:
        case ENCOUNTER_FRAME_ENABLE_OBJECTIVE:
        case ENCOUNTER_FRAME_DISABLE_OBJECTIVE:
        case ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT:
            _worldPacket << uint8(Param1);
            break;
        case ENCOUNTER_FRAME_UPDATE_OBJECTIVE:
            _worldPacket << uint8(Param1);
            _worldPacket << uint8(Param2);
            break;
        case ENCOUNTER_FRAME_UNK7:
        case ENCOUNTER_FRAME_ADD_COMBAT_RES_LIMIT:
        case ENCOUNTER_FRAME_RESET_COMBAT_RES_LIMIT:
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Instance::UpdateDungeonEncounterForLoot::Write()
{
    return &_worldPacket;
}
