/**
   \file G3D.lib/source/Sphere.cpp
 
 Sphere class
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2001-04-17
 \edited  2011-02-10
 */

#include "G3D/platform.h"
#include "G3D/Sphere.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/AABox.h"
#include "G3D/Plane.h"
#include "G3D/Any.h"

namespace G3D {

int32 Sphere::dummy;

Sphere::Sphere(const Any& a) : radius(0) {
    a.verifyName("Sphere");
    a.verifyType(Any::ARRAY);
    if (a.size() == 1) {
        radius = a[0];
    } else if (a.size() == 2) {
        center = a[0];
        radius = a[1];
    } else {
        a.verify(false, "Sphere must recieve exactly 1 or two arguments.");
    }
}


Any Sphere::toAny() const {
    Any a(Any::ARRAY, "Sphere");
    if (center != Point3::zero()) {
        a.append(center);
    }

    a.append(radius);
    return a;
}


Sphere::Sphere(class BinaryInput& b) {
    deserialize(b);
}


void Sphere::serialize(class BinaryOutput& b) const {
    center.serialize(b);
    b.writeFloat64(radius);
}


void Sphere::deserialize(class BinaryInput& b) {
    center.deserialize(b);
    radius = (float)b.readFloat64();
}


const Sphere& Sphere::inf() {
    static const Sphere s(Point3::zero(), finf());
    return s;
}


std::string Sphere::toString() const {
    return format("Sphere(<%g, %g, %g>, %g)", 
                  center.x, center.y, center.z, radius);
}


bool Sphere::contains(const Vector3& point) const {
    float distance = (center - point).squaredMagnitude();
    return distance <= square(radius);
}


bool Sphere::contains(const Sphere& other) const {
    float distance = (center - other.center).squaredMagnitude();
    return (radius >= other.radius) && (distance <= square(radius - other.radius));
}


bool Sphere::intersects(const Sphere& other) const {
    return (other.center - center).length() <= (radius + other.radius);
}


void Sphere::merge(const Sphere& other) {
    if (other.contains(*this)) {
        *this = other;
    } else if (! contains(other)) {
        // The farthest distance is along the axis between the centers, which
        // must not be colocated since neither contains the other.
        Vector3 toMe = center - other.center;
        // Get a point on the axis from each
        toMe = toMe.direction();
        const Vector3& A = center + toMe * radius;
        const Vector3& B = other.center - toMe * other.radius;

        // Now just bound the A->B segment
        center = (A + B) * 0.5f;
        radius = (A - B).length();
    }
    // (if this contains other, we're done)
}


bool Sphere::culledBy(
    const Array<Plane>&        plane,
    int&                    cullingPlaneIndex,
    const uint32            inMask,
    uint32&                    outMask) const {
    
    return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask, outMask);
}
    

bool Sphere::culledBy(
                      const Array<Plane>&        plane,
                      int&                    cullingPlaneIndex,
                      const uint32            inMask) const {
    
    return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask);
}


bool Sphere::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
    int&                cullingPlane,
    const uint32        _inMask,
    uint32&             childMask) const {

    if (radius == finf()) {
        // No plane can cull the infinite box
        return false;
    }

    uint32 inMask = _inMask;
    assert(numPlanes < 31);

    childMask = 0;

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < numPlanes; ++p) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {
        
            bool culledLow = ! plane[p].halfSpaceContainsFinite(center + plane[p].normal() * radius);
            bool culledHigh = ! plane[p].halfSpaceContainsFinite(center - plane[p].normal() * radius);

            if (culledLow) {
                // Plane p culled the sphere
                cullingPlane = p;

                // The caller should not recurse into the children,
                // since the parent is culled.  If they do recurse,
                // make them only test against this one plane, which
                // will immediately cull the volume.
                childMask = 1 << p;
                return true;

            } else if (culledHigh) {
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


bool Sphere::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
    int&                cullingPlane,
    const uint32        _inMask) const {
    // Don't cull if the sphere has infinite radius
    if(!isFinite(radius)) return false;

    uint32 inMask = _inMask;
    assert(numPlanes < 31);

    // See if there is one plane for which all of the
    // vertices are in the negative half space.
    for (int p = 0; p < numPlanes; ++p) {

        // Only test planes that are not masked
        if ((inMask & 1) != 0) {
            bool culled = ! plane[p].halfSpaceContains(center + plane[p].normal() * radius);
            if (culled) {
                // Plane p culled the sphere
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


Vector3 Sphere::randomSurfacePoint() const {
    return Vector3::random() * radius + center;
}


Vector3 Sphere::randomInteriorPoint() const {
    Vector3 result;
    do {
        result = Vector3(uniformRandom(-1, 1), 
                         uniformRandom(-1, 1), 
                         uniformRandom(-1, 1));
    } while (result.squaredMagnitude() >= 1.0f);

    return result * radius + center;
}


float Sphere::volume() const {
    return (float)pi() * (4.0f / 3.0f) * powf((float)radius, 3.0f);
}


float Sphere::area() const {
    return (float)pi() * 4.0f * powf((float)radius, 2.0f);
}


void Sphere::getBounds(AABox& out) const {
    Vector3 extent(radius, radius, radius);
    out = AABox(center - extent, center + extent);
}

} // namespace
