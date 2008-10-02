/**
  @file Vector3.h
 
  3D vector class
 
  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-06-02
  @edited  2005-08-23
  Copyright 2000-2006, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_VECTOR3_H
#define G3D_VECTOR3_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector2.h"
#include <iostream>
#include <string>

namespace G3D {

class Vector2;    
class Vector3;
class Vector4;

/**
  <B>Swizzles</B>
 Vector classes have swizzle operators, e.g. <CODE>v.xy()</CODE>, that
 allow selection of arbitrary sub-fields.  These cannot be used as write 
 masks.  Examples

  <PRE>
Vector3 v(1, 2, 3);
Vector3 j;
Vector2 b;

b = v.xz();
j = b.xx();
</PRE>


  <B>Warning</B>

 Do not subclass-- this implementation makes assumptions about the
 memory layout.
 */
class Vector3 {
private:
    /**
     Reflect this vector about the (not necessarily unit) normal.
     Note that if used for a collision or ray reflection you
     must negate the resulting vector to get a direction pointing
     <I>away</I> from the collision.

     <PRE>
       V'    N      V
                 
         r   ^   -,
          \  |  /
            \|/
     </PRE>

     See also Vector3::reflectionDirection
     */
    Vector3 reflectAbout(const Vector3& normal) const;

    // Hidden operators
    bool operator<(const Vector3&) const;
    bool operator>(const Vector3&) const;
    bool operator<=(const Vector3&) const;
    bool operator>=(const Vector3&) const;

public:
    // construction
    Vector3();
    Vector3(float _x, float _y, float _z);
    Vector3(const class Vector2& v, float _z);
    Vector3(float coordinate[3]);
    Vector3(double coordinate[3]);
    Vector3(const Vector3& rkVector);
    Vector3(const class Vector3int16& v);

    // coordinates
    float x, y, z;

    // access vector V as V[0] = V.x, V[1] = V.y, V[2] = V.z
    //
    // WARNING.  These member functions rely on
    // (1) Vector3 not having virtual functions
    // (2) the data packed in a 3*sizeof(float) memory block
    const float& operator[] (int i) const;
    float& operator[] (int i);

    inline operator float* () {
        return (float*)this;
    }

    operator const float* () const {
        return (float*)this;
    }

    enum Axis {X_AXIS=0, Y_AXIS=1, Z_AXIS=2, DETECT_AXIS=-1};

    /**
     Returns the largest dimension.  Particularly convenient for determining
     which plane to project a triangle onto for point-in-polygon tests.
     */
    Axis primaryAxis() const;

    // assignment and comparison
    Vector3& operator= (const Vector3& rkVector);
    bool operator== (const Vector3& rkVector) const;
    bool operator!= (const Vector3& rkVector) const;
    unsigned int hashCode() const;
    bool fuzzyEq(const Vector3& other) const;
    bool fuzzyNe(const Vector3& other) const;

    /** Returns true if this vector has finite length. */
    bool isFinite() const;

    /** Returns true if this vector has length ~= 0 */
    bool isZero() const;

    /** Returns true if this vector has length ~= 1 */
    bool isUnit() const;
    
    // arithmetic operations
    Vector3 operator+ (const Vector3& v) const;
    Vector3 operator- (const Vector3& v) const;
    Vector3 operator* (float s) const;
    Vector3 operator/ (float s) const;
    Vector3 operator* (const Vector3& v) const;
    Vector3 operator/ (const Vector3& v) const;
    Vector3 operator- () const;

    // arithmetic updates
    Vector3& operator+= (const Vector3& v);
    Vector3& operator-= (const Vector3& v);
    Vector3& operator*= (float s);
    Vector3& operator/= (float s);
    Vector3& operator*= (const Vector3& v);
    Vector3& operator/= (const Vector3& v);

    /** @deprecated Use magnitude */
	float G3D_DEPRECATED length() const;

    float magnitude() const;
    
    /**
     The result is a nan vector if the length is almost zero.
     */
    Vector3 direction() const;

    /**
     Potentially less accurate but faster than direction().
     Only works if System::hasSSE is true.
     */
    Vector3 fastDirection() const;


    /**
      See also G3D::Ray::reflect.
      The length is 1. 
     <PRE>
       V'    N       V
                 
         r   ^    /
          \  |  /
            \|'-
     </PRE>
     */
    Vector3 reflectionDirection(const Vector3& normal) const;
    

    /**
     Returns Vector3::zero() if the length is nearly zero, otherwise
     returns a unit vector.
     */
    inline Vector3 directionOrZero() const {
        float mag = magnitude();
        if (G3D::fuzzyEq(mag, 0.0f)) {
            return Vector3::zero();
        } else if (G3D::fuzzyEq(mag, 1.0f)) {
            return *this;
        } else {
            return *this * (1.0f / mag);
        }
    }

    /**
     Returns the direction of a refracted ray,
     where iExit is the index of refraction for the
     previous material and iEnter is the index of refraction
     for the new material.  Like Vector3::reflectionDirection,
     the result has length 1 and is 
     pointed <I>away</I> from the intersection.

     Returns Vector3::zero() in the case of total internal refraction.

     @param iOutside The index of refraction (eta) outside
     (on the <I>positive</I> normal side) of the surface.

     @param iInside The index of refraction (eta) inside
     (on the <I>negative</I> normal side) of the surface.

     See also G3D::Ray::refract.
     <PRE>
              N      V
                  
              ^    /
              |  /
              |'-
          __--
     V'<--
     </PRE>
     */
    Vector3 refractionDirection(
        const Vector3&  normal,
        float           iInside,
        float           iOutside) const;

    /** Synonym for direction */
    inline Vector3 unit() const {
        return direction();
    }

    /** Returns a normalized vector.  May be computed with lower precision than unit */
    inline Vector3 fastUnit() const {
        return fastDirection();
    }

    /** @deprecated Use squaredMagnitude */
    float G3D_DEPRECATED squaredLength() const;

    float squaredMagnitude () const;
	
    /** @deprecated Use squaredMagnitude */
    inline float G3D_DEPRECATED norm() const {
        return squaredMagnitude();
    }

    float dot(const Vector3& rkVector) const;
    
    float G3D_DEPRECATED unitize(float fTolerance = 1e-06);

    /** Cross product.  Note that two cross products in a row
        can be computed more cheaply: v1 x (v2 x v3) = (v1 dot v3) v2  - (v1 dot v2) v3.
      */
    Vector3 cross(const Vector3& rkVector) const;
    Vector3 unitCross (const Vector3& rkVector) const;

    /**
     Returns a matrix such that v.cross() * w = v.cross(w).
     <PRE>
     [ 0  -v.z  v.y ]
     [ v.z  0  -v.x ]
     [ -v.y v.x  0  ]
     </PRE>
     */
    class Matrix3 cross() const;

    Vector3 min(const Vector3 &v) const;
    Vector3 max(const Vector3 &v) const;

    std::string toString() const;

    inline Vector3 clamp(const Vector3& low, const Vector3& high) const {
        return Vector3(
            G3D::clamp(x, low.x, high.x),
            G3D::clamp(y, low.y, high.y),
            G3D::clamp(z, low.z, high.z));
    }

    inline Vector3 clamp(float low, float high) const {
        return Vector3(
            G3D::clamp(x, low, high),
            G3D::clamp(y, low, high),
            G3D::clamp(z, low, high));
    }

    /**
     Linear interpolation
     */
    inline Vector3 lerp(const Vector3& v, float alpha) const {
        return (*this) + (v - *this) * alpha; 
    }

    /** Gram-Schmidt orthonormalization. */
    static void orthonormalize (Vector3 akVector[3]);

    /** Random unit vector, uniformly distributed */
    static Vector3 random();

    /** Random unit vector, distributed
        so that the probability of V is proportional 
        to max(V dot Normal, 0).

        @cite Henrik Wann Jensen, Realistic Image Synthesis using Photon Mapping eqn 2.24
    */
    static Vector3 cosRandom(const Vector3& normal);


    /**
     Random vector distributed over the hemisphere about normal.
     */
    static Vector3 hemiRandom(const Vector3& normal);

    // Input W must be initialize to a nonzero vector, output is {U,V,W}
    // an orthonormal basis.  A hint is provided about whether or not W
    // is already unit length.
    static void generateOrthonormalBasis (Vector3& rkU, Vector3& rkV,
                                          Vector3& rkW, bool bUnitLengthW = true);

    inline float sum() const {
        return x + y + z;
    }

    inline float average() const {
        return sum() / 3.0f;
    }

    // Special values.
    inline static const Vector3& zero()     { static Vector3 v(0, 0, 0); return v; }
    inline static const Vector3& one()      { static Vector3 v(1, 1, 1); return v; }
    inline static const Vector3& unitX()    { static Vector3 v(1, 0, 0); return v; }
    inline static const Vector3& unitY()    { static Vector3 v(0, 1, 0); return v; }
    inline static const Vector3& unitZ()    { static Vector3 v(0, 0, 1); return v; }
    inline static const Vector3& inf()      { static Vector3 v((float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf()); return v; }
    inline static const Vector3& nan()      { static Vector3 v((float)G3D::nan(), (float)G3D::nan(), (float)G3D::nan()); return v; }
    /** Smallest (most negative) representable vector */
    inline static const Vector3& minFinite(){ static Vector3 v(-FLT_MAX, -FLT_MAX, -FLT_MAX); return v; }
    /** Largest representable vector */
    inline static const Vector3& maxFinite(){ static Vector3 v(FLT_MAX, FLT_MAX, FLT_MAX); return v; }

    // Deprecated. See Matrix3::identity() for details.
    /** @deprecated Use Vector3::zero() */
    static const Vector3 ZERO;
    /** @deprecated Use Vector3::zero() */
    static const Vector3 ZERO3;
    /** @deprecated Use Vector3::unitX() */
    static const Vector3 UNIT_X;
    /** @deprecated Use Vector3::unitY() */
    static const Vector3 UNIT_Y;
    /** @deprecated Use Vector3::unitZ() */
    static const Vector3 UNIT_Z;
    /** @deprecated Use Vector3::inf() */
    static const Vector3 INF3;
    /** @deprecated Use Vector3::nan() */
    static const Vector3 NAN3;

    // 2-char swizzles

    Vector2 xx() const;
    Vector2 yx() const;
    Vector2 zx() const;
    Vector2 xy() const;
    Vector2 yy() const;
    Vector2 zy() const;
    Vector2 xz() const;
    Vector2 yz() const;
    Vector2 zz() const;

    // 3-char swizzles

    Vector3 xxx() const;
    Vector3 yxx() const;
    Vector3 zxx() const;
    Vector3 xyx() const;
    Vector3 yyx() const;
    Vector3 zyx() const;
    Vector3 xzx() const;
    Vector3 yzx() const;
    Vector3 zzx() const;
    Vector3 xxy() const;
    Vector3 yxy() const;
    Vector3 zxy() const;
    Vector3 xyy() const;
    Vector3 yyy() const;
    Vector3 zyy() const;
    Vector3 xzy() const;
    Vector3 yzy() const;
    Vector3 zzy() const;
    Vector3 xxz() const;
    Vector3 yxz() const;
    Vector3 zxz() const;
    Vector3 xyz() const;
    Vector3 yyz() const;
    Vector3 zyz() const;
    Vector3 xzz() const;
    Vector3 yzz() const;
    Vector3 zzz() const;

    // 4-char swizzles

    Vector4 xxxx() const;
    Vector4 yxxx() const;
    Vector4 zxxx() const;
    Vector4 xyxx() const;
    Vector4 yyxx() const;
    Vector4 zyxx() const;
    Vector4 xzxx() const;
    Vector4 yzxx() const;
    Vector4 zzxx() const;
    Vector4 xxyx() const;
    Vector4 yxyx() const;
    Vector4 zxyx() const;
    Vector4 xyyx() const;
    Vector4 yyyx() const;
    Vector4 zyyx() const;
    Vector4 xzyx() const;
    Vector4 yzyx() const;
    Vector4 zzyx() const;
    Vector4 xxzx() const;
    Vector4 yxzx() const;
    Vector4 zxzx() const;
    Vector4 xyzx() const;
    Vector4 yyzx() const;
    Vector4 zyzx() const;
    Vector4 xzzx() const;
    Vector4 yzzx() const;
    Vector4 zzzx() const;
    Vector4 xxxy() const;
    Vector4 yxxy() const;
    Vector4 zxxy() const;
    Vector4 xyxy() const;
    Vector4 yyxy() const;
    Vector4 zyxy() const;
    Vector4 xzxy() const;
    Vector4 yzxy() const;
    Vector4 zzxy() const;
    Vector4 xxyy() const;
    Vector4 yxyy() const;
    Vector4 zxyy() const;
    Vector4 xyyy() const;
    Vector4 yyyy() const;
    Vector4 zyyy() const;
    Vector4 xzyy() const;
    Vector4 yzyy() const;
    Vector4 zzyy() const;
    Vector4 xxzy() const;
    Vector4 yxzy() const;
    Vector4 zxzy() const;
    Vector4 xyzy() const;
    Vector4 yyzy() const;
    Vector4 zyzy() const;
    Vector4 xzzy() const;
    Vector4 yzzy() const;
    Vector4 zzzy() const;
    Vector4 xxxz() const;
    Vector4 yxxz() const;
    Vector4 zxxz() const;
    Vector4 xyxz() const;
    Vector4 yyxz() const;
    Vector4 zyxz() const;
    Vector4 xzxz() const;
    Vector4 yzxz() const;
    Vector4 zzxz() const;
    Vector4 xxyz() const;
    Vector4 yxyz() const;
    Vector4 zxyz() const;
    Vector4 xyyz() const;
    Vector4 yyyz() const;
    Vector4 zyyz() const;
    Vector4 xzyz() const;
    Vector4 yzyz() const;
    Vector4 zzyz() const;
    Vector4 xxzz() const;
    Vector4 yxzz() const;
    Vector4 zxzz() const;
    Vector4 xyzz() const;
    Vector4 yyzz() const;
    Vector4 zyzz() const;
    Vector4 xzzz() const;
    Vector4 yzzz() const;
    Vector4 zzzz() const;

    /** A value that can be passed to ignore a parameter.  Never look at the result of dummy. */
    static Vector3 dummy;
};

inline G3D::Vector3 operator*(float s, const G3D::Vector3& v) {
    return v * s;
}

inline G3D::Vector3 operator*(double s, const G3D::Vector3& v) {
    return v * (float)s;
}

inline G3D::Vector3 operator*(int s, const G3D::Vector3& v) {
    return v * (float)s;
}

std::ostream& operator<<(std::ostream& os, const Vector3&);

}

unsigned int hashCode(const G3D::Vector3& v);

#include "Vector3.inl"

#endif
