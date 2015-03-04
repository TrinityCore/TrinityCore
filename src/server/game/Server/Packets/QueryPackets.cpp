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

#include "QueryPackets.h"
#include "BattlenetAccountMgr.h"
#include "Player.h"
#include "World.h"
#include "ObjectMgr.h"

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << CreatureID;
    _worldPacket.WriteBit(Allow);

    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket.WriteBits(Stats.Title.length() + 1, 11);
        _worldPacket.WriteBits(Stats.TitleAlt.length() + 1, 11);
        _worldPacket.WriteBits(Stats.CursorName.length() + 1, 6);
        _worldPacket.WriteBit(Stats.Leader);

        for (uint32 i = 0; i < MAX_CREATURE_NAMES; ++i)
        {
            _worldPacket.WriteBits(Stats.Name[i].length() + 1, 11);
            _worldPacket.WriteBits(Stats.NameAlt[i].length() + 1, 11);
        }

        for (uint32 i = 0; i < MAX_CREATURE_NAMES; ++i)
        {
            if (!Stats.Name[i].empty())
                _worldPacket << Stats.Name[i];

            if (!Stats.NameAlt[i].empty())
                _worldPacket << Stats.NameAlt[i];
        }

        for (uint8 i = 0; i < 2; ++i)
            _worldPacket << Stats.Flags[i];

        _worldPacket << Stats.CreatureType;
        _worldPacket << Stats.CreatureFamily;
        _worldPacket << Stats.Classification;

        for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
            _worldPacket << Stats.ProxyCreatureID[i];

        for (uint32 i = 0; i < MAX_CREATURE_MODELS; ++i)
            _worldPacket << Stats.CreatureDisplayID[i];

        _worldPacket << Stats.HpMulti;
        _worldPacket << Stats.EnergyMulti;

        _worldPacket << int32(Stats.QuestItems.size());
        _worldPacket << Stats.CreatureMovementInfoID;
        _worldPacket << Stats.RequiredExpansion;

        _worldPacket << int32(0); // FlagQuest

        if (!Stats.Title.empty())
            _worldPacket << Stats.Title;

        if (!Stats.TitleAlt.empty())
            _worldPacket << Stats.TitleAlt;

        if (!Stats.CursorName.empty())
            _worldPacket << Stats.CursorName;

        for (int32 questItem : Stats.QuestItems)
            _worldPacket << questItem;
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryPlayerName::Read()
{
    _worldPacket >> Player;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupHint const& lookupHint)
{
    data.WriteBit(lookupHint.VirtualRealmAddress.HasValue);
    data.WriteBit(lookupHint.NativeRealmAddress.HasValue);
    data.FlushBits();

    if (lookupHint.VirtualRealmAddress.HasValue)
        data << uint32(lookupHint.VirtualRealmAddress.Value);

    if (lookupHint.NativeRealmAddress.HasValue)
        data << uint32(lookupHint.NativeRealmAddress.Value);

    return data;
}

bool WorldPackets::Query::PlayerGuidLookupData::Initialize(ObjectGuid const& guid, Player const* player /*= nullptr*/)
{
    CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid);
    if (!characterInfo)
        return false;

    if (player)
    {
        ASSERT(player->GetGUID() == guid);

        AccountID     = player->GetSession()->GetAccountGUID();
        BnetAccountID = player->GetSession()->GetBattlenetAccountGUID();
        Name          = player->GetName();
        Race          = player->getRace();
        Sex           = player->getGender();
        ClassID       = player->getClass();
        Level         = player->getLevel();

        if (DeclinedName const* names = player->GetDeclinedNames())
            DeclinedNames = *names;
    }
    else
    {
        uint32 accountId = ObjectMgr::GetPlayerAccountIdByGUID(guid);
        uint32 bnetAccountId = Battlenet::AccountMgr::GetIdByGameAccount(accountId);

        AccountID     = ObjectGuid::Create<HighGuid::WowAccount>(accountId);
        BnetAccountID = ObjectGuid::Create<HighGuid::BNetAccount>(bnetAccountId);
        Name          = characterInfo->Name;
        Race          = characterInfo->Race;
        Sex           = characterInfo->Sex;
        ClassID       = characterInfo->Class;
        Level         = characterInfo->Level;
    }

    IsDeleted = characterInfo->IsDeleted;
    GuidActual = guid;
    VirtualRealmAddress = GetVirtualRealmAddress();

    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupData const& lookupData)
{
    data.WriteBit(lookupData.IsDeleted);
    data.WriteBits(lookupData.Name.length(), 6);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        data.WriteBits(lookupData.DeclinedNames.name[i].length(), 7);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        data.WriteString(lookupData.DeclinedNames.name[i]);

    data << lookupData.AccountID;
    data << lookupData.BnetAccountID;
    data << lookupData.GuidActual;
    data << uint32(lookupData.VirtualRealmAddress);
    data << uint8(lookupData.Race);
    data << uint8(lookupData.Sex);
    data << uint8(lookupData.ClassID);
    data << uint8(lookupData.Level);
    data.WriteString(lookupData.Name);

    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Query::QueryPlayerNameResponse::Write()
{
    _worldPacket << Result;
    _worldPacket << Player;

    if (Result == RESPONSE_SUCCESS)
        _worldPacket << Data;

    return &_worldPacket;
}

void WorldPackets::Query::QueryPageText::Read()
{
    _worldPacket >> PageTextID;
    _worldPacket >> ItemGUID;
}

WorldPacket const* WorldPackets::Query::QueryPageTextResponse::Write()
{
    _worldPacket << PageTextID;
    _worldPacket.WriteBit(Allow);

    if (Allow)
    {
        _worldPacket << Info.ID;
        _worldPacket << Info.NextPageID;
        _worldPacket.WriteBits(Info.Text.length(), 12);
        _worldPacket.WriteString(Info.Text);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryNPCText::Read()
{
    _worldPacket >> TextID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryNPCTextResponse::Write()
{
    _worldPacket << TextID;
    _worldPacket.WriteBit(Allow);

    if (Allow)
    {
        _worldPacket << int32(MAX_GOSSIP_TEXT_OPTIONS * (4 + 4));
        for (uint32 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
            _worldPacket << Probabilities[i];
        for (uint32 i = 0; i < MAX_GOSSIP_TEXT_OPTIONS; ++i)
            _worldPacket << BroadcastTextID[i];
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Query::DBQueryBulk::Read()
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

WorldPacket const* WorldPackets::Query::DBReply::Write()
{
    _worldPacket << TableHash;
    _worldPacket << RecordID;
    _worldPacket << Timestamp;
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::HotfixNotifyBlob::Write()
{
    _worldPacket << uint32(Hotfixes->size());
    for (HotfixNotify const& hotfix : *Hotfixes)
    {
        _worldPacket << uint32(hotfix.TableHash);
        _worldPacket << int32(hotfix.Entry);
        _worldPacket << uint32(hotfix.Timestamp);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryGameObject::Read()
{
    _worldPacket >> GameObjectID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryGameObjectResponse::Write()
{
    _worldPacket << GameObjectID;
    _worldPacket.WriteBit(Allow);

    if (Allow)
    {
        uint32 dataSize = Stats.GetDataSize();

        _worldPacket << uint32(dataSize);
        if (dataSize)
        {
            _worldPacket << Stats.Type;
            _worldPacket << Stats.DisplayID;
            for (int8 i = 0; i < 4; i++)
                _worldPacket << Stats.Name[i];

            _worldPacket << Stats.IconName;
            _worldPacket << Stats.CastBarCaption;
            _worldPacket << Stats.UnkString;

            for (uint32 i = 0; i < MAX_GAMEOBJECT_DATA; i++)
                _worldPacket << Stats.Data[i];

            _worldPacket << Stats.Size;

            _worldPacket << uint8(Stats.QuestItems.size());
            for (int32 questItem : Stats.QuestItems)
                _worldPacket << questItem;

            _worldPacket << Stats.Expansion;
        }
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::CorpseLocation::Write()
{
    _worldPacket.WriteBit(Valid);
    _worldPacket.FlushBits();

    _worldPacket << ActualMapID;
    _worldPacket << Position.x;
    _worldPacket << Position.y;
    _worldPacket << Position.z;
    _worldPacket << MapID;
    _worldPacket << Transport;

    return &_worldPacket;
}

void WorldPackets::Query::QueryCorpseTransport::Read()
{
    _worldPacket >> Transport;
}

WorldPacket const* WorldPackets::Query::CorpseTransportQuery::Write()
{
    _worldPacket << Position.x;
    _worldPacket << Position.y;
    _worldPacket << Position.z;
    _worldPacket << Facing;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::QueryTimeResponse::Write()
{
    _worldPacket << uint32(CurrentTime);
    _worldPacket << int32(TimeOutRequest);

    return &_worldPacket;
}
