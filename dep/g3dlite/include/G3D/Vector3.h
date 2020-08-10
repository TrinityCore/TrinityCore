/**
  \file Vector3.h
 
  3D vector class
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2001-06-02
  \edited  2010-12-25

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Vector3_h
#define G3D_Vector3_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Random.h"
#include "G3D/Vector2.h"
#include "G3D/Table.h"
#include "G3D/HashTrait.h"
#include "G3D/PositionTrait.h"
#include "G3D/Vector2.h"
#include <iostream>
#include <string>

namespace G3D {

class Vector2;
class Vector4;
class Vector4int8;
class Vector3int32;
class Any;

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
public:

    // coordinates
    float x, y, z;

private:

    // Hidden operators
    bool operator<(const Vector3&) const;
    bool operator>(const Vector3&) const;
    bool operator<=(const Vector3&) const;
    bool operator>=(const Vector3&) const;

public:
    /** Initializes to zero */
    Vector3();

    /** 
        \param any  Must either Vector3(#, #, #) or Vector3 {x = #, y = #, z = #}.
        Because Point3 is a typedef for Vector3 in the current implementation,
        this constructor accepts Point3(#, #, #), etc. as well.
        
     */
    explicit Vector3(const Any& any);
    
    /** Converts the Vector3 to an Any, using the specified \a name instead of "Vector3" */
    Any toAny(const std::string& name) const;

    /** Converts the Vector3 to an Any. */
    Any toAny() const;

    /** Divides by 127 */
    Vector3(const Vector4int8&);
    Vector3(const class Vector2& v, float z);
    Vector3(const class Vector3int32& v);
    explicit Vector3(class BinaryInput& b);
    Vector3(float _x, float _y, float _z);
    explicit Vector3(float coordinate[3]);
    explicit Vector3(double coordinate[3]);
    Vector3(const class Vector3int16& v);
    explicit Vector3(class TextInput& t);
    explicit Vector3(const class Color3& c);

     /** Format is three float32's */
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    /** Format is "(%f, %f, %f)" */
    void serialize(class TextOutput& t) const;
    void deserialize(class TextInput& t);

    // access vector V as V[0] = V.x, V[1] = V.y, V[2] = V.z
    //
    // WARNING.  These member functions rely on
    // (1) Vector3 not having virtual functions
    // (2) the data packed in a 3*sizeof(float) memory block
    const float& __fastcall operator[] (int i) const;
    float& operator[] (int i);

    bool nonZero() const {
        return (x != 0) || (y != 0) || (z != 0);    
    }

    enum Axis {X_AXIS=0, Y_AXIS=1, Z_AXIS=2, DETECT_AXIS=-1};

    /**
     Returns the largest dimension.  Particularly convenient for determining
     which plane to project a triangle onto for point-in-polygon tests.
     */
    Axis primaryAxis() const;

    // assignment and comparison
    Vector3& operator=(const Vector3& rkVector) = default;
    Vector3& operator=(const Any& a);
    bool operator== (const Vector3& rkVector) const;
    bool operator!= (const Vector3& rkVector) const;
    size_t hashCode() const;
    bool fuzzyEq(const Vector3& other) const;
    bool fuzzyNe(const Vector3& other) const;

    /** Returns true if this vector has finite length. */
    bool isFinite() const;

    /** True if any field is nan */
    bool isNaN() const;

    /** Returns true if this vector has length ~= 0 */
    bool isZero() const;

    /** Returns true if this vector has length ~= 1 */
    bool isUnit() const;

    /** Returns a vector that is \a this translated towards \a goal with a maximum translation of \a maxTranslation. */
    Vector3 movedTowards(const Vector3& goal, float maxTranslation) const;
    void moveTowards(const Vector3& goal, float maxTranslation);
    
    // arithmetic operations
    Vector3 __fastcall operator+ (const Vector3& v) const;
    Vector3 __fastcall operator- (const Vector3& v) const;
    Vector3 __fastcall operator* (float s) const;
    inline Vector3 __fastcall operator/ (float s) const {
        return *this * (1.0f / s);
    }
    Vector3 __fastcall operator* (const Vector3& v) const;
    Vector3 __fastcall operator/ (const Vector3& v) const;
    Vector3 __fastcall operator- () const;

    // arithmetic updates
    Vector3& __fastcall operator+= (const Vector3& v);
    Vector3& __fastcall operator-= (const Vector3& v);
    Vector3& __fastcall operator*= (float s);
    inline Vector3& __fastcall operator/= (float s) {
        return (*this *= (1.0f / s));
    }
    Vector3& __fastcall operator*= (const Vector3& v);
    Vector3& __fastcall operator/= (const Vector3& v);

    /** Same as magnitude */
    float length() const;

    float magnitude() const;

    /** Raise each component of this vector to a power */
    Vector3 pow(float p) const {
        return Vector3(powf(x, p), powf(y, p), powf(z, p));
    }
    
    /**
     Returns a unit-length version of this vector.
     Returns nan if length is almost zero.
     */
    Vector3 direction() const;

    /**
     Potentially less accurate but faster than direction().
     Only works if System::hasSSE is true.
     */
    Vector3 fastDirection() const;

    /**
     Reflect this vector about the (not necessarily unit) normal.
     Assumes that both the before and after vectors point away from
     the base of the normal.

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
        if (mag < 0.0000001f) {
            return Vector3::zero();
        } else if (mag < 1.00001f && mag > 0.99999f) {
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

    /** Returns a normalized vector.  May be computed with lower
        precision than unit */
    inline Vector3 fastUnit() const {
        return fastDirection();
    }

    /** Same as squaredMagnitude */
    float squaredLength() const;

    float squaredMagnitude () const;
    
    float __fastcall dot(const Vector3& rkVector) const;
    
    /** Cross product.  Note that two cross products in a row
        can be computed more cheaply: v1 x (v2 x v3) = (v1 dot v3) v2  - (v1 dot v2) v3.
      */
    Vector3 __fastcall cross(const Vector3& rkVector) const;
    Vector3 unitCross(const Vector3& rkVector) const;

    /**
     Returns a matrix such that v.cross() * w = v.cross(w).
     <PRE>
     [ 0  -v.z  v.y ]
     [ v.z  0  -v.x ]
     [ -v.y v.x  0  ]
     </PRE>
     */
    class Matrix3 cross() const;

    Vector3 __fastcall min(const Vector3 &v) const;
    Vector3 __fastcall max(const Vector3 &v) const;

    /** Smallest element */
    inline float min() const {
        return G3D::min(G3D::min(x, y), z);
    }

    /** Largest element */
    inline float max() const {
        return G3D::max(G3D::max(x, y), z);
    }

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


    inline Vector3 floor() const {
        return G3D::Vector3(::floor(x), ::floor(y), ::floor(z));
    }


    inline Vector3 round() const {
        return Vector3(G3D::round(x), G3D::round(y), G3D::round(z));
    }


    /**
     Linear interpolation
     */
    inline Vector3 lerp(const Vector3& v, float alpha) const {
        return (*this) + (v - *this) * alpha; 
    }

    /** Gram-Schmidt orthonormalization. */
    static void orthonormalize (Vector3 akVector[3]);

    /** \brief Random unit vector, uniformly distributed on the sphere. 
    
       Distribution rendered by G3D::DirectionHistogram:
       \image html vector3-random.png
      */
    static Vector3 random(Random& r = Random::common());

    /** \brief Random unit vector, distributed according to \f$\max(\cos \theta,0)\f$.

        That is, so that the probability of \f$\vec{V}\f$ is proportional 
        to \f$\max(\vec{v} \cdot \vec{n}, 0)\f$.  Useful in photon mapping for 
        Lambertian scattering.

        Distribution rendered by G3D::DirectionHistogram:
        \image html vector3-coshemirandom.png

        \param n Unit vector at the center of the distribution.

        @cite Henrik Wann Jensen, Realistic Image Synthesis using Photon Mapping eqn 2.24
    */
    static Vector3 cosHemiRandom(const Vector3& n, Random& r = Random::common());

    static Vector3 cosSphereRandom(const Vector3& n, Random& r = Random::common());

    /** \brief Random unit vector, distributed according to \f$\max(\cos^k \theta,0)\f$.

        That is, so that the probability of \f$\vec{V}\f$ is
        proportional to \f$\max((\vec{v} \cdot \vec{n})^k, 0)\f$.
        Useful in photon mapping for glossy scattering.

        Distribution rendered by G3D::DirectionHistogram:
        \image html vector3-cospowhemirandom.png

        \param n Unit vector at the center of the distribution.

        @cite Ashikhmin and Shirley, An anisotropic Phong BRDF model, Journal of Graphics Tools, 2002
    */
    static Vector3 cosPowHemiRandom(const Vector3& n, const float k, Random& r = Random::common());

    /**
     \brief Random vector distributed over the hemisphere about normal.

     Distribution rendered by G3D::DirectionHistogram:
      \image html vector3-hemirandom.png
     */
    static Vector3 hemiRandom(const Vector3& normal, Random& r = Random::common());

    inline float sum() const {
        return x + y + z;
    }

    inline float average() const {
        return sum() / 3.0f;
    }

    // Special values.
    static const Vector3& zero();
    static const Vector3& one();
    static const Vector3& unitX();
    static const Vector3& unitY();
    static const Vector3& unitZ();
    static const Vector3& inf();
    static const Vector3& nan();
    
    /** Smallest (most negative) representable vector */
    static const Vector3& minFinite();

    /** Largest representable vector */
    static const Vector3& maxFinite();


    /** Creates two orthonormal tangent vectors X and Y such that
        if Z = this, X x Y = Z.*/
    inline void getTangents(Vector3& X, Vector3& Y) const {
        debugAssertM(G3D::fuzzyEq(length(), 1.0f), 
                     "makeAxes requires Z to have unit length");
        
        // Choose another vector not perpendicular
        X = (abs(x) < 0.9f) ? Vector3::unitX() : Vector3::unitY();
        
        // Remove the part that is parallel to Z
        X -= *this * this->dot(X);
        X /= X.length();
    
        Y = this->cross(X);
    }


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

    /** Can be passed to ignore a vector3 parameter */
    static Vector3& ignore();
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


void serialize(const Vector3::Axis& a, class BinaryOutput& bo);
void deserialize(Vector3::Axis& a, class BinaryInput& bo);


//----------------------------------------------------------------------------
inline Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {
}

//----------------------------------------------------------------------------

inline Vector3::Vector3 (float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {
}

//----------------------------------------------------------------------------
inline Vector3::Vector3 (float V[3]) : x(V[0]), y(V[1]), z(V[2]){
}

//----------------------------------------------------------------------------
inline Vector3::Vector3 (double V[3]) : x((float)V[0]), y((float)V[1]), z((float)V[2]){
}

//----------------------------------------------------------------------------
inline const float& Vector3::operator[] (int i) const {
    return ((float*)this)[i];
}

inline float& Vector3::operator[] (int i) {
    return ((float*)this)[i];
}


//----------------------------------------------------------------------------

inline bool Vector3::fuzzyEq(const Vector3& other) const {
    return G3D::fuzzyEq((*this - other).squaredMagnitude(), 0);
}

//----------------------------------------------------------------------------

inline bool Vector3::fuzzyNe(const Vector3& other) const {
    return G3D::fuzzyNe((*this - other).squaredMagnitude(), 0);
}

//----------------------------------------------------------------------------

inline bool Vector3::isFinite() const {
    return G3D::isFinite(x) && G3D::isFinite(y) && G3D::isFinite(z);
}

//----------------------------------------------------------------------------
inline bool Vector3::operator== (const Vector3& rkVector) const {
    return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
}

//----------------------------------------------------------------------------
inline bool Vector3::operator!= (const Vector3& rkVector) const {
    return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::operator+ (const Vector3& rkVector) const {
    return Vector3(x + rkVector.x, y + rkVector.y, z + rkVector.z);
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::operator- (const Vector3& rkVector) const {
    return Vector3(x - rkVector.x, y - rkVector.y, z - rkVector.z);
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::operator* (const Vector3& rkVector) const {
    return Vector3(x * rkVector.x, y * rkVector.y, z * rkVector.z);
}

inline Vector3 Vector3::operator*(float f) const {
    return Vector3(x * f, y * f, z * f);
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::operator/ (const Vector3& rkVector) const {
    return Vector3(x / rkVector.x, y / rkVector.y, z / rkVector.z);
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::operator- () const {
    return Vector3(-x, -y, -z);
}

//----------------------------------------------------------------------------
inline Vector3& Vector3::operator+= (const Vector3& rkVector) {
    x += rkVector.x;
    y += rkVector.y;
    z += rkVector.z;
    return *this;
}

//----------------------------------------------------------------------------
inline Vector3& Vector3::operator-= (const Vector3& rkVector) {
    x -= rkVector.x;
    y -= rkVector.y;
    z -= rkVector.z;
    return *this;
}

//----------------------------------------------------------------------------
inline Vector3& Vector3::operator*= (float fScalar) {
    x *= fScalar;
    y *= fScalar;
    z *= fScalar;
    return *this;
}

//----------------------------------------------------------------------------
inline Vector3& Vector3::operator*= (const Vector3& rkVector) {
    x *= rkVector.x;
    y *= rkVector.y;
    z *= rkVector.z;
    return *this;
}

//----------------------------------------------------------------------------
inline Vector3& Vector3::operator/= (const Vector3& rkVector) {
    x /= rkVector.x;
    y /= rkVector.y;
    z /= rkVector.z;
    return *this;
}

//----------------------------------------------------------------------------
inline float Vector3::squaredMagnitude () const {
    return x*x + y*y + z*z;
}

//----------------------------------------------------------------------------
inline float Vector3::squaredLength () const {
    return squaredMagnitude();
}

//----------------------------------------------------------------------------
inline float Vector3::magnitude() const {
    return ::sqrtf(x*x + y*y + z*z);
}

//----------------------------------------------------------------------------
inline float Vector3::length() const {
    return magnitude();
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::direction () const {
    const float lenSquared = squaredMagnitude();
    const float invSqrt = 1.0f / sqrtf(lenSquared);
    return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
}

//----------------------------------------------------------------------------

inline Vector3 Vector3::fastDirection () const {
    float lenSquared = x * x + y * y + z * z;
    float invSqrt = rsq(lenSquared);
    return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
}

//----------------------------------------------------------------------------
inline float Vector3::dot (const Vector3& rkVector) const {
    return x*rkVector.x + y*rkVector.y + z*rkVector.z;
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::cross (const Vector3& rkVector) const {
    return Vector3(y*rkVector.z - z*rkVector.y, z*rkVector.x - x*rkVector.z,
                   x*rkVector.y - y*rkVector.x);
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::unitCross (const Vector3& rkVector) const {
    Vector3 kCross(y*rkVector.z - z*rkVector.y, z*rkVector.x - x*rkVector.z,
                   x*rkVector.y - y*rkVector.x);
    return kCross.direction();
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::min(const Vector3 &v) const {
    return Vector3(G3D::min(v.x, x), G3D::min(v.y, y), G3D::min(v.z, z));
}

//----------------------------------------------------------------------------
inline Vector3 Vector3::max(const Vector3 &v) const {
    return Vector3(G3D::max(v.x, x), G3D::max(v.y, y), G3D::max(v.z, z));
}

//----------------------------------------------------------------------------
inline bool Vector3::isZero() const {
    return G3D::fuzzyEq(fabsf(x) + fabsf(y) + fabsf(z), 0.0f);
}

//----------------------------------------------------------------------------

inline bool Vector3::isUnit() const {
    return G3D::fuzzyEq(squaredMagnitude(), 1.0f);
}

/** 
 Points are technically distinct mathematical entities from vectors.
 Actually distinguishing them at the class level tends to add lots of
 boilerplate (e.g., (P - Point3::zero()).direction()
 vs. P.direction()), so many programmers prefer use a single class,
 as GLSL does.  

 G3D provides this typedef as a way of documenting arguments that are
 locations in space and not directions.  Beware that points and
 vectors are interchangable from the compiler's point of view, and
 that the programmer must track which is really which. */
typedef Vector3 Point3;

void serialize(const Vector3& v, class BinaryOutput& b);
void deserialize(Vector3& v, class BinaryInput& b);

} // namespace G3D


template <>
struct HashTrait<G3D::Vector3> {
    static size_t hashCode(const G3D::Vector3& key) {
        return key.hashCode();
    }
};


template<> struct PositionTrait<class G3D::Vector2> {
    static void getPosition(const G3D::Vector2& v, G3D::Vector3& p) { p = G3D::Vector3(v, 0); }
};

template<> struct PositionTrait<class G3D::Vector3> {
    static void getPosition(const G3D::Vector3& v, G3D::Vector3& p) { p = v; }
};


#endif
