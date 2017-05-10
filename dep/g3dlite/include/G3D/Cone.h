/**
 @file Cone.h
 
 Cone class
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @cite Portions based on Dave Eberly's Magic Software Library at <A HREF="http://www.magic-software.com">http://www.magic-software.com</A>
  
 @created 2001-06-02
 @edited  2006-02-23

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_CONE_H
#define G3D_CONE_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"

namespace G3D {

/**
 An infinite cone.
 */
class Cone {

private:
    Vector3         tip;
    Vector3         direction;

    /** Angle from the center line to the edge. */
    float            angle;

public:

    /**
     @param angle Angle from the center line to the edge, in radians
     */
    Cone(const Vector3& tip, const Vector3& direction, float angle);

    /**
     Forms the smallest cone that contains the box.  Undefined if
     the tip is inside or on the box.
     */
    Cone(const Vector3& tip, const class Box& box);

    virtual ~Cone() {}

    /**
     Returns true if the cone touches, intersects, or contains b.

     If c.intersects(s) and c.intersects(Sphere(s.center, s.radius * 2)
     then the sphere s is entirely within cone c.
     */
    bool intersects(const class Sphere& s) const;

    /**
     True if v is a point inside the cone.
     */
    bool contains(const class Vector3& v) const;


    /** Returns the solid angle (in steradians) subtended by a cone with half-angle \a halfAngle  */
    static float solidAngleFromHalfAngle(float halfAngle);
    static double solidAngleFromHalfAngle(double halfAngle);

    /** Returns the half-angle (in radians) of a cone that subtends \a solidAngle (in steradians) */
    static float halfAngleFromSolidAngle(float solidAngle);
    static double halfAngleFromSolidAngle(double solidAngle);


    Vector3 randomDirectionInCone(Random& rng) const;

};

} // namespace

#endif
