/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
    QuestId = questRecord[0].GetUInt32();
    QuestMethod = questRecord[1].GetUInt32();
    ZoneOrSort = questRecord[2].GetInt32();
    MinLevel = questRecord[3].GetUInt32();
    MaxLevel = questRecord[4].GetUInt32();
    QuestLevel = questRecord[5].GetInt32();
    Type = questRecord[6].GetUInt32();
    RequiredClasses = questRecord[7].GetUInt32();
    RequiredRaces = questRecord[8].GetUInt32();
    RequiredSkill = questRecord[9].GetUInt32();
    RequiredSkillValue = questRecord[10].GetUInt32();
    RepObjectiveFaction = questRecord[11].GetUInt32();
    RepObjectiveValue = questRecord[12].GetInt32();
    RepObjectiveFaction2 = questRecord[13].GetUInt32();
    RepObjectiveValue2 = questRecord[14].GetInt32();
    RequiredMinRepFaction = questRecord[15].GetUInt32();
    RequiredMinRepValue = questRecord[16].GetInt32();
    RequiredMaxRepFaction = questRecord[17].GetUInt32();
    RequiredMaxRepValue = questRecord[18].GetInt32();
    SuggestedPlayers = questRecord[19].GetUInt32();
    LimitTime = questRecord[20].GetUInt32();
    QuestFlags = questRecord[21].GetUInt32();
    uint32 SpecialFlags = questRecord[22].GetUInt16();
    CharTitleId = questRecord[23].GetUInt32();
    PlayersSlain = questRecord[24].GetUInt32();
    BonusTalents = questRecord[25].GetUInt32();
    RewArenaPoints = questRecord[26].GetInt32();
    PrevQuestId = questRecord[27].GetInt32();
    NextQuestId = questRecord[28].GetInt32();
    ExclusiveGroup = questRecord[29].GetInt32();
    NextQuestInChain = questRecord[30].GetUInt32();
    XPId = questRecord[31].GetUInt32();
    SrcItemId = questRecord[32].GetUInt32();
    SrcItemCount = questRecord[33].GetUInt32();
    SrcSpell = questRecord[34].GetUInt32();
    Title = questRecord[35].GetString();
    Details = questRecord[36].GetString();
    Objectives = questRecord[37].GetString();
    OfferRewardText = questRecord[38].GetString();
    RequestItemsText = questRecord[39].GetString();
    EndText = questRecord[40].GetString();
    CompletedText = questRecord[41].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[42+i].GetString();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[46+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[52+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[58+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[62+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[66+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[70+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[74+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[78+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[84+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[90+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[94+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[98+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValueId[i] = questRecord[103+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[108+i].GetInt32();

    RewHonorAddition = questRecord[113].GetUInt32();
    RewHonorMultiplier = questRecord[114].GetFloat();
    RewOrReqMoney = questRecord[115].GetInt32();
    RewMoneyMaxLevel = questRecord[116].GetUInt32();
    RewSpell = questRecord[117].GetUInt32();
    RewSpellCast = questRecord[118].GetInt32();
    RewMailTemplateId = questRecord[119].GetUInt32();
    RewMailDelaySecs = questRecord[120].GetUInt32();
    PointMapId = questRecord[121].GetUInt32();
    PointX = questRecord[122].GetFloat();
    PointY = questRecord[123].GetFloat();
    PointOpt = questRecord[124].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[125+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[129+i].GetUInt32();

    IncompleteEmote = questRecord[133].GetUInt32();
    CompleteEmote = questRecord[134].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[135+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[139+i].GetInt32();

    QuestStartScript = questRecord[143].GetUInt32();
    QuestCompleteScript = questRecord[144].GetUInt32();

    QuestFlags |= SpecialFlags << 20;
    if (QuestFlags & QUEST_TRINITY_FLAGS_AUTO_ACCEPT)
        QuestFlags |= QUEST_FLAGS_AUTO_ACCEPT;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (ReqItemId[i])
            ++m_reqitemscount;

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (ReqCreatureOrGOId[i])
            ++m_reqCreatureOrGOcount;

    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewItemId[i])
            ++m_rewitemscount;

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewChoiceItemId[i])
            ++m_rewchoiceitemscount;
}

uint32 Quest::XPValue(Player* player) const
{
    if (player)
    {
        int32 quest_level = (QuestLevel == -1 ? player->getLevel() : QuestLevel);
        const QuestXPEntry* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->getLevel()) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = diffFactor * xpentry->Exp[XPId] / 10;
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
    if (RewOrReqMoney <= 0)
        return RewOrReqMoney;

    return int32(RewOrReqMoney * sWorld->getRate(RATE_DROP_MONEY));
}

bool Quest::IsAutoComplete() const
{
    return QuestMethod == 0 || HasFlag(QUEST_FLAGS_AUTOCOMPLETE);
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
