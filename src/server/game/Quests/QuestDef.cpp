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
#include "DB2Stores.h"
#include "Field.h"
#include "GameTables.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "World.h"

Quest::Quest(Field* questRecord)
{
    _id = questRecord[0].GetUInt32();
    _type = questRecord[1].GetUInt8();
    _level = questRecord[2].GetInt32();
    _scalingFactionGroup = questRecord[3].GetInt32();
    _maxScalingLevel = questRecord[4].GetInt32();
    _packageID = questRecord[5].GetUInt32();
    _minLevel = questRecord[6].GetInt32();
    _questSortID = questRecord[7].GetInt16();
    _questInfoID = questRecord[8].GetUInt16();
    _suggestedPlayers = questRecord[9].GetUInt8();
    _nextQuestInChain = questRecord[10].GetUInt32();
    _rewardXPDifficulty = questRecord[11].GetUInt32();
    _rewardXPMultiplier = questRecord[12].GetFloat();
    _rewardMoney = questRecord[13].GetUInt32();
    _rewardMoneyDifficulty = questRecord[14].GetUInt32();
    _rewardMoneyMultiplier = questRecord[15].GetFloat();
    _rewardBonusMoney = questRecord[16].GetUInt32();
    for (uint32 i = 0; i < QUEST_REWARD_DISPLAY_SPELL_COUNT; ++i)
        RewardDisplaySpell[i] = questRecord[17 + i].GetUInt32();

    _rewardSpell = questRecord[20].GetUInt32();
    _rewardHonor = questRecord[21].GetUInt32();
    _rewardKillHonor = questRecord[22].GetUInt32();
    _sourceItemId = questRecord[23].GetUInt32();
    _rewardArtifactXPDifficulty = questRecord[24].GetUInt32();
    _rewardArtifactXPMultiplier = questRecord[25].GetFloat();
    _rewardArtifactCategoryID = questRecord[26].GetUInt32();
    _flags = questRecord[27].GetUInt32();
    _flagsEx = questRecord[28].GetUInt32();
    _flagsEx2 = questRecord[29].GetUInt32();

    for (uint32 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[30 + i * 4].GetUInt32();
        RewardItemCount[i] = questRecord[31 + i * 4].GetUInt32();
        ItemDrop[i] = questRecord[32 + i * 4].GetUInt32();
        ItemDropQuantity[i] = questRecord[33 + i * 4].GetUInt32();

        if (RewardItemId[i])
            ++_rewItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[46 + i * 3].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[47 + i * 3].GetUInt32();
        RewardChoiceItemDisplayId[i] = questRecord[48 + i * 3].GetUInt32();

        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
    }

    _poiContinent = questRecord[64].GetUInt32();
    _poix = questRecord[65].GetFloat();
    _poiy = questRecord[66].GetFloat();
    _poiPriority = questRecord[67].GetUInt32();

    _rewardTitleId = questRecord[68].GetUInt32();
    _rewardArenaPoints = questRecord[69].GetUInt32();
    _rewardSkillId = questRecord[70].GetUInt32();
    _rewardSkillPoints = questRecord[71].GetUInt32();

    _questGiverPortrait = questRecord[72].GetUInt32();
    _questGiverPortraitMount = questRecord[73].GetUInt32();
    _questTurnInPortrait = questRecord[74].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[75 + i * 4].GetUInt32();
        RewardFactionValue[i] = questRecord[76 + i * 4].GetInt32();
        RewardFactionOverride[i] = questRecord[77 + i * 4].GetInt32();
        RewardFactionCapIn[i] = questRecord[78 + i * 4].GetUInt32();
    }

    _rewardReputationMask = questRecord[95].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        RewardCurrencyId[i] = questRecord[96 + i * 2].GetUInt32();
        RewardCurrencyCount[i] = questRecord[97 + i * 2].GetUInt32();

        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;
    }

    _soundAccept = questRecord[104].GetUInt32();
    _soundTurnIn = questRecord[105].GetUInt32();
    _areaGroupID = questRecord[106].GetUInt32();
    _limitTime = questRecord[107].GetUInt32();
    _allowableRaces.RawValue = questRecord[108].GetUInt64();
    _treasurePickerID = questRecord[109].GetInt32();
    _expansion = questRecord[110].GetInt32();
    _managedWorldStateID = questRecord[111].GetInt32();
    _questSessionBonus = questRecord[112].GetInt32();

    _logTitle = questRecord[113].GetString();
    _logDescription = questRecord[114].GetString();
    _questDescription = questRecord[115].GetString();
    _areaDescription = questRecord[116].GetString();
    _portraitGiverText = questRecord[117].GetString();
    _portraitGiverName = questRecord[118].GetString();
    _portraitTurnInText = questRecord[119].GetString();
    _portraitTurnInName = questRecord[120].GetString();
    _questCompletionLog = questRecord[121].GetString();
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1 + i].GetUInt16()))
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

    _emoteOnCompleteDelay = fields[3].GetUInt32();
    _emoteOnIncompleteDelay = fields[4].GetUInt32();
    _requestItemsText = fields[5].GetString();
}

void Quest::LoadQuestOfferReward(Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1 + i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward` has non-existing Emote%i (%u) set for quest %u. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
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
    _rewardMailTemplateId = fields[7].GetUInt32();
    _rewardMailDelay = fields[8].GetUInt32();
    _requiredSkillId = fields[9].GetUInt16();
    _requiredSkillPoints = fields[10].GetUInt16();
    _requiredMinRepFaction = fields[11].GetUInt16();
    _requiredMaxRepFaction = fields[12].GetUInt16();
    _requiredMinRepValue = fields[13].GetInt32();
    _requiredMaxRepValue = fields[14].GetInt32();
    _sourceItemIdCount = fields[15].GetUInt8();
    _specialFlags = fields[16].GetUInt8();
    _scriptId = sObjectMgr->GetScriptId(fields[17].GetString());

    if (_specialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        _flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

void Quest::LoadQuestMailSender(Field* fields)
{
    _rewardMailSenderEntry = fields[1].GetUInt32();
}

void Quest::LoadQuestObjective(Field* fields)
{
    QuestObjective obj;
    obj.QuestID = fields[0].GetUInt32();
    obj.ID = fields[1].GetUInt32();
    obj.Type = fields[2].GetUInt8();
    obj.StorageIndex = fields[3].GetInt8();
    obj.ObjectID = fields[4].GetInt32();
    obj.Amount = fields[5].GetInt32();
    obj.Flags = fields[6].GetUInt32();
    obj.Flags2 = fields[7].GetUInt32();
    obj.ProgressBarWeight = fields[8].GetFloat();
    obj.Description = fields[9].GetString();

    Objectives.push_back(obj);
}

void Quest::LoadQuestObjectiveVisualEffect(Field* fields)
{
    uint32 objID = fields[1].GetUInt32();

    for (QuestObjective& obj : Objectives)
    {
        if (obj.ID == objID)
        {
            uint8 effectIndex = fields[3].GetUInt8();
            if (effectIndex >= obj.VisualEffects.size())
                obj.VisualEffects.resize(effectIndex + 1, 0);

            obj.VisualEffects[effectIndex] = fields[4].GetInt32();
            break;
        }
    }
}

uint32 Quest::XPValue(Player const* player) const
{
    if (player)
    {
        uint32 questLevel = player->GetQuestLevel(this);
        QuestXPEntry const* questXp = sQuestXPStore.LookupEntry(questLevel);
        if (!questXp || _rewardXPDifficulty >= 10)
            return 0;

        float multiplier = 1.0f;
        if (questLevel != player->getLevel())
            multiplier = sXpGameTable.GetRow(std::min<int32>(player->getLevel(), questLevel))->Divisor / sXpGameTable.GetRow(player->getLevel())->Divisor;

        int32 diffFactor = 2 * (questLevel + (_level == -1 ? 0 : 5) - player->getLevel()) + 10;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = diffFactor * questXp->Difficulty[_rewardXPDifficulty] * _rewardXPMultiplier / 10 * multiplier;
        if (xp <= 100)
            xp = 5 * ((xp + 2) / 5);
        else if (xp <= 500)
            xp = 10 * ((xp + 5) / 10);
        else if (xp <= 1000)
            xp = 25 * ((xp + 12) / 25);
        else
            xp = 50 * ((xp + 25) / 50);

        return xp;
    }

    return 0;
}

uint32 Quest::MoneyValue(Player const* player) const
{
    if (QuestMoneyRewardEntry const* money = sQuestMoneyRewardStore.LookupEntry(player->GetQuestLevel(this)))
        return money->Difficulty[GetRewMoneyDifficulty()] * GetMoneyMultiplier();
    else
        return 0;
}

void Quest::BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const
{
    rewards.ChoiceItemCount         = GetRewChoiceItemsCount();
    rewards.ItemCount               = GetRewItemsCount();
    rewards.Money                   = player->GetQuestMoneyReward(this);
    rewards.XP                      = player->GetQuestXPReward(this);
    rewards.ArtifactCategoryID      = GetArtifactCategoryId();
    rewards.Title                   = GetRewTitle();
    rewards.FactionFlags            = GetRewardReputationMask();
    for (uint32 i = 0; i < QUEST_REWARD_DISPLAY_SPELL_COUNT; ++i)
        rewards.SpellCompletionDisplayID[i] = RewardDisplaySpell[i];

    rewards.SpellCompletionID       = GetRewSpell();
    rewards.SkillLineID             = GetRewardSkillId();
    rewards.NumSkillUps             = GetRewardSkillPoints();
    rewards.TreasurePickerID        = GetTreasurePickerId();

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        rewards.ChoiceItems[i].Item.ItemID = RewardChoiceItemId[i];
        rewards.ChoiceItems[i].Quantity = RewardChoiceItemCount[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        rewards.ItemID[i] = RewardItemId[i];
        rewards.ItemQty[i] = RewardItemCount[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        rewards.FactionID[i] = RewardFactionId[i];
        rewards.FactionValue[i] = RewardFactionValue[i];
        rewards.FactionOverride[i] = RewardFactionOverride[i];
        rewards.FactionCapIn[i] = RewardFactionCapIn[i];
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
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && _type == QUEST_TYPE_AUTOCOMPLETE;
}

bool Quest::IsRaidQuest(Difficulty difficulty) const
{
    switch (_questInfoID)
    {
        case QUEST_INFO_RAID:
            return true;
        case QUEST_INFO_RAID_10:
            return difficulty == DIFFICULTY_10_N || difficulty == DIFFICULTY_10_HC;
        case QUEST_INFO_RAID_25:
            return difficulty == DIFFICULTY_25_N || difficulty == DIFFICULTY_25_HC;
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

uint32 Quest::CalculateHonorGain(uint8 /*level*/) const
{
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

    response.Allow = true;
    response.QuestID = GetQuestId();

    response.Info.LogTitle = GetLogTitle();
    response.Info.LogDescription = GetLogDescription();
    response.Info.QuestDescription = GetQuestDescription();
    response.Info.AreaDescription = GetAreaDescription();
    response.Info.QuestCompletionLog = GetQuestCompletionLog();
    response.Info.PortraitGiverText = GetPortraitGiverText();
    response.Info.PortraitGiverName = GetPortraitGiverName();
    response.Info.PortraitTurnInText = GetPortraitTurnInText();
    response.Info.PortraitTurnInName = GetPortraitTurnInName();

    if (loc != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(GetQuestId()))
        {
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle,           loc, response.Info.LogTitle);
            ObjectMgr::GetLocaleString(questTemplateLocale->LogDescription,     loc, response.Info.LogDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->QuestDescription,   loc, response.Info.QuestDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->AreaDescription,    loc, response.Info.AreaDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->QuestCompletionLog, loc, response.Info.QuestCompletionLog);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverText,  loc, response.Info.PortraitGiverText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverName,  loc, response.Info.PortraitGiverName);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInText, loc, response.Info.PortraitTurnInText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInName, loc, response.Info.PortraitTurnInName);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        AddQuestLevelToTitle(response.Info.LogTitle, GetQuestLevel());

    response.Info.QuestID = GetQuestId();
    response.Info.QuestType = GetQuestType();
    response.Info.QuestLevel = GetQuestLevel();
    response.Info.QuestScalingFactionGroup = GetQuestScalingFactionGroup();
    response.Info.QuestMaxScalingLevel = GetQuestMaxScalingLevel();
    response.Info.QuestPackageID = GetQuestPackageID();
    response.Info.QuestMinLevel = GetMinLevel();
    response.Info.QuestSortID = GetZoneOrSort();
    response.Info.QuestInfoID = GetQuestInfoID();
    response.Info.SuggestedGroupNum = GetSuggestedPlayers();
    response.Info.RewardNextQuest = GetNextQuestInChain();
    response.Info.RewardXPDifficulty = GetXPDifficulty();
    response.Info.RewardXPMultiplier = GetXPMultiplier();

    if (!HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
        response.Info.RewardMoney = GetRewMoney();

    response.Info.RewardMoneyDifficulty = GetRewMoneyDifficulty();
    response.Info.RewardMoneyMultiplier = GetMoneyMultiplier();
    response.Info.RewardBonusMoney = GetRewMoneyMaxLevel();
    for (uint8 i = 0; i < QUEST_REWARD_DISPLAY_SPELL_COUNT; ++i)
        response.Info.RewardDisplaySpell[i] = RewardDisplaySpell[i];

    response.Info.RewardSpell = GetRewSpell();

    response.Info.RewardHonor = GetRewHonor();
    response.Info.RewardKillHonor = GetRewKillHonor();

    response.Info.RewardArtifactXPDifficulty = GetArtifactXPDifficulty();
    response.Info.RewardArtifactXPMultiplier = GetArtifactXPMultiplier();
    response.Info.RewardArtifactCategoryID = GetArtifactCategoryId();

    response.Info.StartItem = GetSrcItemId();
    response.Info.Flags = GetFlags();
    response.Info.FlagsEx = GetFlagsEx();
    response.Info.FlagsEx2 = GetFlagsEx2();
    response.Info.RewardTitle = GetRewTitle();
    response.Info.RewardArenaPoints = GetRewArenaPoints();
    response.Info.RewardSkillLineID = GetRewardSkillId();
    response.Info.RewardNumSkillUps = GetRewardSkillPoints();
    response.Info.RewardFactionFlags = GetRewardReputationMask();
    response.Info.PortraitGiver = GetQuestGiverPortrait();
    response.Info.PortraitGiverMount = GetQuestGiverPortraitMount();
    response.Info.PortraitTurnIn = GetQuestTurnInPortrait();

    for (uint8 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        response.Info.ItemDrop[i] = ItemDrop[i];
        response.Info.ItemDropQuantity[i] = ItemDropQuantity[i];
    }

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
        response.Info.RewardFactionCapIn[i] = RewardFactionCapIn[i];
    }

    response.Info.POIContinent = GetPOIContinent();
    response.Info.POIx = GetPOIx();
    response.Info.POIy = GetPOIy();
    response.Info.POIPriority = GetPOIPriority();

    response.Info.AllowableRaces = GetAllowableRaces();
    response.Info.TreasurePickerID = GetTreasurePickerId();
    response.Info.Expansion = GetExpansion();
    response.Info.ManagedWorldStateID = GetManagedWorldStateId();
    response.Info.QuestSessionBonus = 0; //GetQuestSessionBonus(); // this is only sent while quest session is active

    for (QuestObjective const& questObjective : GetObjectives())
    {
        response.Info.Objectives.push_back(questObjective);

        if (loc != LOCALE_enUS)
        {
            if (QuestObjectivesLocale const* questObjectivesLocale = sObjectMgr->GetQuestObjectivesLocale(questObjective.ID))
                ObjectMgr::GetLocaleString(questObjectivesLocale->Description, loc, response.Info.Objectives.back().Description);
        }
    }

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        response.Info.RewardCurrencyID[i] = RewardCurrencyId[i];
        response.Info.RewardCurrencyQty[i] = RewardCurrencyCount[i];
    }

    response.Info.AcceptedSoundKitID = GetSoundAccept();
    response.Info.CompleteSoundKitID = GetSoundTurnIn();
    response.Info.AreaGroupID = GetAreaGroupID();
    response.Info.TimeAllowed = GetLimitTime();

    return *response.Write();
}

void Quest::AddQuestLevelToTitle(std::string& title, int32 level)
{
    // Adds the quest level to the front of the quest title
    // example: [13] Westfall Stew
    title = Trinity::StringFormat("[%d] %s", level, title);
}
