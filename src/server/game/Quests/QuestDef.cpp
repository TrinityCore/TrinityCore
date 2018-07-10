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

#include "QuestDef.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "QuestPackets.h"
#include "World.h"

Quest::Quest(Field* questRecord, LocaleConstant localeConstantDefault)
{
    LocaleConstant lc = _localeConstantDefault = localeConstantDefault;
    _response[lc] = new WorldPackets::Quest::QueryQuestInfoResponse();

    _id = questRecord[0].GetUInt32();
    _method = questRecord[1].GetUInt8();
    _level = questRecord[2].GetInt16();
    _minLevel = questRecord[3].GetUInt8();
    _zoneOrSort = questRecord[4].GetInt16();
    _type = questRecord[5].GetUInt16();
    _suggestedPlayers = questRecord[6].GetUInt8();
    _timeAllowed = questRecord[7].GetUInt32();
    _allowableRaces = questRecord[8].GetUInt16();
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
    _rewardTitleId = questRecord[23].GetUInt8();
    _requiredPlayerKills = questRecord[24].GetUInt8();
    _rewardTalents = questRecord[25].GetUInt8();
    _rewardArenaPoints = questRecord[26].GetUInt16();

    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[27 + i * 2].GetUInt32();
        RewardItemIdCount[i] = questRecord[28 + i * 2].GetUInt16();

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

    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[47 + i * 3].GetUInt16();
        RewardFactionValueId[i] = questRecord[48 + i * 3].GetInt32();
        RewardFactionValueIdOverride[i] = questRecord[49 + i * 3].GetInt32();
    }

    _poiContinent = questRecord[62].GetUInt16();
    _poiX = questRecord[63].GetFloat();
    _poiY = questRecord[64].GetFloat();
    _poiPriority = questRecord[65].GetUInt32();
    _title[lc] = questRecord[66].GetString();
    _objectives[lc] = questRecord[67].GetString();
    _details[lc] = questRecord[68].GetString();
    _areaDescription[lc] = questRecord[69].GetString();
    _completedText[lc] = questRecord[70].GetString();

    for (uint32 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        RequiredNpcOrGo[i] = questRecord[71+i].GetInt32();
        RequiredNpcOrGoCount[i] = questRecord[75+i].GetUInt16();
        ObjectiveText[lc][i] = questRecord[100+i].GetString();

        if (RequiredNpcOrGo[i])
            ++_reqCreatureOrGOcount;
    }

    for (uint32 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
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

    // int8 Unknown0 = questRecord[99].GetUInt8();
    // int32 VerifiedBuild = questRecord[104].GetInt32();
}

void Quest::LoadQuestDetails(LocaleConstant /* lc */, Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1+i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_details` has non-existing Emote%i (%u) set for quest %u. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        DetailsEmote[i] = fields[1+i].GetUInt16();
    }

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = fields[5+i].GetUInt32();
}

void Quest::LoadQuestRequestItems(LocaleConstant lc, Field* fields)
{
    _emoteOnComplete = fields[1].GetUInt16();
    _emoteOnIncomplete = fields[2].GetUInt16();

    if (!sEmotesStore.LookupEntry(_emoteOnComplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnComplete (%u) set for quest %u.", _emoteOnComplete, fields[0].GetUInt32());

    if (!sEmotesStore.LookupEntry(_emoteOnIncomplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnIncomplete (%u) set for quest %u.", _emoteOnIncomplete, fields[0].GetUInt32());

    _requestItemsText[lc] = fields[3].GetString();
}

void Quest::LoadQuestOfferReward(LocaleConstant lc, Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1 + i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward` has non-existing Emote%i (%u) set for quest %u. Skipped.", 1 + i, fields[1 + i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        OfferRewardEmote[i] = fields[1 + i].GetUInt16();
    }

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = fields[5 + i].GetUInt32();

    _offerRewardText[lc] = fields[9].GetString();
}

void Quest::LoadQuestTemplateAddon(LocaleConstant /* lc */, Field* fields)
{
    _maxLevel = fields[1].GetUInt8();
    _requiredClasses = fields[2].GetUInt32();
    _sourceSpellid = fields[3].GetUInt32();
    _prevQuestId = fields[4].GetInt32();
    _nextQuestId = fields[5].GetUInt32();
    _exclusiveGroup = fields[6].GetInt32();
    _rewardMailTemplateId = fields[7].GetUInt32();
    _rewardMailDelay = fields[8].GetUInt32();
    _requiredSkillId = fields[9].GetUInt16();
    _requiredSkillPoints = fields[10].GetUInt16();
    _requiredMinRepFaction = fields[11].GetUInt16();
    _requiredMaxRepFaction = fields[12].GetUInt16();
    _requiredMinRepValue = fields[13].GetInt32();
    _requiredMaxRepValue = fields[14].GetInt32();
    _startItemCount = fields[15].GetUInt8();
    _specialFlags = fields[16].GetUInt8();

    if (_specialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        _flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

void Quest::LoadQuestMailSender(LocaleConstant /* lc */, Field* fields)
{
    _rewardMailSenderEntry = fields[1].GetUInt32();
}

uint32 Quest::XPValue(Player* player) const
{
    if (player)
    {
        int32 quest_level = (_level == -1 ? player->getLevel() : _level);
        QuestXPEntry const* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->getLevel()) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = RoundXPValue(diffFactor * xpentry->Exp[_rewardXPDifficulty] / 10);
        if (sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO))
        {
            uint32 minScaledXP = RoundXPValue(xpentry->Exp[_rewardXPDifficulty]) * sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO) / 100;
            xp = std::max(minScaledXP, xp);
        }

        return xp;
    }

    return 0;
}

int32 Quest::GetRewOrReqMoney() const
{
    // RequiredMoney: the amount is the negative copper sum.
    if (_rewardMoney <= 0)
        return _rewardMoney;

    // RewardMoney: the positive amount
    return int32(_rewardMoney * sWorld->getRate(RATE_MONEY_QUEST));
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
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && (_method == 0 || HasFlag(QUEST_FLAGS_AUTOCOMPLETE));
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

    if (GetRewHonorAddition() > 0 || GetRewHonorMultiplier() > 0.0f)
    {
        // values stored from 0.. for 1...
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level);
        if (!tc)
            return 0;

        honor = uint32(tc->value * GetRewHonorMultiplier() * 0.1f);
        honor += GetRewHonorAddition();
    }

    return honor;
}

bool Quest::CanIncreaseRewardedQuestCounters() const
{
    // Dungeon Finder/Daily/Repeatable (if not weekly, monthly or seasonal) quests are never considered rewarded serverside.
    // This affects counters and client requests for completed quests.
    return (!IsDFQuest() && !IsDaily() && (!IsRepeatable() || IsWeekly() || IsMonthly() || IsSeasonal()));
}

void Quest::BuildQueryData(LocaleConstant lc) const
{
    if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(GetQuestId()))
    {
        _response[lc]->Info.Title[lc] = GetTitle(lc);
        _response[lc]->Info.Objectives[lc] = GetDetails(lc);
        _response[lc]->Info.Details[lc] = GetObjectives(lc);
        _response[lc]->Info.AreaDescription[lc] = GetAreaDescription(lc);
        _response[lc]->Info.CompletedText[lc] = GetCompletedText(lc);

        if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
            Quest::AddQuestLevelToTitle(_response[lc]->Info.Title[lc], GetQuestLevel());

        std::string locQuestObjectiveText[QUEST_OBJECTIVES_COUNT];
        for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        {
            _response[lc]->Info.ObjectiveText[lc][i] = ObjectiveText[lc][i];
        }   
    }

    _response[lc]->Info.QuestID = GetQuestId();
    _response[lc]->Info.QuestMethod = GetQuestMethod();
    _response[lc]->Info.QuestLevel = GetQuestLevel();
    _response[lc]->Info.QuestMinLevel = GetMinLevel();
    _response[lc]->Info.QuestSortID = GetZoneOrSort();

    _response[lc]->Info.QuestType = GetType();
    _response[lc]->Info.SuggestedGroupNum = GetSuggestedPlayers();

    _response[lc]->Info.RequiredFactionId[0] = GetRepObjectiveFaction();
    _response[lc]->Info.RequiredFactionValue[0] = GetRepObjectiveValue();

    _response[lc]->Info.RequiredFactionId[1] = GetRepObjectiveFaction2();
    _response[lc]->Info.RequiredFactionValue[1] = GetRepObjectiveValue2();

    _response[lc]->Info.RewardNextQuest = GetNextQuestInChain();
    _response[lc]->Info.RewardXPDifficulty = GetXPId();

    _response[lc]->Info.RewardMoney = GetRewOrReqMoney();
    _response[lc]->Info.RewardBonusMoney = GetRewMoneyMaxLevel();
    _response[lc]->Info.RewardDisplaySpell = GetRewSpell();
    _response[lc]->Info.RewardSpell = GetRewSpellCast();

    _response[lc]->Info.RewardHonor = GetRewHonorAddition();
    _response[lc]->Info.RewardKillHonor = GetRewHonorMultiplier();

    _response[lc]->Info.StartItem = GetSrcItemId();
    _response[lc]->Info.Flags = GetFlags();
    _response[lc]->Info.RewardTitleId = GetCharTitleId();
    _response[lc]->Info.RequiredPlayerKills = GetPlayersSlain();
    _response[lc]->Info.RewardTalents = GetBonusTalents();
    _response[lc]->Info.RewardArenaPoints = GetRewArenaPoints();

    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        _response[lc]->Info.RewardItems[i] = RewardItemId[i];
        _response[lc]->Info.RewardAmount[i] = RewardItemIdCount[i];
    }

    for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        _response[lc]->Info.UnfilteredChoiceItems[i].ItemID = RewardChoiceItemId[i];
        _response[lc]->Info.UnfilteredChoiceItems[i].Quantity = RewardChoiceItemCount[i];
    }

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // reward factions ids
        _response[lc]->Info.RewardFactionID[i] = RewardFactionId[i];

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // columnid+1 QuestFactionReward.dbc?
        _response[lc]->Info.RewardFactionValue[i] = RewardFactionValueId[i];

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // unk (0)
        _response[lc]->Info.RewardFactionValueOverride[i] = RewardFactionValueIdOverride[i];

    _response[lc]->Info.POIContinent = GetPOIContinent();
    _response[lc]->Info.POIx = GetPOIx();
    _response[lc]->Info.POIy = GetPOIy();
    _response[lc]->Info.POIPriority = GetPointOpt();

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        _response[lc]->Info.RequiredNpcOrGo[i] = RequiredNpcOrGo[i];
        _response[lc]->Info.RequiredNpcOrGoCount[i] = RequiredNpcOrGoCount[i];
        _response[lc]->Info.ItemDrop[i] = ItemDrop[i];
    }

    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        _response[lc]->Info.RequiredItemId[i] = RequiredItemId[i];
        _response[lc]->Info.RequiredItemCount[i] = RequiredItemCount[i];
    }
}

void Quest::InitializeQueryData(LocaleConstant lc)
{
    BuildQueryDataRaw(lc);
    BuildQueryDataLocale(lc);
    _response[lc]->Write();
}

WorldPacket* Quest::GetQueryDataRef(LocaleConstant lc)
{
    if (!_response[lc])
    {
        GetQueryData(lc);
    }
    return (WorldPacket*) _response[lc]->GetRawPacket();
}

WorldPacket Quest::GetQueryData(LocaleConstant lc)
{
    if (!_response[lc])
    {
        _response[lc] = new WorldPackets::Quest::QueryQuestInfoResponse();
        BuildQueryDataRaw(lc);
        BuildQueryDataLocale(lc);
    }
    const WorldPacket* wp = _response[lc]->Write(lc);
    return *wp;
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
