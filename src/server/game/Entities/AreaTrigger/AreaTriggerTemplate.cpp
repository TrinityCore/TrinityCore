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
#include <algorithm>
#include <cmath>

float AreaTriggerShapeInfo::Sphere::GetMaxSearchRadius() const
{
    return std::max(Radius, RadiusTarget);
}

float AreaTriggerShapeInfo::Box::GetMaxSearchRadius() const
{
    return std::sqrt(std::max(
        Extents.Pos.GetPositionX() * Extents.Pos.GetPositionX() + Extents.Pos.GetPositionY() * Extents.Pos.GetPositionY(),
        ExtentsTarget.Pos.GetPositionX() * ExtentsTarget.Pos.GetPositionX() + ExtentsTarget.Pos.GetPositionY() * ExtentsTarget.Pos.GetPositionY()));
}

float AreaTriggerShapeInfo::Polygon::GetMaxSearchRadius() const
{
    Position center(0.0f, 0.0f);
    float maxSearchRadius = 0.0f;

    for (TaggedPosition<Position::XY> const& vertex : PolygonVertices)
        maxSearchRadius = std::max(maxSearchRadius, center.GetExactDist2d(vertex));

    for (TaggedPosition<Position::XY> const& vertex : PolygonVerticesTarget)
        maxSearchRadius = std::max(maxSearchRadius, center.GetExactDist2d(vertex));

    return maxSearchRadius;
}

float AreaTriggerShapeInfo::Cylinder::GetMaxSearchRadius() const
{
    return std::max(Radius, RadiusTarget);
}

float AreaTriggerShapeInfo::Disk::GetMaxSearchRadius() const
{
    return std::max(OuterRadius, OuterRadiusTarget);
}

float AreaTriggerShapeInfo::BoundedPlane::GetMaxSearchRadius() const
{
    return std::sqrt(std::max(
        Extents.Pos.GetPositionX() * Extents.Pos.GetPositionX() / 4 + Extents.Pos.GetPositionY() * Extents.Pos.GetPositionY() / 4,
        ExtentsTarget.Pos.GetPositionX() * ExtentsTarget.Pos.GetPositionX() / 4 + ExtentsTarget.Pos.GetPositionY() * ExtentsTarget.Pos.GetPositionY() / 4));
}

float AreaTriggerShapeInfo::GetMaxSearchRadius() const
{
    return std::visit([&](auto const& data) { return data.GetMaxSearchRadius(); }, Data);
}

AreaTriggerTemplate::AreaTriggerTemplate() = default;
AreaTriggerTemplate::~AreaTriggerTemplate() = default;

AreaTriggerCreateProperties::AreaTriggerCreateProperties() = default;
AreaTriggerCreateProperties::~AreaTriggerCreateProperties() = default;
