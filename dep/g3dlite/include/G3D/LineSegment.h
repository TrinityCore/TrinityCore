/**
 @file LineSegment.h
  
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
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

    Point3             _point;

    /** Not normalized */
    Vector3             direction;

    LineSegment(const Point3& __point, const Vector3& _direction) : _point(__point), direction(_direction) {
    }

public:

    LineSegment() : _point(Point3::zero()), direction(Vector3::zero()) {}

    LineSegment(class BinaryInput& b);
    
    void serialize(class BinaryOutput& b) const;
    
    void deserialize(class BinaryInput& b);

    virtual ~LineSegment() {}
    
    /**
     * Constructs a line from two (not equal) points.
     */
    static LineSegment fromTwoPoints(const Point3 &point1, const Point3 &point2) {
        return LineSegment(point1, point2 - point1);
    }

    /** Call with 0 or 1 */
    Point3 point(int i) const;

    Point3 midpoint() const {
        return _point + direction * 0.5f;
    }

    inline float length() const {
        return direction.magnitude();
    }

    /**
     * Returns the closest point on the line segment to point.
     */
    Point3 closestPoint(const Point3 &point) const;

    /**
     Returns the distance between point and the line
     */
    double distance(const Point3& p) const {
        return (closestPoint(p) - p).magnitude();
    }

    double distanceSquared(const Point3& p) const {
        return (closestPoint(p) - p).squaredMagnitude();
    }

    /** Returns true if some part of this segment is inside the sphere */
    bool intersectsSolidSphere(const class Sphere& s) const;

    Point3 randomPoint() const;

};


class LineSegment2D {
private:

    Point2         m_origin;

    /** Not normalized */
    Vector2         m_direction;

    /** Length of m_direction */
    float           m_length;

public:
    
    LineSegment2D() {}

    static LineSegment2D fromTwoPoints(const Point2& p0, const Vector2& p1);

    /** Returns the intersection of these segements (including 
       testing endpoints), or Point2::inf() if they do not intersect. */
    Point2 intersection(const LineSegment2D& other) const;

    Point2 point(int i) const;

    Point2 closestPoint(const Point2& Q) const;

    float distance(const Point2& p) const;

    float length() const;
};

} // namespace


#endif
