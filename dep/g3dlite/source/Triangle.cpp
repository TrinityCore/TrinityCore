/**
 @file Triangle.cpp
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2001-04-06
 @edited  2008-12-28

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/platform.h"
#include "G3D/Triangle.h"
#include "G3D/Plane.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/debugAssert.h"
#include "G3D/AABox.h"
#include "G3D/Ray.h"

namespace G3D {

    
void Triangle::init(const Vector3& v0, const Vector3& v1, const Vector3& v2) {

    _plane = Plane(v0, v1, v2);
    _vertex[0] = v0;
    _vertex[1] = v1;
    _vertex[2] = v2;

    static int next[] = {1,2,0};

    for (int i = 0; i < 3; ++i) {
        const Vector3& e  = _vertex[next[i]] - _vertex[i];
        edgeMagnitude[i]  = e.magnitude();

        if (edgeMagnitude[i] == 0) {
            edgeDirection[i] = Vector3::zero();
        } else {
            edgeDirection[i] = e / (float)edgeMagnitude[i];
        }
    }

    _edge01 = _vertex[1] - _vertex[0];
    _edge02 = _vertex[2] - _vertex[0];

    _primaryAxis = _plane.normal().primaryAxis();
    _area = 0.5f * edgeDirection[0].cross(edgeDirection[2]).magnitude() * (edgeMagnitude[0] * edgeMagnitude[2]);
        //0.5f * (_vertex[1] - _vertex[0]).cross(_vertex[2] - _vertex[0]).dot(_plane.normal());
}


Triangle::Triangle() {
    init(Vector3::zero(), Vector3::zero(), Vector3::zero());
}
    

Triangle::Triangle(const Vector3& v0, const Vector3& v1, const Vector3& v2) {
    init(v0, v1, v2);
}

    
Triangle::~Triangle() {
}


Triangle::Triangle(class BinaryInput& b) {
    deserialize(b);
}


void Triangle::serialize(class BinaryOutput& b) {
    _vertex[0].serialize(b);
    _vertex[1].serialize(b);
    _vertex[2].serialize(b);
}


void Triangle::deserialize(class BinaryInput& b) {
    _vertex[0].deserialize(b);
    _vertex[1].deserialize(b);
    _vertex[2].deserialize(b);
    init(_vertex[0], _vertex[1], _vertex[2]);
}


float Triangle::area() const {
    return _area;
}


const Vector3& Triangle::normal() const {
    return _plane.normal();
}


const Plane& Triangle::plane() const {
    return _plane;
}


Vector3 Triangle::center() const {
    return (_vertex[0] + _vertex[1] + _vertex[2]) / 3.0;
}

Vector3 Triangle::randomPoint() const {
    // Choose a random point in the parallelogram

    float s = uniformRandom();
    float t = uniformRandom();

    if (t > 1.0f - s) {
        // Outside the triangle; reflect about the
        // diagonal of the parallelogram
        t = 1.0f - t;
        s = 1.0f - s;
    }

    return _edge01 * s + _edge02 * t + _vertex[0];
}


void Triangle::getBounds(AABox& out) const {
    Vector3 lo = _vertex[0];
    Vector3 hi = lo;

    for (int i = 1; i < 3; ++i) {
        lo = lo.min(_vertex[i]);
        hi = hi.max(_vertex[i]);
    }

    out = AABox(lo, hi);
}


bool Triangle::intersect(const Ray& ray, float& distance, float baryCoord[3]) const {
    static const float EPS = 1e-5f;

    // See RTR2 ch. 13.7 for the algorithm.

    const Vector3& e1 = edge01();
    const Vector3& e2 = edge02();
    const Vector3 p(ray.direction().cross(e2));
    const float a = e1.dot(p);

    if (abs(a) < EPS) {
        // Determinant is ill-conditioned; abort early
        return false;
    }

    const float f = 1.0f / a;
    const Vector3 s(ray.origin() - vertex(0));
    const float u = f * s.dot(p);

    if ((u < 0.0f) || (u > 1.0f)) {
        // We hit the plane of the m_geometry, but outside the m_geometry
        return false;
    }

    const Vector3 q(s.cross(e1));
    const float v = f * ray.direction().dot(q);

    if ((v < 0.0f) || ((u + v) > 1.0f)) {
        // We hit the plane of the triangle, but outside the triangle
        return false;
    }

    const float t = f * e2.dot(q);

    if ((t > 0.0f) && (t < distance)) {
        // This is a new hit, closer than the previous one
        distance = t;

        baryCoord[0] = 1.0f - u - v;
        baryCoord[1] = u;
        baryCoord[2] = v;

        return true;
    } else {
        // This hit is after the previous hit, so ignore it
        return false;
    }
}

} // G3D
