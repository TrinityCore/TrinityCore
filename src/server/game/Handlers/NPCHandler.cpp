/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "SpellMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "Trainer.h"
#include "WorldPacket.h"
#include "Creature.h"
#include "Pet.h"
#include "Spell.h"
#include "Chat.h"
#include "CharacterDatabaseCache.h"

enum StableResultCode
{
    STABLE_ERR_MONEY        = 0x01,                         // "you don't have enough money"
    STABLE_ERR_STABLE       = 0x06,                         // currently used in most fail cases
    STABLE_SUCCESS_STABLE   = 0x08,                         // stable success
    STABLE_SUCCESS_UNSTABLE = 0x09,                         // unstable/swap success
    STABLE_SUCCESS_BUY_SLOT = 0x0A,                         // buy slot success
};

void WorldSession::HandleTabardVendorActivateOpcode(WorldPacket& recv_data)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.Unit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.Unit))
            creature->SendMirrorSound(_player, 0);
#endif
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TABARDDESIGNER, UNIT_NPC_FLAG_2_NONE);
    ObjectGuid guid;
    recv_data >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TABARDDESIGNER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTabardVendorActivateOpcode - {} not found or you can not interact with him.", packet.Unit.ToString());
        DEBUG_LOG("WORLD: HandleTabardVendorActivateOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    SendTabardVendorActivate(guid);
}

void WorldSession::SendTabardVendorActivate(ObjectGuid guid)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = PlayerInteractionType::TabardVendor;
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
    WorldPacket data(MSG_TABARDVENDOR_ACTIVATE, 8);
    data << ObjectGuid(guid);
    SendPacket(&data);
}

void WorldSession::HandleBankerActivateOpcode(WorldPacket& recv_data)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = PlayerInteractionType::MailInfo;
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
}
    ObjectGuid guid;

void WorldSession::HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.Unit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.Unit))
            creature->SendMirrorSound(_player, 0);
#endif
    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - {} not found or you can not interact with him.", packet.Unit.ToString());
    DEBUG_LOG("WORLD: Received CMSG_BANKER_ACTIVATE");

    recv_data >> guid;

    if (!CheckBanker(guid))
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STAT_FEIGN_DEATH))
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    SendShowBank(guid);
}

    if (uint32 trainerId = sObjectMgr->GetCreatureDefaultTrainer(npc->GetEntry()))
        SendTrainerList(npc, trainerId);
    else
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - Creature id {} has no trainer data.", npc->GetEntry());
void WorldSession::SendShowBank(ObjectGuid guid)
{
    WorldPacket data(SMSG_SHOW_BANK, 8);
    data << ObjectGuid(guid);
    m_currentBankerGUID = guid;
    SendPacket(&data);
}

void WorldSession::HandleTrainerListOpcode(WorldPacket& recv_data)
{
    ObjectGuid guid;

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(trainerId);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - trainer spells not found for trainer {} id {}", npc->GetGUID().ToString(), trainerId);
    recv_data >> guid;

    SendTrainerList(guid);
}

static void SendTrainerSpellHelper(WorldPacket& data, TrainerSpell const* tSpell, uint32 triggerSpell, TrainerSpellState state, float fDiscountMod, bool can_learn_primary_prof)
{
    SpellEntry const* triggerInfo = sSpellMgr.GetSpellEntry(triggerSpell);
    uint32 spellLevel = 0;
    if (tSpell->reqLevel)
        spellLevel = tSpell->reqLevel;
    else if (triggerInfo)
        spellLevel = triggerInfo->spellLevel;
    else
        return;

    bool primary_prof_first_rank = sSpellMgr.IsPrimaryProfessionFirstRankSpell(triggerSpell);

    SpellChainNode const* chain_node = sSpellMgr.GetSpellChainNode(triggerSpell);

    data << uint32(tSpell->spell);
    data << uint8(state == TRAINER_SPELL_GREEN_DISABLED ? TRAINER_SPELL_GREEN : state);
    data << uint32(floor(tSpell->spellCost * fDiscountMod));

    data << uint32(primary_prof_first_rank && can_learn_primary_prof ? 1 : 0);
    // primary prof. learn confirmation dialog
    data << uint32(primary_prof_first_rank ? 1 : 0);    // must be equal prev. field to have learn button in enabled state
    data << uint8(spellLevel);
    data << uint32(tSpell->reqSkill);
    data << uint32(tSpell->reqSkillValue);
    // Nostalrius: le client veut spellreq1, spellreq2 avec spellreq2 != 0 seulement si spellreq1 != 0.
    if (chain_node)
    {
        if (chain_node->req)
        {
            data << uint32(chain_node->req);
            data << uint32(chain_node->prev);
        }
        else
        {
            data << uint32(chain_node->prev);
            data << uint32(0);
        }
    }
    else
        data << uint32(0) << uint32(0);
    data << uint32(0);
}

void WorldSession::SendTrainerList(ObjectGuid guid)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL {}, learn spell id is: {}", packet.TrainerGUID.ToString(), packet.SpellID);
    DEBUG_LOG("WORLD: SendTrainerList");

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - {} not found or you can not interact with him.", packet.TrainerGUID.ToString());
        DEBUG_LOG("WORLD: SendTrainerList - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    // trainer list loaded at check;
    if (!unit->IsTrainerOf(_player, true))
        return;

    CreatureInfo const* ci = unit->GetCreatureInfo();
    if (!ci)
        return;

    TrainerSpellData const* cSpells = unit->GetTrainerSpells();
    TrainerSpellData const* tSpells = unit->GetTrainerTemplateSpells();

    if (!cSpells && !tSpells)
    {
        DEBUG_LOG("WORLD: SendTrainerList - Training spells not found for %s", guid.GetString().c_str());
        return;
    }

void WorldSession::HandleGossipHelloOpcode(WorldPackets::NPC::Hello& packet)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.Unit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.Unit))
            creature->SendMirrorSound(_player, 0);
#endif
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_GOSSIP, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    uint32 maxcount = (cSpells ? cSpells->spellList.size() : 0) + (tSpells ? tSpells->spellList.size() : 0);
    uint32 trainer_type = cSpells && cSpells->trainerType ? cSpells->trainerType : (tSpells ? tSpells->trainerType : 0);

    std::string strTitle;
    if (TrainerGreetingLocale const* trainerGreeting = sObjectMgr.GetTrainerGreetingLocale(guid.GetEntry()))
    {
        int locale_idx = GetSessionDbLocaleIndex();

        if ((int32)trainerGreeting->Content.size() > locale_idx + 1 && !trainerGreeting->Content[locale_idx + 1].empty())
            strTitle = trainerGreeting->Content[locale_idx + 1];
        else
            strTitle = trainerGreeting->Content[0];
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipHelloOpcode - {} not found or you can not interact with him.", packet.Unit.ToString());
        return;
        strTitle = GetMangosString(LANG_NPC_TAINER_HELLO);
    }

    WorldPacket data(SMSG_TRAINER_LIST, 8 + 4 + 4 + maxcount * 38 + strTitle.size() + 1);
    data << ObjectGuid(guid);
    data << uint32(trainer_type);

    size_t count_pos = data.wpos();
    data << uint32(maxcount);

    // Stop the npc if moving
    if (uint32 pause = unit->GetMovementTemplate().GetInteractionPauseTimer())
        unit->PauseMovement(pause);
    unit->SetHomePosition(unit->GetPosition());
    // reputation discount
    float fDiscountMod = _player->GetReputationPriceDiscount(unit);
    bool can_learn_primary_prof = GetPlayer()->GetFreePrimaryProfessionPoints() > 0;

    uint32 count = 0;

    if (cSpells)
    {
        for (const auto& itr : cSpells->spellList)
        {
            TrainerSpell const* tSpell = &itr.second;

            uint32 triggerSpell = sSpellMgr.GetSpellEntry(tSpell->spell)->EffectTriggerSpell[0];

            if (!_player->IsSpellFitByClassAndRace(triggerSpell))
                continue;

            TrainerSpellState state = _player->GetTrainerSpellState(tSpell);

            SendTrainerSpellHelper(data, tSpell, triggerSpell, state, fDiscountMod, can_learn_primary_prof);

            ++count;
        }
    }

    _player->PlayerTalkClass->ClearMenus();
    if (!unit->AI()->OnGossipHello(_player))
    if (tSpells)
    {
//        _player->TalkedToCreature(unit->GetEntry(), unit->GetGUID());
        _player->PrepareGossipMenu(unit, unit->GetCreatureTemplate()->GossipMenuId, true);
        _player->SendPreparedGossip(unit);
    }
}
        for (const auto& itr : tSpells->spellList)
        {
            TrainerSpell const* tSpell = &itr.second;

            uint32 triggerSpell = sSpellMgr.GetSpellEntry(tSpell->spell)->EffectTriggerSpell[0];

            if (!_player->IsSpellFitByClassAndRace(triggerSpell))
                continue;

            TrainerSpellState state = _player->GetTrainerSpellState(tSpell);

            SendTrainerSpellHelper(data, tSpell, triggerSpell, state, fDiscountMod, can_learn_primary_prof);

            ++count;
        }
    }

    data << strTitle;

    data.put<uint32>(count_pos, count);
    SendPacket(&data);
}

void WorldSession::SendTrainingSuccess(ObjectGuid guid, uint32 spellId)
{
    GossipMenuItem const* gossipMenuItem = _player->PlayerTalkClass->GetGossipMenu().GetItem(packet.GossipOptionID);
    if (!gossipMenuItem)
        return;
    WorldPacket data(SMSG_TRAINER_BUY_SUCCEEDED, 12);
    data << ObjectGuid(guid);
    data << uint32(spellId);                                // should be same as in packet from client
    SendPacket(&data);
}

void WorldSession::SendTrainingFailure(ObjectGuid guid, uint32 serviceId, uint32 errorCode)
{
    WorldPacket data(SMSG_TRAINER_BUY_FAILED, 16);
    data << ObjectGuid(guid);
    data << uint32(serviceId);
    data << uint32(errorCode);
    SendPacket(&data);
}

    Item* item = nullptr;
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
void WorldSession::HandleTrainerBuySpellOpcode(WorldPacket& recv_data)
{
    ObjectGuid guid;
    uint32 spellId = 0;

    recv_data >> guid >> spellId;
    DEBUG_LOG("WORLD: Received CMSG_TRAINER_BUY_SPELL Trainer: %s, learn spell id is: %u", guid.GetString().c_str(), spellId);

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);

    if (!unit || !unit->IsTrainerOf(_player, true) || !unit->IsWithinLOSInMap(_player))
    {
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_UNAVAILABLE);
        DEBUG_LOG("WORLD: HandleTrainerBuySpellOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    // Check if the spell is present in the trainer's spell list.
    TrainerSpellData const* cSpells = unit->GetTrainerSpells();
    TrainerSpellData const* tSpells = unit->GetTrainerTemplateSpells();

    if (!cSpells && !tSpells)
    {
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_UNAVAILABLE);
        return;
    }
        
    // Try to find the spell in npc_trainer.
    TrainerSpell const* trainer_spell = cSpells ? cSpells->Find(spellId) : nullptr;

    // Not found, try find it in npc_trainer_template.
    if (!trainer_spell && tSpells)
        trainer_spell = tSpells->Find(spellId);

    // Not found anywhere, cheating?
    if (!trainer_spell)
    {
        go = _player->GetGameObjectIfCanInteractWith(packet.GossipUnit);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - {} not found or you can't interact with it.", packet.GossipUnit.ToString());
            return;
        }
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_UNAVAILABLE);
        return;
    }
    
    // Can't be learned, cheat? Or double learn with lags...
    if (_player->GetTrainerSpellState(trainer_spell) != TRAINER_SPELL_GREEN)
    {
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_NOT_ENOUGH_SKILL);
        return;
    }

    SpellEntry const* proto = sSpellMgr.GetSpellEntry(trainer_spell->spell);

    // Apply reputation discount.
    uint32 nSpellCost = uint32(floor(trainer_spell->spellCost * _player->GetReputationPriceDiscount(unit)));

    // Check money requirement.
    if (_player->GetMoney() < nSpellCost)
    {
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_NOT_ENOUGH_MONEY);
        return;
    }
    else if (packet.GossipUnit.IsItem())
    {
        item = _player->GetItemByGuid(packet.GossipUnit);
        if (!item || _player->IsBankPos(item->GetPos()))
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }
    else if (packet.GossipUnit.IsPlayer())
    {
        if (packet.GossipUnit != _player->GetGUID() || static_cast<uint32>(packet.GossipID) != _player->PlayerTalkClass->GetGossipMenu().GetMenuId())
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }

    // All is good. Spell can be learned if we reach this point.
    _player->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    _player->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    _player->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

    Spell* spell;
    if (proto->SpellVisual == 222)
        spell = new Spell(_player, proto, false);
    else
        spell = new Spell(unit, proto, false);

    SpellCastTargets targets;
    targets.setUnitTarget(_player);

    SpellCastResult cast_result = spell->prepare(std::move(targets));
    spell->update(1); // Update the spell right now. Prevents desynch => take twice the money if you click really fast.

    // Only charge player if cast of learning spell was successful.
    if (cast_result == SPELL_CAST_OK)
    {
        _player->ModifyMoney(-int32(nSpellCost));
        SendTrainingSuccess(guid, spellId);
    }
    else
        SendTrainingFailure(guid, spellId, TRAIN_FAIL_UNAVAILABLE);
}

        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported {}.", packet.GossipUnit.ToString());
void WorldSession::HandleGossipHelloOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: Received CMSG_GOSSIP_HELLO");

    ObjectGuid guid;
    recv_data >> guid;

    Creature* pCreature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_NONE);
    if (!pCreature)
    {
        DEBUG_LOG("WORLD: HandleGossipHelloOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    if (!pCreature->HasExtraFlag(CREATURE_FLAG_EXTRA_NO_MOVEMENT_PAUSE))
        pCreature->PauseOutOfCombatMovement();

    if (pCreature->IsSpiritGuide())
        pCreature->SendAreaSpiritHealerQueryOpcode(_player);

    if (!sScriptMgr.OnGossipHello(_player, pCreature))
    {
        _player->PrepareGossipMenu(pCreature, pCreature->GetDefaultGossipMenuId());
        _player->SendPreparedGossip(pCreature);
    }
}

void WorldSession::HandleGossipSelectOptionOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: CMSG_GOSSIP_SELECT_OPTION");

    uint32 gossipListId;
    ObjectGuid guid;
    std::string code;

    recv_data >> guid >> gossipListId;

    if (_player->PlayerTalkClass->GossipOptionCoded(gossipListId))
    {
        recv_data >> code;
        DEBUG_LOG("Gossip code: %s", code.c_str());
    }

    if (!packet.PromotionCode.empty())
    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    uint32 sender = _player->PlayerTalkClass->GossipOptionSender(gossipListId);
    uint32 action = _player->PlayerTalkClass->GossipOptionAction(gossipListId);

    if (guid.IsAnyTypeCreature())
    {
        Creature* pCreature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_NONE);

        if (!pCreature)
        {
            if (!unit->AI()->OnGossipSelectCode(_player, packet.GossipID, gossipMenuItem->OrderIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipOptionID, packet.GossipID);
            DEBUG_LOG("WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with it.", guid.GetString().c_str());
            return;
        }
        else if (go)
        {
            if (!go->AI()->OnGossipSelectCode(_player, packet.GossipID, gossipMenuItem->OrderIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipOptionID, packet.GossipID);
        }
        else if (item)
        {
            sScriptMgr->OnGossipSelectCode(_player, item, _player->PlayerTalkClass->GetGossipOptionSender(gossipMenuItem->OrderIndex), _player->PlayerTalkClass->GetGossipOptionAction(gossipMenuItem->OrderIndex), packet.PromotionCode.c_str());
        }
        else
        {
            sScriptMgr->OnGossipSelectCode(_player, packet.GossipID, _player->PlayerTalkClass->GetGossipOptionSender(gossipMenuItem->OrderIndex), _player->PlayerTalkClass->GetGossipOptionAction(gossipMenuItem->OrderIndex), packet.PromotionCode.c_str());
        }
    }
    else

        if (!pCreature->HasExtraFlag(CREATURE_FLAG_EXTRA_NO_MOVEMENT_PAUSE))
            pCreature->PauseOutOfCombatMovement();

        if (!sScriptMgr.OnGossipSelect(_player, pCreature, sender, action, code.empty() ? nullptr : code.c_str()))
            _player->OnGossipSelect(pCreature, gossipListId);
    }
    else if (guid.IsGameObject())
    {
        GameObject* pGo = GetPlayer()->GetGameObjectIfCanInteractWith(guid);

        if (!pGo)
        {
            if (!unit->AI()->OnGossipSelect(_player, packet.GossipID, gossipMenuItem->OrderIndex))
                _player->OnGossipSelect(unit, packet.GossipOptionID, packet.GossipID);
            DEBUG_LOG("WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with it.", guid.GetString().c_str());
            return;
        }
        else if (go)
        {
            if (!go->AI()->OnGossipSelect(_player, packet.GossipID, gossipMenuItem->OrderIndex))
                _player->OnGossipSelect(go, packet.GossipOptionID, packet.GossipID);
        }
        else if (item)
        {
            sScriptMgr->OnGossipSelect(_player, item, _player->PlayerTalkClass->GetGossipOptionSender(gossipMenuItem->OrderIndex), _player->PlayerTalkClass->GetGossipOptionAction(gossipMenuItem->OrderIndex));
        }
        else
        {
            sScriptMgr->OnGossipSelect(_player, packet.GossipID, _player->PlayerTalkClass->GetGossipOptionSender(gossipMenuItem->OrderIndex), _player->PlayerTalkClass->GetGossipOptionAction(gossipMenuItem->OrderIndex));
        }

        if (!sScriptMgr.OnGossipSelect(_player, pGo, sender, action, code.empty() ? nullptr : code.c_str()))
            _player->OnGossipSelect(pGo, gossipListId);
    }
}

void WorldSession::HandleSpiritHealerActivateOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: CMSG_SPIRIT_HEALER_ACTIVATE");

    ObjectGuid guid;

    recv_data >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_SPIRITHEALER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSpiritHealerActivateOpcode - {} not found or you can not interact with him.", packet.Healer.ToString());
        DEBUG_LOG("WORLD: HandleSpiritHealerActivateOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    SendSpiritResurrect();
}

void WorldSession::SendSpiritResurrect()
{
    _player->ResurrectPlayer(0.5f, true);

    _player->DurabilityLossAll(0.25f, true);

    // get corpse nearest graveyard
    WorldSafeLocsEntry const* corpseGrave = nullptr;
    Corpse* corpse = _player->GetCorpse();
    if (corpse)
        corpseGrave = sObjectMgr.GetClosestGraveYard(
                          corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetMapId(), _player->GetTeam());

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr.GetClosestGraveYard(
                _player->GetPositionX(), _player->GetPositionY(), _player->GetPositionZ(), _player->GetMapId(), _player->GetTeam());

        float orientation = _player->GetOrientation();

        // World of Warcraft Client Patch 1.8.0 (2005-10-11)
        // - All graveyards that needed adjustment were changed so that a 
        //   character's spirit comes into the world facing toward the Spirit Healer.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        if (float facing = sObjectMgr.GetWorldSafeLocFacing(corpseGrave->ID))
            orientation = facing;
#endif

        if (corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->map_id, corpseGrave->x, corpseGrave->y, corpseGrave->z, orientation);
        // or update at original position
        else
        {
            _player->GetCamera().UpdateVisibilityForOwner();
            _player->UpdateObjectVisibility();
        }
    }
    // or update at original position
    else
    {
        _player->GetCamera().UpdateVisibilityForOwner();
        _player->UpdateObjectVisibility();
    }
}

void WorldSession::HandleBinderActivateOpcode(WorldPacket& recv_data)
{
    ObjectGuid npcGuid;
    recv_data >> npcGuid;

    if (!GetPlayer()->IsInWorld() || !GetPlayer()->IsAlive())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(npcGuid, UNIT_NPC_FLAG_INNKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBinderActivateOpcode - {} not found or you can not interact with him.", packet.Unit.ToString());
        DEBUG_LOG("WORLD: HandleBinderActivateOpcode - %s not found or you can't interact with him.", npcGuid.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    SendBindPoint(unit);
}

void WorldSession::SendBindPoint(Creature* npc)
{
    // prevent set homebind to instances in any case
    if (GetPlayer()->GetMap()->Instanceable())
        return;

    // send spell for bind 3286 bind magic
    npc->CastSpell(_player, 3286, true);                    // Bind

    _player->PlayerTalkClass->CloseGossip();
}

void WorldSession::HandleListStabledPetsOpcode(WorldPacket& recv_data)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.StableMaster.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.StableMaster))
            creature->SendMirrorSound(_player, 0);
#endif
    if (!CheckStableMaster(packet.StableMaster))
        return;
    DEBUG_LOG("WORLD: Recv MSG_LIST_STABLED_PETS");
    ObjectGuid npcGUID;

    recv_data >> npcGUID;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        DEBUG_LOG("WORLD: HandleListStabledPetsOpcode - %s not found or you can't interact with him.", npcGUID.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    SendStablePet(npcGUID);
}

void WorldSession::SendStablePet(ObjectGuid guid)
{
    WorldPackets::Pet::PetStableList packet;
    DEBUG_LOG("WORLD: Recv MSG_LIST_STABLED_PETS Send.");

    WorldPacket data(MSG_LIST_STABLED_PETS, 200);           // guess size
    data << guid;

    Pet* pet = _player->GetPet();

    size_t wpos = data.wpos();
    data << uint8(0);                                       // place holder for slot show number

    data << uint8(GetPlayer()->m_stableSlots);

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendPacket(packet.Write());
        return;
    }
    uint8 num = 0;                                          // counter for place holder

    for (uint32 petSlot = 0; petSlot < petStable->ActivePets.size(); ++petSlot)
    // not let move dead pet in slot
    if (pet && pet->IsAlive() && pet->getPetType() == HUNTER_PET)
    {
        if (!petStable->ActivePets[petSlot])
            continue;

        PetStable::PetInfo const& pet = *petStable->ActivePets[petSlot];
        WorldPackets::Pet::PetStableInfo& stableEntry = packet.Pets.emplace_back();
        stableEntry.PetSlot = petSlot + PET_SAVE_FIRST_ACTIVE_SLOT;
        stableEntry.PetNumber = pet.PetNumber;
        stableEntry.CreatureID = pet.CreatureId;
        stableEntry.DisplayID = pet.DisplayId;
        stableEntry.ExperienceLevel = pet.Level;
        stableEntry.PetFlags = PET_STABLE_ACTIVE;
        stableEntry.PetName = pet.Name;
    }
        data << uint32(pet->GetCharmInfo()->GetPetNumber());
        data << uint32(pet->GetEntry());
        data << uint32(pet->GetLevel());
        data << pet->GetName();                             // petname
        data << uint32(pet->GetLoyaltyLevel());             // loyalty
        data << uint8(0x01);                                // client slot 1 == current pet (0)
        ++num;
    }
    // Pet may be despawned if owner went far away from pet for example.
    else if (CharacterPetCache const* currentPetData = sCharacterDatabaseCache.GetCharacterPetByOwner(_player->GetGUIDLow()))
    {
        data << uint32(currentPetData->id);
        data << uint32(currentPetData->entry);
        data << uint32(currentPetData->level);
        data << currentPetData->name;                           // petname
        data << uint32(currentPetData->loyalty);                // loyalty
        data << uint8(0x01);                                    // client slot 1 == current pet (0)
        ++num;
    }
    CharPetMap const& pets = sCharacterDatabaseCache.GetCharPetsMap();
    CharPetMap::const_iterator myPets = pets.find(GetPlayer()->GetGUIDLow());
    if (myPets != pets.end())
        for (const auto it : myPets->second)
            if (it->slot >= PET_SAVE_FIRST_STABLE_SLOT && it->slot <= PET_SAVE_LAST_STABLE_SLOT)
            {
                data << uint32(it->id);                 // pet number
                data << uint32(it->entry);              // creature entry
                data << uint32(it->level);              // level
                data << it->name;                       // name
                data << uint32(it->loyalty);            // loyalty
                data << uint8(it->slot + 1);            // slot
                ++num;
            }

    data.put<uint8>(wpos, num);                             // set real data to placeholder
    SendPacket(&data);
}

void WorldSession::SendStableResult(uint8 res)
{
    WorldPacket data(SMSG_STABLE_RESULT, 1);
    data << uint8(res);
    SendPacket(&data);
}

    for (uint32 petSlot = 0; petSlot < petStable->StabledPets.size(); ++petSlot)
    {
        if (!petStable->StabledPets[petSlot])
            continue;

        PetStable::PetInfo const& pet = *petStable->StabledPets[petSlot];
        WorldPackets::Pet::PetStableInfo& stableEntry = packet.Pets.emplace_back();
        stableEntry.PetSlot = petSlot + PET_SAVE_FIRST_STABLE_SLOT;
        stableEntry.PetNumber = pet.PetNumber;
        stableEntry.CreatureID = pet.CreatureId;
        stableEntry.DisplayID = pet.DisplayId;
        stableEntry.ExperienceLevel = pet.Level;
        stableEntry.PetFlags = PET_STABLE_INACTIVE;
        stableEntry.PetName = pet.Name;
    }

    SendPacket(packet.Write());
}
bool WorldSession::CheckStableMaster(ObjectGuid guid)
{
    // spell case or GM
    if (guid == GetPlayer()->GetObjectGuid())
    {
        // command case will return only if player have real access to command
        if (!ChatHandler(GetPlayer()).FindCommand("stable"))
        {
            DEBUG_LOG("%s attempt open stable in cheating way.", guid.GetString().c_str());
            return false;
        }
    }
    // stable master case
    else
    {
        if (!GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_STABLEMASTER))
        {
            DEBUG_LOG("Stablemaster %s not found or you can't interact with him.", guid.GetString().c_str());
            return false;
        }
    }

    return true;
}

void WorldSession::HandleSetPetSlot(WorldPackets::NPC::SetPetSlot& setPetSlot)
void WorldSession::HandleStablePet(WorldPacket& recv_data)
{
    if (!CheckStableMaster(setPetSlot.StableMaster) || setPetSlot.DestSlot >= PET_SAVE_LAST_STABLE_SLOT)
    DEBUG_LOG("WORLD: Recv CMSG_STABLE_PET");
    ObjectGuid npcGUID;

    recv_data >> npcGUID;

    if (!GetPlayer()->IsAlive())
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    GetPlayer()->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Interacting);

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    auto [srcPet, srcPetSlot] = Pet::GetLoadPetInfo(*petStable, 0, setPetSlot.PetNumber, {});
    PetSaveMode dstPetSlot = PetSaveMode(setPetSlot.DestSlot);
    PetStable::PetInfo const* dstPet = Pet::GetLoadPetInfo(*petStable, 0, 0, dstPetSlot).first;
    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    Pet* pet = _player->GetPet();

    if (!srcPet || srcPet->Type != HUNTER_PET)
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (dstPet && dstPet->Type != HUNTER_PET)
    {
        SendPetStableResult(StableResult::InternalError);
    uint32 free_slot = PET_SAVE_FIRST_STABLE_SLOT;

    // Find free slot for pet
    bool usedSlots[PET_SAVE_LAST_STABLE_SLOT - PET_SAVE_FIRST_STABLE_SLOT + 1] = {false};
    CharPetMap const& pets = sCharacterDatabaseCache.GetCharPetsMap();
    CharPetMap::const_iterator myPets = pets.find(GetPlayer()->GetGUIDLow());
    if (myPets != pets.end())
        for (const auto it : myPets->second)
            if (it->slot >= PET_SAVE_FIRST_STABLE_SLOT && it->slot <= PET_SAVE_LAST_STABLE_SLOT)
                usedSlots[it->slot - PET_SAVE_FIRST_STABLE_SLOT] = true;

    for (free_slot = PET_SAVE_FIRST_STABLE_SLOT; free_slot <= PET_SAVE_LAST_STABLE_SLOT && usedSlots[free_slot - PET_SAVE_FIRST_STABLE_SLOT]; ++free_slot);

    if (free_slot <= GetPlayer()->m_stableSlots)
    {
        pet->Unsummon(PetSaveMode(free_slot), _player);
        SendStableResult(STABLE_SUCCESS_STABLE);
    }
    else
        SendStableResult(STABLE_ERR_STABLE);
}

void WorldSession::HandleUnstablePet(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: Recv CMSG_UNSTABLE_PET.");
    ObjectGuid npcGUID;
    uint32 petNumber;

    recv_data >> npcGUID >> petNumber;

    if (!CheckStableMaster(npcGUID))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    Optional<PetStable::PetInfo>* src = nullptr;
    Optional<PetStable::PetInfo>* dst = nullptr;
    Optional<uint32> newActivePetIndex;

    if (IsActivePetSlot(srcPetSlot) && IsActivePetSlot(dstPetSlot))
    {
        // active<->active: only swap ActivePets and CurrentPetIndex (do not despawn pets)
        src = &petStable->ActivePets[srcPetSlot - PET_SAVE_FIRST_ACTIVE_SLOT];
        dst = &petStable->ActivePets[dstPetSlot - PET_SAVE_FIRST_ACTIVE_SLOT];
    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

        if (petStable->GetCurrentActivePetIndex() == uint32_t(srcPetSlot))
            newActivePetIndex = dstPetSlot;
        else if (petStable->GetCurrentActivePetIndex() == uint32(dstPetSlot))
            newActivePetIndex = srcPetSlot;
    }
    else if (IsStabledPetSlot(srcPetSlot) && IsStabledPetSlot(dstPetSlot))
    CharacterPetCache const* petData = sCharacterDatabaseCache.GetCharacterPetCacheByOwnerAndId(_player->GetGUIDLow(), petNumber);

    if (!petData || petData->slot < PET_SAVE_FIRST_STABLE_SLOT || petData->slot > PET_SAVE_LAST_STABLE_SLOT)
    {
        // stabled<->stabled: only swap StabledPets
        src = &petStable->StabledPets[srcPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
        dst = &petStable->StabledPets[dstPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }
    else if (IsActivePetSlot(srcPetSlot) && IsStabledPetSlot(dstPetSlot))

    uint32 creatureId = petData->entry;
    CreatureInfo const* creatureInfo = ObjectMgr::GetCreatureTemplate(creatureId);
    if (!creatureInfo || !creatureInfo->isTameable())
    {
        // active<->stabled: swap petStable contents and despawn active pet if it is involved in swap
        if (petStable->CurrentPetIndex == uint32(srcPetSlot))
        {
            Pet* oldPet = _player->GetPet();
            if (oldPet && !oldPet->IsAlive())
            {
                SendPetStableResult(StableResult::InternalError);
                return;
            }
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    // Player may have a pet, but unsummoned currently (too far away from owner ...). Do not erase this pet!
    Pet* pet = _player->GetPet();
    if (pet || sCharacterDatabaseCache.GetCharacterPetByOwner(_player->GetGUIDLow()))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    Pet* newpet = new Pet(HUNTER_PET);
    if (!newpet->LoadPetFromDB(_player, creatureId, petNumber))
    {
        delete newpet;
        newpet = nullptr;
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

            _player->RemovePet(oldPet, PET_SAVE_NOT_IN_SLOT);
        }
    SendStableResult(STABLE_SUCCESS_UNSTABLE);
}

        if (dstPet)
        {
            CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(dstPet->CreatureId);
            if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
            {
                SendPetStableResult(StableResult::CantControlExotic);
                return;
            }
        }
void WorldSession::HandleBuyStableSlot(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: Recv CMSG_BUY_STABLE_SLOT.");
    ObjectGuid npcGUID;

    recv_data >> npcGUID;

    if (!CheckStableMaster(npcGUID))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    if (GetPlayer()->m_stableSlots < MAX_PET_STABLES)
    {
        StableSlotPricesEntry const* SlotPrice = sStableSlotPricesStore.LookupEntry(GetPlayer()->m_stableSlots + 1);
        if (_player->GetMoney() >= SlotPrice->Price)
        {
            ++GetPlayer()->m_stableSlots;
            _player->ModifyMoney(-int32(SlotPrice->Price));
            SendStableResult(STABLE_SUCCESS_BUY_SLOT);
        }
        else
            SendStableResult(STABLE_ERR_MONEY);
    }
    else
        SendStableResult(STABLE_ERR_STABLE);
}

        src = &petStable->ActivePets[srcPetSlot - PET_SAVE_FIRST_ACTIVE_SLOT];
        dst = &petStable->StabledPets[dstPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
    }
    else if (IsStabledPetSlot(srcPetSlot) && IsActivePetSlot(dstPetSlot))
    {
        // stabled<->active: swap petStable contents and despawn active pet if it is involved in swap
        if (petStable->CurrentPetIndex == uint32(dstPetSlot))
        {
            Pet* oldPet = _player->GetPet();
            if (oldPet && !oldPet->IsAlive())
            {
                SendPetStableResult(StableResult::InternalError);
                return;
            }

            _player->RemovePet(oldPet, PET_SAVE_NOT_IN_SLOT);
        }

        CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(srcPet->CreatureId);
        if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
        {
            SendPetStableResult(StableResult::CantControlExotic);
            return;
        }

        src = &petStable->StabledPets[srcPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
        dst = &petStable->ActivePets[dstPetSlot - PET_SAVE_FIRST_ACTIVE_SLOT];
void WorldSession::HandleStableRevivePet(WorldPacket& /* recv_data */)
{
    DEBUG_LOG("HandleStableRevivePet: Not implemented");
}

void WorldSession::HandleStableSwapPet(WorldPacket& recv_data)
{
    DEBUG_LOG("WORLD: Recv CMSG_STABLE_SWAP_PET.");
    ObjectGuid npcGUID;
    uint32 pet_number;

    recv_data >> npcGUID >> pet_number;

    if (!CheckStableMaster(npcGUID))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    Pet* pet = _player->GetPet();

    if (!pet || !pet->IsAlive() || pet->getPetType() != HUNTER_PET)
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
    stmt->setInt16(0, dstPetSlot);
    stmt->setUInt64(1, _player->GetGUID().GetCounter());
    stmt->setUInt32(2, srcPet->PetNumber);
    trans->Append(stmt);

    if (dstPet)
    // find swapped pet slot in stable
    CharacterPetCache const* swappedPet = sCharacterDatabaseCache.GetCharacterPetCacheByOwnerAndId(_player->GetGUIDLow(), pet_number);
    if (!swappedPet)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setInt16(0, srcPetSlot);
        stmt->setUInt64(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, dstPet->PetNumber);
        trans->Append(stmt);
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete(
        [this, currentPlayerGuid = _player->GetGUID(), src, dst, newActivePetIndex](bool success)
    {
        if (_player && _player->GetGUID() == currentPlayerGuid)
        {
            if (success)
            {
                std::swap(*src, *dst);
                if (newActivePetIndex)
                    GetPlayer()->GetPetStable()->SetCurrentActivePetIndex(*newActivePetIndex);
    uint32 slot        = swappedPet->slot;
    uint32 creature_id = swappedPet->entry;

                SendPetStableResult(StableResult::StableSuccess);
            }
            else
            {
                SendPetStableResult(StableResult::InternalError);
            }
        }
    });
    if (!creature_id)
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    CreatureInfo const* creatureInfo = ObjectMgr::GetCreatureTemplate(creature_id);
    if (!creatureInfo || !creatureInfo->isTameable())
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    pet->Unsummon(PetSaveMode(slot), _player);

    // summon unstabled pet
    Pet* newpet = new Pet;
    if (!newpet->LoadPetFromDB(_player, creature_id, pet_number))
    {
        delete newpet;
        SendStableResult(STABLE_ERR_STABLE);
    }
    else
        SendStableResult(STABLE_SUCCESS_UNSTABLE);
}

void WorldSession::HandleRepairItemOpcode(WorldPacket& recv_data)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_REPAIR_ITEM: Npc {}, Item {}, UseGuildBank: {}",
        packet.NpcGUID.ToString(), packet.ItemGUID.ToString(), packet.UseGuildBank);
    DEBUG_LOG("WORLD: CMSG_REPAIR_ITEM");

    ObjectGuid npcGuid;
    ObjectGuid itemGuid;

    recv_data >> npcGuid >> itemGuid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(npcGuid, UNIT_NPC_FLAG_REPAIR);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleRepairItemOpcode - {} not found or you can not interact with him.", packet.NpcGUID.ToString());
        DEBUG_LOG("WORLD: HandleRepairItemOpcode - %s not found or you can't interact with him.", npcGuid.GetString().c_str());
        return;
    }

    GetPlayer()->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_INTERACTING_CANCELS);
    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);

    // reputation discount
    float discountMod = _player->GetReputationPriceDiscount(unit);

    uint32 TotalCost = 0;
    if (itemGuid)
    {
        TC_LOG_DEBUG("network", "ITEM: Repair {}, at {}", packet.ItemGUID.ToString(), packet.NpcGUID.ToString());
        DEBUG_LOG("ITEM: %s repair of %s", npcGuid.GetString().c_str(), itemGuid.GetString().c_str());

        Item* item = _player->GetItemByGuid(itemGuid);

        if (item)
            _player->DurabilityRepair(item->GetPos(), true, discountMod);
            TotalCost = _player->DurabilityRepair(item->GetPos(), true, discountMod);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at {}", packet.NpcGUID.ToString());
        _player->DurabilityRepairAll(true, discountMod, packet.UseGuildBank);
        DEBUG_LOG("ITEM: %s repair all items", npcGuid.GetString().c_str());

        TotalCost = _player->DurabilityRepairAll(true, discountMod);
    }
}
