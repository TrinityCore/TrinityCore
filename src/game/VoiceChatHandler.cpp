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
#include "Opcodes.h"
#include "Log.h"

void WorldSession::HandleVoiceSettingsOpcode( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_VOICE_SETTINGS");
    // uint8 isVoiceEnabled, uint8 isMicrophoneEnabled
    recv_data.hexlike();
}

void WorldSession::HandleChannelEnableVoiceOpcode( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_CHANNEL_ENABLE_VOICE");
    // Enable Voice button in channel context menu
    recv_data.hexlike();
}

void WorldSession::HandleChannelVoiceChatQuery( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_CHANNEL_VOICE_CHAT_QUERY");
    // uint32, string
    recv_data.hexlike();
}

