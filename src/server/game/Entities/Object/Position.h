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

#ifndef Trinity_game_Position_h__
#define Trinity_game_Position_h__

#include "Define.h"
#include <string>
#include <cmath>

class ByteBuffer;

struct TC_GAME_API Position
{
    Position(float x = 0, float y = 0, float z = 0, float o = 0)
        : m_positionX(x), m_positionY(y), m_positionZ(z), m_orientation(NormalizeOrientation(o)) { }

    // streamer tags
    struct XY;
    struct XYZ;
    struct XYZO;
    struct PackedXYZ;

    template <class Tag>
    struct ConstStreamer
    {
        explicit ConstStreamer(Position const& pos) : Pos(&pos) { }
        Position const* Pos;
    };

    template <class Tag>
    struct Streamer
    {
        explicit Streamer(Position& pos) : Pos(&pos) { }
        operator ConstStreamer<Tag>() const { return ConstStreamer<Tag>(*Pos); }
        Position* Pos;
    };

    float m_positionX;
    float m_positionY;
    float m_positionZ;
    // Better to limit access to _orientation field, to guarantee the value is normalized
private:
    float m_orientation;

public:
    bool operator==(Position const& a);
    bool operator!=(Position const& a) { return !(operator==(a)); }

    void Relocate(float x, float y) { m_positionX = x; m_positionY = y; }
    void Relocate(float x, float y, float z) { Relocate(x, y); m_positionZ = z; }
    void Relocate(float x, float y, float z, float o) { Relocate(x, y, z); SetOrientation(o); }
    void Relocate(Position const& pos) { *this = pos; }
    void Relocate(Position const* pos) { *this = *pos; }

    void RelocateOffset(Position const& offset);

    void SetOrientation(float orientation)
    {
        m_orientation = NormalizeOrientation(orientation);
    }

    float GetPositionX() const { return m_positionX; }
    float GetPositionY() const { return m_positionY; }
    float GetPositionZ() const { return m_positionZ; }
    float GetOrientation() const { return m_orientation; }

    void GetPosition(float &x, float &y) const { x = m_positionX; y = m_positionY; }
    void GetPosition(float &x, float &y, float &z) const { GetPosition(x, y); z = m_positionZ; }
    void GetPosition(float &x, float &y, float &z, float &o) const { GetPosition(x, y, z); o = m_orientation; }
    Position GetPosition() const { return *this; }

    Streamer<XY> PositionXYStream() { return Streamer<XY>(*this); }
    ConstStreamer<XY> PositionXYStream() const { return ConstStreamer<XY>(*this); }
    Streamer<XYZ> PositionXYZStream() { return Streamer<XYZ>(*this); }
    ConstStreamer<XYZ> PositionXYZStream() const { return ConstStreamer<XYZ>(*this); }
    Streamer<XYZO> PositionXYZOStream() { return Streamer<XYZO>(*this); }
    ConstStreamer<XYZO> PositionXYZOStream() const { return ConstStreamer<XYZO>(*this); }
    Streamer<PackedXYZ> PositionPackedXYZStream() { return Streamer<PackedXYZ>(*this); }
    ConstStreamer<PackedXYZ> PositionPackedXYZStream() const { return ConstStreamer<PackedXYZ>(*this); }

    bool IsPositionValid() const;

    float GetExactDist2dSq(const float x, const float y) const
    {
        float dx = x - m_positionX;
        float dy = y - m_positionY;
        return dx*dx + dy*dy;
    }
    float GetExactDist2dSq(Position const& pos) const { return GetExactDist2dSq(pos.m_positionX, pos.m_positionY); }
    float GetExactDist2dSq(Position const* pos) const { return GetExactDist2dSq(*pos); }

    float GetExactDist2d(const float x, const float y) const { return std::sqrt(GetExactDist2dSq(x, y)); }
    float GetExactDist2d(Position const& pos) const { return GetExactDist2d(pos.m_positionX, pos.m_positionY); }
    float GetExactDist2d(Position const* pos) const { return GetExactDist2d(*pos); }

    float GetExactDistSq(float x, float y, float z) const
    {
        float dz = z - m_positionZ;
        return GetExactDist2dSq(x, y) + dz*dz;
    }
    float GetExactDistSq(Position const& pos) const { return GetExactDistSq(pos.m_positionX, pos.m_positionY, pos.m_positionZ); }
    float GetExactDistSq(Position const* pos) const { return GetExactDistSq(*pos); }

    float GetExactDist(float x, float y, float z) const { return std::sqrt(GetExactDistSq(x, y, z)); }
    float GetExactDist(Position const& pos) const { return GetExactDist(pos.m_positionX, pos.m_positionY, pos.m_positionZ); }
    float GetExactDist(Position const* pos) const { return GetExactDist(*pos); }

    void GetPositionOffsetTo(Position const & endPos, Position & retOffset) const;
    Position GetPositionWithOffset(Position const& offset) const;

    float GetAbsoluteAngle(float x, float y) const
    {
        float dx = x - m_positionX;
        float dy = y - m_positionY;
        return NormalizeOrientation(std::atan2(dy, dx));
    }
    float GetAbsoluteAngle(Position const& pos) const { return GetAbsoluteAngle(pos.m_positionX, pos.m_positionY); }
    float GetAbsoluteAngle(Position const* pos) const { return GetAbsoluteAngle(*pos); }
    float ToAbsoluteAngle(float relAngle) const { return NormalizeOrientation(relAngle + m_orientation); }

    float ToRelativeAngle(float absAngle) const { return NormalizeOrientation(absAngle - m_orientation); }
    float GetRelativeAngle(float x, float y) const { return ToRelativeAngle(GetAbsoluteAngle(x, y)); }
    float GetRelativeAngle(Position const& pos) const { return ToRelativeAngle(GetAbsoluteAngle(pos)); }
    float GetRelativeAngle(Position const* pos) const { return ToRelativeAngle(GetAbsoluteAngle(pos)); }

    void GetSinCos(float x, float y, float &vsin, float &vcos) const;

    bool IsInDist2d(float x, float y, float dist) const { return GetExactDist2dSq(x, y) < dist * dist; }
    bool IsInDist2d(Position const* pos, float dist) const { return GetExactDist2dSq(pos) < dist * dist; }

    bool IsInDist(float x, float y, float z, float dist) const { return GetExactDistSq(x, y, z) < dist * dist; }
    bool IsInDist(Position const& pos, float dist) const { return GetExactDistSq(pos) < dist * dist; }
    bool IsInDist(Position const* pos, float dist) const { return GetExactDistSq(pos) < dist * dist; }

    bool IsWithinBox(Position const& center, float xradius, float yradius, float zradius) const;

    // dist2d < radius && abs(dz) < height
    bool IsWithinDoubleVerticalCylinder(Position const* center, float radius, float height) const;

    bool HasInArc(float arcangle, Position const* pos, float border = 2.0f) const;
    bool HasInLine(Position const* pos, float objSize, float width) const;
    std::string ToString() const;

    // constrain arbitrary radian orientation to interval [0,2*PI)
    static float NormalizeOrientation(float o);
};

#define MAPID_INVALID 0xFFFFFFFF

class WorldLocation : public Position
{
    public:
        explicit WorldLocation(uint32 _mapId = MAPID_INVALID, float x = 0.f, float y = 0.f, float z = 0.f, float o = 0.f)
            : Position(x, y, z, o), m_mapId(_mapId) { }

        WorldLocation(uint32 mapId, Position const& position)
            : Position(position), m_mapId(mapId) { }

        void WorldRelocate(WorldLocation const& loc) { m_mapId = loc.GetMapId(); Relocate(loc); }
        void WorldRelocate(WorldLocation const* loc) { m_mapId = loc->GetMapId(); Relocate(loc); }
        void WorldRelocate(uint32 mapId, Position const& pos) { m_mapId = mapId; Relocate(pos); }
        void WorldRelocate(uint32 mapId = MAPID_INVALID, float x = 0.f, float y = 0.f, float z = 0.f, float o = 0.f)
        {
            m_mapId = mapId;
            Relocate(x, y, z, o);
        }

        WorldLocation GetWorldLocation() const
        {
            return *this;
        }

        uint32 GetMapId() const { return m_mapId; }

        uint32 m_mapId;

        std::string GetDebugInfo() const;
};

TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XY> const& streamer);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XY> const& streamer);
TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XYZ> const& streamer);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XYZ> const& streamer);
TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XYZO> const& streamer);
TC_GAME_API ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XYZO> const& streamer);
TC_GAME_API ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::PackedXYZ> const& streamer);

template <class Tag>
struct TaggedPosition
{
    TaggedPosition(float x = 0.0f, float y = 0.0f, float z = 0.0f, float o = 0.0f) : Pos(x, y, z, o) { }
    TaggedPosition(Position const& pos) : Pos(pos) { }

    TaggedPosition& operator=(Position const& pos)
    {
        Pos.Relocate(pos);
        return *this;
    }

    operator Position() const { return Pos; }

    friend ByteBuffer& operator<<(ByteBuffer& buf, TaggedPosition const& tagged) { return buf << Position::ConstStreamer<Tag>(tagged.Pos); }
    friend ByteBuffer& operator>>(ByteBuffer& buf, TaggedPosition& tagged) { return buf >> Position::Streamer<Tag>(tagged.Pos); }

    Position Pos;
};

#endif // Trinity_game_Position_h__
