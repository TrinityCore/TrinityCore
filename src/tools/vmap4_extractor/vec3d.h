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

#ifndef VEC3D_H
#define VEC3D_H

class Vec3D
{
public:
    float x, y, z;

    Vec3D(float x0 = 0.0f, float y0 = 0.0f, float z0 = 0.0f) : x(x0), y(y0), z(z0) { }

    Vec3D(Vec3D const& v) = default;

    Vec3D& operator=(Vec3D const& v) = default;

    Vec3D operator+(Vec3D const& v) const
    {
        return Vec3D(*this) += v;
    }

    Vec3D operator-(Vec3D const& v) const
    {
        return Vec3D(*this) -= v;
    }

    Vec3D& operator+=(Vec3D const& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3D& operator-=(Vec3D const& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
};

class AaBox3D
{
public:
    Vec3D min;
    Vec3D max;

    AaBox3D& operator+=(Vec3D const& offset)
    {
        min += offset;
        max += offset;
        return *this;
    }
};

struct Quaternion
{
    float X, Y, Z, W;
};

#endif
