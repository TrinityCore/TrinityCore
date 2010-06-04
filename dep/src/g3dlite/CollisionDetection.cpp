/**
  @file CollisionDetection.cpp
  
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @cite Bounce direction based on Paul Nettle's ftp://ftp.3dmaileffects.com/pub/FluidStudios/CollisionDetection/Fluid_Studios_Generic_Collision_Detection_for_Games_Using_Ellipsoids.pdf and comments by Max McGuire.  Ray-sphere code by Eric Haines.

  @created 2001-11-24
  @edited  2008-12-29
 */

#include "G3D/CoordinateFrame.h"
#include "G3D/platform.h"
#include "G3D/CollisionDetection.h"
#include "G3D/debugAssert.h"
#include "G3D/vectorMath.h"
#include "G3D/Capsule.h"
#include "G3D/Plane.h"
#include "G3D/Line.h"
#include "G3D/LineSegment.h"
#include "G3D/Sphere.h"
#include "G3D/Box.h"
#include "G3D/Triangle.h"
#include "G3D/Vector3.h"
#include "G3D/AABox.h"

#ifdef _MSC_VER
// Turn on fast floating-point optimizations
#pragma float_control( push )
#pragma fp_contract( on ) 
#pragma fenv_access( off )
#pragma float_control( except, off )
#pragma float_control( precise, off )
#endif


namespace G3D {

bool CollisionDetection::ignoreBool;
Vector3	CollisionDetection::ignore;
Array<Vector3> CollisionDetection::ignoreArray;



Vector3 CollisionDetection::separatingAxisForSolidBoxSolidBox(
        const int separatingAxisIndex,
        const Box & box1,
        const Box & box2) {
    debugAssert(separatingAxisIndex >= 0);
    debugAssert(separatingAxisIndex < 15);
    Vector3 axis;
    if (separatingAxisIndex < 3) {
        axis = box1.axis(separatingAxisIndex);
    } else if (separatingAxisIndex < 6) {
        axis = box2.axis(separatingAxisIndex - 3);
    } else {
        int box1Index = (separatingAxisIndex - 6) / 3;
        int box2Index = (separatingAxisIndex - 6) % 3;
        axis = cross(box1.axis(box1Index), box2.axis(box2Index));
    }
    return axis;
}

#ifdef _MSC_VER
#   pragma warning (push)
#   pragma warning (disable : 4244)
#endif

float CollisionDetection::projectedDistanceForSolidBoxSolidBox(
    const int           separatingAxisIndex,
    const Vector3 &     a,
    const Vector3 &     b,
    const Vector3 &     D,
    const double*       c,
    const double*       ca,
    const double*       ad,
    const double*       bd)
{
    (void)D;

    float R0 = 0.0f;
    float R1 = 0.0f;
    float R = 0.0f;
    switch (separatingAxisIndex) {
    case 0:
        // A0
        R0 = a[0];
        R1 = b[0] * ca[0] + b[1] * ca[1] + b[2] * ca[2];
        R = fabs(ad[0]);
        break;
    case 1:
        // A1
        R0 = a[1];
        R1 = b[0] * ca[3] + b[1] * ca[4] + b[2] * ca[5];
        R = fabs(ad[1]);
        break;
    case 2:
        // A2
        R0 = a[2];
        R1 = b[0] * ca[6] + b[1] * ca[7] + b[2] * ca[8];
        R = fabs(ad[2]);
        break;
    case 3:
        // B0
        R0 = a[0] * ca[0] + a[1] * ca[3] + a[2] * ca[6];
        R1 = b[0];
        R = fabs(bd[0]);
        break;
    case 4:
        // B1
        R0 = a[0] * ca[1] + a[1] * ca[4] + a[2] * ca[7];
        R1 = b[1];
        R = fabs(bd[1]);
        break;
    case 5:
        // B2
        R0 = a[0] * ca[2] + a[1] * ca[5] + a[2] * ca[8];
        R1 = b[2];
        R = fabs(bd[2]);
        break;
    case 6:
        // A0 x B0
        R0 = a[1] * ca[6] + a[2] * ca[3];
        R1 = b[1] * ca[2] + b[2] * ca[1];
        R = fabs(c[3] * ad[2] - c[6] * ad[1]);
        break;
    case 7:
        // A0 x B1
        R0 = a[1] * ca[7] + a[2] * ca[4];
        R1 = b[0] * ca[2] + b[2] * ca[0];
        R = fabs(c[4] * ad[2] - c[7] * ad[1]);
        break;
    case 8:
        // A0 x B2
        R0 = a[1] * ca[8] + a[2] * ca[5];
        R1 = b[0] * ca[1] + b[1] * ca[0];
        R = fabs(c[5] * ad[2] - c[8] * ad[1]);
        break;
    case 9:
        // A1 x B0
        R0 = a[0] * ca[6] + a[2] * ca[0];
        R1 = b[1] * ca[5] + b[2] * ca[4];
        R = fabs(c[6] * ad[0] - c[0] * ad[2]);
        break;
    case 10:
        // A1 x B1
        R0 = a[0] * ca[7] + a[2] * ca[1];
        R1 = b[0] * ca[5] + b[2] * ca[3];
        R = fabs(c[7] * ad[0] - c[1] * ad[2]);
        break;
    case 11:
        // A1 x B2
        R0 = a[0] * ca[8] + a[2] * ca[2];
        R1 = b[0] * ca[4] + b[1] * ca[3];
        R = fabs(c[8] * ad[0] - c[2] * ad[2]);
        break;
    case 12:
        // A2 x B0
        R0 = a[0] * ca[3] + a[1] * ca[0];
        R1 = b[1] * ca[8] + b[2] * ca[7];
        R = fabs(c[0] * ad[1] - c[3] * ad[0]);
        break;
    case 13:
        // A2 x B1
        R0 = a[0] * ca[4] + a[1] * ca[1];
        R1 = b[0] * ca[8] + b[2] * ca[6];
        R = fabs(c[1] * ad[1] - c[4] * ad[0]);
        break;
    case 14:
        // A2 x B2
        R0 = a[0] * ca[5] + a[1] * ca[2];
        R1 = b[0] * ca[7] + b[1] * ca[6];
        R = fabs(c[2] * ad[1] - c[5] * ad[0]);
        break;
    default:
        debugAssertM(false, "fell through switch statement");
    }

    return (R - (R0 + R1));
}


bool CollisionDetection::parallelAxisForSolidBoxSolidBox(
        const double* ca,
        const double epsilon,
        int & axis1,
        int & axis2) {
    const double parallelDot = 1.0 - epsilon;
    for (int i = 0; i < 9; i++) {
        if (ca[i] >= parallelDot) {
            axis1 = i / 3;
            axis2 = i % 3;
            return true;
        }
    }
    return false;
}




void CollisionDetection::fillSolidBoxSolidBoxInfo(
        const Box & box1,
        const Box & box2,
        Vector3 & a,
        Vector3 & b,
        Vector3 & D,
        double* c,
        double* ca,
        double* ad,
        double* bd) {
    // length between center and each side of box1 and box2
    a = box1.extent() * 0.5;
    b = box2.extent() * 0.5;

    // difference between centers of box1 and box2
    D = box2.center() - box1.center();

    // store the value of all possible dot products between the
    // axes of box1 and box2, c_{row, col} in the Eberly paper
    // corresponds to c[row * 3 + col] for this 9 element array.
    //
    // c[] holds signed values, ca[] hold absolute values
    for (int i = 0; i < 9; i++) {
        c[i] = dot(box1.axis(i / 3), box2.axis(i % 3));
        ca[i] = fabs(c[i]);
    }

    // store all possible dot products between the axes of box1 and D,
    // as well as the axes of box2 and D
    for (int i = 0; i < 3; i++) {
        ad[i] = dot(box1.axis(i), D);
        bd[i] = dot(box2.axis(i), D);
    }
}



bool CollisionDetection::conservativeBoxBoxTest(
        const Vector3 & a, const Vector3 & b, const Vector3 & D) {
    // do a quick bounding sphere test because it is relatively
    // cheap, (three dot products, two sqrts, and a few others)
    double boxRadius1 = a.magnitude();
    double boxRadius2 = b.magnitude();
    return (D.squaredMagnitude() < square(boxRadius1 + boxRadius2));
}




bool CollisionDetection::fixedSolidBoxIntersectsFixedSolidBox(
    const Box&      box1,
    const Box&      box2,
	const int		lastSeparatingAxis) {
    // for explanations of the variable please refer to the
    // paper and fillSolidBoxSolidBoxInfo()
    Vector3 a;
    Vector3 b;
    Vector3 D;
    double c[9];
    double ca[9];
    double ad[3];
    double bd[3];

    fillSolidBoxSolidBoxInfo(box1, box2, a, b, D, c, ca, ad, bd);

    int dummy1, dummy2;
    bool parallelAxes = parallelAxisForSolidBoxSolidBox(ca, 0.00001,
            dummy1, dummy2);

    // check the separating axis from the last time step
    if (lastSeparatingAxis != -1 &&
            (lastSeparatingAxis < 6 || !parallelAxes)) {
        double projectedDistance = projectedDistanceForSolidBoxSolidBox(
                lastSeparatingAxis, a, b, D, c, ca, ad, bd);

        // the separating axis from the last time step is still
        // valid, the boxes do not intersect
        if (projectedDistance > 0.0) {
            return false;
        }
    }

    // test if the boxes can be separated by a plane normal to
    // any of the three axes of box1, any of the three axes of box2,
    // or any of the 9 possible cross products of axes from box1
    // and box2
    for (int i = 0; i < 15; i++) {
        // do not need to check edge-edge cases if any two of
        // the axes are parallel
        if (parallelAxes && i == 6) {
            return true;
        }

        double projectedDistance =
            projectedDistanceForSolidBoxSolidBox(i, a, b, D, c, ca, ad, bd);

        // found a separating axis, the boxes do not intersect
        if (projectedDistance > 0.0) {
            return false;
        }
    }

    return true;
}



void CollisionDetection::closestPointsBetweenLineAndLine(
        const Line & line1,
        const Line & line2,
        Vector3 & closest1,
        Vector3 & closest2) {
    // TODO make accessors for Line that don't make a copy of data
    Vector3 P0 = line1.point();
    Vector3 u = line1.direction();
    Vector3 Q0 = line2.point();
    Vector3 v = line2.direction();
    Vector3 w0 = P0 - Q0;

    // a = 1.0, c = 1.0
    double  b = dot(u, v);
    double  d = dot(u, w0);
    double  e = dot(v, w0);
    double  D = 1.0 - b * b;
    double  sc, tc;

    static const double epsilon = 0.00001;

    if (D < epsilon) {
        // lines are parallel, choose P0 as one point, find the point
        // on line2 that is closest to P0
        sc = 0.0;
        tc = (b > 1.0) ? (d / b) : (e / 1.0);
    } else {
        // lines are not parallel
        sc = (b * e - 1.0 * d) / D;
        tc = (1.0 * e - b * d) / D;
    }

    closest1 = P0 + (sc * u);
    closest2 = Q0 + (tc * v);
}



float CollisionDetection::penetrationDepthForFixedBoxFixedBox(
    const Box&      box1,
    const Box&      box2,
    Array<Vector3>& contactPoints,
    Array<Vector3>& contactNormals,
    const int lastSeparatingAxis) {

    contactPoints.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    contactNormals.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);

    Vector3 a;
    Vector3 b;
    Vector3 D;
    double c[9];
    double ca[9];
    double ad[3];
    double bd[3];

    debugAssert(lastSeparatingAxis >= -1);
    debugAssert(lastSeparatingAxis < 15);

    fillSolidBoxSolidBoxInfo(box1, box2, a, b, D, c, ca, ad, bd);

    int axis1, axis2;
    bool parallelAxes = parallelAxisForSolidBoxSolidBox(ca, 0.00001,
            axis1, axis2);


    // check the separating axis from the last time step
    if (lastSeparatingAxis != -1 &&
            (lastSeparatingAxis < 6 || !parallelAxes)) {
        float projectedDistance = projectedDistanceForSolidBoxSolidBox(
                lastSeparatingAxis, a, b, D, c, ca, ad, bd);

        // the separating axis from the last time step is still
        // valid, the boxes do not intersect
        if (projectedDistance > 0.0) {
            return -projectedDistance;
        }
    }

    // test if the boxes can be separated by a plane normal to
    // any of the three axes of box1, any of the three axes of box2,
    // (test 9 possible cross products later)
	float penetration = -finf();
    int penetrationAxisIndex = -1;

    for (int i = 0; i < 6; i++) {
        float projectedDistance =
            projectedDistanceForSolidBoxSolidBox(i, a, b, D, c, ca, ad, bd);

        // found a separating axis, the boxes do not intersect
        if (projectedDistance > 0.0) {
            return -projectedDistance;
        }

        // keep track of the axis that is least violated
        if (projectedDistance > penetration) {
            penetration = projectedDistance;
            penetrationAxisIndex = i;
        }
    }


    // for each edge-edge case we have to adjust the magnitude of
    // penetration since we did not include the dot(L, L) denominator
    // that can be smaller than 1.0 for the edge-edge cases.
	if (!parallelAxes) {
	    double edgeDistances[9];

		// run through edge-edge cases to see if we can find a separating axis
		for (int i = 6; i < 15; i++) {
			float projectedDistance =
				projectedDistanceForSolidBoxSolidBox(i, a, b, D, c, ca, ad, bd);

			// found a separating axis, the boxes do not intersect,
			// correct magnitude and return projected distance
			if (projectedDistance > 0.0) {
				Vector3 L = separatingAxisForSolidBoxSolidBox(i, box1, box2);
				projectedDistance /= dot(L, L);
				return -projectedDistance;
			}

			edgeDistances[i - 6] = projectedDistance;
		}

		// no separating axis found, the boxes do intersect,
		// correct the magnitudes of the projectedDistance values
		for (int i = 6; i < 15; i++) {
			// find the negative penetration value with the smallest magnitude,
			// the adjustment done for the edge-edge cases only increases
			// magnitude by dividing by a number smaller than 1 and greater than 0
			float projectedDistance = (float)edgeDistances[i - 6];
			if (projectedDistance > penetration) {
				Vector3 L = separatingAxisForSolidBoxSolidBox(i, box1, box2);
				projectedDistance /= dot(L, L);
				if (projectedDistance > penetration) {
					penetration = projectedDistance;
					penetrationAxisIndex = i;
				}
			}
		}
	}

	// get final separating axis vector
    Vector3 L = separatingAxisForSolidBoxSolidBox(penetrationAxisIndex,
            box1, box2);

    // set L to be the normal that faces away from box1
    if (dot(L, D) < 0) {
        L = -L;
    }

    Vector3 contactPoint;

    if (penetrationAxisIndex < 6) {
        // vertex to face collision, find deepest colliding vertex
        const Box* vertexBox;
        const Box* faceBox;
        Vector3 faceNormal = L;

        // L will be the outward facing normal for the faceBox
        if (penetrationAxisIndex < 3) {
            faceBox = & box1;
            vertexBox = & box2;
            if (dot(L, D) < 0) {
                faceNormal = -L;
            }
        } else {
            faceBox = & box2;
            vertexBox = & box1;
            if (dot(L, D) > 0) {
                faceNormal = -L;
            }
        }

        // find the vertex that is farthest away in the direction
        // face normal direction
        int deepestPointIndex = 0;
        float deepestPointDot = dot(faceNormal, vertexBox->corner(0));
        for (int i = 1; i < 8; i++) {
            float dotProduct = dot(faceNormal, vertexBox->corner(i));
            if (dotProduct < deepestPointDot) {
                deepestPointDot = dotProduct;
                deepestPointIndex = i;
            }
        }
        
        // return the point half way between the deepest point and the
        // contacting face
        contactPoint = vertexBox->corner(deepestPointIndex) +
            (-penetration * 0.5 * faceNormal);
    } else {
        // edge-edge case, find the two ege lines
        int edge1 = (penetrationAxisIndex - 6) / 3;
        int edge2 = (penetrationAxisIndex - 6) % 3;
        Vector3 linePoint1 = box1.center();
        Vector3 linePoint2 = box2.center();
        Vector3 lineDir1;
        Vector3 lineDir2;

        // find edge line by finding the edge axis, and the
        // other two axes that are closest to the other box
        for (int i = 0; i < 3; i++ ) {
            if (i == edge1) {
                lineDir1 = box1.axis(i);
            } else {
                Vector3 axis = box1.axis(i);
                if (dot(axis, L) < 0) {
                    axis = -axis;
                }
                linePoint1 += axis * a[i];
            }

            if (i == edge2) {
                lineDir2 = box2.axis(i);
            } else {
                Vector3 axis = box2.axis(i);
                if (dot(axis, L) > 0) {
                    axis = -axis;
                }
                linePoint2 += axis * b[i];
            }
        }

        // make lines from the two closest edges, and find
        // the points that on each line that are closest to the other
        Line line1 = Line::fromPointAndDirection(linePoint1, lineDir1);
        Line line2 = Line::fromPointAndDirection(linePoint2, lineDir2);
        Vector3 closest1;
        Vector3 closest2;

        closestPointsBetweenLineAndLine(line1, line2, closest1, closest2);
        
        // take the average of the two closest edge points for the final
        // contact point
        contactPoint = (closest1 + closest2) * 0.5;
    }

    contactPoints.push(contactPoint);
    contactNormals.push(L);

    return -penetration;

}




float CollisionDetection::penetrationDepthForFixedSphereFixedBox(
    const Sphere&   sphere,
    const Box&      box,
    Array<Vector3>& contactPoints,
    Array<Vector3>& contactNormals) {

    contactPoints.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    contactNormals.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);

    // In its local coordinate frame, the box measures
    // 2 * halfExtent[a] along dimesion a.
    Vector3 halfExtent(box.extent(0), box.extent(1), box.extent(2));
    halfExtent *= 0.5f;

    CoordinateFrame boxFrame;
    box.getLocalFrame(boxFrame);

    // Transform the sphere to the box's coordinate frame.
    Vector3 center = boxFrame.pointToObjectSpace(sphere.center);

    // Find the square of the distance from the sphere to the box


    // Distance along each axis from the closest side of the box
    // to the sphere center.  Negative values are *inside* the box.
    Vector3 distOutsideBox;

    // Divide space up into the 27 regions corresponding
    // to {+|-|0}X, {+|-|0}Y, {+|-|0}Z and classify the
    // sphere center into one of them.
    Vector3 centerRegion;

    // In the edge collision case, the edge is between vertices
    // (constant + variable) and (constant - variable).
    Vector3 constant, variable;

    int numNonZero = 0;

    // Iterate over axes
    for (int a = 0; a < 3; ++a) { 
        // For each (box side), see which direction the sphere
        // is outside the box (positive or negative).  Add the
        // square of that distance to the total distance from 
        // the box.

        float distanceFromLow  = -halfExtent[a] - center[a];
        float distanceFromHigh = center[a] - halfExtent[a];

        if (fabsf(distanceFromLow) < fabsf(distanceFromHigh)) {
            distOutsideBox[a] = distanceFromLow;
        } else {
            distOutsideBox[a] = distanceFromHigh;
        }

        if (distanceFromLow < 0.0) {
            if (distanceFromHigh < 0.0) {
                // Inside the box
                centerRegion[a] = 0.0;
                variable[a]     = 1.0;
            } else {
                // Off the high side
                centerRegion[a] = 1.0;
                constant[a]     = halfExtent[a];
                ++numNonZero;
            }
        } else if (distanceFromHigh < 0.0) {
            // Off the low side
            centerRegion[a] = -1.0;
            constant[a]     = -halfExtent[a];
            ++numNonZero;
        } else {
            debugAssertM(false, 
                "distanceFromLow and distanceFromHigh cannot both be positive");
        }
    }

    // Squared distance between the outside of the box and the
    // sphere center.
    float d2 = Vector3::zero().max(distOutsideBox).squaredMagnitude();

    if (d2 > square(sphere.radius)) {
        // There is no penetration because the distance is greater
        // than the radius of the sphere.  This is the common case
        // and we quickly exit.
        return -1;
    }

    // We know there is some penetration but need to classify it.
    //
    // Examine the region that contains the center of the sphere. If
    // there is exactly one non-zero axis, the collision is with a 
    // plane.  If there are exactly two non-zero axes, the collision
    // is with an edge.  If all three axes are non-zero, the collision is
    // with a vertex.  If there are no non-zero axes, the center is inside
    // the box.

    double depth = -1;
    switch (numNonZero) {
    case 3: // Vertex collision
        // The collision point is the vertex at constant, the normal
        // is the vector from there to the sphere center.
        contactNormals.append(boxFrame.normalToWorldSpace(constant - center));
        contactPoints.append(boxFrame.pointToWorldSpace(constant));
        depth = sphere.radius - sqrt(d2);
        break;

    case 2: // Edge collision
        {
            // TODO: unwrapping the edge constructor and closest point
            // code will probably make it faster.

            // Determine the edge
            Line line = Line::fromPointAndDirection(constant, variable);

            // Penetration depth:
            depth = sphere.radius - sqrt(d2);

            // The contact point is the closes point to the sphere on the line 
            Vector3 X = line.closestPoint(center);
            contactNormals.append(boxFrame.normalToWorldSpace(X - center).direction());
            contactPoints.append(boxFrame.pointToWorldSpace(X));
        }
        break;

    case 1: // Plane collision
        {
            // The plane normal is the centerRegion vector,
            // so the sphere normal is the negative.  Take
            // it to world space from box-space.

            // Center region doesn't need to be normalized because
            // it is known to contain only one non-zero value
            // and that value is +/- 1.
            Vector3 N = boxFrame.normalToWorldSpace(-centerRegion);
            contactNormals.append(N);

            // Penetration depth:
            depth = sphere.radius - sqrtf(d2);

            // Compute the contact point from the penetration depth
            contactPoints.append(sphere.center + N * (sphere.radius - depth));
        }
        break;

    case 0: // Volume collision

        // The sphere center is inside the box.  This is an easy case
        // to handle.  Note that all axes of distOutsideBox must
        // be negative.  
    
        // Arbitratily choose the sphere center as a contact point
        contactPoints.append(sphere.center);

        // Find the least-negative penetration axis.
        //
        // We could have computed this during the loop over the axes,
        // but since volume collisions are rare (they only occur with
        // large time steps), this case will seldom be executed and
        // should not be optimized at the expense of the others.
        if (distOutsideBox.x > distOutsideBox.y) {
            if (distOutsideBox.x > distOutsideBox.z) {
                // Smallest penetration on x-axis
                // Chose normal based on which side we're closest to.
                // Keep in mind that this is a normal to the sphere,
                // so it is the inverse of the box normal.
                if (center.x > 0) {
                    contactNormals.append(boxFrame.normalToWorldSpace(-Vector3::unitX()));
                } else {
                    contactNormals.append(boxFrame.normalToWorldSpace(Vector3::unitX()));
                }
                depth = -distOutsideBox.x;
            } else {
                // Smallest penetration on z-axis
                goto ZAXIS;
            }
        } else if (distOutsideBox.y > distOutsideBox.z) {
            // Smallest penetration on y-axis
            // Chose normal based on which side we're closest to.
            // Keep in mind that this is a normal to the sphere,
            // so it is the inverse of the box normal.
            if (center.y > 0) {
                contactNormals.append(boxFrame.normalToWorldSpace(-Vector3::unitY()));
            } else {
                contactNormals.append(boxFrame.normalToWorldSpace(Vector3::unitY()));
            }
            depth = -distOutsideBox.y;
        } else {
            // Smallest on z-axis
ZAXIS:
            // Chose normal based on which side we're closest to.
            // Keep in mind that this is a normal to the sphere,
            // so it is the inverse of the box normal.
            if (center.z > 0) {
                contactNormals.append(boxFrame.normalToWorldSpace(-Vector3::unitZ()));
            } else {
                contactNormals.append(boxFrame.normalToWorldSpace(Vector3::unitZ()));
            }
            depth = -distOutsideBox.z;
        }
        break;

    default:
        debugAssertM(false, "Fell through switch");
        break;
    }

    return depth;
}


float CollisionDetection::penetrationDepthForFixedSphereFixedSphere(
    const Sphere&           sphereA,
    const Sphere&           sphereB,
    Array<Vector3>&         contactPoints,
    Array<Vector3>&         contactNormals) {

    Vector3 axis = sphereB.center - sphereA.center;
    double radius = sphereA.radius + sphereB.radius;
    double mag = axis.magnitude();
    axis /= mag;
    double depth = -(mag - radius);

    contactPoints.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    contactNormals.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);

    if (depth >= 0) {
        contactPoints.append(sphereA.center + axis * (sphereA.radius - depth / 2));
        contactNormals.append(axis);
    }

    return depth;
}


float CollisionDetection::penetrationDepthForFixedSphereFixedPlane(
    const Sphere&           sphereA,
    const Plane&            planeB,
    Array<Vector3>&         contactPoints,
    Array<Vector3>&         contactNormals) {

    Vector3 N;
    double d;

    planeB.getEquation(N, d);
    
    double depth = -(sphereA.center.dot(N) + d - sphereA.radius);

    contactPoints.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    contactNormals.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);

    if (depth >= 0) {
        contactPoints.append(N * (depth - sphereA.radius) + sphereA.center);
        contactNormals.append(N);
    }

    return depth;
}


float CollisionDetection::penetrationDepthForFixedBoxFixedPlane(
    const Box&          box,
    const Plane&        plane,
    Array<Vector3>&     contactPoints,
    Array<Vector3>&     contactNormals) {

    Vector3 N;
    double d;
    
    plane.getEquation(N, d);

    contactPoints.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
    contactNormals.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);

    float lowest = finf();
    for (int i = 0; i < 8; ++i) {
        const Vector3 vertex = box.corner(i);
        
        float x = vertex.dot(N) + (float)d;
        
        if (x <= 0) {
            // All vertices below the plane should be contact points.
            contactPoints.append(vertex);
            contactNormals.append(-N);
        }

        lowest = min(lowest, x);
    }

    // Depth should be a positive number
    return -lowest;
}


float CollisionDetection::collisionTimeForMovingPointFixedPlane(
    const Vector3&  point,
    const Vector3&  velocity,
    const Plane&    plane,
    Vector3&        location,
    Vector3&        outNormal) {

    // Solve for the time at which normal.dot(point + velocity) + d == 0.
    double d;
    Vector3 normal;
    plane.getEquation(normal, d);
    
    float vdotN = velocity.dot(normal);
    float pdotN = point.dot(normal);

    if (fuzzyEq(pdotN + d, 0)) {
        // The point is *in* the plane.
        location = point;
        outNormal = normal;
        return 0;
    }

    if (vdotN >= 0) {
        // no collision will occur
        location = Vector3::inf();
        return finf();
    }

    float t = -(pdotN + d) / vdotN;
    if (t < 0) {
        location = Vector3::inf();
        return finf();
    } else {
        location = point + velocity * t;
        outNormal = normal;
        return t;
    }
}

bool __fastcall CollisionDetection::rayAABox(
    const Ray&              ray,
    const Vector3&          invDir,
    const AABox&            box,
    const Vector3&          boxCenter,
    float                   boundingRadiusSquared,
    Vector3&                location,
    bool&                   inside) {

    debugAssertM(fabs(ray.direction().squaredLength() - 1.0f) < 0.01f, format("Length = %f", ray.direction().length()));
    {
        // Pre-emptive partial bounding sphere test
        const Vector3 L(boxCenter - ray.origin());
        float d = L.dot(ray.direction());

        float L2 = L.dot(L);
        float D2 = square(d);
        float M2 = L2 - D2;

        if (((d < 0) && (L2 > boundingRadiusSquared)) || (M2 > boundingRadiusSquared)) {
            inside = false;
            return false;
        }
        // Passing here does not mean that the ray hits the bounding sphere;
        // we would still have to perform more expensive tests to determine
        // that.
    }

    inside = true;
    const Vector3& MinB = box.low();
    const Vector3& MaxB = box.high();
    Vector3 MaxT(-1.0f, -1.0f, -1.0f);

    // Find candidate planes.
    for (int i = 0; i < 3; ++i) {
        if (ray.origin()[i] < MinB[i]) {
            location[i]	= MinB[i];
            inside      = false;
            
            // Calculate T distances to candidate planes
            if (ray.direction()[i] != 0) {
                MaxT[i] = (MinB[i] - ray.origin()[i]) * invDir[i];
            }
        } else if (ray.origin()[i] > MaxB[i]) {
            location[i]	= MaxB[i];
            inside      = false;

            // Calculate T distances to candidate planes
            if (ray.direction()[i] != 0) {
                MaxT[i] = (MaxB[i] - ray.origin()[i]) * invDir[i];
            }
        }
    }

    if (inside) {
    	// Ray origin inside bounding box
        location = ray.origin();
        return true;
    }
    
    // Get largest of the maxT's for final choice of intersection
    int WhichPlane = 0;
    if (MaxT[1] > MaxT[WhichPlane]) {
        WhichPlane = 1;
    }

    if (MaxT[2] > MaxT[WhichPlane]) {
        WhichPlane = 2;
    }

    // Check final candidate actually inside box
    if (MaxT[WhichPlane] < 0.0f) {
        // Miss the box
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        if (i != WhichPlane) {
            location[i] = ray.origin()[i] + MaxT[WhichPlane] * ray.direction()[i];
            if ((location[i] < MinB[i]) ||
                (location[i] > MaxB[i])) {
                // On this plane we're outside the box extents, so
                // we miss the box
                return false;
            }
        }
    }
    
    return true;
}

float CollisionDetection::collisionTimeForMovingPointFixedSphere(
    const Vector3&  point,
    const Vector3&  velocity,
    const Sphere&   sphere,
    Vector3&        location,
    Vector3&        outNormal,
    bool            solid) {

    if (solid && sphere.contains(point)) {
        location = point;
        outNormal = (point - sphere.center).direction();
        return 0.0f;
    }

    float          speed = velocity.magnitude();
    const Vector3& direction = velocity / speed;

    // length of the axis between the start and the sphere
    const Vector3& L = sphere.center - point;
    float          d = L.dot(direction);

    float L2 = L.dot(L);
    float R2 = square(sphere.radius);
    float D2 = square(d);

    if ((d < 0.0f) && (L2 > R2)) {
        location = Vector3::inf();
        return finf();
    }

    const float M2 = L2 - D2;

    if (M2 > R2) {
        location = Vector3::inf();
        return finf();
    }

    float q = sqrt(R2 - M2);
    float time;

    if (L2 > R2) {
        time = d - q;
    } else {
        time = d + q;
    }

    time /= speed;

    location  = point + velocity * time;
    outNormal = (location - sphere.center).direction();

    return time;
}


float CollisionDetection::collisionTimeForMovingSphereFixedSphere(
    const Sphere&   movingSphere,
    const Vector3&  velocity,
    const Sphere&   fixedSphere,
    Vector3&        location,
    Vector3&        outNormal) {

    const Vector3& sep = (fixedSphere.center - movingSphere.center);
    float sepLen = sep.squaredLength();
    if (sepLen < square(movingSphere.radius + fixedSphere.radius)) {
        // Interpenetrating
        outNormal   = sep.directionOrZero();
        location = fixedSphere.center - outNormal * fixedSphere.radius;
        return 0;
    }

    float time = collisionTimeForMovingPointFixedSphere
        (movingSphere.center, velocity, 
         Sphere(fixedSphere.center, fixedSphere.radius + movingSphere.radius), 
         location, outNormal);

    if (time < finf()) {
        // Location is now the center of the moving sphere at the collision time.
        // Adjust for the size of the moving sphere.  Two spheres always collide
        // along a line between their centers.
        location += (location - fixedSphere.center) * movingSphere.radius / fixedSphere.radius;
    }

    return time;
}


/*
float CollisionDetection::collisionTimeForMovingPointFixedTriangle(
    const Vector3&			point,
    const Vector3&			velocity,
    const Triangle&       triangle,
    Vector3&				outLocation,
    Vector3&                outNormal) {

    double time = collisionTimeForMovingPointFixedPlane(point, velocity, triangle.plane(), outLocation, outNormal);

    if (time == finf()) {
        // No collision with the plane of the triangle.
        return finf();
    }

    if (isPointInsideTriangle(triangle.vertex(0), triangle.vertex(1), triangle.vertex(2), triangle.normal(), outLocation, triangle.primaryAxis())) {
        // Collision occured inside the triangle
        return time;
    } else {
        // Missed the triangle
        outLocation = Vector3::inf();
        return finf();
    }
}*/

/*
float CollisionDetection::collisionTimeForMovingPointFixedTriangle(
    const Vector3& orig,
    const Vector3& dir,
    const Vector3& vert0,
    const Vector3& vert1,
    const Vector3& vert2) {

    // Barycenteric coords
    double u, v;
    #define EPSILON 0.000001
    #define CROSS(dest,v1,v2) \
              dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; \
              dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; \
              dest[2]=v1[0]*v2[1]-v1[1]*v2[0];

    #define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

    #define SUB(dest,v1,v2) \
              dest[0]=v1[0]-v2[0]; \
              dest[1]=v1[1]-v2[1]; \
              dest[2]=v1[2]-v2[2]; 

    double edge1[3], edge2[3], tvec[3], pvec[3], qvec[3];
    
    // find vectors for two edges sharing vert0
    SUB(edge1, vert1, vert0);
    SUB(edge2, vert2, vert0);
    
    // begin calculating determinant - also used to calculate U parameter
    CROSS(pvec, dir, edge2);
    
    // if determinant is near zero, ray lies in plane of triangle
    const double det = DOT(edge1, pvec);
    
    if (det < EPSILON) {
        return finf();
    }
    
    // calculate distance from vert0 to ray origin
    SUB(tvec, orig, vert0);
    
    // calculate U parameter and test bounds
    u = DOT(tvec, pvec);
    if ((u < 0.0) || (u > det)) {
        // Hit the plane outside the triangle
        return finf();
    }
    
    // prepare to test V parameter
    CROSS(qvec, tvec, edge1);
    
    // calculate V parameter and test bounds
    v = DOT(dir, qvec);
    if ((v < 0.0) || (u + v > det)) {
        // Hit the plane outside the triangle
        return finf();
    }
    
    // calculate t, scale parameters, ray intersects triangle
    // If we want u,v, we can compute this
    // double t = DOT(edge2, qvec);
    //const double inv_det = 1.0 / det;
    //t *= inv_det;
    //u *= inv_det;
    //v *= inv_det;
    // return t;

    // Case where we don't need correct (u, v):

    const double t = DOT(edge2, qvec);
    
    if (t >= 0) {
        // Note that det must be positive
        return t / det;
    } else {
        // We had to travel backwards in time to intersect
        return finf();
    }

    #undef EPSILON
    #undef CROSS
    #undef DOT
    #undef SUB
}
*/

float CollisionDetection::collisionTimeForMovingPointFixedBox(
    const Vector3&          point,
    const Vector3&          velocity,
    const Box&              box,
    Vector3&                location,
    Vector3&                outNormal) {

    double    bestTime;

    Vector3 normal;
    Vector3 v[4];

    // Prime the loop
    int f = 0;
    box.getFaceCorners(f, v[0], v[1], v[2], v[3]);
    bestTime = collisionTimeForMovingPointFixedRectangle(point, velocity, v[0], v[1], v[2], v[3], location, normal);
    outNormal = normal;

    // Check other faces
    for (f = 1; f < 6; ++f) {
        Vector3 pos;
        box.getFaceCorners(f, v[0], v[1], v[2], v[3]);
        float time = collisionTimeForMovingPointFixedRectangle(point, velocity, v[0], v[1], v[2], v[3], pos, normal);
        if (time < bestTime) {
            bestTime = time;
            outNormal = normal;
            location = pos;
        }
    }

    return bestTime;
}


float CollisionDetection::collisionTimeForMovingPointFixedAABox(
    const Vector3&          origin,
    const Vector3&          dir,
    const AABox&            box,
    Vector3&                location,
    bool&                   Inside,
    Vector3&                normal) {

    if (collisionLocationForMovingPointFixedAABox(origin, dir, box, location, Inside, normal)) {
        return (location - origin).magnitude();
    } else {
        return (float)finf();
    }
}


bool CollisionDetection::collisionLocationForMovingPointFixedAABox(
    const Vector3&          origin,
    const Vector3&          dir,
    const AABox&            box,
    Vector3&                location,
    bool&                   Inside,
    Vector3&                normal) {

    // Integer representation of a floating-point value.
    #define IR(x)	((uint32&)x)

    Inside = true;
	const Vector3& MinB = box.low();
	const Vector3& MaxB = box.high();
	Vector3 MaxT(-1.0f, -1.0f, -1.0f);

	// Find candidate planes.
    for (int i = 0; i < 3; ++i) {
		if (origin[i] < MinB[i]) {
			location[i]	= MinB[i];
			Inside      = false;

			// Calculate T distances to candidate planes
            if (IR(dir[i])) {
                MaxT[i] = (MinB[i] - origin[i]) / dir[i];
            }
        } else if (origin[i] > MaxB[i]) {
			location[i]	= MaxB[i];
			Inside	    = false;

			// Calculate T distances to candidate planes
            if (IR(dir[i])) {
                MaxT[i] = (MaxB[i] - origin[i]) / dir[i];
            }
		}
	}

	if (Inside) {
    	// Ray origin inside bounding box
        location = origin;
		return false;
	}

	// Get largest of the maxT's for final choice of intersection
	int WhichPlane = 0;
    if (MaxT[1] > MaxT[WhichPlane])	{
        WhichPlane = 1;
    }

    if (MaxT[2] > MaxT[WhichPlane])	{
        WhichPlane = 2;
    }

	// Check final candidate actually inside box
    if (IR(MaxT[WhichPlane]) & 0x80000000) {
        // Miss the box
        return false;
    }

	for (int i = 0; i < 3; ++i) {
        if (i != WhichPlane) {
			location[i] = origin[i] + MaxT[WhichPlane] * dir[i];
            if ((location[i] < MinB[i]) ||
                (location[i] > MaxB[i])) {
                // On this plane we're outside the box extents, so
                // we miss the box
                return false;
            }
		}
	}

    // Choose the normal to be the plane normal facing into the ray
    normal = Vector3::zero();
    normal[WhichPlane] = (dir[WhichPlane] > 0) ? -1.0 : 1.0;

	return true;

    #undef IR
}



float CollisionDetection::collisionTimeForMovingPointFixedRectangle(
    const Vector3&      point,
    const Vector3&      velocity,
    const Vector3&      v0,
    const Vector3&      v1,
    const Vector3&      v2,
    const Vector3&      v3,
    Vector3&            location,
    Vector3&            outNormal) {

    Plane plane = Plane(v0, v1, v2);

    float time = collisionTimeForMovingPointFixedPlane(point, velocity, plane, location, outNormal);

    if (time == finf()) {
        // No collision is ever going to happen
        return time;
    }

    if (isPointInsideRectangle(v0, v1, v2, v3, plane.normal(), location)) {
        // The intersection point is inside the rectangle; that is the location where
        // the point hits the rectangle.
        return time;
    } else {
        return finf();
    }
}

/** Used by findRayCapsuleIntersection.
    @cite From magic software http://www.magic-software.com/Source/Intersection3D/MgcIntr3DLinCap.cpp */
static int findRayCapsuleIntersectionAux(
	const Vector3&		rkOrigin,
	const Vector3&		rkDirection,
    const Capsule&		rkCapsule,
	double   			afT[2]) {

	Vector3 capsuleDirection = rkCapsule.point(1) - rkCapsule.point(0);

    // set up quadratic Q(t) = a*t^2 + 2*b*t + c
    Vector3 kU, kV, kW = capsuleDirection;
    float fWLength = kW.unitize();
    Vector3::generateOrthonormalBasis(kU, kV, kW);
    Vector3 kD(kU.dot(rkDirection), kV.dot(rkDirection), kW.dot(rkDirection));
    float fDLength = kD.unitize();

    float fEpsilon = 1e-6f;

    float fInvDLength = 1.0f/fDLength;
    Vector3 kDiff = rkOrigin - rkCapsule.point(0);
    Vector3 kP(kU.dot(kDiff),kV.dot(kDiff),kW.dot(kDiff));
    float fRadiusSqr = square(rkCapsule.radius());

    float fInv, fA, fB, fC, fDiscr, fRoot, fT, fTmp;

    // Is the velocity parallel to the capsule direction? (or zero)
    if ((abs(kD.z) >= 1.0f - fEpsilon) || (fDLength < fEpsilon)) {

        float fAxisDir = rkDirection.dot(capsuleDirection);

        fDiscr = fRadiusSqr - kP.x*kP.x - kP.y*kP.y;
        if ((fAxisDir < 0) && (fDiscr >= 0.0f)) {
            // Velocity anti-parallel to the capsule direction
            fRoot = sqrt(fDiscr);
            afT[0] = (kP.z + fRoot)*fInvDLength;
            afT[1] = -(fWLength - kP.z + fRoot)*fInvDLength;
            return 2;
        } else if ((fAxisDir > 0) && (fDiscr >= 0.0f)) {
            // Velocity parallel to the capsule direction
            fRoot = sqrt(fDiscr);
            afT[0] = -(kP.z + fRoot)*fInvDLength;
            afT[1] = (fWLength - kP.z + fRoot)*fInvDLength;
            return 2;
        } else {
            // sphere heading wrong direction, or no velocity at all
            return 0;
        }   
    }

    // test intersection with infinite cylinder
    fA = kD.x*kD.x + kD.y*kD.y;
    fB = kP.x*kD.x + kP.y*kD.y;
    fC = kP.x*kP.x + kP.y*kP.y - fRadiusSqr;
    fDiscr = fB*fB - fA*fC;
    if (fDiscr < 0.0f) {
        // line does not intersect infinite cylinder
        return 0;
    }

    int iQuantity = 0;

    if (fDiscr > 0.0f) {
        // line intersects infinite cylinder in two places
        fRoot = sqrt(fDiscr);
        fInv = 1.0f/fA;
        fT = (-fB - fRoot)*fInv;
        fTmp = kP.z + fT*kD.z;
        if ((0.0f <= fTmp) && (fTmp <= fWLength)) {
            afT[iQuantity] = fT * fInvDLength;
            iQuantity++;
		}

        fT = (-fB + fRoot)*fInv;
        fTmp = kP.z + fT*kD.z;
        
		if ((0.0f <= fTmp) && (fTmp <= fWLength)) {
            afT[iQuantity++] = fT*fInvDLength;
		}

        if (iQuantity == 2) {
            // line intersects capsule wall in two places
            return 2;
        }
    } else {
        // line is tangent to infinite cylinder
        fT = -fB/fA;
        fTmp = kP.z + fT*kD.z;
        if ((0.0f <= fTmp) && (fTmp <= fWLength)) {
            afT[0] = fT*fInvDLength;
            return 1;
        }
    }

    // test intersection with bottom hemisphere
    // fA = 1
    fB += kP.z*kD.z;
    fC += kP.z*kP.z;
    fDiscr = fB*fB - fC;
    if (fDiscr > 0.0f) {
        fRoot = sqrt(fDiscr);
        fT = -fB - fRoot;
        fTmp = kP.z + fT*kD.z;
        if (fTmp <= 0.0f) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }

        fT = -fB + fRoot;
        fTmp = kP.z + fT*kD.z;
        if (fTmp <= 0.0f) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }
    } else if (fDiscr == 0.0f) {
        fT = -fB;
        fTmp = kP.z + fT*kD.z;
        if (fTmp <= 0.0f) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }
    }

    // test intersection with top hemisphere
    // fA = 1
    fB -= kD.z*fWLength;
    fC += fWLength*(fWLength - 2.0f*kP.z);

    fDiscr = fB*fB - fC;
    if (fDiscr > 0.0f) {
        fRoot = sqrt(fDiscr);
        fT = -fB - fRoot;
        fTmp = kP.z + fT*kD.z;
        if (fTmp >= fWLength) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }

        fT = -fB + fRoot;
        fTmp = kP.z + fT*kD.z;
        if (fTmp >= fWLength) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }
    } else if (fDiscr == 0.0f) {
        fT = -fB;
        fTmp = kP.z + fT*kD.z;
        if (fTmp >= fWLength) {
            afT[iQuantity++] = fT*fInvDLength;
            if (iQuantity == 2) {
                return 2;
			}
        }
    }

    return iQuantity;
}


/** Used by collisionTimeForMovingPointFixedCapsule.
    @cite From magic software http://www.magic-software.com/Source/Intersection3D/MgcIntr3DLinCap.cpp
	
	@param rkRay      The ray
	@param rkCapsule  The capsule
	@param riQuantity The number of intersections found
	@param akPoint    The intersections found
	@return           True if there is at least one intersection
	*/
static bool findRayCapsuleIntersection(
	const Ray&			rkRay,
	const Capsule&		rkCapsule,
	int&				riQuantity,
	Vector3				akPoint[2]) {

    double afT[2];
    riQuantity = findRayCapsuleIntersectionAux(rkRay.origin(), rkRay.direction(), rkCapsule, afT);

    // Only return intersections that occur in the future
    int iClipQuantity = 0;
	int i;
    for (i = 0; i < riQuantity; ++i) {
        if (afT[i] >= 0.0f) {
            akPoint[iClipQuantity] = rkRay.origin() + afT[i] * rkRay.direction();
            ++iClipQuantity;
        }
    }

    riQuantity = iClipQuantity;
    return (riQuantity > 0);
}

float CollisionDetection::collisionTimeForMovingPointFixedCapsule(
	const Vector3&		_point,
	const Vector3&		velocity,
	const Capsule&		capsule,
	Vector3&		    location,
    Vector3&            outNormal) {

	float timeScale = velocity.magnitude();

    if (timeScale == 0.0f) {
        timeScale = 1;
    }

	Vector3 direction = velocity / timeScale;
	int numIntersections;
	Vector3 intersection[2];
	findRayCapsuleIntersection(Ray::fromOriginAndDirection(_point, direction), capsule, numIntersections, intersection);

	if (numIntersections == 2) {
		// A collision can only occur if there are two intersections.  If there is one
		// intersection, that one is exiting the capsule.  

		// Find the entering intersection (the first one that occurs).
		float d0 = (intersection[0] - _point).squaredMagnitude();
		float d1 = (intersection[1] - _point).squaredMagnitude();

        // Compute the surface normal (if we aren't ignoring the result)
        if (&outNormal != &ignore) {
            Vector3 p2 = LineSegment::fromTwoPoints(capsule.point(0), capsule.point(1)).closestPoint(_point);
            outNormal = (_point - p2).direction();
        }

        if (d0 > d1) {
			location = intersection[1];
			return sqrt(d1) / timeScale;
		} else {
			location = intersection[0];
			return sqrt(d0) / timeScale;
		}
	} else {
		// No entering intersection discovered; return no intersection.
		location = Vector3::inf();
		return finf();
	}
}


float CollisionDetection::collisionTimeForMovingSphereFixedPlane(
    const Sphere&		sphere,
    const Vector3&		velocity,
    const Plane&		plane,
    Vector3&			location,
    Vector3&            outNormal) {

	if (sphere.radius == 0) {
		// Optimization for zero radius sphere
        return collisionTimeForMovingPointFixedPlane(sphere.center, velocity, plane, location, outNormal);
	}

    // The collision point on the sphere will be the point at
    // center - (radius * normal).  Collisions only occur when
    // the sphere is travelling into the plane.

    double d;
    plane.getEquation(outNormal, d);
    
    double vdotN = velocity.dot(outNormal);

    if (fuzzyGt(vdotN, 0)) {
        // No collision when the sphere is moving towards a backface.
        location = Vector3::inf();
        return (float)finf();
    }

    float cdotN = sphere.center.dot(outNormal);

    // Distance from the center to the plane
    float distance = cdotN + (float)d;

    // Where is the collision on the sphere?
    Vector3 point = sphere.center - (sphere.radius * outNormal);

    if (fuzzyLe(G3D::abs(distance), sphere.radius)) {
        // Already interpenetrating
        location = sphere.center - distance * outNormal;
        return 0;
    } else {
        return collisionTimeForMovingPointFixedPlane(point, velocity, plane, location, outNormal);
    }

}


float CollisionDetection::collisionTimeForMovingSphereFixedTriangle(
    const class Sphere&		sphere,
    const Vector3&              velocity,
    const Triangle&             triangle,
    Vector3&                    outLocation,
    float                       b[3]) {

    Vector3 dummy;
    float time = collisionTimeForMovingSphereFixedPlane(sphere, velocity, triangle.plane(), 
                                                        outLocation, dummy);

    if (time == finf()) {
        // No collision is ever going to happen
        return time;
    }

    // We will hit the plane of the triangle at *time*. See if
    // the intersection point actually is within the triangle.

    if (isPointInsideTriangle(triangle.vertex(0), triangle.vertex(1), triangle.vertex(2), triangle.normal(), 
        outLocation, b, triangle.primaryAxis())) {

        // The intersection point is inside the triangle; that is the location where
        // the sphere hits the triangle.

#       ifdef G3D_DEBUG
        {
            // Internal consistency checks
            debugAssertM(b[0] >= 0.0 && b[0] <= 1.0f, "Intersection is outside triangle.");
            debugAssertM(b[1] >= 0.0 && b[1] <= 1.0f, "Intersection is outside triangle.");
            debugAssertM(b[2] >= 0.0 && b[2] <= 1.0f, "Intersection is outside triangle.");
            Vector3 blend = 
                b[0] * triangle.vertex(0) + 
                b[1] * triangle.vertex(1) + 
                b[2] * triangle.vertex(2);
            debugAssertM(blend.fuzzyEq(outLocation), "Barycentric coords don't match intersection.");
            // Call again so that we can debug the problem
            // isPointInsideTriangle(triangle.vertex(0), triangle.vertex(1), triangle.vertex(2), triangle.normal(), 
            // outLocation, b, triangle.primaryAxis());
        }
#       endif

        return time;
    }

    // The collision (if it exists) is with a point on the triangle perimeter.
    // Switch over to moving the triangle towards a fixed sphere and see at what time
    // they will hit.

    // Closest point on the triangle to the sphere intersection with the plane.
    int edgeIndex;
    const Vector3& point = closestPointOnTrianglePerimeter(triangle._vertex, triangle.edgeDirection,
                                                           triangle.edgeMagnitude, outLocation, edgeIndex);

    float t = 0;
    if (! sphere.contains(point)) {
        // The point is outside the sphere--see when it will hit
        t = collisionTimeForMovingPointFixedSphere(point, -velocity, sphere, dummy, dummy);
    }

    if (t < finf()) {
        outLocation = point;
        // Compute Barycentric coords

        // Index of the next vertex
        static const int next[] = {1, 2, 0};

        // Project along the edge in question.
        // Avoid sqrt by taking advantage of the existing edgeDirection unit vector.
        b[next[edgeIndex]] = (outLocation - triangle._vertex[edgeIndex]).dot
            (triangle.edgeDirection[edgeIndex]) / triangle.edgeMagnitude[edgeIndex];

        b[edgeIndex] = 1.0f - b[next[edgeIndex]];

        b[next[next[edgeIndex]]] = 0.0f;

#       ifdef G3D_DEBUG
        {
            // Internal consistency checks
            for (int i = 0; i < 3; ++i) {
                debugAssertM(fuzzyGe(b[i], 0.0f) && fuzzyLe(b[i], 1.0f), "Intersection is outside triangle.");
            }
            Vector3 blend = 
                b[0] * triangle.vertex(0) + 
                b[1] * triangle.vertex(1) + 
                b[2] * triangle.vertex(2);
            debugAssertM(blend.fuzzyEq(outLocation), 
                format("Barycentric coords don't match intersection. %s != %s", 
                    blend.toString().c_str(), 
                    outLocation.toString().c_str()));    

            // Call again so that we can debug the problem
            collisionTimeForMovingPointFixedSphere(point, -velocity, sphere, dummy, dummy);
        }
#       endif

        // Due to tiny roundoffs, these values might be slightly out of bounds.
        // Ensure that they are legal.  Note that the above debugging code
        // verifies that we are not clamping truly illegal values.
        for (int i = 0; i < 3; ++i) {
            b[i] = clamp(b[i], 0.0f, 1.0f);
        }
    }

    // The collision occured at the point, if it occured.  The normal
    // was the plane normal, computed above.

    return t;
}


float CollisionDetection::collisionTimeForMovingSphereFixedRectangle(
    const Sphere&       sphere,
    const Vector3&      velocity,
    const Vector3&      v0,
    const Vector3&      v1,
    const Vector3&      v2,
    const Vector3&      v3,
    Vector3&            location,
    Vector3&            outNormal) {

    Plane plane(v0, v1, v2);

    float time = collisionTimeForMovingSphereFixedPlane(sphere, velocity, plane, location, outNormal);

    if (time == finf()) {
        // No collision is ever going to happen
        return time;
    }

    if (isPointInsideRectangle(v0, v1, v2, v3, plane.normal(), location)) {
        // The intersection point is inside the rectangle; that is the location where
        // the sphere hits the rectangle.
        return time;
    }

    // Switch over to moving the rectangle towards a fixed sphere and see at what time
    // they will hit.

    Vector3 point = closestPointToRectanglePerimeter(v0, v1, v2, v3, sphere.center);

    Vector3 dummy;
    double t = collisionTimeForMovingPointFixedSphere(point, -velocity, sphere, location, dummy);

    // Normal is the plane normal, location is the original location of the point.
    location = point;

    return t;
}


float CollisionDetection::collisionTimeForMovingSphereFixedBox(
    const Sphere&       sphere,
    const Vector3&      velocity,
    const Box&          box,
    Vector3&            location,
    Vector3&            outNormal) {

    if (fixedSolidSphereIntersectsFixedSolidBox(sphere, box)) {
        // TODO: Compute more useful location and normal?
        location = sphere.center;
        outNormal = Vector3::zero();
        return 0;
    }

    float bestTime;

    Vector3 v[4];
    int f = 0;
    box.getFaceCorners(f, v[0], v[1], v[2], v[3]);
    bestTime = collisionTimeForMovingSphereFixedRectangle(sphere, velocity, v[0], v[1], v[2], v[3], location, outNormal);

    for (f = 1; f < 6; ++f) {
        Vector3 pos, normal;
        box.getFaceCorners(f, v[0], v[1], v[2], v[3]);
        float time = collisionTimeForMovingSphereFixedRectangle(sphere, velocity, v[0], v[1], v[2], v[3], pos, normal);
        if (time < bestTime) {
            bestTime  = time;
            location  = pos;
            outNormal = normal;
        }
    }

    return bestTime;
}


float CollisionDetection::collisionTimeForMovingSphereFixedCapsule(
	const Sphere&		sphere,
	const Vector3&		velocity,
	const Capsule&		capsule,
	Vector3&		    location,
    Vector3&            outNormal) {

    (void)outNormal;

	Capsule _capsule(capsule.point(0), capsule.point(1), capsule.radius() + sphere.radius);

    Vector3 normal;
	double time = collisionTimeForMovingPointFixedCapsule(sphere.center, velocity, _capsule, location, normal);
    
    if (time < finf()) {
        // Location is now the position of the center of the sphere at the time of collision.
        // We have to adjust the collision location for the size of the sphere.
        location -= sphere.radius * normal;
    }

    return time;
}


Vector3 CollisionDetection::bounceDirection(
    const Sphere&   sphere,
    const Vector3&  velocity,
    const float     collisionTime,
    const Vector3&  collisionLocation,
    const Vector3&  collisionNormal) {

	// Location when the collision occurs
    Vector3 sphereLocation  = sphere.center + velocity * collisionTime;

    Vector3 normal          = (sphereLocation - collisionLocation);
    if (fuzzyEq(normal.squaredMagnitude(), 0)) {
        normal = collisionNormal;
    } else {
        normal.unitize();
    }

    Vector3 direction       = velocity.direction();

    // Reflect direction about the normal
    return direction - 2.0 * normal * normal.dot(direction);
}


Vector3 CollisionDetection::slideDirection(
    const Sphere&   sphere,
    const Vector3&  velocity,
    const float     collisionTime,
    const Vector3&  collisionLocation) {

    Vector3 sphereLocation  = sphere.center + velocity * collisionTime;
    Vector3 normal          = (sphereLocation - collisionLocation).direction();
    Vector3 direction       = velocity.direction();

    // subtract off the part in the direction away from the normal.
    return direction - normal * normal.dot(direction);
}


Vector3 CollisionDetection::closestPointOnLineSegment(
    const Vector3& v0,
    const Vector3& v1,
    const Vector3& point) {

    const Vector3& edge       = (v1 - v0);
    float          edgeLength = edge.magnitude();

    if (edgeLength == 0) {
        // The line segment is a point
        return v0;
    }

    return closestPointOnLineSegment(v0, v1, edge / edgeLength, edgeLength, point);
}


Vector3 CollisionDetection::closestPointOnLineSegment(
    const Vector3& v0,
    const Vector3& v1,
    const Vector3& edgeDirection,
    const float    edgeLength,
    const Vector3& point) {

    debugAssert((v1 - v0).direction().fuzzyEq(edgeDirection));
    debugAssert(fuzzyEq((v1 - v0).magnitude(), edgeLength));

    // Vector towards the point
    const Vector3& c = point - v0;

    // Projected onto the edge itself
    float t = edgeDirection.dot(c);

    if (t <= 0) {
        // Before the start
        return v0;
    } else if (t >= edgeLength) {
        // After the end
        return v1;
    } else {
        // At distance t along the edge
        return v0 + edgeDirection * t;
    }
}


Vector3 CollisionDetection::closestPointOnTrianglePerimeter(
    const Vector3&			v0, 
    const Vector3&			v1,
    const Vector3&			v2,
    const Vector3&			point) {
    
    Vector3 v[3] = {v0, v1, v2};
    Vector3 edgeDirection[3] = {(v1 - v0), (v2 - v1), (v0 - v2)};
    float   edgeLength[3];
    
    for (int i = 0; i < 3; ++i) {
        edgeLength[i] = edgeDirection[i].magnitude();
        edgeDirection[i] /= edgeLength[i];
    }

    int edgeIndex;
    return closestPointOnTrianglePerimeter(v, edgeDirection, edgeLength, point, edgeIndex);
}


Vector3 CollisionDetection::closestPointOnTrianglePerimeter(
    const Vector3   v[3],
    const Vector3   edgeDirection[3],
    const float     edgeLength[3],
    const Vector3&  point,
    int&            edgeIndex) {

    // Closest point on segment from v[i] to v[i + 1]
    Vector3 r[3];

    // Distance squared from r[i] to point
    float d[3];

    // Index of the next point
    static const int next[] = {1, 2, 0};

    for (int i = 0; i < 3; ++i) {
        r[i] = closestPointOnLineSegment(v[i], v[next[i]], edgeDirection[i], edgeLength[i], point);
        d[i] = (r[i] - point).squaredMagnitude();
    }

    if (d[0] < d[1]) {
        if (d[0] < d[2]) {
            // Between v0 and v1
            edgeIndex = 0;
        } else {
            // Between v2 and v0
            edgeIndex = 2;
        }
    } else {
        if (d[1] < d[2]) {
            // Between v1 and v2
            edgeIndex = 1;
        } else {
            // Between v2 and v0
            edgeIndex = 2;
        }
    }

#   ifdef G3D_DEBUG
    {
        Vector3 diff = r[edgeIndex] - v[edgeIndex];
        debugAssertM(fuzzyEq(diff.direction().dot(edgeDirection[edgeIndex]), 1.0f) ||
            diff.fuzzyEq(Vector3::zero()), "Point not on correct triangle edge");
        float frac = diff.dot(edgeDirection[edgeIndex])/edgeLength[edgeIndex];
        debugAssertM(frac >= -0.000001, "Point off low side of edge.");
        debugAssertM(frac <= 1.000001, "Point off high side of edge.");
    }
#   endif

    return r[edgeIndex];
}


bool CollisionDetection::isPointInsideTriangle(
    const Vector3&			v0,
    const Vector3&			v1,
    const Vector3&			v2,
    const Vector3&			normal,
    const Vector3&			point,
    float                   b[3],
    Vector3::Axis           primaryAxis) {
    
    if (primaryAxis == Vector3::DETECT_AXIS) {
        primaryAxis = normal.primaryAxis();
    }

    // Check that the point is within the triangle using a Barycentric
    // coordinate test on a two dimensional plane.
    int i, j;

    switch (primaryAxis) {
    case Vector3::X_AXIS:
        i = Vector3::Y_AXIS;
        j = Vector3::Z_AXIS;
        break;

    case Vector3::Y_AXIS:
        i = Vector3::Z_AXIS;
        j = Vector3::X_AXIS;
        break;

    case Vector3::Z_AXIS:
        i = Vector3::X_AXIS;
        j = Vector3::Y_AXIS;
        break;

    default:
        // This case is here to supress a warning on Linux
        i = j = 0;
        debugAssertM(false, "Should not get here.");
        break;
    }

    // See if all barycentric coordinates are non-negative

    // 2D area via cross product
#   define AREA2(d, e, f)  (((e)[i] - (d)[i]) * ((f)[j] - (d)[j]) - ((f)[i] - (d)[i]) * ((e)[j] - (d)[j]))

    // Area of the polygon
    float area = AREA2(v0, v1, v2);
    if (area == 0) {
        // This triangle has zero area, so the point must not
        // be in it unless the triangle point is the test point.
        return (v0 == point);
    }

    debugAssert(area != 0);

    float invArea = 1.0f / area;

    // (avoid normalization until absolutely necessary)
    b[0] = AREA2(point, v1, v2) * invArea;

    if ((b[0] < 0.0f) || (b[0] > 1.0f)) {
        return false;
    }

    b[1] = AREA2(v0,  point, v2) * invArea;
    if ((b[1] < 0.0f) || (b[1] > 1.0f)) {
        return false;
    }

    b[2] = 1.0f - b[0] - b[1];

#   undef AREA2

    return (b[2] >= 0.0f) && (b[2] <= 1.0f);
}


bool CollisionDetection::isPointInsideRectangle(
    const Vector3& v0,
    const Vector3& v1,
    const Vector3& v2,
    const Vector3& v3,
    const Vector3& normal,
    const Vector3& point) {

    return isPointInsideTriangle(v0, v1, v2, normal, point) ||
           isPointInsideTriangle(v2, v3, v0, normal, point);  
}


Vector3 CollisionDetection::closestPointToRectanglePerimeter(
    const Vector3& v0,
    const Vector3& v1,
    const Vector3& v2,
    const Vector3& v3,
    const Vector3& point) {

    Vector3 r0 = closestPointOnLineSegment(v0, v1, point);
    Vector3 r1 = closestPointOnLineSegment(v1, v2, point);
    Vector3 r2 = closestPointOnLineSegment(v2, v3, point);
    Vector3 r3 = closestPointOnLineSegment(v3, v0, point);

    double d0 = (r0 - point).squaredMagnitude();
    double d1 = (r1 - point).squaredMagnitude();
    double d2 = (r2 - point).squaredMagnitude();
    double d3 = (r3 - point).squaredMagnitude();

    if (d0 < d1) {
        if (d0 < d2) {
            if (d0 < d3) {
                return r0;
            } else {
                return r3;
            }
        } else {
            if (d2 < d3) {
                return r2;
            } else {
                return r3;
            }
        }
    } else {
        if (d1 < d2) {
            if (d1 < d3) {
                return r1;
            } else {
                return r3;
            }
        } else {
            if (d2 < d3) {
                return r2;
            } else {
                return r3;
            }
        }
    }
}


Vector3 CollisionDetection::closestPointToRectangle(
    const Vector3&      v0,
    const Vector3&      v1,
    const Vector3&      v2,
    const Vector3&      v3,
    const Vector3&      point) {

    Plane plane(v0, v1, v2);

    // Project the point into the plane
    double a, b, c, d;
    plane.getEquation(a, b, c, d);
    
    double distance = a*point.x + b*point.y + c*point.z + d;
    Vector3 planePoint = point - distance * plane.normal();

    if (isPointInsideRectangle(v0, v1, v2, v3, plane.normal(), planePoint)) {
        return planePoint;
    } else {
        return closestPointToRectanglePerimeter(v0, v1, v2, v3, planePoint);
    }
}


bool CollisionDetection::fixedSolidSphereIntersectsFixedSolidSphere(
    const Sphere&           sphere1,
    const Sphere&           sphere2) {
    
    return (sphere1.center - sphere2.center).squaredMagnitude() < square(sphere1.radius + sphere2.radius);
}


bool CollisionDetection::fixedSolidSphereIntersectsFixedSolidBox(
    const Sphere&           sphere,
    const Box&              box) {

    // If the center of the sphere is within the box, the whole
    // sphere is within the box.
    if (box.contains(sphere.center)) {
        return true;
    }

    float r2 = square(sphere.radius);

    // Find the closest point on the surface of the box to the sphere.  If
    // this point is within the sphere's radius, they intersect.
    int f;
    for (f = 0; f < 6; ++f) {
        Vector3 v0, v1, v2, v3;
        box.getFaceCorners(f, v0, v1, v2, v3);
        if ((closestPointToRectangle(v0, v1, v2, v3, sphere.center) - sphere.center).squaredMagnitude() <= r2) {
            return true;
        }
    }

    return false;
}


bool CollisionDetection::movingSpherePassesThroughFixedBox(
    const Sphere&           sphere,
    const Vector3&          velocity,
    const Box&              box,
    double                  timeLimit) {

    // If they intersect originally, they definitely pass through each other.
    if (fixedSolidSphereIntersectsFixedSolidBox(sphere, box)) {
        return true;
    }

    // See if the sphere hits the box during the time period.
    Vector3 dummy1, dummy2;

    return (collisionTimeForMovingSphereFixedBox(sphere, velocity, box, dummy1, dummy2) < timeLimit);
}


bool CollisionDetection::movingSpherePassesThroughFixedSphere(
    const Sphere&           sphere,
    const Vector3&          velocity,
    const Sphere&           fixedSphere,
    double                  timeLimit) {

    if (fixedSolidSphereIntersectsFixedSolidSphere(sphere, fixedSphere)) {
        return true;
    }

    // Extend the fixed sphere by the radius of the moving sphere
    Sphere bigFixed(fixedSphere.center, fixedSphere.radius + sphere.radius);
    Vector3 dummy1, dummy2;

    // If the sphere collides with the other sphere during the time limit, it passes through
    return (collisionTimeForMovingPointFixedSphere(sphere.center, velocity, bigFixed, dummy1, dummy2) < timeLimit);
}



bool CollisionDetection::fixedSolidSphereIntersectsFixedTriangle(
    const Sphere&           sphere,
    const Triangle&         triangle) {

    // How far is the sphere from the plane of the triangle
    const Plane& plane = triangle.plane();

    // Does the closest point to the sphere center lie within the triangle?
    Vector3 v = plane.closestPoint(sphere.center);

    // Is the closest point to the plane within the sphere?
    if ((v - sphere.center).squaredLength() <= square(sphere.radius)) {
        // Is it also within the triangle?
        float b[3];
        if (isPointInsideTriangle(triangle.vertex(0), triangle.vertex(1), triangle.vertex(2), triangle.normal(), 
                v, b, triangle.primaryAxis())){
            // The closest point is inside the triangle
            return true;
        }
    }

    // ignored
    int edgeIndex;

    v = closestPointOnTrianglePerimeter(triangle._vertex, triangle.edgeDirection, triangle.edgeMagnitude, sphere.center, edgeIndex);

    // Is the closest point within the sphere?
    return ((v - sphere.center).squaredLength() <= square(sphere.radius));
}


////////////////////////////////////////////////////////////////////////////////
// AABB-triangle overlap test code based on Tomas Akenine-Möller's
// http://www.cs.lth.se/home/Tomas_Akenine_Moller/code/tribox3.txt
// Ported 2008-12-28

#define X 0
#define Y 1
#define Z 2

#define FINDMINMAX(x0, x1, x2, min, max) \
    min = max = x0;   \
    if(x1<min) min=x1;\
    if(x1>max) max=x1;\
    if(x2<min) min=x2;\
    if(x2>max) max=x2;

static bool planeBoxOverlap(const Vector3& normal, const Vector3& vert, const Vector3& maxbox)  {
    Vector3 vmin, vmax;
    float v;
    
    // for each axis
    for(int a = 0; a < 3; ++a) {
        v = vert[a];
        
        if (normal[a] > 0.0f) {
            vmin[a] = -maxbox[a] - v;
            vmax[a] =  maxbox[a] - v;
        } else {
            vmin[a] =  maxbox[a] - v;
            vmax[a] = -maxbox[a] - v;
        }
    }
    
    if (normal.dot(vmin) > 0.0f) {
        return false;
    } else if (normal.dot(vmax) >= 0.0f) {
        return true;
    } else {
        return false;
    }
}

/*======================== X-tests ========================*/

#define AXISTEST_X01(a, b, fa, fb)   \
    p0 = a*v0[Y] - b*v0[Z];          \
    p2 = a*v2[Y] - b*v2[Z];          \
    if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
    rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return false;


#define AXISTEST_X2(a, b, fa, fb)    \
    p0 = a*v0[Y] - b*v0[Z];          \
    p1 = a*v1[Y] - b*v1[Z];          \
    if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return false;

/*======================== Y-tests ========================*/

#define AXISTEST_Y02(a, b, fa, fb)   \
    p0 = -a*v0[X] + b*v0[Z];         \
    p2 = -a*v2[X] + b*v2[Z];         \
    if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return false;

#define AXISTEST_Y1(a, b, fa, fb)   \
    p0 = -a*v0[X] + b*v0[Z];        \
    p1 = -a*v1[X] + b*v1[Z];        \
    if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return false;

/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)   \
    p1 = a*v1[X] - b*v1[Y];          \
    p2 = a*v2[X] - b*v2[Y];          \
    if(p2<p1) {min=p2; max=p1;} else {min=p1; max=p2;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
    if(min>rad || max<-rad) return false;

#define AXISTEST_Z0(a, b, fa, fb)   \
    p0 = a*v0[X] - b*v0[Y];   \
    p1 = a*v1[X] - b*v1[Y];           \
    if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
    if(min>rad || max<-rad) return false;

bool CollisionDetection::fixedSolidBoxIntersectsFixedTriangle(
   const AABox& box, const Triangle& tri) {

    //    use separating axis theorem to test overlap between triangle and box 
    //    need to test for overlap in these directions: 
    //    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle 
    //       we do not even need to test these) 
    //    2) normal of the triangle 
    //    3) crossproduct(edge from tri, {x,y,z}-direction) 
    //       this gives 3x3=9 more tests 

    // This is the fastest branch (on Sun).
    // Move the triangle to the object space of the box
    // Triangle vertices in box object space

    const Vector3& boxcenter = box.center();
    const Vector3& boxhalfsize = box.extent() * 0.5f;

    const Vector3& v0 = tri.vertex(0) - boxcenter;
    const Vector3& v1 = tri.vertex(1) - boxcenter;
    const Vector3& v2 = tri.vertex(2) - boxcenter;

    // Compute triangle edges in object space
    const Vector3& e0 = v1 - v0;
    const Vector3& e1 = v2 - v1;
    const Vector3& e2 = v0 - v2;

    // Bullet 3: 
    //  test the 9 tests first (this was faster) 
    float min,max,p0,p1,p2,rad;
    Vector3 fe;

    fe = abs(e0);
    AXISTEST_X01(e0[Z], e0[Y], fe[Z], fe[Y]);
    AXISTEST_Y02(e0[Z], e0[X], fe[Z], fe[X]);
    AXISTEST_Z12(e0[Y], e0[X], fe[Y], fe[X]);
    
    fe = abs(e1);
    AXISTEST_X01(e1[Z], e1[Y], fe[Z], fe[Y]);
    AXISTEST_Y02(e1[Z], e1[X], fe[Z], fe[X]);
    AXISTEST_Z0 (e1[Y], e1[X], fe[Y], fe[X]);

    fe = abs(e2);
    AXISTEST_X2 (e2[Z], e2[Y], fe[Z], fe[Y]);
    AXISTEST_Y1 (e2[Z], e2[X], fe[Z], fe[X]);
    AXISTEST_Z12(e2[Y], e2[X], fe[Y], fe[X]);

    // Bullet 1: 
    //  first test overlap in the {x,y,z}-directions 
    //  find min, max of the triangle each direction, and test for overlap in 
    //  that direction -- this is equivalent to testing a minimal AABB around
    //  the triangle against the AABB 

    // test in X-direction 
    FINDMINMAX(v0[X],v1[X],v2[X],min,max);
    if (min > boxhalfsize[X] || max < -boxhalfsize[X]) {
        return false;
    }

    // test in Y-direction
    FINDMINMAX(v0[Y],v1[Y],v2[Y],min,max);
    if (min > boxhalfsize[Y] || max < -boxhalfsize[Y]) {
        return false;
    }

    // test in Z-direction 
    FINDMINMAX(v0[Z],v1[Z],v2[Z],min,max);
    if (min > boxhalfsize[Z] || max < -boxhalfsize[Z]) {
        return false;
    }

    // Bullet 2: 
    //  test if the box intersects the plane of the triangle 
    //  compute plane equation of triangle: normal*x+d=0 

    if (! planeBoxOverlap(tri.normal(), v0, boxhalfsize)) {
        return false;
    }

    // box and triangle overlap
    return true;
}
#undef X
#undef Y
#undef Z

////////////////////////////////////////////////////////////////////////////////


} // namespace

#ifdef _MSC_VER
// Turn off fast floating-point optimizations
#pragma float_control( pop )
#pragma warning (pop)
#endif
