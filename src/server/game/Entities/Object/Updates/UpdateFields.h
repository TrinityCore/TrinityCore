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

#ifndef _UPDATEFIELDS_H
#define _UPDATEFIELDS_H

// Auto generated for version 7, 3, 2, 25383

enum ObjectFields
{
    OBJECT_FIELD_GUID                                      = 0x000, // Size: 4, Flags: PUBLIC
    OBJECT_FIELD_DATA                                      = 0x004, // Size: 4, Flags: PUBLIC
    OBJECT_FIELD_TYPE                                      = 0x008, // Size: 1, Flags: PUBLIC
    OBJECT_FIELD_ENTRY                                     = 0x009, // Size: 1, Flags: DYNAMIC
    OBJECT_DYNAMIC_FLAGS                                   = 0x00A, // Size: 1, Flags: DYNAMIC, URGENT
    OBJECT_FIELD_SCALE_X                                   = 0x00B, // Size: 1, Flags: PUBLIC
    OBJECT_END                                             = 0x00C,
};

enum ObjectDynamicFields
{
    OBJECT_DYNAMIC_END                                     = 0x000,
};

enum ItemFields
{
    ITEM_FIELD_OWNER                                       = OBJECT_END + 0x000, // Size: 4, Flags: PUBLIC
    ITEM_FIELD_CONTAINED                                   = OBJECT_END + 0x004, // Size: 4, Flags: PUBLIC
    ITEM_FIELD_CREATOR                                     = OBJECT_END + 0x008, // Size: 4, Flags: PUBLIC
    ITEM_FIELD_GIFTCREATOR                                 = OBJECT_END + 0x00C, // Size: 4, Flags: PUBLIC
    ITEM_FIELD_STACK_COUNT                                 = OBJECT_END + 0x010, // Size: 1, Flags: OWNER
    ITEM_FIELD_DURATION                                    = OBJECT_END + 0x011, // Size: 1, Flags: OWNER
    ITEM_FIELD_SPELL_CHARGES                               = OBJECT_END + 0x012, // Size: 5, Flags: OWNER
    ITEM_FIELD_FLAGS                                       = OBJECT_END + 0x017, // Size: 1, Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT                                 = OBJECT_END + 0x018, // Size: 39, Flags: PUBLIC
    ITEM_FIELD_PROPERTY_SEED                               = OBJECT_END + 0x03F, // Size: 1, Flags: PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID                        = OBJECT_END + 0x040, // Size: 1, Flags: PUBLIC
    ITEM_FIELD_DURABILITY                                  = OBJECT_END + 0x041, // Size: 1, Flags: OWNER
    ITEM_FIELD_MAXDURABILITY                               = OBJECT_END + 0x042, // Size: 1, Flags: OWNER
    ITEM_FIELD_CREATE_PLAYED_TIME                          = OBJECT_END + 0x043, // Size: 1, Flags: PUBLIC
    ITEM_FIELD_MODIFIERS_MASK                              = OBJECT_END + 0x044, // Size: 1, Flags: OWNER
    ITEM_FIELD_CONTEXT                                     = OBJECT_END + 0x045, // Size: 1, Flags: PUBLIC
    ITEM_FIELD_ARTIFACT_XP                                 = OBJECT_END + 0x046, // Size: 2, Flags: OWNER
    ITEM_FIELD_APPEARANCE_MOD_ID                           = OBJECT_END + 0x048, // Size: 1, Flags: OWNER
    ITEM_END                                               = OBJECT_END + 0x049,
};

enum ItemDynamicFields
{
    ITEM_DYNAMIC_FIELD_MODIFIERS                           = OBJECT_DYNAMIC_END + 0x000, // Flags: OWNER
    ITEM_DYNAMIC_FIELD_BONUSLIST_IDS                       = OBJECT_DYNAMIC_END + 0x001, // Flags: OWNER, 0x100
    ITEM_DYNAMIC_FIELD_ARTIFACT_POWERS                     = OBJECT_DYNAMIC_END + 0x002, // Flags: OWNER
    ITEM_DYNAMIC_FIELD_GEMS                                = OBJECT_DYNAMIC_END + 0x003, // Flags: OWNER
    ITEM_DYNAMIC_FIELD_RELIC_TALENT_DATA                   = OBJECT_DYNAMIC_END + 0x004, // Flags: OWNER
    ITEM_DYNAMIC_END                                       = OBJECT_DYNAMIC_END + 0x005,
};

enum ContainerFields
{
    CONTAINER_FIELD_SLOT_1                                 = ITEM_END + 0x000, // Size: 144, Flags: PUBLIC
    CONTAINER_FIELD_NUM_SLOTS                              = ITEM_END + 0x090, // Size: 1, Flags: PUBLIC
    CONTAINER_END                                          = ITEM_END + 0x091,
};

enum ContainerDynamicFields
{
    CONTAINER_DYNAMIC_END                                  = ITEM_DYNAMIC_END + 0x000,
};

enum UnitFields
{
    UNIT_FIELD_CHARM                                       = OBJECT_END + 0x000, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_SUMMON                                      = OBJECT_END + 0x004, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_CRITTER                                     = OBJECT_END + 0x008, // Size: 4, Flags: PRIVATE
    UNIT_FIELD_CHARMEDBY                                   = OBJECT_END + 0x00C, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_SUMMONEDBY                                  = OBJECT_END + 0x010, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_CREATEDBY                                   = OBJECT_END + 0x014, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_DEMON_CREATOR                               = OBJECT_END + 0x018, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_TARGET                                      = OBJECT_END + 0x01C, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_BATTLE_PET_COMPANION_GUID                   = OBJECT_END + 0x020, // Size: 4, Flags: PUBLIC
    UNIT_FIELD_BATTLE_PET_DB_ID                            = OBJECT_END + 0x024, // Size: 2, Flags: PUBLIC
    UNIT_FIELD_CHANNEL_DATA                                = OBJECT_END + 0x026, // Size: 2, Flags: PUBLIC, URGENT
    UNIT_FIELD_SUMMONED_BY_HOME_REALM                      = OBJECT_END + 0x028, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BYTES_0                                     = OBJECT_END + 0x029, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_DISPLAY_POWER                               = OBJECT_END + 0x02A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_OVERRIDE_DISPLAY_POWER_ID                   = OBJECT_END + 0x02B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_HEALTH                                      = OBJECT_END + 0x02C, // Size: 2, Flags: PUBLIC
    UNIT_FIELD_POWER                                       = OBJECT_END + 0x02E, // Size: 6, Flags: PUBLIC, URGENT_SELF_ONLY
    UNIT_FIELD_MAXHEALTH                                   = OBJECT_END + 0x034, // Size: 2, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER                                    = OBJECT_END + 0x036, // Size: 6, Flags: PUBLIC
    UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER                   = OBJECT_END + 0x03C, // Size: 6, Flags: PRIVATE, OWNER, UNIT_ALL
    UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER       = OBJECT_END + 0x042, // Size: 6, Flags: PRIVATE, OWNER, UNIT_ALL
    UNIT_FIELD_LEVEL                                       = OBJECT_END + 0x048, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_EFFECTIVE_LEVEL                             = OBJECT_END + 0x049, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_SCALING_LEVEL_MIN                           = OBJECT_END + 0x04A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_SCALING_LEVEL_MAX                           = OBJECT_END + 0x04B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_SCALING_LEVEL_DELTA                         = OBJECT_END + 0x04C, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                             = OBJECT_END + 0x04D, // Size: 1, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_ID                              = OBJECT_END + 0x04E, // Size: 6, Flags: PUBLIC
    UNIT_FIELD_FLAGS                                       = OBJECT_END + 0x054, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_FLAGS_2                                     = OBJECT_END + 0x055, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_FLAGS_3                                     = OBJECT_END + 0x056, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_AURASTATE                                   = OBJECT_END + 0x057, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                              = OBJECT_END + 0x058, // Size: 2, Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME                            = OBJECT_END + 0x05A, // Size: 1, Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                              = OBJECT_END + 0x05B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                                 = OBJECT_END + 0x05C, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                                   = OBJECT_END + 0x05D, // Size: 1, Flags: DYNAMIC, URGENT
    UNIT_FIELD_NATIVEDISPLAYID                             = OBJECT_END + 0x05E, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_MOUNTDISPLAYID                              = OBJECT_END + 0x05F, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_MINDAMAGE                                   = OBJECT_END + 0x060, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXDAMAGE                                   = OBJECT_END + 0x061, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MINOFFHANDDAMAGE                            = OBJECT_END + 0x062, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXOFFHANDDAMAGE                            = OBJECT_END + 0x063, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_BYTES_1                                     = OBJECT_END + 0x064, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                                   = OBJECT_END + 0x065, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP                          = OBJECT_END + 0x066, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                               = OBJECT_END + 0x067, // Size: 1, Flags: OWNER
    UNIT_FIELD_PETNEXTLEVELEXP                             = OBJECT_END + 0x068, // Size: 1, Flags: OWNER
    UNIT_MOD_CAST_SPEED                                    = OBJECT_END + 0x069, // Size: 1, Flags: PUBLIC
    UNIT_MOD_CAST_HASTE                                    = OBJECT_END + 0x06A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_HASTE                                   = OBJECT_END + 0x06B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_RANGED_HASTE                            = OBJECT_END + 0x06C, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_HASTE_REGEN                             = OBJECT_END + 0x06D, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_TIME_RATE                               = OBJECT_END + 0x06E, // Size: 1, Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                                  = OBJECT_END + 0x06F, // Size: 1, Flags: PUBLIC
    UNIT_NPC_FLAGS                                         = OBJECT_END + 0x070, // Size: 2, Flags: PUBLIC, DYNAMIC
    UNIT_NPC_EMOTESTATE                                    = OBJECT_END + 0x072, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_STAT                                        = OBJECT_END + 0x073, // Size: 4, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT                                     = OBJECT_END + 0x077, // Size: 4, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT                                     = OBJECT_END + 0x07B, // Size: 4, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCES                                 = OBJECT_END + 0x07F, // Size: 7, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE                  = OBJECT_END + 0x086, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE                  = OBJECT_END + 0x08D, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_MOD_BONUS_ARMOR                             = OBJECT_END + 0x094, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_BASE_MANA                                   = OBJECT_END + 0x095, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BASE_HEALTH                                 = OBJECT_END + 0x096, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_BYTES_2                                     = OBJECT_END + 0x097, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_ATTACK_POWER                                = OBJECT_END + 0x098, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_POS                        = OBJECT_END + 0x099, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_NEG                        = OBJECT_END + 0x09A, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER                     = OBJECT_END + 0x09B, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER                         = OBJECT_END + 0x09C, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_POS                 = OBJECT_END + 0x09D, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_NEG                 = OBJECT_END + 0x09E, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER              = OBJECT_END + 0x09F, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_SPEED_AURA                           = OBJECT_END + 0x0A0, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_MINRANGEDDAMAGE                             = OBJECT_END + 0x0A1, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXRANGEDDAMAGE                             = OBJECT_END + 0x0A2, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MODIFIER                         = OBJECT_END + 0x0A3, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_POWER_COST_MULTIPLIER                       = OBJECT_END + 0x0AA, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_MAXHEALTHMODIFIER                           = OBJECT_END + 0x0B1, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_HOVERHEIGHT                                 = OBJECT_END + 0x0B2, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MIN_ITEM_LEVEL_CUTOFF                       = OBJECT_END + 0x0B3, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MIN_ITEM_LEVEL                              = OBJECT_END + 0x0B4, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MAXITEMLEVEL                                = OBJECT_END + 0x0B5, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_WILD_BATTLEPET_LEVEL                        = OBJECT_END + 0x0B6, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BATTLEPET_COMPANION_NAME_TIMESTAMP          = OBJECT_END + 0x0B7, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_INTERACT_SPELLID                            = OBJECT_END + 0x0B8, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_STATE_SPELL_VISUAL_ID                       = OBJECT_END + 0x0B9, // Size: 1, Flags: DYNAMIC, URGENT
    UNIT_FIELD_STATE_ANIM_ID                               = OBJECT_END + 0x0BA, // Size: 1, Flags: DYNAMIC, URGENT
    UNIT_FIELD_STATE_ANIM_KIT_ID                           = OBJECT_END + 0x0BB, // Size: 1, Flags: DYNAMIC, URGENT
    UNIT_FIELD_STATE_WORLD_EFFECT_ID                       = OBJECT_END + 0x0BC, // Size: 4, Flags: DYNAMIC, URGENT
    UNIT_FIELD_SCALE_DURATION                              = OBJECT_END + 0x0C0, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_LOOKS_LIKE_MOUNT_ID                         = OBJECT_END + 0x0C1, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_LOOKS_LIKE_CREATURE_ID                      = OBJECT_END + 0x0C2, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_LOOK_AT_CONTROLLER_ID                       = OBJECT_END + 0x0C3, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_LOOK_AT_CONTROLLER_TARGET                   = OBJECT_END + 0x0C4, // Size: 4, Flags: PUBLIC
    UNIT_END                                               = OBJECT_END + 0x0C8,
};

enum UnitDynamicFields
{
    UNIT_DYNAMIC_FIELD_PASSIVE_SPELLS                      = OBJECT_DYNAMIC_END + 0x000, // Flags: PUBLIC, URGENT
    UNIT_DYNAMIC_FIELD_WORLD_EFFECTS                       = OBJECT_DYNAMIC_END + 0x001, // Flags: PUBLIC, URGENT
    UNIT_DYNAMIC_FIELD_CHANNEL_OBJECTS                     = OBJECT_DYNAMIC_END + 0x002, // Flags: PUBLIC, URGENT
    UNIT_DYNAMIC_END                                       = OBJECT_DYNAMIC_END + 0x003,
};

enum PlayerFields
{
    PLAYER_DUEL_ARBITER                                    = UNIT_END + 0x000, // Size: 4, Flags: PUBLIC
    PLAYER_WOW_ACCOUNT                                     = UNIT_END + 0x004, // Size: 4, Flags: PUBLIC
    PLAYER_LOOT_TARGET_GUID                                = UNIT_END + 0x008, // Size: 4, Flags: PUBLIC
    PLAYER_FLAGS                                           = UNIT_END + 0x00C, // Size: 1, Flags: PUBLIC
    PLAYER_FLAGS_EX                                        = UNIT_END + 0x00D, // Size: 1, Flags: PUBLIC
    PLAYER_GUILDRANK                                       = UNIT_END + 0x00E, // Size: 1, Flags: PUBLIC
    PLAYER_GUILDDELETE_DATE                                = UNIT_END + 0x00F, // Size: 1, Flags: PUBLIC
    PLAYER_GUILDLEVEL                                      = UNIT_END + 0x010, // Size: 1, Flags: PUBLIC
    PLAYER_BYTES                                           = UNIT_END + 0x011, // Size: 1, Flags: PUBLIC
    PLAYER_BYTES_2                                         = UNIT_END + 0x012, // Size: 1, Flags: PUBLIC
    PLAYER_BYTES_3                                         = UNIT_END + 0x013, // Size: 1, Flags: PUBLIC
    PLAYER_BYTES_4                                         = UNIT_END + 0x014, // Size: 1, Flags: PUBLIC
    PLAYER_DUEL_TEAM                                       = UNIT_END + 0x015, // Size: 1, Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                                 = UNIT_END + 0x016, // Size: 1, Flags: PUBLIC
    PLAYER_QUEST_LOG                                       = UNIT_END + 0x017, // Size: 800, Flags: PARTY_MEMBER
    PLAYER_VISIBLE_ITEM                                    = UNIT_END + 0x337, // Size: 38, Flags: PUBLIC
    PLAYER_CHOSEN_TITLE                                    = UNIT_END + 0x35D, // Size: 1, Flags: PUBLIC
    PLAYER_FAKE_INEBRIATION                                = UNIT_END + 0x35E, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_VIRTUAL_PLAYER_REALM                      = UNIT_END + 0x35F, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_CURRENT_SPEC_ID                           = UNIT_END + 0x360, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_TAXI_MOUNT_ANIM_KIT_ID                    = UNIT_END + 0x361, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_AVG_ITEM_LEVEL                            = UNIT_END + 0x362, // Size: 4, Flags: PUBLIC
    PLAYER_FIELD_CURRENT_BATTLE_PET_BREED_QUALITY          = UNIT_END + 0x366, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_PRESTIGE                                  = UNIT_END + 0x367, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_HONOR_LEVEL                               = UNIT_END + 0x368, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_INV_SLOT_HEAD                             = UNIT_END + 0x369, // Size: 748, Flags: PRIVATE
    PLAYER_FIELD_END_NOT_SELF                              = UNIT_END + 0x369,
    PLAYER_FARSIGHT                                        = UNIT_END + 0x655, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_SUMMONED_BATTLE_PET_ID                    = UNIT_END + 0x659, // Size: 4, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES                             = UNIT_END + 0x65D, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_COINAGE                                   = UNIT_END + 0x669, // Size: 2, Flags: PRIVATE
    PLAYER_XP                                              = UNIT_END + 0x66B, // Size: 1, Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                                   = UNIT_END + 0x66C, // Size: 1, Flags: PRIVATE
    PLAYER_SKILL_LINEID                                    = UNIT_END + 0x66D, // Size: 448, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS                                = UNIT_END + 0x82D, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MAX_TALENT_TIERS                          = UNIT_END + 0x82E, // Size: 1, Flags: PRIVATE
    PLAYER_TRACK_CREATURES                                 = UNIT_END + 0x82F, // Size: 1, Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                                 = UNIT_END + 0x830, // Size: 1, Flags: PRIVATE
    PLAYER_EXPERTISE                                       = UNIT_END + 0x831, // Size: 1, Flags: PRIVATE
    PLAYER_OFFHAND_EXPERTISE                               = UNIT_END + 0x832, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_RANGED_EXPERTISE                          = UNIT_END + 0x833, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_EXPERTISE                   = UNIT_END + 0x834, // Size: 1, Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                                = UNIT_END + 0x835, // Size: 1, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                                = UNIT_END + 0x836, // Size: 1, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE_FROM_ATTRIBUTE                 = UNIT_END + 0x837, // Size: 1, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                                = UNIT_END + 0x838, // Size: 1, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE_FROM_ATTRIBUTE                 = UNIT_END + 0x839, // Size: 1, Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                                 = UNIT_END + 0x83A, // Size: 1, Flags: PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE                          = UNIT_END + 0x83B, // Size: 1, Flags: PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE                         = UNIT_END + 0x83C, // Size: 1, Flags: PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1                          = UNIT_END + 0x83D, // Size: 1, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK                                    = UNIT_END + 0x83E, // Size: 1, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE                    = UNIT_END + 0x83F, // Size: 1, Flags: PRIVATE
    PLAYER_MASTERY                                         = UNIT_END + 0x840, // Size: 1, Flags: PRIVATE
    PLAYER_SPEED                                           = UNIT_END + 0x841, // Size: 1, Flags: PRIVATE
    PLAYER_LIFESTEAL                                       = UNIT_END + 0x842, // Size: 1, Flags: PRIVATE
    PLAYER_AVOIDANCE                                       = UNIT_END + 0x843, // Size: 1, Flags: PRIVATE
    PLAYER_STURDINESS                                      = UNIT_END + 0x844, // Size: 1, Flags: PRIVATE
    PLAYER_VERSATILITY                                     = UNIT_END + 0x845, // Size: 1, Flags: PRIVATE
    PLAYER_VERSATILITY_BONUS                               = UNIT_END + 0x846, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_POWER_DAMAGE                          = UNIT_END + 0x847, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_POWER_HEALING                         = UNIT_END + 0x848, // Size: 1, Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                                = UNIT_END + 0x849, // Size: 320, Flags: PRIVATE
    PLAYER_FIELD_REST_INFO                                 = UNIT_END + 0x989, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS                       = UNIT_END + 0x98D, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                       = UNIT_END + 0x994, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                       = UNIT_END + 0x99B, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS                      = UNIT_END + 0x9A2, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_PCT                           = UNIT_END + 0x9A3, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_PCT                      = UNIT_END + 0x9A4, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_PERIODIC_HEALING_DONE_PERCENT         = UNIT_END + 0x9A5, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_WEAPON_DMG_MULTIPLIERS                    = UNIT_END + 0x9A6, // Size: 3, Flags: PRIVATE
    PLAYER_FIELD_WEAPON_ATK_SPEED_MULTIPLIERS              = UNIT_END + 0x9A9, // Size: 3, Flags: PRIVATE
    PLAYER_FIELD_MOD_SPELL_POWER_PCT                       = UNIT_END + 0x9AC, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_RESILIENCE_PERCENT                    = UNIT_END + 0x9AD, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_SPELL_POWER_BY_AP_PCT            = UNIT_END + 0x9AE, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_AP_BY_SPELL_POWER_PERCENT        = UNIT_END + 0x9AF, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE                     = UNIT_END + 0x9B0, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE            = UNIT_END + 0x9B1, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LOCAL_FLAGS                               = UNIT_END + 0x9B2, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BYTES                                     = UNIT_END + 0x9B3, // Size: 1, Flags: PRIVATE
    PLAYER_SELF_RES_SPELL                                  = UNIT_END + 0x9B4, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                                = UNIT_END + 0x9B5, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1                           = UNIT_END + 0x9B6, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1                       = UNIT_END + 0x9C2, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_KILLS                                     = UNIT_END + 0x9CE, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LIFETIME_HONORABLE_KILLS                  = UNIT_END + 0x9CF, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX                     = UNIT_END + 0x9D0, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1                           = UNIT_END + 0x9D1, // Size: 32, Flags: PRIVATE
    PLAYER_FIELD_ARENA_TEAM_INFO_1_1                       = UNIT_END + 0x9F1, // Size: 42, Flags: PRIVATE
    PLAYER_FIELD_MAX_LEVEL                                 = UNIT_END + 0xA1B, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_SCALING_PLAYER_LEVEL_DELTA                = UNIT_END + 0xA1C, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MAX_CREATURE_SCALING_LEVEL                = UNIT_END + 0xA1D, // Size: 1, Flags: PRIVATE
    PLAYER_NO_REAGENT_COST_1                               = UNIT_END + 0xA1E, // Size: 4, Flags: PRIVATE
    PLAYER_PET_SPELL_POWER                                 = UNIT_END + 0xA22, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_RESEARCHING_1                             = UNIT_END + 0xA23, // Size: 10, Flags: PRIVATE
    PLAYER_PROFESSION_SKILL_LINE_1                         = UNIT_END + 0xA2D, // Size: 2, Flags: PRIVATE
    PLAYER_FIELD_UI_HIT_MODIFIER                           = UNIT_END + 0xA2F, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_UI_SPELL_HIT_MODIFIER                     = UNIT_END + 0xA30, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_HOME_REALM_TIME_OFFSET                    = UNIT_END + 0xA31, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_PET_HASTE                             = UNIT_END + 0xA32, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BYTES2                                    = UNIT_END + 0xA33, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BYTES3                                    = UNIT_END + 0xA34, // Size: 1, Flags: PRIVATE, URGENT_SELF_ONLY
    PLAYER_FIELD_LFG_BONUS_FACTION_ID                      = UNIT_END + 0xA35, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LOOT_SPEC_ID                              = UNIT_END + 0xA36, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_ZONE_PVP_TYPE                    = UNIT_END + 0xA37, // Size: 1, Flags: PRIVATE, URGENT_SELF_ONLY
    PLAYER_FIELD_BAG_SLOT_FLAGS                            = UNIT_END + 0xA38, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_BANK_BAG_SLOT_FLAGS                       = UNIT_END + 0xA3C, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_INSERT_ITEMS_LEFT_TO_RIGHT                = UNIT_END + 0xA43, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_QUEST_COMPLETED                           = UNIT_END + 0xA44, // Size: 1750, Flags: PRIVATE
    PLAYER_FIELD_HONOR                                     = UNIT_END + 0x111A, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_HONOR_NEXT_LEVEL                          = UNIT_END + 0x111B, // Size: 1, Flags: PRIVATE
    PLAYER_END                                             = UNIT_END + 0x111C,
};

enum PlayerDynamicFields
{
    PLAYER_DYNAMIC_FIELD_RESERACH_SITE                     = UNIT_DYNAMIC_END + 0x000, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_RESEARCH_SITE_PROGRESS            = UNIT_DYNAMIC_END + 0x001, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_DAILY_QUESTS                      = UNIT_DYNAMIC_END + 0x002, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_AVAILABLE_QUEST_LINE_X_QUEST_ID   = UNIT_DYNAMIC_END + 0x003, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_HEIRLOOMS                         = UNIT_DYNAMIC_END + 0x004, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_HEIRLOOM_FLAGS                    = UNIT_DYNAMIC_END + 0x005, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_TOYS                              = UNIT_DYNAMIC_END + 0x006, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_TRANSMOG                          = UNIT_DYNAMIC_END + 0x007, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_CONDITIONAL_TRANSMOG              = UNIT_DYNAMIC_END + 0x008, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_CHARACTER_RESTRICTIONS            = UNIT_DYNAMIC_END + 0x009, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_SPELL_PCT_MOD_BY_LABEL            = UNIT_DYNAMIC_END + 0x00A, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_SPELL_FLAT_MOD_BY_LABEL           = UNIT_DYNAMIC_END + 0x00B, // Flags: PRIVATE
    PLAYER_DYNAMIC_FIELD_ARENA_COOLDOWNS                   = UNIT_DYNAMIC_END + 0x00C, // Flags: PUBLIC
    PLAYER_DYNAMIC_END                                     = UNIT_DYNAMIC_END + 0x00D,
};

enum GameObjectFields
{
    GAMEOBJECT_FIELD_CREATED_BY                            = OBJECT_END + 0x000, // Size: 4, Flags: PUBLIC
    GAMEOBJECT_DISPLAYID                                   = OBJECT_END + 0x004, // Size: 1, Flags: DYNAMIC, URGENT
    GAMEOBJECT_FLAGS                                       = OBJECT_END + 0x005, // Size: 1, Flags: PUBLIC, URGENT
    GAMEOBJECT_PARENTROTATION                              = OBJECT_END + 0x006, // Size: 4, Flags: PUBLIC
    GAMEOBJECT_FACTION                                     = OBJECT_END + 0x00A, // Size: 1, Flags: PUBLIC
    GAMEOBJECT_LEVEL                                       = OBJECT_END + 0x00B, // Size: 1, Flags: PUBLIC
    GAMEOBJECT_BYTES_1                                     = OBJECT_END + 0x00C, // Size: 1, Flags: PUBLIC, URGENT
    GAMEOBJECT_SPELL_VISUAL_ID                             = OBJECT_END + 0x00D, // Size: 1, Flags: PUBLIC, DYNAMIC, URGENT
    GAMEOBJECT_STATE_SPELL_VISUAL_ID                       = OBJECT_END + 0x00E, // Size: 1, Flags: DYNAMIC, URGENT
    GAMEOBJECT_STATE_ANIM_ID                               = OBJECT_END + 0x00F, // Size: 1, Flags: DYNAMIC, URGENT
    GAMEOBJECT_STATE_ANIM_KIT_ID                           = OBJECT_END + 0x010, // Size: 1, Flags: DYNAMIC, URGENT
    GAMEOBJECT_STATE_WORLD_EFFECT_ID                       = OBJECT_END + 0x011, // Size: 4, Flags: DYNAMIC, URGENT
    GAMEOBJECT_END                                         = OBJECT_END + 0x015,
};

enum GameObjectDynamicFields
{
    GAMEOBJECT_DYNAMIC_ENABLE_DOODAD_SETS                  = OBJECT_DYNAMIC_END + 0x000, // Flags: PUBLIC
    GAMEOBJECT_DYNAMIC_END                                 = OBJECT_DYNAMIC_END + 0x001,
};

enum DynamicObjectFields
{
    DYNAMICOBJECT_CASTER                                   = OBJECT_END + 0x000, // Size: 4, Flags: PUBLIC
    DYNAMICOBJECT_TYPE                                     = OBJECT_END + 0x004, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_SPELL_X_SPELL_VISUAL_ID                  = OBJECT_END + 0x005, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_SPELLID                                  = OBJECT_END + 0x006, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                                   = OBJECT_END + 0x007, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_CASTTIME                                 = OBJECT_END + 0x008, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_END                                      = OBJECT_END + 0x009,
};

enum DynamicObjectDynamicFields
{
    DYNAMICOBJECT_DYNAMIC_END                              = OBJECT_DYNAMIC_END + 0x000,
};

enum CorpseFields
{
    CORPSE_FIELD_OWNER                                     = OBJECT_END + 0x000, // Size: 4, Flags: PUBLIC
    CORPSE_FIELD_PARTY                                     = OBJECT_END + 0x004, // Size: 4, Flags: PUBLIC
    CORPSE_FIELD_DISPLAY_ID                                = OBJECT_END + 0x008, // Size: 1, Flags: PUBLIC
    CORPSE_FIELD_ITEM                                      = OBJECT_END + 0x009, // Size: 19, Flags: PUBLIC
    CORPSE_FIELD_BYTES_1                                   = OBJECT_END + 0x01C, // Size: 1, Flags: PUBLIC
    CORPSE_FIELD_BYTES_2                                   = OBJECT_END + 0x01D, // Size: 1, Flags: PUBLIC
    CORPSE_FIELD_FLAGS                                     = OBJECT_END + 0x01E, // Size: 1, Flags: PUBLIC
    CORPSE_FIELD_DYNAMIC_FLAGS                             = OBJECT_END + 0x01F, // Size: 1, Flags: DYNAMIC
    CORPSE_FIELD_FACTIONTEMPLATE                           = OBJECT_END + 0x020, // Size: 1, Flags: PUBLIC
    CORPSE_FIELD_CUSTOM_DISPLAY_OPTION                     = OBJECT_END + 0x021, // Size: 1, Flags: PUBLIC
    CORPSE_END                                             = OBJECT_END + 0x022,
};

enum CorpseDynamicFields
{
    CORPSE_DYNAMIC_END                                     = OBJECT_DYNAMIC_END + 0x000,
};

enum AreaTriggerFields
{
    AREATRIGGER_OVERRIDE_SCALE_CURVE                       = OBJECT_END + 0x000, // Size: 7, Flags: PUBLIC, URGENT
    AREATRIGGER_EXTRA_SCALE_CURVE                          = OBJECT_END + 0x007, // Size: 7, Flags: PUBLIC, URGENT
    AREATRIGGER_CASTER                                     = OBJECT_END + 0x00E, // Size: 4, Flags: PUBLIC
    AREATRIGGER_DURATION                                   = OBJECT_END + 0x012, // Size: 1, Flags: PUBLIC
    AREATRIGGER_TIME_TO_TARGET                             = OBJECT_END + 0x013, // Size: 1, Flags: PUBLIC, URGENT
    AREATRIGGER_TIME_TO_TARGET_SCALE                       = OBJECT_END + 0x014, // Size: 1, Flags: PUBLIC, URGENT
    AREATRIGGER_TIME_TO_TARGET_EXTRA_SCALE                 = OBJECT_END + 0x015, // Size: 1, Flags: PUBLIC, URGENT
    AREATRIGGER_SPELLID                                    = OBJECT_END + 0x016, // Size: 1, Flags: PUBLIC
    AREATRIGGER_SPELL_FOR_VISUALS                          = OBJECT_END + 0x017, // Size: 1, Flags: PUBLIC
    AREATRIGGER_SPELL_X_SPELL_VISUAL_ID                    = OBJECT_END + 0x018, // Size: 1, Flags: PUBLIC
    AREATRIGGER_BOUNDS_RADIUS_2D                           = OBJECT_END + 0x019, // Size: 1, Flags: DYNAMIC, URGENT
    AREATRIGGER_DECAL_PROPERTIES_ID                        = OBJECT_END + 0x01A, // Size: 1, Flags: PUBLIC
    AREATRIGGER_CREATING_EFFECT_GUID                       = OBJECT_END + 0x01B, // Size: 4, Flags: PUBLIC
    AREATRIGGER_END                                        = OBJECT_END + 0x01F,
};

enum AreaTriggerDynamicFields
{
    AREATRIGGER_DYNAMIC_END                                = OBJECT_DYNAMIC_END + 0x000,
};

enum SceneObjectFields
{
    SCENEOBJECT_FIELD_SCRIPT_PACKAGE_ID                    = OBJECT_END + 0x000, // Size: 1, Flags: PUBLIC
    SCENEOBJECT_FIELD_RND_SEED_VAL                         = OBJECT_END + 0x001, // Size: 1, Flags: PUBLIC
    SCENEOBJECT_FIELD_CREATEDBY                            = OBJECT_END + 0x002, // Size: 4, Flags: PUBLIC
    SCENEOBJECT_FIELD_SCENE_TYPE                           = OBJECT_END + 0x006, // Size: 1, Flags: PUBLIC
    SCENEOBJECT_END                                        = OBJECT_END + 0x007,
};

enum SceneObjectDynamicFields
{
    SCENEOBJECT_DYNAMIC_END                                = OBJECT_DYNAMIC_END + 0x000,
};

enum ConversationFields
{
    CONVERSATION_LAST_LINE_END_TIME                        = OBJECT_END + 0x000, // Size: 1, Flags: DYNAMIC
    CONVERSATION_END                                       = OBJECT_END + 0x001,
};

enum ConversationDynamicFields
{
    CONVERSATION_DYNAMIC_FIELD_ACTORS                      = OBJECT_DYNAMIC_END + 0x000, // Flags: PUBLIC
    CONVERSATION_DYNAMIC_FIELD_LINES                       = OBJECT_DYNAMIC_END + 0x001, // Flags: 0x100
    CONVERSATION_DYNAMIC_END                               = OBJECT_DYNAMIC_END + 0x002,
};

#endif // _UPDATEFIELDS_H
