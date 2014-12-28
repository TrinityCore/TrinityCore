/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "AchievementPackets.h"

WorldPacket const* WorldPackets::Achievement::AllAchievements::Write()
{
    _worldPacket << uint32(Earned.size());
    _worldPacket << uint32(Progress.size());

    for (EarnedAchievement const& earned : Earned)
    {
        _worldPacket << uint32(earned.Id);
        _worldPacket.AppendPackedTime(earned.Date);
        _worldPacket << earned.Owner;
        _worldPacket << uint32(earned.VirtualRealmAddress);
        _worldPacket << uint32(earned.NativeRealmAddress);
    }

    for (CriteriaProgress const& progress : Progress)
    {
        _worldPacket << uint32(progress.Id);
        _worldPacket << uint64(progress.Quantity);
        _worldPacket << progress.Player;
        _worldPacket.AppendPackedTime(progress.Date);
        _worldPacket << uint32(progress.TimeFromStart);
        _worldPacket << uint32(progress.TimeFromCreate);
        _worldPacket.WriteBits(progress.Flags, 4);
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::CriteriaUpdate::Write()
{
    _worldPacket << uint32(CriteriaID);
    _worldPacket << uint64(Quantity);
    _worldPacket << PlayerGUID;
    _worldPacket << uint32(Flags);
    _worldPacket.AppendPackedTime(CurrentTime);
    _worldPacket << uint32(ElapsedTime);
    _worldPacket << uint32(CreationTime);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Achievement::AchievementEarned::Write()
{
    _worldPacket << Sender;
    _worldPacket << Earner;
    _worldPacket << uint32(AchievementID);
    _worldPacket.AppendPackedTime(Time);
    _worldPacket << uint32(EarnerNativeRealm);
    _worldPacket << uint32(EarnerVirtualRealm);
    _worldPacket.WriteBit(Initial);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
