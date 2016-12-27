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
#include "Spline.h"
#include <G3D/Vector3.h>
#include "MoveSplineInitArgs.h"

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
    AREATRIGGER_FLAG_UNK2                       = 0x00080,
    AREATRIGGER_FLAG_UNK3                       = 0x00100,
    AREATRIGGER_FLAG_UNK4                       = 0x00200,
    AREATRIGGER_FLAG_UNK5                       = 0x00400
};

enum AreaTriggerTypes
{
    AREATRIGGER_TYPE_SPHERE     = 0,
    AREATRIGGER_TYPE_BOX        = 1,
    AREATRIGGER_TYPE_UNK        = 2,
    AREATRIGGER_TYPE_POLYGON    = 3,
    AREATRIGGER_TYPE_CYLINDER   = 4,
    AREATRIGGER_TYPE_MAX        = 5
};

struct AreaTriggerPolygonVertice
{
    float VerticeX;
    float VerticeY;
    float VerticeTargetX;
    float VerticeTargetY;
};

struct AreaTriggerAuras
{
    uint32 AuraId;
    AreaTriggerAuraTypes TargetType;
    AreaTriggerAuraCastTypes CastType;
};

class AreaTriggerTemplate
{
public:
    AreaTriggerTemplate()
    {
        Id                  = 0;
        Flags               = 0;
        ScriptId            = 0;
        MaxSearchRadius     = 0.0f;

        memset(DefaultDatas.Data, 0, sizeof(DefaultDatas.Data));
    }

    bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }

    bool IsSphere()     const { return Type == AREATRIGGER_TYPE_SPHERE;     }
    bool IsBox()        const { return Type == AREATRIGGER_TYPE_BOX;        }
    bool IsPolygon()    const { return Type == AREATRIGGER_TYPE_POLYGON;    }
    bool IsCylinder()   const { return Type == AREATRIGGER_TYPE_CYLINDER;   }

    void InitMaxSearchRadius();

    uint32 Id;
    AreaTriggerTypes Type;
    uint32 Flags;
    uint32 ScriptId;
    float MaxSearchRadius;
    std::vector<AreaTriggerPolygonVertice> PolygonVertices;
    std::vector<AreaTriggerAuras> Auras;

    union
    {
        struct
        {
            float Data[MAX_AREATRIGGER_ENTITY_DATA];
        } DefaultDatas;

        // AREATRIGGER_TYPE_SPHERE
        struct
        {
            float Radius;
            float RadiusTarget;
        } SphereDatas;

        // AREATRIGGER_TYPE_BOX
        struct
        {
            float Extents[3];
            float ExtentsTarget[3];
        } BoxDatas;

        // AREATRIGGER_TYPE_POLYGON
        struct
        {
            float  Height;
            float  HeightTarget;
        } PolygonDatas;

        // AREATRIGGER_TYPE_CYLINDER
        struct
        {
            float Radius;
            float RadiusTarget;
            float Height;
            float HeightTarget;
            float LocationZOffset;
            float LocationZOffsetTarget;
        } CylinderDatas;
    };
};

class AreaTriggerMiscTemplate
{
public:
    AreaTriggerMiscTemplate()
    {
        MiscId              = 0;
        AreaTriggerEntry    = 0;

        MoveCurveId         = 0;
        ScaleCurveId        = 0;
        MorphCurveId        = 0;
        FacingCurveId       = 0;

        TimeToTarget        = 0;
        TimeToTargetScale   = 0;

        Template            = nullptr;
    }

    bool HasSplines()   const { return SplinePoints.size() >= 2; }

    uint32 MiscId;
    uint32 AreaTriggerEntry;

    uint32 MoveCurveId;
    uint32 ScaleCurveId;
    uint32 MorphCurveId;
    uint32 FacingCurveId;

    uint32 TimeToTarget;
    uint32 TimeToTargetScale;

    AreaTriggerTemplate const* Template;
    Movement::PointsArray SplinePoints;
};

#endif
