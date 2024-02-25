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

#include "AuctionHouseBot.h"
#include "AuctionHouseMgr.h"
#include "AuctionHousePackets.h"
#include "AccountMgr.h"
#include "Bag.h"
#include "BattlePetMgr.h"
#include "DB2Stores.h"
#include "CharacterCache.h"
#include "CollectionMgr.h"
#include "Common.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "WowTime.h"
#include <boost/dynamic_bitset.hpp>
#include <numeric>
#include <sstream>
#include <vector>

enum eAuctionHouse
{
    AH_MINIMUM_DEPOSIT = 100
};

AuctionsBucketKey::AuctionsBucketKey(WorldPackets::AuctionHouse::AuctionBucketKey const& key) :
    ItemId(key.ItemID), ItemLevel(key.ItemLevel), BattlePetSpeciesId(key.BattlePetSpeciesID.value_or(0)),
    SuffixItemNameDescriptionId(key.SuffixItemNameDescriptionID.value_or(0))
{
}

std::size_t AuctionsBucketKey::Hash(AuctionsBucketKey const& key)
{
    std::size_t hashVal = 0;
    Trinity::hash_combine(hashVal, std::hash<uint32>()(key.ItemId));
    Trinity::hash_combine(hashVal, std::hash<uint16>()(key.ItemLevel));
    Trinity::hash_combine(hashVal, std::hash<uint16>()(key.BattlePetSpeciesId));
    Trinity::hash_combine(hashVal, std::hash<uint16>()(key.SuffixItemNameDescriptionId));
    return hashVal;
}

AuctionsBucketKey AuctionsBucketKey::ForItem(Item const* item)
{
    ItemTemplate const* itemTemplate = item->GetTemplate();
    if (itemTemplate->GetMaxStackSize() == 1)
    {
        return
        {
            item->GetEntry(),
            uint16(Item::GetItemLevel(itemTemplate, *item->GetBonus(), 0, item->GetRequiredLevel(), 0, 0, 0, false, 0)),
            uint16(item->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID)),
            uint16(item->GetBonus()->Suffix)
        };
    }
    else
        return ForCommodity(itemTemplate);
}

AuctionsBucketKey AuctionsBucketKey::ForCommodity(ItemTemplate const* itemTemplate)
{
    return { itemTemplate->GetId(), uint16(itemTemplate->GetBaseItemLevel()), 0, 0 };
}

void AuctionsBucketData::BuildBucketInfo(WorldPackets::AuctionHouse::BucketInfo* bucketInfo, Player const* player) const
{
    bucketInfo->Key = Key;
    bucketInfo->MinPrice = MinPrice;
    bucketInfo->RequiredLevel = RequiredLevel;
    bucketInfo->TotalQuantity = 0;

    for (AuctionPosting const* auction : Auctions)
    {
        for (Item* item : auction->Items)
        {
            bucketInfo->TotalQuantity += item->GetCount();

            if (Key.BattlePetSpeciesId)
            {
                uint32 breedData = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA);
                uint32 breedId = breedData & 0xFFFFFF;
                uint8 quality = uint8((breedData >> 24) & 0xFF);
                uint8 level = uint8(item->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL));

                bucketInfo->MaxBattlePetQuality = bucketInfo->MaxBattlePetQuality ? std::max(*bucketInfo->MaxBattlePetQuality, quality) : quality;
                bucketInfo->MaxBattlePetLevel = bucketInfo->MaxBattlePetLevel ? std::max(*bucketInfo->MaxBattlePetLevel, level) : level;
                bucketInfo->BattlePetBreedID = breedId;
            }
        }

        bucketInfo->ContainsOwnerItem = bucketInfo->ContainsOwnerItem || auction->Owner == player->GetGUID();
    }

    bucketInfo->ContainsOnlyCollectedAppearances = true;
    for (std::pair<uint32, uint32> appearance : ItemModifiedAppearanceId)
    {
        if (appearance.first)
        {
            bucketInfo->ItemModifiedAppearanceIDs.push_back(appearance.first);
            if (!player->GetSession()->GetCollectionMgr()->HasItemAppearance(appearance.first).first)
                bucketInfo->ContainsOnlyCollectedAppearances = false;
        }
    }
}

bool AuctionPosting::IsCommodity() const
{
    return Items.size() > 1 || Items[0]->GetTemplate()->GetMaxStackSize() > 1;
}

uint32 AuctionPosting::GetTotalItemCount() const
{
    return std::accumulate(Items.begin(), Items.end(), 0u, [](uint32 totalCount, Item const* item)
    {
        return totalCount + item->GetCount();
    });
}

void AuctionPosting::BuildAuctionItem(WorldPackets::AuctionHouse::AuctionItem* auctionItem,
    bool alwaysSendItem, bool sendKey, bool censorServerInfo, bool censorBidInfo) const
{
    // SMSG_AUCTION_LIST_BIDDER_ITEMS_RESULT, SMSG_AUCTION_LIST_ITEMS_RESULT (if not commodity), SMSG_AUCTION_LIST_OWNER_ITEMS_RESULT, SMSG_AUCTION_REPLICATE_RESPONSE (if not commodity)
    //auctionItem->Item - here to unify comment

    // all (not optional<>)
    auctionItem->Count = int32(GetTotalItemCount());
    auctionItem->Flags = Items[0]->m_itemData->DynamicFlags;
    auctionItem->AuctionID = Id;
    auctionItem->Owner = Owner;

    // prices set when filled
    if (IsCommodity())
    {
        if (alwaysSendItem)
        {
            auctionItem->Item.emplace();
            auctionItem->Item->Initialize(Items[0]);
        }

        auctionItem->UnitPrice = BuyoutOrUnitPrice;
    }
    else
    {
        auctionItem->Item.emplace();
        auctionItem->Item->Initialize(Items[0]);
        auctionItem->Charges = std::max({ Items[0]->GetSpellCharges(0), Items[0]->GetSpellCharges(1), Items[0]->GetSpellCharges(2), Items[0]->GetSpellCharges(3), Items[0]->GetSpellCharges(4) });
        for (uint8 i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; i++)
        {
            uint32 enchantId = Items[0]->GetEnchantmentId(EnchantmentSlot(i));
            if (!enchantId)
                continue;

            auctionItem->Enchantments.emplace_back(enchantId, Items[0]->GetEnchantmentDuration(EnchantmentSlot(i)), Items[0]->GetEnchantmentCharges(EnchantmentSlot(i)), i);
        }

        for (uint8 i = 0; i < Items[0]->m_itemData->Gems.size(); ++i)
        {
            UF::SocketedGem const* gemData = &Items[0]->m_itemData->Gems[i];
            if (gemData->ItemID)
            {
                WorldPackets::Item::ItemGemData gem;
                gem.Slot = i;
                gem.Item.Initialize(gemData);
                auctionItem->Gems.push_back(gem);
            }
        }

        if (MinBid)
            auctionItem->MinBid = MinBid;

        if (uint64 minIncrement = CalculateMinIncrement())
            auctionItem->MinIncrement = minIncrement;

        if (BuyoutOrUnitPrice)
            auctionItem->BuyoutPrice = BuyoutOrUnitPrice;
    }

    // all (not optional<>)
    auctionItem->DurationLeft = uint32(std::max(std::chrono::duration_cast<Milliseconds>(EndTime - GameTime::GetSystemTime()).count(), Milliseconds::zero().count()));
    auctionItem->DeleteReason = 0;

    // SMSG_AUCTION_LIST_ITEMS_RESULT (only if owned)
    auctionItem->CensorServerSideInfo = censorServerInfo;
    auctionItem->ItemGuid = IsCommodity() ? ObjectGuid::Empty : Items[0]->GetGUID();
    auctionItem->OwnerAccountID = OwnerAccount;
    auctionItem->EndTime = uint32(std::chrono::system_clock::to_time_t(EndTime));

    // SMSG_AUCTION_LIST_BIDDER_ITEMS_RESULT, SMSG_AUCTION_LIST_ITEMS_RESULT (if has bid), SMSG_AUCTION_LIST_OWNER_ITEMS_RESULT, SMSG_AUCTION_REPLICATE_RESPONSE (if has bid)
    auctionItem->CensorBidInfo = censorBidInfo;
    if (!Bidder.IsEmpty())
    {
        auctionItem->Bidder = Bidder;
        auctionItem->BidAmount = BidAmount;
    }

    // SMSG_AUCTION_LIST_BIDDER_ITEMS_RESULT, SMSG_AUCTION_LIST_OWNER_ITEMS_RESULT, SMSG_AUCTION_REPLICATE_RESPONSE (if commodity)
    if (sendKey)
        auctionItem->AuctionBucketKey.emplace(AuctionsBucketKey::ForItem(Items[0]));

    // all
    if (!Items[0]->m_itemData->Creator->IsEmpty())
        auctionItem->Creator = *Items[0]->m_itemData->Creator;
}

uint64 AuctionPosting::CalculateMinIncrement(uint64 bidAmount)
{
    return CalculatePct(bidAmount / SILVER /*ignore copper*/, 5) * SILVER;
}

class AuctionsBucketData::Sorter
{
public:
    Sorter(LocaleConstant locale, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts)
        : _locale(locale), _sorts(sorts) { }

    bool operator()(AuctionsBucketData const* left, AuctionsBucketData const* right) const
    {
        for (WorldPackets::AuctionHouse::AuctionSortDef const& sort : _sorts)
        {
            int64 ordering = CompareColumns(sort.SortOrder, left, right);
            if (ordering != 0)
                return (ordering < 0) == !sort.ReverseSort;
        }

        return left->Key < right->Key;
    }

private:
    int64 CompareColumns(AuctionHouseSortOrder column, AuctionsBucketData const* left, AuctionsBucketData const* right) const
    {
        switch (column)
        {
            case AuctionHouseSortOrder::Price:
            case AuctionHouseSortOrder::Bid:
            case AuctionHouseSortOrder::Buyout:
                return int64(left->MinPrice) - int64(right->MinPrice);
            case AuctionHouseSortOrder::Name:
                return left->FullName[_locale].compare(right->FullName[_locale]);
            case AuctionHouseSortOrder::Level:
                return int32(left->SortLevel) - int32(right->SortLevel);
            default:
                break;
        }

        return 0;
    }

    LocaleConstant _locale;
    std::span<WorldPackets::AuctionHouse::AuctionSortDef const> _sorts;
};

class AuctionPosting::Sorter
{
public:
    Sorter(LocaleConstant locale, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts)
        : _locale(locale), _sorts(sorts) { }

    bool operator()(AuctionPosting const* left, AuctionPosting const* right) const
    {
        for (WorldPackets::AuctionHouse::AuctionSortDef const& sort : _sorts)
        {
            int64 ordering = CompareColumns(sort.SortOrder, left, right);
            if (ordering != 0)
                return (ordering < 0) == !sort.ReverseSort;
        }

        // Auctions are processed in LIFO order
        if (left->StartTime != right->StartTime)
            return left->StartTime > right->StartTime;

        return left->Id > right->Id;
    }

private:
    int64 CompareColumns(AuctionHouseSortOrder column, AuctionPosting const* left, AuctionPosting const* right) const
    {
        switch (column)
        {
            case AuctionHouseSortOrder::Price:
            {
                int64 leftPrice = left->BuyoutOrUnitPrice ? left->BuyoutOrUnitPrice : (left->BidAmount ? left->BidAmount : left->MinBid);
                int64 rightPrice = right->BuyoutOrUnitPrice ? right->BuyoutOrUnitPrice : (right->BidAmount ? right->BidAmount : right->MinBid);
                return leftPrice - rightPrice;
            }
            case AuctionHouseSortOrder::Name:
                return left->Bucket->FullName[_locale].compare(right->Bucket->FullName[_locale]);
            case AuctionHouseSortOrder::Level:
            {
                int32 leftLevel = !left->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID)
                    ? left->Bucket->SortLevel
                    : left->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
                int32 rightLevel = !right->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID)
                    ? right->Bucket->SortLevel
                    : right->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
                return leftLevel - rightLevel;
            }
            case AuctionHouseSortOrder::Bid:
                return int64(left->BidAmount) - int64(right->BidAmount);
            case AuctionHouseSortOrder::Buyout:
                return int64(left->BuyoutOrUnitPrice) - int64(right->BuyoutOrUnitPrice);
            default:
                break;
        }

        return 0;
    }

    LocaleConstant _locale;
    std::span<WorldPackets::AuctionHouse::AuctionSortDef const> _sorts;
};

template<typename T>
class AuctionsResultBuilder
{
public:
    using Sorter = typename T::Sorter;

    AuctionsResultBuilder(uint32 offset, LocaleConstant locale, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts, AuctionHouseResultLimits maxResults)
        : _offset(offset), _sorter(locale, sorts), _maxResults(AsUnderlyingType(maxResults)), _hasMoreResults(false)
    {
        _items.reserve(_maxResults + offset + 1);
    }

    void AddItem(T const* item)
    {
        auto where = std::lower_bound(_items.begin(), _items.end(), item, std::cref(_sorter));

        _items.insert(where, item);
        if (_items.size() > _maxResults + _offset)
        {
            _items.pop_back();
            _hasMoreResults = true;
        }
    }

    Trinity::IteratorPair<typename std::vector<T const*>::const_iterator> GetResultRange() const
    {
        return Trinity::Containers::MakeIteratorPair(_items.begin() + _offset, _items.end());
    }

    bool HasMoreResults() const
    {
        return _hasMoreResults;
    }

private:
    uint32 _offset;
    Sorter _sorter;
    std::size_t _maxResults;
    std::vector<T const*> _items;
    bool _hasMoreResults;
};

AuctionHouseMgr::AuctionHouseMgr() : mHordeAuctions(6), mAllianceAuctions(2), mNeutralAuctions(1), mGoblinAuctions(7), _replicateIdGenerator(0)
{
    _playerThrottleObjectsCleanupTime = GameTime::Now() + Hours(1);
}

AuctionHouseMgr::~AuctionHouseMgr()
{
    for (std::pair<ObjectGuid const, Item*>& itemPair : _itemsByGuid)
        delete itemPair.second;
}

AuctionHouseMgr* AuctionHouseMgr::instance()
{
    static AuctionHouseMgr instance;
    return &instance;
}

AuctionHouseObject* AuctionHouseMgr::GetAuctionsMap(uint32 factionTemplateId)
{
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        return &mNeutralAuctions;

    // teams have linked auction houses
    FactionTemplateEntry const* uEntry = sFactionTemplateStore.LookupEntry(factionTemplateId);
    if (!uEntry)
        return &mNeutralAuctions;
    else if (uEntry->FactionGroup & FACTION_MASK_ALLIANCE)
        return &mAllianceAuctions;
    else if (uEntry->FactionGroup & FACTION_MASK_HORDE)
        return &mHordeAuctions;
    else
        return &mNeutralAuctions;
}

AuctionHouseObject* AuctionHouseMgr::GetAuctionsById(uint32 auctionHouseId)
{
    switch (auctionHouseId)
    {
        case 1:
            return &mNeutralAuctions;
        case 2:
            return &mAllianceAuctions;
        case 6:
            return &mHordeAuctions;
        case 7:
            return &mGoblinAuctions;
        default:
            break;
    }
    return &mNeutralAuctions;
}

Item* AuctionHouseMgr::GetAItem(ObjectGuid itemGuid)
{
    return Trinity::Containers::MapGetValuePtr(_itemsByGuid, itemGuid);
}

uint64 AuctionHouseMgr::GetCommodityAuctionDeposit(ItemTemplate const* item, Minutes time, uint32 quantity)
{
    uint32 sellPrice = item->GetSellPrice();
    return uint64(std::ceil(std::floor(fmax(0.15 * quantity * sellPrice, 100.0)) / int64(SILVER)) * int64(SILVER)) * (time.count() / (MIN_AUCTION_TIME / MINUTE));
}

uint64 AuctionHouseMgr::GetItemAuctionDeposit(Player const* player, Item const* item, Minutes time)
{
    uint32 sellPrice = item->GetSellPrice(player);
    return uint64(std::ceil(std::floor(fmax(sellPrice * 0.15, 100.0)) / int64(SILVER)) * int64(SILVER)) * (time.count() / (MIN_AUCTION_TIME / MINUTE));
}

std::string AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType type, AuctionPosting const* auction)
{
    return BuildAuctionMailSubject(auction->Items[0]->GetEntry(), type, auction->Id, auction->GetTotalItemCount(),
        auction->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID), auction->Items[0]->GetContext(), auction->Items[0]->GetBonusListIDs());
}

std::string AuctionHouseMgr::BuildCommodityAuctionMailSubject(AuctionMailType type, uint32 itemId, uint32 itemCount)
{
    return BuildAuctionMailSubject(itemId, type, 0, itemCount, 0, ItemContext::NONE, {});
}

std::string AuctionHouseMgr::BuildAuctionMailSubject(uint32 itemId, AuctionMailType type, uint32 auctionId, uint32 itemCount, uint32 battlePetSpeciesId,
    ItemContext context, std::vector<int32> const& bonusListIds)
{
    std::ostringstream strm;
    strm
        << itemId << ':'
        << "0:" // OLD: itemRandomPropertiesId
        << AsUnderlyingType(type) << ':'
        << auctionId << ':'
        << itemCount << ':'
        << battlePetSpeciesId << ':'
        << "0:"
        << "0:"
        << "0:"
        << "0:"
        << uint32(context) << ':'
        << bonusListIds.size();

    for (int32 bonusListId : bonusListIds)
        strm << ':' << bonusListId;

    return strm.str();
}

std::string AuctionHouseMgr::BuildAuctionWonMailBody(ObjectGuid guid, uint64 bid, uint64 buyout)
{
    return Trinity::StringFormat("{}:{}:{}:0", guid.ToString(), bid, buyout);
}

std::string AuctionHouseMgr::BuildAuctionSoldMailBody(ObjectGuid guid, uint64 bid, uint64 buyout, uint32 deposit, uint64 consignment)
{
    return Trinity::StringFormat("{}:{}:{}:{}:{}:0", guid.ToString(), bid, buyout, deposit, consignment);
}

std::string AuctionHouseMgr::BuildAuctionInvoiceMailBody(ObjectGuid guid, uint64 bid, uint64 buyout, uint32 deposit, uint64 consignment, uint32 moneyDelay, uint32 eta)
{
    return Trinity::StringFormat("{}:{}:{}:{}:{}:{}:{}:0", guid.ToString(), bid, buyout, deposit, consignment, moneyDelay, eta);
}

void AuctionHouseMgr::LoadAuctions()
{
    uint32 oldMSTime = getMSTime();

    // need to clear in case we are reloading
    if (!_itemsByGuid.empty())
    {
        for (std::pair<ObjectGuid const, Item*>& itemPair : _itemsByGuid)
            delete itemPair.second;

        _itemsByGuid.clear();
    }

    // data needs to be at first place for Item::LoadFromDB
    uint32 count = 0;
    std::unordered_map<uint32, std::vector<Item*>> itemsByAuction;
    std::unordered_map<uint32, GuidUnorderedSet> biddersByAuction;

    if (PreparedQueryResult result = CharacterDatabase.Query(CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_ITEMS)))
    {
        do
        {
            Field* fields = result->Fetch();

            ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
            uint32 itemEntry = fields[1].GetUInt32();

            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
            if (!proto)
            {
                TC_LOG_ERROR("misc", "AuctionHouseMgr::LoadAuctionItems: Unknown item (GUID: {} item entry: #{}) in auction, skipped.", itemGuid, itemEntry);
                continue;
            }

            Item* item = NewItemOrBag(proto);
            if (!item->LoadFromDB(itemGuid, ObjectGuid::Create<HighGuid::Player>(fields[51].GetUInt64()), fields, itemEntry))
            {
                delete item;
                continue;
            }
            uint32 auctionId = fields[52].GetUInt32();
            itemsByAuction[auctionId].push_back(item);

            ++count;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} auction items in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();

    count = 0;

    if (PreparedQueryResult result = CharacterDatabase.Query(CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_BIDDERS)))
    {
        do
        {
            Field* fields = result->Fetch();
            biddersByAuction[fields[0].GetUInt32()].insert(ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64()));

        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} auction bidders in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();

    count = 0;

    if (PreparedQueryResult result = CharacterDatabase.Query(CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONS)))
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        do
        {
            Field* fields = result->Fetch();

            AuctionPosting auction;
            auction.Id = fields[0].GetUInt32();
            uint32 auctionHouseId = fields[1].GetUInt32();
            AuctionHouseObject* auctionHouse = GetAuctionsById(auctionHouseId);
            if (!auctionHouse)
            {
                TC_LOG_ERROR("misc", "Auction {} has wrong auctionHouseId {}", auction.Id, auctionHouseId);
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
                stmt->setUInt32(0, auction.Id);
                trans->Append(stmt);
                continue;
            }

            auto itemsItr = itemsByAuction.find(auction.Id);
            if (itemsItr == itemsByAuction.end())
            {
                TC_LOG_ERROR("misc", "Auction {} has no items", auction.Id);
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
                stmt->setUInt32(0, auction.Id);
                trans->Append(stmt);
                continue;
            }

            auction.Items = std::move(itemsItr->second);
            auction.Owner = ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64());
            auction.OwnerAccount = ObjectGuid::Create<HighGuid::WowAccount>(sCharacterCache->GetCharacterAccountIdByGuid(auction.Owner));
            if (uint64 bidder = fields[3].GetUInt64())
                auction.Bidder = ObjectGuid::Create<HighGuid::Player>(bidder);

            auction.MinBid = fields[4].GetUInt64();
            auction.BuyoutOrUnitPrice = fields[5].GetUInt64();
            auction.Deposit = fields[6].GetUInt64();
            auction.BidAmount = fields[7].GetUInt64();
            auction.StartTime = std::chrono::system_clock::from_time_t(fields[8].GetInt64());
            auction.EndTime = std::chrono::system_clock::from_time_t(fields[9].GetInt64());
            auction.ServerFlags = static_cast<AuctionPostingServerFlag>(fields[10].GetUInt8());

            auto biddersItr = biddersByAuction.find(auction.Id);
            if (biddersItr != biddersByAuction.end())
                auction.BidderHistory = std::move(biddersItr->second);

            auctionHouse->AddAuction(nullptr, std::move(auction));

            ++count;
        } while (result->NextRow());

        CharacterDatabase.CommitTransaction(trans);
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} auctions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AuctionHouseMgr::AddAItem(Item* item)
{
    ASSERT(item);
    ASSERT(_itemsByGuid.count(item->GetGUID()) == 0);
    _itemsByGuid[item->GetGUID()] = item;
}

bool AuctionHouseMgr::RemoveAItem(ObjectGuid itemGuid, bool deleteItem /*= false*/, CharacterDatabaseTransaction* trans /*= nullptr*/)
{
    auto i = _itemsByGuid.find(itemGuid);
    if (i == _itemsByGuid.end())
        return false;

    if (deleteItem)
    {
        ASSERT(trans);
        i->second->FSetState(ITEM_REMOVED);
        i->second->SaveToDB(*trans);
    }

    _itemsByGuid.erase(i);
    return true;
}

bool AuctionHouseMgr::PendingAuctionAdd(Player const* player, uint32 auctionHouseId, uint32 auctionId, uint64 deposit)
{
    auto itr = _pendingAuctionsByPlayer.find(player->GetGUID());
    if (itr != _pendingAuctionsByPlayer.end())
    {
        // Get deposit so far
        uint64 totalDeposit = 0;
        for (PendingAuctionInfo const& thisAuction : itr->second.Auctions)
            totalDeposit += thisAuction.Deposit;

        // Add this deposit
        totalDeposit += deposit;

        if (!player->HasEnoughMoney(totalDeposit))
            return false;
    }
    else
        itr = _pendingAuctionsByPlayer.emplace(std::piecewise_construct, std::forward_as_tuple(player->GetGUID()), std::forward_as_tuple()).first;

    itr->second.Auctions.push_back({ auctionId, auctionHouseId, deposit });
    return true;
}

std::size_t AuctionHouseMgr::PendingAuctionCount(Player const* player) const
{
    auto itr = _pendingAuctionsByPlayer.find(player->GetGUID());
    if (itr != _pendingAuctionsByPlayer.end())
        return itr->second.Auctions.size();

    return 0;
}

void AuctionHouseMgr::PendingAuctionProcess(Player* player)
{
    auto iterMap = _pendingAuctionsByPlayer.find(player->GetGUID());
    if (iterMap == _pendingAuctionsByPlayer.end())
        return;

    uint64 totaldeposit = 0;
    auto itrAH = iterMap->second.Auctions.begin();
    for (; itrAH != iterMap->second.Auctions.end(); ++itrAH)
    {
        if (!player->HasEnoughMoney(totaldeposit + itrAH->Deposit))
            break;

        totaldeposit += itrAH->Deposit;
    }

    // expire auctions we cannot afford
    if (itrAH != iterMap->second.Auctions.end())
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        do
        {
            PendingAuctionInfo const& pendingAuction = *itrAH;
            if (AuctionPosting* auction = GetAuctionsById(pendingAuction.AuctionHouseId)->GetAuction(pendingAuction.AuctionId))
                auction->EndTime = GameTime::GetSystemTime();

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AUCTION_EXPIRATION);
            stmt->setUInt32(0, uint32(GameTime::GetGameTime()));
            stmt->setUInt32(1, pendingAuction.AuctionId);
            trans->Append(stmt);
            ++itrAH;
        } while (itrAH != iterMap->second.Auctions.end());
        CharacterDatabase.CommitTransaction(trans);
    }

    _pendingAuctionsByPlayer.erase(player->GetGUID());
    player->ModifyMoney(-int64(totaldeposit));
}

void AuctionHouseMgr::UpdatePendingAuctions()
{
    for (auto itr = _pendingAuctionsByPlayer.begin(); itr != _pendingAuctionsByPlayer.end();)
    {
        ObjectGuid playerGUID = itr->first;
        if (Player* player = ObjectAccessor::FindConnectedPlayer(playerGUID))
        {
            // Check if there were auctions since last update process if not
            if (PendingAuctionCount(player) == itr->second.LastAuctionsSize)
            {
                ++itr;
                PendingAuctionProcess(player);
            }
            else
            {
                ++itr;
                _pendingAuctionsByPlayer[playerGUID].LastAuctionsSize = PendingAuctionCount(player);
            }
        }
        else
        {
            // Expire any auctions that we couldn't get a deposit for
            TC_LOG_WARN("auctionHouse", "Player {} was offline, unable to retrieve deposit!", playerGUID.ToString());
            ++itr;
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (PendingAuctionInfo const& pendingAuction : itr->second.Auctions)
            {
                if (AuctionPosting* auction = GetAuctionsById(pendingAuction.AuctionHouseId)->GetAuction(pendingAuction.AuctionId))
                    auction->EndTime = GameTime::GetSystemTime();

                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AUCTION_EXPIRATION);
                stmt->setUInt32(0, uint32(GameTime::GetGameTime()));
                stmt->setUInt32(1, pendingAuction.AuctionId);
                trans->Append(stmt);
            }
            CharacterDatabase.CommitTransaction(trans);
            _pendingAuctionsByPlayer.erase(playerGUID);
        }
    }
}

void AuctionHouseMgr::Update()
{
    mHordeAuctions.Update();
    mAllianceAuctions.Update();
    mNeutralAuctions.Update();
    mGoblinAuctions.Update();

    TimePoint now = GameTime::Now();
    if (now >= _playerThrottleObjectsCleanupTime)
    {
        for (auto itr = _playerThrottleObjects.begin(); itr != _playerThrottleObjects.end();)
        {
            if (itr->second.PeriodEnd < now)
                itr = _playerThrottleObjects.erase(itr);
            else
                ++itr;
        }

        _playerThrottleObjectsCleanupTime = now + 1h;
    }
}

uint32 AuctionHouseMgr::GenerateReplicationId()
{
    return ++_replicateIdGenerator;
}

AuctionThrottleResult AuctionHouseMgr::CheckThrottle(Player const* player, bool addonTainted, AuctionCommand command /*= AuctionCommand::SellItem*/)
{
    TimePoint now = GameTime::Now();
    auto itr = _playerThrottleObjects.emplace(std::piecewise_construct, std::forward_as_tuple(player->GetGUID()), std::forward_as_tuple());
    if (itr.second || now > itr.first->second.PeriodEnd)
    {
        itr.first->second.PeriodEnd = now + Minutes(1);
        itr.first->second.QueriesRemaining = 100;
    }

    if (!itr.first->second.QueriesRemaining)
    {
        player->GetSession()->SendAuctionCommandResult(0, command, AuctionResult::AuctionHouseBusy, std::chrono::duration_cast<Milliseconds>(itr.first->second.PeriodEnd - now));
        return { {}, true };
    }

    if (!--itr.first->second.QueriesRemaining)
        return { std::chrono::duration_cast<Milliseconds>(itr.first->second.PeriodEnd - now), false };
    else
        return { Milliseconds(sWorld->getIntConfig(addonTainted ? CONFIG_AUCTION_TAINTED_SEARCH_DELAY : CONFIG_AUCTION_SEARCH_DELAY)), false };
}

AuctionHouseEntry const* AuctionHouseMgr::GetAuctionHouseEntry(uint32 factionTemplateId, uint32* houseId)
{
    uint32 houseid = 1; // Auction House

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        // FIXME: found way for proper auctionhouse selection by another way
        // AuctionHouse.dbc have faction field with _player_ factions associated with auction house races.
        // but no easy way convert creature faction to player race faction for specific city
        switch (factionTemplateId)
        {
            case  120: houseid = 7; break; // booty bay, Blackwater Auction House
            case  474: houseid = 7; break; // gadgetzan, Blackwater Auction House
            case  855: houseid = 7; break; // everlook, Blackwater Auction House
            default:                       // default
            {
                FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(factionTemplateId);
                if (!u_entry)
                    houseid = 1; // Auction House
                else if (u_entry->FactionGroup & FACTION_MASK_ALLIANCE)
                    houseid = 2; // Alliance Auction House
                else if (u_entry->FactionGroup & FACTION_MASK_HORDE)
                    houseid = 6; // Horde Auction House
                else
                    houseid = 1; // Auction House
                break;
            }
        }
    }

    if (houseId)
        *houseId = houseid;

    return sAuctionHouseStore.LookupEntry(houseid);
}

AuctionHouseObject::AuctionHouseObject(uint32 auctionHouseId) : _auctionHouse(sAuctionHouseStore.AssertEntry(auctionHouseId))
{
}

AuctionHouseObject::~AuctionHouseObject() = default;

uint32 AuctionHouseObject::GetAuctionHouseId() const
{
    return _auctionHouse->ID;
}

AuctionPosting* AuctionHouseObject::GetAuction(uint32 auctionId)
{
    return Trinity::Containers::MapGetValuePtr(_itemsByAuctionId, auctionId);
}

void AuctionHouseObject::AddAuction(CharacterDatabaseTransaction trans, AuctionPosting auction)
{
    AuctionsBucketKey key = AuctionsBucketKey::ForItem(auction.Items[0]);
    AuctionsBucketData* bucket;
    auto bucketItr = _buckets.find(key);
    if (bucketItr == _buckets.end())
    {
        // we don't have any item for this key yet, create new bucket
        bucketItr = _buckets.emplace(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple()).first;
        bucket = &bucketItr->second;
        bucket->Key = key;

        ItemTemplate const* itemTemplate = auction.Items[0]->GetTemplate();
        bucket->ItemClass = itemTemplate->GetClass();
        bucket->ItemSubClass = itemTemplate->GetSubClass();
        bucket->InventoryType = itemTemplate->GetInventoryType();
        bucket->RequiredLevel = auction.Items[0]->GetRequiredLevel();
        switch (itemTemplate->GetClass())
        {
            case ITEM_CLASS_WEAPON:
            case ITEM_CLASS_ARMOR:
                bucket->SortLevel = key.ItemLevel;
                break;
            case ITEM_CLASS_CONTAINER:
                bucket->SortLevel = itemTemplate->GetContainerSlots();
                break;
            case ITEM_CLASS_GEM:
            case ITEM_CLASS_ITEM_ENHANCEMENT:
                bucket->SortLevel = itemTemplate->GetBaseItemLevel();
                break;
            case ITEM_CLASS_CONSUMABLE:
                bucket->SortLevel = std::max<uint8>(1, bucket->RequiredLevel);
                break;
            case ITEM_CLASS_MISCELLANEOUS:
            case ITEM_CLASS_BATTLE_PETS:
                bucket->SortLevel = 1;
                break;
            case ITEM_CLASS_RECIPE:
                bucket->SortLevel = itemTemplate->GetSubClass() != ITEM_SUBCLASS_BOOK ? itemTemplate->GetRequiredSkillRank() : itemTemplate->GetBaseRequiredLevel();
                break;
            default:
                break;
        }

        for (LocaleConstant locale = LOCALE_enUS; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
        {
            if (locale == LOCALE_none)
                continue;

            std::wstring utf16name;
            if (!Utf8toWStr(auction.Items[0]->GetNameForLocaleIdx(locale), utf16name))
                continue;

            bucket->FullName[locale] = wstrCaseAccentInsensitiveParse(utf16name, locale);
        }
    }
    else
        bucket = &bucketItr->second;

    // update cache fields
    uint64 priceToDisplay = auction.BuyoutOrUnitPrice ? auction.BuyoutOrUnitPrice : auction.BidAmount;
    if (!bucket->MinPrice || priceToDisplay < bucket->MinPrice)
        bucket->MinPrice = priceToDisplay;

    if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = auction.Items[0]->GetItemModifiedAppearance())
    {
        auto itr = std::find_if(bucket->ItemModifiedAppearanceId.begin(), bucket->ItemModifiedAppearanceId.end(),
            [itemModifiedAppearance](std::pair<uint32, uint32> const& appearance) { return appearance.first == itemModifiedAppearance->ID; });

        if (itr == bucket->ItemModifiedAppearanceId.end())
            itr = std::find_if(bucket->ItemModifiedAppearanceId.begin(), bucket->ItemModifiedAppearanceId.end(),
                [](std::pair<uint32, uint32> const& appearance) { return appearance.first == 0; });

        if (itr != bucket->ItemModifiedAppearanceId.end())
        {
            itr->first = itemModifiedAppearance->ID;
            ++itr->second;
        }
    }

    uint32 quality;

    if (!auction.Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID))
    {
        quality = auction.Items[0]->GetQuality();
    }
    else
    {
        quality = (auction.Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) >> 24) & 0xFF;
        for (Item* item : auction.Items)
        {
            uint8 battlePetLevel = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
            if (!bucket->MinBattlePetLevel)
                bucket->MinBattlePetLevel = battlePetLevel;
            else if (bucket->MinBattlePetLevel > battlePetLevel)
                bucket->MinBattlePetLevel = battlePetLevel;

            bucket->MaxBattlePetLevel = std::max<uint8>(bucket->MaxBattlePetLevel, battlePetLevel);
            bucket->SortLevel = bucket->MaxBattlePetLevel;
        }
    }

    bucket->QualityMask |= static_cast<AuctionHouseFilterMask>(1 << (quality + 4));
    ++bucket->QualityCounts[quality];

    if (trans)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION);
        stmt->setUInt32(0, auction.Id);
        stmt->setUInt32(1, _auctionHouse->ID);
        stmt->setUInt64(2, auction.Owner.GetCounter());
        stmt->setUInt64(3, ObjectGuid::Empty.GetCounter());
        stmt->setUInt64(4, auction.MinBid);
        stmt->setUInt64(5, auction.BuyoutOrUnitPrice);
        stmt->setUInt64(6, auction.Deposit);
        stmt->setUInt64(7, auction.BidAmount);
        stmt->setInt64(8, std::chrono::system_clock::to_time_t(auction.StartTime));
        stmt->setInt64(9, std::chrono::system_clock::to_time_t(auction.EndTime));
        stmt->setUInt8(10, auction.ServerFlags.AsUnderlyingType());
        trans->Append(stmt);

        for (Item* item : auction.Items)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION_ITEMS);
            stmt->setUInt32(0, auction.Id);
            stmt->setUInt64(1, item->GetGUID().GetCounter());
            trans->Append(stmt);
        }
    }

    for (Item* item : auction.Items)
        sAuctionMgr->AddAItem(item);

    auction.Bucket = bucket;
    _playerOwnedAuctions.emplace(auction.Owner, auction.Id);
    for (ObjectGuid bidder : auction.BidderHistory)
        _playerBidderAuctions.emplace(bidder, auction.Id);

    AuctionPosting* addedAuction = &(_itemsByAuctionId[auction.Id] = std::move(auction));

    WorldPackets::AuctionHouse::AuctionSortDef priceSort{ AuctionHouseSortOrder::Price, false };
    AuctionPosting::Sorter insertSorter(LOCALE_enUS, std::span(&priceSort, 1));
    bucket->Auctions.insert(std::lower_bound(bucket->Auctions.begin(), bucket->Auctions.end(), addedAuction, std::cref(insertSorter)), addedAuction);

    sScriptMgr->OnAuctionAdd(this, addedAuction);
}

void AuctionHouseObject::RemoveAuction(CharacterDatabaseTransaction trans, AuctionPosting* auction, std::map<uint32, AuctionPosting>::iterator* auctionItr /*= nullptr*/)
{
    AuctionsBucketData* bucket = auction->Bucket;

    bucket->Auctions.erase(std::remove(bucket->Auctions.begin(), bucket->Auctions.end(), auction), bucket->Auctions.end());
    if (!bucket->Auctions.empty())
    {
        // update cache fields
        uint64 priceToDisplay = auction->BuyoutOrUnitPrice ? auction->BuyoutOrUnitPrice : auction->BidAmount;
        if (bucket->MinPrice == priceToDisplay)
        {
            bucket->MinPrice = std::numeric_limits<uint64>::max();
            for (AuctionPosting const* remainingAuction : bucket->Auctions)
                bucket->MinPrice = std::min(bucket->MinPrice, remainingAuction->BuyoutOrUnitPrice ? remainingAuction->BuyoutOrUnitPrice : remainingAuction->BidAmount);
        }

        if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = auction->Items[0]->GetItemModifiedAppearance())
        {
            auto itr = std::find_if(bucket->ItemModifiedAppearanceId.begin(), bucket->ItemModifiedAppearanceId.end(),
                [itemModifiedAppearance](std::pair<uint32, uint32> const& appearance)
            {
                return appearance.first == itemModifiedAppearance->ID;
            });

            if (itr != bucket->ItemModifiedAppearanceId.end())
                if (!--itr->second)
                    itr->first = 0;
        }

        uint32 quality;

        if (!auction->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID))
        {
            quality = auction->Items[0]->GetQuality();
        }
        else
        {
            quality = (auction->Items[0]->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) >> 24) & 0xFF;
            bucket->MinBattlePetLevel = 0;
            bucket->MaxBattlePetLevel = 0;
            for (AuctionPosting const* remainingAuction : bucket->Auctions)
            {
                for (Item* item : remainingAuction->Items)
                {
                    uint8 battlePetLevel = item->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
                    if (!bucket->MinBattlePetLevel)
                        bucket->MinBattlePetLevel = battlePetLevel;
                    else if (bucket->MinBattlePetLevel > battlePetLevel)
                        bucket->MinBattlePetLevel = battlePetLevel;

                    bucket->MaxBattlePetLevel = std::max<uint8>(bucket->MaxBattlePetLevel, battlePetLevel);
                }
            }
        }

        if (!--bucket->QualityCounts[quality])
            bucket->QualityMask &= static_cast<AuctionHouseFilterMask>(~(1 << (quality + 4)));
    }
    else
        _buckets.erase(bucket->Key);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
    stmt->setUInt32(0, auction->Id);
    trans->Append(stmt);

    for (Item* item : auction->Items)
        sAuctionMgr->RemoveAItem(item->GetGUID());

    sScriptMgr->OnAuctionRemove(this, auction);

    Trinity::Containers::MultimapErasePair(_playerOwnedAuctions, auction->Owner, auction->Id);
    for (ObjectGuid bidder : auction->BidderHistory)
        Trinity::Containers::MultimapErasePair(_playerBidderAuctions, bidder, auction->Id);

    if (auctionItr)
        *auctionItr = _itemsByAuctionId.erase(*auctionItr);
    else
        _itemsByAuctionId.erase(auction->Id);
}

void AuctionHouseObject::Update()
{
    SystemTimePoint curTime = GameTime::GetSystemTime();
    TimePoint curTimeSteady = GameTime::Now();
    ///- Handle expired auctions

    // Clear expired throttled players
    for (auto itr = _replicateThrottleMap.begin(); itr != _replicateThrottleMap.end();)
    {
        if (itr->second.NextAllowedReplication <= curTimeSteady)
            itr = _replicateThrottleMap.erase(itr);
        else
            ++itr;
    }

    for (auto itr = _commodityQuotes.begin(); itr != _commodityQuotes.end();)
    {
        if (itr->second.ValidTo < curTimeSteady)
            itr = _commodityQuotes.erase(itr);
        else
            ++itr;
    }

    if (_itemsByAuctionId.empty())
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for (auto it = _itemsByAuctionId.begin(); it != _itemsByAuctionId.end();)
    {
        AuctionPosting* auction = &it->second;
        ///- filter auctions expired on next update
        if (auction->EndTime > curTime + 1min)
        {
            ++it;
            continue;
        }

        ///- Either cancel the auction if there was no bidder
        if (auction->Bidder.IsEmpty())
        {
            SendAuctionExpired(auction, trans);
            sScriptMgr->OnAuctionExpire(this, auction);
        }
        ///- Or perform the transaction
        else
        {
            //we should send an "item sold" message if the seller is online
            //we send the item to the winner
            //we send the money to the seller
            SendAuctionWon(auction, nullptr, trans);
            SendAuctionSold(auction, nullptr, trans);
            sScriptMgr->OnAuctionSuccessful(this, auction);
        }

        ///- In any case clear the auction
        RemoveAuction(trans, auction, &it);
    }

    // Run DB changes
    CharacterDatabase.CommitTransaction(trans);
}

void AuctionHouseObject::BuildListBuckets(WorldPackets::AuctionHouse::AuctionListBucketsResult& listBucketsResult, Player const* player,
    std::wstring const& name, uint8 minLevel, uint8 maxLevel, EnumFlag<AuctionHouseFilterMask> filters, Optional<AuctionSearchClassFilters> const& classFilters,
    std::span<uint8 const> knownPetBits, uint8 maxKnownPetLevel, uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    std::unordered_set<uint32> knownAppearanceIds;
    boost::dynamic_bitset<uint8> knownPetSpecies;
    // prepare uncollected filter for more efficient searches
    if (filters.HasFlag(AuctionHouseFilterMask::UncollectedOnly))
    {
        knownAppearanceIds = player->GetSession()->GetCollectionMgr()->GetAppearanceIds();
        knownPetSpecies.init_from_block_range(knownPetBits.begin(), knownPetBits.end());
        if (knownPetSpecies.size() < sBattlePetSpeciesStore.GetNumRows())
            knownPetSpecies.resize(sBattlePetSpeciesStore.GetNumRows());
    }

    AuctionsResultBuilder<AuctionsBucketData> builder(offset, player->GetSession()->GetSessionDbcLocale(), sorts, AuctionHouseResultLimits::Browse);

    for (std::pair<AuctionsBucketKey const, AuctionsBucketData> const& bucket : _buckets)
    {
        AuctionsBucketData const* bucketData = &bucket.second;
        if (!name.empty())
        {
            if (filters.HasFlag(AuctionHouseFilterMask::ExactMatch))
            {
                if (bucketData->FullName[player->GetSession()->GetSessionDbcLocale()] != name)
                    continue;
            }
            else
                if (bucketData->FullName[player->GetSession()->GetSessionDbcLocale()].find(name) == std::wstring::npos)
                    continue;
        }

        if (minLevel && bucketData->RequiredLevel < minLevel)
            continue;

        if (maxLevel && bucketData->RequiredLevel > maxLevel)
            continue;

        if (!filters.HasFlag(bucketData->QualityMask))
            continue;

        if (classFilters)
        {
            // if we dont want any class filters, Optional is not initialized
            // if we dont want this class included, SubclassMask is set to FILTER_SKIP_CLASS
            // if we want this class and did not specify and subclasses, its set to FILTER_SKIP_SUBCLASS
            // otherwise full restrictions apply
            if (classFilters->Classes[bucketData->ItemClass].SubclassMask == AuctionSearchClassFilters::FILTER_SKIP_CLASS)
                continue;

            if (classFilters->Classes[bucketData->ItemClass].SubclassMask != AuctionSearchClassFilters::FILTER_SKIP_SUBCLASS)
            {
                if (!(classFilters->Classes[bucketData->ItemClass].SubclassMask & (1 << bucketData->ItemSubClass)))
                    continue;

                if (!(classFilters->Classes[bucketData->ItemClass].InvTypes[bucketData->ItemSubClass] & (UI64LIT(1) << bucketData->InventoryType)))
                    continue;
            }
        }

        if (filters.HasFlag(AuctionHouseFilterMask::UncollectedOnly))
        {
            // appearances - by ItemAppearanceId, not ItemModifiedAppearanceId
            if (bucketData->InventoryType != INVTYPE_NON_EQUIP && bucketData->InventoryType != INVTYPE_BAG)
            {
                bool hasAll = true;
                for (std::pair<uint32, uint32> bucketAppearance : bucketData->ItemModifiedAppearanceId)
                {
                    if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(bucketAppearance.first))
                    {
                        if (knownAppearanceIds.find(itemModifiedAppearance->ItemAppearanceID) == knownAppearanceIds.end())
                        {
                            hasAll = false;
                            break;
                        }
                    }
                }

                if (hasAll)
                    continue;
            }
            // caged pets
            else if (bucket.first.BattlePetSpeciesId)
            {
                if (knownPetSpecies.test(bucket.first.BattlePetSpeciesId))
                    continue;
            }
            // toys
            else if (sDB2Manager.IsToyItem(bucket.first.ItemId))
            {
                if (player->GetSession()->GetCollectionMgr()->HasToy(bucket.first.ItemId))
                    continue;
            }
            // mounts
            // recipes
            // pet items
            else if (bucketData->ItemClass == ITEM_CLASS_CONSUMABLE || bucketData->ItemClass == ITEM_CLASS_RECIPE || bucketData->ItemClass == ITEM_CLASS_MISCELLANEOUS)
            {
                ItemTemplate const* itemTemplate = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(bucket.first.ItemId));
                if (itemTemplate->Effects.size() >= 2 && (itemTemplate->Effects[0]->SpellID == 483 || itemTemplate->Effects[0]->SpellID == 55884))
                {
                    if (player->HasSpell(itemTemplate->Effects[1]->SpellID))
                        continue;

                    if (BattlePetSpeciesEntry const* battlePetSpecies = BattlePets::BattlePetMgr::GetBattlePetSpeciesBySpell(itemTemplate->Effects[1]->SpellID))
                        if (knownPetSpecies.test(battlePetSpecies->ID))
                            continue;
                }
            }
        }

        if (filters.HasFlag(AuctionHouseFilterMask::UsableOnly))
        {
            if (bucketData->RequiredLevel && player->GetLevel() < bucketData->RequiredLevel)
                continue;

            if (player->CanUseItem(sObjectMgr->GetItemTemplate(bucket.first.ItemId), true) != EQUIP_ERR_OK)
                continue;

            // cannot learn caged pets whose level exceeds highest level of currently owned pet
            if (bucketData->MinBattlePetLevel && bucketData->MinBattlePetLevel > maxKnownPetLevel)
                continue;
        }

        // TODO: this one needs to access loot history to know highest item level for every inventory type
        //if (filters.HasFlag(AuctionHouseFilterMask::UpgradesOnly))
        //{
        //}

        builder.AddItem(bucketData);
    }

    for (AuctionsBucketData const* resultBucket : builder.GetResultRange())
    {
        listBucketsResult.Buckets.emplace_back();
        WorldPackets::AuctionHouse::BucketInfo& bucketInfo = listBucketsResult.Buckets.back();
        resultBucket->BuildBucketInfo(&bucketInfo, player);
    }

    listBucketsResult.HasMoreResults = builder.HasMoreResults();
}

void AuctionHouseObject::BuildListBuckets(WorldPackets::AuctionHouse::AuctionListBucketsResult& listBucketsResult, Player const* player,
    std::span<WorldPackets::AuctionHouse::AuctionBucketKey const> keys,
    std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    std::vector<AuctionsBucketData const*> buckets;
    buckets.reserve(keys.size());
    for (WorldPackets::AuctionHouse::AuctionBucketKey const& key : keys)
    {
        auto bucketItr = _buckets.find(AuctionsBucketKey(key));
        if (bucketItr != _buckets.end())
            buckets.push_back(&bucketItr->second);
    }

    AuctionsBucketData::Sorter sorter(player->GetSession()->GetSessionDbcLocale(), sorts);
    std::sort(buckets.begin(), buckets.end(), std::cref(sorter));

    for (AuctionsBucketData const* resultBucket : buckets)
    {
        listBucketsResult.Buckets.emplace_back();
        WorldPackets::AuctionHouse::BucketInfo& bucketInfo = listBucketsResult.Buckets.back();
        resultBucket->BuildBucketInfo(&bucketInfo, player);
    }

    listBucketsResult.HasMoreResults = false;
}

void AuctionHouseObject::BuildListBiddedItems(WorldPackets::AuctionHouse::AuctionListBiddedItemsResult& listBiddedItemsResult, Player const* player,
    uint32 /*offset*/, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    // always full list
    std::vector<AuctionPosting const*> auctions;
    for (auto const& auctionId : Trinity::Containers::MapEqualRange(_playerBidderAuctions, player->GetGUID()))
        if (AuctionPosting const* auction = Trinity::Containers::MapGetValuePtr(_itemsByAuctionId, auctionId.second))
            auctions.push_back(auction);

    AuctionPosting::Sorter sorter(player->GetSession()->GetSessionDbcLocale(), sorts);
    std::sort(auctions.begin(), auctions.end(), std::cref(sorter));

    for (AuctionPosting const* resultAuction : auctions)
    {
        listBiddedItemsResult.Items.emplace_back();
        WorldPackets::AuctionHouse::AuctionItem& auctionItem = listBiddedItemsResult.Items.back();
        resultAuction->BuildAuctionItem(&auctionItem, true, true, true, false);
    }

    listBiddedItemsResult.HasMoreResults = false;
}

void AuctionHouseObject::BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& listItemsResult, Player const* player, AuctionsBucketKey const& bucketKey,
    uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    listItemsResult.TotalCount = 0;
    if (AuctionsBucketData const* bucket = Trinity::Containers::MapGetValuePtr(_buckets, bucketKey))
    {
        AuctionsResultBuilder<AuctionPosting> builder(offset, player->GetSession()->GetSessionDbcLocale(), sorts, AuctionHouseResultLimits::Items);

        for (AuctionPosting const* auction : bucket->Auctions)
        {
            builder.AddItem(auction);
            for (Item* item : auction->Items)
                listItemsResult.TotalCount += item->GetCount();
        }

        for (AuctionPosting const* resultAuction : builder.GetResultRange())
        {
            listItemsResult.Items.emplace_back();
            WorldPackets::AuctionHouse::AuctionItem& auctionItem = listItemsResult.Items.back();
            resultAuction->BuildAuctionItem(&auctionItem, false, false, resultAuction->OwnerAccount != player->GetSession()->GetAccountGUID(),
                resultAuction->Bidder.IsEmpty());
        }

        listItemsResult.HasMoreResults = builder.HasMoreResults();
    }
}

void AuctionHouseObject::BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& listItemsResult, Player const* player, uint32 itemId,
    uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    AuctionsResultBuilder<AuctionPosting> builder(offset, player->GetSession()->GetSessionDbcLocale(), sorts, AuctionHouseResultLimits::Items);
    auto itr = _buckets.lower_bound(AuctionsBucketKey(itemId, 0, 0, 0));
    auto end = _buckets.lower_bound(AuctionsBucketKey(itemId + 1, 0, 0, 0));
    listItemsResult.TotalCount = 0;
    while (itr != end)
    {
        for (AuctionPosting const* auction : itr->second.Auctions)
        {
            builder.AddItem(auction);
            for (Item* item : auction->Items)
                listItemsResult.TotalCount += item->GetCount();
        }

        ++itr;
    }

    for (AuctionPosting const* resultAuction : builder.GetResultRange())
    {
        listItemsResult.Items.emplace_back();
        WorldPackets::AuctionHouse::AuctionItem& auctionItem = listItemsResult.Items.back();
        resultAuction->BuildAuctionItem(&auctionItem, false, true, resultAuction->OwnerAccount != player->GetSession()->GetAccountGUID(),
            resultAuction->Bidder.IsEmpty());
    }

    listItemsResult.HasMoreResults = builder.HasMoreResults();
}

void AuctionHouseObject::BuildListOwnedItems(WorldPackets::AuctionHouse::AuctionListOwnedItemsResult& listOwnedItemsResult, Player const* player,
    uint32 /*offset*/, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const
{
    // always full list
    std::vector<AuctionPosting const*> auctions;
    for (auto const& auctionId : Trinity::Containers::MapEqualRange(_playerOwnedAuctions, player->GetGUID()))
        if (AuctionPosting const* auction = Trinity::Containers::MapGetValuePtr(_itemsByAuctionId, auctionId.second))
            auctions.push_back(auction);

    AuctionPosting::Sorter sorter(player->GetSession()->GetSessionDbcLocale(), sorts);
    std::sort(auctions.begin(), auctions.end(), std::cref(sorter));

    for (AuctionPosting const* resultAuction : auctions)
    {
        listOwnedItemsResult.Items.emplace_back();
        WorldPackets::AuctionHouse::AuctionItem& auctionItem = listOwnedItemsResult.Items.back();
        resultAuction->BuildAuctionItem(&auctionItem, true, true, false, false);
    }

    listOwnedItemsResult.HasMoreResults = false;
}

void AuctionHouseObject::BuildReplicate(WorldPackets::AuctionHouse::AuctionReplicateResponse& replicateResponse, Player* player,
    uint32 global, uint32 cursor, uint32 tombstone, uint32 count)
{
    TimePoint curTime = GameTime::Now();

    auto throttleItr = _replicateThrottleMap.find(player->GetGUID());
    if (throttleItr != _replicateThrottleMap.end())
    {
        if (throttleItr->second.Global != global || throttleItr->second.Cursor != cursor || throttleItr->second.Tombstone != tombstone)
            return;

        if (!throttleItr->second.IsReplicationInProgress() && throttleItr->second.NextAllowedReplication > curTime)
            return;
    }
    else
    {
        throttleItr = _replicateThrottleMap.emplace(player->GetGUID(), PlayerReplicateThrottleData{}).first;
        throttleItr->second.NextAllowedReplication = curTime + Seconds(sWorld->getIntConfig(CONFIG_AUCTION_REPLICATE_DELAY));
        throttleItr->second.Global = sAuctionMgr->GenerateReplicationId();
    }

    if (_itemsByAuctionId.empty() || !count)
        return;

    auto itr = _itemsByAuctionId.upper_bound(cursor);
    for (; itr != _itemsByAuctionId.end(); ++itr)
    {
        AuctionPosting const& auction = itr->second;

        replicateResponse.Items.emplace_back();
        WorldPackets::AuctionHouse::AuctionItem& auctionItem = replicateResponse.Items.back();
        auction.BuildAuctionItem(&auctionItem, false, true, true, auction.Bidder.IsEmpty());
        if (!--count)
            break;
    }

    replicateResponse.ChangeNumberGlobal = throttleItr->second.Global;
    replicateResponse.ChangeNumberCursor = throttleItr->second.Cursor = !replicateResponse.Items.empty() ? replicateResponse.Items.back().AuctionID : 0;
    replicateResponse.ChangeNumberTombstone = throttleItr->second.Tombstone = !count ? _itemsByAuctionId.rbegin()->first : 0;
}

uint64 AuctionHouseObject::CalculateAuctionHouseCut(uint64 bidAmount) const
{
    return std::max(int64(CalculatePct(bidAmount, _auctionHouse->ConsignmentRate) * double(sWorld->getRate(RATE_AUCTION_CUT))), SI64LIT(0));
}

CommodityQuote const* AuctionHouseObject::CreateCommodityQuote(Player const* player, uint32 itemId, uint32 quantity)
{
    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
    if (!itemTemplate)
        return nullptr;

    auto bucketItr = _buckets.find(AuctionsBucketKey::ForCommodity(itemTemplate));
    if (bucketItr == _buckets.end())
        return nullptr;

    uint64 totalPrice = 0;
    uint32 remainingQuantity = quantity;
    for (AuctionPosting const* auction : bucketItr->second.Auctions)
    {
        for (Item* auctionItem : auction->Items)
        {
            if (auctionItem->GetCount() >= remainingQuantity)
            {
                totalPrice += auction->BuyoutOrUnitPrice * remainingQuantity;
                remainingQuantity = 0;
                break;
            }

            totalPrice += auction->BuyoutOrUnitPrice * auctionItem->GetCount();
            remainingQuantity -= auctionItem->GetCount();
        }
    }

    // not enough items on auction house
    if (remainingQuantity)
        return nullptr;

    if (!player->HasEnoughMoney(totalPrice))
        return nullptr;

    CommodityQuote* quote = &_commodityQuotes[player->GetGUID()];
    quote->TotalPrice = totalPrice;
    quote->Quantity = quantity;
    quote->ValidTo = GameTime::Now() + 30s;
    return quote;
}

void AuctionHouseObject::CancelCommodityQuote(ObjectGuid guid)
{
    _commodityQuotes.erase(guid);
}

bool AuctionHouseObject::BuyCommodity(CharacterDatabaseTransaction trans, Player* player, uint32 itemId, uint32 quantity, Milliseconds delayForNextAction)
{
    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
    if (!itemTemplate)
        return false;

    auto bucketItr = _buckets.find(AuctionsBucketKey::ForCommodity(itemTemplate));
    if (bucketItr == _buckets.end())
    {
        player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
        return false;
    }

    auto quote = _commodityQuotes.find(player->GetGUID());
    if (quote == _commodityQuotes.end())
    {
        player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
        return false;
    }

    std::shared_ptr<std::nullptr_t> removeQuote(nullptr, [this, quote](std::nullptr_t)
    {
        _commodityQuotes.erase(quote);
    });

    uint64 totalPrice = 0;
    uint32 remainingQuantity = quantity;
    std::vector<AuctionPosting*> auctions;
    for (auto auctionItr = bucketItr->second.Auctions.begin(); auctionItr != bucketItr->second.Auctions.end();)
    {
        AuctionPosting* auction = *auctionItr++;
        auctions.push_back(auction);
        for (Item* auctionItem : auction->Items)
        {
            if (auctionItem->GetCount() >= remainingQuantity)
            {
                totalPrice += auction->BuyoutOrUnitPrice * remainingQuantity;
                remainingQuantity = 0;
                auctionItr = bucketItr->second.Auctions.end();
                break;
            }

            totalPrice += auction->BuyoutOrUnitPrice * auctionItem->GetCount();
            remainingQuantity -= auctionItem->GetCount();
        }
    }

    // not enough items on auction house
    if (remainingQuantity)
    {
        player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
        return false;
    }

    // something was bought between creating quote and finalizing transaction
    // but we allow lower price if new items were posted at lower price
    if (totalPrice > quote->second.TotalPrice)
    {
        player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
        return false;
    }

    if (!player->HasEnoughMoney(totalPrice))
    {
        player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
        return false;
    }

    Optional<ObjectGuid> uniqueSeller;

    // prepare items
    struct MailedItemsBatch
    {
        std::array<Item*, MAX_MAIL_ITEMS> Items = { };
        uint64 TotalPrice = 0;
        uint32 Quantity = 0;

        std::size_t ItemsCount = 0;

        bool IsFull() const { return ItemsCount >= Items.size(); }
        void AddItem(Item* item, uint64 unitPrice)
        {
            Items[ItemsCount++] = item;
            Quantity += item->GetCount();
            TotalPrice += unitPrice * item->GetCount();
        }
    };

    std::vector<MailedItemsBatch> items;
    items.emplace_back();

    remainingQuantity = quantity;
    std::vector<std::size_t> removedItemsFromAuction;

    for (auto auctionItr = bucketItr->second.Auctions.begin(); auctionItr != bucketItr->second.Auctions.end();)
    {
        AuctionPosting* auction = *auctionItr++;
        if (!uniqueSeller)
            uniqueSeller = auction->Owner;
        else if (*uniqueSeller != auction->Owner)
            uniqueSeller = ObjectGuid::Empty;

        uint32 boughtFromAuction = 0;
        std::size_t removedItems = 0;
        for (Item* auctionItem : auction->Items)
        {
            MailedItemsBatch* itemsBatch = &items.back();
            if (itemsBatch->IsFull())
            {
                items.emplace_back();
                itemsBatch = &items.back();
            }

            if (auctionItem->GetCount() > remainingQuantity)
            {
                Item* clonedItem = auctionItem->CloneItem(remainingQuantity, player);
                if (!clonedItem)
                {
                    player->GetSession()->SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, delayForNextAction);
                    return false;
                }

                auctionItem->SetCount(auctionItem->GetCount() - remainingQuantity);
                auctionItem->FSetState(ITEM_CHANGED);
                auctionItem->SaveToDB(trans);
                itemsBatch->AddItem(clonedItem, auction->BuyoutOrUnitPrice);
                boughtFromAuction += remainingQuantity;
                remainingQuantity = 0;
                auctionItr = bucketItr->second.Auctions.end();
                break;
            }

            itemsBatch->AddItem(auctionItem, auction->BuyoutOrUnitPrice);
            boughtFromAuction += auctionItem->GetCount();
            remainingQuantity -= auctionItem->GetCount();
            ++removedItems;
        }

        removedItemsFromAuction.push_back(removedItems);

        if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        {
            uint32 bidderAccId = player->GetSession()->GetAccountId();
            std::string ownerName;
            if (!sCharacterCache->GetCharacterNameByGuid(auction->Owner, ownerName))
                ownerName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);

            sLog->OutCommand(bidderAccId, "GM {} (Account: {}) bought commodity in auction: {} (Entry: {} Count: {}) and pay money: {}. Original owner {} (Account: {})",
                player->GetName(), bidderAccId, items[0].Items[0]->GetNameForLocaleIdx(sWorld->GetDefaultDbcLocale()),
                items[0].Items[0]->GetEntry(), boughtFromAuction, auction->BuyoutOrUnitPrice * boughtFromAuction, ownerName,
                sCharacterCache->GetCharacterAccountIdByGuid(auction->Owner));
        }

        uint64 auctionHouseCut = CalculateAuctionHouseCut(auction->BuyoutOrUnitPrice * boughtFromAuction);
        uint64 depositPart = AuctionHouseMgr::GetCommodityAuctionDeposit(items[0].Items[0]->GetTemplate(), std::chrono::duration_cast<Minutes>(auction->EndTime - auction->StartTime),
            boughtFromAuction);
        uint64 profit = auction->BuyoutOrUnitPrice * boughtFromAuction + depositPart - auctionHouseCut;

        if (Player* owner = ObjectAccessor::FindConnectedPlayer(auction->Owner))
        {
            owner->UpdateCriteria(CriteriaType::MoneyEarnedFromAuctions, profit);
            owner->UpdateCriteria(CriteriaType::HighestAuctionSale, profit);
            owner->GetSession()->SendAuctionClosedNotification(auction, (float)sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY), true);
        }

        MailDraft(AuctionHouseMgr::BuildCommodityAuctionMailSubject(AuctionMailType::Sold, itemId, boughtFromAuction),
            AuctionHouseMgr::BuildAuctionSoldMailBody(player->GetGUID(), auction->BuyoutOrUnitPrice * boughtFromAuction, boughtFromAuction, depositPart, auctionHouseCut))
            .AddMoney(profit)
            .SendMailTo(trans, MailReceiver(ObjectAccessor::FindConnectedPlayer(auction->Owner), auction->Owner), this, MAIL_CHECK_MASK_COPIED, sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
    }

    player->ModifyMoney(-int64(totalPrice));
    player->SaveInventoryAndGoldToDB(trans);

    for (MailedItemsBatch const& batch : items)
    {
        MailDraft mail(AuctionHouseMgr::BuildCommodityAuctionMailSubject(AuctionMailType::Won, itemId, batch.Quantity),
            AuctionHouseMgr::BuildAuctionWonMailBody(*uniqueSeller, batch.TotalPrice, batch.Quantity));

        for (std::size_t i = 0; i < batch.ItemsCount; ++i)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION_ITEMS_BY_ITEM);
            stmt->setUInt64(0, batch.Items[i]->GetGUID().GetCounter());
            trans->Append(stmt);

            batch.Items[i]->SetOwnerGUID(player->GetGUID());
            batch.Items[i]->SaveToDB(trans);
            mail.AddItem(batch.Items[i]);
        }

        mail.SendMailTo(trans, player, this, MAIL_CHECK_MASK_COPIED);
    }

    WorldPackets::AuctionHouse::AuctionWonNotification packet;
    packet.Info.Initialize(auctions[0], items[0].Items[0]);
    player->SendDirectMessage(packet.Write());

    for (std::size_t i = 0; i < auctions.size(); ++i)
    {
        if (removedItemsFromAuction[i] == auctions[i]->Items.size())
            RemoveAuction(trans, auctions[i]); // bought all items
        else if (removedItemsFromAuction[i])
        {
            auto lastRemovedItem = auctions[i]->Items.begin() + removedItemsFromAuction[i];
            for (auto itr = auctions[i]->Items.begin(); itr != lastRemovedItem; ++itr)
                sAuctionMgr->RemoveAItem((*itr)->GetGUID());

            auctions[i]->Items.erase(auctions[i]->Items.begin(), lastRemovedItem);
        }
    }

    return true;
}

// this function notified old bidder that his bid is no longer highest
void AuctionHouseObject::SendAuctionOutbid(AuctionPosting const* auction, ObjectGuid newBidder, uint64 newBidAmount, CharacterDatabaseTransaction trans) const
{
    Player* oldBidder = ObjectAccessor::FindConnectedPlayer(auction->Bidder);

    // old bidder exist
    if ((oldBidder || sCharacterCache->HasCharacterCacheEntry(auction->Bidder)) && !sAuctionBotConfig->IsBotChar(auction->Bidder))
    {
        if (oldBidder)
        {
            WorldPackets::AuctionHouse::AuctionOutbidNotification packet;
            packet.BidAmount = newBidAmount;
            packet.MinIncrement = AuctionPosting::CalculateMinIncrement(newBidAmount);
            packet.Info.AuctionID = auction->Id;
            packet.Info.Bidder = newBidder;
            packet.Info.Item.Initialize(auction->Items[0]);
            oldBidder->SendDirectMessage(packet.Write());
        }

        MailDraft(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Outbid, auction), "")
            .AddMoney(auction->BidAmount)
            .SendMailTo(trans, MailReceiver(oldBidder, auction->Bidder), this, MAIL_CHECK_MASK_COPIED);
    }
}

void AuctionHouseObject::SendAuctionWon(AuctionPosting const* auction, Player* bidder, CharacterDatabaseTransaction trans) const
{
    uint32 bidderAccId = 0;
    if (!bidder)
        bidder = ObjectAccessor::FindConnectedPlayer(auction->Bidder); // try lookup bidder when called from ::Update

    // data for gm.log
    std::string bidderName;
    bool logGmTrade = auction->ServerFlags.HasFlag(AuctionPostingServerFlag::GmLogBuyer);

    if (bidder)
    {
        bidderAccId = bidder->GetSession()->GetAccountId();
        bidderName = bidder->GetName();
    }
    else
    {
        bidderAccId = sCharacterCache->GetCharacterAccountIdByGuid(auction->Bidder);

        if (logGmTrade && !sCharacterCache->GetCharacterNameByGuid(auction->Bidder, bidderName))
            bidderName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);
    }

    if (logGmTrade)
    {
        std::string ownerName;
        if (!sCharacterCache->GetCharacterNameByGuid(auction->Owner, ownerName))
            ownerName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);

        uint32 ownerAccId = sCharacterCache->GetCharacterAccountIdByGuid(auction->Owner);

        sLog->OutCommand(bidderAccId, "GM {} (Account: {}) won item in auction: {} (Entry: {} Count: {}) and pay money: {}. Original owner {} (Account: {})",
            bidderName, bidderAccId, auction->Items[0]->GetNameForLocaleIdx(sWorld->GetDefaultDbcLocale()),
            auction->Items[0]->GetEntry(), auction->GetTotalItemCount(), auction->BidAmount, ownerName, ownerAccId);
    }

    // receiver exist
    if ((bidder || bidderAccId) && !sAuctionBotConfig->IsBotChar(auction->Bidder))
    {
        MailDraft mail(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Won, auction),
            AuctionHouseMgr::BuildAuctionWonMailBody(auction->Owner, auction->BidAmount, auction->BuyoutOrUnitPrice));

        // set owner to bidder (to prevent delete item with sender char deleting)
        // owner in `data` will set at mail receive and item extracting
        for (Item* item : auction->Items)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
            stmt->setUInt64(0, auction->Bidder.GetCounter());
            stmt->setUInt64(1, item->GetGUID().GetCounter());
            trans->Append(stmt);

            mail.AddItem(item);
        }

        if (bidder)
        {
            WorldPackets::AuctionHouse::AuctionWonNotification packet;
            packet.Info.Initialize(auction, auction->Items[0]);
            bidder->SendDirectMessage(packet.Write());

            // FIXME: for offline player need also
            bidder->UpdateCriteria(CriteriaType::AuctionsWon, 1);
        }

        mail.SendMailTo(trans, MailReceiver(bidder, auction->Bidder), this, MAIL_CHECK_MASK_COPIED);
    }
    else
    {
        // bidder doesn't exist, delete the item
        for (Item* item : auction->Items)
            sAuctionMgr->RemoveAItem(item->GetGUID(), true, &trans);
    }
}

//call this method to send mail to auction owner, when auction is successful, it does not clear ram
void AuctionHouseObject::SendAuctionSold(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const
{
    if (!owner)
        owner = ObjectAccessor::FindConnectedPlayer(auction->Owner);

    // owner exist
    if ((owner || sCharacterCache->HasCharacterCacheEntry(auction->Owner)) && !sAuctionBotConfig->IsBotChar(auction->Owner))
    {
        uint64 auctionHouseCut = CalculateAuctionHouseCut(auction->BidAmount);
        uint64 profit = auction->BidAmount + auction->Deposit - auctionHouseCut;

        //FIXME: what do if owner offline
        if (owner)
        {
            owner->UpdateCriteria(CriteriaType::MoneyEarnedFromAuctions, profit);
            owner->UpdateCriteria(CriteriaType::HighestAuctionSale, auction->BidAmount);
            //send auction owner notification, bidder must be current!
            owner->GetSession()->SendAuctionClosedNotification(auction, (float)sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY), true);
        }

        MailDraft(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Sold, auction),
            AuctionHouseMgr::BuildAuctionSoldMailBody(auction->Bidder, auction->BidAmount, auction->BuyoutOrUnitPrice, auction->Deposit, auctionHouseCut))
            .AddMoney(profit)
            .SendMailTo(trans, MailReceiver(owner, auction->Owner), this, MAIL_CHECK_MASK_COPIED, sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
    }
}

void AuctionHouseObject::SendAuctionExpired(AuctionPosting const* auction, CharacterDatabaseTransaction trans) const
{
    Player* owner = ObjectAccessor::FindConnectedPlayer(auction->Owner);
    // owner exist
    if ((owner || sCharacterCache->HasCharacterCacheEntry(auction->Owner)) && !sAuctionBotConfig->IsBotChar(auction->Owner))
    {
        if (owner)
            owner->GetSession()->SendAuctionClosedNotification(auction, 0.0f, false);

        auto itemItr = auction->Items.begin();
        while (itemItr != auction->Items.end())
        {
            MailDraft mail(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Expired, auction), "");

            for (std::size_t i = 0; i < MAX_MAIL_ITEMS && itemItr != auction->Items.end(); ++i, ++itemItr)
                mail.AddItem(*itemItr);

            mail.SendMailTo(trans, MailReceiver(owner, auction->Owner), this, MAIL_CHECK_MASK_COPIED, 0);
        }
    }
    else
    {
        // owner doesn't exist, delete the item
        for (Item* item : auction->Items)
            sAuctionMgr->RemoveAItem(item->GetGUID(), true, &trans);
    }
}

void AuctionHouseObject::SendAuctionRemoved(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const
{
    auto itemItr = auction->Items.begin();
    while (itemItr != auction->Items.end())
    {
        MailDraft draft(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Cancelled, auction), "");

        for (std::size_t i = 0; i < MAX_MAIL_ITEMS && itemItr != auction->Items.end(); ++i, ++itemItr)
            draft.AddItem(*itemItr);

        draft.SendMailTo(trans, owner, this, MAIL_CHECK_MASK_COPIED);
    }
}

//this function sends mail, when auction is cancelled to old bidder
void AuctionHouseObject::SendAuctionCancelledToBidder(AuctionPosting const* auction, CharacterDatabaseTransaction trans) const
{
    Player* bidder = ObjectAccessor::FindConnectedPlayer(auction->Bidder);

    // bidder exist
    if ((bidder || sCharacterCache->HasCharacterCacheEntry(auction->Bidder)) && !sAuctionBotConfig->IsBotChar(auction->Bidder))
        MailDraft(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Removed, auction), "")
        .AddMoney(auction->BidAmount)
        .SendMailTo(trans, MailReceiver(bidder, auction->Bidder), this, MAIL_CHECK_MASK_COPIED);
}

void AuctionHouseObject::SendAuctionInvoice(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const
{
    if (!owner)
        owner = ObjectAccessor::FindConnectedPlayer(auction->Owner);

    // owner exist (online or offline)
    if ((owner || sCharacterCache->HasCharacterCacheEntry(auction->Owner)) && !sAuctionBotConfig->IsBotChar(auction->Owner))
    {
        WowTime eta = *GameTime::GetUtcWowTime();
        eta += Seconds(sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
        if (owner)
            eta += owner->GetSession()->GetTimezoneOffset();

        MailDraft(AuctionHouseMgr::BuildItemAuctionMailSubject(AuctionMailType::Invoice, auction),
            AuctionHouseMgr::BuildAuctionInvoiceMailBody(auction->Bidder, auction->BidAmount, auction->BuyoutOrUnitPrice, auction->Deposit,
                CalculateAuctionHouseCut(auction->BidAmount), sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY), eta.GetPackedTime()))
            .SendMailTo(trans, MailReceiver(owner, auction->Owner), this, MAIL_CHECK_MASK_COPIED);
    }
}
