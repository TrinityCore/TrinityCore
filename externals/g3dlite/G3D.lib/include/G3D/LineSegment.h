/**
 @file LineSegment.h
  
 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2003-02-08
 @edited  2008-02-02
 */

#ifndef G3D_LINESEGMENT_H
#define G3D_LINESEGMENT_H

#include "G3D/platform.h"
#include "G3D/Vector3.h"

namespace G3D {

/**
 An finite segment of an infinite 3D line.
 */
class LineSegment {
protected:

    Vector3             _point;

    /** Not normalized */
    Vector3             direction;

    LineSegment(const Vector3& __point, const Vector3& _direction) : _point(__point), direction(_direction) {
    }

public:

    inline LineSegment() : _point(Vector3::zero()), direction(Vector3::zero()) {}

	LineSegment(class BinaryInput& b);

	void serialize(class BinaryOutput& b) const;

	void deserialize(class BinaryInput& b);

    virtual ~LineSegment() {}

    /**
     * Constructs a line from two (not equal) points.
     */
    static LineSegment fromTwoPoints(const Vector3 &point1, const Vector3 &point2) {
        return LineSegment(point1, point2 - point1);
    }

	/** Call with 0 or 1 */
    Vector3 point(int i) const;

    inline float length() const {
        return direction.magnitude();
    }

    /**
     * Returns the closest point on the line segment to point.
     */
    Vector3 closestPoint(const Vector3 &point) const;

    /**
     Returns the distance between point and the line
     */
    double distance(const Vector3& p) const {
        return (closestPoint(p) - p).magnitude();
    }

    double distanceSquared(const Vector3& p) const {
        return (closestPoint(p) - p).squaredMagnitude();
    }

    /** Returns true if some part of this segment is inside the sphere */
    bool intersectsSolidSphere(const class Sphere& s) const;

    Vector3 randomPoint() const;

};


class LineSegment2D {
private:

    Vector2         m_origin;

    /** Not normalized */
    Vector2         m_direction;

    /** Length of m_direction */
    float           m_length;

public:
    
    LineSegment2D() {}

    static LineSegment2D fromTwoPoints(const Vector2& p0, const Vector2& p1);

    /** Returns the intersection of these segements (including 
       testing endpoints), or Vector2::inf() if they do not intersect. */
    Vector2 intersection(const LineSegment2D& other) const;

    Vector2 point(int i) const;

    Vector2 closestPoint(const Vector2& Q) const;

    float distance(const Vector2& p) const;

    float length() const;
};

} // namespace


#endif
