/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

/***
 * Inherits all methods from: [Object]
 */
namespace LuaItem
{
    /**
     * Returns 'true' if the [Item] is soulbound, 'false' otherwise
     *
     * @return bool isSoulBound
     */
    int IsSoulBound(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsSoulBound());
        return 1;
    }

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Returns 'true' if the [Item] is account bound, 'false' otherwise
     *
     * @return bool isAccountBound
     */
    int IsBoundAccountWide(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBoundAccountWide());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Item] is bound to a [Player] by an enchant, 'false' otehrwise
     *
     * @return bool isBoundByEnchant
     */
    int IsBoundByEnchant(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBoundByEnchant());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is not bound to the [Player] specified, 'false' otherwise
     *
     * @param [Player] player : the [Player] object to check the item against
     * @return bool isNotBound
     */
    int IsNotBoundToPlayer(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        Eluna::Push(L, item->IsBindedNotWith(player));
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is locked, 'false' otherwise
     *
     * @return bool isLocked
     */
    int IsLocked(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsLocked());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a bag, 'false' otherwise
     *
     * @return bool isBag
     */
    int IsBag(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBag());
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Item] is a currency token, 'false' otherwise
     *
     * @return bool isCurrencyToken
     */
    int IsCurrencyToken(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsCurrencyToken());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Item] is a not an empty bag, 'false' otherwise
     *
     * @return bool isNotEmptyBag
     */
    int IsNotEmptyBag(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsNotEmptyBag());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is broken, 'false' otherwise
     *
     * @return bool isBroken
     */
    int IsBroken(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsBroken());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] can be traded, 'false' otherwise
     *
     * @return bool isTradeable
     */
    int CanBeTraded(Eluna* /*E*/, lua_State* L, Item* item)
    {
#if (defined(TBC) || defined(CLASSIC))
        Eluna::Push(L, item->CanBeTraded());
#else
        bool mail = Eluna::CHECKVAL<bool>(L, 2, false);
        Eluna::Push(L, item->CanBeTraded(mail));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently in a trade window, 'false' otherwise
     *
     * @return bool isInTrade
     */
    int IsInTrade(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsInTrade());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently in a bag, 'false' otherwise
     *
     * @return bool isInBag
     */
    int IsInBag(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsInBag());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is currently equipped, 'false' otherwise
     *
     * @return bool isEquipped
     */
    int IsEquipped(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsEquipped());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] has the [Quest] specified tied to it, 'false' otherwise
     *
     * @param uint32 questId : the [Quest] id to be checked
     * @return bool hasQuest
     */
    int HasQuest(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint32 quest = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef TRINITY
        Eluna::Push(L, item->HasQuest(quest));
#else
        Eluna::Push(L, item->hasQuest(quest));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is a potion, 'false' otherwise
     *
     * @return bool isPotion
     */
    int IsPotion(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsPotion());
        return 1;
    }

#ifndef CATA
    /**
     * Returns 'true' if the [Item] is a weapon vellum, 'false' otherwise
     *
     * @return bool isWeaponVellum
     */
    int IsWeaponVellum(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsWeaponVellum());
        return 1;
    }

    /**
     * Returns 'true' if the [Item] is an armor vellum, 'false' otherwise
     *
     * @return bool isArmorVellum
     */
    int IsArmorVellum(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsArmorVellum());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Item] is a conjured consumable, 'false' otherwise
     *
     * @return bool isConjuredConsumable
     */
    int IsConjuredConsumable(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->IsConjuredConsumable());
        return 1;
    }

    /*int IsRefundExpired(Eluna* E, lua_State* L, Item* item)// TODO: Implement core support
    {
        Eluna::Push(L, item->IsRefundExpired());
        return 1;
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
     * };
     * </pre>
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the [Item]'s name in
     * @return string itemLink
     */
    int GetItemLink(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint8 locale = Eluna::CHECKVAL<uint8>(L, 2, DEFAULT_LOCALE);
        if (locale >= TOTAL_LOCALES)
            return luaL_argerror(L, 2, "valid LocaleConstant expected");

        const ItemTemplate* temp = item->GetTemplate();
        std::string name = temp->Name1;
        if (ItemLocale const* il = eObjectMgr->GetItemLocale(temp->ItemId))
            ObjectMgr::GetLocaleString(il->Name, locale, name);

#ifndef CLASSIC
        if (int32 itemRandPropId = item->GetItemRandomPropertyId())
        {
#ifdef CATA
            char* suffix = NULL;
#else
            char* const* suffix = NULL;
#endif
            if (itemRandPropId < 0)
            {
                const ItemRandomSuffixEntry* itemRandEntry = sItemRandomSuffixStore.LookupEntry(-item->GetItemRandomPropertyId());
                if (itemRandEntry)
                    suffix = itemRandEntry->nameSuffix;
            }
            else
            {
                const ItemRandomPropertiesEntry* itemRandEntry = sItemRandomPropertiesStore.LookupEntry(item->GetItemRandomPropertyId());
                if (itemRandEntry)
                    suffix = itemRandEntry->nameSuffix;
            }
            if (suffix)
            {
                name += ' ';
                name += suffix[(name != temp->Name1) ? locale : uint8(DEFAULT_LOCALE)];
            }
        }
#endif

        std::ostringstream oss;
        oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
            "|Hitem:" << temp->ItemId << ":" <<
            item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":" <<
#ifndef CLASSIC
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":" <<
            item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":" <<
#endif
            item->GetItemRandomPropertyId() << ":" << item->GetItemSuffixFactor() << ":" <<
            (uint32)item->GetOwner()->getLevel() << "|h[" << name << "]|h|r";

        Eluna::Push(L, oss.str());
        return 1;
    }

    int GetOwnerGUID(Eluna* /*E*/, lua_State* L, Item* item)
    {
#ifndef TRINITY
        Eluna::Push(L, item->GetOwnerGuid());
#else
        Eluna::Push(L, item->GetOwnerGUID());
#endif
        return 1;
    }

    /**
     * Returns the [Player] who currently owns the [Item]
     *
     * @return [Player] player : the [Player] who owns the [Item]
     */
    int GetOwner(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetOwner());
        return 1;
    }

    /**
     * Returns the [Item]s stack count
     *
     * @return uint32 count
     */
    int GetCount(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetCount());
        return 1;
    }

    /**
     * Returns the [Item]s max stack count
     *
     * @return uint32 maxCount
     */
    int GetMaxStackCount(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetMaxStackCount());
        return 1;
    }

    /**
     * Returns the [Item]s current slot
     *
     * @return uint8 slot
     */
    int GetSlot(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetSlot());
        return 1;
    }

    /**
     * Returns the [Item]s current bag slot
     *
     * @return uint8 bagSlot
     */
    int GetBagSlot(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetBagSlot());
        return 1;
    }

    /**
     * Returns the [Item]s enchantment ID by enchant slot specified
     *
     * @param [EnchantmentSlot] enchantSlot : the enchant slot specified
     * @return uint32 enchantId : the id of the enchant slot specified
     */
    int GetEnchantmentId(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint32 enchant_slot = Eluna::CHECKVAL<uint32>(L, 2);

        if (enchant_slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        Eluna::Push(L, item->GetEnchantmentId(EnchantmentSlot(enchant_slot)));
        return 1;
    }

    /**
     * Returns the spell ID tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellId : the id of the spell
     */
    int GetSpellId(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint32 index = Eluna::CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

        Eluna::Push(L, item->GetTemplate()->Spells[index].SpellId);
        return 1;
    }

    /**
     * Returns the spell trigger tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellTrigger : the spell trigger of the specified index
     */
    int GetSpellTrigger(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint32 index = Eluna::CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

        Eluna::Push(L, item->GetTemplate()->Spells[index].SpellTrigger);
        return 1;
    }

    /**
     * Returns class of the [Item]
     *
     * @return uint32 class
     */
    int GetClass(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->Class);
        return 1;
    }

    /**
     * Returns subclass of the [Item]
     *
     * @return uint32 subClass
     */
    int GetSubClass(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->SubClass);
        return 1;
    }

    /**
     * Returns the name of the [Item]
     *
     * @return string name
     */
    int GetName(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->Name1);
        return 1;
    }

    /**
     * Returns the display ID of the [Item]
     *
     * @return uint32 displayId
     */
    int GetDisplayId(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->DisplayInfoID);
        return 1;
    }

    /**
     * Returns the quality of the [Item]
     *
     * @return uint32 quality
     */
    int GetQuality(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->Quality);
        return 1;
    }

    /**
     * Returns the default purchase count of the [Item]
     *
     * @return uint32 count
     */
    int GetBuyCount(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->BuyCount);
        return 1;
    }

    /**
     * Returns the purchase price of the [Item]
     *
     * @return uint32 price
     */
    int GetBuyPrice(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->BuyPrice);
        return 1;
    }

    /**
     * Returns the sell price of the [Item]
     *
     * @return uint32 price
     */
    int GetSellPrice(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->SellPrice);
        return 1;
    }

    /**
     * Returns the inventory type of the [Item]
     *
     * @return uint32 inventoryType
     */
    int GetInventoryType(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->InventoryType);
        return 1;
    }

    /**
     * Returns the [Player] classes allowed to use this [Item]
     *
     * @return uint32 allowableClass
     */
    int GetAllowableClass(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->AllowableClass);
        return 1;
    }

    /**
     * Returns the [Player] races allowed to use this [Item]
     *
     * @return uint32 allowableRace
     */
    int GetAllowableRace(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->AllowableRace);
        return 1;
    }

    /**
     * Returns the [Item]s level
     *
     * @return uint32 itemLevel
     */
    int GetItemLevel(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->ItemLevel);
        return 1;
    }

    /**
     * Returns the minimum level required to use this [Item]
     *
     * @return uint32 requiredLevel
     */
    int GetRequiredLevel(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->RequiredLevel);
        return 1;
    }

#ifdef WOTLK
    int GetStatsCount(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->StatsCount);
        return 1;
    }
#endif

    /**
     * Returns the random property ID of this [Item]
     *
     * @return uint32 randomPropertyId
     */
    int GetRandomProperty(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->RandomProperty);
        return 1;
    }

#ifndef CLASSIC
    int GetRandomSuffix(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->RandomSuffix);
        return 1;
    }
#endif

    /**
     * Returns the item set ID of this [Item]
     *
     * @return uint32 itemSetId
     */
    int GetItemSet(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Eluna::Push(L, item->GetTemplate()->ItemSet);
        return 1;
    }

    /**
     * Returns the bag size of this [Item], 0 if [Item] is not a bag
     *
     * @return uint32 bagSize
     */
    int GetBagSize(Eluna* /*E*/, lua_State* L, Item* item)
    {
        if (Bag* bag = item->ToBag())
            Eluna::Push(L, bag->GetBagSize());
        else
            Eluna::Push(L, 0);
        return 1;
    }

    /**
     * Sets the [Player] specified as the owner of the [Item]
     *
     * @param [Player] player : the [Player] specified
     */
    int SetOwner(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);
#ifndef TRINITY
        item->SetOwnerGuid(player->GET_GUID());
#else
        item->SetOwnerGUID(player->GET_GUID());
#endif
        return 0;
    }

    /**
     * Sets the binding of the [Item] to 'true' or 'false'
     *
     * @param bool setBinding
     */
    int SetBinding(Eluna* /*E*/, lua_State* L, Item* item)
    {
        bool soulbound = Eluna::CHECKVAL<bool>(L, 2);

        item->SetBinding(soulbound);
        return 0;
    }

    /**
     * Sets the stack count of the [Item]
     *
     * @param uint32 count
     */
    int SetCount(Eluna* /*E*/, lua_State* L, Item* item)
    {
        uint32 count = Eluna::CHECKVAL<uint32>(L, 2);
        item->SetCount(count);
        return 0;
    }

    /**
     * Sets the specified enchantment of the [Item] to the specified slot
     *
     * @param uint32 enchantId : the ID of the enchant to be applied
     * @param uint32 enchantSlot : the slot for the enchant to be applied to
     * @return bool enchantmentSuccess : if enchantment is successfully set to specified slot, returns 'true', otherwise 'false'
     */
    int SetEnchantment(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            Eluna::Push(L, false);
            return 1;
        }

        uint32 enchant = Eluna::CHECKVAL<uint32>(L, 2);
        if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
        {
            Eluna::Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = (EnchantmentSlot)Eluna::CHECKVAL<uint32>(L, 3);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        owner->ApplyEnchantment(item, slot, false);
        item->SetEnchantment(slot, enchant, 0, 0);
        owner->ApplyEnchantment(item, slot, true);
        Eluna::Push(L, true);
        return 1;
    }

    /* OTHER */
    /**
     * Removes an enchant from the [Item] by the specified slot
     *
     * @param uint32 enchantSlot : the slot for the enchant to be removed from
     * @return bool enchantmentRemoved : if enchantment is successfully removed from specified slot, returns 'true', otherwise 'false'
     */
    int ClearEnchantment(Eluna* /*E*/, lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            Eluna::Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = (EnchantmentSlot)Eluna::CHECKVAL<uint32>(L, 2);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

        if (!item->GetEnchantmentId(slot))
        {
            Eluna::Push(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->ClearEnchantment(slot);
        Eluna::Push(L, true);
        return 1;
    }

    /**
     * Saves the [Item] to the database
     */
    int SaveToDB(Eluna* /*E*/, lua_State* /*L*/, Item* item)
    {
#ifndef TRINITY
        item->SaveToDB();
#else
        SQLTransaction trans = SQLTransaction(NULL);
        item->SaveToDB(trans);
#endif
        return 0;
    }
};
#endif
