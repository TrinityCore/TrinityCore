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

#include "MiscPackets.h"
#include "Common.h"

WorldPacket const* WorldPackets::Misc::SetupCurrency::Write()
{
    _worldPacket.WriteBits(Data.size(), 23);

    for (Record const& data : Data)
    {
        _worldPacket.WriteBit(data.WeeklyQuantity.is_initialized());
        _worldPacket.WriteBits(data.Flags, 4);
        _worldPacket.WriteBit(data.MaxWeeklyQuantity.is_initialized());
        _worldPacket.WriteBit(data.TrackedQuantity.is_initialized());
    }

    _worldPacket.FlushBits();

    for (Record const& data : Data)
    {
        _worldPacket << uint32(data.Quantity);

        if (data.MaxWeeklyQuantity.is_initialized())
            _worldPacket << uint32(*data.MaxWeeklyQuantity);
        if (data.TrackedQuantity.is_initialized())
            _worldPacket << uint32(*data.TrackedQuantity);

        _worldPacket << uint32(data.Type);

        if (data.WeeklyQuantity.is_initialized())
            _worldPacket << uint32(*data.WeeklyQuantity);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::RequestPVPRewardsResponse::Write()
{
    _worldPacket << uint32(MaxRewardPointsThisWeek);
    _worldPacket << uint32(RewardPointsThisWeek);
    _worldPacket << uint32(ArenaMaxRewardPointsThisWeek);
    _worldPacket << uint32(RatedRewardPointsThisWeek);
    _worldPacket << uint32(ArenaRewardPointsThisWeek);
    _worldPacket << uint32(RatedMaxRewardPointsThisWeek);

    return &_worldPacket;
}
