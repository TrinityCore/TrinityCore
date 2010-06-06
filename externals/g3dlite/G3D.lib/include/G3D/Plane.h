/**
 @file Plane.h

 Plane class

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2001-06-02
 @edited  2004-07-18
*/

#ifndef G3D_PLANE_H
#define G3D_PLANE_H

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/debugAssert.h"

namespace G3D {

/**
 An infinite 2D plane in 3D space.
 */
class Plane {
private:

    /** normal.Dot(x,y,z) = distance */
    Vector3						_normal;
    float						_distance;

    /**
     Assumes the normal has unit length.
     */
    Plane(const Vector3& n, float d) : _normal(n), _distance(d) {
    }

public:

    Plane() : _normal(Vector3::unitY()), _distance(0) {
    }

    /**
     Constructs a plane from three points.
     */
    Plane(
        const Vector3&      point0,
        const Vector3&      point1,
        const Vector3&      point2);

    /**
     Constructs a plane from three points, where at most two are
     at infinity (w = 0, not xyz = inf).
     */
    Plane(
        Vector4             point0,
        Vector4             point1,
        Vector4             point2);

    /**
     The normal will be unitized.
     */
    Plane(
        const Vector3&      __normal,
        const Vector3&      point);

    static Plane fromEquation(float a, float b, float c, float d);

	Plane(class BinaryInput& b);
	void serialize(class BinaryOutput& b) const;
	void deserialize(class BinaryInput& b);

    virtual ~Plane() {}

    /**
     Returns true if point is on the side the normal points to or 
     is in the plane.
     */
    inline bool halfSpaceContains(Vector3 point) const {
        // Clamp to a finite range for testing
        point = point.clamp(Vector3::minFinite(), Vector3::maxFinite());

        // We can get away with putting values *at* the limits of the float32 range into
        // a dot product, since the dot product is carried out on float64.
        return _normal.dot(point) >= _distance;
    }

    /**
     Returns true if point is on the side the normal points to or 
     is in the plane.
     */
    inline bool halfSpaceContains(const Vector4& point) const {
        if (point.w == 0) {
            return _normal.dot(point.xyz()) > 0;
        } else {
            return halfSpaceContains(point.xyz() / point.w);
        }
    }

    /**
     Returns true if point is on the side the normal points to or 
     is in the plane.  Only call on finite points.  Faster than halfSpaceContains.
     */
    inline bool halfSpaceContainsFinite(const Vector3& point) const {
        debugAssert(point.isFinite());
        return _normal.dot(point) >= _distance;
    }

    /**
     Returns true if the point is nearly in the plane.
     */
    inline bool fuzzyContains(const Vector3 &point) const {
        return fuzzyEq(point.dot(_normal), _distance);
    }

	inline const Vector3& normal() const {
		return _normal;
	}

    /**
      Returns distance from point to plane. Distance is negative if point is behind (not in plane in direction opposite normal) the plane.
    */
    inline float distance(const Vector3& x) const {
        return (_normal.dot(x) - _distance);
    }

    inline Vector3 closestPoint(const Vector3& x) const {
        return x + (_normal * (-distance(x)));
    }

    /** Returns normal * distance from origin */
    Vector3 center() const {
        return _normal * _distance;
    }

    /**
     Inverts the facing direction of the plane so the new normal
     is the inverse of the old normal.
     */
    void flip();

    /**
      Returns the equation in the form:

      <CODE>normal.Dot(Vector3(<I>x</I>, <I>y</I>, <I>z</I>)) + d = 0</CODE>
     */
    void getEquation(Vector3 &normal, double& d) const;
    void getEquation(Vector3 &normal, float& d) const;

    /**
      ax + by + cz + d = 0
     */
    void getEquation(double& a, double& b, double& c, double& d) const;
    void getEquation(float& a, float& b, float& c, float& d) const;

    std::string toString() const;
};

} // namespace

#endif
