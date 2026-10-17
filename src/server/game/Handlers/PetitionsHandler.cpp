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
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "CharacterCache.h"
#include "Common.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "PetitionMgr.h"
#include "PetitionPackets.h"
#include "WorldPacket.h"
#include "World.h"

#define CHARTER_DISPLAY_ID 16161

// Charters ID in item_template
enum CharterItemIDs
{
    GUILD_CHARTER                                 = 5863,
    ARENA_TEAM_CHARTER_2v2                        = 23560,
    ARENA_TEAM_CHARTER_3v3                        = 23561,
    ARENA_TEAM_CHARTER_5v5                        = 23562
};

void WorldSession::HandlePetitionBuy(WorldPackets::Petition::PetitionBuy& packet)
{
    TC_LOG_DEBUG("network", "Petitioner {} tried sell petition: title {}", packet.Unit.ToString(), packet.Petition.Title);

    // prevent cheating
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_PETITIONER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionBuyOpcode - {} not found or you can't interact with him.", packet.Unit.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    uint32 charterid = 0;
    uint32 cost = 0;
    CharterTypes type = CHARTER_TYPE_NONE;
    if (creature->IsTabardDesigner())
    {
        // if tabard designer, then trying to buy a guild charter.
        // do not let if already in guild.
        if (_player->GetGuildId())
            return;

        charterid = GUILD_CHARTER;
        cost = sWorld->getIntConfig(CONFIG_CHARTER_COST_GUILD);
        type = GUILD_CHARTER_TYPE;
    }
    else
    {
        /// @todo find correct opcode
        if (!_player->IsMaxLevel())
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", _player->GetName(), ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
            return;
        }

        switch (packet.Petition.Muid)                                 // arenaSlot+1 as received from client (1 from 3 case)
        {
            case 1:
                charterid = ARENA_TEAM_CHARTER_2v2;
                cost = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_2v2);
                type = ARENA_TEAM_CHARTER_2v2_TYPE;
                break;
            case 2:
                charterid = ARENA_TEAM_CHARTER_3v3;
                cost = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_3v3);
                type = ARENA_TEAM_CHARTER_3v3_TYPE;
                break;
            case 3:
                charterid = ARENA_TEAM_CHARTER_5v5;
                cost = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_5v5);
                type = ARENA_TEAM_CHARTER_5v5_TYPE;
                break;
            default:
                TC_LOG_DEBUG("network", "unknown selection at buy arena petition: {}", packet.Petition.Muid);
                return;
        }

        if (_player->GetArenaTeamId(packet.Petition.Muid - 1))        // arenaSlot+1 as received from client
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, packet.Petition.Title, "", ERR_ALREADY_IN_ARENA_TEAM);
            return;
        }
    }

    if (type == GUILD_CHARTER_TYPE)
    {
        if (sGuildMgr->GetGuildByName(packet.Petition.Title))
        {
            Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_EXISTS_S, packet.Petition.Title);
            return;
        }

        if (sObjectMgr->IsReservedName(packet.Petition.Title) || !ObjectMgr::IsValidCharterName(packet.Petition.Title))
        {
            Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NAME_INVALID, packet.Petition.Title);
            return;
        }
    }
    else
    {
        if (sArenaTeamMgr->GetArenaTeamByName(packet.Petition.Title))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, packet.Petition.Title, "", ERR_ARENA_TEAM_NAME_EXISTS_S);
            return;
        }
        if (sObjectMgr->IsReservedName(packet.Petition.Title) || !ObjectMgr::IsValidCharterName(packet.Petition.Title))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, packet.Petition.Title, "", ERR_ARENA_TEAM_NAME_INVALID);
            return;
        }
    }

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(charterid);
    if (!pProto)
    {
        _player->SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, 0);
        return;
    }

    if (!_player->HasEnoughMoney(cost))
    {                                                       //player hasn't got enough money
        _player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0);
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, charterid, pProto->GetBuyCount());
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, nullptr, nullptr, charterid);
        return;
    }

    _player->ModifyMoney(-int32(cost));
    Item* charter = _player->StoreNewItem(dest, charterid, true);
    if (!charter)
        return;

    charter->SetPetitionId(charter->GetGUID().GetCounter());
    charter->SetState(ITEM_CHANGED, _player);
    _player->SendNewItem(charter, 1, true, false);

    // a petition is invalid, if both the owner and the type matches
    // we checked above, if this player is in an arenateam, so this must be
    // datacorruption
    if (Petition const* petition = sPetitionMgr->GetPetitionByOwnerWithType(_player->GetGUID(), type))
    {
        // clear from petition store
        sPetitionMgr->RemovePetition(petition->PetitionGuid);
        TC_LOG_DEBUG("network", "Invalid petition {}", petition->PetitionGuid.ToString());
    }

    // fill petition store
    sPetitionMgr->AddPetition(charter->GetGUID(), _player->GetGUID(), packet.Petition.Title, type, false);
}

void WorldSession::HandlePetitionShowSignatures(WorldPackets::Petition::PetitionShowSignatures& packet)
{
    Petition const* petition = sPetitionMgr->GetPetition(packet.Item);
    if (!petition)
    {
        TC_LOG_DEBUG("entities.player.items", "Petition {} is not found for player {} {}", packet.Item.ToString(), GetPlayer()->GetGUID().ToString(), GetPlayer()->GetName());
        return;
    }

    // if guild petition and has guild => error, return;
    if (petition->PetitionType == GUILD_CHARTER_TYPE && _player->GetGuildId())
        return;

    TC_LOG_DEBUG("network", "CMSG_PETITION_SHOW_SIGNATURES petition {}", packet.Item.ToString());

    SendPetitionSigns(petition, _player);
}

void WorldSession::SendPetitionSigns(Petition const* petition, Player* sendTo)
{
    WorldPackets::Petition::ServerPetitionShowSignatures signaturesPacket;
    signaturesPacket.Item = petition->PetitionGuid;
    signaturesPacket.Owner = petition->OwnerGuid;
    signaturesPacket.PetitionID = petition->PetitionGuid.GetCounter();

    for (Signature const& signature : petition->Signatures)
    {
        WorldPackets::Petition::ServerPetitionShowSignatures::PetitionSignature& signaturePkt = signaturesPacket.Signatures.emplace_back();
        signaturePkt.Signer = signature.second;
        signaturePkt.Choice = 0;
    }

    sendTo->SendDirectMessage(signaturesPacket.Write());
}

void WorldSession::HandleQueryPetition(WorldPackets::Petition::QueryPetition& packet)
{
    TC_LOG_DEBUG("network", "Received CMSG_QUERY_PETITION Petition {} PetitionID {}", packet.ItemGUID.ToString(), packet.PetitionID);

    SendPetitionQueryOpcode(packet.ItemGUID);
}

void WorldSession::SendPetitionQueryOpcode(ObjectGuid petitionguid)
{
    WorldPackets::Petition::QueryPetitionResponse responsePacket;
    Petition const* petition = sPetitionMgr->GetPetition(petitionguid);
    if (!petition)
    {
        responsePacket.Info.PetitionID = -int32(petitionguid.GetCounter());
        SendPacket(responsePacket.Write());

        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition ({})", petitionguid.ToString());
        return;
    }

    CharterTypes type = petition->PetitionType;
    uint32 reqSignatures = type == GUILD_CHARTER_TYPE ? sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS) : uint32(type - 1);

    WorldPackets::Petition::PetitionInfo& petitionInfo = responsePacket.Info;
    petitionInfo.PetitionID = int32(petitionguid.GetCounter());
    petitionInfo.Petitioner = petition->OwnerGuid;
    petitionInfo.MinSignatures = reqSignatures;
    petitionInfo.MaxSignatures = reqSignatures;
    petitionInfo.Title = petition->PetitionName;
    petitionInfo.StaticType = type != GUILD_CHARTER_TYPE ? 1 : 0;
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
        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition {}", packet.PetitionGuid.ToString());
        return;
    }

    CharterTypes type = petition->PetitionType;
    if (type == GUILD_CHARTER_TYPE)
    {
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
    }
    else
    {
        if (sArenaTeamMgr->GetArenaTeamByName(packet.NewGuildName))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, packet.NewGuildName, "", ERR_ARENA_TEAM_NAME_EXISTS_S);
            return;
        }

        if (sObjectMgr->IsReservedName(packet.NewGuildName) || !ObjectMgr::IsValidCharterName(packet.NewGuildName))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, packet.NewGuildName, "", ERR_ARENA_TEAM_NAME_INVALID);
            return;
        }
    }

    // update petition storage
    petition->UpdateName(packet.NewGuildName);

    WorldPackets::Petition::PetitionRenameGuildResponse renameResponse;
    renameResponse.PetitionGuid = packet.PetitionGuid;
    renameResponse.NewGuildName = packet.NewGuildName;
    SendPacket(renameResponse.Write());

    TC_LOG_DEBUG("network", "Petition {} renamed to '{}'", packet.PetitionGuid.ToString(), packet.NewGuildName);
}

void WorldSession::HandleSignPetition(WorldPackets::Petition::SignPetition& packet)
{
    Petition* petition = sPetitionMgr->GetPetition(packet.PetitionGUID);
    if (!petition)
    {
        TC_LOG_ERROR("network", "Petition {} is not found for player {} {}", packet.PetitionGUID.ToString(), GetPlayer()->GetGUID().ToString(), GetPlayer()->GetName());
        return;
    }

    ObjectGuid ownerGuid = petition->OwnerGuid;
    CharterTypes type = petition->PetitionType;
    uint8 signs = uint8(petition->Signatures.size());

    if (ownerGuid == _player->GetGUID())
        return;

    // not let enemies sign guild charter
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != sCharacterCache->GetCharacterTeamByGuid(ownerGuid))
    {
        if (type != GUILD_CHARTER_TYPE)
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        else
            Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (type != GUILD_CHARTER_TYPE)
    {
        if (!_player->IsMaxLevel())
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", _player->GetName(), ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
            return;
        }

        uint8 slot = ArenaTeam::GetSlotByType(static_cast<uint32>(type));
        if (slot >= MAX_ARENA_SLOT)
            return;

        if (_player->GetArenaTeamId(slot))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", _player->GetName(), ERR_ALREADY_IN_ARENA_TEAM_S);
            return;
        }

        if (_player->GetArenaTeamIdInvited())
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", _player->GetName(), ERR_ALREADY_INVITED_TO_ARENA_TEAM_S);
            return;
        }
    }
    else
    {
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
    }

    if (++signs > static_cast<uint8>(type))                                        // client signs maximum
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
            owner->SendDirectMessage(signResult.GetRawPacket());
        return;
    }

    // fill petition store
    petition->AddSignature(GetAccountId(), _player->GetGUID(), false);

    TC_LOG_DEBUG("network", "PETITION SIGN: {} by player: {} ({} Account: {})", packet.PetitionGUID.ToString(), _player->GetName(), _player->GetGUID().ToString(), GetAccountId());

    signResult.Error = int32(PETITION_SIGN_OK);

    // update signs count on charter
    if (Item* item = _player->GetItemByGuid(packet.PetitionGUID))
    {
        item->SetPetitionNumSignatures(signs);
        item->SetState(ITEM_CHANGED, _player);
    }

    // update for owner if online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(ownerGuid))
        owner->SendDirectMessage(signResult.GetRawPacket());
}

void WorldSession::HandleDeclinePetition(WorldPackets::Petition::DeclinePetition& packet)
{
    TC_LOG_DEBUG("network", "Petition {} declined by {}", packet.PetitionGUID.ToString(), _player->GetGUID().ToString());

    Petition const* petition = sPetitionMgr->GetPetition(packet.PetitionGUID);
    if (!petition)
        return;

    // petition owner online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(petition->OwnerGuid))
    {
        WorldPackets::Petition::PetitionDeclined petitionDeclined;
        petitionDeclined.Decliner = _player->GetGUID();
        owner->SendDirectMessage(petitionDeclined.Write());
    }
}

void WorldSession::HandleOfferPetition(WorldPackets::Petition::OfferPetition& packet)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(packet.TargetPlayer);
    if (!player)
        return;

    Petition const* petition = sPetitionMgr->GetPetition(packet.ItemGUID);
    if (!petition)
        return;

    CharterTypes type = petition->PetitionType;

    TC_LOG_DEBUG("network", "OFFER PETITION: type {}, {}, to {}", static_cast<uint32>(type), packet.ItemGUID.ToString(), packet.TargetPlayer.ToString());

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        if (type != GUILD_CHARTER_TYPE)
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        else
            Guild::SendCommandResult(this, GUILD_COMMAND_CREATE_GUILD, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (type != GUILD_CHARTER_TYPE)
    {
        if (!player->IsMaxLevel())
        {
            // player is too low level to join an arena team
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
            return;
        }

        uint8 slot = ArenaTeam::GetSlotByType(static_cast<uint32>(type));
        if (slot >= MAX_ARENA_SLOT)
            return;

        if (player->GetArenaTeamId(slot))
        {
            // player is already in an arena team
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ALREADY_IN_ARENA_TEAM_S);
            return;
        }

        if (player->GetArenaTeamIdInvited())
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", _player->GetName(), ERR_ALREADY_INVITED_TO_ARENA_TEAM_S);
            return;
        }
    }
    else
    {
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
    }

    SendPetitionSigns(petition, player);
}

void WorldSession::HandleTurnInPetition(WorldPackets::Petition::TurnInPetition& packet)
{
    // Check if player really has the required petition charter
    Item* item = _player->GetItemByGuid(packet.Item);
    if (!item)
        return;

    TC_LOG_DEBUG("network", "Petition {} turned in by {}", packet.Item.ToString(), _player->GetGUID().ToString());

    Petition const* petition = sPetitionMgr->GetPetition(packet.Item);
    if (!petition)
    {
        TC_LOG_ERROR("entities.player.cheat", "Player {} {} tried to turn in petition ({}) that is not present in the database", _player->GetName(), _player->GetGUID().ToString(), packet.Item.ToString());
        return;
    }

    CharterTypes type = petition->PetitionType;
    std::string const name = petition->PetitionName; // we need a copy, it will be removed on guild/arena remove

    // Only the petition owner can turn in the petition
    if (_player->GetGUID() != petition->OwnerGuid)
        return;

    // Petition type (guild/arena) specific checks
    if (type == GUILD_CHARTER_TYPE)
    {
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
    }
    else
    {
        // Check for valid arena bracket (2v2, 3v3, 5v5)
        uint8 slot = ArenaTeam::GetSlotByType(static_cast<uint32>(type));
        if (slot >= MAX_ARENA_SLOT)
            return;

        // Check if player is already in an arena team
        if (_player->GetArenaTeamId(slot))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, name, "", ERR_ALREADY_IN_ARENA_TEAM);
            return;
        }

        // Check if arena team name is already taken
        if (sArenaTeamMgr->GetArenaTeamByName(name))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, name, "", ERR_ARENA_TEAM_NAME_EXISTS_S);
            return;
        }
    }

    SignaturesVector const signatures = petition->Signatures; // we need a copy, it will be removed on guild/arena remove
    uint32 requiredSignatures = static_cast<uint32>(type) - 1;
    if (type == GUILD_CHARTER_TYPE)
        requiredSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);

    // Notify player if signatures are missing
    if (signatures.size() < requiredSignatures)
    {
        WorldPackets::Petition::TurnInPetitionResult resultPacket;
        resultPacket.Result = int32(PETITION_TURN_NEED_MORE_SIGNATURES);
        SendPacket(resultPacket.Write());
        return;
    }

    // Proceed with guild/arena team creation

    // Delete charter item
    _player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

    if (type == GUILD_CHARTER_TYPE)
    {
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
    }
    else
    {
        // Create arena team
        ArenaTeam* arenaTeam = new ArenaTeam();

        if (!arenaTeam->Create(_player->GetGUID(), type, name, packet.EmblemBackground, packet.EmblemIconStyle, packet.EmblemIconColor, packet.EmblemBorderStyle, packet.EmblemBorderColor))
        {
            delete arenaTeam;
            return;
        }

        // Register arena team
        sArenaTeamMgr->AddArenaTeam(arenaTeam);
        TC_LOG_DEBUG("network", "PetitonsHandler: Arena team (guid: {}) added to ObjectMgr", arenaTeam->GetId());

        // Add members
        for (Signature const& signature : signatures)
        {
            TC_LOG_DEBUG("network", "PetitionsHandler: Adding arena team (guid: {}) member {}", arenaTeam->GetId(), signature.second.ToString());
            arenaTeam->AddMember(signature.second);
        }
    }

    sPetitionMgr->RemovePetition(packet.Item);

    // created
    TC_LOG_DEBUG("network", "Player {} ({}) turning in petition {}", _player->GetName(), _player->GetGUID().ToString(), packet.Item.ToString());

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
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionShowListOpcode - {} not found or you can't interact with him.", guid.ToString());
        return;
    }

    WorldPackets::Petition::ServerPetitionShowList packet;
    packet.Unit = guid;

    if (creature->IsTabardDesigner())
    {
        std::array<WorldPackets::Petition::PetitionList, 1> const guildCharter =
        {{
            {
                .Muid = 1,
                .ItemID = GUILD_CHARTER,
                .ItemDisplayID = CHARTER_DISPLAY_ID,
                .Price = sWorld->getIntConfig(CONFIG_CHARTER_COST_GUILD),
                .PetitionTypeID = 0,
                .SignaturesNeeded = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS)
            }
        }};

        packet.PetitionInfo = guildCharter;
    }
    else
    {
        std::array<WorldPackets::Petition::PetitionList, 3> const arenaCharters =
        {{
            {
                .Muid = 1,
                .ItemID = ARENA_TEAM_CHARTER_2v2,
                .ItemDisplayID = CHARTER_DISPLAY_ID,
                .Price = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_2v2),
                .PetitionTypeID = 1,
                .SignaturesNeeded = 2
            },
            {
                .Muid = 2,
                .ItemID = ARENA_TEAM_CHARTER_3v3,
                .ItemDisplayID = CHARTER_DISPLAY_ID,
                .Price = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_3v3),
                .PetitionTypeID = 1,
                .SignaturesNeeded = 3
            },
            {
                .Muid = 3,
                .ItemID = ARENA_TEAM_CHARTER_5v5,
                .ItemDisplayID = CHARTER_DISPLAY_ID,
                .Price = sWorld->getIntConfig(CONFIG_CHARTER_COST_ARENA_5v5),
                .PetitionTypeID = 1,
                .SignaturesNeeded = 5
            },
        }};

        packet.PetitionInfo = arenaCharters;
    }

    SendPacket(packet.Write());
}
