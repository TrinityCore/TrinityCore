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

#ifndef _AUCTION_HOUSE_MGR_H
#define _AUCTION_HOUSE_MGR_H

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "Duration.h"
#include "EnumFlag.h"
#include "ItemTemplate.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <map>
#include <span>
#include <unordered_map>

class Item;
class Player;
class WorldPacket;

namespace WorldPackets
{
    namespace AuctionHouse
    {
        struct AuctionBucketKey;
        struct AuctionItem;
        struct AuctionSortDef;
        struct BucketInfo;
        class AuctionListBucketsResult;
        class AuctionListBiddedItemsResult;
        class AuctionListOwnedItemsResult;
        class AuctionListItemsResult;
        class AuctionReplicateResponse;
    }
}

uint32 constexpr MIN_AUCTION_TIME = 12 * HOUR;

enum class AuctionResult : int8
{
    Ok                      = 0,
    Inventory               = 1,
    DatabaseError           = 2,
    NotEnoughMoney          = 3,
    ItemNotFound            = 4,
    HigherBid               = 5,
    BidIncrement            = 7,
    BidOwn                  = 10,
    RestrictedAccountTrial  = 13,
    HasRestriction          = 17,
    AuctionHouseBusy        = 18,
    AuctionHouseUnavailable = 19,
    CommodityPurchaseFailed = 21,
    ItemHasQuote            = 23
};

enum class AuctionCommand : int8
{
    SellItem    = 0,
    Cancel      = 1,
    PlaceBid    = 2
};

enum class AuctionMailType : int32
{
    Outbid      = 0,
    Won         = 1,
    Sold        = 2,
    Expired     = 3,
    Removed     = 4, // for bidder
    Cancelled   = 5, // for seller
    Invoice     = 6
};

enum class AuctionHouseResultLimits : std::size_t
{
    Browse = 500,
    Items = 50
};

constexpr std::size_t MAX_FAVORITE_AUCTIONS = 100;

enum class AuctionHouseFilterMask : uint32
{
    None                        = 0x0,
    UncollectedOnly             = 0x1,
    UsableOnly                  = 0x2,
    UpgradesOnly                = 0x4,
    ExactMatch                  = 0x8,
    PoorQuality                 = 0x10,
    CommonQuality               = 0x20,
    UncommonQuality             = 0x40,
    RareQuality                 = 0x80,
    EpicQuality                 = 0x100,
    LegendaryQuality            = 0x200,
    ArtifactQuality             = 0x400,
    LegendaryCraftedItemOnly    = 0x800,
};

DEFINE_ENUM_FLAG(AuctionHouseFilterMask);

enum class AuctionHouseSortOrder : uint8
{
    Price           = 0,
    Name            = 1,
    Level           = 2,
    Bid             = 3,
    Buyout          = 4,
    TimeRemaining   = 5
};

enum class AuctionHouseBrowseMode : uint8
{
    Search          = 0,
    SpecificKeys    = 1
};

enum class AuctionHouseListType : uint8
{
    Commodities = 1,
    Items       = 2
};

struct AuctionSearchClassFilters
{
    enum FilterType : uint32
    {
        FILTER_SKIP_CLASS = 0,
        FILTER_SKIP_SUBCLASS = 0xFFFFFFFF,
        FILTER_SKIP_INVTYPE = 0xFFFFFFFF
    };

    struct SubclassFilter
    {
        uint32 SubclassMask = FILTER_SKIP_CLASS;
        std::array<uint64, MAX_ITEM_SUBCLASS_TOTAL> InvTypes = { };
    };

    std::array<SubclassFilter, MAX_ITEM_CLASS> Classes = { };
};

struct AuctionsBucketKey
{
    AuctionsBucketKey() = default;
    AuctionsBucketKey(uint32 itemId, uint16 itemLevel, uint16 battlePetSpeciesId, uint16 suffixItemNameDescriptionId)
        : ItemId(itemId), ItemLevel(itemLevel), BattlePetSpeciesId(battlePetSpeciesId), SuffixItemNameDescriptionId(suffixItemNameDescriptionId) { }
    AuctionsBucketKey(WorldPackets::AuctionHouse::AuctionBucketKey const& key);

    uint32 ItemId;
    uint16 ItemLevel;
    uint16 BattlePetSpeciesId;
    uint16 SuffixItemNameDescriptionId;

    bool operator==(AuctionsBucketKey const& right) const = default;

    friend std::strong_ordering operator<=>(AuctionsBucketKey const& left, AuctionsBucketKey const& right) = default;

    static std::size_t Hash(AuctionsBucketKey const& key);
    static AuctionsBucketKey ForItem(Item const* item);
    static AuctionsBucketKey ForCommodity(ItemTemplate const* itemTemplate);
};

template<>
struct std::hash<AuctionsBucketKey>
{
    size_t operator()(AuctionsBucketKey const& key) const noexcept
    {
        return AuctionsBucketKey::Hash(key);
    }
};

struct AuctionPosting;

struct AuctionsBucketData
{
    AuctionsBucketKey Key{};

    // filter helpers
    uint8 ItemClass = 0;
    uint8 ItemSubClass = 0;
    uint8 InventoryType = 0;
    AuctionHouseFilterMask QualityMask = AuctionHouseFilterMask::None;
    std::array<uint32, MAX_ITEM_QUALITY> QualityCounts = { };
    uint64 MinPrice = 0; // for sort
    std::array<std::pair<uint32, uint32>, 4> ItemModifiedAppearanceId = { }; // for uncollected search
    uint8 RequiredLevel = 0; // for usable search
    uint16 SortLevel = 0;
    uint8 MinBattlePetLevel = 0;
    uint8 MaxBattlePetLevel = 0;
    std::array<std::wstring, TOTAL_LOCALES> FullName = { };

    std::vector<AuctionPosting*> Auctions;

    void BuildBucketInfo(WorldPackets::AuctionHouse::BucketInfo* bucketInfo, Player const* player) const;

    class Sorter;
};

enum class AuctionPostingServerFlag : uint8
{
    None        = 0x0,
    GmLogBuyer  = 0x1  // write transaction to gm log file for buyer (optimization flag - avoids querying database for offline player permissions)
};

DEFINE_ENUM_FLAG(AuctionPostingServerFlag);

// This structure represents the result of a single C_AuctionHouse.PostItem/PostCommodity call
struct AuctionPosting
{
    uint32 Id = 0;
    AuctionsBucketData* Bucket = nullptr;

    std::vector<Item*> Items;
    ObjectGuid Owner;
    ObjectGuid OwnerAccount;
    ObjectGuid Bidder;
    uint64 MinBid = 0;
    uint64 BuyoutOrUnitPrice = 0;
    uint64 Deposit = 0;
    uint64 BidAmount = 0;
    SystemTimePoint StartTime = SystemTimePoint::min();
    SystemTimePoint EndTime = SystemTimePoint::min();
    EnumFlag<AuctionPostingServerFlag> ServerFlags = AuctionPostingServerFlag::None;

    GuidUnorderedSet BidderHistory;

    bool IsCommodity() const;
    uint32 GetTotalItemCount() const;
    void BuildAuctionItem(WorldPackets::AuctionHouse::AuctionItem* auctionItem, bool alwaysSendItem, bool sendKey, bool censorServerInfo, bool censorBidInfo) const;
    static uint64 CalculateMinIncrement(uint64 bidAmount);
    uint64 CalculateMinIncrement() const { return CalculateMinIncrement(BidAmount); }

    class Sorter;
};

struct CommodityQuote
{
    uint64 TotalPrice = 0;
    uint32 Quantity = 0;
    TimePoint ValidTo = TimePoint::min();
};

struct AuctionThrottleResult
{
    Milliseconds DelayUntilNext;
    bool Throttled;
};

//this class is used as auctionhouse instance
class TC_GAME_API AuctionHouseObject
{
public:
    explicit AuctionHouseObject(uint32 auctionHouseId);
    AuctionHouseObject(AuctionHouseObject const&) = delete;
    AuctionHouseObject(AuctionHouseObject&&) = delete;
    AuctionHouseObject& operator=(AuctionHouseObject const&) = delete;
    AuctionHouseObject& operator=(AuctionHouseObject&&) = delete;
    ~AuctionHouseObject();

    struct PlayerReplicateThrottleData
    {
        uint32 Global = 0;
        uint32 Cursor = 0;
        uint32 Tombstone = 0;
        TimePoint NextAllowedReplication = TimePoint::min();

        bool IsReplicationInProgress() const { return Cursor != Tombstone && Global != 0; }
    };

    uint32 GetAuctionHouseId() const;

    std::map<uint32, AuctionPosting>::iterator GetAuctionsBegin() { return _itemsByAuctionId.begin(); }
    std::map<uint32, AuctionPosting>::iterator GetAuctionsEnd() { return _itemsByAuctionId.end(); }

    AuctionPosting* GetAuction(uint32 auctionId);

    void AddAuction(CharacterDatabaseTransaction trans, AuctionPosting auction);

    void RemoveAuction(CharacterDatabaseTransaction trans, AuctionPosting* auction, std::map<uint32, AuctionPosting>::iterator* auctionItr = nullptr);

    void Update();

    void BuildListBuckets(WorldPackets::AuctionHouse::AuctionListBucketsResult& listBucketsResult, Player const* player,
        std::wstring const& name, uint8 minLevel, uint8 maxLevel, EnumFlag<AuctionHouseFilterMask> filters, Optional<AuctionSearchClassFilters> const& classFilters,
        std::span<uint8 const> knownPetBits, uint8 maxKnownPetLevel,
        uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildListBuckets(WorldPackets::AuctionHouse::AuctionListBucketsResult& listBucketsResult, Player const* player,
        std::span<WorldPackets::AuctionHouse::AuctionBucketKey const> keys,
        std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildListBiddedItems(WorldPackets::AuctionHouse::AuctionListBiddedItemsResult& listBiddedItemsResult, Player const* player,
        uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& listItemsResult, Player const* player, AuctionsBucketKey const& bucketKey,
        uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& listItemsResult, Player const* player, uint32 itemId,
        uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildListOwnedItems(WorldPackets::AuctionHouse::AuctionListOwnedItemsResult& listOwnedItemsResult, Player const* player,
        uint32 offset, std::span<WorldPackets::AuctionHouse::AuctionSortDef const> sorts) const;
    void BuildReplicate(WorldPackets::AuctionHouse::AuctionReplicateResponse& replicateResponse, Player* player,
        uint32 global, uint32 cursor, uint32 tombstone, uint32 count);

    uint64 CalculateAuctionHouseCut(uint64 bidAmount) const;

    CommodityQuote const* CreateCommodityQuote(Player const* player, uint32 itemId, uint32 quantity);
    void CancelCommodityQuote(ObjectGuid guid);
    bool BuyCommodity(CharacterDatabaseTransaction trans, Player* player, uint32 itemId, uint32 quantity, Milliseconds delayForNextAction);

    void SendAuctionOutbid(AuctionPosting const* auction, ObjectGuid newBidder, uint64 newBidAmount, CharacterDatabaseTransaction trans) const;
    void SendAuctionWon(AuctionPosting const* auction, Player* bidder, CharacterDatabaseTransaction trans) const;
    void SendAuctionSold(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const;
    void SendAuctionExpired(AuctionPosting const* auction, CharacterDatabaseTransaction trans) const;
    void SendAuctionRemoved(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const;
    void SendAuctionCancelledToBidder(AuctionPosting const* auction, CharacterDatabaseTransaction trans) const;
    void SendAuctionInvoice(AuctionPosting const* auction, Player* owner, CharacterDatabaseTransaction trans) const;

private:
    AuctionHouseEntry const* _auctionHouse;

    std::map<uint32, AuctionPosting> _itemsByAuctionId; // ordered for replicate
    std::unordered_map<uint32, AuctionPosting> _soldItemsById;
    std::map<AuctionsBucketKey, AuctionsBucketData> _buckets; // ordered for search by itemid only
    std::unordered_map<ObjectGuid, CommodityQuote> _commodityQuotes;

    std::unordered_multimap<ObjectGuid, uint32> _playerOwnedAuctions;
    std::unordered_multimap<ObjectGuid, uint32> _playerBidderAuctions;

    // Map of throttled players for GetAll, and throttle expiry time
    // Stored here, rather than player object to maintain persistence after logout
    std::unordered_map<ObjectGuid, PlayerReplicateThrottleData> _replicateThrottleMap;
};

class TC_GAME_API AuctionHouseMgr
{
    private:
        AuctionHouseMgr();
        ~AuctionHouseMgr();

    public:
        AuctionHouseMgr(AuctionHouseMgr const&) = delete;
        AuctionHouseMgr(AuctionHouseMgr&&) = delete;
        AuctionHouseMgr& operator=(AuctionHouseMgr const&) = delete;
        AuctionHouseMgr& operator=(AuctionHouseMgr&&) = delete;

        static AuctionHouseMgr* instance();

        AuctionHouseObject* GetAuctionsMap(uint32 factionTemplateId);
        AuctionHouseObject* GetAuctionsById(uint32 auctionHouseId);

        Item* GetAItem(ObjectGuid itemGuid);

        static std::string BuildItemAuctionMailSubject(AuctionMailType type, AuctionPosting const* auction);
        static std::string BuildCommodityAuctionMailSubject(AuctionMailType type, uint32 itemId, uint32 itemCount);
        static std::string BuildAuctionMailSubject(uint32 itemId, AuctionMailType type, uint32 auctionId, uint32 itemCount, uint32 battlePetSpeciesId,
            ItemContext context, std::vector<int32> const& bonusListIds);
        static std::string BuildAuctionWonMailBody(ObjectGuid guid, uint64 bid, uint64 buyout);
        static std::string BuildAuctionSoldMailBody(ObjectGuid guid, uint64 bid, uint64 buyout, uint32 deposit, uint64 consignment);
        static std::string BuildAuctionInvoiceMailBody(ObjectGuid guid, uint64 bid, uint64 buyout, uint32 deposit, uint64 consignment, uint32 moneyDelay, uint32 eta);

        static uint64 GetCommodityAuctionDeposit(ItemTemplate const* item, Minutes time, uint32 quantity);
        static uint64 GetItemAuctionDeposit(Player const* player, Item const* item, Minutes time);
        static AuctionHouseEntry const* GetAuctionHouseEntry(uint32 factionTemplateId, uint32* houseId);

    public:

        void LoadAuctions();

        void AddAItem(Item* item);
        bool RemoveAItem(ObjectGuid itemGuid, bool deleteItem = false, CharacterDatabaseTransaction* trans = nullptr);
        bool PendingAuctionAdd(Player const* player, uint32 auctionHouseId, uint32 auctionId, uint64 deposit);
        std::size_t PendingAuctionCount(Player const* player) const;
        void PendingAuctionProcess(Player* player);
        void UpdatePendingAuctions();
        void Update();

        uint32 GenerateReplicationId();

        AuctionThrottleResult CheckThrottle(Player const* player, bool addonTainted, AuctionCommand command = AuctionCommand::SellItem);

    private:

        AuctionHouseObject mHordeAuctions;
        AuctionHouseObject mAllianceAuctions;
        AuctionHouseObject mNeutralAuctions;
        AuctionHouseObject mGoblinAuctions;

        struct PendingAuctionInfo
        {
            uint32 AuctionId = 0;
            uint32 AuctionHouseId = 0;
            uint64 Deposit = 0;
        };

        struct PlayerPendingAuctions
        {
            std::vector<PendingAuctionInfo> Auctions;
            std::size_t LastAuctionsSize = 0;
        };

        struct PlayerThrottleObject
        {
            TimePoint PeriodEnd;
            uint8 QueriesRemaining = 100;
        };

        std::unordered_map<ObjectGuid, PlayerPendingAuctions> _pendingAuctionsByPlayer;

        std::unordered_map<ObjectGuid, Item*> _itemsByGuid;

        uint32 _replicateIdGenerator;

        std::unordered_map<ObjectGuid, PlayerThrottleObject> _playerThrottleObjects;
        TimePoint _playerThrottleObjectsCleanupTime;
};

#define sAuctionMgr AuctionHouseMgr::instance()

#endif
