/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "Define.h"
#include "ConditionMgr.h"
#include "ItemEnchantmentMgr.h"
#include "ObjectGuid.h"
#include "RefManager.h"
#include "SharedDefines.h"
#include <unordered_map>
#include <vector>

class Item;
class LootStore;
class Player;
struct Loot;
struct LootStoreItem;

namespace WorldPackets
{
    namespace Loot
    {
        class LootResponse;
    }
}

enum RollType
{
    ROLL_PASS         = 0,
    ROLL_NEED         = 1,
    ROLL_GREED        = 2,
    ROLL_DISENCHANT   = 3,
    MAX_ROLL_TYPE     = 4
};

enum RollMask
{
    ROLL_FLAG_TYPE_PASS         = 0x01,
    ROLL_FLAG_TYPE_NEED         = 0x02,
    ROLL_FLAG_TYPE_GREED        = 0x04,
    ROLL_FLAG_TYPE_DISENCHANT   = 0x08,

    ROLL_ALL_TYPE_NO_DISENCHANT = 0x07,
    ROLL_ALL_TYPE_MASK          = 0x0F
};

#define MAX_NR_LOOT_ITEMS 16
// note: the client cannot show more than 16 items total
#define MAX_NR_QUEST_ITEMS 32
// unrelated to the number of quest items shown, just for reserve

enum LootMethod : uint8
{
    FREE_FOR_ALL      = 0,
    MASTER_LOOT       = 2,
    GROUP_LOOT        = 3,
    PERSONAL_LOOT     = 5
};

enum PermissionTypes
{
    ALL_PERMISSION              = 0,
    GROUP_PERMISSION            = 1,
    MASTER_PERMISSION           = 2,
    RESTRICTED_PERMISSION       = 3,
    OWNER_PERMISSION            = 5,
    NONE_PERMISSION             = 6
};

enum LootType : uint8
{
    LOOT_NONE                   = 0,

    LOOT_CORPSE                 = 1,
    LOOT_PICKPOCKETING          = 2,
    LOOT_FISHING                = 3,
    LOOT_DISENCHANTING          = 4,
                                                            // ignored always by client
    LOOT_SKINNING               = 6,
    LOOT_PROSPECTING            = 7,
    LOOT_MILLING                = 8,

    LOOT_FISHINGHOLE            = 20,                       // unsupported by client, sending LOOT_FISHING instead
    LOOT_INSIGNIA               = 21,                       // unsupported by client, sending LOOT_CORPSE instead
    LOOT_FISHING_JUNK           = 22                        // unsupported by client, sending LOOT_FISHING instead
};

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

struct TC_GAME_API LootItem
{
    uint32  itemid;
    ItemRandomBonusListId randomBonusListId;
    int32   upgradeId;
    std::vector<int32> BonusListIDs;
    uint8   context;
    ConditionContainer conditions;                               // additional loot condition
    GuidSet allowedGUIDs;
    ObjectGuid rollWinnerGUID;                                   // Stores the guid of person who won loot, if his bags are full only he can see the item in loot list!
    uint8   count             : 8;
    bool    is_looted         : 1;
    bool    is_blocked        : 1;
    bool    freeforall        : 1;                          // free for all
    bool    is_underthreshold : 1;
    bool    is_counted        : 1;
    bool    needs_quest       : 1;                          // quest drop
    bool    follow_loot_rules : 1;
    bool    canSave;

    // Constructor, copies most fields from LootStoreItem, generates random count and random suffixes/properties
    // Should be called for non-reference LootStoreItem entries only (reference = 0)
    explicit LootItem(LootStoreItem const& li);

    // Empty constructor for creating an empty LootItem to be filled in with DB data
    LootItem() : itemid(0), randomBonusListId(0), upgradeId(0), context(0), count(0), is_looted(false), is_blocked(false),
                 freeforall(false), is_underthreshold(false), is_counted(false), needs_quest(false), follow_loot_rules(false),
                 canSave(true){ };

    // Basic checks for player/item compatibility - if false no chance to see the item in the loot
    bool AllowedForPlayer(Player const* player) const;
    void AddAllowedLooter(Player const* player);
    GuidSet const& GetAllowedLooters() const { return allowedGUIDs; }
};

struct NotNormalLootItem
{
    uint8   index;                                          // position in quest_items or items;
    bool    is_looted;

    NotNormalLootItem()
        : index(0), is_looted(false) { }

    NotNormalLootItem(uint8 _index, bool _islooted = false)
        : index(_index), is_looted(_islooted) { }
};

typedef std::vector<NotNormalLootItem> NotNormalLootItemList;
typedef std::vector<LootItem> LootItemList;
typedef std::unordered_map<ObjectGuid, NotNormalLootItemList*> NotNormalLootItemMap;

//=====================================================

class LootValidatorRef : public Reference<Loot, LootValidatorRef>
{
public:
    LootValidatorRef() { }
    void targetObjectDestroyLink() override { }
    void sourceObjectDestroyLink() override { }
};

//=====================================================

class LootValidatorRefManager : public RefManager<Loot, LootValidatorRef>
{
public:
    typedef LinkedListHead::Iterator<LootValidatorRef> iterator;

    LootValidatorRef* getFirst() { return (LootValidatorRef*)RefManager<Loot, LootValidatorRef>::getFirst(); }

    iterator begin() { return iterator(getFirst()); }
    iterator end() { return iterator(nullptr); }
};

//=====================================================

struct TC_GAME_API Loot
{
    NotNormalLootItemMap const& GetPlayerQuestItems() const { return PlayerQuestItems; }
    NotNormalLootItemMap const& GetPlayerFFAItems() const { return PlayerFFAItems; }
    NotNormalLootItemMap const& GetPlayerNonQuestNonFFAConditionalItems() const { return PlayerNonQuestNonFFAConditionalItems; }

    std::vector<LootItem> items;
    std::vector<LootItem> quest_items;
    uint32 gold;
    uint8 unlootedCount;
    ObjectGuid roundRobinPlayer;                            // GUID of the player having the Round-Robin ownership for the loot. If 0, round robin owner has released.
    LootType loot_type;                                     // required for achievement system
    uint8 maxDuplicates;                                    // Max amount of items with the same entry that can drop (default is 1; on 25 man raid mode 3)

    // GUID of container that holds this loot (item_instance.entry)
    //  Only set for inventory items that can be right-click looted
    ObjectGuid containerID;

    Loot(uint32 _gold = 0);
    ~Loot();

    ObjectGuid const& GetGUID() const { return _GUID; }
    void SetGUID(ObjectGuid const& guid) { _GUID = guid; }

    // For deleting items at loot removal since there is no backward interface to the Item()
    void DeleteLootItemFromContainerItemDB(uint32 itemID);
    void DeleteLootMoneyFromContainerItemDB();

    // if loot becomes invalid this reference is used to inform the listener
    void addLootValidatorRef(LootValidatorRef* pLootValidatorRef)
    {
        i_LootValidatorRefManager.insertFirst(pLootValidatorRef);
    }

    void clear();

    bool empty() const { return items.empty() && gold == 0; }
    bool isLooted() const { return gold == 0 && unlootedCount == 0; }

    void NotifyItemRemoved(uint8 lootIndex);
    void NotifyQuestItemRemoved(uint8 questIndex);
    void NotifyMoneyRemoved();
    void AddLooter(ObjectGuid GUID) { PlayersLooting.insert(GUID); }
    void RemoveLooter(ObjectGuid GUID) { PlayersLooting.erase(GUID); }

    void generateMoneyLoot(uint32 minAmount, uint32 maxAmount);
    bool FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError = false, uint16 lootMode = LOOT_MODE_DEFAULT);

    // Inserts the item into the loot (called by LootTemplate processors)
    void AddItem(LootStoreItem const & item);

    LootItem const* GetItemInSlot(uint32 lootSlot) const;
    LootItem* LootItemInSlot(uint32 lootslot, Player* player, NotNormalLootItem** qitem = NULL, NotNormalLootItem** ffaitem = NULL, NotNormalLootItem** conditem = NULL);
    uint32 GetMaxSlotInLootFor(Player* player) const;
    bool hasItemForAll() const;
    bool hasItemFor(Player const* player) const;
    bool hasOverThresholdItem() const;

    // Builds data for SMSG_LOOT_RESPONSE
    void BuildLootResponse(WorldPackets::Loot::LootResponse& packet, Player* viewer, PermissionTypes permission = ALL_PERMISSION) const;

private:

    void FillNotNormalLootFor(Player* player, bool presentAtLooting);
    NotNormalLootItemList* FillFFALoot(Player* player);
    NotNormalLootItemList* FillQuestLoot(Player* player);
    NotNormalLootItemList* FillNonQuestNonFFAConditionalLoot(Player* player, bool presentAtLooting);

    GuidSet PlayersLooting;
    NotNormalLootItemMap PlayerQuestItems;
    NotNormalLootItemMap PlayerFFAItems;
    NotNormalLootItemMap PlayerNonQuestNonFFAConditionalItems;

    // All rolls are registered here. They need to know, when the loot is not valid anymore
    LootValidatorRefManager i_LootValidatorRefManager;

    // Loot GUID
    ObjectGuid _GUID;
    uint8 _itemContext;
};

class TC_GAME_API AELootResult
{
public:
    struct ResultValue
    {
        Item* item;
        uint8 count;
        LootType lootType;
    };

    typedef std::vector<ResultValue> OrderedStorage;

    void Add(Item* item, uint8 count, LootType lootType);

    OrderedStorage::const_iterator begin() const;
    OrderedStorage::const_iterator end() const;

    OrderedStorage _byOrder;
    std::unordered_map<Item*, OrderedStorage::size_type> _byItem;
};

#endif // Loot_h__
