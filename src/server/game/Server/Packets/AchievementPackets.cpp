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

#include "AchievementPackets.h"

namespace WorldPackets::Achievement
{
ByteBuffer& operator<<(ByteBuffer& data, EarnedAchievement const& earned)
{
    data << uint32(earned.Id);
    data << earned.Date;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CriteriaProgress const& criteria)
{
    data << uint32(criteria.Id);
    data.appendPackGUID(criteria.Quantity);
    data << criteria.Player.WriteAsPacked();
    data << uint32(criteria.Flags);
    data << criteria.Date;
    data << uint32(criteria.TimeFromStart);
    data << uint32(criteria.TimeFromCreate);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AllAchievements const& allAchievements)
{
    for (EarnedAchievement const& earned : allAchievements.Earned)
        data << earned;

    data << int32(-1);

    for (CriteriaProgress const& progress : allAchievements.Progress)
        data << progress;

    data << int32(-1);

    return data;
}

WorldPacket const* AllAchievementData::Write()
{
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* RespondInspectAchievements::Write()
{
    _worldPacket << Player.WriteAsPacked();
    _worldPacket << Data;

    return &_worldPacket;
}

WorldPacket const* CriteriaUpdate::Write()
{
    _worldPacket << uint32(CriteriaID);
    _worldPacket.appendPackGUID(Quantity);
    _worldPacket << PlayerGUID.WriteAsPacked();
    _worldPacket << uint32(Flags);
    _worldPacket << (CurrentTime);
    _worldPacket << uint32(ElapsedTime);
    _worldPacket << uint32(CreationTime);

    return &_worldPacket;
}

WorldPacket const* AchievementEarned::Write()
{
    _worldPacket << Earner.WriteAsPacked();
    _worldPacket << uint32(AchievementID);
    _worldPacket << Time;
    _worldPacket << uint32(Initial);

    return &_worldPacket;
}
}
