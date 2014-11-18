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
#include <G3D/Vector3.h>

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
            ServerPlayerMovement() : ServerPacket(SMSG_PLAYER_MOVE) { }

            WorldPacket const* Write() override;

            Unit* mover;
        };

        struct MonsterSplineFilterKey
        {
            int16 Idx;
            int16 Speed;
        };

        struct MonsterSplineFilter
        {
            std::vector<MonsterSplineFilterKey> FilterKeys;
            uint8 FilterFlags;
            float BaseSpeed;
            int16 StartOffset;
            float DistToPrevFilterKey;
            int16 AddedToStart;
        };

        struct MovementSpline
        {
            uint32 Flags                = 0;    // Spline flags
            uint8 Face                  = 0;    // Movement direction (see MonsterMoveType enum)
            uint8 AnimTier              = 0;
            uint32 TierTransStartTime   = 0;
            uint32 Elapsed              = 0;
            uint32 MoveTime             = 0;
            float JumpGravity           = 0.0f;
            uint32 SpecialTime          = 0;
            std::vector<G3D::Vector3> Points;        // Spline path
            uint8 Mode                  = 0;
            uint8 VehicleExitVoluntary  = 0;
            ObjectGuid TransportGUID;
            uint8 VehicleSeat           = 255;
            std::vector<G3D::Vector3> PackedDeltas;
            Optional<MonsterSplineFilter> SplineFilter;
            float FaceDirection         = 0.0f;
            ObjectGuid FaceGUID;
            G3D::Vector3 FaceSpot;
        };

        struct MovementMonsterSpline
        {
            uint32 ID;
            G3D::Vector3 Destination;
            bool CrzTeleport = false;
            MovementSpline Move;
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            MonsterMove() : ServerPacket(SMSG_MONSTER_MOVE) { }

            WorldPacket const* Write() override;

            MovementMonsterSpline SplineData;
            ObjectGuid MoverGUID;
            G3D::Vector3 Pos;
        };

        class MoveSplineSet : public ServerPacket
        {
        public:
            MoveSplineSet(OpcodeServer opcode) : ServerPacket(opcode, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            float Speed;
        };

        class MoveUpdate : public ServerPacket
        {
        public:
            MoveUpdate(OpcodeServer opcode) : ServerPacket(opcode) { }

            WorldPacket const* Write() override;

            MovementInfo movementInfo;
            float Speed;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            NewWorld() : ServerPacket(SMSG_NEW_WORLD, 24) { }

            WorldPacket const* Write() override;

            int32 MapID         = 0;
            uint32 Reason       = 0;
            Position Pos;
        };

        class WorldPortAck final : public ClientPacket
        {
        public:
            WorldPortAck(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override { }
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, const G3D::Vector3& v);
ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector3& v);

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo& movementInfo);

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineFilterKey const& monsterSplineFilterKey);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineFilter const& monsterSplineFilter);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementSpline const& movementSpline);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementMonsterSpline const& movementMonsterSpline);

#endif // MovementPackets_h__
