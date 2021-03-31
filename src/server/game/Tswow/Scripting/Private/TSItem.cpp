/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include <memory.h>
#include "Object.h"
#include "Item.h"
#include "Bag.h"

#include "TSIncludes.h"
#include "TSItem.h"
#include "TSString.h"
#include "TSPlayer.h"

TSItem::TSItem(Item *item) : TSObject(item)
{
    this->item = item;
}

TSItem::TSItem() : TSObject()
{
    this->item = nullptr;
}

/**
 * Returns 'true' if the [Item] is soulbound, 'false' otherwise
 *
 * @return bool isSoulBound
 */
bool TSItem::IsSoulBound() 
{
    return item->IsSoulBound();
}
    
#if (!defined(TBC) && !defined(CLASSIC))
/**
 * Returns 'true' if the [Item] is account bound, 'false' otherwise
 *
 * @return bool isAccountBound
 */
bool TSItem::IsBoundAccountWide() 
{
    return item->IsBoundAccountWide();
}
#endif
    
/**
 * Returns 'true' if the [Item] is bound to a [Player] by an enchant, 'false' otehrwise
 *
 * @return bool isBoundByEnchant
 */
bool TSItem::IsBoundByEnchant() 
{
    return item->IsBoundByEnchant();
}
    
/**
 * Returns 'true' if the [Item] is not bound to the [Player] specified, 'false' otherwise
 *
 * @param [Player] player : the [Player] object to check the item against
 * @return bool isNotBound
 */
bool TSItem::IsNotBoundToPlayer(TSPlayer _player)
{
    auto player = _player.player;
    return item->IsBindedNotWith(player);
}
    
/**
 * Returns 'true' if the [Item] is locked, 'false' otherwise
 *
 * @return bool isLocked
 */
bool TSItem::IsLocked() 
{
    return item->IsLocked();
}
    
/**
 * Returns 'true' if the [Item] is a bag, 'false' otherwise
 *
 * @return bool isBag
 */
bool TSItem::IsBag() 
{
    return item->IsBag();
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Item] is a currency token, 'false' otherwise
 *
 * @return bool isCurrencyToken
 */
bool TSItem::IsCurrencyToken() 
{
    return item->IsCurrencyToken();
}
#endif
    
/**
 * Returns 'true' if the [Item] is a not an empty bag, 'false' otherwise
 *
 * @return bool isNotEmptyBag
 */
bool TSItem::IsNotEmptyBag() 
{
    return item->IsNotEmptyBag();
}
    
/**
 * Returns 'true' if the [Item] is broken, 'false' otherwise
 *
 * @return bool isBroken
 */
bool TSItem::IsBroken() 
{
    return item->IsBroken();
}
    
/**
 * Returns 'true' if the [Item] can be traded, 'false' otherwise
 *
 * @return bool isTradeable
 */
bool TSItem::CanBeTraded(bool mail) 
{
#if (defined(TBC) || defined(CLASSIC))
    return item->CanBeTraded();
#else
    return item->CanBeTraded(mail);
#endif
}
    
/**
 * Returns 'true' if the [Item] is currently in a trade window, 'false' otherwise
 *
 * @return bool isInTrade
 */
bool TSItem::IsInTrade() 
{
    return item->IsInTrade();
}
    
/**
 * Returns 'true' if the [Item] is currently in a bag, 'false' otherwise
 *
 * @return bool isInBag
 */
bool TSItem::IsInBag() 
{
    return item->IsInBag();
}
    
/**
 * Returns 'true' if the [Item] is currently equipped, 'false' otherwise
 *
 * @return bool isEquipped
 */
bool TSItem::IsEquipped() 
{
    return item->IsEquipped();
}
    
/**
 * Returns 'true' if the [Item] has the [Quest] specified tied to it, 'false' otherwise
 *
 * @param uint32 questId : the [Quest] id to be checked
 * @return bool hasQuest
 */
bool TSItem::HasQuest(uint32 quest) 
{
#if defined TRINITY || AZEROTHCORE
    return item->hasQuest(quest);
#else
    return item->HasQuest(quest);
#endif
}
    
/**
 * Returns 'true' if the [Item] is a potion, 'false' otherwise
 *
 * @return bool isPotion
 */
bool TSItem::IsPotion() 
{
    return item->IsPotion();
}
    
#if defined CLASSIC || defined(TBC) || defined(WOTLK)
/**
 * Returns 'true' if the [Item] is a weapon vellum, 'false' otherwise
 *
 * @return bool isWeaponVellum
 */
bool TSItem::IsWeaponVellum() 
{
    return item->IsWeaponVellum();
}
    
/**
 * Returns 'true' if the [Item] is an armor vellum, 'false' otherwise
 *
 * @return bool isArmorVellum
 */
bool TSItem::IsArmorVellum() 
{
    return item->IsArmorVellum();
}
#endif
    
/**
 * Returns 'true' if the [Item] is a conjured consumable, 'false' otherwise
 *
 * @return bool isConjuredConsumable
 */
bool TSItem::IsConjuredConsumable() 
{
    return item->IsConjuredConsumable();
}
    
/*int TSItem::IsRefundExpired(lua_State* L, Item* item)// TODO: Implement core support
{
    return item->IsRefundExpired();
}*/
    
/**
 * Returns the chat link of the [Item]
 *
 * <pre>
 * enum LocaleConstant
 * {
 *     LOCALE_enUS = 0,
 *     LOCALE_koKR = 1,
 *     LOCALE_frFR = 2,
 *     LOCALE_deDE = 3,
 *     LOCALE_zhCN = 4,
 *     LOCALE_zhTW = 5,
 *     LOCALE_esES = 6,
 *     LOCALE_esMX = 7,
 *     LOCALE_ruRU = 8
 * </pre>
 *
 * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the [Item]'s name in
 * @return string itemLink
 */
TSString TSItem::GetItemLink(uint8 locale)
{

    const ItemTemplate* temp = item->GetTemplate();
    std::string name = temp->Name1;
    if (ItemLocale const* il = eObjectMgr->GetItemLocale(temp->ItemId))
        ObjectMgr::GetLocaleString(il->Name, static_cast<LocaleConstant>(locale), name);

    if (int32 itemRandPropId = item->GetItemRandomPropertyId())
    {
        std::array<char const*, 16> const* suffix = NULL;
        if (itemRandPropId < 0)
        {
            const ItemRandomSuffixEntry* itemRandEntry = sItemRandomSuffixStore.LookupEntry(-item->GetItemRandomPropertyId());
            if (itemRandEntry) suffix = &itemRandEntry->Name;
        } 
        else
        {
            const ItemRandomPropertiesEntry* itemRandEntry = sItemRandomPropertiesStore.LookupEntry(item->GetItemRandomPropertyId());
            if (itemRandEntry) suffix = &itemRandEntry->Name;
        }

        if(suffix)
        {
            name += ' ';
            name += (*suffix)[(name != temp->Name1) ? locale : uint8(DEFAULT_LOCALE)];
        }
    }

    std::ostringstream oss;
    oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
        "|Hitem:" << temp->ItemId << ":" <<
        item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":" <<
        item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":" <<
        item->GetItemRandomPropertyId() << ":" << item->GetItemSuffixFactor() << ":" <<
        (uint32)item->GetOwner()->GetLevel() << "|h[" << name << "]|h|r";
    return TSString(oss.str());
}
    
uint64 TSItem::GetOwnerGUID() 
{
#if defined TRINITY || AZEROTHCORE
    return item->GetOwnerGUID();
#else
    return item->GetOwnerGuid();
#endif
}
    
/**
 * Returns the [Player] who currently owns the [Item]
 *
 * @return [Player] player : the [Player] who owns the [Item]
 */
TSPlayer  TSItem::GetOwner() 
{
     return TSPlayer(item->GetOwner());
}
    
/**
 * Returns the [Item]s stack count
 *
 * @return uint32 count
 */
uint32 TSItem::GetCount() 
{
    return item->GetCount();
}
    
/**
 * Returns the [Item]s max stack count
 *
 * @return uint32 maxCount
 */
uint32 TSItem::GetMaxStackCount() 
{
    return item->GetMaxStackCount();
}
    
/**
 * Returns the [Item]s current slot
 *
 * @return uint8 slot
 */
uint8 TSItem::GetSlot() 
{
    return item->GetSlot();
}
    
/**
 * Returns the [Item]s current bag slot
 *
 * @return uint8 bagSlot
 */
uint8 TSItem::GetBagSlot() 
{
    return item->GetBagSlot();
}
    
/**
 * Returns the [Item]s enchantment ID by enchant slot specified
 *
 * @param [EnchantmentSlot] enchantSlot : the enchant slot specified
 * @return uint32 enchantId : the id of the enchant slot specified
 */
uint32 TSItem::GetEnchantmentId(uint32 enchant_slot) 
{
    
    return item->GetEnchantmentId(EnchantmentSlot(enchant_slot));
}
    
/**
 * Returns the spell ID tied to the [Item] by spell index
 *
 * @param uint32 spellIndex : the spell index specified
 * @return uint32 spellId : the id of the spell
 */
uint32 TSItem::GetSpellId(uint32 index) 
{
    return item->GetTemplate()->Spells[index].SpellId;
}
    
/**
 * Returns the spell trigger tied to the [Item] by spell index
 *
 * @param uint32 spellIndex : the spell index specified
 * @return uint32 spellTrigger : the spell trigger of the specified index
 */
uint32 TSItem::GetSpellTrigger(uint32 index) 
{
    return item->GetTemplate()->Spells[index].SpellTrigger;
}
    
/**
 * Returns class of the [Item]
 *
 * @return uint32 class
 */
uint32 TSItem::GetClass() 
{
    return item->GetTemplate()->Class;
}
    
/**
 * Returns subclass of the [Item]
 *
 * @return uint32 subClass
 */
uint32 TSItem::GetSubClass() 
{
    return item->GetTemplate()->SubClass;
}
    
/**
 * Returns the name of the [Item]
 *
 * @return string name
 */
TSString TSItem::GetName()
{
     return TSString(item->GetTemplate()->Name1);
}
    
/**
 * Returns the display ID of the [Item]
 *
 * @return uint32 displayId
 */
uint32 TSItem::GetDisplayId() 
{
    return item->GetTemplate()->DisplayInfoID;
}
    
/**
 * Returns the quality of the [Item]
 *
 * @return uint32 quality
 */
uint32 TSItem::GetQuality() 
{
    return item->GetTemplate()->Quality;
}
    
/**
 * Returns the default purchase count of the [Item]
 *
 * @return uint32 count
 */
uint32 TSItem::GetBuyCount() 
{
    return item->GetTemplate()->BuyCount;
}
    
/**
 * Returns the purchase price of the [Item]
 *
 * @return uint32 price
 */
uint32 TSItem::GetBuyPrice() 
{
    return item->GetTemplate()->BuyPrice;
}
    
/**
 * Returns the sell price of the [Item]
 *
 * @return uint32 price
 */
uint32 TSItem::GetSellPrice() 
{
    return item->GetTemplate()->SellPrice;
}
    
/**
 * Returns the inventory type of the [Item]
 *
 * @return uint32 inventoryType
 */
uint32 TSItem::GetInventoryType() 
{
    return item->GetTemplate()->InventoryType;
}
    
/**
 * Returns the [Player] classes allowed to use this [Item]
 *
 * @return uint32 allowableClass
 */
uint32 TSItem::GetAllowableClass() 
{
    return item->GetTemplate()->AllowableClass;
}
    
/**
 * Returns the [Player] races allowed to use this [Item]
 *
 * @return uint32 allowableRace
 */
uint32 TSItem::GetAllowableRace() 
{
    return item->GetTemplate()->AllowableRace;
}
    
/**
 * Returns the [Item]s level
 *
 * @return uint32 itemLevel
 */
uint32 TSItem::GetItemLevel() 
{
    return item->GetTemplate()->ItemLevel;
}
    
/**
 * Returns the minimum level required to use this [Item]
 *
 * @return uint32 requiredLevel
 */
uint32 TSItem::GetRequiredLevel() 
{
    return item->GetTemplate()->RequiredLevel;
}
    
#ifdef WOTLK
uint32 TSItem::GetStatsCount() 
{
    return item->GetTemplate()->StatsCount;
}
#endif
    
/**
 * Returns the random property ID of this [Item]
 *
 * @return uint32 randomPropertyId
 */
uint32 TSItem::GetRandomProperty() 
{
    return item->GetTemplate()->RandomProperty;
}
    
#ifndef CLASSIC
int32 TSItem::GetRandomSuffix() 
{
    return item->GetTemplate()->RandomSuffix;
}
#endif
    
/**
 * Returns the item set ID of this [Item]
 *
 * @return uint32 itemSetId
 */
uint32 TSItem::GetItemSet() 
{
    return item->GetTemplate()->ItemSet;
}
    
/**
 * Returns the bag size of this [Item], 0 if [Item] is not a bag
 *
 * @return uint32 bagSize
 */
uint32 TSItem::GetBagSize() 
{
    if (Bag* bag = item->ToBag())
        return bag->GetBagSize();
    else
        return 0;
}
    
/**
 * Sets the [Player] specified as the owner of the [Item]
 *
 * @param [Player] player : the [Player] specified
 */
void TSItem::SetOwner(TSPlayer _player)
{
    auto player = _player.player;
#if defined TRINITY || AZEROTHCORE
    item->SetOwnerGUID(player->TS_GET_GUID());
#else
    item->SetOwnerGuid(player->TS_GET_GUID());
#endif
}
    
/**
 * Sets the binding of the [Item] to 'true' or 'false'
 *
 * @param bool setBinding
 */
void TSItem::SetBinding(bool soulbound) 
{
    
    item->SetBinding(soulbound);
    item->SetState(ITEM_CHANGED, item->GetOwner());
    
}
    
/**
 * Sets the stack count of the [Item]
 *
 * @param uint32 count
 */
void TSItem::SetCount(uint32 count) 
{
    item->SetCount(count);
}
    
/**
 * Sets the specified enchantment of the [Item] to the specified slot
 *
 * @param uint32 enchantId : the ID of the enchant to be applied
 * @param uint32 enchantSlot : the slot for the enchant to be applied to
 * @return bool enchantmentSuccess : if enchantment is successfully set to specified (EnchantmentSlot)slot, returns 'true', otherwise 'false'
 */
bool TSItem::SetEnchantment(uint32 enchant,uint32 slot) 
{
    Player* owner = item->GetOwner();
    if (!owner)
    {
        return false;
    }
    
    if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
    {
        return false;
    }
    
    
    owner->ApplyEnchantment(item, (EnchantmentSlot)slot, false);
    item->SetEnchantment((EnchantmentSlot)slot, enchant, 0, 0);
    owner->ApplyEnchantment(item, (EnchantmentSlot)slot, true);
    return true;
}
    
/* OTHER */
/**
 * Removes an enchant from the [Item] by the specified slot
 *
 * @param uint32 enchantSlot : the slot for the enchant to be removed from
 * @return bool enchantmentRemoved : if enchantment is successfully removed from specified (EnchantmentSlot)slot, returns 'true', otherwise 'false'
 */
bool TSItem::ClearEnchantment(uint32 slot) 
{
    Player* owner = item->GetOwner();
    if (!owner)
    {
        return false;
    }
    
    
    if (!item->GetEnchantmentId((EnchantmentSlot)slot))
    {
        return false;
    }
    
    owner->ApplyEnchantment(item, (EnchantmentSlot)slot, false);
    item->ClearEnchantment((EnchantmentSlot)slot);
    return true;
}
    
/**
 * Saves the [Item] to the database
 */
void TSItem::SaveToDB() 
{
#if defined TRINITY
    CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
    item->SaveToDB(trans);
#elif defined AZEROTHCORE
    SQLTransaction trans = SQLTransaction(NULL);
    item->SaveToDB(trans);
#else
    item->SaveToDB();
#endif
}

TSItem CreateItem(uint32 entry, uint32 count)
{
    return TSItem(Item::CreateItem(entry,count,nullptr));
}

TSItemTemplate TSItem::GetTemplate()
{
    return TSItemTemplate(item->GetTemplate());
}

// Inherited functions