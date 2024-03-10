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
#include "ConditionMgr.h"
#include "DB2Stores.h"
#include "Field.h"
#include "GameTables.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "QuestPools.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"

Quest::Quest(Field* questRecord)
{
    _id = questRecord[0].GetUInt32();
    _type = questRecord[1].GetUInt8();
    _packageID = questRecord[2].GetUInt32();
    _contentTuningID = questRecord[3].GetInt32();
    _questSortID = questRecord[4].GetInt16();
    _questInfoID = questRecord[5].GetUInt16();
    _suggestedPlayers = questRecord[6].GetUInt8();
    _nextQuestInChain = questRecord[7].GetUInt32();
    _rewardXPDifficulty = questRecord[8].GetUInt32();
    _rewardXPMultiplier = questRecord[9].GetFloat();
    _rewardMoneyDifficulty = questRecord[10].GetUInt32();
    _rewardMoneyMultiplier = questRecord[11].GetFloat();
    _rewardBonusMoney = questRecord[12].GetUInt32();
    _rewardSpell = questRecord[13].GetUInt32();
    _rewardHonor = questRecord[14].GetUInt32();
    _rewardKillHonor = questRecord[15].GetUInt32();
    _sourceItemId = questRecord[16].GetUInt32();
    _rewardArtifactXPDifficulty = questRecord[17].GetUInt32();
    _rewardArtifactXPMultiplier = questRecord[18].GetFloat();
    _rewardArtifactCategoryID = questRecord[19].GetUInt32();
    _flags = questRecord[20].GetUInt32();
    _flagsEx = questRecord[21].GetUInt32();
    _flagsEx2 = questRecord[22].GetUInt32();

    for (uint32 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[23 + i * 4].GetUInt32();
        RewardItemCount[i] = questRecord[24 + i * 4].GetUInt32();
        ItemDrop[i] = questRecord[25 + i * 4].GetUInt32();
        ItemDropQuantity[i] = questRecord[26 + i * 4].GetUInt32();

        if (RewardItemId[i])
            ++_rewItemsCount;
    }

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[39 + i * 3].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[40 + i * 3].GetUInt32();
        RewardChoiceItemDisplayId[i] = questRecord[41 + i * 3].GetUInt32();

        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
    }

    _poiContinent = questRecord[57].GetUInt32();
    _poix = questRecord[58].GetFloat();
    _poiy = questRecord[59].GetFloat();
    _poiPriority = questRecord[60].GetUInt32();

    _rewardTitleId = questRecord[61].GetUInt32();
    _rewardArenaPoints = questRecord[62].GetUInt32();
    _rewardSkillId = questRecord[63].GetUInt32();
    _rewardSkillPoints = questRecord[64].GetUInt32();

    _questGiverPortrait = questRecord[65].GetUInt32();
    _questGiverPortraitMount = questRecord[66].GetUInt32();
    _questGiverPortraitModelSceneId = questRecord[67].GetInt32();
    _questTurnInPortrait = questRecord[68].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[69 + i * 4].GetUInt32();
        RewardFactionValue[i] = questRecord[70 + i * 4].GetInt32();
        RewardFactionOverride[i] = questRecord[71 + i * 4].GetInt32();
        RewardFactionCapIn[i] = questRecord[72 + i * 4].GetInt32();
    }

    _rewardReputationMask = questRecord[89].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        RewardCurrencyId[i] = questRecord[90 + i * 2].GetUInt32();
        RewardCurrencyCount[i] = questRecord[91 + i * 2].GetUInt32();

        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;
    }

    _soundAccept = questRecord[98].GetUInt32();
    _soundTurnIn = questRecord[99].GetUInt32();
    _areaGroupID = questRecord[100].GetUInt32();
    _limitTime = questRecord[101].GetInt64();
    _allowableRaces.RawValue = questRecord[102].GetUInt64();
    _treasurePickerID = questRecord[103].GetInt32();
    _expansion = questRecord[104].GetInt32();
    _managedWorldStateID = questRecord[105].GetInt32();
    _questSessionBonus = questRecord[106].GetInt32();

    _logTitle = questRecord[107].GetString();
    _logDescription = questRecord[108].GetString();
    _questDescription = questRecord[109].GetString();
    _areaDescription = questRecord[110].GetString();
    _portraitGiverText = questRecord[111].GetString();
    _portraitGiverName = questRecord[112].GetString();
    _portraitTurnInText = questRecord[113].GetString();
    _portraitTurnInName = questRecord[114].GetString();
    _questCompletionLog = questRecord[115].GetString();
}

Quest::~Quest()
{
    for (QuestObjective& objective : Objectives)
        delete objective.CompletionEffect;
}

void Quest::LoadRewardDisplaySpell(Field* fields)
{
    uint32 spellId = fields[1].GetUInt32();
    uint32 playerConditionId = fields[2].GetUInt32();
    uint32 type = fields[3].GetUInt32();

    if (!sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE))
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_reward_display_spell` has non-existing Spell ({}) set for quest {}. Skipped.", spellId, fields[0].GetUInt32());
        return;
    }

    if (playerConditionId && !sPlayerConditionStore.LookupEntry(playerConditionId))
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_reward_display_spell` has non-existing PlayerCondition ({}) set for quest {} and spell {}. Set to 0.", playerConditionId, fields[0].GetUInt32(), spellId);
        playerConditionId = 0;
    }

    if (type >= AsUnderlyingType(QuestCompleteSpellType::Max))
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_reward_display_spell` invalid type value ({}) set for quest {} and spell {}. Set to 0.", type, fields[0].GetUInt32(), spellId);
        type = AsUnderlyingType(QuestCompleteSpellType::LegacyBehavior);
    }

    RewardDisplaySpell.emplace_back(spellId, playerConditionId, QuestCompleteSpellType(type));
}

void Quest::LoadRewardChoiceItems(Field* fields)
{
    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemType[i] = LootItemType(fields[1 + i].GetUInt8());
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (!sEmotesStore.LookupEntry(fields[1 + i].GetUInt16()))
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_details` has non-existing Emote{} ({}) set for quest {}. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
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
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnComplete ({}) set for quest {}.", _emoteOnComplete, fields[0].GetUInt32());

    if (!sEmotesStore.LookupEntry(_emoteOnIncomplete))
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items` has non-existing EmoteOnIncomplete ({}) set for quest {}.", _emoteOnIncomplete, fields[0].GetUInt32());

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
            TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward` has non-existing Emote{} ({}) set for quest {}. Skipped.", 1+i, fields[1+i].GetUInt16(), fields[0].GetUInt32());
            continue;
        }

        OfferRewardEmote[i] = fields[1 + i].GetInt16();
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
    _scriptId = sObjectMgr->GetScriptId(fields[18].GetString());

    if (_specialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        _flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

void Quest::LoadQuestMailSender(Field* fields)
{
    _rewardMailSenderEntry = fields[1].GetUInt32();
}

void Quest::LoadQuestObjective(Field* fields)
{
    QuestObjective& obj = Objectives.emplace_back();
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

    bool hasCompletionEffect = std::any_of(fields + 10, fields + 15, [](Field const& f) { return !f.IsNull(); });
    if (hasCompletionEffect)
    {
        obj.CompletionEffect = new QuestObjectiveAction();
        if (!fields[10].IsNull())
            obj.CompletionEffect->GameEventId = fields[10].GetUInt32();
        if (!fields[11].IsNull())
            obj.CompletionEffect->SpellId = fields[11].GetUInt32();
        if (!fields[12].IsNull())
            obj.CompletionEffect->ConversationId = fields[12].GetUInt32();
        if (!fields[13].IsNull())
            obj.CompletionEffect->UpdatePhaseShift = fields[13].GetBool();
        if (!fields[14].IsNull())
            obj.CompletionEffect->UpdateZoneAuras = fields[14].GetBool();
    }

    _usedQuestObjectiveTypes[obj.Type] = true;
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

void Quest::LoadConditionalConditionalQuestDescription(Field* fields)
{
    LocaleConstant locale = GetLocaleByName(fields[4].GetStringView());
    if (locale >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_description_conditional` has invalid locale {} set for quest {}. Skipped.", fields[4].GetCString(), fields[0].GetUInt32());
        return;
    }

    auto itr = std::find_if(_conditionalQuestDescription.begin(), _conditionalQuestDescription.end(), [fields](QuestConditionalText const& text)
    {
        return text.PlayerConditionId == fields[1].GetInt32() && text.QuestgiverCreatureId == fields[2].GetInt32();
    });

    QuestConditionalText& text = itr != _conditionalQuestDescription.end() ? *itr : _conditionalQuestDescription.emplace_back();
    text.PlayerConditionId = fields[1].GetInt32();
    text.QuestgiverCreatureId = fields[2].GetInt32();
    ObjectMgr::AddLocaleString(fields[3].GetStringView(), locale, text.Text);
}

void Quest::LoadConditionalConditionalRequestItemsText(Field* fields)
{
    LocaleConstant locale = GetLocaleByName(fields[4].GetStringView());
    if (locale >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_request_items_conditional` has invalid locale {} set for quest {}. Skipped.", fields[4].GetCString(), fields[0].GetUInt32());
        return;
    }

    auto itr = std::find_if(_conditionalRequestItemsText.begin(), _conditionalRequestItemsText.end(), [fields](QuestConditionalText const& text)
    {
        return text.PlayerConditionId == fields[1].GetInt32() && text.QuestgiverCreatureId == fields[2].GetInt32();
    });

    QuestConditionalText& text = itr != _conditionalRequestItemsText.end() ? *itr : _conditionalRequestItemsText.emplace_back();
    text.PlayerConditionId = fields[1].GetInt32();
    text.QuestgiverCreatureId = fields[2].GetInt32();
    ObjectMgr::AddLocaleString(fields[3].GetStringView(), locale, text.Text);
}

void Quest::LoadConditionalConditionalOfferRewardText(Field* fields)
{
    LocaleConstant locale = GetLocaleByName(fields[4].GetStringView());
    if (locale >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_offer_reward_conditional` has invalid locale {} set for quest {}. Skipped.", fields[4].GetCString(), fields[0].GetUInt32());
        return;
    }

    auto itr = std::find_if(_conditionalOfferRewardText.begin(), _conditionalOfferRewardText.end(), [fields](QuestConditionalText const& text)
    {
        return text.PlayerConditionId == fields[1].GetInt32() && text.QuestgiverCreatureId == fields[2].GetInt32();
    });

    QuestConditionalText& text = itr != _conditionalOfferRewardText.end() ? *itr : _conditionalOfferRewardText.emplace_back();
    text.PlayerConditionId = fields[1].GetInt32();
    text.QuestgiverCreatureId = fields[2].GetInt32();
    ObjectMgr::AddLocaleString(fields[3].GetStringView(), locale, text.Text);
}

void Quest::LoadConditionalConditionalQuestCompletionLog(Field* fields)
{
    LocaleConstant locale = GetLocaleByName(fields[4].GetStringView());
    if (locale >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("sql.sql", "Table `quest_completion_log_conditional` has invalid locale {} set for quest {}. Skipped.", fields[4].GetCString(), fields[0].GetUInt32());
        return;
    }

    auto itr = std::find_if(_conditionalQuestCompletionLog.begin(), _conditionalQuestCompletionLog.end(), [fields](QuestConditionalText const& text)
    {
        return text.PlayerConditionId == fields[1].GetInt32() && text.QuestgiverCreatureId == fields[2].GetInt32();
    });

    QuestConditionalText& text = itr != _conditionalQuestCompletionLog.end() ? *itr : _conditionalQuestCompletionLog.emplace_back();
    text.PlayerConditionId = fields[1].GetInt32();
    text.QuestgiverCreatureId = fields[2].GetInt32();
    ObjectMgr::AddLocaleString(fields[3].GetStringView(), locale, text.Text);
}

uint32 Quest::XPValue(Player const* player) const
{
    return XPValue(player, GetContentTuningId(), _rewardXPDifficulty, _rewardXPMultiplier, _expansion);
}

uint32 Quest::XPValue(Player const* player, uint32 contentTuningId, uint32 xpDifficulty, float xpMultiplier /*= 1.0f*/, int32 expansion /*= -1*/)
{
    if (player)
    {
        uint32 questLevel = player->GetQuestLevel(contentTuningId);
        QuestXPEntry const* questXp = sQuestXPStore.LookupEntry(questLevel);
        if (!questXp || xpDifficulty >= 10)
            return 0;

        uint32 xp = questXp->Difficulty[xpDifficulty];

        int32 diffFactor = 2 * (questLevel - player->GetLevel()) + 12;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        xp = diffFactor * xp * xpMultiplier / 10;
        if (player->GetLevel() >= GetMaxLevelForExpansion(CURRENT_EXPANSION - 1) && player->GetSession()->GetExpansion() == CURRENT_EXPANSION && expansion >= 0 && expansion < CURRENT_EXPANSION)
            xp = uint32(xp / 9.0f);

        xp = RoundXPValue(xp);

        if (sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO))
        {
            uint32 minScaledXP = RoundXPValue(questXp->Difficulty[xpDifficulty] * xpMultiplier) * sWorld->getIntConfig(CONFIG_MIN_QUEST_SCALED_XP_RATIO) / 100;
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

uint32 Quest::MoneyValue(Player const* player) const
{
    if (QuestMoneyRewardEntry const* money = sQuestMoneyRewardStore.LookupEntry(player->GetQuestLevel(this)))
        return money->Difficulty[GetRewMoneyDifficulty()] * GetMoneyMultiplier();
    else
        return 0;
}

uint32 Quest::MaxMoneyValue() const
{
    uint32 value = 0;
    if (Optional<ContentTuningLevels> questLevels = sDB2Manager.GetContentTuningData(GetContentTuningId(), 0))
        if (QuestMoneyRewardEntry const* money = sQuestMoneyRewardStore.LookupEntry(questLevels->MaxLevel))
            value = money->Difficulty[GetRewMoneyDifficulty()] * GetMoneyMultiplier();

    return value;
}

uint32 Quest::GetMaxMoneyReward() const
{
    return MaxMoneyValue() * sWorld->getRate(RATE_MONEY_QUEST);
}

Optional<QuestTagType> Quest::GetQuestTag() const
{
    if (QuestInfoEntry const* questInfo = sQuestInfoStore.LookupEntry(GetQuestInfoID()))
        return static_cast<QuestTagType>(questInfo->Type);

    return {};
}

bool Quest::IsImportant() const
{
    if (QuestInfoEntry const* questInfo = sQuestInfoStore.LookupEntry(GetQuestInfoID()))
        return (questInfo->Modifiers & 0x400) != 0;

    return false;
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
    auto displaySpellItr = rewards.SpellCompletionDisplayID.begin();
    for (QuestRewardDisplaySpell displaySpell : RewardDisplaySpell)
    {
        if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(displaySpell.PlayerConditionId))
            if (!ConditionMgr::IsPlayerMeetingCondition(player, playerCondition))
                continue;

        *displaySpellItr = displaySpell.SpellId;
        if (++displaySpellItr == rewards.SpellCompletionDisplayID.end())
            break;
    }

    rewards.SpellCompletionID       = GetRewSpell();
    rewards.SkillLineID             = GetRewardSkillId();
    rewards.NumSkillUps             = GetRewardSkillPoints();
    rewards.TreasurePickerID        = GetTreasurePickerId();

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        rewards.ChoiceItems[i].LootItemType = RewardChoiceItemType[i];
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
    if (HasFlag(QUEST_FLAGS_NO_MONEY_FOR_XP))
        return 0;

    // Else, return the rewarded copper sum modified by the rate
    return uint32(_rewardBonusMoney * sWorld->getRate(RATE_MONEY_MAX_LEVEL_QUEST));
}

bool Quest::IsAutoAccept() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT) && HasFlag(QUEST_FLAGS_AUTO_ACCEPT);
}

bool Quest::IsTurnIn() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && _type == QUEST_TYPE_TURNIN;
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

    if ((_flags & QUEST_FLAGS_RAID_GROUP_OK) != 0)
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

        honor = uint32(tc->Data * GetRewHonorMultiplier() * 0.1f);
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
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc), nullptr);
}

WorldPacket Quest::BuildQueryData(LocaleConstant loc, Player* player) const
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
    std::transform(GetConditionalQuestDescription().begin(), GetConditionalQuestDescription().end(), std::back_inserter(response.Info.ConditionalQuestDescription), [loc](QuestConditionalText const& text)
    {
        std::string_view content = text.Text[LOCALE_enUS];
        ObjectMgr::GetLocaleString(text.Text, loc, content);
        return WorldPackets::Quest::ConditionalQuestText { text.PlayerConditionId, text.QuestgiverCreatureId, content };
    });

    std::transform(GetConditionalQuestCompletionLog().begin(), GetConditionalQuestCompletionLog().end(), std::back_inserter(response.Info.ConditionalQuestCompletionLog), [loc](QuestConditionalText const& text)
    {
        std::string_view content = text.Text[LOCALE_enUS];
        ObjectMgr::GetLocaleString(text.Text, loc, content);
        return WorldPackets::Quest::ConditionalQuestText { text.PlayerConditionId, text.QuestgiverCreatureId, content };
    });

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

    response.Info.QuestID = GetQuestId();
    response.Info.QuestType = GetQuestType();
    response.Info.ContentTuningID = GetContentTuningId();
    response.Info.QuestPackageID = GetQuestPackageID();
    response.Info.QuestSortID = GetZoneOrSort();
    response.Info.QuestInfoID = GetQuestInfoID();
    response.Info.SuggestedGroupNum = GetSuggestedPlayers();
    response.Info.RewardNextQuest = GetNextQuestInChain();
    response.Info.RewardXPDifficulty = GetXPDifficulty();
    response.Info.RewardXPMultiplier = GetXPMultiplier();

    if (!HasFlag(QUEST_FLAGS_HIDE_REWARD))
        response.Info.RewardMoney = player ? player->GetQuestMoneyReward(this) : GetMaxMoneyReward();

    response.Info.RewardMoneyDifficulty = GetRewMoneyDifficulty();
    response.Info.RewardMoneyMultiplier = GetMoneyMultiplier();
    response.Info.RewardBonusMoney = GetRewMoneyMaxLevel();
    for (QuestRewardDisplaySpell displaySpell : RewardDisplaySpell)
    {
        WorldPackets::Quest::QuestCompleteDisplaySpell& rewardDisplaySpell = response.Info.RewardDisplaySpell.emplace_back();
        rewardDisplaySpell.SpellID = displaySpell.SpellId;
        rewardDisplaySpell.PlayerConditionID = displaySpell.PlayerConditionId;
        rewardDisplaySpell.Type = int32(displaySpell.Type);
    }

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
    response.Info.PortraitGiverModelSceneID = GetQuestGiverPortraitModelSceneId();
    response.Info.PortraitTurnIn = GetQuestTurnInPortrait();

    for (uint8 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        response.Info.ItemDrop[i] = ItemDrop[i];
        response.Info.ItemDropQuantity[i] = ItemDropQuantity[i];
    }

    if (!HasFlag(QUEST_FLAGS_HIDE_REWARD))
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
    response.Info.QuestGiverCreatureID = 0; // only sent during npc interaction

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

    response.Write();
    response.ShrinkToFit();
    return response.Move();
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
