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
#include "DBCEnums.h"
#include "SharedDefines.h"
#include "WorldPacket.h"
#include <vector>

class Player;
class WorldPacket;

namespace WorldPackets
{
    namespace Quest
    {
        struct QuestRewards;
    }
}

#define MAX_QUEST_LOG_SIZE 25

#define QUEST_OBJECTIVES_COUNT 4
#define QUEST_ITEM_OBJECTIVES_COUNT 6
#define QUEST_SOURCE_ITEM_IDS_COUNT 4
#define QUEST_REWARD_CHOICES_COUNT 6
#define QUEST_REWARDS_COUNT 4
#define QUEST_DEPLINK_COUNT 10
#define QUEST_REPUTATIONS_COUNT 5
#define QUEST_EMOTE_COUNT 4
#define QUEST_PVP_KILL_SLOT 0
#define QUEST_REWARD_CURRENCY_COUNT 4
#define QUEST_REQUIRED_CURRENCY_COUNT 4

enum QuestFailedReason
{
    INVALIDREASON_DONT_HAVE_REQ                 = 0,
    INVALIDREASON_QUEST_FAILED_LOW_LEVEL        = 1,        // You are not high enough level for that quest.
    INVALIDREASON_QUEST_FAILED_WRONG_RACE       = 6,        // That quest is not available to your race.
    INVALIDREASON_QUEST_ALREADY_DONE            = 7,        // You have completed that quest.
    INVALIDREASON_QUEST_ONLY_ONE_TIMED          = 12,       // You can only be on one timed quest at a time.
    INVALIDREASON_QUEST_ALREADY_ON              = 13,       // You are already on that quest.
    INVALIDREASON_QUEST_FAILED_EXPANSION        = 16,       // This quest requires an expansion enabled account.
    INVALIDREASON_QUEST_ALREADY_ON2             = 18,       // You are already on that quest.
    INVALIDREASON_QUEST_FAILED_MISSING_ITEMS    = 21,       // You don't have the required items with you. Check storage.
    INVALIDREASON_QUEST_FAILED_NOT_ENOUGH_MONEY = 23,       // You don't have enough money for that quest.
    INVALIDREASON_DAILY_QUESTS_REMAINING        = 26,       // You have already completed 25 daily quests today.
    INVALIDREASON_QUEST_FAILED_CAIS             = 27,       // You cannot complete quests once you have reached tired time.
    INVALIDREASON_DAILY_QUEST_COMPLETED_TODAY   = 29        // You have completed that daily quest today.
};

enum QuestShareMessages : uint8
{
    QUEST_PARTY_MSG_SHARING_QUEST           = 0,
    QUEST_PARTY_MSG_CANT_TAKE_QUEST         = 1,
    QUEST_PARTY_MSG_ACCEPT_QUEST            = 2,
    QUEST_PARTY_MSG_DECLINE_QUEST           = 3,
    QUEST_PARTY_MSG_BUSY                    = 4,
    QUEST_PARTY_MSG_LOG_FULL                = 5,
    QUEST_PARTY_MSG_HAVE_QUEST              = 6,
    QUEST_PARTY_MSG_FINISH_QUEST            = 7,
    QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY    = 8,
    QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED   = 9,
    QUEST_PARTY_MSG_NOT_IN_PARTY            = 10,
    QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY      = 11
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
    DIALOG_STATUS_REWARD                   = 0x400          // yellow dot on minimap

};

enum QuestFlags
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
    QUEST_SPECIAL_FLAGS_PLAYER_KILL          = 0x800,   // Internal flag computed only
    QUEST_SPECIAL_FLAGS_COMPLETED_AT_START   = 0x1000   // Internal flag computed only
};

enum QuestStatusFlags
{
    QUEST_STATUS_FLAG_NONE                          = 0x0,
    QUEST_STATUS_FLAG_UNK_1                         = 0x1, // somewhat related to repeatable quests
    QUEST_STATUS_FLAG_KILL_OBJECTIVE_COMPLETE       = 0x2, // quest has its kill credit objectives completed
    QUEST_STATUS_FLAG_COLLECT_OBJECTIVE_COMPLETE    = 0x4, // quest has its collect objectives completed
    QUEST_STATUS_FLAG_UNK_4                         = 0x8,
    QUEST_STATUS_FLAG_UNK_5                         = 0x10,
    QUEST_STATUS_FLAG_NO_ITEM_REQUEST               = 0x20, // server wont send SMSG_QUEST_GIVER_REQUEST_ITEMS
    QUEST_STATUS_FLAG_UNK_7                         = 0x40,
    QUEST_STATUS_FLAG_UNK_8                         = 0x80
};

struct QuestLocale
{
    QuestLocale() { ObjectiveText.resize(QUEST_OBJECTIVES_COUNT); }

    std::vector<std::string> Title;
    std::vector<std::string> Details;
    std::vector<std::string> Objectives;
    std::vector<std::string> OfferRewardText;
    std::vector<std::string> RequestItemsText;
    std::vector<std::string> AreaDescription;
    std::vector<std::string> CompletedText;
    std::vector<std::vector<std::string>> ObjectiveText;
    // new on 4.x
    std::vector<std::string> QuestGiverTextWindow;
    std::vector<std::string> QuestGiverTargetName;
    std::vector<std::string> QuestTurnTextWindow;
    std::vector<std::string> QuestTurnTargetName;
};

// This Quest class provides a convenient way to access a few pretotaled (cached) quest details,
// all base quest information, and any utility functions such as generating the amount of
// xp to give
class TC_GAME_API Quest
{
    friend class ObjectMgr;
    public:
        Quest(Field* questRecord);
        void LoadQuestDetails(Field* fields);
        void LoadQuestRequestItems(Field* fields);
        void LoadQuestOfferReward(Field* fields);
        void LoadQuestTemplateAddon(Field* fields);
        void LoadQuestMailSender(Field* fields);

        uint32 GetXPReward(Player const* player) const;

        bool HasFlag(uint32 flag) const { return (_flags & flag) != 0; }
        void SetFlag(uint32 flag) { _flags |= flag; }

        bool HasSpecialFlag(uint32 flag) const { return (_specialFlags & flag) != 0; }
        void SetSpecialFlag(uint32 flag) { _specialFlags |= flag; }

        // whether the quest is globally enabled (spawned by pool, game event active etc.)
        static bool IsTakingQuestEnabled(uint32 questId);

        // table data accessors:
        uint32 GetQuestId() const { return _id; }
        uint32 GetQuestMethod() const { return _method; }
        int32  GetZoneOrSort() const { return _zoneOrSort; }
        uint32 GetMinLevel() const { return _minLevel; }
        uint32 GetMaxLevel() const { return _maxLevel; }
        int32  GetQuestLevel() const { return _level; }
        uint32 GetType() const { return _type; }
        uint32 GetAllowableClasses() const { return _allowableClasses; }
        uint32 GetAllowableRaces() const { return _allowableRaces; }
        uint32 GetRequiredSkill() const { return _requiredSkillId; }
        uint32 GetRequiredSkillValue() const { return _requiredSkillPoints; }
        uint32 GetRepObjectiveFaction() const { return _requiredFactionId1; }
        int32  GetRepObjectiveValue() const { return _requiredFactionValue1; }
        uint32 GetRepObjectiveFaction2() const { return _requiredFactionId2; }
        int32  GetRepObjectiveValue2() const { return _requiredFactionValue2; }
        uint32 GetRequiredMinRepFaction() const { return _requiredMinRepFaction; }
        int32  GetRequiredMinRepValue() const { return _requiredMinRepValue; }
        uint32 GetRequiredMaxRepFaction() const { return _requiredMaxRepFaction; }
        int32  GetRequiredMaxRepValue() const { return _requiredMaxRepValue; }
        uint32 GetSuggestedPlayers() const { return _suggestedPlayers; }
        uint32 GetTimeAllowed() const { return _timeAllowed; }
        int32  GetPrevQuestId() const { return _prevQuestId; }
        uint32 GetNextQuestId() const { return _nextQuestId; }
        int32  GetExclusiveGroup() const { return _exclusiveGroup; }
        int32  GetBreadcrumbForQuestId() const { return _breadcrumbForQuestId; }
        uint32 GetNextQuestInChain() const { return _rewardNextQuest; }
        uint32 GetCharTitleId() const { return _rewardTitleId; }
        uint32 GetPlayersSlain() const { return _requiredPlayerKills; }
        uint32 GetBonusTalents() const { return _rewardTalents; }
        int32  GetRewArenaPoints() const {return _rewardArenaPoints; }
        uint32 GetXPId() const { return _rewardXPDifficulty; }
        uint32 GetSrcItemId() const { return _startItem; }
        uint32 GetSrcItemCount() const { return _startItemCount; }
        uint32 GetSrcSpell() const { return _sourceSpellId; }
        std::string const& GetTitle() const { return _title; }
        std::string const& GetDetails() const { return _details; }
        std::string const& GetObjectives() const { return _objectives; }
        std::string const& GetOfferRewardText() const { return _offerRewardText; }
        std::string const& GetRequestItemsText() const { return _requestItemsText; }
        std::string const& GetAreaDescription() const { return _areaDescription; }
        std::string const& GetCompletedText() const { return _completedText; }
        std::string const& GetQuestGiverTextWindow() const { return _questGiverTextWindow; }
        std::string const& GetQuestGiverTargetName() const { return _questGiverTargetName; }
        std::string const& GetQuestTurnTextWindow() const { return _questTurnTextWindow; }
        std::string const& GetQuestTurnTargetName() const { return _questTurnTargetName; }
        int32  GetRewOrReqMoney(Player const* player = nullptr) const;
        uint32 GetRewHonorAddition() const { return _rewardHonor; }
        float GetRewHonorMultiplier() const { return _rewardKillHonor; }
        uint32 GetRewMoneyMaxLevel() const; // use in XP calculation at client
        uint32 GetRewSpell() const { return _rewardDisplaySpell; }
        int32  GetRewSpellCast() const { return _rewardSpell; }
        uint32 GetRewMailTemplateId() const { return _rewardMailTemplateId; }
        uint32 GetRewMailDelaySecs() const { return _rewardMailDelay; }
        uint32 GetRewMailSenderEntry() const { return _rewardMailSenderEntry; }
        uint32 GetPOIContinent() const { return _poiContinent; }
        float  GetPOIx() const { return _poiX; }
        float  GetPOIy() const { return _poiY; }
        uint32 GetPointOpt() const { return _poiPriority; }
        uint32 GetRequiredSpell() const { return _requiredSpell; }
        uint32 GetSoundAccept() const { return _soundAccept; }
        uint32 GetSoundTurnIn() const { return _soundTurnIn; }
        uint32 GetIncompleteEmote() const { return _emoteOnIncomplete; }
        uint32 GetCompleteEmote() const { return _emoteOnComplete; }
        bool   IsRepeatable() const { return _specialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE; }
        bool   IsAutoAccept() const;
        bool   IsAutoComplete() const;
        uint32 GetFlags() const { return _flags; }
        uint32 GetSpecialFlags() const { return _specialFlags; }
        uint32 GetMinimapTargetMark() const { return _minimapTargetMark; }
        uint32 GetRewardSkillId() const { return _rewardSkillId; }
        uint32 GetRewardSkillPoints() const { return _rewardSkillPoints; }
        uint32 GetRewardReputationMask() const { return _rewardReputationMask; }
        uint32 GetQuestGiverPortrait() const { return _questGiverPortrait; }
        uint32 GetQuestTurnInPortrait() const { return _questTurnInPortrait; }
        bool   IsDaily() const { return (_flags & QUEST_FLAGS_DAILY) != 0; }
        bool   IsWeekly() const { return (_flags & QUEST_FLAGS_WEEKLY) != 0; }
        bool   IsMonthly() const { return (_specialFlags & QUEST_SPECIAL_FLAGS_MONTHLY) != 0; }
        bool   IsSeasonal() const { return (_zoneOrSort == -QUEST_SORT_SEASONAL || _zoneOrSort == -QUEST_SORT_SPECIAL || _zoneOrSort == -QUEST_SORT_LUNAR_FESTIVAL || _zoneOrSort == -QUEST_SORT_MIDSUMMER || _zoneOrSort == -QUEST_SORT_BREWFEST || _zoneOrSort == -QUEST_SORT_LOVE_IS_IN_THE_AIR || _zoneOrSort == -QUEST_SORT_NOBLEGARDEN) && !IsRepeatable(); }
        bool   IsDailyOrWeekly() const { return (_flags & (QUEST_FLAGS_DAILY | QUEST_FLAGS_WEEKLY)) != 0; }
        bool   IsRaidQuest(Difficulty difficulty) const;
        bool   IsAllowedInRaid(Difficulty difficulty) const;
        bool   IsDFQuest() const { return (_specialFlags & QUEST_SPECIAL_FLAGS_DF_QUEST) != 0; }
        uint32 CalculateHonorGain(uint8 level) const;
        bool   CanIncreaseRewardedQuestCounters() const;
        bool   IsStartAtAreaTrigger() const { return _startsAtAreaTrigger; }

        // multiple values
        std::string ObjectiveText[QUEST_OBJECTIVES_COUNT];

        uint32 RequiredItemId[QUEST_ITEM_OBJECTIVES_COUNT] = { };
        uint32 RequiredItemCount[QUEST_ITEM_OBJECTIVES_COUNT] = { };
        uint32 ItemDrop[QUEST_SOURCE_ITEM_IDS_COUNT] = { };
        uint32 ItemDropQuantity[QUEST_SOURCE_ITEM_IDS_COUNT] = { };
        int32  RequiredNpcOrGo[QUEST_OBJECTIVES_COUNT] = { };   // >0 Creature <0 Gameobject
        uint32 RequiredNpcOrGoCount[QUEST_OBJECTIVES_COUNT] = { };
        uint32 RewardChoiceItemId[QUEST_REWARD_CHOICES_COUNT] = { };
        uint32 RewardChoiceItemCount[QUEST_REWARD_CHOICES_COUNT] = { };
        uint32 RewardItemId[QUEST_REWARDS_COUNT] = { };
        uint32 RewardItemIdCount[QUEST_REWARDS_COUNT] = { };
        uint32 RewardFactionId[QUEST_REPUTATIONS_COUNT] = { };
        int32  RewardFactionValueId[QUEST_REPUTATIONS_COUNT] = { };
        int32  RewardFactionValueIdOverride[QUEST_REPUTATIONS_COUNT] = { };
        uint32 DetailsEmote[QUEST_EMOTE_COUNT] = { };
        uint32 DetailsEmoteDelay[QUEST_EMOTE_COUNT] = { };
        uint32 OfferRewardEmote[QUEST_EMOTE_COUNT] = { };
        uint32 OfferRewardEmoteDelay[QUEST_EMOTE_COUNT] = { };
        // 4.x
        uint32 RewardCurrencyId[QUEST_REWARD_CURRENCY_COUNT] = { };
        uint32 RewardCurrencyCount[QUEST_REWARD_CURRENCY_COUNT] = { };
        uint32 RequiredCurrencyId[QUEST_REQUIRED_CURRENCY_COUNT] = { };
        uint32 RequiredCurrencyCount[QUEST_REQUIRED_CURRENCY_COUNT] = { };

        uint32 GetReqItemsCount() const { return _reqItemsCount; }
        uint32 GetReqCreatureOrGOcount() const { return _reqNpcOrGoCount; }
        uint32 GetRewChoiceItemsCount() const { return _rewChoiceItemsCount; }
        uint32 GetRewItemsCount() const { return _rewItemsCount; }
        uint32 GetRewCurrencyCount() const { return _rewCurrencyCount; }
        uint32 GetReqCurrencyCount() const { return _reqCurrencyCount; }

        void SetEventIdForQuest(uint16 eventId) { _eventIdForQuest = eventId; }
        uint16 GetEventIdForQuest() const { return _eventIdForQuest; }

        void BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const;

        static void AddQuestLevelToTitle(std::string& title, int32 level);
        void InitializeQueryData();
        WorldPacket BuildQueryData(LocaleConstant loc) const;

        std::vector<uint32> DependentPreviousQuests;
        std::vector<uint32> DependentBreadcrumbQuests;
        WorldPacket QueryData[TOTAL_LOCALES];

        // cached data
    private:
        uint32 _reqItemsCount = 0;
        uint32 _reqNpcOrGoCount = 0;
        uint32 _rewChoiceItemsCount = 0;
        uint32 _rewItemsCount = 0;
        uint16 _eventIdForQuest = 0;
        uint32 _rewCurrencyCount = 0;
        uint32 _reqCurrencyCount = 0;

        // table data
        uint32 _id = 0;
        uint32 _method = 0;
        int32  _zoneOrSort = 0;
        uint32 _minLevel = 0;
        int32  _level = 0;
        uint32 _type = 0;
        uint32 _allowableRaces = 0;
        uint32 _requiredFactionId1 = 0;
        int32  _requiredFactionValue1 = 0;
        uint32 _requiredFactionId2 = 0;
        int32  _requiredFactionValue2 = 0;
        uint32 _suggestedPlayers = 0;
        uint32 _timeAllowed = 0;
        uint32 _flags = 0;
        uint32 _rewardTitleId = 0;
        uint32 _requiredPlayerKills = 0;
        uint32 _rewardTalents = 0;
        int32  _rewardArenaPoints = 0;
        uint32 _rewardNextQuest = 0;
        uint32 _rewardXPDifficulty = 0;
        uint32 _startItem = 0;
        std::string _title;
        std::string _details;
        std::string _objectives;
        std::string _offerRewardText;
        std::string _requestItemsText;
        std::string _areaDescription;
        std::string _completedText;
        uint32 _rewardHonor = 0;
        float _rewardKillHonor = 0.f;
        int32  _rewardMoney = 0;
        uint32 _rewardBonusMoney = 0;
        uint32 _rewardDisplaySpell = 0;
        int32  _rewardSpell = 0;
        uint32 _poiContinent = 0;
        float  _poiX = 0.f;
        float  _poiY = 0.f;
        uint32 _poiPriority = 0;
        uint32 _emoteOnIncomplete = 0;
        uint32 _emoteOnComplete = 0;
        // new in 4.x
        uint32 _minimapTargetMark = 0;
        uint32 _rewardSkillId = 0;
        uint32 _rewardSkillPoints = 0;
        uint32 _rewardReputationMask = 0;
        uint32 _questGiverPortrait = 0;
        uint32 _questTurnInPortrait = 0;
        uint32 _requiredSpell = 0;
        std::string _questGiverTextWindow;
        std::string _questGiverTargetName;
        std::string _questTurnTextWindow;
        std::string _questTurnTargetName;
        uint32 _soundAccept = 0;
        uint32 _soundTurnIn = 0;
        bool _startsAtAreaTrigger = false;

        void SetStartAtAreaTrigger() { _startsAtAreaTrigger = true; }

        // quest_template_addon table (custom data)
        uint32 _maxLevel                = 0;
        uint32 _allowableClasses        = 0;
        uint32 _sourceSpellId           = 0;
        int32  _prevQuestId             = 0;
        uint32 _nextQuestId             = 0;
        int32  _exclusiveGroup          = 0;
        int32  _breadcrumbForQuestId    = 0;
        uint32 _rewardMailTemplateId    = 0;
        uint32 _rewardMailDelay         = 0;
        uint32 _requiredSkillId         = 0;
        uint32 _requiredSkillPoints     = 0;
        uint32 _requiredMinRepFaction   = 0;
        int32  _requiredMinRepValue     = 0;
        uint32 _requiredMaxRepFaction   = 0;
        int32  _requiredMaxRepValue     = 0;
        uint32 _startItemCount          = 0;
        uint32 _rewardMailSenderEntry   = 0;
        uint32 _specialFlags            = 0; // custom flags, not sniffed/WDB

        // Helpers
        static uint32 RoundXPValue(uint32 xp);
};

struct QuestStatusData
{
    QuestStatus Status = QUEST_STATUS_NONE;
    uint32 Timer = 0;
    uint16 ItemCount[QUEST_ITEM_OBJECTIVES_COUNT] = { };
    uint16 CreatureOrGOCount[QUEST_OBJECTIVES_COUNT] = { };
    uint16 PlayerCount = 0;
    bool Explored = false;
};
#endif
