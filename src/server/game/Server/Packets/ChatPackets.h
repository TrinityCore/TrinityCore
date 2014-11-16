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

namespace WorldPackets
{
    namespace Chat
    {
        class ChatMessage final : public ClientPacket
        {
        public:
            ChatMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            std::string Text;
            int32 Language = LANG_UNIVERSAL;
        };

        class Chat final : public ServerPacket
        {
        public:
            Chat() : ServerPacket(SMSG_MESSAGECHAT, 1+1+8+8+8+8+8+4+4+4+1+4+20) { }

            WorldPacket const* Write() override;

            uint8 SlashCmd = 0;
            uint8 Language = LANG_UNIVERSAL;
            ObjectGuid SenderGUID;
            ObjectGuid SenderGuildGUID;
            ObjectGuid SenderAccountGUID; // Not in JAM messages but appears in packet?
            ObjectGuid TargetGUID;
            ObjectGuid PartyGUID;
            uint32 SenderVirtualAddress;
            uint32 TargetVirtualAddress;
            std::string SenderName;
            std::string TargetName;
            std::string Prefix;
            std::string Channel;
            std::string ChatText;
            uint32 AchievementID = 0;
            uint8 ChatFlags = 0;
            float DisplayTime = 0.0f;
            bool HideChatLog = false;
            bool FakeSenderName = false;
        };
    }
}

#endif // ChatPackets_h__
