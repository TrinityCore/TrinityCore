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

#include "BattlegroundPackets.h"
#include "Battleground.h"

void WorldPackets::Battleground::AreaSpiritHealerQuery::Read()
{
    _worldPacket >> HealerGuid;
}

void WorldPackets::Battleground::AreaSpiritHealerQueue::Read()
{
    _worldPacket >> HealerGuid;
}

WorldPacket const* WorldPackets::Battleground::AreaSpiritHealerTime::Write()
{
    _worldPacket << HealerGuid;
    _worldPacket << int32(TimeLeft);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData_RatingData const& ratingData)
{
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << int32(ratingData.Prematch[i]);
        data << int32(ratingData.Postmatch[i]);
        data << int32(ratingData.PrematchMMR[i]);
    }
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData_Arena const& arena)
{
    data << arena.Ratings;
    for (std::string_view const& teamName : arena.TeamName)
        data << teamName;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData_Honor const& honorData)
{
    data << uint32(honorData.HonorKills);
    data << uint32(honorData.Deaths);
    data << uint32(honorData.ContributionPoints);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::PVPLogData_Player const& playerData)
{
    data << playerData.PlayerGUID;
    data << uint32(playerData.Kills);
    std::visit([&](auto const& v) { return data << v; }, playerData.HonorOrFaction);
    data << uint32(playerData.DamageDone);
    data << uint32(playerData.HealingDone);
    data << uint32(playerData.Stats.size());
    for (uint32 pvpStat : playerData.Stats)
        data << uint32(pvpStat);

    return data;
}

WorldPacket const* WorldPackets::Battleground::PVPMatchStatistics::Write()
{
    _worldPacket.reserve(sizeof(PVPLogData_Arena) + 1 + 1 + 4 + Players.size() * sizeof(PVPLogData_Player));

    _worldPacket << uint8(Arena.has_value());
    if (Arena)
        _worldPacket << *Arena;

    _worldPacket << uint8(Winner.has_value());
    if (Winner)
        _worldPacket << uint8(*Winner);

    _worldPacket << uint32(Players.size());
    for (PVPLogData_Player const& player : Players)
        _worldPacket << player;

    return &_worldPacket;
}

void WorldPackets::Battleground::BattlemasterJoin::Read()
{
    _worldPacket >> BattlemasterGuid;
    _worldPacket >> BattlemasterListID;
    _worldPacket >> InstanceID;
    _worldPacket >> JoinAsGroup;
}

void WorldPackets::Battleground::BattlemasterJoinArena::Read()
{
    _worldPacket >> BattlemasterGuid;
    _worldPacket >> TeamSizeIndex;
    _worldPacket >> JoinAsGroup;
    _worldPacket >> IsRated;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::BattlefieldStatusHeader const& header)
{
    data << uint32(header.QueueSlot);
    data << uint64(header.QueueID);
    data << uint8(header.RangeMin);
    data << uint8(header.RangeMax);
    data << uint32(header.InstanceID);
    data << uint8(header.RegisteredMatch);
    return data;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusNone::Write()
{
    _worldPacket << uint32(QueueSlot);
    _worldPacket << uint64(0);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusNeedConfirmation::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(STATUS_WAIT_JOIN);
    _worldPacket << uint32(Mapid);
    _worldPacket << uint64(RandomQueueID);
    _worldPacket << uint32(Timeout);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusActive::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(STATUS_IN_PROGRESS);
    _worldPacket << uint32(Mapid);
    _worldPacket << uint64(RandomQueueID);
    _worldPacket << uint32(ShutdownTimer);
    _worldPacket << uint32(StartTimer);
    _worldPacket << uint8(ArenaFaction);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldStatusQueued::Write()
{
    _worldPacket << Hdr;
    _worldPacket << uint32(STATUS_WAIT_QUEUE);
    _worldPacket << uint32(AverageWaitTime);
    _worldPacket << uint32(WaitTime);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::GroupJoinedBattleground::Write()
{
    _worldPacket << uint32(Reason);
    if (Reason == ERR_BATTLEGROUND_JOIN_TIMED_OUT || Reason == ERR_BATTLEGROUND_JOIN_FAILED)
        _worldPacket << ClientID;

    return &_worldPacket;
}

void WorldPackets::Battleground::BattlefieldLeave::Read()
{
    _worldPacket >> QueueID;
}

void WorldPackets::Battleground::BattlefieldPort::Read()
{
    _worldPacket >> QueueID;
    _worldPacket >> AcceptedInvite;
}

void WorldPackets::Battleground::BattlefieldListRequest::Read()
{
    _worldPacket >> ListID;
    _worldPacket >> PvpAnywhere;
    _worldPacket >> NoXpGain;
}

WorldPacket const* WorldPackets::Battleground::BattlefieldList::Write()
{
    _worldPacket << BattlemasterGuid;
    _worldPacket << uint8(PvpAnywhere);
    _worldPacket << int32(BattlemasterListID);
    _worldPacket << uint8(MinLevel);
    _worldPacket << uint8(MaxLevel);

    _worldPacket << uint8(HasHolidayWinToday);
    _worldPacket << uint32(HolidayWinHonorCurrencyBonus);
    _worldPacket << uint32(HolidayFirstWinArenaCurrencyBonus);
    _worldPacket << uint32(HolidayLossHonorCurrencyBonus);

    _worldPacket << uint8(BattlemasterListID == BATTLEGROUND_RB);
    if (BattlemasterListID == BATTLEGROUND_RB)
    {
        _worldPacket << uint8(HasRandomWinToday);
        _worldPacket << uint32(RandomWinHonorCurrencyBonus);
        _worldPacket << uint32(RandomFirstWinArenaCurrencyBonus);
        _worldPacket << uint32(RandomLossHonorCurrencyBonus);
    }

    _worldPacket << uint32(Battlefields ? Battlefields->size() : 0);
    if (Battlefields)
        for (uint32 battlefield : *Battlefields)
            _worldPacket << uint32(battlefield);

    return &_worldPacket;
}

void WorldPackets::Battleground::ReportPvPPlayerAFK::Read()
{
    _worldPacket >> Offender;
}

WorldPacket const* WorldPackets::Battleground::ReportPvPPlayerAFKResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << uint8(NumBlackMarksOnOffender);
    _worldPacket << uint8(NumPlayersIHaveReported);
    _worldPacket << Offender;
    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battleground::BattlegroundPlayerPosition const& playerPosition)
{
    data << playerPosition.Guid;
    data << playerPosition.Pos;
    return data;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerPositions::Write()
{
    _worldPacket << uint32(Players.size());
    for (BattlegroundPlayerPosition const& pos : Players)
        _worldPacket << pos;

    _worldPacket << uint32(FlagCarriers.size());
    for (BattlegroundPlayerPosition const& pos : FlagCarriers)
        _worldPacket << pos;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerJoined::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::BattlegroundPlayerLeft::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battleground::DestroyArenaUnit::Write()
{
    _worldPacket << Guid;
    return &_worldPacket;
}
