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

Quest::Quest(Field * questRecord)
{
    QuestId = questRecord[0].GetUInt32();
    QuestMethod = questRecord[1].GetUInt32();
    ZoneOrSort = questRecord[2].GetInt32();
    SkillOrClassMask = questRecord[3].GetInt32();
    MinLevel = questRecord[4].GetUInt32();
    MaxLevel = questRecord[5].GetUInt32();
    QuestLevel = questRecord[6].GetInt32();
    Type = questRecord[7].GetUInt32();
    RequiredRaces = questRecord[8].GetUInt32();
    RequiredSkillValue = questRecord[9].GetUInt32();
    RepObjectiveFaction = questRecord[10].GetUInt32();
    RepObjectiveValue = questRecord[11].GetInt32();
    RepObjectiveFaction2 = questRecord[12].GetUInt32();
    RepObjectiveValue2 = questRecord[13].GetInt32();
    RequiredMinRepFaction = questRecord[14].GetUInt32();
    RequiredMinRepValue = questRecord[15].GetInt32();
    RequiredMaxRepFaction = questRecord[16].GetUInt32();
    RequiredMaxRepValue = questRecord[17].GetInt32();
    SuggestedPlayers = questRecord[18].GetUInt32();
    LimitTime = questRecord[19].GetUInt32();
    QuestFlags = questRecord[20].GetUInt32();
    uint32 SpecialFlags = questRecord[21].GetUInt16();
    CharTitleId = questRecord[22].GetUInt32();
    PlayersSlain = questRecord[23].GetUInt32();
    BonusTalents = questRecord[24].GetUInt32();
    RewArenaPoints = questRecord[25].GetInt32();
    PrevQuestId = questRecord[26].GetInt32();
    NextQuestId = questRecord[27].GetInt32();
    ExclusiveGroup = questRecord[28].GetInt32();
    NextQuestInChain = questRecord[29].GetUInt32();
    XPId = questRecord[30].GetUInt32();
    SrcItemId = questRecord[31].GetUInt32();
    SrcItemCount = questRecord[32].GetUInt32();
    SrcSpell = questRecord[33].GetUInt32();
    Title = questRecord[34].GetString();
    Details = questRecord[35].GetString();
    Objectives = questRecord[36].GetString();
    OfferRewardText = questRecord[37].GetString();
    RequestItemsText = questRecord[38].GetString();
    EndText = questRecord[39].GetString();
    CompletedText = questRecord[40].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[41+i].GetString();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[45+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[51+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[57+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[61+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[65+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[69+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[73+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[77+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[83+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[89+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[93+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[97+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValueId[i] = questRecord[102+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[107+i].GetInt32();

    RewHonorAddition = questRecord[112].GetUInt32();
    RewHonorMultiplier = questRecord[113].GetFloat();
    RewOrReqMoney = questRecord[114].GetInt32();
    RewMoneyMaxLevel = questRecord[115].GetUInt32();
    RewSpell = questRecord[116].GetUInt32();
    RewSpellCast = questRecord[117].GetInt32();
    RewMailTemplateId = questRecord[118].GetUInt32();
    RewMailDelaySecs = questRecord[119].GetUInt32();
    PointMapId = questRecord[120].GetUInt32();
    PointX = questRecord[121].GetFloat();
    PointY = questRecord[122].GetFloat();
    PointOpt = questRecord[123].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[124+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[128+i].GetUInt32();

    IncompleteEmote = questRecord[132].GetUInt32();
    CompleteEmote = questRecord[133].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[134+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[138+i].GetInt32();

    QuestStartScript = questRecord[142].GetUInt32();
    QuestCompleteScript = questRecord[143].GetUInt32();

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

uint32 Quest::XPValue(Player *pPlayer) const
{
    if (pPlayer)
    {
        int32 quest_level = (QuestLevel == -1 ? pPlayer->getLevel() : QuestLevel);
        const QuestXPEntry *xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - pPlayer->getLevel()) + 20;
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
