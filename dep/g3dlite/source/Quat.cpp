/**
   \file G3D/Quat.cpp
 
  Quaternion implementation based on Watt & Watt page 363
  
  \uthor Morgan McGuire, graphics3d.com
  
  \created 2002-01-23
  \edited  2010-05-31
 */

#include "G3D/Quat.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

Quat Quat::fromAxisAngleRotation(
    const Vector3&      axis,
    float               angle) {

    Quat q;

    q.w = cos(angle / 2.0f);
    q.imag() = axis.direction() * sin(angle / 2.0f); 

    return q;
}


Quat::Quat(const class Any& a) {
    *this = Quat();
    if (beginsWith(toLower(a.name()), "matrix3")) {
        *this = a;
    } else {
        a.verifyName("Quat");
        a.verifyType(Any::ARRAY);
        x = a[0];
        y = a[1];
        z = a[2];
        w = a[3];
    }
}


Any Quat::toAny() const {
    Any a(Any::ARRAY, "Quat");
    a.append(x, y, z, w);
    return a;
}


Quat::Quat(const Matrix3& rot) {

    static const int plus1mod3[] = {1, 2, 0};

    // Find the index of the largest diagonal component
    // These ? operations hopefully compile to conditional
    // move instructions instead of branches.
    int i = (rot[1][1] > rot[0][0]) ? 1 : 0;
    i = (rot[2][2] > rot[i][i]) ? 2 : i;

    // Find the indices of the other elements
    int j = plus1mod3[i];
    int k = plus1mod3[j];

    // Index the elements of the vector part of the quaternion as a float*
    float* v = (float*)(this);

    // If we attempted to pre-normalize and trusted the matrix to be
    // perfectly orthonormal, the result would be:
    //
    //   double c = sqrt((rot[i][i] - (rot[j][j] + rot[k][k])) + 1.0)
    //   v[i] = -c * 0.5
    //   v[j] = -(rot[i][j] + rot[j][i]) * 0.5 / c
    //   v[k] = -(rot[i][k] + rot[k][i]) * 0.5 / c
    //   w    =  (rot[j][k] - rot[k][j]) * 0.5 / c
    //
    // Since we're going to pay the sqrt anyway, we perform a post normalization, which also
    // fixes any poorly normalized input.  Multiply all elements by 2*c in the above, giving:

    // nc2 = -c^2
    double nc2 = ((rot[j][j] + rot[k][k]) - rot[i][i]) - 1.0;
    v[i] =  (float)nc2;
    w    =  (rot[j][k] - rot[k][j]);
    v[j] = -(rot[i][j] + rot[j][i]);
    v[k] = -(rot[i][k] + rot[k][i]);

    // We now have the correct result with the wrong magnitude, so normalize it:
    float s = sqrt(x*x + y*y + z*z + w*w);
    if (s > 0.00001f) {
        s = 1.0f / s;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    } else {
        // The quaternion is nearly zero.  Make it 0 0 0 1
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
}


void Quat::toAxisAngleRotation(
    Vector3&            axis,
    double&             angle) const {
   
    // Decompose the quaternion into an angle and an axis.
    
    axis = Vector3(x, y, z);
    angle = 2 * acos(w);

    float len = sqrt(1.0f - w * w);

    if (fuzzyGt(abs(len), 0.0f)) {
        axis /= len;
    }

    // Reduce the range of the angle.

    if (angle < 0) {        
        angle = -angle;
        axis = -axis;
    }

    while (angle > twoPi()) {
        angle -= twoPi();
    }

    if (abs(angle) > pi()) {
        angle -= twoPi();
    }

    // Make the angle positive.

    if (angle < 0.0f) {        
        angle = -angle;
        axis = -axis;
    }
}


Matrix3 Quat::toRotationMatrix() const {
    Matrix3 out = Matrix3::zero();

    toRotationMatrix(out);

    return out;
}


void Quat::toRotationMatrix(
    Matrix3&            rot) const {

    rot = Matrix3(*this);
}


Quat Quat::slerp
   (const Quat&         _quat1,
    float               alpha,
    float               threshold,
    float               maxAngle) const {

    // From: Game Physics -- David Eberly pg 538-540
    // Modified to include lerp for small angles, which
    // is a common practice.

    // See also:
    // http://number-none.com/product/Understanding%20Slerp,%20Then%20Not%20Using%20It/index.html

    const Quat& quat0 = *this;
    Quat quat1 = _quat1;

    // angle between quaternion rotations
    float halfPhi;
    float cosHalfPhi = quat0.dot(quat1);


    if (cosHalfPhi < 0) {
        // Change the sign and fix the dot product; we need to
        // loop the other way to get the shortest path
        quat1 = -quat1;
        cosHalfPhi = -cosHalfPhi;
    }

    // Using G3D::aCos will clamp the angle to 0 and pi
    halfPhi = static_cast<float>(G3D::aCos(cosHalfPhi));
    
    debugAssertM(halfPhi >= 0.0f, "Assumed acos returned a value >= 0");
    if (halfPhi * 2.0f * alpha > maxAngle) {
        // Back off alpha        
        alpha = maxAngle * 0.5f / halfPhi;
    }

    if (halfPhi >= threshold) {
        // For large angles, slerp
        float scale0, scale1;

        scale0 = sin((1.0f - alpha) * halfPhi);
        scale1 = sin(alpha * halfPhi);
        
        return ( (quat0 * scale0) + (quat1 * scale1) ) / sin(halfPhi);
    } else {
        // For small angles, linear interpolate
        return quat0.nlerp(quat1, alpha);
    }
}


float Quat::angleBetween(const Quat& other) const {
    const float d = this->dot(other);
    return 2.0f * acos(fabsf(d));
}


Quat Quat::nlerp
   (const Quat&         quat1,
    float               alpha) const {

    Quat result = (*this) * (1.0f - alpha) + quat1 * alpha;
    return result / result.magnitude();
}


Quat Quat::operator*(const Quat& other) const {

    // Following Watt & Watt, page 360
    const Vector3& v1 = imag();
    const Vector3& v2 = other.imag();
    float          s1 = w;
    float          s2 = other.w;

    return Quat(s1*v2 + s2*v1 + v1.cross(v2), s1*s2 - v1.dot(v2));
}


// From "Uniform Random Rotations", Ken Shoemake, Graphics Gems III.
Quat Quat::unitRandom() {
    float x0 = uniformRandom();
    float r1 = sqrtf(1 - x0), 
          r2 = sqrtf(x0);
    float t1 = (float)G3D::twoPi() * uniformRandom();
    float t2 = (float)G3D::twoPi() * uniformRandom();
    float c1 = cosf(t1), 
          s1 = sinf(t1);
    float c2 = cosf(t2), 
          s2 = sinf(t2);
    return Quat(s1 * r1, c1 * r1, s2 * r2, c2 * r2);
}


void Quat::deserialize(class BinaryInput& b) {
    x = b.readFloat32();
    y = b.readFloat32();
    z = b.readFloat32();
    w = b.readFloat32();
}


void Quat::serialize(class BinaryOutput& b) const {
    b.writeFloat32(x);
    b.writeFloat32(y);
    b.writeFloat32(z);
    b.writeFloat32(w);
}


// 2-char swizzles

Vector2 Quat::xx() const  { return Vector2       (x, x); }
Vector2 Quat::yx() const  { return Vector2       (y, x); }
Vector2 Quat::zx() const  { return Vector2       (z, x); }
Vector2 Quat::wx() const  { return Vector2       (w, x); }
Vector2 Quat::xy() const  { return Vector2       (x, y); }
Vector2 Quat::yy() const  { return Vector2       (y, y); }
Vector2 Quat::zy() const  { return Vector2       (z, y); }
Vector2 Quat::wy() const  { return Vector2       (w, y); }
Vector2 Quat::xz() const  { return Vector2       (x, z); }
Vector2 Quat::yz() const  { return Vector2       (y, z); }
Vector2 Quat::zz() const  { return Vector2       (z, z); }
Vector2 Quat::wz() const  { return Vector2       (w, z); }
Vector2 Quat::xw() const  { return Vector2       (x, w); }
Vector2 Quat::yw() const  { return Vector2       (y, w); }
Vector2 Quat::zw() const  { return Vector2       (z, w); }
Vector2 Quat::ww() const  { return Vector2       (w, w); }

// 3-char swizzles

Vector3 Quat::xxx() const  { return Vector3       (x, x, x); }
Vector3 Quat::yxx() const  { return Vector3       (y, x, x); }
Vector3 Quat::zxx() const  { return Vector3       (z, x, x); }
Vector3 Quat::wxx() const  { return Vector3       (w, x, x); }
Vector3 Quat::xyx() const  { return Vector3       (x, y, x); }
Vector3 Quat::yyx() const  { return Vector3       (y, y, x); }
Vector3 Quat::zyx() const  { return Vector3       (z, y, x); }
Vector3 Quat::wyx() const  { return Vector3       (w, y, x); }
Vector3 Quat::xzx() const  { return Vector3       (x, z, x); }
Vector3 Quat::yzx() const  { return Vector3       (y, z, x); }
Vector3 Quat::zzx() const  { return Vector3       (z, z, x); }
Vector3 Quat::wzx() const  { return Vector3       (w, z, x); }
Vector3 Quat::xwx() const  { return Vector3       (x, w, x); }
Vector3 Quat::ywx() const  { return Vector3       (y, w, x); }
Vector3 Quat::zwx() const  { return Vector3       (z, w, x); }
Vector3 Quat::wwx() const  { return Vector3       (w, w, x); }
Vector3 Quat::xxy() const  { return Vector3       (x, x, y); }
Vector3 Quat::yxy() const  { return Vector3       (y, x, y); }
Vector3 Quat::zxy() const  { return Vector3       (z, x, y); }
Vector3 Quat::wxy() const  { return Vector3       (w, x, y); }
Vector3 Quat::xyy() const  { return Vector3       (x, y, y); }
Vector3 Quat::yyy() const  { return Vector3       (y, y, y); }
Vector3 Quat::zyy() const  { return Vector3       (z, y, y); }
Vector3 Quat::wyy() const  { return Vector3       (w, y, y); }
Vector3 Quat::xzy() const  { return Vector3       (x, z, y); }
Vector3 Quat::yzy() const  { return Vector3       (y, z, y); }
Vector3 Quat::zzy() const  { return Vector3       (z, z, y); }
Vector3 Quat::wzy() const  { return Vector3       (w, z, y); }
Vector3 Quat::xwy() const  { return Vector3       (x, w, y); }
Vector3 Quat::ywy() const  { return Vector3       (y, w, y); }
Vector3 Quat::zwy() const  { return Vector3       (z, w, y); }
Vector3 Quat::wwy() const  { return Vector3       (w, w, y); }
Vector3 Quat::xxz() const  { return Vector3       (x, x, z); }
Vector3 Quat::yxz() const  { return Vector3       (y, x, z); }
Vector3 Quat::zxz() const  { return Vector3       (z, x, z); }
Vector3 Quat::wxz() const  { return Vector3       (w, x, z); }
Vector3 Quat::xyz() const  { return Vector3       (x, y, z); }
Vector3 Quat::yyz() const  { return Vector3       (y, y, z); }
Vector3 Quat::zyz() const  { return Vector3       (z, y, z); }
Vector3 Quat::wyz() const  { return Vector3       (w, y, z); }
Vector3 Quat::xzz() const  { return Vector3       (x, z, z); }
Vector3 Quat::yzz() const  { return Vector3       (y, z, z); }
Vector3 Quat::zzz() const  { return Vector3       (z, z, z); }
Vector3 Quat::wzz() const  { return Vector3       (w, z, z); }
Vector3 Quat::xwz() const  { return Vector3       (x, w, z); }
Vector3 Quat::ywz() const  { return Vector3       (y, w, z); }
Vector3 Quat::zwz() const  { return Vector3       (z, w, z); }
Vector3 Quat::wwz() const  { return Vector3       (w, w, z); }
Vector3 Quat::xxw() const  { return Vector3       (x, x, w); }
Vector3 Quat::yxw() const  { return Vector3       (y, x, w); }
Vector3 Quat::zxw() const  { return Vector3       (z, x, w); }
Vector3 Quat::wxw() const  { return Vector3       (w, x, w); }
Vector3 Quat::xyw() const  { return Vector3       (x, y, w); }
Vector3 Quat::yyw() const  { return Vector3       (y, y, w); }
Vector3 Quat::zyw() const  { return Vector3       (z, y, w); }
Vector3 Quat::wyw() const  { return Vector3       (w, y, w); }
Vector3 Quat::xzw() const  { return Vector3       (x, z, w); }
Vector3 Quat::yzw() const  { return Vector3       (y, z, w); }
Vector3 Quat::zzw() const  { return Vector3       (z, z, w); }
Vector3 Quat::wzw() const  { return Vector3       (w, z, w); }
Vector3 Quat::xww() const  { return Vector3       (x, w, w); }
Vector3 Quat::yww() const  { return Vector3       (y, w, w); }
Vector3 Quat::zww() const  { return Vector3       (z, w, w); }
Vector3 Quat::www() const  { return Vector3       (w, w, w); }

// 4-char swizzles

Vector4 Quat::xxxx() const  { return Vector4       (x, x, x, x); }
Vector4 Quat::yxxx() const  { return Vector4       (y, x, x, x); }
Vector4 Quat::zxxx() const  { return Vector4       (z, x, x, x); }
Vector4 Quat::wxxx() const  { return Vector4       (w, x, x, x); }
Vector4 Quat::xyxx() const  { return Vector4       (x, y, x, x); }
Vector4 Quat::yyxx() const  { return Vector4       (y, y, x, x); }
Vector4 Quat::zyxx() const  { return Vector4       (z, y, x, x); }
Vector4 Quat::wyxx() const  { return Vector4       (w, y, x, x); }
Vector4 Quat::xzxx() const  { return Vector4       (x, z, x, x); }
Vector4 Quat::yzxx() const  { return Vector4       (y, z, x, x); }
Vector4 Quat::zzxx() const  { return Vector4       (z, z, x, x); }
Vector4 Quat::wzxx() const  { return Vector4       (w, z, x, x); }
Vector4 Quat::xwxx() const  { return Vector4       (x, w, x, x); }
Vector4 Quat::ywxx() const  { return Vector4       (y, w, x, x); }
Vector4 Quat::zwxx() const  { return Vector4       (z, w, x, x); }
Vector4 Quat::wwxx() const  { return Vector4       (w, w, x, x); }
Vector4 Quat::xxyx() const  { return Vector4       (x, x, y, x); }
Vector4 Quat::yxyx() const  { return Vector4       (y, x, y, x); }
Vector4 Quat::zxyx() const  { return Vector4       (z, x, y, x); }
Vector4 Quat::wxyx() const  { return Vector4       (w, x, y, x); }
Vector4 Quat::xyyx() const  { return Vector4       (x, y, y, x); }
Vector4 Quat::yyyx() const  { return Vector4       (y, y, y, x); }
Vector4 Quat::zyyx() const  { return Vector4       (z, y, y, x); }
Vector4 Quat::wyyx() const  { return Vector4       (w, y, y, x); }
Vector4 Quat::xzyx() const  { return Vector4       (x, z, y, x); }
Vector4 Quat::yzyx() const  { return Vector4       (y, z, y, x); }
Vector4 Quat::zzyx() const  { return Vector4       (z, z, y, x); }
Vector4 Quat::wzyx() const  { return Vector4       (w, z, y, x); }
Vector4 Quat::xwyx() const  { return Vector4       (x, w, y, x); }
Vector4 Quat::ywyx() const  { return Vector4       (y, w, y, x); }
Vector4 Quat::zwyx() const  { return Vector4       (z, w, y, x); }
Vector4 Quat::wwyx() const  { return Vector4       (w, w, y, x); }
Vector4 Quat::xxzx() const  { return Vector4       (x, x, z, x); }
Vector4 Quat::yxzx() const  { return Vector4       (y, x, z, x); }
Vector4 Quat::zxzx() const  { return Vector4       (z, x, z, x); }
Vector4 Quat::wxzx() const  { return Vector4       (w, x, z, x); }
Vector4 Quat::xyzx() const  { return Vector4       (x, y, z, x); }
Vector4 Quat::yyzx() const  { return Vector4       (y, y, z, x); }
Vector4 Quat::zyzx() const  { return Vector4       (z, y, z, x); }
Vector4 Quat::wyzx() const  { return Vector4       (w, y, z, x); }
Vector4 Quat::xzzx() const  { return Vector4       (x, z, z, x); }
Vector4 Quat::yzzx() const  { return Vector4       (y, z, z, x); }
Vector4 Quat::zzzx() const  { return Vector4       (z, z, z, x); }
Vector4 Quat::wzzx() const  { return Vector4       (w, z, z, x); }
Vector4 Quat::xwzx() const  { return Vector4       (x, w, z, x); }
Vector4 Quat::ywzx() const  { return Vector4       (y, w, z, x); }
Vector4 Quat::zwzx() const  { return Vector4       (z, w, z, x); }
Vector4 Quat::wwzx() const  { return Vector4       (w, w, z, x); }
Vector4 Quat::xxwx() const  { return Vector4       (x, x, w, x); }
Vector4 Quat::yxwx() const  { return Vector4       (y, x, w, x); }
Vector4 Quat::zxwx() const  { return Vector4       (z, x, w, x); }
Vector4 Quat::wxwx() const  { return Vector4       (w, x, w, x); }
Vector4 Quat::xywx() const  { return Vector4       (x, y, w, x); }
Vector4 Quat::yywx() const  { return Vector4       (y, y, w, x); }
Vector4 Quat::zywx() const  { return Vector4       (z, y, w, x); }
Vector4 Quat::wywx() const  { return Vector4       (w, y, w, x); }
Vector4 Quat::xzwx() const  { return Vector4       (x, z, w, x); }
Vector4 Quat::yzwx() const  { return Vector4       (y, z, w, x); }
Vector4 Quat::zzwx() const  { return Vector4       (z, z, w, x); }
Vector4 Quat::wzwx() const  { return Vector4       (w, z, w, x); }
Vector4 Quat::xwwx() const  { return Vector4       (x, w, w, x); }
Vector4 Quat::ywwx() const  { return Vector4       (y, w, w, x); }
Vector4 Quat::zwwx() const  { return Vector4       (z, w, w, x); }
Vector4 Quat::wwwx() const  { return Vector4       (w, w, w, x); }
Vector4 Quat::xxxy() const  { return Vector4       (x, x, x, y); }
Vector4 Quat::yxxy() const  { return Vector4       (y, x, x, y); }
Vector4 Quat::zxxy() const  { return Vector4       (z, x, x, y); }
Vector4 Quat::wxxy() const  { return Vector4       (w, x, x, y); }
Vector4 Quat::xyxy() const  { return Vector4       (x, y, x, y); }
Vector4 Quat::yyxy() const  { return Vector4       (y, y, x, y); }
Vector4 Quat::zyxy() const  { return Vector4       (z, y, x, y); }
Vector4 Quat::wyxy() const  { return Vector4       (w, y, x, y); }
Vector4 Quat::xzxy() const  { return Vector4       (x, z, x, y); }
Vector4 Quat::yzxy() const  { return Vector4       (y, z, x, y); }
Vector4 Quat::zzxy() const  { return Vector4       (z, z, x, y); }
Vector4 Quat::wzxy() const  { return Vector4       (w, z, x, y); }
Vector4 Quat::xwxy() const  { return Vector4       (x, w, x, y); }
Vector4 Quat::ywxy() const  { return Vector4       (y, w, x, y); }
Vector4 Quat::zwxy() const  { return Vector4       (z, w, x, y); }
Vector4 Quat::wwxy() const  { return Vector4       (w, w, x, y); }
Vector4 Quat::xxyy() const  { return Vector4       (x, x, y, y); }
Vector4 Quat::yxyy() const  { return Vector4       (y, x, y, y); }
Vector4 Quat::zxyy() const  { return Vector4       (z, x, y, y); }
Vector4 Quat::wxyy() const  { return Vector4       (w, x, y, y); }
Vector4 Quat::xyyy() const  { return Vector4       (x, y, y, y); }
Vector4 Quat::yyyy() const  { return Vector4       (y, y, y, y); }
Vector4 Quat::zyyy() const  { return Vector4       (z, y, y, y); }
Vector4 Quat::wyyy() const  { return Vector4       (w, y, y, y); }
Vector4 Quat::xzyy() const  { return Vector4       (x, z, y, y); }
Vector4 Quat::yzyy() const  { return Vector4       (y, z, y, y); }
Vector4 Quat::zzyy() const  { return Vector4       (z, z, y, y); }
Vector4 Quat::wzyy() const  { return Vector4       (w, z, y, y); }
Vector4 Quat::xwyy() const  { return Vector4       (x, w, y, y); }
Vector4 Quat::ywyy() const  { return Vector4       (y, w, y, y); }
Vector4 Quat::zwyy() const  { return Vector4       (z, w, y, y); }
Vector4 Quat::wwyy() const  { return Vector4       (w, w, y, y); }
Vector4 Quat::xxzy() const  { return Vector4       (x, x, z, y); }
Vector4 Quat::yxzy() const  { return Vector4       (y, x, z, y); }
Vector4 Quat::zxzy() const  { return Vector4       (z, x, z, y); }
Vector4 Quat::wxzy() const  { return Vector4       (w, x, z, y); }
Vector4 Quat::xyzy() const  { return Vector4       (x, y, z, y); }
Vector4 Quat::yyzy() const  { return Vector4       (y, y, z, y); }
Vector4 Quat::zyzy() const  { return Vector4       (z, y, z, y); }
Vector4 Quat::wyzy() const  { return Vector4       (w, y, z, y); }
Vector4 Quat::xzzy() const  { return Vector4       (x, z, z, y); }
Vector4 Quat::yzzy() const  { return Vector4       (y, z, z, y); }
Vector4 Quat::zzzy() const  { return Vector4       (z, z, z, y); }
Vector4 Quat::wzzy() const  { return Vector4       (w, z, z, y); }
Vector4 Quat::xwzy() const  { return Vector4       (x, w, z, y); }
Vector4 Quat::ywzy() const  { return Vector4       (y, w, z, y); }
Vector4 Quat::zwzy() const  { return Vector4       (z, w, z, y); }
Vector4 Quat::wwzy() const  { return Vector4       (w, w, z, y); }
Vector4 Quat::xxwy() const  { return Vector4       (x, x, w, y); }
Vector4 Quat::yxwy() const  { return Vector4       (y, x, w, y); }
Vector4 Quat::zxwy() const  { return Vector4       (z, x, w, y); }
Vector4 Quat::wxwy() const  { return Vector4       (w, x, w, y); }
Vector4 Quat::xywy() const  { return Vector4       (x, y, w, y); }
Vector4 Quat::yywy() const  { return Vector4       (y, y, w, y); }
Vector4 Quat::zywy() const  { return Vector4       (z, y, w, y); }
Vector4 Quat::wywy() const  { return Vector4       (w, y, w, y); }
Vector4 Quat::xzwy() const  { return Vector4       (x, z, w, y); }
Vector4 Quat::yzwy() const  { return Vector4       (y, z, w, y); }
Vector4 Quat::zzwy() const  { return Vector4       (z, z, w, y); }
Vector4 Quat::wzwy() const  { return Vector4       (w, z, w, y); }
Vector4 Quat::xwwy() const  { return Vector4       (x, w, w, y); }
Vector4 Quat::ywwy() const  { return Vector4       (y, w, w, y); }
Vector4 Quat::zwwy() const  { return Vector4       (z, w, w, y); }
Vector4 Quat::wwwy() const  { return Vector4       (w, w, w, y); }
Vector4 Quat::xxxz() const  { return Vector4       (x, x, x, z); }
Vector4 Quat::yxxz() const  { return Vector4       (y, x, x, z); }
Vector4 Quat::zxxz() const  { return Vector4       (z, x, x, z); }
Vector4 Quat::wxxz() const  { return Vector4       (w, x, x, z); }
Vector4 Quat::xyxz() const  { return Vector4       (x, y, x, z); }
Vector4 Quat::yyxz() const  { return Vector4       (y, y, x, z); }
Vector4 Quat::zyxz() const  { return Vector4       (z, y, x, z); }
Vector4 Quat::wyxz() const  { return Vector4       (w, y, x, z); }
Vector4 Quat::xzxz() const  { return Vector4       (x, z, x, z); }
Vector4 Quat::yzxz() const  { return Vector4       (y, z, x, z); }
Vector4 Quat::zzxz() const  { return Vector4       (z, z, x, z); }
Vector4 Quat::wzxz() const  { return Vector4       (w, z, x, z); }
Vector4 Quat::xwxz() const  { return Vector4       (x, w, x, z); }
Vector4 Quat::ywxz() const  { return Vector4       (y, w, x, z); }
Vector4 Quat::zwxz() const  { return Vector4       (z, w, x, z); }
Vector4 Quat::wwxz() const  { return Vector4       (w, w, x, z); }
Vector4 Quat::xxyz() const  { return Vector4       (x, x, y, z); }
Vector4 Quat::yxyz() const  { return Vector4       (y, x, y, z); }
Vector4 Quat::zxyz() const  { return Vector4       (z, x, y, z); }
Vector4 Quat::wxyz() const  { return Vector4       (w, x, y, z); }
Vector4 Quat::xyyz() const  { return Vector4       (x, y, y, z); }
Vector4 Quat::yyyz() const  { return Vector4       (y, y, y, z); }
Vector4 Quat::zyyz() const  { return Vector4       (z, y, y, z); }
Vector4 Quat::wyyz() const  { return Vector4       (w, y, y, z); }
Vector4 Quat::xzyz() const  { return Vector4       (x, z, y, z); }
Vector4 Quat::yzyz() const  { return Vector4       (y, z, y, z); }
Vector4 Quat::zzyz() const  { return Vector4       (z, z, y, z); }
Vector4 Quat::wzyz() const  { return Vector4       (w, z, y, z); }
Vector4 Quat::xwyz() const  { return Vector4       (x, w, y, z); }
Vector4 Quat::ywyz() const  { return Vector4       (y, w, y, z); }
Vector4 Quat::zwyz() const  { return Vector4       (z, w, y, z); }
Vector4 Quat::wwyz() const  { return Vector4       (w, w, y, z); }
Vector4 Quat::xxzz() const  { return Vector4       (x, x, z, z); }
Vector4 Quat::yxzz() const  { return Vector4       (y, x, z, z); }
Vector4 Quat::zxzz() const  { return Vector4       (z, x, z, z); }
Vector4 Quat::wxzz() const  { return Vector4       (w, x, z, z); }
Vector4 Quat::xyzz() const  { return Vector4       (x, y, z, z); }
Vector4 Quat::yyzz() const  { return Vector4       (y, y, z, z); }
Vector4 Quat::zyzz() const  { return Vector4       (z, y, z, z); }
Vector4 Quat::wyzz() const  { return Vector4       (w, y, z, z); }
Vector4 Quat::xzzz() const  { return Vector4       (x, z, z, z); }
Vector4 Quat::yzzz() const  { return Vector4       (y, z, z, z); }
Vector4 Quat::zzzz() const  { return Vector4       (z, z, z, z); }
Vector4 Quat::wzzz() const  { return Vector4       (w, z, z, z); }
Vector4 Quat::xwzz() const  { return Vector4       (x, w, z, z); }
Vector4 Quat::ywzz() const  { return Vector4       (y, w, z, z); }
Vector4 Quat::zwzz() const  { return Vector4       (z, w, z, z); }
Vector4 Quat::wwzz() const  { return Vector4       (w, w, z, z); }
Vector4 Quat::xxwz() const  { return Vector4       (x, x, w, z); }
Vector4 Quat::yxwz() const  { return Vector4       (y, x, w, z); }
Vector4 Quat::zxwz() const  { return Vector4       (z, x, w, z); }
Vector4 Quat::wxwz() const  { return Vector4       (w, x, w, z); }
Vector4 Quat::xywz() const  { return Vector4       (x, y, w, z); }
Vector4 Quat::yywz() const  { return Vector4       (y, y, w, z); }
Vector4 Quat::zywz() const  { return Vector4       (z, y, w, z); }
Vector4 Quat::wywz() const  { return Vector4       (w, y, w, z); }
Vector4 Quat::xzwz() const  { return Vector4       (x, z, w, z); }
Vector4 Quat::yzwz() const  { return Vector4       (y, z, w, z); }
Vector4 Quat::zzwz() const  { return Vector4       (z, z, w, z); }
Vector4 Quat::wzwz() const  { return Vector4       (w, z, w, z); }
Vector4 Quat::xwwz() const  { return Vector4       (x, w, w, z); }
Vector4 Quat::ywwz() const  { return Vector4       (y, w, w, z); }
Vector4 Quat::zwwz() const  { return Vector4       (z, w, w, z); }
Vector4 Quat::wwwz() const  { return Vector4       (w, w, w, z); }
Vector4 Quat::xxxw() const  { return Vector4       (x, x, x, w); }
Vector4 Quat::yxxw() const  { return Vector4       (y, x, x, w); }
Vector4 Quat::zxxw() const  { return Vector4       (z, x, x, w); }
Vector4 Quat::wxxw() const  { return Vector4       (w, x, x, w); }
Vector4 Quat::xyxw() const  { return Vector4       (x, y, x, w); }
Vector4 Quat::yyxw() const  { return Vector4       (y, y, x, w); }
Vector4 Quat::zyxw() const  { return Vector4       (z, y, x, w); }
Vector4 Quat::wyxw() const  { return Vector4       (w, y, x, w); }
Vector4 Quat::xzxw() const  { return Vector4       (x, z, x, w); }
Vector4 Quat::yzxw() const  { return Vector4       (y, z, x, w); }
Vector4 Quat::zzxw() const  { return Vector4       (z, z, x, w); }
Vector4 Quat::wzxw() const  { return Vector4       (w, z, x, w); }
Vector4 Quat::xwxw() const  { return Vector4       (x, w, x, w); }
Vector4 Quat::ywxw() const  { return Vector4       (y, w, x, w); }
Vector4 Quat::zwxw() const  { return Vector4       (z, w, x, w); }
Vector4 Quat::wwxw() const  { return Vector4       (w, w, x, w); }
Vector4 Quat::xxyw() const  { return Vector4       (x, x, y, w); }
Vector4 Quat::yxyw() const  { return Vector4       (y, x, y, w); }
Vector4 Quat::zxyw() const  { return Vector4       (z, x, y, w); }
Vector4 Quat::wxyw() const  { return Vector4       (w, x, y, w); }
Vector4 Quat::xyyw() const  { return Vector4       (x, y, y, w); }
Vector4 Quat::yyyw() const  { return Vector4       (y, y, y, w); }
Vector4 Quat::zyyw() const  { return Vector4       (z, y, y, w); }
Vector4 Quat::wyyw() const  { return Vector4       (w, y, y, w); }
Vector4 Quat::xzyw() const  { return Vector4       (x, z, y, w); }
Vector4 Quat::yzyw() const  { return Vector4       (y, z, y, w); }
Vector4 Quat::zzyw() const  { return Vector4       (z, z, y, w); }
Vector4 Quat::wzyw() const  { return Vector4       (w, z, y, w); }
Vector4 Quat::xwyw() const  { return Vector4       (x, w, y, w); }
Vector4 Quat::ywyw() const  { return Vector4       (y, w, y, w); }
Vector4 Quat::zwyw() const  { return Vector4       (z, w, y, w); }
Vector4 Quat::wwyw() const  { return Vector4       (w, w, y, w); }
Vector4 Quat::xxzw() const  { return Vector4       (x, x, z, w); }
Vector4 Quat::yxzw() const  { return Vector4       (y, x, z, w); }
Vector4 Quat::zxzw() const  { return Vector4       (z, x, z, w); }
Vector4 Quat::wxzw() const  { return Vector4       (w, x, z, w); }
Vector4 Quat::xyzw() const  { return Vector4       (x, y, z, w); }
Vector4 Quat::yyzw() const  { return Vector4       (y, y, z, w); }
Vector4 Quat::zyzw() const  { return Vector4       (z, y, z, w); }
Vector4 Quat::wyzw() const  { return Vector4       (w, y, z, w); }
Vector4 Quat::xzzw() const  { return Vector4       (x, z, z, w); }
Vector4 Quat::yzzw() const  { return Vector4       (y, z, z, w); }
Vector4 Quat::zzzw() const  { return Vector4       (z, z, z, w); }
Vector4 Quat::wzzw() const  { return Vector4       (w, z, z, w); }
Vector4 Quat::xwzw() const  { return Vector4       (x, w, z, w); }
Vector4 Quat::ywzw() const  { return Vector4       (y, w, z, w); }
Vector4 Quat::zwzw() const  { return Vector4       (z, w, z, w); }
Vector4 Quat::wwzw() const  { return Vector4       (w, w, z, w); }
Vector4 Quat::xxww() const  { return Vector4       (x, x, w, w); }
Vector4 Quat::yxww() const  { return Vector4       (y, x, w, w); }
Vector4 Quat::zxww() const  { return Vector4       (z, x, w, w); }
Vector4 Quat::wxww() const  { return Vector4       (w, x, w, w); }
Vector4 Quat::xyww() const  { return Vector4       (x, y, w, w); }
Vector4 Quat::yyww() const  { return Vector4       (y, y, w, w); }
Vector4 Quat::zyww() const  { return Vector4       (z, y, w, w); }
Vector4 Quat::wyww() const  { return Vector4       (w, y, w, w); }
Vector4 Quat::xzww() const  { return Vector4       (x, z, w, w); }
Vector4 Quat::yzww() const  { return Vector4       (y, z, w, w); }
Vector4 Quat::zzww() const  { return Vector4       (z, z, w, w); }
Vector4 Quat::wzww() const  { return Vector4       (w, z, w, w); }
Vector4 Quat::xwww() const  { return Vector4       (x, w, w, w); }
Vector4 Quat::ywww() const  { return Vector4       (y, w, w, w); }
Vector4 Quat::zwww() const  { return Vector4       (z, w, w, w); }
Vector4 Quat::wwww() const  { return Vector4       (w, w, w, w); }
}

