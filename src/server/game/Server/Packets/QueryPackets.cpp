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

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
    _worldPacket >> GUID;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << uint32(CreatureID | (Allow ? 0x00000000 : 0x80000000)); // creature entry

    if (Allow)
    {
        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
            _worldPacket << Stats.Name[i];

        for (std::size_t i = 0; i < Stats.NameAlt.size(); ++i)
            _worldPacket << Stats.NameAlt[i];

        _worldPacket << Stats.Title;

        _worldPacket << Stats.CursorName;                                   // "Directions" for guard, string for Icons 2.3.0
        _worldPacket.append(Stats.Flags.data(), Stats.Flags.size());        // flags
        _worldPacket << uint32(Stats.CreatureType);                         // CreatureType.dbc
        _worldPacket << uint32(Stats.CreatureFamily);                       // CreatureFamily.dbc
        _worldPacket << uint32(Stats.Classification);                       // Creature Rank (elite, boss, etc)
        _worldPacket.append(Stats.ProxyCreatureID.data(), Stats.ProxyCreatureID.size());
        _worldPacket.append(Stats.CreatureDisplayID.data(), Stats.CreatureDisplayID.size());  // Modelid
        _worldPacket << float(Stats.HpMulti);                               // dmg/hp modifier
        _worldPacket << float(Stats.EnergyMulti);                           // dmg/mana modifier
        _worldPacket << uint8(Stats.Leader);
        _worldPacket.append(Stats.QuestItems.data(), Stats.QuestItems.size());
        _worldPacket << uint32(Stats.CreatureMovementInfoID);               // CreatureMovementInfo.dbc
        _worldPacket << uint32(Stats.RequiredExpansion);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryGameObject::Read()
{
    _worldPacket >> GameObjectID;
    _worldPacket >> GUID;
}

WorldPacket const* WorldPackets::Query::QueryGameObjectResponse::Write()
{
    _worldPacket << uint32(GameObjectID | (Allow ? 0x00000000 : 0x80000000));

    if (Allow)
    {
        _worldPacket << uint32(Stats.Type);
        _worldPacket << uint32(Stats.DisplayID);

        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
            _worldPacket << Stats.Name[i];

        _worldPacket << Stats.IconName;                             // 2.0.3, string. Icon name to use instead of default icon for go's (ex: "Attack" makes sword)
        _worldPacket << Stats.CastBarCaption;                       // 2.0.3, string. Text will appear in Cast Bar when using GO (ex: "Collecting")
        _worldPacket << Stats.UnkString;                            // 2.0.3, string
        _worldPacket.append(Stats.Data.data(), Stats.Data.size());
        _worldPacket << float(Stats.Size);                          // go size
        _worldPacket.append(Stats.QuestItems.data(), Stats.QuestItems.size());
        _worldPacket << int32(Stats.RequiredLevel);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QuestPOIQuery::Read()
{
    _worldPacket >> MissingQuestCount;

    MissingQuestPOIs.fill(0);
    if (MissingQuestCount <= MAX_QUEST_LOG_SIZE)
    {
        for (std::size_t i = 0; i < MissingQuestCount; ++i)
            _worldPacket >> MissingQuestPOIs[i];
    }
    else
        _worldPacket.rfinish();
}

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

        if (DeclinedName const* names = player->GetDeclinedNames())
            DeclinedNames = *names;
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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupData const& lookupData)
{
    data << lookupData.Name;
    data << lookupData.RealmName;
    data << uint8(lookupData.Race);
    data << uint8(lookupData.Sex);
    data << uint8(lookupData.ClassID);

    data << bool(lookupData.DeclinedNames.has_value());
    if (lookupData.DeclinedNames.has_value())
        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << lookupData.DeclinedNames->name[i];

    return data;
}

WorldPacket const* WorldPackets::Query::QueryPlayerNameResponse::Write()
{
    _worldPacket << Player.WriteAsPacked();
    _worldPacket << uint8(Result);

    if (Result == RESPONSE_SUCCESS)
        _worldPacket << Data;

    return &_worldPacket;
}
