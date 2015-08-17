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

#ifndef Trinity_game_Position_h__
#define Trinity_game_Position_h__

#include "Common.h"

class ByteBuffer;

struct Position
{
    Position(float x = 0, float y = 0, float z = 0, float o = 0)
        : m_positionX(x), m_positionY(y), m_positionZ(z), m_orientation(NormalizeOrientation(o)) { }

    Position(Position const& loc) { Relocate(loc); }

    struct PositionXYStreamer
    {
        explicit PositionXYStreamer(Position& pos) : Pos(&pos) { }
        Position* Pos;
    };

    struct PositionXYZStreamer
    {
        explicit PositionXYZStreamer(Position& pos) : Pos(&pos) { }
        Position* Pos;
    };

    struct PositionXYZOStreamer
    {
        explicit PositionXYZOStreamer(Position& pos) : Pos(&pos) { }
        Position* Pos;
    };

    float m_positionX;
    float m_positionY;
    float m_positionZ;
    // Better to limit access to _orientation field, to guarantee the value is normalized
private:
    float m_orientation;

public:
    bool operator==(Position const &a);

    inline bool operator!=(Position const &a)
    {
        return !(operator==(a));
    }

    void Relocate(float x, float y)
    {
        m_positionX = x; m_positionY = y;
    }

    void Relocate(float x, float y, float z)
    {
        m_positionX = x; m_positionY = y; m_positionZ = z;
    }

    void Relocate(float x, float y, float z, float orientation)
    {
        m_positionX = x; m_positionY = y; m_positionZ = z; SetOrientation(orientation);
    }

    void Relocate(Position const &pos)
    {
        m_positionX = pos.m_positionX; m_positionY = pos.m_positionY; m_positionZ = pos.m_positionZ; SetOrientation(pos.m_orientation);
    }

    void Relocate(Position const* pos)
    {
        m_positionX = pos->m_positionX; m_positionY = pos->m_positionY; m_positionZ = pos->m_positionZ; SetOrientation(pos->m_orientation);
    }

    void RelocateOffset(Position const &offset);

    void SetOrientation(float orientation)
    {
        m_orientation = NormalizeOrientation(orientation);
    }

    float GetPositionX() const { return m_positionX; }
    float GetPositionY() const { return m_positionY; }
    float GetPositionZ() const { return m_positionZ; }
    float GetOrientation() const { return m_orientation; }

    void GetPosition(float &x, float &y) const
    {
        x = m_positionX; y = m_positionY;
    }

    void GetPosition(float &x, float &y, float &z) const
    {
        x = m_positionX; y = m_positionY; z = m_positionZ;
    }

    void GetPosition(float &x, float &y, float &z, float &o) const
    {
        x = m_positionX; y = m_positionY; z = m_positionZ; o = m_orientation;
    }

    Position GetPosition() const { return *this; }

    Position::PositionXYStreamer PositionXYStream() { return PositionXYStreamer(*this); }
    Position::PositionXYZStreamer PositionXYZStream() { return PositionXYZStreamer(*this); }
    Position::PositionXYZOStreamer PositionXYZOStream() { return PositionXYZOStreamer(*this); }

    bool IsPositionValid() const;

    float GetExactDist2dSq(float x, float y) const
    {
        float dx = m_positionX - x; float dy = m_positionY - y; return dx*dx + dy*dy;
    }

    float GetExactDist2d(const float x, const float y) const
    {
        return std::sqrt(GetExactDist2dSq(x, y));
    }

    float GetExactDist2dSq(Position const* pos) const
    {
        float dx = m_positionX - pos->m_positionX; float dy = m_positionY - pos->m_positionY; return dx*dx + dy*dy;
    }

    float GetExactDist2d(Position const* pos) const
    {
        return std::sqrt(GetExactDist2dSq(pos));
    }

    float GetExactDistSq(float x, float y, float z) const
    {
        float dz = m_positionZ - z; return GetExactDist2dSq(x, y) + dz*dz;
    }

    float GetExactDist(float x, float y, float z) const
    {
        return std::sqrt(GetExactDistSq(x, y, z));
    }

    float GetExactDistSq(Position const* pos) const
    {
        float dx = m_positionX - pos->m_positionX; float dy = m_positionY - pos->m_positionY; float dz = m_positionZ - pos->m_positionZ; return dx*dx + dy*dy + dz*dz;
    }

    float GetExactDist(Position const* pos) const
    {
        return std::sqrt(GetExactDistSq(pos));
    }

    void GetPositionOffsetTo(Position const & endPos, Position & retOffset) const;
    Position GetPositionWithOffset(Position const& offset) const;

    float GetAngle(Position const* pos) const;
    float GetAngle(float x, float y) const;
    float GetRelativeAngle(Position const* pos) const
    {
        return GetAngle(pos) - m_orientation;
    }

    float GetRelativeAngle(float x, float y) const { return GetAngle(x, y) - m_orientation; }
    void GetSinCos(float x, float y, float &vsin, float &vcos) const;

    bool IsInDist2d(float x, float y, float dist) const
    {
        return GetExactDist2dSq(x, y) < dist * dist;
    }

    bool IsInDist2d(Position const* pos, float dist) const
    {
        return GetExactDist2dSq(pos) < dist * dist;
    }

    bool IsInDist(float x, float y, float z, float dist) const
    {
        return GetExactDistSq(x, y, z) < dist * dist;
    }

    bool IsInDist(Position const* pos, float dist) const
    {
        return GetExactDistSq(pos) < dist * dist;
    }

    bool IsWithinBox(const Position& center, float xradius, float yradius, float zradius) const;
    bool HasInArc(float arcangle, Position const* pos, float border = 2.0f) const;
    bool HasInLine(Position const* pos, float width) const;
    std::string ToString() const;

    // modulos a radian orientation to the range of 0..2PI
    static float NormalizeOrientation(float o)
    {
        // fmod only supports positive numbers. Thus we have
        // to emulate negative numbers
        if (o < 0)
        {
            float mod = o *-1;
            mod = std::fmod(mod, 2.0f * static_cast<float>(M_PI));
            mod = -mod + 2.0f * static_cast<float>(M_PI);
            return mod;
        }
        return std::fmod(o, 2.0f * static_cast<float>(M_PI));
    }
};

ByteBuffer& operator<<(ByteBuffer& buf, Position::PositionXYStreamer const& streamer);
ByteBuffer& operator>>(ByteBuffer& buf, Position::PositionXYStreamer const& streamer);
ByteBuffer& operator<<(ByteBuffer& buf, Position::PositionXYZStreamer const& streamer);
ByteBuffer& operator>>(ByteBuffer& buf, Position::PositionXYZStreamer const& streamer);
ByteBuffer& operator<<(ByteBuffer& buf, Position::PositionXYZOStreamer const& streamer);
ByteBuffer& operator>>(ByteBuffer& buf, Position::PositionXYZOStreamer const& streamer);

#endif // Trinity_game_Position_h__
