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
#include "DBCStores.h"
#include "Field.h"
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
    _method = questRecord[1].GetUInt8();
    _level = questRecord[2].GetInt16();
    _minLevel = questRecord[3].GetInt16();
    _zoneOrSort = questRecord[4].GetInt16();
    _type = questRecord[5].GetUInt16();
    _suggestedPlayers = questRecord[6].GetUInt8();
    _timeAllowed = questRecord[7].GetUInt32();
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
    _startItem = questRecord[21].GetUInt32();
    _flags = questRecord[22].GetUInt32();
    _minimapTargetMark = questRecord[23].GetUInt8();
    _rewardTitleId = questRecord[24].GetUInt8();
    _requiredPlayerKills = questRecord[25].GetUInt8();
    _rewardTalents = questRecord[26].GetUInt8();
    _rewardArenaPoints = questRecord[27].GetUInt16();
    _rewardSkillId = questRecord[28].GetUInt16();
    _rewardSkillPoints = questRecord[29].GetUInt8();
    _rewardReputationMask = questRecord[30].GetUInt8();
    _questGiverPortrait = questRecord[31].GetUInt32();
    _questTurnInPortrait = questRecord[32].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[33 + i * 2].GetUInt32();
        RewardItemIdCount[i] = questRecord[34 + i * 2].GetUInt16();

        if (RewardItemId[i])
            ++_rewItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[41 + i * 2].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[42 + i * 2].GetUInt16();

        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[53 + i * 3].GetUInt16();
        RewardFactionValueId[i] = questRecord[54 + i * 3].GetInt32();
        RewardFactionValueIdOverride[i] = questRecord[55 + i * 3].GetInt32();
    }

    _poiContinent = questRecord[68].GetUInt16();
    _poiX = questRecord[69].GetFloat();
    _poiY = questRecord[70].GetFloat();
    _poiPriority = questRecord[71].GetUInt32();
    _title = questRecord[72].GetString();
    _objectives = questRecord[73].GetString();
    _details = questRecord[74].GetString();
    _areaDescription = questRecord[75].GetString();
    _completedText = questRecord[76].GetString();

    for (uint32 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        RequiredNpcOrGo[i] = questRecord[77 + i].GetInt32();
        RequiredNpcOrGoCount[i] = questRecord[81 + i].GetUInt16();
        ObjectiveText[i] = questRecord[106 + i].GetString();

        if (RequiredNpcOrGo[i])
            ++_reqNpcOrGoCount;
    }

    for (uint32 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
    {
        ItemDrop[i] = questRecord[85 + i].GetUInt32();
        ItemDropQuantity[i] = questRecord[89 + i].GetUInt16();
    }

    for (uint32 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        RequiredItemId[i] = questRecord[93 + i].GetUInt32();
        RequiredItemCount[i] = questRecord[99 + i].GetUInt16();

        if (RequiredItemId[i])
            ++_reqItemsCount;
    }

    //int32 VerifiedBuild = questRecord[132].GetInt32();

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        DetailsEmote[i] = 0;
        DetailsEmoteDelay[i] = 0;
        OfferRewardEmote[i] = 0;
        OfferRewardEmoteDelay[i] = 0;
    }

    _requiredSpell = questRecord[105].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        RewardCurrencyId[i] = questRecord[110 + i].GetUInt16();
        RewardCurrencyCount[i] = questRecord[114 + i].GetUInt32();

        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;
    }

    for (uint32 i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
    {
        RequiredCurrencyId[i] = questRecord[118 + i].GetUInt16();
        RequiredCurrencyCount[i] = questRecord[122 + i].GetUInt32();

        if (RequiredCurrencyId[i])
            ++_reqCurrencyCount;
    }

    _questGiverTextWindow = questRecord[126].GetString();
    _questGiverTargetName = questRecord[127].GetString();
    _questTurnTextWindow = questRecord[128].GetString();
    _questTurnTargetName = questRecord[129].GetString();
    _soundAccept = questRecord[130].GetUInt16();
    _soundTurnIn = questRecord[131].GetUInt16();
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
   {
        if (!sEmotesStore.LookupEntry(fields[1+i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_details` has non-existing Emote%i (%u) set for quest %u. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        DetailsEmote[i] = fields[1 + i].GetUInt16();
    }

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = fields[5 + i].GetUInt32();
}

void Quest::LoadQuestRequestItems(Field* fields)
{
    _emoteOnComplete = fields[1].GetUInt16();
    _emoteOnIncomplete = fields[2].GetUInt16();

    if (!sEmotesStore.LookupEntry(_emoteOnComplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnComplete (%u) set for quest %u.", _emoteOnComplete, fields[0].GetUInt32());

    if (!sEmotesStore.LookupEntry(_emoteOnIncomplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnIncomplete (%u) set for quest %u.", _emoteOnIncomplete, fields[0].GetUInt32());

    _requestItemsText = fields[3].GetString();
}

void Quest::LoadQuestOfferReward(Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
   {
        if (!sEmotesStore.LookupEntry(fields[1+i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward` has non-existing Emote%i (%u) set for quest %u. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        OfferRewardEmote[i] = fields[1 + i].GetUInt16();
    }

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = fields[5 + i].GetUInt32();

    _offerRewardText = fields[9].GetString();
}

void Quest::LoadQuestTemplateAddon(Field* fields)
{
    _maxLevel = fields[1].GetUInt8();
    _allowableClasses = fields[2].GetUInt32();
    _sourceSpellId = fields[3].GetUInt32();
    _prevQuestId = fields[4].GetInt32();
    _nextQuestId = fields[5].GetUInt32();
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
    _startItemCount = fields[16].GetUInt8();
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
        int32 quest_level = (_level == -1 ? player->getLevel() : _level);
        const QuestXPEntry* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->getLevel()) + 20;
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

void Quest::BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const
{
    rewards.ChoiceItemCount = GetRewChoiceItemsCount();
    rewards.ItemCount = GetReqItemsCount();
    rewards.Money = GetRewOrReqMoney(player);
    rewards.XP = GetXPReward(player) * sWorld->getRate(RATE_XP_QUEST);
    rewards.Title = GetCharTitleId();
    rewards.FactionFlags = GetRewardReputationMask();
    rewards.SpellCompletionDisplayID = GetRewSpell();
    rewards.SpellCompletionID = GetRewSpellCast();
    rewards.SkillLineID = GetRewardSkillId();
    rewards.NumSkillUps = GetRewardSkillPoints();
    rewards.NumBonusTalents = GetBonusTalents();

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        rewards.ChoiceItems[i].ItemID = RewardChoiceItemId[i];
        rewards.ChoiceItems[i].Quantity = RewardChoiceItemCount[i];
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardChoiceItemId[i]))
            rewards.ChoiceItems[i].DisplayID = itemTemplate->GetDisplayID();
    }

    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        rewards.ItemID[i] = RewardItemId[i];
        rewards.ItemQty[i] = RewardItemIdCount[i];
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardItemId[i]))
            rewards.ItemDisplayID[i] = itemTemplate->GetDisplayID();
    }

    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        rewards.FactionID[i] = RewardFactionId[i];
        rewards.FactionValue[i] = RewardFactionValueId[i];
        rewards.FactionOverride[i] = RewardFactionValueIdOverride[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        rewards.CurrencyID[i] = RewardCurrencyId[i];
        rewards.CurrencyQty[i] = RewardCurrencyCount[i];
    }
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
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && _method == 0;
}

bool Quest::IsRaidQuest(Difficulty difficulty) const
{
    switch (_type)
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

    /*if (GetRewHonorAddition() > 0 || GetRewHonorMultiplier() > 0.0f)
    {
        // values stored from 0.. for 1...
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level);
        if (!tc)
            return 0;

        honor = uint32(tc->value * GetRewHonorMultiplier() * 0.1f);
        honor += GetRewHonorAddition();
    }*/

    return honor;
}

bool Quest::CanIncreaseRewardedQuestCounters() const
{
    // Dungeon Finder/Daily/Repeatable (if not weekly, monthly or seasonal) quests are never considered rewarded serverside.
    // This affects counters and client requests for completed quests.
    return (!IsDFQuest() && !IsDaily() && (!IsRepeatable() || IsWeekly() || IsMonthly() || IsSeasonal()));
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

void Quest::InitializeQueryData()
{
    WorldPacket queryTemp;
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
    {
        queryTemp = BuildQueryData(static_cast<LocaleConstant>(loc));
        QueryData[loc] = queryTemp;
    }
}

WorldPacket Quest::BuildQueryData(LocaleConstant loc) const
{
    WorldPackets::Quest::QueryQuestInfoResponse response;

    response.Info.QuestID = GetQuestId();

    std::string locQuestTitle = GetTitle();
    std::string locQuestDetails = GetDetails();
    std::string locQuestObjectives = GetObjectives();
    std::string locQuestAreaDescription = GetAreaDescription();
    std::string locQuestCompletedText = GetCompletedText();
    std::string locQuestGiverTextWindow = GetQuestGiverTextWindow();
    std::string locQuestGiverTargetName = GetQuestGiverTargetName();
    std::string locQuestTurnTextWindow = GetQuestTurnTextWindow();
    std::string locQuestTurnTargetName = GetQuestTurnTargetName();

    std::string locQuestObjectiveText[QUEST_OBJECTIVES_COUNT];
    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        locQuestObjectiveText[i] = ObjectiveText[i];

    if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(GetQuestId()))
    {
        ObjectMgr::GetLocaleString(localeData->Title, loc, locQuestTitle);
        ObjectMgr::GetLocaleString(localeData->Details, loc, locQuestDetails);
        ObjectMgr::GetLocaleString(localeData->Objectives, loc, locQuestObjectives);
        ObjectMgr::GetLocaleString(localeData->AreaDescription, loc, locQuestAreaDescription);
        ObjectMgr::GetLocaleString(localeData->CompletedText, loc, locQuestCompletedText);
        ObjectMgr::GetLocaleString(localeData->QuestGiverTextWindow, loc, locQuestGiverTextWindow);
        ObjectMgr::GetLocaleString(localeData->QuestGiverTargetName, loc, locQuestGiverTargetName);
        ObjectMgr::GetLocaleString(localeData->QuestTurnTextWindow, loc, locQuestTurnTextWindow);
        ObjectMgr::GetLocaleString(localeData->QuestTurnTargetName, loc, locQuestTurnTargetName);

        for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
            ObjectMgr::GetLocaleString(localeData->ObjectiveText[i], loc, locQuestObjectiveText[i]);
    }

    response.Info.QuestType = GetQuestMethod();
    response.Info.QuestLevel = GetQuestLevel();
    response.Info.QuestMinLevel = GetMinLevel();
    response.Info.QuestSortID = GetZoneOrSort();
    response.Info.QuestInfoID = GetType();

    response.Info.SuggestedGroupNum = GetSuggestedPlayers();

    response.Info.RequiredFactionId[0] = GetRepObjectiveFaction();
    response.Info.RequiredFactionValue[0] = GetRepObjectiveValue();

    response.Info.RequiredFactionId[1] = GetRepObjectiveFaction2();
    response.Info.RequiredFactionValue[1] = GetRepObjectiveValue2();

    response.Info.RewardNextQuest = GetNextQuestInChain();
    response.Info.RewardXPDifficulty = GetXPId();

    response.Info.RewardMoney = GetRewOrReqMoney();
    response.Info.RewardBonusMoney = GetRewMoneyMaxLevel();
    response.Info.RewardDisplaySpell = GetRewSpell();
    response.Info.RewardSpell = GetRewSpellCast();

    response.Info.RewardHonor = GetRewHonorAddition();
    response.Info.RewardKillHonor = GetRewHonorMultiplier();

    response.Info.StartItem = GetSrcItemId();
    response.Info.Flags = GetFlags();
    response.Info.MinimapTargetMark = GetMinimapTargetMark();

    response.Info.RewardTitle = GetCharTitleId();
    response.Info.RequiredPlayerKills = GetPlayersSlain();
    response.Info.RewardTalents = GetBonusTalents();
    response.Info.RewardArenaPoints = GetRewArenaPoints();
    response.Info.PortraitGiver = GetQuestGiverPortrait();
    response.Info.PortraitTurnIn = GetQuestTurnInPortrait();

    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        response.Info.RewardItems[i] = RewardItemId[i];
        response.Info.RewardAmount[i] = RewardItemIdCount[i];
    }

    for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        response.Info.UnfilteredChoiceItems[i].ItemID = RewardChoiceItemId[i];
        response.Info.UnfilteredChoiceItems[i].Quantity = RewardChoiceItemCount[i];
    }

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // reward factions ids
        response.Info.RewardFactionID[i] = RewardFactionId[i];

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // columnid+1 QuestFactionReward.dbc?
        response.Info.RewardFactionValue[i] = RewardFactionValueId[i];

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // unknown usage
        response.Info.RewardFactionValueOverride[i] = RewardFactionValueIdOverride[i];

    response.Info.POIContinent = GetPOIContinent();
    response.Info.POIx = GetPOIx();
    response.Info.POIy = GetPOIy();
    response.Info.POIPriority = GetPointOpt();

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        Quest::AddQuestLevelToTitle(locQuestTitle, GetQuestLevel());

    response.Info.LogTitle = locQuestTitle;
    response.Info.LogDescription = locQuestObjectives;
    response.Info.QuestDescription = locQuestDetails;
    response.Info.AreaDescription = locQuestAreaDescription;
    response.Info.QuestCompletionLog = locQuestCompletedText;

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

    response.Info.RequiredSpell = GetRequiredSpell();

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        response.Info.ObjectiveText[i] = locQuestObjectiveText[i];

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        response.Info.RewardCurrencyID[i] = RewardCurrencyId[i];
        response.Info.RewardCurrencyQty[i] = RewardCurrencyCount[i];
    }

    for (uint8 i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
    {
        response.Info.RequiredCurrencyID[i] = RequiredCurrencyId[i];
        response.Info.RequiredCurrencyQty[i] = RequiredCurrencyCount[i];
    }

    response.Info.PortraitGiverText = locQuestGiverTextWindow;
    response.Info.PortraitGiverName = locQuestGiverTargetName;
    response.Info.PortraitTurnintext = locQuestTurnTextWindow;
    response.Info.PortraitTurnInName = locQuestTurnTargetName;

    response.Info.AcceptedSoundKitID = GetSoundAccept();
    response.Info.CompleteSoundKitID = GetSoundTurnIn();

    response.Write();
    response.ShrinkToFit();
    return response.Move();
}

void Quest::AddQuestLevelToTitle(std::string& title, int32 level)
{
    // Adds the quest level to the front of the quest title
    // example: [13] Westfall Stew

    std::stringstream questTitlePretty;
    questTitlePretty << "[" << level << "] " << title;
    title = questTitlePretty.str();
}
