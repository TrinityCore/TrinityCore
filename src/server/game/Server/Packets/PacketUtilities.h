/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PacketUtilities_h__
#define PacketUtilities_h__

#include "ByteBuffer.h"
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>

inline ByteBuffer& operator<<(ByteBuffer& data, G3D::Vector2 const& v)
{
    data << v.x << v.y;
    return data;
}

inline ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector2& v)
{
    data >> v.x >> v.y;
    return data;
}

inline ByteBuffer& operator<<(ByteBuffer& data, G3D::Vector3 const& v)
{
    data << v.x << v.y << v.z;
    return data;
}

inline ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector3& v)
{
    data >> v.x >> v.y >> v.z;
    return data;
}

#endif // PacketUtilities_h__
