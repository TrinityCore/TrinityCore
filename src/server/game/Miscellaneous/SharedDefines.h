/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITY_SHAREDDEFINES_H
#define TRINITY_SHAREDDEFINES_H

#include "Define.h"
#include "EnumFlag.h"
#include <compare>

float const GROUND_HEIGHT_TOLERANCE = 0.05f; // Extra tolerance to z position to check if it is in air or on ground.
constexpr float Z_OFFSET_FIND_HEIGHT = 0.5f;

enum SpellEffIndex : uint8
{
    EFFECT_0 = 0,
    EFFECT_1 = 1,
    EFFECT_2 = 2,
    EFFECT_3 = 3,
    EFFECT_4 = 4,
    EFFECT_5 = 5,
    EFFECT_6 = 6,
    EFFECT_7 = 7,
    EFFECT_8 = 8,
    EFFECT_9 = 9,
    EFFECT_10 = 10,
    EFFECT_11 = 11,
    EFFECT_12 = 12,
    EFFECT_13 = 13,
    EFFECT_14 = 14,
    EFFECT_15 = 15,
    EFFECT_16 = 16,
    EFFECT_17 = 17,
    EFFECT_18 = 18,
    EFFECT_19 = 19,
    EFFECT_20 = 20,
    EFFECT_21 = 21,
    EFFECT_22 = 22,
    EFFECT_23 = 23,
    EFFECT_24 = 24,
    EFFECT_25 = 25,
    EFFECT_26 = 26,
    EFFECT_27 = 27,
    EFFECT_28 = 28,
    EFFECT_29 = 29,
    EFFECT_30 = 30,
    EFFECT_31 = 31
};

enum class SpellTargetIndex : uint8
{
    TargetA = 0,
    TargetB = 1
};

// used in script definitions
#define EFFECT_FIRST_FOUND 254
#define EFFECT_ALL 255

// loot modes for creatures and gameobjects, bitmask!
enum LootModes
{
    LOOT_MODE_DEFAULT                  = 0x1,
    LOOT_MODE_HARD_MODE_1              = 0x2,
    LOOT_MODE_HARD_MODE_2              = 0x4,
    LOOT_MODE_HARD_MODE_3              = 0x8,
    LOOT_MODE_HARD_MODE_4              = 0x10,
    LOOT_MODE_JUNK_FISH                = 0x8000
};

#define MAX_CHARACTERS_PER_REALM 200

enum Expansions
{
    EXPANSION_LEVEL_CURRENT            = -1,
    EXPANSION_CLASSIC                  = 0,
    EXPANSION_THE_BURNING_CRUSADE      = 1,
    EXPANSION_WRATH_OF_THE_LICH_KING   = 2,
    EXPANSION_CATACLYSM                = 3,
    EXPANSION_MISTS_OF_PANDARIA        = 4,
    EXPANSION_WARLORDS_OF_DRAENOR      = 5,
    EXPANSION_LEGION                   = 6,
    EXPANSION_BATTLE_FOR_AZEROTH       = 7,
    EXPANSION_SHADOWLANDS              = 8,
    EXPANSION_DRAGONFLIGHT             = 9,
    MAX_EXPANSIONS,
    EXPANSION_THE_WAR_WITHIN           = 10,

    MAX_ACCOUNT_EXPANSIONS
};

#define CURRENT_EXPANSION EXPANSION_DRAGONFLIGHT

constexpr uint32 GetMaxLevelForExpansion(uint32 expansion)
{
    switch (expansion)
    {
        case EXPANSION_CLASSIC:
            return 30;
        case EXPANSION_THE_BURNING_CRUSADE:
            return 30;
        case EXPANSION_WRATH_OF_THE_LICH_KING:
            return 30;
        case EXPANSION_CATACLYSM:
            return 35;
        case EXPANSION_MISTS_OF_PANDARIA:
            return 35;
        case EXPANSION_WARLORDS_OF_DRAENOR:
            return 40;
        case EXPANSION_LEGION:
            return 45;
        case EXPANSION_BATTLE_FOR_AZEROTH:
            return 50;
        case EXPANSION_SHADOWLANDS:
            return 60;
        case EXPANSION_DRAGONFLIGHT:
            return 70;
        case EXPANSION_THE_WAR_WITHIN:
            return 80;
        default:
            break;
    }
    return 0;
}

enum Gender
{
    GENDER_UNKNOWN                     = -1,
    GENDER_MALE                        =  0,
    GENDER_FEMALE                      =  1,
    GENDER_NONE                        =  2
};

// Class value is index in ChrClasses.db2
// EnumUtils: DESCRIBE THIS
enum Classes : uint8
{
    CLASS_NONE          = 0,  // SKIP
    CLASS_WARRIOR       = 1,  // TITLE Warrior
    CLASS_PALADIN       = 2,  // TITLE Paladin
    CLASS_HUNTER        = 3,  // TITLE Hunter
    CLASS_ROGUE         = 4,  // TITLE Rogue
    CLASS_PRIEST        = 5,  // TITLE Priest
    CLASS_DEATH_KNIGHT  = 6,  // TITLE Death Knight
    CLASS_SHAMAN        = 7,  // TITLE Shaman
    CLASS_MAGE          = 8,  // TITLE Mage
    CLASS_WARLOCK       = 9,  // TITLE Warlock
    CLASS_MONK          = 10, // TITLE Monk
    CLASS_DRUID         = 11, // TITLE Druid
    CLASS_DEMON_HUNTER  = 12, // TITLE Demon Hunter
    CLASS_EVOKER        = 13, // TITLE Evoker
    CLASS_ADVENTURER    = 14  // TITLE Adventurer
};

// max+1 for player class
#define MAX_CLASSES       15

#define CLASSMASK_ALL_PLAYABLE     \
    ((1<<(CLASS_WARRIOR-1))      | \
     (1<<(CLASS_PALADIN-1))      | \
     (1<<(CLASS_HUNTER-1))       | \
     (1<<(CLASS_ROGUE-1))        | \
     (1<<(CLASS_PRIEST-1))       | \
     (1<<(CLASS_DEATH_KNIGHT-1)) | \
     (1<<(CLASS_SHAMAN-1))       | \
     (1<<(CLASS_MAGE-1))         | \
     (1<<(CLASS_WARLOCK-1))      | \
     (1<<(CLASS_MONK-1))         | \
     (1<<(CLASS_DRUID-1))        | \
     (1<<(CLASS_DEMON_HUNTER-1)) | \
     (1<<(CLASS_EVOKER-1)))

// valid classes for creature_template.unit_class
enum UnitClass
{
    UNIT_CLASS_WARRIOR                  = 1,
    UNIT_CLASS_PALADIN                  = 2,
    UNIT_CLASS_ROGUE                    = 4,
    UNIT_CLASS_MAGE                     = 8
};

static constexpr uint8 MAX_UNIT_CLASSES = 4;

#define CLASSMASK_ALL_CREATURES ((1<<(UNIT_CLASS_WARRIOR-1)) | (1<<(UNIT_CLASS_PALADIN-1)) | (1<<(UNIT_CLASS_ROGUE-1)) | (1<<(UNIT_CLASS_MAGE-1)))

#define CLASSMASK_WAND_USERS ((1<<(CLASS_PRIEST-1)) | (1<<(CLASS_MAGE-1)) | (1<<(CLASS_WARLOCK-1)))

static constexpr uint8 PLAYER_MAX_BATTLEGROUND_QUEUES = 3;

enum ReputationRank
{
    REP_HATED       = 0,
    REP_HOSTILE     = 1,
    REP_UNFRIENDLY  = 2,
    REP_NEUTRAL     = 3,
    REP_FRIENDLY    = 4,
    REP_HONORED     = 5,
    REP_REVERED     = 6,
    REP_EXALTED     = 7
};

enum FactionTemplates
{
    FACTION_NONE                        = 0,
    FACTION_CREATURE                    = 7,
    FACTION_ESCORTEE_A_NEUTRAL_PASSIVE  = 10,
    FACTION_MONSTER                     = 14,
    FACTION_MONSTER_2                   = 16,
    FACTION_TROLL_BLOODSCALP            = 28,
    FACTION_PREY                        = 31,
    FACTION_ESCORTEE_H_NEUTRAL_PASSIVE  = 33,
    FACTION_FRIENDLY                    = 35,
    FACTION_TROLL_FROSTMANE             = 37,
    FACTION_OGRE                        = 45,
    FACTION_ORC_DRAGONMAW               = 62,
    FACTION_HORDE_GENERIC               = 83,
    FACTION_ALLIANCE_GENERIC            = 84,
    FACTION_DEMON                       = 90,
    FACTION_ELEMENTAL                   = 91,
    FACTION_DRAGONFLIGHT_BLACK          = 103,
    FACTION_ESCORTEE_N_NEUTRAL_PASSIVE  = 113,
    FACTION_ENEMY                       = 168,
    FACTION_ESCORTEE_A_NEUTRAL_ACTIVE   = 231,
    FACTION_ESCORTEE_H_NEUTRAL_ACTIVE   = 232,
    FACTION_ESCORTEE_N_NEUTRAL_ACTIVE   = 250,
    FACTION_ESCORTEE_N_FRIEND_PASSIVE   = 290,
    FACTION_TITAN                       = 415,
    FACTION_ESCORTEE_N_FRIEND_ACTIVE    = 495,
    FACTION_RATCHET                     = 637,
    FACTION_GOBLIN_DARK_IRON_BAR_PATRON = 736,
    FACTION_DARK_IRON_DWARVES           = 754,
    FACTION_ESCORTEE_A_PASSIVE          = 774,
    FACTION_ESCORTEE_H_PASSIVE          = 775,
    FACTION_UNDEAD_SCOURGE              = 974,
    FACTION_EARTHEN_RING                = 1726,
    FACTION_ALLIANCE_GENERIC_WG         = 1732,
    FACTION_HORDE_GENERIC_WG            = 1735,
    FACTION_ARAKKOA                     = 1738,
    FACTION_ASHTONGUE_DEATHSWORN        = 1820,
    FACTION_FLAYER_HUNTER               = 1840,
    FACTION_MONSTER_SPAR_BUDDY          = 1868,
    FACTION_ESCORTEE_N_ACTIVE           = 1986,
    FACTION_ESCORTEE_H_ACTIVE           = 2046,
    FACTION_UNDEAD_SCOURGE_2            = 2068,
    FACTION_UNDEAD_SCOURGE_3            = 2084,
    FACTION_SCARLET_CRUSADE             = 2089,
    FACTION_SCARLET_CRUSADE_2           = 2096
};

#define MIN_REPUTATION_RANK (REP_HATED)
#define MAX_REPUTATION_RANK 8

#define MAX_SPILLOVER_FACTIONS 5

enum MoneyConstants
{
    COPPER = 1,
    SILVER = COPPER*100,
    GOLD   = SILVER*100
};

enum Stats : uint16
{
    STAT_STRENGTH                      = 0,
    STAT_AGILITY                       = 1,
    STAT_STAMINA                       = 2,
    STAT_INTELLECT                     = 3,
};

#define MAX_STATS                        4

// EnumUtils: DESCRIBE THIS
enum Powers : int8
{
    POWER_HEALTH                        = -2, // TITLE Health
    POWER_MANA                          = 0,  // TITLE Mana
    POWER_RAGE                          = 1,  // TITLE Rage
    POWER_FOCUS                         = 2,  // TITLE Focus
    POWER_ENERGY                        = 3,  // TITLE Energy
    POWER_COMBO_POINTS                  = 4,  // TITLE Combo Points
    POWER_RUNES                         = 5,  // TITLE Runes
    POWER_RUNIC_POWER                   = 6,  // TITLE Runic Power
    POWER_SOUL_SHARDS                   = 7,  // TITLE Soul Shards
    POWER_LUNAR_POWER                   = 8,  // TITLE Lunar Power
    POWER_HOLY_POWER                    = 9,  // TITLE Holy Power
    POWER_ALTERNATE_POWER               = 10, // TITLE Alternate
    POWER_MAELSTROM                     = 11, // TITLE Maelstrom
    POWER_CHI                           = 12, // TITLE Chi
    POWER_INSANITY                      = 13, // TITLE Insanity
    POWER_BURNING_EMBERS                = 14, // TITLE Burning Embers (Obsolete)
    POWER_DEMONIC_FURY                  = 15, // TITLE Demonic Fury (Obsolete)
    POWER_ARCANE_CHARGES                = 16, // TITLE Arcane Charges
    POWER_FURY                          = 17, // TITLE Fury
    POWER_PAIN                          = 18, // TITLE Pain
    POWER_ESSENCE                       = 19, // TITLE Essence
    POWER_RUNE_BLOOD                    = 20, // TITLE Blood Runes
    POWER_RUNE_FROST                    = 21, // TITLE Frost Runes
    POWER_RUNE_UNHOLY                   = 22, // TITLE Unholy Runes
    POWER_ALTERNATE_QUEST               = 23, // TITLE Alternate (Quest)
    POWER_ALTERNATE_ENCOUNTER           = 24, // TITLE Alternate (Encounter)
    POWER_ALTERNATE_MOUNT               = 25, // TITLE Alternate (Mount)
    MAX_POWERS                          = 26, // SKIP
    POWER_ALL                           = 127 // SKIP
};

#define MAX_POWERS_PER_CLASS            10

// EnumUtils: DESCRIBE THIS
enum SpellSchools : uint16
{
    SPELL_SCHOOL_NORMAL                 = 0, // TITLE Physical
    SPELL_SCHOOL_HOLY                   = 1, // TITLE Holy
    SPELL_SCHOOL_FIRE                   = 2, // TITLE Fire
    SPELL_SCHOOL_NATURE                 = 3, // TITLE Nature
    SPELL_SCHOOL_FROST                  = 4, // TITLE Frost
    SPELL_SCHOOL_SHADOW                 = 5, // TITLE Shadow
    SPELL_SCHOOL_ARCANE                 = 6, // TITLE Arcane
    MAX_SPELL_SCHOOL                    = 7  // SKIP
};

enum SpellSchoolMask : uint32
{
    SPELL_SCHOOL_MASK_NONE    = 0x00,                       // not exist
    SPELL_SCHOOL_MASK_NORMAL  = (1 << SPELL_SCHOOL_NORMAL), // PHYSICAL (Armor)
    SPELL_SCHOOL_MASK_HOLY    = (1 << SPELL_SCHOOL_HOLY),
    SPELL_SCHOOL_MASK_FIRE    = (1 << SPELL_SCHOOL_FIRE),
    SPELL_SCHOOL_MASK_NATURE  = (1 << SPELL_SCHOOL_NATURE),
    SPELL_SCHOOL_MASK_FROST   = (1 << SPELL_SCHOOL_FROST),
    SPELL_SCHOOL_MASK_SHADOW  = (1 << SPELL_SCHOOL_SHADOW),
    SPELL_SCHOOL_MASK_ARCANE  = (1 << SPELL_SCHOOL_ARCANE),

    // unions

    // 124, not include normal and holy damage
    SPELL_SCHOOL_MASK_SPELL   = (SPELL_SCHOOL_MASK_FIRE   |
                                  SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_FROST  |
                                  SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE),
    // 126
    SPELL_SCHOOL_MASK_MAGIC   = (SPELL_SCHOOL_MASK_HOLY | SPELL_SCHOOL_MASK_SPELL),

    // 127
    SPELL_SCHOOL_MASK_ALL     = (SPELL_SCHOOL_MASK_NORMAL | SPELL_SCHOOL_MASK_MAGIC)
};

constexpr SpellSchoolMask GetMaskForSchool(SpellSchools school)
{
    return SpellSchoolMask(1 << school);
}

inline SpellSchools GetFirstSchoolInMask(SpellSchoolMask mask)
{
    // Do not use EnumUtils to iterate
    // this can cause some compilers to instantiate Trinity::Impl::EnumUtils<SpellSchools>
    // when compiling enuminfo_SharedDefines before their explicit specializations in that file
    for (uint16 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (mask & (1 << i))
            return SpellSchools(i);

    return SPELL_SCHOOL_NORMAL;
}

enum ItemQualities
{
    ITEM_QUALITY_POOR                  = 0, // GREY
    ITEM_QUALITY_NORMAL                = 1, // WHITE
    ITEM_QUALITY_UNCOMMON              = 2, // GREEN
    ITEM_QUALITY_RARE                  = 3, // BLUE
    ITEM_QUALITY_EPIC                  = 4, // PURPLE
    ITEM_QUALITY_LEGENDARY             = 5, // ORANGE
    ITEM_QUALITY_ARTIFACT              = 6, // LIGHT YELLOW
    ITEM_QUALITY_HEIRLOOM              = 7, // LIGHT BLUE
    ITEM_QUALITY_WOW_TOKEN             = 8, // LIGHT BLUE
    MAX_ITEM_QUALITY
};

enum SpellCategory
{
    SPELL_CATEGORY_FOOD             = 11,
    SPELL_CATEGORY_DRINK            = 59
};

enum SpellVisualKit
{
    SPELL_VISUAL_KIT_FOOD           = 406,
    SPELL_VISUAL_KIT_DRINK          = 438
};

uint32 constexpr ItemQualityColors[MAX_ITEM_QUALITY] =
{
    0xff9d9d9d, // GREY
    0xffffffff, // WHITE
    0xff1eff00, // GREEN
    0xff0070dd, // BLUE
    0xffa335ee, // PURPLE
    0xffff8000, // ORANGE
    0xffe6cc80, // LIGHT YELLOW
    0xff00ccff, // LIGHT BLUE
    0xff00ccff  // LIGHT BLUE
};

size_t constexpr MAX_QUEST_DIFFICULTY = 5;
uint32 constexpr QuestDifficultyColors[MAX_QUEST_DIFFICULTY] =
{
    0xff40c040,
    0xff808080,
    0xffffff00,
    0xffff8040,
    0xffff2020
};

// ***********************************
// Spell Attributes definitions
// ***********************************

// EnumUtils: DESCRIBE THIS
enum SpellAttr0 : uint32
{
    SPELL_ATTR0_PROC_FAILURE_BURNS_CHARGE                           = 0x00000001, // TITLE Proc Failure Burns Charge
    SPELL_ATTR0_USES_RANGED_SLOT                                    = 0x00000002, // TITLE Uses Ranged Slot DESCRIPTION Use ammo, ranged attack range modifiers, ranged haste, etc.
    SPELL_ATTR0_ON_NEXT_SWING_NO_DAMAGE                             = 0x00000004, // TITLE On Next Swing (No Damage) DESCRIPTION Both "on next swing" attributes have identical handling in server & client
    SPELL_ATTR0_DO_NOT_LOG_IMMUNE_MISSES                            = 0x00000008, // TITLE Do Not Log Immune Misses (client only)
    SPELL_ATTR0_IS_ABILITY                                          = 0x00000010, // TITLE Is Ability DESCRIPTION Cannot be reflected, not affected by cast speed modifiers, etc.
    SPELL_ATTR0_IS_TRADESKILL                                       = 0x00000020, // TITLE Is Tradeskill DESCRIPTION Displayed in recipe list, not affected by cast speed modifiers
    SPELL_ATTR0_PASSIVE                                             = 0x00000040, // TITLE Passive DESCRIPTION Spell is automatically cast on self by core
    SPELL_ATTR0_DO_NOT_DISPLAY_SPELLBOOK_AURA_ICON_COMBAT_LOG       = 0x00000080, // TITLE Do Not Display (Spellbook, Aura Icon, Combat Log) (client only) DESCRIPTION Not visible in spellbook or aura bar
    SPELL_ATTR0_DO_NOT_LOG                                          = 0x00000100, // TITLE Do Not Log (client only) DESCRIPTION Spell will not appear in combat logs
    SPELL_ATTR0_HELD_ITEM_ONLY                                      = 0x00000200, // TITLE Held Item Only (client only) DESCRIPTION Client will automatically select main-hand item as cast target
    SPELL_ATTR0_ON_NEXT_SWING                                       = 0x00000400, // TITLE On Next Swing DESCRIPTION Both "on next swing" attributes have identical handling in server & client
    SPELL_ATTR0_WEARER_CASTS_PROC_TRIGGER                           = 0x00000800, // TITLE Wearer Casts Proc Trigger DESCRIPTION Just a marker attribute to show auras that trigger another spell (either directly or with a script)
    SPELL_ATTR0_SERVER_ONLY                                         = 0x00001000, // TITLE Server Only
    SPELL_ATTR0_ALLOW_ITEM_SPELL_IN_PVP                             = 0x00002000, // TITLE Allow Item Spell In PvP
    SPELL_ATTR0_ONLY_INDOORS                                        = 0x00004000, // TITLE Only Indoors
    SPELL_ATTR0_ONLY_OUTDOORS                                       = 0x00008000, // TITLE Only Outdoors
    SPELL_ATTR0_NOT_SHAPESHIFTED                                    = 0x00010000, // TITLE Not Shapeshifted
    SPELL_ATTR0_ONLY_STEALTHED                                      = 0x00020000, // TITLE Only Stealthed
    SPELL_ATTR0_DO_NOT_SHEATH                                       = 0x00040000, // TITLE Do Not Sheath (client only)
    SPELL_ATTR0_SCALES_WITH_CREATURE_LEVEL                          = 0x00080000, // TITLE Scales w/ Creature Level DESCRIPTION For non-player casts, scale impact and power cost with caster's level
    SPELL_ATTR0_CANCELS_AUTO_ATTACK_COMBAT                          = 0x00100000, // TITLE Cancels Auto Attack Combat DESCRIPTION After casting this, the current auto-attack will be interrupted
    SPELL_ATTR0_NO_ACTIVE_DEFENSE                                   = 0x00200000, // TITLE No Active Defense DESCRIPTION Spell cannot be dodged, parried or blocked
    SPELL_ATTR0_TRACK_TARGET_IN_CAST_PLAYER_ONLY                    = 0x00400000, // TITLE Track Target in Cast (Player Only) (client only)
    SPELL_ATTR0_ALLOW_CAST_WHILE_DEAD                               = 0x00800000, // TITLE Allow Cast While Dead DESCRIPTION Spells without this flag cannot be cast by dead units in non-triggered contexts
    SPELL_ATTR0_ALLOW_WHILE_MOUNTED                                 = 0x01000000, // TITLE Allow While Mounted
    SPELL_ATTR0_COOLDOWN_ON_EVENT                                   = 0x02000000, // TITLE Cooldown On Event DESCRIPTION Spell is unusable while already active, and cooldown does not begin until the effects have worn off
    SPELL_ATTR0_AURA_IS_DEBUFF                                      = 0x04000000, // TITLE Aura Is Debuff DESCRIPTION Forces the spell to be treated as a negative spell
    SPELL_ATTR0_ALLOW_WHILE_SITTING                                 = 0x08000000, // TITLE Allow While Sitting
    SPELL_ATTR0_NOT_IN_COMBAT_ONLY_PEACEFUL                         = 0x10000000, // TITLE Not In Combat (Only Peaceful)
    SPELL_ATTR0_NO_IMMUNITIES                                       = 0x20000000, // TITLE No Immunities DESCRIPTION Allows spell to pierce invulnerability, unless the invulnerability spell also has this attribute
    SPELL_ATTR0_HEARTBEAT_RESIST                                    = 0x40000000, // TITLE Heartbeat Resist DESCRIPTION Periodically re-rolls against resistance to potentially expire aura early
    SPELL_ATTR0_NO_AURA_CANCEL                                      = 0x80000000  // TITLE No Aura Cancel DESCRIPTION Prevents the player from voluntarily canceling a positive aura
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr1 : uint32
{
    SPELL_ATTR1_DISMISS_PET_FIRST                                   = 0x00000001, // TITLE Dismiss Pet First DESCRIPTION Without this attribute, summoning spells will fail if caster already has a pet
    SPELL_ATTR1_USE_ALL_MANA                                        = 0x00000002, // TITLE Use All Mana DESCRIPTION Ignores listed power cost and drains entire pool instead
    SPELL_ATTR1_IS_CHANNELLED                                       = 0x00000004, // TITLE Is Channelled DESCRIPTION Both "channeled" attributes have identical handling in server & client
    SPELL_ATTR1_NO_REDIRECTION                                      = 0x00000008, // TITLE No Redirection DESCRIPTION Spell will not be attracted by SPELL_MAGNET auras (Grounding Totem)
    SPELL_ATTR1_NO_SKILL_INCREASE                                   = 0x00000010, // TITLE No Skill Increase
    SPELL_ATTR1_ALLOW_WHILE_STEALTHED                               = 0x00000020, // TITLE Allow While Stealthed
    SPELL_ATTR1_IS_SELF_CHANNELLED                                  = 0x00000040, // TITLE Is Self Channelled DESCRIPTION Both "channeled" attributes have identical handling in server & client
    SPELL_ATTR1_NO_REFLECTION                                       = 0x00000080, // TITLE No Reflection DESCRIPTION Spell will pierce through Spell Reflection and similar
    SPELL_ATTR1_ONLY_PEACEFUL_TARGETS                               = 0x00000100, // TITLE Only Peaceful Targets DESCRIPTION Target cannot be in combat
    SPELL_ATTR1_INITIATES_COMBAT_ENABLES_AUTO_ATTACK                = 0x00000200, // TITLE Initiates Combat (Enables Auto-Attack) (client only) DESCRIPTION Caster will begin auto-attacking the target on cast
    SPELL_ATTR1_NO_THREAT                                           = 0x00000400, // TITLE No Threat DESCRIPTION Also does not cause target to engage
    SPELL_ATTR1_AURA_UNIQUE                                         = 0x00000800, // TITLE Aura Unique DESCRIPTION Aura will not refresh its duration when recast
    SPELL_ATTR1_FAILURE_BREAKS_STEALTH                              = 0x00001000, // TITLE Failure Breaks Stealth
    SPELL_ATTR1_TOGGLE_FAR_SIGHT                                    = 0x00002000, // TITLE Toggle Far Sight (client only)
    SPELL_ATTR1_TRACK_TARGET_IN_CHANNEL                             = 0x00004000, // TITLE Track Target in Channel DESCRIPTION While channeling, adjust facing to face target
    SPELL_ATTR1_IMMUNITY_PURGES_EFFECT                              = 0x00008000, // TITLE Immunity Purges Effect DESCRIPTION For immunity spells, cancel all auras that this spell would make you immune to when the spell is applied
    SPELL_ATTR1_IMMUNITY_TO_HOSTILE_AND_FRIENDLY_EFFECTS            = 0x00010000, // TITLE Immunity to Hostile & Friendly Effects DESCRIPTION Immunity applied by this aura will also be checked for friendly spells (school immunity only) - used by Cyclone for example to cause friendly spells and healing over time to be immuned
    SPELL_ATTR1_NO_AUTOCAST_AI                                      = 0x00020000, // TITLE No AutoCast (AI)
    SPELL_ATTR1_PREVENTS_ANIM                                       = 0x00040000, /*NYI*/ // TITLE Prevents Anim DESCRIPTION Auras apply UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT
    SPELL_ATTR1_EXCLUDE_CASTER                                      = 0x00080000, // TITLE Exclude Caster
    SPELL_ATTR1_FINISHING_MOVE_DAMAGE                               = 0x00100000, // TITLE Finishing Move - Damage
    SPELL_ATTR1_THREAT_ONLY_ON_MISS                                 = 0x00200000, /*NYI*/ // TITLE Threat only on Miss
    SPELL_ATTR1_FINISHING_MOVE_DURATION                             = 0x00400000, // TITLE Finishing Move - Duration
    SPELL_ATTR1_IGNORE_OWNERS_DEATH                                 = 0x00800000, /*NYI*/ // TITLE Ignore Owner's Death
    SPELL_ATTR1_SPECIAL_SKILLUP                                     = 0x01000000, // TITLE Special Skillup
    SPELL_ATTR1_AURA_STAYS_AFTER_COMBAT                             = 0x02000000, // TITLE Aura Stays After Combat
    SPELL_ATTR1_REQUIRE_ALL_TARGETS                                 = 0x04000000, // TITLE Require All Targets
    SPELL_ATTR1_DISCOUNT_POWER_ON_MISS                              = 0x08000000, // TITLE Discount Power On Miss
    SPELL_ATTR1_NO_AURA_ICON                                        = 0x10000000, // TITLE No Aura Icon (client only)
    SPELL_ATTR1_NAME_IN_CHANNEL_BAR                                 = 0x20000000, // TITLE Name in Channel Bar (client only)
    SPELL_ATTR1_DISPEL_ALL_STACKS                                   = 0x40000000, // TITLE Dispel All Stacks
    SPELL_ATTR1_CAST_WHEN_LEARNED                                   = 0x80000000  // TITLE Cast When Learned
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr2 : uint32
{
    SPELL_ATTR2_ALLOW_DEAD_TARGET                                   = 0x00000001, // TITLE Allow Dead Target
    SPELL_ATTR2_NO_SHAPESHIFT_UI                                    = 0x00000002, // TITLE No shapeshift UI (client only) DESCRIPTION Does not replace action bar when shapeshifted
    SPELL_ATTR2_IGNORE_LINE_OF_SIGHT                                = 0x00000004, // TITLE Ignore Line of Sight
    SPELL_ATTR2_ALLOW_LOW_LEVEL_BUFF                                = 0x00000008, // TITLE Allow Low Level Buff
    SPELL_ATTR2_USE_SHAPESHIFT_BAR                                  = 0x00000010, // TITLE Use Shapeshift Bar (client only)
    SPELL_ATTR2_AUTO_REPEAT                                         = 0x00000020, // TITLE Auto Repeat
    SPELL_ATTR2_CANNOT_CAST_ON_TAPPED                               = 0x00000040, // TITLE Cannot cast on tapped DESCRIPTION Can only target untapped units, or those tapped by caster
    SPELL_ATTR2_DO_NOT_REPORT_SPELL_FAILURE                         = 0x00000080, // TITLE Do Not Report Spell Failure
    SPELL_ATTR2_INCLUDE_IN_ADVANCED_COMBAT_LOG                      = 0x00000100, // TITLE Include In Advanced Combat Log (client only) DESCRIPTION Determines whether to include this aura in list of auras in SMSG_ENCOUNTER_START
    SPELL_ATTR2_ALWAYS_CAST_AS_UNIT                                 = 0x00000200, /*NYI, UNK*/ // TITLE Always Cast As Unit
    SPELL_ATTR2_SPECIAL_TAMING_FLAG                                 = 0x00000400, // TITLE Special Taming Flag DESCRIPTION Related to taming?
    SPELL_ATTR2_NO_TARGET_PER_SECOND_COSTS                          = 0x00000800, // TITLE No Target Per-Second Costs
    SPELL_ATTR2_CHAIN_FROM_CASTER                                   = 0x00001000, // TITLE Chain From Caster
    SPELL_ATTR2_ENCHANT_OWN_ITEM_ONLY                               = 0x00002000, // TITLE Enchant own item only
    SPELL_ATTR2_ALLOW_WHILE_INVISIBLE                               = 0x00004000, // TITLE Allow While Invisible
    SPELL_ATTR2_DO_NOT_CONSUME_IF_GAINED_DURING_CAST                = 0x00008000, // TITLE Do Not Consume if Gained During Cast
    SPELL_ATTR2_NO_ACTIVE_PETS                                      = 0x00010000, // TITLE No Active Pets
    SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS                          = 0x00020000, // TITLE Do Not Reset Combat Timers DESCRIPTION Does not reset melee/ranged autoattack timer on cast
    SPELL_ATTR2_NO_JUMP_WHILE_CAST_PENDING                          = 0x00040000, // TITLE No Jump While Cast Pending (client only)
    SPELL_ATTR2_ALLOW_WHILE_NOT_SHAPESHIFTED_CASTER_FORM            = 0x00080000, // TITLE Allow While Not Shapeshifted (caster form) DESCRIPTION Even if Stances are nonzero, allow spell to be cast outside of shapeshift (though not in a different shapeshift)
    SPELL_ATTR2_INITIATE_COMBAT_POST_CAST_ENABLES_AUTO_ATTACK       = 0x00100000, // TITLE Initiate Combat Post-Cast (Enables Auto-Attack)
    SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE                          = 0x00200000, // TITLE Fail on all targets immune DESCRIPTION Causes BG flags to be dropped if combined with ATTR1_DISPEL_AURAS_ON_IMMUNITY
    SPELL_ATTR2_NO_INITIAL_THREAT                                   = 0x00400000, // TITLE No Initial Threat
    SPELL_ATTR2_PROC_COOLDOWN_ON_FAILURE                            = 0x00800000, // TITLE Proc Cooldown On Failure
    SPELL_ATTR2_ITEM_CAST_WITH_OWNER_SKILL                          = 0x01000000, // TITLE Item Cast With Owner Skill
    SPELL_ATTR2_DONT_BLOCK_MANA_REGEN                               = 0x02000000, // TITLE Don't Block Mana Regen
    SPELL_ATTR2_NO_SCHOOL_IMMUNITIES                                = 0x04000000, // TITLE No School Immunities DESCRIPTION Allow aura to be applied despite target being immune to new aura applications
    SPELL_ATTR2_IGNORE_WEAPONSKILL                                  = 0x08000000, // TITLE Ignore Weaponskill
    SPELL_ATTR2_NOT_AN_ACTION                                       = 0x10000000, // TITLE Not an Action
    SPELL_ATTR2_CANT_CRIT                                           = 0x20000000, // TITLE Can't Crit
    SPELL_ATTR2_ACTIVE_THREAT                                       = 0x40000000, // TITLE Active Threat
    SPELL_ATTR2_RETAIN_ITEM_CAST                                    = 0x80000000  // TITLE Retain Item Cast DESCRIPTION passes m_CastItem to triggered spells
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr3 : uint32
{
    SPELL_ATTR3_PVP_ENABLING                                        = 0x00000001, // TITLE PvP Enabling
    SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT                           = 0x00000002, // TITLE No Proc Equip Requirement DESCRIPTION Ignores subclass mask check when checking proc
    SPELL_ATTR3_NO_CASTING_BAR_TEXT                                 = 0x00000004, // TITLE No Casting Bar Text
    SPELL_ATTR3_COMPLETELY_BLOCKED                                  = 0x00000008, // TITLE Completely Blocked
    SPELL_ATTR3_NO_RES_TIMER                                        = 0x00000010, // TITLE No Res Timer
    SPELL_ATTR3_NO_DURABILITY_LOSS                                  = 0x00000020, // TITLE No Durability Loss
    SPELL_ATTR3_NO_AVOIDANCE                                        = 0x00000040, // TITLE No Avoidance
    SPELL_ATTR3_DOT_STACKING_RULE                                   = 0x00000080, // TITLE DoT Stacking Rule DESCRIPTION Stack separately for each caster
    SPELL_ATTR3_ONLY_ON_PLAYER                                      = 0x00000100, // TITLE Only On Player
    SPELL_ATTR3_NOT_A_PROC                                          = 0x00000200, // TITLE Not a Proc DESCRIPTION Without this attribute, any triggered spell will be unable to trigger other auras' procs
    SPELL_ATTR3_REQUIRES_MAIN_HAND_WEAPON                           = 0x00000400, // TITLE Requires Main-Hand Weapon
    SPELL_ATTR3_ONLY_BATTLEGROUNDS                                  = 0x00000800, // TITLE Only Battlegrounds
    SPELL_ATTR3_ONLY_ON_GHOSTS                                      = 0x00001000, // TITLE Only On Ghosts
    SPELL_ATTR3_HIDE_CHANNEL_BAR                                    = 0x00002000, // TITLE Hide Channel Bar (client only)
    SPELL_ATTR3_HIDE_IN_RAID_FILTER                                 = 0x00004000, // TITLE Hide In Raid Filter (client only)
    SPELL_ATTR3_NORMAL_RANGED_ATTACK                                = 0x00008000, // TITLE Normal Ranged Attack DESCRIPTION Auto Shoot, Shoot, Throw - ranged normal attack attribute?
    SPELL_ATTR3_SUPPRESS_CASTER_PROCS                               = 0x00010000, // TITLE Suppress Caster Procs
    SPELL_ATTR3_SUPPRESS_TARGET_PROCS                               = 0x00020000, // TITLE Suppress Target Procs
    SPELL_ATTR3_ALWAYS_HIT                                          = 0x00040000, // TITLE Always Hit DESCRIPTION Spell cannot miss, or be dodged/parried/blocked
    SPELL_ATTR3_INSTANT_TARGET_PROCS                                = 0x00080000, // TITLE Instant Target Procs DESCRIPTION Proc events are triggered before spell batching processes the spell hit on target
    SPELL_ATTR3_ALLOW_AURA_WHILE_DEAD                               = 0x00100000, // TITLE Allow Aura While Dead
    SPELL_ATTR3_ONLY_PROC_OUTDOORS                                  = 0x00200000, // TITLE Only Proc Outdoors
    SPELL_ATTR3_DO_NOT_TRIGGER_TARGET_STAND                         = 0x00400000, // TITLE Do Not Trigger Target Stand
    SPELL_ATTR3_NO_DAMAGE_HISTORY                                   = 0x00800000, /*NYI, no damage history implementation*/ // TITLE No Damage History
    SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON                            = 0x01000000, // TITLE Requires Off-Hand Weapon
    SPELL_ATTR3_TREAT_AS_PERIODIC                                   = 0x02000000, // TITLE Treat As Periodic
    SPELL_ATTR3_CAN_PROC_FROM_PROCS                                 = 0x04000000, // TITLE Can Proc From Procs
    SPELL_ATTR3_ONLY_PROC_ON_CASTER                                 = 0x08000000, // TITLE Only Proc on Caster
    SPELL_ATTR3_IGNORE_CASTER_AND_TARGET_RESTRICTIONS               = 0x10000000, /*NYI*/ // TITLE Ignore Caster & Target Restrictions
    SPELL_ATTR3_IGNORE_CASTER_MODIFIERS                             = 0x20000000, // TITLE Ignore Caster Modifiers
    SPELL_ATTR3_DO_NOT_DISPLAY_RANGE                                = 0x40000000, // TITLE Do Not Display Range (client only)
    SPELL_ATTR3_NOT_ON_AOE_IMMUNE                                   = 0x80000000  // TITLE Not On AOE Immune
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr4 : uint32
{
    SPELL_ATTR4_NO_CAST_LOG                                         = 0x00000001, // TITLE No Cast Log
    SPELL_ATTR4_CLASS_TRIGGER_ONLY_ON_TARGET                        = 0x00000002, // TITLE Class Trigger Only On Target
    SPELL_ATTR4_AURA_EXPIRES_OFFLINE                                = 0x00000004, // TITLE Aura Expires Offline DESCRIPTION Debuffs (except Resurrection Sickness) will automatically do this
    SPELL_ATTR4_NO_HELPFUL_THREAT                                   = 0x00000008, // TITLE No Helpful Threat
    SPELL_ATTR4_NO_HARMFUL_THREAT                                   = 0x00000010, // TITLE No Harmful Threat
    SPELL_ATTR4_ALLOW_CLIENT_TARGETING                              = 0x00000020, // TITLE Allow Client Targeting DESCRIPTION Allows client to send spell targets for this spell. Applies only to pet spells, without this attribute CMSG_PET_ACTION is sent instead of CMSG_PET_CAST_SPELL
    SPELL_ATTR4_CANNOT_BE_STOLEN                                    = 0x00000040, // TITLE Cannot Be Stolen
    SPELL_ATTR4_ALLOW_CAST_WHILE_CASTING                            = 0x00000080, // TITLE Allow Cast While Casting DESCRIPTION Ignores already in-progress cast and still casts
    SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS                       = 0x00000100, // TITLE Ignore Damage Taken Modifiers
    SPELL_ATTR4_COMBAT_FEEDBACK_WHEN_USABLE                         = 0x00000200, // TITLE Combat Feedback When Usable (client only)
    SPELL_ATTR4_WEAPON_SPEED_COST_SCALING                           = 0x00000400, // TITLE Weapon Speed Cost Scaling DESCRIPTION Adds 10 to power cost for each 1s of weapon speed
    SPELL_ATTR4_NO_PARTIAL_IMMUNITY                                 = 0x00000800, // TITLE No Partial Immunity
    SPELL_ATTR4_AURA_IS_BUFF                                        = 0x00001000, // TITLE Aura Is Buff
    SPELL_ATTR4_DO_NOT_LOG_CASTER                                   = 0x00002000, // TITLE Do Not Log Caster
    SPELL_ATTR4_REACTIVE_DAMAGE_PROC                                = 0x00004000, // TITLE Reactive Damage Proc DESCRIPTION Damage from spells with this attribute doesn't break auras that normally break on damage taken
    SPELL_ATTR4_NOT_IN_SPELLBOOK                                    = 0x00008000, // TITLE Not In Spellbook
    SPELL_ATTR4_NOT_IN_ARENA_OR_RATED_BATTLEGROUND                  = 0x00010000, // TITLE Not In Arena or Rated Battleground DESCRIPTION Makes spell unusable despite CD <= 10min
    SPELL_ATTR4_IGNORE_DEFAULT_ARENA_RESTRICTIONS                   = 0x00020000, // TITLE Ignore Default Arena Restrictions DESCRIPTION Makes spell usable despite CD > 10min
    SPELL_ATTR4_BOUNCY_CHAIN_MISSILES                               = 0x00040000, // TITLE Bouncy Chain Missiles DESCRIPTION Hits area targets over time instead of all at once
    SPELL_ATTR4_ALLOW_PROC_WHILE_SITTING                            = 0x00080000, // TITLE Allow Proc While Sitting
    SPELL_ATTR4_AURA_NEVER_BOUNCES                                  = 0x00100000, // TITLE Aura Never Bounces
    SPELL_ATTR4_ALLOW_ENTERING_ARENA                                = 0x00200000, // TITLE Allow Entering Arena
    SPELL_ATTR4_PROC_SUPPRESS_SWING_ANIM                            = 0x00400000, // TITLE Proc Suppress Swing Anim
    SPELL_ATTR4_SUPPRESS_WEAPON_PROCS                               = 0x00800000, // TITLE Suppress Weapon Procs
    SPELL_ATTR4_AUTO_RANGED_COMBAT                                  = 0x01000000, // TITLE Auto Ranged Combat
    SPELL_ATTR4_OWNER_POWER_SCALING                                 = 0x02000000, // TITLE Owner Power Scaling
    SPELL_ATTR4_ONLY_FLYING_AREAS                                   = 0x04000000, // TITLE Only Flying Areas
    SPELL_ATTR4_FORCE_DISPLAY_CASTBAR                               = 0x08000000, // TITLE Force Display Castbar
    SPELL_ATTR4_IGNORE_COMBAT_TIMER                                 = 0x10000000, // TITLE Ignore Combat Timer
    SPELL_ATTR4_AURA_BOUNCE_FAILS_SPELL                             = 0x20000000, // TITLE Aura Bounce Fails Spell
    SPELL_ATTR4_OBSOLETE                                            = 0x40000000, // TITLE Obsolete
    SPELL_ATTR4_USE_FACING_FROM_SPELL                               = 0x80000000  // TITLE Use Facing From Spell
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr5 : uint32
{
    SPELL_ATTR5_ALLOW_ACTIONS_DURING_CHANNEL                        = 0x00000001, // TITLE Allow Actions During Channel
    SPELL_ATTR5_NO_REAGENT_COST_WITH_AURA                           = 0x00000002, // TITLE No Reagent Cost With Aura
    SPELL_ATTR5_REMOVE_ENTERING_ARENA                               = 0x00000004, // TITLE Remove Entering Arena DESCRIPTION Force this aura to be removed on entering arena, regardless of other properties
    SPELL_ATTR5_ALLOW_WHILE_STUNNED                                 = 0x00000008, // TITLE Allow While Stunned
    SPELL_ATTR5_TRIGGERS_CHANNELING                                 = 0x00000010, // TITLE Triggers Channeling
    SPELL_ATTR5_LIMIT_N                                             = 0x00000020, // TITLE Limit N DESCRIPTION Remove previous application to another unit if applied
    SPELL_ATTR5_IGNORE_AREA_EFFECT_PVP_CHECK                        = 0x00000040, // TITLE Ignore Area Effect PvP Check
    SPELL_ATTR5_NOT_ON_PLAYER                                       = 0x00000080, // TITLE Not On Player
    SPELL_ATTR5_NOT_ON_PLAYER_CONTROLLED_NPC                        = 0x00000100, // TITLE Not On Player Controlled NPC
    SPELL_ATTR5_EXTRA_INITIAL_PERIOD                                = 0x00000200, // TITLE Extra Initial Period DESCRIPTION Immediately do periodic tick on apply
    SPELL_ATTR5_DO_NOT_DISPLAY_DURATION                             = 0x00000400, // TITLE Do Not Display Duration
    SPELL_ATTR5_IMPLIED_TARGETING                                   = 0x00000800, // TITLE Implied Targeting (client only)
    SPELL_ATTR5_MELEE_CHAIN_TARGETING                               = 0x00001000, // TITLE Melee Chain Targeting
    SPELL_ATTR5_SPELL_HASTE_AFFECTS_PERIODIC                        = 0x00002000, // TITLE Spell Haste Affects Periodic
    SPELL_ATTR5_NOT_AVAILABLE_WHILE_CHARMED                         = 0x00004000, // TITLE Not Available While Charmed
    SPELL_ATTR5_TREAT_AS_AREA_EFFECT                                = 0x00008000, // TITLE Treat as Area Effect
    SPELL_ATTR5_AURA_AFFECTS_NOT_JUST_REQ_EQUIPPED_ITEM             = 0x00010000, // TITLE Aura Affects Not Just Req. Equipped Item
    SPELL_ATTR5_ALLOW_WHILE_FLEEING                                 = 0x00020000, // TITLE Allow While Fleeing
    SPELL_ATTR5_ALLOW_WHILE_CONFUSED                                = 0x00040000, // TITLE Allow While Confused
    SPELL_ATTR5_AI_DOESNT_FACE_TARGET                               = 0x00080000, // TITLE AI Doesn't Face Target
    SPELL_ATTR5_DO_NOT_ATTEMPT_A_PET_RESUMMON_WHEN_DISMOUNTING      = 0x00100000, // TITLE Do Not Attempt a Pet Resummon When Dismounting DESCRIPTION No generic handling possible, used by scripted dismount spells
    SPELL_ATTR5_IGNORE_TARGET_REQUIREMENTS                          = 0x00200000, /*NYI*/ // TITLE Ignore Target Requirements
    SPELL_ATTR5_NOT_ON_TRIVIAL                                      = 0x00400000, /*NYI*/ // TITLE Not On Trivial
    SPELL_ATTR5_NO_PARTIAL_RESISTS                                  = 0x00800000, /*NYI, resisting only some spell effects not implemented*/ // TITLE No Partial Resists
    SPELL_ATTR5_IGNORE_CASTER_REQUIREMENTS                          = 0x01000000, /*NYI*/ // TITLE Ignore Caster Requirements
    SPELL_ATTR5_ALWAYS_LINE_OF_SIGHT                                = 0x02000000, // TITLE Always Line of Sight
    SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT                            = 0x04000000, // TITLE Always AOE Line of Sight DESCRIPTION Requires line of sight between caster and target in addition to between dest and target
    SPELL_ATTR5_NO_CASTER_AURA_ICON                                 = 0x08000000, // TITLE No Caster Aura Icon (client only)
    SPELL_ATTR5_NO_TARGET_AURA_ICON                                 = 0x10000000, // TITLE No Target Aura Icon (client only)
    SPELL_ATTR5_AURA_UNIQUE_PER_CASTER                              = 0x20000000, // TITLE Aura Unique Per Caster
    SPELL_ATTR5_ALWAYS_SHOW_GROUND_TEXTURE                          = 0x40000000, // TITLE Always Show Ground Texture
    SPELL_ATTR5_ADD_MELEE_HIT_RATING                                = 0x80000000  // TITLE Add Melee Hit Rating
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr6 : uint32
{
    SPELL_ATTR6_NO_COOLDOWN_ON_TOOLTIP                              = 0x00000001, // TITLE No Cooldown On Tooltip (client only)
    SPELL_ATTR6_DO_NOT_RESET_COOLDOWN_IN_ARENA                      = 0x00000002, // TITLE Do Not Reset Cooldown In Arena
    SPELL_ATTR6_NOT_AN_ATTACK                                       = 0x00000004, /*NYI*/ // TITLE Not an Attack
    SPELL_ATTR6_CAN_ASSIST_IMMUNE_PC                                = 0x00000008, // TITLE Can Assist Immune PC
    SPELL_ATTR6_IGNORE_FOR_MOD_TIME_RATE                            = 0x00000010, /*NYI, time rate not implemented*/ // TITLE Ignore For Mod Time Rate
    SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES                            = 0x00000020, // TITLE Do Not Consume Resources
    SPELL_ATTR6_FLOATING_COMBAT_TEXT_ON_CAST                        = 0x00000040, // TITLE Floating Combat Text On Cast (client only)
    SPELL_ATTR6_AURA_IS_WEAPON_PROC                                 = 0x00000080, // TITLE Aura Is Weapon Proc
    SPELL_ATTR6_DO_NOT_CHAIN_TO_CROWD_CONTROLLED_TARGETS            = 0x00000100, // TITLE Do Not Chain To Crowd-Controlled Targets DESCRIPTION Implicit targeting (chaining and area targeting) will not impact crowd controlled targets
    SPELL_ATTR6_ALLOW_ON_CHARMED_TARGETS                            = 0x00000200, /*NYI*/ // TITLE Allow On Charmed Targets
    SPELL_ATTR6_NO_AURA_LOG                                         = 0x00000400, // TITLE No Aura Log
    SPELL_ATTR6_NOT_IN_RAID_INSTANCES                               = 0x00000800, // TITLE Not In Raid Instances
    SPELL_ATTR6_ALLOW_WHILE_RIDING_VEHICLE                          = 0x00001000, // TITLE Allow While Riding Vehicle
    SPELL_ATTR6_IGNORE_PHASE_SHIFT                                  = 0x00002000, // TITLE Ignore Phase Shift
    SPELL_ATTR6_AI_PRIMARY_RANGED_ATTACK                            = 0x00004000, /*NYI*/ // TITLE AI Primary Ranged Attack
    SPELL_ATTR6_NO_PUSHBACK                                         = 0x00008000, // TITLE No Pushback
    SPELL_ATTR6_NO_JUMP_PATHING                                     = 0x00010000, /*NYI, currently jumps dont path at all*/ // TITLE No Jump Pathing
    SPELL_ATTR6_ALLOW_EQUIP_WHILE_CASTING                           = 0x00020000, // TITLE Allow Equip While Casting
    SPELL_ATTR6_ORIGINATE_FROM_CONTROLLER                           = 0x00040000, // TITLE Originate From Controller DESCRIPTION Client will prevent casting if not possessed, charmer will be caster for all intents and purposes
    SPELL_ATTR6_DELAY_COMBAT_TIMER_DURING_CAST                      = 0x00080000, // TITLE Delay Combat Timer During Cast
    SPELL_ATTR6_AURA_ICON_ONLY_FOR_CASTER_LIMIT_10                  = 0x00100000, // TITLE Aura Icon Only For Caster (Limit 10) (client only)
    SPELL_ATTR6_SHOW_MECHANIC_AS_COMBAT_TEXT                        = 0x00200000, // TITLE Show Mechanic as Combat Text (client only)
    SPELL_ATTR6_ABSORB_CANNOT_BE_IGNORE                             = 0x00400000, // TITLE Absorb Cannot Be Ignore
    SPELL_ATTR6_TAPS_IMMEDIATELY                                    = 0x00800000, // TITLE Taps immediately
    SPELL_ATTR6_CAN_TARGET_UNTARGETABLE                             = 0x01000000, // TITLE Can Target Untargetable
    SPELL_ATTR6_DOESNT_RESET_SWING_TIMER_IF_INSTANT                 = 0x02000000, // TITLE Doesn't Reset Swing Timer if Instant
    SPELL_ATTR6_VEHICLE_IMMUNITY_CATEGORY                           = 0x04000000, /*NYI, immunity to some buffs for some vehicles*/ // TITLE Vehicle Immunity Category
    SPELL_ATTR6_IGNORE_HEALING_MODIFIERS                            = 0x08000000, // TITLE Ignore Healing Modifiers DESCRIPTION This prevents certain healing modifiers from applying - see implementation if you really care about details
    SPELL_ATTR6_DO_NOT_AUTO_SELECT_TARGET_WITH_INITIATES_COMBAT     = 0x10000000, // TITLE Do Not Auto Select Target with Initiates Combat (client only)
    SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS                      = 0x20000000, // TITLE Ignore Caster Damage Modifiers DESCRIPTION This prevents certain damage modifiers from applying - see implementation if you really care about details
    SPELL_ATTR6_DISABLE_TIED_EFFECT_POINTS                          = 0x40000000, /*NYI*/ // TITLE Disable Tied Effect Points
    SPELL_ATTR6_NO_CATEGORY_COOLDOWN_MODS                           = 0x80000000  // TITLE No Category Cooldown Mods
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr7 : uint32
{
    SPELL_ATTR7_ALLOW_SPELL_REFLECTION                              = 0x00000001, // TITLE Allow Spell Reflection
    SPELL_ATTR7_NO_TARGET_DURATION_MOD                              = 0x00000002, // TITLE No Target Duration Mod
    SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD                             = 0x00000004, // TITLE Disable Aura While Dead
    SPELL_ATTR7_DEBUG_SPELL                                         = 0x00000008, // TITLE Debug Spell DESCRIPTION Cannot cast if caster doesn't have UnitFlag2 & UNIT_FLAG2_ALLOW_CHEAT_SPELLS
    SPELL_ATTR7_TREAT_AS_RAID_BUFF                                  = 0x00000010, /*NYI*/ // TITLE Treat as Raid Buff
    SPELL_ATTR7_CAN_BE_MULTI_CAST                                   = 0x00000020, // TITLE Can Be Multi Cast
    SPELL_ATTR7_DONT_CAUSE_SPELL_PUSHBACK                           = 0x00000040, // TITLE Don't Cause Spell Pushback DESCRIPTION Damage dealt by this does not cause spell pushback
    SPELL_ATTR7_PREPARE_FOR_VEHICLE_CONTROL_END                     = 0x00000080, /*NYI*/ // TITLE Prepare for Vehicle Control End
    SPELL_ATTR7_HORDE_SPECIFIC_SPELL                                = 0x00000100, /*NYI*/ // TITLE Horde Specific Spell
    SPELL_ATTR7_ALLIANCE_SPECIFIC_SPELL                             = 0x00000200, /*NYI*/ // TITLE Alliance Specific Spell
    SPELL_ATTR7_DISPEL_REMOVES_CHARGES                              = 0x00000400, // TITLE Dispel Removes Charges DESCRIPTION Dispel/Spellsteal remove individual charges
    SPELL_ATTR7_CAN_CAUSE_INTERRUPT                                 = 0x00000800, // TITLE Can Cause Interrupt DESCRIPTION Only interrupt non-player casting
    SPELL_ATTR7_CAN_CAUSE_SILENCE                                   = 0x00001000, /*NYI*/ // TITLE Can Cause Silence
    SPELL_ATTR7_NO_UI_NOT_INTERRUPTIBLE                             = 0x00002000, // TITLE No UI Not Interruptible DESCRIPTION Can always be interrupted, even if caster is immune
    SPELL_ATTR7_RECAST_ON_RESUMMON                                  = 0x00004000, /*NYI - deprecated attribute, there is no SPELL_GO sent anymore on pet resummon*/ // TITLE Recast On Resummon
    SPELL_ATTR7_RESET_SWING_TIMER_AT_SPELL_START                    = 0x00008000, // TITLE Reset Swing Timer at spell start
    SPELL_ATTR7_ONLY_IN_SPELLBOOK_UNTIL_LEARNED                     = 0x00010000, // TITLE Only In Spellbook Until Learned DESCRIPTION After learning these spells become hidden in spellbook (but are visible when not learned for low level characters)
    SPELL_ATTR7_DO_NOT_LOG_PVP_KILL                                 = 0x00020000, /*NYI, only used by 1 spell that is already filtered out in pvp credits because its self targeting*/ // TITLE Do Not Log PvP Kill
    SPELL_ATTR7_ATTACK_ON_CHARGE_TO_UNIT                            = 0x00040000, // TITLE Attack on Charge to Unit
    SPELL_ATTR7_REPORT_SPELL_FAILURE_TO_UNIT_TARGET                 = 0x00080000, // TITLE Report Spell failure to unit target
    SPELL_ATTR7_NO_CLIENT_FAIL_WHILE_STUNNED_FLEEING_CONFUSED       = 0x00100000, // TITLE No Client Fail While Stunned, Fleeing, Confused DESCRIPTION Clientside - skips stunned/fleeing/confused checks
    SPELL_ATTR7_RETAIN_COOLDOWN_THROUGH_LOAD                        = 0x00200000, /*NYI*/ // TITLE Retain Cooldown Through Load
    SPELL_ATTR7_IGNORES_COLD_WEATHER_FLYING_REQUIREMENT             = 0x00400000, /*NYI - deprecated attribute*/ // TITLE Ignores Cold Weather Flying Requirement
    SPELL_ATTR7_NO_ATTACK_DODGE                                     = 0x00800000, // TITLE No Attack Dodge
    SPELL_ATTR7_NO_ATTACK_PARRY                                     = 0x01000000, // TITLE No Attack Parry
    SPELL_ATTR7_NO_ATTACK_MISS                                      = 0x02000000, // TITLE No Attack Miss
    SPELL_ATTR7_TREAT_AS_NPC_AOE                                    = 0x04000000, // TITLE Treat as NPC AoE
    SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA                            = 0x08000000, // TITLE Bypass No Resurrect Aura
    SPELL_ATTR7_DO_NOT_COUNT_FOR_PVP_SCOREBOARD                     = 0x10000000, // TITLE Do Not Count For PvP Scoreboard
    SPELL_ATTR7_REFLECTION_ONLY_DEFENDS                             = 0x20000000, // TITLE Reflection Only Defends
    SPELL_ATTR7_CAN_PROC_FROM_SUPPRESSED_TARGET_PROCS               = 0x40000000, // TITLE Can Proc From Suppressed Target Procs
    SPELL_ATTR7_ALWAYS_CAST_LOG                                     = 0x80000000  // TITLE Always Cast Log
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr8 : uint32
{
    SPELL_ATTR8_NO_ATTACK_BLOCK                                     = 0x00000001, // TITLE No Attack Block
    SPELL_ATTR8_IGNORE_DYNAMIC_OBJECT_CASTER                        = 0x00000002, /*NYI*/ // TITLE Ignore Dynamic Object Caster
    SPELL_ATTR8_REMOVE_OUTSIDE_DUNGEONS_AND_RAIDS                   = 0x00000004, // TITLE Remove Outside Dungeons and Raids
    SPELL_ATTR8_ONLY_TARGET_IF_SAME_CREATOR                         = 0x00000008, // TITLE Only Target If Same Creator
    SPELL_ATTR8_CAN_HIT_AOE_UNTARGETABLE                            = 0x00000010, // TITLE Can Hit AOE Untargetable
    SPELL_ATTR8_ALLOW_WHILE_CHARMED                                 = 0x00000020, /*NYI - not implementable currently, charming replaces AI*/ // TITLE Allow While Charmed
    SPELL_ATTR8_AURA_REQUIRED_BY_CLIENT                             = 0x00000040, /*NYI - we send all auras to client*/ // TITLE Aura Required by Client
    SPELL_ATTR8_IGNORE_SANCTUARY                                    = 0x00000080, // TITLE Ignore Sanctuary
    SPELL_ATTR8_USE_TARGETS_LEVEL_FOR_SPELL_SCALING                 = 0x00000100, // TITLE Use Target's Level for Spell Scaling
    SPELL_ATTR8_PERIODIC_CAN_CRIT                                   = 0x00000200, // TITLE Periodic Can Crit
    SPELL_ATTR8_MIRROR_CREATURE_NAME                                = 0x00000400, // TITLE Mirror creature name DESCRIPTION Transform auras also override name (handled clientside)
    SPELL_ATTR8_ONLY_PLAYERS_CAN_CAST_THIS_SPELL                    = 0x00000800, // TITLE Only Players Can Cast This Spell
    SPELL_ATTR8_AURA_POINTS_ON_CLIENT                               = 0x00001000, // TITLE Aura Points On Client
    SPELL_ATTR8_NOT_IN_SPELLBOOK_UNTIL_LEARNED                      = 0x00002000, // TITLE Not In Spellbook Until Learned DESCRIPTION Hides autolearned spell from spellbook before learning (handled clientside)
    SPELL_ATTR8_TARGET_PROCS_ON_CASTER                              = 0x00004000, // TITLE Target Procs On Caster DESCRIPTION Target (taken) procs happen on caster (actor) instead of aura target (action target)
    SPELL_ATTR8_REQUIRES_LOCATION_TO_BE_ON_LIQUID_SURFACE           = 0x00008000, // TITLE Requires location to be on liquid surface
    SPELL_ATTR8_ONLY_TARGET_OWN_SUMMONS                             = 0x00010000, // TITLE Only Target Own Summons
    SPELL_ATTR8_HASTE_AFFECTS_DURATION                              = 0x00020000, // TITLE Haste Affects Duration
    SPELL_ATTR8_IGNORE_SPELLCAST_OVERRIDE_COST                      = 0x00040000, // TTILE Ignore Spellcast Override Cost
    SPELL_ATTR8_ALLOW_TARGETS_HIDDEN_BY_SPAWN_TRACKING              = 0x00080000, /*NYI - no spawn tracking implementation*/ // TITLE Allow Targets Hidden by Spawn Tracking
    SPELL_ATTR8_REQUIRES_EQUIPPED_INV_TYPES                         = 0x00100000, // TITLE Requires Equipped Inv Types
    SPELL_ATTR8_NO_SUMMON_DEST_FROM_CLIENT_TARGETING_PATHING_REQUIREMENT = 0x00200000, /*NYI - vald path to a spell dest is not required currently if the dest comes from client*/ // TITLE No 'Summon + Dest from Client' Targeting Pathing Requirement
    SPELL_ATTR8_MELEE_HASTE_AFFECTS_PERIODIC                        = 0x00400000, // TITLE Melee Haste Affects Periodic
    SPELL_ATTR8_ENFORCE_IN_COMBAT_RESSURECTION_LIMIT                = 0x00800000, // TITLE Enforce In Combat Ressurection Limit DESCRIPTION Used to limit the number of resurrections in boss encounters
    SPELL_ATTR8_HEAL_PREDICTION                                     = 0x01000000, // TITLE Heal Prediction
    SPELL_ATTR8_NO_LEVEL_UP_TOAST                                   = 0x02000000, // TITLE No Level Up Toast
    SPELL_ATTR8_SKIP_IS_KNOWN_CHECK                                 = 0x04000000, // TITLE Skip Is Known Check
    SPELL_ATTR8_AI_FACE_TARGET                                      = 0x08000000, /*NYI - unknown facing conditions, needs research*/ // TITLE AI Face Target
    SPELL_ATTR8_NOT_IN_BATTLEGROUND                                 = 0x10000000, // TITLE Not in Battleground
    SPELL_ATTR8_MASTERY_AFFECTS_POINTS                              = 0x20000000, // TITLE Mastery Affects Points
    SPELL_ATTR8_DISPLAY_LARGE_AURA_ICON_ON_UNIT_FRAMES_BOSS_AURA    = 0x40000000, // TITLE Display Large Aura Icon On Unit Frames (Boss Aura)
    SPELL_ATTR8_CAN_ATTACK_IMMUNE_PC                                = 0x80000000  // TITLE Can Attack ImmunePC DESCRIPTION Do not check UNIT_FLAG_IMMUNE_TO_PC in IsValidAttackTarget
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr9 : uint32
{
    SPELL_ATTR9_FORCE_DEST_LOCATION                                 = 0x00000001, // TITLE Force Dest Location DESCRIPTION Ignores collision with terrain (unsure if it also ignores terrain height and can go under map)
    SPELL_ATTR9_MOD_INVIS_INCLUDES_PARTY                            = 0x00000002, // TITLE Mod Invis Includes Party 1@Attr9 DESCRIPTION Causes invisibility auras to ignore "can always see party member invis" rule
    SPELL_ATTR9_ONLY_WHEN_ILLEGALLY_MOUNTED                         = 0x00000004, // TITLE Only When Illegally Mounted
    SPELL_ATTR9_DO_NOT_LOG_AURA_REFRESH                             = 0x00000008, // TITLE Do Not Log Aura Refresh (client only)
    SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC                       = 0x00000010, // TITLE Missile Speed is Delay (in sec)
    SPELL_ATTR9_IGNORE_TOTEM_REQUIREMENTS_FOR_CASTING               = 0x00000020, // TITLE Ignore Totem Requirements for Casting
    SPELL_ATTR9_ITEM_CAST_GRANTS_SKILL_GAIN                         = 0x00000040, // TITLE Item Cast Grants Skill Gain
    SPELL_ATTR9_DO_NOT_ADD_TO_UNLEARN_LIST                          = 0x00000080, /* NYI - unlearn list not maintained SMSG_SEND_UNLEARN_SPELLS always empty */ // TITLE Do Not Add to Unlearn List
    SPELL_ATTR9_COOLDOWN_IGNORES_RANGED_WEAPON                      = 0x00000100, // TITLE Cooldown Ignores Ranged Weapon
    SPELL_ATTR9_NOT_IN_ARENA                                        = 0x00000200, // TITLE Not In Arena
    SPELL_ATTR9_TARGET_MUST_BE_GROUNDED                             = 0x00000400, // TITLE Target Must Be Grounded
    SPELL_ATTR9_ALLOW_WHILE_BANISHED_AURA_STATE                     = 0x00000800, // TITLE Allow While Banished Aura State DESCRIPTION Doesn't seem to be doing anything, banish behaves like a regular stun now - tested on patch 10.2.7 with spell 17767 (doesn't have this attribute, only SPELL_ATTR5_ALLOW_WHILE_STUNNED and was castable while banished)
    SPELL_ATTR9_FACE_UNIT_TARGET_UPON_COMPLETION_OF_JUMP_CHARGE     = 0x00001000, // TITLE Face unit target upon completion of jump charge
    SPELL_ATTR9_HASTE_AFFECTS_MELEE_ABILITY_CASTTIME                = 0x00002000, // TITLE Haste Affects Melee Ability Casttime
    SPELL_ATTR9_IGNORE_DEFAULT_RATED_BATTLEGROUND_RESTRICTIONS      = 0x00004000, // TITLE Ignore Default Rated Battleground Restrictions
    SPELL_ATTR9_DO_NOT_DISPLAY_POWER_COST                           = 0x00008000, // TITLE Do Not Display Power Cost (client only)
    SPELL_ATTR9_NEXT_MODAL_SPELL_REQUIRES_SAME_UNIT_TARGET          = 0x00010000, // TITLE Next modal spell requires same unit target DESCRIPTION Prevents automatically casting the spell from SpellClassOptions::ModalNextSpell after current spell if target was changed (client only)
    SPELL_ATTR9_AUTOCAST_OFF_BY_DEFAULT                             = 0x00020000, // TITLE AutoCast Off By Default
    SPELL_ATTR9_IGNORE_SCHOOL_LOCKOUT                               = 0x00040000, // TITLE Ignore School Lockout
    SPELL_ATTR9_ALLOW_DARK_SIMULACRUM                               = 0x00080000, // TITLE Allow Dark Simulacrum
    SPELL_ATTR9_ALLOW_CAST_WHILE_CHANNELING                         = 0x00100000, // TITLE Allow Cast While Channeling
    SPELL_ATTR9_SUPPRESS_VISUAL_KIT_ERRORS                          = 0x00200000, // TITLE Suppress Visual Kit Errors (client only)
    SPELL_ATTR9_SPELLCAST_OVERRIDE_IN_SPELLBOOK                     = 0x00400000, // TITLE Spellcast Override In Spellbook (client only)
    SPELL_ATTR9_JUMPCHARGE__NO_FACING_CONTROL                       = 0x00800000, // TITLE JumpCharge - no facing control
    SPELL_ATTR9_IGNORE_CASTER_HEALING_MODIFIERS                     = 0x01000000, // TITLE Ignore Caster Healing Modifiers
    SPELL_ATTR9_DONT_CONSUME_CHARGE_IF_ITEM_DELETED                 = 0x02000000, /*NYI - some sort of bugfix attribute to prevent double item deletion?*/ // TITLE (Programmer Only) Don't consume charge if item deleted
    SPELL_ATTR9_ITEM_PASSIVE_ON_CLIENT                              = 0x04000000, // TITLE Item Passive On Client
    SPELL_ATTR9_FORCE_CORPSE_TARGET                                 = 0x08000000, // TITLE Force Corpse Target DESCRIPTION Causes the spell to continue executing effects on the target even if one of them kills it
    SPELL_ATTR9_CANNOT_KILL_TARGET                                  = 0x10000000, // TITLE Cannot Kill Target
    SPELL_ATTR9_LOG_PASSIVE                                         = 0x20000000, // TITLE Log Passive (client only) DESCRIPTION Allows passive auras to trigger aura applied/refreshed/removed combat log events
    SPELL_ATTR9_NO_MOVEMENT_RADIUS_BONUS                            = 0x40000000, // TITLE No Movement Radius Bonus
    SPELL_ATTR9_CHANNEL_PERSISTS_ON_PET_FOLLOW                      = 0x80000000  // TITLE Channel Persists on Pet Follow
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr10 : uint32
{
    SPELL_ATTR10_UNK0                            = 0x00000001, // TITLE Unknown attribute 0@Attr10
    SPELL_ATTR10_UNK1                            = 0x00000002, // TITLE Unknown attribute 1@Attr10
    SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY  = 0x00000004, // TITLE Uses Ranged Slot (Cosmetic Only)
    SPELL_ATTR10_UNK3                            = 0x00000008, // TITLE Unknown attribute 3@Attr10
    SPELL_ATTR10_WATER_SPOUT                     = 0x00000010, // TITLE NPC Knockback - ignore doors
    SPELL_ATTR10_UNK5                            = 0x00000020, // TITLE Unknown attribute 5@Attr10
    SPELL_ATTR10_UNK6                            = 0x00000040, // TITLE Unknown attribute 6@Attr10
    SPELL_ATTR10_TELEPORT_PLAYER                 = 0x00000080, // TITLE Ignore instance lock and farm limit on teleport
    SPELL_ATTR10_UNK8                            = 0x00000100, // TITLE Unknown attribute 8@Attr10
    SPELL_ATTR10_UNK9                            = 0x00000200, // TITLE Unknown attribute 9@Attr10
    SPELL_ATTR10_UNK10                           = 0x00000400, // TITLE Unknown attribute 10@Attr10
    SPELL_ATTR10_HERB_GATHERING_MINING           = 0x00000800, // TITLE Lock chest at precast
    SPELL_ATTR10_USE_SPELL_BASE_LEVEL_FOR_SCALING= 0x00001000, // TITLE Use Spell Base Level For Scaling
    SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END = 0x00002000, // TITLE Reset cooldown upon ending an encounter
    SPELL_ATTR10_ROLLING_PERIODIC                = 0x00004000, // TITLE Rolling Periodic DESCRIPTION Add remaining periodic damage to new aura when refreshed
    SPELL_ATTR10_UNK15                           = 0x00008000, // TITLE Unknown attribute 15@Attr10
    SPELL_ATTR10_UNK16                           = 0x00010000, // TITLE Unknown attribute 16@Attr10
    SPELL_ATTR10_CAN_DODGE_PARRY_WHILE_CASTING   = 0x00020000, // TITLE Allow Defense While Casting
    SPELL_ATTR10_UNK18                           = 0x00040000, // TITLE Unknown attribute 18@Attr10
    SPELL_ATTR10_UNK19                           = 0x00080000, // TITLE Unknown attribute 19@Attr10
    SPELL_ATTR10_UNK20                           = 0x00100000, // TITLE Unknown attribute 20@Attr10
    SPELL_ATTR10_UNK21                           = 0x00200000, // TITLE Unknown attribute 21@Attr10
    SPELL_ATTR10_UNK22                           = 0x00400000, // TITLE Unknown attribute 22@Attr10
    SPELL_ATTR10_UNK23                           = 0x00800000, // TITLE Unknown attribute 23@Attr10
    SPELL_ATTR10_UNK24                           = 0x01000000, // TITLE Unknown attribute 24@Attr10
    SPELL_ATTR10_UNK25                           = 0x02000000, // TITLE Unknown attribute 25@Attr10
    SPELL_ATTR10_UNK26                           = 0x04000000, // TITLE Unknown attribute 26@Attr10
    SPELL_ATTR10_UNK27                           = 0x08000000, // TITLE Unknown attribute 27@Attr10
    SPELL_ATTR10_UNK28                           = 0x10000000, // TITLE Unknown attribute 28@Attr10
    SPELL_ATTR10_MOUNT_IS_NOT_ACCOUNT_WIDE       = 0x20000000, // TITLE This Mount is NOT at the account level
    SPELL_ATTR10_UNK30                           = 0x40000000, // TITLE Unknown attribute 30@Attr10
    SPELL_ATTR10_UNK31                           = 0x80000000  // TITLE Unknown attribute 31@Attr10
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr11 : uint32
{
    SPELL_ATTR11_UNK0                            = 0x00000001, // TITLE Unknown attribute 0@Attr11
    SPELL_ATTR11_UNK1                            = 0x00000002, // TITLE Unknown attribute 1@Attr11
    SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL          = 0x00000004, // TITLE Scales with Casting Item's Level
    SPELL_ATTR11_UNK3                            = 0x00000008, // TITLE Unknown attribute 3@Attr11
    SPELL_ATTR11_UNK4                            = 0x00000010, // TITLE Unknown attribute 4@Attr11
    SPELL_ATTR11_ABSORB_ENVIRONMENTAL_DAMAGE     = 0x00000020, // TITLE Absorb Falling Damage
    SPELL_ATTR11_UNK6                            = 0x00000040, // TITLE Unknown attribute 6@Attr11
    SPELL_ATTR11_RANK_IGNORES_CASTER_LEVEL       = 0x00000080, // TITLE Ignore Caster's spell level DESCRIPTION Spell_C_GetSpellRank returns SpellLevels->MaxLevel * 5 instead of std::min(SpellLevels->MaxLevel, caster->Level) * 5
    SPELL_ATTR11_UNK8                            = 0x00000100, // TITLE Unknown attribute 8@Attr11
    SPELL_ATTR11_IGNORE_SPELLCAST_OVERRIDE_SHAPESHIFT_REQUIREMENTS  = 0x00000200, // TITLE Ignore Spellcast Override Shapeshift Requirements
    SPELL_ATTR11_UNK10                           = 0x00000400, // TITLE Unknown attribute 10@Attr11
    SPELL_ATTR11_NOT_USABLE_IN_INSTANCES         = 0x00000800, // TITLE Not in Instances
    SPELL_ATTR11_UNK12                           = 0x00001000, // TITLE Unknown attribute 12@Attr11
    SPELL_ATTR11_UNK13                           = 0x00002000, // TITLE Unknown attribute 13@Attr11
    SPELL_ATTR11_UNK14                           = 0x00004000, // TITLE Unknown attribute 14@Attr11
    SPELL_ATTR11_UNK15                           = 0x00008000, // TITLE Unknown attribute 15@Attr11
    SPELL_ATTR11_NOT_USABLE_IN_CHALLENGE_MODE    = 0x00010000, // TITLE Not in Mythic+ Mode (Challenge Mode)
    SPELL_ATTR11_UNK17                           = 0x00020000, // TITLE Unknown attribute 17@Attr11
    SPELL_ATTR11_UNK18                           = 0x00040000, // TITLE Unknown attribute 18@Attr11
    SPELL_ATTR11_UNK19                           = 0x00080000, // TITLE Unknown attribute 19@Attr11
    SPELL_ATTR11_UNK20                           = 0x00100000, // TITLE Unknown attribute 20@Attr11
    SPELL_ATTR11_UNK21                           = 0x00200000, // TITLE Unknown attribute 21@Attr11
    SPELL_ATTR11_UNK22                           = 0x00400000, // TITLE Unknown attribute 22@Attr11
    SPELL_ATTR11_UNK23                           = 0x00800000, // TITLE Unknown attribute 23@Attr11
    SPELL_ATTR11_UNK24                           = 0x01000000, // TITLE Unknown attribute 24@Attr11
    SPELL_ATTR11_UNK25                           = 0x02000000, // TITLE Unknown attribute 25@Attr11
    SPELL_ATTR11_UNK26                           = 0x04000000, // TITLE Unknown attribute 26@Attr11
    SPELL_ATTR11_UNK27                           = 0x08000000, // TITLE Unknown attribute 27@Attr11
    SPELL_ATTR11_UNK28                           = 0x10000000, // TITLE Unknown attribute 28@Attr11
    SPELL_ATTR11_UNK29                           = 0x20000000, // TITLE Unknown attribute 29@Attr11
    SPELL_ATTR11_UNK30                           = 0x40000000, // TITLE Unknown attribute 30@Attr11
    SPELL_ATTR11_UNK31                           = 0x80000000  // TITLE Unknown attribute 31@Attr11
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr12 : uint32
{
    SPELL_ATTR12_ENABLE_PROCS_FROM_SUPPRESSED_CASTER_PROCS          = 0x00000001, // TITLE Enable Procs from Suppressed Caster Procs
    SPELL_ATTR12_CAN_PROC_FROM_SUPPRESSED_CASTER_PROCS              = 0x00000002, // TITLE Can Proc from Suppressed Caster Procs
    SPELL_ATTR12_UNK2                            = 0x00000004, // TITLE Unknown attribute 2@Attr12
    SPELL_ATTR12_UNK3                            = 0x00000008, // TITLE Unknown attribute 3@Attr12
    SPELL_ATTR12_UNK4                            = 0x00000010, // TITLE Unknown attribute 4@Attr12
    SPELL_ATTR12_UNK5                            = 0x00000020, // TITLE Unknown attribute 5@Attr12
    SPELL_ATTR12_UNK6                            = 0x00000040, // TITLE Unknown attribute 6@Attr12
    SPELL_ATTR12_UNK7                            = 0x00000080, // TITLE Unknown attribute 7@Attr12
    SPELL_ATTR12_UNK8                            = 0x00000100, // TITLE Unknown attribute 8@Attr12
    SPELL_ATTR12_IGNORE_CASTING_DISABLED         = 0x00000200, // TITLE Active Passive DESCRIPTION Ignores aura 263 SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES
    SPELL_ATTR12_UNK10                           = 0x00000400, // TITLE Unknown attribute 10@Attr12
    SPELL_ATTR12_UNK11                           = 0x00000800, // TITLE Unknown attribute 11@Attr12
    SPELL_ATTR12_UNK12                           = 0x00001000, // TITLE Unknown attribute 12@Attr12
    SPELL_ATTR12_UNK13                           = 0x00002000, // TITLE Unknown attribute 13@Attr12
    SPELL_ATTR12_UNK14                           = 0x00004000, // TITLE Unknown attribute 14@Attr12
    SPELL_ATTR12_UNK15                           = 0x00008000, // TITLE Unknown attribute 15@Attr12
    SPELL_ATTR12_UNK16                           = 0x00010000, // TITLE Unknown attribute 16@Attr12
    SPELL_ATTR12_UNK17                           = 0x00020000, // TITLE Unknown attribute 17@Attr12
    SPELL_ATTR12_UNK18                           = 0x00040000, // TITLE Unknown attribute 18@Attr12
    SPELL_ATTR12_UNK19                           = 0x00080000, // TITLE Unknown attribute 19@Attr12
    SPELL_ATTR12_UNK20                           = 0x00100000, // TITLE Unknown attribute 20@Attr12
    SPELL_ATTR12_UNK21                           = 0x00200000, // TITLE Unknown attribute 21@Attr12
    SPELL_ATTR12_UNK22                           = 0x00400000, // TITLE Unknown attribute 22@Attr12
    SPELL_ATTR12_START_COOLDOWN_ON_CAST_START    = 0x00800000, // TITLE Trigger Cooldown On Spell Start
    SPELL_ATTR12_IS_GARRISON_BUFF                = 0x01000000, // TITLE Never Learn
    SPELL_ATTR12_UNK25                           = 0x02000000, // TITLE Unknown attribute 25@Attr12
    SPELL_ATTR12_UNK26                           = 0x04000000, // TITLE Unknown attribute 26@Attr12
    SPELL_ATTR12_IS_READINESS_SPELL              = 0x08000000, // TITLE Recompute Aura on Mercenary Mode
    SPELL_ATTR12_UNK28                           = 0x10000000, // TITLE Unknown attribute 28@Attr12
    SPELL_ATTR12_UNK29                           = 0x20000000, // TITLE Unknown attribute 29@Attr12
    SPELL_ATTR12_UNK30                           = 0x40000000, // TITLE Unknown attribute 30@Attr12
    SPELL_ATTR12_ONLY_PROC_FROM_CLASS_ABILITIES                     = 0x80000000  // TITLE Only Proc From Class Abilities
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr13 : uint32
{
    SPELL_ATTR13_ALLOW_CLASS_ABILITY_PROCS       = 0x00000001, // TITLE Allow Class Ability Procs
    SPELL_ATTR13_UNK1                            = 0x00000002, // TITLE Unknown attribute 0@Attr13
    SPELL_ATTR13_PASSIVE_IS_UPGRADE              = 0x00000004, // TITLE Is Upgrade DESCRIPTION Displays "Upgrade" in spell tooltip instead of "Passive"
    SPELL_ATTR13_UNK3                            = 0x00000008, // TITLE Unknown attribute 3@Attr13
    SPELL_ATTR13_UNK4                            = 0x00000010, // TITLE Unknown attribute 4@Attr13
    SPELL_ATTR13_UNK5                            = 0x00000020, // TITLE Unknown attribute 5@Attr13
    SPELL_ATTR13_UNK6                            = 0x00000040, // TITLE Unknown attribute 6@Attr13
    SPELL_ATTR13_UNK7                            = 0x00000080, // TITLE Unknown attribute 7@Attr13
    SPELL_ATTR13_UNK8                            = 0x00000100, // TITLE Unknown attribute 8@Attr13
    SPELL_ATTR13_UNK9                            = 0x00000200, // TITLE Unknown attribute 9@Attr13
    SPELL_ATTR13_UNK10                           = 0x00000400, // TITLE Unknown attribute 10@Attr13
    SPELL_ATTR13_UNK11                           = 0x00000800, // TITLE Unknown attribute 11@Attr13
    SPELL_ATTR13_UNK12                           = 0x00001000, // TITLE Unknown attribute 12@Attr13
    SPELL_ATTR13_UNK13                           = 0x00002000, // TITLE Unknown attribute 13@Attr13
    SPELL_ATTR13_UNK14                           = 0x00004000, // TITLE Unknown attribute 14@Attr13
    SPELL_ATTR13_UNK15                           = 0x00008000, // TITLE Unknown attribute 15@Attr13
    SPELL_ATTR13_UNK16                           = 0x00010000, // TITLE Unknown attribute 16@Attr13
    SPELL_ATTR13_UNK17                           = 0x00020000, // TITLE Unknown attribute 17@Attr13
    SPELL_ATTR13_ACTIVATES_REQUIRED_SHAPESHIFT   = 0x00040000, // TITLE Do Not Enforce Shapeshift Requirements
    SPELL_ATTR13_UNK19                           = 0x00080000, // TITLE Unknown attribute 19@Attr13
    SPELL_ATTR13_PERIODIC_REFRESH_EXTENDS_DURATION = 0x00100000, // TITLE Periodic Refresh Extends Duration
    SPELL_ATTR13_UNK21                           = 0x00200000, // TITLE Unknown attribute 21@Attr13
    SPELL_ATTR13_UNK22                           = 0x00400000, // TITLE Unknown attribute 22@Attr13
    SPELL_ATTR13_UNK23                           = 0x00800000, // TITLE Unknown attribute 23@Attr13
    SPELL_ATTR13_UNK24                           = 0x01000000, // TITLE Unknown attribute 24@Attr13
    SPELL_ATTR13_UNK25                           = 0x02000000, // TITLE Unknown attribute 25@Attr13
    SPELL_ATTR13_ALWAYS_ALLOW_NEGATIVE_HEALING_PERCENT_MODIFIERS    = 0x04000000, // TITLE Always Allow Negative Healing Percent Modifiers
    SPELL_ATTR13_DO_NOT_ALLOW_DISABLE_MOVEMENT_INTERRUPT            = 0x08000000, // TITLE Do Not Allow "Disable Movement Interrupt"
    SPELL_ATTR13_UNK28                           = 0x10000000, // TITLE Unknown attribute 28@Attr13
    SPELL_ATTR13_UNK29                           = 0x20000000, // TITLE Unknown attribute 29@Attr13
    SPELL_ATTR13_UNK30                           = 0x40000000, // TITLE Unknown attribute 30@Attr13
    SPELL_ATTR13_UNK31                           = 0x80000000  // TITLE Unknown attribute 31@Attr13
};

// EnumUtils: DESCRIBE THIS
enum SpellAttr14 : uint32
{
    SPELL_ATTR14_UNK0                            = 0x00000001, // TITLE Unknown attribute 0@Attr14
    SPELL_ATTR14_REAGENT_COST_CONSUMES_CHARGES   = 0x00000002, // TITLE Reagent Consume Charges DESCRIPTION Consumes item charges for reagent costs instead of whole items
    SPELL_ATTR14_UNK2                            = 0x00000004, // TITLE Unknown attribute 2@Attr14
    SPELL_ATTR14_HIDE_PASSIVE_FROM_TOOLTIP       = 0x00000008, // TITLE Don't show "Passive" or "Upgrade" in tooltip
    SPELL_ATTR14_UNK4                            = 0x00000010, // TITLE Unknown attribute 4@Attr14
    SPELL_ATTR14_UNK5                            = 0x00000020, // TITLE Unknown attribute 5@Attr14
    SPELL_ATTR14_UNK6                            = 0x00000040, // TITLE Unknown attribute 6@Attr14
    SPELL_ATTR14_UNK7                            = 0x00000080, // TITLE Unknown attribute 7@Attr14
    SPELL_ATTR14_UNK8                            = 0x00000100, // TITLE Unknown attribute 8@Attr14
    SPELL_ATTR14_UNK9                            = 0x00000200, // TITLE Unknown attribute 9@Attr14
    SPELL_ATTR14_UNK10                           = 0x00000400, // TITLE Unknown attribute 10@Attr14
    SPELL_ATTR14_UNK11                           = 0x00000800, // TITLE Unknown attribute 11@Attr14
    SPELL_ATTR14_UNK12                           = 0x00001000, // TITLE Unknown attribute 12@Attr14
    SPELL_ATTR14_UNK13                           = 0x00002000, // TITLE Unknown attribute 13@Attr14
    SPELL_ATTR14_UNK14                           = 0x00004000, // TITLE Unknown attribute 14@Attr14
    SPELL_ATTR14_UNK15                           = 0x00008000, // TITLE Unknown attribute 15@Attr14
    SPELL_ATTR14_UNK16                           = 0x00010000, // TITLE Unknown attribute 16@Attr14
    SPELL_ATTR14_UNK17                           = 0x00020000, // TITLE Unknown attribute 17@Attr14
    SPELL_ATTR14_UNK18                           = 0x00040000, // TITLE Unknown attribute 18@Attr14
    SPELL_ATTR14_UNK19                           = 0x00080000, // TITLE Unknown attribute 19@Attr14
    SPELL_ATTR14_AURA_IS_PRIVATE                                        = 0x00100000, // TITLE Aura is private DESCRIPTION Clientside attribue that prevents the aura from being accessed by addons (but is still visible in UI)
    SPELL_ATTR14_UNK21                           = 0x00200000, // TITLE Unknown attribute 21@Attr14
    SPELL_ATTR14_UNK22                           = 0x00400000, // TITLE Unknown attribute 22@Attr14
    SPELL_ATTR14_UNK23                           = 0x00800000, // TITLE Unknown attribute 23@Attr14
    SPELL_ATTR14_UNK24                           = 0x01000000, // TITLE Unknown attribute 24@Attr14
    SPELL_ATTR14_UNK25                           = 0x02000000, // TITLE Unknown attribute 25@Attr14
    SPELL_ATTR14_UNK26                           = 0x04000000, // TITLE Unknown attribute 26@Attr14
    SPELL_ATTR14_UNK27                           = 0x08000000, // TITLE Unknown attribute 27@Attr14
    SPELL_ATTR14_UNK28                           = 0x10000000, // TITLE Unknown attribute 28@Attr14
    SPELL_ATTR14_UNK29                           = 0x20000000, // TITLE Unknown attribute 29@Attr14
    SPELL_ATTR14_UNK30                           = 0x40000000, // TITLE Unknown attribute 30@Attr14
    SPELL_ATTR14_UNK31                           = 0x80000000  // TITLE Unknown attribute 31@Attr14
};

#define MIN_SPECIALIZATION_LEVEL    10
#define MAX_SPECIALIZATIONS         5
#define PET_SPEC_OVERRIDE_CLASS_INDEX MAX_CLASSES
#define INITIAL_SPECIALIZATION_INDEX 4

// Custom values
enum SpellClickUserTypes
{
    SPELL_CLICK_USER_ANY    = 0,
    SPELL_CLICK_USER_FRIEND = 1,
    SPELL_CLICK_USER_RAID   = 2,
    SPELL_CLICK_USER_PARTY  = 3,
    SPELL_CLICK_USER_MAX    = 4
};

enum SpellClickCastFlags
{
    NPC_CLICK_CAST_CASTER_CLICKER       = 0x01,
    NPC_CLICK_CAST_TARGET_CLICKER       = 0x02,
    NPC_CLICK_CAST_ORIG_CASTER_OWNER    = 0x04
};

enum SheathTypes
{
    SHEATHETYPE_NONE                   = 0,
    SHEATHETYPE_MAINHAND               = 1,
    SHEATHETYPE_OFFHAND                = 2,
    SHEATHETYPE_LARGEWEAPONLEFT        = 3,
    SHEATHETYPE_LARGEWEAPONRIGHT       = 4,
    SHEATHETYPE_HIPWEAPONLEFT          = 5,
    SHEATHETYPE_HIPWEAPONRIGHT         = 6,
    SHEATHETYPE_SHIELD                 = 7
};

#define MAX_SHEATHETYPE                  8

enum CharacterFlags
{
    CHARACTER_FLAG_NONE                 = 0x00000000,
    CHARACTER_FLAG_UNK1                 = 0x00000001,
    CHARACTER_FLAG_RESTING              = 0x00000002,
    CHARACTER_FLAG_LOCKED_FOR_TRANSFER  = 0x00000004,
    CHARACTER_FLAG_UNK4                 = 0x00000008,
    CHARACTER_FLAG_UNK5                 = 0x00000010,
    CHARACTER_FLAG_UNK6                 = 0x00000020,
    CHARACTER_FLAG_UNK7                 = 0x00000040,
    CHARACTER_FLAG_UNK8                 = 0x00000080,
    CHARACTER_FLAG_UNK9                 = 0x00000100,
    CHARACTER_FLAG_UNK10                = 0x00000200,
    CHARACTER_FLAG_HIDE_HELM            = 0x00000400,
    CHARACTER_FLAG_HIDE_CLOAK           = 0x00000800,
    CHARACTER_FLAG_UNK13                = 0x00001000,
    CHARACTER_FLAG_GHOST                = 0x00002000,
    CHARACTER_FLAG_RENAME               = 0x00004000,
    CHARACTER_FLAG_UNK16                = 0x00008000,
    CHARACTER_FLAG_UNK17                = 0x00010000,
    CHARACTER_FLAG_UNK18                = 0x00020000,
    CHARACTER_FLAG_UNK19                = 0x00040000,
    CHARACTER_FLAG_UNK20                = 0x00080000,
    CHARACTER_FLAG_UNK21                = 0x00100000,
    CHARACTER_FLAG_UNK22                = 0x00200000,
    CHARACTER_FLAG_UNK23                = 0x00400000,
    CHARACTER_FLAG_UNK24                = 0x00800000,
    CHARACTER_FLAG_LOCKED_BY_BILLING    = 0x01000000,
    CHARACTER_FLAG_DECLINED             = 0x02000000,
    CHARACTER_FLAG_UNK27                = 0x04000000,
    CHARACTER_FLAG_UNK28                = 0x08000000,
    CHARACTER_FLAG_UNK29                = 0x10000000,
    CHARACTER_FLAG_UNK30                = 0x20000000,
    CHARACTER_FLAG_UNK31                = 0x40000000,
    CHARACTER_FLAG_UNK32                = 0x80000000
};

enum CharacterCustomizeFlags
{
    CHAR_CUSTOMIZE_FLAG_NONE            = 0x00000000,
    CHAR_CUSTOMIZE_FLAG_CUSTOMIZE       = 0x00000001, // name, gender, etc...
    CHAR_CUSTOMIZE_FLAG_FACTION         = 0x00010000, // name, gender, faction, etc...
    CHAR_CUSTOMIZE_FLAG_RACE            = 0x00100000  // name, gender, race, etc...
};

enum CharacterFlags3 : uint32
{
    CHARACTER_FLAG_3_LOCKED_BY_REVOKED_VAS_TRANSACTION      = 0x00100000,
    CHARACTER_FLAG_3_LOCKED_BY_REVOKED_CHARACTER_UPGRADE    = 0x80000000,
};

enum CharacterFlags4 : uint32
{
    CHARACTER_FLAG_4_TRIAL_BOOST        = 0x00000080,
    CHARACTER_FLAG_4_TRIAL_BOOST_LOCKED = 0x00040000,
    CHARACTER_FLAG_4_EXPANSION_TRIAL    = 0x00080000,
};

// Languages.db2 (9.2.0.42423)
enum Language
{
    LANG_UNIVERSAL          = 0,
    LANG_ORCISH             = 1,
    LANG_DARNASSIAN         = 2,
    LANG_TAURAHE            = 3,
    LANG_DWARVISH           = 6,
    LANG_COMMON             = 7,
    LANG_DEMONIC            = 8,
    LANG_TITAN              = 9,
    LANG_THALASSIAN         = 10,
    LANG_DRACONIC           = 11,
    LANG_KALIMAG            = 12,
    LANG_GNOMISH            = 13,
    LANG_TROLL              = 14,
    LANG_GUTTERSPEAK        = 33,
    LANG_DRAENEI            = 35,
    LANG_ZOMBIE             = 36,
    LANG_GNOMISH_BINARY     = 37,
    LANG_GOBLIN_BINARY      = 38,
    LANG_WORGEN             = 39,
    LANG_GOBLIN             = 40,
    LANG_PANDAREN_NEUTRAL   = 42,
    LANG_PANDAREN_ALLIANCE  = 43,
    LANG_PANDAREN_HORDE     = 44,
    LANG_SPRITE             = 168,
    LANG_SHATH_YAR          = 178,
    LANG_NERGLISH           = 179,
    LANG_MOONKIN            = 180,
    LANG_SHALASSIAN         = 181,
    LANG_THALASSIAN_2       = 182,
    LANG_ADDON              = 183,
    LANG_ADDON_LOGGED       = 184,
    LANG_VULPERA            = 285,
    LANG_COMPLEX_CIPHER     = 287,
    LANG_BASIC_CYPHER       = 288,
    LANG_METRIAL            = 290,
    LANG_ALTONIAN           = 291,
    LANG_SOPRANIAN          = 292,
    LANG_AEALIC             = 293,
    LANG_DEALIC             = 294,
    LANG_TREBELIM           = 295,
    LANG_BASSALIM           = 296,
    LANG_EMBEDDED_LANGUAGES = 297,
    LANG_UNKNOWABLE         = 298,
};

enum TeamId
{
    TEAM_ALLIANCE = 0,
    TEAM_HORDE,
    TEAM_NEUTRAL
};

constexpr TeamId GetOtherTeam(TeamId team)
{
    switch (team)
    {
        case TEAM_ALLIANCE:
            return TEAM_HORDE;
        case TEAM_HORDE:
            return TEAM_ALLIANCE;
        default:
            break;
    }
    return TEAM_NEUTRAL;
}

enum Team
{
    HORDE               = 67,
    ALLIANCE            = 469,
    PANDARIA_NEUTRAL    = 1249,                             // Starting pandas should have this team
    TEAM_OTHER          = 0                                 // if ReputationListId > 0 && Flags != FACTION_FLAG_TEAM_HEADER
};

constexpr Team GetOtherTeam(Team team)
{
    switch (team)
    {
        case HORDE:
            return ALLIANCE;
        case ALLIANCE:
            return HORDE;
        case PANDARIA_NEUTRAL:
            return PANDARIA_NEUTRAL;
        default:
            break;
    }
    return TEAM_OTHER;
}

constexpr TeamId GetTeamIdForTeam(Team team)
{
    switch (team)
    {
        case HORDE:
            return TEAM_HORDE;
        case ALLIANCE:
            return TEAM_ALLIANCE;
        default:
            break;
    }
    return TEAM_NEUTRAL;
}

enum SpellEffectName
{
    SPELL_EFFECT_NONE                               = 0,
    SPELL_EFFECT_INSTAKILL                          = 1,
    SPELL_EFFECT_SCHOOL_DAMAGE                      = 2,
    SPELL_EFFECT_DUMMY                              = 3,
    SPELL_EFFECT_PORTAL_TELEPORT                    = 4, // Unused (4.3.4)
    SPELL_EFFECT_5                                  = 5,
    SPELL_EFFECT_APPLY_AURA                         = 6,
    SPELL_EFFECT_ENVIRONMENTAL_DAMAGE               = 7,
    SPELL_EFFECT_POWER_DRAIN                        = 8,
    SPELL_EFFECT_HEALTH_LEECH                       = 9,
    SPELL_EFFECT_HEAL                               = 10,
    SPELL_EFFECT_BIND                               = 11,
    SPELL_EFFECT_PORTAL                             = 12,
    SPELL_EFFECT_TELEPORT_TO_RETURN_POINT           = 13, // MiscValueA = spellid of the aura holding destination
    SPELL_EFFECT_INCREASE_CURRENCY_CAP              = 14,
    SPELL_EFFECT_TELEPORT_WITH_SPELL_VISUAL_KIT_LOADING_SCREEN = 15, // MiscValueA = delay, MiscValueB = SpellVisualKitId
    SPELL_EFFECT_QUEST_COMPLETE                     = 16,
    SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL             = 17,
    SPELL_EFFECT_RESURRECT                          = 18,
    SPELL_EFFECT_ADD_EXTRA_ATTACKS                  = 19,
    SPELL_EFFECT_DODGE                              = 20,
    SPELL_EFFECT_EVADE                              = 21,
    SPELL_EFFECT_PARRY                              = 22,
    SPELL_EFFECT_BLOCK                              = 23,
    SPELL_EFFECT_CREATE_ITEM                        = 24,
    SPELL_EFFECT_WEAPON                             = 25,
    SPELL_EFFECT_DEFENSE                            = 26,
    SPELL_EFFECT_PERSISTENT_AREA_AURA               = 27,
    SPELL_EFFECT_SUMMON                             = 28,
    SPELL_EFFECT_LEAP                               = 29,
    SPELL_EFFECT_ENERGIZE                           = 30,
    SPELL_EFFECT_WEAPON_PERCENT_DAMAGE              = 31,
    SPELL_EFFECT_TRIGGER_MISSILE                    = 32,
    SPELL_EFFECT_OPEN_LOCK                          = 33,
    SPELL_EFFECT_SUMMON_CHANGE_ITEM                 = 34,
    SPELL_EFFECT_APPLY_AREA_AURA_PARTY              = 35,
    SPELL_EFFECT_LEARN_SPELL                        = 36,
    SPELL_EFFECT_SPELL_DEFENSE                      = 37,
    SPELL_EFFECT_DISPEL                             = 38,
    SPELL_EFFECT_LANGUAGE                           = 39,
    SPELL_EFFECT_DUAL_WIELD                         = 40,
    SPELL_EFFECT_JUMP                               = 41,
    SPELL_EFFECT_JUMP_DEST                          = 42,
    SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER         = 43,
    SPELL_EFFECT_SKILL_STEP                         = 44,
    SPELL_EFFECT_PLAY_MOVIE                         = 45,
    SPELL_EFFECT_SPAWN                              = 46,
    SPELL_EFFECT_TRADE_SKILL                        = 47,
    SPELL_EFFECT_STEALTH                            = 48,
    SPELL_EFFECT_DETECT                             = 49,
    SPELL_EFFECT_TRANS_DOOR                         = 50,
    SPELL_EFFECT_FORCE_CRITICAL_HIT                 = 51, // Unused (4.3.4)
    SPELL_EFFECT_SET_MAX_BATTLE_PET_COUNT           = 52,
    SPELL_EFFECT_ENCHANT_ITEM                       = 53,
    SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY             = 54,
    SPELL_EFFECT_TAMECREATURE                       = 55,
    SPELL_EFFECT_SUMMON_PET                         = 56,
    SPELL_EFFECT_LEARN_PET_SPELL                    = 57,
    SPELL_EFFECT_WEAPON_DAMAGE                      = 58,
    SPELL_EFFECT_CREATE_RANDOM_ITEM                 = 59,
    SPELL_EFFECT_PROFICIENCY                        = 60,
    SPELL_EFFECT_SEND_EVENT                         = 61,
    SPELL_EFFECT_POWER_BURN                         = 62,
    SPELL_EFFECT_THREAT                             = 63,
    SPELL_EFFECT_TRIGGER_SPELL                      = 64,
    SPELL_EFFECT_APPLY_AREA_AURA_RAID               = 65,
    SPELL_EFFECT_RECHARGE_ITEM                      = 66,
    SPELL_EFFECT_HEAL_MAX_HEALTH                    = 67,
    SPELL_EFFECT_INTERRUPT_CAST                     = 68,
    SPELL_EFFECT_DISTRACT                           = 69,
    SPELL_EFFECT_COMPLETE_AND_REWARD_WORLD_QUEST    = 70,
    SPELL_EFFECT_PICKPOCKET                         = 71,
    SPELL_EFFECT_ADD_FARSIGHT                       = 72,
    SPELL_EFFECT_UNTRAIN_TALENTS                    = 73,
    SPELL_EFFECT_APPLY_GLYPH                        = 74,
    SPELL_EFFECT_HEAL_MECHANICAL                    = 75,
    SPELL_EFFECT_SUMMON_OBJECT_WILD                 = 76,
    SPELL_EFFECT_SCRIPT_EFFECT                      = 77,
    SPELL_EFFECT_ATTACK                             = 78,
    SPELL_EFFECT_SANCTUARY                          = 79,
    SPELL_EFFECT_MODIFY_FOLLOWER_ITEM_LEVEL         = 80,
    SPELL_EFFECT_PUSH_ABILITY_TO_ACTION_BAR         = 81,
    SPELL_EFFECT_BIND_SIGHT                         = 82,
    SPELL_EFFECT_DUEL                               = 83,
    SPELL_EFFECT_STUCK                              = 84,
    SPELL_EFFECT_SUMMON_PLAYER                      = 85,
    SPELL_EFFECT_ACTIVATE_OBJECT                    = 86,
    SPELL_EFFECT_GAMEOBJECT_DAMAGE                  = 87,
    SPELL_EFFECT_GAMEOBJECT_REPAIR                  = 88,
    SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE   = 89,
    SPELL_EFFECT_KILL_CREDIT                        = 90,
    SPELL_EFFECT_THREAT_ALL                         = 91,
    SPELL_EFFECT_ENCHANT_HELD_ITEM                  = 92,
    SPELL_EFFECT_FORCE_DESELECT                     = 93,
    SPELL_EFFECT_SELF_RESURRECT                     = 94,
    SPELL_EFFECT_SKINNING                           = 95,
    SPELL_EFFECT_CHARGE                             = 96,
    SPELL_EFFECT_CAST_BUTTON                        = 97,
    SPELL_EFFECT_KNOCK_BACK                         = 98,
    SPELL_EFFECT_DISENCHANT                         = 99,
    SPELL_EFFECT_INEBRIATE                          = 100,
    SPELL_EFFECT_FEED_PET                           = 101,
    SPELL_EFFECT_DISMISS_PET                        = 102,
    SPELL_EFFECT_REPUTATION                         = 103,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT1                = 104,
    SPELL_EFFECT_SURVEY                             = 105,
    SPELL_EFFECT_CHANGE_RAID_MARKER                 = 106,
    SPELL_EFFECT_SHOW_CORPSE_LOOT                   = 107,
    SPELL_EFFECT_DISPEL_MECHANIC                    = 108,
    SPELL_EFFECT_RESURRECT_PET                      = 109,
    SPELL_EFFECT_DESTROY_ALL_TOTEMS                 = 110,
    SPELL_EFFECT_DURABILITY_DAMAGE                  = 111,
    SPELL_EFFECT_112                                = 112,
    SPELL_EFFECT_CANCEL_CONVERSATION                = 113,
    SPELL_EFFECT_ATTACK_ME                          = 114,
    SPELL_EFFECT_DURABILITY_DAMAGE_PCT              = 115,
    SPELL_EFFECT_SKIN_PLAYER_CORPSE                 = 116,
    SPELL_EFFECT_SPIRIT_HEAL                        = 117,
    SPELL_EFFECT_SKILL                              = 118,
    SPELL_EFFECT_APPLY_AREA_AURA_PET                = 119,
    SPELL_EFFECT_TELEPORT_GRAVEYARD                 = 120,
    SPELL_EFFECT_NORMALIZED_WEAPON_DMG              = 121,
    SPELL_EFFECT_122                                = 122,
    SPELL_EFFECT_SEND_TAXI                          = 123,
    SPELL_EFFECT_PULL_TOWARDS                       = 124,
    SPELL_EFFECT_MODIFY_THREAT_PERCENT              = 125,
    SPELL_EFFECT_STEAL_BENEFICIAL_BUFF              = 126,
    SPELL_EFFECT_PROSPECTING                        = 127,
    SPELL_EFFECT_APPLY_AREA_AURA_FRIEND             = 128,
    SPELL_EFFECT_APPLY_AREA_AURA_ENEMY              = 129,
    SPELL_EFFECT_REDIRECT_THREAT                    = 130,
    SPELL_EFFECT_PLAY_SOUND                         = 131,
    SPELL_EFFECT_PLAY_MUSIC                         = 132,
    SPELL_EFFECT_UNLEARN_SPECIALIZATION             = 133,
    SPELL_EFFECT_KILL_CREDIT2                       = 134,
    SPELL_EFFECT_CALL_PET                           = 135,
    SPELL_EFFECT_HEAL_PCT                           = 136,
    SPELL_EFFECT_ENERGIZE_PCT                       = 137,
    SPELL_EFFECT_LEAP_BACK                          = 138,
    SPELL_EFFECT_CLEAR_QUEST                        = 139,
    SPELL_EFFECT_FORCE_CAST                         = 140,
    SPELL_EFFECT_FORCE_CAST_WITH_VALUE              = 141,
    SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE           = 142,
    SPELL_EFFECT_APPLY_AREA_AURA_OWNER              = 143,
    SPELL_EFFECT_KNOCK_BACK_DEST                    = 144,
    SPELL_EFFECT_PULL_TOWARDS_DEST                  = 145,
    SPELL_EFFECT_RESTORE_GARRISON_TROOP_VITALITY    = 146,
    SPELL_EFFECT_QUEST_FAIL                         = 147,
    SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE   = 148,
    SPELL_EFFECT_CHARGE_DEST                        = 149,
    SPELL_EFFECT_QUEST_START                        = 150,
    SPELL_EFFECT_TRIGGER_SPELL_2                    = 151,
    SPELL_EFFECT_SUMMON_RAF_FRIEND                  = 152,
    SPELL_EFFECT_CREATE_TAMED_PET                   = 153,
    SPELL_EFFECT_DISCOVER_TAXI                      = 154,
    SPELL_EFFECT_TITAN_GRIP                         = 155,
    SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC             = 156,
    SPELL_EFFECT_CREATE_LOOT                        = 157, // crafting loot
    SPELL_EFFECT_MILLING                            = 158,
    SPELL_EFFECT_ALLOW_RENAME_PET                   = 159,
    SPELL_EFFECT_FORCE_CAST_2                       = 160,
    SPELL_EFFECT_TALENT_SPEC_COUNT                  = 161,
    SPELL_EFFECT_TALENT_SPEC_SELECT                 = 162,
    SPELL_EFFECT_OBLITERATE_ITEM                    = 163,
    SPELL_EFFECT_REMOVE_AURA                        = 164,
    SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT         = 165,
    SPELL_EFFECT_GIVE_CURRENCY                      = 166,
    SPELL_EFFECT_UPDATE_PLAYER_PHASE                = 167,
    SPELL_EFFECT_ALLOW_CONTROL_PET                  = 168, // NYI
    SPELL_EFFECT_DESTROY_ITEM                       = 169,
    SPELL_EFFECT_UPDATE_ZONE_AURAS_AND_PHASES       = 170, // NYI
    SPELL_EFFECT_SUMMON_PERSONAL_GAMEOBJECT         = 171, // Summons gamebject
    SPELL_EFFECT_RESURRECT_WITH_AURA                = 172,
    SPELL_EFFECT_UNLOCK_GUILD_VAULT_TAB             = 173, // Guild tab unlocked (guild perk)
    SPELL_EFFECT_APPLY_AURA_ON_PET                  = 174, // NYI
    SPELL_EFFECT_175                                = 175,
    SPELL_EFFECT_SANCTUARY_2                        = 176, // NYI
    SPELL_EFFECT_DESPAWN_PERSISTENT_AREA_AURA       = 177,
    SPELL_EFFECT_178                                = 178,
    SPELL_EFFECT_CREATE_AREATRIGGER                 = 179,
    SPELL_EFFECT_UPDATE_AREATRIGGER                 = 180, // NYI
    SPELL_EFFECT_REMOVE_TALENT                      = 181,
    SPELL_EFFECT_DESPAWN_AREATRIGGER                = 182,
    SPELL_EFFECT_183                                = 183,
    SPELL_EFFECT_REPUTATION_2                       = 184,
    SPELL_EFFECT_185                                = 185,
    SPELL_EFFECT_186                                = 186,
    SPELL_EFFECT_RANDOMIZE_ARCHAEOLOGY_DIGSITES     = 187, // NYI
    SPELL_EFFECT_SUMMON_STABLED_PET_AS_GUARDIAN     = 188,
    SPELL_EFFECT_LOOT                               = 189, // NYI, lootid in MiscValue ?
    SPELL_EFFECT_CHANGE_PARTY_MEMBERS               = 190, // MiscValueA = 1 is join, MiscValueA = 0 is leave - used by NPCs
    SPELL_EFFECT_TELEPORT_TO_DIGSITE                = 191, // NYI
    SPELL_EFFECT_UNCAGE_BATTLEPET                   = 192,
    SPELL_EFFECT_START_PET_BATTLE                   = 193,
    SPELL_EFFECT_194                                = 194,
    SPELL_EFFECT_PLAY_SCENE_SCRIPT_PACKAGE          = 195,
    SPELL_EFFECT_CREATE_SCENE_OBJECT                = 196, // MiscValueA = SceneId, goes into guid as entry, SceneScriptPackageId goes into ObjectData::Entry
    SPELL_EFFECT_CREATE_PERSONAL_SCENE_OBJECT       = 197, // MiscValueA = SceneId, goes into guid as entry, SceneScriptPackageId goes into ObjectData::Entry
    SPELL_EFFECT_PLAY_SCENE                         = 198,
    SPELL_EFFECT_DESPAWN_SUMMON                     = 199, // MiscValueA is some kind of unknown internal id
    SPELL_EFFECT_HEAL_BATTLEPET_PCT                 = 200, // NYI
    SPELL_EFFECT_ENABLE_BATTLE_PETS                 = 201, // NYI
    SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS            = 202,
    SPELL_EFFECT_REMOVE_AURA_2                      = 203,
    SPELL_EFFECT_CHANGE_BATTLEPET_QUALITY           = 204,
    SPELL_EFFECT_LAUNCH_QUEST_CHOICE                = 205,
    SPELL_EFFECT_ALTER_ITEM                         = 206, // NYI
    SPELL_EFFECT_LAUNCH_QUEST_TASK                  = 207, // Starts one of the "progress bar" quests
    SPELL_EFFECT_SET_REPUTATION                     = 208,
    SPELL_EFFECT_209                                = 209,
    SPELL_EFFECT_LEARN_GARRISON_BUILDING            = 210,
    SPELL_EFFECT_LEARN_GARRISON_SPECIALIZATION      = 211,
    SPELL_EFFECT_REMOVE_AURA_BY_SPELL_LABEL         = 212,
    SPELL_EFFECT_JUMP_DEST_2                        = 213,
    SPELL_EFFECT_CREATE_GARRISON                    = 214,
    SPELL_EFFECT_UPGRADE_CHARACTER_SPELLS           = 215, // Unlocks boosted players' spells (ChrUpgrade*.db2)
    SPELL_EFFECT_CREATE_SHIPMENT                    = 216,
    SPELL_EFFECT_UPGRADE_GARRISON                   = 217,
    SPELL_EFFECT_218                                = 218,
    SPELL_EFFECT_CREATE_CONVERSATION                = 219,
    SPELL_EFFECT_ADD_GARRISON_FOLLOWER              = 220,
    SPELL_EFFECT_ADD_GARRISON_MISSION               = 221,
    SPELL_EFFECT_CREATE_HEIRLOOM_ITEM               = 222,
    SPELL_EFFECT_CHANGE_ITEM_BONUSES                = 223,
    SPELL_EFFECT_ACTIVATE_GARRISON_BUILDING         = 224,
    SPELL_EFFECT_GRANT_BATTLEPET_LEVEL              = 225,
    SPELL_EFFECT_TRIGGER_ACTION_SET                 = 226,
    SPELL_EFFECT_TELEPORT_TO_LFG_DUNGEON            = 227,
    SPELL_EFFECT_228                                = 228,
    SPELL_EFFECT_SET_FOLLOWER_QUALITY               = 229,
    SPELL_EFFECT_230                                = 230,
    SPELL_EFFECT_INCREASE_FOLLOWER_EXPERIENCE       = 231,
    SPELL_EFFECT_REMOVE_PHASE                       = 232,
    SPELL_EFFECT_RANDOMIZE_FOLLOWER_ABILITIES       = 233,
    SPELL_EFFECT_234                                = 234,
    SPELL_EFFECT_235                                = 235,
    SPELL_EFFECT_GIVE_EXPERIENCE                    = 236, // Increases players XP
    SPELL_EFFECT_GIVE_RESTED_EXPERIENCE_BONUS       = 237,
    SPELL_EFFECT_INCREASE_SKILL                     = 238,
    SPELL_EFFECT_END_GARRISON_BUILDING_CONSTRUCTION = 239, // Instantly finishes building construction
    SPELL_EFFECT_GIVE_ARTIFACT_POWER                = 240,
    SPELL_EFFECT_241                                = 241,
    SPELL_EFFECT_GIVE_ARTIFACT_POWER_NO_BONUS       = 242, // Unaffected by Artifact Knowledge
    SPELL_EFFECT_APPLY_ENCHANT_ILLUSION             = 243,
    SPELL_EFFECT_LEARN_FOLLOWER_ABILITY             = 244,
    SPELL_EFFECT_UPGRADE_HEIRLOOM                   = 245,
    SPELL_EFFECT_FINISH_GARRISON_MISSION            = 246,
    SPELL_EFFECT_ADD_GARRISON_MISSION_SET           = 247,
    SPELL_EFFECT_FINISH_SHIPMENT                    = 248,
    SPELL_EFFECT_FORCE_EQUIP_ITEM                   = 249,
    SPELL_EFFECT_TAKE_SCREENSHOT                    = 250, // Serverside marker for selfie screenshot - achievement check
    SPELL_EFFECT_SET_GARRISON_CACHE_SIZE            = 251,
    SPELL_EFFECT_TELEPORT_UNITS                     = 252,
    SPELL_EFFECT_GIVE_HONOR                         = 253,
    SPELL_EFFECT_JUMP_CHARGE                        = 254,
    SPELL_EFFECT_LEARN_TRANSMOG_SET                 = 255,
    SPELL_EFFECT_256                                = 256,
    SPELL_EFFECT_257                                = 257,
    SPELL_EFFECT_MODIFY_KEYSTONE                    = 258,
    SPELL_EFFECT_RESPEC_AZERITE_EMPOWERED_ITEM      = 259,
    SPELL_EFFECT_SUMMON_STABLED_PET                 = 260,
    SPELL_EFFECT_SCRAP_ITEM                         = 261,
    SPELL_EFFECT_262                                = 262,
    SPELL_EFFECT_REPAIR_ITEM                        = 263,
    SPELL_EFFECT_REMOVE_GEM                         = 264,
    SPELL_EFFECT_LEARN_AZERITE_ESSENCE_POWER        = 265,
    SPELL_EFFECT_SET_ITEM_BONUS_LIST_GROUP_ENTRY    = 266, // Sets item bonuses to specific ItemBonusListGroupEntry id
    SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION        = 267,
    SPELL_EFFECT_APPLY_MOUNT_EQUIPMENT              = 268,
    SPELL_EFFECT_INCREASE_ITEM_BONUS_LIST_GROUP_STEP= 269, // Advances ItemBonusListGroup bonuses to next rank
    SPELL_EFFECT_270                                = 270,
    SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM    = 271,
    SPELL_EFFECT_SET_COVENANT                       = 272,
    SPELL_EFFECT_CRAFT_RUNEFORGE_LEGENDARY          = 273,
    SPELL_EFFECT_274                                = 274,
    SPELL_EFFECT_275                                = 275,
    SPELL_EFFECT_LEARN_TRANSMOG_ILLUSION            = 276,
    SPELL_EFFECT_SET_CHROMIE_TIME                   = 277,
    SPELL_EFFECT_278                                = 278,
    SPELL_EFFECT_LEARN_GARR_TALENT                  = 279,
    SPELL_EFFECT_280                                = 280,
    SPELL_EFFECT_LEARN_SOULBIND_CONDUIT             = 281,
    SPELL_EFFECT_CONVERT_ITEMS_TO_CURRENCY          = 282,
    SPELL_EFFECT_COMPLETE_CAMPAIGN                  = 283, // Flags all quests as completed that are assigned to campaign (MiscValueA)
    SPELL_EFFECT_SEND_CHAT_MESSAGE                  = 284, // MiscValue[0] = BroadcastTextID, MiscValue[1] = ChatType
    SPELL_EFFECT_MODIFY_KEYSTONE_2                  = 285,
    SPELL_EFFECT_GRANT_BATTLEPET_EXPERIENCE         = 286,
    SPELL_EFFECT_SET_GARRISON_FOLLOWER_LEVEL        = 287,
    SPELL_EFFECT_CRAFT_ITEM                         = 288, // MiscValue[0] = CraftingDataID
    SPELL_EFFECT_MODIFY_AURA_STACKS                 = 289, // MiscValue[0] = 0 means add, = 1 means set
    SPELL_EFFECT_MODIFY_COOLDOWN                    = 290,
    SPELL_EFFECT_MODIFY_COOLDOWNS                   = 291, // MiscValue[0] = SpellFamily, MiscValue[1] = maybe bit index for family flags? off by 1 for the only spell using this effect
    SPELL_EFFECT_MODIFY_COOLDOWNS_BY_CATEGORY       = 292, // MiscValue[0] = category
    SPELL_EFFECT_MODIFY_CHARGES                     = 293, // MiscValue[0] = charge category
    SPELL_EFFECT_CRAFT_LOOT                         = 294, // MiscValue[0] = CraftingDataID
    SPELL_EFFECT_SALVAGE_ITEM                       = 295, // MiscValue[0] = ItemSalvageID
    SPELL_EFFECT_CRAFT_SALVAGE_ITEM                 = 296, // MiscValue[0] = ItemSalvageID, MiscValue[1] = CraftingDataID
    SPELL_EFFECT_RECRAFT_ITEM                       = 297,
    SPELL_EFFECT_CANCEL_ALL_PRIVATE_CONVERSATIONS   = 298,
    SPELL_EFFECT_299                                = 299, // something with items, as of 10.0.2 all spells are named "Downgrading"
    SPELL_EFFECT_300                                = 300,
    SPELL_EFFECT_CRAFT_ENCHANT                      = 301, // MiscValue[0] = CraftingDataID, MiscValue[1] = ?
    SPELL_EFFECT_GATHERING                          = 302,
    SPELL_EFFECT_CREATE_TRAIT_TREE_CONFIG           = 303, // MiscValue[0] = TraitTreeID
    SPELL_EFFECT_CHANGE_ACTIVE_COMBAT_TRAIT_CONFIG  = 304,
    SPELL_EFFECT_305                                = 305,
    SPELL_EFFECT_UPDATE_INTERACTIONS                = 306,
    SPELL_EFFECT_307                                = 307,
    SPELL_EFFECT_CANCEL_PRELOAD_WORLD               = 308,
    SPELL_EFFECT_PRELOAD_WORLD                      = 309,
    SPELL_EFFECT_310                                = 310,
    SPELL_EFFECT_ENSURE_WORLD_LOADED                = 311,
    SPELL_EFFECT_312                                = 312,
    SPELL_EFFECT_CHANGE_ITEM_BONUSES_2              = 313, // MiscValue[0] = ItemBonusTreeID to preserve
    SPELL_EFFECT_ADD_SOCKET_BONUS                   = 314, // MiscValue[0] = required ItemBonusTreeID
    SPELL_EFFECT_LEARN_TRANSMOG_APPEARANCE_FROM_ITEM_MOD_APPEARANCE_GROUP = 315, // MiscValue[0] = ItemModAppearanceGroupID (not in db2)
    SPELL_EFFECT_KILL_CREDIT_LABEL_1                = 316,
    SPELL_EFFECT_KILL_CREDIT_LABEL_2                = 317,
    SPELL_EFFECT_318                                = 318,
    SPELL_EFFECT_319                                = 319,
    SPELL_EFFECT_320                                = 320,
    SPELL_EFFECT_321                                = 321,
    SPELL_EFFECT_322                                = 322,
    SPELL_EFFECT_323                                = 323,
    SPELL_EFFECT_324                                = 324,
    SPELL_EFFECT_325                                = 325,
    SPELL_EFFECT_326                                = 326,
    SPELL_EFFECT_327                                = 327,
    SPELL_EFFECT_328                                = 328,
    SPELL_EFFECT_329                                = 329,
    SPELL_EFFECT_330                                = 330,
    SPELL_EFFECT_331                                = 331,
    SPELL_EFFECT_332                                = 332,
    SPELL_EFFECT_333                                = 333,
    TOTAL_SPELL_EFFECTS
};

// EnumUtils: DESCRIBE THIS
enum SpellCastResult : int32
{
    SPELL_FAILED_SUCCESS                                        = 0,
    SPELL_FAILED_AFFECTING_COMBAT                               = 1,
    SPELL_FAILED_ALREADY_AT_FULL_HEALTH                         = 2,
    SPELL_FAILED_ALREADY_AT_FULL_MANA                           = 3,
    SPELL_FAILED_ALREADY_AT_FULL_POWER                          = 4,
    SPELL_FAILED_ALREADY_BEING_TAMED                            = 5,
    SPELL_FAILED_ALREADY_HAVE_CHARM                             = 6,
    SPELL_FAILED_ALREADY_HAVE_SUMMON                            = 7,
    SPELL_FAILED_ALREADY_HAVE_PET                               = 8,
    SPELL_FAILED_ALREADY_OPEN                                   = 9,
    SPELL_FAILED_AURA_BOUNCED                                   = 10,
    SPELL_FAILED_AUTOTRACK_INTERRUPTED                          = 11,
    SPELL_FAILED_BAD_IMPLICIT_TARGETS                           = 12,
    SPELL_FAILED_BAD_TARGETS                                    = 13,
    SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED                     = 14,
    SPELL_FAILED_CANT_BE_CHARMED                                = 15,
    SPELL_FAILED_CANT_BE_SALVAGED                               = 16,
    SPELL_FAILED_CANT_BE_SALVAGED_SKILL                         = 17,
    SPELL_FAILED_CANT_BE_ENCHANTED                              = 18,
    SPELL_FAILED_CANT_BE_MILLED                                 = 19,
    SPELL_FAILED_CANT_BE_PROSPECTED                             = 20,
    SPELL_FAILED_CANT_CAST_ON_TAPPED                            = 21,
    SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE                      = 22,
    SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED                      = 23,
    SPELL_FAILED_CANT_STEALTH                                   = 24,
    SPELL_FAILED_CANT_UNTALENT                                  = 25,
    SPELL_FAILED_CASTER_AURASTATE                               = 26,
    SPELL_FAILED_CASTER_DEAD                                    = 27,
    SPELL_FAILED_CHARMED                                        = 28,
    SPELL_FAILED_CHEST_IN_USE                                   = 29,
    SPELL_FAILED_CONFUSED                                       = 30,
    SPELL_FAILED_DISABLED_BY_POWER_SCALING                      = 31,
    SPELL_FAILED_DONT_REPORT                                    = 32,
    SPELL_FAILED_EQUIPPED_ITEM                                  = 33,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS                            = 34,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND                   = 35,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND                    = 36,
    SPELL_FAILED_ERROR                                          = 37,
    SPELL_FAILED_FALLING                                        = 38,
    SPELL_FAILED_FIZZLE                                         = 39,
    SPELL_FAILED_FLEEING                                        = 40,
    SPELL_FAILED_FOOD_LOWLEVEL                                  = 41,
    SPELL_FAILED_GARRISON_NOT_OWNED                             = 42,
    SPELL_FAILED_GARRISON_OWNED                                 = 43,
    SPELL_FAILED_GARRISON_MAX_LEVEL                             = 44,
    SPELL_FAILED_GARRISON_NOT_UPGRADEABLE                       = 45,
    SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION                   = 46,
    SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING                  = 47,
    SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL                    = 48,
    SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL               = 49,
    SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL               = 50,
    SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY                  = 51,
    SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL                = 52,
    SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY                  = 53,
    SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY   = 54,
    SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC                = 55,
    SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS               = 56,
    SPELL_FAILED_GARRISON_MISSION_COMPLETE                      = 57,
    SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE                 = 58,
    SPELL_FAILED_HIGHLEVEL                                      = 59,
    SPELL_FAILED_HUNGER_SATIATED                                = 60,
    SPELL_FAILED_IMMUNE                                         = 61,
    SPELL_FAILED_INCORRECT_AREA                                 = 62,
    SPELL_FAILED_INTERRUPTED                                    = 63,
    SPELL_FAILED_INTERRUPTED_COMBAT                             = 64,
    SPELL_FAILED_ITEM_ALREADY_ENCHANTED                         = 65,
    SPELL_FAILED_ITEM_GONE                                      = 66,
    SPELL_FAILED_ITEM_NOT_FOUND                                 = 67,
    SPELL_FAILED_ITEM_NOT_READY                                 = 68,
    SPELL_FAILED_LEGACY_SPELL                                   = 69,
    SPELL_FAILED_LEVEL_REQUIREMENT                              = 70,
    SPELL_FAILED_LINE_OF_SIGHT                                  = 71,
    SPELL_FAILED_LOWLEVEL                                       = 72,
    SPELL_FAILED_LOW_CASTLEVEL                                  = 73,
    SPELL_FAILED_MAINHAND_EMPTY                                 = 74,
    SPELL_FAILED_MOVING                                         = 75,
    SPELL_FAILED_NEED_AMMO                                      = 76,
    SPELL_FAILED_NEED_AMMO_POUCH                                = 77,
    SPELL_FAILED_NEED_EXOTIC_AMMO                               = 78,
    SPELL_FAILED_NEED_MORE_ITEMS                                = 79,
    SPELL_FAILED_NOPATH                                         = 80,
    SPELL_FAILED_NOT_BEHIND                                     = 81,
    SPELL_FAILED_NOT_FISHABLE                                   = 82,
    SPELL_FAILED_NOT_FLYING                                     = 83,
    SPELL_FAILED_NOT_HERE                                       = 84,
    SPELL_FAILED_NOT_INFRONT                                    = 85,
    SPELL_FAILED_NOT_IN_CONTROL                                 = 86,
    SPELL_FAILED_NOT_KNOWN                                      = 87,
    SPELL_FAILED_NOT_MOUNTED                                    = 88,
    SPELL_FAILED_NOT_ON_TAXI                                    = 89,
    SPELL_FAILED_NOT_ON_TRANSPORT                               = 90,
    SPELL_FAILED_NOT_READY                                      = 91,
    SPELL_FAILED_NOT_SHAPESHIFT                                 = 92,
    SPELL_FAILED_NOT_STANDING                                   = 93,
    SPELL_FAILED_NOT_TRADEABLE                                  = 94,
    SPELL_FAILED_NOT_TRADING                                    = 95,
    SPELL_FAILED_NOT_UNSHEATHED                                 = 96,
    SPELL_FAILED_NOT_WHILE_GHOST                                = 97,
    SPELL_FAILED_NOT_WHILE_LOOTING                              = 98,
    SPELL_FAILED_NO_AMMO                                        = 99,
    SPELL_FAILED_NO_CHARGES_REMAIN                              = 100,
    SPELL_FAILED_NO_COMBO_POINTS                                = 101,
    SPELL_FAILED_NO_DUELING                                     = 102,
    SPELL_FAILED_NO_ENDURANCE                                   = 103,
    SPELL_FAILED_NO_FISH                                        = 104,
    SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED                    = 105,
    SPELL_FAILED_NO_MOUNTS_ALLOWED                              = 106,
    SPELL_FAILED_NO_PET                                         = 107,
    SPELL_FAILED_NO_POWER                                       = 108,
    SPELL_FAILED_NOTHING_TO_DISPEL                              = 109,
    SPELL_FAILED_NOTHING_TO_STEAL                               = 110,
    SPELL_FAILED_ONLY_ABOVEWATER                                = 111,
    SPELL_FAILED_ONLY_INDOORS                                   = 112,
    SPELL_FAILED_ONLY_MOUNTED                                   = 113,
    SPELL_FAILED_ONLY_OUTDOORS                                  = 114,
    SPELL_FAILED_ONLY_SHAPESHIFT                                = 115,
    SPELL_FAILED_ONLY_STEALTHED                                 = 116,
    SPELL_FAILED_ONLY_UNDERWATER                                = 117,
    SPELL_FAILED_OUT_OF_RANGE                                   = 118,
    SPELL_FAILED_PACIFIED                                       = 119,
    SPELL_FAILED_POSSESSED                                      = 120,
    SPELL_FAILED_REAGENTS                                       = 121,
    SPELL_FAILED_REQUIRES_AREA                                  = 122,
    SPELL_FAILED_REQUIRES_SPELL_FOCUS                           = 123,
    SPELL_FAILED_ROOTED                                         = 124,
    SPELL_FAILED_SILENCED                                       = 125,
    SPELL_FAILED_SPELL_IN_PROGRESS                              = 126,
    SPELL_FAILED_SPELL_LEARNED                                  = 127,
    SPELL_FAILED_SPELL_UNAVAILABLE                              = 128,
    SPELL_FAILED_STUNNED                                        = 129,
    SPELL_FAILED_TARGETS_DEAD                                   = 130,
    SPELL_FAILED_TARGET_AFFECTING_COMBAT                        = 131,
    SPELL_FAILED_TARGET_AURASTATE                               = 132,
    SPELL_FAILED_TARGET_DUELING                                 = 133,
    SPELL_FAILED_TARGET_ENEMY                                   = 134,
    SPELL_FAILED_TARGET_ENRAGED                                 = 135,
    SPELL_FAILED_TARGET_FRIENDLY                                = 136,
    SPELL_FAILED_TARGET_IN_COMBAT                               = 137,
    SPELL_FAILED_TARGET_IN_PET_BATTLE                           = 138,
    SPELL_FAILED_TARGET_IS_PLAYER                               = 139,
    SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED                    = 140,
    SPELL_FAILED_TARGET_NOT_DEAD                                = 141,
    SPELL_FAILED_TARGET_NOT_IN_PARTY                            = 142,
    SPELL_FAILED_TARGET_NOT_LOOTED                              = 143,
    SPELL_FAILED_TARGET_NOT_PLAYER                              = 144,
    SPELL_FAILED_TARGET_NO_POCKETS                              = 145,
    SPELL_FAILED_TARGET_NO_WEAPONS                              = 146,
    SPELL_FAILED_TARGET_NO_RANGED_WEAPONS                       = 147,
    SPELL_FAILED_TARGET_UNSKINNABLE                             = 148,
    SPELL_FAILED_THIRST_SATIATED                                = 149,
    SPELL_FAILED_TOO_CLOSE                                      = 150,
    SPELL_FAILED_TOO_MANY_OF_ITEM                               = 151,
    SPELL_FAILED_TOTEM_CATEGORY                                 = 152,
    SPELL_FAILED_TOTEMS                                         = 153,
    SPELL_FAILED_TRAINING_POINTS                                = 154,
    SPELL_FAILED_TRY_AGAIN                                      = 155,
    SPELL_FAILED_UNIT_NOT_BEHIND                                = 156,
    SPELL_FAILED_UNIT_NOT_INFRONT                               = 157,
    SPELL_FAILED_VISION_OBSCURED                                = 158,
    SPELL_FAILED_WRONG_PET_FOOD                                 = 159,
    SPELL_FAILED_NOT_WHILE_FATIGUED                             = 160,
    SPELL_FAILED_TARGET_NOT_IN_INSTANCE                         = 161,
    SPELL_FAILED_NOT_WHILE_TRADING                              = 162,
    SPELL_FAILED_TARGET_NOT_IN_RAID                             = 163,
    SPELL_FAILED_TARGET_FREEFORALL                              = 164,
    SPELL_FAILED_NO_EDIBLE_CORPSES                              = 165,
    SPELL_FAILED_ONLY_BATTLEGROUNDS                             = 166,
    SPELL_FAILED_TARGET_NOT_GHOST                               = 167,
    SPELL_FAILED_TOO_MANY_SKILLS                                = 168,
    SPELL_FAILED_TRANSFORM_UNUSABLE                             = 169,
    SPELL_FAILED_WRONG_WEATHER                                  = 170,
    SPELL_FAILED_DAMAGE_IMMUNE                                  = 171,
    SPELL_FAILED_PREVENTED_BY_MECHANIC                          = 172,
    SPELL_FAILED_PLAY_TIME                                      = 173,
    SPELL_FAILED_REPUTATION                                     = 174,
    SPELL_FAILED_MIN_SKILL                                      = 175,
    SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND                      = 176,
    SPELL_FAILED_NOT_ON_SHAPESHIFT                              = 177,
    SPELL_FAILED_NOT_ON_STEALTHED                               = 178,
    SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE                           = 179,
    SPELL_FAILED_NOT_ON_MOUNTED                                 = 180,
    SPELL_FAILED_TOO_SHALLOW                                    = 181,
    SPELL_FAILED_TARGET_NOT_IN_SANCTUARY                        = 182,
    SPELL_FAILED_TARGET_IS_TRIVIAL                              = 183,
    SPELL_FAILED_BM_OR_INVISGOD                                 = 184,
    SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED                       = 185,
    SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED                     = 186,
    SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED                   = 187,
    SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED                       = 188,
    SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT                  = 189,
    SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT                  = 190,
    SPELL_FAILED_EXPERT_RIDING_REQUIREMENT                      = 191,
    SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT                     = 192,
    SPELL_FAILED_MASTER_RIDING_REQUIREMENT                      = 193,
    SPELL_FAILED_COLD_RIDING_REQUIREMENT                        = 194,
    SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT               = 195,
    SPELL_FAILED_CS_RIDING_REQUIREMENT                          = 196,
    SPELL_FAILED_PANDA_RIDING_REQUIREMENT                       = 197,
    SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT                     = 198,
    SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT                = 199,
    SPELL_FAILED_MOUNT_NO_FLOAT_HERE                            = 200,
    SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE                       = 201,
    SPELL_FAILED_MOUNT_ABOVE_WATER_HERE                         = 202,
    SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR                  = 203,
    SPELL_FAILED_NOT_IDLE                                       = 204,
    SPELL_FAILED_NOT_INACTIVE                                   = 205,
    SPELL_FAILED_PARTIAL_PLAYTIME                               = 206,
    SPELL_FAILED_NO_PLAYTIME                                    = 207,
    SPELL_FAILED_NOT_IN_BATTLEGROUND                            = 208,
    SPELL_FAILED_NOT_IN_RAID_INSTANCE                           = 209,
    SPELL_FAILED_ONLY_IN_ARENA                                  = 210,
    SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE                 = 211,
    SPELL_FAILED_ON_USE_ENCHANT                                 = 212,
    SPELL_FAILED_NOT_ON_GROUND                                  = 213,
    SPELL_FAILED_CUSTOM_ERROR                                   = 214,
    SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW                         = 215,
    SPELL_FAILED_TOO_MANY_SOCKETS                               = 216,
    SPELL_FAILED_INVALID_GLYPH                                  = 217,
    SPELL_FAILED_UNIQUE_GLYPH                                   = 218,
    SPELL_FAILED_GLYPH_SOCKET_LOCKED                            = 219,
    SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY                       = 220,
    SPELL_FAILED_GLYPH_INVALID_SPEC                             = 221,
    SPELL_FAILED_GLYPH_NO_SPEC                                  = 222,
    SPELL_FAILED_NO_ACTIVE_GLYPHS                               = 223,
    SPELL_FAILED_NO_VALID_TARGETS                               = 224,
    SPELL_FAILED_ITEM_AT_MAX_CHARGES                            = 225,
    SPELL_FAILED_NOT_IN_BARBERSHOP                              = 226,
    SPELL_FAILED_FISHING_TOO_LOW                                = 227,
    SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW                      = 228,
    SPELL_FAILED_SUMMON_PENDING                                 = 229,
    SPELL_FAILED_MAX_SOCKETS                                    = 230,
    SPELL_FAILED_PET_CAN_RENAME                                 = 231,
    SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED                   = 232,
    SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING                   = 233,
    SPELL_FAILED_NO_ACTIONS                                     = 234,
    SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH                       = 235,
    SPELL_FAILED_WEIGHT_NOT_ENOUGH                              = 236,
    SPELL_FAILED_WEIGHT_TOO_MUCH                                = 237,
    SPELL_FAILED_NO_VACANT_SEAT                                 = 238,
    SPELL_FAILED_NO_LIQUID                                      = 239,
    SPELL_FAILED_ONLY_NOT_SWIMMING                              = 240,
    SPELL_FAILED_BY_NOT_MOVING                                  = 241,
    SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED                    = 242,
    SPELL_FAILED_NOT_IN_ARENA                                   = 243,
    SPELL_FAILED_TARGET_NOT_GROUNDED                            = 244,
    SPELL_FAILED_EXCEEDED_WEEKLY_USAGE                          = 245,
    SPELL_FAILED_NOT_IN_LFG_DUNGEON                             = 246,
    SPELL_FAILED_BAD_TARGET_FILTER                              = 247,
    SPELL_FAILED_NOT_ENOUGH_TARGETS                             = 248,
    SPELL_FAILED_NO_SPEC                                        = 249,
    SPELL_FAILED_CANT_ADD_BATTLE_PET                            = 250,
    SPELL_FAILED_CANT_UPGRADE_BATTLE_PET                        = 251,
    SPELL_FAILED_WRONG_BATTLE_PET_TYPE                          = 252,
    SPELL_FAILED_NO_DUNGEON_ENCOUNTER                           = 253,
    SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON                       = 254,
    SPELL_FAILED_MAX_LEVEL_TOO_LOW                              = 255,
    SPELL_FAILED_CANT_REPLACE_ITEM_BONUS                        = 256,
    GRANT_PET_LEVEL_FAIL                                        = 257,
    SPELL_FAILED_SKILL_LINE_NOT_KNOWN                           = 258,
    SPELL_FAILED_BLUEPRINT_KNOWN                                = 259,
    SPELL_FAILED_FOLLOWER_KNOWN                                 = 260,
    SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL                   = 261,
    SPELL_FAILED_ITEM_NOT_A_WEAPON                              = 262,
    SPELL_FAILED_SAME_ENCHANT_VISUAL                            = 263,
    SPELL_FAILED_TOY_USE_LIMIT_REACHED                          = 264,
    SPELL_FAILED_TOY_ALREADY_KNOWN                              = 265,
    SPELL_FAILED_SHIPMENTS_FULL                                 = 266,
    SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER                     = 267,
    SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT                       = 268,
    SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER             = 269,
    SPELL_FAILED_HAS_MISSION                                    = 270,
    SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY                    = 271,
    SPELL_FAILED_NOT_SOULBOUND                                  = 272,
    SPELL_FAILED_RIDING_VEHICLE                                 = 273,
    SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX             = 274,
    SPELL_FAILED_NOT_WHILE_MERCENARY                            = 275,
    SPELL_FAILED_SPEC_DISABLED                                  = 276,
    SPELL_FAILED_CANT_BE_OBLITERATED                            = 277,
    SPELL_FAILED_CANT_BE_SCRAPPED                               = 278,
    SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP                        = 279,
    SPELL_FAILED_TRANSPORT_NOT_READY                            = 280,
    SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN                     = 281,
    SPELL_FAILED_DISABLED_BY_AURA_LABEL                         = 282,
    SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL                   = 283,
    SPELL_FAILED_SPELL_ALREADY_KNOWN                            = 284,
    SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL                    = 285,
    SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE            = 286,
    SPELL_FAILED_NO_ARTIFACT_EQUIPPED                           = 287,
    SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED                        = 288,
    SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE               = 289,
    SPELL_FAILED_SPELL_EFFECT_FAILED                            = 290,
    SPELL_FAILED_NEED_ALL_PARTY_MEMBERS                         = 291,
    SPELL_FAILED_ARTIFACT_AT_FULL_POWER                         = 292,
    SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER                     = 293,
    SPELL_FAILED_AREA_TRIGGER_CREATION                          = 294,
    SPELL_FAILED_AZERITE_EMPOWERED_ONLY                         = 295,
    SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO           = 296,
    SPELL_FAILED_WRONG_FACTION                                  = 297,
    SPELL_FAILED_NOT_ENOUGH_CURRENCY                            = 298,
    SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT          = 299,
    SPELL_FAILED_MOUNT_EQUIPMENT_ERROR                          = 300,
    SPELL_FAILED_NOT_WHILE_LEVEL_LINKED                         = 301,
    SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL                         = 302,
    SPELL_FAILED_SUMMON_MAP_CONDITION                           = 303,
    SPELL_FAILED_SET_COVENANT_ERROR                             = 304,
    SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE                    = 305,
    SPELL_FAILED_SET_CHROMIE_TIME_ERROR                         = 306,
    SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE                   = 307,
    SPELL_FAILED_PLAYER_CONDITION                               = 308,
    SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED                        = 309,
    SPELL_FAILED_CRAFTING_REAGENTS                              = 310,
    SPELL_FAILED_SPECTATOR_OR_COMMENTATOR                       = 311,
    SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT = 312,
    SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT                 = 313,
    SPELL_FAILED_NOT_IN_MAGE_TOWER                              = 314,
    SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL                 = 315,
    SPELL_FAILED_CANT_BE_RECRAFTED                              = 316,
    SPELL_FAILED_PASSIVE_REPLACED                               = 317,
    SPELL_FAILED_CANT_FLY_HERE                                  = 318,
    SPELL_FAILED_DRAGONRIDING_RIDING_REQUIREMENT                = 319,
    SPELL_FAILED_ITEM_MOD_APPEARANCE_GROUP_ALREADY_KNOWN        = 320,
    SPELL_FAILED_ITEM_CREATION_DISABLED_FOR_EVENT               = 321,
    SPELL_FAILED_UNKNOWN                                        = 322,

    // ok cast value - here in case a future version removes SPELL_FAILED_SUCCESS and we need to use a custom value (not sent to client either way)
    SPELL_CAST_OK                                               = SPELL_FAILED_SUCCESS  // SKIP
};

enum SpellCustomErrors
{
    SPELL_CUSTOM_ERROR_NONE                                             =  0,
    SPELL_CUSTOM_ERROR_CUSTOM_MSG                                       =  1,  // Something bad happened, and we want to display a custom message!
    SPELL_CUSTOM_ERROR_ALEX_BROKE_QUEST                                 =  2,  // Alex broke your quest! Thank him later!
    SPELL_CUSTOM_ERROR_NEED_HELPLESS_VILLAGER                           =  3,  // This spell may only be used on Helpless Wintergarde Villagers that have not been rescued.
    SPELL_CUSTOM_ERROR_NEED_WARSONG_DISGUISE                            =  4,  // Requires that you be wearing the Warsong Orc Disguise.
    SPELL_CUSTOM_ERROR_REQUIRES_PLAGUE_WAGON                            =  5,  // You must be closer to a plague wagon in order to drop off your 7th Legion Siege Engineer.
    SPELL_CUSTOM_ERROR_CANT_TARGET_FRIENDLY_NONPARTY                    =  6,  // You cannot target friendly units outside your party.
    SPELL_CUSTOM_ERROR_NEED_CHILL_NYMPH                                 =  7,  // You must target a weakened chill nymph.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_ENKILAH                               =  8,  // The Imbued Scourge Shroud will only work when equipped in the Temple City of En'kilah.
    SPELL_CUSTOM_ERROR_REQUIRES_CORPSE_DUST                             =  9,  // Requires Corpse Dust
    SPELL_CUSTOM_ERROR_CANT_SUMMON_GARGOYLE                             = 10,  // You cannot summon another gargoyle yet.
    SPELL_CUSTOM_ERROR_NEED_CORPSE_DUST_IF_NO_TARGET                    = 11,  // Requires Corpse Dust if the target is not dead and humanoid.
    SPELL_CUSTOM_ERROR_MUST_BE_AT_SHATTERHORN                           = 12,  // Can only be placed near Shatterhorn
    SPELL_CUSTOM_ERROR_MUST_TARGET_PROTO_DRAKE_EGG                      = 13,  // You must first select a Proto-Drake Egg.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_TREE                            = 14,  // You must be close to a marked tree.
    SPELL_CUSTOM_ERROR_MUST_TARGET_TURKEY                               = 15,  // You must target a Fjord Turkey.
    SPELL_CUSTOM_ERROR_MUST_TARGET_HAWK                                 = 16,  // You must target a Fjord Hawk.
    SPELL_CUSTOM_ERROR_TOO_FAR_FROM_BOUY                                = 17,  // You are too far from the bouy.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_OIL_SLICK                       = 18,  // Must be used near an oil slick.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_BOUY                            = 19,  // You must be closer to the buoy!
    SPELL_CUSTOM_ERROR_WYRMREST_VANQUISHER                              = 20,  // You may only call for the aid of a Wyrmrest Vanquisher in Wyrmrest Temple, The Dragon Wastes, Galakrond's Rest or The Wicked Coil.
    SPELL_CUSTOM_ERROR_MUST_TARGET_ICE_HEART_JORMUNGAR                  = 21,  // That can only be used on a Ice Heart Jormungar Spawn.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_SINKHOLE                        = 22,  // You must be closer to a sinkhole to use your map.
    SPELL_CUSTOM_ERROR_REQUIRES_HAROLD_LANE                             = 23,  // You may only call down a stampede on Harold Lane.
    SPELL_CUSTOM_ERROR_REQUIRES_GAMMOTH_MAGNATAUR                       = 24,  // You may only use the Pouch of Crushed Bloodspore on Gammothra or other magnataur in the Bloodspore Plains and Gammoth.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_RESURRECTION_CHAMBER                  = 25,  // Requires the magmawyrm resurrection chamber in the back of the Maw of Neltharion.
    SPELL_CUSTOM_ERROR_CANT_CALL_WINTERGARDE_HERE                       = 26,  // You may only call down a Wintergarde Gryphon in Wintergarde Keep or the Carrion Fields.
    SPELL_CUSTOM_ERROR_MUST_TARGET_WILHELM                              = 27,  // What are you doing? Only aim that thing at Wilhelm!
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_HEALTH                                = 28,  // Not enough health!
    SPELL_CUSTOM_ERROR_NO_NEARBY_CORPSES                                = 29,  // There are no nearby corpses to use.
    SPELL_CUSTOM_ERROR_TOO_MANY_GHOULS                                  = 30,  // You've created enough ghouls. Return to Gothik the Harvester at Death's Breach.
    SPELL_CUSTOM_ERROR_GO_FURTHER_FROM_SUNDERED_SHARD                   = 31,  // Your companion does not want to come here.  Go further from the Sundered Shard.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_CAT_FORM                              = 32,  // Must be in Cat Form
    SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT                             = 33,  // Only Death Knights may enter Ebon Hold.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_BEAR_FORM                             = 34,  // Must be in Bear Form
    SPELL_CUSTOM_ERROR_MUST_BE_NEAR_HELPLESS_VILLAGER                   = 35,  // You must be within range of a Helpless Wintergarde Villager.
    SPELL_CUSTOM_ERROR_CANT_TARGET_ELEMENTAL_MECHANICAL                 = 36,  // You cannot target an elemental or mechanical corpse.
    SPELL_CUSTOM_ERROR_MUST_HAVE_USED_DALARAN_CRYSTAL                   = 37,  // This teleport crystal cannot be used until the teleport crystal in Dalaran has been used at least once.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HOLD_SOMETHING                       = 38,  // You are already holding something in your hand. You must throw the creature in your hand before picking up another.
    SPELL_CUSTOM_ERROR_YOU_DONT_HOLD_ANYTHING                           = 39,  // You don't have anything to throw! Find a Vargul and use Gymer Grab to pick one up!
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_VALDURAN                        = 40,  // Bouldercrag's War Horn can only be used within 10 yards of Valduran the Stormborn.
    SPELL_CUSTOM_ERROR_NO_PASSENGER                                     = 41,  // You are not carrying a passenger. There is nobody to drop off.
    SPELL_CUSTOM_ERROR_CANT_BUILD_MORE_VEHICLES                         = 42,  // You cannot build any more siege vehicles.
    SPELL_CUSTOM_ERROR_ALREADY_CARRYING_CRUSADER                        = 43,  // You are already carrying a captured Argent Crusader. You must return to the Argent Vanguard infirmary and drop off your passenger before you may pick up another.
    SPELL_CUSTOM_ERROR_CANT_DO_WHILE_ROOTED                             = 44,  // You can't do that while rooted.
    SPELL_CUSTOM_ERROR_REQUIRES_NEARBY_TARGET                           = 45,  // Requires a nearby target.
    SPELL_CUSTOM_ERROR_NOTHING_TO_DISCOVER                              = 46,  // Nothing left to discover.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_TARGETS                               = 47,  // No targets close enough to bluff.
    SPELL_CUSTOM_ERROR_CONSTRUCT_TOO_FAR                                = 48,  // Your Iron Rune Construct is out of range.
    SPELL_CUSTOM_ERROR_REQUIRES_GRAND_MASTER_ENGINEER                   = 49,  // Requires Engineering (350)
    SPELL_CUSTOM_ERROR_CANT_USE_THAT_MOUNT                              = 50,  // You can't use that mount.
    SPELL_CUSTOM_ERROR_NOONE_TO_EJECT                                   = 51,  // There is nobody to eject!
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_BOUND                             = 52,  // The target must be bound to you.
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_UNDEAD                            = 53,  // Target must be undead.
    SPELL_CUSTOM_ERROR_TARGET_TOO_FAR                                   = 54,  // You have no target or your target is too far away.
    SPELL_CUSTOM_ERROR_MISSING_DARK_MATTER                              = 55,  // Missing Reagents: Dark Matter
    SPELL_CUSTOM_ERROR_CANT_USE_THAT_ITEM                               = 56,  // You can't use that item
    SPELL_CUSTOM_ERROR_CANT_DO_WHILE_CYCYLONED                          = 57,  // You can't do that while Cycloned
    SPELL_CUSTOM_ERROR_TARGET_HAS_SCROLL                                = 58,  // Target is already affected by a similar effect
    SPELL_CUSTOM_ERROR_POISON_TOO_STRONG                                = 59,  // That anti-venom is not strong enough to dispel that poison
    SPELL_CUSTOM_ERROR_MUST_HAVE_LANCE_EQUIPPED                         = 60,  // You must have a lance equipped.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_MAIDEN                          = 61,  // You must be near the Maiden of Winter's Breath Lake.
    SPELL_CUSTOM_ERROR_LEARNED_EVERYTHING                               = 62,  // You have learned everything from that book
    SPELL_CUSTOM_ERROR_PET_IS_DEAD                                      = 63,  // Your pet is dead
    SPELL_CUSTOM_ERROR_NO_VALID_TARGETS                                 = 64,  // There are no valid targets within range.
    SPELL_CUSTOM_ERROR_GM_ONLY                                          = 65,  // Only GMs may use that. Your account has been reported for investigation.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_58                                = 66,  // You must reach level 58 to use this portal.
    SPELL_CUSTOM_ERROR_AT_HONOR_CAP                                     = 67,  // You already have the maximum amount of honor.
    SPELL_CUSTOM_ERROR_HAVE_HOT_ROD                                     = 68,  // You already have a Hot Rod.
    SPELL_CUSTOM_ERROR_PARTYGOER_MORE_BUBBLY                            = 69,  // This partygoer wants some more bubbly.
    SPELL_CUSTOM_ERROR_PARTYGOER_NEED_BUCKET                            = 70,  // This partygoer needs a bucket!
    SPELL_CUSTOM_ERROR_PARTYGOER_WANT_TO_DANCE                          = 71,  // This partygoer wants to dance with you.
    SPELL_CUSTOM_ERROR_PARTYGOER_WANT_FIREWORKS                         = 72,  // This partygoer wants to see some fireworks.
    SPELL_CUSTOM_ERROR_PARTYGOER_WANT_APPETIZER                         = 73,  // This partygoer wants some more hors d'oeuvres.
    SPELL_CUSTOM_ERROR_GOBLIN_BATTERY_DEPLETED                          = 74,  // The Goblin All-In-1-Der Belt's battery is depleted.
    SPELL_CUSTOM_ERROR_MUST_HAVE_DEMONIC_CIRCLE                         = 75,  // You must have a demonic circle active.
    SPELL_CUSTOM_ERROR_AT_MAX_RAGE                                      = 76,  // You already have maximum rage
    SPELL_CUSTOM_ERROR_REQUIRES_350_ENGINEERING                         = 77,  // Requires Engineering (350)
    SPELL_CUSTOM_ERROR_SOUL_BELONGS_TO_LICH_KING                        = 78,  // Your soul belongs to the Lich King
    SPELL_CUSTOM_ERROR_ATTENDANT_HAS_PONY                               = 79,  // Your attendant already has an Argent Pony
    SPELL_CUSTOM_ERROR_GOBLIN_STARTING_MISSION                          = 80,  // First, Overload the Defective Generator, Activate the Leaky Stove, and Drop a Cigar on the Flammable Bed.
    SPELL_CUSTOM_ERROR_GASBOT_ALREADY_SENT                              = 81,  // You've already sent in the Gasbot and destroyed headquarters!
    SPELL_CUSTOM_ERROR_GOBLIN_IS_PARTIED_OUT                            = 82,  // This goblin is all partied out!
    SPELL_CUSTOM_ERROR_MUST_HAVE_FIRE_TOTEM                             = 83,  // You must have a Magma, Flametongue, or Fire Elemental Totem active.
    SPELL_CUSTOM_ERROR_CANT_TARGET_VAMPIRES                             = 84,  // You may not bite other vampires.
    SPELL_CUSTOM_ERROR_PET_ALREADY_AT_YOUR_LEVEL                        = 85,  // Your pet is already at your level.
    SPELL_CUSTOM_ERROR_MISSING_ITEM_REQUIREMENS                         = 86,  // You do not meet the level requirements for this item.
    SPELL_CUSTOM_ERROR_TOO_MANY_ABOMINATIONS                            = 87,  // There are too many Mutated Abominations.
    SPELL_CUSTOM_ERROR_ALL_POTIONS_USED                                 = 88,  // The potions have all been depleted by Professor Putricide.
    SPELL_CUSTOM_ERROR_DEFEATED_ENOUGH_ALREADY                          = 89,  // You have already defeated enough of them.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_65                                = 90,  // Requires level 65
    SPELL_CUSTOM_ERROR_DESTROYED_KTC_OIL_PLATFORM                       = 91,  // You have already destroyed the KTC Oil Platform.
    SPELL_CUSTOM_ERROR_LAUNCHED_ENOUGH_CAGES                            = 92,  // You have already launched enough cages.
    SPELL_CUSTOM_ERROR_REQUIRES_BOOSTER_ROCKETS                         = 93,  // Requires Single-Stage Booster Rockets. Return to Hobart Grapplehammer to get more.
    SPELL_CUSTOM_ERROR_ENOUGH_WILD_CLUCKERS                             = 94,  // You have already captured enough wild cluckers.
    SPELL_CUSTOM_ERROR_REQUIRES_CONTROL_FIREWORKS                       = 95,  // Requires Remote Control Fireworks. Return to Hobart Grapplehammer to get more.
    SPELL_CUSTOM_ERROR_MAX_NUMBER_OF_RECRUITS                           = 96,  // You already have the max number of recruits.
    SPELL_CUSTOM_ERROR_MAX_NUMBER_OF_VOLUNTEERS                         = 97,  // You already have the max number of volunteers.
    SPELL_CUSTOM_ERROR_FROSTMOURNE_RENDERED_RESURRECT                   = 98,  // Frostmourne has rendered you unable to resurrect.
    SPELL_CUSTOM_ERROR_CANT_MOUNT_WITH_SHAPESHIFT                       = 99,  // You can't mount while affected by that shapeshift.
    SPELL_CUSTOM_ERROR_FAWNS_ALREADY_FOLLOWING                          = 100, // Three fawns are already following you!
    SPELL_CUSTOM_ERROR_ALREADY_HAVE_RIVER_BOAT                          = 101, // You already have a River Boat.
    SPELL_CUSTOM_ERROR_NO_ACTIVE_ENCHANTMENT                            = 102, // You have no active enchantment to unleash.
    SPELL_CUSTOM_ERROR_ENOUGH_HIGHBOURNE_SOULS                          = 103, // You have bound enough Highborne souls. Return to Arcanist Valdurian.
    SPELL_CUSTOM_ERROR_ATLEAST_40YD_FROM_OIL_DRILLING                   = 104, // You must be at least 40 yards away from all other Oil Drilling Rigs.
    SPELL_CUSTOM_ERROR_ABOVE_ENSLAVED_PEARL_MINER                       = 106, // You must be above the Enslaved Pearl Miner.
    SPELL_CUSTOM_ERROR_MUST_TARGET_CORPSE_SPECIAL_1                     = 107, // You must target the corpse of a Seabrush Terrapin, Scourgut Remora, or Spinescale Hammerhead.
    SPELL_CUSTOM_ERROR_SLAGHAMMER_ALREADY_PRISONER                      = 108, // Ambassador Slaghammer is already your prisoner.
    SPELL_CUSTOM_ERROR_REQUIRE_ATTUNED_LOCATION_1                       = 109, // Requires a location that is attuned with the Naz'jar Battlemaiden.
    SPELL_CUSTOM_ERROR_NEED_TO_FREE_DRAKE_FIRST                         = 110, // Free the Drake from the net first!
    SPELL_CUSTOM_ERROR_DRAGONMAW_ALLIES_ALREADY_FOLLOW                  = 111, // You already have three Dragonmaw allies following you.
    SPELL_CUSTOM_ERROR_REQUIRE_OPPOSABLE_THUMBS                         = 112, // Requires Opposable Thumbs.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_HEALTH_2                              = 113, // Not enough health
    SPELL_CUSTOM_ERROR_ENOUGH_FORSAKEN_TROOPERS                         = 114, // You already have enough Forsaken Troopers.
    SPELL_CUSTOM_ERROR_CANNOT_JUMP_TO_BOULDER                           = 115, // You cannot jump to another boulder yet.
    SPELL_CUSTOM_ERROR_SKILL_TOO_HIGH                                   = 116, // Skill too high.
    SPELL_CUSTOM_ERROR_ALREADY_6_SURVIVORS_RESCUED                      = 117, // You have already rescued 6 Survivors.
    SPELL_CUSTOM_ERROR_MUST_FACE_SHIPS_FROM_BALLOON                     = 118, // You need to be facing the ships from the rescue balloon.
    SPELL_CUSTOM_ERROR_CANNOT_SUPERVISE_MORE_CULTISTS                   = 119, // You cannot supervise more than 5 Arrested Cultists at a time.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_85                                = 120, // You must reach level 85 to use this portal.
    SPELL_CUSTOM_ERROR_MUST_BE_BELOW_35_HEALTH                          = 121, // Your target must be below 35% health.
    SPELL_CUSTOM_ERROR_MUST_SELECT_SPECIALIZATION                       = 122, // You must select a specialization first.
    SPELL_CUSTOM_ERROR_TOO_WISE_AND_POWERFUL                            = 123, // You are too wise and powerful to gain any benefit from that item.
    SPELL_CUSTOM_ERROR_TOO_CLOSE_ARGENT_LIGHTWELL                       = 124, // You are within 10 yards of another Argent Lightwell.
    SPELL_CUSTOM_ERROR_NOT_WHILE_SHAPESHIFTED                           = 125, // You can't do that while shapeshifted.
    SPELL_CUSTOM_ERROR_MANA_GEM_IN_BANK                                 = 126, // You already have a Mana Gem in your bank.
    SPELL_CUSTOM_ERROR_FLAME_SHOCK_NOT_ACTIVE                           = 127, // You must have at least one Flame Shock active.
    SPELL_CUSTOM_ERROR_CANT_TRANSFORM                                   = 128, // You cannot transform right now
    SPELL_CUSTOM_ERROR_PET_MUST_BE_ATTACKING                            = 129, // Your pet must be attacking a target.
    SPELL_CUSTOM_ERROR_GNOMISH_ENGINEERING                              = 130, // Requires Gnomish Engineering
    SPELL_CUSTOM_ERROR_GOBLIN_ENGINEERING                               = 131, // Requires Goblin Engineering
    SPELL_CUSTOM_ERROR_NO_TARGET                                        = 132, // You have no target.
    SPELL_CUSTOM_ERROR_PET_OUT_OF_RANGE                                 = 133, // Your Pet is out of range of the target.
    SPELL_CUSTOM_ERROR_HOLDING_FLAG                                     = 134, // You can't do that while holding the flag.
    SPELL_CUSTOM_ERROR_TARGET_HOLDING_FLAG                              = 135, // You can't do that to targets holding the flag.
    SPELL_CUSTOM_ERROR_PORTAL_NOT_OPEN                                  = 136, // The portal is not yet open.  Continue helping the druids at the Sanctuary of Malorne.
    SPELL_CUSTOM_ERROR_AGGRA_AIR_TOTEM                                  = 137, // You need to be closer to Aggra's Air Totem, in the west.
    SPELL_CUSTOM_ERROR_AGGRA_WATER_TOTEM                                = 138, // You need to be closer to Aggra's Water Totem, in the north.
    SPELL_CUSTOM_ERROR_AGGRA_EARTH_TOTEM                                = 139, // You need to be closer to Aggra's Earth Totem, in the east.
    SPELL_CUSTOM_ERROR_AGGRA_FIRE_TOTEM                                 = 140, // You need to be closer to Aggra's Fire Totem, near Thrall.
    SPELL_CUSTOM_ERROR_FACING_WRONG_WAY                                 = 141, // You are facing the wrong way.
    SPELL_CUSTOM_ERROR_TOO_CLOSE_TO_MAKESHIFT_DYNAMITE                  = 142, // You are within 10 yards of another Makeshift Dynamite.
    SPELL_CUSTOM_ERROR_NOT_NEAR_SAPPHIRE_SUNKEN_SHIP                    = 143, // You must be near the sunken ship at Sapphire's End in the Jade Forest.
    SPELL_CUSTOM_ERROR_DEMONS_HEALTH_FULL                               = 144, // That demon's health is already full.
    SPELL_CUSTOM_ERROR_ONYX_SERPENT_NOT_OVERHEAD                        = 145, // Wait until the Onyx Serpent is directly overhead.
    SPELL_CUSTOM_ERROR_OBJECTIVE_ALREADY_COMPLETE                       = 146, // Your objective is already complete.
    SPELL_CUSTOM_ERROR_PUSH_SAD_PANDA_TOWARDS_TOWN                      = 147, // You can only push Sad Panda towards Sad Panda Town!
    SPELL_CUSTOM_ERROR_TARGET_HAS_STARTDUST_2                           = 148, // Target is already affected by Stardust No. 2.
    SPELL_CUSTOM_ERROR_ELEMENTIUM_GEM_CLUSTERS                          = 149, // You cannot deconstruct Elementium Gem Clusters while collecting them!
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_HEALTH                      = 150, // You don't have enough health.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_USE_THE_GATEWAY_YET                   = 151, // You cannot use the gateway yet.
    SPELL_CUSTOM_ERROR_CHOOSE_SPEC_FOR_ASCENDANCE                       = 152, // You must choose a specialization to use Ascendance.
    SPELL_CUSTOM_ERROR_INSUFFICIENT_BLOOD_CHARGES                       = 153, // You have insufficient Blood Charges.
    SPELL_CUSTOM_ERROR_NO_FULLY_DEPLETED_RUNES                          = 154, // No fully depleted runes.
    SPELL_CUSTOM_ERROR_NO_MORE_CHARGES                                  = 155, // No more charges.
    SPELL_CUSTOM_ERROR_STATUE_IS_OUT_OF_RANGE_OF_TARGET                 = 156, // Statue is out of range of the target.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_A_STATUE_SUMMONED                  = 157, // You don't have a statue summoned.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_SPIRIT_ACTIVE                        = 158, // You have no spirit active.
    SPELL_CUSTOM_ERROR_BOTH_DISESASES_MUST_BE_ON_TARGET                 = 159, // Both Frost Fever and Blood Plague must be present on the target.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_WITH_ORB_OF_POWER                   = 160, // You can't do that while holding an Orb of Power.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_WHILE_JUMPING_OR_FALLING            = 161, // You can't do that while jumping or falling.
    SPELL_CUSTOM_ERROR_MUST_BE_TRANSFORMED_BY_POLYFORMIC_ACID           = 162, // You must be transformed by Polyformic Acid.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_ACID_TO_STORE_TRANSFORMATION          = 163, // There isn't enough acid left to store this transformation.
    SPELL_CUSTOM_ERROR_MUST_HAVE_FLIGHT_MASTERS_LICENSE                 = 164, // You must obtain a Flight Master's License before using this spell.
    SPELL_CUSTOM_ERROR_ALREADY_SAMPLED_SAP_FROM_FEEDER                  = 165, // You have already sampled sap from this Feeder.
    SPELL_CUSTOM_ERROR_MUST_BE_NEWR_MANTID_FEEDER                       = 166, // Requires you to be near a Mantid Feeder in the Heart of Fear.
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_IN_DIRECTLY_FRONT                 = 167, // Target must be directly in front of you.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_WHILE_MYTHIC_KEYSTONE_IS_ACTIVE     = 168, // You can't do that while a Mythic Keystone is active.
    SPELL_CUSTOM_ERROR_WRONG_CLASS_FOR_MOUNT                            = 169, // You are not the correct class for that mount.
    SPELL_CUSTOM_ERROR_NOTHING_LEFT_TO_DISCOVER                         = 170, // Nothing left to discover.
    SPELL_CUSTOM_ERROR_NO_EXPLOSIVES_AVAILABLE                          = 171, // There are no explosives available.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_FLAGGED_FOR_PVP                      = 172, // You must be flagged for PvP.
    SPELL_CUSTOM_ERROR_REQUIRES_BATTLE_RATIONS                          = 173, // Requires Battle Rations or Meaty Haunch
    SPELL_CUSTOM_ERROR_REQUIRES_BRITTLE_ROOT                            = 174, // Requires Brittle Root
    SPELL_CUSTOM_ERROR_REQUIRES_LABORERS_TOOL                           = 175, // Requires Laborer's Tool
    SPELL_CUSTOM_ERROR_REQUIRES_UNEXPLODED_CANNONBALL                   = 176, // Requires Unexploded Cannonball
    SPELL_CUSTOM_ERROR_REQUIRES_MISPLACED_KEG                           = 177, // Requires Misplaced Keg
    SPELL_CUSTOM_ERROR_REQUIRES_LIQUID_FIRE                             = 178, // Requires Liquid Fire, Jungle Hops, or Spirit-kissed Water
    SPELL_CUSTOM_ERROR_REQUIRES_KRASARI_IRON                            = 179, // Requires Krasari Iron
    SPELL_CUSTOM_ERROR_REQUIRES_SPIRIT_KISSED_WATER                     = 180, // Requires Spirit-Kissed Water
    SPELL_CUSTOM_ERROR_REQUIRES_SNAKE_OIL                               = 181, // Requires Snake Oil
    SPELL_CUSTOM_ERROR_SCENARIO_IS_IN_PROGRESS                          = 182, // You can't do that while a Scenario is in progress.
    SPELL_CUSTOM_ERROR_REQUIRES_DARKMOON_FAIRE_OPEN                     = 183, // Requires the Darkmoon Faire to be open.
    SPELL_CUSTOM_ERROR_ALREADY_AT_VALOR_CAP                             = 184, // Already at Valor cap
    SPELL_CUSTOM_ERROR_ALREADY_COMMENDED_BY_THIS_FACTION                = 185, // Already commended by this faction
    SPELL_CUSTOM_ERROR_OUT_OF_COINS                                     = 186, // Out of coins! Pickpocket humanoids to get more.
    SPELL_CUSTOM_ERROR_ONLY_ONE_ELEMENTAL_SPIRIT                        = 187, // Only one elemental spirit on a target at a time.
    SPELL_CUSTOM_ERROR_DONT_KNOW_HOW_TO_TAME_DIREHORNS                  = 188, // You do not know how to tame Direhorns.
    SPELL_CUSTOM_ERROR_MUST_BE_NEAR_BLOODIED_COURT_GATE                 = 189, // You must be near the Bloodied Court gate.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_ELECTRIFIED                          = 190, // You are not Electrified.
    SPELL_CUSTOM_ERROR_THERE_IS_NOTHING_TO_BE_FETCHED                   = 191, // There is nothing to be fetched.
    SPELL_CUSTOM_ERROR_REQUIRES_THE_THUNDER_FORGE                       = 192, // Requires The Thunder Forge.
    SPELL_CUSTOM_ERROR_CANNOT_USE_THE_DICE_AGAIN_YET                    = 193, // You cannot use the dice again yet.
    SPELL_CUSTOM_ERROR_ALREADY_MEMBER_OF_BRAWLERS_GUILD                 = 194, // You are already a member of the Brawler's Guild.
    SPELL_CUSTOM_ERROR_CANT_CHANGE_SPEC_IN_CELESTIAL_CHALLENGE          = 195, // You may not change talent specializations during a celestial challenge.
    SPELL_CUSTOM_ERROR_SPEC_DOES_MATCH_CHALLENGE                        = 196, // Your talent specialization does not match the selected challenge.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_CURRENCY                    = 197, // You don't have enough currency to do that.
    SPELL_CUSTOM_ERROR_TARGET_CANNOT_BENEFIT_FROM_SPELL                 = 198, // Target cannot benefit from that spell
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_HAVE_ONE_HEALING_RAIN               = 199, // You can only have one Healing Rain active at a time.
    SPELL_CUSTOM_ERROR_THE_DOOR_IS_LOCKED                               = 200, // The door is locked.
    SPELL_CUSTOM_ERROR_YOU_NEED_TO_SELECT_WAITING_CUSTOMER              = 201, // You need to select a customer who is waiting in line first.
    SPELL_CUSTOM_ERROR_CANT_CHANGE_SPEC_DURING_TRIAL                    = 202, // You may not change specialization while a trial is in progress.
    SPELL_CUSTOM_ERROR_CUSTOMER_NEED_TO_GET_IN_LINE                     = 203, // You must wait for customers to get in line before you can select them to be seated.
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSER_TO_GAZLOWE_OBJECTIVE              = 204, // Must be closer to one of Gazlowe's objectives to deploy!
    SPELL_CUSTOM_ERROR_MUST_BE_CLOSER_TO_THAELIN_OBJECTIVE              = 205, // Must be closer to one of Thaelin's objectives to deploy!
    SPELL_CUSTOM_ERROR_YOUR_PACK_OF_VOLEN_IS_FULL                       = 206, // Your pack of volen is already full!
    SPELL_CUSTOM_ERROR_REQUIRES_600_MINING_OR_BLACKSMITHING             = 207, // Requires 600 Mining or Blacksmithing
    SPELL_CUSTOM_ERROR_ARKONITE_PROTECTOR_NOT_IN_RANGE                  = 208, // The Arkonite Protector is not in range.
    SPELL_CUSTOM_ERROR_TARGET_CANNOT_HAVE_BOTH_BEACONS                  = 209, // You are unable to have both Beacon of Light and Beacon of Faith on the same target.
    SPELL_CUSTOM_ERROR_CAN_ONLY_USE_ON_AFK_PLAYER                       = 210, // Can only be used on AFK players.
    SPELL_CUSTOM_ERROR_NO_LOOTABLE_CORPSES_IN_RANGE                     = 211, // No lootable corpse in range
    SPELL_CUSTOM_ERROR_CHIMAERON_TOO_CALM_TO_TAME                       = 212, // Chimaeron is too calm to tame right now.
    SPELL_CUSTOM_ERROR_CAN_ONLY_CARRY_ONE_TYPE_OF_MUNITIONS             = 213, // You may only carry one type of Blackrock Munitions.
    SPELL_CUSTOM_ERROR_OUT_OF_BLACKROCK_MUNITIONS                       = 214, // You have run out of Blackrock Munitions.
    SPELL_CUSTOM_ERROR_CARRYING_MAX_AMOUNT_OF_MUNITIONS                 = 215, // You are carrying the maximum amount of Blackrock Munitions.
    SPELL_CUSTOM_ERROR_TARGET_IS_TOO_FAR_AWAY                           = 216, // Target is too far away.
    SPELL_CUSTOM_ERROR_CANNOT_USE_DURING_BOSS_ENCOUNTER                 = 217, // Cannot use during a boss encounter.
    SPELL_CUSTOM_ERROR_MUST_HAVE_MELEE_WEAPON_IN_BOTH_HANDS             = 218, // Must have a Melee Weapon equipped in both hands
    SPELL_CUSTOM_ERROR_YOUR_WEAPON_HAS_OVERHEATED                       = 219, // Your weapon has overheated.
    SPELL_CUSTOM_ERROR_MUST_BE_PARTY_LEADER_TO_QUEUE                    = 220, // You must be a party leader to queue your group.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_FUEL                                  = 221, // Not enough fuel
    SPELL_CUSTOM_ERROR_YOU_ARE_ALREADY_DISGUISED                        = 222, // You are already disguised!
    SPELL_CUSTOM_ERROR_YOU_NEED_TO_BE_IN_SHREDDER                       = 223, // You need to be in a Shredder to chop this up!
    SPELL_CUSTOM_ERROR_FOOD_CANNOT_EAT_FOOD                             = 224, // Food cannot eat food
    SPELL_CUSTOM_ERROR_MYSTERIOUS_FORCE_PREVENTS_OPENING_CHEST          = 225, // A mysterious force prevents you from opening the chest.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_WHILE_HOLDING_EMPOWERED_ORE         = 226, // You can't do that while holding Empowered Ore.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_AMMUNITION                            = 227, // Not enough Ammunition!
    SPELL_CUSTOM_ERROR_YOU_NEED_BEATFACE_THE_GLADIATOR                  = 228, // You need Beatface the Sparring Arena gladiator to break this!
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_HAVE_ONE_WAYGATE                    = 229, // You can only have one waygate open. Disable an activated waygate first.
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_HAVE_TWO_WAYGATES                   = 230, // You can only have two waygates open. Disable an activated waygate first.
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_HAVE_THREE_WAYGATES                 = 231, // You can only have three waygates open. Disable an activated waygate first.
    SPELL_CUSTOM_ERROR_REQUIRES_MAGE_TOWER                              = 232, // Requires Mage Tower
    SPELL_CUSTOM_ERROR_REQUIRES_SPIRIT_LODGE                            = 233, // Requires Spirit Lodge
    SPELL_CUSTOM_ERROR_FROST_WYRM_ALREADY_ACTIVE                        = 234, // A Frost Wyrm is already active.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_RUNIC_POWER                           = 235, // Not enough Runic Power
    SPELL_CUSTOM_ERROR_YOU_ARE_THE_PARTY_LEADER                         = 236, // You are the Party Leader.
    SPELL_CUSTOM_ERROR_YULON_IS_ALREADY_ACTIVE                          = 237, // Yu'lon is already active.
    SPELL_CUSTOM_ERROR_A_STAMPEDE_IS_ALREADY_ACTIVE                     = 238, // A Stampede is already active.
    SPELL_CUSTOM_ERROR_YOU_ARE_ALREADY_WELL_FED                         = 239, // You are already Well Fed.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_UNDER_SUPPRESSIVE_FIRE              = 240, // You cannot do that while under Suppressive Fire.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_MURLOC_SLOP                     = 241, // You already have a piece of Murloc Slop.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ARTIFACT_FRAGMENTS                 = 242, // You don't have any Artifact Fragments.
    SPELL_CUSTOM_ERROR_YOU_ARENT_IN_A_PARTY                             = 243, // You aren't in a Party.
    SPELL_CUSTOM_ERROR_REQUIRES_20_AMMUNITION                           = 244, // Requires 30 Ammunition!
    SPELL_CUSTOM_ERROR_REQUIRES_30_AMMUNITION                           = 245, // Requires 20 Ammunition!
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_MAX_OUTCAST_FOLLOWERS           = 246, // You already have the maximum amount of Outcasts following you.
    SPELL_CUSTOM_ERROR_NOT_IN_WORLD_PVP_ZONE                            = 247, // Not in World PvP zone.
    SPELL_CUSTOM_ERROR_ALREADY_AT_RESOURCE_CAP                          = 248, // Already at Resource cap
    SPELL_CUSTOM_ERROR_APEXIS_SENTINEL_REQUIRES_ENERGY                  = 249, // This Apexis Sentinel requires energy from a nearby Apexis Pylon to be powered up.
    SPELL_CUSTOM_ERROR_YOU_MUST_HAVE_3_OR_FEWER_PLAYER                  = 250, // You must have 3 or fewer players.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_READ_TREASURE_MAP                    = 251, // You have already read that treasure map.
    SPELL_CUSTOM_ERROR_MAY_ONLY_USE_WHILE_GARRISON_UNDER_ATTACK         = 252, // You may only use this item while your garrison is under attack.
    SPELL_CUSTOM_ERROR_REQUIRES_ACTIVE_MUSHROOMS                        = 253, // This spell requires active mushrooms for you to detonate.
    SPELL_CUSTOM_ERROR_REQUIRES_FASTER_TIME_WITH_RACER                  = 254, // Requires a faster time with the basic racer
    SPELL_CUSTOM_ERROR_REQUIRES_INFERNO_SHOT_AMMO                       = 255, // Requires Inferno Shot Ammo!
    SPELL_CUSTOM_ERROR_YOU_CANNOT_DO_THAT_RIGHT_NOW                     = 256, // You cannot do that right now.
    SPELL_CUSTOM_ERROR_A_TRAP_IS_ALREADY_PLACED_THERE                   = 257, // A trap is already placed there.
    SPELL_CUSTOM_ERROR_YOU_ARE_ALREADY_ON_THAT_QUEST                    = 258, // You are already on that quest.
    SPELL_CUSTOM_ERROR_REQUIRES_FELFORGED_CUDGEL                        = 259, // Requires a Felforged Cudgel!
    SPELL_CUSTOM_ERROR_CANT_TAKE_WHILE_BEING_DAMAGED                    = 260, // Can't take while being damaged!
    SPELL_CUSTOM_ERROR_YOU_ARE_BOUND_TO_DRAENOR                         = 261, // You are bound to Draenor by Archimonde's magic.
    SPELL_CUSTOM_ERROR_ALREAY_HAVE_MAX_NUMBER_OF_SHIPS                  = 262, // You already have the maximum number of ships your shipyard can support.
    SPELL_CUSTOM_ERROR_MUST_BE_AT_SHIPYARD                              = 263, // You must be at your shipyard.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_3_MAGE_TOWER                      = 264, // Requires a level 3 Mage Tower.
    SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_3_SPIRIT_LODGE                    = 265, // Requires a level 3 Spirit Lodge.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_LIKE_FEL_EGGS_AND_HAM                 = 266, // You do not like Fel Eggs and Ham.
    SPELL_CUSTOM_ERROR_ALREADY_ENTERED_IN_THIS_AGREEMENT                = 267, // You have already entered in to this trade agreement.
    SPELL_CUSTOM_ERROR_CANNOT_STEAL_THAT_WHILE_GUARDS_ARE_ON_DUTY       = 268, // You cannot steal that while guards are on duty.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_VANTUS_RUNE                     = 269, // You have already used a Vantus Rune this week.
    SPELL_CUSTOM_ERROR_THAT_ITEM_CANNOT_BE_OBLITERATED                  = 270, // That item cannot be obliterated.
    SPELL_CUSTOM_ERROR_NO_SKINNABLE_CORPSE_IN_RANGE                     = 271, // No skinnable corpse in range
    SPELL_CUSTOM_ERROR_MUST_BE_MERCENARY_TO_USE_TRINKET                 = 272, // You must be a Mercenary to use this trinket.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_COMBAT                            = 273, // You must be in combat.
    SPELL_CUSTOM_ERROR_NO_ENEMIES_NEAR_TARGET                           = 274, // No enemies near target.
    SPELL_CUSTOM_ERROR_REQUIRES_LEYSPINE_MISSILE                        = 275, // Requires a Leyspine Missile
    SPELL_CUSTOM_ERROR_REQUIRES_BOTH_CURRENTS_CONNECTED                 = 276, // Requires both currents connected.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_IN_DEMON_FORM                       = 277, // Can't do that while in demon form (yet)
    SPELL_CUSTOM_ERROR_YOU_DONT_KNOW_HOW_TO_TAME_MECHS                  = 278, // You do not know how to tame or obtain lore about Mechs.
    SPELL_CUSTOM_ERROR_CANNOT_CHARM_ANY_MORE_WITHERED                   = 279, // You cannot charm any more withered.
    SPELL_CUSTOM_ERROR_REQUIRES_ACTIVE_HEALING_RAIN                     = 280, // Requires an active Healing Rain.
    SPELL_CUSTOM_ERROR_ALREADY_COLLECTED_APPEARANCES                    = 281, // You've already collected these appearances
    SPELL_CUSTOM_ERROR_CANNOT_RESURRECT_SURRENDERED_TO_MADNESS          = 282, // Cannot resurrect someone who has surrendered to madness
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_CAT_FORM                          = 283, // You must be in Cat Form.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_RELEASE_SPIRIT_YET                    = 284, // You cannot Release Spirit yet.
    SPELL_CUSTOM_ERROR_NO_FISHING_NODES_NEARBY                          = 285, // No fishing nodes nearby.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_IN_CORRECT_SPEC                      = 286, // You are not the correct specialization.
    SPELL_CUSTOM_ERROR_ULTHALESH_HAS_NO_POWER_WITHOUT_SOULS             = 287, // Ulthalesh has no power without souls.
    SPELL_CUSTOM_ERROR_CANNOT_CAST_THAT_WITH_VOODOO_TOTEM               = 288, // You cannot cast that while talented into Voodoo Totem.
    SPELL_CUSTOM_ERROR_ALREADY_COLLECTED_THIS_APPEARANCE                = 289, // You've already collected this appearance.
    SPELL_CUSTOM_ERROR_YOUR_PET_MAXIMUM_IS_ALREADY_HIGH                 = 290, // Your total pet maximum is already this high.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_WITHERED                    = 291, // You do not have enough withered to do that.
    SPELL_CUSTOM_ERROR_REQUIRES_NEARBY_SOUL_FRAGMENT                    = 292, // Requires a nearby Soul Fragment.
    SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_10_WITHERED                    = 293, // Requires at least 10 living withered
    SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_14_WITHERED                    = 294, // Requires at least 14 living withered
    SPELL_CUSTOM_ERROR_REQUIRES_AT_LEAST_18_WITHERED                    = 295, // Requires at least 18 living withered
    SPELL_CUSTOM_ERROR_REQUIRES_2_WITHERED_MANA_RAGERS                  = 296, // Requires 2 Withered Mana-Ragers
    SPELL_CUSTOM_ERROR_REQUIRES_1_WITHERED_BERSERKE                     = 297, // Requires 1 Withered Berserker
    SPELL_CUSTOM_ERROR_REQUIRES_2_WITHERED_BERSERKER                    = 298, // Requires 2 Withered Berserkers
    SPELL_CUSTOM_ERROR_TARGET_HEALTH_IS_TOO_LOW                         = 299, // Target's health is too low
    SPELL_CUSTOM_ERROR_CANNOT_SHAPESHIFT_WHILE_RIDING_STORMTALON        = 300, // You cannot shapeshift while riding Stormtalon
    SPELL_CUSTOM_ERROR_CANNOT_CHANGE_SPEC_IN_COMBAT_TRAINING            = 301, // You can not change specializations while in Combat Training.
    SPELL_CUSTOM_ERROR_UNKNOWN_PHENOMENON_PREVENTS_LEYLINE_CONNECTION   = 302, // Unknown phenomenon is preventing a connection to the Leyline.
    SPELL_CUSTOM_ERROR_THE_NIGHTMARE_OBSCURES_YOUR_VISION               = 303, // The Nightmare obscures your vision.
    SPELL_CUSTOM_ERROR_YOU_ARE_IN_WRONG_CLASS_SPEC                      = 304, // You are in the wrong class specialization.
    SPELL_CUSTOM_ERROR_THERE_ARE_NO_VALID_CORPSES_NEARBY                = 305, // There are no valid corpses nearby.
    SPELL_CUSTOM_ERROR_CANT_CAST_THAT_RIGHT_NOW                         = 306, // Can't cast that right now.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_ANCIENT_MAN                           = 307, // Not enough Ancient Mana.
    SPELL_CUSTOM_ERROR_REQUIRES_SONG_SCROLL                             = 308, // Requires a Song Scroll to function.
    SPELL_CUSTOM_ERROR_MUST_HAVE_ARTIFACT_EQUIPPED                      = 309, // You must have an artifact weapon equipped.
    SPELL_CUSTOM_ERROR_REQUIRES_CAT_FORM                                = 310, // Requires Cat Form.
    SPELL_CUSTOM_ERROR_REQUIRES_BEAR_FORM                               = 311, // Requires Bear Form.
    SPELL_CUSTOM_ERROR_REQUIRES_CONJURED_FOOD                           = 312, // Requires either a Conjured Mana Pudding or Conjured Mana Fritter.
    SPELL_CUSTOM_ERROR_REQUIRES_ARTIFACT_WEAPON                         = 313, // Requires an artifact weapon.
    SPELL_CUSTOM_ERROR_YOU_CANT_CAST_THAT_HERE                          = 314, // You can't cast that here
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_ON_CLASS_TRIAL                      = 315, // You cannot do that while on a Class Trial.
    SPELL_CUSTOM_ERROR_RITUAL_OF_DOOM_ONCE_PER_DAY                      = 316, // You can only benefit from the Ritual of Doom once per day.
    SPELL_CUSTOM_ERROR_CANNOT_RITUAL_OF_DOOM_WHILE_SUMMONING_SITERS     = 317, // You cannot perform the Ritual of Doom while attempting to summon the sisters.
    SPELL_CUSTOM_ERROR_LEARNED_ALL_THAT_YOU_CAN_ABOUT_YOUR_ARTIFACT     = 318, // You have learned all that you can about your artifact.
    SPELL_CUSTOM_ERROR_CANT_CALL_PET_WITH_LONE_WOLF                     = 319, // You cannot use Call Pet while Lone Wolf is active.
    SPELL_CUSTOM_ERROR_TARGET_CANNOT_ALREADY_HAVE_ORB_OF_POWER          = 320, // Target cannot already have a Orb of Power.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_AN_INN_TO_STRUM_THAT_GUITAR       = 321, // You must be in an inn to strum that guitar.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_REACH_THE_LATCH                       = 322, // You cannot reach the latch.
    SPELL_CUSTOM_ERROR_REQUIRES_A_BRIMMING_KEYSTONE                     = 323, // Requires a Brimming Keystone.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_WIELDING_THE_UNDERLIGHT_ANGLER       = 324, // You must be wielding the Underlight Angler.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_MUST_BE_SHACKLED                     = 325, // Your target must be Shackled.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_POSSES_ALL_OF_THE_KNOWLEDGE_CONTAINED_IN_THOSE_PAGES = 326, // You already possess all of the knowledge contained in these pages.
    SPELL_CUSTOM_ERROR_YOU_CANT_RISK_GETTING_THE_GRUMMELS_WET           = 327, // You can't risk getting the grummels wet!
    SPELL_CUSTOM_ERROR_YOU_CANNOT_CHANGE_SPECIALIZATION_RIGHT_NOW       = 328, // You cannot change specializations right now.
    SPELL_CUSTOM_ERROR_YOUVE_REACHED_THE_MAXIMUM_NUMBER_OF_ARTIFACT_RESEARCH_NOTES_AVAILABLE = 329, // You've reached the maximum number of Artifact Research Notes available.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_NETHERSHARDS                = 330, // You don't have enough Nethershards.
    SPELL_CUSTOM_ERROR_THE_SENTINAX_IS_NOT_PATROLLING_THIS_AREA         = 331, // The Sentinax is not patrolling this area.
    SPELL_CUSTOM_ERROR_THE_SENTINAX_CANNOT_OPEN_ANOTHER_PORTAL_RIGHT_NOW = 332, // The Sentinax cannot open another portal right now.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_GAIN_ADDITIONAL_REPUTATION_WITH_THIS_ITEM = 333, // You cannot gain additional reputation with this item.
    SPELL_CUSTOM_ERROR_CANT_DO_THAT_WHILE_GHOST_WOLF_FORM               = 334, // Can't do that while in Ghost Wolf form.
    SPELL_CUSTOM_ERROR_YOUR_SUPPLIES_ARE_FROZEN                         = 335, // Your supplies are frozen.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_FEATHERMANES         = 336, // You do not know how to tame Feathermanes.
    SPELL_CUSTOM_ERROR_YOU_MUST_REACH_ARTIFACT_KNOWLEDGE_LEVEL_25       = 337, // You must reach Artifact Knowledge level 25 to use the Tome.
    SPELL_CUSTOM_ERROR_REQUIRES_A_NETHER_PORTAL_DISRUPTOR               = 338, // Requires a Nether Portal Disruptor.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_THE_CORRECT_RANK_TO_USE_THIS_ITEM    = 339, // You are not the correct Rank to use this item.
    SPELL_CUSTOM_ERROR_MUST_BE_STANDING_NEAR_INJURED_CHROMIE_IN_MOUNT_HYJAL = 340, // Must be standing near the injured Chromie in Mount Hyjal.
    SPELL_CUSTOM_ERROR_THERES_NOTHING_FURTHER_YOU_CAN_LEARN             = 341, // There's nothing further you can learn.
    SPELL_CUSTOM_ERROR_REMOVE_CANNONS_HEAVY_IRON_PLATING_FIRST          = 342, // You should remove the cannon's Heavy Iron Plating first.
    SPELL_CUSTOM_ERROR_REMOVE_CANNONS_ELECTROKINETIC_DEFENSE_GRID_FIRST = 343, // You should remove the cannon's Electrokinetic Defense Grid first.
    SPELL_CUSTOM_ERROR_REQUIRES_THE_ARMORY_KEY_AND_DENDRITE_CLUSTERS    = 344, // You are missing pieces of the Armory Key or do not have enough Dendrite Clusters.
    SPELL_CUSTOM_ERROR_THIS_ITEM_REQUIRES_BASIC_OBLITERUM_TO_UPGRADE    = 345, // This item requires basic Obliterum to upgrade.
    SPELL_CUSTOM_ERROR_THIS_ITEM_REQUIRES_PRIMAL_OBLITERUM_TO_UPGRADE   = 346, // This item requires Primal Obliterum to upgrade.
    SPELL_CUSTOM_ERROR_THIS_ITEM_REQUIRES_FLIGHT_MASTERS_WHISTLE        = 347, // This item requires a Flight Master's Whistle.
    SPELL_CUSTOM_ERROR_REQUIRES_MORRISONS_MASTER_KEY                    = 348, // Requires Morrison's Master Key.
    SPELL_CUSTOM_ERROR_REQUIRES_POWER_THAT_ECHOES_THAT_OF_THE_AUGARI    = 349, // Will only open to one wielding the power that echoes that of the Augari.
    SPELL_CUSTOM_ERROR_THAT_PLAYER_HAS_A_PENDING_TOTEMIC_REVIVAL        = 350, // That player has a pending Totemic Revival.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_FIRE_MINES_DEPLOYED                  = 351, // You have no Fire Mines deployed.
    SPELL_CUSTOM_ERROR_MUST_BE_AFFECTED_BY_SPIRIT_POWDER                = 352, // You must be affected by the Spirit Powder to take the phylactery.
    SPELL_CUSTOM_ERROR_YOU_ARE_BLOCKED_BY_A_STRUCTURE_ABOVE_YOU         = 353, // You are blocked by a structure above you.
    SPELL_CUSTOM_ERROR_REQUIRES_100_IMP_MEAT                            = 354, // Requires 100 Imp Meat.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NOT_OBTAINED_ANY_BACKGROUND_FILTERS     = 355, // You have not obtained any background filters.
    SPELL_CUSTOM_ERROR_NOTHING_INTERESTING_POSTED_HERE_RIGHT_NOW        = 356, // There is nothing interesting posted here right now.
    SPELL_CUSTOM_ERROR_PARAGON_REPUTATION_REQUIRES_HIGHER_LEVEL         = 357, // Paragon Reputation is not available until a higher level.
    SPELL_CUSTOM_ERROR_UUNA_IS_MISSING                                  = 358, // Uuna is missing.
    SPELL_CUSTOM_ERROR_ONLY_OTHER_HIVEMIND_MEMBERS_MAY_JOIN             = 359, // Only other members of their Hivemind may join with them.
    SPELL_CUSTOM_ERROR_NO_VALID_FLASK_PRESENT                           = 360, // No valid flask present.
    SPELL_CUSTOM_ERROR_NO_WILD_IMPS_TO_SACRIFICE                        = 361, // There are no Wild Imps to sacrifice.
    SPELL_CUSTOM_ERROR_YOU_ARE_CARRYING_TOO_MUCH_IRON                   = 362, // You are carrying too much Iron
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_IRON_TO_COLLECT                      = 363, // You have no Iron to collect
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_WILD_IMPS                            = 364, // You have no available Wild Imps.
    SPELL_CUSTOM_ERROR_NEEDS_REPAIRS                                    = 365, // Needs repairs.
    SPELL_CUSTOM_ERROR_YOU_ARE_CARRYING_TOO_MUCH_WOOD                   = 366, // You're carrying too much wood.
    SPELL_CUSTOM_ERROR_YOU_ARE_ALREADY_CARRYING_REPAIR_PARTS            = 367, // You're already carrying repair parts.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NOT_UNLOCKED_FLIGHT_WHISTLE_FOR_ZONE    = 368, // You have not unlocked the Flight Whistle for this zone.
    SPELL_CUSTOM_ERROR_THERE_ARE_NO_UNLOCKED_FLIGHT_POINTS_NEARBY       = 369, // There are no unlocked flight points nearby to take you to.
    SPELL_CUSTOM_ERROR_YOU_MUST_HAVE_A_FELGUARD                         = 370, // You must have a Felguard.
    SPELL_CUSTOM_ERROR_TARGET_HAS_NO_FESTERING_WOUNDS                   = 371, // The target has no Festering Wounds.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_DEADLY_OR_WOUND_POISON_ACTIVE      = 372, // You do not have Deadly Poison or Wound Poison active.
    SPELL_CUSTOM_ERROR_CANNOT_READ_SOLDIER_DOG_TAG_WITHOUT_HEADLAMP_ON  = 373, // You cannot read the soldier's dog tag without your headlamp on.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_WOOD_TO_COLLECT                      = 374, // You have no Wood to collect.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_WEARING_A_SHIRT                      = 375, // You are not wearing a shirt!
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_DEAD                              = 376, // Target must be dead.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_IS_ALREADY_EMBIGGIFIED               = 377, // Your target is already embiggified.
    SPELL_CUSTOM_ERROR_YOU_MUST_TARGET_A_SINISTER_GLADIATOR_ITEM        = 378, // You must target a Sinister Gladiator's item to upgrade.
    SPELL_CUSTOM_ERROR_THIS_ITEM_LEVEL_IS_TOO_HIGH_FOR_THIS_UPGRADE     = 379, // This item's level is too high for this upgrade.
    SPELL_CUSTOM_ERROR_THE_BALLISTA_CANNOT_BE_USED_WHILE_ON_FIRE        = 380, // The ballista cannot be used while on fire.
    SPELL_CUSTOM_ERROR_YOU_MUST_TARGET_A_DREAD_GLADIATOR_ITEM           = 381, // You must target a Dread Gladiator's item to upgrade.
    SPELL_CUSTOM_ERROR_YOU_DO_KNOT_KNOW_HOW_TO_TAME_BLOOD_BEASTS        = 382, // You do not know how to tame Blood Beasts.
    SPELL_CUSTOM_ERROR_CAN_ONLY_BE_USED_IN_THE_EVENING                  = 385, // Can only be used in the evening.
    SPELL_CUSTOM_ERROR_REQUIRES_PAKU_TO_BE_YOUR_CHOSEN_LOA              = 386, // Requires Pa'ku to be your chosen loa.
    SPELL_CUSTOM_ERROR_REQUIRES_VIGOR_ENGAGED                           = 387, // Requires V.I.G.O.R. Engaged.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_IS_NOT_HUNGRY                        = 388, // Your target is not hungry.
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_HAVE_ON_TREASURE_MAP_MISSION        = 389, // You can only have one treasure map mission at a time.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_A_SILAS_SPHERE_OF_TRANSMUTATION = 390, // You already have a Silas' Sphere of Transmuation.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_HAVE_THE_MALLET_OF_THUNDEROUS_SKINS   = 391, // You do not have the Mallet of Thunderous Skins.
    SPELL_CUSTOM_ERROR_YOU_MUST_HAVE_AN_OPEN_STABLE_SLOT                = 393, // You must have an open stable slot.
    SPELL_CUSTOM_ERROR_DOES_NOT_WORK_ON_CRITTERS                        = 394, // Does not work on critters.
    SPELL_CUSTOM_ERROR_CAN_ONLY_BE_USED_ON_HATI                         = 395, // Can only be used on Hati.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_IWENS_ENCHANTING_ROD            = 396, // You already have an Iwen's Enchanting Rod.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_MALLET_OF_THUNDEROUS_SKINS      = 397, // You already have a Mallet of Thunderous Skins.
    SPELL_CUSTOM_ERROR_CAN_ONLY_BE_USED_ON_INERT_TIDE_WATCHERS_OR_VOODOO_MASKS = 398, // Can only be used on Inert Tide Watchers or Inert Voodoo Masks.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_AT_SHRINE_TO_MAKE_OFFERING_TO_LOA    = 399, // You must be at a Shrine to make an offering to a Loa.
    SPELL_CUSTOM_ERROR_REQUIRES_EMERALD_EMPOWERMENT                     = 400, // Requires Emerald Empowerment.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_AN_HONORED_TAUREN                    = 401, // You must be an honored tauren.
    SPELL_CUSTOM_ERROR_REQUIRES_CHITTERSPINE_MEAT                       = 402, // Requires Chitterspine Meat.
    SPELL_CUSTOM_ERROR_REQUIRES_HEART_FORGE                             = 403, // Requires Heart Forge.
    SPELL_CUSTOM_ERROR_NOT_AUTHORIZED_TO_ACCESS_CHARGING_STATION        = 405, // You are not authorized to access this Charging Station. Speak to Flux.
    SPELL_CUSTOM_ERROR_REQUIRES_MARDIVAS_ARCANE_COFFER                  = 406, // Requires Mardivas's Arcane Coffer
    SPELL_CUSTOM_ERROR_REQUIRES_HEART_OF_AZEROTH_ATOP_HEART_FORGE       = 407, // Requires Heart of Azeroth placed atop Heart Forge.
    SPELL_CUSTOM_ERROR_REQUIRES_BRINESTONE_PICKAXE                      = 408, // Requires a Brinestone Pickaxe.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_COLLECTED_DATA_ON_THIS_TARGET        = 409, // You have already collected data on this target.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_THIS_ESSENCE_FOR_CURRENT_SPEC   = 410, // You already have this Essence for your current loot specialization
    SPELL_CUSTOM_ERROR_YOU_CANNOT_SUMMON_ANOTHER_PET_WHILE_RIDING_HATI  = 411, // You cannot summon another pet while riding Hati.
    SPELL_CUSTOM_ERROR_YOU_HAVE_ALREADY_COLLECTED_THIS_AZEROTH_MINI     = 422, // You have already collected this Azeroth Mini
    SPELL_CUSTOM_ERROR_YOUR_TARGET_IS_ALREADY_AFFECTED_BY_TEA_TIME      = 412, // Your target is already affected by Tea Time!
    SPELL_CUSTOM_ERROR_YOU_MUST_COMPLETE_QUEST_THE_HEART_FORGE_TO_INFUSE_ESSENCE = 413, // You must complete the quest "The Heart Forge" to infuse an Essence
    SPELL_CUSTOM_ERROR_THIS_TARGET_DOES_NOT_HAVE_YOUR_RAZOR_CORAL       = 414, // This target does not have your Razor Coral.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_HAVE_ENOUGH_OF_THAT_ITEM              = 415, // You do not have enough of that item.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_IS_NOT_WEARING_UNBOUND_CURSED_LOVERS_RING = 417, // Your target is not wearing an unbound Cursed Lover's Ring
    SPELL_CUSTOM_ERROR_YOUR_CURSED_LOVERS_RING_IS_ALREDY_BOUND          = 418, // Your Cursed Lover's Ring is already bound
    SPELL_CUSTOM_ERROR_YOU_MUST_TARGET_A_NOTORIUS_GLADIATOR_ITEM        = 421, // You must target a Notorious Gladiator's item to upgrade.
    SPELL_CUSTOM_ERROR_YOU_CANT_CARRY_MORE_PICKAXES_CHUM_SEEDS          = 423, // You can't carry any more Brinestone Pickaxes, Chum, or Germinating Seeds.
    SPELL_CUSTOM_ERROR_REQUIRES_HOLIDAY_FEAST_OF_WINTER_WEIL            = 424, // Requires holiday: Feast of Winter Veil
    SPELL_CUSTOM_ERROR_REQUIRES_ASHJRAKAMAS_SHROUD_OF_RESOLVE           = 425, // Requires Ashjra'kamas, Shroud of Resolve.
    SPELL_CUSTOM_ERROR_REQUIRES_WAR_MODE                                = 426, // Requires War Mode.
    SPELL_CUSTOM_ERROR_ONLY_ONE_OF_THIS_MASK_MAY_BE_WORN                = 427, // Only one of this mask may be worn.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_ASCEND_WHILE_THE_TARRAGRUE_IS_NEARBY  = 428, // You cannot ascend while the Tarragrue is nearby.
    SPELL_CUSTOM_ERROR_TARGET_DOES_NOT_HAVE_A_VALID_AZERITE_ESSENCE     = 429, // Target does not have a valid Azerite Essence.
    SPELL_CUSTOM_ERROR_YOUR_MIND_IS_STILL_RECOVERING_FROM_RECENT_VISION = 430, // Your mind is still recovering from a recent vision.
    SPELL_CUSTOM_ERROR_REQUIRES_VESSEL_OF_HORRIFIC_VISIONS              = 431, // Requires Vessel of Horrific Visions.
    SPELL_CUSTOM_ERROR_REQUIRES_ALL_PARTY_MEMBERS_TO_BE_WEARING_ASHJRAKAMAS_SHROUD_OF_RESOLVE = 432, // Requires all party members to be wearing Ashjra'kamas, Shroud of Resolve.
    SPELL_CUSTOM_ERROR_REQUIRES_ALL_PARTY_MEMBERS_TO_POSSESS_A_VESSEL_OF_HORRIFIC_VISIONS = 434, // Requires all party members to possess a Vessel of Horrific Visions.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_THE_HIGHEST_RANKED_ESSENCE_AVAILABLE_FROM_THIS_SOURCE = 435, // You already have the highest ranked Essence available from this source.
    SPELL_CUSTOM_ERROR_REQUIRES_DARKMOON_GAME_TOKEN                     = 436, // Requires Darkmoon Game Token.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_THE_RIGHT_PROFESSION                 = 437, // You are not the right profession.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_KNOW_HOW_TO_CRAFT_A_VOID_FOCUS       = 438, // You already know how to craft a Void Focus.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_KNOW_THE_RECIPES_IN_THIS_BOOK        = 439, // You already know the recipes in this book.
    SPELL_CUSTOM_ERROR_YOU_MUST_TARGET_A_CORRUPTED_GLADIATORS_ITEM      = 440, // You must target a Corrupted Gladiator's item to upgrade.
    SPELL_CUSTOM_ERROR_REQUIRES_THE_FIX_IT_STICK                        = 441, // Requires the Fix-It-Stick.
    SPELL_CUSTOM_ERROR_THAT_ITEM_CANNOT_RECEIVE_ADDITIONAL_SOCKETS      = 442, // That item cannot receive additional sockets.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_A_CONTRACTED_VETERAN_TROOP      = 443, // You already have a contracted veteran troop.
    SPELL_CUSTOM_ERROR_YOU_ARE_CURRENTLY_AT_YOUR_TROOP_CAPACITY         = 444, // You are currently at your troop capacity.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_ANIMA                       = 445, // You don't have enough Anima
    SPELL_CUSTOM_ERROR_TARGET_ALREADY_HOLDING_VOID_TOUCHED_SKULL        = 446, // That player is already holding a void-touched skull.
    SPELL_CUSTOM_ERROR_TARGETS_INVENTORY_IS_FULL                        = 447, // Target's inventory is full.
    SPELL_CUSTOM_ERROR_TARGETS_MIND_IS_PROTECTED_BY_NEURAL_SILENCER     = 448, // Your target's mind is protected by a neural silencer.
    SPELL_CUSTOM_ERROR_ALL_TARGETS_MINDS_ARE_PROTECTED_BY_NEURAL_SILENCERS = 449, // All of your targets' minds are protected by neural silencers.
    SPELL_CUSTOM_ERROR_YOU_MUST_FIND_A_MORE_POWERFUL_CORE_TO_PROGRESS_YOUR_CLOAK_RANKS_FURTHER = 450, // You must find a more powerful core to progress your cloak ranks further.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_USE_THIS_ITEM_IN_WAR_MODE             = 451, // You cannot use this item in War Mode.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_MAKE_YOUR_CAMP_HERE                   = 452, // You cannot make your camp here.
    SPELL_CUSTOM_ERROR_REQUIRES_TITANIC_BEACON                          = 453, // Requires Titanic Beacon
    SPELL_CUSTOM_ERROR_THAT_OBJECT_IS_LOCKED                            = 454, // That Object is Locked.
    SPELL_CUSTOM_ERROR_INVALID_COMBINATION                              = 455, // Invalid Combination.
    SPELL_CUSTOM_ERROR_NO_NEARBY_ENEMY_PLAYERS_ARE_CORRUPTED            = 456, // No nearby enemy players are corrupted.
    SPELL_CUSTOM_ERROR_THAT_SPELL_IS_ALREADY_ACTIVE                     = 457, // That spell is already active
    SPELL_CUSTOM_ERROR_YOU_CANNOT_USE_THIS_WHEN_THE_TARRAGRUE_HAS_BEEN_ALERTED = 458, // You cannot use this when the Tarragrue has been alerted.
    SPELL_CUSTOM_ERROR_THAT_GUEST_ALREADY_HAS_TEA                       = 459, // That guest already has tea.
    SPELL_CUSTOM_ERROR_REQUIRES_SHADOWLANDS_SKINNING                    = 460, // Requires Shadowlands Skinning.
    SPELL_CUSTOM_ERROR_REQUIRES_HUNTERS_MARK_ON_A_TARGET                = 461, // Requires Hunter's Mark on a target.
    SPELL_CUSTOM_ERROR_HOUNDMASTER_LOKSEY_IS_BUSY                       = 462, // Houndmaster Loksey is busy.
    SPELL_CUSTOM_ERROR_REQUIRES_COIL_OF_ROPE                            = 463, // Requires Coil of Rope.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_A_REST_AREA                           = 464, // Must be in a rest area.
    SPELL_CUSTOM_ERROR_TARGET_IS_LINKED_TO_SOMEBODY_ELSE                = 465, // Target is linked to somebody else.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_A_SUMMONED_GHOUL                   = 466, // You don't have a summoned Ghoul.
    SPELL_CUSTOM_ERROR_ONE_OF_YOUR_PARTY_MEMBERS_IS_AN_INELIGIBLE_CLASS = 467, // One of your party members is an ineligible class.
    SPELL_CUSTOM_ERROR_YOU_MUST_SELECT_A_SOULBIND_BOSS_AND_TIER_FIRST   = 468, // You must select a soulbind, boss, and tier first.
    SPELL_CUSTOM_ERROR_THAT_GUEST_DOESNT_WANT_THIS                      = 469, // That guest doesn't want this.
    SPELL_CUSTOM_ERROR_YOU_MUST_DEFEAT_THE_EMPOWERED_GUARD_TO_ASCEND    = 470, // You must defeat the Empowered guard to ascend.
    SPELL_CUSTOM_ERROR_REQUIRES_SOULSTEEL_FORGE                         = 471, // Requires Soulsteel Forge.
    SPELL_CUSTOM_ERROR_REQUIRES_PROOF_OF_PURITY                         = 472, // Requires Proof of Purity
    SPELL_CUSTOM_ERROR_REQUIRES_PROOF_OF_HUMILITY                       = 473, // Requires Proof of Humility
    SPELL_CUSTOM_ERROR_REQUIRES_PROOF_OF_COURAGE                        = 474, // Requires Proof of Courage
    SPELL_CUSTOM_ERROR_REQUIRES_PROOF_OF_WISDOM                         = 475, // Requires Proof of Wisdom
    SPELL_CUSTOM_ERROR_REQUIRES_PROOF_OF_LOYALTY                        = 476, // Requires Proof of Loyalty
    SPELL_CUSTOM_ERROR_REQUIRES_ARCANE_SPECILIZATION                    = 477, // Requires Arcane Specilization.
    SPELL_CUSTOM_ERROR_PLEASE_GATHER_YOUR_PARTY_BEFORE_QUEUING          = 478, // Please gather your party before queuing.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_GARGON               = 479, // You do not know how to tame Gargon.
    SPELL_CUSTOM_ERROR_REQUIRES_DEAD_SPRIGGAN                           = 480, // Requires Dead Spriggan
    SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_A_PROFESSION_JOURNAL_THIS_WEEK  = 481, // You have already used a Profession Journal this week.
    SPELL_CUSTOM_ERROR_REQUIRES_MORDRETHAR_THE_DEATH_GATE               = 482, // Requires Mord'rethar: The Death Gate.
    SPELL_CUSTOM_ERROR_REQUIRES_PLAGUEFALLEN                            = 483, // Requires Plaguefallen
    SPELL_CUSTOM_ERROR_YOU_CANNOT_FIT_THROUGH_THERE                     = 484, // You cannot fit through there.
    SPELL_CUSTOM_ERROR_A_BINDING_RITUAL_PREVENTS_THIS_FROM_OPENING      = 485, // A binding ritual prevents this from opening.
    SPELL_CUSTOM_ERROR_THAT_CHARM_IS_ALREADY_APPLIED                    = 486, // That charm is already applied.
    SPELL_CUSTOM_ERROR_THAT_SIGIL_IS_ALREADY_APPLIED                    = 487, // That sigil is already applied.
    SPELL_CUSTOM_ERROR_AT_LEAST_ONE_GUEST_MUST_RSVP_BEFORE_YOU_OPEN_COURT = 488, // At least one guest must RSVP before you open court.
    SPELL_CUSTOM_ERROR_THERE_IS_NO_TIME_LIMIT_TO_INCREASE               = 489, // There is no time limit to increase.
    SPELL_CUSTOM_ERROR_YOUR_HEART_OF_AZEROTH_IS_CURRENTLY_DISABLED      = 490, // Your Heart of Azeroth is currently disabled.
    SPELL_CUSTOM_ERROR_ESSENCE_YOU_ARE_TRYING_TO_ACTIVATE_IS_INVALID    = 491, // The Essence you are trying to activate is invalid.
    SPELL_CUSTOM_ERROR_REQUIRES_MEDALLION_OF_SERVICE                    = 492, // Requires Medallion of Service
    SPELL_CUSTOM_ERROR_ALL_PLAYERS_MUST_HAVE_QUEST_TORGHAST_TOWER_OF_THE_DAMNED = 493, // All players must have quest - Torghast: Tower of the Damned.
    SPELL_CUSTOM_ERROR_REQUIRES_SHADOWLANDS_ENGINEERING                 = 494, // Requires Shadowlands Engineering
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_IN_DEEP_ENOUGH_WATER                 = 495, // You are not in deep enough water.
    SPELL_CUSTOM_ERROR_REQUIRES_FRESH_WATERS_OF_ARDENWEALD_OR_BASTION   = 496, // Requires the fresh waters of Ardenweald or Bastion
    SPELL_CUSTOM_ERROR_REQUIRES_30_INFUSED_RUBIES                       = 497, // Requires 30 Infused Rubies
    SPELL_CUSTOM_ERROR_THE_CURSE_OF_TERAMANIKS_LEGACY_IS_KEEPING_YOUR_MOUNTS_FROM_HEEDING_YOUR_CALL = 498, // The Curse of Teramanik's Legacy is keeping your mounts from heeding your call.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_CLOUD_SERPENTS       = 499, // You do not know how to tame Cloud Serpents.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_UNDEAD_CREATURES     = 500, // You do not know how to tame Undead creatures.
    SPELL_CUSTOM_ERROR_REQUIRES_THE_FORGE_OF_BONDS                      = 501, // Requires the Forge of Bonds
    SPELL_CUSTOM_ERROR_REQUIRES_GATAMATOS                               = 502, // Requires Gatamatos
    SPELL_CUSTOM_ERROR_MUST_BE_CHANNELLING_MIND_SEAR                    = 503, // Must be channelling Mind Sear.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ANY_PERIODIC_EFFECTS_ACTIVE        = 504, // You don't have any periodic effects active.
    SPELL_CUSTOM_ERROR_YOU_ARE_NOT_BEST_FRIENDS_WITH_ANY_EMBER_COURT_GUESTS = 505, // You are not Best Friends with any Ember Court guests.
    SPELL_CUSTOM_ERROR_YOU_MUST_OBTAIN_VENOMOUS_SOLVENTS                = 506, // You must obtain Venomous Solvents.
    SPELL_CUSTOM_ERROR_YOU_MUST_OBTAIN_DREAD_POLLEN                     = 507, // You must obtain Dread Pollen.
    SPELL_CUSTOM_ERROR_A_PARTY_MEMBER_DOES_NOT_HAVE_THAT_LAYER_UNLOCKED = 508, // A party member does not have that layer unlocked
    SPELL_CUSTOM_ERROR_INVENTORY_IS_FULL                                = 509, // Inventory is full.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_ANIMA_TO_DEPOSIT                     = 510, // You have no Anima to deposit
    SPELL_CUSTOM_ERROR_YOUR_MOUNT_IGNORES_YOUR_CALL_WITHIN_THE_MAW      = 511, // Your mount ignores your call within The Maw.
    SPELL_CUSTOM_ERROR_YOUR_BUTLER_IS_ALREADY_PRESENT_SOMEWHERE_IN_THE_EMBER_COURT = 512, // Your butler is already present somewhere in the Ember Court.
    SPELL_CUSTOM_ERROR_YOU_HAVE_ALREADY_BUILT_THIS_CONSTRUCT            = 513, // You have already built this construct
    SPELL_CUSTOM_ERROR_REQUIRES_INNER_ALTAR_OF_DOMINATION               = 514, // Requires Inner Altar of Domination
    SPELL_CUSTOM_ERROR_PARTY_MEMBER_DOES_NOT_MEET_REQUIREMENTS_TO_QUEUE = 515, // A party member does not meet the requirements to queue
    SPELL_CUSTOM_ERROR_NO_CONSTRUCT_CURRENTLY_ACTIVE                    = 516, // No construct currently active
    SPELL_CUSTOM_ERROR_COMPLETE_THE_QUEST_LINE_WELCOME_TO_ZANDALAR      = 517, // Complete the quest line "Welcome to Zandalar" to use this spell.
    SPELL_CUSTOM_ERROR_COMPLETE_THE_QUEST_LINE_A_NATION_DIVIDED         = 518, // Complete the quest line "A Nation Divided" to use this spell.
    SPELL_CUSTOM_ERROR_CANNOT_BE_USED_ON_COMMON_QUALITY_ITEMS           = 519, // Cannot be used on Common quality items.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_PLEDGED_TO_THE_VENTHYR               = 520, // You must be pledged to the Venthyr.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_PLEDGED_TO_THE_NIGHT_FAE             = 521, // You must be pledged to the Night Fae.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_PLEDGED_TO_THE_KYRIAN                = 522, // You must be pledged to the Kyrian.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_PLEDGED_TO_THE_NECROLORDS            = 523, // You must be pledged to the Necrolords.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_THE_SHADOWLANDS                   = 524, // You must be in the Shadowlands.
    SPELL_CUSTOM_ERROR_REQUIRES_SANCTUM_RESERVOIR                       = 525, // Requires Sanctum Reservoir.
    SPELL_CUSTOM_ERROR_THIS_WILDSEED_OF_REGROWTH_IS_STILL_INCUBATING    = 526, // This Wildseed of Regrowth is still incubating.
    SPELL_CUSTOM_ERROR_THIS_WILDSEED_OF_REGROWTH_IS_STILL_GROWING       = 527, // This Wildseed of Regrowth is still growing.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_PARTY_LEADER_TO_START_THIS_ESCORT    = 528, // You must be the party leader to start this escort.
    SPELL_CUSTOM_ERROR_YOU_HAVE_FULLY_UPGRADED_ALL_OF_YOUR_CONDUITS     = 529, // You have fully upgraded all of your Conduits.
    SPELL_CUSTOM_ERROR_YOU_HAVE_ALREADY_ADDED_THAT_CONDUIT              = 530, // You have already added that Conduit to the Forge of Bonds.
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_WEAKENED                          = 531, // Target must be weakened.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_ADD_THAT_CONDUIT_TO_FORGE_OF_BONDS    = 532, // You cannot add that Conduit to the Forge of Bonds.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_SOULSHAPE_DURING_LICHBORNE            = 533, // You cannot Soulshape during Lichborne.
    SPELL_CUSTOM_ERROR_YOU_CANT_DO_THAT_WHILE_CARRYING_AN_ANIMACONE     = 534, // You can't do that while carrying an Animacone.
    SPELL_CUSTOM_ERROR_NECESSARY_CONSTRUCT_NOT_PRESENT                  = 535, // Necessary construct not present.
    SPELL_CUSTOM_ERROR_THAT_GUEST_IS_ALREADY_COVERED_IN_GELATIN         = 536, // That guest is already covered in gelatin.
    SPELL_CUSTOM_ERROR_YOU_NEED_TO_WAIT_TO_USE_THIS_ITEM                = 537, // You need to wait to use this item.
    SPELL_CUSTOM_ERROR_THAT_ALLY_ALREADY_HAS_TEA                        = 538, // That ally already has tea.
    SPELL_CUSTOM_ERROR_TARGET_DOES_NOT_NEED_TEA                         = 539, // The target does not need tea.
    SPELL_CUSTOM_ERROR_THEY_DONT_DESERVE_YOUR_FANCY_TEA                 = 540, // They don't deserve your fancy tea!
    SPELL_CUSTOM_ERROR_YOUR_GORM_PREFERS_TO_EAT_DEAD_THINGS             = 541, // Your gorm prefers to eat dead things.
    SPELL_CUSTOM_ERROR_YOUR_GORM_HAS_ALREADY_EATEN_THAT_CORPSE          = 542, // Your gorm has already eaten that corpse.
    SPELL_CUSTOM_ERROR_YOU_NEED_A_GORMLING_FROM_NIYA_TO_DO_THAT         = 543, // You need a gormling from Niya to do that.
    SPELL_CUSTOM_ERROR_TARGET_IS_ALREADY_SHRUNKEN                       = 544, // Target is already shrunken.
    SPELL_CUSTOM_ERROR_TARGET_IS_ALREADY_ENLARGED                       = 545, // Target is already enlarged.
    SPELL_CUSTOM_ERROR_LADY_MOONBERRYS_WAND_IS_FOR_ENEMIES_AND_MAWRATS  = 546, // Lady Moonberry's wand is meant for enemies and mawrats.
    SPELL_CUSTOM_ERROR_LADY_MOONBERRYS_WAND_IS_FOR_ENEMIES              = 547, // Lady Moonberry's wand is meant for enemies.
    SPELL_CUSTOM_ERROR_TARGET_IS_ALREADY_TRANSFORMED_INTO_A_SNAIL       = 548, // Target is already transformed into a snail.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_MUST_BE_BELOW_50_PCT_HEALTH          = 549, // Your target must be below 50% health.
    SPELL_CUSTOM_ERROR_LADY_MOONBERRYS_WAND_IS_DRAINED_OF_POWER         = 550, // Lady Moonberry's wand is drained of power.
    SPELL_CUSTOM_ERROR_THIS_BOOK_HOLDS_NO_RECIPES_FOR_YOUR_PROFESSION   = 551, // This book holds no recipes for your profession.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_KORTHIAN_RELICS_IN_YOUR_INVENTORY    = 552, // You have no Korthian Relics in your Inventory.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_THE_RIFT_TO_INTERACT_WITH_THIS    = 553, // You must be in the Rift to interact with this.
    SPELL_CUSTOM_ERROR_CANNOT_SUMMON_WHILE_IN_THE_RIFT                  = 554, // Cannot summon while in the Rift.
    SPELL_CUSTOM_ERROR_YOU_NEED_AN_ACTIVE_ELEMENTAL_SHIELD              = 600, // You need an active Elemental Shield.
    SPELL_CUSTOM_ERROR_SPEAK_TO_ARCHIVIST_TO_TURN_IN_RELIC_FRAGMENTS    = 601, // Speak to the Archivist to turn in relic fragments.
    SPELL_CUSTOM_ERROR_REQUIRES_RESEARCH_REPORTS_ANCIENT_SHRINES        = 602, // Requires knowledge from Research Reports: Ancient Shrines
    SPELL_CUSTOM_ERROR_YOUR_STEWARD_IS_NOT_PRESENT                      = 603, // Your steward companion is not present.
    SPELL_CUSTOM_ERROR_YOUR_STEWARD_HAS_ALREADY_BEEN_TRANSFORMED        = 604, // Your steward companion has already been transformed.
    SPELL_CUSTOM_ERROR_REQUIRES_KORTHIAN_RELICS                         = 605, // Requires Korthian Relics
    SPELL_CUSTOM_ERROR_REQUIRES_FULL_EMPOWERED_BAR                      = 606, // Requires Full Empowered Bar
    SPELL_CUSTOM_ERROR_REQUIRES_YOU_TO_BE_RIDING_A_YAK                  = 607, // Requires you to be riding a yak.
    SPELL_CUSTOM_ERROR_JAITHYS_IS_NOT_A_CANNIBAL                        = 609, // Jaithys is many things, but Jaithys is not a cannibal.
    SPELL_CUSTOM_ERROR_THAT_ITEM_IS_PUNY_UNWORTHY_FIND_ANOTHER          = 610, // That item is puny. Unworthy. Find another.
    SPELL_CUSTOM_ERROR_JAITHYS_HUNGERS_ONLY_FOR_WEAPONS                 = 611, // Jaithys hungers only for weapons. Only weapons will do.
    SPELL_CUSTOM_ERROR_RETURN_TO_RELIQUARY_OF_REMEMBERANCE_TO_SUBMIT_KORTHIAN_RELICS = 612, // Return to the Reliquary of Rememberance to submit Korthian Relics to Archivist Roh-Suir.
    SPELL_CUSTOM_ERROR_SHARDS_OF_DOMINATION_CAN_BE_REMOVED_BY_SOULFIRE_CHISEL = 615, // Shards of Domination can only be removed by the Soulfire Chisel.
    SPELL_CUSTOM_ERROR_YOU_HAVE_LEARNED_EVERYTHING_FROM_THAT_MAP        = 616, // You have learned everything from that map.
    SPELL_CUSTOM_ERROR_YOU_MUST_TARGET_A_CRITTER_TO_HELP_IT_ATONE_FOR_ITS_SINS = 617, // You must target a critter to help it atone for its sins.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_A_MEMBER_OF_THE_KYRIAN_COVENANT_OR_HAVE_REACHED_RENOWN_80_WITH_THE_KYRIAN = 619, // You must be a member of the Kyrian Covenant or have reached Renown 80 with the Kyrian.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_A_MEMBER_OF_THE_NECROLORD_COVENANT_OR_HAVE_REACHED_RENOWN_80_WITH_THE_NECROLORDS = 620, // You must be a member of the Necrolord Covenant or have reached Renown 80 with the Necrolords.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_A_MEMBER_OF_THE_NIGHT_FAE_COVENANT_OR_HAVE_REACHED_RENOWN_80_WITH_THE_NIGHT_FAE = 621, // You must be a member of the Night Fae Covenant or have reached Renown 80 with the Night Fae.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_A_MEMBER_OF_THE_VENTHYR_COVENANT_OR_HAVE_REACHED_RENOWN_80_WITH_THE_VENTHYR = 622, // You must be a member of the Venthyr Covenant or have reached Renown 80 with the Venthyr.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_THAT_MUCH_RENOWN_WITH_YOUR_ACTIVE_COVENANT = 627, // You already have that much Renown with your active Covenant.
    SPELL_CUSTOM_ERROR_CANNOT_EXCEED_THE_MAXIMUM_FOR_THAT_CURRENCY      = 628, // Cannot exceed the maximum for that currency.
    SPELL_CUSTOM_ERROR_REQUIRES_ADDITIONAL_COSMIC_ENERGY                = 629, // Requires additional Cosmic Energy.
    SPELL_CUSTOM_ERROR_REQUIRES_ARCHITECT                               = 630, // Requires Architect.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_SITTING_TO_DO_THAT                   = 631, // You must be sitting to do that.
    SPELL_CUSTOM_ERROR_REQUIRES_POLLEN_CLOUD                            = 632, // Requires Pollen Cloud.
    SPELL_CUSTOM_ERROR_REQUIRES_5_LOST_OVOIDS                           = 633, // Requires 5 Lost Ovoids.
    SPELL_CUSTOM_ERROR_YOU_HAVE_TOO_MANY_TEMPORARY_ENHANCEMENTS         = 634, // You have too many temporary enhancements.
    SPELL_CUSTOM_ERROR_YOU_HAVE_OTHER_WAYS_TO_SUMMON_POCOPOC            = 635, // You have other ways to summon Pocopoc while in Zereth Mortis.
    SPELL_CUSTOM_ERROR_REQUIRES_MORE_SYLLABIC_RECALL                    = 636, // Requires more Syllabic Recall.
    SPELL_CUSTOM_ERROR_THIS_BATTLE_PET_CANNOT_RIDE_ON_MAGIC_SAUCER      = 637, // This battle pet is unable to ride on the Magic Saucer.
    SPELL_CUSTOM_ERROR_YOU_CAN_ONLY_DO_THIS_WHILE_MIDAIR                = 638, // You can only do this while midair.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_DO_THAT_WHILE_AIRBORNE                = 639, // You cannot do that while airborne.
    SPELL_CUSTOM_ERROR_POCOPOC_IS_UNAVAILABLE_ON_QUESTLINE              = 640, // Pocopoc is unavailable to summon during the questline A Means to an End.
    SPELL_CUSTOM_ERROR_CANNOT_CAST_THAT_WITH_AURA_OF_RECKONING_TALENT   = 650, // You cannot cast that while Aura of Reckoning is talented.
    SPELL_CUSTOM_ERROR_REQUIRES_SULFURON_SLAMMER                        = 711, // Requires Sulfuron Slammer
    SPELL_CUSTOM_ERROR_NOT_READY_YET                                    = 788, // Not ready yet.
    SPELL_CUSTOM_ERROR_QUALITY_OF_TIERED_MEDALLION_SETTING_IS_TOO_LOW   = 789, // The quality of your Tiered Medallion Setting is too low to add another socket to this item.
    SPELL_CUSTOM_ERROR_YOU_HAVE_NOT_LEARNED_BARREL_ROLL                 = 790, // You have not learned Barrel Roll.
    SPELL_CUSTOM_ERROR_TARGET_MUST_BE_AN_ELITE_ELEMENTAL                = 791, // Target must be an Elite Elemental.
    SPELL_CUSTOM_ERROR_SKILL_CHECK_ALREADY_FAILED                       = 792, // Skill check already failed.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_WAS_RECENTLY_FED                     = 793, // Your target was recently fed.
    SPELL_CUSTOM_ERROR_CANNOT_LURE_ELUSIVE_CREATURE_TOWARDS_TOWN        = 794, // You cannot lure an elusive creature towards a town.
    SPELL_CUSTOM_ERROR_NO_WORTHWHILE_CREATURES_IN_AREA_TO_LURE_OUT      = 795, // There are no worthwhile creatures in this area to lure out.
    SPELL_CUSTOM_ERROR_CANNOT_LURE_WILD_BEAST                           = 796, // This is a daycare for whelps. Why would you try to lure a wild beast here...?
    SPELL_CUSTOM_ERROR_YOU_HAVE_NO_ARCANE_ESSENCES_IN_YOUR_INVENTORY    = 797, // You have no Arcane Essences in your inventory.
    SPELL_CUSTOM_ERROR_THAT_PLAYER_IS_CURRENTLY_NOT_INTERESTED_IN_ENGAGING_WITH_YOUR_SHENANIGANS = 798, // That player is currently not interested in engaging with your shenanigans.
    SPELL_CUSTOM_ERROR_CANT_BE_CAST_ON_NON_PLAYER_CHARACTERS            = 799, // Can't be cast on Non Player Characters.
    SPELL_CUSTOM_ERROR_A_SIGNAL_FLARE_WAS_RECENTLY_FIRED_AT_THIS_LOCATION = 800, // A signal flare was recently fired at this location.
    SPELL_CUSTOM_ERROR_THIS_TINKER_IS_TOO_COMPLICATED_FOR_YOU           = 801, // This tinker is too complicated for you.
    SPELL_CUSTOM_ERROR_THE_DUCK_REFUSES_TO_PLAY_WHILE_ANOTHER_MAESTRO_IS_NEARBY = 802, // The duck refuses to play while another maestro is nearby.
    SPELL_CUSTOM_ERROR_YOU_HAVE_STUDIED_THESE_NOTES_EXTENSIVELYAND_THERE_IS_NOTHING_NEW_TO_LEARN_FROM_THEM = 803, // You have studied these notes extensively and there is nothing new to learn from them.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_GOLD                        = 804, // You don't have enough gold.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_OTTUK                = 805, // You do not know how to tame Ottuk.
    SPELL_CUSTOM_ERROR_CLAN_AYLAAG_IS_CURRENTLY_TRAVELLINGAND_CANNOT_BE_TELEPORTED_TO = 806, // Clan Aylaag is currently travelling and cannot be teleported to.
    SPELL_CUSTOM_ERROR_NOT_ENOUGH_INSANITY                              = 807, // Not enough insanity
    SPELL_CUSTOM_ERROR_YOU_MUST_WAIT_TO_ACCESS_THIS_AGAIN               = 808, // You must wait to access this again.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_KNOW_HOW_TO_TAME_DRAGONKIN            = 809, // You do not know how to tame Dragonkin.
    SPELL_CUSTOM_ERROR_REQUIRES_AN_EMPTY_SOUL_CAGE = 810, // Requires an Empty Soul Cage.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_A_CAGED_SOUL_OF_THAT_TYPE       = 811, // You already have a caged soul of that type.
    SPELL_CUSTOM_ERROR_YOU_CANT_DO_THAT_HERE                            = 812, // You can't do that here.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_HAVE_ANY_ELEMENTAL_GEMS_SOCKETED      = 813, // You do not have any elemental gems socketed.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_THE_DRAGON_ISLES                  = 814, // You must be in the Dragon Isles.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_DO_THAT_WHILE_UNDERWATER              = 815, // You cannot do that while underwater.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_RIDING_A_STOLEN_TAME_MAGMAMMOTH      = 816, // You must be riding a stolen Tame Magmammoth.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_FLYING_ABOVE_WATER_INSIDE_AN_ACTIVE_TUSKARR_FISHING_HOLE = 817, // You must be flying above water inside an active Tuskarr Fishing Hole.
    SPELL_CUSTOM_ERROR_YOU_ARE_ALREADY_BRAVE_ENOUGH_TO_CONTINUE_WITH_YOUR_EXPERIMENTATION = 818, // You are already brave enough to continue with your experimentation.
    SPELL_CUSTOM_ERROR_YOU_DONT_KNOW_HOW_TO_REPAIR_THIS_ITEM            = 819, // You don't know how to repair this item.
    SPELL_CUSTOM_ERROR_THERE_IS_NO_MORE_ROOM_ON_THAT_HANDHOLD           = 820, // There is no more room on that handhold.
    SPELL_CUSTOM_ERROR_YOU_MUST_UNBLOCK_THIS_SPOT_BY_COMPLETING_A_DAILY_QUEST = 821, // You must unblock this spot by completing a daily quest.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_CLOSER_TO_AN_ICE_HOLE_TO_DO_THAT     = 822, // You must be closer to an ice hole to do that.
    SPELL_CUSTOM_ERROR_SHADOWFLAME_IS_TOO_STRONG_TO_BEAR                = 823, // The shadowflame is too strong to bear.
    SPELL_CUSTOM_ERROR_SOMEONE_HAS_ALREADY_OVERLOADED_THIS              = 824, // Someone has already overloaded this.
    SPELL_CUSTOM_ERROR_REQUIRES_NOKHUD_TRAINING_COURSE                  = 825, // Requires Nokhud Training Course.
    SPELL_CUSTOM_ERROR_THIS_RECIPE_IS_CURRENTLY_DISABLED                = 826, // This recipe is currently disabled. Please try again later.
    SPELL_CUSTOM_ERROR_YOU_DO_NOT_HAVE_THE_CORRECT_BATTLE_PET_SUMMONED  = 827, // You do not have the correct battle pet summoned.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_AT_LEAST_ONE_CONJURED_PHIAL     = 828, // You already have at least one conjured phial.
    SPELL_CUSTOM_ERROR_MARKED_TOO_MANY_TREASURES_IN_THE_FORBIDDEN_REACH = 830, // You have already marked too many treasures in the Forbidden Reach. Collect a few before unsealing more Forbidden Reach treasure scrolls.
    SPELL_CUSTOM_ERROR_REQUIRES_A_DJARADIN_PILLAR_SHARD                 = 831, // Requires a Djaradin Pillar Shard.
    SPELL_CUSTOM_ERROR_REQUIRES_A_RESILIENT_STONE                       = 832, // Requires a Resilient Stone.
    SPELL_CUSTOM_ERROR_MYRRIT_CANNOT_CARRY_ANY_MORE_MAPS                = 835, // Myrrit cannot carry any more maps. Go on a dig with him!
    SPELL_CUSTOM_ERROR_SOME_GIFTSS_ARE_BETTER_LEFT_UNDELIVERED          = 836, // Some gifts are better left undelivered.
    SPELL_CUSTOM_ERROR_REQUIRES_NIFFEN_CAVE_DIVE_KEYAND_SHIELD_DISABLED = 850, // Requires Niffen Cave Dive Key and shield disabled.
    SPELL_CUSTOM_ERROR_ELUSIVE_CREATURE_BAIT_WAS_RECENTLY_USED          = 851, // You cannot lure anything in this area for a few minutes. Elusive Creature Bait was recently used.
    SPELL_CUSTOM_ERROR_MUST_BE_IN_QUIET_PLACE_WITHIN_CAER_DARROW        = 852, // Must be in a suitably quiet place within Caer Darrow.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ANY_GLIMMER_OF_LIGHTS_ACTIVE       = 856, // You don't have any Glimmer of Lights active.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_THE_SWIRLING_MOJO_STONE            = 999, // You don't have the Swirling Mojo Stone equipped.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_NEAR_A_DRAGONFLIGHT_OATHSTONE        = 1000, // You must be near one of the five dragonflight oathstones in the Dragon Isles.
    SPELL_CUSTOM_ERROR_CAN_ONLY_USE_THIS_ITEM_WHILE_AIRBORNE            = 1001, // You can only use this item while airborne.
    SPELL_CUSTOM_ERROR_THIS_PLAYER_IS_NOT_OPPOSITE_FACTION              = 1002, // This player is not of the opposite faction.
    SPELL_CUSTOM_ERROR_THIS_PLAYER_ALREADY_HAS_THIS_MOUNT               = 1003, // This player already has this mount.
    SPELL_CUSTOM_ERROR_YOUR_TARGET_IS_IN_WAR_MODE                       = 1004, // Your target is in War Mode.
    SPELL_CUSTOM_ERROR_COOLDOWN_RESET                                   = 1005, // Cooldown Reset
    SPELL_CUSTOM_ERROR_SOIL_NUTRIENTS_MUST_REPLENISH                    = 1006, // The nutrients of this soil must replenish before further growth.
    SPELL_CUSTOM_ERROR_TARGET_ALREADY_HAD_SOME_FEATHERS_PLUCKED         = 1007, // The target has already had some feathers plucked. It would be rude to take more.
    SPELL_CUSTOM_ERROR_THIS_CREATURE_HAS_ALREADY_BEEN_ATTUNED_WITH      = 1008, // This creature has already been attuned with recently.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_SOME_MULCH_PREPARED             = 1009, // You already have some mulch prepared. Use your current mulch first.
    SPELL_CUSTOM_ERROR_YOU_DONT_KNOW_HOW_TO_GATHER_THIS                 = 1010, // You don't know how to gather this.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ANY_ITEMS_OF_THIS_TYPE             = 1011, // You don't have any items of this type.
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ANY_RADIANT_REMNANTS               = 1012, // You don't have any Radiant Remnants.
    SPELL_CUSTOM_ERROR_TARGETS_RING_IS_ALREADY_BOUND_TO_ANOTHER_PLAYER  = 1013, // Your target's ring is already bound to another player.
    SPELL_CUSTOM_ERROR_TARGET_IS_NOT_WEARING_THIS_RING                  = 1014, // Your target is not also wearing this ring.
    SPELL_CUSTOM_ERROR_CAN_ONLY_BE_USED_ON_SOCKETABLE_PVP_TWW_ITEMS     = 1015, // Can only be used on socket eligible PvP items from the War Within expansion.
    SPELL_CUSTOM_ERROR_HARVESTBOTS_ALREADY_ACTIVE                       = 1016, // Harvestbots already active.
    SPELL_CUSTOM_ERROR_AIRSHIP_DAUNTLESS_IS_ALREADY_ACTIVE              = 1017, // The Airship Dauntless is already active.
    SPELL_CUSTOM_ERROR_CANNOT_SWAP_SPELLS_ON_COOLDOWN_IN_COMBAT         = 1026, // You cannot swap spells on cooldown while in combat.
    SPELL_CUSTOM_ERROR_MUST_EQUIP_CLOAK_OF_INFINITE_POTENTIAL           = 1027, // You must first equip the Cloak of Infinite Potential.
    SPELL_CUSTOM_ERROR_INSUFFICIENT_BRONZE                              = 1028, // You have insufficient Bronze to make this trade.
    SPELL_CUSTOM_ERROR_REQUIRES_SKYRIDING                               = 1029, // Requires Skyriding
    SPELL_CUSTOM_ERROR_YOU_ALREADY_OVERLOADED_THIS_GATHERING_NODE       = 1030, // You have already overloaded this gathering node.
    SPELL_CUSTOM_ERROR_YOU_DONT_KNOW_HOW_TO_OVERLOAD_THIS_NODE          = 1031, // You do not know how to Overload this gathering node.
    SPELL_CUSTOM_ERROR_TIMERUNNERS_CANNOT_TELEPORT_OUT_OF_PANDARIA      = 1032, // Timerunners cannot teleport outside of Pandaria.
    SPELL_CUSTOM_ERROR_SPECIALIZE_FURTHER_FOR_THESE_NOTES               = 1033, // Specialize further or improve your hasty handwriting to make sense of these notes.
    SPELL_CUSTOM_ERROR_THERE_IS_NOTHING_LEFT_TO_INVENT                  = 1034, // There is nothing left to invent and you cannot be convinced otherwise.
    SPELL_CUSTOM_ERROR_PLAYER_IN_PARTY_DOESNT_HAVE_THIS_TIER_UNLOCKED   = 1035, // A player in your party does not have this tier unlocked
    SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ANY_RADIANT_ECHOES                 = 1036, // You don't have any Radiant Echoes.
    SPELL_CUSTOM_ERROR_REQUIRES_TWW_PATHFINDER_UNLOCKED                 = 1037, // Requires The War Within Pathfinder Unlocked to use in this area.
    SPELL_CUSTOM_ERROR_CAN_ONLY_BE_USED_WHILE_IN_COMBAT                 = 1039, // Can only be used while in combat.
    SPELL_CUSTOM_ERROR_NOT_HIGH_ENOUGH_LEVEL_TO_ENTER_A_DELVE           = 1040, // You are not high enough level to enter a Delve.
    SPELL_CUSTOM_ERROR_WONDROUS_WISDOMBALL_IS_NONRESPONSIVE             = 1041, // For some reason the Wondrous Wisdomball is nonresponsive.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_HAVE_THIS_CURIO_IN_YOUR_COLLECTION   = 1042, // You already have this curio in your collection.
    SPELL_CUSTOM_ERROR_ALREADY_HAVE_IDENTIFIED_PROTOTYPE                = 1043, // You must choose what to do with your current prototype before identifying new ones.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_KHAZ_ALGAR_CONTRACT             = 1044, // You have already used a Khaz Algar Contract this week.
    SPELL_CUSTOM_ERROR_YOU_ALREADY_REVEALED_ALL_TODAY_PACT_LOCATIONS    = 1051, // You have revealed or completed all of today's Pact locations.
    SPELL_CUSTOM_ERROR_TIMERUNNERS_CANNOT_CAST_THIS_SPELL               = 1053, // Timerunners cannot cast this spell.
    SPELL_CUSTOM_ERROR_THIS_EMBLEM_HAS_NO_MAGIC_STORED                  = 2001, // The emblem has no magic stored.
    SPELL_CUSTOM_ERROR_YOU_MUST_BE_IN_VISAGE_FORM                       = 2222, // You must be in visage form to do this.
    SPELL_CUSTOM_ERROR_A_TRIAL_IS_BEING_UNDERGONE_NEARBY                = 2223, // A Trial is already being undergone nearby.
    SPELL_CUSTOM_ERROR_YOU_CANNOT_USE_VANTUS_RUNE_IN_STORY_MODE         = 2224, // You cannot use a Vantus Rune in Story Mode.
    SPELL_CUSTOM_ERROR_TOO_CLOSE_TO_ANOTHER_MOLTEN_RITUAL               = 2424, // You can't begin a molten ritual this close to another one.
    SPELL_CUSTOM_ERROR_EARTHEN_CANNOT_CONSUME_REGULAR_FOOD_OR_DRINK     = 2425, // Earthen cannot consume traditional food or drink.
};

enum StealthType
{
    STEALTH_GENERAL     = 0,
    STEALTH_TRAP        = 1,

    TOTAL_STEALTH_TYPES = 2
};

enum InvisibilityType
{
    INVISIBILITY_GENERAL                =  0,
    INVISIBILITY_UNK1                   =  1,
    INVISIBILITY_UNK2                   =  2,
    INVISIBILITY_TRAP                   =  3,
    INVISIBILITY_UNK4                   =  4,
    INVISIBILITY_UNK5                   =  5,
    INVISIBILITY_DRUNK                  =  6,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_1  =  7,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_2  =  8,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_3  =  9,
    INVISIBILITY_UNK10                  = 10,
    INVISIBILITY_UNK11                  = 11,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_4  = 12,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_5  = 13,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_6  = 14,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_7  = 15,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_8  = 16,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_9  = 17,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_10 = 18,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_11 = 19,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_12 = 20,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_13 = 21,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_14 = 22,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_15 = 23,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_16 = 24,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_17 = 25,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_18 = 26,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_19 = 27,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_20 = 28,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_21 = 29,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_22 = 30,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_23 = 31,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_24 = 32,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_25 = 33,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_26 = 34,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_27 = 35,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_28 = 36,
    INVISIBILITY_QUEST_ZONE_SPECIFIC_29 = 37,

    TOTAL_INVISIBILITY_TYPES            = 38
};

enum ServerSideVisibilityType
{
    SERVERSIDE_VISIBILITY_GM          = 0,
    SERVERSIDE_VISIBILITY_GHOST       = 1,

    TOTAL_SERVERSIDE_VISIBILITY_TYPES = 2
};

enum GhostVisibilityType
{
    GHOST_VISIBILITY_ALIVE = 0x1,
    GHOST_VISIBILITY_GHOST = 0x2
};

// Spell aura states
// EnumUtils: DESCRIBE THIS
enum AuraStateType
{   // (C) used in caster aura state     (T) used in target aura state
    // (c) used in caster aura state-not (t) used in target aura state-not
    AURA_STATE_NONE                         = 0,            // C   |
    AURA_STATE_DEFENSIVE                    = 1,            // CcTt|
    AURA_STATE_WOUNDED_20_PERCENT           = 2,            // CcT |
    AURA_STATE_UNBALANCED                   = 3,            // CcT | NYI
    AURA_STATE_FROZEN                       = 4,            //  c t|
    AURA_STATE_MARKED                       = 5,            // C  t| NYI
    AURA_STATE_WOUNDED_25_PERCENT           = 6,            //   T |
    AURA_STATE_DEFENSIVE_2                  = 7,            // Cc  | NYI
    AURA_STATE_BANISHED                     = 8,            //  c  |
    AURA_STATE_DAZED                        = 9,            //    t|
    AURA_STATE_VICTORIOUS                   = 10,           // C   |
    AURA_STATE_RAMPAGE                      = 11,           //     | NYI
    AURA_STATE_FAERIE_FIRE                  = 12,           //  c t|
    AURA_STATE_WOUNDED_35_PERCENT           = 13,           // CcT |
    AURA_STATE_RAID_ENCOUNTER_2             = 14,           //  cT |
    AURA_STATE_DRUID_PERIODIC_HEAL          = 15,           //   T |
    AURA_STATE_ROGUE_POISONED               = 16,           //     |
    AURA_STATE_ENRAGED                      = 17,           // C   |
    AURA_STATE_BLEED                        = 18,           //   T |
    AURA_STATE_VULNERABLE                   = 19,           //     | NYI
    AURA_STATE_ARENA_PREPARATION            = 20,           //  c  |
    AURA_STATE_WOUND_HEALTH_20_80           = 21,           //   T |
    AURA_STATE_RAID_ENCOUNTER               = 22,           // CcTt|
    AURA_STATE_HEALTHY_75_PERCENT           = 23,           // C   |
    AURA_STATE_WOUND_HEALTH_35_80           = 24,           //   T |
    AURA_STATE_WOUNDED_50_PERCENT           = 25            // C T |
};

#define PER_CASTER_AURA_STATE_MASK (\
    (1<<(AURA_STATE_RAID_ENCOUNTER_2-1))|(1<<(AURA_STATE_ROGUE_POISONED-1)))

// Spell mechanics
// EnumUtils: DESCRIBE THIS
enum Mechanics : uint32
{
    MECHANIC_NONE             = 0,
    MECHANIC_CHARM            = 1,
    MECHANIC_DISORIENTED      = 2,
    MECHANIC_DISARM           = 3,
    MECHANIC_DISTRACT         = 4,
    MECHANIC_FEAR             = 5,
    MECHANIC_GRIP             = 6,
    MECHANIC_ROOT             = 7,
    MECHANIC_SLOW_ATTACK      = 8,
    MECHANIC_SILENCE          = 9,
    MECHANIC_SLEEP            = 10,
    MECHANIC_SNARE            = 11,
    MECHANIC_STUN             = 12,
    MECHANIC_FREEZE           = 13,
    MECHANIC_KNOCKOUT         = 14,
    MECHANIC_BLEED            = 15,
    MECHANIC_BANDAGE          = 16,
    MECHANIC_POLYMORPH        = 17,
    MECHANIC_BANISH           = 18,
    MECHANIC_SHIELD           = 19,
    MECHANIC_SHACKLE          = 20,
    MECHANIC_MOUNT            = 21,
    MECHANIC_INFECTED         = 22,
    MECHANIC_TURN             = 23,
    MECHANIC_HORROR           = 24,
    MECHANIC_INVULNERABILITY  = 25,
    MECHANIC_INTERRUPT        = 26,
    MECHANIC_DAZE             = 27,
    MECHANIC_DISCOVERY        = 28,
    MECHANIC_IMMUNE_SHIELD    = 29, // Divine (Blessing) Shield/Protection and Ice Block
    MECHANIC_SAPPED           = 30,
    MECHANIC_ENRAGED          = 31,
    MECHANIC_WOUNDED          = 32,
    MECHANIC_INFECTED_2       = 33,
    MECHANIC_INFECTED_3       = 34,
    MECHANIC_INFECTED_4       = 35,
    MECHANIC_TAUNTED          = 36,
    MAX_MECHANIC              = 37  // SKIP
};

// Used for spell 42292 Immune Movement Impairment and Loss of Control (0x49967ca6)
inline constexpr uint64 IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK(\
    (1 << MECHANIC_CHARM) | (1 << MECHANIC_DISORIENTED) | (1 << MECHANIC_FEAR) | \
    (1 << MECHANIC_ROOT) | (1 << MECHANIC_SLEEP) | (1 << MECHANIC_SNARE) | \
    (1 << MECHANIC_STUN) | (1 << MECHANIC_FREEZE) | (1 << MECHANIC_SILENCE) | (1 << MECHANIC_DISARM) | (1 << MECHANIC_KNOCKOUT) | \
    (1 << MECHANIC_POLYMORPH) | (1 << MECHANIC_BANISH) | (1 << MECHANIC_SHACKLE) | \
    (1 << MECHANIC_TURN) | (1 << MECHANIC_HORROR) | (1 << MECHANIC_DAZE) | \
    (1 << MECHANIC_SAPPED));

// Spell dispel type
enum DispelType
{
    DISPEL_NONE         = 0,
    DISPEL_MAGIC        = 1,
    DISPEL_CURSE        = 2,
    DISPEL_DISEASE      = 3,
    DISPEL_POISON       = 4,
    DISPEL_STEALTH      = 5,
    DISPEL_INVISIBILITY = 6,
    DISPEL_ALL          = 7,
    DISPEL_SPE_NPC_ONLY = 8,
    DISPEL_ENRAGE       = 9,
    DISPEL_ZG_TICKET    = 10,
    DESPEL_OLD_UNUSED   = 11,

    DISPEL_MAX
};

#define DISPEL_ALL_MASK ((1<<DISPEL_MAGIC) | (1<<DISPEL_CURSE) | (1<<DISPEL_DISEASE) | (1<<DISPEL_POISON))

//To all Immune system, if target has immunes,
//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
//some aura(related to Mechanics or ImmuneToState<aura>) can't apply to it.
enum SpellImmunity
{
    IMMUNITY_EFFECT                = 0,                     // enum SpellEffects
    IMMUNITY_STATE                 = 1,                     // enum AuraType
    IMMUNITY_SCHOOL                = 2,                     // enum SpellSchoolMask
    IMMUNITY_DAMAGE                = 3,                     // enum SpellSchoolMask
    IMMUNITY_DISPEL                = 4,                     // enum DispelType
    IMMUNITY_MECHANIC              = 5,                     // enum Mechanics
    IMMUNITY_ID                    = 6,
    IMMUNITY_OTHER                 = 7,                     // enum SpellOtherImmunity

    MAX_SPELL_IMMUNITY
};

// target enum name consist of:
// TARGET_[OBJECT_TYPE]_[REFERENCE_TYPE(skipped for caster)]_[SELECTION_TYPE(skipped for default)]_[additional specifiers(friendly, BACK_LEFT, etc.]
enum Targets
{
    TARGET_UNIT_CASTER                          = 1,
    TARGET_UNIT_NEARBY_ENEMY                    = 2,
    TARGET_UNIT_NEARBY_ALLY                     = 3,
    TARGET_UNIT_NEARBY_PARTY                    = 4,
    TARGET_UNIT_PET                             = 5,
    TARGET_UNIT_TARGET_ENEMY                    = 6,
    TARGET_UNIT_SRC_AREA_ENTRY                  = 7,
    TARGET_UNIT_DEST_AREA_ENTRY                 = 8,
    TARGET_DEST_HOME                            = 9,
    TARGET_UNIT_SRC_AREA_UNK_11                 = 11,
    TARGET_UNIT_SRC_AREA_ENEMY                  = 15,
    TARGET_UNIT_DEST_AREA_ENEMY                 = 16,
    TARGET_DEST_DB                              = 17,
    TARGET_DEST_CASTER                          = 18,
    TARGET_UNIT_CASTER_AREA_PARTY               = 20,
    TARGET_UNIT_TARGET_ALLY                     = 21,
    TARGET_SRC_CASTER                           = 22,
    TARGET_GAMEOBJECT_TARGET                    = 23,
    TARGET_UNIT_CONE_ENEMY_24                   = 24,
    TARGET_UNIT_TARGET_ANY                      = 25,
    TARGET_GAMEOBJECT_ITEM_TARGET               = 26,
    TARGET_UNIT_MASTER                          = 27,
    TARGET_DEST_DYNOBJ_ENEMY                    = 28,
    TARGET_DEST_DYNOBJ_ALLY                     = 29,
    TARGET_UNIT_SRC_AREA_ALLY                   = 30,
    TARGET_UNIT_DEST_AREA_ALLY                  = 31,
    TARGET_DEST_CASTER_SUMMON                   = 32, // front left, doesn't use radius
    TARGET_UNIT_SRC_AREA_PARTY                  = 33,
    TARGET_UNIT_DEST_AREA_PARTY                 = 34,
    TARGET_UNIT_TARGET_PARTY                    = 35,
    TARGET_DEST_CASTER_UNK_36                   = 36,
    TARGET_UNIT_LASTTARGET_AREA_PARTY           = 37,
    TARGET_UNIT_NEARBY_ENTRY                    = 38,
    TARGET_DEST_CASTER_FISHING                  = 39,
    TARGET_GAMEOBJECT_NEARBY_ENTRY              = 40,
    TARGET_DEST_CASTER_FRONT_RIGHT              = 41,
    TARGET_DEST_CASTER_BACK_RIGHT               = 42,
    TARGET_DEST_CASTER_BACK_LEFT                = 43,
    TARGET_DEST_CASTER_FRONT_LEFT               = 44,
    TARGET_UNIT_TARGET_CHAINHEAL_ALLY           = 45,
    TARGET_DEST_NEARBY_ENTRY                    = 46,
    TARGET_DEST_CASTER_FRONT                    = 47,
    TARGET_DEST_CASTER_BACK                     = 48,
    TARGET_DEST_CASTER_RIGHT                    = 49,
    TARGET_DEST_CASTER_LEFT                     = 50,
    TARGET_GAMEOBJECT_SRC_AREA                  = 51,
    TARGET_GAMEOBJECT_DEST_AREA                 = 52,
    TARGET_DEST_TARGET_ENEMY                    = 53,
    TARGET_UNIT_CONE_180_DEG_ENEMY              = 54, // Defaults to 180 if ConeDegrees is not set
    TARGET_DEST_CASTER_FRONT_LEAP               = 55, // for a leap spell
    TARGET_UNIT_CASTER_AREA_RAID                = 56,
    TARGET_UNIT_TARGET_RAID                     = 57,
    TARGET_UNIT_NEARBY_RAID                     = 58,
    TARGET_UNIT_CONE_ALLY                       = 59,
    TARGET_UNIT_CONE_ENTRY                      = 60,
    TARGET_UNIT_TARGET_AREA_RAID_CLASS          = 61,
    TARGET_DEST_CASTER_GROUND                   = 62,
    TARGET_DEST_TARGET_ANY                      = 63,
    TARGET_DEST_TARGET_FRONT                    = 64,
    TARGET_DEST_TARGET_BACK                     = 65,
    TARGET_DEST_TARGET_RIGHT                    = 66,
    TARGET_DEST_TARGET_LEFT                     = 67,
    TARGET_DEST_TARGET_FRONT_RIGHT              = 68,
    TARGET_DEST_TARGET_BACK_RIGHT               = 69,
    TARGET_DEST_TARGET_BACK_LEFT                = 70,
    TARGET_DEST_TARGET_FRONT_LEFT               = 71,
    TARGET_DEST_CASTER_RANDOM                   = 72,
    TARGET_DEST_CASTER_RADIUS                   = 73,
    TARGET_DEST_TARGET_RANDOM                   = 74,
    TARGET_DEST_TARGET_RADIUS                   = 75,
    TARGET_DEST_CHANNEL_TARGET                  = 76,
    TARGET_UNIT_CHANNEL_TARGET                  = 77,
    TARGET_DEST_DEST_FRONT                      = 78,
    TARGET_DEST_DEST_BACK                       = 79,
    TARGET_DEST_DEST_RIGHT                      = 80,
    TARGET_DEST_DEST_LEFT                       = 81,
    TARGET_DEST_DEST_FRONT_RIGHT                = 82,
    TARGET_DEST_DEST_BACK_RIGHT                 = 83,
    TARGET_DEST_DEST_BACK_LEFT                  = 84,
    TARGET_DEST_DEST_FRONT_LEFT                 = 85,
    TARGET_DEST_DEST_RANDOM                     = 86,
    TARGET_DEST_DEST                            = 87,
    TARGET_DEST_DYNOBJ_NONE                     = 88,
    TARGET_DEST_TRAJ                            = 89,
    TARGET_UNIT_TARGET_MINIPET                  = 90,
    TARGET_DEST_DEST_RADIUS                     = 91,
    TARGET_UNIT_SUMMONER                        = 92,
    TARGET_CORPSE_SRC_AREA_ENEMY                = 93, // NYI
    TARGET_UNIT_VEHICLE                         = 94,
    TARGET_UNIT_TARGET_PASSENGER                = 95,
    TARGET_UNIT_PASSENGER_0                     = 96,
    TARGET_UNIT_PASSENGER_1                     = 97,
    TARGET_UNIT_PASSENGER_2                     = 98,
    TARGET_UNIT_PASSENGER_3                     = 99,
    TARGET_UNIT_PASSENGER_4                     = 100,
    TARGET_UNIT_PASSENGER_5                     = 101,
    TARGET_UNIT_PASSENGER_6                     = 102,
    TARGET_UNIT_PASSENGER_7                     = 103,
    TARGET_UNIT_CONE_CASTER_TO_DEST_ENEMY       = 104,
    TARGET_UNIT_CASTER_AND_PASSENGERS           = 105,
    TARGET_DEST_CHANNEL_CASTER                  = 106,
    TARGET_DEST_NEARBY_ENTRY_2                  = 107,
    TARGET_GAMEOBJECT_CONE_CASTER_TO_DEST_ENEMY = 108,
    TARGET_GAMEOBJECT_CONE_CASTER_TO_DEST_ALLY  = 109,
    TARGET_UNIT_CONE_CASTER_TO_DEST_ENTRY       = 110,
    TARGET_UNK_111                              = 111, // NYI
    TARGET_UNK_112                              = 112, // NYI
    TARGET_UNK_113                              = 113, // NYI
    TARGET_UNK_114                              = 114, // NYI
    TARGET_UNIT_SRC_AREA_FURTHEST_ENEMY         = 115,
    TARGET_UNIT_AND_DEST_LAST_ENEMY             = 116,
    TARGET_UNK_117                              = 117,
    TARGET_UNIT_TARGET_ALLY_OR_RAID             = 118, // If target is in your party or raid, all party and raid members will be affected
    TARGET_CORPSE_SRC_AREA_RAID                 = 119,
    TARGET_UNIT_CASTER_AND_SUMMONS              = 120,
    TARGET_CORPSE_TARGET_ALLY                   = 121,
    TARGET_UNIT_AREA_THREAT_LIST                = 122, // any unit on threat list
    TARGET_UNIT_AREA_TAP_LIST                   = 123,
    TARGET_UNIT_TARGET_TAP_LIST                 = 124,
    TARGET_DEST_CASTER_GROUND_2                 = 125,
    TARGET_UNIT_CASTER_AREA_ENEMY_CLUMP         = 126, // NYI
    TARGET_DEST_CASTER_ENEMY_CLUMP_CENTROID     = 127, // NYI
    TARGET_UNIT_RECT_CASTER_ALLY                = 128,
    TARGET_UNIT_RECT_CASTER_ENEMY               = 129,
    TARGET_UNIT_RECT_CASTER                     = 130,
    TARGET_DEST_SUMMONER                        = 131,
    TARGET_DEST_TARGET_ALLY                     = 132,
    TARGET_UNIT_LINE_CASTER_TO_DEST_ALLY        = 133,
    TARGET_UNIT_LINE_CASTER_TO_DEST_ENEMY       = 134,
    TARGET_UNIT_LINE_CASTER_TO_DEST             = 135,
    TARGET_UNIT_CONE_CASTER_TO_DEST_ALLY        = 136,
    TARGET_DEST_CASTER_MOVEMENT_DIRECTION       = 137,
    TARGET_DEST_DEST_GROUND                     = 138,
    TARGET_UNK_139                              = 139,
    TARGET_DEST_CASTER_CLUMP_CENTROID           = 140, // NYI
    TARGET_UNK_141                              = 141,
    TARGET_DEST_NEARBY_ENTRY_OR_DB              = 142,
    TARGET_UNK_143                              = 143,
    TARGET_UNK_144                              = 144,
    TARGET_UNK_145                              = 145,
    TARGET_UNK_146                              = 146,
    TARGET_UNK_147                              = 147,
    TARGET_DEST_DEST_TARGET_TOWARDS_CASTER      = 148,
    TARGET_UNK_149                              = 149,
    TARGET_UNIT_OWN_CRITTER                     = 150, // own battle pet from UNIT_FIELD_CRITTER
    TARGET_UNK_151                              = 151,
    TARGET_UNK_152                              = 152,
    TOTAL_SPELL_TARGETS
};

enum SpellMissInfo : uint8
{
    SPELL_MISS_NONE                    = 0,
    SPELL_MISS_MISS                    = 1,
    SPELL_MISS_RESIST                  = 2,
    SPELL_MISS_DODGE                   = 3,
    SPELL_MISS_PARRY                   = 4,
    SPELL_MISS_BLOCK                   = 5,
    SPELL_MISS_EVADE                   = 6,
    SPELL_MISS_IMMUNE                  = 7,
    SPELL_MISS_IMMUNE2                 = 8, // one of these 2 is MISS_TEMPIMMUNE
    SPELL_MISS_DEFLECT                 = 9,
    SPELL_MISS_ABSORB                  = 10,
    SPELL_MISS_REFLECT                 = 11
};

enum SpellHitType
{
    SPELL_HIT_TYPE_CRIT_DEBUG           = 0x01,
    SPELL_HIT_TYPE_CRIT                 = 0x02,
    SPELL_HIT_TYPE_HIT_DEBUG            = 0x04,
    SPELL_HIT_TYPE_SPLIT                = 0x08,
    SPELL_HIT_TYPE_VICTIM_IS_ATTACKER   = 0x10,
    SPELL_HIT_TYPE_ATTACK_TABLE_DEBUG   = 0x20,
    SPELL_HIT_TYPE_UNK                  = 0x40,
    SPELL_HIT_TYPE_NO_ATTACKER          = 0x80, // does the same as SPELL_ATTR4_COMBAT_LOG_NO_CASTER
};

// EnumUtils: DESCRIBE THIS
enum SpellDmgClass
{
    SPELL_DAMAGE_CLASS_NONE     = 0, // TITLE None
    SPELL_DAMAGE_CLASS_MAGIC    = 1, // TITLE Magic
    SPELL_DAMAGE_CLASS_MELEE    = 2, // TITLE Melee
    SPELL_DAMAGE_CLASS_RANGED   = 3  // TITLE Ranged
};

// EnumUtils: DESCRIBE THIS
enum SpellPreventionType
{
    SPELL_PREVENTION_TYPE_NONE          = 0, // TITLE None
    SPELL_PREVENTION_TYPE_SILENCE       = 1, // TITLE Silence
    SPELL_PREVENTION_TYPE_PACIFY        = 2, // TITLE Pacify
    SPELL_PREVENTION_TYPE_NO_ACTIONS    = 4  // TITLE No actions
};

enum GameobjectTypes : uint8
{
    GAMEOBJECT_TYPE_DOOR                        = 0,
    GAMEOBJECT_TYPE_BUTTON                      = 1,
    GAMEOBJECT_TYPE_QUESTGIVER                  = 2,
    GAMEOBJECT_TYPE_CHEST                       = 3,
    GAMEOBJECT_TYPE_BINDER                      = 4,
    GAMEOBJECT_TYPE_GENERIC                     = 5,
    GAMEOBJECT_TYPE_TRAP                        = 6,
    GAMEOBJECT_TYPE_CHAIR                       = 7,
    GAMEOBJECT_TYPE_SPELL_FOCUS                 = 8,
    GAMEOBJECT_TYPE_TEXT                        = 9,
    GAMEOBJECT_TYPE_GOOBER                      = 10,
    GAMEOBJECT_TYPE_TRANSPORT                   = 11,
    GAMEOBJECT_TYPE_AREADAMAGE                  = 12,
    GAMEOBJECT_TYPE_CAMERA                      = 13,
    GAMEOBJECT_TYPE_MAP_OBJECT                  = 14,
    GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT           = 15,
    GAMEOBJECT_TYPE_DUEL_ARBITER                = 16,
    GAMEOBJECT_TYPE_FISHINGNODE                 = 17,
    GAMEOBJECT_TYPE_RITUAL                      = 18,
    GAMEOBJECT_TYPE_MAILBOX                     = 19,
    GAMEOBJECT_TYPE_DO_NOT_USE                  = 20,
    GAMEOBJECT_TYPE_GUARDPOST                   = 21,
    GAMEOBJECT_TYPE_SPELLCASTER                 = 22,
    GAMEOBJECT_TYPE_MEETINGSTONE                = 23,
    GAMEOBJECT_TYPE_FLAGSTAND                   = 24,
    GAMEOBJECT_TYPE_FISHINGHOLE                 = 25,
    GAMEOBJECT_TYPE_FLAGDROP                    = 26,
    GAMEOBJECT_TYPE_MINI_GAME                   = 27,
    GAMEOBJECT_TYPE_DO_NOT_USE_2                = 28,
    GAMEOBJECT_TYPE_CONTROL_ZONE                = 29,
    GAMEOBJECT_TYPE_AURA_GENERATOR              = 30,
    GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY          = 31,
    GAMEOBJECT_TYPE_BARBER_CHAIR                = 32,
    GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING       = 33,
    GAMEOBJECT_TYPE_GUILD_BANK                  = 34,
    GAMEOBJECT_TYPE_TRAPDOOR                    = 35,
    GAMEOBJECT_TYPE_NEW_FLAG                    = 36,
    GAMEOBJECT_TYPE_NEW_FLAG_DROP               = 37,
    GAMEOBJECT_TYPE_GARRISON_BUILDING           = 38,
    GAMEOBJECT_TYPE_GARRISON_PLOT               = 39,
    GAMEOBJECT_TYPE_CLIENT_CREATURE             = 40,
    GAMEOBJECT_TYPE_CLIENT_ITEM                 = 41,
    GAMEOBJECT_TYPE_CAPTURE_POINT               = 42,
    GAMEOBJECT_TYPE_PHASEABLE_MO                = 43,
    GAMEOBJECT_TYPE_GARRISON_MONUMENT           = 44,
    GAMEOBJECT_TYPE_GARRISON_SHIPMENT           = 45,
    GAMEOBJECT_TYPE_GARRISON_MONUMENT_PLAQUE    = 46,
    GAMEOBJECT_TYPE_ITEM_FORGE                  = 47,
    GAMEOBJECT_TYPE_UI_LINK                     = 48,
    GAMEOBJECT_TYPE_KEYSTONE_RECEPTACLE         = 49,
    GAMEOBJECT_TYPE_GATHERING_NODE              = 50,
    GAMEOBJECT_TYPE_CHALLENGE_MODE_REWARD       = 51,
    GAMEOBJECT_TYPE_MULTI                       = 52,
    GAMEOBJECT_TYPE_SIEGEABLE_MULTI             = 53,
    GAMEOBJECT_TYPE_SIEGEABLE_MO                = 54,
    GAMEOBJECT_TYPE_PVP_REWARD                  = 55,
    GAMEOBJECT_TYPE_PLAYER_CHOICE_CHEST         = 56,
    GAMEOBJECT_TYPE_LEGENDARY_FORGE             = 57,
    GAMEOBJECT_TYPE_GARR_TALENT_TREE            = 58,
    GAMEOBJECT_TYPE_WEEKLY_REWARD_CHEST         = 59,
    GAMEOBJECT_TYPE_CLIENT_MODEL                = 60,
    GAMEOBJECT_TYPE_CRAFTING_TABLE              = 61,
    GAMEOBJECT_TYPE_PERKS_PROGRAM_CHEST         = 62,
};

#define MAX_GAMEOBJECT_TYPE                  63             // sending to client this or greater value can crash client.
#define MAX_GAMEOBJECT_DATA                  35             // Max number of uint32 vars in gameobject_template data field

enum GameObjectFlags
{
    GO_FLAG_IN_USE                                  = 0x00000001, // disables interaction while animated
    GO_FLAG_LOCKED                                  = 0x00000002, // require key, spell, event, etc to be opened. Makes "Locked" appear in tooltip
    GO_FLAG_INTERACT_COND                           = 0x00000004, // cannot interact (condition to interact - requires GO_DYNFLAG_LO_ACTIVATE to enable interaction clientside)
    GO_FLAG_TRANSPORT                               = 0x00000008, // any kind of transport? Object can transport (elevator, boat, car)
    GO_FLAG_NOT_SELECTABLE                          = 0x00000010, // not selectable even in GM mode
    GO_FLAG_NODESPAWN                               = 0x00000020, // never despawn, typically for doors, they just change state
    GO_FLAG_AI_OBSTACLE                             = 0x00000040, // makes the client register the object in something called AIObstacleMgr, unknown what it does
    GO_FLAG_FREEZE_ANIMATION                        = 0x00000080,

    // for object types GAMEOBJECT_TYPE_GARRISON_BUILDING, GAMEOBJECT_TYPE_GARRISON_PLOT and GAMEOBJECT_TYPE_PHASEABLE_MO flag bits 8 to 12 are used as WMOAreaTable::NameSetID
    GO_FLAG_DAMAGED                                 = 0x00000200,
    GO_FLAG_DESTROYED                               = 0x00000400,

    GO_FLAG_IGNORE_CURRENT_STATE_FOR_USE_SPELL      = 0x00004000, // Allows casting use spell without checking current state (opening open gameobjects, unlocking unlocked gameobjects and closing closed gameobjects)
    GO_FLAG_INTERACT_DISTANCE_IGNORES_MODEL         = 0x00008000, // Client completely ignores model bounds for interaction distance check
    GO_FLAG_IGNORE_CURRENT_STATE_FOR_USE_SPELL_EXCEPT_UNLOCKED = 0x00040000, // Allows casting use spell without checking current state except unlocking unlocked gamobjets (opening open gameobjects and closing closed gameobjects)
    GO_FLAG_INTERACT_DISTANCE_USES_TEMPLATE_MODEL   = 0x00080000, // client checks interaction distance from model sent in SMSG_QUERY_GAMEOBJECT_RESPONSE instead of GAMEOBJECT_DISPLAYID
    GO_FLAG_MAP_OBJECT                              = 0x00100000, // pre-7.0 model loading used to be controlled by file extension (wmo vs m2)
    GO_FLAG_IN_MULTI_USE                            = 0x00200000, // GO_FLAG_IN_USE equivalent for objects usable by multiple players
    GO_FLAG_LOW_PRIORITY_SELECTION                  = 0x04000000, // client will give lower cursor priority to this object when multiple objects overlap
};

DEFINE_ENUM_FLAG(GameObjectFlags);

enum GameObjectDynamicLowFlags : uint16
{
    GO_DYNFLAG_LO_HIDE_MODEL        = 0x0002,               // Object model is not shown with this flag
    GO_DYNFLAG_LO_ACTIVATE          = 0x0004,               // enables interaction with GO
    GO_DYNFLAG_LO_ANIMATE           = 0x0008,               // possibly more distinct animation of GO
    GO_DYNFLAG_LO_DEPLETED          = 0x0010,               // can no longer be interacted with (and for gathering nodes it forces "open" visual state)
    GO_DYNFLAG_LO_SPARKLE           = 0x0020,               // makes GO sparkle
    GO_DYNFLAG_LO_STOPPED           = 0x0040,               // Transport is stopped
    GO_DYNFLAG_LO_NO_INTERACT       = 0x0080,
    GO_DYNFLAG_LO_INVERTED_MOVEMENT = 0x0100,               // GAMEOBJECT_TYPE_TRANSPORT only
    GO_DYNFLAG_LO_HIGHLIGHT         = 0x0200,               // Allows object highlight when GO_DYNFLAG_LO_ACTIVATE or GO_DYNFLAG_LO_SPARKLE are set, not only when player is on quest determined by Data fields
};

// client side GO show states
enum GOState : uint8
{
    GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
    GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
    GO_STATE_DESTROYED          = 2,                        // show the object in-game as already used and not yet reset (e.g. door opened by a cannon blast)
    GO_STATE_TRANSPORT_ACTIVE   = 24,
    GO_STATE_TRANSPORT_STOPPED  = 25
};

#define MAX_GO_STATE              3
#define MAX_GO_STATE_TRANSPORT_STOP_FRAMES 9

enum GameObjectDestructibleState
{
    GO_DESTRUCTIBLE_INTACT      = 0,
    GO_DESTRUCTIBLE_DAMAGED     = 1,
    GO_DESTRUCTIBLE_DESTROYED   = 2,
    GO_DESTRUCTIBLE_REBUILDING  = 3
};

// EmotesText.db2 (9.2.0.42423)
enum TextEmotes
{
    TEXT_EMOTE_AGREE                = 1,
    TEXT_EMOTE_AMAZE                = 2,
    TEXT_EMOTE_ANGRY                = 3,
    TEXT_EMOTE_APOLOGIZE            = 4,
    TEXT_EMOTE_APPLAUD              = 5,
    TEXT_EMOTE_BASHFUL              = 6,
    TEXT_EMOTE_BECKON               = 7,
    TEXT_EMOTE_BEG                  = 8,
    TEXT_EMOTE_BITE                 = 9,
    TEXT_EMOTE_BLEED                = 10,
    TEXT_EMOTE_BLINK                = 11,
    TEXT_EMOTE_BLUSH                = 12,
    TEXT_EMOTE_BONK                 = 13,
    TEXT_EMOTE_BORED                = 14,
    TEXT_EMOTE_BOUNCE               = 15,
    TEXT_EMOTE_BRB                  = 16,
    TEXT_EMOTE_BOW                  = 17,
    TEXT_EMOTE_BURP                 = 18,
    TEXT_EMOTE_BYE                  = 19,
    TEXT_EMOTE_CACKLE               = 20,
    TEXT_EMOTE_CHEER                = 21,
    TEXT_EMOTE_CHICKEN              = 22,
    TEXT_EMOTE_CHUCKLE              = 23,
    TEXT_EMOTE_CLAP                 = 24,
    TEXT_EMOTE_CONFUSED             = 25,
    TEXT_EMOTE_CONGRATULATE         = 26,
    TEXT_EMOTE_COUGH                = 27,
    TEXT_EMOTE_COWER                = 28,
    TEXT_EMOTE_CRACK                = 29,
    TEXT_EMOTE_CRINGE               = 30,
    TEXT_EMOTE_CRY                  = 31,
    TEXT_EMOTE_CURIOUS              = 32,
    TEXT_EMOTE_CURTSEY              = 33,
    TEXT_EMOTE_DANCE                = 34,
    TEXT_EMOTE_DRINK                = 35,
    TEXT_EMOTE_DROOL                = 36,
    TEXT_EMOTE_EAT                  = 37,
    TEXT_EMOTE_EYE                  = 38,
    TEXT_EMOTE_FART                 = 39,
    TEXT_EMOTE_FIDGET               = 40,
    TEXT_EMOTE_FLEX                 = 41,
    TEXT_EMOTE_FROWN                = 42,
    TEXT_EMOTE_GASP                 = 43,
    TEXT_EMOTE_GAZE                 = 44,
    TEXT_EMOTE_GIGGLE               = 45,
    TEXT_EMOTE_GLARE                = 46,
    TEXT_EMOTE_GLOAT                = 47,
    TEXT_EMOTE_GREET                = 48,
    TEXT_EMOTE_GRIN                 = 49,
    TEXT_EMOTE_GROAN                = 50,
    TEXT_EMOTE_GROVEL               = 51,
    TEXT_EMOTE_GUFFAW               = 52,
    TEXT_EMOTE_HAIL                 = 53,
    TEXT_EMOTE_HAPPY                = 54,
    TEXT_EMOTE_HELLO                = 55,
    TEXT_EMOTE_HUG                  = 56,
    TEXT_EMOTE_HUNGRY               = 57,
    TEXT_EMOTE_KISS                 = 58,
    TEXT_EMOTE_KNEEL                = 59,
    TEXT_EMOTE_LAUGH                = 60,
    TEXT_EMOTE_LAYDOWN              = 61,
    TEXT_EMOTE_MESSAGE              = 62,
    TEXT_EMOTE_MOAN                 = 63,
    TEXT_EMOTE_MOON                 = 64,
    TEXT_EMOTE_MOURN                = 65,
    TEXT_EMOTE_NO                   = 66,
    TEXT_EMOTE_NOD                  = 67,
    TEXT_EMOTE_NOSEPICK             = 68,
    TEXT_EMOTE_PANIC                = 69,
    TEXT_EMOTE_PEER                 = 70,
    TEXT_EMOTE_PLEAD                = 71,
    TEXT_EMOTE_POINT                = 72,
    TEXT_EMOTE_POKE                 = 73,
    TEXT_EMOTE_PRAY                 = 74,
    TEXT_EMOTE_ROAR                 = 75,
    TEXT_EMOTE_ROFL                 = 76,
    TEXT_EMOTE_RUDE                 = 77,
    TEXT_EMOTE_SALUTE               = 78,
    TEXT_EMOTE_SCRATCH              = 79,
    TEXT_EMOTE_SEXY                 = 80,
    TEXT_EMOTE_SHAKE                = 81,
    TEXT_EMOTE_SHOUT                = 82,
    TEXT_EMOTE_SHRUG                = 83,
    TEXT_EMOTE_SHY                  = 84,
    TEXT_EMOTE_SIGH                 = 85,
    TEXT_EMOTE_SIT                  = 86,
    TEXT_EMOTE_SLEEP                = 87,
    TEXT_EMOTE_SNARL                = 88,
    TEXT_EMOTE_SPIT                 = 89,
    TEXT_EMOTE_STARE                = 90,
    TEXT_EMOTE_SURPRISED            = 91,
    TEXT_EMOTE_SURRENDER            = 92,
    TEXT_EMOTE_TALK                 = 93,
    TEXT_EMOTE_TALKEX               = 94,
    TEXT_EMOTE_TALKQ                = 95,
    TEXT_EMOTE_TAP                  = 96,
    TEXT_EMOTE_THANK                = 97,
    TEXT_EMOTE_THREATEN             = 98,
    TEXT_EMOTE_TIRED                = 99,
    TEXT_EMOTE_VICTORY              = 100,
    TEXT_EMOTE_WAVE                 = 101,
    TEXT_EMOTE_WELCOME              = 102,
    TEXT_EMOTE_WHINE                = 103,
    TEXT_EMOTE_WHISTLE              = 104,
    TEXT_EMOTE_WORK                 = 105,
    TEXT_EMOTE_YAWN                 = 106,
    TEXT_EMOTE_BOGGLE               = 107,
    TEXT_EMOTE_CALM                 = 108,
    TEXT_EMOTE_COLD                 = 109,
    TEXT_EMOTE_COMFORT              = 110,
    TEXT_EMOTE_CUDDLE               = 111,
    TEXT_EMOTE_DUCK                 = 112,
    TEXT_EMOTE_INSULT               = 113,
    TEXT_EMOTE_INTRODUCE            = 114,
    TEXT_EMOTE_JK                   = 115,
    TEXT_EMOTE_LICK                 = 116,
    TEXT_EMOTE_LISTEN               = 117,
    TEXT_EMOTE_LOST                 = 118,
    TEXT_EMOTE_MOCK                 = 119,
    TEXT_EMOTE_PONDER               = 120,
    TEXT_EMOTE_POUNCE               = 121,
    TEXT_EMOTE_PRAISE               = 122,
    TEXT_EMOTE_PURR                 = 123,
    TEXT_EMOTE_PUZZLE               = 124,
    TEXT_EMOTE_RAISE                = 125,
    TEXT_EMOTE_READY                = 126,
    TEXT_EMOTE_SHIMMY               = 127,
    TEXT_EMOTE_SHIVER               = 128,
    TEXT_EMOTE_SHOO                 = 129,
    TEXT_EMOTE_SLAP                 = 130,
    TEXT_EMOTE_SMIRK                = 131,
    TEXT_EMOTE_SNIFF                = 132,
    TEXT_EMOTE_SNUB                 = 133,
    TEXT_EMOTE_SOOTHE               = 134,
    TEXT_EMOTE_STINK                = 135,
    TEXT_EMOTE_TAUNT                = 136,
    TEXT_EMOTE_TEASE                = 137,
    TEXT_EMOTE_THIRSTY              = 138,
    TEXT_EMOTE_VETO                 = 139,
    TEXT_EMOTE_SNICKER              = 140,
    TEXT_EMOTE_STAND                = 141,
    TEXT_EMOTE_TICKLE               = 142,
    TEXT_EMOTE_VIOLIN               = 143,
    TEXT_EMOTE_SMILE                = 163,
    TEXT_EMOTE_RASP                 = 183,
    TEXT_EMOTE_PITY                 = 203,
    TEXT_EMOTE_GROWL                = 204,
    TEXT_EMOTE_BARK                 = 205,
    TEXT_EMOTE_SCARED               = 223,
    TEXT_EMOTE_FLOP                 = 224,
    TEXT_EMOTE_LOVE                 = 225,
    TEXT_EMOTE_MOO                  = 226,
    TEXT_EMOTE_COMMEND              = 243,
    TEXT_EMOTE_TRAIN                = 264,
    TEXT_EMOTE_HELPME               = 303,
    TEXT_EMOTE_INCOMING             = 304,
    TEXT_EMOTE_CHARGE               = 305,
    TEXT_EMOTE_FLEE                 = 306,
    TEXT_EMOTE_ATTACKMYTARGET       = 307,
    TEXT_EMOTE_OOM                  = 323,
    TEXT_EMOTE_FOLLOW               = 324,
    TEXT_EMOTE_WAIT                 = 325,
    TEXT_EMOTE_HEALME               = 326,
    TEXT_EMOTE_OPENFIRE             = 327,
    TEXT_EMOTE_FLIRT                = 328,
    TEXT_EMOTE_JOKE                 = 329,
    TEXT_EMOTE_GOLFCLAP             = 343,
    TEXT_EMOTE_WINK                 = 363,
    TEXT_EMOTE_PAT                  = 364,
    TEXT_EMOTE_SERIOUS              = 365,
    TEXT_EMOTE_MOUNT_SPECIAL        = 366,
    TEXT_EMOTE_GOODLUCK             = 367,
    TEXT_EMOTE_BLAME                = 368,
    TEXT_EMOTE_BLANK                = 369,
    TEXT_EMOTE_BRANDISH             = 370,
    TEXT_EMOTE_BREATH               = 371,
    TEXT_EMOTE_DISAGREE             = 372,
    TEXT_EMOTE_DOUBT                = 373,
    TEXT_EMOTE_EMBARRASS            = 374,
    TEXT_EMOTE_ENCOURAGE            = 375,
    TEXT_EMOTE_ENEMY                = 376,
    TEXT_EMOTE_EYEBROW              = 377,
    TEXT_EMOTE_TOAST                = 378,
    TEXT_EMOTE_FAIL                 = 379,
    TEXT_EMOTE_HIGHFIVE             = 380,
    TEXT_EMOTE_ABSENT               = 381,
    TEXT_EMOTE_ARM                  = 382,
    TEXT_EMOTE_AWE                  = 383,
    TEXT_EMOTE_BACKPACK             = 384,
    TEXT_EMOTE_BADFEELING           = 385,
    TEXT_EMOTE_CHALLENGE            = 386,
    TEXT_EMOTE_CHUG                 = 387,
    TEXT_EMOTE_DING                 = 389,
    TEXT_EMOTE_FACEPALM             = 390,
    TEXT_EMOTE_FAINT                = 391,
    TEXT_EMOTE_GO                   = 392,
    TEXT_EMOTE_GOING                = 393,
    TEXT_EMOTE_GLOWER               = 394,
    TEXT_EMOTE_HEADACHE             = 395,
    TEXT_EMOTE_HICCUP               = 396,
    TEXT_EMOTE_HISS                 = 398,
    TEXT_EMOTE_HOLDHAND             = 399,
    TEXT_EMOTE_HURRY                = 401,
    TEXT_EMOTE_IDEA                 = 402,
    TEXT_EMOTE_JEALOUS              = 403,
    TEXT_EMOTE_LUCK                 = 404,
    TEXT_EMOTE_MAP                  = 405,
    TEXT_EMOTE_MERCY                = 406,
    TEXT_EMOTE_MUTTER               = 407,
    TEXT_EMOTE_NERVOUS              = 408,
    TEXT_EMOTE_OFFER                = 409,
    TEXT_EMOTE_PET                  = 410,
    TEXT_EMOTE_PINCH                = 411,
    TEXT_EMOTE_PROUD                = 413,
    TEXT_EMOTE_PROMISE              = 414,
    TEXT_EMOTE_PULSE                = 415,
    TEXT_EMOTE_PUNCH                = 416,
    TEXT_EMOTE_POUT                 = 417,
    TEXT_EMOTE_REGRET               = 418,
    TEXT_EMOTE_REVENGE              = 420,
    TEXT_EMOTE_ROLLEYES             = 421,
    TEXT_EMOTE_RUFFLE               = 422,
    TEXT_EMOTE_SAD                  = 423,
    TEXT_EMOTE_SCOFF                = 424,
    TEXT_EMOTE_SCOLD                = 425,
    TEXT_EMOTE_SCOWL                = 426,
    TEXT_EMOTE_SEARCH               = 427,
    TEXT_EMOTE_SHAKEFIST            = 428,
    TEXT_EMOTE_SHIFTY               = 429,
    TEXT_EMOTE_SHUDDER              = 430,
    TEXT_EMOTE_SIGNAL               = 431,
    TEXT_EMOTE_SILENCE              = 432,
    TEXT_EMOTE_SING                 = 433,
    TEXT_EMOTE_SMACK                = 434,
    TEXT_EMOTE_SNEAK                = 435,
    TEXT_EMOTE_SNEEZE               = 436,
    TEXT_EMOTE_SNORT                = 437,
    TEXT_EMOTE_SQUEAL               = 438,
    TEXT_EMOTE_STOPATTACK           = 439,
    TEXT_EMOTE_SUSPICIOUS           = 440,
    TEXT_EMOTE_THINK                = 441,
    TEXT_EMOTE_TRUCE                = 442,
    TEXT_EMOTE_TWIDDLE              = 443,
    TEXT_EMOTE_WARN                 = 444,
    TEXT_EMOTE_SNAP                 = 445,
    TEXT_EMOTE_CHARM                = 446,
    TEXT_EMOTE_COVEREARS            = 447,
    TEXT_EMOTE_CROSSARMS            = 448,
    TEXT_EMOTE_LOOK                 = 449,
    TEXT_EMOTE_OBJECT               = 450,
    TEXT_EMOTE_SWEAT                = 451,
    TEXT_EMOTE_YW                   = 453,
    TEXT_EMOTE_READ                 = 456,
    TEXT_EMOTE_BOOT                 = 506,
    TEXT_EMOTE_FORTHEALLIANCE       = 507,
    TEXT_EMOTE_FORTTHEHORDE         = 508,
    TEXT_EMOTE_WHOA                 = 517,
    TEXT_EMOTE_OOPS                 = 518,
    TEXT_EMOTE_ALLIANCE             = 519,
    TEXT_EMOTE_HORDE                = 520,
    TEXT_EMOTE_MEOW                 = 521,
    TEXT_EMOTE_BOOP                 = 522,
    TEXT_EMOTE_WINCE                = 623,
    TEXT_EMOTE_HUZZAH               = 624,
    TEXT_EMOTE_IMPRESSED            = 625,
    TEXT_EMOTE_MAGNIFICENT          = 626,
};

// Emotes.db2 (10.1.5.50232)
// EnumUtils: DESCRIBE THIS
enum Emote : uint32
{
    EMOTE_ONESHOT_NONE                           = 0, // SKIP
    EMOTE_ONESHOT_TALK                           = 1,
    EMOTE_ONESHOT_BOW                            = 2,
    EMOTE_ONESHOT_WAVE                           = 3,
    EMOTE_ONESHOT_CHEER                          = 4,
    EMOTE_ONESHOT_EXCLAMATION                    = 5,
    EMOTE_ONESHOT_QUESTION                       = 6,
    EMOTE_ONESHOT_EAT                            = 7,
    EMOTE_STATE_DANCE                            = 10,
    EMOTE_ONESHOT_LAUGH                          = 11,
    EMOTE_STATE_SLEEP                            = 12,
    EMOTE_STATE_SIT                              = 13,
    EMOTE_ONESHOT_RUDE                           = 14,
    EMOTE_ONESHOT_ROAR                           = 15,
    EMOTE_ONESHOT_KNEEL                          = 16,
    EMOTE_ONESHOT_KISS                           = 17,
    EMOTE_ONESHOT_CRY                            = 18,
    EMOTE_ONESHOT_CHICKEN                        = 19,
    EMOTE_ONESHOT_BEG                            = 20,
    EMOTE_ONESHOT_APPLAUD                        = 21,
    EMOTE_ONESHOT_SHOUT                          = 22,
    EMOTE_ONESHOT_FLEX                           = 23,
    EMOTE_ONESHOT_SHY                            = 24,
    EMOTE_ONESHOT_POINT                          = 25,
    EMOTE_STATE_STAND                            = 26,
    EMOTE_STATE_READY_UNARMED                    = 27,
    EMOTE_STATE_WORK_SHEATHED                    = 28,
    EMOTE_STATE_POINT                            = 29,
    EMOTE_STATE_NONE                             = 30,
    EMOTE_ONESHOT_WOUND                          = 33,
    EMOTE_ONESHOT_WOUND_CRITICAL                 = 34,
    EMOTE_ONESHOT_ATTACK_UNARMED                 = 35,
    EMOTE_ONESHOT_ATTACK1H                       = 36,
    EMOTE_ONESHOT_ATTACK2HTIGHT                  = 37,
    EMOTE_ONESHOT_ATTACK2H_LOOSE                 = 38,
    EMOTE_ONESHOT_PARRY_UNARMED                  = 39,
    EMOTE_ONESHOT_PARRY_SHIELD                   = 43,
    EMOTE_ONESHOT_READY_UNARMED                  = 44,
    EMOTE_ONESHOT_READY1H                        = 45,
    EMOTE_ONESHOT_READY_BOW                      = 48,
    EMOTE_ONESHOT_SPELL_PRECAST                  = 50,
    EMOTE_ONESHOT_SPELL_CAST                     = 51,
    EMOTE_ONESHOT_BATTLE_ROAR                    = 53,
    EMOTE_ONESHOT_SPECIALATTACK1H                = 54,
    EMOTE_ONESHOT_KICK                           = 60,
    EMOTE_ONESHOT_ATTACK_THROWN                  = 61,
    EMOTE_STATE_STUN                             = 64,
    EMOTE_STATE_DEAD                             = 65,
    EMOTE_ONESHOT_SALUTE                         = 66,
    EMOTE_STATE_KNEEL                            = 68,
    EMOTE_STATE_USE_STANDING                     = 69,
    EMOTE_ONESHOT_WAVE_NO_SHEATHE                = 70,
    EMOTE_ONESHOT_CHEER_NO_SHEATHE               = 71,
    EMOTE_ONESHOT_EAT_NO_SHEATHE                 = 92,
    EMOTE_STATE_STUN_NO_SHEATHE                  = 93,
    EMOTE_ONESHOT_DANCE                          = 94,
    EMOTE_ONESHOT_SALUTE_NO_SHEATH               = 113,
    EMOTE_STATE_USE_STANDING_NO_SHEATHE          = 133,
    EMOTE_ONESHOT_LAUGH_NO_SHEATHE               = 153,
    EMOTE_STATE_WORK                             = 173,
    EMOTE_STATE_SPELL_PRECAST                    = 193,
    EMOTE_ONESHOT_READY_RIFLE                    = 213,
    EMOTE_STATE_READY_RIFLE                      = 214,
    EMOTE_STATE_WORK_MINING                      = 233,
    EMOTE_STATE_WORK_CHOPWOOD                    = 234,
    EMOTE_STATE_APPLAUD                          = 253,
    EMOTE_ONESHOT_LIFTOFF                        = 254,
    EMOTE_ONESHOT_YES                            = 273,
    EMOTE_ONESHOT_NO                             = 274,
    EMOTE_ONESHOT_TRAIN                          = 275,
    EMOTE_ONESHOT_LAND                           = 293,
    EMOTE_STATE_AT_EASE                          = 313,
    EMOTE_STATE_READY1H                          = 333,
    EMOTE_STATE_SPELL_KNEEL_START                = 353,
    EMOTE_STATE_SUBMERGED                        = 373,
    EMOTE_ONESHOT_SUBMERGE                       = 374,
    EMOTE_STATE_READY2H                          = 375,
    EMOTE_STATE_READY_BOW                        = 376,
    EMOTE_ONESHOT_MOUNT_SPECIAL                  = 377,
    EMOTE_STATE_TALK                             = 378,
    EMOTE_STATE_FISHING                          = 379,
    EMOTE_ONESHOT_FISHING                        = 380,
    EMOTE_ONESHOT_LOOT                           = 381,
    EMOTE_STATE_WHIRLWIND                        = 382,
    EMOTE_STATE_DROWNED                          = 383,
    EMOTE_STATE_HOLD_BOW                         = 384,
    EMOTE_STATE_HOLD_RIFLE                       = 385,
    EMOTE_STATE_HOLD_THROWN                      = 386,
    EMOTE_ONESHOT_DROWN                          = 387,
    EMOTE_ONESHOT_STOMP                          = 388,
    EMOTE_ONESHOT_ATTACK_OFF                     = 389,
    EMOTE_ONESHOT_ATTACK_OFF_PIERCE              = 390,
    EMOTE_STATE_ROAR                             = 391,
    EMOTE_STATE_LAUGH                            = 392,
    EMOTE_ONESHOT_CREATURE_SPECIAL               = 393,
    EMOTE_ONESHOT_JUMPLANDRUN                    = 394,
    EMOTE_ONESHOT_JUMPEND                        = 395,
    EMOTE_ONESHOT_TALK_NO_SHEATHE                = 396,
    EMOTE_ONESHOT_POINT_NO_SHEATHE               = 397,
    EMOTE_STATE_CANNIBALIZE                      = 398,
    EMOTE_ONESHOT_JUMPSTART                      = 399,
    EMOTE_STATE_DANCESPECIAL                     = 400,
    EMOTE_ONESHOT_DANCESPECIAL                   = 401,
    EMOTE_ONESHOT_CUSTOM_SPELL_01                = 402,
    EMOTE_ONESHOT_CUSTOM_SPELL_02                = 403,
    EMOTE_ONESHOT_CUSTOM_SPELL_03                = 404,
    EMOTE_ONESHOT_CUSTOM_SPELL_04                = 405,
    EMOTE_ONESHOT_CUSTOM_SPELL_05                = 406,
    EMOTE_ONESHOT_CUSTOM_SPELL_06                = 407,
    EMOTE_ONESHOT_CUSTOM_SPELL_07                = 408,
    EMOTE_ONESHOT_CUSTOM_SPELL_08                = 409,
    EMOTE_ONESHOT_CUSTOM_SPELL_09                = 410,
    EMOTE_ONESHOT_CUSTOM_SPELL_10                = 411,
    EMOTE_STATE_EXCLAIM                          = 412,
    EMOTE_STATE_DANCE_CUSTOM                     = 413,
    EMOTE_STATE_SIT_CHAIR_MED                    = 415,
    EMOTE_STATE_CUSTOM_SPELL_01                  = 416,
    EMOTE_STATE_CUSTOM_SPELL_02                  = 417,
    EMOTE_STATE_EAT                              = 418,
    EMOTE_STATE_CUSTOM_SPELL_04                  = 419,
    EMOTE_STATE_CUSTOM_SPELL_03                  = 420,
    EMOTE_STATE_CUSTOM_SPELL_05                  = 421,
    EMOTE_STATE_SPELLEFFECT_HOLD                 = 422,
    EMOTE_STATE_EAT_NO_SHEATHE                   = 423,
    EMOTE_STATE_MOUNT                            = 424,
    EMOTE_STATE_READY2HL                         = 425,
    EMOTE_STATE_SIT_CHAIR_HIGH                   = 426,
    EMOTE_STATE_FALL                             = 427,
    EMOTE_STATE_LOOT                             = 428,
    EMOTE_STATE_SUBMERGED_NEW                    = 429,
    EMOTE_ONESHOT_COWER                          = 430,
    EMOTE_STATE_COWER                            = 431,
    EMOTE_ONESHOT_USE_STANDING                   = 432,
    EMOTE_STATE_STEALTH_STAND                    = 433,
    EMOTE_ONESHOT_OMNICAST_GHOUL                 = 434,
    EMOTE_ONESHOT_ATTACK_BOW                     = 435,
    EMOTE_ONESHOT_ATTACK_RIFLE                   = 436,
    EMOTE_STATE_SWIM_IDLE                        = 437,
    EMOTE_STATE_ATTACK_UNARMED                   = 438,
    EMOTE_ONESHOT_SPELL_CAST_W_SOUND             = 439,
    EMOTE_ONESHOT_DODGE                          = 440,
    EMOTE_ONESHOT_PARRY1H                        = 441,
    EMOTE_ONESHOT_PARRY2H                        = 442,
    EMOTE_ONESHOT_PARRY2HL                       = 443,
    EMOTE_STATE_FLYFALL                          = 444,
    EMOTE_ONESHOT_FLYDEATH                       = 445,
    EMOTE_STATE_FLY_FALL                         = 446,
    EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN            = 447,
    EMOTE_ONESHOT_FLY_SIT_GROUND_UP              = 448,
    EMOTE_ONESHOT_EMERGE                         = 449,
    EMOTE_ONESHOT_DRAGON_SPIT                    = 450,
    EMOTE_STATE_SPECIAL_UNARMED                  = 451,
    EMOTE_ONESHOT_FLYGRAB                        = 452,
    EMOTE_STATE_FLYGRABCLOSED                    = 453,
    EMOTE_ONESHOT_FLYGRABTHROWN                  = 454,
    EMOTE_STATE_FLY_SIT_GROUND                   = 455,
    EMOTE_STATE_WALK_BACKWARDS                   = 456,
    EMOTE_ONESHOT_FLYTALK                        = 457,
    EMOTE_ONESHOT_FLYATTACK1H                    = 458,
    EMOTE_STATE_CUSTOM_SPELL_08                  = 459,
    EMOTE_ONESHOT_FLY_DRAGON_SPIT                = 460,
    EMOTE_STATE_SIT_CHAIR_LOW                    = 461,
    EMOTE_ONESHOT_STUN                           = 462,
    EMOTE_ONESHOT_SPELL_CAST_OMNI                = 463,
    EMOTE_STATE_READY_THROWN                     = 465,
    EMOTE_ONESHOT_WORK_CHOPWOOD                  = 466,
    EMOTE_ONESHOT_WORK_MINING                    = 467,
    EMOTE_STATE_SPELL_CHANNEL_OMNI               = 468,
    EMOTE_STATE_SPELL_CHANNEL_DIRECTED           = 469,
    EMOTE_STAND_STATE_NONE                       = 470,
    EMOTE_STATE_READYJOUST                       = 471,
    EMOTE_STATE_STRANGULATE                      = 472,
    EMOTE_STATE_STRANGULATE2                     = 473,
    EMOTE_STATE_READY_SPELL_OMNI                 = 474,
    EMOTE_STATE_HOLD_JOUST                       = 475,
    EMOTE_ONESHOT_CRY_JAINA                      = 476,
    EMOTE_ONESHOT_SPECIAL_UNARMED                = 477,
    EMOTE_STATE_DANCE_NOSHEATHE                  = 478,
    EMOTE_ONESHOT_SNIFF                          = 479,
    EMOTE_ONESHOT_DRAGONSTOMP                    = 480,
    EMOTE_ONESHOT_KNOCKDOWN                      = 482,
    EMOTE_STATE_READ                             = 483,
    EMOTE_ONESHOT_FLYEMOTETALK                   = 485,
    EMOTE_STATE_READ_ALLOWMOVEMENT               = 492,
    EMOTE_STATE_CUSTOM_SPELL_06                  = 498,
    EMOTE_STATE_CUSTOM_SPELL_07                  = 499,
    EMOTE_STATE_CUSTOM_SPELL_08_2                = 500,
    EMOTE_STATE_CUSTOM_SPELL_09                  = 501,
    EMOTE_STATE_CUSTOM_SPELL_10                  = 502,
    EMOTE_STATE_READY1H_ALLOW_MOVEMENT           = 505,
    EMOTE_STATE_READY2H_ALLOW_MOVEMENT           = 506,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED      = 507,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED     = 508,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED       = 509,
    EMOTE_STATE_MONKOFFENSE_READYUNARMED         = 510,
    EMOTE_ONESHOT_PALMSTRIKE                     = 511,
    EMOTE_STATE_CRANE                            = 512,
    EMOTE_ONESHOT_OPEN                           = 517,
    EMOTE_STATE_READ_CHRISTMAS                   = 518,
    EMOTE_ONESHOT_FLYATTACK2HL                   = 526,
    EMOTE_ONESHOT_FLYATTACKTHROWN                = 527,
    EMOTE_STATE_FLYREADYSPELLDIRECTED            = 528,
    EMOTE_STATE_FLY_READY_1H                     = 531,
    EMOTE_STATE_MEDITATE                         = 533,
    EMOTE_STATE_FLY_READY_2HL                    = 534,
    EMOTE_ONESHOT_TOGROUND                       = 535,
    EMOTE_ONESHOT_TOFLY                          = 536,
    EMOTE_STATE_ATTACKTHROWN                     = 537,
    EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND   = 538,
    EMOTE_ONESHOT_WORK                           = 539,
    EMOTE_STATE_READYUNARMED_NOSOUND             = 540,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF   = 543,
    EMOTE_RECLINED_MOUNT_PASSENGER               = 546,
    EMOTE_ONESHOT_QUESTION_2                     = 547,
    EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND = 549,
    EMOTE_STATE_KNEEL_2                          = 550,
    EMOTE_ONESHOT_FLYATTACKUNARMED               = 551,
    EMOTE_ONESHOT_FLYCOMBATWOUND                 = 552,
    EMOTE_ONESHOT_MOUNTSELFSPECIAL               = 553,
    EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND          = 554,
    EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK        = 555,
    EMOTE_ONESHOT_ATTACK1H_NO_SOUND              = 556,
    EMOTE_STATE_MOUNT_SELF_IDLE                  = 557,
    EMOTE_ONESHOT_WALK                           = 558,
    EMOTE_STATE_OPENED                           = 559,
    EMOTE_STATE_CUSTOMSPELL03                    = 564,
    EMOTE_ONESHOT_BREATHOFFIRE                   = 565,
    EMOTE_STATE_ATTACK1H                         = 567,
    EMOTE_STATE_WORK_CHOPWOOD_2                  = 568,
    EMOTE_STATE_USESTANDING_LOOP                 = 569,
    EMOTE_STATE_USESTANDING                      = 572,
    EMOTE_ONESHOT_SHEATH                         = 573,
    EMOTE_ONESHOT_LAUGH_NO_SOUND                 = 574,
    EMOTE_RECLINED_MOUNT                         = 575,
    EMOTE_ONESHOT_ATTACK1H_2                     = 577,
    EMOTE_STATE_CRY_NOSOUND                      = 578,
    EMOTE_ONESHOT_CRY_NOSOUND                    = 579,
    EMOTE_ONESHOT_COMBATCRITICAL                 = 584,
    EMOTE_STATE_TRAIN                            = 585,
    EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE         = 586,
    EMOTE_ONESHOT_SPECIALATTACK2H                = 587,
    EMOTE_STATE_READ_AND_TALK                    = 588,
    EMOTE_ONESHOT_STAND_VAR1                     = 589,
    EMOTE_REXXAR_STRANGLES_GOBLIN                = 590,
    EMOTE_ONESHOT_STAND_VAR2                     = 591,
    EMOTE_ONESHOT_DEATH                          = 592,
    EMOTE_STATE_TALKONCE                         = 595,
    EMOTE_STATE_ATTACK2H                         = 596,
    EMOTE_STATE_SIT_GROUND                       = 598,
    EMOTE_STATE_WORK_CHOPWOOD3                   = 599,
    EMOTE_STATE_CUSTOMSPELL01                    = 601,
    EMOTE_ONESHOT_COMBATWOUND                    = 602,
    EMOTE_ONESHOT_TALK_EXCLAMATION               = 603,
    EMOTE_ONESHOT_QUESTION2                      = 604,
    EMOTE_STATE_CRY                              = 605,
    EMOTE_STATE_USESTANDING_LOOP2                = 606,
    EMOTE_STATE_WORK_SMITH                       = 613,
    EMOTE_STATE_WORK_CHOPWOOD4                   = 614,
    EMOTE_STATE_CUSTOMSPELL02                    = 615,
    EMOTE_STATE_READ_AND_SIT                     = 616,
    EMOTE_STATE_PARRY_UNARMED                    = 619,
    EMOTE_STATE_BLOCK_SHIELD                     = 620,
    EMOTE_STATE_SIT_GROUND_2                     = 621,
    EMOTE_ONESHOT_MOUNTSPECIAL                   = 628,
    EMOTE_ONESHOT_SETTLE                         = 636,
    EMOTE_STATE_ATTACK_UNARMED_STILL             = 638,
    EMOTE_STATE_READ_BOOK_AND_TALK               = 641,
    EMOTE_ONESHOT_SLAM                           = 642,
    EMOTE_ONESHOT_GRABTHROWN                     = 643,
    EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND     = 644,
    EMOTE_STATE_READYSPELLOMNI_WITH_SOUND        = 645,
    EMOTE_ONESHOT_TALK_BARSERVER                 = 646,
    EMOTE_ONESHOT_WAVE_BARSERVER                 = 647,
    EMOTE_STATE_WORK_MINING2                     = 648,
    EMOTE_STATE_READY2HL_ALLOW_MOVEMENT          = 654,
    EMOTE_STATE_USESTANDING_NOSHEATHE_STILL      = 655,
    EMOTE_ONESHOT_WORK_STILL                     = 657,
    EMOTE_STATE_HOLD_THROWN_INTERRUPTS           = 658,
    EMOTE_ONESHOT_CANNIBALIZE                    = 659,
    EMOTE_ONESHOT_NO_NOT_SWIMMING                = 661,
    EMOTE_STATE_READYGLV                         = 663,
    EMOTE_ONESHOT_COMBATABILITYGLV01             = 664,
    EMOTE_ONESHOT_COMBATABILITYGLVOFF01          = 665,
    EMOTE_ONESHOT_COMBATABILITYGLVBIG02          = 666,
    EMOTE_ONESHOT_PARRYGLV                       = 667,
    EMOTE_STATE_WORK_MINING3                     = 668,
    EMOTE_ONESHOT_TALK_NOSHEATHE                 = 669,
    EMOTE_ONESHOT_STAND_VAR3                     = 671,
    EMOTE_STATE_KNEEL2                           = 672,
    EMOTE_ONESHOT_CUSTOM0                        = 673,
    EMOTE_ONESHOT_CUSTOM1                        = 674,
    EMOTE_ONESHOT_CUSTOM2                        = 675,
    EMOTE_ONESHOT_CUSTOM3                        = 676,
    EMOTE_STATE_FLY_READY_UNARMED                = 677,
    EMOTE_ONESHOT_CHEER_FORTHEALLIANCE           = 679,
    EMOTE_ONESHOT_CHEER_FORTHEHORDE              = 680,
    EMOTE_ONESHOT_STAND_VAR4                     = 690,
    EMOTE_ONESHOT_FLYEMOTEEXCLAMATION            = 691,
    EMOTE_STATE_EMOTEEAT                         = 700,
    EMOTE_STATE_MONKHEAL_CHANNELOMNI             = 705,
    EMOTE_STATE_MONKDEFENSE_READYUNARMED         = 706,
    EMOTE_ONESHOT_STAND                          = 707,
    EMOTE_STATE_WAPOURHOLD                       = 709,
    EMOTE_STATE_READYBLOWDART                    = 710,
    EMOTE_STATE_WORK_CHOPMEAT                    = 711,
    EMOTE_STATE_MONK2HLIDLE                      = 712,
    EMOTE_STATE_WAPERCH                          = 713,
    EMOTE_STATE_WAGUARDSTAND01                   = 714,
    EMOTE_STATE_READ_AND_SIT_CHAIR_MED           = 715,
    EMOTE_STATE_WAGUARDSTAND02                   = 716,
    EMOTE_STATE_WAGUARDSTAND03                   = 717,
    EMOTE_STATE_WAGUARDSTAND04                   = 718,
    EMOTE_STATE_WACHANT02                        = 719,
    EMOTE_STATE_WALEAN01                         = 720,
    EMOTE_STATE_DRUNKWALK                        = 721,
    EMOTE_STATE_WASCRUBBING                      = 722,
    EMOTE_STATE_WACHANT01                        = 723,
    EMOTE_STATE_WACHANT03                        = 724,
    EMOTE_STATE_WASUMMON01                       = 725,
    EMOTE_STATE_WATRANCE01                       = 726,
    EMOTE_STATE_CUSTOMSPELL05                    = 727,
    EMOTE_STATE_WAHAMMERLOOP                     = 728,
    EMOTE_STATE_WABOUND01                        = 729,
    EMOTE_STATE_WABOUND02                        = 730,
    EMOTE_STATE_WASACKHOLD                       = 731,
    EMOTE_STATE_WASIT01                          = 732,
    EMOTE_STATE_WAROWINGSTANDLEFT                = 733,
    EMOTE_STATE_WAROWINGSTANDRIGHT               = 734,
    EMOTE_STATE_LOOT_BITE_SOUND                  = 735,
    EMOTE_ONESHOT_WASUMMON01                     = 736,
    EMOTE_ONESHOT_STAND_VAR2_2                   = 737,
    EMOTE_ONESHOT_FALCONEER_START                = 738,
    EMOTE_STATE_FALCONEER_LOOP                   = 739,
    EMOTE_ONESHOT_FALCONEER_END                  = 740,
    EMOTE_STATE_WAPERCH_NOINTERACT               = 741,
    EMOTE_ONESHOT_WASTANDDRINK                   = 742,
    EMOTE_STATE_WALEAN02                         = 743,
    EMOTE_ONESHOT_READ_END                       = 744,
    EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT    = 745,
    EMOTE_STATE_READYCROSSBOW                    = 747,
    EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH          = 748,
    EMOTE_STATE_WAHANG01                         = 749,
    EMOTE_STATE_WABEGGARSTAND                    = 750,
    EMOTE_STATE_WADRUNKSTAND                     = 751,
    EMOTE_ONESHOT_WACRIERTALK                    = 753,
    EMOTE_STATE_HOLD_CROSSBOW                    = 754,
    EMOTE_STATE_WASIT02                          = 757,
    EMOTE_STATE_WACRANKSTAND                     = 761,
    EMOTE_ONESHOT_READ_START                     = 762,
    EMOTE_ONESHOT_READ_LOOP                      = 763,
    EMOTE_ONESHOT_WADRUNKDRINK                   = 765,
    EMOTE_STATE_SIT_CHAIR_MED_EAT                = 766,
    EMOTE_STATE_KNEEL_COPY                       = 867,
    EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE          = 868,
    EMOTE_ONESHOT_BARPATRON_POINT                = 870,
    EMOTE_STATE_STAND_NOSOUND                    = 871,
    EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND        = 872,
    EMOTE_STATE_USESTANDING_LOOP3                = 873,
    EMOTE_ONESHOT_VEHICLEGRAB                    = 874,
    EMOTE_STATE_USESTANDING_LOOP4                = 875,
    EMOTE_STATE_BARPATRON_STAND                  = 876,
    EMOTE_ONESHOT_WABEGGARPOINT                  = 877,
    EMOTE_STATE_WACRIERSTAND01                   = 878,
    EMOTE_ONESHOT_WABEGGARBEG                    = 879,
    EMOTE_STATE_WABOATWHEELSTAND                 = 880,
    EMOTE_STATE_WASIT03                          = 882,
    EMOTE_STATE_BARSWEEP_STAND                   = 883,
    EMOTE_STATE_WAGUARDSTAND05                   = 884,
    EMOTE_STATE_WAGUARDSTAND06                   = 885,
    EMOTE_STATE_BARTENDSTAND                     = 886,
    EMOTE_STATE_WAHAMMERLOOP2                    = 887,
    // EMOTE_STAND_STATE_STATE_READYTHROWN          = 890,  //< Doesn't work
    EMOTE_STATE_WORK_MINING_NO_COMBAT            = 893,
    EMOTE_ONESHOT_CASTSTRONG                     = 894,
    EMOTE_STATE_CUSTOMSPELL07                    = 895,
    EMOTE_STATE_WALK                             = 897,
    EMOTE_ONESHOT_CLOSE                          = 898,
    EMOTE_STATE_WACRATEHOLD                      = 900,
    EMOTE_STATE_FLYCUSTOMSPELL02                 = 901,
    EMOTE_ONESHOT_SLEEP                          = 902,
    EMOTE_STATE_STAND_SETEMOTESTATE              = 903,
    EMOTE_ONESHOT_WAWALKTALK                     = 904,
    EMOTE_ONESHOT_TAKE_OFF_FINISH                = 905,
    EMOTE_ONESHOT_ATTACK2H                       = 906,
    EMOTE_STATE_WA_BARREL_HOLD                   = 908,
    EMOTE_STATE_WA_BARREL_WALK                   = 909,
    EMOTE_STATE_CUSTOMSPELL04                    = 910,
    EMOTE_STATE_FLYWAPERCH01                     = 912,
    EMOTE_ONESHOT_PALSPELLCAST1HUP               = 916,
    EMOTE_ONESHOT_READYSPELLOMNI                 = 917,
    EMOTE_ONESHOT_SPELLCAST_DIRECTED             = 961,
    EMOTE_STATE_FLYCUSTOMSPELL07                 = 977,
    EMOTE_STATE_FLYCHANNELCASTOMNI               = 978,
    EMOTE_STATE_CLOSED                           = 979,
    EMOTE_STATE_CUSTOMSPELL10                    = 980,
    EMOTE_STATE_WAWHEELBARROWSTAND               = 981,
    EMOTE_STATE_CUSTOMSPELL06                    = 982,
    EMOTE_STATE_CUSTOM1                          = 983,
    EMOTE_STATE_WASIT04                          = 986,
    EMOTE_ONESHOT_BARSWEEP_STAND                 = 987,
    EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND   = 989,
    EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2  = 990,
    EMOTE_ONESHOT_STAND_VAR0                     = 991,
    EMOTE_ONESHOT_FLYCUSTOMSPELL01               = 992,
    EMOTE_ONESHOT_SPELLEFFECT_DECAY              = 993,
    EMOTE_STATE_CREATURE_SPECIAL                 = 994,
    EMOTE_ONESHOT_WAREACT01                      = 1001,
    EMOTE_ONESHOT_FLYCUSTOMSPELL04               = 1004,
    EMOTE_ONESHOT_TALK_SUBDUED                   = 1005,
    EMOTE_STATE_EMOTETALK                        = 1006,
    EMOTE_STATE_WAINTERACTION                    = 1007,
    EMOTE_ONESHOT_TAKE_OFF_START                 = 1009,
    EMOTE_ONESHOT_BATTLEROAR_NO_SOUND            = 1010,
    EMOTE_STATE_WAWEAPONSHARPEN                  = 1011,
    EMOTE_ONESHOT_ROLLSTART                      = 1012,
    EMOTE_ONESHOT_ROLLEND                        = 1013,
    EMOTE_ONESHOT_WAREACT02                      = 1014,
    EMOTE_ONESHOT_WATHREATEN                     = 1015,
    EMOTE_ARTOFFLOOP                             = 1016,
    EMOTE_STATE_READYSPELLOMNI_NOSHEATH          = 1017,
};

// AnimationData.db2 (6.0.2.18988)
enum Anim
{
    ANIM_STAND                               = 0,
    ANIM_DEATH                               = 1,
    ANIM_SPELL                               = 2,
    ANIM_STOP                                = 3,
    ANIM_WALK                                = 4,
    ANIM_RUN                                 = 5,
    ANIM_DEAD                                = 6,
    ANIM_RISE                                = 7,
    ANIM_STAND_WOUND                         = 8,
    ANIM_COMBAT_WOUND                        = 9,
    ANIM_COMBAT_CRITICAL                     = 10,
    ANIM_SHUFFLE_LEFT                        = 11,
    ANIM_SHUFFLE_RIGHT                       = 12,
    ANIM_WALK_BACKWARDS                      = 13,
    ANIM_STUN                                = 14,
    ANIM_HANDS_CLOSED                        = 15,
    ANIM_ATTACK_UNARMED                      = 16,
    ANIM_ATTACK1H                            = 17,
    ANIM_ATTACK2H                            = 18,
    ANIM_ATTACK2HL                           = 19,
    ANIM_PARRY_UNARMED                       = 20,
    ANIM_PARRY1H                             = 21,
    ANIM_PARRY2H                             = 22,
    ANIM_PARRY2HL                            = 23,
    ANIM_SHIELD_BLOCK                        = 24,
    ANIM_READY_UNARMED                       = 25,
    ANIM_READY1H                             = 26,
    ANIM_READY2H                             = 27,
    ANIM_READY2HL                            = 28,
    ANIM_READY_BOW                           = 29,
    ANIM_DODGE                               = 30,
    ANIM_SPELL_PRECAST                       = 31,
    ANIM_SPELL_CAST                          = 32,
    ANIM_SPELL_CAST_AREA                     = 33,
    ANIM_NPC_WELCOME                         = 34,
    ANIM_NPC_GOODBYE                         = 35,
    ANIM_BLOCK                               = 36,
    ANIM_JUMP_START                          = 37,
    ANIM_JUMP                                = 38,
    ANIM_JUMP_END                            = 39,
    ANIM_FALL                                = 40,
    ANIM_SWIM_IDLE                           = 41,
    ANIM_SWIM                                = 42,
    ANIM_SWIM_LEFT                           = 43,
    ANIM_SWIM_RIGHT                          = 44,
    ANIM_SWIM_BACKWARDS                      = 45,
    ANIM_ATTACK_BOW                          = 46,
    ANIM_FIRE_BOW                            = 47,
    ANIM_READY_RIFLE                         = 48,
    ANIM_ATTACK_RIFLE                        = 49,
    ANIM_LOOT                                = 50,
    ANIM_READY_SPELL_DIRECTED                = 51,
    ANIM_READY_SPELL_OMNI                    = 52,
    ANIM_SPELL_CAST_DIRECTED                 = 53,
    ANIM_SPELL_CAST_OMNI                     = 54,
    ANIM_BATTLE_ROAR                         = 55,
    ANIM_READY_ABILITY                       = 56,
    ANIM_SPECIAL1H                           = 57,
    ANIM_SPECIAL2H                           = 58,
    ANIM_SHIELD_BASH                         = 59,
    ANIM_EMOTE_TALK                          = 60,
    ANIM_EMOTE_EAT                           = 61,
    ANIM_EMOTE_WORK                          = 62,
    ANIM_EMOTE_USE_STANDING                  = 63,
    ANIM_EMOTE_TALK_EXCLAMATION              = 64,
    ANIM_EMOTE_TALK_QUESTION                 = 65,
    ANIM_EMOTE_BOW                           = 66,
    ANIM_EMOTE_WAVE                          = 67,
    ANIM_EMOTE_CHEER                         = 68,
    ANIM_EMOTE_DANCE                         = 69,
    ANIM_EMOTE_LAUGH                         = 70,
    ANIM_EMOTE_SLEEP                         = 71,
    ANIM_EMOTE_SIT_GROUND                    = 72,
    ANIM_EMOTE_RUDE                          = 73,
    ANIM_EMOTE_ROAR                          = 74,
    ANIM_EMOTE_KNEEL                         = 75,
    ANIM_EMOTE_KISS                          = 76,
    ANIM_EMOTE_CRY                           = 77,
    ANIM_EMOTE_CHICKEN                       = 78,
    ANIM_EMOTE_BEG                           = 79,
    ANIM_EMOTE_APPLAUD                       = 80,
    ANIM_EMOTE_SHOUT                         = 81,
    ANIM_EMOTE_FLEX                          = 82,
    ANIM_EMOTE_SHY                           = 83,
    ANIM_EMOTE_POINT                         = 84,
    ANIM_ATTACK1H_PIERCE                     = 85,
    ANIM_ATTACK2H_LOOSE_PIERCE               = 86,
    ANIM_ATTACK_OFF                          = 87,
    ANIM_ATTACK_OFF_PIERCE                   = 88,
    ANIM_SHEATHE                             = 89,
    ANIM_HIP_SHEATHE                         = 90,
    ANIM_MOUNT                               = 91,
    ANIM_RUN_RIGHT                           = 92,
    ANIM_RUN_LEFT                            = 93,
    ANIM_MOUNT_SPECIAL                       = 94,
    ANIM_KICK                                = 95,
    ANIM_SIT_GROUND_DOWN                     = 96,
    ANIM_SIT_GROUND                          = 97,
    ANIM_SIT_GROUND_UP                       = 98,
    ANIM_SLEEP_DOWN                          = 99,
    ANIM_SLEEP                               = 100,
    ANIM_SLEEP_UP                            = 101,
    ANIM_SIT_CHAIR_LOW                       = 102,
    ANIM_SIT_CHAIR_MED                       = 103,
    ANIM_SIT_CHAIR_HIGH                      = 104,
    ANIM_LOAD_BOW                            = 105,
    ANIM_LOAD_RIFLE                          = 106,
    ANIM_ATTACK_THROWN                       = 107,
    ANIM_READY_THROWN                        = 108,
    ANIM_HOLD_BOW                            = 109,
    ANIM_HOLD_RIFLE                          = 110,
    ANIM_HOLD_THROWN                         = 111,
    ANIM_LOAD_THROWN                         = 112,
    ANIM_EMOTE_SALUTE                        = 113,
    ANIM_KNEEL_START                         = 114,
    ANIM_KNEEL_LOOP                          = 115,
    ANIM_KNEEL_END                           = 116,
    ANIM_ATTACK_UNARMED_OFF                  = 117,
    ANIM_SPECIAL_UNARMED                     = 118,
    ANIM_STEALTH_WALK                        = 119,
    ANIM_STEALTH_STAND                       = 120,
    ANIM_KNOCKDOWN                           = 121,
    ANIM_EATING_LOOP                         = 122,
    ANIM_USE_STANDING_LOOP                   = 123,
    ANIM_CHANNEL_CAST_DIRECTED               = 124,
    ANIM_CHANNEL_CAST_OMNI                   = 125,
    ANIM_WHIRLWIND                           = 126,
    ANIM_BIRTH                               = 127,
    ANIM_USE_STANDING_START                  = 128,
    ANIM_USE_STANDING_END                    = 129,
    ANIM_CREATURE_SPECIAL                    = 130,
    ANIM_DROWN                               = 131,
    ANIM_DROWNED                             = 132,
    ANIM_FISHING_CAST                        = 133,
    ANIM_FISHING_LOOP                        = 134,
    ANIM_FLY                                 = 135,
    ANIM_EMOTE_WORK_NO_SHEATHE               = 136,
    ANIM_EMOTE_STUN_NO_SHEATHE               = 137,
    ANIM_EMOTE_USE_STANDING_NO_SHEATHE       = 138,
    ANIM_SPELL_SLEEP_DOWN                    = 139,
    ANIM_SPELL_KNEEL_START                   = 140,
    ANIM_SPELL_KNEEL_LOOP                    = 141,
    ANIM_SPELL_KNEEL_END                     = 142,
    ANIM_SPRINT                              = 143,
    ANIM_IN_FLIGHT                           = 144,
    ANIM_SPAWN                               = 145,
    ANIM_CLOSE                               = 146,
    ANIM_CLOSED                              = 147,
    ANIM_OPEN                                = 148,
    ANIM_OPENED                              = 149,
    ANIM_DESTROY                             = 150,
    ANIM_DESTROYED                           = 151,
    ANIM_REBUILD                             = 152,
    ANIM_CUSTOM_0                            = 153,
    ANIM_CUSTOM_1                            = 154,
    ANIM_CUSTOM_2                            = 155,
    ANIM_CUSTOM_3                            = 156,
    ANIM_DESPAWN                             = 157,
    ANIM_HOLD                                = 158,
    ANIM_DECAY                               = 159,
    ANIM_BOW_PULL                            = 160,
    ANIM_BOW_RELEASE                         = 161,
    ANIM_SHIP_START                          = 162,
    ANIM_SHIP_MOVING                         = 163,
    ANIM_SHIP_STOP                           = 164,
    ANIM_GROUP_ARROW                         = 165,
    ANIM_ARROW                               = 166,
    ANIM_CORPSE_ARROW                        = 167,
    ANIM_GUIDE_ARROW                         = 168,
    ANIM_SWAY                                = 169,
    ANIM_DRUID_CAT_POUNCE                    = 170,
    ANIM_DRUID_CAT_RIP                       = 171,
    ANIM_DRUID_CAT_RAKE                      = 172,
    ANIM_DRUID_CAT_RAVAGE                    = 173,
    ANIM_DRUID_CAT_CLAW                      = 174,
    ANIM_DRUID_CAT_COWER                     = 175,
    ANIM_DRUID_BEAR_SWIPE                    = 176,
    ANIM_DRUID_BEAR_BITE                     = 177,
    ANIM_DRUID_BEAR_MAUL                     = 178,
    ANIM_DRUID_BEAR_BASH                     = 179,
    ANIM_DRAGON_TAIL                         = 180,
    ANIM_DRAGON_STOMP                        = 181,
    ANIM_DRAGON_SPIT                         = 182,
    ANIM_DRAGON_SPIT_HOVER                   = 183,
    ANIM_DRAGON_SPIT_FLY                     = 184,
    ANIM_EMOTE_YES                           = 185,
    ANIM_EMOTE_NO                            = 186,
    ANIM_JUMP_LAND_RUN                       = 187,
    ANIM_LOOT_HOLD                           = 188,
    ANIM_LOOT_UP                             = 189,
    ANIM_STAND_HIGH                          = 190,
    ANIM_IMPACT                              = 191,
    ANIM_LIFTOFF                             = 192,
    ANIM_HOVER                               = 193,
    ANIM_SUCCUBUS_ENTICE                     = 194,
    ANIM_EMOTE_TRAIN                         = 195,
    ANIM_EMOTE_DEAD                          = 196,
    ANIM_EMOTE_DANCE_ONCE                    = 197,
    ANIM_DEFLECT                             = 198,
    ANIM_EMOTE_EAT_NO_SHEATHE                = 199,
    ANIM_LAND                                = 200,
    ANIM_SUBMERGE                            = 201,
    ANIM_SUBMERGED                           = 202,
    ANIM_CANNIBALIZE                         = 203,
    ANIM_ARROW_BIRTH                         = 204,
    ANIM_GROUP_ARROW_BIRTH                   = 205,
    ANIM_CORPSE_ARROW_BIRTH                  = 206,
    ANIM_GUIDE_ARROW_BIRTH                   = 207,
    ANIM_EMOTE_TALK_NO_SHEATHE               = 208,
    ANIM_EMOTE_POINT_NO_SHEATHE              = 209,
    ANIM_EMOTE_SALUTE_NO_SHEATHE             = 210,
    ANIM_EMOTE_DANCE_SPECIAL                 = 211,
    ANIM_MUTILATE                            = 212,
    ANIM_CUSTOM_SPELL_01                     = 213,
    ANIM_CUSTOM_SPELL_02                     = 214,
    ANIM_CUSTOM_SPELL_03                     = 215,
    ANIM_CUSTOM_SPELL_04                     = 216,
    ANIM_CUSTOM_SPELL_05                     = 217,
    ANIM_CUSTOM_SPELL_06                     = 218,
    ANIM_CUSTOM_SPELL_07                     = 219,
    ANIM_CUSTOM_SPELL_08                     = 220,
    ANIM_CUSTOM_SPELL_09                     = 221,
    ANIM_CUSTOM_SPELL_10                     = 222,
    ANIM_STEALTH_RUN                         = 223,
    ANIM_EMERGE                              = 224,
    ANIM_COWER                               = 225,
    ANIM_GRAB                                = 226,
    ANIM_GRAB_CLOSED                         = 227,
    ANIM_GRAB_THROWN                         = 228,
    ANIM_FLY_STAND                           = 229,
    ANIM_FLY_DEATH                           = 230,
    ANIM_FLY_SPELL                           = 231,
    ANIM_FLY_STOP                            = 232,
    ANIM_FLY_WALK                            = 233,
    ANIM_FLY_RUN                             = 234,
    ANIM_FLY_DEAD                            = 235,
    ANIM_FLY_RISE                            = 236,
    ANIM_FLY_STAND_WOUND                     = 237,
    ANIM_FLY_COMBAT_WOUND                    = 238,
    ANIM_FLY_COMBAT_CRITICAL                 = 239,
    ANIM_FLY_SHUFFLE_LEFT                    = 240,
    ANIM_FLY_SHUFFLE_RIGHT                   = 241,
    ANIM_FLY_WALK_BACKWARDS                  = 242,
    ANIM_FLY_STUN                            = 243,
    ANIM_FLY_HANDS_CLOSED                    = 244,
    ANIM_FLY_ATTACK_UNARMED                  = 245,
    ANIM_FLY_ATTACK1H                        = 246,
    ANIM_FLY_ATTACK2H                        = 247,
    ANIM_FLY_ATTACK2HL                       = 248,
    ANIM_FLY_PARRY_UNARMED                   = 249,
    ANIM_FLY_PARRY1H                         = 250,
    ANIM_FLY_PARRY2H                         = 251,
    ANIM_FLY_PARRY2HL                        = 252,
    ANIM_FLY_SHIELD_BLOCK                    = 253,
    ANIM_FLY_READY_UNARMED                   = 254,
    ANIM_FLY_READY1H                         = 255,
    ANIM_FLY_READY2H                         = 256,
    ANIM_FLY_READY2HL                        = 257,
    ANIM_FLY_READY_BOW                       = 258,
    ANIM_FLY_DODGE                           = 259,
    ANIM_FLY_SPELL_PRECAST                   = 260,
    ANIM_FLY_SPELL_CAST                      = 261,
    ANIM_FLY_SPELL_CAST_AREA                 = 262,
    ANIM_FLY_NPC_WELCOME                     = 263,
    ANIM_FLY_NPC_GOODBYE                     = 264,
    ANIM_FLY_BLOCK                           = 265,
    ANIM_FLY_JUMP_START                      = 266,
    ANIM_FLY_JUMP                            = 267,
    ANIM_FLY_JUMP_END                        = 268,
    ANIM_FLY_FALL                            = 269,
    ANIM_FLY_SWIM_IDLE                       = 270,
    ANIM_FLY_SWIM                            = 271,
    ANIM_FLY_SWIM_LEFT                       = 272,
    ANIM_FLY_SWIM_RIGHT                      = 273,
    ANIM_FLY_SWIM_BACKWARDS                  = 274,
    ANIM_FLY_ATTACK_BOW                      = 275,
    ANIM_FLY_FIRE_BOW                        = 276,
    ANIM_FLY_READY_RIFLE                     = 277,
    ANIM_FLY_ATTACK_RIFLE                    = 278,
    ANIM_FLY_LOOT                            = 279,
    ANIM_FLY_READY_SPELL_DIRECTED            = 280,
    ANIM_FLY_READY_SPELL_OMNI                = 281,
    ANIM_FLY_SPELL_CAST_DIRECTED             = 282,
    ANIM_FLY_SPELL_CAST_OMNI                 = 283,
    ANIM_FLY_SPELL_BATTLE_ROAR               = 284,
    ANIM_FLY_READY_ABILITY                   = 285,
    ANIM_FLY_SPECIAL1H                       = 286,
    ANIM_FLY_SPECIAL2H                       = 287,
    ANIM_FLY_SHIELD_BASH                     = 288,
    ANIM_FLY_EMOTE_TALK                      = 289,
    ANIM_FLY_EMOTE_EAT                       = 290,
    ANIM_FLY_EMOTE_WORK                      = 291,
    ANIM_FLY_USE_STANDING                    = 292,
    ANIM_FLY_EMOTE_TALK_EXCLAMATION          = 293,
    ANIM_FLY_EMOTE_TALK_QUESTION             = 294,
    ANIM_FLY_EMOTE_BOW                       = 295,
    ANIM_FLY_EMOTE_WAVE                      = 296,
    ANIM_FLY_EMOTE_CHEER                     = 297,
    ANIM_FLY_EMOTE_DANCE                     = 298,
    ANIM_FLY_EMOTE_LAUGH                     = 299,
    ANIM_FLY_EMOTE_SLEEP                     = 300,
    ANIM_FLY_EMOTE_SIT_GROUND                = 301,
    ANIM_FLY_EMOTE_RUDE                      = 302,
    ANIM_FLY_EMOTE_ROAR                      = 303,
    ANIM_FLY_EMOTE_KNEEL                     = 304,
    ANIM_FLY_EMOTE_KISS                      = 305,
    ANIM_FLY_EMOTE_CRY                       = 306,
    ANIM_FLY_EMOTE_CHICKEN                   = 307,
    ANIM_FLY_EMOTE_BEG                       = 308,
    ANIM_FLY_EMOTE_APPLAUD                   = 309,
    ANIM_FLY_EMOTE_SHOUT                     = 310,
    ANIM_FLY_EMOTE_FLEX                      = 311,
    ANIM_FLY_EMOTE_SHY                       = 312,
    ANIM_FLY_EMOTE_POINT                     = 313,
    ANIM_FLY_ATTACK1H_PIERCE                 = 314,
    ANIM_FLY_ATTACK2H_LOOSE_PIERCE           = 315,
    ANIM_FLY_ATTACK_OFF                      = 316,
    ANIM_FLY_ATTACK_OFF_PIERCE               = 317,
    ANIM_FLY_SHEATH                          = 318,
    ANIM_FLY_HIP_SHEATH                      = 319,
    ANIM_FLY_MOUNT                           = 320,
    ANIM_FLY_RUN_RIGHT                       = 321,
    ANIM_FLY_RUN_LEFT                        = 322,
    ANIM_FLY_MOUNT_SPECIAL                   = 323,
    ANIM_FLY_KICK                            = 324,
    ANIM_FLY_SIT_GROUND_DOWN                 = 325,
    ANIM_FLY_SIT_GROUND                      = 326,
    ANIM_FLY_SIT_GROUND_UP                   = 327,
    ANIM_FLY_SLEEP_DOWN                      = 328,
    ANIM_FLY_SLEEP                           = 329,
    ANIM_FLY_SLEEP_UP                        = 330,
    ANIM_FLY_SIT_CHAIR_LOW                   = 331,
    ANIM_FLY_SIT_CHAIR_MED                   = 332,
    ANIM_FLY_SIT_CHAIR_HIGH                  = 333,
    ANIM_FLY_LOAD_BOW                        = 334,
    ANIM_FLY_LOAD_RIFLE                      = 335,
    ANIM_FLY_ATTACK_THROWN                   = 336,
    ANIM_FLY_READY_THROWN                    = 337,
    ANIM_FLY_HOLD_BOW                        = 338,
    ANIM_FLY_HOLD_RIFLE                      = 339,
    ANIM_FLY_HOLD_THROWN                     = 340,
    ANIM_FLY_LOAD_THROWN                     = 341,
    ANIM_FLY_EMOTE_SALUTE                    = 342,
    ANIM_FLY_KNEEL_START                     = 343,
    ANIM_FLY_KNEEL_LOOP                      = 344,
    ANIM_FLY_KNEEL_END                       = 345,
    ANIM_FLY_ATTACK_UNARMED_OFF              = 346,
    ANIM_FLY_SPECIAL_UNARMED                 = 347,
    ANIM_FLY_STEALTH_WALK                    = 348,
    ANIM_FLY_STEALTH_STAND                   = 349,
    ANIM_FLY_KNOCKDOWN                       = 350,
    ANIM_FLY_EATING_LOOP                     = 351,
    ANIM_FLY_USE_STANDING_LOOP               = 352,
    ANIM_FLY_CHANNEL_CAST_DIRECTED           = 353,
    ANIM_FLY_CHANNEL_CAST_OMNI               = 354,
    ANIM_FLY_WHIRLWIND                       = 355,
    ANIM_FLY_BIRTH                           = 356,
    ANIM_FLY_USE_STANDING_START              = 357,
    ANIM_FLY_USE_STANDING_END                = 358,
    ANIM_FLY_CREATURE_SPECIAL                = 359,
    ANIM_FLY_DROWN                           = 360,
    ANIM_FLY_DROWNED                         = 361,
    ANIM_FLY_FISHING_CAST                    = 362,
    ANIM_FLY_FISHING_LOOP                    = 363,
    ANIM_FLY_FLY                             = 364,
    ANIM_FLY_EMOTE_WORK_NO_SHEATHE           = 365,
    ANIM_FLY_EMOTE_STUN_NO_SHEATHE           = 366,
    ANIM_FLY_EMOTE_USE_STANDING_NO_SHEATHE   = 367,
    ANIM_FLY_SPELL_SLEEP_DOWN                = 368,
    ANIM_FLY_SPELL_KNEEL_START               = 369,
    ANIM_FLY_SPELL_KNEEL_LOOP                = 370,
    ANIM_FLY_SPELL_KNEEL_END                 = 371,
    ANIM_FLY_SPRINT                          = 372,
    ANIM_FLY_IN_FLIGHT                       = 373,
    ANIM_FLY_SPAWN                           = 374,
    ANIM_FLY_CLOSE                           = 375,
    ANIM_FLY_CLOSED                          = 376,
    ANIM_FLY_OPEN                            = 377,
    ANIM_FLY_OPENED                          = 378,
    ANIM_FLY_DESTROY                         = 379,
    ANIM_FLY_DESTROYED                       = 380,
    ANIM_FLY_REBUILD                         = 381,
    ANIM_FLY_CUSTOM_0                        = 382,
    ANIM_FLY_CUSTOM_1                        = 383,
    ANIM_FLY_CUSTOM_2                        = 384,
    ANIM_FLY_CUSTOM_3                        = 385,
    ANIM_FLY_DESPAWN                         = 386,
    ANIM_FLY_HOLD                            = 387,
    ANIM_FLY_DECAY                           = 388,
    ANIM_FLY_BOW_PULL                        = 389,
    ANIM_FLY_BOW_RELEASE                     = 390,
    ANIM_FLY_SHIP_START                      = 391,
    ANIM_FLY_SHIP_MOVING                     = 392,
    ANIM_FLY_SHIP_STOP                       = 393,
    ANIM_FLY_GROUP_ARROW                     = 394,
    ANIM_FLY_ARROW                           = 395,
    ANIM_FLY_CORPSE_ARROW                    = 396,
    ANIM_FLY_GUIDE_ARROW                     = 397,
    ANIM_FLY_SWAY                            = 398,
    ANIM_FLY_DRUID_CAT_POUNCE                = 399,
    ANIM_FLY_DRUID_CAT_RIP                   = 400,
    ANIM_FLY_DRUID_CAT_RAKE                  = 401,
    ANIM_FLY_DRUID_CAT_RAVAGE                = 402,
    ANIM_FLY_DRUID_CAT_CLAW                  = 403,
    ANIM_FLY_DRUID_CAT_COWER                 = 404,
    ANIM_FLY_DRUID_BEAR_SWIPE                = 405,
    ANIM_FLY_DRUID_BEAR_BITE                 = 406,
    ANIM_FLY_DRUID_BEAR_MAUL                 = 407,
    ANIM_FLY_DRUID_BEAR_BASH                 = 408,
    ANIM_FLY_DRAGON_TAIL                     = 409,
    ANIM_FLY_DRAGON_STOMP                    = 410,
    ANIM_FLY_DRAGON_SPIT                     = 411,
    ANIM_FLY_DRAGON_SPIT_HOVER               = 412,
    ANIM_FLY_DRAGON_SPIT_FLY                 = 413,
    ANIM_FLY_EMOTE_YES                       = 414,
    ANIM_FLY_EMOTE_NO                        = 415,
    ANIM_FLY_JUMP_LAND_RUN                   = 416,
    ANIM_FLY_LOOT_HOLD                       = 417,
    ANIM_FLY_LOOT_UP                         = 418,
    ANIM_FLY_STAND_HIGH                      = 419,
    ANIM_FLY_IMPACT                          = 420,
    ANIM_FLY_LIFTOFF                         = 421,
    ANIM_FLY_HOVER                           = 422,
    ANIM_FLY_SUCCUBUS_ENTICE                 = 423,
    ANIM_FLY_EMOTE_TRAIN                     = 424,
    ANIM_FLY_EMOTE_DEAD                      = 425,
    ANIM_FLY_EMOTE_DANCE_ONCE                = 426,
    ANIM_FLY_DEFLECT                         = 427,
    ANIM_FLY_EMOTE_EAT_NO_SHEATHE            = 428,
    ANIM_FLY_LAND                            = 429,
    ANIM_FLY_SUBMERGE                        = 430,
    ANIM_FLY_SUBMERGED                       = 431,
    ANIM_FLY_CANNIBALIZE                     = 432,
    ANIM_FLY_ARROW_BIRTH                     = 433,
    ANIM_FLY_GROUP_ARROW_BIRTH               = 434,
    ANIM_FLY_CORPSE_ARROW_BIRTH              = 435,
    ANIM_FLY_GUIDE_ARROW_BIRTH               = 436,
    ANIM_FLY_EMOTE_TALK_NO_SHEATHE           = 437,
    ANIM_FLY_EMOTE_POINT_NO_SHEATHE          = 438,
    ANIM_FLY_EMOTE_SALUTE_NO_SHEATHE         = 439,
    ANIM_FLY_EMOTE_DANCE_SPECIAL             = 440,
    ANIM_FLY_MUTILATE                        = 441,
    ANIM_FLY_CUSTOM_SPELL_01                 = 442,
    ANIM_FLY_CUSTOM_SPELL_02                 = 443,
    ANIM_FLY_CUSTOM_SPELL_03                 = 444,
    ANIM_FLY_CUSTOM_SPELL_04                 = 445,
    ANIM_FLY_CUSTOM_SPELL_05                 = 446,
    ANIM_FLY_CUSTOM_SPELL_06                 = 447,
    ANIM_FLY_CUSTOM_SPELL_07                 = 448,
    ANIM_FLY_CUSTOM_SPELL_08                 = 449,
    ANIM_FLY_CUSTOM_SPELL_09                 = 450,
    ANIM_FLY_CUSTOM_SPELL_10                 = 451,
    ANIM_FLY_STEALTH_RUN                     = 452,
    ANIM_FLY_EMERGE                          = 453,
    ANIM_FLY_COWER                           = 454,
    ANIM_FLY_GRAB                            = 455,
    ANIM_FLY_GRAB_CLOSED                     = 456,
    ANIM_FLY_GRAB_THROWN                     = 457,
    ANIM_TO_FLY                              = 458,
    ANIM_TO_HOVER                            = 459,
    ANIM_TO_GROUND                           = 460,
    ANIM_FLY_TO_FLY                          = 461,
    ANIM_FLY_TO_HOVER                        = 462,
    ANIM_FLY_TO_GROUND                       = 463,
    ANIM_SETTLE                              = 464,
    ANIM_FLY_SETTLE                          = 465,
    ANIM_DEATH_START                         = 466,
    ANIM_DEATH_LOOP                          = 467,
    ANIM_DEATH_END                           = 468,
    ANIM_FLY_DEATH_START                     = 469,
    ANIM_FLY_DEATH_LOOP                      = 470,
    ANIM_FLY_DEATH_END                       = 471,
    ANIM_DEATH_END_HOLD                      = 472,
    ANIM_FLY_DEATH_END_HOLD                  = 473,
    ANIM_STRANGULATE                         = 474,
    ANIM_FLY_STRANGULATE                     = 475,
    ANIM_READY_JOUST                         = 476,
    ANIM_LOAD_JOUST                          = 477,
    ANIM_HOLD_JOUST                          = 478,
    ANIM_FLY_READY_JOUST                     = 479,
    ANIM_FLY_LOAD_JOUST                      = 480,
    ANIM_FLY_HOLD_JOUST                      = 481,
    ANIM_ATTACK_JOUST                        = 482,
    ANIM_FLY_ATTACK_JOUST                    = 483,
    ANIM_RECLINED_MOUNT                      = 484,
    ANIM_FLY_RECLINED_MOUNT                  = 485,
    ANIM_TO_ALTERED                          = 486,
    ANIM_FROM_ALTERED                        = 487,
    ANIM_FLY_TO_ALTERED                      = 488,
    ANIM_FLY_FROM_ALTERED                    = 489,
    ANIM_IN_STOCKS                           = 490,
    ANIM_FLY_IN_STOCKS                       = 491,
    ANIM_VEHICLE_GRAB                        = 492,
    ANIM_VEHICLE_THROW                       = 493,
    ANIM_FLY_VEHICLE_GRAB                    = 494,
    ANIM_FLY_VEHICLE_THROW                   = 495,
    ANIM_TO_ALTERED_POST_SWAP                = 496,
    ANIM_FROM_ALTERED_POST_SWAP              = 497,
    ANIM_FLY_TO_ALTERED_POST_SWAP            = 498,
    ANIM_FLY_FROM_ALTERED_POST_SWAP          = 499,
    ANIM_RECLINED_MOUNT_PASSENGER            = 500,
    ANIM_FLY_RECLINED_MOUNT_PASSENGER        = 501,
    ANIM_CARRY2H                             = 502,
    ANIM_CARRIED2H                           = 503,
    ANIM_FLY_CARRY2H                         = 504,
    ANIM_FLY_CARRIED2H                       = 505,
    ANIM_EMOTE_SNIFF                         = 506,
    ANIM_EMOTE_FLY_SNIFF                     = 507,
    ANIM_ATTACK_FIST1H                       = 508,
    ANIM_FLY_ATTACK_FIST1H                   = 509,
    ANIM_ATTACK_FIST_1H_OFF                  = 510,
    ANIM_FLY_ATTACK_FIST_1H_OFF              = 511,
    ANIM_PARRY_FIST1H                        = 512,
    ANIM_FLY_PARRY_FIST1H                    = 513,
    ANIM_READY_FIST1H                        = 514,
    ANIM_FLY_READY_FIST1H                    = 515,
    ANIM_SPECIAL_FIST1H                      = 516,
    ANIM_FLY_SPECIAL_FIST1H                  = 517,
    ANIM_EMOTE_READ_START                    = 518,
    ANIM_FLY_EMOTE_READ_START                = 519,
    ANIM_EMOTE_READ_LOOP                     = 520,
    ANIM_FLY_EMOTE_READ_LOOP                 = 521,
    ANIM_EMOTE_READ_END                      = 522,
    ANIM_FLY_EMOTE_READ_END                  = 523,
    ANIM_SWIM_RUN                            = 524,
    ANIM_FLY_SWIM_RUN                        = 525,
    ANIM_SWIM_WALK                           = 526,
    ANIM_FLY_SWIM_WALK                       = 527,
    ANIM_SWIM_WALK_BACKWARDS                 = 528,
    ANIM_FLY_SWIM_WALK_BACKWARDS             = 529,
    ANIM_SWIM_SPRINT                         = 530,
    ANIM_FLY_SWIM_SPRINT                     = 531,
    ANIM_MOUNT_SWIM_IDLE                     = 532,
    ANIM_FLY_MOUNT_SWIM_IDLE                 = 533,
    ANIM_MOUNT_SWIM_BACKWARDS                = 534,
    ANIM_FLY_MOUNT_SWIM_BACKWARDS            = 535,
    ANIM_MOUNT_SWIM_LEFT                     = 536,
    ANIM_FLY_MOUNT_SWIM_LEFT                 = 537,
    ANIM_MOUNT_SWIM_RIGHT                    = 538,
    ANIM_FLY_MOUNT_SWIM_RIGHT                = 539,
    ANIM_MOUNT_SWIM_RUN                      = 540,
    ANIM_FLY_MOUNT_SWIM_RUN                  = 541,
    ANIM_MOUNT_SWIM_SPRINT                   = 542,
    ANIM_FLY_MOUNT_SWIM_SPRINT               = 543,
    ANIM_MOUNT_SWIM_WALK                     = 544,
    ANIM_FLY_MOUNT_SWIM_WALK                 = 545,
    ANIM_MOUNT_SWIM_WALK_BACKWARDS           = 546,
    ANIM_FLY_MOUNT_SWIM_WALK_BACKWARDS       = 547,
    ANIM_MOUNT_FLIGHT_IDLE                   = 548,
    ANIM_FLY_MOUNT_FLIGHT_IDLE               = 549,
    ANIM_MOUNT_FLIGHT_BACKWARDS              = 550,
    ANIM_FLY_MOUNT_FLIGHT_BACKWARDS          = 551,
    ANIM_MOUNT_FLIGHT_LEFT                   = 552,
    ANIM_FLY_MOUNT_FLIGHT_LEFT               = 553,
    ANIM_MOUNT_FLIGHT_RIGHT                  = 554,
    ANIM_FLY_MOUNT_FLIGHT_RIGHT              = 555,
    ANIM_MOUNT_FLIGHT_RUN                    = 556,
    ANIM_FLY_MOUNT_FLIGHT_RUN                = 557,
    ANIM_MOUNT_FLIGHT_SPRINT                 = 558,
    ANIM_FLY_MOUNT_FLIGHT_SPRINT             = 559,
    ANIM_MOUNT_FLIGHT_WALK                   = 560,
    ANIM_FLY_MOUNT_FLIGHT_WALK               = 561,
    ANIM_MOUNT_FLIGHT_WALK_BACKWARDS         = 562,
    ANIM_FLY_MOUNT_FLIGHT_WALK_BACKWARDS     = 563,
    ANIM_MOUNT_FLIGHT_START                  = 564,
    ANIM_FLY_MOUNT_FLIGHT_START              = 565,
    ANIM_MOUNT_SWIM_START                    = 566,
    ANIM_FLY_MOUNT_SWIM_START                = 567,
    ANIM_MOUNT_SWIM_LAND                     = 568,
    ANIM_FLY_MOUNT_SWIM_LAND                 = 569,
    ANIM_MOUNT_SWIM_LAND_RUN                 = 570,
    ANIM_FLY_MOUNT_SWIM_LAND_RUN             = 571,
    ANIM_MOUNT_FLIGHT_LAND                   = 572,
    ANIM_FLY_MOUNT_FLIGHT_LAND               = 573,
    ANIM_MOUNT_FLIGHT_LAND_RUN               = 574,
    ANIM_FLY_MOUNT_FLIGHT_LAND_RUN           = 575,
    ANIM_READY_BLOW_DART                     = 576,
    ANIM_FLY_READY_BLOW_DART                 = 577,
    ANIM_LOAD_BLOW_DART                      = 578,
    ANIM_FLY_LOAD_BLOW_DART                  = 579,
    ANIM_HOLD_BLOW_DART                      = 580,
    ANIM_FLY_HOLD_BLOW_DART                  = 581,
    ANIM_ATTACK_BLOW_DART                    = 582,
    ANIM_FLY_ATTACK_BLOW_DART                = 583,
    ANIM_CARRIAGE_MOUNT                      = 584,
    ANIM_FLY_CARRIAGE_MOUNT                  = 585,
    ANIM_CARRIAGE_PASSENGER_MOUNT            = 586,
    ANIM_FLY_CARRIAGE_PASSENGER_MOUNT        = 587,
    ANIM_CARRIAGE_MOUNT_ATTACK               = 588,
    ANIM_FLY_CARRIAGE_MOUNT_ATTACK           = 589,
    ANIM_BARTENDER_STAND                     = 590,
    ANIM_FLY_BARTENDER_STAND                 = 591,
    ANIM_BARTENDER_WALK                      = 592,
    ANIM_FLY_BARTENDER_WALK                  = 593,
    ANIM_BARTENDER_RUN                       = 594,
    ANIM_FLY_BARTENDER_RUN                   = 595,
    ANIM_BARTENDER_SHUFFLE_LEFT              = 596,
    ANIM_FLY_BARTENDER_SHUFFLE_LEFT          = 597,
    ANIM_BARTENDER_SHUFFLE_RIGHT             = 598,
    ANIM_FLY_BARTENDER_SHUFFLE_RIGHT         = 599,
    ANIM_BARTENDER_EMOTE_TALK                = 600,
    ANIM_FLY_BARTENDER_EMOTE_TALK            = 601,
    ANIM_BARTENDER_EMOTE_POINT               = 602,
    ANIM_FLY_BARTENDER_EMOTE_POINT           = 603,
    ANIM_BARMAID_STAND                       = 604,
    ANIM_FLY_BARMAID_STAND                   = 605,
    ANIM_BARMAID_WALK                        = 606,
    ANIM_FLY_BARMAID_WALK                    = 607,
    ANIM_BARMAID_RUN                         = 608,
    ANIM_FLY_BARMAID_RUN                     = 609,
    ANIM_BARMAID_SHUFFLE_LEFT                = 610,
    ANIM_FLY_BARMAID_SHUFFLE_LEFT            = 611,
    ANIM_BARMAID_SHUFFLE_RIGHT               = 612,
    ANIM_FLY_BARMAID_SHUFFLE_RIGHT           = 613,
    ANIM_BARMAID_EMOTE_TALK                  = 614,
    ANIM_FLY_BARMAID_EMOTE_TALK              = 615,
    ANIM_BARMAID_EMOTE_POINT                 = 616,
    ANIM_FLY_BARMAID_EMOTE_POINT             = 617,
    ANIM_MOUNT_SELF_IDLE                     = 618,
    ANIM_FLY_MOUNT_SELF_IDLE                 = 619,
    ANIM_MOUNT_SELF_WALK                     = 620,
    ANIM_FLY_MOUNT_SELF_WALK                 = 621,
    ANIM_MOUNT_SELF_RUN                      = 622,
    ANIM_FLY_MOUNT_SELF_RUN                  = 623,
    ANIM_MOUNT_SELF_SPRINT                   = 624,
    ANIM_FLY_MOUNT_SELF_SPRINT               = 625,
    ANIM_MOUNT_SELF_RUN_LEFT                 = 626,
    ANIM_FLY_MOUNT_SELF_RUN_LEFT             = 627,
    ANIM_MOUNT_SELF_RUN_RIGHT                = 628,
    ANIM_FLY_MOUNT_SELF_RUN_RIGHT            = 629,
    ANIM_MOUNT_SELF_SHUFFLE_LEFT             = 630,
    ANIM_FLY_MOUNT_SELF_SHUFFLE_LEFT         = 631,
    ANIM_MOUNT_SELF_SHUFFLE_RIGHT            = 632,
    ANIM_FLY_MOUNT_SELF_SHUFFLE_RIGHT        = 633,
    ANIM_MOUNT_SELF_WALK_BACKWARDS           = 634,
    ANIM_FLY_MOUNT_SELF_WALK_BACKWARDS       = 635,
    ANIM_MOUNT_SELF_SPECIAL                  = 636,
    ANIM_FLY_MOUNT_SELF_SPECIAL              = 637,
    ANIM_MOUNT_SELF_JUMP                     = 638,
    ANIM_FLY_MOUNT_SELF_JUMP                 = 639,
    ANIM_MOUNT_SELF_JUMP_START               = 640,
    ANIM_FLY_MOUNT_SELF_JUMP_START           = 641,
    ANIM_MOUNT_SELF_JUMP_END                 = 642,
    ANIM_FLY_MOUNT_SELF_JUMP_END             = 643,
    ANIM_MOUNT_SELF_JUMP_LAND_RUN            = 644,
    ANIM_FLY_MOUNT_SELF_JUMP_LAND_RUN        = 645,
    ANIM_MOUNT_SELF_START                    = 646,
    ANIM_FLY_MOUNT_SELF_START                = 647,
    ANIM_MOUNT_SELF_FALL                     = 648,
    ANIM_FLY_MOUNT_SELF_FALL                 = 649,
    ANIM_STORMSTRIKE                         = 650,
    ANIM_FLY_STORMSTRIKE                     = 651,
    ANIM_READY_JOUST_NO_SHEATHE              = 652,
    ANIM_FLY_READY_JOUST_NO_SHEATHE          = 653,
    ANIM_SLAM                                = 654,
    ANIM_FLY_SLAM                            = 655,
    ANIM_DEATH_STRIKE                        = 656,
    ANIM_FLY_DEATH_STRIKE                    = 657,
    ANIM_SWIM_ATTACK_UNARMED                 = 658,
    ANIM_FLY_SWIM_ATTACK_UNARMED             = 659,
    ANIM_SPINNING_KICK                       = 660,
    ANIM_FLY_SPINNING_KICK                   = 661,
    ANIM_ROUND_HOUSE_KICK                    = 662,
    ANIM_FLY_ROUND_HOUSE_KICK                = 663,
    ANIM_ROLL_START                          = 664,
    ANIM_FLY_ROLL_START                      = 665,
    ANIM_ROLL                                = 666,
    ANIM_FLY_ROLL                            = 667,
    ANIM_ROLL_END                            = 668,
    ANIM_FLY_ROLL_END                        = 669,
    ANIM_PALM_STRIKE                         = 670,
    ANIM_FLY_PALM_STRIKE                     = 671,
    ANIM_MONK_OFFENSE_ATTACK_UNARMED         = 672,
    ANIM_FLY_MONK_OFFENSE_ATTACK_UNARMED     = 673,
    ANIM_MONK_OFFENSE_ATTACK_UNARMED_OFF     = 674,
    ANIM_FLY_MONK_OFFENSE_ATTACK_UNARMED_OFF = 675,
    ANIM_MONK_OFFENSE_PARRY_UNARMED          = 676,
    ANIM_FLY_MONK_OFFENSE_PARRY_UNARMED      = 677,
    ANIM_MONK_OFFENSE_READY_UNARMED          = 678,
    ANIM_FLY_MONK_OFFENSE_READY_UNARMED      = 679,
    ANIM_MONK_OFFENSE_SPECIAL_UNARMED        = 680,
    ANIM_FLY_MONK_OFFENSE_SPECIAL_UNARMED    = 681,
    ANIM_MONK_DEFENSE_ATTACK_UNARMED         = 682,
    ANIM_FLY_MONK_DEFENSE_ATTACK_UNARMED     = 683,
    ANIM_MONK_DEFENSE_ATTACK_UNARMED_OFF     = 684,
    ANIM_FLY_MONK_DEFENSE_ATTACK_UNARMED_OFF = 685,
    ANIM_MONK_DEFENSE_PARRY_UNARMED          = 686,
    ANIM_FLY_MONK_DEFENSE_PARRY_UNARMED      = 687,
    ANIM_MONK_DEFENSE_READY_UNARMED          = 688,
    ANIM_FLY_MONK_DEFENSE_READY_UNARMED      = 689,
    ANIM_MONK_DEFENSE_SPECIAL_UNARMED        = 690,
    ANIM_FLY_MONK_DEFENSE_SPECIAL_UNARMED    = 691,
    ANIM_MONK_HEAL_ATTACK_UNARMED            = 692,
    ANIM_FLY_MONK_HEAL_ATTACK_UNARMED        = 693,
    ANIM_MONK_HEAL_ATTACK_UNARMED_OFF        = 694,
    ANIM_FLY_MONK_HEAL_ATTACK_UNARMED_OFF    = 695,
    ANIM_MONK_HEAL_PARRY_UNARMED             = 696,
    ANIM_FLY_MONK_HEAL_PARRY_UNARMED         = 697,
    ANIM_MONK_HEAL_READY_UNARMED             = 698,
    ANIM_FLY_MONK_HEAL_READY_UNARMED         = 699,
    ANIM_MONK_HEAL_SPECIAL_UNARMED           = 700,
    ANIM_FLY_MONK_HEAL_SPECIAL_UNARMED       = 701,
    ANIM_FLYING_KICK                         = 702,
    ANIM_FLY_FLYING_KICK                     = 703,
    ANIM_FLYING_KICK_START                   = 704,
    ANIM_FLY_FLYING_KICK_START               = 705,
    ANIM_FLYING_KICK_END                     = 706,
    ANIM_FLY_FLYING_KICK_END                 = 707,
    ANIM_CRANE_START                         = 708,
    ANIM_FLY_CRANE_START                     = 709,
    ANIM_CRANE_LOOP                          = 710,
    ANIM_FLY_CRANE_LOOP                      = 711,
    ANIM_CRANE_END                           = 712,
    ANIM_FLY_CRANE_END                       = 713,
    ANIM_DESPAWNED                           = 714,
    ANIM_FLY_DESPAWNED                       = 715,
    ANIM_THOUSAND_FISTS                      = 716,
    ANIM_FLY_THOUSAND_FISTS                  = 717,
    ANIM_MONK_HEAL_READY_SPELL_DIRECTED      = 718,
    ANIM_FLY_MONK_HEAL_READY_SPELL_DIRECTED  = 719,
    ANIM_MONK_HEAL_READY_SPELL_OMNI          = 720,
    ANIM_FLY_MONK_HEAL_READY_SPELL_OMNI      = 721,
    ANIM_MONK_HEAL_SPELL_CAST_DIRECTED       = 722,
    ANIM_FLY_MONK_HEAL_SPELL_CAST_DIRECTED   = 723,
    ANIM_MONK_HEAL_SPELL_CAST_OMNI           = 724,
    ANIM_FLY_MONK_HEAL_SPELL_CAST_OMNI       = 725,
    ANIM_MONK_HEAL_CHANNEL_CAST_DIRECTED     = 726,
    ANIM_FLY_MONK_HEAL_CHANNEL_CAST_DIRECTED = 727,
    ANIM_MONK_HEAL_CHANNEL_CAST_OMNI         = 728,
    ANIM_FLY_MONK_HEAL_CHANNEL_CAST_OMNI     = 729,
    ANIM_TORPEDO                             = 730,
    ANIM_FLY_TORPEDO                         = 731,
    ANIM_MEDITATE                            = 732,
    ANIM_FLY_MEDITATE                        = 733,
    ANIM_BREATH_OF_FIRE                      = 734,
    ANIM_FLY_BREATH_OF_FIRE                  = 735,
    ANIM_RISING_SUN_KICK                     = 736,
    ANIM_FLY_RISING_SUN_KICK                 = 737,
    ANIM_GROUND_KICK                         = 738,
    ANIM_FLY_GROUND_KICK                     = 739,
    ANIM_KICK_BACK                           = 740,
    ANIM_FLY_KICK_BACK                       = 741,
    ANIM_PET_BATTLE_STAND                    = 742,
    ANIM_FLY_PET_BATTLE_STAND                = 743,
    ANIM_PET_BATTLE_DEATH                    = 744,
    ANIM_FLY_PET_BATTLE_DEATH                = 745,
    ANIM_PET_BATTLE_RUN                      = 746,
    ANIM_FLY_PET_BATTLE_RUN                  = 747,
    ANIM_PET_BATTLE_WOUND                    = 748,
    ANIM_FLY_PET_BATTLE_WOUND                = 749,
    ANIM_PET_BATTLE_ATTACK                   = 750,
    ANIM_FLY_PET_BATTLE_ATTACK               = 751,
    ANIM_PET_BATTLE_READY_SPELL              = 752,
    ANIM_FLY_PET_BATTLE_READY_SPELL          = 753,
    ANIM_PET_BATTLE_SPELL_CAST               = 754,
    ANIM_FLY_PET_BATTLE_SPELL_CAST           = 755,
    ANIM_PET_BATTLE_CUSTOM0                  = 756,
    ANIM_FLY_PET_BATTLE_CUSTOM0              = 757,
    ANIM_PET_BATTLE_CUSTOM1                  = 758,
    ANIM_FLY_PET_BATTLE_CUSTOM1              = 759,
    ANIM_PET_BATTLE_CUSTOM2                  = 760,
    ANIM_FLY_PET_BATTLE_CUSTOM2              = 761,
    ANIM_PET_BATTLE_CUSTOM3                  = 762,
    ANIM_FLY_PET_BATTLE_CUSTOM3              = 763,
    ANIM_PET_BATTLE_VICTORY                  = 764,
    ANIM_FLY_PET_BATTLE_VICTORY              = 765,
    ANIM_PET_BATTLE_LOSS                     = 766,
    ANIM_FLY_PET_BATTLE_LOSS                 = 767,
    ANIM_PET_BATTLE_STUN                     = 768,
    ANIM_FLY_PET_BATTLE_STUN                 = 769,
    ANIM_PET_BATTLE_DEAD                     = 770,
    ANIM_FLY_PET_BATTLE_DEAD                 = 771,
    ANIM_PET_BATTLE_FREEZE                   = 772,
    ANIM_FLY_PET_BATTLE_FREEZE               = 773,
    ANIM_MONK_OFFENSE_ATTACK_WEAPON          = 774,
    ANIM_FLY_MONK_OFFENSE_ATTACK_WEAPON      = 775,
    ANIM_BAR_TEND_EMOTE_WAVE                 = 776,
    ANIM_FLY_BAR_TEND_EMOTE_WAVE             = 777,
    ANIM_BAR_SERVER_EMOTE_TALK               = 778,
    ANIM_FLY_BAR_SERVER_EMOTE_TALK           = 779,
    ANIM_BAR_SERVER_EMOTE_WAVE               = 780,
    ANIM_FLY_BAR_SERVER_EMOTE_WAVE           = 781,
    ANIM_BAR_SERVER_POUR_DRINKS              = 782,
    ANIM_FLY_BAR_SERVER_POUR_DRINKS          = 783,
    ANIM_BAR_SERVER_PICKUP                   = 784,
    ANIM_FLY_BAR_SERVER_PICKUP               = 785,
    ANIM_BAR_SERVER_PUT_DOWN                 = 786,
    ANIM_FLY_BAR_SERVER_PUT_DOWN             = 787,
    ANIM_BAR_SWEEP_STAND                     = 788,
    ANIM_FLY_BAR_SWEEP_STAND                 = 789,
    ANIM_BAR_PATRON_SIT                      = 790,
    ANIM_FLY_BAR_PATRON_SIT                  = 791,
    ANIM_BAR_PATRON_SIT_EMOTE_TALK           = 792,
    ANIM_FLY_BAR_PATRON_SIT_EMOTE_TALK       = 793,
    ANIM_BAR_PATRON_STAND                    = 794,
    ANIM_FLY_BAR_PATRON_STAND                = 795,
    ANIM_BAR_PATRON_STAND_EMOTE_TALK         = 796,
    ANIM_FLY_BAR_PATRON_STAND_EMOTE_TALK     = 797,
    ANIM_BAR_PATRON_STAND_EMOTE_POINT        = 798,
    ANIM_FLY_BAR_PATRON_STAND_EMOTE_POINT    = 799,
    ANIM_CARRION_SWARM                       = 800,
    ANIM_FLY_CARRION_SWARM                   = 801,
    ANIM_WHEEL_LOOP                          = 802,
    ANIM_FLY_WHEEL_LOOP                      = 803,
    ANIM_STAND_CHARACTER_CREATE              = 804,
    ANIM_FLY_STAND_CHARACTER_CREATE          = 805,
    ANIM_MOUNT_CHOPPER                       = 806,
    ANIM_FLY_MOUNT_CHOPPER                   = 807,
    ANIM_FACE_POSE                           = 808,
    ANIM_FLY_FACE_POSE                       = 809,
    ANIM_WARRIOR_COLOSSUS_SMASH              = 810,
    ANIM_FLY_WARRIOR_COLOSSUS_SMASH          = 811,
    ANIM_WARRIOR_MORTAL_STRIKE               = 812,
    ANIM_FLY_WARRIOR_MORTAL_STRIKE           = 813,
    ANIM_WARRIOR_WHIRLWIND                   = 814,
    ANIM_FLY_WARRIOR_WHIRLWIND               = 815,
    ANIM_WARRIOR_CHARGE                      = 816,
    ANIM_FLY_WARRIOR_CHARGE                  = 817,
    ANIM_WARRIOR_CHARGE_START                = 818,
    ANIM_FLY_WARRIOR_CHARGE_START            = 819,
    ANIM_WARRIOR_CHARGE_END                  = 820,
    ANIM_FLY_WARRIOR_CHARGE_END              = 821
};

enum LockKeyType
{
    LOCK_KEY_NONE  = 0,
    LOCK_KEY_ITEM  = 1,
    LOCK_KEY_SKILL = 2,
    LOCK_KEY_SPELL = 3,
};

// LockType.dbc (10.0.5.48069)
enum LockType
{
    LOCKTYPE_LOCKPICKING                    = 1,
    LOCKTYPE_HERBALISM                      = 2,
    LOCKTYPE_MINING                         = 3,
    LOCKTYPE_DISARM_TRAP                    = 4,
    LOCKTYPE_OPEN                           = 5,
    LOCKTYPE_TREASURE                       = 6,
    LOCKTYPE_CALCIFIED_ELVEN_GEMS           = 7,
    LOCKTYPE_CLOSE                          = 8,
    LOCKTYPE_ARM_TRAP                       = 9,
    LOCKTYPE_QUICK_OPEN                     = 10,
    LOCKTYPE_QUICK_CLOSE                    = 11,
    LOCKTYPE_OPEN_TINKERING                 = 12,
    LOCKTYPE_OPEN_KNEELING                  = 13,
    LOCKTYPE_OPEN_ATTACKING                 = 14,
    LOCKTYPE_GAHZRIDIAN                     = 15,
    LOCKTYPE_BLASTING                       = 16,
    LOCKTYPE_PVP_OPEN                       = 17,
    LOCKTYPE_PVP_CLOSE                      = 18,
    LOCKTYPE_FISHING                        = 19,
    LOCKTYPE_INSCRIPTION                    = 20,
    LOCKTYPE_OPEN_FROM_VEHICLE              = 21,
    LOCKTYPE_ARCHAEOLOGY                    = 22,
    LOCKTYPE_PVP_OPEN_FAST                  = 23,
    LOCKTYPE_LUMBER_MILL                    = 28,
    LOCKTYPE_SKINNING                       = 29,
    LOCKTYPE_ANCIENT_MANA                   = 30,
    LOCKTYPE_WARBOARD                       = 31,
    LOCKTYPE_CLASSIC_HERBALISM              = 32,
    LOCKTYPE_OUTLAND_HERBALISM              = 33,
    LOCKTYPE_NORTHREND_HERBALISM            = 34,
    LOCKTYPE_CATACLYSM_HERBALISM            = 35,
    LOCKTYPE_PANDARIA_HERBALISM             = 36,
    LOCKTYPE_DRAENOR_HERBALISM              = 37,
    LOCKTYPE_LEGION_HERBALISM               = 38,
    LOCKTYPE_KUL_TIRAN_HERBALISM            = 39,
    LOCKTYPE_CLASSIC_MINING                 = 40,
    LOCKTYPE_OUTLAND_MINING                 = 41,
    LOCKTYPE_NORTHREND_MINING               = 42,
    LOCKTYPE_CATACLYSM_MINING               = 43,
    LOCKTYPE_PANDARIA_MINING                = 44,
    LOCKTYPE_DRAENOR_MINING                 = 45,
    LOCKTYPE_LEGION_MINING                  = 46,
    LOCKTYPE_KUL_TIRAN_MINING               = 47,
    LOCKTYPE_LEGION_SKINNING                = 48,
    LOCKTYPE_OPEN_ITEM                      = 149,
    LOCKTYPE_FORAGING                       = 150,
    LOCKTYPE_JELLY_DEPOSIT                  = 152,
    LOCKTYPE_SHADOWLANDS_HERBALISM          = 153,
    LOCKTYPE_SHADOWLANDS_MINING             = 155,
    LOCKTYPE_COVENANT_NIGHT_FAE             = 157,
    LOCKTYPE_COVENANT_VENTHYR               = 158,
    LOCKTYPE_COVENANT_KYRIAN                = 159,
    LOCKTYPE_COVENANT_NECROLORD             = 160,
    LOCKTYPE_ENGINEERING                    = 161,
    LOCKTYPE_DRAGON_ISLES_HERBALISM         = 162,
    LOCKTYPE_MINING_2                       = 163,
    LOCKTYPE_ELUSIVE_HERBALISM              = 166,
    LOCKTYPE_ELUSIVE_MINING                 = 167,
    LOCKTYPE_ENCHANTING                     = 169,
    LOCKTYPE_DRAGON_ISLES_TREASURE          = 170,
    LOCKTYPE_DRAGON_ISLES_ALCHEMY_25        = 172,
    LOCKTYPE_DRAGON_ISLES_BLACKSMITHING_25  = 173,
    LOCKTYPE_DRAGON_ISLES_ENCHANTING_25     = 174,
    LOCKTYPE_DRAGON_ISLES_ENGINEERING_25    = 175,
    LOCKTYPE_DRAGON_ISLES_HERBALISM_25      = 176,
    LOCKTYPE_DRAGON_ISLES_INSCRIPTION_25    = 177,
    LOCKTYPE_DRAGON_ISLES_JEWELCRAFTING_25  = 178,
    LOCKTYPE_DRAGON_ISLES_LEATHERWORKING_25 = 179,
    LOCKTYPE_DRAGON_ISLES_MINING_25         = 180,
    LOCKTYPE_DRAGON_ISLES_SKINNING_25       = 181,
    LOCKTYPE_DRAGON_ISLES_TAILORING_25      = 182,
    LOCKTYPE_OPEN_KNEELING_PLANT            = 186,
    LOCKTYPE_DRAGON_ISLES_MINING            = 188
};

// this is important type for npcs!
enum TrainerType
{
    TRAINER_TYPE_CLASS             = 0,
};

// CreatureType.dbc (9.0.2.37176)
enum CreatureType
{
    CREATURE_TYPE_BEAST            = 1,
    CREATURE_TYPE_DRAGONKIN        = 2,
    CREATURE_TYPE_DEMON            = 3,
    CREATURE_TYPE_ELEMENTAL        = 4,
    CREATURE_TYPE_GIANT            = 5,
    CREATURE_TYPE_UNDEAD           = 6,
    CREATURE_TYPE_HUMANOID         = 7,
    CREATURE_TYPE_CRITTER          = 8,
    CREATURE_TYPE_MECHANICAL       = 9,
    CREATURE_TYPE_NOT_SPECIFIED    = 10,
    CREATURE_TYPE_TOTEM            = 11,
    CREATURE_TYPE_NON_COMBAT_PET   = 12,
    CREATURE_TYPE_GAS_CLOUD        = 13,
    CREATURE_TYPE_WILD_PET         = 14,
    CREATURE_TYPE_ABERRATION       = 15
};

uint32 const CREATURE_TYPEMASK_DEMON_OR_UNDEAD = (1 << (CREATURE_TYPE_DEMON-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));
uint32 const CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD = (1 << (CREATURE_TYPE_HUMANOID-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));
uint32 const CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL = (1 << (CREATURE_TYPE_MECHANICAL-1)) | (1 << (CREATURE_TYPE_ELEMENTAL-1));

// CreatureFamily.dbc (9.0.2.37176)
enum CreatureFamily
{
    CREATURE_FAMILY_NONE                = 0,
    CREATURE_FAMILY_WOLF                = 1,
    CREATURE_FAMILY_CAT                 = 2,
    CREATURE_FAMILY_SPIDER              = 3,
    CREATURE_FAMILY_BEAR                = 4,
    CREATURE_FAMILY_BOAR                = 5,
    CREATURE_FAMILY_CROCOLISK           = 6,
    CREATURE_FAMILY_CARRION_BIRD        = 7,
    CREATURE_FAMILY_CRAB                = 8,
    CREATURE_FAMILY_GORILLA             = 9,
    CREATURE_FAMILY_RAPTOR              = 11,
    CREATURE_FAMILY_TALLSTRIDER         = 12,
    CREATURE_FAMILY_FELHUNTER           = 15,
    CREATURE_FAMILY_VOIDWALKER          = 16,
    CREATURE_FAMILY_SUCCUBUS            = 17,
    CREATURE_FAMILY_DOOMGUARD           = 19,
    CREATURE_FAMILY_SCORPID             = 20,
    CREATURE_FAMILY_TURTLE              = 21,
    CREATURE_FAMILY_IMP                 = 23,
    CREATURE_FAMILY_BAT                 = 24,
    CREATURE_FAMILY_HYENA               = 25,
    CREATURE_FAMILY_BIRD_OF_PREY        = 26,
    CREATURE_FAMILY_WIND_SERPENT        = 27,
    CREATURE_FAMILY_REMOTE_CONTROL      = 28,
    CREATURE_FAMILY_FELGUARD            = 29,
    CREATURE_FAMILY_DRAGONHAWK          = 30,
    CREATURE_FAMILY_RAVAGER             = 31,
    CREATURE_FAMILY_WARP_STALKER        = 32,
    CREATURE_FAMILY_SPOREBAT            = 33,
    CREATURE_FAMILY_RAY                 = 34,
    CREATURE_FAMILY_SERPENT             = 35,
    CREATURE_FAMILY_MOTH                = 37,
    CREATURE_FAMILY_CHIMAERA            = 38,
    CREATURE_FAMILY_DEVILSAUR           = 39,
    CREATURE_FAMILY_GHOUL               = 40,
    CREATURE_FAMILY_AQIRI               = 41,
    CREATURE_FAMILY_WORM                = 42,
    CREATURE_FAMILY_CLEFTHOOF           = 43,
    CREATURE_FAMILY_WASP                = 44,
    CREATURE_FAMILY_CORE_HOUND          = 45,
    CREATURE_FAMILY_SPIRIT_BEAST        = 46,
    CREATURE_FAMILY_WATER_ELEMENTAL     = 49,
    CREATURE_FAMILY_FOX                 = 50,
    CREATURE_FAMILY_MONKEY              = 51,
    CREATURE_FAMILY_HOUND               = 52,
    CREATURE_FAMILY_BEETLE              = 53,
    CREATURE_FAMILY_SHALE_BEAST         = 55,
    CREATURE_FAMILY_ZOMBIE              = 56,
    CREATURE_FAMILY_QA_TEST             = 57,
    CREATURE_FAMILY_HYDRA               = 68,
    CREATURE_FAMILY_FELIMP              = 100,
    CREATURE_FAMILY_VOIDLORD            = 101,
    CREATURE_FAMILY_SHIVARA             = 102,
    CREATURE_FAMILY_OBSERVER            = 103,
    CREATURE_FAMILY_WRATHGUARD          = 104,
    CREATURE_FAMILY_INFERNAL            = 108,
    CREATURE_FAMILY_FIREELEMENTAL       = 116,
    CREATURE_FAMILY_EARTHELEMENTAL      = 117,
    CREATURE_FAMILY_CRANE               = 125,
    CREATURE_FAMILY_WATERSTRIDER        = 126,
    CREATURE_FAMILY_RODENT              = 127,
    CREATURE_FAMILY_STONE_HOUND         = 128,
    CREATURE_FAMILY_GRUFFHORN           = 129,
    CREATURE_FAMILY_BASILISK            = 130,
    CREATURE_FAMILY_DIREHORN            = 138,
    CREATURE_FAMILY_STORMELEMENTAL      = 145,
    CREATURE_FAMILY_TORRORGUARD         = 147,
    CREATURE_FAMILY_ABYSSAL             = 148,
    CREATURE_FAMILY_RIVERBEAST          = 150,
    CREATURE_FAMILY_STAG                = 151,
    CREATURE_FAMILY_MECHANICAL          = 154,
    CREATURE_FAMILY_ABOMINATION         = 155,
    CREATURE_FAMILY_SCALEHIDE           = 156,
    CREATURE_FAMILY_OXEN                = 157,
    CREATURE_FAMILY_FEATHERMANE         = 160,
    CREATURE_FAMILY_LIZARD              = 288,
    CREATURE_FAMILY_PTERRORDAX          = 290,
    CREATURE_FAMILY_TOAD                = 291,
    CREATURE_FAMILY_CARAPID             = 292,
    CREATURE_FAMILY_BLOOD_BEAST         = 296,
    CREATURE_FAMILY_CAMEL               = 298,
    CREATURE_FAMILY_COURSER             = 299,
    CREATURE_FAMILY_MAMMOTH             = 300,
    CREATURE_FAMILY_INCUBUS             = 302
};

enum CreatureTypeFlags
{
    CREATURE_TYPE_FLAG_TAMEABLE                          = 0x00000001, // Makes the mob tameable (must also be a beast and have family set)
    CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS                 = 0x00000002, // Creature is also visible for not alive player. Allows gossip interaction if npcflag allows?
    CREATURE_TYPE_FLAG_BOSS_MOB                          = 0x00000004, // Changes creature's visible level to "??" in the creature's portrait - Immune Knockback.
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_WOUND_ANIM            = 0x00000008,
    CREATURE_TYPE_FLAG_NO_FACTION_TOOLTIP                = 0x00000010,
    CREATURE_TYPE_FLAG_MORE_AUDIBLE                      = 0x00000020, // Sound related
    CREATURE_TYPE_FLAG_SPELL_ATTACKABLE                  = 0x00000040,
    CREATURE_TYPE_FLAG_INTERACT_WHILE_DEAD               = 0x00000080, // Player can interact with the creature if creature is dead (not if player is dead)
    CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM               = 0x00000100, // Can be looted by herbalist
    CREATURE_TYPE_FLAG_SKIN_WITH_MINING                  = 0x00000200, // Can be looted by miner
    CREATURE_TYPE_FLAG_NO_DEATH_MESSAGE                  = 0x00000400, // Death event will not show up in combat log
    CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT              = 0x00000800, // Creature can remain mounted when entering combat
    CREATURE_TYPE_FLAG_CAN_ASSIST                        = 0x00001000, // ? Can aid any player in combat if in range?
    CREATURE_TYPE_FLAG_NO_PET_BAR                        = 0x00002000,
    CREATURE_TYPE_FLAG_MASK_UID                          = 0x00004000,
    CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING             = 0x00008000, // Can be looted by engineer
    CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC                   = 0x00010000, // Can be tamed by hunter as exotic pet
    CREATURE_TYPE_FLAG_USE_MODEL_COLLISION_SIZE          = 0x00020000, // Collision related. (always using default collision box?)
    CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT = 0x00040000,
    CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES             = 0x00080000, // Projectiles can collide with this creature - interacts with TARGET_DEST_TRAJ
    CREATURE_TYPE_FLAG_NO_NAME_PLATE                     = 0x00100000,
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_MOUNTED_ANIMATIONS    = 0x00200000,
    CREATURE_TYPE_FLAG_LINK_ALL                          = 0x00400000,
    CREATURE_TYPE_FLAG_INTERACT_ONLY_WITH_CREATOR        = 0x00800000,
    CREATURE_TYPE_FLAG_DO_NOT_PLAY_UNIT_EVENT_SOUNDS     = 0x01000000,
    CREATURE_TYPE_FLAG_HAS_NO_SHADOW_BLOB                = 0x02000000,
    CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT                = 0x04000000, //!< Creature can be targeted by spells that require target to be in caster's party/raid
    CREATURE_TYPE_FLAG_FORCE_GOSSIP                      = 0x08000000, // Allows the creature to display a single gossip option.
    CREATURE_TYPE_FLAG_DO_NOT_SHEATHE                    = 0x10000000,
    CREATURE_TYPE_FLAG_DO_NOT_TARGET_ON_INTERACTION      = 0x20000000,
    CREATURE_TYPE_FLAG_DO_NOT_RENDER_OBJECT_NAME         = 0x40000000,
    CREATURE_TYPE_FLAG_QUEST_BOSS                        = 0x80000000  // Not verified
};

enum CreatureTypeFlags2
{
    CREATURE_TYPE_FLAG_2_UNK1 = 0x00000001,
    CREATURE_TYPE_FLAG_2_UNK2 = 0x00000002,
    CREATURE_TYPE_FLAG_2_UNK3 = 0x00000004,
    CREATURE_TYPE_FLAG_2_UNK4 = 0x00000008,
    CREATURE_TYPE_FLAG_2_UNK5 = 0x00000010,
    CREATURE_TYPE_FLAG_2_UNK6 = 0x00000020,
    CREATURE_TYPE_FLAG_2_UNK7 = 0x00000040,
    CREATURE_TYPE_FLAG_2_UNK8 = 0x00000080
};

enum class CreatureClassifications : uint32
{
    Normal                    = 0,
    Elite                     = 1,
    RareElite                 = 2,
    Obsolete                  = 3,
    Rare                      = 4,
    Trivial                   = 5,
    MinusMob                  = 6
};

enum class StringIdType : int32
{
    Template    = 0,
    Spawn       = 1,
    Script      = 2
};

// Holidays.dbc (9.0.2.37176)
enum HolidayIds
{
    HOLIDAY_NONE                                        = 0,

    HOLIDAY_FIREWORKS_SPECTACULAR                       = 62,
    HOLIDAY_FEAST_OF_WINTER_VEIL                        = 141,
    HOLIDAY_NOBLEGARDEN                                 = 181,
    HOLIDAY_CHILDRENS_WEEK                              = 201,
    HOLIDAY_CALL_TO_ARMS_AV_OLD                         = 283,
    HOLIDAY_CALL_TO_ARMS_WG_OLD                         = 284,
    HOLIDAY_CALL_TO_ARMS_AB_OLD                         = 285,
    HOLIDAY_HARVEST_FESTIVAL                            = 321,
    HOLIDAY_HALLOWS_END                                 = 324,
    HOLIDAY_LUNAR_FESTIVAL                              = 327,
    HOLIDAY_LOVE_IS_IN_THE_AIR_OLD                      = 335,
    HOLIDAY_MIDSUMMER_FIRE_FESTIVAL                     = 341,
    HOLIDAY_CALL_TO_ARMS_ES_OLD                         = 353,
    HOLIDAY_BREWFEST                                    = 372,
    HOLIDAY_PIRATES_DAY                                 = 398,
    HOLIDAY_CALL_TO_ARMS_SA_OLD                         = 400,
    HOLIDAY_PILGRIMS_BOUNTY                             = 404,
    HOLIDAY_LK_LAUNCH                                   = 406,
    HOLIDAY_DAY_OF_THE_DEAD                             = 409,
    HOLIDAY_CALL_TO_ARMS_IC_OLD                         = 420,
    HOLIDAY_LOVE_IS_IN_THE_AIR                          = 423,
    HOLIDAY_KALU_AK_FISHING_DERBY                       = 424,
    HOLIDAY_CALL_TO_ARMS_BG                             = 435,
    HOLIDAY_CALL_TO_ARMS_TP                             = 436,
    HOLIDAY_RATED_BG_15_VS_15                           = 442,
    HOLIDAY_RATED_BG_25_VS_25                           = 443,
    HOLIDAY_WOW_7TH_ANNIVERSARY                         = 467,
    HOLIDAY_DARKMOON_FAIRE                              = 479,
    HOLIDAY_WOW_8TH_ANNIVERSARY                         = 484,
    HOLIDAY_CALL_TO_ARMS_SM                             = 488,
    HOLIDAY_CALL_TO_ARMS_TK                             = 489,
    HOLIDAY_CALL_TO_ARMS_AV                             = 490,
    HOLIDAY_CALL_TO_ARMS_AB                             = 491,
    HOLIDAY_CALL_TO_ARMS_ES                             = 492,
    HOLIDAY_CALL_TO_ARMS_IC                             = 493,
    HOLIDAY_CALL_TO_ARMS_SM_OLD                         = 494,
    HOLIDAY_CALL_TO_ARMS_SA                             = 495,
    HOLIDAY_CALL_TO_ARMS_TK_OLD                         = 496,
    HOLIDAY_CALL_TO_ARMS_BG_OLD                         = 497,
    HOLIDAY_CALL_TO_ARMS_TP_OLD                         = 498,
    HOLIDAY_CALL_TO_ARMS_WG                             = 499,
    HOLIDAY_WOW_9TH_ANNIVERSARY                         = 509,
    HOLIDAY_WOW_10TH_ANNIVERSARY                        = 514,
    HOLIDAY_CALL_TO_ARMS_DG                             = 515,
    HOLIDAY_CALL_TO_ARMS_DG_OLD                         = 516,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_BC_DEFAULT        = 559,
    HOLIDAY_APEXIS_BONUS_EVENT_DEFAULT                  = 560,
    HOLIDAY_ARENA_SKIRMISH_BONUS_EVENT                  = 561,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_LK_DEFAULT        = 562,
    HOLIDAY_BATTLEGROUND_BONUS_EVENT_DEFAULT            = 563,
    HOLIDAY_DRAENOR_DUNGEON_EVENT_DEFAULT               = 564,
    HOLIDAY_PET_BATTLE_BONUS_EVENT_DEFAULT              = 565,
    HOLIDAY_WOW_11TH_ANNIVERSARY                        = 566,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_CATA_DEFAULT      = 587,
    HOLIDAY_WOW_12TH_ANNIVERSARY                        = 589,
    HOLIDAY_WOW_ANNIVERSARY                             = 590,
    HOLIDAY_LEGION_DUNGEON_EVENT_DEFAULT                = 591,
    HOLIDAY_WORLD_QUEST_BONUS_EVENT_DEFAULT             = 592,
    HOLIDAY_APEXIS_BONUS_EVENT_EU                       = 593,
    HOLIDAY_APEXIS_BONUS_EVENT_TW_CN                    = 594,
    HOLIDAY_APEXIS_BONUS_EVENT_KR                       = 595,
    HOLIDAY_DRAENOR_DUNGEON_EVENT_EU                    = 596,
    HOLIDAY_DRAENOR_DUNGEON_EVENT_TW_CN                 = 597,
    HOLIDAY_DRAENOR_DUNGEON_EVENT_KR                    = 598,
    HOLIDAY_PET_BATTLE_BONUS_EVENT_EU                   = 599,
    HOLIDAY_PET_BATTLE_BONUS_EVENT_TW_CN                = 600,
    HOLIDAY_PET_BATTLE_BONUS_EVENT_KR                   = 601,
    HOLIDAY_BATTLEGROUND_BONUS_EVENT_EU                 = 602,
    HOLIDAY_BATTLEGROUND_BONUS_EVENT_TW_CN              = 603,
    HOLIDAY_BATTLEGROUND_BONUS_EVENT_KR                 = 604,
    HOLIDAY_LEGION_DUNGEON_EVENT_EU                     = 605,
    HOLIDAY_LEGION_DUNGEON_EVENT_TW_CN                  = 606,
    HOLIDAY_LEGION_DUNGEON_EVENT_KR                     = 607,
    HOLIDAY_ARENA_SKIRMISH_BONUS_EVENT_EU               = 610,
    HOLIDAY_ARENA_SKIRMISH_BONUS_EVENT_TW_CN            = 611,
    HOLIDAY_ARENA_SKIRMISH_BONUS_EVENT_KR               = 612,
    HOLIDAY_WORLD_QUEST_BONUS_EVENT_EU                  = 613,
    HOLIDAY_WORLD_QUEST_BONUS_EVENT_TW_CN               = 614,
    HOLIDAY_WORLD_QUEST_BONUS_EVENT_KR                  = 615,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_LK_EU             = 616,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_LK_TW_CN          = 617,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_LK_KR             = 618,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_BC_EU             = 622,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_BC_TW_CN          = 623,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_BC_KR             = 624,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_CATA_EU           = 628,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_CATA_TW_CN        = 629,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_CATA_KR           = 630,
    HOLIDAY_HATCHING_OF_THE_HIPPOGRYPHS                 = 634,
    HOLIDAY_VOLUNTEER_GUARD_DAY                         = 635,
    HOLIDAY_CALL_OF_THE_SCARAB                          = 638,
    HOLIDAY_THOUSAND_BOAT_BASH                          = 642,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_MOP_DEFAULT       = 643,
    HOLIDAY_UNGORO_MADNESS                              = 644,
    HOLIDAY_SPRING_BALLOON_FESTIVAL                     = 645,
    HOLIDAY_KIRIN_TOR_TAVERN_CRAWL                      = 646,
    HOLIDAY_MARCH_OF_THE_TADPOLES                       = 647,
    HOLIDAY_GLOWCAP_FESTIVAL                            = 648,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_MOP_EU            = 652,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_MOP_TW_CN         = 654,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_MOP_KR            = 656,
    HOLIDAY_FIREWORKS_CELEBRATION                       = 658,
    HOLIDAY_PVP_BRAWL_GL_1984                           = 659,
    HOLIDAY_PVP_BRAWL_SS_VS_TM_1984                     = 660,
    HOLIDAY_PVP_BRAWL_SS_VS_TM_US                       = 662,
    HOLIDAY_PVP_BRAWL_GL_US                             = 663,
    HOLIDAY_PVP_BRAWL_WS_US                             = 664,
    HOLIDAY_PVP_BRAWL_AB_US                             = 666,
    HOLIDAY_PVP_BRAWL_PH_US                             = 667,
    HOLIDAY_PVP_BRAWL_SS_VS_TM_EU                       = 669,
    HOLIDAY_PVP_BRAWL_GL_EU                             = 670,
    HOLIDAY_PVP_BRAWL_WS_EU                             = 671,
    HOLIDAY_PVP_BRAWL_AB_EU                             = 673,
    HOLIDAY_PVP_BRAWL_PH_EU                             = 674,
    HOLIDAY_PVP_BRAWL_SS_VS_TM_TW_CN                    = 676,
    HOLIDAY_PVP_BRAWL_GL_TW_CN                          = 677,
    HOLIDAY_PVP_BRAWL_WS_TW_CN                          = 678,
    HOLIDAY_PVP_BRAWL_AB_TW_CN                          = 680,
    HOLIDAY_PVP_BRAWL_PH_TW_CN                          = 681,
    HOLIDAY_PVP_BRAWL_SS_VS_TM_KR                       = 683,
    HOLIDAY_PVP_BRAWL_GL_KR                             = 684,
    HOLIDAY_PVP_BRAWL_WS_KR                             = 685,
    HOLIDAY_PVP_BRAWL_AB_KR                             = 687,
    HOLIDAY_PVP_BRAWL_PH_KR                             = 688,
    HOLIDAY_TRIAL_OF_STYLE                              = 691,
    HOLIDAY_AUCTION_HOUSE_DANCE_PARTY                   = 692,
    HOLIDAY_WOW_13TH_ANNIVERSARY                        = 693,
    HOLIDAY_MOOKIN_FESTIVAL                             = 694,
    HOLIDAY_THE_GREAT_GNOMEREGAN_RUN                    = 696,
    HOLIDAY_PVP_BRAWL_WS_1984                           = 701,
    HOLIDAY_PVP_BRAWL_DS_US                             = 702,
    HOLIDAY_PVP_BRAWL_DS_EU                             = 704,
    HOLIDAY_PVP_BRAWL_DS_TW_CN                          = 705,
    HOLIDAY_PVP_BRAWL_DS_KR                             = 706,
    HOLIDAY_TOMB_OF_SARGERAS_NORMAL_HEROIC_DEFAULT      = 710,    // Tomb of Sargeras: Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_NORMAL_HEROIC_EU           = 711,    // Tomb of Sargeras: Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_NORMAL_HEROIC_TW_CN        = 712,    // Tomb of Sargeras: Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_NORMAL_HEROIC_KR           = 713,    // Tomb of Sargeras: Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_RF_1_SECTION_DEFAULT       = 714,    // Tomb of Sargeras: The Gates of Hell.
    HOLIDAY_TOMB_OF_SARGERAS_RF_1_SECTION_EU            = 715,    // Tomb of Sargeras: The Gates of Hell.
    HOLIDAY_TOMB_OF_SARGERAS_RF_1_SECTION_TW_CN         = 716,    // Tomb of Sargeras: The Gates of Hell.
    HOLIDAY_TOMB_OF_SARGERAS_RF_1_SECTION_KR            = 717,    // Tomb of Sargeras: The Gates of Hell.
    HOLIDAY_TOMB_OF_SARGERAS_RF_2_SECTION_DEFAULT       = 718,    // Tomb of Sargeras: Wailing Halls.
    HOLIDAY_TOMB_OF_SARGERAS_RF_2_SECTION_EU            = 719,    // Tomb of Sargeras: Wailing Halls.
    HOLIDAY_TOMB_OF_SARGERAS_RF_2_SECTION_TW_CN         = 720,    // Tomb of Sargeras: Wailing Halls.
    HOLIDAY_TOMB_OF_SARGERAS_RF_2_SECTION_KR            = 721,    // Tomb of Sargeras: Wailing Halls.
    HOLIDAY_TOMB_OF_SARGERAS_RF_3_SECTION_DEFAULT       = 722,    // Tomb of Sargeras: Chamber of the Avatar.
    HOLIDAY_TOMB_OF_SARGERAS_RF_3_SECTION_EU            = 723,    // Tomb of Sargeras: Chamber of the Avatar.
    HOLIDAY_TOMB_OF_SARGERAS_RF_3_SECTION_TW_CN         = 724,    // Tomb of Sargeras: Chamber of the Avatar.
    HOLIDAY_TOMB_OF_SARGERAS_RF_3_SECTION_KR            = 725,    // Tomb of Sargeras: Chamber of the Avatar.
    HOLIDAY_TOMB_OF_SARGERAS_FINAL_ENCOUNTER_DEFAULT    = 726,    // Tomb of Sargeras: Deceiver's Fall. Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_FINAL_ENCOUNTER_EU         = 727,    // Tomb of Sargeras: Deceiver's Fall. Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_FINAL_ENCOUNTER_TW_CN      = 728,    // Tomb of Sargeras: Deceiver's Fall. Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_FINAL_ENCOUNTER_KR         = 729,    // Tomb of Sargeras: Deceiver's Fall. Kil'jaeden awaits!
    HOLIDAY_TOMB_OF_SARGERAS_NORMAL_HEROIC_768          = 730,    // Tomb of Sargeras: Kil'jaeden awaits!
    HOLIDAY_PVP_BRAWL_DS_1984                           = 736,
    HOLIDAY_PVP_BRAWL_AB_1984                           = 737,
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_2_UNLOCKS_DEFAULT = 744,    // In part 2 of Shadows of Argus, finish the story of Krokuun and travel to the ruined draenei city of Mac'Aree. Gain access to Invasion Points and thwart the Burning Legion's plans on other worlds. Additional World Quests become available.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_3_UNLOCKS_DEFAULT = 745,    // In part 3 of Shadows of Argus, finish the Shadows of Argus storyline, unlock all World Quests, and venture into the new dungeon, the Seat of the Triumvirate. Activate your Netherlight Crucible on the Vindicaar to begin forging Relics.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_2_UNLOCKS_KR      = 746,    // In part 2 of Shadows of Argus, finish the story of Krokuun and travel to the ruined draenei city of Mac'Aree. Gain access to Invasion Points and thwart the Burning Legion's plans on other worlds. Additional World Quests become available.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_2_UNLOCKS_EU      = 747,    // In part 2 of Shadows of Argus, finish the story of Krokuun and travel to the ruined draenei city of Mac'Aree. Gain access to Invasion Points and thwart the Burning Legion's plans on other worlds. Additional World Quests become available.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_2_UNLOCKS_TW_CN   = 748,    // In part 2 of Shadows of Argus, finish the story of Krokuun and travel to the ruined draenei city of Mac'Aree. Gain access to Invasion Points and thwart the Burning Legion's plans on other worlds. Additional World Quests become available.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_3_UNLOCKS_TW_CN   = 749,    // In part 3 of Shadows of Argus, finish the Shadows of Argus storyline, unlock all World Quests, and venture into the new dungeon, the Seat of the Triumvirate. Activate your Netherlight Crucible on the Vindicaar to begin forging Relics.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_3_UNLOCKS_KR      = 750,    // In part 3 of Shadows of Argus, finish the Shadows of Argus storyline, unlock all World Quests, and venture into the new dungeon, the Seat of the Triumvirate. Activate your Netherlight Crucible on the Vindicaar to begin forging Relics.
    HOLIDAY_7_3_SHADOWS_OF_ARGUS_WEEK_3_UNLOCKS_EU      = 751,    // In part 3 of Shadows of Argus, finish the Shadows of Argus storyline, unlock all World Quests, and venture into the new dungeon, the Seat of the Triumvirate. Activate your Netherlight Crucible on the Vindicaar to begin forging Relics.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_2_SECTION_TW_CN   = 756,    // Antorus, the Burning Throne: Forbidden Descent.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_2_SECTION_EU      = 757,    // Antorus, the Burning Throne: Forbidden Descent.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_2_SECTION_KR      = 758,    // Antorus, the Burning Throne: Forbidden Descent.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_2_SECTION_DEFAULT = 759,    // Antorus, the Burning Throne: Forbidden Descent.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_3_SECTION_TW_CN   = 760,    // Antorus, the Burning Throne: Hope's End.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_3_SECTION_EU      = 761,    // Antorus, the Burning Throne: Hope's End.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_3_SECTION_KR      = 762,    // Antorus, the Burning Throne: Hope's End.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_3_SECTION_DEFAULT = 763,    // Antorus, the Burning Throne: Hope's End.
    HOLIDAY_ANTORUS_BURNING_THRONE_FINAL_SECTION_TW_CN  = 764,    // Antorus, the Burning Throne: Seat of the Pantheon.
    HOLIDAY_ANTORUS_BURNING_THRONE_FINAL_SECTION_EU     = 765,    // Antorus, the Burning Throne: Seat of the Pantheon.
    HOLIDAY_ANTORUS_BURNING_THRONE_FINAL_SECTION_KR     = 766,    // Antorus, the Burning Throne: Seat of the Pantheon.
    HOLIDAY_ANTORUS_BURNING_THRONE_FINAL_SECTION_DEFAULT= 767,    // Antorus, the Burning Throne: Seat of the Pantheon.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_1_SECTION_TW_CN   = 768,    // Antorus, the Burning Throne: Light's Breach.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_1_SECTION_EU      = 769,    // Antorus, the Burning Throne: Light's Breach.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_1_SECTION_KR      = 770,    // Antorus, the Burning Throne: Light's Breach.
    HOLIDAY_ANTORUS_BURNING_THRONE_RF_1_SECTION_DEFAULT = 771,    // Antorus, the Burning Throne: Light's Breach.
    HOLIDAY_ANTORUS_BURNING_THRONE_NORMAL_HEROIC_TW_CN  = 772,    // Antorus, the Burning Throne: Argus awaits!
    HOLIDAY_ANTORUS_BURNING_THRONE_NORMAL_HEROIC_EU     = 773,    // Antorus, the Burning Throne: Argus awaits!
    HOLIDAY_ANTORUS_BURNING_THRONE_NORMAL_HEROIC_KR     = 774,    // Antorus, the Burning Throne: Argus awaits!
    HOLIDAY_ANTORUS_BURNING_THRONE_NORMAL_HEROIC_DEFAULT= 775,    // Antorus, the Burning Throne: Argus awaits!
    HOLIDAY_ANTORUS_BURNING_THRONE_NORMAL_HEROIC_768    = 776,    // Antorus, the Burning Throne: Argus awaits!
    HOLIDAY_WOW_14TH_ANNIVERSARY                        = 807,
    HOLIDAY_WOW_15TH_ANNIVERSARY                        = 808,
    HOLIDAY_WAR_OF_THE_THORNS                           = 918,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_ULDIR_NORMAL_HEROIC_768                     = 920,    // Uldir: G'huun awaits!
    HOLIDAY_ULDIR_NORMAL_HEROIC_DEFAULT                 = 921,    // Uldir: G'huun awaits!
    HOLIDAY_ULDIR_NORMAL_HEROIC_KR                      = 922,    // Uldir: G'huun awaits!
    HOLIDAY_ULDIR_NORMAL_HEROIC_EU                      = 923,    // Uldir: G'huun awaits!
    HOLIDAY_ULDIR_NORMAL_HEROIC_TW_CN                   = 924,    // Uldir: G'huun awaits!
    HOLIDAY_ULDIR_RF_1_SECTION_DEFAULT                  = 925,    // Uldir: Halls of Containment.
    HOLIDAY_ULDIR_RF_1_SECTION_KR                       = 926,    // Uldir: Halls of Containment.
    HOLIDAY_ULDIR_RF_1_SECTION_EU                       = 927,    // Uldir: Halls of Containment.
    HOLIDAY_ULDIR_RF_1_SECTION_TW_CN                    = 928,    // Uldir: Halls of Containment.
    HOLIDAY_ULDIR_RF_2_SECTION_DEFAULT                  = 929,    // Uldir: Crimson Descent.
    HOLIDAY_ULDIR_RF_2_SECTION_KR                       = 930,    // Uldir: Crimson Descent.
    HOLIDAY_ULDIR_RF_2_SECTION_EU                       = 931,    // Uldir: Crimson Descent.
    HOLIDAY_ULDIR_RF_2_SECTION_TW_CN                    = 932,    // Uldir: Crimson Descent.
    HOLIDAY_ULDIR_FINAL_SECTION_DEFAULT                 = 933,    // Uldir: Heart of Corruption.
    HOLIDAY_ULDIR_FINAL_SECTION_KR                      = 934,    // Uldir: Heart of Corruption.
    HOLIDAY_ULDIR_FINAL_SECTION_EU                      = 935,    // Uldir: Heart of Corruption.
    HOLIDAY_ULDIR_FINAL_SECTION_TW_CN                   = 936,    // Uldir: Heart of Corruption.
    HOLIDAY_BATTLE_FOR_AZEROTH_DUNGEON_EVENT_EU         = 938,
    HOLIDAY_BATTLE_FOR_AZEROTH_DUNGEON_EVENT_TW_CN      = 939,
    HOLIDAY_BATTLE_FOR_AZEROTH_DUNGEON_EVENT_KR         = 940,
    HOLIDAY_BATTLE_FOR_AZEROTH_DUNGEON_EVENT_DEFAULT    = 941,
    HOLIDAY_WAR_OF_THE_THORNS_EU                        = 956,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_TW_CN                     = 957,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_KR                        = 958,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_320                       = 959,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_US                        = 965,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_512                       = 967,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_WAR_OF_THE_THORNS_128                       = 973,    // Conflict emerges in Darkshore as the Horde and Alliance battle for control over Teldrassil in this limited time event!
    HOLIDAY_ULDIR_NORMAL_HEROIC                         = 979,    // Uldir: G'huun awaits!
    HOLIDAY_BATTLE_OF_DAZARALOR_NORMAL_HEROIC_DEFAULT   = 1025,    // Battle of Dazar'alor raid
    HOLIDAY_BATTLE_OF_DAZARALOR_NORMAL_HEROIC_KR        = 1026,    // Battle of Dazar'alor raid
    HOLIDAY_BATTLE_OF_DAZARALOR_NORMAL_HEROIC_EU        = 1027,    // Battle of Dazar'alor raid
    HOLIDAY_BATTLE_OF_DAZARALOR_NORMAL_HEROIC_TW_CN     = 1028,    // Battle of Dazar'alor raid
    HOLIDAY_BATTLE_OF_DAZARALOR_NORMAL_HEROIC_768       = 1029,    // Battle of Dazar'alor raid
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_1_SECTION_DEFAULT    = 1030,    // Battle of Dazar'alor: Siege of Dazar'alor.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_1_SECTION_KR         = 1031,    // Battle of Dazar'alor: Siege of Dazar'alor.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_1_SECTION_EU         = 1032,    // Battle of Dazar'alor: Siege of Dazar'alor.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_1_SECTION_TW_CN      = 1033,    // Battle of Dazar'alor: Siege of Dazar'alor.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_2_SECTION_DEFAULT    = 1034,    // Battle of Dazar'alor: Empire's Fall.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_2_SECTION_KR         = 1035,    // Battle of Dazar'alor: Empire's Fall.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_2_SECTION_EU         = 1036,    // Battle of Dazar'alor: Empire's Fall.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_2_SECTION_TW_CN      = 1037,    // Battle of Dazar'alor: Empire's Fall.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_3_SECTION_DEFAULT    = 1038,    // Battle of Dazar'alor: Might of the Alliance for Alliance players, and Victory or Death for Horde players.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_3_SECTION_KR         = 1039,    // Battle of Dazar'alor: Might of the Alliance for Alliance players, and Victory or Death for Horde players.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_3_SECTION_EU         = 1040,    // Battle of Dazar'alor: Might of the Alliance for Alliance players, and Victory or Death for Horde players.
    HOLIDAY_BATTLE_OF_DAZARALOR_RF_3_SECTION_TW_CN      = 1041,    // Battle of Dazar'alor: Might of the Alliance for Alliance players, and Victory or Death for Horde players.
    HOLIDAY_PVP_BRAWL_COOKING_IMPOSSIBLE_US             = 1047,
    HOLIDAY_PVP_BRAWL_COOKING_IMPOSSIBLE_KR             = 1048,
    HOLIDAY_PVP_BRAWL_COOKING_IMPOSSIBLE_EU             = 1049,
    HOLIDAY_PVP_BRAWL_COOKING_IMPOSSIBLE_1984           = 1050,
    HOLIDAY_PVP_BRAWL_COOKING_IMPOSSIBLE_TW_CN          = 1051,
    HOLIDAY_WANDERERS_FESTIVAL                          = 1052,
    HOLIDAY_FREE_TSHIRT_DAY                             = 1053,
    HOLIDAY_LUMINOUS_LUMINARIES                         = 1054,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_WOD_DEFAULT       = 1056,
    HOLIDAY_LUMINOUS_LUMINARIES_64                      = 1062,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_WOD_EU            = 1063,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_WOD_KR            = 1065,
    HOLIDAY_TIMEWALKING_DUNGEON_EVENT_WOD_TW_CN         = 1068,
    HOLIDAY_CRUCIBLE_OF_STORMS_NORMAL_HEROIC_DEFAULT    = 1069,    // Delve into the chambers beneath Stormsong Valley to uncover the source of the shadow spreading across the land, now available on Normal or Heroic difficulty.
    HOLIDAY_CRUCIBLE_OF_STORMS_NORMAL_HEROIC_KR         = 1070,    // Delve into the chambers beneath Stormsong Valley to uncover the source of the shadow spreading across the land, now available on Normal or Heroic difficulty.
    HOLIDAY_CRUCIBLE_OF_STORMS_NORMAL_HEROIC_EU         = 1071,    // Delve into the chambers beneath Stormsong Valley to uncover the source of the shadow spreading across the land, now available on Normal or Heroic difficulty.
    HOLIDAY_CRUCIBLE_OF_STORMS_NORMAL_HEROIC_TW_CN      = 1072,    // Delve into the chambers beneath Stormsong Valley to uncover the source of the shadow spreading across the land, now available on Normal or Heroic difficulty.
    HOLIDAY_CRUCIBLE_OF_STORMS_NORMAL_HEROIC            = 1073,    // Delve into the chambers beneath Stormsong Valley to uncover the source of the shadow spreading across the land, now available on Normal or Heroic difficulty.
    HOLIDAY_CRUCIBLE_OF_STORMS_RAID_FINDER_DEFAULT      = 1074,    // Mythic difficulty of the Crucible of Storms raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_CRUCIBLE_OF_STORMS_RAID_FINDER_EU           = 1075,    // Mythic difficulty of the Crucible of Storms raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_CRUCIBLE_OF_STORMS_RAID_FINDER_KR           = 1076,    // Mythic difficulty of the Crucible of Storms raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_CRUCIBLE_OF_STORMS_RAID_FINDER_TW_CN        = 1077,    // Mythic difficulty of the Crucible of Storms raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_CRUCIBLE_OF_STORMS_RAID_FINDER              = 1078,    // Mythic difficulty of the Crucible of Storms raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_THE_ETERNAL_PALACE_DEFAULT                  = 1098,    // The dangers of Nazjatar were merely preamble. Breach the palace gates and descend into Azshara's deadly domain.
    HOLIDAY_THE_ETERNAL_PALACE_KR                       = 1099,    // The dangers of Nazjatar were merely preamble. Breach the palace gates and descend into Azshara's deadly domain.
    HOLIDAY_THE_ETERNAL_PALACE_EU                       = 1100,    // The dangers of Nazjatar were merely preamble. Breach the palace gates and descend into Azshara's deadly domain.
    HOLIDAY_THE_ETERNAL_PALACE_TW_CN                    = 1101,    // The dangers of Nazjatar were merely preamble. Breach the palace gates and descend into Azshara's deadly domain.
    HOLIDAY_THE_ETERNAL_PALACE_RAID_FINDER_DEFAULT      = 1102,    // Mythic difficulty of The Eternal Palace raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_THE_ETERNAL_PALACE_RAID_FINDER_KR           = 1103,    // Mythic difficulty of The Eternal Palace raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_THE_ETERNAL_PALACE_RAID_FINDER_EU           = 1104,    // Mythic difficulty of The Eternal Palace raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_THE_ETERNAL_PALACE_RAID_FINDER_TW_CN        = 1105,    // Mythic difficulty of The Eternal Palace raid awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_THE_ETERNAL_PALACE_RF_2_SECTION_EU          = 1106,    // The Eternal Palace: Depths of the Devoted.
    HOLIDAY_THE_ETERNAL_PALACE_RF_2_SECTION_TW_CN       = 1107,    // The Eternal Palace: Depths of the Devoted.
    HOLIDAY_THE_ETERNAL_PALACE_FINAL_SECTION_DEFAULT    = 1108,    // The Eternal Palace: The Circle of Stars.
    HOLIDAY_THE_ETERNAL_PALACE_FINAL_SECTION_KR         = 1109,    // The Eternal Palace: The Circle of Stars.
    HOLIDAY_THE_ETERNAL_PALACE_FINAL_SECTION_EU         = 1110,    // The Eternal Palace: The Circle of Stars.
    HOLIDAY_THE_ETERNAL_PALACE_FINAL_SECTION_TW_CN      = 1111,    // The Eternal Palace: The Circle of Stars.
    HOLIDAY_THE_ETERNAL_PALACE_RF_2_SECTION_KR          = 1112,    // The Eternal Palace: Depths of the Devoted.
    HOLIDAY_THE_ETERNAL_PALACE_RF_2_SECTION_DEFAULT     = 1113,    // The Eternal Palace: Depths of the Devoted.
    HOLIDAY_PVP_BRAWL_CLASSIC_ASHRAN_US                 = 1120,
    HOLIDAY_PVP_BRAWL_CLASSIC_ASHRAN_KR                 = 1121,
    HOLIDAY_PVP_BRAWL_CLASSIC_ASHRAN_EU                 = 1122,
    HOLIDAY_PVP_BRAWL_CLASSIC_ASHRAN_1984               = 1123,
    HOLIDAY_PVP_BRAWL_CLASSIC_ASHRAN_TW_CN              = 1124,
    HOLIDAY_NYALOTHA_WALKING_CITY_DEFAULT               = 1140,    // Descend into Ny'alotha, the Waking City and face N'Zoth in his own realm.
    HOLIDAY_NYALOTHA_WALKING_CITY_KR                    = 1141,    // Descend into Ny'alotha, the Waking City and face N'Zoth in his own realm.
    HOLIDAY_NYALOTHA_WALKING_CITY_EU                    = 1142,    // Descend into Ny'alotha, the Waking City and face N'Zoth in his own realm.
    HOLIDAY_NYALOTHA_WALKING_CITY_TW_CN                 = 1143,    // Descend into Ny'alotha, the Waking City and face N'Zoth in his own realm.
    HOLIDAY_NYALOTHA_WALKING_CITY_RAID_FINDER_DEFAULT   = 1144,    // Mythic difficulty of Ny'alotha, the Waking City awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_NYALOTHA_WALKING_CITY_RAID_FINDER_KR        = 1145,    // Mythic difficulty of Ny'alotha, the Waking City awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_NYALOTHA_WALKING_CITY_RAID_FINDER_EU        = 1146,    // Mythic difficulty of Ny'alotha, the Waking City awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_NYALOTHA_WALKING_CITY_RAID_FINDER_TW_CN     = 1147,    // Mythic difficulty of Ny'alotha, the Waking City awaits the boldest of adventurers, and players may now use the Raid Finder to access the raid.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_2_SECTION_DEFAULT  = 1148,    // Ny'alotha, the Waking City: Halls of Devotion.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_2_SECTION_KR       = 1149,    // Ny'alotha, the Waking City: Halls of Devotion.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_2_SECTION_EU       = 1150,    // Ny'alotha, the Waking City: Halls of Devotion.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_2_SECTION_TW_CN    = 1151,    // Ny'alotha, the Waking City: Halls of Devotion.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_3_SECTION_DEFAULT  = 1152,    // Ny'alotha, the Waking City: Gift of Flesh.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_3_SECTION_KR       = 1153,    // Ny'alotha, the Waking City: Gift of Flesh.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_3_SECTION_EU       = 1154,    // Ny'alotha, the Waking City: Gift of Flesh.
    HOLIDAY_NYALOTHA_WALKING_CITY_RF_3_SECTION_TW_CN    = 1155,    // Ny'alotha, the Waking City: Gift of Flesh.
    HOLIDAY_NYALOTHA_WALKING_CITY_FINAL_SECTION_DEFAULT = 1156,    // Ny'alotha, the Waking City: The Waking Dream.
    HOLIDAY_NYALOTHA_WALKING_CITY_FINAL_SECTION_KR      = 1157,    // Ny'alotha, the Waking City: The Waking Dream.
    HOLIDAY_NYALOTHA_WALKING_CITY_FINAL_SECTION_EU      = 1158,    // Ny'alotha, the Waking City: The Waking Dream.
    HOLIDAY_NYALOTHA_WALKING_CITY_FINAL_SECTION_TW_CN   = 1159,    // Ny'alotha, the Waking City: The Waking Dream.
    HOLIDAY_PVP_BRAWL_TH_1984                           = 1166,
    HOLIDAY_PVP_BRAWL_TH_KR                             = 1167,
    HOLIDAY_PVP_BRAWL_TH_TW_CN                          = 1168,
    HOLIDAY_PVP_BRAWL_TH_EU                             = 1169,
    HOLIDAY_PVP_BRAWL_TH_US                             = 1170,
    HOLIDAY_WOW_16TH_ANNIVERSARY                        = 1181,
    HOLIDAY_CASTLE_NATHRIA_DEFAULT                      = 1194,    // Enter Castle Nathria and confront Sire Denathrius in his citadel.
    HOLIDAY_CASTLE_NATHRIA_RF_1_SECTION_DEFAULT         = 1195,    // Castle Nathria: The Leeching Vaults.
    HOLIDAY_CASTLE_NATHRIA_RF_2_SECTION_DEFAULT         = 1196,    // Castle Nathria: Reliquary of Opulence.
    HOLIDAY_CASTLE_NATHRIA_RF_3_SECTION_DEFAULT         = 1197,    // Castle Nathria: Blood from Stone.
    HOLIDAY_CASTLE_NATHRIA_EU                           = 1198,    // Enter Castle Nathria and confront Sire Denathrius in his citadel.
    HOLIDAY_CASTLE_NATHRIA_RF_1_SECTION_EU              = 1199,    // Castle Nathria: The Leeching Vaults.
    HOLIDAY_CASTLE_NATHRIA_RF_2_SECTION_EU              = 1200,    // Castle Nathria: Reliquary of Opulence.
    HOLIDAY_CASTLE_NATHRIA_RF_3_SECTION_EU              = 1201,    // Castle Nathria: Blood from Stone.
    HOLIDAY_CASTLE_NATHRIA_KR                           = 1202,    // Enter Castle Nathria and confront Sire Denathrius in his citadel.
    HOLIDAY_CASTLE_NATHRIA_RF_1_SECTION_KR              = 1203,    // Castle Nathria: The Leeching Vaults.
    HOLIDAY_CASTLE_NATHRIA_RF_2_SECTION_KR              = 1204,    // Castle Nathria: Reliquary of Opulence.
    HOLIDAY_CASTLE_NATHRIA_RF_3_SECTION_KR              = 1205,    // Castle Nathria: Blood from Stone.
    HOLIDAY_CASTLE_NATHRIA_TW_CN                        = 1206,    // Enter Castle Nathria and confront Sire Denathrius in his citadel.
    HOLIDAY_CASTLE_NATHRIA_RF_1_SECTION_TW_CN           = 1207,    // Castle Nathria: The Leeching Vaults.
    HOLIDAY_CASTLE_NATHRIA_RF_2_SECTION_TW_CN           = 1208,    // Castle Nathria: Reliquary of Opulence.
    HOLIDAY_CASTLE_NATHRIA_RF_3_SECTION_TW_CN           = 1209,    // Castle Nathria: Blood from Stone.
    HOLIDAY_CASTLE_NATHRIA_FINAL_SECTION_DEFAULT        = 1210,    // Castle Nathria: An Audience with Arrogance.
    HOLIDAY_CASTLE_NATHRIA_FINAL_SECTION_EU             = 1211,    // Castle Nathria: An Audience with Arrogance.
    HOLIDAY_CASTLE_NATHRIA_FINAL_SECTION_KR             = 1212,    // Castle Nathria: An Audience with Arrogance.
    HOLIDAY_CASTLE_NATHRIA_FINAL_SECTION_TW_CN          = 1213,    // Castle Nathria: An Audience with Arrogance.
    HOLIDAY_TORGHAST_BEASTS_OF_PRODIGUM                 = 1214,
    HOLIDAY_TORGHAST_UNBRIDLED_DARKNESS                 = 1215,
    HOLIDAY_TORGHAST_CHORUS_OF_DEAD_SOULS               = 1216,
    HOLIDAY_SHADOWLANDS_DUNGEON_EVENT_DEFAULT           = 1217,
    HOLIDAY_SHADOWLANDS_DUNGEON_EVENT_EU                = 1218,
    HOLIDAY_SHADOWLANDS_DUNGEON_EVENT_TW_CN             = 1219,
    HOLIDAY_SHADOWLANDS_DUNGEON_EVENT_KR                = 1220,
    HOLIDAY_PVP_BRAWL_WS_1984_2                         = 1221,
    HOLIDAY_CASTLE_NATHRIA_32                           = 1222    // Enter Castle Nathria and confront Sire Denathrius in his citadel.
};

enum QuestType
{
    QUEST_TYPE_TURNIN               = 0,
    QUEST_TYPE_WITH_MAX_LEVEL       = 1,
    QUEST_TYPE_NORMAL               = 2,
    QUEST_TYPE_TASK                 = 3,
    MAX_DB_ALLOWED_QUEST_TYPES      = 4,

    // values used in quest menu packets
    QUEST_TYPE_IN_PROGRESS          = 4,
    QUEST_TYPE_TASK_IN_PROGRESS     = 5
};

// QuestInfo.dbc (9.0.2.37176)
enum QuestInfo
{
    QUEST_INFO_GROUP                                = 1,
    QUEST_INFO_CLASS                                = 21,
    QUEST_INFO_PVP                                  = 41,
    QUEST_INFO_RAID                                 = 62,
    QUEST_INFO_DUNGEON                              = 81,
    QUEST_INFO_WORLD_EVENT                          = 82,
    QUEST_INFO_LEGENDARY                            = 83,
    QUEST_INFO_ESCORT                               = 84,
    QUEST_INFO_HEROIC                               = 85,
    QUEST_INFO_RAID_10                              = 88,
    QUEST_INFO_RAID_25                              = 89,
    QUEST_INFO_SCENARIO                             = 98,
    QUEST_INFO_ACCOUNT                              = 102,
    QUEST_INFO_SIDE_QUEST                           = 104,
    QUEST_INFO_ARTIFACT                             = 107,
    QUEST_INFO_WORLD_QUEST                          = 109,
    QUEST_INFO_EPIC_WORLD_QUEST                     = 110,
    QUEST_INFO_ELITE_WORLD_QUEST                    = 111,
    QUEST_INFO_EPIC_ELITE_WORLD_QUEST               = 112,
    QUEST_INFO_PVP_WORLD_QUEST                      = 113,
    QUEST_INFO_FIRST_AID_WORLD_QUEST                = 114,
    QUEST_INFO_BATTLE_PET_WORLD_QUEST               = 115,
    QUEST_INFO_BLACKSMITHING_WORLD_QUEST            = 116,
    QUEST_INFO_LEATHERWORKING_WORLD_QUEST           = 117,
    QUEST_INFO_ALCHEMY_WORLD_QUEST                  = 118,
    QUEST_INFO_HERBALISM_WORLD_QUEST                = 119,
    QUEST_INFO_MINING_WORLD_QUEST                   = 120,
    QUEST_INFO_TAILORING_WORLD_QUEST                = 121,
    QUEST_INFO_ENGINEERING_WORLD_QUEST              = 122,
    QUEST_INFO_ENCHANTING_WORLD_QUEST               = 123,
    QUEST_INFO_SKINNING_WORLD_QUEST                 = 124,
    QUEST_INFO_JEWELCRAFTING_WORLD_QUEST            = 125,
    QUEST_INFO_INSCRIPTION_WORLD_QUEST              = 126,
    QUEST_INFO_EMISSARY_QUEST                       = 128,
    QUEST_INFO_ARCHEOLOGY_WORLD_QUEST               = 129,
    QUEST_INFO_FISHING_WORLD_QUEST                  = 130,
    QUEST_INFO_COOKING_WORLD_QUEST                  = 131,
    QUEST_INFO_RARE_WORLD_QUEST                     = 135,
    QUEST_INFO_RARE_ELITE_WORLD_QUEST               = 136,
    QUEST_INFO_DUNGEON_WORLD_QUEST                  = 137,
    QUEST_INFO_LEGION_INVASION_WORLD_QUEST          = 139,
    QUEST_INFO_RATED_REWARD                         = 140,
    QUEST_INFO_RAID_WORLD_QUEST                     = 141,
    QUEST_INFO_LEGION_INVASION_ELITE_WORLD_QUEST    = 142,
    QUEST_INFO_LEGIONFALL_CONTRIBUTION              = 143,
    QUEST_INFO_LEGIONFALL_WORLD_QUEST               = 144,
    QUEST_INFO_LEGIONFALL_DUNGEON_WORLD_QUEST       = 145,
    QUEST_INFO_LEGION_INVASION_WORLD_QUEST_WRAPPER  = 146,
    QUEST_INFO_WARFRONT_BARRENS                     = 147,
    QUEST_INFO_PICKPOCKETING                        = 148,
    QUEST_INFO_MAGNI_WORLD_QUEST_AZERITE            = 151,
    QUEST_INFO_TORTOLLAN_WORLD_QUEST                = 152,
    QUEST_INFO_WARFRONT_CONTRIBUTION                = 153,
    QUEST_INFO_ISLAND_QUEST                         = 254,
    QUEST_INFO_WAR_MODE                             = 255,
    QUEST_INFO_PVP_CONQUEST                         = 256,
    QUEST_INFO_FACTION_ASSAULT_WORLD_QUEST          = 259,
    QUEST_INFO_FACTION_ASSAULT_ELITE_WORLD_QUEST    = 260,
    QUEST_INFO_ISLAND_WEEKLY_QUEST                  = 261,
    QUEST_INFO_PUBLIC_QUEST                         = 263,
    QUEST_INFO_THREAT_OBJECTIVE                     = 264,
    QUEST_INFO_HIDDEN_QUEST                         = 265,
    QUEST_INFO_COMBAT_ALLY_QUEST                    = 266,
    QUEST_INFO_PROFESSIONS                          = 267,
    QUEST_INFO_THREAT_WRAPPER                       = 268,
    QUEST_INFO_THREAT_EMISSARY_QUEST                = 270,
    QUEST_INFO_CALLING_QUEST                        = 271,
    QUEST_INFO_VENTHYR_PARTY_QUEST                  = 272,
    QUEST_INFO_MAW_SOUL_SPAWN_TRACKER               = 273
};

// QuestSort.dbc (9.0.2.37176)
enum QuestSort
{
    QUEST_SORT_EPIC                             = 1,
    QUEST_SORT_HALLOWS_END                      = 21,
    QUEST_SORT_SEASONAL                         = 22,
    QUEST_SORT_CATACLYSM                        = 23,
    QUEST_SORT_HERBALISM                        = 24,
    QUEST_SORT_BATTLEGROUNDS                    = 25,
    QUEST_SORT_DAY_OF_THE_DEAD                  = 41,
    QUEST_SORT_WARLOCK                          = 61,
    QUEST_SORT_WARRIOR                          = 81,
    QUEST_SORT_SHAMAN                           = 82,
    QUEST_SORT_FISHING                          = 101,
    QUEST_SORT_BLACKSMITHING                    = 121,
    QUEST_SORT_PALADIN                          = 141,
    QUEST_SORT_MAGE                             = 161,
    QUEST_SORT_ROGUE                            = 162,
    QUEST_SORT_ALCHEMY                          = 181,
    QUEST_SORT_LEATHERWORKING                   = 182,
    QUEST_SORT_ENGINEERING                      = 201,
    QUEST_SORT_TREASURE_MAP                     = 221,
    QUEST_SORT_TOURNAMENT                       = 241,
    QUEST_SORT_HUNTER                           = 261,
    QUEST_SORT_PRIEST                           = 262,
    QUEST_SORT_DRUID                            = 263,
    QUEST_SORT_TAILORING                        = 264,
    QUEST_SORT_SPECIAL                          = 284,
    QUEST_SORT_COOKING                          = 304,
    QUEST_SORT_FIRST_AID                        = 324,
    QUEST_SORT_LEGENDARY                        = 344,
    QUEST_SORT_DARKMOON_FAIRE                   = 364,
    QUEST_SORT_AHN_QIRAJ_WAR                    = 365,
    QUEST_SORT_LUNAR_FESTIVAL                   = 366,
    QUEST_SORT_REPUTATION                       = 367,
    QUEST_SORT_INVASION                         = 368,
    QUEST_SORT_MIDSUMMER                        = 369,
    QUEST_SORT_BREWFEST                         = 370,
    QUEST_SORT_INSCRIPTION                      = 371,
    QUEST_SORT_DEATH_KNIGHT                     = 372,
    QUEST_SORT_JEWELCRAFTING                    = 373,
    QUEST_SORT_NOBLEGARDEN                      = 374,
    QUEST_SORT_PILGRIMS_BOUNTY                  = 375,
    QUEST_SORT_LOVE_IS_IN_THE_AIR               = 376,
    QUEST_SORT_ARCHAEOLOGY                      = 377,
    QUEST_SORT_CHILDRENS_WEEK                   = 378,
    QUEST_SORT_FIRELANDS_INVASION               = 379,
    QUEST_SORT_THE_ZANDALARI                    = 380,
    QUEST_SORT_ELEMENTAL_BONDS                  = 381,
    QUEST_SORT_PANDAREN_BREWMASTER              = 391,
    QUEST_SORT_SCENARIO                         = 392,
    QUEST_SORT_BATTLE_PETS                      = 394,
    QUEST_SORT_MONK                             = 395,
    QUEST_SORT_LANDFALL                         = 396,
    QUEST_SORT_PANDAREN_CAMPAIGN                = 397,
    QUEST_SORT_RIDING                           = 398,
    QUEST_SORT_BRAWLERS_GUILD                   = 399,
    QUEST_SORT_PROVING_GROUNDS                  = 400,
    QUEST_SORT_GARRISON_CAMPAIGN                = 401,
    QUEST_SORT_ASSAULT_ON_THE_DARK_PORTAL       = 402,
    QUEST_SORT_GARRISON_SUPPORT                 = 403,
    QUEST_SORT_LOGGING                          = 404,
    QUEST_SORT_PICKPOCKETING                    = 405,
    QUEST_SORT_ARTIFACT                         = 406,
    QUEST_SORT_DEMON_HUNTER                     = 407,
    QUEST_SORT_MINING                           = 408,
    QUEST_SORT_WEEKEND_EVENT                    = 409,
    QUEST_SORT_ENCHANTING                       = 410,
    QUEST_SORT_SKINNING                         = 411,
    QUEST_SORT_WORLD_QUEST                      = 412,
    QUEST_SORT_DEATH_KNIGHT_CAMPAIGN            = 413,
    QUEST_SORT_DEMON_HUNTER_CAMPAIGN            = 416,
    QUEST_SORT_DRUID_CAMPAIGN                   = 417,
    QUEST_SORT_HUNTER_CAMPAIGN                  = 418,
    QUEST_SORT_MONK_CAMPAIGN                    = 419,
    QUEST_SORT_MAGE_CAMPAIGN                    = 420,
    QUEST_SORT_PRIEST_CAMPAIGN                  = 421,
    QUEST_SORT_PALADIN_CAMPAIGN                 = 422,
    QUEST_SORT_SHAMAN_CAMPAIGN                  = 423,
    QUEST_SORT_ROGUE_CAMPAIGN                   = 424,
    QUEST_SORT_WARLOCK_CAMPAIGN                 = 425,
    QUEST_SORT_WARRIOR_CAMPAIGN                 = 426,
    QUEST_SORT_ORDER_HALL                       = 427,
    QUEST_SORT_LEGIONFALL_CAMPAIGN              = 428,
    QUEST_SORT_THE_HUNT_FOR_ILLIDAN_STORMRAGE   = 429,
    QUEST_SORT_PIRATES_DAY                      = 430,
    QUEST_SORT_ARGUS_EXPEDITION                 = 431,
    QUEST_SORT_WARFRONTS                        = 432,
    QUEST_SORT_MOONKIN_FESTIVAL                 = 433,
    QUEST_SORT_THE_KINGS_PATH                   = 434,
    QUEST_SORT_THE_DEATHS_OF_CHROMIE            = 435,
    QUEST_SORT_ROCKET_CHICKEN                   = 436,
    QUEST_SORT_LIGHTFORGED_DRAENEI              = 437,
    QUEST_SORT_HIGHMOUNTAIN_TAUREN              = 438,
    QUEST_SORT_VOID_ELF                         = 439,
    QUEST_SORT_NIGHTBORNE                       = 440,
    QUEST_SORT_DUNGEON                          = 441,
    QUEST_SORT_RAID                             = 442,
    QUEST_SORT_ALLIED_RACES                     = 444,
    QUEST_SORT_THE_WARCHIEFS_AGENDA             = 445,
    QUEST_SORT_ADVENTURE_JOURNEY                = 446,
    QUEST_SORT_ALLIANCE_WAR_CAMPAIGN            = 447,
    QUEST_SORT_HORDE_WAR_CAMPAIGN               = 448,
    QUEST_SORT_DARK_IRON_DWARF                  = 449,
    QUEST_SORT_MAGHAR_ORC                       = 450,
    QUEST_SORT_THE_SHADOW_HUNTER                = 451,
    QUEST_SORT_ISLAND_EXPEDITIONS               = 453,
    QUEST_SORT_WORLD_PVP                        = 555,
    QUEST_SORT_THE_PRIDE_OF_KUL_TIRAS           = 556,
    QUEST_SORT_RATED_PVP                        = 557,
    QUEST_SORT_ZANDALARI_TROLL                  = 559,
    QUEST_SORT_HERITAGE                         = 560,
    QUEST_SORT_QUESTFALL                        = 561,
    QUEST_SORT_TYRANDES_VENGEANCE               = 562,
    QUEST_SORT_THE_FATE_OF_SAURFANG             = 563,
    QUEST_SORT_FREE_TSHIRT_DAY                  = 564,
    QUEST_SORT_CRUCIBLE_OF_STORMS               = 565,
    QUEST_SORT_KUL_TIRAN                        = 566,
    QUEST_SORT_ASSAULT                          = 567,
    QUEST_SORT_HEART_OF_AZEROTH                 = 569,
    QUEST_SORT_PROFESSIONS                      = 571,
    QUEST_SORT_NAZJATAR_FOLLOWERS               = 573,
    QUEST_SORT_SINFALL                          = 574,
    QUEST_SORT_KORRAKS_REVENGE                  = 575,
    QUEST_SORT_COVENANT_SANCTUM                 = 576,
    QUEST_SORT_REFER_A_FRIEND                   = 579,
    QUEST_SORT_VISIONS_OF_NZOTH                 = 580,
    QUEST_SORT_VULPERA                          = 582,
    QUEST_SORT_MECHAGNOME                       = 583,
    QUEST_SORT_BLACK_EMPIRE_CAMPAIGN            = 584,
    QUEST_SORT_EMBER_COURT                      = 586,
    QUEST_SORT_THROUGH_THE_SHATTERED_SKY        = 587,
    QUEST_SORT_DEATH_RISING                     = 588,
    QUEST_SORT_KYRIAN_CALLINGS                  = 589,
    QUEST_SORT_NIGHT_FAE_CALLINGS               = 590,
    QUEST_SORT_NECROLORD_CALLINGS               = 591,
    QUEST_SORT_VENTHYR_CALLINGS                 = 592,
    QUEST_SORT_ABOMINABLE_STITCHING             = 593,
    QUEST_SORT_TIMEWALKING_CAMPAIGN             = 594,
    QUEST_SORT_PATH_OF_ASCENSION                = 595,
    QUEST_SORT_LEGENDARY_CRAFTING               = 596,
    QUEST_SORT_9_1_CAMPAIGN                     = 600,
    QUEST_SORT_CYPHERS_OF_THE_FIRST_ONES        = 601,
    QUEST_SORT_ZERETH_MORTIS_CAMPAIGN           = 602,
    QUEST_SORT_THE_ARCHIVISTS_CODEX             = 603,
    QUEST_SORT_COVENANT_ASSAULTS                = 604,
    QUEST_SORT_PROTOFORM_SYNTHESIS              = 606,
    QUEST_SORT_CH_6_SYMBOL_TRACKING             = 607,
};

constexpr uint8 ClassByQuestSort(int32 QuestSort)
{
    switch (QuestSort)
    {
        case QUEST_SORT_WARLOCK:        return CLASS_WARLOCK;
        case QUEST_SORT_WARRIOR:        return CLASS_WARRIOR;
        case QUEST_SORT_SHAMAN:         return CLASS_SHAMAN;
        case QUEST_SORT_PALADIN:        return CLASS_PALADIN;
        case QUEST_SORT_MAGE:           return CLASS_MAGE;
        case QUEST_SORT_ROGUE:          return CLASS_ROGUE;
        case QUEST_SORT_HUNTER:         return CLASS_HUNTER;
        case QUEST_SORT_PRIEST:         return CLASS_PRIEST;
        case QUEST_SORT_DRUID:          return CLASS_DRUID;
        case QUEST_SORT_DEATH_KNIGHT:   return CLASS_DEATH_KNIGHT;
        case QUEST_SORT_DEMON_HUNTER:   return CLASS_DEMON_HUNTER;
    }
    return 0;
}

// SkillLine.db2 (10.0.5.48069)
enum SkillType
{
    SKILL_NONE                                      = 0,

    SKILL_SWORDS                                    = 43,
    SKILL_AXES                                      = 44,
    SKILL_BOWS                                      = 45,
    SKILL_GUNS                                      = 46,
    SKILL_MACES                                     = 54,
    SKILL_TWO_HANDED_SWORDS                         = 55,
    SKILL_DEFENSE                                   = 95,
    SKILL_LANGUAGE_COMMON                           = 98,
    SKILL_RACIAL_DWARF                              = 101,
    SKILL_LANGUAGE_ORCISH                           = 109,
    SKILL_LANGUAGE_DWARVEN                          = 111,
    SKILL_LANGUAGE_DARNASSIAN                       = 113,
    SKILL_LANGUAGE_TAURAHE                          = 115,
    SKILL_DUAL_WIELD                                = 118,
    SKILL_RACIAL_TAUREN                             = 124,
    SKILL_RACIAL_ORC                                = 125,
    SKILL_RACIAL_NIGHT_ELF                          = 126,
    SKILL_STAVES                                    = 136,
    SKILL_LANGUAGE_THALASSIAN                       = 137,
    SKILL_LANGUAGE_DRACONIC                         = 138,
    SKILL_LANGUAGE_DEMON_TONGUE                     = 139,
    SKILL_LANGUAGE_TITAN                            = 140,
    SKILL_LANGUAGE_OLD_TONGUE                       = 141,
    SKILL_SURVIVAL                                  = 142,
    SKILL_HORSE_RIDING                              = 148,
    SKILL_WOLF_RIDING                               = 149,
    SKILL_TIGER_RIDING                              = 150,
    SKILL_RAM_RIDING                                = 152,
    SKILL_SWIMMING                                  = 155,
    SKILL_TWO_HANDED_MACES                          = 160,
    SKILL_UNARMED                                   = 162,
    SKILL_BLACKSMITHING                             = 164,
    SKILL_LEATHERWORKING                            = 165,
    SKILL_ALCHEMY                                   = 171,
    SKILL_TWO_HANDED_AXES                           = 172,
    SKILL_DAGGERS                                   = 173,
    SKILL_HERBALISM                                 = 182,
    SKILL_GENERIC_DND                               = 183,
    SKILL_COOKING                                   = 185,
    SKILL_MINING                                    = 186,
    SKILL_PET_IMP                                   = 188,
    SKILL_PET_FELHUNTER                             = 189,
    SKILL_TAILORING                                 = 197,
    SKILL_ENGINEERING                               = 202,
    SKILL_PET_SPIDER                                = 203,
    SKILL_PET_VOIDWALKER                            = 204,
    SKILL_PET_SUCCUBUS                              = 205,
    SKILL_PET_INFERNAL                              = 206,
    SKILL_PET_DOOMGUARD                             = 207,
    SKILL_PET_WOLF                                  = 208,
    SKILL_PET_CAT                                   = 209,
    SKILL_PET_BEAR                                  = 210,
    SKILL_PET_BOAR                                  = 211,
    SKILL_PET_CROCOLISK                             = 212,
    SKILL_PET_CARRION_BIRD                          = 213,
    SKILL_PET_CRAB                                  = 214,
    SKILL_PET_GORILLA                               = 215,
    SKILL_PET_RAPTOR                                = 217,
    SKILL_PET_TALLSTRIDER                           = 218,
    SKILL_RACIAL_UNDEAD                             = 220,
    SKILL_CROSSBOWS                                 = 226,
    SKILL_WANDS                                     = 228,
    SKILL_POLEARMS                                  = 229,
    SKILL_PET_SCORPID                               = 236,
    SKILL_PET_TURTLE                                = 251,
    SKILL_PET_GENERIC_HUNTER                        = 270,
    SKILL_PLATE_MAIL                                = 293,
    SKILL_LANGUAGE_GNOMISH                          = 313,
    SKILL_LANGUAGE_TROLL                            = 315,
    SKILL_ENCHANTING                                = 333,
    SKILL_FISHING                                   = 356,
    SKILL_SKINNING                                  = 393,
    SKILL_MAIL                                      = 413,
    SKILL_LEATHER                                   = 414,
    SKILL_CLOTH                                     = 415,
    SKILL_SHIELD                                    = 433,
    SKILL_FIST_WEAPONS                              = 473,
    SKILL_RAPTOR_RIDING                             = 533,
    SKILL_MECHANOSTRIDER_PILOTING                   = 553,
    SKILL_UNDEAD_HORSEMANSHIP                       = 554,
    SKILL_PET_BAT                                   = 653,
    SKILL_PET_HYENA                                 = 654,
    SKILL_PET_BIRD_OF_PREY                          = 655,
    SKILL_PET_WIND_SERPENT                          = 656,
    SKILL_LANGUAGE_FORSAKEN                         = 673,
    SKILL_KODO_RIDING                               = 713,
    SKILL_RACIAL_TROLL                              = 733,
    SKILL_RACIAL_GNOME                              = 753,
    SKILL_RACIAL_HUMAN                              = 754,
    SKILL_JEWELCRAFTING                             = 755,
    SKILL_RACIAL_BLOOD_ELF                          = 756,
    SKILL_PET_EVENT_REMOTE_CONTROL                  = 758,
    SKILL_LANGUAGE_DRAENEI                          = 759,
    SKILL_RACIAL_DRAENEI                            = 760,
    SKILL_PET_FELGUARD                              = 761,
    SKILL_RIDING                                    = 762,
    SKILL_PET_DRAGONHAWK                            = 763,
    SKILL_PET_NETHER_RAY                            = 764,
    SKILL_PET_SPOREBAT                              = 765,
    SKILL_PET_WARP_STALKER                          = 766,
    SKILL_PET_RAVAGER                               = 767,
    SKILL_PET_SERPENT                               = 768,
    SKILL_INTERNAL                                  = 769,
    SKILL_INSCRIPTION                               = 773,
    SKILL_PET_MOTH                                  = 775,
    SKILL_MOUNTS                                    = 777,
    SKILL_COMPANIONS                                = 778,
    SKILL_PET_EXOTIC_CHIMAERA                       = 780,
    SKILL_PET_EXOTIC_DEVILSAUR                      = 781,
    SKILL_PET_GHOUL                                 = 782,
    SKILL_PET_EXOTIC_SILITHID                       = 783,
    SKILL_PET_EXOTIC_WORM                           = 784,
    SKILL_PET_WASP                                  = 785,
    SKILL_PET_EXOTIC_CLEFTHOOF                      = 786,
    SKILL_PET_EXOTIC_CORE_HOUND                     = 787,
    SKILL_PET_EXOTIC_SPIRIT_BEAST                   = 788,
    SKILL_RACIAL_WORGEN                             = 789,
    SKILL_RACIAL_GOBLIN                             = 790,
    SKILL_LANGUAGE_GILNEAN                          = 791,
    SKILL_LANGUAGE_GOBLIN                           = 792,
    SKILL_ARCHAEOLOGY                               = 794,
    SKILL_HUNTER                                    = 795,
    SKILL_DEATH_KNIGHT                              = 796,
    SKILL_DRUID                                     = 798,
    SKILL_PALADIN                                   = 800,
    SKILL_PRIEST                                    = 804,
    SKILL_PET_WATER_ELEMENTAL                       = 805,
    SKILL_PET_FOX                                   = 808,
    SKILL_ALL_GLYPHS                                = 810,
    SKILL_PET_DOG                                   = 811,
    SKILL_PET_MONKEY                                = 815,
    SKILL_PET_EXOTIC_SHALE_SPIDER                   = 817,
    SKILL_BEETLE                                    = 818,
    SKILL_ALL_GUILD_PERKS                           = 821,
    SKILL_PET_HYDRA                                 = 824,
    SKILL_MONK                                      = 829,
    SKILL_WARRIOR                                   = 840,
    SKILL_WARLOCK                                   = 849,
    SKILL_RACIAL_PANDAREN                           = 899,
    SKILL_MAGE                                      = 904,
    SKILL_LANGUAGE_PANDAREN_NEUTRAL                 = 905,
    SKILL_ROGUE                                     = 921,
    SKILL_SHAMAN                                    = 924,
    SKILL_FEL_IMP                                   = 927,
    SKILL_VOIDLORD                                  = 928,
    SKILL_SHIVARRA                                  = 929,
    SKILL_OBSERVER                                  = 930,
    SKILL_WRATHGUARD                                = 931,
    SKILL_ALL_SPECIALIZATIONS                       = 934,
    SKILL_RUNEFORGING                               = 960,
    SKILL_PET_PRIMAL_FIRE_ELEMENTAL                 = 962,
    SKILL_PET_PRIMAL_EARTH_ELEMENTAL                = 963,
    SKILL_WAY_OF_THE_GRILL                          = 975,
    SKILL_WAY_OF_THE_WOK                            = 976,
    SKILL_WAY_OF_THE_POT                            = 977,
    SKILL_WAY_OF_THE_STEAMER                        = 978,
    SKILL_WAY_OF_THE_OVEN                           = 979,
    SKILL_WAY_OF_THE_BREW                           = 980,
    SKILL_APPRENTICE_COOKING                        = 981,
    SKILL_JOURNEYMAN_COOKBOOK                       = 982,
    SKILL_PET_RODENT                                = 983,
    SKILL_PET_CRANE                                 = 984,
    SKILL_PET_WATER_STRIDER                         = 985,
    SKILL_PET_EXOTIC_QUILEN                         = 986,
    SKILL_PET_GOAT                                  = 987,
    SKILL_PET_BASILISK                              = 988,
    SKILL_NO_PLAYERS                                = 999,
    SKILL_PET_DIREHORN                              = 1305,
    SKILL_PET_PRIMAL_STORM_ELEMENTAL                = 1748,
    SKILL_PET_WATER_ELEMENTAL_MINOR_TALENT_VERSION  = 1777,
    SKILL_PET_RIVERBEAST                            = 1819,
    SKILL_UNUSED                                    = 1830,
    SKILL_DEMON_HUNTER                              = 1848,
    SKILL_LOGGING                                   = 1945,
    SKILL_PET_TERRORGUARD                           = 1981,
    SKILL_PET_ABYSSAL                               = 1982,
    SKILL_PET_STAG                                  = 1993,
    SKILL_TRADING_POST                              = 2000,
    SKILL_WARGLAIVES                                = 2152,
    SKILL_PET_MECHANICAL                            = 2189,
    SKILL_PET_ABOMINATION                           = 2216,
    SKILL_PET_OXEN                                  = 2279,
    SKILL_PET_SCALEHIDE                             = 2280,
    SKILL_PET_FEATHERMANE                           = 2361,
    SKILL_RACIAL_NIGHTBORNE                         = 2419,
    SKILL_RACIAL_HIGHMOUNTAIN_TAUREN                = 2420,
    SKILL_RACIAL_LIGHTFORGED_DRAENEI                = 2421,
    SKILL_RACIAL_VOID_ELF                           = 2423,
    SKILL_KUL_TIRAN_BLACKSMITHING                   = 2437,
    SKILL_LEGION_BLACKSMITHING                      = 2454,
    SKILL_LANGUAGE_SHALASSIAN                       = 2464,
    SKILL_LANGUAGE_THALASSIAN_2                     = 2465,
    SKILL_DRAENOR_BLACKSMITHING                     = 2472,
    SKILL_PANDARIA_BLACKSMITHING                    = 2473,
    SKILL_CATACLYSM_BLACKSMITHING                   = 2474,
    SKILL_NORTHREND_BLACKSMITHING                   = 2475,
    SKILL_OUTLAND_BLACKSMITHING                     = 2476,
    SKILL_CLASSIC_BLACKSMITHING                     = 2477,
    SKILL_KUL_TIRAN_ALCHEMY                         = 2478,
    SKILL_LEGION_ALCHEMY                            = 2479,
    SKILL_DRAENOR_ALCHEMY                           = 2480,
    SKILL_PANDARIA_ALCHEMY                          = 2481,
    SKILL_CATACLYSM_ALCHEMY                         = 2482,
    SKILL_NORTHREND_ALCHEMY                         = 2483,
    SKILL_OUTLAND_ALCHEMY                           = 2484,
    SKILL_CLASSIC_ALCHEMY                           = 2485,
    SKILL_KUL_TIRAN_ENCHANTING                      = 2486,
    SKILL_LEGION_ENCHANTING                         = 2487,
    SKILL_DRAENOR_ENCHANTING                        = 2488,
    SKILL_PANDARIA_ENCHANTING                       = 2489,
    SKILL_CATACLYSM_ENCHANTING                      = 2491,
    SKILL_NORTHREND_ENCHANTING                      = 2492,
    SKILL_OUTLAND_ENCHANTING                        = 2493,
    SKILL_CLASSIC_ENCHANTING                        = 2494,
    SKILL_KUL_TIRAN_ENGINEERING                     = 2499,
    SKILL_LEGION_ENGINEERING                        = 2500,
    SKILL_DRAENOR_ENGINEERING                       = 2501,
    SKILL_PANDARIA_ENGINEERING                      = 2502,
    SKILL_CATACLYSM_ENGINEERING                     = 2503,
    SKILL_NORTHREND_ENGINEERING                     = 2504,
    SKILL_OUTLAND_ENGINEERING                       = 2505,
    SKILL_CLASSIC_ENGINEERING                       = 2506,
    SKILL_KUL_TIRAN_INSCRIPTION                     = 2507,
    SKILL_LEGION_INSCRIPTION                        = 2508,
    SKILL_DRAENOR_INSCRIPTION                       = 2509,
    SKILL_PANDARIA_INSCRIPTION                      = 2510,
    SKILL_CATACLYSM_INSCRIPTION                     = 2511,
    SKILL_NORTHREND_INSCRIPTION                     = 2512,
    SKILL_OUTLAND_INSCRIPTION                       = 2513,
    SKILL_CLASSIC_INSCRIPTION                       = 2514,
    SKILL_KUL_TIRAN_JEWELCRAFTING                   = 2517,
    SKILL_LEGION_JEWELCRAFTING                      = 2518,
    SKILL_DRAENOR_JEWELCRAFTING                     = 2519,
    SKILL_PANDARIA_JEWELCRAFTING                    = 2520,
    SKILL_CATACLYSM_JEWELCRAFTING                   = 2521,
    SKILL_NORTHREND_JEWELCRAFTING                   = 2522,
    SKILL_OUTLAND_JEWELCRAFTING                     = 2523,
    SKILL_CLASSIC_JEWELCRAFTING                     = 2524,
    SKILL_KUL_TIRAN_LEATHERWORKING                  = 2525,
    SKILL_LEGION_LEATHERWORKING                     = 2526,
    SKILL_DRAENOR_LEATHERWORKING                    = 2527,
    SKILL_PANDARIA_LEATHERWORKING                   = 2528,
    SKILL_CATACLYSM_LEATHERWORKING                  = 2529,
    SKILL_NORTHREND_LEATHERWORKING                  = 2530,
    SKILL_OUTLAND_LEATHERWORKING                    = 2531,
    SKILL_CLASSIC_LEATHERWORKING                    = 2532,
    SKILL_KUL_TIRAN_TAILORING                       = 2533,
    SKILL_LEGION_TAILORING                          = 2534,
    SKILL_DRAENOR_TAILORING                         = 2535,
    SKILL_PANDARIA_TAILORING                        = 2536,
    SKILL_CATACLYSM_TAILORING                       = 2537,
    SKILL_NORTHREND_TAILORING                       = 2538,
    SKILL_OUTLAND_TAILORING                         = 2539,
    SKILL_CLASSIC_TAILORING                         = 2540,
    SKILL_KUL_TIRAN_COOKING                         = 2541,
    SKILL_LEGION_COOKING                            = 2542,
    SKILL_DRAENOR_COOKING                           = 2543,
    SKILL_PANDARIA_COOKING                          = 2544,
    SKILL_CATACLYSM_COOKING                         = 2545,
    SKILL_NORTHREND_COOKING                         = 2546,
    SKILL_OUTLAND_COOKING                           = 2547,
    SKILL_CLASSIC_COOKING                           = 2548,
    SKILL_KUL_TIRAN_HERBALISM                       = 2549,
    SKILL_LEGION_HERBALISM                          = 2550,
    SKILL_DRAENOR_HERBALISM                         = 2551,
    SKILL_PANDARIA_HERBALISM                        = 2552,
    SKILL_CATACLYSM_HERBALISM                       = 2553,
    SKILL_NORTHREND_HERBALISM                       = 2554,
    SKILL_OUTLAND_HERBALISM                         = 2555,
    SKILL_CLASSIC_HERBALISM                         = 2556,
    SKILL_KUL_TIRAN_SKINNING                        = 2557,
    SKILL_LEGION_SKINNING                           = 2558,
    SKILL_DRAENOR_SKINNING                          = 2559,
    SKILL_PANDARIA_SKINNING                         = 2560,
    SKILL_CATACLYSM_SKINNING                        = 2561,
    SKILL_NORTHREND_SKINNING                        = 2562,
    SKILL_OUTLAND_SKINNING                          = 2563,
    SKILL_CLASSIC_SKINNING                          = 2564,
    SKILL_KUL_TIRAN_MINING                          = 2565,
    SKILL_LEGION_MINING                             = 2566,
    SKILL_DRAENOR_MINING                            = 2567,
    SKILL_PANDARIA_MINING                           = 2568,
    SKILL_CATACLYSM_MINING                          = 2569,
    SKILL_NORTHREND_MINING                          = 2570,
    SKILL_OUTLAND_MINING                            = 2571,
    SKILL_CLASSIC_MINING                            = 2572,
    SKILL_KUL_TIRAN_FISHING                         = 2585,
    SKILL_LEGION_FISHING                            = 2586,
    SKILL_DRAENOR_FISHING                           = 2587,
    SKILL_PANDARIA_FISHING                          = 2588,
    SKILL_CATACLYSM_FISHING                         = 2589,
    SKILL_NORTHREND_FISHING                         = 2590,
    SKILL_OUTLAND_FISHING                           = 2591,
    SKILL_CLASSIC_FISHING                           = 2592,
    SKILL_RACIAL_DARK_IRON_DWARF                    = 2597,
    SKILL_RACIAL_MAG_HAR_ORC                        = 2598,
    SKILL_PET_LIZARD                                = 2703,
    SKILL_PET_HORSE                                 = 2704,
    SKILL_PET_EXOTIC_PTERRORDAX                     = 2705,
    SKILL_PET_TOAD                                  = 2706,
    SKILL_PET_EXOTIC_KROLUSK                        = 2707,
    SKILL_SECOND_PET_HUNTER                         = 2716,
    SKILL_PET_BLOOD_BEAST                           = 2719,
    SKILL_JUNKYARD_TINKERING                        = 2720,
    SKILL_RACIAL_ZANDALARI_TROLL                    = 2721,
    SKILL_RACIAL_KUL_TIRAN                          = 2723,
    SKILL_AZERITE_POWER                             = 2727,
    SKILL_COVENANT_KYRIAN                           = 2730,
    SKILL_COVENANT_VENTHYR                          = 2731,
    SKILL_COVENANT_NIGHT_FAE                        = 2732,
    SKILL_COVENANT_NECROLORD                        = 2733,
    SKILL_MOUNT_EQUIPEMENT                          = 2734,
    SKILL_SHADOWLANDS_ALCHEMY                       = 2750,
    SKILL_SHADOWLANDS_BLACKSMITHING                 = 2751,
    SKILL_SHADOWLANDS_COOKING                       = 2752,
    SKILL_SHADOWLANDS_ENCHANTING                    = 2753,
    SKILL_SHADOWLANDS_FISHING                       = 2754,
    SKILL_SHADOWLANDS_ENGINEERING                   = 2755,
    SKILL_SHADOWLANDS_INSCRIPTION                   = 2756,
    SKILL_SHADOWLANDS_JEWELCRAFTING                 = 2757,
    SKILL_SHADOWLANDS_LEATHERWORKING                = 2758,
    SKILL_SHADOWLANDS_TAILORING                     = 2759,
    SKILL_SHADOWLANDS_HERBALISM                     = 2760,
    SKILL_SHADOWLANDS_MINING                        = 2761,
    SKILL_SHADOWLANDS_SKINNING                      = 2762,
    SKILL_RACIAL_DARK_IRON_DWARF_2                  = 2773,
    SKILL_RACIAL_MECHAGNOME                         = 2774,
    SKILL_RACIAL_VULPERA                            = 2775,
    SKILL_LANGUAGE_VULPERA                          = 2776,
    SKILL_SOUL_CYPHERING                            = 2777,
    SKILL_ABOMINABLE_STITCHING                      = 2787,
    SKILL_ASCENSION_CRAFTING                        = 2791,
    SKILL_PET_MAMMOTH                               = 2805,
    SKILL_PET_COURSER                               = 2806,
    SKILL_PET_CAMEL                                 = 2807,
    SKILL_RACIAL_DRACTHYR                           = 2808,
    SKILL_EVOKER                                    = 2810,
    SKILL_STYGIA_CRAFTING                           = 2811,
    SKILL_LANGUAGE_CYPHER                           = 2817,
    SKILL_PROTOFORM_SYNTHESIS                       = 2819,
    SKILL_ARCANA_MANIPULATION                       = 2821,
    SKILL_DRAGON_ISLES_BLACKSMITHING                = 2822,
    SKILL_DRAGON_ISLES_ALCHEMY                      = 2823,
    SKILL_DRAGON_ISLES_COOKING                      = 2824,
    SKILL_DRAGON_ISLES_ENCHANTING                   = 2825,
    SKILL_DRAGON_ISLES_FISHING                      = 2826,
    SKILL_DRAGON_ISLES_ENGINEERING                  = 2827,
    SKILL_DRAGON_ISLES_INSCRIPTION                  = 2828,
    SKILL_DRAGON_ISLES_JEWELCRAFTING                = 2829,
    SKILL_DRAGON_ISLES_LEATHERWORKING               = 2830,
    SKILL_DRAGON_ISLES_TAILORING                    = 2831,
    SKILL_DRAGON_ISLES_HERBALISM                    = 2832,
    SKILL_DRAGON_ISLES_MINING                       = 2833,
    SKILL_DRAGON_ISLES_SKINNING                     = 2834,
    SKILL_CRAFTING                                  = 2846,
    SKILL_TUSKARR_FISHING_GEAR                      = 2847,
    SKILL_PET_LESSER_DRAGONKIN                      = 2850
};

constexpr SkillType SkillByLockType(LockType locktype)
{
    switch (locktype)
    {
        case LOCKTYPE_HERBALISM:
        case LOCKTYPE_ELUSIVE_HERBALISM:              return SKILL_HERBALISM;
        case LOCKTYPE_MINING:
        case LOCKTYPE_MINING_2:
        case LOCKTYPE_ELUSIVE_MINING:                 return SKILL_MINING;
        case LOCKTYPE_FISHING:                        return SKILL_FISHING;
        case LOCKTYPE_INSCRIPTION:                    return SKILL_INSCRIPTION;
        case LOCKTYPE_ARCHAEOLOGY:                    return SKILL_ARCHAEOLOGY;
        case LOCKTYPE_LUMBER_MILL:                    return SKILL_LOGGING;
        case LOCKTYPE_SKINNING:                       return SKILL_SKINNING;
        case LOCKTYPE_CLASSIC_HERBALISM:              return SKILL_CLASSIC_HERBALISM;
        case LOCKTYPE_OUTLAND_HERBALISM:              return SKILL_OUTLAND_HERBALISM;
        case LOCKTYPE_NORTHREND_HERBALISM:            return SKILL_NORTHREND_HERBALISM;
        case LOCKTYPE_CATACLYSM_HERBALISM:            return SKILL_CATACLYSM_HERBALISM;
        case LOCKTYPE_PANDARIA_HERBALISM:             return SKILL_PANDARIA_HERBALISM;
        case LOCKTYPE_DRAENOR_HERBALISM:              return SKILL_DRAENOR_HERBALISM;
        case LOCKTYPE_LEGION_HERBALISM:               return SKILL_LEGION_HERBALISM;
        case LOCKTYPE_KUL_TIRAN_HERBALISM:            return SKILL_KUL_TIRAN_HERBALISM;
        case LOCKTYPE_CLASSIC_MINING:                 return SKILL_CLASSIC_MINING;
        case LOCKTYPE_OUTLAND_MINING:                 return SKILL_OUTLAND_MINING;
        case LOCKTYPE_NORTHREND_MINING:               return SKILL_NORTHREND_MINING;
        case LOCKTYPE_CATACLYSM_MINING:               return SKILL_CATACLYSM_MINING;
        case LOCKTYPE_PANDARIA_MINING:                return SKILL_PANDARIA_MINING;
        case LOCKTYPE_DRAENOR_MINING:                 return SKILL_DRAENOR_MINING;
        case LOCKTYPE_LEGION_MINING:                  return SKILL_LEGION_MINING;
        case LOCKTYPE_KUL_TIRAN_MINING:               return SKILL_KUL_TIRAN_MINING;
        case LOCKTYPE_LEGION_SKINNING:                return SKILL_LEGION_SKINNING;
        case LOCKTYPE_SHADOWLANDS_HERBALISM:          return SKILL_SHADOWLANDS_HERBALISM;
        case LOCKTYPE_SHADOWLANDS_MINING:             return SKILL_SHADOWLANDS_MINING;
        case LOCKTYPE_COVENANT_NIGHT_FAE:             return SKILL_COVENANT_NIGHT_FAE;
        case LOCKTYPE_COVENANT_VENTHYR:               return SKILL_COVENANT_VENTHYR;
        case LOCKTYPE_COVENANT_KYRIAN:                return SKILL_COVENANT_KYRIAN;
        case LOCKTYPE_COVENANT_NECROLORD:             return SKILL_COVENANT_NECROLORD;
        case LOCKTYPE_ENGINEERING:                    return SKILL_ENGINEERING;
        case LOCKTYPE_DRAGON_ISLES_HERBALISM:
        case LOCKTYPE_DRAGON_ISLES_HERBALISM_25:      return SKILL_DRAGON_ISLES_HERBALISM;
        case LOCKTYPE_ENCHANTING:                     return SKILL_ENCHANTING;
        case LOCKTYPE_DRAGON_ISLES_ALCHEMY_25:        return SKILL_DRAGON_ISLES_ALCHEMY;
        case LOCKTYPE_DRAGON_ISLES_BLACKSMITHING_25:  return SKILL_DRAGON_ISLES_BLACKSMITHING;
        case LOCKTYPE_DRAGON_ISLES_ENCHANTING_25:     return SKILL_DRAGON_ISLES_ENCHANTING;
        case LOCKTYPE_DRAGON_ISLES_ENGINEERING_25:    return SKILL_DRAGON_ISLES_ENGINEERING;
        case LOCKTYPE_DRAGON_ISLES_INSCRIPTION_25:    return SKILL_DRAGON_ISLES_INSCRIPTION;
        case LOCKTYPE_DRAGON_ISLES_JEWELCRAFTING_25:  return SKILL_DRAGON_ISLES_JEWELCRAFTING;
        case LOCKTYPE_DRAGON_ISLES_LEATHERWORKING_25: return SKILL_DRAGON_ISLES_LEATHERWORKING;
        case LOCKTYPE_DRAGON_ISLES_SKINNING_25:       return SKILL_DRAGON_ISLES_SKINNING;
        case LOCKTYPE_DRAGON_ISLES_TAILORING_25:      return SKILL_DRAGON_ISLES_TAILORING;
        case LOCKTYPE_DRAGON_ISLES_MINING:
        case LOCKTYPE_DRAGON_ISLES_MINING_25:         return SKILL_DRAGON_ISLES_MINING;
        default: break;
    }
    return SKILL_NONE;
}

constexpr uint32 SkillByQuestSort(int32 QuestSort)
{
    switch (QuestSort)
    {
        case QUEST_SORT_HERBALISM:      return SKILL_HERBALISM;
        case QUEST_SORT_FISHING:        return SKILL_FISHING;
        case QUEST_SORT_BLACKSMITHING:  return SKILL_BLACKSMITHING;
        case QUEST_SORT_ALCHEMY:        return SKILL_ALCHEMY;
        case QUEST_SORT_LEATHERWORKING: return SKILL_LEATHERWORKING;
        case QUEST_SORT_ENGINEERING:    return SKILL_ENGINEERING;
        case QUEST_SORT_TAILORING:      return SKILL_TAILORING;
        case QUEST_SORT_COOKING:        return SKILL_COOKING;
        case QUEST_SORT_JEWELCRAFTING:  return SKILL_JEWELCRAFTING;
        case QUEST_SORT_INSCRIPTION:    return SKILL_INSCRIPTION;
        case QUEST_SORT_ARCHAEOLOGY:    return SKILL_ARCHAEOLOGY;
    }
    return 0;
}

enum SkillCategory
{
    SKILL_CATEGORY_UNK1          = 0,
    SKILL_CATEGORY_ATTRIBUTES    = 5,
    SKILL_CATEGORY_WEAPON        = 6,
    SKILL_CATEGORY_CLASS         = 7,
    SKILL_CATEGORY_ARMOR         = 8,
    SKILL_CATEGORY_SECONDARY     = 9,                       // secondary professions
    SKILL_CATEGORY_LANGUAGES     = 10,
    SKILL_CATEGORY_PROFESSION    = 11,                      // primary professions
    SKILL_CATEGORY_GENERIC       = 12
};

// TotemCategory.db2 (9.0.2.37176)
enum TotemCategory
{
    TC_SKINNING_SKIFE_OLD                   = 1,
    TC_EARTH_TOTEM                          = 2,
    TC_AIR_TOTEM                            = 3,
    TC_FIRE_TOTEM                           = 4,
    TC_WATER_TOTEM                          = 5,
    TC_COPPER_ROD                           = 6,
    TC_SILVER_ROD                           = 7,
    TC_GOLDEN_ROD                           = 8,
    TC_TRUESILVER_ROD                       = 9,
    TC_ARCANITE_ROD                         = 10,
    TC_MINING_PICK_OLD                      = 11,
    TC_PHILOSOPHERS_STONE                   = 12,
    TC_BLACKSMITH_HAMMER_OLD                = 13,
    TC_ARCLIGHT_SPANNER                     = 14,
    TC_GYROMATIC_MA                         = 15,
    TC_MASTER_TOTEM                         = 21,
    TC_FEL_IRON_ROD                         = 41,
    TC_ADAMANTITE_ROD                       = 62,
    TC_ETERNIUM_ROD                         = 63,
    TC_HOLLOW_QUILL                         = 81,
    TC_RUNED_AZURITE_ROD                    = 101,
    TC_VIRTUOSO_INKING_SET                  = 121,
    TC_DRUMS                                = 141,
    TC_GNOMISH_ARMY_KNIFE                   = 161,
    TC_BLACKSMITH_HAMMER                    = 162,
    TC_MINING_PICK                          = 165,
    TC_SKINNING_KNIFE                       = 166,
    TC_HAMMER_PICK                          = 167,
    TC_BLADED_PICKAXE                       = 168,
    TC_FLINT_AND_TINDER                     = 169,
    TC_RUNED_COBALT_ROD                     = 189,
    TC_RUNED_TITANIUM_ROD                   = 190,
    TC_RUNED_ELEMENTIUM_ROD                 = 209,
    TC_HIGH_POWERED_BOLT_GUN                = 210,
    TC_RUNED_COPPER_ROD                     = 230,
    TC_JEWELERS_KIT                         = 238,
    TC_ULTIMATE_GNOMISH_ARMY_KNIFE          = 250,
    TC_SANGUINE_FEATHER_QUILL_OF_LANATHEL   = 253,
    TC_UB3R_SPANNER                         = 354,
    TC_VOID_FOCUS                           = 355,
    TC_EMPOWERED_VOID_FOCUS                 = 356,
    TC_UNLEASHED_VOID_FOCUS                 = 357,
    TC_MASTERCRAFT                          = 358,
    TC_VIRTUOSO_ENGRAVING_SET               = 359,
};

enum UnitDynFlags
{
    UNIT_DYNFLAG_NONE                       = 0x0000,
    UNIT_DYNFLAG_HIDE_MODEL                 = 0x0002, // Object model is not shown with this flag
    UNIT_DYNFLAG_LOOTABLE                   = 0x0004,
    UNIT_DYNFLAG_TRACK_UNIT                 = 0x0008,
    UNIT_DYNFLAG_TAPPED                     = 0x0010, // Lua_UnitIsTapped
    UNIT_DYNFLAG_SPECIALINFO                = 0x0020,
    UNIT_DYNFLAG_CAN_SKIN                   = 0x0040,
    UNIT_DYNFLAG_REFER_A_FRIEND             = 0x0080
};

enum CorpseDynFlags
{
    CORPSE_DYNFLAG_LOOTABLE        = 0x0001
};

DEFINE_ENUM_FLAG(CorpseDynFlags);

#define PLAYER_CORPSE_LOOT_ENTRY 1

// EnumUtils: DESCRIBE THIS
enum WeatherType
{
    WEATHER_TYPE_FINE       = 0,
    WEATHER_TYPE_RAIN       = 1,
    WEATHER_TYPE_SNOW       = 2,
    WEATHER_TYPE_STORM      = 3,
    WEATHER_TYPE_THUNDERS   = 86,
    WEATHER_TYPE_BLACKRAIN  = 90
};

#define MAX_WEATHER_TYPE 4

// EnumUtils: DESCRIBE THIS
enum ChatMsg : int32
{
    CHAT_MSG_ADDON                              = -1,
    CHAT_MSG_SYSTEM                             = 0x00,
    CHAT_MSG_SAY                                = 0x01,
    CHAT_MSG_PARTY                              = 0x02,
    CHAT_MSG_RAID                               = 0x03,
    CHAT_MSG_GUILD                              = 0x04,
    CHAT_MSG_OFFICER                            = 0x05,
    CHAT_MSG_YELL                               = 0x06,
    CHAT_MSG_WHISPER                            = 0x07,
    CHAT_MSG_WHISPER_FOREIGN                    = 0x08,
    CHAT_MSG_WHISPER_INFORM                     = 0x09,
    CHAT_MSG_EMOTE                              = 0x0A,
    CHAT_MSG_TEXT_EMOTE                         = 0x0B,
    CHAT_MSG_MONSTER_SAY                        = 0x0C,
    CHAT_MSG_MONSTER_PARTY                      = 0x0D,
    CHAT_MSG_MONSTER_YELL                       = 0x0E,
    CHAT_MSG_MONSTER_WHISPER                    = 0x0F,
    CHAT_MSG_MONSTER_EMOTE                      = 0x10,
    CHAT_MSG_CHANNEL                            = 0x11,
    CHAT_MSG_CHANNEL_JOIN                       = 0x12,
    CHAT_MSG_CHANNEL_LEAVE                      = 0x13,
    CHAT_MSG_CHANNEL_LIST                       = 0x14,
    CHAT_MSG_CHANNEL_NOTICE                     = 0x15,
    CHAT_MSG_CHANNEL_NOTICE_USER                = 0x16,
    CHAT_MSG_AFK                                = 0x17,
    CHAT_MSG_DND                                = 0x18,
    CHAT_MSG_IGNORED                            = 0x19,
    CHAT_MSG_SKILL                              = 0x1A,
    CHAT_MSG_LOOT                               = 0x1B,
    CHAT_MSG_MONEY                              = 0x1C,
    CHAT_MSG_OPENING                            = 0x1D,
    CHAT_MSG_TRADESKILLS                        = 0x1E,
    CHAT_MSG_PET_INFO                           = 0x1F,
    CHAT_MSG_COMBAT_MISC_INFO                   = 0x20,
    CHAT_MSG_COMBAT_XP_GAIN                     = 0x21,
    CHAT_MSG_COMBAT_HONOR_GAIN                  = 0x22,
    CHAT_MSG_COMBAT_FACTION_CHANGE              = 0x23,
    CHAT_MSG_BG_SYSTEM_NEUTRAL                  = 0x24,
    CHAT_MSG_BG_SYSTEM_ALLIANCE                 = 0x25,
    CHAT_MSG_BG_SYSTEM_HORDE                    = 0x26,
    CHAT_MSG_RAID_LEADER                        = 0x27,
    CHAT_MSG_RAID_WARNING                       = 0x28,
    CHAT_MSG_RAID_BOSS_EMOTE                    = 0x29,
    CHAT_MSG_RAID_BOSS_WHISPER                  = 0x2A,
    CHAT_MSG_FILTERED                           = 0x2B,
    CHAT_MSG_RESTRICTED                         = 0x2C,
    CHAT_MSG_BATTLENET                          = 0x2D,
    CHAT_MSG_ACHIEVEMENT                        = 0x2E,
    CHAT_MSG_GUILD_ACHIEVEMENT                  = 0x2F,
    CHAT_MSG_ARENA_POINTS                       = 0x30,
    CHAT_MSG_PARTY_LEADER                       = 0x31,
    CHAT_MSG_TARGETICONS                        = 0x32,
    CHAT_MSG_BN_WHISPER                         = 0x33,
    CHAT_MSG_BN_WHISPER_INFORM                  = 0x34,
    CHAT_MSG_BN_INLINE_TOAST_ALERT              = 0x35,
    CHAT_MSG_BN_INLINE_TOAST_BROADCAST          = 0x36,
    CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM   = 0x37,
    CHAT_MSG_BN_INLINE_TOAST_CONVERSATION       = 0x38,
    CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE          = 0x39,
    CHAT_MSG_CURRENCY                           = 0x3A,
    CHAT_MSG_QUEST_BOSS_EMOTE                   = 0x3B,
    CHAT_MSG_PET_BATTLE_COMBAT_LOG              = 0x3C,
    CHAT_MSG_PET_BATTLE_INFO                    = 0x3D,
    CHAT_MSG_INSTANCE_CHAT                      = 0x3E,
    CHAT_MSG_INSTANCE_CHAT_LEADER               = 0x3F,
    CHAT_MSG_GUILD_ITEM_LOOTED                  = 0x40,
    CHAT_MSG_COMMUNITIES_CHANNEL                = 0x41,
    CHAT_MSG_VOICE_TEXT                         = 0x42,

    MAX_CHAT_MSG_TYPE
};

#define GM_SILENCE_AURA 1852

enum ChatFlags
{
    CHAT_FLAG_NONE       = 0x0000,
    CHAT_FLAG_AFK        = 0x0001,
    CHAT_FLAG_DND        = 0x0002,
    CHAT_FLAG_GM         = 0x0004,
    CHAT_FLAG_COM        = 0x0008, // Commentator
    CHAT_FLAG_DEV        = 0x0010,
    CHAT_FLAG_BOSS_SOUND = 0x0020, // Plays "RaidBossEmoteWarning" sound on raid boss emote/whisper
    CHAT_FLAG_MOBILE     = 0x0040,
    CHAT_FLAG_GUIDE      = 0x1000,
    CHAT_FLAG_NEWCOMER   = 0x2000,
    CHAT_FLAG_CENSORED   = 0x4000,
    CHAT_FLAG_TIMERUNNING= 0x8000
};

enum ChatLinkColors : uint32
{
    CHAT_LINK_COLOR_TRADE           = 0xffffd000,   // orange
    CHAT_LINK_COLOR_TALENT          = 0xff71d5ff,   // bright blue
    CHAT_LINK_COLOR_SPELL           = 0xff71d5ff,   // bright blue
    CHAT_LINK_COLOR_ENCHANT         = 0xffffd000,   // orange
    CHAT_LINK_COLOR_ACHIEVEMENT     = 0xffffff00,
    CHAT_LINK_COLOR_ARTIFACT_POWER  = 0xff71d5ff,
    CHAT_LINK_COLOR_BATTLE_PET_ABIL = 0xff4e96f7,
    CHAT_LINK_COLOR_GARR_ABILITY    = 0xff4e96f7,
    CHAT_LINK_COLOR_INSTANCE_LOCK   = 0xffff8000,
    CHAT_LINK_COLOR_JOURNAL         = 0xff66bbff,
    CHAT_LINK_COLOR_TRANSMOG        = 0xffff80ff,
};

enum class ChatMessageResult : uint32
{
    Ok,
    HandledCommand,
    DisallowedLanguage,
    InvalidLanguage,
    LanguageNotLearned,
    Muted,
    SilencedByGM,
    MessageTooLong,
    MessageEmpty,
    MessageHasInvalidCharacters,
    MalformedHyperlinks,
    PlayerDead,
    LevelTooLow,
    NoWhisperTarget,
    WhisperTargetWrongFaction,
    NotInGroup,
    NotLeaderOrAssistant,
    RaidWarningInPartyDisabled,
    ChannelIsReadOnly
};

// Values from ItemPetFood (power of (value-1) used for compare with CreatureFamilyEntry.PetFoodMask
enum PetDiet
{
    PET_DIET_MEAT     = 1,
    PET_DIET_FISH     = 2,
    PET_DIET_CHEESE   = 3,
    PET_DIET_BREAD    = 4,
    PET_DIET_FUNGAS   = 5,
    PET_DIET_FRUIT    = 6,
    PET_DIET_RAW_MEAT = 7,
    PET_DIET_RAW_FISH = 8
};

#define MAX_PET_DIET 9

#define CHAIN_SPELL_JUMP_RADIUS 8

enum GuildLogs
{
    GUILD_BANKLOG_MAX_RECORDS   = 25,
    GUILD_EVENTLOG_MAX_RECORDS  = 100,
    GUILD_NEWSLOG_MAX_RECORDS   = 250
};

enum AiReaction
{
    AI_REACTION_ALERT    = 0,                               // pre-aggro (used in client packet handler)
    AI_REACTION_FRIENDLY = 1,                               // (NOT used in client packet handler)
    AI_REACTION_HOSTILE  = 2,                               // sent on every attack, triggers aggro sound (used in client packet handler)
    AI_REACTION_AFRAID   = 3,                               // seen for polymorph (when AI not in control of self?) (NOT used in client packet handler)
    AI_REACTION_DESTROY  = 4                                // used on object destroy (NOT used in client packet handler)
};

// Diminishing Returns Types
enum DiminishingReturnsType
{
    DRTYPE_NONE         = 0,                                // this spell is not diminished, but may have its duration limited
    DRTYPE_PLAYER       = 1,                                // this spell is diminished only when applied on players
    DRTYPE_ALL          = 2                                 // this spell is diminished in every case
};

// Diminishing Return Groups
enum DiminishingGroup : uint16
{
    DIMINISHING_NONE             = 0,
    DIMINISHING_ROOT             = 1,
    DIMINISHING_STUN             = 2,
    DIMINISHING_INCAPACITATE     = 3,
    DIMINISHING_DISORIENT        = 4,
    DIMINISHING_SILENCE          = 5,
    DIMINISHING_AOE_KNOCKBACK    = 6,
    DIMINISHING_TAUNT            = 7,
    DIMINISHING_LIMITONLY        = 8,

    DIMINISHING_MAX
};

enum SummonCategory
{
    SUMMON_CATEGORY_WILD        = 0,
    SUMMON_CATEGORY_ALLY        = 1,
    SUMMON_CATEGORY_PET         = 2,
    SUMMON_CATEGORY_PUPPET      = 3,
    SUMMON_CATEGORY_VEHICLE     = 4,
    SUMMON_CATEGORY_UNK         = 5  // as of patch 3.3.5a only Bone Spike in Icecrown Citadel
                                     // uses this category
};

enum class SummonTitle : int32
{
    None                = 0,
    Pet                 = 1,
    Guardian            = 2,
    Minion              = 3,
    Totem               = 4,
    Companion           = 5,
    Runeblade           = 6,
    Construct           = 7,
    Opponent            = 8,    // Related to phases and DK prequest line (3.3.5a)
    Vehicle             = 9,
    Mount               = 10,   // Oculus and Argent Tournament vehicles (3.3.5a)
    Lightwell           = 11,
    Butler              = 12,
    aka                 = 13,
    Gateway             = 14,
    Hatred              = 15,
    Statue              = 16,
    Spirit              = 17,
    WarBanner           = 18,
    Heartwarmer         = 19,
    HiredBy             = 20,
    PurchasedBy         = 21,
    Pride               = 22,
    TwistedImage        = 23,
    NoodleCart          = 24,
    InnerDemon          = 25,
    Bodyguard           = 26,
    Name                = 27,
    Squire              = 28,
    Champion            = 29,
    TheBetrayer         = 30,
    EruptingReflection  = 31,
    HopelessReflection  = 32,
    MalignantReflection = 33,
    WailingReflection   = 34,
    Assistant           = 35,
    Enforcer            = 36,
    Recruit             = 37,
    Admirer             = 38,
    EvilTwin            = 39,
    Greed               = 40,
    LostMind            = 41,
    ServantOfNZoth      = 44
};

enum SummonSlot : int32
{
    SUMMON_SLOT_ANY_TOTEM           = -1,
    SUMMON_SLOT_PET                 = 0,
    SUMMON_SLOT_TOTEM               = 1,
    SUMMON_SLOT_TOTEM_2             = 2,
    SUMMON_SLOT_TOTEM_3             = 3,
    SUMMON_SLOT_TOTEM_4             = 4,
    SUMMON_SLOT_MINIPET             = 5,
    SUMMON_SLOT_QUEST               = 6,

    MAX_SUMMON_SLOT
};

#define MAX_TOTEM_SLOT      5
#define MAX_GAMEOBJECT_SLOT 4

enum EventId
{
    EVENT_CHARGE            = 1003,
    EVENT_JUMP              = 1004,

    /// Special charge event which is used for charge spells that have explicit targets
    /// and had a path already generated - using it in PointMovementGenerator will not
    /// create a new spline and launch it
    EVENT_CHARGE_PREPATH    = 1005,

    EVENT_FACE              = 1006,
    EVENT_VEHICLE_BOARD     = 1007,
    EVENT_VEHICLE_EXIT      = 1008,
    EVENT_ASSIST_MOVE       = 1009,
};

enum ResponseCodes
{
    RESPONSE_SUCCESS                                       = 0,
    RESPONSE_FAILURE                                       = 1,
    RESPONSE_CANCELLED                                     = 2,
    RESPONSE_DISCONNECTED                                  = 3,
    RESPONSE_FAILED_TO_CONNECT                             = 4,
    RESPONSE_CONNECTED                                     = 5,
    RESPONSE_VERSION_MISMATCH                              = 6,

    CSTATUS_CONNECTING                                     = 7,
    CSTATUS_NEGOTIATING_SECURITY                           = 8,
    CSTATUS_NEGOTIATION_COMPLETE                           = 9,
    CSTATUS_NEGOTIATION_FAILED                             = 10,
    CSTATUS_AUTHENTICATING                                 = 11,

    REALM_LIST_IN_PROGRESS                                 = 12,
    REALM_LIST_SUCCESS                                     = 13,
    REALM_LIST_FAILED                                      = 14,
    REALM_LIST_INVALID                                     = 15,
    REALM_LIST_REALM_NOT_FOUND                             = 16,

    ACCOUNT_CREATE_IN_PROGRESS                             = 17,
    ACCOUNT_CREATE_SUCCESS                                 = 18,
    ACCOUNT_CREATE_FAILED                                  = 19,

    CHAR_LIST_RETRIEVING                                   = 20,
    CHAR_LIST_RETRIEVED                                    = 21,
    CHAR_LIST_FAILED                                       = 22,

    CHAR_CREATE_IN_PROGRESS                                = 23,
    CHAR_CREATE_SUCCESS                                    = 24,
    CHAR_CREATE_ERROR                                      = 25,
    CHAR_CREATE_FAILED                                     = 26,
    CHAR_CREATE_NAME_IN_USE                                = 27,
    CHAR_CREATE_DISABLED                                   = 28,
    CHAR_CREATE_PVP_TEAMS_VIOLATION                        = 29,
    CHAR_CREATE_SERVER_LIMIT                               = 30,
    CHAR_CREATE_ACCOUNT_LIMIT                              = 31,
    CHAR_CREATE_SERVER_QUEUE                               = 32,
    CHAR_CREATE_ONLY_EXISTING                              = 33,
    CHAR_CREATE_EXPANSION                                  = 34,
    CHAR_CREATE_EXPANSION_CLASS                            = 35,
    CHAR_CREATE_CHARACTER_IN_GUILD                         = 36,
    CHAR_CREATE_RESTRICTED_RACECLASS                       = 37,
    CHAR_CREATE_CHARACTER_CHOOSE_RACE                      = 38,
    CHAR_CREATE_CHARACTER_ARENA_LEADER                     = 39,
    CHAR_CREATE_CHARACTER_ARENA_TEAM                       = 40,
    CHAR_CREATE_CHARACTER_DELETE_MAIL                      = 41,
    CHAR_CREATE_CHARACTER_SWAP_FACTION                     = 42,
    CHAR_CREATE_CHARACTER_RACE_ONLY                        = 43,
    CHAR_CREATE_CHARACTER_GOLD_LIMIT                       = 44,
    CHAR_CREATE_FORCE_LOGIN                                = 45,
    CHAR_CREATE_TRIAL                                      = 46,
    CHAR_CREATE_TIMEOUT                                    = 47,
    CHAR_CREATE_THROTTLE                                   = 48,
    CHAR_CREATE_ALLIED_RACE_ACHIEVEMENT                    = 49,
    CHAR_CREATE_CHARACTER_IN_COMMUNITY                     = 50,
    CHAR_CREATE_NEW_PLAYER                                 = 51,
    CHAR_CREATE_NAME_RESERVATION_FULL                      = 52,
    CHAR_CREATE_DRACTHYR_DUPLICATE                         = 53,
    CHAR_CREATE_DRACTHYR_LEVEL_REQUIREMENT                 = 54,
    CHAR_CREATE_DEATHKNIGHT_DUPLICATE                      = 55,
    CHAR_CREATE_DEATHKNIGHT_LEVEL_REQUIREMENT              = 56,
    CHAR_CREATE_CLASS_TRIAL_NEWCOMER                       = 57,
    CHAR_CREATE_CLASS_TRIAL_THROTTLE_HOUR                  = 58,
    CHAR_CREATE_CLASS_TRIAL_THROTTLE_DAY                   = 59,
    CHAR_CREATE_CLASS_TRIAL_THROTTLE_WEEK                  = 60,
    CHAR_CREATE_CLASS_TRIAL_THROTTLE_ACCOUNT               = 61,
    CHAR_CREATE_FACTION_BALANCE                            = 62,
    CHAR_CREATE_TIMERUNNING                                = 63,

    CHAR_DELETE_IN_PROGRESS                                = 64,
    CHAR_DELETE_SUCCESS                                    = 65,
    CHAR_DELETE_FAILED                                     = 66,
    CHAR_DELETE_FAILED_CHARACTER_SERVICE_PENDING           = 67,
    CHAR_DELETE_FAILED_GUILD_LEADER                        = 68,
    CHAR_DELETE_FAILED_ARENA_CAPTAIN                       = 69,
    CHAR_DELETE_FAILED_HAS_HEIRLOOM_OR_MAIL                = 70,
    CHAR_DELETE_FAILED_DEPRECATED1                         = 71,
    CHAR_DELETE_FAILED_HAS_WOW_TOKEN                       = 72,
    CHAR_DELETE_FAILED_DEPRECATED2                         = 73,
    CHAR_DELETE_FAILED_COMMUNITY_OWNER                     = 74,

    CHAR_LOGIN_IN_PROGRESS                                 = 75,
    CHAR_LOGIN_SUCCESS                                     = 76,
    CHAR_LOGIN_NO_WORLD                                    = 77,
    CHAR_LOGIN_DUPLICATE_CHARACTER                         = 78,
    CHAR_LOGIN_NO_INSTANCES                                = 79,
    CHAR_LOGIN_FAILED                                      = 80,
    CHAR_LOGIN_DISABLED                                    = 81,
    CHAR_LOGIN_NO_CHARACTER                                = 82,
    CHAR_LOGIN_LOCKED_FOR_TRANSFER                         = 83,
    CHAR_LOGIN_LOCKED_BY_BILLING                           = 84,
    CHAR_LOGIN_LOCKED_BY_MOBILE_AH                         = 85,
    CHAR_LOGIN_TEMPORARY_GM_LOCK                           = 86,
    CHAR_LOGIN_LOCKED_BY_CHARACTER_UPGRADE                 = 87,
    CHAR_LOGIN_LOCKED_BY_REVOKED_CHARACTER_UPGRADE         = 88,
    CHAR_LOGIN_LOCKED_BY_REVOKED_VAS_TRANSACTION           = 89,
    CHAR_LOGIN_LOCKED_BY_RESTRICTION                       = 90,
    CHAR_LOGIN_LOCKED_FOR_REALM_PLAYTYPE                   = 91,

    CHAR_NAME_SUCCESS                                      = 92,
    CHAR_NAME_FAILURE                                      = 93,
    CHAR_NAME_NO_NAME                                      = 94,
    CHAR_NAME_TOO_SHORT                                    = 95,
    CHAR_NAME_TOO_LONG                                     = 96,
    CHAR_NAME_INVALID_CHARACTER                            = 97,
    CHAR_NAME_MIXED_LANGUAGES                              = 98,
    CHAR_NAME_PROFANE                                      = 99,
    CHAR_NAME_RESERVED                                     = 100,
    CHAR_NAME_INVALID_APOSTROPHE                           = 101,
    CHAR_NAME_MULTIPLE_APOSTROPHES                         = 102,
    CHAR_NAME_THREE_CONSECUTIVE                            = 103,
    CHAR_NAME_INVALID_SPACE                                = 104,
    CHAR_NAME_CONSECUTIVE_SPACES                           = 105,
    CHAR_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS        = 106,
    CHAR_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END = 107,
    CHAR_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME            = 108,
    CHAR_NAME_SPACES_DISALLOWED                            = 109,
};

enum CharacterUndeleteResult
{
    CHARACTER_UNDELETE_RESULT_OK                               = 0,
    CHARACTER_UNDELETE_RESULT_ERROR_COOLDOWN                   = 1,
    CHARACTER_UNDELETE_RESULT_ERROR_CHAR_CREATE                = 2,
    CHARACTER_UNDELETE_RESULT_ERROR_DISABLED                   = 3,
    CHARACTER_UNDELETE_RESULT_ERROR_NAME_TAKEN_BY_THIS_ACCOUNT = 4,
    CHARACTER_UNDELETE_RESULT_ERROR_UNKNOWN                    = 5
};

enum ComplaintStatus : uint8
{
    COMPLAINT_DISABLED                      = 0,
    COMPLAINT_ENABLED_WITHOUT_AUTO_IGNORE   = 1,
    COMPLAINT_ENABLED_WITH_AUTO_IGNORE      = 2
};

/// Ban function modes
enum BanMode
{
    BAN_ACCOUNT,
    BAN_CHARACTER,
    BAN_IP
};

/// Ban function return codes
enum BanReturn
{
    BAN_SUCCESS,
    BAN_SYNTAX_ERROR,
    BAN_NOTFOUND,
    BAN_EXISTS
};

enum PvPTeamId : uint8
{
    PVP_TEAM_HORDE       = 0, // Battleground: Horde,    Arena: Green
    PVP_TEAM_ALLIANCE    = 1, // Battleground: Alliance, Arena: Gold
    PVP_TEAM_NEUTRAL     = 2  // Battleground: Neutral,  Arena: None
};

uint8 constexpr PVP_TEAMS_COUNT = 2;

// Indexes of BattlemasterList.db2 (9.0.2.37176)
enum BattlegroundTypeId : uint32
{
    BATTLEGROUND_TYPE_NONE      = 0,        // None
    BATTLEGROUND_AV             = 1,        // Alterac Valley
    BATTLEGROUND_WS             = 2,        // Warsong Gulch
    BATTLEGROUND_AB             = 3,        // Arathi Basin
    BATTLEGROUND_NA             = 4,        // Nagrand Arena
    BATTLEGROUND_BE             = 5,        // Blade's Edge Arena
    BATTLEGROUND_AA             = 6,        // All Arenas
    BATTLEGROUND_EY             = 7,        // Eye of the Storm
    BATTLEGROUND_RL             = 8,        // Ruins of Lordaernon
    BATTLEGROUND_SA             = 9,        // Strand of the Ancients
    BATTLEGROUND_DS             = 10,       // Dalaran Sewers
    BATTLEGROUND_RV             = 11,       // The Ring of Valor
    BATTLEGROUND_IC             = 30,       // Isle of Conquest
    BATTLEGROUND_RB             = 32,       // Random Battleground
    BATTLEGROUND_RATED_10_VS_10 = 100,      // Rated Battleground 10 vs 10
    BATTLEGROUND_RATED_15_VS_15 = 101,      // Rated Battleground 15 vs 15
    BATTLEGROUND_RATED_25_VS_25 = 102,      // Rated Battleground 25 vs 25
    BATTLEGROUND_TP             = 108,      // Twin Peaks
    BATTLEGROUND_BFG            = 120,      // Battle For Gilneas
    // 656 = "Rated Eye of the Storm"
    BATTLEGROUND_TK             = 699,      // Temple of Kotmogu
    // 706 = "CTF3"
    BATTLEGROUND_SM             = 708,      // Silvershard Mines
    BATTLEGROUND_TVA            = 719,      // Tol'Viron Arena
    BATTLEGROUND_DG             = 754,      // Deepwind Gorge
    BATTLEGROUND_TTP            = 757,      // The Tiger's Peak
    BATTLEGROUND_SS_VS_TM       = 789,      // Southshore vs. Tarren Mill
    BATTLEGROUND_SMALL_D        = 803,      // Small Battleground D
    BATTLEGROUND_BRH            = 808,      // Black Rook Hold Arena
    // 809 = "New Nagrand Arena (Legion)"
    BATTLEGROUND_AF             = 816,      // Ashamane's Fall
    // 844 = "New Blade's Edge Arena (Legion)"
    BATTLEGROUND_BRAWL_TBG      = 846,      // Brawl - The Battle for Gilneas (Old City Map)
    BATTLEGROUND_BRAWL_ABW      = 847,      // Brawl - Arathi Basin Winter
    // 848 = "AI Test - Arathi Basin"
    BATTLEGROUND_BRAWL_DD       = 849,      // Brawl - Deepwind Dunk
    BATTLEGROUND_BRAWL_SPS      = 853,      // Brawl - Shadow-Pan Showdown
    // 856 = "[TEMP] RaceTrackBG"
    BATTLEGROUND_BR             = 857,      // Blackrock
    BATTLEGROUND_BRAWL_TH       = 858,      // Brawl - Temple of Hotmogu
    BATTLEGROUND_BRAWL_GL       = 859,      // Brawl - Gravity Lapse
    BATTLEGROUND_BRAWL_DD2      = 860,      // Brawl - Deepwind Dunk
    BATTLEGROUND_BRAWL_WS       = 861,      // Brawl - Warsong Scramble
    BATTLEGROUND_BRAWL_EH       = 862,      // Brawl - Eye of the Horn
    BATTLEGROUND_BRAWL_AA       = 866,      // Brawl - All Arenas
    BATTLEGROUND_RL2            = 868,      // Ruins of Lordaeron
    BATTLEGROUND_DS2            = 869,      // Dalaran Sewers
    BATTLEGROUND_TVA2           = 870,      // Tol'Viron Arena
    BATTLEGROUND_TTP2           = 871,      // The Tiger's Peak
    BATTLEGROUND_BRHA2          = 872,      // Black Rook Hold Arena
    BATTLEGROUND_NA2            = 873,      // Nagrand Arena
    BATTLEGROUND_AF2            = 874,      // Ashamane's Fall
    BATTLEGROUND_BEA2           = 875,      // Blade's Edge Arena
    // 878 = "AI Test - Warsong Gulch"
    BATTLEGROUND_BRAWL_DS       = 879,      // Brawl - Deep Six
    BATTLEGROUND_BRAWL_AB       = 880,      // Brawl - Arathi Basin
    BATTLEGROUND_BRAWL_DG       = 881,      // Brawl - Deepwind Gorge
    BATTLEGROUND_BRAWL_ES       = 882,      // Brawl - Eye of the Storm
    BATTLEGROUND_BRAWL_SM       = 883,      // Brawl - Silvershard Mines
    BATTLEGROUND_BRAWL_TK       = 884,      // Brawl - Temple of Kotmogue
    BATTLEGROUND_BRAWL_TBG2     = 885,      // Brawl - The Battle for Gilneas
    BATTLEGROUND_BRAWL_WG       = 886,      // Brawl - Warsong Gulch
    BATTLEGROUND_CI             = 887,      // Cooking: Impossible
    BATTLEGROUND_DOM_SS         = 890,      // Domination - Seething Strand
    // 893 = "8.0 BG Temp"
    BATTLEGROUND_SS             = 894,      // Seething Shore
    BATTLEGROUND_HP             = 897,      // Hooking Point
    BATTLEGROUND_RANDOM_EPIC    = 901,      // Random Epic Battleground
    BATTLEGROUND_TTP3           = 902,      // The Tiger's Peak
    BATTLEGROUND_MB             = 903,      // Mugambala
    BATTLEGROUND_BRAWL_AA2      = 904,      // Brawl - All Arenas
    BATTLEGROUND_BRAWL_AASH     = 905,      // Brawl - All Arenas - Stocked House
    BATTLEGROUND_AF3            = 906,      // Ashamane's Fall
    BATTLEGROUND_BEA3           = 907,      // Blade's Edge Arena
    BATTLEGROUND_BE2            = 908,      // Blade's Edge
    BATTLEGROUND_DS3            = 909,      // Dalaran Sewers
    BATTLEGROUND_NA3            = 910,      // Nagrand Arena
    BATTLEGROUND_RL3            = 911,      // Ruins of Lordaeron
    BATTLEGROUND_TVA3           = 912,      // Tol'Viron Arena
    BATTLEGROUND_BRHA3          = 913,      // Black Rook Hold Arena
    BATTLEGROUND_WG_CTF         = 1014,     // Warsong Gulch Capture the Flag
    BATTLEGROUND_EB_BW          = 1017,     // Epic Battleground - Battle for Wintergrasp
    BATTLEGROUND_DOM_AB         = 1018,     // Domination - Arathi Basin
    BATTLEGROUND_AB_CS          = 1019,     // Arathi Basin Comp Stomp
    BATTLEGROUND_EB_A           = 1020,     // Epic Battleground - Ashran
    BATTLEGROUND_CA             = 1021,     // Classic Ashran (Endless)
    BATTLEGROUND_BRAWL_AB2      = 1022,     // Brawl - Arathi Basin
    BATTLEGROUND_TR             = 1025,     // The Robodrome (Arena)
    BATTLEGROUND_RANDOM_BG      = 1029,     // Random Battleground
    BATTLEGROUND_EB_BW2         = 1030,     // Epic Battleground - Battle for Wintergrasp
    // 1031 = "Programmer Map - Battlefield"
    BATTLEGROUND_KR             = 1033,     // Korrak's Revenge
    BATTLEGROUND_EPIC_BG_WF     = 1036,     // Epic Battleground - Warfront Arathi (PvP)
    BATTLEGROUND_DOM_DG         = 1037,     // Domination - Deepwind Gorge
    BATTLEGROUND_DOM_DG2        = 1039,     // Domination - Deepwind Gorge
    BATTLEGROUND_ED             = 1041,     // Empyrean Domain
};

#define MAX_BATTLEGROUND_TYPE_ID 845

enum BattlefieldBattleId : uint8
{
    BATTLEFIELD_BATTLEID_WINTERGRASP = 1, // Wintergrasp battle
    BATTLEFIELD_BATTLEID_TOL_BARAD = 2, // Tol barad battle
    BATTLEFIELD_BATTLEID_MAX
};

enum MailResponseType
{
    MAIL_SEND               = 0,
    MAIL_MONEY_TAKEN        = 1,
    MAIL_ITEM_TAKEN         = 2,
    MAIL_RETURNED_TO_SENDER = 3,
    MAIL_DELETED            = 4,
    MAIL_MADE_PERMANENT     = 5
};

enum MailResponseResult
{
    MAIL_OK                            = 0,
    MAIL_ERR_EQUIP_ERROR               = 1,
    MAIL_ERR_CANNOT_SEND_TO_SELF       = 2,
    MAIL_ERR_NOT_ENOUGH_MONEY          = 3,
    MAIL_ERR_RECIPIENT_NOT_FOUND       = 4,
    MAIL_ERR_NOT_YOUR_TEAM             = 5,
    MAIL_ERR_INTERNAL_ERROR            = 6,
    MAIL_ERR_DISABLED_FOR_TRIAL_ACC    = 14,
    MAIL_ERR_RECIPIENT_CAP_REACHED     = 15,
    MAIL_ERR_CANT_SEND_WRAPPED_COD     = 16,
    MAIL_ERR_MAIL_AND_CHAT_SUSPENDED   = 17,
    MAIL_ERR_TOO_MANY_ATTACHMENTS      = 18,
    MAIL_ERR_MAIL_ATTACHMENT_INVALID   = 19,
    MAIL_ERR_ITEM_HAS_EXPIRED          = 21
};

// EnumUtils: DESCRIBE THIS
enum SpellFamilyNames : uint8
{
    SPELLFAMILY_GENERIC         = 0,  // TITLE Generic
    SPELLFAMILY_UNK1            = 1,  // TITLE Unk1 (events, holidays, ...)
    // 2 - unused
    SPELLFAMILY_MAGE            = 3,  // TITLE Mage
    SPELLFAMILY_WARRIOR         = 4,  // TITLE Warrior
    SPELLFAMILY_WARLOCK         = 5,  // TITLE Warlock
    SPELLFAMILY_PRIEST          = 6,  // TITLE Priest
    SPELLFAMILY_DRUID           = 7,  // TITLE Druid
    SPELLFAMILY_ROGUE           = 8,  // TITLE Rogue
    SPELLFAMILY_HUNTER          = 9,  // TITLE Hunter
    SPELLFAMILY_PALADIN         = 10, // TITLE Paladin
    SPELLFAMILY_SHAMAN          = 11, // TITLE Shaman
    SPELLFAMILY_UNK2            = 12, // TITLE Unk2 (Silence resistance?)
    SPELLFAMILY_POTION          = 13, // TITLE Potion
    // 14 - unused
    SPELLFAMILY_DEATHKNIGHT     = 15, // TITLE Death Knight
    // 16 - unused
    SPELLFAMILY_PET             = 17, // TITLE Pet
    SPELLFAMILY_TOTEMS          = 50,
    SPELLFAMILY_MONK            = 53,
    SPELLFAMILY_WARLOCK_PET     = 57,
    SPELLFAMILY_UNK66           = 66,
    SPELLFAMILY_UNK71           = 71,
    SPELLFAMILY_UNK78           = 78,
    SPELLFAMILY_UNK91           = 91,
    SPELLFAMILY_UNK100          = 100,
    SPELLFAMILY_DEMON_HUNTER    = 107,
    SPELLFAMILY_EVOKER          = 224
};

enum TradeStatus
{
    TRADE_STATUS_PLAYER_BUSY           = 0,
    TRADE_STATUS_PROPOSED              = 1,
    TRADE_STATUS_INITIATED             = 2,
    TRADE_STATUS_CANCELLED             = 3,
    TRADE_STATUS_ACCEPTED              = 4,
    TRADE_STATUS_ALREADY_TRADING       = 5,
    TRADE_STATUS_NO_TARGET             = 6,
    TRADE_STATUS_UNACCEPTED            = 7,
    TRADE_STATUS_COMPLETE              = 8,
    TRADE_STATUS_STATE_CHANGED         = 9,
    TRADE_STATUS_TOO_FAR_AWAY          = 10,
    TRADE_STATUS_WRONG_FACTION         = 11,
    TRADE_STATUS_FAILED                = 12,
    TRADE_STATUS_PETITION              = 13,
    TRADE_STATUS_PLAYER_IGNORED        = 14,
    TRADE_STATUS_STUNNED               = 15,
    TRADE_STATUS_TARGET_STUNNED        = 16,
    TRADE_STATUS_DEAD                  = 17,
    TRADE_STATUS_TARGET_DEAD           = 18,
    TRADE_STATUS_LOGGING_OUT           = 19,
    TRADE_STATUS_TARGET_LOGGING_OUT    = 20,
    TRADE_STATUS_RESTRICTED_ACCOUNT    = 21,
    TRADE_STATUS_WRONG_REALM           = 22,
    TRADE_STATUS_NOT_ON_TAPLIST        = 23,
    TRADE_STATUS_CURRENCY_NOT_TRADABLE = 24,
    TRADE_STATUS_NOT_ENOUGH_CURRENCY   = 25,
};

enum XPColorChar : uint8
{
    XP_RED,
    XP_ORANGE,
    XP_YELLOW,
    XP_GREEN,
    XP_GRAY
};

enum RemoveMethod : uint8
{
    GROUP_REMOVEMETHOD_DEFAULT  = 0,
    GROUP_REMOVEMETHOD_KICK     = 1,
    GROUP_REMOVEMETHOD_LEAVE    = 2,
    GROUP_REMOVEMETHOD_KICK_LFG = 3
};

enum ActivateTaxiReply
{
    ERR_TAXIOK                      = 0,
    ERR_TAXIUNSPECIFIEDSERVERERROR  = 1,
    ERR_TAXINOSUCHPATH              = 2,
    ERR_TAXINOTENOUGHMONEY          = 3,
    ERR_TAXITOOFARAWAY              = 4,
    ERR_TAXINOVENDORNEARBY          = 5,
    ERR_TAXINOTVISITED              = 6,
    ERR_TAXIPLAYERBUSY              = 7,
    ERR_TAXIPLAYERALREADYMOUNTED    = 8,
    ERR_TAXIPLAYERSHAPESHIFTED      = 9,
    ERR_TAXIPLAYERMOVING            = 10,
    ERR_TAXISAMENODE                = 11,
    ERR_TAXINOTSTANDING             = 12
};

enum TaxiNodeStatus
{
    TAXISTATUS_NONE             = 0,
    TAXISTATUS_LEARNED          = 1,
    TAXISTATUS_UNLEARNED        = 2,
    TAXISTATUS_NOT_ELIGIBLE     = 3,
};

enum ProfessionUI
{
    MAX_PRIMARY_PROFESSIONS = 2,
    MAX_SECONDARY_SKILLS    = 5,
    BASE_PARENT_TIER_INDEX  = 4
};

enum DuelCompleteType : uint8
{
    DUEL_INTERRUPTED = 0,
    DUEL_WON         = 1,
    DUEL_FLED        = 2
};

struct BattlegroundQueueTypeId
{
    uint16 BattlemasterListId;
    uint8 Type;
    bool Rated;
    uint8 TeamSize;

    static constexpr BattlegroundQueueTypeId FromPacked(uint64 packedQueueId)
    {
        return { uint16(packedQueueId & 0xFFFF), uint8((packedQueueId >> 16) & 0xF), ((packedQueueId >> 20) & 1) != 0, uint8((packedQueueId >> 24) & 0x3F) };
    }

    constexpr uint64 GetPacked() const
    {
        return uint64(BattlemasterListId)
            | (uint64(Type & 0xF) << 16)
            | (uint64(Rated ? 1 : 0) << 20)
            | (uint64(TeamSize & 0x3F) << 24)
            | UI64LIT(0x1F10000000000000);
    }

    constexpr bool operator==(BattlegroundQueueTypeId const& right) const = default;

    constexpr std::strong_ordering operator<=>(BattlegroundQueueTypeId const& right) const = default;
};

constexpr BattlegroundQueueTypeId BATTLEGROUND_QUEUE_NONE = { 0, 0, false, 0 };

enum GroupJoinBattlegroundResult
{
    ERR_BATTLEGROUND_NONE                           = 0,
    ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS           = 2,        // You cannot join the battleground yet because you or one of your party members is flagged as a Deserter.
    ERR_ARENA_TEAM_PARTY_SIZE                       = 3,        // Incorrect party size for this arena.
    ERR_BATTLEGROUND_TOO_MANY_QUEUES                = 4,        // You can only be queued for 2 battles at once
    ERR_BATTLEGROUND_CANNOT_QUEUE_FOR_RATED         = 5,        // You cannot queue for a rated match while queued for other battles
    ERR_BATTLEDGROUND_QUEUED_FOR_RATED              = 6,        // You cannot queue for another battle while queued for a rated arena match
    ERR_BATTLEGROUND_TEAM_LEFT_QUEUE                = 7,        // Your team has left the arena queue
    ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND            = 8,        // You can't do that in a battleground.
    ERR_BATTLEGROUND_JOIN_XP_GAIN                   = 9,        // Cannot join as a group unless all the members of your party have the same XP gain setting.
    ERR_BATTLEGROUND_JOIN_RANGE_INDEX               = 10,       // Cannot join the queue unless all members of your party are in the same battleground level range.
    ERR_BATTLEGROUND_JOIN_TIMED_OUT                 = 11,       // %s was unavailable to join the queue. (ObjectGuid exist in client cache)
    //ERR_BATTLEGROUND_JOIN_TIMED_OUT               = 12,       // same as 11
    //ERR_BATTLEGROUND_TEAM_LEFT_QUEUE              = 13,       // same as 7
    ERR_LFG_CANT_USE_BATTLEGROUND                   = 14,       // You cannot queue for a battleground or arena while using the dungeon system.
    ERR_IN_RANDOM_BG                                = 15,       // Can't do that while in a Random Battleground queue.
    ERR_IN_NON_RANDOM_BG                            = 16,       // Can't queue for Random Battleground while in another Battleground queue.
    ERR_BG_DEVELOPER_ONLY                           = 17,       // This battleground is only available for developer testing at this time.
    ERR_BATTLEGROUND_INVITATION_DECLINED            = 18,       // Your War Game invitation has been declined
    ERR_MEETING_STONE_NOT_FOUND                     = 19,       // Player not found.
    ERR_WARGAME_REQUEST_FAILURE                     = 20,       // War Game request failed
    ERR_BATTLEFIELD_TEAM_PARTY_SIZE                 = 22,       // Incorrect party size for this battlefield.
    ERR_NOT_ON_TOURNAMENT_REALM                     = 23,       // Not available on a Tournament Realm.
    ERR_BATTLEGROUND_PLAYERS_FROM_DIFFERENT_REALMS  = 24,       // You cannot queue for a battleground while players from different realms are in your party.
    ERR_BATTLEGROUND_JOIN_LEVELUP                   = 33,       // You have been removed from a PvP queue because you have gained a level.
    ERR_REMOVE_FROM_PVP_QUEUE_FACTION_CHANGE        = 34,       // You have been removed from a PvP Queue because you changed your faction.
    ERR_BATTLEGROUND_JOIN_FAILED                    = 35,       // Join as a group failed
    ERR_BATTLEGROUND_DUPE_QUEUE                     = 43,       // Someone in your group is already queued for that.
    ERR_BATTLEGROUND_JOIN_NO_VALID_SPEC_FOR_ROLE    = 44,       // Role check failed because one of your party members selected an invalid role.
    ERR_BATTLEGROUND_JOIN_RESPEC                    = 45,       // You have been removed from a PvP queue because your specialization changed.
    ERR_ALREADY_USING_LFG_LIST                      = 46,       // You can't do that while using Premade Groups.
    ERR_BATTLEGROUND_JOIN_MUST_COMPLETE_QUEST       = 47,       // You have been removed from a PvP queue because someone is missing required quest completion.
    ERR_BATTLERGOUND_RESTRICTED_ACCOUNT             = 48,       // Free Trial accounts cannot perform that action
    ERR_BATTLEGROUND_JOIN_MERCENARY                 = 49,       // Cannot join as a group unless all the members of your party are flagged as a mercenary.
    ERR_BATTLEGROUND_JOIN_TOO_MANY_HEALERS          = 51,       // You can not enter this bracket of arena with more than one healer. / You can not enter a rated battleground with more than three healers.
    ERR_BATTLEGROUND_JOIN_TOO_MANY_TANKS            = 52,       // You can not enter this bracket of arena with more than one tank.
    ERR_BATTLEGROUND_JOIN_TOO_MANY_DAMAGE           = 53,       // You can not enter this bracket of arena with more than two damage dealers.
    ERR_GROUP_JOIN_BATTLEGROUND_DEAD                = 57,       // You cannot join the battleground because you or one of your party members is dead.
    ERR_BATTLEGROUND_JOIN_REQUIRES_LEVEL            = 58,       // Tournament rules requires all participants to be max level.
    ERR_BATTLEGROUND_JOIN_DISQUALIFIED              = 59,       // %s has been disqualified from ranked play in this bracket.
    ERR_ARENA_EXPIRED_CAIS                          = 60,       // You may not queue while one or more of your team members is under the effect of restricted play.
    ERR_SOLO_SHUFFLE_WARGAME_GROUP_SIZE             = 64,       // Exactly 6 non-spectator players must be present to begin a Solo Shuffle Wargame.
    ERR_SOLO_SHUFFLE_WARGAME_GROUP_COMP             = 65,       // Exactly 4 DPS, and either 2 Tanks or 2 Healers, must be present to begin a Solo Shuffle Wargame.
};

enum PetNameInvalidReason
{
    // custom, not send
    PET_NAME_SUCCESS                                        = 0,

    PET_NAME_INVALID                                        = 1,
    PET_NAME_NO_NAME                                        = 2,
    PET_NAME_TOO_SHORT                                      = 3,
    PET_NAME_TOO_LONG                                       = 4,
    PET_NAME_MIXED_LANGUAGES                                = 6,
    PET_NAME_PROFANE                                        = 7,
    PET_NAME_RESERVED                                       = 8,
    PET_NAME_THREE_CONSECUTIVE                              = 11,
    PET_NAME_INVALID_SPACE                                  = 12,
    PET_NAME_CONSECUTIVE_SPACES                             = 13,
    PET_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS          = 14,
    PET_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END   = 15,
    PET_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME              = 16
};

enum DungeonStatusFlag
{
    DUNGEON_STATUSFLAG_NORMAL = 0x01,
    DUNGEON_STATUSFLAG_HEROIC = 0x02,

    RAID_STATUSFLAG_10MAN_NORMAL = 0x01,
    RAID_STATUSFLAG_25MAN_NORMAL = 0x02,
    RAID_STATUSFLAG_10MAN_HEROIC = 0x04,
    RAID_STATUSFLAG_25MAN_HEROIC = 0x08
};

enum VoidStorageConstants
{
    VOID_STORAGE_UNLOCK_COST        = 100 * GOLD,
    VOID_STORAGE_STORE_ITEM_COST    = 10 * GOLD,
    VOID_STORAGE_MAX_DEPOSIT        = 9,
    VOID_STORAGE_MAX_WITHDRAW       = 9,
    VOID_STORAGE_MAX_SLOT           = 160
};

enum VoidTransferError
{
    VOID_TRANSFER_ERROR_NO_ERROR          = 0,
    VOID_TRANSFER_ERROR_INTERNAL_ERROR_1  = 1,
    VOID_TRANSFER_ERROR_INTERNAL_ERROR_2  = 2,
    VOID_TRANSFER_ERROR_FULL              = 3,
    VOID_TRANSFER_ERROR_INTERNAL_ERROR_3  = 4,
    VOID_TRANSFER_ERROR_INTERNAL_ERROR_4  = 5,
    VOID_TRANSFER_ERROR_NOT_ENOUGH_MONEY  = 6,
    VOID_TRANSFER_ERROR_INVENTORY_FULL    = 7,
    VOID_TRANSFER_ERROR_ITEM_INVALID      = 8,
    VOID_TRANSFER_ERROR_TRANSFER_UNKNOWN  = 9
};

enum class CurrencyDbFlags : uint8
{
    None                        = 0x00,
    IgnoreMaxQtyOnload          = 0x01,
    Reuse1                      = 0x02,
    InBackpack                  = 0x04,
    UnusedInUI                  = 0x08,
    Reuse2                      = 0x10,

    UnusedFlags                 = (IgnoreMaxQtyOnload | Reuse1 | Reuse2),
    ClientFlags                 = (0x1F & ~UnusedFlags)
};

DEFINE_ENUM_FLAG(CurrencyDbFlags);

enum class CurrencyDestroyReason : uint32
{
    Cheat                       = 0,
    Spell                       = 1,
    VersionUpdate               = 2,
    QuestTurnin                 = 3,
    Vendor                      = 4,
    Trade                       = 5,
    Capped                      = 6,
    Garrison                    = 7,
    DroppedToCorpse             = 8,
    BonusRoll                   = 9,
    FactionConversion           = 10,
    FulfillCraftingOrder        = 11,
    Last                        = 12
};

enum class CurrencyGainSource : uint32
{
    ConvertOldItem              = 0,
    ConvertOldPvPCurrency       = 1,
    ItemRefund                  = 2,
    QuestReward                 = 3,
    Cheat                       = 4,
    Vendor                      = 5,
    PvPKillCredit               = 6,
    PvPMetaCredit               = 7,
    PvPScriptedAward            = 8,
    Loot                        = 9,
    UpdatingVersion             = 10,
    LFGReward                   = 11,
    Trade                       = 12,
    Spell                       = 13,
    ItemDeletion                = 14,
    RatedBattleground           = 15,
    RandomBattleground          = 16,
    Arena                       = 17,
    ExceededMaxQty              = 18,
    PvPCompletionBonus          = 19,
    Script                      = 20,
    GuildBankWithdrawal         = 21,
    Pushloot                    = 22,
    GarrisonBuilding            = 23,
    PvPDrop                     = 24,
    GarrisonFollowerActivation  = 25,
    GarrisonBuildingRefund      = 26,
    GarrisonMissionReward       = 27,
    GarrisonResourceOverTime    = 28,
    QuestRewardIgnoreCaps       = 29,
    GarrisonTalent              = 30,
    GarrisonWorldQuestBonus     = 31,
    PvPHonorReward              = 32,
    BonusRoll                   = 33,
    AzeriteRespec               = 34,
    WorldQuestReward            = 35,
    WorldQuestRewardIgnoreCaps  = 36,
    FactionConversion           = 37,
    DailyQuestReward            = 38,
    DailyQuestWarModeReward     = 39,
    WeeklyQuestReward           = 40,
    WeeklyQuestWarModeReward    = 41,
    AccountCopy                 = 42,
    WeeklyRewardChest           = 43,
    GarrisonTalentTreeReset     = 44,
    DailyReset                  = 45,
    AddConduitToCollection      = 46,
    Barbershop                  = 47,
    ConvertItemsToCurrencyValue = 48,
    PvPTeamContribution         = 49,
    Transmogrify                = 50,
    AuctionDeposit              = 51,
    PlayerTrait                 = 52,
    PhBuffer_53                 = 53,
    PhBuffer_54                 = 54,
    RenownRepGain               = 55,
    CraftingOrder               = 56,
    CatalystBalancing           = 57,
    CatalystCraft               = 58,
    ProfessionInitialAward      = 59,
    PlayerTraitRefund           = 60,
    Last                        = 61
};

enum class CurrencyGainFlags : uint32
{
    None                        = 0x00,
    BonusAward                  = 0x01,
    DroppedFromDeath            = 0x02,
    FromAccountServer           = 0x04
};

DEFINE_ENUM_FLAG(CurrencyGainFlags);

enum PartyResult
{
    ERR_PARTY_RESULT_OK                 = 0,
    ERR_BAD_PLAYER_NAME_S               = 1,
    ERR_TARGET_NOT_IN_GROUP_S           = 2,
    ERR_TARGET_NOT_IN_INSTANCE_S        = 3,
    ERR_GROUP_FULL                      = 4,
    ERR_ALREADY_IN_GROUP_S              = 5,
    ERR_NOT_IN_GROUP                    = 6,
    ERR_NOT_LEADER                      = 7,
    ERR_PLAYER_WRONG_FACTION            = 8,
    ERR_IGNORING_YOU_S                  = 9,
    ERR_LFG_PENDING                     = 12,
    ERR_INVITE_RESTRICTED               = 13,
    ERR_GROUP_SWAP_FAILED               = 14,               // if (PartyOperation == PARTY_OP_SWAP) ERR_GROUP_SWAP_FAILED else ERR_INVITE_IN_COMBAT
    ERR_INVITE_UNKNOWN_REALM            = 15,
    ERR_INVITE_NO_PARTY_SERVER          = 16,
    ERR_INVITE_PARTY_BUSY               = 17,
    ERR_PARTY_TARGET_AMBIGUOUS          = 18,
    ERR_PARTY_LFG_INVITE_RAID_LOCKED    = 19,
    ERR_PARTY_LFG_BOOT_LIMIT            = 20,
    ERR_PARTY_LFG_BOOT_COOLDOWN_S       = 21,
    ERR_PARTY_LFG_BOOT_IN_PROGRESS      = 22,
    ERR_PARTY_LFG_BOOT_TOO_FEW_PLAYERS  = 23,
    ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S   = 24,
    ERR_RAID_DISALLOWED_BY_LEVEL        = 25,
    ERR_PARTY_LFG_BOOT_IN_COMBAT        = 26,
    ERR_VOTE_KICK_REASON_NEEDED         = 27,
    ERR_PARTY_LFG_BOOT_DUNGEON_COMPLETE = 28,
    ERR_PARTY_LFG_BOOT_LOOT_ROLLS       = 29,
    ERR_PARTY_LFG_TELEPORT_IN_COMBAT    = 30
};

enum DiminishingLevels
{
    DIMINISHING_LEVEL_1             = 0,
    DIMINISHING_LEVEL_2             = 1,
    DIMINISHING_LEVEL_3             = 2,
    DIMINISHING_LEVEL_IMMUNE        = 3,
    DIMINISHING_LEVEL_4             = 3,
    DIMINISHING_LEVEL_TAUNT_IMMUNE  = 4
};

enum WeaponAttackType : uint8
{
    BASE_ATTACK   = 0,
    OFF_ATTACK    = 1,
    RANGED_ATTACK = 2,
    MAX_ATTACK
};

enum CharterTypes
{
    CHARTER_TYPE_NONE           = 0,
    CHARTER_TYPE_ANY            = 10,

    GUILD_CHARTER_TYPE          = 4,
    ARENA_TEAM_CHARTER_2v2_TYPE = 2,
    ARENA_TEAM_CHARTER_3v3_TYPE = 3,
    ARENA_TEAM_CHARTER_5v5_TYPE = 5
};

enum LineOfSightChecks : uint8
{
    LINEOFSIGHT_CHECK_VMAP      = 0x1, // check static floor layout data
    LINEOFSIGHT_CHECK_GOBJECT   = 0x2, // check dynamic game object data

    LINEOFSIGHT_ALL_CHECKS      = (LINEOFSIGHT_CHECK_VMAP | LINEOFSIGHT_CHECK_GOBJECT)
};

enum TokenResult
{
    TOKEN_RESULT_SUCCESS                        = 0,
    TOKEN_RESULT_ERROR_DISABLED                 = 1,
    TOKEN_RESULT_ERROR_OTHER                    = 2,
    TOKEN_RESULT_ERROR_NONE_FOR_SALE            = 3,
    TOKEN_RESULT_ERROR_TOO_MANY_TOKENS          = 4,
    TOKEN_RESULT_SUCCESS_NO                     = 5,
    TOKEN_RESULT_ERROR_TRANSACTION_IN_PROGRESS  = 6,
    TOKEN_RESULT_ERROR_AUCTIONABLE_TOKEN_OWNED  = 7,
    TOKEN_RESULT_ERROR_TRIAL_RESTRICTED         = 8
};

enum TutorialAction : uint8
{
    TUTORIAL_ACTION_UPDATE  = 0,
    TUTORIAL_ACTION_CLEAR   = 1,
    TUTORIAL_ACTION_RESET   = 2
};

/*
enum Tutorials : uint8
{
    TUTORIAL_TALENT                   = 0,
    TUTORIAL_SPEC                     = 1,
    TUTORIAL_GLYPH                    = 2,
    TUTORIAL_SPELLBOOK                = 3,
    TUTORIAL_PROFESSIONS              = 4,
    TUTORIAL_CORE_ABILITITES          = 5,
    TUTORIAL_PET_JOURNAL              = 6,
    TUTORIAL_WHAT_HAS_CHANGED         = 7,
    TUTORIAL_GARRISON_BUILDING        = 8,
    TUTORIAL_GARRISON_MISSION_LIST    = 9,
    TUTORIAL_GARRISON_MISSION_PAGE    = 10,
    TUTORIAL_GARRISON_LANDING         = 11,
    TUTORIAL_GARRISON_ZONE_ABILITY    = 12,
    TUTORIAL_WORLD_MAP_FRAME          = 13,
    TUTORIAL_CLEAN_UP_BAGS            = 14,
    TUTORIAL_BAG_SETTINGS             = 15,
    TUTORIAL_REAGENT_BANK_UNLOCK      = 16,
    TUTORIAL_TOYBOX_FAVORITE          = 17,
    TUTORIAL_TOYBOX_MOUSEWHEEL_PAGING = 18,
    TUTORIAL_LFG_LIST                 = 19
};
*/

#define MAX_ACCOUNT_TUTORIAL_VALUES 8

enum RaidGroupReason
{
    RAID_GROUP_ERR_NONE                 = 0,
    RAID_GROUP_ERR_LOWLEVEL             = 1, // "You are too low level to enter this instance."
    RAID_GROUP_ERR_ONLY                 = 2, // "You must be in a raid group to enter this instance."
    RAID_GROUP_ERR_FULL                 = 3, // "The instance is full."
    RAID_GROUP_ERR_REQUIREMENTS_UNMATCH = 4  // "You do not meet the requirements to enter this instance."
};

enum ResetFailedReason : uint8
{
    INSTANCE_RESET_FAILED           = 0, // "Cannot reset %s.  There are players still inside the instance."
    INSTANCE_RESET_FAILED_OFFLINE   = 1, // "Cannot reset %s.  There are players offline in your party."
    INSTANCE_RESET_FAILED_ZONING    = 2  // "Cannot reset %s.  There are players in your party attempting to zone into an instance."
};

enum class GameError : uint32
{
    ERR_SYSTEM                                                      = 0,
    ERR_INTERNAL_ERROR                                              = 1,
    ERR_INV_FULL                                                    = 2,
    ERR_BANK_FULL                                                   = 3,
    ERR_CANT_EQUIP_LEVEL_I                                          = 4,
    ERR_CANT_EQUIP_SKILL                                            = 5,
    ERR_CANT_EQUIP_EVER                                             = 6,
    ERR_CANT_EQUIP_RANK                                             = 7,
    ERR_CANT_EQUIP_RATING                                           = 8,
    ERR_CANT_EQUIP_REPUTATION                                       = 9,
    ERR_PROFICIENCY_NEEDED                                          = 10,
    ERR_WRONG_SLOT                                                  = 11,
    ERR_CANT_EQUIP_NEED_TALENT                                      = 12,
    ERR_BAG_FULL                                                    = 13,
    ERR_INTERNAL_BAG_ERROR                                          = 14,
    ERR_DESTROY_NONEMPTY_BAG                                        = 15,
    ERR_BAG_IN_BAG                                                  = 16,
    ERR_TOO_MANY_SPECIAL_BAGS                                       = 17,
    ERR_TRADE_EQUIPPED_BAG                                          = 18,
    ERR_AMMO_ONLY                                                   = 19,
    ERR_NO_SLOT_AVAILABLE                                           = 20,
    ERR_WRONG_BAG_TYPE                                              = 21,
    ERR_REAGENTBAG_WRONG_SLOT                                       = 22,
    ERR_SLOT_ONLY_REAGENTBAG                                        = 23,
    ERR_REAGENTBAG_ITEM_TYPE                                        = 24,
    ERR_ITEM_MAX_COUNT                                              = 25,
    ERR_NOT_EQUIPPABLE                                              = 26,
    ERR_CANT_STACK                                                  = 27,
    ERR_CANT_SWAP                                                   = 28,
    ERR_SLOT_EMPTY                                                  = 29,
    ERR_ITEM_NOT_FOUND                                              = 30,
    ERR_TOO_FEW_TO_SPLIT                                            = 31,
    ERR_SPLIT_FAILED                                                = 32,
    ERR_NOT_A_BAG                                                   = 33,
    ERR_NOT_OWNER                                                   = 34,
    ERR_ONLY_ONE_QUIVER                                             = 35,
    ERR_NO_BANK_SLOT                                                = 36,
    ERR_NO_BANK_HERE                                                = 37,
    ERR_NO_ACCOUNT_BANK_HERE                                        = 38,
    ERR_ITEM_LOCKED                                                 = 39,
    ERR_2HANDED_EQUIPPED                                            = 40,
    ERR_VENDOR_NOT_INTERESTED                                       = 41,
    ERR_VENDOR_REFUSE_SCRAPPABLE_AZERITE                            = 42,
    ERR_VENDOR_HATES_YOU                                            = 43,
    ERR_VENDOR_SOLD_OUT                                             = 44,
    ERR_VENDOR_TOO_FAR                                              = 45,
    ERR_VENDOR_DOESNT_BUY                                           = 46,
    ERR_NOT_ENOUGH_MONEY                                            = 47,
    ERR_RECEIVE_ITEM_S                                              = 48,
    ERR_DROP_BOUND_ITEM                                             = 49,
    ERR_TRADE_BOUND_ITEM                                            = 50,
    ERR_TRADE_QUEST_ITEM                                            = 51,
    ERR_TRADE_TEMP_ENCHANT_BOUND                                    = 52,
    ERR_TRADE_GROUND_ITEM                                           = 53,
    ERR_TRADE_BAG                                                   = 54,
    ERR_TRADE_FACTION_SPECIFIC                                      = 55,
    ERR_SPELL_FAILED_S                                              = 56,
    ERR_ITEM_COOLDOWN                                               = 57,
    ERR_POTION_COOLDOWN                                             = 58,
    ERR_FOOD_COOLDOWN                                               = 59,
    ERR_SPELL_COOLDOWN                                              = 60,
    ERR_ABILITY_COOLDOWN                                            = 61,
    ERR_SPELL_ALREADY_KNOWN_S                                       = 62,
    ERR_PET_SPELL_ALREADY_KNOWN_S                                   = 63,
    ERR_PROFICIENCY_GAINED_S                                        = 64,
    ERR_SKILL_GAINED_S                                              = 65,
    ERR_SKILL_UP_SI                                                 = 66,
    ERR_LEARN_SPELL_S                                               = 67,
    ERR_LEARN_ABILITY_S                                             = 68,
    ERR_LEARN_PASSIVE_S                                             = 69,
    ERR_LEARN_RECIPE_S                                              = 70,
    ERR_PROFESSIONS_RECIPE_DISCOVERY_S                              = 71,
    ERR_LEARN_COMPANION_S                                           = 72,
    ERR_LEARN_MOUNT_S                                               = 73,
    ERR_LEARN_TOY_S                                                 = 74,
    ERR_LEARN_HEIRLOOM_S                                            = 75,
    ERR_LEARN_TRANSMOG_S                                            = 76,
    ERR_COMPLETED_TRANSMOG_SET_S                                    = 77,
    ERR_APPEARANCE_ALREADY_LEARNED                                  = 78,
    ERR_REVOKE_TRANSMOG_S                                           = 79,
    ERR_INVITE_PLAYER_S                                             = 80,
    ERR_SUGGEST_INVITE_PLAYER_S                                     = 81,
    ERR_INFORM_SUGGEST_INVITE_S                                     = 82,
    ERR_INFORM_SUGGEST_INVITE_SS                                    = 83,
    ERR_REQUEST_JOIN_PLAYER_S                                       = 84,
    ERR_INVITE_SELF                                                 = 85,
    ERR_INVITED_TO_GROUP_SS                                         = 86,
    ERR_INVITED_ALREADY_IN_GROUP_SS                                 = 87,
    ERR_ALREADY_IN_GROUP_S                                          = 88,
    ERR_REQUESTED_INVITE_TO_GROUP_SS                                = 89,
    ERR_CROSS_REALM_RAID_INVITE                                     = 90,
    ERR_PLAYER_BUSY_S                                               = 91,
    ERR_NEW_LEADER_S                                                = 92,
    ERR_NEW_LEADER_YOU                                              = 93,
    ERR_NEW_GUIDE_S                                                 = 94,
    ERR_NEW_GUIDE_YOU                                               = 95,
    ERR_LEFT_GROUP_S                                                = 96,
    ERR_LEFT_GROUP_YOU                                              = 97,
    ERR_GROUP_DISBANDED                                             = 98,
    ERR_DECLINE_GROUP_S                                             = 99,
    ERR_DECLINE_GROUP_REQUEST_S                                     = 100,
    ERR_JOINED_GROUP_S                                              = 101,
    ERR_UNINVITE_YOU                                                = 102,
    ERR_BAD_PLAYER_NAME_S                                           = 103,
    ERR_NOT_IN_GROUP                                                = 104,
    ERR_TARGET_NOT_IN_GROUP_S                                       = 105,
    ERR_TARGET_NOT_IN_INSTANCE_S                                    = 106,
    ERR_NOT_IN_INSTANCE_GROUP                                       = 107,
    ERR_GROUP_FULL                                                  = 108,
    ERR_NOT_LEADER                                                  = 109,
    ERR_PLAYER_DIED_S                                               = 110,
    ERR_GUILD_CREATE_S                                              = 111,
    ERR_GUILD_INVITE_S                                              = 112,
    ERR_INVITED_TO_GUILD_SSS                                        = 113,
    ERR_ALREADY_IN_GUILD_S                                          = 114,
    ERR_ALREADY_INVITED_TO_GUILD_S                                  = 115,
    ERR_INVITED_TO_GUILD                                            = 116,
    ERR_ALREADY_IN_GUILD                                            = 117,
    ERR_GUILD_ACCEPT                                                = 118,
    ERR_GUILD_DECLINE_S                                             = 119,
    ERR_GUILD_DECLINE_AUTO_S                                        = 120,
    ERR_GUILD_PERMISSIONS                                           = 121,
    ERR_GUILD_JOIN_S                                                = 122,
    ERR_GUILD_FOUNDER_S                                             = 123,
    ERR_GUILD_PROMOTE_SSS                                           = 124,
    ERR_GUILD_DEMOTE_SS                                             = 125,
    ERR_GUILD_DEMOTE_SSS                                            = 126,
    ERR_GUILD_INVITE_SELF                                           = 127,
    ERR_GUILD_QUIT_S                                                = 128,
    ERR_GUILD_LEAVE_S                                               = 129,
    ERR_GUILD_REMOVE_SS                                             = 130,
    ERR_GUILD_REMOVE_SELF                                           = 131,
    ERR_GUILD_DISBAND_S                                             = 132,
    ERR_GUILD_DISBAND_SELF                                          = 133,
    ERR_GUILD_LEADER_S                                              = 134,
    ERR_GUILD_LEADER_SELF                                           = 135,
    ERR_GUILD_PLAYER_NOT_FOUND_S                                    = 136,
    ERR_GUILD_PLAYER_NOT_IN_GUILD_S                                 = 137,
    ERR_GUILD_PLAYER_NOT_IN_GUILD                                   = 138,
    ERR_GUILD_BANK_NOT_AVAILABLE                                    = 139,
    ERR_GUILD_CANT_PROMOTE_S                                        = 140,
    ERR_GUILD_CANT_DEMOTE_S                                         = 141,
    ERR_GUILD_NOT_IN_A_GUILD                                        = 142,
    ERR_GUILD_INTERNAL                                              = 143,
    ERR_GUILD_LEADER_IS_S                                           = 144,
    ERR_GUILD_LEADER_CHANGED_SS                                     = 145,
    ERR_GUILD_DISBANDED                                             = 146,
    ERR_GUILD_NOT_ALLIED                                            = 147,
    ERR_GUILD_NEW_LEADER_NOT_ALLIED                                 = 148,
    ERR_GUILD_LEADER_LEAVE                                          = 149,
    ERR_GUILD_RANKS_LOCKED                                          = 150,
    ERR_GUILD_RANK_IN_USE                                           = 151,
    ERR_GUILD_RANK_TOO_HIGH_S                                       = 152,
    ERR_GUILD_RANK_TOO_LOW_S                                        = 153,
    ERR_GUILD_NAME_EXISTS_S                                         = 154,
    ERR_GUILD_WITHDRAW_LIMIT                                        = 155,
    ERR_GUILD_NOT_ENOUGH_MONEY                                      = 156,
    ERR_GUILD_TOO_MUCH_MONEY                                        = 157,
    ERR_GUILD_BANK_CONJURED_ITEM                                    = 158,
    ERR_GUILD_BANK_EQUIPPED_ITEM                                    = 159,
    ERR_GUILD_BANK_BOUND_ITEM                                       = 160,
    ERR_GUILD_BANK_QUEST_ITEM                                       = 161,
    ERR_GUILD_BANK_WRAPPED_ITEM                                     = 162,
    ERR_GUILD_BANK_FULL                                             = 163,
    ERR_GUILD_BANK_WRONG_TAB                                        = 164,
    ERR_GUILD_BANK_WARBANDS_BANK_SOURCE                             = 165,
    ERR_GUILD_NEW_LEADER_WRONG_REALM                                = 166,
    ERR_NO_GUILD_CHARTER                                            = 167,
    ERR_OUT_OF_RANGE                                                = 168,
    ERR_PLAYER_DEAD                                                 = 169,
    ERR_CLIENT_LOCKED_OUT                                           = 170,
    ERR_CLIENT_ON_TRANSPORT                                         = 171,
    ERR_KILLED_BY_S                                                 = 172,
    ERR_LOOT_LOCKED                                                 = 173,
    ERR_LOOT_TOO_FAR                                                = 174,
    ERR_LOOT_DIDNT_KILL                                             = 175,
    ERR_LOOT_BAD_FACING                                             = 176,
    ERR_LOOT_NOTSTANDING                                            = 177,
    ERR_LOOT_STUNNED                                                = 178,
    ERR_LOOT_NO_UI                                                  = 179,
    ERR_LOOT_WHILE_INVULNERABLE                                     = 180,
    ERR_NO_LOOT                                                     = 181,
    ERR_QUEST_ACCEPTED_S                                            = 182,
    ERR_QUEST_COMPLETE_S                                            = 183,
    ERR_QUEST_FAILED_S                                              = 184,
    ERR_QUEST_FAILED_BAG_FULL_S                                     = 185,
    ERR_QUEST_FAILED_MAX_COUNT_S                                    = 186,
    ERR_QUEST_FAILED_LOW_LEVEL                                      = 187,
    ERR_QUEST_FAILED_MISSING_ITEMS                                  = 188,
    ERR_QUEST_FAILED_WRONG_RACE                                     = 189,
    ERR_QUEST_FAILED_NOT_ENOUGH_MONEY                               = 190,
    ERR_QUEST_FAILED_EXPANSION                                      = 191,
    ERR_QUEST_ONLY_ONE_TIMED                                        = 192,
    ERR_QUEST_NEED_PREREQS                                          = 193,
    ERR_QUEST_NEED_PREREQS_CUSTOM                                   = 194,
    ERR_QUEST_ALREADY_ON                                            = 195,
    ERR_QUEST_ALREADY_DONE                                          = 196,
    ERR_QUEST_ALREADY_DONE_DAILY                                    = 197,
    ERR_QUEST_HAS_IN_PROGRESS                                       = 198,
    ERR_QUEST_REWARD_EXP_I                                          = 199,
    ERR_QUEST_REWARD_MONEY_S                                        = 200,
    ERR_QUEST_MUST_CHOOSE                                           = 201,
    ERR_QUEST_LOG_FULL                                              = 202,
    ERR_COMBAT_DAMAGE_SSI                                           = 203,
    ERR_INSPECT_S                                                   = 204,
    ERR_CANT_USE_ITEM                                               = 205,
    ERR_CANT_USE_ITEM_IN_ARENA                                      = 206,
    ERR_CANT_USE_ITEM_IN_RATED_BATTLEGROUND                         = 207,
    ERR_MUST_EQUIP_ITEM                                             = 208,
    ERR_PASSIVE_ABILITY                                             = 209,
    ERR_2HSKILLNOTFOUND                                             = 210,
    ERR_NO_ATTACK_TARGET                                            = 211,
    ERR_INVALID_ATTACK_TARGET                                       = 212,
    ERR_ATTACK_PVP_TARGET_WHILE_UNFLAGGED                           = 213,
    ERR_ATTACK_STUNNED                                              = 214,
    ERR_ATTACK_PACIFIED                                             = 215,
    ERR_ATTACK_MOUNTED                                              = 216,
    ERR_ATTACK_FLEEING                                              = 217,
    ERR_ATTACK_CONFUSED                                             = 218,
    ERR_ATTACK_CHARMED                                              = 219,
    ERR_ATTACK_DEAD                                                 = 220,
    ERR_ATTACK_PREVENTED_BY_MECHANIC_S                              = 221,
    ERR_ATTACK_CHANNEL                                              = 222,
    ERR_TAXISAMENODE                                                = 223,
    ERR_TAXINOSUCHPATH                                              = 224,
    ERR_TAXIUNSPECIFIEDSERVERERROR                                  = 225,
    ERR_TAXINOTENOUGHMONEY                                          = 226,
    ERR_TAXITOOFARAWAY                                              = 227,
    ERR_TAXINOVENDORNEARBY                                          = 228,
    ERR_TAXINOTVISITED                                              = 229,
    ERR_TAXIPLAYERBUSY                                              = 230,
    ERR_TAXIPLAYERALREADYMOUNTED                                    = 231,
    ERR_TAXIPLAYERSHAPESHIFTED                                      = 232,
    ERR_TAXIPLAYERMOVING                                            = 233,
    ERR_TAXINOPATHS                                                 = 234,
    ERR_TAXINOTELIGIBLE                                             = 235,
    ERR_TAXINOTSTANDING                                             = 236,
    ERR_TAXIINCOMBAT                                                = 237,
    ERR_NO_REPLY_TARGET                                             = 238,
    ERR_GENERIC_NO_TARGET                                           = 239,
    ERR_INITIATE_TRADE_S                                            = 240,
    ERR_TRADE_REQUEST_S                                             = 241,
    ERR_TRADE_BLOCKED_S                                             = 242,
    ERR_TRADE_TARGET_DEAD                                           = 243,
    ERR_TRADE_TOO_FAR                                               = 244,
    ERR_TRADE_CANCELLED                                             = 245,
    ERR_TRADE_COMPLETE                                              = 246,
    ERR_TRADE_BAG_FULL                                              = 247,
    ERR_TRADE_TARGET_BAG_FULL                                       = 248,
    ERR_TRADE_MAX_COUNT_EXCEEDED                                    = 249,
    ERR_TRADE_TARGET_MAX_COUNT_EXCEEDED                             = 250,
    ERR_INVENTORY_TRADE_TOO_MANY_UNIQUE_ITEM                        = 251,
    ERR_ALREADY_TRADING                                             = 252,
    ERR_MOUNT_INVALIDMOUNTEE                                        = 253,
    ERR_MOUNT_TOOFARAWAY                                            = 254,
    ERR_MOUNT_ALREADYMOUNTED                                        = 255,
    ERR_MOUNT_NOTMOUNTABLE                                          = 256,
    ERR_MOUNT_NOTYOURPET                                            = 257,
    ERR_MOUNT_OTHER                                                 = 258,
    ERR_MOUNT_LOOTING                                               = 259,
    ERR_MOUNT_RACECANTMOUNT                                         = 260,
    ERR_MOUNT_SHAPESHIFTED                                          = 261,
    ERR_MOUNT_NO_FAVORITES                                          = 262,
    ERR_MOUNT_NO_MOUNTS                                             = 263,
    ERR_DISMOUNT_NOPET                                              = 264,
    ERR_DISMOUNT_NOTMOUNTED                                         = 265,
    ERR_DISMOUNT_NOTYOURPET                                         = 266,
    ERR_SPELL_FAILED_TOTEMS                                         = 267,
    ERR_SPELL_FAILED_REAGENTS                                       = 268,
    ERR_SPELL_FAILED_REAGENTS_GENERIC                               = 269,
    ERR_SPELL_FAILED_OPTIONAL_REAGENTS                              = 270,
    ERR_CANT_TRADE_GOLD                                             = 271,
    ERR_SPELL_FAILED_EQUIPPED_ITEM                                  = 272,
    ERR_SPELL_FAILED_EQUIPPED_ITEM_CLASS_S                          = 273,
    ERR_SPELL_FAILED_SHAPESHIFT_FORM_S                              = 274,
    ERR_SPELL_FAILED_ANOTHER_IN_PROGRESS                            = 275,
    ERR_BADATTACKFACING                                             = 276,
    ERR_BADATTACKPOS                                                = 277,
    ERR_CHEST_IN_USE                                                = 278,
    ERR_USE_CANT_OPEN                                               = 279,
    ERR_USE_LOCKED                                                  = 280,
    ERR_DOOR_LOCKED                                                 = 281,
    ERR_BUTTON_LOCKED                                               = 282,
    ERR_USE_LOCKED_WITH_ITEM_S                                      = 283,
    ERR_USE_LOCKED_WITH_SPELL_S                                     = 284,
    ERR_USE_LOCKED_WITH_SPELL_KNOWN_SI                              = 285,
    ERR_USE_TOO_FAR                                                 = 286,
    ERR_USE_BAD_ANGLE                                               = 287,
    ERR_USE_OBJECT_MOVING                                           = 288,
    ERR_USE_SPELL_FOCUS                                             = 289,
    ERR_USE_DESTROYED                                               = 290,
    ERR_SET_LOOT_FREEFORALL                                         = 291,
    ERR_SET_LOOT_ROUNDROBIN                                         = 292,
    ERR_SET_LOOT_MASTER                                             = 293,
    ERR_SET_LOOT_GROUP                                              = 294,
    ERR_SET_LOOT_THRESHOLD_S                                        = 295,
    ERR_NEW_LOOT_MASTER_S                                           = 296,
    ERR_SPECIFY_MASTER_LOOTER                                       = 297,
    ERR_LOOT_SPEC_CHANGED_S                                         = 298,
    ERR_TAME_FAILED                                                 = 299,
    ERR_CHAT_WHILE_DEAD                                             = 300,
    ERR_CHAT_PLAYER_NOT_FOUND_S                                     = 301,
    ERR_NEWTAXIPATH                                                 = 302,
    ERR_NO_PET                                                      = 303,
    ERR_NOTYOURPET                                                  = 304,
    ERR_PET_NOT_RENAMEABLE                                          = 305,
    ERR_QUEST_OBJECTIVE_COMPLETE_S                                  = 306,
    ERR_QUEST_UNKNOWN_COMPLETE                                      = 307,
    ERR_QUEST_ADD_KILL_SII                                          = 308,
    ERR_QUEST_ADD_FOUND_SII                                         = 309,
    ERR_QUEST_ADD_ITEM_SII                                          = 310,
    ERR_QUEST_ADD_PLAYER_KILL_SII                                   = 311,
    ERR_CANNOTCREATEDIRECTORY                                       = 312,
    ERR_CANNOTCREATEFILE                                            = 313,
    ERR_PLAYER_WRONG_FACTION                                        = 314,
    ERR_PLAYER_IS_NEUTRAL                                           = 315,
    ERR_BANKSLOT_FAILED_TOO_MANY                                    = 316,
    ERR_BANKSLOT_INSUFFICIENT_FUNDS                                 = 317,
    ERR_BANKSLOT_NOTBANKER                                          = 318,
    ERR_FRIEND_DB_ERROR                                             = 319,
    ERR_FRIEND_LIST_FULL                                            = 320,
    ERR_FRIEND_ADDED_S                                              = 321,
    ERR_BATTLETAG_FRIEND_ADDED_S                                    = 322,
    ERR_FRIEND_ONLINE_SS                                            = 323,
    ERR_FRIEND_OFFLINE_S                                            = 324,
    ERR_FRIEND_NOT_FOUND                                            = 325,
    ERR_FRIEND_WRONG_FACTION                                        = 326,
    ERR_FRIEND_REMOVED_S                                            = 327,
    ERR_BATTLETAG_FRIEND_REMOVED_S                                  = 328,
    ERR_FRIEND_ERROR                                                = 329,
    ERR_FRIEND_ALREADY_S                                            = 330,
    ERR_FRIEND_SELF                                                 = 331,
    ERR_FRIEND_DELETED                                              = 332,
    ERR_IGNORE_FULL                                                 = 333,
    ERR_IGNORE_SELF                                                 = 334,
    ERR_IGNORE_NOT_FOUND                                            = 335,
    ERR_IGNORE_ALREADY_S                                            = 336,
    ERR_IGNORE_ADDED_S                                              = 337,
    ERR_IGNORE_REMOVED_S                                            = 338,
    ERR_IGNORE_AMBIGUOUS                                            = 339,
    ERR_IGNORE_DELETED                                              = 340,
    ERR_ONLY_ONE_BOLT                                               = 341,
    ERR_ONLY_ONE_AMMO                                               = 342,
    ERR_SPELL_FAILED_EQUIPPED_SPECIFIC_ITEM                         = 343,
    ERR_WRONG_BAG_TYPE_SUBCLASS                                     = 344,
    ERR_CANT_WRAP_STACKABLE                                         = 345,
    ERR_CANT_WRAP_EQUIPPED                                          = 346,
    ERR_CANT_WRAP_WRAPPED                                           = 347,
    ERR_CANT_WRAP_BOUND                                             = 348,
    ERR_CANT_WRAP_UNIQUE                                            = 349,
    ERR_CANT_WRAP_BAGS                                              = 350,
    ERR_OUT_OF_MANA                                                 = 351,
    ERR_OUT_OF_RAGE                                                 = 352,
    ERR_OUT_OF_FOCUS                                                = 353,
    ERR_OUT_OF_ENERGY                                               = 354,
    ERR_OUT_OF_CHI                                                  = 355,
    ERR_OUT_OF_HEALTH                                               = 356,
    ERR_OUT_OF_RUNES                                                = 357,
    ERR_OUT_OF_RUNIC_POWER                                          = 358,
    ERR_OUT_OF_SOUL_SHARDS                                          = 359,
    ERR_OUT_OF_LUNAR_POWER                                          = 360,
    ERR_OUT_OF_HOLY_POWER                                           = 361,
    ERR_OUT_OF_MAELSTROM                                            = 362,
    ERR_OUT_OF_COMBO_POINTS                                         = 363,
    ERR_OUT_OF_INSANITY                                             = 364,
    ERR_OUT_OF_ESSENCE                                              = 365,
    ERR_OUT_OF_ARCANE_CHARGES                                       = 366,
    ERR_OUT_OF_FURY                                                 = 367,
    ERR_OUT_OF_PAIN                                                 = 368,
    ERR_OUT_OF_POWER_DISPLAY                                        = 369,
    ERR_LOOT_GONE                                                   = 370,
    ERR_MOUNT_FORCEDDISMOUNT                                        = 371,
    ERR_AUTOFOLLOW_TOO_FAR                                          = 372,
    ERR_UNIT_NOT_FOUND                                              = 373,
    ERR_INVALID_FOLLOW_TARGET                                       = 374,
    ERR_INVALID_FOLLOW_PVP_COMBAT                                   = 375,
    ERR_INVALID_FOLLOW_TARGET_PVP_COMBAT                            = 376,
    ERR_INVALID_INSPECT_TARGET                                      = 377,
    ERR_GUILDEMBLEM_SUCCESS                                         = 378,
    ERR_GUILDEMBLEM_INVALID_TABARD_COLORS                           = 379,
    ERR_GUILDEMBLEM_NOGUILD                                         = 380,
    ERR_GUILDEMBLEM_NOTGUILDMASTER                                  = 381,
    ERR_GUILDEMBLEM_NOTENOUGHMONEY                                  = 382,
    ERR_GUILDEMBLEM_INVALIDVENDOR                                   = 383,
    ERR_EMBLEMERROR_NOTABARDGEOSET                                  = 384,
    ERR_SPELL_OUT_OF_RANGE                                          = 385,
    ERR_COMMAND_NEEDS_TARGET                                        = 386,
    ERR_NOAMMO_S                                                    = 387,
    ERR_TOOBUSYTOFOLLOW                                             = 388,
    ERR_DUEL_REQUESTED                                              = 389,
    ERR_DUEL_CANCELLED                                              = 390,
    ERR_DEATHBINDALREADYBOUND                                       = 391,
    ERR_DEATHBIND_SUCCESS_S                                         = 392,
    ERR_NOEMOTEWHILERUNNING                                         = 393,
    ERR_ZONE_EXPLORED                                               = 394,
    ERR_ZONE_EXPLORED_XP                                            = 395,
    ERR_INVALID_ITEM_TARGET                                         = 396,
    ERR_INVALID_QUEST_TARGET                                        = 397,
    ERR_IGNORING_YOU_S                                              = 398,
    ERR_FISH_NOT_HOOKED                                             = 399,
    ERR_FISH_ESCAPED                                                = 400,
    ERR_SPELL_FAILED_NOTUNSHEATHED                                  = 401,
    ERR_PETITION_OFFERED_S                                          = 402,
    ERR_PETITION_SIGNED                                             = 403,
    ERR_PETITION_SIGNED_S                                           = 404,
    ERR_PETITION_DECLINED_S                                         = 405,
    ERR_PETITION_ALREADY_SIGNED                                     = 406,
    ERR_PETITION_RESTRICTED_ACCOUNT_TRIAL                           = 407,
    ERR_PETITION_ALREADY_SIGNED_OTHER                               = 408,
    ERR_PETITION_IN_GUILD                                           = 409,
    ERR_PETITION_CREATOR                                            = 410,
    ERR_PETITION_NOT_ENOUGH_SIGNATURES                              = 411,
    ERR_PETITION_NOT_SAME_SERVER                                    = 412,
    ERR_PETITION_FULL                                               = 413,
    ERR_PETITION_ALREADY_SIGNED_BY_S                                = 414,
    ERR_GUILD_NAME_INVALID                                          = 415,
    ERR_SPELL_UNLEARNED_S                                           = 416,
    ERR_PET_SPELL_ROOTED                                            = 417,
    ERR_PET_SPELL_AFFECTING_COMBAT                                  = 418,
    ERR_PET_SPELL_OUT_OF_RANGE                                      = 419,
    ERR_PET_SPELL_NOT_BEHIND                                        = 420,
    ERR_PET_SPELL_TARGETS_DEAD                                      = 421,
    ERR_PET_SPELL_DEAD                                              = 422,
    ERR_PET_SPELL_NOPATH                                            = 423,
    ERR_ITEM_CANT_BE_DESTROYED                                      = 424,
    ERR_TICKET_ALREADY_EXISTS                                       = 425,
    ERR_TICKET_CREATE_ERROR                                         = 426,
    ERR_TICKET_UPDATE_ERROR                                         = 427,
    ERR_TICKET_DB_ERROR                                             = 428,
    ERR_TICKET_NO_TEXT                                              = 429,
    ERR_TICKET_TEXT_TOO_LONG                                        = 430,
    ERR_OBJECT_IS_BUSY                                              = 431,
    ERR_EXHAUSTION_WELLRESTED                                       = 432,
    ERR_EXHAUSTION_RESTED                                           = 433,
    ERR_EXHAUSTION_NORMAL                                           = 434,
    ERR_EXHAUSTION_TIRED                                            = 435,
    ERR_EXHAUSTION_EXHAUSTED                                        = 436,
    ERR_NO_ITEMS_WHILE_SHAPESHIFTED                                 = 437,
    ERR_CANT_INTERACT_SHAPESHIFTED                                  = 438,
    ERR_REALM_NOT_FOUND                                             = 439,
    ERR_MAIL_QUEST_ITEM                                             = 440,
    ERR_MAIL_BOUND_ITEM                                             = 441,
    ERR_MAIL_CONJURED_ITEM                                          = 442,
    ERR_MAIL_BAG                                                    = 443,
    ERR_MAIL_TO_SELF                                                = 444,
    ERR_MAIL_TARGET_NOT_FOUND                                       = 445,
    ERR_MAIL_DATABASE_ERROR                                         = 446,
    ERR_MAIL_DELETE_ITEM_ERROR                                      = 447,
    ERR_MAIL_WRAPPED_COD                                            = 448,
    ERR_MAIL_CANT_SEND_REALM                                        = 449,
    ERR_MAIL_TEMP_RETURN_OUTAGE                                     = 450,
    ERR_MAIL_RECEPIENT_CANT_RECEIVE_MAIL                            = 451,
    ERR_MAIL_SENT                                                   = 452,
    ERR_MAIL_TARGET_IS_TRIAL                                        = 453,
    ERR_NOT_HAPPY_ENOUGH                                            = 454,
    ERR_USE_CANT_IMMUNE                                             = 455,
    ERR_CANT_BE_DISENCHANTED                                        = 456,
    ERR_CANT_USE_DISARMED                                           = 457,
    ERR_AUCTION_DATABASE_ERROR                                      = 458,
    ERR_AUCTION_HIGHER_BID                                          = 459,
    ERR_AUCTION_ALREADY_BID                                         = 460,
    ERR_AUCTION_OUTBID_S                                            = 461,
    ERR_AUCTION_WON_S                                               = 462,
    ERR_AUCTION_REMOVED_S                                           = 463,
    ERR_AUCTION_BID_PLACED                                          = 464,
    ERR_LOGOUT_FAILED                                               = 465,
    ERR_QUEST_PUSH_SUCCESS_S                                        = 466,
    ERR_QUEST_PUSH_INVALID_S                                        = 467,
    ERR_QUEST_PUSH_INVALID_TO_RECIPIENT_S                           = 468,
    ERR_QUEST_PUSH_ACCEPTED_S                                       = 469,
    ERR_QUEST_PUSH_DECLINED_S                                       = 470,
    ERR_QUEST_PUSH_BUSY_S                                           = 471,
    ERR_QUEST_PUSH_DEAD_S                                           = 472,
    ERR_QUEST_PUSH_DEAD_TO_RECIPIENT_S                              = 473,
    ERR_QUEST_PUSH_LOG_FULL_S                                       = 474,
    ERR_QUEST_PUSH_LOG_FULL_TO_RECIPIENT_S                          = 475,
    ERR_QUEST_PUSH_ONQUEST_S                                        = 476,
    ERR_QUEST_PUSH_ONQUEST_TO_RECIPIENT_S                           = 477,
    ERR_QUEST_PUSH_ALREADY_DONE_S                                   = 478,
    ERR_QUEST_PUSH_ALREADY_DONE_TO_RECIPIENT_S                      = 479,
    ERR_QUEST_PUSH_NOT_DAILY_S                                      = 480,
    ERR_QUEST_PUSH_TIMER_EXPIRED_S                                  = 481,
    ERR_QUEST_PUSH_NOT_IN_PARTY_S                                   = 482,
    ERR_QUEST_PUSH_DIFFERENT_SERVER_DAILY_S                         = 483,
    ERR_QUEST_PUSH_DIFFERENT_SERVER_DAILY_TO_RECIPIENT_S            = 484,
    ERR_QUEST_PUSH_NOT_ALLOWED_S                                    = 485,
    ERR_QUEST_PUSH_PREREQUISITE_S                                   = 486,
    ERR_QUEST_PUSH_PREREQUISITE_TO_RECIPIENT_S                      = 487,
    ERR_QUEST_PUSH_LOW_LEVEL_S                                      = 488,
    ERR_QUEST_PUSH_LOW_LEVEL_TO_RECIPIENT_S                         = 489,
    ERR_QUEST_PUSH_HIGH_LEVEL_S                                     = 490,
    ERR_QUEST_PUSH_HIGH_LEVEL_TO_RECIPIENT_S                        = 491,
    ERR_QUEST_PUSH_CLASS_S                                          = 492,
    ERR_QUEST_PUSH_CLASS_TO_RECIPIENT_S                             = 493,
    ERR_QUEST_PUSH_RACE_S                                           = 494,
    ERR_QUEST_PUSH_RACE_TO_RECIPIENT_S                              = 495,
    ERR_QUEST_PUSH_LOW_FACTION_S                                    = 496,
    ERR_QUEST_PUSH_LOW_FACTION_TO_RECIPIENT_S                       = 497,
    ERR_QUEST_PUSH_HIGH_FACTION_S                                   = 498,
    ERR_QUEST_PUSH_HIGH_FACTION_TO_RECIPIENT_S                      = 499,
    ERR_QUEST_PUSH_EXPANSION_S                                      = 500,
    ERR_QUEST_PUSH_EXPANSION_TO_RECIPIENT_S                         = 501,
    ERR_QUEST_PUSH_NOT_GARRISON_OWNER_S                             = 502,
    ERR_QUEST_PUSH_NOT_GARRISON_OWNER_TO_RECIPIENT_S                = 503,
    ERR_QUEST_PUSH_WRONG_COVENANT_S                                 = 504,
    ERR_QUEST_PUSH_WRONG_COVENANT_TO_RECIPIENT_S                    = 505,
    ERR_QUEST_PUSH_NEW_PLAYER_EXPERIENCE_S                          = 506,
    ERR_QUEST_PUSH_NEW_PLAYER_EXPERIENCE_TO_RECIPIENT_S             = 507,
    ERR_QUEST_PUSH_WRONG_FACTION_S                                  = 508,
    ERR_QUEST_PUSH_WRONG_FACTION_TO_RECIPIENT_S                     = 509,
    ERR_QUEST_PUSH_CROSS_FACTION_RESTRICTED_S                       = 510,
    ERR_RAID_GROUP_LOWLEVEL                                         = 511,
    ERR_RAID_GROUP_ONLY                                             = 512,
    ERR_RAID_GROUP_FULL                                             = 513,
    ERR_RAID_GROUP_REQUIREMENTS_UNMATCH                             = 514,
    ERR_CORPSE_IS_NOT_IN_INSTANCE                                   = 515,
    ERR_PVP_KILL_HONORABLE                                          = 516,
    ERR_PVP_KILL_DISHONORABLE                                       = 517,
    ERR_SPELL_FAILED_ALREADY_AT_FULL_HEALTH                         = 518,
    ERR_SPELL_FAILED_ALREADY_AT_FULL_MANA                           = 519,
    ERR_SPELL_FAILED_ALREADY_AT_FULL_POWER_S                        = 520,
    ERR_AUTOLOOT_MONEY_S                                            = 521,
    ERR_GENERIC_STUNNED                                             = 522,
    ERR_GENERIC_THROTTLE                                            = 523,
    ERR_CLUB_FINDER_SEARCHING_TOO_FAST                              = 524,
    ERR_TARGET_STUNNED                                              = 525,
    ERR_MUST_REPAIR_DURABILITY                                      = 526,
    ERR_RAID_YOU_JOINED                                             = 527,
    ERR_RAID_YOU_LEFT                                               = 528,
    ERR_INSTANCE_GROUP_JOINED_WITH_PARTY                            = 529,
    ERR_INSTANCE_GROUP_JOINED_WITH_RAID                             = 530,
    ERR_RAID_MEMBER_ADDED_S                                         = 531,
    ERR_RAID_MEMBER_REMOVED_S                                       = 532,
    ERR_INSTANCE_GROUP_ADDED_S                                      = 533,
    ERR_INSTANCE_GROUP_REMOVED_S                                    = 534,
    ERR_CLICK_ON_ITEM_TO_FEED                                       = 535,
    ERR_TOO_MANY_CHAT_CHANNELS                                      = 536,
    ERR_LOOT_ROLL_PENDING                                           = 537,
    ERR_LOOT_PLAYER_NOT_FOUND                                       = 538,
    ERR_NOT_IN_RAID                                                 = 539,
    ERR_LOGGING_OUT                                                 = 540,
    ERR_TARGET_LOGGING_OUT                                          = 541,
    ERR_NOT_WHILE_MOUNTED                                           = 542,
    ERR_NOT_WHILE_SHAPESHIFTED                                      = 543,
    ERR_NOT_IN_COMBAT                                               = 544,
    ERR_NOT_WHILE_DISARMED                                          = 545,
    ERR_PET_BROKEN                                                  = 546,
    ERR_TALENT_WIPE_ERROR                                           = 547,
    ERR_SPEC_WIPE_ERROR                                             = 548,
    ERR_GLYPH_WIPE_ERROR                                            = 549,
    ERR_PET_SPEC_WIPE_ERROR                                         = 550,
    ERR_FEIGN_DEATH_RESISTED                                        = 551,
    ERR_MEETING_STONE_IN_QUEUE_S                                    = 552,
    ERR_MEETING_STONE_LEFT_QUEUE_S                                  = 553,
    ERR_MEETING_STONE_OTHER_MEMBER_LEFT                             = 554,
    ERR_MEETING_STONE_PARTY_KICKED_FROM_QUEUE                       = 555,
    ERR_MEETING_STONE_MEMBER_STILL_IN_QUEUE                         = 556,
    ERR_MEETING_STONE_SUCCESS                                       = 557,
    ERR_MEETING_STONE_IN_PROGRESS                                   = 558,
    ERR_MEETING_STONE_MEMBER_ADDED_S                                = 559,
    ERR_MEETING_STONE_GROUP_FULL                                    = 560,
    ERR_MEETING_STONE_NOT_LEADER                                    = 561,
    ERR_MEETING_STONE_INVALID_LEVEL                                 = 562,
    ERR_MEETING_STONE_TARGET_NOT_IN_PARTY                           = 563,
    ERR_MEETING_STONE_TARGET_INVALID_LEVEL                          = 564,
    ERR_MEETING_STONE_MUST_BE_LEADER                                = 565,
    ERR_MEETING_STONE_NO_RAID_GROUP                                 = 566,
    ERR_MEETING_STONE_NEED_PARTY                                    = 567,
    ERR_MEETING_STONE_NOT_FOUND                                     = 568,
    ERR_MEETING_STONE_TARGET_IN_VEHICLE                             = 569,
    ERR_GUILDEMBLEM_SAME                                            = 570,
    ERR_EQUIP_TRADE_ITEM                                            = 571,
    ERR_PVP_TOGGLE_ON                                               = 572,
    ERR_PVP_TOGGLE_OFF                                              = 573,
    ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS                           = 574,
    ERR_GROUP_JOIN_BATTLEGROUND_DEAD                                = 575,
    ERR_GROUP_JOIN_BATTLEGROUND_S                                   = 576,
    ERR_GROUP_JOIN_BATTLEGROUND_FAIL                                = 577,
    ERR_GROUP_JOIN_BATTLEGROUND_TOO_MANY                            = 578,
    ERR_SOLO_JOIN_BATTLEGROUND_S                                    = 579,
    ERR_JOIN_SINGLE_SCENARIO_S                                      = 580,
    ERR_BATTLEGROUND_TOO_MANY_QUEUES                                = 581,
    ERR_BATTLEGROUND_CANNOT_QUEUE_FOR_RATED                         = 582,
    ERR_BATTLEDGROUND_QUEUED_FOR_RATED                              = 583,
    ERR_BATTLEGROUND_TEAM_LEFT_QUEUE                                = 584,
    ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND                            = 585,
    ERR_ALREADY_IN_ARENA_TEAM_S                                     = 586,
    ERR_INVALID_PROMOTION_CODE                                      = 587,
    ERR_BG_PLAYER_JOINED_SS                                         = 588,
    ERR_BG_PLAYER_LEFT_S                                            = 589,
    ERR_RESTRICTED_ACCOUNT                                          = 590,
    ERR_RESTRICTED_ACCOUNT_TRIAL                                    = 591,
    ERR_NOT_ENOUGH_PURCHASED_GAME_TIME                              = 592,
    ERR_PLAY_TIME_EXCEEDED                                          = 593,
    ERR_APPROACHING_PARTIAL_PLAY_TIME                               = 594,
    ERR_APPROACHING_PARTIAL_PLAY_TIME_2                             = 595,
    ERR_APPROACHING_NO_PLAY_TIME                                    = 596,
    ERR_APPROACHING_NO_PLAY_TIME_2                                  = 597,
    ERR_UNHEALTHY_TIME                                              = 598,
    ERR_CHAT_RESTRICTED_TRIAL                                       = 599,
    ERR_CHAT_THROTTLED                                              = 600,
    ERR_MAIL_REACHED_CAP                                            = 601,
    ERR_INVALID_RAID_TARGET                                         = 602,
    ERR_RAID_LEADER_READY_CHECK_START_S                             = 603,
    ERR_READY_CHECK_IN_PROGRESS                                     = 604,
    ERR_READY_CHECK_THROTTLED                                       = 605,
    ERR_DUNGEON_DIFFICULTY_FAILED                                   = 606,
    ERR_DUNGEON_DIFFICULTY_CHANGED_S                                = 607,
    ERR_TRADE_WRONG_REALM                                           = 608,
    ERR_TRADE_NOT_ON_TAPLIST                                        = 609,
    ERR_CHAT_PLAYER_AMBIGUOUS_S                                     = 610,
    ERR_LOOT_CANT_LOOT_THAT_NOW                                     = 611,
    ERR_LOOT_MASTER_INV_FULL                                        = 612,
    ERR_LOOT_MASTER_UNIQUE_ITEM                                     = 613,
    ERR_LOOT_MASTER_OTHER                                           = 614,
    ERR_FILTERING_YOU_S                                             = 615,
    ERR_USE_PREVENTED_BY_MECHANIC_S                                 = 616,
    ERR_ITEM_UNIQUE_EQUIPPABLE                                      = 617,
    ERR_LFG_LEADER_IS_LFM_S                                         = 618,
    ERR_LFG_PENDING                                                 = 619,
    ERR_CANT_SPEAK_LANGAGE                                          = 620,
    ERR_VENDOR_MISSING_TURNINS                                      = 621,
    ERR_BATTLEGROUND_NOT_IN_TEAM                                    = 622,
    ERR_NOT_IN_BATTLEGROUND                                         = 623,
    ERR_NOT_ENOUGH_HONOR_POINTS                                     = 624,
    ERR_NOT_ENOUGH_ARENA_POINTS                                     = 625,
    ERR_SOCKETING_REQUIRES_META_GEM                                 = 626,
    ERR_SOCKETING_META_GEM_ONLY_IN_METASLOT                         = 627,
    ERR_SOCKETING_REQUIRES_HYDRAULIC_GEM                            = 628,
    ERR_SOCKETING_HYDRAULIC_GEM_ONLY_IN_HYDRAULICSLOT               = 629,
    ERR_SOCKETING_REQUIRES_COGWHEEL_GEM                             = 630,
    ERR_SOCKETING_COGWHEEL_GEM_ONLY_IN_COGWHEELSLOT                 = 631,
    ERR_SOCKETING_ITEM_TOO_LOW_LEVEL                                = 632,
    ERR_ITEM_MAX_COUNT_SOCKETED                                     = 633,
    ERR_SYSTEM_DISABLED                                             = 634,
    ERR_QUEST_FAILED_TOO_MANY_DAILY_QUESTS_I                        = 635,
    ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED                            = 636,
    ERR_ITEM_UNIQUE_EQUIPPABLE_SOCKETED                             = 637,
    ERR_USER_SQUELCHED                                              = 638,
    ERR_ACCOUNT_SILENCED                                            = 639,
    ERR_PARTY_MEMBER_SILENCED                                       = 640,
    ERR_PARTY_MEMBER_SILENCED_LFG_DELIST                            = 641,
    ERR_TOO_MUCH_GOLD                                               = 642,
    ERR_NOT_BARBER_SITTING                                          = 643,
    ERR_QUEST_FAILED_CAIS                                           = 644,
    ERR_INVITE_RESTRICTED_TRIAL                                     = 645,
    ERR_VOICE_IGNORE_FULL                                           = 646,
    ERR_VOICE_IGNORE_SELF                                           = 647,
    ERR_VOICE_IGNORE_NOT_FOUND                                      = 648,
    ERR_VOICE_IGNORE_ALREADY_S                                      = 649,
    ERR_VOICE_IGNORE_ADDED_S                                        = 650,
    ERR_VOICE_IGNORE_REMOVED_S                                      = 651,
    ERR_VOICE_IGNORE_AMBIGUOUS                                      = 652,
    ERR_VOICE_IGNORE_DELETED                                        = 653,
    ERR_UNKNOWN_MACRO_OPTION_S                                      = 654,
    ERR_NOT_DURING_ARENA_MATCH                                      = 655,
    ERR_NOT_IN_RATED_BATTLEGROUND                                   = 656,
    ERR_PLAYER_SILENCED                                             = 657,
    ERR_PLAYER_UNSILENCED                                           = 658,
    ERR_COMSAT_DISCONNECT                                           = 659,
    ERR_COMSAT_RECONNECT_ATTEMPT                                    = 660,
    ERR_COMSAT_CONNECT_FAIL                                         = 661,
    ERR_MAIL_INVALID_ATTACHMENT_SLOT                                = 662,
    ERR_MAIL_TOO_MANY_ATTACHMENTS                                   = 663,
    ERR_MAIL_INVALID_ATTACHMENT                                     = 664,
    ERR_MAIL_ATTACHMENT_EXPIRED                                     = 665,
    ERR_VOICE_CHAT_PARENTAL_DISABLE_MIC                             = 666,
    ERR_PROFANE_CHAT_NAME                                           = 667,
    ERR_PLAYER_SILENCED_ECHO                                        = 668,
    ERR_PLAYER_UNSILENCED_ECHO                                      = 669,
    ERR_LOOT_CANT_LOOT_THAT                                         = 670,
    ERR_ARENA_EXPIRED_CAIS                                          = 671,
    ERR_GROUP_ACTION_THROTTLED                                      = 672,
    ERR_ALREADY_PICKPOCKETED                                        = 673,
    ERR_NAME_INVALID                                                = 674,
    ERR_NAME_NO_NAME                                                = 675,
    ERR_NAME_TOO_SHORT                                              = 676,
    ERR_NAME_TOO_LONG                                               = 677,
    ERR_NAME_MIXED_LANGUAGES                                        = 678,
    ERR_NAME_PROFANE                                                = 679,
    ERR_NAME_RESERVED                                               = 680,
    ERR_NAME_THREE_CONSECUTIVE                                      = 681,
    ERR_NAME_INVALID_SPACE                                          = 682,
    ERR_NAME_CONSECUTIVE_SPACES                                     = 683,
    ERR_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS                  = 684,
    ERR_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END           = 685,
    ERR_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME                      = 686,
    ERR_RECRUIT_A_FRIEND_NOT_LINKED                                 = 687,
    ERR_RECRUIT_A_FRIEND_NOT_NOW                                    = 688,
    ERR_RECRUIT_A_FRIEND_SUMMON_LEVEL_MAX                           = 689,
    ERR_RECRUIT_A_FRIEND_SUMMON_COOLDOWN                            = 690,
    ERR_RECRUIT_A_FRIEND_SUMMON_OFFLINE                             = 691,
    ERR_RECRUIT_A_FRIEND_INSUF_EXPAN_LVL                            = 692,
    ERR_RECRUIT_A_FRIEND_MAP_INCOMING_TRANSFER_NOT_ALLOWED          = 693,
    ERR_NOT_SAME_ACCOUNT                                            = 694,
    ERR_BAD_ON_USE_ENCHANT                                          = 695,
    ERR_TRADE_SELF                                                  = 696,
    ERR_TOO_MANY_SOCKETS                                            = 697,
    ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS                   = 698,
    ERR_TRADE_TARGET_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS           = 699,
    ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS                = 700,
    ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS                = 701,
    ERR_SHAPESHIFT_FORM_CANNOT_EQUIP                                = 702,
    ERR_ITEM_INVENTORY_FULL_SATCHEL                                 = 703,
    ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED                            = 704,
    ERR_SCALING_STAT_ITEM_LEVEL_TOO_LOW                             = 705,
    ERR_PURCHASE_LEVEL_TOO_LOW                                      = 706,
    ERR_GROUP_SWAP_FAILED                                           = 707,
    ERR_INVITE_IN_COMBAT                                            = 708,
    ERR_INVALID_GLYPH_SLOT                                          = 709,
    ERR_GENERIC_NO_VALID_TARGETS                                    = 710,
    ERR_CALENDAR_EVENT_ALERT_S                                      = 711,
    ERR_PET_LEARN_SPELL_S                                           = 712,
    ERR_PET_LEARN_ABILITY_S                                         = 713,
    ERR_PET_SPELL_UNLEARNED_S                                       = 714,
    ERR_INVITE_UNKNOWN_REALM                                        = 715,
    ERR_INVITE_NO_PARTY_SERVER                                      = 716,
    ERR_INVITE_PARTY_BUSY                                           = 717,
    ERR_INVITE_PARTY_BUSY_PENDING_REQUEST                           = 718,
    ERR_INVITE_PARTY_BUSY_PENDING_SUGGEST                           = 719,
    ERR_PARTY_TARGET_AMBIGUOUS                                      = 720,
    ERR_PARTY_LFG_INVITE_RAID_LOCKED                                = 721,
    ERR_PARTY_LFG_BOOT_LIMIT                                        = 722,
    ERR_PARTY_LFG_BOOT_COOLDOWN_S                                   = 723,
    ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S                               = 724,
    ERR_PARTY_LFG_BOOT_INPATIENT_TIMER_S                            = 725,
    ERR_PARTY_LFG_BOOT_IN_PROGRESS                                  = 726,
    ERR_PARTY_LFG_BOOT_TOO_FEW_PLAYERS                              = 727,
    ERR_PARTY_LFG_BOOT_VOTE_SUCCEEDED                               = 728,
    ERR_PARTY_LFG_BOOT_VOTE_FAILED                                  = 729,
    ERR_PARTY_LFG_BOOT_DISALLOWED_BY_MAP                            = 730,
    ERR_PARTY_LFG_BOOT_DUNGEON_COMPLETE                             = 731,
    ERR_PARTY_LFG_BOOT_LOOT_ROLLS                                   = 732,
    ERR_PARTY_LFG_BOOT_VOTE_REGISTERED                              = 733,
    ERR_PARTY_PRIVATE_GROUP_ONLY                                    = 734,
    ERR_PARTY_LFG_TELEPORT_IN_COMBAT                                = 735,
    ERR_PARTY_TIME_RUNNING_SEASON_ID_MUST_MATCH                     = 736,
    ERR_RAID_DISALLOWED_BY_LEVEL                                    = 737,
    ERR_RAID_DISALLOWED_BY_CROSS_REALM                              = 738,
    ERR_PARTY_ROLE_NOT_AVAILABLE                                    = 739,
    ERR_JOIN_LFG_OBJECT_FAILED                                      = 740,
    ERR_LFG_REMOVED_LEVELUP                                         = 741,
    ERR_LFG_REMOVED_XP_TOGGLE                                       = 742,
    ERR_LFG_REMOVED_FACTION_CHANGE                                  = 743,
    ERR_BATTLEGROUND_INFO_THROTTLED                                 = 744,
    ERR_BATTLEGROUND_ALREADY_IN                                     = 745,
    ERR_ARENA_TEAM_CHANGE_FAILED_QUEUED                             = 746,
    ERR_ARENA_TEAM_PERMISSIONS                                      = 747,
    ERR_NOT_WHILE_FALLING                                           = 748,
    ERR_NOT_WHILE_MOVING                                            = 749,
    ERR_NOT_WHILE_FATIGUED                                          = 750,
    ERR_MAX_SOCKETS                                                 = 751,
    ERR_MULTI_CAST_ACTION_TOTEM_S                                   = 752,
    ERR_BATTLEGROUND_JOIN_LEVELUP                                   = 753,
    ERR_REMOVE_FROM_PVP_QUEUE_XP_GAIN                               = 754,
    ERR_BATTLEGROUND_JOIN_XP_GAIN                                   = 755,
    ERR_BATTLEGROUND_JOIN_MERCENARY                                 = 756,
    ERR_BATTLEGROUND_JOIN_TOO_MANY_HEALERS                          = 757,
    ERR_BATTLEGROUND_JOIN_RATED_TOO_MANY_HEALERS                    = 758,
    ERR_BATTLEGROUND_JOIN_TOO_MANY_TANKS                            = 759,
    ERR_BATTLEGROUND_JOIN_TOO_MANY_DAMAGE                           = 760,
    ERR_RAID_DIFFICULTY_FAILED                                      = 761,
    ERR_RAID_DIFFICULTY_CHANGED_S                                   = 762,
    ERR_LEGACY_RAID_DIFFICULTY_CHANGED_S                            = 763,
    ERR_RAID_LOCKOUT_CHANGED_S                                      = 764,
    ERR_RAID_CONVERTED_TO_PARTY                                     = 765,
    ERR_PARTY_CONVERTED_TO_RAID                                     = 766,
    ERR_PLAYER_DIFFICULTY_CHANGED_S                                 = 767,
    ERR_GMRESPONSE_DB_ERROR                                         = 768,
    ERR_BATTLEGROUND_JOIN_RANGE_INDEX                               = 769,
    ERR_ARENA_JOIN_RANGE_INDEX                                      = 770,
    ERR_REMOVE_FROM_PVP_QUEUE_FACTION_CHANGE                        = 771,
    ERR_BATTLEGROUND_JOIN_FAILED                                    = 772,
    ERR_BATTLEGROUND_JOIN_NO_VALID_SPEC_FOR_ROLE                    = 773,
    ERR_BATTLEGROUND_JOIN_RESPEC                                    = 774,
    ERR_BATTLEGROUND_INVITATION_DECLINED                            = 775,
    ERR_BATTLEGROUND_INVITATION_DECLINED_BY                         = 776,
    ERR_BATTLEGROUND_JOIN_TIMED_OUT                                 = 777,
    ERR_BATTLEGROUND_DUPE_QUEUE                                     = 778,
    ERR_BATTLEGROUND_JOIN_MUST_COMPLETE_QUEST                       = 779,
    ERR_IN_BATTLEGROUND_RESPEC                                      = 780,
    ERR_MAIL_LIMITED_DURATION_ITEM                                  = 781,
    ERR_YELL_RESTRICTED_TRIAL                                       = 782,
    ERR_CHAT_RAID_RESTRICTED_TRIAL                                  = 783,
    ERR_LFG_ROLE_CHECK_FAILED                                       = 784,
    ERR_LFG_ROLE_CHECK_FAILED_TIMEOUT                               = 785,
    ERR_LFG_ROLE_CHECK_FAILED_NOT_VIABLE                            = 786,
    ERR_LFG_READY_CHECK_FAILED                                      = 787,
    ERR_LFG_READY_CHECK_FAILED_TIMEOUT                              = 788,
    ERR_LFG_GROUP_FULL                                              = 789,
    ERR_LFG_NO_LFG_OBJECT                                           = 790,
    ERR_LFG_NO_SLOTS_PLAYER                                         = 791,
    ERR_LFG_NO_SLOTS_PARTY                                          = 792,
    ERR_LFG_NO_SPEC                                                 = 793,
    ERR_LFG_MISMATCHED_SLOTS                                        = 794,
    ERR_LFG_MISMATCHED_SLOTS_LOCAL_XREALM                           = 795,
    ERR_LFG_PARTY_PLAYERS_FROM_DIFFERENT_REALMS                     = 796,
    ERR_LFG_MEMBERS_NOT_PRESENT                                     = 797,
    ERR_LFG_GET_INFO_TIMEOUT                                        = 798,
    ERR_LFG_INVALID_SLOT                                            = 799,
    ERR_LFG_DESERTER_PLAYER                                         = 800,
    ERR_LFG_DESERTER_PARTY                                          = 801,
    ERR_LFG_DEAD                                                    = 802,
    ERR_LFG_RANDOM_COOLDOWN_PLAYER                                  = 803,
    ERR_LFG_RANDOM_COOLDOWN_PARTY                                   = 804,
    ERR_LFG_TOO_MANY_MEMBERS                                        = 805,
    ERR_LFG_TOO_FEW_MEMBERS                                         = 806,
    ERR_LFG_PROPOSAL_FAILED                                         = 807,
    ERR_LFG_PROPOSAL_DECLINED_SELF                                  = 808,
    ERR_LFG_PROPOSAL_DECLINED_PARTY                                 = 809,
    ERR_LFG_NO_SLOTS_SELECTED                                       = 810,
    ERR_LFG_NO_ROLES_SELECTED                                       = 811,
    ERR_LFG_ROLE_CHECK_INITIATED                                    = 812,
    ERR_LFG_READY_CHECK_INITIATED                                   = 813,
    ERR_LFG_PLAYER_DECLINED_ROLE_CHECK                              = 814,
    ERR_LFG_PLAYER_DECLINED_READY_CHECK                             = 815,
    ERR_LFG_JOINED_QUEUE                                            = 816,
    ERR_LFG_JOINED_FLEX_QUEUE                                       = 817,
    ERR_LFG_JOINED_RF_QUEUE                                         = 818,
    ERR_LFG_JOINED_SCENARIO_QUEUE                                   = 819,
    ERR_LFG_JOINED_WORLD_PVP_QUEUE                                  = 820,
    ERR_LFG_JOINED_BATTLEFIELD_QUEUE                                = 821,
    ERR_LFG_JOINED_LIST                                             = 822,
    ERR_LFG_LEFT_QUEUE                                              = 823,
    ERR_LFG_LEFT_LIST                                               = 824,
    ERR_LFG_ROLE_CHECK_ABORTED                                      = 825,
    ERR_LFG_READY_CHECK_ABORTED                                     = 826,
    ERR_LFG_CANT_USE_BATTLEGROUND                                   = 827,
    ERR_LFG_CANT_USE_DUNGEONS                                       = 828,
    ERR_LFG_REASON_TOO_MANY_LFG                                     = 829,
    ERR_LFG_FARM_LIMIT                                              = 830,
    ERR_LFG_NO_CROSS_FACTION_PARTIES                                = 831,
    ERR_INVALID_TELEPORT_LOCATION                                   = 832,
    ERR_TOO_FAR_TO_INTERACT                                         = 833,
    ERR_BATTLEGROUND_PLAYERS_FROM_DIFFERENT_REALMS                  = 834,
    ERR_DIFFICULTY_CHANGE_COOLDOWN_S                                = 835,
    ERR_DIFFICULTY_CHANGE_COMBAT_COOLDOWN_S                         = 836,
    ERR_DIFFICULTY_CHANGE_WORLDSTATE                                = 837,
    ERR_DIFFICULTY_CHANGE_ENCOUNTER                                 = 838,
    ERR_DIFFICULTY_CHANGE_COMBAT                                    = 839,
    ERR_DIFFICULTY_CHANGE_PLAYER_BUSY                               = 840,
    ERR_DIFFICULTY_CHANGE_PLAYER_ON_VEHICLE                         = 841,
    ERR_DIFFICULTY_CHANGE_ALREADY_STARTED                           = 842,
    ERR_DIFFICULTY_CHANGE_OTHER_HEROIC_S                            = 843,
    ERR_DIFFICULTY_CHANGE_HEROIC_INSTANCE_ALREADY_RUNNING           = 844,
    ERR_ARENA_TEAM_PARTY_SIZE                                       = 845,
    ERR_SOLO_SHUFFLE_WARGAME_GROUP_SIZE                             = 846,
    ERR_SOLO_SHUFFLE_WARGAME_GROUP_COMP                             = 847,
    ERR_SOLO_RBG_WARGAME_GROUP_SIZE                                 = 848,
    ERR_SOLO_RBG_WARGAME_GROUP_COMP                                 = 849,
    ERR_SOLO_MIN_ITEM_LEVEL                                         = 850,
    ERR_PVP_PLAYER_ABANDONED                                        = 851,
    ERR_BATTLEGROUND_JOIN_GROUP_QUEUE_WITHOUT_HEALER                = 852,
    ERR_QUEST_FORCE_REMOVED_S                                       = 853,
    ERR_ATTACK_NO_ACTIONS                                           = 854,
    ERR_IN_RANDOM_BG                                                = 855,
    ERR_IN_NON_RANDOM_BG                                            = 856,
    ERR_BN_FRIEND_SELF                                              = 857,
    ERR_BN_FRIEND_ALREADY                                           = 858,
    ERR_BN_FRIEND_BLOCKED                                           = 859,
    ERR_BN_FRIEND_LIST_FULL                                         = 860,
    ERR_BN_FRIEND_REQUEST_SENT                                      = 861,
    ERR_BN_BROADCAST_THROTTLE                                       = 862,
    ERR_BG_DEVELOPER_ONLY                                           = 863,
    ERR_CURRENCY_SPELL_SLOT_MISMATCH                                = 864,
    ERR_CURRENCY_NOT_TRADABLE                                       = 865,
    ERR_REQUIRES_EXPANSION_S                                        = 866,
    ERR_QUEST_FAILED_SPELL                                          = 867,
    ERR_TALENT_FAILED_UNSPENT_TALENT_POINTS                         = 868,
    ERR_TALENT_FAILED_NOT_ENOUGH_TALENTS_IN_PRIMARY_TREE            = 869,
    ERR_TALENT_FAILED_NO_PRIMARY_TREE_SELECTED                      = 870,
    ERR_TALENT_FAILED_CANT_REMOVE_TALENT                            = 871,
    ERR_TALENT_FAILED_UNKNOWN                                       = 872,
    ERR_TALENT_FAILED_IN_COMBAT                                     = 873,
    ERR_TALENT_FAILED_IN_PVP_MATCH                                  = 874,
    ERR_TALENT_FAILED_IN_MYTHIC_PLUS                                = 875,
    ERR_WARGAME_REQUEST_FAILURE                                     = 876,
    ERR_RANK_REQUIRES_AUTHENTICATOR                                 = 877,
    ERR_GUILD_BANK_VOUCHER_FAILED                                   = 878,
    ERR_WARGAME_REQUEST_SENT                                        = 879,
    ERR_REQUIRES_ACHIEVEMENT_I                                      = 880,
    ERR_REFUND_RESULT_EXCEED_MAX_CURRENCY                           = 881,
    ERR_CANT_BUY_QUANTITY                                           = 882,
    ERR_ITEM_IS_BATTLE_PAY_LOCKED                                   = 883,
    ERR_PARTY_ALREADY_IN_BATTLEGROUND_QUEUE                         = 884,
    ERR_PARTY_CONFIRMING_BATTLEGROUND_QUEUE                         = 885,
    ERR_BATTLEFIELD_TEAM_PARTY_SIZE                                 = 886,
    ERR_INSUFF_TRACKED_CURRENCY_IS                                  = 887,
    ERR_NOT_ON_TOURNAMENT_REALM                                     = 888,
    ERR_GUILD_TRIAL_ACCOUNT_TRIAL                                   = 889,
    ERR_GUILD_TRIAL_ACCOUNT_VETERAN                                 = 890,
    ERR_GUILD_UNDELETABLE_DUE_TO_LEVEL                              = 891,
    ERR_CANT_DO_THAT_IN_A_GROUP                                     = 892,
    ERR_GUILD_LEADER_REPLACED                                       = 893,
    ERR_TRANSMOGRIFY_CANT_EQUIP                                     = 894,
    ERR_TRANSMOGRIFY_INVALID_ITEM_TYPE                              = 895,
    ERR_TRANSMOGRIFY_NOT_SOULBOUND                                  = 896,
    ERR_TRANSMOGRIFY_INVALID_SOURCE                                 = 897,
    ERR_TRANSMOGRIFY_INVALID_DESTINATION                            = 898,
    ERR_TRANSMOGRIFY_MISMATCH                                       = 899,
    ERR_TRANSMOGRIFY_LEGENDARY                                      = 900,
    ERR_TRANSMOGRIFY_SAME_ITEM                                      = 901,
    ERR_TRANSMOGRIFY_SAME_APPEARANCE                                = 902,
    ERR_TRANSMOGRIFY_NOT_EQUIPPED                                   = 903,
    ERR_VOID_DEPOSIT_FULL                                           = 904,
    ERR_VOID_WITHDRAW_FULL                                          = 905,
    ERR_VOID_STORAGE_WRAPPED                                        = 906,
    ERR_VOID_STORAGE_STACKABLE                                      = 907,
    ERR_VOID_STORAGE_UNBOUND                                        = 908,
    ERR_VOID_STORAGE_REPAIR                                         = 909,
    ERR_VOID_STORAGE_CHARGES                                        = 910,
    ERR_VOID_STORAGE_QUEST                                          = 911,
    ERR_VOID_STORAGE_CONJURED                                       = 912,
    ERR_VOID_STORAGE_MAIL                                           = 913,
    ERR_VOID_STORAGE_BAG                                            = 914,
    ERR_VOID_TRANSFER_STORAGE_FULL                                  = 915,
    ERR_VOID_TRANSFER_INV_FULL                                      = 916,
    ERR_VOID_TRANSFER_INTERNAL_ERROR                                = 917,
    ERR_VOID_TRANSFER_ITEM_INVALID                                  = 918,
    ERR_DIFFICULTY_DISABLED_IN_LFG                                  = 919,
    ERR_VOID_STORAGE_UNIQUE                                         = 920,
    ERR_VOID_STORAGE_LOOT                                           = 921,
    ERR_VOID_STORAGE_HOLIDAY                                        = 922,
    ERR_VOID_STORAGE_DURATION                                       = 923,
    ERR_VOID_STORAGE_LOAD_FAILED                                    = 924,
    ERR_VOID_STORAGE_INVALID_ITEM                                   = 925,
    ERR_VOID_STORAGE_ACCOUNT_ITEM                                   = 926,
    ERR_PARENTAL_CONTROLS_CHAT_MUTED                                = 927,
    ERR_SOR_START_EXPERIENCE_INCOMPLETE                             = 928,
    ERR_SOR_INVALID_EMAIL                                           = 929,
    ERR_SOR_INVALID_COMMENT                                         = 930,
    ERR_CHALLENGE_MODE_RESET_COOLDOWN_S                             = 931,
    ERR_CHALLENGE_MODE_RESET_KEYSTONE                               = 932,
    ERR_PET_JOURNAL_ALREADY_IN_LOADOUT                              = 933,
    ERR_REPORT_SUBMITTED_SUCCESSFULLY                               = 934,
    ERR_REPORT_SUBMISSION_FAILED                                    = 935,
    ERR_SUGGESTION_SUBMITTED_SUCCESSFULLY                           = 936,
    ERR_BUG_SUBMITTED_SUCCESSFULLY                                  = 937,
    ERR_CHALLENGE_MODE_ENABLED                                      = 938,
    ERR_CHALLENGE_MODE_DISABLED                                     = 939,
    ERR_PETBATTLE_CREATE_FAILED                                     = 940,
    ERR_PETBATTLE_NOT_HERE                                          = 941,
    ERR_PETBATTLE_NOT_HERE_ON_TRANSPORT                             = 942,
    ERR_PETBATTLE_NOT_HERE_UNEVEN_GROUND                            = 943,
    ERR_PETBATTLE_NOT_HERE_OBSTRUCTED                               = 944,
    ERR_PETBATTLE_NOT_WHILE_IN_COMBAT                               = 945,
    ERR_PETBATTLE_NOT_WHILE_DEAD                                    = 946,
    ERR_PETBATTLE_NOT_WHILE_FLYING                                  = 947,
    ERR_PETBATTLE_TARGET_INVALID                                    = 948,
    ERR_PETBATTLE_TARGET_OUT_OF_RANGE                               = 949,
    ERR_PETBATTLE_TARGET_NOT_CAPTURABLE                             = 950,
    ERR_PETBATTLE_NOT_A_TRAINER                                     = 951,
    ERR_PETBATTLE_DECLINED                                          = 952,
    ERR_PETBATTLE_IN_BATTLE                                         = 953,
    ERR_PETBATTLE_INVALID_LOADOUT                                   = 954,
    ERR_PETBATTLE_ALL_PETS_DEAD                                     = 955,
    ERR_PETBATTLE_NO_PETS_IN_SLOTS                                  = 956,
    ERR_PETBATTLE_NO_ACCOUNT_LOCK                                   = 957,
    ERR_PETBATTLE_WILD_PET_TAPPED                                   = 958,
    ERR_PETBATTLE_RESTRICTED_ACCOUNT                                = 959,
    ERR_PETBATTLE_OPPONENT_NOT_AVAILABLE                            = 960,
    ERR_PETBATTLE_NOT_WHILE_IN_MATCHED_BATTLE                       = 961,
    ERR_CANT_HAVE_MORE_PETS_OF_THAT_TYPE                            = 962,
    ERR_CANT_HAVE_MORE_PETS                                         = 963,
    ERR_PVP_MAP_NOT_FOUND                                           = 964,
    ERR_PVP_MAP_NOT_SET                                             = 965,
    ERR_PETBATTLE_QUEUE_QUEUED                                      = 966,
    ERR_PETBATTLE_QUEUE_ALREADY_QUEUED                              = 967,
    ERR_PETBATTLE_QUEUE_JOIN_FAILED                                 = 968,
    ERR_PETBATTLE_QUEUE_JOURNAL_LOCK                                = 969,
    ERR_PETBATTLE_QUEUE_REMOVED                                     = 970,
    ERR_PETBATTLE_QUEUE_PROPOSAL_DECLINED                           = 971,
    ERR_PETBATTLE_QUEUE_PROPOSAL_TIMEOUT                            = 972,
    ERR_PETBATTLE_QUEUE_OPPONENT_DECLINED                           = 973,
    ERR_PETBATTLE_QUEUE_REQUEUED_INTERNAL                           = 974,
    ERR_PETBATTLE_QUEUE_REQUEUED_REMOVED                            = 975,
    ERR_PETBATTLE_QUEUE_SLOT_LOCKED                                 = 976,
    ERR_PETBATTLE_QUEUE_SLOT_EMPTY                                  = 977,
    ERR_PETBATTLE_QUEUE_SLOT_NO_TRACKER                             = 978,
    ERR_PETBATTLE_QUEUE_SLOT_NO_SPECIES                             = 979,
    ERR_PETBATTLE_QUEUE_SLOT_CANT_BATTLE                            = 980,
    ERR_PETBATTLE_QUEUE_SLOT_REVOKED                                = 981,
    ERR_PETBATTLE_QUEUE_SLOT_DEAD                                   = 982,
    ERR_PETBATTLE_QUEUE_SLOT_NO_PET                                 = 983,
    ERR_PETBATTLE_QUEUE_NOT_WHILE_NEUTRAL                           = 984,
    ERR_PETBATTLE_GAME_TIME_LIMIT_WARNING                           = 985,
    ERR_PETBATTLE_GAME_ROUNDS_LIMIT_WARNING                         = 986,
    ERR_HAS_RESTRICTION                                             = 987,
    ERR_ITEM_UPGRADE_ITEM_TOO_LOW_LEVEL                             = 988,
    ERR_ITEM_UPGRADE_NO_PATH                                        = 989,
    ERR_ITEM_UPGRADE_NO_MORE_UPGRADES                               = 990,
    ERR_BONUS_ROLL_EMPTY                                            = 991,
    ERR_CHALLENGE_MODE_FULL                                         = 992,
    ERR_CHALLENGE_MODE_IN_PROGRESS                                  = 993,
    ERR_CHALLENGE_MODE_INCORRECT_KEYSTONE                           = 994,
    ERR_BATTLETAG_FRIEND_NOT_FOUND                                  = 995,
    ERR_BATTLETAG_FRIEND_NOT_VALID                                  = 996,
    ERR_BATTLETAG_FRIEND_NOT_ALLOWED                                = 997,
    ERR_BATTLETAG_FRIEND_THROTTLED                                  = 998,
    ERR_BATTLETAG_FRIEND_SUCCESS                                    = 999,
    ERR_PET_TOO_HIGH_LEVEL_TO_UNCAGE                                = 1000,
    ERR_PETBATTLE_INTERNAL                                          = 1001,
    ERR_CANT_CAGE_PET_YET                                           = 1002,
    ERR_NO_LOOT_IN_CHALLENGE_MODE                                   = 1003,
    ERR_QUEST_PET_BATTLE_VICTORIES_PVP_II                           = 1004,
    ERR_ROLE_CHECK_ALREADY_IN_PROGRESS                              = 1005,
    ERR_RECRUIT_A_FRIEND_ACCOUNT_LIMIT                              = 1006,
    ERR_RECRUIT_A_FRIEND_FAILED                                     = 1007,
    ERR_SET_LOOT_PERSONAL                                           = 1008,
    ERR_SET_LOOT_METHOD_FAILED_COMBAT                               = 1009,
    ERR_REAGENT_BANK_FULL                                           = 1010,
    ERR_REAGENT_BANK_LOCKED                                         = 1011,
    ERR_GARRISON_BUILDING_EXISTS                                    = 1012,
    ERR_GARRISON_INVALID_PLOT                                       = 1013,
    ERR_GARRISON_INVALID_BUILDINGID                                 = 1014,
    ERR_GARRISON_INVALID_PLOT_BUILDING                              = 1015,
    ERR_GARRISON_REQUIRES_BLUEPRINT                                 = 1016,
    ERR_GARRISON_NOT_ENOUGH_CURRENCY                                = 1017,
    ERR_GARRISON_NOT_ENOUGH_GOLD                                    = 1018,
    ERR_GARRISON_COMPLETE_MISSION_WRONG_FOLLOWER_TYPE               = 1019,
    ERR_ALREADY_USING_LFG_LIST                                      = 1020,
    ERR_RESTRICTED_ACCOUNT_LFG_LIST_TRIAL                           = 1021,
    ERR_TOY_USE_LIMIT_REACHED                                       = 1022,
    ERR_TOY_ALREADY_KNOWN                                           = 1023,
    ERR_TRANSMOG_SET_ALREADY_KNOWN                                  = 1024,
    ERR_NOT_ENOUGH_CURRENCY                                         = 1025,
    ERR_SPEC_IS_DISABLED                                            = 1026,
    ERR_FEATURE_RESTRICTED_TRIAL                                    = 1027,
    ERR_CANT_BE_OBLITERATED                                         = 1028,
    ERR_CANT_BE_SCRAPPED                                            = 1029,
    ERR_CANT_BE_RECRAFTED                                           = 1030,
    ERR_ARTIFACT_RELIC_DOES_NOT_MATCH_ARTIFACT                      = 1031,
    ERR_MUST_EQUIP_ARTIFACT                                         = 1032,
    ERR_CANT_DO_THAT_RIGHT_NOW                                      = 1033,
    ERR_AFFECTING_COMBAT                                            = 1034,
    ERR_EQUIPMENT_MANAGER_COMBAT_SWAP_S                             = 1035,
    ERR_EQUIPMENT_MANAGER_BAGS_FULL                                 = 1036,
    ERR_EQUIPMENT_MANAGER_MISSING_ITEM_S                            = 1037,
    ERR_MOVIE_RECORDING_WARNING_PERF                                = 1038,
    ERR_MOVIE_RECORDING_WARNING_DISK_FULL                           = 1039,
    ERR_MOVIE_RECORDING_WARNING_NO_MOVIE                            = 1040,
    ERR_MOVIE_RECORDING_WARNING_REQUIREMENTS                        = 1041,
    ERR_MOVIE_RECORDING_WARNING_COMPRESSING                         = 1042,
    ERR_NO_CHALLENGE_MODE_REWARD                                    = 1043,
    ERR_CLAIMED_CHALLENGE_MODE_REWARD                               = 1044,
    ERR_CHALLENGE_MODE_PERIOD_RESET_SS                              = 1045,
    ERR_CANT_DO_THAT_CHALLENGE_MODE_ACTIVE                          = 1046,
    ERR_TALENT_FAILED_REST_AREA                                     = 1047,
    ERR_CANNOT_ABANDON_LAST_PET                                     = 1048,
    ERR_TEST_CVAR_SET_SSS                                           = 1049,
    ERR_QUEST_TURN_IN_FAIL_REASON                                   = 1050,
    ERR_CLAIMED_CHALLENGE_MODE_REWARD_OLD                           = 1051,
    ERR_TALENT_GRANTED_BY_AURA                                      = 1052,
    ERR_CHALLENGE_MODE_ALREADY_COMPLETE                             = 1053,
    ERR_GLYPH_TARGET_NOT_AVAILABLE                                  = 1054,
    ERR_PVP_WARMODE_TOGGLE_ON                                       = 1055,
    ERR_PVP_WARMODE_TOGGLE_OFF                                      = 1056,
    ERR_SPELL_FAILED_LEVEL_REQUIREMENT                              = 1057,
    ERR_SPELL_FAILED_CANT_FLY_HERE                                  = 1058,
    ERR_BATTLEGROUND_JOIN_REQUIRES_LEVEL                            = 1059,
    ERR_BATTLEGROUND_JOIN_DISQUALIFIED                              = 1060,
    ERR_BATTLEGROUND_JOIN_DISQUALIFIED_NO_NAME                      = 1061,
    ERR_VOICE_CHAT_GENERIC_UNABLE_TO_CONNECT                        = 1062,
    ERR_VOICE_CHAT_SERVICE_LOST                                     = 1063,
    ERR_VOICE_CHAT_CHANNEL_NAME_TOO_SHORT                           = 1064,
    ERR_VOICE_CHAT_CHANNEL_NAME_TOO_LONG                            = 1065,
    ERR_VOICE_CHAT_CHANNEL_ALREADY_EXISTS                           = 1066,
    ERR_VOICE_CHAT_TARGET_NOT_FOUND                                 = 1067,
    ERR_VOICE_CHAT_TOO_MANY_REQUESTS                                = 1068,
    ERR_VOICE_CHAT_PLAYER_SILENCED                                  = 1069,
    ERR_VOICE_CHAT_PARENTAL_DISABLE_ALL                             = 1070,
    ERR_VOICE_CHAT_DISABLED                                         = 1071,
    ERR_NO_PVP_REWARD                                               = 1072,
    ERR_CLAIMED_PVP_REWARD                                          = 1073,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_ESSENCE_NOT_UNLOCKED       = 1074,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_CANT_REMOVE_ESSENCE        = 1075,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_CONDITION_FAILED           = 1076,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_REST_AREA                  = 1077,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_SLOT_LOCKED                = 1078,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_NOT_AT_FORGE               = 1079,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_HEART_LEVEL_TOO_LOW        = 1080,
    ERR_AZERITE_ESSENCE_SELECTION_FAILED_NOT_EQUIPPED               = 1081,
    ERR_SOCKETING_REQUIRES_PUNCHCARDRED_GEM                         = 1082,
    ERR_SOCKETING_PUNCHCARDRED_GEM_ONLY_IN_PUNCHCARDREDSLOT         = 1083,
    ERR_SOCKETING_REQUIRES_PUNCHCARDYELLOW_GEM                      = 1084,
    ERR_SOCKETING_PUNCHCARDYELLOW_GEM_ONLY_IN_PUNCHCARDYELLOWSLOT   = 1085,
    ERR_SOCKETING_REQUIRES_PUNCHCARDBLUE_GEM                        = 1086,
    ERR_SOCKETING_PUNCHCARDBLUE_GEM_ONLY_IN_PUNCHCARDBLUESLOT       = 1087,
    ERR_SOCKETING_REQUIRES_DOMINATION_SHARD                         = 1088,
    ERR_SOCKETING_DOMINATION_SHARD_ONLY_IN_DOMINATIONSLOT           = 1089,
    ERR_SOCKETING_REQUIRES_CYPHER_GEM                               = 1090,
    ERR_SOCKETING_CYPHER_GEM_ONLY_IN_CYPHERSLOT                     = 1091,
    ERR_SOCKETING_REQUIRES_TINKER_GEM                               = 1092,
    ERR_SOCKETING_TINKER_GEM_ONLY_IN_TINKERSLOT                     = 1093,
    ERR_SOCKETING_REQUIRES_PRIMORDIAL_GEM                           = 1094,
    ERR_SOCKETING_PRIMORDIAL_GEM_ONLY_IN_PRIMORDIALSLOT             = 1095,
    ERR_SOCKETING_REQUIRES_FRAGRANCE_GEM                            = 1096,
    ERR_SOCKETING_FRAGRANCE_GEM_ONLY_IN_FRAGRANCESLOT               = 1097,
    ERR_LEVEL_LINKING_RESULT_LINKED                                 = 1098,
    ERR_LEVEL_LINKING_RESULT_UNLINKED                               = 1099,
    ERR_CLUB_FINDER_ERROR_POST_CLUB                                 = 1100,
    ERR_CLUB_FINDER_ERROR_APPLY_CLUB                                = 1101,
    ERR_CLUB_FINDER_ERROR_RESPOND_APPLICANT                         = 1102,
    ERR_CLUB_FINDER_ERROR_CANCEL_APPLICATION                        = 1103,
    ERR_CLUB_FINDER_ERROR_TYPE_ACCEPT_APPLICATION                   = 1104,
    ERR_CLUB_FINDER_ERROR_TYPE_NO_INVITE_PERMISSIONS                = 1105,
    ERR_CLUB_FINDER_ERROR_TYPE_NO_POSTING_PERMISSIONS               = 1106,
    ERR_CLUB_FINDER_ERROR_TYPE_APPLICANT_LIST                       = 1107,
    ERR_CLUB_FINDER_ERROR_TYPE_APPLICANT_LIST_NO_PERM               = 1108,
    ERR_CLUB_FINDER_ERROR_TYPE_FINDER_NOT_AVAILABLE                 = 1109,
    ERR_CLUB_FINDER_ERROR_TYPE_GET_POSTING_IDS                      = 1110,
    ERR_CLUB_FINDER_ERROR_TYPE_JOIN_APPLICATION                     = 1111,
    ERR_CLUB_FINDER_ERROR_TYPE_REALM_NOT_ELIGIBLE                   = 1112,
    ERR_CLUB_FINDER_ERROR_TYPE_FLAGGED_RENAME                       = 1113,
    ERR_CLUB_FINDER_ERROR_TYPE_FLAGGED_DESCRIPTION_CHANGE           = 1114,
    ERR_ITEM_INTERACTION_NOT_ENOUGH_GOLD                            = 1115,
    ERR_ITEM_INTERACTION_NOT_ENOUGH_CURRENCY                        = 1116,
    ERR_ITEM_INTERACTION_NO_CONVERSION_OUTPUT                       = 1117,
    ERR_PLAYER_CHOICE_ERROR_PENDING_CHOICE                          = 1118,
    ERR_SOULBIND_INVALID_CONDUIT                                    = 1119,
    ERR_SOULBIND_INVALID_CONDUIT_ITEM                               = 1120,
    ERR_SOULBIND_INVALID_TALENT                                     = 1121,
    ERR_SOULBIND_DUPLICATE_CONDUIT                                  = 1122,
    ERR_ACTIVATE_SOULBIND_S                                         = 1123,
    ERR_ACTIVATE_SOULBIND_FAILED_REST_AREA                          = 1124,
    ERR_CANT_USE_PROFANITY                                          = 1125,
    ERR_NOT_IN_PET_BATTLE                                           = 1126,
    ERR_NOT_IN_NPE                                                  = 1127,
    ERR_NO_SPEC                                                     = 1128,
    ERR_NO_DOMINATIONSHARD_OVERWRITE                                = 1129,
    ERR_USE_WEEKLY_REWARDS_DISABLED                                 = 1130,
    ERR_CROSS_FACTION_GROUP_JOINED                                  = 1131,
    ERR_CANT_TARGET_UNFRIENDLY_IN_OVERWORLD                         = 1132,
    ERR_EQUIPABLESPELLS_SLOTS_FULL                                  = 1133,
    ERR_ITEM_MOD_APPEARANCE_GROUP_ALREADY_KNOWN                     = 1134,
    ERR_CANT_BULK_SELL_ITEM_WITH_REFUND                             = 1135,
    ERR_NO_SOULBOUND_ITEM_IN_ACCOUNT_BANK                           = 1136,
    ERR_NO_REFUNDABLE_ITEM_IN_ACCOUNT_BANK                          = 1137,
    ERR_CANT_DELETE_IN_ACCOUNT_BANK                                 = 1138,
    ERR_NO_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK                      = 1139,
    ERR_NO_OPEN_IMMEDIATE_CONTAINER_IN_ACCOUNT_BANK                 = 1140,
    ERR_CANT_TRADE_ACCOUNT_ITEM                                     = 1141,
    ERR_NO_ACCOUNT_INVENTORY_LOCK                                   = 1142,
    ERR_BANK_NOT_ACCESSIBLE                                         = 1143,
    ERR_TOO_MANY_ACCOUNT_BANK_TABS                                  = 1144,
    ERR_ACCOUNT_BANK_TAB_NOT_UNLOCKED                               = 1145,
    ERR_BANK_TAB_INVALID_NAME                                       = 1146,
    ERR_BANK_TAB_INVALID_TEXT                                       = 1147,
    ERR_WOW_LABS_PARTY_ERROR_TYPE_PARTY_IS_FULL                     = 1148,
    ERR_WOW_LABS_PARTY_ERROR_TYPE_MAX_INVITE_SENT                   = 1149,
    ERR_WOW_LABS_PARTY_ERROR_TYPE_PLAYER_ALREADY_INVITED            = 1150,
    ERR_WOW_LABS_PARTY_ERROR_TYPE_PARTY_INVITE_INVALID              = 1151,
    ERR_WOW_LABS_LOBBY_MATCHMAKER_ERROR_ENTER_QUEUE_FAILED          = 1152,
    ERR_WOW_LABS_LOBBY_MATCHMAKER_ERROR_LEAVE_QUEUE_FAILED          = 1153,
    ERR_TARGET_IS_SELF_FOUND_CANNOT_TRADE                           = 1154,
    ERR_PLAYER_IS_SELF_FOUND_CANNOT_TRADE                           = 1155,
    ERR_MAIL_RECEPIENT_IS_SELF_FOUND_CANNOT_RECEIVE_MAIL            = 1156,
    ERR_PLAYER_IS_SELF_FOUND_CANNOT_SEND_MAIL                       = 1157,
    ERR_PLAYER_IS_SELF_FOUND_CANNOT_USE_AUCTION_HOUSE               = 1158,
    ERR_MAIL_TARGET_CANNOT_RECEIVE_MAIL                             = 1159,
    ERR_REMIX_INVALID_TRANSFER_REQUEST                              = 1160,
    ERR_CURRENCY_TRANSFER_INVALID_CHARACTER                         = 1161,
    ERR_CURRENCY_TRANSFER_INVALID_CURRENCY                          = 1162,
    ERR_CURRENCY_TRANSFER_INSUFFICIENT_CURRENCY                     = 1163,
    ERR_CURRENCY_TRANSFER_MAX_QUANTITY                              = 1164,
    ERR_CURRENCY_TRANSFER_NO_VALID_SOURCE                           = 1165,
    ERR_CURRENCY_TRANSFER_CHARACTER_LOGGED_IN                       = 1166,
    ERR_CURRENCY_TRANSFER_SERVER_ERROR                              = 1167,
    ERR_CURRENCY_TRANSFER_UNMET_REQUIREMENTS                        = 1168,
};

enum class MountResult : uint32
{
    InvalidMountee = 0,
    TooFarAway     = 1,
    AlreadyMounted = 2,
    NotMountable   = 3,
    NotYourPet     = 4,
    Other          = 5,
    Looting        = 6,
    RaceCantMount  = 7,
    Shapeshifted   = 8,
    ForcedDismount = 9,
    Ok             = 10 // never sent
};

enum AreaId : uint32
{
    AREA_WINTERGRASP                = 4197,
    AREA_THE_SUNKEN_RING            = 4538,
    AREA_THE_BROKEN_TEMPLATE        = 4539,
    AREA_WINTERGRASP_FORTRESS       = 4575,
    AREA_THE_CHILLED_QUAGMIRE       = 4589,
    AREA_WESTPARK_WORKSHOP          = 4611,
    AREA_EASTPARK_WORKSHOP          = 4612,
};

enum WorldState : uint32
{
    WS_CURRENT_PVP_SEASON_ID                = 3191,
    WS_PREVIOUS_PVP_SEASON_ID               = 3901,

    WS_TEAM_IN_INSTANCE_ALLIANCE            = 4485,
    WS_TEAM_IN_INSTANCE_HORDE               = 4486,

    WS_BATTLEFIELD_WG_VEHICLE_H             = 3490,
    WS_BATTLEFIELD_WG_MAX_VEHICLE_H         = 3491,
    WS_BATTLEFIELD_WG_VEHICLE_A             = 3680,
    WS_BATTLEFIELD_WG_MAX_VEHICLE_A         = 3681,
    WS_BATTLEFIELD_WG_WORKSHOP_K_W          = 3698,
    WS_BATTLEFIELD_WG_WORKSHOP_K_E          = 3699,
    WS_BATTLEFIELD_WG_WORKSHOP_NW           = 3700,
    WS_BATTLEFIELD_WG_WORKSHOP_NE           = 3701,
    WS_BATTLEFIELD_WG_WORKSHOP_SW           = 3702,
    WS_BATTLEFIELD_WG_WORKSHOP_SE           = 3703,
    WS_BATTLEFIELD_WG_SHOW_TIME_BATTLE_END  = 3710,
    WS_BATTLEFIELD_WG_TIME_BATTLE_END       = 3781,
    WS_BATTLEFIELD_WG_SHOW_TIME_NEXT_BATTLE = 3801,
    WS_BATTLEFIELD_WG_DEFENDER              = 3802,
    WS_BATTLEFIELD_WG_ATTACKER              = 3803,
    WS_BATTLEFIELD_WG_ATTACKED_H            = 4022,
    WS_BATTLEFIELD_WG_ATTACKED_A            = 4023,
    WS_BATTLEFIELD_WG_DEFENDED_H            = 4024,
    WS_BATTLEFIELD_WG_DEFENDED_A            = 4025,
    WS_BATTLEFIELD_WG_TIME_NEXT_BATTLE      = 4354,

    WS_BATTLEFIELD_TB_ALLIANCE_CONTROLS_SHOW  = 5385,
    WS_BATTLEFIELD_TB_HORDE_CONTROLS_SHOW     = 5384,
    WS_BATTLEFIELD_TB_ALLIANCE_ATTACKING_SHOW = 5546,
    WS_BATTLEFIELD_TB_HORDE_ATTACKING_SHOW    = 5547,

    WS_BATTLEFIELD_TB_BUILDINGS_CAPTURED      = 5348,
    WS_BATTLEFIELD_TB_BUILDINGS_CAPTURED_SHOW = 5349,
    WS_BATTLEFIELD_TB_TOWERS_DESTROYED        = 5347,
    WS_BATTLEFIELD_TB_TOWERS_DESTROYED_SHOW   = 5350,

    WS_BATTLEFIELD_TB_FACTION_CONTROLLING = 5334, // 1 -> Alliance, 2 -> Horde

    WS_BATTLEFIELD_TB_TIME_NEXT_BATTLE      = 5332,
    WS_BATTLEFIELD_TB_TIME_NEXT_BATTLE_SHOW = 5387,
    WS_BATTLEFIELD_TB_TIME_BATTLE_END       = 5333,
    WS_BATTLEFIELD_TB_TIME_BATTLE_END_SHOW  = 5346,

    WS_BATTLEFIELD_TB_STATE_PREPARATIONS = 5684,
    WS_BATTLEFIELD_TB_STATE_BATTLE       = 5344,

    WS_BATTLEFIELD_TB_KEEP_HORDE    = 5469,
    WS_BATTLEFIELD_TB_KEEP_ALLIANCE = 5470,

    WS_BATTLEFIELD_TB_GARRISON_HORDE_CONTROLLED    = 5418,
    WS_BATTLEFIELD_TB_GARRISON_HORDE_CAPTURING     = 5419,
    WS_BATTLEFIELD_TB_GARRISON_NEUTRAL             = 5420, // unused
    WS_BATTLEFIELD_TB_GARRISON_ALLIANCE_CAPTURING  = 5421,
    WS_BATTLEFIELD_TB_GARRISON_ALLIANCE_CONTROLLED = 5422,

    WS_BATTLEFIELD_TB_VIGIL_HORDE_CONTROLLED    = 5423,
    WS_BATTLEFIELD_TB_VIGIL_HORDE_CAPTURING     = 5424,
    WS_BATTLEFIELD_TB_VIGIL_NEUTRAL             = 5425, // unused
    WS_BATTLEFIELD_TB_VIGIL_ALLIANCE_CAPTURING  = 5426,
    WS_BATTLEFIELD_TB_VIGIL_ALLIANCE_CONTROLLED = 5427,

    WS_BATTLEFIELD_TB_SLAGWORKS_HORDE_CONTROLLED    = 5428,
    WS_BATTLEFIELD_TB_SLAGWORKS_HORDE_CAPTURING     = 5429,
    WS_BATTLEFIELD_TB_SLAGWORKS_NEUTRAL             = 5430, // unused
    WS_BATTLEFIELD_TB_SLAGWORKS_ALLIANCE_CAPTURING  = 5431,
    WS_BATTLEFIELD_TB_SLAGWORKS_ALLIANCE_CONTROLLED = 5432,

    WS_BATTLEFIELD_TB_WEST_INTACT_HORDE      = 5433,
    WS_BATTLEFIELD_TB_WEST_DAMAGED_HORDE     = 5434,
    WS_BATTLEFIELD_TB_WEST_DESTROYED_NEUTRAL = 5435,
    WS_BATTLEFIELD_TB_WEST_INTACT_ALLIANCE   = 5436,
    WS_BATTLEFIELD_TB_WEST_DAMAGED_ALLIANCE  = 5437,
    WS_BATTLEFIELD_TB_WEST_INTACT_NEUTRAL    = 5453, // unused
    WS_BATTLEFIELD_TB_WEST_DAMAGED_NEUTRAL   = 5454, // unused

    WS_BATTLEFIELD_TB_SOUTH_INTACT_HORDE      = 5438,
    WS_BATTLEFIELD_TB_SOUTH_DAMAGED_HORDE     = 5439,
    WS_BATTLEFIELD_TB_SOUTH_DESTROYED_NEUTRAL = 5440,
    WS_BATTLEFIELD_TB_SOUTH_INTACT_ALLIANCE   = 5441,
    WS_BATTLEFIELD_TB_SOUTH_DAMAGED_ALLIANCE  = 5442,
    WS_BATTLEFIELD_TB_SOUTH_INTACT_NEUTRAL    = 5455, // unused
    WS_BATTLEFIELD_TB_SOUTH_DAMAGED_NEUTRAL   = 5456, // unused

    WS_BATTLEFIELD_TB_EAST_INTACT_HORDE      = 5443,
    WS_BATTLEFIELD_TB_EAST_DAMAGED_HORDE     = 5444,
    WS_BATTLEFIELD_TB_EAST_DESTROYED_NEUTRAL = 5445,
    WS_BATTLEFIELD_TB_EAST_INTACT_ALLIANCE   = 5446,
    WS_BATTLEFIELD_TB_EAST_DAMAGED_ALLIANCE  = 5447,
    WS_BATTLEFIELD_TB_EAST_INTACT_NEUTRAL    = 5451,
    WS_BATTLEFIELD_TB_EAST_DAMAGED_NEUTRAL   = 5452,

    WS_WAR_MODE_HORDE_BUFF_VALUE    = 17042,
    WS_WAR_MODE_ALLIANCE_BUFF_VALUE = 17043,
};

#endif
