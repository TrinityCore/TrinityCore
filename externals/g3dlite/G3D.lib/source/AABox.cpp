/**
  @file AABox.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2004-01-10
  @edited  2006-01-11
*/

#include "G3D/platform.h"
#include "G3D/AABox.h"
#include "G3D/Box.h"
#include "G3D/Plane.h"
#include "G3D/Sphere.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"


namespace G3D {


void AABox::serialize(class BinaryOutput& b) const {
    b.writeVector3(lo);
    b.writeVector3(hi);
}


void AABox::deserialize(class BinaryInput& b) {
    lo = b.readVector3();
    hi = b.readVector3();
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


Vector3 AABox::randomSurfacePoint() const {
    Vector3 extent = hi - lo;
    float aXY = extent.x * extent.y;
    float aYZ = extent.y * extent.z;
    float aZX = extent.z * extent.x;

    float r = (float)uniformRandom(0.0f, aXY + aYZ + aZX);

    // Choose evenly between positive and negative face planes
    float d = ((float)uniformRandom(0, 1) < 0.5f) ? 0.0f : 1.0f;

    // The probability of choosing a given face is proportional to
    // its area.
    if (r < aXY) {
        return 
            lo + 
            Vector3(
                (float)uniformRandom(0.0f, extent.x),
                (float)uniformRandom(0.0f, extent.y),
                d * extent.z);
    } else if (r < aYZ) {
        return 
            lo + 
            Vector3(
                d * extent.x,
                (float)uniformRandom(0, extent.y),
                (float)uniformRandom(0, extent.z));
    } else {
        return 
            lo + 
            Vector3(
                (float)uniformRandom(0, extent.x),
                d * extent.y,
                (float)uniformRandom(0, extent.z));
    }
}


Vector3 AABox::randomInteriorPoint() const {
    return Vector3(
        (float)uniformRandom(lo.x, hi.x), 
        (float)uniformRandom(lo.y, hi.y), 
        (float)uniformRandom(lo.z, hi.z));
}


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

int AABox::dummy = 0;


bool AABox::culledBy(
    const Array<Plane>&	plane,
	int&				cullingPlane,
	const uint32		_inMask,
    uint32&             childMask) const {

	uint32 inMask = _inMask;
	assert(plane.size() < 31);

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
    for (int p = 0; p < plane.size(); ++p) {

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
    const Array<Plane>& plane,
	int&				cullingPlane,
	const uint32		_inMask) const {

	uint32 inMask = _inMask;
	assert(plane.size() < 31);
    
    const bool finite = 
        (abs(lo.x) < G3D::inf()) &&
        (abs(hi.x) < G3D::inf()) &&
        (abs(lo.y) < G3D::inf()) &&
        (abs(hi.y) < G3D::inf()) &&
        (abs(lo.z) < G3D::inf()) &&
        (abs(hi.z) < G3D::inf());

    // See if there is one plane for which all of the
	// vertices are in the negative half space.
    for (int p = 0; p < plane.size(); ++p) {

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

Vector3 AABox::corner(int index) const {

    // default constructor inits all components to 0
    Vector3 v;

    switch (index)
    {
    case 0:
        v.x = lo.x;
        v.y = lo.y;
        v.z = hi.z;
        break;

    case 1:
        v.x = hi.x;
        v.y = lo.y;
        v.z = hi.z;
        break;

    case 2:
        v.x = hi.x;
        v.y = hi.y;
        v.z = hi.z;
        break;

    case 3:
        v.x = lo.x;
        v.y = hi.y;
        v.z = hi.z;
        break;

    case 4:
        v.x = lo.x;
        v.y = lo.y;
        v.z = lo.z;
        break;

    case 5:
        v.x = hi.x;
        v.y = lo.y;
        v.z = lo.z;
        break;

    case 6:
        v.x = hi.x;
        v.y = hi.y;
        v.z = lo.z;
        break;

    case 7:
        v.x = lo.x;
        v.y = hi.y;
        v.z = lo.z;
        break;

    default:
        debugAssertM(false, "Invalid corner index");
        break;
    }

    return v;
}


}
