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
#include "DBCStores.h"
#include "GossipDef.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "Player.h"
#include "QueryCallback.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldPacket.h"

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

void WorldSession::HandleBankerActivateOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BANKER_ACTIVATE");

    recvData >> guid;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_BANKER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBankerActivateOpcode - %s not found or you can not interact with him.", guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendShowBank(guid);
}

void WorldSession::SendShowBank(ObjectGuid guid)
{
    WorldPacket data(SMSG_SHOW_BANK, 8);
    data << guid;
    m_currentBankerGUID = guid;
    SendPacket(&data);
}

void WorldSession::SendShowMailBox(ObjectGuid guid)
{
    WorldPacket data(SMSG_SHOW_MAILBOX, 8);
    data << guid;
    SendPacket(&data);
}

void WorldSession::HandleTrainerListOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;

    recvData >> guid;
    SendTrainerList(guid);
}

void WorldSession::SendTrainerList(ObjectGuid guid, uint32 index)
{
    std::string str = GetTrinityString(LANG_NPC_TAINER_HELLO);
    SendTrainerList(guid, str, index);
}

void WorldSession::SendTrainerList(ObjectGuid guid, const std::string& strTitle, uint32 index)
{
    TC_LOG_DEBUG("network", "WORLD: SendTrainerList");

    Creature* trainer = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WORLD: SendTrainerList - %s not found or you can not interact with him.", guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    TrainerSpellData const* trainer_spells = trainer->GetTrainerSpells();
    if (!trainer_spells)
    {
        TC_LOG_DEBUG("network", "WORLD: SendTrainerList - Training spells not found for %s", guid.ToString().c_str());
        return;
    }

    WorldPacket data(SMSG_TRAINER_LIST, 8+4+4+trainer_spells->spellList.size()*38 + strTitle.size()+1);
    data << guid;
    data << uint32(trainer_spells->trainerType);
    data << uint32(1); // different value for each trainer, also found in CMSG_TRAINER_BUY_SPELL

    size_t count_pos = data.wpos();
    data << uint32(trainer_spells->spellList.size());

    // reputation discount
    float fDiscountMod = _player->GetReputationPriceDiscount(trainer);
    bool can_learn_primary_prof = GetPlayer()->GetFreePrimaryProfessionPoints() > 0;

    uint32 count = 0;
    for (TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
    {
        TrainerSpell const* tSpell = &itr->second;

        if (index && tSpell->Index != index)
            continue;

        bool valid = true;
        bool primary_prof_first_rank = false;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (!tSpell->ReqAbility[i])
                continue;
            if (!_player->IsSpellFitByClassAndRace(tSpell->ReqAbility[i]))
            {
                valid = false;
                break;
            }
            SpellInfo const* learnedSpellInfo = sSpellMgr->GetSpellInfo(tSpell->ReqAbility[i]);
            if (learnedSpellInfo && learnedSpellInfo->IsPrimaryProfessionFirstRank())
                primary_prof_first_rank = true;
        }
        if (!valid)
            continue;

        TrainerSpellState state = _player->GetTrainerSpellState(tSpell);

        data << uint32(tSpell->SpellID);                      // learned spell (or cast-spell in profession case)
        data << uint8(state == TRAINER_SPELL_GREEN_DISABLED ? TRAINER_SPELL_GREEN : state);
        data << uint32(floor(tSpell->MoneyCost * fDiscountMod));

        data << uint8(tSpell->ReqLevel);
        data << uint32(tSpell->ReqSkillLine);
        data << uint32(tSpell->ReqSkillRank);
        //prev + req or req + 0
        uint8 maxReq = 0;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (!tSpell->ReqAbility[i])
                continue;
            if (uint32 prevSpellId = sSpellMgr->GetPrevSpellInChain(tSpell->ReqAbility[i]))
            {
                data << uint32(prevSpellId);
                ++maxReq;
            }
            if (maxReq == 2)
                break;
            SpellsRequiringSpellMapBounds spellsRequired = sSpellMgr->GetSpellsRequiredForSpellBounds(tSpell->ReqAbility[i]);
            for (SpellsRequiringSpellMap::const_iterator itr2 = spellsRequired.first; itr2 != spellsRequired.second && maxReq < 3; ++itr2)
            {
                data << uint32(itr2->second);
                ++maxReq;
            }
            if (maxReq == 2)
                break;
        }
        while (maxReq < 2)
        {
            data << uint32(0);
            ++maxReq;
        }

        data << uint32(primary_prof_first_rank && can_learn_primary_prof ? 1 : 0);
        // primary prof. learn confirmation dialog
        data << uint32(primary_prof_first_rank ? 1 : 0);    // must be equal prev. field to have learn button in enabled state

        ++count;
    }

    data << strTitle;

    data.put<uint32>(count_pos, count);
    SendPacket(&data);
}

void WorldSession::HandleTrainerBuySpellOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint32 spellId;
    uint32 trainerId;

    recvData >> guid >> trainerId >> spellId;
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_TRAINER_BUY_SPELL %s, learn spell id is: %u", guid.ToString().c_str(), spellId);

    Creature* trainer = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!trainer)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTrainerBuySpellOpcode - %s not found or you can not interact with him.", guid.ToString().c_str());
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
        SendTrainerBuyFailed(guid, spellId, 0);
        return;
    }

    // not found, cheat?
    TrainerSpell const* trainer_spell = trainer_spells->Find(spellId);
    if (!trainer_spell)
    {
        SendTrainerBuyFailed(guid, spellId, 0);
        return;
    }

    // can't be learn, cheat? Or double learn with lags...
    if (_player->GetTrainerSpellState(trainer_spell) != TRAINER_SPELL_GREEN)
    {
        SendTrainerBuyFailed(guid, spellId, 0);
        return;
    }

    // apply reputation discount
    uint32 nSpellCost = uint32(floor(trainer_spell->MoneyCost * _player->GetReputationPriceDiscount(trainer)));

    // check money requirement
    if (!_player->HasEnoughMoney(uint64(nSpellCost)))
    {
        SendTrainerBuyFailed(guid, spellId, 1);
        return;
    }

    _player->ModifyMoney(-int64(nSpellCost));

    trainer->SendPlaySpellVisualKit(179, 0, 0); // 53 SpellCastDirected
    trainer->SendPlaySpellVisualKit(362, 1, 0);    // 113 EmoteSalute

    // learn explicitly or cast explicitly
    if (trainer_spell->IsCastable())
        _player->CastSpell(_player, trainer_spell->SpellID, true);
    else
        _player->LearnSpell(spellId, false);

    WorldPacket data(SMSG_TRAINER_BUY_SUCCEEDED, 12);
    data << uint64(guid);
    data << uint32(spellId);
    SendPacket(&data);
}

void WorldSession::SendTrainerBuyFailed(uint64 guid, uint32 spellId, uint32 reason)
{
    WorldPacket data(SMSG_TRAINER_BUY_FAILED, 16);
    data << uint64(guid);
    data << uint32(spellId);        // should be same as in packet from client
    data << uint32(reason);         // 1 == "Not enough money for trainer service." 0 == "Trainer service %d unavailable."
    SendPacket(&data);
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

        // If npc is a flightmaster who is a quest giver do not send the gossip if there is no quest
        if (unit->IsTaxi() && (unit->IsQuestGiver() || unit->IsGossip()))
        {
            if (_player->PlayerTalkClass->GetQuestMenu().Empty() && _player->PlayerTalkClass->GetGossipMenu().Empty())
            {
                SendTaxiMenu(unit);
                return;
            }
        }

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
        corpseGrave = sObjectMgr->GetClosestGraveyard(corpseLocation, _player->GetTeam(), _player);
    }

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if (corpseGrave)
    {
        WorldSafeLocsEntry const* ghostGrave = sObjectMgr->GetClosestGraveyard(*_player, _player->GetTeam(), _player);

        if (corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->map_id, corpseGrave->x, corpseGrave->y, corpseGrave->z, _player->GetOrientation());
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

    WorldPacket data(SMSG_TRAINER_BUY_SUCCEEDED, 12);
    data << uint64(npc->GetGUID());
    data << uint32(bindspell);
    SendPacket(&data);

    _player->PlayerTalkClass->SendCloseGossip();
}

void WorldSession::HandleListStabledPetsOpcode(WorldPacket& recvData)
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
    WorldPacket data(MSG_LIST_STABLED_PETS, 200);

    data << uint64(guid); // Stablemaster
    data << uint8(_player->PlayerPetDataStore.size());
    data << uint8(PET_SLOT_LAST_STABLE_SLOT); // Stable Slots

    for (PlayerPetData* p : _player->PlayerPetDataStore)
    {
        uint32 petSlot = p->Slot;
        uint8 flags = PET_STABLE_ACTIVE;

        if (petSlot > PET_SLOT_LAST_ACTIVE_SLOT)
            flags |= PET_STABLE_INACTIVE;

        data << int32(petSlot);
        data << uint32(p->PetId);
        data << uint32(p->CreatureId);
        data << uint32(p->Petlevel);
        data << p->Name;
        data << uint8(flags);
    }

    SendPacket(&data);
}

void WorldSession::SendStableResult(uint8 res)
{
    WorldPacket data(SMSG_STABLE_RESULT, 1);
    data << uint8(res);
    SendPacket(&data);
}

void WorldSession::HandleSetPetSlot(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recv CMSG_STABLE_PET");
    ObjectGuid guid;
    uint32 petId;
    uint8 new_slot;

    recvData >> petId >> new_slot;

    guid[3] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[2]);

    if (!GetPlayer()->IsAlive())
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!CheckStableMaster(guid))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (new_slot > PET_SLOT_LAST_STABLE_SLOT || new_slot < PET_SLOT_FIRST_ACTIVE_SLOT)
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }
    PlayerPetData* playerPetData = _player->GetPlayerPetDataById(petId);
    CreatureTemplate const* creatureInfo = nullptr;

    if (playerPetData)
        creatureInfo = sObjectMgr->GetCreatureTemplate(playerPetData->CreatureId);

    if (!creatureInfo || !creatureInfo->IsTameable(true))
    {
        SendStableResult(STABLE_ERR_STABLE);
        return;
    }

    if (!creatureInfo->IsTameable(_player->CanTameExoticPets()) && new_slot <= PET_SLOT_LAST_ACTIVE_SLOT)
    {
        SendStableResult(STABLE_ERR_EXOTIC);
        return;
    }

    // remove fake death 2
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet* pet = _player->GetPet();

    // can't place in stable dead pet
    if (pet)
    {
        if (pet->GetCharmInfo()->GetPetNumber() == petId)
        {
            if (!pet->IsAlive() || !pet->IsHunterPet())
            {
                SendStableResult(STABLE_ERR_STABLE);
                return;
            }
        }
    }

    if (playerPetData)
    {
        UpdatePetSlot(petId, playerPetData->Slot, new_slot);
    }
}

void WorldSession::HandleStableRevivePet(WorldPacket &/* recvData */)
{
    TC_LOG_DEBUG("network", "HandleStableRevivePet: Not implemented");
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
            _player->DurabilityRepair(item->GetPos(), true, discountMod, guildBank != 0);
    }
    else
    {
        TC_LOG_DEBUG("network", "ITEM: Repair all items at %s", npcGUID.ToString().c_str());
        _player->DurabilityRepairAll(true, discountMod, guildBank != 0);
    }
}
