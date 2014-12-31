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

#include "ObjectMgr.h"                                      // for normalizePlayerName
#include "ChannelMgr.h"
#include "ChannelPackets.h"
#include "Player.h"
#include "WorldSession.h"

#include <cctype>

void WorldSession::HandleJoinChannel(WorldPackets::Channel::JoinChannel& packet)
{
    TC_LOG_DEBUG("chat.system", "CMSG_JOIN_CHANNEL %s ChatChannelId: %u, CreateVoiceSession: %u, Internal: %u, ChannelName: %s, Password: %s",
        GetPlayerInfo().c_str(), packet.ChatChannelId, packet.CreateVoiceSession, packet.Internal, packet.ChannelName.c_str(), packet.Password.c_str());

    if (packet.ChatChannelId)
    {
        ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(packet.ChatChannelId);
        if (!channel)
            return;

        AreaTableEntry const* zone = GetAreaEntryByAreaID(GetPlayer()->GetZoneId());
        if (!zone || !GetPlayer()->CanJoinConstantChannelInZone(channel, zone))
            return;
    }

    if (packet.ChannelName.empty())
        return;

    if (isdigit(packet.ChannelName[0]))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
    {
        cMgr->SetTeam(GetPlayer()->GetTeam());
        if (Channel* channel = cMgr->GetJoinChannel(packet.ChannelName, packet.ChatChannelId))
            channel->JoinChannel(GetPlayer(), packet.Password);
    }
}

void WorldSession::HandleLeaveChannel(WorldPackets::Channel::LeaveChannel& packet)
{
    TC_LOG_DEBUG("chat.system", "CMSG_LEAVE_CHANNEL %s ChannelName: %s, ZoneChannelID: %u",
        GetPlayerInfo().c_str(), packet.ChannelName.c_str(), packet.ZoneChannelID);

    if (packet.ChannelName.empty())
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
    {
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, GetPlayer()))
            channel->LeaveChannel(GetPlayer(), true);
        cMgr->LeftChannel(packet.ChannelName);
    }
}

void WorldSession::HandleChannelList(WorldPackets::Channel::ChannelListRequest& packet)
{
    TC_LOG_DEBUG("chat.system", "%s %s ChannelName: %s",
        GetOpcodeNameForLogging(packet.GetOpcode()).c_str(), GetPlayerInfo().c_str(), packet.ChannelName.c_str());

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, GetPlayer()))
            channel->List(GetPlayer());
}

void WorldSession::HandleChannelPassword(WorldPacket& recvPacket)
{
    uint32 nameLength = recvPacket.ReadBits(8);
    uint32 passLength = recvPacket.ReadBits(7);

    std::string channelName = recvPacket.ReadString(nameLength);
    std::string password = recvPacket.ReadString(passLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_PASSWORD %s Channel: %s, Password: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), password.c_str());

    if (password.length() > MAX_CHANNEL_PASS_STR)
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->Password(GetPlayer(), password);
}

void WorldSession::HandleChannelSetOwner(WorldPacket& recvPacket)
{
    uint32 channelLength = recvPacket.ReadBits(8);
    uint32 nameLength = recvPacket.ReadBits(7);

    std::string targetName = recvPacket.ReadString(nameLength);
    std::string channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_SET_OWNER %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->SetOwner(GetPlayer(), targetName);
}

void WorldSession::HandleChannelOwner(WorldPacket& recvPacket)
{
    uint32 length = recvPacket.ReadBits(8);
    std::string channelName = recvPacket.ReadString(length);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_OWNER %s Channel: %s",
        GetPlayerInfo().c_str(), channelName.c_str());

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->SendWhoOwner(GetPlayer());
}

void WorldSession::HandleChannelModerator(WorldPacket& recvPacket)
{
    uint32 channelLength = recvPacket.ReadBits(8);
    uint32 nameLength = recvPacket.ReadBits(7);

    std::string targetName = recvPacket.ReadString(nameLength);
    std::string channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_MODERATOR %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->SetModerator(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnmoderator(WorldPacket& recvPacket)
{
    uint32 nameLength = recvPacket.ReadBits(7);
    uint32 channelLength = recvPacket.ReadBits(8);

    std::string channelName = recvPacket.ReadString(channelLength);
    std::string targetName = recvPacket.ReadString(nameLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNMODERATOR %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->UnsetModerator(GetPlayer(), targetName);
}

void WorldSession::HandleChannelMute(WorldPacket& recvPacket)
{
    uint32 channelLength = recvPacket.ReadBits(8);
    uint32 nameLength = recvPacket.ReadBits(7);

    std::string channelName = recvPacket.ReadString(channelLength);
    std::string targetName = recvPacket.ReadString(nameLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_MUTE %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->SetMute(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnmute(WorldPacket& recvPacket)
{
    uint32 nameLength = recvPacket.ReadBits(8);
    uint32 channelLength = recvPacket.ReadBits(7);

    std::string targetName = recvPacket.ReadString(nameLength);
    std::string channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNMUTE %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->UnsetMute(GetPlayer(), targetName);
}

void WorldSession::HandleChannelInvite(WorldPacket& recvPacket)
{
    uint32 nameLength = recvPacket.ReadBits(7);
    uint32 channelLength = recvPacket.ReadBits(8);

    std::string targetName = recvPacket.ReadString(nameLength);
    std::string channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_INVITE %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->Invite(GetPlayer(), targetName);
}

void WorldSession::HandleChannelKick(WorldPacket& recvPacket)
{
    uint32 channelLength = recvPacket.ReadBits(8);
    uint32 nameLength = recvPacket.ReadBits(7);

    std::string channelName = recvPacket.ReadString(channelLength);
    std::string targetName = recvPacket.ReadString(nameLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_KICK %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->Kick(GetPlayer(), targetName);
}

void WorldSession::HandleChannelBan(WorldPacket& recvPacket)
{
    uint32 channelLength, nameLength;
    std::string channelName, targetName;

    channelLength = recvPacket.ReadBits(8);
    nameLength = recvPacket.ReadBits(7);

    targetName = recvPacket.ReadString(nameLength);
    channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_BAN %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->Ban(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnban(WorldPacket& recvPacket)
{
    uint32 channelLength = recvPacket.ReadBits(7);
    uint32 nameLength = recvPacket.ReadBits(8);

    std::string targetName = recvPacket.ReadString(nameLength);
    std::string channelName = recvPacket.ReadString(channelLength);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNBAN %s Channel: %s, Target: %s",
        GetPlayerInfo().c_str(), channelName.c_str(), targetName.c_str());

    if (!normalizePlayerName(targetName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->UnBan(GetPlayer(), targetName);
}

void WorldSession::HandleChannelAnnouncements(WorldPacket& recvPacket)
{
    uint32 length = recvPacket.ReadBits(8);
    std::string channelName = recvPacket.ReadString(length);

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_ANNOUNCEMENTS %s Channel: %s",
        GetPlayerInfo().c_str(), channelName.c_str());

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->Announce(GetPlayer());
}

void WorldSession::HandleGetChannelMemberCount(WorldPacket &recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_GET_CHANNEL_MEMBER_COUNT %s Channel: %s",
        GetPlayerInfo().c_str(), channelName.c_str());

    if (ChannelMgr* cMgr = ChannelMgr::ForTeam(GetPlayer()->GetTeam()))
    {
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
        {
            TC_LOG_DEBUG("chat.system", "SMSG_CHANNEL_MEMBER_COUNT %s Channel: %s Count: %u",
                GetPlayerInfo().c_str(), channelName.c_str(), channel->GetNumPlayers());

            WorldPacket data(SMSG_CHANNEL_MEMBER_COUNT, channel->GetName().size() + 1 + 4);
            data << channel->GetName();
            data << uint8(channel->GetFlags());
            data << uint32(channel->GetNumPlayers());
            SendPacket(&data);
        }
    }
}

void WorldSession::HandleSetChannelWatch(WorldPacket& recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_SET_CHANNEL_WATCH %s Channel: %s",
        GetPlayerInfo().c_str(), channelName.c_str());

    /*
    if (ChannelMgr* cMgr = channelMgr(GetPlayer()->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(channelName, GetPlayer()))
            channel->JoinNotify(GetPlayer());
    */
}
