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
#include "ClubUtils.h"
#include "ObjectMgr.h"
#include "PacketOperators.h"
#include "Player.h"
#include "World.h"

ByteBuffer& operator<<(ByteBuffer& data, QuestPOIData const& questPOIData)
{
    data << int32(questPOIData.QuestID);
    data << WorldPackets::Size<int32>(questPOIData.Blobs);

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
        data << WorldPackets::Size<int32>(questPOIBlobData.Points);

        for (QuestPOIBlobPoint const& questPOIBlobPoint : questPOIBlobData.Points)
        {
            data << int16(questPOIBlobPoint.X);
            data << int16(questPOIBlobPoint.Y);
            data << int16(questPOIBlobPoint.Z);
        }

        data << WorldPackets::Bits<1>(questPOIBlobData.AlwaysAllowMergingBlobs);
        data.FlushBits();
    }

    return data;
}

namespace WorldPackets::Query
{
void QueryCreature::Read()
{
    _worldPacket >> CreatureID;
}

WorldPacket const* QueryCreatureResponse::Write()
{
    _worldPacket << uint32(CreatureID);
    _worldPacket << Bits<1>(Allow);

    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << SizedCString::BitsSize<11>(Stats.Title);
        _worldPacket << SizedCString::BitsSize<11>(Stats.TitleAlt);
        _worldPacket << SizedCString::BitsSize<6>(Stats.CursorName);
        _worldPacket << Bits<1>(Stats.Leader);

        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
        {
            _worldPacket << SizedCString::BitsSize<11>(Stats.Name[i]);
            _worldPacket << SizedCString::BitsSize<11>(Stats.NameAlt[i]);
        }

        for (std::size_t i = 0; i < Stats.Name.size(); ++i)
        {
            _worldPacket << SizedCString::Data(Stats.Name[i]);
            _worldPacket << SizedCString::Data(Stats.NameAlt[i]);
        }

        _worldPacket.append(Stats.Flags.data(), Stats.Flags.size());
        _worldPacket << uint8(Stats.CreatureType);
        _worldPacket << int32(Stats.CreatureFamily);
        _worldPacket << int8(Stats.Classification);
        _worldPacket.append(Stats.ProxyCreatureID.data(), Stats.ProxyCreatureID.size());
        _worldPacket << Size<uint32>(Stats.Display.CreatureDisplay);
        _worldPacket << float(Stats.Display.TotalProbability);

        for (CreatureXDisplay const& display : Stats.Display.CreatureDisplay)
        {
            _worldPacket << uint32(display.CreatureDisplayID);
            _worldPacket << float(display.Scale);
            _worldPacket << float(display.Probability);
        }

        _worldPacket << float(Stats.HpMulti);
        _worldPacket << float(Stats.EnergyMulti);
        _worldPacket << Size<uint32>(Stats.QuestItems);
        _worldPacket << Size<uint32>(Stats.QuestCurrencies);
        _worldPacket << int32(Stats.CreatureMovementInfoID);
        _worldPacket << int32(Stats.HealthScalingExpansion);
        _worldPacket << int32(Stats.RequiredExpansion);
        _worldPacket << int32(Stats.VignetteID);
        _worldPacket << int32(Stats.Class);
        _worldPacket << int32(Stats.CreatureDifficultyID);
        _worldPacket << int32(Stats.WidgetSetID);
        _worldPacket << int32(Stats.WidgetSetUnitConditionID);

        _worldPacket << SizedCString::Data(Stats.Title);
        _worldPacket << SizedCString::Data(Stats.TitleAlt);
        _worldPacket << SizedCString::Data(Stats.CursorName);

        if (!Stats.QuestItems.empty())
            _worldPacket.append(Stats.QuestItems.data(), Stats.QuestItems.size());

        if (!Stats.QuestCurrencies.empty())
            _worldPacket.append(Stats.QuestCurrencies.data(), Stats.QuestCurrencies.size());
    }

    return &_worldPacket;
}

void QueryPlayerNames::Read()
{
    _worldPacket >> Size<uint32>(Players);
    for (ObjectGuid& player : Players)
        _worldPacket >> player;
}

bool PlayerGuidLookupData::Initialize(ObjectGuid const& guid, Player const* player /*= nullptr*/)
{
    CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid);
    if (!characterInfo)
        return false;

    if (player)
    {
        ASSERT(player->GetGUID() == guid);

        AccountID     = player->m_playerData->WowAccount;
        BnetAccountID = player->m_playerData->BnetAccount;
        Name          = player->GetName();
        Race          = player->GetRace();
        Sex           = player->GetNativeGender();
        ClassID       = player->GetClass();
        Level         = player->GetLevel();
        PvpFaction    = player->GetTeamId() == TEAM_ALLIANCE ? 1 : 0;
        TimerunningSeasonID = player->m_activePlayerData->TimerunningSeasonID;

        if (UF::DeclinedNames const* names = player->GetDeclinedNames())
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
        PvpFaction    = Player::TeamIdForRace(characterInfo->Race) == TEAM_ALLIANCE ? 1 : 0;
    }

    IsDeleted = characterInfo->IsDeleted;
    GuidActual = guid;
    GuildClubMemberID = ::Battlenet::Services::Clubs::CreateClubMemberId(guid);
    VirtualRealmAddress = GetVirtualRealmAddress();

    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, PlayerGuidLookupData const& lookupData)
{
    data << Bits<1>(lookupData.IsDeleted);
    data << SizedString::BitsSize<6>(lookupData.Name);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        data << SizedString::BitsSize<7>(lookupData.DeclinedNames.name[i]);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        data << SizedString::Data(lookupData.DeclinedNames.name[i]);

    data << lookupData.AccountID;
    data << lookupData.BnetAccountID;
    data << lookupData.GuidActual;
    data << uint64(lookupData.GuildClubMemberID);
    data << uint32(lookupData.VirtualRealmAddress);
    data << uint8(lookupData.Race);
    data << uint8(lookupData.Sex);
    data << uint8(lookupData.ClassID);
    data << uint8(lookupData.Level);
    data << uint8(lookupData.PvpFaction);
    data << int32(lookupData.TimerunningSeasonID);
    data << SizedString::Data(lookupData.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildGuidLookupData const& lookupData)
{
    data << uint32(lookupData.VirtualRealmAddress);
    data << lookupData.Guid;
    data << SizedString::BitsSize<7>(lookupData.Name);
    data.FlushBits();

    data << SizedString::Data(lookupData.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, NameCacheLookupResult const& result)
{
    data << uint8(result.Result);
    data << result.Player;
    data << OptionalInit(result.Data);
    data << OptionalInit(result.GuildData);
    data.FlushBits();

    if (result.Data)
        data << *result.Data;

    if (result.GuildData)
        data << *result.GuildData;

    return data;
}

WorldPacket const* QueryPlayerNamesResponse::Write()
{
    _worldPacket << Size<uint32>(Players);
    for (NameCacheLookupResult const& lookupResult : Players)
        _worldPacket << lookupResult;

    return &_worldPacket;
}

void QueryPageText::Read()
{
    _worldPacket >> PageTextID;
    _worldPacket >> ItemGUID;
}

ByteBuffer& operator<<(ByteBuffer& data, QueryPageTextResponse::PageTextInfo const& page)
{
    data << uint32(page.ID);
    data << uint32(page.NextPageID);
    data << int32(page.PlayerConditionID);
    data << uint8(page.Flags);
    data << SizedString::BitsSize<12>(page.Text);
    data.FlushBits();

    data << SizedString::Data(page.Text);

    return data;
}

WorldPacket const* QueryPageTextResponse::Write()
{
    _worldPacket << uint32(PageTextID);
    _worldPacket << Bits<1>(Allow);
    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << Size<uint32>(Pages);
        for (PageTextInfo const& pageText : Pages)
            _worldPacket << pageText;
    }

    return &_worldPacket;
}

void QueryNPCText::Read()
{
    _worldPacket >> TextID;
    _worldPacket >> Guid;
}

WorldPacket const* QueryNPCTextResponse::Write()
{
    _worldPacket << uint32(TextID);
    _worldPacket << Bits<1>(Allow);
    _worldPacket.FlushBits();

    _worldPacket << int32(Allow ? (MAX_NPC_TEXT_OPTIONS * (sizeof(float) + sizeof(uint32))) : 0);

    if (Allow)
    {
        _worldPacket.append(Probabilities.data(), Probabilities.size());
        _worldPacket.append(BroadcastTextID.data(), BroadcastTextID.size());
    }

    return &_worldPacket;
}

void QueryGameObject::Read()
{
    _worldPacket >> GameObjectID;
    _worldPacket >> Guid;
}

WorldPacket const* QueryGameObjectResponse::Write()
{
    _worldPacket << GameObjectID;
    _worldPacket << Guid;
    _worldPacket << Bits<1>(Allow);
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
        statsData << Size<uint8>(Stats.QuestItems);
        if (!Stats.QuestItems.empty())
            statsData.append(Stats.QuestItems.data(), Stats.QuestItems.size());

        statsData << int32(Stats.ContentTuningId);
    }

    _worldPacket << Size<uint32>(statsData);
    if (!statsData.empty())
        _worldPacket.append(statsData);

    return &_worldPacket;
}

void QueryCorpseLocationFromClient::Read()
{
    _worldPacket >> Player;
}

WorldPacket const* CorpseLocation::Write()
{
    _worldPacket << Bits<1>(Valid);
    _worldPacket.FlushBits();

    _worldPacket << Player;
    _worldPacket << ActualMapID;
    _worldPacket << MapID;
    _worldPacket << Transport;
    _worldPacket << Position;

    return &_worldPacket;
}

void QueryCorpseTransport::Read()
{
    _worldPacket >> Player;
    _worldPacket >> Transport;
}

WorldPacket const* CorpseTransportQuery::Write()
{
    _worldPacket << Player;
    _worldPacket << Position;
    _worldPacket << Facing;

    return &_worldPacket;
}

WorldPacket const* QueryTimeResponse::Write()
{
    _worldPacket << CurrentTime;

    return &_worldPacket;
}

void QuestPOIQuery::Read()
{
    _worldPacket >> MissingQuestCount;

    if (MissingQuestCount > std::ssize(MissingQuestPOIs))
        OnInvalidArraySize(MissingQuestCount, MissingQuestPOIs.size());

    for (std::size_t i = 0; i < MissingQuestPOIs.size(); ++i)
        _worldPacket >> MissingQuestPOIs[i];
}

WorldPacket const* QuestPOIQueryResponse::Write()
{
    _worldPacket << Size<int32>(QuestPOIDataStats);
    _worldPacket << Size<int32>(QuestPOIDataStats);

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

void QueryQuestCompletionNPCs::Read()
{
    _worldPacket >> Size<uint32>(QuestCompletionNPCs);
    if (!QuestCompletionNPCs.empty())
        _worldPacket.read(QuestCompletionNPCs.data(), QuestCompletionNPCs.size());
}

WorldPacket const* QuestCompletionNPCResponse::Write()
{
    _worldPacket << Size<uint32>(QuestCompletionNPCs);
    for (QuestCompletionNPC& quest : QuestCompletionNPCs)
    {
        _worldPacket << int32(quest.QuestID);
        _worldPacket << Size<uint32>(quest.NPCs);
        if (!quest.NPCs.empty())
            _worldPacket.append(quest.NPCs.data(), quest.NPCs.size());
    }

    return &_worldPacket;
}

void QueryPetName::Read()
{
    _worldPacket >> UnitGUID;
}

WorldPacket const* QueryPetNameResponse::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Bits<1>(Allow);

    if (Allow)
    {
        _worldPacket << SizedString::BitsSize<8>(Name);
        _worldPacket << Bits<1>(HasDeclined);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket << SizedString::BitsSize<7>(DeclinedNames.name[i]);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket << SizedString::Data(DeclinedNames.name[i]);

        _worldPacket << Timestamp;
        _worldPacket << SizedString::Data(Name);
    }
    else
        _worldPacket.FlushBits();

    return &_worldPacket;
}

void ItemTextQuery::Read()
{
    _worldPacket >> Id;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemTextCache const& itemTextCache)
{
    data << SizedString::BitsSize<13>(itemTextCache.Text);
    data.FlushBits();

    data << SizedString::Data(itemTextCache.Text);

    return data;
}

WorldPacket const* QueryItemTextResponse::Write()
{
    _worldPacket << Bits<1>(Valid);
    _worldPacket.FlushBits();
    _worldPacket << Item;
    _worldPacket << Id;

    return &_worldPacket;
}

void QueryRealmName::Read()
{
    _worldPacket >> VirtualRealmAddress;
}

WorldPacket const* RealmQueryResponse::Write()
{
    _worldPacket << uint32(VirtualRealmAddress);
    _worldPacket << uint8(LookupState);
    if (!LookupState)
        _worldPacket << NameInfo;

    return &_worldPacket;
}

void QueryTreasurePicker::Read()
{
    _worldPacket >> QuestID;
    _worldPacket >> TreasurePickerID;
}

ByteBuffer& operator<<(ByteBuffer& data, TreasurePickItem const& treasurePickItem)
{
    data << treasurePickItem.Item;
    data << uint32(treasurePickItem.Quantity);
    data << OptionalInit(treasurePickItem.ContextFlags);
    data.FlushBits();

    if (treasurePickItem.ContextFlags)
        data << As<int32>(*treasurePickItem.ContextFlags);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TreasurePickCurrency const& treasurePickCurrency)
{
    data << uint32(treasurePickCurrency.CurrencyID);
    data << uint32(treasurePickCurrency.Quantity);
    data << OptionalInit(treasurePickCurrency.ContextFlags);
    data.FlushBits();

    if (treasurePickCurrency.ContextFlags)
        data << As<int32>(*treasurePickCurrency.ContextFlags);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TreasurePickerBonus const& treasurePickerBonus)
{
    data << Size<uint32>(treasurePickerBonus.ItemPicks);
    data << Size<uint32>(treasurePickerBonus.CurrencyPicks);
    data << uint64(treasurePickerBonus.Gold);
    data << Bits<1>(treasurePickerBonus.Context);
    data.FlushBits();

    for (TreasurePickItem const& treasurePickerItem : treasurePickerBonus.ItemPicks)
        data << treasurePickerItem;

    for (TreasurePickCurrency const& treasurePickCurrency : treasurePickerBonus.CurrencyPicks)
        data << treasurePickCurrency;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TreasurePickerPick const& treasurePickerPick)
{
    data << Size<uint32>(treasurePickerPick.ItemPicks);
    data << Size<uint32>(treasurePickerPick.CurrencyPicks);
    data << uint64(treasurePickerPick.Gold);
    data << Size<uint32>(treasurePickerPick.Bonuses);
    data << int32(treasurePickerPick.Flags);
    data << Bits<1>(treasurePickerPick.IsChoice);
    data.FlushBits();

    for (TreasurePickItem const& treasurePickItem : treasurePickerPick.ItemPicks)
        data << treasurePickItem;

    for (TreasurePickCurrency const& treasurePickCurrency : treasurePickerPick.CurrencyPicks)
        data << treasurePickCurrency;

    for (TreasurePickerBonus const& treasurePickerBonus : treasurePickerPick.Bonuses)
        data << treasurePickerBonus;

    return data;
}

WorldPacket const* TreasurePickerResponse::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(TreasurePickerID);
    _worldPacket << Treasure;

    return &_worldPacket;
}
}
