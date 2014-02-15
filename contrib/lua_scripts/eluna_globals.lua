--[[
    EmuDevs <http:emudevs.com/forum.php>
    Eluna Lua Engine <https://github.com/ElunaLuaEngine/Eluna>
    Eluna Scripts <https://github.com/ElunaLuaEngine/Scripts>
    Eluna Wiki <http://wiki.emudevs.com/doku.php?id=eluna>

    Eluna Globals
    
    Copyright (C) 2014 EmuDevs <http://www.emudevs.com/>
--]]
--------------------------------------------------------
--[[
     COMMON
--]]
--------------------------------------------------------
-- TIME CONSTANTS
MINUTE          = 60
HOUR            = MINUTE*60
DAY             = HOUR*24
WEEK            = DAY*7
MONTH           = DAY*30
YEAR            = MONTH*12
IN_MILLISECONDS = 1000
-- LOCALE CONSTANTS
LOCALE_enUS   = 0
LOCALE_koKR   = 1
LOCALE_frFR   = 2
LOCALE_deDE   = 3
LOCALE_zhCN   = 4
LOCALE_zhTW   = 5
LOCALE_esES   = 6
LOCALE_esMX   = 7
LOCALE_ruRU   = 8
MAX_LOCALES   = 8 -- MAX LOCALES
TOTAL_LOCALES = 9 -- TOTAL LOCALES
-- ACCOUNT TYPES
SEC_PLAYER         = 0
SEC_MODERATOR      = 1
SEC_GAMEMASTER     = 2
SEC_ADMINISTRATOR  = 3
SEC_CONSOLE        = 4 -- must be always last in list, accounts must have less security level always also
--------------------------------------------------------
--[[
     OBJECT FIELDS
--]]
--------------------------------------------------------
-- OBJECT FIELD TYPES
OBJECT_FIELD_GUID                         = 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
OBJECT_FIELD_TYPE                         = 0x0002 -- Size: 1, Type: INT, Flags: PUBLIC
OBJECT_FIELD_ENTRY                        = 0x0003 -- Size: 1, Type: INT, Flags: PUBLIC
OBJECT_FIELD_SCALE_X                      = 0x0004 -- Size: 1, Type: FLOAT, Flags: PUBLIC
OBJECT_FIELD_PADDING                      = 0x0005 -- Size: 1, Type: INT, Flags: NONE
local OBJECT_END                          = 0x0006
local ITEM_END                            = OBJECT_END + 0x003A
local UNIT_END                            = OBJECT_END + 0x008E
local PLAYER_END                          = UNIT_END + 0x049A
local GAMEOBJECT_END                      = OBJECT_END + 0x000C
local DYNAMICOBJECT_END                   = OBJECT_END + 0x0006
local CORPSE_END                          = OBJECT_END + 0x001E
-- ITEM FIELD TYPES
ITEM_FIELD_OWNER                          = OBJECT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
ITEM_FIELD_CONTAINED                      = OBJECT_END + 0x0002 -- Size: 2, Type: LONG, Flags: PUBLIC
ITEM_FIELD_CREATOR                        = OBJECT_END + 0x0004 -- Size: 2, Type: LONG, Flags: PUBLIC
ITEM_FIELD_GIFTCREATOR                    = OBJECT_END + 0x0006 -- Size: 2, Type: LONG, Flags: PUBLIC
ITEM_FIELD_STACK_COUNT                    = OBJECT_END + 0x0008 -- Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
ITEM_FIELD_DURATION                       = OBJECT_END + 0x0009 -- Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
ITEM_FIELD_SPELL_CHARGES                  = OBJECT_END + 0x000A -- Size: 5, Type: INT, Flags: OWNER, ITEM_OWNER
ITEM_FIELD_FLAGS                          = OBJECT_END + 0x000F -- Size: 1, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_1_1                = OBJECT_END + 0x0010 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_1_3                = OBJECT_END + 0x0012 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_2_1                = OBJECT_END + 0x0013 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_2_3                = OBJECT_END + 0x0015 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_3_1                = OBJECT_END + 0x0016 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_3_3                = OBJECT_END + 0x0018 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_4_1                = OBJECT_END + 0x0019 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_4_3                = OBJECT_END + 0x001B -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_5_1                = OBJECT_END + 0x001C -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_5_3                = OBJECT_END + 0x001E -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_6_1                = OBJECT_END + 0x001F -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_6_3                = OBJECT_END + 0x0021 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_7_1                = OBJECT_END + 0x0022 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_7_3                = OBJECT_END + 0x0024 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_8_1                = OBJECT_END + 0x0025 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_8_3                = OBJECT_END + 0x0027 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_9_1                = OBJECT_END + 0x0028 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_9_3                = OBJECT_END + 0x002A -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_10_1               = OBJECT_END + 0x002B -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_10_3               = OBJECT_END + 0x002D -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_11_1               = OBJECT_END + 0x002E -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_11_3               = OBJECT_END + 0x0030 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_12_1               = OBJECT_END + 0x0031 -- Size: 2, Type: INT, Flags: PUBLIC
ITEM_FIELD_ENCHANTMENT_12_3               = OBJECT_END + 0x0033 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
ITEM_FIELD_PROPERTY_SEED                  = OBJECT_END + 0x0034 -- Size: 1, Type: INT, Flags: PUBLIC
ITEM_FIELD_RANDOM_PROPERTIES_ID           = OBJECT_END + 0x0035 -- Size: 1, Type: INT, Flags: PUBLIC
ITEM_FIELD_DURABILITY                     = OBJECT_END + 0x0036 -- Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
ITEM_FIELD_MAXDURABILITY                  = OBJECT_END + 0x0037 -- Size: 1, Type: INT, Flags: OWNER, ITEM_OWNER
ITEM_FIELD_CREATE_PLAYED_TIME             = OBJECT_END + 0x0038 -- Size: 1, Type: INT, Flags: PUBLIC
ITEM_FIELD_PAD                            = OBJECT_END + 0x0039 -- Size: 1, Type: INT, Flags: NONE
-- CONTAINER FIELD TYPES
CONTAINER_FIELD_NUM_SLOTS                 = ITEM_END + 0x0000 -- Size: 1, Type: INT, Flags: PUBLIC
CONTAINER_ALIGN_PAD                       = ITEM_END + 0x0001 -- Size: 1, Type: BYTES, Flags: NONE
CONTAINER_FIELD_SLOT_1                    = ITEM_END + 0x0002 -- Size: 72, Type: LONG, Flags: PUBLIC
CONTAINER_END                             = ITEM_END + 0x004A
-- UNIT FIELD TYPES
UNIT_FIELD_CHARM                          = OBJECT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_SUMMON                         = OBJECT_END + 0x0002 -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_CRITTER                        = OBJECT_END + 0x0004 -- Size: 2, Type: LONG, Flags: PRIVATE
UNIT_FIELD_CHARMEDBY                      = OBJECT_END + 0x0006 -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_SUMMONEDBY                     = OBJECT_END + 0x0008 -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_CREATEDBY                      = OBJECT_END + 0x000A -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_TARGET                         = OBJECT_END + 0x000C -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_FIELD_CHANNEL_OBJECT                 = OBJECT_END + 0x000E -- Size: 2, Type: LONG, Flags: PUBLIC
UNIT_CHANNEL_SPELL                        = OBJECT_END + 0x0010 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_BYTES_0                        = OBJECT_END + 0x0011 -- Size: 1, Type: BYTES, Flags: PUBLIC
UNIT_FIELD_HEALTH                         = OBJECT_END + 0x0012 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER1                         = OBJECT_END + 0x0013 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER2                         = OBJECT_END + 0x0014 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER3                         = OBJECT_END + 0x0015 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER4                         = OBJECT_END + 0x0016 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER5                         = OBJECT_END + 0x0017 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER6                         = OBJECT_END + 0x0018 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER7                         = OBJECT_END + 0x0019 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXHEALTH                      = OBJECT_END + 0x001A -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER1                      = OBJECT_END + 0x001B -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER2                      = OBJECT_END + 0x001C -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER3                      = OBJECT_END + 0x001D -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER4                      = OBJECT_END + 0x001E -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER5                      = OBJECT_END + 0x001F -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER6                      = OBJECT_END + 0x0020 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MAXPOWER7                      = OBJECT_END + 0x0021 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER      = OBJECT_END + 0x0022 -- Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER = OBJECT_END + 0x0029 -- Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_LEVEL                          = OBJECT_END + 0x0030 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_FACTIONTEMPLATE                = OBJECT_END + 0x0031 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_VIRTUAL_ITEM_SLOT_ID                 = OBJECT_END + 0x0032 -- Size: 3, Type: INT, Flags: PUBLIC
UNIT_FIELD_FLAGS                          = OBJECT_END + 0x0035 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_FLAGS_2                        = OBJECT_END + 0x0036 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_AURASTATE                      = OBJECT_END + 0x0037 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_BASEATTACKTIME                 = OBJECT_END + 0x0038 -- Size: 2, Type: INT, Flags: PUBLIC
UNIT_FIELD_RANGEDATTACKTIME               = OBJECT_END + 0x003A -- Size: 1, Type: INT, Flags: PRIVATE
UNIT_FIELD_BOUNDINGRADIUS                 = OBJECT_END + 0x003B -- Size: 1, Type: FLOAT, Flags: PUBLIC
UNIT_FIELD_COMBATREACH                    = OBJECT_END + 0x003C -- Size: 1, Type: FLOAT, Flags: PUBLIC
UNIT_FIELD_DISPLAYID                      = OBJECT_END + 0x003D -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_NATIVEDISPLAYID                = OBJECT_END + 0x003E -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MOUNTDISPLAYID                 = OBJECT_END + 0x003F -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_MINDAMAGE                      = OBJECT_END + 0x0040 -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
UNIT_FIELD_MAXDAMAGE                      = OBJECT_END + 0x0041 -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
UNIT_FIELD_MINOFFHANDDAMAGE               = OBJECT_END + 0x0042 -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
UNIT_FIELD_MAXOFFHANDDAMAGE               = OBJECT_END + 0x0043 -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER, PARTY_LEADER
UNIT_FIELD_BYTES_1                        = OBJECT_END + 0x0044 -- Size: 1, Type: BYTES, Flags: PUBLIC
UNIT_FIELD_PETNUMBER                      = OBJECT_END + 0x0045 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_PET_NAME_TIMESTAMP             = OBJECT_END + 0x0046 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_PETEXPERIENCE                  = OBJECT_END + 0x0047 -- Size: 1, Type: INT, Flags: OWNER
UNIT_FIELD_PETNEXTLEVELEXP                = OBJECT_END + 0x0048 -- Size: 1, Type: INT, Flags: OWNER
UNIT_DYNAMIC_FLAGS                        = OBJECT_END + 0x0049 -- Size: 1, Type: INT, Flags: DYNAMIC
UNIT_MOD_CAST_SPEED                       = OBJECT_END + 0x004A -- Size: 1, Type: FLOAT, Flags: PUBLIC
UNIT_CREATED_BY_SPELL                     = OBJECT_END + 0x004B -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_NPC_FLAGS                            = OBJECT_END + 0x004C -- Size: 1, Type: INT, Flags: DYNAMIC
UNIT_NPC_EMOTESTATE                       = OBJECT_END + 0x004D -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_STAT0                          = OBJECT_END + 0x004E -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_STAT1                          = OBJECT_END + 0x004F -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_STAT2                          = OBJECT_END + 0x0050 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_STAT3                          = OBJECT_END + 0x0051 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_STAT4                          = OBJECT_END + 0x0052 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POSSTAT0                       = OBJECT_END + 0x0053 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POSSTAT1                       = OBJECT_END + 0x0054 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POSSTAT2                       = OBJECT_END + 0x0055 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POSSTAT3                       = OBJECT_END + 0x0056 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POSSTAT4                       = OBJECT_END + 0x0057 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_NEGSTAT0                       = OBJECT_END + 0x0058 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_NEGSTAT1                       = OBJECT_END + 0x0059 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_NEGSTAT2                       = OBJECT_END + 0x005A -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_NEGSTAT3                       = OBJECT_END + 0x005B -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_NEGSTAT4                       = OBJECT_END + 0x005C -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_RESISTANCES                    = OBJECT_END + 0x005D -- Size: 7, Type: INT, Flags: PRIVATE, OWNER, PARTY_LEADER
UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE     = OBJECT_END + 0x0064 -- Size: 7, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE     = OBJECT_END + 0x006B -- Size: 7, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_BASE_MANA                      = OBJECT_END + 0x0072 -- Size: 1, Type: INT, Flags: PUBLIC
UNIT_FIELD_BASE_HEALTH                    = OBJECT_END + 0x0073 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_BYTES_2                        = OBJECT_END + 0x0074 -- Size: 1, Type: BYTES, Flags: PUBLIC
UNIT_FIELD_ATTACK_POWER                   = OBJECT_END + 0x0075 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_ATTACK_POWER_MODS              = OBJECT_END + 0x0076 -- Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
UNIT_FIELD_ATTACK_POWER_MULTIPLIER        = OBJECT_END + 0x0077 -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_RANGED_ATTACK_POWER            = OBJECT_END + 0x0078 -- Size: 1, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_RANGED_ATTACK_POWER_MODS       = OBJECT_END + 0x0079 -- Size: 1, Type: TWO_SHORT, Flags: PRIVATE, OWNER
UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER = OBJECT_END + 0x007A -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_MINRANGEDDAMAGE                = OBJECT_END + 0x007B -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_MAXRANGEDDAMAGE                = OBJECT_END + 0x007C -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_POWER_COST_MODIFIER            = OBJECT_END + 0x007D -- Size: 7, Type: INT, Flags: PRIVATE, OWNER
UNIT_FIELD_POWER_COST_MULTIPLIER          = OBJECT_END + 0x0084 -- Size: 7, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_MAXHEALTHMODIFIER              = OBJECT_END + 0x008B -- Size: 1, Type: FLOAT, Flags: PRIVATE, OWNER
UNIT_FIELD_HOVERHEIGHT                    = OBJECT_END + 0x008C -- Size: 1, Type: FLOAT, Flags: PUBLIC
UNIT_FIELD_PADDING                        = OBJECT_END + 0x008D -- Size: 1, Type: INT, Flags: NONE

PLAYER_DUEL_ARBITER                       = UNIT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
PLAYER_FLAGS                              = UNIT_END + 0x0002 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_GUILDID                            = UNIT_END + 0x0003 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_GUILDRANK                          = UNIT_END + 0x0004 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_BYTES                              = UNIT_END + 0x0005 -- Size: 1, Type: BYTES, Flags: PUBLIC
PLAYER_BYTES_2                            = UNIT_END + 0x0006 -- Size: 1, Type: BYTES, Flags: PUBLIC
PLAYER_BYTES_3                            = UNIT_END + 0x0007 -- Size: 1, Type: BYTES, Flags: PUBLIC
PLAYER_DUEL_TEAM                          = UNIT_END + 0x0008 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_GUILD_TIMESTAMP                    = UNIT_END + 0x0009 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_QUEST_LOG_1_1                      = UNIT_END + 0x000A -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_1_2                      = UNIT_END + 0x000B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_1_3                      = UNIT_END + 0x000C -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_1_4                      = UNIT_END + 0x000E -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_2_1                      = UNIT_END + 0x000F -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_2_2                      = UNIT_END + 0x0010 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_2_3                      = UNIT_END + 0x0011 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_2_5                      = UNIT_END + 0x0013 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_3_1                      = UNIT_END + 0x0014 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_3_2                      = UNIT_END + 0x0015 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_3_3                      = UNIT_END + 0x0016 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_3_5                      = UNIT_END + 0x0018 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_4_1                      = UNIT_END + 0x0019 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_4_2                      = UNIT_END + 0x001A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_4_3                      = UNIT_END + 0x001B -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_4_5                      = UNIT_END + 0x001D -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_5_1                      = UNIT_END + 0x001E -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_5_2                      = UNIT_END + 0x001F -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_5_3                      = UNIT_END + 0x0020 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_5_5                      = UNIT_END + 0x0022 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_6_1                      = UNIT_END + 0x0023 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_6_2                      = UNIT_END + 0x0024 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_6_3                      = UNIT_END + 0x0025 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_6_5                      = UNIT_END + 0x0027 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_7_1                      = UNIT_END + 0x0028 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_7_2                      = UNIT_END + 0x0029 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_7_3                      = UNIT_END + 0x002A -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_7_5                      = UNIT_END + 0x002C -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_8_1                      = UNIT_END + 0x002D -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_8_2                      = UNIT_END + 0x002E -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_8_3                      = UNIT_END + 0x002F -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_8_5                      = UNIT_END + 0x0031 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_9_1                      = UNIT_END + 0x0032 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_9_2                      = UNIT_END + 0x0033 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_9_3                      = UNIT_END + 0x0034 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_9_5                      = UNIT_END + 0x0036 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_10_1                     = UNIT_END + 0x0037 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_10_2                     = UNIT_END + 0x0038 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_10_3                     = UNIT_END + 0x0039 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_10_5                     = UNIT_END + 0x003B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_11_1                     = UNIT_END + 0x003C -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_11_2                     = UNIT_END + 0x003D -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_11_3                     = UNIT_END + 0x003E -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_11_5                     = UNIT_END + 0x0040 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_12_1                     = UNIT_END + 0x0041 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_12_2                     = UNIT_END + 0x0042 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_12_3                     = UNIT_END + 0x0043 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_12_5                     = UNIT_END + 0x0045 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_13_1                     = UNIT_END + 0x0046 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_13_2                     = UNIT_END + 0x0047 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_13_3                     = UNIT_END + 0x0048 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_13_5                     = UNIT_END + 0x004A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_14_1                     = UNIT_END + 0x004B -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_14_2                     = UNIT_END + 0x004C -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_14_3                     = UNIT_END + 0x004D -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_14_5                     = UNIT_END + 0x004F -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_15_1                     = UNIT_END + 0x0050 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_15_2                     = UNIT_END + 0x0051 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_15_3                     = UNIT_END + 0x0052 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_15_5                     = UNIT_END + 0x0054 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_16_1                     = UNIT_END + 0x0055 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_16_2                     = UNIT_END + 0x0056 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_16_3                     = UNIT_END + 0x0057 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_16_5                     = UNIT_END + 0x0059 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_17_1                     = UNIT_END + 0x005A -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_17_2                     = UNIT_END + 0x005B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_17_3                     = UNIT_END + 0x005C -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_17_5                     = UNIT_END + 0x005E -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_18_1                     = UNIT_END + 0x005F -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_18_2                     = UNIT_END + 0x0060 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_18_3                     = UNIT_END + 0x0061 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_18_5                     = UNIT_END + 0x0063 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_19_1                     = UNIT_END + 0x0064 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_19_2                     = UNIT_END + 0x0065 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_19_3                     = UNIT_END + 0x0066 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_19_5                     = UNIT_END + 0x0068 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_20_1                     = UNIT_END + 0x0069 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_20_2                     = UNIT_END + 0x006A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_20_3                     = UNIT_END + 0x006B -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_20_5                     = UNIT_END + 0x006D -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_21_1                     = UNIT_END + 0x006E -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_21_2                     = UNIT_END + 0x006F -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_21_3                     = UNIT_END + 0x0070 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_21_5                     = UNIT_END + 0x0072 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_22_1                     = UNIT_END + 0x0073 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_22_2                     = UNIT_END + 0x0074 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_22_3                     = UNIT_END + 0x0075 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_22_5                     = UNIT_END + 0x0077 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_23_1                     = UNIT_END + 0x0078 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_23_2                     = UNIT_END + 0x0079 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_23_3                     = UNIT_END + 0x007A -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_23_5                     = UNIT_END + 0x007C -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_24_1                     = UNIT_END + 0x007D -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_24_2                     = UNIT_END + 0x007E -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_24_3                     = UNIT_END + 0x007F -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_24_5                     = UNIT_END + 0x0081 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_25_1                     = UNIT_END + 0x0082 -- Size: 1, Type: INT, Flags: PARTY_MEMBER
PLAYER_QUEST_LOG_25_2                     = UNIT_END + 0x0083 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_QUEST_LOG_25_3                     = UNIT_END + 0x0084 -- Size: 2, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_QUEST_LOG_25_5                     = UNIT_END + 0x0086 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_VISIBLE_ITEM_1_ENTRYID             = UNIT_END + 0x0087 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_1_ENCHANTMENT         = UNIT_END + 0x0088 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_2_ENTRYID             = UNIT_END + 0x0089 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_2_ENCHANTMENT         = UNIT_END + 0x008A -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_3_ENTRYID             = UNIT_END + 0x008B -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_3_ENCHANTMENT         = UNIT_END + 0x008C -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_4_ENTRYID             = UNIT_END + 0x008D -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_4_ENCHANTMENT         = UNIT_END + 0x008E -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_5_ENTRYID             = UNIT_END + 0x008F -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_5_ENCHANTMENT         = UNIT_END + 0x0090 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_6_ENTRYID             = UNIT_END + 0x0091 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_6_ENCHANTMENT         = UNIT_END + 0x0092 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_7_ENTRYID             = UNIT_END + 0x0093 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_7_ENCHANTMENT         = UNIT_END + 0x0094 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_8_ENTRYID             = UNIT_END + 0x0095 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_8_ENCHANTMENT         = UNIT_END + 0x0096 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_9_ENTRYID             = UNIT_END + 0x0097 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_9_ENCHANTMENT         = UNIT_END + 0x0098 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_10_ENTRYID            = UNIT_END + 0x0099 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_10_ENCHANTMENT        = UNIT_END + 0x009A -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_11_ENTRYID            = UNIT_END + 0x009B -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_11_ENCHANTMENT        = UNIT_END + 0x009C -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_12_ENTRYID            = UNIT_END + 0x009D -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_12_ENCHANTMENT        = UNIT_END + 0x009E -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_13_ENTRYID            = UNIT_END + 0x009F -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_13_ENCHANTMENT        = UNIT_END + 0x00A0 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_14_ENTRYID            = UNIT_END + 0x00A1 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_14_ENCHANTMENT        = UNIT_END + 0x00A2 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_15_ENTRYID            = UNIT_END + 0x00A3 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_15_ENCHANTMENT        = UNIT_END + 0x00A4 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_16_ENTRYID            = UNIT_END + 0x00A5 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_16_ENCHANTMENT        = UNIT_END + 0x00A6 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_17_ENTRYID            = UNIT_END + 0x00A7 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_17_ENCHANTMENT        = UNIT_END + 0x00A8 -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_18_ENTRYID            = UNIT_END + 0x00A9 -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_18_ENCHANTMENT        = UNIT_END + 0x00AA -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_19_ENTRYID            = UNIT_END + 0x00AB -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_VISIBLE_ITEM_19_ENCHANTMENT        = UNIT_END + 0x00AC -- Size: 1, Type: TWO_SHORT, Flags: PUBLIC
PLAYER_CHOSEN_TITLE                       = UNIT_END + 0x00AD -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_FAKE_INEBRIATION                   = UNIT_END + 0x00AE -- Size: 1, Type: INT, Flags: PUBLIC
PLAYER_FIELD_PAD_0                        = UNIT_END + 0x00AF -- Size: 1, Type: INT, Flags: NONE
PLAYER_FIELD_INV_SLOT_HEAD                = UNIT_END + 0x00B0 -- Size: 46, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_PACK_SLOT_1                  = UNIT_END + 0x00DE -- Size: 32, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_BANK_SLOT_1                  = UNIT_END + 0x00FE -- Size: 56, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_BANKBAG_SLOT_1               = UNIT_END + 0x0136 -- Size: 14, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_VENDORBUYBACK_SLOT_1         = UNIT_END + 0x0144 -- Size: 24, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_KEYRING_SLOT_1               = UNIT_END + 0x015C -- Size: 64, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_CURRENCYTOKEN_SLOT_1         = UNIT_END + 0x019C -- Size: 64, Type: LONG, Flags: PRIVATE
PLAYER_FARSIGHT                           = UNIT_END + 0x01DC -- Size: 2, Type: LONG, Flags: PRIVATE
PLAYER__FIELD_KNOWN_TITLES                 = UNIT_END + 0x01DE -- Size: 2, Type: LONG, Flags: PRIVATE
PLAYER__FIELD_KNOWN_TITLES1                = UNIT_END + 0x01E0 -- Size: 2, Type: LONG, Flags: PRIVATE
PLAYER__FIELD_KNOWN_TITLES2                = UNIT_END + 0x01E2 -- Size: 2, Type: LONG, Flags: PRIVATE
PLAYER_FIELD_KNOWN_CURRENCIES             = UNIT_END + 0x01E4 -- Size: 2, Type: LONG, Flags: PRIVATE
PLAYER_XP                                 = UNIT_END + 0x01E6 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_NEXT_LEVEL_XP                      = UNIT_END + 0x01E7 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_SKILL_INFO_1_1                     = UNIT_END + 0x01E8 -- Size: 384, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_CHARACTER_POINTS1                  = UNIT_END + 0x0368 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_CHARACTER_POINTS2                  = UNIT_END + 0x0369 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_TRACK_CREATURES                    = UNIT_END + 0x036A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_TRACK_RESOURCES                    = UNIT_END + 0x036B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_BLOCK_PERCENTAGE                   = UNIT_END + 0x036C -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_DODGE_PERCENTAGE                   = UNIT_END + 0x036D -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_PARRY_PERCENTAGE                   = UNIT_END + 0x036E -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_EXPERTISE                          = UNIT_END + 0x036F -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_OFFHAND_EXPERTISE                  = UNIT_END + 0x0370 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_CRIT_PERCENTAGE                    = UNIT_END + 0x0371 -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_RANGED_CRIT_PERCENTAGE             = UNIT_END + 0x0372 -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_OFFHAND_CRIT_PERCENTAGE            = UNIT_END + 0x0373 -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_SPELL_CRIT_PERCENTAGE1             = UNIT_END + 0x0374 -- Size: 7, Type: FLOAT, Flags: PRIVATE
PLAYER_SHIELD_BLOCK                       = UNIT_END + 0x037B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE       = UNIT_END + 0x037C -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_EXPLORED_ZONES_1                   = UNIT_END + 0x037D -- Size: 128, Type: BYTES, Flags: PRIVATE
PLAYER_REST_STATE_EXPERIENCE              = UNIT_END + 0x03FD -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_COINAGE                      = UNIT_END + 0x03FE -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_DAMAGE_DONE_POS          = UNIT_END + 0x03FF -- Size: 7, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_DAMAGE_DONE_NEG          = UNIT_END + 0x0406 -- Size: 7, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_DAMAGE_DONE_PCT          = UNIT_END + 0x040D -- Size: 7, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_HEALING_DONE_POS         = UNIT_END + 0x0414 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_HEALING_PCT              = UNIT_END + 0x0415 -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_FIELD_MOD_HEALING_DONE_PCT         = UNIT_END + 0x0416 -- Size: 1, Type: FLOAT, Flags: PRIVATE
PLAYER_FIELD_MOD_TARGET_RESISTANCE        = UNIT_END + 0x0417 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE = UNIT_END + 0x0418 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_BYTES                        = UNIT_END + 0x0419 -- Size: 1, Type: BYTES, Flags: PRIVATE
PLAYER_AMMO_ID                            = UNIT_END + 0x041A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_SELF_RES_SPELL                     = UNIT_END + 0x041B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_PVP_MEDALS                   = UNIT_END + 0x041C -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_BUYBACK_PRICE_1              = UNIT_END + 0x041D -- Size: 12, Type: INT, Flags: PRIVATE
PLAYER_FIELD_BUYBACK_TIMESTAMP_1          = UNIT_END + 0x0429 -- Size: 12, Type: INT, Flags: PRIVATE
PLAYER_FIELD_KILLS                        = UNIT_END + 0x0435 -- Size: 1, Type: TWO_SHORT, Flags: PRIVATE
PLAYER_FIELD_TODAY_CONTRIBUTION           = UNIT_END + 0x0436 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_YESTERDAY_CONTRIBUTION       = UNIT_END + 0x0437 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_LIFETIME_HONORABLE_KILLS     = UNIT_END + 0x0438 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_BYTES2                       = UNIT_END + 0x0439 -- Size: 1, Type: 6, Flags: PRIVATE
PLAYER_FIELD_WATCHED_FACTION_INDEX        = UNIT_END + 0x043A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_COMBAT_RATING_1              = UNIT_END + 0x043B -- Size: 25, Type: INT, Flags: PRIVATE
PLAYER_FIELD_ARENA_TEAM_INFO_1_1          = UNIT_END + 0x0454 -- Size: 21, Type: INT, Flags: PRIVATE
PLAYER_FIELD_HONOR_CURRENCY               = UNIT_END + 0x0469 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_ARENA_CURRENCY               = UNIT_END + 0x046A -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_MAX_LEVEL                    = UNIT_END + 0x046B -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_FIELD_DAILY_QUESTS_1               = UNIT_END + 0x046C -- Size: 25, Type: INT, Flags: PRIVATE
PLAYER_RUNE_REGEN_1                       = UNIT_END + 0x0485 -- Size: 4, Type: FLOAT, Flags: PRIVATE
PLAYER_NO_REAGENT_COST_1                  = UNIT_END + 0x0489 -- Size: 3, Type: INT, Flags: PRIVATE
PLAYER_FIELD_GLYPH_SLOTS_1                = UNIT_END + 0x048C -- Size: 6, Type: INT, Flags: PRIVATE
PLAYER_FIELD_GLYPHS_1                     = UNIT_END + 0x0492 -- Size: 6, Type: INT, Flags: PRIVATE
PLAYER_GLYPHS_ENABLED                     = UNIT_END + 0x0498 -- Size: 1, Type: INT, Flags: PRIVATE
PLAYER_PET_SPELL_POWER                    = UNIT_END + 0x0499 -- Size: 1, Type: INT, Flags: PRIVATE
-- GAMEOBJECT FIELD TYPES
OBJECT_FIELD_CREATED_BY                   = OBJECT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
GAMEOBJECT_DISPLAYID                      = OBJECT_END + 0x0002 -- Size: 1, Type: INT, Flags: PUBLIC
GAMEOBJECT_FLAGS                          = OBJECT_END + 0x0003 -- Size: 1, Type: INT, Flags: PUBLIC
GAMEOBJECT_PARENTROTATION                 = OBJECT_END + 0x0004 -- Size: 4, Type: FLOAT, Flags: PUBLIC
GAMEOBJECT_DYNAMIC                        = OBJECT_END + 0x0008 -- Size: 1, Type: TWO_SHORT, Flags: DYNAMIC
GAMEOBJECT_FACTION                        = OBJECT_END + 0x0009 -- Size: 1, Type: INT, Flags: PUBLIC
GAMEOBJECT_LEVEL                          = OBJECT_END + 0x000A -- Size: 1, Type: INT, Flags: PUBLIC
GAMEOBJECT_BYTES_1                        = OBJECT_END + 0x000B -- Size: 1, Type: BYTES, Flags: PUBLIC
-- DYNAMIC FIELD TYPES
DYNAMICOBJECT_CASTER                      = OBJECT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
DYNAMICOBJECT_BYTES                       = OBJECT_END + 0x0002 -- Size: 1, Type: BYTES, Flags: PUBLIC
DYNAMICOBJECT_SPELLID                     = OBJECT_END + 0x0003 -- Size: 1, Type: INT, Flags: PUBLIC
DYNAMICOBJECT_RADIUS                      = OBJECT_END + 0x0004 -- Size: 1, Type: FLOAT, Flags: PUBLIC
DYNAMICOBJECT_CASTTIME                    = OBJECT_END + 0x0005 -- Size: 1, Type: INT, Flags: PUBLIC
-- CORPSE FIELD TYPES
CORPSE_FIELD_OWNER                        = OBJECT_END + 0x0000 -- Size: 2, Type: LONG, Flags: PUBLIC
CORPSE_FIELD_PARTY                        = OBJECT_END + 0x0002 -- Size: 2, Type: LONG, Flags: PUBLIC
CORPSE_FIELD_DISPLAY_ID                   = OBJECT_END + 0x0004 -- Size: 1, Type: INT, Flags: PUBLIC
CORPSE_FIELD_ITEM                         = OBJECT_END + 0x0005 -- Size: 19, Type: INT, Flags: PUBLIC
CORPSE_FIELD_BYTES_1                      = OBJECT_END + 0x0018 -- Size: 1, Type: BYTES, Flags: PUBLIC
CORPSE_FIELD_BYTES_2                      = OBJECT_END + 0x0019 -- Size: 1, Type: BYTES, Flags: PUBLIC
CORPSE_FIELD_GUILD                        = OBJECT_END + 0x001A -- Size: 1, Type: INT, Flags: PUBLIC
CORPSE_FIELD_FLAGS                        = OBJECT_END + 0x001B -- Size: 1, Type: INT, Flags: PUBLIC
CORPSE_FIELD_DYNAMIC_FLAGS                = OBJECT_END + 0x001C -- Size: 1, Type: INT, Flags: DYNAMIC
CORPSE_FIELD_PAD                          = OBJECT_END + 0x001D -- Size: 1, Type: INT, Flags: NONE
--------------------------------------------------------
--[[
     ITEM PROTOTYPES
--]]
--------------------------------------------------------
MAX_ITEM_PROTO_DAMAGES            = 2
MAX_ITEM_PROTO_SOCKETS            = 3
MAX_ITEM_PROTO_SPELLS             = 5
MAX_ITEM_PROTO_STATS              = 10
-- ITEM MOD TYPES
ITEM_MOD_MANA                     = 0
ITEM_MOD_HEALTH                   = 1
ITEM_MOD_AGILITY                  = 3
ITEM_MOD_STRENGTH                 = 4
ITEM_MOD_INTELLECT                = 5
ITEM_MOD_SPIRIT                   = 6
ITEM_MOD_STAMINA                  = 7
ITEM_MOD_DEFENSE_SKILL_RATING     = 12
ITEM_MOD_DODGE_RATING             = 13
ITEM_MOD_PARRY_RATING             = 14
ITEM_MOD_BLOCK_RATING             = 15
ITEM_MOD_HIT_MELEE_RATING         = 16
ITEM_MOD_HIT_RANGED_RATING        = 17
ITEM_MOD_HIT_SPELL_RATING         = 18
ITEM_MOD_CRIT_MELEE_RATING        = 19
ITEM_MOD_CRIT_RANGED_RATING       = 20
ITEM_MOD_CRIT_SPELL_RATING        = 21
ITEM_MOD_HIT_TAKEN_MELEE_RATING   = 22
ITEM_MOD_HIT_TAKEN_RANGED_RATING  = 23
ITEM_MOD_HIT_TAKEN_SPELL_RATING   = 24
ITEM_MOD_CRIT_TAKEN_MELEE_RATING  = 25
ITEM_MOD_CRIT_TAKEN_RANGED_RATING = 26
ITEM_MOD_CRIT_TAKEN_SPELL_RATING  = 27
ITEM_MOD_HASTE_MELEE_RATING       = 28
ITEM_MOD_HASTE_RANGED_RATING      = 29
ITEM_MOD_HASTE_SPELL_RATING       = 30
ITEM_MOD_HIT_RATING               = 31
ITEM_MOD_CRIT_RATING              = 32
ITEM_MOD_HIT_TAKEN_RATING         = 33
ITEM_MOD_CRIT_TAKEN_RATING        = 34
ITEM_MOD_RESILIENCE_RATING        = 35
ITEM_MOD_HASTE_RATING             = 36
ITEM_MOD_EXPERTISE_RATING         = 37
ITEM_MOD_ATTACK_POWER             = 38
ITEM_MOD_RANGED_ATTACK_POWER      = 39
ITEM_MOD_SPELL_HEALING_DONE       = 41
ITEM_MOD_SPELL_DAMAGE_DONE        = 42
ITEM_MOD_MANA_REGENERATION        = 43
ITEM_MOD_ARMOR_PENETRATION_RATING = 44
ITEM_MOD_SPELL_POWER              = 45
ITEM_MOD_HEALTH_REGEN             = 46
ITEM_MOD_SPELL_PENETRATION        = 47
ITEM_MOD_BLOCK_VALUE              = 48
MAX_ITEM_MOD                      = 49 -- MAX ITEM MOD
-- ITEM SPELL TRIGGER TYPES
ITEM_SPELLTRIGGER_ON_USE          = 0
ITEM_SPELLTRIGGER_ON_EQUIP        = 1
ITEM_SPELLTRIGGER_CHANCE_ON_HIT   = 2
ITEM_SPELLTRIGGER_SOULSTONE       = 4
ITEM_SPELLTRIGGER_ON_NO_DELAY_USE = 5
ITEM_SPELLTRIGGER_LEARN_SPELL_ID  = 6
-- ITEM BONDING TYPES
NO_BIND                           = 0
BIND_WHEN_PICKED_UP               = 1
BIND_WHEN_EQUIPED                 = 2
BIND_WHEN_USE                     = 3
BIND_QUEST_ITEM                   = 4
BIND_QUEST_ITEM1                  = 5
-- ITEM PROTO FLAGS
ITEM_PROTO_FLAG_UNK1                        = 0x00000001
ITEM_PROTO_FLAG_CONJURED                    = 0x00000002 -- Conjured item
ITEM_PROTO_FLAG_OPENABLE                    = 0x00000004 -- Item can be right clicked to open for loot
ITEM_PROTO_FLAG_HEROIC                      = 0x00000008 -- Makes green "Heroic" text appear on item
ITEM_PROTO_FLAG_DEPRECATED                  = 0x00000010 -- Cannot equip or use
ITEM_PROTO_FLAG_INDESTRUCTIBLE              = 0x00000020 -- Item can not be destroyed except by using spell (item can be reagent for spell)
ITEM_PROTO_FLAG_UNK2                        = 0x00000040 
ITEM_PROTO_FLAG_NO_EQUIP_COOLDOWN           = 0x00000080 -- No default 30 seconds cooldown when equipped
ITEM_PROTO_FLAG_UNK3                        = 0x00000100
ITEM_PROTO_FLAG_WRAPPER                     = 0x00000200 -- Item can wrap other items
ITEM_PROTO_FLAG_UNK4                        = 0x00000400
ITEM_PROTO_FLAG_PARTY_LOOT                  = 0x00000800 -- Looting this item does not remove it from available loot
ITEM_PROTO_FLAG_REFUNDABLE                  = 0x00001000 -- Item can be returned to vendor for its original cost (extended cost)
ITEM_PROTO_FLAG_CHARTER                     = 0x00002000 -- Item is guild or arena charter
ITEM_PROTO_FLAG_UNK5                        = 0x00004000 -- Only readable items have this (but not all)
ITEM_PROTO_FLAG_UNK6                        = 0x00008000
ITEM_PROTO_FLAG_UNK7                        = 0x00010000
ITEM_PROTO_FLAG_UNK8                        = 0x00020000
ITEM_PROTO_FLAG_PROSPECTABLE                = 0x00040000 -- Item can be prospected
ITEM_PROTO_FLAG_UNIQUE_EQUIPPED             = 0x00080000 -- You can only equip one of these
ITEM_PROTO_FLAG_UNK9                        = 0x00100000
ITEM_PROTO_FLAG_USEABLE_IN_ARENA            = 0x00200000 -- Item can be used during arena match
ITEM_PROTO_FLAG_THROWABLE                   = 0x00400000 -- Some Thrown weapons have it (and only Thrown) but not all
ITEM_PROTO_FLAG_USABLE_WHEN_SHAPESHIFTED    = 0x00800000 -- Item can be used in shapeshift forms
ITEM_PROTO_FLAG_UNK10                       = 0x01000000
ITEM_PROTO_FLAG_SMART_LOOT                  = 0x02000000 -- Profession recipes: can only be looted if you meet requirements and don't already know it
ITEM_PROTO_FLAG_NOT_USEABLE_IN_ARENA        = 0x04000000 -- Item cannot be used in arena
ITEM_PROTO_FLAG_BIND_TO_ACCOUNT             = 0x08000000 -- Item binds to account and can be sent only to your own characters
ITEM_PROTO_FLAG_TRIGGERED_CAST              = 0x10000000 -- Spell is cast with triggered flag
ITEM_PROTO_FLAG_MILLABLE                    = 0x20000000 -- Item can be milled
ITEM_PROTO_FLAG_UNK11                       = 0x40000000
ITEM_PROTO_FLAG_UNK12                       = 0x80000000
-- ITEM FIELD FLAGS
ITEM_FLAG_SOULBOUND      = 0x00000001 -- Item is soulbound and cannot be traded
ITEM_FLAG_UNK1           = 0x00000002
ITEM_FLAG_UNLOCKED       = 0x00000004 -- Item had lock but can be opened now
ITEM_FLAG_WRAPPED        = 0x00000008 -- Item is wrapped and contains another item
ITEM_FLAG_UNK2           = 0x00000010
ITEM_FLAG_UNK3           = 0x00000020
ITEM_FLAG_UNK4           = 0x00000040
ITEM_FLAG_UNK5           = 0x00000080
ITEM_FLAG_BOP_TRADEABLE  = 0x00000100 -- Allows trading soulbound items
ITEM_FLAG_READABLE       = 0x00000200 -- Opens text page when right clicked
ITEM_FLAG_UNK6           = 0x00000400
ITEM_FLAG_UNK7           = 0x00000800
ITEM_FLAG_REFUNDABLE     = 0x00001000 -- Item can be returned to vendor for its original cost (extended cost)
ITEM_FLAG_UNK8           = 0x00002000
ITEM_FLAG_UNK9           = 0x00004000
ITEM_FLAG_UNK10          = 0x00008000
ITEM_FLAG_UNK11          = 0x00010000
ITEM_FLAG_UNK12          = 0x00020000
ITEM_FLAG_UNK13          = 0x00040000
ITEM_FLAG_UNK14          = 0x00080000
ITEM_FLAG_UNK15          = 0x00100000
ITEM_FLAG_UNK16          = 0x00200000
ITEM_FLAG_UNK17          = 0x00400000
ITEM_FLAG_UNK18          = 0x00800000
ITEM_FLAG_UNK19          = 0x01000000
ITEM_FLAG_UNK20          = 0x02000000
ITEM_FLAG_UNK21          = 0x04000000
ITEM_FLAG_UNK22          = 0x08000000
ITEM_FLAG_UNK23          = 0x10000000
ITEM_FLAG_UNK24          = 0x20000000
ITEM_FLAG_UNK25          = 0x40000000
ITEM_FLAG_UNK26          = 0x80000000
ITEM_FLAG_MAIL_TEXT_MASK = 786944
-- ITEM FLAGS EXTRA
ITEM_FLAGS_EXTRA_HORDE_ONLY              = 0x00000001
ITEM_FLAGS_EXTRA_ALLIANCE_ONLY           = 0x00000002
ITEM_FLAGS_EXTRA_EXT_COST_REQUIRES_GOLD  = 0x00000004 -- when item uses extended cost, gold is also required
ITEM_FLAGS_EXTRA_NEED_ROLL_DISABLED      = 0x00000100
-- ITEM FLAGS CUSTOM
ITEM_FLAGS_CU_DURATION_REAL_TIME    = 0x0001 -- Item duration will tick even if player is offline
ITEM_FLAGS_CU_IGNORE_QUEST_STATUS   = 0x0002 -- No quest status will be checked when this item drops
ITEM_FLAGS_CU_FOLLOW_LOOT_RULES     = 0x0004 -- Item will always follow group/master/need before greed looting rules
-- ITEM CLASS
ITEM_CLASS_CONSUMABLE                       = 0
ITEM_CLASS_CONTAINER                        = 1
ITEM_CLASS_WEAPON                           = 2
ITEM_CLASS_GEM                              = 3
ITEM_CLASS_ARMOR                            = 4
ITEM_CLASS_REAGENT                          = 5
ITEM_CLASS_PROJECTILE                       = 6
ITEM_CLASS_TRADE_GOODS                      = 7
ITEM_CLASS_GENERIC                          = 8
ITEM_CLASS_RECIPE                           = 9
ITEM_CLASS_MONEY                            = 10
ITEM_CLASS_QUIVER                           = 11
ITEM_CLASS_QUEST                            = 12
ITEM_CLASS_KEY                              = 13
ITEM_CLASS_PERMANENT                        = 14
ITEM_CLASS_MISC                             = 15
ITEM_CLASS_GLYPH                            = 16
MAX_ITEM_CLASS                              = 17 -- MAX ITEM CLASS
-- ITEM SUBCLASS CONSUMABLE
ITEM_SUBCLASS_CONSUMABLE                    = 0
ITEM_SUBCLASS_POTION                        = 1
ITEM_SUBCLASS_ELIXIR                        = 2
ITEM_SUBCLASS_FLASK                         = 3
ITEM_SUBCLASS_SCROLL                        = 4
ITEM_SUBCLASS_FOOD                          = 5
ITEM_SUBCLASS_ITEM_ENHANCEMENT              = 6
ITEM_SUBCLASS_BANDAGE                       = 7
ITEM_SUBCLASS_CONSUMABLE_OTHER              = 8
MAX_ITEM_SUBCLASS_CONSUMABLE                = 9 -- MAX ITEM SUBCLASS CONSUMABLE
-- ITEM SUBCLASS CONTAINER
ITEM_SUBCLASS_CONTAINER                     = 0
ITEM_SUBCLASS_SOUL_CONTAINER                = 1
ITEM_SUBCLASS_HERB_CONTAINER                = 2
ITEM_SUBCLASS_ENCHANTING_CONTAINER          = 3
ITEM_SUBCLASS_ENGINEERING_CONTAINER         = 4
ITEM_SUBCLASS_GEM_CONTAINER                 = 5
ITEM_SUBCLASS_MINING_CONTAINER              = 6
ITEM_SUBCLASS_LEATHERWORKING_CONTAINER      = 7
ITEM_SUBCLASS_INSCRIPTION_CONTAINER         = 8
MAX_ITEM_SUBCLASS_CONTAINER                 = 9 -- MAX ITEM SUBCLASS CONTAINER
-- ITEM SUBCLASS WEAPON
ITEM_SUBCLASS_WEAPON_AXE                    = 0
ITEM_SUBCLASS_WEAPON_AXE2                   = 1
ITEM_SUBCLASS_WEAPON_BOW                    = 2
ITEM_SUBCLASS_WEAPON_GUN                    = 3
ITEM_SUBCLASS_WEAPON_MACE                   = 4
ITEM_SUBCLASS_WEAPON_MACE2                  = 5
ITEM_SUBCLASS_WEAPON_POLEARM                = 6
ITEM_SUBCLASS_WEAPON_SWORD                  = 7
ITEM_SUBCLASS_WEAPON_SWORD2                 = 8
ITEM_SUBCLASS_WEAPON_obsolete               = 9
ITEM_SUBCLASS_WEAPON_STAFF                  = 10
ITEM_SUBCLASS_WEAPON_EXOTIC                 = 11
ITEM_SUBCLASS_WEAPON_EXOTIC2                = 12
ITEM_SUBCLASS_WEAPON_FIST                   = 13
ITEM_SUBCLASS_WEAPON_MISC                   = 14
ITEM_SUBCLASS_WEAPON_DAGGER                 = 15
ITEM_SUBCLASS_WEAPON_THROWN                 = 16
ITEM_SUBCLASS_WEAPON_SPEAR                  = 17
ITEM_SUBCLASS_WEAPON_CROSSBOW               = 18
ITEM_SUBCLASS_WEAPON_WAND                   = 19
ITEM_SUBCLASS_WEAPON_FISHING_POLE           = 20
MAX_ITEM_SUBCLASS_WEAPON                    = 21 -- MAX ITEM SUBCLASS WEAPON
-- ITEM SUBCLASS GEM
ITEM_SUBCLASS_GEM_RED                       = 0
ITEM_SUBCLASS_GEM_BLUE                      = 1
ITEM_SUBCLASS_GEM_YELLOW                    = 2
ITEM_SUBCLASS_GEM_PURPLE                    = 3
ITEM_SUBCLASS_GEM_GREEN                     = 4
ITEM_SUBCLASS_GEM_ORANGE                    = 5
ITEM_SUBCLASS_GEM_META                      = 6
ITEM_SUBCLASS_GEM_SIMPLE                    = 7
ITEM_SUBCLASS_GEM_PRISMATIC                 = 8
MAX_ITEM_SUBCLASS_GEM                       = 9 -- MAX ITEM SUBCLASS GEM
-- ITEM SUBCLASS ARMOR
ITEM_SUBCLASS_ARMOR_MISC                    = 0
ITEM_SUBCLASS_ARMOR_CLOTH                   = 1
ITEM_SUBCLASS_ARMOR_LEATHER                 = 2
ITEM_SUBCLASS_ARMOR_MAIL                    = 3
ITEM_SUBCLASS_ARMOR_PLATE                   = 4
ITEM_SUBCLASS_ARMOR_BUCKLER                 = 5
ITEM_SUBCLASS_ARMOR_SHIELD                  = 6
ITEM_SUBCLASS_ARMOR_LIBRAM                  = 7
ITEM_SUBCLASS_ARMOR_IDOL                    = 8
ITEM_SUBCLASS_ARMOR_TOTEM                   = 9
ITEM_SUBCLASS_ARMOR_SIGIL                   = 10
MAX_ITEM_SUBCLASS_ARMOR                     = 11 -- MAX ITEM SUBCLASS ARMOR
-- ITEM SUBCLASS REAGENT
ITEM_SUBCLASS_REAGENT                       = 0
MAX_ITEM_SUBCLASS_REAGENT                   = 1 -- MAX ITEM SUBCLASS REAGENT
-- ITEM SUBCLASS PROJECTILE
ITEM_SUBCLASS_WAND                          = 0
ITEM_SUBCLASS_BOLT                          = 1
ITEM_SUBCLASS_ARROW                         = 2
ITEM_SUBCLASS_BULLET                        = 3
ITEM_SUBCLASS_THROWN                        = 4
MAX_ITEM_SUBCLASS_PROJECTILE                = 5 -- MAX ITEM SUBCLASS PROJECTILE
-- ITEM SUBCLASS TRADE GOODS
ITEM_SUBCLASS_TRADE_GOODS                   = 0
ITEM_SUBCLASS_PARTS                         = 1
ITEM_SUBCLASS_EXPLOSIVES                    = 2
ITEM_SUBCLASS_DEVICES                       = 3
ITEM_SUBCLASS_JEWELCRAFTING                 = 4
ITEM_SUBCLASS_CLOTH                         = 5
ITEM_SUBCLASS_LEATHER                       = 6
ITEM_SUBCLASS_METAL_STONE                   = 7
ITEM_SUBCLASS_MEAT                          = 8
ITEM_SUBCLASS_HERB                          = 9
ITEM_SUBCLASS_ELEMENTAL                     = 10
ITEM_SUBCLASS_TRADE_GOODS_OTHER             = 11
ITEM_SUBCLASS_ENCHANTING                    = 12
ITEM_SUBCLASS_MATERIAL                      = 13
ITEM_SUBCLASS_ARMOR_ENCHANTMENT             = 14
ITEM_SUBCLASS_WEAPON_ENCHANTMENT            = 15
MAX_ITEM_SUBCLASS_TRADE_GOODS               = 16 -- MAX ITEM SUBCLASS TRADE GOODS
-- ITEM SUBCLASS GENERIC
ITEM_SUBCLASS_GENERIC                       = 0
MAX_ITEM_SUBCLASS_GENERIC                   = 1 -- MAX ITEM SUBCLASS GENERIC
-- ITEM SUBCLASS RECIPE
ITEM_SUBCLASS_BOOK                          = 0
ITEM_SUBCLASS_LEATHERWORKING_PATTERN        = 1
ITEM_SUBCLASS_TAILORING_PATTERN             = 2
ITEM_SUBCLASS_ENGINEERING_SCHEMATIC         = 3
ITEM_SUBCLASS_BLACKSMITHING                 = 4
ITEM_SUBCLASS_COOKING_RECIPE                = 5
ITEM_SUBCLASS_ALCHEMY_RECIPE                = 6
ITEM_SUBCLASS_FIRST_AID_MANUAL              = 7
ITEM_SUBCLASS_ENCHANTING_FORMULA            = 8
ITEM_SUBCLASS_FISHING_MANUAL                = 9
ITEM_SUBCLASS_JEWELCRAFTING_RECIPE          = 10
MAX_ITEM_SUBCLASS_RECIPE                    = 11 -- MAX ITEM SUBCLASS RECIPE
-- ITEM SUBCLASS MONEY
ITEM_SUBCLASS_MONEY                         = 0
MAX_ITEM_SUBCLASS_MONEY                     = 1 -- MAX ITEM SUBCLASS MONEY
-- ITEM SUBCLASS QUIVER
ITEM_SUBCLASS_QUIVER0                       = 0
ITEM_SUBCLASS_QUIVER1                       = 1
ITEM_SUBCLASS_QUIVER                        = 2
ITEM_SUBCLASS_AMMO_POUCH                    = 3
MAX_ITEM_SUBCLASS_QUIVER                    = 4 -- MAX ITEM SUBCLASS QUIVER
-- ITEM SUBCLASS QUEST
ITEM_SUBCLASS_QUEST                         = 0
MAX_ITEM_SUBCLASS_QUEST                     = 1 -- MAX ITEM SUBCLASS QUEST
-- ITEM SUBCLASS KEY
ITEM_SUBCLASS_KEY                           = 0
ITEM_SUBCLASS_LOCKPICK                      = 1
MAX_ITEM_SUBCLASS_KEY                       = 2 -- MAX ITEM SUBCLASS KEY
-- ITEM SUBCLASS PERMANENT
ITEM_SUBCLASS_PERMANENT                     = 0
MAX_ITEM_SUBCLASS_PERMANENT                 = 1 -- MAX ITEM SUBCLASS PERMANENT
-- ITEM SUBCLASS JUNK
ITEM_SUBCLASS_JUNK                          = 0
ITEM_SUBCLASS_JUNK_REAGENT                  = 1
ITEM_SUBCLASS_JUNK_PET                      = 2
ITEM_SUBCLASS_JUNK_HOLIDAY                  = 3
ITEM_SUBCLASS_JUNK_OTHER                    = 4
ITEM_SUBCLASS_JUNK_MOUNT                    = 5
MAX_ITEM_SUBCLASS_JUNK                      = 6 -- MAX ITEM SUBCLASS JUNK
-- ITEM SUBCLASS GLYPH
ITEM_SUBCLASS_GLYPH_WARRIOR                 = 1
ITEM_SUBCLASS_GLYPH_PALADIN                 = 2
ITEM_SUBCLASS_GLYPH_HUNTER                  = 3
ITEM_SUBCLASS_GLYPH_ROGUE                   = 4
ITEM_SUBCLASS_GLYPH_PRIEST                  = 5
ITEM_SUBCLASS_GLYPH_DEATH_KNIGHT            = 6
ITEM_SUBCLASS_GLYPH_SHAMAN                  = 7
ITEM_SUBCLASS_GLYPH_MAGE                    = 8
ITEM_SUBCLASS_GLYPH_WARLOCK                 = 9
ITEM_SUBCLASS_GLYPH_DRUID                   = 11
MAX_ITEM_SUBCLASS_GLYPH                     = 12 -- MAX ITEM SUBCLASS GLYPH
-- BAG FAMILY MASK
BAG_FAMILY_MASK_NONE                      = 0x00000000
BAG_FAMILY_MASK_ARROWS                    = 0x00000001
BAG_FAMILY_MASK_BULLETS                   = 0x00000002
BAG_FAMILY_MASK_SOUL_SHARDS               = 0x00000004
BAG_FAMILY_MASK_LEATHERWORKING_SUPP       = 0x00000008
BAG_FAMILY_MASK_INSCRIPTION_SUPP          = 0x00000010
BAG_FAMILY_MASK_HERBS                     = 0x00000020
BAG_FAMILY_MASK_ENCHANTING_SUPP           = 0x00000040
BAG_FAMILY_MASK_ENGINEERING_SUPP          = 0x00000080
BAG_FAMILY_MASK_KEYS                      = 0x00000100
BAG_FAMILY_MASK_GEMS                      = 0x00000200
BAG_FAMILY_MASK_MINING_SUPP               = 0x00000400
BAG_FAMILY_MASK_SOULBOUND_EQUIPMENT       = 0x00000800
BAG_FAMILY_MASK_VANITY_PETS               = 0x00001000
BAG_FAMILY_MASK_CURRENCY_TOKENS           = 0x00002000
BAG_FAMILY_MASK_QUEST_ITEMS               = 0x00004000
-- SOCKET COLORS
SOCKET_COLOR_META                         = 1
SOCKET_COLOR_RED                          = 2
SOCKET_COLOR_YELLOW                       = 4
SOCKET_COLOR_BLUE                         = 8
SOCKET_COLOR_ALL                          = 15
-- INVENTORY TYPES
INVTYPE_NON_EQUIP                           = 0
INVTYPE_HEAD                                = 1
INVTYPE_NECK                                = 2
INVTYPE_SHOULDERS                           = 3
INVTYPE_BODY                                = 4
INVTYPE_CHEST                               = 5
INVTYPE_WAIST                               = 6
INVTYPE_LEGS                                = 7
INVTYPE_FEET                                = 8
INVTYPE_WRISTS                              = 9
INVTYPE_HANDS                               = 10
INVTYPE_FINGER                              = 11
INVTYPE_TRINKET                             = 12
INVTYPE_WEAPON                              = 13
INVTYPE_SHIELD                              = 14
INVTYPE_RANGED                              = 15
INVTYPE_CLOAK                               = 16
INVTYPE_2HWEAPON                            = 17
INVTYPE_BAG                                 = 18
INVTYPE_TABARD                              = 19
INVTYPE_ROBE                                = 20
INVTYPE_WEAPONMAINHAND                      = 21
INVTYPE_WEAPONOFFHAND                       = 22
INVTYPE_HOLDABLE                            = 23
INVTYPE_AMMO                                = 24
INVTYPE_THROWN                              = 25
INVTYPE_RANGEDRIGHT                         = 26
INVTYPE_QUIVER                              = 27
INVTYPE_RELIC                               = 28
MAX_INVTYPE                                 = 29 -- MAX INVENTORY TYPE
--------------------------------------------------------
--[[
     VEHICLE DEFINES
--]]
--------------------------------------------------------
-- VEHICLE POWER TYPE
POWER_STEAM                                  = 61
POWER_PYRITE                                 = 41
POWER_HEAT                                   = 101
POWER_OOZE                                   = 121
POWER_BLOOD                                  = 141
POWER_WRATH                                  = 142
-- VEHICLE FLAGS
VEHICLE_FLAG_NO_STRAFE                       = 0x00000001           -- Sets MOVEFLAG2_NO_STRAFE
VEHICLE_FLAG_NO_JUMPING                      = 0x00000002           -- Sets MOVEFLAG2_NO_JUMPING
VEHICLE_FLAG_FULLSPEEDTURNING                = 0x00000004           -- Sets MOVEFLAG2_FULLSPEEDTURNING
VEHICLE_FLAG_ALLOW_PITCHING                  = 0x00000010           -- Sets MOVEFLAG2_ALLOW_PITCHING
VEHICLE_FLAG_FULLSPEEDPITCHING               = 0x00000020           -- Sets MOVEFLAG2_FULLSPEEDPITCHING
VEHICLE_FLAG_CUSTOM_PITCH                    = 0x00000040           -- If set use pitchMin and pitchMax from DBC, otherwise pitchMin = -pi/2, pitchMax = pi/2
VEHICLE_FLAG_ADJUST_AIM_ANGLE                = 0x00000400           -- Lua_IsVehicleAimAngleAdjustable
VEHICLE_FLAG_ADJUST_AIM_POWER                = 0x00000800            -- Lua_IsVehicleAimPowerAdjustable
-- VEHICLE SPELLS
VEHICLE_SPELL_RIDE_HARDCODED                 = 46598
VEHICLE_SPELL_PARACHUTE                      = 45472
--------------------------------------------------------
--[[
     WEATHER STATES
--]]
--------------------------------------------------------
WEATHER_STATE_FINE              = 0
WEATHER_STATE_FOG               = 1
WEATHER_STATE_LIGHT_RAIN        = 3
WEATHER_STATE_MEDIUM_RAIN       = 4
WEATHER_STATE_HEAVY_RAIN        = 5
WEATHER_STATE_LIGHT_SNOW        = 6
WEATHER_STATE_MEDIUM_SNOW       = 7
WEATHER_STATE_HEAVY_SNOW        = 8
WEATHER_STATE_LIGHT_SANDSTORM   = 22
WEATHER_STATE_MEDIUM_SANDSTORM  = 41
WEATHER_STATE_HEAVY_SANDSTORM   = 42
WEATHER_STATE_THUNDERS          = 86
WEATHER_STATE_BLACKRAIN         = 90
WEATHER_STATE_BLACKSNOW         = 106
-- WEATHER SEASONS
WEATHER_SEASONS                 = 4
--------------------------------------------------------
--[[
     LOOT
--]]
--------------------------------------------------------
-- LOOT TYPES
LOOT_CORPSE                 = 1
LOOT_PICKPOCKETING          = 2
LOOT_FISHING                = 3
LOOT_DISENCHANTING          = 4
LOOT_SKINNING               = 6
LOOT_PROSPECTING            = 7
LOOT_MILLING                = 8
LOOT_FISHINGHOLE            = 20                       -- unsupported by client, sending LOOT_FISHING instead
LOOT_INSIGNIA               = 21                       -- unsupported by client, sending LOOT_CORPSE instead
-- LOOT SLOT TYPES
LOOT_SLOT_TYPE_ALLOW_LOOT   = 0                        -- player can loot the item.
LOOT_SLOT_TYPE_ROLL_ONGOING = 1                        -- roll is ongoing. player cannot loot.
LOOT_SLOT_TYPE_MASTER       = 2                        -- item can only be distributed by group loot master.
LOOT_SLOT_TYPE_LOCKED       = 3                        -- item is shown in red. player cannot loot.
LOOT_SLOT_TYPE_OWNER        = 4                         -- ignore binding confirmation and etc, for single player looting
-- LOOT METHOD
FREE_FOR_ALL      = 0
ROUND_ROBIN       = 1
MASTER_LOOT       = 2
GROUP_LOOT        = 3
NEED_BEFORE_GREED = 4
-- PERMISSION TYPES
ALL_PERMISSION              = 0
GROUP_PERMISSION            = 1
MASTER_PERMISSION           = 2
ROUND_ROBIN_PERMISSION      = 3
OWNER_PERMISSION            = 4
NONE_PERMISSION             = 5
-- ROLL TYPES
ROLL_PASS         = 0
ROLL_NEED         = 1
ROLL_GREED        = 2
ROLL_DISENCHANT   = 3
MAX_ROLL_TYPE     = 4
-- ROLL MASK
ROLL_FLAG_TYPE_PASS         = 0x01
ROLL_FLAG_TYPE_NEED         = 0x02
ROLL_FLAG_TYPE_GREED        = 0x04
ROLL_FLAG_TYPE_DISENCHANT   = 0x08

ROLL_ALL_TYPE_NO_DISENCHANT = 0x07
ROLL_ALL_TYPE_MASK          = 0x0F
--------------------------------------------------------
--[[
     LFG
--]]
--------------------------------------------------------
-- CLASS NEEDED
LFG_TANKS_OR_HEALERS_NEEDED                  = 1
LFG_DPS_NEEDED                               = 3
-- LFG ROLES
PLAYER_ROLE_NONE                             = 0x00
PLAYER_ROLE_LEADER                           = 0x01
PLAYER_ROLE_TANK                             = 0x02
PLAYER_ROLE_HEALER                           = 0x04
PLAYER_ROLE_DAMAGE                           = 0x08
-- LFG UPDATE TYPES
LFG_UPDATETYPE_DEFAULT                       = 0      -- Internal Use
LFG_UPDATETYPE_LEADER_UNK1                   = 1      -- FIXME: At group leave
LFG_UPDATETYPE_ROLECHECK_ABORTED             = 4
LFG_UPDATETYPE_JOIN_QUEUE                    = 5
LFG_UPDATETYPE_ROLECHECK_FAILED              = 6
LFG_UPDATETYPE_REMOVED_FROM_QUEUE            = 7
LFG_UPDATETYPE_PROPOSAL_FAILED               = 8
LFG_UPDATETYPE_PROPOSAL_DECLINED             = 9
LFG_UPDATETYPE_GROUP_FOUND                   = 10
LFG_UPDATETYPE_ADDED_TO_QUEUE                = 12
LFG_UPDATETYPE_PROPOSAL_BEGIN                = 13
LFG_UPDATETYPE_UPDATE_STATUS                 = 14
LFG_UPDATETYPE_GROUP_MEMBER_OFFLINE          = 15
LFG_UPDATETYPE_GROUP_DISBAND_UNK16           = 16     -- FIXME: Sometimes at group disband
-- LFG STATES
LFG_STATE_NONE                               = 0      -- Not using LFG / LFR
LFG_STATE_ROLECHECK                          = 1      -- Rolecheck active
LFG_STATE_QUEUED                             = 2      -- Queued
LFG_STATE_PROPOSAL                           = 3      -- Proposal active
LFG_STATE_BOOT                               = 4      -- Vote kick active
LFG_STATE_DUNGEON                            = 5      -- In LFG Group, in a Dungeon
LFG_STATE_FINISHED_DUNGEON                   = 6      -- In LFG Group, in a finished Dungeon
LFG_STATE_RAIDBROWSER                        = 7      -- Using Raid finder
-- LFG LOCK STATUS TYPES
LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION        = 1
LFG_LOCKSTATUS_TOO_LOW_LEVEL                 = 2
LFG_LOCKSTATUS_TOO_HIGH_LEVEL                = 3
LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE            = 4
LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE           = 5
LFG_LOCKSTATUS_RAID_LOCKED                   = 6
LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL      = 1001
LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL     = 1002
LFG_LOCKSTATUS_QUEST_NOT_COMPLETED           = 1022
LFG_LOCKSTATUS_MISSING_ITEM                  = 1025
LFG_LOCKSTATUS_NOT_IN_SEASON                 = 1031
LFG_LOCKSTATUS_MISSING_ACHIEVEMENT           = 1034
-- LFG ANSWER
LFG_ANSWER_PENDING                           = -1
LFG_ANSWER_DENY                              = 0
LFG_ANSWER_AGREE                             = 1
-- LFG GROUP TYPE
 LFG_GROUP_MAX_KICKS                         = 3
-- LFG OPTIONS
LFG_OPTION_ENABLE_DUNGEON_FINDER             = 0x01
LFG_OPTION_ENABLE_RAID_BROWSER               = 0x02
-- LFG MGR TYPES
LFG_TIME_ROLECHECK                           = 45 * IN_MILLISECONDS
LFG_TIME_BOOT                                = 120
LFG_TIME_PROPOSAL                            = 45
LFG_QUEUEUPDATE_INTERVAL                     = 15 * IN_MILLISECONDS
LFG_SPELL_DUNGEON_COOLDOWN                   = 71328
LFG_SPELL_DUNGEON_DESERTER                   = 71041
LFG_SPELL_LUCK_OF_THE_DRAW                   = 72221
LFG_GROUP_KICK_VOTES_NEEDED                  = 3
-- LFG FLAGS
LFG_FLAG_UNK1                                = 0x1
LFG_FLAG_UNK2                                = 0x2
LFG_FLAG_SEASONAL                            = 0x4
LFG_FLAG_UNK3                                = 0x8
-- LFG TYPES
LFG_TYPE_NONE                                = 0
LFG_TYPE_DUNGEON                             = 1
LFG_TYPE_RAID                                = 2
LFG_TYPE_HEROIC                              = 5
LFG_TYPE_RANDOM                              = 6
-- LFG PROPOSAL STATE
LFG_PROPOSAL_INITIATING                      = 0
LFG_PROPOSAL_FAILED                          = 1
LFG_PROPOSAL_SUCCESS                         = 2
-- LFG TELEPORT ERRORS
LFG_TELEPORTERROR_OK                         = 0      -- Internal use
LFG_TELEPORTERROR_PLAYER_DEAD                = 1
LFG_TELEPORTERROR_FALLING                    = 2
LFG_TELEPORTERROR_IN_VEHICLE                 = 3
LFG_TELEPORTERROR_FATIGUE                    = 4
LFG_TELEPORTERROR_INVALID_LOCATION           = 6
LFG_TELEPORTERROR_CHARMING                   = 8       -- FIXME - It can be 7 or 8 (Need proper data)
-- LFG JOIN RESULTS
LFG_JOIN_OK                                  = 0      -- Joined (no client msg)
LFG_JOIN_FAILED                              = 1      -- RoleCheck Failed
LFG_JOIN_GROUPFULL                           = 2      -- Your group is full
LFG_JOIN_INTERNAL_ERROR                      = 4      -- Internal LFG Error
LFG_JOIN_NOT_MEET_REQS                       = 5      -- You do not meet the requirements for the chosen dungeons
LFG_JOIN_PARTY_NOT_MEET_REQS                 = 6      -- One or more party members do not meet the requirements for the chosen dungeons
LFG_JOIN_MIXED_RAID_DUNGEON                  = 7      -- You cannot mix dungeons, raids, and random when picking dungeons
LFG_JOIN_MULTI_REALM                         = 8      -- The dungeon you chose does not support players from multiple realms
LFG_JOIN_DISCONNECTED                        = 9      -- One or more party members are pending invites or disconnected
LFG_JOIN_PARTY_INFO_FAILED                   = 10     -- Could not retrieve information about some party members
LFG_JOIN_DUNGEON_INVALID                     = 11     -- One or more dungeons was not valid
LFG_JOIN_DESERTER                            = 12     -- You can not queue for dungeons until your deserter debuff wears off
LFG_JOIN_PARTY_DESERTER                      = 13     -- One or more party members has a deserter debuff
LFG_JOIN_RANDOM_COOLDOWN                     = 14     -- You can not queue for random dungeons while on random dungeon cooldown
LFG_JOIN_PARTY_RANDOM_COOLDOWN               = 15     -- One or more party members are on random dungeon cooldown
LFG_JOIN_TOO_MUCH_MEMBERS                    = 16     -- You can not enter dungeons with more that 5 party members
LFG_JOIN_USING_BG_SYSTEM                     = 17     -- You can not use the dungeon system while in BG or arenas
-- LFG ROLE CHECK STATE
LFG_ROLECHECK_DEFAULT                        = 0      -- Internal use = Not initialized.
LFG_ROLECHECK_FINISHED                       = 1      -- Role check finished
LFG_ROLECHECK_INITIALITING                   = 2      -- Role check begins
LFG_ROLECHECK_MISSING_ROLE                   = 3      -- Someone didn't selected a role after 2 mins
LFG_ROLECHECK_WRONG_ROLES                    = 4      -- Can't form a group with that role selection
LFG_ROLECHECK_ABORTED                        = 5      -- Someone leave the group
LFG_ROLECHECK_NO_ROLE                        = 6       -- Someone selected no role
--------------------------------------------------------
--[[
     MAIL
--]]
--------------------------------------------------------
-- MAIL MESSAGE TYPES
MAIL_NORMAL         = 0
MAIL_AUCTION        = 2
MAIL_CREATURE       = 3                                -- client send CMSG_CREATURE_QUERY on this mailmessagetype
MAIL_GAMEOBJECT     = 4                                -- client send CMSG_GAMEOBJECT_QUERY on this mailmessagetype
MAIL_CALENDAR       = 5
-- MAIL STATE
MAIL_STATE_UNCHANGED = 1
MAIL_STATE_CHANGED   = 2
MAIL_STATE_DELETED   = 3
-- MAIL SHOW FLAGS
MAIL_SHOW_UNK0    = 0x0001
MAIL_SHOW_DELETE  = 0x0002                             -- forced show delete button instead return button
MAIL_SHOW_AUCTION = 0x0004                             -- from old comment
MAIL_SHOW_UNK2    = 0x0008                             -- unknown, COD will be shown even without that flag
MAIL_SHOW_RETURN  = 0x0010
-- MAIL CHECK MASK
MAIL_CHECK_MASK_NONE        = 0x00
MAIL_CHECK_MASK_READ        = 0x01
MAIL_CHECK_MASK_RETURNED    = 0x02                     -- This mail was returned. Do not allow returning mail back again.
MAIL_CHECK_MASK_COPIED      = 0x04                     -- This mail was copied. Do not allow making a copy of items in mail.
MAIL_CHECK_MASK_COD_PAYMENT = 0x08
MAIL_CHECK_MASK_HAS_BODY    = 0x10                      -- This mail has body text.
-- MAIL STATIONARY TYPES
MAIL_STATIONERY_TEST    = 1
MAIL_STATIONERY_DEFAULT = 41
MAIL_STATIONERY_GM      = 61
MAIL_STATIONERY_AUCTION = 62
MAIL_STATIONERY_VAL     = 64                           -- Valentine
MAIL_STATIONERY_CHR     = 65                           -- Christmas
MAIL_STATIONERY_ORP     = 67                           -- Orphan
--------------------------------------------------------
--[[
     MOTION (MOVEMENT)
--]]
--------------------------------------------------------
-- MOVEMENT GENERATOR TYPES
IDLE_MOTION_TYPE      = 0                              -- IdleMovementGenerator.h
RANDOM_MOTION_TYPE    = 1                              -- RandomMovementGenerator.h
WAYPOINT_MOTION_TYPE  = 2                              -- WaypointMovementGenerator.h
MAX_DB_MOTION_TYPE    = 3                              -- *** this and below motion types can't be set in DB.
ANIMAL_RANDOM_MOTION_TYPE = MAX_DB_MOTION_TYPE         -- AnimalRandomMovementGenerator.h
CONFUSED_MOTION_TYPE  = 4                              -- ConfusedMovementGenerator.h
CHASE_MOTION_TYPE     = 5                              -- TargetedMovementGenerator.h
HOME_MOTION_TYPE      = 6                              -- HomeMovementGenerator.h
FLIGHT_MOTION_TYPE    = 7                              -- WaypointMovementGenerator.h
POINT_MOTION_TYPE     = 8                              -- PointMovementGenerator.h
FLEEING_MOTION_TYPE   = 9                              -- FleeingMovementGenerator.h
DISTRACT_MOTION_TYPE  = 10                             -- IdleMovementGenerator.h
ASSISTANCE_MOTION_TYPE= 11                             -- PointMovementGenerator.h (first part of flee for assistance)
ASSISTANCE_DISTRACT_MOTION_TYPE = 12                   -- IdleMovementGenerator.h (second part of flee for assistance)
TIMED_FLEEING_MOTION_TYPE = 13                         -- FleeingMovementGenerator.h (alt.second part of flee for assistance)
FOLLOW_MOTION_TYPE    = 14
ROTATE_MOTION_TYPE    = 15
EFFECT_MOTION_TYPE    = 16
NULL_MOTION_TYPE      = 17
-- MOVEMENT SLOTS
MOTION_SLOT_IDLE       = 0
MOTION_SLOT_ACTIVE     = 1
MOTION_SLOT_CONTROLLED = 2
MAX_MOTION_SLOT        = 3 -- MAX MOTION SLOT
--------------------------------------------------------
--[[
     OBJECT
--]]
--------------------------------------------------------
-- OBJECT TYPE MASK
TYPEMASK_OBJECT         = 0x0001
TYPEMASK_ITEM           = 0x0002
TYPEMASK_CONTAINER      = 0x0006                       -- TYPEMASK_ITEM | 0x0004
TYPEMASK_UNIT           = 0x0008                       -- creature
TYPEMASK_PLAYER         = 0x0010
TYPEMASK_GAMEOBJECT     = 0x0020
TYPEMASK_DYNAMICOBJECT  = 0x0040
TYPEMASK_CORPSE         = 0x0080
TYPEMASK_SEER           = 88
-- OBJECT TYPE ID
TYPEID_OBJECT        = 0
TYPEID_ITEM          = 1
TYPEID_CONTAINER     = 2
TYPEID_UNIT          = 3
TYPEID_PLAYER        = 4
TYPEID_GAMEOBJECT    = 5
TYPEID_DYNAMICOBJECT = 6
TYPEID_CORPSE        = 7
-- TEMP SUMMON TYPES
TEMPSUMMON_TIMED_OR_DEAD_DESPAWN       = 1             -- despawns after a specified time OR when the creature disappears
TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN     = 2             -- despawns after a specified time OR when the creature dies
TEMPSUMMON_TIMED_DESPAWN               = 3             -- despawns after a specified time
TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT = 4             -- despawns after a specified time after the creature is out of combat
TEMPSUMMON_CORPSE_DESPAWN              = 5             -- despawns instantly after death
TEMPSUMMON_CORPSE_TIMED_DESPAWN        = 6             -- despawns after a specified time after death
TEMPSUMMON_DEAD_DESPAWN                = 7             -- despawns when the creature disappears
TEMPSUMMON_MANUAL_DESPAWN              = 8              -- despawns when UnSummon() is called
-- PHASEMASK
PHASEMASK_NORMAL   = 0x00000001
PHASEMASK_ANYWHERE = 0xFFFFFFFF
-- OBJECT GUID
HIGHGUID_ITEM           = 0x4000
HIGHGUID_CONTAINER      = 0x4000
HIGHGUID_PLAYER         = 0x0000
HIGHGUID_GAMEOBJECT     = 0xF110
HIGHGUID_TRANSPORT      = 0xF120
HIGHGUID_UNIT           = 0xF130
HIGHGUID_PET            = 0xF140
HIGHGUID_VEHICLE        = 0xF150
HIGHGUID_DYNAMICOBJECT  = 0xF100
HIGHGUID_CORPSE         = 0xF101
HIGHGUID_MO_TRANSPORT   = 0x1FC0
HIGHGUID_GROUP          = 0x1F50