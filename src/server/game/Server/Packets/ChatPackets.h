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
        class SendTextEmote final : public ClientPacket
        {
        public:
            SendTextEmote(WorldPacket&& packet) : ClientPacket(CMSG_SEND_TEXT_EMOTE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
            int32 EmoteID = 0;
            int32 SoundIndex = 0;
        };

        class STextEmote final : public ServerPacket
        {
        public:
            STextEmote() : ServerPacket(SMSG_TEXT_EMOTE, 21) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceGUID;
            std::string Target;
            int32 SoundIndex = 0;
            int32 EmoteID = 0;
        };

        class Emote final : public ServerPacket
        {
        public:
            Emote() : ServerPacket(SMSG_EMOTE, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            uint32 EmoteID = 0;
        };
    }
}

#endif // ChatPackets_h__
