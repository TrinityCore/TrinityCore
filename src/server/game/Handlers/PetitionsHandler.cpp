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
#include "Common.h"
#include "Creature.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "PetitionMgr.h"
#include "PetitionPackets.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include <sstream>

#define CHARTER_DISPLAY_ID 16161
#define GUILD_CHARTER_ITEM_ID 5863

void WorldSession::HandlePetitionBuy(WorldPackets::Petition::PetitionBuy& packet)
{
    TC_LOG_DEBUG("network", "Petitioner %s tried sell petition: title %s", packet.Unit.ToString().c_str(), packet.Title.c_str());

    // prevent cheating
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_PETITIONER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionBuyOpcode - %s not found or you can't interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    uint32 charterItemID = GUILD_CHARTER_ITEM_ID;
    uint32 cost = sWorld->getIntConfig(CONFIG_CHARTER_COST_GUILD);

    // do not let if already in guild.
    if (_player->GetGuildId())
        return;

    if (sGuildMgr->GetGuildByName(packet.Title))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_EXISTS_S, packet.Title);
        return;
    }

    if (sObjectMgr->IsReservedName(packet.Title) || !ObjectMgr::IsValidCharterName(packet.Title))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_INVALID, packet.Title);
        return;
    }

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(charterItemID);
    if (!pProto)
    {
        _player->SendBuyError(BUY_ERR_CANT_FIND_ITEM, NULL, charterItemID, 0);
        return;
    }

    if (!_player->HasEnoughMoney(uint64(cost)))
    {
        _player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, charterItemID, 0);
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, charterItemID, pProto->GetBuyCount());
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, NULL, NULL, charterItemID);
        return;
    }

    _player->ModifyMoney(-int32(cost));
    Item* charter = _player->StoreNewItem(dest, charterItemID, true);
    if (!charter)
        return;

    charter->SetPetitionId(charter->GetGUID().GetCounter());
    charter->SetState(ITEM_CHANGED, _player);
    _player->SendNewItem(charter, 1, true, false);

    // a petition is invalid, if both the owner and the type matches
    // we checked above, if this player is in an arenateam, so this must be
    // datacorruption
    if (Petition const* petition = sPetitionMgr->GetPetitionByOwner(_player->GetGUID()))
    {
        // clear from petition store
        sPetitionMgr->RemovePetition(petition->petitionGuid);
        TC_LOG_DEBUG("network", "Invalid petition GUID: %s", petition->petitionGuid.ToString().c_str());
    }

    // fill petition store
    sPetitionMgr->AddPetition(charter->GetGUID(), _player->GetGUID(), packet.Title, false);
}

void WorldSession::HandlePetitionShowSignatures(WorldPackets::Petition::PetitionShowSignatures& packet)
{
    Petition const* petition = sPetitionMgr->GetPetition(packet.Item);
    if (!petition)
    {
        TC_LOG_DEBUG("entities.player.items", "Petition %s is not found for %s %s", packet.Item.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    // if has guild => error, return;
    if (_player->GetGuildId())
        return;

    TC_LOG_DEBUG("network", "CMSG_PETITION_SHOW_SIGNATURES %s", packet.Item.ToString().c_str());

    SendPetitionSigns(petition, _player);
}

void WorldSession::SendPetitionSigns(Petition const* petition, Player* sendTo)
{
    WorldPackets::Petition::ServerPetitionShowSignatures signaturesPacket;
    signaturesPacket.Item = petition->petitionGuid;
    signaturesPacket.Owner = petition->ownerGuid;
    signaturesPacket.OwnerAccountID = ObjectGuid::Create<HighGuid::WowAccount>(sCharacterCache->GetCharacterAccountIdByGuid(petition->ownerGuid));
    signaturesPacket.PetitionID = petition->petitionGuid.GetCounter();

    for (Signature const& signature : petition->signatures)
    {
        WorldPackets::Petition::ServerPetitionShowSignatures::PetitionSignature signaturePkt;
        signaturePkt.Signer = signature.second;
        signaturePkt.Choice = 0;
        signaturesPacket.Signatures.push_back(signaturePkt);
    }

    sendTo->SendDirectMessage(signaturesPacket.Write());
}

void WorldSession::HandleQueryPetition(WorldPackets::Petition::QueryPetition& packet)
{
    TC_LOG_DEBUG("network", "Received CMSG_QUERY_PETITION Petition %s PetitionID %u", packet.ItemGUID.ToString().c_str(), packet.PetitionID);

    SendPetitionQueryOpcode(packet.ItemGUID);
}

void WorldSession::SendPetitionQueryOpcode(ObjectGuid petitionguid)
{
    WorldPackets::Petition::QueryPetitionResponse responsePacket;
    responsePacket.PetitionID = uint32(petitionguid.GetCounter());  // PetitionID (in Trinity always same as GUID_LOPART(petition guid))
    Petition const* petition = sPetitionMgr->GetPetition(petitionguid);
    if (!petition)
    {
        responsePacket.Allow = false;
        SendPacket(responsePacket.Write());

        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition (%s)", petitionguid.ToString().c_str());
        return;
    }

    uint32 reqSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);

    WorldPackets::Petition::PetitionInfo& petitionInfo = responsePacket.Info;
    petitionInfo.PetitionID = int32(petitionguid.GetCounter());
    petitionInfo.Petitioner = petition->ownerGuid;
    petitionInfo.MinSignatures = reqSignatures;
    petitionInfo.MaxSignatures = reqSignatures;
    petitionInfo.Title = petition->petitionName;

    responsePacket.Allow = true;

    SendPacket(responsePacket.Write());
}

void WorldSession::HandlePetitionRenameGuild(WorldPackets::Petition::PetitionRenameGuild& packet)
{
    Item* item = _player->GetItemByGuid(packet.PetitionGuid);
    if (!item)
        return;

    Petition* petition = sPetitionMgr->GetPetition(packet.PetitionGuid);
    if (!petition)
    {
        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition %s", packet.PetitionGuid.ToString().c_str());
        return;
    }

    if (sGuildMgr->GetGuildByName(packet.NewGuildName))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_EXISTS_S, packet.NewGuildName);
        return;
    }

    if (sObjectMgr->IsReservedName(packet.NewGuildName) || !ObjectMgr::IsValidCharterName(packet.NewGuildName))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_INVALID, packet.NewGuildName);
        return;
    }

    // update petition storage
    petition->UpdateName(packet.NewGuildName);

    WorldPackets::Petition::PetitionRenameGuildResponse renameResponse;
    renameResponse.PetitionGuid = packet.PetitionGuid;
    renameResponse.NewGuildName = packet.NewGuildName;
    SendPacket(renameResponse.Write());

    TC_LOG_DEBUG("network", "Petition %s renamed to '%s'", packet.PetitionGuid.ToString().c_str(), packet.NewGuildName.c_str());
}

void WorldSession::HandleSignPetition(WorldPackets::Petition::SignPetition& packet)
{
    Petition* petition = sPetitionMgr->GetPetition(packet.PetitionGUID);
    if (!petition)
    {
        TC_LOG_ERROR("network", "Petition %s is not found for %s %s", packet.PetitionGUID.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    ObjectGuid ownerGuid = petition->ownerGuid;
    uint64 signs = petition->signatures.size();

    if (ownerGuid == _player->GetGUID())
        return;

    // not let enemies sign guild charter
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != sCharacterCache->GetCharacterTeamByGuid(ownerGuid))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (_player->GetGuildId())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_IN_GUILD_S, _player->GetName());
        return;
    }

    if (_player->GetGuildIdInvited())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_INVITED_TO_GUILD_S, _player->GetName());
        return;
    }

    if (++signs > 10)                                          // client signs maximum
        return;

    // Client doesn't allow to sign petition two times by one character, but not check sign by another character from same account
    // not allow sign another player from already sign player account
    WorldPackets::Petition::PetitionSignResults signResult;
    signResult.Player = _player->GetGUID();
    signResult.Item = packet.PetitionGUID;

    bool isSigned = petition->IsPetitionSignedByAccount(GetAccountId());
    if (isSigned)
    {
        signResult.Error = int32(PETITION_SIGN_ALREADY_SIGNED);

        // close at signer side
        SendPacket(signResult.Write());

        // update for owner if online
        if (Player* owner = ObjectAccessor::FindConnectedPlayer(ownerGuid))
            owner->GetSession()->SendPacket(signResult.GetRawPacket());
        return;
    }

    // fill petition store
    petition->AddSignature(packet.PetitionGUID, GetAccountId(), _player->GetGUID(), false);

    TC_LOG_DEBUG("network", "PETITION SIGN: %s by player: %s (%s Account: %u)", packet.PetitionGUID.ToString().c_str(), _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), GetAccountId());

    signResult.Error = int32(PETITION_SIGN_OK);

    SendPacket(signResult.Write());

    // update signs count on charter
    if (Item* item = _player->GetItemByGuid(packet.PetitionGUID))
    {
        item->SetPetitionNumSignatures(signs);
        item->SetState(ITEM_CHANGED, _player);
    }

    // update for owner if online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(ownerGuid))
        owner->GetSession()->SendPacket(signResult.GetRawPacket());
}

void WorldSession::HandleDeclinePetition(WorldPackets::Petition::DeclinePetition& packet)
{
    TC_LOG_DEBUG("network", "Petition %s declined by %s", packet.PetitionGUID.ToString().c_str(), _player->GetGUID().ToString().c_str());

    // Disabled because packet isn't handled by the client in any way
    /*
    Petition const* petition = sPetitionMgr->GetPetition(packet.PetitionGUID);
    if (!petition)
        return;

    // petition owner online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(petition->ownerGuid))
    {
        WorldPackets::Petition::PetitionDeclined packet;
        packet.Decliner = _player->GetGUID();
        owner->GetSession()->SendPacket(packet.Write());
    }
    */
}

void WorldSession::HandleOfferPetition(WorldPackets::Petition::OfferPetition& packet)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(packet.TargetPlayer);
    if (!player)
        return;

    Petition const* petition = sPetitionMgr->GetPetition(packet.ItemGUID);
    if (!petition)
        return;

    TC_LOG_DEBUG("network", "OFFER PETITION: %s, to %s", packet.ItemGUID.ToString().c_str(), packet.TargetPlayer.ToString().c_str());

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (player->GetGuildId())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_IN_GUILD_S, _player->GetName());
        return;
    }

    if (player->GetGuildIdInvited())
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_INVITED_TO_GUILD_S, _player->GetName());
        return;
    }

    SendPetitionSigns(petition, player);
}

void WorldSession::HandleTurnInPetition(WorldPackets::Petition::TurnInPetition& packet)
{
    // Check if player really has the required petition charter
    Item* item = _player->GetItemByGuid(packet.Item);
    if (!item)
        return;

    TC_LOG_DEBUG("network", "Petition %s turned in by %s", packet.Item.ToString().c_str(), _player->GetGUID().ToString().c_str());

    Petition const* petition = sPetitionMgr->GetPetition(packet.Item);
    if (!petition)
    {
        TC_LOG_ERROR("entities.player.cheat", "Player %s (%s) tried to turn in petition (%s) that is not present in the database", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.Item.ToString().c_str());
        return;
    }

    std::string const name = petition->petitionName; // we need a copy, Guild::AddMember invalidates petition

    // Only the petition owner can turn in the petition
    if (_player->GetGUID() != petition->ownerGuid)
        return;

    // Check if player is already in a guild
    if (_player->GetGuildId())
    {
        WorldPackets::Petition::TurnInPetitionResult resultPacket;
        resultPacket.Result = int32(PETITION_TURN_ALREADY_IN_GUILD);
        SendPacket(resultPacket.Write());
        return;
    }

    // Check if guild name is already taken
    if (sGuildMgr->GetGuildByName(name))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_EXISTS_S, name);
        return;
    }

    SignaturesVector const signatures = petition->signatures; // we need a copy, Guild::AddMember invalidates petition
    uint32 requiredSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);

    // Notify player if signatures are missing
    if (signatures.size() < requiredSignatures)
    {
        WorldPackets::Petition::TurnInPetitionResult resultPacket;
        resultPacket.Result = int32(PETITION_TURN_NEED_MORE_SIGNATURES);
        SendPacket(resultPacket.Write());
        return;
    }

    // Proceed with guild creation

    // Delete charter item
    _player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

    // Create guild
    Guild* guild = new Guild;

    if (!guild->Create(_player, name))
    {
        delete guild;
        return;
    }

    // Register guild and add guild master
    sGuildMgr->AddGuild(guild);

    Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_COMMAND_SUCCESS, name);

    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        // Add members from signatures
        for (Signature const& signature : signatures)
            guild->AddMember(trans, signature.second);

        CharacterDatabase.CommitTransaction(trans);
    }

    sPetitionMgr->RemovePetition(packet.Item);

    // created
    TC_LOG_DEBUG("network", "Player %s (%s) turning in petition %s", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.Item.ToString().c_str());

    WorldPackets::Petition::TurnInPetitionResult resultPacket;
    resultPacket.Result = int32(PETITION_TURN_OK);
    SendPacket(resultPacket.Write());
}

void WorldSession::HandlePetitionShowList(WorldPackets::Petition::PetitionShowList& packet)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.PetitionUnit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.PetitionUnit))
            creature->SendMirrorSound(_player, 0);
#endif
    SendPetitionShowList(packet.PetitionUnit);
}

void WorldSession::SendPetitionShowList(ObjectGuid guid)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_PETITIONER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionShowListOpcode - %s not found or you can't interact with him.", guid.ToString().c_str());
        return;
    }

    WorldPackets::Petition::ServerPetitionShowList packet;
    packet.Unit = guid;
    packet.Price = uint32(sWorld->getIntConfig(CONFIG_CHARTER_COST_GUILD));
    SendPacket(packet.Write());

    TC_LOG_DEBUG("network", "Sent SMSG_PETITION_SHOW_LIST");
}
