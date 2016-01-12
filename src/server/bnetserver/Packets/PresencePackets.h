/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PresencePackets_h__
#define PresencePackets_h__

#include "PacketsBase.h"

namespace Battlenet
{
    namespace Presence
    {
        enum Opcode
        {
            CMSG_UPDATE_REQUEST         = 0x0,  // Not implemented
            CMSG_STATISTIC_SUBSCRIBE    = 0x2,  // Not implemented

            SMSG_UPDATE_NOTIFY          = 0x0,  // Not implemented
            SMSG_FIELD_SPEC_ANNOUNCE    = 0x1,  // Not implemented
            SMSG_STATISTICS_UPDATE      = 0x3   // Not implemented
        };

        class UpdateRequest final : public ClientPacket
        {
        public:
            UpdateRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_UPDATE_REQUEST, PRESENCE) && "Invalid packet header for UpdateRequest");
            }

            void Read() override;
            std::string ToString() const override;
        };

        class StatisticSubscribe final : public ClientPacket
        {
        public:
            StatisticSubscribe(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_STATISTIC_SUBSCRIBE, PRESENCE) && "Invalid packet header for StatisticSubscribe");
            }

            void Read() override;
            std::string ToString() const override;
        };
    }
}

#endif // PresencePackets_h__
