/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Spell.h"
#include "ObjectAccessor.h"
#include "MapManager.h"
#include "CreatureAI.h"
#include "Util.h"
#include "Pet.h"
#include "Language.h"

void WorldSession::HandlePetAction( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+2+2+8);

    uint64 guid1;
    uint16 spellid;
    uint16 flag;
    uint64 guid2;
    recv_data >> guid1;                                     //pet guid
    recv_data >> spellid;
    recv_data >> flag;                                      //delete = 0x0700 CastSpell = C100
    recv_data >> guid2;                                     //tag guid

    // used also for charmed creature
    Unit* pet= ObjectAccessor::GetUnit(*_player, guid1);
    sLog.outDetail("HandlePetAction.Pet %u flag is %u, spellid is %u, target %u.\n", uint32(GUID_LOPART(guid1)), flag, spellid, uint32(GUID_LOPART(guid2)) );
    if(!pet)
    {
        sLog.outError( "Pet %u not exist.\n", uint32(GUID_LOPART(guid1)) );
        return;
    }

    if(pet != GetPlayer()->GetPet() && pet != GetPlayer()->GetCharm())
    {
        sLog.outError("HandlePetAction.Pet %u isn't pet of player %s.\n", uint32(GUID_LOPART(guid1)), GetPlayer()->GetName() );
        return;
    }

    if(!pet->isAlive())
        return;

    if(pet->GetTypeId() == TYPEID_PLAYER && !(flag == ACT_COMMAND && spellid == COMMAND_ATTACK))
        return;

    CharmInfo *charmInfo = pet->GetCharmInfo();
    if(!charmInfo)
    {
        sLog.outError("WorldSession::HandlePetAction: object "I64FMTD" is considered pet-like but doesn't have a charminfo!", pet->GetGUID());
        return;
    }

    switch(flag)
    {
        case ACT_COMMAND:                                   //0x0700
            // Possessed or shared vision pets are only able to attack
            if ((pet->isPossessed() || pet->HasAuraType(SPELL_AURA_BIND_SIGHT)) && spellid != COMMAND_ATTACK)
                return;

            switch(spellid)
            {
                case COMMAND_STAY:                          //flat=1792  //STAY
                    pet->StopMoving();
                    pet->GetMotionMaster()->Clear();
                    pet->GetMotionMaster()->MoveIdle();
                    charmInfo->SetCommandState( COMMAND_STAY );
                    break;
                case COMMAND_FOLLOW:                        //spellid=1792  //FOLLOW
                    pet->AttackStop();
                    pet->GetMotionMaster()->MoveFollow(_player,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);
                    charmInfo->SetCommandState( COMMAND_FOLLOW );
                    break;
                case COMMAND_ATTACK:                        //spellid=1792  //ATTACK
                {
                    // Can't attack if owner is pacified
                    if (_player->HasAuraType(SPELL_AURA_MOD_PACIFY))
                    {
                        //pet->SendPetCastFail(spellid, SPELL_FAILED_PACIFIED);
                        //TODO: Send proper error message to client
                        return;
                    }
                    // only place where pet can be player
                    pet->clearUnitState(UNIT_STAT_FOLLOW);
                    uint64 selguid = _player->GetSelection();
                    Unit *TargetUnit = ObjectAccessor::GetUnit(*_player, selguid);
                    if(!TargetUnit)
                        return;

                    // not let attack friendly units.
                    if(GetPlayer()->IsFriendlyTo(TargetUnit))
                        return;
                    // Not let attack through obstructions
                    //if(!pet->IsWithinLOSInMap(TargetUnit))
                    //    return;

                    if(pet->GetTypeId() != TYPEID_PLAYER)
                    {
                        if (((Creature*)pet)->AI())
                            ((Creature*)pet)->AI()->AttackStart(TargetUnit);

                        //10% chance to play special pet attack talk, else growl
                        if(((Creature*)pet)->isPet() && ((Pet*)pet)->getPetType() == SUMMON_PET && pet != TargetUnit && urand(0, 100) < 10)
                            pet->SendPetTalk((uint32)PET_TALK_ATTACK);
                        else
                        {
                            // 90% chance for pet and 100% chance for charmed creature
                            pet->SendPetAIReaction(guid1);
                        }
                    }
                    else                                    // charmed player
                    {
                        if(pet->getVictim() && pet->getVictim() != TargetUnit)
                            pet->AttackStop();

                        pet->Attack(TargetUnit,true);
                        pet->SendPetAIReaction(guid1);
                    }
                    break;
                }
                case COMMAND_ABANDON:                       // abandon (hunter pet) or dismiss (summoned pet)
                    if(((Creature*)pet)->isPet())
                    {
                        Pet* p = (Pet*)pet;
                        if(p->getPetType() == HUNTER_PET)
                            _player->RemovePet(p,PET_SAVE_AS_DELETED);
                        else
                            //dismissing a summoned pet is like killing them (this prevents returning a soulshard...)
                            p->setDeathState(CORPSE);
                    }
                    else                                    // charmed or possessed
                    {
                        if (_player->isPossessing())
                            _player->RemovePossess(true);
                        else
                            _player->Uncharm();
                    }
                    break;
                default:
                    sLog.outError("WORLD: unknown PET flag Action %i and spellid %i.\n", flag, spellid);
            }
            break;
        case ACT_REACTION:                                  // 0x600
            switch(spellid)
            {
                case REACT_PASSIVE:                         //passive
                case REACT_DEFENSIVE:                       //recovery
                case REACT_AGGRESSIVE:                      //activete
                    charmInfo->SetReactState( ReactStates(spellid) );
                    break;
            }
            break;
        case ACT_DISABLED:                                  // 0x8100    spell (disabled), ignore
        case ACT_PASSIVE:                                   // 0x0100
        case ACT_ENABLED:                                   // 0xC100    spell
        {
            Unit* unit_target;
            if(guid2)
                unit_target = ObjectAccessor::GetUnit(*_player,guid2);
            else
                unit_target = NULL;

            if (((Creature*)pet)->GetGlobalCooldown() > 0)
                return;

            // do not cast unknown spells
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellid );
            if(!spellInfo)
            {
                sLog.outError("WORLD: unknown PET spell id %i\n", spellid);
                return;
            }

            for(uint32 i = 0; i < 3;i++)
            {
                if(spellInfo->EffectImplicitTargetA[i] == TARGET_ALL_ENEMY_IN_AREA || spellInfo->EffectImplicitTargetA[i] == TARGET_ALL_ENEMY_IN_AREA_INSTANT || spellInfo->EffectImplicitTargetA[i] == TARGET_ALL_ENEMY_IN_AREA_CHANNELED)
                    return;
            }

            // do not cast not learned spells
            if(!pet->HasSpell(spellid) || IsPassiveSpell(spellid))
                return;

            pet->clearUnitState(UNIT_STAT_FOLLOW);

            Spell *spell = new Spell(pet, spellInfo, false);

            int16 result = spell->PetCanCast(unit_target);

                                                            //auto turn to target unless possessed
            if(result == SPELL_FAILED_UNIT_NOT_INFRONT && !pet->isPossessed())
            {
                pet->SetInFront(unit_target);
                if( unit_target->GetTypeId() == TYPEID_PLAYER )
                    pet->SendUpdateToPlayer( (Player*)unit_target );
                if(Unit* powner = pet->GetCharmerOrOwner())
                    if(powner->GetTypeId() == TYPEID_PLAYER)
                        pet->SendUpdateToPlayer((Player*)powner);
                result = -1;
            }

            if(result == -1)
            {
                ((Creature*)pet)->AddCreatureSpellCooldown(spellid);
                if (((Creature*)pet)->isPet())
                    ((Pet*)pet)->CheckLearning(spellid);

                unit_target = spell->m_targets.getUnitTarget();

                //10% chance to play special pet attack talk, else growl
                //actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
                if(((Creature*)pet)->isPet() && (((Pet*)pet)->getPetType() == SUMMON_PET) && (pet != unit_target) && (urand(0, 100) < 10))
                    pet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
                else
                {
                    pet->SendPetAIReaction(guid1);
                }

                if( unit_target && !GetPlayer()->IsFriendlyTo(unit_target) && !pet->isPossessed())
                {
                    pet->clearUnitState(UNIT_STAT_FOLLOW);
                    if(pet->getVictim())
                        pet->AttackStop();
                    pet->GetMotionMaster()->Clear();
                    if (((Creature*)pet)->AI())
                        ((Creature*)pet)->AI()->AttackStart(unit_target);
                }

                spell->prepare(&(spell->m_targets));
            }
            else
            {
                if(pet->isPossessed())
                {
                    WorldPacket data(SMSG_CAST_FAILED, (4+1+1));
                    data << uint8(0) << uint32(spellid) << uint8(result);
                    switch (result)
                    {
                        case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
                            data << uint32(spellInfo->RequiresSpellFocus);
                            break;
                    }
                    SendPacket(&data);
                }
                else
                    pet->SendPetCastFail(spellid, result);

                if(!((Creature*)pet)->HasSpellCooldown(spellid))
                    pet->SendPetClearCooldown(spellid);

                spell->finish(false);
                delete spell;
            }
            break;
        }
        default:
            sLog.outError("WORLD: unknown PET flag Action %i and spellid %i.\n", flag, spellid);
    }
}

void WorldSession::HandlePetNameQuery( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+8);

    sLog.outDetail( "HandlePetNameQuery. CMSG_PET_NAME_QUERY\n" );

    uint32 petnumber;
    uint64 petguid;

    recv_data >> petnumber;
    recv_data >> petguid;

    SendPetNameQuery(petguid,petnumber);
}

void WorldSession::SendPetNameQuery( uint64 petguid, uint32 petnumber)
{
    Creature* pet = ObjectAccessor::GetCreatureOrPet(*_player, petguid);
    if(!pet || !pet->GetCharmInfo() || pet->GetCharmInfo()->GetPetNumber() != petnumber)
        return;

    std::string name = pet->GetName();

    WorldPacket data(SMSG_PET_NAME_QUERY_RESPONSE, (4+4+name.size()+1));
    data << uint32(petnumber);
    data << name.c_str();
    data << uint32(pet->GetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP));

    if( pet->isPet() && ((Pet*)pet)->GetDeclinedNames() )
    {
        data << uint8(1);
        for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << ((Pet*)pet)->GetDeclinedNames()->name[i];
    }
    else
        data << uint8(0);

    _player->GetSession()->SendPacket(&data);
}

void WorldSession::HandlePetSetAction( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+4+2+2);

    sLog.outDetail( "HandlePetSetAction. CMSG_PET_SET_ACTION\n" );

    uint64 petguid;
    uint32 position;
    uint16 spell_id;
    uint16 act_state;
    uint8  count;

    recv_data >> petguid;

    // FIXME: charmed case
    //Pet* pet = ObjectAccessor::Instance().GetPet(petguid);
    if(ObjectAccessor::FindPlayer(petguid))
        return;

    Creature* pet = ObjectAccessor::GetCreatureOrPet(*_player, petguid);

    if(!pet || (pet != _player->GetPet() && pet != _player->GetCharm()))
    {
        sLog.outError( "HandlePetSetAction: Unknown pet or pet owner.\n" );
        return;
    }

    CharmInfo *charmInfo = pet->GetCharmInfo();
    if(!charmInfo)
    {
        sLog.outError("WorldSession::HandlePetSetAction: object "I64FMTD" is considered pet-like but doesn't have a charminfo!", pet->GetGUID());
        return;
    }

    count = (recv_data.size() == 24) ? 2 : 1;
    for(uint8 i = 0; i < count; i++)
    {
        recv_data >> position;
        recv_data >> spell_id;
        recv_data >> act_state;

        sLog.outDetail( "Player %s has changed pet spell action. Position: %u, Spell: %u, State: 0x%X\n", _player->GetName(), position, spell_id, act_state);

                                                            //if it's act for spell (en/disable/cast) and there is a spell given (0 = remove spell) which pet doesn't know, don't add
        if(!((act_state == ACT_ENABLED || act_state == ACT_DISABLED || act_state == ACT_PASSIVE) && spell_id && !pet->HasSpell(spell_id)))
        {
            //sign for autocast
            if(act_state == ACT_ENABLED && spell_id)
            {
                if(pet->isCharmed())
                    charmInfo->ToggleCreatureAutocast(spell_id, true);
                else
                    ((Pet*)pet)->ToggleAutocast(spell_id, true);
            }
            //sign for no/turn off autocast
            else if(act_state == ACT_DISABLED && spell_id)
            {
                if(pet->isCharmed())
                    charmInfo->ToggleCreatureAutocast(spell_id, false);
                else
                    ((Pet*)pet)->ToggleAutocast(spell_id, false);
            }

            charmInfo->GetActionBarEntry(position)->Type = act_state;
            charmInfo->GetActionBarEntry(position)->SpellOrAction = spell_id;
        }
    }
}

void WorldSession::HandlePetRename( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+1);

    sLog.outDetail( "HandlePetRename. CMSG_PET_RENAME\n" );

    uint64 petguid;
    uint8 isdeclined;

    std::string name;
    DeclinedName declinedname;

    recv_data >> petguid;
    recv_data >> name;
    CHECK_PACKET_SIZE(recv_data, recv_data.rpos() + 1);
    recv_data >> isdeclined;

    Pet* pet = ObjectAccessor::GetPet(petguid);
                                                            // check it!
    if( !pet || !pet->isPet() || ((Pet*)pet)->getPetType()!= HUNTER_PET ||
        pet->GetByteValue(UNIT_FIELD_BYTES_2, 2) != UNIT_RENAME_ALLOWED ||
        pet->GetOwnerGUID() != _player->GetGUID() || !pet->GetCharmInfo() )
        return;

    if(!ObjectMgr::IsValidPetName(name))
    {
        SendPetNameInvalid(PET_NAME_INVALID, name, NULL);
        return;
    }

    if(objmgr.IsReservedName(name))
    {
        SendPetNameInvalid(PET_NAME_RESERVED, name, NULL);
        return;
    }

    pet->SetName(name);

    Unit *owner = pet->GetOwner();
    if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
        ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_NAME);

    pet->SetByteValue(UNIT_FIELD_BYTES_2, 2, UNIT_RENAME_NOT_ALLOWED);

    if(isdeclined)
    {
        for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        {
            CHECK_PACKET_SIZE(recv_data, recv_data.rpos() + 1);
            recv_data >> declinedname.name[i];
        }

        std::wstring wname;
        Utf8toWStr(name, wname);
        if(!ObjectMgr::CheckDeclinedNames(GetMainPartOfName(wname,0),declinedname))
        {
            SendPetNameInvalid(PET_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME, name, &declinedname);
            return;
        }
    }

    CharacterDatabase.BeginTransaction();
    if(isdeclined)
    {
        for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            CharacterDatabase.escape_string(declinedname.name[i]);
        CharacterDatabase.PExecute("DELETE FROM character_pet_declinedname WHERE owner = '%u' AND id = '%u'", _player->GetGUIDLow(), pet->GetCharmInfo()->GetPetNumber());
        CharacterDatabase.PExecute("INSERT INTO character_pet_declinedname (id, owner, genitive, dative, accusative, instrumental, prepositional) VALUES ('%u','%u','%s','%s','%s','%s','%s')",
            pet->GetCharmInfo()->GetPetNumber(), _player->GetGUIDLow(), declinedname.name[0].c_str(), declinedname.name[1].c_str(), declinedname.name[2].c_str(), declinedname.name[3].c_str(), declinedname.name[4].c_str());
    }

    CharacterDatabase.escape_string(name);
    CharacterDatabase.PExecute("UPDATE character_pet SET name = '%s', renamed = '1' WHERE owner = '%u' AND id = '%u'", name.c_str(), _player->GetGUIDLow(), pet->GetCharmInfo()->GetPetNumber());
    CharacterDatabase.CommitTransaction();

    pet->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, time(NULL));
}

void WorldSession::HandlePetAbandon( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;
    recv_data >> guid;                                      //pet guid
    sLog.outDetail( "HandlePetAbandon. CMSG_PET_ABANDON pet guid is %u", GUID_LOPART(guid) );

    // pet/charmed
    Creature* pet = ObjectAccessor::GetCreatureOrPet(*_player, guid);
    if(pet)
    {
        if(pet->isPet())
        {
            if(pet->GetGUID() == _player->GetPetGUID())
            {
                uint32 feelty = pet->GetPower(POWER_HAPPINESS);
                pet->SetPower(POWER_HAPPINESS ,(feelty-50000) > 0 ?(feelty-50000) : 0);
            }

            _player->RemovePet((Pet*)pet,PET_SAVE_AS_DELETED);
        }
        else if(pet->GetGUID() == _player->GetCharmGUID())
        {
            if (_player->isPossessing())
                _player->RemovePossess(true);
            else
                _player->Uncharm();
        }
    }
}

void WorldSession::HandlePetUnlearnOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket,8);

    sLog.outDetail("CMSG_PET_UNLEARN");
    uint64 guid;
    recvPacket >> guid;                 // Pet guid

    Pet* pet = _player->GetPet();

    if(!pet || pet->getPetType() != HUNTER_PET || pet->m_usedTalentCount == 0)
        return;

    if(guid != pet->GetGUID())
    {
        sLog.outError( "HandlePetUnlearnOpcode.Pet %u isn't pet of player %s .\n", uint32(GUID_LOPART(guid)),GetPlayer()->GetName() );
        return;
    }

    CharmInfo *charmInfo = pet->GetCharmInfo();
    if(!charmInfo)
    {
        sLog.outError("WorldSession::HandlePetUnlearnOpcode: object "I64FMTD" is considered pet-like but doesn't have a charminfo!", pet->GetGUID());
        return;
    }
    pet->resetTalents();
}

void WorldSession::HandlePetSpellAutocastOpcode( WorldPacket& recvPacket )
{
    CHECK_PACKET_SIZE(recvPacket,8+2+2+1);

    sLog.outDetail("CMSG_PET_SPELL_AUTOCAST");
    uint64 guid;
    uint16 spellid;
    uint16 spellid2;                                        //maybe second spell, automatically toggled off when first toggled on?
    uint8  state;                                           //1 for on, 0 for off
    recvPacket >> guid >> spellid >> spellid2 >> state;

    if(!_player->GetPet() && !_player->GetCharm())
        return;

    if(ObjectAccessor::FindPlayer(guid))
        return;

    Creature* pet=ObjectAccessor::GetCreatureOrPet(*_player,guid);

    if(!pet || (pet != _player->GetPet() && pet != _player->GetCharm()))
    {
        sLog.outError( "HandlePetSpellAutocastOpcode.Pet %u isn't pet of player %s .\n", uint32(GUID_LOPART(guid)),GetPlayer()->GetName() );
        return;
    }

    // do not add not learned spells/ passive spells
    if(!pet->HasSpell(spellid) || IsPassiveSpell(spellid))
        return;

    CharmInfo *charmInfo = pet->GetCharmInfo();
    if(!charmInfo)
    {
        sLog.outError("WorldSession::HandlePetSpellAutocastOpcod: object "I64FMTD" is considered pet-like but doesn't have a charminfo!", pet->GetGUID());
        return;
    }

    if(pet->isCharmed())
                                                            //state can be used as boolean
        pet->GetCharmInfo()->ToggleCreatureAutocast(spellid, state);
    else
        ((Pet*)pet)->ToggleAutocast(spellid, state);

    for(uint8 i = 0; i < 10; ++i)
    {
        if((charmInfo->GetActionBarEntry(i)->Type == ACT_ENABLED || charmInfo->GetActionBarEntry(i)->Type == ACT_DISABLED) && spellid == charmInfo->GetActionBarEntry(i)->SpellOrAction)
            charmInfo->GetActionBarEntry(i)->Type = state ? ACT_ENABLED : ACT_DISABLED;
    }
}

void WorldSession::HandlePetCastSpellOpcode( WorldPacket& recvPacket )
{
    sLog.outDetail("WORLD: CMSG_PET_CAST_SPELL");

    CHECK_PACKET_SIZE(recvPacket,8+1+4+1);
    uint64 guid;
    uint32 spellid;
    uint8  cast_count;
    uint8  unk_flags;                                       // flags (if 0x02 - some additional data are received)

    recvPacket >> guid >> cast_count >> spellid >> unk_flags;

    sLog.outDebug("WORLD: CMSG_PET_CAST_SPELL, cast_count: %u, spellid %u, unk_flags %u", cast_count, spellid, unk_flags);

    // This opcode is also sent from charmed and possessed units (players and creatures)
    if(!_player->GetPet() && !_player->GetCharm())
        return;

    Unit* caster = ObjectAccessor::GetUnit(*_player, guid);

    if(!caster || (caster != _player->GetPet() && caster != _player->GetCharm()))
    {
        sLog.outError( "HandlePetCastSpellOpcode: Pet %u isn't pet of player %s .\n", uint32(GUID_LOPART(guid)),GetPlayer()->GetName() );
        return;
    }

    if (caster->GetTypeId() == TYPEID_UNIT && ((Creature*)caster)->GetGlobalCooldown() > 0)
        return;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellid);
    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown PET spell id %i\n", spellid);
        return;
    }

    // do not cast not learned spells
    if(!caster->HasSpell(spellid) || IsPassiveSpell(spellid))
        return;

    SpellCastTargets targets;
    if(!targets.read(&recvPacket,caster))
        return;

    caster->clearUnitState(UNIT_STAT_FOLLOW);

    Spell *spell = new Spell(caster, spellInfo, false);
    spell->m_cast_count = cast_count;                       // probably pending spell cast
    spell->m_targets = targets;

    int16 result = spell->PetCanCast(NULL);
    if(result == -1)
    {
        if(caster->GetTypeId() == TYPEID_UNIT)
        {
            Creature* pet = (Creature*)caster;
            pet->AddCreatureSpellCooldown(spellid);
            if(pet->isPet())
            {
                Pet* p = (Pet*)pet;
                p->CheckLearning(spellid);
                // 10% chance to play special pet attack talk, else growl
                // actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
                if(p->getPetType() == SUMMON_PET && (urand(0, 100) < 10))
                    pet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
                else
                    pet->SendPetAIReaction(guid);
            }
        }

        spell->prepare(&(spell->m_targets));
    }
    else
    {
        caster->SendPetCastFail(spellid, result);
        if(caster->GetTypeId() == TYPEID_PLAYER)
        {
            if(!((Player*)caster)->HasSpellCooldown(spellid))
                caster->SendPetClearCooldown(spellid);
        }
        else
        {
            if(!((Creature*)caster)->HasSpellCooldown(spellid))
                caster->SendPetClearCooldown(spellid);
        }

        spell->finish(false);
        delete spell;
    }
}

void WorldSession::SendPetNameInvalid(uint32 error, const std::string& name, DeclinedName *declinedName)
{
    WorldPacket data(SMSG_PET_NAME_INVALID, 4 + name.size() + 1 + 1);
    data << uint32(error);
    data << name;
    if(declinedName)
    {
        data << uint8(1);
        for(uint32 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << declinedName->name[i];
    }
    else
        data << uint8(0);
    SendPacket(&data);
}

void WorldSession::HandlePetLearnTalent( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_PET_LEARN_TALENT");
    recv_data.hexlike();

    CHECK_PACKET_SIZE(recv_data, 8+4+4);

    uint64 guid;
    uint32 talent_id, requested_rank;
    recv_data >> guid >> talent_id >> requested_rank;

    Pet *pet = _player->GetPet();

    if(!pet)
        return;

    if(guid != pet->GetGUID())
        return;

    uint32 CurTalentPoints =  pet->GetFreeTalentPoints();

    if(CurTalentPoints == 0)
        return;

    if (requested_rank > 4)
        return;

    TalentEntry const *talentInfo = sTalentStore.LookupEntry(talent_id);

    if(!talentInfo)
        return;

    TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);

    if(!talentTabInfo)
        return;

    CreatureInfo const *ci = pet->GetCreatureInfo();

    if(!ci)
        return;

    CreatureFamilyEntry const *pet_family = sCreatureFamilyStore.LookupEntry(ci->family);

    if(!pet_family)
        return;

    if(pet_family->petTalentType < 0)                       // not hunter pet
        return;

    // prevent learn talent for different family (cheating)
    if(!((1 << pet_family->petTalentType) & talentTabInfo->petTalentMask))
        return;

    // prevent skip talent ranks (cheating)
    if(requested_rank > 0 && !pet->HasSpell(talentInfo->RankID[requested_rank-1]))
        return;

    // Check if it requires another talent
    if (talentInfo->DependsOn > 0)
    {
        if(TalentEntry const *depTalentInfo = sTalentStore.LookupEntry(talentInfo->DependsOn))
        {
            bool hasEnoughRank = false;
            for (int i = talentInfo->DependsOnRank; i <= 4; i++)
            {
                if (depTalentInfo->RankID[i] != 0)
                    if (pet->HasSpell(depTalentInfo->RankID[i]))
                        hasEnoughRank = true;
            }
            if (!hasEnoughRank)
                return;
        }
    }

    // Find out how many points we have in this field
    uint32 spentPoints = 0;

    uint32 tTab = talentInfo->TalentTab;
    if (talentInfo->Row > 0)
    {
        unsigned int numRows = sTalentStore.GetNumRows();
        for (unsigned int i = 0; i < numRows; i++)          // Loop through all talents.
        {
            // Someday, someone needs to revamp
            const TalentEntry *tmpTalent = sTalentStore.LookupEntry(i);
            if (tmpTalent)                                  // the way talents are tracked
            {
                if (tmpTalent->TalentTab == tTab)
                {
                    for (int j = 0; j <= 4; j++)
                    {
                        if (tmpTalent->RankID[j] != 0)
                        {
                            if (pet->HasSpell(tmpTalent->RankID[j]))
                            {
                                spentPoints += j + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    // not have required min points spent in talent tree
    if(spentPoints < (talentInfo->Row * 3))
        return;

    // spell not set in talent.dbc
    uint32 spellid = talentInfo->RankID[requested_rank];
    if( spellid == 0 )
    {
        sLog.outError("Talent.dbc have for talent: %u Rank: %u spell id = 0", talent_id, requested_rank);
        return;
    }

    // already known
    if(pet->HasSpell(spellid))
        return;

    // learn! (other talent ranks will unlearned at learning)
    pet->learnSpell(spellid);
    sLog.outDetail("TalentID: %u Rank: %u Spell: %u\n", talent_id, requested_rank, spellid);
}
