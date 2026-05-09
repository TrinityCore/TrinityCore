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
#include "MoveSpline.h"
#include "ObjectGuid.h"
#include <G3D/Vector3.h>

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

        struct MovementSpline
        {
            uint32 Flags                = 0;        // Spline flags (see MoveSplineFlag)
            uint8 Face                  = 0;        // Movement direction (see MonsterMoveType)
            uint8 AnimTier              = 0;
            uint32 TierTransStartTime   = 0;
            uint32 MoveTime             = 0;
            float JumpGravity           = 0.0f;
            uint32 SpecialTime          = 0;
            std::vector<G3D::Vector3> Points;       // Spline path (CatmullRom) or single destination point (Linear)
            std::vector<G3D::Vector3> PackedDeltas; // Linear path offsets (encoded as PackedXYZ on the wire)
            float FaceDirection         = 0.0f;
            ObjectGuid FaceGUID;
            G3D::Vector3 FaceSpot;
        };

        struct MovementMonsterSpline
        {
            uint32 ID = 0;
            ObjectGuid TransportGUID;
            int8 VehicleSeat = -1;
            G3D::Vector3 Destination;
            MovementSpline Move;
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            MonsterMove() : ServerPacket(SMSG_MONSTER_MOVE) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            MovementMonsterSpline SplineData;
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

ByteBuffer& operator<<(ByteBuffer& data, const G3D::Vector3& v);
ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector3& v);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo);
ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementSpline const& movementSpline);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementMonsterSpline const& movementMonsterSpline);

#endif // TRINITYCORE_MOVEMENT_PACKETS_H
