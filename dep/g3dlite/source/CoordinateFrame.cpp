/**
 \file CoordinateFrame.cpp

 Coordinate frame class

 \maintainer Morgan McGuire, http://graphics.cs.williams.edu

 \created 2001-06-02
 \edited  2012-09-29

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
*/

#include "G3D/platform.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Quat.h"
#include "G3D/Matrix4.h"
#include "G3D/Box.h"
#include "G3D/AABox.h"
#include "G3D/Sphere.h"
#include "G3D/Triangle.h"
#include "G3D/Ray.h"
#include "G3D/Capsule.h"
#include "G3D/Cylinder.h"
#include "G3D/UprightFrame.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"
#include "G3D/PhysicsFrame.h"
#include "G3D/UprightFrame.h"
#include "G3D/Frustum.h"

namespace G3D {


std::string CoordinateFrame::toXYZYPRDegreesString() const {
    float x,y,z,yaw,pitch,roll;
    getXYZYPRDegrees(x,y,z,yaw,pitch,roll);
    
    return format("CFrame::fromXYZYPRDegrees(% 5.1ff, % 5.1ff, % 5.1ff, % 5.1ff, % 5.1ff, % 5.1ff)", 
                  x,y,z,yaw,pitch,roll);
}


CoordinateFrame::CoordinateFrame(const Any& any) {
    *this = CFrame();

    const std::string& n = toUpper(any.name());

    if (beginsWith(n, "VECTOR3") || beginsWith(n, "POINT3")) {
        translation = Point3(any);
    } else if (beginsWith(n, "MATRIX3")) {
        rotation = Matrix3(any);
    } else if (beginsWith(n, "MATRIX4")) {
        *this = Matrix4(any).approxCoordinateFrame();
    } else if ((n == "CFRAME") || (n == "COORDINATEFRAME")) {
        any.verifyType(Any::TABLE, Any::ARRAY);
        if (any.type() == Any::ARRAY) {
            any.verifySize(2);
            rotation    = any[0];
            translation = any[1];
        } else {
            AnyTableReader r(any);
            r.getIfPresent("translation", translation);
            r.getIfPresent("rotation", rotation);
            r.verifyDone();
        }
    } else if (beginsWith(n, "PHYSICSFRAME") || beginsWith(n, "PFRAME")) {
        *this = PhysicsFrame(any);
//    } else if (beginsWith(n, "UPRIGHTFRAME") || beginsWith(n, "UFRAME")) {
//        *this = UprightFrame(any);
    } else {
        any.verifyName("CFrame::fromXYZYPRDegrees", "CoordinateFrame::fromXYZYPRDegrees");
        any.verifyType(Any::ARRAY);
        any.verifySize(3, 6);

        int s = any.size();

        *this = fromXYZYPRDegrees(any[0], any[1], any[2], 
                                  (s > 3) ? (float)any[3].number() : 0.0f,
                                  (s > 4) ? (float)any[4].number() : 0.0f,
                                  (s > 5) ? (float)any[5].number() : 0.0f);
    }
}


Any CoordinateFrame::toAny() const {
    float x, y, z, yaw, pitch, roll;
    getXYZYPRDegrees(x, y, z, yaw, pitch, roll); 
    Any a(Any::ARRAY, "CFrame::fromXYZYPRDegrees");
    a.append(x, y, z);
    if ( ! G3D::fuzzyEq(yaw, 0.0f) || ! G3D::fuzzyEq(pitch, 0.0f) || ! G3D::fuzzyEq(roll, 0.0f)) {
        a.append(yaw);
        if (! G3D::fuzzyEq(pitch, 0.0f) || ! G3D::fuzzyEq(roll, 0.0f)) {
            a.append(pitch);
            if (! G3D::fuzzyEq(roll, 0.0f)) {
                a.append(roll);
            }
        }
    }
    return a;
}


CoordinateFrame::CoordinateFrame(const class UprightFrame& f) {
    *this = f.toCoordinateFrame();
}


CoordinateFrame::CoordinateFrame() : 
    rotation(Matrix3::identity()), translation(Vector3::zero()) {
}

CoordinateFrame CoordinateFrame::fromXYZYPRRadians(float x, float y, float z, float yaw, 
                                                   float pitch, float roll) {
    const Matrix3& rotation = Matrix3::fromEulerAnglesYXZ(yaw, pitch, roll);
    const Vector3 translation(x, y, z);
    
    return CoordinateFrame(rotation, translation);
}


void CoordinateFrame::getXYZYPRRadians(float& x, float& y, float& z, 
                                       float& yaw, float& pitch, float& roll) const {
    x = translation.x;
    y = translation.y;
    z = translation.z;
    
    rotation.toEulerAnglesYXZ(yaw, pitch, roll);
}


void CoordinateFrame::getXYZYPRDegrees(float& x, float& y, float& z, 
                                       float& yaw, float& pitch, float& roll) const {
    getXYZYPRRadians(x, y, z, yaw, pitch, roll);
    yaw   = toDegrees(yaw);
    pitch = toDegrees(pitch);
    roll  = toDegrees(roll);
}
    

CoordinateFrame CoordinateFrame::fromXYZYPRDegrees(float x, float y, float z, 
                                                   float yaw, float pitch, float roll) {
    return fromXYZYPRRadians(x, y, z, toRadians(yaw), toRadians(pitch), toRadians(roll));
}


Ray CoordinateFrame::lookRay() const {
    return Ray::fromOriginAndDirection(translation, lookVector());
}


bool CoordinateFrame::fuzzyEq(const CoordinateFrame& other) const {

    for (int c = 0; c < 3; ++c) {
        for (int r = 0; r < 3; ++r) {
            if (! G3D::fuzzyEq(other.rotation[r][c], rotation[r][c])) {
                return false;
            }
        }
        if (! G3D::fuzzyEq(translation[c], other.translation[c])) {
            return false;
        }
    }

    return true;
}


bool CoordinateFrame::fuzzyIsIdentity() const {
    const Matrix3& I = Matrix3::identity();

    for (int c = 0; c < 3; ++c) {
        for (int r = 0; r < 3; ++r) {
            if (fuzzyNe(I[r][c], rotation[r][c])) {
                return false;
            }
        }
        if (fuzzyNe(translation[c], 0)) {
            return false;
        }
    }

    return true;
}


bool CoordinateFrame::isIdentity() const {
    return 
        (translation == Vector3::zero()) &&
        (rotation == Matrix3::identity());
}


Matrix4 CoordinateFrame::toMatrix4() const {
    return Matrix4(*this);
}


std::string CoordinateFrame::toXML() const {
    return G3D::format(
        "<COORDINATEFRAME>\n  %lf,%lf,%lf,%lf,\n  %lf,%lf,%lf,%lf,\n  %lf,%lf,%lf,%lf,\n  %lf,%lf,%lf,%lf\n</COORDINATEFRAME>\n",
        rotation[0][0], rotation[0][1], rotation[0][2], translation.x,
        rotation[1][0], rotation[1][1], rotation[1][2], translation.y,
        rotation[2][0], rotation[2][1], rotation[2][2], translation.z,
        0.0, 0.0, 0.0, 1.0);
}


Plane CoordinateFrame::toObjectSpace(const Plane& p) const {
    // TODO
    Vector3 N, P;
    double d;
    p.getEquation(N, d);
    P = N * (float)d;
    P = pointToObjectSpace(P);
    N = normalToObjectSpace(N);
    debugAssertM(isFinite(d), "Not implemented for infinite planes");
    return Plane(N, P);
}


Frustum CoordinateFrame::toWorldSpace(const Frustum& f) const {
    Frustum g;
    g.vertexPos.resize(f.vertexPos.size());
    g.faceArray.resize(f.faceArray.size());

    for (int i = 0; i < f.vertexPos.size(); ++i) {
        g.vertexPos[i] = toWorldSpace(f.vertexPos[i]);
    }
    for (int i = 0; i < f.faceArray.size(); ++i) {
        g.faceArray[i].plane = toWorldSpace(f.faceArray[i].plane);
        for (int j = 0; j < 4; ++j) {
            g.faceArray[i].vertexIndex[j] = f.faceArray[i].vertexIndex[j];
        }
    }

    return g;
}


Plane CoordinateFrame::toWorldSpace(const Plane& plane) const {
    // Since there is no scale factor, we don't have to 
    // worry about the inverse transpose of the normal.
    Vector3 normal;
    float d;
        
    plane.getEquation(normal, d);
        
    const Vector3& newNormal = rotation * normal;
        
    if (isFinite(d)) {
        d = (newNormal * -d + translation).dot(newNormal);
        return Plane(newNormal, newNormal * d);
    } else {
        // When d is infinite, we can't multiply 0's by it without
        // generating NaNs.
        return Plane::fromEquation(newNormal.x, newNormal.y, newNormal.z, d);
    }
}


Triangle CoordinateFrame::toObjectSpace(const Triangle& t) const {
    return Triangle(pointToObjectSpace(t.vertex(0)),
        pointToObjectSpace(t.vertex(1)),
        pointToObjectSpace(t.vertex(2)));
}


Triangle CoordinateFrame::toWorldSpace(const Triangle& t) const {
    return Triangle(pointToWorldSpace(t.vertex(0)),
        pointToWorldSpace(t.vertex(1)),
        pointToWorldSpace(t.vertex(2)));
}


Cylinder CoordinateFrame::toWorldSpace(const Cylinder& c) const {
    return Cylinder(
        pointToWorldSpace(c.point(0)), 
        pointToWorldSpace(c.point(1)), 
        c.radius());
}


Capsule CoordinateFrame::toWorldSpace(const Capsule& c) const {
    return Capsule(
        pointToWorldSpace(c.point(0)), 
        pointToWorldSpace(c.point(1)), 
        c.radius());
}


void CoordinateFrame::toWorldSpace(const AABox& b, AABox& result) const {
    if (b.isEmpty()) {
        result = b;
    } else if (! b.isFinite()) {
        // We can't combine infinite elements under a matrix
        // multiplication: if the computation performs inf-inf we'll
        // get NaN.  So treat the box as infinite in all directions.
        result = AABox::inf();
    } else {
        toWorldSpace(Box(b)).getBounds(result);
    }
}


Box CoordinateFrame::toWorldSpace(const AABox& b) const {
    Box b2(b);
    return toWorldSpace(b2);
}


Box CoordinateFrame::toWorldSpace(const Box& b) const {
    if(!b.isFinite()) {
        return b;
    }
    Box out(b);
    out._center = pointToWorldSpace(b._center);
    for (int i = 0; i < 3; ++i) {
        out._edgeVector[i] = vectorToWorldSpace(out._edgeVector[i]);
    }

    out._area   = b._area;
    out._volume = b._volume;

    return out;
}


Box CoordinateFrame::toObjectSpace(const Box &b) const {
    return inverse().toWorldSpace(b);
}


Box CoordinateFrame::toObjectSpace(const AABox& b) const {
    return toObjectSpace(Box(b));
}


CoordinateFrame::CoordinateFrame(class BinaryInput& b) : rotation(Matrix3::zero()) {
    deserialize(b);
}


void CoordinateFrame::deserialize(class BinaryInput& b) {
    rotation.deserialize(b);
    translation.deserialize(b);
}


void CoordinateFrame::serialize(class BinaryOutput& b) const {
    rotation.serialize(b);
    translation.serialize(b);
}


Sphere CoordinateFrame::toWorldSpace(const Sphere &b) const {
    return Sphere(pointToWorldSpace(b.center), b.radius);
}


Sphere CoordinateFrame::toObjectSpace(const Sphere &b) const {
    return Sphere(pointToObjectSpace(b.center), b.radius);
}


Ray CoordinateFrame::toWorldSpace(const Ray& r) const {
    return Ray::fromOriginAndDirection(pointToWorldSpace(r.origin()), vectorToWorldSpace(r.direction()));
}


Ray CoordinateFrame::toObjectSpace(const Ray& r) const {
    return Ray::fromOriginAndDirection(pointToObjectSpace(r.origin()), vectorToObjectSpace(r.direction()));
}


void CoordinateFrame::lookAt(const Vector3 &target) {
    lookAt(target, Vector3::unitY());
}


void CoordinateFrame::lookAt(
    const Vector3&  target,
    Vector3         up) {

    up = up.direction();

    Vector3 look = (target - translation).direction();
    if (fabs(look.dot(up)) > .99f) {
        up = Vector3::unitX();
        if (fabs(look.dot(up)) > .99f) {
            up = Vector3::unitY();
        }
    }

    up -= look * look.dot(up);
    up = up.direction();

    Vector3 z = -look;
    Vector3 x = -z.cross(up);
    x = x.direction();

    Vector3 y = z.cross(x);

    rotation.setColumn(0, x);
    rotation.setColumn(1, y);
    rotation.setColumn(2, z);
}


void CoordinateFrame::moveTowards(const CoordinateFrame& goal, float maxTranslation, float maxRotation) {
    translation.moveTowards(goal.translation, maxTranslation);
    Quat q(rotation);
    q.moveTowards(Quat(goal.rotation), maxRotation);
    rotation = Matrix3(q);
}


CoordinateFrame CoordinateFrame::lerp(
    const CoordinateFrame&  other,
    float                   alpha) const {

    if (alpha == 1.0f) {
        return other;
    } else if (alpha == 0.0f) {
        return *this;
    } else {
        const Quat q1(this->rotation);
        const Quat q2(other.rotation);

        return CoordinateFrame(
            q1.slerp(q2, alpha).toRotationMatrix(),
            translation * (1 - alpha) + other.translation * alpha);
    }
} 


void CoordinateFrame::pointToWorldSpace(const Array<Vector3>& v, Array<Vector3>& vout) const {
    vout.resize(v.size());

    for (int i = 0; i < v.size(); ++i) {
        vout[i] = pointToWorldSpace(v[i]);
    }
}


void CoordinateFrame::normalToWorldSpace(const Array<Vector3>& v, Array<Vector3>& vout) const  {
    vout.resize(v.size());

    for (int i = 0; i < v.size(); ++i) {
        vout[i] = normalToWorldSpace(v[i]);
    }
}


void CoordinateFrame::vectorToWorldSpace(const Array<Vector3>& v, Array<Vector3>& vout) const {
    vout.resize(v.size());

    for (int i = v.size() - 1; i >= 0; --i) {
        vout[i] = vectorToWorldSpace(v[i]);
    }
}


void CoordinateFrame::pointToObjectSpace(const Array<Vector3>& v, Array<Vector3>& vout) const {
    vout.resize(v.size());

    for (int i = v.size() - 1; i >= 0; --i) {
        vout[i] = pointToObjectSpace(v[i]);
    }
}


void CoordinateFrame::normalToObjectSpace(const Array<Vector3>& v, Array<Vector3>& vout) const {
    vout.resize(v.size());

    for (int i = v.size() - 1; i >= 0; --i) {
        vout[i] = normalToObjectSpace(v[i]);
    }
}


void CoordinateFrame::vectorToObjectSpace(const Array<Vector3>& v, Array<Vector3>& vout) const {
    vout.resize(v.size());

    for (int i = v.size() - 1; i >= 0; --i) {
        vout[i] = vectorToObjectSpace(v[i]);
    }
}

} // namespace
