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

#include "MiscPackets.h"

WorldPacket const* WorldPackets::Misc::BindPointUpdate::Write()
{
    _worldPacket << float(BindPosition.x);
    _worldPacket << float(BindPosition.y);
    _worldPacket << float(BindPosition.z);
    _worldPacket << uint32(BindMapID);
    _worldPacket << uint32(BindAreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::InvalidatePlayer::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::LoginSetTimeSpeed::Write()
{
    _worldPacket.AppendPackedTime(ServerTime);
    _worldPacket.AppendPackedTime(GameTime);
    _worldPacket << float(NewSpeed);
    _worldPacket << uint32(ServerTimeHolidayOffset);
    _worldPacket << uint32(GameTimeHolidayOffset);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetCurrency::Write()
{
    _worldPacket << uint32(Type);
    _worldPacket << uint32(Quantity);
    _worldPacket << uint32(Flags);
    _worldPacket.WriteBit(WeeklyQuantity.HasValue);
    _worldPacket.WriteBit(TrackedQuantity.HasValue);
    _worldPacket.WriteBit(SuppressChatLog);

    if (WeeklyQuantity.HasValue)
        _worldPacket << uint32(WeeklyQuantity.Value);

    if (TrackedQuantity.HasValue)
        _worldPacket << uint32(TrackedQuantity.Value);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::SetSelection::Read()
{
    _worldPacket >> Selection;
}

WorldPacket const* WorldPackets::Misc::SetupCurrency::Write()
{
    _worldPacket << uint32(Data.size());

    for (Record const& data : Data)
    {
        _worldPacket << uint32(data.Type);
        _worldPacket << uint32(data.Quantity);

        _worldPacket.WriteBit(data.WeeklyQuantity.HasValue);
        _worldPacket.WriteBit(data.MaxWeeklyQuantity.HasValue);
        _worldPacket.WriteBit(data.TrackedQuantity.HasValue);

        _worldPacket.WriteBits(data.Flags, 5);

        if (data.WeeklyQuantity.HasValue)
            _worldPacket << uint32(data.WeeklyQuantity.Value);
        if (data.MaxWeeklyQuantity.HasValue)
            _worldPacket << uint32(data.MaxWeeklyQuantity.Value);
        if (data.TrackedQuantity.HasValue)
            _worldPacket << uint32(data.TrackedQuantity.Value);
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::ViolenceLevel::Read()
{
    _worldPacket >> ViolenceLvl;
}

WorldPacket const* WorldPackets::Misc::TimeSyncRequest::Write()
{
    _worldPacket << SequenceIndex;

    return &_worldPacket;
}

void WorldPackets::Misc::TimeSyncResponse::Read()
{
    _worldPacket >> SequenceIndex;
    _worldPacket >> ClientTime;
}

WorldPacket const* WorldPackets::Misc::UITime::Write()
{
    _worldPacket << Time;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::TutorialFlags::Write()
{
    _worldPacket.append(TutorialData, MAX_ACCOUNT_TUTORIAL_VALUES);

    return &_worldPacket;
}

void WorldPackets::Misc::TutorialSetFlag::Read()
{
    Action = _worldPacket.ReadBits(2);
    _worldPacket >> TutorialBit;
}

WorldPacket const* WorldPackets::Misc::WorldServerInfo::Write()
{
    _worldPacket << uint32(DifficultyID);
    _worldPacket << uint8(IsTournamentRealm);
    _worldPacket << uint32(WeeklyReset);
    _worldPacket.WriteBit(IneligibleForLootMask.HasValue);
    _worldPacket.WriteBit(InstanceGroupSize.HasValue);
    _worldPacket.WriteBit(RestrictedAccountMaxLevel.HasValue);
    _worldPacket.WriteBit(RestrictedAccountMaxMoney.HasValue);

    if (IneligibleForLootMask.HasValue)
        _worldPacket << uint32(IneligibleForLootMask.Value);

    if (InstanceGroupSize.HasValue)
        _worldPacket << uint32(InstanceGroupSize.Value);

    if (RestrictedAccountMaxLevel.HasValue)
        _worldPacket << uint32(RestrictedAccountMaxLevel.Value);

    if (RestrictedAccountMaxMoney.HasValue)
        _worldPacket << uint32(RestrictedAccountMaxMoney.Value);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::AreaTrigger::Read()
{
    _worldPacket >> AreaTriggerID;
    Entered = _worldPacket.ReadBit();
    FromClient = _worldPacket.ReadBit();
}
