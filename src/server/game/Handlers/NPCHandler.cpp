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
    unit->PauseMovement(sWorld->getIntConfig(CONFIG_CREATURE_STOP_FOR_PLAYER));
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
    if (!unit->AI()->GossipHello(_player))
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
            if (!unit->AI()->GossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            if (!go->AI()->GossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
    else
    {
        if (unit)
        {
            if (!unit->AI()->GossipSelect(_player, packet.GossipID, packet.GossipIndex))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            if (!go->AI()->GossipSelect(_player, packet.GossipID, packet.GossipIndex))
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
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOTS_DETAIL);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt8(1, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(2, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::SendStablePetCallback, this, guid, std::placeholders::_1)));
}

void WorldSession::SendStablePetCallback(ObjectGuid guid, PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    WorldPackets::Pet::PetStableList packet;

    packet.StableMaster = guid;

    Pet* pet = _player->GetPet();

    int32 petSlot = 0;
    // not let move dead pet in slot
    if (pet && pet->IsAlive() && pet->getPetType() == HUNTER_PET)
    {
        WorldPackets::Pet::PetStableInfo stableEntry;
        stableEntry.PetSlot = petSlot;
        stableEntry.PetNumber = pet->GetCharmInfo()->GetPetNumber();
        stableEntry.CreatureID = pet->GetEntry();
        stableEntry.DisplayID = pet->GetDisplayId();
        stableEntry.ExperienceLevel = pet->GetLevel();
        stableEntry.PetFlags = PET_STABLE_ACTIVE;
        stableEntry.PetName = pet->GetName();
        ++petSlot;

        packet.Pets.push_back(stableEntry);
    }

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            WorldPackets::Pet::PetStableInfo stableEntry;

            stableEntry.PetSlot = petSlot;
            stableEntry.PetNumber = fields[1].GetUInt32();          // petnumber
            stableEntry.CreatureID = fields[2].GetUInt32();         // creature entry
            stableEntry.DisplayID = fields[5].GetUInt32();          // creature displayid
            stableEntry.ExperienceLevel = fields[3].GetUInt16();    // level
            stableEntry.PetFlags = PET_STABLE_INACTIVE;
            stableEntry.PetName = fields[4].GetString();            // Name

            ++petSlot;
            packet.Pets.push_back(stableEntry);
        }
        while (result->NextRow());
    }

    SendPacket(packet.Write());
}

void WorldSession::SendPetStableResult(StableResult result)
{
    WorldPackets::Pet::PetStableResult petStableResult;
    petStableResult.Result = AsUnderlyingType(result);
    SendPacket(petStableResult.Write());
}

void WorldSession::HandleStablePet(WorldPacket& recvData)
{
    ObjectGuid npcGUID;

    recvData >> npcGUID;

    if (!GetPlayer()->IsAlive())
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet* pet = _player->GetPet();

    // can't place in stable dead pet
    if (!pet || !pet->IsAlive() || pet->getPetType() != HUNTER_PET)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOTS);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt8(1, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(2, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleStablePetCallback, this, std::placeholders::_1)));
}

void WorldSession::HandleStablePetCallback(PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    uint8 freeSlot = 1;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint8 slot = fields[1].GetUInt8();

            // slots ordered in query, and if not equal then free
            if (slot != freeSlot)
                break;

            // this slot not free, skip
            ++freeSlot;
        }
        while (result->NextRow());
    }

    if (freeSlot > 0 && freeSlot <= GetPlayer()->m_stableSlots)
    {
        _player->RemovePet(_player->GetPet(), PetSaveMode(freeSlot));
        SendPetStableResult(StableResult::StableSuccess);
    }
    else
        SendPetStableResult(StableResult::InvalidSlot);
}

void WorldSession::HandleUnstablePet(WorldPacket& recvData)
{
    ObjectGuid npcGUID;
    uint32 petnumber;

    recvData >> npcGUID >> petnumber;

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_ENTRY);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt32(1, petnumber);
    stmt->setUInt8(2, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(3, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleUnstablePetCallback, this, petnumber, std::placeholders::_1)));
}

void WorldSession::HandleUnstablePetCallback(uint32 petId, PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    uint32 petEntry = 0;
    if (result)
    {
        Field* fields = result->Fetch();
        petEntry = fields[0].GetUInt32();
    }

    if (!petEntry)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petEntry);
    if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        // if problem in exotic pet
        if (creatureInfo && creatureInfo->IsTameable(true))
            SendPetStableResult(StableResult::CantControlExotic);
        else
            SendPetStableResult(StableResult::InternalError);
        return;
    }

    Pet* pet = _player->GetPet();
    if (pet && pet->IsAlive())
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // delete dead pet
    if (pet)
        _player->RemovePet(pet, PET_SAVE_AS_DELETED);

    Pet* newPet = new Pet(_player, HUNTER_PET);
    if (!newPet->LoadPetFromDB(_player, petEntry, petId))
    {
        delete newPet;
        newPet = nullptr;
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    SendPetStableResult(StableResult::UnstableSuccess);
}

void WorldSession::HandleBuyStableSlot(WorldPacket& recvData)
{
    ObjectGuid npcGUID;

    recvData >> npcGUID;

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if (GetPlayer()->m_stableSlots < MAX_PET_STABLES)
    {
        /*StableSlotPricesEntry const* SlotPrice = sStableSlotPricesStore.LookupEntry(GetPlayer()->m_stableSlots+1);
        if (_player->HasEnoughMoney(SlotPrice->Cost))
        {
            ++GetPlayer()->m_stableSlots;
            _player->ModifyMoney(-int32(SlotPrice->Cost));
            SendPetStableResult(StableResult::BuySlotSuccess);
        }
        else
            SendPetStableResult(StableResult::NotEnoughMoney);*/
    }
    else
        SendPetStableResult(StableResult::InternalError);
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
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet* pet = _player->GetPet();

    if (!pet || pet->getPetType() != HUNTER_PET)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // Find swapped pet slot in stable

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOT_BY_ID);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt32(1, petId);

    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleStableSwapPetCallback, this, petId, std::placeholders::_1)));
}

void WorldSession::HandleStableSwapPetCallback(uint32 petId, PreparedQueryResult result)
{
    if (!GetPlayer())
        return;

    if (!result)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    Field* fields = result->Fetch();

    uint32 slot     = fields[0].GetUInt8();
    uint32 petEntry = fields[1].GetUInt32();

    if (!petEntry)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petEntry);
    if (!creatureInfo || !creatureInfo->IsTameable(true))
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    if (!creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        SendPetStableResult(StableResult::CantControlExotic);
        return;
    }

    Pet* pet = _player->GetPet();
    // The player's pet could have been removed during the delay of the DB callback
    if (!pet)
    {
        SendPetStableResult(StableResult::InternalError);
        return;
    }

    // move alive pet to slot or delete dead pet
    _player->RemovePet(pet, pet->IsAlive() ? PetSaveMode(slot) : PET_SAVE_AS_DELETED);

    // summon unstabled pet
    Pet* newPet = new Pet(_player);
    if (!newPet->LoadPetFromDB(_player, petEntry, petId))
    {
        delete newPet;
        SendPetStableResult(StableResult::InternalError);
    }
    else
        SendPetStableResult(StableResult::UnstableSuccess);
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
            _player->DurabilityRepair(item->GetPos(), true, discountMod, packet.UseGuildBank);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at %s", packet.NpcGUID.ToString().c_str());
        _player->DurabilityRepairAll(true, discountMod, packet.UseGuildBank);
    }
}
