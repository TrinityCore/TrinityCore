/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef ChatPackets_h__
#define ChatPackets_h__

#include "Packet.h"
#include "Common.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"
#include "SharedDefines.h"

class WorldObject;

namespace WorldPackets
{
    namespace Chat
    {
        // CMSG_CHAT_MESSAGE_GUILD
        // CMSG_CHAT_MESSAGE_OFFICER
        // CMSG_CHAT_MESSAGE_YELL
        // CMSG_CHAT_MESSAGE_SAY
        // CMSG_CHAT_MESSAGE_PARTY
        // CMSG_CHAT_MESSAGE_RAID
        // CMSG_CHAT_MESSAGE_RAID_WARNING
        // CMSG_CHAT_MESSAGE_INSTANCE_CHAT
        class ChatMessage final : public ClientPacket
        {
        public:
            ChatMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Text;
            int32 Language = LANG_UNIVERSAL;
        };

        // CMSG_CHAT_MESSAGE_WHISPER
        class ChatMessageWhisper final : public ClientPacket
        {
        public:
            ChatMessageWhisper(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            int32 Language = LANG_UNIVERSAL;
            std::string Text;
            std::string Target;
        };

        // CMSG_CHAT_MESSAGE_CHANNEL
        class ChatMessageChannel final : public ClientPacket
        {
        public:
            ChatMessageChannel(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            int32 Language = LANG_UNIVERSAL;
            std::string Text;
            std::string Target;
        };

        // CMSG_CHAT_ADDON_MESSAGE_GUILD
        // CMSG_CHAT_ADDON_MESSAGE_OFFICER
        // CMSG_CHAT_ADDON_MESSAGE_PARTY
        // CMSG_CHAT_ADDON_MESSAGE_RAID
        // CMSG_CHAT_ADDON_MESSAGE_INSTANCE_CHAT
        class ChatAddonMessage final : public ClientPacket
        {
        public:
            ChatAddonMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Prefix;
            std::string Text;
        };

        // CMSG_CHAT_ADDON_MESSAGE_WHISPER
        class ChatAddonMessageWhisper final : public ClientPacket
        {
        public:
            ChatAddonMessageWhisper(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_ADDON_MESSAGE_WHISPER, std::move(packet)) { }

            void Read() override;

            std::string Prefix;
            std::string Target;
            std::string Text;
        };

        // CMSG_CHAT_ADDON_MESSAGE_CHANNEL
        class ChatAddonMessageChannel final : public ClientPacket
        {
        public:
            ChatAddonMessageChannel(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_ADDON_MESSAGE_CHANNEL, std::move(packet)) { }

            void Read() override;

            std::string Text;
            std::string Target;
            std::string Prefix;
        };

        class ChatMessageDND final : public ClientPacket
        {
        public:
            ChatMessageDND(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_MESSAGE_DND, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        class ChatMessageAFK final : public ClientPacket
        {
        public:
            ChatMessageAFK(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_MESSAGE_AFK, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        class ChatMessageEmote final : public ClientPacket
        {
        public:
            ChatMessageEmote(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_MESSAGE_EMOTE, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        // SMSG_CHAT
        class TC_GAME_API Chat final : public ServerPacket
        {
        public:
            Chat() : ServerPacket(SMSG_CHAT, 100) { }
            Chat(Chat const& chat);

            void Initialize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string message, uint32 achievementId = 0, std::string channelName = "", LocaleConstant locale = DEFAULT_LOCALE, std::string addonPrefix = "");
            void SetSender(WorldObject const* sender, LocaleConstant locale);
            void SetReceiver(WorldObject const* receiver, LocaleConstant locale);

            WorldPacket const* Write() override;

            uint8 SlashCmd = 0;     ///< @see enum ChatMsg
            uint8 _Language = LANG_UNIVERSAL;
            ObjectGuid SenderGUID;
            ObjectGuid SenderGuildGUID;
            ObjectGuid SenderAccountGUID;
            ObjectGuid TargetGUID;
            ObjectGuid PartyGUID;
            uint32 SenderVirtualAddress = 0;
            uint32 TargetVirtualAddress = 0;
            std::string SenderName;
            std::string TargetName;
            std::string Prefix;     ///< Addon Prefix
            std::string _Channel;   ///< Channel Name
            std::string ChatText;
            uint32 AchievementID = 0;
            uint8 _ChatFlags = 0;   ///< @see enum ChatFlags
            float DisplayTime = 0.0f;
            bool HideChatLog = false;
            bool FakeSenderName = false;
        };

        class Emote final : public ServerPacket
        {
        public:
            Emote() : ServerPacket(SMSG_EMOTE, 18 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            int32 EmoteID = 0;
        };

        class CTextEmote final : public ClientPacket
        {
        public:
            CTextEmote(WorldPacket&& packet) : ClientPacket(CMSG_SEND_TEXT_EMOTE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
            int32 EmoteID = 0;
            int32 SoundIndex = -1;
        };

        class STextEmote final : public ServerPacket
        {
        public:
            STextEmote() : ServerPacket(SMSG_TEXT_EMOTE, 3 * 18 + 2 * 4) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceGUID;
            ObjectGuid SourceAccountGUID;
            ObjectGuid TargetGUID;
            int32 SoundIndex = -1;
            int32 EmoteID = 0;
        };

        class TC_GAME_API PrintNotification final : public ServerPacket
        {
        public:
            PrintNotification(std::string const& notifyText) : ServerPacket(SMSG_PRINT_NOTIFICATION, 2 + notifyText.size()), NotifyText(notifyText) { }

            WorldPacket const* Write() override;

            std::string NotifyText;
        };

        class EmoteClient final : public ClientPacket
        {
        public:
            EmoteClient(WorldPacket&& packet) : ClientPacket(CMSG_EMOTE, std::move(packet)) { }

            void Read() override { }
        };

        class ChatPlayerNotfound final : public ServerPacket
        {
        public:
            ChatPlayerNotfound(std::string const& name) : ServerPacket(SMSG_CHAT_PLAYER_NOTFOUND, 2 + name.size()), Name(name) { }

            WorldPacket const* Write() override;

            std::string Name;
        };

        class ChatServerMessage final : public ServerPacket
        {
        public:
            ChatServerMessage() : ServerPacket(SMSG_CHAT_SERVER_MESSAGE, 4 + 2) { }

            WorldPacket const* Write() override;

            int32 MessageID = 0;
            std::string StringParam;
        };

        class ChatRegisterAddonPrefixes final : public ClientPacket
        {
        public:
            enum
            {
                MAX_PREFIXES = 64
            };

            ChatRegisterAddonPrefixes(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_REGISTER_ADDON_PREFIXES, std::move(packet)) { }

            void Read() override;

            Array<std::string, MAX_PREFIXES> Prefixes;
        };

        class ChatUnregisterAllAddonPrefixes final : public ClientPacket
        {
        public:
            ChatUnregisterAllAddonPrefixes(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_UNREGISTER_ALL_ADDON_PREFIXES, std::move(packet)) { }

            void Read() override { }
        };

        class DefenseMessage final : public ServerPacket
        {
        public:
            DefenseMessage() : ServerPacket(SMSG_DEFENSE_MESSAGE) { }

            WorldPacket const* Write() override;

            int32 ZoneID = 0;
            std::string MessageText;
        };

        class ChatReportIgnored final : public ClientPacket
        {
        public:
            ChatReportIgnored(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_REPORT_IGNORED, std::move(packet)) { }

            void Read() override;

            ObjectGuid IgnoredGUID;
            uint8 Reason = 0;
        };

        class ChatPlayerAmbiguous final : public ServerPacket
        {
        public:
            ChatPlayerAmbiguous(std::string const& name) : ServerPacket(SMSG_CHAT_PLAYER_AMBIGUOUS, 2 + name.length()), Name(name) { }

            WorldPacket const* Write() override;

            std::string Name;
        };

        class ChatRestricted final : public ServerPacket
        {
        public:
            ChatRestricted() : ServerPacket(SMSG_CHAT_RESTRICTED, 1) { }

            WorldPacket const* Write() override;

            uint8 Reason = 0;
        };
    }
}

#endif // ChatPackets_h__
