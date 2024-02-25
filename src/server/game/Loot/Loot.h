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

#ifndef Loot_h__
#define Loot_h__

#include "ConditionMgr.h"
#include "DBCEnums.h"
#include "Define.h"
#include "Duration.h"
#include "ItemEnchantmentMgr.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "SharedDefines.h"
#include <memory>
#include <unordered_map>
#include <vector>

constexpr Minutes LOOT_ROLL_TIMEOUT = 1min;

class Group;
class Item;
class LootStore;
class Map;
class Player;
struct ItemDisenchantLootEntry;
struct Loot;
struct LootStoreItem;

namespace WorldPackets
{
    namespace Loot
    {
        struct LootItemData;
        class LootResponse;
    }
}

enum RollType
{
    ROLL_PASS         = 0,
    ROLL_NEED         = 1,
    ROLL_GREED        = 2,
    ROLL_DISENCHANT   = 3,
    ROLL_TRANSMOG     = 4,
    MAX_ROLL_TYPE     = 5
};

enum class RollVote
{
    Pass            = 0,
    Need            = 1,
    Greed           = 2,
    Disenchant      = 3,
    NotEmitedYet    = 4,
    NotValid        = 5
};

enum RollMask
{
    ROLL_FLAG_TYPE_PASS         = 0x01,
    ROLL_FLAG_TYPE_NEED         = 0x02,
    ROLL_FLAG_TYPE_GREED        = 0x04,
    ROLL_FLAG_TYPE_DISENCHANT   = 0x08,
    ROLL_FLAG_TYPE_TRANSMOG     = 0x10,

    ROLL_ALL_TYPE_NO_DISENCHANT = 0x07,
    ROLL_ALL_TYPE_MASK          = 0x0F
};

#define MAX_NR_LOOT_ITEMS 18

enum LootMethod : uint8
{
    FREE_FOR_ALL      = 0,
    ROUND_ROBIN       = 1,
    MASTER_LOOT       = 2,
    GROUP_LOOT        = 3,
    NEED_BEFORE_GREED = 4,
    PERSONAL_LOOT     = 5
};

enum LootType : uint8
{
    LOOT_NONE                   = 0,

    LOOT_CORPSE                 = 1,
    LOOT_PICKPOCKETING          = 2,
    LOOT_FISHING                = 3,
    LOOT_DISENCHANTING          = 4,
    LOOT_ITEM                   = 5,
    LOOT_SKINNING               = 6,
    LOOT_GATHERING_NODE         = 8,
    LOOT_CHEST                  = 9,
    LOOT_CORPSE_PERSONAL        = 14,

    LOOT_FISHINGHOLE            = 20,                       // unsupported by client, sending LOOT_FISHING instead
    LOOT_INSIGNIA               = 21,                       // unsupported by client, sending LOOT_CORPSE instead
    LOOT_FISHING_JUNK           = 22,                       // unsupported by client, sending LOOT_FISHING instead
    LOOT_PROSPECTING            = 23,
    LOOT_MILLING                = 24,
};

constexpr LootType GetLootTypeForClient(LootType lootType)
{
    switch (lootType)
    {
        case LOOT_PROSPECTING:
        case LOOT_MILLING:
            return LOOT_DISENCHANTING;
        case LOOT_INSIGNIA:
            return LOOT_SKINNING;
        case LOOT_FISHINGHOLE:
        case LOOT_FISHING_JUNK:
            return LOOT_FISHING;
        default:
            break;
    }
    return lootType;
}

enum LootError : uint8
{
    LOOT_ERROR_DIDNT_KILL               = 0,    // You don't have permission to loot that corpse.
    LOOT_ERROR_TOO_FAR                  = 4,    // You are too far away to loot that corpse.
    LOOT_ERROR_BAD_FACING               = 5,    // You must be facing the corpse to loot it.
    LOOT_ERROR_LOCKED                   = 6,    // Someone is already looting that corpse.
    LOOT_ERROR_NOTSTANDING              = 8,    // You need to be standing up to loot something!
    LOOT_ERROR_STUNNED                  = 9,    // You can't loot anything while stunned!
    LOOT_ERROR_PLAYER_NOT_FOUND         = 10,   // Player not found
    LOOT_ERROR_PLAY_TIME_EXCEEDED       = 11,   // Maximum play time exceeded
    LOOT_ERROR_MASTER_INV_FULL          = 12,   // That player's inventory is full
    LOOT_ERROR_MASTER_UNIQUE_ITEM       = 13,   // Player has too many of that item already
    LOOT_ERROR_MASTER_OTHER             = 14,   // Can't assign item to that player
    LOOT_ERROR_ALREADY_PICKPOCKETED     = 15,   // Your target has already had its pockets picked
    LOOT_ERROR_NOT_WHILE_SHAPESHIFTED   = 16,   // You can't do that while shapeshifted.
    LOOT_ERROR_NO_LOOT                  = 17    // There is no loot.
};

// type of Loot Item in Loot View
enum LootSlotType
{
    LOOT_SLOT_TYPE_ALLOW_LOOT   = 0,                        // player can loot the item.
    LOOT_SLOT_TYPE_ROLL_ONGOING = 1,                        // roll is ongoing. player cannot loot.
    LOOT_SLOT_TYPE_MASTER       = 3,                        // item can only be distributed by group loot master.
    LOOT_SLOT_TYPE_LOCKED       = 2,                        // item is shown in red. player cannot loot.
    LOOT_SLOT_TYPE_OWNER        = 4                         // ignore binding confirmation and etc, for single player looting
};

enum class LootRollIneligibilityReason : uint32
{
    None                    = 0,
    UnusableByClass         = 1, // Your class may not roll need on this item.
    MaxUniqueItemCount      = 2, // You already have the maximum amount of this item.
    CannotBeDisenchanted    = 3, // This item may not be disenchanted.
    EnchantingSkillTooLow   = 4, // You do not have an Enchanter of skill %d in your group.
    NeedDisabled            = 5, // Need rolls are disabled for this item.
    OwnBetterItem           = 6  // You already have a powerful version of this item.
};

struct TC_GAME_API LootItem
{
    uint32  itemid;
    uint32  LootListId;
    ItemRandomBonusListId randomBonusListId;
    std::vector<int32> BonusListIDs;
    ItemContext context;
    ConditionsReference conditions;                         // additional loot condition
    GuidSet allowedGUIDs;
    ObjectGuid rollWinnerGUID;                              // Stores the guid of person who won loot, if his bags are full only he can see the item in loot list!
    uint8   count             : 8;
    bool    is_looted         : 1;
    bool    is_blocked        : 1;
    bool    freeforall        : 1;                          // free for all
    bool    is_underthreshold : 1;
    bool    is_counted        : 1;
    bool    needs_quest       : 1;                          // quest drop
    bool    follow_loot_rules : 1;

    // Constructor, copies most fields from LootStoreItem, generates random count and random suffixes/properties
    // Should be called for non-reference LootStoreItem entries only (reference = 0)
    explicit LootItem(LootStoreItem const& li);

    // Empty constructor for creating an empty LootItem to be filled in with DB data
    LootItem() : itemid(0), LootListId(0), randomBonusListId(0), context(ItemContext::NONE), count(0), is_looted(false), is_blocked(false),
                 freeforall(false), is_underthreshold(false), is_counted(false), needs_quest(false), follow_loot_rules(false) { }

    LootItem(LootItem const&);
    LootItem(LootItem&&) noexcept;
    LootItem& operator=(LootItem const&);
    LootItem& operator=(LootItem&&) noexcept;
    ~LootItem();

    // Basic checks for player/item compatibility - if false no chance to see the item in the loot - used only for loot generation
    bool AllowedForPlayer(Player const* player, Loot const* loot) const;
    static bool AllowedForPlayer(Player const* player, Loot const* loot, uint32 itemid, bool needs_quest, bool follow_loot_rules, bool strictUsabilityCheck,
        ConditionsReference const& conditions);
    void AddAllowedLooter(Player const* player);
    GuidSet const& GetAllowedLooters() const { return allowedGUIDs; }
    bool HasAllowedLooter(ObjectGuid const& looter) const;
    Optional<LootSlotType> GetUiTypeForPlayer(Player const* player, Loot const& loot) const;
};

struct NotNormalLootItem
{
    uint8   LootListId;
    bool    is_looted;

    NotNormalLootItem()
        : LootListId(0), is_looted(false) { }

    NotNormalLootItem(uint8 _index, bool _islooted = false)
        : LootListId(_index), is_looted(_islooted) { }
};

typedef std::vector<NotNormalLootItem> NotNormalLootItemList;
typedef std::vector<LootItem> LootItemList;
typedef std::unordered_map<ObjectGuid, std::unique_ptr<NotNormalLootItemList>> NotNormalLootItemMap;

//=====================================================

struct PlayerRollVote
{
    PlayerRollVote() : Vote(RollVote::NotValid), RollNumber(0) { }
    RollVote Vote;
    uint8    RollNumber;
};

class LootRoll
{
public:
    using RollVoteMap = std::unordered_map<ObjectGuid, PlayerRollVote>;

    LootRoll() : m_map(nullptr), m_isStarted(false), m_lootItem(nullptr), m_loot(nullptr), m_voteMask(), m_endTime(TimePoint::min()) { }
    ~LootRoll();

    LootRoll(LootRoll const&) = delete;
    LootRoll(LootRoll&&) = delete;
    LootRoll& operator=(LootRoll const&) = delete;
    LootRoll& operator=(LootRoll&&) = delete;

    bool TryToStart(Map* map, Loot& loot, uint32 lootListId, uint16 enchantingSkill);
    bool PlayerVote(Player* player, RollVote vote);
    bool UpdateRoll();

    bool IsLootItem(ObjectGuid const& lootObject, uint32 lootListId) const;

private:
    void SendStartRoll();
    void SendAllPassed();
    void SendRoll(ObjectGuid const& targetGuid, int32 rollNumber, RollVote rollType, Optional<ObjectGuid> const& rollWinner);
    void SendLootRollWon(ObjectGuid const& targetGuid, int32 rollNumber, RollVote rollType);
    void FillPacket(WorldPackets::Loot::LootItemData& lootItem) const;
    void Finish(RollVoteMap::const_iterator winnerItr);
    bool AllPlayerVoted(RollVoteMap::const_iterator& winnerItr);
    ItemDisenchantLootEntry const* GetItemDisenchantLoot() const;
    Map*        m_map;
    RollVoteMap m_rollVoteMap;
    bool        m_isStarted;
    LootItem*   m_lootItem;
    Loot*       m_loot;
    RollMask    m_voteMask;
    TimePoint   m_endTime;
};

struct TC_GAME_API Loot
{
    NotNormalLootItemMap const& GetPlayerFFAItems() const { return PlayerFFAItems; }

    std::vector<LootItem> items;
    uint32 gold;
    uint8 unlootedCount;
    ObjectGuid roundRobinPlayer;                            // GUID of the player having the Round-Robin ownership for the loot. If 0, round robin owner has released.
    LootType loot_type;                                     // required for achievement system

    explicit Loot(Map* map, ObjectGuid owner, LootType type, Group const* group);
    ~Loot();

    Loot(Loot const&) = delete;
    Loot(Loot&&) = delete;
    Loot& operator=(Loot const&) = delete;
    Loot& operator=(Loot&&) = delete;

    ObjectGuid const& GetGUID() const { return _guid; }
    ObjectGuid const& GetOwnerGUID() const { return _owner; }
    ItemContext GetItemContext() const { return _itemContext; }
    void SetItemContext(ItemContext context) { _itemContext = context; }
    LootMethod GetLootMethod() const { return _lootMethod; }
    ObjectGuid const& GetLootMasterGUID() const { return _lootMaster; }
    uint32 GetDungeonEncounterId() const { return _dungeonEncounterId; }
    void SetDungeonEncounterId(uint32 dungeonEncounterId) { _dungeonEncounterId = dungeonEncounterId; }

    bool isLooted() const { return gold == 0 && unlootedCount == 0; }
    bool IsChanged() const { return _changed; }

    void NotifyLootList(Map const* map) const;
    void NotifyItemRemoved(uint8 lootListId, Map const* map);
    void NotifyMoneyRemoved(Map const* map);
    void OnLootOpened(Map* map, ObjectGuid looter);
    void AddLooter(ObjectGuid GUID) { PlayersLooting.insert(GUID); }
    void RemoveLooter(ObjectGuid GUID) { PlayersLooting.erase(GUID); }

    bool HasAllowedLooter(ObjectGuid const& looter) const;

    void generateMoneyLoot(uint32 minAmount, uint32 maxAmount);
    bool FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError = false, uint16 lootMode = LOOT_MODE_DEFAULT, ItemContext context = ItemContext::NONE);
    void FillNotNormalLootFor(Player const* player);        // count unlooted items

    // Inserts the item into the loot (called by LootTemplate processors)
    void AddItem(LootStoreItem const& item);

    bool AutoStore(Player* player, uint8 bag, uint8 slot, bool broadcast = false, bool createdByPlayer = false);

    void LootMoney();
    LootItem const* GetItemInSlot(uint32 lootListId) const;
    LootItem* LootItemInSlot(uint32 lootListId, Player const* player, NotNormalLootItem** ffaItem = nullptr);
    bool hasItemForAll() const;
    bool hasItemFor(Player const* player) const;
    bool hasOverThresholdItem() const;

    // Builds data for SMSG_LOOT_RESPONSE
    void BuildLootResponse(WorldPackets::Loot::LootResponse& packet, Player const* viewer) const;

    void Update();

private:
    GuidSet PlayersLooting;
    NotNormalLootItemMap PlayerFFAItems;

    // Loot GUID
    ObjectGuid _guid;
    ObjectGuid _owner;                                              // The WorldObject that holds this loot
    ItemContext _itemContext;
    LootMethod _lootMethod;
    std::unordered_map<uint32, LootRoll> _rolls;                    // used if an item is under rolling
    ObjectGuid _lootMaster;
    GuidUnorderedSet _allowedLooters;
    bool _wasOpened;                                                // true if at least one player received the loot content
    bool _changed;
    uint32 _dungeonEncounterId;
};

class TC_GAME_API AELootResult
{
public:
    struct ResultValue
    {
        Item* item;
        uint8 count;
        LootType lootType;
        uint32 dungeonEncounterId;
    };

    typedef std::vector<ResultValue> OrderedStorage;

    void Add(Item* item, uint8 count, LootType lootType, uint32 dungeonEncounterId);

    OrderedStorage::const_iterator begin() const;
    OrderedStorage::const_iterator end() const;

    OrderedStorage _byOrder;
    std::unordered_map<Item*, OrderedStorage::size_type> _byItem;
};

#endif // Loot_h__
