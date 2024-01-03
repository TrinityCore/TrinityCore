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

#ifndef TRINITYCORE_QUEST_H
#define TRINITYCORE_QUEST_H

#include "Common.h"
#include "DatabaseEnvFwd.h"
#include "EnumFlag.h"
#include "LootItemType.h"
#include "Optional.h"
#include "RaceMask.h"
#include "SharedDefines.h"
#include "WorldPacket.h"
#include <bitset>
#include <vector>

class Player;
enum Difficulty : uint8;

namespace WorldPackets
{
    namespace Quest
    {
        struct QuestRewards;
    }
}

#define MAX_QUEST_LOG_SIZE 35

#define QUEST_ITEM_DROP_COUNT 4
#define QUEST_REWARD_CHOICES_COUNT 6
#define QUEST_REWARD_ITEM_COUNT 4
#define QUEST_DEPLINK_COUNT 10
#define QUEST_REWARD_REPUTATIONS_COUNT 5
#define QUEST_EMOTE_COUNT 4
#define QUEST_REWARD_CURRENCY_COUNT 4
#define QUEST_REWARD_DISPLAY_SPELL_COUNT 3

// EnumUtils: DESCRIBE THIS
enum QuestFailedReason : uint32
{
    QUEST_ERR_NONE                              = 0,
    QUEST_ERR_FAILED_LOW_LEVEL                  = 1,        // DESCRIPTION "You are not high enough level for that quest.""
    QUEST_ERR_FAILED_WRONG_RACE                 = 6,        // DESCRIPTION "That quest is not available to your race."
    QUEST_ERR_ALREADY_DONE                      = 7,        // DESCRIPTION "You have completed that daily quest today."
    QUEST_ERR_ONLY_ONE_TIMED                    = 12,       // DESCRIPTION "You can only be on one timed quest at a time"
    QUEST_ERR_ALREADY_ON1                       = 13,       // DESCRIPTION "You are already on that quest"
    QUEST_ERR_FAILED_EXPANSION                  = 16,       // DESCRIPTION "This quest requires an expansion enabled account."
    QUEST_ERR_ALREADY_ON2                       = 18,       // DESCRIPTION "You are already on that quest"
    QUEST_ERR_FAILED_MISSING_ITEMS              = 21,       // DESCRIPTION "You don't have the required items with you.  Check storage."
    QUEST_ERR_FAILED_NOT_ENOUGH_MONEY           = 23,       // DESCRIPTION "You don't have enough money for that quest"
    QUEST_ERR_FAILED_CAIS                       = 24,       // DESCRIPTION "You cannot complete quests once you have reached tired time"
    QUEST_ERR_ALREADY_DONE_DAILY                = 26,       // DESCRIPTION "You have completed that daily quest today."
    QUEST_ERR_FAILED_SPELL                      = 28,       // DESCRIPTION "You haven't learned the required spell."
    QUEST_ERR_HAS_IN_PROGRESS                   = 30        // DESCRIPTION "Progress Bar objective not completed"
};

// EnumUtils: DESCRIBE THIS
enum class QuestPushReason : uint8
{
    Success                         = 0,    // "Sharing quest with %s..."
    Invalid                         = 1,    // "%s is not eligible for that quest"
    InvalidToRecipient              = 2,    // "%s's attempt to share quest "%s" failed. You are not eligible for that quest."
    Accepted                        = 3,    // "%s has accepted your quest"
    Declined                        = 4,    // "%s has declined your quest"
    Busy                            = 5,    // "%s is busy"
    Dead                            = 6,    // "%s is dead."
    DeadToRecipient                 = 7,    // "%s's attempt to share quest "%s" failed. You are dead."
    LogFull                         = 8,    // "%s's quest log is full"
    LogFullToRecipient              = 9,    // "%s's attempt to share quest "%s" failed. Your quest log is full."
    OnQuest                         = 10,   // "%s is already on that quest"
    OnQuestToRecipient              = 11,   // "%s's attempt to share quest "%s" failed. You are already on that quest."
    AlreadyDone                     = 12,   // "%s has completed that quest"
    AlreadyDoneToRecipient          = 13,   // "%s's attempt to share quest "%s" failed. You have completed that quest."
    NotDaily                        = 14,   // "That quest cannot be shared today"
    TimerExpired                    = 15,   // "Quest sharing timer has expired"
    NotInParty                      = 16,   // "You are not in a party"
    DifferentServerDaily            = 17,   // "%s is not eligible for that quest today"
    DifferentServerDailyToRecipient = 18,   // "%s's attempt to share quest "%s" failed. You are not eligible for that quest today."
    NotAllowed                      = 19,   // "That quest cannot be shared"
    Prerequisite                    = 20,   // "%s hasn't completed all of the prerequisite quests required for that quest."
    PrerequisiteToRecipient         = 21,   // "%s's attempt to share quest "%s" failed. You must complete all of the prerequisite quests first."
    LowLevel                        = 22,   // "%s is too low level for that quest."
    LowLevelToRecipient             = 23,   // "%s's attempt to share quest "%s" failed. You are too low level for that quest."
    HighLevel                       = 24,   // "%s is too high level for that quest."
    HighLevelToRecipient            = 25,   // "%s's attempt to share quest "%s" failed. You are too high level for that quest."
    Class                           = 26,   // "%s is the wrong class for that quest."
    ClassToRecipient                = 27,   // "%s's attempt to share quest "%s" failed. You are the wrong class for that quest."
    Race                            = 28,   // "%s is the wrong race for that quest."
    RaceToRecipient                 = 29,   // "%s's attempt to share quest "%s" failed. You are the wrong race for that quest."
    LowFaction                      = 30,   // "%s's reputation is too low for that quest."
    LowFactionToRecipient           = 31,   // "%s's attempt to share quest "%s" failed. Your reputation is too low for that quest."
    Expansion                       = 32,   // "%s doesn't own the required expansion for that quest."
    ExpansionToRecipient            = 33,   // "%s's attempt to share quest "%s" failed. You do not own the required expansion for that quest."
    NotGarrisonOwner                = 34,   // "%s must own a garrison to accept that quest."
    NotGarrisonOwnerToRecipient     = 35,   // "%s's attempt to share quest "%s" failed. You must own a garrison to accept that quest."
    WrongCovenant                   = 36,   // "%s is in the wrong covenant for that quest."
    WrongCovenantToRecipient        = 37,   // "%s's attempt to share quest "%s" failed. You are in the wrong covenant for that quest."
    NewPlayerExperience             = 38,   // "%s must complete Exile's Reach to accept that quest."
    NewPlayerExperienceToRecipient  = 39,   // "%s's attempt to share quest "%s" failed. You must complete Exile's Reach to accept that quest."
    WrongFaction                    = 40,   // "%s is the wrong faction for that quest."
    WrongFactionToRecipient         = 41    // "%s's attempt to share quest "%s" failed. You are the wrong faction for that quest."
};

enum QuestTradeSkill
{
    QUEST_TRSKILL_NONE           = 0,
    QUEST_TRSKILL_ALCHEMY        = 1,
    QUEST_TRSKILL_BLACKSMITHING  = 2,
    QUEST_TRSKILL_COOKING        = 3,
    QUEST_TRSKILL_ENCHANTING     = 4,
    QUEST_TRSKILL_ENGINEERING    = 5,
    QUEST_TRSKILL_FIRSTAID       = 6,
    QUEST_TRSKILL_HERBALISM      = 7,
    QUEST_TRSKILL_LEATHERWORKING = 8,
    QUEST_TRSKILL_POISONS        = 9,
    QUEST_TRSKILL_TAILORING      = 10,
    QUEST_TRSKILL_MINING         = 11,
    QUEST_TRSKILL_FISHING        = 12,
    QUEST_TRSKILL_SKINNING       = 13,
    QUEST_TRSKILL_JEWELCRAFTING  = 14
};

enum QuestStatus : uint8
{
    QUEST_STATUS_NONE           = 0,
    QUEST_STATUS_COMPLETE       = 1,
    //QUEST_STATUS_UNAVAILABLE    = 2,
    QUEST_STATUS_INCOMPLETE     = 3,
    //QUEST_STATUS_AVAILABLE      = 4,
    QUEST_STATUS_FAILED         = 5,
    QUEST_STATUS_REWARDED       = 6,        // Not used in DB
    MAX_QUEST_STATUS
};

enum class QuestGiverStatus : uint64
{
    None                                = 0x000000000,
    Future                              = 0x000000002,
    Trivial                             = 0x000000004,
    TrivialRepeatableTurnin             = 0x000000008,
    TrivialDailyQuest                   = 0x000000010,
    Reward                              = 0x000000020,
    JourneyReward                       = 0x000000040,
    CovenantCallingReward               = 0x000000080,
    RepeatableTurnin                    = 0x000000100,
    DailyQuest                          = 0x000000200,
    Quest                               = 0x000000400,
    RewardCompleteNoPOI                 = 0x000000800,
    RewardCompletePOI                   = 0x000001000,
    LegendaryQuest                      = 0x000002000,
    LegendaryRewardCompleteNoPOI        = 0x000004000,
    LegendaryRewardCompletePOI          = 0x000008000,
    JourneyQuest                        = 0x000010000,
    JourneyRewardCompleteNoPOI          = 0x000020000,
    JourneyRewardCompletePOI            = 0x000040000,
    CovenantCallingQuest                = 0x000080000,
    CovenantCallingRewardCompleteNoPOI  = 0x000100000,
    CovenantCallingRewardCompletePOI    = 0x000200000,
    TrivialLegendaryQuest               = 0x000400000,
    FutureLegendaryQuest                = 0x000800000,
    LegendaryReward                     = 0x001000000,
    ImportantQuest                      = 0x002000000,
    ImportantReward                     = 0x004000000,
    TrivialImportantQuest               = 0x008000000,
    FutureImportantQuest                = 0x010000000,
    ImportantQuestRewardCompleteNoPOI   = 0x020000000,
    ImportantQuestRewardCompletePOI     = 0x040000000,
    TrivialJourneyQuest                 = 0x080000000,
    FutureJourneyQuest                  = 0x100000000,
};

DEFINE_ENUM_FLAG(QuestGiverStatus);

enum QuestFlags : uint32
{
    QUEST_FLAGS_NONE                        = 0x00000000,
    QUEST_FLAGS_COMPLETION_NO_DEATH         = 0x00000001,
    QUEST_FLAGS_COMPLETION_EVENT            = 0x00000002,
    QUEST_FLAGS_COMPLETION_AREA_TRIGGER     = 0x00000004,
    QUEST_FLAGS_SHARABLE                    = 0x00000008,   // Can be shared: Player::CanShareQuest()
    QUEST_FLAGS_HAS_CONDITION               = 0x00000010,   // Not used currently
    QUEST_FLAGS_HIDE_REWARD_POI             = 0x00000020,   // Hides questgiver turn-in minimap icon
    QUEST_FLAGS_RAID_GROUP_OK               = 0x00000040,   // Can be completed while in raid
    QUEST_FLAGS_WAR_MODE_REWARDS_OPT_IN     = 0x00000080,   // Not used currently
    QUEST_FLAGS_NO_MONEY_FOR_XP             = 0x00000100,   // Experience is not converted to gold at max level
    QUEST_FLAGS_HIDE_REWARD                 = 0x00000200,   // Items and money rewarded only sent in SMSG_QUESTGIVER_OFFER_REWARD (not in SMSG_QUEST_GIVER_QUEST_DETAILS or in client quest log(SMSG_QUEST_QUERY_RESPONSE))
    QUEST_FLAGS_TRACKING_EVENT              = 0x00000400,   // These quests are automatically rewarded on quest complete and they will never appear in quest log client side.
    QUEST_FLAGS_DEPRECATE_REPUTATION        = 0x00000800,   // Not used currently
    QUEST_FLAGS_DAILY                       = 0x00001000,   // Used to know quest is Daily one
    QUEST_FLAGS_FLAGS_PVP                   = 0x00002000,   // Having this quest in log forces PvP flag
    QUEST_FLAGS_DEPRECATED                  = 0x00004000,   // Used on quests that are not generally available
    QUEST_FLAGS_WEEKLY                      = 0x00008000,
    QUEST_FLAGS_AUTO_COMPLETE               = 0x00010000,   // Quests with this flag player submit automatically by special button in player gui
    QUEST_FLAGS_DISPLAY_ITEM_IN_TRACKER     = 0x00020000,   // Displays usable item in quest tracker
    QUEST_FLAGS_DISABLE_COMPLETION_TEXT     = 0x00040000,   // use Objective text as Complete text
    QUEST_FLAGS_AUTO_ACCEPT                 = 0x00080000,   // The client recognizes this flag as auto-accept.
    QUEST_FLAGS_PLAYER_CAST_ACCEPT          = 0x00100000,   // Accept Spell Player Cast
    QUEST_FLAGS_PLAYER_CAST_COMPLETE        = 0x00200000,   // Complete Spell Player Cast
    QUEST_FLAGS_UPDATE_PHASESHIFT           = 0x00400000,   // Update Phase Shift
    QUEST_FLAGS_SOR_WHITELIST               = 0x00800000,   // Scroll of Resurrection Whitelist
    QUEST_FLAGS_LAUNCH_GOSSIP_COMPLETE      = 0x01000000,   // Gossip on Quest Completion - Force Gossip
    QUEST_FLAGS_REMOVE_SURPLUS_ITEMS        = 0x02000000,   // Remove all items from inventory that have the same id as the objective, not just the amount required by quest
    QUEST_FLAGS_WELL_KNOWN                  = 0x04000000,   // Well-Known
    QUEST_FLAGS_PORTRAIT_IN_QUEST_LOG       = 0x08000000,   // Portrait from Log
    QUEST_FLAGS_SHOW_ITEM_WHEN_COMPLETED    = 0x10000000,   // Show Item When Completed
    QUEST_FLAGS_LAUNCH_GOSSIP_ACCEPT        = 0x20000000,   // Gossip on Quest Accept - Force Gossip
    QUEST_FLAGS_ITEMS_GLOW_WHEN_COMPLETE    = 0x40000000,   // Items Glow When Done
    QUEST_FLAGS_FAIL_ON_LOGOUT              = 0x80000000    // Fail on Logout
};

// last checked in 19802
enum QuestFlagsEx : uint32
{
    QUEST_FLAGS_EX_NONE                                     = 0x00000000,
    QUEST_FLAGS_EX_NO_ITEM_REMOVAL                          = 0x00000001,   // Keep Additional Items
    QUEST_FLAGS_EX_SUPPRESS_GOSSIP_COMPLETE                 = 0x00000002,   // Gossip on Quest Completion - Suppress Gossip
    QUEST_FLAGS_EX_SUPPRESS_GOSSIP_ACCEPT                   = 0x00000004,   // Gossip on Quest Accept - Suppress Gossip
    QUEST_FLAGS_EX_DENY_PLAYER_QUESTGIVER                   = 0x00000008,   // Disallow Player as Questgiver (advanced)
    QUEST_FLAGS_EX_DISPLAY_CLASS_CHOICE_REWARDS             = 0x00000010,   // Choice Reward Filter - Matches Class
    QUEST_FLAGS_EX_DISPLAY_SPEC_CHOICE_REWARDS              = 0x00000020,   // Choice Reward Filter - Matches Spec
    QUEST_FLAGS_EX_REMOVE_ON_PERIODIC_RESET                 = 0x00000040,   // Remove from Log on Periodic Reset
    QUEST_FLAGS_EX_ACCOUNT                                  = 0x00000080,   // Account-Level Quest
    QUEST_FLAGS_EX_LEGENDARY                                = 0x00000100,   // Legendary Quest
    QUEST_FLAGS_EX_NO_GUILD_XP                              = 0x00000200,   // No Guild XP
    QUEST_FLAGS_EX_RESET_CACHE_ON_ACCEPT                    = 0x00000400,   // Reset Cache on Accept (internal)
    QUEST_FLAGS_EX_NO_ABANDON_ONCE_BEGUN                    = 0x00000800,   // No Abandon Once Any Objective Complete
    QUEST_FLAGS_EX_RECAST_ACCEPT_SPELL_ON_LOGIN             = 0x00001000,   // Recast accept spell on login
    QUEST_FLAGS_EX_UPDATE_ZONE_AURAS                        = 0x00002000,   // Update Zone Auras
    QUEST_FLAGS_EX_NO_CREDIT_FOR_PROXY                      = 0x00004000,   // No Credit for Proxy Creatures
    QUEST_FLAGS_EX_DISPLAY_AS_DAILY                         = 0x00008000,   // Display As Daily Quest
    QUEST_FLAGS_EX_DISPLAY_QUEST_LINE                       = 0x00010000,
    QUEST_FLAGS_EX_INTERNAL_BUILDS_ONLY                     = 0x00020000,   // Quest for Internal Builds ONLY
    QUEST_FLAGS_EX_SUPPRESS_SPELL_LEARN_TEXT                = 0x00040000,   // Suppress spell learn text line (for followers)
    QUEST_FLAGS_EX_DISPLAY_AS_OBJECTIVE                     = 0x00080000,   // Display Header as Objective for Tasks
    QUEST_FLAGS_EX_ALLOW_ALL_IN_GARRISON                    = 0x00100000,   // Garrison non-owners allowed
    QUEST_FLAGS_EX_REMOVE_ON_WEEKLY_RESET                   = 0x00200000,   // Remove quest on weekly reset
    QUEST_FLAGS_EX_SUPPRESS_GREETINGS_ON_ACCEPT             = 0x00400000,   // Suppress farewell audio after quest accept
    QUEST_FLAGS_EX_REWARDS_IGNORE_CAPS                      = 0x00800000,   // Rewards bypass weekly caps and Season Total
    QUEST_FLAGS_EX_IS_WORLD_QUEST                           = 0x01000000,   // Is a World Quest
    QUEST_FLAGS_EX_NOT_IGNORABLE                            = 0x02000000,   // Not Ignorable
    QUEST_FLAGS_EX_AUTO_PUSH                                = 0x04000000,   // Auto Push
    QUEST_FLAGS_EX_NO_SPELL_COMPLETE_EFFECTS                = 0x08000000,   // No Complete Quest Spell Effect
    QUEST_FLAGS_EX_DO_NOT_TOAST_HONOR_REWARD                = 0x10000000,   // Do Not Toast Honor Reward
    QUEST_FLAGS_EX_KEEP_REPEATABLE_QUEST_ON_FACTION_CHANGE  = 0x20000000,   // Keep repeatable quest on faction change
    QUEST_FLAGS_EX_KEEP_PROGRESS_ON_FACTION_CHANGE          = 0x40000000,   // Keep quest progress on faction change
    QUEST_FLAGS_EX_PUSH_TEAM_QUEST_USING_MAP_CONTROLLER     = 0x80000000
};

enum QuestFlagsEx2 : uint32
{
    QUEST_FLAGS_EX2_RESET_ON_GAME_MILESTONE             = 0x00000001,
    QUEST_FLAGS_EX2_WAR_MODE_REWARDS_OPT_OUT            = 0x00000002,
    QUEST_FLAGS_EX2_AWARD_HIGHEST_PROFESSION            = 0x00000004,
    QUEST_FLAGS_EX2_NOT_REPLAYABLE                      = 0x00000008,
    QUEST_FLAGS_EX2_NO_REPLAY_REWARDS                   = 0x00000010,
    QUEST_FLAGS_EX2_DISABLE_WAYPOINT_PATHING            = 0x00000020,
    QUEST_FLAGS_EX2_RESET_ON_MYTHIC_PLUS_SEASON         = 0x00000040,
    QUEST_FLAGS_EX2_RESET_ON_PVP_SEASON                 = 0x00000080,
    QUEST_FLAGS_EX2_ENABLE_OVERRIDE_SORT_ORDER          = 0x00000100,
    QUEST_FLAGS_EX2_FORCE_STARTING_LOC_ON_ZONE_MAP      = 0x00000200,
    QUEST_FLAGS_EX2_BONUS_LOOT_NEVER                    = 0x00000400,
    QUEST_FLAGS_EX2_BONUS_LOOT_ALWAYS                   = 0x00000800,
    QUEST_FLAGS_EX2_HIDE_TASK_ON_MAIN_MAP               = 0x00001000,
    QUEST_FLAGS_EX2_HIDE_TASK_IN_TRACKER                = 0x00002000,
    QUEST_FLAGS_EX2_SKIP_DISABLED_CHECK                 = 0x00004000,
    QUEST_FLAGS_EX2_ENFORCE_MAXIMUM_QUEST_LEVEL         = 0x00008000,
    QUEST_FLAGS_EX2_CONTENT_ALERT                       = 0x00010000,
    QUEST_FLAGS_EX2_DISPLAY_TIME_REMAINING              = 0x00020000,
    QUEST_FLAGS_EX2_CLEAR_TASK_PROGRESS_WHEN_ABANDONED  = 0x00040000,
    QUEST_FLAGS_EX2_SUPPRESS_GREETINGS_ON_COMPLETE      = 0x00080000,
    QUEST_FLAGS_EX2_HIDE_REQUIRED_ITEMS_ON_TURN_IN      = 0x00100000,
    QUEST_FLAGS_EX2_IGNORE_SOULBOUND_ITEMS              = 0x00200000,
    QUEST_FLAGS_EX2_DONT_DEFER_START_EFFECTS            = 0x00400000,
    QUEST_FLAGS_EX2_HIDE_REQUIRED_ITEMS_PRE_TURN_IN     = 0x00800000,
};

enum QuestSpecialFlags
{
    QUEST_SPECIAL_FLAGS_NONE                 = 0x000,
    // Trinity flags for set SpecialFlags in DB if required but used only at server
    QUEST_SPECIAL_FLAGS_REPEATABLE           = 0x001,   // Set by 1 in SpecialFlags from DB
    QUEST_SPECIAL_FLAGS_AUTO_PUSH_TO_PARTY   = 0x002,   // Set by 2 in SpecialFlags from DB will make quest be pushed to entire party when one member accepts it
    QUEST_SPECIAL_FLAGS_AUTO_ACCEPT          = 0x004,   // Set by 4 in SpecialFlags in DB if the quest is to be auto-accepted.
    QUEST_SPECIAL_FLAGS_DF_QUEST             = 0x008,   // Set by 8 in SpecialFlags in DB if the quest is used by Dungeon Finder.
    QUEST_SPECIAL_FLAGS_MONTHLY              = 0x010,   // Set by 16 in SpecialFlags in DB if the quest is reset at the begining of the month
    // room for more custom flags

    QUEST_SPECIAL_FLAGS_DB_ALLOWED = QUEST_SPECIAL_FLAGS_REPEATABLE | QUEST_SPECIAL_FLAGS_AUTO_PUSH_TO_PARTY | QUEST_SPECIAL_FLAGS_AUTO_ACCEPT | QUEST_SPECIAL_FLAGS_DF_QUEST | QUEST_SPECIAL_FLAGS_MONTHLY,

    QUEST_SPECIAL_FLAGS_SEQUENCED_OBJECTIVES = 0x020,    // Internal flag computed only
};

enum class QuestTagType
{
    Tag,
    Profession,
    Normal,
    Pvp,
    PetBattle,
    Bounty,
    Dungeon,
    Invasion,
    Raid,
    Contribution,
    RatedRreward,
    InvasionWrapper,
    FactionAssault,
    Islands,
    Threat,
    CovenantCalling
};

enum QuestObjectiveType
{
    QUEST_OBJECTIVE_MONSTER                 = 0,
    QUEST_OBJECTIVE_ITEM                    = 1,
    QUEST_OBJECTIVE_GAMEOBJECT              = 2,
    QUEST_OBJECTIVE_TALKTO                  = 3,
    QUEST_OBJECTIVE_CURRENCY                = 4,
    QUEST_OBJECTIVE_LEARNSPELL              = 5,
    QUEST_OBJECTIVE_MIN_REPUTATION          = 6,
    QUEST_OBJECTIVE_MAX_REPUTATION          = 7,
    QUEST_OBJECTIVE_MONEY                   = 8,
    QUEST_OBJECTIVE_PLAYERKILLS             = 9,
    QUEST_OBJECTIVE_AREATRIGGER             = 10,
    QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC  = 11,
    QUEST_OBJECTIVE_DEFEATBATTLEPET         = 12,
    QUEST_OBJECTIVE_WINPVPPETBATTLES        = 13,
    QUEST_OBJECTIVE_CRITERIA_TREE           = 14,
    QUEST_OBJECTIVE_PROGRESS_BAR            = 15,
    QUEST_OBJECTIVE_HAVE_CURRENCY           = 16,   // requires the player to have X currency when turning in but does not consume it
    QUEST_OBJECTIVE_OBTAIN_CURRENCY         = 17,   // requires the player to gain X currency after starting the quest but not required to keep it until the end (does not consume)
    QUEST_OBJECTIVE_INCREASE_REPUTATION     = 18,   // requires the player to gain X reputation with a faction
    QUEST_OBJECTIVE_AREA_TRIGGER_ENTER      = 19,
    QUEST_OBJECTIVE_AREA_TRIGGER_EXIT       = 20,

    MAX_QUEST_OBJECTIVE_TYPE
};

enum QuestObjectiveFlags
{
    QUEST_OBJECTIVE_FLAG_TRACKED_ON_MINIMAP                 = 0x0001, // client displays large yellow blob on minimap for creature/gameobject
    QUEST_OBJECTIVE_FLAG_SEQUENCED                          = 0x0002, // client will not see the objective displayed until all previous objectives are completed
    QUEST_OBJECTIVE_FLAG_OPTIONAL                           = 0x0004, // not required to complete the quest
    QUEST_OBJECTIVE_FLAG_HIDDEN                             = 0x0008, // never displayed in quest log
    QUEST_OBJECTIVE_FLAG_HIDE_CREDIT_MSG                    = 0x0010, // skip showing item objective progress
    QUEST_OBJECTIVE_FLAG_PRESERVE_QUEST_ITEMS               = 0x0020,
    QUEST_OBJECTIVE_FLAG_PART_OF_PROGRESS_BAR               = 0x0040, // hidden objective used to calculate progress bar percent (quests are limited to a single progress bar objective)
    QUEST_OBJECTIVE_FLAG_KILL_PLAYERS_SAME_FACTION          = 0x0080,
    QUEST_OBJECTIVE_FLAG_NO_SHARE_PROGRESS                  = 0x0100,
    QUEST_OBJECTIVE_FLAG_IGNORE_SOULBOUND_ITEMS             = 0x0200,
};

enum QuestObjectiveFlags2
{
    QUEST_OBJECTIVE_FLAG_2_QUEST_BOUND_ITEM = 0x1   // Item is bound to a single objective, only increments the counter for one quest if multiple require the same item and is not stored in inventory
};

enum class QuestCompleteSpellType : uint32
{
    LegacyBehavior  = 0,
    Follower        = 1,
    Tradeskill      = 2,
    Ability         = 3,
    Aura            = 4,
    Spell           = 5,
    Unlock          = 6,
    Companion       = 7,
    Max
};

struct QuestGreeting
{
    uint16 EmoteType;
    uint32 EmoteDelay;
    std::string Text;

    QuestGreeting() : EmoteType(0), EmoteDelay(0) { }
    QuestGreeting(uint16 emoteType, uint32 emoteDelay, std::string text)
        : EmoteType(emoteType), EmoteDelay(emoteDelay), Text(std::move(text)) { }
};

struct QuestGreetingLocale
{
    std::vector<std::string> Greeting;
};

struct QuestTemplateLocale
{
    std::vector<std::string> LogTitle;
    std::vector<std::string> LogDescription;
    std::vector<std::string> QuestDescription;
    std::vector<std::string> AreaDescription;
    std::vector<std::string> PortraitGiverText;
    std::vector<std::string> PortraitGiverName;
    std::vector<std::string> PortraitTurnInText;
    std::vector<std::string> PortraitTurnInName;
    std::vector<std::string> QuestCompletionLog;
};

struct QuestRequestItemsLocale
{
    std::vector<std::string> CompletionText;
};

struct QuestObjectivesLocale
{
    std::vector<std::string> Description;
};

struct QuestOfferRewardLocale
{
    std::vector<std::string> RewardText;
};

struct QuestObjectiveAction
{
    Optional<uint32> GameEventId;
    Optional<uint32> SpellId;
    Optional<uint32> ConversationId;
    bool UpdatePhaseShift = false;
    bool UpdateZoneAuras = false;
};

struct QuestObjective
{
    uint32 ID           = 0;
    uint32 QuestID      = 0;
    uint8  Type         = 0;
    int8   StorageIndex = 0;
    int32  ObjectID     = 0;
    int32  Amount       = 0;
    uint32 Flags        = 0;
    uint32 Flags2       = 0;
    float  ProgressBarWeight = 0.0f;
    std::string Description;
    std::vector<int32> VisualEffects;
    QuestObjectiveAction* CompletionEffect = nullptr;

    bool IsStoringValue() const
    {
        switch (Type)
        {
            case QUEST_OBJECTIVE_MONSTER:
            case QUEST_OBJECTIVE_ITEM:
            case QUEST_OBJECTIVE_GAMEOBJECT:
            case QUEST_OBJECTIVE_TALKTO:
            case QUEST_OBJECTIVE_PLAYERKILLS:
            case QUEST_OBJECTIVE_WINPVPPETBATTLES:
            case QUEST_OBJECTIVE_HAVE_CURRENCY:
            case QUEST_OBJECTIVE_OBTAIN_CURRENCY:
            case QUEST_OBJECTIVE_INCREASE_REPUTATION:
                return true;
            default:
                break;
        }
        return false;
    }

    bool IsStoringFlag() const
    {
        switch (Type)
        {
            case QUEST_OBJECTIVE_AREATRIGGER:
            case QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC:
            case QUEST_OBJECTIVE_DEFEATBATTLEPET:
            case QUEST_OBJECTIVE_CRITERIA_TREE:
            case QUEST_OBJECTIVE_AREA_TRIGGER_ENTER:
            case QUEST_OBJECTIVE_AREA_TRIGGER_EXIT:
                return true;
            default:
                break;
        }
        return false;
    }

    static constexpr bool CanAlwaysBeProgressedInRaid(QuestObjectiveType type)
    {
        switch (type)
        {
            case QUEST_OBJECTIVE_ITEM:
            case QUEST_OBJECTIVE_CURRENCY:
            case QUEST_OBJECTIVE_LEARNSPELL:
            case QUEST_OBJECTIVE_MIN_REPUTATION:
            case QUEST_OBJECTIVE_MAX_REPUTATION:
            case QUEST_OBJECTIVE_MONEY:
            case QUEST_OBJECTIVE_HAVE_CURRENCY:
            case QUEST_OBJECTIVE_INCREASE_REPUTATION:
                return true;
            default:
                break;
        }
        return false;
    }
};

using QuestObjectives = std::vector<QuestObjective>;

struct QuestRewardDisplaySpell
{
    QuestRewardDisplaySpell() : SpellId(0), PlayerConditionId(0), Type(QuestCompleteSpellType::LegacyBehavior) { }
    QuestRewardDisplaySpell(uint32 spellId, uint32 playerConditionId, QuestCompleteSpellType type) : SpellId(spellId), PlayerConditionId(playerConditionId), Type(type) { }

    uint32 SpellId;
    uint32 PlayerConditionId;
    QuestCompleteSpellType Type;
};

struct QuestConditionalText
{
    int32 PlayerConditionId = 0;
    int32 QuestgiverCreatureId = 0;
    std::vector<std::string> Text;
};

// This Quest class provides a convenient way to access a few pretotaled (cached) quest details,
// all base quest information, and any utility functions such as generating the amount of
// xp to give
class TC_GAME_API Quest
{
    friend class ObjectMgr;
    friend class Player;
    friend class PlayerMenu;
    public:
        // Loading data. All queries are in ObjectMgr::LoadQuests()
        explicit Quest(Field* questRecord);
        ~Quest();
        void LoadRewardDisplaySpell(Field* fields);
        void LoadRewardChoiceItems(Field* fields);
        void LoadQuestDetails(Field* fields);
        void LoadQuestRequestItems(Field* fields);
        void LoadQuestOfferReward(Field* fields);
        void LoadQuestTemplateAddon(Field* fields);
        void LoadQuestMailSender(Field* fields);
        void LoadQuestObjective(Field* fields);
        void LoadQuestObjectiveVisualEffect(Field* fields);
        void LoadConditionalConditionalQuestDescription(Field* fields);
        void LoadConditionalConditionalRequestItemsText(Field* fields);
        void LoadConditionalConditionalOfferRewardText(Field* fields);
        void LoadConditionalConditionalQuestCompletionLog(Field* fields);

        uint32 XPValue(Player const* player) const;
        static uint32 XPValue(Player const* player, uint32 contentTuningId, uint32 xpDifficulty, float xpMultiplier = 1.0f, int32 expansion = -1);
        uint32 MoneyValue(Player const* player) const;
        uint32 MaxMoneyValue() const;
        uint32 GetMaxMoneyReward() const;
        Optional<QuestTagType> GetQuestTag() const;
        bool IsImportant() const;

        bool HasFlag(QuestFlags flag) const { return (_flags & uint32(flag)) != 0; }
        bool HasFlagEx(QuestFlagsEx flag) const { return (_flagsEx & uint32(flag)) != 0; }
        bool HasFlagEx2(QuestFlagsEx2 flag) const { return (_flagsEx2 & uint32(flag)) != 0; }

        bool HasSpecialFlag(QuestSpecialFlags flag) const { return (_specialFlags & flag) != 0; }
        void SetSpecialFlag(QuestSpecialFlags flag) { _specialFlags |= flag; }
        bool HasQuestObjectiveType(QuestObjectiveType type) const { return _usedQuestObjectiveTypes[type]; }

        bool IsAutoPush() const { return HasFlagEx(QUEST_FLAGS_EX_AUTO_PUSH); }
        bool IsWorldQuest() const { return HasFlagEx(QUEST_FLAGS_EX_IS_WORLD_QUEST); }

        // Possibly deprecated flag
        bool IsUnavailable() const { return HasFlag(QUEST_FLAGS_DEPRECATED); }

        // whether the quest is globally enabled (spawned by pool, game event active etc.)
        static bool IsTakingQuestEnabled(uint32 questId);

        // table data accessors:
        uint32 GetQuestId() const { return _id; }
        uint32 GetQuestType() const { return _type; }
        uint32 GetQuestPackageID() const { return _packageID; }
        uint32 GetContentTuningId() const { return _contentTuningID; }
        int32  GetZoneOrSort() const { return _questSortID; }
        uint32 GetMaxLevel() const { return _maxLevel; }
        uint32 GetQuestInfoID() const { return _questInfoID; }
        uint32 GetAllowableClasses() const { return _allowableClasses; }
        Trinity::RaceMask<uint64> GetAllowableRaces() const { return _allowableRaces; }
        uint32 GetRequiredSkill() const { return _requiredSkillId; }
        uint32 GetRequiredSkillValue() const { return _requiredSkillPoints; }
        uint32 GetRequiredMinRepFaction() const { return _requiredMinRepFaction; }
        int32  GetRequiredMinRepValue() const { return _requiredMinRepValue; }
        uint32 GetRequiredMaxRepFaction() const { return _requiredMaxRepFaction; }
        int32  GetRequiredMaxRepValue() const { return _requiredMaxRepValue; }
        uint32 GetSuggestedPlayers() const { return _suggestedPlayers; }
        int64 GetLimitTime() const { return _limitTime; }
        int32  GetPrevQuestId() const { return _prevQuestID; }
        uint32 GetNextQuestId() const { return _nextQuestID; }
        int32  GetExclusiveGroup() const { return _exclusiveGroup; }
        int32  GetBreadcrumbForQuestId() const { return _breadcrumbForQuestId; }
        uint32 GetNextQuestInChain() const { return _nextQuestInChain; }
        int32  GetRewArenaPoints() const {return _rewardArenaPoints; }
        uint32 GetXPDifficulty() const { return _rewardXPDifficulty; }
        float  GetXPMultiplier() const { return _rewardXPMultiplier; }
        float  GetMoneyMultiplier() const { return _rewardMoneyMultiplier; }
        uint32 GetSrcItemId() const { return _sourceItemId; }
        uint32 GetSrcItemCount() const { return _sourceItemIdCount; }
        uint32 GetSrcSpell() const { return _sourceSpellID; }
        std::string const& GetLogTitle() const { return _logTitle; }
        std::string const& GetLogDescription() const { return _logDescription; }
        std::string const& GetQuestDescription() const { return _questDescription; }
        std::vector<QuestConditionalText> const& GetConditionalQuestDescription() const { return _conditionalQuestDescription; }
        std::string const& GetAreaDescription() const { return _areaDescription; }
        std::string const& GetOfferRewardText() const { return _offerRewardText; }
        std::vector<QuestConditionalText> const& GetConditionalOfferRewardText() const { return _conditionalOfferRewardText; }
        std::string const& GetRequestItemsText() const { return _requestItemsText; }
        std::vector<QuestConditionalText> const& GetConditionalRequestItemsText() const { return _conditionalRequestItemsText; }
        std::string const& GetQuestCompletionLog() const { return _questCompletionLog; }
        std::vector<QuestConditionalText> const& GetConditionalQuestCompletionLog() const { return _conditionalQuestCompletionLog; }
        std::string const& GetPortraitGiverText() const { return _portraitGiverText; }
        std::string const& GetPortraitGiverName() const { return _portraitGiverName; }
        std::string const& GetPortraitTurnInText() const { return _portraitTurnInText; }
        std::string const& GetPortraitTurnInName() const { return _portraitTurnInName; }
        QuestObjectives const& GetObjectives() const { return Objectives; }
        uint32 GetRewMoneyDifficulty() const { return _rewardMoneyDifficulty; }
        uint32 GetRewHonor() const { return _rewardHonor; }
        uint32 GetRewKillHonor() const { return _rewardKillHonor; }
        uint32 GetArtifactXPDifficulty() const { return _rewardArtifactXPDifficulty; }
        float GetArtifactXPMultiplier() const { return _rewardArtifactXPMultiplier; }
        uint32 GetArtifactCategoryId() const { return _rewardArtifactCategoryID; }
        uint32 GetRewMoneyMaxLevel() const; // use in XP calculation at client
        uint32 GetRewSpell() const { return _rewardSpell; }
        uint32 GetRewMailTemplateId() const { return _rewardMailTemplateId; }
        uint32 GetRewMailDelaySecs() const { return _rewardMailDelay; }
        uint32 GetRewMailSenderEntry() const { return _rewardMailSenderEntry; }
        uint32 GetRewTitle() const { return _rewardTitleId; }
        uint32 GetPOIContinent() const { return _poiContinent; }
        float GetPOIx() const { return _poix; }
        float GetPOIy() const { return _poiy; }
        uint32 GetPOIPriority() const { return _poiPriority; }
        uint32 GetSoundAccept() const { return _soundAccept; }
        uint32 GetSoundTurnIn() const { return _soundTurnIn; }
        uint32 GetIncompleteEmote() const { return _emoteOnIncomplete; }
        uint32 GetCompleteEmote() const { return _emoteOnComplete; }
        uint32 GetIncompleteEmoteDelay() const { return _emoteOnIncompleteDelay; }
        uint32 GetCompleteEmoteDelay() const { return _emoteOnCompleteDelay; }
        bool IsRepeatable() const { return _specialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE; }
        bool IsAutoAccept() const;
        bool IsTurnIn() const;
        uint32 GetFlags() const { return _flags; }
        uint32 GetFlagsEx() const { return _flagsEx; }
        uint32 GetFlagsEx2() const { return _flagsEx2; }
        uint32 GetSpecialFlags() const { return _specialFlags; }
        uint32 GetScriptId() const { return _scriptId; }
        uint32 GetAreaGroupID() const { return _areaGroupID; }
        uint32 GetRewardSkillId() const { return _rewardSkillId; }
        uint32 GetRewardSkillPoints() const { return _rewardSkillPoints; }
        uint32 GetRewardReputationMask() const { return _rewardReputationMask; }
        int32 GetTreasurePickerId() const { return _treasurePickerID; }
        int32 GetExpansion() const { return _expansion; }
        int32 GetManagedWorldStateId() const { return _managedWorldStateID; }
        int32 GetQuestSessionBonus() const { return _questSessionBonus; }
        uint32 GetQuestGiverPortrait() const { return _questGiverPortrait; }
        int32 GetQuestGiverPortraitMount() const { return _questGiverPortraitMount; }
        int32 GetQuestGiverPortraitModelSceneId() const { return _questGiverPortraitModelSceneId; }
        uint32 GetQuestTurnInPortrait() const { return _questTurnInPortrait; }
        bool IsDaily() const { return (_flags & QUEST_FLAGS_DAILY) != 0; }
        bool IsWeekly() const { return (_flags & QUEST_FLAGS_WEEKLY) != 0; }
        bool IsMonthly() const { return (_specialFlags & QUEST_SPECIAL_FLAGS_MONTHLY) != 0; }
        bool IsSeasonal() const { return (_questSortID == -QUEST_SORT_SEASONAL || _questSortID == -QUEST_SORT_SPECIAL || _questSortID == -QUEST_SORT_LUNAR_FESTIVAL || _questSortID == -QUEST_SORT_MIDSUMMER || _questSortID == -QUEST_SORT_BREWFEST || _questSortID == -QUEST_SORT_LOVE_IS_IN_THE_AIR || _questSortID == -QUEST_SORT_NOBLEGARDEN) && !IsRepeatable(); }
        bool IsDailyOrWeekly() const { return (_flags & (QUEST_FLAGS_DAILY | QUEST_FLAGS_WEEKLY)) != 0; }
        bool IsRaidQuest(Difficulty difficulty) const;
        bool IsAllowedInRaid(Difficulty difficulty) const;
        bool IsDFQuest() const { return (_specialFlags & QUEST_SPECIAL_FLAGS_DF_QUEST) != 0; }
        bool IsPushedToPartyOnAccept() const { return HasSpecialFlag(QUEST_SPECIAL_FLAGS_AUTO_PUSH_TO_PARTY); }
        uint32 CalculateHonorGain(uint8 level) const;
        bool CanIncreaseRewardedQuestCounters() const;

        // multiple values
        std::vector<QuestRewardDisplaySpell> RewardDisplaySpell;
        std::array<uint32, QUEST_REWARD_ITEM_COUNT> RewardItemId = { };
        std::array<uint32, QUEST_REWARD_ITEM_COUNT> RewardItemCount = { };
        std::array<uint32, QUEST_ITEM_DROP_COUNT> ItemDrop = { };
        std::array<uint32, QUEST_ITEM_DROP_COUNT> ItemDropQuantity = { };
        std::array<LootItemType, QUEST_REWARD_CHOICES_COUNT> RewardChoiceItemType = { };
        std::array<uint32, QUEST_REWARD_CHOICES_COUNT> RewardChoiceItemId = { };
        std::array<uint32, QUEST_REWARD_CHOICES_COUNT> RewardChoiceItemCount = { };
        std::array<uint32, QUEST_REWARD_CHOICES_COUNT> RewardChoiceItemDisplayId = { };
        std::array<uint32, QUEST_REWARD_REPUTATIONS_COUNT> RewardFactionId = { };
        std::array<int32, QUEST_REWARD_REPUTATIONS_COUNT>  RewardFactionValue = { };
        std::array<int32, QUEST_REWARD_REPUTATIONS_COUNT>  RewardFactionOverride = { };
        std::array<int32, QUEST_REWARD_REPUTATIONS_COUNT> RewardFactionCapIn = { };
        std::array<uint32, QUEST_REWARD_CURRENCY_COUNT> RewardCurrencyId = { };
        std::array<uint32, QUEST_REWARD_CURRENCY_COUNT> RewardCurrencyCount = { };
        QuestObjectives Objectives;
        std::array<uint32, QUEST_EMOTE_COUNT> DetailsEmote = { };
        std::array<uint32, QUEST_EMOTE_COUNT> DetailsEmoteDelay = { };
        std::array<int32, QUEST_EMOTE_COUNT> OfferRewardEmote = { };
        std::array<uint32, QUEST_EMOTE_COUNT> OfferRewardEmoteDelay = { };

        uint32 GetRewChoiceItemsCount() const { return _rewChoiceItemsCount; }
        uint32 GetRewItemsCount() const { return _rewItemsCount; }
        uint32 GetRewCurrencyCount() const { return _rewCurrencyCount; }

        void SetEventIdForQuest(uint16 eventId) { _eventIdForQuest = eventId; }
        uint16 GetEventIdForQuest() const { return _eventIdForQuest; }

        void InitializeQueryData();
        WorldPacket BuildQueryData(LocaleConstant loc, Player* player) const;

        void BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const;

        // Helpers
        static uint32 RoundXPValue(uint32 xp);

        std::vector<uint32> DependentPreviousQuests;
        std::vector<uint32> DependentBreadcrumbQuests;
        std::array<WorldPacket, TOTAL_LOCALES> QueryData;

    private:
        uint32 _rewChoiceItemsCount = 0;
        uint32 _rewItemsCount = 0;
        uint16 _eventIdForQuest = 0;
        uint32 _rewCurrencyCount = 0;

        // wdb data (quest query response)
        uint32 _id = 0;
        uint32 _type = 0;
        uint32 _packageID = 0;
        uint32 _contentTuningID = 0;
        int32 _questSortID = 0;
        uint32 _questInfoID = 0;
        uint32 _suggestedPlayers = 0;
        uint32 _nextQuestInChain = 0;
        uint32 _rewardXPDifficulty = 0;
        float _rewardXPMultiplier = 0.f;
        uint32 _rewardMoneyDifficulty = 0;
        float _rewardMoneyMultiplier = 0.f;
        uint32 _rewardBonusMoney = 0;
        uint32 _rewardSpell = 0;
        uint32 _rewardHonor = 0;
        uint32 _rewardKillHonor = 0;
        uint32 _rewardArtifactXPDifficulty = 0;
        float _rewardArtifactXPMultiplier = 0.f;
        uint32 _rewardArtifactCategoryID = 0;
        uint32 _sourceItemId = 0;
        uint32 _flags = 0;
        uint32 _flagsEx = 0;
        uint32 _flagsEx2 = 0;
        uint32 _poiContinent = 0;
        float _poix = 0.f;
        float _poiy = 0.f;
        uint32 _poiPriority = 0;
        uint32 _rewardTitleId = 0;
        int32 _rewardArenaPoints = 0;
        uint32 _rewardSkillId = 0;
        uint32 _rewardSkillPoints = 0;
        uint32 _questGiverPortrait = 0;
        int32 _questGiverPortraitMount = 0;
        int32 _questGiverPortraitModelSceneId = 0;
        uint32 _questTurnInPortrait = 0;
        uint32 _rewardReputationMask;
        uint32 _soundAccept = 0;
        uint32 _soundTurnIn = 0;
        uint32 _areaGroupID = 0;
        int64 _limitTime = 0;
        Trinity::RaceMask<uint64> _allowableRaces;
        int32 _treasurePickerID = 0;
        int32 _expansion = 0;
        int32 _managedWorldStateID = 0;
        int32 _questSessionBonus = 0;
        std::string _logTitle;
        std::string _logDescription;
        std::string _questDescription;
        std::string _areaDescription;
        std::string _portraitGiverText;
        std::string _portraitGiverName;
        std::string _portraitTurnInText;
        std::string _portraitTurnInName;
        std::string _questCompletionLog;

        // quest_description_conditional
        std::vector<QuestConditionalText> _conditionalQuestDescription;

        // quest_completion_log_conditional
        std::vector<QuestConditionalText> _conditionalQuestCompletionLog;

        // quest_request_items table
        uint32 _emoteOnComplete = 0;
        uint32 _emoteOnIncomplete = 0;
        uint32 _emoteOnCompleteDelay = 0;
        uint32 _emoteOnIncompleteDelay = 0;
        std::string _requestItemsText;

        // quest_request_items_conditional
        std::vector<QuestConditionalText> _conditionalRequestItemsText;

        // quest_offer_reward table
        std::string _offerRewardText;

        // quest_offer_reward_conditional
        std::vector<QuestConditionalText> _conditionalOfferRewardText;

        // quest_template_addon table (custom data)
        uint32 _maxLevel = 0;
        uint32 _allowableClasses = 0;
        uint32 _sourceSpellID = 0;
        int32 _prevQuestID = 0;
        uint32 _nextQuestID = 0;
        int32 _exclusiveGroup = 0;
        int32 _breadcrumbForQuestId = 0;
        uint32 _rewardMailTemplateId = 0;
        uint32 _rewardMailDelay = 0;
        uint32 _requiredSkillId = 0;
        uint32 _requiredSkillPoints = 0;
        uint32 _requiredMinRepFaction = 0;
        int32 _requiredMinRepValue = 0;
        uint32 _requiredMaxRepFaction = 0;
        int32 _requiredMaxRepValue = 0;
        uint32 _sourceItemIdCount = 0;
        uint32 _rewardMailSenderEntry = 0;
        uint32 _specialFlags = 0; // custom flags, not sniffed/WDB
        std::bitset<MAX_QUEST_OBJECTIVE_TYPE> _usedQuestObjectiveTypes;
        uint32 _scriptId = 0;
};

struct QuestStatusData
{
    uint16 Slot = MAX_QUEST_LOG_SIZE;
    QuestStatus Status = QUEST_STATUS_NONE;
    time_t AcceptTime = time_t(0);
    uint32 Timer = 0;
    bool Explored = false;
};

#endif
