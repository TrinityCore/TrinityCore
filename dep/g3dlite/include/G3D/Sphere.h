/**
 \file G3D/Sphere.h
 
 Sphere class
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2001-06-02
 \edited  2011-02-07
 */

#ifndef G3D_Sphere_h
#define G3D_Sphere_h

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Array.h"

namespace G3D {

/**
 Sphere.
 */
class Sphere {
private:

    static int32     dummy;

public:
    Point3           center;
    float            radius;

    Sphere() : center(Point3::zero()), radius(0) {
    }

    explicit Sphere(float radius) : radius(radius) {}

    Sphere(class BinaryInput& b);
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    /** Format is one of:
        - Sphere(point, radius)
        - Sphere(radius)
    */
    explicit Sphere(const class Any& a);

    Any toAny() const;

    Sphere
    (const Point3&  center,
     float          radius) : center(center), radius(radius) {
    }

    virtual ~Sphere() {}

    /** Returns the infinite sphere. */
    static const Sphere& inf();

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
    bool contains(const Point3& point) const;

    bool contains(const Sphere& other) const;

    /**
       @deprecated Use culledBy(Array<Plane>&)
     */
    bool culledBy(
                  const class Plane*  plane,
                  int                 numPlanes,
                  int32&              cullingPlaneIndex,
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
                  const Array<Plane>&        plane,
                  int32&                    cullingPlaneIndex,
                  const uint32              testMask,
                  uint32&                 childMask) const;
    
    /**
     Conservative culling test that does not produce a mask for children.
     */
    bool culledBy(
                  const Array<Plane>&        plane,
                  int32&                    cullingPlaneIndex = dummy,
                  const uint32              testMask          = 0xFFFFFFFF) const;

    virtual std::string toString() const;

    float volume() const;

    float area() const;

    /**
     Uniformly distributed on the surface.
     */
    Point3 randomSurfacePoint() const;

    /**
     Uniformly distributed on the interior (includes surface)
     */
    Point3 randomInteriorPoint() const;

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

    /** Sets this to the smallest sphere that encapsulates both */
    void merge(const Sphere& s);
};

}

template <> struct HashTrait<G3D::Sphere> {
    static size_t hashCode(const G3D::Sphere& key) { 
        return static_cast<size_t>(key.center.hashCode() + (key.radius * 13));
    }
};


#endif
