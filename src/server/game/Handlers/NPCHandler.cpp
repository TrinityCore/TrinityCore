/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Language.h"
#include "Log.h"
#include "MailPackets.h"
#include "Map.h"
#include "NPCPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "PetPackets.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Trainer.h"
#include "WorldPacket.h"

void WorldSession::HandleTabardVendorActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TABARDDESIGNER);
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
    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_TRAINER);
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

    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.TrainerGUID, UNIT_NPC_FLAG_TRAINER);
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
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_GOSSIP);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipHelloOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    // set faction visible if needed
    if (FactionTemplateEntry const* factionTemplateEntry = sFactionTemplateStore.LookupEntry(unit->getFaction()))
        _player->GetReputationMgr().SetVisible(factionTemplateEntry);

    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    // remove fake death
    //if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
    //    GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (unit->IsArmorer() || unit->IsCivilian() || unit->IsQuestGiver() || unit->IsServiceProvider() || unit->IsGuard())
        unit->StopMoving();

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

    if (!sScriptMgr->OnGossipHello(_player, unit))
    {
//        _player->TalkedToCreature(unit->GetEntry(), unit->GetGUID());
        _player->PrepareGossipMenu(unit, unit->GetCreatureTemplate()->GossipMenuId, true);
        _player->SendPreparedGossip(unit);
    }
    unit->AI()->sGossipHello(_player);
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
        unit = GetPlayer()->GetNPCIfCanInteractWith(packet.GossipUnit, UNIT_NPC_FLAG_GOSSIP);
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
            unit->AI()->sGossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str());
            if (!sScriptMgr->OnGossipSelectCode(_player, unit, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex), packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            go->AI()->GossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str());
            if (!sScriptMgr->OnGossipSelectCode(_player, go, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex), packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
    else
    {
        if (unit)
        {
            unit->AI()->sGossipSelect(_player, packet.GossipID, packet.GossipIndex);
            if (!sScriptMgr->OnGossipSelect(_player, unit, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex)))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            go->AI()->GossipSelect(_player, packet.GossipID, packet.GossipIndex);
            if (!sScriptMgr->OnGossipSelect(_player, go, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex)))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
}

void WorldSession::HandleSpiritHealerActivate(WorldPackets::NPC::SpiritHealerActivate& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Healer, UNIT_NPC_FLAG_SPIRITHEALER);
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
    WorldSafeLocsEntry const* corpseGrave = NULL;
    WorldLocation corpseLocation = _player->GetCorpseLocation();
    if (_player->HasCorpse())
    {
        corpseGrave = sObjectMgr->GetClosestGraveYard(corpseLocation.GetPositionX(), corpseLocation.GetPositionY(),
            corpseLocation.GetPositionZ(), corpseLocation.GetMapId(), _player->GetTeam());
    }

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr->GetClosestGraveYard(
            _player->GetPositionX(), _player->GetPositionY(), _player->GetPositionZ(), _player->GetMapId(), _player->GetTeam());

        if (corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->MapID, corpseGrave->Loc.X, corpseGrave->Loc.Y, corpseGrave->Loc.Z, (corpseGrave->Facing * M_PI) / 180); // Orientation is initially in degrees
        // or update at original position
        else
            _player->UpdateObjectVisibility();
    }
    // or update at original position
    else
        _player->UpdateObjectVisibility();
}

void WorldSession::HandleBinderActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    if (!GetPlayer()->IsInWorld() || !GetPlayer()->IsAlive())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_INNKEEPER);
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
    if (!GetPlayer())
        return;

    WorldPackets::Pet::PetStableList packet;

    packet.StableMaster = guid;

    for (PlayerPetData* p : _player->PlayerPetDataStore)
    {

        WorldPackets::Pet::PetStableInfo stableEntry;

        uint32 petSlot = p->Slot;

        stableEntry.PetSlot         = petSlot;
        stableEntry.PetNumber       = p->PetId;             // petnumber
        stableEntry.CreatureID      = p->CreatureId;             // creature entry
        stableEntry.DisplayID       = p->DisplayId;             // creature displayid
        stableEntry.ExperienceLevel = p->Petlevel;             // level
        stableEntry.PetFlags        = petSlot <= PET_SLOT_LAST_ACTIVE_SLOT ? PET_STABLE_ACTIVE : PET_STABLE_INACTIVE;
        stableEntry.PetName         = p->Name;             // Name

        packet.Pets.push_back(stableEntry);
    }

    SendPacket(packet.Write());
}

void WorldSession::SendPetStableResult(uint8 result)
{
    WorldPacket data(SMSG_PET_STABLE_RESULT, 1);
    data << uint8(result);
    SendPacket(&data);
}

void WorldSession::HandleSetPetSlot(WorldPackets::NPC::SetPetSlot& packet)
{
    if (!GetPlayer()->IsAlive())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!CheckStableMaster(packet.StableMaster))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (packet.DestSlot > PET_SLOT_LAST_STABLE_SLOT || packet.DestSlot < PET_SLOT_FIRST_ACTIVE_SLOT)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // remove fake death 2
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet* pet = _player->GetPet();

    // can't place in stable dead pet
    if (pet)
    {
        if (pet->GetCharmInfo()->GetPetNumber() == packet.PetNumber)
        {
            if (!pet->IsAlive() || pet->getPetType() != HUNTER_PET)
            {
                SendPetStableResult(STABLE_ERR_STABLE);
                return;
            }
        }
    }

    PlayerPetData* playerPetData = _player->GetPlayerPetDataById(packet.PetNumber);

    if (playerPetData)
    {
        UpdatePetSlot(packet.PetNumber, playerPetData->Slot, packet.DestSlot);
    }
}

void WorldSession::HandleStableRevivePet(WorldPacket &/* recvData */)
{
    TC_LOG_DEBUG("network", "HandleStableRevivePet: Not implemented");
}

void WorldSession::HandleStableSwapPet(WorldPacket& recvData)
{
    ObjectGuid npcGUID;
    uint32 petId;

    recvData >> npcGUID >> petId;

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet* pet = _player->GetPet();

    if (!pet || pet->getPetType() != HUNTER_PET)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // Find swapped pet slot in stable

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOT_BY_ID);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt32(1, petId);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleStableSwapPetCallback, this, petId, std::placeholders::_1)));
}

void WorldSession::HandleStableSwapPetCallback(uint32 petId, PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    if (!result)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    Field* fields = result->Fetch();

    uint32 slot     = fields[0].GetUInt8();
    uint32 petEntry = fields[1].GetUInt32();

    if (!petEntry)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petEntry);
    if (!creatureInfo || !creatureInfo->IsTameable(true))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        SendPetStableResult(STABLE_ERR_EXOTIC);
        return;
    }

    Pet* pet = _player->GetPet();
    // The player's pet could have been removed during the delay of the DB callback
    if (!pet)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // move alive pet to slot or delete dead pet
    _player->RemovePet(pet, pet->IsAlive() ? PetSaveMode(slot) : PET_SAVE_AS_DELETED);

    // summon unstabled pet
    Pet* newPet = new Pet(_player);
    if (!newPet->LoadPetData(_player, petEntry, petId))
    {
        delete newPet;
        SendPetStableResult(STABLE_ERR_STABLE);
    }
    else
        SendPetStableResult(STABLE_SUCCESS_UNSTABLE);
}

void WorldSession::HandleRepairItemOpcode(WorldPackets::Item::RepairItem& packet)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_REPAIR_ITEM: Npc %s, Item %s, UseGuildBank: %u",
        packet.NpcGUID.ToString().c_str(), packet.ItemGUID.ToString().c_str(), packet.UseGuildBank);

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.NpcGUID, UNIT_NPC_FLAG_REPAIR);
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
            _player->DurabilityRepair(item->GetPos(), true, discountMod, packet.UseGuildBank);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at %s", packet.NpcGUID.ToString().c_str());
        _player->DurabilityRepairAll(true, discountMod, packet.UseGuildBank);
    }
}

