/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

// Auto generated for version 2, 4, 3, 8606

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
    ITEM_FIELD_STACK_COUNT                    = OBJECT_END + 0x0008, // Size: 1, Type: INT, Flags: OWNER_ONLY, UNK2
    ITEM_FIELD_DURATION                       = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: OWNER_ONLY, UNK2
    ITEM_FIELD_SPELL_CHARGES                  = OBJECT_END + 0x000A, // Size: 5, Type: INT, Flags: OWNER_ONLY, UNK2
    ITEM_FIELD_FLAGS                          = OBJECT_END + 0x000F, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT                    = OBJECT_END + 0x0010, // Size: 33, Type: INT, Flags: PUBLIC
    ITEM_FIELD_PROPERTY_SEED                  = OBJECT_END + 0x0031, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID           = OBJECT_END + 0x0032, // Size: 1, Type: INT, Flags: PUBLIC
    ITEM_FIELD_ITEM_TEXT_ID                   = OBJECT_END + 0x0033, // Size: 1, Type: INT, Flags: OWNER_ONLY
    ITEM_FIELD_DURABILITY                     = OBJECT_END + 0x0034, // Size: 1, Type: INT, Flags: OWNER_ONLY, UNK2
    ITEM_FIELD_MAXDURABILITY                  = OBJECT_END + 0x0035, // Size: 1, Type: INT, Flags: OWNER_ONLY, UNK2
    ITEM_END                                  = OBJECT_END + 0x0036,
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
    UNIT_FIELD_CHARMEDBY                      = OBJECT_END + 0x0004, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_SUMMONEDBY                     = OBJECT_END + 0x0006, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CREATEDBY                      = OBJECT_END + 0x0008, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_TARGET                         = OBJECT_END + 0x000A, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_PERSUADED                      = OBJECT_END + 0x000C, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_CHANNEL_OBJECT                 = OBJECT_END + 0x000E, // Size: 2, Type: LONG, Flags: PUBLIC
    UNIT_FIELD_HEALTH                         = OBJECT_END + 0x0010, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_FIELD_POWER1                         = OBJECT_END + 0x0011, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER2                         = OBJECT_END + 0x0012, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER3                         = OBJECT_END + 0x0013, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER4                         = OBJECT_END + 0x0014, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_POWER5                         = OBJECT_END + 0x0015, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXHEALTH                      = OBJECT_END + 0x0016, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_FIELD_MAXPOWER1                      = OBJECT_END + 0x0017, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER2                      = OBJECT_END + 0x0018, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER3                      = OBJECT_END + 0x0019, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER4                      = OBJECT_END + 0x001A, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER5                      = OBJECT_END + 0x001B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_LEVEL                          = OBJECT_END + 0x001C, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                = OBJECT_END + 0x001D, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BYTES_0                        = OBJECT_END + 0x001E, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_DISPLAY            = OBJECT_END + 0x001F, // Size: 3, Type: INT, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_INFO                    = OBJECT_END + 0x0022, // Size: 6, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_FLAGS                          = OBJECT_END + 0x0028, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_FLAGS_2                        = OBJECT_END + 0x0029, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_AURA                           = OBJECT_END + 0x002A, // Size: 56, Type: INT, Flags: PUBLIC
    UNIT_FIELD_AURAFLAGS                      = OBJECT_END + 0x0062, // Size: 14, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_AURALEVELS                     = OBJECT_END + 0x0070, // Size: 14, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_AURAAPPLICATIONS               = OBJECT_END + 0x007E, // Size: 14, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_AURASTATE                      = OBJECT_END + 0x008C, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                 = OBJECT_END + 0x008D, // Size: 2, Type: INT, Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME               = OBJECT_END + 0x008F, // Size: 1, Type: INT, Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                 = OBJECT_END + 0x0090, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                    = OBJECT_END + 0x0091, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                      = OBJECT_END + 0x0092, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_NATIVEDISPLAYID                = OBJECT_END + 0x0093, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MOUNTDISPLAYID                 = OBJECT_END + 0x0094, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_MINDAMAGE                      = OBJECT_END + 0x0095, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY, UNK3
    UNIT_FIELD_MAXDAMAGE                      = OBJECT_END + 0x0096, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY, UNK3
    UNIT_FIELD_MINOFFHANDDAMAGE               = OBJECT_END + 0x0097, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY, UNK3
    UNIT_FIELD_MAXOFFHANDDAMAGE               = OBJECT_END + 0x0098, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY, UNK3
    UNIT_FIELD_BYTES_1                        = OBJECT_END + 0x0099, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                      = OBJECT_END + 0x009A, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP             = OBJECT_END + 0x009B, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                  = OBJECT_END + 0x009C, // Size: 1, Type: INT, Flags: OWNER_ONLY
    UNIT_FIELD_PETNEXTLEVELEXP                = OBJECT_END + 0x009D, // Size: 1, Type: INT, Flags: OWNER_ONLY
    UNIT_DYNAMIC_FLAGS                        = OBJECT_END + 0x009E, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_CHANNEL_SPELL                        = OBJECT_END + 0x009F, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_MOD_CAST_SPEED                       = OBJECT_END + 0x00A0, // Size: 1, Type: FLOAT, Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                     = OBJECT_END + 0x00A1, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_NPC_FLAGS                            = OBJECT_END + 0x00A2, // Size: 1, Type: INT, Flags: DYNAMIC
    UNIT_NPC_EMOTESTATE                       = OBJECT_END + 0x00A3, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_TRAINING_POINTS                      = OBJECT_END + 0x00A4, // Size: 1, Type: TWO_SHORT, Flags: OWNER_ONLY
    UNIT_FIELD_STAT0                          = OBJECT_END + 0x00A5, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_STAT1                          = OBJECT_END + 0x00A6, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_STAT2                          = OBJECT_END + 0x00A7, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_STAT3                          = OBJECT_END + 0x00A8, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_STAT4                          = OBJECT_END + 0x00A9, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POSSTAT0                       = OBJECT_END + 0x00AA, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POSSTAT1                       = OBJECT_END + 0x00AB, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POSSTAT2                       = OBJECT_END + 0x00AC, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POSSTAT3                       = OBJECT_END + 0x00AD, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POSSTAT4                       = OBJECT_END + 0x00AE, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_NEGSTAT0                       = OBJECT_END + 0x00AF, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_NEGSTAT1                       = OBJECT_END + 0x00B0, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_NEGSTAT2                       = OBJECT_END + 0x00B1, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_NEGSTAT3                       = OBJECT_END + 0x00B2, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_NEGSTAT4                       = OBJECT_END + 0x00B3, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_RESISTANCES                    = OBJECT_END + 0x00B4, // Size: 7, Type: INT, Flags: PRIVATE, OWNER_ONLY, UNK3
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE     = OBJECT_END + 0x00BB, // Size: 7, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE     = OBJECT_END + 0x00C2, // Size: 7, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_BASE_MANA                      = OBJECT_END + 0x00C9, // Size: 1, Type: INT, Flags: PUBLIC
    UNIT_FIELD_BASE_HEALTH                    = OBJECT_END + 0x00CA, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_BYTES_2                        = OBJECT_END + 0x00CB, // Size: 1, Type: BYTES, Flags: PUBLIC
    UNIT_FIELD_ATTACK_POWER                   = OBJECT_END + 0x00CC, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_ATTACK_POWER_MODS              = OBJECT_END + 0x00CD, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER        = OBJECT_END + 0x00CE, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_RANGED_ATTACK_POWER            = OBJECT_END + 0x00CF, // Size: 1, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_RANGED_ATTACK_POWER_MODS       = OBJECT_END + 0x00D0, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER = OBJECT_END + 0x00D1, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_MINRANGEDDAMAGE                = OBJECT_END + 0x00D2, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_MAXRANGEDDAMAGE                = OBJECT_END + 0x00D3, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POWER_COST_MODIFIER            = OBJECT_END + 0x00D4, // Size: 7, Type: INT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_POWER_COST_MULTIPLIER          = OBJECT_END + 0x00DB, // Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_MAXHEALTHMODIFIER              = OBJECT_END + 0x00E2, // Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER_ONLY
    UNIT_FIELD_PADDING                        = OBJECT_END + 0x00E3, // Size: 1, Type: INT, Flags: NONE
    UNIT_END                                  = OBJECT_END + 0x00E4,

    PLAYER_DUEL_ARBITER                       = UNIT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_FLAGS                              = UNIT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDID                            = UNIT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILDRANK                          = UNIT_END + 0x0004, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_BYTES                              = UNIT_END + 0x0005, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_2                            = UNIT_END + 0x0006, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_BYTES_3                            = UNIT_END + 0x0007, // Size: 1, Type: BYTES, Flags: PUBLIC
    PLAYER_DUEL_TEAM                          = UNIT_END + 0x0008, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                    = UNIT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_QUEST_LOG_1_1                      = UNIT_END + 0x000A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_1_2                      = UNIT_END + 0x000B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_1_3                      = UNIT_END + 0x000C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_1_4                      = UNIT_END + 0x000D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_1                      = UNIT_END + 0x000E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_2_2                      = UNIT_END + 0x000F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_3                      = UNIT_END + 0x0010, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_2_4                      = UNIT_END + 0x0011, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_1                      = UNIT_END + 0x0012, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_3_2                      = UNIT_END + 0x0013, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_3                      = UNIT_END + 0x0014, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_3_4                      = UNIT_END + 0x0015, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_1                      = UNIT_END + 0x0016, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_4_2                      = UNIT_END + 0x0017, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_3                      = UNIT_END + 0x0018, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_4_4                      = UNIT_END + 0x0019, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_1                      = UNIT_END + 0x001A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_5_2                      = UNIT_END + 0x001B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_3                      = UNIT_END + 0x001C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_5_4                      = UNIT_END + 0x001D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_1                      = UNIT_END + 0x001E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_6_2                      = UNIT_END + 0x001F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_3                      = UNIT_END + 0x0020, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_6_4                      = UNIT_END + 0x0021, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_1                      = UNIT_END + 0x0022, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_7_2                      = UNIT_END + 0x0023, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_3                      = UNIT_END + 0x0024, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_7_4                      = UNIT_END + 0x0025, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_1                      = UNIT_END + 0x0026, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_8_2                      = UNIT_END + 0x0027, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_3                      = UNIT_END + 0x0028, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_8_4                      = UNIT_END + 0x0029, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_1                      = UNIT_END + 0x002A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_9_2                      = UNIT_END + 0x002B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_3                      = UNIT_END + 0x002C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_9_4                      = UNIT_END + 0x002D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_1                     = UNIT_END + 0x002E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_10_2                     = UNIT_END + 0x002F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_3                     = UNIT_END + 0x0030, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_10_4                     = UNIT_END + 0x0031, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_1                     = UNIT_END + 0x0032, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_11_2                     = UNIT_END + 0x0033, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_3                     = UNIT_END + 0x0034, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_11_4                     = UNIT_END + 0x0035, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_1                     = UNIT_END + 0x0036, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_12_2                     = UNIT_END + 0x0037, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_3                     = UNIT_END + 0x0038, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_12_4                     = UNIT_END + 0x0039, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_1                     = UNIT_END + 0x003A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_13_2                     = UNIT_END + 0x003B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_3                     = UNIT_END + 0x003C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_13_4                     = UNIT_END + 0x003D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_1                     = UNIT_END + 0x003E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_14_2                     = UNIT_END + 0x003F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_3                     = UNIT_END + 0x0040, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_14_4                     = UNIT_END + 0x0041, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_1                     = UNIT_END + 0x0042, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_15_2                     = UNIT_END + 0x0043, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_3                     = UNIT_END + 0x0044, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_15_4                     = UNIT_END + 0x0045, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_1                     = UNIT_END + 0x0046, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_16_2                     = UNIT_END + 0x0047, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_3                     = UNIT_END + 0x0048, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_16_4                     = UNIT_END + 0x0049, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_1                     = UNIT_END + 0x004A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_17_2                     = UNIT_END + 0x004B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_3                     = UNIT_END + 0x004C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_17_4                     = UNIT_END + 0x004D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_1                     = UNIT_END + 0x004E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_18_2                     = UNIT_END + 0x004F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_3                     = UNIT_END + 0x0050, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_18_4                     = UNIT_END + 0x0051, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_1                     = UNIT_END + 0x0052, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_19_2                     = UNIT_END + 0x0053, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_3                     = UNIT_END + 0x0054, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_19_4                     = UNIT_END + 0x0055, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_1                     = UNIT_END + 0x0056, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_20_2                     = UNIT_END + 0x0057, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_3                     = UNIT_END + 0x0058, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_20_4                     = UNIT_END + 0x0059, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_1                     = UNIT_END + 0x005A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_21_2                     = UNIT_END + 0x005B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_3                     = UNIT_END + 0x005C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_21_4                     = UNIT_END + 0x005D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_1                     = UNIT_END + 0x005E, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_22_2                     = UNIT_END + 0x005F, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_3                     = UNIT_END + 0x0060, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_22_4                     = UNIT_END + 0x0061, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_1                     = UNIT_END + 0x0062, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_23_2                     = UNIT_END + 0x0063, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_3                     = UNIT_END + 0x0064, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_23_4                     = UNIT_END + 0x0065, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_1                     = UNIT_END + 0x0066, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_24_2                     = UNIT_END + 0x0067, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_3                     = UNIT_END + 0x0068, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_24_4                     = UNIT_END + 0x0069, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_1                     = UNIT_END + 0x006A, // Size: 1, Type: INT, Flags: GROUP_ONLY
    PLAYER_QUEST_LOG_25_2                     = UNIT_END + 0x006B, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_3                     = UNIT_END + 0x006C, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_QUEST_LOG_25_4                     = UNIT_END + 0x006D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_VISIBLE_ITEM_1_CREATOR             = UNIT_END + 0x006E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_0                   = UNIT_END + 0x0070, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_PROPERTIES          = UNIT_END + 0x007C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_PAD                 = UNIT_END + 0x007D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_CREATOR             = UNIT_END + 0x007E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_0                   = UNIT_END + 0x0080, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_PROPERTIES          = UNIT_END + 0x008C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_PAD                 = UNIT_END + 0x008D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_CREATOR             = UNIT_END + 0x008E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_0                   = UNIT_END + 0x0090, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_PROPERTIES          = UNIT_END + 0x009C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_PAD                 = UNIT_END + 0x009D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_CREATOR             = UNIT_END + 0x009E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_0                   = UNIT_END + 0x00A0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_PROPERTIES          = UNIT_END + 0x00AC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_PAD                 = UNIT_END + 0x00AD, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_CREATOR             = UNIT_END + 0x00AE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_0                   = UNIT_END + 0x00B0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_PROPERTIES          = UNIT_END + 0x00BC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_PAD                 = UNIT_END + 0x00BD, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_CREATOR             = UNIT_END + 0x00BE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_0                   = UNIT_END + 0x00C0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_PROPERTIES          = UNIT_END + 0x00CC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_PAD                 = UNIT_END + 0x00CD, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_CREATOR             = UNIT_END + 0x00CE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_0                   = UNIT_END + 0x00D0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_PROPERTIES          = UNIT_END + 0x00DC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_PAD                 = UNIT_END + 0x00DD, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_CREATOR             = UNIT_END + 0x00DE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_0                   = UNIT_END + 0x00E0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_PROPERTIES          = UNIT_END + 0x00EC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_PAD                 = UNIT_END + 0x00ED, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_CREATOR             = UNIT_END + 0x00EE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_0                   = UNIT_END + 0x00F0, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_PROPERTIES          = UNIT_END + 0x00FC, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_PAD                 = UNIT_END + 0x00FD, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_CREATOR            = UNIT_END + 0x00FE, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_0                  = UNIT_END + 0x0100, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_PROPERTIES         = UNIT_END + 0x010C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_PAD                = UNIT_END + 0x010D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_CREATOR            = UNIT_END + 0x010E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_0                  = UNIT_END + 0x0110, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_PROPERTIES         = UNIT_END + 0x011C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_PAD                = UNIT_END + 0x011D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_CREATOR            = UNIT_END + 0x011E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_0                  = UNIT_END + 0x0120, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_PROPERTIES         = UNIT_END + 0x012C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_PAD                = UNIT_END + 0x012D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_CREATOR            = UNIT_END + 0x012E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_0                  = UNIT_END + 0x0130, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_PROPERTIES         = UNIT_END + 0x013C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_PAD                = UNIT_END + 0x013D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_CREATOR            = UNIT_END + 0x013E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_0                  = UNIT_END + 0x0140, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_PROPERTIES         = UNIT_END + 0x014C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_PAD                = UNIT_END + 0x014D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_CREATOR            = UNIT_END + 0x014E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_0                  = UNIT_END + 0x0150, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_PROPERTIES         = UNIT_END + 0x015C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_PAD                = UNIT_END + 0x015D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_CREATOR            = UNIT_END + 0x015E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_0                  = UNIT_END + 0x0160, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_PROPERTIES         = UNIT_END + 0x016C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_PAD                = UNIT_END + 0x016D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_CREATOR            = UNIT_END + 0x016E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_0                  = UNIT_END + 0x0170, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_PROPERTIES         = UNIT_END + 0x017C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_PAD                = UNIT_END + 0x017D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_CREATOR            = UNIT_END + 0x017E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_0                  = UNIT_END + 0x0180, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_PROPERTIES         = UNIT_END + 0x018C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_PAD                = UNIT_END + 0x018D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_CREATOR            = UNIT_END + 0x018E, // Size: 2, Type: LONG, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_0                  = UNIT_END + 0x0190, // Size: 12, Type: INT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_PROPERTIES         = UNIT_END + 0x019C, // Size: 1, Type: TWO_SHORT, Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_PAD                = UNIT_END + 0x019D, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_CHOSEN_TITLE                       = UNIT_END + 0x019E, // Size: 1, Type: INT, Flags: PUBLIC
    PLAYER_FIELD_PAD_0                        = UNIT_END + 0x019F, // Size: 1, Type: INT, Flags: NONE
    PLAYER_FIELD_INV_SLOT_HEAD                = UNIT_END + 0x01A0, // Size: 46, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_PACK_SLOT_1                  = UNIT_END + 0x01CE, // Size: 32, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANK_SLOT_1                  = UNIT_END + 0x01EE, // Size: 56, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_BANKBAG_SLOT_1               = UNIT_END + 0x0226, // Size: 14, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_VENDORBUYBACK_SLOT_1         = UNIT_END + 0x0234, // Size: 24, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_KEYRING_SLOT_1               = UNIT_END + 0x024C, // Size: 64, Type: LONG, Flags: PRIVATE
    PLAYER_FIELD_VANITYPET_SLOT_1             = UNIT_END + 0x028C, // Size: 36, Type: LONG, Flags: PRIVATE
    PLAYER_FARSIGHT                           = UNIT_END + 0x02B0, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES                = UNIT_END + 0x02B2, // Size: 2, Type: LONG, Flags: PRIVATE
    PLAYER_XP                                 = UNIT_END + 0x02B4, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                      = UNIT_END + 0x02B5, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SKILL_INFO_1_1                     = UNIT_END + 0x02B6, // Size: 384, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS1                  = UNIT_END + 0x0436, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS2                  = UNIT_END + 0x0437, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_CREATURES                    = UNIT_END + 0x0438, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                    = UNIT_END + 0x0439, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                   = UNIT_END + 0x043A, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                   = UNIT_END + 0x043B, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                   = UNIT_END + 0x043C, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_EXPERTISE                          = UNIT_END + 0x043D, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_OFFHAND_EXPERTISE                  = UNIT_END + 0x043E, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                    = UNIT_END + 0x043F, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE             = UNIT_END + 0x0440, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE            = UNIT_END + 0x0441, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1             = UNIT_END + 0x0442, // Size: 7, Type: FLOAT, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK                       = UNIT_END + 0x0449, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                   = UNIT_END + 0x044A, // Size: 128, Type: BYTES, Flags: PRIVATE
    PLAYER_REST_STATE_EXPERIENCE              = UNIT_END + 0x04CA, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COINAGE                      = UNIT_END + 0x04CB, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS          = UNIT_END + 0x04CC, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG          = UNIT_END + 0x04D3, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT          = UNIT_END + 0x04DA, // Size: 7, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS         = UNIT_END + 0x04E1, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE        = UNIT_END + 0x04E2, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE = UNIT_END + 0x04E3, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES                        = UNIT_END + 0x04E4, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_AMMO_ID                            = UNIT_END + 0x04E5, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_SELF_RES_SPELL                     = UNIT_END + 0x04E6, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                   = UNIT_END + 0x04E7, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1              = UNIT_END + 0x04E8, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1          = UNIT_END + 0x04F4, // Size: 12, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_KILLS                        = UNIT_END + 0x0500, // Size: 1, Type: TWO_SHORT, Flags: PRIVATE
    PLAYER_FIELD_TODAY_CONTRIBUTION           = UNIT_END + 0x0501, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_YESTERDAY_CONTRIBUTION       = UNIT_END + 0x0502, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_LIFETIME_HONORBALE_KILLS     = UNIT_END + 0x0503, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_BYTES2                       = UNIT_END + 0x0504, // Size: 1, Type: BYTES, Flags: PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX        = UNIT_END + 0x0505, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1              = UNIT_END + 0x0506, // Size: 24, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_ARENA_TEAM_INFO_1_1          = UNIT_END + 0x051E, // Size: 18, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_HONOR_CURRENCY               = UNIT_END + 0x0530, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_ARENA_CURRENCY               = UNIT_END + 0x0531, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_MOD_MANA_REGEN               = UNIT_END + 0x0532, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MOD_MANA_REGEN_INTERRUPT     = UNIT_END + 0x0533, // Size: 1, Type: FLOAT, Flags: PRIVATE
    PLAYER_FIELD_MAX_LEVEL                    = UNIT_END + 0x0534, // Size: 1, Type: INT, Flags: PRIVATE
    PLAYER_FIELD_DAILY_QUESTS_1               = UNIT_END + 0x0535, // Size: 25, Type: INT, Flags: PRIVATE
    PLAYER_END                                = UNIT_END + 0x054E,
};

enum EGameObjectFields
{
    OBJECT_FIELD_CREATED_BY                   = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    GAMEOBJECT_DISPLAYID                      = OBJECT_END + 0x0002, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_FLAGS                          = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_ROTATION                       = OBJECT_END + 0x0004, // Size: 4, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_STATE                          = OBJECT_END + 0x0008, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_POS_X                          = OBJECT_END + 0x0009, // Size: 1, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_POS_Y                          = OBJECT_END + 0x000A, // Size: 1, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_POS_Z                          = OBJECT_END + 0x000B, // Size: 1, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_FACING                         = OBJECT_END + 0x000C, // Size: 1, Type: FLOAT, Flags: PUBLIC
    GAMEOBJECT_DYN_FLAGS                      = OBJECT_END + 0x000D, // Size: 1, Type: INT, Flags: DYNAMIC
    GAMEOBJECT_FACTION                        = OBJECT_END + 0x000E, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_TYPE_ID                        = OBJECT_END + 0x000F, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_LEVEL                          = OBJECT_END + 0x0010, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_ARTKIT                         = OBJECT_END + 0x0011, // Size: 1, Type: INT, Flags: PUBLIC
    GAMEOBJECT_ANIMPROGRESS                   = OBJECT_END + 0x0012, // Size: 1, Type: INT, Flags: DYNAMIC
    GAMEOBJECT_PADDING                        = OBJECT_END + 0x0013, // Size: 1, Type: INT, Flags: NONE
    GAMEOBJECT_END                            = OBJECT_END + 0x0014,
};

enum EDynamicObjectFields
{
    DYNAMICOBJECT_CASTER                      = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    DYNAMICOBJECT_BYTES                       = OBJECT_END + 0x0002, // Size: 1, Type: BYTES, Flags: PUBLIC
    DYNAMICOBJECT_SPELLID                     = OBJECT_END + 0x0003, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                      = OBJECT_END + 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_POS_X                       = OBJECT_END + 0x0005, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_POS_Y                       = OBJECT_END + 0x0006, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_POS_Z                       = OBJECT_END + 0x0007, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_FACING                      = OBJECT_END + 0x0008, // Size: 1, Type: FLOAT, Flags: PUBLIC
    DYNAMICOBJECT_CASTTIME                    = OBJECT_END + 0x0009, // Size: 1, Type: INT, Flags: PUBLIC
    DYNAMICOBJECT_END                         = OBJECT_END + 0x000A,
};

enum ECorpseFields
{
    CORPSE_FIELD_OWNER                        = OBJECT_END + 0x0000, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_PARTY                        = OBJECT_END + 0x0002, // Size: 2, Type: LONG, Flags: PUBLIC
    CORPSE_FIELD_FACING                       = OBJECT_END + 0x0004, // Size: 1, Type: FLOAT, Flags: PUBLIC
    CORPSE_FIELD_POS_X                        = OBJECT_END + 0x0005, // Size: 1, Type: FLOAT, Flags: PUBLIC
    CORPSE_FIELD_POS_Y                        = OBJECT_END + 0x0006, // Size: 1, Type: FLOAT, Flags: PUBLIC
    CORPSE_FIELD_POS_Z                        = OBJECT_END + 0x0007, // Size: 1, Type: FLOAT, Flags: PUBLIC
    CORPSE_FIELD_DISPLAY_ID                   = OBJECT_END + 0x0008, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_ITEM                         = OBJECT_END + 0x0009, // Size: 19, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_BYTES_1                      = OBJECT_END + 0x001C, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_BYTES_2                      = OBJECT_END + 0x001D, // Size: 1, Type: BYTES, Flags: PUBLIC
    CORPSE_FIELD_GUILD                        = OBJECT_END + 0x001E, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_FLAGS                        = OBJECT_END + 0x001F, // Size: 1, Type: INT, Flags: PUBLIC
    CORPSE_FIELD_DYNAMIC_FLAGS                = OBJECT_END + 0x0020, // Size: 1, Type: INT, Flags: DYNAMIC
    CORPSE_FIELD_PAD                          = OBJECT_END + 0x0021, // Size: 1, Type: INT, Flags: NONE
    CORPSE_END                                = OBJECT_END + 0x0022,
};
#endif

