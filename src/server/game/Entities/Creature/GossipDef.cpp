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
#include "Containers.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "Log.h"
#include "NPCPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Util.h"
#include "World.h"
#include "WorldSession.h"

GossipMenu::GossipMenu()
{
    _menuId = 0;
    _locale = DEFAULT_LOCALE;
}

GossipMenu::~GossipMenu() = default;

uint32 GossipMenu::AddMenuItem(int32 gossipOptionId, int32 orderIndex, GossipOptionNpc optionNpc, std::string optionText, uint32 language,
    GossipOptionFlags flags, Optional<int32> gossipNpcOptionId, uint32 actionMenuId, uint32 actionPoiId, bool boxCoded, uint32 boxMoney,
    std::string boxText, Optional<int32> spellId, Optional<int32> overrideIconId, uint32 sender, uint32 action)
{
    ASSERT(_menuItems.size() <= GOSSIP_MAX_MENU_ITEMS);

    // Find a free new id - script case
    if (orderIndex == -1)
    {
        orderIndex = 0;
        if (_menuId)
        {
            // set baseline orderIndex as higher than whatever exists in db
            Trinity::IteratorPair bounds = sObjectMgr->GetGossipMenuItemsMapBounds(_menuId);
            auto itr = std::max_element(bounds.begin(), bounds.end(), [](GossipMenuItemsContainer::value_type const& a, GossipMenuItemsContainer::value_type const& b)
            {
                return a.second.OrderIndex < b.second.OrderIndex;
            });
            if (itr != bounds.end())
                orderIndex = itr->second.OrderIndex + 1;
        }

        if (!_menuItems.empty())
        {
            for (GossipMenuItemContainer::const_iterator itr = _menuItems.begin(); itr != _menuItems.end(); ++itr)
            {
                if (int32(itr->OrderIndex) > orderIndex)
                    break;

                orderIndex = itr->OrderIndex + 1;
            }
        }
    }

    if (!gossipOptionId)
        gossipOptionId = -(int32(_menuId) * 100 + orderIndex);

    auto where = std::lower_bound(_menuItems.begin(), _menuItems.end(), orderIndex, [](GossipMenuItem const& item, int32 index)
    {
        return int32(item.OrderIndex) < index;
    });

    GossipMenuItem& menuItem = *_menuItems.emplace(where);
    menuItem.GossipOptionID = gossipOptionId;
    menuItem.OrderIndex = orderIndex;
    menuItem.OptionNpc = optionNpc;
    menuItem.OptionText = std::move(optionText);
    menuItem.Language = language;
    menuItem.Flags = flags;
    menuItem.GossipNpcOptionID = gossipNpcOptionId;
    menuItem.BoxCoded = boxCoded;
    menuItem.BoxMoney = boxMoney;
    menuItem.BoxText = std::move(boxText);
    menuItem.SpellID = spellId;
    menuItem.OverrideIconID = overrideIconId;
    menuItem.ActionMenuID = actionMenuId;
    menuItem.ActionPoiID = actionPoiId;
    menuItem.Sender = sender;
    menuItem.Action = action;
    return orderIndex;
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
    Trinity::IteratorPair bounds = sObjectMgr->GetGossipMenuItemsMapBounds(menuId);

    /// Find the one with the given menu item id.
    auto itr = std::find_if(bounds.begin(), bounds.end(), [menuItemId](std::pair<uint32 const, GossipMenuItems> const& itemPair)
    {
        return itemPair.second.OrderIndex == menuItemId;
    });

    if (itr == bounds.end())
        return;

    AddMenuItem(itr->second, sender, action);
}

void GossipMenu::AddMenuItem(GossipMenuItems const& menuItem, uint32 sender, uint32 action)
{
    /// Store texts for localization.
    std::string strOptionText, strBoxText;
    BroadcastTextEntry const* optionBroadcastText = sBroadcastTextStore.LookupEntry(menuItem.OptionBroadcastTextID);
    BroadcastTextEntry const* boxBroadcastText = sBroadcastTextStore.LookupEntry(menuItem.BoxBroadcastTextID);

    /// OptionText
    if (optionBroadcastText)
        strOptionText = DB2Manager::GetBroadcastTextValue(optionBroadcastText, GetLocale());
    else
    {
        strOptionText = menuItem.OptionText;

        /// Find localizations from database.
        if (GetLocale() != LOCALE_enUS)
            if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuItem.MenuID, menuItem.OrderIndex))
                ObjectMgr::GetLocaleString(gossipMenuLocale->OptionText, GetLocale(), strBoxText);
    }

    /// BoxText
    if (boxBroadcastText)
        strBoxText = DB2Manager::GetBroadcastTextValue(boxBroadcastText, GetLocale());
    else
    {
        strBoxText = menuItem.BoxText;

        /// Find localizations from database.
        if (GetLocale() != LOCALE_enUS)
            if (GossipMenuItemsLocale const* gossipMenuLocale = sObjectMgr->GetGossipMenuItemsLocale(menuItem.MenuID, menuItem.OrderIndex))
                ObjectMgr::GetLocaleString(gossipMenuLocale->BoxText, GetLocale(), strBoxText);
    }

    AddMenuItem(menuItem.GossipOptionID, menuItem.OrderIndex, menuItem.OptionNpc, std::move(strOptionText), menuItem.Language, menuItem.Flags,
        menuItem.GossipNpcOptionID, menuItem.ActionMenuID, menuItem.ActionPoiID, menuItem.BoxCoded, menuItem.BoxMoney, std::move(strBoxText),
        menuItem.SpellID, menuItem.OverrideIconID, sender, action);
}

GossipMenuItem const* GossipMenu::GetItem(int32 gossipOptionId) const
{
    auto itr = std::find_if(_menuItems.begin(), _menuItems.end(), [gossipOptionId](GossipMenuItem const& item)
    {
        return item.GossipOptionID == gossipOptionId;
    });

    if (itr != _menuItems.end())
        return &*itr;

    return nullptr;
}

GossipMenuItem const* GossipMenu::GetItemByIndex(uint32 orderIndex) const
{
    auto itr = std::find_if(_menuItems.begin(), _menuItems.end(), [orderIndex](GossipMenuItem const& item)
    {
        return item.OrderIndex == orderIndex;
    });

    if (itr != _menuItems.end())
        return &*itr;

    return nullptr;
}

uint32 GossipMenu::GetMenuItemSender(uint32 orderIndex) const
{
    GossipMenuItem const* item = GetItemByIndex(orderIndex);
    if (item)
        return item->Sender;

    return 0;
}

uint32 GossipMenu::GetMenuItemAction(uint32 orderIndex) const
{
    GossipMenuItem const* item = GetItemByIndex(orderIndex);
    if (item)
        return item->Action;

    return 0;
}

bool GossipMenu::IsMenuItemCoded(uint32 orderIndex) const
{
    GossipMenuItem const* item = GetItemByIndex(orderIndex);
    if (item)
        return item->BoxCoded;

    return 0;
}

void GossipMenu::ClearMenu()
{
    _menuItems.clear();
}

PlayerMenu::PlayerMenu(WorldSession* session) : _session(session)
{
    if (_session)
        _gossipMenu.SetLocale(_session->GetSessionDbLocaleIndex());
}

PlayerMenu::~PlayerMenu() = default;

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
    if (GossipMenuAddon const* addon = sObjectMgr->GetGossipMenuAddon(packet.GossipID))
    {
        packet.FriendshipFactionID = addon->FriendshipFactionID;
        packet.LfgDungeonsID = addon->LfgDungeonsID;
    }

    if (NpcText const* text = sObjectMgr->GetNpcText(titleTextId))
        packet.BroadcastTextID = Trinity::Containers::SelectRandomWeightedContainerElement(text->Data, [](NpcTextData const& data) { return data.Probability; })->BroadcastTextID;

    packet.GossipOptions.reserve(_gossipMenu.GetMenuItems().size());
    for (GossipMenuItem const& item : _gossipMenu.GetMenuItems())
    {
        WorldPackets::NPC::ClientGossipOptions& opt = packet.GossipOptions.emplace_back();
        opt.GossipOptionID = item.GossipOptionID;
        opt.OptionNPC = item.OptionNpc;
        opt.OptionFlags = item.BoxCoded;    // makes pop up box password
        opt.OptionCost = item.BoxMoney;     // money required to open menu, 2.0.3
        opt.OptionLanguage = item.Language;
        opt.Flags = item.Flags;
        opt.OrderIndex = item.OrderIndex;
        opt.Text = item.OptionText;         // text for gossip item
        opt.Confirm = item.BoxText;         // accept text (related to money) pop up box, 2.0.3
        opt.Status = GossipOptionStatus::Available;
        opt.SpellID = item.SpellID;
        opt.OverrideIconID = item.OverrideIconID;
    }

    packet.GossipText.resize(_questMenu.GetMenuItemCount());
    uint32 count = 0;
    for (uint8 i = 0; i < _questMenu.GetMenuItemCount(); ++i)
    {
        QuestMenuItem const& item = _questMenu.GetItem(i);
        uint32 questID = item.QuestId;
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questID))
        {
            WorldPackets::NPC::ClientGossipText& text = packet.GossipText[count];
            text.QuestID = questID;
            text.ContentTuningID = quest->GetContentTuningId();
            text.QuestType = item.QuestIcon;
            text.QuestFlags[0] = quest->GetFlags();
            text.QuestFlags[1] = quest->GetFlagsEx();
            text.QuestFlags[2] = quest->GetFlagsEx2();
            text.Repeatable = quest->IsTurnIn() && quest->IsRepeatable() && !quest->IsDailyOrWeekly() && !quest->IsMonthly();
            text.ResetByScheduler = quest->IsResetByScheduler();
            text.Important = quest->IsImportant();
            text.Meta = quest->IsMeta();

            text.QuestTitle = quest->GetLogTitle();
            LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (QuestTemplateLocale const* localeData = sObjectMgr->GetQuestLocale(questID))
                    ObjectMgr::GetLocaleString(localeData->LogTitle, localeConstant, text.QuestTitle);

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
        TC_LOG_ERROR("sql.sql", "Request to send non-existing PointOfInterest (Id: {}), ignored.", id);
        return;
    }

    WorldPackets::NPC::GossipPOI packet;
    packet.ID = pointOfInterest->ID;
    packet.Name = pointOfInterest->Name;

    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
    if (localeConstant != LOCALE_enUS)
        if (PointOfInterestLocale const* localeData = sObjectMgr->GetPointOfInterestLocale(id))
            ObjectMgr::GetLocaleString(localeData->Name, localeConstant, packet.Name);

    packet.Flags = pointOfInterest->Flags;
    packet.Pos = pointOfInterest->Pos;
    packet.Icon = pointOfInterest->Icon;
    packet.Importance = pointOfInterest->Importance;
    packet.WMOGroupID = pointOfInterest->WMOGroupID;

    _session->SendPacket(packet.Write());
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/

QuestMenu::QuestMenu()
{
    _questMenuItems.reserve(4);                                    // can be set for max from most often sizes to speedup push_back and less memory use
}

QuestMenu::~QuestMenu() = default;

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

void PlayerMenu::SendQuestGiverQuestListMessage(Object* questgiver)
{
    ObjectGuid guid = questgiver->GetGUID();
    LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();

    WorldPackets::Quest::QuestGiverQuestListMessage questList;
    questList.QuestGiverGUID = guid;

    if (QuestGreeting const* questGreeting = sObjectMgr->GetQuestGreeting(questgiver->GetTypeId(), questgiver->GetEntry()))
    {
        questList.GreetEmoteDelay = questGreeting->EmoteDelay;
        questList.GreetEmoteType = questGreeting->EmoteType;
        questList.Greeting = questGreeting->Text;

        if (localeConstant != LOCALE_enUS)
            if (QuestGreetingLocale const* questGreetingLocale = sObjectMgr->GetQuestGreetingLocale(questgiver->GetTypeId(), questgiver->GetEntry()))
                ObjectMgr::GetLocaleString(questGreetingLocale->Greeting, localeConstant, questList.Greeting);
    }

    for (uint32 i = 0; i < _questMenu.GetMenuItemCount(); ++i)
    {
        QuestMenuItem const& questMenuItem = _questMenu.GetItem(i);

        uint32 questID = questMenuItem.QuestId;

        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questID))
        {
            questList.QuestDataText.emplace_back();
            WorldPackets::NPC::ClientGossipText& text = questList.QuestDataText.back();
            text.QuestID = questID;
            text.ContentTuningID = quest->GetContentTuningId();
            text.QuestType = questMenuItem.QuestIcon;
            text.QuestFlags[0] = quest->GetFlags();
            text.QuestFlags[1] = quest->GetFlagsEx();
            text.QuestFlags[2] = quest->GetFlagsEx2();
            text.Repeatable = quest->IsTurnIn() && quest->IsRepeatable() && !quest->IsDailyOrWeekly() && !quest->IsMonthly();
            text.ResetByScheduler = quest->IsResetByScheduler();
            text.Important = quest->IsImportant();
            text.Meta = quest->IsMeta();

            text.QuestTitle = quest->GetLogTitle();
            LocaleConstant localeConstant = _session->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
                if (QuestTemplateLocale const* localeData = sObjectMgr->GetQuestLocale(questID))
                    ObjectMgr::GetLocaleString(localeData->LogTitle, localeConstant, text.QuestTitle);
        }
    }

    _session->SendPacket(questList.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE NPC={}", guid.ToString());
}

void PlayerMenu::SendQuestGiverStatus(QuestGiverStatus questStatus, ObjectGuid npcGUID) const
{
    WorldPackets::Quest::QuestGiverStatus packet;
    packet.QuestGiver.Guid = npcGUID;
    packet.QuestGiver.Status = questStatus;

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_STATUS NPC={}, status={}", npcGUID.ToString(), AsUnderlyingType(questStatus));
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
    std::transform(quest->GetConditionalQuestDescription().begin(), quest->GetConditionalQuestDescription().end(), std::back_inserter(packet.ConditionalDescriptionText), [localeConstant](QuestConditionalText const& text)
    {
        std::string_view content = text.Text[LOCALE_enUS];
        ObjectMgr::GetLocaleString(text.Text, localeConstant, content);
        return WorldPackets::Quest::ConditionalQuestText{ text.PlayerConditionId, text.QuestgiverCreatureId, content };
    });

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

    packet.QuestGiverGUID = npcGUID;
    packet.InformUnit = _session->GetPlayer()->GetPlayerSharingQuest();
    packet.QuestID = quest->GetQuestId();
    packet.QuestPackageID = quest->GetQuestPackageID();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.PortraitGiverMount = quest->GetQuestGiverPortraitMount();
    packet.PortraitGiverModelSceneID = quest->GetQuestGiverPortraitModelSceneId();
    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.QuestInfoID = quest->GetQuestInfoID();
    packet.QuestSessionBonus = 0; //quest->GetQuestSessionBonus(); // this is only sent while quest session is active
    packet.AutoLaunched = autoLaunched;
    packet.ResetByScheduler = quest->IsResetByScheduler();
    packet.DisplayPopup = displayPopup;
    packet.QuestFlags[0] = quest->GetFlags() & (sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT) ? ~QUEST_FLAGS_AUTO_ACCEPT : ~0);
    packet.QuestFlags[1] = quest->GetFlagsEx();
    packet.QuestFlags[2] = quest->GetFlagsEx2();
    packet.SuggestedPartyMembers = quest->GetSuggestedPlayers();

    // Is there a better way? what about game objects?
    if (Creature const* creature = ObjectAccessor::GetCreature(*_session->GetPlayer(), npcGUID))
        packet.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;

    // RewardSpell can teach multiple spells in trigger spell effects. But not all effects must be SPELL_EFFECT_LEARN_SPELL. See example spell 33950
    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(quest->GetRewSpell(), DIFFICULTY_NONE))
        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_LEARN_SPELL))
                packet.LearnSpells.push_back(spellEffectInfo.TriggerSpell);

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
        packet.Objectives[i].Type = objs[i].Type;
        packet.Objectives[i].ObjectID = objs[i].ObjectID;
        packet.Objectives[i].Amount = objs[i].Amount;
    }

    _session->SendPacket(packet.Write());

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_GIVER_QUEST_DETAILS NPC={}, questid={}", npcGUID.ToString(), quest->GetQuestId());
}

void PlayerMenu::SendQuestQueryResponse(Quest const* quest) const
{
    if (sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
        _session->SendPacket(&quest->QueryData[static_cast<uint32>(_session->GetSessionDbLocaleIndex())]);
    else
    {
        WorldPacket queryPacket = quest->BuildQueryData(_session->GetSessionDbLocaleIndex(), _session->GetPlayer());
        _session->SendPacket(&queryPacket);
    }

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUEST_QUERY_RESPONSE questid={}", quest->GetQuestId());
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
    std::transform(quest->GetConditionalOfferRewardText().begin(), quest->GetConditionalOfferRewardText().end(), std::back_inserter(packet.ConditionalRewardText), [locale](QuestConditionalText const& text)
    {
        std::string_view content = text.Text[LOCALE_enUS];
        ObjectMgr::GetLocaleString(text.Text, locale, content);
        return WorldPackets::Quest::ConditionalQuestText{ text.PlayerConditionId, text.QuestgiverCreatureId, content };
    });

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

    WorldPackets::Quest::QuestGiverOfferReward& offer = packet.QuestData;

    quest->BuildQuestRewards(offer.Rewards, _session->GetPlayer());
    offer.QuestGiverGUID = npcGUID;

    // Is there a better way? what about game objects?
    if (Creature const* creature = ObjectAccessor::GetCreature(*_session->GetPlayer(), npcGUID))
    {
        packet.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;
        offer.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;
    }

    offer.QuestID = quest->GetQuestId();
    offer.AutoLaunched = autoLaunched;
    offer.ResetByScheduler = quest->IsResetByScheduler();
    offer.SuggestedPartyMembers = quest->GetSuggestedPlayers();
    offer.QuestInfoID = quest->GetQuestInfoID();

    for (uint32 i = 0; i < QUEST_EMOTE_COUNT && quest->OfferRewardEmote[i]; ++i)
        offer.Emotes.emplace_back(quest->OfferRewardEmote[i], quest->OfferRewardEmoteDelay[i]);

    offer.QuestFlags[0] = quest->GetFlags();
    offer.QuestFlags[1] = quest->GetFlagsEx();
    offer.QuestFlags[2] = quest->GetFlagsEx2();

    packet.PortraitTurnIn = quest->GetQuestTurnInPortrait();
    packet.PortraitGiver = quest->GetQuestGiverPortrait();
    packet.PortraitGiverMount = quest->GetQuestGiverPortraitMount();
    packet.PortraitGiverModelSceneID = quest->GetQuestGiverPortraitModelSceneId();
    packet.QuestPackageID = quest->GetQuestPackageID();

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_OFFER_REWARD NPC={}, questid={}", npcGUID.ToString(), quest->GetQuestId());
}

void PlayerMenu::SendQuestGiverRequestItems(Quest const* quest, ObjectGuid npcGUID, bool canComplete, bool autoLaunched) const
{
    // We can always call to RequestItems, but this packet only goes out if there are actually
    // items.  Otherwise, we'll skip straight to the OfferReward

    if (!quest->HasQuestObjectiveType(QUEST_OBJECTIVE_ITEM) && canComplete)
    {
        SendQuestGiverOfferReward(quest, npcGUID, true);
        return;
    }

    WorldPackets::Quest::QuestGiverRequestItems packet;

    packet.QuestTitle = quest->GetLogTitle();
    packet.CompletionText = quest->GetRequestItemsText();

    LocaleConstant locale = _session->GetSessionDbLocaleIndex();
    std::transform(quest->GetConditionalRequestItemsText().begin(), quest->GetConditionalRequestItemsText().end(), std::back_inserter(packet.ConditionalCompletionText), [locale](QuestConditionalText const& text)
    {
        std::string_view content = text.Text[LOCALE_enUS];
        ObjectMgr::GetLocaleString(text.Text, locale, content);
        return WorldPackets::Quest::ConditionalQuestText{ text.PlayerConditionId, text.QuestgiverCreatureId, content };
    });

    if (locale != LOCALE_enUS)
    {
        if (QuestTemplateLocale const* questTemplateLocale = sObjectMgr->GetQuestLocale(quest->GetQuestId()))
            ObjectMgr::GetLocaleString(questTemplateLocale->LogTitle, locale, packet.QuestTitle);

        if (QuestRequestItemsLocale const* questRequestItemsLocale = sObjectMgr->GetQuestRequestItemsLocale(quest->GetQuestId()))
            ObjectMgr::GetLocaleString(questRequestItemsLocale->CompletionText, locale, packet.CompletionText);
    }

    packet.QuestGiverGUID = npcGUID;

    // Is there a better way? what about game objects?
    if (Creature const* creature = ObjectAccessor::GetCreature(*_session->GetPlayer(), npcGUID))
        packet.QuestGiverCreatureID = creature->GetCreatureTemplate()->Entry;

    packet.QuestID = quest->GetQuestId();

    if (canComplete)
    {
        packet.CompEmoteDelay = quest->GetCompleteEmoteDelay();
        packet.CompEmoteType = quest->GetCompleteEmote();
    }
    else
    {
        packet.CompEmoteDelay = quest->GetIncompleteEmoteDelay();
        packet.CompEmoteType = quest->GetIncompleteEmote();
    }

    packet.QuestFlags[0] = quest->GetFlags();
    packet.QuestFlags[1] = quest->GetFlagsEx();
    packet.QuestFlags[2] = quest->GetFlagsEx2();
    packet.SuggestPartyMembers = quest->GetSuggestedPlayers();
    packet.QuestInfoID = quest->GetQuestInfoID();

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
    packet.ResetByScheduler = quest->IsResetByScheduler();

    _session->SendPacket(packet.Write());
    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_QUESTGIVER_REQUEST_ITEMS NPC={}, questid={}", npcGUID.ToString(), quest->GetQuestId());
}
