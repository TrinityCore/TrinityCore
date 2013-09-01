#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

class LuaItem
{
public:
    static int GetItemLink(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        /*
        LOCALE_enUS = 0,
        LOCALE_koKR = 1,
        LOCALE_frFR = 2,
        LOCALE_deDE = 3,
        LOCALE_zhCN = 4,
        LOCALE_zhTW = 5,
        LOCALE_esES = 6,
        LOCALE_esMX = 7,
        LOCALE_ruRU = 8
        */
        int loc_idx = luaL_optint(L, 1, DEFAULT_LOCALE);
        if (loc_idx < 0 || loc_idx >= TOTAL_LOCALES)
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
            "|Hitem:" << temp->ItemId <<":" <<
            item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":" <<
            item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":" <<
            item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":" <<
            item->GetItemRandomPropertyId() << ":" << item->GetItemSuffixFactor() << ":" <<
            (uint32)item->GetOwner()->getLevel() << "|h[" << name << "]|h|r";

        sEluna->PushString(L, oss.str().c_str());
        return 1;
    }

    static int GetUnitType(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushString(L, "Item");
        return 1;
    }

    static int GetGUID(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushULong(L, item->GetGUID());
        return 1;
    }

    static int GetOwnerGUID(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushULong(L, item->GetOwnerGUID());
        return 1;
    }

    static int GetOwner(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnit(L, item->GetOwner());
        return 1;
    }

    static int SetOwner(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        Player* player = sEluna->CHECK_PLAYER(L, 1);

        if (player)
            item->SetOwnerGUID(player->GetGUID());
        return 0;
    }

    static int SetBinding(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        bool soulbound = luaL_checkbool(L, 1);

        item->SetBinding(soulbound);
        return 0;
    }

    static int IsSoulBound(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsSoulBound());
        return 1;
    }

    static int IsBoundAccountWide(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsBoundAccountWide());
        return 1;
    }

    static int IsBoundByEnchant(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsBoundByEnchant());
        return 1;
    }

    static int IsNotBoundToPlayer(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
        {
            Player* player = sEluna->CHECK_PLAYER(L, 1);
            if (player)
                sEluna->PushBoolean(L, item->IsBindedNotWith(player));
            else
                sEluna->PushBoolean(L, false);
        }
        return 1;
    }

    static int IsLocked(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsLocked());
        return 1;
    }

    static int IsBag(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsBag());
        return 1;
    }

    static int IsCurrencyToken(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsCurrencyToken());
        return 1;
    }

    static int IsNotEmptyBag(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsNotEmptyBag());
        return 1;
    }

    static int IsBroken(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsBroken());
        return 1;
    }

    static int CanBeTraded(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
        {
            bool mail = luaL_optbool(L, 1, false);
            bool trade = luaL_optbool(L, 2, false);
            sEluna->PushBoolean(L, item->CanBeTraded(mail, trade));
        }
        return 1;
    }

    static int IsInTrade(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsInTrade());
        return 1;
    }

    static int GetCount(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetCount());
        return 1;
    }

    static int SetCount(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint32 count = luaL_checkunsigned(L, 1);
        item->SetCount(count);
        return 0;
    }

    static int GetMaxStackCount(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetMaxStackCount());
        return 1;
    }

    static int GetSlot(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetSlot());
        return 1;
    }

    static int GetBagSlot(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetBagSlot());
        return 1;
    }

    static int IsInBag(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsInBag());
        return 1;
    }

    static int IsEquipped(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsEquipped());
        return 1;
    }

    static int hasQuest(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
        {
            uint32 quest = luaL_checkunsigned(L, 1);
            sEluna->PushBoolean(L, item->hasQuest(quest));
        }
        return 1;
    }

    static int IsPotion(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsPotion());
        return 1;
    }

    static int IsWeaponVellum(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsWeaponVellum());
        return 1;
    }

    static int IsArmorVellum(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsArmorVellum());
        return 1;
    }

    static int IsConjuredConsumable(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsConjuredConsumable());
        return 1;
    }

    static int IsRefundExpired(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, item->IsRefundExpired());
        return 1;
    }

    static int GetInt32Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushInteger(L, item->GetInt32Value(index));
        return 1;
    }

    static int GetUInt32Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushUnsigned(L, item->GetUInt32Value(index));
        return 1;
    }

    static int GetFloatValue(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushFloat(L, item->GetFloatValue(index));
        return 1;
    }

    static int GetByteValue(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, item->GetByteValue(index, offset));
        return 1;
    }

    static int GetUInt16Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, item->GetUInt16Value(index, offset));
        return 1;
    }

    static int SetInt32Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);
        item->SetInt32Value(index, value);
        return 0;
    }

    static int SetUInt32Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        item->SetUInt32Value(index, value);
        return 0;
    }

    static int UpdateUInt32Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        item->UpdateUInt32Value(index, value);
        return 0;
    }

    static int SetFloatValue(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);
        item->SetFloatValue(index, value);
        return 0;
    }

    static int SetByteValue(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);
        item->SetByteValue(index, offset, value);
        return 0;
    }

    static int SetUInt16Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);
        item->SetUInt16Value(index, offset, value);
        return 0;
    }

    static int SetInt16Value(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);
        item->SetInt16Value(index, offset, value);
        return 0;
    }

    static int SetEnchantment(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* owner = item->GetOwner();
        if (!owner)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        uint32 enchant = luaL_checkunsigned(L, 1);
        if (!sSpellItemEnchantmentStore.LookupEntry(enchant))
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 2));
        if(slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
        {
            luaL_error(L, "Invalid enchantment slot (%d)", slot);
            sEluna->PushBoolean(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->SetEnchantment(slot, enchant, 0, 0);
        owner->ApplyEnchantment(item, slot, true);
        sEluna->PushBoolean(L, true);
        return 1;
    }

    static int ClearEnchantment(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* owner = item->GetOwner();
        if (!owner)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 1));
        if(slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
        {
            luaL_error(L, "Invalid enchantment slot (%d)", slot);
            sEluna->PushBoolean(L, false);
            return 1;
        }

        if (!item->GetEnchantmentId(slot))
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        owner->ApplyEnchantment(item, slot, false);
        item->ClearEnchantment(slot);
        sEluna->PushBoolean(L, true);
        return 1;
    }

    static int GetGUIDLow(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetGUIDLow());
        return 1;
    }

    static int GetEnchantmentId(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint32 enchant_slot = luaL_checkunsigned(L, 1);

        EnchantmentSlot slot = EnchantmentSlot(luaL_checkunsigned(L, 2));
        if(slot >= MAX_INSPECTED_ENCHANTMENT_SLOT)
            sEluna->PushUnsigned(L, 0);
        else
            sEluna->PushUnsigned(L, item->GetEnchantmentId(EnchantmentSlot(enchant_slot)));
        return 1;
    }

    static int GetSpellId(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint32 index = luaL_checkunsigned(L, 1);
        if (index >= MAX_ITEM_PROTO_SPELLS)
        {
            luaL_error(L, "Invalid index (%d)", index);
            return 0;
        }

        sEluna->PushUnsigned(L, item->GetTemplate()->Spells[index].SpellId);
        return 1;
    }

    static int GetSpellTrigger(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        uint32 index = luaL_checkunsigned(L, 1);
        if (index >= MAX_ITEM_PROTO_SPELLS)
        {
            luaL_error(L, "Invalid index (%d)", index);
            return 0;
        }

        sEluna->PushUnsigned(L, item->GetTemplate()->Spells[index].SpellTrigger);
        return 1;
    }

    static int GetEntry(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetEntry());
        return 1;
    }

    static int GetClass(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->Class);
        return 1;
    }

    static int GetSubClass(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->SubClass);
        return 1;
    }

    static int GetName(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushString(L, item->GetTemplate()->Name1.c_str());
        return 1;
    }

    static int GetDisplayId(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->DisplayInfoID);
        return 1;
    }

    static int GetQuality(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->Quality);
        return 1;
    }

    static int GetBuyCount(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->BuyCount);
        return 1;
    }

    static int GetBuyPrice(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushInteger(L, item->GetTemplate()->BuyPrice);
        return 1;
    }

    static int GetSellPrice(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->SellPrice);
        return 1;
    }

    static int GetInventoryType(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->InventoryType);
        return 1;
    }

    static int GetAllowableClass(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->AllowableClass);
        return 1;
    }

    static int GetAllowableRace(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->AllowableRace);
        return 1;
    }

    static int GetItemLevel(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->ItemLevel);
        return 1;
    }

    static int GetRequiredLevel(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->RequiredLevel);
        return 1;
    }

    static int GetStatsCount(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->StatsCount);
        return 1;
    }

    static int GetRandomProperty(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushInteger(L, item->GetTemplate()->RandomProperty);
        return 1;
    }

    static int GetRandomSuffix(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushInteger(L, item->GetTemplate()->RandomSuffix);
        return 1;
    }

    static int GetItemSet(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        sEluna->PushUnsigned(L, item->GetTemplate()->ItemSet);
        return 1;
    }

    static int GetBagSize(lua_State* L, Item* item)
    {
        if (!item || !item->IsInWorld())
            return 0;

        if (Bag* bag = item->ToBag())
            sEluna->PushUnsigned(L, bag->GetBagSize());
        else
            sEluna->PushUnsigned(L, 0);
        return 1;
    }
};
#endif
