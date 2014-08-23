/**
  \file G3D/Vector2.h
 
  2D vector class
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  
  \created 2001-06-02
  \edited  2011-11-30

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
*/

#ifndef G3D_Vector2_h
#define G3D_Vector2_h

#include <string>

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Table.h"
#include "G3D/HashTrait.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector2unorm16.h"
#include "G3D/Random.h"

namespace G3D {

class Vector2;    
class Vector3;
class Vector4;
class Vector2int32;
class Any;

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
    float x;
    float y;

    /** \param any Must either Vector2(#, #) or Vector2 {x = #, y = #}*/
    Vector2(const Any& any);
    
    /** Converts the Vector2 to an Any. */
    Any toAny() const;

    /** Creates the zero vector */
    Vector2();
    Vector2(class TextInput& t);
    Vector2(class BinaryInput& b);
    Vector2(float x, float y);
    Vector2(float coordinate[2]);
    Vector2(double coordinate[2]);
    Vector2(const Vector2& other);
    Vector2(const Vector2int16& other); 
    Vector2(const Vector2unorm16& other);

    // explicit because of precision loss
    explicit Vector2(const Vector2int32& other);

    Vector2& operator=(const Any& a);

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    void serialize(class TextOutput& t) const;
    void deserialize(class TextInput& t);

    float& operator[](int i);
    const float& operator[](int i) const;

    // assignment and comparison
    Vector2& operator=(const Vector2& other);
    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;
    size_t hashCode() const;
    bool fuzzyEq(const Vector2& other) const;
    bool fuzzyNe(const Vector2& other) const;

    /** Returns true if this vector has finite length */
    bool isFinite() const;

    /** True if any field is NaN */
    bool isNaN() const {
        return G3D::isNaN(x) || G3D::isNaN(y);
    }

    /** Returns true if this vector has length == 0 */
    bool isZero() const;

    /** Returns true if this vector has length == 1 */
    bool isUnit() const;

    // arithmetic operations
    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;
    Vector2 operator*(float s) const;

    /** Raise each component of this vector to a power */
    Vector2 pow(float p) const {
        return Vector2(powf(x, p), powf(y, p));
    }

    /** Array (pointwise) multiplication */
    Vector2 operator*(const Vector2& v) const;

    /** Array division */
    Vector2 operator/(const Vector2& v) const;
    Vector2 operator/(float s) const;

    /** Unary minus */
    Vector2 operator-() const;

    /** x + y */
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
    Vector2& operator+=(const Vector2&);
    Vector2& operator-=(const Vector2&);
    Vector2& operator*=(float);
    Vector2& operator/=(float);
    Vector2& operator*=(const Vector2&);
    Vector2& operator/=(const Vector2&);

    // vector operations

    /** Magnitude of the vector */
    float length() const;
    
    /**
     Returns a unit-length version of this vector.
     Returns nan if length is almost zero.
     */
    Vector2 direction() const;

    /** Returns Vector2::zero() is magnitude is almost zero,
        otherwise returns unit-length vector. */
    Vector2 directionOrZero() const;

    /**
     Potentially less accurate but faster than direction().
     Only works if System::hasSSE is true.
     */
    Vector2 fastDirection() const {
        return direction();
    }

    float squaredLength() const;
    float dot(const Vector2& s) const;

    /** Componentwise absolute value */
    Vector2 abs() const {
        return Vector2(fabs(x), fabs(y));
    }

    /** Component-wise minimum */
    Vector2 min(const Vector2& v) const;

    /** Component-wise maximum */
    Vector2 max(const Vector2& v) const;

    /** Component-wise argmax(abs(), v.abs()).

        For the larger magnitude vector, simply use <code>(a.squaredMagnitude() > b.squaredMagnitude) ?  a : b</code>.
        \sa max
     */
    Vector2 maxAbs(const Vector2& v) const {
        return Vector2(::fabsf(x) > ::fabsf(v.x) ? x : v.x, ::fabsf(y) > ::fabsf(v.y) ? y : v.y);
    }

    /** Component-wise argmin(abs(), v.abs()).

        For the smaller magnitude vector, simply use <code>(a.squaredMagnitude() < b.squaredMagnitude) ?  a : b</code>.
        \sa max
     */
    Vector2 minAbs(const Vector2& v) const {
        return Vector2(::fabsf(x) < ::fabsf(v.x) ? x : v.x, ::fabsf(y) < ::fabsf(v.y) ? y : v.y);
    }

    /** Uniformly distributed random vector on the unit sphere */
    static Vector2 random(Random& r = Random::common());

    // Special values.
    // Intentionally not inlined: see Matrix3::identity() for details.
    static const Vector2& zero();
    static const Vector2& one();
    static const Vector2& unitX();
    static const Vector2& unitY();
    static const Vector2& inf(); 
    static const Vector2& nan();
    /** smallest (most negative) representable vector */
    static const Vector2& minFinite(); 
    /** Largest representable vector */
    static const Vector2& maxFinite();

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
inline Vector2::Vector2 (const Vector2unorm16& v) : x(float(v.x)), y(float(v.y)) {
}

inline float& Vector2::operator[] (int i) {
    return ((float*)this)[i];
}


inline const float& Vector2::operator[] (int i) const {
    return ((float*)this)[i];
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

inline Vector2 Vector2::directionOrZero() const {
    float mag = length();
    if (mag < 0.0000001f) {
        return Vector2::zero();
    } else if (mag < 1.00001f && mag > 0.99999f) {
        return *this;
    } else {
        return *this * (1.0f / mag);
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
    return G3D::fuzzyEq(fabsf(x) + fabsf(y), 0.0f);
}



inline bool Vector2::isUnit() const {
    return G3D::fuzzyEq(squaredLength(), 1.0f);
}

typedef Vector2 Point2;
void serialize(const Vector2& v, class BinaryOutput& b);
void deserialize(Vector2& v, class BinaryInput& b);

} // namespace G3D

template <>
struct HashTrait<G3D::Vector2> {
    static size_t hashCode(const G3D::Vector2& key) {
        return key.hashCode();
    }
};


// Intentionally outside namespace to avoid operator overloading confusion
inline G3D::Vector2 operator*(double s, const G3D::Vector2& v) {
    return v * (float)s;
}
inline G3D::Vector2 operator*(int s, const G3D::Vector2& v) {
    return v * (float)s;
}

#endif
