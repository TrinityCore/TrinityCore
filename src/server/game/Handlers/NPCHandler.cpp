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

#include "Common.h"
#include "Language.h"
#include "DatabaseEnv.h"
#include "QueryCallback.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "ObjectAccessor.h"
#include "Creature.h"
#include "Pet.h"
#include "PetPackets.h"
#include "ReputationMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "GameObjectAI.h"
#include "SpellInfo.h"
#include "NPCPackets.h"
#include "MailPackets.h"

enum StableResultCode
{
    STABLE_ERR_MONEY        = 0x01,                         // "you don't have enough money"
    STABLE_ERR_INVALID_SLOT = 0x03,                         // "That slot is locked"
    STABLE_SUCCESS_STABLE   = 0x08,                         // stable success
    STABLE_SUCCESS_UNSTABLE = 0x09,                         // unstable/swap success
    STABLE_SUCCESS_BUY_SLOT = 0x0A,                         // buy slot success
    STABLE_ERR_EXOTIC       = 0x0B,                         // "you are unable to control exotic creatures"
    STABLE_ERR_STABLE       = 0x0C,                         // "Internal pet error"
};

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
    SendTrainerList(packet.Unit);
}

void WorldSession::SendTrainerList(ObjectGuid guid)
{
    std::string str = GetTrinityString(LANG_NPC_TAINER_HELLO);
    SendTrainerList(guid, str);
}

void WorldSession::SendTrainerList(ObjectGuid guid, const std::string& strTitle)
{
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

            SpellsRequiringSpellMapBounds spellsRequired = sSpellMgr->GetSpellsRequiredForSpellBounds(tSpell->ReqAbility[i]);
            for (SpellsRequiringSpellMap::const_iterator itr2 = spellsRequired.first; itr2 != spellsRequired.second && maxReq < MAX_TRAINERSPELL_ABILITY_REQS; ++itr2)
            {
                spell.ReqAbility[maxReq] = itr2->second;
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
    if (trainer->GetCreatureTemplate()->trainer_type == TRAINER_TYPE_MOUNTS)
    {
        if (uint32 trainerRace = trainer->GetCreatureTemplate()->trainer_race)
            if (_player->getRace() != trainerRace)
                return;
    }

    // check class for class trainers
    if (_player->getClass() != trainer->GetCreatureTemplate()->trainer_class && trainer->GetCreatureTemplate()->trainer_type == TRAINER_TYPE_CLASS)
        return;

    // check present spell in trainer spell list
    TrainerSpellData const* trainer_spells = trainer->GetTrainerSpells();
    if (!trainer_spells)
    {
        SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // not found, cheat?
    TrainerSpell const* trainerSpell = trainer_spells->Find(packet.SpellID);
    if (!trainerSpell)
    {
        SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // can't be learn, cheat? Or double learn with lags...
    if (_player->GetTrainerSpellState(trainerSpell) != TRAINER_SPELL_GREEN)
    {
        SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 0);
        return;
    }

    // apply reputation discount
    uint32 nSpellCost = uint32(floor(trainerSpell->MoneyCost * _player->GetReputationPriceDiscount(trainer)));

    // check money requirement
    if (!_player->HasEnoughMoney(uint64(nSpellCost)))
    {
        SendTrainerBuyFailed(packet.TrainerGUID, packet.SpellID, 1);
        return;
    }

    _player->ModifyMoney(-int64(nSpellCost));

    trainer->SendPlaySpellVisualKit(179, 0);    // 53 SpellCastDirected
    _player->SendPlaySpellVisualKit(362, 1);    // 113 EmoteSalute

    // learn explicitly or cast explicitly
    if (trainerSpell->IsCastable())
        _player->CastSpell(_player, trainerSpell->SpellID, true);
    else
        _player->LearnSpell(packet.SpellID, false);
}

void WorldSession::SendTrainerBuyFailed(ObjectGuid trainerGUID, uint32 spellID, int32 trainerFailedReason)
{
    WorldPackets::NPC::TrainerBuyFailed trainerBuyFailed;
    trainerBuyFailed.TrainerGUID = trainerGUID;
    trainerBuyFailed.SpellID = spellID;                             // should be same as in packet from client
    trainerBuyFailed.TrainerFailedReason = trainerFailedReason;     // 1 == "Not enough money for trainer service." 0 == "Trainer service %d unavailable."
    SendPacket(trainerBuyFailed.Write());
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
    if (_player->PlayerTalkClass->GetGossipMenu().GetSenderGUID() != packet.GossipUnit)
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
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOTS_DETAIL);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt8(1, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(2, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::SendStablePetCallback, this, guid, std::placeholders::_1)));
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
        stableEntry.ExperienceLevel = pet->getLevel();
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

void WorldSession::SendPetStableResult(uint8 res)
{
    WorldPacket data(SMSG_PET_STABLE_RESULT, 1);
    data << uint8(res);
    SendPacket(&data);
}

void WorldSession::HandleStablePet(WorldPacket& recvData)
{
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

    Pet* pet = _player->GetPet();

    // can't place in stable dead pet
    if (!pet || !pet->IsAlive() || pet->getPetType() != HUNTER_PET)
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SLOTS);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt8(1, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(2, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleStablePetCallback, this, std::placeholders::_1)));
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
        SendPetStableResult(STABLE_SUCCESS_STABLE);
    }
    else
        SendPetStableResult(STABLE_ERR_INVALID_SLOT);
}

void WorldSession::HandleUnstablePet(WorldPacket& recvData)
{
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_ENTRY);

    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt32(1, petnumber);
    stmt->setUInt8(2, PET_SAVE_FIRST_STABLE_SLOT);
    stmt->setUInt8(3, PET_SAVE_LAST_STABLE_SLOT);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&WorldSession::HandleUnstablePetCallback, this, petnumber, std::placeholders::_1)));
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
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petEntry);
    if (!creatureInfo || !creatureInfo->IsTameable(_player->CanTameExoticPets()))
    {
        // if problem in exotic pet
        if (creatureInfo && creatureInfo->IsTameable(true))
            SendPetStableResult(STABLE_ERR_EXOTIC);
        else
            SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    Pet* pet = _player->GetPet();
    if (pet && pet->IsAlive())
    {
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    // delete dead pet
    if (pet)
        _player->RemovePet(pet, PET_SAVE_AS_DELETED);

    Pet* newPet = new Pet(_player, HUNTER_PET);
    if (!newPet->LoadPetFromDB(_player, petEntry, petId))
    {
        delete newPet;
        newPet = NULL;
        SendPetStableResult(STABLE_ERR_STABLE);
        return;
    }

    SendPetStableResult(STABLE_SUCCESS_UNSTABLE);
}

void WorldSession::HandleBuyStableSlot(WorldPacket& recvData)
{
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

    if (GetPlayer()->m_stableSlots < MAX_PET_STABLES)
    {
        /*StableSlotPricesEntry const* SlotPrice = sStableSlotPricesStore.LookupEntry(GetPlayer()->m_stableSlots+1);
        if (_player->HasEnoughMoney(SlotPrice->Price))
        {
            ++GetPlayer()->m_stableSlots;
            _player->ModifyMoney(-int32(SlotPrice->Price));
            SendPetStableResult(STABLE_SUCCESS_BUY_SLOT);
        }
        else
            SendPetStableResult(STABLE_ERR_MONEY);*/
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
    if (!newPet->LoadPetFromDB(_player, petEntry, petId))
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

