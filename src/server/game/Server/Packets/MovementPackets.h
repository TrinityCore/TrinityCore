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
#include "Optional.h"

namespace Movement
{
    class MoveSpline;
}

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

        struct MonsterSplineJumpExtraData
        {
            float JumpGravity = 0.0f;
            uint32 StartTime = 0;
        };

        struct MonsterSplineAnimTierTransition
        {
            uint32 StartTime = 0;
            uint8 AnimTier = 0;
        };

        struct MovementSpline
        {
            uint32 Flags = 0;    // Spline flags
            uint8 Face = 0;    // Movement direction (see MonsterMoveType enum)
            uint32 MoveTime = 0;
            std::vector<TaggedPosition<Position::XYZ>> Points;   // Spline path
            std::vector<TaggedPosition<Position::PackedXYZ>> PackedDeltas;
            Optional<MonsterSplineJumpExtraData> JumpExtraData;
            Optional<MonsterSplineAnimTierTransition> AnimTierTransition;
            float FaceDirection = 0.0f;
            ObjectGuid FaceGUID;
            TaggedPosition<Position::XYZ> FaceSpot;
        };

        struct MovementMonsterSpline
        {
            uint32 ID = 0;
            MovementSpline Move;
        };

        struct MovementSplineTransport
        {
            ObjectGuid TransportGUID;
            int8 VehicleSeat = -1;
        };

        class CommonMovement
        {
        public:
            static void WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data);
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            explicit MonsterMove() : ServerPacket(SMSG_MONSTER_MOVE, 64) { }

            void InitializeSplineData(::Movement::MoveSpline const& moveSpline);

            WorldPacket const* Write() override;

            MovementMonsterSpline SplineData;
            ObjectGuid MoverGUID;
            Optional<MovementSplineTransport> Transport;
            bool VehicleExitVoluntary = false;
            TaggedPosition<Position::XYZ> Pos;
        };

        class FlightSplineSync final : public ServerPacket
        {
        public:
            explicit FlightSplineSync() : ServerPacket(SMSG_FLIGHT_SPLINE_SYNC, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            float SplineDist = 0.0f;
        };

        class MoveSplineSetSpeed : public ServerPacket
        {
        public:
            explicit MoveSplineSetSpeed(OpcodeServer opcode) : ServerPacket(opcode, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            float Speed = 1.0f;
        };

        class MoveSetSpeed : public ServerPacket
        {
        public:
            explicit MoveSetSpeed(OpcodeServer opcode) : ServerPacket(opcode, 8 + 4 + 1 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0; ///< Unit movement packet index, incremented each time
            float Speed = 1.0f;
            bool Unknown = true;
        };

        class MoveUpdateSpeed : public ServerPacket
        {
        public:
            explicit MoveUpdateSpeed(OpcodeServer opcode) : ServerPacket(opcode, 8 + 30 + 4) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
            float Speed = 1.0f;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            explicit NewWorld() : ServerPacket(SMSG_NEW_WORLD, 4 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            Position Pos;
        };

        class WorldPortResponse final : public ClientPacket
        {
        public:
            explicit WorldPortResponse(WorldPacket&& packet) : ClientPacket(MSG_MOVE_WORLDPORT_ACK, std::move(packet)) { }

            void Read() override { }
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo);
ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);

#endif // TRINITYCORE_MOVEMENT_PACKETS_H
