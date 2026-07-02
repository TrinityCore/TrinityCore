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

#include "QuestDef.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "QuestPackets.h"
#include "QuestPools.h"
#include "World.h"

Quest::Quest(Field* questRecord)
{
    _id = questRecord[0].GetUInt32();
    _type = questRecord[1].GetUInt8();
    _level = questRecord[2].GetInt16();
    _minLevel = questRecord[3].GetUInt8();
    _zoneOrSort = questRecord[4].GetInt16();
    _questInfoID = questRecord[5].GetUInt16();
    _suggestedPlayers = questRecord[6].GetUInt8();
    _limitTime = questRecord[7].GetUInt32();
    _allowableRaces = questRecord[8].GetUInt32();
    _requiredFactionId1 = questRecord[9].GetUInt16();
    _requiredFactionId2 = questRecord[10].GetUInt16();
    _requiredFactionValue1 = questRecord[11].GetInt32();
    _requiredFactionValue2 = questRecord[12].GetInt32();
    _rewardNextQuest = questRecord[13].GetUInt32();
    _rewardXPDifficulty = questRecord[14].GetUInt8();
    _rewardMoney = questRecord[15].GetInt32();
    _rewardBonusMoney = questRecord[16].GetUInt32();
    _rewardDisplaySpell = questRecord[17].GetUInt32();
    _rewardSpell = questRecord[18].GetInt32();
    _rewardHonor = questRecord[19].GetUInt32();
    _rewardKillHonor = questRecord[20].GetFloat();
    _sourceItemId = questRecord[21].GetUInt32();
    _flags = questRecord[22].GetUInt32();
    _rewardTitleId = questRecord[23].GetUInt8();
    _requiredPlayerKills = questRecord[24].GetUInt8();
    _rewardTalents = questRecord[25].GetUInt8();
    _rewardArenaPoints = questRecord[26].GetUInt16();

    for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[27 + i * 2].GetUInt32();
        RewardItemCount[i] = questRecord[28 + i * 2].GetUInt16();

        if (RewardItemId[i])
            ++_rewItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[35 + i * 2].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[36 + i * 2].GetUInt16();

        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[47 + i * 3].GetUInt16();
        RewardFactionValue[i] = questRecord[48 + i * 3].GetInt32();
        RewardFactionOverride[i] = questRecord[49 + i * 3].GetInt32();
    }

    _poiContinent = questRecord[62].GetUInt16();
    _poiX = questRecord[63].GetFloat();
    _poiY = questRecord[64].GetFloat();
    _poiPriority = questRecord[65].GetUInt32();
    _logTitle = questRecord[66].GetString();
    _logDescription = questRecord[67].GetString();
    _questDescription = questRecord[68].GetString();
    _areaDescription = questRecord[69].GetString();
    _questCompletionLog = questRecord[70].GetString();

    for (uint32 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        RequiredNpcOrGo[i] = questRecord[71+i].GetInt32();
        RequiredNpcOrGoCount[i] = questRecord[75+i].GetUInt16();
        ObjectiveText[i] = questRecord[100+i].GetString();

        if (RequiredNpcOrGo[i])
            ++_reqCreatureOrGOcount;
    }

    for (uint32 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        ItemDrop[i] = questRecord[79+i].GetUInt32();
        ItemDropQuantity[i] = questRecord[83+i].GetUInt16();
    }

    for (uint32 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        RequiredItemId[i] = questRecord[87+i].GetUInt32();
        RequiredItemCount[i] = questRecord[93+i].GetUInt16();

        if (RequiredItemId[i])
            ++_reqItemsCount;
    }

    _rewardReputationMask = questRecord[99].GetUInt32();
    // int32 VerifiedBuild = questRecord[104].GetInt32();
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1+i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_details` has non-existing Emote{} ({}) set for quest {}. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        DetailsEmote[i] = fields[1+i].GetUInt16();
    }

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = fields[5+i].GetUInt32();
}

void Quest::LoadQuestRequestItems(Field* fields)
{
    _emoteOnComplete = fields[1].GetUInt16();
    _emoteOnIncomplete = fields[2].GetUInt16();

    if (!sEmotesStore.LookupEntry(_emoteOnComplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnComplete ({}) set for quest {}.", _emoteOnComplete, fields[0].GetUInt32());

    if (!sEmotesStore.LookupEntry(_emoteOnIncomplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnIncomplete ({}) set for quest {}.", _emoteOnIncomplete, fields[0].GetUInt32());

    _requestItemsText = fields[3].GetString();
}

void Quest::LoadQuestOfferReward(Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1 + i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward` has non-existing Emote{} ({}) set for quest {}. Skipped.", 1 + i, fields[1 + i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        OfferRewardEmote[i] = fields[1 + i].GetUInt16();
    }

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = fields[5 + i].GetUInt32();

    _offerRewardText = fields[9].GetString();
}

void Quest::LoadQuestTemplateAddon(Field* fields)
{
    _maxLevel = fields[1].GetUInt8();
    _allowableClasses = fields[2].GetUInt32();
    _sourceSpellID = fields[3].GetUInt32();
    _prevQuestID = fields[4].GetInt32();
    _nextQuestID = fields[5].GetUInt32();
    _exclusiveGroup = fields[6].GetInt32();
    _breadcrumbForQuestId = fields[7].GetInt32();
    _rewardMailTemplateId = fields[8].GetUInt32();
    _rewardMailDelay = fields[9].GetUInt32();
    _requiredSkillId = fields[10].GetUInt16();
    _requiredSkillPoints = fields[11].GetUInt16();
    _requiredMinRepFaction = fields[12].GetUInt16();
    _requiredMaxRepFaction = fields[13].GetUInt16();
    _requiredMinRepValue = fields[14].GetInt32();
    _requiredMaxRepValue = fields[15].GetInt32();
    _sourceItemIdCount = fields[16].GetUInt8();
    _specialFlags = fields[17].GetUInt8();

    if (_specialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        _flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

void Quest::LoadQuestMailSender(Field* fields)
{
    _rewardMailSenderEntry = fields[1].GetUInt32();
}

uint32 Quest::GetXPReward(Player const* player) const
{
    if (player)
    {
        int32 quest_level = (_level == -1 ? player->GetLevel() : _level);
        QuestXPEntry const* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->GetLevel()) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = RoundXPValue(diffFactor * xpentry->Difficulty[_rewardXPDifficulty] / 10);
        if (sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO))
        {
            uint32 minScaledXP = RoundXPValue(xpentry->Difficulty[_rewardXPDifficulty]) * sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO) / 100;
            xp = std::max(minScaledXP, xp);
        }

        return xp;
    }

    return 0;
}

/*static*/ bool Quest::IsTakingQuestEnabled(uint32 questId)
{
    if (!sQuestPoolMgr->IsQuestActive(questId))
        return false;

    return true;
}

void Quest::BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player, bool sendHiddenRewards) const
{
    if (!HasFlag(QUEST_FLAGS_HIDDEN_REWARDS) || sendHiddenRewards)
    {
        for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            if (!RewardChoiceItemId[i])
                continue;

            uint32 displayID = 0;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardChoiceItemId[i]))
                displayID = itemTemplate->GetDisplayId();

            rewards.UnfilteredChoiceItems.emplace_back(RewardChoiceItemId[i], RewardChoiceItemCount[i], displayID);
        }

        for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        {
            if (!RewardItemId[i])
                continue;

            uint32 displayID = 0;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardItemId[i]))
                displayID = itemTemplate->GetDisplayId();

            rewards.RewardItems.emplace_back(RewardItemId[i], RewardItemCount[i], displayID);
        }

        rewards.RewardMoney = GetRewOrReqMoney(player);
        rewards.RewardXPDifficulty = player->GetQuestXPReward(this);
    }

    rewards.RewardHonor = 10 * CalculateHonorGain(player->GetQuestLevel(this)); // rewarded honor points. Multiply with 10 to satisfy client
    rewards.RewardDisplaySpell = GetRewDisplaySpell(); // reward spell, this spell will display (icon) (cast if RewSpellCast == 0)
    rewards.RewardSpell = GetRewSpell();
    rewards.RewardTitleId = GetRewTitle();
    rewards.RewardTalents = GetBonusTalents();
    rewards.RewardArenaPoints = GetRewArenaPoints();

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        rewards.RewardFactionID[i] = RewardFactionId[i];
        rewards.RewardFactionValue[i] = RewardFactionValue[i];
        rewards.RewardFactionOverride[i] = RewardFactionOverride[i];
    }
}

int32 Quest::GetRewOrReqMoney(Player const* player) const
{
    // RequiredMoney: the amount is the negative copper sum.
    if (_rewardMoney < 0)
        return _rewardMoney;

    // RewardMoney: the positive amount
    if (!player || !player->IsMaxLevel())
        return int32(_rewardMoney * sWorld->getRate(RATE_MONEY_QUEST));
    else // At level cap, the money reward is the maximum amount between normal and bonus money reward
        return std::max(int32(GetRewMoneyMaxLevel()), int32(_rewardMoney * sWorld->getRate(RATE_MONEY_QUEST)));
}

uint32 Quest::GetRewMoneyMaxLevel() const
{
    // If Quest has flag to not give money on max level, it's 0
    if (HasFlag(QUEST_FLAGS_NO_MONEY_FROM_XP))
        return 0;

    // Else, return the rewarded copper sum modified by the rate
    return uint32(_rewardBonusMoney * sWorld->getRate(RATE_MONEY_MAX_LEVEL_QUEST));
}

bool Quest::IsAutoAccept() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT) && HasFlag(QUEST_FLAGS_AUTO_ACCEPT);
}

bool Quest::IsAutoComplete() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && (_type == 0 || HasFlag(QUEST_FLAGS_AUTOCOMPLETE));
}

bool Quest::IsRaidQuest(Difficulty difficulty) const
{
    switch (_questInfoID)
    {
        case QUEST_TYPE_RAID:
            return true;
        case QUEST_TYPE_RAID_10:
            return !(difficulty & RAID_DIFFICULTY_MASK_25MAN);
        case QUEST_TYPE_RAID_25:
            return difficulty & RAID_DIFFICULTY_MASK_25MAN;
        default:
            break;
    }

    if ((_flags & QUEST_FLAGS_RAID) != 0)
        return true;

    return false;
}

bool Quest::IsAllowedInRaid(Difficulty difficulty) const
{
    if (IsRaidQuest(difficulty))
        return true;

    return sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_RAID);
}

uint32 Quest::CalculateHonorGain(uint8 level) const
{
    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    uint32 honor = 0;

    if (GetRewHonor() > 0 || GetRewKillHonor() > 0.0f)
    {
        // values stored from 0.. for 1...
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level);
        if (!tc)
            return 0;

        honor = uint32(tc->Data * GetRewKillHonor() * 0.1f);
        honor += GetRewHonor();
    }

    return honor;
}

bool Quest::CanIncreaseRewardedQuestCounters() const
{
    // Dungeon Finder/Daily/Repeatable (if not weekly, monthly or seasonal) quests are never considered rewarded serverside.
    // This affects counters and client requests for completed quests.
    return (!IsDFQuest() && !IsDaily() && (!IsRepeatable() || IsWeekly() || IsMonthly() || IsSeasonal()));
}

void Quest::InitializeQueryData()
{
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc));
}

WorldPacket Quest::BuildQueryData(LocaleConstant loc) const
{
    WorldPackets::Quest::QueryQuestInfoResponse response;

    response.Info.LogTitle = GetLogTitle();
    response.Info.LogDescription = GetLogDescription();
    response.Info.QuestDescription = GetQuestDescription();
    response.Info.AreaDescription = GetAreaDescription();
    response.Info.QuestCompletionLog = GetQuestCompletionLog();

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        response.Info.ObjectiveText[i] = ObjectiveText[i];

    if (QuestLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(GetQuestId()))
    {
        ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle,           loc, response.Info.LogTitle);
        ObjectMgr::GetLocaleString(questTemplateLocale->LogDescription,     loc, response.Info.LogDescription);
        ObjectMgr::GetLocaleString(questTemplateLocale->QuestDescription,   loc, response.Info.QuestDescription);
        ObjectMgr::GetLocaleString(questTemplateLocale->AreaDescription,    loc, response.Info.AreaDescription);
        ObjectMgr::GetLocaleString(questTemplateLocale->QuestCompletionLog, loc, response.Info.QuestCompletionLog);

        for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
            ObjectMgr::GetLocaleString(questTemplateLocale->ObjectiveText[i], loc, response.Info.ObjectiveText[i]);
    }

    response.Info.QuestID = GetQuestId();
    response.Info.QuestType = GetQuestType();
    response.Info.QuestLevel = GetQuestLevel();
    response.Info.QuestMinLevel = GetMinLevel();
    response.Info.QuestSortID = GetZoneOrSort();

    response.Info.QuestInfoID = GetQuestInfoID();
    response.Info.SuggestedGroupNum = GetSuggestedPlayers();

    response.Info.RequiredFactionId[0] = GetRepObjectiveFaction();
    response.Info.RequiredFactionValue[0] = GetRepObjectiveValue();

    response.Info.RequiredFactionId[1] = GetRepObjectiveFaction2();
    response.Info.RequiredFactionValue[1] = GetRepObjectiveValue2();

    response.Info.RewardNextQuest = GetNextQuestInChain();
    response.Info.RewardXPDifficulty = GetXPDifficulty();

    if (!HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
        response.Info.RewardMoney = GetRewOrReqMoney();

    response.Info.RewardBonusMoney = GetRewMoneyMaxLevel();
    response.Info.RewardDisplaySpell = GetRewDisplaySpell();
    response.Info.RewardSpell = GetRewSpell();

    response.Info.RewardHonor = GetRewHonor();
    response.Info.RewardKillHonor = GetRewKillHonor();

    response.Info.StartItem = GetSrcItemId();
    response.Info.Flags = GetFlags();
    response.Info.RewardTitle = GetRewTitle();
    response.Info.RequiredPlayerKills = GetPlayersSlain();
    response.Info.RewardTalents = GetBonusTalents();
    response.Info.RewardArenaPoints = GetRewArenaPoints();
    response.Info.RewardFactionFlags = GetRewardReputationMask();

    if (!HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
    {
        for (uint8 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        {
            response.Info.RewardItems[i] = RewardItemId[i];
            response.Info.RewardAmount[i] = RewardItemCount[i];
        }

        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            response.Info.UnfilteredChoiceItems[i].ItemID = RewardChoiceItemId[i];
            response.Info.UnfilteredChoiceItems[i].Quantity = RewardChoiceItemCount[i];
        }
    }

    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        response.Info.RewardFactionID[i] = RewardFactionId[i];
        response.Info.RewardFactionValue[i] = RewardFactionValue[i];
        response.Info.RewardFactionOverride[i] = RewardFactionOverride[i];
    }

    response.Info.POIContinent = GetPOIContinent();
    response.Info.POIx = GetPOIx();
    response.Info.POIy = GetPOIy();
    response.Info.POIPriority = GetPOIPriority();

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        response.Info.RequiredNpcOrGo[i] = RequiredNpcOrGo[i];
        response.Info.RequiredNpcOrGoCount[i] = RequiredNpcOrGoCount[i];
        response.Info.ItemDrop[i] = ItemDrop[i];
        response.Info.ItemDropQuantity[i] = ItemDropQuantity[i];
    }

    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        response.Info.RequiredItemId[i] = RequiredItemId[i];
        response.Info.RequiredItemCount[i] = RequiredItemCount[i];
    }

    response.Write();
    response.ShrinkToFit();
    return response.Move();
}

void Quest::AddQuestLevelToTitle(std::string &title, int32 level)
{
    // Adds the quest level to the front of the quest title
    // example: [13] Westfall Stew

    std::stringstream questTitlePretty;
    questTitlePretty << "[" << level << "] " << title;
    title = questTitlePretty.str();
}

uint32 Quest::RoundXPValue(uint32 xp)
{
    if (xp <= 100)
        return 5 * ((xp + 2) / 5);
    else if (xp <= 500)
        return 10 * ((xp + 5) / 10);
    else if (xp <= 1000)
        return 25 * ((xp + 12) / 25);
    else
        return 50 * ((xp + 25) / 50);
}
