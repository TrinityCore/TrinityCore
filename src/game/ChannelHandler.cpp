/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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


#include "Policies/SingletonImp.h"

#include "ObjectMgr.h"                                      // for normalizePlayerName
#include "ChannelMgr.h"

void WorldSession::HandleJoinChannel(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 4+1+1+1);

    uint32 channel_id;
    uint8 unknown1, unknown2;
    std::string channelname, pass;

    recvPacket >> channel_id >> unknown1 >> unknown2;
    recvPacket >> channelname;

    if(channelname.empty())
        return;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, 4+1+1+(channelname.size()+1)+1);

    recvPacket >> pass;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
    {
        cMgr->team = _player->GetTeam();
        if(Channel *chn = cMgr->GetJoinChannel(channelname, channel_id))
            chn->Join(_player->GetGUID(), pass.c_str());
    }
}

void WorldSession::HandleLeaveChannel(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 4+1);

    uint32 unk;
    std::string channelname;
    recvPacket >> unk;                                      // channel id?
    recvPacket >> channelname;

    if(channelname.empty())
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
    {
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Leave(_player->GetGUID(), true);
        cMgr->LeftChannel(channelname);
    }
}

void WorldSession::HandleChannelList(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->List(_player);
}

void WorldSession::HandleChannelPassword(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, pass;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> pass;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Password(_player->GetGUID(), pass.c_str());
}

void WorldSession::HandleChannelSetOwner(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, newp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> newp;

    if(!normalizePlayerName(newp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->SetOwner(_player->GetGUID(), newp.c_str());
}

void WorldSession::HandleChannelOwner(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->SendWhoOwner(_player->GetGUID());
}

void WorldSession::HandleChannelModerator(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->SetModerator(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelUnmoderator(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->UnsetModerator(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelMute(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->SetMute(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelUnmute(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->UnsetMute(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelInvite(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Invite(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelKick(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;
    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Kick(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelBan(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Ban(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelUnban(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1+1);

    std::string channelname, otp;
    recvPacket >> channelname;

    // recheck
    CHECK_PACKET_SIZE(recvPacket, (channelname.size()+1)+1);

    recvPacket >> otp;

    if(!normalizePlayerName(otp))
        return;

    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->UnBan(_player->GetGUID(), otp.c_str());
}

void WorldSession::HandleChannelAnnouncements(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Announce(_player->GetGUID());
}

void WorldSession::HandleChannelModerate(WorldPacket& recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->Moderate(_player->GetGUID());
}

void WorldSession::HandleChannelDisplayListQuery(WorldPacket &recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->List(_player);
}

void WorldSession::HandleGetChannelMemberCount(WorldPacket &recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
    {
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
        {
            WorldPacket data(SMSG_CHANNEL_MEMBER_COUNT, chn->GetName().size()+1+1+4);
            data << chn->GetName();
            data << uint8(chn->GetFlags());
            data << uint32(chn->GetNumPlayers());
            SendPacket(&data);
        }
    }
}

void WorldSession::HandleSetChannelWatch(WorldPacket &recvPacket)
{
    sLog.outDebug("Opcode %u", recvPacket.GetOpcode());
    //recvPacket.hexlike();
    CHECK_PACKET_SIZE(recvPacket, 1);

    std::string channelname;
    recvPacket >> channelname;
    /*if(ChannelMgr* cMgr = channelMgr(_player->GetTeam()))
        if(Channel *chn = cMgr->GetChannel(channelname, _player))
            chn->JoinNotify(_player->GetGUID());*/
}

