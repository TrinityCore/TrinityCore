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
#include "Item.h"
#include "ItemPackets.h"
#include "Log.h"
#include "Map.h"
#include "NPCPackets.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "SpellInfo.h"
#include "Trainer.h"
#include "WorldPacket.h"

enum class TabardVendorType : int32
{
    Guild       = 0,
    Personal    = 1,
};

void WorldSession::HandleTabardVendorActivateOpcode(WorldPackets::NPC::TabardVendorActivate const& tabardVendorActivate)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(tabardVendorActivate.Vendor, UNIT_NPC_FLAG_TABARDDESIGNER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTabardVendorActivateOpcode - {} not found or you can not interact with him.", tabardVendorActivate.Vendor.ToString());
        return;
    }

    TabardVendorType type = TabardVendorType(tabardVendorActivate.Type);
    if (type != TabardVendorType::Guild && type != TabardVendorType::Personal)
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendTabardVendorActivate(tabardVendorActivate.Vendor, TabardVendorType(tabardVendorActivate.Type));
}

void WorldSession::SendTabardVendorActivate(ObjectGuid guid, TabardVendorType type)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = [&]
    {
        switch (type)
        {
            case TabardVendorType::Guild:
                return PlayerInteractionType::GuildTabardVendor;
            case TabardVendorType::Personal:
                return PlayerInteractionType::PersonalTabardVendor;
            default:
                ABORT_MSG("Unsupported tabard vendor type %d", AsUnderlyingType(type));
        }
    }();
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
}

void WorldSession::SendShowMailBox(ObjectGuid guid)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = PlayerInteractionType::MailInfo;
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
}

void WorldSession::HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - {} not found or you can not interact with him.", packet.Unit.ToString());
        return;
    }

    if (uint32 trainerId = npc->GetTrainerId())
        SendTrainerList(npc, trainerId);
    else
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - Creature id {} has no trainer data.", npc->GetEntry());
}

void WorldSession::SendTrainerList(Creature* npc, uint32 trainerId)
{
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(trainerId);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - trainer spells not found for trainer {} id {}", npc->GetGUID().ToString(), trainerId);
        return;
    }

    _player->PlayerTalkClass->GetInteractionData().StartInteraction(npc->GetGUID(), PlayerInteractionType::Trainer);
    _player->PlayerTalkClass->GetInteractionData().GetTrainer()->Id = trainerId;
    trainer->SendSpells(npc, _player, GetSessionDbLocaleIndex());
}

void WorldSession::HandleTrainerBuySpellOpcode(WorldPackets::NPC::TrainerBuySpell& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL {}, learn spell id is: {}", packet.TrainerGUID.ToString(), packet.SpellID);

    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.TrainerGUID, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - {} not found or you can not interact with him.", packet.TrainerGUID.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (!_player->PlayerTalkClass->GetInteractionData().IsInteractingWith(packet.TrainerGUID, PlayerInteractionType::Trainer))
        return;

    if (_player->PlayerTalkClass->GetInteractionData().GetTrainer()->Id != uint32(packet.TrainerID))
        return;

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(packet.TrainerID);
    if (!trainer)
        return;

    trainer->TeachSpell(npc, _player, packet.SpellID);
}

void WorldSession::HandleGossipHelloOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_GOSSIP, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipHelloOpcode - {} not found or you can not interact with him.", packet.Unit.ToString());
        return;
    }

    // set faction visible if needed
    if (FactionTemplateEntry const* factionTemplateEntry = sFactionTemplateStore.LookupEntry(unit->GetFaction()))
        _player->GetReputationMgr().SetVisible(factionTemplateEntry);

    GetPlayer()->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Interacting);

    // Stop the npc if moving
    if (uint32 pause = unit->GetMovementTemplate().GetInteractionPauseTimer())
        unit->PauseMovement(pause);
    unit->SetHomePosition(unit->GetPosition());

    if (unit->IsAreaSpiritHealer())
    {
        _player->SetAreaSpiritHealer(unit);
        _player->SendAreaSpiritHealerTime(unit);
    }

    _player->PlayerTalkClass->ClearMenus();
    if (!unit->AI()->OnGossipHello(_player))
    {
//        _player->TalkedToCreature(unit->GetEntry(), unit->GetGUID());
        _player->PrepareGossipMenu(unit, _player->GetGossipMenuForSource(unit), true);
        _player->SendPreparedGossip(unit);
    }
}

void WorldSession::HandleGossipSelectOptionOpcode(WorldPackets::NPC::GossipSelectOption& packet)
{
    GossipMenuItem const* gossipMenuItem = _player->PlayerTalkClass->GetGossipMenu().GetItem(packet.GossipOptionID);
    if (!gossipMenuItem)
        return;

    // Prevent cheating on C++ scripted menus
    if (!_player->PlayerTalkClass->GetInteractionData().IsInteractingWith(packet.GossipUnit, PlayerInteractionType::Gossip))
        return;

    Creature* unit = nullptr;
    GameObject* go = nullptr;
    if (packet.GossipUnit.IsCreatureOrVehicle())
    {
        unit = GetPlayer()->GetNPCIfCanInteractWith(packet.GossipUnit, UNIT_NPC_FLAG_GOSSIP, UNIT_NPC_FLAG_2_NONE);
        if (!unit)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - {} not found or you can't interact with him.", packet.GossipUnit.ToString());
            return;
        }
    }
    else if (packet.GossipUnit.IsGameObject())
    {
        go = _player->GetGameObjectIfCanInteractWith(packet.GossipUnit);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - {} not found or you can't interact with it.", packet.GossipUnit.ToString());
            return;
        }
    }
    else
    {

        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported {}.", packet.GossipUnit.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if ((unit && unit->GetScriptId() != unit->LastUsedScriptID) || (go && go->GetScriptId() != go->LastUsedScriptID))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - Script reloaded while in use, ignoring and set new scipt id");
        if (unit)
            unit->LastUsedScriptID = unit->GetScriptId();

        if (go)
            go->LastUsedScriptID = go->GetScriptId();
        _player->PlayerTalkClass->SendCloseGossip();
        return;
    }

    if (!packet.PromotionCode.empty())
    {
        if (unit)
        {
            if (!unit->AI()->OnGossipSelectCode(_player, packet.GossipID, gossipMenuItem->OrderIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipOptionID, packet.GossipID);
        }
        else
        {
            if (!go->AI()->OnGossipSelectCode(_player, packet.GossipID, gossipMenuItem->OrderIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipOptionID, packet.GossipID);
        }
    }
    else
    {
        if (unit)
        {
            if (!unit->AI()->OnGossipSelect(_player, packet.GossipID, gossipMenuItem->OrderIndex))
                _player->OnGossipSelect(unit, packet.GossipOptionID, packet.GossipID);
        }
        else
        {
            if (!go->AI()->OnGossipSelect(_player, packet.GossipID, gossipMenuItem->OrderIndex))
                _player->OnGossipSelect(go, packet.GossipOptionID, packet.GossipID);
        }
    }
}

void WorldSession::HandleSpiritHealerActivate(WorldPackets::NPC::SpiritHealerActivate& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Healer, UNIT_NPC_FLAG_SPIRIT_HEALER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSpiritHealerActivateOpcode - {} not found or you can not interact with him.", packet.Healer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendSpiritResurrect();
}

void WorldSession::SendSpiritResurrect()
{
    _player->ResurrectPlayer(0.5f, true);
    _player->DurabilityLossAll(0.25f, true);

    // get corpse nearest graveyard
    WorldSafeLocsEntry const* corpseGrave = nullptr;
    WorldLocation corpseLocation = _player->GetCorpseLocation();
    if (_player->HasCorpse())
    {
        corpseGrave = sObjectMgr->GetClosestGraveyard(corpseLocation, _player->GetTeam(), _player);
    }

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr->GetClosestGraveyard(*_player, _player->GetTeam(), _player);

        if (corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->Loc);
    }
}

void WorldSession::HandleBinderActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    if (!GetPlayer()->IsInWorld() || !GetPlayer()->IsAlive())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_INNKEEPER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBinderActivateOpcode - {} not found or you can not interact with him.", packet.Unit.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendBindPoint(unit);
}

void WorldSession::SendBindPoint(Creature* npc)
{
    // prevent set homebind to instances in any case
    if (GetPlayer()->GetMap()->Instanceable())
        return;

    uint32 bindspell = 3286;

    // send spell for homebinding (3286)
    npc->CastSpell(_player, bindspell, true);

    _player->PlayerTalkClass->SendCloseGossip();
}

void WorldSession::HandleRequestStabledPets(WorldPackets::NPC::RequestStabledPets& packet)
{
    if (!CheckStableMaster(packet.StableMaster))
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // remove mounts this fix bug where getting pet from stable while mounted deletes pet.
    if (GetPlayer()->IsMounted())
        GetPlayer()->RemoveAurasByType(SPELL_AURA_MOUNTED);

    _player->SetStableMaster(packet.StableMaster);
}

void WorldSession::SendPetStableResult(StableResult result)
{
    WorldPackets::Pet::PetStableResult petStableResult;
    petStableResult.Result = AsUnderlyingType(result);
    SendPacket(petStableResult.Write());
}

void WorldSession::HandleSetPetSlot(WorldPackets::NPC::SetPetSlot& setPetSlot)
{
    if (!CheckStableMaster(setPetSlot.StableMaster))
    {
        SendPetStableResult(StableResult::NotStableMaster);
        return;
    }

    if (setPetSlot.DestSlot >= PET_SAVE_LAST_STABLE_SLOT)
    {
        SendPetStableResult(StableResult::InvalidSlot);
        return;
    }

    _player->SetPetSlot(setPetSlot.PetNumber, PetSaveMode(setPetSlot.DestSlot));
}

void WorldSession::HandleRepairItemOpcode(WorldPackets::Item::RepairItem& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_REPAIR_ITEM: Npc {}, Item {}, UseGuildBank: {}",
        packet.NpcGUID.ToString(), packet.ItemGUID.ToString(), packet.UseGuildBank);

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.NpcGUID, UNIT_NPC_FLAG_REPAIR, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleRepairItemOpcode - {} not found or you can not interact with him.", packet.NpcGUID.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // reputation discount
    float discountMod = _player->GetReputationPriceDiscount(unit);

    if (!packet.ItemGUID.IsEmpty())
    {
        TC_LOG_DEBUG("network", "ITEM: Repair {}, at {}", packet.ItemGUID.ToString(), packet.NpcGUID.ToString());

        Item* item = _player->GetItemByGuid(packet.ItemGUID);
        if (item)
            _player->DurabilityRepair(item->GetPos(), true, discountMod);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at {}", packet.NpcGUID.ToString());
        _player->DurabilityRepairAll(true, discountMod, packet.UseGuildBank);
    }
}

void WorldSession::HandleChromieTimeSelectExpansion(WorldPackets::NPC::ChromieTimeSelectExpansion& expansion)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    uint32 questId = 0;
    uint32 conversationId = 0;

    UIChromieTimeExpansionInfoEntry const* expansionInfo = sUIChromieTimeExpansionInfoStore.LookupEntry(expansion.Expansion);
    if (!expansionInfo)
    {
        TC_LOG_INFO("server", "Player {} sent invalid ChromieTime ExpansionID {}", player->GetGUID().ToString(), expansion.Expansion);
        return;
    }

    if (expansionInfo->RecommendPlayerConditionID > 0 &&
        !sConditionMgr->IsPlayerMeetingCondition(player, expansionInfo->RecommendPlayerConditionID))
    {
        
    }

    if (expansionInfo->SpellID > 0)
    {
        SpellCastResult result = player->CastSpell(player, expansionInfo->SpellID);
        if (result != SPELL_CAST_OK)
        {
            TC_LOG_INFO("server", "ChromieTime Spell cast failed for player {} SpellID {} result {}",
                player->GetGUID().ToString(), expansionInfo->SpellID, result);
        }
    }

    switch (expansion.Expansion)
    {
    case 5:
        questId = 60891;
        conversationId = 14405;
        break;
    case 6:
        questId = 60120;
        conversationId = 14304;
        break;
    case 7:
        questId = 60096;
        conversationId = 14278;
        break;
    case 8:
        questId = 60965;
        conversationId = 14303;
        break;
    case 9:
        questId = 34398;
        conversationId = 14300;
        break;
    case 10:
        questId = 40519;
        conversationId = 14406;
        break;
    case 14:
        questId = 60545;
        conversationId = 20312;
        break;
    case 15:
        questId = 46727;
        break;
    case 16:
        questId = 65436;
        break;
    default:
        break;
    }

    if (questId)
        if (_player->GetQuestStatus(questId) == QUEST_STATUS_NONE)
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
                if (Creature* chromie = ObjectAccessor::GetCreature(*_player, expansion.GUID))
                    _player->AddQuest(quest, chromie);

    if (conversationId)
        Conversation::CreateConversation(conversationId, _player, *_player, { _player->GetGUID() });

    WorldPackets::NPC::ChromieTimeSelectExpansionSuccess success;
    SendPacket(success.Write());
}
