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

#include "ChatPackets.h"
#include "Creature.h"
#include "Group.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"

void WorldPackets::Chat::ChatMessage::Read()
{
    _worldPacket >> Language;
    uint32 len = _worldPacket.ReadBits(11);
    switch (GetOpcode())
    {
        case CMSG_CHAT_MESSAGE_SAY:
        case CMSG_CHAT_MESSAGE_PARTY:
        case CMSG_CHAT_MESSAGE_RAID:
        case CMSG_CHAT_MESSAGE_RAID_WARNING:
        case CMSG_CHAT_MESSAGE_INSTANCE_CHAT:
            IsSecure = _worldPacket.ReadBit();
            break;
        default:
            break;
    }
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageWhisper::Read()
{
    _worldPacket >> Language;
    uint32 targetLen = _worldPacket.ReadBits(9);
    uint32 textLen = _worldPacket.ReadBits(11);
    Target = _worldPacket.ReadString(targetLen);
    Text = _worldPacket.ReadString(textLen);
}

void WorldPackets::Chat::ChatMessageChannel::Read()
{
    _worldPacket >> Language;
    _worldPacket >> ChannelGUID;
    uint32 targetLen = _worldPacket.ReadBits(9);
    uint32 textLen = _worldPacket.ReadBits(11);
    if (_worldPacket.ReadBit())
        IsSecure = _worldPacket.ReadBit();

    Target = _worldPacket.ReadString(targetLen);
    Text = _worldPacket.ReadString(textLen);
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Chat::ChatAddonMessageParams& params)
{
    uint32 prefixLen = data.ReadBits(5);
    uint32 textLen = data.ReadBits(8);
    params.IsLogged = data.ReadBit();
    params.Type = ChatMsg(data.read<int32>());
    params.Prefix = data.ReadString(prefixLen);
    params.Text = data.ReadString(textLen, false);

    return data;
}

void WorldPackets::Chat::ChatAddonMessage::Read()
{
    _worldPacket >> Params;
}

void WorldPackets::Chat::ChatAddonMessageTargeted::Read()
{
    uint32 targetLen = _worldPacket.ReadBits(9);
    _worldPacket.ResetBitPos();

    _worldPacket >> Params;
    _worldPacket >> *ChannelGUID;
    Target = _worldPacket.ReadString(targetLen);
}

void WorldPackets::Chat::ChatMessageDND::Read()
{
    uint32 len = _worldPacket.ReadBits(11);
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageAFK::Read()
{
    uint32 len = _worldPacket.ReadBits(11);
    Text = _worldPacket.ReadString(len);
}

void WorldPackets::Chat::ChatMessageEmote::Read()
{
    uint32 len = _worldPacket.ReadBits(11);
    Text = _worldPacket.ReadString(len);
}

WorldPackets::Chat::Chat::Chat(Chat const& chat) : ServerPacket(SMSG_CHAT, chat._worldPacket.size()),
    SlashCmd(chat.SlashCmd), _Language(chat._Language), SenderGUID(chat.SenderGUID),
    SenderGuildGUID(chat.SenderGuildGUID), SenderAccountGUID(chat.SenderAccountGUID), TargetGUID(chat.TargetGUID),
    SenderVirtualAddress(chat.SenderVirtualAddress), TargetVirtualAddress(chat.TargetVirtualAddress), SenderName(chat.SenderName), TargetName(chat.TargetName),
    Prefix(chat.Prefix), _Channel(chat._Channel), ChatText(chat.ChatText), AchievementID(chat.AchievementID), _ChatFlags(chat._ChatFlags),
    DisplayTime(chat.DisplayTime), HideChatLog(chat.HideChatLog), FakeSenderName(chat.FakeSenderName)
{
}

void WorldPackets::Chat::Chat::Initialize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string_view message,
    uint32 achievementId /*= 0*/, std::string_view channelName /*= ""*/, LocaleConstant locale /*= DEFAULT_LOCALE*/, std::string_view addonPrefix /*= ""*/)
{
    // Clear everything because same packet can be used multiple times
    Clear();

    SenderGUID.Clear();
    SenderAccountGUID.Clear();
    SenderGuildGUID.Clear();
    TargetGUID.Clear();
    SenderName.clear();
    TargetName.clear();
    _ChatFlags = CHAT_FLAG_NONE;

    SlashCmd = chatType;
    _Language = language;

    if (sender)
        SetSender(sender, locale);

    if (receiver)
        SetReceiver(receiver, locale);

    SenderVirtualAddress = GetVirtualRealmAddress();
    TargetVirtualAddress = GetVirtualRealmAddress();
    AchievementID = achievementId;
    _Channel = std::move(channelName);
    Prefix = std::move(addonPrefix);
    ChatText = message;
}

void WorldPackets::Chat::Chat::SetSender(WorldObject const* sender, LocaleConstant locale)
{
    SenderGUID = sender->GetGUID();

    if (Creature const* creatureSender = sender->ToCreature())
        SenderName = creatureSender->GetNameForLocaleIdx(locale);

    if (Player const* playerSender = sender->ToPlayer())
    {
        SenderAccountGUID = playerSender->GetSession()->GetAccountGUID();
        _ChatFlags = playerSender->GetChatFlags();

        SenderGuildGUID = ObjectGuid::Create<HighGuid::Guild>(playerSender->GetGuildId());
    }
}

void WorldPackets::Chat::Chat::SetReceiver(WorldObject const* receiver, LocaleConstant locale)
{
    TargetGUID = receiver->GetGUID();
    if (Creature const* creatureReceiver = receiver->ToCreature())
        TargetName = creatureReceiver->GetNameForLocaleIdx(locale);
}

WorldPacket const* WorldPackets::Chat::Chat::Write()
{
    _worldPacket << uint8(SlashCmd);
    _worldPacket << uint32(_Language);
    _worldPacket << SenderGUID;
    _worldPacket << SenderGuildGUID;
    _worldPacket << SenderAccountGUID;
    _worldPacket << TargetGUID;
    _worldPacket << uint32(TargetVirtualAddress);
    _worldPacket << uint32(SenderVirtualAddress);
    _worldPacket << int32(AchievementID);
    _worldPacket << float(DisplayTime);
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBits(SenderName.length(), 11);
    _worldPacket.WriteBits(TargetName.length(), 11);
    _worldPacket.WriteBits(Prefix.length(), 5);
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket.WriteBits(ChatText.length(), 12);
    _worldPacket.WriteBits(_ChatFlags, 15);
    _worldPacket.WriteBit(HideChatLog);
    _worldPacket.WriteBit(FakeSenderName);
    _worldPacket.WriteBit(Unused_801.has_value());
    _worldPacket.WriteBit(ChannelGUID.has_value());
    _worldPacket.FlushBits();

    _worldPacket.WriteString(SenderName);
    _worldPacket.WriteString(TargetName);
    _worldPacket.WriteString(Prefix);
    _worldPacket.WriteString(_Channel);
    _worldPacket.WriteString(ChatText);

    if (Unused_801)
        _worldPacket << uint32(*Unused_801);

    if (ChannelGUID)
        _worldPacket << *ChannelGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::Emote::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(EmoteID);
    _worldPacket << uint32(SpellVisualKitIDs.size());
    _worldPacket << int32(SequenceVariation);
    if (!SpellVisualKitIDs.empty())
        _worldPacket.append(SpellVisualKitIDs.data(), SpellVisualKitIDs.size());

    return &_worldPacket;
}

void WorldPackets::Chat::CTextEmote::Read()
{
    _worldPacket >> Target;
    _worldPacket >> EmoteID;
    _worldPacket >> SoundIndex;
    SpellVisualKitIDs.resize(_worldPacket.read<uint32>());
    _worldPacket >> SequenceVariation;
    for (int32& spellVisualKitId : SpellVisualKitIDs)
        _worldPacket >> spellVisualKitId;
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

WorldPacket const* WorldPackets::Chat::PrintNotification::Write()
{
    _worldPacket.WriteBits(NotifyText.size(), 12);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(NotifyText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::ChatPlayerNotfound::Write()
{
    _worldPacket.WriteBits(Name.length(), 9);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::ChatServerMessage::Write()
{
    _worldPacket << int32(MessageID);

    _worldPacket.WriteBits(StringParam.length(), 11);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(StringParam);

    return &_worldPacket;
}

void WorldPackets::Chat::ChatRegisterAddonPrefixes::Read()
{
    Prefixes.resize(_worldPacket.read<uint32>());
    for (std::string& prefix : Prefixes)
        prefix.assign(_worldPacket.ReadString(_worldPacket.ReadBits(5)));
}

WorldPacket const* WorldPackets::Chat::DefenseMessage::Write()
{
    _worldPacket << int32(ZoneID);
    _worldPacket.WriteBits(MessageText.length(), 12);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(MessageText);

    return &_worldPacket;
}

void WorldPackets::Chat::ChatReportIgnored::Read()
{
    _worldPacket >> IgnoredGUID;
    _worldPacket >> Reason;
}

WorldPacket const* WorldPackets::Chat::ChatPlayerAmbiguous::Write()
{
    _worldPacket.WriteBits(Name.length(), 9);
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::ChatRestricted::Write()
{
    _worldPacket << int32(Reason);

    return &_worldPacket;
}

void WorldPackets::Chat::CanLocalWhisperTargetRequest::Read()
{
    _worldPacket >> WhisperTarget;
}

WorldPacket const* WorldPackets::Chat::CanLocalWhisperTargetResponse::Write()
{
    _worldPacket << WhisperTarget;
    _worldPacket << int32(Status);

    return &_worldPacket;
}

void WorldPackets::Chat::UpdateAADCStatus::Read()
{
    ChatDisabled = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Chat::UpdateAADCStatusResponse::Write()
{
    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBit(ChatDisabled);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
