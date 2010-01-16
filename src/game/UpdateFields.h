/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _UPDATEFIELDS_AUTO_H
#define _UPDATEFIELDS_AUTO_H

// Auto generated for version 3, 2, 2, 10505

enum EObjectFields
{
    OBJECT_FIELD_GUID                         = 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    OBJECT_FIELD_TYPE                         = 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    OBJECT_FIELD_ENTRY                        = 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    OBJECT_FIELD_SCALE_X                      = 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
    OBJECT_FIELD_PADDING                      = 0x0005, // Size: 1, Type: INT, Flags: NONE
    OBJECT_END                                = 0x0006,
};

enum EItemFields
{
    ITEM_FIELD_OWNER                          = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_CONTAINED                      = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_CREATOR                        = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_GIFTCREATOR                    = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
    ITEM_FIELD_STACK_COUNT                    = OBJECT_END + 0x0008, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_DURATION                       = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_SPELL_CHARGES                  = OBJECT_END + 0x000A, // Size: 5, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_FLAGS                          = OBJECT_END + 0x000F, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_1_1                = OBJECT_END + 0x0010, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_1_3                = OBJECT_END + 0x0012, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_2_1                = OBJECT_END + 0x0013, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_2_3                = OBJECT_END + 0x0015, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_3_1                = OBJECT_END + 0x0016, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_3_3                = OBJECT_END + 0x0018, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_4_1                = OBJECT_END + 0x0019, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_4_3                = OBJECT_END + 0x001B, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_5_1                = OBJECT_END + 0x001C, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_5_3                = OBJECT_END + 0x001E, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_6_1                = OBJECT_END + 0x001F, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_6_3                = OBJECT_END + 0x0021, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_7_1                = OBJECT_END + 0x0022, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_7_3                = OBJECT_END + 0x0024, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_8_1                = OBJECT_END + 0x0025, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_8_3                = OBJECT_END + 0x0027, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_9_1                = OBJECT_END + 0x0028, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_9_3                = OBJECT_END + 0x002A, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_10_1               = OBJECT_END + 0x002B, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_10_3               = OBJECT_END + 0x002D, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_11_1               = OBJECT_END + 0x002E, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_11_3               = OBJECT_END + 0x0030, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_12_1               = OBJECT_END + 0x0031, // Size: 2, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT_12_3               = OBJECT_END + 0x0033, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    ITEM_FIELD_PROPERTY_SEED                  = OBJECT_END + 0x0034, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID           = OBJECT_END + 0x0035, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ITEM_TEXT_ID                   = OBJECT_END + 0x0036, // Size: 1, Type: INT, Flags: OWNER
    ITEM_FIELD_DURABILITY                     = OBJECT_END + 0x0037, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_MAXDURABILITY                  = OBJECT_END + 0x0038, // Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
    ITEM_FIELD_CREATE_PLAYED_TIME             = OBJECT_END + 0x0039, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_END                                  = OBJECT_END + 0x003A,
};

enum EContainerFields
{
    CONTAINER_FIELD_NUM_SLOTS                 = ITEM_END + 0x0000, // Size: 1, Type: INT, Flags: PUBLIC
    CONTAINER_ALIGN_PAD                       = ITEM_END + 0x0001, // Size: 1, Type: BYTES, Flags: NONE
    CONTAINER_FIELD_SLOT_1                    = ITEM_END + 0x0002, // Size: 72, Type: LONG, Flags: PUBLIC
    CONTAINER_END                             = ITEM_END + 0x004A,
};

enum EUnitFields
{
    UNIT_FIELD_CHARM                          = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_SUMMON                         = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CRITTER                        = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PRIVATE
    UNIT_FIELD_CHARMEDBY                      = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_SUMMONEDBY                     = OBJECT_END + 0x0008, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CREATEDBY                      = OBJECT_END + 0x000A, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_TARGET                         = OBJECT_END + 0x000C, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CHANNEL_OBJECT                 = OBJECT_END + 0x000E, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_BYTES_0                        = OBJECT_END + 0x0010, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_HEALTH                         = OBJECT_END + 0x0011, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER1                         = OBJECT_END + 0x0012, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER2                         = OBJECT_END + 0x0013, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER3                         = OBJECT_END + 0x0014, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER4                         = OBJECT_END + 0x0015, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER5                         = OBJECT_END + 0x0016, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER6                         = OBJECT_END + 0x0017, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER7                         = OBJECT_END + 0x0018, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXHEALTH                      = OBJECT_END + 0x0019, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER1                      = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER2                      = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER3                      = OBJECT_END + 0x001C, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER4                      = OBJECT_END + 0x001D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER5                      = OBJECT_END + 0x001E, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER6                      = OBJECT_END + 0x001F, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER7                      = OBJECT_END + 0x0020, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER      = OBJECT_END + 0x0021, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER = OBJECT_END + 0x0028, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_LEVEL                          = OBJECT_END + 0x002F, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                = OBJECT_END + 0x0030, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_ID                 = OBJECT_END + 0x0031, // Size: 3, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FLAGS                          = OBJECT_END + 0x0034, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FLAGS_2                        = OBJECT_END + 0x0035, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_AURASTATE                      = OBJECT_END + 0x0036, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                 = OBJECT_END + 0x0037, // Size: 2, Type: INT, Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME               = OBJECT_END + 0x0039, // Size: 1, Type: INT, Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                 = OBJECT_END + 0x003A, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                    = OBJECT_END + 0x003B, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                      = OBJECT_END + 0x003C, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_NATIVEDISPLAYID                = OBJECT_END + 0x003D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MOUNTDISPLAYID                 = OBJECT_END + 0x003E, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MINDAMAGE                      = OBJECT_END + 0x003F, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
    UNIT_FIELD_MAXDAMAGE                      = OBJECT_END + 0x0040, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
    UNIT_FIELD_MINOFFHANDDAMAGE               = OBJECT_END + 0x0041, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
    UNIT_FIELD_MAXOFFHANDDAMAGE               = OBJECT_END + 0x0042, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
    UNIT_FIELD_BYTES_1                        = OBJECT_END + 0x0043, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                      = OBJECT_END + 0x0044, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP             = OBJECT_END + 0x0045, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                  = OBJECT_END + 0x0046, // Size: 1, Type: INT, Flags: OWNER
    UNIT_FIELD_PETNEXTLEVELEXP                = OBJECT_END + 0x0047, // Size: 1, Type: INT, Flags: OWNER
    UNIT_DYNAMIC_FLAGS                        = OBJECT_END + 0x0048, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_CHANNEL_SPELL                        = OBJECT_END + 0x0049, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_MOD_CAST_SPEED                       = OBJECT_END + 0x004A, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                     = OBJECT_END + 0x004B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_NPC_FLAGS                            = OBJECT_END + 0x004C, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_NPC_EMOTESTATE                       = OBJECT_END + 0x004D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_STAT0                          = OBJECT_END + 0x004E, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT1                          = OBJECT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT2                          = OBJECT_END + 0x0050, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT3                          = OBJECT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_STAT4                          = OBJECT_END + 0x0052, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT0                       = OBJECT_END + 0x0053, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT1                       = OBJECT_END + 0x0054, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT2                       = OBJECT_END + 0x0055, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT3                       = OBJECT_END + 0x0056, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT4                       = OBJECT_END + 0x0057, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT0                       = OBJECT_END + 0x0058, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT1                       = OBJECT_END + 0x0059, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT2                       = OBJECT_END + 0x005A, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT3                       = OBJECT_END + 0x005B, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT4                       = OBJECT_END + 0x005C, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCES                    = OBJECT_END + 0x005D, // Size: 7, Type: INT, Flags: PRIVATE, OWNER, PARTY_LEADER
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE     = OBJECT_END + 0x0064, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE     = OBJECT_END + 0x006B, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_BASE_MANA                      = OBJECT_END + 0x0072, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASE_HEALTH                    = OBJECT_END + 0x0073, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_BYTES_2                        = OBJECT_END + 0x0074, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_ATTACK_POWER                   = OBJECT_END + 0x0075, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MODS              = OBJECT_END + 0x0076, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER        = OBJECT_END + 0x0077, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER            = OBJECT_END + 0x0078, // Size: 1, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MODS       = OBJECT_END + 0x0079, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER = OBJECT_END + 0x007A, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MINRANGEDDAMAGE                = OBJECT_END + 0x007B, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXRANGEDDAMAGE                = OBJECT_END + 0x007C, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MODIFIER            = OBJECT_END + 0x007D, // Size: 7, Type: INT, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MULTIPLIER          = OBJECT_END + 0x0084, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXHEALTHMODIFIER              = OBJECT_END + 0x008B, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
    UNIT_FIELD_HOVERHEIGHT                    = OBJECT_END + 0x008C, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_PADDING                        = OBJECT_END + 0x008D, // Size: 1, Type: INT, Flags: NONE
    UNIT_END                                  = OBJECT_END + 0x008E,

    PLAYER_DUEL_ARBITER                       = UNIT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_FLAGS                              = UNIT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDID                            = UNIT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDRANK                          = UNIT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_BYTES                              = UNIT_END + 0x0005, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_2                            = UNIT_END + 0x0006, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_3                            = UNIT_END + 0x0007, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_DUEL_TEAM                          = UNIT_END + 0x0008, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                    = UNIT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_QUEST_LOG_1_1                      = UNIT_END + 0x000A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_1_2                      = UNIT_END + 0x000B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_1_3                      = UNIT_END + 0x000C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_1_4                      = UNIT_END + 0x000D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_1                      = UNIT_END + 0x000E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_2_2                      = UNIT_END + 0x000F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_3                      = UNIT_END + 0x0010, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_4                      = UNIT_END + 0x0011, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_1                      = UNIT_END + 0x0012, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_3_2                      = UNIT_END + 0x0013, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_3                      = UNIT_END + 0x0014, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_4                      = UNIT_END + 0x0015, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_1                      = UNIT_END + 0x0016, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_4_2                      = UNIT_END + 0x0017, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_3                      = UNIT_END + 0x0018, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_4                      = UNIT_END + 0x0019, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_1                      = UNIT_END + 0x001A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_5_2                      = UNIT_END + 0x001B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_3                      = UNIT_END + 0x001C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_4                      = UNIT_END + 0x001D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_1                      = UNIT_END + 0x001E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_6_2                      = UNIT_END + 0x001F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_3                      = UNIT_END + 0x0020, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_4                      = UNIT_END + 0x0021, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_1                      = UNIT_END + 0x0022, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_7_2                      = UNIT_END + 0x0023, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_3                      = UNIT_END + 0x0024, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_4                      = UNIT_END + 0x0025, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_1                      = UNIT_END + 0x0026, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_8_2                      = UNIT_END + 0x0027, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_3                      = UNIT_END + 0x0028, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_4                      = UNIT_END + 0x0029, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_1                      = UNIT_END + 0x002A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_9_2                      = UNIT_END + 0x002B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_3                      = UNIT_END + 0x002C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_4                      = UNIT_END + 0x002D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_1                     = UNIT_END + 0x002E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_10_2                     = UNIT_END + 0x002F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_3                     = UNIT_END + 0x0030, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_4                     = UNIT_END + 0x0031, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_1                     = UNIT_END + 0x0032, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_11_2                     = UNIT_END + 0x0033, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_3                     = UNIT_END + 0x0034, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_4                     = UNIT_END + 0x0035, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_1                     = UNIT_END + 0x0036, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_12_2                     = UNIT_END + 0x0037, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_3                     = UNIT_END + 0x0038, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_4                     = UNIT_END + 0x0039, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_1                     = UNIT_END + 0x003A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_13_2                     = UNIT_END + 0x003B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_3                     = UNIT_END + 0x003C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_4                     = UNIT_END + 0x003D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_1                     = UNIT_END + 0x003E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_14_2                     = UNIT_END + 0x003F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_3                     = UNIT_END + 0x0040, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_4                     = UNIT_END + 0x0041, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_1                     = UNIT_END + 0x0042, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_15_2                     = UNIT_END + 0x0043, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_3                     = UNIT_END + 0x0044, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_4                     = UNIT_END + 0x0045, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_1                     = UNIT_END + 0x0046, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_16_2                     = UNIT_END + 0x0047, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_3                     = UNIT_END + 0x0048, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_4                     = UNIT_END + 0x0049, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_1                     = UNIT_END + 0x004A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_17_2                     = UNIT_END + 0x004B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_3                     = UNIT_END + 0x004C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_4                     = UNIT_END + 0x004D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_1                     = UNIT_END + 0x004E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_18_2                     = UNIT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_3                     = UNIT_END + 0x0050, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_4                     = UNIT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_1                     = UNIT_END + 0x0052, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_19_2                     = UNIT_END + 0x0053, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_3                     = UNIT_END + 0x0054, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_4                     = UNIT_END + 0x0055, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_1                     = UNIT_END + 0x0056, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_20_2                     = UNIT_END + 0x0057, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_3                     = UNIT_END + 0x0058, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_4                     = UNIT_END + 0x0059, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_1                     = UNIT_END + 0x005A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_21_2                     = UNIT_END + 0x005B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_3                     = UNIT_END + 0x005C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_4                     = UNIT_END + 0x005D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_1                     = UNIT_END + 0x005E, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_22_2                     = UNIT_END + 0x005F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_3                     = UNIT_END + 0x0060, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_4                     = UNIT_END + 0x0061, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_1                     = UNIT_END + 0x0062, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_23_2                     = UNIT_END + 0x0063, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_3                     = UNIT_END + 0x0064, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_4                     = UNIT_END + 0x0065, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_1                     = UNIT_END + 0x0066, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_24_2                     = UNIT_END + 0x0067, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_3                     = UNIT_END + 0x0068, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_4                     = UNIT_END + 0x0069, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_1                     = UNIT_END + 0x006A, // Size: 1, Type: INT, Flags: PARTY_MEMBER
    PLAYER_QUEST_LOG_25_2                     = UNIT_END + 0x006B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_3                     = UNIT_END + 0x006C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_4                     = UNIT_END + 0x006D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_VISIBLE_ITEM_1_ENTRYID             = UNIT_END + 0x006E, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_ENCHANTMENT         = UNIT_END + 0x006F, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_ENTRYID             = UNIT_END + 0x0070, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_ENCHANTMENT         = UNIT_END + 0x0071, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_ENTRYID             = UNIT_END + 0x0072, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_ENCHANTMENT         = UNIT_END + 0x0073, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_ENTRYID             = UNIT_END + 0x0074, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_ENCHANTMENT         = UNIT_END + 0x0075, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_ENTRYID             = UNIT_END + 0x0076, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_ENCHANTMENT         = UNIT_END + 0x0077, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_ENTRYID             = UNIT_END + 0x0078, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_ENCHANTMENT         = UNIT_END + 0x0079, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_ENTRYID             = UNIT_END + 0x007A, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_ENCHANTMENT         = UNIT_END + 0x007B, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_ENTRYID             = UNIT_END + 0x007C, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_ENCHANTMENT         = UNIT_END + 0x007D, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_ENTRYID             = UNIT_END + 0x007E, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_ENCHANTMENT         = UNIT_END + 0x007F, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_ENTRYID            = UNIT_END + 0x0080, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_ENCHANTMENT        = UNIT_END + 0x0081, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_ENTRYID            = UNIT_END + 0x0082, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_ENCHANTMENT        = UNIT_END + 0x0083, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_ENTRYID            = UNIT_END + 0x0084, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_ENCHANTMENT        = UNIT_END + 0x0085, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_ENTRYID            = UNIT_END + 0x0086, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_ENCHANTMENT        = UNIT_END + 0x0087, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_ENTRYID            = UNIT_END + 0x0088, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_ENCHANTMENT        = UNIT_END + 0x0089, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_ENTRYID            = UNIT_END + 0x008A, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_ENCHANTMENT        = UNIT_END + 0x008B, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_ENTRYID            = UNIT_END + 0x008C, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_ENCHANTMENT        = UNIT_END + 0x008D, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_ENTRYID            = UNIT_END + 0x008E, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_ENCHANTMENT        = UNIT_END + 0x008F, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_ENTRYID            = UNIT_END + 0x0090, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_ENCHANTMENT        = UNIT_END + 0x0091, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_ENTRYID            = UNIT_END + 0x0092, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_ENCHANTMENT        = UNIT_END + 0x0093, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_CHOSEN_TITLE                       = UNIT_END + 0x0094, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_FAKE_INEBRIATION                   = UNIT_END + 0x0095, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_FIELD_INV_SLOT_HEAD                = UNIT_END + 0x0096, // Size: 46, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_PACK_SLOT_1                  = UNIT_END + 0x00C4, // Size: 32, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANK_SLOT_1                  = UNIT_END + 0x00E4, // Size: 56, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANKBAG_SLOT_1               = UNIT_END + 0x011C, // Size: 14, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_VENDORBUYBACK_SLOT_1         = UNIT_END + 0x012A, // Size: 24, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_KEYRING_SLOT_1               = UNIT_END + 0x0142, // Size: 64, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_CURRENCYTOKEN_SLOT_1         = UNIT_END + 0x0182, // Size: 64, Type: LONG, Flags: PRIVATE
    PLAYER_FARSIGHT                           = UNIT_END + 0x01C2, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES                = UNIT_END + 0x01C4, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES1               = UNIT_END + 0x01C6, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES2               = UNIT_END + 0x01C8, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_KNOWN_CURRENCIES             = UNIT_END + 0x01CA, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER_XP                                 = UNIT_END + 0x01CC, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                      = UNIT_END + 0x01CD, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SKILL_INFO_1_1                     = UNIT_END + 0x01CE, // Size: 384, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS1                  = UNIT_END + 0x034E, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS2                  = UNIT_END + 0x034F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_CREATURES                    = UNIT_END + 0x0350, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                    = UNIT_END + 0x0351, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                   = UNIT_END + 0x0352, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                   = UNIT_END + 0x0353, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                   = UNIT_END + 0x0354, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_EXPERTISE                          = UNIT_END + 0x0355, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_OFFHAND_EXPERTISE                  = UNIT_END + 0x0356, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                    = UNIT_END + 0x0357, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE             = UNIT_END + 0x0358, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE            = UNIT_END + 0x0359, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1             = UNIT_END + 0x035A, // Size: 7, Type: FLOAT, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK                       = UNIT_END + 0x0361, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE       = UNIT_END + 0x0362, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                   = UNIT_END + 0x0363, // Size: 128, Type: BYTES, Flags: PRIVATE
    PLAYER_REST_STATE_EXPERIENCE              = UNIT_END + 0x03E3, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COINAGE                      = UNIT_END + 0x03E4, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS          = UNIT_END + 0x03E5, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG          = UNIT_END + 0x03EC, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT          = UNIT_END + 0x03F3, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS         = UNIT_END + 0x03FA, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_PCT              = UNIT_END + 0x03FB, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_PCT         = UNIT_END + 0x03FC, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE        = UNIT_END + 0x03FD, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE = UNIT_END + 0x03FE, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES                        = UNIT_END + 0x03FF, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_AMMO_ID                            = UNIT_END + 0x0400, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SELF_RES_SPELL                     = UNIT_END + 0x0401, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                   = UNIT_END + 0x0402, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1              = UNIT_END + 0x0403, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1          = UNIT_END + 0x040F, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_KILLS                        = UNIT_END + 0x041B, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_FIELD_TODAY_CONTRIBUTION           = UNIT_END + 0x041C, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_YESTERDAY_CONTRIBUTION       = UNIT_END + 0x041D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_LIFETIME_HONORABLE_KILLS     = UNIT_END + 0x041E, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES2                       = UNIT_END + 0x041F, // Size: 1, Type: 6, Flags: PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX        = UNIT_END + 0x0420, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1              = UNIT_END + 0x0421, // Size: 25, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_ARENA_TEAM_INFO_1_1          = UNIT_END + 0x043A, // Size: 21, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_HONOR_CURRENCY               = UNIT_END + 0x044F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_ARENA_CURRENCY               = UNIT_END + 0x0450, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MAX_LEVEL                    = UNIT_END + 0x0451, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_DAILY_QUESTS_1               = UNIT_END + 0x0452, // Size: 25, Type: INT, Flags: PRIVATE
    PLAYER_RUNE_REGEN_1                       = UNIT_END + 0x046B, // Size: 4, Type: FLOAT, Flags: PRIVATE
    PLAYER_NO_REAGENT_COST_1                  = UNIT_END + 0x046F, // Size: 3, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_GLYPH_SLOTS_1                = UNIT_END + 0x0472, // Size: 6, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_GLYPHS_1                     = UNIT_END + 0x0478, // Size: 6, Type: INT, Flags: PRIVATE
    PLAYER_GLYPHS_ENABLED                     = UNIT_END + 0x047E, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_PADDING                      = UNIT_END + 0x047F, // Size: 1, Type: INT, Flags: NONE
    PLAYER_END                                = UNIT_END + 0x0480,
};

enum EGameObjectFields
{
    OBJECT_FIELD_CREATED_BY                   = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    GAMEOBJECT_DISPLAYID                      = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_FLAGS                          = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_PARENTROTATION                 = OBJECT_END + 0x0004, // Size: 4, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_DYNAMIC                        = OBJECT_END + 0x0008, // Size: 1, Type: TWO_SHORT, Flags: DYNAMIC
    GAMEOBJECT_FACTION                        = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_LEVEL                          = OBJECT_END + 0x000A, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_BYTES_1                        = OBJECT_END + 0x000B, // Size: 1, Type: BYTES, Flags: PUBLIC
    GAMEOBJECT_END                            = OBJECT_END + 0x000C,
};

enum EDynamicObjectFields
{
    DYNAMICOBJECT_CASTER                      = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    DYNAMICOBJECT_BYTES                       = OBJECT_END + 0x0002, // Size: 1, Type: BYTES, Flags: PUBLIC
    DYNAMICOBJECT_SPELLID                     = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                      = OBJECT_END + 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_CASTTIME                    = OBJECT_END + 0x0005, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_END                         = OBJECT_END + 0x0006,
};

enum ECorpseFields
{
    CORPSE_FIELD_OWNER                        = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_PARTY                        = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_DISPLAY_ID                   = OBJECT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_ITEM                         = OBJECT_END + 0x0005, // Size: 19, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_BYTES_1                      = OBJECT_END + 0x0018, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_BYTES_2                      = OBJECT_END + 0x0019, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_GUILD                        = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_FLAGS                        = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_DYNAMIC_FLAGS                = OBJECT_END + 0x001C, // Size: 1, Type: INT, Flags: DYNAMIC
    CORPSE_FIELD_PAD                          = OBJECT_END + 0x001D, // Size: 1, Type: INT, Flags: NONE
    CORPSE_END                                = OBJECT_END + 0x001E,
};
#endif
