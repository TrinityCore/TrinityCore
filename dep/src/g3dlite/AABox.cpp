/**
  @file AABox.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2004-01-10
  @edited  2006-01-11
*/

#include "G3D/platform.h"
#   if defined(_MSC_VER) && (_MSC_VER <= 1200)
        // VC6 std:: has signed/unsigned problems
#       pragma warning (disable : 4018)
#   endif

#include <assert.h>
#include "G3D/AABox.h"
#include "G3D/Box.h"
#include "G3D/Plane.h"
#include "G3D/Sphere.h"


namespace G3D {

Box AABox::toBox() const {
    return Box(lo, hi);
}



void AABox::split(const Vector3::Axis& axis, float location, AABox& low, AABox& high) const {
    // Low, medium, and high along the chosen axis
    float L = G3D::min(location, lo[axis]);
    float M = G3D::min(G3D::max(location, lo[axis]), hi[axis]);
    float H = G3D::max(location, hi[axis]);

    // Copy over this box.
    high = low = *this;

    // Now move the split points along the special axis
    low.lo[axis] = L;
    low.hi[axis] = M;
    high.lo[axis] = M;
    high.hi[axis] = H;
}

#if 0
Vector3 AABox::randomSurfacePoint() const {
    Vector3 extent = hi - lo;
    float aXY = extent.x * extent.y;
    float aYZ = extent.y * extent.z;
    float aZX = extent.z * extent.x;

    float r = (float)random(0, aXY + aYZ + aZX);

    // Choose evenly between positive and negative face planes
    float d = ((float)random(0, 1) < 0.5f) ? 0.0f : 1.0f;

    // The probability of choosing a given face is proportional to
    // its area.
    if (r < aXY) {
        return 
            lo + 
            Vector3(
                (float)random(0, extent.x),
                (float)random(0, extent.y),
                d * extent.z);
    } else if (r < aYZ) {
        return 
            lo + 
            Vector3(
                d * extent.x,
                (float)random(0, extent.y),
                (float)random(0, extent.z));
    } else {
        return 
            lo + 
            Vector3(
                (float)random(0, extent.x),
                d * extent.y,
                (float)random(0, extent.z));
    }
}


Vector3 AABox::randomInteriorPoint() const {
    return Vector3(
        (float)random(lo.x, hi.x), 
        (float)random(lo.y, hi.y), 
        (float)random(lo.z, hi.z));
}
#endif


bool AABox::intersects(const AABox& other) const {
    // Must be overlap along all three axes.
    // Try to find a separating axis.

    for (int a = 0; a < 3; ++a) {

        //     |--------|
        // |------|

        if ((lo[a] > other.hi[a]) ||
            (hi[a] < other.lo[a])) {
            return false;
        }
    }

    return true;
}


bool AABox::culledBy(
    const Array<Plane>&		plane,
	int&				    cullingPlaneIndex,
	const uint32			inMask,
	uint32&					outMask) const {

	return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask, outMask);
}


bool AABox::culledBy(
    const Array<Plane>&		plane,
	int&				    cullingPlaneIndex,
	const uint32			inMask) const {

	return culledBy(plane.getCArray(), plane.size(), cullingPlaneIndex, inMask);
}


int AABox::dummy = 0;


bool AABox::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
	int&				cullingPlane,
	const uint32		_inMask,
    uint32&             childMask) const {

	uint32 inMask = _inMask;
	assert(numPlanes < 31);

    childMask = 0;

    const bool finite = 
        (abs(lo.x) < G3D::inf()) &&
        (abs(hi.x) < G3D::inf()) &&
        (abs(lo.y) < G3D::inf()) &&
        (abs(hi.y) < G3D::inf()) &&
        (abs(lo.z) < G3D::inf()) &&
        (abs(hi.z) < G3D::inf());

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
                // Unrolling these 3 if's into a switch decreases performance
                // by about 2x
				corner.x = (v & 1) ? hi.x : lo.x;
				corner.y = (v & 2) ? hi.y : lo.y;
				corner.z = (v & 4) ? hi.z : lo.z;
        
                if (finite) { // this branch is highly predictable
                    if (plane[p].halfSpaceContainsFinite(corner)) {
                        ++numContained;
                    }
                } else {
                    if (plane[p].halfSpaceContains(corner)) {
                        ++numContained;
                    }
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


bool AABox::culledBy(
    const class Plane*  plane,
    int                 numPlanes,
	int&				cullingPlane,
	const uint32		_inMask) const {

	uint32 inMask = _inMask;
	assert(numPlanes < 31);
    
    const bool finite = 
        (abs(lo.x) < G3D::inf()) &&
        (abs(hi.x) < G3D::inf()) &&
        (abs(lo.y) < G3D::inf()) &&
        (abs(hi.y) < G3D::inf()) &&
        (abs(lo.z) < G3D::inf()) &&
        (abs(hi.z) < G3D::inf());

    // See if there is one plane for which all of the
	// vertices are in the negative half space.
    for (int p = 0; p < numPlanes; p++) {

		// Only test planes that are not masked
		if ((inMask & 1) != 0) {
		
			bool culled = true;
			Vector3 corner;

            int v;

			// Assume this plane culls all points.  See if there is a point
			// not culled by the plane... early out when at least one point
            // is in the positive half space.
			for (v = 0; (v < 8) && culled; ++v) {

                // Unrolling these 3 if's into a switch decreases performance
                // by about 2x
				corner.x = (v & 1) ? hi.x : lo.x;
				corner.y = (v & 2) ? hi.y : lo.y;
				corner.z = (v & 4) ? hi.z : lo.z;
        
                if (finite) { // this branch is highly predictable
                    culled = ! plane[p].halfSpaceContainsFinite(corner);
                } else {
                    culled = ! plane[p].halfSpaceContains(corner);
                }
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


bool AABox::intersects(const class Sphere& sphere) const {
    double d = 0; 

    //find the square of the distance
    //from the sphere to the box
    for (int i = 0; i < 3; ++i) {
        if (sphere.center[i] < lo[i]) {
            d += square(sphere.center[i] - lo[i]);
        } else if (sphere.center[i] > hi[i]) {
            d += square(sphere.center[i] - hi[i]);
        }
    }

    return d <= square(sphere.radius);
}


} // namespace
