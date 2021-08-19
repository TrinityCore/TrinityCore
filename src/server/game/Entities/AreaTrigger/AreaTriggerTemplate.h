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

#ifndef TRINITYCORE_AREATRIGGER_TEMPLATE_H
#define TRINITYCORE_AREATRIGGER_TEMPLATE_H

#include "Define.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include <vector>

#define MAX_AREATRIGGER_ENTITY_DATA 6
#define MAX_AREATRIGGER_SCALE 7

enum AreaTriggerFlags
{
    AREATRIGGER_FLAG_HAS_ABSOLUTE_ORIENTATION   = 0x00001, // NYI
    AREATRIGGER_FLAG_HAS_DYNAMIC_SHAPE          = 0x00002, // Implemented for Spheres
    AREATRIGGER_FLAG_HAS_ATTACHED               = 0x00004,
    AREATRIGGER_FLAG_HAS_FACE_MOVEMENT_DIR      = 0x00008,
    AREATRIGGER_FLAG_HAS_FOLLOWS_TERRAIN        = 0x00010, // NYI
    AREATRIGGER_FLAG_UNK1                       = 0x00020,
    AREATRIGGER_FLAG_HAS_TARGET_ROLL_PITCH_YAW  = 0x00040, // NYI
    AREATRIGGER_FLAG_HAS_ANIM_ID                = 0x00080,
    AREATRIGGER_FLAG_UNK3                       = 0x00100,
    AREATRIGGER_FLAG_HAS_ANIM_KIT_ID            = 0x00200,
    AREATRIGGER_FLAG_HAS_CIRCULAR_MOVEMENT      = 0x00400,
    AREATRIGGER_FLAG_UNK5                       = 0x00800,
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

enum AreaTriggerActionTypes
{
    AREATRIGGER_ACTION_CAST        = 0,
    AREATRIGGER_ACTION_ADDAURA     = 1,
    AREATRIGGER_ACTION_TELEPORT    = 2,
    AREATRIGGER_ACTION_MAX         = 3
};

enum AreaTriggerActionUserTypes
{
    AREATRIGGER_ACTION_USER_ANY    = 0,
    AREATRIGGER_ACTION_USER_FRIEND = 1,
    AREATRIGGER_ACTION_USER_ENEMY  = 2,
    AREATRIGGER_ACTION_USER_RAID   = 3,
    AREATRIGGER_ACTION_USER_PARTY  = 4,
    AREATRIGGER_ACTION_USER_CASTER = 5,
    AREATRIGGER_ACTION_USER_MAX    = 6
};

struct AreaTriggerId
{
    uint32 Id = 0;
    bool IsServerSide = false;
};

struct AreaTriggerAction
{
    uint32 Param;
    AreaTriggerActionTypes ActionType;
    AreaTriggerActionUserTypes TargetType;
};

// Scale array definition
// 0 - time offset from creation for starting of scaling
// 1+2,3+4 are values for curve points Vector2[2]
// 5 is packed curve information (has_no_data & 1) | ((interpolation_mode & 0x7) << 1) | ((first_point_offset & 0x7FFFFF) << 4) | ((point_count & 0x1F) << 27)
// 6 bool is_override, only valid for AREATRIGGER_OVERRIDE_SCALE_CURVE, if true then use data from AREATRIGGER_OVERRIDE_SCALE_CURVE instead of ScaleCurveId from CreateObject

struct AreaTriggerScaleInfo
{
    AreaTriggerScaleInfo();

    union
    {
        struct
        {
            uint32 StartTimeOffset;
            float Points[4];
            struct
            {
                uint32 NoData : 1;
                uint32 InterpolationMode : 3;
                uint32 FirstPointOffset : 23;
                uint32 PointCount : 5;
            } CurveParameters;
            uint32 OverrideActive;
        } Structured;

        uint32 Raw[MAX_AREATRIGGER_SCALE];
    } Data;
};

struct AreaTriggerOrbitInfo
{
    Optional<ObjectGuid> PathTarget;
    Optional<TaggedPosition<Position::XYZ>> Center;
    bool CounterClockwise = false;
    bool CanLoop = false;
    uint32 TimeToTarget = 0;
    int32 ElapsedTimeForMovement = 0;
    uint32 StartDelay = 0;
    float Radius = 0.0f;
    float BlendFromRadius = 0.0f;
    float InitialAngle = 0.0f;
    float ZOffset = 0.0f;
};

class AreaTriggerTemplate
{
public:
    AreaTriggerTemplate();
    ~AreaTriggerTemplate();

    bool HasFlag(uint32 flag) const { return (Flags & flag) != 0; }

    bool IsSphere()     const { return Type == AREATRIGGER_TYPE_SPHERE;     }
    bool IsBox()        const { return Type == AREATRIGGER_TYPE_BOX;        }
    bool IsPolygon()    const { return Type == AREATRIGGER_TYPE_POLYGON;    }
    bool IsCylinder()   const { return Type == AREATRIGGER_TYPE_CYLINDER;   }

    void InitMaxSearchRadius();

    AreaTriggerId Id;
    AreaTriggerTypes Type;
    uint32 Flags;
    uint32 ScriptId;
    float MaxSearchRadius;
    std::vector<TaggedPosition<Position::XY>> PolygonVertices;
    std::vector<TaggedPosition<Position::XY>> PolygonVerticesTarget;
    std::vector<AreaTriggerAction> Actions;

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
            float Height;
            float HeightTarget;
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
    AreaTriggerMiscTemplate();
    ~AreaTriggerMiscTemplate();

    bool HasSplines()   const;

    uint32 MiscId;
    uint32 AreaTriggerEntry;

    uint32 MoveCurveId;
    uint32 ScaleCurveId;
    uint32 MorphCurveId;
    uint32 FacingCurveId;

    int32 AnimId;
    int32 AnimKitId;

    uint32 DecalPropertiesId;

    uint32 TimeToTarget;
    uint32 TimeToTargetScale;

    AreaTriggerScaleInfo OverrideScale;
    AreaTriggerScaleInfo ExtraScale;
    AreaTriggerOrbitInfo OrbitInfo;

    AreaTriggerTemplate const* Template;
    std::vector<Position> SplinePoints;
};

struct AreaTriggerSpawn
{
    ObjectGuid::LowType SpawnId = 0;
    AreaTriggerId Id;
    WorldLocation Location;
    uint32 PhaseId = 0;
    uint32 PhaseGroup = 0;
    uint8 PhaseUseFlags = 0;
};

#endif
