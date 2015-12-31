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

#ifndef BlackMarketPackets_h__
#define BlackMarketPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace BlackMarket
    {
        class BlackMarketOpen final : public ClientPacket
        {
        public:
            BlackMarketOpen(WorldPacket&& packet) : ClientPacket(CMSG_BLACK_MARKET_OPEN, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class BlackMarketOpenResult final : public ServerPacket
        {
        public:
            BlackMarketOpenResult() : ServerPacket(SMSG_BLACK_MARKET_OPEN_RESULT, 15) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            bool Enable = true;
        };
    }
}
#endif // BlackMarketPackets_h__
