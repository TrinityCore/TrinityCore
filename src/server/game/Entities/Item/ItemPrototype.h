/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "SharedDefines.h"

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
    //ITEM_MOD_FERAL_ATTACK_POWER       = 40, not in 3.3
    ITEM_MOD_SPELL_HEALING_DONE       = 41,                 // deprecated
    ITEM_MOD_SPELL_DAMAGE_DONE        = 42,                 // deprecated
    ITEM_MOD_MANA_REGENERATION        = 43,
    ITEM_MOD_ARMOR_PENETRATION_RATING = 44,
    ITEM_MOD_SPELL_POWER              = 45,
    ITEM_MOD_HEALTH_REGEN             = 46,
    ITEM_MOD_SPELL_PENETRATION        = 47,
    ITEM_MOD_BLOCK_VALUE              = 48
};

#define MAX_ITEM_MOD                    49

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
    ITEM_SPELLTRIGGER_ON_NO_DELAY_USE = 5,                  // no equip cooldown
    ITEM_SPELLTRIGGER_LEARN_SPELL_ID  = 6                   // used in item_template.spell_2 with spell_id with SPELL_GENERIC_LEARN in spell_1
};

#define MAX_ITEM_SPELLTRIGGER           7

enum ItemBondingType
{
    NO_BIND                                     = 0,
    BIND_WHEN_PICKED_UP                         = 1,
    BIND_WHEN_EQUIPED                           = 2,
    BIND_WHEN_USE                               = 3,
    BIND_QUEST_ITEM                             = 4,
    BIND_QUEST_ITEM1                            = 5         // not used in game
};

#define MAX_BIND_TYPE                             6

/* /// @todo: Requiring actual cases in which using (an) item isn't allowed while shapeshifted. Else, this flag would need an implementation.
    ITEM_PROTO_FLAG_USABLE_WHEN_SHAPESHIFTED    = 0x00800000, // Item can be used in shapeshift forms */

enum ItemProtoFlags
{
    ITEM_PROTO_FLAG_UNK1                        = 0x00000001, // ?
    ITEM_PROTO_FLAG_CONJURED                    = 0x00000002, // Conjured item
    ITEM_PROTO_FLAG_OPENABLE                    = 0x00000004, // Item can be right clicked to open for loot
    ITEM_PROTO_FLAG_HEROIC                      = 0x00000008, // Makes green "Heroic" text appear on item
    ITEM_PROTO_FLAG_DEPRECATED                  = 0x00000010, // Cannot equip or use
    ITEM_PROTO_FLAG_INDESTRUCTIBLE              = 0x00000020, // Item can not be destroyed, except by using spell (item can be reagent for spell)
    ITEM_PROTO_FLAG_UNK2                        = 0x00000040, // ?
    ITEM_PROTO_FLAG_NO_EQUIP_COOLDOWN           = 0x00000080, // No default 30 seconds cooldown when equipped
    ITEM_PROTO_FLAG_UNK3                        = 0x00000100, // ?
    ITEM_PROTO_FLAG_WRAPPER                     = 0x00000200, // Item can wrap other items
    ITEM_PROTO_FLAG_UNK4                        = 0x00000400, // ?
    ITEM_PROTO_FLAG_PARTY_LOOT                  = 0x00000800, // Looting this item does not remove it from available loot
    ITEM_PROTO_FLAG_REFUNDABLE                  = 0x00001000, // Item can be returned to vendor for its original cost (extended cost)
    ITEM_PROTO_FLAG_CHARTER                     = 0x00002000, // Item is guild or arena charter
    ITEM_PROTO_FLAG_UNK5                        = 0x00004000, // Only readable items have this (but not all)
    ITEM_PROTO_FLAG_UNK6                        = 0x00008000, // ?
    ITEM_PROTO_FLAG_UNK7                        = 0x00010000, // ?
    ITEM_PROTO_FLAG_UNK8                        = 0x00020000, // ?
    ITEM_PROTO_FLAG_PROSPECTABLE                = 0x00040000, // Item can be prospected
    ITEM_PROTO_FLAG_UNIQUE_EQUIPPED             = 0x00080000, // You can only equip one of these
    ITEM_PROTO_FLAG_UNK9                        = 0x00100000, // ?
    ITEM_PROTO_FLAG_USEABLE_IN_ARENA            = 0x00200000, // Item can be used during arena match
    ITEM_PROTO_FLAG_THROWABLE                   = 0x00400000, // Some Thrown weapons have it (and only Thrown) but not all
    ITEM_PROTO_FLAG_USABLE_WHEN_SHAPESHIFTED    = 0x00800000, // Item can be used in shapeshift forms
    ITEM_PROTO_FLAG_UNK10                       = 0x01000000, // ?
    ITEM_PROTO_FLAG_SMART_LOOT                  = 0x02000000, // Profession recipes: can only be looted if you meet requirements and don't already know it
    ITEM_PROTO_FLAG_NOT_USEABLE_IN_ARENA        = 0x04000000, // Item cannot be used in arena
    ITEM_PROTO_FLAG_BIND_TO_ACCOUNT             = 0x08000000, // Item binds to account and can be sent only to your own characters
    ITEM_PROTO_FLAG_TRIGGERED_CAST              = 0x10000000, // Spell is cast with triggered flag
    ITEM_PROTO_FLAG_MILLABLE                    = 0x20000000, // Item can be milled
    ITEM_PROTO_FLAG_UNK11                       = 0x40000000, // ?
    ITEM_PROTO_FLAG_UNK12                       = 0x80000000  // ?
};

enum ItemFieldFlags
{
    ITEM_FLAG_SOULBOUND     = 0x00000001, // Item is soulbound and cannot be traded <<--
    ITEM_FLAG_UNK1          = 0x00000002, // ?
    ITEM_FLAG_UNLOCKED      = 0x00000004, // Item had lock but can be opened now
    ITEM_FLAG_WRAPPED       = 0x00000008, // Item is wrapped and contains another item
    ITEM_FLAG_UNK2          = 0x00000010, // ?
    ITEM_FLAG_UNK3          = 0x00000020, // ?
    ITEM_FLAG_UNK4          = 0x00000040, // ?
    ITEM_FLAG_UNK5          = 0x00000080, // ?
    ITEM_FLAG_BOP_TRADEABLE = 0x00000100, // Allows trading soulbound items
    ITEM_FLAG_READABLE      = 0x00000200, // Opens text page when right clicked
    ITEM_FLAG_UNK6          = 0x00000400, // ?
    ITEM_FLAG_UNK7          = 0x00000800, // ?
    ITEM_FLAG_REFUNDABLE    = 0x00001000, // Item can be returned to vendor for its original cost (extended cost)
    ITEM_FLAG_UNK8          = 0x00002000, // ?
    ITEM_FLAG_UNK9          = 0x00004000, // ?
    ITEM_FLAG_UNK10         = 0x00008000, // ?
    ITEM_FLAG_UNK11         = 0x00010000, // ?
    ITEM_FLAG_UNK12         = 0x00020000, // ?
    ITEM_FLAG_UNK13         = 0x00040000, // ?
    ITEM_FLAG_UNK14         = 0x00080000, // ?
    ITEM_FLAG_UNK15         = 0x00100000, // ?
    ITEM_FLAG_UNK16         = 0x00200000, // ?
    ITEM_FLAG_UNK17         = 0x00400000, // ?
    ITEM_FLAG_UNK18         = 0x00800000, // ?
    ITEM_FLAG_UNK19         = 0x01000000, // ?
    ITEM_FLAG_UNK20         = 0x02000000, // ?
    ITEM_FLAG_UNK21         = 0x04000000, // ?
    ITEM_FLAG_UNK22         = 0x08000000, // ?
    ITEM_FLAG_UNK23         = 0x10000000, // ?
    ITEM_FLAG_UNK24         = 0x20000000, // ?
    ITEM_FLAG_UNK25         = 0x40000000, // ?
    ITEM_FLAG_UNK26         = 0x80000000, // ?

    ITEM_FLAG_MAIL_TEXT_MASK = ITEM_FLAG_READABLE | ITEM_FLAG_UNK13 | ITEM_FLAG_UNK14
};

enum ItemFlagsExtra
{
    ITEM_FLAGS_EXTRA_HORDE_ONLY              = 0x00000001,
    ITEM_FLAGS_EXTRA_ALLIANCE_ONLY           = 0x00000002,
    ITEM_FLAGS_EXTRA_EXT_COST_REQUIRES_GOLD  = 0x00000004, // when item uses extended cost, gold is also required
    ITEM_FLAGS_EXTRA_NEED_ROLL_DISABLED      = 0x00000100
};

enum ItemFlagsCustom
{
    ITEM_FLAGS_CU_DURATION_REAL_TIME    = 0x0001,   // Item duration will tick even if player is offline
    ITEM_FLAGS_CU_IGNORE_QUEST_STATUS   = 0x0002,   // No quest status will be checked when this item drops
    ITEM_FLAGS_CU_FOLLOW_LOOT_RULES     = 0x0004    // Item will always follow group/master/need before greed looting rules
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
    BAG_FAMILY_MASK_QUEST_ITEMS               = 0x00004000
};

enum SocketColor
{
    SOCKET_COLOR_META                           = 1,
    SOCKET_COLOR_RED                            = 2,
    SOCKET_COLOR_YELLOW                         = 4,
    SOCKET_COLOR_BLUE                           = 8
};

#define SOCKET_COLOR_ALL (SOCKET_COLOR_META | SOCKET_COLOR_RED | SOCKET_COLOR_YELLOW | SOCKET_COLOR_BLUE)

enum InventoryType
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

enum ItemClass
{
    ITEM_CLASS_CONSUMABLE                       = 0,
    ITEM_CLASS_CONTAINER                        = 1,
    ITEM_CLASS_WEAPON                           = 2,
    ITEM_CLASS_GEM                              = 3,
    ITEM_CLASS_ARMOR                            = 4,
    ITEM_CLASS_REAGENT                          = 5,
    ITEM_CLASS_PROJECTILE                       = 6,
    ITEM_CLASS_TRADE_GOODS                      = 7,
    ITEM_CLASS_GENERIC                          = 8,
    ITEM_CLASS_RECIPE                           = 9,
    ITEM_CLASS_MONEY                            = 10,
    ITEM_CLASS_QUIVER                           = 11,
    ITEM_CLASS_QUEST                            = 12,
    ITEM_CLASS_KEY                              = 13,
    ITEM_CLASS_PERMANENT                        = 14,
    ITEM_CLASS_MISC                             = 15,
    ITEM_CLASS_GLYPH                            = 16
};

#define MAX_ITEM_CLASS                            17

enum ItemSubclassConsumable
{
    ITEM_SUBCLASS_CONSUMABLE                    = 0,
    ITEM_SUBCLASS_POTION                        = 1,
    ITEM_SUBCLASS_ELIXIR                        = 2,
    ITEM_SUBCLASS_FLASK                         = 3,
    ITEM_SUBCLASS_SCROLL                        = 4,
    ITEM_SUBCLASS_FOOD                          = 5,
    ITEM_SUBCLASS_ITEM_ENHANCEMENT              = 6,
    ITEM_SUBCLASS_BANDAGE                       = 7,
    ITEM_SUBCLASS_CONSUMABLE_OTHER              = 8
};

#define MAX_ITEM_SUBCLASS_CONSUMABLE              9

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
    ITEM_SUBCLASS_INSCRIPTION_CONTAINER         = 8
};

#define MAX_ITEM_SUBCLASS_CONTAINER               9

enum ItemSubclassWeapon
{
    ITEM_SUBCLASS_WEAPON_AXE                    = 0,
    ITEM_SUBCLASS_WEAPON_AXE2                   = 1,
    ITEM_SUBCLASS_WEAPON_BOW                    = 2,
    ITEM_SUBCLASS_WEAPON_GUN                    = 3,
    ITEM_SUBCLASS_WEAPON_MACE                   = 4,
    ITEM_SUBCLASS_WEAPON_MACE2                  = 5,
    ITEM_SUBCLASS_WEAPON_POLEARM                = 6,
    ITEM_SUBCLASS_WEAPON_SWORD                  = 7,
    ITEM_SUBCLASS_WEAPON_SWORD2                 = 8,
    ITEM_SUBCLASS_WEAPON_obsolete               = 9,
    ITEM_SUBCLASS_WEAPON_STAFF                  = 10,
    ITEM_SUBCLASS_WEAPON_EXOTIC                 = 11,
    ITEM_SUBCLASS_WEAPON_EXOTIC2                = 12,
    ITEM_SUBCLASS_WEAPON_FIST                   = 13,
    ITEM_SUBCLASS_WEAPON_MISC                   = 14,
    ITEM_SUBCLASS_WEAPON_DAGGER                 = 15,
    ITEM_SUBCLASS_WEAPON_THROWN                 = 16,
    ITEM_SUBCLASS_WEAPON_SPEAR                  = 17,
    ITEM_SUBCLASS_WEAPON_CROSSBOW               = 18,
    ITEM_SUBCLASS_WEAPON_WAND                   = 19,
    ITEM_SUBCLASS_WEAPON_FISHING_POLE           = 20
};

#define ITEM_SUBCLASS_MASK_WEAPON_RANGED (\
    (1 << ITEM_SUBCLASS_WEAPON_BOW) | (1 << ITEM_SUBCLASS_WEAPON_GUN) |\
    (1 << ITEM_SUBCLASS_WEAPON_CROSSBOW) | (1 << ITEM_SUBCLASS_WEAPON_THROWN))

#define MAX_ITEM_SUBCLASS_WEAPON                  21

enum ItemSubclassGem
{
    ITEM_SUBCLASS_GEM_RED                       = 0,
    ITEM_SUBCLASS_GEM_BLUE                      = 1,
    ITEM_SUBCLASS_GEM_YELLOW                    = 2,
    ITEM_SUBCLASS_GEM_PURPLE                    = 3,
    ITEM_SUBCLASS_GEM_GREEN                     = 4,
    ITEM_SUBCLASS_GEM_ORANGE                    = 5,
    ITEM_SUBCLASS_GEM_META                      = 6,
    ITEM_SUBCLASS_GEM_SIMPLE                    = 7,
    ITEM_SUBCLASS_GEM_PRISMATIC                 = 8
};

#define MAX_ITEM_SUBCLASS_GEM                     9

enum ItemSubclassArmor
{
    ITEM_SUBCLASS_ARMOR_MISC                    = 0,
    ITEM_SUBCLASS_ARMOR_CLOTH                   = 1,
    ITEM_SUBCLASS_ARMOR_LEATHER                 = 2,
    ITEM_SUBCLASS_ARMOR_MAIL                    = 3,
    ITEM_SUBCLASS_ARMOR_PLATE                   = 4,
    ITEM_SUBCLASS_ARMOR_BUCKLER                 = 5,
    ITEM_SUBCLASS_ARMOR_SHIELD                  = 6,
    ITEM_SUBCLASS_ARMOR_LIBRAM                  = 7,
    ITEM_SUBCLASS_ARMOR_IDOL                    = 8,
    ITEM_SUBCLASS_ARMOR_TOTEM                   = 9,
    ITEM_SUBCLASS_ARMOR_SIGIL                   = 10
};

#define MAX_ITEM_SUBCLASS_ARMOR                   11

enum ItemSubclassReagent
{
    ITEM_SUBCLASS_REAGENT                       = 0
};

#define MAX_ITEM_SUBCLASS_REAGENT                 1

enum ItemSubclassProjectile
{
    ITEM_SUBCLASS_WAND                          = 0,        // ABS
    ITEM_SUBCLASS_BOLT                          = 1,        // ABS
    ITEM_SUBCLASS_ARROW                         = 2,
    ITEM_SUBCLASS_BULLET                        = 3,
    ITEM_SUBCLASS_THROWN                        = 4         // ABS
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
    ITEM_SUBCLASS_ARMOR_ENCHANTMENT             = 14,
    ITEM_SUBCLASS_WEAPON_ENCHANTMENT            = 15
};

#define MAX_ITEM_SUBCLASS_TRADE_GOODS             16

enum ItemSubclassGeneric
{
    ITEM_SUBCLASS_GENERIC                       = 0
};

#define MAX_ITEM_SUBCLASS_GENERIC                 1

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
    ITEM_SUBCLASS_JEWELCRAFTING_RECIPE          = 10
};

#define MAX_ITEM_SUBCLASS_RECIPE                  11

enum ItemSubclassMoney
{
    ITEM_SUBCLASS_MONEY                         = 0
};

#define MAX_ITEM_SUBCLASS_MONEY                   1

enum ItemSubclassQuiver
{
    ITEM_SUBCLASS_QUIVER0                       = 0,        // ABS
    ITEM_SUBCLASS_QUIVER1                       = 1,        // ABS
    ITEM_SUBCLASS_QUIVER                        = 2,
    ITEM_SUBCLASS_AMMO_POUCH                    = 3
};

#define MAX_ITEM_SUBCLASS_QUIVER                  4

enum ItemSubclassQuest
{
    ITEM_SUBCLASS_QUEST                         = 0
};

#define MAX_ITEM_SUBCLASS_QUEST                   1

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
    ITEM_SUBCLASS_JUNK                          = 0,
    ITEM_SUBCLASS_JUNK_REAGENT                  = 1,
    ITEM_SUBCLASS_JUNK_PET                      = 2,
    ITEM_SUBCLASS_JUNK_HOLIDAY                  = 3,
    ITEM_SUBCLASS_JUNK_OTHER                    = 4,
    ITEM_SUBCLASS_JUNK_MOUNT                    = 5
};

#define MAX_ITEM_SUBCLASS_JUNK                    6

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
    ITEM_SUBCLASS_GLYPH_DRUID                   = 11
};

#define MAX_ITEM_SUBCLASS_GLYPH                   12

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
    MAX_ITEM_SUBCLASS_GENERIC,
    MAX_ITEM_SUBCLASS_RECIPE,
    MAX_ITEM_SUBCLASS_MONEY,
    MAX_ITEM_SUBCLASS_QUIVER,
    MAX_ITEM_SUBCLASS_QUEST,
    MAX_ITEM_SUBCLASS_KEY,
    MAX_ITEM_SUBCLASS_PERMANENT,
    MAX_ITEM_SUBCLASS_JUNK,
    MAX_ITEM_SUBCLASS_GLYPH
};

inline uint8 ItemSubClassToDurabilityMultiplierId(uint32 ItemClass, uint32 ItemSubClass)
{
    switch (ItemClass)
    {
        case ITEM_CLASS_WEAPON: return ItemSubClass;
        case ITEM_CLASS_ARMOR:  return ItemSubClass + 21;
    }
    return 0;
}

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push, N), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

struct _Damage
{
    float   DamageMin;
    float   DamageMax;
    uint32  DamageType;                                     // id from Resistances.dbc
};

struct _ItemStat
{
    uint32  ItemStatType;
    int32   ItemStatValue;
};
struct _Spell
{
    int32 SpellId;                                         // id from Spell.dbc
    uint32 SpellTrigger;
    int32  SpellCharges;
    float  SpellPPMRate;
    int32  SpellCooldown;
    uint32 SpellCategory;                                   // id from SpellCategory.dbc
    int32  SpellCategoryCooldown;
};

struct _Socket
{
    uint32 Color;
    uint32 Content;
};

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

#define MAX_ITEM_PROTO_DAMAGES 2                            // changed in 3.1.0
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_SPELLS  5
#define MAX_ITEM_PROTO_STATS  10

struct ItemTemplate
{
    uint32 ItemId;
    uint32 Class;                                           // id from ItemClass.dbc
    uint32 SubClass;                                        // id from ItemSubClass.dbc
    int32  SoundOverrideSubclass;                           // < 0: id from ItemSubClass.dbc, used to override weapon sound from actual SubClass
    std::string Name1;
    uint32 DisplayInfoID;                                   // id from ItemDisplayInfo.dbc
    uint32 Quality;
    uint32 Flags;
    uint32 Flags2;
    uint32 BuyCount;
    int32  BuyPrice;
    uint32 SellPrice;
    uint32 InventoryType;
    uint32 AllowableClass;
    uint32 AllowableRace;
    uint32 ItemLevel;
    uint32 RequiredLevel;
    uint32 RequiredSkill;                                   // id from SkillLine.dbc
    uint32 RequiredSkillRank;
    uint32 RequiredSpell;                                   // id from Spell.dbc
    uint32 RequiredHonorRank;
    uint32 RequiredCityRank;
    uint32 RequiredReputationFaction;                       // id from Faction.dbc
    uint32 RequiredReputationRank;
    int32  MaxCount;                                        // <= 0: no limit
    int32  Stackable;                                       // 0: not allowed, -1: put in player coin info tab and don't limit stacking (so 1 slot)
    uint32 ContainerSlots;
    uint32 StatsCount;
    _ItemStat ItemStat[MAX_ITEM_PROTO_STATS];
    uint32 ScalingStatDistribution;                         // id from ScalingStatDistribution.dbc
    uint32 ScalingStatValue;                                // mask for selecting column in ScalingStatValues.dbc
    _Damage Damage[MAX_ITEM_PROTO_DAMAGES];
    uint32 Armor;
    uint32 HolyRes;
    uint32 FireRes;
    uint32 NatureRes;
    uint32 FrostRes;
    uint32 ShadowRes;
    uint32 ArcaneRes;
    uint32 Delay;
    uint32 AmmoType;
    float  RangedModRange;
    _Spell Spells[MAX_ITEM_PROTO_SPELLS];
    uint32 Bonding;
    std::string  Description;
    uint32 PageText;
    uint32 LanguageID;
    uint32 PageMaterial;
    uint32 StartQuest;                                      // id from QuestCache.wdb
    uint32 LockID;
    int32  Material;                                        // id from Material.dbc
    uint32 Sheath;
    int32  RandomProperty;                                  // id from ItemRandomProperties.dbc
    int32  RandomSuffix;                                    // id from ItemRandomSuffix.dbc
    uint32 Block;
    uint32 ItemSet;                                         // id from ItemSet.dbc
    uint32 MaxDurability;
    uint32 Area;                                            // id from AreaTable.dbc
    uint32 Map;                                             // id from Map.dbc
    uint32 BagFamily;                                       // bit mask (1 << id from ItemBagFamily.dbc)
    uint32 TotemCategory;                                   // id from TotemCategory.dbc
    _Socket Socket[MAX_ITEM_PROTO_SOCKETS];
    uint32 socketBonus;                                     // id from SpellItemEnchantment.dbc
    uint32 GemProperties;                                   // id from GemProperties.dbc
    uint32 RequiredDisenchantSkill;
    float  ArmorDamageModifier;
    uint32 Duration;
    uint32 ItemLimitCategory;                               // id from ItemLimitCategory.dbc
    uint32 HolidayId;                                       // id from Holidays.dbc
    uint32 ScriptId;
    uint32 DisenchantID;
    uint32 FoodType;
    uint32 MinMoneyLoot;
    uint32 MaxMoneyLoot;
    uint32 FlagsCu;

    // helpers
    bool CanChangeEquipStateInCombat() const
    {
        switch (InventoryType)
        {
            case INVTYPE_RELIC:
            case INVTYPE_SHIELD:
            case INVTYPE_HOLDABLE:
                return true;
        }

        switch (Class)
        {
            case ITEM_CLASS_WEAPON:
            case ITEM_CLASS_PROJECTILE:
                return true;
        }

        return false;
    }

    bool IsCurrencyToken() const { return BagFamily & BAG_FAMILY_MASK_CURRENCY_TOKENS; }

    uint32 GetMaxStackSize() const
    {
        return (Stackable == 2147483647 || Stackable <= 0) ? uint32(0x7FFFFFFF-1) : uint32(Stackable);
    }

    float getDPS() const
    {
        if (Delay == 0)
            return 0;
        float temp = 0;
        for (int i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            temp+=Damage[i].DamageMin + Damage[i].DamageMax;
        return temp*500/Delay;
    }

    int32 getFeralBonus(int32 extraDPS = 0) const
    {
        // 0x02A5F3 - is mask for Melee weapon from ItemSubClassMask.dbc
        if (Class == ITEM_CLASS_WEAPON && (1<<SubClass)&0x02A5F3)
        {
            int32 bonus = int32((extraDPS + getDPS())*14.0f) - 767;
            if (bonus < 0)
                return 0;
            return bonus;
        }
        return 0;
    }

    float GetItemLevelIncludingQuality() const
    {
        float itemLevel = (float)ItemLevel;
        switch (Quality)
        {
            case ITEM_QUALITY_POOR:
            case ITEM_QUALITY_NORMAL:
            case ITEM_QUALITY_UNCOMMON:
            case ITEM_QUALITY_ARTIFACT:
            case ITEM_QUALITY_HEIRLOOM:
                itemLevel -= 13; // leaving this as a separate statement since we do not know the real behavior in this case
                break;
            case ITEM_QUALITY_RARE:
                itemLevel -= 13;
                break;
            case ITEM_QUALITY_EPIC:
            case ITEM_QUALITY_LEGENDARY:
            default:
                break;
        }
        return itemLevel;
    }

    bool IsPotion() const { return Class == ITEM_CLASS_CONSUMABLE && SubClass == ITEM_SUBCLASS_POTION; }
    bool IsWeaponVellum() const { return Class == ITEM_CLASS_TRADE_GOODS && SubClass == ITEM_SUBCLASS_WEAPON_ENCHANTMENT; }
    bool IsArmorVellum() const { return Class == ITEM_CLASS_TRADE_GOODS && SubClass == ITEM_SUBCLASS_ARMOR_ENCHANTMENT; }
    bool IsConjuredConsumable() const { return Class == ITEM_CLASS_CONSUMABLE && (Flags & ITEM_PROTO_FLAG_CONJURED); }
};

// Benchmarked: Faster than std::map (insert/find)
typedef UNORDERED_MAP<uint32, ItemTemplate> ItemTemplateContainer;

struct ItemLocale
{
    StringVector Name;
    StringVector Description;
};

struct ItemSetNameEntry
{
    std::string name;
    uint32 InventoryType;
};

struct ItemSetNameLocale
{
    StringVector Name;
};

#endif
