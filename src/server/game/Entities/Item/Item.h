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

#ifndef TRINITYCORE_ITEM_H
#define TRINITYCORE_ITEM_H

#include "Object.h"
#include "Common.h"
#include "DatabaseEnvFwd.h"
#include "ItemDefines.h"
#include "ItemEnchantmentMgr.h"
#include "ItemTemplate.h"
#include "Loot.h"

class SpellInfo;
class Bag;
class Unit;
namespace WorldPackets
{
    namespace Item
    {
        struct ItemInstance;
    }
}

struct ItemSetEffect
{
    uint32 ItemSetID;
    uint32 EquippedItemCount;
    std::unordered_set<ItemSetSpellEntry const*> SetBonuses;
};

#define MAX_GEM_SOCKETS               MAX_ITEM_PROTO_SOCKETS// (BONUS_ENCHANTMENT_SLOT-SOCK_ENCHANTMENT_SLOT) and item proto size, equal value expected

enum EnchantmentOffset
{
    ENCHANTMENT_ID_OFFSET       = 0,
    ENCHANTMENT_DURATION_OFFSET = 1,
    ENCHANTMENT_CHARGES_OFFSET  = 2                         // now here not only charges, but something new in wotlk
};

#define MAX_ENCHANTMENT_OFFSET    3

enum ItemUpdateState
{
    ITEM_UNCHANGED                               = 0,
    ITEM_CHANGED                                 = 1,
    ITEM_NEW                                     = 2,
    ITEM_REMOVED                                 = 3
};


#define MAX_ITEM_SPELLS 5

bool ItemCanGoIntoBag(ItemTemplate const* proto, ItemTemplate const* pBagProto);
extern ItemModifier const AppearanceModifierSlotBySpec[MAX_SPECIALIZATIONS];
extern ItemModifier const IllusionModifierSlotBySpec[MAX_SPECIALIZATIONS];
extern int32 const ItemTransmogrificationSlots[MAX_INVTYPE];

struct BonusData
{
    uint32 Quality;
    int32 ItemLevelBonus;
    int32 RequiredLevel;
    int32 ItemStatType[MAX_ITEM_PROTO_STATS];
    int32 ItemStatAllocation[MAX_ITEM_PROTO_STATS];
    float ItemStatSocketCostMultiplier[MAX_ITEM_PROTO_STATS];
    uint32 SocketColor[MAX_ITEM_PROTO_SOCKETS];
    ItemBondingType Bonding;
    uint32 AppearanceModID;
    float RepairCostMultiplier;
    uint32 ScalingStatDistribution;
    uint32 ContentTuningId;
    uint32 DisenchantLootId;
    uint32 GemItemLevelBonus[MAX_ITEM_PROTO_SOCKETS];
    int32 GemRelicType[MAX_ITEM_PROTO_SOCKETS];
    uint16 GemRelicRankBonus[MAX_ITEM_PROTO_SOCKETS];
    int32 RelicType;
    int32 RequiredLevelOverride;
    int32 AzeriteTierUnlockSetId;
    uint32 Suffix;
    bool CanDisenchant;
    bool CanScrap;
    bool HasFixedLevel;

    void Initialize(ItemTemplate const* proto);
    void Initialize(WorldPackets::Item::ItemInstance const& itemInstance);
    void AddBonusList(uint32 bonusListId);
    void AddBonus(uint32 type, int32 const (&values)[3]);

private:
    struct
    {
        int32 SuffixPriority;
        int32 AppearanceModPriority;
        int32 ScalingStatDistributionPriority;
        int32 AzeriteTierUnlockSetPriority;
        bool HasQualityBonus;
    } _state;
};

struct ArtifactPowerData
{
    uint32 ArtifactPowerId = 0;
    uint8 PurchasedRank = 0;
    uint8 CurrentRankWithBonus = 0;
};

struct ArtifactData
{
    uint64 Xp = 0;
    uint32 ArtifactAppearanceId = 0;
    uint32 ArtifactTierId = 0;
    std::vector<ArtifactPowerData> ArtifactPowers;
};

struct AzeriteItemSelectedEssencesData
{
    uint32 SpecializationId = 0;
    std::array<uint32, MAX_AZERITE_ESSENCE_SLOT> AzeriteEssenceId = { };
};

struct AzeriteItemData
{
    uint64 Xp;
    uint32 Level;
    uint32 KnowledgeLevel;
    std::vector<uint32> AzeriteItemMilestonePowers;
    std::vector<AzeriteEssencePowerEntry const*> UnlockedAzeriteEssences;
    std::array<AzeriteItemSelectedEssencesData, MAX_SPECIALIZATIONS> SelectedAzeriteEssences = { };
};

struct AzeriteEmpoweredItemData
{
    std::array<int32, MAX_AZERITE_EMPOWERED_TIER> SelectedAzeritePowers;
};

struct ItemAdditionalLoadInfo
{
    static void Init(std::unordered_map<ObjectGuid::LowType, ItemAdditionalLoadInfo>* loadInfo, PreparedQueryResult artifactResult, PreparedQueryResult azeriteItemResult,
        PreparedQueryResult azeriteItemMilestonePowersResult, PreparedQueryResult azeriteItemUnlockedEssencesResult, PreparedQueryResult azeriteEmpoweredItemResult);

    Optional<ArtifactData> Artifact;
    Optional<AzeriteItemData> AzeriteItem;
    Optional<AzeriteEmpoweredItemData> AzeriteEmpoweredItem;
};

struct ItemDynamicFieldGems
{
    uint32 ItemId;
    uint16 BonusListIDs[16];
    uint8 Context;
};

Item* NewItemOrBag(ItemTemplate const* proto);

class TC_GAME_API Item : public Object
{
    friend void AddItemToUpdateQueueOf(Item* item, Player* player);
    friend void RemoveItemFromUpdateQueueOf(Item* item, Player* player);
    public:
        static Item* CreateItem(uint32 itemEntry, uint32 count, ItemContext context, Player const* player = nullptr);
        Item* CloneItem(uint32 count, Player const* player = nullptr) const;

        Item();

        virtual bool Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner);

        std::string GetNameForLocaleIdx(LocaleConstant locale) const override;

        ItemTemplate const* GetTemplate() const;
        BonusData const* GetBonus() const { return &_bonusData; }

        ObjectGuid GetOwnerGUID()    const { return m_itemData->Owner; }
        void SetOwnerGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Owner), guid); }
        ObjectGuid GetContainedIn()    const { return m_itemData->ContainedIn; }
        void SetContainedIn(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ContainedIn), guid); }
        ObjectGuid GetCreator()    const { return m_itemData->Creator; }
        void SetCreator(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Creator), guid); }
        ObjectGuid GetGiftCreator()    const { return m_itemData->GiftCreator; }
        void SetGiftCreator(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::GiftCreator), guid); }
        Player* GetOwner() const;

        void SetExpiration(uint32 expiration) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Expiration), expiration); }

        ItemBondingType GetBonding() const { return _bonusData.Bonding; }
        void SetBinding(bool val)
        {
            if (val)
                AddItemFlag(ITEM_FIELD_FLAG_SOULBOUND);
            else
                RemoveItemFlag(ITEM_FIELD_FLAG_SOULBOUND);
        }
        bool HasItemFlag(ItemFieldFlags flag) const { return (*m_itemData->DynamicFlags & flag) != 0; }
        void AddItemFlag(ItemFieldFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags), flags); }
        void RemoveItemFlag(ItemFieldFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags), flags); }
        void SetItemFlags(ItemFieldFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags), flags); }
        bool HasItemFlag2(ItemFieldFlags2 flag) const { return (*m_itemData->DynamicFlags2 & flag) != 0; }
        void AddItemFlag2(ItemFieldFlags2 flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags2), flags); }
        void RemoveItemFlag2(ItemFieldFlags2 flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags2), flags); }
        void SetItemFlags2(ItemFieldFlags2 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::DynamicFlags2), flags); }
        bool IsSoulBound() const { return HasItemFlag(ITEM_FIELD_FLAG_SOULBOUND); }
        bool IsBoundAccountWide() const { return (GetTemplate()->GetFlags() & ITEM_FLAG_IS_BOUND_TO_ACCOUNT) != 0; }
        bool IsBattlenetAccountBound() const { return (GetTemplate()->GetFlags2() & ITEM_FLAG2_BNET_ACCOUNT_TRADE_OK) != 0; }
        bool IsBindedNotWith(Player const* player) const;
        bool IsBoundByEnchant() const;
        virtual void SaveToDB(CharacterDatabaseTransaction& trans);
        virtual bool LoadFromDB(ObjectGuid::LowType guid, ObjectGuid ownerGuid, Field* fields, uint32 entry);
        void LoadArtifactData(Player const* owner, uint64 xp, uint32 artifactAppearanceId, uint32 artifactTier, std::vector<ArtifactPowerData>& powers);  // must be called after LoadFromDB to have gems (relics) initialized
        void CheckArtifactRelicSlotUnlock(Player const* owner);

        void AddBonuses(uint32 bonusListID);
        void SetBonuses(std::vector<int32> bonusListIDs);
        void ClearBonuses();

        static void DeleteFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid);
        virtual void DeleteFromDB(CharacterDatabaseTransaction& trans);
        static void DeleteFromInventoryDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid);

        // Lootable items and their contents
        void ItemContainerSaveLootToDB();
        bool ItemContainerLoadLootFromDB();
        void ItemContainerDeleteLootItemsFromDB();
        void ItemContainerDeleteLootItemFromDB(uint32 itemID);
        void ItemContainerDeleteLootMoneyFromDB();
        void ItemContainerDeleteLootMoneyAndLootItemsFromDB();

        void DeleteFromInventoryDB(CharacterDatabaseTransaction& trans);
        void SaveRefundDataToDB();
        void DeleteRefundDataFromDB(CharacterDatabaseTransaction* trans);

        Bag* ToBag() { if (IsBag()) return reinterpret_cast<Bag*>(this); else return nullptr; }
        Bag const* ToBag() const { if (IsBag()) return reinterpret_cast<Bag const*>(this); else return nullptr; }
        AzeriteItem* ToAzeriteItem() { return IsAzeriteItem() ? reinterpret_cast<AzeriteItem*>(this) : nullptr; }
        AzeriteItem const* ToAzeriteItem() const { return IsAzeriteItem() ? reinterpret_cast<AzeriteItem const*>(this) : nullptr; }
        AzeriteEmpoweredItem* ToAzeriteEmpoweredItem() { return IsAzeriteEmpoweredItem() ? reinterpret_cast<AzeriteEmpoweredItem*>(this) : nullptr; }
        AzeriteEmpoweredItem const* ToAzeriteEmpoweredItem() const { return IsAzeriteEmpoweredItem() ? reinterpret_cast<AzeriteEmpoweredItem const*>(this) : nullptr; }

        bool IsLocked() const { return !HasItemFlag(ITEM_FIELD_FLAG_UNLOCKED); }
        bool IsBag() const { return GetTemplate()->GetInventoryType() == INVTYPE_BAG; }
        bool IsAzeriteItem() const { return GetTypeId() == TYPEID_AZERITE_ITEM; }
        bool IsAzeriteEmpoweredItem() const { return GetTypeId() == TYPEID_AZERITE_EMPOWERED_ITEM; }
        bool IsCurrencyToken() const { return GetTemplate()->IsCurrencyToken(); }
        bool IsNotEmptyBag() const;
        bool IsBroken() const { return *m_itemData->MaxDurability > 0 && *m_itemData->Durability == 0; }
        void SetDurability(uint32 durability) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Durability), durability); }
        bool CanBeTraded(bool mail = false, bool trade = false) const;
        void SetInTrade(bool b = true) { mb_in_trade = b; }
        bool IsInTrade() const { return mb_in_trade; }

        bool HasEnchantRequiredSkill(const Player* player) const;
        uint32 GetEnchantRequiredLevel() const;

        bool IsFitToSpellRequirements(SpellInfo const* spellInfo) const;
        bool IsLimitedToAnotherMapOrZone(uint32 cur_mapId, uint32 cur_zoneId) const;
        bool GemsFitSockets() const;

        uint32 GetCount() const { return m_itemData->StackCount; }
        void SetCount(uint32 value);
        uint32 GetMaxStackCount() const { return GetTemplate()->GetMaxStackSize(); }
        uint8 GetGemCountWithID(uint32 GemID) const;
        uint8 GetGemCountWithLimitCategory(uint32 limitCategory) const;
        InventoryResult CanBeMergedPartlyWith(ItemTemplate const* proto) const;

        uint8 GetSlot() const {return m_slot;}
        Bag* GetContainer() { return m_container; }
        uint8 GetBagSlot() const;
        void SetSlot(uint8 slot) { m_slot = slot; }
        uint16 GetPos() const { return uint16(GetBagSlot()) << 8 | GetSlot(); }
        void SetContainer(Bag* container) { m_container = container; }

        bool IsInBag() const { return m_container != NULL; }
        bool IsEquipped() const;

        uint32 GetSkill();

        ItemRandomBonusListId GetItemRandomBonusListId() const { return m_randomBonusListId; }
        void SetItemRandomBonusList(ItemRandomBonusListId bonusListId);
        void SetEnchantment(EnchantmentSlot slot, uint32 id, uint32 duration, uint32 charges, ObjectGuid caster = ObjectGuid::Empty);
        void SetEnchantmentDuration(EnchantmentSlot slot, uint32 duration, Player* owner);
        void SetEnchantmentCharges(EnchantmentSlot slot, uint32 charges);
        void ClearEnchantment(EnchantmentSlot slot);
        uint32 GetEnchantmentId(EnchantmentSlot slot)       const { return m_itemData->Enchantment[slot].ID; }
        uint32 GetEnchantmentDuration(EnchantmentSlot slot) const { return m_itemData->Enchantment[slot].Duration; }
        uint32 GetEnchantmentCharges(EnchantmentSlot slot)  const { return m_itemData->Enchantment[slot].Charges; }
        UF::SocketedGem const* GetGem(uint16 slot) const;
        void SetGem(uint16 slot, ItemDynamicFieldGems const* gem, uint32 gemScalingLevel);

        std::string const& GetText() const { return m_text; }
        void SetText(std::string const& text) { m_text = text; }

        void SendUpdateSockets();

        void SendTimeUpdate(Player* owner);
        void UpdateDuration(Player* owner, uint32 diff);
        void SetCreatePlayedTime(uint32 createPlayedTime) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::CreatePlayedTime), createPlayedTime); }

        // spell charges (signed but stored as unsigned)
        int32 GetSpellCharges(uint8 index/*0..5*/ = 0) const { return m_itemData->SpellCharges[index]; }
        void  SetSpellCharges(uint8 index/*0..5*/, int32 value) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::SpellCharges, index), value); }

        Loot loot;
        bool m_lootGenerated;

        // Update States
        ItemUpdateState GetState() const { return uState; }
        void SetState(ItemUpdateState state, Player* forplayer = NULL);
        void RemoveFromUpdateQueueOf(Player* player);
        bool IsInUpdateQueue() const { return uQueuePos != -1; }
        uint16 GetQueuePos() const { return uQueuePos; }
        void FSetState(ItemUpdateState state)               // forced
        {
            uState = state;
        }

        bool hasQuest(uint32 quest_id) const override { return GetTemplate()->GetStartQuest() == quest_id; }
        bool hasInvolvedQuest(uint32 /*quest_id*/) const override { return false; }
        bool IsPotion() const { return GetTemplate()->IsPotion(); }
        bool IsVellum() const { return GetTemplate()->IsVellum(); }
        bool IsConjuredConsumable() const { return GetTemplate()->IsConjuredConsumable(); }
        bool IsRangedWeapon() const { return GetTemplate()->IsRangedWeapon(); }
        uint32 GetQuality() const { return _bonusData.Quality; }
        uint32 GetItemLevel(Player const* owner) const;
        static uint32 GetItemLevel(ItemTemplate const* itemTemplate, BonusData const& bonusData, uint32 level, uint32 fixedLevel,
            uint32 minItemLevel, uint32 minItemLevelCutoff, uint32 maxItemLevel, bool pvpBonus, uint32 azeriteLevel);
        int32 GetRequiredLevel() const;
        int32 GetItemStatType(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_STATS); return _bonusData.ItemStatType[index]; }
        int32 GetItemStatValue(uint32 index, Player const* owner) const;
        SocketColor GetSocketColor(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_SOCKETS); return SocketColor(_bonusData.SocketColor[index]); }
        uint32 GetAppearanceModId() const { return m_itemData->ItemAppearanceModID; }
        void SetAppearanceModId(uint32 appearanceModId) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemAppearanceModID), appearanceModId); }
        uint32 GetArmor(Player const* owner) const { return GetTemplate()->GetArmor(GetItemLevel(owner)); }
        void GetDamage(Player const* owner, float& minDamage, float& maxDamage) const { GetTemplate()->GetDamage(GetItemLevel(owner), minDamage, maxDamage); }
        uint32 GetDisplayId(Player const* owner) const;
        ItemModifiedAppearanceEntry const* GetItemModifiedAppearance() const;
        float GetRepairCostMultiplier() const { return _bonusData.RepairCostMultiplier; }
        uint32 GetScalingStatDistribution() const { return _bonusData.ScalingStatDistribution; }
        ItemDisenchantLootEntry const* GetDisenchantLoot(Player const* owner) const;
        static ItemDisenchantLootEntry const* GetDisenchantLoot(ItemTemplate const* itemTemplate, uint32 quality, uint32 itemLevel);
        void SetFixedLevel(uint8 level);

        // Item Refund system
        void SetNotRefundable(Player* owner, bool changestate = true, CharacterDatabaseTransaction* trans = nullptr, bool addToCollection = true);
        void SetRefundRecipient(ObjectGuid const& guid) { m_refundRecipient = guid; }
        void SetPaidMoney(uint64 money) { m_paidMoney = money; }
        void SetPaidExtendedCost(uint32 iece) { m_paidExtendedCost = iece; }

        ObjectGuid const& GetRefundRecipient() const { return m_refundRecipient; }
        uint64 GetPaidMoney() const { return m_paidMoney; }
        uint32 GetPaidExtendedCost() const { return m_paidExtendedCost; }

        void UpdatePlayedTime(Player* owner);
        uint32 GetPlayedTime();
        bool IsRefundExpired();

        // Soulbound trade system
        void SetSoulboundTradeable(GuidSet const& allowedLooters);
        void ClearSoulboundTradeable(Player* currentOwner);
        bool CheckSoulboundTradeExpire();

        void BuildUpdate(UpdateDataMapType&) override;
        UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const override;
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const override;
        void ClearUpdateMask(bool remove) override;
        void AddToObjectUpdate() override;
        void RemoveFromObjectUpdate() override;

        uint32 GetScriptId() const { return GetTemplate()->ScriptId; }

        bool IsValidTransmogrificationTarget() const;
        bool HasStats() const;
        static bool HasStats(WorldPackets::Item::ItemInstance const& itemInstance, BonusData const* bonus);
        static bool CanTransmogrifyItemWithItem(Item const* item, ItemModifiedAppearanceEntry const* itemModifiedAppearance);
        uint32 GetBuyPrice(Player const* owner, bool& standardPrice) const;
        static uint32 GetBuyPrice(ItemTemplate const* proto, uint32 quality, uint32 itemLevel, bool& standardPrice);
        uint32 GetSellPrice(Player const* owner) const;
        static uint32 GetSellPrice(ItemTemplate const* proto, uint32 quality, uint32 itemLevel);

        uint32 GetVisibleEntry(Player const* owner) const;
        uint16 GetVisibleAppearanceModId(Player const* owner) const;
        uint32 GetVisibleEnchantmentId(Player const* owner) const;
        uint16 GetVisibleItemVisual(Player const* owner) const;

        uint32 GetModifier(ItemModifier modifier) const;
        void SetModifier(ItemModifier modifier, uint32 value);

        ObjectGuid GetChildItem() const { return m_childItem; }
        void SetChildItem(ObjectGuid childItem) { m_childItem = childItem; }

        bool IsArtifactDisabled() const;

        UF::ArtifactPower const* GetArtifactPower(uint32 artifactPowerId) const;
        void AddArtifactPower(ArtifactPowerData const* artifactPower);
        void SetArtifactPower(uint16 artifactPowerId, uint8 purchasedRank, uint8 currentRankWithBonus);

        void InitArtifactPowers(uint8 artifactId, uint8 artifactTier);
        uint32 GetTotalPurchasedArtifactPowers() const;
        void ApplyArtifactPowerEnchantmentBonuses(EnchantmentSlot slot, uint32 enchantId, bool apply, Player* owner);
        void CopyArtifactDataFromParent(Item* parent);

        void SetArtifactXP(uint64 xp) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ArtifactXP), xp); }
        void GiveArtifactXp(uint64 amount, Item* sourceItem, uint32 artifactCategoryId);

        ItemContext GetContext() const { return ItemContext(*m_itemData->Context); }
        void SetContext(ItemContext context) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Context), int32(context)); }

        void SetPetitionId(uint32 petitionId) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, 0).ModifyValue(&UF::ItemEnchantment::ID), petitionId); }
        void SetPetitionNumSignatures(uint32 signatures) { SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, 0).ModifyValue(&UF::ItemEnchantment::Duration), signatures); }

        UF::UpdateField<UF::ItemData, 0, TYPEID_ITEM> m_itemData;

    protected:
        void ApplyBonusList(uint32 itemBonusListId);
        BonusData _bonusData;

    private:
        std::string m_text;
        uint8 m_slot;
        Bag* m_container;
        ItemUpdateState uState;
        int16 uQueuePos;
        bool mb_in_trade;                                   // true if item is currently in trade-window
        time_t m_lastPlayedTimeUpdate;
        ObjectGuid m_refundRecipient;
        uint64 m_paidMoney;
        uint32 m_paidExtendedCost;
        GuidSet allowedGUIDs;
        ItemRandomBonusListId m_randomBonusListId;          // store separately to easily find which bonus list is the one randomly given for stat rerolling
        ObjectGuid m_childItem;
        std::unordered_map<uint32, uint16> m_artifactPowerIdToIndex;
        std::array<uint32, MAX_ITEM_PROTO_SOCKETS> m_gemScalingLevels;
};
#endif
