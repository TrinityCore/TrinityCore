/**
 \file G3D/CoordinateFrame.h

 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2001-03-04
 \edited  2012-07-29

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3D_CFrame_h
#define G3D_CFrame_h

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/Matrix3.h"
#include "G3D/Array.h"
#include <math.h>
#include <string>
#include <stdio.h>
#include <cstdarg>
#include <assert.h>

#ifdef _MSC_VER
// Turn off "conditional expression is constant" warning; MSVC generates this
// for debug assertions in inlined methods.
#   pragma warning (disable : 4127)
#endif


namespace G3D {
class Any;
class Frustum;

/**
\brief A rigid body RT (rotation-translation) transformation.
    
CoordinateFrame abstracts a 4x4 matrix that maps object space to world space:
  
  v_world = C * v_object

CoordinateFrame::rotation is the upper 3x3 submatrix, CoordinateFrame::translation
is the right 3x1 column.  The 4th row is always [0 0 0 1], so it isn't stored.  
So you don't have to remember which way the multiplication and transformation work,
it provides explicit toWorldSpace and toObjectSpace methods.  Also, points, vectors 
(directions), and surface normals transform differently, so they have separate methods.
 
Some helper functions transform whole primitives like boxes in and out of object space.

Convert to Matrix4 using CoordinateFrame::toMatrix4.  You <I>can</I> construct a CoordinateFrame
from a Matrix4 using Matrix4::approxCoordinateFrame, however, because a Matrix4 is more 
general than a CoordinateFrame, some information may be lost.

\sa G3D::UprightFrame, G3D::PhysicsFrame, G3D::Matrix4, G3D::Quat
*/
class CoordinateFrame {
public:

    /**  Takes object space points to world space.  */
    Matrix3  rotation;

    /** The origin of this coordinate frame in world space (or its parent's space, if nested). */
    Point3   translation;

    /** \param any Must be in one of the following forms: 
        - CFrame((matrix3 expr), (Point3 expr))
        - CFrame::fromXYZYPRDegrees(#, #, #, #, #, #)
        - CFrame {  rotation = (Matrix3 expr), translation = (Point3 expr) }
        - Point3( ... )
        - Matrix3( ... )
        */
    CoordinateFrame(const Any& any);
    
    /** Converts the CFrame to an Any. */
    Any toAny() const;

    inline bool operator==(const CoordinateFrame& other) const {
        return (translation == other.translation) && (rotation == other.rotation);
    }

    inline bool operator!=(const CoordinateFrame& other) const {
        return !(*this == other);
    }

    bool fuzzyEq(const CoordinateFrame& other) const;

    bool fuzzyIsIdentity() const;

    bool isIdentity() const;

    /**
     Initializes to the identity coordinate frame.
     */
    CoordinateFrame();

    CoordinateFrame(const Point3& _translation) :
        rotation(Matrix3::identity()), translation(_translation) {
    }
    
    CoordinateFrame(const Matrix3& rotation, const Point3& translation) :
        rotation(rotation), translation(translation) {
    }

    CoordinateFrame(const Matrix3& rotation) :
        rotation(rotation), translation(Point3::zero()) {
    }

    CoordinateFrame(const class UprightFrame& f);

    static CoordinateFrame fromXYZYPRRadians(float x, float y, float z, float yaw = 0.0f, float pitch = 0.0f, float roll = 0.0f);

    std::string toXYZYPRDegreesString() const;

    /** Construct a coordinate frame from translation = (x,y,z) and
     rotations (in that order) about Y, object space X, object space
     Z.  Note that because object-space axes are used, these are not
     equivalent to Euler angles; they are known as Tait-Bryan
     rotations and are more convenient for intuitive positioning.*/
    static CoordinateFrame fromXYZYPRDegrees(float x, float y, float z, float yaw = 0.0f, float pitch = 0.0f, float roll = 0.0f);
    
    CoordinateFrame(class BinaryInput& b);

    void deserialize(class BinaryInput& b);

    void serialize(class BinaryOutput& b) const;

    CoordinateFrame(const CoordinateFrame &other) :
        rotation(other.rotation), translation(other.translation) {}

    /**
      Computes the inverse of this coordinate frame.
     */
    inline CoordinateFrame inverse() const {
        CoordinateFrame out;
        out.rotation = rotation.transpose();
        out.translation = -out.rotation * translation;
        return out;
    }

    inline ~CoordinateFrame() {}

    /** See also Matrix4::approxCoordinateFrame */
    class Matrix4 toMatrix4() const;

    void getXYZYPRRadians(float& x, float& y, float& z, float& yaw, float& pitch, float& roll) const;
    void getXYZYPRDegrees(float& x, float& y, float& z, float& yaw, float& pitch, float& roll) const;


    /**
     Produces an XML serialization of this coordinate frame.
     @deprecated
     */
    std::string toXML() const;

    /**
     Returns the heading of the lookVector as an angle in radians relative to
     the world -z axis.  That is, a counter-clockwise heading where north (-z) 
     is 0 and west (-x) is PI/2.

     Note that the heading ignores the Y axis, so an inverted
     object has an inverted heading.
     */
    inline float getHeading() const {
        Vector3 look = rotation.column(2);
        float angle = -(float) atan2(-look.x, look.z);
        return angle;
    }

    /**
     Takes the coordinate frame into object space.
     this->inverse() * c
     */
    inline CoordinateFrame toObjectSpace(const CoordinateFrame& c) const {
        return this->inverse() * c;
    }

    inline Vector4 toObjectSpace(const Vector4& v) const {
        return this->inverse().toWorldSpace(v);
    }

    inline Vector4 toWorldSpace(const Vector4& v) const {
        return Vector4(rotation * Vector3(v.x, v.y, v.z) + translation * v.w, v.w);
    }

    /**
     Transforms the point into world space.
     */
    inline Point3 pointToWorldSpace(const Point3& v) const {
        return Point3
        (rotation[0][0] * v[0] + rotation[0][1] * v[1] + rotation[0][2] * v[2] + translation[0],
         rotation[1][0] * v[0] + rotation[1][1] * v[1] + rotation[1][2] * v[2] + translation[1],
         rotation[2][0] * v[0] + rotation[2][1] * v[1] + rotation[2][2] * v[2] + translation[2]);
    }

    /**
     Transforms the point into object space.  Assumes that the rotation matrix is orthonormal.
     */
    inline Point3 pointToObjectSpace(const Point3& v) const {
        float p[3];
        p[0] = v[0] - translation[0];
        p[1] = v[1] - translation[1];
        p[2] = v[2] - translation[2];
        debugAssert(G3D::fuzzyEq(fabsf(rotation.determinant()), 1.0f));
        return Point3(rotation[0][0] * p[0] + rotation[1][0] * p[1] + rotation[2][0] * p[2],
                      rotation[0][1] * p[0] + rotation[1][1] * p[1] + rotation[2][1] * p[2],
                      rotation[0][2] * p[0] + rotation[1][2] * p[1] + rotation[2][2] * p[2]);
    }

    /**
     Transforms the vector into world space (no translation).
     */
    inline Vector3 vectorToWorldSpace(const Vector3& v) const {
        return rotation * v;
    }

    inline Vector3 normalToWorldSpace(const Vector3& v) const {
        return rotation * v;
    }

    class Ray toObjectSpace(const Ray& r) const;

    Ray toWorldSpace(const Ray& r) const;

    Frustum toWorldSpace(const Frustum& f) const;

    /**
     Transforms the vector into object space (no translation).
     */
    inline Vector3 vectorToObjectSpace(const Vector3 &v) const {
        // Multiply on the left (same as rotation.transpose() * v)
        return v * rotation;
    }

    inline Vector3 normalToObjectSpace(const Vector3 &v) const {
        // Multiply on the left (same as rotation.transpose() * v)
        return v * rotation;
    }

    void pointToWorldSpace(const Array<Point3>& v, Array<Point3>& vout) const;

    void normalToWorldSpace(const Array<Vector3>& v, Array<Vector3>& vout) const;

    void vectorToWorldSpace(const Array<Vector3>& v, Array<Vector3>& vout) const;

    void pointToObjectSpace(const Array<Point3>& v, Array<Point3>& vout) const;

    void normalToObjectSpace(const Array<Vector3>& v, Array<Vector3>& vout) const;

    void vectorToObjectSpace(const Array<Vector3>& v, Array<Vector3>& vout) const;

    void toWorldSpace(const class AABox& b, class AABox& result) const;

    class Box toWorldSpace(const class AABox& b) const;

    class Box toWorldSpace(const class Box& b) const;

    class Cylinder toWorldSpace(const class Cylinder& b) const;

    class Capsule toWorldSpace(const class Capsule& b) const;

    class Plane toWorldSpace(const class Plane& p) const;

    class Sphere toWorldSpace(const class Sphere& b) const;
    
    class Triangle toWorldSpace(const class Triangle& t) const;

    class Box toObjectSpace(const AABox& b) const;

    class Box toObjectSpace(const Box& b) const;

    class Plane toObjectSpace(const Plane& p) const;
 
    class Sphere toObjectSpace(const Sphere& b) const;

    Triangle toObjectSpace(const Triangle& t) const;

    /** Compose: create the transformation that is <I>other</I> followed by <I>this</I>.*/
    CoordinateFrame operator*(const CoordinateFrame &other) const {
        return CoordinateFrame(rotation * other.rotation,
                               pointToWorldSpace(other.translation));
    }

    CoordinateFrame operator+(const Vector3& v) const {
        return CoordinateFrame(rotation, translation + v);
    }

    CoordinateFrame operator-(const Vector3& v) const {
        return CoordinateFrame(rotation, translation - v);
    }


    /**
    Transform this coordinate frame towards \a goal, but not past it, goverened by maximum
    rotation and translations.  This is a useful alternative to \a lerp, especially if the
    goal is expected to change every transformation step so that constant start and end positions will
    not be available.

    \param goal            Step from this towards goal
    \param maxTranslation  Meters 
    \param maxRotation     Radians

    \sa lerp
    */
    void moveTowards(const CoordinateFrame& goal, float maxTranslation, float maxRotation);

    void lookAt(const Point3& target);

    void lookAt
    (const Point3&  target,
     Vector3         up);

    /** The direction this camera is looking (its negative z axis)*/
    inline Vector3 lookVector() const {
        return -rotation.column(2);
    }
    
    /** Returns the ray starting at the camera origin travelling in direction CoordinateFrame::lookVector. */
    class Ray lookRay() const;

    /** Up direction for this camera (its y axis). */
    inline Vector3 upVector() const {
        return rotation.column(1);
    }

    inline Vector3 rightVector() const {
        return rotation.column(0);
    }

    /**
     If a viewer looks along the look vector, this is the viewer's "left".
     Useful for strafing motions and building alternative coordinate frames.
     */
    inline Vector3 leftVector() const {
        return -rotation.column(0);
    }

    /**
     Linearly interpolates between two coordinate frames, using
     Quat::slerp for the rotations.

     \sa moveTowards
     */
    CoordinateFrame lerp
    (const CoordinateFrame&  other,
     float                   alpha) const;

};

typedef CoordinateFrame CFrame;

} // namespace

#endif
