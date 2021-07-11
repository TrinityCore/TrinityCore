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

#include "ObjectMgr.h"                                      // for normalizePlayerName
#include "ChannelMgr.h"
#include "Chat.h"
#include "World.h"

static size_t const MAX_CHANNEL_NAME_STR = 31;
static size_t const MAX_CHANNEL_PASS_STR = 127;
void WorldSession::HandleJoinChannelOpcode(WorldPacket& recvPacket)
{
    std::string channelname, pass;

void WorldSession::HandleJoinChannel(WorldPackets::Channel::JoinChannel& packet)
{
    TC_LOG_DEBUG("chat.system", "CMSG_JOIN_CHANNEL {} ChatChannelId: {}, CreateVoiceSession: {}, Internal: {}, ChannelName: {}, Password: {}",
        GetPlayerInfo(), packet.ChatChannelId, packet.CreateVoiceSession, packet.Internal, packet.ChannelName, packet.Password);
    recvPacket >> channelname;

    DEBUG_LOG("Opcode CMSG_JOIN_CHANNEL channel \"%s\"", channelname.c_str());

    if (channelname.empty())
        return;

    recvPacket >> pass;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetJoinChannel(channelname))
            chn->Join(player->GetObjectGuid(), pass.c_str());
    }

    if (player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_BOOL_GM_JOIN_OPPOSITE_FACTION_CHANNELS))
        if (ChannelMgr* cMgr = channelMgr(_player->GetTeam() == ALLIANCE ? HORDE : ALLIANCE))
            if (Channel *chn = cMgr->GetJoinChannel(channelname))
                if (!chn->GetSecurityLevel()) // Special both factions channel
                    chn->Join(player->GetObjectGuid(), pass.c_str());
}

void WorldSession::HandleLeaveChannelOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    // uint32 unk;
    std::string channelname;
    // recvPacket >> unk;                                      // channel id?
    recvPacket >> channelname;

    if (channelname.empty())
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Leave(player->GetObjectGuid(), true);

        cMgr->LeftChannel(channelname);
    }
    if (player->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_BOOL_GM_JOIN_OPPOSITE_FACTION_CHANNELS))
        if (ChannelMgr* cMgr = channelMgr(player->GetTeam() == ALLIANCE ? HORDE : ALLIANCE))
        {
            if (Channel *chn = cMgr->GetChannel(channelname, player))
                chn->Leave(player->GetObjectGuid(), true);
            cMgr->LeftChannel(channelname);
        }
}

void WorldSession::HandleChannelListOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname;
    recvPacket >> channelname;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->List(player);
    }
}

void WorldSession::HandleChannelPasswordOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, pass;
    recvPacket >> channelname;

    recvPacket >> pass;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Password(player->GetObjectGuid(), pass.c_str());
    } 
}

void WorldSession::HandleChannelSetOwnerOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();

    std::string channelname, newp;
    recvPacket >> channelname;

    recvPacket >> newp;

    if (!normalizePlayerName(newp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->SetOwner(player->GetObjectGuid(), newp.c_str());
    }
}

    ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam());
    if (!cMgr)
        return;

    if (packet.ChatChannelId)
    { // system channel
        if (Channel* channel = cMgr->GetSystemChannel(packet.ChatChannelId, zone))
            channel->JoinChannel(GetPlayer());
    }
    else
    { // custom channel
        if (packet.ChannelName.empty() || isdigit((unsigned char)packet.ChannelName[0]))
        {
            WorldPackets::Channel::ChannelNotify channelNotify;
            channelNotify.Type = CHAT_INVALID_NAME_NOTICE;
            channelNotify._Channel = packet.ChannelName;
            SendPacket(channelNotify.Write());
            return;
        }

        if (utf8length(packet.ChannelName) > MAX_CHANNEL_NAME_STR)
        {
            WorldPackets::Channel::ChannelNotify channelNotify;
            channelNotify.Type = CHAT_INVALID_NAME_NOTICE;
            channelNotify._Channel = packet.ChannelName;
            SendPacket(channelNotify.Write());
            TC_LOG_ERROR("network", "Player {} tried to create a channel with a name more than {} characters long - blocked", GetPlayer()->GetGUID().ToString(), MAX_CHANNEL_NAME_STR);
            return;
        }

        if (packet.Password.length() > MAX_CHANNEL_PASS_STR)
        {
            TC_LOG_ERROR("network", "Player {} tried to create a channel with a password more than {} characters long - blocked", GetPlayer()->GetGUID().ToString(), MAX_CHANNEL_PASS_STR);
            return;
        }
void WorldSession::HandleChannelOwnerOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname;
    recvPacket >> channelname;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->SendWhoOwner(player->GetObjectGuid());
    }
}

void WorldSession::HandleChannelModeratorOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

        if (!DisallowHyperlinksAndMaybeKick(packet.ChannelName))
            return;
    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->SetModerator(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelUnmoderatorOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

        if (Channel* channel = cMgr->GetCustomChannel(packet.ChannelName))
            channel->JoinChannel(GetPlayer(), packet.Password);
        else if (Channel* channel = cMgr->CreateCustomChannel(packet.ChannelName))
        {
            channel->SetPassword(packet.Password);
            channel->JoinChannel(GetPlayer(), packet.Password);
        }
    }
}
    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->UnsetModerator(player->GetObjectGuid(), otp.c_str());;
    } 
}

void WorldSession::HandleChannelMuteOpcode(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("chat.system", "CMSG_LEAVE_CHANNEL {} ChannelName: {}, ZoneChannelID: {}",
        GetPlayerInfo(), packet.ChannelName, packet.ZoneChannelID);
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->SetMute(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelUnmuteOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->UnsetMute(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelInviteOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (player->GetLevel() < sWorld.getConfig(CONFIG_UINT32_CHANNEL_INVITE_MIN_LEVEL))
        return;

        if (packet.ZoneChannelID)
            cMgr->LeftChannel(packet.ZoneChannelID, zone);
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Invite(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelKickOpcode(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("chat.system", "{} {} ChannelName: {}",
        GetOpcodeNameForLogging(packet.GetOpcode()), GetPlayerInfo(), packet.ChannelName);
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;
    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Kick(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelPlayerCommand(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR)
    {
        TC_LOG_DEBUG("chat.system", "{} {} ChannelName: {}, Name: {}, Name too long.",
            GetOpcodeNameForLogging(packet.GetOpcode()), GetPlayerInfo(), packet.ChannelName, packet.Name);
void WorldSession::HandleChannelBanOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Ban(player->GetObjectGuid(), otp.c_str());
    }
}

    TC_LOG_DEBUG("chat.system", "{} {} ChannelName: {}, Name: {}",
        GetOpcodeNameForLogging(packet.GetOpcode()), GetPlayerInfo(), packet.ChannelName, packet.Name);
void WorldSession::HandleChannelUnbanOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname, otp;
    recvPacket >> channelname;

    recvPacket >> otp;

    if (!normalizePlayerName(otp))
        return;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->UnBan(player->GetObjectGuid(), otp.c_str());
    }
}

void WorldSession::HandleChannelAnnouncementsOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname;
    recvPacket >> channelname;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        TC_LOG_DEBUG("chat.system", "{} {} ChannelName: {}, Password: {}, Password too long.",
            GetOpcodeNameForLogging(packet.GetOpcode()), GetPlayerInfo(), packet.ChannelName, packet.Password);
        return;
    }
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Announce(player->GetObjectGuid());
    }
}

    TC_LOG_DEBUG("chat.system", "{} {} ChannelName: {}, Password: {}",
        GetOpcodeNameForLogging(packet.GetOpcode()), GetPlayerInfo(), packet.ChannelName, packet.Password);
void WorldSession::HandleChannelModerateOpcode(WorldPacket& recvPacket)
{
    DEBUG_LOG("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    std::string channelname;
    recvPacket >> channelname;

    PlayerPointer player = GetPlayerPointer();
    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel *chn = cMgr->GetChannel(channelname, player))
            chn->Moderate(player->GetObjectGuid());
    }
}

