/**
  @file CollisionDetection.h


  Moving collision detection for simple primitives.

  @author Morgan McGuire, http://graphics.cs.williams.edu
  @cite Spherical collision based on Paul Nettle's
  ftp://ftp.3dmaileffects.com/pub/FluidStudios/CollisionDetection/Fluid_Studios_Generic_Collision_Detection_for_Games_Using_Ellipsoids.pdf
  and comments by Max McGuire.  Ray-sphere intersection by Eric Haines.
  Box-Box intersection written by Kevin Egan.
  Thanks to Max McGuire of Iron Lore for various bug fixes.
  Box-Triangle by Tomas Akenine-Moller

  @created 2001-11-19
  @edited  2008-12-19

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_COLLISIONDETECTION_H
#define G3D_COLLISIONDETECTION_H

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Plane.h"
#include "G3D/Box.h"
#include "G3D/Triangle.h"
#include "G3D/Array.h"
#include "G3D/Ray.h"
#include "G3D/Line.h"

namespace G3D {


/**
  Collision detection primitives and tools for building
  higher order collision detection schemes.

  These routines provide <I>moving</I> and static collision detection.
  Moving collision detection allows the calculation of collisions that
  occur during a period of time -- as opposed to the intersection of 
  two static bodies.
  
  Moving collision detection routines detect collisions between
  <I>only</I> static primitives and moving spheres or points.  Since the 
  reference frame can be user defined, these functions can be used to
  detect the collision between two moving bodies by subtracting
  the velocity vector of one object from the velocity vector of the 
  sphere or point the detection is to occur with.  This unified 
  velocity vector will act as if both objects are moving simultaneously.

  Collisions are detected for single-sided objects only.  That is,
  no collision is detected when <I>leaving</I> a primitive or passing
  through a plane or triangle opposite the normal... except for the 
  point-sphere calculation or when otherwise noted.

  For a sphere, the collision location returned is the point in world
  space where the surface of the sphere and the fixed object meet.
  It is <B>not</B> the position of the center of the sphere at
  the time of the collision.

  The collision normal returned is the surface normal to the fixed
  object at the collision location.

  <p>
  <b>Static Collision Detection:</b> (Neither object is moving)

  <table>
  <tr><td></td><td><b>Vector3</b></td><td><b>LineSegment</b></td><td><b>Ray *</b></td><td><b>Line</b></td><td><b>Plane</b></td><td><b>Triangle</b></td><td><b>Sphere</b></td><td><b>Cylinder</b></td><td><b>Capsule</b></td><td><b>AABox</b></td><td><b>Box</b></td></tr>
  <tr><td><b>Vector3</b></td><td>\link Vector3::operator== V3::==\endlink \link Vector3::fuzzyEq V3::fuzzy \endlink \link G3D::distance distance \endlink</td><td bgcolor=#C0C0C0 colspan=10 ></td></tr>
  <tr><td><b>LineSegment</b></td><td>\link LineSegment::closestPoint LS::closestPoint\endlink \link LineSegment::distance LS::distance\endlink \link CollisionDetection::closestPointOnLineSegment CD\endlink</td><td></td><td bgcolor=#C0C0C0 colspan=9 ></td></tr>
  <tr><td><b>Ray *</b></td><td>Ray::closestPoint Ray::distance</td><td></td><td></td><td bgcolor=#C0C0C0 colspan=8 ></td></tr>
  <tr><td><b>Line</b></td><td>Line::closestPoint Line::distance</td><td></td><td>\link CollisionDetection::closestPointsBetweenLineAndLine CD\endlink</td><td></td><td bgcolor=#C0C0C0 colspan=7 ></td></tr>
  <tr><td><b>Plane</b></td><td></td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=6 ></td></tr>
  <tr><td><b>Triangle</b></td><td></td><td></td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=5 ></td></tr>
  <tr><td><b>Sphere</b></td><td>Sphere::contains</td><td></td><td>\link CollisionDetection::collisionTimeForMovingPointFixedSphere CD \endlink, \link Ray::intersectionTime R::time\endlink</td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=4 ></td></tr>
  <tr><td><b>Cylinder</b></td><td>Cylinder::contains</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=3 ></td></tr>
  <tr><td><b>Capsule</b></td><td>Capsule::contains</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=2 ></td></tr>
  <tr><td><b>AABox</b></td><td>AABox::contains</td><td></td><td></td><td></td><td></td><td>\link CollisionDetection::fixedSolidBoxIntersectsFixedTriangle CD\endlink</td><td></td><td></td><td></td><td></td><td bgcolor=#C0C0C0 colspan=1 ></td></tr>
  <tr><td><b>Box</b></td><td>Box::contains</td><td>(treat as Ray)</td><td>\link CollisionDetection::collisionTimeForMovingPointFixedBox CD\endlink</td><td>(treat as Ray)</td><td>\link CollisionDetection::penetrationDepthForFixedBoxFixedPlane CD \endlink</td><td>\link CollisionDetection::penetrationDepthForFixedBoxFixedPlane CD\endlink</td><td>\link CollisionDetection::penetrationDepthForFixedSphereFixedBox CD\endlink</td><td>None (use OPCODE)</td><td>\link CollisionDetection::movingSpherePassesThroughFixedBox CD \endlink</td><td>\link CollisionDetection::penetrationDepthForFixedBoxFixedBox CD\endlink</td><td>\link CollisionDetection::penetrationDepthForFixedBoxFixedBox CD\endlink</td></tr>
  </table>

  <p>
  <b>Moving Collision Detection:</b>

  <i>* Note: Moving collision detection against certain primitives is equivalent to static collision
   detection against a bigger primitive.  Ray, Line Segment == ``moving Point''; Capsule ==``moving Sphere''; Plane == ``moving Line''</i>

   @deprecated Routines moving to the G3D::Intersect class in G3D 8.0
 */
class CollisionDetection {
private:

	/**
	 Default parameter if value passed to a function as reference is
	 not to be calculated.  Must be explicitly supported by function.
	 */
	static Vector3 ignore;

	/**
	 Default parameter if value passed to a function as reference is
	 not to be calculated.  Must be explicitly supported by function.
	 */
    static bool    ignoreBool;

	/**
	 Default parameter if value passed to a function as reference is
	 not to be calculated.  Must be explicitly supported by function.
	 */
    static Array<Vector3> ignoreArray;


    // Static class!
    CollisionDetection() {}
    virtual ~CollisionDetection() {}

public:

    /**
      Converts an index [0, 15] to the corresponding separating axis.
      Does not return normalized vector in the edge-edge case
      (indices 6 through 15).

	  @param separatingAxisIndex	Separating axis.
	  @param box1					Box 1.
	  @param box2					Box 2.

 	  @return Axis that separates the two boxes.
  	 */
    static Vector3 separatingAxisForSolidBoxSolidBox(
            const int       separatingAxisIndex,
            const Box &     box1,
            const Box &     box2);

    /**
	  Tests whether two boxes have axes that are parallel to
	  each other.  If they are, axis1 and axis2 are set to be
	  the parallel axes for both box1 and box2 respectively.

	  @param ca			Dot products of each of the boxes axes
	  @param epsilon	Fudge factor (small unit by which the dot
	  					products may vary and still be considered
	  					zero).
	  @param axis1		Parallel Axis 1. [Post Condition]
	  @param axis2		Parallel Axis 2. [Post Condition]

	  @return true  - If boxes have a parallel axis
	  @return false - otherwise.
 	 */
    static bool parallelAxisForSolidBoxSolidBox(
            const double*   ca,
            const double    epsilon,
            int &           axis1,
            int &           axis2);

    /**
      Calculates the projected distance between the two boxes along
      the specified separating axis, negative distances correspond
      to an overlap along that separating axis.  The distance is not
      divided by denominator dot(L, L), see
      penetrationDepthForFixedSphereFixedBox() for more details

      @param separatingAxisIndex
	  @param a Box 1's bounding sphere vector
	  @param b Box 2's bounding sphere vector
	  @param D Vector between Box 1 and Box 2's center points
	  @param c Pointer to array of dot products of the axes of Box 1
	           and Box 2.
	  @param ca Pointer to array of unsigned dot products of the axes
	            of Box 1 and Box 2.
	  @param ad Pointer to array of dot products of Box 1 axes and D.
	  @param bd Pointer to array of dot products of Box 2 axes and D.

      @return Projected distance between the two boxes along the
      specified separating axis.
     */
    static float projectedDistanceForSolidBoxSolidBox(
            const int           separatingAxisIndex,
            const Vector3 &     a,
            const Vector3 &     b,
            const Vector3 &     D,
            const double*       c,
            const double*       ca,
            const double*       ad,
            const double*       bd);


	/**
	  Creates a set of standard information about two boxes in order to
	  solve for their collision.  This information includes a vector to
	  the radius of the bounding sphere for each box, the vector between
	  each boxes' center and a series of dot products between differing
	  important vectors.  These dot products include those between the axes
	  of both boxes (signed and unsigned values), and the dot products
	  between all the axes of box1 and the boxes' center vector and box2
	  and the boxes' center vector.

	  @pre The following space requirements must be met:
      		- c[]  9 elements
      		- ca[] 9 elements
      		- ad[] 3 elements
      		- bd[] 3 elements

	  @cite dobted from David Eberly's papers, variables used in this function
      correspond to variables used in pages 6 and 7 in the pdf
      http://www.magic-software.com/Intersection.html
      http://www.magic-software.com/Documentation/DynamicCollisionDetection.pdf

      @note Links are out-dated. (Kept to preserve origin and authorship)

	  @param box1 Box 1
	  @param box2 Box 2
	  @param a Box 1's bounding sphere vector
	  @param b Box 2's bounding sphere vector
	  @param D Vector between Box 1 and Box 2's center points
	  @param c Pointer to array of dot products of the axes of Box 1
	           and Box 2.
	  @param ca Pointer to array of unsigned dot products of the axes
	            of Box 1 and Box 2.
	  @param ad Pointer to array of dot products of Box 1 axes and D.
	  @param bd Pointer to array of dot products of Box 2 axes and D.
	 */
    static void fillSolidBoxSolidBoxInfo(
            const Box &     box1,
            const Box &     box2,
            Vector3 &       a,
            Vector3 &       b,
            Vector3 &       D,
            double*         c,
            double*         ca,
            double*         ad,
            double*         bd);

	/**
	  Performs a simple bounding sphere check between two boxes to determine
	  whether these boxes could <i>possibly</i> intersect.  This is a very
	  cheap operation (three dot products, two sqrts and a few others).  If
	  it returns true, an intersection is possible, but not necessarily
	  guaranteed.

	  @param a Vector from box A's center to an outer vertex
	  @param b Vector from box B's center to an outer vertex
	  @param D Distance between the centers of the two boxes

	  @return true - if possible intersection
	  @return false - otherwise (This does not guarantee an intersection)
	 */
    static bool conservativeBoxBoxTest(
            const Vector3 &     a,
            const Vector3 &     b,
            const Vector3 &     D);

	/**
 	  Determines whether two fixed solid boxes intersect.

      @note To speed up collision detection, the lastSeparatingAxis from
      the previous time step can be passed in and that plane can be
      checked first.  If the separating axis was not saved, or if the
      two boxes intersected then lastSeparatingAxis should equal -1.

	  @cite Adobted from David Eberly's papers, variables used in this function
      correspond to variables used in pages 6 and 7 in the pdf
      http://www.magic-software.com/Intersection.html
      http://www.magic-software.com/Documentation/DynamicCollisionDetection.pdf

 	  @param box1				Box 1.
 	  @param box2				Box 2.
 	  @param lastSeparatingAxis	Last separating axis.
 	  							(optimization - see note)

	  @return true  - Intersection.
	  @return false - otherwise.
	 */
    static bool fixedSolidBoxIntersectsFixedSolidBox(
        const Box&      box1,
        const Box&      box2,
        const int       lastSeparatingAxis = -1);

    /**
	  Calculates the closest points on two lines with each other.   If the
	  lines are parallel then using the starting point, else calculate the
	  closest point on each line to the other.

	  @note This is very similiar to calculating the intersection of two lines.
	  Logically then, the two points calculated would be identical if calculated
	  with inifinite precision, but with the finite precision of floating point
	  calculations, these values could (will) differ as the line slope approaches
	  zero or inifinity.

	  @cite variables and algorithm based on derivation at the following website:
      	    http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm

	  @param line1		Line 1.
	  @param line2		Line 2.
	  @param closest1	Closest point on line 1.
	  @param closest2	Closest point on line 2.
 	*/
    static void closestPointsBetweenLineAndLine(
            const Line &    line1,
            const Line &    line2,
            Vector3 &       closest1,
            Vector3 &       closest2);

    /**
	  Calculates the depth of penetration between two fixed boxes.
      Contact normal faces away from box1 and into box2.  If there is
      contact, only one contact point is returned.  The minimally
      violated separating plane is computed
         - if the separating axis corresponds to a face
              the contact point is half way between the deepest vertex
              and the face
         - if the separating axis corresponds to two edges
              the contact point is the midpoint of the smallest line
              segment between the two edge lines

	  @note This is very similiar to calculating the intersection of two lines.
	  Logically then, the two points calculated would be identical if calculated
	  with inifinite precision, but with the finite precision of floating point
	  calculations, these values could (will) differ as the line slope approaches
	  zero or inifinity.

	  @cite adobted from David Eberly's papers, variables used in this function
      correspond to variables used in pages 6 and 7 in the pdf
      http://www.magic-software.com/Intersection.html
      http://www.magic-software.com/Documentation/DynamicCollisionDetection.pdf

	  @param box1				Box 1
	  @param box2				Box 2
	  @param contactPoints		Contact point between boxes. [Post Condition]
	  @param contactNormals		Surface normal at contact point. [Post Condition]
	  @param lastSeparatingAxis	Last separating axis. (Used for optimization)

	  @return Depth of penetration between the two boxes.  If there is no
 	   intersection between the boxes, then a negative value is returned.
 	*/
    static float penetrationDepthForFixedBoxFixedBox(
        const Box&          box1,
        const Box&          box2,
        Array<Vector3>&     contactPoints,
        Array<Vector3>&     contactNormals,
        const int           lastSeparatingAxis = -1);

    /**
	  Calculates the depth of penetration between two fixed spheres as well
	  as the deepest point of Sphere A that penetrates Sphere B. The normal
      returned points <B>away</B> from the object A, although it may
      represent a perpendicular to either the faces of object B or object A
      depending on their relative orientations.

	  @param sphereA		Fixed Sphere A.
	  @param sphereB		Fixed Sphere B.
	  @param contactPoints	Sphere A's deepest point that penetrates Sphere B.
	 						[Post Condition]
	  @param contactNormals	Normal at penetration point. [Post Condition]

	  @return Depth of penetration.  If there is no intersection between the
	 		 objects then the depth will be a negative value.
	 */
    static float penetrationDepthForFixedSphereFixedSphere(
        const class Sphere& sphereA,
        const Sphere&       sphereB,
        Array<Vector3>&     contactPoints,
        Array<Vector3>&     contactNormals = ignoreArray);

    /**
	  Calculates the depth of penetration between a fixed sphere and a fixed
	  box as well as the deepest point of the sphere that penetrates the box
	  and the normal at that intersection.

	  @note There are three possible intersections between a sphere and box.
	  - Sphere completely contained in the box
	  - Sphere intersects one edge
	  - Sphere intersects one vertex

	  The contact point and contact normal vary for each of these situations.
	  - Sphere contained in Box:
	 	- Normal is based on side of least penetration (as is the depth calculation).
	 	- Point is based on center of sphere
	  - Sphere intersects one edge
	 	- Normal is based on vector from the box center to the point of depth.
	 	- Point is closest point to the sphere on the line
	  - Sphere intersects one vertex
	 	- Normal is based on vector from the box center to the vertex of penetration.
	 	- Point is vertex of penetration.

      @cite Adapted from Jim Arvo's method in Graphics Gems
      See also http://www.win.tue.nl/~gino/solid/gdc2001depth.pdf

	  @param sphere			Fixed Sphere.
	  @param box			Fixed Box.
	  @param contactPoints	Sphere point that penetrates the box. [Post Condition]
	  @param contactNormals	Normal at the penetration point. [Post Condition]

	  @return Depth of penetration.  If there is no intersection between the
	 		  objects then the depth will be a negative value.
 	 */
    static float penetrationDepthForFixedSphereFixedBox(
        const Sphere&       sphere,
        const Box&          box,
        Array<Vector3>&     contactPoints,
        Array<Vector3>&     contactNormals = ignoreArray);

	/**
	  Calculates the depth of penetration between a Fixed Sphere and a Fixed
	  Plane as well as the deepest point of the sphere that penetrates the plane
	  and the plane normal at that intersection.

	  @param sphereA        Fixed Sphere.
	  @param planeB         Fixed Plane.
	  @param contactPoints  Sphere point that penetrates the plane.
	 						[Post Condition]
	  @param contactNormals Normal at penetration point. [Post Condition]

 	  @return Depth of penetration.  If there is no intersection between the
	  		 objects then the depth will be a negative value.
 	 */
    static float penetrationDepthForFixedSphereFixedPlane(
        const Sphere&       sphereA,
        const class Plane&  planeB,
        Array<Vector3>&     contactPoints,
        Array<Vector3>&     contactNormals = ignoreArray);

	/**
	  Calculates the depth of penetration between a fixed box and a fixed
	  plane as well as the vertexes of the box that penetrate the plane
	  and the plane normals at those intersections.

	  @param box			Fixed Box.
	  @param plane			Fixed Plane.
	  @param contactPoints	Box points that penetrate the plane.
	 						[Post Condition]
	  @param contactNormals	Normals at penetration points [Post Condition]

	  @return Depth of penetration.  If there is no intersection between the
	 		 objects then the depth will be a negative value.
 	*/
    static float penetrationDepthForFixedBoxFixedPlane(
        const Box&          box,
        const Plane&        plane,
        Array<Vector3>&     contactPoints,
        Array<Vector3>&     contactNormals = ignoreArray);

	/**
 	  Calculates time between the intersection of a moving point and a fixed
 	  plane.

 	  @note This is only a one sided collision test.   The side defined by
 	  the plane's surface normal is the only one tested.  For a two sided
 	  collision, call the function once for each side's surface normal.

 	  @param point		Moving point.
 	  @param velocity	Point's velocity.
 	  @param plane		Fixed plane.
 	  @param location	Location of collision. [Post Condition]
 	  					(Infinite vector on no collision)
 	  @param outNormal	Plane's surface normal. [Post Condition]

 	  @return Time til collision.  If there is no collision then the return
 	          value will be inf().
 	*/
    static float collisionTimeForMovingPointFixedPlane(
        const Vector3&			point,
        const Vector3&			velocity,
        const class Plane&		plane,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
 	  Calculates time between the intersection of a moving point and a fixed
 	  triangle.

 	  @note This is only a one sided collision test.   The side defined by
 	  the triangle's surface normal is the only one tested.  For a two sided
 	  collision, call the function once for each side's surface normal.

 	  @param orig		Moving point.
 	  @param dir		Point's velocity.
	  @param v0 		Triangle vertex 1.
	  @param v1 		Triangle vertex 2.
	  @param v2 		Triangle vertex 3

 	  @return Time til collision.  If there is no collision then the return
 	          value will be inf().
 	*/
    inline static float collisionTimeForMovingPointFixedTriangle(
        const Vector3& orig,
        const Vector3& dir,
        const Vector3& v0,
        const Vector3& v1,
        const Vector3& v2) {
        return Ray::fromOriginAndDirection(orig, dir).intersectionTime(v0, v1, v2);
    }

	/**
 	  Calculates time between the intersection of a moving point and a fixed
 	  triangle.

 	  @note This is only a one sided collision test.   The side defined by
 	  the triangle's surface normal is the only one tested.  For a two sided
 	  collision, call the function once for each side's surface normal.

 	  @param orig		Moving point.
 	  @param dir		Point's velocity.
	  @param v0 		Triangle vertex 1.
	  @param v1 		Triangle vertex 2.
	  @param v2 		Triangle vertex 3
 	  @param location	Location of collision. [Post Condition]
 	  					(Infinite vector on no collision)

 	  @return Time til collision.  If there is no collision then the return
 	          value will be inf().
 	*/
    inline static float collisionTimeForMovingPointFixedTriangle(
        const Vector3& orig,
        const Vector3& dir,
        const Vector3& v0,
        const Vector3& v1,
        const Vector3& v2,
        Vector3&       location) {
        float t = collisionTimeForMovingPointFixedTriangle(orig, dir, v0, v1, v2);
        if (t < finf()) {
            location = orig + dir * t;
        }
        return t;
    }

	/**
 	  Calculates time between the intersection of a moving point and a fixed
 	  triangle.

 	  @note This is only a one sided collision test.   The side defined by
 	  the triangle's surface normal is the only one tested.  For a two sided
 	  collision, call the function once for each side's surface normal.

 	  @param orig		Moving point.
 	  @param dir		Point's velocity.
 	  @param tri		Fixed triangle.
 	  @param location	Location of collision. [Post Condition]
 	  					(Infinite vector on no collision)
 	  @param normal		Triangle's surface normal. [Post Condition]

 	  @return Time til collision.  If there is no collision then the return
 	          value will be inf().
 	*/
    inline static float collisionTimeForMovingPointFixedTriangle(
        const Vector3&  orig,
        const Vector3&  dir,
        const Triangle& tri,
        Vector3&        location = ignore,
        Vector3&        normal   = ignore) {

        float t = collisionTimeForMovingPointFixedTriangle(
            orig, dir, tri.vertex(0), tri.vertex(1), tri.vertex(2));
        
        if ((t < finf()) && (&location != &ignore)) {
            location = orig + dir * t;
            normal   = tri.normal();
        }
        return t;
    }

	/**
 	  Calculates time between the intersection of a moving point and a fixed
 	  triangle.

 	  @note This is only a one sided collision test.   The side defined by
 	  the triangle's surface normal is the only one tested.  For a two sided
 	  collision, call the function once for each side's surface normal.

 	  @param orig		Moving point.
 	  @param dir		Point's velocity.
	  @param v0 		Triangle vertex 1.
	  @param v1 		Triangle vertex 2.
	  @param v2 		Triangle vertex 3
 	  @param location	Location of collision. [Post Condition]
 	  					(Infinite vector on no collision)
 	  @param normal		Triangle's surface normal. [Post Condition]

 	  @return Time til collision.  If there is no collision then the return
 	          value will be inf().
 	*/
    inline static float collisionTimeForMovingPointFixedTriangle(
        const Vector3& orig,
        const Vector3& dir,
        const Vector3& v0,
        const Vector3& v1,
        const Vector3& v2,
        Vector3&       location,
        Vector3&       normal) {
        float t = collisionTimeForMovingPointFixedTriangle(orig, dir, v0, v1, v2);
        if (t < finf()) {
            location = orig + dir * t;
            normal   = (v1 - v0).cross(v2 - v0).direction();
        }
        return t;
    }

    /**
     If the ray origin is inside the box, returns inf() but inside
     is set to true.
     <B>Beta API</B>

     @cite Andrew Woo, from "Graphics Gems", Academic Press, 1990
  	 @cite Optimized code by Pierre Terdiman, 2000 (~20-30% faster on Celeron 500)
     @cite Epsilon value added by Klaus Hartmann
     @cite http://www.codercorner.com/RayAABB.cpp
     */
    static float collisionTimeForMovingPointFixedAABox(
        const Vector3&			point,
        const Vector3&			velocity,
        const class AABox&      box,
        Vector3&				outLocation,
        bool&                   inside = ignoreBool,
        Vector3&                outNormal = ignore);

    /**
	 Calculates time between the intersection of a moving point and a fixed
	 Axis-Aligned Box (AABox).

	 @note Avoids the sqrt from collisionTimeForMovingPointFixedAABox.

	 @param point		Moving point.
	 @param velocity	Sphere's velocity.
	 @param box			Fixed AAbox.
	 @param location	Location of collision. [Post Condition]
	 @param Inside		Does the ray originate inside the box? [Post Condition]
	 @param normal		Box's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static bool collisionLocationForMovingPointFixedAABox(
        const Vector3&			point,
        const Vector3&			velocity,
        const class AABox&      box,
        Vector3&				outLocation,
        bool&                   inside = ignoreBool,
        Vector3&                normal = ignore);


    /**
     @brief Calculates intersection of a ray and a static
     Axis-Aligned Box (AABox).

     @note Avoids the sqrt from collisionTimeForMovingPointFixedAABox; 
      early-out branches and operations optimized for Intel Core2 architecture.
     
     @param invDir      1/dir
     @param location	Location of collision. [Post Condition]
     @param inside		Does the ray originate inside the box? [Post Condition]

     @return True if the ray hits the box
    */
    static bool __fastcall rayAABox(
        const Ray&              ray,
        const Vector3&          invDir,
        const AABox&            box,
        const Vector3&          boxCenter,
        float                   boundingRadiusSquared,
        Vector3&                location,
        bool&                   inside);

    /**
	 Calculates time between the intersection of a moving point and a fixed
	 sphere.

	 @note When ray is starts inside the rectangle, the exiting intersection
	 is detected.

	 @param point		Moving point.
	 @param velocity	Point's velocity.
	 @param sphere		Fixed Sphere.
	 @param outLocation	Location of collision. [Post Condition]
	 @param outNormal	Sphere's surface normal to collision [Post Condition]
     \param solid If true, rays inside the sphere immediately intersect (good for collision detection).  If false, they hit the opposite side of the sphere (good for ray tracing).

	 @return Time until collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static float collisionTimeForMovingPointFixedSphere(
        const Vector3&			point,
        const Vector3&			velocity,
        const class Sphere&		sphere,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore,
        bool                    solid = false);

    /**
	 Calculates time between the intersection of a moving point and a fixed
	 box.

	 @note If the point is already inside the box, no collision: inf is returned.

	 @param point		Moving point.
	 @param velocity	Sphere's velocity.
	 @param box			Fixed box.
	 @param location	Position of collision. [Post Condition]
	 @param outNormal	Box's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static float collisionTimeForMovingPointFixedBox(
        const Vector3&			point,
        const Vector3&			velocity,
        const class  Box&		box,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
	 Calculates time between the intersection of a moving point and a fixed
	 rectangle defined by the points v0, v1, v2, & v3.

	 @note This is only a one sided collision test.   The side defined by
	 the rectangle's surface normal is the only one tested.  For a two sided
	 collision, call the function once for each side's surface normal.

	 @param point		Moving point.
	 @param velocity	Sphere's velocity.
	 @param v0 			Rectangle vertex 1.
	 @param v1 			Rectangle vertex 2.
	 @param v2 			Rectangle vertex 3
	 @param v3 			Rectangle vertex 4.
	 @param location	Location of collision [Post Condition]
	 @param outNormal	Rectangle's surface normal. [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static float collisionTimeForMovingPointFixedRectangle(
        const Vector3&			point,
        const Vector3&			velocity,
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			v3,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
	 Calculates time between the intersection of a moving point and a fixed
	 capsule.

	 @param point		Moving point.
	 @param velocity	Point's velocity.
	 @param capsule		Fixed capsule.
	 @param outLocation	Location of collision. [Post Condition]
	 @param outNormal	Capsule's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
	static float collisionTimeForMovingPointFixedCapsule(
		const Vector3&		    point,
		const Vector3&		    velocity,
		const class Capsule&	capsule,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
	 Calculates time between the intersection of a moving sphere and a fixed
	 triangle.

	 @param sphere		Moving sphere.
	 @param velocity	Sphere's velocity.
	 @param plane		Fixed Plane.
	 @param outLocation	Location of collision -- not center position of sphere
	 					at the collision time. [Post Condition]
	 @param outNormal	Box's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
	 */
    static float collisionTimeForMovingSphereFixedPlane(
        const class Sphere&		sphere,
        const Vector3&	    	velocity,
        const class Plane&		plane,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
	 Calculates time between the intersection of a moving sphere and a fixed
	 triangle.

	 @param sphere		Moving sphere.
	 @param velocity	Sphere's velocity.
	 @param triangle	Fixed Triangle.  (collisions can happen on the back side of the triangle)
	 @param outLocation	Location of collision, if collision occurs -- not center position of sphere
	 					at the collision time. If there is interpenetration at the start, this point may be inside
                        the sphere.
     @param b           Barycentric coordinates. These are not valid unless collision occurs.

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
	*/
    static float collisionTimeForMovingSphereFixedTriangle(
        const class Sphere&		sphere,
        const Vector3&		    velocity,
        const Triangle&         triangle,
        Vector3&				outLocation,
        float                   b[3] = (float*)&ignore);

	/**
	 Calculates time between the intersection of a moving sphere and a fixed
	 rectangle defined by the points v0, v1, v2, & v3.

	 @param sphere		Moving sphere.
	 @param velocity	Sphere's velocity.
	 @param v0 			Rectangle vertex 1.
	 @param v1 			Rectangle vertex 2.
	 @param v2 			Rectangle vertex 3
	 @param v3 			Rectangle vertex 4.
	 @param outLocation	Location of collision -- not center position of sphere
	 					at the collision time. [Post Condition]
	 @param outNormal	Box's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static float collisionTimeForMovingSphereFixedRectangle(
        const class Sphere&		sphere,
        const Vector3&	    	velocity,
        const Vector3&	    	v0,
        const Vector3&	    	v1,
        const Vector3&	    	v2,
        const Vector3&	    	v3,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

	/**
	 Calculates time between the intersection of a moving sphere and a fixed
	 box.

	 @note This function will not detect an intersection between a moving object
	 that is already interpenetrating the fixed object.

	 @param sphere		Moving sphere.
	 @param velocity	Sphere's velocity.
	 @param box			Fixed box.
	 @param location	Location of collision -- not center position of sphere
	 					at the collision time. [Post Condition]
	 @param outNormal	Box's surface normal to collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
    static float collisionTimeForMovingSphereFixedBox(
        const class Sphere&		sphere,
        const Vector3&		    velocity,
        const class Box&		box,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

    /** Calculates time between the intersection of a moving sphere
        and a fixed sphere. 

        If they are already interpenetrating, returns 0 and @a
        location is the closest point on the surface of the fixed sphere
        to the center of the moving sphere.
        
        @param sphere	        Moving sphere.
        @param velocity         Sphere's velocity.
        @param fixedSphere	    Fixed Sphere.
        @param outLocation	    Location of collision -- not center position of sphere
        at the collision time. [Post Condition]
        @param outNormal	    Moving sphere's surface normal to collision [Post Condition]
        
        @return Time until collision.  If there is no collision then the return
        value will be inf().
    */
    static float collisionTimeForMovingSphereFixedSphere(
        const Sphere&	    sphere,
        const Vector3&		velocity,
        const Sphere&	    fixedSphere,
        Vector3&	        outLocation,
        Vector3&            outNormal = ignore);

    /**
	 Calculates time between the intersection of a moving sphere and a fixed
	 capsule.

	 @note This won't detect a collision if the sphere is already
	       interpenetrating the capsule.

	 @param sphere		Moving sphere.
	 @param velocity	Sphere's velocity.
	 @param capsule		Fixed capsule.
	 @param location	Location of collision -- not center position of sphere
	 					at the collision time. [Post Condition]
	 @param outNormal	Capsule's surface normal to the collision [Post Condition]

	 @return Time til collision.  If there is no collision then the return
	         value will be inf().
 	*/
	static float collisionTimeForMovingSphereFixedCapsule(
		const class Sphere&		sphere,
		const Vector3&		    velocity,
		const class Capsule&	capsule,
        Vector3&				outLocation,
        Vector3&                outNormal = ignore);

    /**
	 Finds the direction of bounce that a sphere would have when it 
	 intersects an object with the  given time of collision, the 
	 collision location and the collision normal.

	 @note This function works like a pong style ball bounce.

	 @param sphere				Moving sphere.
	 @param velocity			Sphere's velocity.
	 @param collisionTime		Time of collision.
	 @param collisionLocation	Collision location.
	 @param collisionNormal		Surface collision normal.

	 @return Direction of bounce.
 	*/
    static Vector3 bounceDirection(
        const class Sphere&		sphere,
        const Vector3&			velocity,
        const float				collisionTime,
        const Vector3&			collisionLocation,
        const Vector3&          collisionNormal);

    /**
	 Finds the direction of slide given a moving sphere, its velocity, the
	 time of collision and the collision location.  This function works as
	 if the sphere intersects the surface and continues to hug it.

	 @note The result will work well for calculating the movement of a player
	 who collides with an object and continues moving along the object instead
	 of just bouncing off it.

	 @param sphere				Moving sphere.
	 @param velocity			Sphere's velocity.
	 @param collisionTime		Time of collision
	 @param collisionLocation	Collision location.

	 @return Direction of slide.
 	*/
    static Vector3 slideDirection(
        const class Sphere&		sphere,
        const Vector3&			velocity,
        const float				collisionTime,
        const Vector3&			collisionLocation);

	/**
	 Finds the closest point on a line segment to a given point.

	 @param v0 line vertex 1.
	 @param v1 line vertex 2.
	 @param point External point.

	 @return Closests point to <code>point</code> on the line segment.
 	*/
	static Vector3 closestPointOnLineSegment(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			point);

    /**
	 Finds the closest point on a line segment to a given point.

	 @note This is an optimization to closestPointOnLineSegment.  Edge length
	 and direction can be used in this function if already pre-calculated.  This
	 prevents doing the same work twice.

	 @param v0 line vertex 0.
	 @param v1 line vertex 1.
     @param edgeDirection The direction of the segment (unit length).
     @param edgeLength The length of the segment.
     @param point External point.

	 @return Closests point to <code>point</code> on the line segment.
 	*/
    static Vector3 closestPointOnLineSegment(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&          edgeDirection,
        float                   edgeLength,
        const Vector3&			point);

    /**
	 Finds the closest point on the perimeter of the triangle to an external point;
	 given a triangle defined by three points v0, v1, & v2, and the external point.

	 @param v0 Triangle vertex 0.
	 @param v1 Triangle vertex 1.
	 @param v2 Triangle vertex 2.
	 @param point External point.

	 @return Closests point to <code>point</code> on the perimeter of the
	 triangle.
 	*/
    static Vector3 closestPointOnTrianglePerimeter(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			point);

	/**
	 Finds the closest point on the perimeter of the triangle to an external point;
	 given a triangle defined by the array of points v, its edge directions and
	 their lengths, as well as the external point.

	 @note This is an optimization to closestPointToTrianglePerimeter.  Edge length
	 and direction can be used in this function if already pre-calculated.  This
	 prevents doing the same work twice.

	 @param v           Triangle vertices.
	 @param point       External point.
     @param edgeIndex   The point lies on the edge between v[edgeIndex] and v[(edgeIndex + 1) % 3]

	 @return Closest point to <code>point</code> on the perimeter of the
	 triangle.
 	*/
    static Vector3 closestPointOnTrianglePerimeter(
        const Vector3           v[3],
        const Vector3           edgeDirection[3],
        const float             edgeLength[3],
        const Vector3&			point,
        int&                    edgeIndex);

    /**
	 Tests whether a point is contained within the triangle defined by
	 v0, v1, and v2 and its plane's normal.

	 @param v0 Triangle vertex 0.
	 @param v1 Triangle vertex 1.
	 @param v2 Triangle vertex 2.
	 @param normal Normal to triangle's plane.
	 @param point The point in question.
	 @param primaryAxis Primary axis of triangle.  This will be detected
	        if not given. This parameter is provided as an optimization.
     @param b Barycentric coordinates; b[i] is the weight on v[i]

	 @return true  - if point is inside the triangle.
	 @return false - otherwise
 	*/
    static bool isPointInsideTriangle(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			normal,
        const Vector3&          point,
        float                   b[3],
        Vector3::Axis           primaryAxis = Vector3::DETECT_AXIS);

    inline static bool isPointInsideTriangle(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			normal,
        const Vector3&			point,
        Vector3::Axis           primaryAxis = Vector3::DETECT_AXIS) {

        float b[3];
        return isPointInsideTriangle(v0, v1, v2, normal, point, b, primaryAxis);
    }

     /**
	  Tests for the intersection of a moving sphere and a fixed box in a
	  given time limit.

	  @note Returns true if any part of the sphere is inside the box
     		during the time period (inf means "ever").  Useful for
		    performing bounding-box collision detection.

	  @param sphere 		Moving sphere.
	  @param velocity 	Velocity of moving sphere.
	  @param box 		Fixed box.
	  @param timeLimit 	Time limit for intersection test.

	  @return true  -  if the two objects will touch.
	  @return false - if there is no intersection.
 	*/
    static bool movingSpherePassesThroughFixedBox(
        const Sphere&           sphere,
        const Vector3&          velocity,
        const Box&              box,
        double                  timeLimit = inf());

	/**
	 Tests for the intersection of a moving sphere and a fixed sphere in a
	 given time limit.

	 @note This function will not detect an intersection between a moving object
	 that is already interpenetrating the fixed object.

	 @param sphere 		Moving sphere.
	 @param velocity 	Velocity of moving sphere.
	 @param fixedSphere Fixed sphere.
	 @param timeLimit 	Time limit for intersection test.

	 @return true  -  if the two spheres will touch.
	 @return false - if there is no intersection.
 	*/
    static bool movingSpherePassesThroughFixedSphere(
        const Sphere&           sphere,
        const Vector3&          velocity,
        const Sphere&           fixedSphere,
        double                  timeLimit = inf());

	/**
	 Tests for the intersection of two fixed spheres.

	 @param sphere1 Fixed sphere 1.
	 @param sphere2 Fixed sphere 2.

	 @return true -  if the two spheres touch.
	 @return false - if there is no intersection.
 	*/
    static bool fixedSolidSphereIntersectsFixedSolidSphere(
        const Sphere&           sphere1,
        const Sphere&           sphere2);

	/**
	 Tests for the intersection of a fixed sphere and a fixed box.

	 @param sphere Fixed sphere.
	 @param box    Fixed box.

	 @return true  -  if the two objects touch.
	 @return false - if there is no intersection.
 	*/
    static bool fixedSolidSphereIntersectsFixedSolidBox(
        const Sphere&           sphere,
        const Box&              box);

    static bool fixedSolidSphereIntersectsFixedTriangle(
        const Sphere&           sphere,
        const Triangle&         triangle);

    static bool fixedSolidBoxIntersectsFixedTriangle(
        const AABox&            box, 
        const Triangle&         triangle);

    /**
	 Tests whether a point is inside a rectangle defined by the vertexes
	 v0, v1, v2, & v3, and the rectangle's plane normal.

	 @param v0 Rectangle vertex 1.
	 @param v1 Rectangle vertex 2.
	 @param v2 Rectangle vertex 3.
	 @param v3 Rectangle vertex 4.
	 @param normal Normal to rectangle's plane.
	 @param point The point in question.

	 @return true  - if point is inside the rectangle.
	 @return false - otherwise
 	*/
    static bool isPointInsideRectangle(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			v3,
        const Vector3&			normal,
        const Vector3&			point);

    /**
	 Finds the closest point on the perimeter of the rectangle to an
	 external point; given a rectangle defined by four points v0, v1,
	 v2, & v3, and the external point.

	 @param v0 Rectangle vertex 1.
	 @param v1 Rectangle vertex 2.
	 @param v2 Rectangle vertex 3.
	 @param v3 Rectangle vertex 4.
	 @param point External point.

	 @return Closests point to <code>point</code> on the perimeter of the
 	 rectangle.
 	 */
    static Vector3 closestPointToRectanglePerimeter(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			v3,
        const Vector3&			point);

     /**
	  Finds the closest point in the rectangle to an external point; Given
	  a rectangle defined by four points v0, v1, v2, & v3, and the external
	  point.

	  @param v0 Rectangle vertex 1.
	  @param v1 Rectangle vertex 2.
	  @param v2 Rectangle vertex 3
	  @param v3 Rectangle vertex 4.
	  @param point External point.

      @return Closet point in the rectangle to the external point.
	  */
	 static Vector3 closestPointToRectangle(
        const Vector3&			v0,
        const Vector3&			v1,
        const Vector3&			v2,
        const Vector3&			v3,
        const Vector3&			point);
};

} // namespace

#endif // G3D_COLLISIONDETECTION_H
