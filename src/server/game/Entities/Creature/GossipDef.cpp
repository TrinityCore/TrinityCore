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
#include "GossipDef.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Formulas.h"

GossipMenu::GossipMenu()
{
    m_gItems.reserve(16);                                   // can be set for max from most often sizes to speedup push_back and less memory use
    m_gMenuId = 0;
}

GossipMenu::~GossipMenu()
{
    ClearMenu();
}

void GossipMenu::AddMenuItem(uint8 Icon, const std::string& Message, uint32 dtSender, uint32 dtAction, const std::string& BoxMessage, uint32 BoxMoney, bool Coded)
{
    ASSERT(m_gItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    GossipMenuItem gItem;

    gItem.m_gIcon       = Icon;
    gItem.m_gMessage    = Message;
    gItem.m_gCoded      = Coded;
    gItem.m_gSender     = dtSender;
    gItem.m_gOptionId   = dtAction;
    gItem.m_gBoxMessage = BoxMessage;
    gItem.m_gBoxMoney   = BoxMoney;

    m_gItems.push_back(gItem);
}

void GossipMenu::AddGossipMenuItemData(uint32 action_menu, uint32 action_poi, uint32 action_script)
{
    GossipMenuItemData pItemData;

    pItemData.m_gAction_menu    = action_menu;
    pItemData.m_gAction_poi     = action_poi;
    pItemData.m_gAction_script  = action_script;

    m_gItemsData.push_back(pItemData);
}

void GossipMenu::AddMenuItem(uint8 Icon, const std::string& Message, bool Coded)
{
    AddMenuItem(Icon, Message, 0, 0, "", 0, Coded);
}

void GossipMenu::AddMenuItem(uint8 Icon, char const* Message, bool Coded)
{
    AddMenuItem(Icon, std::string(Message ? Message : ""),Coded);
}

void GossipMenu::AddMenuItem(uint8 Icon, char const* Message, uint32 dtSender, uint32 dtAction, char const* BoxMessage, uint32 BoxMoney, bool Coded)
{
    AddMenuItem(Icon, std::string(Message ? Message : ""), dtSender, dtAction, std::string(BoxMessage ? BoxMessage : ""), BoxMoney, Coded);
}

uint32 GossipMenu::MenuItemSender(unsigned int ItemId)
{
    if (ItemId >= m_gItems.size()) return 0;

    return m_gItems[ ItemId ].m_gSender;
}

uint32 GossipMenu::MenuItemAction(unsigned int ItemId)
{
    if (ItemId >= m_gItems.size()) return 0;

   return m_gItems[ ItemId ].m_gOptionId;
}

bool GossipMenu::MenuItemCoded(unsigned int ItemId)
{
    if (ItemId >= m_gItems.size()) return 0;

    return m_gItems[ ItemId ].m_gCoded;
}

void GossipMenu::ClearMenu()
{
    m_gItems.clear();
    m_gItemsData.clear();
}

PlayerMenu::PlayerMenu(WorldSession *session) : pSession(session)
{
}

PlayerMenu::~PlayerMenu()
{
    ClearMenus();
}

void PlayerMenu::ClearMenus()
{
    mGossipMenu.ClearMenu();
    mQuestMenu.ClearMenu();
}

uint32 PlayerMenu::GossipOptionSender(unsigned int Selection)
{
    return mGossipMenu.MenuItemSender(Selection);
}

uint32 PlayerMenu::GossipOptionAction(unsigned int Selection)
{
    return mGossipMenu.MenuItemAction(Selection);
}

bool PlayerMenu::GossipOptionCoded(unsigned int Selection)
{
    return mGossipMenu.MenuItemCoded(Selection);
}

void PlayerMenu::SendGossipMenu(uint32 TitleTextId, uint64 objectGUID)
{
    WorldPacket data(SMSG_GOSSIP_MESSAGE, (100));         // guess size
    data << uint64(objectGUID);
    data << uint32(mGossipMenu.GetMenuId());              // new 2.4.0
    data << uint32(TitleTextId);
    data << uint32(mGossipMenu.MenuItemCount());          // max count 0x10

    for (uint32 iI = 0; iI < mGossipMenu.MenuItemCount(); ++iI)
    {
        GossipMenuItem const& gItem = mGossipMenu.GetItem(iI);
        data << uint32(iI);
        data << uint8(gItem.m_gIcon);
        data << uint8(gItem.m_gCoded);                    // makes pop up box password
        data << uint32(gItem.m_gBoxMoney);                  // money required to open menu, 2.0.3
        data << gItem.m_gMessage;                           // text for gossip item
        data << gItem.m_gBoxMessage;                        // accept text (related to money) pop up box, 2.0.3
    }

    data << uint32(mQuestMenu.MenuItemCount());           // max count 0x20

    for (uint32 iI = 0; iI < mQuestMenu.MenuItemCount(); ++iI)
    {
        QuestMenuItem const& qItem = mQuestMenu.GetItem(iI);
        uint32 questID = qItem.m_qId;
        Quest const* pQuest = sObjectMgr->GetQuestTemplate(questID);

        data << uint32(questID);
        data << uint32(qItem.m_qIcon);
        data << int32(pQuest->GetQuestLevel());
        data << uint32(pQuest->GetFlags());                 // 3.3.3 quest flags
        data << uint8(0);                                   // 3.3.3 changes icon: blue question or yellow exclamation
        std::string Title = pQuest->GetTitle();

        int loc_idx = pSession->GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
            if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(questID))
                sObjectMgr->GetLocaleString(ql->Title, loc_idx, Title);

        data << Title;                                      // max 0x200
    }

    pSession->SendPacket(&data);
}

void PlayerMenu::CloseGossip()
{
    WorldPacket data(SMSG_GOSSIP_COMPLETE, 0);
    pSession->SendPacket(&data);
}

// Outdated
void PlayerMenu::SendPointOfInterest(float X, float Y, uint32 Icon, uint32 Flags, uint32 Data, char const * locName)
{
    WorldPacket data(SMSG_GOSSIP_POI, (4+4+4+4+4+10));    // guess size
    data << uint32(Flags);
    data << float(X);
    data << float(Y);
    data << uint32(Icon);
    data << uint32(Data);
    data << locName;

    pSession->SendPacket(&data);
    //sLog->outDebug(LOG_FILTER_PACKETIO, "WORLD: Sent SMSG_GOSSIP_POI");
}

void PlayerMenu::SendPointOfInterest(uint32 poi_id)
{
    PointOfInterest const* poi = sObjectMgr->GetPointOfInterest(poi_id);
    if (!poi)
    {
        sLog->outErrorDb("Request to send non-existing POI (Id: %u), ignored.",poi_id);
        return;
    }

    std::string icon_name = poi->icon_name;

    int loc_idx = pSession->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
        if (PointOfInterestLocale const *pl = sObjectMgr->GetPointOfInterestLocale(poi_id))
            sObjectMgr->GetLocaleString(pl->IconName, loc_idx, icon_name);

    WorldPacket data(SMSG_GOSSIP_POI, (4+4+4+4+4+10));    // guess size
    data << uint32(poi->flags);
    data << float(poi->x);
    data << float(poi->y);
    data << uint32(poi->icon);
    data << uint32(poi->data);
    data << icon_name;

    pSession->SendPacket(&data);
    //sLog->outDebug(LOG_FILTER_PACKETIO, "WORLD: Sent SMSG_GOSSIP_POI");
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/

QuestMenu::QuestMenu()
{
    m_qItems.reserve(16);                                   // can be set for max from most often sizes to speedup push_back and less memory use
}

QuestMenu::~QuestMenu()
{
    ClearMenu();
}

void QuestMenu::AddMenuItem(uint32 QuestId, uint8 Icon)
{
    Quest const* qinfo = sObjectMgr->GetQuestTemplate(QuestId);
    if (!qinfo) return;

    ASSERT(m_qItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    QuestMenuItem qItem;

    qItem.m_qId        = QuestId;
    qItem.m_qIcon      = Icon;

    m_qItems.push_back(qItem);
}

bool QuestMenu::HasItem(uint32 questid)
{
    for (QuestMenuItemList::const_iterator i = m_qItems.begin(); i != m_qItems.end(); ++i)
    {
        if (i->m_qId == questid)
        {
            return true;
        }
    }
    return false;
}

void QuestMenu::ClearMenu()
{
    m_qItems.clear();
}

void PlayerMenu::SendQuestGiverQuestList(QEmote eEmote, const std::string& Title, uint64 npcGUID)
{
    WorldPacket data(SMSG_QUESTGIVER_QUEST_LIST, 100);    // guess size
    data << uint64(npcGUID);
    data << Title;
    data << uint32(eEmote._Delay);                         // player emote
    data << uint32(eEmote._Emote);                         // NPC emote

    size_t count_pos = data.wpos();
    data << uint8 ( mQuestMenu.MenuItemCount());
    uint32 count = 0;
    for (; count < mQuestMenu.MenuItemCount(); ++count)
    {
        QuestMenuItem const& qmi = mQuestMenu.GetItem(count);

        uint32 questID = qmi.m_qId;

        if (Quest const *pQuest = sObjectMgr->GetQuestTemplate(questID))
        {
            std::string title = pQuest->GetTitle();

            int loc_idx = pSession->GetSessionDbLocaleIndex();
            if (loc_idx >= 0)
                if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(questID))
                    sObjectMgr->GetLocaleString(ql->Title, loc_idx, title);

            data << uint32(questID);
            data << uint32(qmi.m_qIcon);
            data << int32(pQuest->GetQuestLevel());
            data << uint32(pQuest->GetFlags());             // 3.3.3 quest flags
            data << uint8(0);                               // 3.3.3 changes icon: blue question or yellow exclamation
            data << title;
        }
    }

    data.put<uint8>(count_pos, count);
    pSession->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUESTGIVER_QUEST_LIST NPC Guid=%u", GUID_LOPART(npcGUID));
}

void PlayerMenu::SendQuestGiverStatus(uint8 questStatus, uint64 npcGUID)
{
    WorldPacket data(SMSG_QUESTGIVER_STATUS, 9);
    data << uint64(npcGUID);
    data << uint8(questStatus);

    pSession->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUESTGIVER_STATUS NPC Guid=%u, status=%u", GUID_LOPART(npcGUID), questStatus);
}

void PlayerMenu::SendQuestGiverQuestDetails(Quest const *pQuest, uint64 npcGUID, bool ActivateAccept)
{
    std::string Title      = pQuest->GetTitle();
    std::string Details    = pQuest->GetDetails();
    std::string Objectives = pQuest->GetObjectives();
    std::string EndText    = pQuest->GetEndText();

    int loc_idx = pSession->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
    {
        if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(pQuest->GetQuestId()))
        {
            sObjectMgr->GetLocaleString(ql->Title, loc_idx, Title);
            sObjectMgr->GetLocaleString(ql->Details, loc_idx, Details);
            sObjectMgr->GetLocaleString(ql->Objectives, loc_idx, Objectives);
            sObjectMgr->GetLocaleString(ql->EndText, loc_idx, EndText);
        }
    }

    WorldPacket data(SMSG_QUESTGIVER_QUEST_DETAILS, 100);   // guess size
    data << uint64(npcGUID);
    data << uint64(0);                                      // wotlk, something todo with quest sharing?
    data << uint32(pQuest->GetQuestId());
    data << Title;
    data << Details;
    data << Objectives;
    data << uint8(ActivateAccept ? 1 : 0);                  // auto finish
    data << uint32(pQuest->GetFlags());                     // 3.3.3 questFlags
    data << uint32(pQuest->GetSuggestedPlayers());
    data << uint8(0);                                       // IsFinished? value is sent back to server in quest accept packet

    if (pQuest->HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
    {
        data << uint32(0);                                  // Rewarded chosen items hidden
        data << uint32(0);                                  // Rewarded items hidden
        data << uint32(0);                                  // Rewarded money hidden
        data << uint32(0);                                  // Rewarded XP hidden
    }
    else
    {
        ItemPrototype const* IProto;

        data << uint32(pQuest->GetRewChoiceItemsCount());
        for (uint32 i=0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            if (!pQuest->RewChoiceItemId[i])
                continue;

            data << uint32(pQuest->RewChoiceItemId[i]);
            data << uint32(pQuest->RewChoiceItemCount[i]);

            IProto = ObjectMgr::GetItemPrototype(pQuest->RewChoiceItemId[i]);

            if (IProto)
                data << uint32(IProto->DisplayInfoID);
            else
                data << uint32(0x00);
        }

        data << uint32(pQuest->GetRewItemsCount());

        for (uint32 i=0; i < QUEST_REWARDS_COUNT; ++i)
        {
            if (!pQuest->RewItemId[i])
                continue;

            data << uint32(pQuest->RewItemId[i]);
            data << uint32(pQuest->RewItemCount[i]);

            IProto = ObjectMgr::GetItemPrototype(pQuest->RewItemId[i]);

            if (IProto)
                data << uint32(IProto->DisplayInfoID);
            else
                data << uint32(0);
        }

        data << uint32(pQuest->GetRewOrReqMoney());
        data << uint32(pQuest->XPValue(pSession->GetPlayer())*sWorld->getRate(RATE_XP_QUEST));
    }

    // rewarded honor points. Multiply with 10 to satisfy client
    data << 10 * Trinity::Honor::hk_honor_at_level(pSession->GetPlayer()->getLevel(), pQuest->GetRewHonorMultiplier());
    data << float(0);                                       // new 3.3.0, honor multiplier?
    data << uint32(pQuest->GetRewSpell());                  // reward spell, this spell will display (icon) (casted if RewSpellCast == 0)
    data << int32(pQuest->GetRewSpellCast());               // casted spell
    data << uint32(pQuest->GetCharTitleId());               // CharTitleId, new 2.4.0, player gets this title (id from CharTitles)
    data << uint32(pQuest->GetBonusTalents());              // bonus talents
    data << uint32(pQuest->GetRewArenaPoints());            // reward arena points
    data << uint32(0);                                      // unk

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << uint32(pQuest->RewRepFaction[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << int32(pQuest->RewRepValueId[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << int32(pQuest->RewRepValue[i]);

    data << uint32(QUEST_EMOTE_COUNT);
    for (uint32 i=0; i < QUEST_EMOTE_COUNT; ++i)
    {
        data << uint32(pQuest->DetailsEmote[i]);
        data << uint32(pQuest->DetailsEmoteDelay[i]);       // DetailsEmoteDelay (in ms)
    }
    pSession->SendPacket(&data);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUESTGIVER_QUEST_DETAILS NPCGuid=%u, questid=%u", GUID_LOPART(npcGUID), pQuest->GetQuestId());
}

void PlayerMenu::SendQuestQueryResponse(Quest const *pQuest)
{
    std::string Title, Details, Objectives, EndText, CompletedText;
    std::string ObjectiveText[QUEST_OBJECTIVES_COUNT];
    Title = pQuest->GetTitle();
    Details = pQuest->GetDetails();
    Objectives = pQuest->GetObjectives();
    EndText = pQuest->GetEndText();
    CompletedText = pQuest->GetCompletedText();
    for (int i=0; i<QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i]=pQuest->ObjectiveText[i];

    int loc_idx = pSession->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
    {
        if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(pQuest->GetQuestId()))
        {
            sObjectMgr->GetLocaleString(ql->Title, loc_idx, Title);
            sObjectMgr->GetLocaleString(ql->Details, loc_idx, Details);
            sObjectMgr->GetLocaleString(ql->Objectives, loc_idx, Objectives);
            sObjectMgr->GetLocaleString(ql->EndText, loc_idx, EndText);
            sObjectMgr->GetLocaleString(ql->CompletedText, loc_idx, CompletedText);

            for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
                sObjectMgr->GetLocaleString(ql->ObjectiveText[i], loc_idx, ObjectiveText[i]);
        }
    }

    WorldPacket data(SMSG_QUEST_QUERY_RESPONSE, 100);     // guess size

    data << uint32(pQuest->GetQuestId());                   // quest id
    data << uint32(pQuest->GetQuestMethod());               // Accepted values: 0, 1 or 2. 0 == IsAutoComplete() (skip objectives/details)
    data << uint32(pQuest->GetQuestLevel());                // may be -1, static data, in other cases must be used dynamic level: Player::GetQuestLevel (0 is not known, but assuming this is no longer valid for quest intended for client)
    data << uint32(pQuest->GetMinLevel());                  // min level
    data << uint32(pQuest->GetZoneOrSort());                // zone or sort to display in quest log

    data << uint32(pQuest->GetType());                      // quest type
    data << uint32(pQuest->GetSuggestedPlayers());          // suggested players count

    data << uint32(pQuest->GetRepObjectiveFaction());       // shown in quest log as part of quest objective
    data << uint32(pQuest->GetRepObjectiveValue());         // shown in quest log as part of quest objective

    data << uint32(pQuest->GetRepObjectiveFaction2());       // shown in quest log as part of quest objective OPOSITE faction
    data << uint32(pQuest->GetRepObjectiveValue2());         // shown in quest log as part of quest objective OPPOSITE faction

    data << uint32(pQuest->GetNextQuestInChain());          // client will request this quest from NPC, if not 0
    data << uint32(pQuest->GetXPId());                      // used for calculating rewarded experience

    if (pQuest->HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
        data << uint32(0);                                  // Hide money rewarded
    else
        data << uint32(pQuest->GetRewOrReqMoney());         // reward money (below max lvl)

    data << uint32(pQuest->GetRewMoneyMaxLevel());          // used in XP calculation at client
    data << uint32(pQuest->GetRewSpell());                  // reward spell, this spell will display (icon) (casted if RewSpellCast == 0)
    data << int32(pQuest->GetRewSpellCast());               // casted spell

    // rewarded honor points
    data << Trinity::Honor::hk_honor_at_level(pSession->GetPlayer()->getLevel(), pQuest->GetRewHonorMultiplier());
    data << float(0);                                       // new reward honor (multipled by ~62 at client side)
    data << uint32(pQuest->GetSrcItemId());                 // source item id
    data << uint32(pQuest->GetFlags() & 0xFFFF);            // quest flags
    data << uint32(pQuest->GetCharTitleId());               // CharTitleId, new 2.4.0, player gets this title (id from CharTitles)
    data << uint32(pQuest->GetPlayersSlain());              // players slain
    data << uint32(pQuest->GetBonusTalents());              // bonus talents
    data << uint32(pQuest->GetRewArenaPoints());            // bonus arena points
    data << uint32(0);                                      // review rep show mask

    int iI;

    if (pQuest->HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
    {
        for (iI = 0; iI < QUEST_REWARDS_COUNT; ++iI)
            data << uint32(0) << uint32(0);
        for (iI = 0; iI < QUEST_REWARD_CHOICES_COUNT; ++iI)
            data << uint32(0) << uint32(0);
    }
    else
    {
        for (iI = 0; iI < QUEST_REWARDS_COUNT; ++iI)
        {
            data << uint32(pQuest->RewItemId[iI]);
            data << uint32(pQuest->RewItemCount[iI]);
        }
        for (iI = 0; iI < QUEST_REWARD_CHOICES_COUNT; ++iI)
        {
            data << uint32(pQuest->RewChoiceItemId[iI]);
            data << uint32(pQuest->RewChoiceItemCount[iI]);
        }
    }

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)         // reward factions ids
        data << uint32(pQuest->RewRepFaction[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)         // columnid+1 QuestFactionReward.dbc?
        data << int32(pQuest->RewRepValueId[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)         // unk (0)
        data << int32(pQuest->RewRepValue[i]);

    data << pQuest->GetPointMapId();
    data << pQuest->GetPointX();
    data << pQuest->GetPointY();
    data << pQuest->GetPointOpt();

    data << Title;
    data << Objectives;
    data << Details;
    data << EndText;
    data << CompletedText;                                  // display in quest objectives window once all objectives are completed

    for (iI = 0; iI < QUEST_OBJECTIVES_COUNT; ++iI)
    {
        if (pQuest->ReqCreatureOrGOId[iI] < 0)
        {
            // client expected gameobject template id in form (id|0x80000000)
            data << uint32((pQuest->ReqCreatureOrGOId[iI]*(-1))|0x80000000);
        }
        else
        {
            data << uint32(pQuest->ReqCreatureOrGOId[iI]);
        }
        data << uint32(pQuest->ReqCreatureOrGOCount[iI]);
        data << uint32(pQuest->ReqSourceId[iI]);
        data << uint32(0);                                  // req source count?
    }

    for (iI = 0; iI < QUEST_ITEM_OBJECTIVES_COUNT; ++iI)
    {
        data << uint32(pQuest->ReqItemId[iI]);
        data << uint32(pQuest->ReqItemCount[iI]);
    }

    for (iI = 0; iI < QUEST_OBJECTIVES_COUNT; ++iI)
        data << ObjectiveText[iI];

    pSession->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUEST_QUERY_RESPONSE questid=%u", pQuest->GetQuestId());
}

void PlayerMenu::SendQuestGiverOfferReward(Quest const* pQuest, uint64 npcGUID, bool EnableNext)
{
    std::string Title = pQuest->GetTitle();
    std::string OfferRewardText = pQuest->GetOfferRewardText();

    int loc_idx = pSession->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
    {
        if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(pQuest->GetQuestId()))
        {
            sObjectMgr->GetLocaleString(ql->Title, loc_idx, Title);
            sObjectMgr->GetLocaleString(ql->OfferRewardText, loc_idx, OfferRewardText);
        }
    }

    WorldPacket data(SMSG_QUESTGIVER_OFFER_REWARD, 50);   // guess size

    data << uint64(npcGUID);
    data << uint32(pQuest->GetQuestId());
    data << Title;
    data << OfferRewardText;

    data << uint8(EnableNext ? 1 : 0);                      // Auto Finish
    data << uint32(pQuest->GetFlags());                     // 3.3.3 questFlags
    data << uint32(pQuest->GetSuggestedPlayers());          // SuggestedGroupNum

    uint32 EmoteCount = 0;
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        if (pQuest->OfferRewardEmote[i] <= 0)
            break;
        ++EmoteCount;
    }

    data << EmoteCount;                                     // Emote Count
    for (uint32 i = 0; i < EmoteCount; ++i)
    {
        data << uint32(pQuest->OfferRewardEmoteDelay[i]);   // Delay Emote
        data << uint32(pQuest->OfferRewardEmote[i]);
    }

    ItemPrototype const *pItem;

    data << uint32(pQuest->GetRewChoiceItemsCount());
    for (uint32 i=0; i < pQuest->GetRewChoiceItemsCount(); ++i)
    {
        pItem = ObjectMgr::GetItemPrototype(pQuest->RewChoiceItemId[i]);

        data << uint32(pQuest->RewChoiceItemId[i]);
        data << uint32(pQuest->RewChoiceItemCount[i]);

        if (pItem)
            data << uint32(pItem->DisplayInfoID);
        else
            data << uint32(0);
    }

    data << uint32(pQuest->GetRewItemsCount());
    for (uint32 i = 0; i < pQuest->GetRewItemsCount(); ++i)
    {
        pItem = ObjectMgr::GetItemPrototype(pQuest->RewItemId[i]);
        data << uint32(pQuest->RewItemId[i]);
        data << uint32(pQuest->RewItemCount[i]);

        if (pItem)
            data << uint32(pItem->DisplayInfoID);
        else
            data << uint32(0);
    }

    data << uint32(pQuest->GetRewOrReqMoney());
    data << uint32(pQuest->XPValue(pSession->GetPlayer())*sWorld->getRate(RATE_XP_QUEST));

    // rewarded honor points. Multiply with 10 to satisfy client
    data << 10 * Trinity::Honor::hk_honor_at_level(pSession->GetPlayer()->getLevel(), pQuest->GetRewHonorMultiplier());
    data << float(0);                                       // unk, honor multiplier?
    data << uint32(0x08);                                   // unused by client?
    data << uint32(pQuest->GetRewSpell());                  // reward spell, this spell will display (icon) (casted if RewSpellCast == 0)
    data << int32(pQuest->GetRewSpellCast());               // casted spell
    data << uint32(0);                                      // unknown
    data << uint32(pQuest->GetBonusTalents());              // bonus talents
    data << uint32(pQuest->GetRewArenaPoints());               // arena points
    data << uint32(0);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)        // reward factions ids
        data << uint32(pQuest->RewRepFaction[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)        // columnid in QuestFactionReward.dbc (zero based)?
        data << int32(pQuest->RewRepValueId[i]);

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)        // reward reputation override?
        data << uint32(pQuest->RewRepValue[i]);

    pSession->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUESTGIVER_OFFER_REWARD NPCGuid=%u, questid=%u", GUID_LOPART(npcGUID), pQuest->GetQuestId());
}

void PlayerMenu::SendQuestGiverRequestItems(Quest const *pQuest, uint64 npcGUID, bool Completable, bool CloseOnCancel)
{
    // We can always call to RequestItems, but this packet only goes out if there are actually
    // items.  Otherwise, we'll skip straight to the OfferReward

    std::string Title = pQuest->GetTitle();
    std::string RequestItemsText = pQuest->GetRequestItemsText();

    int loc_idx = pSession->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
    {
        if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(pQuest->GetQuestId()))
        {
            sObjectMgr->GetLocaleString(ql->Title, loc_idx, Title);
            sObjectMgr->GetLocaleString(ql->RequestItemsText, loc_idx, RequestItemsText);
        }
    }

    if (!pQuest->GetReqItemsCount() && Completable)
    {
        SendQuestGiverOfferReward(pQuest, npcGUID, true);
        return;
    }

    WorldPacket data(SMSG_QUESTGIVER_REQUEST_ITEMS, 50);  // guess size
    data << uint64(npcGUID);
    data << uint32(pQuest->GetQuestId());
    data << Title;
    data << RequestItemsText;

    data << uint32(0x00);                                   // unknown

    if (Completable)
        data << pQuest->GetCompleteEmote();
    else
        data << pQuest->GetIncompleteEmote();

    // Close Window after cancel
    if (CloseOnCancel)
        data << uint32(0x01);
    else
        data << uint32(0x00);

    data << uint32(pQuest->GetFlags());                     // 3.3.3 questFlags
    data << uint32(pQuest->GetSuggestedPlayers());          // SuggestedGroupNum

    // Required Money
    data << uint32(pQuest->GetRewOrReqMoney() < 0 ? -pQuest->GetRewOrReqMoney() : 0);

    data << uint32(pQuest->GetReqItemsCount());
    ItemPrototype const *pItem;
    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if (!pQuest->ReqItemId[i])
            continue;

        pItem = ObjectMgr::GetItemPrototype(pQuest->ReqItemId[i]);

        data << uint32(pQuest->ReqItemId[i]);
        data << uint32(pQuest->ReqItemCount[i]);

        if (pItem)
            data << uint32(pItem->DisplayInfoID);
        else
            data << uint32(0);
    }

    if (!Completable)
        data << uint32(0x00);
    else
        data << uint32(0x03);

    data << uint32(0x04);
    data << uint32(0x08);
    data << uint32(0x10);

    pSession->SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_QUESTGIVER_REQUEST_ITEMS NPCGuid=%u, questid=%u", GUID_LOPART(npcGUID), pQuest->GetQuestId());
}
