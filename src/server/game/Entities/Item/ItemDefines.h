/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef ItemDefines_h__
#define ItemDefines_h__

#include "Define.h"

enum InventoryResult : uint8
{
    EQUIP_ERR_OK                                           = 0,
    EQUIP_ERR_CANT_EQUIP_LEVEL_I                           = 1,  // You must reach level %d to use that item.
    EQUIP_ERR_CANT_EQUIP_SKILL                             = 2,  // You aren't skilled enough to use that item.
    EQUIP_ERR_WRONG_SLOT                                   = 3,  // That item does not go in that slot.
    EQUIP_ERR_BAG_FULL                                     = 4,  // That bag is full.
    EQUIP_ERR_BAG_IN_BAG                                   = 5,  // Can't put non-empty bags in other bags.
    EQUIP_ERR_TRADE_EQUIPPED_BAG                           = 6,  // You can't trade equipped bags.
    EQUIP_ERR_AMMO_ONLY                                    = 7,  // Only ammo can go there.
    EQUIP_ERR_PROFICIENCY_NEEDED                           = 8,  // You do not have the required proficiency for that item.
    EQUIP_ERR_NO_SLOT_AVAILABLE                            = 9,  // No equipment slot is available for that item.
    EQUIP_ERR_CANT_EQUIP_EVER                              = 10, // You can never use that item.
    EQUIP_ERR_CANT_EQUIP_EVER_2                            = 11, // You can never use that item.
    EQUIP_ERR_NO_SLOT_AVAILABLE_2                          = 12, // No equipment slot is available for that item.
    EQUIP_ERR_2HANDED_EQUIPPED                             = 13, // Cannot equip that with a two-handed weapon.
    EQUIP_ERR_2HSKILLNOTFOUND                              = 14, // You cannot dual-wield
    EQUIP_ERR_WRONG_BAG_TYPE                               = 15, // That item doesn't go in that container.
    EQUIP_ERR_WRONG_BAG_TYPE_2                             = 16, // That item doesn't go in that container.
    EQUIP_ERR_ITEM_MAX_COUNT                               = 17, // You can't carry any more of those items.
    EQUIP_ERR_NO_SLOT_AVAILABLE_3                          = 18, // No equipment slot is available for that item.
    EQUIP_ERR_CANT_STACK                                   = 19, // This item cannot stack.
    EQUIP_ERR_NOT_EQUIPPABLE                               = 20, // This item cannot be equipped.
    EQUIP_ERR_CANT_SWAP                                    = 21, // These items can't be swapped.
    EQUIP_ERR_SLOT_EMPTY                                   = 22, // That slot is empty.
    EQUIP_ERR_ITEM_NOT_FOUND                               = 23, // The item was not found.
    EQUIP_ERR_DROP_BOUND_ITEM                              = 24, // You can't drop a soulbound item.
    EQUIP_ERR_OUT_OF_RANGE                                 = 25, // Out of range.
    EQUIP_ERR_TOO_FEW_TO_SPLIT                             = 26, // Tried to split more than number in stack.
    EQUIP_ERR_SPLIT_FAILED                                 = 27, // Couldn't split those items.
    EQUIP_ERR_SPELL_FAILED_REAGENTS_GENERIC                = 28, // Missing reagent
    EQUIP_ERR_CANT_TRADE_GOLD                              = 29, // Gold may only be offered by one trader.
    EQUIP_ERR_NOT_ENOUGH_MONEY                             = 30, // You don't have enough money.
    EQUIP_ERR_NOT_A_BAG                                    = 31, // Not a bag.
    EQUIP_ERR_DESTROY_NONEMPTY_BAG                         = 32, // You can only do that with empty bags.
    EQUIP_ERR_NOT_OWNER                                    = 33, // You don't own that item.
    EQUIP_ERR_ONLY_ONE_QUIVER                              = 34, // You can only equip one quiver.
    EQUIP_ERR_NO_BANK_SLOT                                 = 35, // You must purchase that bag slot first
    EQUIP_ERR_NO_BANK_HERE                                 = 36, // You are too far away from a bank.
    EQUIP_ERR_ITEM_LOCKED                                  = 37, // Item is locked.
    EQUIP_ERR_GENERIC_STUNNED                              = 38, // You are stunned
    EQUIP_ERR_PLAYER_DEAD                                  = 39, // You can't do that when you're dead.
    EQUIP_ERR_CLIENT_LOCKED_OUT                            = 40, // You can't do that right now.
    EQUIP_ERR_INTERNAL_BAG_ERROR                           = 41, // Internal Bag Error
    EQUIP_ERR_ONLY_ONE_BOLT                                = 42, // You can only equip one quiver.
    EQUIP_ERR_ONLY_ONE_AMMO                                = 43, // You can only equip one ammo pouch.
    EQUIP_ERR_CANT_WRAP_STACKABLE                          = 44, // Stackable items can't be wrapped.
    EQUIP_ERR_CANT_WRAP_EQUIPPED                           = 45, // Equipped items can't be wrapped.
    EQUIP_ERR_CANT_WRAP_WRAPPED                            = 46, // Wrapped items can't be wrapped.
    EQUIP_ERR_CANT_WRAP_BOUND                              = 47, // Bound items can't be wrapped.
    EQUIP_ERR_CANT_WRAP_UNIQUE                             = 48, // Unique items can't be wrapped.
    EQUIP_ERR_CANT_WRAP_BAGS                               = 49, // Bags can't be wrapped.
    EQUIP_ERR_LOOT_GONE                                    = 50, // Already looted
    EQUIP_ERR_INV_FULL                                     = 51, // Inventory is full.
    EQUIP_ERR_BANK_FULL                                    = 52, // Your bank is full
    EQUIP_ERR_VENDOR_SOLD_OUT                              = 53, // That item is currently sold out.
    EQUIP_ERR_BAG_FULL_2                                   = 54, // That bag is full.
    EQUIP_ERR_ITEM_NOT_FOUND_2                             = 55, // The item was not found.
    EQUIP_ERR_CANT_STACK_2                                 = 56, // This item cannot stack.
    EQUIP_ERR_BAG_FULL_3                                   = 57, // That bag is full.
    EQUIP_ERR_VENDOR_SOLD_OUT_2                            = 58, // That item is currently sold out.
    EQUIP_ERR_OBJECT_IS_BUSY                               = 59, // That object is busy.
    EQUIP_ERR_CANT_BE_DISENCHANTED                         = 60, // Item cannot be disenchanted
    EQUIP_ERR_NOT_IN_COMBAT                                = 61, // You can't do that while in combat
    EQUIP_ERR_NOT_WHILE_DISARMED                           = 62, // You can't do that while disarmed
    EQUIP_ERR_BAG_FULL_4                                   = 63, // That bag is full.
    EQUIP_ERR_CANT_EQUIP_RANK                              = 64, // You don't have the required rank for that item
    EQUIP_ERR_CANT_EQUIP_REPUTATION                        = 65, // You don't have the required reputation for that item
    EQUIP_ERR_TOO_MANY_SPECIAL_BAGS                        = 66, // You cannot equip another bag of that type
    EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW                      = 67, // You can't loot that item now.
    EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE                       = 68, // You cannot equip more than one of those.
    EQUIP_ERR_VENDOR_MISSING_TURNINS                       = 69, // You do not have the required items for that purchase
    EQUIP_ERR_NOT_ENOUGH_HONOR_POINTS                      = 70, // You don't have enough honor points
    EQUIP_ERR_NOT_ENOUGH_ARENA_POINTS                      = 71, // You don't have enough arena points
    EQUIP_ERR_ITEM_MAX_COUNT_SOCKETED                      = 72, // You have the maximum number of those gems in your inventory or socketed into items.
    EQUIP_ERR_MAIL_BOUND_ITEM                              = 73, // You can't mail soulbound items.
    EQUIP_ERR_INTERNAL_BAG_ERROR_2                         = 74, // Internal Bag Error
    EQUIP_ERR_BAG_FULL_5                                   = 75, // That bag is full.
    EQUIP_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED             = 76, // You have the maximum number of those gems socketed into equipped items.
    EQUIP_ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED              = 77, // You cannot socket more than one of those gems into a single item.
    EQUIP_ERR_TOO_MUCH_GOLD                                = 78, // At gold limit
    EQUIP_ERR_NOT_DURING_ARENA_MATCH                       = 79, // You can't do that while in an arena match
    EQUIP_ERR_TRADE_BOUND_ITEM                             = 80, // You can't trade a soulbound item.
    EQUIP_ERR_CANT_EQUIP_RATING                            = 81, // You don't have the personal, team, or battleground rating required to buy that item
    EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM                 = 82,
    EQUIP_ERR_NOT_SAME_ACCOUNT                             = 83, // Account-bound items can only be given to your own characters.
    EQUIP_NONE_3                                           = 84,
    EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS    = 85, // You can only carry %d %s
    EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS = 86, // You can only equip %d |4item:items in the %s category
    EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED             = 87, // Your level is too high to use that item
    EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW                       = 88, // You must reach level %d to purchase that item.
    EQUIP_ERR_CANT_EQUIP_NEED_TALENT                       = 89, // You do not have the required talent to equip that.
    EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS = 90, // You can only equip %d |4item:items in the %s category
    EQUIP_ERR_SHAPESHIFT_FORM_CANNOT_EQUIP                 = 91, // Cannot equip item in this form
    EQUIP_ERR_ITEM_INVENTORY_FULL_SATCHEL                  = 92, // Your inventory is full. Your satchel has been delivered to your mailbox.
    EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW              = 93, // Your level is too low to use that item
    EQUIP_ERR_CANT_BUY_QUANTITY                            = 94, // You can't buy the specified quantity of that item.
    EQUIP_ERR_ITEM_IS_BATTLE_PAY_LOCKED                    = 95, // Your purchased item is still waiting to be unlocked
    EQUIP_ERR_REAGENT_BANK_FULL                            = 96, // Your reagent bank is full
    EQUIP_ERR_REAGENT_BANK_LOCKED                          = 97,
    EQUIP_ERR_WRONG_BAG_TYPE_3                             = 98, // That item doesn't go in that container.
    EQUIP_ERR_CANT_USE_ITEM                                = 99, // You can't use that item.
    EQUIP_ERR_CANT_BE_OBLITERATED                          = 100,// You can't obliterate that item
    EQUIP_ERR_GUILD_BANK_CONJURED_ITEM                     = 101,// You cannot store conjured items in the guild bank
    EQUIP_ERR_CANT_DO_THAT_RIGHT_NOW                       = 102,// You can't do that right now.
    EQUIP_ERR_BAG_FULL_6                                   = 103,// That bag is full.
    EQUIP_ERR_CANT_BE_SCRAPPED                             = 104,// You can't scrap that item
};

enum BuyResult
{
    BUY_ERR_CANT_FIND_ITEM                      = 0,
    BUY_ERR_ITEM_ALREADY_SOLD                   = 1,
    BUY_ERR_NOT_ENOUGHT_MONEY                   = 2,
    BUY_ERR_SELLER_DONT_LIKE_YOU                = 4,
    BUY_ERR_DISTANCE_TOO_FAR                    = 5,
    BUY_ERR_ITEM_SOLD_OUT                       = 7,
    BUY_ERR_CANT_CARRY_MORE                     = 8,
    BUY_ERR_RANK_REQUIRE                        = 11,
    BUY_ERR_REPUTATION_REQUIRE                  = 12
};

enum SellResult
{
    SELL_ERR_CANT_FIND_ITEM                      = 1,
    SELL_ERR_CANT_SELL_ITEM                      = 2,       // merchant doesn't like that item
    SELL_ERR_CANT_FIND_VENDOR                    = 3,       // merchant doesn't like you
    SELL_ERR_YOU_DONT_OWN_THAT_ITEM              = 4,       // you don't own that item
    SELL_ERR_UNK                                 = 5,       // nothing appears...
    SELL_ERR_ONLY_EMPTY_BAG                      = 6        // can only do with empty bags
};

// -1 from client enchantment slot number
enum EnchantmentSlot : uint16
{
    PERM_ENCHANTMENT_SLOT           = 0,
    TEMP_ENCHANTMENT_SLOT           = 1,
    SOCK_ENCHANTMENT_SLOT           = 2,
    SOCK_ENCHANTMENT_SLOT_2         = 3,
    SOCK_ENCHANTMENT_SLOT_3         = 4,
    BONUS_ENCHANTMENT_SLOT          = 5,
    PRISMATIC_ENCHANTMENT_SLOT      = 6,                    // added at apply special permanent enchantment
    USE_ENCHANTMENT_SLOT            = 7,

    MAX_INSPECTED_ENCHANTMENT_SLOT  = 8,

    PROP_ENCHANTMENT_SLOT_0         = 8,                   // used with RandomSuffix
    PROP_ENCHANTMENT_SLOT_1         = 9,                   // used with RandomSuffix
    PROP_ENCHANTMENT_SLOT_2         = 10,                   // used with RandomSuffix and RandomProperty
    PROP_ENCHANTMENT_SLOT_3         = 11,                   // used with RandomProperty
    PROP_ENCHANTMENT_SLOT_4         = 12,                   // used with RandomProperty
    MAX_ENCHANTMENT_SLOT            = 13
};

#define MAX_VISIBLE_ITEM_OFFSET       2                     // 2 fields per visible item (entry+enchantment)

enum ItemVendorType
{
    ITEM_VENDOR_TYPE_NONE     = 0,
    ITEM_VENDOR_TYPE_ITEM     = 1,
    ITEM_VENDOR_TYPE_CURRENCY = 2,
};

enum ItemModifier : uint16
{
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS         = 0,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1            = 1,
    ITEM_MODIFIER_UPGRADE_ID                            = 2,
    ITEM_MODIFIER_BATTLE_PET_SPECIES_ID                 = 3,
    ITEM_MODIFIER_BATTLE_PET_BREED_DATA                 = 4, // (breedId) | (breedQuality << 24)
    ITEM_MODIFIER_BATTLE_PET_LEVEL                      = 5,
    ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID                 = 6,
    ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS            = 7,
    ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID                = 8,
    ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL = 9,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1               = 10,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2            = 11,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2               = 12,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3            = 13,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3               = 14,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4            = 15,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4               = 16,
    ITEM_MODIFIER_CHALLENGE_MAP_CHALLENGE_MODE_ID       = 17,
    ITEM_MODIFIER_CHALLENGE_KEYSTONE_LEVEL              = 18,
    ITEM_MODIFIER_CHALLENGE_KEYSTONE_AFFIX_ID_1         = 19,
    ITEM_MODIFIER_CHALLENGE_KEYSTONE_AFFIX_ID_2         = 20,
    ITEM_MODIFIER_CHALLENGE_KEYSTONE_AFFIX_ID_3         = 21,
    ITEM_MODIFIER_CHALLENGE_KEYSTONE_IS_CHARGED         = 22,
    ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL              = 23,
    ITEM_MODIFIER_ARTIFACT_TIER                         = 24,

    MAX_ITEM_MODIFIERS
};

#endif // ItemDefines_h__
