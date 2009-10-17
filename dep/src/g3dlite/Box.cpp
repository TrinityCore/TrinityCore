/**
  @file Box.cpp
  Box class

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-06-02
  @edited  2006-02-05
*/

#include "G3D/Box.h"
#include "G3D/debug.h"
#include "G3D/Plane.h"
#include "G3D/AABox.h"
#include "G3D/CoordinateFrame.h"

namespace G3D {

/**
 Sets a field on four vertices.  Used by the constructor.
 */
#define setMany(i0, i1, i2, i3, field, extreme) \
    _corner[i0].field = _corner[i1].field = \
    _corner[i2].field = _corner[i3].field = \
    (extreme).field

Box::Box() {
}


Box::Box(const AABox& b) {
    init(b.low(), b.high());
}


Box::Box(
    const Vector3& min,
    const Vector3& max) {

    init(min.min(max), min.max(max));

}

void Box::init(
    const Vector3& min,
    const Vector3& max) {

    setMany(0, 1, 2, 3, z, max);
    setMany(4, 5, 6, 7, z, min);

    setMany(1, 2, 5, 6, x, max);
    setMany(0, 3, 4, 7, x, min);

    setMany(3, 2, 6, 7, y, max);
    setMany(0, 1, 5, 4, y, min);

    _extent = max - min;

    _axis[0] = Vector3::unitX();
    _axis[1] = Vector3::unitY();
    _axis[2] = Vector3::unitZ();

    _volume = _extent.x * _extent.y * _extent.z;
    _area = 2 * 
        (_extent.x * _extent.y +
         _extent.y * _extent.z +
         _extent.z * _extent.x);

    _center = (max + min) / 2;
}


float Box::volume() const {
    return _volume;
}


float Box::surfaceArea() const {
    return _area;
}


void Box::getLocalFrame(CoordinateFrame& frame) const {

    frame.rotation = Matrix3(
        _axis[0][0], _axis[1][0], _axis[2][0],
        _axis[0][1], _axis[1][1], _axis[2][1],
        _axis[0][2], _axis[1][2], _axis[2][2]);

    frame.translation = _center;
}


CoordinateFrame Box::localFrame() const {
    CoordinateFrame out;
    getLocalFrame(out);
    return out;
}


void Box::getFaceCorners(int f, Vector3& v0, Vector3& v1, Vector3& v2, Vector3& v3) const {
    switch (f) {
    case 0:
        v0 = _corner[0]; v1 = _corner[1]; v2 = _corner[2]; v3 = _corner[3];
        break;

    case 1:
        v0 = _corner[1]; v1 = _corner[5]; v2 = _corner[6]; v3 = _corner[2];
        break;

    case 2:
        v0 = _corner[7]; v1 = _corner[6]; v2 = _corner[5]; v3 = _corner[4];
        break;

    case 3:
        v0 = _corner[2]; v1 = _corner[6]; v2 = _corner[7]; v3 = _corner[3];
        break;

    case 4:
        v0 = _corner[3]; v1 = _corner[7]; v2 = _corner[4]; v3 = _corner[0];
        break;

    case 5:
        v0 = _corner[1]; v1 = _corner[0]; v2 = _corner[4]; v3 = _corner[5];
        break;

    default:
        debugAssert((f >= 0) && (f < 6));
    }
}


bool Box::culledBy(
    const Array<Plane>&        plane,
    int&                    cullingPlaneIndex,
    const uint32            inMask,
    uint32&                    outMask) const {

    return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask, outMask);
}


bool Box::culledBy(
    const Array<Plane>&        plane,
    int&                    cullingPlaneIndex,
    const uint32            inMask) const {

    return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask);
}


int32 Box::dummy = 0;

bool Box::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
    int&                cullingPlane,
    const uint32        _inMask,
    uint32&             childMask) const {

    uint32 inMask = _inMask;
    assert(numPlanes < 31);

    childMask = 0;

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < numPlanes; p++) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {
        
            Vector3 corner;

            int numContained = 0;
            int v = 0;

            // We can early-out only if we have found one point on each
            // side of the plane (i.e. if we are straddling).  That
            // occurs when (numContained < v) && (numContained > 0)
            for (v = 0; (v < 8) && ((numContained == v) || (numContained == 0)); ++v) {
                if (plane[p].halfSpaceContains(getCorner(v))) {
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


bool Box::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
    int&                cullingPlane,
    const uint32        _inMask) const {

    uint32 inMask = _inMask;
    assert(numPlanes < 31);

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < numPlanes; p++) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {
        
            bool culled = true;

            int v;

            // Assume this plane culls all points.  See if there is a point
            // not culled by the plane... early out when at least one point
            // is in the positive half space.
            for (v = 0; (v < 8) && culled; ++v) {
                culled = ! plane[p].halfSpaceContains(getCorner(v));
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


bool Box::contains(
    const Vector3&      point) const {

    // Form axes from three edges, transform the point into that
    // space, and perform 3 interval tests

    Vector3 u = _corner[4] - _corner[0];
    Vector3 v = _corner[3] - _corner[0];
    Vector3 w = _corner[1] - _corner[0];

    Matrix3 M = Matrix3(u.x, v.x, w.x,
                        u.y, v.y, w.y,
                        u.z, v.z, w.z);

    // M^-1 * (point - _corner[0]) = point in unit cube's object space
    // compute the inverse of M
    Vector3 osPoint = M.inverse() * (point - _corner[0]);

    return
        (osPoint.x >= 0) && 
        (osPoint.y >= 0) &&
        (osPoint.z >= 0) &&
        (osPoint.x <= 1) &&
        (osPoint.y <= 1) &&
        (osPoint.z <= 1);
}

#undef setMany

#if 0
void Box::getRandomSurfacePoint(Vector3& P, Vector3& N) const {
    float aXY = _extent.x * _extent.y;
    float aYZ = _extent.y * _extent.z;
    float aZX = _extent.z * _extent.x;

    float r = (float)random(0, aXY + aYZ + aZX);

    // Choose evenly between positive and negative face planes
    float d = (random(0, 1) < 0.5f) ? -1.0f : 1.0f;

    // The probability of choosing a given face is proportional to
    // its area.
    if (r < aXY) {
        P = _axis[0] * (float)random(-0.5, 0.5) * _extent.x +
            _axis[1] * (float)random(-0.5, 0.5) * _extent.y +
            _center + _axis[2] * d * _extent.z * 0.5f;
        N = _axis[2] * d;
    } else if (r < aYZ) {
        P = _axis[1] * (float)random(-0.5, 0.5) * _extent.y +
            _axis[2] * (float)random(-0.5, 0.5) * _extent.z +
            _center + _axis[0] * d * _extent.x * 0.5f;
        N = _axis[0] * d;
    } else {
        P = _axis[2] * (float)random(-0.5, 0.5) * _extent.z +
            _axis[0] *(float) random(-0.5, 0.5) * _extent.x +
            _center + _axis[1] * d * _extent.y * 0.5f;
        N = _axis[1] * d;
    }
}


Vector3 Box::randomInteriorPoint() const {
    Vector3 sum = _center;

    for (int a = 0; a < 3; ++a) {
        sum += _axis[a] * (float)random(-0.5, 0.5) * _extent[a];
    }

    return sum;
}
#endif


void Box::getBounds(class AABox& aabb) const {

    Vector3 lo = _corner[0];
    Vector3 hi = lo;

    for (int v = 1; v < 8; ++v) {
        const Vector3& C = _corner[v];
        lo = lo.min(C);
        hi = hi.max(C);
    }

    aabb = AABox(lo, hi);
}


} // namespace

