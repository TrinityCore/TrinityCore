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

#include "ItemDefines.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/*********************************************************************\
|* data for enum 'InventoryResult' in 'ItemDefines.h' auto-generated *|
\*********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<InventoryResult>::ToString(InventoryResult value)
{
    switch (value)
    {
        case EQUIP_ERR_OK: return { "EQUIP_ERR_OK", "EQUIP_ERR_OK", "" };
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I: return { "EQUIP_ERR_CANT_EQUIP_LEVEL_I", "EQUIP_ERR_CANT_EQUIP_LEVEL_I", "" };
        case EQUIP_ERR_CANT_EQUIP_SKILL: return { "EQUIP_ERR_CANT_EQUIP_SKILL", "EQUIP_ERR_CANT_EQUIP_SKILL", "" };
        case EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT: return { "EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT", "EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT", "" };
        case EQUIP_ERR_BAG_FULL: return { "EQUIP_ERR_BAG_FULL", "EQUIP_ERR_BAG_FULL", "" };
        case EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG: return { "EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG", "EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG", "" };
        case EQUIP_ERR_CANT_TRADE_EQUIP_BAGS: return { "EQUIP_ERR_CANT_TRADE_EQUIP_BAGS", "EQUIP_ERR_CANT_TRADE_EQUIP_BAGS", "" };
        case EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE: return { "EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE", "EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE", "" };
        case EQUIP_ERR_NO_REQUIRED_PROFICIENCY: return { "EQUIP_ERR_NO_REQUIRED_PROFICIENCY", "EQUIP_ERR_NO_REQUIRED_PROFICIENCY", "" };
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE: return { "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE", "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE", "" };
        case EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM: return { "EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM", "EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM", "" };
        case EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2: return { "EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2", "EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2", "" };
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2: return { "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2", "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2", "" };
        case EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED: return { "EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED", "EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED", "" };
        case EQUIP_ERR_CANT_DUAL_WIELD: return { "EQUIP_ERR_CANT_DUAL_WIELD", "EQUIP_ERR_CANT_DUAL_WIELD", "" };
        case EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG: return { "EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG", "EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG", "" };
        case EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2: return { "EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2", "EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2", "" };
        case EQUIP_ERR_CANT_CARRY_MORE_OF_THIS: return { "EQUIP_ERR_CANT_CARRY_MORE_OF_THIS", "EQUIP_ERR_CANT_CARRY_MORE_OF_THIS", "" };
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3: return { "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3", "EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3", "" };
        case EQUIP_ERR_ITEM_CANT_STACK: return { "EQUIP_ERR_ITEM_CANT_STACK", "EQUIP_ERR_ITEM_CANT_STACK", "" };
        case EQUIP_ERR_ITEM_CANT_BE_EQUIPPED: return { "EQUIP_ERR_ITEM_CANT_BE_EQUIPPED", "EQUIP_ERR_ITEM_CANT_BE_EQUIPPED", "" };
        case EQUIP_ERR_ITEMS_CANT_BE_SWAPPED: return { "EQUIP_ERR_ITEMS_CANT_BE_SWAPPED", "EQUIP_ERR_ITEMS_CANT_BE_SWAPPED", "" };
        case EQUIP_ERR_SLOT_IS_EMPTY: return { "EQUIP_ERR_SLOT_IS_EMPTY", "EQUIP_ERR_SLOT_IS_EMPTY", "" };
        case EQUIP_ERR_ITEM_NOT_FOUND: return { "EQUIP_ERR_ITEM_NOT_FOUND", "EQUIP_ERR_ITEM_NOT_FOUND", "" };
        case EQUIP_ERR_CANT_DROP_SOULBOUND: return { "EQUIP_ERR_CANT_DROP_SOULBOUND", "EQUIP_ERR_CANT_DROP_SOULBOUND", "" };
        case EQUIP_ERR_OUT_OF_RANGE: return { "EQUIP_ERR_OUT_OF_RANGE", "EQUIP_ERR_OUT_OF_RANGE", "" };
        case EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT: return { "EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT", "EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT", "" };
        case EQUIP_ERR_COULDNT_SPLIT_ITEMS: return { "EQUIP_ERR_COULDNT_SPLIT_ITEMS", "EQUIP_ERR_COULDNT_SPLIT_ITEMS", "" };
        case EQUIP_ERR_MISSING_REAGENT: return { "EQUIP_ERR_MISSING_REAGENT", "EQUIP_ERR_MISSING_REAGENT", "" };
        case EQUIP_ERR_NOT_ENOUGH_MONEY: return { "EQUIP_ERR_NOT_ENOUGH_MONEY", "EQUIP_ERR_NOT_ENOUGH_MONEY", "" };
        case EQUIP_ERR_NOT_A_BAG: return { "EQUIP_ERR_NOT_A_BAG", "EQUIP_ERR_NOT_A_BAG", "" };
        case EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS: return { "EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS", "EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS", "" };
        case EQUIP_ERR_DONT_OWN_THAT_ITEM: return { "EQUIP_ERR_DONT_OWN_THAT_ITEM", "EQUIP_ERR_DONT_OWN_THAT_ITEM", "" };
        case EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER: return { "EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER", "EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER", "" };
        case EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT: return { "EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT", "EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT", "" };
        case EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK: return { "EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK", "EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK", "" };
        case EQUIP_ERR_ITEM_LOCKED: return { "EQUIP_ERR_ITEM_LOCKED", "EQUIP_ERR_ITEM_LOCKED", "" };
        case EQUIP_ERR_YOU_ARE_STUNNED: return { "EQUIP_ERR_YOU_ARE_STUNNED", "EQUIP_ERR_YOU_ARE_STUNNED", "" };
        case EQUIP_ERR_YOU_ARE_DEAD: return { "EQUIP_ERR_YOU_ARE_DEAD", "EQUIP_ERR_YOU_ARE_DEAD", "" };
        case EQUIP_ERR_CANT_DO_RIGHT_NOW: return { "EQUIP_ERR_CANT_DO_RIGHT_NOW", "EQUIP_ERR_CANT_DO_RIGHT_NOW", "" };
        case EQUIP_ERR_INT_BAG_ERROR: return { "EQUIP_ERR_INT_BAG_ERROR", "EQUIP_ERR_INT_BAG_ERROR", "" };
        case EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT: return { "EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT", "EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT", "" };
        case EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH: return { "EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH", "EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH", "" };
        case EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED: return { "EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED", "EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED: return { "EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED", "EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED: return { "EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED", "EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_BOUND_CANT_BE_WRAPPED: return { "EQUIP_ERR_BOUND_CANT_BE_WRAPPED", "EQUIP_ERR_BOUND_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED: return { "EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED", "EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_BAGS_CANT_BE_WRAPPED: return { "EQUIP_ERR_BAGS_CANT_BE_WRAPPED", "EQUIP_ERR_BAGS_CANT_BE_WRAPPED", "" };
        case EQUIP_ERR_ALREADY_LOOTED: return { "EQUIP_ERR_ALREADY_LOOTED", "EQUIP_ERR_ALREADY_LOOTED", "" };
        case EQUIP_ERR_INVENTORY_FULL: return { "EQUIP_ERR_INVENTORY_FULL", "EQUIP_ERR_INVENTORY_FULL", "" };
        case EQUIP_ERR_BANK_FULL: return { "EQUIP_ERR_BANK_FULL", "EQUIP_ERR_BANK_FULL", "" };
        case EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT: return { "EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT", "EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT", "" };
        case EQUIP_ERR_BAG_FULL3: return { "EQUIP_ERR_BAG_FULL3", "EQUIP_ERR_BAG_FULL3", "" };
        case EQUIP_ERR_ITEM_NOT_FOUND2: return { "EQUIP_ERR_ITEM_NOT_FOUND2", "EQUIP_ERR_ITEM_NOT_FOUND2", "" };
        case EQUIP_ERR_ITEM_CANT_STACK2: return { "EQUIP_ERR_ITEM_CANT_STACK2", "EQUIP_ERR_ITEM_CANT_STACK2", "" };
        case EQUIP_ERR_BAG_FULL4: return { "EQUIP_ERR_BAG_FULL4", "EQUIP_ERR_BAG_FULL4", "" };
        case EQUIP_ERR_ITEM_SOLD_OUT: return { "EQUIP_ERR_ITEM_SOLD_OUT", "EQUIP_ERR_ITEM_SOLD_OUT", "" };
        case EQUIP_ERR_OBJECT_IS_BUSY: return { "EQUIP_ERR_OBJECT_IS_BUSY", "EQUIP_ERR_OBJECT_IS_BUSY", "" };
        case EQUIP_ERR_NONE: return { "EQUIP_ERR_NONE", "EQUIP_ERR_NONE", "" };
        case EQUIP_ERR_NOT_IN_COMBAT: return { "EQUIP_ERR_NOT_IN_COMBAT", "EQUIP_ERR_NOT_IN_COMBAT", "" };
        case EQUIP_ERR_NOT_WHILE_DISARMED: return { "EQUIP_ERR_NOT_WHILE_DISARMED", "EQUIP_ERR_NOT_WHILE_DISARMED", "" };
        case EQUIP_ERR_BAG_FULL6: return { "EQUIP_ERR_BAG_FULL6", "EQUIP_ERR_BAG_FULL6", "" };
        case EQUIP_ERR_CANT_EQUIP_RANK: return { "EQUIP_ERR_CANT_EQUIP_RANK", "EQUIP_ERR_CANT_EQUIP_RANK", "" };
        case EQUIP_ERR_CANT_EQUIP_REPUTATION: return { "EQUIP_ERR_CANT_EQUIP_REPUTATION", "EQUIP_ERR_CANT_EQUIP_REPUTATION", "" };
        case EQUIP_ERR_TOO_MANY_SPECIAL_BAGS: return { "EQUIP_ERR_TOO_MANY_SPECIAL_BAGS", "EQUIP_ERR_TOO_MANY_SPECIAL_BAGS", "" };
        case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW: return { "EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW", "EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW", "" };
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE: return { "EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE", "EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE", "" };
        case EQUIP_ERR_VENDOR_MISSING_TURNINS: return { "EQUIP_ERR_VENDOR_MISSING_TURNINS", "EQUIP_ERR_VENDOR_MISSING_TURNINS", "" };
        case EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS: return { "EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS", "EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS", "" };
        case EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS: return { "EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS", "EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS", "" };
        case EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED: return { "EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED", "EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED", "" };
        case EQUIP_ERR_MAIL_BOUND_ITEM: return { "EQUIP_ERR_MAIL_BOUND_ITEM", "EQUIP_ERR_MAIL_BOUND_ITEM", "" };
        case EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING: return { "EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING", "EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING", "" };
        case EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED: return { "EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED", "EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED", "" };
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED: return { "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED", "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED", "" };
        case EQUIP_ERR_TOO_MUCH_GOLD: return { "EQUIP_ERR_TOO_MUCH_GOLD", "EQUIP_ERR_TOO_MUCH_GOLD", "" };
        case EQUIP_ERR_NOT_DURING_ARENA_MATCH: return { "EQUIP_ERR_NOT_DURING_ARENA_MATCH", "EQUIP_ERR_NOT_DURING_ARENA_MATCH", "" };
        case EQUIP_ERR_CANNOT_TRADE_THAT: return { "EQUIP_ERR_CANNOT_TRADE_THAT", "EQUIP_ERR_CANNOT_TRADE_THAT", "" };
        case EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW: return { "EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW", "EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW", "" };
        case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM: return { "EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM", "EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM", "" };
        case EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS: return { "EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS", "EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS", "" };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED", "" };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED", "" };
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED: return { "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED", "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED", "" };
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW: return { "EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW", "EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW", "" };
        case EQUIP_ERR_CANT_EQUIP_NEED_TALENT: return { "EQUIP_ERR_CANT_EQUIP_NEED_TALENT", "EQUIP_ERR_CANT_EQUIP_NEED_TALENT", "" };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<InventoryResult>::Count() { return 88; }

template <>
TC_API_EXPORT InventoryResult EnumUtils<InventoryResult>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return EQUIP_ERR_OK;
        case 1: return EQUIP_ERR_CANT_EQUIP_LEVEL_I;
        case 2: return EQUIP_ERR_CANT_EQUIP_SKILL;
        case 3: return EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT;
        case 4: return EQUIP_ERR_BAG_FULL;
        case 5: return EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG;
        case 6: return EQUIP_ERR_CANT_TRADE_EQUIP_BAGS;
        case 7: return EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE;
        case 8: return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
        case 9: return EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE;
        case 10: return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;
        case 11: return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2;
        case 12: return EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2;
        case 13: return EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED;
        case 14: return EQUIP_ERR_CANT_DUAL_WIELD;
        case 15: return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;
        case 16: return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2;
        case 17: return EQUIP_ERR_CANT_CARRY_MORE_OF_THIS;
        case 18: return EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3;
        case 19: return EQUIP_ERR_ITEM_CANT_STACK;
        case 20: return EQUIP_ERR_ITEM_CANT_BE_EQUIPPED;
        case 21: return EQUIP_ERR_ITEMS_CANT_BE_SWAPPED;
        case 22: return EQUIP_ERR_SLOT_IS_EMPTY;
        case 23: return EQUIP_ERR_ITEM_NOT_FOUND;
        case 24: return EQUIP_ERR_CANT_DROP_SOULBOUND;
        case 25: return EQUIP_ERR_OUT_OF_RANGE;
        case 26: return EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT;
        case 27: return EQUIP_ERR_COULDNT_SPLIT_ITEMS;
        case 28: return EQUIP_ERR_MISSING_REAGENT;
        case 29: return EQUIP_ERR_NOT_ENOUGH_MONEY;
        case 30: return EQUIP_ERR_NOT_A_BAG;
        case 31: return EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS;
        case 32: return EQUIP_ERR_DONT_OWN_THAT_ITEM;
        case 33: return EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER;
        case 34: return EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT;
        case 35: return EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK;
        case 36: return EQUIP_ERR_ITEM_LOCKED;
        case 37: return EQUIP_ERR_YOU_ARE_STUNNED;
        case 38: return EQUIP_ERR_YOU_ARE_DEAD;
        case 39: return EQUIP_ERR_CANT_DO_RIGHT_NOW;
        case 40: return EQUIP_ERR_INT_BAG_ERROR;
        case 41: return EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT;
        case 42: return EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH;
        case 43: return EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED;
        case 44: return EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED;
        case 45: return EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED;
        case 46: return EQUIP_ERR_BOUND_CANT_BE_WRAPPED;
        case 47: return EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED;
        case 48: return EQUIP_ERR_BAGS_CANT_BE_WRAPPED;
        case 49: return EQUIP_ERR_ALREADY_LOOTED;
        case 50: return EQUIP_ERR_INVENTORY_FULL;
        case 51: return EQUIP_ERR_BANK_FULL;
        case 52: return EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT;
        case 53: return EQUIP_ERR_BAG_FULL3;
        case 54: return EQUIP_ERR_ITEM_NOT_FOUND2;
        case 55: return EQUIP_ERR_ITEM_CANT_STACK2;
        case 56: return EQUIP_ERR_BAG_FULL4;
        case 57: return EQUIP_ERR_ITEM_SOLD_OUT;
        case 58: return EQUIP_ERR_OBJECT_IS_BUSY;
        case 59: return EQUIP_ERR_NONE;
        case 60: return EQUIP_ERR_NOT_IN_COMBAT;
        case 61: return EQUIP_ERR_NOT_WHILE_DISARMED;
        case 62: return EQUIP_ERR_BAG_FULL6;
        case 63: return EQUIP_ERR_CANT_EQUIP_RANK;
        case 64: return EQUIP_ERR_CANT_EQUIP_REPUTATION;
        case 65: return EQUIP_ERR_TOO_MANY_SPECIAL_BAGS;
        case 66: return EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW;
        case 67: return EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE;
        case 68: return EQUIP_ERR_VENDOR_MISSING_TURNINS;
        case 69: return EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS;
        case 70: return EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS;
        case 71: return EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED;
        case 72: return EQUIP_ERR_MAIL_BOUND_ITEM;
        case 73: return EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING;
        case 74: return EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED;
        case 75: return EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED;
        case 76: return EQUIP_ERR_TOO_MUCH_GOLD;
        case 77: return EQUIP_ERR_NOT_DURING_ARENA_MATCH;
        case 78: return EQUIP_ERR_CANNOT_TRADE_THAT;
        case 79: return EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW;
        case 80: return EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM;
        case 81: return EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS;
        case 82: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED;
        case 83: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED;
        case 84: return EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED;
        case 85: return EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW;
        case 86: return EQUIP_ERR_CANT_EQUIP_NEED_TALENT;
        case 87: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<InventoryResult>::ToIndex(InventoryResult value)
{
    switch (value)
    {
        case EQUIP_ERR_OK: return 0;
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I: return 1;
        case EQUIP_ERR_CANT_EQUIP_SKILL: return 2;
        case EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT: return 3;
        case EQUIP_ERR_BAG_FULL: return 4;
        case EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG: return 5;
        case EQUIP_ERR_CANT_TRADE_EQUIP_BAGS: return 6;
        case EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE: return 7;
        case EQUIP_ERR_NO_REQUIRED_PROFICIENCY: return 8;
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE: return 9;
        case EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM: return 10;
        case EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2: return 11;
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2: return 12;
        case EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED: return 13;
        case EQUIP_ERR_CANT_DUAL_WIELD: return 14;
        case EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG: return 15;
        case EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2: return 16;
        case EQUIP_ERR_CANT_CARRY_MORE_OF_THIS: return 17;
        case EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3: return 18;
        case EQUIP_ERR_ITEM_CANT_STACK: return 19;
        case EQUIP_ERR_ITEM_CANT_BE_EQUIPPED: return 20;
        case EQUIP_ERR_ITEMS_CANT_BE_SWAPPED: return 21;
        case EQUIP_ERR_SLOT_IS_EMPTY: return 22;
        case EQUIP_ERR_ITEM_NOT_FOUND: return 23;
        case EQUIP_ERR_CANT_DROP_SOULBOUND: return 24;
        case EQUIP_ERR_OUT_OF_RANGE: return 25;
        case EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT: return 26;
        case EQUIP_ERR_COULDNT_SPLIT_ITEMS: return 27;
        case EQUIP_ERR_MISSING_REAGENT: return 28;
        case EQUIP_ERR_NOT_ENOUGH_MONEY: return 29;
        case EQUIP_ERR_NOT_A_BAG: return 30;
        case EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS: return 31;
        case EQUIP_ERR_DONT_OWN_THAT_ITEM: return 32;
        case EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER: return 33;
        case EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT: return 34;
        case EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK: return 35;
        case EQUIP_ERR_ITEM_LOCKED: return 36;
        case EQUIP_ERR_YOU_ARE_STUNNED: return 37;
        case EQUIP_ERR_YOU_ARE_DEAD: return 38;
        case EQUIP_ERR_CANT_DO_RIGHT_NOW: return 39;
        case EQUIP_ERR_INT_BAG_ERROR: return 40;
        case EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT: return 41;
        case EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH: return 42;
        case EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED: return 43;
        case EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED: return 44;
        case EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED: return 45;
        case EQUIP_ERR_BOUND_CANT_BE_WRAPPED: return 46;
        case EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED: return 47;
        case EQUIP_ERR_BAGS_CANT_BE_WRAPPED: return 48;
        case EQUIP_ERR_ALREADY_LOOTED: return 49;
        case EQUIP_ERR_INVENTORY_FULL: return 50;
        case EQUIP_ERR_BANK_FULL: return 51;
        case EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT: return 52;
        case EQUIP_ERR_BAG_FULL3: return 53;
        case EQUIP_ERR_ITEM_NOT_FOUND2: return 54;
        case EQUIP_ERR_ITEM_CANT_STACK2: return 55;
        case EQUIP_ERR_BAG_FULL4: return 56;
        case EQUIP_ERR_ITEM_SOLD_OUT: return 57;
        case EQUIP_ERR_OBJECT_IS_BUSY: return 58;
        case EQUIP_ERR_NONE: return 59;
        case EQUIP_ERR_NOT_IN_COMBAT: return 60;
        case EQUIP_ERR_NOT_WHILE_DISARMED: return 61;
        case EQUIP_ERR_BAG_FULL6: return 62;
        case EQUIP_ERR_CANT_EQUIP_RANK: return 63;
        case EQUIP_ERR_CANT_EQUIP_REPUTATION: return 64;
        case EQUIP_ERR_TOO_MANY_SPECIAL_BAGS: return 65;
        case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW: return 66;
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE: return 67;
        case EQUIP_ERR_VENDOR_MISSING_TURNINS: return 68;
        case EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS: return 69;
        case EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS: return 70;
        case EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED: return 71;
        case EQUIP_ERR_MAIL_BOUND_ITEM: return 72;
        case EQUIP_ERR_NO_SPLIT_WHILE_PROSPECTING: return 73;
        case EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED: return 74;
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED: return 75;
        case EQUIP_ERR_TOO_MUCH_GOLD: return 76;
        case EQUIP_ERR_NOT_DURING_ARENA_MATCH: return 77;
        case EQUIP_ERR_CANNOT_TRADE_THAT: return 78;
        case EQUIP_ERR_PERSONAL_ARENA_RATING_TOO_LOW: return 79;
        case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM: return 80;
        case EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS: return 81;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED: return 82;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED: return 83;
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED: return 84;
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW: return 85;
        case EQUIP_ERR_CANT_EQUIP_NEED_TALENT: return 86;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED: return 87;
        default: throw std::out_of_range("value");
    }
}

/***************************************************************\
|* data for enum 'BuyResult' in 'ItemDefines.h' auto-generated *|
\***************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<BuyResult>::ToString(BuyResult value)
{
    switch (value)
    {
        case BUY_ERR_CANT_FIND_ITEM: return { "BUY_ERR_CANT_FIND_ITEM", "BUY_ERR_CANT_FIND_ITEM", "" };
        case BUY_ERR_ITEM_ALREADY_SOLD: return { "BUY_ERR_ITEM_ALREADY_SOLD", "BUY_ERR_ITEM_ALREADY_SOLD", "" };
        case BUY_ERR_NOT_ENOUGHT_MONEY: return { "BUY_ERR_NOT_ENOUGHT_MONEY", "BUY_ERR_NOT_ENOUGHT_MONEY", "" };
        case BUY_ERR_SELLER_DONT_LIKE_YOU: return { "BUY_ERR_SELLER_DONT_LIKE_YOU", "BUY_ERR_SELLER_DONT_LIKE_YOU", "" };
        case BUY_ERR_DISTANCE_TOO_FAR: return { "BUY_ERR_DISTANCE_TOO_FAR", "BUY_ERR_DISTANCE_TOO_FAR", "" };
        case BUY_ERR_ITEM_SOLD_OUT: return { "BUY_ERR_ITEM_SOLD_OUT", "BUY_ERR_ITEM_SOLD_OUT", "" };
        case BUY_ERR_CANT_CARRY_MORE: return { "BUY_ERR_CANT_CARRY_MORE", "BUY_ERR_CANT_CARRY_MORE", "" };
        case BUY_ERR_RANK_REQUIRE: return { "BUY_ERR_RANK_REQUIRE", "BUY_ERR_RANK_REQUIRE", "" };
        case BUY_ERR_REPUTATION_REQUIRE: return { "BUY_ERR_REPUTATION_REQUIRE", "BUY_ERR_REPUTATION_REQUIRE", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<BuyResult>::Count() { return 9; }

template <>
TC_API_EXPORT BuyResult EnumUtils<BuyResult>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return BUY_ERR_CANT_FIND_ITEM;
        case 1: return BUY_ERR_ITEM_ALREADY_SOLD;
        case 2: return BUY_ERR_NOT_ENOUGHT_MONEY;
        case 3: return BUY_ERR_SELLER_DONT_LIKE_YOU;
        case 4: return BUY_ERR_DISTANCE_TOO_FAR;
        case 5: return BUY_ERR_ITEM_SOLD_OUT;
        case 6: return BUY_ERR_CANT_CARRY_MORE;
        case 7: return BUY_ERR_RANK_REQUIRE;
        case 8: return BUY_ERR_REPUTATION_REQUIRE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<BuyResult>::ToIndex(BuyResult value)
{
    switch (value)
    {
        case BUY_ERR_CANT_FIND_ITEM: return 0;
        case BUY_ERR_ITEM_ALREADY_SOLD: return 1;
        case BUY_ERR_NOT_ENOUGHT_MONEY: return 2;
        case BUY_ERR_SELLER_DONT_LIKE_YOU: return 3;
        case BUY_ERR_DISTANCE_TOO_FAR: return 4;
        case BUY_ERR_ITEM_SOLD_OUT: return 5;
        case BUY_ERR_CANT_CARRY_MORE: return 6;
        case BUY_ERR_RANK_REQUIRE: return 7;
        case BUY_ERR_REPUTATION_REQUIRE: return 8;
        default: throw std::out_of_range("value");
    }
}

/****************************************************************\
|* data for enum 'SellResult' in 'ItemDefines.h' auto-generated *|
\****************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SellResult>::ToString(SellResult value)
{
    switch (value)
    {
        case SELL_ERR_CANT_FIND_ITEM: return { "SELL_ERR_CANT_FIND_ITEM", "SELL_ERR_CANT_FIND_ITEM", "The item was not found." };
        case SELL_ERR_CANT_SELL_ITEM: return { "SELL_ERR_CANT_SELL_ITEM", "SELL_ERR_CANT_SELL_ITEM", "The merchant doesn't want that item." };
        case SELL_ERR_CANT_FIND_VENDOR: return { "SELL_ERR_CANT_FIND_VENDOR", "SELL_ERR_CANT_FIND_VENDOR", "The merchant doesn't like you." };
        case SELL_ERR_YOU_DONT_OWN_THAT_ITEM: return { "SELL_ERR_YOU_DONT_OWN_THAT_ITEM", "SELL_ERR_YOU_DONT_OWN_THAT_ITEM", "You don't own that item." };
        case SELL_ERR_UNK: return { "SELL_ERR_UNK", "SELL_ERR_UNK", "nothing appears..." };
        case SELL_ERR_ONLY_EMPTY_BAG: return { "SELL_ERR_ONLY_EMPTY_BAG", "SELL_ERR_ONLY_EMPTY_BAG", "You can only do that with empty bags." };
        case SELL_ERR_CANT_SELL_TO_THIS_MERCHANT: return { "SELL_ERR_CANT_SELL_TO_THIS_MERCHANT", "SELL_ERR_CANT_SELL_TO_THIS_MERCHANT", "You cannot sell items to this merchant." };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SellResult>::Count() { return 7; }

template <>
TC_API_EXPORT SellResult EnumUtils<SellResult>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SELL_ERR_CANT_FIND_ITEM;
        case 1: return SELL_ERR_CANT_SELL_ITEM;
        case 2: return SELL_ERR_CANT_FIND_VENDOR;
        case 3: return SELL_ERR_YOU_DONT_OWN_THAT_ITEM;
        case 4: return SELL_ERR_UNK;
        case 5: return SELL_ERR_ONLY_EMPTY_BAG;
        case 6: return SELL_ERR_CANT_SELL_TO_THIS_MERCHANT;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SellResult>::ToIndex(SellResult value)
{
    switch (value)
    {
        case SELL_ERR_CANT_FIND_ITEM: return 0;
        case SELL_ERR_CANT_SELL_ITEM: return 1;
        case SELL_ERR_CANT_FIND_VENDOR: return 2;
        case SELL_ERR_YOU_DONT_OWN_THAT_ITEM: return 3;
        case SELL_ERR_UNK: return 4;
        case SELL_ERR_ONLY_EMPTY_BAG: return 5;
        case SELL_ERR_CANT_SELL_TO_THIS_MERCHANT: return 6;
        default: throw std::out_of_range("value");
    }
}
}
