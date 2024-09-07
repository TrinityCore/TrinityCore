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
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I: return { "EQUIP_ERR_CANT_EQUIP_LEVEL_I", "EQUIP_ERR_CANT_EQUIP_LEVEL_I", "You must reach level %d to use that item." };
        case EQUIP_ERR_CANT_EQUIP_SKILL: return { "EQUIP_ERR_CANT_EQUIP_SKILL", "EQUIP_ERR_CANT_EQUIP_SKILL", "You aren't skilled enough to use that item." };
        case EQUIP_ERR_WRONG_SLOT: return { "EQUIP_ERR_WRONG_SLOT", "EQUIP_ERR_WRONG_SLOT", "That item does not go in that slot." };
        case EQUIP_ERR_BAG_FULL: return { "EQUIP_ERR_BAG_FULL", "EQUIP_ERR_BAG_FULL", "That bag is full." };
        case EQUIP_ERR_BAG_IN_BAG: return { "EQUIP_ERR_BAG_IN_BAG", "EQUIP_ERR_BAG_IN_BAG", "Can't put non-empty bags in other bags." };
        case EQUIP_ERR_TRADE_EQUIPPED_BAG: return { "EQUIP_ERR_TRADE_EQUIPPED_BAG", "EQUIP_ERR_TRADE_EQUIPPED_BAG", "You can't trade equipped bags." };
        case EQUIP_ERR_AMMO_ONLY: return { "EQUIP_ERR_AMMO_ONLY", "EQUIP_ERR_AMMO_ONLY", "Only ammo can go there." };
        case EQUIP_ERR_PROFICIENCY_NEEDED: return { "EQUIP_ERR_PROFICIENCY_NEEDED", "EQUIP_ERR_PROFICIENCY_NEEDED", "You do not have the required proficiency for that item." };
        case EQUIP_ERR_NO_SLOT_AVAILABLE: return { "EQUIP_ERR_NO_SLOT_AVAILABLE", "EQUIP_ERR_NO_SLOT_AVAILABLE", "No equipment slot is available for that item." };
        case EQUIP_ERR_CANT_EQUIP_EVER: return { "EQUIP_ERR_CANT_EQUIP_EVER", "EQUIP_ERR_CANT_EQUIP_EVER", "You can never use that item." };
        case EQUIP_ERR_CANT_EQUIP_EVER_2: return { "EQUIP_ERR_CANT_EQUIP_EVER_2", "EQUIP_ERR_CANT_EQUIP_EVER_2", "You can never use that item." };
        case EQUIP_ERR_NO_SLOT_AVAILABLE_2: return { "EQUIP_ERR_NO_SLOT_AVAILABLE_2", "EQUIP_ERR_NO_SLOT_AVAILABLE_2", "No equipment slot is available for that item." };
        case EQUIP_ERR_2HANDED_EQUIPPED: return { "EQUIP_ERR_2HANDED_EQUIPPED", "EQUIP_ERR_2HANDED_EQUIPPED", "Cannot equip that with a two-handed weapon." };
        case EQUIP_ERR_2HSKILLNOTFOUND: return { "EQUIP_ERR_2HSKILLNOTFOUND", "EQUIP_ERR_2HSKILLNOTFOUND", "You cannot dual-wield" };
        case EQUIP_ERR_WRONG_BAG_TYPE: return { "EQUIP_ERR_WRONG_BAG_TYPE", "EQUIP_ERR_WRONG_BAG_TYPE", "That item doesn't go in that container." };
        case EQUIP_ERR_WRONG_BAG_TYPE_2: return { "EQUIP_ERR_WRONG_BAG_TYPE_2", "EQUIP_ERR_WRONG_BAG_TYPE_2", "That item doesn't go in that container." };
        case EQUIP_ERR_ITEM_MAX_COUNT: return { "EQUIP_ERR_ITEM_MAX_COUNT", "EQUIP_ERR_ITEM_MAX_COUNT", "You can't carry any more of those items." };
        case EQUIP_ERR_NO_SLOT_AVAILABLE_3: return { "EQUIP_ERR_NO_SLOT_AVAILABLE_3", "EQUIP_ERR_NO_SLOT_AVAILABLE_3", "No equipment slot is available for that item." };
        case EQUIP_ERR_CANT_STACK: return { "EQUIP_ERR_CANT_STACK", "EQUIP_ERR_CANT_STACK", "This item cannot stack." };
        case EQUIP_ERR_NOT_EQUIPPABLE: return { "EQUIP_ERR_NOT_EQUIPPABLE", "EQUIP_ERR_NOT_EQUIPPABLE", "This item cannot be equipped." };
        case EQUIP_ERR_CANT_SWAP: return { "EQUIP_ERR_CANT_SWAP", "EQUIP_ERR_CANT_SWAP", "These items can't be swapped." };
        case EQUIP_ERR_SLOT_EMPTY: return { "EQUIP_ERR_SLOT_EMPTY", "EQUIP_ERR_SLOT_EMPTY", "That slot is empty." };
        case EQUIP_ERR_ITEM_NOT_FOUND: return { "EQUIP_ERR_ITEM_NOT_FOUND", "EQUIP_ERR_ITEM_NOT_FOUND", "The item was not found." };
        case EQUIP_ERR_DROP_BOUND_ITEM: return { "EQUIP_ERR_DROP_BOUND_ITEM", "EQUIP_ERR_DROP_BOUND_ITEM", "You can't drop a soulbound item." };
        case EQUIP_ERR_OUT_OF_RANGE: return { "EQUIP_ERR_OUT_OF_RANGE", "EQUIP_ERR_OUT_OF_RANGE", "Out of range." };
        case EQUIP_ERR_TOO_FEW_TO_SPLIT: return { "EQUIP_ERR_TOO_FEW_TO_SPLIT", "EQUIP_ERR_TOO_FEW_TO_SPLIT", "Tried to split more than number in stack." };
        case EQUIP_ERR_SPLIT_FAILED: return { "EQUIP_ERR_SPLIT_FAILED", "EQUIP_ERR_SPLIT_FAILED", "Couldn't split those items." };
        case EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC: return { "EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC", "EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC", "Missing reagent" };
        case EQUIP_ERR_CANT_TRADE_GOLD: return { "EQUIP_ERR_CANT_TRADE_GOLD", "EQUIP_ERR_CANT_TRADE_GOLD", "Gold may only be offered by one trader." };
        case EQUIP_ERR_NOT_ENOUGH_MONEY: return { "EQUIP_ERR_NOT_ENOUGH_MONEY", "EQUIP_ERR_NOT_ENOUGH_MONEY", "You don't have enough money." };
        case EQUIP_ERR_NOT_A_BAG: return { "EQUIP_ERR_NOT_A_BAG", "EQUIP_ERR_NOT_A_BAG", "Not a bag." };
        case EQUIP_ERR_DESTROY_NONEMPTY_BAG: return { "EQUIP_ERR_DESTROY_NONEMPTY_BAG", "EQUIP_ERR_DESTROY_NONEMPTY_BAG", "You can only do that with empty bags." };
        case EQUIP_ERR_NOT_OWNER: return { "EQUIP_ERR_NOT_OWNER", "EQUIP_ERR_NOT_OWNER", "You don't own that item." };
        case EQUIP_ERR_ONLY_ONE_QUIVER: return { "EQUIP_ERR_ONLY_ONE_QUIVER", "EQUIP_ERR_ONLY_ONE_QUIVER", "You can only equip one quiver." };
        case EQUIP_ERR_NO_BANK_SLOT: return { "EQUIP_ERR_NO_BANK_SLOT", "EQUIP_ERR_NO_BANK_SLOT", "You must purchase that bag slot first" };
        case EQUIP_ERR_NO_BANK_HERE: return { "EQUIP_ERR_NO_BANK_HERE", "EQUIP_ERR_NO_BANK_HERE", "You are too far away from a bank." };
        case EQUIP_ERR_ITEM_LOCKED: return { "EQUIP_ERR_ITEM_LOCKED", "EQUIP_ERR_ITEM_LOCKED", "Item is locked." };
        case EQUIP_ERR_GENERIC_STUNNED: return { "EQUIP_ERR_GENERIC_STUNNED", "EQUIP_ERR_GENERIC_STUNNED", "You are stunned" };
        case EQUIP_ERR_PLAYER_DEAD: return { "EQUIP_ERR_PLAYER_DEAD", "EQUIP_ERR_PLAYER_DEAD", "You can't do that when you're dead." };
        case EQUIP_ERR_CLIENT_LOCKED_OUT: return { "EQUIP_ERR_CLIENT_LOCKED_OUT", "EQUIP_ERR_CLIENT_LOCKED_OUT", "You can't do that right now." };
        case EQUIP_ERR_INTERNAL_BAG_ERROR: return { "EQUIP_ERR_INTERNAL_BAG_ERROR", "EQUIP_ERR_INTERNAL_BAG_ERROR", "Internal Bag Error" };
        case EQUIP_ERR_ONLY_ONE_BOLT: return { "EQUIP_ERR_ONLY_ONE_BOLT", "EQUIP_ERR_ONLY_ONE_BOLT", "You can only equip one quiver." };
        case EQUIP_ERR_ONLY_ONE_AMMO: return { "EQUIP_ERR_ONLY_ONE_AMMO", "EQUIP_ERR_ONLY_ONE_AMMO", "You can only equip one ammo pouch." };
        case EQUIP_ERR_CANT_WRAP_STACKABLE: return { "EQUIP_ERR_CANT_WRAP_STACKABLE", "EQUIP_ERR_CANT_WRAP_STACKABLE", "Stackable items can't be wrapped." };
        case EQUIP_ERR_CANT_WRAP_EQUIPPED: return { "EQUIP_ERR_CANT_WRAP_EQUIPPED", "EQUIP_ERR_CANT_WRAP_EQUIPPED", "Equipped items can't be wrapped." };
        case EQUIP_ERR_CANT_WRAP_WRAPPED: return { "EQUIP_ERR_CANT_WRAP_WRAPPED", "EQUIP_ERR_CANT_WRAP_WRAPPED", "Wrapped items can't be wrapped." };
        case EQUIP_ERR_CANT_WRAP_BOUND: return { "EQUIP_ERR_CANT_WRAP_BOUND", "EQUIP_ERR_CANT_WRAP_BOUND", "Bound items can't be wrapped." };
        case EQUIP_ERR_CANT_WRAP_UNIQUE: return { "EQUIP_ERR_CANT_WRAP_UNIQUE", "EQUIP_ERR_CANT_WRAP_UNIQUE", "Unique items can't be wrapped." };
        case EQUIP_ERR_CANT_WRAP_BAGS: return { "EQUIP_ERR_CANT_WRAP_BAGS", "EQUIP_ERR_CANT_WRAP_BAGS", "Bags can't be wrapped." };
        case EQUIP_ERR_LOOT_GONE: return { "EQUIP_ERR_LOOT_GONE", "EQUIP_ERR_LOOT_GONE", "Already looted" };
        case EQUIP_ERR_INV_FULL: return { "EQUIP_ERR_INV_FULL", "EQUIP_ERR_INV_FULL", "Inventory is full." };
        case EQUIP_ERR_BANK_FULL: return { "EQUIP_ERR_BANK_FULL", "EQUIP_ERR_BANK_FULL", "Your bank is full" };
        case EQUIP_ERR_VENDOR_SOLD_OUT: return { "EQUIP_ERR_VENDOR_SOLD_OUT", "EQUIP_ERR_VENDOR_SOLD_OUT", "That item is currently sold out." };
        case EQUIP_ERR_BAG_FULL_2: return { "EQUIP_ERR_BAG_FULL_2", "EQUIP_ERR_BAG_FULL_2", "That bag is full." };
        case EQUIP_ERR_ITEM_NOT_FOUND_2: return { "EQUIP_ERR_ITEM_NOT_FOUND_2", "EQUIP_ERR_ITEM_NOT_FOUND_2", "The item was not found." };
        case EQUIP_ERR_CANT_STACK_2: return { "EQUIP_ERR_CANT_STACK_2", "EQUIP_ERR_CANT_STACK_2", "This item cannot stack." };
        case EQUIP_ERR_BAG_FULL_3: return { "EQUIP_ERR_BAG_FULL_3", "EQUIP_ERR_BAG_FULL_3", "That bag is full." };
        case EQUIP_ERR_VENDOR_SOLD_OUT_2: return { "EQUIP_ERR_VENDOR_SOLD_OUT_2", "EQUIP_ERR_VENDOR_SOLD_OUT_2", "That item is currently sold out." };
        case EQUIP_ERR_OBJECT_IS_BUSY: return { "EQUIP_ERR_OBJECT_IS_BUSY", "EQUIP_ERR_OBJECT_IS_BUSY", "That object is busy." };
        case EQUIP_ERR_CANT_BE_DISENCHANTED: return { "EQUIP_ERR_CANT_BE_DISENCHANTED", "EQUIP_ERR_CANT_BE_DISENCHANTED", "Item cannot be disenchanted" };
        case EQUIP_ERR_NOT_IN_COMBAT: return { "EQUIP_ERR_NOT_IN_COMBAT", "EQUIP_ERR_NOT_IN_COMBAT", "You can't do that while in combat" };
        case EQUIP_ERR_NOT_WHILE_DISARMED: return { "EQUIP_ERR_NOT_WHILE_DISARMED", "EQUIP_ERR_NOT_WHILE_DISARMED", "You can't do that while disarmed" };
        case EQUIP_ERR_BAG_FULL_4: return { "EQUIP_ERR_BAG_FULL_4", "EQUIP_ERR_BAG_FULL_4", "That bag is full." };
        case EQUIP_ERR_CANT_EQUIP_RANK: return { "EQUIP_ERR_CANT_EQUIP_RANK", "EQUIP_ERR_CANT_EQUIP_RANK", "You don't have the required rank for that item" };
        case EQUIP_ERR_CANT_EQUIP_REPUTATION: return { "EQUIP_ERR_CANT_EQUIP_REPUTATION", "EQUIP_ERR_CANT_EQUIP_REPUTATION", "You don't have the required reputation for that item" };
        case EQUIP_ERR_TOO_MANY_SPECIAL_BAGS: return { "EQUIP_ERR_TOO_MANY_SPECIAL_BAGS", "EQUIP_ERR_TOO_MANY_SPECIAL_BAGS", "You cannot equip another bag of that type" };
        case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW: return { "EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW", "EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW", "You can't loot that item now." };
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE: return { "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE", "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE", "You cannot equip more than one of those." };
        case EQUIP_ERR_VENDOR_MISSING_TURNINS: return { "EQUIP_ERR_VENDOR_MISSING_TURNINS", "EQUIP_ERR_VENDOR_MISSING_TURNINS", "You do not have the required items for that purchase" };
        case EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS: return { "EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS", "EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS", "You don't have enough honor points" };
        case EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS: return { "EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS", "EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS", "You don't have enough arena points" };
        case EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED: return { "EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED", "EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED", "You have the maximum number of those gems in your inventory or socketed into items." };
        case EQUIP_ERR_MAIL_BOUND_ITEM: return { "EQUIP_ERR_MAIL_BOUND_ITEM", "EQUIP_ERR_MAIL_BOUND_ITEM", "You can't mail soulbound items." };
        case EQUIP_ERR_INTERNAL_BAG_ERROR_2: return { "EQUIP_ERR_INTERNAL_BAG_ERROR_2", "EQUIP_ERR_INTERNAL_BAG_ERROR_2", "Internal Bag Error" };
        case EQUIP_ERR_BAG_FULL_5: return { "EQUIP_ERR_BAG_FULL_5", "EQUIP_ERR_BAG_FULL_5", "That bag is full." };
        case EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED: return { "EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED", "EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED", "You have the maximum number of those gems socketed into equipped items." };
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED: return { "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED", "EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED", "You cannot socket more than one of those gems into a single item." };
        case EQUIP_ERR_TOO_MUCH_GOLD: return { "EQUIP_ERR_TOO_MUCH_GOLD", "EQUIP_ERR_TOO_MUCH_GOLD", "At gold limit" };
        case EQUIP_ERR_NOT_DURING_ARENA_MATCH: return { "EQUIP_ERR_NOT_DURING_ARENA_MATCH", "EQUIP_ERR_NOT_DURING_ARENA_MATCH", "You can't do that while in an arena match" };
        case EQUIP_ERR_TRADE_BOUND_ITEM: return { "EQUIP_ERR_TRADE_BOUND_ITEM", "EQUIP_ERR_TRADE_BOUND_ITEM", "You can't trade a soulbound item." };
        case EQUIP_ERR_CANT_EQUIP_RATING: return { "EQUIP_ERR_CANT_EQUIP_RATING", "EQUIP_ERR_CANT_EQUIP_RATING", "You don't have the personal, team, or battleground rating required to buy that item" };
        case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM: return { "EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM", "EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM", "" };
        case EQUIP_ERR_NOT_SAME_ACCOUNT: return { "EQUIP_ERR_NOT_SAME_ACCOUNT", "EQUIP_ERR_NOT_SAME_ACCOUNT", "Account-bound items can only be given to your own characters." };
        case EQUIP_ERR_NONE: return { "EQUIP_ERR_NONE", "EQUIP_ERR_NONE", "" };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS", "You can only carry %d %s" };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS", "You can only equip %d |4item:items in the %s category" };
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED: return { "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED", "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED", "Your level is too high to use that item" };
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW: return { "EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW", "EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW", "You must reach level %d to purchase that item." };
        case EQUIP_ERR_CANT_EQUIP_NEED_TALENT: return { "EQUIP_ERR_CANT_EQUIP_NEED_TALENT", "EQUIP_ERR_CANT_EQUIP_NEED_TALENT", "You do not have the required talent to equip that." };
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS: return { "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS", "EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS", "You can only equip %d |4item:items in the %s category" };
        case EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP: return { "EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP", "EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP", "Cannot equip item in this form" };
        case EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL: return { "EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL", "EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL", "Your inventory is full. Your satchel has been delivered to your mailbox." };
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW: return { "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW", "EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW", "Your level is too low to use that item" };
        case EQUIP_ERR_CANT_BUY_QUANTITY: return { "EQUIP_ERR_CANT_BUY_QUANTITY", "EQUIP_ERR_CANT_BUY_QUANTITY", "You can't buy the specified quantity of that item." };
        case EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED: return { "EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED", "EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED", "Your purchased item is still waiting to be unlocked" };
        case EQUIP_ERR_REAGENT_BANK_FULL: return { "EQUIP_ERR_REAGENT_BANK_FULL", "EQUIP_ERR_REAGENT_BANK_FULL", "Your reagent bank is full" };
        case EQUIP_ERR_REAGENT_BANK_LOCKED: return { "EQUIP_ERR_REAGENT_BANK_LOCKED", "EQUIP_ERR_REAGENT_BANK_LOCKED", "" };
        case EQUIP_ERR_WRONG_BAG_TYPE_3: return { "EQUIP_ERR_WRONG_BAG_TYPE_3", "EQUIP_ERR_WRONG_BAG_TYPE_3", "That item doesn't go in that container." };
        case EQUIP_ERR_CANT_USE_ITEM: return { "EQUIP_ERR_CANT_USE_ITEM", "EQUIP_ERR_CANT_USE_ITEM", "You can't use that item." };
        case EQUIP_ERR_CANT_BE_OBLITERATED: return { "EQUIP_ERR_CANT_BE_OBLITERATED", "EQUIP_ERR_CANT_BE_OBLITERATED", "You can't obliterate that item" };
        case EQUIP_ERR_GUILD_BANK_CONJURED_ITEM: return { "EQUIP_ERR_GUILD_BANK_CONJURED_ITEM", "EQUIP_ERR_GUILD_BANK_CONJURED_ITEM", "You cannot store conjured items in the guild bank" };
        case EQUIP_ERR_BAG_FULL_6: return { "EQUIP_ERR_BAG_FULL_6", "EQUIP_ERR_BAG_FULL_6", "That bag is full." };
        case EQUIP_ERR_BAG_FULL_7: return { "EQUIP_ERR_BAG_FULL_7", "EQUIP_ERR_BAG_FULL_7", "That bag is full." };
        case EQUIP_ERR_CANT_BE_SCRAPPED: return { "EQUIP_ERR_CANT_BE_SCRAPPED", "EQUIP_ERR_CANT_BE_SCRAPPED", "You can't scrap that item" };
        case EQUIP_ERR_BAG_FULL_8: return { "EQUIP_ERR_BAG_FULL_8", "EQUIP_ERR_BAG_FULL_8", "That bag is full." };
        case EQUIP_ERR_NOT_IN_PET_BATTLE: return { "EQUIP_ERR_NOT_IN_PET_BATTLE", "EQUIP_ERR_NOT_IN_PET_BATTLE", "You cannot do that while in a pet battle" };
        case EQUIP_ERR_BAG_FULL_9: return { "EQUIP_ERR_BAG_FULL_9", "EQUIP_ERR_BAG_FULL_9", "That bag is full." };
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW: return { "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW", "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW", "You can't do that right now." };
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_2: return { "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_2", "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_2", "You can't do that right now." };
        case EQUIP_ERR_NOT_IN_NPE: return { "EQUIP_ERR_NOT_IN_NPE", "EQUIP_ERR_NOT_IN_NPE", "Not available during the tutorial" };
        case EQUIP_ERR_ITEM_COOLDOWN: return { "EQUIP_ERR_ITEM_COOLDOWN", "EQUIP_ERR_ITEM_COOLDOWN", "Item is not ready yet." };
        case EQUIP_ERR_NOT_IN_RATED_BATTLEGROUND: return { "EQUIP_ERR_NOT_IN_RATED_BATTLEGROUND", "EQUIP_ERR_NOT_IN_RATED_BATTLEGROUND", "You can't do that in a rated battleground." };
        case EQUIP_ERR_EQUIPABLESPELLS_SLOTS_FULL: return { "EQUIP_ERR_EQUIPABLESPELLS_SLOTS_FULL", "EQUIP_ERR_EQUIPABLESPELLS_SLOTS_FULL", "" };
        case EQUIP_ERR_CANT_BE_RECRAFTED: return { "EQUIP_ERR_CANT_BE_RECRAFTED", "EQUIP_ERR_CANT_BE_RECRAFTED", "You can't recraft that itemv" };
        case EQUIP_ERR_REAGENTBAG_WRONG_SLOT: return { "EQUIP_ERR_REAGENTBAG_WRONG_SLOT", "EQUIP_ERR_REAGENTBAG_WRONG_SLOT", "Reagent Bags can only be placed in the reagent bag slot." };
        case EQUIP_ERR_SLOT_ONLY_REAGENTBAG: return { "EQUIP_ERR_SLOT_ONLY_REAGENTBAG", "EQUIP_ERR_SLOT_ONLY_REAGENTBAG", "Only Reagent Bags can be placed in the reagent bag slot." };
        case EQUIP_ERR_REAGENTBAG_ITEM_TYPE: return { "EQUIP_ERR_REAGENTBAG_ITEM_TYPE", "EQUIP_ERR_REAGENTBAG_ITEM_TYPE", "Only Reagents can be placed in Reagent Bags." };
        case EQUIP_ERR_CANT_BULK_SELL_ITEM_WITH_REFUND: return { "EQUIP_ERR_CANT_BULK_SELL_ITEM_WITH_REFUND", "EQUIP_ERR_CANT_BULK_SELL_ITEM_WITH_REFUND", "Items that can be refunded can't be bulk sold." };
        case EQUIP_ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK: return { "EQUIP_ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK", "EQUIP_ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK", "Soulbound items cannot be stored in the Warband Bank." };
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_3: return { "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_3", "EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_3", "You can't do that right now." };
        case EQUIP_ERR_NO_ACCOUNT_INVENTORY_LOCK: return { "EQUIP_ERR_NO_ACCOUNT_INVENTORY_LOCK", "EQUIP_ERR_NO_ACCOUNT_INVENTORY_LOCK", "Your character cannot complete this action." };
        case EQUIP_ERR_TOO_MANY_ACCOUNT_BANK_TABS: return { "EQUIP_ERR_TOO_MANY_ACCOUNT_BANK_TABS", "EQUIP_ERR_TOO_MANY_ACCOUNT_BANK_TABS", "You have already purchased the maximum amount of tabs." };
        case EQUIP_ERR_NO_ACCOUNT_BANK_HERE: return { "EQUIP_ERR_NO_ACCOUNT_BANK_HERE", "EQUIP_ERR_NO_ACCOUNT_BANK_HERE", "You are too far away from a Warband Bank." };
        case EQUIP_ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK: return { "EQUIP_ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK", "EQUIP_ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK", "Refundable items cannot be stored in the Warband Bank." };
        case EQUIP_ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK: return { "EQUIP_ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK", "EQUIP_ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK", "You cannot place that in the Warband Bank." };
        case EQUIP_ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK: return { "EQUIP_ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK", "EQUIP_ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK", "You cannot open this while it is in the Warband Bank." };
        case EQUIP_ERR_CANT_DELETE_IN_ACCOUNT_BANK: return { "EQUIP_ERR_CANT_DELETE_IN_ACCOUNT_BANK", "EQUIP_ERR_CANT_DELETE_IN_ACCOUNT_BANK", "Items must be moved out of the Warband Bank to be deleted." };
        case EQUIP_ERR_BANK_NOT_ACCESSIBLE: return { "EQUIP_ERR_BANK_NOT_ACCESSIBLE", "EQUIP_ERR_BANK_NOT_ACCESSIBLE", "This character does not have access to this bank." };
        case EQUIP_ERR_CANT_TRADE_ACCOUNT_ITEM: return { "EQUIP_ERR_CANT_TRADE_ACCOUNT_ITEM", "EQUIP_ERR_CANT_TRADE_ACCOUNT_ITEM", "You can't trade an item from the Warband bank." };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<InventoryResult>::Count() { return 130; }

template <>
TC_API_EXPORT InventoryResult EnumUtils<InventoryResult>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return EQUIP_ERR_OK;
        case 1: return EQUIP_ERR_CANT_EQUIP_LEVEL_I;
        case 2: return EQUIP_ERR_CANT_EQUIP_SKILL;
        case 3: return EQUIP_ERR_WRONG_SLOT;
        case 4: return EQUIP_ERR_BAG_FULL;
        case 5: return EQUIP_ERR_BAG_IN_BAG;
        case 6: return EQUIP_ERR_TRADE_EQUIPPED_BAG;
        case 7: return EQUIP_ERR_AMMO_ONLY;
        case 8: return EQUIP_ERR_PROFICIENCY_NEEDED;
        case 9: return EQUIP_ERR_NO_SLOT_AVAILABLE;
        case 10: return EQUIP_ERR_CANT_EQUIP_EVER;
        case 11: return EQUIP_ERR_CANT_EQUIP_EVER_2;
        case 12: return EQUIP_ERR_NO_SLOT_AVAILABLE_2;
        case 13: return EQUIP_ERR_2HANDED_EQUIPPED;
        case 14: return EQUIP_ERR_2HSKILLNOTFOUND;
        case 15: return EQUIP_ERR_WRONG_BAG_TYPE;
        case 16: return EQUIP_ERR_WRONG_BAG_TYPE_2;
        case 17: return EQUIP_ERR_ITEM_MAX_COUNT;
        case 18: return EQUIP_ERR_NO_SLOT_AVAILABLE_3;
        case 19: return EQUIP_ERR_CANT_STACK;
        case 20: return EQUIP_ERR_NOT_EQUIPPABLE;
        case 21: return EQUIP_ERR_CANT_SWAP;
        case 22: return EQUIP_ERR_SLOT_EMPTY;
        case 23: return EQUIP_ERR_ITEM_NOT_FOUND;
        case 24: return EQUIP_ERR_DROP_BOUND_ITEM;
        case 25: return EQUIP_ERR_OUT_OF_RANGE;
        case 26: return EQUIP_ERR_TOO_FEW_TO_SPLIT;
        case 27: return EQUIP_ERR_SPLIT_FAILED;
        case 28: return EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC;
        case 29: return EQUIP_ERR_CANT_TRADE_GOLD;
        case 30: return EQUIP_ERR_NOT_ENOUGH_MONEY;
        case 31: return EQUIP_ERR_NOT_A_BAG;
        case 32: return EQUIP_ERR_DESTROY_NONEMPTY_BAG;
        case 33: return EQUIP_ERR_NOT_OWNER;
        case 34: return EQUIP_ERR_ONLY_ONE_QUIVER;
        case 35: return EQUIP_ERR_NO_BANK_SLOT;
        case 36: return EQUIP_ERR_NO_BANK_HERE;
        case 37: return EQUIP_ERR_ITEM_LOCKED;
        case 38: return EQUIP_ERR_GENERIC_STUNNED;
        case 39: return EQUIP_ERR_PLAYER_DEAD;
        case 40: return EQUIP_ERR_CLIENT_LOCKED_OUT;
        case 41: return EQUIP_ERR_INTERNAL_BAG_ERROR;
        case 42: return EQUIP_ERR_ONLY_ONE_BOLT;
        case 43: return EQUIP_ERR_ONLY_ONE_AMMO;
        case 44: return EQUIP_ERR_CANT_WRAP_STACKABLE;
        case 45: return EQUIP_ERR_CANT_WRAP_EQUIPPED;
        case 46: return EQUIP_ERR_CANT_WRAP_WRAPPED;
        case 47: return EQUIP_ERR_CANT_WRAP_BOUND;
        case 48: return EQUIP_ERR_CANT_WRAP_UNIQUE;
        case 49: return EQUIP_ERR_CANT_WRAP_BAGS;
        case 50: return EQUIP_ERR_LOOT_GONE;
        case 51: return EQUIP_ERR_INV_FULL;
        case 52: return EQUIP_ERR_BANK_FULL;
        case 53: return EQUIP_ERR_VENDOR_SOLD_OUT;
        case 54: return EQUIP_ERR_BAG_FULL_2;
        case 55: return EQUIP_ERR_ITEM_NOT_FOUND_2;
        case 56: return EQUIP_ERR_CANT_STACK_2;
        case 57: return EQUIP_ERR_BAG_FULL_3;
        case 58: return EQUIP_ERR_VENDOR_SOLD_OUT_2;
        case 59: return EQUIP_ERR_OBJECT_IS_BUSY;
        case 60: return EQUIP_ERR_CANT_BE_DISENCHANTED;
        case 61: return EQUIP_ERR_NOT_IN_COMBAT;
        case 62: return EQUIP_ERR_NOT_WHILE_DISARMED;
        case 63: return EQUIP_ERR_BAG_FULL_4;
        case 64: return EQUIP_ERR_CANT_EQUIP_RANK;
        case 65: return EQUIP_ERR_CANT_EQUIP_REPUTATION;
        case 66: return EQUIP_ERR_TOO_MANY_SPECIAL_BAGS;
        case 67: return EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW;
        case 68: return EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE;
        case 69: return EQUIP_ERR_VENDOR_MISSING_TURNINS;
        case 70: return EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS;
        case 71: return EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS;
        case 72: return EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED;
        case 73: return EQUIP_ERR_MAIL_BOUND_ITEM;
        case 74: return EQUIP_ERR_INTERNAL_BAG_ERROR_2;
        case 75: return EQUIP_ERR_BAG_FULL_5;
        case 76: return EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED;
        case 77: return EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED;
        case 78: return EQUIP_ERR_TOO_MUCH_GOLD;
        case 79: return EQUIP_ERR_NOT_DURING_ARENA_MATCH;
        case 80: return EQUIP_ERR_TRADE_BOUND_ITEM;
        case 81: return EQUIP_ERR_CANT_EQUIP_RATING;
        case 82: return EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM;
        case 83: return EQUIP_ERR_NOT_SAME_ACCOUNT;
        case 84: return EQUIP_ERR_NONE;
        case 85: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS;
        case 86: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS;
        case 87: return EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED;
        case 88: return EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW;
        case 89: return EQUIP_ERR_CANT_EQUIP_NEED_TALENT;
        case 90: return EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS;
        case 91: return EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP;
        case 92: return EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL;
        case 93: return EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW;
        case 94: return EQUIP_ERR_CANT_BUY_QUANTITY;
        case 95: return EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED;
        case 96: return EQUIP_ERR_REAGENT_BANK_FULL;
        case 97: return EQUIP_ERR_REAGENT_BANK_LOCKED;
        case 98: return EQUIP_ERR_WRONG_BAG_TYPE_3;
        case 99: return EQUIP_ERR_CANT_USE_ITEM;
        case 100: return EQUIP_ERR_CANT_BE_OBLITERATED;
        case 101: return EQUIP_ERR_GUILD_BANK_CONJURED_ITEM;
        case 102: return EQUIP_ERR_BAG_FULL_6;
        case 103: return EQUIP_ERR_BAG_FULL_7;
        case 104: return EQUIP_ERR_CANT_BE_SCRAPPED;
        case 105: return EQUIP_ERR_BAG_FULL_8;
        case 106: return EQUIP_ERR_NOT_IN_PET_BATTLE;
        case 107: return EQUIP_ERR_BAG_FULL_9;
        case 108: return EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW;
        case 109: return EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_2;
        case 110: return EQUIP_ERR_NOT_IN_NPE;
        case 111: return EQUIP_ERR_ITEM_COOLDOWN;
        case 112: return EQUIP_ERR_NOT_IN_RATED_BATTLEGROUND;
        case 113: return EQUIP_ERR_EQUIPABLESPELLS_SLOTS_FULL;
        case 114: return EQUIP_ERR_CANT_BE_RECRAFTED;
        case 115: return EQUIP_ERR_REAGENTBAG_WRONG_SLOT;
        case 116: return EQUIP_ERR_SLOT_ONLY_REAGENTBAG;
        case 117: return EQUIP_ERR_REAGENTBAG_ITEM_TYPE;
        case 118: return EQUIP_ERR_CANT_BULK_SELL_ITEM_WITH_REFUND;
        case 119: return EQUIP_ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK;
        case 120: return EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_3;
        case 121: return EQUIP_ERR_NO_ACCOUNT_INVENTORY_LOCK;
        case 122: return EQUIP_ERR_TOO_MANY_ACCOUNT_BANK_TABS;
        case 123: return EQUIP_ERR_NO_ACCOUNT_BANK_HERE;
        case 124: return EQUIP_ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK;
        case 125: return EQUIP_ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK;
        case 126: return EQUIP_ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK;
        case 127: return EQUIP_ERR_CANT_DELETE_IN_ACCOUNT_BANK;
        case 128: return EQUIP_ERR_BANK_NOT_ACCESSIBLE;
        case 129: return EQUIP_ERR_CANT_TRADE_ACCOUNT_ITEM;
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
        case EQUIP_ERR_WRONG_SLOT: return 3;
        case EQUIP_ERR_BAG_FULL: return 4;
        case EQUIP_ERR_BAG_IN_BAG: return 5;
        case EQUIP_ERR_TRADE_EQUIPPED_BAG: return 6;
        case EQUIP_ERR_AMMO_ONLY: return 7;
        case EQUIP_ERR_PROFICIENCY_NEEDED: return 8;
        case EQUIP_ERR_NO_SLOT_AVAILABLE: return 9;
        case EQUIP_ERR_CANT_EQUIP_EVER: return 10;
        case EQUIP_ERR_CANT_EQUIP_EVER_2: return 11;
        case EQUIP_ERR_NO_SLOT_AVAILABLE_2: return 12;
        case EQUIP_ERR_2HANDED_EQUIPPED: return 13;
        case EQUIP_ERR_2HSKILLNOTFOUND: return 14;
        case EQUIP_ERR_WRONG_BAG_TYPE: return 15;
        case EQUIP_ERR_WRONG_BAG_TYPE_2: return 16;
        case EQUIP_ERR_ITEM_MAX_COUNT: return 17;
        case EQUIP_ERR_NO_SLOT_AVAILABLE_3: return 18;
        case EQUIP_ERR_CANT_STACK: return 19;
        case EQUIP_ERR_NOT_EQUIPPABLE: return 20;
        case EQUIP_ERR_CANT_SWAP: return 21;
        case EQUIP_ERR_SLOT_EMPTY: return 22;
        case EQUIP_ERR_ITEM_NOT_FOUND: return 23;
        case EQUIP_ERR_DROP_BOUND_ITEM: return 24;
        case EQUIP_ERR_OUT_OF_RANGE: return 25;
        case EQUIP_ERR_TOO_FEW_TO_SPLIT: return 26;
        case EQUIP_ERR_SPLIT_FAILED: return 27;
        case EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC: return 28;
        case EQUIP_ERR_CANT_TRADE_GOLD: return 29;
        case EQUIP_ERR_NOT_ENOUGH_MONEY: return 30;
        case EQUIP_ERR_NOT_A_BAG: return 31;
        case EQUIP_ERR_DESTROY_NONEMPTY_BAG: return 32;
        case EQUIP_ERR_NOT_OWNER: return 33;
        case EQUIP_ERR_ONLY_ONE_QUIVER: return 34;
        case EQUIP_ERR_NO_BANK_SLOT: return 35;
        case EQUIP_ERR_NO_BANK_HERE: return 36;
        case EQUIP_ERR_ITEM_LOCKED: return 37;
        case EQUIP_ERR_GENERIC_STUNNED: return 38;
        case EQUIP_ERR_PLAYER_DEAD: return 39;
        case EQUIP_ERR_CLIENT_LOCKED_OUT: return 40;
        case EQUIP_ERR_INTERNAL_BAG_ERROR: return 41;
        case EQUIP_ERR_ONLY_ONE_BOLT: return 42;
        case EQUIP_ERR_ONLY_ONE_AMMO: return 43;
        case EQUIP_ERR_CANT_WRAP_STACKABLE: return 44;
        case EQUIP_ERR_CANT_WRAP_EQUIPPED: return 45;
        case EQUIP_ERR_CANT_WRAP_WRAPPED: return 46;
        case EQUIP_ERR_CANT_WRAP_BOUND: return 47;
        case EQUIP_ERR_CANT_WRAP_UNIQUE: return 48;
        case EQUIP_ERR_CANT_WRAP_BAGS: return 49;
        case EQUIP_ERR_LOOT_GONE: return 50;
        case EQUIP_ERR_INV_FULL: return 51;
        case EQUIP_ERR_BANK_FULL: return 52;
        case EQUIP_ERR_VENDOR_SOLD_OUT: return 53;
        case EQUIP_ERR_BAG_FULL_2: return 54;
        case EQUIP_ERR_ITEM_NOT_FOUND_2: return 55;
        case EQUIP_ERR_CANT_STACK_2: return 56;
        case EQUIP_ERR_BAG_FULL_3: return 57;
        case EQUIP_ERR_VENDOR_SOLD_OUT_2: return 58;
        case EQUIP_ERR_OBJECT_IS_BUSY: return 59;
        case EQUIP_ERR_CANT_BE_DISENCHANTED: return 60;
        case EQUIP_ERR_NOT_IN_COMBAT: return 61;
        case EQUIP_ERR_NOT_WHILE_DISARMED: return 62;
        case EQUIP_ERR_BAG_FULL_4: return 63;
        case EQUIP_ERR_CANT_EQUIP_RANK: return 64;
        case EQUIP_ERR_CANT_EQUIP_REPUTATION: return 65;
        case EQUIP_ERR_TOO_MANY_SPECIAL_BAGS: return 66;
        case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW: return 67;
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE: return 68;
        case EQUIP_ERR_VENDOR_MISSING_TURNINS: return 69;
        case EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS: return 70;
        case EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS: return 71;
        case EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED: return 72;
        case EQUIP_ERR_MAIL_BOUND_ITEM: return 73;
        case EQUIP_ERR_INTERNAL_BAG_ERROR_2: return 74;
        case EQUIP_ERR_BAG_FULL_5: return 75;
        case EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED: return 76;
        case EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED: return 77;
        case EQUIP_ERR_TOO_MUCH_GOLD: return 78;
        case EQUIP_ERR_NOT_DURING_ARENA_MATCH: return 79;
        case EQUIP_ERR_TRADE_BOUND_ITEM: return 80;
        case EQUIP_ERR_CANT_EQUIP_RATING: return 81;
        case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM: return 82;
        case EQUIP_ERR_NOT_SAME_ACCOUNT: return 83;
        case EQUIP_ERR_NONE: return 84;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS: return 85;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS: return 86;
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED: return 87;
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW: return 88;
        case EQUIP_ERR_CANT_EQUIP_NEED_TALENT: return 89;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS: return 90;
        case EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP: return 91;
        case EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL: return 92;
        case EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW: return 93;
        case EQUIP_ERR_CANT_BUY_QUANTITY: return 94;
        case EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED: return 95;
        case EQUIP_ERR_REAGENT_BANK_FULL: return 96;
        case EQUIP_ERR_REAGENT_BANK_LOCKED: return 97;
        case EQUIP_ERR_WRONG_BAG_TYPE_3: return 98;
        case EQUIP_ERR_CANT_USE_ITEM: return 99;
        case EQUIP_ERR_CANT_BE_OBLITERATED: return 100;
        case EQUIP_ERR_GUILD_BANK_CONJURED_ITEM: return 101;
        case EQUIP_ERR_BAG_FULL_6: return 102;
        case EQUIP_ERR_BAG_FULL_7: return 103;
        case EQUIP_ERR_CANT_BE_SCRAPPED: return 104;
        case EQUIP_ERR_BAG_FULL_8: return 105;
        case EQUIP_ERR_NOT_IN_PET_BATTLE: return 106;
        case EQUIP_ERR_BAG_FULL_9: return 107;
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW: return 108;
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_2: return 109;
        case EQUIP_ERR_NOT_IN_NPE: return 110;
        case EQUIP_ERR_ITEM_COOLDOWN: return 111;
        case EQUIP_ERR_NOT_IN_RATED_BATTLEGROUND: return 112;
        case EQUIP_ERR_EQUIPABLESPELLS_SLOTS_FULL: return 113;
        case EQUIP_ERR_CANT_BE_RECRAFTED: return 114;
        case EQUIP_ERR_REAGENTBAG_WRONG_SLOT: return 115;
        case EQUIP_ERR_SLOT_ONLY_REAGENTBAG: return 116;
        case EQUIP_ERR_REAGENTBAG_ITEM_TYPE: return 117;
        case EQUIP_ERR_CANT_BULK_SELL_ITEM_WITH_REFUND: return 118;
        case EQUIP_ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK: return 119;
        case EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW_3: return 120;
        case EQUIP_ERR_NO_ACCOUNT_INVENTORY_LOCK: return 121;
        case EQUIP_ERR_TOO_MANY_ACCOUNT_BANK_TABS: return 122;
        case EQUIP_ERR_NO_ACCOUNT_BANK_HERE: return 123;
        case EQUIP_ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK: return 124;
        case EQUIP_ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK: return 125;
        case EQUIP_ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK: return 126;
        case EQUIP_ERR_CANT_DELETE_IN_ACCOUNT_BANK: return 127;
        case EQUIP_ERR_BANK_NOT_ACCESSIBLE: return 128;
        case EQUIP_ERR_CANT_TRADE_ACCOUNT_ITEM: return 129;
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
        case SELL_ERR_MUST_REPAIR_DURABILITY: return { "SELL_ERR_MUST_REPAIR_DURABILITY", "SELL_ERR_MUST_REPAIR_DURABILITY", "You must repair that item's durability to use it." };
        case SELL_ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE: return { "SELL_ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE", "SELL_ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE", "The merchant doesn't want that item. Bring it to the Scrapper to extract Titan Residuum." };
        case SELL_ERR_INTERNAL_BAG_ERROR: return { "SELL_ERR_INTERNAL_BAG_ERROR", "SELL_ERR_INTERNAL_BAG_ERROR", "Internal Bag Error" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SellResult>::Count() { return 10; }

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
        case 7: return SELL_ERR_MUST_REPAIR_DURABILITY;
        case 8: return SELL_ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE;
        case 9: return SELL_ERR_INTERNAL_BAG_ERROR;
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
        case SELL_ERR_MUST_REPAIR_DURABILITY: return 7;
        case SELL_ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE: return 8;
        case SELL_ERR_INTERNAL_BAG_ERROR: return 9;
        default: throw std::out_of_range("value");
    }
}
}
