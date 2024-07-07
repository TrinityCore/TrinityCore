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
#include "EnumFlag.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "SpawnData.h"
#include <variant>
#include <vector>

#define MAX_AREATRIGGER_ENTITY_DATA 8
#define MAX_AREATRIGGER_SCALE 7

enum class AreaTriggerFlag : uint32
{
    None                           = 0x00,
    IsServerSide                   = 0x01
};

DEFINE_ENUM_FLAG(AreaTriggerFlag);

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

enum class AreaTriggerCreatePropertiesFlag : uint32
{
    None                           = 0x00000,
    HasAbsoluteOrientation         = 0x00001,
    HasDynamicShape                = 0x00002,
    HasAttached                    = 0x00004,
    HasFaceMovementDir             = 0x00008,
    HasFollowsTerrain              = 0x00010, // NYI
    Unk1                           = 0x00020,
    HasTargetRollPitchYaw          = 0x00040, // NYI
    HasAnimId                      = 0x00080, // DEPRECATED
    Unk3                           = 0x00100,
    HasAnimKitId                   = 0x00200, // DEPRECATED
    HasCircularMovement            = 0x00400, // DEPRECATED
    Unk5                           = 0x00800,
};

DEFINE_ENUM_FLAG(AreaTriggerCreatePropertiesFlag);

struct AreaTriggerId
{
    uint32 Id = 0;
    bool IsCustom = false;

    friend bool operator==(AreaTriggerId const& left, AreaTriggerId const& right) = default;
};

typedef AreaTriggerId AreaTriggerCreatePropertiesId;

struct AreaTriggerAction
{
    uint32 Param;
    AreaTriggerActionTypes ActionType;
    AreaTriggerActionUserTypes TargetType;
};

struct AreaTriggerScaleCurvePointsTemplate
{
    AreaTriggerScaleCurvePointsTemplate();

    CurveInterpolationMode Mode;
    std::array<DBCPosition2D, 2> Points;
};

struct AreaTriggerScaleCurveTemplate
{
    AreaTriggerScaleCurveTemplate();

    uint32 StartTimeOffset;
    std::variant<float, AreaTriggerScaleCurvePointsTemplate> Curve;
};

struct AreaTriggerShapeInfo
{
    AreaTriggerShapeInfo();

    bool IsSphere()         const { return Type == AreaTriggerShapeType::Sphere;        }
    bool IsBox()            const { return Type == AreaTriggerShapeType::Box;           }
    bool IsPolygon()        const { return Type == AreaTriggerShapeType::Polygon;       }
    bool IsCylinder()       const { return Type == AreaTriggerShapeType::Cylinder;      }
    bool IsDisk()           const { return Type == AreaTriggerShapeType::Disk;          }
    bool IsBoundedPlane()   const { return Type == AreaTriggerShapeType::BoundedPlane;  }
    float GetMaxSearchRadius() const;

    AreaTriggerShapeType Type;

    std::vector<TaggedPosition<Position::XY>> PolygonVertices;
    std::vector<TaggedPosition<Position::XY>> PolygonVerticesTarget;

    union
    {
        struct
        {
            float Data[MAX_AREATRIGGER_ENTITY_DATA];
        } DefaultDatas;

        // AreaTriggerShapeType::Sphere
        struct
        {
            float Radius;
            float RadiusTarget;
        } SphereDatas;

        // AreaTriggerShapeType::Box
        struct
        {
            float Extents[3];
            float ExtentsTarget[3];
        } BoxDatas;

        // AreaTriggerShapeType::Polygon
        struct
        {
            float Height;
            float HeightTarget;
        } PolygonDatas;

        // AreaTriggerShapeType::Cylinder
        struct
        {
            float Radius;
            float RadiusTarget;
            float Height;
            float HeightTarget;
            float LocationZOffset;
            float LocationZOffsetTarget;
        } CylinderDatas;

        // AreaTriggerShapeType::Disk
        struct
        {
            float InnerRadius;
            float InnerRadiusTarget;
            float OuterRadius;
            float OuterRadiusTarget;
            float Height;
            float HeightTarget;
            float LocationZOffset;
            float LocationZOffsetTarget;
        } DiskDatas;

        // AreaTriggerShapeType::BoundedPlane
        struct
        {
            float Extents[2];
            float ExtentsTarget[2];
        } BoundedPlaneDatas;
    };
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

    AreaTriggerId Id;
    EnumFlag<AreaTriggerFlag> Flags;
    std::vector<AreaTriggerAction> Actions;
};

class AreaTriggerCreateProperties
{
public:
    AreaTriggerCreateProperties();
    ~AreaTriggerCreateProperties();

    bool HasSplines() const;

    AreaTriggerCreatePropertiesId Id;
    AreaTriggerTemplate const* Template;
    EnumFlag<AreaTriggerCreatePropertiesFlag> Flags;

    uint32 MoveCurveId;
    uint32 ScaleCurveId;
    uint32 MorphCurveId;
    uint32 FacingCurveId;

    int32 AnimId;
    int32 AnimKitId;

    uint32 DecalPropertiesId;

    Optional<int32> SpellForVisuals;

    uint32 TimeToTarget;
    uint32 TimeToTargetScale;

    Optional<AreaTriggerScaleCurveTemplate> OverrideScale;
    Optional<AreaTriggerScaleCurveTemplate> ExtraScale;

    AreaTriggerShapeInfo Shape;

    std::vector<Position> SplinePoints;
    Optional<AreaTriggerOrbitInfo> OrbitInfo;

    uint32 ScriptId;
};

struct AreaTriggerSpawn : SpawnData
{
    AreaTriggerSpawn() : SpawnData(SPAWN_TYPE_AREATRIGGER) { }

    AreaTriggerCreatePropertiesId Id;
};

#endif
