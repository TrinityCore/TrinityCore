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

#ifndef TRINITYCORE_AREATRIGGER_TEMPLATE_H
#define TRINITYCORE_AREATRIGGER_TEMPLATE_H

#include "Object.h"
#include "ObjectAccessor.h"

class Unit;
class SpellInfo;

#define MAX_AREATRIGGER_ENTITY_DATA 6

enum AreaTriggerFlags
{
    AREATRIGGER_FLAG_HAS_ABSOLUTE_ORIENTATION   = 0x00001,
    AREATRIGGER_FLAG_HAS_DYNAMIC_SHAPE          = 0x00002,
    AREATRIGGER_FLAG_HAS_ATTACHED               = 0x00004,
    AREATRIGGER_FLAG_HAS_FACE_MOVEMENT_DIR      = 0x00008,
    AREATRIGGER_FLAG_HAS_FOLLOWS_TERRAIN        = 0x00010,
    AREATRIGGER_FLAG_UNK1                       = 0x00020,
    AREATRIGGER_FLAG_HAS_TARGET_ROLL_PITCH_YAW  = 0x00040,
    AREATRIGGER_FLAG_HAS_SCALE_CURVE            = 0x00080,
    AREATRIGGER_FLAG_HAS_MORPH_CURVE            = 0x00100,
    AREATRIGGER_FLAG_HAS_FACING_CURVE           = 0x00200,
    AREATRIGGER_FLAG_HAS_MOVE_CURVE             = 0x00400,
    AREATRIGGER_FLAG_UNK2                       = 0x00800,
    AREATRIGGER_FLAG_UNK3                       = 0x01000,
    AREATRIGGER_FLAG_UNK4                       = 0x02000,
    AREATRIGGER_FLAG_HAS_SPHERE                 = 0x04000,
    AREATRIGGER_FLAG_HAS_BOX                    = 0x08000,
    AREATRIGGER_FLAG_HAS_POLYGON                = 0x10000,
    AREATRIGGER_FLAG_HAS_CYLINDER               = 0x20000,
    AREATRIGGER_FLAG_HAS_SPLINE                 = 0x40000,
    AREATRIGGER_FLAG_UNK5                       = 0x80000
};

struct AreaTriggerPolygonVertice
{
    float VerticeX;
    float VerticeY;
    float VerticeTargetX;
    float VerticeTargetY;
};

class AreaTriggerTemplate
{
public:
    AreaTriggerTemplate()
    {
        Id              = 0;
        Flags           = 0;
        MoveCurveId     = 0;
        ScaleCurveId    = 0;
        MorphCurveId    = 0;
        FacingCurveId   = 0;
        ScriptId        = 0;
        MaxSearchRadius = 0.0f;

        memset(DefaultDatas.Data, 0, sizeof(DefaultDatas.Data));
    }

    bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }

    bool IsSphere()     const { return HasFlag(AREATRIGGER_FLAG_HAS_SPHERE);    }
    bool IsBox()        const { return HasFlag(AREATRIGGER_FLAG_HAS_BOX);       }
    bool IsPolygon()    const { return HasFlag(AREATRIGGER_FLAG_HAS_POLYGON);   }
    bool IsCylinder()   const { return HasFlag(AREATRIGGER_FLAG_HAS_CYLINDER);  }
    bool IsSpline()     const { return HasFlag(AREATRIGGER_FLAG_HAS_SPLINE);    }

    void InitMaxSearchRadius();

    uint32 Id;
    uint32 Flags;
    int32 MoveCurveId;
    int32 ScaleCurveId;
    int32 MorphCurveId;
    int32 FacingCurveId;
    uint32 ScriptId;
    float MaxSearchRadius;
    std::vector<AreaTriggerPolygonVertice> PolygonVertices;

    union
    {
        struct
        {
            float Data[MAX_AREATRIGGER_ENTITY_DATA];
        } DefaultDatas;

        // AREATRIGGER_FLAG_IS_SPHERE
        struct
        {
            float Radius;
            float RadiusTarget;
        } SphereDatas;

        // AREATRIGGER_FLAG_IS_BOX
        struct
        {
            float Extents[3];
            float ExtentsTarget[3];
        } BoxDatas;

        // AREATRIGGER_FLAG_IS_POLYGON
        struct
        {
            float  Height;
            float  HeightTarget;
        } PolygonDatas;

        // AREATRIGGER_FLAG_IS_CYLINDER
        struct
        {
            float Radius;
            float RadiusTarget;
            float Height;
            float HeightTarget;
            float LocationZOffset;
            float LocationZOffsetTarget;
        } CylinderDatas;

        // AREATRIGGER_FLAG_IS_SPLINE
        struct
        {
            // TODO
        } SplineDatas;

        // AREATRIGGER_FLAG_IS_UNK
        struct
        {
            // TODO
        } UnkDatas;
    };
};

#endif
