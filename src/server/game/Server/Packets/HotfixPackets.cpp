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
#include "Util.h"

namespace WorldPackets
{
namespace Hotfix
{
ByteBuffer& operator>>(ByteBuffer& data, DB2Manager::HotfixRecord& hotfixRecord)
{
    data >> hotfixRecord.TableHash;
    data >> hotfixRecord.RecordID;
    data >> hotfixRecord.HotfixID;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DB2Manager::HotfixRecord const& hotfixRecord)
{
    data << uint32(hotfixRecord.TableHash);
    data << int32(hotfixRecord.RecordID);
    data << int32(hotfixRecord.HotfixID);
    return data;
}

void DBQueryBulk::Read()
{
    _worldPacket >> TableHash;

    uint32 count = _worldPacket.ReadBits(13);

    Queries.resize(count);
    for (uint32 i = 0; i < count; ++i)
        _worldPacket >> Queries[i].RecordID;
}

WorldPacket const* DBReply::Write()
{
    _worldPacket << uint32(TableHash);
    _worldPacket << uint32(RecordID);
    _worldPacket << uint32(Timestamp);
    _worldPacket.WriteBits(AsUnderlyingType(Status), 3);
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* AvailableHotfixes::Write()
{
    _worldPacket << int32(VirtualRealmAddress);
    _worldPacket << uint32(Hotfixes.size());
    for (DB2Manager::HotfixContainer::value_type const& hotfixRecord : Hotfixes)
        _worldPacket << int32(hotfixRecord.first);

    return &_worldPacket;
}

void HotfixRequest::Read()
{
    _worldPacket >> ClientBuild;
    _worldPacket >> DataBuild;

    uint32 hotfixCount = _worldPacket.read<uint32>();
    if (hotfixCount > sDB2Manager.GetHotfixCount())
        throw PacketArrayMaxCapacityException(hotfixCount, sDB2Manager.GetHotfixCount());

    Hotfixes.resize(hotfixCount);
    for (int32& hotfixId : Hotfixes)
        _worldPacket >> hotfixId;
}

ByteBuffer& operator<<(ByteBuffer& data, HotfixConnect::HotfixData const& hotfixData)
{
    data << hotfixData.Record;
    data << uint32(hotfixData.Size);
    data.WriteBits(AsUnderlyingType(hotfixData.Record.HotfixStatus), 3);
    data.FlushBits();

    return data;
}

WorldPacket const* HotfixConnect::Write()
{
    _worldPacket << uint32(Hotfixes.size());
    for (HotfixData const& hotfix : Hotfixes)
        _worldPacket << hotfix;

    _worldPacket << uint32(HotfixContent.size());
    _worldPacket.append(HotfixContent);

    return &_worldPacket;
}
}
}
