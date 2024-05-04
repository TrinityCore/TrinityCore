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

#include "Position.h"
#include "ByteBuffer.h"
#include "DB2Stores.h"
#include "GridDefines.h"
#include "World.h"
#include <G3D/g3dmath.h>
#include <sstream>

bool Position::operator==(Position const& a) const
{
    return (G3D::fuzzyEq(a.m_positionX, m_positionX) &&
        G3D::fuzzyEq(a.m_positionY, m_positionY) &&
        G3D::fuzzyEq(a.m_positionZ, m_positionZ) &&
        G3D::fuzzyEq(a.m_orientation, m_orientation));
}

void Position::RelocateOffset(Position const& offset)
{
    m_positionX = GetPositionX() + (offset.GetPositionX() * std::cos(GetOrientation()) + offset.GetPositionY() * std::sin(GetOrientation() + float(M_PI)));
    m_positionY = GetPositionY() + (offset.GetPositionY() * std::cos(GetOrientation()) + offset.GetPositionX() * std::sin(GetOrientation()));
    m_positionZ = GetPositionZ() + offset.GetPositionZ();
    SetOrientation(GetOrientation() + offset.GetOrientation());
}

bool Position::IsPositionValid() const
{
    return Trinity::IsValidMapCoord(m_positionX, m_positionY, m_positionZ, m_orientation);
}

void Position::GetPositionOffsetTo(Position const& endPos, Position& retOffset) const
{
    float dx = endPos.GetPositionX() - GetPositionX();
    float dy = endPos.GetPositionY() - GetPositionY();

    retOffset.m_positionX = dx * std::cos(GetOrientation()) + dy * std::sin(GetOrientation());
    retOffset.m_positionY = dy * std::cos(GetOrientation()) - dx * std::sin(GetOrientation());
    retOffset.m_positionZ = endPos.GetPositionZ() - GetPositionZ();
    retOffset.SetOrientation(endPos.GetOrientation() - GetOrientation());
}

Position Position::GetPositionWithOffset(Position const& offset) const
{
    Position ret(*this);
    ret.RelocateOffset(offset);
    return ret;
}

bool Position::IsWithinBox(Position const& boxOrigin, float length, float width, float height) const
{
    // rotate the WorldObject position instead of rotating the whole cube, that way we can make a simplified
    // is-in-cube check and we have to calculate only one point instead of 4

    // 2PI = 360*, keep in mind that ingame orientation is counter-clockwise
    double rotation = 2 * M_PI - boxOrigin.GetOrientation();
    double sinVal = std::sin(rotation);
    double cosVal = std::cos(rotation);

    float BoxDistX = GetPositionX() - boxOrigin.GetPositionX();
    float BoxDistY = GetPositionY() - boxOrigin.GetPositionY();

    float rotX = float(boxOrigin.GetPositionX() + BoxDistX * cosVal - BoxDistY * sinVal);
    float rotY = float(boxOrigin.GetPositionY() + BoxDistY * cosVal + BoxDistX * sinVal);

    // box edges are parallel to coordiante axis, so we can treat every dimension independently :D
    float dz = GetPositionZ() - boxOrigin.GetPositionZ();
    float dx = rotX - boxOrigin.GetPositionX();
    float dy = rotY - boxOrigin.GetPositionY();
    if ((std::fabs(dx) > length) ||
        (std::fabs(dy) > width)  ||
        (std::fabs(dz) > height))
        return false;

    return true;
}

bool Position::IsWithinVerticalCylinder(Position const& cylinderOrigin, float radius, float height, bool isDoubleVertical) const
{
    float verticalDelta = GetPositionZ() - cylinderOrigin.GetPositionZ();
    bool isValidPositionZ = isDoubleVertical ? std::abs(verticalDelta) <= height : 0 <= verticalDelta && verticalDelta <= height;

    return isValidPositionZ && IsInDist2d(cylinderOrigin, radius);
}

bool Position::IsInPolygon2D(Position const& polygonOrigin, std::span<Position const> vertices) const
{
    float testX = GetPositionX();
    float testY = GetPositionY();

    //this method uses the ray tracing algorithm to determine if the point is in the polygon
    bool locatedInPolygon = false;

    for (std::size_t vertex = 0; vertex < vertices.size(); ++vertex)
    {
        std::size_t nextVertex;

        //repeat loop for all sets of points
        if (vertex == (vertices.size() - 1))
        {
            //if i is the last vertex, let j be the first vertex
            nextVertex = 0;
        }
        else
        {
            //for all-else, let j=(i+1)th vertex
            nextVertex = vertex + 1;
        }

        float vertX_i = polygonOrigin.GetPositionX() + vertices[vertex].GetPositionX();
        float vertY_i = polygonOrigin.GetPositionY() + vertices[vertex].GetPositionY();
        float vertX_j = polygonOrigin.GetPositionX() + vertices[nextVertex].GetPositionX();
        float vertY_j = polygonOrigin.GetPositionY() + vertices[nextVertex].GetPositionY();

        // following statement checks if testPoint.Y is below Y-coord of i-th vertex
        bool belowLowY = vertY_i > testY;
        // following statement checks if testPoint.Y is below Y-coord of i+1-th vertex
        bool belowHighY = vertY_j > testY;

        /* following statement is true if testPoint.Y satisfies either (only one is possible)
        -->(i).Y < testPoint.Y < (i+1).Y        OR
        -->(i).Y > testPoint.Y > (i+1).Y

        (Note)
        Both of the conditions indicate that a point is located within the edges of the Y-th coordinate
        of the (i)-th and the (i+1)- th vertices of the polygon. If neither of the above
        conditions is satisfied, then it is assured that a semi-infinite horizontal line draw
        to the right from the testpoint will NOT cross the line that connects vertices i and i+1
        of the polygon
        */
        bool withinYsEdges = belowLowY != belowHighY;

        if (withinYsEdges)
        {
            // this is the slope of the line that connects vertices i and i+1 of the polygon
            float slopeOfLine = (vertX_j - vertX_i) / (vertY_j - vertY_i);

            // this looks up the x-coord of a point lying on the above line, given its y-coord
            float pointOnLine = (slopeOfLine * (testY - vertY_i)) + vertX_i;

            //checks to see if x-coord of testPoint is smaller than the point on the line with the same y-coord
            bool isLeftToLine = testX < pointOnLine;

            if (isLeftToLine)
            {
                //this statement changes true to false (and vice-versa)
                locatedInPolygon = !locatedInPolygon;
            }//end if (isLeftToLine)
        }//end if (withinYsEdges
    }

    return locatedInPolygon;
}

bool Position::HasInArc(float arc, Position const* obj, float border) const
{
    // always have self in arc
    if (obj == this)
        return true;

    // move arc to range 0.. 2*pi
    arc = NormalizeOrientation(arc);

    // move angle to range -pi ... +pi
    float angle = GetRelativeAngle(obj);
    if (angle > float(M_PI))
        angle -= 2.0f * float(M_PI);

    float lborder = -1 * (arc / border);                        // in range -pi..0
    float rborder = (arc / border);                             // in range 0..pi
    return ((angle >= lborder) && (angle <= rborder));
}

bool Position::HasInLine(Position const* pos, float objSize, float width) const
{
    if (!HasInArc(float(M_PI), pos, 2.0f))
        return false;

    width += objSize;
    float angle = GetRelativeAngle(pos);
    return std::fabs(std::sin(angle)) * GetExactDist2d(pos->GetPositionX(), pos->GetPositionY()) < width;
}

std::string Position::ToString() const
{
    std::stringstream sstr;
    sstr << "X: " << m_positionX << " Y: " << m_positionY << " Z: " << m_positionZ << " O: " << m_orientation;
    return sstr.str();
}

float Position::NormalizeOrientation(float o)
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

ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XY> const& streamer)
{
    buf << streamer.Pos->GetPositionX();
    buf << streamer.Pos->GetPositionY();
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XY> const& streamer)
{
    float x, y;
    buf >> x >> y;
    streamer.Pos->Relocate(x, y);
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XYZ> const& streamer)
{
    buf << streamer.Pos->GetPositionX();
    buf << streamer.Pos->GetPositionY();
    buf << streamer.Pos->GetPositionZ();
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XYZ> const& streamer)
{
    float x, y, z;
    buf >> x >> y >> z;
    streamer.Pos->Relocate(x, y, z);
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::XYZO> const& streamer)
{
    buf << streamer.Pos->GetPositionX();
    buf << streamer.Pos->GetPositionY();
    buf << streamer.Pos->GetPositionZ();
    buf << streamer.Pos->GetOrientation();
    return buf;
}

ByteBuffer& operator>>(ByteBuffer& buf, Position::Streamer<Position::XYZO> const& streamer)
{
    float x, y, z, o;
    buf >> x >> y >> z >> o;
    streamer.Pos->Relocate(x, y, z, o);
    return buf;
}

ByteBuffer& operator<<(ByteBuffer& buf, Position::ConstStreamer<Position::PackedXYZ> const& streamer)
{
    buf.appendPackXYZ(streamer.Pos->GetPositionX(), streamer.Pos->GetPositionY(), streamer.Pos->GetPositionZ());
    return buf;
}

std::string WorldLocation::GetDebugInfo() const
{
    std::stringstream sstr;
    MapEntry const* mapEntry = sMapStore.LookupEntry(m_mapId);
    sstr << "MapID: " << m_mapId << " Map name: '" << (mapEntry ? mapEntry->MapName[sWorld->GetDefaultDbcLocale()] : "<not found>") <<"' " << Position::ToString();
    return sstr.str();
}
