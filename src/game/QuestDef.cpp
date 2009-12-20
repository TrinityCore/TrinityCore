/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "QuestDef.h"
#include "Player.h"
#include "World.h"

Quest::Quest(Field * questRecord)
{
    QuestId = questRecord[0].GetUInt32();
    QuestMethod = questRecord[1].GetUInt32();
    ZoneOrSort = questRecord[2].GetInt32();
    SkillOrClass = questRecord[3].GetInt32();
    MinLevel = questRecord[4].GetUInt32();
    QuestLevel = questRecord[5].GetInt32();
    Type = questRecord[6].GetUInt32();
    RequiredRaces = questRecord[7].GetUInt32();
    RequiredSkillValue = questRecord[8].GetUInt32();
    RepObjectiveFaction = questRecord[9].GetUInt32();
    RepObjectiveValue = questRecord[10].GetInt32();
    RepObjectiveFaction2 = questRecord[11].GetUInt32();
    RepObjectiveValue2 = questRecord[12].GetInt32();
    RequiredMinRepFaction = questRecord[13].GetUInt32();
    RequiredMinRepValue = questRecord[14].GetInt32();
    RequiredMaxRepFaction = questRecord[15].GetUInt32();
    RequiredMaxRepValue = questRecord[16].GetInt32();
    SuggestedPlayers = questRecord[17].GetUInt32();
    LimitTime = questRecord[18].GetUInt32();
    QuestFlags = questRecord[19].GetUInt16();
    uint32 SpecialFlags = questRecord[20].GetUInt16();
    CharTitleId = questRecord[21].GetUInt32();
    PlayersSlain = questRecord[22].GetUInt32();
    BonusTalents = questRecord[23].GetUInt32();
    PrevQuestId = questRecord[24].GetInt32();
    NextQuestId = questRecord[25].GetInt32();
    ExclusiveGroup = questRecord[26].GetInt32();
    NextQuestInChain = questRecord[27].GetUInt32();
    SrcItemId = questRecord[28].GetUInt32();
    SrcItemCount = questRecord[29].GetUInt32();
    SrcSpell = questRecord[30].GetUInt32();
    Title = questRecord[31].GetCppString();
    Details = questRecord[32].GetCppString();
    Objectives = questRecord[33].GetCppString();
    OfferRewardText = questRecord[34].GetCppString();
    RequestItemsText = questRecord[35].GetCppString();
    EndText = questRecord[36].GetCppString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[37+i].GetCppString();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[41+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[47+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[52+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[57+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[61+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[65+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[69+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[72+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[79+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[85+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[89+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[93+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[98+i].GetInt32();

    RewHonorableKills = questRecord[103].GetUInt32();
    RewOrReqMoney = questRecord[104].GetInt32();
    RewMoneyMaxLevel = questRecord[105].GetUInt32();
    RewSpell = questRecord[106].GetUInt32();
    RewSpellCast = questRecord[107].GetUInt32();
    RewMailTemplateId = questRecord[108].GetUInt32();
    RewMailDelaySecs = questRecord[109].GetUInt32();
    PointMapId = questRecord[110].GetUInt32();
    PointX = questRecord[111].GetFloat();
    PointY = questRecord[112].GetFloat();
    PointOpt = questRecord[113].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[114+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[118+i].GetUInt32();

    IncompleteEmote = questRecord[122].GetUInt32();
    CompleteEmote = questRecord[123].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[124+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[128+i].GetInt32();

    QuestStartScript = questRecord[132].GetUInt32();
    QuestCompleteScript = questRecord[133].GetUInt32();

    QuestFlags |= SpecialFlags << 16;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i=0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if ( ReqItemId[i] )
            ++m_reqitemscount;
    }

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        if ( ReqCreatureOrGOId[i] )
            ++m_reqCreatureOrGOcount;
    }

    for (int i=0; i < QUEST_REWARDS_COUNT; ++i)
    {
        if ( RewItemId[i] )
            ++m_rewitemscount;
    }

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        if (RewChoiceItemId[i])
            ++m_rewchoiceitemscount;
    }
}

uint32 Quest::XPValue( Player *pPlayer ) const
{
    if( pPlayer )
    {
        if( RewMoneyMaxLevel > 0 )
        {
            uint32 pLevel = pPlayer->getLevel();
            int32 qLevel = QuestLevel;
            float fullxp = 0;
            if (qLevel >= 15)
                fullxp = RewMoneyMaxLevel / 6.0f;
            else if (qLevel == 14)
                fullxp = RewMoneyMaxLevel / 4.8f;
            else if (qLevel == 13)
                fullxp = RewMoneyMaxLevel / 3.666f;
            else if (qLevel == 12)
                fullxp = RewMoneyMaxLevel / 2.4f;
            else if (qLevel == 11)
                fullxp = RewMoneyMaxLevel / 1.2f;
            else if (qLevel >= 1 && qLevel <= 10)
                fullxp = RewMoneyMaxLevel / 0.6f;
            else if (qLevel <= 0)
                fullxp = RewMoneyMaxLevel;

            if ((pLevel <= qLevel + 5) || qLevel == -1)
                return (uint32)fullxp;
            else if (pLevel == qLevel + 6)
                return (uint32)(fullxp * 0.8f);
            else if (pLevel == qLevel + 7)
                return (uint32)(fullxp * 0.6f);
            else if (pLevel == qLevel + 8)
                return (uint32)(fullxp * 0.4f);
            else if (pLevel == qLevel + 9)
                return (uint32)(fullxp * 0.2f);
            else
                return (uint32)(fullxp * 0.1f);
        }
    }
    return 0;
}

int32  Quest::GetRewOrReqMoney() const
{
    if(RewOrReqMoney <= 0)
        return RewOrReqMoney;

    return int32(RewOrReqMoney * sWorld.getRate(RATE_DROP_MONEY));
}
