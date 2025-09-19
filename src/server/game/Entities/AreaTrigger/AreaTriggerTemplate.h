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
    AREATRIGGER_ACTION_TAVERN      = 3,
    AREATRIGGER_ACTION_MAX         = 4
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
    AlwaysExterior                 = 0x00020,
    HasTargetRollPitchYaw          = 0x00040, // NYI
    HasAnimId                      = 0x00080, // DEPRECATED
    VisualAnimIsDecay              = 0x00100,
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

struct AreaTriggerShapeInfo
{
    struct Sphere
    {
        Sphere()
            : Radius(0.0f), RadiusTarget(0.0f) { }
        explicit Sphere(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : Radius(raw[0]), RadiusTarget(raw[1]) { }

        float Radius;
        float RadiusTarget;

        float GetMaxSearchRadius() const;
    };

    struct Box
    {
        Box()
            : Extents(), ExtentsTarget() { }
        explicit Box(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : Extents(raw[0], raw[1], raw[2]), ExtentsTarget(raw[3], raw[4], raw[5]) { }

        TaggedPosition<Position::XYZ> Extents;
        TaggedPosition<Position::XYZ> ExtentsTarget;

        float GetMaxSearchRadius() const;
    };

    struct Polygon
    {
        Polygon()
            : PolygonVertices(), PolygonVerticesTarget(), Height(0.0f), HeightTarget(0.0f) { }
        explicit Polygon(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : PolygonVertices(), PolygonVerticesTarget(), Height(raw[0]), HeightTarget(raw[1]) { }

        std::vector<TaggedPosition<Position::XY>> PolygonVertices;
        std::vector<TaggedPosition<Position::XY>> PolygonVerticesTarget;
        float Height;
        float HeightTarget;

        float GetMaxSearchRadius() const;
    };

    struct Cylinder
    {
        Cylinder()
            : Radius(0.0f), RadiusTarget(0.0f), Height(0.0f), HeightTarget(0.0f), LocationZOffset(0.0f), LocationZOffsetTarget(0.0f) { }
        explicit Cylinder(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : Radius(raw[0]), RadiusTarget(raw[1]), Height(raw[2]), HeightTarget(raw[3]), LocationZOffset(raw[4]), LocationZOffsetTarget(raw[5]) { }

        float Radius;
        float RadiusTarget;
        float Height;
        float HeightTarget;
        float LocationZOffset;
        float LocationZOffsetTarget;

        float GetMaxSearchRadius() const;
    };

    struct Disk
    {
        Disk()
            : InnerRadius(0.0f), InnerRadiusTarget(0.0f), OuterRadius(0.0f), OuterRadiusTarget(0.0f),
            Height(0.0f), HeightTarget(0.0f), LocationZOffset(0.0f), LocationZOffsetTarget(0.0f) { }
        explicit Disk(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : InnerRadius(raw[0]), InnerRadiusTarget(raw[1]), OuterRadius(raw[2]), OuterRadiusTarget(raw[3]),
            Height(raw[4]), HeightTarget(raw[5]), LocationZOffset(raw[6]), LocationZOffsetTarget(raw[7]) { }

        float InnerRadius;
        float InnerRadiusTarget;
        float OuterRadius;
        float OuterRadiusTarget;
        float Height;
        float HeightTarget;
        float LocationZOffset;
        float LocationZOffsetTarget;

        float GetMaxSearchRadius() const;
    };

    struct BoundedPlane
    {
        BoundedPlane()
            : Extents(), ExtentsTarget() { }
        explicit BoundedPlane(std::array<float, MAX_AREATRIGGER_ENTITY_DATA> const& raw)
            : Extents(raw[0], raw[1]), ExtentsTarget(raw[2], raw[3]) { }

        TaggedPosition<Position::XY> Extents;
        TaggedPosition<Position::XY> ExtentsTarget;

        float GetMaxSearchRadius() const;
    };

    std::variant<Sphere, Box, Polygon, Cylinder, Disk, BoundedPlane> Data;

    bool IsSphere()         const { return std::holds_alternative<Sphere>(Data);        }
    bool IsBox()            const { return std::holds_alternative<Box>(Data);           }
    bool IsPolygon()        const { return std::holds_alternative<Polygon>(Data);       }
    bool IsCylinder()       const { return std::holds_alternative<Cylinder>(Data);      }
    bool IsDisk()           const { return std::holds_alternative<Disk>(Data);          }
    bool IsBoundedPlane()   const { return std::holds_alternative<BoundedPlane>(Data);  }
    float GetMaxSearchRadius() const;
};

struct AreaTriggerOrbitInfo
{
    Optional<ObjectGuid> PathTarget;
    Optional<TaggedPosition<Position::XYZ>> Center;
    bool CounterClockwise = false;
    bool CanLoop = false;
    int32 ExtraTimeForBlending = 0;
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

    AreaTriggerId Id = { .Id = 0, .IsCustom = false };
    EnumFlag<AreaTriggerFlag> Flags = AreaTriggerFlag::None;
    uint32 ActionSetId = 0;
    EnumFlag<AreaTriggerActionSetFlag> ActionSetFlags = AreaTriggerActionSetFlag::None;
    std::vector<AreaTriggerAction> Actions;
};

class AreaTriggerCreateProperties
{
public:
    AreaTriggerCreateProperties();
    ~AreaTriggerCreateProperties();

    AreaTriggerCreatePropertiesId Id = { .Id = 0, .IsCustom = false };
    AreaTriggerTemplate const* Template = nullptr;
    EnumFlag<AreaTriggerCreatePropertiesFlag> Flags = AreaTriggerCreatePropertiesFlag::None;

    uint32 MoveCurveId = 0;
    uint32 ScaleCurveId = 0;
    uint32 MorphCurveId = 0;
    uint32 FacingCurveId = 0;

    int32 AnimId = 0;
    int32 AnimKitId = 0;

    uint32 DecalPropertiesId = 0;

    Optional<int32> SpellForVisuals;

    uint32 TimeToTargetScale = 0;

    AreaTriggerShapeInfo Shape;

    float Speed = 1.0f;
    bool SpeedIsTime = false;
    using SplineInfo = std::vector<Position>;
    std::variant<std::monostate, SplineInfo, AreaTriggerOrbitInfo> Movement;

    uint32 ScriptId = 0;
};

struct AreaTriggerSpawn : SpawnData
{
    AreaTriggerSpawn() : SpawnData(SPAWN_TYPE_AREATRIGGER) { }

    AreaTriggerCreatePropertiesId Id;
};

#endif
