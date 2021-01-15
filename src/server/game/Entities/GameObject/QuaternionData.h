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

#ifndef QuaternionData_h__
#define QuaternionData_h__

#include "Define.h"

struct TC_GAME_API QuaternionData
{
    float x, y, z, w;

    QuaternionData() : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
    {
    }
    QuaternionData(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W)
    {
    }

    bool isUnit() const;
    static QuaternionData fromEulerAnglesZYX(float Z, float Y, float X);

    friend bool operator==(QuaternionData const& left, QuaternionData const& right)
    {
        return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
    }

    friend bool operator!=(QuaternionData const& left, QuaternionData const& right)
    {
        return !(left == right);
    }
};

#endif // QuaternionData_h__
