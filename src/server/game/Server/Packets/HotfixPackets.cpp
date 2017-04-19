/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "HotfixPackets.h"
#include "PacketUtilities.h"

void WorldPackets::Hotfix::DBQueryBulk::Read()
{
    _worldPacket >> TableHash;

    uint32 count = _worldPacket.ReadBits(13);

    Queries.resize(count);
    for (uint32 i = 0; i < count; ++i)
    {
        _worldPacket >> Queries[i].GUID;
        _worldPacket >> Queries[i].RecordID;
    }
}

WorldPacket const* WorldPackets::Hotfix::DBReply::Write()
{
    _worldPacket << uint32(TableHash);
    _worldPacket << uint32(RecordID);
    _worldPacket << uint32(Timestamp);
    _worldPacket.WriteBit(Allow);
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Hotfix::HotfixList::Write()
{
    _worldPacket << int32(HotfixCacheVersion);
    _worldPacket << uint32(Hotfixes.size());
    for (auto const& hotfixEntry : Hotfixes)
        _worldPacket << int32(hotfixEntry.first);

    return &_worldPacket;
}

void WorldPackets::Hotfix::HotfixQuery::Read()
{
    uint32 hotfixCount = _worldPacket.read<uint32>();
    if (hotfixCount > sDB2Manager.GetHotfixData().size())
        throw PacketArrayMaxCapacityException(hotfixCount, sDB2Manager.GetHotfixData().size());

    Hotfixes.resize(hotfixCount);
    for (int32& hotfixId : Hotfixes)
        _worldPacket >> hotfixId;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Hotfix::HotfixQueryResponse::HotfixRecord const& hotfixRecord)
{
    data << uint32(hotfixRecord.TableHash);
    data << int32(hotfixRecord.RecordID);
    data.WriteBit(hotfixRecord.HotfixData.is_initialized());
    if (hotfixRecord.HotfixData)
    {
        data << uint32(hotfixRecord.HotfixData->size());
        data.append(*hotfixRecord.HotfixData);
    }
    else
        data << uint32(0);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Hotfix::HotfixQueryResponse::HotfixData const& hotfixData)
{
    data << int32(hotfixData.ID);
    data << uint32(hotfixData.Records.size());
    for (WorldPackets::Hotfix::HotfixQueryResponse::HotfixRecord const& hotfixRecord : hotfixData.Records)
        data << hotfixRecord;

    return data;
}

WorldPacket const* WorldPackets::Hotfix::HotfixQueryResponse::Write()
{
    _worldPacket << uint32(Hotfixes.size());
    for (HotfixData const& hotfix : Hotfixes)
        _worldPacket << hotfix;

    return &_worldPacket;
}
