/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "GossipDef.h"
#include "SocialMgr.h"

void WorldSession::HandleGuildQueryOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_QUERY");

    uint32 guildId;
    recvPacket >> guildId;

    if (Guild *guild = sObjectMgr.GetGuildById(guildId))
    {
        guild->Query(this);
        return;
    }

    SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

void WorldSession::HandleGuildCreateOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_CREATE");

    std::string gname;
    recvPacket >> gname;

    if (GetPlayer()->GetGuildId())                           // already in guild
        return;

    Guild *guild = new Guild;
    if (!guild->Create(GetPlayer(), gname))
    {
        delete guild;
        return;
    }

    sObjectMgr.AddGuild(guild);
}

void WorldSession::HandleGuildInviteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_INVITE");

    std::string Invitedname, plname;

    Player * player = NULL;
    recvPacket >> Invitedname;

    if (normalizePlayerName(Invitedname))
        player = sObjectAccessor.FindPlayerByName(Invitedname.c_str());

    if (!player)
    {
        SendGuildCommandResult(GUILD_INVITE_S, Invitedname, ERR_GUILD_PLAYER_NOT_FOUND_S);
        return;
    }

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    // OK result but not send invite
    if (player->GetSocial()->HasIgnore(GetPlayer()->GetGUIDLow()))
        return;

    // not let enemies sign guild charter
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != GetPlayer()->GetTeam())
    {
        SendGuildCommandResult(GUILD_INVITE_S, Invitedname, ERR_GUILD_NOT_ALLIED);
        return;
    }

    if (player->GetGuildId())
    {
        plname = player->GetName();
        SendGuildCommandResult(GUILD_INVITE_S, plname, ERR_ALREADY_IN_GUILD_S);
        return;
    }

    if (player->GetGuildIdInvited())
    {
        plname = player->GetName();
        SendGuildCommandResult(GUILD_INVITE_S, plname, ERR_ALREADY_INVITED_TO_GUILD_S);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_INVITE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
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

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_INVITE)");
}

void WorldSession::HandleGuildRemoveOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_REMOVE");

    std::string plName;
    recvPacket >> plName;

    if (!normalizePlayerName(plName))
        return;

    Guild* guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_REMOVE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);
    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if (slot->RankId == GR_GUILDMASTER)
    {
        SendGuildCommandResult(GUILD_QUIT_S, "", ERR_GUILD_LEADER_LEAVE);
        return;
    }

    //do not allow to kick player with same or higher rights
    if (GetPlayer()->GetRank() >= slot->RankId)
    {
        SendGuildCommandResult(GUILD_QUIT_S, plName, ERR_GUILD_RANK_TOO_HIGH_S);
        return;
    }

    guild->DelMember(plGuid, false, true);
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), 0);

    guild->BroadcastEvent(GE_REMOVED, 0, 2, plName, _player->GetName(), "");
}

void WorldSession::HandleGuildAcceptOpcode(WorldPacket& /*recvPacket*/)
{
    Guild *guild;
    Player *player = GetPlayer();

    sLog.outDebug("WORLD: Received CMSG_GUILD_ACCEPT");

    guild = sObjectMgr.GetGuildById(player->GetGuildIdInvited());
    if (!guild || player->GetGuildId())
        return;

    // not let enemies sign guild charter
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != sObjectMgr.GetPlayerTeamByGUID(guild->GetLeader()))
        return;

    if (!guild->AddMember(GetPlayer()->GetGUID(),guild->GetLowestRank()))
        return;
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_JOIN_GUILD, GetPlayer()->GetGUIDLow(), 0, 0);

    guild->BroadcastEvent(GE_JOINED, player->GetGUID(), 1, player->GetName(), "", "");

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_EVENT)");
}

void WorldSession::HandleGuildDeclineOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DECLINE");

    GetPlayer()->SetGuildIdInvited(0);
    GetPlayer()->SetInGuild(0);
}

void WorldSession::HandleGuildInfoOpcode(WorldPacket& /*recvPacket*/)
{
    Guild *guild;
    sLog.outDebug("WORLD: Received CMSG_GUILD_INFO");

    guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    WorldPacket data(SMSG_GUILD_INFO, (guild->GetName().size() + 4 + 4 + 4));
    data << guild->GetName();
    data << secsToTimeBitFields(guild->GetCreatedDate()); // 3.x (prev. year + month + day)
    data << guild->GetMemberSize();                 // char amount
    data << guild->GetAccountsNumber();             // amount of accounts

    SendPacket(&data);
}

void WorldSession::HandleGuildRosterOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_ROSTER");

    if (Guild* guild = sObjectMgr.GetGuildById(_player->GetGuildId()))
        guild->Roster(this);
}

void WorldSession::HandleGuildPromoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_PROMOTE");

    std::string plName;
    recvPacket >> plName;

    if (!normalizePlayerName(plName))
        return;

    Guild* guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_PROMOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if (plGuid == GetPlayer()->GetGUID())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_NAME_INVALID);
        return;
    }

    //allow to promote only to lower rank than member's rank
    //guildmaster's rank = 0
    //GetPlayer()->GetRank() + 1 is highest rank that current player can promote to
    if (GetPlayer()->GetRank() + 1 >= slot->RankId)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_RANK_TOO_HIGH_S);
        return;
    }

    uint32 newRankId = slot->RankId - 1;                    //when promoting player, rank is decreased

    guild->BroadcastEvent(GE_PROMOTION, 0, 3, _player->GetName(), plName, guild->GetRankName(newRankId));

    guild->ChangeRank(plGuid, newRankId);
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_PROMOTE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), newRankId);
}

void WorldSession::HandleGuildDemoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DEMOTE");

    std::string plName;
    recvPacket >> plName;

    if (!normalizePlayerName(plName))
        return;

    Guild* guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());

    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_DEMOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    if (plGuid == GetPlayer()->GetGUID())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_NAME_INVALID);
        return;
    }

    //do not allow to demote same or higher rank
    if (GetPlayer()->GetRank() >= slot->RankId)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_RANK_TOO_HIGH_S);
        return;
    }

    //do not allow to demote lowest rank
    if (slot->RankId >= guild->GetLowestRank())
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_RANK_TOO_LOW_S);
        return;
    }

    uint32 newRankId = slot->RankId + 1;                    //when demoting player, rank is increased

    guild->ChangeRank(plGuid, newRankId);
    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_DEMOTE_PLAYER, GetPlayer()->GetGUIDLow(), GUID_LOPART(plGuid), newRankId);

    guild->BroadcastEvent(GE_DEMOTION, 0, 3, _player->GetName(), plName, guild->GetRankName(slot->RankId));
}

void WorldSession::HandleGuildLeaveOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_LEAVE");

    Guild *guild = sObjectMgr.GetGuildById(_player->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (_player->GetGUID() == guild->GetLeader() && guild->GetMemberSize() > 1)
    {
        SendGuildCommandResult(GUILD_QUIT_S, "", ERR_GUILD_LEADER_LEAVE);
        return;
    }

    if (_player->GetGUID() == guild->GetLeader())
    {
        guild->Disband();
        return;
    }

    guild->DelMember(_player->GetGUID(), false, false);

    // Put record into guildlog
    guild->LogGuildEvent(GUILD_EVENT_LOG_LEAVE_GUILD, _player->GetGUIDLow(), 0, 0);

    guild->BroadcastEvent(GE_LEFT, _player->GetGUID(), 1, _player->GetName(), "", "");

    SendGuildCommandResult(GUILD_QUIT_S, guild->GetName(), ERR_PLAYER_NO_MORE_IN_GUILD);
}

void WorldSession::HandleGuildDisbandOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DISBAND");

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    guild->Disband();

    sLog.outDebug("WORLD: Guild Successfully Disbanded");
}

void WorldSession::HandleGuildLeaderOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_LEADER");

    std::string name;
    recvPacket >> name;

    Player *oldLeader = GetPlayer();

    if (!normalizePlayerName(name))
        return;

    Guild *guild = sObjectMgr.GetGuildById(oldLeader->GetGuildId());

    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (oldLeader->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 newLeaderGUID;
    MemberSlot* slot = guild->GetMemberSlot(name, newLeaderGUID);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, name, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    guild->SetLeader(newLeaderGUID);
    guild->ChangeRank(oldLeader->GetGUID(), GR_OFFICER);

    guild->BroadcastEvent(GE_LEADER_CHANGED, 0, 2, oldLeader->GetName(), name, "");
}

void WorldSession::HandleGuildMOTDOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_MOTD");

    std::string MOTD;

    if (!recvPacket.empty())
        recvPacket >> MOTD;
    else
        MOTD = "";

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_SETMOTD))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    guild->SetMOTD(MOTD);

    guild->BroadcastEvent(GE_MOTD, 0, 1, MOTD, "", "");
}

void WorldSession::HandleGuildSetPublicNoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_SET_PUBLIC_NOTE");

    std::string name,PNOTE;
    recvPacket >> name;

    if (!normalizePlayerName(name))
        return;

    Guild* guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_EPNOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(name, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, name, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    recvPacket >> PNOTE;
    guild->SetPNOTE(plGuid, PNOTE);

    guild->Roster(this);
}

void WorldSession::HandleGuildSetOfficerNoteOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_SET_OFFICER_NOTE");

    std::string plName, OFFNOTE;
    recvPacket >> plName;

    if (!normalizePlayerName(plName))
        return;

    Guild* guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_EOFFNOTE))
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    uint64 plGuid;
    MemberSlot* slot = guild->GetMemberSlot(plName, plGuid);

    if (!slot)
    {
        SendGuildCommandResult(GUILD_INVITE_S, plName, ERR_GUILD_PLAYER_NOT_IN_GUILD_S);
        return;
    }

    recvPacket >> OFFNOTE;
    guild->SetOFFNOTE(plGuid, OFFNOTE);

    guild->Roster(this);
}

void WorldSession::HandleGuildRankOpcode(WorldPacket& recvPacket)
{
    std::string rankname;
    uint32 rankId;
    uint32 rights, MoneyPerDay;

    sLog.outDebug("WORLD: Received CMSG_GUILD_RANK");

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        recvPacket.rpos(recvPacket.wpos());                 // set to end to avoid warnings spam
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    else if (GetPlayer()->GetGUID() != guild->GetLeader())
    {
        recvPacket.rpos(recvPacket.wpos());                 // set to end to avoid warnings spam
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    recvPacket >> rankId;
    recvPacket >> rights;
    recvPacket >> rankname;
    recvPacket >> MoneyPerDay;

    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        uint32 BankRights;
        uint32 BankSlotPerDay;

        recvPacket >> BankRights;
        recvPacket >> BankSlotPerDay;
        guild->SetBankRightsAndSlots(rankId, uint8(i), uint16(BankRights & 0xFF), uint16(BankSlotPerDay), true);
    }

    sLog.outDebug("WORLD: Changed RankName to %s , Rights to 0x%.4X", rankname.c_str(), rights);

    guild->SetBankMoneyPerDay(rankId, MoneyPerDay);
    guild->SetRankName(rankId, rankname);

    if (rankId == GR_GUILDMASTER)                           // prevent loss leader rights
        rights = GR_RIGHT_ALL;

    guild->SetRankRights(rankId, rights);

    guild->Query(this);
    guild->Roster();                                        // broadcast for tab rights update
}

void WorldSession::HandleGuildAddRankOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_ADD_RANK");

    std::string rankname;
    recvPacket >> rankname;

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    if (guild->GetRanksSize() >= GUILD_RANKS_MAX_COUNT)      // client not let create more 10 than ranks
        return;

    guild->CreateRank(rankname, GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);

    guild->Query(this);
    guild->Roster();                                        // broadcast for tab rights update
}

void WorldSession::HandleGuildDelRankOpcode(WorldPacket& /*recvPacket*/)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_DEL_RANK");

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }
    else if (GetPlayer()->GetGUID() != guild->GetLeader())
    {
        SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    guild->DelRank();

    guild->Query(this);
    guild->Roster();                                        // broadcast for tab rights update
}

void WorldSession::SendGuildCommandResult(uint32 typecmd, const std::string& str,uint32 cmdresult)
{
    WorldPacket data(SMSG_GUILD_COMMAND_RESULT, (8+str.size()+1));
    data << typecmd;
    data << str;
    data << cmdresult;
    SendPacket(&data);

    sLog.outDebug("WORLD: Sent (SMSG_GUILD_COMMAND_RESULT)");
}

void WorldSession::HandleGuildChangeInfoTextOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received CMSG_GUILD_INFO_TEXT");

    std::string GINFO;

    recvPacket >> GINFO;

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
        return;
    }

    if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_MODIFY_GUILD_INFO))
    {
        SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PERMISSIONS);
        return;
    }

    guild->SetGINFO(GINFO);
}

void WorldSession::HandleSaveGuildEmblemOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug("WORLD: Received MSG_SAVE_GUILD_EMBLEM");

    uint64 vendorGuid;

    uint32 EmblemStyle, EmblemColor, BorderStyle, BorderColor, BackgroundColor;

    recvPacket >> vendorGuid;
    recvPacket >> EmblemStyle >> EmblemColor >> BorderStyle >> BorderColor >> BackgroundColor;

    Creature *pCreature = GetPlayer()->GetNPCIfCanInteractWith(vendorGuid,UNIT_NPC_FLAG_TABARDDESIGNER);
    if (!pCreature)
    {
        //"That's not an emblem vendor!"
        SendSaveGuildEmblem(ERR_GUILDEMBLEM_INVALIDVENDOR);
        sLog.outDebug("WORLD: HandleSaveGuildEmblemOpcode - Unit (GUID: %u) not found or you can't interact with him.", GUID_LOPART(vendorGuid));
        return;
    }

    // remove fake death
    if (GetPlayer()->hasUnitState(UNIT_STAT_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Guild *guild = sObjectMgr.GetGuildById(GetPlayer()->GetGuildId());
    if (!guild)
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

    if (GetPlayer()->GetMoney() < 10*GOLD)
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

void WorldSession::HandleGuildEventLogQueryOpcode(WorldPacket& /* recvPacket */)
{
                                                            // empty
    sLog.outDebug("WORLD: Received (MSG_GUILD_EVENT_LOG_QUERY)");
    if (uint32 GuildId = GetPlayer()->GetGuildId())
        if (Guild *pGuild = sObjectMgr.GetGuildById(GuildId))
            pGuild->DisplayGuildEventLog(this);
}

/******  GUILD BANK  *******/

void WorldSession::HandleGuildBankMoneyWithdrawn(WorldPacket & /* recv_data */)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_MONEY_WITHDRAWN)");
    if (uint32 GuildId = GetPlayer()->GetGuildId())
        if (Guild *pGuild = sObjectMgr.GetGuildById(GuildId))
            pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());
}

void WorldSession::HandleGuildPermissions(WorldPacket& /* recv_data */)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_PERMISSIONS)");

    if (uint32 GuildId = GetPlayer()->GetGuildId())
    {
        if (Guild *pGuild = sObjectMgr.GetGuildById(GuildId))
        {
            uint32 rankId = GetPlayer()->GetRank();

            WorldPacket data(MSG_GUILD_PERMISSIONS, 4*15+1);
            data << uint32(rankId);                                 // guild rank id
            data << uint32(pGuild->GetRankRights(rankId));          // rank rights
            // money per day left
            data << uint32(pGuild->GetMemberMoneyWithdrawRem(GetPlayer()->GetGUIDLow()));
            data << uint8(pGuild->GetPurchasedTabs());              // tabs count
            // why sending all info when not all tabs are purchased???
    for (int i = 0; i < GUILD_BANK_MAX_TABS; ++i)
            {
                data << uint32(pGuild->GetBankRights(rankId, uint8(i)));
                data << uint32(pGuild->GetMemberSlotWithdrawRem(GetPlayer()->GetGUIDLow(), uint8(i)));
            }
            SendPacket(&data);
            sLog.outDebug("WORLD: Sent (MSG_GUILD_PERMISSIONS)");
        }
    }
}

/* Called when clicking on Guild bank gameobject */
void WorldSession::HandleGuildBankerActivate(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANKER_ACTIVATE)");

    uint64 GoGuid;
    uint8  unk;
    recv_data >> GoGuid >> unk;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    if (uint32 GuildId = GetPlayer()->GetGuildId())
    {
        if (Guild *pGuild = sObjectMgr.GetGuildById(GuildId))
        {
            pGuild->DisplayGuildBankTabsInfo(this);         // this also will load guild bank if not yet
            return;
        }
    }

    SendGuildCommandResult(GUILD_UNK1, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
}

/* Called when opening guild bank tab only (first one) */
void WorldSession::HandleGuildBankQueryTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_QUERY_TAB)");

    uint64 GoGuid;
    uint8 TabId, unk1;
    recv_data >> GoGuid >> TabId >> unk1;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (TabId >= pGuild->GetPurchasedTabs())
        return;

    // Let's update the amount of gold the player can withdraw before displaying the content
    // This is useful if money withdraw right has changed
    pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());
    pGuild->DisplayGuildBankContent(this, TabId);
}

void WorldSession::HandleGuildBankDepositMoney(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_DEPOSIT_MONEY)");

    uint64 GoGuid;
    uint32 money;
    recv_data >> GoGuid >> money;

    if (!money)
        return;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    if (GetPlayer()->GetMoney() < money)
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (!pGuild->GetPurchasedTabs())
        return;

    CharacterDatabase.BeginTransaction();

    pGuild->SetBankMoney(pGuild->GetGuildBankMoney()+money);
    GetPlayer()->ModifyMoney(-int(money));
    GetPlayer()->SaveGoldToDB();

    CharacterDatabase.CommitTransaction();

    // logging money
    if (_player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
    {
        sLog.outCommand(_player->GetSession()->GetAccountId(),"GM %s (Account: %u) deposit money (Amount: %u) to guild bank (Guild ID %u)",
            _player->GetName(),_player->GetSession()->GetAccountId(),money,GuildId);
    }

    // log
    pGuild->LogBankEvent(GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), GetPlayer()->GetGUIDLow(), money);

    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this, 0);
    pGuild->DisplayGuildBankMoneyUpdate(this);
}

void WorldSession::HandleGuildBankWithdrawMoney(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_WITHDRAW_MONEY)");

    uint64 GoGuid;
    uint32 money;
    recv_data >> GoGuid >> money;

    if (!money)
        return;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (GuildId == 0)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (!pGuild->GetPurchasedTabs())
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
    GetPlayer()->SaveGoldToDB();

    CharacterDatabase.CommitTransaction();

    // Log
    pGuild->LogBankEvent(GUILD_BANK_LOG_WITHDRAW_MONEY, uint8(0), GetPlayer()->GetGUIDLow(), money);

    pGuild->SendMoneyInfo(this, GetPlayer()->GetGUIDLow());
    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this,0);
    pGuild->DisplayGuildBankMoneyUpdate(this);
}

void WorldSession::HandleGuildBankSwapItems(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_SWAP_ITEMS)");

    uint64 GoGuid;
    uint8 BankToBank;

    uint8 BankTab, BankTabSlot, AutoStore;
    uint8 PlayerSlot = NULL_SLOT;
    uint8 PlayerBag = NULL_BAG;
    uint8 BankTabDst = 0, BankTabSlotDst = 0, unk2;
    uint8 ToChar = 1;
    uint32 ItemEntry, unk1;
    uint32 AutoStoreCount = 0;
    uint32 SplitedAmount = 0;

    recv_data >> GoGuid >> BankToBank;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
    {
        recv_data.rpos(recv_data.wpos());                   // prevent additional spam at rejected packet
        return;
    }

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
    {
        recv_data.rpos(recv_data.wpos());                   // prevent additional spam at rejected packet
        return;
    }

    if (BankToBank)
    {
        recv_data >> BankTabDst;
        recv_data >> BankTabSlotDst;
        recv_data >> unk1;                                  // always 0
        recv_data >> BankTab;
        recv_data >> BankTabSlot;
        recv_data >> ItemEntry;
        recv_data >> unk2;                                  // always 0
        recv_data >> SplitedAmount;

        if (BankTabSlotDst >= GUILD_BANK_MAX_SLOTS ||
            (BankTabDst == BankTab && BankTabSlotDst == BankTabSlot) ||
            BankTab >= pGuild->GetPurchasedTabs() ||
            BankTabDst >= pGuild->GetPurchasedTabs())
        {
            recv_data.rpos(recv_data.wpos());               // prevent additional spam at rejected packet
            return;
        }
    }
    else
    {
        recv_data >> BankTab;
        recv_data >> BankTabSlot;
        recv_data >> ItemEntry;
        recv_data >> AutoStore;
        if (AutoStore)
        {
            recv_data >> AutoStoreCount;
            recv_data.read_skip<uint8>();                   // ToChar (?), always and expected to be 1 (autostore only triggered in guild->ToChar)
            recv_data.read_skip<uint32>();                  // unknown, always 0
        }
        else
        {
            recv_data >> PlayerBag;
            recv_data >> PlayerSlot;
            recv_data >> ToChar;
            recv_data >> SplitedAmount;
        }

        if (BankTabSlot >= GUILD_BANK_MAX_SLOTS && BankTabSlot != 0xFF ||
            BankTab >= pGuild->GetPurchasedTabs())
        {
            recv_data.rpos(recv_data.wpos());               // prevent additional spam at rejected packet
            return;
        }
    }

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    if (BankTab >= pGuild->GetPurchasedTabs())
        return;

    // Bank <-> Bank
    if (BankToBank)
    {
        pGuild->SwapItems(_player, BankTab, BankTabSlot, BankTabDst, BankTabSlotDst, SplitedAmount);
        return;
    }

    // Player <-> Bank

    // allow work with inventory only
    if (!Player::IsInventoryPos(PlayerBag, PlayerSlot) && !(PlayerBag == NULL_BAG && PlayerSlot == NULL_SLOT))
    {
        _player->SendEquipError(EQUIP_ERR_NONE, NULL, NULL);
        return;
    }

    // BankToChar swap or char to bank remaining
    if (ToChar)                                             // Bank -> Char cases
        pGuild->MoveFromBankToChar(_player, BankTab, BankTabSlot, PlayerBag, PlayerSlot, SplitedAmount);
    else                                                    // Char -> Bank cases
        pGuild->MoveFromCharToBank(_player, PlayerBag, PlayerSlot, BankTab, BankTabSlot, SplitedAmount);
}

void WorldSession::HandleGuildBankBuyTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_BUY_TAB)");

    uint64 GoGuid;
    uint8 TabId;

    recv_data >> GoGuid;
    recv_data >> TabId;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    // m_PurchasedTabs = 0 when buying Tab 0, that is why this check can be made
    if (TabId != pGuild->GetPurchasedTabs())
        return;

    uint32 TabCost = GetGuildBankTabPrice(TabId) * GOLD;
    if (!TabCost)
        return;

    if (GetPlayer()->GetMoney() < TabCost)                  // Should not happen, this is checked by client
        return;

    // Go on with creating tab
    pGuild->CreateNewBankTab();
    GetPlayer()->ModifyMoney(-int(TabCost));
    pGuild->SetBankMoneyPerDay(GetPlayer()->GetRank(), WITHDRAW_MONEY_UNLIMITED);
    pGuild->SetBankRightsAndSlots(GetPlayer()->GetRank(), TabId, GUILD_BANK_RIGHT_FULL, WITHDRAW_SLOT_UNLIMITED, true);
    pGuild->Roster();                                       // broadcast for tab rights update
    pGuild->DisplayGuildBankTabsInfo(this);
}

void WorldSession::HandleGuildBankUpdateTab(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (CMSG_GUILD_BANK_UPDATE_TAB)");

    uint64 GoGuid;
    uint8 TabId;
    std::string Name;
    std::string IconIndex;

    recv_data >> GoGuid;
    recv_data >> TabId;
    recv_data >> Name;
    recv_data >> IconIndex;

    if (Name.empty())
        return;

    if (IconIndex.empty())
        return;

    if (!GetPlayer()->GetGameObjectIfCanInteractWith(GoGuid, GAMEOBJECT_TYPE_GUILD_BANK))
        return;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (TabId >= pGuild->GetPurchasedTabs())
        return;

    pGuild->SetGuildBankTabInfo(TabId, Name, IconIndex);
    pGuild->DisplayGuildBankTabsInfo(this);
    pGuild->DisplayGuildBankContent(this, TabId);
}

void WorldSession::HandleGuildBankLogQuery(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received (MSG_GUILD_BANK_LOG_QUERY)");

    uint8 TabId;
    recv_data >> TabId;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    // GUILD_BANK_MAX_TABS send by client for money log
    if (TabId >= pGuild->GetPurchasedTabs() && TabId != GUILD_BANK_MAX_TABS)
        return;

    pGuild->DisplayGuildBankLogs(this, TabId);
}

void WorldSession::HandleQueryGuildBankTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received MSG_QUERY_GUILD_BANK_TEXT");

    uint8 TabId;
    recv_data >> TabId;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (TabId >= pGuild->GetPurchasedTabs())
        return;

    pGuild->SendGuildBankTabText(this, TabId);
}

void WorldSession::HandleSetGuildBankTabText(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_SET_GUILD_BANK_TEXT");

    uint8 TabId;
    std::string Text;
    recv_data >> TabId;
    recv_data >> Text;

    uint32 GuildId = GetPlayer()->GetGuildId();
    if (!GuildId)
        return;

    Guild *pGuild = sObjectMgr.GetGuildById(GuildId);
    if (!pGuild)
        return;

    if (TabId >= pGuild->GetPurchasedTabs())
        return;

    pGuild->SetGuildBankTabText(TabId, Text);
}

void WorldSession::SendSaveGuildEmblem(uint32 msg)
{
    WorldPacket data(MSG_SAVE_GUILD_EMBLEM, 4);
    data << uint32(msg);                                    // not part of guild
    SendPacket(&data);
}
