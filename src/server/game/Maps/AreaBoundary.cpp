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

#include "AreaBoundary.h"
#include "Errors.h"

// ---== RECTANGLE ==---
RectangleBoundary::RectangleBoundary(float southX, float northX, float eastY, float westY, bool isInverted) :
    AreaBoundary(isInverted), _minX(southX), _maxX(northX), _minY(eastY), _maxY(westY) { }

bool RectangleBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return pos->GetPositionX() >= _minX && pos->GetPositionX() <= _maxX
        && pos->GetPositionY() >= _minY && pos->GetPositionY() <= _maxY;
}

// ---== CIRCLE ==---
CircleBoundary::CircleBoundary(Position const& center, float radius, bool isInverted) :
    AreaBoundary(isInverted), _center(center), _radiusSq(radius * radius) { }

CircleBoundary::CircleBoundary(Position const& center, Position const& pointOnCircle, bool isInverted) :
    AreaBoundary(isInverted), _center(center), _radiusSq(_center.GetExactDist2dSq(pointOnCircle)) { }

bool CircleBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return _center.GetExactDistSq(pos) <= _radiusSq;
}

// ---== ELLIPSE ==---
EllipseBoundary::EllipseBoundary(Position const& center, float radiusX, float radiusY, bool isInverted) :
    AreaBoundary(isInverted), _center(center), _radiusYSq(radiusY * radiusY), _scaleXSq(_radiusYSq / (radiusX * radiusX)) { }

bool EllipseBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    float offX = _center.GetPositionX() - pos->GetPositionX();
    float offY = _center.GetPositionY() - pos->GetPositionY();
    return (offX * offX) * _scaleXSq + (offY * offY) <= _radiusYSq;
}

// ---== TRIANGLE ==---
TriangleBoundary::TriangleBoundary(Position const& pointA, Position const& pointB, Position const& pointC, bool isInverted) :
    AreaBoundary(isInverted), _a(pointA), _b(pointB), _c(pointC),
    _abx(_b.GetPositionX() - _a.GetPositionX()), _bcx(_c.GetPositionX() - _b.GetPositionX()), _cax(_a.GetPositionX() - _c.GetPositionX()),
    _aby(_b.GetPositionY() - _a.GetPositionY()), _bcy(_c.GetPositionY() - _b.GetPositionY()), _cay(_a.GetPositionY() - _c.GetPositionY()) { }

bool TriangleBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    // half-plane signs
    bool sign1 = ((-_b.GetPositionX() + pos->GetPositionX()) * _aby - (-_b.GetPositionY() + pos->GetPositionY()) * _abx) < 0;
    bool sign2 = ((-_c.GetPositionX() + pos->GetPositionX()) * _bcy - (-_c.GetPositionY() + pos->GetPositionY()) * _bcx) < 0;
    bool sign3 = ((-_a.GetPositionX() + pos->GetPositionX()) * _cay - (-_a.GetPositionY() + pos->GetPositionY()) * _cax) < 0;

    // if all signs are the same, the point is inside the triangle
    return ((sign1 == sign2) && (sign2 == sign3));
}

// ---== PARALLELOGRAM ==---
ParallelogramBoundary::ParallelogramBoundary(Position const& cornerA, Position const& cornerB, Position const& cornerD, bool isInverted) :
    AreaBoundary(isInverted), _a(cornerA), _b(cornerB), _d(cornerD),
    _c(_d.GetPositionX() + (_b.GetPositionX() - _a.GetPositionX()), _d.GetPositionY() + (_b.GetPositionY() - _a.GetPositionY())),
    _abx(_b.GetPositionX() - _a.GetPositionX()), _dax(_a.GetPositionX() - _d.GetPositionX()),
    _aby(_b.GetPositionY() - _a.GetPositionY()), _day(_a.GetPositionY() - _d.GetPositionY()) { }

bool ParallelogramBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    // half-plane signs
    bool sign1 = ((-_b.GetPositionX() + pos->GetPositionX()) * _aby - (-_b.GetPositionY() + pos->GetPositionY()) * _abx) < 0;
    bool sign2 = ((-_a.GetPositionX() + pos->GetPositionX()) * _day - (-_a.GetPositionY() + pos->GetPositionY()) * _dax) < 0;
    bool sign3 = ((-_d.GetPositionY() + pos->GetPositionY()) * _abx - (-_d.GetPositionX() + pos->GetPositionX()) * _aby) < 0; // AB = -CD
    bool sign4 = ((-_c.GetPositionY() + pos->GetPositionY()) * _dax - (-_c.GetPositionX() + pos->GetPositionX()) * _day) < 0; // DA = -BC

    // if all signs are equal, the point is inside
    return ((sign1 == sign2) && (sign2 == sign3) && (sign3 == sign4));
}

// ---== Z RANGE ==---
ZRangeBoundary::ZRangeBoundary(float minZ, float maxZ, bool isInverted) :
    AreaBoundary(isInverted), _minZ(minZ), _maxZ(maxZ) { }

bool ZRangeBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return pos->GetPositionZ() >= _minZ && pos->GetPositionZ() <= _maxZ;
}

// ---== POLYGON ==---
PolygonBoundary::PolygonBoundary(Position const& origin, std::vector<Position>&& vertices, bool isInverted /* = false*/) :
    AreaBoundary(isInverted), _origin(origin), _vertices(std::move(vertices)) { }

bool PolygonBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return pos->IsInPolygon2D(_origin, _vertices);
}

// ---== UNION OF 2 BOUNDARIES ==---
BoundaryUnionBoundary::BoundaryUnionBoundary(AreaBoundary const* b1, AreaBoundary const* b2, bool isInverted) :
    AreaBoundary(isInverted), _b1(b1), _b2(b2)
{
    ASSERT(b1 && b2);
}

BoundaryUnionBoundary::~BoundaryUnionBoundary()
{
    delete _b1;
    delete _b2;
}

bool BoundaryUnionBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return _b1->IsWithinBoundary(pos) || _b2->IsWithinBoundary(pos);
}

// ---== INTERSECTION OF 2 BOUNDARIES ==---
BoundaryIntersectionBoundary::BoundaryIntersectionBoundary(AreaBoundary const* b1, AreaBoundary const* b2, bool isInverted) :
    AreaBoundary(isInverted), _b1(b1), _b2(b2)
{
    ASSERT(b1 && b2);
}

BoundaryIntersectionBoundary::~BoundaryIntersectionBoundary()
{
    delete _b1;
    delete _b2;
}

bool BoundaryIntersectionBoundary::IsWithinBoundaryArea(Position const* pos) const
{
    return _b1->IsWithinBoundary(pos) && _b2->IsWithinBoundary(pos);
}
