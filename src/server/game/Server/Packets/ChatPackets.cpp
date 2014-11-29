/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ChatPackets.h"

void WorldPackets::Chat::ChatMessage::Read()
{
    _worldPacket >> Language;
    uint32 len = _worldPacket.ReadBits(8);
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageWhisper::Read()
{
    _worldPacket >> Language;
    uint32 targetLen = _worldPacket.ReadBits(9);
    uint32 textLen = _worldPacket.ReadBits(8);
    Target = _worldPacket.ReadString(targetLen);
    Text = _worldPacket.ReadString(textLen);
}

void WorldPackets::Chat::ChatMessageChannel::Read()
{
    _worldPacket >> Language;
    uint32 targetLen = _worldPacket.ReadBits(9);
    uint32 textLen = _worldPacket.ReadBits(8);
    _worldPacket.ResetBitPos();
    Target = _worldPacket.ReadString(targetLen);
    Text = _worldPacket.ReadString(textLen);
}

void WorldPackets::Chat::ChatAddonMessage::Read()
{
    uint32 prefixLen = _worldPacket.ReadBits(5);
    uint32 textLen = _worldPacket.ReadBits(8);
    Prefix = _worldPacket.ReadString(prefixLen);
    Text = _worldPacket.ReadString(textLen);
}

void WorldPackets::Chat::ChatAddonMessageWhisper::Read()
{
    uint32 targetLen = _worldPacket.ReadBits(9);
    uint32 prefixLen = _worldPacket.ReadBits(5);
    uint32 textLen = _worldPacket.ReadBits(8);
    Target = _worldPacket.ReadString(targetLen);
    Prefix = _worldPacket.ReadString(prefixLen);
    Text = _worldPacket.ReadString(textLen);
}

void WorldPackets::Chat::ChatMessageDND::Read()
{
    uint32 len = _worldPacket.ReadBits(8);
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageAFK::Read()
{
    uint32 len = _worldPacket.ReadBits(8);
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageEmote::Read()
{
    uint32 len = _worldPacket.ReadBits(8);
    Text = _worldPacket.ReadString(len);
}

WorldPacket const* WorldPackets::Chat::Chat::Write()
{
    _worldPacket << SlashCmd;
    _worldPacket << Language;
    _worldPacket << SenderGUID;
    _worldPacket << SenderGuildGUID;
    _worldPacket << SenderAccountGUID;
    _worldPacket << TargetGUID;
    _worldPacket << TargetVirtualAddress;
    _worldPacket << SenderVirtualAddress;
    _worldPacket << PartyGUID;
    _worldPacket << AchievementID;
    _worldPacket << DisplayTime;
    _worldPacket.WriteBits(SenderName.length(), 11);
    _worldPacket.WriteBits(TargetName.length(), 11);
    _worldPacket.WriteBits(Prefix.length(), 5);
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket.WriteBits(ChatText.length(), 12);
    _worldPacket.WriteBits(ChatFlags, 10);
    _worldPacket.WriteBit(HideChatLog);
    _worldPacket.WriteBit(FakeSenderName);
    _worldPacket.WriteString(SenderName);
    _worldPacket.WriteString(TargetName);
    _worldPacket.WriteString(Prefix);
    _worldPacket.WriteString(Channel);
    _worldPacket.WriteString(ChatText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::Emote::Write()
{
    _worldPacket << Guid;
    _worldPacket << EmoteID;
    
    return &_worldPacket;
}

void WorldPackets::Chat::CTextEmote::Read()
{
    _worldPacket >> Target;
    _worldPacket >> EmoteID;
    _worldPacket >> SoundIndex;
}

WorldPacket const* WorldPackets::Chat::STextEmote::Write()
{
    _worldPacket << SourceGUID;
    _worldPacket << SourceAccountGUID;
    _worldPacket << EmoteID;
    _worldPacket << SoundIndex;
    _worldPacket << TargetGUID;
    
    return &_worldPacket;
}
