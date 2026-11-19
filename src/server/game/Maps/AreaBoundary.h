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

#ifndef TRINITY_AREA_BOUNDARY_H
#define TRINITY_AREA_BOUNDARY_H

#include "Position.h"
#include <vector>

class TC_GAME_API AreaBoundary
{
public:
    bool IsWithinBoundary(Position const* pos) const { return pos && (IsWithinBoundaryArea(pos) != _isInvertedBoundary); }
    bool IsWithinBoundary(Position const& pos) const { return IsWithinBoundary(&pos); }

    AreaBoundary(AreaBoundary const&) = delete;
    AreaBoundary(AreaBoundary&&) = delete;
    AreaBoundary& operator=(AreaBoundary const&) = delete;
    AreaBoundary& operator=(AreaBoundary&&) = delete;

    virtual ~AreaBoundary() = default;

protected:
    explicit AreaBoundary(bool isInverted) : _isInvertedBoundary(isInverted) { }

    virtual bool IsWithinBoundaryArea(Position const* pos) const = 0;

private:
    bool const _isInvertedBoundary;
};

class TC_GAME_API RectangleBoundary : public AreaBoundary
{
public:
    // X axis is north/south, Y axis is east/west, larger values are northwest
    RectangleBoundary(float southX, float northX, float eastY, float westY, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    float const _minX, _maxX, _minY, _maxY;
};

class TC_GAME_API CircleBoundary : public AreaBoundary
{
public:
    CircleBoundary(Position const& center, float radius, bool isInverted = false);
    CircleBoundary(Position const& center, Position const& pointOnCircle, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    Position const _center;
    float const _radiusSq;
};

class TC_GAME_API EllipseBoundary : public AreaBoundary
{
public:
    EllipseBoundary(Position const& center, float radiusX, float radiusY, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    Position const _center;
    float const _radiusYSq, _scaleXSq;
};

class TC_GAME_API TriangleBoundary : public AreaBoundary
{
public:
    TriangleBoundary(Position const& pointA, Position const& pointB, Position const& pointC, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    Position const _a, _b, _c;
    float const _abx, _bcx, _cax, _aby, _bcy, _cay;
};

class TC_GAME_API ParallelogramBoundary : public AreaBoundary
{
public:
    // Note: AB must be orthogonal to AD
    ParallelogramBoundary(Position const& cornerA, Position const& cornerB, Position const& cornerD, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    Position const _a, _b, _d, _c;
    float const _abx, _dax, _aby, _day;
};

class TC_GAME_API ZRangeBoundary : public AreaBoundary
{
public:
    ZRangeBoundary(float minZ, float maxZ, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    float const _minZ, _maxZ;
};

class TC_GAME_API PolygonBoundary : public AreaBoundary
{
public:
    PolygonBoundary(Position const& origin, std::vector<Position>&& vertices, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    Position _origin;
    std::vector<Position> _vertices;
};

class TC_GAME_API BoundaryUnionBoundary : public AreaBoundary
{
public:
    BoundaryUnionBoundary(AreaBoundary const* b1, AreaBoundary const* b2, bool isInverted = false);
    BoundaryUnionBoundary(BoundaryUnionBoundary const&) = delete;
    BoundaryUnionBoundary(BoundaryUnionBoundary&&) = delete;
    BoundaryUnionBoundary& operator=(BoundaryUnionBoundary const&) = delete;
    BoundaryUnionBoundary& operator=(BoundaryUnionBoundary&&) = delete;

protected:
    virtual ~BoundaryUnionBoundary();
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    AreaBoundary const* const _b1;
    AreaBoundary const* const _b2;
};

class TC_GAME_API BoundaryIntersectionBoundary : public AreaBoundary
{
public:
    BoundaryIntersectionBoundary(AreaBoundary const* b1, AreaBoundary const* b2, bool isInverted = false);
    BoundaryIntersectionBoundary(BoundaryIntersectionBoundary const&) = delete;
    BoundaryIntersectionBoundary(BoundaryIntersectionBoundary&&) = delete;
    BoundaryIntersectionBoundary& operator=(BoundaryIntersectionBoundary const&) = delete;
    BoundaryIntersectionBoundary& operator=(BoundaryIntersectionBoundary&&) = delete;

protected:
    virtual ~BoundaryIntersectionBoundary();
    bool IsWithinBoundaryArea(Position const* pos) const override;

private:
    AreaBoundary const* const _b1;
    AreaBoundary const* const _b2;
};

#endif //TRINITY_AREA_BOUNDARY_H
