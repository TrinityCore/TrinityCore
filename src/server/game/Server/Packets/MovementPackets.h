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
#include "CombatLogPacketsCommon.h"
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

        class ClientPlayerMovement final : public ClientPacket
        {
        public:
            ClientPlayerMovement(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            MovementInfo Status;
        };

        class TC_GAME_API MoveUpdate final : public ServerPacket
        {
        public:
            MoveUpdate() : ServerPacket(SMSG_MOVE_UPDATE) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
        };

        struct MonsterSplineFilterKey
        {
            int16 Idx    = 0;
            uint16 Speed = 0;
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

        struct MonsterSplineSpellEffectExtraData
        {
            ObjectGuid TargetGUID;
            uint32 SpellVisualID = 0;
            uint32 ProgressCurveID = 0;
            uint32 ParabolicCurveID = 0;
            float JumpGravity = 0.0f;
        };

        struct MonsterSplineJumpExtraData
        {
            float JumpGravity = 0.0f;
            uint32 StartTime = 0;
            uint32 Duration = 0;
        };

        struct MonsterSplineAnimTierTransition
        {
            int32 TierTransitionID = 0;
            uint32 StartTime = 0;
            uint32 EndTime = 0;
            uint8 AnimTier = 0;
        };

        struct MonsterSplineUnknown901
        {
            struct Inner
            {
                int32 Unknown_1 = 0;
                Spells::SpellCastVisual Visual;
                uint32 Unknown_4 = 0;
            };

            std::array<Inner, 16> Data;
        };

        struct MovementSpline
        {
            uint32 Flags                = 0;    // Spline flags
            uint8 Face                  = 0;    // Movement direction (see MonsterMoveType enum)
            int32 Elapsed               = 0;
            uint32 MoveTime             = 0;
            uint32 FadeObjectTime       = 0;
            std::vector<TaggedPosition<Position::XYZ>> Points;   // Spline path
            uint8 Mode                  = 0;    // Spline mode - actually always 0 in this packet - Catmullrom mode appears only in SMSG_UPDATE_OBJECT. In this packet it is determined by flags
            bool VehicleExitVoluntary   = false;
            bool Interpolate            = false;
            ObjectGuid TransportGUID;
            int8 VehicleSeat            = -1;
            std::vector<TaggedPosition<Position::PackedXYZ>> PackedDeltas;
            Optional<MonsterSplineFilter> SplineFilter;
            Optional<MonsterSplineSpellEffectExtraData> SpellEffectExtraData;
            Optional<MonsterSplineJumpExtraData> JumpExtraData;
            Optional<MonsterSplineAnimTierTransition> AnimTierTransition;
            Optional<MonsterSplineUnknown901> Unknown901;
            float FaceDirection         = 0.0f;
            ObjectGuid FaceGUID;
            TaggedPosition<Position::XYZ> FaceSpot;
        };

        struct MovementMonsterSpline
        {
            uint32 ID = 0;
            bool CrzTeleport = false;
            uint8 StopDistanceTolerance = 0;    // Determines how far from spline destination the mover is allowed to stop in place 0, 0, 3.0, 2.76, numeric_limits<float>::max, 1.1, float(INT_MAX); default before this field existed was distance 3.0 (index 2)
            MovementSpline Move;
        };

        class CommonMovement
        {
        public:
            static void WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data);
            static void WriteCreateObjectAreaTriggerSpline(::Movement::Spline<int32> const& spline, ByteBuffer& data);

            static void WriteMovementForceWithDirection(MovementForce const& movementForce, ByteBuffer& data, Position const* objectPosition = nullptr);
        };

        class MonsterMove final : public ServerPacket
        {
        public:
            MonsterMove() : ServerPacket(SMSG_ON_MONSTER_MOVE) { }

            void InitializeSplineData(::Movement::MoveSpline const& moveSpline);

            WorldPacket const* Write() override;

            MovementMonsterSpline SplineData;
            ObjectGuid MoverGUID;
            TaggedPosition<Position::XYZ> Pos;
        };

        class FlightSplineSync final : public ServerPacket
        {
        public:
            FlightSplineSync() : ServerPacket(SMSG_FLIGHT_SPLINE_SYNC, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            float SplineDist = 0.0f;
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

            MovementInfo* Status = nullptr;
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

        struct ShipTransferPending
        {
            uint32 ID = 0;              ///< gameobject_template.entry of the transport the player is teleporting on
            int32 OriginMapID = -1;     ///< Map id the player is currently on (before teleport)
        };

        class TransferPending final : public ServerPacket
        {
        public:
            TransferPending() : ServerPacket(SMSG_TRANSFER_PENDING, 16) { }

            WorldPacket const* Write() override;

            int32 MapID = -1;
            TaggedPosition<Position::XYZ> OldMapPosition;
            Optional<ShipTransferPending> Ship;
            Optional<int32> TransferSpellID;
        };

        class TransferAborted final : public ServerPacket
        {
        public:
            TransferAborted() : ServerPacket(SMSG_TRANSFER_ABORTED, 4 + 1 + 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 MapID = 0;
            uint8 Arg = 0;
            int32 MapDifficultyXConditionID = 0;
            uint32 TransfertAbort = 0;
        };

        struct TeleportLocation
        {
            TaggedPosition<Position::XYZO> Pos;
            int32 Unused901_1 = -1;
            int32 Unused901_2 = -1;
        };

        class NewWorld final : public ServerPacket
        {
        public:
            NewWorld() : ServerPacket(SMSG_NEW_WORLD, 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            uint32 Reason = 0;
            TeleportLocation Loc;
            TaggedPosition<Position::XYZ> MovementOffset;    // Adjusts all pending movement events by this offset
            int32 Counter = 0;
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

            TaggedPosition<Position::XYZ> Pos;
            Optional<VehicleTeleport> Vehicle;
            uint32 SequenceIndex = 0;
            ObjectGuid MoverGUID;
            Optional<ObjectGuid> TransportGUID;
            float Facing = 0.0f;
            uint8 PreloadWorld = 0;
        };

        class MoveUpdateTeleport final : public ServerPacket
        {
        public:
            MoveUpdateTeleport() : ServerPacket(SMSG_MOVE_UPDATE_TELEPORT) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
            ::MovementForces::Container const* MovementForces = nullptr;
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

        class MoveApplyMovementForce final : public ServerPacket
        {
        public:
            MoveApplyMovementForce() : ServerPacket(SMSG_MOVE_APPLY_MOVEMENT_FORCE, 16 + 4 + 16 + 12 + 12 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            int32 SequenceIndex = 0;
            MovementForce const* Force = nullptr;
        };

        class MoveApplyMovementForceAck final : public ClientPacket
        {
        public:
            MoveApplyMovementForceAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_APPLY_MOVEMENT_FORCE_ACK, std::move(packet)) { }

            void Read() override;

            MovementAck Ack;
            MovementForce Force;
        };

        class MoveRemoveMovementForce final : public ServerPacket
        {
        public:
            MoveRemoveMovementForce() : ServerPacket(SMSG_MOVE_REMOVE_MOVEMENT_FORCE, 16 + 4 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            int32 SequenceIndex = 0;
            ObjectGuid ID;
        };

        class MoveRemoveMovementForceAck final : public ClientPacket
        {
        public:
            MoveRemoveMovementForceAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_REMOVE_MOVEMENT_FORCE_ACK, std::move(packet)) { }

            void Read() override;

            MovementAck Ack;
            ObjectGuid ID;
        };

        class MoveUpdateApplyMovementForce final : public ServerPacket
        {
        public:
            MoveUpdateApplyMovementForce() : ServerPacket(SMSG_MOVE_UPDATE_APPLY_MOVEMENT_FORCE, sizeof(MovementInfo) + 16 + 12 + 12 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
            MovementForce const* Force = nullptr;
        };

        class MoveUpdateRemoveMovementForce final : public ServerPacket
        {
        public:
            MoveUpdateRemoveMovementForce() : ServerPacket(SMSG_MOVE_UPDATE_REMOVE_MOVEMENT_FORCE, sizeof(MovementInfo) + 16) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
            ObjectGuid TriggerGUID;
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

        struct MoveKnockBackSpeeds
        {
            float HorzSpeed = 0.0f;
            float VertSpeed = 0.0f;
        };

        class MoveKnockBack final : public ServerPacket
        {
        public:
            MoveKnockBack() : ServerPacket(SMSG_MOVE_KNOCK_BACK, 16 + 8 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            TaggedPosition<Position::XY> Direction;
            MoveKnockBackSpeeds Speeds;
            uint32 SequenceIndex = 0;
        };

        class MoveUpdateKnockBack final : public ServerPacket
        {
        public:
            MoveUpdateKnockBack() : ServerPacket(SMSG_MOVE_UPDATE_KNOCK_BACK) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
        };

        class MoveKnockBackAck final : public ClientPacket
        {
        public:
            MoveKnockBackAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_KNOCK_BACK_ACK, std::move(packet)) { }

            void Read() override;

            MovementAck Ack;
            Optional<MoveKnockBackSpeeds> Speeds;
        };

        enum class UpdateCollisionHeightReason : uint8
        {
            Scale   = 0,
            Mount   = 1,
            Force   = 2
        };

        class MoveSetCollisionHeight final : public ServerPacket
        {
        public:
            MoveSetCollisionHeight() : ServerPacket(SMSG_MOVE_SET_COLLISION_HEIGHT, 4 + 16 + 4 + 1 + 4 + 4) { }

            WorldPacket const* Write() override;

            float Scale = 1.0f;
            ObjectGuid MoverGUID;
            uint32 MountDisplayID = 0;
            UpdateCollisionHeightReason Reason = UpdateCollisionHeightReason::Scale;
            uint32 SequenceIndex = 0;
            int32 ScaleDuration = 0;
            float Height = 1.0f;
        };

        class MoveUpdateCollisionHeight final : public ServerPacket
        {
        public:
            MoveUpdateCollisionHeight() : ServerPacket(SMSG_MOVE_UPDATE_COLLISION_HEIGHT) { }

            WorldPacket const* Write() override;

            MovementInfo* Status = nullptr;
            float Scale = 1.0f;
            float Height = 1.0f;
        };

        class MoveSetCollisionHeightAck final : public ClientPacket
        {
        public:
            MoveSetCollisionHeightAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SET_COLLISION_HEIGHT_ACK, std::move(packet)) { }

            void Read() override;

            MovementAck Data;
            UpdateCollisionHeightReason Reason = UpdateCollisionHeightReason::Scale;
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

        class MoveSkipTime final : public ServerPacket
        {
        public:
            MoveSkipTime() : ServerPacket(SMSG_MOVE_SKIP_TIME, 16 + 4) { }

            WorldPacket const* Write() override;

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

            MovementInfo Status;
            int32 SplineID = 0;
        };

        class SummonRequest final : public ServerPacket
        {
        public:
            enum SummonReason : uint8
            {
                SPELL = 0,
                SCENARIO = 1
            };

            SummonRequest() : ServerPacket(SMSG_SUMMON_REQUEST, 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid SummonerGUID;
            uint32 SummonerVirtualRealmAddress = 0;
            int32 AreaID = 0;
            SummonReason Reason = SPELL;
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

        class MoveSetCompoundState final : public ServerPacket
        {
        public:
            struct CollisionHeightInfo
            {
                float Height = 0.0f;
                float Scale = 0.0f;
                UpdateCollisionHeightReason Reason = UpdateCollisionHeightReason::Scale;
            };

            struct KnockBackInfo
            {
                float HorzSpeed = 0.0f;
                TaggedPosition<Position::XY> Direction;
                float InitVertSpeed = 0.0f;
            };

            struct SpeedRange
            {
                float Min = 0.0f;
                float Max = 0.0f;
            };

            struct MoveStateChange
            {
                MoveStateChange(OpcodeServer messageId, uint32 sequenceIndex) : MessageID(messageId), SequenceIndex(sequenceIndex) { }

                uint16 MessageID = 0;
                uint32 SequenceIndex = 0;
                Optional<float> Speed;
                Optional<MoveSetCompoundState::SpeedRange> SpeedRange;
                Optional<KnockBackInfo> KnockBack;
                Optional<int32> VehicleRecID;
                Optional<CollisionHeightInfo> CollisionHeight;
                Optional<MovementForce> MovementForce_;
                Optional<ObjectGuid> MovementForceGUID;
                Optional<int32> MovementInertiaID;
                Optional<uint32> MovementInertiaLifetimeMs;
            };

            MoveSetCompoundState() : ServerPacket(SMSG_MOVE_SET_COMPOUND_STATE, 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            std::vector<MoveStateChange> StateChanges;
        };

        class MoveInitActiveMoverComplete final : public ClientPacket
        {
        public:
            MoveInitActiveMoverComplete(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_INIT_ACTIVE_MOVER_COMPLETE, std::move(packet)) { }

            void Read() override;

            uint32 Ticks = 0;
        };
    }

    ByteBuffer& operator<<(ByteBuffer& data, Movement::MonsterSplineFilterKey const& monsterSplineFilterKey);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MonsterSplineFilter const& monsterSplineFilter);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline);
    ByteBuffer& operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline);
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo);

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo::TransportInfo& transportInfo);
ByteBuffer& operator<<(ByteBuffer& data, MovementInfo::TransportInfo const& transportInfo);
ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& movementAck);
ByteBuffer& operator<<(ByteBuffer& data, MovementForce const& movementForce);

#endif // MovementPackets_h__
