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
    DEFAULT_MAX_LEVEL = 60,

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
    MAX_LEVEL = 123,

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

uint32 constexpr ACHIVEMENT_CATEGORY_PET_BATTLES = 15117;

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,                // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2                  = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,                // city and city subzones
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
    AREA_FLAG_COMBAT                = 0x01000000,                // "combat" area (Script_GetZonePVPInfo), used
    AREA_FLAG_INSIDE                = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE               = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_CAN_HEARTH_AND_RESURRECT = 0x08000000,             // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE           = 0x20000000,                // Marks zones where you cannot fly
    AREA_FLAG_UNK9                  = 0x40000000
};

enum AreaFlags2
{
    AREA_FLAG_2_DONT_SHOW_SANCTUARY = 0x00000200,                // Hides sanctuary status from zone text color (Script_GetZonePVPInfo)
    AREA_FLAG_2_CAN_ENABLE_WAR_MODE = 0x00001000,                // Allows enabling war mode
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

#define BATTLE_PET_SPECIES_MAX_ID 3159

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

enum class ChrRacesFlag : int32
{
    AlliedRace  = 0x80000
};

DEFINE_ENUM_FLAG(ChrRacesFlag);

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

enum class ContentTuningCalcType : int32
{
    Base                        = 0,
    PlusOne                     = 1,
    PlusMaxLevelForExpansion    = 2
};

enum class ContentTuningFlag : int32
{
    DisabledForItem = 0x04,
    Horde           = 0x8,
    Alliance        = 0x10
};

DEFINE_ENUM_FLAG(ContentTuningFlag);

enum class CorruptionEffectsFlag
{
    None        = 0,
    Disabled    = 0x1
};

DEFINE_ENUM_FLAG(CorruptionEffectsFlag);

enum class CriteriaFailEvent : uint8
{
    None                                = 0,
    Death                               = 1,    // Death
    Hours24WithoutCompletingDailyQuest  = 2,    // 24 hours without completing a daily quest
    LeaveBattleground                   = 3,    // Leave a battleground
    LoseRankedArenaMatchWithTeamSize    = 4,    // Lose a ranked arena match with team size {#Team Size}
    LoseAura                            = 5,    // Lose aura "{Spell}"
    GainAura                            = 6,    // Gain aura "{Spell}"
    GainAuraEffect                      = 7,    // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                           = 8,    // Cast spell "{Spell}"
    BeSpellTarget                       = 9,    // Have spell "{Spell}" cast on you
    ModifyPartyStatus                   = 10,   // Modify your party status
    LosePetBattle                       = 11,   // Lose a pet battle
    BattlePetDies                       = 12,   // Battle pet dies
    DailyQuestsCleared                  = 13,   // Daily quests cleared
    SendEvent                           = 14,   // Send event "{GameEvents}" (player-sent/instance only)

    Count
};

enum class CriteriaStartEvent : uint8
{
    None                            = 0, // - NONE -
    ReachLevel                      = 1, // Reach level {#Level}
    CompleteDailyQuest              = 2, // Complete daily quest "{QuestV2}"
    StartBattleground               = 3, // Start battleground "{Map}"
    WinRankedArenaMatchWithTeamSize = 4, // Win a ranked arena match with team size {#Team Size}
    GainAura                        = 5, // Gain aura "{Spell}"
    GainAuraEffect                  = 6, // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                       = 7, // Cast spell "{Spell}"
    BeSpellTarget                   = 8, // Have spell "{Spell}" cast on you
    AcceptQuest                     = 9, // Accept quest "{QuestV2}"
    KillNPC                         = 10, // Kill NPC "{Creature}"
    KillPlayer                      = 11, // Kill player
    UseItem                         = 12, // Use item "{Item}"
    SendEvent                       = 13, // Send event "{GameEvents}" (player-sent/instance only)
    BeginScenarioStep               = 14, // Begin scenario step "{#Step}" (for use with "Player on Scenario" modifier only)

    Count
};

enum class CriteriaFlags : uint8
{
    FailAchievement         = 0x01, // Fail Achievement
    ResetOnStart            = 0x02, // Reset on Start
    ServerOnly              = 0x04, // Server Only
    AlwaysSaveToDB          = 0x08, // Always Save to DB (Use with Caution)
    AllowCriteriaDecrement  = 0x10, // Allow criteria to be decremented
    IsForQuest              = 0x20  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaFlags);

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
    CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED        = 215,
    CRITERIA_TYPE_MYTHIC_KEYSTONE_COMPLETED             = 216, // NYI
    // 217 - 0 criterias
    CRITERIA_TYPE_COMPLETE_QUEST_ACCUMULATE             = 218,
    CRITERIA_TYPE_BOUGHT_ITEM_FROM_VENDOR               = 219,
    CRITERIA_TYPE_SOLD_ITEM_TO_VENDOR                   = 220,
    // 221 - 0 criterias
    // 222 - 0 criterias
    // 223 - 0 criterias
    // 224 - 0 criterias
    CRITERIA_TYPE_TRAVELLED_TO_AREA                     = 225,
    // 226 - 0 criterias
    // 227 - 0 criterias
    CRITERIA_TYPE_APPLY_CONDUIT                         = 228,
    CRITERIA_TYPE_CONVERT_ITEMS_TO_CURRENCY             = 229,
};

#define CRITERIA_TYPE_TOTAL 232

enum class CriteriaTreeFlags : uint16
{
    ProgressBar                 = 0x0001, // Progress Bar
    DoNotDisplay                = 0x0002, // Do Not Display
    IsDate                      = 0x0004, // Is a Date
    IsMoney                     = 0x0008, // Is Money
    ToastOnComplete             = 0x0010, // Toast on Complete
    UseObjectsDescription       = 0x0020, // Use Object's Description
    ShowFactionSpecificChild    = 0x0040, // Show faction specific child
    DisplayAllChildren          = 0x0080, // Display all children
    AwardBonusRep               = 0x0100, // Award Bonus Rep (Hack!!)
    AllianceOnly                = 0x0200, // Treat this criteria or block as Alliance
    HordeOnly                   = 0x0400, // Treat this criteria or block as Horde
    DisplayAsFraction           = 0x0800, // Display as Fraction
    IsForQuest                  = 0x1000  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaTreeFlags);

enum class CriteriaTreeOperator : uint8
{
    Complete        = 0, // Complete
    NotComplete     = 1, // Not Complete
    CompleteAll     = 4, // Complete All
    Sum             = 5, // Sum Of Criteria Is
    Highest         = 6, // Highest Criteria Is
    StartedAtLeast  = 7, // Started At Least
    CompleteAtLeast = 8, // Complete At Least
    ProgressBar     = 9  // Progress Bar
};

enum class ChrCustomizationOptionFlag : int32
{
    Disabled    = 0x4,
};

DEFINE_ENUM_FLAG(ChrCustomizationOptionFlag);

enum class ChrCustomizationReqFlag : int32
{
    HasRequirements = 0x1
};

DEFINE_ENUM_FLAG(ChrCustomizationReqFlag);

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

enum class FriendshipReputationFlags : int32
{
    NoFXOnReactionChange                            = 0x01,
    NoLogTextOnRepGain                              = 0x02,
    NoLogTextOnReactionChange                       = 0x04,
    ShowRepGainandReactionChangeForHiddenFaction    = 0x08,
    NoRepGainModifiers                              = 0x10
};

DEFINE_ENUM_FLAG(FriendshipReputationFlags);

enum class GlobalCurve : int32
{
    CritDiminishing = 0,
    MasteryDiminishing = 1,
    HasteDiminishing = 2,
    SpeedDiminishing = 3,
    AvoidanceDiminishing = 4,
    VersatilityDoneDiminishing = 5,
    LifestealDiminishing = 6,
    DodgeDiminishing = 7,
    BlockDiminishing = 8,
    ParryDiminishing = 9,

    VersatilityTakenDiminishing = 11,

    ContentTuningPvpItemLevelHealthScaling = 13,
    ContentTuningPvpLevelDamageScaling = 14,
    ContentTuningPvpItemLevelDamageScaling = 15,
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

enum class SkillLineAbilityFlags
{
    CanFallbackToLearnedOnSkillLearn            = 0x80, // The skill is rewarded from a quest if player started on exile's reach

};

DEFINE_ENUM_FLAG(SkillLineAbilityFlags);

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
    ITEM_BONUS_NAME_SUBTITLE                    = 4,              // Text under name
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
    ITEM_BONUS_MODIFIED_CRAFTING_STAT           = 25,
    ITEM_BONUS_REQUIRED_LEVEL_CURVE             = 27,
    ITEM_BONUS_DESCRIPTION_TEXT                 = 30,             // Item description
    ITEM_BONUS_OVERRIDE_NAME                    = 31,             // ItemNameDescription id
};

enum class ItemContext : uint8
{
    NONE                                = 0,
    Dungeon_Normal                      = 1,
    Dungeon_Heroic                      = 2,
    Raid_Normal                         = 3,
    Raid_Raid_Finder                    = 4,
    Raid_Heroic                         = 5,
    Raid_Mythic                         = 6,
    PVP_Unranked_1                      = 7,
    PVP_Ranked_1_Unrated                = 8,
    Scenario_Normal                     = 9,
    Scenario_Heroic                     = 10,
    Quest_Reward                        = 11,
    In_Game_Store                       = 12,
    Trade_Skill                         = 13,
    Vendor                              = 14,
    Black_Market                        = 15,
    MythicPlus_End_of_Run               = 16,
    Dungeon_Lvl_Up_1                    = 17,
    Dungeon_Lvl_Up_2                    = 18,
    Dungeon_Lvl_Up_3                    = 19,
    Dungeon_Lvl_Up_4                    = 20,
    Force_to_NONE                       = 21,
    Timewalking                         = 22,
    Dungeon_Mythic                      = 23,
    Pvp_Honor_Reward                    = 24,
    World_Quest_1                       = 25,
    World_Quest_2                       = 26,
    World_Quest_3                       = 27,
    World_Quest_4                       = 28,
    World_Quest_5                       = 29,
    World_Quest_6                       = 30,
    Mission_Reward_1                    = 31,
    Mission_Reward_2                    = 32,
    MythicPlus_End_of_Run_Time_Chest    = 33,
    zzChallenge_Mode_3                  = 34,
    MythicPlus_Jackpot                  = 35,
    World_Quest_7                       = 36,
    World_Quest_8                       = 37,
    PVP_Ranked_2_Combatant              = 38,
    PVP_Ranked_3_Challenger             = 39,
    PVP_Ranked_4_Rival                  = 40,
    PVP_Unranked_2                      = 41,
    World_Quest_9                       = 42,
    World_Quest_10                      = 43,
    PVP_Ranked_5_Duelist                = 44,
    PVP_Ranked_6_Elite                  = 45,
    PVP_Ranked_7                        = 46,
    PVP_Unranked_3                      = 47,
    PVP_Unranked_4                      = 48,
    PVP_Unranked_5                      = 49,
    PVP_Unranked_6                      = 50,
    PVP_Unranked_7                      = 51,
    PVP_Ranked_8                        = 52,
    World_Quest_11                      = 53,
    World_Quest_12                      = 54,
    World_Quest_13                      = 55,
    PVP_Ranked_Jackpot                  = 56,
    Tournament_Realm                    = 57,
    Relinquished                        = 58,
    Legendary_Forge                     = 59,
    Quest_Bonus_Loot                    = 60,
    Character_Boost_BFA                 = 61,
    Character_Boost_Shadowlands         = 62,
    Legendary_Crafting_1                = 63,
    Legendary_Crafting_2                = 64,
    Legendary_Crafting_3                = 65,
    Legendary_Crafting_4                = 66,
    Legendary_Crafting_5                = 67,
    Legendary_Crafting_6                = 68,
    Legendary_Crafting_7                = 69,
    Legendary_Crafting_8                = 70,
    Legendary_Crafting_9                = 71,
    Weekly_Rewards_Additional           = 72,
    Weekly_Rewards_Concession           = 73,
    World_Quest_Jackpot                 = 74,
    New_Character                       = 75,
    War_Mode                            = 76,
    PvP_Brawl_1                         = 77,
    PvP_Brawl_2                         = 78,
    Torghast                            = 79,
    Corpse_Recovery                     = 80,
    World_Boss                          = 81,
    Raid_Normal_Extended                = 82,
    Raid_Raid_Finder_Extended           = 83,
    Raid_Heroic_Extended                = 84,
    Raid_Mythic_Extended                = 85,
    Character_Template_9_1              = 86,

    Max
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

enum class ModifierTreeType : int32
{
    None                                                                = 0,   // No modifier
    PlayerInebriationLevelEqualOrGreaterThan                            = 1,   // Player inebriation level is {#Drunkenness} or more
    PlayerMeetsCondition                                                = 2,   // Player meets condition "{PlayerCondition}"
    MinimumItemLevel                                                    = 3,   // Minimum item level is {#Item Level}
    TargetCreatureId                                                    = 4,   // Target is NPC "{Creature}"
    TargetIsPlayer                                                      = 5,   // Target is player
    TargetIsDead                                                        = 6,   // Target is dead
    TargetIsOppositeFaction                                             = 7,   // Target is opposite faction
    PlayerHasAura                                                       = 8,   // Player has aura "{Spell}"
    PlayerHasAuraEffect                                                 = 9,   // Player has aura effect "{SpellAuraNames.EnumID}"
    TargetHasAura                                                       = 10,  // Target has aura "{Spell}"
    TargetHasAuraEffect                                                 = 11,  // Target has aura effect "{SpellAuraNames.EnumID}"
    TargetHasAuraState                                                  = 12,  // Target has aura state "{$Aura State}"
    PlayerHasAuraState                                                  = 13,  // Player has aura state "{$Aura State}"
    ItemQualityIsAtLeast                                                = 14,  // Item quality is at least {$Item Quality}
    ItemQualityIsExactly                                                = 15,  // Item quality is exactly {$Item Quality}
    PlayerIsAlive                                                       = 16,  // Player is alive
    PlayerIsInArea                                                      = 17,  // Player is in area "{AreaTable}"
    TargetIsInArea                                                      = 18,  // Target is in area "{AreaTable}"
    ItemId                                                              = 19,  // Item is "{Item}"
    LegacyDungeonDifficulty                                             = 20,  // Legacy dungeon difficulty is "{$Dungeon Difficulty}"
    PlayerToTargetLevelDeltaGreaterThan                                 = 21,  // Exceeds the target's level by {#Level Delta} levels
    TargetToPlayerLevelDeltaGreaterThan                                 = 22,  // Target exceeds your level by {#Level Delta} levels
    PlayerLevelEqualTargetLevel                                         = 23,  // You and the target are equal level
    PlayerInArenaWithTeamSize                                           = 24,  // Player is in an arena with team size {#Team Size}
    PlayerRace                                                          = 25,  // Player race is "{ChrRaces}"
    PlayerClass                                                         = 26,  // Player class is "{ChrClasses}"
    TargetRace                                                          = 27,  // Target race is "{ChrRaces}"
    TargetClass                                                         = 28,  // Target class is "{ChrClasses}"
    LessThanTappers                                                     = 29,  // Less than {#Tappers} tappers
    CreatureType                                                        = 30,  // Creature is type "{CreatureType}"
    CreatureFamily                                                      = 31,  // Creature is family "{CreatureFamily}"
    PlayerMap                                                           = 32,  // Player is on map "{Map}"
    ClientVersionEqualOrLessThan                                        = 33,  // Milestone is at or before "{WowStaticSchemas}"
    BattlePetTeamLevel                                                  = 34,  // All three winning battle pets are at or above level {#Battle Pet Level}
    PlayerIsNotInParty                                                  = 35,  // Player is not in a party
    PlayerIsInParty                                                     = 36,  // Player is in a party
    HasPersonalRatingEqualOrGreaterThan                                 = 37,  // Has a Personal Rating of at least {#Personal Rating}
    HasTitle                                                            = 38,  // Has title "{CharTitles.Mask_ID}"
    PlayerLevelEqual                                                    = 39,  // Player is exactly level {#Level}
    TargetLevelEqual                                                    = 40,  // Target is exactly level {#Level}
    PlayerIsInZone                                                      = 41,  // Player is in top-level area "{AreaTable}"
    TargetIsInZone                                                      = 42,  // Target is in top-level area "{AreaTable}"
    PlayerHealthBelowPercent                                            = 43,  // Player health below {#Percent}%
    PlayerHealthAbovePercent                                            = 44,  // Player health above {#Percent}%
    PlayerHealthEqualsPercent                                           = 45,  // Player health equals {#Percent}%
    TargetHealthBelowPercent                                            = 46,  // Target health below {#Percent}%
    TargetHealthAbovePercent                                            = 47,  // Target health above {#Percent}%
    TargetHealthEqualsPercent                                           = 48,  // Target health equals {#Percent}%
    PlayerHealthBelowValue                                              = 49,  // Player health below {#Hit Points} HP
    PlayerHealthAboveValue                                              = 50,  // Player health above {#Hit Points} HP
    PlayerHealthEqualsValue                                             = 51,  // Player health equals {#Hit Points} HP
    TargetHealthBelowValue                                              = 52,  // Target health below {#Hit Points} HP
    TargetHealthAboveValue                                              = 53,  // Target health above {#Hit Points} HP
    TargetHealthEqualsValue                                             = 54,  // Target health equals {#Hit Points} HP
    TargetIsPlayerAndMeetsCondition                                     = 55,  // Target is a player with condition "{PlayerCondition}"
    PlayerHasMoreThanAchievementPoints                                  = 56,  // Player has over {#Achievement Pts} achievement points
    PlayerInLfgDungeon                                                  = 57,  // Player is in a LFG dungeon
    PlayerInRandomLfgDungeon                                            = 58,  // Player is in a random LFG dungeon
    PlayerInFirstRandomLfgDungeon                                       = 59,  // Player is in a first random LFG dungeon
    PlayerInRankedArenaMatch                                            = 60,  // Player is in a ranked arena match
    PlayerInGuildParty                                                  = 61,  /*NYI*/ // Player is in a guild party
    PlayerGuildReputationEqualOrGreaterThan                             = 62,  // Player has guild reputation of {#Guild Reputation} or more
    PlayerInRatedBattleground                                           = 63,  // Player is in rated battleground
    PlayerBattlegroundRatingEqualOrGreaterThan                          = 64,  // Player has a battleground rating of {#Battleground Rating} or more
    ResearchProjectRarity                                               = 65,  /*NYI*/ // Research project rarity is "{$Project Rarity}"
    ResearchProjectBranch                                               = 66,  /*NYI*/ // Research project is in branch "{ResearchBranch}"
    WorldStateExpression                                                = 67,  // World state expression "{WorldStateExpression}" is true
    DungeonDifficulty                                                   = 68,  // Dungeon difficulty is "{Difficulty}"
    PlayerLevelEqualOrGreaterThan                                       = 69,  // Player level is {#Level} or more
    TargetLevelEqualOrGreaterThan                                       = 70,  // Target level is {#Level} or more
    PlayerLevelEqualOrLessThan                                          = 71,  // Player level is {#Level} or less
    TargetLevelEqualOrLessThan                                          = 72,  // Target level is {#Level} or less
    ModifierTree                                                        = 73,  // Modifier tree "{ModifierTree}" is also true
    PlayerScenario                                                      = 74,  // Player is on scenario "{Scenario}"
    TillersReputationGreaterThan                                        = 75,  // Reputation with Tillers is above {#Reputation}
    BattlePetAchievementPointsEqualOrGreaterThan                        = 76,  // Battle pet achievement points are at least {#Achievement Pts}
    UniqueBattlePetsEqualOrGreaterThan                                  = 77,  // (Account) At least {#Pets Known} unique pets known
    BattlePetType                                                       = 78,  // Battlepet is of type "{$Battle Pet Types}"
    BattlePetHealthPercentLessThan                                      = 79,  /*NYI*/ // (Account) Battlepet's health is below {#Health Percent} percent
    GuildGroupMemberCountEqualOrGreaterThan                             = 80,  // Be in a group with at least {#Members} guild members
    BattlePetOpponentCreatureId                                         = 81,  /*NYI*/ // Battle pet opponent is "{Creature}"
    PlayerScenarioStep                                                  = 82,  // Player is on scenario step number {#Step Number}
    ChallengeModeMedal                                                  = 83,  // Challenge mode medal earned is "{#Challenge Mode Medal(OBSOLETE)}" (OBSOLETE)
    PlayerOnQuest                                                       = 84,  // Player is currently on the quest "{QuestV2}"
    ExaltedWithFaction                                                  = 85,  // Reach exalted with "{Faction}"
    EarnedAchievementOnAccount                                          = 86,  // Earned achievement "{Achievement}" on this account
    EarnedAchievementOnPlayer                                           = 87,  // Earned achievement "{Achievement}" on this player
    OrderOfTheCloudSerpentReputationGreaterThan                         = 88,  // Reputation with Order of the Cloud Serpent is above {#Reputation}
    BattlePetQuality                                                    = 89,  /*NYI*/ // Battle pet is of quality "{BattlePetBreedQuality}"
    BattlePetFightWasPVP                                                = 90,  /*NYI*/ // Battle pet fight was PVP
    BattlePetSpecies                                                    = 91,  // Battle pet is species type "{BattlePetSpecies}"
    ServerExpansionEqualOrGreaterThan                                   = 92,  // Server expansion level is "{$Expansion Level}" or higher
    PlayerHasBattlePetJournalLock                                       = 93,  // Player has battle pet journal lock
    FriendshipRepReactionIsMet                                          = 94,  // Friendship rep reaction "{FriendshipRepReaction}" is met
    ReputationWithFactionIsEqualOrGreaterThan                           = 95,  // Reputation with "{Faction}" is {#Reputation} or more
    ItemClassAndSubclass                                                = 96,  // Item is class "{ItemClass.ClassID}", subclass "{^ItemSubclass.SubclassID:ItemSubclass.ClassID = ?}"
    PlayerGender                                                        = 97,  // Player's gender is "{$Gender}"
    PlayerNativeGender                                                  = 98,  // Player's native gender is "{$Gender}"
    PlayerSkillEqualOrGreaterThan                                       = 99,  // Player skill "{SkillLine}" is level {#Skill Level} or higher
    PlayerLanguageSkillEqualOrGreaterThan                               = 100, // Player language "{Languages}" is level {#Language Level} or higher
    PlayerIsInNormalPhase                                               = 101, // Player is in normal phase
    PlayerIsInPhase                                                     = 102, // Player is in phase "{Phase}"
    PlayerIsInPhaseGroup                                                = 103, // Player is in phase group "{PhaseGroup}"
    PlayerKnowsSpell                                                    = 104, // Player knows spell "{Spell}"
    PlayerHasItemQuantity                                               = 105, // Player is carrying item "{Item}", quantity {#Quantity}
    PlayerExpansionLevelEqualOrGreaterThan                              = 106, // Player expansion level is "{$Expansion Level}" or higher
    PlayerHasAuraWithLabel                                              = 107, // Player has aura with label {Label}
    PlayersRealmWorldState                                              = 108, // Player's realm state "{WorldState}" equals {#Value}
    TimeBetween                                                         = 109, // Time is between "{/Begin Date}" and "{/End Date}"
    PlayerHasCompletedQuest                                             = 110, // Player has previously completed quest "{QuestV2}"
    PlayerIsReadyToTurnInQuest                                          = 111, // Player is ready to turn in quest "{QuestV2}"
    PlayerHasCompletedQuestObjective                                    = 112, // Player has completed Quest Objective "{QuestObjective}"
    PlayerHasExploredArea                                               = 113, // Player has explored area "{AreaTable}"
    PlayerHasItemQuantityIncludingBank                                  = 114, // Player or bank has item "{Item}", quantity {#Quantity}
    Weather                                                             = 115, // Weather is "{Weather}"
    PlayerFaction                                                       = 116, // Player faction is {$Player Faction}
    LfgStatusEqual                                                      = 117, // Looking-for-group status "{$LFG Status}" equals {#Value}
    LFgStatusEqualOrGreaterThan                                         = 118, // Looking-for-group status "{$LFG Status}" is {#Value} or more
    PlayerHasCurrencyEqualOrGreaterThan                                 = 119, // Player has currency "{CurrencyTypes}" in amount {#Amount} or more
    TargetThreatListSizeLessThan                                        = 120, // Player Killed creature with less than "{#Targets}" threat list targets
    PlayerHasTrackedCurrencyEqualOrGreaterThan                          = 121, // Player has currency "{CurrencyTypes}" tracked (per season) in amount {#Amount} or more
    PlayerMapInstanceType                                               = 122, // Player is on a map of type "{@INSTANCE_TYPE}"
    PlayerInTimeWalkerInstance                                          = 123, // Player was in a Time Walker instance
    PvpSeasonIsActive                                                   = 124, // PVP season is active
    PvpSeason                                                           = 125, // Current PVP season is {#Season}
    GarrisonTierEqualOrGreaterThan                                      = 126, // Garrison is tier {#Tier} or higher for garrison type "{GarrType}"
    GarrisonFollowersWithLevelEqualOrGreaterThan                        = 127, // At least {#Followers} followers of at least level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowersWithQualityEqualOrGreaterThan                      = 128, // At least {#Followers} followers at least quality "{@GARR_FOLLOWER_QUALITY}" for follower type "{GarrFollowerType}"
    GarrisonFollowerWithAbilityAtLevelEqualOrGreaterThan                = 129, // Follower of at least level {#Level} has ability {GarrAbility} for follower type "{GarrFollowerType}"
    GarrisonFollowerWithTraitAtLevelEqualOrGreaterThan                  = 130, // Follower of at least level {#Level} has trait {GarrAbility} for follower type "{GarrFollowerType}"
    GarrisonFollowerWithAbilityAssignedToBuilding                       = 131, // Follower with ability "{GarrAbility}" is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "{GarrType}"
    GarrisonFollowerWithTraitAssignedToBuilding                         = 132, // Follower with trait "{GarrAbility}" is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "{GarrType}"
    GarrisonFollowerWithLevelAssignedToBuilding                         = 133, // Follower at least level {#Level} is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "GarrType}"
    GarrisonBuildingWithLevelEqualOrGreaterThan                         = 134, // Building "{@GARRISON_BUILDING_TYPE}" is at least level {#Level} for garrison type "{GarrType}"
    HasBlueprintForGarrisonBuilding                                     = 135, // Has blueprint for garrison building "{GarrBuilding}" of type "{GarrType}"
    HasGarrisonBuildingSpecialization                                   = 136, // Has garrison building specialization "{GarrSpecialization}"
    AllGarrisonPlotsAreFull                                             = 137, // All garrison type "{GarrType}" plots are full
    PlayerIsInOwnGarrison                                               = 138, // Player is in their own garrison
    GarrisonShipmentOfTypeIsPending                                     = 139, /*NYI*/ // Shipment of type "{CharShipmentContainer}" is pending
    GarrisonBuildingIsUnderConstruction                                 = 140, // Garrison building "{GarrBuilding}" is under construction
    GarrisonMissionHasBeenCompleted                                     = 141, /*NYI*/ // Garrison mission "{GarrMission}" has been completed
    GarrisonBuildingLevelEqual                                          = 142, // Building {@GARRISON_BUILDING_TYPE} is exactly level {#Level} for garrison type "{GarrType}"
    GarrisonFollowerHasAbility                                          = 143, // This follower has ability "{GarrAbility}" for garrison type "{GarrType}"
    GarrisonFollowerHasTrait                                            = 144, // This follower has trait "{GarrAbility}" for garrison type "{GarrType}"
    GarrisonFollowerQualityEqual                                        = 145, // This Garrison Follower is {@GARR_FOLLOWER_QUALITY} quality
    GarrisonFollowerLevelEqual                                          = 146, // This Garrison Follower is level {#Level}
    GarrisonMissionIsRare                                               = 147, /*NYI*/ // This Garrison Mission is Rare
    GarrisonMissionIsElite                                              = 148, /*NYI*/ // This Garrison Mission is Elite
    CurrentGarrisonBuildingLevelEqual                                   = 149, // This Garrison Building is level {#Level} - building type passed as argument
    GarrisonPlotInstanceHasBuildingThatIsReadyToActivate                = 150, // Garrison plot instance "{GarrPlotInstance}" has building that is ready to activate
    BattlePetTeamWithSpeciesEqualOrGreaterThan                          = 151, // Battlepet: with at least {#Amount} "{BattlePetSpecies}"
    BattlePetTeamWithTypeEqualOrGreaterThan                             = 152, // Battlepet: with at least {#Amount} pets of type "{$Battle Pet Types}"
    PetBattleLastAbility                                                = 153, /*NYI*/ // Battlepet: last ability was "{BattlePetAbility}"
    PetBattleLastAbilityType                                            = 154, /*NYI*/ // Battlepet: last ability was of type "{$Battle Pet Types}"
    BattlePetTeamWithAliveEqualOrGreaterThan                            = 155, // Battlepet: with at least {#Alive} alive
    HasGarrisonBuildingActiveSpecialization                             = 156, // Has Garrison building active specialization "{GarrSpecialization}"
    HasGarrisonFollower                                                 = 157, // Has Garrison follower "{GarrFollower}"
    PlayerQuestObjectiveProgressEqual                                   = 158, // Player's progress on Quest Objective "{QuestObjective}" is equal to {#Value}
    PlayerQuestObjectiveProgressEqualOrGreaterThan                      = 159, // Player's progress on Quest Objective "{QuestObjective}" is at least {#Value}
    IsPTRRealm                                                          = 160, // This is a PTR Realm
    IsBetaRealm                                                         = 161, // This is a Beta Realm
    IsQARealm                                                           = 162, // This is a QA Realm
    GarrisonShipmentContainerIsFull                                     = 163, /*NYI*/ // Shipment Container "{CharShipmentContainer}" is full
    PlayerCountIsValidToStartGarrisonInvasion                           = 164, // Player count is valid to start garrison invasion
    InstancePlayerCountEqualOrLessThan                                  = 165, // Instance has at most {#Players} players
    AllGarrisonPlotsFilledWithBuildingsWithLevelEqualOrGreater          = 166, // All plots are full and at least level {#Level} for garrison type "{GarrType}"
    GarrisonMissionType                                                 = 167, /*NYI*/ // This mission is type "{GarrMissionType}"
    GarrisonFollowerItemLevelEqualOrGreaterThan                         = 168, // This follower is at least item level {#Level}
    GarrisonFollowerCountWithItemLevelEqualOrGreaterThan                = 169, // At least {#Followers} followers are at least item level {#Level} for follower type "{GarrFollowerType}"
    GarrisonTierEqual                                                   = 170, // Garrison is exactly tier {#Tier} for garrison type "{GarrType}"
    InstancePlayerCountEqual                                            = 171, // Instance has exactly {#Players} players
    CurrencyId                                                          = 172, // The currency is type "{CurrencyTypes}"
    SelectionIsPlayerCorpse                                             = 173, // Target is player corpse
    PlayerCanAcceptQuest                                                = 174, // Player is currently eligible for quest "{QuestV2}"
    GarrisonFollowerCountWithLevelEqualOrGreaterThan                    = 175, // At least {#Followers} followers exactly level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowerIsInBuilding                                        = 176, // Garrison follower "{GarrFollower}" is in building "{GarrBuilding}"
    GarrisonMissionCountLessThan                                        = 177, /*NYI*/ // Player has less than {#Available} available and {#In-Progress} in-progress missions of garrison type "{GarrType}"
    GarrisonPlotInstanceCountEqualOrGreaterThan                         = 178, // Player has at least {#Amount} instances of plot "{GarrPlot}" available
    CurrencySource                                                      = 179, /*NYI*/ // Currency source is {$Currency Source}
    PlayerIsInNotOwnGarrison                                            = 180, // Player is in another garrison (not their own)
    HasActiveGarrisonFollower                                           = 181, // Has active Garrison follower "{GarrFollower}"
    PlayerDailyRandomValueMod_X_Equals                                  = 182, /*NYI*/ // Player daily random value mod {#Mod Value} equals {#Equals Value}
    PlayerHasMount                                                      = 183, // Player has Mount "{Mount}"
    GarrisonFollowerCountWithInactiveWithItemLevelEqualOrGreaterThan    = 184, // At least {#Followers} followers (including inactive) are at least item level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowerIsOnAMission                                        = 185, // Garrison follower "{GarrFollower}" is on a mission
    GarrisonMissionCountInSetLessThan                                   = 186, /*NYI*/ // Player has less than {#Missions} available and in-progress missions of set "{GarrMissionSet}" in garrison type "{GarrType}"
    GarrisonFollowerType                                                = 187, // This Garrison Follower is of type "{GarrFollowerType}"
    PlayerUsedBoostLessThanHoursAgoRealTime                             = 188, /*NYI*/ // Player has boosted and boost occurred < {#Hours} hours ago (real time)
    PlayerUsedBoostLessThanHoursAgoGameTime                             = 189, /*NYI*/ // Player has boosted and boost occurred < {#Hours} hours ago (in-game time)
    PlayerIsMercenary                                                   = 190, // Player is currently Mercenary
    PlayerEffectiveRace                                                 = 191, /*NYI*/ // Player effective race is "{ChrRaces}"
    TargetEffectiveRace                                                 = 192, /*NYI*/ // Target effective race is "{ChrRaces}"
    HonorLevelEqualOrGreaterThan                                        = 193, // Honor level >= {#Level}
    PrestigeLevelEqualOrGreaterThan                                     = 194, // Prestige level >= {#Level}
    GarrisonMissionIsReadyToCollect                                     = 195, /*NYI*/ // Garrison mission "{GarrMission}" is ready to collect
    PlayerIsInstanceOwner                                               = 196, /*NYI*/ // Player is the instance owner (requires 'Lock Instance Owner' LFGDungeon flag)
    PlayerHasHeirloom                                                   = 197, // Player has heirloom "{Item}"
    TeamPoints                                                          = 198, /*NYI*/ // Team has {#Points} Points
    PlayerHasToy                                                        = 199, // Player has toy "{Item}"
    PlayerHasTransmog                                                   = 200, // Player has transmog "{ItemModifiedAppearance}"
    GarrisonTalentSelected                                              = 201, /*NYI*/ // Garrison has talent "{GarrTalent}" selected
    GarrisonTalentResearched                                            = 202, /*NYI*/ // Garrison has talent "{GarrTalent}" researched
    PlayerHasRestriction                                                = 203, // Player has restriction of type "{@CHARACTER_RESTRICTION_TYPE}"
    PlayerCreatedCharacterLessThanHoursAgoRealTime                      = 204, /*NYI*/ // Player has created their character < {#Hours} hours ago (real time)
    PlayerCreatedCharacterLessThanHoursAgoGameTime                      = 205, // Player has created their character < {#Hours} hours ago (in-game time)
    QuestHasQuestInfoId                                                 = 206, // Quest has Quest Info "{QuestInfo}"
    GarrisonTalentResearchInProgress                                    = 207, /*NYI*/ // Garrison is researching talent "{GarrTalent}"
    PlayerEquippedArtifactAppearanceSet                                 = 208, // Player has equipped Artifact Appearance Set "{ArtifactAppearanceSet}"
    PlayerHasCurrencyEqual                                              = 209, // Player has currency "{CurrencyTypes}" in amount {#Amount} exactly
    MinimumAverageItemHighWaterMarkForSpec                              = 210, /*NYI*/ // Minimum average item high water mark is {#Item High Water Mark} for "{$Item History Spec Match}")
    PlayerScenarioType                                                  = 211, // Player in scenario of type "{$Scenario Type}"
    PlayersAuthExpansionLevelEqualOrGreaterThan                         = 212, // Player's auth expansion level is "{$Expansion Level}" or higher
    PlayerLastWeek2v2Rating                                             = 213, /*NYI*/ // Player achieved at least a rating of {#Rating} in 2v2 last week player played
    PlayerLastWeek3v3Rating                                             = 214, /*NYI*/ // Player achieved at least a rating of {#Rating} in 3v3 last week player played
    PlayerLastWeekRBGRating                                             = 215, /*NYI*/ // Player achieved at least a rating of {#Rating} in RBG last week player played
    GroupMemberCountFromConnectedRealmEqualOrGreaterThan                = 216, // At least {#Num Players} members of the group are from your connected realms
    ArtifactTraitUnlockedCountEqualOrGreaterThan                        = 217, // At least {#Num Traits} traits have been unlocked in artifact "{Item}"
    ParagonReputationLevelEqualOrGreaterThan                            = 218, // Paragon level >= "{#Level}"
    GarrisonShipmentIsReady                                             = 219, /*NYI*/ // Shipment in container type "{CharShipmentContainer}" ready
    PlayerIsInPvpBrawl                                                  = 220, // Player is in PvP Brawl
    ParagonReputationLevelWithFactionEqualOrGreaterThan                 = 221, // Paragon level >= "{#Level}" with faction "{Faction}"
    PlayerHasItemWithBonusListFromTreeAndQuality                        = 222, // Player has an item with bonus list from tree "{ItemBonusTree}" and of quality "{$Item Quality}"
    PlayerHasEmptyInventorySlotCountEqualOrGreaterThan                  = 223, // Player has at least "{#Number of empty slots}" empty inventory slots
    PlayerHasItemInHistoryOfProgressiveEvent                            = 224, /*NYI*/ // Player has item "{Item}" in the item history of progressive event "{ProgressiveEvent}"
    PlayerHasArtifactPowerRankCountPurchasedEqualOrGreaterThan          = 225, // Player has at least {#Purchased Ranks} ranks of {ArtifactPower} on equipped artifact
    PlayerHasBoosted                                                    = 226, // Player has boosted
    PlayerHasRaceChanged                                                = 227, // Player has race changed
    PlayerHasBeenGrantedLevelsFromRaF                                   = 228, // Player has been granted levels from Recruit a Friend
    IsTournamentRealm                                                   = 229, // Is Tournament Realm
    PlayerCanAccessAlliedRaces                                          = 230, // Player can access allied races
    GroupMemberCountWithAchievementEqualOrLessThan                      = 231, // No More Than {#Group Members} With Achievement {Achievement} In Group (true if no group)
    PlayerMainhandWeaponType                                            = 232, // Player has main hand weapon of type "{$Weapon Type}"
    PlayerOffhandWeaponType                                             = 233, // Player has off-hand weapon of type "{$Weapon Type}"
    PlayerPvpTier                                                       = 234, // Player is in PvP tier {PvpTier}
    PlayerAzeriteLevelEqualOrGreaterThan                                = 235, // Players' Azerite Item is at or above level "{#Azerite Level}"
    PlayerIsOnQuestInQuestline                                          = 236, // Player is on quest in questline "{QuestLine}"
    PlayerIsQnQuestLinkedToScheduledWorldStateGroup                     = 237, // Player is on quest associated with current progressive unlock group "{ScheduledWorldStateGroup}"
    PlayerIsInRaidGroup                                                 = 238, // Player is in raid group
    PlayerPvpTierInBracketEqualOrGreaterThan                            = 239, // Player is at or above "{@PVP_TIER_ENUM}" for "{@PVP_BRACKET}"
    PlayerCanAcceptQuestInQuestline                                     = 240, // Player is eligible for quest in questline "{Questline}"
    PlayerHasCompletedQuestline                                         = 241, // Player has completed questline "{Questline}"
    PlayerHasCompletedQuestlineQuestCount                               = 242, // Player has completed "{#Quests}" quests in questline "{Questline}"
    PlayerHasCompletedPercentageOfQuestline                             = 243, // Player has completed "{#Percentage}" % of quests in questline "{Questline}"
    PlayerHasWarModeEnabled                                             = 244, // Player has WarMode Enabled (regardless of shard state)
    PlayerIsOnWarModeShard                                              = 245, // Player is on a WarMode Shard
    PlayerIsAllowedToToggleWarModeInArea                                = 246, // Player is allowed to toggle WarMode in area
    MythicPlusKeystoneLevelEqualOrGreaterThan                           = 247, /*NYI*/ // Mythic Plus Keystone Level Atleast {#Level}
    MythicPlusCompletedInTime                                           = 248, /*NYI*/ // Mythic Plus Completed In Time
    MythicPlusMapChallengeMode                                          = 249, /*NYI*/ // Mythic Plus Map Challenge Mode {MapChallengeMode}
    MythicPlusDisplaySeason                                             = 250, /*NYI*/ // Mythic Plus Display Season {#Season}
    MythicPlusMilestoneSeason                                           = 251, /*NYI*/ // Mythic Plus Milestone Season {#Season}
    PlayerVisibleRace                                                   = 252, // Player visible race is "{ChrRaces}"
    TargetVisibleRace                                                   = 253, // Target visible race is "{ChrRaces}"
    FriendshipRepReactionEqual                                          = 254, // Friendship rep reaction is exactly "{FriendshipRepReaction}"
    PlayerAuraStackCountEqual                                           = 255, // Player has exactly {#Stacks} stacks of aura "{Spell}"
    TargetAuraStackCountEqual                                           = 256, // Target has exactly {#Stacks} stacks of aura "{Spell}"
    PlayerAuraStackCountEqualOrGreaterThan                              = 257, // Player has at least {#Stacks} stacks of aura "{Spell}"
    TargetAuraStackCountEqualOrGreaterThan                              = 258, // Target has at least {#Stacks} stacks of aura "{Spell}"
    PlayerHasAzeriteEssenceRankLessThan                                 = 259, // Player has Azerite Essence {AzeriteEssence} at less than rank {#rank}
    PlayerHasAzeriteEssenceRankEqual                                    = 260, // Player has Azerite Essence {AzeriteEssence} at rank {#rank}
    PlayerHasAzeriteEssenceRankGreaterThan                              = 261, // Player has Azerite Essence {AzeriteEssence} at greater than rank {#rank}
    PlayerHasAuraWithEffectIndex                                        = 262, // Player has Aura {Spell} with Effect Index {#index} active
    PlayerLootSpecializationMatchesRole                                 = 263, // Player loot specialization matches role {@LFG_ROLE}
    PlayerIsAtMaxExpansionLevel                                         = 264, // Player is at max expansion level
    TransmogSource                                                      = 265, // Transmog Source is "{@TRANSMOG_SOURCE}"
    PlayerHasAzeriteEssenceInSlotAtRankLessThan                         = 266, // Player has Azerite Essence in slot {@AZERITE_ESSENCE_SLOT} at less than rank {#rank}
    PlayerHasAzeriteEssenceInSlotAtRankGreaterThan                      = 267, // Player has Azerite Essence in slot {@AZERITE_ESSENCE_SLOT} at greater than rank {#rank}
    PlayerLevelWithinContentTuning                                      = 268, // Player has level within Content Tuning {ContentTuning}
    TargetLevelWithinContentTuning                                      = 269, // Target has level within Content Tuning {ContentTuning}
    PlayerIsScenarioInitiator                                           = 270, /*NYI*/ // Player is Scenario Initiator
    PlayerHasCompletedQuestOrIsOnQuest                                  = 271, // Player is currently on or previously completed quest "{QuestV2}"
    PlayerLevelWithinOrAboveContentTuning                               = 272, // Player has level within or above Content Tuning {ContentTuning}
    TargetLevelWithinOrAboveContentTuning                               = 273, // Target has level within or above Content Tuning {ContentTuning}
    PlayerLevelWithinOrAboveLevelRange                                  = 274, /*NYI*/ // Player has level within or above Level Range {LevelRange}
    TargetLevelWithinOrAboveLevelRange                                  = 275, /*NYI*/ // Target has level within or above Level Range {LevelRange}
    MaxJailersTowerLevelEqualOrGreaterThan                              = 276, // Max Jailers Tower Level Atleast {#Level}
    GroupedWithRaFRecruit                                               = 277, // Grouped With Recruit
    GroupedWithRaFRecruiter                                             = 278, // Grouped with Recruiter
    PlayerSpecialization                                                = 279, // Specialization is "{ChrSpecialization}"
    PlayerMapOrCosmeticChildMap                                         = 280, // Player is on map or cosmetic child map "{Map}"
    PlayerCanAccessShadowlandsPrepurchaseContent                        = 281, // Player can access Shadowlands (9.0) prepurchase content
    PlayerHasEntitlement                                                = 282, /*NYI*/ // Player has entitlement "{BattlePayDeliverable}"
    PlayerIsInPartySyncGroup                                            = 283, /*NYI*/ // Player is in party sync group
    QuestHasPartySyncRewards                                            = 284, /*NYI*/ // Quest is eligible for party sync rewards
    HonorGainSource                                                     = 285, /*NYI*/ // Player gained honor from source {@SPECIAL_MISC_HONOR_GAIN_SOURCE}
    JailersTowerActiveFloorIndexEqualOrGreaterThan                      = 286, /*NYI*/ // Active Floor Index Atleast {#Level}
    JailersTowerActiveFloorDifficultyEqualOrGreaterThan                 = 287, /*NYI*/ // Active Floor Difficulty Atleast {#Level}
    PlayerCovenant                                                      = 288, // Player is member of covenant "{Covenant}"
    HasTimeEventPassed                                                  = 289, // Has time event "{TimeEvent}" passed
    GarrisonHasPermanentTalent                                          = 290, /*NYI*/ // Garrison has permanent talent "{GarrTalent}"
    HasActiveSoulbind                                                   = 291, // Has Active Soulbind "{Soulbind}"
    HasMemorizedSpell                                                   = 292, /*NYI*/ // Has memorized spell "{Spell}"
    PlayerHasAPACSubscriptionReward_2020                                = 293, // Player has APAC Subscription Reward 2020
    PlayerHasTBCCDEWarpStalker_Mount                                    = 294, // Player has TBCC:DE Warp Stalker Mount
    PlayerHasTBCCDEDarkPortal_Toy                                       = 295, // Player has TBCC:DE Dark Portal Toy
    PlayerHasTBCCDEPathOfIllidan_Toy                                    = 296, // Player has TBCC:DE Path of Illidan Toy
    PlayerHasImpInABallToySubscriptionReward                            = 297, // Player has Imp in a Ball Toy Subscription Reward
    PlayerIsInAreaGroup                                                 = 298, // Player is in area group "{AreaGroup}"
    TargetIsInAreaGroup                                                 = 299, // Target is in area group "{AreaGroup}"
    PlayerIsInChromieTime                                               = 300, // Player has selected Chromie Time ID "{UiChromieTimeExpansionInfo}"
    PlayerIsInAnyChromieTime                                            = 301, // Player has selected ANY Chromie Time ID
    ItemIsAzeriteArmor                                                  = 302, // Item is Azerite Armor
    PlayerHasRuneforgePower                                             = 303, // Player Has Runeforge Power "{RuneforgeLegendaryAbility}"
    PlayerInChromieTimeForScaling                                       = 304, // Player is Chromie Time for Scaling
    IsRaFRecruit                                                        = 305, // Is RAF recruit
    AllPlayersInGroupHaveAchievement                                    = 306, // All Players In Group Have Achievement "{Achievement}"
    PlayerHasSoulbindConduitRankEqualOrGreaterThan                      = 307, /*NYI*/ // Player has Conduit "{SoulbindConduit}" at Rank {#Rank} or Higher
    PlayerSpellShapeshiftFormCreatureDisplayInfoSelection               = 308, // Player has chosen {CreatureDisplayInfo} for shapeshift form {SpellShapeshiftForm}
    PlayerSoulbindConduitCountAtRankEqualOrGreaterThan                  = 309, /*NYI*/ // Player has at least {#Level} Conduits at Rank {#Rank} or higher.
    PlayerIsRestrictedAccount                                           = 310, // Player is a Restricted Account
    PlayerIsFlying                                                      = 311, // Player is flying
    PlayerScenarioIsLastStep                                            = 312, // Player is on the last step of a Scenario
    PlayerHasWeeklyRewardsAvailable                                     = 313, // Player has weekly rewards available
    TargetCovenant                                                      = 314, // Target is member of covenant "{Covenant}"
    PlayerHasTBCCollectorsEdition                                       = 315, // Player has TBC Collector's Edition
    PlayerHasWrathCollectorsEdition                                     = 316, // Player has Wrath Collector's Edition
    GarrisonTalentResearchedAndAtRankEqualOrGreaterThan                 = 317, /*NYI*/ // Garrison has talent "{GarrTalent}" researched and active at or above {#Rank}
    CurrencySpentOnGarrisonTalentResearchEqualOrGreaterThan             = 318, /*NYI*/ // Currency {CurrencyTypes} Spent on Garrison Talent Research in Tree {GarrTalentTree} is greater than or equal to {#Quantity}
    RenownCatchupActive                                                 = 319, /*NYI*/ // Renown Catchup Active
    RapidRenownCatchupActive                                            = 320, /*NYI*/ // Rapid Renown Catchup Active
    PlayerMythicPlusRatingEqualOrGreaterThan                            = 321, /*NYI*/ // Player has Mythic+ Rating of at least "{#DungeonScore}"
    PlayerMythicPlusRunCountInCurrentExpansionEqualOrGreaterThan        = 322, /*NYI*/ // Player has completed at least "{#MythicKeystoneRuns}" Mythic+ runs in current expansion
    PlayerHasCustomizationChoice                                        = 323, // (Mainline) Player has Customization Choice "{ChrCustomizationChoice}"
    PlayerBestWeeklyWinPvpTier                                          = 324, // (Mainline) Player has best weekly win in PVP tier {PvpTier}
    PlayerBestWeeklyWinPvpTierInBracketEqualOrGreaterThan               = 325, // (Mainline) Player has best weekly win at or above "{@PVP_TIER_ENUM}" for "{@PVP_BRACKET}"
    PlayerHasVanillaCollectorsEdition                                   = 326, // Player has Vanilla Collector's Edition
    PlayerHasItemWithKeystoneLevelModifierEqualOrGreaterThan            = 327,
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

enum class SpellEffectAttributes
{
    None                                    = 0,
    UnaffectedByInvulnerability             = 0x000001, // not cancelled by immunities
    NoScaleWithStack                        = 0x000040,
    StackAuraAmountOnRecast                 = 0x008000, // refreshing periodic auras with this attribute will add remaining damage to new aura
    AllowAnyExplicitTarget                  = 0x100000,
    IgnoreDuringCooldownTimeRateCalculation = 0x800000
};

DEFINE_ENUM_FLAG(SpellEffectAttributes);

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

enum class SpellShapeshiftFormFlags : int32
{
    Stance                      = 0x00000001,
    NotToggleable               = 0x00000002,   // player cannot cancel the aura giving this shapeshift
    PersistOnDeath              = 0x00000004,
    CanInteractNPC              = 0x00000008,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag must be present to allow NPC interaction
    DontUseWeapon               = 0x00000010,

    CanUseEquippedItems         = 0x00000040,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows equipping items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    CanUseItems                 = 0x00000080,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows using items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    DontAutoUnshift             = 0x00000100,   // clientside
    ConsideredDead              = 0x00000200,
    CanOnlyCastShapeshiftSpells = 0x00000400,   // prevents using spells that don't have any shapeshift requirement
    StanceCancelsAtFlightmaster = 0x00000800,
    NoEmoteSounds               = 0x00001000,
    NoTriggerTeleport           = 0x00002000,
    CannotChangeEquippedItems   = 0x00004000,

    CannotUseGameObjects        = 0x00010000
};

DEFINE_ENUM_FLAG(SpellShapeshiftFormFlags);

#define TaxiMaskSize 338
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
    SUMMON_PROP_FLAG_PERSONAL_SPAWN  = 0x00000010,          // Only Visible to Summoner
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
    SUMMON_PROP_FLAG_PERSONAL_GROUP_SPAWN = 0x00010000,     // Only Visible to Summoner's Group
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

enum class UiMapFlag : int32
{
    None                    = 0,
    NoHighlight             = 0x00000001,
    ShowOverlays            = 0x00000002,
    ShowTaxiNodes           = 0x00000004,
    GarrisonMap             = 0x00000008,
    FallbackToParentMap     = 0x00000010,
    NoHighlightTexture      = 0x00000020,
    ShowTaskObjectives      = 0x00000040,
    NoWorldPositions        = 0x00000080,
    HideArchaeologyDigs     = 0x00000100,
    Deprecated              = 0x00000200,
    HideIcons               = 0x00000400,
    HideVignettes           = 0x00000800,
    ForceAllOverlayExplored = 0x00001000,
    FlightMapShowZoomOut    = 0x00002000,
    FlightMapAutoZoom       = 0x00004000,
    ForceOnNavbar           = 0x00008000
};

DEFINE_ENUM_FLAG(UiMapFlag);

enum UiMapSystem : int8
{
    UI_MAP_SYSTEM_WORLD     = 0,
    UI_MAP_SYSTEM_TAXI      = 1,
    UI_MAP_SYSTEM_ADVENTURE = 2,
    UI_MAP_SYSTEM_MINIMAP   = 3,
    MAX_UI_MAP_SYSTEM
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
    VEHICLE_SEAT_FLAG_B_PASSENGER_MIRRORS_ANIMS  = 0x00010000,           // Passenger forced to repeat all vehicle animations
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
