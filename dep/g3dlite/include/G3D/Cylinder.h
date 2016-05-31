/**
 @file Cylinder.h
  
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  
 @created 2003-02-07
 @edited  2005-09-26

 Copyright 2000-2005, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_Cylinder_H
#define G3D_Cylinder_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"

namespace G3D {

class Line;
class AABox;
/**
 Right cylinder
 */
class Cylinder {
private:
    Vector3            p1;
    Vector3            p2;

    float           mRadius;

public:

    /** Uninitialized */
    Cylinder();
    Cylinder(class BinaryInput& b);
    Cylinder(const Vector3& _p1, const Vector3& _p2, float _r);
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);
    
    /** The line down the center of the Cylinder */
    Line axis() const;

    /** 
      A reference frame in which the center of mass is at the origin and
      the Y-axis is the cylinder's axis.  If the cylinder is transformed, this reference frame
      may freely rotate around its axis.*/
    void getReferenceFrame(class CoordinateFrame& cframe) const;

    /** Returns point 0 or 1 */
    inline const Vector3& point(int i) const {
        debugAssert(i >= 0 && i <= 1);
        return (i == 0) ? p1 : p2;
    }

    /**
     Returns true if the point is inside the Cylinder or on its surface.
     */
    bool contains(const Vector3& p) const;

    float area() const;

    float volume() const;

    float radius() const; 

    /** Center of mass */
    inline Vector3 center() const {
        return (p1 + p2) / 2.0f;
    }

    inline float height() const {
        return (p1 - p2).magnitude();
    }

    /**
     Get close axis aligned bounding box.
     With vertical world orientation, the top and bottom might not be very tight. */
    void getBounds(AABox& out) const;

    /** Random world space point with outward facing normal. */
    void getRandomSurfacePoint(Vector3& P, Vector3& N) const;

    /** Point selected uniformly at random over the volume. */
    Vector3 randomInteriorPoint() const;
};

} // namespace

#endif
