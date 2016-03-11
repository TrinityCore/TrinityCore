/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_LOOTMGR_H
#define TRINITY_LOOTMGR_H

#include "ItemEnchantmentMgr.h"
#include "ByteBuffer.h"
#include "RefManager.h"
#include "SharedDefines.h"
#include "ConditionMgr.h"
#include "ObjectGuid.h"
#include <map>
#include <vector>
#include <list>

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

enum LootMethod
{
    FREE_FOR_ALL      = 0,
    ROUND_ROBIN       = 1,
    MASTER_LOOT       = 2,
    GROUP_LOOT        = 3,
    NEED_BEFORE_GREED = 4,
    PERSONAL_LOOT     = 5
};

enum PermissionTypes
{
    ALL_PERMISSION              = 0,
    GROUP_PERMISSION            = 1,
    MASTER_PERMISSION           = 2,
    RESTRICTED_PERMISSION       = 3,
    ROUND_ROBIN_PERMISSION      = 4,
    OWNER_PERMISSION            = 5,
    NONE_PERMISSION             = 6
};

enum LootType
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

enum LootError
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
    LOOT_ERROR_NOT_WHILE_SHAPESHIFTED   = 16    // You can't do that while shapeshifted.
};

// type of Loot Item in Loot View
enum LootSlotType
{
    LOOT_SLOT_TYPE_ALLOW_LOOT   = 4,                        // player can loot the item.
    LOOT_SLOT_TYPE_ROLL_ONGOING = 7,                        // roll is ongoing. player cannot loot.
    LOOT_SLOT_TYPE_MASTER       = 6,                        // item can only be distributed by group loot master.
    LOOT_SLOT_TYPE_LOCKED       = 3,                        // item is shown in red. player cannot loot.
    LOOT_SLOT_TYPE_OWNER        = 5                         // ignore binding confirmation and etc, for single player looting
};

class Player;
class LootStore;

struct TC_GAME_API LootStoreItem
{
    uint32  itemid;                                         // id of the item
    uint32  reference;                                      // referenced TemplateleId
    float   chance;                                         // chance to drop for both quest and non-quest items, chance to be used for refs
    uint16  lootmode;
    bool    needs_quest : 1;                                // quest drop (quest is required for item to drop)
    uint8   groupid     : 7;
    uint8   mincount;                                       // mincount for drop items
    uint8   maxcount;                                       // max drop count for the item mincount or Ref multiplicator
    ConditionContainer conditions;                               // additional loot condition

    // Constructor
    // displayid is filled in IsValid() which must be called after
    LootStoreItem(uint32 _itemid, uint32 _reference, float _chance, bool _needs_quest, uint16 _lootmode, uint8 _groupid, uint8 _mincount, uint8 _maxcount)
        : itemid(_itemid), reference(_reference), chance(_chance), lootmode(_lootmode),
        needs_quest(_needs_quest), groupid(_groupid), mincount(_mincount), maxcount(_maxcount)
         { }

    bool Roll(bool rate) const;                             // Checks if the entry takes it's chance (at loot generation)
    bool IsValid(LootStore const& store, uint32 entry) const; // Checks correctness of values
};

struct TC_GAME_API LootItem
{
    uint32  itemid;
    uint32  randomSuffix;
    int32   randomPropertyId;
    std::vector<int32> BonusListIDs;
    ConditionContainer conditions;                               // additional loot condition
    GuidSet allowedGUIDs;
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
    LootItem() : itemid(0), randomSuffix(0), randomPropertyId(0), count(0), is_looted(false), is_blocked(false),
                 freeforall(false), is_underthreshold(false), is_counted(false), needs_quest(false), follow_loot_rules(false),
                 canSave(true){ };

    // Basic checks for player/item compatibility - if false no chance to see the item in the loot
    bool AllowedForPlayer(Player const* player) const;
    void AddAllowedLooter(Player const* player);
    GuidSet const& GetAllowedLooters() const { return allowedGUIDs; }
};

struct QuestItem
{
    uint8   index;                                          // position in quest_items;
    bool    is_looted;

    QuestItem()
        : index(0), is_looted(false) { }

    QuestItem(uint8 _index, bool _islooted = false)
        : index(_index), is_looted(_islooted) { }
};

struct Loot;
class LootTemplate;

typedef std::vector<QuestItem> QuestItemList;
typedef std::vector<LootItem> LootItemList;
typedef std::map<ObjectGuid::LowType, QuestItemList*> QuestItemMap;
typedef std::list<LootStoreItem*> LootStoreItemList;
typedef std::unordered_map<uint32, LootTemplate*> LootTemplateMap;

typedef std::set<uint32> LootIdSet;

class TC_GAME_API LootStore
{
    public:
        explicit LootStore(char const* name, char const* entryName, bool ratesAllowed)
            : m_name(name), m_entryName(entryName), m_ratesAllowed(ratesAllowed) { }

        virtual ~LootStore() { Clear(); }

        void Verify() const;

        uint32 LoadAndCollectLootIds(LootIdSet& ids_set);
        void CheckLootRefs(LootIdSet* ref_set = NULL) const; // check existence reference and remove it from ref_set
        void ReportUnusedIds(LootIdSet const& ids_set) const;
        void ReportNonExistingId(uint32 lootId) const;
        void ReportNonExistingId(uint32 lootId, const char* ownerType, uint32 ownerId) const;

        bool HaveLootFor(uint32 loot_id) const { return m_LootTemplates.find(loot_id) != m_LootTemplates.end(); }
        bool HaveQuestLootFor(uint32 loot_id) const;
        bool HaveQuestLootForPlayer(uint32 loot_id, Player* player) const;

        LootTemplate const* GetLootFor(uint32 loot_id) const;
        void ResetConditions();
        LootTemplate* GetLootForConditionFill(uint32 loot_id);

        char const* GetName() const { return m_name; }
        char const* GetEntryName() const { return m_entryName; }
        bool IsRatesAllowed() const { return m_ratesAllowed; }
    protected:
        uint32 LoadLootTable();
        void Clear();
    private:
        LootTemplateMap m_LootTemplates;
        char const* m_name;
        char const* m_entryName;
        bool m_ratesAllowed;
};

class TC_GAME_API LootTemplate
{
    class LootGroup;                                       // A set of loot definitions for items (refs are not allowed inside)
    typedef std::vector<LootGroup*> LootGroups;

    public:
        LootTemplate() { }
        ~LootTemplate();

        // Adds an entry to the group (at loading stage)
        void AddEntry(LootStoreItem* item);
        // Rolls for every item in the template and adds the rolled items the the loot
        void Process(Loot& loot, bool rate, uint16 lootMode, uint8 groupId = 0) const;
        void CopyConditions(const ConditionContainer& conditions);
        void CopyConditions(LootItem* li) const;

        // True if template includes at least 1 quest drop entry
        bool HasQuestDrop(LootTemplateMap const& store, uint8 groupId = 0) const;
        // True if template includes at least 1 quest drop for an active quest of the player
        bool HasQuestDropForPlayer(LootTemplateMap const& store, Player const* player, uint8 groupId = 0) const;

        // Checks integrity of the template
        void Verify(LootStore const& store, uint32 Id) const;
        void CheckLootRefs(LootTemplateMap const& store, LootIdSet* ref_set) const;
        bool addConditionItem(Condition* cond);
        bool isReference(uint32 id);

    private:
        LootStoreItemList Entries;                          // not grouped only
        LootGroups        Groups;                           // groups have own (optimised) processing, grouped entries go there

        // Objects of this class must never be copied, we are storing pointers in container
        LootTemplate(LootTemplate const&);
        LootTemplate& operator=(LootTemplate const&);
};

//=====================================================

class LootValidatorRef :  public Reference<Loot, LootValidatorRef>
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
        typedef LinkedListHead::Iterator< LootValidatorRef > iterator;

        LootValidatorRef* getFirst() { return (LootValidatorRef*)RefManager<Loot, LootValidatorRef>::getFirst(); }
        LootValidatorRef* getLast() { return (LootValidatorRef*)RefManager<Loot, LootValidatorRef>::getLast(); }

        iterator begin() { return iterator(getFirst()); }
        iterator end() { return iterator(NULL); }
        iterator rbegin() { return iterator(getLast()); }
        iterator rend() { return iterator(NULL); }
};

//=====================================================

struct TC_GAME_API Loot
{
    QuestItemMap const& GetPlayerQuestItems() const { return PlayerQuestItems; }
    QuestItemMap const& GetPlayerFFAItems() const { return PlayerFFAItems; }
    QuestItemMap const& GetPlayerNonQuestNonFFAConditionalItems() const { return PlayerNonQuestNonFFAConditionalItems; }

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

    Loot(uint32 _gold = 0) : gold(_gold), unlootedCount(0), roundRobinPlayer(), loot_type(LOOT_CORPSE), maxDuplicates(1), _difficultyBonusTreeMod(0){ }
    ~Loot() { clear(); }

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

    // void clear();
    void clear()
    {
        for (QuestItemMap::const_iterator itr = PlayerQuestItems.begin(); itr != PlayerQuestItems.end(); ++itr)
            delete itr->second;
        PlayerQuestItems.clear();

        for (QuestItemMap::const_iterator itr = PlayerFFAItems.begin(); itr != PlayerFFAItems.end(); ++itr)
            delete itr->second;
        PlayerFFAItems.clear();

        for (QuestItemMap::const_iterator itr = PlayerNonQuestNonFFAConditionalItems.begin(); itr != PlayerNonQuestNonFFAConditionalItems.end(); ++itr)
            delete itr->second;
        PlayerNonQuestNonFFAConditionalItems.clear();

        PlayersLooting.clear();
        items.clear();
        quest_items.clear();
        gold = 0;
        unlootedCount = 0;
        roundRobinPlayer.Clear();
        loot_type = LOOT_NONE;
        i_LootValidatorRefManager.clearReferences();
        _difficultyBonusTreeMod = 0;
    }

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

    LootItem* LootItemInSlot(uint32 lootslot, Player* player, QuestItem** qitem = NULL, QuestItem** ffaitem = NULL, QuestItem** conditem = NULL);
    uint32 GetMaxSlotInLootFor(Player* player) const;
    bool hasItemFor(Player* player) const;
    bool hasOverThresholdItem() const;

    // Builds data for SMSG_LOOT_RESPONSE
    void BuildLootResponse(WorldPackets::Loot::LootResponse& packet, Player* viewer, PermissionTypes permission = ALL_PERMISSION) const;

private:

    void FillNotNormalLootFor(Player* player, bool presentAtLooting);
    QuestItemList* FillFFALoot(Player* player);
    QuestItemList* FillQuestLoot(Player* player);
    QuestItemList* FillNonQuestNonFFAConditionalLoot(Player* player, bool presentAtLooting);

    GuidSet PlayersLooting;
    QuestItemMap PlayerQuestItems;
    QuestItemMap PlayerFFAItems;
    QuestItemMap PlayerNonQuestNonFFAConditionalItems;

    // All rolls are registered here. They need to know, when the loot is not valid anymore
    LootValidatorRefManager i_LootValidatorRefManager;

    // Loot GUID
    ObjectGuid _GUID;
    uint32 _difficultyBonusTreeMod;
};

TC_GAME_API extern LootStore LootTemplates_Creature;
TC_GAME_API extern LootStore LootTemplates_Fishing;
TC_GAME_API extern LootStore LootTemplates_Gameobject;
TC_GAME_API extern LootStore LootTemplates_Item;
TC_GAME_API extern LootStore LootTemplates_Mail;
TC_GAME_API extern LootStore LootTemplates_Milling;
TC_GAME_API extern LootStore LootTemplates_Pickpocketing;
TC_GAME_API extern LootStore LootTemplates_Reference;
TC_GAME_API extern LootStore LootTemplates_Skinning;
TC_GAME_API extern LootStore LootTemplates_Disenchant;
TC_GAME_API extern LootStore LootTemplates_Prospecting;
TC_GAME_API extern LootStore LootTemplates_Spell;

TC_GAME_API void LoadLootTemplates_Creature();
TC_GAME_API void LoadLootTemplates_Fishing();
TC_GAME_API void LoadLootTemplates_Gameobject();
TC_GAME_API void LoadLootTemplates_Item();
TC_GAME_API void LoadLootTemplates_Mail();
TC_GAME_API void LoadLootTemplates_Milling();
TC_GAME_API void LoadLootTemplates_Pickpocketing();
TC_GAME_API void LoadLootTemplates_Skinning();
TC_GAME_API void LoadLootTemplates_Disenchant();
TC_GAME_API void LoadLootTemplates_Prospecting();

TC_GAME_API void LoadLootTemplates_Spell();
TC_GAME_API void LoadLootTemplates_Reference();

TC_GAME_API void LoadLootTables();

#endif
