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

#ifndef ChatPackets_h__
#define ChatPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Chat
    {
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

#endif // ChatPackets_h__
