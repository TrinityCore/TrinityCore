/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
    XPId = questRecord[28].GetUInt32();
    SrcItemId = questRecord[29].GetUInt32();
    SrcItemCount = questRecord[30].GetUInt32();
    SrcSpell = questRecord[31].GetUInt32();
    Title = questRecord[32].GetCppString();
    Details = questRecord[33].GetCppString();
    Objectives = questRecord[34].GetCppString();
    OfferRewardText = questRecord[35].GetCppString();
    RequestItemsText = questRecord[36].GetCppString();
    EndText = questRecord[37].GetCppString();
    CompletedText = questRecord[38].GetCppString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[39+i].GetCppString();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemId[i] = questRecord[43+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        ReqItemCount[i] = questRecord[49+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceId[i] = questRecord[55+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ReqSourceCount[i] = questRecord[59+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOId[i] = questRecord[63+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqCreatureOrGOCount[i] = questRecord[67+i].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ReqSpell[i] = questRecord[71+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemId[i] = questRecord[75+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewChoiceItemCount[i] = questRecord[81+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemId[i] = questRecord[87+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewItemCount[i] = questRecord[91+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepFaction[i] = questRecord[95+i].GetUInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValueId[i] = questRecord[100+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewRepValue[i] = questRecord[105+i].GetInt32();

    RewHonorableKills = questRecord[110].GetUInt32();
    RewHonorMultiplier = questRecord[111].GetFloat();
    RewOrReqMoney = questRecord[112].GetInt32();
    RewMoneyMaxLevel = questRecord[113].GetUInt32();
    RewSpell = questRecord[114].GetUInt32();
    RewSpellCast = questRecord[115].GetInt32();
    RewMailTemplateId = questRecord[116].GetUInt32();
    RewMailDelaySecs = questRecord[117].GetUInt32();
    PointMapId = questRecord[118].GetUInt32();
    PointX = questRecord[119].GetFloat();
    PointY = questRecord[120].GetFloat();
    PointOpt = questRecord[121].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[122+i].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[126+i].GetUInt32();

    IncompleteEmote = questRecord[130].GetUInt32();
    CompleteEmote = questRecord[131].GetUInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[132+i].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[136+i].GetInt32();

    QuestStartScript = questRecord[140].GetUInt32();
    QuestCompleteScript = questRecord[141].GetUInt32();

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

      const QuestXPEntry *xpentry;
      int32 quest_level = (QuestLevel == -1 ? pPlayer->getLevel() : QuestLevel);
      xpentry = sQuestXPStore.LookupEntry(quest_level);
      if(!xpentry)
	return 0;
      
      int diffFactor = 2 * (quest_level - pPlayer->getLevel()) + 20;

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
    if(RewOrReqMoney <= 0)
        return RewOrReqMoney;

    return int32(RewOrReqMoney * sWorld.getRate(RATE_DROP_MONEY));
}
