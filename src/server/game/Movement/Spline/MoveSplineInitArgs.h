/*
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

#ifndef TRINITYSERVER_MOVESPLINEINIT_ARGS_H
#define TRINITYSERVER_MOVESPLINEINIT_ARGS_H

#include "MoveSplineFlag.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Unit;

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

    struct SpellEffectExtraData
    {
        ObjectGuid Target;
        uint32 SpellVisualId = 0;
        uint32 ProgressCurveId = 0;
        uint32 ParabolicCurveId = 0;
    };

    struct MoveSplineInitArgs
    {
        explicit MoveSplineInitArgs(size_t path_capacity = 16);
        ~MoveSplineInitArgs();

        PointsArray path;
        FacingInfo facing;
        MoveSplineFlag flags;
        int32 path_Idx_offset;
        float velocity;
        float parabolic_amplitude;
        float time_perc;
        uint32 splineId;
        float initialOrientation;
        Optional<SpellEffectExtraData> spellEffectExtra;
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
