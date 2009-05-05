/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "UpdateMask.h"
#include "ScriptCalls.h"
#include "ObjectAccessor.h"
#include "Creature.h"
#include "Pet.h"
#include "BattleGroundMgr.h"
#include "BattleGround.h"
#include "Guild.h"

void WorldSession::HandleTabardVendorActivateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 guid;
    recv_data >> guid;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid,UNIT_NPC_FLAG_TABARDDESIGNER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleTabardVendorActivateOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendTabardVendorActivate(guid);
}

void WorldSession::SendTabardVendorActivate( uint64 guid )
{
    WorldPacket data( MSG_TABARDVENDOR_ACTIVATE, 8 );
    data << guid;
    SendPacket( &data );
}

void WorldSession::HandleBankerActivateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 guid;

    sLog.outDebug(  "WORLD: Received CMSG_BANKER_ACTIVATE" );

    recv_data >> guid;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid,UNIT_NPC_FLAG_BANKER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleBankerActivateOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendShowBank(guid);
}

void WorldSession::SendShowBank( uint64 guid )
{
    WorldPacket data( SMSG_SHOW_BANK, 8 );
    data << guid;
    SendPacket( &data );
}

void WorldSession::HandleTrainerListOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 guid;

    recv_data >> guid;
    SendTrainerList( guid );
}

void WorldSession::SendTrainerList( uint64 guid )
{
    std::string str = GetTrinityString(LANG_NPC_TAINER_HELLO);
    SendTrainerList( guid, str );
}

void WorldSession::SendTrainerList( uint64 guid, const std::string& strTitle )
{
    sLog.outDebug( "WORLD: SendTrainerList" );

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid,UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: SendTrainerList - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // trainer list loaded at check;
    if(!unit->isCanTrainingOf(_player,true))
        return;

    CreatureInfo const *ci = unit->GetCreatureInfo();

    if (!ci)
    {
        sLog.outDebug( "WORLD: SendTrainerList - (GUID: %u) NO CREATUREINFO!",GUID_LOPART(guid) );
        return;
    }

    TrainerSpellData const* trainer_spells = unit->GetTrainerSpells();
    if(!trainer_spells)
    {
        sLog.outDebug( "WORLD: SendTrainerList - Training spells not found for creature (GUID: %u Entry: %u)",
            GUID_LOPART(guid), unit->GetEntry());
        return;
    }

    WorldPacket data( SMSG_TRAINER_LIST, 8+4+4+trainer_spells->spellList.size()*38 + strTitle.size()+1);
    data << guid;
    data << uint32(trainer_spells->trainerType);

    size_t count_pos = data.wpos();
    data << uint32(trainer_spells->spellList.size());

    // reputation discount
    float fDiscountMod = _player->GetReputationPriceDiscount(unit);
    bool can_learn_primary_prof = GetPlayer()->GetFreePrimaryProffesionPoints() > 0;

    uint32 count = 0;
    for(TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
    {
        TrainerSpell const* tSpell = &itr->second;

        if(!_player->IsSpellFitByClassAndRace(tSpell->learnedSpell))
            continue;

        bool primary_prof_first_rank = spellmgr.IsPrimaryProfessionFirstRankSpell(tSpell->learnedSpell);
        SpellChainNode const* chain_node = spellmgr.GetSpellChainNode(tSpell->learnedSpell);
        uint32 req_spell = spellmgr.GetSpellRequired(tSpell->spell);
        TrainerSpellState state = _player->GetTrainerSpellState(tSpell);

        data << uint32(tSpell->spell);                      // learned spell (or cast-spell in profession case)
        data << uint8(state==TRAINER_SPELL_GREEN_DISABLED ? TRAINER_SPELL_GREEN : state);
        data << uint32(floor(tSpell->spellCost * fDiscountMod));

        data << uint32(primary_prof_first_rank && can_learn_primary_prof ? 1 : 0);
                                                            // primary prof. learn confirmation dialog
        data << uint32(primary_prof_first_rank ? 1 : 0);    // must be equal prev. field to have learn button in enabled state
        data << uint8(tSpell->reqLevel);
        data << uint32(tSpell->reqSkill);
        data << uint32(tSpell->reqSkillValue);
        //prev + req or req + 0
        data << uint32(!tSpell->IsCastable() && chain_node && chain_node->prev ? chain_node->prev : req_spell);
        data << uint32(!tSpell->IsCastable() && chain_node && chain_node->prev ? req_spell : 0);
        data << uint32(0);

        ++count;
    }

    data << strTitle;

    data.put<uint32>(count_pos,count);
    SendPacket( &data );
}

void WorldSession::HandleTrainerBuySpellOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 guid;
    uint32 spellId = 0;

    recv_data >> guid >> spellId;
    sLog.outDebug( "WORLD: Received CMSG_TRAINER_BUY_SPELL NpcGUID=%u, learn spell id is: %u",uint32(GUID_LOPART(guid)), spellId );

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_TRAINER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleTrainerBuySpellOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if(!unit->isCanTrainingOf(_player,true))
        return;

    // check present spell in trainer spell list
    TrainerSpellData const* trainer_spells = unit->GetTrainerSpells();
    if(!trainer_spells)
        return;

    // not found, cheat?
    TrainerSpell const* trainer_spell = trainer_spells->Find(spellId);
    if(!trainer_spell)
        return;

    // can't be learn, cheat? Or double learn with lags...
    if(_player->GetTrainerSpellState(trainer_spell) != TRAINER_SPELL_GREEN)
        return;

    // apply reputation discount
    uint32 nSpellCost = uint32(floor(trainer_spell->spellCost * _player->GetReputationPriceDiscount(unit)));

    // check money requirement
    if(_player->GetMoney() < nSpellCost )
        return;

    _player->ModifyMoney( -int32(nSpellCost) );

    WorldPacket data(SMSG_PLAY_SPELL_VISUAL, 12);           // visual effect on trainer
    data << uint64(guid) << uint32(0xB3);
    SendPacket(&data);

    data.Initialize(SMSG_PLAY_SPELL_IMPACT, 12);            // visual effect on player
    data << uint64(_player->GetGUID()) << uint32(0x016A);
    SendPacket(&data);

    // learn explicitly or cast explicitly
    if(trainer_spell->IsCastable ())
        //FIXME: prof. spell entry in trainer list not marked gray until list re-open.
        _player->CastSpell(_player,trainer_spell->spell,true);
    else
        _player->learnSpell(spellId,false);

    data.Initialize(SMSG_TRAINER_BUY_SUCCEEDED, 12);
    data << uint64(guid) << uint32(trainer_spell->spell);
    SendPacket(&data);
}

void WorldSession::HandleGossipHelloOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    sLog.outDebug(  "WORLD: Received CMSG_GOSSIP_HELLO" );

    uint64 guid;
    recv_data >> guid;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_NONE);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleGossipHelloOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    GetPlayer()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
    // remove fake death
    //if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
    //    GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if( unit->isArmorer() || unit->isCivilian() || unit->isQuestGiver() || unit->isServiceProvider())
    {
        unit->StopMoving();
    }

    // If spiritguide, no need for gossip menu, just put player into resurrect queue
    if (unit->isSpiritGuide())
    {
        BattleGround *bg = _player->GetBattleGround();
        if(bg)
        {
            bg->AddPlayerToResurrectQueue(unit->GetGUID(), _player->GetGUID());
            sBattleGroundMgr.SendAreaSpiritHealerQueryOpcode(_player, bg, unit->GetGUID());
            return;
        }
    }

    if(!Script->GossipHello( _player, unit ))
    {
        _player->TalkedToCreature(unit->GetEntry(),unit->GetGUID());
        unit->prepareGossipMenu(_player);
        unit->sendPreparedGossip(_player);
    }
}

/*void WorldSession::HandleGossipSelectOptionOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4+4);

    sLog.outDebug("WORLD: CMSG_GOSSIP_SELECT_OPTION");

    uint32 option;
    uint32 unk;
    uint64 guid;
    std::string code = "";

    recv_data >> guid >> unk >> option;

    if(_player->PlayerTalkClass->GossipOptionCoded( option ))
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data,8+4+1);
        sLog.outDebug("reading string");
        recv_data >> code;
        sLog.outDebug("string read: %s", code.c_str());
    }

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_NONE);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleGossipSelectOptionOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if(!code.empty())
    {
        if (!Script->GossipSelectWithCode(_player, unit, _player->PlayerTalkClass->GossipOptionSender (option), _player->PlayerTalkClass->GossipOptionAction( option ), code.c_str()))
            unit->OnGossipSelect (_player, option);
    }
    else
    {
        if (!Script->GossipSelect (_player, unit, _player->PlayerTalkClass->GossipOptionSender (option), _player->PlayerTalkClass->GossipOptionAction (option)))
           unit->OnGossipSelect (_player, option);
    }
}*/

void WorldSession::HandleSpiritHealerActivateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    sLog.outDebug("WORLD: CMSG_SPIRIT_HEALER_ACTIVATE");

    uint64 guid;

    recv_data >> guid;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_SPIRITHEALER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleSpiritHealerActivateOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendSpiritResurrect();
}

void WorldSession::SendSpiritResurrect()
{
    _player->ResurrectPlayer(0.5f, true);

    _player->DurabilityLossAll(0.25f,true);

    // get corpse nearest graveyard
    WorldSafeLocsEntry const *corpseGrave = NULL;
    Corpse *corpse = _player->GetCorpse();
    if(corpse)
        corpseGrave = objmgr.GetClosestGraveYard(
            corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetMapId(), _player->GetTeam() );

    // now can spawn bones
    _player->SpawnCorpseBones();

    // teleport to nearest from corpse graveyard, if different from nearest to player ghost
    if(corpseGrave)
    {
        WorldSafeLocsEntry const *ghostGrave = objmgr.GetClosestGraveYard(
            _player->GetPositionX(), _player->GetPositionY(), _player->GetPositionZ(), _player->GetMapId(), _player->GetTeam() );

        if(corpseGrave != ghostGrave)
            _player->TeleportTo(corpseGrave->map_id, corpseGrave->x, corpseGrave->y, corpseGrave->z, _player->GetOrientation());
        // or update at original position
        else
            //ObjectAccessor::UpdateVisibilityForPlayer(_player);
            _player->SetToNotify();
    }
    // or update at original position
    else
        //ObjectAccessor::UpdateVisibilityForPlayer(_player);
        _player->SetToNotify();

    _player->SaveToDB();
}

void WorldSession::HandleBinderActivateOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 npcGUID;
    recv_data >> npcGUID;

    if(!GetPlayer()->isAlive())
        return;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID,UNIT_NPC_FLAG_INNKEEPER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleBinderActivateOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendBindPoint(unit);
}

void WorldSession::SendBindPoint(Creature *npc)
{
    // prevent set homebind to instances in any case
    if(sMapStore.LookupEntry(GetPlayer()->GetMapId())->Instanceable())
        return;

    uint32 bindspell = 3286;
    uint32 zone_id = _player->GetZoneId();

    // update sql homebind
    CharacterDatabase.PExecute("UPDATE character_homebind SET map = '%u', zone = '%u', position_x = '%f', position_y = '%f', position_z = '%f' WHERE guid = '%u'", _player->GetMapId(), zone_id, _player->GetPositionX(), _player->GetPositionY(), _player->GetPositionZ(), _player->GetGUIDLow());
    _player->m_homebindMapId = _player->GetMapId();
    _player->m_homebindZoneId = zone_id;
    _player->m_homebindX = _player->GetPositionX();
    _player->m_homebindY = _player->GetPositionY();
    _player->m_homebindZ = _player->GetPositionZ();

    // send spell for bind 3286 bind magic
    _player->CastSpell(_player, bindspell, true);

    WorldPacket data( SMSG_TRAINER_BUY_SUCCEEDED, (8+4));
    data << npc->GetGUID();
    data << bindspell;
    SendPacket( &data );

    // binding
    data.Initialize( SMSG_BINDPOINTUPDATE, (4+4+4+4+4) );
    data << float(_player->GetPositionX());
    data << float(_player->GetPositionY());
    data << float(_player->GetPositionZ());
    data << uint32(_player->GetMapId());
    data << uint32(zone_id);
    SendPacket( &data );

    DEBUG_LOG("New Home Position X is %f",_player->GetPositionX());
    DEBUG_LOG("New Home Position Y is %f",_player->GetPositionY());
    DEBUG_LOG("New Home Position Z is %f",_player->GetPositionZ());
    DEBUG_LOG("New Home MapId is %u",_player->GetMapId());
    DEBUG_LOG("New Home ZoneId is %u",zone_id);

    // zone update
    data.Initialize( SMSG_PLAYERBOUND, 8+4 );
    data << uint64(_player->GetGUID());
    data << uint32(zone_id);
    SendPacket( &data );

    _player->PlayerTalkClass->CloseGossip();
}

void WorldSession::HandleListStabledPetsOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    sLog.outDebug("WORLD: Recv MSG_LIST_STABLED_PETS");
    uint64 npcGUID;

    recv_data >> npcGUID;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleListStabledPetsOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // remove mounts this fix bug where getting pet from stable while mounted deletes pet.
    if(GetPlayer()->IsMounted())
        GetPlayer()->RemoveAurasByType(SPELL_AURA_MOUNTED);

    SendStablePet(npcGUID);
}

void WorldSession::SendStablePet(uint64 guid )
{
    sLog.outDebug("WORLD: Recv MSG_LIST_STABLED_PETS Send.");

    WorldPacket data(MSG_LIST_STABLED_PETS, 200);           // guess size
    data << uint64 ( guid );

    Pet *pet = _player->GetPet();

    size_t wpos = data.wpos();
    data << uint8(0);                                       // place holder for slot show number

    data << uint8(GetPlayer()->m_stableSlots);

    uint8 num = 0;                                          // counter for place holder

    // not let move dead pet in slot
    if(pet && pet->isAlive() && pet->getPetType()==HUNTER_PET)
    {
        data << uint32(pet->GetCharmInfo()->GetPetNumber());
        data << uint32(pet->GetEntry());
        data << uint32(pet->getLevel());
        data << pet->GetName();                             // petname
        data << uint8(1);                                   // 1 = current, 2/3 = in stable (any from 4,5,... create problems with proper show)
        ++num;
    }

    //                                                     0      1   2      3      4
    QueryResult* result = CharacterDatabase.PQuery("SELECT owner, id, entry, level, name FROM character_pet WHERE owner = '%u' AND slot >= '%u' AND slot <= '%u' ORDER BY slot",
        _player->GetGUIDLow(),PET_SAVE_FIRST_STABLE_SLOT,PET_SAVE_LAST_STABLE_SLOT);

    if(result)
    {
        do
        {
            Field *fields = result->Fetch();

            data << uint32(fields[1].GetUInt32());          // petnumber
            data << uint32(fields[2].GetUInt32());          // creature entry
            data << uint32(fields[3].GetUInt32());          // level
            data << fields[4].GetString();                  // name
            data << uint8(2);                               // 1 = current, 2/3 = in stable (any from 4,5,... create problems with proper show)

            ++num;
        }while( result->NextRow() );

        delete result;
    }

    data.put<uint8>(wpos, num);                             // set real data to placeholder
    SendPacket(&data);
}

void WorldSession::HandleStablePet( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    sLog.outDebug("WORLD: Recv CMSG_STABLE_PET");
    uint64 npcGUID;

    recv_data >> npcGUID;

    if(!GetPlayer()->isAlive())
        return;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleStablePet - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Pet *pet = _player->GetPet();

    WorldPacket data(SMSG_STABLE_RESULT, 200);              // guess size

    // can't place in stable dead pet
    if(!pet||!pet->isAlive()||pet->getPetType()!=HUNTER_PET)
    {
        data << uint8(0x06);
        SendPacket(&data);
        return;
    }

    uint32 free_slot = 1;

    QueryResult *result = CharacterDatabase.PQuery("SELECT owner,slot,id FROM character_pet WHERE owner = '%u'  AND slot >= '%u' AND slot <= '%u' ORDER BY slot ",
        _player->GetGUIDLow(),PET_SAVE_FIRST_STABLE_SLOT,PET_SAVE_LAST_STABLE_SLOT);
    if(result)
    {
        do
        {
            Field *fields = result->Fetch();

            uint32 slot = fields[1].GetUInt32();

            // slots ordered in query, and if not equal then free
            if(slot!=free_slot)
                break;

            // this slot not free, skip
            ++free_slot;
        }while( result->NextRow() );

        delete result;
    }

    if( free_slot > 0 && free_slot <= GetPlayer()->m_stableSlots)
    {
        _player->RemovePet(pet,PetSaveMode(free_slot));
        data << uint8(0x08);
    }
    else
        data << uint8(0x06);

    SendPacket(&data);
}

void WorldSession::HandleUnstablePet( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+4);

    sLog.outDebug("WORLD: Recv CMSG_UNSTABLE_PET.");
    uint64 npcGUID;
    uint32 petnumber;

    recv_data >> npcGUID >> petnumber;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleUnstablePet - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    WorldPacket data(SMSG_STABLE_RESULT, 200);              // guess size

    Pet* pet = _player->GetPet();
    if(pet && pet->isAlive())
    {
        data << uint8(0x06);
        SendPacket(&data);
        return;
    }

    // delete dead pet
    if(pet)
        _player->RemovePet(pet,PET_SAVE_AS_DELETED);

    Pet *newpet = NULL;

    QueryResult *result = CharacterDatabase.PQuery("SELECT entry FROM character_pet WHERE owner = '%u' AND id = '%u' AND slot >='%u' AND slot <= '%u'",
        _player->GetGUIDLow(),petnumber,PET_SAVE_FIRST_STABLE_SLOT,PET_SAVE_LAST_STABLE_SLOT);
    if(result)
    {
        Field *fields = result->Fetch();
        uint32 petentry = fields[0].GetUInt32();

        newpet = new Pet(_player, HUNTER_PET);
        if(!newpet->LoadPetFromDB(_player,petentry,petnumber))
        {
            delete newpet;
            newpet = NULL;
        }
        delete result;
    }

    if(newpet)
        data << uint8(0x09);
    else
        data << uint8(0x06);
    SendPacket(&data);
}

void WorldSession::HandleBuyStableSlot( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    sLog.outDebug("WORLD: Recv CMSG_BUY_STABLE_SLOT.");
    uint64 npcGUID;

    recv_data >> npcGUID;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleBuyStableSlot - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    WorldPacket data(SMSG_STABLE_RESULT, 200);

    if(GetPlayer()->m_stableSlots < MAX_PET_STABLES)
    {
        StableSlotPricesEntry const *SlotPrice = sStableSlotPricesStore.LookupEntry(GetPlayer()->m_stableSlots+1);
        if(_player->GetMoney() >= SlotPrice->Price)
        {
            ++GetPlayer()->m_stableSlots;
            _player->ModifyMoney(-int32(SlotPrice->Price));
            data << uint8(0x0A);                            // success buy
        }
        else
            data << uint8(0x06);
    }
    else
        data << uint8(0x06);

    SendPacket(&data);
}

void WorldSession::HandleStableRevivePet( WorldPacket &/* recv_data */)
{
    sLog.outDebug("HandleStableRevivePet: Not implemented");
}

void WorldSession::HandleStableSwapPet( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+4);

    sLog.outDebug("WORLD: Recv CMSG_STABLE_SWAP_PET.");
    uint64 npcGUID;
    uint32 pet_number;

    recv_data >> npcGUID >> pet_number;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_STABLEMASTER);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleStableSwapPet - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    WorldPacket data(SMSG_STABLE_RESULT, 200);              // guess size

    Pet* pet = _player->GetPet();

    if(!pet || pet->getPetType()!=HUNTER_PET)
        return;

    // find swapped pet slot in stable
    QueryResult *result = CharacterDatabase.PQuery("SELECT slot,entry FROM character_pet WHERE owner = '%u' AND id = '%u'",
        _player->GetGUIDLow(),pet_number);
    if(!result)
        return;

    Field *fields = result->Fetch();

    uint32 slot     = fields[0].GetUInt32();
    uint32 petentry = fields[1].GetUInt32();
    delete result;

    // move alive pet to slot or delete dead pet
    _player->RemovePet(pet,pet->isAlive() ? PetSaveMode(slot) : PET_SAVE_AS_DELETED);

    // summon unstabled pet
    Pet *newpet = new Pet(_player);
    if(!newpet->LoadPetFromDB(_player,petentry,pet_number))
    {
        delete newpet;
        data << uint8(0x06);
    }
    else
        data << uint8(0x09);

    SendPacket(&data);
}

void WorldSession::HandleRepairItemOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+8+1);

    sLog.outDebug("WORLD: CMSG_REPAIR_ITEM");

    uint64 npcGUID, itemGUID;
    uint8 guildBank;                                        // new in 2.3.2, bool that means from guild bank money

    recv_data >> npcGUID >> itemGUID >> guildBank;

    Creature *unit = GetPlayer()->GetNPCIfCanInteractWith(npcGUID, UNIT_NPC_FLAG_REPAIR);
    if (!unit)
    {
        sLog.outDebug( "WORLD: HandleRepairItemOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(npcGUID)) );
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // reputation discount
    float discountMod = _player->GetReputationPriceDiscount(unit);

    uint32 TotalCost = 0;
    if (itemGUID)
    {
        sLog.outDebug("ITEM: Repair item, itemGUID = %u, npcGUID = %u", GUID_LOPART(itemGUID), GUID_LOPART(npcGUID));

        Item* item = _player->GetItemByGuid(itemGUID);

        if(item)
            TotalCost= _player->DurabilityRepair(item->GetPos(),true,discountMod,guildBank>0?true:false);
    }
    else
    {
        sLog.outDebug("ITEM: Repair all items, npcGUID = %u", GUID_LOPART(npcGUID));

        TotalCost = _player->DurabilityRepairAll(true,discountMod,guildBank>0?true:false);
    }
    if (guildBank)
    {
        uint32 GuildId = _player->GetGuildId();
        if (!GuildId)
            return;
        Guild *pGuild = objmgr.GetGuildById(GuildId);
        if (!pGuild)
            return;
        pGuild->LogBankEvent(GUILD_BANK_LOG_REPAIR_MONEY, 0, _player->GetGUIDLow(), TotalCost);
        pGuild->SendMoneyInfo(this, _player->GetGUIDLow());
    }
}

