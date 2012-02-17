/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "Define.h"
#include "DatabaseEnv.h"
#include "SharedDefines.h"

#include <string>
#include <vector>

class Player;

class ObjectMgr;

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

enum QuestFailedReasons
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

enum QuestShareMessages
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
    QUEST_PARTY_MSG_NOT_IN_PARTY            = 10
};

enum __QuestTradeSkill
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
    QUEST_TRSKILL_JEWELCRAFTING  = 14,
};

enum QuestStatus
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

enum __QuestGiverStatus
{
    DIALOG_STATUS_NONE                     = 0,
    DIALOG_STATUS_UNAVAILABLE              = 1,
    DIALOG_STATUS_LOW_LEVEL_AVAILABLE      = 2,
    DIALOG_STATUS_LOW_LEVEL_REWARD_REP     = 3,
    DIALOG_STATUS_LOW_LEVEL_AVAILABLE_REP  = 4,
    DIALOG_STATUS_INCOMPLETE               = 5,
    DIALOG_STATUS_REWARD_REP               = 6,
    DIALOG_STATUS_AVAILABLE_REP            = 7,
    DIALOG_STATUS_AVAILABLE                = 8,
    DIALOG_STATUS_REWARD2                  = 9,             // no yellow dot on minimap
    DIALOG_STATUS_REWARD                   = 10             // yellow dot on minimap
};

enum __QuestFlags
{
    // Flags used at server and sent to client
    QUEST_FLAGS_NONE           = 0x00000000,
    QUEST_FLAGS_STAY_ALIVE     = 0x00000001,                // Not used currently
    QUEST_FLAGS_PARTY_ACCEPT   = 0x00000002,                // Not used currently. If player in party, all players that can accept this quest will receive confirmation box to accept quest CMSG_QUEST_CONFIRM_ACCEPT/SMSG_QUEST_CONFIRM_ACCEPT
    QUEST_FLAGS_EXPLORATION    = 0x00000004,                // Not used currently
    QUEST_FLAGS_SHARABLE       = 0x00000008,                // Can be shared: Player::CanShareQuest()
    //QUEST_FLAGS_NONE2        = 0x00000010,                // Not used currently
    QUEST_FLAGS_EPIC           = 0x00000020,                // Not used currently: Unsure of content
    QUEST_FLAGS_RAID           = 0x00000040,                // Not used currently
    QUEST_FLAGS_TBC            = 0x00000080,                // Not used currently: Available if TBC expansion enabled only
    QUEST_FLAGS_DELIVER_MORE   = 0x00000100,                // Not used currently: _DELIVER_MORE Quest needs more than normal _q-item_ drops from mobs
    QUEST_FLAGS_HIDDEN_REWARDS = 0x00000200,                // Items and money rewarded only sent in SMSG_QUESTGIVER_OFFER_REWARD (not in SMSG_QUESTGIVER_QUEST_DETAILS or in client quest log(SMSG_QUEST_QUERY_RESPONSE))
    QUEST_FLAGS_AUTO_REWARDED  = 0x00000400,                // These quests are automatically rewarded on quest complete and they will never appear in quest log client side.
    QUEST_FLAGS_TBC_RACES      = 0x00000800,                // Not used currently: Blood elf/Draenei starting zone quests
    QUEST_FLAGS_DAILY          = 0x00001000,                // Used to know quest is Daily one
    QUEST_FLAGS_REPEATABLE     = 0x00002000,                // Used on repeatable quests (3.0.0+)
    QUEST_FLAGS_UNAVAILABLE    = 0x00004000,                // Used on quests that are not generically available
    QUEST_FLAGS_WEEKLY         = 0x00008000,
    QUEST_FLAGS_AUTOCOMPLETE   = 0x00010000,                // auto complete
    QUEST_FLAGS_SPECIAL_ITEM   = 0x00020000,                // has something to do with RequiredItemId and SourceItemId
    QUEST_FLAGS_OBJ_TEXT       = 0x00040000,                // use Objective text as Complete text
    QUEST_FLAGS_AUTO_ACCEPT    = 0x00080000,                // The client recognizes this flag as auto-accept. However, NONE of the current quests (3.3.5a) have this flag. Maybe blizz used to use it, or will use it in the future.

    // Trinity flags for set SpecialFlags in DB if required but used only at server
    QUEST_TRINITY_FLAGS_REPEATABLE           = 0x00100000,   // Set by 1 in SpecialFlags from DB
    QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT = 0x00200000,   // Set by 2 in SpecialFlags from DB (if reequired area explore, spell SPELL_EFFECT_QUEST_COMPLETE casting, table `*_script` command SCRIPT_COMMAND_QUEST_EXPLORED use, set from script)
    QUEST_TRINITY_FLAGS_AUTO_ACCEPT          = 0x00400000,  // Set by 4 in SpecialFlags in DB if the quest is to be auto-accepted.
    QUEST_TRINITY_FLAGS_DF_QUEST             = 0x00800000,  // Set by 8 in SpecialFlags in DB if the quest is used by Dungeon Finder.

    QUEST_TRINITY_FLAGS_DB_ALLOWED = 0xFFFFF | QUEST_TRINITY_FLAGS_REPEATABLE | QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT | QUEST_TRINITY_FLAGS_AUTO_ACCEPT | QUEST_TRINITY_FLAGS_DF_QUEST,

    // Trinity flags for internal use only
    QUEST_TRINITY_FLAGS_DELIVER              = 0x04000000,   // Internal flag computed only
    QUEST_TRINITY_FLAGS_SPEAKTO              = 0x08000000,   // Internal flag computed only
    QUEST_TRINITY_FLAGS_KILL_OR_CAST         = 0x10000000,   // Internal flag computed only
    QUEST_TRINITY_FLAGS_TIMED                = 0x20000000,   // Internal flag computed only
    QUEST_TRINITY_FLAGS_PLAYER_KILL          = 0x40000000,   // Internal flag computed only
};

struct QuestLocale
{
    QuestLocale() { ObjectiveText.resize(QUEST_OBJECTIVES_COUNT); }

    StringVector Title;
    StringVector Details;
    StringVector Objectives;
    StringVector OfferRewardText;
    StringVector RequestItemsText;
    StringVector EndText;
    StringVector CompletedText;
    std::vector< StringVector > ObjectiveText;
};

// This Quest class provides a convenient way to access a few pretotaled (cached) quest details,
// all base quest information, and any utility functions such as generating the amount of
// xp to give
class Quest
{
    friend class ObjectMgr;
    public:
        Quest(Field* questRecord);
        uint32 XPValue(Player* player) const;

        bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }
        void SetFlag(uint32 flag) { Flags |= flag; }

        // table data accessors:
        uint32 GetQuestId() const { return Id; }
        uint32 GetQuestMethod() const { return Method; }
        int32  GetZoneOrSort() const { return ZoneOrSort; }
        uint32 GetMinLevel() const { return MinLevel; }
        uint32 GetMaxLevel() const { return MaxLevel; }
        uint32 GetQuestLevel() const { return Level; }
        uint32 GetType() const { return Type; }
        uint32 GetRequiredClasses() const { return RequiredClasses; }
        uint32 GetRequiredRaces() const { return RequiredRaces; }
        uint32 GetRequiredSkill() const { return RequiredSkillId; }
        uint32 GetRequiredSkillValue() const { return RequiredSkillPoints; }
        uint32 GetRepObjectiveFaction() const { return RequiredFactionId1; }
        int32  GetRepObjectiveValue() const { return RequiredFactionValue1; }
        uint32 GetRepObjectiveFaction2() const { return RequiredFactionId2; }
        int32  GetRepObjectiveValue2() const { return RequiredFactionValue2; }
        uint32 GetRequiredMinRepFaction() const { return RequiredMinRepFaction; }
        int32  GetRequiredMinRepValue() const { return RequiredMinRepValue; }
        uint32 GetRequiredMaxRepFaction() const { return RequiredMaxRepFaction; }
        int32  GetRequiredMaxRepValue() const { return RequiredMaxRepValue; }
        uint32 GetSuggestedPlayers() const { return SuggestedPlayers; }
        uint32 GetLimitTime() const { return LimitTime; }
        int32  GetPrevQuestId() const { return PrevQuestId; }
        int32  GetNextQuestId() const { return NextQuestId; }
        int32  GetExclusiveGroup() const { return ExclusiveGroup; }
        uint32 GetNextQuestInChain() const { return NextQuestIdChain; }
        uint32 GetCharTitleId() const { return RewardTitleId; }
        uint32 GetPlayersSlain() const { return RequiredPlayerKills; }
        uint32 GetBonusTalents() const { return RewardTalents; }
        int32  GetRewArenaPoints() const {return RewardArenaPoints; }
        uint32 GetXPId() const { return RewardXPId; }
        uint32 GetSrcItemId() const { return SourceItemId; }
        uint32 GetSrcItemCount() const { return SourceItemIdCount; }
        uint32 GetSrcSpell() const { return SourceSpellid; }
        std::string GetTitle() const { return Title; }
        std::string GetDetails() const { return Details; }
        std::string GetObjectives() const { return Objectives; }
        std::string GetOfferRewardText() const { return OfferRewardText; }
        std::string GetRequestItemsText() const { return RequestItemsText; }
        std::string GetEndText() const { return EndText; }
        std::string GetCompletedText() const { return CompletedText; }
        int32  GetRewOrReqMoney() const;
        uint32 GetRewHonorAddition() const { return RewardHonor; }
        float GetRewHonorMultiplier() const { return RewardHonorMultiplier; }
        uint32 GetRewMoneyMaxLevel() const { return RewardMoneyMaxLevel; }
                                                            // use in XP calculation at client
        uint32 GetRewSpell() const { return RewardSpell; }
        int32  GetRewSpellCast() const { return RewardSpellCast; }
        uint32 GetRewMailTemplateId() const { return RewardMailTemplateId; }
        uint32 GetRewMailDelaySecs() const { return RewardMailDelay; }
        uint32 GetPointMapId() const { return PointMapId; }
        float  GetPointX() const { return PointX; }
        float  GetPointY() const { return PointY; }
        uint32 GetPointOpt() const { return PointOption; }
        uint32 GetIncompleteEmote() const { return EmoteOnIncomplete; }
        uint32 GetCompleteEmote() const { return EmoteOnComplete; }
        uint32 GetQuestStartScript() const { return StartScript; }
        uint32 GetQuestCompleteScript() const { return CompleteScript; }
        bool   IsRepeatable() const { return Flags & QUEST_TRINITY_FLAGS_REPEATABLE; }
        bool   IsAutoAccept() const;
        bool   IsAutoComplete() const;
        uint32 GetFlags() const { return Flags; }
        bool   IsDaily() const { return Flags & QUEST_FLAGS_DAILY; }
        bool   IsWeekly() const { return Flags & QUEST_FLAGS_WEEKLY; }
        bool   IsSeasonal() const { return (ZoneOrSort == -QUEST_SORT_SEASONAL || ZoneOrSort == -QUEST_SORT_SPECIAL || ZoneOrSort == -QUEST_SORT_LUNAR_FESTIVAL || ZoneOrSort == -QUEST_SORT_MIDSUMMER || ZoneOrSort == -QUEST_SORT_BREWFEST || ZoneOrSort == -QUEST_SORT_LOVE_IS_IN_THE_AIR || ZoneOrSort == -QUEST_SORT_NOBLEGARDEN); }
        bool   IsDailyOrWeekly() const { return Flags & (QUEST_FLAGS_DAILY | QUEST_FLAGS_WEEKLY); }
        bool   IsRaidQuest() const { return Type == QUEST_TYPE_RAID || Type == QUEST_TYPE_RAID_10 || Type == QUEST_TYPE_RAID_25; }
        bool   IsAllowedInRaid() const;
        bool   IsDFQuest() const { return Flags & QUEST_TRINITY_FLAGS_DF_QUEST; }
        uint32 CalculateHonorGain(uint8 level) const;

        // multiple values
        std::string ObjectiveText[QUEST_OBJECTIVES_COUNT];
        uint32 RequiredItemId[QUEST_ITEM_OBJECTIVES_COUNT];
        uint32 RequiredItemCount[QUEST_ITEM_OBJECTIVES_COUNT];
        uint32 RequiredSourceItemId[QUEST_SOURCE_ITEM_IDS_COUNT];
        uint32 RequiredSourceItemCount[QUEST_SOURCE_ITEM_IDS_COUNT];
        int32  RequiredNpcOrGo[QUEST_OBJECTIVES_COUNT];   // >0 Creature <0 Gameobject
        uint32 RequiredNpcOrGoCount[QUEST_OBJECTIVES_COUNT];
        uint32 RequiredSpellCast[QUEST_OBJECTIVES_COUNT];
        uint32 RewardChoiceItemId[QUEST_REWARD_CHOICES_COUNT];
        uint32 RewardChoiceItemCount[QUEST_REWARD_CHOICES_COUNT];
        uint32 RewardItemId[QUEST_REWARDS_COUNT];
        uint32 RewardItemIdCount[QUEST_REWARDS_COUNT];
        uint32 RewardFactionId[QUEST_REPUTATIONS_COUNT];
        int32  RewardFactionValueId[QUEST_REPUTATIONS_COUNT];
        int32  RewardFactionValueIdOverride[QUEST_REPUTATIONS_COUNT];
        uint32 DetailsEmote[QUEST_EMOTE_COUNT];
        uint32 DetailsEmoteDelay[QUEST_EMOTE_COUNT];
        uint32 OfferRewardEmote[QUEST_EMOTE_COUNT];
        uint32 OfferRewardEmoteDelay[QUEST_EMOTE_COUNT];

        uint32 GetReqItemsCount() const { return m_reqitemscount; }
        uint32 GetReqCreatureOrGOcount() const { return m_reqCreatureOrGOcount; }
        uint32 GetRewChoiceItemsCount() const { return m_rewchoiceitemscount; }
        uint32 GetRewItemsCount() const { return m_rewitemscount; }

        typedef std::vector<int32> PrevQuests;
        PrevQuests prevQuests;
        typedef std::vector<uint32> PrevChainQuests;
        PrevChainQuests prevChainQuests;

        // cached data
    private:
        uint32 m_reqitemscount;
        uint32 m_reqCreatureOrGOcount;
        uint32 m_rewchoiceitemscount;
        uint32 m_rewitemscount;

        // table data
    protected:
        uint32 Id;
        uint32 Method;
        int32  ZoneOrSort;
        uint32 MinLevel;
        uint32 MaxLevel;
        int32  Level;
        uint32 Type;
        uint32 RequiredClasses;
        uint32 RequiredRaces;
        uint32 RequiredSkillId;
        uint32 RequiredSkillPoints;
        uint32 RequiredFactionId1;
        int32  RequiredFactionValue1;
        uint32 RequiredFactionId2;
        int32  RequiredFactionValue2;
        uint32 RequiredMinRepFaction;
        int32  RequiredMinRepValue;
        uint32 RequiredMaxRepFaction;
        int32  RequiredMaxRepValue;
        uint32 SuggestedPlayers;
        uint32 LimitTime;
        uint32 Flags;
        uint32 RewardTitleId;
        uint32 RequiredPlayerKills;
        uint32 RewardTalents;
        int32  RewardArenaPoints;
        int32  PrevQuestId;
        int32  NextQuestId;
        int32  ExclusiveGroup;
        uint32 NextQuestIdChain;
        uint32 RewardXPId;
        uint32 SourceItemId;
        uint32 SourceItemIdCount;
        uint32 SourceSpellid;
        std::string Title;
        std::string Details;
        std::string Objectives;
        std::string OfferRewardText;
        std::string RequestItemsText;
        std::string EndText;
        std::string CompletedText;
        uint32 RewardHonor;
        float RewardHonorMultiplier;
        int32  RewardOrRequiredMoney;
        uint32 RewardMoneyMaxLevel;
        uint32 RewardSpell;
        int32  RewardSpellCast;
        uint32 RewardMailTemplateId;
        uint32 RewardMailDelay;
        uint32 PointMapId;
        float  PointX;
        float  PointY;
        uint32 PointOption;
        uint32 EmoteOnIncomplete;
        uint32 EmoteOnComplete;
        uint32 StartScript;
        uint32 CompleteScript;
};

struct QuestStatusData
{
    QuestStatusData(): Status(QUEST_STATUS_NONE), Explored(false), Timer(0), PlayerCount(0)
    {
        memset(ItemCount, 0, QUEST_ITEM_OBJECTIVES_COUNT * sizeof(uint16));
        memset(CreatureOrGOCount, 0, QUEST_OBJECTIVES_COUNT * sizeof(uint16));
    }

    QuestStatus Status;
    uint32 Timer;
    uint16 ItemCount[QUEST_ITEM_OBJECTIVES_COUNT];
    uint16 CreatureOrGOCount[QUEST_OBJECTIVES_COUNT];
    uint16 PlayerCount;
    bool Explored;
};
#endif
