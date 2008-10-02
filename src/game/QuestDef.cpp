/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "QuestDef.h"
#include "Player.h"
#include "World.h"

Quest::Quest(Field * questRecord)
{
    QuestId = questRecord[0].GetUInt32();
    ZoneOrSort = questRecord[1].GetInt32();
    SkillOrClass = questRecord[2].GetInt32();
    MinLevel = questRecord[3].GetUInt32();
    QuestLevel = questRecord[4].GetUInt32();
    Type = questRecord[5].GetUInt32();
    RequiredRaces = questRecord[6].GetUInt32();
    RequiredSkillValue = questRecord[7].GetUInt32();
    RepObjectiveFaction = questRecord[8].GetUInt32();
    RepObjectiveValue = questRecord[9].GetInt32();
    RequiredMinRepFaction = questRecord[10].GetUInt32();
    RequiredMinRepValue = questRecord[11].GetInt32();
    RequiredMaxRepFaction = questRecord[12].GetUInt32();
    RequiredMaxRepValue = questRecord[13].GetInt32();
    SuggestedPlayers = questRecord[14].GetUInt32();
    LimitTime = questRecord[15].GetUInt32();
    QuestFlags = questRecord[16].GetUInt16();
    uint32 SpecialFlags = questRecord[17].GetUInt16();
    CharTitleId = questRecord[18].GetUInt32();
    PrevQuestId = questRecord[19].GetInt32();
    NextQuestId = questRecord[20].GetInt32();
    ExclusiveGroup = questRecord[21].GetInt32();
    NextQuestInChain = questRecord[22].GetUInt32();
    SrcItemId = questRecord[23].GetUInt32();
    SrcItemCount = questRecord[24].GetUInt32();
    SrcSpell = questRecord[25].GetUInt32();
    Title = questRecord[26].GetCppString();
    Details = questRecord[27].GetCppString();
    Objectives = questRecord[28].GetCppString();
    OfferRewardText = questRecord[29].GetCppString();
    RequestItemsText = questRecord[30].GetCppString();
    EndText = questRecord[31].GetCppString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[32+i].GetCppString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[36+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[40+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[44+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[48+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceRef[i] = questRecord[52+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[56+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[60+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[64+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[68+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[74+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[80+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[84+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[88+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[93+i].GetInt32();

    RewOrReqMoney = questRecord[98].GetInt32();
    RewMoneyMaxLevel = questRecord[99].GetUInt32();
    RewSpell = questRecord[100].GetUInt32();
    RewSpellCast = questRecord[101].GetUInt32();
    RewMailTemplateId = questRecord[102].GetUInt32();
    RewMailDelaySecs = questRecord[103].GetUInt32();
    PointMapId = questRecord[104].GetUInt32();
    PointX = questRecord[105].GetFloat();
    PointY = questRecord[106].GetFloat();
    PointOpt = questRecord[107].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[108+i].GetUInt32();

    IncompleteEmote = questRecord[112].GetUInt32();
    CompleteEmote = questRecord[113].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[114+i].GetInt32();

    QuestStartScript = questRecord[118].GetUInt32();
    QuestCompleteScript = questRecord[119].GetUInt32();

    QuestFlags |= SpecialFlags << 16;

    m_reqitemscount = 0;
    m_reqCreatureOrGOcount = 0;
    m_rewitemscount = 0;
    m_rewchoiceitemscount = 0;

    for (int i=0; i < QUEST_OBJECTIVES_COUNT; i++)
    {
        if ( ReqItemId[i] )
            ++m_reqitemscount;
        if ( ReqCreatureOrGOId[i] )
            ++m_reqCreatureOrGOcount;
    }

    for (int i=0; i < QUEST_REWARDS_COUNT; i++)
    {
        if ( RewItemId[i] )
            ++m_rewitemscount;
    }

    for (int i=0; i < QUEST_REWARD_CHOICES_COUNT; i++)
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
            uint32 qLevel = QuestLevel;
            float fullxp = 0;
            if (qLevel >= 65)
                fullxp = RewMoneyMaxLevel / 6.0f;
            else if (qLevel == 64)
                fullxp = RewMoneyMaxLevel / 4.8f;
            else if (qLevel == 63)
                fullxp = RewMoneyMaxLevel / 3.6f;
            else if (qLevel == 62)
                fullxp = RewMoneyMaxLevel / 2.4f;
            else if (qLevel == 61)
                fullxp = RewMoneyMaxLevel / 1.2f;
            else if (qLevel > 0 && qLevel <= 60)
                fullxp = RewMoneyMaxLevel / 0.6f;

            if( pLevel <= qLevel +  5 )
                return (uint32)fullxp;
            else if( pLevel == qLevel +  6 )
                return (uint32)(fullxp * 0.8f);
            else if( pLevel == qLevel +  7 )
                return (uint32)(fullxp * 0.6f);
            else if( pLevel == qLevel +  8 )
                return (uint32)(fullxp * 0.4f);
            else if( pLevel == qLevel +  9 )
                return (uint32)(fullxp * 0.2f);
            else
                return (uint32)(fullxp * 0.1f);
        }
    }
    return 0;
}

int32  Quest::GetRewOrReqMoney() const
{
    if(RewOrReqMoney <=0)
        return RewOrReqMoney;

    return int32(RewOrReqMoney * sWorld.getRate(RATE_DROP_MONEY));
}
