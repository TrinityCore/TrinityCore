/**
  @file Vector2.h

  2D vector class

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-06-02
  @edited  2006-01-14
  Copyright 2000-2006, Morgan McGuire.
  All rights reserved.
*/

#ifndef G3D_VECTOR2_H
#define G3D_VECTOR2_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "Vector2int16.h"
#include <string>

namespace G3D {

class Vector2;
class Vector3;
class Vector4;

/**
 Do not subclass-- this implementation makes assumptions about the
 memory layout.
 */
class Vector2 {
private:
    // Hidden operators
    bool operator<(const Vector2&) const;
    bool operator>(const Vector2&) const;
    bool operator<=(const Vector2&) const;
    bool operator>=(const Vector2&) const;

public:
    // coordinates
    float x, y;

    // construction
    Vector2();
    Vector2(float x, float y);
    Vector2(float coordinate[2]);
    Vector2(double coordinate[2]);
    Vector2(const Vector2& rkVector);
    Vector2(const class Vector2int16& v);

    float& operator[] (int i);
    const float& operator[] (int i) const;
    operator float* ();
    operator const float* () const;

    // assignment and comparison
    Vector2& operator= (const Vector2& rkVector);
    bool operator== (const Vector2& rkVector) const;
    bool operator!= (const Vector2& rkVector) const;
    unsigned int hashCode() const;
    bool fuzzyEq(const Vector2& other) const;
    bool fuzzyNe(const Vector2& other) const;
    /** Returns true if this vector has finite length */
    bool isFinite() const;

    /** Returns true if this vector has length == 0 */
    bool isZero() const;

    /** Returns true if this vector has length == 1 */
    bool isUnit() const;

    // arithmetic operations
    Vector2 operator+ (const Vector2& rkVector) const;
    Vector2 operator- (const Vector2& rkVector) const;
    Vector2 operator* (float fScalar) const;
    Vector2 operator* (const Vector2& rkVector) const;
    Vector2 operator/ (const Vector2& rkVector) const;
    Vector2 operator/ (float fScalar) const;
    Vector2 operator- () const;

    inline float sum() const {
        return x + y;
    }

    /**
     Linear interpolation
     */
    inline Vector2 lerp(const Vector2& v, float alpha) const {
        return (*this) + (v - *this) * alpha;
    }

    inline Vector2 clamp(const Vector2& low, const Vector2& high) const {
        return Vector2(
            G3D::clamp(x, low.x, high.x),
            G3D::clamp(y, low.y, high.y));
    }

    inline Vector2 clamp(float low, float high) const {
        return Vector2(
            (float)G3D::clamp(x, low, high),
            (float)G3D::clamp(y, low, high));
    }

    // arithmetic updates
    Vector2& operator+= (const Vector2& rkVector);
    Vector2& operator-= (const Vector2& rkVector);
    Vector2& operator*= (float fScalar);
    Vector2& operator/= (float fScalar);
    Vector2& operator*= (const Vector2& rkVector);
    Vector2& operator/= (const Vector2& rkVector);

    // vector operations
    float length() const;
    Vector2 direction() const;
    /**
     Potentially less accurate but faster than direction().
     Only works if System::hasSSE is true.
     */
    Vector2 fastDirection() const {
        return direction();
    }

    float squaredLength () const;
    float dot (const Vector2& rkVector) const;
    float unitize (float fTolerance = 1e-06);

    Vector2 min(const Vector2 &v) const;
    Vector2 max(const Vector2 &v) const;

    // Random unit vector
    static Vector2 random();

    // Special values.
    // Intentionally not inlined: see Matrix3::identity() for details.
    static const Vector2& zero();
    inline static const Vector2& one() { static const Vector2 v(1, 1); return v; }
    static const Vector2& unitX();
    static const Vector2& unitY();
    static const Vector2& inf();
    static const Vector2& nan();
    /** smallest (most negative) representable vector */
    static const Vector2& minFinite();
    /** Largest representable vector */
    static const Vector2& maxFinite();



    // Deprecated. See Matrix3::identity() for details.
    /** @deprecated Use Vector2::zero() */
    static const Vector2 ZERO;
    /** @deprecated Use Vector2::unitX() */
    static const Vector2 UNIT_S;
    /** @deprecated Use Vector2::unitY() */
    static const Vector2 UNIT_T;

    std::string toString() const;

    // 2-char swizzles

    Vector2 xx() const;
    Vector2 yx() const;
    Vector2 xy() const;
    Vector2 yy() const;

    // 3-char swizzles

    Vector3 xxx() const;
    Vector3 yxx() const;
    Vector3 xyx() const;
    Vector3 yyx() const;
    Vector3 xxy() const;
    Vector3 yxy() const;
    Vector3 xyy() const;
    Vector3 yyy() const;

    // 4-char swizzles

    Vector4 xxxx() const;
    Vector4 yxxx() const;
    Vector4 xyxx() const;
    Vector4 yyxx() const;
    Vector4 xxyx() const;
    Vector4 yxyx() const;
    Vector4 xyyx() const;
    Vector4 yyyx() const;
    Vector4 xxxy() const;
    Vector4 yxxy() const;
    Vector4 xyxy() const;
    Vector4 yyxy() const;
    Vector4 xxyy() const;
    Vector4 yxyy() const;
    Vector4 xyyy() const;
    Vector4 yyyy() const;

};

inline Vector2 operator*(double s, const Vector2& v) {
    return v * (float)s;
}

inline Vector2 operator*(float s, const Vector2& v) {
    return v * s;
}

inline Vector2 operator*(int s, const Vector2& v) {
    return v * (float)s;
}


inline unsigned int hashCode(const G3D::Vector2& v) {
     return v.hashCode();
}


inline Vector2::Vector2 () : x(0.0f), y(0.0f) {
}


inline Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {
}


inline Vector2::Vector2 (float afCoordinate[2]) {
    x = afCoordinate[0];
    y = afCoordinate[1];
}



inline Vector2::Vector2 (double afCoordinate[2]) {
    x = (float)afCoordinate[0];
    y = (float)afCoordinate[1];
}


inline Vector2::Vector2 (const Vector2& rkVector) {
    x = rkVector.x;
    y = rkVector.y;
}


inline Vector2::Vector2 (const Vector2int16& v) : x(v.x), y(v.y) {
}


inline float& Vector2::operator[] (int i) {
    return ((float*)this)[i];
}


inline const float& Vector2::operator[] (int i) const {
    return ((float*)this)[i];
}


inline Vector2::operator float* () {
    return (float*)this;
}

inline Vector2::operator const float* () const {
    return (float*)this;
}


inline Vector2& Vector2::operator= (const Vector2& rkVector) {
    x = rkVector.x;
    y = rkVector.y;
    return *this;
}


inline bool Vector2::operator== (const Vector2& rkVector) const {
    return ( x == rkVector.x && y == rkVector.y);
}


inline bool Vector2::operator!= (const Vector2& rkVector) const {
    return ( x != rkVector.x || y != rkVector.y);
}


inline Vector2 Vector2::operator+ (const Vector2& rkVector) const {
    return Vector2(x + rkVector.x, y + rkVector.y);
}


inline Vector2 Vector2::operator- (const Vector2& rkVector) const {
    return Vector2(x - rkVector.x, y - rkVector.y);
}


inline Vector2 Vector2::operator* (float fScalar) const {
    return Vector2(fScalar*x, fScalar*y);
}



inline Vector2 Vector2::operator- () const {
    return Vector2( -x, -y);
}



inline Vector2& Vector2::operator+= (const Vector2& rkVector) {
    x += rkVector.x;
    y += rkVector.y;
    return *this;
}



inline Vector2& Vector2::operator-= (const Vector2& rkVector) {
    x -= rkVector.x;
    y -= rkVector.y;
    return *this;
}



inline Vector2& Vector2::operator*= (float fScalar) {
    x *= fScalar;
    y *= fScalar;
    return *this;
}




inline Vector2& Vector2::operator*= (const Vector2& rkVector) {
    x *= rkVector.x;
    y *= rkVector.y;
    return *this;
}



inline Vector2& Vector2::operator/= (const Vector2& rkVector) {
    x /= rkVector.x;
    y /= rkVector.y;
    return *this;
}


inline Vector2 Vector2::operator* (const Vector2& rkVector) const {
    return Vector2(x * rkVector.x, y * rkVector.y);
}



inline Vector2 Vector2::operator/ (const Vector2& rkVector) const {
    return Vector2(x / rkVector.x, y / rkVector.y);
}


inline float Vector2::squaredLength () const {
    return x*x + y*y;
}


inline float Vector2::length () const {
    return sqrtf(x*x + y*y);
}


inline Vector2 Vector2::direction () const {
    float lenSquared = x * x + y * y;

    if (lenSquared != 1.0f) {
        return *this / sqrtf(lenSquared);
    } else {
        return *this;
    }
}



inline float Vector2::dot (const Vector2& rkVector) const {
    return x*rkVector.x + y*rkVector.y;
}



inline Vector2 Vector2::min(const Vector2 &v) const {
    return Vector2(G3D::min(v.x, x), G3D::min(v.y, y));
}



inline Vector2 Vector2::max(const Vector2 &v) const {
    return Vector2(G3D::max(v.x, x), G3D::max(v.y, y));
}



inline bool Vector2::fuzzyEq(const Vector2& other) const {
    return G3D::fuzzyEq((*this - other).squaredLength(), 0);
}



inline bool Vector2::fuzzyNe(const Vector2& other) const {
    return G3D::fuzzyNe((*this - other).squaredLength(), 0);
}



inline bool Vector2::isFinite() const {
    return G3D::isFinite(x) && G3D::isFinite(y);
}



inline bool Vector2::isZero() const {
    return (x == 0.0f) && (y == 0.0f);
}



inline bool Vector2::isUnit() const {
    return squaredLength() == 1.0f;
}

}

// Intentionally outside namespace to avoid operator overloading confusion
inline G3D::Vector2 operator*(double s, const G3D::Vector2& v) {
    return v * (float)s;
}
inline G3D::Vector2 operator*(int s, const G3D::Vector2& v) {
    return v * (float)s;
}


inline unsigned int hashCode(const G3D::Vector2& v);


#endif

