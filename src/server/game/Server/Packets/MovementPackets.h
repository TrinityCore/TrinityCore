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

#ifndef MovementPackets_h__
#define MovementPackets_h__

#include "Packet.h"
#include "Object.h"
#include "Optional.h"

namespace Movement
{
    template<class index_type>
    class Spline;
    class MoveSpline;
}

namespace WorldPackets
{
    namespace Movement
    {
        struct MovementAck
        {
            MovementInfo Status;
            int32 AckIndex = 0;
        };

        struct ShipTransferPending
        {
            uint32 ID = 0;              ///< gameobject_template.entry of the transport the player is teleporting on
            int32 OriginMapID = -1;     ///< Map id the player is currently on (before teleport)
        };

        class TransferPending final : public ServerPacket
        {
        public:
            TransferPending() : ServerPacket(SMSG_TRANSFER_PENDING, 12) { }

            WorldPacket const* Write() override;

            int32 MapID = -1;
            Optional<ShipTransferPending> Ship;
            Optional<int32> TransferSpellID;
        };

        class SuspendToken final : public ServerPacket
        {
        public:
            SuspendToken() : ServerPacket(SMSG_SUSPEND_TOKEN, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 SequenceIndex = 1;
            uint8 Reason = 1;
        };

        class SuspendTokenResponse final : public ClientPacket
        {
        public:
            SuspendTokenResponse(WorldPacket&& packet) : ClientPacket(CMSG_SUSPEND_TOKEN_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 SequenceIndex = 0;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            NewWorld() : ServerPacket(SMSG_NEW_WORLD, 4 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            Position Pos;
        };

        class MoveSetCollisionHeight final : public ServerPacket
        {
        public:
            MoveSetCollisionHeight() : ServerPacket(SMSG_MOVE_SET_COLLISION_HEIGHT, 15) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0;
            float Height = 1.0f;
            UpdateCollisionHeightReason Reason = UPDATE_COLLISION_HEIGHT_MOUNT;
        };

        struct MoveKnockBackSpeeds
        {
            float HorzSpeed = 0.0f;
            float VertSpeed = 0.0f;
        };

        class MoveKnockBack final : public ServerPacket
        {
        public:
            MoveKnockBack() : ServerPacket(SMSG_MOVE_KNOCK_BACK, 1 + 8 + 4 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            TaggedPosition<Position::XY> Direction;
            MoveKnockBackSpeeds Speeds;
            uint32 SequenceIndex = 0;
        };

        struct VehicleTeleport
        {
            uint8 VehicleSeatIndex = 0;
            bool VehicleExitVoluntary = false;
            bool VehicleExitTeleport = false;
        };

        class MoveTeleport final : public ServerPacket
        {
        public:
            MoveTeleport() : ServerPacket(OpcodeServer(MSG_MOVE_TELEPORT), 12 + 4 + 8 + 8 + 4) { }

            WorldPacket const* Write() override;

            TaggedPosition<Position::XYZ> Pos;
            Optional<VehicleTeleport> Vehicle;
            uint32 SequenceIndex = 0;
            ObjectGuid MoverGUID;
            Optional<ObjectGuid> TransportGUID;
            float Facing = 0.0f;
        };

        class MoveTeleportAck final : public ClientPacket
        {
        public:
            MoveTeleportAck(WorldPacket&& packet) : ClientPacket(OpcodeClient(MSG_MOVE_TELEPORT_ACK), std::move(packet)) { }

            void Read() override;

            ObjectGuid MoverGUID;
            int32 AckIndex = 0;
            int32 MoveTime = 0;
        };

        class SetActiveMover final : public ClientPacket
        {
        public:
            SetActiveMover(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACTIVE_MOVER, std::move(packet)) { }

            void Read() override;

            ObjectGuid ActiveMover;
        };

        class MoveUpdateTeleport final : public ServerPacket
        {
        public:
            MoveUpdateTeleport() : ServerPacket(SMSG_MOVE_UPDATE_TELEPORT) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
        };

        struct MonsterSplineJumpExtraData
        {
            float JumpGravity = 0.0f;
            uint32 StartTime = 0;
        };

        struct MonsterSplineAnimationExtraData
        {
            uint8 AnimTier = 0;
            uint32 TierTransStartTime = 0;
        };

        struct MovementSpline
        {
            uint32 Flags                = 0;    // Spline flags
            uint8 Face                  = 0;    // Movement direction (see MonsterMoveType enum)
            uint32 MoveTime             = 0;
            std::vector<TaggedPosition<Position::XYZ>> Points;   // Spline path
            int8 VehicleExitVoluntary   = 0;
            ObjectGuid TransportGUID;
            int8 VehicleSeat            = -1;
            std::vector<TaggedPosition<Position::PackedXYZ>> PackedDeltas;
            Optional<MonsterSplineJumpExtraData> JumpExtraData;
            Optional<MonsterSplineAnimationExtraData> Animation;
            float FaceDirection         = 0.0f;
            ObjectGuid FaceGUID;
            TaggedPosition<Position::XYZ> FaceSpot;
        };

        struct MovementMonsterSpline
        {
            uint32 ID = 0;
            TaggedPosition<Position::XYZ> Destination;
            bool CrzTeleport = false;
            MovementSpline Move;
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            MonsterMove(bool onTransport) : ServerPacket(onTransport ? SMSG_ON_MONSTER_MOVE_TRANSPORT : SMSG_ON_MONSTER_MOVE) { }

            void InitializeSplineData(::Movement::MoveSpline const& moveSpline);

            WorldPacket const* Write() override;

            MovementMonsterSpline SplineData;
            ObjectGuid MoverGUID;
            TaggedPosition<Position::XYZ> Pos;
        };

        class FlightSplineSync final : public ServerPacket
        {
        public:
            FlightSplineSync() : ServerPacket(SMSG_FLIGHT_SPLINE_SYNC, 4 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            float SplineDist = 0.0f;
        };

        class TransferAborted final : public ServerPacket
        {
        public:
            TransferAborted() : ServerPacket(SMSG_TRANSFER_ABORTED, 4 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 MapID = 0;
            uint8 TransfertAbort = 0;
            uint8 Arg = 0;
        };

        class MoveSetActiveMover final : public ServerPacket
        {
        public:
            MoveSetActiveMover(ObjectGuid moverGuid) : ServerPacket(SMSG_MOVE_SET_ACTIVE_MOVER, 8), MoverGUID(moverGuid) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
        };

        class MoveSetVehicleRecID final : public ServerPacket
        {
        public:
            MoveSetVehicleRecID(ObjectGuid moverGuid) : ServerPacket(SMSG_MOVE_SET_VEHICLE_REC_ID, 8 + 4 + 4), MoverGUID(moverGuid) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0;
            int32 VehicleRecID = 0;
        };
    }

    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline);
}

#endif // MovementPackets_h__
