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

#ifndef LFGPacketsCommon_h__
#define LFGPacketsCommon_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace LFG
    {
        enum class RideType : uint32
        {
            None = 0,
            Battlegrounds = 1,
            Lfg = 3
        };

        struct RideTicket
        {
            int32 Time = 0;
            RideType Type = RideType::None;
            uint32 Id = 0;

            ObjectGuid RequesterGuid;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);

#endif // LFGPacketsCommon_h__
