/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Spell.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "Util.h"
#include "Pet.h"
#include "World.h"
#include "Group.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "Player.h"
#include "SpellPackets.h"
#include "QueryPackets.h"

void WorldSession::HandleDismissCritter(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_DISMISS_CRITTER for %s", guid.ToString().c_str());

    Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if (!pet)
    {
        TC_LOG_DEBUG("network", "Vanitypet (%s) does not exist - player '%s' (%s / account: %u) attempted to dismiss it (possibly lagged out)",
            guid.ToString().c_str(), GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetAccountId());
        return;
    }

    if (_player->GetCritterGUID() == pet->GetGUID())
    {
         if (pet->GetTypeId() == TYPEID_UNIT && pet->ToCreature()->IsSummon())
             pet->ToTempSummon()->UnSummon();
    }
}

void WorldSession::HandlePetAction(WorldPacket& recvData)
{
    ObjectGuid guid1;
    uint32 data;
    ObjectGuid guid2;
    float x, y, z;
    recvData >> guid1;                                     //pet guid
    recvData >> data;
    recvData >> guid2;                                     //tag guid
    // Position
    recvData >> x;
    recvData >> y;
    recvData >> z;

    uint32 spellid = UNIT_ACTION_BUTTON_ACTION(data);
    uint8 flag = UNIT_ACTION_BUTTON_TYPE(data);             //delete = 0x07 CastSpell = C1

    // used also for charmed creature
    Unit* pet = ObjectAccessor::GetUnit(*_player, guid1);
    TC_LOG_DEBUG("network", "HandlePetAction: %s - flag: %u, spellid: %u, target: %s.", guid1.ToString().c_str(), uint32(flag), spellid, guid2.ToString().c_str());

    if (!pet)
    {
        TC_LOG_DEBUG("network", "HandlePetAction: %s doesn't exist for %s %s", guid1.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (pet != GetPlayer()->GetFirstControlled())
    {
        TC_LOG_DEBUG("network", "HandlePetAction: %s does not belong to %s %s", guid1.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (!pet->IsAlive())
    {
        SpellInfo const* spell = (flag == ACT_ENABLED || flag == ACT_PASSIVE) ? sSpellMgr->GetSpellInfo(spellid) : NULL;
        if (!spell)
            return;
        if (!spell->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_DEAD))
            return;
    }

    /// @todo allow control charmed player?
    if (pet->GetTypeId() == TYPEID_PLAYER && !(flag == ACT_COMMAND && spellid == COMMAND_ATTACK))
        return;

    if (GetPlayer()->m_Controlled.size() == 1)
        HandlePetActionHelper(pet, guid1, spellid, flag, guid2, x, y, z);
    else
    {
        //If a pet is dismissed, m_Controlled will change
        std::vector<Unit*> controlled;
        for (Unit::ControlList::iterator itr = GetPlayer()->m_Controlled.begin(); itr != GetPlayer()->m_Controlled.end(); ++itr)
            if ((*itr)->GetEntry() == pet->GetEntry() && (*itr)->IsAlive())
                controlled.push_back(*itr);
        for (std::vector<Unit*>::iterator itr = controlled.begin(); itr != controlled.end(); ++itr)
            HandlePetActionHelper(*itr, guid1, spellid, flag, guid2, x, y, z);
    }
}

void WorldSession::HandlePetStopAttack(WorldPacket &recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_PET_STOP_ATTACK for %s", guid.ToString().c_str());

    Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if (!pet)
    {
        TC_LOG_ERROR("network", "HandlePetStopAttack: %s does not exist", guid.ToString().c_str());
        return;
    }

    if (pet != GetPlayer()->GetPet() && pet != GetPlayer()->GetCharm())
    {
        TC_LOG_ERROR("network", "HandlePetStopAttack: %s isn't a pet or charmed creature of player %s",
            guid.ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    if (!pet->IsAlive())
        return;

    pet->AttackStop();
}

void WorldSession::HandlePetActionHelper(Unit* pet, ObjectGuid guid1, uint32 spellid, uint16 flag, ObjectGuid guid2, float x, float y, float z)
{
    CharmInfo* charmInfo = pet->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandlePetAction(petGuid: %s, tagGuid: %s, spellId: %u, flag: %u): object (%s Entry: %u TypeId: %u) is considered pet-like but doesn't have a charminfo!",
            guid1.ToString().c_str(), guid2.ToString().c_str(), spellid, flag, pet->GetGUID().ToString().c_str(), pet->GetEntry(), pet->GetTypeId());
        return;
    }

    switch (flag)
    {
        case ACT_COMMAND:                                   //0x07
            switch (spellid)
            {
                case COMMAND_STAY:                          //flat=1792  //STAY
                    pet->StopMoving();
                    pet->GetMotionMaster()->Clear(false);
                    pet->GetMotionMaster()->MoveIdle();
                    charmInfo->SetCommandState(COMMAND_STAY);

                    charmInfo->SetIsCommandAttack(false);
                    charmInfo->SetIsAtStay(true);
                    charmInfo->SetIsCommandFollow(false);
                    charmInfo->SetIsFollowing(false);
                    charmInfo->SetIsReturning(false);
                    charmInfo->SaveStayPosition();
                    break;
                case COMMAND_FOLLOW:                        //spellid=1792  //FOLLOW
                    pet->AttackStop();
                    pet->InterruptNonMeleeSpells(false);
                    pet->GetMotionMaster()->MoveFollow(_player, PET_FOLLOW_DIST, pet->GetFollowAngle());
                    charmInfo->SetCommandState(COMMAND_FOLLOW);

                    charmInfo->SetIsCommandAttack(false);
                    charmInfo->SetIsAtStay(false);
                    charmInfo->SetIsReturning(true);
                    charmInfo->SetIsCommandFollow(true);
                    charmInfo->SetIsFollowing(false);
                    break;
                case COMMAND_ATTACK:                        //spellid=1792  //ATTACK
                {
                    // Can't attack if owner is pacified
                    if (_player->HasAuraType(SPELL_AURA_MOD_PACIFY))
                    {
                        //pet->SendPetCastFail(spellid, SPELL_FAILED_PACIFIED);
                        /// @todo Send proper error message to client
                        return;
                    }

                    // only place where pet can be player
                    Unit* TargetUnit = ObjectAccessor::GetUnit(*_player, guid2);
                    if (!TargetUnit)
                        return;

                    if (Unit* owner = pet->GetOwner())
                        if (!owner->IsValidAttackTarget(TargetUnit))
                            return;

                    pet->ClearUnitState(UNIT_STATE_FOLLOW);
                    // This is true if pet has no target or has target but targets differs.
                    if (pet->GetVictim() != TargetUnit || (pet->GetVictim() == TargetUnit && !pet->GetCharmInfo()->IsCommandAttack()))
                    {
                        if (pet->GetVictim())
                            pet->AttackStop();

                        if (pet->GetTypeId() != TYPEID_PLAYER && pet->ToCreature()->IsAIEnabled)
                        {
                            charmInfo->SetIsCommandAttack(true);
                            charmInfo->SetIsAtStay(false);
                            charmInfo->SetIsFollowing(false);
                            charmInfo->SetIsCommandFollow(false);
                            charmInfo->SetIsReturning(false);

                            pet->ToCreature()->AI()->AttackStart(TargetUnit);

                            //10% chance to play special pet attack talk, else growl
                            if (pet->ToCreature()->IsPet() && ((Pet*)pet)->getPetType() == SUMMON_PET && pet != TargetUnit && urand(0, 100) < 10)
                                pet->SendPetTalk((uint32)PET_TALK_ATTACK);
                            else
                            {
                                // 90% chance for pet and 100% chance for charmed creature
                                pet->SendPetAIReaction(guid1);
                            }
                        }
                        else                                // charmed player
                        {
                            if (pet->GetVictim() && pet->GetVictim() != TargetUnit)
                                pet->AttackStop();

                            charmInfo->SetIsCommandAttack(true);
                            charmInfo->SetIsAtStay(false);
                            charmInfo->SetIsFollowing(false);
                            charmInfo->SetIsCommandFollow(false);
                            charmInfo->SetIsReturning(false);

                            pet->Attack(TargetUnit, true);
                            pet->SendPetAIReaction(guid1);
                        }
                    }
                    break;
                }
                case COMMAND_ABANDON:                       // abandon (hunter pet) or dismiss (summoned pet)
                    if (pet->GetCharmerGUID() == GetPlayer()->GetGUID())
                        _player->StopCastingCharm();
                    else if (pet->GetOwnerGUID() == GetPlayer()->GetGUID())
                    {
                        ASSERT(pet->GetTypeId() == TYPEID_UNIT);
                        if (pet->IsPet())
                        {
                            if (((Pet*)pet)->getPetType() == HUNTER_PET)
                                GetPlayer()->RemovePet((Pet*)pet, PET_SAVE_AS_DELETED);
                            else
                                //dismissing a summoned pet is like killing them (this prevents returning a soulshard...)
                                pet->setDeathState(CORPSE);
                        }
                        else if (pet->HasUnitTypeMask(UNIT_MASK_MINION))
                        {
                            ((Minion*)pet)->UnSummon();
                        }
                    }
                    break;
                case COMMAND_MOVE_TO:
                    pet->StopMoving();
                    pet->GetMotionMaster()->Clear(false);
                    pet->GetMotionMaster()->MovePoint(0, x, y, z);
                    charmInfo->SetCommandState(COMMAND_MOVE_TO);

                    charmInfo->SetIsCommandAttack(false);
                    charmInfo->SetIsAtStay(true);
                    charmInfo->SetIsFollowing(false);
                    charmInfo->SetIsReturning(false);
                    charmInfo->SaveStayPosition();
                    break;
                default:
                    TC_LOG_ERROR("network", "WORLD: unknown PET flag Action %i and spellid %i.", uint32(flag), spellid);
            }
            break;
        case ACT_REACTION:                                  // 0x6
            switch (spellid)
            {
                case REACT_PASSIVE:                         //passive
                    pet->AttackStop();
                    // no break;
                case REACT_DEFENSIVE:                       //recovery
                case REACT_AGGRESSIVE:                      //activete
                    if (pet->GetTypeId() == TYPEID_UNIT)
                        pet->ToCreature()->SetReactState(ReactStates(spellid));
                    break;
            }
            break;
        case ACT_DISABLED:                                  // 0x81    spell (disabled), ignore
        case ACT_PASSIVE:                                   // 0x01
        case ACT_ENABLED:                                   // 0xC1    spell
        {
            Unit* unit_target = NULL;

            if (!guid2.IsEmpty())
                unit_target = ObjectAccessor::GetUnit(*_player, guid2);

            // do not cast unknown spells
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellid);
            if (!spellInfo)
            {
                TC_LOG_ERROR("network", "WORLD: unknown PET spell id %i", spellid);
                return;
            }

            for (SpellEffectInfo const* effect: spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            {
                if (effect && (effect->TargetA.GetTarget() == TARGET_UNIT_SRC_AREA_ENEMY || effect->TargetA.GetTarget() == TARGET_UNIT_DEST_AREA_ENEMY || effect->TargetA.GetTarget() == TARGET_DEST_DYNOBJ_ENEMY))
                    return;
            }

            // do not cast not learned spells
            if (!pet->HasSpell(spellid) || spellInfo->IsPassive())
                return;

            //  Clear the flags as if owner clicked 'attack'. AI will reset them
            //  after AttackStart, even if spell failed
            if (pet->GetCharmInfo())
            {
                pet->GetCharmInfo()->SetIsAtStay(false);
                pet->GetCharmInfo()->SetIsCommandAttack(true);
                pet->GetCharmInfo()->SetIsReturning(false);
                pet->GetCharmInfo()->SetIsFollowing(false);
            }

            Spell* spell = new Spell(pet, spellInfo, TRIGGERED_NONE);

            SpellCastResult result = spell->CheckPetCast(unit_target);

            //auto turn to target unless possessed
            if (result == SPELL_FAILED_UNIT_NOT_INFRONT && !pet->isPossessed() && !pet->IsVehicle())
            {
                if (unit_target)
                {
                    pet->SetInFront(unit_target);
                    if (Player* player = unit_target->ToPlayer())
                        pet->SendUpdateToPlayer(player);
                }
                else if (Unit* unit_target2 = spell->m_targets.GetUnitTarget())
                {
                    pet->SetInFront(unit_target2);
                    if (Player* player = unit_target2->ToPlayer())
                        pet->SendUpdateToPlayer(player);
                }

                if (Unit* powner = pet->GetCharmerOrOwner())
                    if (Player* player = powner->ToPlayer())
                        pet->SendUpdateToPlayer(player);

                result = SPELL_CAST_OK;
            }

            if (result == SPELL_CAST_OK)
            {
                unit_target = spell->m_targets.GetUnitTarget();

                //10% chance to play special pet attack talk, else growl
                //actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
                if (pet->ToCreature()->IsPet() && (((Pet*)pet)->getPetType() == SUMMON_PET) && (pet != unit_target) && (urand(0, 100) < 10))
                    pet->SendPetTalk((uint32)PET_TALK_SPECIAL_SPELL);
                else
                {
                    pet->SendPetAIReaction(guid1);
                }

                if (unit_target && !GetPlayer()->IsFriendlyTo(unit_target) && !pet->isPossessed() && !pet->IsVehicle())
                {
                    // This is true if pet has no target or has target but targets differs.
                    if (pet->GetVictim() != unit_target)
                    {
                        if (pet->GetVictim())
                            pet->AttackStop();
                        pet->GetMotionMaster()->Clear();
                        if (pet->ToCreature()->IsAIEnabled)
                            pet->ToCreature()->AI()->AttackStart(unit_target);
                    }
                }

                spell->prepare(&(spell->m_targets));
            }
            else
            {
                if (pet->isPossessed() || pet->IsVehicle()) /// @todo: confirm this check
                    Spell::SendCastResult(GetPlayer(), spellInfo, 0, result);
                else
                    spell->SendPetCastResult(result);

                if (!pet->GetSpellHistory()->HasCooldown(spellid))
                    pet->GetSpellHistory()->ResetCooldown(spellid, true);

                spell->finish(false);
                delete spell;

                // reset specific flags in case of spell fail. AI will reset other flags
                if (pet->GetCharmInfo())
                    pet->GetCharmInfo()->SetIsCommandAttack(false);
            }
            break;
        }
        default:
            TC_LOG_ERROR("network", "WORLD: unknown PET flag Action %i and spellid %i.", uint32(flag), spellid);
    }
}

void WorldSession::HandleQueryPetName(WorldPackets::Query::QueryPetName& packet)
{
    SendQueryPetNameResponse(packet.UnitGUID);
}

void WorldSession::SendQueryPetNameResponse(ObjectGuid guid)
{
    WorldPackets::Query::QueryPetNameResponse response;

    response.UnitGUID = guid;

    if (Creature* unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid))
    {
        response.Allow = true;
        response.Timestamp = unit->GetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP);
        response.Name = unit->GetName();

        if (Pet* pet = unit->ToPet())
        {
            if (DeclinedName const* names = pet->GetDeclinedNames()) 
            {
                response.HasDeclined = true;
                response.DeclinedNames = *names;
            }
        }
    }

    _player->GetSession()->SendPacket(response.Write());
}

bool WorldSession::CheckStableMaster(ObjectGuid guid)
{
    // spell case or GM
    if (guid == GetPlayer()->GetGUID())
    {
        if (!GetPlayer()->IsGameMaster() && !GetPlayer()->HasAuraType(SPELL_AURA_OPEN_STABLE))
        {
            TC_LOG_DEBUG("network", "%s attempt open stable in cheating way.", guid.ToString().c_str());
            return false;
        }
    }
    // stable master case
    else
    {
        if (!GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_STABLEMASTER))
        {
            TC_LOG_DEBUG("network", "Stablemaster %s not found or you can't interact with him.", guid.ToString().c_str());
            return false;
        }
    }
    return true;
}

void WorldSession::HandlePetSetAction(WorldPacket& recvData)
{
    ObjectGuid petguid;
    uint8  count;

    recvData >> petguid;

    Unit* pet = ObjectAccessor::GetUnit(*_player, petguid);

    if (!pet || pet != _player->GetFirstControlled())
    {
        TC_LOG_ERROR("network", "HandlePetSetAction: Unknown %s or owner (%s)", petguid.ToString().c_str(), _player->GetGUID().ToString().c_str());
        return;
    }

    CharmInfo* charmInfo = pet->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_ERROR("network", "WorldSession::HandlePetSetAction: object (%s) is considered pet-like but doesn't have a charminfo!", pet->GetGUID().ToString().c_str());
        return;
    }

    count = (recvData.size() == 24) ? 2 : 1;

    uint32 position[2];
    uint32 data[2];
    bool move_command = false;

    for (uint8 i = 0; i < count; ++i)
    {
        recvData >> position[i];
        recvData >> data[i];

        uint8 act_state = UNIT_ACTION_BUTTON_TYPE(data[i]);

        //ignore invalid position
        if (position[i] >= MAX_UNIT_ACTION_BAR_INDEX)
            return;

        // in the normal case, command and reaction buttons can only be moved, not removed
        // at moving count == 2, at removing count == 1
        // ignore attempt to remove command|reaction buttons (not possible at normal case)
        if (act_state == ACT_COMMAND || act_state == ACT_REACTION)
        {
            if (count == 1)
                return;

            move_command = true;
        }
    }

    // check swap (at command->spell swap client remove spell first in another packet, so check only command move correctness)
    if (move_command)
    {
        uint8 act_state_0 = UNIT_ACTION_BUTTON_TYPE(data[0]);
        if (act_state_0 == ACT_COMMAND || act_state_0 == ACT_REACTION)
        {
            uint32 spell_id_0 = UNIT_ACTION_BUTTON_ACTION(data[0]);
            UnitActionBarEntry const* actionEntry_1 = charmInfo->GetActionBarEntry(position[1]);
            if (!actionEntry_1 || spell_id_0 != actionEntry_1->GetAction() ||
                act_state_0 != actionEntry_1->GetType())
                return;
        }

        uint8 act_state_1 = UNIT_ACTION_BUTTON_TYPE(data[1]);
        if (act_state_1 == ACT_COMMAND || act_state_1 == ACT_REACTION)
        {
            uint32 spell_id_1 = UNIT_ACTION_BUTTON_ACTION(data[1]);
            UnitActionBarEntry const* actionEntry_0 = charmInfo->GetActionBarEntry(position[0]);
            if (!actionEntry_0 || spell_id_1 != actionEntry_0->GetAction() ||
                act_state_1 != actionEntry_0->GetType())
                return;
        }
    }

    for (uint8 i = 0; i < count; ++i)
    {
        uint32 spell_id = UNIT_ACTION_BUTTON_ACTION(data[i]);
        uint8 act_state = UNIT_ACTION_BUTTON_TYPE(data[i]);

        TC_LOG_DEBUG("network", "Player %s has changed pet spell action. Position: %u, Spell: %u, State: 0x%X",
            _player->GetName().c_str(), position[i], spell_id, uint32(act_state));

        //if it's act for spell (en/disable/cast) and there is a spell given (0 = remove spell) which pet doesn't know, don't add
        if (!((act_state == ACT_ENABLED || act_state == ACT_DISABLED || act_state == ACT_PASSIVE) && spell_id && !pet->HasSpell(spell_id)))
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id))
            {
                //sign for autocast
                if (act_state == ACT_ENABLED)
                {
                    if (pet->GetTypeId() == TYPEID_UNIT && pet->ToCreature()->IsPet())
                        ((Pet*)pet)->ToggleAutocast(spellInfo, true);
                    else
                        for (Unit::ControlList::iterator itr = GetPlayer()->m_Controlled.begin(); itr != GetPlayer()->m_Controlled.end(); ++itr)
                            if ((*itr)->GetEntry() == pet->GetEntry())
                                (*itr)->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, true);
                }
                //sign for no/turn off autocast
                else if (act_state == ACT_DISABLED)
                {
                    if (pet->GetTypeId() == TYPEID_UNIT && pet->ToCreature()->IsPet())
                        ((Pet*)pet)->ToggleAutocast(spellInfo, false);
                    else
                        for (Unit::ControlList::iterator itr = GetPlayer()->m_Controlled.begin(); itr != GetPlayer()->m_Controlled.end(); ++itr)
                            if ((*itr)->GetEntry() == pet->GetEntry())
                                (*itr)->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, false);
                }
            }

            charmInfo->SetActionBar(position[i], spell_id, ActiveStates(act_state));
        }
    }
}

void WorldSession::HandlePetRename(WorldPacket& recvData)
{
    ObjectGuid petguid;
    uint8 isdeclined;

    std::string name;
    DeclinedName declinedname;

    recvData >> petguid;
    recvData >> name;
    recvData >> isdeclined;

    Pet* pet = ObjectAccessor::GetPet(*_player, petguid);
                                                            // check it!
    if (!pet || !pet->IsPet() || ((Pet*)pet)->getPetType()!= HUNTER_PET ||
        !pet->HasByteFlag(UNIT_FIELD_BYTES_2, 2, UNIT_CAN_BE_RENAMED) ||
        pet->GetOwnerGUID() != _player->GetGUID() || !pet->GetCharmInfo())
        return;

    PetNameInvalidReason res = ObjectMgr::CheckPetName(name);
    if (res != PET_NAME_SUCCESS)
    {
        SendPetNameInvalid(res, name, NULL);
        return;
    }

    if (sObjectMgr->IsReservedName(name))
    {
        SendPetNameInvalid(PET_NAME_RESERVED, name, NULL);
        return;
    }

    pet->SetName(name);

    pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_NAME);

    pet->RemoveByteFlag(UNIT_FIELD_BYTES_2, 2, UNIT_CAN_BE_RENAMED);

    if (isdeclined)
    {
        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        {
            recvData >> declinedname.name[i];
        }

        std::wstring wname;
        if (!Utf8toWStr(name, wname))
            return;

        if (!ObjectMgr::CheckDeclinedNames(wname, declinedname))
        {
            SendPetNameInvalid(PET_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME, name, &declinedname);
            return;
        }
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    if (isdeclined)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME);
        stmt->setUInt32(0, pet->GetCharmInfo()->GetPetNumber());
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_PET_DECLINEDNAME);
        stmt->setUInt32(0, pet->GetCharmInfo()->GetPetNumber());
        stmt->setUInt64(1, _player->GetGUID().GetCounter());

        for (uint8 i = 0; i < 5; i++)
            stmt->setString(i + 2, declinedname.name[i]);

        trans->Append(stmt);
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_PET_NAME);
    stmt->setString(0, name);
    stmt->setUInt64(1, _player->GetGUID().GetCounter());
    stmt->setUInt32(2, pet->GetCharmInfo()->GetPetNumber());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    pet->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(time(NULL))); // cast can't be helped
}

void WorldSession::HandlePetAbandon(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;                                      //pet guid
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_PET_ABANDON %s", guid.ToString().c_str());

    if (!_player->IsInWorld())
        return;

    // pet/charmed
    Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);
    if (pet)
    {
        if (pet->IsPet())
            _player->RemovePet((Pet*)pet, PET_SAVE_AS_DELETED);
        else if (pet->GetGUID() == _player->GetCharmGUID())
            _player->StopCastingCharm();
    }
}

void WorldSession::HandlePetSpellAutocastOpcode(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    uint32 spellid;
    uint8  state;                                           //1 for on, 0 for off
    recvPacket >> guid >> spellid >> state;

    if (!_player->GetGuardianPet() && !_player->GetCharm())
        return;

    if (ObjectAccessor::FindPlayer(guid))
        return;

    Creature* pet=ObjectAccessor::GetCreatureOrPetOrVehicle(*_player, guid);

    if (!pet || (pet != _player->GetGuardianPet() && pet != _player->GetCharm()))
    {
        TC_LOG_ERROR("network", "HandlePetSpellAutocastOpcode. %s isn't pet of player %s (%s).", guid.ToString().c_str(), GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellid);
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "WORLD: unknown PET spell id %u", spellid);
        return;
    }

    // do not add not learned spells/ passive spells
    if (!pet->HasSpell(spellid) || !spellInfo->IsAutocastable())
        return;

    CharmInfo* charmInfo = pet->GetCharmInfo();
    if (!charmInfo)
    {
        TC_LOG_ERROR("network", "WorldSession::HandlePetSpellAutocastOpcod: object (%s) is considered pet-like but doesn't have a charminfo!", pet->GetGUID().ToString().c_str());
        return;
    }

    if (pet->IsPet())
        ((Pet*)pet)->ToggleAutocast(spellInfo, state != 0);
    else
        pet->GetCharmInfo()->ToggleCreatureAutocast(spellInfo, state != 0);

    charmInfo->SetSpellAutocast(spellInfo, state != 0);
}

void WorldSession::HandlePetCastSpellOpcode(WorldPackets::Spells::PetCastSpell& petCastSpell)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(petCastSpell.Cast.SpellID);
    if (!spellInfo)
    {
        TC_LOG_ERROR("network", "WORLD: unknown PET spell id %i", petCastSpell.Cast.SpellID);
        return;
    }

    // This opcode is also sent from charmed and possessed units (players and creatures)
    if (!_player->GetGuardianPet() && !_player->GetCharm())
        return;

    Unit* caster = ObjectAccessor::GetUnit(*_player, petCastSpell.PetGUID);

    if (!caster || (caster != _player->GetGuardianPet() && caster != _player->GetCharm()))
    {
        TC_LOG_ERROR("network", "HandlePetCastSpellOpcode: %s isn't pet of player %s (%s).", petCastSpell.PetGUID.ToString().c_str(), GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    // do not cast not learned spells
    if (!caster->HasSpell(spellInfo->Id) || spellInfo->IsPassive())
        return;

    SpellCastTargets targets(caster, petCastSpell.Cast);

    caster->ClearUnitState(UNIT_STATE_FOLLOW);

    Spell* spell = new Spell(caster, spellInfo, TRIGGERED_NONE);
    spell->m_cast_count = petCastSpell.Cast.CastID;
    spell->m_misc.Data = petCastSpell.Cast.Misc;
    spell->m_targets = targets;

    SpellCastResult result = spell->CheckPetCast(NULL);
    if (result == SPELL_CAST_OK)
    {
        if (Creature* creature = caster->ToCreature())
        {
            if (Pet* pet = creature->ToPet())
            {
                // 10% chance to play special pet attack talk, else growl
                // actually this only seems to happen on special spells, fire shield for imp, torment for voidwalker, but it's stupid to check every spell
                if (pet->getPetType() == SUMMON_PET && (urand(0, 100) < 10))
                    pet->SendPetTalk(PET_TALK_SPECIAL_SPELL);
                else
                    pet->SendPetAIReaction(petCastSpell.PetGUID);
            }
        }

        spell->prepare(&targets);
    }
    else
    {
        spell->SendPetCastResult(result);

        if (!caster->GetSpellHistory()->HasCooldown(spellInfo->Id))
            caster->GetSpellHistory()->ResetCooldown(spellInfo->Id, true);

        spell->finish(false);
        delete spell;
    }
}

void WorldSession::SendPetNameInvalid(uint32 error, const std::string& name, DeclinedName *declinedName)
{
    WorldPacket data(SMSG_PET_NAME_INVALID, 4 + name.size() + 1 + 1);
    data << uint32(error);
    data << name;
    data << uint8(declinedName ? 1 : 0);
    if (declinedName)
        for (uint32 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            data << declinedName->name[i];

    SendPacket(&data);
}
