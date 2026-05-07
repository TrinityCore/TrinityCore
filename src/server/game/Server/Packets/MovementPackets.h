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

#ifndef TRINITYCORE_MOVEMENT_PACKETS_H
#define TRINITYCORE_MOVEMENT_PACKETS_H

#include "Packet.h"
#include "MovementInfo.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Movement
    {
        class ClientPlayerMovement final : public ClientPacket
        {
        public:
            explicit ClientPlayerMovement(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            MovementInfo Status;
        };

        class TC_GAME_API MoveUpdate final : public ServerPacket
        {
        public:
            explicit MoveUpdate(OpcodeServer opcode = MSG_MOVE_HEARTBEAT) : ServerPacket(opcode, 100) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
        };

        class FlightSplineSync final : public ServerPacket
        {
        public:
            explicit FlightSplineSync() : ServerPacket(SMSG_FLIGHT_SPLINE_SYNC, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            float SplineDist = 0.0f;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo);
ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);

#endif // TRINITYCORE_MOVEMENT_PACKETS_H
