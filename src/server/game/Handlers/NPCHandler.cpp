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
#include "BattlegroundMgr.h"
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
#include "MailPackets.h"
#include "Map.h"
#include "NPCPackets.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "SpellInfo.h"
#include "Trainer.h"
#include "World.h"
#include "WorldPacket.h"

enum class StableResult : uint8
{
    NotEnoughMoney        = 1,                              // "you don't have enough money"
    InvalidSlot           = 3,                              // "That slot is locked"
    StableSuccess         = 8,                              // stable success
    UnstableSuccess       = 9,                              // unstable/swap success
    BuySlotSuccess        = 10,                             // buy slot success
    CantControlExotic     = 11,                             // "you are unable to control exotic creatures"
    InternalError         = 12,                             // "Internal pet error"
};

void WorldSession::HandleTabardVendorActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TABARDDESIGNER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTabardVendorActivateOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendTabardVendorActivate(packet.Unit);
}

void WorldSession::SendTabardVendorActivate(ObjectGuid guid)
{
    WorldPackets::NPC::PlayerTabardVendorActivate packet;
    packet.Vendor = guid;
    SendPacket(packet.Write());
}

void WorldSession::SendShowMailBox(ObjectGuid guid)
{
    WorldPackets::Mail::ShowMailbox packet;
    packet.PostmasterGUID = guid;
    SendPacket(packet.Write());
}

void WorldSession::HandleTrainerListOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    if (uint32 trainerId = sObjectMgr->GetCreatureDefaultTrainer(npc->GetEntry()))
        SendTrainerList(npc, trainerId);
    else
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - Creature id %u has no trainer data.", npc->GetEntry());
}

void WorldSession::SendTrainerList(Creature* npc, uint32 trainerId)
{
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(trainerId);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - trainer spells not found for trainer %s id %d", npc->GetGUID().ToString().c_str(), trainerId);
        return;
    }

    _player->PlayerTalkClass->GetInteractionData().Reset();
    _player->PlayerTalkClass->GetInteractionData().SourceGuid = npc->GetGUID();
    _player->PlayerTalkClass->GetInteractionData().TrainerId = trainerId;
    trainer->SendSpells(npc, _player, GetSessionDbLocaleIndex());
}

void WorldSession::HandleTrainerBuySpellOpcode(WorldPackets::NPC::TrainerBuySpell& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL %s, learn spell id is: %i", packet.TrainerGUID.ToString().c_str(), packet.SpellID);

    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.TrainerGUID, UNIT_NPC_FLAG_TRAINER, UNIT_NPC_FLAG_2_NONE);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - %s not found or you can not interact with him.", packet.TrainerGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (_player->PlayerTalkClass->GetInteractionData().SourceGuid != packet.TrainerGUID)
        return;

    if (_player->PlayerTalkClass->GetInteractionData().TrainerId != uint32(packet.TrainerID))
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
        TC_LOG_DEBUG("network", "WORLD: HandleGossipHelloOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
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

    // If spiritguide, no need for gossip menu, just put player into resurrect queue
    if (unit->IsSpiritGuide())
    {
        Battleground* bg = _player->GetBattleground();
        if (bg)
        {
            bg->AddPlayerToResurrectQueue(unit->GetGUID(), _player->GetGUID());
            sBattlegroundMgr->SendAreaSpiritHealerQueryOpcode(_player, bg, unit->GetGUID());
            return;
        }
    }

    _player->PlayerTalkClass->ClearMenus();
    if (!unit->AI()->OnGossipHello(_player))
    {
//        _player->TalkedToCreature(unit->GetEntry(), unit->GetGUID());
        _player->PrepareGossipMenu(unit, unit->GetCreatureTemplate()->GossipMenuId, true);
        _player->SendPreparedGossip(unit);
    }
}

void WorldSession::HandleGossipSelectOptionOpcode(WorldPackets::NPC::GossipSelectOption& packet)
{
    if (!_player->PlayerTalkClass->GetGossipMenu().GetItem(packet.GossipIndex))
        return;

    // Prevent cheating on C++ scripted menus
    if (_player->PlayerTalkClass->GetInteractionData().SourceGuid != packet.GossipUnit)
        return;

    Creature* unit = nullptr;
    GameObject* go = nullptr;
    if (packet.GossipUnit.IsCreatureOrVehicle())
    {
        unit = GetPlayer()->GetNPCIfCanInteractWith(packet.GossipUnit, UNIT_NPC_FLAG_GOSSIP, UNIT_NPC_FLAG_2_NONE);
        if (!unit)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with him.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }
    else if (packet.GossipUnit.IsGameObject())
    {
        go = _player->GetGameObjectIfCanInteractWith(packet.GossipUnit);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with it.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }
    else
    {

        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported %s.", packet.GossipUnit.ToString().c_str());
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
            if (!unit->AI()->OnGossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            if (!go->AI()->OnGossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
    else
    {
        if (unit)
        {
            if (!unit->AI()->OnGossipSelect(_player, packet.GossipID, packet.GossipIndex))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            if (!go->AI()->OnGossipSelect(_player, packet.GossipID, packet.GossipIndex))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
}

void WorldSession::HandleSpiritHealerActivate(WorldPackets::NPC::SpiritHealerActivate& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Healer, UNIT_NPC_FLAG_SPIRITHEALER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSpiritHealerActivateOpcode - %s not found or you can not interact with him.", packet.Healer.ToString().c_str());
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
        TC_LOG_DEBUG("network", "WORLD: HandleBinderActivateOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
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

    SendStablePet(packet.StableMaster);
}

void WorldSession::SendStablePet(ObjectGuid guid)
{
    WorldPackets::Pet::PetStableList packet;

    packet.StableMaster = guid;

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendPacket(packet.Write());
        return;
    }

    for (uint32 petSlot = 0; petSlot < petStable->ActivePets.size(); ++petSlot)
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

void WorldSession::SendPetStableResult(StableResult result)
{
    WorldPackets::Pet::PetStableResult petStableResult;
    petStableResult.Result = AsUnderlyingType(result);
    SendPacket(petStableResult.Write());
}

void WorldSession::HandleSetPetSlot(WorldPackets::NPC::SetPetSlot& setPetSlot)
{
    if (!CheckStableMaster(setPetSlot.StableMaster) || setPetSlot.DestSlot >= PET_SAVE_LAST_STABLE_SLOT)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    GetPlayer()->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Interacting);

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    auto [srcPet, srcPetSlot] = Pet::GetLoadPetInfo(*petStable, 0, setPetSlot.PetNumber, {});
    PetSaveMode dstPetSlot = PetSaveMode(setPetSlot.DestSlot);
    PetStable::PetInfo const* dstPet = Pet::GetLoadPetInfo(*petStable, 0, 0, dstPetSlot).first;

    if (!srcPet || srcPet->Type != HUNTER_PET)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    if (dstPet && dstPet->Type != HUNTER_PET)
    {
        SendPetStableResult(StableResult::InternalError);
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

        if (petStable->GetCurrentActivePetIndex() == uint32_t(srcPetSlot))
            newActivePetIndex = dstPetSlot;
        else if (petStable->GetCurrentActivePetIndex() == uint32(dstPetSlot))
            newActivePetIndex = srcPetSlot;
    }
    else if (IsStabledPetSlot(srcPetSlot) && IsStabledPetSlot(dstPetSlot))
    {
        // stabled<->stabled: only swap StabledPets
        src = &petStable->StabledPets[srcPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
        dst = &petStable->StabledPets[dstPetSlot - PET_SAVE_FIRST_STABLE_SLOT];
    }
    else if (IsActivePetSlot(srcPetSlot) && IsStabledPetSlot(dstPetSlot))
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

            _player->RemovePet(oldPet, PET_SAVE_NOT_IN_SLOT);
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
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
    stmt->setInt16(0, dstPetSlot);
    stmt->setUInt64(1, _player->GetGUID().GetCounter());
    stmt->setUInt32(2, srcPet->PetNumber);
    trans->Append(stmt);

    if (dstPet)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setInt16(0, srcPetSlot);
        stmt->setUInt64(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, dstPet->PetNumber);
        trans->Append(stmt);
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

                SendPetStableResult(StableResult::StableSuccess);
            }
            else
            {
                SendPetStableResult(StableResult::InternalError);
            }
        }
    });
}

void WorldSession::HandleRepairItemOpcode(WorldPackets::Item::RepairItem& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_REPAIR_ITEM: Npc %s, Item %s, UseGuildBank: %u",
        packet.NpcGUID.ToString().c_str(), packet.ItemGUID.ToString().c_str(), packet.UseGuildBank);

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.NpcGUID, UNIT_NPC_FLAG_REPAIR, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleRepairItemOpcode - %s not found or you can not interact with him.", packet.NpcGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // reputation discount
    float discountMod = _player->GetReputationPriceDiscount(unit);

    if (!packet.ItemGUID.IsEmpty())
    {
        TC_LOG_DEBUG("network", "ITEM: Repair %s, at %s", packet.ItemGUID.ToString().c_str(), packet.NpcGUID.ToString().c_str());

        Item* item = _player->GetItemByGuid(packet.ItemGUID);
        if (item)
            _player->DurabilityRepair(item->GetPos(), true, discountMod);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at %s", packet.NpcGUID.ToString().c_str());
        _player->DurabilityRepairAll(true, discountMod, packet.UseGuildBank);
    }
}
