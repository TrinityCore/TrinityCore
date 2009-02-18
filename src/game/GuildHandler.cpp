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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Guild.h"
#include "MapManager.h"
#include "GossipDef.h"
#include "SocialMgr.h"

void WorldSession::HandleGuildQueryOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 4);

    uint32 guildId;
    Guild *guild;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_QUERY");

    recvPacket >> guildId;

    guild = objmgr.GetGuildById(guildId);
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    guild->Query(this);
}

void WorldSession::HandleGuildCreateOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string gname;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_CREATE");

    recvPacket >> gname;

    if(GetPlayer()->GetGuildId())
        return;

    Guild *guild = new Guild;
    if(!guild->create(GetPlayer()->GetGUID(),gname))
    {
        delete guild;
        return;
    }

    objmgr.AddGuild(guild);
}

void WorldSession::HandleGuildInviteOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string Invitedname, plname;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_INVITE");

    Player * player = NULL;

    recvPacket >> Invitedname;

    if(normalizePlayerName(Invitedname))
        player = ObjectAccessor::Instance().FindPlayerByName(Invitedname.c_str());

    if(!player)
    {
        SendGuildCommandResult(GUILD_INVITE_S, Invitedname, GUILD_PLAYER_NOT_FOUND);
        return;
    }

    Guild *guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    // OK result but not send invite
    if(player->GetSocial()->HasIgnore(GetPlayer()->GetGUIDLow()))
        return;

    // not let enemies sign guild charter
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != GetPlayer()->GetTeam())
    {
        SendGuildCommandResult(GUILD_INVITE_S, Invitedname, GUILD_NOT_ALLIED);
        return;
    }

    if(player->GetGuildId())
    {
        plname = player->GetName();
        SendGuildCommandResult(GUILD_INVITE_S, plname, ALREADY_IN_GUILD);
        return;
    }

    if(player->GetGuildIdInvited())
    {
        plname = player->GetName();
        SendGuildCommandResult(GUILD_INVITE_S, plname, ALREADY_INVITED_TO_GUILD);
        return;
    }

    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_INVITE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    sLog.outDebug("Player %s Invited %s to Join his Guild", GetPlayer()->GetName(), Invitedname.c_str());

    player->SetGuildIdInvited(GetPlayer()->GetGuildId());
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_INVITE_PLAYER, GetPlayer()->GetGUIDLow(), player->GetGUIDLow(), 0);

    WorldPacket data(SMSG_GUILD_INVITE, (8+10));            // guess size
    data << GetPlayer()->GetName();
    data << guild->GetName();
    player->GetSession()->SendPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_INVITE)");
}

void WorldSession::HandleGuildRemoveOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string plName;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_REMOVE");

    recvPacket >> plName;

    if(!normalizePlayerName(plName))
        return;

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_REMOVE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);
    if(!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if(slot->RankId == GR_GUILDMASTER)
    {
        SendGuildCommandResult(GUILD_QUIT_S, "", GUILD_LEADER_LEAVE);
        return;
    }

    guild->DelMember(plGuid);
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), 0);

    WorldPacket data(SMSG_GUILD_EVENT, (2+20));             // guess size
    data << (uint8)GE_REMOVED;
    data << (uint8)2;                                       // strings count
    data << plName;
    data << GetPlayer()->GetName();
    guild->BroadcastPacket(&data);
}

void WorldSession::HandleGuildAcceptOpcode(WorldPacket& /*recvPacket*/)
{
    Guild *guild;
    Player *player = GetPlayer();

    //sLog.outDebug("WORLD: Received CMSG_GUILD_ACCEPT");

    guild = objmgr.GetGuildById(player->GetGuildIdInvited());
    if(!guild || player->GetGuildId())
        return;

    // not let enemies sign guild charter
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != objmgr.GetPlayerTeamByGUID(guild->GetLeader()))
        return;

    if(!guild->AddMember(GetPlayer()->GetGUID(),guild->GetLowestRank()))
        return;
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_JOIN_GUILD, GetPlayer()->GetGUIDLow(), 0, 0);

    WorldPacket data(SMSG_GUILD_EVENT, (2+10));             // guess size
    data << (uint8)GE_JOINED;
    data << (uint8)1;
    data << player->GetName();
    guild->BroadcastPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_EVENT)");
}

void WorldSession::HandleGuildDeclineOpcode(WorldPacket& /*recvPacket*/)
{
    //sLog.outDebug("WORLD: Received CMSG_GUILD_DECLINE");

    GetPlayer()->SetGuildIdInvited(0);
    GetPlayer()->SetInGuild(0);
}

void WorldSession::HandleGuildInfoOpcode(WorldPacket& /*recvPacket*/)
{
    Guild *guild;
    //sLog.outDebug("WORLD: Received CMSG_GUILD_INFO");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    WorldPacket data(SMSG_GUILD_INFO, (5*4 + guild->GetName().size() + 1));
    data << guild->GetName();
    data << guild->GetCreatedDay();
    data << guild->GetCreatedMonth();
    data << guild->GetCreatedYear();
    data << guild->GetMemberSize();
    data << guild->GetMemberSize();

    SendPacket(&data);
}

void WorldSession::HandleGuildRosterOpcode(WorldPacket& /*recvPacket*/)
{
    //sLog.outDebug("WORLD: Received CMSG_GUILD_ROSTER");

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
        return;

    guild->Roster(this);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string plName;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_PROMOTE");

    recvPacket >> plName;

    if(!normalizePlayerName(plName))
        return;

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_PROMOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if(!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if(plGuid == GetPlayer()->GetGUID())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_NAME_INVALID);
        return;
    }

    if(slot->RankId < 2 || (slot->RankId-1) < GetPlayer()->GetRank())
        return;

    uint32 newRankId = slot->RankId < guild->GetNrRanks() ? slot->RankId-1 : guild->GetNrRanks()-1;

    guild->ChangeRank(plGuid, newRankId);
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_PROMOTE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), newRankId);

    WorldPacket data(SMSG_GUILD_EVENT, (2+30));             // guess size
    data << (uint8)GE_PROMOTION;
    data << (uint8)3;
    data << GetPlayer()->GetName();
    data << plName;
    data << guild->GetRankName(newRankId);
    guild->BroadcastPacket(&data);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string plName;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_DEMOTE");

    recvPacket >> plName;

    if(!normalizePlayerName(plName))
        return;

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());

    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_DEMOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if(plGuid == GetPlayer()->GetGUID())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_NAME_INVALID);
        return;
    }

    if((slot->RankId+1) >= guild->GetNrRanks() || slot->RankId <= GetPlayer()->GetRank())
        return;

    guild->ChangeRank(plGuid, (slot->RankId+1));
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_DEMOTE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), (slot->RankId));

    WorldPacket data(SMSG_GUILD_EVENT, (2+30));             // guess size
    data << (uint8)GE_DEMOTION;
    data << (uint8)3;
    data << GetPlayer()->GetName();
    data << plName;
    data << guild->GetRankName(slot->RankId);
    guild->BroadcastPacket(&data);
}

void WorldSession::HandleGuildLeaveOpcode(WorldPacket& /*recvPacket*/)
{
    std::string plName;
    Guild *guild;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_LEAVE");

    guild = objmgr.GetGuildById(_player->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    if(_player->GetGUID() == guild->GetLeader() && guild->GetMemberSize() > 1)
    {
        SendGuildCommandResult(GUILD_QUIT_S, "", GUILD_LEADER_LEAVE);
        return;
    }

    if(_player->GetGUID() == guild->GetLeader())
    {
        guild->Disband();
        return;
    }

    plName = _player->GetName();

    guild->DelMember(_player->GetGUID());
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_LEAVE_GUILD, _player->GetGUIDLow(), 0, 0);

    WorldPacket data(SMSG_GUILD_EVENT, (2+10));             // guess size
    data << (uint8)GE_LEFT;
    data << (uint8)1;
    data << plName;
    guild->BroadcastPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_EVENT)");

    SendGuildCommandResult(GUILD_QUIT_S, guild->GetName(), GUILD_PLAYER_NO_MORE_IN_GUILD);
}

void WorldSession::HandleGuildDisbandOpcode(WorldPacket& /*recvPacket*/)
{
    std::string name;
    Guild *guild;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_DISBAND");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    if(GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    guild->Disband();

    //sLog.outDebug("WORLD: Guild Sucefully Disbanded");
}

void WorldSession::HandleGuildLeaderOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string name;
    Player *oldLeader = GetPlayer();
    Guild *guild;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_LEADER");

    recvPacket >> name;

    if(!normalizePlayerName(name))
        return;

    guild = objmgr.GetGuildById(oldLeader->GetGuildId());

    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if( oldLeader->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 newLeaderGUID;
    MemberSlot* slot = guild->GetMemberSlot(name, newLeaderGUID);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, name, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    guild->SetLeader(newLeaderGUID);
    guild->ChangeRank(oldLeader->GetGUID(), GR_OFFICER);

    WorldPacket data(SMSG_GUILD_EVENT, (2+20));             // guess size
    data << (uint8)GE_LEADER_CHANGED;
    data << (uint8)2;
    data << oldLeader->GetName();
    data << name.c_str();
    guild->BroadcastPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_EVENT)");
}

void WorldSession::HandleGuildMOTDOpcode(WorldPacket& recvPacket)
{
    Guild *guild;
    std::string MOTD;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_MOTD");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_SETMOTD))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    if(!recvPacket.empty())
        recvPacket >> MOTD;
    else
        MOTD = "";

    guild->SetMOTD(MOTD);

    WorldPacket data(SMSG_GUILD_EVENT, (2+MOTD.size()+1));
    data << (uint8)GE_MOTD;
    data << (uint8)1;
    data << MOTD;
    guild->BroadcastPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_EVENT)");
}

void WorldSession::HandleGuildSetPublicNoteOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string name,PNOTE;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_SET_PUBLIC_NOTE");

    recvPacket >> name;

    if(!normalizePlayerName(name))
        return;

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_EPNOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(name, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, name, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    recvPacket >> PNOTE;
    guild->SetPNOTE(plGuid, PNOTE);

    guild->Roster(this);
}

void WorldSession::HandleGuildSetOfficerNoteOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string plName, OFFNOTE;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_SET_OFFICER_NOTE");

    recvPacket >> plName;

    if(!normalizePlayerName(plName))
        return;

    Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_EOFFNOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    recvPacket >> OFFNOTE;
    guild->SetOFFNOTE(plGuid, OFFNOTE);

    guild->Roster(this);
}

void WorldSession::HandleGuildRankOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 4+4+1+4*13);
    //recvPacket.hexlike();

    Guild *guild;
    std::string rankname;
    uint32 rankId;
    uint32 rights, MoneyPerDay;
    uint32 BankRights;
    uint32 BankSlotPerDay;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_RANK");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    else if(GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    recvPacket >> rankId;
    recvPacket >> rights;
    recvPacket >> rankname;
    recvPacket >> MoneyPerDay;

    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        recvPacket >> BankRights;
        recvPacket >> BankSlotPerDay;
        guild->SetBankRightsAndSlots(rankId, uint8(i), uint16(BankRights & 0xFF), uint16(BankSlotPerDay), true);
    }
    sLog.outDebug("WORLD: Changed RankName to %s , Rights to 0x%.4X", rankname.c_str(), rights);

    guild->SetBankMoneyPerDay(rankId, MoneyPerDay);
    guild->SetRankName(rankId, rankname);

    if(rankId==GR_GUILDMASTER)                              // prevent loss leader rights
        rights |= GR_RIGHT_ALL;

    guild->SetRankRights(rankId, rights);

    guild->Query(this);
    guild->Roster(this);
}

void WorldSession::HandleGuildAddRankOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    Guild *guild;
    std::string rankname;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_ADD_RANK");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if(GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    if(guild->GetNrRanks() >= GUILD_MAX_RANKS)              // client not let create more 10 than ranks
        return;

    recvPacket >> rankname;

    guild->CreateRank(rankname, GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);

    guild->Query(this);
    guild->Roster(this);
}

void WorldSession::HandleGuildDelRankOpcode(WorldPacket& /*recvPacket*/)
{
    Guild *guild;
    std::string rankname;

    //sLog.outDebug("WORLD: Received CMSG_GUILD_DEL_RANK");

    guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    else if(GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", GUILD_PERMISSIONS);
        return;
    }

    guild->DelRank();

    guild->Query(this);
    guild->Roster(this);
}

void WorldSession::SendGuildCommandResult(uint32 typecmd, const std::string& str,uint32 cmdresult)
{
    WorldPacket data(SMSG_GUILD_COMMAND_RESULT, (8+str.size()+1));
    data << typecmd;
    data << str;
    data << cmdresult;
    SendPacket(&data);

    //sLog.outDebug("WORLD: Sent (SMSG_GUILD_COMMAND_RESULT)");
}

void WorldSession::HandleGuildChangeInfoOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 1);

    //sLog.outDebug("WORLD: Received CMSG_GUILD_INFO_TEXT");

    std::string GINFO;

    recvPacket >> GINFO;

    Guild *guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if(!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_MODIFY_GUILD_INFO))
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", GUILD_PERMISSIONS);
        return;
    }

    guild->SetGINFO(GINFO);
}

void WorldSession::HandleGuildSaveEmblemOpcode(WorldPacket& recvPacket)
{
    CHECK_PACKET_SIZE(recvPacket, 8+4+4+4+4+4);

    //sLog.outDebug("WORLD: Received MSG_SAVE_GUILD_EMBLEM");

    uint64 vendorGuid;

    uint32 EmblemStyle;
    uint32 EmblemColor;
    uint32 BorderStyle;
    uint32 BorderColor;
    uint32 BackgroundColor;

    recvPacket >> vendorGuid;

    Creature *pCreature = ObjectAccessor::GetNPCIfCanInteractWith(*_player, vendorGuid,UNIT_NPC_FLAG_TABARDDESIGNER);
    if (!pCreature)
    {
        //"That's not an emblem vendor!"
        SendSaveGuildEmblem(ERR_GUILDEMBLEM_INVALIDVENDOR);
        sLog.outDebug("WORLD: HandleGuildSaveEmblemOpcode - Unit (GUID: %u) not found or you can't interact with him.", GUID_LOPART(vendorGuid));
        return;
    }

    // remove fake death
    if(GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    recvPacket >> EmblemStyle;
    recvPacket >> EmblemColor;
    recvPacket >> BorderStyle;
    recvPacket >> BorderColor;
    recvPacket >> BackgroundColor;

    Guild *guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
    if(!guild)
    {
        //"You are not part of a guild!";
        SendSaveGuildEmblem(ERR_GUILDEMBLEM_NOGUILD);
        return;
    }

    if (guild->GetLeader() != GetPlayer()->GetGUID())
    {
        //"Only guild leaders can create emblems."
        SendSaveGuildEmblem(ERR_GUILDEMBLEM_NOTGUILDMASTER);
        return;
    }

    if(GetPlayer()->GetMoney() < 10*GOLD)
    {
        //"You can't afford to do that."
        SendSaveGuildEmblem(ERR_GUILDEMBLEM_NOTENOUGHMONEY);
        return;
    }

    GetPlayer()->ModifyMoney(-10*GOLD);
    guild->SetEmblem(EmblemStyle, EmblemColor, BorderStyle, BorderColor, BackgroundColor);

    //"Guild Emblem saved."
    SendSaveGuildEmblem(ERR_GUILDEMBLEM_SUCCESS);

    guild->Query(this);
}

void WorldSession::HandleGuildEventLogOpcode(WorldPacket& /* recvPacket */)
{
                                                            // empty
    sLog.outDebug("WORLD: Received (MSG_GUILD_EVENT_LOG_QUERY)");
    //recvPacket.hexlike();

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    pGuild->DisplayGuildEventlog(this);
}

/******  GUILD BANK  *******/

void WorldSession::HandleGuildBankGetMoneyAmount( WorldPacket & /* recv_data */ )
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_MONEY_WITHDRAWN)");
    //recv_data.hexlike();

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());
}

void WorldSession::HandleGuildBankGetRights( WorldPacket& /* recv_data */ )
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_PERMISSIONS)");

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    uint32 rankId = GetPlayer()->GetRank();

    WorldPacket data(MSG_GUILD_PERMISSIONS, 4*15+1);
    data << uint32(rankId);                                 // guild rank id
    data << uint32(pGuild->GetRankRights(rankId));          // rank rights
                                                            // money per day left
    data << uint32(pGuild->GetMemberMoneyWithdrawRem(GetPlayer()->GetGUIDLow()));
    data << uint8(pGuild->GetPurchasedTabs());              // tabs count
    for(int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        data << uint32(pGuild->GetBankRights(rankId, uint8(i)));
        data << uint32(pGuild->GetMemberSlotWithdrawRem(GetPlayer()->GetGUIDLow(), uint8(i)));
    }
    SendPacket(&data);
    sLog.outDebug("WORLD: Sent (MSG_GUILD_PERMISSIONS)");
}

/* Called when clicking on Guild bank gameobject */
void WorldSession::HandleGuildBankQuery( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANKER_ACTIVATE)");
    CHECK_PACKET_SIZE(recv_data,8+1);
    uint64 GoGuid;
    uint8  unk;
    recv_data >> GoGuid >> unk;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    if (uint32 GuildId = GetPlayer()->GetGuildId())
    {
        if(Guild *pGuild = objmgr.GetGuildById(GuildId))
        {
            pGuild->DisplayGuildBankTabsInfo(this);
            return;
        }
    }

    SendGuildCommandResult(GUILD_BANK_S, "", GUILD_PLAYER_NOT_IN_GUILD);
}

/* Called when opening guild bank tab only (first one) */
void WorldSession::HandleGuildBankTabColon( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_QUERY_TAB)");
    CHECK_PACKET_SIZE(recv_data,8+1+1);
    uint64 GoGuid;
    uint8 TabId,unk1;
    recv_data >> GoGuid >> TabId >> unk1;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    // Let's update the amount of gold the player can withdraw before displaying the content
    // This is usefull if money withdraw right has changed
    pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());

    pGuild->DisplayGuildBankContent(this, TabId);
}

void WorldSession::HandleGuildBankDeposit( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_DEPOSIT_MONEY)");
    CHECK_PACKET_SIZE(recv_data,8+4);
    uint64 GoGuid;
    uint32 money;
    recv_data >> GoGuid >> money;

    if (!money)
        return;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    if (GetPlayer()->GetMoney() < money)
        return;

    CharacterDatabase.BeginTransaction();

    pGuild->SetBankMoney(pGuild->GetGuildBankMoney()+money);
    GetPlayer()->ModifyMoney(-int(money));
    GetPlayer()->SaveDataFieldToDB();                       //contains money

    CharacterDatabase.CommitTransaction();

    // logging money
    if(_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
    {
        sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit money (Amount: %u) to guild bank (Guild ID %u)",
            _player->GetName(),_player->GetSession()->GetAccountId(),money,GuildId);
    }

    // log
    pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), GetPlayer()->GetGUIDLow(), money);

    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this, 0);
    pGuild->DisplayGuildBankMoneyUpdate();
}

void WorldSession::HandleGuildBankWithdraw( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_WITHDRAW_MONEY)");
    CHECK_PACKET_SIZE(recv_data,8+4);
    uint64 GoGuid;
    uint32 money;
    recv_data >> GoGuid >> money;

    if (!money)
        return;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    if (pGuild->GetGuildBankMoney()<money)                  // not enough money in bank
        return;

    if (!pGuild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_WITHDRAW_GOLD))
        return;

    CharacterDatabase.BeginTransaction();

    if (!pGuild->MemberMoneyWithdraw(money, GetPlayer()->GetGUIDLow()))
    {
        CharacterDatabase.RollbackTransaction();
        return;
    }

    GetPlayer()->ModifyMoney(money);
    GetPlayer()->SaveDataFieldToDB();                       // contains money

    CharacterDatabase.CommitTransaction();

    // Log
    pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_MONEY, uint8(0), GetPlayer()->GetGUIDLow(), money);

    pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());
    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this, 0);
    pGuild->DisplayGuildBankMoneyUpdate();
}

void WorldSession::HandleGuildBankDepositItem( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_SWAP_ITEMS)");
    //recv_data.hexlike();

    uint64 GoGuid;
    uint8 BankToBank;

    uint8 BankTab, BankTabSlot, AutoStore, AutoStoreCount, PlayerSlot, PlayerBag, SplitedAmount = 0;
    uint8 BankTabDst, BankTabSlotDst, unk2, ToChar = 1;
    uint32 ItemEntry, unk1;
    bool BankToChar = false;

    CHECK_PACKET_SIZE(recv_data,8+1);
    recv_data >> GoGuid >> BankToBank;
    if (BankToBank)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1+1+4+1+1+4+1+1);
        recv_data >> BankTabDst;
        recv_data >> BankTabSlotDst;
        recv_data >> unk1;                                  // always 0
        recv_data >> BankTab;
        recv_data >> BankTabSlot;
        recv_data >> ItemEntry;
        recv_data >> unk2;                                  // always 0
        recv_data >> SplitedAmount;

        if (BankTabSlotDst >= GUILD_BANK_MAX_SLOTS)
            return;
        if (BankTabDst == BankTab && BankTabSlotDst == BankTabSlot)
            return;
    }
    else
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1+1+4+1);
        recv_data >> BankTab;
        recv_data >> BankTabSlot;
        recv_data >> ItemEntry;
        recv_data >> AutoStore;
        if (AutoStore)
        {
            // recheck
            CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1);
            recv_data >> AutoStoreCount;
        }
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1+1);
        recv_data >> PlayerBag;
        recv_data >> PlayerSlot;
        if (!AutoStore)
        {
            // recheck
            CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+1+1);
            recv_data >> ToChar;
            recv_data >> SplitedAmount;
        }

        if (BankTabSlot >= GUILD_BANK_MAX_SLOTS && BankTabSlot != 0xFF)
            return;
    }

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    Player *pl = GetPlayer();

    // Bank <-> Bank
    if (BankToBank)
    {
        // empty operation
        if(BankTab==BankTabDst && BankTabSlot==BankTabSlotDst)
            return;

        Item *pItemSrc = pGuild->GetItem(BankTab, BankTabSlot);
        if (!pItemSrc)                                      // may prevent crash
            return;

        if(SplitedAmount > pItemSrc->GetCount())
            return;                                         // cheating?
        else if(SplitedAmount == pItemSrc->GetCount())
            SplitedAmount = 0;                              // no split

        Item *pItemDst = pGuild->GetItem(BankTabDst, BankTabSlotDst);

        if(BankTab!=BankTabDst)
        {
            // check dest pos rights (if different tabs)
            if(!pGuild->IsMemberHaveRights(pl->GetGUIDLow(), BankTabDst, GUILD_BANK_RIGHT_DEPOSIT_ITEM))
                return;

            // check source pos rights (if different tabs)
            uint32 remRight = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTab);
            if(remRight <= 0)
                return;
        }

        if (SplitedAmount)
        {                                                   // Bank -> Bank item split (in empty or non empty slot
            GuildItemPosCountVec dest;
            uint8 msg = pGuild->CanStoreItem(BankTabDst,BankTabSlotDst,dest,SplitedAmount,pItemSrc,false);
            if( msg != EQUIP_ERR_OK )
            {
                pl->SendEquipError( msg, pItemSrc, NULL );
                return;
            }

            Item *pNewItem = pItemSrc->CloneItem( SplitedAmount );
            if( !pNewItem )
            {
                pl->SendEquipError( EQUIP_ERR_ITEM_NOT_FOUND, pItemSrc, NULL );
                return;
            }

            CharacterDatabase.BeginTransaction();
            pGuild->LogBankEvent(GUILD_BANK_LOG_MOVE_ITEM, BankTab, pl->GetGUIDLow(), pItemSrc->GetEntry(), SplitedAmount, BankTabDst);

            pl->ItemRemovedQuestCheck( pItemSrc->GetEntry(), SplitedAmount );
            pItemSrc->SetCount( pItemSrc->GetCount() - SplitedAmount );
            pItemSrc->FSetState(ITEM_CHANGED);
            pItemSrc->SaveToDB();                           // not in inventory and can be save standalone
            pGuild->StoreItem(BankTabDst,dest,pNewItem);
            CharacterDatabase.CommitTransaction();
        }
        else                                                // non split
        {
            GuildItemPosCountVec gDest;
            uint8 msg = pGuild->CanStoreItem(BankTabDst,BankTabSlotDst,gDest,pItemSrc->GetCount(),pItemSrc,false);
            if( msg == EQUIP_ERR_OK )                       // merge to
            {
                CharacterDatabase.BeginTransaction();
                pGuild->LogBankEvent(GUILD_BANK_LOG_MOVE_ITEM, BankTab,    pl->GetGUIDLow(), pItemSrc->GetEntry(), pItemSrc->GetCount(), BankTabDst);

                pGuild->RemoveItem(BankTab, BankTabSlot);
                pGuild->StoreItem(BankTabDst, gDest, pItemSrc);
                CharacterDatabase.CommitTransaction();
            }
            else                                            // swap
            {
                gDest.clear();
                uint8 msg = pGuild->CanStoreItem(BankTabDst,BankTabSlotDst,gDest,pItemSrc->GetCount(),pItemSrc,true);
                if( msg != EQUIP_ERR_OK )
                {
                    pl->SendEquipError( msg, pItemSrc, NULL );
                    return;
                }

                GuildItemPosCountVec gSrc;
                msg = pGuild->CanStoreItem(BankTab,BankTabSlot,gSrc,pItemDst->GetCount(),pItemDst,true);
                if( msg != EQUIP_ERR_OK )
                {
                    pl->SendEquipError( msg, pItemDst, NULL );
                    return;
                }

                if(BankTab!=BankTabDst)
                {
                    // check source pos rights (item swapped to src)
                    if(!pGuild->IsMemberHaveRights(pl->GetGUIDLow(), BankTab, GUILD_BANK_RIGHT_DEPOSIT_ITEM))
                        return;

                    // check dest pos rights (item swapped to src)
                    uint32 remRightDst = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTabDst);
                    if(remRightDst <= 0)
                        return;
                }

                CharacterDatabase.BeginTransaction();
                pGuild->LogBankEvent(GUILD_BANK_LOG_MOVE_ITEM, BankTab,    pl->GetGUIDLow(), pItemSrc->GetEntry(), pItemSrc->GetCount(), BankTabDst);
                pGuild->LogBankEvent(GUILD_BANK_LOG_MOVE_ITEM, BankTabDst, pl->GetGUIDLow(), pItemDst->GetEntry(), pItemDst->GetCount(), BankTab);

                pGuild->RemoveItem(BankTab, BankTabSlot);
                pGuild->RemoveItem(BankTabDst, BankTabSlotDst);
                pGuild->StoreItem(BankTab, gSrc, pItemDst);
                pGuild->StoreItem(BankTabDst, gDest, pItemSrc);
                CharacterDatabase.CommitTransaction();
            }
        }
        pGuild->DisplayGuildBankContentUpdate(BankTab,BankTabSlot,BankTab==BankTabDst ? BankTabSlotDst : -1);
        if(BankTab!=BankTabDst)
            pGuild->DisplayGuildBankContentUpdate(BankTabDst,BankTabSlotDst);
        return;
    }

    // Player <-> Bank

    // char->bank autostore click return BankTabSlot = 255 = NULL_SLOT
    // do similar for bank->char
    if(AutoStore && ToChar)
    {
        PlayerBag = NULL_BAG;
        PlayerSlot = NULL_SLOT;
    }

    // allow work with inventory only
    if(!Player::IsInventoryPos(PlayerBag,PlayerSlot) && !(PlayerBag == NULL_BAG && PlayerSlot == NULL_SLOT) )
    {
        _player->SendEquipError( EQUIP_ERR_NONE, NULL, NULL );
        return;
    }

    Item *pItemBank = pGuild->GetItem(BankTab, BankTabSlot);
    Item *pItemChar = GetPlayer()->GetItemByPos(PlayerBag, PlayerSlot);
    if (!pItemChar && !pItemBank)                           // Nothing to do
        return;

    if (!pItemChar && !ToChar)                              // Problem to get item from player
        return;

    if (!pItemBank && ToChar)                               // Problem to get bank item
        return;

    // BankToChar swap or char to bank remaining

    if (ToChar)                                             // Bank -> Char cases
    {
        if(SplitedAmount > pItemBank->GetCount())
            return;                                         // cheating?
        else if(SplitedAmount == pItemBank->GetCount())
            SplitedAmount = 0;                              // no split

        if (SplitedAmount)
        {                                                   // Bank -> Char split to slot (patly move)
            Item *pNewItem = pItemBank->CloneItem( SplitedAmount );
            if( !pNewItem )
            {
                pl->SendEquipError( EQUIP_ERR_ITEM_NOT_FOUND, pItemBank, NULL );
                return;
            }

            ItemPosCountVec dest;
            uint8 msg = pl->CanStoreItem(PlayerBag, PlayerSlot, dest, pNewItem, false);
            if( msg != EQUIP_ERR_OK )
            {
                pl->SendEquipError( msg, pNewItem, NULL );
                delete pNewItem;
                return;
            }

            // check source pos rights (item moved to inventory)
            uint32 remRight = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTab);
            if(remRight <= 0)
            {
                delete pNewItem;
                return;
            }

            CharacterDatabase.BeginTransaction();
            pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_ITEM, BankTab, pl->GetGUIDLow(), pItemBank->GetEntry(), SplitedAmount);

            pItemBank->SetCount(pItemBank->GetCount()-SplitedAmount);
            pItemBank->FSetState(ITEM_CHANGED);
            pItemBank->SaveToDB();                          // not in inventory and can be save standalone
            pl->MoveItemToInventory(dest,pNewItem,true);
            pl->SaveInventoryAndGoldToDB();

            pGuild->MemberItemWithdraw(BankTab, pl->GetGUIDLow());
            CharacterDatabase.CommitTransaction();
        }
        else                                                // Bank -> Char swap with slot (move)
        {
            ItemPosCountVec dest;
            uint8 msg = pl->CanStoreItem(PlayerBag, PlayerSlot, dest, pItemBank, false);
            if( msg == EQUIP_ERR_OK )                       // merge case
            {
                // check source pos rights (item moved to inventory)
                uint32 remRight = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTab);
                if(remRight <= 0)
                    return;

                CharacterDatabase.BeginTransaction();
                pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_ITEM, BankTab, pl->GetGUIDLow(), pItemBank->GetEntry(), pItemBank->GetCount());

                pGuild->RemoveItem(BankTab, BankTabSlot);
                pl->MoveItemToInventory(dest,pItemBank,true);
                pl->SaveInventoryAndGoldToDB();

                pGuild->MemberItemWithdraw(BankTab, pl->GetGUIDLow());
                CharacterDatabase.CommitTransaction();
            }
            else                                            // Bank <-> Char swap items
            {
                // check source pos rights (item swapped to bank)
                if(!pGuild->IsMemberHaveRights(pl->GetGUIDLow(), BankTab, GUILD_BANK_RIGHT_DEPOSIT_ITEM))
                    return;

                if(pItemChar)
                {
                    if(!pItemChar->CanBeTraded())
                    {
                        _player->SendEquipError( EQUIP_ERR_ITEMS_CANT_BE_SWAPPED, pItemChar, NULL );
                        return;
                    }
                }

                ItemPosCountVec iDest;
                msg = pl->CanStoreItem(PlayerBag, PlayerSlot, iDest, pItemBank, true);
                if( msg != EQUIP_ERR_OK )
                {
                    pl->SendEquipError( msg, pItemBank, NULL );
                    return;
                }

                GuildItemPosCountVec gDest;
                if(pItemChar)
                {
                    msg = pGuild->CanStoreItem(BankTab,BankTabSlot,gDest,pItemChar->GetCount(),pItemChar,true);
                    if( msg != EQUIP_ERR_OK )
                    {
                        pl->SendEquipError( msg, pItemChar, NULL );
                        return;
                    }
                }

                // check source pos rights (item moved to inventory)
                uint32 remRight = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTab);
                if(remRight <= 0)
                    return;

                if(pItemChar)
                {
                    // logging item move to bank
                    if(_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
                    {
                        sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank (Guild ID: %u )",
                            _player->GetName(),_player->GetSession()->GetAccountId(),
                            pItemChar->GetProto()->Name1,pItemChar->GetEntry(),pItemChar->GetCount(),
                            GuildId);
                    }
                }

                CharacterDatabase.BeginTransaction();
                pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_ITEM, BankTab, pl->GetGUIDLow(), pItemBank->GetEntry(), pItemBank->GetCount());
                if(pItemChar)
                    pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_ITEM, BankTab, pl->GetGUIDLow(), pItemChar->GetEntry(), pItemChar->GetCount());

                pGuild->RemoveItem(BankTab, BankTabSlot);
                if(pItemChar)
                {
                    pl->MoveItemFromInventory(PlayerBag, PlayerSlot, true);
                    pItemChar->DeleteFromInventoryDB();
                }

                if(pItemChar)
                    pGuild->StoreItem(BankTab, gDest, pItemChar);
                pl->MoveItemToInventory(iDest,pItemBank,true);
                pl->SaveInventoryAndGoldToDB();

                pGuild->MemberItemWithdraw(BankTab, pl->GetGUIDLow());
                CharacterDatabase.CommitTransaction();
            }
        }
        pGuild->DisplayGuildBankContentUpdate(BankTab,BankTabSlot);
        return;
    }                                                       // End "To char" part

    // Char -> Bank cases

    if(!pItemChar->CanBeTraded())
    {
        _player->SendEquipError( EQUIP_ERR_ITEMS_CANT_BE_SWAPPED, pItemChar, NULL );
        return;
    }

    // check source pos rights (item moved to bank)
    if(!pGuild->IsMemberHaveRights(pl->GetGUIDLow(), BankTab, GUILD_BANK_RIGHT_DEPOSIT_ITEM))
        return;

    if(SplitedAmount > pItemChar->GetCount())
        return;                                             // cheating?
    else if(SplitedAmount == pItemChar->GetCount())
        SplitedAmount = 0;                                  // no split

    if (SplitedAmount)
    {                                                       // Char -> Bank split to empty or non-empty slot (partly move)
        GuildItemPosCountVec dest;
        uint8 msg = pGuild->CanStoreItem(BankTab,BankTabSlot,dest,SplitedAmount,pItemChar,false);
        if( msg != EQUIP_ERR_OK )
        {
            pl->SendEquipError( msg, pItemChar, NULL );
            return;
        }

        Item *pNewItem = pItemChar->CloneItem( SplitedAmount );
        if( !pNewItem )
        {
            pl->SendEquipError( EQUIP_ERR_ITEM_NOT_FOUND, pItemChar, NULL );
            return;
        }

        // logging item move to bank (before items merge
        if(_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
        {
            sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank (Guild ID: %u )",
                _player->GetName(),_player->GetSession()->GetAccountId(),
                pItemChar->GetProto()->Name1,pItemChar->GetEntry(),SplitedAmount,GuildId);
        }

        CharacterDatabase.BeginTransaction();
        pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_ITEM, BankTab, pl->GetGUIDLow(), pItemChar->GetEntry(), SplitedAmount);

        pl->ItemRemovedQuestCheck( pItemChar->GetEntry(), SplitedAmount );
        pItemChar->SetCount(pItemChar->GetCount()-SplitedAmount);
        pItemChar->SetState(ITEM_CHANGED);
        pl->SaveInventoryAndGoldToDB();
        pGuild->StoreItem(BankTab, dest, pNewItem);
        CharacterDatabase.CommitTransaction();

        pGuild->DisplayGuildBankContentUpdate(BankTab,dest);
    }
    else                                                    // Char -> Bank swap with empty or non-empty (move)
    {
        GuildItemPosCountVec dest;
        uint8 msg = pGuild->CanStoreItem(BankTab,BankTabSlot,dest,pItemChar->GetCount(),pItemChar,false);
        if( msg == EQUIP_ERR_OK )                           // merge
        {
            // logging item move to bank
            if(_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
            {
                sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank (Guild ID: %u )",
                    _player->GetName(),_player->GetSession()->GetAccountId(),
                    pItemChar->GetProto()->Name1,pItemChar->GetEntry(),pItemChar->GetCount(),
                    GuildId);
            }

            CharacterDatabase.BeginTransaction();
            pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_ITEM, BankTab, pl->GetGUIDLow(), pItemChar->GetEntry(), pItemChar->GetCount());

            pl->MoveItemFromInventory(PlayerBag, PlayerSlot, true);
            pItemChar->DeleteFromInventoryDB();

            pGuild->StoreItem(BankTab,dest,pItemChar);
            pl->SaveInventoryAndGoldToDB();
            CharacterDatabase.CommitTransaction();

            pGuild->DisplayGuildBankContentUpdate(BankTab,dest);
        }
        else                                                // Char <-> Bank swap items (posible NULL bank item)
        {
            ItemPosCountVec iDest;
            if(pItemBank)
            {
                msg = pl->CanStoreItem(PlayerBag, PlayerSlot, iDest, pItemBank, true);
                if( msg != EQUIP_ERR_OK )
                {
                    pl->SendEquipError( msg, pItemBank, NULL );
                    return;
                }
            }

            GuildItemPosCountVec gDest;
            msg = pGuild->CanStoreItem(BankTab,BankTabSlot,gDest,pItemChar->GetCount(),pItemChar,true);
            if( msg != EQUIP_ERR_OK )
            {
                pl->SendEquipError( msg, pItemChar, NULL );
                return;
            }

            if(pItemBank)
            {
                // check bank pos rights (item swapped with inventory)
                uint32 remRight = pGuild->GetMemberSlotWithdrawRem(pl->GetGUIDLow(), BankTab);
                if(remRight <= 0)
                    return;
            }

            // logging item move to bank
            if(_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
            {
                sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank (Guild ID: %u )",
                    _player->GetName(),_player->GetSession()->GetAccountId(),
                    pItemChar->GetProto()->Name1,pItemChar->GetEntry(),pItemChar->GetCount(),
                    GuildId);
            }

            CharacterDatabase.BeginTransaction();
            if(pItemBank)
                pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_ITEM, BankTab, pl->GetGUIDLow(), pItemBank->GetEntry(), pItemBank->GetCount());
            pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_ITEM, BankTab, pl->GetGUIDLow(), pItemChar->GetEntry(), pItemChar->GetCount());

            pl->MoveItemFromInventory(PlayerBag, PlayerSlot, true);
            pItemChar->DeleteFromInventoryDB();
            if(pItemBank)
                pGuild->RemoveItem(BankTab, BankTabSlot);

            pGuild->StoreItem(BankTab,gDest,pItemChar);
            if(pItemBank)
                pl->MoveItemToInventory(iDest,pItemBank,true);
            pl->SaveInventoryAndGoldToDB();
            if(pItemBank)
                pGuild->MemberItemWithdraw(BankTab, pl->GetGUIDLow());
            CharacterDatabase.CommitTransaction();

            pGuild->DisplayGuildBankContentUpdate(BankTab,gDest);
        }
    }
}

void WorldSession::HandleGuildBankBuyTab( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_BUY_TAB)");
    CHECK_PACKET_SIZE(recv_data, 8+1);
    //recv_data.hexlike();
    uint64 GoGuid;
    uint8 TabId;

    recv_data >> GoGuid;
    recv_data >> TabId;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId==0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    uint32 TabCost = objmgr.GetGuildBankTabPrice(TabId) * GOLD;
    if (!TabCost)
        return;

    if (pGuild->GetPurchasedTabs() >= GUILD_BANK_MAX_TABS)
        return;

    if (TabId != pGuild->GetPurchasedTabs())                // purchased_tabs = 0 when buying Tab 0, that is why this check can be made
    {
        sLog.outError("Error: trying to buy a tab non contigous to owned ones");
        return;
    }

    if (GetPlayer()->GetMoney() < TabCost)                  // Should not happen, this is checked by client
        return;

    // Go on with creating tab
    pGuild->CreateNewBankTab();
    GetPlayer()->ModifyMoney(-int(TabCost));
    pGuild->SetBankMoneyPerDay(GetPlayer()->GetRank(), WITHDRAW_MONEY_UNLIMITED);
    pGuild->SetBankRightsAndSlots(GetPlayer()->GetRank(), TabId, GUILD_BANK_RIGHT_FULL, WITHDRAW_SLOT_UNLIMITED, true);
    pGuild->Roster(this);
    pGuild->DisplayGuildBankTabsInfo(this);
}

void WorldSession::HandleGuildBankModifyTab( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_UPDATE_TAB)");
    //recv_data.hexlike();
    CHECK_PACKET_SIZE(recv_data, 8+1+1+1);
    uint64 GoGuid;
    uint8 TabId;
    std::string Name;
    std::string IconIndex;

    recv_data >> GoGuid;
    recv_data >> TabId;
    recv_data >> Name;
    recv_data >> IconIndex;

    if(Name.empty())
        return;

    if(IconIndex.empty())
        return;

    if (!objmgr.IsGuildVaultGameObject(_player, GoGuid))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId==0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    pGuild->SetGuildBankTabInfo(TabId, Name, IconIndex);
    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this, TabId);
}

void WorldSession::HandleGuildBankLog( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_LOG_QUERY)");
    CHECK_PACKET_SIZE(recv_data, 1);

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    uint8 TabId;
    recv_data >> TabId;

    pGuild->DisplayGuildBankLogs(this, TabId);
}

void WorldSession::HandleGuildBankTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received MSG_QUERY_GUILD_BANK_TEXT");
    CHECK_PACKET_SIZE(recv_data, 1);

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    uint8 TabId;
    recv_data >> TabId;

    pGuild->SendGuildBankTabText(this, TabId);
}

void WorldSession::HandleGuildBankSetTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_SET_GUILD_BANK_TEXT");
    CHECK_PACKET_SIZE(recv_data, 1+1);

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = objmgr.GetGuildById(GuildId);
    if(!pGuild)
        return;

    uint8 TabId;
    std::string Text;
    recv_data >> TabId;
    recv_data >> Text;

    pGuild->SetGuildBankTabText(TabId, Text);
}

void WorldSession::SendSaveGuildEmblem( uint32 msg )
{
    WorldPacket data(MSG_SAVE_GUILD_EMBLEM, 4);
    data << uint32(msg);                                    // not part of guild
    SendPacket( &data );
}

