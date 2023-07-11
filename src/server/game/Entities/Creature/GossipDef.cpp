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

#include "GossipDef.h"
#include "Formulas.h"
#include "NPCPackets.h"
#include "ObjectMgr.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "WorldSession.h"

GossipMenu::GossipMenu()
{
    _menuId = 0;
    _locale = DEFAULT_LOCALE;
}

GossipMenu::~GossipMenu()
{
    ClearMenu();
}

uint32 GossipMenu::AddMenuItem(int32 menuItemId, GossipOptionIcon icon, std::string const& message, uint32 sender, uint32 action, std::string const& boxMessage, uint32 boxMoney, bool coded /*= false*/)
{
    ASSERT(_menuItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    // Find a free new id - script case
    if (menuItemId == -1)
    {
        menuItemId = 0;
        if (!_menuItems.empty())
        {
            for (GossipMenuItemContainer::const_iterator itr = _menuItems.begin(); itr != _menuItems.end(); ++itr)
            {
                if (int32(itr->first) > menuItemId)
                    break;

                menuItemId = itr->first + 1;
            }
        }
    }

    GossipMenuItem& menuItem = _menuItems[menuItemId];

    menuItem.MenuItemIcon    = icon;
    menuItem.Message         = message;
    menuItem.IsCoded         = coded;
    menuItem.Sender          = sender;
    menuItem.OptionType      = action;
    menuItem.BoxMessage      = boxMessage;
    menuItem.BoxMoney        = boxMoney;

    return menuItemId;
}

/**
 * @name AddMenuItem
 * @brief Adds a localized gossip menu item from db by menu id and menu item id.
 * @param menuId Gossip menu id.
 * @param menuItemId Gossip menu item id.
 * @param sender Identifier of the current menu.
 * @param action Custom action given to OnGossipHello.
 */
void GossipMenu::AddMenuItem(uint32 menuId, uint32 menuItemId, uint32 sender, uint32 action)
{
    /// Find items for given menu id.
    GossipMenuItemsMapBounds bounds = sObjectMgr->GetGossipMenuItemsMapBounds(menuId);
    /// Return if there are none.
    if (bounds.first == bounds.second)
        return;

    /// Iterate over each of them.
    for (GossipMenuItemsContainer::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        /// Find the one with the given menu item id.
        if (itr->second.OptionID != menuItemId)
            continue;

        /// Store texts for localization.
        std::string strOptionText, strBoxText;
        BroadcastText const* optionBroadcastText = sObjectMgr->GetBroadcastText(itr->second.OptionBroadcastTextID);
        BroadcastText const* boxBroadcastText = sObjectMgr->GetBroadcastText(itr->second.BoxBroadcastTextID);

        /// OptionText
        if (optionBroadcastText)
            strOptionText = optionBroadcastText->GetText(GetLocale());
        else
            strOptionText = itr->second.OptionText;

        /// BoxText
        if (boxBroadcastText)
            strBoxText = boxBroadcastText->GetText(GetLocale());
        else
            strBoxText = itr->second.BoxText;

        /// Check need of localization.
        if (GetLocale() != DEFAULT_LOCALE)
        {
            if (!optionBroadcastText)
            {
                /// Find localizations from database.
                if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuId, menuItemId))
                    ObjectMgr::GetLocaleString(gossipMenuLocale->OptionText, GetLocale(), strOptionText);
            }

            if (!boxBroadcastText)
            {
                /// Find localizations from database.
                if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuId, menuItemId))
                    ObjectMgr::GetLocaleString(gossipMenuLocale->BoxText, GetLocale(), strBoxText);
            }
        }

        /// Add menu item with existing method. Menu item id -1 is also used in ADD_GOSSIP_ITEM macro.
        uint32 newOptionId = AddMenuItem(-1, itr->second.OptionIcon, strOptionText, sender, action, strBoxText, itr->second.BoxMoney, itr->second.BoxCoded);
        AddGossipMenuItemData(newOptionId, itr->second.ActionMenuID, itr->second.ActionPoiID);
    }
}

void GossipMenu::AddGossipMenuItemData(uint32 optionIndex, uint32 gossipActionMenuId, uint32 gossipActionPoi)
{
    GossipMenuItemData& itemData = _menuItemData[optionIndex];

    itemData.GossipActionMenuId  = gossipActionMenuId;
    itemData.GossipActionPoi     = gossipActionPoi;
}

uint32 GossipMenu::GetMenuItemSender(uint32 menuItemId) const
{
    GossipMenuItemContainer::const_iterator itr = _menuItems.find(menuItemId);
    if (itr == _menuItems.end())
        return 0;

    return itr->second.Sender;
}

uint32 GossipMenu::GetMenuItemAction(uint32 menuItemId) const
{
    GossipMenuItemContainer::const_iterator itr = _menuItems.find(menuItemId);
    if (itr == _menuItems.end())
        return 0;

    return itr->second.OptionType;
}

bool GossipMenu::IsMenuItemCoded(uint32 menuItemId) const
{
    GossipMenuItemContainer::const_iterator itr = _menuItems.find(menuItemId);
    if (itr == _menuItems.end())
        return false;

    return itr->second.IsCoded;
}

bool GossipMenu::HasMenuItemType(uint32 optionType) const
{
    for (auto const& menuItemPair : _menuItems)
        if (menuItemPair.second.OptionType == optionType)
            return true;

    return false;
}

void GossipMenu::ClearMenu()
{
    _menuItems.clear();
    _menuItemData.clear();
}

PlayerMenu::PlayerMenu(WorldSession* session) : _session(session)
{
    if (_session)
        _gossipMenu.SetLocale(_session->GetSessionDbLocaleIndex());
}

PlayerMenu::~PlayerMenu()
{
    ClearMenus();
}

void PlayerMenu::ClearMenus()
{
    _gossipMenu.ClearMenu();
    _questMenu.ClearMenu();
}

void PlayerMenu::SendGossipMenu(uint32 titleTextId, ObjectGuid objectGUID)
{
    _interactionData.Reset();
    _interactionData.SourceGuid = objectGUID;

    WorldPackets::NPC::GossipMessage gossipMessage;
    gossipMessage.GossipGUID = objectGUID;
    gossipMessage.GossipID = _gossipMenu.GetMenuId();
    gossipMessage.TextID = titleTextId;

    gossipMessage.GossipOptions.reserve(_gossipMenu.GetMenuItems().size());
    for (auto const& itr : _gossipMenu.GetMenuItems())
    {
        WorldPackets::NPC::SGossipOptions& option = gossipMessage.GossipOptions.emplace_back();
        option.ClientOption = itr.first;
        option.OptionNPC = itr.second.MenuItemIcon;
        option.OptionFlags = itr.second.IsCoded;     // makes pop up box password
        option.OptionCost = itr.second.BoxMoney;     // money required to open menu, 2.0.3
        option.Text = itr.second.Message;            // text for gossip item
        option.Confirm = itr.second.BoxMessage;      // accept text (related to money) pop up box, 2.0.3
    }

    // Store this instead of checking the Singleton every loop iteration
    bool questLevelInTitle = sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS);

    gossipMessage.GossipQuestText.reserve(_questMenu.GetQuestMenuItems().size());
    for (auto const& itr : _questMenu.GetQuestMenuItems())
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(itr.QuestId);
        if (!quest)
            continue;

        WorldPackets::NPC::GossipText& text = gossipMessage.GossipQuestText.emplace_back();
        text.QuestID = itr.QuestId;
        text.QuestType = itr.QuestIcon;
        text.QuestFlags = quest->GetFlags();
        text.QuestLevel = quest->GetQuestLevel();
        text.Repeatable = quest->IsTurnIn() && quest->IsRepeatable() && !quest->IsDailyOrWeekly() && !quest->IsMonthly();

        text.QuestTitle = quest->GetTitle();
        LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
        if (localeConstant != LOCALE_enUS)
            if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(itr.QuestId))
                ObjectMgr::GetLocaleString(localeData->Title, localeConstant, text.QuestTitle);

        if (questLevelInTitle)
            Quest::AddQuestLevelToTitle(text.QuestTitle, quest->GetQuestLevel());
    }

    _session->SendPacket(gossipMessage.Write());
}

void PlayerMenu::SendCloseGossip()
{
    _interactionData.Reset();

    WorldPacket data(SMSG_GOSSIP_COMPLETE, 0);
    _session->SendPacket(&data);
}

void PlayerMenu::SendPointOfInterest(uint32 id) const
{
    PointOfInterest const* poi = sObjectMgr->GetPointOfInterest(id);
    if (!poi)
    {
        TC_LOG_ERROR("sql.sql", "Request to send non-existing POI (Id: %u), ignored.", id);
        return;
    }

    std::string name = poi->Name;
    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
        if (PointOfInterestLocale const* localeData = sObjectMgr->GetPointOfInterestLocale(id))
            ObjectMgr::GetLocaleString(localeData->Name, localeConstant, name);

    WorldPacket data(SMSG_GOSSIP_POI, 4 + 4 + 4 + 4 + 4 + 10);  // guess size
    data << uint32(poi->Flags);
    data << float(poi->PositionX);
    data << float(poi->PositionY);
    data << uint32(poi->Icon);
    data << uint32(poi->Importance);
    data << name;

    _session->SendPacket(&data);
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/

QuestMenu::QuestMenu()
{
    _questMenuItems.reserve(16);                                   // can be set for max from most often sizes to speedup push_back and less memory use
}

QuestMenu::~QuestMenu()
{
    ClearMenu();
}

void QuestMenu::AddMenuItem(uint32 QuestId, uint8 Icon)
{
    if (!sObjectMgr->GetQuestTemplate(QuestId))
        return;

    ASSERT(_questMenuItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    QuestMenuItem questMenuItem;

    questMenuItem.QuestId        = QuestId;
    questMenuItem.QuestIcon      = Icon;

    _questMenuItems.push_back(questMenuItem);
}

bool QuestMenu::HasItem(uint32 questId) const
{
    for (QuestMenuItemList::const_iterator i = _questMenuItems.begin(); i != _questMenuItems.end(); ++i)
        if (i->QuestId == questId)
            return true;

    return false;
}

void QuestMenu::ClearMenu()
{
    _questMenuItems.clear();
}

void PlayerMenu::SendQuestGiverQuestList(QEmote const& eEmote, const std::string& Title, ObjectGuid guid)
{
    WorldPackets::Quest::QuestGiverQuestListMessage questList;
    questList.QuestGiverGUID = guid;

    if (QuestGreeting const* questGreeting = sObjectMgr->GetQuestGreeting(guid))
    {
        std::string strGreeting = questGreeting->greeting;

        LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
        if (localeConstant != LOCALE_enUS)
            if (QuestGreetingLocale const* questGreetingLocale = sObjectMgr->GetQuestGreetingLocale(MAKE_PAIR32(guid.GetEntry(), guid.GetTypeId())))
                ObjectMgr::GetLocaleString(questGreetingLocale->greeting, localeConstant, strGreeting);

        questList.GreetEmoteDelay = questGreeting->greetEmoteDelay;
        questList.GreetEmoteType = questGreeting->greetEmoteType;
        questList.Greeting = strGreeting;
    }
    else
    {
        questList.GreetEmoteDelay = eEmote._Delay;
        questList.GreetEmoteType = eEmote._Emote;
        questList.Greeting = Title;
    }

    // Store this instead of checking the Singleton every loop iteration
    bool questLevelInTitle = sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS);

    for (uint32 i = 0; i < _questMenu.GetMenuItemCount(); ++i)
    {
        QuestMenuItem const& questMenuItem = _questMenu.GetItem(i);

        uint32 questID = questMenuItem.QuestId;

        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questID))
        {
            std::string title = quest->GetTitle();

            LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (QuestLocale const* questTemplateLocaleData = sObjectMgr->GetQuestLocale(questID))
                    ObjectMgr::GetLocaleString(questTemplateLocaleData->Title, localeConstant, title);

            if (questLevelInTitle)
                Quest::AddQuestLevelToTitle(title, quest->GetQuestLevel());

            bool repeatable = quest->IsTurnIn() && quest->IsRepeatable() && !quest->IsDailyOrWeekly() && !quest->IsMonthly();
            questList.QuestDataText.emplace_back(questID, questMenuItem.QuestIcon, quest->GetQuestLevel(), quest->GetFlags(), repeatable, title);
        }
    }

    _session->SendPacket(questList.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE (QuestGiverGUID: %s)", guid.ToString().c_str());
}

void PlayerMenu::SendQuestGiverStatus(uint32 questStatus, ObjectGuid npcGUID) const
{
    WorldPackets::Quest::QuestGiverStatus packet;
    packet.QuestGiver.Guid = npcGUID;
    packet.QuestGiver.Status = questStatus;

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_STATUS Guid = %s, Status = %u", npcGUID.ToString().c_str(), questStatus);
}

void PlayerMenu::SendQuestGiverQuestDetails(Quest const* quest, ObjectGuid npcGUID, bool autoLaunched, bool displayPopup) const
{
    WorldPackets::Quest::QuestGiverQuestDetails packet;

    packet.QuestTitle = quest->GetTitle();
    packet.LogDescription = quest->GetDetails();
    packet.Objectives = quest->GetObjectives();
    packet.DescriptionText = quest->GetAreaDescription();
    packet.PortraitGiverText = quest->GetQuestGiverTextWindow();
    packet.PortraitGiverName = quest->GetQuestGiverTargetName();
    packet.PortraitTurnInText = quest->GetQuestTurnTextWindow();
    packet.PortraitTurnInName = quest->GetQuestTurnTargetName();

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
    {
        if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(localeData->Title, localeConstant, packet.QuestTitle);
            ObjectMgr::GetLocaleString(localeData->Details, localeConstant, packet.LogDescription);
            ObjectMgr::GetLocaleString(localeData->Objectives, localeConstant, packet.Objectives);
            ObjectMgr::GetLocaleString(localeData->AreaDescription, localeConstant, packet.DescriptionText);
            ObjectMgr::GetLocaleString(localeData->QuestGiverTextWindow, localeConstant, packet.PortraitGiverText);
            ObjectMgr::GetLocaleString(localeData->QuestGiverTargetName, localeConstant, packet.PortraitGiverName);
            ObjectMgr::GetLocaleString(localeData->QuestTurnTextWindow, localeConstant, packet.PortraitTurnInText);
            ObjectMgr::GetLocaleString(localeData->QuestTurnTargetName, localeConstant, packet.PortraitTurnInName);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        Quest::AddQuestLevelToTitle(packet.QuestTitle, quest->GetQuestLevel());

    packet.QuestGiverGUID = npcGUID;
    packet.InformUnit = _session->GetPlayer()->GetPlayerSharingQuest();
    packet.QuestID = quest->GetQuestId();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.AutoLaunched = autoLaunched;
    packet.DisplayPopup = displayPopup;
    packet.QuestFlags = quest->GetFlags() & (sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT) ? ~QUEST_FLAGS_AUTO_ACCEPT : ~0);
    packet.SuggestedPartyMembers = quest->GetSuggestedPlayers();
    packet.RequiredSpellID = quest->GetRequiredSpell();

    quest->BuildQuestRewards(packet.Rewards, _session->GetPlayer());

    packet.DescEmotes.resize(QUEST_EMOTE_COUNT);
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        packet.DescEmotes[i].Type = quest->DetailsEmote[i];
        packet.DescEmotes[i].Delay = quest->DetailsEmoteDelay[i];
    }

    _session->SendPacket(packet.Write());

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_QUEST_DETAILS NPC=%s, questid=%u", npcGUID.ToString().c_str(), quest->GetQuestId());
}

void PlayerMenu::SendQuestQueryResponse(Quest const* quest) const
{
    if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
        _session->SendPacket(&quest->QueryData[static_cast<uint32>(_session->GetSessionDbLocaleIndex())]);
    else
    {
        WorldPacket queryPacket = quest->BuildQueryData(_session->GetSessionDbLocaleIndex());
        _session->SendPacket(&queryPacket);
    }

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_QUERY_RESPONSE questid=%u", quest->GetQuestId());
}

void PlayerMenu::SendQuestGiverOfferReward(Quest const* quest, ObjectGuid npcGUID, bool autoLaunched) const
{
    WorldPackets::Quest::QuestGiverOfferRewardMessage packet;

    packet.QuestTitle = quest->GetTitle();
    packet.RewardText = quest->GetOfferRewardText();
    packet.PortraitGiverText = quest->GetQuestGiverTextWindow();
    packet.PortraitGiverName = quest->GetQuestGiverTargetName();
    packet.PortraitTurnInText = quest->GetQuestTurnTextWindow();
    packet.PortraitTurnInName = quest->GetQuestTurnTargetName();

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
    {
        if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(localeData->Title, localeConstant, packet.QuestTitle);
            ObjectMgr::GetLocaleString(localeData->OfferRewardText, localeConstant, packet.RewardText);
            ObjectMgr::GetLocaleString(localeData->QuestGiverTextWindow, localeConstant, packet.PortraitGiverText);
            ObjectMgr::GetLocaleString(localeData->QuestGiverTargetName, localeConstant, packet.PortraitGiverName);
            ObjectMgr::GetLocaleString(localeData->QuestTurnTextWindow, localeConstant, packet.PortraitTurnInText);
            ObjectMgr::GetLocaleString(localeData->QuestTurnTargetName, localeConstant, packet.PortraitTurnInName);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        Quest::AddQuestLevelToTitle(packet.QuestTitle, quest->GetQuestLevel());

    WorldPackets::Quest::QuestGiverOfferReward& offer = packet.QuestData;

    quest->BuildQuestRewards(offer.Rewards, _session->GetPlayer());
    offer.QuestGiverGUID = npcGUID;
    offer.QuestID = quest->GetQuestId();
    offer.AutoLaunched = autoLaunched;
    offer.SuggestedPartyMembers = quest->GetSuggestedPlayers();

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT && quest->OfferRewardEmote[i]; ++i)
        offer.Emotes.emplace_back(quest->OfferRewardEmote[i], quest->OfferRewardEmoteDelay[i]);

    offer.QuestFlags = quest->GetFlags();

    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();

    _session->SendPacket(packet.Write());
}

void PlayerMenu::SendQuestGiverRequestItems(Quest const* quest, ObjectGuid npcGUID, bool canComplete, bool autoLaunched) const
{
    // We can always call to RequestItems, but this packet only goes out if there are actually
    // items.  Otherwise, we'll skip straight to the OfferReward

    std::string questTitle = quest->GetTitle();
    std::string requestItemsText = quest->GetRequestItemsText();

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
    {
        if (QuestLocale const* localeData = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(localeData->Title, localeConstant, questTitle);
            ObjectMgr::GetLocaleString(localeData->RequestItemsText, localeConstant, requestItemsText);
        }
    }

    if (!quest->GetReqItemsCount() && canComplete)
    {
        SendQuestGiverOfferReward(quest, npcGUID, true);
        return;
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        Quest::AddQuestLevelToTitle(questTitle, quest->GetQuestLevel());

    WorldPackets::Quest::QuestGiverRequestItems packet;

    packet.QuestTitle = questTitle;
    packet.CompletionText = requestItemsText;
    packet.QuestID = quest->GetQuestId();
    packet.QuestGiverGUID = npcGUID;
    packet.CompEmoteType = canComplete ? quest->GetCompleteEmote() : quest->GetIncompleteEmote();
    packet.AutoLaunched = autoLaunched;
    packet.QuestFlags = quest->GetFlags();
    packet.SuggestPartyMembers = quest->GetSuggestedPlayers();
    packet.MoneyToGet = quest->GetRewOrReqMoney() < 0 ? -quest->GetRewOrReqMoney() : 0;

    QuestStatusData data;
    QuestStatusMap statusMap = _session->GetPlayer()->getQuestStatusMap();
    QuestStatusMap::const_iterator itr = statusMap.find(quest->GetQuestId());
    if (itr != statusMap.end())
        data = itr->second;

    bool collectObjectiveComplete = true;
    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if (!quest->RequiredItemId[i])
            continue;

        uint32 displayId = 0;
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(quest->RequiredItemId[i]))
            displayId = itemTemplate->GetDisplayID();

        if (data.ItemCount[i] < quest->RequiredItemCount[i] && !_session->GetPlayer()->HasItemCount(quest->RequiredItemId[i], quest->RequiredItemCount[i]))
            collectObjectiveComplete = false;

        packet.Collect.emplace_back(quest->RequiredItemId[i], quest->RequiredItemCount[i], displayId);
    }

    for (uint8 i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
    {
        if (!quest->RequiredCurrencyId[i])
            continue;

        packet.Currency.emplace_back(quest->RequiredCurrencyId[i], quest->RequiredCurrencyCount[i]);
    }

    bool killCreditObjectiveComplete = true;
    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        if (!quest->RequiredNpcOrGo[i])
            continue;

        if (data.CreatureOrGOCount[i] != quest->RequiredNpcOrGoCount[i])
            killCreditObjectiveComplete = false;
    }

    packet.StatusFlags[0] = killCreditObjectiveComplete ? QUEST_STATUS_FLAG_KILL_OBJECTIVE_COMPLETE : QUEST_STATUS_FLAG_NONE;
    packet.StatusFlags[1] = collectObjectiveComplete ? QUEST_STATUS_FLAG_COLLECT_OBJECTIVE_COMPLETE : QUEST_STATUS_FLAG_NONE;
    packet.StatusFlags[2] = QUEST_STATUS_FLAG_UNK_4;
    packet.StatusFlags[3] = QUEST_STATUS_FLAG_UNK_5;
    packet.StatusFlags[4] = QUEST_STATUS_FLAG_UNK_7;

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_REQUEST_ITEMS NPC=%s, questid=%u", npcGUID.ToString().c_str(), quest->GetQuestId());
}
