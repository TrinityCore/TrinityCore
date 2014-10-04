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

#ifndef ConnectionPackets_h__
#define ConnectionPackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Connection
    {
        enum Opcode
        {
            CMSG_PING               = 0x0,
            CMSG_ENABLE_ENCRYPTION  = 0x5,
            CMSG_LOGOUT_REQUEST     = 0x6,
            CMSG_DISCONNECT_REQUEST = 0x7,  // Not implemented
            CMSG_CONNECTION_CLOSING = 0x9,  // Not implemented

            SMSG_PONG               = 0x0,
            SMSG_BOOM               = 0x1,  // Not implemented
            SMSG_REGULATOR_UPDATE   = 0x2,  // Not implemented
            SMSG_SERVER_VERSION     = 0x3,  // Not implemented
            SMSG_STUN_SERVERS       = 0x4   // Not implemented
        };

        class Pong final : public ServerPacket
        {
        public:
            Pong() : ServerPacket(PacketHeader(SMSG_PONG, CONNECTION))
            {
            }

            void Write() override { }
            std::string ToString() const override;
        };
    }
}

#endif // ConnectionPackets_h__
