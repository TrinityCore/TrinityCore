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
#include "PacketOperators.h"
#include "UnitDefines.h"
#include "Util.h"

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

ByteBuffer& operator<<(ByteBuffer& data, MovementInfo const& movementInfo)
{
    bool hasTransportData = !movementInfo.transport.guid.IsEmpty();
    bool hasFallDirection = movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
    bool hasFallData = hasFallDirection || movementInfo.jump.fallTime != 0;
    bool hasSpline = false; // todo 6.x send this infos
    bool hasInertia = movementInfo.inertia.has_value();
    bool hasAdvFlying = movementInfo.advFlying.has_value();
    bool hasDriveStatus = movementInfo.driveStatus.has_value();
    bool hasStandingOnGameObjectGUID = movementInfo.standingOnGameObjectGUID.has_value();

    data << movementInfo.guid;
    data << uint32(movementInfo.flags);
    data << uint32(movementInfo.flags2);
    data << uint32(movementInfo.flags3);
    data << uint32(movementInfo.time);
    data << movementInfo.pos.PositionXYZOStream();
    data << float(movementInfo.pitch);
    data << float(movementInfo.stepUpStartElevation);

    uint32 removeMovementForcesCount = 0;
    data << removeMovementForcesCount;

    uint32 moveIndex = 0;
    data << moveIndex;

    /*for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        data << ObjectGuid;
    }*/

    data.WriteBit(hasStandingOnGameObjectGUID);
    data.WriteBit(hasTransportData);
    data.WriteBit(hasFallData);
    data.WriteBit(hasSpline);

    data.WriteBit(false); // HeightChangeFailed
    data.WriteBit(false); // RemoteTimeValid
    data.WriteBit(hasInertia);
    data.WriteBit(hasAdvFlying);
    data.WriteBit(hasDriveStatus);

    data.FlushBits();

    if (hasTransportData)
        data << movementInfo.transport;

    if (hasStandingOnGameObjectGUID)
        data << *movementInfo.standingOnGameObjectGUID;

    if (hasInertia)
    {
        data << uint32(movementInfo.inertia->id);
        data << movementInfo.inertia->force.PositionXYZStream();
        data << uint32(movementInfo.inertia->lifetime);
    }

    if (hasAdvFlying)
    {
        data << float(movementInfo.advFlying->forwardVelocity);
        data << float(movementInfo.advFlying->upVelocity);
    }

    if (hasFallData)
    {
        data << uint32(movementInfo.jump.fallTime);
        data << float(movementInfo.jump.zspeed);

        data.WriteBit(hasFallDirection);
        data.FlushBits();
        if (hasFallDirection)
        {
            data << float(movementInfo.jump.sinAngle);
            data << float(movementInfo.jump.cosAngle);
            data << float(movementInfo.jump.xyspeed);
        }
    }

    if (hasDriveStatus)
    {
        data << float(movementInfo.driveStatus->speed);
        data << float(movementInfo.driveStatus->movementAngle);
        data.WriteBit(movementInfo.driveStatus->accelerating);
        data.WriteBit(movementInfo.driveStatus->drifting);
        data.FlushBits();
    }

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementInfo& movementInfo)
{
    //bool hasSpline = false;

    data >> movementInfo.guid;
    data >> movementInfo.flags;
    data >> movementInfo.flags2;
    data >> movementInfo.flags3;
    data >> movementInfo.time;
    data >> movementInfo.pos.PositionXYZOStream();
    data >> movementInfo.pitch;
    data >> movementInfo.stepUpStartElevation;

    uint32 removeMovementForcesCount;
    data >> removeMovementForcesCount;

    uint32 moveIndex;
    data >> moveIndex;

    for (uint32 i = 0; i < removeMovementForcesCount; ++i)
    {
        ObjectGuid guid;
        data >> guid;
    }

    bool hasStandingOnGameObjectGUID = data.ReadBit();
    bool hasTransport = data.ReadBit();
    bool hasFall = data.ReadBit();
    /*hasSpline = */data.ReadBit(); // todo 6.x read this infos

    data.ReadBit(); // HeightChangeFailed
    data.ReadBit(); // RemoteTimeValid
    bool hasInertia = data.ReadBit();
    bool hasAdvFlying = data.ReadBit();
    bool hasDriveStatus = data.ReadBit();

    if (hasTransport)
        data >> movementInfo.transport;

    if (hasStandingOnGameObjectGUID)
        data >> movementInfo.standingOnGameObjectGUID.emplace();

    if (hasInertia)
    {
        movementInfo.inertia.emplace();

        data >> movementInfo.inertia->id;
        data >> movementInfo.inertia->force.PositionXYZStream();
        data >> movementInfo.inertia->lifetime;
    }

    if (hasAdvFlying)
    {
        movementInfo.advFlying.emplace();

        data >> movementInfo.advFlying->forwardVelocity;
        data >> movementInfo.advFlying->upVelocity;
    }

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

    if (hasDriveStatus)
    {
        data.ResetBitPos();

        movementInfo.driveStatus.emplace();

        data >> movementInfo.driveStatus->speed;
        data >> movementInfo.driveStatus->movementAngle;
        movementInfo.driveStatus->accelerating = data.ReadBit();
        movementInfo.driveStatus->drifting = data.ReadBit();
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementForce const& movementForce)
{
    WorldPackets::Movement::CommonMovement::WriteMovementForceWithDirection(movementForce, data);
    return data;
}

namespace WorldPackets::Movement
{
void ClientPlayerMovement::Read()
{
    _worldPacket >> Status;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineFilterKey const& monsterSplineFilterKey)
{
    data << int16(monsterSplineFilterKey.Idx);
    data << uint16(monsterSplineFilterKey.Speed);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineFilter const& monsterSplineFilter)
{
    data << Size<uint32>(monsterSplineFilter.FilterKeys);
    data << float(monsterSplineFilter.BaseSpeed);
    data << int16(monsterSplineFilter.StartOffset);
    data << float(monsterSplineFilter.DistToPrevFilterKey);
    data << int16(monsterSplineFilter.AddedToStart);
    for (MonsterSplineFilterKey const& filterKey : monsterSplineFilter.FilterKeys)
        data << filterKey;

    data << Bits<2>(monsterSplineFilter.FilterFlags);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineSpellEffectExtraData const& spellEffectExtraData)
{
    data << spellEffectExtraData.TargetGUID;
    data << uint32(spellEffectExtraData.SpellVisualID);
    data << uint32(spellEffectExtraData.ProgressCurveID);
    data << uint32(spellEffectExtraData.ParabolicCurveID);
    data << float(spellEffectExtraData.JumpGravity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineJumpExtraData const& jumpExtraData)
{
    data << float(jumpExtraData.JumpGravity);
    data << uint32(jumpExtraData.StartTime);
    data << uint32(jumpExtraData.Duration);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineTurnData const& turnData)
{
    data << float(turnData.StartFacing);
    data << float(turnData.TotalTurnRads);
    data << float(turnData.RadsPerSec);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineAnimTierTransition const& animTierTransition)
{
    data << int32(animTierTransition.TierTransitionID);
    data << uint8(animTierTransition.AnimTier);
    data << uint32(animTierTransition.StartTime);
    data << uint32(animTierTransition.EndTime);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MonsterSplineUnknown901 const& unk)
{
    for (MonsterSplineUnknown901::Inner const& unkInner : unk.Data)
    {
        data << int32(unkInner.Unknown_1);
        data << unkInner.Visual;
        data << uint32(unkInner.Unknown_4);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementSpline const& movementSpline)
{
    data << uint32(movementSpline.Flags);
    data << int32(movementSpline.Elapsed);
    data << uint32(movementSpline.MoveTime);
    data << uint32(movementSpline.FadeObjectTime);
    data << uint8(movementSpline.Mode);
    data << movementSpline.TransportGUID;
    data << int8(movementSpline.VehicleSeat);
    data << Bits<2>(movementSpline.Face);
    data << BitsSize<16>(movementSpline.Points);
    data << Bits<1>(movementSpline.VehicleExitVoluntary);
    data << Bits<1>(movementSpline.TaxiSmoothing);
    data << BitsSize<16>(movementSpline.PackedDeltas);
    data << OptionalInit(movementSpline.SplineFilter);
    data << OptionalInit(movementSpline.SpellEffectExtraData);
    data << OptionalInit(movementSpline.JumpExtraData);
    data << OptionalInit(movementSpline.TurnData);
    data << OptionalInit(movementSpline.AnimTierTransition);
    data << OptionalInit(movementSpline.Unknown901);
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

    if (movementSpline.TurnData)
        data << *movementSpline.TurnData;

    if (movementSpline.AnimTierTransition)
        data << *movementSpline.AnimTierTransition;

    if (movementSpline.Unknown901)
        data << *movementSpline.Unknown901;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MovementMonsterSpline const& movementMonsterSpline)
{
    data << movementMonsterSpline.ID;
    data << Bits<1>(movementMonsterSpline.CrzTeleport);
    data << Bits<1>(movementMonsterSpline.StopUseFaceDirection);
    data << Bits<3>(movementMonsterSpline.StopSplineStyle);

    data << movementMonsterSpline.Move;

    return data;
}

void CommonMovement::WriteCreateObjectSplineDataBlock(::Movement::MoveSpline const& moveSpline, ByteBuffer& data)
{
    data << uint32(moveSpline.GetId());                                         // ID

    G3D::Vector3 dest;
    if (!moveSpline.isCyclic())                                                 // Destination
        dest = moveSpline.FinalDestination();
    else
    {
        ::Movement::MoveSpline::MySpline const& spline = moveSpline._Spline();
        if (spline.getPointCount() <= 1)
            dest = G3D::Vector3::zero();
        else
            dest = spline.getPoint(spline.last() - 1);
    }

    data << dest.x << dest.y << dest.z;

    bool hasSplineMove = !moveSpline.Finalized() && !moveSpline.splineIsFacingOnly;
    data << Bits<1>(hasSplineMove);
    data.FlushBits();

    if (hasSplineMove)                                                          // MovementSplineMove
    {
        data << uint32(moveSpline.splineflags.Raw.AsUnderlyingType());          // SplineFlags
        data << int32(moveSpline.timePassed());                                 // Elapsed
        data << uint32(moveSpline.Duration());                                  // Duration
        data << float(1.0f);                                                    // DurationModifier
        data << float(1.0f);                                                    // NextDurationModifier
        data << Bits<2>(moveSpline.facing.type);                                // Face
        bool hasFadeObjectTime = moveSpline.splineflags.FadeObject && moveSpline.effect_start_time < moveSpline.Duration();
        data << Bits<1>(hasFadeObjectTime);
        data << BitsSize<16>(moveSpline.getPath());
        data << Bits<1>(false);                                                 // HasSplineFilter
        data << OptionalInit(moveSpline.spell_effect_extra);                    // HasSpellEffectExtraData
        bool hasJumpExtraData = moveSpline.splineflags.Parabolic && (!moveSpline.spell_effect_extra || moveSpline.effect_start_time);
        data << Bits<1>(hasJumpExtraData);
        data << OptionalInit(moveSpline.turn);                                  // HasTurnData
        data << OptionalInit(moveSpline.anim_tier);                             // HasAnimTierTransition
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

        data.append(reinterpret_cast<float const*>(moveSpline.getPath().data()), moveSpline.getPath().size() * 3);

        if (moveSpline.spell_effect_extra)
        {
            data << moveSpline.spell_effect_extra->Target;
            data << uint32(moveSpline.spell_effect_extra->SpellVisualId);
            data << uint32(moveSpline.spell_effect_extra->ProgressCurveId);
            data << uint32(moveSpline.spell_effect_extra->ParabolicCurveId);
            data << float(moveSpline.vertical_acceleration);
        }

        if (hasJumpExtraData)
        {
            data << float(moveSpline.vertical_acceleration);
            data << uint32(moveSpline.effect_start_time);
            data << uint32(0);                                                  // Duration (override)
        }

        if (moveSpline.turn)
        {
            data << float(moveSpline.turn->StartFacing);
            data << float(moveSpline.turn->TotalTurnRads);
            data << float(moveSpline.turn->RadsPerSec);
        }

        if (moveSpline.anim_tier)
        {
            data << int32(moveSpline.anim_tier->TierTransitionId);
            data << uint8(moveSpline.anim_tier->AnimTier);
            data << uint32(moveSpline.effect_start_time);
            data << uint32(0);
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

void CommonMovement::WriteMovementForceWithDirection(MovementForce const& movementForce, ByteBuffer& data, Position const* objectPosition /*= nullptr*/)
{
    data << movementForce.ID;
    data << movementForce.Origin;
    if (movementForce.Type == MovementForceType::Gravity && objectPosition)
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
    data << int32(movementForce.MovementForceID);
    data << int32(movementForce.Unknown1110_1);
    data << int32(movementForce.Unused1110);
    data << uint32(movementForce.Flags);
    data << Bits<2>(movementForce.Type);
    data.FlushBits();
}

void MonsterMove::InitializeSplineData(::Movement::MoveSpline const& moveSpline)
{
    SplineData.ID = moveSpline.m_Id;
    MovementSpline& movementSpline = SplineData.Move;

    ::Movement::MoveSplineFlag splineFlags = moveSpline.splineflags;
    movementSpline.Flags = uint32(splineFlags & ~::Movement::MoveSplineFlagEnum::Mask_No_Monster_Move);
    movementSpline.Face = moveSpline.facing.type;
    movementSpline.FaceDirection = moveSpline.facing.angle;
    movementSpline.FaceGUID = moveSpline.facing.target;
    movementSpline.FaceSpot = Position(moveSpline.facing.f.x, moveSpline.facing.f.y, moveSpline.facing.f.z);

    if (moveSpline.anim_tier)
    {
        movementSpline.AnimTierTransition.emplace();
        movementSpline.AnimTierTransition->TierTransitionID = moveSpline.anim_tier->TierTransitionId;
        movementSpline.AnimTierTransition->StartTime = moveSpline.effect_start_time;
        movementSpline.AnimTierTransition->AnimTier = AsUnderlyingType(moveSpline.anim_tier->AnimTier);
    }

    movementSpline.MoveTime = moveSpline.Duration();

    if (splineFlags.Parabolic && (!moveSpline.spell_effect_extra || moveSpline.effect_start_time))
    {
        movementSpline.JumpExtraData.emplace();
        movementSpline.JumpExtraData->JumpGravity = moveSpline.vertical_acceleration;
        movementSpline.JumpExtraData->StartTime = moveSpline.effect_start_time;
    }

    if (moveSpline.turn)
    {
        MonsterSplineTurnData& turn = movementSpline.TurnData.emplace();
        turn.StartFacing = moveSpline.turn->StartFacing;
        turn.TotalTurnRads = moveSpline.turn->TotalTurnRads;
        turn.RadsPerSec = moveSpline.turn->RadsPerSec;
    }

    if (splineFlags.FadeObject)
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

    if (splineFlags.UncompressedPath)
    {
        uint32 count = spline.getPointCount() - (splineFlags.Cyclic ? 4 : 3);
        for (uint32 i = 0; i < count; ++i)
            movementSpline.Points.emplace_back(array[i + 2].x, array[i + 2].y, array[i + 2].z);
    }
    else
    {
        uint32 lastIdx = spline.getPointCount() - (splineFlags.Cyclic ? 4 : 3);
        G3D::Vector3 const* realPath = &array[1];

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

WorldPacket const* MonsterMove::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Pos;
    _worldPacket << SplineData;

    return &_worldPacket;
}

WorldPacket const* FlightSplineSync::Write()
{
    _worldPacket << Guid;
    _worldPacket << float(SplineDist);

    return &_worldPacket;
}

WorldPacket const* MoveSplineSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Speed;

    return &_worldPacket;
}

WorldPacket const* MoveSetSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << Speed;

    return &_worldPacket;
}

WorldPacket const* MoveUpdateSpeed::Write()
{
    _worldPacket << *Status;
    _worldPacket << Speed;

    return &_worldPacket;
}

WorldPacket const* SetAdvFlyingSpeed::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << float(Speed);

    return &_worldPacket;
}

WorldPacket const* SetAdvFlyingSpeedRange::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << float(SpeedMin);
    _worldPacket << float(SpeedMax);

    return &_worldPacket;
}

WorldPacket const* MoveSplineSetFlag::Write()
{
    _worldPacket << MoverGUID;

    return &_worldPacket;
}

WorldPacket const* MoveSetFlag::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;

    return &_worldPacket;
}

WorldPacket const* MoveUpdate::Write()
{
    _worldPacket << *Status;

    return &_worldPacket;
}

WorldPacket const* TransferPending::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << OldMapPosition;
    _worldPacket << OptionalInit(Ship);
    _worldPacket << OptionalInit(TransferSpellID);
    _worldPacket << OptionalInit(TaxiPathID);
    _worldPacket.FlushBits();

    if (Ship)
    {
        _worldPacket << uint32(Ship->ID);
        _worldPacket << int32(Ship->OriginMapID);
    }

    if (TransferSpellID)
        _worldPacket << int32(*TransferSpellID);

    if (TaxiPathID)
        _worldPacket << int32(*TaxiPathID);

    return &_worldPacket;
}

WorldPacket const* TransferAborted::Write()
{
    _worldPacket << uint32(MapID);
    _worldPacket << uint8(Arg);
    _worldPacket << int32(MapDifficultyXConditionID);
    _worldPacket << Bits<6>(TransfertAbort);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, TeleportLocation const& teleportLocation)
{
    data << teleportLocation.Pos;
    data << int32(teleportLocation.FloorDifficulty);
    data << int32(teleportLocation.FloorIndex);

    return data;
}

WorldPacket const* NewWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Loc;
    _worldPacket << uint32(Reason);
    _worldPacket << MovementOffset;
    _worldPacket << int32(Counter);

    return &_worldPacket;
}

WorldPacket const* MoveTeleport::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Pos;
    _worldPacket << float(Facing);
    _worldPacket << uint8(PreloadWorld);

    _worldPacket << OptionalInit(TransportGUID);
    _worldPacket << OptionalInit(Vehicle);
    _worldPacket.FlushBits();

    if (Vehicle)
    {
        _worldPacket << uint8(Vehicle->VehicleSeatIndex);
        _worldPacket << Bits<1>(Vehicle->VehicleExitVoluntary);
        _worldPacket << Bits<1>(Vehicle->VehicleExitTeleport);
        _worldPacket.FlushBits();
    }

    if (TransportGUID)
        _worldPacket << *TransportGUID;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementForce& movementForce)
{
    data >> movementForce.ID;
    data >> movementForce.Origin;
    data >> movementForce.Direction;
    data >> movementForce.TransportID;
    data >> movementForce.Magnitude;
    data >> movementForce.MovementForceID;
    data >> movementForce.Unknown1110_1;
    data >> movementForce.Unused1110;
    data >> movementForce.Flags;
    data >> Bits<2>(movementForce.Type);

    return data;
}

WorldPacket const* MoveUpdateTeleport::Write()
{
    _worldPacket << *Status;

    _worldPacket << uint32(MovementForces ? MovementForces->size() : 0);
    _worldPacket << OptionalInit(WalkSpeed);
    _worldPacket << OptionalInit(RunSpeed);
    _worldPacket << OptionalInit(RunBackSpeed);
    _worldPacket << OptionalInit(SwimSpeed);
    _worldPacket << OptionalInit(SwimBackSpeed);
    _worldPacket << OptionalInit(FlightSpeed);
    _worldPacket << OptionalInit(FlightBackSpeed);
    _worldPacket << OptionalInit(TurnRate);
    _worldPacket << OptionalInit(PitchRate);
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

void MoveTeleportAck::Read()
{
    _worldPacket >> MoverGUID;
    _worldPacket >> AckIndex;
    _worldPacket >> MoveTime;
}

ByteBuffer& operator>>(ByteBuffer& data, MovementAck& ack)
{
    data >> ack.Status;
    data >> ack.AckIndex;

    return data;
}

void MovementAckMessage::Read()
{
    _worldPacket >> Ack;
}

void MovementSpeedAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> Speed;
}

void MovementSpeedRangeAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> SpeedMin;
    _worldPacket >> SpeedMax;
}

void SetActiveMover::Read()
{
    _worldPacket >> ActiveMover;
}

WorldPacket const* MoveSetActiveMover::Write()
{
    _worldPacket << MoverGUID;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, MoveKnockBackSpeeds const& speeds)
{
    data << float(speeds.HorzSpeed);
    data << float(speeds.VertSpeed);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MoveKnockBackSpeeds& speeds)
{
    data >> speeds.HorzSpeed;
    data >> speeds.VertSpeed;

    return data;
}

WorldPacket const* MoveKnockBack::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Direction;
    _worldPacket << Speeds;

    return &_worldPacket;
}

WorldPacket const* MoveUpdateKnockBack::Write()
{
    _worldPacket << *Status;

    return &_worldPacket;
}

void MoveKnockBackAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> OptionalInit(Speeds);
    if (Speeds)
        _worldPacket >> *Speeds;
}

WorldPacket const* MoveSetCollisionHeight::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << float(Height);
    _worldPacket << float(Scale);
    _worldPacket << uint8(Reason);
    _worldPacket << uint32(MountDisplayID);
    _worldPacket << int32(ScaleDuration);

    return &_worldPacket;
}

WorldPacket const* MoveUpdateCollisionHeight::Write()
{
    _worldPacket << *Status;
    _worldPacket << float(Height);
    _worldPacket << float(Scale);

    return &_worldPacket;
}

WorldPacket const* MoveApplyMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << *Force;

    return &_worldPacket;
}

void MoveApplyMovementForceAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> Force;
}

WorldPacket const* MoveRemoveMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << ID;

    return &_worldPacket;
}

void MoveRemoveMovementForceAck::Read()
{
    _worldPacket >> Ack;
    _worldPacket >> ID;
}

WorldPacket const* MoveUpdateApplyMovementForce::Write()
{
    _worldPacket << *Status;
    _worldPacket << *Force;

    return &_worldPacket;
}

WorldPacket const* MoveUpdateRemoveMovementForce::Write()
{
    _worldPacket << *Status;
    _worldPacket << TriggerGUID;

    return &_worldPacket;
}

void MoveSetCollisionHeightAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> Height;
    _worldPacket >> MountDisplayID;
    _worldPacket >> As<uint8>(Reason);
}

void MoveTimeSkipped::Read()
{
    _worldPacket >> MoverGUID;
    _worldPacket >> TimeSkipped;
}

WorldPacket const* MoveSkipTime::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << TimeSkipped;

    return &_worldPacket;
}

void SummonResponse::Read()
{
    _worldPacket >> SummonerGUID;
    _worldPacket >> Bits<1>(Accept);
}

WorldPacket const* ControlUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << Bits<1>(On);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void MoveSplineDone::Read()
{
    _worldPacket >> Status;
    _worldPacket >> SplineID;
}

WorldPacket const* SummonRequest::Write()
{
    _worldPacket << SummonerGUID;
    _worldPacket << uint32(SummonerVirtualRealmAddress);
    _worldPacket << int32(AreaID);
    _worldPacket << uint8(Reason);
    _worldPacket << Bits<1>(SkipStartingArea);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* SuspendToken::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Bits<2>(Reason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void SuspendTokenResponse::Read()
{
    _worldPacket >> SequenceIndex;
}

WorldPacket const* ResumeToken::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << Bits<2>(Reason);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, CollisionHeightInfo const& collisionHeightInfo)
{
    data << float(collisionHeightInfo.Height);
    data << float(collisionHeightInfo.Scale);
    data << uint8(collisionHeightInfo.Reason);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, StateChangeRangeInfo const& stateChangeRangeInfo)
{
    data << float(stateChangeRangeInfo.Min);
    data << float(stateChangeRangeInfo.Max);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, KnockBackInfo const& knockBackInfo)
{
    data << float(knockBackInfo.HorzSpeed);
    data << knockBackInfo.Direction;
    data << float(knockBackInfo.InitVertSpeed);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MoveStateChange const& stateChange)
{
    data << uint32(stateChange.MessageID);
    data << uint32(stateChange.SequenceIndex);
    data << OptionalInit(stateChange.Speed);
    data << OptionalInit(stateChange.Range);
    data << OptionalInit(stateChange.KnockBack);
    data << OptionalInit(stateChange.VehicleRecID);
    data << OptionalInit(stateChange.CollisionHeight);
    data << OptionalInit(stateChange.MovementForce_);
    data << OptionalInit(stateChange.MovementForceGUID);
    data << OptionalInit(stateChange.MovementInertiaID);
    data << OptionalInit(stateChange.MovementInertiaLifetimeMs);
    data << OptionalInit(stateChange.DriveCapabilityRecID);
    data.FlushBits();

    if (stateChange.MovementForce_)
        data << *stateChange.MovementForce_;

    if (stateChange.Speed)
        data << float(*stateChange.Speed);

    if (stateChange.Range)
        data << *stateChange.Range;

    if (stateChange.KnockBack)
        data << *stateChange.KnockBack;

    if (stateChange.VehicleRecID)
        data << int32(*stateChange.VehicleRecID);

    if (stateChange.CollisionHeight)
        data << *stateChange.CollisionHeight;

    if (stateChange.MovementForceGUID)
        data << *stateChange.MovementForceGUID;

    if (stateChange.MovementInertiaID)
        data << int32(*stateChange.MovementInertiaID);

    if (stateChange.MovementInertiaLifetimeMs)
        data << uint32(*stateChange.MovementInertiaLifetimeMs);

    if (stateChange.DriveCapabilityRecID)
        data << int32(*stateChange.DriveCapabilityRecID);

    return data;
}

WorldPacket const* MoveSetCompoundState::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << Size<uint32>(StateChanges);
    for (MoveStateChange const& stateChange : StateChanges)
        _worldPacket << stateChange;

    return &_worldPacket;
}

void MoveInitActiveMoverComplete::Read()
{
    _worldPacket >> Ticks;
}
}
