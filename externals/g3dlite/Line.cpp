/**
  @file Line.cpp
 
  Line class
 
  @maintainer Morgan McGuire, graphics3d.com
 
  @created 2001-06-02
  @edited  2006-01-28
 */

#include "G3D/Line.h"
#include "G3D/Plane.h"

namespace G3D {

Vector3 Line::intersection(const Plane& plane) const {
    float d;
    Vector3 normal = plane.normal();
    plane.getEquation(normal, d);
    float rate = _direction.dot(normal);

    if (rate == 0) {

        return Vector3::inf();

    } else {
        float t = -(d + _point.dot(normal)) / rate;

        return _point + _direction * t;
    }
}


Line::Line(class BinaryInput& b) {
	deserialize(b);
}


void Line::serialize(class BinaryOutput& b) const {
	_point.serialize(b);
	_direction.serialize(b);
}


void Line::deserialize(class BinaryInput& b) {
	_point.deserialize(b);
	_direction.deserialize(b);
}


Vector3 Line::closestPoint(const Vector3& pt) const {
    float t = _direction.dot(pt - _point);
    return _point + _direction * t;
}


Vector3 Line::point() const {
    return _point;
}


Vector3 Line::direction() const {
    return _direction;
}


Vector3 Line::closestPoint(const Line& B, float& minDist) const {
    const Vector3& P1 = _point;
    const Vector3& U1 = _direction;

    Vector3 P2 = B.point();
    Vector3 U2 = B.direction();
    
    const Vector3& P21 = P2 - P1;
    const Vector3& M = U2.cross(U1);
    float m2 = M.length();

    Vector3 R = P21.cross(M) / m2;
    
    float t1 = R.dot(U2);
    
    minDist = abs(P21.dot(M)) / sqrt(m2);

    return P1 + t1 * U1;
}

}

