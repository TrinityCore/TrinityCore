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
#include "EnumFlag.h"
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

enum LevelLimit
{
    // Client expected level limitation, like as used in DBC item max levels for "until max player level"
    // use as default max player level, must be fit max level for used client
    // also see MAX_LEVEL and STRONG_MAX_LEVEL define
    DEFAULT_MAX_LEVEL = 120,

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
    MAX_LEVEL = 120,

    // Server side limitation. Base at used code requirements.
    // also see MAX_LEVEL and GT_MAX_LEVEL define
    STRONG_MAX_LEVEL = 255,
};

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 12,

    // must be max value in PvPDificulty slot + 1
    MAX_BATTLEGROUND_BRACKETS
};

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = AREATEAM_ALLY+AREATEAM_HORDE
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
    ACHIEVEMENT_FLAG_PLAY_NO_VISUAL        = 0x00000004,    // Client does not play achievement earned visual
    ACHIEVEMENT_FLAG_SUMM                  = 0x00000008,    // Use summ criteria value from all requirements (and calculate max value)
    ACHIEVEMENT_FLAG_MAX_USED              = 0x00000010,    // Show max criteria (and calculate max value ??)
    ACHIEVEMENT_FLAG_REQ_COUNT             = 0x00000020,    // Use not zero req count (and calculate max value)
    ACHIEVEMENT_FLAG_AVERAGE               = 0x00000040,    // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_BAR                   = 0x00000080,    // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_REALM_FIRST_REACH     = 0x00000100,    //
    ACHIEVEMENT_FLAG_REALM_FIRST_KILL      = 0x00000200,    //
    ACHIEVEMENT_FLAG_UNK3                  = 0x00000400,    // ACHIEVEMENT_FLAG_HIDE_NAME_IN_TIE
    ACHIEVEMENT_FLAG_HIDE_INCOMPLETE       = 0x00000800,    // hide from UI if not completed
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS    = 0x00001000,    // Shows in guild news
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER  = 0x00002000,    // Shows in guild news header
    ACHIEVEMENT_FLAG_GUILD                 = 0x00004000,    //
    ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS    = 0x00008000,    //
    ACHIEVEMENT_FLAG_SHOW_CRITERIA_MEMBERS = 0x00010000,    //
    ACHIEVEMENT_FLAG_ACCOUNT               = 0x00020000,
    ACHIEVEMENT_FLAG_UNK5                  = 0x00040000,
    ACHIEVEMENT_FLAG_HIDE_ZERO_COUNTER     = 0x00080000,    // statistic is hidden from UI if no criteria value exists
    ACHIEVEMENT_FLAG_TRACKING_FLAG         = 0x00100000,    // hidden tracking flag, sent to client in all cases except completion announcements
};

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,                // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2                  = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,                // city and city subsones
    AREA_FLAG_UNK3                  = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2        = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS           = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA                 = 0x00000080,                // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL               = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY                  = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND               = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY             = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY              = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1               = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_OUTLAND2              = 0x00004000,                // expansion zones? (only Circle of Blood Arena not have this flag, but have 0x00000400 flag)
    AREA_FLAG_OUTDOOR_PVP           = 0x00008000,                // pvp objective area? (Death's Door also has this flag although it's no pvp object area)
    AREA_FLAG_ARENA_INSTANCE        = 0x00010000,                // used by instanced arenas only
    AREA_FLAG_UNUSED2               = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA        = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK6                  = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL              = 0x00100000,                // used for some starting areas with area_level <= 15
    AREA_FLAG_TOWN                  = 0x00200000,                // small towns with Inn
    AREA_FLAG_REST_ZONE_HORDE       = 0x00400000,                // Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion (Something to do with team?)
    AREA_FLAG_REST_ZONE_ALLIANCE    = 0x00800000,                // Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion (Something to do with team?)
    AREA_FLAG_WINTERGRASP           = 0x01000000,                // Wintergrasp and it's subzones
    AREA_FLAG_INSIDE                = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE               = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_CAN_HEARTH_AND_RESURRECT = 0x08000000,             // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE           = 0x20000000,                // Marks zones where you cannot fly
    AREA_FLAG_UNK9                  = 0x40000000
};

enum AreaMountFlags
{
    AREA_MOUNT_FLAG_GROUND_ALLOWED      = 0x1,
    AREA_MOUNT_FLAG_FLYING_ALLOWED      = 0x2,
    AREA_MOUNT_FLAG_FLOAT_ALLOWED       = 0x4,
    AREA_MOUNT_FLAG_UNDERWATER_ALLOWED  = 0x8
};

enum ArtifactCategory : uint32
{
    ARTIFACT_CATEGORY_PRIMARY = 1,
    ARTIFACT_CATEGORY_FISHING = 2
};

enum ArtifactPowerFlag : uint8
{
    ARTIFACT_POWER_FLAG_GOLD                        = 0x01,
    ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED            = 0x02,
    ARTIFACT_POWER_FLAG_FINAL                       = 0x04,
    ARTIFACT_POWER_FLAG_SCALES_WITH_NUM_POWERS      = 0x08,
    ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK = 0x10,
    ARTIFACT_POWER_FLAG_MAX_RANK_WITH_TIER          = 0x20,

    ARTIFACT_POWER_FLAG_FIRST                       = ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED | ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK,
};

#define MAX_ARTIFACT_TIER 1

#define MAX_AZERITE_EMPOWERED_TIER 5

#define MAX_AZERITE_ESSENCE_SLOT 4
#define MAX_AZERITE_ESSENCE_RANK 4

enum class AzeriteItemMilestoneType : int32
{
    MajorEssence    = 0,
    MinorEssence    = 1,
    BonusStamina    = 2
};

enum AzeriteTierUnlockSetFlags
{
    AZERITE_TIER_UNLOCK_SET_FLAG_DEFAULT = 0x1
};

#define BATTLE_PET_SPECIES_MAX_ID 2873

enum BattlemasterListFlags
{
    BATTLEMASTER_LIST_FLAG_DISABLED             = 0x01,
    BATTLEMASTER_LIST_FLAG_SKIP_ROLE_CHECK      = 0x02,
    BATTLEMASTER_LIST_FLAG_UNK04                = 0x04,
    BATTLEMASTER_LIST_FLAG_CAN_INIT_WAR_GAME    = 0x08,
    BATTLEMASTER_LIST_FLAG_CAN_SPECIFIC_QUEUE   = 0x10,
    BATTLEMASTER_LIST_FLAG_BRAWL                = 0x20,
    BATTLEMASTER_LIST_FLAG_FACTIONAL            = 0x40
};

enum ChrSpecializationFlag
{
    CHR_SPECIALIZATION_FLAG_CASTER                  = 0x01,
    CHR_SPECIALIZATION_FLAG_RANGED                  = 0x02,
    CHR_SPECIALIZATION_FLAG_MELEE                   = 0x04,
    CHR_SPECIALIZATION_FLAG_UNKNOWN                 = 0x08,
    CHR_SPECIALIZATION_FLAG_DUAL_WIELD_TWO_HANDED   = 0x10,     // used for CUnitDisplay::SetSheatheInvertedForDualWield
    CHR_SPECIALIZATION_FLAG_PET_OVERRIDE_SPEC       = 0x20,
    CHR_SPECIALIZATION_FLAG_RECOMMENDED             = 0x40,
};

enum class CorruptionEffectsFlag
{
    None        = 0,
    Disabled    = 0x1
};

DEFINE_ENUM_FLAG(CorruptionEffectsFlag);

enum CriteriaCondition
{
    CRITERIA_CONDITION_NONE            = 0,
    CRITERIA_CONDITION_NO_DEATH        = 1,     // reset progress on death
    CRITERIA_CONDITION_UNK2            = 2,     // only used in "Complete a daily quest every day for five consecutive days"
    CRITERIA_CONDITION_BG_MAP          = 3,     // requires you to be on specific map, reset at change
    CRITERIA_CONDITION_NO_LOSE         = 4,     // only used in "Win 10 arenas without losing"
    CRITERIA_CONDITION_REMOVE_AURA     = 5,     // reset when this aura is removed
    CRITERIA_CONDITION_CAST_SPELL      = 8,     // reset when casting this spell
    CRITERIA_CONDITION_NO_SPELL_HIT    = 9,     // requires the player not to be hit by specific spell
    CRITERIA_CONDITION_NOT_IN_GROUP    = 10,    // requires the player not to be in group
    CRITERIA_CONDITION_LOSE_PET_BATTLE = 11,    // reset when losing pet battle
    CRITERIA_CONDITION_UNK13           = 13,    // unk
    CRITERIA_CONDITION_EVENT           = 14,

    CRITERIA_CONDITION_MAX
};

enum CriteriaAdditionalCondition
{
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_DRUNK_VALUE            = 1,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_PLAYER_CONDITION       = 2,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_LEVEL                    = 3,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_ENTRY         = 4,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_PLAYER         = 5,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_DEAD           = 6,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_ENEMY          = 7,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA               = 8,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA_TYPE          = 9,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA               = 10,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA_TYPE          = 11,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_STATE             = 12,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_STATE             = 13,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_MIN              = 14,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_EQUALS           = 15,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_IS_ALIVE               = 16,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_AREA_OR_ZONE           = 17,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_AREA_OR_ZONE           = 18,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_19                      = 19,
    CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY_OLD            = 20,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_YIELDS_XP     = 21, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_ABOVE_TARGET     = 22,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_EQUAL_TARGET     = 23,
    CRITERIA_ADDITIONAL_CONDITION_ARENA_TYPE                    = 24,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_RACE                   = 25,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_CLASS                  = 26,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_RACE                   = 27,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CLASS                  = 28,
    CRITERIA_ADDITIONAL_CONDITION_MAX_GROUP_MEMBERS             = 29,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_TYPE          = 30,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_FAMILY        = 31,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_MAP                    = 32,
    CRITERIA_ADDITIONAL_CONDITION_CLIENT_VERSION                = 33,
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_TEAM_LEVEL         = 34,
    CRITERIA_ADDITIONAL_CONDITION_NOT_IN_GROUP                  = 35,
    CRITERIA_ADDITIONAL_CONDITION_IN_GROUP                      = 36,
    CRITERIA_ADDITIONAL_CONDITION_MIN_PERSONAL_RATING           = 37, // NYI
    CRITERIA_ADDITIONAL_CONDITION_TITLE_BIT_INDEX               = 38,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL                  = 39,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL                  = 40,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_ZONE                   = 41,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_ZONE                   = 42,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_LOWER       = 43,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_GREATER     = 44,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_EQUAL       = 45,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_LOWER       = 46,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_GREATER     = 47,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_EQUAL       = 48,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_LOWER           = 49,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_GREATER         = 50,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_EQUAL           = 51,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_LOWER           = 52,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_GREATER         = 53,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_EQUAL           = 54,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_PLAYER_CONDITION       = 55,
    CRITERIA_ADDITIONAL_CONDITION_MIN_ACHIEVEMENT_POINTS        = 56,
    CRITERIA_ADDITIONAL_CONDITION_IN_LFG_DUNGEON                = 57,
    CRITERIA_ADDITIONAL_CONDITION_IN_LFG_RANDOM_DUNGEON         = 58,
    CRITERIA_ADDITIONAL_CONDITION_IN_LFG_FIRST_RANDOM_DUNGEON   = 59,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_60                      = 60, // NYI
    CRITERIA_ADDITIONAL_CONDITION_REQUIRES_GUILD_GROUP          = 61, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GUILD_REPUTATION              = 62,
    CRITERIA_ADDITIONAL_CONDITION_RATED_BATTLEGROUND            = 63, // NYI
    CRITERIA_ADDITIONAL_CONDITION_RATED_BATTLEGROUND_RATING     = 64,
    CRITERIA_ADDITIONAL_CONDITION_PROJECT_RARITY                = 65,
    CRITERIA_ADDITIONAL_CONDITION_PROJECT_RACE                  = 66,
    CRITERIA_ADDITIONAL_CONDITION_WORLD_STATE_EXPRESSION        = 67,
    CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY                = 68,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_GREATER          = 69,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL_GREATER          = 70,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_LOWER            = 71,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL_LOWER            = 72,
    CRITERIA_ADDITIONAL_CONDITION_MODIFIER_TREE                 = 73,
    CRITERIA_ADDITIONAL_CONDITION_SCENARIO_ID                   = 74,
    CRITERIA_ADDITIONAL_CONDITION_THE_TILLERS_REPUTATION        = 75,
    CRITERIA_ADDITIONAL_CONDITION_PET_BATTLE_ACHIEVEMENT_POINTS = 76, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_77                      = 77, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_FAMILY             = 78, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_HEALTH_PCT         = 79, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GUILD_GROUP_MEMBERS           = 80, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_ENTRY              = 81, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SCENARIO_STEP_INDEX           = 82,
    CRITERIA_ADDITIONAL_CONDITION_CHALLENGE_MODE_MEDAL          = 83, // NYI
    CRITERIA_ADDITIONAL_CONDITION_IS_ON_QUEST                   = 84,
    CRITERIA_ADDITIONAL_CONDITION_EXALTED_WITH_FACTION          = 85, // NYI
    CRITERIA_ADDITIONAL_CONDITION_HAS_ACHIEVEMENT               = 86,
    CRITERIA_ADDITIONAL_CONDITION_HAS_ACHIEVEMENT_ON_CHARACTER  = 87, // NYI
    CRITERIA_ADDITIONAL_CONDITION_CLOUD_SERPENT_REPUTATION      = 88,
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_BREED_QUALITY_ID   = 89, // NYI
    CRITERIA_ADDITIONAL_CONDITION_PET_BATTLE_IS_PVP             = 90, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_SPECIES            = 91,
    CRITERIA_ADDITIONAL_CONDITION_ACTIVE_EXPANSION              = 92,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_93                      = 93, // NYI
    CRITERIA_ADDITIONAL_CONDITION_FRIENDSHIP_REP_REACTION       = 94, // NYI
    CRITERIA_ADDITIONAL_CONDITION_FACTION_STANDING              = 95,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_CLASS_AND_SUBCLASS       = 96, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_SEX                    = 97,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_NATIVE_SEX             = 98,
    CRITERIA_ADDITIONAL_CONDITION_SKILL                         = 99,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_100                     = 100, // NYI
    CRITERIA_ADDITIONAL_CONDITION_NORMAL_PHASE_SHIFT            = 101,
    CRITERIA_ADDITIONAL_CONDITION_IN_PHASE                      = 102,
    CRITERIA_ADDITIONAL_CONDITION_NOT_IN_PHASE                  = 103,
    CRITERIA_ADDITIONAL_CONDITION_HAS_SPELL                     = 104,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_COUNT                    = 105,
    CRITERIA_ADDITIONAL_CONDITION_ACCOUNT_EXPANSION             = 106,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA_LABEL         = 107, // NYI, SpellLabel
    //CRITERIA_ADDITIONAL_CONDITION_UNK_108                     = 108, // NYI
    CRITERIA_ADDITIONAL_CONDITION_TIME_IN_RANGE                 = 109, // NYI, packed time between asset and secondaryAsset
    CRITERIA_ADDITIONAL_CONDITION_REWARDED_QUEST                = 110,
    CRITERIA_ADDITIONAL_CONDITION_COMPLETED_QUEST               = 111,
    CRITERIA_ADDITIONAL_CONDITION_COMPLETED_QUEST_OBJECTIVE     = 112, // NYI, QuestObjectiveID
    CRITERIA_ADDITIONAL_CONDITION_EXPLORED_AREA                 = 113,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_COUNT_INCLUDING_BANK     = 114,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_115                     = 115, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_PVP_FACTION_INDEX      = 116,
    CRITERIA_ADDITIONAL_CONDITION_LFG_VALUE_EQUAL               = 117,
    CRITERIA_ADDITIONAL_CONDITION_LFG_VALUE_GREATER             = 118,
    CRITERIA_ADDITIONAL_CONDITION_CURRENCY_AMOUNT               = 119,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_120                     = 120, // NYI
    CRITERIA_ADDITIONAL_CONDITION_CURRENCY_TRACKED_AMOUNT       = 121,
    CRITERIA_ADDITIONAL_CONDITION_MAP_INSTANCE_TYPE             = 122,
    CRITERIA_ADDITIONAL_CONDITION_MENTOR                        = 123,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_124                     = 124, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_125                     = 125, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_LEVEL_ABOVE          = 126, // asset: garrLevel, secondaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_LEVEL = 127, // asset: count, secondaryAsset: followerLevel, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_QUALITY = 128, // asset: count, secondaryAsset: followerQuality, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_WITH_ABILITY = 129, // asset: followerLevel, secondaryAsset: ability, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_WITH_TRAIT  = 130, // asset: followerLevel, secondaryAsset: ability, tertiaryAsset: garrType (same as above but ability must have GARRISON_ABILITY_FLAG_TRAIT)
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_ABILITY_IN_BUILDING = 131, // asset: ability, secondaryAsset: buildingType, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_TRAIT_IN_BUILDING = 132, // asset: ability, secondaryAsset: buildingType, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_IN_BUILDING = 133, // asset: followerLevel, secondaryAsset: buildingType, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_ABOVE_LEVEL = 134, // asset: buildingType, secondaryAsset: buildingLevel, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_BLUEPRINT            = 135, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_136                     = 136, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_137                     = 137, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_138                     = 138, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_139                     = 139, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_INACTIVE    = 140,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_141                     = 141, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_EQUAL_LEVEL = 142, // asset: buildingType, secondaryAsset: buildingLevel, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_ABILITY= 143, // asset: ability, secondaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_TRAIT  = 144, // asset: ability, secondaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_QUALITY_WOD = 145, // asset: followerQuality
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_EQUAL_LEVEL = 146, // asset: followerLevel, secondaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_RARE_MISSION         = 147, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_148                     = 148, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_LEVEL       = 149, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_150                     = 150, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_SPECIES_IN_TEAM    = 151, // asset: count, secondaryAsset: battlePetSpeciesId
    CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_FAMILY_IN_TEAM     = 152, // asset: count, secondaryAsset: battlePetFamily
    //CRITERIA_ADDITIONAL_CONDITION_UNK_153                     = 153, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_154                     = 154, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_155                     = 155, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_156                     = 156, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ID          = 157, // follower with id, in any garrison
    CRITERIA_ADDITIONAL_CONDITION_QUEST_OBJECTIVE_PROGRESS_EQUAL= 158, // NYI asset: questObjectiveId, secondaryAsset: progress
    CRITERIA_ADDITIONAL_CONDITION_QUEST_OBJECTIVE_PROGRESS_ABOVE= 159, // NYI asset: questObjectiveId, secondaryAsset: progress
    //CRITERIA_ADDITIONAL_CONDITION_UNK_160                     = 160, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_161                     = 161, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_162                     = 162, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_163                     = 163, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_164                     = 164, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_165                     = 165, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_166                     = 166, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_MISSION_TYPE         = 167, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_ITEM_LEVEL = 168, // asset: followerItemLevel
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_ITEM_LEVEL = 169, // asset: count, secondaryAsset: followerItemLevel, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_LEVEL_EQUAL          = 170, // asset: count
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_GROUP_SIZE           = 171, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_172                     = 172, // NYI something to do with currency but only used on criterias that require the same currency
    CRITERIA_ADDITIONAL_CONDITION_TARGETING_CORPSE              = 173,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_174                     = 174, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_LEVEL_EQUAL= 175, // asset: count, secondaryAsset: followerLevel, tertiaryAsset: garrType
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ID_IN_BUILDING = 176, // asset: followerId, secondaryAsset: buildingType
    //CRITERIA_ADDITIONAL_CONDITION_UNK_177                     = 177, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_178                     = 178, // NYI
    CRITERIA_ADDITIONAL_CONDITION_WORLD_PVP_AREA                = 179, // NYI
    CRITERIA_ADDITIONAL_CONDITION_NON_OWN_GARRISON              = 180, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_181                     = 181, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_182                     = 183, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_183                     = 183, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ITEM_LEVEL_ABOVE = 184,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_185                     = 185, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_186                     = 186, // NYI
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_TYPE        = 187, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_188                     = 188, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_189                     = 189, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_190                     = 190, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_191                     = 191, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_192                     = 192, // NYI
    CRITERIA_ADDITIONAL_CONDITION_HONOR_LEVEL                   = 193,
    CRITERIA_ADDITIONAL_CONDITION_PRESTIGE_LEVEL                = 194,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_195                     = 195, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_196                     = 196, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_197                     = 197, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_198                     = 198, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_198                     = 199, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ITEM_MODIFIED_APPEARANCE      = 200,
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_SELECTED_TALENT      = 201, // NYI asset: garrTalentId (talent selected, research timer doesn't matter)
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_RESEARCHED_TALENT    = 202, // NYI asset: garrTalentId (talent selected, research must be finished)
    CRITERIA_ADDITIONAL_CONDITION_HAS_CHARACTER_RESTRICTIONS    = 203,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_204                     = 204, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_205                     = 205, // NYI
    CRITERIA_ADDITIONAL_CONDITION_QUEST_INFO_ID                 = 206,
    CRITERIA_ADDITIONAL_CONDITION_GARRISON_RESEARCHING_TALENT   = 207, // NYI asset: garrTalentId (talent selected, research must be in progress)
    CRITERIA_ADDITIONAL_CONDITION_ARTIFACT_APPEARANCE_SET_USED  = 208,
    CRITERIA_ADDITIONAL_CONDITION_CURRENCY_AMOUNT_EQUAL         = 209,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_210                     = 210, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SCENARIO_TYPE                 = 211,
    CRITERIA_ADDITIONAL_CONDITION_ACCOUNT_EXPANSION_EQUAL       = 212,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_213                     = 213, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_214                     = 214, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_215                     = 215, // NYI
    CRITERIA_ADDITIONAL_CONDITION_CHALLENGE_MODE_MEDAL_2        = 216, // NYI keystone master, asset = 3
    //CRITERIA_ADDITIONAL_CONDITION_UNK_217                     = 217, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_218                     = 218, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_219                     = 219, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_220                     = 220, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_221                     = 221, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_222                     = 222, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_223                     = 223, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_224                     = 224, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_225                     = 225, // NYI
    CRITERIA_ADDITIONAL_CONDITION_USED_LEVEL_BOOST              = 226, // NYI
    CRITERIA_ADDITIONAL_CONDITION_USED_RACE_CHANGE              = 227, // NYI
    CRITERIA_ADDITIONAL_CONDITION_USED_FACTION_CHANGE           = 228, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_229                     = 229, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_230                     = 230, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ACHIEVEMENT_GLOBALLY_INCOMPLETED = 231, // hall of fame stuff, asset: unk, secondaryAsset: achievementId
    CRITERIA_ADDITIONAL_CONDITION_MAIN_HAND_VISIBLE_SUBCLASS    = 232,
    CRITERIA_ADDITIONAL_CONDITION_OFF_HAND_VISIBLE_SUBCLASS     = 233,
    CRITERIA_ADDITIONAL_CONDITION_PVP_TIER                      = 234, // NYI asset: pvpTierId
    CRITERIA_ADDITIONAL_CONDITION_AZERITE_ITEM_LEVEL            = 235,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_236                     = 236, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_237                     = 237, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_238                     = 238, // NYI
    CRITERIA_ADDITIONAL_CONDITION_PVP_TIER_GREATER              = 239, // NYI asset: pvpTierEnum, secondaryAsset: pvpBracket
    //CRITERIA_ADDITIONAL_CONDITION_UNK_240                     = 240, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_241                     = 241, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_242                     = 242, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_243                     = 243, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_244                     = 244, // NYI
    CRITERIA_ADDITIONAL_CONDITION_IN_WAR_MODE                   = 245,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_246                     = 246, // NYI
    CRITERIA_ADDITIONAL_CONDITION_KEYSTONE_LEVEL                = 247, // NYI
    //CRITERIA_ADDITIONAL_CONDITION_UNK_248                     = 248, // NYI
    CRITERIA_ADDITIONAL_CONDITION_KEYSTONE_DUNGEON              = 249, // NYI asset: mapChallengeModeId
    //CRITERIA_ADDITIONAL_CONDITION_UNK_250                     = 250, // NYI
    CRITERIA_ADDITIONAL_CONDITION_PVP_SEASON                    = 251, // NYI asset: that unknown column in PvpSeason.db2
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_DISPLAY_RACE           = 252,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_DISPLAY_RACE           = 253,
    CRITERIA_ADDITIONAL_CONDITION_FRIENDSHIP_REP_REACTION_EXACT = 254, // NYI
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_COUNT_EQUAL       = 255,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_COUNT_EQUAL       = 256,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_COUNT_GREATER     = 257,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_COUNT_GREATER     = 258,
    CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_LOWER = 259,
    CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_EQUAL = 260,
    CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_GREATER = 261,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA_EFFECT_INDEX  = 262, // asset: spellId, secondaryAsset: index
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_SPECIALIZATION_ROLE    = 263,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_120              = 264,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_265                     = 265,
    CRITERIA_ADDITIONAL_CONDITION_SELECTED_AZERITE_ESSENCE_RANK_LOWER = 266,
    CRITERIA_ADDITIONAL_CONDITION_SELECTED_AZERITE_ESSENCE_RANK_GREATER = 267,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_268                     = 268,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_269                     = 269,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_270                     = 270,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_271                     = 271,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_272                     = 272,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_273                     = 273,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_274                     = 274,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_275                     = 275,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_276                     = 276,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_277                     = 277,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_278                     = 278,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_279                     = 279,
    CRITERIA_ADDITIONAL_CONDITION_MAP_OR_COSMETIC_MAP           = 280,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_281                     = 281,
    CRITERIA_ADDITIONAL_CONDITION_HAS_ENTITLEMENT               = 282,
    CRITERIA_ADDITIONAL_CONDITION_HAS_QUEST_SESSION             = 283,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_284                     = 284,
    //CRITERIA_ADDITIONAL_CONDITION_UNK_285                     = 285,
};

enum CriteriaFlags
{
    CRITERIA_FLAG_SHOW_PROGRESS_BAR = 0x00000001,   // Show progress as bar
    CRITERIA_FLAG_HIDDEN            = 0x00000002,   // Not show criteria in client
    CRITERIA_FLAG_FAIL_ACHIEVEMENT  = 0x00000004,   // BG related??
    CRITERIA_FLAG_RESET_ON_START    = 0x00000008,   //
    CRITERIA_FLAG_IS_DATE           = 0x00000010,   // not used
    CRITERIA_FLAG_MONEY_COUNTER     = 0x00000020    // Displays counter as money
};

enum CriteriaTimedTypes : uint8
{
    CRITERIA_TIMED_TYPE_EVENT           = 1,    // Timer is started by internal event with id in timerStartEvent
    CRITERIA_TIMED_TYPE_QUEST           = 2,    // Timer is started by accepting quest with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_SPELL_CASTER    = 5,    // Timer is started by casting a spell with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_SPELL_TARGET    = 6,    // Timer is started by being target of spell with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_CREATURE        = 7,    // Timer is started by killing creature with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_ITEM            = 9,    // Timer is started by using item with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_UNK             = 10,   // Unknown
    CRITERIA_TIMED_TYPE_UNK_2           = 13,   // Unknown
    CRITERIA_TIMED_TYPE_SCENARIO_STAGE  = 14,   // Timer is started by changing stages in a scenario

    CRITERIA_TIMED_TYPE_MAX
};

enum CriteriaTypes : uint8
{
    CRITERIA_TYPE_KILL_CREATURE                         = 0,
    CRITERIA_TYPE_WIN_BG                                = 1,
    // 2 - unused (Legion - 23420)
    CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS         = 3, // struct { uint32 itemCount; }
    CRITERIA_TYPE_SURVEY_GAMEOBJECT                     = 4,
    CRITERIA_TYPE_REACH_LEVEL                           = 5,
    CRITERIA_TYPE_CLEAR_DIGSITE                         = 6,
    CRITERIA_TYPE_REACH_SKILL_LEVEL                     = 7,
    CRITERIA_TYPE_COMPLETE_ACHIEVEMENT                  = 8,
    CRITERIA_TYPE_COMPLETE_QUEST_COUNT                  = 9,
    CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY            = 10, // you have to complete a daily quest x times in a row
    CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE               = 11,
    CRITERIA_TYPE_CURRENCY                              = 12,
    CRITERIA_TYPE_DAMAGE_DONE                           = 13,
    CRITERIA_TYPE_COMPLETE_DAILY_QUEST                  = 14,
    CRITERIA_TYPE_COMPLETE_BATTLEGROUND                 = 15,
    CRITERIA_TYPE_DEATH_AT_MAP                          = 16,
    CRITERIA_TYPE_DEATH                                 = 17,
    CRITERIA_TYPE_DEATH_IN_DUNGEON                      = 18,
    CRITERIA_TYPE_COMPLETE_RAID                         = 19,
    CRITERIA_TYPE_KILLED_BY_CREATURE                    = 20,
    CRITERIA_TYPE_MANUAL_COMPLETE_CRITERIA              = 21,
    CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE_GUILD         = 22,
    CRITERIA_TYPE_KILLED_BY_PLAYER                      = 23,
    CRITERIA_TYPE_FALL_WITHOUT_DYING                    = 24,
    // 25 - unused (Legion - 23420)
    CRITERIA_TYPE_DEATHS_FROM                           = 26,
    CRITERIA_TYPE_COMPLETE_QUEST                        = 27,
    CRITERIA_TYPE_BE_SPELL_TARGET                       = 28,
    CRITERIA_TYPE_CAST_SPELL                            = 29,
    CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE                  = 30,
    CRITERIA_TYPE_HONORABLE_KILL_AT_AREA                = 31,
    CRITERIA_TYPE_WIN_ARENA                             = 32,
    CRITERIA_TYPE_PLAY_ARENA                            = 33,
    CRITERIA_TYPE_LEARN_SPELL                           = 34,
    CRITERIA_TYPE_HONORABLE_KILL                        = 35,
    CRITERIA_TYPE_OWN_ITEM                              = 36,
    CRITERIA_TYPE_WIN_RATED_ARENA                       = 37,
    CRITERIA_TYPE_HIGHEST_TEAM_RATING                   = 38,
    CRITERIA_TYPE_HIGHEST_PERSONAL_RATING               = 39,
    CRITERIA_TYPE_LEARN_SKILL_LEVEL                     = 40,
    CRITERIA_TYPE_USE_ITEM                              = 41,
    CRITERIA_TYPE_LOOT_ITEM                             = 42,
    CRITERIA_TYPE_EXPLORE_AREA                          = 43,
    CRITERIA_TYPE_OWN_RANK                              = 44,
    CRITERIA_TYPE_BUY_BANK_SLOT                         = 45,
    CRITERIA_TYPE_GAIN_REPUTATION                       = 46,
    CRITERIA_TYPE_GAIN_EXALTED_REPUTATION               = 47,
    CRITERIA_TYPE_VISIT_BARBER_SHOP                     = 48,
    CRITERIA_TYPE_EQUIP_EPIC_ITEM                       = 49,
    CRITERIA_TYPE_ROLL_NEED_ON_LOOT                     = 50, /// @todo itemlevel is mentioned in text but not present in dbc
    CRITERIA_TYPE_ROLL_GREED_ON_LOOT                    = 51,
    CRITERIA_TYPE_HK_CLASS                              = 52,
    CRITERIA_TYPE_HK_RACE                               = 53,
    CRITERIA_TYPE_DO_EMOTE                              = 54,
    CRITERIA_TYPE_HEALING_DONE                          = 55,
    CRITERIA_TYPE_GET_KILLING_BLOWS                     = 56, /// @todo in some cases map not present, and in some cases need do without die
    CRITERIA_TYPE_EQUIP_ITEM                            = 57,
    // 58 - unused (Legion - 23420)
    CRITERIA_TYPE_MONEY_FROM_VENDORS                    = 59,
    CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS                = 60,
    CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS               = 61,
    CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD               = 62,
    CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING             = 63,
    CRITERIA_TYPE_DEFEAT_CREATURE_GROUP                 = 64,
    CRITERIA_TYPE_GOLD_SPENT_AT_BARBER                  = 65,
    CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL                   = 66,
    CRITERIA_TYPE_LOOT_MONEY                            = 67,
    CRITERIA_TYPE_USE_GAMEOBJECT                        = 68,
    CRITERIA_TYPE_BE_SPELL_TARGET2                      = 69,
    CRITERIA_TYPE_SPECIAL_PVP_KILL                      = 70,
    CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE               = 71,
    CRITERIA_TYPE_FISH_IN_GAMEOBJECT                    = 72,
    CRITERIA_TYPE_SEND_EVENT                            = 73,
    CRITERIA_TYPE_ON_LOGIN                              = 74,
    CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS                = 75,
    CRITERIA_TYPE_WIN_DUEL                              = 76,
    CRITERIA_TYPE_LOSE_DUEL                             = 77,
    CRITERIA_TYPE_KILL_CREATURE_TYPE                    = 78,
    CRITERIA_TYPE_COOK_RECIPES_GUILD                    = 79,
    CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS               = 80,
    CRITERIA_TYPE_EARN_PET_BATTLE_ACHIEVEMENT_POINTS    = 81,
    CRITERIA_TYPE_CREATE_AUCTION                        = 82,
    CRITERIA_TYPE_HIGHEST_AUCTION_BID                   = 83,
    CRITERIA_TYPE_WON_AUCTIONS                          = 84,
    CRITERIA_TYPE_HIGHEST_AUCTION_SOLD                  = 85,
    CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED              = 86,
    CRITERIA_TYPE_GAIN_REVERED_REPUTATION               = 87,
    CRITERIA_TYPE_GAIN_HONORED_REPUTATION               = 88,
    CRITERIA_TYPE_KNOWN_FACTIONS                        = 89,
    CRITERIA_TYPE_LOOT_EPIC_ITEM                        = 90,
    CRITERIA_TYPE_RECEIVE_EPIC_ITEM                     = 91,
    CRITERIA_TYPE_SEND_EVENT_SCENARIO                   = 92,
    CRITERIA_TYPE_ROLL_NEED                             = 93,
    CRITERIA_TYPE_ROLL_GREED                            = 94,
    CRITERIA_TYPE_RELEASE_SPIRIT                        = 95,
    CRITERIA_TYPE_OWN_PET                               = 96,
    CRITERIA_TYPE_GARRISON_COMPLETE_DUNGEON_ENCOUNTER   = 97,
    // 98 - unused (Legion - 23420)
    // 99 - unused (Legion - 23420)
    // 100 - unused (Legion - 23420)
    CRITERIA_TYPE_HIGHEST_HIT_DEALT                     = 101,
    CRITERIA_TYPE_HIGHEST_HIT_RECEIVED                  = 102,
    CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED                 = 103,
    CRITERIA_TYPE_HIGHEST_HEAL_CAST                     = 104,
    CRITERIA_TYPE_TOTAL_HEALING_RECEIVED                = 105,
    CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED              = 106,
    CRITERIA_TYPE_QUEST_ABANDONED                       = 107,
    CRITERIA_TYPE_FLIGHT_PATHS_TAKEN                    = 108,
    CRITERIA_TYPE_LOOT_TYPE                             = 109,
    CRITERIA_TYPE_CAST_SPELL2                           = 110, /// @todo target entry is missing
    // 111 - unused (Legion - 23420)
    CRITERIA_TYPE_LEARN_SKILL_LINE                      = 112,
    CRITERIA_TYPE_EARN_HONORABLE_KILL                   = 113,
    CRITERIA_TYPE_ACCEPTED_SUMMONINGS                   = 114,
    CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS               = 115,
    // 116 - unused (Legion - 23420)
    // 117 - unused (Legion - 23420)
    CRITERIA_TYPE_COMPLETE_LFG_DUNGEON                  = 118,
    CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS         = 119,
    CRITERIA_TYPE_LFG_VOTE_KICKS_INITIATED_BY_PLAYER    = 120,
    CRITERIA_TYPE_LFG_VOTE_KICKS_NOT_INIT_BY_PLAYER     = 121,
    CRITERIA_TYPE_BE_KICKED_FROM_LFG                    = 122,
    CRITERIA_TYPE_LFG_LEAVES                            = 123,
    CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS              = 124,
    CRITERIA_TYPE_REACH_GUILD_LEVEL                     = 125,
    CRITERIA_TYPE_CRAFT_ITEMS_GUILD                     = 126,
    CRITERIA_TYPE_CATCH_FROM_POOL                       = 127,
    CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS                  = 128,
    CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS         = 129,
    CRITERIA_TYPE_WIN_RATED_BATTLEGROUND                = 130,
    // 131 - unused (Legion - 23420)
    CRITERIA_TYPE_REACH_BG_RATING                       = 132,
    CRITERIA_TYPE_BUY_GUILD_TABARD                      = 133,
    CRITERIA_TYPE_COMPLETE_QUESTS_GUILD                 = 134,
    CRITERIA_TYPE_HONORABLE_KILLS_GUILD                 = 135,
    CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD              = 136,
    CRITERIA_TYPE_COUNT_OF_LFG_QUEUE_BOOSTS_BY_TANK     = 137,
    CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE         = 138, //struct { Flag flag; uint32 count; } 1: Guild Dungeon, 2:Guild Challenge, 3:Guild battlefield
    CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE              = 139, //struct { uint32 count; } Guild Challenge
    // 140 - 1 criteria (16883), unused (Legion - 23420)
    // 141 - 1 criteria (16884), unused (Legion - 23420)
    // 142 - 1 criteria (16881), unused (Legion - 23420)
    // 143 - 1 criteria (16882), unused (Legion - 23420)
    // 144 - 1 criteria (17386), unused (Legion - 23420)
    CRITERIA_TYPE_LFR_DUNGEONS_COMPLETED                = 145,
    CRITERIA_TYPE_LFR_LEAVES                            = 146,
    CRITERIA_TYPE_LFR_VOTE_KICKS_INITIATED_BY_PLAYER    = 147,
    CRITERIA_TYPE_LFR_VOTE_KICKS_NOT_INIT_BY_PLAYER     = 148,
    CRITERIA_TYPE_BE_KICKED_FROM_LFR                    = 149,
    CRITERIA_TYPE_COUNT_OF_LFR_QUEUE_BOOSTS_BY_TANK     = 150,
    CRITERIA_TYPE_COMPLETE_SCENARIO_COUNT               = 151,
    CRITERIA_TYPE_COMPLETE_SCENARIO                     = 152,
    CRITERIA_TYPE_REACH_AREATRIGGER_WITH_ACTIONSET      = 153,
    // 154 - unused (Legion - 23420)
    CRITERIA_TYPE_OWN_BATTLE_PET                        = 155,
    CRITERIA_TYPE_OWN_BATTLE_PET_COUNT                  = 156,
    CRITERIA_TYPE_CAPTURE_BATTLE_PET                    = 157,
    CRITERIA_TYPE_WIN_PET_BATTLE                        = 158,
    // 159 - 2 criterias (22312,22314), unused (Legion - 23420)
    CRITERIA_TYPE_LEVEL_BATTLE_PET                      = 160,
    CRITERIA_TYPE_CAPTURE_BATTLE_PET_CREDIT             = 161, // triggers a quest credit
    CRITERIA_TYPE_LEVEL_BATTLE_PET_CREDIT               = 162, // triggers a quest credit
    CRITERIA_TYPE_ENTER_AREA                            = 163, // triggers a quest credit
    CRITERIA_TYPE_LEAVE_AREA                            = 164, // triggers a quest credit
    CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER            = 165,
    // 166 - unused (Legion - 23420)
    CRITERIA_TYPE_PLACE_GARRISON_BUILDING               = 167,
    CRITERIA_TYPE_UPGRADE_GARRISON_BUILDING             = 168,
    CRITERIA_TYPE_CONSTRUCT_GARRISON_BUILDING           = 169,
    CRITERIA_TYPE_UPGRADE_GARRISON                      = 170,
    CRITERIA_TYPE_START_GARRISON_MISSION                = 171,
    CRITERIA_TYPE_START_ORDER_HALL_MISSION              = 172,
    CRITERIA_TYPE_COMPLETE_GARRISON_MISSION_COUNT       = 173,
    CRITERIA_TYPE_COMPLETE_GARRISON_MISSION             = 174,
    CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_COUNT       = 175,
    CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER             = 176,
    // 177 - 0 criterias (Legion - 23420)
    CRITERIA_TYPE_LEARN_GARRISON_BLUEPRINT_COUNT        = 178,
    // 179 - 0 criterias (Legion - 23420)
    // 180 - 0 criterias (Legion - 23420)
    // 181 - 0 criterias (Legion - 23420)
    CRITERIA_TYPE_COMPLETE_GARRISON_SHIPMENT            = 182,
    CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_ITEM_LEVEL    = 183,
    CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_LEVEL         = 184,
    CRITERIA_TYPE_OWN_TOY                               = 185,
    CRITERIA_TYPE_OWN_TOY_COUNT                         = 186,
    CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_WITH_QUALITY= 187,
    // 188 - 0 criterias (Legion - 23420)
    CRITERIA_TYPE_OWN_HEIRLOOMS                         = 189,
    CRITERIA_TYPE_ARTIFACT_POWER_EARNED                 = 190,
    CRITERIA_TYPE_ARTIFACT_TRAITS_UNLOCKED              = 191,
    CRITERIA_TYPE_HONOR_LEVEL_REACHED                   = 194,
    CRITERIA_TYPE_PRESTIGE_REACHED                      = 195,
    // 196 - CRITERIA_TYPE_REACH_LEVEL_2 or something
    // 197 - Order Hall Advancement related
    CRITERIA_TYPE_ORDER_HALL_TALENT_LEARNED             = 198,
    CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT           = 199,
    CRITERIA_TYPE_ORDER_HALL_RECRUIT_TROOP              = 200,
    // 201 - 0 criterias (Legion - 23420)
    // 202 - 0 criterias (Legion - 23420)
    CRITERIA_TYPE_COMPLETE_WORLD_QUEST                  = 203,
    // 204 - Special criteria type to award players for some external events? Comes with what looks like an identifier, so guessing it's not unique.
    CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED                 = 205,
    CRITERIA_TYPE_GAIN_PARAGON_REPUTATION               = 206,
    CRITERIA_TYPE_EARN_HONOR_XP                         = 207,
    CRITERIA_TYPE_RELIC_TALENT_UNLOCKED                 = 211,
    CRITERIA_TYPE_REACH_ACCOUNT_HONOR_LEVEL             = 213,
    CRITERIA_TYPE_HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED= 214,
    CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED        = 215
};

#define CRITERIA_TYPE_TOTAL 219

enum CriteriaTreeFlags : uint16
{
    CRITERIA_TREE_FLAG_PROGRESS_BAR         = 0x0001,
    CRITERIA_TREE_FLAG_PROGRESS_IS_DATE     = 0x0004,
    CRITERIA_TREE_FLAG_SHOW_CURRENCY_ICON   = 0x0008,
    CRITERIA_TREE_FLAG_ALLIANCE_ONLY        = 0x0200,
    CRITERIA_TREE_FLAG_HORDE_ONLY           = 0x0400,
    CRITERIA_TREE_FLAG_SHOW_REQUIRED_COUNT  = 0x0800
};

enum CriteriaTreeOperator : uint8
{
    CRITERIA_TREE_OPERATOR_SINGLE                   = 0,
    CRITERIA_TREE_OPERATOR_SINGLE_NOT_COMPLETED     = 1,
    CRITERIA_TREE_OPERATOR_ALL                      = 4,
    CRITERIA_TREE_OPERAROR_SUM_CHILDREN             = 5,
    CRITERIA_TREE_OPERATOR_MAX_CHILD                = 6,
    CRITERIA_TREE_OPERATOR_COUNT_DIRECT_CHILDREN    = 7,
    CRITERIA_TREE_OPERATOR_ANY                      = 8,
    CRITERIA_TREE_OPERATOR_SUM_CHILDREN_WEIGHT      = 9
};

enum class CharBaseSectionVariation : uint8
{
    Skin           = 0,
    Face           = 1,
    FacialHair     = 2,
    Hair           = 3,
    Underwear      = 4,
    CustomDisplay1 = 5,
    CustomDisplay2 = 6,
    CustomDisplay3 = 7,

    Count
};

enum CharSectionFlags
{
    SECTION_FLAG_PLAYER = 0x01,
    SECTION_FLAG_DEATH_KNIGHT = 0x04,
    SECTION_FLAG_DEMON_HUNTER = 0x20,
    SECTION_FLAG_CONDITIONAL = 0x400
};

enum CharSectionType
{
    SECTION_TYPE_SKIN_LOW_RES = 0,
    SECTION_TYPE_FACE_LOW_RES = 1,
    SECTION_TYPE_FACIAL_HAIR_LOW_RES = 2,
    SECTION_TYPE_HAIR_LOW_RES = 3,
    SECTION_TYPE_UNDERWEAR_LOW_RES = 4,
    SECTION_TYPE_SKIN = 5,
    SECTION_TYPE_FACE = 6,
    SECTION_TYPE_FACIAL_HAIR = 7,
    SECTION_TYPE_HAIR = 8,
    SECTION_TYPE_UNDERWEAR = 9,
    SECTION_TYPE_CUSTOM_DISPLAY_1_LOW_RES = 10,
    SECTION_TYPE_CUSTOM_DISPLAY_1 = 11,
    SECTION_TYPE_CUSTOM_DISPLAY_2_LOW_RES = 12,
    SECTION_TYPE_CUSTOM_DISPLAY_2 = 13,
    SECTION_TYPE_CUSTOM_DISPLAY_3_LOW_RES = 14,
    SECTION_TYPE_CUSTOM_DISPLAY_3 = 15,

    SECTION_TYPE_MAX
};

enum Curves
{
    CURVE_ID_ARTIFACT_RELIC_ITEM_LEVEL_BONUS    = 1718,
    CURVE_ID_AZERITE_EMPOWERED_ITEM_RESPEC_COST = 6785
};

enum Difficulty : uint8
{
    DIFFICULTY_NONE                 = 0,
    DIFFICULTY_NORMAL               = 1,
    DIFFICULTY_HEROIC               = 2,
    DIFFICULTY_10_N                 = 3,
    DIFFICULTY_25_N                 = 4,
    DIFFICULTY_10_HC                = 5,
    DIFFICULTY_25_HC                = 6,
    DIFFICULTY_LFR                  = 7,
    DIFFICULTY_MYTHIC_KEYSTONE      = 8,
    DIFFICULTY_40                   = 9,
    DIFFICULTY_3_MAN_SCENARIO_HC    = 11,
    DIFFICULTY_3_MAN_SCENARIO_N     = 12,
    DIFFICULTY_NORMAL_RAID          = 14,
    DIFFICULTY_HEROIC_RAID          = 15,
    DIFFICULTY_MYTHIC_RAID          = 16,
    DIFFICULTY_LFR_NEW              = 17,
    DIFFICULTY_EVENT_RAID           = 18,
    DIFFICULTY_EVENT_DUNGEON        = 19,
    DIFFICULTY_EVENT_SCENARIO       = 20,
    DIFFICULTY_MYTHIC               = 23,
    DIFFICULTY_TIMEWALKING          = 24,
    DIFFICULTY_WORLD_PVP_SCENARIO   = 25,
    DIFFICULTY_5_MAN_SCENARIO_N     = 26,
    DIFFICULTY_20_MAN_SCENARIO_N    = 27,
    DIFFICULTY_PVEVP_SCENARIO       = 29,
    DIFFICULTY_EVENT_SCENARIO_6     = 30,
    DIFFICULTY_WORLD_PVP_SCENARIO_2 = 32,
    DIFFICULTY_TIMEWALKING_RAID     = 33,
    DIFFICULTY_PVP                  = 34,
    DIFFICULTY_NORMAL_ISLAND        = 38,
    DIFFICULTY_HEROIC_ISLAND        = 39,
    DIFFICULTY_MYTHIC_ISLAND        = 40,
    DIFFICULTY_PVP_ISLAND           = 45,
    DIFFICULTY_NORMAL_WARFRONT      = 147,
    DIFFICULTY_HEROIC_WARFRONT      = 149,
    DIFFICULTY_LFR_15TH_ANNIVERSARY = 151,
    DIFFICULTY_VISIONS_OF_NZOTH     = 152,
    DIFFICULTY_TEEMING_ISLAND       = 153
};

enum DifficultyFlags
{
    DIFFICULTY_FLAG_HEROIC          = 0x01,
    DIFFICULTY_FLAG_DEFAULT         = 0x02,
    DIFFICULTY_FLAG_CAN_SELECT      = 0x04, // Player can select this difficulty in dropdown menu
    DIFFICULTY_FLAG_CHALLENGE_MODE  = 0x08,

    DIFFICULTY_FLAG_LEGACY          = 0x20,
    DIFFICULTY_FLAG_DISPLAY_HEROIC  = 0x40, // Controls icon displayed on minimap when inside the instance
    DIFFICULTY_FLAG_DISPLAY_MYTHIC  = 0x80  // Controls icon displayed on minimap when inside the instance
};

enum SpawnMask
{
    SPAWNMASK_CONTINENT = (1 << DIFFICULTY_NONE), // any maps without spawn modes

    SPAWNMASK_DUNGEON_NORMAL    = (1 << DIFFICULTY_NORMAL),
    SPAWNMASK_DUNGEON_HEROIC    = (1 << DIFFICULTY_HEROIC),
    SPAWNMASK_DUNGEON_ALL       = (SPAWNMASK_DUNGEON_NORMAL | SPAWNMASK_DUNGEON_HEROIC),

    SPAWNMASK_RAID_10MAN_NORMAL = (1 << DIFFICULTY_10_N),
    SPAWNMASK_RAID_25MAN_NORMAL = (1 << DIFFICULTY_25_N),
    SPAWNMASK_RAID_NORMAL_ALL   = (SPAWNMASK_RAID_10MAN_NORMAL | SPAWNMASK_RAID_25MAN_NORMAL),

    SPAWNMASK_RAID_10MAN_HEROIC = (1 << DIFFICULTY_10_HC),
    SPAWNMASK_RAID_25MAN_HEROIC = (1 << DIFFICULTY_25_HC),
    SPAWNMASK_RAID_HEROIC_ALL   = (SPAWNMASK_RAID_10MAN_HEROIC | SPAWNMASK_RAID_25MAN_HEROIC),

    SPAWNMASK_RAID_ALL          = (SPAWNMASK_RAID_NORMAL_ALL | SPAWNMASK_RAID_HEROIC_ALL)
};

enum class ExpectedStatType : uint8
{
    CreatureHealth          = 0,
    PlayerHealth            = 1,
    CreatureAutoAttackDps   = 2,
    CreatureArmor           = 3,
    PlayerMana              = 4,
    PlayerPrimaryStat       = 5,
    PlayerSecondaryStat     = 6,
    ArmorConstant           = 7,
    None                    = 8,
    CreatureSpellDamage     = 9
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

#define MAX_ITEM_PROTO_FLAGS 4
#define MAX_ITEM_PROTO_ZONES 2
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
    MAP_ARENA           = 4,                                // arena
    MAP_SCENARIO        = 5                                 // scenario
};

enum MapFlags
{
    MAP_FLAG_CAN_TOGGLE_DIFFICULTY  = 0x0100,
    MAP_FLAG_FLEX_LOCKING           = 0x8000, // All difficulties share completed encounters lock, not bound to a single instance id
                                              // heroic difficulty flag overrides it and uses instance id bind
    MAP_FLAG_GARRISON               = 0x4000000
};

enum AbilytyLearnType
{
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE  = 1, // Spell state will update depending on skill value
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN  = 2, // Spell will be learned/removed together with entire skill
    SKILL_LINE_ABILITY_REWARDED_FROM_QUEST     = 4  // Learned as quest reward, also re-learned if missing
};

enum GlyphSlotType
{
    GLYPH_SLOT_MAJOR = 0,
    GLYPH_SLOT_MINOR = 1,
    GLYPH_SLOT_PRIME = 2
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE                              = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL                      = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE                            = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL                       = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE                        = 4,
    ITEM_ENCHANTMENT_TYPE_STAT                              = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM                             = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL                         = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET                  = 8,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_TYPE = 9,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID   = 10,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_ID                     = 11,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_CURVE                  = 12,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER  = 13
};

enum ItemExtendedCostFlags
{
    ITEM_EXT_COST_FLAG_REQUIRE_GUILD                = 0x01,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1   = 0x02,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_2   = 0x04,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_3   = 0x08,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_4   = 0x10,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_5   = 0x20,
};

enum ItemBonusType
{
    ITEM_BONUS_ITEM_LEVEL                       = 1,
    ITEM_BONUS_STAT                             = 2,
    ITEM_BONUS_QUALITY                          = 3,
    ITEM_BONUS_DESCRIPTION                      = 4,
    ITEM_BONUS_SUFFIX                           = 5,
    ITEM_BONUS_SOCKET                           = 6,
    ITEM_BONUS_APPEARANCE                       = 7,
    ITEM_BONUS_REQUIRED_LEVEL                   = 8,
    ITEM_BONUS_DISPLAY_TOAST_METHOD             = 9,
    ITEM_BONUS_REPAIR_COST_MULTIPLIER           = 10,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION        = 11,
    ITEM_BONUS_DISENCHANT_LOOT_ID               = 12,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION_FIXED  = 13,
    ITEM_BONUS_ITEM_LEVEL_CAN_INCREASE          = 14,             // Displays a + next to item level indicating it can warforge
    ITEM_BONUS_RANDOM_ENCHANTMENT               = 15,             // Responsible for showing "<Random additional stats>" or "+%d Rank Random Minor Trait" in the tooltip before item is obtained
    ITEM_BONUS_BONDING                          = 16,
    ITEM_BONUS_RELIC_TYPE                       = 17,
    ITEM_BONUS_OVERRIDE_REQUIRED_LEVEL          = 18,
    ITEM_BONUS_AZERITE_TIER_UNLOCK_SET          = 19,
    ITEM_BONUS_SCRAPPING_LOOT_ID                = 20,
    ITEM_BONUS_OVERRIDE_CAN_DISENCHANT          = 21,
    ITEM_BONUS_OVERRIDE_CAN_SCRAP               = 22,
    ITEM_BONUS_ITEM_EFFECT_ID                   = 23,
};

enum class ItemContext : uint8
{
    NONE                    = 0,
    Dungeon_Normal          = 1,
    Dungeon_Heroic          = 2,
    Raid_Normal             = 3,
    Raid_Raid_Finder        = 4,
    Raid_Heroic             = 5,
    Raid_Mythic             = 6,
    PVP_Unranked_1          = 7,
    PVP_Ranked_1            = 8,
    Scenario_Normal         = 9,
    Scenario_Heroic         = 10,
    Quest_Reward            = 11,
    Store                   = 12,
    Trade_Skill             = 13,
    Vendor                  = 14,
    Black_Market            = 15,
    Challenge_Mode_1        = 16,
    Dungeon_Lvl_Up_1        = 17,
    Dungeon_Lvl_Up_2        = 18,
    Dungeon_Lvl_Up_3        = 19,
    Dungeon_Lvl_Up_4        = 20,
    Force_to_NONE           = 21,
    TimeWalker              = 22,
    Dungeon_Mythic          = 23,
    Pvp_Honor_Reward        = 24,
    World_Quest_1           = 25,
    World_Quest_2           = 26,
    World_Quest_3           = 27,
    World_Quest_4           = 28,
    World_Quest_5           = 29,
    World_Quest_6           = 30,
    Mission_Reward_1        = 31,
    Mission_Reward_2        = 32,
    Challenge_Mode_2        = 33,
    Challenge_Mode_3        = 34,
    Challenge_Mode_Jackpot  = 35,
    World_Quest_7           = 36,
    World_Quest_8           = 37,
    PVP_Ranked_2            = 38,
    PVP_Ranked_3            = 39,
    PVP_Ranked_4            = 40,
    PVP_Unranked_2          = 41,
    World_Quest_9           = 42,
    World_Quest_10          = 43,
    PVP_Ranked_5            = 44,
    PVP_Ranked_6            = 45,
    PVP_Ranked_7            = 46,
    PVP_Unranked_3          = 47,
    PVP_Unranked_4          = 48,
    PVP_Unranked_5          = 49,
    PVP_Unranked_6          = 50,
    PVP_Unranked_7          = 51,
    PVP_Ranked_8            = 52,
    World_Quest_11          = 53,
    World_Quest_12          = 54,
    World_Quest_13          = 55,
    PVP_Ranked_Jackpot      = 56,
    Tournament_Realm        = 57,
    Relinquished            = 58,
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE       = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP      = 1                       // limit applied to amount equipped items (including used gems)
};

enum ItemSetFlags
{
    ITEM_SET_FLAG_LEGACY_INACTIVE = 0x01,
};

enum ItemSpecStat
{
    ITEM_SPEC_STAT_INTELLECT        = 0,
    ITEM_SPEC_STAT_AGILITY          = 1,
    ITEM_SPEC_STAT_STRENGTH         = 2,
    ITEM_SPEC_STAT_SPIRIT           = 3,
    ITEM_SPEC_STAT_HIT              = 4,
    ITEM_SPEC_STAT_DODGE            = 5,
    ITEM_SPEC_STAT_PARRY            = 6,
    ITEM_SPEC_STAT_ONE_HANDED_AXE   = 7,
    ITEM_SPEC_STAT_TWO_HANDED_AXE   = 8,
    ITEM_SPEC_STAT_ONE_HANDED_SWORD = 9,
    ITEM_SPEC_STAT_TWO_HANDED_SWORD = 10,
    ITEM_SPEC_STAT_ONE_HANDED_MACE  = 11,
    ITEM_SPEC_STAT_TWO_HANDED_MACE  = 12,
    ITEM_SPEC_STAT_DAGGER           = 13,
    ITEM_SPEC_STAT_FIST_WEAPON      = 14,
    ITEM_SPEC_STAT_GUN              = 15,
    ITEM_SPEC_STAT_BOW              = 16,
    ITEM_SPEC_STAT_CROSSBOW         = 17,
    ITEM_SPEC_STAT_STAFF            = 18,
    ITEM_SPEC_STAT_POLEARM          = 19,
    ITEM_SPEC_STAT_THROWN           = 20,
    ITEM_SPEC_STAT_WAND             = 21,
    ITEM_SPEC_STAT_SHIELD           = 22,
    ITEM_SPEC_STAT_RELIC            = 23,
    ITEM_SPEC_STAT_CRIT             = 24,
    ITEM_SPEC_STAT_HASTE            = 25,
    ITEM_SPEC_STAT_BONUS_ARMOR      = 26,
    ITEM_SPEC_STAT_CLOAK            = 27,
    ITEM_SPEC_STAT_WARGLAIVES       = 28,
    ITEM_SPEC_STAT_RELIC_IRON       = 29,
    ITEM_SPEC_STAT_RELIC_BLOOD      = 30,
    ITEM_SPEC_STAT_RELIC_SHADOW     = 31,
    ITEM_SPEC_STAT_RELIC_FEL        = 32,
    ITEM_SPEC_STAT_RELIC_ARCANE     = 33,
    ITEM_SPEC_STAT_RELIC_FROST      = 34,
    ITEM_SPEC_STAT_RELIC_FIRE       = 35,
    ITEM_SPEC_STAT_RELIC_WATER      = 36,
    ITEM_SPEC_STAT_RELIC_LIFE       = 37,
    ITEM_SPEC_STAT_RELIC_WIND       = 38,
    ITEM_SPEC_STAT_RELIC_HOLY       = 39,

    ITEM_SPEC_STAT_NONE             = 40
};

enum MapDifficultyFlags : uint8
{
    MAP_DIFFICULTY_FLAG_CANNOT_EXTEND   = 0x10
};

enum class ModifierTreeOperator : int8
{
    SingleTrue  = 2,
    SingleFalse = 3,
    All         = 4,
    Some        = 8
};

enum MountCapabilityFlags
{
    MOUNT_CAPABILITY_FLAG_GROUND                = 0x1,
    MOUNT_CAPABILITY_FLAG_FLYING                = 0x2,
    MOUNT_CAPABILITY_FLAG_FLOAT                 = 0x4,
    MOUNT_CAPABILITY_FLAG_UNDERWATER            = 0x8,
    MOUNT_CAPABIILTY_FLAG_IGNORE_RESTRICTIONS   = 0x20,
};

enum MountFlags
{
    MOUNT_FLAG_SELF_MOUNT               = 0x02,                   // Player becomes the mount himself
    MOUNT_FLAG_FACTION_SPECIFIC         = 0x04,
    MOUNT_FLAG_PREFERRED_SWIMMING       = 0x10,
    MOUNT_FLAG_PREFERRED_WATER_WALKING  = 0x20,
    MOUNT_FLAG_HIDE_IF_UNKNOWN          = 0x40
};

enum PhaseEntryFlags : uint16
{
    PHASE_FLAG_NORMAL   = 0x08,
    PHASE_FLAG_COSMETIC = 0x10,
    PHASE_FLAG_PERSONAL = 0x20
};

// PhaseUseFlags fields in different db2s
enum PhaseUseFlagsValues : uint8
{
    PHASE_USE_FLAGS_NONE            = 0x0,
    PHASE_USE_FLAGS_ALWAYS_VISIBLE  = 0x1,
    PHASE_USE_FLAGS_INVERSE         = 0x2,

    PHASE_USE_FLAGS_ALL             = PHASE_USE_FLAGS_ALWAYS_VISIBLE | PHASE_USE_FLAGS_INVERSE
};

enum class PlayerConditionLfgStatus : uint8
{
    InLFGDungeon            = 1,
    InLFGRandomDungeon      = 2,
    InLFGFirstRandomDungeon = 3,
    PartialClear            = 4,
    StrangerCount           = 5,
    VoteKickCount           = 6,
    BootCount               = 7,
    GearDiff                = 8
};

enum PrestigeLevelInfoFlags : uint8
{
    PRESTIGE_FLAG_DISABLED  = 0x01                      // Prestige levels with this flag won't be included to calculate max prestigelevel.
};

enum QuestPackageFilter
{
    QUEST_PACKAGE_FILTER_LOOT_SPECIALIZATION    = 0,    // Players can select this quest reward if it matches their selected loot specialization
    QUEST_PACKAGE_FILTER_CLASS                  = 1,    // Players can select this quest reward if it matches their class
    QUEST_PACKAGE_FILTER_UNMATCHED              = 2,    // Players can select this quest reward if no class/loot_spec rewards are available
    QUEST_PACKAGE_FILTER_EVERYONE               = 3     // Players can always select this quest reward
};

enum ScenarioStepFlags
{
    SCENARIO_STEP_FLAG_BONUS_OBJECTIVE      = 0x1,
    SCENARIO_STEP_FLAG_HEROIC_ONLY          = 0x2
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
    SPELL_CATEGORY_FLAG_COOLDOWN_STARTS_ON_EVENT            = 0x04,
    SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_DAILY_RESET     = 0x08
};

#define MAX_SPELL_EFFECTS 32
#define MAX_EFFECT_MASK 0xFFFFFFFF

#define MAX_SPELL_AURA_INTERRUPT_FLAGS 2

enum SpellItemEnchantmentFlags
{
    ENCHANTMENT_CAN_SOULBOUND           = 0x01,
    ENCHANTMENT_UNK1                    = 0x02,
    ENCHANTMENT_UNK2                    = 0x04,
    ENCHANTMENT_UNK3                    = 0x08,
    ENCHANTMENT_COLLECTABLE             = 0x100,
    ENCHANTMENT_HIDE_IF_NOT_COLLECTED   = 0x200,
};

enum SpellProcsPerMinuteModType
{
    SPELL_PPM_MOD_HASTE         = 1,
    SPELL_PPM_MOD_CRIT          = 2,
    SPELL_PPM_MOD_CLASS         = 3,
    SPELL_PPM_MOD_SPEC          = 4,
    SPELL_PPM_MOD_RACE          = 5,
    SPELL_PPM_MOD_ITEM_LEVEL    = 6,
    SPELL_PPM_MOD_BATTLEGROUND  = 7
};

constexpr std::size_t MAX_POWERS_PER_SPELL = 4;

enum SpellShapeshiftFormFlags
{
    SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT         = 0x0001,
    SHAPESHIFT_FORM_CANNOT_CANCEL               = 0x0002,   // player cannot cancel the aura giving this shapeshift
    SHAPESHIFT_FORM_CAN_INTERACT                = 0x0008,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag must be present to allow NPC interaction
    SHAPESHIFT_FORM_CAN_EQUIP_ITEMS             = 0x0040,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows equipping items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    SHAPESHIFT_FORM_CAN_USE_ITEMS               = 0x0080,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows using items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    SHAPESHIFT_FORM_CAN_AUTO_UNSHIFT            = 0x0100,   // clientside
    SHAPESHIFT_FORM_PREVENT_LFG_TELEPORT        = 0x0200,
    SHAPESHIFT_FORM_PREVENT_USING_OWN_SKILLS    = 0x0400,   // prevents using spells that don't have any shapeshift requirement
    SHAPESHIFT_FORM_PREVENT_EMOTE_SOUNDS        = 0x1000
};

#define TaxiMaskSize 319
typedef std::array<uint8, TaxiMaskSize> TaxiMask;

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

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 3
enum SummonPropType
{
    SUMMON_PROP_TYPE_UNKNOWN         = 0,                   // different summons, 1330 spells in 3.0.3
    SUMMON_PROP_TYPE_SUMMON          = 1,                   // generic summons, 49 spells in 3.0.3
    SUMMON_PROP_TYPE_GUARDIAN        = 2,                   // summon guardian, 393 spells in 3.0.3
    SUMMON_PROP_TYPE_ARMY            = 3,                   // summon army, 5 spells in 3.0.3
    SUMMON_PROP_TYPE_TOTEM           = 4,                   // summon totem, 169 spells in 3.0.3
    SUMMON_PROP_TYPE_CRITTER         = 5,                   // critter/minipet, 195 spells in 3.0.3
    SUMMON_PROP_TYPE_DK              = 6,                   // summon DRW/Ghoul, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_BOMB            = 7,                   // summon bot/bomb, 4 spells in 3.0.3
    SUMMON_PROP_TYPE_PHASING         = 8,                   // something todo with DK prequest line, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_SIEGE_VEH       = 9,                   // summon different vehicles, 14 spells in 3.0.3
    SUMMON_PROP_TYPE_DRAKE_VEH       = 10,                  // summon drake (vehicle), 3 spells
    SUMMON_PROP_TYPE_LIGHTWELL       = 11,                  // summon lightwell, 6 spells in 3.0.3
    SUMMON_PROP_TYPE_JEEVES          = 12,                  // summon Jeeves, 1 spell in 3.3.5a
    SUMMON_PROP_TYPE_LASHTAIL        = 13                   // Lashtail Hatchling, 1 spell in 4.2.2
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
    SUMMON_PROP_FLAG_UNK16           = 0x00008000,          // Light/Dark Bullet, Soul/Fiery Consumption, Twisted Visage, Twilight Whelp. Phase related?
    SUMMON_PROP_FLAG_UNK17           = 0x00010000,
    SUMMON_PROP_FLAG_UNK18           = 0x00020000,
    SUMMON_PROP_FLAG_UNK19           = 0x00040000,
    SUMMON_PROP_FLAG_UNK20           = 0x00080000,
    SUMMON_PROP_FLAG_UNK21           = 0x00100000,          // Totems
    SUMMON_PROP_FLAG_COMPANION       = 0x00200000
};

#define MAX_TALENT_TIERS 7
#define MAX_TALENT_COLUMNS 3
#define MAX_PVP_TALENT_SLOTS 4

enum TaxiNodeFlags
{
    TAXI_NODE_FLAG_ALLIANCE             = 0x01,
    TAXI_NODE_FLAG_HORDE                = 0x02,
    TAXI_NODE_FLAG_USE_FAVORITE_MOUNT   = 0x10
};

enum TaxiPathNodeFlags
{
    TAXI_PATH_NODE_FLAG_TELEPORT    = 0x1,
    TAXI_PATH_NODE_FLAG_STOP        = 0x2
};

enum UiMapSystem : int8
{
    UI_MAP_SYSTEM_WORLD     = 0,
    UI_MAP_SYSTEM_TAXI      = 1,
    UI_MAP_SYSTEM_ADVENTURE = 2,
    MAX_UI_MAP_SYSTEM       = 3
};

enum UiMapType : int8
{
    UI_MAP_TYPE_COSMIC      = 0,
    UI_MAP_TYPE_WORLD       = 1,
    UI_MAP_TYPE_CONTINENT   = 2,
    UI_MAP_TYPE_ZONE        = 3,
    UI_MAP_TYPE_DUNGEON     = 4,
    UI_MAP_TYPE_MICRO       = 5,
    UI_MAP_TYPE_ORPHAN      = 6,
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER                         = 0x00000001,
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE                          = 0x00000002,
    VEHICLE_SEAT_FLAG_DISABLE_GRAVITY                                  = 0x00000004, // Passenger will not be affected by gravity
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

// CurrencyTypes.dbc
enum CurrencyTypes
{
    CURRENCY_TYPE_JUSTICE_POINTS        = 395,
    CURRENCY_TYPE_VALOR_POINTS          = 396,
    CURRENCY_TYPE_APEXIS_CRYSTALS       = 823,
    CURRENCY_TYPE_AZERITE               = 1553
};

enum WorldMapTransformsFlags
{
    WORLD_MAP_TRANSFORMS_FLAG_DUNGEON   = 0x04
};

enum class WorldStateExpressionValueType : uint8
{
    Constant    = 1,
    WorldState  = 2,
    Function    = 3
};

enum class WorldStateExpressionLogic : uint8
{
    None    = 0,
    And     = 1,
    Or      = 2,
    Xor     = 3,
};

enum class WorldStateExpressionComparisonType : uint8
{
    None            = 0,
    Equal           = 1,
    NotEqual        = 2,
    Less            = 3,
    LessOrEqual     = 4,
    Greater         = 5,
    GreaterOrEqual  = 6,
};

enum class WorldStateExpressionOperatorType : uint8
{
    None            = 0,
    Sum             = 1,
    Substraction    = 2,
    Multiplication  = 3,
    Division        = 4,
    Remainder       = 5,
};

enum WorldStateExpressionFunctions
{
    WSE_FUNCTION_NONE = 0,
    WSE_FUNCTION_RANDOM,
    WSE_FUNCTION_MONTH,
    WSE_FUNCTION_DAY,
    WSE_FUNCTION_TIME_OF_DAY,
    WSE_FUNCTION_REGION,
    WSE_FUNCTION_CLOCK_HOUR,
    WSE_FUNCTION_OLD_DIFFICULTY_ID,
    WSE_FUNCTION_HOLIDAY_START,
    WSE_FUNCTION_HOLIDAY_LEFT,
    WSE_FUNCTION_HOLIDAY_ACTIVE,
    WSE_FUNCTION_TIMER_CURRENT_TIME,
    WSE_FUNCTION_WEEK_NUMBER,
    WSE_FUNCTION_UNK13,
    WSE_FUNCTION_UNK14,
    WSE_FUNCTION_DIFFICULTY_ID,
    WSE_FUNCTION_WAR_MODE_ACTIVE,
    WSE_FUNCTION_UNK17,
    WSE_FUNCTION_UNK18,
    WSE_FUNCTION_UNK19,
    WSE_FUNCTION_UNK20,
    WSE_FUNCTION_UNK21,
    WSE_FUNCTION_WORLD_STATE_EXPRESSION,
    WSE_FUNCTION_KEYSTONE_AFFIX,
    WSE_FUNCTION_UNK24,
    WSE_FUNCTION_UNK25,
    WSE_FUNCTION_UNK26,
    WSE_FUNCTION_UNK27,
    WSE_FUNCTION_KEYSTONE_LEVEL,
    WSE_FUNCTION_UNK29,
    WSE_FUNCTION_UNK30,
    WSE_FUNCTION_UNK31,
    WSE_FUNCTION_UNK32,
    WSE_FUNCTION_MERSENNE_RANDOM,
    WSE_FUNCTION_UNK34,
    WSE_FUNCTION_UNK35,
    WSE_FUNCTION_UNK36,
    WSE_FUNCTION_UI_WIDGET_DATA,

    WSE_FUNCTION_MAX,
};

#endif
