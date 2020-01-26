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

#include "HotfixPackets.h"
#include "PacketUtilities.h"

void WorldPackets::Hotfix::DBQueryBulk::Read()
{
    _worldPacket >> TableHash;

    uint32 count = _worldPacket.ReadBits(13);

    Queries.resize(count);
    for (uint32 i = 0; i < count; ++i)
        _worldPacket >> Queries[i].RecordID;
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

WorldPacket const* WorldPackets::Hotfix::AvailableHotfixes::Write()
{
    _worldPacket << int32(HotfixCacheVersion);
    _worldPacket << uint32(HotfixCount);
    for (auto const& hotfixEntry : Hotfixes)
    {
        for (auto const& tableRecord : hotfixEntry.second)
        {
            _worldPacket << uint32(tableRecord.first);
            _worldPacket << int32(tableRecord.second);
            _worldPacket << int32(hotfixEntry.first);
        }
    }

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Hotfix::HotfixRecord& hotfixRecord)
{
    data >> hotfixRecord.TableHash;
    data >> hotfixRecord.RecordID;
    data >> hotfixRecord.HotfixID;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Hotfix::HotfixRecord const& hotfixRecord)
{
    data << uint32(hotfixRecord.TableHash);
    data << int32(hotfixRecord.RecordID);
    data << int32(hotfixRecord.HotfixID);
    return data;
}

void WorldPackets::Hotfix::HotfixRequest::Read()
{
    _worldPacket >> ClientBuild;
    _worldPacket >> DataBuild;

    uint32 hotfixCount = _worldPacket.read<uint32>();
    if (hotfixCount > sDB2Manager.GetHotfixCount())
        throw PacketArrayMaxCapacityException(hotfixCount, sDB2Manager.GetHotfixCount());

    Hotfixes.resize(hotfixCount);
    for (HotfixRecord& hotfixRecord : Hotfixes)
        _worldPacket >> hotfixRecord;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Hotfix::HotfixResponse::HotfixData const& hotfixData)
{
    data << hotfixData.Record;
    if (hotfixData.Size)
    {
        data << uint32(*hotfixData.Size);
        data.WriteBit(true);
    }
    else
    {
        data << uint32(0);
        data.WriteBit(false);
    }
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Hotfix::HotfixResponse::Write()
{
    _worldPacket << uint32(Hotfixes.size());
    for (HotfixData const& hotfix : Hotfixes)
        _worldPacket << hotfix;

    _worldPacket << uint32(HotfixContent.size());
    _worldPacket.append(HotfixContent);

    return &_worldPacket;
}
