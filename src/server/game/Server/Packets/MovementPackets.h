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

#ifndef MovementPackets_h__
#define MovementPackets_h__

#include "Packet.h"
#include "Object.h"

#include <G3D/Vector3.h>

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
            ClientPlayerMovement(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            MovementInfo movementInfo;
        };

        class TC_GAME_API MoveUpdate final : public ServerPacket
        {
        public:
            MoveUpdate() : ServerPacket(SMSG_MOVE_UPDATE) { }

            WorldPacket const* Write() override;

            MovementInfo* movementInfo = nullptr;
        };

        struct MonsterSplineFilterKey
        {
            int16 Idx   = 0;
            int16 Speed = 0;
        };

        struct MonsterSplineFilter
        {
            std::vector<MonsterSplineFilterKey> FilterKeys;
            uint8 FilterFlags           = 0;
            float BaseSpeed             = 0.0f;
            int16 StartOffset           = 0;
            float DistToPrevFilterKey   = 0.0f;
            int16 AddedToStart          = 0;
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
            std::vector<G3D::Vector3> Points;   // Spline path
            uint8 Mode                  = 0;    // Spline mode - actually always 0 in this packet - Catmullrom mode appears only in SMSG_UPDATE_OBJECT. In this packet it is determined by flags
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
            uint32 ID = 0;
            G3D::Vector3 Destination;
            bool CrzTeleport = false;
            MovementSpline Move;
        };

        class CommonMovement
        {
        public:
            static void WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data);
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            MonsterMove() : ServerPacket(SMSG_ON_MONSTER_MOVE) { }

            void InitializeSplineData(::Movement::MoveSpline const& moveSpline);

            WorldPacket const* Write() override;

            MovementMonsterSpline SplineData;
            ObjectGuid MoverGUID;
            G3D::Vector3 Pos;
        };

        class MoveSplineSetSpeed : public ServerPacket
        {
        public:
            MoveSplineSetSpeed(OpcodeServer opcode) : ServerPacket(opcode, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            float Speed = 1.0f;
        };

        class MoveSetSpeed : public ServerPacket
        {
        public:
            MoveSetSpeed(OpcodeServer opcode) : ServerPacket(opcode) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0; ///< Unit movement packet index, incremented each time
            float Speed = 1.0f;
        };

        class MoveUpdateSpeed : public ServerPacket
        {
        public:
            MoveUpdateSpeed(OpcodeServer opcode) : ServerPacket(opcode) { }

            WorldPacket const* Write() override;

            MovementInfo* movementInfo = nullptr;
            float Speed = 1.0f;
        };

        class MoveSplineSetFlag final : public ServerPacket
        {
        public:
            MoveSplineSetFlag(OpcodeServer opcode) : ServerPacket(opcode, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
        };

        class MoveSetFlag final : public ServerPacket
        {
        public:
            MoveSetFlag(OpcodeServer opcode) : ServerPacket(opcode, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0; ///< Unit movement packet index, incremented each time
        };

        class TransferPending final : public ServerPacket
        {
            struct ShipTransferPending
            {
                uint32 ID = 0;              ///< gameobject_template.entry of the transport the player is teleporting on
                int32 OriginMapID = -1;     ///< Map id the player is currently on (before teleport)
            };

        public:
            TransferPending() : ServerPacket(SMSG_TRANSFER_PENDING, 16) { }

            WorldPacket const* Write() override;

            int32 MapID = -1;
            Optional<ShipTransferPending> Ship;
            Optional<int32> TransferSpellID;
        };

        class TransferAborted final : public ServerPacket
        {
        public:
            TransferAborted() : ServerPacket(SMSG_TRANSFER_ABORTED, 4 + 1 + 4) { }

            WorldPacket const* Write() override;

            uint32 TransfertAbort = 0;
            uint8 Arg = 0;
            uint32 MapID = 0;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            NewWorld() : ServerPacket(SMSG_NEW_WORLD, 24) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            uint32 Reason = 0;
            Position Pos;
        };

        class WorldPortResponse final : public ClientPacket
        {
        public:
            WorldPortResponse(WorldPacket&& packet) : ClientPacket(CMSG_WORLD_PORT_RESPONSE, std::move(packet)) { }

            void Read() override { }
        };

        struct VehicleTeleport
        {
            uint8 VehicleSeatIndex      = 0;
            bool VehicleExitVoluntary   = false;
            bool VehicleExitTeleport    = false;
        };

        class MoveTeleport final : public ServerPacket
        {
        public:
            MoveTeleport() : ServerPacket(SMSG_MOVE_TELEPORT, 12+4+16+16+4) { }

            WorldPacket const* Write() override;

            Position Pos;
            Optional<VehicleTeleport> Vehicle;
            uint32 SequenceIndex = 0;
            ObjectGuid MoverGUID;
            Optional<ObjectGuid> TransportGUID;
            float Facing = 0.0f;
        };

        struct MovementForce
        {
            ObjectGuid ID;
            G3D::Vector3 Direction;
            G3D::Vector3 TransportPosition;
            uint32 TransportID  = 0;
            float Magnitude     = 0;
            uint8 Type          = 0;
        };

        class MoveUpdateTeleport final : public ServerPacket
        {
        public:
            MoveUpdateTeleport() : ServerPacket(SMSG_MOVE_UPDATE_TELEPORT) { }

            WorldPacket const* Write() override;

            MovementInfo* movementInfo = nullptr;
            std::vector<MovementForce> MovementForces;
            Optional<float> SwimBackSpeed;
            Optional<float> FlightSpeed;
            Optional<float> SwimSpeed;
            Optional<float> WalkSpeed;
            Optional<float> TurnRate;
            Optional<float> RunSpeed;
            Optional<float> FlightBackSpeed;
            Optional<float> RunBackSpeed;
            Optional<float> PitchRate;
        };

        class MoveTeleportAck final : public ClientPacket
        {
        public:
            MoveTeleportAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_TELEPORT_ACK, std::move(packet)) { }

            void Read() override;

            ObjectGuid MoverGUID;
            int32 AckIndex = 0;
            int32 MoveTime = 0;
        };

        struct MovementAck
        {
            MovementInfo movementInfo;
            int32 AckIndex = 0;
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
            float Speed = 0.0f;
        };

        class SetActiveMover final : public ClientPacket
        {
        public:
            SetActiveMover(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACTIVE_MOVER, std::move(packet)) { }

            void Read() override;

            ObjectGuid ActiveMover;
        };

        class MoveSetActiveMover final : public ServerPacket
        {
        public:
            MoveSetActiveMover() : ServerPacket(SMSG_MOVE_SET_ACTIVE_MOVER, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
        };

        class MoveKnockBack final : public ServerPacket
        {
        public:
            MoveKnockBack() : ServerPacket(SMSG_MOVE_KNOCK_BACK, 16 + 8 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            G3D::Vector2 Direction;
            float HorzSpeed = 0.0f;
            uint32 SequenceIndex = 0;
            float VertSpeed = 0.0f;
        };

        class MoveUpdateKnockBack final : public ServerPacket
        {
        public:
            MoveUpdateKnockBack() : ServerPacket(SMSG_MOVE_UPDATE_KNOCK_BACK) { }

            WorldPacket const* Write() override;

            MovementInfo* movementInfo = nullptr;
        };

        enum UpdateCollisionHeightReason : uint8
        {
            UPDATE_COLLISION_HEIGHT_SCALE = 0,
            UPDATE_COLLISION_HEIGHT_MOUNT = 1,
            UPDATE_COLLISION_HEIGHT_FORCE = 2
        };

        class MoveSetCollisionHeight final : public ServerPacket
        {
        public:
            MoveSetCollisionHeight() : ServerPacket(SMSG_MOVE_SET_COLLISION_HEIGHT, 4 + 16 + 4 + 1 + 4 + 4) { }

            WorldPacket const* Write() override;

            float Scale = 1.0f;
            ObjectGuid MoverGUID;
            uint32 MountDisplayID = 0;
            UpdateCollisionHeightReason Reason = UPDATE_COLLISION_HEIGHT_MOUNT;
            uint32 SequenceIndex = 0;
            float Height = 1.0f;
        };

        class MoveUpdateCollisionHeight final : public ServerPacket
        {
        public:
            MoveUpdateCollisionHeight() : ServerPacket(SMSG_MOVE_UPDATE_COLLISION_HEIGHT) { }

            WorldPacket const* Write() override;

            MovementInfo* movementInfo = nullptr;
            float Scale = 1.0f;
            float Height = 1.0f;
        };

        class MoveSetCollisionHeightAck final : public ClientPacket
        {
        public:
            MoveSetCollisionHeightAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SET_COLLISION_HEIGHT_ACK, std::move(packet)) { }

            void Read() override;

            MovementAck Data;
            UpdateCollisionHeightReason Reason = UPDATE_COLLISION_HEIGHT_MOUNT;
            uint32 MountDisplayID = 0;
            float Height = 1.0f;
        };

        class MoveTimeSkipped final : public ClientPacket
        {
        public:
            MoveTimeSkipped(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_TIME_SKIPPED, std::move(packet)) { }

            void Read() override;

            ObjectGuid MoverGUID;
            uint32 TimeSkipped = 0;
        };

        class SummonResponse final : public ClientPacket
        {
        public:
            SummonResponse(WorldPacket&& packet) : ClientPacket(CMSG_SUMMON_RESPONSE, std::move(packet)) { }

            void Read() override;

            bool Accept = false;
            ObjectGuid SummonerGUID;
        };

        class TC_GAME_API ControlUpdate final : public ServerPacket
        {
        public:
            ControlUpdate() : ServerPacket(SMSG_CONTROL_UPDATE, 16 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            bool On = false;
        };

        class MoveSplineDone final : public ClientPacket
        {
        public:
            MoveSplineDone(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SPLINE_DONE, std::move(packet)) { }

            void Read() override;

            MovementInfo movementInfo;
            int32 SplineID = 0;
        };

        class SummonRequest final : public ServerPacket
        {
        public:
            SummonRequest() : ServerPacket(SMSG_SUMMON_REQUEST, 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid SummonerGUID;
            uint32 SummonerVirtualRealmAddress = 0;
            int32 AreaID = 0;
            bool SkipStartingArea = false;
        };

        class SuspendToken final : public ServerPacket
        {
        public:
            SuspendToken() : ServerPacket(SMSG_SUSPEND_TOKEN, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 SequenceIndex = 1;
            uint32 Reason = 1;
        };

        class SuspendTokenResponse final : public ClientPacket
        {
        public:
            SuspendTokenResponse(WorldPacket&& packet) : ClientPacket(CMSG_SUSPEND_TOKEN_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 SequenceIndex = 0;
        };

        class ResumeToken final : public ServerPacket
        {
        public:
            ResumeToken() : ServerPacket(SMSG_RESUME_TOKEN, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 SequenceIndex = 1;
            uint32 Reason = 1;
        };
    }

    ByteBuffer& operator<<(ByteBuffer& data, Movement::MonsterSplineFilterKey const& monsterSplineFilterKey);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MonsterSplineFilter const& monsterSplineFilter);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline);
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo& movementInfo);

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo::TransportInfo& transportInfo);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo::TransportInfo const& transportInfo);
ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& movementAck);

#endif // MovementPackets_h__
