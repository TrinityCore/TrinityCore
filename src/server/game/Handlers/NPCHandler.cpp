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
        SendTrainerListLegacy(npc->GetGUID(), 0);
        //TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - Creature id %u has no trainer data.", npc->GetEntry());
}

void WorldSession::SendTrainerList(Creature* npc, uint32 trainerId)
{
    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(trainerId);
    if (!trainer)
    {
        //TC_LOG_DEBUG("network", "WorldSession::SendTrainerList - trainer spells not found for trainer %s id %d", npc->GetGUID().ToString().c_str(), trainerId);
        SendTrainerListLegacy(npc->GetGUID(), 0);
        return;
    }

    _player->PlayerTalkClass->GetInteractionData().Reset();
    _player->PlayerTalkClass->GetInteractionData().SourceGuid = npc->GetGUID();
    _player->PlayerTalkClass->GetInteractionData().TrainerId = trainerId;
    trainer->SendSpells(npc, _player, GetSessionDbLocaleIndex());
}

void WorldSession::SendTrainerListLegacy(ObjectGuid guid, uint32 index)
{
    std::string strTitle = GetTrinityString(LANG_NPC_TAINER_HELLO);
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: SendTrainerList - %s not found or you can not interact with him.", guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    TrainerSpellData const* trainer_spells = unit->GetTrainerSpells();
    if (!trainer_spells)
    {
        TC_LOG_DEBUG("network", "WORLD: SendTrainerList - Training spells not found for %s", guid.ToString().c_str());
        return;
    }

    WorldPackets::NPC::TrainerList packet;
    packet.TrainerGUID = guid;
    packet.TrainerType = trainer_spells->trainerType;
    packet.Greeting = strTitle;

    // reputation discount
    float fDiscountMod = _player->GetReputationPriceDiscount(unit);

    packet.Spells.reserve(trainer_spells->spellList.size());
    for (TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
    {
        TrainerSpell const* tSpell = &itr->second;

        if (index && tSpell->Index != index)
            continue;

        bool valid = true;
        for (uint8 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
        {
            if (!tSpell->ReqAbility[i])
                continue;
            if (!_player->IsSpellFitByClassAndRace(tSpell->ReqAbility[i]))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
            continue;

        TrainerSpellState state = _player->GetTrainerSpellState(tSpell);

        WorldPackets::NPC::TrainerListSpell spell;
        spell.SpellID = tSpell->SpellID;
        spell.MoneyCost = floor(tSpell->MoneyCost * fDiscountMod);
        spell.ReqSkillLine = tSpell->ReqSkillLine;
        spell.ReqSkillRank = tSpell->ReqSkillRank;
        spell.ReqLevel = tSpell->ReqLevel;
        spell.Usable = (state == TRAINER_SPELL_GREEN_DISABLED ? TRAINER_SPELL_GREEN : state);

        uint8 maxReq = 0;
        for (uint8 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
        {
            if (!tSpell->ReqAbility[i])
                continue;

            if (uint32 prevSpellId = sSpellMgr->GetPrevSpellInChain(tSpell->ReqAbility[i]))
            {
                spell.ReqAbility[maxReq] = prevSpellId;
                ++maxReq;
            }

            if (maxReq == 2)
                break;

            for (auto const& requirePair : sSpellMgr->GetSpellsRequiredForSpellBounds(tSpell->ReqAbility[i]))
            {
                spell.ReqAbility[maxReq] = requirePair.second;
                ++maxReq;
            }

            if (maxReq == 2)
                break;
        }

        packet.Spells.push_back(spell);
    }

    SendPacket(packet.Write());
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
    {
        HandleTrainerBuySpellOpcodeLegacy(packet);
        return;
    }

    if (_player->PlayerTalkClass->GetInteractionData().TrainerId != uint32(packet.TrainerID))
    {
        HandleTrainerBuySpellOpcodeLegacy(packet);
        return;
    }

    Trainer::Trainer const* trainer = sObjectMgr->GetTrainer(packet.TrainerID);
    if (!trainer)
    {
        HandleTrainerBuySpellOpcodeLegacy(packet);
        return;
    }

    trainer->TeachSpell(npc, _player, packet.SpellID);
}

void WorldSession::HandleTrainerBuySpellOpcodeLegacy(WorldPackets::NPC::TrainerBuySpell& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL %s, learn spell id is: %i", packet.TrainerGUID.ToString().c_str(), packet.SpellID);

    Creature* trainer = GetPlayer()->GetNPCIfCanInteractWith(packet.TrainerGUID, UNIT_NPC_FLAG_TRAINER);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - %s not found or you can not interact with him.", packet.TrainerGUID.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // check race for mount trainers
    /*if (trainer->GetCreatureTemplate()->trainer_type == TRAINER_TYPE_MOUNTS)
    {
        if (uint32 trainerRace = trainer->GetCreatureTemplate()->trainer_race)
            if (_player->getRace() != trainerRace)
                return;
    }*/

    // check class for class trainers
    if (trainer->GetCreatureTemplate()->trainer_class && _player->getClass() != trainer->GetCreatureTemplate()->trainer_class)
        return;

    // check present spell in trainer spell list
    TrainerSpellData const* trainer_spells = trainer->GetTrainerSpells();
    if (!trainer_spells)
    {
        //SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // not found, cheat?
    TrainerSpell const* trainerSpell = trainer_spells->Find(packet.SpellID);
    if (!trainerSpell)
    {
        //SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // can't be learn, cheat? Or double learn with lags...
    if (_player->GetTrainerSpellState(trainerSpell) != TRAINER_SPELL_GREEN)
    {
        //SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // apply reputation discount
    uint32 nSpellCost = uint32(floor(trainerSpell->MoneyCost * _player->GetReputationPriceDiscount(trainer)));

    // check money requirement
    if (!_player->HasEnoughMoney(uint64(nSpellCost)))
    {
        //SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 1);
        return;
    }

    _player->ModifyMoney(-int64(nSpellCost));

    trainer->SendPlaySpellVisualKit(179, 0, 0);    // 53 SpellCastDirected
    _player->SendPlaySpellVisualKit(362, 1, 0);    // 113 EmoteSalute

                                                   // learn explicitly or cast explicitly
    if (trainerSpell->IsCastable())
        _player->CastSpell(_player, trainerSpell->SpellID, true);
    else
        _player->LearnSpell(packet.SpellID, false);
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
        _player->TalkedToCreature(unit->GetEntry(), unit->GetGUID());
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
        corpseGrave = sObjectMgr->GetClosestGraveYard(corpseLocation, _player->GetTeam(), _player);
    }

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr->GetClosestGraveYard(*_player, _player->GetTeam(), _player);

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
        uint8 flags = PET_STABLE_ACTIVE;

        if (petSlot > PET_SLOT_LAST_ACTIVE_SLOT)
            flags |= PET_STABLE_INACTIVE;

        stableEntry.PetSlot         = petSlot;              // slot
        stableEntry.PetNumber       = p->PetId;             // petnumber
        stableEntry.CreatureID      = p->CreatureId;        // creature entry
        stableEntry.DisplayID       = p->DisplayId;         // creature displayid
        stableEntry.ExperienceLevel = p->Petlevel;          // level
        stableEntry.PetFlags        = flags;                // flags
        stableEntry.PetName         = p->Name;              // Name

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
    PlayerPetData* playerPetData = _player->GetPlayerPetDataById(packet.PetNumber);
    CreatureTemplate const* creatureInfo = nullptr;

    if (playerPetData)
        creatureInfo = sObjectMgr->GetCreatureTemplate(playerPetData->CreatureId);

    if (!creatureInfo || !creatureInfo->IsTameable(true))
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!creatureInfo->IsTameable(_player->CanTameExoticPets()) && packet.DestSlot <= PET_SLOT_LAST_ACTIVE_SLOT)
    {
        SendPetStableResult(STABLE_ERR_EXOTIC);
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
            if (!pet->IsAlive() || !pet->IsHunterPet())
            {
                SendPetStableResult(STABLE_ERR_STABLE);
                return;
            }
        }
    }

    if (playerPetData)
    {
        UpdatePetSlot(packet.PetNumber, playerPetData->Slot, packet.DestSlot);
    }
}

void WorldSession::HandleStableRevivePet(WorldPacket &/* recvData */)
{
    TC_LOG_DEBUG("network", "HandleStableRevivePet: Not implemented");
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
