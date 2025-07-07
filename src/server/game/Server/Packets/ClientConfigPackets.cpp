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

#include "ClientConfigPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::ClientConfig
{
WorldPacket const* AccountDataTimes::Write()
{
    _worldPacket << PlayerGuid;
    _worldPacket << ServerTime;
    for (Timestamp<> const& accountDataTime : AccountTimes)
        _worldPacket << accountDataTime;

    return &_worldPacket;
}

WorldPacket const* ClientCacheVersion::Write()
{
    _worldPacket << uint32(CacheVersion);

    return &_worldPacket;
}

void RequestAccountData::Read()
{
    _worldPacket >> PlayerGuid;
    _worldPacket >> DataType;
}

WorldPacket const* UpdateAccountData::Write()
{
    _worldPacket << Time;
    _worldPacket << uint32(Size);
    _worldPacket << Player;
    _worldPacket << int32(DataType);
    _worldPacket << WorldPackets::Size<uint32>(CompressedData);
    if (!CompressedData.empty())
        _worldPacket.append(CompressedData.data(), CompressedData.size());

    return &_worldPacket;
}

void UserClientUpdateAccountData::Read()
{
    _worldPacket >> Time;
    _worldPacket >> Size;
    _worldPacket >> PlayerGuid;
    _worldPacket >> DataType;

    uint32 compressedSize = _worldPacket.read<uint32>();
    std::size_t pos = _worldPacket.rpos();
    std::size_t remainingSize = _worldPacket.size() - pos;
    if (compressedSize > remainingSize)
        OnInvalidArraySize(compressedSize, remainingSize);

    CompressedData = { _worldPacket.data() + pos, compressedSize };
    _worldPacket.rpos(pos + compressedSize);
}

WorldPacket const* UpdateAccountDataComplete::Write()
{
    _worldPacket << Player;
    _worldPacket << int32(DataType);
    _worldPacket << int32(Result);

    return &_worldPacket;
}

void SetAdvancedCombatLogging::Read()
{
    _worldPacket >> Bits<1>(Enable);
}
}
