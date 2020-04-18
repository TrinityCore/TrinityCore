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

#include "CharacterCache.h"
#include "Player.h"
#include "QueryPackets.h"

void WorldPackets::Query::DBQueryBulk::Read()
{
    _worldPacket >> TableHash;

    uint32 count = _worldPacket.ReadBits(23);
    Queries.resize(count);

    for (uint32 i = 0; i < count; ++i)
    {
        Queries[i].GUID[0] = _worldPacket.ReadBit();
        Queries[i].GUID[4] = _worldPacket.ReadBit();
        Queries[i].GUID[7] = _worldPacket.ReadBit();
        Queries[i].GUID[2] = _worldPacket.ReadBit();
        Queries[i].GUID[5] = _worldPacket.ReadBit();
        Queries[i].GUID[3] = _worldPacket.ReadBit();
        Queries[i].GUID[6] = _worldPacket.ReadBit();
        Queries[i].GUID[1] = _worldPacket.ReadBit();
    }

    for (uint32 i = 0; i < count; ++i)
    {
        _worldPacket.ReadByteSeq(Queries[i].GUID[5]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[6]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[7]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[0]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[1]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[3]);
        _worldPacket.ReadByteSeq(Queries[i].GUID[4]);
        _worldPacket >> Queries[i].RecordID;
        _worldPacket.ReadByteSeq(Queries[i].GUID[2]);
    }
}

WorldPacket const* WorldPackets::Query::DBReply::Write()
{
    _worldPacket << RecordID;
    _worldPacket << TableHash;
    _worldPacket << Timestamp;
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::HotfixNotifyBlob::Write()
{
    _worldPacket.WriteBits(Hotfixes->size(), 22);
    _worldPacket.FlushBits();

    for (HotfixNotify const& hotfix : *Hotfixes)
    {
        _worldPacket << uint32(hotfix.TableHash);
        _worldPacket << uint32(hotfix.Timestamp);
        _worldPacket << int32(hotfix.Entry);
    }

    return &_worldPacket;
}

bool WorldPackets::Query::PlayerGuidLookupData::Initialize(ObjectGuid const& guid, Player const* player /*= nullptr*/)
{
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid);
    if (!characterInfo)
        return false;

    if (player)
    {
        ASSERT(player->GetGUID() == guid);

        Name = player->GetName();
        Race = player->getRace();
        Sex = player->getGender();
        ClassID = player->getClass();
        Level = player->getLevel();
    }
    else
    {
        Name = characterInfo->Name;
        Race = characterInfo->Race;
        Sex = characterInfo->Sex;
        ClassID = characterInfo->Class;
        Level = characterInfo->Level;
    }

    return true;
}
