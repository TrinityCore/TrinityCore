/**
  \file G3D/AABox.h
 
  Axis-aligned box class
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \created 2004-01-10
  \edited  2013-04-13

  Copyright 2000-2013, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_AABox_h
#define G3D_AABox_h

#include "G3D/platform.h"
#include "G3D/debug.h"
#include "G3D/Array.h"
#include "G3D/Plane.h"
#include "G3D/Sphere.h"
#include "G3D/Vector3.h"

namespace G3D {

class Any;

/**
 An axis-aligned box.
 */
class AABox {
private:
    friend class Intersect;

    /** Optional argument placeholder */
    static int dummy;

    /** NaN if empty */
    Point3  lo;

    /** NaN if empty */
    Point3  hi;

public:

    /** Creates the empty bounds, i.e., an empty set of points. */
    AABox() : lo(fnan(), fnan(), fnan()), hi(fnan(), fnan(), fnan()) {}

    /**
     Constructs a zero-volume AABox at v.
     */
    explicit AABox(const Point3& v) {
        lo = hi = v;
    }

    /** Format is one of:
       - AABox(lowpoint, highpoint)
       - AABox(point)
       - AABox::empty()
       - AABox::inf()
    */
    explicit AABox(const class Any& a);

    Any toAny() const;
    
    bool isEmpty() const {
        return lo.isNaN();
    }

    /** Assumes that low is less than or equal to high along each dimension.
        To have this automatically enforced, use
        <code>AABox(low.min(high), low.max(high));</code>
    */
    AABox(const Point3& low, const Point3& high) {
        set(low, high);
    }

    AABox operator*(float f) const {
        if (f < 0) {
            return AABox(hi * f, lo * f);
        } else {
            return AABox(lo * f, hi * f);
        }
    }

    AABox operator/(float f) const {
        return *this * (1.0f / f);
    }

    /** Assumes that low is less than or equal to high along each dimension.
    */
    inline void set(const Point3& low, const Point3& high) {
        debugAssert(
            (low.x <= high.x) &&
            (low.y <= high.y) &&
            (low.z <= high.z));
        debugAssert(! low.isNaN() && ! high.isNaN());
        lo = low;
        hi = high;
    }

    /**
     Grows to include the bounds of \a a
     */
    inline void merge(const AABox& a) {
        if (isEmpty()) {
            lo = a.lo;
            hi = a.hi;
        } else if (! a.isEmpty()) {
            lo = lo.min(a.lo);
            hi = hi.max(a.hi);
        }
    }

    inline void merge(const Point3& a) {
        if (isEmpty()) {
            lo = hi = a;
        } else {
            lo = lo.min(a);
            hi = hi.max(a);
        }
    }

    void merge(const class Box& b);

    void serialize(class BinaryOutput& b) const;
    
    void deserialize(class BinaryInput& b);

    inline bool isFinite() const {
        return isEmpty() || (lo.isFinite() && hi.isFinite());
    }

    /** Returns not-a-number if empty */
    inline const Point3& low() const {
        return lo;
    }

    /** Returns not-a-number if empty */
    inline const Point3& high() const {
        return hi;
    }

    /**
     The largest possible finite box.
     */
    static const AABox& maxFinite();

    /** A large finite box. This is smaller than FLT_MAX
        because it leaves room to add boxes together. */
    static const AABox& large();

    static const AABox& inf();

    static const AABox& zero();

    static const AABox& empty();

    /**
      Returns the centroid of the box (NaN if empty)
     */
    inline Point3 center() const {
        return (lo + hi) * 0.5;
    }

    Point3 corner(int index) const;

    /**
     Distance from corner(0) to the next corner along axis a.
     */
    inline float extent(int a) const {
        if (isEmpty()) {
            return 0.0f;
        }
        debugAssert(a < 3);
        return hi[a] - lo[a];
    }


    inline Vector3 extent() const {
        if (isEmpty()) {
            return Vector3::zero();
        }
        return hi - lo;
    }


    /**
     Splits the box into two AABoxes along the specified axis.  low contains
     the part that was closer to negative infinity along axis, high contains
     the other part.  Either may have zero volume.
     */
    void split(const Vector3::Axis& axis, float location, AABox& low, AABox& high) const;

    /**
     Conservative culling test for up to 32 planes.    
     Returns true if there exists a <CODE>plane[p]</CODE> for
     which the entire object is in the negative half space
     (opposite the plane normal).

     <CODE>testMask</CODE> and <CODE>childMask</CODE>
     are used for optimizing bounding volume hierarchies.
     The version of this method that produces childMask
     is slower than the version without; it should only
     be used for parent nodes.

     @param cullingPlaneIndex The index of the first plane for which
      the entire object is in the negative half-space.  The function
      exits early when one plane is found.  -1 when the function
      returns false (i.e. when no plane culls the whole object).

     @param testMask  If bit <I>p</I> is 0, the 
       bounding volume automatically passes the culling test for
       <CODE>plane[p]</CODE> (i.e. it is known that the volume
       is entirely within the positive half space).  The function
       must return false if testMask is 0 and test all planes
       when testMask is -1 (0xFFFFFFFF).

     @param childMask Test mask for the children of this volume.
       
     */
    bool culledBy
    (const Array<Plane>&    plane,
     int32&            cullingPlaneIndex,
     const uint32          testMask,
     uint32&                    childMask) const;

    /**
     Conservative culling test that does not produce a mask for children.
     */
    bool culledBy
    (const Array<Plane>&        plane,
     int32&                        cullingPlaneIndex = dummy,
     const uint32               testMask  = 0xFFFFFFFF) const;

    /** less than or equal to containment */
    inline bool contains(const AABox& other) const {
        return 
            (other.hi.x <= hi.x) &&
            (other.hi.y <= hi.y) &&
            (other.hi.z <= hi.z) &&
            (other.lo.x >= lo.x) &&
            (other.lo.y >= lo.y) &&
            (other.lo.z >= lo.z);
    }

    inline bool contains(const Point3& point) const {
        return
            (point.x >= lo.x) &&
            (point.y >= lo.y) &&
            (point.z >= lo.z) &&
            (point.x <= hi.x) &&
            (point.y <= hi.y) &&
            (point.z <= hi.z);
    }

    inline float area() const {
        if (isEmpty()) { return 0; }
        Vector3 diag = hi - lo;
        return 2.0f * (diag.x * diag.y + diag.y * diag.z + diag.x * diag.z);
    }

    inline float volume() const {
        if (isEmpty()) { return 0; }
        Vector3 diag = hi - lo;
        return diag.x * diag.y * diag.z;
    }

    Point3 randomInteriorPoint() const;

    Point3 randomSurfacePoint() const;

    /** Returns true if there is any overlap */
    bool intersects(const AABox& other) const;

    /** Returns true if there is any overlap.
        @cite Jim Arvo's algorithm from Graphics Gems II*/
    bool intersects(const Sphere& other) const;

    /** Return the intersection of the two boxes */
    AABox intersect(const AABox& other) const {
        if (isEmpty() || other.isEmpty()) {
            return empty();
        }

        const Point3& H = hi.min(other.hi);
        const Point3& L = lo.max(other.lo).min(H);

        if (H.x < L.x && H.y < L.y && H.z < L.z) {
            return empty();
        } else {
            return AABox(L, H);
        }
    }

    inline size_t hashCode() const {
        return lo.hashCode() + hi.hashCode();
    }

    inline bool operator==(const AABox& b) const {
        if (isEmpty() && b.isEmpty()) {
            return true;
        } else {
            return (lo == b.lo) && (hi == b.hi);
        }
    }

    inline bool operator!=(const AABox& b) const {
        if (isEmpty()) {
            return b.isEmpty();
        } else {
            return !((lo == b.lo) && (hi == b.hi));
        }
    }

    inline AABox operator+(const Vector3& v) const {
        AABox out;
        out.lo = lo + v;
        out.hi = hi + v;
        return out;
    }

    inline AABox operator-(const Vector3& v) const {
        AABox out;
        out.lo = lo - v;
        out.hi = hi - v;
        return out;
    }

    void getBounds(AABox& out) const {
        out = *this;
    }

    void getBounds(Sphere& out) const;
};

}

template <> struct HashTrait<G3D::AABox> {
    static size_t hashCode(const G3D::AABox& key) { return key.hashCode(); }
};



#endif
