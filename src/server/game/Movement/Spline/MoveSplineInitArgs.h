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

#ifndef TRINITYSERVER_MOVESPLINEINIT_ARGS_H
#define TRINITYSERVER_MOVESPLINEINIT_ARGS_H

#include "Duration.h"
#include "MoveSplineFlag.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Unit;

enum class AnimationTier : uint8;

namespace Movement
{
    typedef std::vector<Vector3> PointsArray;

    struct FacingInfo
    {
        struct
        {
            float x, y, z;
        } f;
        ObjectGuid target;
        float angle;

        MonsterMoveType type;

        FacingInfo() : angle(0.0f), type(MONSTER_MOVE_NORMAL) { f.x = f.y = f.z = 0.0f; }
    };

    struct MoveSplineInitArgs
    {
        explicit MoveSplineInitArgs(size_t path_capacity = 16);
        MoveSplineInitArgs(MoveSplineInitArgs&& args);
        ~MoveSplineInitArgs();

        PointsArray path;
        FacingInfo facing;
        MoveSplineFlag flags;
        int32 path_Idx_offset;
        float velocity;
        float parabolic_amplitude;
        float vertical_acceleration;
        float effect_start_time_percent; // fraction of total spline duration
        Milliseconds effect_start_time;  // absolute value
        uint32 splineId;
        float initialOrientation;
        Optional<AnimationTier> animTier;
        bool walk;
        bool HasVelocity;
        bool TransformForTransport;

        /** Returns true to show that the arguments were configured correctly and MoveSpline initialization will succeed. */
        bool Validate(Unit* unit) const;

    private:
        bool _checkPathLengths() const;
    };
}

#endif // TRINITYSERVER_MOVESPLINEINIT_ARGS_H
