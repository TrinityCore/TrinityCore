/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

namespace LuaItem
{
    int GetItemLink(lua_State* L, Item* item) // TODO: Implement
    {
        // LOCALE_enUS = 0,
        // LOCALE_koKR = 1,
        // LOCALE_frFR = 2,
        // LOCALE_deDE = 3,
        // LOCALE_zhCN = 4,
        // LOCALE_zhTW = 5,
        // LOCALE_esES = 6,
        // LOCALE_esMX = 7,
        // LOCALE_ruRU = 8

        int loc_idx = luaL_optint(L, 1, DEFAULT_LOCALE);
        if (loc_idx < 0 || loc_idx >= MAX_LOCALES)
        {
            luaL_error(L, "Invalid locale index (%d)", loc_idx);
            return 0;
        }

        const ItemTemplate* temp = item->GetTemplate();
        std::string name = temp->Name1;
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(temp->ItemId))
            ObjectMgr::GetLocaleString(il->Name, loc_idx, name);

        if (int32 itemRandPropId = item->GetItemRandomPropertyId())
        {
            char* const* suffix = NULL;
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
                std::string test(suffix[(name != temp->Name1) ? loc_idx : DEFAULT_LOCALE]);
                if (!test.empty())
                {
                    name += ' ';
                    name += test;
                }
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
            (uint32)item->GetOwner()->getLevel() << "|h[" << name << "]|h|r";

        sEluna->Push(L, oss.str());
        return 1;
    }

    int GetGUID(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetGUIDLow());
        return 1;
    }

    int GetOwnerGUID(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetOwnerGUID());
        return 1;
    }

    int GetOwner(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetOwner());
        return 1;
    }

    int SetOwner(lua_State* L, Item* item)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);

        if (player)
            item->SetOwnerGUID(player->GetGUID());
        return 0;
    }

    int SetBinding(lua_State* L, Item* item)
    {
        bool soulbound = luaL_checkbool(L, 1);

        item->SetBinding(soulbound);
        return 0;
    }

    int IsSoulBound(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsSoulBound());
        return 1;
    }

    int IsBoundAccountWide(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBoundAccountWide());
        return 1;
    }

    int IsBoundByEnchant(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBoundByEnchant());
        return 1;
    }

    int IsNotBoundToPlayer(lua_State* L, Item* item)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        sEluna->Push(L, item->IsBindedNotWith(player));
        return 1;
    }

    int IsLocked(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsLocked());
        return 1;
    }

    int IsBag(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBag());
        return 1;
    }

    int IsCurrencyToken(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsCurrencyToken());
        return 1;
    }

    int IsNotEmptyBag(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsNotEmptyBag());
        return 1;
    }

    int IsBroken(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBroken());
        return 1;
    }

    int CanBeTraded(lua_State* L, Item* item)
    {
        bool mail = luaL_optbool(L, 1, false);
        sEluna->Push(L, item->CanBeTraded(mail));
        return 1;
    }

    int IsInTrade(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsInTrade());
        return 1;
    }

    int GetCount(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetCount());
        return 1;
    }

    int SetCount(lua_State* L, Item* item)
    {
        uint32 count = luaL_checkunsigned(L, 1);
        item->SetCount(count);
        return 0;
    }

    int GetMaxStackCount(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetMaxStackCount());
        return 1;
    }

    int GetSlot(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetSlot());
        return 1;
    }

    int GetBagSlot(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetBagSlot());
        return 1;
    }

    int IsInBag(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsInBag());
        return 1;
    }

    int IsEquipped(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsEquipped());
        return 1;
    }

    int HasQuest(lua_State* L, Item* item)
    {
        uint32 quest = luaL_checkunsigned(L, 1);
        sEluna->Push(L, item->hasQuest(quest));
        return 1;
    }

    int IsPotion(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsPotion());
        return 1;
    }

    int IsWeaponVellum(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsWeaponVellum());
        return 1;
    }

    int IsArmorVellum(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsArmorVellum());
        return 1;
    }

    int IsConjuredConsumable(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsConjuredConsumable());
        return 1;
    }

    int IsRefundExpired(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsRefundExpired());
        return 1;
    }

    int SetEnchantment(lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            sEluna->Push(L, false);
            return 1;
        }

        uint32 enchant = luaL_checkunsigned(L, 1);
        if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
        {
            sEluna->Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 2));
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
        {
            luaL_error(L, "Invalid enchantment slot (%d)", slot);
            sEluna->Push(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->SetEnchantment(slot, enchant, 0, 0);
        owner->ApplyEnchantment(item, slot, true);
        sEluna->Push(L, true);
        return 1;
    }

    int ClearEnchantment(lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            sEluna->Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 1));
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
        {
            luaL_error(L, "Invalid enchantment slot (%d)", slot);
            sEluna->Push(L, false);
            return 1;
        }

        if (!item->GetEnchantmentId(slot))
        {
            sEluna->Push(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->ClearEnchantment(slot);
        sEluna->Push(L, true);
        return 1;
    }

    int GetGUIDLow(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetGUIDLow());
        return 1;
    }

    int GetEnchantmentId(lua_State* L, Item* item)
    {
        uint32 enchant_slot = luaL_checkunsigned(L, 1);

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 2));
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            sEluna->Push(L, 0);
        else
            sEluna->Push(L, item->GetEnchantmentId(EnchantmentSlot(enchant_slot)));
        return 1;
    }

    int GetSpellId(lua_State* L, Item* item)
    {
        uint32 index = luaL_checkunsigned(L, 1);
        if (index >= MAX_ITEM_PROTO_SPELLS)
        {
            luaL_error(L, "Invalid index (%d)", index);
            return 0;
        }

        sEluna->Push(L, item->GetTemplate()->Spells[index].SpellId);
        return 1;
    }

    int GetSpellTrigger(lua_State* L, Item* item)
    {
        uint32 index = luaL_checkunsigned(L, 1);
        if (index >= MAX_ITEM_PROTO_SPELLS)
        {
            luaL_error(L, "Invalid index (%d)", index);
            return 0;
        }

        sEluna->Push(L, item->GetTemplate()->Spells[index].SpellTrigger);
        return 1;
    }

    int GetClass(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->Class);
        return 1;
    }

    int GetSubClass(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->SubClass);
        return 1;
    }

    int GetName(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->Name1);
        return 1;
    }

    int GetDisplayId(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->DisplayInfoID);
        return 1;
    }

    int GetQuality(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->Quality);
        return 1;
    }

    int GetBuyCount(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->BuyCount);
        return 1;
    }

    int GetBuyPrice(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->BuyPrice);
        return 1;
    }

    int GetSellPrice(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->SellPrice);
        return 1;
    }

    int GetInventoryType(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->InventoryType);
        return 1;
    }

    int GetAllowableClass(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->AllowableClass);
        return 1;
    }

    int GetAllowableRace(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->AllowableRace);
        return 1;
    }

    int GetItemLevel(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->ItemLevel);
        return 1;
    }

    int GetRequiredLevel(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->RequiredLevel);
        return 1;
    }

    int GetStatsCount(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->StatsCount);
        return 1;
    }

    int GetRandomProperty(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->RandomProperty);
        return 1;
    }

    int GetRandomSuffix(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->RandomSuffix);
        return 1;
    }

    int GetItemSet(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->ItemSet);
        return 1;
    }

    int GetBagSize(lua_State* L, Item* item)
    {
        if (Bag* bag = item->ToBag())
            sEluna->Push(L, bag->GetBagSize());
        else
            sEluna->Push(L, 0);
        return 1;
    }

    int SaveToDB(lua_State* L, Item* item)
    {
        SQLTransaction trans = SQLTransaction(NULL);
        item->SaveToDB(trans);
        return 0;
    }
};
#endif
