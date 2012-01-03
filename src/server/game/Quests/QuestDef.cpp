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

#include "QuestDef.h"
#include "Player.h"
#include "World.h"

Quest::Quest(Field* questRecord)
{
    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt32();
    Level = questRecord[2].GetInt32();
    MinLevel = questRecord[3].GetUInt32();
    MaxLevel = questRecord[4].GetUInt32();
    ZoneOrSort = questRecord[5].GetInt32();
    Type = questRecord[6].GetUInt32();
    SuggestedPlayers = questRecord[7].GetUInt32();
    LimitTime = questRecord[8].GetUInt32();
    RequiredClasses = questRecord[9].GetUInt32();
    RequiredRaces = questRecord[10].GetUInt32();
    RequiredSkillId = questRecord[11].GetUInt32();
    RequiredSkillPoints = questRecord[12].GetUInt32();
    RequiredFactionId1 = questRecord[13].GetUInt32();
    RequiredFactionId2 = questRecord[14].GetUInt32();
    RequiredFactionValue1 = questRecord[15].GetInt32();
    RequiredFactionValue2 = questRecord[16].GetInt32();
    RequiredMinRepFaction = questRecord[17].GetUInt32();
    RequiredMaxRepFaction = questRecord[18].GetUInt32();
    RequiredMinRepValue = questRecord[19].GetInt32();
    RequiredMaxRepValue = questRecord[20].GetInt32();
    PrevQuestId = questRecord[21].GetInt32();
    NextQuestId = questRecord[22].GetInt32();
    ExclusiveGroup = questRecord[23].GetInt32();
    NextQuestIdChain = questRecord[24].GetUInt32();
    RewardXPId = questRecord[25].GetUInt32();
    RewardOrRequiredMoney = questRecord[26].GetInt32();
    RewardMoneyMaxLevel = questRecord[27].GetUInt32();
    RewardSpell = questRecord[28].GetUInt32();
    RewardSpellCast = questRecord[29].GetInt32();
    RewardHonor = questRecord[30].GetUInt32();
    RewardHonorMultiplier = questRecord[31].GetFloat();
    RewardMailTemplateId = questRecord[32].GetUInt32();
    RewardMailDelay = questRecord[33].GetUInt32();
    SourceItemId = questRecord[34].GetUInt32();
    SourceItemIdCount = questRecord[35].GetUInt32();
    SourceSpellid = questRecord[36].GetUInt32();
    Flags = questRecord[37].GetUInt32();
    uint32 SpecialFlags = questRecord[38].GetUInt16();
    RewardTitleId = questRecord[39].GetUInt32();
    RequiredPlayerKills = questRecord[40].GetUInt32();
    RewardTalents = questRecord[41].GetUInt32();
    RewardArenaPoints = questRecord[42].GetInt32();
    SeasonalQuestEvent = 0;

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemId[i] = questRecord[43+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemIdCount[i] = questRecord[47+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemId[i] = questRecord[51+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemCount[i] = questRecord[57+i].GetUInt32();
    
    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionId[i] = questRecord[63+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueId[i] = questRecord[68+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueIdOverride[i] = questRecord[73+i].GetInt32();
    
    PointMapId = questRecord[78].GetUInt32();
    PointX = questRecord[79].GetFloat();
    PointY = questRecord[80].GetFloat();
    PointOption = questRecord[81].GetUInt32();
    Title = questRecord[82].GetString();
    Objectives = questRecord[83].GetString();
    Details = questRecord[84].GetString();
    EndText = questRecord[85].GetString();
    OfferRewardText = questRecord[86].GetString();
    RequestItemsText = questRecord[87].GetString();
    CompletedText = questRecord[88].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGo[i] = questRecord[89+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGoCount[i] = questRecord[93+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemId[i] = questRecord[97+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemCount[i] = questRecord[101+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemId[i] = questRecord[105+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemCount[i] = questRecord[111+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredSpellCast[i] = questRecord[117+i].GetUInt32();

    // int8 Unknown0 = questRecord[121].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[122+i].GetString();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[126+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[130+i].GetUInt32();

    EmoteOnIncomplete = questRecord[134].GetUInt32();
    EmoteOnComplete = questRecord[135].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[136+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[140+i].GetInt32();

    StartScript = questRecord[144].GetUInt32();
    CompleteScript = questRecord[145].GetUInt32();

    // int32 WDBVerified = questRecord[146].GetInt32();

    Flags |= SpecialFlags << 20;
    if (Flags & QUEST_TRINITY_FLAGS_AUTO_ACCEPT)
        Flags |= QUEST_FLAGS_AUTO_ACCEPT;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (RequiredItemId[i])
            ++m_reqitemscount;

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (RequiredNpcOrGo[i])
            ++m_reqCreatureOrGOcount;

    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewardItemId[i])
            ++m_rewitemscount;

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewardChoiceItemId[i])
            ++m_rewchoiceitemscount;
}

uint32 Quest::XPValue(Player* player) const
{
    if (player)
    {
        int32 quest_level = (Level == -1 ? player->getLevel() : Level);
        const QuestXPEntry* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->getLevel()) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = diffFactor * xpentry->Exp[RewardXPId] / 10;
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

int32  Quest::GetRewOrReqMoney() const
{
    if (RewardOrRequiredMoney <= 0)
        return RewardOrRequiredMoney;

    return int32(RewardOrRequiredMoney * sWorld->getRate(RATE_DROP_MONEY));
}

bool Quest::IsAutoComplete() const
{
    return Method == 0 || HasFlag(QUEST_FLAGS_AUTOCOMPLETE);
}

bool Quest::IsAllowedInRaid() const
{
    if (IsRaidQuest())
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
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level-1);
        if (!tc)
            return 0;
        honor = uint32(tc->value * GetRewHonorMultiplier() * 0.1000000014901161);
        honor += GetRewHonorAddition();
    }

    return honor;
}
