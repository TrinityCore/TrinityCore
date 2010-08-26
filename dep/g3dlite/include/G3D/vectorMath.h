/**
  @file vectorMath.h
 
  Function aliases for popular vector methods.
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created: 2001-06-02
  @edited:  2004-02-02
  Copyright 2000-2004, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_VECTORMATH_H
#define G3D_VECTORMATH_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/Matrix3.h"
#include "G3D/Matrix4.h"
#include "G3D/Color1.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"


namespace G3D {


inline Matrix4 mul(const Matrix4& a, const Matrix4& b) {
    return a * b;
}

inline Vector4 mul(const Matrix4& m, const Vector4& v) {
    return m * v;
}

inline Vector3 mul(const Matrix3& m, const Vector3& v) {
    return m * v;
}

inline Matrix3 mul(const Matrix3& a, const Matrix3& b) {
    return a * b;
}

inline float dot(const Vector2& a, const Vector2& b) {
    return a.dot(b);
}

inline float dot(const Vector3& a, const Vector3& b) {
    return a.dot(b);
}

inline float dot(const Vector4& a, const Vector4& b) {
    return a.dot(b);
}

inline Vector2 normalize(const Vector2& v) {
    return v / v.length();
}

inline Vector3 normalize(const Vector3& v) {
    return v / v.magnitude();
}

inline Vector4 normalize(const Vector4& v) {
    return v / v.length();
}

inline Vector2 abs(const Vector2& v) {
    return Vector2(::fabsf(v.x), ::fabsf(v.y));
}

inline Vector3 abs(const Vector3& v) {
    return Vector3(::fabsf(v.x), ::fabsf(v.y), ::fabsf(v.z));
}

inline Vector4 abs(const Vector4& v) {
    return Vector4(::fabsf(v.x), ::fabsf(v.y), ::fabsf(v.z), ::fabsf(v.w));
}

inline bool all(const Vector2& v) {
    return (v.x != 0) && (v.y != 0);
}

inline bool all(const Vector3& v) {
    return (v.x != 0) && (v.y != 0) && (v.z != 0);
}

inline bool all(const Vector4& v) {
    return (v.x != 0) && (v.y != 0) && (v.z != 0) && (v.w != 0);
}

inline bool any(const Vector2& v) {
    return (v.x != 0) || (v.y != 0);
}

inline bool any(const Vector3& v) {
    return (v.x != 0) || (v.y != 0) || (v.z != 0);
}

inline bool any(const Vector4& v) {
    return (v.x != 0) || (v.y != 0) || (v.z != 0) || (v.w != 0);
}

inline Vector2 clamp(const Vector2& v, const Vector2& a, const Vector2& b) {
    return v.clamp(a, b);
}

inline Vector3 clamp(const Vector3& v, const Vector3& a, const Vector3& b) {
    return v.clamp(a, b);
}

inline Vector4 clamp(const Vector4& v, const Vector4& a, const Vector4& b) {
    return v.clamp(a, b);
}

inline Vector2 lerp(const Vector2& v1, const Vector2& v2, float f) {
    return v1.lerp(v2, f);
}

inline Vector3 lerp(const Vector3& v1, const Vector3& v2, float f) {
    return v1.lerp(v2, f);
}

inline Vector4 lerp(const Vector4& v1, const Vector4& v2, float f) {
    return v1.lerp(v2, f);
}

inline Color1 lerp(const Color1& v1, const Color1& v2, float f) {
    return v1.lerp(v2, f);
}

inline Color3 lerp(const Color3& v1, const Color3& v2, float f) {
    return v1.lerp(v2, f);
}

inline Color4 lerp(const Color4& v1, const Color4& v2, float f) {
    return v1.lerp(v2, f);
}

inline Vector3 cross(const Vector3& v1, const Vector3& v2) {
    return v1.cross(v2);
}

inline double determinant(const Matrix3& m) {
    return m.determinant();
}

inline double determinant(const Matrix4& m) {
    return m.determinant();
}

inline Vector2 min(const Vector2& v1, const Vector2& v2) {
    return v1.min(v2);
}

inline Vector3 min(const Vector3& v1, const Vector3& v2) {
    return v1.min(v2);
}

inline Vector4 min(const Vector4& v1, const Vector4& v2) {
    return v1.min(v2);
}

inline Color3 min(const Color3& v1, const Color3& v2) {
    return v1.min(v2);
}

inline Color4 min(const Color4& v1, const Color4& v2) {
    return v1.min(v2);
}

inline Vector2 max(const Vector2& v1, const Vector2& v2) {
    return v1.max(v2);
}

inline Vector3 max(const Vector3& v1, const Vector3& v2) {
    return v1.max(v2);
}

inline Vector4 max(const Vector4& v1, const Vector4& v2) {
    return v1.max(v2);
}

inline Color3 max(const Color3& v1, const Color3& v2) {
    return v1.max(v2);
}

inline Color4 max(const Color4& v1, const Color4& v2) {
    return v1.max(v2);
}

inline Vector2 sign(const Vector2& v) {
    return Vector2((float)sign(v.x), (float)sign(v.y));
}

inline Vector3 sign(const Vector3& v) {
    return Vector3((float)sign(v.x), (float)sign(v.y), (float)sign(v.z));
}

inline Vector4 sign(const Vector4& v) {
    return Vector4((float)sign(v.x), (float)sign(v.y), (float)sign(v.z), (float)sign(v.w));
}

inline float length(float v) {
    return ::fabsf(v);
}

inline float length(const Vector2& v) {
    return v.length();
}

inline float length(const Vector3& v) {
    return v.magnitude();
}

inline float length(const Vector4& v) {
    return v.length();
}

/**
 Computes the log of each component.  Useful for
 inverting the monitor gamma function or simulating
 perceptual response.
 */
inline Color3 log(const Color3& c) {
    return Color3(::logf(c.r), ::logf(c.g), ::logf(c.b));
}

}

#endif
