/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#include <iostream>
#include <cmath>

class Vec3D
{
public:
    float x,y,z;

    Vec3D(float x0 = 0.0f, float y0 = 0.0f, float z0 = 0.0f) : x(x0), y(y0), z(z0) {}

    Vec3D(const Vec3D& v) : x(v.x), y(v.y), z(v.z) {}

    Vec3D& operator= (const Vec3D &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vec3D operator+ (const Vec3D &v) const
    {
        Vec3D r(x+v.x,y+v.y,z+v.z);
        return r;
    }

    Vec3D operator- (const Vec3D &v) const
    {
        Vec3D r(x-v.x,y-v.y,z-v.z);
        return r;
    }

    float operator* (const Vec3D &v) const
    {
        return x*v.x + y*v.y + z*v.z;
    }

    Vec3D operator* (float d) const
    {
        Vec3D r(x*d,y*d,z*d);
        return r;
    }

    friend Vec3D operator* (float d, const Vec3D& v)
    {
        return v * d;
    }

    Vec3D operator% (const Vec3D &v) const
    {
        Vec3D r(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
        return r;
    }

    Vec3D& operator+= (const Vec3D &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3D& operator-= (const Vec3D &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3D& operator*= (float d)
    {
        x *= d;
        y *= d;
        z *= d;
        return *this;
    }

    float lengthSquared() const
    {
        return x*x+y*y+z*z;
    }

    float length() const
    {
        return std::sqrt(x*x+y*y+z*z);
    }

    Vec3D& normalize()
    {
        this->operator*= (1.0f/length());
        return *this;
    }

    Vec3D operator~ () const
    {
        Vec3D r(*this);
        r.normalize();
        return r;
    }

    friend std::istream& operator>>(std::istream& in, Vec3D& v)
    {
        in >> v.x >> v.y >> v.z;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vec3D& v)
    {
        out << v.x << " " << v.y << " " << v.z;
        return out;
    }

    operator float*()
    {
        return (float*)this;
    }
};


class Vec2D
{
public:
    float x,y;

    Vec2D(float x0 = 0.0f, float y0 = 0.0f) : x(x0), y(y0) {}

    Vec2D(const Vec2D& v) : x(v.x), y(v.y) {}

    Vec2D& operator= (const Vec2D &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vec2D operator+ (const Vec2D &v) const
    {
        Vec2D r(x+v.x,y+v.y);
        return r;
    }

    Vec2D operator- (const Vec2D &v) const
    {
        Vec2D r(x-v.x,y-v.y);
        return r;
    }

    float operator* (const Vec2D &v) const
    {
        return x*v.x + y*v.y;
    }

    Vec2D operator* (float d) const
    {
        Vec2D r(x*d,y*d);
        return r;
    }

    friend Vec2D operator* (float d, const Vec2D& v)
    {
        return v * d;
    }

    Vec2D& operator+= (const Vec2D &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2D& operator-= (const Vec2D &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vec2D& operator*= (float d)
    {
        x *= d;
        y *= d;
        return *this;
    }

    float lengthSquared() const
    {
        return x*x+y*y;
    }

    float length() const
    {
        return std::sqrt(x*x+y*y);
    }

    Vec2D& normalize()
    {
        this->operator*= (1.0f/length());
        return *this;
    }

    Vec2D operator~ () const
    {
        Vec2D r(*this);
        r.normalize();
        return r;
    }


    friend std::istream& operator>>(std::istream& in, Vec2D& v)
    {
        in >> v.x >> v.y;
        return in;
    }

    operator float*()
    {
        return (float*)this;
    }
};

inline void rotate(float x0, float y0, float *x, float *y, float angle)
{
    float xa = *x - x0, ya = *y - y0;
    *x = xa*cosf(angle) - ya*sinf(angle) + x0;
    *y = xa*sinf(angle) + ya*cosf(angle) + y0;
}

#endif
