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

#include "MovementPacketBuilder.h"
#include "ByteBuffer.h"
#include "MoveSpline.h"
#include "Position.h"
#include "MovementPackets.h"

namespace Movement
{
    void PacketBuilder::WriteMonsterMove(MoveSpline const& move_spline, WorldPackets::Movement::MovementMonsterSpline& movementMonsterSpline)
    {
        movementMonsterSpline.ID = move_spline.m_Id;
        WorldPackets::Movement::MovementSpline& movementSpline = movementMonsterSpline.Move;

        MoveSplineFlag splineflags = move_spline.splineflags;
        movementSpline.Flags = uint32(splineflags & uint32(~MoveSplineFlag::Mask_No_Monster_Move));
 
        movementMonsterSpline.Destination = move_spline.spline.getPoint(move_spline.spline.first());

        switch (splineflags & MoveSplineFlag::Mask_Final_Facing)
        {
            case MoveSplineFlag::Final_Point:
                movementSpline.Face = MONSTER_MOVE_FACING_SPOT;
                movementSpline.FaceSpot = Vector3(move_spline.facing.f.x, move_spline.facing.f.y, move_spline.facing.f.z);
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
            movementSpline.AnimTier = splineflags.animTier;
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

        if (splineflags & MoveSplineFlag::Mask_CatmullRom)
        {
            if (!splineflags.cyclic)
            {
                uint32 count = spline.getPointCount() - 3;
                movementSpline.Points.reserve(count);
                for (uint32 i = 0; i < count; ++i)
                    movementSpline.Points.push_back(array[i + 2]);
            }
            else
            {
                uint32 count = spline.getPointCount() - 4;
                movementSpline.Points.reserve(count);
                for (uint32 i = 0; i < count; ++i)
                    movementSpline.Points.push_back(array[i + 2]);
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

    void PacketBuilder::WriteCreate(MoveSpline const& move_spline, ByteBuffer& data)
    {
        //WriteClientStatus(mov, data);
        //data.append<float>(&mov.m_float_values[SpeedWalk], SpeedMaxCount);
        //if (mov.SplineEnabled())
        {
            MoveSplineFlag const& splineFlags = move_spline.splineflags;

            data << splineFlags.raw();

            if (splineFlags.final_angle)
            {
                data << move_spline.facing.angle;
            }
            else if (splineFlags.final_target)
            {
                data << move_spline.facing.target;
            }
            else if (splineFlags.final_point)
            {
                data << move_spline.facing.f.x << move_spline.facing.f.y << move_spline.facing.f.z;
            }

            data << move_spline.timePassed();
            data << move_spline.Duration();
            data << move_spline.GetId();

            data << float(1.f);                             // splineInfo.duration_mod; added in 3.1
            data << float(1.f);                             // splineInfo.duration_mod_next; added in 3.1

            data << move_spline.vertical_acceleration;      // added in 3.1
            data << move_spline.effect_start_time;          // added in 3.1

            uint32 nodes = move_spline.getPath().size();
            data << nodes;
            data.append<G3D::Vector3>(&move_spline.getPath()[0], nodes);
            data << uint8(move_spline.spline.mode());       // added in 3.1
            data << (move_spline.isCyclic() ? G3D::Vector3::zero() : move_spline.FinalDestination());
        }
    }
}
