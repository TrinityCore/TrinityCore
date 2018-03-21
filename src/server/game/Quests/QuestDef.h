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

#ifndef TRINITYCORE_QUEST_H
#define TRINITYCORE_QUEST_H

#include "Common.h"
#include "DBCEnums.h"
#include "DatabaseEnvFwd.h"
#include "SharedDefines.h"
#include <vector>

class Player;

namespace WorldPackets
{
    namespace Quest
    {
        struct QuestRewards;
    }
}

#define MAX_QUEST_LOG_SIZE 25

#define QUEST_ITEM_DROP_COUNT 4
#define QUEST_REWARD_CHOICES_COUNT 6
#define QUEST_REWARD_ITEM_COUNT 4
#define QUEST_DEPLINK_COUNT 10
#define QUEST_REWARD_REPUTATIONS_COUNT 5
#define QUEST_EMOTE_COUNT 4
#define QUEST_REWARD_CURRENCY_COUNT 4
#define QUEST_REWARD_DISPLAY_SPELL_COUNT 3

enum QuestFailedReason
{
    QUEST_ERR_NONE                              = 0,
    QUEST_ERR_FAILED_LOW_LEVEL                  = 1,        // "You are not high enough level for that quest.""
    QUEST_ERR_FAILED_WRONG_RACE                 = 6,        // "That quest is not available to your race."
    QUEST_ERR_ALREADY_DONE                      = 7,        // "You have completed that daily quest today."
    QUEST_ERR_ONLY_ONE_TIMED                    = 12,       // "You can only be on one timed quest at a time"
    QUEST_ERR_ALREADY_ON1                       = 13,       // "You are already on that quest"
    QUEST_ERR_FAILED_EXPANSION                  = 16,       // "This quest requires an expansion enabled account."
    QUEST_ERR_ALREADY_ON2                       = 18,       // "You are already on that quest"
    QUEST_ERR_FAILED_MISSING_ITEMS              = 21,       // "You don't have the required items with you.  Check storage."
    QUEST_ERR_FAILED_NOT_ENOUGH_MONEY           = 23,       // "You don't have enough money for that quest"
    QUEST_ERR_FAILED_CAIS                       = 24,       // "You cannot complete quests once you have reached tired time"
    QUEST_ERR_ALREADY_DONE_DAILY                = 26,       // "You have completed that daily quest today."
    QUEST_ERR_FAILED_SPELL                      = 28,       // "You haven't learned the required spell."
    QUEST_ERR_HAS_IN_PROGRESS                   = 30        // "Progress Bar objective not completed"
};

enum QuestPushReason : uint8
{
    QUEST_PUSH_SUCCESS                  = 0,    // "Sharing quest with %s..."
    QUEST_PUSH_INVALID                  = 1,    // "%s is not eligible for that quest"
    QUEST_PUSH_ACCEPTED                 = 2,    // "%s has accepted your quest"
    QUEST_PUSH_DECLINED                 = 3,    // "%s has declined your quest"
    QUEST_PUSH_BUSY                     = 4,    // "%s is busy"
    QUEST_PUSH_DEAD                     = 5,    // "%s is dead."
    QUEST_PUSH_LOG_FULL                 = 6,    // "%s's quest log is full"
    QUEST_PUSH_ONQUEST                  = 7,    // "%s is already on that quest"
    QUEST_PUSH_ALREADY_DONE             = 8,    // "%s has completed that quest"
    QUEST_PUSH_NOT_DAILY                = 9,    // "That quest cannot be shared today"
    QUEST_PUSH_TIMER_EXPIRED            = 10,   // "Quest sharing timer has expired"
    QUEST_PUSH_NOT_IN_PARTY             = 11,   // "You are not in a party"
    QUEST_PUSH_DIFFERENT_SERVER_DAILY   = 12,   // "%s is not eligible for that quest today"
    QUEST_PUSH_NOT_ALLOWED              = 13    // "That quest cannot be shared"
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

enum QuestGiverStatus
{
    DIALOG_STATUS_NONE                     = 0x000,
    DIALOG_STATUS_UNK                      = 0x001,
    DIALOG_STATUS_UNAVAILABLE              = 0x002,
    DIALOG_STATUS_LOW_LEVEL_AVAILABLE      = 0x004,
    DIALOG_STATUS_LOW_LEVEL_REWARD_REP     = 0x008,
    DIALOG_STATUS_LOW_LEVEL_AVAILABLE_REP  = 0x010,
    DIALOG_STATUS_INCOMPLETE               = 0x020,
    DIALOG_STATUS_REWARD_REP               = 0x040,
    DIALOG_STATUS_AVAILABLE_REP            = 0x080,
    DIALOG_STATUS_AVAILABLE                = 0x100,
    DIALOG_STATUS_REWARD2                  = 0x200,         // no yellow dot on minimap
    DIALOG_STATUS_REWARD                   = 0x400,         // yellow dot on minimap

    // Custom value meaning that script call did not return any valid quest status
    DIALOG_STATUS_SCRIPTED_NO_STATUS       = 0x1000
};

enum QuestFlags : uint32
{
    QUEST_FLAGS_NONE                        = 0x00000000,
    QUEST_FLAGS_STAY_ALIVE                  = 0x00000001,   // Not used currently
    QUEST_FLAGS_PARTY_ACCEPT                = 0x00000002,   // Not used currently. If player in party, all players that can accept this quest will receive confirmation box to accept quest CMSG_QUEST_CONFIRM_ACCEPT/SMSG_QUEST_CONFIRM_ACCEPT
    QUEST_FLAGS_EXPLORATION                 = 0x00000004,   // Not used currently
    QUEST_FLAGS_SHARABLE                    = 0x00000008,   // Can be shared: Player::CanShareQuest()
    QUEST_FLAGS_HAS_CONDITION               = 0x00000010,   // Not used currently
    QUEST_FLAGS_HIDE_REWARD_POI             = 0x00000020,   // Not used currently: Unsure of content
    QUEST_FLAGS_RAID                        = 0x00000040,   // Can be completed while in raid
    QUEST_FLAGS_TBC                         = 0x00000080,   // Not used currently: Available if TBC expansion enabled only
    QUEST_FLAGS_NO_MONEY_FROM_XP            = 0x00000100,   // Not used currently: Experience is not converted to gold at max level
    QUEST_FLAGS_HIDDEN_REWARDS              = 0x00000200,   // Items and money rewarded only sent in SMSG_QUESTGIVER_OFFER_REWARD (not in SMSG_QUESTGIVER_QUEST_DETAILS or in client quest log(SMSG_QUEST_QUERY_RESPONSE))
    QUEST_FLAGS_TRACKING                    = 0x00000400,   // These quests are automatically rewarded on quest complete and they will never appear in quest log client side.
    QUEST_FLAGS_DEPRECATE_REPUTATION        = 0x00000800,   // Not used currently
    QUEST_FLAGS_DAILY                       = 0x00001000,   // Used to know quest is Daily one
    QUEST_FLAGS_FLAGS_PVP                   = 0x00002000,   // Having this quest in log forces PvP flag
    QUEST_FLAGS_UNAVAILABLE                 = 0x00004000,   // Used on quests that are not generically available
    QUEST_FLAGS_WEEKLY                      = 0x00008000,
    QUEST_FLAGS_AUTOCOMPLETE                = 0x00010000,   // Quests with this flag player submit automatically by special button in player gui
    QUEST_FLAGS_DISPLAY_ITEM_IN_TRACKER     = 0x00020000,   // Displays usable item in quest tracker
    QUEST_FLAGS_OBJ_TEXT                    = 0x00040000,   // use Objective text as Complete text
    QUEST_FLAGS_AUTO_ACCEPT                 = 0x00080000,   // The client recognizes this flag as auto-accept.
    QUEST_FLAGS_PLAYER_CAST_ON_ACCEPT       = 0x00100000,
    QUEST_FLAGS_PLAYER_CAST_ON_COMPLETE     = 0x00200000,
    QUEST_FLAGS_UPDATE_PHASE_SHIFT          = 0x00400000,
    QUEST_FLAGS_SOR_WHITELIST               = 0x00800000,
    QUEST_FLAGS_LAUNCH_GOSSIP_COMPLETE      = 0x01000000,
    QUEST_FLAGS_REMOVE_EXTRA_GET_ITEMS      = 0x02000000,
    QUEST_FLAGS_HIDE_UNTIL_DISCOVERED       = 0x04000000,
    QUEST_FLAGS_PORTRAIT_IN_QUEST_LOG       = 0x08000000,
    QUEST_FLAGS_SHOW_ITEM_WHEN_COMPLETED    = 0x10000000,
    QUEST_FLAGS_LAUNCH_GOSSIP_ACCEPT        = 0x20000000,
    QUEST_FLAGS_ITEMS_GLOW_WHEN_DONE        = 0x40000000,
    QUEST_FLAGS_FAIL_ON_LOGOUT              = 0x80000000
};

// last checked in 19802
enum QuestFlagsEx : uint32
{
    QUEST_FLAGS_EX_NONE                                                 = 0x0000000,
    QUEST_FLAGS_EX_KEEP_ADDITIONAL_ITEMS                                = 0x0000001,
    QUEST_FLAGS_EX_SUPPRESS_GOSSIP_COMPLETE                             = 0x0000002,
    QUEST_FLAGS_EX_SUPPRESS_GOSSIP_ACCEPT                               = 0x0000004,
    QUEST_FLAGS_EX_DISALLOW_PLAYER_AS_QUESTGIVER                        = 0x0000008,
    QUEST_FLAGS_EX_DISPLAY_CLASS_CHOICE_REWARDS                         = 0x0000010,
    QUEST_FLAGS_EX_DISPLAY_SPEC_CHOICE_REWARDS                          = 0x0000020,
    QUEST_FLAGS_EX_REMOVE_FROM_LOG_ON_PERIDOIC_RESET                    = 0x0000040,
    QUEST_FLAGS_EX_ACCOUNT_LEVEL_QUEST                                  = 0x0000080,
    QUEST_FLAGS_EX_LEGENDARY_QUEST                                      = 0x0000100,
    QUEST_FLAGS_EX_NO_GUILD_XP                                          = 0x0000200,
    QUEST_FLAGS_EX_RESET_CACHE_ON_ACCEPT                                = 0x0000400,
    QUEST_FLAGS_EX_NO_ABANDON_ONCE_ANY_OBJECTIVE_COMPLETE               = 0x0000800,
    QUEST_FLAGS_EX_RECAST_ACCEPT_SPELL_ON_LOGIN                         = 0x0001000,
    QUEST_FLAGS_EX_UPDATE_ZONE_AURAS                                    = 0x0002000,
    QUEST_FLAGS_EX_NO_CREDIT_FOR_PROXY                                  = 0x0004000,
    QUEST_FLAGS_EX_DISPLAY_AS_DAILY_QUEST                               = 0x0008000,
    QUEST_FLAGS_EX_PART_OF_QUEST_LINE                                   = 0x0010000,
    QUEST_FLAGS_EX_QUEST_FOR_INTERNAL_BUILDS_ONLY                       = 0x0020000,
    QUEST_FLAGS_EX_SUPPRESS_SPELL_LEARN_TEXT_LINE                       = 0x0040000,
    QUEST_FLAGS_EX_DISPLAY_HEADER_AS_OBJECTIVE_FOR_TASKS                = 0x0080000,
    QUEST_FLAGS_EX_GARRISON_NON_OWNERS_ALLOWED                          = 0x0100000,
    QUEST_FLAGS_EX_REMOVE_QUEST_ON_WEEKLY_RESET                         = 0x0200000,
    QUEST_FLAGS_EX_SUPPRESS_FAREWELL_AUDIO_AFTER_QUEST_ACCEPT           = 0x0400000,
    QUEST_FLAGS_EX_REWARDS_BYPASS_WEEKLY_CAPS_AND_SEASON_TOTAL          = 0x0800000,
    QUEST_FLAGS_EX_CLEAR_PROGRESS_OF_CRITERIA_TREE_OBJECTIVES_ON_ACCEPT = 0x1000000
};

enum QuestSpecialFlags
{
    QUEST_SPECIAL_FLAGS_NONE                 = 0x000,
    // Trinity flags for set SpecialFlags in DB if required but used only at server
    QUEST_SPECIAL_FLAGS_REPEATABLE           = 0x001,   // Set by 1 in SpecialFlags from DB
    QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT = 0x002,   // Set by 2 in SpecialFlags from DB (if required area explore, spell SPELL_EFFECT_QUEST_COMPLETE casting, table `FECT_QUEST_COMPLETE casting, table `*_script` command SCRIPT_COMMAND_QUEST_EXPLORED use, set from script)
    QUEST_SPECIAL_FLAGS_AUTO_ACCEPT          = 0x004,   // Set by 4 in SpecialFlags in DB if the quest is to be auto-accepted.
    QUEST_SPECIAL_FLAGS_DF_QUEST             = 0x008,   // Set by 8 in SpecialFlags in DB if the quest is used by Dungeon Finder.
    QUEST_SPECIAL_FLAGS_MONTHLY              = 0x010,   // Set by 16 in SpecialFlags in DB if the quest is reset at the begining of the month
    QUEST_SPECIAL_FLAGS_CAST                 = 0x020,   // Set by 32 in SpecialFlags in DB if the quest requires RequiredOrNpcGo killcredit but NOT kill (a spell cast)
    // room for more custom flags

    QUEST_SPECIAL_FLAGS_DB_ALLOWED = QUEST_SPECIAL_FLAGS_REPEATABLE | QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT | QUEST_SPECIAL_FLAGS_AUTO_ACCEPT | QUEST_SPECIAL_FLAGS_DF_QUEST | QUEST_SPECIAL_FLAGS_MONTHLY | QUEST_SPECIAL_FLAGS_CAST,

    QUEST_SPECIAL_FLAGS_DELIVER              = 0x080,   // Internal flag computed only
    QUEST_SPECIAL_FLAGS_SPEAKTO              = 0x100,   // Internal flag computed only
    QUEST_SPECIAL_FLAGS_KILL                 = 0x200,   // Internal flag computed only
    QUEST_SPECIAL_FLAGS_TIMED                = 0x400,   // Internal flag computed only
    QUEST_SPECIAL_FLAGS_PLAYER_KILL          = 0x800    // Internal flag computed only
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
    QUEST_OBJECTIVE_OBTAIN_CURRENCY         = 17    // requires the player to gain X currency after starting the quest but not required to keep it until the end (does not consume)
};

enum QuestObjectiveFlags
{
    QUEST_OBJECTIVE_FLAG_TRACKED_ON_MINIMAP                 = 0x01, // client displays large yellow blob on minimap for creature/gameobject
    QUEST_OBJECTIVE_FLAG_SEQUENCED                          = 0x02, // client will not see the objective displayed until all previous objectives are completed
    QUEST_OBJECTIVE_FLAG_OPTIONAL                           = 0x04, // not required to complete the quest
    QUEST_OBJECTIVE_FLAG_HIDDEN                             = 0x08, // never displayed in quest log
    QUEST_OBJECTIVE_FLAG_HIDE_ITEM_GAINS                    = 0x10, // skip showing item objective progress
    QUEST_OBJECTIVE_FLAG_PROGRESS_COUNTS_ITEMS_IN_INVENTORY = 0x20, // item objective progress counts items in inventory instead of reading it from updatefields
    QUEST_OBJECTIVE_FLAG_PART_OF_PROGRESS_BAR               = 0x40, // hidden objective used to calculate progress bar percent (quests are limited to a single progress bar objective)
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

    bool IsStoringFlag() const
    {
        switch (Type)
        {
            case QUEST_OBJECTIVE_AREATRIGGER:
            case QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC:
            case QUEST_OBJECTIVE_DEFEATBATTLEPET:
            case QUEST_OBJECTIVE_CRITERIA_TREE:
                return true;
            default:
                break;
        }
        return false;
    }
};

typedef std::vector<QuestObjective> QuestObjectives;

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
        Quest(Field* questRecord);
        void LoadQuestDetails(Field* fields);
        void LoadQuestRequestItems(Field* fields);
        void LoadQuestOfferReward(Field* fields);
        void LoadQuestTemplateAddon(Field* fields);
        void LoadQuestObjective(Field* fields);
        void LoadQuestObjectiveVisualEffect(Field* fields);

        uint32 XPValue(uint32 playerLevel) const;
        uint32 MoneyValue(uint8 playerLevel) const;

        bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }
        void SetFlag(uint32 flag) { Flags |= flag; }

        bool HasSpecialFlag(uint32 flag) const { return (SpecialFlags & flag) != 0; }
        void SetSpecialFlag(uint32 flag) { SpecialFlags |= flag; }

        bool HasFlagEx(QuestFlagsEx flag) const { return (FlagsEx & uint32(flag)) != 0; }

        // table data accessors:
        uint32 GetQuestId() const { return ID; }
        uint32 GetQuestType() const { return Type; }
        uint32 GetQuestPackageID() const { return PackageID; }
        int32  GetZoneOrSort() const { return QuestSortID; }
        int32  GetMinLevel() const { return MinLevel; }
        uint32 GetMaxLevel() const { return MaxLevel; }
        int32  GetQuestLevel() const { return Level; }
        int32  GetQuestMaxScalingLevel() const { return MaxScalingLevel; }
        uint32 GetQuestInfoID() const { return QuestInfoID; }
        uint32 GetAllowableClasses() const { return AllowableClasses; }
        uint64 GetAllowableRaces() const { return AllowableRaces; }
        uint32 GetRequiredSkill() const { return RequiredSkillId; }
        uint32 GetRequiredSkillValue() const { return RequiredSkillPoints; }
        uint32 GetRequiredMinRepFaction() const { return RequiredMinRepFaction; }
        int32  GetRequiredMinRepValue() const { return RequiredMinRepValue; }
        uint32 GetRequiredMaxRepFaction() const { return RequiredMaxRepFaction; }
        int32  GetRequiredMaxRepValue() const { return RequiredMaxRepValue; }
        uint32 GetSuggestedPlayers() const { return SuggestedPlayers; }
        uint32 GetLimitTime() const { return LimitTime; }
        int32  GetPrevQuestId() const { return PrevQuestID; }
        int32  GetNextQuestId() const { return NextQuestID; }
        int32  GetExclusiveGroup() const { return ExclusiveGroup; }
        uint32 GetNextQuestInChain() const { return NextQuestInChain; }
        int32  GetRewArenaPoints() const {return RewardArenaPoints; }
        uint32 GetXPDifficulty() const { return RewardXPDifficulty; }
        float  GetXPMultiplier() const { return RewardXPMultiplier; }
        float  GetMoneyMultiplier() const { return RewardMoneyMultiplier; }
        uint32 GetSrcItemId() const { return SourceItemId; }
        uint32 GetSrcItemCount() const { return SourceItemIdCount; }
        uint32 GetSrcSpell() const { return SourceSpellID; }
        std::string const& GetLogTitle() const { return LogTitle; }
        std::string const& GetLogDescription() const { return LogDescription; }
        std::string const& GetQuestDescription() const { return QuestDescription; }
        std::string const& GetAreaDescription() const { return AreaDescription; }
        std::string const& GetOfferRewardText() const { return OfferRewardText; }
        std::string const& GetRequestItemsText() const { return RequestItemsText; }
        std::string const& GetQuestCompletionLog() const { return QuestCompletionLog; }
        std::string const& GetPortraitGiverText() const { return PortraitGiverText; }
        std::string const& GetPortraitGiverName() const { return PortraitGiverName; }
        std::string const& GetPortraitTurnInText() const { return PortraitTurnInText; }
        std::string const& GetPortraitTurnInName() const { return PortraitTurnInName; }
        QuestObjectives const& GetObjectives() const { return Objectives; }
        uint32 GetRewMoneyDifficulty() const { return RewardMoneyDifficulty; }
        uint32 GetRewHonor() const { return RewardHonor; }
        uint32 GetRewKillHonor() const { return RewardKillHonor; }
        uint32 GetArtifactXPDifficulty() const { return RewardArtifactXPDifficulty; }
        float  GetArtifactXPMultiplier() const { return RewardArtifactXPMultiplier; }
        uint32 GetArtifactCategoryId() const { return RewardArtifactCategoryID; }
        uint32 GetRewMoneyMaxLevel() const; // use in XP calculation at client
        uint32 GetRewSpell() const { return RewardSpell; }
        uint32 GetRewMailTemplateId() const { return RewardMailTemplateId; }
        uint32 GetRewMailDelaySecs() const { return RewardMailDelay; }
        uint32 GetRewMailSenderEntry() const { return RewardMailSenderEntry; }
        uint32 GetRewTitle() const { return RewardTitleId; }
        uint32 GetPOIContinent() const { return POIContinent; }
        float  GetPOIx() const { return POIx; }
        float  GetPOIy() const { return POIy; }
        uint32 GetPOIPriority() const { return POIPriority; }
        uint32 GetSoundAccept() const { return SoundAccept; }
        uint32 GetSoundTurnIn() const { return SoundTurnIn; }
        uint32 GetIncompleteEmote() const { return EmoteOnIncomplete; }
        uint32 GetCompleteEmote() const { return EmoteOnComplete; }
        bool   IsRepeatable() const { return SpecialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE; }
        bool   IsAutoAccept() const;
        bool   IsAutoComplete() const;
        uint32 GetFlags() const { return Flags; }
        uint32 GetFlagsEx() const { return FlagsEx; }
        uint32 GetSpecialFlags() const { return SpecialFlags; }
        uint32 GetScriptId() const { return ScriptId; }
        uint32 GetAreaGroupID() const { return AreaGroupID; }
        uint32 GetRewardSkillId() const { return RewardSkillId; }
        uint32 GetRewardSkillPoints() const { return RewardSkillPoints; }
        uint32 GetRewardReputationMask() const { return RewardReputationMask; }
        uint32 GetRewardId() const { return QuestRewardID; }
        int32 GetExpansion() const { return Expansion; }
        uint32 GetQuestGiverPortrait() const { return QuestGiverPortrait; }
        uint32 GetQuestTurnInPortrait() const { return QuestTurnInPortrait; }
        bool   IsDaily() const { return (Flags & QUEST_FLAGS_DAILY) != 0; }
        bool   IsWeekly() const { return (Flags & QUEST_FLAGS_WEEKLY) != 0; }
        bool   IsMonthly() const { return (SpecialFlags & QUEST_SPECIAL_FLAGS_MONTHLY) != 0; }
        bool   IsSeasonal() const { return (QuestSortID == -QUEST_SORT_SEASONAL || QuestSortID == -QUEST_SORT_SPECIAL || QuestSortID == -QUEST_SORT_LUNAR_FESTIVAL || QuestSortID == -QUEST_SORT_MIDSUMMER || QuestSortID == -QUEST_SORT_BREWFEST || QuestSortID == -QUEST_SORT_LOVE_IS_IN_THE_AIR || QuestSortID == -QUEST_SORT_NOBLEGARDEN) && !IsRepeatable(); }
        bool   IsDailyOrWeekly() const { return (Flags & (QUEST_FLAGS_DAILY | QUEST_FLAGS_WEEKLY)) != 0; }
        bool   IsRaidQuest(Difficulty difficulty) const;
        bool   IsAllowedInRaid(Difficulty difficulty) const;
        bool   IsDFQuest() const { return (SpecialFlags & QUEST_SPECIAL_FLAGS_DF_QUEST) != 0; }
        uint32 CalculateHonorGain(uint8 level) const;
        bool   CanIncreaseRewardedQuestCounters() const;

        uint32 GetRewChoiceItemsCount() const { return _rewChoiceItemsCount; }
        uint32 GetRewItemsCount() const { return _rewItemsCount; }
        uint32 GetRewCurrencyCount() const { return _rewCurrencyCount; }

        void BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const;

        typedef std::vector<int32> PrevQuests;
        PrevQuests prevQuests;
        typedef std::vector<uint32> PrevChainQuests;
        PrevChainQuests prevChainQuests;

    private:
        uint32 _rewChoiceItemsCount;
        uint32 _rewItemsCount;
        uint32 _rewCurrencyCount;

    public:
        // wdb data (quest query response)
        uint32 ID;
        uint32 Type;
        int32  Level;
        int32  MaxScalingLevel;
        uint32 PackageID;
        int32  MinLevel;
        int32  QuestSortID;
        uint32 QuestInfoID;
        uint32 SuggestedPlayers;
        uint32 NextQuestInChain;
        uint32 RewardXPDifficulty;
        float  RewardXPMultiplier;
        int32  RewardMoney;
        uint32 RewardMoneyDifficulty;
        float  RewardMoneyMultiplier;
        uint32 RewardBonusMoney;
        uint32 RewardDisplaySpell[QUEST_REWARD_DISPLAY_SPELL_COUNT];
        uint32 RewardSpell;
        uint32 RewardHonor;
        uint32 RewardKillHonor;
        uint32 RewardArtifactXPDifficulty;
        float  RewardArtifactXPMultiplier;
        uint32 RewardArtifactCategoryID;
        uint32 SourceItemId;
        uint32 Flags;
        uint32 FlagsEx;
        uint32 RewardItemId[QUEST_REWARD_ITEM_COUNT];
        uint32 RewardItemCount[QUEST_REWARD_ITEM_COUNT];
        uint32 ItemDrop[QUEST_ITEM_DROP_COUNT];
        uint32 ItemDropQuantity[QUEST_ITEM_DROP_COUNT];
        uint32 RewardChoiceItemId[QUEST_REWARD_CHOICES_COUNT];
        uint32 RewardChoiceItemCount[QUEST_REWARD_CHOICES_COUNT];
        uint32 RewardChoiceItemDisplayId[QUEST_REWARD_CHOICES_COUNT];
        uint32 POIContinent;
        float  POIx;
        float  POIy;
        uint32 POIPriority;
        uint32 RewardTitleId;
        int32  RewardArenaPoints;
        uint32 RewardSkillId;
        uint32 RewardSkillPoints;
        uint32 QuestGiverPortrait;
        uint32 QuestTurnInPortrait;
        uint32 RewardFactionId[QUEST_REWARD_REPUTATIONS_COUNT];
        int32  RewardFactionValue[QUEST_REWARD_REPUTATIONS_COUNT];
        int32  RewardFactionOverride[QUEST_REWARD_REPUTATIONS_COUNT];
        uint32 RewardFactionCapIn[QUEST_REWARD_REPUTATIONS_COUNT];
        uint32 RewardReputationMask;
        uint32 RewardCurrencyId[QUEST_REWARD_CURRENCY_COUNT];
        uint32 RewardCurrencyCount[QUEST_REWARD_CURRENCY_COUNT];
        uint32 SoundAccept;
        uint32 SoundTurnIn;
        uint32 AreaGroupID;
        uint32 LimitTime;
        uint64 AllowableRaces;
        uint32 QuestRewardID;
        int32 Expansion;
        QuestObjectives Objectives;
        std::string LogTitle;
        std::string LogDescription;
        std::string QuestDescription;
        std::string AreaDescription;
        std::string PortraitGiverText;
        std::string PortraitGiverName;
        std::string PortraitTurnInText;
        std::string PortraitTurnInName;
        std::string QuestCompletionLog;

    protected:

        // quest_detais table
        uint32 DetailsEmote[QUEST_EMOTE_COUNT] = { };
        uint32 DetailsEmoteDelay[QUEST_EMOTE_COUNT] = { };

        // quest_request_items table
        uint32 EmoteOnComplete          = 0;
        uint32 EmoteOnIncomplete        = 0;
        uint32 EmoteOnCompleteDelay     = 0;
        uint32 EmoteOnIncompleteDelay   = 0;
        std::string RequestItemsText;

        // quest_offer_reward table
        uint32 OfferRewardEmote[QUEST_EMOTE_COUNT] = { };
        uint32 OfferRewardEmoteDelay[QUEST_EMOTE_COUNT] = { };
        std::string OfferRewardText;

        // quest_template_addon table (custom data)
        uint32 MaxLevel             = 0;
        uint32 AllowableClasses     = 0;
        uint32 SourceSpellID        = 0;
        int32  PrevQuestID          = 0;
        int32  NextQuestID          = 0;
        int32  ExclusiveGroup       = 0;
        uint32 RewardMailTemplateId = 0;
        uint32 RewardMailDelay      = 0;
        uint32 RequiredSkillId      = 0;
        uint32 RequiredSkillPoints  = 0;
        uint32 RequiredMinRepFaction = 0;
        int32  RequiredMinRepValue  = 0;
        uint32 RequiredMaxRepFaction = 0;
        int32  RequiredMaxRepValue  = 0;
        uint32 SourceItemIdCount    = 0;
        uint32 RewardMailSenderEntry = 0;
        uint32 SpecialFlags         = 0; // custom flags, not sniffed/WDB
        uint32 ScriptId             = 0;
};

struct QuestStatusData
{
    QuestStatusData(): Status(QUEST_STATUS_NONE), Timer(0)
    {
    }

    QuestStatus Status;
    uint32 Timer;
    std::vector<int32> ObjectiveData;
};

#endif
