/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "GossipDef.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "Log.h"
#include "NPCPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "World.h"
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

uint32 GossipMenu::AddMenuItem(int32 optionIndex, uint8 icon, std::string const& message, uint32 sender, uint32 action, std::string const& boxMessage, uint32 boxMoney, bool coded /*= false*/)
{
    ASSERT(_menuItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    // Find a free new id - script case
    if (optionIndex == -1)
    {
        optionIndex = 0;
        if (!_menuItems.empty())
        {
            for (GossipMenuItemContainer::const_iterator itr = _menuItems.begin(); itr != _menuItems.end(); ++itr)
            {
                if (int32(itr->first) > optionIndex)
                    break;

                optionIndex = itr->first + 1;
            }
        }
    }

    GossipMenuItem& menuItem = _menuItems[optionIndex];

    menuItem.MenuItemIcon    = icon;
    menuItem.Message         = message;
    menuItem.IsCoded         = coded;
    menuItem.Sender          = sender;
    menuItem.OptionType      = action;
    menuItem.BoxMessage      = boxMessage;
    menuItem.BoxMoney        = boxMoney;
    return optionIndex;
}

/**
 * @name AddMenuItem
 * @brief Adds a localized gossip menu item from db by menu id and menu item id.
 * @param menuId Gossip menu id.
 * @param optionIndex Gossip menu item index.
 * @param sender Identifier of the current menu.
 * @param action Custom action given to OnGossipHello.
 */
void GossipMenu::AddMenuItem(uint32 menuId, uint32 optionIndex, uint32 sender, uint32 action)
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
        if (itr->second.OptionIndex != optionIndex)
            continue;

        /// Store texts for localization.
        std::string strOptionText, strBoxText;
        BroadcastTextEntry const* optionBroadcastText = sBroadcastTextStore.LookupEntry(itr->second.OptionBroadcastTextId);
        BroadcastTextEntry const* boxBroadcastText = sBroadcastTextStore.LookupEntry(itr->second.BoxBroadcastTextId);

        /// OptionText
        if (optionBroadcastText)
            strOptionText = DB2Manager::GetBroadcastTextValue(optionBroadcastText, GetLocale());
        else
            strOptionText = itr->second.OptionText;

        /// BoxText
        if (boxBroadcastText)
            strBoxText = DB2Manager::GetBroadcastTextValue(boxBroadcastText, GetLocale());
        else
            strBoxText = itr->second.BoxText;

        /// Check need of localization.
        if (GetLocale() != DEFAULT_LOCALE)
        {
            if (!optionBroadcastText)
            {
                /// Find localizations from database.
                if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuId, optionIndex))
                    ObjectMgr::GetLocaleString(gossipMenuLocale->OptionText, GetLocale(), strOptionText);
            }

            if (!boxBroadcastText)
            {
                /// Find localizations from database.
                if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuId, optionIndex))
                    ObjectMgr::GetLocaleString(gossipMenuLocale->BoxText, GetLocale(), strBoxText);
            }
        }

        /// Add menu item with existing method. Menu item id -1 is also used in ADD_GOSSIP_ITEM macro.
        uint32 newOptionIndex = AddMenuItem(-1, itr->second.OptionIcon, strOptionText, sender, action, strBoxText, itr->second.BoxMoney, itr->second.BoxCoded);
        AddGossipMenuItemData(newOptionIndex, itr->second.ActionMenuId, itr->second.ActionPoiId, itr->second.TrainerId);
    }
}

void GossipMenu::AddGossipMenuItemData(uint32 optionIndex, uint32 gossipActionMenuId, uint32 gossipActionPoi, uint32 trainerId)
{
    GossipMenuItemData& itemData = _menuItemData[optionIndex];

    itemData.GossipActionMenuId  = gossipActionMenuId;
    itemData.GossipActionPoi     = gossipActionPoi;
    itemData.TrainerId           = trainerId;
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

    WorldPackets::NPC::GossipMessage packet;
    packet.GossipGUID = objectGUID;
    packet.GossipID = _gossipMenu.GetMenuId();
    packet.TextID = titleTextId;

    packet.GossipOptions.resize(_gossipMenu.GetMenuItems().size());
    uint32 count = 0;
    for (GossipMenuItemContainer::const_iterator itr = _gossipMenu.GetMenuItems().begin(); itr != _gossipMenu.GetMenuItems().end(); ++itr)
    {
        WorldPackets::NPC::ClientGossipOptions& opt = packet.GossipOptions[count];
        GossipMenuItem const& item = itr->second;
        opt.ClientOption = itr->first;
        opt.OptionNPC = item.MenuItemIcon;
        opt.OptionFlags = item.IsCoded;     // makes pop up box password
        opt.OptionCost = item.BoxMoney;     // money required to open menu, 2.0.3
        opt.Text = item.Message;            // text for gossip item
        opt.Confirm = item.BoxMessage;      // accept text (related to money) pop up box, 2.0.3
        ++count;
    }

    // Store this instead of checking the Singleton every loop iteration
    bool questLevelInTitle = sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS);

    packet.GossipText.resize(_questMenu.GetMenuItemCount());
    count = 0;
    for (uint8 i = 0; i < _questMenu.GetMenuItemCount(); ++i)
    {
        QuestMenuItem const& item = _questMenu.GetItem(i);
        uint32 questID = item.QuestId;
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questID))
        {
            WorldPackets::NPC::ClientGossipText& text = packet.GossipText[count];
            text.QuestID = questID;
            text.QuestType = item.QuestIcon;
            text.QuestLevel = quest->GetQuestLevel();
            text.QuestMaxScalingLevel = quest->GetQuestMaxScalingLevel();
            text.QuestFlags[0] = quest->GetFlags();
            text.QuestFlags[1] = quest->GetFlagsEx();
            text.Repeatable = quest->IsRepeatable();

            text.QuestTitle = quest->GetLogTitle();
            LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (QuestTemplateLocale const* localeData = sObjectMgr->GetQuestLocale(questID))
                    ObjectMgr::GetLocaleString(localeData->LogTitle, localeConstant, text.QuestTitle);

            if (questLevelInTitle)
                AddQuestLevelToTitle(text.QuestTitle, quest->GetQuestLevel());

            ++count;
        }
    }

    // Shrink to the real size
    packet.GossipText.resize(count);

    _session->SendPacket(packet.Write());
}

void PlayerMenu::SendCloseGossip()
{
    _interactionData.Reset();

    WorldPackets::NPC::GossipComplete packet;
    _session->SendPacket(packet.Write());
}

void PlayerMenu::SendPointOfInterest(uint32 id) const
{
    PointOfInterest const* pointOfInterest = sObjectMgr->GetPointOfInterest(id);
    if (!pointOfInterest)
    {
        TC_LOG_ERROR("sql.sql", "Request to send non-existing PointOfInterest (Id: %u), ignored.", id);
        return;
    }

    WorldPackets::NPC::GossipPOI packet;
    packet.Name = pointOfInterest->Name;

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
        if (PointOfInterestLocale const* localeData = sObjectMgr->GetPointOfInterestLocale(id))
            ObjectMgr::GetLocaleString(localeData->Name, localeConstant, packet.Name);

    packet.Flags = pointOfInterest->Flags;
    packet.Pos = pointOfInterest->Pos;
    packet.Icon = pointOfInterest->Icon;
    packet.Importance = pointOfInterest->Importance;

    _session->SendPacket(packet.Write());
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

void PlayerMenu::SendQuestGiverQuestListMessage(ObjectGuid guid)
{
    WorldPackets::Quest::QuestGiverQuestListMessage questList;
    questList.QuestGiverGUID = guid;

    if  (QuestGreeting const* questGreeting = sObjectMgr->GetQuestGreeting(guid))
    {
        questList.GreetEmoteDelay = questGreeting->greetEmoteDelay;
        questList.GreetEmoteType = questGreeting->greetEmoteType;
        questList.Greeting = questGreeting->greeting;
    }
    else
        TC_LOG_ERROR("misc", "Guid: %s - No quest greeting found.", guid.ToString().c_str());

    // Store this instead of checking the Singleton every loop iteration
    bool questLevelInTitle = sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS);

    for (uint32 i = 0; i < _questMenu.GetMenuItemCount(); ++i)
    {
        QuestMenuItem const& questMenuItem = _questMenu.GetItem(i);

        uint32 questID = questMenuItem.QuestId;

        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questID))
        {
            std::string title = quest->GetLogTitle();

            LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(questID))
                    ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle, localeConstant, title);

            if (questLevelInTitle)
                AddQuestLevelToTitle(title, quest->GetQuestLevel());

            bool repeatable = false; // NYI

            questList.QuestDataText.emplace_back(questID, questMenuItem.QuestIcon, quest->GetQuestLevel(), quest->GetQuestMaxScalingLevel(),
                quest->GetFlags(), quest->GetFlagsEx(), repeatable, std::move(title));
        }
    }

    _session->SendPacket(questList.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE NPC=%s", guid.ToString().c_str());
}

void PlayerMenu::SendQuestGiverStatus(uint32 questStatus, ObjectGuid npcGUID) const
{
    WorldPackets::Quest::QuestGiverStatus packet;
    packet.QuestGiver.Guid = npcGUID;
    packet.QuestGiver.Status = questStatus;

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_STATUS NPC=%s, status=%u", npcGUID.ToString().c_str(), questStatus);
}

void PlayerMenu::SendQuestGiverQuestDetails(Quest const* quest, ObjectGuid npcGUID, bool autoLaunched, bool displayPopup) const
{
    WorldPackets::Quest::QuestGiverQuestDetails packet;

    packet.QuestTitle = quest->GetLogTitle();
    packet.LogDescription = quest->GetLogDescription();
    packet.DescriptionText = quest->GetQuestDescription();
    packet.PortraitGiverText = quest->GetPortraitGiverText();
    packet.PortraitGiverName = quest->GetPortraitGiverName();
    packet.PortraitTurnInText = quest->GetPortraitTurnInText();
    packet.PortraitTurnInName = quest->GetPortraitTurnInName();

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle,           localeConstant, packet.QuestTitle);
            ObjectMgr::GetLocaleString(questTemplateLocale->LogDescription,     localeConstant, packet.LogDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->QuestDescription,   localeConstant, packet.DescriptionText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverText,  localeConstant, packet.PortraitGiverText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverName,  localeConstant, packet.PortraitGiverName);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInText, localeConstant, packet.PortraitTurnInText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInName, localeConstant, packet.PortraitTurnInName);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        AddQuestLevelToTitle(packet.QuestTitle, quest->GetQuestLevel());

    packet.QuestGiverGUID = npcGUID;
    packet.InformUnit = _session->GetPlayer()->GetDivider();
    packet.QuestID = quest->GetQuestId();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.AutoLaunched = autoLaunched;
    packet.DisplayPopup = displayPopup;
    packet.QuestFlags[0] = quest->GetFlags();
    packet.QuestFlags[1] = quest->GetFlagsEx();
    packet.SuggestedPartyMembers = quest->GetSuggestedPlayers();

    if (quest->GetSrcSpell())
        packet.LearnSpells.push_back(quest->GetSrcSpell());

    quest->BuildQuestRewards(packet.Rewards, _session->GetPlayer());

    packet.DescEmotes.resize(QUEST_EMOTE_COUNT);
    for (uint32 i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        packet.DescEmotes[i].Type = quest->DetailsEmote[i];
        packet.DescEmotes[i].Delay = quest->DetailsEmoteDelay[i];
    }

    QuestObjectives const& objs = quest->GetObjectives();
    packet.Objectives.resize(objs.size());
    for (uint32 i = 0; i < objs.size(); ++i)
    {
        packet.Objectives[i].ID = objs[i].ID;
        packet.Objectives[i].ObjectID = objs[i].ObjectID;
        packet.Objectives[i].Amount = objs[i].Amount;
        packet.Objectives[i].Type = objs[i].Type;
    }

    _session->SendPacket(packet.Write());

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_QUEST_DETAILS NPC=%s, questid=%u", npcGUID.ToString().c_str(), quest->GetQuestId());
}

void PlayerMenu::SendQuestQueryResponse(Quest const* quest) const
{
    WorldPackets::Quest::QueryQuestInfoResponse packet;

    packet.Allow = true;
    packet.QuestID = quest->GetQuestId();

    packet.Info.LogTitle = quest->GetLogTitle();
    packet.Info.LogDescription = quest->GetLogDescription();
    packet.Info.QuestDescription = quest->GetQuestDescription();
    packet.Info.AreaDescription = quest->GetAreaDescription();
    packet.Info.QuestCompletionLog = quest->GetQuestCompletionLog();
    packet.Info.PortraitGiverText = quest->GetPortraitGiverText();
    packet.Info.PortraitGiverName = quest->GetPortraitGiverName();
    packet.Info.PortraitTurnInText = quest->GetPortraitTurnInText();
    packet.Info.PortraitTurnInName = quest->GetPortraitTurnInName();

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle,           localeConstant, packet.Info.LogTitle);
            ObjectMgr::GetLocaleString(questTemplateLocale->LogDescription,     localeConstant, packet.Info.LogDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->QuestDescription,   localeConstant, packet.Info.QuestDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->AreaDescription,    localeConstant, packet.Info.AreaDescription);
            ObjectMgr::GetLocaleString(questTemplateLocale->QuestCompletionLog, localeConstant, packet.Info.QuestCompletionLog);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverText,  localeConstant, packet.Info.PortraitGiverText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverName,  localeConstant, packet.Info.PortraitGiverName);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInText, localeConstant, packet.Info.PortraitTurnInText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInName, localeConstant, packet.Info.PortraitTurnInName);
        }
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        AddQuestLevelToTitle(packet.Info.LogTitle, quest->GetQuestLevel());

    packet.Info.QuestID = quest->GetQuestId();
    packet.Info.QuestType = quest->GetQuestType();
    packet.Info.QuestLevel = quest->GetQuestLevel();
    packet.Info.QuestMaxScalingLevel = quest->GetQuestMaxScalingLevel();
    packet.Info.QuestPackageID = quest->GetQuestPackageID();
    packet.Info.QuestMinLevel = quest->GetMinLevel();
    packet.Info.QuestSortID = quest->GetZoneOrSort();
    packet.Info.QuestInfoID = quest->GetQuestInfoID();
    packet.Info.SuggestedGroupNum = quest->GetSuggestedPlayers();
    packet.Info.RewardNextQuest = quest->GetNextQuestInChain();
    packet.Info.RewardXPDifficulty = quest->GetXPDifficulty();
    packet.Info.RewardXPMultiplier = quest->GetXPMultiplier();

    if (!quest->HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
        packet.Info.RewardMoney = quest->RewardMoney < 0 ? quest->RewardMoney : _session->GetPlayer()->GetQuestMoneyReward(quest);

    packet.Info.RewardMoneyDifficulty = quest->GetRewMoneyDifficulty();
    packet.Info.RewardMoneyMultiplier = quest->GetMoneyMultiplier();
    packet.Info.RewardBonusMoney = quest->GetRewMoneyMaxLevel();
    for (uint8 i = 0; i < QUEST_REWARD_DISPLAY_SPELL_COUNT; ++i)
        packet.Info.RewardDisplaySpell[i] = quest->RewardDisplaySpell[i];

    packet.Info.RewardSpell = quest->GetRewSpell();

    packet.Info.RewardHonor = quest->GetRewHonor();
    packet.Info.RewardKillHonor = quest->GetRewKillHonor();

    packet.Info.RewardArtifactXPDifficulty = quest->GetArtifactXPDifficulty();
    packet.Info.RewardArtifactXPMultiplier = quest->GetArtifactXPMultiplier();
    packet.Info.RewardArtifactCategoryID = quest->GetArtifactCategoryId();

    packet.Info.StartItem = quest->GetSrcItemId();
    packet.Info.Flags = quest->GetFlags();
    packet.Info.FlagsEx = quest->GetFlagsEx();
    packet.Info.RewardTitle = quest->GetRewTitle();
    packet.Info.RewardArenaPoints = quest->GetRewArenaPoints();
    packet.Info.RewardSkillLineID = quest->GetRewardSkillId();
    packet.Info.RewardNumSkillUps = quest->GetRewardSkillPoints();
    packet.Info.RewardFactionFlags = quest->GetRewardReputationMask();
    packet.Info.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.Info.PortraitTurnIn = quest->GetQuestTurnInPortrait();

    for (uint8 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        packet.Info.ItemDrop[i] = quest->ItemDrop[i];
        packet.Info.ItemDropQuantity[i] = quest->ItemDropQuantity[i];
    }

    if (!quest->HasFlag(QUEST_FLAGS_HIDDEN_REWARDS))
    {
        for (uint8 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        {
            packet.Info.RewardItems[i] = quest->RewardItemId[i];
            packet.Info.RewardAmount[i] = quest->RewardItemCount[i];
        }
        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            packet.Info.UnfilteredChoiceItems[i].ItemID = quest->RewardChoiceItemId[i];
            packet.Info.UnfilteredChoiceItems[i].Quantity = quest->RewardChoiceItemCount[i];
        }
    }

    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        packet.Info.RewardFactionID[i] = quest->RewardFactionId[i];
        packet.Info.RewardFactionValue[i] = quest->RewardFactionValue[i];
        packet.Info.RewardFactionOverride[i] = quest->RewardFactionOverride[i];
        packet.Info.RewardFactionCapIn[i] = quest->RewardFactionCapIn[i];
    }

    packet.Info.POIContinent = quest->GetPOIContinent();
    packet.Info.POIx = quest->GetPOIx();
    packet.Info.POIy = quest->GetPOIy();
    packet.Info.POIPriority = quest->GetPOIPriority();

    packet.Info.AllowableRaces = quest->GetAllowableRaces();
    packet.Info.QuestRewardID = quest->GetRewardId();
    packet.Info.Expansion = quest->GetExpansion();

    for (QuestObjective const& questObjective : quest->GetObjectives())
    {
        packet.Info.Objectives.push_back(questObjective);

        if (localeConstant != LOCALE_enUS)
        {
            if (QuestObjectivesLocale const* questObjectivesLocale = sObjectMgr->GetQuestObjectivesLocale(questObjective.ID))
                ObjectMgr::GetLocaleString(questObjectivesLocale->Description, localeConstant, packet.Info.Objectives.back().Description);
        }
    }

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        packet.Info.RewardCurrencyID[i] = quest->RewardCurrencyId[i];
        packet.Info.RewardCurrencyQty[i] = quest->RewardCurrencyCount[i];
    }

    packet.Info.AcceptedSoundKitID = quest->GetSoundAccept();
    packet.Info.CompleteSoundKitID = quest->GetSoundTurnIn();
    packet.Info.AreaGroupID = quest->GetAreaGroupID();
    packet.Info.TimeAllowed = quest->GetLimitTime();

    _session->SendPacket(packet.Write());

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_QUERY_RESPONSE questid=%u", quest->GetQuestId());
}

void PlayerMenu::SendQuestGiverOfferReward(Quest const* quest, ObjectGuid npcGUID, bool autoLaunched) const
{
    WorldPackets::Quest::QuestGiverOfferRewardMessage packet;

    packet.QuestTitle = quest->GetLogTitle();
    packet.RewardText = quest->GetOfferRewardText();
    packet.PortraitGiverText = quest->GetPortraitGiverText();
    packet.PortraitGiverName = quest->GetPortraitGiverName();
    packet.PortraitTurnInText = quest->GetPortraitTurnInText();
    packet.PortraitTurnInName = quest->GetPortraitTurnInName();

    LocaleConstant locale = _session->GetSessionDbLocaleIndex();
    if (locale != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
        {
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle,           locale, packet.QuestTitle);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverText,  locale, packet.PortraitGiverText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitGiverName,  locale, packet.PortraitGiverName);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInText, locale, packet.PortraitTurnInText);
            ObjectMgr::GetLocaleString(questTemplateLocale->PortraitTurnInName, locale, packet.PortraitTurnInName);
        }

        if (QuestOfferRewardLocale const* questOfferRewardLocale = sObjectMgr->GetQuestOfferRewardLocale(quest->GetQuestId()))
            ObjectMgr::GetLocaleString(questOfferRewardLocale->RewardText, locale, packet.RewardText);
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        AddQuestLevelToTitle(packet.QuestTitle, quest->GetQuestLevel());

    WorldPackets::Quest::QuestGiverOfferReward& offer = packet.QuestData;

    quest->BuildQuestRewards(offer.Rewards, _session->GetPlayer());
    offer.QuestGiverGUID = npcGUID;

    // Is there a better way? what about game objects?
    if (Creature const* creature = ObjectAccessor::GetCreature(*_session->GetPlayer(), npcGUID))
        offer.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;

    offer.QuestID = quest->GetQuestId();
    offer.AutoLaunched = autoLaunched;
    offer.SuggestedPartyMembers = quest->GetSuggestedPlayers();

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT && quest->OfferRewardEmote[i]; ++i)
        offer.Emotes.emplace_back(quest->OfferRewardEmote[i], quest->OfferRewardEmoteDelay[i]);

    offer.QuestFlags[0] = quest->GetFlags();
    offer.QuestFlags[1] = quest->GetFlagsEx();

    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.QuestPackageID = quest->GetQuestPackageID();

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_OFFER_REWARD NPC=%s, questid=%u", npcGUID.ToString().c_str(), quest->GetQuestId());
}

void PlayerMenu::SendQuestGiverRequestItems(Quest const* quest, ObjectGuid npcGUID, bool canComplete, bool autoLaunched) const
{
    // We can always call to RequestItems, but this packet only goes out if there are actually
    // items.  Otherwise, we'll skip straight to the OfferReward

    if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER) && canComplete)
    {
        SendQuestGiverOfferReward(quest, npcGUID, true);
        return;
    }

    WorldPackets::Quest::QuestGiverRequestItems packet;

    packet.QuestTitle = quest->GetLogTitle();
    packet.CompletionText = quest->GetRequestItemsText();

    LocaleConstant locale = _session->GetSessionDbLocaleIndex();
    if (locale != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle, locale, packet.QuestTitle);

        if (QuestRequestItemsLocale const* questRequestItemsLocale = sObjectMgr->GetQuestRequestItemsLocale(quest->GetQuestId()))
            ObjectMgr::GetLocaleString(questRequestItemsLocale->CompletionText, locale, packet.CompletionText);
    }

    if (sWorld->getBoolConfig(CONFIG_UI_QUESTLEVELS_IN_DIALOGS))
        AddQuestLevelToTitle(packet.QuestTitle, quest->GetQuestLevel());

    packet.QuestGiverGUID = npcGUID;

    // Is there a better way? what about game objects?
    if (Creature const* creature = ObjectAccessor::GetCreature(*_session->GetPlayer(), npcGUID))
        packet.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;

    packet.QuestID = quest->GetQuestId();

    if (canComplete)
    {
        packet.CompEmoteDelay = quest->EmoteOnCompleteDelay;
        packet.CompEmoteType = quest->EmoteOnComplete;
    }
    else
    {
        packet.CompEmoteDelay = quest->EmoteOnIncompleteDelay;
        packet.CompEmoteType = quest->EmoteOnIncomplete;
    }

    packet.QuestFlags[0] = quest->GetFlags();
    packet.QuestFlags[1] = quest->GetFlagsEx();
    packet.SuggestPartyMembers = quest->GetSuggestedPlayers();

    // incomplete: FD
    // incomplete quest with item objective but item objective is complete DD
    packet.StatusFlags = canComplete ? 0xFF : 0xFD;

    packet.MoneyToGet = 0;
    for (QuestObjective const& obj : quest->GetObjectives())
    {
        switch (obj.Type)
        {
            case QUEST_OBJECTIVE_ITEM:
                packet.Collect.emplace_back(obj.ObjectID, obj.Amount, obj.Flags);
                break;
            case QUEST_OBJECTIVE_CURRENCY:
                packet.Currency.emplace_back(obj.ObjectID, obj.Amount);
                break;
            case QUEST_OBJECTIVE_MONEY:
                packet.MoneyToGet += obj.Amount;
                break;
            default:
                break;
        }
    }

    packet.AutoLaunched = autoLaunched;

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_REQUEST_ITEMS NPC=%s, questid=%u", npcGUID.ToString().c_str(), quest->GetQuestId());
}

void PlayerMenu::AddQuestLevelToTitle(std::string &title, int32 level)
{
    // Adds the quest level to the front of the quest title
    // example: [13] Westfall Stew

    std::stringstream questTitlePretty;
    questTitlePretty << "[" << level << "] " << title;
    title = questTitlePretty.str();
}
