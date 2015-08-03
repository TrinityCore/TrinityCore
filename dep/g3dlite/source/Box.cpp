/**
  \file G3D.lib/source/Box.cpp
  Box class

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu, Michael Mara

  \created 2001-06-02
  \edited  2013-04-13
*/

#include "G3D/Box.h"
#include "G3D/debug.h"
#include "G3D/Plane.h"
#include "G3D/AABox.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/vectorMath.h"
#include "G3D/Any.h"

namespace G3D {

Box::Box() : _area(0), _volume(0) {
}


Box::Box
   (const Point3& min,
    const Point3& max) {
    init(min.min(max), min.max(max));
}


Box::Box(const Point3& min) {
    init(min, min);
}


Box::Box
   (const Point3& min,
    const Point3& max,
    const CFrame& c) {
    init(min.min(max), min.max(max));
    *this = c.toWorldSpace(*this);
}


Box::Box(const AABox& b) {
    debugAssert(! b.isEmpty());
    init(b.low(), b.high());
}


Box::Box(BinaryInput& b) {
    deserialize(b);    
}


Box::Box(const Any& a) {
    if (a.name() == "Box::inf") {
        *this = Box::inf();
    } else {
        a.verifyName("Box", "AABox", "Point3");

        if (a.name() == "Point3") {
            *this = Box(Point3(a));
        } else if (a.size() == 1) {
            // Single point
            *this = Box(Point3(a[0]));
        } else if (a.size() == 2) {
            *this = Box(Point3(a[0]), Point3(a[1]));
        } else {
            // Oriented box
            a.verifySize(2);
            a.verifyName("Box");
            *this = Box(Point3(a[0]), Point3(a[1]), CFrame(a[2]));
        }
    }
}


Any Box::toAny() const {
    if (! isFinite()) {
        return Any(Any::ARRAY, "Box::inf");
    } else {
        CFrame c;
        getLocalFrame(c);
        if (c.rotation == Matrix3::identity()) {
            // Aligned box
            AABox b;
            getBounds(b);
            return b.toAny();
        } else {
            // Oriented box
            Any a(Any::ARRAY, "Box");

            AABox b;
            c.toObjectSpace(*this).getBounds(b);
            a.append(b.low(), b.high(), c);
            return a;
        }
    }
}


Box Box::operator*(float f) const {
    Box b;

    for (int i = 0; i < 3; ++i) {
        b._edgeVector[i] = _edgeVector[i] * f;
        b._center = _center * f;
        b._area = _area * square(f * f);
        b._volume = _area * (f * f * f);
    }

    return b;
}


void Box::serialize(BinaryOutput& b) const {
    int i;
    for (i = 0; i < 3; ++i) {
        _edgeVector[i].serialize(b);
    }
    _center.serialize(b);

    // Other state can be reconstructed
}


void Box::deserialize(class BinaryInput& b) {
    int i;
    for (i = 0; i < 3; ++i) {
        _edgeVector[i].deserialize(b);
    }
    _center.deserialize(b);

    float extent0 = extent(0);
    float extent1 = extent(1);
    float extent2 = extent(2);
    _volume = extent0 * extent1 * extent2;

    _area = 2 * 
        (extent0 * extent1 +
         extent1 * extent2 +
         extent2 * extent0);
}


void Box::init
   (const Point3& min,
    const Point3& max) {

    debugAssert(
        (min.x <= max.x) &&
        (min.y <= max.y) &&
        (min.z <= max.z));

    _center = (max + min) * 0.5f;

    Vector3 bounds = Vector3(max.x - min.x, max.y - min.y, max.z - min.z);
    _edgeVector[0] = Vector3(bounds.x, 0, 0);
    _edgeVector[1] = Vector3(0, bounds.y, 0);
    _edgeVector[2] = Vector3(0, 0, bounds.z);
    bool finiteExtent = true;
    
    for (int i = 0; i < 3; ++i) {
        if (! G3D::isFinite(extent(i))) {
            finiteExtent = false;
            // If the extent is infinite along an axis, make the center zero to avoid NaNs
            _center[i] = 0.0f;
        }
    }


    if (finiteExtent) {
        _volume = bounds.x * bounds.y * bounds.z;
    } else {
        _volume = G3D::finf();
    }

    debugAssert(! _edgeVector[0].isNaN());

    _area = 2 * 
        (bounds.x * bounds.y +
         bounds.y * bounds.z +
         bounds.z * bounds.x);
}


Vector3 Box::corner(int i) const{
    debugAssert(i < 8);
    // The corner forms a bit mask (xyz), where a one indicates we should
    // add half of the corresponding edge vector from center, and a zero indicates 
    // we should subtract it. Note:
    // 1 = 001
    // 2 = 010
    // 4 = 100
    // 
    // The following bit-hacky code shows this directly:
    // return _center + ((_edgeVector[0] * ((i&1) - 0.5) +
    //                  _edgeVector[1] * (((i>>1)&1) - 0.5) +
    //                  _edgeVector[2] * (((i>>2)&1) - 0.5)));
    // This method is implemented as a swtich statement due to being marginally faster than the bit-hack method
    // Also, the _center + 0.5f * (...) is repeated every time for similarly speed-based reasons.
    switch(i) {
        case 0:  return _center + (0.5f * (-_edgeVector[0]  - _edgeVector[1] - _edgeVector[2]));
        case 1:  return _center + (0.5f * ( _edgeVector[0]  - _edgeVector[1] - _edgeVector[2]));
        case 2:  return _center + (0.5f * (-_edgeVector[0]  + _edgeVector[1] - _edgeVector[2]));
        case 3:  return _center + (0.5f * ( _edgeVector[0]  + _edgeVector[1] - _edgeVector[2]));
        case 4:  return _center + (0.5f * (-_edgeVector[0]  - _edgeVector[1] + _edgeVector[2]));
        case 5:  return _center + (0.5f * ( _edgeVector[0]  - _edgeVector[1] + _edgeVector[2]));
        case 6:  return _center + (0.5f * (-_edgeVector[0]  + _edgeVector[1] + _edgeVector[2]));
        default: return _center + (0.5f * ( _edgeVector[0]  + _edgeVector[1] + _edgeVector[2]));//case 7
    }
        
}

float Box::volume() const {
    return _volume;
}


float Box::area() const {
    return _area;
}


void Box::getLocalFrame(CoordinateFrame& frame) const {
    const Vector3& axis0 = axis(0);
    const Vector3& axis1 = axis(1);
    const Vector3& axis2 = axis(2);

    frame.rotation = Matrix3(
        axis0[0], axis1[0], axis2[0],
        axis0[1], axis1[1], axis2[1],
        axis0[2], axis1[2], axis2[2]);

    frame.translation = _center;
}


CoordinateFrame Box::localFrame() const {
    CoordinateFrame out;
    getLocalFrame(out);
    return out;
}


void Box::getFaceCorners(int f, Point3& v0, Point3& v1, Point3& v2, Point3& v3) const {
    switch (f) {
    case 0:
        v0 = corner(0); v1 = corner(2); v2 = corner(3); v3 = corner(1);
        break;

    case 1:
        v0 = corner(1); v1 = corner(3); v2 = corner(7); v3 = corner(5);
        break;

    case 2:
        v0 = corner(6); v1 = corner(4); v2 = corner(5); v3 = corner(7);
        break;

    case 3:
        v0 = corner(3); v1 = corner(2); v2 = corner(6); v3 = corner(7);
        break;

    case 4:
        v0 = corner(2); v1 = corner(0); v2 = corner(4); v3 = corner(6);
        break;

    case 5:
        v0 = corner(1); v1 = corner(5); v2 = corner(4); v3 = corner(0);
        break;

    default:
        debugAssert((f >= 0) && (f < 6));
    }
}



int Box::dummy = 0;

bool Box::culledBy
   (const Array<Plane>& plane,
    int&                cullingPlane,
    const uint32        _inMask,
    uint32&             childMask) const {

    uint32 inMask = _inMask;
    assert(plane.size() < 31);

    childMask = 0;

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < plane.size(); ++p) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {

            int numContained = 0;
            int v = 0;

            // We can early-out only if we have found one point on each
            // side of the plane (i.e. if we are straddling).  That
            // occurs when (numContained < v) && (numContained > 0)
            for (v = 0; (v < 8) && ((numContained == v) || (numContained == 0)); ++v) {
                if (plane[p].halfSpaceContains(corner(v))) {
                    ++numContained;
                }
            }

            if (numContained == 0) {
                // Plane p culled the box
                cullingPlane = p;

                // The caller should not recurse into the children,
                // since the parent is culled.  If they do recurse,
                // make them only test against this one plane, which
                // will immediately cull the volume.
                childMask = 1 << p;
                return true;

            } else if (numContained < v) {
                // The bounding volume straddled the plane; we have
                // to keep testing against this plane
                childMask |= (1 << p);
            }
        }

        // Move on to the next bit.
        inMask = inMask >> 1;
    }

    // None of the planes could cull this box
    cullingPlane = -1;
    return false;
}


bool Box::culledBy
   (const Array<Plane>& plane,
    int&                cullingPlane,
    const uint32        _inMask) const {

    uint32 inMask = _inMask;
    assert(plane.size() < 31);

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < plane.size(); ++p) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {
        
            bool culled = true;

            int v;

            // Assume this plane culls all points.  See if there is a point
            // not culled by the plane... early out when at least one point
            // is in the positive half space.
            for (v = 0; (v < 8) && culled; ++v) {
                culled = ! plane[p].halfSpaceContains(corner(v));
            }

            if (culled) {
                // Plane p culled the box
                cullingPlane = p;

                return true;
            }
        }

        // Move on to the next bit.
        inMask = inMask >> 1;
    }

    // None of the planes could cull this box
    cullingPlane = -1;
    return false;
}


bool Box::contains
    (const Point3&      point) const {

    // Form axes from three edges, transform the point into that
    // space, and perform 3 interval tests
    // TODO: Write in a more intuitive way. I left it as it was before after figuring it out, but
    // this should make no sense to someone who is just starting to read this code.
    const Vector3& u = _edgeVector[2];
    const Vector3& v = _edgeVector[1];
    const Vector3& w = _edgeVector[0];

    Matrix3 M = Matrix3(u.x, v.x, w.x,
                        u.y, v.y, w.y,
                        u.z, v.z, w.z);

    // M^-1 * (point - _corner[0]) = point in unit cube's object space
    // compute the inverse of M
    Vector3 osPoint = M.inverse() * (point - corner(0));

    return
        (osPoint.x >= 0) && 
        (osPoint.y >= 0) &&
        (osPoint.z >= 0) &&
        (osPoint.x <= 1) &&
        (osPoint.y <= 1) &&
        (osPoint.z <= 1);
}




void Box::getRandomSurfacePoint(Vector3& P, Vector3& N) const {
    float aXY = extent(0) * extent(1);
    float aYZ = extent(1) * extent(2);
    float aZX = extent(2) * extent(0);

    float r = (float)uniformRandom(0, aXY + aYZ + aZX);

    // Choose evenly between positive and negative face planes
    float d = (uniformRandom(0, 1) < 0.5f) ? -1.0f : 1.0f;

    // The probability of choosing a given face is proportional to
    // its area.
    if (r < aXY) {
        P = _edgeVector[0] * (float)uniformRandom(-0.5, 0.5) +
            _edgeVector[1] * (float)uniformRandom(-0.5, 0.5) +
            _center + _edgeVector[2] * d  * 0.5f;
        N = axis(2) * d;
    } else if (r < aYZ) {
        P = _edgeVector[1] * (float)uniformRandom(-0.5, 0.5) +
            _edgeVector[2] * (float)uniformRandom(-0.5, 0.5) +
            _center + _edgeVector[0] * d  * 0.5f;
        N = axis(0) * d;
    } else {
        P = _edgeVector[2] * (float)uniformRandom(-0.5, 0.5) +
            _edgeVector[0] *(float) uniformRandom(-0.5, 0.5) +
            _center + _edgeVector[1] * d * 0.5f;
        N = axis(1) * d;
    }
}


Vector3 Box::randomInteriorPoint() const {
    Vector3 sum = _center;

    for (int a = 0; a < 3; ++a) {
        sum += _edgeVector[a] * (float)uniformRandom(-0.5, 0.5);
    }

    return sum;
}


Box Box::inf() {
    return Box(-Vector3::inf(), Vector3::inf());
}


void Box::getBounds(AABox& aabb) const {
    debugAssert(! _edgeVector[0].isNaN());
    debugAssert(! _center.isNaN());
    aabb = AABox::empty();
    for (int i = 0; i < 8; ++i) {
        aabb.merge(corner(i));
    }
}


} // namespace
