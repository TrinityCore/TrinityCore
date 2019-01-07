/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "Battleground.h"
#include "Common.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "UnitAI.h"
#include "World.h"
#include "WorldPacket.h"

void WorldSession::HandleQuestgiverStatusQueryOpcode(WorldPackets::Quest::QuestGiverStatusQuery& packet)
{
    uint32 questStatus = DIALOG_STATUS_NONE;

    Object* questGiver = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);
    if (!questGiver)
    {
        TC_LOG_INFO("network", "Error in CMSG_QUESTGIVER_STATUS_QUERY, called for non-existing questgiver (%s)", packet.QuestGiverGUID.ToString().c_str());
        return;
    }

    switch (questGiver->GetTypeId())
    {
        case TYPEID_UNIT:
        {
            TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_STATUS_QUERY for npc, %s", questGiver->GetGUID().ToString().c_str());
            if (!questGiver->ToCreature()->IsHostileTo(_player)) // do not show quest status to enemies
                questStatus = _player->GetQuestDialogStatus(questGiver);
            break;
        }
        case TYPEID_GAMEOBJECT:
        {
            TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_STATUS_QUERY for GameObject %s", questGiver->GetGUID().ToString().c_str());
            questStatus = _player->GetQuestDialogStatus(questGiver);
            break;
        }
        default:
            TC_LOG_ERROR("network", "QuestGiver called for unexpected type %u", questGiver->GetTypeId());
            break;
    }

    //inform client about status of quest
    _player->PlayerTalkClass->SendQuestGiverStatus(questStatus, packet.QuestGiverGUID);
}

void WorldSession::HandleQuestgiverHelloOpcode(WorldPackets::Quest::QuestGiverHello& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_HELLO %s", packet.QuestGiverGUID.ToString().c_str());

#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.QuestGiverGUID.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.QuestGiverGUID))
            creature->SendMirrorSound(_player, 0);
#endif
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.QuestGiverGUID, UNIT_NPC_FLAG_QUESTGIVER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleQuestgiverHelloOpcode - %s not found or you can't interact with him.",
            packet.QuestGiverGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
    // Stop the npc if moving
    creature->StopMoving();

    if (sScriptMgr->OnGossipHello(_player, creature))
        return;

    _player->PrepareGossipMenu(creature, creature->GetCreatureTemplate()->GossipMenuId, true);
    _player->SendPreparedGossip(creature);

    creature->GetAI()->sGossipHello(_player);
}

void WorldSession::HandleQuestgiverAcceptQuestOpcode(WorldPackets::Quest::QuestGiverAcceptQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_ACCEPT_QUEST %s, quest = %u, startcheat = %u", packet.QuestGiverGUID.ToString().c_str(), packet.QuestID, packet.StartCheat);

    Object* object;
    if (!packet.QuestGiverGUID.IsPlayer())
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
    else
        object = ObjectAccessor::FindPlayer(packet.QuestGiverGUID);

#define CLOSE_GOSSIP_CLEAR_DIVIDER() \
    do { \
        _player->PlayerTalkClass->SendCloseGossip(); \
        _player->SetDivider(ObjectGuid::Empty); \
    } while (0)

    // no or incorrect quest giver
    if (!object)
    {
        CLOSE_GOSSIP_CLEAR_DIVIDER();
        return;
    }

    if (Player* playerQuestObject = object->ToPlayer())
    {
        if ((_player->GetDivider().IsEmpty() && _player->GetDivider() != packet.QuestGiverGUID) || !playerQuestObject->CanShareQuest(packet.QuestID))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
        if (!_player->IsInSameRaidWith(playerQuestObject))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
    }
    else
    {
        if (!object->hasQuest(packet.QuestID))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
    }

    // some kind of WPE protection
    if (!_player->CanInteractWithQuestGiver(object))
    {
        CLOSE_GOSSIP_CLEAR_DIVIDER();
        return;
    }

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
    {
        // prevent cheating
        if (!GetPlayer()->CanTakeQuest(quest, true))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }

        if (!_player->GetDivider().IsEmpty())
        {
            Player* player = ObjectAccessor::FindPlayer(_player->GetDivider());
            if (player)
            {
                player->SendPushToPartyResponse(_player, QUEST_PUSH_ACCEPTED);
                _player->SetDivider(ObjectGuid::Empty);
            }
        }

        if (_player->CanAddQuest(quest, true))
        {
            _player->AddQuestAndCheckCompletion(quest, object);

            if (quest->HasFlag(QUEST_FLAGS_PARTY_ACCEPT))
            {
                if (Group* group = _player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* player = itr->GetSource();

                        if (!player || player == _player)     // not self
                            continue;

                        if (player->CanTakeQuest(quest, true))
                        {
                            player->SetDivider(_player->GetGUID());

                            // need confirmation that any gossip window will close
                            player->PlayerTalkClass->SendCloseGossip();

                            _player->SendQuestConfirmAccept(quest, player);
                        }
                    }
                }
            }

            _player->PlayerTalkClass->SendCloseGossip();

            if (quest->GetSrcSpell() > 0)
                _player->CastSpell(_player, quest->GetSrcSpell(), true);

            return;
        }
    }

    CLOSE_GOSSIP_CLEAR_DIVIDER();

#undef CLOSE_GOSSIP_CLEAR_DIVIDER
}

void WorldSession::HandleQuestgiverQueryQuestOpcode(WorldPackets::Quest::QuestGiverQueryQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_QUERY_QUEST QuestGiverGUID = %s, QuestID = %u, RespondToGiver = %u", packet.QuestGiverGUID.ToString().c_str(), packet.QuestID, packet.RespondToGiver);

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

        if (quest->IsAutoComplete())
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, object->GetGUID(), _player->CanCompleteQuest(quest->GetQuestId()), true);
        else
            _player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, object->GetGUID(), true, false);
    }
}

void WorldSession::HandleQuestQueryOpcode(WorldPackets::Quest::QueryQuestInfo& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_QUERY quest = %u", packet.QuestID);

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
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_CHOOSE_REWARD npc = %s, quest = %u, reward = %u", packet.QuestGiverGUID.ToString().c_str(), packet.QuestID, packet.ItemChoiceID);

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    // This is Real Item Entry, not slot id as pre 5.x
    if (packet.ItemChoiceID)
    {
        ItemTemplate const* rewardProto = sObjectMgr->GetItemTemplate(packet.ItemChoiceID);
        if (!rewardProto)
        {
            TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player %s (%s) tried to get invalid reward item (Item Entry: %u) for quest %u (possible packet-hacking detected)", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.ItemChoiceID, packet.QuestID);
            return;
        }

        bool itemValid = false;
        for (uint32 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
        {
            if (quest->RewardChoiceItemId[i] && quest->RewardChoiceItemId[i] == uint32(packet.ItemChoiceID))
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
                    if (questPackageItem->ItemID != packet.ItemChoiceID)
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
                        if (questPackageItem->ItemID != packet.ItemChoiceID)
                            continue;

                        itemValid = true;
                        break;
                    }
                }
            }
        }

        if (!itemValid)
        {
            TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_QUESTGIVER_CHOOSE_REWARD: player %s (%s) tried to get reward item (Item Entry: %u) wich is not a reward for quest %u (possible packet-hacking detected)", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.ItemChoiceID, packet.QuestID);
            return;
        }
    }

    Object* object = _player;

    if (!quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
    {
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);
        if (!object || !object->hasInvolvedQuest(packet.QuestID))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }

    if ((!_player->CanSeeStartQuest(quest) &&  _player->GetQuestStatus(packet.QuestID) == QUEST_STATUS_NONE) ||
        (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE && !quest->IsAutoComplete()))
    {
        TC_LOG_ERROR("network", "Error in QUEST_STATUS_COMPLETE: player %s (%s) tried to complete quest %u, but is not allowed to do so (possible packet-hacking or high latency)",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.QuestID);
        return;
    }

    if (_player->CanRewardQuest(quest, packet.ItemChoiceID, true))
    {
        _player->RewardQuest(quest, packet.ItemChoiceID, object);

        switch (object->GetTypeId())
        {
            case TYPEID_UNIT:
            case TYPEID_PLAYER:
            {
                //For AutoSubmition was added plr case there as it almost same exclute AI script cases.
                Creature* creatureQGiver = object->ToCreature();
                if (!creatureQGiver || !sScriptMgr->OnQuestReward(_player, creatureQGiver, quest, packet.ItemChoiceID))
                {
                    // Send next quest
                    if (Quest const* nextQuest = _player->GetNextQuest(packet.QuestGiverGUID, quest))
                    {
                        // Only send the quest to the player if the conditions are met
                        if (_player->CanTakeQuest(nextQuest, false))
                        {
                            if (nextQuest->IsAutoAccept() && _player->CanAddQuest(nextQuest, true))
                                _player->AddQuestAndCheckCompletion(nextQuest, object);

                            _player->PlayerTalkClass->SendQuestGiverQuestDetails(nextQuest, packet.QuestGiverGUID, true, false);
                        }
                    }

                    if (creatureQGiver)
                        creatureQGiver->GetAI()->sQuestReward(_player, quest, packet.ItemChoiceID);
                }
                break;
            }
            case TYPEID_GAMEOBJECT:
            {
                GameObject* questGiver = object->ToGameObject();
                if (!sScriptMgr->OnQuestReward(_player, questGiver, quest, packet.ItemChoiceID))
                {
                    // Send next quest
                    if (Quest const* nextQuest = _player->GetNextQuest(packet.QuestGiverGUID, quest))
                    {
                        // Only send the quest to the player if the conditions are met
                        if (_player->CanTakeQuest(nextQuest, false))
                        {
                            if (nextQuest->IsAutoAccept() && _player->CanAddQuest(nextQuest, true))
                                _player->AddQuestAndCheckCompletion(nextQuest, object);

                            _player->PlayerTalkClass->SendQuestGiverQuestDetails(nextQuest, packet.QuestGiverGUID, true, false);
                        }
                    }

                    questGiver->AI()->QuestReward(_player, quest, packet.ItemChoiceID);
                }
                break;
            }
            default:
                break;
        }
    }
    else
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
}

void WorldSession::HandleQuestgiverRequestRewardOpcode(WorldPackets::Quest::QuestGiverRequestReward& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_REQUEST_REWARD npc = %s, quest = %u", packet.QuestGiverGUID.ToString().c_str(), packet.QuestID);

    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);
    if (!object || !object->hasInvolvedQuest(packet.QuestID))
        return;

    // some kind of WPE protection
    if (!_player->CanInteractWithQuestGiver(object))
        return;

    if (_player->CanCompleteQuest(packet.QuestID))
        _player->CompleteQuest(packet.QuestID);

    if (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE)
        return;

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
}

void WorldSession::HandleQuestLogRemoveQuest(WorldPackets::Quest::QuestLogRemoveQuest& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTLOG_REMOVE_QUEST slot = %u", packet.Entry);

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
                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
                    _player->RemoveTimedQuest(questId);

                if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
                {
                    _player->pvpInfo.IsHostile = _player->pvpInfo.IsInHostileArea || _player->HasPvPForcingQuest();
                    _player->UpdatePvPState();
                }

            }

            _player->TakeQuestSourceItem(questId, true); // remove quest src item from player
            _player->AbandonQuest(questId); // remove all quest items player received before abandoning quest. Note, this does not remove normal drop items that happen to be quest requirements.
            _player->RemoveActiveQuest(questId);
            _player->RemoveCriteriaTimer(CRITERIA_TIMED_TYPE_QUEST, questId);

            TC_LOG_INFO("network", "%s abandoned quest %u", _player->GetGUID().ToString().c_str(), questId);

            if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
            {
                // prepare Quest Tracker datas
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_ABANDON_TIME);
                stmt->setUInt32(0, questId);
                stmt->setUInt64(1, _player->GetGUID().GetCounter());

                // add to Quest Tracker
                CharacterDatabase.Execute(stmt);
            }

            sScriptMgr->OnQuestStatusChange(_player, questId);

            if (quest)
                sScriptMgr->OnQuestStatusChange(_player, quest, oldStatus, QUEST_STATUS_NONE);
        }

        _player->SetQuestSlot(packet.Entry, 0);

        _player->UpdateCriteria(CRITERIA_TYPE_QUEST_ABANDONED, 1);
    }
}

void WorldSession::HandleQuestConfirmAccept(WorldPackets::Quest::QuestConfirmAccept& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_CONFIRM_ACCEPT questId = %u", packet.QuestID);

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID))
    {
        if (!quest->HasFlag(QUEST_FLAGS_PARTY_ACCEPT))
            return;

        Player* originalPlayer = ObjectAccessor::FindPlayer(_player->GetDivider());
        if (!originalPlayer)
            return;

        if (!_player->IsInSameRaidWith(originalPlayer))
            return;

        if (!originalPlayer->IsActiveQuest(packet.QuestID))
            return;

        if (!_player->CanTakeQuest(quest, true))
            return;

        if (_player->CanAddQuest(quest, true))
        {
            _player->AddQuestAndCheckCompletion(quest, NULL); // NULL, this prevent DB script from duplicate running

            if (quest->GetSrcSpell() > 0)
                _player->CastSpell(_player, quest->GetSrcSpell(), true);
        }
    }

    _player->SetDivider(ObjectGuid::Empty);
}

void WorldSession::HandleQuestgiverCompleteQuest(WorldPackets::Quest::QuestGiverCompleteQuest& packet)
{
    bool autoCompleteMode = packet.FromScript; // 0 - standart complete quest mode with npc, 1 - auto-complete mode

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_COMPLETE_QUEST npc = %s, questId = %u self-complete: %u", packet.QuestGiverGUID.ToString().c_str(), packet.QuestID, autoCompleteMode ? 1 : 0);

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    if (autoCompleteMode && !quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
        return;

    Object* object = nullptr;
    if (autoCompleteMode)
        object = _player;
    else
        object = ObjectAccessor::GetObjectByTypeMask(*_player, packet.QuestGiverGUID, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);

    if (!object)
        return;

    if (!autoCompleteMode)
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
        TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player %s [%s] tried to complete quest [entry: %u] without being in possession of the quest!",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.QuestID);
        return;
    }

    if (Battleground* bg = _player->GetBattleground())
        bg->HandleQuestComplete(packet.QuestID, _player);

    if (_player->GetQuestStatus(packet.QuestID) != QUEST_STATUS_COMPLETE)
    {
        if (quest->IsRepeatable())
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanCompleteRepeatableQuest(quest), false);
        else
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanRewardQuest(quest, false), false);
    }
    else
    {
        if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER))                  // some items required
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, packet.QuestGiverGUID, _player->CanRewardQuest(quest, false), false);
        else                                            // no items required
            _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, packet.QuestGiverGUID, true);
    }
}

void WorldSession::HandlePushQuestToParty(WorldPackets::Quest::PushQuestToParty& packet)
{
    if (!_player->CanShareQuest(packet.QuestID))
        return;

    Quest const* quest = sObjectMgr->GetQuestTemplate(packet.QuestID);
    if (!quest)
        return;

    Player * const sender = GetPlayer();

    Group* group = sender->GetGroup();
    if (!group)
        return;

    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* receiver = itr->GetSource();

        if (!receiver || receiver == sender)
            continue;

        if (!receiver->SatisfyQuestStatus(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PUSH_ONQUEST);
            continue;
        }

        if (receiver->GetQuestStatus(packet.QuestID) == QUEST_STATUS_COMPLETE)
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PUSH_ALREADY_DONE);
            continue;
        }

        if (!receiver->CanTakeQuest(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PUSH_INVALID);
            continue;
        }

        if (!receiver->SatisfyQuestLog(false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PUSH_LOG_FULL);
            continue;
        }

        if (!receiver->GetDivider().IsEmpty())
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PUSH_BUSY);
            continue;
        }

        sender->SendPushToPartyResponse(receiver, QUEST_PUSH_SUCCESS);

        if (quest->IsAutoAccept() && receiver->CanAddQuest(quest, true) && receiver->CanTakeQuest(quest, true))
            receiver->AddQuestAndCheckCompletion(quest, sender);

        if (quest->IsAutoComplete() && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
            receiver->PlayerTalkClass->SendQuestGiverRequestItems(quest, sender->GetGUID(), receiver->CanCompleteRepeatableQuest(quest), true);
        else
        {
            receiver->SetDivider(sender->GetGUID());
            receiver->PlayerTalkClass->SendQuestGiverQuestDetails(quest, receiver->GetGUID(), true, false);
        }
    }
}

void WorldSession::HandleQuestPushResult(WorldPackets::Quest::QuestPushResult& packet)
{
    if (!_player->GetDivider().IsEmpty())
    {
        if (_player->GetDivider() == packet.SenderGUID)
            if (Player* player = ObjectAccessor::FindPlayer(_player->GetDivider()))
                player->SendPushToPartyResponse(_player, static_cast<QuestPushReason>(packet.Result));

        _player->SetDivider(ObjectGuid::Empty);
    }
}

void WorldSession::HandleQuestgiverStatusMultipleQuery(WorldPackets::Quest::QuestGiverStatusMultipleQuery& /*packet*/)
{
    _player->SendQuestGiverStatusMultiple();
}

void WorldSession::HandleRequestWorldQuestUpdate(WorldPackets::Quest::RequestWorldQuestUpdate& /*packet*/)
{
    WorldPackets::Quest::WorldQuestUpdate response;

    /// @todo: 7.x Has to be implemented
    //response.WorldQuestUpdates.push_back(WorldPackets::Quest::WorldQuestUpdateInfo(lastUpdate, questID, timer, variableID, value));

    SendPacket(response.Write());
}

void WorldSession::HandlePlayerChoiceResponse(WorldPackets::Quest::ChoiceResponse& choiceResponse)
{
    if (_player->PlayerTalkClass->GetInteractionData().PlayerChoiceId != uint32(choiceResponse.ChoiceID))
    {
        TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_CHOICE_RESPONSE: %s tried to respond to invalid player choice %d (allowed %u) (possible packet-hacking detected)",
            GetPlayerInfo().c_str(), choiceResponse.ChoiceID, _player->PlayerTalkClass->GetInteractionData().PlayerChoiceId);
        return;
    }

    PlayerChoice const* playerChoice = sObjectMgr->GetPlayerChoice(choiceResponse.ChoiceID);
    if (!playerChoice)
        return;

    PlayerChoiceResponse const* playerChoiceResponse = playerChoice->GetResponse(choiceResponse.ResponseID);
    if (!playerChoiceResponse)
    {
        TC_LOG_ERROR("entities.player.cheat", "Error in CMSG_CHOICE_RESPONSE: %s tried to select invalid player choice response %d (possible packet-hacking detected)",
            GetPlayerInfo().c_str(), choiceResponse.ResponseID);
        return;
    }

    sScriptMgr->OnPlayerChoiceResponse(GetPlayer(), choiceResponse.ChoiceID, choiceResponse.ResponseID);

    if (playerChoiceResponse->Reward)
    {
        if (playerChoiceResponse->Reward->TitleId)
            _player->SetTitle(sCharTitlesStore.AssertEntry(playerChoiceResponse->Reward->TitleId), false);

        if (playerChoiceResponse->Reward->PackageId)
            _player->RewardQuestPackage(playerChoiceResponse->Reward->PackageId);

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
                Item* newItem = _player->StoreNewItem(dest, item.Id, true, GenerateItemRandomPropertyId(item.Id), {}, 0, item.BonusListIDs);
                _player->SendNewItem(newItem, item.Quantity, true, false);
            }
        }

        for (PlayerChoiceResponseRewardEntry const& currency : playerChoiceResponse->Reward->Currency)
            _player->ModifyCurrency(currency.Id, currency.Quantity);

        for (PlayerChoiceResponseRewardEntry const& faction : playerChoiceResponse->Reward->Faction)
            _player->GetReputationMgr().ModifyReputation(sFactionStore.AssertEntry(faction.Id), faction.Quantity);
    }
}
