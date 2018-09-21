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
#include "Common.h"
#include "DatabaseEnv.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
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
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_PETITIONER);
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

    charter->SetUInt32Value(ITEM_FIELD_ENCHANTMENT, charter->GetGUID().GetCounter());
    // ITEM_FIELD_ENCHANTMENT_1_1 is guild/arenateam id
    // ITEM_FIELD_ENCHANTMENT_1_1+1 is current signatures count (showed on item)
    charter->SetState(ITEM_CHANGED, _player);
    _player->SendNewItem(charter, 1, true, false);

    // a petition is invalid, if both the owner and the type matches
    // we checked above, if this player is in an arenateam, so this must be
    // datacorruption
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_BY_OWNER);
    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    std::ostringstream ssInvalidPetitionGUIDs;

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            ssInvalidPetitionGUIDs << '\'' << fields[0].GetUInt64() << "', ";
        } while (result->NextRow());
    }

    // delete petitions with the same guid as this one
    ssInvalidPetitionGUIDs << '\'' << charter->GetGUID().GetCounter() << '\'';

    TC_LOG_DEBUG("network", "Invalid petition GUIDs: %s", ssInvalidPetitionGUIDs.str().c_str());
    CharacterDatabase.EscapeString(packet.Title);
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM petition WHERE petitionguid IN (%s)",  ssInvalidPetitionGUIDs.str().c_str());
    trans->PAppend("DELETE FROM petition_sign WHERE petitionguid IN (%s)", ssInvalidPetitionGUIDs.str().c_str());

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PETITION);
    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt64(1, charter->GetGUID().GetCounter());
    stmt->setString(2, packet.Title);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandlePetitionShowSignatures(WorldPackets::Petition::PetitionShowSignatures& packet)
{
    uint8 signs = 0;

    // if has guild => error, return;
    if (_player->GetGuildId())
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIGNATURE);

    stmt->setUInt64(0, packet.Item.GetCounter());

    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    // result == NULL also correct in case no sign yet
    if (result)
        signs = uint8(result->GetRowCount());

    TC_LOG_DEBUG("network", "CMSG_PETITION_SHOW_SIGNATURES %s", packet.Item.ToString().c_str());

    WorldPackets::Petition::ServerPetitionShowSignatures signaturesPacket;
    signaturesPacket.Item = packet.Item;
    signaturesPacket.Owner = _player->GetGUID();
    signaturesPacket.OwnerAccountID = ObjectGuid::Create<HighGuid::WowAccount>(ObjectMgr::GetPlayerAccountIdByGUID(_player->GetGUID()));
    signaturesPacket.PetitionID = int32(packet.Item.GetCounter());  // @todo verify that...

    signaturesPacket.Signatures.reserve(signs);
    for (uint8 i = 1; i <= signs; ++i)
    {
        Field* fields2 = result->Fetch();
        ObjectGuid signerGUID = ObjectGuid::Create<HighGuid::Player>(fields2[0].GetUInt64());

        WorldPackets::Petition::ServerPetitionShowSignatures::PetitionSignature signature;
        signature.Signer = signerGUID;
        signature.Choice = 0;
        signaturesPacket.Signatures.push_back(signature);

        // Checking the return value just to be double safe
        if (!result->NextRow())
            break;
    }

    SendPacket(signaturesPacket.Write());
}

void WorldSession::HandleQueryPetition(WorldPackets::Petition::QueryPetition& packet)
{
    TC_LOG_DEBUG("network", "Received CMSG_QUERY_PETITION Petition %s PetitionID %u", packet.ItemGUID.ToString().c_str(), packet.PetitionID);

    SendPetitionQueryOpcode(packet.ItemGUID);
}

void WorldSession::SendPetitionQueryOpcode(ObjectGuid petitionGUID)
{
    ObjectGuid ownerGUID;
    std::string title = "NO_NAME_FOR_GUID";

    WorldPackets::Petition::QueryPetitionResponse responsePacket;
    responsePacket.PetitionID = uint32(petitionGUID.GetCounter());  // PetitionID (in Trinity always same as GUID_LOPART(petition guid))

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION);

    stmt->setUInt64(0, petitionGUID.GetCounter());

    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        Field* fields = result->Fetch();
        ownerGUID = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
        title     = fields[1].GetString();
    }
    else
    {
        responsePacket.Allow = false;
        SendPacket(responsePacket.Write());

        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition (%s)", petitionGUID.ToString().c_str());
        return;
    }

    int32 reqSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);

    WorldPackets::Petition::PetitionInfo petitionInfo;
    petitionInfo.PetitionID = int32(petitionGUID.GetCounter());
    petitionInfo.Petitioner = ownerGUID;
    petitionInfo.MinSignatures = reqSignatures;
    petitionInfo.MaxSignatures = reqSignatures;
    petitionInfo.Title = title;

    responsePacket.Allow = true;
    responsePacket.Info = petitionInfo;

    SendPacket(responsePacket.Write());
}

void WorldSession::HandlePetitionRenameGuild(WorldPackets::Petition::PetitionRenameGuild& packet)
{
    Item* item = _player->GetItemByGuid(packet.PetitionGuid);
    if (!item)
        return;

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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_PETITION_NAME);

    stmt->setString(0, packet.NewGuildName);
    stmt->setUInt64(1, packet.PetitionGuid.GetCounter());

    CharacterDatabase.Execute(stmt);

    WorldPackets::Petition::PetitionRenameGuildResponse renameResponse;
    renameResponse.PetitionGuid = packet.PetitionGuid;
    renameResponse.NewGuildName = packet.NewGuildName;
    SendPacket(renameResponse.Write());

    TC_LOG_DEBUG("network", "Petition %s renamed to '%s'", packet.PetitionGuid.ToString().c_str(), packet.NewGuildName.c_str());
}

void WorldSession::HandleSignPetition(WorldPackets::Petition::SignPetition& packet)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIGNATURES);

    stmt->setUInt64(0, packet.PetitionGUID.GetCounter());
    stmt->setUInt64(1, packet.PetitionGUID.GetCounter());

    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_ERROR("network", "Petition %s is not found for %s %s", packet.PetitionGUID.ToString().c_str(), GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str());
        return;
    }

    Field* fields = result->Fetch();
    ObjectGuid ownerGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    //uint64 signs = fields[1].GetUInt64();

    if (ownerGuid == _player->GetGUID())
        return;

    // not let enemies sign guild charter
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != ObjectMgr::GetPlayerTeamByGUID(ownerGuid))
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

    //if (++signs > type)                                        // client signs maximum
    //    return;

    // Client doesn't allow to sign petition two times by one character, but not check sign by another character from same account
    // not allow sign another player from already sign player account
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIG_BY_ACCOUNT);

    stmt->setUInt32(0, GetAccountId());
    stmt->setUInt64(1, packet.PetitionGUID.GetCounter());

    result = CharacterDatabase.Query(stmt);

    WorldPackets::Petition::PetitionSignResults signResult;
    signResult.Player = _player->GetGUID();
    signResult.Item = packet.PetitionGUID;

    if (result)
    {
        signResult.Error = int32(PETITION_SIGN_ALREADY_SIGNED);

        // close at signer side
        SendPacket(signResult.Write());
        return;
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PETITION_SIGNATURE);

    stmt->setUInt64(0, ownerGuid.GetCounter());
    stmt->setUInt64(1, packet.PetitionGUID.GetCounter());
    stmt->setUInt64(2, _player->GetGUID().GetCounter());
    stmt->setUInt32(3, GetAccountId());

    CharacterDatabase.Execute(stmt);

    TC_LOG_DEBUG("network", "PETITION SIGN: %s by player: %s (%s Account: %u)", packet.PetitionGUID.ToString().c_str(), _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), GetAccountId());

    signResult.Error = int32(PETITION_SIGN_OK);

    // close at signer side
    SendPacket(signResult.Write());

    // update signs count on charter, required testing...
    //Item* item = _player->GetItemByGuid(petitionguid));
    //if (item)
    //    item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1+1, signs);

    // update for owner if online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(ownerGuid))
        owner->GetSession()->SendPacket(signResult.Write());
}

void WorldSession::HandleDeclinePetition(WorldPackets::Petition::DeclinePetition& packet)
{
    TC_LOG_DEBUG("network", "Petition %s declined by %s", packet.PetitionGUID.ToString().c_str(), _player->GetGUID().ToString().c_str());

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_OWNER_BY_GUID);
    stmt->setUInt64(0, packet.PetitionGUID.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return;

    Field* fields = result->Fetch();
    ObjectGuid ownerguid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());

    Player* owner = ObjectAccessor::FindConnectedPlayer(ownerguid);
    if (owner)                                               // petition owner online
    {
        // Disabled because packet isn't handled by the client in any way
        /*
        WorldPackets::Petition::PetitionDeclined packet;
        packet.Decliner = _player->GetGUID();
        owner->GetSession()->SendPacket(packet.Write());
        */
    }
}

void WorldSession::HandleOfferPetition(WorldPackets::Petition::OfferPetition& packet)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(packet.TargetPlayer);
    if (!player)
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIGNATURE);
    stmt->setUInt64(0, packet.ItemGUID.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    uint8 signs = 0;
    // result == NULL also correct charter without signs
    if (result)
        signs = uint8(result->GetRowCount());

    WorldPackets::Petition::ServerPetitionShowSignatures signaturesPacket;
    signaturesPacket.Item = packet.ItemGUID;
    signaturesPacket.Owner = _player->GetGUID();
    signaturesPacket.OwnerAccountID = ObjectGuid::Create<HighGuid::WowAccount>(player->GetSession()->GetAccountId());
    signaturesPacket.PetitionID = int32(packet.ItemGUID.GetCounter());  // @todo verify that...

    signaturesPacket.Signatures.reserve(signs);
    for (uint8 i = 0; i < signs; ++i)
    {
        Field* fields2 = result->Fetch();
        ObjectGuid signerGUID = ObjectGuid::Create<HighGuid::Player>(fields2[0].GetUInt64());

        WorldPackets::Petition::ServerPetitionShowSignatures::PetitionSignature signature;
        signature.Signer = signerGUID;
        signature.Choice = 0;
        signaturesPacket.Signatures.push_back(signature);

        // Checking the return value just to be double safe
        if (!result->NextRow())
            break;
    }

    player->GetSession()->SendPacket(signaturesPacket.Write());
}

void WorldSession::HandleTurnInPetition(WorldPackets::Petition::TurnInPetition& packet)
{
    // Check if player really has the required petition charter
    Item* item = _player->GetItemByGuid(packet.Item);
    if (!item)
        return;

    TC_LOG_DEBUG("network", "Petition %s turned in by %s", packet.Item.ToString().c_str(), _player->GetGUID().ToString().c_str());

    // Get petition data from db
    ObjectGuid ownerguid;
    std::string name;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION);
    stmt->setUInt64(0, packet.Item.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        Field* fields = result->Fetch();
        ownerguid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
        name = fields[1].GetString();
    }
    else
    {
        TC_LOG_ERROR("entities.player.cheat", "Player %s (%s) tried to turn in petition (%s) that is not present in the database", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.Item.ToString().c_str());
        return;
    }

    // Only the petition owner can turn in the petition
    if (_player->GetGUID() != ownerguid)
        return;

    // Check if player is already in a guild
    if (_player->GetGuildId())
    {
        WorldPackets::Petition::TurnInPetitionResult resultPacket;
        resultPacket.Result = int32(PETITION_TURN_ALREADY_IN_GUILD);
        _player->GetSession()->SendPacket(resultPacket.Write());
        return;
    }

    // Check if guild name is already taken
    if (sGuildMgr->GetGuildByName(name))
    {
        Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_EXISTS_S, name);
        return;
    }

    // Get petition signatures from db
    uint8 signatures;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PETITION_SIGNATURE);
    stmt->setUInt64(0, packet.Item.GetCounter());
    result = CharacterDatabase.Query(stmt);

    if (result)
        signatures = uint8(result->GetRowCount());
    else
        signatures = 0;

    uint32 requiredSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);

    // Notify player if signatures are missing
    if (signatures < requiredSignatures)
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
        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        // Add members from signatures
        for (uint8 i = 0; i < signatures; ++i)
        {
            Field* fields = result->Fetch();
            guild->AddMember(trans, ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64()));

            // Checking the return value just to be double safe
            if (!result->NextRow())
                break;
        }

        CharacterDatabase.CommitTransaction(trans);
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_BY_GUID);
    stmt->setUInt64(0, packet.Item.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETITION_SIGNATURE_BY_GUID);
    stmt->setUInt64(0, packet.Item.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    // created
    TC_LOG_DEBUG("network", "Player %s (%s) turning in petition %s", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), packet.Item.ToString().c_str());

    WorldPackets::Petition::TurnInPetitionResult resultPacket;
    resultPacket.Result = int32(PETITION_TURN_OK);
    SendPacket(resultPacket.Write());
}

void WorldSession::HandlePetitionShowList(WorldPackets::Petition::PetitionShowList& packet)
{
    SendPetitionShowList(packet.PetitionUnit);
}

void WorldSession::SendPetitionShowList(ObjectGuid guid)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_PETITIONER);
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
