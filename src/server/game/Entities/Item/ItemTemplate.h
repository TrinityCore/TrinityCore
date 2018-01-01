/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _ITEMPROTOTYPE_H
#define _ITEMPROTOTYPE_H

#include "Common.h"
#include "DB2Structure.h"
#include "SharedDefines.h"
#include <bitset>
#include <unordered_map>
#include <vector>

enum ItemModType
{
    ITEM_MOD_MANA                     = 0,
    ITEM_MOD_HEALTH                   = 1,
    ITEM_MOD_AGILITY                  = 3,
    ITEM_MOD_STRENGTH                 = 4,
    ITEM_MOD_INTELLECT                = 5,
    ITEM_MOD_SPIRIT                   = 6,
    ITEM_MOD_STAMINA                  = 7,
    ITEM_MOD_DEFENSE_SKILL_RATING     = 12,
    ITEM_MOD_DODGE_RATING             = 13,
    ITEM_MOD_PARRY_RATING             = 14,
    ITEM_MOD_BLOCK_RATING             = 15,
    ITEM_MOD_HIT_MELEE_RATING         = 16,
    ITEM_MOD_HIT_RANGED_RATING        = 17,
    ITEM_MOD_HIT_SPELL_RATING         = 18,
    ITEM_MOD_CRIT_MELEE_RATING        = 19,
    ITEM_MOD_CRIT_RANGED_RATING       = 20,
    ITEM_MOD_CRIT_SPELL_RATING        = 21,
    ITEM_MOD_HIT_TAKEN_MELEE_RATING   = 22,
    ITEM_MOD_HIT_TAKEN_RANGED_RATING  = 23,
    ITEM_MOD_HIT_TAKEN_SPELL_RATING   = 24,
    ITEM_MOD_CRIT_TAKEN_MELEE_RATING  = 25,
    ITEM_MOD_CRIT_TAKEN_RANGED_RATING = 26,
    ITEM_MOD_CRIT_TAKEN_SPELL_RATING  = 27,
    ITEM_MOD_HASTE_MELEE_RATING       = 28,
    ITEM_MOD_HASTE_RANGED_RATING      = 29,
    ITEM_MOD_HASTE_SPELL_RATING       = 30,
    ITEM_MOD_HIT_RATING               = 31,
    ITEM_MOD_CRIT_RATING              = 32,
    ITEM_MOD_HIT_TAKEN_RATING         = 33,
    ITEM_MOD_CRIT_TAKEN_RATING        = 34,
    ITEM_MOD_RESILIENCE_RATING        = 35,
    ITEM_MOD_HASTE_RATING             = 36,
    ITEM_MOD_EXPERTISE_RATING         = 37,
    ITEM_MOD_ATTACK_POWER             = 38,
    ITEM_MOD_RANGED_ATTACK_POWER      = 39,
    ITEM_MOD_VERSATILITY              = 40,
    ITEM_MOD_SPELL_HEALING_DONE       = 41,
    ITEM_MOD_SPELL_DAMAGE_DONE        = 42,
    ITEM_MOD_MANA_REGENERATION        = 43,
    ITEM_MOD_ARMOR_PENETRATION_RATING = 44,
    ITEM_MOD_SPELL_POWER              = 45,
    ITEM_MOD_HEALTH_REGEN             = 46,
    ITEM_MOD_SPELL_PENETRATION        = 47,
    ITEM_MOD_BLOCK_VALUE              = 48,
    ITEM_MOD_MASTERY_RATING           = 49,
    ITEM_MOD_EXTRA_ARMOR              = 50,
    ITEM_MOD_FIRE_RESISTANCE          = 51,
    ITEM_MOD_FROST_RESISTANCE         = 52,
    ITEM_MOD_HOLY_RESISTANCE          = 53,
    ITEM_MOD_SHADOW_RESISTANCE        = 54,
    ITEM_MOD_NATURE_RESISTANCE        = 55,
    ITEM_MOD_ARCANE_RESISTANCE        = 56,
    ITEM_MOD_PVP_POWER                = 57,
    ITEM_MOD_CR_AMPLIFY               = 58,
    ITEM_MOD_CR_MULTISTRIKE           = 59,
    ITEM_MOD_CR_READINESS             = 60,
    ITEM_MOD_CR_SPEED                 = 61,
    ITEM_MOD_CR_LIFESTEAL             = 62,
    ITEM_MOD_CR_AVOIDANCE             = 63,
    ITEM_MOD_CR_STURDINESS            = 64,
    ITEM_MOD_CR_UNUSED_7              = 65,
    ITEM_MOD_CR_CLEAVE                = 66,
    ITEM_MOD_CR_UNUSED_9              = 67,
    ITEM_MOD_CR_UNUSED_10             = 68,
    ITEM_MOD_CR_UNUSED_11             = 69,
    ITEM_MOD_CR_UNUSED_12             = 70,
    ITEM_MOD_AGI_STR_INT              = 71,
    ITEM_MOD_AGI_STR                  = 72,
    ITEM_MOD_AGI_INT                  = 73,
    ITEM_MOD_STR_INT                  = 74
};

enum ItemSpelltriggerType
{
    ITEM_SPELLTRIGGER_ON_USE          = 0,                  // use after equip cooldown
    ITEM_SPELLTRIGGER_ON_EQUIP        = 1,
    ITEM_SPELLTRIGGER_CHANCE_ON_HIT   = 2,
    ITEM_SPELLTRIGGER_SOULSTONE       = 4,
    /*
     * ItemSpelltriggerType 5 might have changed on 2.4.3/3.0.3: Such auras
     * will be applied on item pickup and removed on item loss - maybe on the
     * other hand the item is destroyed if the aura is removed ("removed on
     * death" of spell 57348 makes me think so)
     */
    ITEM_SPELLTRIGGER_ON_OBTAIN       = 5,
    ITEM_SPELLTRIGGER_LEARN_SPELL_ID  = 6                   // used in item_template.spell_2 with spell_id with SPELL_GENERIC_LEARN in spell_1
};

#define MAX_ITEM_SPELLTRIGGER           7

enum ItemBondingType
{
    BIND_NONE                                   = 0,
    BIND_ON_ACQUIRE                             = 1,
    BIND_ON_EQUIP                               = 2,
    BIND_ON_USE                                 = 3,
    BIND_QUEST                                  = 4,
};

#define MAX_BIND_TYPE                             5

/* /// @todo: Requiring actual cases in which using (an) item isn't allowed while shapeshifted. Else, this flag would need an implementation.
    ITEM_FLAG_USE_WHEN_SHAPESHIFTED    = 0x00800000, // Item can be used in shapeshift forms */

// ITEM_FIELD_FLAGS
enum ItemFieldFlags : uint32
{
    ITEM_FIELD_FLAG_SOULBOUND     = 0x00000001, // Item is soulbound and cannot be traded <<--
    ITEM_FIELD_FLAG_TRANSLATED    = 0x00000002, // Item text will not read as garbage when player does not know the language
    ITEM_FIELD_FLAG_UNLOCKED      = 0x00000004, // Item had lock but can be opened now
    ITEM_FIELD_FLAG_WRAPPED       = 0x00000008, // Item is wrapped and contains another item
    ITEM_FIELD_FLAG_UNK2          = 0x00000010,
    ITEM_FIELD_FLAG_UNK3          = 0x00000020,
    ITEM_FIELD_FLAG_UNK4          = 0x00000040,
    ITEM_FIELD_FLAG_UNK5          = 0x00000080,
    ITEM_FIELD_FLAG_BOP_TRADEABLE = 0x00000100, // Allows trading soulbound items
    ITEM_FIELD_FLAG_READABLE      = 0x00000200, // Opens text page when right clicked
    ITEM_FIELD_FLAG_UNK6          = 0x00000400,
    ITEM_FIELD_FLAG_UNK7          = 0x00000800,
    ITEM_FIELD_FLAG_REFUNDABLE    = 0x00001000, // Item can be returned to vendor for its original cost (extended cost)
    ITEM_FIELD_FLAG_UNK8          = 0x00002000,
    ITEM_FIELD_FLAG_UNK9          = 0x00004000,
    ITEM_FIELD_FLAG_UNK10         = 0x00008000,
    ITEM_FIELD_FLAG_UNK11         = 0x00010000,
    ITEM_FIELD_FLAG_UNK12         = 0x00020000,
    ITEM_FIELD_FLAG_UNK13         = 0x00040000,
    ITEM_FIELD_FLAG_CHILD         = 0x00080000,
    ITEM_FIELD_FLAG_UNK15         = 0x00100000,
    ITEM_FIELD_FLAG_NEW_ITEM      = 0x00200000, // Item glows in inventory
    ITEM_FIELD_FLAG_UNK17         = 0x00400000,
    ITEM_FIELD_FLAG_UNK18         = 0x00800000,
    ITEM_FIELD_FLAG_UNK19         = 0x01000000,
    ITEM_FIELD_FLAG_UNK20         = 0x02000000,
    ITEM_FIELD_FLAG_UNK21         = 0x04000000,
    ITEM_FIELD_FLAG_UNK22         = 0x08000000,
    ITEM_FIELD_FLAG_UNK23         = 0x10000000,
    ITEM_FIELD_FLAG_UNK24         = 0x20000000,
    ITEM_FIELD_FLAG_UNK25         = 0x40000000,
    ITEM_FIELD_FLAG_UNK26         = 0x80000000
};

enum ItemFlags : uint32
{
    ITEM_FLAG_NO_PICKUP                         = 0x00000001,
    ITEM_FLAG_CONJURED                          = 0x00000002, // Conjured item
    ITEM_FLAG_HAS_LOOT                          = 0x00000004, // Item can be right clicked to open for loot
    ITEM_FLAG_HEROIC_TOOLTIP                    = 0x00000008, // Makes green "Heroic" text appear on item
    ITEM_FLAG_DEPRECATED                        = 0x00000010, // Cannot equip or use
    ITEM_FLAG_NO_USER_DESTROY                   = 0x00000020, // Item can not be destroyed, except by using spell (item can be reagent for spell)
    ITEM_FLAG_PLAYERCAST                        = 0x00000040, // Item's spells are castable by players
    ITEM_FLAG_NO_EQUIP_COOLDOWN                 = 0x00000080, // No default 30 seconds cooldown when equipped
    ITEM_FLAG_MULTI_LOOT_QUEST                  = 0x00000100,
    ITEM_FLAG_IS_WRAPPER                        = 0x00000200, // Item can wrap other items
    ITEM_FLAG_USES_RESOURCES                    = 0x00000400,
    ITEM_FLAG_MULTI_DROP                        = 0x00000800, // Looting this item does not remove it from available loot
    ITEM_FLAG_ITEM_PURCHASE_RECORD              = 0x00001000, // Item can be returned to vendor for its original cost (extended cost)
    ITEM_FLAG_PETITION                          = 0x00002000, // Item is guild or arena charter
    ITEM_FLAG_HAS_TEXT                          = 0x00004000, // Only readable items have this (but not all)
    ITEM_FLAG_NO_DISENCHANT                     = 0x00008000,
    ITEM_FLAG_REAL_DURATION                     = 0x00010000,
    ITEM_FLAG_NO_CREATOR                        = 0x00020000,
    ITEM_FLAG_IS_PROSPECTABLE                   = 0x00040000, // Item can be prospected
    ITEM_FLAG_UNIQUE_EQUIPPABLE                 = 0x00080000, // You can only equip one of these
    ITEM_FLAG_IGNORE_FOR_AURAS                  = 0x00100000,
    ITEM_FLAG_IGNORE_DEFAULT_ARENA_RESTRICTIONS = 0x00200000, // Item can be used during arena match
    ITEM_FLAG_NO_DURABILITY_LOSS                = 0x00400000, // Some Thrown weapons have it (and only Thrown) but not all
    ITEM_FLAG_USE_WHEN_SHAPESHIFTED             = 0x00800000, // Item can be used in shapeshift forms
    ITEM_FLAG_HAS_QUEST_GLOW                    = 0x01000000,
    ITEM_FLAG_HIDE_UNUSABLE_RECIPE              = 0x02000000, // Profession recipes: can only be looted if you meet requirements and don't already know it
    ITEM_FLAG_NOT_USEABLE_IN_ARENA              = 0x04000000, // Item cannot be used in arena
    ITEM_FLAG_IS_BOUND_TO_ACCOUNT               = 0x08000000, // Item binds to account and can be sent only to your own characters
    ITEM_FLAG_NO_REAGENT_COST                   = 0x10000000, // Spell is cast ignoring reagents
    ITEM_FLAG_IS_MILLABLE                       = 0x20000000, // Item can be milled
    ITEM_FLAG_REPORT_TO_GUILD_CHAT              = 0x40000000,
    ITEM_FLAG_NO_PROGRESSIVE_LOOT               = 0x80000000
};

enum ItemFlags2 : uint32
{
    ITEM_FLAG2_FACTION_HORDE                            = 0x00000001,
    ITEM_FLAG2_FACTION_ALLIANCE                         = 0x00000002,
    ITEM_FLAG2_DONT_IGNORE_BUY_PRICE                    = 0x00000004, // when item uses extended cost, gold is also required
    ITEM_FLAG2_CLASSIFY_AS_CASTER                       = 0x00000008,
    ITEM_FLAG2_CLASSIFY_AS_PHYSICAL                     = 0x00000010,
    ITEM_FLAG2_EVERYONE_CAN_ROLL_NEED                   = 0x00000020,
    ITEM_FLAG2_NO_TRADE_BIND_ON_ACQUIRE                 = 0x00000040,
    ITEM_FLAG2_CAN_TRADE_BIND_ON_ACQUIRE                = 0x00000080,
    ITEM_FLAG2_CAN_ONLY_ROLL_GREED                      = 0x00000100,
    ITEM_FLAG2_CASTER_WEAPON                            = 0x00000200,
    ITEM_FLAG2_DELETE_ON_LOGIN                          = 0x00000400,
    ITEM_FLAG2_INTERNAL_ITEM                            = 0x00000800,
    ITEM_FLAG2_NO_VENDOR_VALUE                          = 0x00001000,
    ITEM_FLAG2_SHOW_BEFORE_DISCOVERED                   = 0x00002000,
    ITEM_FLAG2_OVERRIDE_GOLD_COST                       = 0x00004000,
    ITEM_FLAG2_IGNORE_DEFAULT_RATED_BG_RESTRICTIONS     = 0x00008000,
    ITEM_FLAG2_NOT_USABLE_IN_RATED_BG                   = 0x00010000,
    ITEM_FLAG2_BNET_ACCOUNT_TRADE_OK                    = 0x00020000,
    ITEM_FLAG2_CONFIRM_BEFORE_USE                       = 0x00040000,
    ITEM_FLAG2_REEVALUATE_BONDING_ON_TRANSFORM          = 0x00080000,
    ITEM_FLAG2_NO_TRANSFORM_ON_CHARGE_DEPLETION         = 0x00100000,
    ITEM_FLAG2_NO_ALTER_ITEM_VISUAL                     = 0x00200000,
    ITEM_FLAG2_NO_SOURCE_FOR_ITEM_VISUAL                = 0x00400000,
    ITEM_FLAG2_IGNORE_QUALITY_FOR_ITEM_VISUAL_SOURCE    = 0x00800000,
    ITEM_FLAG2_NO_DURABILITY                            = 0x01000000,
    ITEM_FLAG2_ROLE_TANK                                = 0x02000000,
    ITEM_FLAG2_ROLE_HEALER                              = 0x04000000,
    ITEM_FLAG2_ROLE_DAMAGE                              = 0x08000000,
    ITEM_FLAG2_CAN_DROP_IN_CHALLENGE_MODE               = 0x10000000,
    ITEM_FLAG2_NEVER_STACK_IN_LOOT_UI                   = 0x20000000,
    ITEM_FLAG2_DISENCHANT_TO_LOOT_TABLE                 = 0x40000000,
    ITEM_FLAG2_USED_IN_A_TRADESKILL                     = 0x80000000
};

enum ItemFlags3
{
    ITEM_FLAG3_DONT_DESTROY_ON_QUEST_ACCEPT                 = 0x00000001,
    ITEM_FLAG3_ITEM_CAN_BE_UPGRADED                         = 0x00000002,
    ITEM_FLAG3_UPGRADE_FROM_ITEM_OVERRIDES_DROP_UPGRADE     = 0x00000004,
    ITEM_FLAG3_ALWAYS_FFA_IN_LOOT                           = 0x00000008,
    ITEM_FLAG3_HIDE_UPGRADE_LEVELS_IF_NOT_UPGRADED          = 0x00000010,
    ITEM_FLAG3_UPDATE_INTERACTIONS                          = 0x00000020,
    ITEM_FLAG3_UPDATE_DOESNT_LEAVE_PROGRESSIVE_WIN_HISTORY  = 0x00000040,
    ITEM_FLAG3_IGNORE_ITEM_HISTORY_TRACKER                  = 0x00000080,
    ITEM_FLAG3_IGNORE_ITEM_LEVEL_CAP_IN_PVP                 = 0x00000100,
    ITEM_FLAG3_DISPLAY_AS_HEIRLOOM                          = 0x00000200, // Item appears as having heirloom quality ingame regardless of its real quality (does not affect stat calculation)
    ITEM_FLAG3_SKIP_USE_CHECK_ON_PICKUP                     = 0x00000400,
    ITEM_FLAG3_OBSOLETE                                     = 0x00000800,
    ITEM_FLAG3_DONT_DISPLAY_IN_GUILD_NEWS                   = 0x00001000, // Item is not included in the guild news panel
    ITEM_FLAG3_PVP_TOURNAMENT_GEAR                          = 0x00002000,
    ITEM_FLAG3_REQUIRES_STACK_CHANGE_LOG                    = 0x00004000,
    ITEM_FLAG3_UNUSED_FLAG                                  = 0x00008000,
    ITEM_FLAG3_HIDE_NAME_SUFFIX                             = 0x00010000,
    ITEM_FLAG3_PUSH_LOOT                                    = 0x00020000,
    ITEM_FLAG3_DONT_REPORT_LOOT_LOG_TO_PARTY                = 0x00040000,
    ITEM_FLAG3_ALWAYS_ALLOW_DUAL_WIELD                      = 0x00080000,
    ITEM_FLAG3_OBLITERATABLE                                = 0x00100000,
    ITEM_FLAG3_ACTS_AS_TRANSMOG_HIDDEN_VISUAL_OPTION        = 0x00200000,
    ITEM_FLAG3_EXPIRE_ON_WEEKLY_RESET                       = 0x00400000,
    ITEM_FLAG3_DOESNT_SHOW_UP_IN_TRANSMOG_UNTIL_COLLECTED   = 0x00800000,
    ITEM_FLAG3_CAN_STORE_ENCHANTS                           = 0x01000000
};

enum ItemFlagsCustom
{
    ITEM_FLAGS_CU_UNUSED                = 0x0001,
    ITEM_FLAGS_CU_IGNORE_QUEST_STATUS   = 0x0002,   // No quest status will be checked when this item drops
    ITEM_FLAGS_CU_FOLLOW_LOOT_RULES     = 0x0004    // Item will always follow group/master/need before greed looting rules
};

enum CurrencyFlags
{
    CURRENCY_FLAG_TRADEABLE          = 0x01,
    // ...
    CURRENCY_FLAG_HIGH_PRECISION     = 0x08,
    // ...
    CURRENCY_FLAG_COUNT_SEASON_TOTAL = 0x80,
};

enum CurrencyCategory
{
    // ...
    CURRENCY_CATEGORY_META_CONQUEST = 89,
    // ...
};

enum BAG_FAMILY_MASK
{
    BAG_FAMILY_MASK_NONE                      = 0x00000000,
    BAG_FAMILY_MASK_ARROWS                    = 0x00000001,
    BAG_FAMILY_MASK_BULLETS                   = 0x00000002,
    BAG_FAMILY_MASK_SOUL_SHARDS               = 0x00000004,
    BAG_FAMILY_MASK_LEATHERWORKING_SUPP       = 0x00000008,
    BAG_FAMILY_MASK_INSCRIPTION_SUPP          = 0x00000010,
    BAG_FAMILY_MASK_HERBS                     = 0x00000020,
    BAG_FAMILY_MASK_ENCHANTING_SUPP           = 0x00000040,
    BAG_FAMILY_MASK_ENGINEERING_SUPP          = 0x00000080,
    BAG_FAMILY_MASK_KEYS                      = 0x00000100,
    BAG_FAMILY_MASK_GEMS                      = 0x00000200,
    BAG_FAMILY_MASK_MINING_SUPP               = 0x00000400,
    BAG_FAMILY_MASK_SOULBOUND_EQUIPMENT       = 0x00000800,
    BAG_FAMILY_MASK_VANITY_PETS               = 0x00001000,
    BAG_FAMILY_MASK_CURRENCY_TOKENS           = 0x00002000,
    BAG_FAMILY_MASK_QUEST_ITEMS               = 0x00004000,
    BAG_FAMILY_MASK_FISHING_SUPP              = 0x00008000,
    BAG_FAMILY_MASK_COOKING_SUPP              = 0x00010000,
};

enum SocketColor
{
    SOCKET_COLOR_META                           = 0x00001,
    SOCKET_COLOR_RED                            = 0x00002,
    SOCKET_COLOR_YELLOW                         = 0x00004,
    SOCKET_COLOR_BLUE                           = 0x00008,
    SOCKET_COLOR_HYDRAULIC                      = 0x00010, // not used
    SOCKET_COLOR_COGWHEEL                       = 0x00020,
    SOCKET_COLOR_PRISMATIC                      = 0x0000E,
    SOCKET_COLOR_RELIC_IRON                     = 0x00040,
    SOCKET_COLOR_RELIC_BLOOD                    = 0x00080,
    SOCKET_COLOR_RELIC_SHADOW                   = 0x00100,
    SOCKET_COLOR_RELIC_FEL                      = 0x00200,
    SOCKET_COLOR_RELIC_ARCANE                   = 0x00400,
    SOCKET_COLOR_RELIC_FROST                    = 0x00800,
    SOCKET_COLOR_RELIC_FIRE                     = 0x01000,
    SOCKET_COLOR_RELIC_WATER                    = 0x02000,
    SOCKET_COLOR_RELIC_LIFE                     = 0x04000,
    SOCKET_COLOR_RELIC_WIND                     = 0x08000,
    SOCKET_COLOR_RELIC_HOLY                     = 0x10000
};

extern uint32 const SocketColorToGemTypeMask[19];

#define SOCKET_COLOR_STANDARD (SOCKET_COLOR_RED | SOCKET_COLOR_YELLOW | SOCKET_COLOR_BLUE)

enum InventoryType : uint8
{
    INVTYPE_NON_EQUIP                           = 0,
    INVTYPE_HEAD                                = 1,
    INVTYPE_NECK                                = 2,
    INVTYPE_SHOULDERS                           = 3,
    INVTYPE_BODY                                = 4,
    INVTYPE_CHEST                               = 5,
    INVTYPE_WAIST                               = 6,
    INVTYPE_LEGS                                = 7,
    INVTYPE_FEET                                = 8,
    INVTYPE_WRISTS                              = 9,
    INVTYPE_HANDS                               = 10,
    INVTYPE_FINGER                              = 11,
    INVTYPE_TRINKET                             = 12,
    INVTYPE_WEAPON                              = 13,
    INVTYPE_SHIELD                              = 14,
    INVTYPE_RANGED                              = 15,
    INVTYPE_CLOAK                               = 16,
    INVTYPE_2HWEAPON                            = 17,
    INVTYPE_BAG                                 = 18,
    INVTYPE_TABARD                              = 19,
    INVTYPE_ROBE                                = 20,
    INVTYPE_WEAPONMAINHAND                      = 21,
    INVTYPE_WEAPONOFFHAND                       = 22,
    INVTYPE_HOLDABLE                            = 23,
    INVTYPE_AMMO                                = 24,
    INVTYPE_THROWN                              = 25,
    INVTYPE_RANGEDRIGHT                         = 26,
    INVTYPE_QUIVER                              = 27,
    INVTYPE_RELIC                               = 28
};

#define MAX_INVTYPE                               29

enum ItemClass : uint8
{
    ITEM_CLASS_CONSUMABLE                       = 0,
    ITEM_CLASS_CONTAINER                        = 1,
    ITEM_CLASS_WEAPON                           = 2,
    ITEM_CLASS_GEM                              = 3,
    ITEM_CLASS_ARMOR                            = 4,
    ITEM_CLASS_REAGENT                          = 5,
    ITEM_CLASS_PROJECTILE                       = 6,
    ITEM_CLASS_TRADE_GOODS                      = 7,
    ITEM_CLASS_ITEM_ENHANCEMENT                 = 8,
    ITEM_CLASS_RECIPE                           = 9,
    ITEM_CLASS_MONEY                            = 10, // OBSOLETE
    ITEM_CLASS_QUIVER                           = 11,
    ITEM_CLASS_QUEST                            = 12,
    ITEM_CLASS_KEY                              = 13,
    ITEM_CLASS_PERMANENT                        = 14, // OBSOLETE
    ITEM_CLASS_MISCELLANEOUS                    = 15,
    ITEM_CLASS_GLYPH                            = 16,
    ITEM_CLASS_BATTLE_PETS                      = 17,
    ITEM_CLASS_WOW_TOKEN                        = 18
};

#define MAX_ITEM_CLASS                            19

enum ItemSubclassConsumable
{
    ITEM_SUBCLASS_CONSUMABLE                    = 0,
    ITEM_SUBCLASS_POTION                        = 1,
    ITEM_SUBCLASS_ELIXIR                        = 2,
    ITEM_SUBCLASS_FLASK                         = 3,
    ITEM_SUBCLASS_SCROLL                        = 4,
    ITEM_SUBCLASS_FOOD_DRINK                    = 5,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT              = 6,
    ITEM_SUBCLASS_BANDAGE                       = 7,
    ITEM_SUBCLASS_CONSUMABLE_OTHER              = 8,
    ITEM_SUBCLASS_VANTUS_RUNE                   = 9
};

#define MAX_ITEM_SUBCLASS_CONSUMABLE              10

enum ItemSubclassContainer
{
    ITEM_SUBCLASS_CONTAINER                     = 0,
    ITEM_SUBCLASS_SOUL_CONTAINER                = 1,
    ITEM_SUBCLASS_HERB_CONTAINER                = 2,
    ITEM_SUBCLASS_ENCHANTING_CONTAINER          = 3,
    ITEM_SUBCLASS_ENGINEERING_CONTAINER         = 4,
    ITEM_SUBCLASS_GEM_CONTAINER                 = 5,
    ITEM_SUBCLASS_MINING_CONTAINER              = 6,
    ITEM_SUBCLASS_LEATHERWORKING_CONTAINER      = 7,
    ITEM_SUBCLASS_INSCRIPTION_CONTAINER         = 8,
    ITEM_SUBCLASS_TACKLE_CONTAINER              = 9,
    ITEM_SUBCLASS_COOKING_CONTAINER             = 10
};

#define MAX_ITEM_SUBCLASS_CONTAINER               11

enum ItemSubclassWeapon
{
    ITEM_SUBCLASS_WEAPON_AXE                    = 0,  // One-Handed Axes
    ITEM_SUBCLASS_WEAPON_AXE2                   = 1,  // Two-Handed Axes
    ITEM_SUBCLASS_WEAPON_BOW                    = 2,
    ITEM_SUBCLASS_WEAPON_GUN                    = 3,
    ITEM_SUBCLASS_WEAPON_MACE                   = 4,  // One-Handed Maces
    ITEM_SUBCLASS_WEAPON_MACE2                  = 5,  // Two-Handed Maces
    ITEM_SUBCLASS_WEAPON_POLEARM                = 6,
    ITEM_SUBCLASS_WEAPON_SWORD                  = 7,  // One-Handed Swords
    ITEM_SUBCLASS_WEAPON_SWORD2                 = 8,  // Two-Handed Swords
    ITEM_SUBCLASS_WEAPON_WARGLAIVES             = 9,
    ITEM_SUBCLASS_WEAPON_STAFF                  = 10,
    ITEM_SUBCLASS_WEAPON_EXOTIC                 = 11, // One-Handed Exotics
    ITEM_SUBCLASS_WEAPON_EXOTIC2                = 12, // Two-Handed Exotics
    ITEM_SUBCLASS_WEAPON_FIST_WEAPON            = 13,
    ITEM_SUBCLASS_WEAPON_MISCELLANEOUS          = 14,
    ITEM_SUBCLASS_WEAPON_DAGGER                 = 15,
    ITEM_SUBCLASS_WEAPON_THROWN                 = 16,
    ITEM_SUBCLASS_WEAPON_SPEAR                  = 17,
    ITEM_SUBCLASS_WEAPON_CROSSBOW               = 18,
    ITEM_SUBCLASS_WEAPON_WAND                   = 19,
    ITEM_SUBCLASS_WEAPON_FISHING_POLE           = 20
};

#define ITEM_SUBCLASS_MASK_WEAPON_RANGED (\
    (1 << ITEM_SUBCLASS_WEAPON_BOW) | (1 << ITEM_SUBCLASS_WEAPON_GUN) |\
    (1 << ITEM_SUBCLASS_WEAPON_CROSSBOW))

#define MAX_ITEM_SUBCLASS_WEAPON                  21

enum ItemSubclassGem
{
    ITEM_SUBCLASS_GEM_INTELLECT                 = 0,
    ITEM_SUBCLASS_GEM_AGILITY                   = 1,
    ITEM_SUBCLASS_GEM_STRENGTH                  = 2,
    ITEM_SUBCLASS_GEM_STAMINA                   = 3,
    ITEM_SUBCLASS_GEM_SPIRIT                    = 4,
    ITEM_SUBCLASS_GEM_CRITICAL_STRIKE           = 5,
    ITEM_SUBCLASS_GEM_MASTERY                   = 6,
    ITEM_SUBCLASS_GEM_HASTE                     = 7,
    ITEM_SUBCLASS_GEM_VERSATILITY               = 8,
    ITEM_SUBCLASS_GEM_OTHER                     = 9,
    ITEM_SUBCLASS_GEM_MULTIPLE_STATS            = 10,
    ITEM_SUBCLASS_GEM_ARTIFACT_RELIC            = 11
};

#define MAX_ITEM_SUBCLASS_GEM                     12

enum ItemSubclassArmor
{
    ITEM_SUBCLASS_ARMOR_MISCELLANEOUS           = 0,
    ITEM_SUBCLASS_ARMOR_CLOTH                   = 1,
    ITEM_SUBCLASS_ARMOR_LEATHER                 = 2,
    ITEM_SUBCLASS_ARMOR_MAIL                    = 3,
    ITEM_SUBCLASS_ARMOR_PLATE                   = 4,
    ITEM_SUBCLASS_ARMOR_COSMETIC                = 5,
    ITEM_SUBCLASS_ARMOR_SHIELD                  = 6,
    ITEM_SUBCLASS_ARMOR_LIBRAM                  = 7,
    ITEM_SUBCLASS_ARMOR_IDOL                    = 8,
    ITEM_SUBCLASS_ARMOR_TOTEM                   = 9,
    ITEM_SUBCLASS_ARMOR_SIGIL                   = 10,
    ITEM_SUBCLASS_ARMOR_RELIC                   = 11,
};

#define MAX_ITEM_SUBCLASS_ARMOR                   12

enum ItemSubclassReagent
{
    ITEM_SUBCLASS_REAGENT                       = 0,
    ITEM_SUBCLASS_KEYSTONE                      = 1
};

#define MAX_ITEM_SUBCLASS_REAGENT                 2

enum ItemSubclassProjectile
{
    ITEM_SUBCLASS_WAND                          = 0, // OBSOLETE
    ITEM_SUBCLASS_BOLT                          = 1, // OBSOLETE
    ITEM_SUBCLASS_ARROW                         = 2,
    ITEM_SUBCLASS_BULLET                        = 3,
    ITEM_SUBCLASS_THROWN                        = 4  // OBSOLETE
};

#define MAX_ITEM_SUBCLASS_PROJECTILE              5

enum ItemSubclassTradeGoods
{
    ITEM_SUBCLASS_TRADE_GOODS                   = 0,
    ITEM_SUBCLASS_PARTS                         = 1,
    ITEM_SUBCLASS_EXPLOSIVES                    = 2,
    ITEM_SUBCLASS_DEVICES                       = 3,
    ITEM_SUBCLASS_JEWELCRAFTING                 = 4,
    ITEM_SUBCLASS_CLOTH                         = 5,
    ITEM_SUBCLASS_LEATHER                       = 6,
    ITEM_SUBCLASS_METAL_STONE                   = 7,
    ITEM_SUBCLASS_MEAT                          = 8,
    ITEM_SUBCLASS_HERB                          = 9,
    ITEM_SUBCLASS_ELEMENTAL                     = 10,
    ITEM_SUBCLASS_TRADE_GOODS_OTHER             = 11,
    ITEM_SUBCLASS_ENCHANTING                    = 12,
    ITEM_SUBCLASS_MATERIAL                      = 13,
    ITEM_SUBCLASS_ENCHANTMENT                   = 14,
    ITEM_SUBCLASS_WEAPON_ENCHANTMENT            = 15,
    ITEM_SUBCLASS_INSCRIPTION                   = 16,
    ITEM_SUBCLASS_EXPLOSIVES_DEVICES            = 17
};

#define MAX_ITEM_SUBCLASS_TRADE_GOODS             18

enum ItemSubclassItemEnhancement
{
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_HEAD                 = 0,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_NECK                 = 1,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_SHOULDER             = 2,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_CLOAK                = 3,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_CHEST                = 4,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_WRIST                = 5,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_HANDS                = 6,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_WAIST                = 7,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_LEGS                 = 8,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_FEET                 = 9,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_FINGER               = 10,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_WEAPON               = 11,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_TWO_HANDED_WEAPON    = 12,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT_SHIELD_OFF_HAND      = 13
};

#define MAX_ITEM_SUBCLASS_ITEM_ENHANCEMENT                14

enum ItemSubclassRecipe
{
    ITEM_SUBCLASS_BOOK                          = 0,
    ITEM_SUBCLASS_LEATHERWORKING_PATTERN        = 1,
    ITEM_SUBCLASS_TAILORING_PATTERN             = 2,
    ITEM_SUBCLASS_ENGINEERING_SCHEMATIC         = 3,
    ITEM_SUBCLASS_BLACKSMITHING                 = 4,
    ITEM_SUBCLASS_COOKING_RECIPE                = 5,
    ITEM_SUBCLASS_ALCHEMY_RECIPE                = 6,
    ITEM_SUBCLASS_FIRST_AID_MANUAL              = 7,
    ITEM_SUBCLASS_ENCHANTING_FORMULA            = 8,
    ITEM_SUBCLASS_FISHING_MANUAL                = 9,
    ITEM_SUBCLASS_JEWELCRAFTING_RECIPE          = 10,
    ITEM_SUBCLASS_INSCRIPTION_TECHNIQUE         = 11
};

#define MAX_ITEM_SUBCLASS_RECIPE                  12

enum ItemSubclassMoney
{
    ITEM_SUBCLASS_MONEY                         = 0,  // OBSOLETE
};

#define MAX_ITEM_SUBCLASS_MONEY                   1

enum ItemSubclassQuiver
{
    ITEM_SUBCLASS_QUIVER0                       = 0, // OBSOLETE
    ITEM_SUBCLASS_QUIVER1                       = 1, // OBSOLETE
    ITEM_SUBCLASS_QUIVER                        = 2,
    ITEM_SUBCLASS_AMMO_POUCH                    = 3
};

#define MAX_ITEM_SUBCLASS_QUIVER                  4

enum ItemSubclassQuest
{
    ITEM_SUBCLASS_QUEST                         = 0,
    ITEM_SUBCLASS_QUEST_UNK3                    = 3, // 1 item (33604)
    ITEM_SUBCLASS_QUEST_UNK8                    = 8, // 2 items (37445, 49700)
};

#define MAX_ITEM_SUBCLASS_QUEST                   9

enum ItemSubclassKey
{
    ITEM_SUBCLASS_KEY                           = 0,
    ITEM_SUBCLASS_LOCKPICK                      = 1
};

#define MAX_ITEM_SUBCLASS_KEY                     2

enum ItemSubclassPermanent
{
    ITEM_SUBCLASS_PERMANENT                     = 0
};

#define MAX_ITEM_SUBCLASS_PERMANENT               1

enum ItemSubclassJunk
{
    ITEM_SUBCLASS_MISCELLANEOUS_JUNK                 = 0,
    ITEM_SUBCLASS_MISCELLANEOUS_REAGENT         = 1,
    ITEM_SUBCLASS_MISCELLANEOUS_COMPANION_PET             = 2,
    ITEM_SUBCLASS_MISCELLANEOUS_HOLIDAY         = 3,
    ITEM_SUBCLASS_MISCELLANEOUS_OTHER           = 4,
    ITEM_SUBCLASS_MISCELLANEOUS_MOUNT           = 5,
};

#define MAX_ITEM_SUBCLASS_MISCELLANEOUS           6

enum ItemSubclassGlyph
{
    ITEM_SUBCLASS_GLYPH_WARRIOR                 = 1,
    ITEM_SUBCLASS_GLYPH_PALADIN                 = 2,
    ITEM_SUBCLASS_GLYPH_HUNTER                  = 3,
    ITEM_SUBCLASS_GLYPH_ROGUE                   = 4,
    ITEM_SUBCLASS_GLYPH_PRIEST                  = 5,
    ITEM_SUBCLASS_GLYPH_DEATH_KNIGHT            = 6,
    ITEM_SUBCLASS_GLYPH_SHAMAN                  = 7,
    ITEM_SUBCLASS_GLYPH_MAGE                    = 8,
    ITEM_SUBCLASS_GLYPH_WARLOCK                 = 9,
    ITEM_SUBCLASS_GLYPH_MONK                    = 10,
    ITEM_SUBCLASS_GLYPH_DRUID                   = 11,
    ITEM_SUBCLASS_GLYPH_DEMON_HUNTER            = 12
};

#define MAX_ITEM_SUBCLASS_GLYPH                   13

enum ItemSubclassBattlePet
{
    ITEM_SUBCLASS_BATTLE_PET                    = 0
};

#define MAX_ITEM_SUBCLASS_BATTLE_PET              1

enum ItemSubclassWowToken
{
    ITEM_SUBCLASS_WOW_TOKEN                     = 0
};

#define MAX_ITEM_SUBCLASS_WOW_TOKEN               1

const uint32 MaxItemSubclassValues[MAX_ITEM_CLASS] =
{
    MAX_ITEM_SUBCLASS_CONSUMABLE,
    MAX_ITEM_SUBCLASS_CONTAINER,
    MAX_ITEM_SUBCLASS_WEAPON,
    MAX_ITEM_SUBCLASS_GEM,
    MAX_ITEM_SUBCLASS_ARMOR,
    MAX_ITEM_SUBCLASS_REAGENT,
    MAX_ITEM_SUBCLASS_PROJECTILE,
    MAX_ITEM_SUBCLASS_TRADE_GOODS,
    MAX_ITEM_SUBCLASS_ITEM_ENHANCEMENT,
    MAX_ITEM_SUBCLASS_RECIPE,
    MAX_ITEM_SUBCLASS_MONEY,
    MAX_ITEM_SUBCLASS_QUIVER,
    MAX_ITEM_SUBCLASS_QUEST,
    MAX_ITEM_SUBCLASS_KEY,
    MAX_ITEM_SUBCLASS_PERMANENT,
    MAX_ITEM_SUBCLASS_MISCELLANEOUS,
    MAX_ITEM_SUBCLASS_GLYPH,
    MAX_ITEM_SUBCLASS_BATTLE_PET,
    MAX_ITEM_SUBCLASS_WOW_TOKEN
};

#define MAX_ITEM_SUBCLASS_TOTAL 21

enum ItemLevelConstants : uint32
{
    MIN_ITEM_LEVEL = 1,
    MAX_ITEM_LEVEL = 1300
};

class Player;
struct ChrSpecializationEntry;

struct TC_GAME_API ItemTemplate
{
    ItemEntry const* BasicData;
    ItemSparseEntry const* ExtendedData;

    uint32 GetId() const { return BasicData->ID; }
    uint32 GetClass() const { return BasicData->Class; }
    uint32 GetSubClass() const { return BasicData->SubClass; }
    uint32 GetQuality() const { return ExtendedData->Quality; }
    uint32 GetFlags() const { return ExtendedData->Flags[0]; }
    uint32 GetFlags2() const { return ExtendedData->Flags[1]; }
    uint32 GetFlags3() const { return ExtendedData->Flags[2]; }
    uint32 GetFlags4() const { return ExtendedData->Flags[3]; }
    float GetUnk1() const { return ExtendedData->Unk1; }
    float GetUnk2() const { return ExtendedData->Unk2; }
    uint32 GetBuyCount() const { return std::max<uint32>(ExtendedData->BuyCount, 1u); }
    uint32 GetBuyPrice() const { return ExtendedData->BuyPrice; }
    uint32 GetSellPrice() const { return ExtendedData->SellPrice; }
    InventoryType GetInventoryType() const { return InventoryType(ExtendedData->InventoryType); }
    int32 GetAllowableClass() const { return ExtendedData->AllowableClass; }
    int32 GetAllowableRace() const { return ExtendedData->AllowableRace; }
    uint32 GetBaseItemLevel() const { return ExtendedData->ItemLevel; }
    int32 GetBaseRequiredLevel() const { return ExtendedData->RequiredLevel; }
    uint32 GetRequiredSkill() const { return ExtendedData->RequiredSkill; }
    uint32 GetRequiredSkillRank() const { return ExtendedData->RequiredSkillRank; }
    uint32 GetRequiredSpell() const { return ExtendedData->RequiredSpell; }
    uint32 GetRequiredReputationFaction() const { return ExtendedData->RequiredReputationFaction; }
    uint32 GetRequiredReputationRank() const { return ExtendedData->RequiredReputationRank; }
    uint32 GetMaxCount() const { return ExtendedData->MaxCount; }
    uint32 GetContainerSlots() const { return ExtendedData->ContainerSlots; }
    int32 GetItemStatType(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_STATS); return ExtendedData->ItemStatType[index]; }
    int32 GetItemStatValue(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_STATS); return ExtendedData->ItemStatValue[index]; }
    int32 GetItemStatAllocation(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_STATS); return ExtendedData->ItemStatAllocation[index]; }
    float GetItemStatSocketCostMultiplier(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_STATS); return ExtendedData->ItemStatSocketCostMultiplier[index]; }
    uint32 GetScalingStatDistribution() const { return ExtendedData->ScalingStatDistribution; }
    uint32 GetDamageType() const { return ExtendedData->DamageType; }
    uint32 GetDelay() const { return ExtendedData->Delay; }
    float GetRangedModRange() const { return ExtendedData->RangedModRange; }
    ItemBondingType GetBonding() const { return ItemBondingType(ExtendedData->Bonding); }
    char const* GetName(LocaleConstant locale) const;
    uint32 GetPageText() const { return ExtendedData->PageText; }
    uint32 GetStartQuest() const { return ExtendedData->StartQuest; }
    uint32 GetLockID() const { return ExtendedData->LockID; }
    uint32 GetRandomProperty() const { return ExtendedData->RandomProperty; }
    uint32 GetRandomSuffix() const { return ExtendedData->RandomSuffix; }
    uint32 GetItemSet() const { return ExtendedData->ItemSet; }
    uint32 GetArea() const { return ExtendedData->Area; }
    uint32 GetMap() const { return ExtendedData->Map; }
    uint32 GetBagFamily() const { return ExtendedData->BagFamily; }
    uint32 GetTotemCategory() const { return ExtendedData->TotemCategory; }
    SocketColor GetSocketColor(uint32 index) const { ASSERT(index < MAX_ITEM_PROTO_SOCKETS); return SocketColor(ExtendedData->SocketColor[index]); }
    uint32 GetSocketBonus() const { return ExtendedData->SocketBonus; }
    uint32 GetGemProperties() const { return ExtendedData->GemProperties; }
    float GetArmorDamageModifier() const { return ExtendedData->ArmorDamageModifier; }
    uint32 GetDuration() const { return ExtendedData->Duration; }
    uint32 GetItemLimitCategory() const { return ExtendedData->ItemLimitCategory; }
    HolidayIds GetHolidayID() const { return HolidayIds(ExtendedData->HolidayID); }
    float  GetStatScalingFactor() const { return ExtendedData->StatScalingFactor; }
    uint8 GetArtifactID() const { return ExtendedData->ArtifactID; }

    uint32 MaxDurability;
    std::vector<ItemEffectEntry const*> Effects;

    // extra fields, not part of db2 files
    uint32 ScriptId;
    uint32 DisenchantID;
    uint32 RequiredDisenchantSkill;
    uint32 FoodType;
    uint32 MinMoneyLoot;
    uint32 MaxMoneyLoot;
    uint32 FlagsCu;
    float SpellPPMRate;
    std::bitset<MAX_CLASSES * MAX_SPECIALIZATIONS> Specializations[3];  // one set for 1-40 level range and another for 41-109 and one for 110
    uint32 ItemSpecClassMask;

    // helpers
    bool CanChangeEquipStateInCombat() const;

    bool IsCurrencyToken() const { return (GetBagFamily() & BAG_FAMILY_MASK_CURRENCY_TOKENS) != 0; }

    uint32 GetMaxStackSize() const
    {
        return (ExtendedData->Stackable == 2147483647 || ExtendedData->Stackable <= 0) ? uint32(0x7FFFFFFF - 1) : uint32(ExtendedData->Stackable);
    }

    uint32 GetSkill() const;

    bool IsPotion() const { return GetClass() == ITEM_CLASS_CONSUMABLE && GetSubClass() == ITEM_SUBCLASS_POTION; }
    bool IsVellum() const { return GetClass() == ITEM_CLASS_TRADE_GOODS && GetSubClass() == ITEM_SUBCLASS_ENCHANTMENT; }
    bool IsConjuredConsumable() const { return GetClass() == ITEM_CLASS_CONSUMABLE && (GetFlags() & ITEM_FLAG_CONJURED); }
    bool IsCraftingReagent() const { return (GetFlags2() & ITEM_FLAG2_USED_IN_A_TRADESKILL) != 0; }

    bool IsRangedWeapon() const
    {
        return GetClass() == ITEM_CLASS_WEAPON ||
               GetSubClass() == ITEM_SUBCLASS_WEAPON_BOW ||
               GetSubClass() == ITEM_SUBCLASS_WEAPON_GUN ||
               GetSubClass() == ITEM_SUBCLASS_WEAPON_CROSSBOW;
    }

    char const* GetDefaultLocaleName() const;
    uint32 GetArmor(uint32 itemLevel) const;
    void GetDamage(uint32 itemLevel, float& minDamage, float& maxDamage) const;
    bool IsUsableByLootSpecialization(Player const* player, bool alwaysAllowBoundToAccount) const;
    static std::size_t CalculateItemSpecBit(ChrSpecializationEntry const* spec);
};

#endif
