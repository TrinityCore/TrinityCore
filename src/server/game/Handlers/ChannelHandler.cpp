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
#include "Channel.h"
#include "ChannelMgr.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectMgr.h"                                      // for normalizePlayerName
#include "Player.h"
#include <cctype>

static size_t const MAX_CHANNEL_PASS_STR = 31;
static size_t const MAX_CHANNEL_NAME_STR = 31;

void WorldSession::HandleJoinChannel(WorldPacket& recvPacket)
{
    uint32 channelId;
    uint8 unknown1, unknown2;
    std::string channelName, password;

    recvPacket >> channelId >> unknown1 >> unknown2 >> channelName >> password;

    TC_LOG_DEBUG("chat.system", "CMSG_JOIN_CHANNEL {} Channel: {}, unk1: {}, unk2: {}, channel: {}, password: {}",
        GetPlayerInfo(), channelId, unknown1, unknown2, channelName, password);

    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(GetPlayer()->GetZoneId());
    if (channelId)
    {
        ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(channelId);
        if (!channel)
            return;

        if (!zone || !GetPlayer()->CanJoinConstantChannelInZone(channel, zone))
            return;
    }

    if (channelName.empty() || isdigit((unsigned char)channelName[0]))
    {
        WorldPacket data(SMSG_CHANNEL_NOTIFY, 1 + channelName.size());
        data << uint8(CHAT_INVALID_NAME_NOTICE) << channelName;
        SendPacket(&data);
        return;
    }

    if (password.length() > MAX_CHANNEL_PASS_STR)
    {
        TC_LOG_ERROR("network", "Player {} tried to create a channel with a password more than {} characters long - blocked", GetPlayer()->GetGUID().ToString(), MAX_CHANNEL_PASS_STR);
        return;
    }

    if (!DisallowHyperlinksAndMaybeKick(channelName))
        return;

    if (ChannelMgr* cMgr = ChannelMgr::forTeam(GetPlayer()->GetTeam()))
    {
        if (channelId)
        { // system channel
            if (Channel* channel = cMgr->GetSystemChannel(channelId, zone))
                channel->JoinChannel(GetPlayer());
        }
        else
        { // custom channel
            if (channelName.length() > MAX_CHANNEL_NAME_STR)
            {
                TC_LOG_ERROR("network", "Player {} tried to create a channel with a name more than {} characters long - blocked", GetPlayer()->GetGUID().ToString(), MAX_CHANNEL_NAME_STR);
                return;
            }

            if (Channel* channel = cMgr->GetCustomChannel(channelName))
                channel->JoinChannel(GetPlayer(), password);
            else if (Channel* channel = cMgr->CreateCustomChannel(channelName))
            {
                channel->SetPassword(password);
                channel->JoinChannel(GetPlayer(), password);
            }
        }
    }
}

void WorldSession::HandleLeaveChannel(WorldPacket& recvPacket)
{
    uint32 channelId;
    std::string channelName;
    recvPacket >> channelId >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_LEAVE_CHANNEL {} Channel: {}, channelId: {}",
        GetPlayerInfo(), channelName, channelId);

    if (channelName.empty() && !channelId)
        return;

    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(GetPlayer()->GetZoneId());
    if (channelId)
    {
        ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(channelId);
        if (!channel)
            return;

        if (!zone || !GetPlayer()->CanJoinConstantChannelInZone(channel, zone))
            return;
    }

    if (ChannelMgr* cMgr = ChannelMgr::forTeam(GetPlayer()->GetTeam()))
    {
        if (Channel* channel = cMgr->GetChannel(channelId, channelName, GetPlayer(), true, zone))
            channel->LeaveChannel(GetPlayer(), true);

        if (channelId)
            cMgr->LeftChannel(channelId, zone);
    }
}

void WorldSession::HandleChannelList(WorldPacket& recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "{} {} Channel: {}",
        recvPacket.GetOpcode() == CMSG_CHANNEL_DISPLAY_LIST ? "CMSG_CHANNEL_DISPLAY_LIST" : "CMSG_CHANNEL_LIST",
        GetPlayerInfo(), channelName);

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->List(GetPlayer());
}

void WorldSession::HandleChannelPassword(WorldPacket& recvPacket)
{
    std::string channelName, password;
    recvPacket >> channelName >> password;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_PASSWORD {} Channel: {}, Password: {}",
        GetPlayerInfo(), channelName, password);

    if (password.length() > MAX_CHANNEL_PASS_STR)
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->Password(GetPlayer(), password);
}

void WorldSession::HandleChannelSetOwner(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_SET_OWNER {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->SetOwner(GetPlayer(), targetName);
}

void WorldSession::HandleChannelOwner(WorldPacket& recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_OWNER {} Channel: {}",
        GetPlayerInfo(), channelName);

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->SendWhoOwner(GetPlayer()->GetGUID());
}

void WorldSession::HandleChannelModerator(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_MODERATOR {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->SetModerator(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnmoderator(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNMODERATOR {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->UnsetModerator(GetPlayer(), targetName);
}

void WorldSession::HandleChannelMute(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_MUTE {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->SetMute(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnmute(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNMUTE {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->UnsetMute(GetPlayer(), targetName);
}

void WorldSession::HandleChannelInvite(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_INVITE {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->Invite(GetPlayer(), targetName);
}

void WorldSession::HandleChannelKick(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_KICK {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->Kick(GetPlayer(), targetName);
}

void WorldSession::HandleChannelBan(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_BAN {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->Ban(GetPlayer(), targetName);
}

void WorldSession::HandleChannelUnban(WorldPacket& recvPacket)
{
    std::string channelName, targetName;
    recvPacket >> channelName >> targetName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_UNBAN {} Channel: {}, Target: {}",
        GetPlayerInfo(), channelName, targetName);

    if (!normalizePlayerName(targetName))
        return;

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->UnBan(GetPlayer(), targetName);
}

void WorldSession::HandleChannelAnnouncements(WorldPacket& recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_CHANNEL_ANNOUNCEMENTS {} Channel: {}",
        GetPlayerInfo(), channelName);

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->Announce(GetPlayer());
}

void WorldSession::HandleChannelDisplayListQuery(WorldPacket &recvPacket)
{
    // this should be OK because the 2 function _were_ the same
    HandleChannelList(recvPacket);
}

void WorldSession::HandleGetChannelMemberCount(WorldPacket &recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_GET_CHANNEL_MEMBER_COUNT {} Channel: {}",
        GetPlayerInfo(), channelName);

    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
    {
        TC_LOG_DEBUG("chat.system", "SMSG_CHANNEL_MEMBER_COUNT {} Channel: {} Count: {}",
            GetPlayerInfo(), channelName, channel->GetNumPlayers());

        std::string name = channel->GetName(GetSessionDbcLocale());
        WorldPacket data(SMSG_CHANNEL_MEMBER_COUNT, name.size() + 1 + 4);
        data << name;
        data << uint8(channel->GetFlags());
        data << uint32(channel->GetNumPlayers());
        SendPacket(&data);
    }
}

void WorldSession::HandleSetChannelWatch(WorldPacket &recvPacket)
{
    std::string channelName;
    recvPacket >> channelName;

    TC_LOG_DEBUG("chat.system", "CMSG_SET_CHANNEL_WATCH {} Channel: {}",
        GetPlayerInfo(), channelName);

    /*
    if (Channel* channel = ChannelMgr::GetChannelForPlayerByNamePart(channelName, GetPlayer()))
        channel->JoinNotify(GetPlayer());
    */
}
