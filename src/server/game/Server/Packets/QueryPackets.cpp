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

#include "QueryPackets.h"
#include "BattlenetAccountMgr.h"
#include "CharacterCache.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << uint32(CreatureID);
    _worldPacket.WriteBit(Allow);

    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket.WriteBits(Stats.Title.length() + 1, 11);
        _worldPacket.WriteBits(Stats.TitleAlt.length() + 1, 11);
        _worldPacket.WriteBits(Stats.CursorName.length() + 1, 6);
        _worldPacket.WriteBit(Stats.Leader);

        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
        {
            _worldPacket.WriteBits(Stats.Name[i].length() + 1, 11);
            _worldPacket.WriteBits(Stats.NameAlt[i].length() + 1, 11);
        }

        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
        {
            if (!Stats.Name[i].empty())
                _worldPacket << Stats.Name[i];

            if (!Stats.NameAlt[i].empty())
                _worldPacket << Stats.NameAlt[i];
        }

        _worldPacket.append(Stats.Flags.data(), Stats.Flags.size());
        _worldPacket << int32(Stats.CreatureType);
        _worldPacket << int32(Stats.CreatureFamily);
        _worldPacket << int32(Stats.Classification);
        _worldPacket.append(Stats.ProxyCreatureID.data(), Stats.ProxyCreatureID.size());
        _worldPacket << uint32(Stats.Display.CreatureDisplay.size());
        _worldPacket << float(Stats.Display.TotalProbability);

        for (CreatureXDisplay const& display : Stats.Display.CreatureDisplay)
        {
            _worldPacket << uint32(display.CreatureDisplayID);
            _worldPacket << float(display.Scale);
            _worldPacket << float(display.Probability);
        }

        _worldPacket << float(Stats.HpMulti);
        _worldPacket << float(Stats.EnergyMulti);
        _worldPacket << uint32(Stats.QuestItems.size());
        _worldPacket << int32(Stats.CreatureMovementInfoID);
        _worldPacket << int32(Stats.HealthScalingExpansion);
        _worldPacket << int32(Stats.RequiredExpansion);
        _worldPacket << int32(Stats.VignetteID);
        _worldPacket << int32(Stats.Class);
        _worldPacket << int32(Stats.WidgetSetID);
        _worldPacket << int32(Stats.WidgetSetUnitConditionID);

        if (!Stats.Title.empty())
            _worldPacket << Stats.Title;

        if (!Stats.TitleAlt.empty())
            _worldPacket << Stats.TitleAlt;

        if (!Stats.CursorName.empty())
            _worldPacket << Stats.CursorName;

        if (!Stats.QuestItems.empty())
            _worldPacket.append(Stats.QuestItems.data(), Stats.QuestItems.size());
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryPlayerName::Read()
{
    _worldPacket >> Player;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupHint const& lookupHint)
{
    data.WriteBit(lookupHint.VirtualRealmAddress.is_initialized());
    data.WriteBit(lookupHint.NativeRealmAddress.is_initialized());
    data.FlushBits();

    if (lookupHint.VirtualRealmAddress)
        data << uint32(*lookupHint.VirtualRealmAddress);

    if (lookupHint.NativeRealmAddress)
        data << uint32(*lookupHint.NativeRealmAddress);

    return data;
}

bool WorldPackets::Query::PlayerGuidLookupData::Initialize(ObjectGuid const& guid, Player const* player /*= nullptr*/)
{
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid);
    if (!characterInfo)
        return false;

    if (player)
    {
        ASSERT(player->GetGUID() == guid);

        AccountID     = player->GetSession()->GetAccountGUID();
        BnetAccountID = player->GetSession()->GetBattlenetAccountGUID();
        Name          = player->GetName();
        Race          = player->getRace();
        Sex           = player->GetNativeSex();
        ClassID       = player->getClass();
        Level         = player->getLevel();

        if (DeclinedName const* names = player->GetDeclinedNames())
            DeclinedNames = *names;
    }
    else
    {
        uint32 accountId = sCharacterCache->GetCharacterAccountIdByGuid(guid);
        uint32 bnetAccountId = ::Battlenet::AccountMgr::GetIdByGameAccount(accountId);

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
    data << uint64(lookupData.GuildClubMemberID);
    data << uint32(lookupData.VirtualRealmAddress);
    data << uint8(lookupData.Race);
    data << uint8(lookupData.Sex);
    data << uint8(lookupData.ClassID);
    data << uint8(lookupData.Level);
    data.WriteString(lookupData.Name);

    return data;
}

WorldPacket const* WorldPackets::Query::QueryPlayerNameResponse::Write()
{
    _worldPacket << uint8(Result);
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


ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::QueryPageTextResponse::PageTextInfo const& page)
{
    data << uint32(page.ID);
    data << uint32(page.NextPageID);
    data << int32(page.PlayerConditionID);
    data << uint8(page.Flags);
    data.WriteBits(page.Text.length(), 12);
    data.FlushBits();

    data.WriteString(page.Text);

    return data;
}

WorldPacket const* WorldPackets::Query::QueryPageTextResponse::Write()
{
    _worldPacket << uint32(PageTextID);
    _worldPacket.WriteBit(Allow);

    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << uint32(Pages.size());
        for (PageTextInfo const& pageText : Pages)
            _worldPacket << pageText;
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
    _worldPacket << uint32(TextID);
    _worldPacket.WriteBit(Allow);

    _worldPacket.FlushBits();

    _worldPacket << int32(Allow ? (MAX_NPC_TEXT_OPTIONS * (sizeof(float) + sizeof(uint32))) : 0);

    if (Allow)
    {
        _worldPacket.append(Probabilities.data(), Probabilities.size());
        _worldPacket.append(BroadcastTextID.data(), BroadcastTextID.size());
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
    _worldPacket << Guid;
    _worldPacket.WriteBit(Allow);
    _worldPacket.FlushBits();

    ByteBuffer statsData;
    if (Allow)
    {
        statsData << int32(Stats.Type);
        statsData << int32(Stats.DisplayID);
        for (int8 i = 0; i < 4; ++i)
            statsData << Stats.Name[i];

        statsData << Stats.IconName;
        statsData << Stats.CastBarCaption;
        statsData << Stats.UnkString;

        for (uint32 i = 0; i < MAX_GAMEOBJECT_DATA; ++i)
            statsData << int32(Stats.Data[i]);

        statsData << float(Stats.Size);
        statsData << uint8(Stats.QuestItems.size());
        if (!Stats.QuestItems.empty())
            statsData.append(Stats.QuestItems.data(), Stats.QuestItems.size());

        statsData << int32(Stats.ContentTuningId);
    }

    _worldPacket << uint32(statsData.size());
    if (!statsData.empty())
        _worldPacket.append(statsData);

    return &_worldPacket;
}

void WorldPackets::Query::QueryCorpseLocationFromClient::Read()
{
    _worldPacket >> Player;
}

WorldPacket const* WorldPackets::Query::CorpseLocation::Write()
{
    _worldPacket.WriteBit(Valid);
    _worldPacket.FlushBits();

    _worldPacket << Player;
    _worldPacket << ActualMapID;
    _worldPacket << Position;
    _worldPacket << MapID;
    _worldPacket << Transport;

    return &_worldPacket;
}

void WorldPackets::Query::QueryCorpseTransport::Read()
{
    _worldPacket >> Player;
    _worldPacket >> Transport;
}

WorldPacket const* WorldPackets::Query::CorpseTransportQuery::Write()
{
    _worldPacket << Player;
    _worldPacket << Position;
    _worldPacket << Facing;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Query::QueryTimeResponse::Write()
{
    _worldPacket << int32(CurrentTime);

    return &_worldPacket;
}

void WorldPackets::Query::QuestPOIQuery::Read()
{
    _worldPacket >> MissingQuestCount;

    for (std::size_t i = 0; i < MissingQuestPOIs.size(); ++i)
        _worldPacket >> MissingQuestPOIs[i];
}

ByteBuffer& operator<<(ByteBuffer& data, QuestPOIData const& questPOIData)
{
    data << int32(questPOIData.QuestID);
    data << int32(questPOIData.Blobs.size());

    for (QuestPOIBlobData const& questPOIBlobData : questPOIData.Blobs)
    {
        data << int32(questPOIBlobData.BlobIndex);
        data << int32(questPOIBlobData.ObjectiveIndex);
        data << int32(questPOIBlobData.QuestObjectiveID);
        data << int32(questPOIBlobData.QuestObjectID);
        data << int32(questPOIBlobData.MapID);
        data << int32(questPOIBlobData.UiMapID);
        data << int32(questPOIBlobData.Priority);
        data << int32(questPOIBlobData.Flags);
        data << int32(questPOIBlobData.WorldEffectID);
        data << int32(questPOIBlobData.PlayerConditionID);
        data << int32(questPOIBlobData.NavigationPlayerConditionID);
        data << int32(questPOIBlobData.SpawnTrackingID);
        data << int32(questPOIBlobData.Points.size());

        for (QuestPOIBlobPoint const& questPOIBlobPoint : questPOIBlobData.Points)
        {
            data << int16(questPOIBlobPoint.X);
            data << int16(questPOIBlobPoint.Y);
            data << int16(questPOIBlobPoint.Z);
        }

        data.WriteBit(questPOIBlobData.AlwaysAllowMergingBlobs);
        data.FlushBits();
    }

    return data;
}

WorldPacket const* WorldPackets::Query::QuestPOIQueryResponse::Write()
{
    _worldPacket << int32(QuestPOIDataStats.size());
    _worldPacket << int32(QuestPOIDataStats.size());

    bool useCache = sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES);

    for (QuestPOIData const* questPOIData : QuestPOIDataStats)
    {
        if (useCache)
            _worldPacket.append(questPOIData->QueryDataBuffer);
        else
            _worldPacket << *questPOIData;
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryQuestCompletionNPCs::Read()
{
    QuestCompletionNPCs.resize(_worldPacket.read<uint32>());
    if (!QuestCompletionNPCs.empty())
        _worldPacket.read(QuestCompletionNPCs.data(), QuestCompletionNPCs.size());
}

WorldPacket const* WorldPackets::Query::QuestCompletionNPCResponse::Write()
{
    _worldPacket << uint32(QuestCompletionNPCs.size());
    for (auto& quest : QuestCompletionNPCs)
    {
        _worldPacket << int32(quest.QuestID);
        _worldPacket << uint32(quest.NPCs.size());
        if (!quest.NPCs.empty())
            _worldPacket.append(quest.NPCs.data(), quest.NPCs.size());
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryPetName::Read()
{
    _worldPacket >> UnitGUID;
}

WorldPacket const* WorldPackets::Query::QueryPetNameResponse::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket.WriteBit(Allow);

    if (Allow)
    {
        _worldPacket.WriteBits(Name.length(), 8);
        _worldPacket.WriteBit(HasDeclined);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket.WriteBits(DeclinedNames.name[i].length(), 7);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket.WriteString(DeclinedNames.name[i]);

        _worldPacket << Timestamp;
        _worldPacket.WriteString(Name);
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Query::ItemTextQuery::Read()
{
    _worldPacket >> Id;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::ItemTextCache const& itemTextCache)
{
    data.WriteBits(itemTextCache.Text.length(), 13);
    data.FlushBits();

    data.WriteString(itemTextCache.Text);

    return data;
}

WorldPacket const* WorldPackets::Query::QueryItemTextResponse::Write()
{
    _worldPacket.WriteBit(Valid);
    _worldPacket.FlushBits();
    _worldPacket << Item;
    _worldPacket << Id;

    return &_worldPacket;
}

void WorldPackets::Query::QueryRealmName::Read()
{
    _worldPacket >> VirtualRealmAddress;
}

WorldPacket const* WorldPackets::Query::RealmQueryResponse::Write()
{
    _worldPacket << uint32(VirtualRealmAddress);
    _worldPacket << uint8(LookupState);
    if (!LookupState)
        _worldPacket << NameInfo;

    return &_worldPacket;
}
