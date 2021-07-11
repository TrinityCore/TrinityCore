/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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
#include "Creature.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "PetitionMgr.h"
#include "PetitionPackets.h"
#include "Player.h"
#include "World.h"
#include <sstream>
#include "Guild.h"
#include "GuildMgr.h"
#include "GossipDef.h"
#include "SocialMgr.h"
#include "Anticheat.h"

// Charters ID in item_template
#define GUILD_CHARTER               5863
#define GUILD_CHARTER_COST          1000                    // 10 S
#define CHARTER_DISPLAY_ID          16161

void WorldSession::HandlePetitionBuyOpcode(WorldPacket& recv_data)
{
    TC_LOG_DEBUG("network", "Petitioner {} tried sell petition: title {}", packet.Unit.ToString(), packet.Title);
    DEBUG_LOG("Received opcode CMSG_PETITION_BUY");

    ObjectGuid guidNPC;
    uint32 unk2;
    std::string name;

    recv_data >> guidNPC;                                   // NPC GUID
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint64>();                          // 0
    recv_data >> name;                                      // name
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint16>();                          // 0
    recv_data.read_skip<uint8>();                           // 0

    recv_data >> unk2;                                      // index
    recv_data.read_skip<uint32>();                          // 0

    DEBUG_LOG("Petitioner %s tried sell petition: name %s", guidNPC.GetString().c_str(), name.c_str());

    // prevent cheating
    Creature* pCreature = GetPlayer()->GetNPCIfCanInteractWith(guidNPC, UNIT_NPC_FLAG_PETITIONER);
    if (!pCreature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionBuyOpcode - {} not found or you can't interact with him.", packet.Unit.ToString());
        DEBUG_LOG("WORLD: HandlePetitionBuyOpcode - %s not found or you can't interact with him.", guidNPC.GetString().c_str());
        return;
    }

    if (!pCreature->IsTabardDesigner())
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STAT_FEIGN_DEATH))
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    // if tabard designer, then trying to buy a guild charter.
    // do not let if already in guild.
    if (_player->GetGuildId())
        return;

    // Cannot buy a petition if the owner already has one
    if (Petition* petition = sGuildMgr.GetPetitionByOwnerGuid(_player->GetObjectGuid()))
        return;

    uint32 charterid = GUILD_CHARTER;
    uint32 cost = GUILD_CHARTER_COST;

    if (sGuildMgr.GetGuildByName(name))
    {
        SendGuildCommandResult(GUILD_CREATE_S, name, ERR_GUILD_NAME_EXISTS_S);
        return;
    }
    if (sObjectMgr.IsReservedName(name) || !ObjectMgr::IsValidCharterName(name))
    {
        SendGuildCommandResult(GUILD_CREATE_S, name, ERR_GUILD_NAME_INVALID);
        return;
    }

    // Check guild petition name (use whisper type - 6)
    if (AntispamInterface *a = sAnticheatMgr->GetAntispam())
    {
        if (a->filterMessage(name))
        {
            sWorld.LogChat(this, "Guild", "Attempt to create guild petition with spam name" + name);
            SendGuildCommandResult(GUILD_CREATE_S, name, ERR_GUILD_NAME_INVALID);
            return;
        }
    }

    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(charterid);
    if (!pProto)
    {
        _player->SendBuyError(BUY_ERR_CANT_FIND_ITEM, nullptr, charterid, 0);
        return;
    }

    if (_player->GetMoney() < cost)
    {
        //player hasn't got enough money
        _player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, pCreature, charterid, 0);
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, charterid, pProto->BuyCount);
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, nullptr, nullptr, charterid);
        return;
    }

    _player->ModifyMoney(-(int32)cost);
    Item *charter = _player->StoreNewItem(dest, charterid, true);
    if (!charter)
        return;

    uint32 petitionId = sObjectMgr.GeneratePetitionID();
    charter->SetUInt32Value(ITEM_FIELD_ENCHANTMENT, petitionId);
    // ITEM_FIELD_ENCHANTMENT is guild
    // ITEM_FIELD_ENCHANTMENT+1 is current signatures count (showed on item)
    charter->SetState(ITEM_CHANGED, _player);
    _player->SendNewItem(charter, 1, true, false);

    // a petition is invalid, if both the owner and the type matches
    // we checked above, if this player is in an arenateam, so this must be
    // datacorruption
    if (Petition const* petition = sPetitionMgr->GetPetitionByOwner(_player->GetGUID()))
    {
        // clear from petition store
        sPetitionMgr->RemovePetition(petition->PetitionGuid);
        TC_LOG_DEBUG("network", "Invalid petition {}", petition->PetitionGuid.ToString());
    }
    sGuildMgr.CreatePetition(petitionId, _player, charter->GetObjectGuid(), name);

    _player->SaveInventoryAndGoldToDB();
}

void WorldSession::HandlePetitionShowSignOpcode(WorldPacket& recv_data)
{
    Petition const* petition = sPetitionMgr->GetPetition(packet.Item);
    if (!petition)
    {
        TC_LOG_DEBUG("entities.player.items", "Petition {} is not found for player {} {}", packet.Item.ToString(), GetPlayer()->GetGUID().ToString(), GetPlayer()->GetName());
        return;
    }
    // ok
    DEBUG_LOG("Received opcode CMSG_PETITION_SHOW_SIGNATURES");
    //recv_data.hexlike();

    ObjectGuid itemguid;
    recv_data >> itemguid;                                   // item guid

    // if guild petition and has guild => error, return;
    if (_player->GetGuildId())
        return;

    TC_LOG_DEBUG("network", "CMSG_PETITION_SHOW_SIGNATURES petition {}", packet.Item.ToString());
    Item *charter = _player->GetItemByGuid(itemguid);
    if (!charter)
        return;

    uint32 petitionGuid = charter->GetEnchantmentId(EnchantmentSlot(0));
    Petition *petition = sGuildMgr.GetPetitionById(petitionGuid);

void WorldSession::SendPetitionSigns(Petition const* petition, Player* sendTo)
{
    WorldPackets::Petition::ServerPetitionShowSignatures signaturesPacket;
    signaturesPacket.Item = petition->PetitionGuid;
    signaturesPacket.Owner = petition->OwnerGuid;
    signaturesPacket.OwnerAccountID = ObjectGuid::Create<HighGuid::WowAccount>(sCharacterCache->GetCharacterAccountIdByGuid(petition->OwnerGuid));
    signaturesPacket.PetitionID = petition->PetitionGuid.GetCounter();
    if (!petition)
    {
        sLog.outError("[PetitionHandler] No petition exists for petition ID %u, yet charter exists with guid %u for owner %s",
            petitionGuid, itemguid.GetCounter(), _player->GetGuidStr().c_str());

    for (Signature const& signature : petition->Signatures)
    {
        WorldPackets::Petition::ServerPetitionShowSignatures::PetitionSignature signaturePkt;
        signaturePkt.Signer = signature.second;
        signaturePkt.Choice = 0;
        signaturesPacket.Signatures.push_back(signaturePkt);
        return;
    }

    uint8 signs = petition->GetSignatureCount();

void WorldSession::HandleQueryPetition(WorldPackets::Petition::QueryPetition& packet)
{
    TC_LOG_DEBUG("network", "Received CMSG_QUERY_PETITION Petition {} PetitionID {}", packet.ItemGUID.ToString(), packet.PetitionID);
    DEBUG_LOG("CMSG_PETITION_SHOW_SIGNATURES petition: %u", petitionGuid);

    WorldPacket data(SMSG_PETITION_SHOW_SIGNATURES, (8 + 8 + 4 + 1 + signs * 12));
    data << itemguid;                               // item guid
    data << _player->GetObjectGuid();               // owner guid
    data << petitionGuid;                           // petition guid
    data << signs;                                  // sign's count

    petition->BuildSignatureData(data);

        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition ({})", petitionguid.ToString());
        return;
    }
    SendPacket(&data);
}

void WorldSession::HandlePetitionQueryOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("Received opcode CMSG_PETITION_QUERY");
    //recv_data.hexlike();

    WorldPackets::Petition::PetitionInfo& petitionInfo = responsePacket.Info;
    petitionInfo.PetitionID = int32(petitionguid.GetCounter());
    petitionInfo.Petitioner = petition->OwnerGuid;
    petitionInfo.MinSignatures = reqSignatures;
    petitionInfo.MaxSignatures = reqSignatures;
    petitionInfo.Title = petition->PetitionName;
    uint32 petitionGuid;
    ObjectGuid itemGuid;
    recv_data >> petitionGuid;                          // petition guid
    recv_data >> itemGuid;                              // item guid
    DEBUG_LOG("CMSG_PETITION_QUERY Item %s Petition GUID %u", itemGuid.GetString().c_str(), petitionGuid);

    Petition* petition = sGuildMgr.GetPetitionById(petitionGuid);
    if (!petition)
        return;

    WorldPacket data(SMSG_PETITION_QUERY_RESPONSE, (4 + 8 + petition->GetName().size() + 1 + 2 + 4 * 11));
    data << uint32(petitionGuid);                           // int m_petitionID;
    data << ObjectGuid(petition->GetOwnerGuid());           // unsigned __int64 m_petitioner;
    data << petition->GetName();                            // char m_title[256];
    data << uint8(0);                                       // char m_bodyText[4096];
    data << uint32(1);                                      // int m_flags;
    data << uint32(9);                                      // int m_minSignatures;
    data << uint32(9);                                      // int m_maxSignatures;
    data << uint32(0);                                      // int m_deadLine;
    data << uint32(0);                                      // int m_issueDate;
    data << uint32(0);                                      // int m_allowedGuildID;
    data << uint32(0);                                      // int m_allowedClasses;
    data << uint32(0);                                      // int m_allowedRaces;
    data << uint16(0);                                      // __int16 m_allowedGender;
    data << uint32(0);                                      // int m_allowedMinLevel;
    data << uint32(0);                                      // int m_allowedMaxLevel;
    data << uint32(0);                                      // char m_choicetext[10][64];
    // for (int i=0; i<field13; ++i) data << chartSignersName[i];   Probably, names of the petition signers
    data << uint32(0);                                      // int m_numChoices;
    SendPacket(&data);
}

void WorldSession::HandlePetitionRenameOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("Received opcode MSG_PETITION_RENAME");   // ok
    //recv_data.hexlike();

    ObjectGuid itemGuid;
    std::string newname;

    recv_data >> itemGuid;                              // item
    recv_data >> newname;                               // new name

    Item *charter = _player->GetItemByGuid(itemGuid);
    if (!charter)
        return;

    if (sGuildMgr.GetGuildByName(newname))
    {
        TC_LOG_DEBUG("network", "CMSG_PETITION_QUERY failed for petition {}", packet.PetitionGuid.ToString());
        SendGuildCommandResult(GUILD_CREATE_S, newname, ERR_GUILD_NAME_EXISTS_S);
        return;
    }
    if (sObjectMgr.IsReservedName(newname) || !ObjectMgr::IsValidCharterName(newname))
    {
        SendGuildCommandResult(GUILD_CREATE_S, newname, ERR_GUILD_NAME_INVALID);
        return;
    }

    uint32 petitionGuid = charter->GetEnchantmentId(EnchantmentSlot(0));

    Petition* petition = sGuildMgr.GetPetitionById(petitionGuid);
    if (!petition)
        return;

    if (petition->Rename(newname))
    {
        WorldPacket data(MSG_PETITION_RENAME, (8 + newname.size() + 1));
        data << ObjectGuid(itemGuid);
        data << newname;
        SendPacket(&data);
    }
}

void WorldSession::HandlePetitionSignOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("Received opcode CMSG_PETITION_SIGN");    // ok
    //recv_data.hexlike();

    ObjectGuid itemGuid;
    uint8 unk;
    recv_data >> itemGuid;                              // item guid
    recv_data >> unk;

    TC_LOG_DEBUG("network", "Petition {} renamed to '{}'", packet.PetitionGuid.ToString(), packet.NewGuildName);
}
    Petition* petition = sGuildMgr.GetPetitionByCharterGuid(itemGuid);

    if (!petition)
    {
        TC_LOG_ERROR("network", "Petition {} is not found for player {} {}", packet.PetitionGUID.ToString(), GetPlayer()->GetGUID().ToString(), GetPlayer()->GetName());
        sLog.outError("[PetitionHandler] No petition exists for charter with guid %u for signer %s",
            itemGuid.GetCounter(), _player->GetGuidStr().c_str());
        return;
    }

    ObjectGuid ownerGuid = petition->OwnerGuid;
    uint64 signs = petition->Signatures.size();
    if (petition->IsComplete()) // reached maximum number of signatures for this petition
        return;

    if (petition->GetOwnerGuid() == _player->GetObjectGuid())
    {
        WorldPacket data(SMSG_PETITION_SIGN_RESULTS, (8 + 8 + 4));
        data << ObjectGuid(itemGuid);
        data << ObjectGuid(_player->GetObjectGuid());
        data << uint32(PETITION_SIGN_CANT_SIGN_OWN);
        SendPacket(&data);
        return;
    }

    // not let enemies sign guild charter
    if (!sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_GUILD) &&
            GetPlayer()->GetTeam() != petition->GetTeam())
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (_player->GetGuildId())
    {
        SendGuildCommandResult(GUILD_INVITE_S, _player->GetName(), ERR_ALREADY_IN_GUILD_S);
        return;
    }
    if (_player->GetGuildIdInvited())
    {
        SendGuildCommandResult(GUILD_INVITE_S, _player->GetName(), ERR_ALREADY_INVITED_TO_GUILD_S);
        return;
    }

    uint8 signs = petition->GetSignatureCount();

    // Client hard limit at 9 signatures
    if (signs >= 9)
        return;

    //client doesn't allow to sign petition two times by one character, but not check sign by another character from same account
    //not allow sign another player from already sign player account
    if (PetitionSignature* signature = petition->GetSignatureForPlayer(_player))
    {
        WorldPacket data(SMSG_PETITION_SIGN_RESULTS, (8 + 8 + 4));
        data << ObjectGuid(itemGuid);
        data << ObjectGuid(_player->GetObjectGuid());
        data << uint32(PETITION_SIGN_ALREADY_SIGNED);

        // close at signer side
        SendPacket(&data);

        // Update for owner if online. Note: Unsure if this is the correct message,
        // but sending SMSG_PETITION_SIGN_RESULTS does nothing for the owner here
        if (Player* owner = sObjectMgr.GetPlayer(petition->GetOwnerGuid()))
            owner->GetSession()->SendGuildCommandResult(GUILD_INVITE_S, _player->GetName(), ERR_ALREADY_INVITED_TO_GUILD_S);
        return;
    }

    // fill petition store
    petition->AddSignature(GetAccountId(), _player->GetGUID(), false);

    TC_LOG_DEBUG("network", "PETITION SIGN: {} by player: {} ({} Account: {})", packet.PetitionGUID.ToString(), _player->GetName(), _player->GetGUID().ToString(), GetAccountId());
    if (petition->AddNewSignature(_player))
    {
        DEBUG_LOG("PETITION SIGN: %u by %s", petition->GetId(), _player->GetGuidStr().c_str());

        WorldPacket data(SMSG_PETITION_SIGN_RESULTS, (8 + 8 + 4));
        data << ObjectGuid(itemGuid);
        data << ObjectGuid(_player->GetObjectGuid());
        data << uint32(PETITION_SIGN_OK);

        // close at signer side
        SendPacket(&data);

        // update signs count on charter, required testing...
        //Item *item = _player->GetItemByGuid(petitionguid));
        //if (item)
        //    item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT+1, signs);

        // update for owner if online
        if (Player* owner = sObjectMgr.GetPlayer(petition->GetOwnerGuid()))
            owner->GetSession()->SendPacket(&data);
    }
}

void WorldSession::HandlePetitionDeclineOpcode(WorldPacket& recv_data)
{
    TC_LOG_DEBUG("network", "Petition {} declined by {}", packet.PetitionGUID.ToString(), _player->GetGUID().ToString());
    DEBUG_LOG("Received opcode MSG_PETITION_DECLINE");  // ok
    //recv_data.hexlike();

    ObjectGuid itemGuid;
    recv_data >> itemGuid;                              // item guid

    DEBUG_LOG("Petition %s declined by %s", itemGuid.GetString().c_str(), _player->GetGuidStr().c_str());

    Petition* petition = sGuildMgr.GetPetitionByCharterGuid(itemGuid);

    if (!petition)
        return;

    // petition owner online
    if (Player* owner = ObjectAccessor::FindConnectedPlayer(petition->OwnerGuid))
    // TODO: Check if this is actually used
    Player* owner = sObjectMgr.GetPlayer(petition->GetOwnerGuid());
    if (owner)                                              // petition owner online
    {
        WorldPacket data(MSG_PETITION_DECLINE, 8);
        data << _player->GetObjectGuid();
        owner->GetSession()->SendPacket(&data);
    }
}

void WorldSession::HandleOfferPetitionOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("Received opcode CMSG_OFFER_PETITION");   // ok
    //recv_data.hexlike();

    ObjectGuid itemGuid;
    ObjectGuid playerGuid;
    recv_data >> itemGuid;                              // item guid
    recv_data >> playerGuid;                            // player guid

    Player* player = ObjectAccessor::FindPlayer(playerGuid);
    if (!player)
        return;

    TC_LOG_DEBUG("network", "OFFER PETITION: {}, to {}", packet.ItemGUID.ToString(), packet.TargetPlayer.ToString());

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != player->GetTeam())
    if (!sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (player->GetGuildId())
    {
        SendGuildCommandResult(GUILD_INVITE_S, _player->GetName(), ERR_ALREADY_IN_GUILD_S);
        return;
    }

    if (player->GetGuildIdInvited())
    {
        SendGuildCommandResult(GUILD_INVITE_S, _player->GetName(), ERR_ALREADY_INVITED_TO_GUILD_S);
        return;
    }

    Item *charter = _player->GetItemByGuid(itemGuid);
    if (!charter)
        return;

    TC_LOG_DEBUG("network", "Petition {} turned in by {}", packet.Item.ToString(), _player->GetGUID().ToString());
    uint32 petitionGuid = charter->GetEnchantmentId(EnchantmentSlot(0));

    Petition* petition = sGuildMgr.GetPetitionById(petitionGuid);
    if (!petition)
    {
        TC_LOG_ERROR("entities.player.cheat", "Player {} {} tried to turn in petition ({}) that is not present in the database", _player->GetName(), _player->GetGUID().ToString(), packet.Item.ToString());
        sLog.outError("[PetitionHandler] No petition exists for charter with guid %u for signer %s",
            itemGuid.GetCounter(), _player->GetGuidStr().c_str());
        return;
    }

    DEBUG_LOG("OFFER PETITION: petition %u to %s", petitionGuid, playerGuid.GetString().c_str());

    /// Get petition signs count
    uint8 signs = petition->GetSignatureCount();

    /// Send response
    WorldPacket data(SMSG_PETITION_SHOW_SIGNATURES, (8 + 8 + 4 + 1 + signs * 12));
    data << ObjectGuid(itemGuid);                           // item guid
    data << ObjectGuid(_player->GetObjectGuid());           // owner guid
    data << uint32(petitionGuid);                           // petition guid
    data << uint8(signs);                                   // sign's count

    petition->BuildSignatureData(data);
    player->GetSession()->SendPacket(&data);
}

    std::string const name = petition->PetitionName; // we need a copy, Guild::AddMember invalidates petition
void WorldSession::HandleTurnInPetitionOpcode(WorldPacket& recv_data)
{
    DEBUG_LOG("Received opcode CMSG_TURN_IN_PETITION"); // ok
    //recv_data.hexlike();

    ObjectGuid itemGuid;
    recv_data >> itemGuid;

    // Only the petition owner can turn in the petition
    if (_player->GetGUID() != petition->OwnerGuid)
    Item *charter = _player->GetItemByGuid(itemGuid);
    if (!charter)
        return;

    uint32 petitionGuid = charter->GetEnchantmentId(EnchantmentSlot(0));
    DEBUG_LOG("Petition %u turned in by %s", petitionGuid, _player->GetGuidStr().c_str());

    Petition* petition = sGuildMgr.GetPetitionById(petitionGuid);
    if (!petition)
    {
        sLog.outError("[PetitionHandler] No petition exists for charter with guid %u for guild master %s",
            itemGuid.GetCounter(), _player->GetGuidStr().c_str());
        return;
    }

    /// Collect petition info data
    if (_player->GetGuildId())
    {
        WorldPacket data(SMSG_TURN_IN_PETITION_RESULTS, 4);
        data << uint32(PETITION_SIGN_ALREADY_IN_GUILD); // already in guild
        _player->GetSession()->SendPacket(&data);
        return;
    }

    SignaturesVector const signatures = petition->Signatures; // we need a copy, Guild::AddMember invalidates petition
    uint32 requiredSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);
    if (_player->GetObjectGuid() != petition->GetOwnerGuid())
        return;

    if (!petition->IsComplete())
    {
        WorldPacket data(SMSG_TURN_IN_PETITION_RESULTS, 4);
        data << uint32(PETITION_SIGN_NEED_MORE); // need more signatures...
        SendPacket(&data);
        return;
    }

    if (sGuildMgr.GetGuildByName(petition->GetName()))
    {
        SendGuildCommandResult(GUILD_CREATE_S, petition->GetName(), ERR_GUILD_NAME_EXISTS_S);
        return;
    }

    // OK!

    Guild* guild = new Guild;
    if (!guild->Create(petition, _player))
    {
        delete guild;
        return;
    }

    // register guild
    sGuildMgr.AddGuild(guild);

    sGuildMgr.DeletePetition(petition);
    petition = nullptr; // deleted in GuildMgr::DeletePetition

    // Delete the charter item now. Deleting the charter deletes the petition
    // if it still exists, so we do not want to do it before the guild is
    // created.
    _player->DestroyItem(charter->GetBagSlot(), charter->GetSlot(), true);

    // created
    TC_LOG_DEBUG("network", "Player {} ({}) turning in petition {}", _player->GetName(), _player->GetGUID().ToString(), packet.Item.ToString());
    DEBUG_LOG("TURN IN PETITION %u", petitionGuid);

    WorldPacket data(SMSG_TURN_IN_PETITION_RESULTS, 4);
    data << uint32(PETITION_SIGN_OK);
    SendPacket(&data);
}

void WorldSession::HandlePetitionShowListOpcode(WorldPacket& recv_data)
{
#ifndef DISABLE_DRESSNPCS_CORESOUNDS
    if (packet.PetitionUnit.IsAnyTypeCreature())
        if (Creature* creature = _player->GetMap()->GetCreature(packet.PetitionUnit))
            creature->SendMirrorSound(_player, 0);
#endif
    SendPetitionShowList(packet.PetitionUnit);
    DEBUG_LOG("Received CMSG_PETITION_SHOWLIST");
    //recv_data.hexlike();

    ObjectGuid guid;
    recv_data >> guid;
    SendPetitionShowList(guid);
}

void WorldSession::SendPetitionShowList(ObjectGuid& guid)
{
    Creature* pCreature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_PETITIONER);
    if (!pCreature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandlePetitionShowListOpcode - {} not found or you can't interact with him.", guid.ToString());
        DEBUG_LOG("WORLD: HandlePetitionShowListOpcode - %s not found or you can't interact with him.", guid.GetString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STAT_FEIGN_DEATH))
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    uint8 count = 1;

    WorldPacket data(SMSG_PETITION_SHOWLIST, 8 + 1 + 4 * 6);
    data << guid;                                           // npc guid
    data << count;                                          // count; allowed values 1-10
    data << uint32(1);                                      // index
    data << uint32(GUILD_CHARTER);                          // charter entry
    data << uint32(CHARTER_DISPLAY_ID);                     // charter display id
    data << uint32(GUILD_CHARTER_COST);                     // charter cost
    data << uint32(1);                                      // unknown
    //data << uint32(9);                                    // [-ZERO] required signs?
    //for(uint8 i = 0; i < count; ++i)
    //{
    //    data << uint32(i);                        // index
    //    data << uint32(GUILD_CHARTER);            // charter entry
    //    data << uint32(CHARTER_DISPLAY_ID);       // charter display id
    //    data << uint32(GUILD_CHARTER_COST+i);     // charter cost
    //    data << uint32(1);                        // unknown
    //}
    SendPacket(&data);
    DEBUG_LOG("Sent SMSG_PETITION_SHOWLIST");
}
