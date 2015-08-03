/**
 \file G3D.lib/source/Vector3.cpp
 
 3D vector class
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \cite Portions based on Dave Eberly's Magic Software Library at http://www.magic-software.com
 
 \created 2001-06-02
 \edited  2011-11-27
 */

#include <limits>
#include <stdlib.h>
#include "G3D/Vector3.h"
#include "G3D/g3dmath.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/Vector3int16.h"
#include "G3D/Matrix3.h"
#include "G3D/Vector2.h"
#include "G3D/Color3.h"
#include "G3D/Vector4int8.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3int32.h"
#include "G3D/Any.h"
 
namespace G3D {

    
Vector3 Vector3::movedTowards(const Vector3& goal, float maxTranslation) const {
    Vector3 t = *this;
    t.moveTowards(goal, maxTranslation);
    return t;
}


void Vector3::moveTowards(const Vector3& goal, float maxTranslation) {
    // Apply clamped translation
    Vector3 dX = goal - *this;
    float length = dX.length();
    if ((length < 0.00001f) || (length < maxTranslation)) {
        *this = goal;
    } else {
        *this += G3D::min(1.0f, maxTranslation / length) * dX;
    }
}


Vector3::Vector3(const Any& any) {
    if (any.name() == "Vector3::inf" || any.name() == "Point3::inf") {
        *this = inf();
        return;
    } else if (any.name() == "Vector3::zero" || any.name() == "Point3::zero") {
        *this = zero();
        return;
    } else if (any.name() == "Vector3::nan" || any.name() == "Point3::nan") {
        *this = nan();
        return;
    }

    any.verifyName("Vector3", "Point3");
    any.verifyType(Any::TABLE, Any::ARRAY);
    any.verifySize(3);

    if (any.type() == Any::ARRAY) {
        x = any[0];
        y = any[1];
        z = any[2];
    } else {
        // Table
        x = any["x"];
        y = any["y"];
        z = any["z"];
    }
}


bool Vector3::isNaN() const {
    return G3D::isNaN(x) || G3D::isNaN(y) || G3D::isNaN(z);
}


Vector3& Vector3::operator=(const Any& a) {
    *this = Vector3(a);
    return *this;
}


Any Vector3::toAny() const {
    return toAny("Vector3");
}


Any Vector3::toAny(const std::string& name) const {
    Any any(Any::ARRAY, name);
    any.append(x, y, z);
    return any;
}

Vector3::Vector3(const class Color3& v) : x(v.r), y(v.g), z(v.b) {}

Vector3::Vector3(const class Vector3int32& v) : x((float)v.x), y((float)v.y), z((float)v.z) {}

Vector3::Vector3(const Vector4int8& v) : x(v.x / 127.0f), y(v.y / 127.0f), z(v.z / 127.0f) {}

Vector3::Vector3(const class Vector2& v, float _z) : x(v.x), y(v.y), z(_z) {
}

Vector3& Vector3::ignore() {
    static Vector3 v;
    return v;
}

const Vector3& Vector3::zero() { static const Vector3 v(0, 0, 0); return v; }
const Vector3& Vector3::one()      { static const Vector3 v(1, 1, 1); return v; }
const Vector3& Vector3::unitX()    { static const Vector3 v(1, 0, 0); return v; }
const Vector3& Vector3::unitY()    { static const Vector3 v(0, 1, 0); return v; }
const Vector3& Vector3::unitZ()    { static const Vector3 v(0, 0, 1); return v; }
const Vector3& Vector3::inf()      { static const Vector3 v((float)G3D::finf(), (float)G3D::finf(), (float)G3D::finf()); return v; }
const Vector3& Vector3::nan()      { static const Vector3 v((float)G3D::fnan(), (float)G3D::fnan(), (float)G3D::fnan()); return v; }
const Vector3& Vector3::minFinite(){ static const Vector3 v(-FLT_MAX, -FLT_MAX, -FLT_MAX); return v; }
const Vector3& Vector3::maxFinite(){ static const Vector3 v(FLT_MAX, FLT_MAX, FLT_MAX); return v; }

Vector3::Axis Vector3::primaryAxis() const {
    
    Axis a = X_AXIS;

    double nx = abs(x);
    double ny = abs(y);
    double nz = abs(z);

    if (nx > ny) {
        if (nx > nz) {
            a = X_AXIS;
        } else {
            a = Z_AXIS;
        }
    } else {
        if (ny > nz) {
            a = Y_AXIS;
        } else {
            a = Z_AXIS;
        }
    }

    return a;
}


size_t Vector3::hashCode() const {
    const uint32* u = (const uint32*)this;
    return 
        HashTrait<uint32>::hashCode(u[0]) ^ 
        HashTrait<uint32>::hashCode(~u[1]) ^
        HashTrait<uint32>::hashCode((u[2] << 16) | ~(u[2] >> 16));
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    return os << v.toString();
}


//----------------------------------------------------------------------------

double frand() {
    return rand() / (double) RAND_MAX;
}

Vector3::Vector3(TextInput& t) {
    deserialize(t);
}

Vector3::Vector3(BinaryInput& b) {
    deserialize(b);
}


Vector3::Vector3(const class Vector3int16& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}


void Vector3::deserialize(BinaryInput& b) {
    x = b.readFloat32();
    y = b.readFloat32();
    z = b.readFloat32();
}


void Vector3::deserialize(TextInput& t) {
    t.readSymbol("(");
    x = (float)t.readNumber();
    t.readSymbol(",");
    y = (float)t.readNumber();
    t.readSymbol(",");
    z = (float)t.readNumber();
    t.readSymbol(")");
}


void Vector3::serialize(TextOutput& t) const {
   t.writeSymbol("(");
   t.writeNumber(x);
   t.writeSymbol(",");
   t.writeNumber(y);
   t.writeSymbol(",");
   t.writeNumber(z);
   t.writeSymbol(")");
}


void Vector3::serialize(BinaryOutput& b) const {
    b.writeFloat32(x);
    b.writeFloat32(y);
    b.writeFloat32(z);
}


Vector3 Vector3::random(Random& r) {
    Vector3 result;
    r.sphere(result.x, result.y, result.z);
    return result;
}


Vector3 Vector3::reflectAbout(const Vector3& normal) const {
    Vector3 out;

    Vector3 N = normal.direction();

    // 2 * normal.dot(this) * normal - this
    return N * 2 * this->dot(N) - *this;
}


Vector3 Vector3::cosHemiRandom(const Vector3& normal, Random& r) {
    debugAssertM(G3D::fuzzyEq(normal.length(), 1.0f), 
                 "cosHemiRandom requires its argument to have unit length");

    float x, y, z;
    r.cosHemi(x, y, z);

    // Make a coordinate system
    const Vector3& Z = normal;

    Vector3 X, Y;
    normal.getTangents(X, Y);

    return 
        x * X +
        y * Y +
        z * Z;
}


Vector3 Vector3::cosSphereRandom(const Vector3& normal, Random& r) {
    debugAssertM(G3D::fuzzyEq(normal.length(), 1.0f), 
                 "cosSphereRandom requires its argument to have unit length");

    float x, y, z;
    r.cosSphere(x, y, z);

    // Make a coordinate system
    const Vector3& Z = normal;

    Vector3 X, Y;
    normal.getTangents(X, Y);

    return 
        x * X +
        y * Y +
        z * Z;
}


Vector3 Vector3::cosPowHemiRandom(const Vector3& normal, const float k, Random& r) {
    debugAssertM(G3D::fuzzyEq(normal.length(), 1.0f), 
                 "cosPowHemiRandom requires its argument to have unit length");

    float x, y, z;
    r.cosPowHemi(k, x, y, z);

    // Make a coordinate system
    const Vector3& Z = normal;

    Vector3 X, Y;
    normal.getTangents(X, Y);

    return 
        x * X +
        y * Y +
        z * Z;
}


Vector3 Vector3::hemiRandom(const Vector3& normal, Random& r) {
    const Vector3& V = Vector3::random(r);

    if (V.dot(normal) < 0) {
        return -V;
    } else {
        return V;
    }
}

//----------------------------------------------------------------------------

Vector3 Vector3::reflectionDirection(const Vector3& normal) const {
    return -reflectAbout(normal).direction();
}

//----------------------------------------------------------------------------

Vector3 Vector3::refractionDirection(
    const Vector3&  normal,
    float           iInside,
    float           iOutside) const {

    // From pg. 24 of Henrik Wann Jensen. Realistic Image Synthesis
    // Using Photon Mapping.  AK Peters. ISBN: 1568811470. July 2001.

    // Invert the directions from Wann Jensen's formulation
    // and normalize the vectors.
    const Vector3 W = -direction();
    Vector3 N = normal.direction();

    float h1 = iOutside;
    float h2 = iInside;

    if (normal.dot(*this) > 0.0f) {
        h1 = iInside;
        h2 = iOutside;
        N  = -N;
    }

    const float hRatio = h1 / h2;
    const float WdotN = W.dot(N);

    float det = 1.0f - (float)square(hRatio) * (1.0f - (float)square(WdotN));

    if (det < 0) {
        // Total internal reflection
        return Vector3::zero();
    } else {
        return -hRatio * (W - WdotN * N) - N * sqrt(det);
    }
}

//----------------------------------------------------------------------------
void Vector3::orthonormalize (Vector3 akVector[3]) {
    // If the input vectors are v0, v1, and v2, then the Gram-Schmidt
    // orthonormalization produces vectors u0, u1, and u2 as follows,
    //
    //   u0 = v0/|v0|
    //   u1 = (v1-(u0*v1)u0)/|v1-(u0*v1)u0|
    //   u2 = (v2-(u0*v2)u0-(u1*v2)u1)/|v2-(u0*v2)u0-(u1*v2)u1|
    //
    // where |A| indicates length of vector A and A*B indicates dot
    // product of vectors A and B.

    // compute u0
    akVector[0] = akVector[0].direction();

    // compute u1
    float fDot0 = akVector[0].dot(akVector[1]);
    akVector[1] -= akVector[0] * fDot0;
    akVector[1] = akVector[1].direction();

    // compute u2
    float fDot1 = akVector[1].dot(akVector[2]);
    fDot0 = akVector[0].dot(akVector[2]);
    akVector[2] -= akVector[0] * fDot0 + akVector[1] * fDot1;
    akVector[2] = akVector[2].direction();
}


//----------------------------------------------------------------------------

std::string Vector3::toString() const {
    return G3D::format("(%g, %g, %g)", x, y, z);
}


//----------------------------------------------------------------------------

Matrix3 Vector3::cross() const {
    return Matrix3( 0, -z,  y,
                    z,  0, -x,
                   -y,  x,  0);
}


void serialize(const Vector3::Axis& a, class BinaryOutput& bo) {
    bo.writeUInt8((uint8)a);
}

void deserialize(Vector3::Axis& a, class BinaryInput& bi) {
    a = (Vector3::Axis)bi.readUInt8();
}

//----------------------------------------------------------------------------
// 2-char swizzles

Vector2 Vector3::xx() const  { return Vector2       (x, x); }
Vector2 Vector3::yx() const  { return Vector2       (y, x); }
Vector2 Vector3::zx() const  { return Vector2       (z, x); }
Vector2 Vector3::xy() const  { return Vector2       (x, y); }
Vector2 Vector3::yy() const  { return Vector2       (y, y); }
Vector2 Vector3::zy() const  { return Vector2       (z, y); }
Vector2 Vector3::xz() const  { return Vector2       (x, z); }
Vector2 Vector3::yz() const  { return Vector2       (y, z); }
Vector2 Vector3::zz() const  { return Vector2       (z, z); }

// 3-char swizzles

Vector3 Vector3::xxx() const  { return Vector3       (x, x, x); }
Vector3 Vector3::yxx() const  { return Vector3       (y, x, x); }
Vector3 Vector3::zxx() const  { return Vector3       (z, x, x); }
Vector3 Vector3::xyx() const  { return Vector3       (x, y, x); }
Vector3 Vector3::yyx() const  { return Vector3       (y, y, x); }
Vector3 Vector3::zyx() const  { return Vector3       (z, y, x); }
Vector3 Vector3::xzx() const  { return Vector3       (x, z, x); }
Vector3 Vector3::yzx() const  { return Vector3       (y, z, x); }
Vector3 Vector3::zzx() const  { return Vector3       (z, z, x); }
Vector3 Vector3::xxy() const  { return Vector3       (x, x, y); }
Vector3 Vector3::yxy() const  { return Vector3       (y, x, y); }
Vector3 Vector3::zxy() const  { return Vector3       (z, x, y); }
Vector3 Vector3::xyy() const  { return Vector3       (x, y, y); }
Vector3 Vector3::yyy() const  { return Vector3       (y, y, y); }
Vector3 Vector3::zyy() const  { return Vector3       (z, y, y); }
Vector3 Vector3::xzy() const  { return Vector3       (x, z, y); }
Vector3 Vector3::yzy() const  { return Vector3       (y, z, y); }
Vector3 Vector3::zzy() const  { return Vector3       (z, z, y); }
Vector3 Vector3::xxz() const  { return Vector3       (x, x, z); }
Vector3 Vector3::yxz() const  { return Vector3       (y, x, z); }
Vector3 Vector3::zxz() const  { return Vector3       (z, x, z); }
Vector3 Vector3::xyz() const  { return Vector3       (x, y, z); }
Vector3 Vector3::yyz() const  { return Vector3       (y, y, z); }
Vector3 Vector3::zyz() const  { return Vector3       (z, y, z); }
Vector3 Vector3::xzz() const  { return Vector3       (x, z, z); }
Vector3 Vector3::yzz() const  { return Vector3       (y, z, z); }
Vector3 Vector3::zzz() const  { return Vector3       (z, z, z); }

// 4-char swizzles

Vector4 Vector3::xxxx() const  { return Vector4       (x, x, x, x); }
Vector4 Vector3::yxxx() const  { return Vector4       (y, x, x, x); }
Vector4 Vector3::zxxx() const  { return Vector4       (z, x, x, x); }
Vector4 Vector3::xyxx() const  { return Vector4       (x, y, x, x); }
Vector4 Vector3::yyxx() const  { return Vector4       (y, y, x, x); }
Vector4 Vector3::zyxx() const  { return Vector4       (z, y, x, x); }
Vector4 Vector3::xzxx() const  { return Vector4       (x, z, x, x); }
Vector4 Vector3::yzxx() const  { return Vector4       (y, z, x, x); }
Vector4 Vector3::zzxx() const  { return Vector4       (z, z, x, x); }
Vector4 Vector3::xxyx() const  { return Vector4       (x, x, y, x); }
Vector4 Vector3::yxyx() const  { return Vector4       (y, x, y, x); }
Vector4 Vector3::zxyx() const  { return Vector4       (z, x, y, x); }
Vector4 Vector3::xyyx() const  { return Vector4       (x, y, y, x); }
Vector4 Vector3::yyyx() const  { return Vector4       (y, y, y, x); }
Vector4 Vector3::zyyx() const  { return Vector4       (z, y, y, x); }
Vector4 Vector3::xzyx() const  { return Vector4       (x, z, y, x); }
Vector4 Vector3::yzyx() const  { return Vector4       (y, z, y, x); }
Vector4 Vector3::zzyx() const  { return Vector4       (z, z, y, x); }
Vector4 Vector3::xxzx() const  { return Vector4       (x, x, z, x); }
Vector4 Vector3::yxzx() const  { return Vector4       (y, x, z, x); }
Vector4 Vector3::zxzx() const  { return Vector4       (z, x, z, x); }
Vector4 Vector3::xyzx() const  { return Vector4       (x, y, z, x); }
Vector4 Vector3::yyzx() const  { return Vector4       (y, y, z, x); }
Vector4 Vector3::zyzx() const  { return Vector4       (z, y, z, x); }
Vector4 Vector3::xzzx() const  { return Vector4       (x, z, z, x); }
Vector4 Vector3::yzzx() const  { return Vector4       (y, z, z, x); }
Vector4 Vector3::zzzx() const  { return Vector4       (z, z, z, x); }
Vector4 Vector3::xxxy() const  { return Vector4       (x, x, x, y); }
Vector4 Vector3::yxxy() const  { return Vector4       (y, x, x, y); }
Vector4 Vector3::zxxy() const  { return Vector4       (z, x, x, y); }
Vector4 Vector3::xyxy() const  { return Vector4       (x, y, x, y); }
Vector4 Vector3::yyxy() const  { return Vector4       (y, y, x, y); }
Vector4 Vector3::zyxy() const  { return Vector4       (z, y, x, y); }
Vector4 Vector3::xzxy() const  { return Vector4       (x, z, x, y); }
Vector4 Vector3::yzxy() const  { return Vector4       (y, z, x, y); }
Vector4 Vector3::zzxy() const  { return Vector4       (z, z, x, y); }
Vector4 Vector3::xxyy() const  { return Vector4       (x, x, y, y); }
Vector4 Vector3::yxyy() const  { return Vector4       (y, x, y, y); }
Vector4 Vector3::zxyy() const  { return Vector4       (z, x, y, y); }
Vector4 Vector3::xyyy() const  { return Vector4       (x, y, y, y); }
Vector4 Vector3::yyyy() const  { return Vector4       (y, y, y, y); }
Vector4 Vector3::zyyy() const  { return Vector4       (z, y, y, y); }
Vector4 Vector3::xzyy() const  { return Vector4       (x, z, y, y); }
Vector4 Vector3::yzyy() const  { return Vector4       (y, z, y, y); }
Vector4 Vector3::zzyy() const  { return Vector4       (z, z, y, y); }
Vector4 Vector3::xxzy() const  { return Vector4       (x, x, z, y); }
Vector4 Vector3::yxzy() const  { return Vector4       (y, x, z, y); }
Vector4 Vector3::zxzy() const  { return Vector4       (z, x, z, y); }
Vector4 Vector3::xyzy() const  { return Vector4       (x, y, z, y); }
Vector4 Vector3::yyzy() const  { return Vector4       (y, y, z, y); }
Vector4 Vector3::zyzy() const  { return Vector4       (z, y, z, y); }
Vector4 Vector3::xzzy() const  { return Vector4       (x, z, z, y); }
Vector4 Vector3::yzzy() const  { return Vector4       (y, z, z, y); }
Vector4 Vector3::zzzy() const  { return Vector4       (z, z, z, y); }
Vector4 Vector3::xxxz() const  { return Vector4       (x, x, x, z); }
Vector4 Vector3::yxxz() const  { return Vector4       (y, x, x, z); }
Vector4 Vector3::zxxz() const  { return Vector4       (z, x, x, z); }
Vector4 Vector3::xyxz() const  { return Vector4       (x, y, x, z); }
Vector4 Vector3::yyxz() const  { return Vector4       (y, y, x, z); }
Vector4 Vector3::zyxz() const  { return Vector4       (z, y, x, z); }
Vector4 Vector3::xzxz() const  { return Vector4       (x, z, x, z); }
Vector4 Vector3::yzxz() const  { return Vector4       (y, z, x, z); }
Vector4 Vector3::zzxz() const  { return Vector4       (z, z, x, z); }
Vector4 Vector3::xxyz() const  { return Vector4       (x, x, y, z); }
Vector4 Vector3::yxyz() const  { return Vector4       (y, x, y, z); }
Vector4 Vector3::zxyz() const  { return Vector4       (z, x, y, z); }
Vector4 Vector3::xyyz() const  { return Vector4       (x, y, y, z); }
Vector4 Vector3::yyyz() const  { return Vector4       (y, y, y, z); }
Vector4 Vector3::zyyz() const  { return Vector4       (z, y, y, z); }
Vector4 Vector3::xzyz() const  { return Vector4       (x, z, y, z); }
Vector4 Vector3::yzyz() const  { return Vector4       (y, z, y, z); }
Vector4 Vector3::zzyz() const  { return Vector4       (z, z, y, z); }
Vector4 Vector3::xxzz() const  { return Vector4       (x, x, z, z); }
Vector4 Vector3::yxzz() const  { return Vector4       (y, x, z, z); }
Vector4 Vector3::zxzz() const  { return Vector4       (z, x, z, z); }
Vector4 Vector3::xyzz() const  { return Vector4       (x, y, z, z); }
Vector4 Vector3::yyzz() const  { return Vector4       (y, y, z, z); }
Vector4 Vector3::zyzz() const  { return Vector4       (z, y, z, z); }
Vector4 Vector3::xzzz() const  { return Vector4       (x, z, z, z); }
Vector4 Vector3::yzzz() const  { return Vector4       (y, z, z, z); }
Vector4 Vector3::zzzz() const  { return Vector4       (z, z, z, z); }


void serialize(const Vector3& v, class BinaryOutput& b) {
    v.serialize(b);
}

void deserialize(Vector3& v, class BinaryInput& b) {
    v.deserialize(b);
}

} // namespace
