/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

namespace LuaItem
{
    int GetItemLink(lua_State* L, Item* item)
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

        int loc_idx = sEluna->CHECKVAL<int>(L, 2, DEFAULT_LOCALE);
        if (loc_idx < 0 || loc_idx >= MAX_LOCALES)
            return luaL_argerror(L, 2, "valid LocaleConstant expected");

        const ItemTemplate* temp = item->GetTemplate();
        std::string name = temp->Name1;
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(temp->ItemId))
            ObjectMgr::GetLocaleString(il->Name, loc_idx, name);

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
                //std::string test(suffix[(name != temp->Name1) ? loc_idx : DEFAULT_LOCALE]);
                //if (!test.empty())
                //{
                name += ' ';
                name += suffix[(name != temp->Name1) ? loc_idx : DEFAULT_LOCALE];
                /*}*/
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
#ifdef MANGOS
        sEluna->Push(L, item->GetOwnerGuid());
#else
        sEluna->Push(L, item->GetOwnerGUID());
#endif
        return 1;
    }

    int GetOwner(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetOwner());
        return 1;
    }

    int SetOwner(lua_State* L, Item* item)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
#ifdef MANGOS
        item->SetOwnerGuid(player->GET_GUID());
#else
        item->SetOwnerGUID(player->GET_GUID());
#endif
        return 0;
    }

    int SetBinding(lua_State* L, Item* item)
    {
        bool soulbound = sEluna->CHECKVAL<bool>(L, 2);

        item->SetBinding(soulbound);
        return 0;
    }

    int IsSoulBound(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsSoulBound());
        return 1;
    }

#ifndef TBC
    int IsBoundAccountWide(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBoundAccountWide());
        return 1;
    }
#endif

    int IsBoundByEnchant(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsBoundByEnchant());
        return 1;
    }

    int IsNotBoundToPlayer(lua_State* L, Item* item)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);

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
#ifdef TBC
        sEluna->Push(L, item->CanBeTraded());
#else
        bool mail = sEluna->CHECKVAL<bool>(L, 2, false);
        sEluna->Push(L, item->CanBeTraded(mail));
#endif
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
        uint32 count = sEluna->CHECKVAL<uint32>(L, 2);
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
        uint32 quest = sEluna->CHECKVAL<uint32>(L, 2);
#ifdef MANGOS
        sEluna->Push(L, item->HasQuest(quest));
#else
        sEluna->Push(L, item->hasQuest(quest));
#endif
        return 1;
    }

    int IsPotion(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsPotion());
        return 1;
    }

#ifndef CATA
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
#endif

    int IsConjuredConsumable(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->IsConjuredConsumable());
        return 1;
    }

    int IsRefundExpired(lua_State* L, Item* item)// TODO: Implement core support
    {
        /*sEluna->Push(L, item->IsRefundExpired());
        return 1;*/
        return 0; // Temp till supported
    }

    int SetEnchantment(lua_State* L, Item* item)
    {
        Player* owner = item->GetOwner();
        if (!owner)
        {
            sEluna->Push(L, false);
            return 1;
        }

        uint32 enchant = sEluna->CHECKVAL<uint32>(L, 2);
        if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
        {
            sEluna->Push(L, false);
            return 1;
        }

        EnchantmentSlot slot = (EnchantmentSlot)sEluna->CHECKVAL<uint32>(L, 3);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

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

        EnchantmentSlot slot = (EnchantmentSlot)sEluna->CHECKVAL<uint32>(L, 2);
        if (slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return luaL_argerror(L, 2, "valid EnchantmentSlot expected");

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
        uint32 enchant_slot = sEluna->CHECKVAL<uint32>(L, 2);

        if (enchant_slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            return 0;

        sEluna->Push(L, item->GetEnchantmentId(EnchantmentSlot(enchant_slot)));
        return 1;
    }

    int GetSpellId(lua_State* L, Item* item)
    {
        uint32 index = sEluna->CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

        sEluna->Push(L, item->GetTemplate()->Spells[index].SpellId);
        return 1;
    }

    int GetSpellTrigger(lua_State* L, Item* item)
    {
        uint32 index = sEluna->CHECKVAL<uint32>(L, 2);
        if (index >= MAX_ITEM_PROTO_SPELLS)
            return luaL_argerror(L, 2, "valid SpellIndex expected");

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

#ifdef WOTLK
    int GetStatsCount(lua_State* L, Item* item)
    {
        sEluna->Push(L, item->GetTemplate()->StatsCount);
        return 1;
    }
#endif

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
#ifdef MANGOS
        item->SaveToDB();
#else
        SQLTransaction trans = SQLTransaction(NULL);
        item->SaveToDB(trans);
#endif
        return 0;
    }
};
#endif
