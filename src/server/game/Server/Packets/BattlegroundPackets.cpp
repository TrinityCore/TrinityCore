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

#include "BattlegroundPackets.h"

WorldPacket const* WorldPackets::Battleground::PVPSeason::Write()
{
    _worldPacket << uint32(CurrentSeason);
    _worldPacket << uint32(PreviousSeason);

    return &_worldPacket;
}

void WorldPackets::Battleground::AreaSpiritHealerQuery::Read()
{
    _worldPacket >> HealerGuid;
}

void WorldPackets::Battleground::AreaSpiritHealerQueue::Read()
{
    _worldPacket >> HealerGuid;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData::RatingData const& ratingData)
{
    data.append(ratingData.Prematch, 2);
    data.append(ratingData.Postmatch, 2);
    data.append(ratingData.PrematchMMR, 2);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData::HonorData const& honorData)
{
    data << uint32(honorData.HonorKills);
    data << uint32(honorData.Deaths);
    data << uint32(honorData.ContributionPoints);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData::PlayerData const& playerData)
{
    data << playerData.PlayerGUID;
    data << uint32(playerData.Kills);
    data << uint32(playerData.DamageDone);
    data << uint32(playerData.HealingDone);
    data << uint32(playerData.Stats.size());
    data << int32(playerData.PrimaryTalentTree);
    data << uint32(playerData.PrimaryTalentTreeNameIndex);
    if (!playerData.Stats.empty())
        data.append(playerData.Stats.data(), playerData.Stats.size());

    data.WriteBit(playerData.Faction);
    data.WriteBit(playerData.IsInWorld);
    data.WriteBit(playerData.Honor.HasValue);
    data.WriteBit(playerData.PreMatchRating.HasValue);
    data.WriteBit(playerData.RatingChange.HasValue);
    data.WriteBit(playerData.PreMatchMMR.HasValue);
    data.WriteBit(playerData.MmrChange.HasValue);
    data.FlushBits();

    if (playerData.Honor.HasValue)
        data << playerData.Honor.Value;

    if (playerData.PreMatchRating.HasValue)
        data << uint32(playerData.PreMatchRating.Value);

    if (playerData.RatingChange.HasValue)
        data << uint32(playerData.RatingChange.Value);

    if (playerData.PreMatchMMR.HasValue)
        data << uint32(playerData.PreMatchMMR.Value);

    if (playerData.MmrChange.HasValue)
        data << uint32(playerData.MmrChange.Value);

    return data;
}

WorldPacket const* WorldPackets::Battleground::PVPLogData::Write()
{
    _worldPacket.reserve(Players.size() * sizeof(PlayerData) + sizeof(PVPLogData));

    _worldPacket.WriteBit(Ratings.HasValue);
    _worldPacket.WriteBit(Winner.HasValue);
    _worldPacket << uint32(Players.size());
    _worldPacket.append(PlayerCount, 2);

    if (Ratings.HasValue)
        _worldPacket << Ratings.Value;

    if (Winner.HasValue)
        _worldPacket << uint8(Winner.Value);

    for (PlayerData const& player : Players)
        _worldPacket << player;

    return &_worldPacket;
}
