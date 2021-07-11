// Auto generated file
// Patch: 1.2.4
// Build: 4222

enum EObjectFields
{
    OBJECT_FIELD_GUID                                = 0x0,                // 0x000 - Size: 2 - Type: GUID - Flags: PUBLIC
    OBJECT_FIELD_TYPE                                = 0x2,                // 0x002 - Size: 1 - Type: INT - Flags: PUBLIC
    OBJECT_FIELD_ENTRY                               = 0x3,                // 0x003 - Size: 1 - Type: INT - Flags: PUBLIC
    OBJECT_FIELD_SCALE_X                             = 0x4,                // 0x004 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    OBJECT_FIELD_PADDING                             = 0x5,                // 0x005 - Size: 1 - Type: INT - Flags: NONE
    OBJECT_END                                       = 0x6                 
};
enum EItemFields
{
    ITEM_FIELD_OWNER                                 = OBJECT_END + 0x0,   // 0x006 - Size: 2 - Type: GUID - Flags: PUBLIC
    ITEM_FIELD_CONTAINED                             = OBJECT_END + 0x2,   // 0x008 - Size: 2 - Type: GUID - Flags: PUBLIC
    ITEM_FIELD_CREATOR                               = OBJECT_END + 0x4,   // 0x00A - Size: 2 - Type: GUID - Flags: PUBLIC
    ITEM_FIELD_GIFTCREATOR                           = OBJECT_END + 0x6,   // 0x00C - Size: 2 - Type: GUID - Flags: PUBLIC
    ITEM_FIELD_STACK_COUNT                           = OBJECT_END + 0x8,   // 0x00E - Size: 1 - Type: INT - Flags: OWNER_ONLY + UNK2
    ITEM_FIELD_DURATION                              = OBJECT_END + 0x9,   // 0x00F - Size: 1 - Type: INT - Flags: OWNER_ONLY + UNK2
    ITEM_FIELD_SPELL_CHARGES                         = OBJECT_END + 0xA,   // 0x010 - Size: 5 - Type: INT - Flags: OWNER_ONLY + UNK2
    ITEM_FIELD_FLAGS                                 = OBJECT_END + 0xF,   // 0x015 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    ITEM_FIELD_ENCHANTMENT                           = OBJECT_END + 0x10,  // 0x016 - Size: 21 - Type: INT - Flags: PUBLIC
    ITEM_FIELD_PROPERTY_SEED                         = OBJECT_END + 0x25,  // 0x02B - Size: 1 - Type: INT - Flags: PUBLIC
    ITEM_FIELD_RANDOM_PROPERTIES_ID                  = OBJECT_END + 0x26,  // 0x02C - Size: 1 - Type: INT - Flags: PUBLIC
    ITEM_FIELD_ITEM_TEXT_ID                          = OBJECT_END + 0x27,  // 0x02D - Size: 1 - Type: INT - Flags: OWNER_ONLY
    ITEM_FIELD_DURABILITY                            = OBJECT_END + 0x28,  // 0x02E - Size: 1 - Type: INT - Flags: OWNER_ONLY + UNK2
    ITEM_FIELD_MAXDURABILITY                         = OBJECT_END + 0x29,  // 0x02F - Size: 1 - Type: INT - Flags: OWNER_ONLY + UNK2
    ITEM_END                                         = OBJECT_END + 0x2A   // 0x030
};
enum EContainerFields
{
    CONTAINER_FIELD_NUM_SLOTS                        = ITEM_END + 0x0,     // 0x02A - Size: 1 - Type: INT - Flags: PUBLIC
    CONTAINER_ALIGN_PAD                              = ITEM_END + 0x1,     // 0x02B - Size: 1 - Type: BYTES - Flags: NONE
    CONTAINER_FIELD_SLOT_1                           = ITEM_END + 0x2,     // 0x02C - Size: 40 - Type: GUID - Flags: PUBLIC
    CONTAINER_END                                    = ITEM_END + 0x2A     // 0x054
};
enum EUnitFields
{
    UNIT_FIELD_CHARM                                 = OBJECT_END + 0x0,   // 0x006 - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_SUMMON                                = OBJECT_END + 0x2,   // 0x008 - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_CHARMEDBY                             = OBJECT_END + 0x4,   // 0x00A - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_SUMMONEDBY                            = OBJECT_END + 0x6,   // 0x00C - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_CREATEDBY                             = OBJECT_END + 0x8,   // 0x00E - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_TARGET                                = OBJECT_END + 0xA,   // 0x010 - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_PERSUADED                             = OBJECT_END + 0xC,   // 0x012 - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_CHANNEL_OBJECT                        = OBJECT_END + 0xE,   // 0x014 - Size: 2 - Type: GUID - Flags: PUBLIC
    UNIT_FIELD_HEALTH                                = OBJECT_END + 0x10,  // 0x016 - Size: 1 - Type: INT - Flags: DYNAMIC
    UNIT_FIELD_POWER1                                = OBJECT_END + 0x11,  // 0x017 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_POWER2                                = OBJECT_END + 0x12,  // 0x018 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_POWER3                                = OBJECT_END + 0x13,  // 0x019 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_POWER4                                = OBJECT_END + 0x14,  // 0x01A - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_POWER5                                = OBJECT_END + 0x15,  // 0x01B - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MAXHEALTH                             = OBJECT_END + 0x16,  // 0x01C - Size: 1 - Type: INT - Flags: DYNAMIC
    UNIT_FIELD_MAXPOWER1                             = OBJECT_END + 0x17,  // 0x01D - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MAXPOWER2                             = OBJECT_END + 0x18,  // 0x01E - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MAXPOWER3                             = OBJECT_END + 0x19,  // 0x01F - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MAXPOWER4                             = OBJECT_END + 0x1A,  // 0x020 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MAXPOWER5                             = OBJECT_END + 0x1B,  // 0x021 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_LEVEL                                 = OBJECT_END + 0x1C,  // 0x022 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_FACTIONTEMPLATE                       = OBJECT_END + 0x1D,  // 0x023 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_BYTES_0                               = OBJECT_END + 0x1E,  // 0x024 - Size: 1 - Type: BYTES - Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_SLOT_DISPLAY                   = OBJECT_END + 0x1F,  // 0x025 - Size: 3 - Type: INT - Flags: PUBLIC
    UNIT_VIRTUAL_ITEM_INFO                           = OBJECT_END + 0x22,  // 0x028 - Size: 6 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_FLAGS                                 = OBJECT_END + 0x28,  // 0x02E - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_AURA                                  = OBJECT_END + 0x29,  // 0x02F - Size: 56 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_AURALEVELS                            = OBJECT_END + 0x61,  // 0x067 - Size: 10 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_AURAAPPLICATIONS                      = OBJECT_END + 0x6B,  // 0x071 - Size: 10 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_AURAFLAGS                             = OBJECT_END + 0x75,  // 0x07B - Size: 7 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_AURASTATE                             = OBJECT_END + 0x7C,  // 0x082 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_BASEATTACKTIME                        = OBJECT_END + 0x7D,  // 0x083 - Size: 2 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_RANGEDATTACKTIME                      = OBJECT_END + 0x7F,  // 0x085 - Size: 1 - Type: INT - Flags: PRIVATE
    UNIT_FIELD_BOUNDINGRADIUS                        = OBJECT_END + 0x80,  // 0x086 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    UNIT_FIELD_COMBATREACH                           = OBJECT_END + 0x81,  // 0x087 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    UNIT_FIELD_DISPLAYID                             = OBJECT_END + 0x82,  // 0x088 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_NATIVEDISPLAYID                       = OBJECT_END + 0x83,  // 0x089 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MOUNTDISPLAYID                        = OBJECT_END + 0x84,  // 0x08A - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_MINDAMAGE                             = OBJECT_END + 0x85,  // 0x08B - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY + SPECIAL_INFO
    UNIT_FIELD_MAXDAMAGE                             = OBJECT_END + 0x86,  // 0x08C - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY + SPECIAL_INFO
    UNIT_FIELD_MINOFFHANDDAMAGE                      = OBJECT_END + 0x87,  // 0x08D - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY + SPECIAL_INFO
    UNIT_FIELD_MAXOFFHANDDAMAGE                      = OBJECT_END + 0x88,  // 0x08E - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY + SPECIAL_INFO
    UNIT_FIELD_BYTES_1                               = OBJECT_END + 0x89,  // 0x08F - Size: 1 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_PETNUMBER                             = OBJECT_END + 0x8A,  // 0x090 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_PET_NAME_TIMESTAMP                    = OBJECT_END + 0x8B,  // 0x091 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_FIELD_PETEXPERIENCE                         = OBJECT_END + 0x8C,  // 0x092 - Size: 1 - Type: INT - Flags: OWNER_ONLY
    UNIT_FIELD_PETNEXTLEVELEXP                       = OBJECT_END + 0x8D,  // 0x093 - Size: 1 - Type: INT - Flags: OWNER_ONLY
    UNIT_DYNAMIC_FLAGS                               = OBJECT_END + 0x8E,  // 0x094 - Size: 1 - Type: INT - Flags: DYNAMIC
    UNIT_CHANNEL_SPELL                               = OBJECT_END + 0x8F,  // 0x095 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_MOD_CAST_SPEED                              = OBJECT_END + 0x90,  // 0x096 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_CREATED_BY_SPELL                            = OBJECT_END + 0x91,  // 0x097 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_NPC_FLAGS                                   = OBJECT_END + 0x92,  // 0x098 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_NPC_EMOTESTATE                              = OBJECT_END + 0x93,  // 0x099 - Size: 1 - Type: INT - Flags: PUBLIC
    UNIT_TRAINING_POINTS                             = OBJECT_END + 0x94,  // 0x09A - Size: 1 - Type: TWO_SHORT - Flags: OWNER_ONLY
    UNIT_FIELD_STAT0                                 = OBJECT_END + 0x95,  // 0x09B - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_STAT1                                 = OBJECT_END + 0x96,  // 0x09C - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_STAT2                                 = OBJECT_END + 0x97,  // 0x09D - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_STAT3                                 = OBJECT_END + 0x98,  // 0x09E - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_STAT4                                 = OBJECT_END + 0x99,  // 0x09F - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_RESISTANCES                           = OBJECT_END + 0x9A,  // 0x0A0 - Size: 7 - Type: INT - Flags: PRIVATE + OWNER_ONLY + SPECIAL_INFO
    UNIT_FIELD_ATTACK_POWER                          = OBJECT_END + 0xA1,  // 0x0A7 - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_BASE_MANA                             = OBJECT_END + 0xA2,  // 0x0A8 - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_ATTACK_POWER_MODS                     = OBJECT_END + 0xA3,  // 0x0A9 - Size: 1 - Type: TWO_SHORT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_BYTES_2                               = OBJECT_END + 0xA4,  // 0x0AA - Size: 1 - Type: BYTES - Flags: PUBLIC
    UNIT_FIELD_RANGED_ATTACK_POWER                   = OBJECT_END + 0xA5,  // 0x0AB - Size: 1 - Type: INT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_RANGED_ATTACK_POWER_MODS              = OBJECT_END + 0xA6,  // 0x0AC - Size: 1 - Type: TWO_SHORT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_MINRANGEDDAMAGE                       = OBJECT_END + 0xA7,  // 0x0AD - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_MAXRANGEDDAMAGE                       = OBJECT_END + 0xA8,  // 0x0AE - Size: 1 - Type: FLOAT - Flags: PRIVATE + OWNER_ONLY
    UNIT_FIELD_PADDING                               = OBJECT_END + 0xA9,  // 0x0AF - Size: 1 - Type: INT - Flags: NONE
    UNIT_END                                         = OBJECT_END + 0xAA   // 0x0B0
};
enum EPlayerFields
{
    PLAYER_SELECTION                                 = UNIT_END + 0x0,     // 0x0AA - Size: 2 - Type: GUID - Flags: PUBLIC
    PLAYER_DUEL_ARBITER                              = UNIT_END + 0x2,     // 0x0AC - Size: 2 - Type: GUID - Flags: PUBLIC
    PLAYER_FLAGS                                     = UNIT_END + 0x4,     // 0x0AE - Size: 1 - Type: INT - Flags: PUBLIC
    PLAYER_GUILDID                                   = UNIT_END + 0x5,     // 0x0AF - Size: 1 - Type: INT - Flags: PUBLIC
    PLAYER_GUILDRANK                                 = UNIT_END + 0x6,     // 0x0B0 - Size: 1 - Type: INT - Flags: PUBLIC
    PLAYER_BYTES                                     = UNIT_END + 0x7,     // 0x0B1 - Size: 1 - Type: BYTES - Flags: PUBLIC
    PLAYER_BYTES_2                                   = UNIT_END + 0x8,     // 0x0B2 - Size: 1 - Type: BYTES - Flags: PUBLIC
    PLAYER_BYTES_3                                   = UNIT_END + 0x9,     // 0x0B3 - Size: 1 - Type: BYTES - Flags: PUBLIC
    PLAYER_DUEL_TEAM                                 = UNIT_END + 0xA,     // 0x0B4 - Size: 1 - Type: INT - Flags: PUBLIC
    PLAYER_GUILD_TIMESTAMP                           = UNIT_END + 0xB,     // 0x0B5 - Size: 1 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_0                          = UNIT_END + 0xC,     // 0x0B6 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_1_PROPERTIES                 = UNIT_END + 0x14,    // 0x0BE - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_0                          = UNIT_END + 0x15,    // 0x0BF - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_2_PROPERTIES                 = UNIT_END + 0x1D,    // 0x0C7 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_0                          = UNIT_END + 0x1E,    // 0x0C8 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_3_PROPERTIES                 = UNIT_END + 0x26,    // 0x0D0 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_0                          = UNIT_END + 0x27,    // 0x0D1 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_4_PROPERTIES                 = UNIT_END + 0x2F,    // 0x0D9 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_0                          = UNIT_END + 0x30,    // 0x0DA - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_5_PROPERTIES                 = UNIT_END + 0x38,    // 0x0E2 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_0                          = UNIT_END + 0x39,    // 0x0E3 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_6_PROPERTIES                 = UNIT_END + 0x41,    // 0x0EB - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_0                          = UNIT_END + 0x42,    // 0x0EC - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_7_PROPERTIES                 = UNIT_END + 0x4A,    // 0x0F4 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_0                          = UNIT_END + 0x4B,    // 0x0F5 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_8_PROPERTIES                 = UNIT_END + 0x53,    // 0x0FD - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_0                          = UNIT_END + 0x54,    // 0x0FE - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_9_PROPERTIES                 = UNIT_END + 0x5C,    // 0x106 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_0                         = UNIT_END + 0x5D,    // 0x107 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_10_PROPERTIES                = UNIT_END + 0x65,    // 0x10F - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_0                         = UNIT_END + 0x66,    // 0x110 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_11_PROPERTIES                = UNIT_END + 0x6E,    // 0x118 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_0                         = UNIT_END + 0x6F,    // 0x119 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_12_PROPERTIES                = UNIT_END + 0x77,    // 0x121 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_0                         = UNIT_END + 0x78,    // 0x122 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_13_PROPERTIES                = UNIT_END + 0x80,    // 0x12A - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_0                         = UNIT_END + 0x81,    // 0x12B - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_14_PROPERTIES                = UNIT_END + 0x89,    // 0x133 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_0                         = UNIT_END + 0x8A,    // 0x134 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_15_PROPERTIES                = UNIT_END + 0x92,    // 0x13C - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_0                         = UNIT_END + 0x93,    // 0x13D - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_16_PROPERTIES                = UNIT_END + 0x9B,    // 0x145 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_0                         = UNIT_END + 0x9C,    // 0x146 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_17_PROPERTIES                = UNIT_END + 0xA4,    // 0x14E - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_0                         = UNIT_END + 0xA5,    // 0x14F - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_18_PROPERTIES                = UNIT_END + 0xAD,    // 0x157 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_0                         = UNIT_END + 0xAE,    // 0x158 - Size: 8 - Type: INT - Flags: PUBLIC
    PLAYER_VISIBLE_ITEM_19_PROPERTIES                = UNIT_END + 0xB6,    // 0x160 - Size: 1 - Type: TWO_SHORT - Flags: PUBLIC
    PLAYER_FIELD_PAD_0                               = UNIT_END + 0xB7,    // 0x161 - Size: 1 - Type: INT - Flags: NONE
    PLAYER_FIELD_INV_SLOT_HEAD                       = UNIT_END + 0xB8,    // 0x162 - Size: 46 - Type: GUID - Flags: PUBLIC
    PLAYER_FIELD_PACK_SLOT_1                         = UNIT_END + 0xE6,    // 0x190 - Size: 32 - Type: GUID - Flags: PRIVATE
    PLAYER_FIELD_BANK_SLOT_1                         = UNIT_END + 0x106,   // 0x1B0 - Size: 48 - Type: GUID - Flags: PRIVATE
    PLAYER_FIELD_BANKBAG_SLOT_1                      = UNIT_END + 0x136,   // 0x1E0 - Size: 12 - Type: GUID - Flags: PRIVATE
    PLAYER_FIELD_VENDORBUYBACK_SLOT                  = UNIT_END + 0x142,   // 0x1EC - Size: 2 - Type: GUID - Flags: PRIVATE
    PLAYER_FARSIGHT                                  = UNIT_END + 0x144,   // 0x1EE - Size: 2 - Type: GUID - Flags: PRIVATE
    PLAYER_FIELD_COMBO_TARGET                        = UNIT_END + 0x146,   // 0x1F0 - Size: 2 - Type: GUID - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_NPC                         = UNIT_END + 0x148,   // 0x1F2 - Size: 2 - Type: GUID - Flags: PRIVATE
    PLAYER_XP                                        = UNIT_END + 0x14A,   // 0x1F4 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_NEXT_LEVEL_XP                             = UNIT_END + 0x14B,   // 0x1F5 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_SKILL_INFO_1_1                            = UNIT_END + 0x14C,   // 0x1F6 - Size: 384 - Type: TWO_SHORT - Flags: PRIVATE
    PLAYER_QUEST_LOG_1_1                             = UNIT_END + 0x2CC,   // 0x376 - Size: 60 - Type: INT - Flags: PRIVATE
    PLAYER_CHARACTER_POINTS1                         = UNIT_END + 0x308,   // 0x3B2 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_CHARACTER_POINTS2                         = UNIT_END + 0x309,   // 0x3B3 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_TRACK_CREATURES                           = UNIT_END + 0x30A,   // 0x3B4 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_TRACK_RESOURCES                           = UNIT_END + 0x30B,   // 0x3B5 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_CHAT_FILTERS                              = UNIT_END + 0x30C,   // 0x3B6 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_BLOCK_PERCENTAGE                          = UNIT_END + 0x30D,   // 0x3B7 - Size: 1 - Type: FLOAT - Flags: PRIVATE
    PLAYER_DODGE_PERCENTAGE                          = UNIT_END + 0x30E,   // 0x3B8 - Size: 1 - Type: FLOAT - Flags: PRIVATE
    PLAYER_PARRY_PERCENTAGE                          = UNIT_END + 0x30F,   // 0x3B9 - Size: 1 - Type: FLOAT - Flags: PRIVATE
    PLAYER_CRIT_PERCENTAGE                           = UNIT_END + 0x310,   // 0x3BA - Size: 1 - Type: FLOAT - Flags: PRIVATE
    PLAYER_EXPLORED_ZONES_1                          = UNIT_END + 0x311,   // 0x3BB - Size: 32 - Type: BYTES - Flags: PRIVATE
    PLAYER_REST_STATE_EXPERIENCE                     = UNIT_END + 0x331,   // 0x3DB - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_COINAGE                             = UNIT_END + 0x332,   // 0x3DC - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_POSSTAT0                            = UNIT_END + 0x333,   // 0x3DD - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_POSSTAT1                            = UNIT_END + 0x334,   // 0x3DE - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_POSSTAT2                            = UNIT_END + 0x335,   // 0x3DF - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_POSSTAT3                            = UNIT_END + 0x336,   // 0x3E0 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_POSSTAT4                            = UNIT_END + 0x337,   // 0x3E1 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_NEGSTAT0                            = UNIT_END + 0x338,   // 0x3E2 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_NEGSTAT1                            = UNIT_END + 0x339,   // 0x3E3 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_NEGSTAT2                            = UNIT_END + 0x33A,   // 0x3E4 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_NEGSTAT3                            = UNIT_END + 0x33B,   // 0x3E5 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_NEGSTAT4                            = UNIT_END + 0x33C,   // 0x3E6 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE          = UNIT_END + 0x33D,   // 0x3E7 - Size: 7 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE          = UNIT_END + 0x344,   // 0x3EE - Size: 7 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_POS                 = UNIT_END + 0x34B,   // 0x3F5 - Size: 7 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_NEG                 = UNIT_END + 0x352,   // 0x3FC - Size: 7 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_MOD_DAMAGE_DONE_PCT                 = UNIT_END + 0x359,   // 0x403 - Size: 7 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BYTES                               = UNIT_END + 0x360,   // 0x40A - Size: 1 - Type: BYTES - Flags: PRIVATE
    PLAYER_AMMO_ID                                   = UNIT_END + 0x361,   // 0x40B - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_PVP_MEDALS                          = UNIT_END + 0x362,   // 0x40C - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_ITEM_ID                     = UNIT_END + 0x363,   // 0x40D - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_RANDOM_PROPERTIES_ID        = UNIT_END + 0x364,   // 0x40E - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_SEED                        = UNIT_END + 0x365,   // 0x40F - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_PRICE                       = UNIT_END + 0x366,   // 0x410 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_DURABILITY                  = UNIT_END + 0x367,   // 0x411 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_BUYBACK_COUNT                       = UNIT_END + 0x368,   // 0x412 - Size: 1 - Type: INT - Flags: PRIVATE
    PLAYER_FIELD_PADDING                             = UNIT_END + 0x369,   // 0x413 - Size: 1 - Type: INT - Flags: NONE
    PLAYER_END                                       = UNIT_END + 0x36A    // 0x414
};
enum EGameObjectFields
{
    GAMEOBJECT_DISPLAYID                             = OBJECT_END + 0x0,   // 0x006 - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_FLAGS                                 = OBJECT_END + 0x1,   // 0x007 - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_ROTATION                              = OBJECT_END + 0x2,   // 0x008 - Size: 4 - Type: FLOAT - Flags: PUBLIC
    GAMEOBJECT_STATE                                 = OBJECT_END + 0x6,   // 0x00C - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_TIMESTAMP                             = OBJECT_END + 0x7,   // 0x00D - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_POS_X                                 = OBJECT_END + 0x8,   // 0x00E - Size: 1 - Type: FLOAT - Flags: PUBLIC
    GAMEOBJECT_POS_Y                                 = OBJECT_END + 0x9,   // 0x00F - Size: 1 - Type: FLOAT - Flags: PUBLIC
    GAMEOBJECT_POS_Z                                 = OBJECT_END + 0xA,   // 0x010 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    GAMEOBJECT_FACING                                = OBJECT_END + 0xB,   // 0x011 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    GAMEOBJECT_DYN_FLAGS                             = OBJECT_END + 0xC,   // 0x012 - Size: 1 - Type: INT - Flags: DYNAMIC
    GAMEOBJECT_FACTION                               = OBJECT_END + 0xD,   // 0x013 - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_TYPE_ID                               = OBJECT_END + 0xE,   // 0x014 - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_LEVEL                                 = OBJECT_END + 0xF,   // 0x015 - Size: 1 - Type: INT - Flags: PUBLIC
    GAMEOBJECT_END                                   = OBJECT_END + 0x10   // 0x016
};
enum EDynamicObjectFields
{
    DYNAMICOBJECT_CASTER                             = OBJECT_END + 0x0,   // 0x006 - Size: 2 - Type: GUID - Flags: PUBLIC
    DYNAMICOBJECT_BYTES                              = OBJECT_END + 0x2,   // 0x008 - Size: 1 - Type: BYTES - Flags: PUBLIC
    DYNAMICOBJECT_SPELLID                            = OBJECT_END + 0x3,   // 0x009 - Size: 1 - Type: INT - Flags: PUBLIC
    DYNAMICOBJECT_RADIUS                             = OBJECT_END + 0x4,   // 0x00A - Size: 1 - Type: FLOAT - Flags: PUBLIC
    DYNAMICOBJECT_POS_X                              = OBJECT_END + 0x5,   // 0x00B - Size: 1 - Type: FLOAT - Flags: PUBLIC
    DYNAMICOBJECT_POS_Y                              = OBJECT_END + 0x6,   // 0x00C - Size: 1 - Type: FLOAT - Flags: PUBLIC
    DYNAMICOBJECT_POS_Z                              = OBJECT_END + 0x7,   // 0x00D - Size: 1 - Type: FLOAT - Flags: PUBLIC
    DYNAMICOBJECT_FACING                             = OBJECT_END + 0x8,   // 0x00E - Size: 1 - Type: FLOAT - Flags: PUBLIC
    DYNAMICOBJECT_PAD                                = OBJECT_END + 0x9,   // 0x00F - Size: 1 - Type: BYTES - Flags: PUBLIC
    DYNAMICOBJECT_END                                = OBJECT_END + 0xA    // 0x010
};
enum ECorpseFields
{
    CORPSE_FIELD_OWNER                               = OBJECT_END + 0x0,   // 0x006 - Size: 2 - Type: GUID - Flags: PUBLIC
    CORPSE_FIELD_FACING                              = OBJECT_END + 0x2,   // 0x008 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    CORPSE_FIELD_POS_X                               = OBJECT_END + 0x3,   // 0x009 - Size: 1 - Type: FLOAT - Flags: PUBLIC
    CORPSE_FIELD_POS_Y                               = OBJECT_END + 0x4,   // 0x00A - Size: 1 - Type: FLOAT - Flags: PUBLIC
    CORPSE_FIELD_POS_Z                               = OBJECT_END + 0x5,   // 0x00B - Size: 1 - Type: FLOAT - Flags: PUBLIC
    CORPSE_FIELD_DISPLAY_ID                          = OBJECT_END + 0x6,   // 0x00C - Size: 1 - Type: INT - Flags: PUBLIC
    CORPSE_FIELD_ITEM                                = OBJECT_END + 0x7,   // 0x00D - Size: 19 - Type: INT - Flags: PUBLIC
    CORPSE_FIELD_BYTES_1                             = OBJECT_END + 0x1A,  // 0x020 - Size: 1 - Type: BYTES - Flags: PUBLIC
    CORPSE_FIELD_BYTES_2                             = OBJECT_END + 0x1B,  // 0x021 - Size: 1 - Type: BYTES - Flags: PUBLIC
    CORPSE_FIELD_GUILD                               = OBJECT_END + 0x1C,  // 0x022 - Size: 1 - Type: INT - Flags: PUBLIC
    CORPSE_FIELD_FLAGS                               = OBJECT_END + 0x1D,  // 0x023 - Size: 1 - Type: INT - Flags: PUBLIC
    CORPSE_END                                       = OBJECT_END + 0x1E   // 0x024
};
