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

#ifndef DBCENUMS_H
#define DBCENUMS_H

#include "Define.h"
#include <array>

#pragma pack(push, 1)

struct DBCPosition2D
{
    float X;
    float Y;
};

struct DBCPosition3D
{
    float X;
    float Y;
    float Z;
};

#pragma pack(pop)
enum LevelLimit : uint8
{
    // Client expected level limitation, like as used in DBC item max levels for "until max player level"
    // use as default max player level, must be fit max level for used client
    // also see MAX_LEVEL and STRONG_MAX_LEVEL define
    DEFAULT_MAX_LEVEL = 80,

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
    MAX_LEVEL = 100,

    // Server side limitation. Base at used code requirements.
    // also see MAX_LEVEL and GT_MAX_LEVEL define
    STRONG_MAX_LEVEL = 255,
};

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 15
};

// must be max value in PvPDificulty slot+1
#define MAX_BATTLEGROUND_BRACKETS  16

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = 6
};

enum AchievementFaction
{
    ACHIEVEMENT_FACTION_HORDE           = 0,
    ACHIEVEMENT_FACTION_ALLIANCE        = 1,
    ACHIEVEMENT_FACTION_ANY             = -1
};

enum AchievementFlags
{
    ACHIEVEMENT_FLAG_COUNTER               = 0x00000001,    // Just count statistic (never stop and complete)
    ACHIEVEMENT_FLAG_HIDDEN                = 0x00000002,    // Not sent to client - internal use only
    ACHIEVEMENT_FLAG_STORE_MAX_VALUE       = 0x00000004,    // Store only max value? used only in "Reach level xx"
    ACHIEVEMENT_FLAG_SUMM                  = 0x00000008,    // Use summ criteria value from all requirements (and calculate max value)
    ACHIEVEMENT_FLAG_MAX_USED              = 0x00000010,    // Show max criteria (and calculate max value ??)
    ACHIEVEMENT_FLAG_REQ_COUNT             = 0x00000020,    // Use not zero req count (and calculate max value)
    ACHIEVEMENT_FLAG_AVERAGE               = 0x00000040,    // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_BAR                   = 0x00000080,    // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_REALM_FIRST_REACH     = 0x00000100,    //
    ACHIEVEMENT_FLAG_REALM_FIRST_KILL      = 0x00000200     //
};

#define MAX_CRITERIA_REQUIREMENTS 2

enum AchievementCriteriaCondition
{
    ACHIEVEMENT_CRITERIA_CONDITION_NONE            = 0,
    ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH        = 1,    // reset progress on death
    ACHIEVEMENT_CRITERIA_CONDITION_UNK2            = 2,    // only used in "Complete a daily quest every day for five consecutive days"
    ACHIEVEMENT_CRITERIA_CONDITION_BG_MAP          = 3,    // requires you to be on specific map, reset at change
    ACHIEVEMENT_CRITERIA_CONDITION_NO_LOSE         = 4,    // only used in "Win 10 arenas without losing"
    ACHIEVEMENT_CRITERIA_CONDITION_NO_SPELL_HIT    = 9,    // requires the player not to be hit by specific spell
    ACHIEVEMENT_CRITERIA_CONDITION_NOT_IN_GROUP    = 10,   // requires the player not to be in group
    ACHIEVEMENT_CRITERIA_CONDITION_UNK13           = 13,   // unk

    ACHIEVEMENT_CRITERIA_CONDITION_MAX
};

enum AchievementCriteriaFlags
{
    ACHIEVEMENT_CRITERIA_FLAG_SHOW_PROGRESS_BAR = 0x00000001,         // Show progress as bar
    ACHIEVEMENT_CRITERIA_FLAG_HIDDEN            = 0x00000002,         // Not show criteria in client
    ACHIEVEMENT_CRITERIA_FLAG_FAIL_ACHIEVEMENT  = 0x00000004,         // BG related??
    ACHIEVEMENT_CRITERIA_FLAG_RESET_ON_START    = 0x00000008,         //
    ACHIEVEMENT_CRITERIA_FLAG_IS_DATE           = 0x00000010,         // not used
    ACHIEVEMENT_CRITERIA_FLAG_MONEY_COUNTER     = 0x00000020          // Displays counter as money
};

enum AchievementCriteriaTimedTypes : uint8
{
    ACHIEVEMENT_TIMED_TYPE_EVENT            = 1,    // Timer is started by internal event with id in timerStartEvent
    ACHIEVEMENT_TIMED_TYPE_QUEST            = 2,    // Timer is started by accepting quest with entry in timerStartEvent
    ACHIEVEMENT_TIMED_TYPE_SPELL_CASTER     = 5,    // Timer is started by casting a spell with entry in timerStartEvent
    ACHIEVEMENT_TIMED_TYPE_SPELL_TARGET     = 6,    // Timer is started by being target of spell with entry in timerStartEvent
    ACHIEVEMENT_TIMED_TYPE_CREATURE         = 7,    // Timer is started by killing creature with entry in timerStartEvent
    ACHIEVEMENT_TIMED_TYPE_ITEM             = 9,    // Timer is started by using item with entry in timerStartEvent

    ACHIEVEMENT_TIMED_TYPE_MAX
};

enum AchievementCriteriaTypes : uint8
{
    ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE                 = 0,
    ACHIEVEMENT_CRITERIA_TYPE_WIN_BG                        = 1,
    ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL                   = 5,
    ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL             = 7,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT          = 8,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT          = 9,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY    = 10, // you have to complete a daily quest x times in a row
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE       = 11,
    ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE                   = 13,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST          = 14,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND         = 15,
    ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP                  = 16,
    ACHIEVEMENT_CRITERIA_TYPE_DEATH                         = 17,
    ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON              = 18,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID                 = 19,
    ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE            = 20,
    ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER              = 23,
    ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING            = 24,
    ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM                   = 26,
    ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST                = 27,
    ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET               = 28,
    ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL                    = 29,
    ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE          = 30,
    ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA        = 31,
    ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA                     = 32,
    ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA                    = 33,
    ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL                   = 34,
    ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL                = 35,
    ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM                      = 36,
    ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA               = 37,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING           = 38,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING       = 39,
    ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL             = 40,
    ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM                      = 41,
    ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM                     = 42,
    ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA                  = 43,
    ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK                      = 44,
    ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT                 = 45,
    ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION               = 46,
    ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION       = 47,
    ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP             = 48,
    ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM               = 49,
    ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT             = 50, /// @todo itemlevel is mentioned in text but not present in dbc
    ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT            = 51,
    ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS                      = 52,
    ACHIEVEMENT_CRITERIA_TYPE_HK_RACE                       = 53,
    ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE                      = 54,
    ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE                  = 55,
    ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS             = 56, /// @todo in some cases map not present, and in some cases need do without die
    ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM                    = 57,
    ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS            = 59,
    ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS        = 60,
    ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS       = 61,
    ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD       = 62,
    ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING     = 63,
    ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER          = 65,
    ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL           = 66,
    ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY                    = 67,
    ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT                = 68,
    ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2              = 69,
    ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL              = 70,
    ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT            = 72,
    /// @todo 73: Achievements 1515, 1241, 1103 (Name: Mal'Ganis)
    ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN                      = 74,
    ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS        = 75,
    ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL                      = 76,
    ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL                     = 77,
    ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE            = 78,
    ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS       = 80,
    ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION                = 82,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID           = 83,
    ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS                  = 84,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD          = 85,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED      = 86,
    ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION       = 87,
    ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION       = 88,
    ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS                = 89,
    ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM                = 90,
    ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM             = 91,
    ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED                     = 93,
    ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED                    = 94,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH                = 95,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER                 = 96,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT                  = 97,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER            = 98,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR                 = 99,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_RATING                = 100,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT             = 101,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED          = 102,
    ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED         = 103,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CAST             = 104,
    ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED        = 105,
    ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED      = 106,
    ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED               = 107,
    ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN            = 108,
    ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE                     = 109,
    ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2                   = 110, /// @todo target entry is missing
    ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE              = 112,
    ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL           = 113,
    ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS           = 114,
    ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS       = 115,
    ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS = 119,
};

#define ACHIEVEMENT_CRITERIA_TYPE_TOTAL 124

enum AchievementCategory
{
    CATEGORY_CHILDRENS_WEEK     = 163
};

enum AreaFlags
{
    AREA_FLAG_UNK0               = 0x00000001,                // Unknown
    AREA_FLAG_UNK1               = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2               = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL      = 0x00000008,                // city and city subzones
    AREA_FLAG_UNK3               = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2     = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS        = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA              = 0x00000080,                // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL            = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY               = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND            = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY          = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY           = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1            = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_OUTLAND2           = 0x00004000,                // expansion zones? (only Circle of Blood Arena not have this flag, but have 0x00000400 flag)
    AREA_FLAG_OUTDOOR_PVP        = 0x00008000,                // pvp objective area? (Death's Door also has this flag although it's no pvp object area)
    AREA_FLAG_ARENA_INSTANCE     = 0x00010000,                // used by instanced arenas only
    AREA_FLAG_UNUSED2            = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA     = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK4               = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL           = 0x00100000,                // used for some starting areas with ExplorationLevel <= 15
    AREA_FLAG_TOWN               = 0x00200000,                // small towns with Inn
    AREA_FLAG_REST_ZONE_HORDE    = 0x00400000,                // Instead of using areatriggers, the zone will act as one for Horde players (Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion, etc)
    AREA_FLAG_REST_ZONE_ALLIANCE = 0x00800000,                // Instead of using areatriggers, the zone will act as one for Alliance players (Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion, etc)
    AREA_FLAG_WINTERGRASP        = 0x01000000,                // Wintergrasp and it's subzones
    AREA_FLAG_INSIDE             = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE            = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_WINTERGRASP_2      = 0x08000000,                // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE        = 0x20000000                 // Marks zones where you cannot fly
};

enum Difficulty : uint8
{
    REGULAR_DIFFICULTY           = 0,

    DUNGEON_DIFFICULTY_NORMAL    = 0,
    DUNGEON_DIFFICULTY_HEROIC    = 1,
    DUNGEON_DIFFICULTY_EPIC      = 2,

    RAID_DIFFICULTY_10MAN_NORMAL = 0,
    RAID_DIFFICULTY_25MAN_NORMAL = 1,
    RAID_DIFFICULTY_10MAN_HEROIC = 2,
    RAID_DIFFICULTY_25MAN_HEROIC = 3
};

#define RAID_DIFFICULTY_MASK_25MAN 1    // since 25man difficulties are 1 and 3, we can check them like that

#define MAX_DUNGEON_DIFFICULTY     3
#define MAX_RAID_DIFFICULTY        4
#define MAX_DIFFICULTY             4

enum SpawnMask
{
    SPAWNMASK_CONTINENT         = (1 << REGULAR_DIFFICULTY), // any maps without spawn modes

    SPAWNMASK_DUNGEON_NORMAL    = (1 << DUNGEON_DIFFICULTY_NORMAL),
    SPAWNMASK_DUNGEON_HEROIC    = (1 << DUNGEON_DIFFICULTY_HEROIC),
    SPAWNMASK_DUNGEON_ALL       = (SPAWNMASK_DUNGEON_NORMAL | SPAWNMASK_DUNGEON_HEROIC),

    SPAWNMASK_RAID_10MAN_NORMAL = (1 << RAID_DIFFICULTY_10MAN_NORMAL),
    SPAWNMASK_RAID_25MAN_NORMAL = (1 << RAID_DIFFICULTY_25MAN_NORMAL),
    SPAWNMASK_RAID_NORMAL_ALL   = (SPAWNMASK_RAID_10MAN_NORMAL | SPAWNMASK_RAID_25MAN_NORMAL),

    SPAWNMASK_RAID_10MAN_HEROIC = (1 << RAID_DIFFICULTY_10MAN_HEROIC),
    SPAWNMASK_RAID_25MAN_HEROIC = (1 << RAID_DIFFICULTY_25MAN_HEROIC),
    SPAWNMASK_RAID_HEROIC_ALL   = (SPAWNMASK_RAID_10MAN_HEROIC | SPAWNMASK_RAID_25MAN_HEROIC),

    SPAWNMASK_RAID_ALL          = (SPAWNMASK_RAID_NORMAL_ALL | SPAWNMASK_RAID_HEROIC_ALL)
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
    FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT= 0x00002000
};

enum FactionMasks
{
    FACTION_MASK_PLAYER   = 1,                              // any player
    FACTION_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_MASK_MONSTER  = 8                               // aggressive creature from monster team
    // if none flags set then non-aggressive creature
};

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
    MAP_ARENA           = 4                                 // arena
};

enum MapFlags
{
    MAP_FLAG_DYNAMIC_DIFFICULTY = 0x100
};

enum AbilityLearnType
{
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE  = 1, // Spell state will update depending on skill value
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN  = 2  // Spell will be learned/removed together with entire skill
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE             = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL     = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE           = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL      = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE       = 4,
    ITEM_ENCHANTMENT_TYPE_STAT             = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM            = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL        = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET = 8
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE       = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP      = 1                       // limit applied to amount equipped items (including used gems)
};

enum SkillRaceClassInfoFlags
{
    SKILL_FLAG_NO_SKILLUP_MESSAGE       = 0x2,
    SKILL_FLAG_ALWAYS_MAX_VALUE         = 0x10,
    SKILL_FLAG_UNLEARNABLE              = 0x20,     // Skill can be unlearned
    SKILL_FLAG_INCLUDE_IN_SORT          = 0x80,     // Spells belonging to a skill with this flag will additionally compare skill ids when sorting spellbook in client
    SKILL_FLAG_NOT_TRAINABLE            = 0x100,
    SKILL_FLAG_MONO_VALUE               = 0x400     // Skill always has value 1 - clientside display flag, real value can be different
};

enum SpellCategoryFlags
{
    SPELL_CATEGORY_FLAG_COOLDOWN_SCALES_WITH_WEAPON_SPEED   = 0x01, // unused
    SPELL_CATEGORY_FLAG_COOLDOWN_STARTS_ON_EVENT            = 0x04
};

#define MAX_SPELL_EFFECTS 3
#define MAX_EFFECT_MASK 7
#define MAX_SPELL_REAGENTS 8

enum EnchantmentSlotMask
{
    ENCHANTMENT_CAN_SOULBOUND = 0x01,
    ENCHANTMENT_UNK1 = 0x02,
    ENCHANTMENT_UNK2 = 0x04,
    ENCHANTMENT_UNK3 = 0x08
};

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 5
enum SummonPropFlags
{
    SUMMON_PROP_FLAG_NONE            = 0x00000000,          // 1342 spells in 3.0.3
    SUMMON_PROP_FLAG_UNK1            = 0x00000001,          // 75 spells in 3.0.3, something unfriendly
    SUMMON_PROP_FLAG_UNK2            = 0x00000002,          // 616 spells in 3.0.3, something friendly
    SUMMON_PROP_FLAG_UNK3            = 0x00000004,          // 22 spells in 3.0.3, no idea...
    SUMMON_PROP_FLAG_UNK4            = 0x00000008,          // 49 spells in 3.0.3, some mounts
    SUMMON_PROP_FLAG_PERSONAL_SPAWN  = 0x00000010,          // Personal Spawn (creature visible only by summoner)
    SUMMON_PROP_FLAG_UNK6            = 0x00000020,          // 0 spells in 3.3.5, unused
    SUMMON_PROP_FLAG_UNK7            = 0x00000040,          // 12 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK8            = 0x00000080,          // 4 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK9            = 0x00000100,          // 51 spells in 3.0.3, no idea, many quest related
    SUMMON_PROP_FLAG_UNK10           = 0x00000200,          // 51 spells in 3.0.3, something defensive
    SUMMON_PROP_FLAG_UNK11           = 0x00000400,          // 3 spells, requires something near?
    SUMMON_PROP_FLAG_UNK12           = 0x00000800,          // 30 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK13           = 0x00001000,          // Lightwell, Jeeves, Gnomish Alarm-o-bot, Build vehicles(wintergrasp)
    SUMMON_PROP_FLAG_UNK14           = 0x00002000,          // Guides, player follows
    SUMMON_PROP_FLAG_UNK15           = 0x00004000,          // Force of Nature, Shadowfiend, Feral Spirit, Summon Water Elemental
    SUMMON_PROP_FLAG_UNK16           = 0x00008000           // Light/Dark Bullet, Soul/Fiery Consumption, Twisted Visage, Twilight Whelp. Phase related?
};

#define MAX_TALENT_RANK 5
#define MAX_PET_TALENT_RANK 3                               // use in calculations, expected <= MAX_TALENT_RANK
#define MAX_TALENT_TABS 3

static constexpr size_t TaxiMaskSize = 14;
typedef std::array<uint32, TaxiMaskSize> TaxiMask;

enum TotemCategoryType
{
    TOTEM_CATEGORY_TYPE_KNIFE           = 1,
    TOTEM_CATEGORY_TYPE_TOTEM           = 2,
    TOTEM_CATEGORY_TYPE_ROD             = 3,
    TOTEM_CATEGORY_TYPE_PICK            = 21,
    TOTEM_CATEGORY_TYPE_STONE           = 22,
    TOTEM_CATEGORY_TYPE_HAMMER          = 23,
    TOTEM_CATEGORY_TYPE_SPANNER         = 24
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER                         = 0x00000001,
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE                          = 0x00000002,
    VEHICLE_SEAT_FLAG_UNK3                                             = 0x00000004,
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT  = 0x00000008,
    VEHICLE_SEAT_FLAG_UNK5                                             = 0x00000010,
    VEHICLE_SEAT_FLAG_UNK6                                             = 0x00000020,
    VEHICLE_SEAT_FLAG_UNK7                                             = 0x00000040,
    VEHICLE_SEAT_FLAG_UNK8                                             = 0x00000080,
    VEHICLE_SEAT_FLAG_UNK9                                             = 0x00000100,
    VEHICLE_SEAT_FLAG_HIDE_PASSENGER                                   = 0x00000200, // Passenger is hidden
    VEHICLE_SEAT_FLAG_ALLOW_TURNING                                    = 0x00000400, // needed for CGCamera__SyncFreeLookFacing
    VEHICLE_SEAT_FLAG_CAN_CONTROL                                      = 0x00000800, // Lua_UnitInVehicleControlSeat
    VEHICLE_SEAT_FLAG_CAN_CAST_MOUNT_SPELL                             = 0x00001000, // Can cast spells with SPELL_AURA_MOUNTED from seat (possibly 4.x only, 0 seats on 3.3.5a)
    VEHICLE_SEAT_FLAG_UNCONTROLLED                                     = 0x00002000, // can override !& VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT
    VEHICLE_SEAT_FLAG_CAN_ATTACK                                       = 0x00004000, // Can attack, cast spells and use items from vehicle
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_FORCED_EXIT     = 0x00008000,
    VEHICLE_SEAT_FLAG_UNK17                                            = 0x00010000,
    VEHICLE_SEAT_FLAG_UNK18                                            = 0x00020000, // Needs research and support (28 vehicles): Allow entering vehicles while keeping specific permanent(?) auras that impose visuals (states like beeing under freeze/stun mechanic, emote state animations).
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_VOLUNTARY_EXIT                 = 0x00040000,
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_FORCED_EXIT                    = 0x00080000,
    VEHICLE_SEAT_FLAG_PASSENGER_NOT_SELECTABLE                         = 0x00100000,
    VEHICLE_SEAT_FLAG_UNK22                                            = 0x00200000,
    VEHICLE_SEAT_FLAG_REC_HAS_VEHICLE_ENTER_ANIM                       = 0x00400000,
    VEHICLE_SEAT_FLAG_IS_USING_VEHICLE_CONTROLS                        = 0x00800000, // Lua_IsUsingVehicleControls
    VEHICLE_SEAT_FLAG_ENABLE_VEHICLE_ZOOM                              = 0x01000000,
    VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT                                = 0x02000000, // Lua_CanExitVehicle - can enter and exit at free will
    VEHICLE_SEAT_FLAG_CAN_SWITCH                                       = 0x04000000, // Lua_CanSwitchVehicleSeats
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_ENTER = 0x08000000,
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_EXIT  = 0x10000000,
    VEHICLE_SEAT_FLAG_CAN_CAST                                         = 0x20000000, // Lua_UnitHasVehicleUI
    VEHICLE_SEAT_FLAG_UNK2                                             = 0x40000000, // checked in conjunction with 0x800 in CastSpell2
    VEHICLE_SEAT_FLAG_ALLOWS_INTERACTION                               = 0x80000000
};

enum VehicleSeatFlagsB
{
    VEHICLE_SEAT_FLAG_B_NONE                     = 0x00000000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED            = 0x00000002,
    VEHICLE_SEAT_FLAG_B_TARGETS_IN_RAIDUI        = 0x00000008,           // Lua_UnitTargetsVehicleInRaidUI
    VEHICLE_SEAT_FLAG_B_EJECTABLE                = 0x00000020,           // ejectable
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2          = 0x00000040,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3          = 0x00000100,
    VEHICLE_SEAT_FLAG_B_KEEP_PET                 = 0x00020000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4          = 0x02000000,
    VEHICLE_SEAT_FLAG_B_CAN_SWITCH               = 0x04000000,
    VEHICLE_SEAT_FLAG_B_VEHICLE_PLAYERFRAME_UI   = 0x80000000            // Lua_UnitHasVehiclePlayerFrameUI - actually checked for flagsb &~ 0x80000000
};

#endif
