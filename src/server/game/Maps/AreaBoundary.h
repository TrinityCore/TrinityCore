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
    virtual ~AreaBoundary() = default;

    [[nodiscard]] bool IsWithinBoundary(const Position& pos) const { return IsWithinBoundary(&pos); }
    bool IsWithinBoundary(const Position* pos) const { return pos && (IsWithinBoundaryArea(pos) != _isInvertedBoundary); }

    AreaBoundary(const AreaBoundary&) = delete;
    AreaBoundary(AreaBoundary&&) = delete;
    AreaBoundary& operator=(const AreaBoundary&) = delete;
    AreaBoundary& operator=(AreaBoundary&&) = delete;

protected:
    explicit AreaBoundary(bool isInverted) : _isInvertedBoundary(isInverted) {}
    virtual bool IsWithinBoundaryArea(const Position* pos) const = 0;

private:
    const bool _isInvertedBoundary;
};

class TC_GAME_API RectangleBoundary : public AreaBoundary
{
public:
    RectangleBoundary(float southX, float northX, float eastY, float westY, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const float _minX, _maxX, _minY, _maxY;
};

class TC_GAME_API CircleBoundary : public AreaBoundary
{
public:
    CircleBoundary(const Position& center, float radius, bool isInverted = false);
    CircleBoundary(const Position& center, const Position& pointOnCircle, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const Position _center;
    const float _radiusSq;
};

class TC_GAME_API EllipseBoundary : public AreaBoundary
{
public:
    EllipseBoundary(const Position& center, float radiusX, float radiusY, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const Position _center;
    const float _radiusYSq, _scaleXSq;
};

class TC_GAME_API TriangleBoundary : public AreaBoundary
{
public:
    TriangleBoundary(const Position& pointA, const Position& pointB, const Position& pointC, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const Position _a, _b, _c;
    const float _abx, _bcx, _cax, _aby, _bcy, _cay;
};

class TC_GAME_API ParallelogramBoundary : public AreaBoundary
{
public:
    ParallelogramBoundary(const Position& cornerA, const Position& cornerB, const Position& cornerD, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const Position _a, _b, _d, _c;
    const float _abx, _dax, _aby, _day;
};

class TC_GAME_API ZRangeBoundary : public AreaBoundary
{
public:
    ZRangeBoundary(float minZ, float maxZ, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    const float _minZ, _maxZ;
};

class TC_GAME_API PolygonBoundary : public AreaBoundary
{
public:
    PolygonBoundary(const Position& origin, std::vector<Position> vertices, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    Position _origin;
    std::vector<Position> _vertices;
};

class TC_GAME_API BoundaryUnionBoundary : public AreaBoundary
{
public:
    BoundaryUnionBoundary(std::unique_ptr<AreaBoundary> b1, std::unique_ptr<AreaBoundary> b2, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    std::unique_ptr<AreaBoundary> _b1;
    std::unique_ptr<AreaBoundary> _b2;
};

class TC_GAME_API BoundaryIntersectionBoundary : public AreaBoundary
{
public:
    BoundaryIntersectionBoundary(std::unique_ptr<AreaBoundary> b1, std::unique_ptr<AreaBoundary> b2, bool isInverted = false);

protected:
    bool IsWithinBoundaryArea(const Position* pos) const override;

private:
    std::unique_ptr<AreaBoundary> _b1;
    std::unique_ptr<AreaBoundary> _b2;
};

#endif // TRINITY_AREA_BOUNDARY_H
