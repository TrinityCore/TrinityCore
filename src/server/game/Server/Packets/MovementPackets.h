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

#ifndef MovementPackets_h__
#define MovementPackets_h__

#include "Packet.h"
#include "Object.h"

namespace WorldPackets
{
    namespace Movement
    {
        class ClientPlayerMovement final : public ClientPacket
        {
        public:
            ClientPlayerMovement(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            MovementInfo movementInfo;
        };

        class ServerPlayerMovement final : public ServerPacket
        {
        public:
            ServerPlayerMovement() : ServerPacket(SMSG_PLAYER_MOVE) {}

            WorldPacket const* Write() override;

            Unit* mover;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            NewWorld() : ServerPacket(SMSG_NEW_WORLD, 24) {}

            WorldPacket const* Write() override;

            int32 MapID         = 0;
            uint32 Reason       = 0;
            Position Pos;
        };

        class WorldPortAck final : public ClientPacket
        {
        public:
            WorldPortAck(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override {};
        };
    }
}

#endif // MovementPackets_h__
