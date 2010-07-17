/**
 @file Sphere.h
 
 Sphere class
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2001-06-02
 @edited  2008-10-07
 */

#ifndef G3D_SPHERE_H
#define G3D_SPHERE_H

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Array.h"
#include "G3D/Sphere.h"

namespace G3D {

/**
 Sphere.
 */
class Sphere {
private:

    static int32     dummy;

public:
    Vector3          center;
    float            radius;

    Sphere() {
        center = Vector3::zero();
        radius = 0;
    }

    Sphere(class BinaryInput& b);
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    Sphere(
        const Vector3&  center,
        float           radius) {

        this->center = center;
        this->radius = radius;
    }

    virtual ~Sphere() {}

    bool operator==(const Sphere& other) const {
        return (center == other.center) && (radius == other.radius);
    }

    bool operator!=(const Sphere& other) const {
        return !((center == other.center) && (radius == other.radius));
    }

    /**
     Returns true if point is less than or equal to radius away from
     the center.
     */
    bool contains(const Vector3& point) const;

    /**
       @deprecated Use culledBy(Array<Plane>&)
     */
    bool culledBy(
                  const class Plane*  plane,
                  int                 numPlanes,
                  int32&	      cullingPlaneIndex,
                  const uint32        testMask,
                  uint32&             childMask) const;
    
    /**
       @deprecated Use culledBy(Array<Plane>&)
     */
    bool culledBy(
                  const class Plane*  plane,
                  int                 numPlanes,
                  int32&              cullingPlaneIndex = dummy,
                  const uint32        testMask = 0xFFFFFFFF) const;

    /**
       See AABox::culledBy
    */
    bool culledBy(
                  const Array<Plane>&		plane,
                  int32&					cullingPlaneIndex,
                  const uint32  			testMask,
                  uint32&                 childMask) const;
    
    /**
     Conservative culling test that does not produce a mask for children.
     */
    bool culledBy(
                  const Array<Plane>&		plane,
                  int32&					cullingPlaneIndex = dummy,
                  const uint32  			testMask		  = 0xFFFFFFFF) const;

    virtual std::string toString() const;

    float volume() const;

    float area() const;

    /**
     Uniformly distributed on the surface.
     */
    Vector3 randomSurfacePoint() const;

    /**
     Uniformly distributed on the interior (includes surface)
     */
    Vector3 randomInteriorPoint() const;

    void getBounds(class AABox& out) const;

    bool intersects(const Sphere& other) const;

    /** Translates the sphere */
    Sphere operator+(const Vector3& v) const {
        return Sphere(center + v, radius);
    }

    /** Translates the sphere */
    Sphere operator-(const Vector3& v) const {
        return Sphere(center - v, radius);
    }
};

}

template <> struct HashTrait<G3D::Sphere> {
    static size_t hashCode(const G3D::Sphere& key) { 
        return static_cast<size_t>(key.center.hashCode() + (key.radius * 13));
    }
};


#endif
