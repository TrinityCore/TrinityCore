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

#ifndef AuctionHousePackets_h__
#define AuctionHousePackets_h__

#include "Packet.h"
#include "AddonPackets.h"
#include "DBCEnums.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"

struct AuctionsBucketKey;
struct AuctionPosting;
enum class AuctionHouseBrowseMode : uint8;
enum class AuctionHouseFilterMask : uint32;
enum class AuctionHouseListType : uint8;
enum class AuctionHouseSortOrder : uint8;

namespace WorldPackets
{
    namespace AuctionHouse
    {
        struct AuctionBucketKey
        {
            AuctionBucketKey() : ItemID(0), ItemLevel(0) { }
            AuctionBucketKey(AuctionsBucketKey const& key) { *this = key; }

            AuctionBucketKey& operator=(AuctionBucketKey const& key) = default;
            AuctionBucketKey& operator=(AuctionsBucketKey const& key);

            uint32 ItemID = 0;
            uint16 ItemLevel = 0;
            Optional<uint16> BattlePetSpeciesID;
            Optional<uint16> SuffixItemNameDescriptionID;
        };

        struct AuctionListFilterSubClass
        {
            int32 ItemSubclass = 0;
            uint32 InvTypeMask = 0;
        };

        struct AuctionListFilterClass
        {
            int32 ItemClass = 0;
            Array<AuctionListFilterSubClass, 31> SubClassFilters;
        };

        struct AuctionSortDef
        {
            AuctionHouseSortOrder SortOrder = AuctionHouseSortOrder(0);
            bool ReverseSort = false;
        };

        struct AuctionItemForSale
        {
            ObjectGuid Guid;
            uint32 UseCount = 0;
        };

        struct AuctionFavoriteInfo
        {
            uint32 Order = 0;
            uint32 ItemID = 0;
            uint32 ItemLevel = 0;
            uint32 BattlePetSpeciesID = 0;
            uint32 SuffixItemNameDescriptionID = 0;
        };

        struct AuctionOwnerNotification
        {
            void Initialize(::AuctionPosting const* auction);

            int32 AuctionID = 0;
            uint64 BidAmount = 0;
            Item::ItemInstance Item;
        };

        struct BucketInfo
        {
            AuctionBucketKey Key;
            int32 TotalQuantity = 0;
            int32 RequiredLevel = 0;
            uint64 MinPrice = 0;
            std::vector<int32> ItemModifiedAppearanceIDs;
            Optional<uint8> MaxBattlePetQuality;
            Optional<uint8> MaxBattlePetLevel;
            Optional<uint8> BattlePetBreedID;
            Optional<uint32> Unk901_1;
            bool ContainsOwnerItem = false;
            bool ContainsOnlyCollectedAppearances = false;
        };

        struct AuctionItem
        {
            Optional<Item::ItemInstance> Item;
            int32 Count = 0;
            int32 Charges = 0;
            std::vector<Item::ItemEnchantData> Enchantments;
            int32 Flags = 0;
            int32 AuctionID = 0;
            ObjectGuid Owner;
            Optional<uint64> MinBid;
            Optional<uint64> MinIncrement;
            Optional<uint64> BuyoutPrice;
            Optional<uint64> UnitPrice;
            int32 DurationLeft = 0;
            uint8 DeleteReason = 0;
            bool CensorServerSideInfo = false;
            bool CensorBidInfo = false;
            ObjectGuid ItemGuid;
            ObjectGuid OwnerAccountID;
            uint32 EndTime = 0;
            Optional<ObjectGuid> Bidder;
            Optional<uint64> BidAmount;
            std::vector<Item::ItemGemData> Gems;
            Optional<WorldPackets::AuctionHouse::AuctionBucketKey> AuctionBucketKey;
        };

        struct AuctionBidderNotification
        {
            void Initialize(::AuctionPosting const* auction, ::Item const* item);

            int32 AuctionID = 0;
            ObjectGuid Bidder;
            Item::ItemInstance Item;
        };

        class AuctionBrowseQuery final : public ClientPacket
        {
        public:
            AuctionBrowseQuery(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_BROWSE_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 Offset = 0;
            uint8 MinLevel = 1;
            uint8 MaxLevel = MAX_LEVEL;
            AuctionHouseFilterMask Filters = AuctionHouseFilterMask(0);
            Array<uint8, BATTLE_PET_SPECIES_MAX_ID / 8 + 1> KnownPets;
            int8 MaxPetLevel = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            std::string Name;
            Array<AuctionListFilterClass, 7> ItemClassFilters;
            Array<AuctionSortDef, 2> Sorts;
        };

        class AuctionCancelCommoditiesPurchase final : public ClientPacket
        {
        public:
            AuctionCancelCommoditiesPurchase(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_CANCEL_COMMODITIES_PURCHASE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionConfirmCommoditiesPurchase final : public ClientPacket
        {
        public:
            AuctionConfirmCommoditiesPurchase(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_CONFIRM_COMMODITIES_PURCHASE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            int32 ItemID = 0;
            uint32 Quantity = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionHelloRequest final : public ClientPacket
        {
        public:
            AuctionHelloRequest(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_HELLO_REQUEST, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class AuctionListBiddedItems final : public ClientPacket
        {
        public:
            AuctionListBiddedItems(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_LIST_BIDDED_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 Offset = 0;
            Array<uint32, 100> AuctionIDs;
            Array<AuctionSortDef, 2> Sorts;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionListBucketsByBucketKeys final : public ClientPacket
        {
        public:
            AuctionListBucketsByBucketKeys(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_LIST_BUCKETS_BY_BUCKET_KEYS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionBucketKey, 100> BucketKeys;
            Array<AuctionSortDef, 2> Sorts;
        };

        class AuctionListItemsByBucketKey final : public ClientPacket
        {
        public:
            AuctionListItemsByBucketKey(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_LIST_ITEMS_BY_BUCKET_KEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 Offset = 0;
            int8 Unknown830 = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionSortDef, 2> Sorts;
            AuctionBucketKey BucketKey;
        };

        class AuctionListItemsByItemID final : public ClientPacket
        {
        public:
            AuctionListItemsByItemID(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_LIST_ITEMS_BY_ITEM_ID, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            int32 ItemID = 0;
            int32 SuffixItemNameDescriptionID = 0;
            uint32 Offset = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionSortDef, 2> Sorts;
        };

        class AuctionListOwnedItems final : public ClientPacket
        {
        public:
            AuctionListOwnedItems(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_LIST_OWNED_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 Offset = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionSortDef, 2> Sorts;
        };

        class AuctionPlaceBid final : public ClientPacket
        {
        public:
            AuctionPlaceBid(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_PLACE_BID, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint64 BidAmount = 0;
            int32 AuctionID = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionRemoveItem final : public ClientPacket
        {
        public:
            AuctionRemoveItem(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_REMOVE_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            int32 AuctionID = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionReplicateItems final : public ClientPacket
        {
        public:
            AuctionReplicateItems(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_REPLICATE_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint32 ChangeNumberGlobal = 0;
            uint32 ChangeNumberCursor = 0;
            uint32 ChangeNumberTombstone = 0;
            uint32 Count = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionSellCommodity final : public ClientPacket
        {
        public:
            AuctionSellCommodity(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_SELL_COMMODITY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            uint64 UnitPrice = 0;
            uint32 RunTime = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionItemForSale, 64> Items;
        };

        class AuctionSellItem final : public ClientPacket
        {
        public:
            AuctionSellItem(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_SELL_ITEM, std::move(packet)) { }

            void Read() override;

            uint64 BuyoutPrice = 0;
            ObjectGuid Auctioneer;
            uint64 MinBid = 0;
            uint32 RunTime = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
            Array<AuctionItemForSale, 1> Items;
        };

        class AuctionSetFavoriteItem final : public ClientPacket
        {
        public:
            AuctionSetFavoriteItem(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_SET_FAVORITE_ITEM, std::move(packet)) { }

            void Read() override;

            AuctionFavoriteInfo Item;
            bool IsNotFavorite = true;
        };

        class AuctionGetCommodityQuote final : public ClientPacket
        {
        public:
            AuctionGetCommodityQuote(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_GET_COMMODITY_QUOTE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Auctioneer;
            int32 ItemID = 0;
            uint32 Quantity = 0;
            Optional<Addon::AddOnInfo> TaintedBy;
        };

        class AuctionClosedNotification final : public ServerPacket
        {
        public:
            AuctionClosedNotification() : ServerPacket(SMSG_AUCTION_CLOSED_NOTIFICATION, 45) { }

            WorldPacket const* Write() override;

            AuctionOwnerNotification Info;
            float ProceedsMailDelay = 0.0f;
            bool Sold = true;
        };

        class AuctionCommandResult final : public ServerPacket
        {
        public:
            AuctionCommandResult() : ServerPacket(SMSG_AUCTION_COMMAND_RESULT, 4 + 4 + 4 + 8 + 4 + 8 + 8 + 8) { }

            WorldPacket const* Write() override;

            int32 AuctionID      = 0; ///< the id of the auction that triggered this notification
            int32 Command        = 0; ///< the type of action that triggered this notification. Possible values are @ref AuctionAction
            int32 ErrorCode      = 0; ///< the error code that was generated when trying to perform the action. Possible values are @ref AuctionError
            int32 BagResult      = 0; ///< the bid error. Possible values are @ref AuctionError
            ObjectGuid Guid;          ///< the GUID of the bidder for this auction.
            uint64 MinIncrement  = 0; ///< the sum of outbid is (1% of current bid) * 5, if the bid is too small, then this value is 1 copper.
            uint64 Money         = 0; ///< the amount of money that the player bid in copper
            uint32 DesiredDelay  = 0;
        };

        class AuctionGetCommodityQuoteResult final : public ServerPacket
        {
        public:
            AuctionGetCommodityQuoteResult() : ServerPacket(SMSG_AUCTION_GET_COMMODITY_QUOTE_RESULT, 1 + 8 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            Optional<uint64> TotalPrice;
            Optional<uint32> Quantity;
            Optional<Duration<Milliseconds>> QuoteDuration;
            int32 Unknown830 = 0;
            uint32 DesiredDelay = 0;
        };

        class AuctionHelloResponse final : public ServerPacket
        {
        public:
            AuctionHelloResponse() : ServerPacket(SMSG_AUCTION_HELLO_RESPONSE, 1 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            bool OpenForBusiness = true;
        };

        class AuctionListBiddedItemsResult final : public ServerPacket
        {
        public:
            AuctionListBiddedItemsResult() : ServerPacket(SMSG_AUCTION_LIST_BIDDED_ITEMS_RESULT, 149) { }

            WorldPacket const* Write() override;

            std::vector<AuctionItem> Items;
            uint32 DesiredDelay = 0;
            bool HasMoreResults = false;
        };

        class AuctionListBucketsResult final : public ServerPacket
        {
        public:
            AuctionListBucketsResult() : ServerPacket(SMSG_AUCTION_LIST_BUCKETS_RESULT) { }

            WorldPacket const* Write() override;

            std::vector<BucketInfo> Buckets;
            uint32 DesiredDelay = 0;
            int32 Unknown830_0 = 0;
            int32 Unknown830_1 = 0;
            AuctionHouseBrowseMode BrowseMode = AuctionHouseBrowseMode(0);
            bool HasMoreResults = false;
        };

        class AuctionFavoriteList final : public ServerPacket
        {
        public:
            AuctionFavoriteList() : ServerPacket(SMSG_AUCTION_FAVORITE_LIST, 4 + 4 + 20 * 100) { }

            WorldPacket const* Write() override;

            uint32 DesiredDelay = 0;
            std::vector<AuctionFavoriteInfo> Items;
        };

        class AuctionListItemsResult final : public ServerPacket
        {
        public:
            AuctionListItemsResult() : ServerPacket(SMSG_AUCTION_LIST_ITEMS_RESULT, 150) { }

            WorldPacket const* Write() override;

            std::vector<AuctionItem> Items;
            uint32 Unknown830 = 0;
            uint32 TotalCount = 0;
            uint32 DesiredDelay = 0;
            AuctionHouseListType ListType = AuctionHouseListType(0);
            bool HasMoreResults = false;
            AuctionBucketKey BucketKey;
        };

        class AuctionListOwnedItemsResult final : public ServerPacket
        {
        public:
            AuctionListOwnedItemsResult() : ServerPacket(SMSG_AUCTION_LIST_OWNED_ITEMS_RESULT, 149) { }

            WorldPacket const* Write() override;

            std::vector<AuctionItem> Items;
            std::vector<AuctionItem> SoldItems;
            uint32 DesiredDelay = 0;
            bool HasMoreResults = false;
        };

        class AuctionOutbidNotification final : public ServerPacket
        {
        public:
            AuctionOutbidNotification() : ServerPacket(SMSG_AUCTION_OUTBID_NOTIFICATION, 62) { }

            WorldPacket const* Write() override;

            AuctionBidderNotification Info;
            uint64 BidAmount = 0;
            uint64 MinIncrement = 0;
        };

        class AuctionOwnerBidNotification final : public ServerPacket
        {
        public:
            AuctionOwnerBidNotification() : ServerPacket(SMSG_AUCTION_OWNER_BID_NOTIFICATION, 62) { }

            WorldPacket const* Write() override;

            AuctionOwnerNotification Info;
            ObjectGuid Bidder;
            uint64 MinIncrement = 0;
        };

        class AuctionReplicateResponse final : public ServerPacket
        {
        public:
            AuctionReplicateResponse() : ServerPacket(SMSG_AUCTION_REPLICATE_RESPONSE, 165) { }

            WorldPacket const* Write() override;

            uint32 ChangeNumberCursor = 0;
            uint32 ChangeNumberGlobal = 0;
            uint32 DesiredDelay = 0;
            uint32 ChangeNumberTombstone = 0;
            uint32 Result = 0;
            std::vector<AuctionItem> Items;
        };

        class AuctionWonNotification final : public ServerPacket
        {
        public:
            AuctionWonNotification() : ServerPacket(SMSG_AUCTION_WON_NOTIFICATION, 46) { }

            WorldPacket const* Write() override;

            AuctionBidderNotification Info;
        };
    }
}

#endif // AuctionHousePackets_h__
