/**
 @file Vector2.cpp
 
 2D vector class, used for texture coordinates primarily.
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @cite Portions based on Dave Eberly'x Magic Software Library
  at http://www.magic-software.com
 
 @created 2001-06-02
 @edited  2009-11-16
 */

#include "G3D/platform.h"
#include <stdlib.h>
#include "G3D/Vector2.h"
#include "G3D/g3dmath.h"
#include "G3D/format.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/Any.h"

namespace G3D {


Vector2::Vector2(const Any& any) {
    any.verifyName("Vector2");
    any.verifyType(Any::TABLE, Any::ARRAY);
    any.verifySize(2);

    if (any.type() == Any::ARRAY) {
        x = any[0];
        y = any[1];
    } else {
        // Table
        x = any["x"];
        y = any["y"];
    }
}


Vector2::operator Any() const {
    Any any(Any::ARRAY, "Vector2");
    any.append(x, y);
    return any;
}


const Vector2& Vector2::one() { 
    static const Vector2 v(1, 1); return v; 
}


const Vector2& Vector2::zero() {
    static Vector2 v(0, 0);
    return v;
}

const Vector2& Vector2::unitX() {
    static Vector2 v(1, 0);
    return v;
}

const Vector2& Vector2::unitY() {
    static Vector2 v(0, 1);
    return v;
}

const Vector2& Vector2::inf() { 
	static Vector2 v((float)G3D::finf(), (float)G3D::finf());
	return v; 
}


const Vector2& Vector2::nan() { 
	static Vector2 v((float)G3D::fnan(), (float)G3D::fnan()); 
	return v; 
}


const Vector2& Vector2::minFinite() {
	static Vector2 v(-FLT_MAX, -FLT_MAX); 
	return v; 
}


const Vector2& Vector2::maxFinite() {
	static Vector2 v(FLT_MAX, FLT_MAX); 
	return v; 
}


size_t Vector2::hashCode() const {
    unsigned int xhash = (*(int*)(void*)(&x));
    unsigned int yhash = (*(int*)(void*)(&y));

    return xhash + (yhash * 37);
}


Vector2::Vector2(BinaryInput& b) {
    deserialize(b);
}


void Vector2::deserialize(BinaryInput& b) {
    x = b.readFloat32();
    y = b.readFloat32();
}


void Vector2::serialize(BinaryOutput& b) const {
    b.writeFloat32(x);
    b.writeFloat32(y);
}


void Vector2::deserialize(TextInput& t) {
    t.readSymbol("(");
    x = (float)t.readNumber();
    t.readSymbol(",");
    y = (float)t.readNumber();
    t.readSymbol(")");
}


void Vector2::serialize(TextOutput& t) const {
   t.writeSymbol("(");
   t.writeNumber(x);
   t.writeSymbol(",");
   t.writeNumber(y);
   t.writeSymbol(")");
}

//----------------------------------------------------------------------------

Vector2 Vector2::random(G3D::Random& r) {
    Vector2 result;

    do {
        result = Vector2(r.uniform(-1, 1), r.uniform(-1, 1));

    } while (result.squaredLength() >= 1.0f);

    result.unitize();

    return result;
}


Vector2 Vector2::operator/ (float k) const {
    return *this * (1.0f / k);
}

Vector2& Vector2::operator/= (float k) {
    this->x /= k;
    this->y /= k;
    return *this;
}

//----------------------------------------------------------------------------
float Vector2::unitize (float fTolerance) {
	float fLength = length();

    if (fLength > fTolerance) {
		float fInvLength = 1.0f / fLength;
        x *= fInvLength;
        y *= fInvLength;
    } else {
        fLength = 0.0;
    }

    return fLength;
}

//----------------------------------------------------------------------------

std::string Vector2::toString() const {
    return G3D::format("(%g, %g)", x, y);
}

// 2-char swizzles

Vector2 Vector2::xx() const  { return Vector2       (x, x); }
Vector2 Vector2::yx() const  { return Vector2       (y, x); }
Vector2 Vector2::xy() const  { return Vector2       (x, y); }
Vector2 Vector2::yy() const  { return Vector2       (y, y); }

// 3-char swizzles

Vector3 Vector2::xxx() const  { return Vector3       (x, x, x); }
Vector3 Vector2::yxx() const  { return Vector3       (y, x, x); }
Vector3 Vector2::xyx() const  { return Vector3       (x, y, x); }
Vector3 Vector2::yyx() const  { return Vector3       (y, y, x); }
Vector3 Vector2::xxy() const  { return Vector3       (x, x, y); }
Vector3 Vector2::yxy() const  { return Vector3       (y, x, y); }
Vector3 Vector2::xyy() const  { return Vector3       (x, y, y); }
Vector3 Vector2::yyy() const  { return Vector3       (y, y, y); }

// 4-char swizzles

Vector4 Vector2::xxxx() const  { return Vector4       (x, x, x, x); }
Vector4 Vector2::yxxx() const  { return Vector4       (y, x, x, x); }
Vector4 Vector2::xyxx() const  { return Vector4       (x, y, x, x); }
Vector4 Vector2::yyxx() const  { return Vector4       (y, y, x, x); }
Vector4 Vector2::xxyx() const  { return Vector4       (x, x, y, x); }
Vector4 Vector2::yxyx() const  { return Vector4       (y, x, y, x); }
Vector4 Vector2::xyyx() const  { return Vector4       (x, y, y, x); }
Vector4 Vector2::yyyx() const  { return Vector4       (y, y, y, x); }
Vector4 Vector2::xxxy() const  { return Vector4       (x, x, x, y); }
Vector4 Vector2::yxxy() const  { return Vector4       (y, x, x, y); }
Vector4 Vector2::xyxy() const  { return Vector4       (x, y, x, y); }
Vector4 Vector2::yyxy() const  { return Vector4       (y, y, x, y); }
Vector4 Vector2::xxyy() const  { return Vector4       (x, x, y, y); }
Vector4 Vector2::yxyy() const  { return Vector4       (y, x, y, y); }
Vector4 Vector2::xyyy() const  { return Vector4       (x, y, y, y); }
Vector4 Vector2::yyyy() const  { return Vector4       (y, y, y, y); }



} // namespace
