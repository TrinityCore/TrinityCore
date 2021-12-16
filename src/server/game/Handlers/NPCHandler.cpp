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
#include "DBCStores.h"
#include "GossipDef.h"
#include "Item.h"
#include "Log.h"
#include "MailPackets.h"
#include "Map.h"
#include "NPCPackets.h"
#include "Opcodes.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "QueryCallback.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Trainer.h"
#include "World.h"
#include "WorldPacket.h"

enum StableResultCode
{
    STABLE_ERR_MONEY        = 0x01,                         // "you don't have enough money"
    STABLE_ERR_STABLE       = 0x06,                         // currently used in most fail cases
    STABLE_SUCCESS_STABLE   = 0x08,                         // stable success
    STABLE_SUCCESS_UNSTABLE = 0x09,                         // unstable/swap success
    STABLE_SUCCESS_BUY_SLOT = 0x0A,                         // buy slot success
    STABLE_ERR_EXOTIC       = 0x0C                          // "you are unable to control exotic creatures"
};

void WorldSession::HandleTabardVendorActivateOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TABARDDESIGNER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTabardVendorActivateOpcode - %s not found or you can not interact with him.", guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendTabardVendorActivate(guid);
}

void WorldSession::SendTabardVendorActivate(ObjectGuid guid)
{
    WorldPacket data(MSG_TABARDVENDOR_ACTIVATE, 8);
    data << guid;
    SendPacket(&data);
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
        TC_LOG_DEBUG("network", "WorldSession: SendTrainerList - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    SendTrainerList(npc);
}

void WorldSession::SendTrainerList(Creature* npc)
{
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(npc->GetEntry());
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WorldSession: SendTrainerList - trainer spells not found for %s", npc->GetGUID().ToString().c_str());
        return;
    }

    if (!trainer->IsTrainerValidForPlayer(_player))
    {
        TC_LOG_DEBUG("network", "WorldSession: SendTrainerList - trainer %s not valid for player %s", npc->GetGUID().ToString().c_str(), GetPlayerInfo().c_str());
        return;
    }

    trainer->SendSpells(npc, _player, GetSessionDbLocaleIndex());
}

void WorldSession::HandleTrainerBuySpellOpcode(WorldPackets::NPC::TrainerBuySpell& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL %s, learn spell id is: %u", packet.TrainerGUID.ToString().c_str(), packet.SpellID);

    Creature* npc = GetPlayer()->GetNPCIfCanInteractWith(packet.TrainerGUID, UNIT_NPC_FLAG_TRAINER);
    if (!npc)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - %s not found or you can not interact with him.", packet.TrainerGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(npc->GetEntry());
    if (!trainer)
        return;

    trainer->TeachSpell(npc, _player, packet.SpellID);
}

void WorldSession::HandleGossipHelloOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_GOSSIP_HELLO");

    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_GOSSIP);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipHelloOpcode - %s not found or you can not interact with him.", guid.ToString().c_str());
        return;
    }

    // set faction visible if needed
    if (FactionTemplateEntry const* factionTemplateEntry = sFactionTemplateStore.LookupEntry(unit->GetFaction()))
        _player->GetReputationMgr().SetVisible(factionTemplateEntry);

    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    // remove fake death
    //if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
    //    GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

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

void WorldSession::HandleSpiritHealerActivateOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SPIRIT_HEALER_ACTIVATE");

    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_SPIRITHEALER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleSpiritHealerActivateOpcode - %s not found or you can not interact with him.", guid.ToString().c_str());
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
        corpseGrave = sObjectMgr->GetClosestGraveyard(corpseLocation.GetPositionX(), corpseLocation.GetPositionY(),
            corpseLocation.GetPositionZ(), corpseLocation.GetMapId(), _player->GetTeam());
    }

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr->GetClosestGraveyard(
            _player->GetPositionX(), _player->GetPositionY(), _player->GetPositionZ(), _player->GetMapId(), _player->GetTeam());

        if (corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->Continent, corpseGrave->Loc.X, corpseGrave->Loc.Y, corpseGrave->Loc.Z, _player->GetOrientation());
    }
}

void WorldSession::HandleBinderActivateOpcode(WorldPacket& recvData)
{
    ObjectGuid npcGUID;
    recvData >> npcGUID;

    if (!GetPlayer()->IsInWorld() || !GetPlayer()->IsAlive())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_INNKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBinderActivateOpcode - %s not found or you can not interact with him.", npcGUID.ToString().c_str());
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

    WorldPacket data(SMSG_TRAINER_BUY_SUCCEEDED, (8+4));
    data << uint64(npc->GetGUID());
    data << uint32(bindspell);
    SendPacket(&data);

    _player->PlayerTalkClass->SendCloseGossip();
}

void WorldSession::HandleRequestStabledPets(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv MSG_LIST_STABLED_PETS");
    ObjectGuid npcGUID;

    recvData >> npcGUID;

    if (!CheckStableMaster(npcGUID))
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // remove mounts this fix bug where getting pet from stable while mounted deletes pet.
    if (GetPlayer()->IsMounted())
        GetPlayer()->RemoveAurasByType(SPELL_AURA_MOUNTED);

    SendStablePet(npcGUID);
}

void WorldSession::SendStablePet(ObjectGuid guid)
{
    TC_LOG_DEBUG("network", "WORLD: Recv MSG_LIST_STABLED_PETS Send.");

    WorldPacket data(MSG_LIST_STABLED_PETS, 200);           // guess size

    data << uint64(guid);

    size_t wpos = data.wpos();
    data << uint8(0);                                       // place holder for slot show number

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        data << uint8(0);                                   // stable slots
        SendPacket(&data);
        return;
    }

    data << uint8(petStable->MaxStabledPets);

    uint8 num = 0;                                          // counter for place holder

    if (petStable->CurrentPet)
    {
        PetStable::PetInfo const& pet = *petStable->CurrentPet;
        data << uint32(pet.PetNumber);
        data << uint32(pet.CreatureId);
        data << uint32(pet.Level);
        data << pet.Name;                                   // petname
        data << uint8(1);                                   // flags: 1 active, 2 inactive
        ++num;
    }
    else
    {
        if (PetStable::PetInfo const* pet = petStable->GetUnslottedHunterPet())
        {
            data << uint32(pet->PetNumber);
            data << uint32(pet->CreatureId);
            data << uint32(pet->Level);
            data << pet->Name;                                   // petname
            data << uint8(1);                                   // flags: 1 active, 2 inactive
            ++num;
        }
    }

    for (Optional<PetStable::PetInfo> const& stabledSlot : petStable->StabledPets)
    {
        if (stabledSlot)
        {
            PetStable::PetInfo const& pet = *stabledSlot;
            data << uint32(pet.PetNumber);
            data << uint32(pet.CreatureId);
            data << uint32(pet.Level);
            data << pet.Name;                               // petname
            data << uint8(2);                               // flags: 1 active, 2 inactive
            ++num;
        }
    }

    data.put<uint8>(wpos, num);                             // set real data to placeholder
    SendPacket(&data);
}

void WorldSession::SendPetStableResult(uint8 res)
{
    WorldPacket data(SMSG_STABLE_RESULT, 1);
    data << uint8(res);
    SendPacket(&data);
}

void WorldSession::HandleStablePet(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_STABLE_PET");
    ObjectGuid npcGUID;

    recvData >> npcGUID;

    if (!GetPlayer()->IsAlive())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
        return;

    Pet* pet = _player->GetPet();

    // can't place in stable dead pet
    if ((pet && (!pet->IsAlive() || pet->getPetType() != HUNTER_PET))
        || (!pet && (petStable->UnslottedPets.size() != 1 || !petStable->UnslottedPets[0].Health || petStable->UnslottedPets[0].Type != HUNTER_PET)))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    for (uint32 freeSlot = 0; freeSlot < petStable->MaxStabledPets; ++freeSlot)
    {
        if (!petStable->StabledPets[freeSlot])
        {
            if (pet)
            {
                // stable summoned pet
                _player->RemovePet(pet, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + freeSlot));
                std::swap(petStable->StabledPets[freeSlot], petStable->CurrentPet);
                SendPetStableResult(STABLE_SUCCESS_STABLE);
                return;
            }

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
            stmt->setUInt8(0, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + freeSlot));
            stmt->setUInt32(1, _player->GetGUID().GetCounter());
            stmt->setUInt32(2, petStable->UnslottedPets[0].PetNumber);
            CharacterDatabase.Execute(stmt);

            // stable unsummoned pet
            petStable->StabledPets[freeSlot] = std::move(petStable->UnslottedPets.back());
            petStable->UnslottedPets.pop_back();
            SendPetStableResult(STABLE_SUCCESS_STABLE);
            return;
        }
    }

    // not free stable slot
    SendPetStableResult(STABLE_ERR_STABLE);
}

void WorldSession::HandleUnstablePet(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_UNSTABLE_PET.");
    ObjectGuid npcGUID;
    uint32 petnumber;

    recvData >> npcGUID >> petnumber;

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    auto stabledPet = std::find_if(petStable->StabledPets.begin(), petStable->StabledPets.end(), [petnumber](Optional<PetStable::PetInfo> const& pet)
    {
        return pet && pet->PetNumber == petnumber;
    });

    if (stabledPet == petStable->StabledPets.end())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate((*stabledPet)->CreatureId);
    if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        // if problem in exotic pet
        if (creatureInfo && creatureInfo->IsTameable(true))
            SendPetStableResult(STABLE_ERR_EXOTIC);
        else
            SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    Pet* oldPet = _player->GetPet();
    if (oldPet)
    {
        // try performing a swap, client sends this packet instead of swap when starting from stabled slot
        if (!oldPet->IsAlive() || !oldPet->IsHunterPet())
        {
            SendPetStableResult(STABLE_ERR_STABLE);
            return;
        }

        _player->RemovePet(oldPet, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + std::distance(petStable->StabledPets.begin(), stabledPet)));
    }
    else if (petStable->UnslottedPets.size() == 1)
    {
        if (petStable->CurrentPet || !petStable->UnslottedPets[0].Health || petStable->UnslottedPets[0].Type != HUNTER_PET)
        {
            SendPetStableResult(STABLE_ERR_STABLE);
            return;
        }

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + std::distance(petStable->StabledPets.begin(), stabledPet)));
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petStable->UnslottedPets[0].PetNumber);
        CharacterDatabase.Execute(stmt);

        // move unsummoned pet into CurrentPet slot so that it gets moved into stable slot later
        petStable->CurrentPet = std::move(petStable->UnslottedPets.back());
        petStable->UnslottedPets.pop_back();
    }
    else if (petStable->CurrentPet || !petStable->UnslottedPets.empty())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    Pet* newPet = new Pet(_player, HUNTER_PET);
    if (!newPet->LoadPetFromDB(_player, 0, petnumber, false))
    {
        delete newPet;

        petStable->UnslottedPets.push_back(std::move(*petStable->CurrentPet));
        petStable->CurrentPet.reset();

        // update current pet slot in db immediately to maintain slot consistency, dismissed pet was already saved
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PET_SAVE_NOT_IN_SLOT);
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petnumber);
        CharacterDatabase.Execute(stmt);

        SendPetStableResult(STABLE_ERR_STABLE);
    }
    else
    {
        // update current pet slot in db immediately to maintain slot consistency, dismissed pet was already saved
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PET_SAVE_AS_CURRENT);
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petnumber);
        CharacterDatabase.Execute(stmt);

        SendPetStableResult(STABLE_SUCCESS_UNSTABLE);
    }
}

void WorldSession::HandleBuyStableSlot(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_BUY_STABLE_SLOT.");
    ObjectGuid npcGUID;

    recvData >> npcGUID;

    if (!CheckStableMaster(npcGUID))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    PetStable& petStable = GetPlayer()->GetOrInitPetStable();
    if (petStable.MaxStabledPets < MAX_PET_STABLES)
    {
        StableSlotPricesEntry const* SlotPrice = sStableSlotPricesStore.LookupEntry(petStable.MaxStabledPets + 1);
        if (_player->HasEnoughMoney(SlotPrice->Cost))
        {
            ++petStable.MaxStabledPets;
            _player->ModifyMoney(-int32(SlotPrice->Cost));
            SendPetStableResult(STABLE_SUCCESS_BUY_SLOT);
        }
        else
            SendPetStableResult(STABLE_ERR_MONEY);
    }
    else
        SendPetStableResult(STABLE_ERR_STABLE);
}

void WorldSession::HandleStableRevivePet(WorldPacket &/* recvData */)
{
    TC_LOG_DEBUG("network", "HandleStableRevivePet: Not implemented");
}

void WorldSession::HandleStableSwapPet(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_STABLE_SWAP_PET.");
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

    PetStable* petStable = GetPlayer()->GetPetStable();
    if (!petStable)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // Find swapped pet slot in stable
    auto stabledPet = std::find_if(petStable->StabledPets.begin(), petStable->StabledPets.end(), [petId](Optional<PetStable::PetInfo> const& pet)
    {
        return pet && pet->PetNumber == petId;
    });

    if (stabledPet == petStable->StabledPets.end())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate((*stabledPet)->CreatureId);
    if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        // if problem in exotic pet
        if (creatureInfo && creatureInfo->IsTameable(true))
            SendPetStableResult(STABLE_ERR_EXOTIC);
        else
            SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    Pet* oldPet = _player->GetPet();
    if (oldPet)
    {
        if (!oldPet->IsAlive() || !oldPet->IsHunterPet())
        {
            SendPetStableResult(STABLE_ERR_STABLE);
            return;
        }

        _player->RemovePet(oldPet, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + std::distance(petStable->StabledPets.begin(), stabledPet)));
    }
    else if (petStable->UnslottedPets.size() == 1)
    {
        if (petStable->CurrentPet || !petStable->UnslottedPets[0].Health || petStable->UnslottedPets[0].Type != HUNTER_PET)
        {
            SendPetStableResult(STABLE_ERR_STABLE);
            return;
        }

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + std::distance(petStable->StabledPets.begin(), stabledPet)));
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petStable->UnslottedPets[0].PetNumber);
        CharacterDatabase.Execute(stmt);

        // move unsummoned pet into CurrentPet slot so that it gets moved into stable slot later
        petStable->CurrentPet = std::move(petStable->UnslottedPets.back());
        petStable->UnslottedPets.pop_back();
    }
    else if (petStable->CurrentPet || !petStable->UnslottedPets.empty())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // summon unstabled pet
    Pet* newPet = new Pet(_player, HUNTER_PET);
    if (!newPet->LoadPetFromDB(_player, 0, petId, false))
    {
        delete newPet;
        SendPetStableResult(STABLE_ERR_STABLE);

        petStable->UnslottedPets.push_back(std::move(*petStable->CurrentPet));
        petStable->CurrentPet.reset();

        // update current pet slot in db immediately to maintain slot consistency, dismissed pet was already saved
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PET_SAVE_NOT_IN_SLOT);
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petId);
        CharacterDatabase.Execute(stmt);
    }
    else
    {
        // update current pet slot in db immediately to maintain slot consistency, dismissed pet was already saved
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID);
        stmt->setUInt8(0, PET_SAVE_AS_CURRENT);
        stmt->setUInt32(1, _player->GetGUID().GetCounter());
        stmt->setUInt32(2, petId);
        CharacterDatabase.Execute(stmt);

        SendPetStableResult(STABLE_SUCCESS_UNSTABLE);
    }
}

void WorldSession::HandleRepairItemOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_REPAIR_ITEM");

    ObjectGuid npcGUID, itemGUID;
    uint8 guildBank;                                        // new in 2.3.2, bool that means from guild bank money

    recvData >> npcGUID >> itemGUID >> guildBank;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_REPAIR);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleRepairItemOpcode - %s not found or you can not interact with him.", npcGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // reputation discount
    float discountMod = _player->GetReputationPriceDiscount(unit);

    if (itemGUID)
    {
        TC_LOG_DEBUG("network", "ITEM: Repair %s, at %s", itemGUID.ToString().c_str(), npcGUID.ToString().c_str());

        Item* item = _player->GetItemByGuid(itemGUID);
        if (item)
            _player->DurabilityRepair(item->GetPos(), true, discountMod);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at %s", npcGUID.ToString().c_str());
        _player->DurabilityRepairAll(true, discountMod, guildBank != 0);
    }
}
