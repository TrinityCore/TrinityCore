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
#include "MovementPackets.h"

namespace Movement
{
    void PacketBuilder::WriteMonsterMove(const MoveSpline& move_spline, WorldPackets::Movement::MovementMonsterSpline& movementMonsterSpline)
    {
        movementMonsterSpline.ID = move_spline.m_Id;
        WorldPackets::Movement::MovementSpline& movementSpline = movementMonsterSpline.Move;

        MoveSplineFlag splineflags = move_spline.splineflags;
        splineflags.enter_cycle = move_spline.isCyclic();
        movementSpline.Flags = uint32(splineflags & uint32(~MoveSplineFlag::Mask_No_Monster_Move));

        switch (move_spline.splineflags & MoveSplineFlag::Mask_Final_Facing)
        {
            case MoveSplineFlag::Final_Point:
                movementSpline.Face = MONSTER_MOVE_FACING_SPOT;
                movementSpline.FaceSpot = move_spline.facing.f;
                break;
            case MoveSplineFlag::Final_Target:
                movementSpline.Face = MONSTER_MOVE_FACING_TARGET;
                movementSpline.FaceGUID = move_spline.facing.target;
                break;
            case MoveSplineFlag::Final_Angle:
                movementSpline.Face = MONSTER_MOVE_FACING_ANGLE;
                movementSpline.FaceDirection = move_spline.facing.angle;
                break;
            default:
                movementSpline.Face = MONSTER_MOVE_NORMAL;
                break;
        }

        if (splineflags.animation)
        {
            movementSpline.AnimTier = splineflags.getAnimationId();
            movementSpline.TierTransStartTime = move_spline.effect_start_time;
        }

        movementSpline.MoveTime = move_spline.Duration();

        if (splineflags.parabolic)
        {
            movementSpline.JumpGravity = move_spline.vertical_acceleration;
            movementSpline.SpecialTime = move_spline.effect_start_time;
        }

        Spline<int32> const& spline = move_spline.spline;
        std::vector<Vector3> const& array = spline.getPoints();

        if (splineflags & MoveSplineFlag::UncompressedPath)
        {
            if (!splineflags.cyclic)
            {
                uint32 count = spline.getPointCount() - 3;
                for (uint32 i = 2; i < count; ++i)
                    movementSpline.Points.push_back(array[i]);
            }
            else
            {
                uint32 count = spline.getPointCount() - 3;
                movementSpline.Points.push_back(array[1]);
                for (uint32 i = 1; i < count; ++i)
                    movementSpline.Points.push_back(array[i]);
            }
        }
        else
        {
            uint32 last_idx = spline.getPointCount() - 3;
            Vector3 const* real_path = &spline.getPoint(1);

            movementSpline.Points.push_back(real_path[last_idx]);
            
            if (last_idx > 1)
            {
                Vector3 middle = (real_path[0] + real_path[last_idx]) / 2.f;
                Vector3 offset;
                // first and last points already appended
                for (uint32 i = 1; i < last_idx; ++i)
                {
                    offset = middle - real_path[i];
                    movementSpline.PackedDeltas.push_back(offset);
                }
            }
        }
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

            if (splineFlags.final_angle)
                data.WriteBits(3, 2); // Face
            else if (splineFlags.final_target)
                data.WriteBits(2, 2); // Face
            else if (splineFlags.final_point)
                data.WriteBits(1, 2); // Face
            else
                data.WriteBits(0, 2); // Face

            bool HasJumpGravity = data.WriteBit(moveSpline.splineflags & (MoveSplineFlag::Parabolic | MoveSplineFlag::Animation));    // HasJumpGravity
            bool HasSpecialTime = data.WriteBit((moveSpline.splineflags & MoveSplineFlag::Parabolic) && moveSpline.effect_start_time < moveSpline.Duration());    // HasSpecialTime

            data.WriteBits(uint8(moveSpline.spline.mode()), 2);                     // Mode

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
