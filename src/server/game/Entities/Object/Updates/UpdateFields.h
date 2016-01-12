/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _UPDATEFIELDS_H
#define _UPDATEFIELDS_H

// Auto generated for version 4, 3, 4, 15595

enum EObjectFields
{
    OBJECT_FIELD_GUID                                = 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    OBJECT_FIELD_DATA                                = 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    OBJECT_FIELD_TYPE                                = 0x0004, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    OBJECT_FIELD_ENTRY                               = 0x0005, // Size: 1, Type: INT, Flags: PUBLIC
    OBJECT_FIELD_SCALE_X                             = 0x0006, // Size: 1, Type: FLOAT, Flags: PUBLIC
    OBJECT_FIELD_PADDING                             = 0x0007, // Size: 1, Type: INT, Flags: NONE
    OBJECT_END                                       = 0x0008
};

enum EItemFields
{
    ITEM_FIELD_OWNER                                 = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_CONTAINED                             = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_CREATOR                               = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_GIFTCREATOR                           = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_STACK_COUNT                           = OBJECT_END + 0x0008, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_DURATION                              = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_SPELL_CHARGES                         = OBJECT_END + 0x000A, // Size: 5, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_FLAGS                                 = OBJECT_END + 0x000F, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_1_1                       = OBJECT_END + 0x0010, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_1_3                       = OBJECT_END + 0x0012, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_2_1                       = OBJECT_END + 0x0013, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_2_3                       = OBJECT_END + 0x0015, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_3_1                       = OBJECT_END + 0x0016, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_3_3                       = OBJECT_END + 0x0018, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_4_1                       = OBJECT_END + 0x0019, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_4_3                       = OBJECT_END + 0x001B, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_5_1                       = OBJECT_END + 0x001C, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_5_3                       = OBJECT_END + 0x001E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_6_1                       = OBJECT_END + 0x001F, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_6_3                       = OBJECT_END + 0x0021, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_7_1                       = OBJECT_END + 0x0022, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_7_3                       = OBJECT_END + 0x0024, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_8_1                       = OBJECT_END + 0x0025, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_8_3                       = OBJECT_END + 0x0027, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_9_1                       = OBJECT_END + 0x0028, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_9_3                       = OBJECT_END + 0x002A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_10_1                      = OBJECT_END + 0x002B, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_10_3                      = OBJECT_END + 0x002D, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_11_1                      = OBJECT_END + 0x002E, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_11_3                      = OBJECT_END + 0x0030, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_12_1                      = OBJECT_END + 0x0031, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_12_3                      = OBJECT_END + 0x0033, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_13_1                      = OBJECT_END + 0x0034, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_13_3                      = OBJECT_END + 0x0036, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_14_1                      = OBJECT_END + 0x0037, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_14_3                      = OBJECT_END + 0x0039, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_15_1                      = OBJECT_END + 0x003A, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_15_3                      = OBJECT_END + 0x003C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_PROPERTY_SEED                         = OBJECT_END + 0x003D, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID                  = OBJECT_END + 0x003E, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_DURABILITY                            = OBJECT_END + 0x003F, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_MAXDURABILITY                         = OBJECT_END + 0x0040, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_CREATE_PLAYED_TIME                    = OBJECT_END + 0x0041, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_END                                         = OBJECT_END + 0x0042,
};

enum EContainerFields
{
    CONTAINER_FIELD_NUM_SLOTS                        = ITEM_END + 0x0000, // Size: 1, Type: INT, Flags: PUBLIC
    CONTAINER_ALIGN_PAD                              = ITEM_END + 0x0001, // Size: 1, Type: BYTES, Flags: NONE
    CONTAINER_FIELD_SLOT_1                           = ITEM_END + 0x0002, // Size: 72, Type: LONG, Flags: PUBLIC
    CONTAINER_END                                    = ITEM_END + 0x004A
};

enum EUnitFields
{
    UNIT_FIELD_CHARM                                 = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_SUMMON                                = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CRITTER                               = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PRIVATE
    UNIT_FIELD_CHARMEDBY                             = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_SUMMONEDBY                            = OBJECT_END + 0x0008, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CREATEDBY                             = OBJECT_END + 0x000A, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_TARGET                                = OBJECT_END + 0x000C, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CHANNEL_OBJECT                        = OBJECT_END + 0x000E, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_CHANNEL_SPELL                               = OBJECT_END + 0x0010, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BYTES_0                               = OBJECT_END + 0x0011, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_HEALTH                                = OBJECT_END + 0x0012, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER1                                = OBJECT_END + 0x0013, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER2                                = OBJECT_END + 0x0014, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER3                                = OBJECT_END + 0x0015, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER4                                = OBJECT_END + 0x0016, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER5                                = OBJECT_END + 0x0017, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXHEALTH                             = OBJECT_END + 0x0018, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER1                             = OBJECT_END + 0x0019, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER2                             = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER3                             = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER4                             = OBJECT_END + 0x001C, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER5                             = OBJECT_END + 0x001D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER             = OBJECT_END + 0x001E, // Size: 5, Type: FLOAT, Flags: PRIVATE, OWNER, UNUSED2
    UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER = OBJECT_END + 0x0023, // Size: 5, Type: FLOAT, Flags: PRIVATE, OWNER, UNUSED2
    UNIT_FIELD_LEVEL                                 = OBJECT_END + 0x0028, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                       = OBJECT_END + 0x0029, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_ID                        = OBJECT_END + 0x002A, // Size: 3, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FLAGS                                 = OBJECT_END + 0x002D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FLAGS_2                               = OBJECT_END + 0x002E, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_AURASTATE                             = OBJECT_END + 0x002F, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                        = OBJECT_END + 0x0030, // Size: 2, Type: INT, Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME                      = OBJECT_END + 0x0032, // Size: 1, Type: INT, Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                        = OBJECT_END + 0x0033, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                           = OBJECT_END + 0x0034, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                             = OBJECT_END + 0x0035, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_FIELD_NATIVEDISPLAYID                       = OBJECT_END + 0x0036, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MOUNTDISPLAYID                        = OBJECT_END + 0x0037, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MINDAMAGE                             = OBJECT_END + 0x0038, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXDAMAGE                             = OBJECT_END + 0x0039, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MINOFFHANDDAMAGE                      = OBJECT_END + 0x003A, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXOFFHANDDAMAGE                      = OBJECT_END + 0x003B, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_BYTES_1                               = OBJECT_END + 0x003C, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                             = OBJECT_END + 0x003D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP                    = OBJECT_END + 0x003E, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                         = OBJECT_END + 0x003F, // Size: 1, Type: INT, Flags: OWNER
    UNIT_FIELD_PETNEXTLEVELEXP                       = OBJECT_END + 0x0040, // Size: 1, Type: INT, Flags: OWNER
    UNIT_DYNAMIC_FLAGS                               = OBJECT_END + 0x0041, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_MOD_CAST_SPEED                              = OBJECT_END + 0x0042, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_MOD_CAST_HASTE                              = OBJECT_END + 0x0043, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                            = OBJECT_END + 0x0044, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_NPC_FLAGS                                   = OBJECT_END + 0x0045, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_NPC_EMOTESTATE                              = OBJECT_END + 0x0046, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_STAT0                                 = OBJECT_END + 0x0047, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT1                                 = OBJECT_END + 0x0048, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT2                                 = OBJECT_END + 0x0049, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT3                                 = OBJECT_END + 0x004A, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT4                                 = OBJECT_END + 0x004B, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT0                              = OBJECT_END + 0x004C, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT1                              = OBJECT_END + 0x004D, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT2                              = OBJECT_END + 0x004E, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT3                              = OBJECT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT4                              = OBJECT_END + 0x0050, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT0                              = OBJECT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT1                              = OBJECT_END + 0x0052, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT2                              = OBJECT_END + 0x0053, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT3                              = OBJECT_END + 0x0054, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT4                              = OBJECT_END + 0x0055, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCES                           = OBJECT_END + 0x0056, // Size: 7, Type: INT, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE            = OBJECT_END + 0x005D, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE            = OBJECT_END + 0x0064, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_BASE_MANA                             = OBJECT_END + 0x006B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASE_HEALTH                           = OBJECT_END + 0x006C, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_BYTES_2                               = OBJECT_END + 0x006D, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_ATTACK_POWER                          = OBJECT_END + 0x006E, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_POS                  = OBJECT_END + 0x006F, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_NEG                  = OBJECT_END + 0x0070, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER               = OBJECT_END + 0x0071, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER                   = OBJECT_END + 0x0072, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_POS           = OBJECT_END + 0x0073, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_NEG           = OBJECT_END + 0x0074, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER        = OBJECT_END + 0x0075, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MINRANGEDDAMAGE                       = OBJECT_END + 0x0076, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXRANGEDDAMAGE                       = OBJECT_END + 0x0077, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MODIFIER                   = OBJECT_END + 0x0078, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MULTIPLIER                 = OBJECT_END + 0x007F, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXHEALTHMODIFIER                     = OBJECT_END + 0x0086, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_HOVERHEIGHT                           = OBJECT_END + 0x0087, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_MAXITEMLEVEL                          = OBJECT_END + 0x0088, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PADDING                               = OBJECT_END + 0x0089, // Size: 1, Type: INT, Flags: NONE
    UNIT_END                                         = OBJECT_END + 0x008A
};

enum EPlayerFields
{
    PLAYER_DUEL_ARBITER                              = UNIT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_FLAGS                                     = UNIT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDRANK                                 = UNIT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDDELETE_DATE                          = UNIT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDLEVEL                                = UNIT_END + 0x0005, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_BYTES                                     = UNIT_END + 0x0006, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_2                                   = UNIT_END + 0x0007, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_3                                   = UNIT_END + 0x0008, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_DUEL_TEAM                                 = UNIT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                           = UNIT_END + 0x000A, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_QUEST_LOG_1_1                             = UNIT_END + 0x000B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_1_2                             = UNIT_END + 0x000C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_1_3                             = UNIT_END + 0x000D, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_1_4                             = UNIT_END + 0x000F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_2_1                             = UNIT_END + 0x0010, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_2_2                             = UNIT_END + 0x0011, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_2_3                             = UNIT_END + 0x0012, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_2_5                             = UNIT_END + 0x0014, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_3_1                             = UNIT_END + 0x0015, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_3_2                             = UNIT_END + 0x0016, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_3_3                             = UNIT_END + 0x0017, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_3_5                             = UNIT_END + 0x0019, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_4_1                             = UNIT_END + 0x001A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_4_2                             = UNIT_END + 0x001B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_4_3                             = UNIT_END + 0x001C, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_4_5                             = UNIT_END + 0x001E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_5_1                             = UNIT_END + 0x001F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_5_2                             = UNIT_END + 0x0020, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_5_3                             = UNIT_END + 0x0021, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_5_5                             = UNIT_END + 0x0023, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_6_1                             = UNIT_END + 0x0024, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_6_2                             = UNIT_END + 0x0025, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_6_3                             = UNIT_END + 0x0026, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_6_5                             = UNIT_END + 0x0028, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_7_1                             = UNIT_END + 0x0029, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_7_2                             = UNIT_END + 0x002A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_7_3                             = UNIT_END + 0x002B, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_7_5                             = UNIT_END + 0x002D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_8_1                             = UNIT_END + 0x002E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_8_2                             = UNIT_END + 0x002F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_8_3                             = UNIT_END + 0x0030, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_8_5                             = UNIT_END + 0x0032, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_9_1                             = UNIT_END + 0x0033, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_9_2                             = UNIT_END + 0x0034, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_9_3                             = UNIT_END + 0x0035, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_9_5                             = UNIT_END + 0x0037, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_10_1                            = UNIT_END + 0x0038, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_10_2                            = UNIT_END + 0x0039, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_10_3                            = UNIT_END + 0x003A, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_10_5                            = UNIT_END + 0x003C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_11_1                            = UNIT_END + 0x003D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_11_2                            = UNIT_END + 0x003E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_11_3                            = UNIT_END + 0x003F, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_11_5                            = UNIT_END + 0x0041, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_12_1                            = UNIT_END + 0x0042, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_12_2                            = UNIT_END + 0x0043, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_12_3                            = UNIT_END + 0x0044, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_12_5                            = UNIT_END + 0x0046, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_13_1                            = UNIT_END + 0x0047, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_13_2                            = UNIT_END + 0x0048, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_13_3                            = UNIT_END + 0x0049, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_13_5                            = UNIT_END + 0x004B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_14_1                            = UNIT_END + 0x004C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_14_2                            = UNIT_END + 0x004D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_14_3                            = UNIT_END + 0x004E, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_14_5                            = UNIT_END + 0x0050, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_15_1                            = UNIT_END + 0x0051, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_15_2                            = UNIT_END + 0x0052, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_15_3                            = UNIT_END + 0x0053, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_15_5                            = UNIT_END + 0x0055, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_16_1                            = UNIT_END + 0x0056, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_16_2                            = UNIT_END + 0x0057, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_16_3                            = UNIT_END + 0x0058, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_16_5                            = UNIT_END + 0x005A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_17_1                            = UNIT_END + 0x005B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_17_2                            = UNIT_END + 0x005C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_17_3                            = UNIT_END + 0x005D, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_17_5                            = UNIT_END + 0x005F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_18_1                            = UNIT_END + 0x0060, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_18_2                            = UNIT_END + 0x0061, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_18_3                            = UNIT_END + 0x0062, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_18_5                            = UNIT_END + 0x0064, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_19_1                            = UNIT_END + 0x0065, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_19_2                            = UNIT_END + 0x0066, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_19_3                            = UNIT_END + 0x0067, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_19_5                            = UNIT_END + 0x0069, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_20_1                            = UNIT_END + 0x006A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_20_2                            = UNIT_END + 0x006B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_20_3                            = UNIT_END + 0x006C, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_20_5                            = UNIT_END + 0x006E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_21_1                            = UNIT_END + 0x006F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_21_2                            = UNIT_END + 0x0070, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_21_3                            = UNIT_END + 0x0071, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_21_5                            = UNIT_END + 0x0073, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_22_1                            = UNIT_END + 0x0074, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_22_2                            = UNIT_END + 0x0075, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_22_3                            = UNIT_END + 0x0076, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_22_5                            = UNIT_END + 0x0078, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_23_1                            = UNIT_END + 0x0079, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_23_2                            = UNIT_END + 0x007A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_23_3                            = UNIT_END + 0x007B, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_23_5                            = UNIT_END + 0x007D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_24_1                            = UNIT_END + 0x007E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_24_2                            = UNIT_END + 0x007F, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_24_3                            = UNIT_END + 0x0080, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_24_5                            = UNIT_END + 0x0082, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_25_1                            = UNIT_END + 0x0083, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_25_2                            = UNIT_END + 0x0084, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_25_3                            = UNIT_END + 0x0085, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_25_5                            = UNIT_END + 0x0087, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_26_1                            = UNIT_END + 0x0088, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_26_2                            = UNIT_END + 0x0089, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_26_3                            = UNIT_END + 0x008A, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_26_5                            = UNIT_END + 0x008C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_27_1                            = UNIT_END + 0x008D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_27_2                            = UNIT_END + 0x008E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_27_3                            = UNIT_END + 0x008F, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_27_5                            = UNIT_END + 0x0091, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_28_1                            = UNIT_END + 0x0092, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_28_2                            = UNIT_END + 0x0093, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_28_3                            = UNIT_END + 0x0094, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_28_5                            = UNIT_END + 0x0096, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_29_1                            = UNIT_END + 0x0097, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_29_2                            = UNIT_END + 0x0098, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_29_3                            = UNIT_END + 0x0099, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_29_5                            = UNIT_END + 0x009B, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_30_1                            = UNIT_END + 0x009C, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_30_2                            = UNIT_END + 0x009D, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_30_3                            = UNIT_END + 0x009E, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_30_5                            = UNIT_END + 0x00A0, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_31_1                            = UNIT_END + 0x00A1, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_31_2                            = UNIT_END + 0x00A2, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_31_3                            = UNIT_END + 0x00A3, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_31_5                            = UNIT_END + 0x00A5, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_32_1                            = UNIT_END + 0x00A6, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_32_2                            = UNIT_END + 0x00A7, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_32_3                            = UNIT_END + 0x00A8, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_32_5                            = UNIT_END + 0x00AA, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_33_1                            = UNIT_END + 0x00AB, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_33_2                            = UNIT_END + 0x00AC, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_33_3                            = UNIT_END + 0x00AD, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_33_5                            = UNIT_END + 0x00AF, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_34_1                            = UNIT_END + 0x00B0, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_34_2                            = UNIT_END + 0x00B1, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_34_3                            = UNIT_END + 0x00B2, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_34_5                            = UNIT_END + 0x00B4, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_35_1                            = UNIT_END + 0x00B5, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_35_2                            = UNIT_END + 0x00B6, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_35_3                            = UNIT_END + 0x00B7, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_35_5                            = UNIT_END + 0x00B9, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_36_1                            = UNIT_END + 0x00BA, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_36_2                            = UNIT_END + 0x00BB, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_36_3                            = UNIT_END + 0x00BC, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_36_5                            = UNIT_END + 0x00BE, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_37_1                            = UNIT_END + 0x00BF, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_37_2                            = UNIT_END + 0x00C0, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_37_3                            = UNIT_END + 0x00C1, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_37_5                            = UNIT_END + 0x00C3, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_38_1                            = UNIT_END + 0x00C4, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_38_2                            = UNIT_END + 0x00C5, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_38_3                            = UNIT_END + 0x00C6, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_38_5                            = UNIT_END + 0x00C8, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_39_1                            = UNIT_END + 0x00C9, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_39_2                            = UNIT_END + 0x00CA, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_39_3                            = UNIT_END + 0x00CB, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_39_5                            = UNIT_END + 0x00CD, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_40_1                            = UNIT_END + 0x00CE, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_40_2                            = UNIT_END + 0x00CF, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_40_3                            = UNIT_END + 0x00D0, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_40_5                            = UNIT_END + 0x00D2, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_41_1                            = UNIT_END + 0x00D3, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_41_2                            = UNIT_END + 0x00D4, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_41_3                            = UNIT_END + 0x00D5, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_41_5                            = UNIT_END + 0x00D7, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_42_1                            = UNIT_END + 0x00D8, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_42_2                            = UNIT_END + 0x00D9, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_42_3                            = UNIT_END + 0x00DA, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_42_5                            = UNIT_END + 0x00DC, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_43_1                            = UNIT_END + 0x00DD, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_43_2                            = UNIT_END + 0x00DE, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_43_3                            = UNIT_END + 0x00DF, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_43_5                            = UNIT_END + 0x00E1, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_44_1                            = UNIT_END + 0x00E2, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_44_2                            = UNIT_END + 0x00E3, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_44_3                            = UNIT_END + 0x00E4, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_44_5                            = UNIT_END + 0x00E6, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_45_1                            = UNIT_END + 0x00E7, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_45_2                            = UNIT_END + 0x00E8, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_45_3                            = UNIT_END + 0x00E9, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_45_5                            = UNIT_END + 0x00EB, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_46_1                            = UNIT_END + 0x00EC, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_46_2                            = UNIT_END + 0x00ED, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_46_3                            = UNIT_END + 0x00EE, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_46_5                            = UNIT_END + 0x00F0, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_47_1                            = UNIT_END + 0x00F1, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_47_2                            = UNIT_END + 0x00F2, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_47_3                            = UNIT_END + 0x00F3, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_47_5                            = UNIT_END + 0x00F5, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_48_1                            = UNIT_END + 0x00F6, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_48_2                            = UNIT_END + 0x00F7, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_48_3                            = UNIT_END + 0x00F8, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_48_5                            = UNIT_END + 0x00FA, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_49_1                            = UNIT_END + 0x00FB, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_49_2                            = UNIT_END + 0x00FC, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_49_3                            = UNIT_END + 0x00FD, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_49_5                            = UNIT_END + 0x00FF, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_50_1                            = UNIT_END + 0x0100, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_50_2                            = UNIT_END + 0x0101, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_50_3                            = UNIT_END + 0x0102, // Size: 2, Type: TWO_SHORT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_50_5                            = UNIT_END + 0x0104, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_VISIBLE_ITEM_1_ENTRYID                    = UNIT_END + 0x0105, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_ENCHANTMENT                = UNIT_END + 0x0106, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_ENTRYID                    = UNIT_END + 0x0107, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_ENCHANTMENT                = UNIT_END + 0x0108, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_ENTRYID                    = UNIT_END + 0x0109, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_ENCHANTMENT                = UNIT_END + 0x010A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_ENTRYID                    = UNIT_END + 0x010B, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_ENCHANTMENT                = UNIT_END + 0x010C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_ENTRYID                    = UNIT_END + 0x010D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_ENCHANTMENT                = UNIT_END + 0x010E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_ENTRYID                    = UNIT_END + 0x010F, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_ENCHANTMENT                = UNIT_END + 0x0110, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_ENTRYID                    = UNIT_END + 0x0111, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_ENCHANTMENT                = UNIT_END + 0x0112, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_ENTRYID                    = UNIT_END + 0x0113, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_ENCHANTMENT                = UNIT_END + 0x0114, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_ENTRYID                    = UNIT_END + 0x0115, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_ENCHANTMENT                = UNIT_END + 0x0116, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_ENTRYID                   = UNIT_END + 0x0117, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_ENCHANTMENT               = UNIT_END + 0x0118, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_ENTRYID                   = UNIT_END + 0x0119, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_ENCHANTMENT               = UNIT_END + 0x011A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_ENTRYID                   = UNIT_END + 0x011B, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_ENCHANTMENT               = UNIT_END + 0x011C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_ENTRYID                   = UNIT_END + 0x011D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_ENCHANTMENT               = UNIT_END + 0x011E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_ENTRYID                   = UNIT_END + 0x011F, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_ENCHANTMENT               = UNIT_END + 0x0120, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_ENTRYID                   = UNIT_END + 0x0121, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_ENCHANTMENT               = UNIT_END + 0x0122, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_ENTRYID                   = UNIT_END + 0x0123, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_ENCHANTMENT               = UNIT_END + 0x0124, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_ENTRYID                   = UNIT_END + 0x0125, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_ENCHANTMENT               = UNIT_END + 0x0126, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_ENTRYID                   = UNIT_END + 0x0127, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_ENCHANTMENT               = UNIT_END + 0x0128, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_ENTRYID                   = UNIT_END + 0x0129, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_ENCHANTMENT               = UNIT_END + 0x012A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_CHOSEN_TITLE                              = UNIT_END + 0x012B, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_FAKE_INEBRIATION                          = UNIT_END + 0x012C, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_FIELD_PAD_0                               = UNIT_END + 0x012D, // Size: 1, Type: INT, Flags: NONE
    PLAYER_END_NOT_SELF                              = UNIT_END + 0x012E,

    PLAYER_FIELD_INV_SLOT_HEAD                       = UNIT_END + 0x012E, // Size: 46, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_PACK_SLOT_1                         = UNIT_END + 0x015C, // Size: 32, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANK_SLOT_1                         = UNIT_END + 0x017C, // Size: 56, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANKBAG_SLOT_1                      = UNIT_END + 0x01B4, // Size: 14, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_VENDORBUYBACK_SLOT_1                = UNIT_END + 0x01C2, // Size: 24, Type: LONG, Flags: PRIVATE
    PLAYER_FARSIGHT                                  = UNIT_END + 0x01DA, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES                       = UNIT_END + 0x01DC, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES1                      = UNIT_END + 0x01DE, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES2                      = UNIT_END + 0x01E0, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES3                      = UNIT_END + 0x01E2, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER_XP                                        = UNIT_END + 0x01E4, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                             = UNIT_END + 0x01E5, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SKILL_LINEID_0                            = UNIT_END + 0x01E6, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_SKILL_STEP_0                              = UNIT_END + 0x0226, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_SKILL_RANK_0                              = UNIT_END + 0x0266, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_SKILL_MAX_RANK_0                          = UNIT_END + 0x02A6, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_SKILL_MODIFIER_0                          = UNIT_END + 0x02E6, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_SKILL_TALENT_0                            = UNIT_END + 0x0326, // Size: 64, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS                          = UNIT_END + 0x0366, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_CREATURES                           = UNIT_END + 0x0367, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                           = UNIT_END + 0x0368, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_EXPERTISE                                 = UNIT_END + 0x0369, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_OFFHAND_EXPERTISE                         = UNIT_END + 0x036A, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                          = UNIT_END + 0x036B, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                          = UNIT_END + 0x036C, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                          = UNIT_END + 0x036D, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                           = UNIT_END + 0x036E, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE                    = UNIT_END + 0x036F, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE                   = UNIT_END + 0x0370, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1                    = UNIT_END + 0x0371, // Size: 7, Type: FLOAT, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK                              = UNIT_END + 0x0378, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE              = UNIT_END + 0x0379, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_MASTERY                                   = UNIT_END + 0x037A, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                          = UNIT_END + 0x037B, // Size: 156, Type: BYTES, Flags: PRIVATE
    PLAYER_REST_STATE_EXPERIENCE                     = UNIT_END + 0x0417, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COINAGE                             = UNIT_END + 0x0418, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS                 = UNIT_END + 0x041A, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                 = UNIT_END + 0x0421, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                 = UNIT_END + 0x0428, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS                = UNIT_END + 0x042F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_PCT                     = UNIT_END + 0x0430, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_PCT                = UNIT_END + 0x0431, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_WEAPON_DMG_MULTIPLIERS              = UNIT_END + 0x0432, // Size: 3, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_SPELL_POWER_PCT                 = UNIT_END + 0x0435, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_SPELL_POWER_BY_AP_PCT      = UNIT_END + 0x0436, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE               = UNIT_END + 0x0437, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE      = UNIT_END + 0x0438, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES                               = UNIT_END + 0x0439, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_SELF_RES_SPELL                            = UNIT_END + 0x043A, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                          = UNIT_END + 0x043B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1                     = UNIT_END + 0x043C, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1                 = UNIT_END + 0x0448, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_KILLS                               = UNIT_END + 0x0454, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_FIELD_LIFETIME_HONORABLE_KILLS            = UNIT_END + 0x0455, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES2                              = UNIT_END + 0x0456, // Size: 1, Type: 6, Flags: PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX               = UNIT_END + 0x0457, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1                     = UNIT_END + 0x0458, // Size: 26, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_ARENA_TEAM_INFO_1_1                 = UNIT_END + 0x0472, // Size: 21, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BATTLEGROUND_RATING                 = UNIT_END + 0x0487, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MAX_LEVEL                           = UNIT_END + 0x0488, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_DAILY_QUESTS_1                      = UNIT_END + 0x0489, // Size: 25, Type: INT, Flags: PRIVATE
    PLAYER_RUNE_REGEN_1                              = UNIT_END + 0x04A2, // Size: 4, Type: FLOAT, Flags: PRIVATE
    PLAYER_NO_REAGENT_COST_1                         = UNIT_END + 0x04A6, // Size: 3, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_GLYPH_SLOTS_1                       = UNIT_END + 0x04A9, // Size: 9, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_GLYPHS_1                            = UNIT_END + 0x04B2, // Size: 9, Type: INT, Flags: PRIVATE
    PLAYER_GLYPHS_ENABLED                            = UNIT_END + 0x04BB, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_PET_SPELL_POWER                           = UNIT_END + 0x04BC, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_RESEARCHING_1                       = UNIT_END + 0x04BD, // Size: 8, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_FIELD_RESERACH_SITE_1                     = UNIT_END + 0x04C5, // Size: 8, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_PROFESSION_SKILL_LINE_1                   = UNIT_END + 0x04CD, // Size: 2, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_UI_HIT_MODIFIER                     = UNIT_END + 0x04CF, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_UI_SPELL_HIT_MODIFIER               = UNIT_END + 0x04D0, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_HOME_REALM_TIME_OFFSET              = UNIT_END + 0x04D1, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HASTE                           = UNIT_END + 0x04D2, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_RANGED_HASTE                    = UNIT_END + 0x04D3, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_PET_HASTE                       = UNIT_END + 0x04D4, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HASTE_REGEN                     = UNIT_END + 0x04D5, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_END                                       = UNIT_END + 0x04D6
};

enum EGameObjectFields
{
    OBJECT_FIELD_CREATED_BY                          = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    GAMEOBJECT_DISPLAYID                             = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_FLAGS                                 = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_PARENTROTATION                        = OBJECT_END + 0x0004, // Size: 4, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_DYNAMIC                               = OBJECT_END + 0x0008, // Size: 1, Type: TWO_SHORT, Flags: DYNAMIC
    GAMEOBJECT_FACTION                               = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_LEVEL                                 = OBJECT_END + 0x000A, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_BYTES_1                               = OBJECT_END + 0x000B, // Size: 1, Type: BYTES, Flags: PUBLIC
    GAMEOBJECT_END                                   = OBJECT_END + 0x000C
};

enum EDynamicObjectFields
{
    DYNAMICOBJECT_CASTER                             = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    DYNAMICOBJECT_BYTES                              = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: DYNAMIC
    DYNAMICOBJECT_SPELLID                            = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                             = OBJECT_END + 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_CASTTIME                           = OBJECT_END + 0x0005, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_END                                = OBJECT_END + 0x0006
};

enum ECorpseFields
{
    CORPSE_FIELD_OWNER                               = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_PARTY                               = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_DISPLAY_ID                          = OBJECT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_ITEM                                = OBJECT_END + 0x0005, // Size: 19, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_BYTES_1                             = OBJECT_END + 0x0018, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_BYTES_2                             = OBJECT_END + 0x0019, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_FLAGS                               = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_DYNAMIC_FLAGS                       = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: DYNAMIC
    CORPSE_END                                       = OBJECT_END + 0x001C
};

enum EAreaTriggerFields
{
    AREATRIGGER_SPELLID                              = OBJECT_END + 0x0000, // Size: 1, Type: INT, Flags: PUBLIC
    AREATRIGGER_SPELLVISUALID                        = OBJECT_END + 0x0001, // Size: 1, Type: INT, Flags: PUBLIC
    AREATRIGGER_DURATION                             = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    AREATRIGGER_FINAL_POS                            = OBJECT_END + 0x0003, // Size: 3, Type: FLOAT, Flags: PUBLIC
    AREATRIGGER_END                                  = OBJECT_END + 0x0006
};

#endif // _UPDATEFIELDS_H
