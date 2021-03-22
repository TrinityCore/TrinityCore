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

#include "MovementPackets.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "PacketUtilities.h"
#include "Unit.h"

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo)
{
    bool hasTransportData = !movementInfo.transport.guid.IsEmpty();
    bool hasFallDirection = movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
    bool hasFallData = hasFallDirection || movementInfo.jump.fallTime != 0;
    bool hasSpline = false; // todo 6.x send this infos

    data << movementInfo.guid;
    data << movementInfo.time;
    data << movementInfo.pos.PositionXYZOStream();
    data << movementInfo.pitch;
    data << movementInfo.splineElevation;

    uint32 removeMovementForcesCount = 0;
    data << removeMovementForcesCount;

    uint32 int168 = 0;
    data << int168;

    /*for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        data << ObjectGuid;
    }*/

    data.WriteBits(movementInfo.flags, 30);
    data.WriteBits(movementInfo.flags2, 18);

    data.WriteBit(hasTransportData);
    data.WriteBit(hasFallData);
    data.WriteBit(hasSpline);

    data.WriteBit(false); // HeightChangeFailed
    data.WriteBit(false); // RemoteTimeValid

    data.FlushBits();

    if (hasTransportData)
        data << movementInfo.transport;

    if (hasFallData)
    {
        data << movementInfo.jump.fallTime;
        data << movementInfo.jump.zspeed;

        data.WriteBit(hasFallDirection);
        data.FlushBits();
        if (hasFallDirection)
        {
            data << movementInfo.jump.sinAngle;
            data << movementInfo.jump.cosAngle;
            data << movementInfo.jump.xyspeed;
        }
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo)
{
    //bool hasSpline = false;

    data >> movementInfo.guid;
    data >> movementInfo.time;
    data >> movementInfo.pos.PositionXYZOStream();
    data >> movementInfo.pitch;
    data >> movementInfo.splineElevation;

    uint32 removeMovementForcesCount;
    data >> removeMovementForcesCount;

    uint32 moveIndex;
    data >> moveIndex;

    for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        ObjectGuid guid;
        data >> guid;
    }

    movementInfo.flags = data.ReadBits(30);
    movementInfo.flags2 = data.ReadBits(18);

    bool hasTransport = data.ReadBit();
    bool hasFall = data.ReadBit();
    /*hasSpline = */data.ReadBit(); // todo 6.x read this infos

    data.ReadBit(); // HeightChangeFailed
    data.ReadBit(); // RemoteTimeValid

    if (hasTransport)
        data >> movementInfo.transport;

    if (hasFall)
    {
        data >> movementInfo.jump.fallTime;
        data >> movementInfo.jump.zspeed;

        // ResetBitReader

        bool hasFallDirection = data.ReadBit();
        if (hasFallDirection)
        {
            data >> movementInfo.jump.sinAngle;
            data >> movementInfo.jump.cosAngle;
            data >> movementInfo.jump.xyspeed;
        }
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo::TransportInfo& transportInfo)
{
    data >> transportInfo.guid;                 // Transport Guid
    data >> transportInfo.pos.PositionXYZOStream();
    data >> transportInfo.seat;                 // VehicleSeatIndex
    data >> transportInfo.time;                 // MoveTime

    bool hasPrevTime = data.ReadBit();
    bool hasVehicleId = data.ReadBit();

    if (hasPrevTime)
        data >> transportInfo.prevTime;         // PrevMoveTime

    if (hasVehicleId)
        data >> transportInfo.vehicleId;        // VehicleRecID

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo::TransportInfo const& transportInfo)
{
    bool hasPrevTime = transportInfo.prevTime != 0;
    bool hasVehicleId = transportInfo.vehicleId != 0;

    data << transportInfo.guid;                 // Transport Guid
    data << transportInfo.pos.GetPositionX();
    data << transportInfo.pos.GetPositionY();
    data << transportInfo.pos.GetPositionZ();
    data << transportInfo.pos.GetOrientation();
    data << transportInfo.seat;                 // VehicleSeatIndex
    data << transportInfo.time;                 // MoveTime

    data.WriteBit(hasPrevTime);
    data.WriteBit(hasVehicleId);

    data.FlushBits();

    if (hasPrevTime)
        data << transportInfo.prevTime;         // PrevMoveTime

    if (hasVehicleId)
        data << transportInfo.vehicleId;        // VehicleRecID

    return data;
}

void WorldPackets::Movement::ClientPlayerMovement::Read()
{
    _worldPacket >> Status;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MonsterSplineFilterKey const& monsterSplineFilterKey)
{
    data << int16(monsterSplineFilterKey.Idx);
    data << uint16(monsterSplineFilterKey.Speed);

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MonsterSplineFilter const& monsterSplineFilter)
{
    data << uint32(monsterSplineFilter.FilterKeys.size());
    data << float(monsterSplineFilter.BaseSpeed);
    data << int16(monsterSplineFilter.StartOffset);
    data << float(monsterSplineFilter.DistToPrevFilterKey);
    data << int16(monsterSplineFilter.AddedToStart);
    for (WorldPackets::Movement::MonsterSplineFilterKey const& filterKey : monsterSplineFilter.FilterKeys)
        data << filterKey;
    data.WriteBits(monsterSplineFilter.FilterFlags, 2);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineSpellEffectExtraData const& spellEffectExtraData)
{
    data << spellEffectExtraData.TargetGUID;
    data << uint32(spellEffectExtraData.SpellVisualID);
    data << uint32(spellEffectExtraData.ProgressCurveID);
    data << uint32(spellEffectExtraData.ParabolicCurveID);
    data << float(spellEffectExtraData.JumpGravity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineJumpExtraData const& jumpExtraData)
{
    data << float(jumpExtraData.JumpGravity);
    data << uint32(jumpExtraData.StartTime);
    data << uint32(jumpExtraData.Duration);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineAnimTierTransition const& animTierTransition)
{
    data << int32(animTierTransition.TierTransitionID);
    data << uint32(animTierTransition.StartTime);
    data << uint32(animTierTransition.EndTime);
    data << uint8(animTierTransition.AnimTier);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MonsterSplineUnknown901 const& unk)
{
    for (WorldPackets::Movement::MonsterSplineUnknown901::Inner const& unkInner : unk.Data)
    {
        data << int32(unkInner.Unknown_1);
        data << int32(unkInner.Unknown_2);
        data << int32(unkInner.Unknown_3);
        data << uint32(unkInner.Unknown_4);
    }

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementSpline const& movementSpline)
{
    data << uint32(movementSpline.Flags);
    data << int32(movementSpline.Elapsed);
    data << uint32(movementSpline.MoveTime);
    data << uint32(movementSpline.FadeObjectTime);
    data << uint8(movementSpline.Mode);
    data << movementSpline.TransportGUID;
    data << int8(movementSpline.VehicleSeat);
    data.WriteBits(movementSpline.Face, 2);
    data.WriteBits(movementSpline.Points.size(), 16);
    data.WriteBit(movementSpline.VehicleExitVoluntary);
    data.WriteBit(movementSpline.Interpolate);
    data.WriteBits(movementSpline.PackedDeltas.size(), 16);
    data.WriteBit(movementSpline.SplineFilter.is_initialized());
    data.WriteBit(movementSpline.SpellEffectExtraData.is_initialized());
    data.WriteBit(movementSpline.JumpExtraData.is_initialized());
    data.WriteBit(movementSpline.AnimTierTransition.is_initialized());
    data.WriteBit(movementSpline.Unknown901.is_initialized());
    data.FlushBits();

    if (movementSpline.SplineFilter)
        data << *movementSpline.SplineFilter;

    switch (movementSpline.Face)
    {
        case ::Movement::MONSTER_MOVE_FACING_SPOT:
            data << movementSpline.FaceSpot;
            break;
        case ::Movement::MONSTER_MOVE_FACING_TARGET:
            data << float(movementSpline.FaceDirection);
            data << movementSpline.FaceGUID;
            break;
        case ::Movement::MONSTER_MOVE_FACING_ANGLE:
            data << float(movementSpline.FaceDirection);
            break;
    }

    for (TaggedPosition<Position::XYZ> const& pos : movementSpline.Points)
        data << pos;

    for (TaggedPosition<Position::PackedXYZ> const& pos : movementSpline.PackedDeltas)
        data << pos;

    if (movementSpline.SpellEffectExtraData)
        data << *movementSpline.SpellEffectExtraData;

    if (movementSpline.JumpExtraData)
        data << *movementSpline.JumpExtraData;

    if (movementSpline.AnimTierTransition)
        data << *movementSpline.AnimTierTransition;

    if (movementSpline.Unknown901)
        data << *movementSpline.Unknown901;

    return data;
}

ByteBuffer& WorldPackets::operator<<(ByteBuffer& data, Movement::MovementMonsterSpline const& movementMonsterSpline)
{
    data << movementMonsterSpline.ID;
    data << movementMonsterSpline.Destination;
    data.WriteBit(movementMonsterSpline.CrzTeleport);
    data.WriteBits(movementMonsterSpline.StopDistanceTolerance, 3);

    data << movementMonsterSpline.Move;

    return data;
}

void WorldPackets::Movement::CommonMovement::WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data)
{
    data << uint32(moveSpline.GetId());                                         // ID

    G3D::Vector3 dest;
    if (!moveSpline.isCyclic())                                                 // Destination
        dest = moveSpline.FinalDestination();
    else
        dest = G3D::Vector3::zero();

    data << dest.x << dest.y << dest.z;

    bool hasSplineMove = data.WriteBit(!moveSpline.Finalized() && !moveSpline.splineIsFacingOnly);
    data.FlushBits();

    if (hasSplineMove)                                                          // MovementSplineMove
    {
        data << uint32(moveSpline.splineflags.raw());                           // SplineFlags
        data << int32(moveSpline.timePassed());                                 // Elapsed
        data << uint32(moveSpline.Duration());                                  // Duration
        data << float(1.0f);                                                    // DurationModifier
        data << float(1.0f);                                                    // NextDurationModifier
        data.WriteBits(moveSpline.facing.type, 2);                              // Face
        bool hasFadeObjectTime = data.WriteBit(moveSpline.splineflags.fadeObject && moveSpline.effect_start_time < moveSpline.Duration());
        data.WriteBits(moveSpline.getPath().size(), 16);
        data.WriteBit(false);                                                   // HasSplineFilter
        data.WriteBit(moveSpline.spell_effect_extra.is_initialized());          // HasSpellEffectExtraData
        data.WriteBit(moveSpline.splineflags.parabolic);                        // HasJumpExtraData
        data.WriteBit(moveSpline.anim_tier.is_initialized());                   // HasAnimationTierTransition
        data.WriteBit(false);                                                   // HasUnknown901
        data.FlushBits();

        //if (HasSplineFilterKey)
        //{
        //    data << uint32(FilterKeysCount);
        //    for (var i = 0; i < FilterKeysCount; ++i)
        //    {
        //        data << float(In);
        //        data << float(Out);
        //    }

        //    data.WriteBits(FilterFlags, 2);
        //    data.FlushBits();
        //}

        switch (moveSpline.facing.type)
        {
            case ::Movement::MONSTER_MOVE_FACING_SPOT:
            {
                // FaceSpot
                data << float(moveSpline.facing.f.x);
                data << float(moveSpline.facing.f.y);
                data << float(moveSpline.facing.f.z);
                break;
            }
            case ::Movement::MONSTER_MOVE_FACING_TARGET:
                data << moveSpline.facing.target;   // FaceGUID
                break;
            case ::Movement::MONSTER_MOVE_FACING_ANGLE:
                data << moveSpline.facing.angle;    // FaceDirection
                break;
            default:
                break;
        }

        if (hasFadeObjectTime)
            data << uint32(moveSpline.effect_start_time);                       // FadeObjectTime

        data.append(moveSpline.getPath().data(), moveSpline.getPath().size());

        if (moveSpline.spell_effect_extra)
        {
            data << moveSpline.spell_effect_extra->Target;
            data << uint32(moveSpline.spell_effect_extra->SpellVisualId);
            data << uint32(moveSpline.spell_effect_extra->ProgressCurveId);
            data << uint32(moveSpline.spell_effect_extra->ParabolicCurveId);
            data << float(moveSpline.vertical_acceleration);
        }

        if (moveSpline.splineflags.parabolic)
        {
            data << float(moveSpline.vertical_acceleration);
            data << uint32(moveSpline.effect_start_time);
            data << uint32(0);                                                  // Duration (override)
        }

        if (moveSpline.anim_tier)
        {
            data << int32(moveSpline.anim_tier->TierTransitionId);
            data << uint32(moveSpline.effect_start_time);
            data << uint32(0);
            data << uint8(moveSpline.anim_tier->AnimTier);
        }

        //if (HasUnknown901)
        //{
        //    for (WorldPackets::Movement::MonsterSplineUnknown901::Inner const& unkInner : unk.Data) size = 16
        //    {
        //        data << int32(unkInner.Unknown_1);
        //        data << int32(unkInner.Unknown_2);
        //        data << int32(unkInner.Unknown_3);
        //        data << uint32(unkInner.Unknown_4);
        //    }
        //}
    }
}

void WorldPackets::Movement::CommonMovement::WriteCreateObjectAreaTriggerSpline(::Movement::Spline<int32> const& spline, ByteBuffer& data)
{
    data.WriteBits(spline.getPoints().size(), 16);
    data.append<G3D::Vector3>(spline.getPoints().data(), spline.getPoints().size());
}

void WorldPackets::Movement::CommonMovement::WriteMovementForceWithDirection(MovementForce const& movementForce, ByteBuffer& data, Position const* objectPosition /*= nullptr*/)
{
    data << movementForce.ID;
    data << movementForce.Origin;
    if (movementForce.Type == 1 && objectPosition) // gravity
    {
        TaggedPosition<Position::XYZ> direction;
        if (movementForce.Magnitude != 0.0f)
        {
            Position tmp(movementForce.Origin.Pos.GetPositionX() - objectPosition->GetPositionX(),
                movementForce.Origin.Pos.GetPositionY() - objectPosition->GetPositionY(),
                movementForce.Origin.Pos.GetPositionZ() - objectPosition->GetPositionZ());
            float lengthSquared = tmp.GetExactDistSq(0.0f, 0.0f, 0.0f);
            if (lengthSquared > 0.0f)
            {
                float mult = 1.0f / std::sqrt(lengthSquared) * movementForce.Magnitude;
                tmp.m_positionX *= mult;
                tmp.m_positionY *= mult;
                tmp.m_positionZ *= mult;
                float minLengthSquared = (tmp.GetPositionX() * tmp.GetPositionX() * 0.04f) +
                    (tmp.GetPositionY() * tmp.GetPositionY() * 0.04f) +
                    (tmp.GetPositionZ() * tmp.GetPositionZ() * 0.04f);
                if (lengthSquared > minLengthSquared)
                    direction = tmp;
            }
        }

        data << direction;
    }
    else
        data << movementForce.Direction;

    data << uint32(movementForce.TransportID);
    data << float(movementForce.Magnitude);
    data.WriteBits(movementForce.Type, 2);
    data.FlushBits();
}

void WorldPackets::Movement::MonsterMove::InitializeSplineData(::Movement::MoveSpline const& moveSpline)
{
    SplineData.ID = moveSpline.m_Id;
    WorldPackets::Movement::MovementSpline& movementSpline = SplineData.Move;

    ::Movement::MoveSplineFlag splineFlags = moveSpline.splineflags;
    splineFlags.enter_cycle = moveSpline.isCyclic();
    movementSpline.Flags = uint32(splineFlags & uint32(~::Movement::MoveSplineFlag::Mask_No_Monster_Move));
    movementSpline.Face = moveSpline.facing.type;
    movementSpline.FaceDirection = moveSpline.facing.angle;
    movementSpline.FaceGUID = moveSpline.facing.target;
    movementSpline.FaceSpot = Position(moveSpline.facing.f.x, moveSpline.facing.f.y, moveSpline.facing.f.z);

    if (splineFlags.animation)
    {
        movementSpline.AnimTierTransition.emplace();
        movementSpline.AnimTierTransition->TierTransitionID = moveSpline.anim_tier->TierTransitionId;
        movementSpline.AnimTierTransition->StartTime = moveSpline.effect_start_time;
        movementSpline.AnimTierTransition->AnimTier = moveSpline.anim_tier->AnimTier;
    }

    movementSpline.MoveTime = moveSpline.Duration();

    if (splineFlags.parabolic)
    {
        movementSpline.JumpExtraData.emplace();
        movementSpline.JumpExtraData->JumpGravity = moveSpline.vertical_acceleration;
        movementSpline.JumpExtraData->StartTime = moveSpline.effect_start_time;
    }

    if (splineFlags.fadeObject)
        movementSpline.FadeObjectTime = moveSpline.effect_start_time;

    if (moveSpline.spell_effect_extra)
    {
        movementSpline.SpellEffectExtraData.emplace();
        movementSpline.SpellEffectExtraData->TargetGUID = moveSpline.spell_effect_extra->Target;
        movementSpline.SpellEffectExtraData->SpellVisualID = moveSpline.spell_effect_extra->SpellVisualId;
        movementSpline.SpellEffectExtraData->ProgressCurveID = moveSpline.spell_effect_extra->ProgressCurveId;
        movementSpline.SpellEffectExtraData->ParabolicCurveID = moveSpline.spell_effect_extra->ParabolicCurveId;
        movementSpline.SpellEffectExtraData->JumpGravity = moveSpline.vertical_acceleration;
    }

    ::Movement::Spline<int32> const& spline = moveSpline.spline;
    std::vector<G3D::Vector3> const& array = spline.getPoints();

    if (splineFlags & ::Movement::MoveSplineFlag::UncompressedPath)
    {
        if (!splineFlags.cyclic)
        {
            uint32 count = spline.getPointCount() - 3;
            for (uint32 i = 0; i < count; ++i)
                movementSpline.Points.emplace_back(array[i + 2].x, array[i + 2].y, array[i + 2].z);
        }
        else
        {
            uint32 count = spline.getPointCount() - 3;
            movementSpline.Points.emplace_back(array[1].x, array[1].y, array[1].z);
            for (uint32 i = 0; i < count; ++i)
                movementSpline.Points.emplace_back(array[i + 1].x, array[i + 1].y, array[i + 1].z);
        }
    }
    else
    {
        uint32 lastIdx = spline.getPointCount() - 3;
        G3D::Vector3 const* realPath = &spline.getPoint(1);

        movementSpline.Points.emplace_back(realPath[lastIdx].x, realPath[lastIdx].y, realPath[lastIdx].z);

        if (lastIdx > 1)
        {
            G3D::Vector3 middle = (realPath[0] + realPath[lastIdx]) / 2.f;

            // first and last points already appended
            for (uint32 i = 1; i < lastIdx; ++i)
            {
                G3D::Vector3 delta = middle - realPath[i];
                movementSpline.PackedDeltas.emplace_back(delta.x, delta.y, delta.z);
            }
        }
    }
}

WorldPacket const* WorldPackets::Movement::MonsterMove::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Pos;
    _worldPacket << SplineData;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSplineSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateSpeed::Write()
{
    _worldPacket << *Status;
    _worldPacket << Speed;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSplineSetFlag::Write()
{
    _worldPacket << MoverGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveSetFlag::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdate::Write()
{
    _worldPacket << *Status;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::TransferPending::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << OldMapPosition;
    _worldPacket.WriteBit(Ship.is_initialized());
    _worldPacket.WriteBit(TransferSpellID.is_initialized());
    if (Ship)
    {
        _worldPacket << uint32(Ship->ID);
        _worldPacket << int32(Ship->OriginMapID);
    }

    if (TransferSpellID)
        _worldPacket << int32(*TransferSpellID);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::TransferAborted::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << uint8(Arg);
    _worldPacket << int32(MapDifficultyXConditionID);
    _worldPacket.WriteBits(TransfertAbort, 5);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::TeleportLocation const& teleportLocation)
{
    data << teleportLocation.Pos;
    data << int32(teleportLocation.Unused901_1);
    data << int32(teleportLocation.Unused901_2);

    return data;
}

WorldPacket const* WorldPackets::Movement::NewWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Loc;
    _worldPacket << uint32(Reason);
    _worldPacket << MovementOffset;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveTeleport::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Pos;
    _worldPacket << float(Facing);
    _worldPacket << uint8(PreloadWorld);

    _worldPacket.WriteBit(TransportGUID.is_initialized());
    _worldPacket.WriteBit(Vehicle.is_initialized());
    _worldPacket.FlushBits();

    if (Vehicle)
    {
        _worldPacket << uint8(Vehicle->VehicleSeatIndex);
        _worldPacket.WriteBit(Vehicle->VehicleExitVoluntary);
        _worldPacket.WriteBit(Vehicle->VehicleExitTeleport);
        _worldPacket.FlushBits();
    }

    if (TransportGUID)
        _worldPacket << *TransportGUID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementForce const& movementForce)
{
    WorldPackets::Movement::CommonMovement::WriteMovementForceWithDirection(movementForce, data);
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementForce& movementForce)
{
    data >> movementForce.ID;
    data >> movementForce.Origin;
    data >> movementForce.Direction;
    data >> movementForce.TransportID;
    data >> movementForce.Magnitude;
    movementForce.Type = data.ReadBits(2);

    return data;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateTeleport::Write()
{
    _worldPacket << *Status;

    _worldPacket << uint32(MovementForces ? MovementForces->size() : 0);
    _worldPacket.WriteBit(WalkSpeed.is_initialized());
    _worldPacket.WriteBit(RunSpeed.is_initialized());
    _worldPacket.WriteBit(RunBackSpeed.is_initialized());
    _worldPacket.WriteBit(SwimSpeed.is_initialized());
    _worldPacket.WriteBit(SwimBackSpeed.is_initialized());
    _worldPacket.WriteBit(FlightSpeed.is_initialized());
    _worldPacket.WriteBit(FlightBackSpeed.is_initialized());
    _worldPacket.WriteBit(TurnRate.is_initialized());
    _worldPacket.WriteBit(PitchRate.is_initialized());
    _worldPacket.FlushBits();

    if (MovementForces)
        for (MovementForce const& force : *MovementForces)
            _worldPacket << force;

    if (WalkSpeed)
        _worldPacket << *WalkSpeed;

    if (RunSpeed)
        _worldPacket << *RunSpeed;

    if (RunBackSpeed)
        _worldPacket << *RunBackSpeed;

    if (SwimSpeed)
        _worldPacket << *SwimSpeed;

    if (SwimBackSpeed)
        _worldPacket << *SwimBackSpeed;

    if (FlightSpeed)
        _worldPacket << *FlightSpeed;

    if (FlightBackSpeed)
        _worldPacket << *FlightBackSpeed;

    if (TurnRate)
        _worldPacket << *TurnRate;

    if (PitchRate)
        _worldPacket << *PitchRate;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveTeleportAck::Read()
{
    _worldPacket >> MoverGUID;
    _worldPacket >> AckIndex;
    _worldPacket >> MoveTime;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MovementAck& ack)
{
    data >> ack.Status;
    data >> ack.AckIndex;
    return data;
}

void WorldPackets::Movement::MovementAckMessage::Read()
{
    _worldPacket >> Ack;
}

void WorldPackets::Movement::MovementSpeedAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> Speed;
}

void WorldPackets::Movement::SetActiveMover::Read()
{
    _worldPacket >> ActiveMover;
}

WorldPacket const* WorldPackets::Movement::MoveSetActiveMover::Write()
{
    _worldPacket << MoverGUID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MoveKnockBackSpeeds const& speeds)
{
    data << float(speeds.HorzSpeed);
    data << float(speeds.VertSpeed);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Movement::MoveKnockBackSpeeds& speeds)
{
    data >> speeds.HorzSpeed;
    data >> speeds.VertSpeed;

    return data;
}

WorldPacket const* WorldPackets::Movement::MoveKnockBack::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Direction;
    _worldPacket << Speeds;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateKnockBack::Write()
{
    _worldPacket << *Status;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveKnockBackAck::Read()
{
    _worldPacket >> Ack;
    bool hasSpeeds = _worldPacket.ReadBit();
    if (hasSpeeds)
    {
        Speeds = boost::in_place();
        _worldPacket >> *Speeds;
    }
}

WorldPacket const* WorldPackets::Movement::MoveSetCollisionHeight::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << float(Height);
    _worldPacket << float(Scale);
    _worldPacket << uint8(Reason);
    _worldPacket << uint32(MountDisplayID);
    _worldPacket << int32(ScaleDuration);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateCollisionHeight::Write()
{
    _worldPacket << *Status;
    _worldPacket << float(Height);
    _worldPacket << float(Scale);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveApplyMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << *Force;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveApplyMovementForceAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> Force;
}

WorldPacket const* WorldPackets::Movement::MoveRemoveMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << ID;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveRemoveMovementForceAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> ID;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateApplyMovementForce::Write()
{
    _worldPacket << *Status;
    _worldPacket << *Force;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::MoveUpdateRemoveMovementForce::Write()
{
    _worldPacket << *Status;
    _worldPacket << TriggerGUID;

    return &_worldPacket;
}

void WorldPackets::Movement::MoveSetCollisionHeightAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> Height;
    _worldPacket >> MountDisplayID;
    Reason = _worldPacket.read<UpdateCollisionHeightReason, uint8>();
}

void WorldPackets::Movement::MoveTimeSkipped::Read()
{
    _worldPacket >> MoverGUID;
    _worldPacket >> TimeSkipped;
}

void WorldPackets::Movement::SummonResponse::Read()
{
    _worldPacket >> SummonerGUID;
    Accept = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Movement::ControlUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket.WriteBit(On);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Movement::MoveSplineDone::Read()
{
    _worldPacket >> Status;
    _worldPacket >> SplineID;
}

WorldPacket const* WorldPackets::Movement::SummonRequest::Write()
{
    _worldPacket << SummonerGUID;
    _worldPacket << uint32(SummonerVirtualRealmAddress);
    _worldPacket << int32(AreaID);
    _worldPacket << uint8(Reason);
    _worldPacket.WriteBit(SkipStartingArea);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Movement::SuspendToken::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Movement::SuspendTokenResponse::Read()
{
    _worldPacket >> SequenceIndex;
}

WorldPacket const* WorldPackets::Movement::ResumeToken::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MoveSetCompoundState::MoveStateChange const& stateChange)
{
    data << uint16(stateChange.MessageID);
    data << uint32(stateChange.SequenceIndex);
    data.WriteBit(stateChange.Speed.is_initialized());
    data.WriteBit(stateChange.KnockBack.is_initialized());
    data.WriteBit(stateChange.VehicleRecID.is_initialized());
    data.WriteBit(stateChange.CollisionHeight.is_initialized());
    data.WriteBit(stateChange.MovementForce_.is_initialized());
    data.WriteBit(stateChange.MovementForceGUID.is_initialized());
    data.FlushBits();

    if (stateChange.MovementForce_)
        data << *stateChange.MovementForce_;

    if (stateChange.Speed)
        data << float(*stateChange.Speed);

    if (stateChange.KnockBack)
    {
        data << float(stateChange.KnockBack->HorzSpeed);
        data << stateChange.KnockBack->Direction;
        data << float(stateChange.KnockBack->InitVertSpeed);
    }

    if (stateChange.VehicleRecID)
        data << int32(*stateChange.VehicleRecID);

    if (stateChange.CollisionHeight)
    {
        data << float(stateChange.CollisionHeight->Height);
        data << float(stateChange.CollisionHeight->Scale);
        data << uint8(stateChange.CollisionHeight->Reason);
    }

    if (stateChange.MovementForceGUID)
        data << *stateChange.MovementForceGUID;

    return data;
}

WorldPacket const* WorldPackets::Movement::MoveSetCompoundState::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(StateChanges.size());
    for (MoveStateChange const& stateChange : StateChanges)
        _worldPacket << stateChange;

    return &_worldPacket;
}
