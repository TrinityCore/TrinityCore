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
#include "PacketOperators.h"
#include "Player.h"
#include "World.h"

namespace WorldPackets::Chat
{
void ChatMessage::Read()
{
    _worldPacket >> Language;
    _worldPacket >> SizedString::BitsSize<11>(Text);
    switch (GetOpcode())
    {
        case CMSG_CHAT_MESSAGE_SAY:
        case CMSG_CHAT_MESSAGE_PARTY:
        case CMSG_CHAT_MESSAGE_RAID:
        case CMSG_CHAT_MESSAGE_RAID_WARNING:
        case CMSG_CHAT_MESSAGE_INSTANCE_CHAT:
            _worldPacket >> Bits<1>(IsSecure);
            break;
        default:
            break;
    }
    _worldPacket >> SizedString::Data(Text);
}

void ChatMessageWhisper::Read()
{
    _worldPacket >> Language;
    _worldPacket >> TargetGUID;
    _worldPacket >> TargetVirtualRealmAddress;

    _worldPacket >> SizedCString::BitsSize<9>(Target);
    _worldPacket >> SizedCString::BitsSize<11>(Text);

    _worldPacket >> SizedCString::Data(Target);
    _worldPacket >> SizedCString::Data(Text);
}

void ChatMessageChannel::Read()
{
    _worldPacket >> Language;
    _worldPacket >> ChannelGUID;
    _worldPacket >> SizedString::BitsSize<9>(Target);
    _worldPacket >> SizedString::BitsSize<11>(Text);
    _worldPacket >> OptionalInit(IsSecure);
    if (IsSecure)
        _worldPacket >> Bits<1>(*IsSecure);

    _worldPacket >> SizedCString::Data(Target);
    _worldPacket >> SizedCString::Data(Text);
}

ByteBuffer& operator>>(ByteBuffer& data, ChatAddonMessageParams& params)
{
    data >> SizedString::BitsSize<5>(params.Prefix);
    data >> SizedString::BitsSize<8>(params.Text);
    data >> Bits<1>(params.IsLogged);
    data >> As<int32>(params.Type);
    data >> SizedString::Data(params.Prefix);
    data >> SizedString::Data<Strings::DontValidateUtf8>(params.Text);

    return data;
}

void ChatAddonMessage::Read()
{
    _worldPacket >> Params;
}

void ChatAddonMessageTargeted::Read()
{
    _worldPacket >> Params;
    _worldPacket >> ChannelGUID;
    _worldPacket >> PlayerGUID;
    _worldPacket >> PlayerVirtualRealmAddress;

    _worldPacket >> SizedCString::BitsSize<9>(PlayerName);
    _worldPacket >> SizedCString::BitsSize<8>(ChannelName);

    _worldPacket >> SizedCString::Data(PlayerName);
    _worldPacket >> SizedCString::Data(ChannelName);
}

void ChatMessageDND::Read()
{
    _worldPacket >> SizedString::BitsSize<11>(Text);

    _worldPacket >> SizedString::Data(Text);
}

void ChatMessageAFK::Read()
{
    _worldPacket >> SizedString::BitsSize<11>(Text);

    _worldPacket >> SizedString::Data(Text);
}

void ChatMessageEmote::Read()
{
    _worldPacket >> SizedString::BitsSize<11>(Text);

    _worldPacket >> SizedString::Data(Text);
}

Chat::Chat(Chat const& chat) : ServerPacket(SMSG_CHAT, chat._worldPacket.size()),
    SlashCmd(chat.SlashCmd), _Language(chat._Language), SenderGUID(chat.SenderGUID),
    SenderGuildGUID(chat.SenderGuildGUID), SenderWowAccount(chat.SenderWowAccount), TargetGUID(chat.TargetGUID),
    SenderVirtualAddress(chat.SenderVirtualAddress), TargetVirtualAddress(chat.TargetVirtualAddress), SenderName(chat.SenderName), TargetName(chat.TargetName),
    Prefix(chat.Prefix), _Channel(chat._Channel), ChatText(chat.ChatText), AchievementID(chat.AchievementID), _ChatFlags(chat._ChatFlags),
    DisplayTime(chat.DisplayTime), SpellID(chat.SpellID), BroadcastTextID(chat.BroadcastTextID), HideChatLog(chat.HideChatLog), FakeSenderName(chat.FakeSenderName),
    ChannelGUID(chat.ChannelGUID)
{
}

void Chat::Initialize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string_view message,
    uint32 achievementId /*= 0*/, std::string_view channelName /*= ""*/, LocaleConstant locale /*= DEFAULT_LOCALE*/, std::string_view addonPrefix /*= ""*/)
{
    // Clear everything because same packet can be used multiple times
    Clear();

    SenderGUID.Clear();
    SenderWowAccount.Clear();
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
    _Channel = channelName;
    Prefix = addonPrefix;
    ChatText = message;
}

void Chat::SetSender(WorldObject const* sender, LocaleConstant locale)
{
    SenderGUID = sender->GetGUID();

    if (Creature const* creatureSender = sender->ToCreature())
        SenderName = creatureSender->GetNameForLocaleIdx(locale);

    if (Player const* playerSender = sender->ToPlayer())
    {
        SenderGuildGUID = playerSender->m_unitData->GuildGUID;
        SenderWowAccount = playerSender->m_playerData->WowAccount;
        _ChatFlags = playerSender->GetChatFlags();
    }
}

void Chat::SetReceiver(WorldObject const* receiver, LocaleConstant locale)
{
    TargetGUID = receiver->GetGUID();
    if (Creature const* creatureReceiver = receiver->ToCreature())
        TargetName = creatureReceiver->GetNameForLocaleIdx(locale);
}

WorldPacket const* Chat::Write()
{
    _worldPacket << uint8(SlashCmd);
    _worldPacket << uint32(_Language);
    _worldPacket << SenderGUID;
    _worldPacket << SenderGuildGUID;
    _worldPacket << SenderWowAccount;
    _worldPacket << TargetGUID;
    _worldPacket << uint32(TargetVirtualAddress);
    _worldPacket << uint32(SenderVirtualAddress);
    _worldPacket << int32(AchievementID);
    _worldPacket << uint16(_ChatFlags);
    _worldPacket << float(DisplayTime);
    _worldPacket << int32(SpellID);
    _worldPacket << SizedString::BitsSize<11>(SenderName);
    _worldPacket << SizedString::BitsSize<11>(TargetName);
    _worldPacket << SizedString::BitsSize<5>(Prefix);
    _worldPacket << SizedString::BitsSize<7>(_Channel);
    _worldPacket << SizedString::BitsSize<12>(ChatText);
    _worldPacket << Bits<1>(HideChatLog);
    _worldPacket << Bits<1>(FakeSenderName);
    _worldPacket << OptionalInit(BroadcastTextID);
    _worldPacket << OptionalInit(ChannelGUID);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(SenderName);
    _worldPacket << SizedString::Data(TargetName);
    _worldPacket << SizedString::Data(Prefix);
    _worldPacket << SizedString::Data(_Channel);
    _worldPacket << SizedString::Data(ChatText);

    if (BroadcastTextID)
        _worldPacket << uint32(*BroadcastTextID);

    if (ChannelGUID)
        _worldPacket << *ChannelGUID;

    return &_worldPacket;
}

WorldPacket const* Emote::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(EmoteID);
    _worldPacket << Size<uint32>(SpellVisualKitIDs);
    _worldPacket << int32(SequenceVariation);
    if (!SpellVisualKitIDs.empty())
        _worldPacket.append(SpellVisualKitIDs.data(), SpellVisualKitIDs.size());

    return &_worldPacket;
}

void CTextEmote::Read()
{
    _worldPacket >> Target;
    _worldPacket >> EmoteID;
    _worldPacket >> SoundIndex;
    _worldPacket >> Size<uint32>(SpellVisualKitIDs);
    _worldPacket >> SequenceVariation;
    for (int32& spellVisualKitId : SpellVisualKitIDs)
        _worldPacket >> spellVisualKitId;
}

WorldPacket const* STextEmote::Write()
{
    _worldPacket << SourceGUID;
    _worldPacket << SourceAccountGUID;
    _worldPacket << EmoteID;
    _worldPacket << SoundIndex;
    _worldPacket << TargetGUID;

    return &_worldPacket;
}

WorldPacket const* PrintNotification::Write()
{
    _worldPacket << SizedString::BitsSize<12>(NotifyText);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(NotifyText);

    return &_worldPacket;
}

WorldPacket const* ChatPlayerNotfound::Write()
{
    _worldPacket << SizedString::BitsSize<9>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

WorldPacket const* ChatServerMessage::Write()
{
    _worldPacket << int32(MessageID);

    _worldPacket << SizedString::BitsSize<11>(StringParam);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(StringParam);

    return &_worldPacket;
}

void ChatRegisterAddonPrefixes::Read()
{
    _worldPacket >> Size<uint32>(Prefixes);
    for (std::string& prefix : Prefixes)
    {
        _worldPacket >> SizedString::BitsSize<5>(prefix);
        _worldPacket >> SizedString::Data(prefix);
    }
}

WorldPacket const* DefenseMessage::Write()
{
    _worldPacket << int32(ZoneID);
    _worldPacket << SizedString::BitsSize<12>(MessageText);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(MessageText);

    return &_worldPacket;
}

void ChatReportIgnored::Read()
{
    _worldPacket >> IgnoredGUID;
    _worldPacket >> Reason;
}

WorldPacket const* ChatPlayerAmbiguous::Write()
{
    _worldPacket << SizedString::BitsSize<9>(Name);

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

WorldPacket const* ChatRestricted::Write()
{
    _worldPacket << int32(Reason);

    return &_worldPacket;
}

void CanLocalWhisperTargetRequest::Read()
{
    _worldPacket >> WhisperTarget;
}

WorldPacket const* CanLocalWhisperTargetResponse::Write()
{
    _worldPacket << WhisperTarget;
    _worldPacket << int32(Status);

    return &_worldPacket;
}

void UpdateAADCStatus::Read()
{
    _worldPacket >> Bits<1>(ChatDisabled);
}

WorldPacket const* UpdateAADCStatusResponse::Write()
{
    _worldPacket << Bits<1>(Success);
    _worldPacket << Bits<1>(ChatDisabled);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
}
