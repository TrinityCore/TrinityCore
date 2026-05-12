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
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

void WorldPackets::Chat::ChatMessage::Read()
{
    SlashCmd = static_cast<ChatMsg>(_worldPacket.read<int32>());
    Language = static_cast<::Language>(_worldPacket.read<int32>());

    switch (SlashCmd)
    {
        case CHAT_MSG_SAY:
        case CHAT_MSG_EMOTE:
        case CHAT_MSG_YELL:
        case CHAT_MSG_PARTY:
        case CHAT_MSG_PARTY_LEADER:
        case CHAT_MSG_GUILD:
        case CHAT_MSG_OFFICER:
        case CHAT_MSG_RAID:
        case CHAT_MSG_RAID_LEADER:
        case CHAT_MSG_RAID_WARNING:
        case CHAT_MSG_BATTLEGROUND:
        case CHAT_MSG_BATTLEGROUND_LEADER:
        case CHAT_MSG_AFK:
        case CHAT_MSG_DND:
            Text = _worldPacket.ReadCString(Language != LANG_ADDON);
            break;
        case CHAT_MSG_WHISPER:
        case CHAT_MSG_CHANNEL:
            _worldPacket >> Target;
            Text = _worldPacket.ReadCString(Language != LANG_ADDON);
            break;
        default:
            break;
    }
}

WorldPackets::Chat::Chat::Chat(Chat const& chat) : ServerPacket(chat.GetOpcode(), chat._worldPacket.size()),
    SlashCmd(chat.SlashCmd), _Language(chat._Language), SenderGUID(chat.SenderGUID), TargetGUID(chat.TargetGUID),
    SenderName(chat.SenderName), TargetName(chat.TargetName),
    _Channel(chat._Channel), ChatText(chat.ChatText), AchievementID(chat.AchievementID), ChatTag(chat.ChatTag)
{
}

void WorldPackets::Chat::Chat::Initialize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string_view message,
    uint32 achievementId /*= 0*/, std::string_view channelName /*= ""*/, LocaleConstant locale /*= DEFAULT_LOCALE*/)
{
    // Clear everything because same packet can be used multiple times
    Clear();
    _worldPacket.SetOpcode(SMSG_MESSAGECHAT);

    SenderGUID.Clear();
    TargetGUID.Clear();
    SenderName.clear();
    TargetName.clear();
    ChatTag = CHAT_TAG_NONE;

    SlashCmd = chatType;
    _Language = language;

    if (sender)
        SetSender(sender, locale);

    if (receiver)
        SetReceiver(receiver, locale);

    AchievementID = achievementId;
    _Channel = channelName;
    ChatText = message;
}

void WorldPackets::Chat::Chat::SetSender(WorldObject const* sender, LocaleConstant locale)
{
    SenderGUID = sender->GetGUID();
    SenderName = sender->GetNameForLocaleIdx(locale);

    if (Player const* playerSender = sender->ToPlayer())
    {
        ChatTag = playerSender->GetChatTag();
        if (playerSender->GetSession()->HasPermission(rbac::RBAC_PERM_COMMAND_GM_CHAT))
            _worldPacket.SetOpcode(SMSG_GM_MESSAGECHAT);
    }
}

void WorldPackets::Chat::Chat::SetReceiver(WorldObject const* receiver, LocaleConstant locale)
{
    TargetGUID = receiver->GetGUID();
    TargetName = receiver->GetNameForLocaleIdx(locale);
}

WorldPacket const* WorldPackets::Chat::Chat::Write()
{
    _worldPacket << uint8(SlashCmd);
    _worldPacket << int32(_Language);
    _worldPacket << SenderGUID;
    _worldPacket << uint32(0);  // some flags
    switch (SlashCmd)
    {
        case CHAT_MSG_MONSTER_SAY:
        case CHAT_MSG_MONSTER_PARTY:
        case CHAT_MSG_MONSTER_YELL:
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_MONSTER_EMOTE:
        case CHAT_MSG_RAID_BOSS_EMOTE:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        case CHAT_MSG_BATTLENET:
            _worldPacket << uint32(SenderName.length() + 1);
            _worldPacket << SenderName;
            TargetGUIDPos = _worldPacket.wpos();
            _worldPacket << TargetGUID;
            if (!TargetGUID.IsEmpty() && !TargetGUID.IsPlayer() && !TargetGUID.IsPet())
            {
                _worldPacket << uint32(TargetName.length() + 1);
                _worldPacket << TargetName;
            }
            break;
        case CHAT_MSG_WHISPER_FOREIGN:
            _worldPacket << uint32(SenderName.length() + 1);
            _worldPacket << SenderName;
            TargetGUIDPos = _worldPacket.wpos();
            _worldPacket << TargetGUID;
            break;
        case CHAT_MSG_BG_SYSTEM_NEUTRAL:
        case CHAT_MSG_BG_SYSTEM_ALLIANCE:
        case CHAT_MSG_BG_SYSTEM_HORDE:
            TargetGUIDPos = _worldPacket.wpos();
            _worldPacket << TargetGUID;
            if (!TargetGUID.IsEmpty() && !TargetGUID.IsPlayer())
            {
                _worldPacket << uint32(TargetName.length() + 1);
                _worldPacket << TargetName;
            }
            break;
        case CHAT_MSG_ACHIEVEMENT:
        case CHAT_MSG_GUILD_ACHIEVEMENT:
            TargetGUIDPos = _worldPacket.wpos();
            _worldPacket << TargetGUID;
            break;
        default:
            if (GetOpcode() == SMSG_GM_MESSAGECHAT)
            {
                _worldPacket << uint32(SenderName.length() + 1);
                _worldPacket << SenderName;
            }

            if (SlashCmd == CHAT_MSG_CHANNEL)
            {
                ASSERT(!_Channel.empty());
                _worldPacket << _Channel;
            }

            TargetGUIDPos = _worldPacket.wpos();
            _worldPacket << TargetGUID;
            break;
    }

    _worldPacket << uint32(ChatText.length() + 1);
    _worldPacket << ChatText;
    _worldPacket << uint8(ChatTag);

    if (SlashCmd == CHAT_MSG_ACHIEVEMENT || SlashCmd == CHAT_MSG_GUILD_ACHIEVEMENT)
        _worldPacket << uint32(AchievementID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Chat::Emote::Write()
{
    _worldPacket << EmoteID;
    _worldPacket << Guid;

    return &_worldPacket;
}

void WorldPackets::Chat::EmoteClient::Read()
{
    _worldPacket >> EmoteID;
}

WorldPacket const* WorldPackets::Chat::ChatServerMessage::Write()
{
    _worldPacket << int32(MessageID);
    _worldPacket << StringParam;

    return &_worldPacket;
}
