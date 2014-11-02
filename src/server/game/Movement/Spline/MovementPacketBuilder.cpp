/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "MovementPacketBuilder.h"
#include "MoveSpline.h"
#include "WorldPacket.h"
#include "Object.h"

namespace Movement
{
    inline void operator << (ByteBuffer& b, const Vector3& v)
    {
        b << v.x << v.y << v.z;
    }

    inline void operator >> (ByteBuffer& b, Vector3& v)
    {
        b >> v.x >> v.y >> v.z;
    }

    enum MonsterMoveType
    {
        MonsterMoveNormal       = 0,
        MonsterMoveStop         = 1,
        MonsterMoveFacingSpot   = 2,
        MonsterMoveFacingTarget = 3,
        MonsterMoveFacingAngle  = 4
    };

    void PacketBuilder::WriteCommonMonsterMovePart(const MoveSpline& move_spline, WorldPacket& data)
    {
        MoveSplineFlag splineflags = move_spline.splineflags;

        data << uint8(0);                                       // sets/unsets MOVEMENTFLAG2_UNK7 (0x40)
        data << move_spline.spline.getPoint(move_spline.spline.first());
        data << move_spline.GetId();

        switch (splineflags & MoveSplineFlag::Mask_Final_Facing)
        {
            case MoveSplineFlag::Final_Target:
                data << uint8(MonsterMoveFacingTarget);
                data << move_spline.facing.target;
                break;
            case MoveSplineFlag::Final_Angle:
                data << uint8(MonsterMoveFacingAngle);
                data << move_spline.facing.angle;
                break;
            case MoveSplineFlag::Final_Point:
                data << uint8(MonsterMoveFacingSpot);
                data << move_spline.facing.f.x << move_spline.facing.f.y << move_spline.facing.f.z;
                break;
            default:
                data << uint8(MonsterMoveNormal);
                break;
        }

        // add fake Enter_Cycle flag - needed for client-side cyclic movement (client will erase first spline vertex after first cycle done)
        splineflags.enter_cycle = move_spline.isCyclic();
        data << uint32(splineflags & uint32(~MoveSplineFlag::Mask_No_Monster_Move));

        if (splineflags.animation)
        {
            data << splineflags.getAnimationId();
            data << move_spline.effect_start_time;
        }

        data << move_spline.Duration();

        if (splineflags.parabolic)
        {
            data << move_spline.vertical_acceleration;
            data << move_spline.effect_start_time;
        }
    }

    void PacketBuilder::WriteStopMovement(Vector3 const& pos, uint32 splineId, ByteBuffer& data)
    {
        data << uint8(0);                                       // sets/unsets MOVEMENTFLAG2_UNK7 (0x40)
        data << pos;
        data << splineId;
        data << uint8(MonsterMoveStop);
    }

    void WriteLinearPath(Spline<int32> const& spline, ByteBuffer& data)
    {
        uint32 last_idx = spline.getPointCount() - 3;
        Vector3 const* real_path = &spline.getPoint(1);

        data << last_idx;
        data << real_path[last_idx];   // destination
        if (last_idx > 1)
        {
            Vector3 middle = (real_path[0] + real_path[last_idx]) / 2.f;
            Vector3 offset;
            // first and last points already appended
            for (uint32 i = 1; i < last_idx; ++i)
            {
                offset = middle - real_path[i];
                data.appendPackXYZ(offset.x, offset.y, offset.z);
            }
        }
    }

    void WriteUncompressedPath(Spline<int32> const& spline, ByteBuffer& data)
    {
        uint32 count = spline.getPointCount() - 3;
        data << count;
        data.append<Vector3>(&spline.getPoint(2), count);
    }

    void WriteUncompressedCyclicPath(Spline<int32> const& spline, ByteBuffer& data)
    {
        uint32 count = spline.getPointCount() - 3;
        data << uint32(count + 1);
        data << spline.getPoint(1); // fake point, client will erase it from the spline after first cycle done
        data.append<Vector3>(&spline.getPoint(1), count);
    }

    void PacketBuilder::WriteMonsterMove(const MoveSpline& move_spline, WorldPacket& data)
    {
        WriteCommonMonsterMovePart(move_spline, data);

        Spline<int32> const& spline = move_spline.spline;
        MoveSplineFlag splineflags = move_spline.splineflags;
        if (splineflags & MoveSplineFlag::UncompressedPath)
        {
            if (!splineflags.cyclic)
                WriteUncompressedPath(spline, data);
            else
                WriteUncompressedCyclicPath(spline, data);
        }
        else
            WriteLinearPath(spline, data);
    }

    void PacketBuilder::WriteCreate(MoveSpline const& moveSpline, ByteBuffer& data)
    {
        data << uint32(moveSpline.GetId());                                         // ID
        if (!moveSpline.isCyclic())                                                 // Destination
        {
            Vector3 dest = moveSpline.FinalDestination();
            data << float(dest.z);
            data << float(dest.x);
            data << float(dest.y);
        }
        else
            data << Vector3::zero();

        if (data.WriteBit(!moveSpline.Finalized()))                                 // MovementSplineMove
        {
            MoveSplineFlag const& splineFlags = moveSpline.splineflags;
            data.FlushBits();

            data.WriteBits(moveSpline.splineflags.raw(), 25);                       // SplineFlags
            data.WriteBits(uint8(moveSpline.spline.mode()), 2);                     // Mode

            bool HasJumpGravity = data.WriteBit(moveSpline.splineflags & (MoveSplineFlag::Parabolic | MoveSplineFlag::Animation));    // HasJumpGravity
            bool HasSpecialTime = data.WriteBit((moveSpline.splineflags & MoveSplineFlag::Parabolic) && moveSpline.effect_start_time < moveSpline.Duration());    // HasSpecialTime

            if (splineFlags.final_angle)
                data.WriteBit(3);
            else if (splineFlags.final_target)
                data.WriteBit(2);
            else if (splineFlags.final_point)
                data.WriteBit(1);
            else
                data.WriteBit(0);

            data.WriteBit(0);                                                       // HasSplineFilterKey

            data << int32(moveSpline.timePassed());                                 // Elapsed
            data << uint32(moveSpline.Duration());                                  // Duration
            data << float(1.0f);                                                    // DurationModifier
            data << float(1.0f);                                                    // NextDurationModifier

            uint32 PointsCount = moveSpline.getPath().size();
            data << uint32(PointsCount);

            if (splineFlags.final_angle)                                            // FaceDirection
                data << moveSpline.facing.angle;
            else if (splineFlags.final_target)                                      // FaceGUID
                data << moveSpline.facing.target;
            else if (splineFlags.final_point)                                       // FaceSpot
                data << moveSpline.facing.f.x << moveSpline.facing.f.y << moveSpline.facing.f.z;

            if (HasJumpGravity)
                data << float(moveSpline.vertical_acceleration);                    // JumpGravity

            if (HasSpecialTime)
                data << uint32(moveSpline.effect_start_time);                       // SpecialTime

            //if (HasSplineFilterKey)
            //{
            //    data << uint32(FilterKeysCount);
            //    for (var i = 0; i < PointsCount; ++i)
            //    {
            //        data << float(In);
            //        data << float(Out);
            //    }

            //    data.WriteBits(FilterFlags, 2);
            //}

            data.append<Vector3>(&moveSpline.getPath()[0], PointsCount);            // Points
        }
    }
}
