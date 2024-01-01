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

#include "AreaTriggerTemplate.h"
#include <G3D/Vector3.h>
#include <algorithm>
#include <cstring>
#include <cmath>

AreaTriggerScaleCurvePointsTemplate::AreaTriggerScaleCurvePointsTemplate() : Mode(CurveInterpolationMode::Linear), Points()
{
}

AreaTriggerScaleCurveTemplate::AreaTriggerScaleCurveTemplate() : StartTimeOffset(0), Curve(1.0f)
{
}

AreaTriggerShapeInfo::AreaTriggerShapeInfo()
{
    Type = AreaTriggerShapeType::Max;
    memset(DefaultDatas.Data, 0, sizeof(DefaultDatas.Data));
}

float AreaTriggerShapeInfo::GetMaxSearchRadius() const
{
    switch (Type)
    {
        case AreaTriggerShapeType::Sphere:
            return std::max(SphereDatas.Radius, SphereDatas.RadiusTarget);
        case AreaTriggerShapeType::Box:
            return std::sqrt(std::max(
                BoxDatas.Extents[0] * BoxDatas.Extents[0] + BoxDatas.Extents[1] * BoxDatas.Extents[1],
                BoxDatas.ExtentsTarget[0] * BoxDatas.ExtentsTarget[0] + BoxDatas.ExtentsTarget[1] * BoxDatas.ExtentsTarget[1]));
        case AreaTriggerShapeType::Polygon:
        {
            Position center(0.0f, 0.0f);
            float maxSearchRadius = 0.0f;

            for (TaggedPosition<Position::XY> const& vertex : PolygonVertices)
                maxSearchRadius = std::max(maxSearchRadius, center.GetExactDist2d(vertex));

            for (TaggedPosition<Position::XY> const& vertex : PolygonVerticesTarget)
                maxSearchRadius = std::max(maxSearchRadius, center.GetExactDist2d(vertex));

            return maxSearchRadius;
        }
        case AreaTriggerShapeType::Cylinder:
            return std::max(CylinderDatas.Radius, CylinderDatas.RadiusTarget);
        case AreaTriggerShapeType::Disk:
            return std::max(DiskDatas.OuterRadius, DiskDatas.OuterRadiusTarget);
        case AreaTriggerShapeType::BoundedPlane:
            return std::sqrt(std::max(
                BoundedPlaneDatas.Extents[0] * BoundedPlaneDatas.Extents[0] / 4 + BoundedPlaneDatas.Extents[1] * BoundedPlaneDatas.Extents[1] / 4,
                BoundedPlaneDatas.ExtentsTarget[0] * BoundedPlaneDatas.ExtentsTarget[0] / 4 + BoundedPlaneDatas.ExtentsTarget[1] * BoundedPlaneDatas.ExtentsTarget[1] / 4));
        default:
            break;
    }

    return 0.0f;
}

AreaTriggerTemplate::AreaTriggerTemplate() : Flags(AreaTriggerFlag::None)
{
    Id = { 0, false };
}

AreaTriggerTemplate::~AreaTriggerTemplate() = default;

AreaTriggerCreateProperties::AreaTriggerCreateProperties() : Flags(AreaTriggerCreatePropertiesFlag::None)
{
    Id = { 0, false };
    Template = nullptr;

    MoveCurveId = 0;
    ScaleCurveId = 0;
    MorphCurveId = 0;
    FacingCurveId = 0;

    AnimId = 0;
    AnimKitId = 0;

    DecalPropertiesId = 0;

    TimeToTarget = 0;
    TimeToTargetScale = 0;

    ExtraScale.emplace();

    ScriptId = 0;
}

AreaTriggerCreateProperties::~AreaTriggerCreateProperties() = default;

bool AreaTriggerCreateProperties::HasSplines() const
{
    return SplinePoints.size() >= 2;
}
