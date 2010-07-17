/**
 @file Ray.cpp 
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2002-07-12
 @edited  2004-03-19
 */

#include "G3D/platform.h"
#include "G3D/Ray.h"
#include "G3D/Plane.h"
#include "G3D/Sphere.h"
#include "G3D/CollisionDetection.h"

namespace G3D {

Ray::Ray(class BinaryInput& b) {
	deserialize(b);
}


void Ray::serialize(class BinaryOutput& b) const {
	origin.serialize(b);
	direction.serialize(b);
}


void Ray::deserialize(class BinaryInput& b) {
	origin.deserialize(b);
	direction.deserialize(b);
}


Ray Ray::refract(
    const Vector3&  newOrigin,
    const Vector3&  normal,
    float           iInside,
    float           iOutside) const {

    Vector3 D = direction.refractionDirection(normal, iInside, iOutside);
    return Ray::fromOriginAndDirection(
        newOrigin + (direction + normal * (float)sign(direction.dot(normal))) * 0.001f, D);
}


Ray Ray::reflect(
    const Vector3&  newOrigin,
    const Vector3&  normal) const {

    Vector3 D = direction.reflectionDirection(normal);
    return Ray::fromOriginAndDirection(newOrigin + (D + normal) * 0.001f, D);
}


Vector3 Ray::intersection(const Plane& plane) const {
    float d;
    Vector3 normal = plane.normal();
    plane.getEquation(normal, d);
    float rate = direction.dot(normal);

    if (rate >= 0.0f) {
        return Vector3::inf();
    } else {
        float t = -(d + origin.dot(normal)) / rate;

        return origin + direction * t;
    }
}


float Ray::intersectionTime(const class Sphere& sphere) const {
    Vector3 dummy;
    return CollisionDetection::collisionTimeForMovingPointFixedSphere(
            origin, direction, sphere, dummy);
}


float Ray::intersectionTime(const class Plane& plane) const {
    Vector3 dummy;
    return CollisionDetection::collisionTimeForMovingPointFixedPlane(
            origin, direction, plane, dummy);
}


float Ray::intersectionTime(const class Box& box) const {
    Vector3 dummy;
    float time = CollisionDetection::collisionTimeForMovingPointFixedBox(
            origin, direction, box, dummy);

    if ((time == inf()) && (box.contains(origin))) {
        return 0.0f;
    } else {
        return time;
    }
}


float Ray::intersectionTime(const class AABox& box) const {
    Vector3 dummy;
    bool inside;
    float time = CollisionDetection::collisionTimeForMovingPointFixedAABox(
            origin, direction, box, dummy, inside);

    if ((time == inf()) && inside) {
        return 0.0f;
    } else {
        return time;
    }
}

}
