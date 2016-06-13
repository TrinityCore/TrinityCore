#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ItemUsageValue.h"

#include "../../GuildTaskMgr.h"
using namespace ai;

ItemUsage ItemUsageValue::Calculate()
{
    uint32 itemId = atoi(qualifier.c_str());
    if (!itemId)
        return ITEM_USAGE_NONE;

    const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itemId);
    if (!proto)
        return ITEM_USAGE_NONE;

    if (IsItemUsefulForSkill(proto))
        return ITEM_USAGE_SKILL;

    switch (proto->Class)
    {
    case ITEM_CLASS_KEY:
    case ITEM_CLASS_CONSUMABLE:
        return ITEM_USAGE_USE;
    }

    if (bot->GetGuildId() && sGuildTaskMgr.IsGuildTaskItem(itemId, bot->GetGuildId()))
        return ITEM_USAGE_GUILD_TASK;

    return QueryItemUsageForEquip(proto);
}

ItemUsage ItemUsageValue::QueryItemUsageForEquip(ItemTemplate const * item)
{
    if (bot->CanUseItem(item) != EQUIP_ERR_OK)
        return ITEM_USAGE_NONE;

    if (item->InventoryType == INVTYPE_NON_EQUIP)
        return ITEM_USAGE_NONE;

    Item *pItem = Item::CreateItem(item->ItemId, 1, bot);
    if (!pItem)
        return ITEM_USAGE_NONE;

    uint16 dest;
    InventoryResult result = bot->CanEquipItem(NULL_SLOT, dest, pItem, true, false);
    pItem->RemoveFromUpdateQueueOf(bot);
    delete pItem;

    if( result != EQUIP_ERR_OK )
        return ITEM_USAGE_NONE;

    Item* existingItem = bot->GetItemByPos(dest);
    if (!existingItem)
        return ITEM_USAGE_EQUIP;

    const ItemTemplate* oldItem = existingItem->GetTemplate();
    if (oldItem->ItemLevel < item->ItemLevel && oldItem->ItemId != item->ItemId)
    {
        switch (item->Class)
        {
        case ITEM_CLASS_ARMOR:
            if (oldItem->SubClass <= item->SubClass) {
                return ITEM_USAGE_REPLACE;
            }
            break;
        default:
            return ITEM_USAGE_EQUIP;
        }
    }

    return ITEM_USAGE_NONE;
}

bool ItemUsageValue::IsItemUsefulForSkill(ItemTemplate const * proto)
{
    switch (proto->Class)
    {
    case ITEM_CLASS_GEM:
        if (proto->SubClass == ITEM_SUBCLASS_GEM_SIMPLE && bot->HasSkill(SKILL_JEWELCRAFTING))
            return true;
        if (proto->SubClass != ITEM_SUBCLASS_GEM_SIMPLE)
            return true;
        break;
    case ITEM_CLASS_TRADE_GOODS:
        switch (proto->SubClass)
        {
        case ITEM_SUBCLASS_PARTS:
        case ITEM_SUBCLASS_EXPLOSIVES:
        case ITEM_SUBCLASS_DEVICES:
            return bot->HasSkill(SKILL_ENGINEERING);
        case ITEM_SUBCLASS_JEWELCRAFTING:
            return bot->HasSkill(SKILL_JEWELCRAFTING);
        case ITEM_SUBCLASS_CLOTH:
            return bot->HasSkill(SKILL_TAILORING);
        case ITEM_SUBCLASS_LEATHER:
            return bot->HasSkill(SKILL_LEATHERWORKING) || bot->HasSkill(SKILL_SKINNING);
        case ITEM_SUBCLASS_METAL_STONE:
            return (bot->HasSkill(SKILL_BLACKSMITHING) ||
                bot->HasSkill(SKILL_ENGINEERING) ||
                bot->HasSkill(SKILL_MINING));
        case ITEM_SUBCLASS_MEAT:
            return bot->HasSkill(SKILL_COOKING);
        case ITEM_SUBCLASS_HERB:
            return (bot->HasSkill(SKILL_HERBALISM) ||
                bot->HasSkill(SKILL_ALCHEMY) ||
                bot->HasSkill(SKILL_INSCRIPTION));
        case ITEM_SUBCLASS_ELEMENTAL:
            return true;
        case ITEM_SUBCLASS_ENCHANTING:
            return bot->HasSkill(SKILL_ENCHANTING);
        }
        break;
    case ITEM_CLASS_RECIPE:
        {
            if (bot->HasSpell(proto->Spells[2].SpellId))
                break;

            switch (proto->SubClass)
            {
            case ITEM_SUBCLASS_LEATHERWORKING_PATTERN:
                return bot->HasSkill(SKILL_LEATHERWORKING);
            case ITEM_SUBCLASS_TAILORING_PATTERN:
                return bot->HasSkill(SKILL_TAILORING);
            case ITEM_SUBCLASS_ENGINEERING_SCHEMATIC:
                return bot->HasSkill(SKILL_ENGINEERING);
            case ITEM_SUBCLASS_BLACKSMITHING:
                return bot->HasSkill(SKILL_BLACKSMITHING);
            case ITEM_SUBCLASS_COOKING_RECIPE:
                return bot->HasSkill(SKILL_COOKING);
            case ITEM_SUBCLASS_ALCHEMY_RECIPE:
                return bot->HasSkill(SKILL_ALCHEMY);
            case ITEM_SUBCLASS_FIRST_AID_MANUAL:
                return bot->HasSkill(SKILL_FIRST_AID);
            case ITEM_SUBCLASS_ENCHANTING_FORMULA:
                return bot->HasSkill(SKILL_ENCHANTING);
            case ITEM_SUBCLASS_FISHING_MANUAL:
                return bot->HasSkill(SKILL_FISHING);
            case ITEM_SUBCLASS_JEWELCRAFTING_RECIPE:
                return bot->HasSkill(SKILL_JEWELCRAFTING);
            }
        }
    }
    return false;
}
