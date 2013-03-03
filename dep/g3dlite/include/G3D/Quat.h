/**
  @file Quat.h
 
  Quaternion
  
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  
  @created 2002-01-23
  @edited  2009-05-10
 */

#ifndef G3D_Quat_h
#define G3D_Quat_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"
#include "G3D/Matrix3.h"
#include <string>

namespace G3D {

/**
  Arbitrary quaternion (not necessarily unit)

  Unit quaternions are used in computer graphics to represent
  rotation about an axis.  Any 3x3 rotation matrix can
  be stored as a quaternion.

  A quaternion represents the sum of a real scalar and
  an imaginary vector: ix + jy + kz + w.  A unit quaternion
  representing a rotation by A about axis v has the form 
  [sin(A/2)*v, cos(A/2)].  For a unit quaternion, q.conj() == q.inverse()
  is a rotation by -A about v.  -q is the same rotation as q
  (negate both the axis and angle).  
  
  A non-unit quaterion q represents the same rotation as
  q.unitize() (Dam98 pg 28).

  Although quaternion-vector operations (eg. Quat + Vector3) are
  well defined, they are not supported by this class because
  they typically are bugs when they appear in code.

  Do not subclass.

  <B>BETA API -- subject to change</B>
  \cite Erik B. Dam, Martin Koch, Martin Lillholm, Quaternions, Interpolation and Animation.  Technical Report DIKU-TR-98/5, Department of Computer Science, University of Copenhagen, Denmark.  1998.
 */
class Quat {
private:
    // Hidden operators
    bool operator<(const Quat&) const;
    bool operator>(const Quat&) const;
    bool operator<=(const Quat&) const;
    bool operator>=(const Quat&) const;

public:

    /**
     q = [sin(angle / 2) * axis, cos(angle / 2)]
    
     In Watt & Watt's notation, s = w, v = (x, y, z)
     In the Real-Time Rendering notation, u = (x, y, z), w = w 
     */
    float x, y, z, w;

    /**
     Initializes to a zero degree rotation, (0,0,0,1)
     */
    Quat() : x(0), y(0), z(0), w(1) {}

    /** Expects "Quat(x,y,z,w)" or a Matrix3 constructor. */
    Quat(const class Any& a);

    Quat(const Matrix3& rot);

    Quat(float _x, float _y, float _z, float _w) :
        x(_x), y(_y), z(_z), w(_w) {}

    /** Defaults to a pure vector quaternion */
    Quat(const Vector3& v, float _w = 0) : x(v.x), y(v.y), z(v.z), w(_w) {
    }

    /**
     The real part of the quaternion.
     */
    const float& real() const {
        return w;
    }

    float& real() {
        return w;
    }

	Quat operator-() const {
		return Quat(-x, -y, -z, -w);
	}

    Quat operator-(const Quat& other) const {
        return Quat(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Quat& operator-=(const Quat& q) {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }

    Quat operator+(const Quat& q) const {
        return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
    }
    
    Quat& operator+=(const Quat& q) {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }

    /**
     Negates the imaginary part.
     */
    Quat conj() const {
        return Quat(-x, -y, -z, w);
    }

    float sum() const {
        return x + y + z + w;
    }

    float average() const {
        return sum() / 4.0f;
    }

    Quat operator*(float s) const {
        return Quat(x * s, y * s, z * s, w * s);
    }

    Quat& operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }


	/** @cite Based on Watt & Watt, page 360 */
    friend Quat operator* (float s, const Quat& q);

    inline Quat operator/(float s) const {
        return Quat(x / s, y / s, z / s, w / s);
    }

    float dot(const Quat& other) const {
        return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
    }

    /** Note: two quats can represent the Quat::sameRotation and not be equal. */
    bool fuzzyEq(const Quat& q) {
      return G3D::fuzzyEq(x, q.x) && G3D::fuzzyEq(y, q.y) && G3D::fuzzyEq(z, q.z) && G3D::fuzzyEq(w, q.w);
    }
    
    /** True if these quaternions represent the same rotation (note that every rotation is 
        represented by two values; q and -q).
      */
    bool sameRotation(const Quat& q) {
        return fuzzyEq(q) || fuzzyEq(-q);
    }

    /**
     Returns the imaginary part (x, y, z)
     */
    const Vector3& imag() const {
        return *(reinterpret_cast<const Vector3*>(this));
    }

    Vector3& imag() {
        return *(reinterpret_cast<Vector3*>(this));
    }

    /** q = [sin(angle/2)*axis, cos(angle/2)] */
    static Quat fromAxisAngleRotation(
        const Vector3&      axis,
        float               angle);

    /** Returns the axis and angle of rotation represented
        by this quaternion (i.e. q = [sin(angle/2)*axis, cos(angle/2)]) */
    void toAxisAngleRotation(
        Vector3&            axis,
        double&             angle) const;

    void toAxisAngleRotation(
        Vector3&            axis,
        float&              angle) const {
		double d;
		toAxisAngleRotation(axis, d);
		angle = (float)d;
	}

    Matrix3 toRotationMatrix() const;

    void toRotationMatrix(
        Matrix3&            rot) const;
    
    /**
     Spherical linear interpolation: linear interpolation along the 
     shortest (3D) great-circle route between two quaternions.

     Note: Correct rotations are expected between 0 and PI in the right order.

     @cite Based on Game Physics -- David Eberly pg 538-540
     @param threshold Critical angle between between rotations at which
	        the algorithm switches to normalized lerp, which is more
			numerically stable in those situations. 0.0 will always slerp. 
     */
    Quat slerp(
        const Quat&         other,
        float               alpha,
        float               threshold = 0.05f) const;

	/** Normalized linear interpolation of quaternion components. */
	Quat nlerp(const Quat& other, float alpha) const;



    /** Note that q<SUP>-1</SUP> = q.conj() for a unit quaternion. 
        @cite Dam99 page 13 */
    inline Quat inverse() const {
        return conj() / dot(*this);
    }

    /**
     Quaternion multiplication (composition of rotations).
     Note that this does not commute.
     */
    Quat operator*(const Quat& other) const;

    /* (*this) * other.inverse() */
    Quat operator/(const Quat& other) const {
        return (*this) * other.inverse();
    }

    /** Is the magnitude nearly 1.0? */
    bool isUnit(float tolerance = 1e-5) const {
        return abs(dot(*this) - 1.0f) < tolerance;
    }    

    float magnitude() const {
        return sqrtf(dot(*this));
    }

    Quat log() const {
        if ((x == 0) && (y == 0) && (z == 0)) {
            if (w > 0) {
                return Quat(0, 0, 0, ::logf(w));
            } else if (w < 0) {
                // Log of a negative number.  Multivalued, any number of the form
                // (PI * v, ln(-q.w))
                return Quat((float)pi(), 0, 0, ::logf(-w));
            } else {
                 // log of zero!
                 return Quat((float)nan(), (float)nan(), (float)nan(), (float)nan());
            }
        } else {
            // Partly imaginary.
            float imagLen = sqrtf(x * x + y * y + z * z);
            float len = sqrtf(imagLen * imagLen + w * w);
            float theta = atan2f(imagLen, (float)w);
            float t = theta / imagLen;
            return Quat(t * x, t * y, t * z, ::logf(len));
        }
    }
    /** log q = [Av, 0] where q = [sin(A) * v, cos(A)].
        Only for unit quaternions 
        debugAssertM(isUnit(), "Log only defined for unit quaternions");
        // Solve for A in q = [sin(A)*v, cos(A)]
        Vector3 u(x, y, z);
        double len = u.magnitude();

        if (len == 0.0) {
            return 
        }
        double A = atan2((double)w, len);
        Vector3 v = u / len;
        
        return Quat(v * A, 0);
    }
    */

    /** exp q = [sin(A) * v, cos(A)] where q = [Av, 0].
        Only defined for pure-vector quaternions */
    inline Quat exp() const {
        debugAssertM(w == 0, "exp only defined for vector quaternions");
        Vector3 u(x, y, z);
        float A = u.magnitude();
        Vector3 v = u / A;
        return Quat(sinf(A) * v, cosf(A));
    }


    /**
     Raise this quaternion to a power.  For a rotation, this is
     the effect of rotating x times as much as the original
     quaterion.

     Note that q.pow(a).pow(b) == q.pow(a + b)
     @cite Dam98 pg 21
     */
    inline Quat pow(float x) const {
        return (log() * x).exp();
    }

    /** Make unit length in place */
    void unitize() {
        *this *= rsq(dot(*this));
    }

    /**
     Returns a unit quaterion obtained by dividing through by
     the magnitude.
     */
    Quat toUnit() const {
        Quat x = *this;
        x.unitize();
        return x;
    }

    /**
     The linear algebra 2-norm, sqrt(q dot q).  This matches
     the value used in Dam's 1998 tech report but differs from the
     n(q) value used in Eberly's 1999 paper, which is the square of the
     norm.
     */
    float norm() const {
        return magnitude();
    }

    // access quaternion as q[0] = q.x, q[1] = q.y, q[2] = q.z, q[3] = q.w
    //
    // WARNING.  These member functions rely on
    // (1) Quat not having virtual functions
    // (2) the data packed in a 4*sizeof(float) memory block
    const float& operator[] (int i) const;
    float& operator[] (int i);

    /** Generate uniform random unit quaternion (i.e. random "direction") 
	@cite From "Uniform Random Rotations", Ken Shoemake, Graphics Gems III.
   */
    static Quat unitRandom();

    void deserialize(class BinaryInput& b);
    void serialize(class BinaryOutput& b) const;

    // 2-char swizzles

    Vector2 xx() const;
    Vector2 yx() const;
    Vector2 zx() const;
    Vector2 wx() const;
    Vector2 xy() const;
    Vector2 yy() const;
    Vector2 zy() const;
    Vector2 wy() const;
    Vector2 xz() const;
    Vector2 yz() const;
    Vector2 zz() const;
    Vector2 wz() const;
    Vector2 xw() const;
    Vector2 yw() const;
    Vector2 zw() const;
    Vector2 ww() const;

    // 3-char swizzles

    Vector3 xxx() const;
    Vector3 yxx() const;
    Vector3 zxx() const;
    Vector3 wxx() const;
    Vector3 xyx() const;
    Vector3 yyx() const;
    Vector3 zyx() const;
    Vector3 wyx() const;
    Vector3 xzx() const;
    Vector3 yzx() const;
    Vector3 zzx() const;
    Vector3 wzx() const;
    Vector3 xwx() const;
    Vector3 ywx() const;
    Vector3 zwx() const;
    Vector3 wwx() const;
    Vector3 xxy() const;
    Vector3 yxy() const;
    Vector3 zxy() const;
    Vector3 wxy() const;
    Vector3 xyy() const;
    Vector3 yyy() const;
    Vector3 zyy() const;
    Vector3 wyy() const;
    Vector3 xzy() const;
    Vector3 yzy() const;
    Vector3 zzy() const;
    Vector3 wzy() const;
    Vector3 xwy() const;
    Vector3 ywy() const;
    Vector3 zwy() const;
    Vector3 wwy() const;
    Vector3 xxz() const;
    Vector3 yxz() const;
    Vector3 zxz() const;
    Vector3 wxz() const;
    Vector3 xyz() const;
    Vector3 yyz() const;
    Vector3 zyz() const;
    Vector3 wyz() const;
    Vector3 xzz() const;
    Vector3 yzz() const;
    Vector3 zzz() const;
    Vector3 wzz() const;
    Vector3 xwz() const;
    Vector3 ywz() const;
    Vector3 zwz() const;
    Vector3 wwz() const;
    Vector3 xxw() const;
    Vector3 yxw() const;
    Vector3 zxw() const;
    Vector3 wxw() const;
    Vector3 xyw() const;
    Vector3 yyw() const;
    Vector3 zyw() const;
    Vector3 wyw() const;
    Vector3 xzw() const;
    Vector3 yzw() const;
    Vector3 zzw() const;
    Vector3 wzw() const;
    Vector3 xww() const;
    Vector3 yww() const;
    Vector3 zww() const;
    Vector3 www() const;

    // 4-char swizzles

    Vector4 xxxx() const;
    Vector4 yxxx() const;
    Vector4 zxxx() const;
    Vector4 wxxx() const;
    Vector4 xyxx() const;
    Vector4 yyxx() const;
    Vector4 zyxx() const;
    Vector4 wyxx() const;
    Vector4 xzxx() const;
    Vector4 yzxx() const;
    Vector4 zzxx() const;
    Vector4 wzxx() const;
    Vector4 xwxx() const;
    Vector4 ywxx() const;
    Vector4 zwxx() const;
    Vector4 wwxx() const;
    Vector4 xxyx() const;
    Vector4 yxyx() const;
    Vector4 zxyx() const;
    Vector4 wxyx() const;
    Vector4 xyyx() const;
    Vector4 yyyx() const;
    Vector4 zyyx() const;
    Vector4 wyyx() const;
    Vector4 xzyx() const;
    Vector4 yzyx() const;
    Vector4 zzyx() const;
    Vector4 wzyx() const;
    Vector4 xwyx() const;
    Vector4 ywyx() const;
    Vector4 zwyx() const;
    Vector4 wwyx() const;
    Vector4 xxzx() const;
    Vector4 yxzx() const;
    Vector4 zxzx() const;
    Vector4 wxzx() const;
    Vector4 xyzx() const;
    Vector4 yyzx() const;
    Vector4 zyzx() const;
    Vector4 wyzx() const;
    Vector4 xzzx() const;
    Vector4 yzzx() const;
    Vector4 zzzx() const;
    Vector4 wzzx() const;
    Vector4 xwzx() const;
    Vector4 ywzx() const;
    Vector4 zwzx() const;
    Vector4 wwzx() const;
    Vector4 xxwx() const;
    Vector4 yxwx() const;
    Vector4 zxwx() const;
    Vector4 wxwx() const;
    Vector4 xywx() const;
    Vector4 yywx() const;
    Vector4 zywx() const;
    Vector4 wywx() const;
    Vector4 xzwx() const;
    Vector4 yzwx() const;
    Vector4 zzwx() const;
    Vector4 wzwx() const;
    Vector4 xwwx() const;
    Vector4 ywwx() const;
    Vector4 zwwx() const;
    Vector4 wwwx() const;
    Vector4 xxxy() const;
    Vector4 yxxy() const;
    Vector4 zxxy() const;
    Vector4 wxxy() const;
    Vector4 xyxy() const;
    Vector4 yyxy() const;
    Vector4 zyxy() const;
    Vector4 wyxy() const;
    Vector4 xzxy() const;
    Vector4 yzxy() const;
    Vector4 zzxy() const;
    Vector4 wzxy() const;
    Vector4 xwxy() const;
    Vector4 ywxy() const;
    Vector4 zwxy() const;
    Vector4 wwxy() const;
    Vector4 xxyy() const;
    Vector4 yxyy() const;
    Vector4 zxyy() const;
    Vector4 wxyy() const;
    Vector4 xyyy() const;
    Vector4 yyyy() const;
    Vector4 zyyy() const;
    Vector4 wyyy() const;
    Vector4 xzyy() const;
    Vector4 yzyy() const;
    Vector4 zzyy() const;
    Vector4 wzyy() const;
    Vector4 xwyy() const;
    Vector4 ywyy() const;
    Vector4 zwyy() const;
    Vector4 wwyy() const;
    Vector4 xxzy() const;
    Vector4 yxzy() const;
    Vector4 zxzy() const;
    Vector4 wxzy() const;
    Vector4 xyzy() const;
    Vector4 yyzy() const;
    Vector4 zyzy() const;
    Vector4 wyzy() const;
    Vector4 xzzy() const;
    Vector4 yzzy() const;
    Vector4 zzzy() const;
    Vector4 wzzy() const;
    Vector4 xwzy() const;
    Vector4 ywzy() const;
    Vector4 zwzy() const;
    Vector4 wwzy() const;
    Vector4 xxwy() const;
    Vector4 yxwy() const;
    Vector4 zxwy() const;
    Vector4 wxwy() const;
    Vector4 xywy() const;
    Vector4 yywy() const;
    Vector4 zywy() const;
    Vector4 wywy() const;
    Vector4 xzwy() const;
    Vector4 yzwy() const;
    Vector4 zzwy() const;
    Vector4 wzwy() const;
    Vector4 xwwy() const;
    Vector4 ywwy() const;
    Vector4 zwwy() const;
    Vector4 wwwy() const;
    Vector4 xxxz() const;
    Vector4 yxxz() const;
    Vector4 zxxz() const;
    Vector4 wxxz() const;
    Vector4 xyxz() const;
    Vector4 yyxz() const;
    Vector4 zyxz() const;
    Vector4 wyxz() const;
    Vector4 xzxz() const;
    Vector4 yzxz() const;
    Vector4 zzxz() const;
    Vector4 wzxz() const;
    Vector4 xwxz() const;
    Vector4 ywxz() const;
    Vector4 zwxz() const;
    Vector4 wwxz() const;
    Vector4 xxyz() const;
    Vector4 yxyz() const;
    Vector4 zxyz() const;
    Vector4 wxyz() const;
    Vector4 xyyz() const;
    Vector4 yyyz() const;
    Vector4 zyyz() const;
    Vector4 wyyz() const;
    Vector4 xzyz() const;
    Vector4 yzyz() const;
    Vector4 zzyz() const;
    Vector4 wzyz() const;
    Vector4 xwyz() const;
    Vector4 ywyz() const;
    Vector4 zwyz() const;
    Vector4 wwyz() const;
    Vector4 xxzz() const;
    Vector4 yxzz() const;
    Vector4 zxzz() const;
    Vector4 wxzz() const;
    Vector4 xyzz() const;
    Vector4 yyzz() const;
    Vector4 zyzz() const;
    Vector4 wyzz() const;
    Vector4 xzzz() const;
    Vector4 yzzz() const;
    Vector4 zzzz() const;
    Vector4 wzzz() const;
    Vector4 xwzz() const;
    Vector4 ywzz() const;
    Vector4 zwzz() const;
    Vector4 wwzz() const;
    Vector4 xxwz() const;
    Vector4 yxwz() const;
    Vector4 zxwz() const;
    Vector4 wxwz() const;
    Vector4 xywz() const;
    Vector4 yywz() const;
    Vector4 zywz() const;
    Vector4 wywz() const;
    Vector4 xzwz() const;
    Vector4 yzwz() const;
    Vector4 zzwz() const;
    Vector4 wzwz() const;
    Vector4 xwwz() const;
    Vector4 ywwz() const;
    Vector4 zwwz() const;
    Vector4 wwwz() const;
    Vector4 xxxw() const;
    Vector4 yxxw() const;
    Vector4 zxxw() const;
    Vector4 wxxw() const;
    Vector4 xyxw() const;
    Vector4 yyxw() const;
    Vector4 zyxw() const;
    Vector4 wyxw() const;
    Vector4 xzxw() const;
    Vector4 yzxw() const;
    Vector4 zzxw() const;
    Vector4 wzxw() const;
    Vector4 xwxw() const;
    Vector4 ywxw() const;
    Vector4 zwxw() const;
    Vector4 wwxw() const;
    Vector4 xxyw() const;
    Vector4 yxyw() const;
    Vector4 zxyw() const;
    Vector4 wxyw() const;
    Vector4 xyyw() const;
    Vector4 yyyw() const;
    Vector4 zyyw() const;
    Vector4 wyyw() const;
    Vector4 xzyw() const;
    Vector4 yzyw() const;
    Vector4 zzyw() const;
    Vector4 wzyw() const;
    Vector4 xwyw() const;
    Vector4 ywyw() const;
    Vector4 zwyw() const;
    Vector4 wwyw() const;
    Vector4 xxzw() const;
    Vector4 yxzw() const;
    Vector4 zxzw() const;
    Vector4 wxzw() const;
    Vector4 xyzw() const;
    Vector4 yyzw() const;
    Vector4 zyzw() const;
    Vector4 wyzw() const;
    Vector4 xzzw() const;
    Vector4 yzzw() const;
    Vector4 zzzw() const;
    Vector4 wzzw() const;
    Vector4 xwzw() const;
    Vector4 ywzw() const;
    Vector4 zwzw() const;
    Vector4 wwzw() const;
    Vector4 xxww() const;
    Vector4 yxww() const;
    Vector4 zxww() const;
    Vector4 wxww() const;
    Vector4 xyww() const;
    Vector4 yyww() const;
    Vector4 zyww() const;
    Vector4 wyww() const;
    Vector4 xzww() const;
    Vector4 yzww() const;
    Vector4 zzww() const;
    Vector4 wzww() const;
    Vector4 xwww() const;
    Vector4 ywww() const;
    Vector4 zwww() const;
    Vector4 wwww() const;
};

inline Quat exp(const Quat& q) {
    return q.exp();
}

inline Quat log(const Quat& q) {
    return q.log();
}

inline G3D::Quat operator*(double s, const G3D::Quat& q) {
    return q * (float)s;
}

inline G3D::Quat operator*(float s, const G3D::Quat& q) {
    return q * s;
}

inline float& Quat::operator[] (int i) {
    debugAssert(i >= 0);
    debugAssert(i < 4);
    return ((float*)this)[i];
}

inline const float& Quat::operator[] (int i) const {
    debugAssert(i >= 0);
    debugAssert(i < 4);
    return ((float*)this)[i];
}


} // Namespace G3D

// Outside the namespace to avoid overloading confusion for C++
inline G3D::Quat pow(const G3D::Quat& q, double x) {
    return q.pow((float)x);
}


#endif
