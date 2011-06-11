/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ArenaTeamMgr.h"
#include "GuildMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Guild.h"
#include "ArenaTeam.h"
#include "GossipDef.h"
#include "SocialMgr.h"

#define CHARTER_DISPLAY_ID 16161

/*enum PetitionType // dbc data
{
    PETITION_TYPE_GUILD      = 1,
    PETITION_TYPE_ARENA_TEAM = 3
};*/

// Charters ID in item_template
enum CharterItemIDs
{
    GUILD_CHARTER                                 = 5863,
    ARENA_TEAM_CHARTER_2v2                        = 23560,
    ARENA_TEAM_CHARTER_3v3                        = 23561,
    ARENA_TEAM_CHARTER_5v5                        = 23562
};

enum CharterCosts
{
    GUILD_CHARTER_COST                            = 1000,
    ARENA_TEAM_CHARTER_2v2_COST                   = 800000,
    ARENA_TEAM_CHARTER_3v3_COST                   = 1200000,
    ARENA_TEAM_CHARTER_5v5_COST                   = 2000000
};

void WorldSession::HandlePetitionBuyOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_PETITION_BUY");
    recv_data.hexlike();

    uint64 guidNPC;
    uint32 clientIndex;                                     // 1 for guild and arenaslot+1 for arenas in client
    std::string name;

    recv_data >> guidNPC;                                   // NPC GUID
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint64>();                          // 0
    recv_data >> name;                                      // name
    recv_data.read_skip<std::string>();                     // some string
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint16>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0
    recv_data.read_skip<uint32>();                          // 0

    for (int i = 0; i < 10; ++i)
        recv_data.read_skip<std::string>();

    recv_data >> clientIndex;                               // index
    recv_data.read_skip<uint32>();                          // 0

    sLog->outDebug(LOG_FILTER_NETWORKIO, "Petitioner with GUID %u tried sell petition: name %s", GUID_LOPART(guidNPC), name.c_str());

    // prevent cheating
    Creature *pCreature = GetPlayer()->GetNPCIfCanInteractWith(guidNPC, UNIT_NPC_FLAG_PETITIONER);
    if (!pCreature)
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: HandlePetitionBuyOpcode - Unit (GUID: %u) not found or you can't interact with him.", GUID_LOPART(guidNPC));
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    uint32 charterid = 0;
    uint32 cost = 0;
    uint32 type = 0;
    if (pCreature->isTabardDesigner())
    {
        // if tabard designer, then trying to buy a guild charter.
        // do not let if already in guild.
        if (_player->GetGuildId())
            return;

        charterid = GUILD_CHARTER;
        cost = GUILD_CHARTER_COST;
        type = GUILD_CHARTER_TYPE;
    }
    else
    {
        // TODO: find correct opcode
        if (_player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            SendNotification(LANG_ARENA_ONE_TOOLOW, sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
            return;
        }

        switch(clientIndex)                                 // arenaSlot+1 as received from client (1 from 3 case)
        {
            case 1:
                charterid = ARENA_TEAM_CHARTER_2v2;
                cost = ARENA_TEAM_CHARTER_2v2_COST;
                type = ARENA_TEAM_CHARTER_2v2_TYPE;
                break;
            case 2:
                charterid = ARENA_TEAM_CHARTER_3v3;
                cost = ARENA_TEAM_CHARTER_3v3_COST;
                type = ARENA_TEAM_CHARTER_3v3_TYPE;
                break;
            case 3:
                charterid = ARENA_TEAM_CHARTER_5v5;
                cost = ARENA_TEAM_CHARTER_5v5_COST;
                type = ARENA_TEAM_CHARTER_5v5_TYPE;
                break;
            default:
                sLog->outDebug(LOG_FILTER_NETWORKIO, "unknown selection at buy arena petition: %u", clientIndex);
                return;
        }

        if (_player->GetArenaTeamId(clientIndex - 1))        // arenaSlot+1 as received from client
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, name, "", ERR_ALREADY_IN_ARENA_TEAM);
            return;
        }
    }

    if (type == GUILD_CHARTER_TYPE)
    {
        if (sGuildMgr->GetGuildByName(name))
        {
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NAME_EXISTS_S, name);
            return;
        }
        if (sObjectMgr->IsReservedName(name) || !ObjectMgr::IsValidCharterName(name))
        {
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NAME_INVALID, name);
            return;
        }
    }
    else
    {
        if (sArenaTeamMgr->GetArenaTeamByName(name))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, name, "", ERR_ARENA_TEAM_NAME_EXISTS_S);
            return;
        }
        if (sObjectMgr->IsReservedName(name) || !ObjectMgr::IsValidCharterName(name))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, name, "", ERR_ARENA_TEAM_NAME_INVALID);
            return;
        }
    }

    ItemTemplate const *pProto = sObjectMgr->GetItemTemplate(charterid);
    if (!pProto)
    {
        _player->SendBuyError(BUY_ERR_CANT_FIND_ITEM, NULL, charterid, 0);
        return;
    }

    if (!_player->HasEnoughMoney(cost))
    {                                                       //player hasn't got enough money
        _player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, pCreature, charterid, 0);
        return;
    }

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, charterid, pProto->BuyCount);
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, NULL, NULL, charterid);
        return;
    }

    _player->ModifyMoney(-(int32)cost);
    Item *charter = _player->StoreNewItem(dest, charterid, true);
    if (!charter)
        return;

    charter->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1, charter->GetGUIDLow());
    // ITEM_FIELD_ENCHANTMENT_1_1 is guild/arenateam id
    // ITEM_FIELD_ENCHANTMENT_1_1+1 is current signatures count (showed on item)
    charter->SetState(ITEM_CHANGED, _player);
    _player->SendNewItem(charter, 1, true, false);

    // a petition is invalid, if both the owner and the type matches
    // we checked above, if this player is in an arenateam, so this must be
    // datacorruption
    QueryResult result = CharacterDatabase.PQuery("SELECT petitionguid FROM petition WHERE ownerguid = '%u'  AND type = '%u'", _player->GetGUIDLow(), type);

    std::ostringstream ssInvalidPetitionGUIDs;

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            ssInvalidPetitionGUIDs << "'" << fields[0].GetUInt32() << "' , ";
        } while (result->NextRow());
    }

    // delete petitions with the same guid as this one
    ssInvalidPetitionGUIDs << "'" << charter->GetGUIDLow() << "'";

    sLog->outDebug(LOG_FILTER_NETWORKIO, "Invalid petition GUIDs: %s", ssInvalidPetitionGUIDs.str().c_str());
    CharacterDatabase.escape_string(name);
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM petition WHERE petitionguid IN (%s)",  ssInvalidPetitionGUIDs.str().c_str());
    trans->PAppend("DELETE FROM petition_sign WHERE petitionguid IN (%s)", ssInvalidPetitionGUIDs.str().c_str());
    trans->PAppend("INSERT INTO petition (ownerguid, petitionguid, name, type) VALUES ('%u', '%u', '%s', '%u')",
        _player->GetGUIDLow(), charter->GetGUIDLow(), name.c_str(), type);
    CharacterDatabase.CommitTransaction(trans);
}

void WorldSession::HandlePetitionShowSignOpcode(WorldPacket & recv_data)
{
                                                            // ok
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_PETITION_SHOW_SIGNATURES");
    //recv_data.hexlike();

    uint8 signs = 0;
    uint64 petitionguid;
    recv_data >> petitionguid;                              // petition guid

    // solve (possible) some strange compile problems with explicit use GUID_LOPART(petitionguid) at some GCC versions (wrong code optimization in compiler?)
    uint32 petitionguid_low = GUID_LOPART(petitionguid);

    QueryResult result = CharacterDatabase.PQuery("SELECT type FROM petition WHERE petitionguid = '%u'", petitionguid_low);
    if (!result)
    {
        sLog->outError("Petition %u is not found for player %u %s", GUID_LOPART(petitionguid), GetPlayer()->GetGUIDLow(), GetPlayer()->GetName());
        return;
    }
    Field *fields = result->Fetch();
    uint32 type = fields[0].GetUInt8();

    // if guild petition and has guild => error, return;
    if (type == GUILD_CHARTER_TYPE && _player->GetGuildId())
        return;

    result = CharacterDatabase.PQuery("SELECT playerguid FROM petition_sign WHERE petitionguid = '%u'", petitionguid_low);

    // result == NULL also correct in case no sign yet
    if (result)
        signs = uint8(result->GetRowCount());

    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_PETITION_SHOW_SIGNATURES petition entry: '%u'", petitionguid_low);

    WorldPacket data(SMSG_PETITION_SHOW_SIGNATURES, (8+8+4+1+signs*12));
    data << uint64(petitionguid);                           // petition guid
    data << uint64(_player->GetGUID());                     // owner guid
    data << uint32(petitionguid_low);                       // guild guid
    data << uint8(signs);                                   // sign's count

    for (uint8 i = 1; i <= signs; ++i)
    {
        Field *fields2 = result->Fetch();
        uint64 plguid = fields2[0].GetUInt64();

        data << uint64(plguid);                             // Player GUID
        data << uint32(0);                                  // there 0 ...

        result->NextRow();
    }
    SendPacket(&data);
}

void WorldSession::HandlePetitionQueryOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_PETITION_QUERY");   // ok
    //recv_data.hexlike();

    uint32 guildguid;
    uint64 petitionguid;
    recv_data >> guildguid;                                 // in Trinity always same as GUID_LOPART(petitionguid)
    recv_data >> petitionguid;                              // petition guid
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_PETITION_QUERY Petition GUID %u Guild GUID %u", GUID_LOPART(petitionguid), guildguid);

    SendPetitionQueryOpcode(petitionguid);
}

void WorldSession::SendPetitionQueryOpcode(uint64 petitionguid)
{
    uint64 ownerguid = 0;
    uint32 type;
    std::string name = "NO_NAME_FOR_GUID";
    uint8 signs = 0;

    QueryResult result = CharacterDatabase.PQuery(
        "SELECT ownerguid, name, "
        "  (SELECT COUNT(playerguid) FROM petition_sign WHERE petition_sign.petitionguid = '%u') AS signs, "
        "  type "
        "FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionguid), GUID_LOPART(petitionguid));

    if (result)
    {
        Field* fields = result->Fetch();
        ownerguid = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);
        name      = fields[1].GetString();
        signs     = fields[2].GetUInt8();
        type      = fields[3].GetUInt32();
    }
    else
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_PETITION_QUERY failed for petition (GUID: %u)", GUID_LOPART(petitionguid));
        return;
    }

    WorldPacket data(SMSG_PETITION_QUERY_RESPONSE, (4+8+name.size()+1+1+4*12+2+10));
    data << uint32(GUID_LOPART(petitionguid));              // guild/team guid (in Trinity always same as GUID_LOPART(petition guid)
    data << uint64(ownerguid);                              // charter owner guid
    data << name;                                           // name (guild/arena team)
    data << uint8(0);                                       // some string
    if (type == GUILD_CHARTER_TYPE)
    {
        data << uint32(9);
        data << uint32(9);
        data << uint32(0);                                  // bypass client - side limitation, a different value is needed here for each petition
    }
    else
    {
        data << uint32(type-1);
        data << uint32(type-1);
        data << uint32(type);                               // bypass client - side limitation, a different value is needed here for each petition
    }
    data << uint32(0);                                      // 5
    data << uint32(0);                                      // 6
    data << uint32(0);                                      // 7
    data << uint32(0);                                      // 8
    data << uint16(0);                                      // 9 2 bytes field
    data << uint32(0);                                      // 10
    data << uint32(0);                                      // 11
    data << uint32(0);                                      // 13 count of next strings?

    for (int i = 0; i < 10; ++i)
        data << uint8(0);                                   // some string

    data << uint32(0);                                      // 14

    if (type == GUILD_CHARTER_TYPE)
        data << uint32(0);                                  // 15 0 - guild, 1 - arena team
    else
        data << uint32(1);

    SendPacket(&data);
}

void WorldSession::HandlePetitionRenameOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode MSG_PETITION_RENAME");   // ok
    //recv_data.hexlike();

    uint64 petitionguid;
    uint32 type;
    std::string newname;

    recv_data >> petitionguid;                              // guid
    recv_data >> newname;                                   // new name

    Item *item = _player->GetItemByGuid(petitionguid);
    if (!item)
        return;

    QueryResult result = CharacterDatabase.PQuery("SELECT type FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionguid));

    if (result)
    {
        Field* fields = result->Fetch();
        type = fields[0].GetUInt8();
    }
    else
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_PETITION_QUERY failed for petition (GUID: %u)", GUID_LOPART(petitionguid));
        return;
    }

    if (type == GUILD_CHARTER_TYPE)
    {
        if (sGuildMgr->GetGuildByName(newname))
        {
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NAME_EXISTS_S, newname);
            return;
        }
        if (sObjectMgr->IsReservedName(newname) || !ObjectMgr::IsValidCharterName(newname))
        {
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NAME_INVALID, newname);
            return;
        }
    }
    else
    {
        if (sArenaTeamMgr->GetArenaTeamByName(newname))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, newname, "", ERR_ARENA_TEAM_NAME_EXISTS_S);
            return;
        }
        if (sObjectMgr->IsReservedName(newname) || !ObjectMgr::IsValidCharterName(newname))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, newname, "", ERR_ARENA_TEAM_NAME_INVALID);
            return;
        }
    }

    std::string db_newname = newname;
    CharacterDatabase.escape_string(db_newname);
    CharacterDatabase.PExecute("UPDATE petition SET name = '%s' WHERE petitionguid = '%u'",
        db_newname.c_str(), GUID_LOPART(petitionguid));

    sLog->outDebug(LOG_FILTER_NETWORKIO, "Petition (GUID: %u) renamed to '%s'", GUID_LOPART(petitionguid), newname.c_str());
    WorldPacket data(MSG_PETITION_RENAME, (8+newname.size()+1));
    data << uint64(petitionguid);
    data << newname;
    SendPacket(&data);
}

void WorldSession::HandlePetitionSignOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_PETITION_SIGN");    // ok
    //recv_data.hexlike();

    Field *fields;
    uint64 petitionguid;
    uint8 unk;
    recv_data >> petitionguid;                              // petition guid
    recv_data >> unk;

    QueryResult result = CharacterDatabase.PQuery(
        "SELECT ownerguid, "
        "  (SELECT COUNT(playerguid) FROM petition_sign WHERE petition_sign.petitionguid = '%u') AS signs, "
        "  type "
        "FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionguid), GUID_LOPART(petitionguid));

    if (!result)
    {
        sLog->outError("Petition %u is not found for player %u %s", GUID_LOPART(petitionguid), GetPlayer()->GetGUIDLow(), GetPlayer()->GetName());
        return;
    }

    fields = result->Fetch();
    uint64 ownerguid = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);
    uint8 signs = fields[1].GetUInt8();
    uint32 type = fields[2].GetUInt32();

    uint32 plguidlo = _player->GetGUIDLow();
    if (GUID_LOPART(ownerguid) == plguidlo)
        return;

    // not let enemies sign guild charter
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != sObjectMgr->GetPlayerTeamByGUID(ownerguid))
    {
        if (type != GUILD_CHARTER_TYPE)
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        else
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (type != GUILD_CHARTER_TYPE)
    {
        if (_player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", _player->GetName(), ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
            return;
        }

        uint8 slot = ArenaTeam::GetSlotByType(type);
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
            Guild::SendCommandResult(this, GUILD_INVITE_S, ERR_ALREADY_IN_GUILD_S, _player->GetName());
            return;
        }
        if (_player->GetGuildIdInvited())
        {
            Guild::SendCommandResult(this, GUILD_INVITE_S, ERR_ALREADY_INVITED_TO_GUILD_S, _player->GetName());
            return;
        }
    }

    if (++signs > type)                                        // client signs maximum
        return;

    //client doesn't allow to sign petition two times by one character, but not check sign by another character from same account
    //not allow sign another player from already sign player account
    result = CharacterDatabase.PQuery("SELECT playerguid FROM petition_sign WHERE player_account = '%u' AND petitionguid = '%u'", GetAccountId(), GUID_LOPART(petitionguid));

    if (result)
    {
        WorldPacket data(SMSG_PETITION_SIGN_RESULTS, (8+8+4));
        data << uint64(petitionguid);
        data << uint64(_player->GetGUID());
        data << (uint32)PETITION_SIGN_ALREADY_SIGNED;

        // close at signer side
        SendPacket(&data);

        // update for owner if online
        if (Player *owner = sObjectMgr->GetPlayer(ownerguid))
            owner->GetSession()->SendPacket(&data);
        return;
    }

    CharacterDatabase.PExecute("INSERT INTO petition_sign (ownerguid, petitionguid, playerguid, player_account) VALUES ('%u', '%u', '%u', '%u')", GUID_LOPART(ownerguid), GUID_LOPART(petitionguid), plguidlo, GetAccountId());

    sLog->outDebug(LOG_FILTER_NETWORKIO, "PETITION SIGN: GUID %u by player: %s (GUID: %u Account: %u)", GUID_LOPART(petitionguid), _player->GetName(), plguidlo, GetAccountId());

    WorldPacket data(SMSG_PETITION_SIGN_RESULTS, (8+8+4));
    data << uint64(petitionguid);
    data << uint64(_player->GetGUID());
    data << uint32(PETITION_SIGN_OK);

    // close at signer side
    SendPacket(&data);

    // update signs count on charter, required testing...
    //Item *item = _player->GetItemByGuid(petitionguid));
    //if (item)
    //    item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1+1, signs);

    // update for owner if online
    if (Player *owner = sObjectMgr->GetPlayer(ownerguid))
        owner->GetSession()->SendPacket(&data);
}

void WorldSession::HandlePetitionDeclineOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode MSG_PETITION_DECLINE");  // ok
    //recv_data.hexlike();

    uint64 petitionguid;
    uint64 ownerguid;
    recv_data >> petitionguid;                              // petition guid
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Petition %u declined by %u", GUID_LOPART(petitionguid), _player->GetGUIDLow());

    QueryResult result = CharacterDatabase.PQuery("SELECT ownerguid FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionguid));
    if (!result)
        return;

    Field *fields = result->Fetch();
    ownerguid = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);

    Player *owner = sObjectMgr->GetPlayer(ownerguid);
    if (owner)                                               // petition owner online
    {
        WorldPacket data(MSG_PETITION_DECLINE, 8);
        data << uint64(_player->GetGUID());
        owner->GetSession()->SendPacket(&data);
    }
}

void WorldSession::HandleOfferPetitionOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_OFFER_PETITION");   // ok
    //recv_data.hexlike();

    uint8 signs = 0;
    uint64 petitionguid, plguid;
    uint32 type, junk;
    Player* player;
    recv_data >> junk;                                      // this is not petition type!
    recv_data >> petitionguid;                              // petition guid
    recv_data >> plguid;                                    // player guid

    player = ObjectAccessor::FindPlayer(plguid);
    if (!player)
        return;

    QueryResult result = CharacterDatabase.PQuery("SELECT type FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionguid));
    if (!result)
        return;

    Field *fields = result->Fetch();
    type = fields[0].GetUInt8();

    sLog->outDebug(LOG_FILTER_NETWORKIO, "OFFER PETITION: type %u, GUID1 %u, to player id: %u", type, GUID_LOPART(petitionguid), GUID_LOPART(plguid));

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        if (type != GUILD_CHARTER_TYPE)
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        else
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (type != GUILD_CHARTER_TYPE)
    {
        if (player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            // player is too low level to join an arena team
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
            return;
        }

        uint8 slot = ArenaTeam::GetSlotByType(type);
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
            Guild::SendCommandResult(this, GUILD_INVITE_S, ERR_ALREADY_IN_GUILD_S, _player->GetName());
            return;
        }

        if (player->GetGuildIdInvited())
        {
            Guild::SendCommandResult(this, GUILD_INVITE_S, ERR_ALREADY_INVITED_TO_GUILD_S, _player->GetName());
            return;
        }
    }

    result = CharacterDatabase.PQuery("SELECT playerguid FROM petition_sign WHERE petitionguid = '%u'", GUID_LOPART(petitionguid));
    // result == NULL also correct charter without signs
    if (result)
        signs = uint8(result->GetRowCount());

    WorldPacket data(SMSG_PETITION_SHOW_SIGNATURES, (8+8+4+signs+signs*12));
    data << uint64(petitionguid);                           // petition guid
    data << uint64(_player->GetGUID());                     // owner guid
    data << uint32(GUID_LOPART(petitionguid));              // guild guid
    data << uint8(signs);                                   // sign's count

    for (uint8 i = 1; i <= signs; ++i)
    {
        Field *fields2 = result->Fetch();
        plguid = fields2[0].GetUInt64();

        data << uint64(plguid);                             // Player GUID
        data << uint32(0);                                  // there 0 ...

        result->NextRow();
    }

    player->GetSession()->SendPacket(&data);
}

void WorldSession::HandleTurnInPetitionOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received opcode CMSG_TURN_IN_PETITION");

    // Get petition guid from packet
    WorldPacket data;
    uint64 petitionGuid;

    recv_data >> petitionGuid;

    // Check if player really has the required petition charter
    Item* item = _player->GetItemByGuid(petitionGuid);
    if (!item)
        return;

    sLog->outDebug(LOG_FILTER_NETWORKIO, "Petition %u turned in by %u", GUID_LOPART(petitionGuid), _player->GetGUIDLow());

    // Get petition data from db
    uint32 ownerguidlo;
    uint32 type;
    std::string name;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_LOAD_PETITION);
    stmt->setUInt32(0, GUID_LOPART(petitionGuid));
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        Field *fields = result->Fetch();
        ownerguidlo = fields[0].GetUInt32();
        name = fields[1].GetString();
        type = fields[2].GetUInt8();
    }
    else
    {
        sLog->outError("Player %s (guid: %u) tried to turn in petition (guid: %u) that is not present in the database", _player->GetName(), _player->GetGUIDLow(), GUID_LOPART(petitionGuid));
        return;
    }

    // Only the petition owner can turn in the petition
    if (_player->GetGUIDLow() != ownerguidlo)
        return;

    // Petition type (guild/arena) specific checks
    if (type == GUILD_CHARTER_TYPE)
    {
        // Check if player is already in a guild
        if (_player->GetGuildId())
        {
            data.Initialize(SMSG_TURN_IN_PETITION_RESULTS, 4);
            data << (uint32)PETITION_TURN_ALREADY_IN_GUILD;
            _player->GetSession()->SendPacket(&data);
            return;
        }

        // Check if guild name is already taken
        if (sGuildMgr->GetGuildByName(name))
        {
            Guild::SendCommandResult(this, GUILD_CREATE_S, ERR_GUILD_NAME_EXISTS_S, name);
            return;
        }
    }
    else
    {
        // Check for valid arena bracket (2v2, 3v3, 5v5)
        uint8 slot = ArenaTeam::GetSlotByType(type);
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

    // Get petition signatures from db
    uint8 signatures;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_LOAD_PETITION_SIGNATURE);
    stmt->setUInt32(0, GUID_LOPART(petitionGuid));
    result = CharacterDatabase.Query(stmt);

    if (result)
        signatures = uint8(result->GetRowCount());
    else
        signatures = 0;

    uint32 requiredSignatures;
    if (type == GUILD_CHARTER_TYPE)
        requiredSignatures = sWorld->getIntConfig(CONFIG_MIN_PETITION_SIGNS);
    else
        requiredSignatures = type-1;

    // Notify player if signatures are missing
    if (signatures < requiredSignatures)
    {
        data.Initialize(SMSG_TURN_IN_PETITION_RESULTS, 4);
        data << (uint32)PETITION_TURN_NEED_MORE_SIGNATURES;
        SendPacket(&data);
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

        // Add members from signatures
        for (uint8 i = 0; i < signatures; ++i)
        {
            Field* fields = result->Fetch();
            guild->AddMember(MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER));
            result->NextRow();
        }
    }
    else
    {
        // Receive the rest of the packet in arena team creation case
        uint32 background, icon, iconcolor, border, bordercolor;
        recv_data >> background >> icon >> iconcolor >> border >> bordercolor;

        // Create arena team
        ArenaTeam* arenaTeam = new ArenaTeam();

        if (!arenaTeam->Create(GUID_LOPART(_player->GetGUID()), type, name, background, icon, iconcolor, border, bordercolor))
        {
            delete arenaTeam;
            return;
        }

        // Register arena team
        sArenaTeamMgr->AddArenaTeam(arenaTeam);
        sLog->outDebug(LOG_FILTER_NETWORKIO, "PetitonsHandler: Arena team (guid: %u) added to ObjectMgr", arenaTeam->GetId());

        // Add members
        for (uint8 i = 0; i < signatures; ++i)
        {
            Field* fields = result->Fetch();
            uint32 memberGUID = fields[0].GetUInt32();
            sLog->outDebug(LOG_FILTER_NETWORKIO, "PetitionsHandler: Adding arena team (guid: %u) member %u", arenaTeam->GetId(), memberGUID);
            arenaTeam->AddMember(MAKE_NEW_GUID(memberGUID, 0, HIGHGUID_PLAYER));
            result->NextRow();
        }
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM petition WHERE petitionguid = '%u'", GUID_LOPART(petitionGuid));
    trans->PAppend("DELETE FROM petition_sign WHERE petitionguid = '%u'", GUID_LOPART(petitionGuid));
    CharacterDatabase.CommitTransaction(trans);

    // created
    sLog->outDebug(LOG_FILTER_NETWORKIO, "TURN IN PETITION GUID %u", GUID_LOPART(petitionGuid));

    data.Initialize(SMSG_TURN_IN_PETITION_RESULTS, 4);
    data << (uint32)PETITION_TURN_OK;
    SendPacket(&data);
}

void WorldSession::HandlePetitionShowListOpcode(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Received CMSG_PETITION_SHOWLIST");

    uint64 guid;
    recv_data >> guid;

    SendPetitionShowList(guid);
}

void WorldSession::SendPetitionShowList(uint64 guid)
{
    Creature *pCreature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_PETITIONER);
    if (!pCreature)
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: HandlePetitionShowListOpcode - Unit (GUID: %u) not found or you can't interact with him.", uint32(GUID_LOPART(guid)));
        return;
    }

    WorldPacket data(SMSG_PETITION_SHOWLIST, 8+1+4*6);
    data << guid;                                           // npc guid

    if (pCreature->isTabardDesigner())
    {
        data << uint8(1);                                   // count
        data << uint32(1);                                  // index
        data << uint32(GUILD_CHARTER);                      // charter entry
        data << uint32(CHARTER_DISPLAY_ID);                 // charter display id
        data << uint32(GUILD_CHARTER_COST);                 // charter cost
        data << uint32(0);                                  // unknown
        data << uint32(9);                                  // required signs?
    }
    else
    {
        data << uint8(3);                                   // count
        // 2v2
        data << uint32(1);                                  // index
        data << uint32(ARENA_TEAM_CHARTER_2v2);             // charter entry
        data << uint32(CHARTER_DISPLAY_ID);                 // charter display id
        data << uint32(ARENA_TEAM_CHARTER_2v2_COST);        // charter cost
        data << uint32(2);                                  // unknown
        data << uint32(2);                                  // required signs?
        // 3v3
        data << uint32(2);                                  // index
        data << uint32(ARENA_TEAM_CHARTER_3v3);             // charter entry
        data << uint32(CHARTER_DISPLAY_ID);                 // charter display id
        data << uint32(ARENA_TEAM_CHARTER_3v3_COST);        // charter cost
        data << uint32(3);                                  // unknown
        data << uint32(3);                                  // required signs?
        // 5v5
        data << uint32(3);                                  // index
        data << uint32(ARENA_TEAM_CHARTER_5v5);             // charter entry
        data << uint32(CHARTER_DISPLAY_ID);                 // charter display id
        data << uint32(ARENA_TEAM_CHARTER_5v5_COST);        // charter cost
        data << uint32(5);                                  // unknown
        data << uint32(5);                                  // required signs?
    }

    SendPacket(&data);
    sLog->outDebug(LOG_FILTER_NETWORKIO, "Sent SMSG_PETITION_SHOWLIST");
}
