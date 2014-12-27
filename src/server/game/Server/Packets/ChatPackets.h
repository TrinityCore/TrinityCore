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

#ifndef ChatPackets_h__
#define ChatPackets_h__

#include "Packet.h"
#include "SharedDefines.h"
#include "ObjectGuid.h"

class WorldObject;

namespace WorldPackets
{
    namespace Chat
    {
        // CMSG_MESSAGECHAT_GUILD
        // CMSG_MESSAGECHAT_OFFICER
        // CMSG_MESSAGECHAT_YELL
        // CMSG_MESSAGECHAT_SAY
        // CMSG_MESSAGECHAT_PARTY
        // CMSG_MESSAGECHAT_RAID
        // CMSG_MESSAGECHAT_RAID_WARNING
        class ChatMessage final : public ClientPacket
        {
        public:
            ChatMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Text;
            int32 Language = LANG_UNIVERSAL;
        };

        // CMSG_MESSAGECHAT_WHISPER
        class ChatMessageWhisper final : public ClientPacket
        {
        public:
            ChatMessageWhisper(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            int32 Language = LANG_UNIVERSAL;
            std::string Text;
            std::string Target;
        };

        // CMSG_MESSAGECHAT_CHANNEL
        class ChatMessageChannel final : public ClientPacket
        {
        public:
            ChatMessageChannel(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            int32 Language = LANG_UNIVERSAL;
            std::string Text;
            std::string Target;
        };

        // CMSG_MESSAGECHAT_ADDON_GUILD
        // CMSG_MESSAGECHAT_ADDON_OFFICER
        // CMSG_MESSAGECHAT_ADDON_PARTY
        // CMSG_MESSAGECHAT_ADDON_RAID
        class ChatAddonMessage final : public ClientPacket
        {
        public:
            ChatAddonMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Prefix;
            std::string Text;
        };

        // CMSG_MESSAGECHAT_ADDON_WHISPER
        class ChatAddonMessageWhisper final : public ClientPacket
        {
        public:
            ChatAddonMessageWhisper(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Prefix;
            std::string Target;
            std::string Text;
        };

        class ChatMessageDND final : public ClientPacket
        {
        public:
            ChatMessageDND(WorldPacket&& packet) : ClientPacket(CMSG_MESSAGECHAT_DND, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        class ChatMessageAFK final : public ClientPacket
        {
        public:
            ChatMessageAFK(WorldPacket&& packet) : ClientPacket(CMSG_MESSAGECHAT_AFK, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        class ChatMessageEmote final : public ClientPacket
        {
        public:
            ChatMessageEmote(WorldPacket&& packet) : ClientPacket(CMSG_MESSAGECHAT_EMOTE, std::move(packet)) { }

            void Read() override;

            std::string Text;
        };

        // SMSG_MESSAGECHAT
        class Chat final : public ServerPacket
        {
        public:
            Chat() : ServerPacket(SMSG_MESSAGECHAT, 100) { }

            void Initalize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string message, uint32 achievementId = 0, std::string channelName = "", LocaleConstant locale = DEFAULT_LOCALE, std::string addonPrefix = "");
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
            CTextEmote(WorldPacket&& packet) : ClientPacket(CMSG_TEXT_EMOTE, std::move(packet)) { }

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
    }
}

#endif // ChatPackets_h__
