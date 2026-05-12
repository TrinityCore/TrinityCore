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

#ifndef TRINITYCORE_CHAT_PACKETS_H
#define TRINITYCORE_CHAT_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

class WorldObject;

namespace WorldPackets
{
    namespace Chat
    {
        // CMSG_MESSAGECHAT
        class ChatMessage final : public ClientPacket
        {
        public:
            explicit ChatMessage(WorldPacket&& packet) : ClientPacket(CMSG_MESSAGECHAT, std::move(packet)) { }

            void Read() override;

            ChatMsg SlashCmd = { };
            ::Language Language = LANG_UNIVERSAL;
            std::string Text;
            std::string Target; ///< Whisper target or channel name
        };

        // SMSG_MESSAGECHAT
        // SMSG_GM_MESSAGECHAT
        class TC_GAME_API Chat final : public ServerPacket
        {
        public:
            explicit Chat() : ServerPacket(SMSG_MESSAGECHAT, 100) { }
            Chat(Chat const& chat);

            void Initialize(ChatMsg chatType, Language language, WorldObject const* sender, WorldObject const* receiver, std::string_view message, uint32 achievementId = 0,
                std::string_view channelName = "", LocaleConstant locale = DEFAULT_LOCALE, std::string_view addonPrefix = "");
            void SetSender(WorldObject const* sender, LocaleConstant locale);
            void SetReceiver(WorldObject const* receiver, LocaleConstant locale);

            WorldPacket const* Write() override;

            uint8 SlashCmd = 0;     ///< @see enum ChatMsg
            uint32 _Language = LANG_UNIVERSAL;
            ObjectGuid SenderGUID;
            ObjectGuid TargetGUID;
            std::string SenderName;
            std::string TargetName;
            std::string _Channel;   ///< Channel Name
            std::string ChatText;
            uint32 AchievementID = 0;
            uint8 ChatTag = 0;   ///< @see enum PlayerChatTag

            std::size_t TargetGUIDPos = 0;
        };

        class Emote final : public ServerPacket
        {
        public:
            Emote() : ServerPacket(SMSG_EMOTE, 4 + 8) { }

            WorldPacket const* Write() override;

            uint32 EmoteID = 0;
            ObjectGuid Guid;
        };

        class EmoteClient final : public ClientPacket
        {
        public:
            EmoteClient(WorldPacket&& packet) : ClientPacket(CMSG_EMOTE, std::move(packet)) { }

            void Read() override;

            uint32 EmoteID = 0;
        };

        class ChatServerMessage final : public ServerPacket
        {
        public:
            ChatServerMessage() : ServerPacket(SMSG_CHAT_SERVER_MESSAGE, 4 + 20) { }

            WorldPacket const* Write() override;

            int32 MessageID = 0;
            std::string StringParam;
        };
    }
}

#endif // TRINITYCORE_CHAT_PACKETS_H
