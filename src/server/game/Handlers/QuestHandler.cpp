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

#include "WorldSession.h"
#include "Battleground.h"
#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "Group.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "PoolMgr.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "QuestPools.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "World.h"

void WorldSession::HandleQuestgiverStatusQueryOpcode(WorldPackets::Quest::QuestGiverStatusQuery& packet)
{
    Object* questGiver = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);
    if (!questGiver)
    {
        TC_LOG_INFO("network", "Error in CMSG_QUESTGIVER_STATUS_QUERY, called for non-existing questgiver ({})", packet.QuestGiverGUID.ToString());
        return;
    }

    QuestGiverStatus questStatus = _player->GetQuestDialogStatus(questGiver);

    //inform client about status of quest
    _player->PlayerTalkClass->SendQuestGiverStatus(questStatus, packet.QuestGiverGUID);
}

void WorldSession::HandleQuestgiverHelloOpcode(WorldPackets::Quest::QuestGiverHello& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_HELLO {}", packet.QuestGiverGUID.ToString());

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.QuestGiverGUID, UNIT_NPC_FLAG_QUESTGIVER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleQuestgiverHelloOpcode - {} not found or you can't interact with him.",
            packet.QuestGiverGUID.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // Stop the npc if moving
    if (uint32 pause = creature->GetMovementTemplate().GetInteractionPauseTimer())
        creature->PauseMovement(pause);
    creature->SetHomePosition(creature->GetPosition());

    _player->PlayerTalkClass->ClearMenus();
    if (creature->AI()->OnGossipHello(_player))
        return;

    _player->PrepareGossipMenu(creature, _player->GetGossipMenuForSource(creature), true);
    _player->SendPreparedGossip(creature);
}

void WorldSession::HandleQuestgiverAcceptQuestOpcode(WorldPackets::Quest::QuestGiverAcceptQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_ACCEPT_QUEST {}, quest = {}, startcheat = {}", packet.QuestGiverGUID.ToString(), packet.QuestID, packet.StartCheat);

    Object* object;
    if (!packet.QuestGiverGUID.IsPlayer())
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
    else
        object = ObjectAccessor::FindPlayer(packet.QuestGiverGUID);

    auto CLOSE_GOSSIP_CLEAR_SHARING_INFO = ([this]()
    {
        _player->PlayerTalkClass->SendCloseGossip();
        _player->ClearQuestSharingInfo();
    });

    // no or incorrect quest giver
    if (!object)
    {
        CLOSE_GOSSIP_CLEAR_SHARING_INFO();
        return;
    }

    if (Player* playerQuestObject = object->ToPlayer())
    {
        if ((_player->GetPlayerSharingQuest().IsEmpty() && _player->GetPlayerSharingQuest() != packet.QuestGiverGUID) || !playerQuestObject->CanShareQuest(packet.QuestID))
        {
            CLOSE_GOSSIP_CLEAR_SHARING_INFO();
            return;
        }
        if (!_player->IsInSameRaidWith(playerQuestObject))
        {
            CLOSE_GOSSIP_CLEAR_SHARING_INFO();
            return;
        }
    }
    else
    {
        if (!object->hasQuest(packet.QuestID))
        {
            CLOSE_GOSSIP_CLEAR_SHARING_INFO();
            return;
        }
    }

    // some kind of WPE protection
    if (!_player->CanInteractWithQuestGiver(object))
    {
        CLOSE_GOSSIP_CLEAR_SHARING_INFO();
        return;
    }

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
    {
        // prevent cheating
        if (!GetPlayer()->CanTakeQuest(quest, true))
        {
            CLOSE_GOSSIP_CLEAR_SHARING_INFO();
            return;
        }

        if (!_player->GetPlayerSharingQuest().IsEmpty())
        {
            Player* player = ObjectAccessor::FindPlayer(_player->GetPlayerSharingQuest());
            if (player)
            {
                player->SendPushToPartyResponse(_player, QuestPushReason::Accepted);
                _player->ClearQuestSharingInfo();
            }
        }

        if (_player->CanAddQuest(quest, true))
        {
            _player->AddQuestAndCheckCompletion(quest, object);

            if (quest->IsPushedToPartyOnAccept())
            {
                if (Group* group = _player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* player = itr->GetSource();

                        if (!player || player == _player || !player->IsInMap(_player))     // not self and in same map
                            continue;

                        if (player->CanTakeQuest(quest, true))
                        {
                            player->SetQuestSharingInfo(_player->GetGUID(), quest->GetQuestId());

                            // need confirmation that any gossip window will close
                            player->PlayerTalkClass->SendCloseGossip();

                            _player->SendQuestConfirmAccept(quest, player);
                        }
                    }
                }
            }

            _player->PlayerTalkClass->SendCloseGossip();

            if (quest->HasFlag(QUEST_FLAGS_LAUNCH_GOSSIP_ACCEPT))
            {
                auto launchGossip = [&](WorldObject* worldObject)
                {
                    _player->PlayerTalkClass->ClearMenus();
                    _player->PrepareGossipMenu(worldObject, _player->GetGossipMenuForSource(worldObject), true);
                    _player->SendPreparedGossip(worldObject);
                };

                if (Creature* creature = object->ToCreature())
                    launchGossip(creature);
                else if (GameObject* go = object->ToGameObject())
                    launchGossip(go);
            }

            return;
        }
    }

    CLOSE_GOSSIP_CLEAR_SHARING_INFO();
}

void WorldSession::HandleQuestgiverQueryQuestOpcode(WorldPackets::Quest::QuestGiverQueryQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_QUERY_QUEST QuestGiverGUID = {}, QuestID = {}, RespondToGiver = {}", packet.QuestGiverGUID.ToString(), packet.QuestID, packet.RespondToGiver);

    // Verify that the guid is valid and is a questgiver or involved in the requested quest
    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
    if (!object || (!object->hasQuest(packet.QuestID) && !object->hasInvolvedQuest(packet.QuestID)))
    {
        _player->PlayerTalkClass->SendCloseGossip();
        return;
    }

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
    {
        if (!_player->CanTakeQuest(quest, true))
            return;

        if (quest->IsAutoAccept() && _player->CanAddQuest(quest, true))
            _player->AddQuestAndCheckCompletion(quest, object);

        if (quest->IsTurnIn())
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, object->GetGUID(), _player->CanCompleteQuest(quest->GetQuestId()), true);
        else
            _player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, object->GetGUID(), true, false);
    }
}

void WorldSession::HandleQuestQueryOpcode(WorldPackets::Quest::QueryQuestInfo& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_QUERY quest = {}", packet.QuestID);

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
        _player->PlayerTalkClass->SendQuestQueryResponse(quest);
    else
    {
        WorldPackets::Quest::QueryQuestInfoResponse response;
        response.QuestID = packet.QuestID;
        SendPacket(response.Write());
    }
}

void WorldSession::HandleQuestgiverChooseRewardOpcode(WorldPackets::Quest::QuestGiverChooseReward& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_CHOOSE_REWARD npc = {}, quest = {}, reward = {}",
        packet.QuestGiverGUID.ToString(), packet.QuestID, packet.Choice.Item.ItemID);

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    if (packet.Choice.Item.ItemID)
    {
        switch (packet.Choice.LootItemType)
        {
            case LootItemType::Item:
            {
                ItemTemplate const* rewardProto = sObjectMgr->GetItemTemplate(packet.Choice.Item.ItemID);
                if (!rewardProto)
                {
                    TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player {} {} tried to get invalid reward item (Item Entry: {}) for quest {} (possible packet-hacking detected)",
                        _player->GetName(), _player->GetGUID().ToString(), packet.Choice.Item.ItemID, packet.QuestID);
                    return;
                }

                bool itemValid = false;
                for (uint32 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
                {
                    if (quest->RewardChoiceItemId[i] && quest->RewardChoiceItemType[i] == LootItemType::Item && quest->RewardChoiceItemId[i] == packet.Choice.Item.ItemID)
                    {
                        itemValid = true;
                        break;
                    }
                }

                if (!itemValid && quest->GetQuestPackageID())
                {
                    if (std::vector<QuestPackageItemEntry const*> const* questPackageItems = sDB2Manager.GetQuestPackageItems(quest->GetQuestPackageID()))
                    {
                        for (QuestPackageItemEntry const* questPackageItem : *questPackageItems)
                        {
                            if (uint32(questPackageItem->ItemID) != packet.Choice.Item.ItemID)
                                continue;

                            if (_player->CanSelectQuestPackageItem(questPackageItem))
                            {
                                itemValid = true;
                                break;
                            }
                        }
                    }

                    if (!itemValid)
                    {
                        if (std::vector<QuestPackageItemEntry const*> const* questPackageItems = sDB2Manager.GetQuestPackageItemsFallback(quest->GetQuestPackageID()))
                        {
                            for (QuestPackageItemEntry const* questPackageItem : *questPackageItems)
                            {
                                if (uint32(questPackageItem->ItemID) != packet.Choice.Item.ItemID)
                                    continue;

                                itemValid = true;
                                break;
                            }
                        }
                    }
                }

                if (!itemValid)
                {
                    TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player {} {} tried to get reward item (Item Entry: {}) wich is not a reward for quest {} (possible packet-hacking detected)",
                        _player->GetName(), _player->GetGUID().ToString(), packet.Choice.Item.ItemID, packet.QuestID);
                    return;
                }
                break;
            }
            case LootItemType::Currency:
            {
                if (!sCurrencyTypesStore.HasRecord(packet.Choice.Item.ItemID))
                {
                    TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player {} {} tried to get invalid reward currency (Currency ID: {}) for quest {} (possible packet-hacking detected)",
                        _player->GetName(), _player->GetGUID().ToString(), packet.Choice.Item.ItemID, packet.QuestID);
                    return;
                }

                bool currencyValid = false;
                for (uint32 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
                {
                    if (quest->RewardChoiceItemId[i] && quest->RewardChoiceItemType[i] == LootItemType::Currency && quest->RewardChoiceItemId[i] == packet.Choice.Item.ItemID)
                    {
                        currencyValid = true;
                        break;
                    }
                }

                if (!currencyValid)
                {
                    TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player {} {} tried to get reward currency (Currency ID: {}) wich is not a reward for quest {} (possible packet-hacking detected)",
                        _player->GetName(), _player->GetGUID().ToString(), packet.Choice.Item.ItemID, packet.QuestID);
                    return;
                }
                break;
            }
            default:
                break;
        }
    }

    Object* object = _player;

    if (!quest->HasFlag(QUEST_FLAGS_AUTO_COMPLETE))
    {
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);
        if (!object || !object->hasInvolvedQuest(packet.QuestID))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }

    if ((!_player->CanSeeStartQuest(quest) &&  _player->GetQuestStatus(packet.QuestID) == QUEST_STATUS_NONE) ||
        (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE && !quest->IsTurnIn()))
    {
        TC_LOG_ERROR("network", "Error in QUEST_STATUS_COMPLETE: player {} {} tried to complete quest {}, but is not allowed to do so (possible packet-hacking or high latency)",
            _player->GetName(), _player->GetGUID().ToString(), packet.QuestID);
        return;
    }

    if (_player->CanRewardQuest(quest, true)) // First, check if player is allowed to turn the quest in (all objectives completed). If not, we send players to the offer reward screen
    {
        if (_player->CanRewardQuest(quest, packet.Choice.LootItemType, packet.Choice.Item.ItemID, true)) // Then check if player can receive the reward item (if inventory is not full, if player doesn't have too many unique items, and so on). If not, the client will close the gossip window
        {
            _player->RewardQuest(quest, packet.Choice.LootItemType, packet.Choice.Item.ItemID, object);
        }
    }
    else
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
}

void WorldSession::HandleQuestgiverRequestRewardOpcode(WorldPackets::Quest::QuestGiverRequestReward& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_REQUEST_REWARD npc = {}, quest = {}", packet.QuestGiverGUID.ToString(), packet.QuestID);

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    if (!quest->HasFlag(QUEST_FLAGS_AUTO_COMPLETE))
    {
        Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);
        if (!object || !object->hasInvolvedQuest(packet.QuestID))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }

    if (_player->CanCompleteQuest(packet.QuestID))
        _player->CompleteQuest(packet.QuestID);

    if (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE)
        return;

    if (quest)
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
}

void WorldSession::HandleQuestLogRemoveQuest(WorldPackets::Quest::QuestLogRemoveQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTLOG_REMOVE_QUEST slot = {}", packet.Entry);

    if (packet.Entry < MAX_QUEST_LOG_SIZE)
    {
        if (uint32 questId = _player->GetQuestSlotQuestId(packet.Entry))
        {
            if (!_player->TakeQuestSourceItem(questId, true))
                return;                                     // can't un-equip some items, reject quest cancel

            Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
            QuestStatus oldStatus = _player->GetQuestStatus(questId);

            if (quest)
            {
                if (quest->HasFlagEx(QUEST_FLAGS_EX_NO_ABANDON_ONCE_BEGUN))
                    for (QuestObjective const& objective : quest->Objectives)
                        if (_player->IsQuestObjectiveComplete(packet.Entry, quest, objective))
                            return;

                if (quest->GetLimitTime())
                    _player->RemoveTimedQuest(questId);

                if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
                {
                    _player->pvpInfo.IsHostile = _player->pvpInfo.IsInHostileArea || _player->HasPvPForcingQuest();
                    _player->UpdatePvPState();
                }
            }

            _player->SetQuestSlot(packet.Entry, 0);
            _player->TakeQuestSourceItem(questId, true); // remove quest src item from player
            _player->AbandonQuest(questId); // remove all quest items player received before abandoning quest. Note, this does not remove normal drop items that happen to be quest requirements.
            _player->RemoveActiveQuest(questId);
            _player->DespawnPersonalSummonsForQuest(questId);

            TC_LOG_INFO("network", "Player {} abandoned quest {}", _player->GetGUID().ToString(), questId);

            if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
            {
                // prepare Quest Tracker datas
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_ABANDON_TIME);
                stmt->setUInt32(0, questId);
                stmt->setUInt64(1, _player->GetGUID().GetCounter());

                // add to Quest Tracker
                CharacterDatabase.Execute(stmt);
            }

            sScriptMgr->OnQuestStatusChange(_player, questId);

            if (quest)
                sScriptMgr->OnQuestStatusChange(_player, quest, oldStatus, QUEST_STATUS_NONE);
        }

        _player->UpdateCriteria(CriteriaType::AbandonAnyQuest, 1);
    }
}

void WorldSession::HandleQuestConfirmAccept(WorldPackets::Quest::QuestConfirmAccept& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_CONFIRM_ACCEPT questId = {}", packet.QuestID);

    if (_player->GetSharedQuestID() != uint32(packet.QuestID))
        return;

    _player->ClearQuestSharingInfo();
    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    Player* originalPlayer = ObjectAccessor::FindPlayer(_player->GetPlayerSharingQuest());
    if (!originalPlayer)
        return;

    if (!_player->IsInSameRaidWith(originalPlayer))
        return;

    if (!originalPlayer->IsActiveQuest(packet.QuestID))
        return;

    if (!_player->CanTakeQuest(quest, true))
        return;

    if (!_player->CanAddQuest(quest, true))
        return;

    _player->AddQuestAndCheckCompletion(quest, nullptr); // NULL, this prevent DB script from duplicate running

    if (quest->GetSrcSpell() > 0)
        _player->CastSpell(_player, quest->GetSrcSpell(), true);
}

void WorldSession::HandleQuestgiverCompleteQuest(WorldPackets::Quest::QuestGiverCompleteQuest& packet)
{
    bool autoCompleteMode = packet.FromScript; // 0 - standart complete quest mode with npc, 1 - auto-complete mode

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_COMPLETE_QUEST npc = {}, questId = {} self-complete: {}", packet.QuestGiverGUID.ToString(), packet.QuestID, autoCompleteMode ? 1 : 0);

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    Object* object = nullptr;
    if (autoCompleteMode)
        object = _player;
    else
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);

    if (!object)
        return;

    if (!quest->HasFlag(QUEST_FLAGS_AUTO_COMPLETE))
    {
        if (!object->hasInvolvedQuest(packet.QuestID))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }
    else
    {
        // Do not allow completing quests on other players.
        if (packet.QuestGiverGUID != _player->GetGUID())
            return;
    }

    if (!_player->CanSeeStartQuest(quest) && _player->GetQuestStatus(packet.QuestID) == QUEST_STATUS_NONE)
    {
        TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player {} [{}] tried to complete quest [entry: {}] without being in possession of the quest!",
            _player->GetName(), _player->GetGUID().ToString(), packet.QuestID);
        return;
    }

    if (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE)
    {
        if (quest->IsRepeatable())
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanCompleteRepeatableQuest(quest), false);
        else
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanRewardQuest(quest, false), false);
    }
    else
    {
        if (quest->HasQuestObjectiveType(QUEST_OBJECTIVE_ITEM))                  // some items required
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanRewardQuest(quest, false), false);
        else                                            // no items required
            _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
    }
}

void WorldSession::HandleQuestgiverCloseQuest(WorldPackets::Quest::QuestGiverCloseQuest& questGiverCloseQuest)
{
    if (_player->FindQuestSlot(questGiverCloseQuest.QuestID) >= MAX_QUEST_LOG_SIZE)
        return;

    Quest const* quest = sObjectMgr->GetQuestTemplate(questGiverCloseQuest.QuestID);
    if (!quest)
        return;

    sScriptMgr->OnQuestAcknowledgeAutoAccept(_player, quest);
}

void WorldSession::HandlePushQuestToParty(WorldPackets::Quest::PushQuestToParty& packet)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    Player* const sender = GetPlayer();

    if (!_player->CanShareQuest(packet.QuestID))
    {
        sender->SendPushToPartyResponse(sender, QuestPushReason::NotAllowed);
        return;
    }

    // in pool and not currently available (wintergrasp weekly, dalaran weekly) - can't share
    if (!sQuestPoolMgr->IsQuestActive(packet.QuestID))
    {
        sender->SendPushToPartyResponse(sender, QuestPushReason::NotDaily);
        return;
    }

    Group* group = sender->GetGroup();
    if (!group)
    {
        sender->SendPushToPartyResponse(sender, QuestPushReason::NotInParty);
        return;
    }

    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* receiver = itr->GetSource();

        if (!receiver || receiver == sender)
            continue;

        if (!receiver->GetPlayerSharingQuest().IsEmpty())
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Busy);
            continue;
        }

        if (!receiver->IsAlive())
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Dead);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::DeadToRecipient, quest);
            continue;
        }

        switch (receiver->GetQuestStatus(packet.QuestID))
        {
            case QUEST_STATUS_REWARDED:
            {
                sender->SendPushToPartyResponse(receiver, QuestPushReason::AlreadyDone);
                receiver->SendPushToPartyResponse(sender, QuestPushReason::AlreadyDoneToRecipient, quest);
                continue;
            }
            case QUEST_STATUS_INCOMPLETE:
            case QUEST_STATUS_COMPLETE:
            {
                sender->SendPushToPartyResponse(receiver, QuestPushReason::OnQuest);
                receiver->SendPushToPartyResponse(sender, QuestPushReason::OnQuestToRecipient, quest);
                continue;
            }
            default:
                break;
        }

        if (!receiver->SatisfyQuestLog(false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::LogFull);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::LogFullToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestDay(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::AlreadyDone);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::AlreadyDoneToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestMinLevel(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::LowLevel);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::LowLevelToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestMaxLevel(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::HighLevel);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::HighLevelToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestClass(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Class);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::ClassToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestRace(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Race);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::RaceToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestMinReputation(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::LowFaction);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::LowFactionToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestMaxReputation(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::HighFaction);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::HighFactionToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestDependentQuests(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Prerequisite);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::PrerequisiteToRecipient, quest);
            continue;
        }

        if (!receiver->SatisfyQuestExpansion(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Expansion);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::ExpansionToRecipient, quest);
            continue;
        }

        if (!receiver->CanTakeQuest(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QuestPushReason::Invalid);
            receiver->SendPushToPartyResponse(sender, QuestPushReason::InvalidToRecipient, quest);
            continue;
        }

        sender->SendPushToPartyResponse(receiver, QuestPushReason::Success);

        if (quest->IsTurnIn() && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
            receiver->PlayerTalkClass->SendQuestGiverRequestItems(quest, sender->GetGUID(), receiver->CanCompleteRepeatableQuest(quest), true);
        else
        {
            receiver->SetQuestSharingInfo(sender->GetGUID(), quest->GetQuestId());
            receiver->PlayerTalkClass->SendQuestGiverQuestDetails(quest, receiver->GetGUID(), true, false);
            if (quest->IsAutoAccept() && receiver->CanAddQuest(quest, true) && receiver->CanTakeQuest(quest, true))
            {
                receiver->AddQuestAndCheckCompletion(quest, sender);
                sender->SendPushToPartyResponse(receiver, QuestPushReason::Accepted);
                receiver->ClearQuestSharingInfo();
            }
        }
    }
}

void WorldSession::HandleQuestPushResult(WorldPackets::Quest::QuestPushResult& packet)
{
    if (!_player->GetPlayerSharingQuest().IsEmpty())
    {
        if (_player->GetPlayerSharingQuest() == packet.SenderGUID)
            if (Player* player = ObjectAccessor::FindPlayer(_player->GetPlayerSharingQuest()))
                player->SendPushToPartyResponse(_player, static_cast<QuestPushReason>(packet.Result));

        _player->ClearQuestSharingInfo();
    }
}

void WorldSession::HandleQuestgiverStatusMultipleQuery(WorldPackets::Quest::QuestGiverStatusMultipleQuery& /*packet*/)
{
    _player->SendQuestGiverStatusMultiple();
}

void WorldSession::HandleRequestWorldQuestUpdate(WorldPackets::Quest::RequestWorldQuestUpdate& /*packet*/)
{
    WorldPackets::Quest::WorldQuestUpdateResponse response;

    /// @todo: 7.x Has to be implemented
    //response.WorldQuestUpdates.push_back(WorldPackets::Quest::WorldQuestUpdateInfo(lastUpdate, questID, timer, variableID, value));

    SendPacket(response.Write());
}

void WorldSession::HandlePlayerChoiceResponse(WorldPackets::Quest::ChoiceResponse& choiceResponse)
{
    if (_player->PlayerTalkClass->GetInteractionData().PlayerChoiceId != uint32(choiceResponse.ChoiceID))
    {
        TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_CHOICE_RESPONSE: {} tried to respond to invalid player choice {} (allowed {}) (possible packet-hacking detected)",
            GetPlayerInfo(), choiceResponse.ChoiceID, _player->PlayerTalkClass->GetInteractionData().PlayerChoiceId);
        return;
    }

    PlayerChoice const* playerChoice = sObjectMgr->GetPlayerChoice(choiceResponse.ChoiceID);
    if (!playerChoice)
        return;

    PlayerChoiceResponse const* playerChoiceResponse = playerChoice->GetResponseByIdentifier(choiceResponse.ResponseIdentifier);
    if (!playerChoiceResponse)
    {
        TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_CHOICE_RESPONSE: {} tried to select invalid player choice response {} (possible packet-hacking detected)",
            GetPlayerInfo(), choiceResponse.ResponseIdentifier);
        return;
    }

    sScriptMgr->OnPlayerChoiceResponse(GetPlayer(), choiceResponse.ChoiceID, choiceResponse.ResponseIdentifier);

    if (playerChoiceResponse->Reward)
    {
        if (playerChoiceResponse->Reward->TitleId)
            _player->SetTitle(sCharTitlesStore.AssertEntry(playerChoiceResponse->Reward->TitleId), false);

        if (playerChoiceResponse->Reward->PackageId)
            _player->RewardQuestPackage(playerChoiceResponse->Reward->PackageId, ItemContext::NONE);

        if (playerChoiceResponse->Reward->SkillLineId && _player->HasSkill(playerChoiceResponse->Reward->SkillLineId))
            _player->UpdateSkillPro(playerChoiceResponse->Reward->SkillLineId, 1000, playerChoiceResponse->Reward->SkillPointCount);

        if (playerChoiceResponse->Reward->HonorPointCount)
            _player->AddHonorXP(playerChoiceResponse->Reward->HonorPointCount);

        if (playerChoiceResponse->Reward->Money)
            _player->ModifyMoney(playerChoiceResponse->Reward->Money, false);

        if (playerChoiceResponse->Reward->Xp)
            _player->GiveXP(playerChoiceResponse->Reward->Xp, nullptr, 0.0f);

        for (PlayerChoiceResponseRewardItem const& item : playerChoiceResponse->Reward->Items)
        {
            ItemPosCountVec dest;
            if (_player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item.Id, item.Quantity) == EQUIP_ERR_OK)
            {
                Item* newItem = _player->StoreNewItem(dest, item.Id, true, GenerateItemRandomBonusListId(item.Id), {}, ItemContext::Quest_Reward, &item.BonusListIDs);
                _player->SendNewItem(newItem, item.Quantity, true, false);
            }
        }

        for (PlayerChoiceResponseRewardEntry const& currency : playerChoiceResponse->Reward->Currency)
            _player->ModifyCurrency(currency.Id, currency.Quantity);

        for (PlayerChoiceResponseRewardEntry const& faction : playerChoiceResponse->Reward->Faction)
            _player->GetReputationMgr().ModifyReputation(sFactionStore.AssertEntry(faction.Id), faction.Quantity);
    }
}

void WorldSession::HandleUiMapQuestLinesRequest(WorldPackets::Quest::UiMapQuestLinesRequest& uiMapQuestLinesRequest)
{
    UiMapEntry const* uiMap = sUiMapStore.LookupEntry(uiMapQuestLinesRequest.UiMapID);
    if (!uiMap)
        return;

    WorldPackets::Quest::UiMapQuestLinesResponse response;
    response.UiMapID = uiMap->ID;

    if (std::vector<uint32> const* questLines = sObjectMgr->GetUiMapQuestLinesList(uiMap->ID))
    {
        for (uint32 questLineId : *questLines)
        {
            std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(questLineId);
            if (!questLineQuests)
                continue;

            for (QuestLineXQuestEntry const* questLineQuest : *questLineQuests)
                if (Quest const* quest = sObjectMgr->GetQuestTemplate(questLineQuest->QuestID))
                    if (_player->CanTakeQuest(quest, false))
                        response.QuestLineXQuestIDs.push_back(questLineQuest->ID);
        }
    }

    if (std::vector<uint32> const* quests = sObjectMgr->GetUiMapQuestsList(uiMap->ID))
    {
        for (uint32 questId : *quests)
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
                if (_player->CanTakeQuest(quest, false))
                    response.QuestIDs.push_back(questId);
    }

    SendPacket(response.Write());
}
