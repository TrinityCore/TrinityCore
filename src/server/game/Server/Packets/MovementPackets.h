/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef MovementPackets_h__
#define MovementPackets_h__

#include "Packet.h"
#include "Util.h"

namespace WorldPackets
{
    namespace Movement
    {
        struct MovementAck
        {
            MovementInfo movementInfo;
            uint32 AckIndex = 0;
        };

        class ClientPlayerMovement final : public ClientPacket
        {
            public:
                ClientPlayerMovement(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

                void Read() override;

                MovementInfo movementInfo;
        };

        class MovementAckMessage final : public ClientPacket
        {
            public:
                MovementAckMessage(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

                void Read() override;

                MovementAck Ack;
        };

        class MovementSpeedAck final : public ClientPacket
        {
            public:
                MovementSpeedAck(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

                void Read() override;

                MovementAck Ack;
                float Speed = 0.f;
        };

        class NotActiveMover final : public ClientPacket
        {
            public:
                NotActiveMover(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_NOT_ACTIVE_MOVER, std::move(packet)) { }

                void Read() override;

                MovementInfo movementInfo;
        };

        class MoveTimeSkipped final : public ClientPacket
        {
            public:
                MoveTimeSkipped(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_TIME_SKIPPED, std::move(packet)) { }

                void Read() override;

                ObjectGuid moverGUID;
                uint32 timeSkipped;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);
ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& ack);

#endif // MovementPackets_h__
