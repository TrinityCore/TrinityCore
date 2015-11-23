/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

// Auto generated for version 6, 2, 3, 20726

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
    ITEM_END                                               = OBJECT_END + 0x046,
};

enum ItemDynamicFields
{
    ITEM_DYNAMIC_FIELD_MODIFIERS                           = OBJECT_DYNAMIC_END + 0x000, // Flags: OWNER
    ITEM_DYNAMIC_FIELD_BONUSLIST_IDS                       = OBJECT_DYNAMIC_END + 0x001, // Flags: OWNER, 0x100
    ITEM_DYNAMIC_END                                       = OBJECT_DYNAMIC_END + 0x002,
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
    UNIT_FIELD_CHANNEL_OBJECT                              = OBJECT_END + 0x026, // Size: 4, Flags: PUBLIC, URGENT
    UNIT_CHANNEL_SPELL                                     = OBJECT_END + 0x02A, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_CHANNEL_SPELL_X_SPELL_VISUAL                      = OBJECT_END + 0x02B, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_SUMMONED_BY_HOME_REALM                      = OBJECT_END + 0x02C, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BYTES_0                                     = OBJECT_END + 0x02D, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_DISPLAY_POWER                               = OBJECT_END + 0x02E, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_OVERRIDE_DISPLAY_POWER_ID                   = OBJECT_END + 0x02F, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_HEALTH                                      = OBJECT_END + 0x030, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_POWER                                       = OBJECT_END + 0x031, // Size: 6, Flags: PUBLIC, URGENT_SELF_ONLY
    UNIT_FIELD_MAXHEALTH                                   = OBJECT_END + 0x037, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MAXPOWER                                    = OBJECT_END + 0x038, // Size: 6, Flags: PUBLIC
    UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER                   = OBJECT_END + 0x03E, // Size: 6, Flags: PRIVATE, OWNER, UNIT_ALL
    UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER       = OBJECT_END + 0x044, // Size: 6, Flags: PRIVATE, OWNER, UNIT_ALL
    UNIT_FIELD_LEVEL                                       = OBJECT_END + 0x04A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_EFFECTIVE_LEVEL                             = OBJECT_END + 0x04B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                             = OBJECT_END + 0x04C, // Size: 1, Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_ID                              = OBJECT_END + 0x04D, // Size: 6, Flags: PUBLIC
    UNIT_FIELD_FLAGS                                       = OBJECT_END + 0x053, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_FLAGS_2                                     = OBJECT_END + 0x054, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_FLAGS_3                                     = OBJECT_END + 0x055, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_AURASTATE                                   = OBJECT_END + 0x056, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                              = OBJECT_END + 0x057, // Size: 2, Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME                            = OBJECT_END + 0x059, // Size: 1, Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                              = OBJECT_END + 0x05A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                                 = OBJECT_END + 0x05B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                                   = OBJECT_END + 0x05C, // Size: 1, Flags: DYNAMIC, URGENT
    UNIT_FIELD_NATIVEDISPLAYID                             = OBJECT_END + 0x05D, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_MOUNTDISPLAYID                              = OBJECT_END + 0x05E, // Size: 1, Flags: PUBLIC, URGENT
    UNIT_FIELD_MINDAMAGE                                   = OBJECT_END + 0x05F, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXDAMAGE                                   = OBJECT_END + 0x060, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MINOFFHANDDAMAGE                            = OBJECT_END + 0x061, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_MAXOFFHANDDAMAGE                            = OBJECT_END + 0x062, // Size: 1, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_BYTES_1                                     = OBJECT_END + 0x063, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                                   = OBJECT_END + 0x064, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP                          = OBJECT_END + 0x065, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                               = OBJECT_END + 0x066, // Size: 1, Flags: OWNER
    UNIT_FIELD_PETNEXTLEVELEXP                             = OBJECT_END + 0x067, // Size: 1, Flags: OWNER
    UNIT_MOD_CAST_SPEED                                    = OBJECT_END + 0x068, // Size: 1, Flags: PUBLIC
    UNIT_MOD_CAST_HASTE                                    = OBJECT_END + 0x069, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_HASTE                                   = OBJECT_END + 0x06A, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_RANGED_HASTE                            = OBJECT_END + 0x06B, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_MOD_HASTE_REGEN                             = OBJECT_END + 0x06C, // Size: 1, Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                                  = OBJECT_END + 0x06D, // Size: 1, Flags: PUBLIC
    UNIT_NPC_FLAGS                                         = OBJECT_END + 0x06E, // Size: 2, Flags: PUBLIC, DYNAMIC
    UNIT_NPC_EMOTESTATE                                    = OBJECT_END + 0x070, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_STAT                                        = OBJECT_END + 0x071, // Size: 5, Flags: PRIVATE, OWNER
    UNIT_FIELD_POSSTAT                                     = OBJECT_END + 0x076, // Size: 5, Flags: PRIVATE, OWNER
    UNIT_FIELD_NEGSTAT                                     = OBJECT_END + 0x07B, // Size: 5, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCES                                 = OBJECT_END + 0x080, // Size: 7, Flags: PRIVATE, OWNER, SPECIAL_INFO
    UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE                  = OBJECT_END + 0x087, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE                  = OBJECT_END + 0x08E, // Size: 7, Flags: PRIVATE, OWNER
    UNIT_FIELD_MOD_BONUS_ARMOR                             = OBJECT_END + 0x095, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_BASE_MANA                                   = OBJECT_END + 0x096, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_BASE_HEALTH                                 = OBJECT_END + 0x097, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_BYTES_2                                     = OBJECT_END + 0x098, // Size: 1, Flags: PUBLIC
    UNIT_FIELD_ATTACK_POWER                                = OBJECT_END + 0x099, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_POS                        = OBJECT_END + 0x09A, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MOD_NEG                        = OBJECT_END + 0x09B, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_ATTACK_POWER_MULTIPLIER                     = OBJECT_END + 0x09C, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER                         = OBJECT_END + 0x09D, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_POS                 = OBJECT_END + 0x09E, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MOD_NEG                 = OBJECT_END + 0x09F, // Size: 1, Flags: PRIVATE, OWNER
    UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER              = OBJECT_END + 0x0A0, // Size: 1, Flags: PRIVATE, OWNER
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
    UNIT_DYNAMIC_END                                       = OBJECT_DYNAMIC_END + 0x002,
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
    PLAYER_DUEL_TEAM                                       = UNIT_END + 0x014, // Size: 1, Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                                 = UNIT_END + 0x015, // Size: 1, Flags: PUBLIC
    PLAYER_QUEST_LOG                                       = UNIT_END + 0x016, // Size: 750, Flags: PARTY_MEMBER
    PLAYER_VISIBLE_ITEM                                    = UNIT_END + 0x304, // Size: 38, Flags: PUBLIC
    PLAYER_CHOSEN_TITLE                                    = UNIT_END + 0x32A, // Size: 1, Flags: PUBLIC
    PLAYER_FAKE_INEBRIATION                                = UNIT_END + 0x32B, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_VIRTUAL_PLAYER_REALM                      = UNIT_END + 0x32C, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_CURRENT_SPEC_ID                           = UNIT_END + 0x32D, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_TAXI_MOUNT_ANIM_KIT_ID                    = UNIT_END + 0x32E, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_AVG_ITEM_LEVEL                            = UNIT_END + 0x32F, // Size: 4, Flags: PUBLIC
    PLAYER_FIELD_CURRENT_BATTLE_PET_BREED_QUALITY          = UNIT_END + 0x333, // Size: 1, Flags: PUBLIC
    PLAYER_FIELD_INV_SLOT_HEAD                             = UNIT_END + 0x334, // Size: 736, Flags: PRIVATE
    PLAYER_FIELD_END_NOT_SELF                              = UNIT_END + 0x334,
    PLAYER_FARSIGHT                                        = UNIT_END + 0x614, // Size: 4, Flags: PRIVATE
    PLAYER__FIELD_KNOWN_TITLES                             = UNIT_END + 0x618, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_COINAGE                                   = UNIT_END + 0x624, // Size: 2, Flags: PRIVATE
    PLAYER_XP                                              = UNIT_END + 0x626, // Size: 1, Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                                   = UNIT_END + 0x627, // Size: 1, Flags: PRIVATE
    PLAYER_SKILL_LINEID                                    = UNIT_END + 0x628, // Size: 448, Flags: PRIVATE
    PLAYER_CHARACTER_POINTS                                = UNIT_END + 0x7E8, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MAX_TALENT_TIERS                          = UNIT_END + 0x7E9, // Size: 1, Flags: PRIVATE
    PLAYER_TRACK_CREATURES                                 = UNIT_END + 0x7EA, // Size: 1, Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                                 = UNIT_END + 0x7EB, // Size: 1, Flags: PRIVATE
    PLAYER_EXPERTISE                                       = UNIT_END + 0x7EC, // Size: 1, Flags: PRIVATE
    PLAYER_OFFHAND_EXPERTISE                               = UNIT_END + 0x7ED, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_RANGED_EXPERTISE                          = UNIT_END + 0x7EE, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_EXPERTISE                   = UNIT_END + 0x7EF, // Size: 1, Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                                = UNIT_END + 0x7F0, // Size: 1, Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                                = UNIT_END + 0x7F1, // Size: 1, Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                                = UNIT_END + 0x7F2, // Size: 1, Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                                 = UNIT_END + 0x7F3, // Size: 1, Flags: PRIVATE
    PLAYER_RANGED_CRIT_PERCENTAGE                          = UNIT_END + 0x7F4, // Size: 1, Flags: PRIVATE
    PLAYER_OFFHAND_CRIT_PERCENTAGE                         = UNIT_END + 0x7F5, // Size: 1, Flags: PRIVATE
    PLAYER_SPELL_CRIT_PERCENTAGE1                          = UNIT_END + 0x7F6, // Size: 7, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK                                    = UNIT_END + 0x7FD, // Size: 1, Flags: PRIVATE
    PLAYER_SHIELD_BLOCK_CRIT_PERCENTAGE                    = UNIT_END + 0x7FE, // Size: 1, Flags: PRIVATE
    PLAYER_MASTERY                                         = UNIT_END + 0x7FF, // Size: 1, Flags: PRIVATE
    PLAYER_AMPLIFY                                         = UNIT_END + 0x800, // Size: 1, Flags: PRIVATE
    PLAYER_MULTISTRIKE                                     = UNIT_END + 0x801, // Size: 1, Flags: PRIVATE
    PLAYER_MULTISTRIKE_EFFECT                              = UNIT_END + 0x802, // Size: 1, Flags: PRIVATE
    PLAYER_READINESS                                       = UNIT_END + 0x803, // Size: 1, Flags: PRIVATE
    PLAYER_SPEED                                           = UNIT_END + 0x804, // Size: 1, Flags: PRIVATE
    PLAYER_LIFESTEAL                                       = UNIT_END + 0x805, // Size: 1, Flags: PRIVATE
    PLAYER_AVOIDANCE                                       = UNIT_END + 0x806, // Size: 1, Flags: PRIVATE
    PLAYER_STURDINESS                                      = UNIT_END + 0x807, // Size: 1, Flags: PRIVATE
    PLAYER_CLEAVE                                          = UNIT_END + 0x808, // Size: 1, Flags: PRIVATE
    PLAYER_VERSATILITY                                     = UNIT_END + 0x809, // Size: 1, Flags: PRIVATE
    PLAYER_VERSATILITY_BONUS                               = UNIT_END + 0x80A, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_POWER_DAMAGE                          = UNIT_END + 0x80B, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_POWER_HEALING                         = UNIT_END + 0x80C, // Size: 1, Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                                = UNIT_END + 0x80D, // Size: 256, Flags: PRIVATE
    PLAYER_REST_STATE_EXPERIENCE                           = UNIT_END + 0x90D, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS                       = UNIT_END + 0x90E, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                       = UNIT_END + 0x915, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                       = UNIT_END + 0x91C, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_POS                      = UNIT_END + 0x923, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_PCT                           = UNIT_END + 0x924, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_HEALING_DONE_PCT                      = UNIT_END + 0x925, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_PERIODIC_HEALING_DONE_PERCENT         = UNIT_END + 0x926, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_WEAPON_DMG_MULTIPLIERS                    = UNIT_END + 0x927, // Size: 3, Flags: PRIVATE
    PLAYER_FIELD_WEAPON_ATK_SPEED_MULTIPLIERS              = UNIT_END + 0x92A, // Size: 3, Flags: PRIVATE
    PLAYER_FIELD_MOD_SPELL_POWER_PCT                       = UNIT_END + 0x92D, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_RESILIENCE_PERCENT                    = UNIT_END + 0x92E, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_SPELL_POWER_BY_AP_PCT            = UNIT_END + 0x92F, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_AP_BY_SPELL_POWER_PERCENT        = UNIT_END + 0x930, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_RESISTANCE                     = UNIT_END + 0x931, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_TARGET_PHYSICAL_RESISTANCE            = UNIT_END + 0x932, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LOCAL_FLAGS                               = UNIT_END + 0x933, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BYTES                                     = UNIT_END + 0x934, // Size: 1, Flags: PRIVATE
    PLAYER_SELF_RES_SPELL                                  = UNIT_END + 0x935, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                                = UNIT_END + 0x936, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE_1                           = UNIT_END + 0x937, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_TIMESTAMP_1                       = UNIT_END + 0x943, // Size: 12, Flags: PRIVATE
    PLAYER_FIELD_KILLS                                     = UNIT_END + 0x94F, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LIFETIME_HONORABLE_KILLS                  = UNIT_END + 0x950, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_WATCHED_FACTION_INDEX                     = UNIT_END + 0x951, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_COMBAT_RATING_1                           = UNIT_END + 0x952, // Size: 32, Flags: PRIVATE
    PLAYER_FIELD_ARENA_TEAM_INFO_1_1                       = UNIT_END + 0x972, // Size: 36, Flags: PRIVATE
    PLAYER_FIELD_MAX_LEVEL                                 = UNIT_END + 0x996, // Size: 1, Flags: PRIVATE
    PLAYER_RUNE_REGEN_1                                    = UNIT_END + 0x997, // Size: 4, Flags: PRIVATE
    PLAYER_NO_REAGENT_COST_1                               = UNIT_END + 0x99B, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_GLYPH_SLOTS_1                             = UNIT_END + 0x99F, // Size: 6, Flags: PRIVATE
    PLAYER_FIELD_GLYPHS_1                                  = UNIT_END + 0x9A5, // Size: 6, Flags: PRIVATE
    PLAYER_GLYPHS_ENABLED                                  = UNIT_END + 0x9AB, // Size: 1, Flags: PRIVATE
    PLAYER_PET_SPELL_POWER                                 = UNIT_END + 0x9AC, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_RESEARCHING_1                             = UNIT_END + 0x9AD, // Size: 10, Flags: PRIVATE
    PLAYER_PROFESSION_SKILL_LINE_1                         = UNIT_END + 0x9B7, // Size: 2, Flags: PRIVATE
    PLAYER_FIELD_UI_HIT_MODIFIER                           = UNIT_END + 0x9B9, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_UI_SPELL_HIT_MODIFIER                     = UNIT_END + 0x9BA, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_HOME_REALM_TIME_OFFSET                    = UNIT_END + 0x9BB, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_MOD_PET_HASTE                             = UNIT_END + 0x9BC, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_SUMMONED_BATTLE_PET_ID                    = UNIT_END + 0x9BD, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_BYTES2                                    = UNIT_END + 0x9C1, // Size: 1, Flags: PRIVATE, URGENT_SELF_ONLY
    PLAYER_FIELD_LFG_BONUS_FACTION_ID                      = UNIT_END + 0x9C2, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_LOOT_SPEC_ID                              = UNIT_END + 0x9C3, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_OVERRIDE_ZONE_PVP_TYPE                    = UNIT_END + 0x9C4, // Size: 1, Flags: PRIVATE, URGENT_SELF_ONLY
    PLAYER_FIELD_ITEM_LEVEL_DELTA                          = UNIT_END + 0x9C5, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_BAG_SLOT_FLAGS                            = UNIT_END + 0x9C6, // Size: 4, Flags: PRIVATE
    PLAYER_FIELD_BANK_BAG_SLOT_FLAGS                       = UNIT_END + 0x9CA, // Size: 7, Flags: PRIVATE
    PLAYER_FIELD_INSERT_ITEMS_LEFT_TO_RIGHT                = UNIT_END + 0x9D1, // Size: 1, Flags: PRIVATE
    PLAYER_FIELD_QUEST_COMPLETED                           = UNIT_END + 0x9D2, // Size: 875, Flags: PRIVATE
    PLAYER_END                                             = UNIT_END + 0xD3D,
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
    PLAYER_DYNAMIC_END                                     = UNIT_DYNAMIC_END + 0x007,
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
    DYNAMICOBJECT_BYTES                                    = OBJECT_END + 0x004, // Size: 1, Flags: DYNAMIC
    DYNAMICOBJECT_SPELLID                                  = OBJECT_END + 0x005, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                                   = OBJECT_END + 0x006, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_CASTTIME                                 = OBJECT_END + 0x007, // Size: 1, Flags: PUBLIC
    DYNAMICOBJECT_END                                      = OBJECT_END + 0x008,
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
    CORPSE_END                                             = OBJECT_END + 0x021,
};

enum CorpseDynamicFields
{
    CORPSE_DYNAMIC_END                                     = OBJECT_DYNAMIC_END + 0x000,
};

enum AreaTriggerFields
{
    AREATRIGGER_OVERRIDE_SCALE_CURVE                       = OBJECT_END + 0x000, // Size: 7, Flags: PUBLIC, URGENT
    AREATRIGGER_CASTER                                     = OBJECT_END + 0x007, // Size: 4, Flags: PUBLIC
    AREATRIGGER_DURATION                                   = OBJECT_END + 0x00B, // Size: 1, Flags: PUBLIC
    AREATRIGGER_TIME_TO_TARGET_SCALE                       = OBJECT_END + 0x00C, // Size: 1, Flags: PUBLIC, URGENT
    AREATRIGGER_SPELLID                                    = OBJECT_END + 0x00D, // Size: 1, Flags: PUBLIC
    AREATRIGGER_SPELLVISUALID                              = OBJECT_END + 0x00E, // Size: 1, Flags: DYNAMIC
    AREATRIGGER_BOUNDS_RADIUS_2D                           = OBJECT_END + 0x00F, // Size: 1, Flags: DYNAMIC, URGENT
    AREATRIGGER_EXPLICIT_SCALE                             = OBJECT_END + 0x010, // Size: 1, Flags: PUBLIC, URGENT
    AREATRIGGER_END                                        = OBJECT_END + 0x011,
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
    CONVERSATION_FIELD_DUMMY                               = OBJECT_END + 0x000, // Size: 1, Flags: PRIVATE
    CONVERSATION_END                                       = OBJECT_END + 0x001,
};

enum ConversationDynamicFields
{
    CONVERSATION_DYNAMIC_FIELD_ACTORS                      = OBJECT_DYNAMIC_END + 0x000, // Flags: PUBLIC
    CONVERSATION_DYNAMIC_FIELD_LINES                       = OBJECT_DYNAMIC_END + 0x001, // Flags: 0x100
    CONVERSATION_DYNAMIC_END                               = OBJECT_DYNAMIC_END + 0x002,
};

#endif // _UPDATEFIELDS_H
