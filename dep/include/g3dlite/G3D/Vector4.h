/**
  @file Vector4.h
  Homogeneous vector class.
  @maintainer Morgan McGuire, matrix@graphics3d.com
  @created 2002-07-09
  @edited  2005-03-28
  Copyright 2000-2006, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_VECTOR4_H
#define G3D_VECTOR4_H
#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"
#include <string>
namespace G3D {
class Vector2;
class Vector3;
class Vector4;
/**
 Do not subclass-- this implementation makes assumptions about the
 memory layout.
 */
class Vector4 {
private:
    // Hidden operators
    bool operator<(const Vector4&) const;
    bool operator>(const Vector4&) const;
    bool operator<=(const Vector4&) const;
    bool operator>=(const Vector4&) const;
public:
    // construction
    Vector4();
    Vector4(float fX, float fY, float fZ, float fW);
    Vector4(float afCoordinate[4]);
    Vector4(const Vector4& rkVector);
    Vector4(const class Color4& c);
    Vector4(const Vector3& rkVector, float fW);
    Vector4(const Vector2& v1, const Vector2& v2);
    Vector4(const Vector2& v1, float fz, float fw);
    // coordinates
    float x, y, z, w;
    // access vector V as V[0] = V.x, V[1] = V.y, V[2] = V.z, etc.
    //
    // WARNING.  These member functions rely on
    // (1) Vector4 not having virtual functions
    // (2) the data packed in a 4*sizeof(float) memory block
    float& operator[] (int i);
    const float& operator[] (int i) const;
    operator float* ();
    operator const float* () const;
    // assignment and comparison
    Vector4& operator= (const Vector4& rkVector);
    bool operator== (const Vector4& rkVector) const;
    bool operator!= (const Vector4& rkVector) const;
    inline void set(float _x, float _y, float _z, float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }
    inline void set(const Vector3& v, float _w) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = _w;
    }
    inline void set(const Vector2& v, float _z, float _w) {
        x = v.x;
        y = v.y;
        z = _z;
        w = _w;
    }
    unsigned int hashCode() const;
    bool fuzzyEq(const Vector4& other) const;
    bool fuzzyNe(const Vector4& other) const;
    inline static const Vector4& inf()      { static Vector4 v((float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf()); return v; }
    inline static const Vector4& nan()      { static Vector4 v((float)G3D::nan(), (float)G3D::nan(), (float)G3D::nan(), (float)G3D::nan()); return v; }
    /** sqrt(this->dot(*this)) */
    float length() const;
    float squaredLength() const;
    inline float sum() const {
        return x + y + z + w;
    }
    /** Returns true if this vector has finite length */
    bool isFinite() const;
    /** Returns true if this vector has length == 0 */
    bool isZero() const;
    /** Returns true if this vector has length == 1 */
    bool isUnit() const;
    // arithmetic operations
    Vector4 operator+ (const Vector4& rkVector) const;
    Vector4 operator- (const Vector4& rkVector) const;
    inline Vector4 operator*(const Vector4& rkVector) const {
        return Vector4(x * rkVector.x, y * rkVector.y, z * rkVector.z, w * rkVector.w);
    }
    inline Vector4 operator/(const Vector4& rkVector) const {
        return Vector4(x / rkVector.x, y / rkVector.y, z / rkVector.z, w / rkVector.w);
    }
    Vector4 operator* (float fScalar) const;
    Vector4 operator/ (float fScalar) const;
    Vector4 operator- () const;
    friend Vector4 operator* (float, const Vector4& rkVector);
    // arithmetic updates
    Vector4& operator+= (const Vector4& rkVector);
    Vector4& operator-= (const Vector4& rkVector);
    Vector4& operator*= (float fScalar);
    Vector4& operator/= (float fScalar);
    inline Vector4 clamp(const Vector4& low, const Vector4& high) const {
        return Vector4(
            G3D::clamp(x, low.x, high.x),
            G3D::clamp(y, low.y, high.y),
            G3D::clamp(z, low.z, high.z),
            G3D::clamp(w, low.w, high.w));
    }
    inline Vector4 clamp(float low, float high) const {
        return Vector4(
            G3D::clamp(x, low, high),
            G3D::clamp(y, low, high),
            G3D::clamp(z, low, high),
            G3D::clamp(w, low, high));
    }
    float dot (const Vector4& rkVector) const;
    Vector4 min(const Vector4& v) const;
    Vector4 max(const Vector4& v) const;
    std::string toString() const;
    /**
     Linear interpolation
     */
    Vector4 lerp(const Vector4& v, float alpha) const;
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
}
inline G3D::Vector4 operator* (float s, const G3D::Vector4& v) {
    return v * s;
}
unsigned int hashCode(const G3D::Vector4& v);
#include "Vector4.inl"
#endif

